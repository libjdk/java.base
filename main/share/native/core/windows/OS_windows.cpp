/*
 * Copyright (c) 2025, Yao Yuan <yeaya@163.com>. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  This file as subject to the
 * "Classpath" exception in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "jvm.h"
#include "OS.h"
#include "JavaThread.h"
#include "StackWalk.h"

#include <java/lang/Logger.h>
#include "WindowsSemaphore.h"
#include "Arguments.h"
#include "WindowsDecoder.h"

#include <windows.h>
#include <malloc.h>
#include <direct.h>
#include <errno.h>
#include <io.h>
#include <process.h>
#include <psapi.h>
#include <mmsystem.h>
#include <winsock2.h>
#include <shlobj.h> 

#include <minidumpapiset.h>

#include <java/lang/String.h>
#include <java/lang/Logger.h>
#include <java/lang/MemoryManager.h>
#include <java/lang/ObjectHead.h>
#include <java/lang/ObjectManagerInternal.h>

#pragma comment(lib, "Dbghelp.lib")

namespace java {
	namespace lang {
		extern MemoryManager memoryManager;
	}
}

using ::java::lang::ObjectManagerInternal;
using ::java::lang::NullPointerException;
using namespace ::java::lang;

WindowsDecoder windowsDecoder;
PVOID  topLevelVectoredExceptionHandler = nullptr;
LPTOP_LEVEL_EXCEPTION_FILTER previousUnhandledExceptionFilter = nullptr;

HINSTANCE libHandle = nullptr;
#if 0
BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		libHandle = hinst;
		if (ForceTimeHighResolution) {
			timeBeginPeriod(1L);
		}
		WindowsDbgHelp::pre_initialize();
		SymbolEngine::pre_initialize();
		break;
	case DLL_PROCESS_DETACH:
		if (ForceTimeHighResolution) {
			timeEndPeriod(1L);
		}
		if (topLevelVectoredExceptionHandler != nullptr) {
			RemoveVectoredExceptionHandler(topLevelVectoredExceptionHandler);
			topLevelVectoredExceptionHandler = nullptr;
		}
		break;
	default:
		break;
	}
	return true;
}
#endif

struct PreserveLastError {
	const DWORD v;
	PreserveLastError() : v(::GetLastError()) {
	}
	~PreserveLastError() {
		::SetLastError(v);
	}
};

inline address getPc(_EXCEPTION_POINTERS* exceptionInfo) {
#if defined(_M_ARM64)
	return (address)exceptionInfo->ContextRecord->Pc;
#elif defined(_M_AMD64)
	return (address)exceptionInfo->ContextRecord->Rip;
#else
	return (address)exceptionInfo->ContextRecord->Eip;
#endif
}

inline void setPc(_EXCEPTION_POINTERS* exceptionInfo, address pc) {
#if defined(_M_ARM64)
	exceptionInfo->ContextRecord->Pc = (DWORD64)pc;
#elif defined(_M_AMD64)
	exceptionInfo->ContextRecord->Rip = (DWORD64)pc;
#else
	exceptionInfo->ContextRecord->Eip = (DWORD64)pc;
#endif
}

void OS::initSystemProperties() {
#define BIN_DIR "\\bin"
	{
		char homeDir[MAX_PATH + 1];
		OS::getJavaBasePath(homeDir, sizeof(homeDir));
		Arguments::setJavaBasePath(homeDir);
		char* pslash = strrchr(homeDir, '\\');
		if (pslash != nullptr) {
			*pslash = '\0';
		}
		pslash = strrchr(homeDir, '\\');
		if (pslash != nullptr) {
			*pslash = '\0';
		}
		Arguments::setJavaHome(homeDir);

		char* dllPath = $allocRaw<char>(strlen(homeDir) + strlen(BIN_DIR) + 1);
		strcpy(dllPath, homeDir);
		strcat(dllPath, BIN_DIR);
		Arguments::setBootLibraryPath(dllPath);
		$freeRaw(dllPath);
	}

	{
		char tmp[MAX_PATH + 1];
		char* envPath = ::getenv("PATH");

		char* libraryPath = $allocRaw<char>(MAX_PATH * 4 + (envPath ? strlen(envPath) : 0) + 10);

		libraryPath[0] = '\0';

		// the directory from application
		GetModuleFileName(nullptr, tmp, sizeof(tmp));
		*(strrchr(tmp, '\\')) = '\0';
		strcat(libraryPath, tmp);

		GetSystemDirectory(tmp, sizeof(tmp));
		strcat(libraryPath, ";");
		strcat(libraryPath, tmp);

		GetWindowsDirectory(tmp, sizeof(tmp));
		strcat(libraryPath, ";");
		strcat(libraryPath, tmp);

		if (envPath != nullptr) {
			strcat(libraryPath, ";");
			strcat(libraryPath, envPath);
		}

		strcat(libraryPath, ";.");

		Arguments::setJavaLibraryPath(libraryPath);
		$freeRaw(libraryPath);
	}

	{
		char tmp[MAX_PATH + 1];
		getExecutionFilePath(tmp, sizeof(tmp));
		Arguments::setExecutionFilePath(tmp);
	}
	return;
}

void OS::breakpoint() {
	DebugBreak();
}

int OS::getBackTrace(address* stack, int frames, int toSkip) {
	int captured = RtlCaptureStackBackTrace(toSkip + 1, frames, (PVOID*)stack, nullptr);
	if (captured < frames) {
		stack[captured] = nullptr;
	}
	return captured;
}

address OS::getCurrentStackBase() {
	MEMORY_BASIC_INFORMATION minfo = { 0 };
	VirtualQuery(&minfo, &minfo, sizeof(minfo));
	address stackBottom = (address)minfo.AllocationBase;
	size_t stackSize = minfo.RegionSize;
	while (true) {
		VirtualQuery(stackBottom + stackSize, &minfo, sizeof(minfo));
		if (stackBottom == (address)minfo.AllocationBase) {
			stackSize += minfo.RegionSize;
		} else {
			break;
		}
	}
	return stackBottom + stackSize;
}

size_t OS::getCurrentStackSize() {
	MEMORY_BASIC_INFORMATION minfo = { 0 };
	VirtualQuery(&minfo, &minfo, sizeof(minfo));
	size_t stackSize = (size_t)OS::getCurrentStackBase() - (size_t)minfo.AllocationBase;
	return stackSize;
}

int64_t OS::getCurrentStackPointer() {
	CONTEXT context;
	HANDLE hThread = GetCurrentThread();
	context.ContextFlags = CONTEXT_FULL; // CONTEXT_INTEGER;
	GetThreadContext(hThread, &context);
#ifdef AMD64
	return context.Rsp;
#elif defined(AARCH64)
	return context.Sp;
#else
#endif
}

bool OS::snapshotStackObjects(void* jthread) {
	if (jthread == nullptr) {
		return false;
	}
	JavaThread* thread = (JavaThread*)jthread;
	if (thread->threadObject == nullptr || thread->threadObject->threadStatus == (int32_t)JavaThread::Status::TERMINATED) {
		return false;
	}
	thread->clearStackObjects();
	uint64_t* stackBase = (uint64_t*)thread->getStackBase();
	uint64_t* stackEnd = (uint64_t*)thread->getStackEnd();
	int64_t stackSize = thread->getStackSize();
	void* handle = thread->getOsThread()->getThreadHandle();

	bool needSuspend = thread != JavaThread::getCurrentThread();
	if (needSuspend) {
		if (SuspendThread(handle) != 0) {
			log_debug("snapshotStackObjects SuspendThread GetLastError %d\n", GetLastError());
			return false;
		}
	}

	thread->snapshotStackObjects();
	ObjectStackType objectStackType = ObjectManagerInternal::getObjectStackType();
	if (objectStackType == OBJECT_STACK_TYPE_NATIVE || objectStackType == OBJECT_STACK_TYPE_NATIVE_MAGIC) {
		CONTEXT context;
		context.ContextFlags = CONTEXT_FULL; // CONTEXT_INTEGER;
		GetThreadContext(handle, &context);
#ifdef AMD64
		uint64_t rsp = context.Rsp;
		if (objectStackType == OBJECT_STACK_TYPE_NATIVE) {
			thread->saveStackObject((void*)context.Rax);
			thread->saveStackObject((void*)context.Rcx);
			thread->saveStackObject((void*)context.Rdx);
			thread->saveStackObject((void*)context.Rbx);
			thread->saveStackObject((void*)context.Rsp);
			thread->saveStackObject((void*)context.Rbp);
			thread->saveStackObject((void*)context.Rsi);
			thread->saveStackObject((void*)context.Rdi);
			thread->saveStackObject((void*)context.R8);
			thread->saveStackObject((void*)context.R9);
			thread->saveStackObject((void*)context.R10);
			thread->saveStackObject((void*)context.R11);
			thread->saveStackObject((void*)context.R12);
			thread->saveStackObject((void*)context.R13);
			thread->saveStackObject((void*)context.R14);
			thread->saveStackObject((void*)context.R15);
		}
#elif defined(AARCH64)
		uint64_t rsp = context.Sp;
		if (objectStackType == OBJECT_STACK_TYPE_NATIVE) {
			for (int i = 0; i < $lengthOf(context.X); i++) {
				void* reg = (void*)context.X[i];
				thread->saveStackObject(reg);
			}
		}
#else

#endif
		int64_t begin = $align_up(rsp, 8);
		uint64_t* ptr = (uint64_t*)begin;
		if (ptr >= stackEnd) {
			int32_t count = 0;
			while (ptr < stackBase) {
				uint64_t value = *ptr;
				if (objectStackType == OBJECT_STACK_TYPE_NATIVE_MAGIC) {
					while (value == JCPP_NATIVE_OBJECT_STACK_MAGIC) {
						ptr++;
						if (ptr < stackBase) {
							value = *ptr;
							if (value != JCPP_NATIVE_OBJECT_STACK_MAGIC) {
								thread->saveStackObject((void*)value);
							}
						} else {
							break;
						}
					}
				} else {
					thread->saveStackObject((void*)value);
				}
				ptr++;
			}
		}
	}

	if (needSuspend) {
		OS::resumeThread(handle);
	}
	thread->setStackObjectsSaved();

	return true;
}

static jlong initialPerformanceCount;
static jlong performanceFrequency;

inline jlong jlongFrom(jint high, jint low) {
	jlong value = 0;
	value |= (jlong)high << 32;
	value |= (jlong)(uint64_t)(uint32_t)low;
	return value;
}

jlong jlongFrom(const LARGE_INTEGER& x) {
	return jlongFrom(x.HighPart, x.LowPart);
}

jlong OS::getElapsedCounter() {
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return jlongFrom(count) - initialPerformanceCount;
}

jlong OS::getAvailableMemory() {
	MEMORYSTATUSEX ms;
	ms.dwLength = sizeof(ms);
	GlobalMemoryStatusEx(&ms);
	return (jlong)ms.ullAvailPhys;
}

jlong OS::getPhysicalMemory() {
	MEMORYSTATUSEX ms;
	ms.dwLength = sizeof(ms);
	GlobalMemoryStatusEx(&ms);
	return ms.ullTotalPhys;
}

int OS::getActiveProcessorCount() {
	DWORD_PTR lpProcessAffinityMask = 0;
	DWORD_PTR lpSystemAffinityMask = 0;
	if (GetProcessAffinityMask(GetCurrentProcess(), &lpProcessAffinityMask, &lpSystemAffinityMask)) {
		int bitcount = 0;
		while (lpProcessAffinityMask != 0) {
			lpProcessAffinityMask = lpProcessAffinityMask & (lpProcessAffinityMask - 1);
			bitcount++;
		}
		return bitcount;
	} else {
		return -1;
	}
}

#pragma pack(push, 8)  
struct THREADNAME_INFO {
	DWORD dwType;
	LPCSTR szName;
	DWORD dwThreadID;
	DWORD dwFlags;
};
#pragma pack(pop)  

void OS::setNativeThreadName($String* name) {
	if (name == nullptr) {
		return;
	}
	char threadName[512];
	name->utf8String((char*)threadName, sizeof(threadName));

	DWORD dwThreadID = -1;
	THREADNAME_INFO info;
	info.dwType = 0x1000;
	info.szName = threadName;
	info.dwThreadID = dwThreadID;
	info.dwFlags = 0;
#pragma warning(push)  
#pragma warning(disable: 6320 6322)  
	__try {
		const DWORD MS_VC_EXCEPTION = 0x406D1388;
		RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
	} __except (EXCEPTION_EXECUTE_HANDLER) {
	}
#pragma warning(pop) 
}

static const jlong TIME_TICK_OFFSET = 116444736000000000;

inline jlong windowsToTimeTicks(const FILETIME& wt) {
	jlong t = jlongFrom(wt.dwHighDateTime, wt.dwLowDateTime);
	return (t - TIME_TICK_OFFSET);
}

inline jlong windowsToTimeMillis(const FILETIME& wt) {
	return windowsToTimeTicks(wt) / 10000;
}

jlong OS::getTimeMillis() {
	FILETIME wt;
	GetSystemTimeAsFileTime(&wt);
	return windowsToTimeMillis(wt);
}

void OS::getTimeSystemUTC(jlong& seconds, jlong& nanos) {
	FILETIME wt;
	GetSystemTimeAsFileTime(&wt);
	jlong ticks = windowsToTimeTicks(wt); // 10th of micros
	jlong secs = jlong(ticks / 10000000); // 10000 * 1000
	seconds = secs;
	nanos = jlong(ticks - (secs * 10000000)) * 100;
}

jlong OS::getTimeNanos() {
	LARGE_INTEGER currentCount;
	QueryPerformanceCounter(&currentCount);
	jlong current = jlongFrom(currentCount);
	jlong time = 0;
	if (NANOSECS_PER_SEC > performanceFrequency && NANOSECS_PER_SEC % performanceFrequency == 0) {
		jlong v = NANOSECS_PER_SEC / performanceFrequency;
		time = current * v;
	} else {
		time = (jlong)(((double)current / performanceFrequency) * NANOSECS_PER_SEC);
	}
	return time;
}

void OS::shutdown() {
}

void OS::abort(bool dumpCore, void* siginfo, const void* context) {
	shutdown();
	OS::exitProcess(false, 1);
}

void OS::die() {
	OS::exitProcess(true, -1);
}

void OS::unloadLibrary(void* lib) {
	::FreeLibrary((HMODULE)lib);
}

void* OS::getFromLibrary(void* lib, const char* name) {
	return (void*)::GetProcAddress((HMODULE)lib, name);
}

const char* OS::getTempDirectory(char* buf, int bufLen) {
	if (GetTempPath(bufLen, buf) > 0) {
		return buf;
	} else {
		buf[0] = '\0';
		return buf;
	}
}

const char* OS::getCurrentDirectory(char* buf, int bufLen) {
	return _getcwd(buf, bufLen);
}

const char* OS::getExecutionFilePath(char* buf, int bufLen) {
	GetModuleFileNameA(NULL, buf, bufLen);
	return buf;
}

struct ModInfo {
	address addr;
	char* fullPath;
	int buflen;
	address baseAddr;
};

static int locateModule(const char* mod_fname, address baseAddr, address topAddress, void* param) {
	struct ModInfo* pmod = (struct ModInfo*)param;
	if (pmod == nullptr) {
		return -1;
	}
	if (baseAddr <= pmod->addr &&
		topAddress > pmod->addr) {
		if (pmod->fullPath != nullptr) {
			jio_snprintf(pmod->fullPath, pmod->buflen, "%s", mod_fname);
		}
		pmod->baseAddr = baseAddr;
		return 1;
	}
	return 0;
}

typedef int (*LoadedModulesCallbackFunc)(const char*, address, address, void*);

int getLoadedModulesInfo(LoadedModulesCallbackFunc callback, void* param) {
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
		FALSE, OS::getCurrentProcessId());
	if (hProcess == nullptr) {
		return 0;
	}

	DWORD size;
# define MAX_NUM_MODULES 512
	HMODULE modules[MAX_NUM_MODULES];
	if (!EnumProcessModules(hProcess, modules, sizeof(modules), &size)) {
		CloseHandle(hProcess);
		return 0;
	}

	int numModules = size / sizeof(HMODULE);
	if (numModules > MAX_NUM_MODULES) {
		numModules = MAX_NUM_MODULES;
	}
	char filename[MAX_PATH];
	int result = 0;
	for (int i = 0; i < numModules; i++) {
		if (!GetModuleFileNameEx(hProcess, modules[i], filename, sizeof(filename))) {
			filename[0] = '\0';
		}
		MODULEINFO modinfo = { 0 };
		if (!GetModuleInformation(hProcess, modules[i], &modinfo, sizeof(modinfo))) {
			modinfo.lpBaseOfDll = nullptr;
			modinfo.SizeOfImage = 0;
		}
		result = callback(filename, (address)modinfo.lpBaseOfDll, (address)((uint64_t)modinfo.lpBaseOfDll + (uint64_t)modinfo.SizeOfImage), param);
		if (result) break;
	}
	CloseHandle(hProcess);
	return result;
}

bool OS::getLibraryWithAddress(address addr, char* buf, int buflen) {
	struct ModInfo mi;
	mi.addr = addr;
	mi.fullPath = buf;
	mi.buflen = buflen;
	if (getLoadedModulesInfo(locateModule, (void*)&mi)) {
		return true;
	}
	buf[0] = '\0';
	return false;
}

bool OS::addressToFunctionName(address addr, char* buf, int buflen) {
	if (windowsDecoder.decode(addr, buf, buflen)) {
		return true;
	}
	buf[0] = '\0';
	return false;
}

void* OS::loadLibrary(const char* name, char* ebuf, int ebuflen) {
	void* result = LoadLibrary(name);
	if (result != nullptr) {
		windowsDecoder.onLoad(name);
		return result;
	}
	DWORD errcode = GetLastError();
	getLastErrorDesc(ebuf, (size_t)ebuflen);
	ebuf[ebuflen - 1] = '\0';
	if (errcode == ERROR_MOD_NOT_FOUND) {
		strncpy(ebuf, "Can't find dependent libraries", ebuflen - 1);
		ebuf[ebuflen - 1] = '\0';
	}
	return nullptr;
}

int OS::vsnprintf(char* buf, size_t len, const char* fmt, va_list args) {
	int result = ::vsnprintf(buf, len, fmt, args);
	if ((result < 0) && (len > 0)) {
		buf[len - 1] = '\0';
	}
	return result;
}

void OS::getJavaBasePath(char* buf, jint buflen) {
	buf[0] = '\0';
	//libHandle = (HINSTANCE)OS::getDefaultProcessHandle();
	//GetModuleFileName(libHandle, buf, buflen);
	getLibraryWithAddress((address)OS::getJavaBasePath, buf, buflen);
}

size_t OS::getLastErrorDesc(char* buf, size_t len) {
	DWORD errval;
	if ((errval = GetLastError()) != 0) {
		size_t n = (size_t)FormatMessage(
			FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			errval,
			0,
			buf,
			(DWORD)len,
			nullptr);
		if (n > 3) {
			if (buf[n - 1] == '\n') {
				n--;
			}
			if (buf[n - 1] == '\r') {
				n--;
			}
			if (buf[n - 1] == '.') {
				n--;
			}
			buf[n] = '\0';
		}
		return n;
	}
	if (errno != 0) {
		const char* s = OS::getErrorDesc(errno);
		size_t n = strlen(s);
		if (n >= len) {
			n = len - 1;
		}
		strncpy(buf, s, n);
		buf[n] = '\0';
		return n;
	}
	return 0;
}

// sun.misc.Signal
static void (*sigbreakHandler)(int) = nullptr;

static void UserHandler(int sig, void* siginfo, void* context) {
	OS::notifySignal(sig);
	OS::signal(sig, (void*)UserHandler);
}

void* OS::getUserHandler() {
	return (void*)UserHandler;
}

void* OS::signal(int signal_number, void* handler) {
	if ((signal_number == SIGBREAK)) {
		void (*oldHandler)(int) = sigbreakHandler;
		sigbreakHandler = (void (*)(int)) handler;
		return (void*)oldHandler;
	} else {
		return (void*)::signal(signal_number, (void (*)(int))handler);
	}
}

void OS::raiseSignal(int sig) {
	raise(sig);
}

static BOOL WINAPI consoleHandler(DWORD event) {
	printf("consoleHandler event %d\n", event);

	switch (event) {
	case CTRL_C_EVENT:
		printf("consoleHandler CTRL_C_EVENT\n");
		OS::die();
		OS::raiseSignal(SIGINT);
		return TRUE;
		break;
	case CTRL_BREAK_EVENT:
		if (sigbreakHandler != nullptr) {
			(*sigbreakHandler)(SIGBREAK);
		}
		return TRUE;
		break;
	case CTRL_LOGOFF_EVENT: {
		USEROBJECTFLAGS flags;
		HANDLE handle = GetProcessWindowStation();
		if (handle != nullptr && GetUserObjectInformation(handle, UOI_FLAGS, &flags, sizeof(USEROBJECTFLAGS), nullptr)) {
			if ((flags.dwFlags & WSF_VISIBLE) == 0) {
				return FALSE;
			}
		}
	}
	case CTRL_CLOSE_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		OS::raiseSignal(SIGTERM);
		return TRUE;
		break;
	default:
		break;
	}
	return FALSE;
}

static std::atomic_int pendingSignals[NSIG + 1] = { 0 };
static Semaphore* sig_sem = nullptr;

static void initMiscSignal() {
	sig_sem = new Semaphore();
	// ctrl-c handler
	SetConsoleCtrlHandler(consoleHandler, TRUE);
}

void OS::notifySignal(int sig) {
	if (sig_sem != nullptr) {
		pendingSignals[sig].fetch_add(1);
		sig_sem->signal();
	}
}

int OS::waitSignal() {
	while (true) {
		for (int i = 0; i < NSIG + 1; i++) {
			int n = pendingSignals[i];
			if (n > 0) {
				pendingSignals[i].fetch_add(-1);
				return i;
			}
		}
		JavaThread::sureCurrentThread()->waitSignal(sig_sem);
	}
	shouldNotReachHere();
	return 0;
}

LONG handleException(struct _EXCEPTION_POINTERS* exceptionInfo, address handler) {
	setPc(exceptionInfo, handler);
	return EXCEPTION_CONTINUE_EXECUTION;
}

#define EXCEPTION_UNCAUGHT_CXX_EXCEPTION    0xE06D7363

LONG handleIDivException(struct _EXCEPTION_POINTERS* exceptionInfo) {
	//  for -MinInt/-1
	PCONTEXT contextRecord = exceptionInfo->ContextRecord;
#if defined(_M_ARM64)
	address pc = (address)contextRecord->Sp;
	// idiv reg, reg, reg (pc[0] == 0x83, 4 bytes)
	contextRecord->Pc = (uint64_t)pc + 4;
	contextRecord->X4 = (uint64_t)0x80000000; // min_jint;
	contextRecord->X5 = 0;
#elif defined(_M_AMD64)
	address pc = (address)contextRecord->Rip;
	if (pc[0] == 0xF7) { // idiv reg, reg (2 bytes)
		contextRecord->Rip = (DWORD64)pc + 2;
	} else { // REX idiv reg, reg  (3 bytes)
		contextRecord->Rip = (DWORD64)pc + 3;
	}
	contextRecord->Rdx = 0;
#else
	address pc = (address)contextRecord->Eip;
	// idiv reg, reg (pc[0] == 0xF7, 2 bytes)
	contextRecord->Eip = (DWORD)pc + 2;
	contextRecord->Eax = (DWORD)0x80000000; // min_jint;
	contextRecord->Edx = 0;
#endif
	return EXCEPTION_CONTINUE_EXECUTION;
}

#if defined(_M_AMD64) || defined(_M_IX86)
LONG WINAPI handleFltException(struct _EXCEPTION_POINTERS* exceptionInfo) {
	if (exceptionInfo->ContextRecord->MxCsr != INITIAL_MXCSR) {
		exceptionInfo->ContextRecord->MxCsr = INITIAL_MXCSR;
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	return EXCEPTION_CONTINUE_SEARCH;
}
#endif

void dump(PCONTEXT context, PEXCEPTION_RECORD exception) {
	log_info("dump begin\n");
	EXCEPTION_POINTERS ep;
	MINIDUMP_EXCEPTION_INFORMATION mei;
	MINIDUMP_EXCEPTION_INFORMATION* pmei;

	HANDLE hProcess = GetCurrentProcess();
	DWORD processId = GetCurrentProcessId();
	MINIDUMP_TYPE dumpType;

	//shutdown();
	//if (!dump_core || dumpFile == NULL) {
	//    if (dumpFile != NULL) {
	//        CloseHandle(dumpFile);
	//    }
	//    win32::exit_process_or_thread(win32::EPT_PROCESS, 1);
	//}

	static HANDLE dumpFile = NULL;


	if (dumpFile == NULL &&
		(dumpFile = CreateFile("jcpp.dump", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL))
		== INVALID_HANDLE_VALUE) {
		//jio_snprintf(buffer, buffsz, "Failed to create minidump file (0x%x).", GetLastError());
		//status = false;
	}
	dumpType = (MINIDUMP_TYPE)(MiniDumpWithFullMemory | MiniDumpWithHandleData |
		MiniDumpWithFullMemoryInfo | MiniDumpWithThreadInfo | MiniDumpWithUnloadedModules);

	if (exception != NULL && context != NULL) {
		ep.ContextRecord = (PCONTEXT)context;
		ep.ExceptionRecord = (PEXCEPTION_RECORD)exception;

		mei.ThreadId = GetCurrentThreadId();
		mei.ExceptionPointers = &ep;
		pmei = &mei;
	} else {
		pmei = NULL;
	}

	// Older versions of dbghelp.dll (the one shipped with Win2003 for example) may not support all
	// the dump types we really want. If first call fails, lets fall back to just use MiniDumpWithFullMemory then.
	if (!MiniDumpWriteDump(hProcess, processId, dumpFile, dumpType, pmei, NULL, NULL) &&
		!MiniDumpWriteDump(hProcess, processId, dumpFile, (MINIDUMP_TYPE)MiniDumpWithFullMemory, pmei, NULL, NULL)) {
		jio_fprintf(stderr, "Call to MiniDumpWriteDump() failed (Error 0x%x)\n", GetLastError());
	}
	CloseHandle(dumpFile);

	log_info("dump end\n");
	//exit(0);
}

LONG WINAPI topLevelVectoredExceptionFilter(struct _EXCEPTION_POINTERS* exceptionInfo) {
	PEXCEPTION_RECORD exceptionRecord = exceptionInfo->ExceptionRecord;
	DWORD exceptionCode = exceptionRecord->ExceptionCode;
	address pc = getPc(exceptionInfo);

	if (exceptionCode == EXCEPTION_ACCESS_VIOLATION) {
		int exceptionSubcode = (int)exceptionRecord->ExceptionInformation[0];
		address addr = (address)exceptionRecord->ExceptionInformation[1];
		//#ifndef JCPP_ENABLE_NC
		if (addr != nullptr) {
			java::lang::ObjectHead* oh = java::lang::memoryManager.tryToObject(addr);
			if (oh != nullptr) {
				log_info("topLevelVectoredExceptionFilter oh:0x%x\n",
					oh);
			} else {
				log_info("topLevelVectoredExceptionFilter oh == nullptr\n");
			}
			log_info("topLevelVectoredExceptionFilter exceptionCode:0x%x pc:%p flag:0x%x subcode:%d addr:%p\n",
				exceptionCode, pc, exceptionRecord->ExceptionFlags, exceptionSubcode, addr);
		}
		if (Logger::isLoggable(Logger::LOG_INFO)) {
			StackWalk::printStackTrace(nullptr);
		}
		//#endif
				//dump(exceptionInfo->ContextRecord, exceptionRecord);
		NullPointerException::throwNew$();
#if 0   // may be useful in the future
		//   return Handle_Exception(exceptionInfo, (address)NullPointerException::throwNew$);
		char* buf = (char*)VirtualAlloc(nullptr, 128, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		int32_t off = 0;
		buf[off++] = 0x48; // mov
		buf[off++] = (int8_t)0xB8; // rax
		//  int8_t* pc2 = buf + off + 10;
			// function address
		*(int64_t*)(buf + off) = (int64_t)pc; // 1, TODO, why its work?
		off += sizeof(int64_t);
		buf[off++] = (int8_t)0x50; // push rax

		char* pc3 = buf + off;
		buf[off++] = 0x48; // mov
		buf[off++] = (int8_t)0xB8; // rax

		//  int8_t* pc2 = buf + off + 10;
		*(int64_t*)(buf + off) = (int64_t)NullPointerException::throwNew$;
		off += sizeof(int64_t);
		buf[off++] = (int8_t)0xff; // jmp
		buf[off++] = (int8_t)0xe0; // rax
		buf[off++] = 0xC9; // leaveq
		buf[off++] = 0xC3; // retq
		setPc(exceptionInfo, buf);
		return EXCEPTION_CONTINUE_EXECUTION;
#endif
	}

	JavaThread* current = JavaThread::getCurrentThread();
	if (current != nullptr) {
		if (exceptionCode == EXCEPTION_STACK_OVERFLOW) {
			return EXCEPTION_CONTINUE_SEARCH;
		} else if (exceptionCode == EXCEPTION_ACCESS_VIOLATION) {
			return EXCEPTION_CONTINUE_SEARCH;
		}

		switch (exceptionCode) {
		case EXCEPTION_INT_DIVIDE_BY_ZERO:
			// TODO
			break;

		case EXCEPTION_INT_OVERFLOW:
			return handleIDivException(exceptionInfo);

		}

#if defined(_M_AMD64) || defined(_M_IX86)
		if (exceptionCode != EXCEPTION_UNCAUGHT_CXX_EXCEPTION) {
			return handleFltException(exceptionInfo);
		}
#endif
	}

	return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI topLevelUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* exceptionInfo) {
	return previousUnhandledExceptionFilter ? previousUnhandledExceptionFilter(exceptionInfo) : EXCEPTION_CONTINUE_SEARCH;
}

int32_t OS::getPageSize() {
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	return si.dwPageSize;
}

void OS::sleep(jlong ms) {
	Sleep((DWORD)ms);
}

void OS::nanoSleep(jlong ns) {
	int64_t last = getTimeNanos();
	while (ns > 0) {
		if (SwitchToThread() == 0) {
			spinPause();
		}
		int64_t curr = getTimeNanos();
		int64_t dif = curr - last;
		if (dif > 0) {
			if (dif >= ns) {
				break;
			}
			ns -= dif;
		}
		last = curr;
	}
}

void OS::yield() {
	SwitchToThread();
}

int64_t OS::getCurrentThreadId() {
	return GetCurrentThreadId();
}

int32_t OS::getCurrentProcessId() {
	return _getpid();
}

bool OS::suspendThread(void* handle) {
	SuspendThread(handle);
	return true;
}

bool OS::resumeThread(void* handle) {
	ResumeThread(handle);
	return true;
}

size_t OS::defaultStackSize = 0;

void OS::initSystemInfo() {
	defaultStackSize = OS::getCurrentStackSize();

	// initialize performance counter
	LARGE_INTEGER count;
	QueryPerformanceFrequency(&count);
	performanceFrequency = jlongFrom(count);
	QueryPerformanceCounter(&count);
	initialPerformanceCount = jlongFrom(count);
}

#define MAXIMUM_THREADS_TO_KEEP (16 * MAXIMUM_WAIT_OBJECTS)
#define EXIT_TIMEOUT 300000 // ms
static HANDLE exitingThreadHandles[MAXIMUM_THREADS_TO_KEEP];
static int exitingThreadHandleCount = 0;
static CRITICAL_SECTION exitingCritSect;
static std::atomic<DWORD> exitingProcessThreadId = 0;

void OS::exitProcess(bool die, int exitCode) {
	DWORD currentThreadId = GetCurrentThreadId();
	exitingProcessThreadId.exchange(currentThreadId);

	EnterCriticalSection(&exitingCritSect);
	jlong startTime = OS::getTimeMillis();
	jlong finishTime = startTime + EXIT_TIMEOUT;
	for (int i = 0; ; ) {
		int waitCount = exitingThreadHandleCount - i;
		if (waitCount > MAXIMUM_WAIT_OBJECTS) {
			waitCount = MAXIMUM_WAIT_OBJECTS;
		}
		jlong timeout = finishTime - startTime;
		if (timeout < 0) {
			timeout = 0;
		}
		DWORD res = WaitForMultipleObjects(waitCount, exitingThreadHandles + i, TRUE, (DWORD)timeout);
		if (res == WAIT_FAILED || res == WAIT_TIMEOUT) {
			waitCount = exitingThreadHandleCount - i;
		}
		for (int j = 0; j < waitCount; ++j) {
			CloseHandle(exitingThreadHandles[i + j]);
		}
		if ((i += waitCount) >= exitingThreadHandleCount) {
			break;
		}
		startTime = OS::getTimeMillis();
	}
	exitingThreadHandleCount = 0;
	LeaveCriticalSection(&exitingCritSect);

	if (die) {
		_exit(exitCode);
	} else {
		::exit(exitCode);
	}
}

int OS::exitThread(int exitCode) {
	if (exitingProcessThreadId == 0) {
		EnterCriticalSection(&exitingCritSect);
		if (exitingProcessThreadId == 0) {
			int lastFreeIndex = 0;
			for (int i = 0; i < exitingThreadHandleCount; ++i) {
				HANDLE handle = exitingThreadHandles[i];
				DWORD res = WaitForSingleObject(handle, 0); // 0: don't wait
				if (res == WAIT_TIMEOUT) {
					exitingThreadHandles[lastFreeIndex++] = handle;
				} else {
					CloseHandle(handle);
				}
			}

			exitingThreadHandleCount = lastFreeIndex;
			if (exitingThreadHandleCount < MAXIMUM_THREADS_TO_KEEP) {
				HANDLE currentProcess = GetCurrentProcess();
				HANDLE currentThread = GetCurrentThread();
				if (DuplicateHandle(currentProcess, currentThread, currentProcess, &exitingThreadHandles[lastFreeIndex],
					0, FALSE, DUPLICATE_SAME_ACCESS)) {
					exitingThreadHandleCount++;
				}
			}
		}
		LeaveCriticalSection(&exitingCritSect);
	}
	_endthreadex((unsigned)exitCode);
	return exitCode;
}

// to fix crash issue, EnumObjects crash after java.base init
// refer test case: DeserializedJFileChooserTest
void fix() {
	IShellFolder* pDesktop;
	HRESULT res = SHGetDesktopFolder(&pDesktop);
	if (res != S_OK) {
		return;
	}
	LPITEMIDLIST relPIDL;
	res = SHGetSpecialFolderLocation(NULL, CSIDL_DRIVES, &relPIDL);
	if (res != S_OK) {
		pDesktop->Release();
		return;
	}
	IShellFolder* pFolder;
	res = pDesktop->BindToObject(relPIDL, NULL, IID_IShellFolder, (void**)&pFolder);
	if (res != S_OK) {
		pDesktop->Release();
		return;
	}
	DWORD dwFlags = SHCONTF_FOLDERS | SHCONTF_NONFOLDERS;
	IEnumIDList* pEnum = nullptr;
	if (pFolder->EnumObjects(NULL, dwFlags, &pEnum) != S_OK) {
		pFolder->Release();
		pDesktop->Release();
		return;
	}
	pEnum->Release();
	pFolder->Release();
	pDesktop->Release();
}

void OS::init() {
	initSystemInfo();
	InitializeCriticalSection(&exitingCritSect);

	_setmode(_fileno(stdin), _O_BINARY);
	_setmode(_fileno(stdout), _O_BINARY);
	_setmode(_fileno(stderr), _O_BINARY);

	fix();
}

bool OS::init2(void) {
	topLevelVectoredExceptionHandler = AddVectoredExceptionHandler(1, topLevelVectoredExceptionFilter);
	previousUnhandledExceptionFilter = SetUnhandledExceptionFilter(topLevelUnhandledExceptionFilter);

	size_t stackCommitSize = $align_up(ThreadStackSize * K, OS::getPageSize());
	JavaThread::setStackSizeAtCreate(stackCommitSize);

	// init sock
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		jio_fprintf(stderr, "Could not initialize Winsock (error: %d)\n", ::GetLastError());
		return false;
	}

	WindowsDecoder::init();
	initMiscSignal();
	return true;
}

void OS::exit(int num) {
	OS::exitProcess(false, num);
}

inline bool isFileSepChar(char c) {
	return (c) == '/' || (c) == '\\';
}

char* OS::toNativePath(char* path) {
	char* src = path;
	while (isFileSepChar(*src)) {
		src++;
	}

	char* dst = path;
	char* colon = nullptr;
	if (::isalpha(*src) && !::IsDBCSLeadByte(*src) && src[1] == ':') {
		*dst++ = *src++;
		colon = dst;
		*dst++ = ':';
		src++;
	} else {
		src = path;
		if (isFileSepChar(src[0]) && isFileSepChar(src[1])) {
			src = dst = path + 1;
			path[0] = '\\';
		}
	}

	char* end = dst;

	while (*src != '\0') {
		if (isFileSepChar(*src)) {
			*dst++ = '\\';
			src++;
			while (isFileSepChar(*src)) {
				src++;
			}
			if (*src == '\0') {
				end = dst;
				if (colon == dst - 2) {
					break;
				}
				if (dst == path + 1) {
					break;
				}
				if (dst == path + 2 && isFileSepChar(path[0])) {
					break;
				}
				end = --dst;
				break;
			}
			end = dst;
		} else {
			if (::IsDBCSLeadByte(*src)) {
				*dst++ = *src++;
				if (*src) {
					*dst++ = *src++;
				}
				end = dst;
			} else {
				char c = *src++;
				*dst++ = c;
				if (c != ' ') {
					end = dst;
				}
			}
		}
	}

	*end = '\0';

	if (colon == dst - 1) {
		path[2] = '.';
		path[3] = '\0';
	}
	return path;
}

class HighResolutionInterval {
public:
	HighResolutionInterval(jlong ms) {
		if (ms < 100 && ms % 10L != 0) {
			enable = true;
			timeBeginPeriod(1L);
		}
	}
	~HighResolutionInterval() {
		if (enable) {
			timeEndPeriod(1L);
		}
	}
private:
	bool enable = false;
};

int OS::ParkEvent::park(jlong Millis) {
	int oldEvent = event.load(std::memory_order_relaxed);
	while (true) {
		if (event.compare_exchange_weak(oldEvent, oldEvent - 1, std::memory_order_release, std::memory_order_relaxed)) {
			break;
		}
	}
	guarantee((oldEvent == 0) || (oldEvent == 1), "invariant");
	if (oldEvent != 0) {
		return OS_OK;
	}

	const int MAXTIMEOUT = 0x10000000;
	DWORD rv = WAIT_TIMEOUT;
	while (event < 0 && Millis > 0) {
		DWORD prd = (DWORD)Millis;
		if (Millis > MAXTIMEOUT) {
			prd = MAXTIMEOUT;
		}
		HighResolutionInterval phri(prd);
		rv = ::WaitForSingleObject(parkHandle, prd);
		if (rv == WAIT_TIMEOUT) {
			Millis -= prd;
		}
	}
	oldEvent = event;
	event = 0;
	$fence();
	return (oldEvent >= 0) ? OS_OK : OS_TIMEOUT;
}

void OS::ParkEvent::park() {
	int oldEvent = event.load(std::memory_order_relaxed);
	while (true) {
		if (event.compare_exchange_weak(oldEvent, oldEvent - 1, std::memory_order_release, std::memory_order_relaxed)) {
			break;
		}
	}
	guarantee((oldEvent == 0) || (oldEvent == 1), "invariant");
	if (oldEvent != 0) {
		return;
	}

	while (event < 0) {
		DWORD rv = ::WaitForSingleObject(parkHandle, INFINITE);
		if (rv == WAIT_OBJECT_0) {
			int i = 0;
			i++;
		}
	}
	event = 0;
	$fence();
	guarantee(event >= 0, "invariant");
}

void OS::ParkEvent::unpark() {
	if (event.exchange(1) >= 0) {
		return;
	}
	::SetEvent(parkHandle);
}

void OS::Parker::park(bool isAbsolute, jlong time) {
	if (time < 0) {
		return;
	} else if (time == 0 && !isAbsolute) {
		time = INFINITE;
	} else if (isAbsolute) {
		time -= OS::getTimeMillis();
		if (time <= 0) {
			return;
		}
	} else { // relative
		time /= NANOSECS_PER_MILLISEC;
		if (time == 0) {
			time = 1;
		}
	}

	JavaThread* thread = JavaThread::sureCurrentThread();
	if (thread == owner) {

		//   printf("thread == owner\n");
	}
	if (thread->isInterrupted(false) ||
		WaitForSingleObject(parkHandle, 0) == WAIT_OBJECT_0) {
		ResetEvent(parkHandle);
		$storestore();
		owner = thread;
		return;
	} else {
		JavaThreadStateInVMBlock tbivm(thread);
		WaitForSingleObject(parkHandle, (DWORD)time);
		ResetEvent(parkHandle);
		$storestore();
		owner = thread;
	}
}

void OS::Parker::unpark() {
	owner = nullptr;
	$storestore();
	guarantee(parkHandle != nullptr, "invariant");
	SetEvent(parkHandle);
}

bool OS::PlatformMonitor::wait(jlong millis) {
	int status = SleepConditionVariableCS(&cond, &mutex, millis == 0 ? INFINITE : (DWORD)millis);
	return status != 0;
}

void* OS::getDefaultProcessHandle() {
	return (void*)GetModuleHandle(nullptr);
}

static const OS::SignalInfo signalInfos[] = {
	DEFINE_SIGNAL_INFO(SIGABRT),
	DEFINE_SIGNAL_INFO(SIGFPE),
	DEFINE_SIGNAL_INFO(SIGSEGV),
	DEFINE_SIGNAL_INFO(SIGINT),
	DEFINE_SIGNAL_INFO(SIGTERM),
	DEFINE_SIGNAL_INFO(SIGBREAK),
	DEFINE_SIGNAL_INFO(SIGILL),
	{-1, nullptr}
};

int32_t OS::getSignalNumber(const char* signalName) {
	return getSignalNumber0(signalName, signalInfos);
}