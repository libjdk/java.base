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

#include "Platform.h"

#include <java/lang/Object.h>
#include <java/util/Objects.h>
#include <java/lang/Class.h>
#include <java/lang/System.h>
#include <java/lang/ObjectHead.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/ArrayList.h>
#include <java/lang/interpreter/ByteCodeObject.h>
#include <java/lang/ObjectManagerInternal.h>
#include <jcpp.h>

#include "Arguments.h"
#include "JavaThread.h"
#include "ObjectSynchronizer.h"
#include "ObjectMonitor.h"
#include "StackWalk.h"

#include "ffi.h"

#ifdef _WIN32
#include <windows.h>
#include <winuser.h>
#endif

using namespace ::java::lang;
using namespace ::java::util;
using $Method = ::java::lang::reflect::Method;
using $Constructor = ::java::lang::reflect::Constructor;
using $Executable = ::java::lang::reflect::Executable;
using $ArrayList = ::java::util::ArrayList;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $Modifier = ::java::lang::reflect::Modifier;

namespace java {
	namespace lang {

void Platform::init() {
	OS::init();
	Arguments::initSystemProperties();
	OS::initSystemProperties();
	Arguments::initVersionSpecificProperties();
	OS::init2();
	StackWalk::init();
#ifdef _WIN32
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
#endif
}

void Platform::init2() {
	OS::initSignalSupport();
}

bool Platform::isSupportedVersion(int32_t version) {
	switch (version) {
	case JNI_VERSION_1_2:
	case JNI_VERSION_1_4:
	case JNI_VERSION_1_6:
	case JNI_VERSION_1_8:
	case JNI_VERSION_9:
	case JNI_VERSION_10:
		return true;
	default:
		break;
	}
	return false;
}

int64_t Platform::getTimeMillis() {
	return OS::getTimeMillis();
}

int64_t Platform::getTimeNanos() {
	return OS::getTimeNanos();
}

int64_t Platform::getAvailableMemory() {
	return OS::getAvailableMemory();
}

int64_t Platform::getPhysicalMemory() {
	return OS::getPhysicalMemory();
}

int32_t Platform::getActiveProcessorCount() {
	return OS::getActiveProcessorCount();
}

int32_t Platform::getAddressSize() {
	return sizeof(void*);
}

int32_t Platform::getPageSize() {
	return OS::getPageSize();
}

void* Platform::getCurrentStackBase() {
	return OS::getCurrentStackBase();
}
size_t Platform::getCurrentStackSize() {
	return OS::getCurrentStackSize();
}

int64_t Platform::getCurrentStackPointer() {
	return OS::getCurrentStackPointer();
}

bool Platform::snapshotStackObjects(void* jthread) {
	return OS::snapshotStackObjects(jthread);
}

bool Platform::suspendThread(void* handle) {
	return OS::suspendThread(handle);
}

bool Platform::resumeThread(void* handle) {
	return OS::resumeThread(handle);
}

bool Platform::isBigEndian() {
	int32_t i = 1;
	int8_t ret = *((int8_t*)&i);
	return ret == 0;
}

bool Platform::isUnalignedAccess() {
	return false;
}

int32_t Platform::getDataCacheLineFlushSize() {
	return 0;
}

void Platform::freeObjectMonitor(ObjectHead* oh) {
	ObjectSynchronizer::freeMonitor(oh);
}

void Platform::JVM_MonitorWait(const Object$* obj, int64_t timeoutMs) {
	Object0* obj0 = $toObject0(obj);
	JavaThread* current = JavaThread::sureCurrentThread();
	current->checkAndHandleAsyncExceptions();
	JavaThreadInObjectWaitStatus jtiows(current, timeoutMs);
	ObjectSynchronizer::wait(obj0, timeoutMs, current);
}

void Platform::JVM_MonitorNotify(const Object$* obj) {
	Object0* obj0 = $toObject0(obj);
	JavaThread* current = JavaThread::sureCurrentThread();
	current->checkAndHandleAsyncExceptions();
	ObjectSynchronizer::notify(obj0, current);
}

void Platform::JVM_MonitorNotifyAll(const Object$* obj) {
	Object0* obj0 = $toObject0(obj);
	JavaThread* current = JavaThread::sureCurrentThread();
	current->checkAndHandleAsyncExceptions();
	ObjectSynchronizer::notifyAll(obj0, current);
}

void Platform::enterMonitor(const Object0* obj) {
	JavaThread* current = JavaThread::getCurrentThread();
	// avoid crash, before Systen inited, thread exit
	if (current != nullptr) {
		current->checkAndHandleAsyncExceptions();
		ObjectSynchronizer::enter(obj, current);
	}
}

bool Platform::tryEnterMonitor(const Object0* obj) {
	JavaThread* current = JavaThread::getCurrentThread();
	current->checkAndHandleAsyncExceptions();
	return ObjectSynchronizer::tryEnter(obj, current);
}

void Platform::exitMonitor(const Object0* obj) {
	JavaThread* current = JavaThread::getCurrentThread();
	// avoid crash, before Systen inited, thread exit
	if (current != nullptr) {
		current->checkAndHandleAsyncExceptions();
		ObjectSynchronizer::exit(obj, current);
	}
}

void Platform::upgradeMonitor(::java::lang::ObjectHead* oh) {
	JavaThread* current = JavaThread::sureCurrentThread();
	ObjectSynchronizer::upgradeMonitor(oh, current);
}

void Platform::registerMainThread(::java::lang::Thread* thread) {
	JavaThread::registerMainThread(thread);
}

void Platform::park(::java::lang::Thread* thread, bool isAbsolute, int64_t time) {
	JavaThread::park(thread, isAbsolute, time);
}

void Platform::unpark(::java::lang::Thread* thread) {
	JavaThread::unpark(thread);
}

void Platform::JVM_StartThread(::java::lang::Thread* thread) {
	JavaThread::JVM_StartThread(thread);
}

bool Platform::JVM_IsThreadAlive(::java::lang::Thread* thread) {
	return JavaThread::JVM_IsThreadAlive(thread);
}

void Platform::JVM_SetThreadPriority(::java::lang::Thread* thread, int32_t prio) {
	JavaThread::JVM_SetThreadPriority(thread, prio);
}

void Platform::JVM_StopThread(::java::lang::Thread* thread, Object$* throwable) {
	JavaThread::JVM_StopThread(thread, ($Object*)throwable);
}

void Platform::JVM_SuspendThread(::java::lang::Thread* thread) {
	JavaThread::JVM_SuspendThread(thread);
}

void Platform::JVM_ResumeThread(::java::lang::Thread* thread) {
	JavaThread::JVM_ResumeThread(thread);
}

void Platform::JVM_Interrupt(::java::lang::Thread* thread) {
	JavaThread::JVM_Interrupt(thread);
}

void Platform::clearInterruptEvent() {
	JavaThread::clearInterruptEvent();
}

void Platform::JVM_SetNativeThreadName(::java::lang::Thread* thread, ::java::lang::String* name) {
	JavaThread::JVM_SetNativeThreadName(thread, name);
}

void Platform::yield() {
	OS::yield();
}

void Platform::JVM_Yield() {
	JavaThread::JVM_Yield();
}

void Platform::JVM_Sleep(int64_t millis) {
	JavaThread::JVM_Sleep(millis);
}

bool Platform::JVM_HoldsLock(Object$* obj) {
	Object0* obj0 = $toObject0(obj);
	return JavaThread::JVM_HoldsLock(obj0);
}

void* Platform::getDefaultProcessHandle() {
	return OS::getDefaultProcessHandle();
}

const char* Platform::getExecutionFilePath(char* buf, int bufLen) {
	return OS::getExecutionFilePath(buf, bufLen);
}

void* Platform::loadLibrary(const char* filename, char* ebuf, int ebuflen) {
	return OS::loadLibrary(filename, ebuf, ebuflen);
}

void Platform::unloadLibrary(void* lib) {
	OS::unloadLibrary(lib);
}

bool Platform::getLibraryWithAddress(void* addr, char* buf, int buflen) {
	return OS::getLibraryWithAddress((address)addr, buf, buflen);
}

void* Platform::findLibraryEntry(void* handle, const char* name) {
	return OS::getFromLibrary(handle, name);
}

size_t Platform::getLastErrorDesc(char* buf, size_t len) {
	return OS::getLastErrorDesc(buf, len);
}

void* Platform::getJNIEnv() {
	return JavaThread::sureCurrentThread()->getJNIEnv();
}

$Array<::java::lang::Thread>* Platform::JVM_GetAllThreads() {
	return ObjectManagerInternal::getAllThreads();
}

$Array<::java::lang::StackTraceElement, 2>* Platform::JVM_DumpThreads($Array<::java::lang::Thread>* threads) {
	return JavaThread::JVM_DumpThreads(threads);
}

::java::lang::Thread* Platform::JVM_CurrentThread() {
	return JavaThread::JVM_CurrentThread();
}

bool methodEquals($Method* m0, $Method* m1) {
	if (m0->name->equals(m1->name)// && m0->returnType == m1->returnType 
		&& m0->parameterTypes->length == m1->parameterTypes->length) {
		for (int32_t i = 0; i < m0->parameterTypes->length; i++) {
			if (m0->parameterTypes->get(i) != m1->parameterTypes->get(i)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

$Method* findTargetMethod($ArrayList* targetMethods, $Method* method) {
	for (int32_t i = 0; i < targetMethods->size(); i++) {
		$Method* targetMethod = $fcast<$Method>(targetMethods->get(i));
		if (methodEquals(targetMethod, method)) {
			return targetMethod;
		}
	}
	return nullptr;
}

void select($ArrayList* targetMethods, $Method* method) {
	for (int32_t i = 0; i < targetMethods->size(); i++) {
		$var($Method, targetMethod, $fcast<$Method>(targetMethods->get(i)));
		if (methodEquals(targetMethod, method)) {
			bool flag = false;
			if (targetMethod->clazz->isInterface()) {
				if (method->clazz->isInterface()) {
					if (targetMethod->isDefault()) {
						flag = false;
					} else {
						flag = true;
					}
				} else {
					if (targetMethod->isDefault()) {
						if ($Modifier::isAbstract(method->getModifiers())) {
							flag = false;
						} else {
							flag = true;
						}
					} else {
						flag = true;
					}
				}
			} else {
				if (method->clazz->isInterface()) {
					if ($Modifier::isAbstract(targetMethod->getModifiers())) {
						if (method->isDefault()) {
							flag = true;
						} else {
							flag = false;
						}
					}
				} else {
					if ($Modifier::isAbstract(targetMethod->getModifiers())) {
						if ($Modifier::isAbstract(method->getModifiers())) {
							flag = true;
						} else {
							flag = true;
						}
					} else {
						if ($Modifier::isAbstract(method->getModifiers())) {
							flag = false;
						} else {
							flag = true;
						}
					}
				}
			}
			if (flag) {
				targetMethods->set(i, method);
			}
			return;
		}
	}
}

void merge($ArrayList* targetMethods, int32_t begin, $Method* method) {
#ifdef _WIN32
	for (int32_t i = begin; i < targetMethods->size(); i++) {
		$var($Method, targetMethod, $fcast<$Method>(targetMethods->get(i)));
		if (Objects::equals(targetMethod->getName(), method->getName())) {
			targetMethods->add(i, method);
			return;
		}
	}
	targetMethods->add(method);
#else
	targetMethods->add(method);
#endif
}

$MethodArray* getVirtualMethods0(Class* clazz, $ArrayList* baseMethods) {
	$var($ArrayList, methods, $new<$ArrayList>());
	$var(Class, primaryBase, nullptr);
	Class* superClass = clazz->getSuperclass();
	if (superClass != nullptr && superClass != Object::class$) {
		$assign(primaryBase, superClass);
	}
	$var($ClassArray, interfaces, clazz->getInterfaces(false));
	if (primaryBase == nullptr && interfaces->length > 0) {
		$assign(primaryBase, $fcast<Class>(interfaces->get(0)));
	}
	if (primaryBase == nullptr && clazz != Object::class$) {
		$assign(primaryBase, Object::class$);
	}

	if (primaryBase != nullptr) {
		$var($MethodArray, primaryBaseMethods, getVirtualMethods0(primaryBase, baseMethods));
		for (int32_t i = 0; i < primaryBaseMethods->length; i++) {
			$var($Method, method, primaryBaseMethods->get(i));
			methods->add(method);
		}
	}

	for (int32_t i = 0; i < interfaces->length; i++) {
		Class* ifc = $fcast<Class>(interfaces->get(i));
		if (ifc == primaryBase) {
			continue;
		}
		$var($MethodArray, ifcMethods, getVirtualMethods0(ifc, baseMethods));
		for (int32_t j = 0; j < ifcMethods->length; j++) {
			$Method* method = $fcast<$Method>(ifcMethods->get(j));
			select(methods, method);
		}
	}

	int32_t begin = methods->size();
	$var($MethodArray, declaredMethods, clazz->getDeclaredMethods(false, true));
	for (int32_t i = 0; i < declaredMethods->length; i++) {
		$Method* method = ($Method*)declaredMethods->get(i);
		if (method->isStatic()) {
			continue;
		}
		if ($Modifier::isPrivate(method->getModifiers())) {
			continue;
		}
		if (findTargetMethod(methods, method) != nullptr) {
			select(methods, method);
			continue;
		}
#ifdef _WIN32
		if (findTargetMethod(baseMethods, method) != nullptr) {
			continue;
		}
		if ($Modifier::isFinal(method->getModifiers())) {
			continue;
		}
		if ($Modifier::isFinal(clazz->getModifiers())) {
			continue;
		}
		baseMethods->add(method);
#else // GCC
		if (findTargetMethod(baseMethods, method) != nullptr) {
			//	continue;
		} else {
			if ($Modifier::isFinal(method->getModifiers())) {
				continue;
			}
			if ($Modifier::isFinal(clazz->getModifiers())) {
				continue;
			}
			baseMethods->add(method);
		}
#endif
		merge(methods, begin, method);
	}

	return $fcast<$MethodArray>(methods->toArray($$new($MethodArray, 0)));
}

$MethodArray* Platform::getVirtualMethods(Class* clazz) {
	$var($ArrayList, baseMethods, $new<$ArrayList>());
	return getVirtualMethods0(clazz, baseMethods);
}

$MethodArray* Platform::getBaseClassVirtualMethods(Class* clazz, Class* baseClass) {
	if (clazz == baseClass) {
		return getVirtualMethods(clazz);
	}
	$var($ArrayList, methods, $new<$ArrayList>());
	$var($MethodArray, methods2, getVirtualMethods(baseClass));
	for (int32_t i = 0; i < methods2->length; i++) {
		$var($Method, method, methods2->get(i));
		methods->add(method);
	}

	$var($MethodArray, declaredMethods, clazz->getDeclaredMethods(false, true));
	for (int32_t i = 0; i < declaredMethods->length; i++) {
		$Method* method = $fcast<$Method>(declaredMethods->get(i));
		if (method->isStatic()) {
			continue;
		}
		if ($Modifier::isPrivate(method->getModifiers())) {
			continue;
		}
		if (findTargetMethod(methods, method) != nullptr) {
			select(methods, method);
			continue;
		}
	}

	return $fcast<$MethodArray>(methods->toArray($$new($MethodArray, 0)));
}

bool Platform::setVirtualInvokeAddress(::java::lang::reflect::Method* method) {
	$var($ClassArray, classes, method->clazz->getPrimaryBaseClasses());
	for (int32_t i = 0; i < classes->length; i++) {
		Class* clazz = classes->get(i);

		int32_t offset = method->clazz->getBaseClassOffset(clazz);
		$var($Array<$Method>, methods, nullptr);

		if (offset == 0) {
			$assign(methods, getVirtualMethods(method->clazz));
		} else {
			$assign(methods, getBaseClassVirtualMethods(method->clazz, clazz));
		}
		for (int32_t methodIndex = 0; methodIndex < methods->length; methodIndex++) {
			$Method* method0 = ($Method*)methods->get(methodIndex);
			if (method->name == method0->name && $ObjectArray::equals(method->parameterTypes, method0->parameterTypes)) {
				int32_t virtualIndex = methodIndex;

#ifdef JCPP_USE_VIRTUAL_DESTRUCTOR // virtual ~Object()
				virtualIndex++;
	#if defined(__clang__) || defined(__GNUC__)
				// the-deleting-destructor-occupy-a-second-vtable-slot
				virtualIndex++;
	#endif
#endif

#ifdef JCPP_USE_VIRTUAL_TO_OBJECT0
				virtualIndex++;
#endif
				$var(Object, instance0, method0->clazz->allocateInstance());
				void* invokeAddress = getVirtualInvokeAddress(instance0, offset, virtualIndex);
				$synchronized(method) {
					method->invokeAddress = invokeAddress;
					method->virtualOffset = offset;
					method->virtualIndex = virtualIndex;
				}
				return true;
			}
		}
	}
	return false;
}

#ifdef _WIN32
struct RTTIEx {
	void* opt;
	RTTICompleteObjectLocator col;
	RTTICompleteObjectLocator* pcol = nullptr;
	RTTIEx(void* opt) {
		this->opt = opt;
	}
	void setRTTI(RTTI* rtti) {
		col = *rtti->pcol;
	}
	void setObject0Offset(int32_t offset) {
		col.offset = offset;
	}
	void encode(int8_t* data) {
		memcpy(data, this, sizeof(RTTIEx));
		RTTIEx* p = (RTTIEx*)data;
		p->pcol = &p->col;
	}
	//	int32_t getOffset() {
	//		return col.offset;
	//	}
	static constexpr int32_t size() {
		return sizeof(RTTIEx);
	}
};

#else // GCC 64

struct RTTIEx {
	void* opt;
	int64_t offset;
	void* typeinfo = nullptr;
	RTTIEx(void* opt) {
		this->opt = opt;
	}
	void setRTTI(RTTI* rtti) {
		this->offset = rtti->offset;
		this->typeinfo = rtti->typeinfo;
	}
	void setObject0Offset(int32_t objectOffset) {
		this->offset = -objectOffset;
	}
	void encode(int8_t* data) {
		((void**)data)[0] = opt;
		data += sizeof(void*);
		((int64_t*)data)[0] = offset;
		data += sizeof(offset);
		((void**)data)[0] = nullptr;
	}
	//	int32_t getOffset() {
	//		return offset;
	//	}
	static constexpr int32_t size() {
		return sizeof(RTTIEx);
	}
};

#endif

$bytes* Platform::makeVirtualFunctionTable(int32_t objectOffset, int32_t count, void** addresses, void* opt) {
	RTTIEx head(opt);
	head.setObject0Offset(objectOffset);
	int32_t dataSize = head.size() + (count + 1) * sizeof(void*);
	$var($bytes, data, $new<$bytes>(dataSize));
	int8_t* begin = data->begin();
	head.encode(begin);
	void** vfts = (void**)(begin + head.size());
	for (int32_t i = 0; i < count; i++) {
		vfts[i] = addresses[i];
	}
	vfts[count] = nullptr;
	return data;
}

int8_t* Platform::makeRTTIAndVFTable(Object$* obj, int32_t objectOffset, int32_t count, void** addresses, void* opt) {
	RTTI* vfth = (RTTI*)((int8_t*)(*(void**)obj) - sizeof(RTTI));
	//RTTIInfo* vfth = RTTIInfo::fromObject(THIS);
	RTTIEx head(opt);
	head.setRTTI(vfth);
	head.setObject0Offset(objectOffset);
	int32_t dataSize = head.size() + (count + 1) * sizeof(void*);
	//$var($bytes, data, $new<$bytes>(dataSize));
	int8_t* begin = $allocRawStatic<int8_t>(dataSize);
	//int8_t* begin = data->begin();
	head.encode(begin);
	void** vfts = (void**)(begin + head.size());
	for (int32_t i = 0; i < count; i++) {
		vfts[i] = addresses[i];
	}
	vfts[count] = nullptr;
	return begin;
	//return data;
}

void** Platform::rttiToVFTable(int8_t* rttiData) {
//void** Platform::getVirtualFunctionTable($bytes* data) {
	//int8_t* begin = data->begin();
	void** vfts = (void**)(rttiData + RTTIEx::size());
	return vfts;
}

void Platform::assembleVfTab(Object$* obj, int32_t objectOffset, $bytes* data) {
	int8_t* addr = (int8_t*)obj;
	addr += objectOffset;
	void** pVtab = (void**)(addr);
	//	int64_t* vtab = vfptrInfo->vfTab->begin() + 1; // index 0: is pointer of vfptrInfo
	void** vtab = Platform::rttiToVFTable(data->begin());
	*pVtab = vtab;
}

int32_t Platform::getObjectOffset(Object$* obj) {
	//void** pVtabByteCode0 = (void**)((int8_t*)obj);
	//void* ptr = pVtabByteCode0[0];
	//RTTI* vfth = (RTTI*)((int8_t*)(ptr) - sizeof(RTTIInfo));
	RTTI* rtti = RTTI::fromObject(obj);
	return rtti->getOffset();
}

void* Platform::getOpt(const Object$* obj) {
	void** pVtabByteCode0 = (void**)((int8_t*)obj);
	void* ptr = pVtabByteCode0[0];
	RTTIEx* vfth = (RTTIEx*)((int8_t*)(ptr) - RTTIEx::size());
	return vfth->opt;
}

void* Platform::getVirtualInvokeAddress(Object$* obj, int32_t offset, int32_t index) {
	void*** pVtabByteCode0 = (void***)((int8_t*)obj + offset);
	void* invokeAddress = pVtabByteCode0[0][index];
	return invokeAddress;
}

void* Platform::getVirtualInvokeAddress(Object$* obj, ::java::lang::reflect::Method* method) {
	return getVirtualInvokeAddress(obj, method->virtualOffset, method->virtualIndex);
}

ffi_type prepareReturnType(Class* type) {
	if (type->isPrimitive()) {
		if (type == Byte::TYPE) {
			return ffi_type_sint8;
		} else if (type == Short::TYPE) {
			return ffi_type_sint16;
		} else if (type == Integer::TYPE) {
			return ffi_type_sint32;
		} else if (type == Long::TYPE) {
			return ffi_type_sint64;
		} else if (type == Float::TYPE) {
			return ffi_type_float;
		} else if (type == Double::TYPE) {
			return ffi_type_double;
		} else if (type == Boolean::TYPE) {
			return ffi_type_sint8;
		} else if (type == Character::TYPE) {
			return ffi_type_uint16;
		} else {
			return ffi_type_void;
		}
	} else {
		return ffi_type_pointer;
	}
}

void prepareArgs($ClassArray* parameterTypes, void** ffiArgs, $Value* argv) {
	for (int32_t i = 0; i < parameterTypes->length; i++) {
		$Class* type = parameterTypes->get(i);
		if (type->isPrimitive()) {
			if (type == Byte::TYPE) {
				ffiArgs[i] = &(argv[i].byteValue());
			} else if (type == Short::TYPE) {
				ffiArgs[i] = &(argv[i].shortValue());
			} else if (type == Integer::TYPE) {
				ffiArgs[i] = &(argv[i].intValue());
			} else if (type == Long::TYPE) {
				ffiArgs[i] = &(argv[i].longValue());
			} else if (type == Float::TYPE) {
				ffiArgs[i] = &(argv[i].floatValue());
			} else if (type == Double::TYPE) {
				ffiArgs[i] = &(argv[i].doubleValue());
			} else if (type == Boolean::TYPE) {
				ffiArgs[i] = &(argv[i].booleanValue());
			} else if (type == Character::TYPE) {
				ffiArgs[i] = &(argv[i].charValue());
			}
		} else {
			ffiArgs[i] = &(argv[i].is<Object$>());
		}
	}
}

void prepareArgsJni($ClassArray* parameterTypes, void** ffiArgs, $Value* argv, va_list args, ObjectArray* globalRefed) {
	for (int32_t i = 0; i < parameterTypes->length; i++) {
		$Class* type = parameterTypes->get(i);
		if (type->isPrimitive()) {
			if (type == Byte::TYPE) {
				argv[i].byteValue() = (int8_t)va_arg(args, int32_t);
				ffiArgs[i] = &(argv[i].byteValue());
			} else if (type == Short::TYPE) {
				argv[i].shortValue() = (int16_t)va_arg(args, int32_t);
				ffiArgs[i] = &(argv[i].shortValue());
			} else if (type == Integer::TYPE) {
				argv[i].intValue() = va_arg(args, int32_t);
				ffiArgs[i] = &(argv[i].intValue());
			} else if (type == Long::TYPE) {
				argv[i].longValue() = va_arg(args, int64_t);
				ffiArgs[i] = &(argv[i].longValue());
			} else if (type == Float::TYPE) {
				// float is coerced to double
				argv[i].floatValue() = (float)va_arg(args, double);
				ffiArgs[i] = &(argv[i].floatValue());
			} else if (type == Double::TYPE) {
				argv[i].doubleValue() = va_arg(args, double);
				ffiArgs[i] = &(argv[i].doubleValue());
			} else if (type == Boolean::TYPE) {
				argv[i].booleanValue() = va_arg(args, int32_t) != 0;
				ffiArgs[i] = &(argv[i].booleanValue());
			} else if (type == Character::TYPE) {
				argv[i].charValue() = (char16_t)va_arg(args, int32_t);
				ffiArgs[i] = &(argv[i].charValue());
			}
		} else {
			Object* obj = va_arg(args, Object*);
			if (Platform::isGlobalRef(obj)) {
				obj = Platform::resolveRef(obj);
				globalRefed->set(i, obj);
			}
			argv[i] = obj;
			ffiArgs[i] = &(argv[i].objectValue());
		}
	}
}

void prepareArgsJni($ClassArray* parameterTypes, void** ffiArgs, $Value* argv, const jvalue* args, ObjectArray* globalRefed) {
	for (int32_t i = 0; i < parameterTypes->length; i++) {
		$Class* type = parameterTypes->get(i);
		if (type->isPrimitive()) {
			if (type == Byte::TYPE) {
				argv[i].byteValue() = (int8_t)args[i].b;
				ffiArgs[i] = &(argv[i].byteValue());
			} else if (type == Short::TYPE) {
				argv[i].shortValue() = (int16_t)args[i].s;
				ffiArgs[i] = &(argv[i].shortValue());
			} else if (type == Integer::TYPE) {
				argv[i].intValue() = (int32_t)args[i].i;
				ffiArgs[i] = &(argv[i].intValue());
			} else if (type == Long::TYPE) {
				argv[i].longValue() = (int64_t)args[i].j;
				ffiArgs[i] = &(argv[i].longValue());
			} else if (type == Float::TYPE) {
				// float is coerced to double
				argv[i].floatValue() = (float)args[i].f;
				ffiArgs[i] = &(argv[i].floatValue());
			} else if (type == Double::TYPE) {
				argv[i].doubleValue() = (double)args[i].d;
				ffiArgs[i] = &(argv[i].doubleValue());
			} else if (type == Boolean::TYPE) {
				argv[i].booleanValue() = (bool)args[i].z;
				ffiArgs[i] = &(argv[i].booleanValue());
			} else if (type == Character::TYPE) {
				argv[i].charValue() = (char16_t)args[i].c;
				ffiArgs[i] = &(argv[i].charValue());
			}
		} else {
			Object* obj = (Object*)args[i].l;
			if (Platform::isGlobalRef(obj)) {
				obj = Platform::resolveRef(obj);
				globalRefed->set(i, obj);
			}
			argv[i] = obj;
			ffiArgs[i] = &(argv[i].objectValue());
		}
	}
}

$Value Platform::invokev(bool special, $Method* method, Object$* obj, $Value* argv) {
	//	::java::lang::System::out->println(method->getDescriptor());
	//	if (method->name->equals("setUninterruptible")) {
	//		method->name->toString();
	//	}
	//	$Object0* obj0 = nullptr;
	//	if (!method->isStatic()) {
		//	obj0 = $toObject0(obj);
	//		obj = Class::sure(method->clazz, obj);
	//	}
	void(*invokeAddress)() = (void(*)())method->invokeAddress;
	if (method->virtualIndex > 0) {
		if (!special) {
			invokeAddress = (void(*)())getVirtualInvokeAddress(obj, method);
		}
	} else if (invokeAddress == nullptr) {
		setVirtualInvokeAddress(method);
		if (special) {
			invokeAddress = (void(*)())method->invokeAddress;
		} else {
			invokeAddress = (void(*)())getVirtualInvokeAddress(obj, method);
		}
	}

	$ClassArray* parameterTypes = method->getSharedParameterTypes();
	int32_t parameterTypesLength = parameterTypes->length;
	int32_t argCount = parameterTypesLength;
	if (!method->isStatic()) {
		argCount++;
	}
	$var($bytes, typeBytes, prepareParameterTypes(method->isStatic(), parameterTypes));
	ffi_type** types = (ffi_type**)typeBytes->begin();

	Class* returnType = method->getReturnType();
	ffi_type retType = prepareReturnType(returnType);

	$var($bytes, argsBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	void** ffiArgs = (void**)argsBytes->begin();
	int32_t index = 0;
	if (!method->isStatic()) {
		if (method->virtualOffset > 0) { // since the virtual method maybe change this address
			obj = (int8_t*)obj + method->virtualOffset;
		}
		ffiArgs[index] = &obj;
		index++;
		prepareArgs(parameterTypes, ffiArgs + 1, argv);
	} else {
		prepareArgs(parameterTypes, ffiArgs, argv);
	}

	ffi_cif cif;
	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argCount, &retType, types);

	$Value ret;
	ffi_call(&cif, invokeAddress, &ret, ffiArgs);
	return ret;
}

$Value Platform::invokeJni(bool special, ::java::lang::reflect::Method* method, Object$* jobj, va_list args) {
	$var(Object, obj, resolveRef(jobj));
	void(*invokeAddress)() = (void(*)())method->invokeAddress;
	if (method->virtualIndex > 0) {
		if (!special) {
			invokeAddress = (void(*)())getVirtualInvokeAddress(obj, method);
		}
	} else if (invokeAddress == nullptr) {
		setVirtualInvokeAddress(method);
		if (special) {
			invokeAddress = (void(*)())method->invokeAddress;
		} else {
			invokeAddress = (void(*)())getVirtualInvokeAddress(obj, method);
		}
	}

	$ClassArray* parameterTypes = method->getSharedParameterTypes();
	int32_t parameterTypesLength = parameterTypes->length;
	int32_t argCount = parameterTypesLength;
	if (!method->isStatic()) {
		argCount++;
	}
	$var($bytes, typeBytes, prepareParameterTypes(method->isStatic(), parameterTypes));
	ffi_type** types = (ffi_type**)typeBytes->begin();

	Class* returnType = method->getReturnType();
	ffi_type retType = prepareReturnType(returnType);

	$var($bytes, argsBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	void** ffiArgs = (void**)argsBytes->begin();
	$var($bytes, argvBytes, $new<$bytes>(sizeof($Value*) * parameterTypesLength));
	$Value* argv = ($Value*)argvBytes->begin();
	$var(ObjectArray, globalRefed, $new<ObjectArray>(parameterTypesLength));
	int32_t index = 0;
	if (!method->isStatic()) {
		if (method->virtualOffset > 0) { // since the obj should be right before call this function, need not change with offset
			//			obj = (int8_t*)obj + method->virtualOffset;
		}
		ffiArgs[index] = &obj;
		index++;
		prepareArgsJni(parameterTypes, ffiArgs + 1, argv, args, globalRefed);
	} else {
		prepareArgsJni(parameterTypes, ffiArgs, argv, args, globalRefed);
	}

	ffi_cif cif;
	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argCount, &retType, types);

	$Value ret;
	ffi_call(&cif, invokeAddress, &ret, ffiArgs);
	return ret;
}

$Value Platform::invokeJni(bool special, ::java::lang::reflect::Method* method, Object$* jobj, const jvalue* args) {
	$var(Object, obj, resolveRef(jobj));
	void(*invokeAddress)() = (void(*)())method->invokeAddress;
	if (method->virtualIndex > 0) {
		if (!special) {
			invokeAddress = (void(*)())getVirtualInvokeAddress(obj, method);
		}
	} else if (invokeAddress == nullptr) {
		setVirtualInvokeAddress(method);
		if (special) {
			invokeAddress = (void(*)())method->invokeAddress;
		} else {
			invokeAddress = (void(*)())getVirtualInvokeAddress(obj, method);
		}
	}

	$ClassArray* parameterTypes = method->getSharedParameterTypes();
	int32_t parameterTypesLength = parameterTypes->length;
	int32_t argCount = parameterTypesLength;
	if (!method->isStatic()) {
		argCount++;
	}
	$var($bytes, typeBytes, prepareParameterTypes(method->isStatic(), parameterTypes));
	ffi_type** types = (ffi_type**)typeBytes->begin();

	Class* returnType = method->getReturnType();
	ffi_type retType = prepareReturnType(returnType);

	$var($bytes, argsBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	void** ffiArgs = (void**)argsBytes->begin();
	$var($bytes, argvBytes, $new<$bytes>(sizeof($Value*) * parameterTypesLength));
	$Value* argv = ($Value*)argvBytes->begin();
	$var(ObjectArray, globalRefed, $new<ObjectArray>(parameterTypesLength));
	int32_t index = 0;
	if (!method->isStatic()) {
		if (method->virtualOffset > 0) { // since the obj should be right before call this function, need not change with offset
			//			obj = (int8_t*)obj + method->virtualOffset;
		}
		ffiArgs[index] = &obj;
		index++;
		prepareArgsJni(parameterTypes, ffiArgs + 1, argv, args, globalRefed);
	} else {
		prepareArgsJni(parameterTypes, ffiArgs, argv, args, globalRefed);
	}

	ffi_cif cif;
	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argCount, &retType, types);

	$Value ret;
	ffi_call(&cif, invokeAddress, &ret, ffiArgs);
	return ret;
}

$Object* of($Value var, Class* type) {
	if (type->isPrimitive()) {
		if (type == Byte::TYPE) {
			return $of(var.byteValue());
		} else if (type == Short::TYPE) {
			return $of(var.shortValue());
		} else if (type == Integer::TYPE) {
			return $of(var.intValue());
		} else if (type == Long::TYPE) {
			return $of(var.longValue());
		} else if (type == Float::TYPE) {
			return $of(var.floatValue());
		} else if (type == Double::TYPE) {
			return $of(var.doubleValue());
		} else if (type == Boolean::TYPE) {
			return $of(var.booleanValue());
		} else if (type == Character::TYPE) {
			return $of(var.charValue());
		} else if (type == Void::TYPE) {
			return Void::VOID$;
		}
		return Void::VOID$;
	} else {
		return var.objectValue();
	}
}

$Object* Platform::invoke($Method* method, Object$* obj, $Value* argv) {
	$Value ret = invokev(false, method, obj, argv);
	return of(ret, method->getReturnType());
}

$Object* Platform::invokeSpecial($Method* method, Object$* obj, $Value* argv) {
	$Value ret = invokev(true, method, obj, argv);
	return of(ret, method->getReturnType());
}

void Platform::initInstance($Constructor* constructor, Object$* obj, $Value* argv) {
	void(*invokeAddress)() = (void(*)())$nullcheck(constructor)->invokeAddress;
	$nullcheck(obj);
	if (invokeAddress == nullptr) {
		//	setVirtualInvokeAddress(constructor);
		//	invokeAddress= (void(*)())method->invokeAddress;
	}
	$ClassArray* parameterTypes = constructor->getSharedParameterTypes();
	int32_t argCount = parameterTypes->length + 1;
	$var($bytes, typeBytes, prepareParameterTypes(false, parameterTypes));
	ffi_type** types = (ffi_type**)typeBytes->begin();
	ffi_type* retType = &ffi_type_void;

	$var($bytes, argsBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	void** ffiArgs = (void**)argsBytes->begin();
	int32_t index = 0;
	ffiArgs[index] = &obj;
	index++;

	prepareArgs(parameterTypes, ffiArgs + 1, argv);

	ffi_cif cif;
	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argCount, retType, types);

	$Value ret;
	ffi_call(&cif, invokeAddress, &ret, ffiArgs);
}

void Platform::initInstanceJni($Constructor* constructor, Object$* jobj, va_list args) {
	$var(Object, obj, resolveRef(jobj));
	void(*invokeAddress)() = (void(*)())$nullcheck(constructor)->invokeAddress;
	$nullcheck(obj);
	if (invokeAddress == nullptr) {
		//	setVirtualInvokeAddress(constructor);
		//	invokeAddress= (void(*)())method->invokeAddress;
	}
	$ClassArray* parameterTypes = constructor->getSharedParameterTypes();
	int32_t argCount = parameterTypes->length + 1;
	$var($bytes, typeBytes, prepareParameterTypes(false, parameterTypes));
	$var($bytes, argvBytes, $new<$bytes>(sizeof($Value*) * parameterTypes->length));
	$Value* argv = ($Value*)argvBytes->begin();
	ffi_type** types = (ffi_type**)typeBytes->begin();
	ffi_type* retType = &ffi_type_void;

	$var($bytes, argsBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	void** ffiArgs = (void**)argsBytes->begin();
	int32_t index = 0;
	ffiArgs[index] = &obj;
	index++;
	$var(ObjectArray, globalRefed, $new<ObjectArray>(parameterTypes->length));
	prepareArgsJni(parameterTypes, ffiArgs + 1, argv, args, globalRefed);

	ffi_cif cif;
	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argCount, retType, types);

	$Value ret;
	ffi_call(&cif, invokeAddress, &ret, ffiArgs);
}

void Platform::initInstanceJni($Constructor* constructor, Object$* jobj, const jvalue* args) {
	$var(Object, obj, resolveRef(jobj));
	void(*invokeAddress)() = (void(*)())constructor->invokeAddress;
	if (invokeAddress == nullptr) {
		//	setVirtualInvokeAddress(constructor);
		//	invokeAddress= (void(*)())method->invokeAddress;
	}
	$ClassArray* parameterTypes = constructor->getSharedParameterTypes();
	int32_t argCount = parameterTypes->length + 1;
	$var($bytes, typeBytes, prepareParameterTypes(false, parameterTypes));
	$var($bytes, argvBytes, $new<$bytes>(sizeof($Value*) * parameterTypes->length));
	$Value* argv = ($Value*)argvBytes->begin();
	ffi_type** types = (ffi_type**)typeBytes->begin();
	ffi_type* retType = &ffi_type_void;

	$var($bytes, argsBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	void** ffiArgs = (void**)argsBytes->begin();
	int32_t index = 0;
	ffiArgs[index] = &obj;
	index++;

	$var(ObjectArray, globalRefed, $new<ObjectArray>(parameterTypes->length));
	prepareArgsJni(parameterTypes, ffiArgs + 1, argv, args, globalRefed);

	ffi_cif cif;
	ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argCount, retType, types);

	$Value ret;
	ffi_call(&cif, invokeAddress, &ret, ffiArgs);
}

$bytes* Platform::prepareParameterTypes(bool isStatic, $ClassArray* parameterTypes) {
	int32_t argCount = parameterTypes->length;
	if (!isStatic) {
		argCount++;
	}
	$var($bytes, typeBytes, $new<$bytes>(sizeof(ffi_type*) * argCount));
	ffi_type** types;
	types = (ffi_type**)typeBytes->begin();
	int32_t index = 0;
	if (!isStatic) {
		types[index] = &ffi_type_pointer;
		index++;
	}
	for (int32_t i = 0; i < parameterTypes->length; index++, i++) {
		$Class* type = parameterTypes->get(i);
		if (type->isPrimitive()) {
			if (type == Byte::TYPE) {
				types[index] = &ffi_type_sint8;
			} else if (type == Short::TYPE) {
				types[index] = &ffi_type_sint16;
			} else if (type == Integer::TYPE) {
				types[index] = &ffi_type_sint32;
			} else if (type == Long::TYPE) {
				types[index] = &ffi_type_sint64;
			} else if (type == Float::TYPE) {
				types[index] = &ffi_type_float;
			} else if (type == Double::TYPE) {
				types[index] = &ffi_type_double;
			} else if (type == Boolean::TYPE) {
				types[index] = &ffi_type_sint8;
			} else if (type == Character::TYPE) {
				types[index] = &ffi_type_uint16;
			}
		} else {
			types[index] = &ffi_type_pointer;
		}
	}
	return typeBytes;
}

class FFIClosure {
public:
	ffi_cif cif;
	ffi_type retType;
	ffi_closure* closure = nullptr;
	void* functionEntry = nullptr;
	::java::lang::reflect::Method* method = nullptr;
	int32_t toObject0Offset = 0;
};

void memberFunction0(ffi_cif* cif, void* ret, void** args, void* userdata) {
	FFIClosure* ffiClosure = (FFIClosure*)userdata;
	Object* self = *(Object**)args[0];
	$Value retValue = ffiClosure->method->invokev(self, nullptr);
	*($Value*)ret = retValue;
}

void memberFunction16(ffi_cif* cif, void* ret, void** args, void* userdata) {
	FFIClosure* ffiClosure = (FFIClosure*)userdata;
	$Value argv[17]; // this + args
	ffi_type** argTypes = cif->arg_types;
	for (uint32_t i = 0; i < cif->nargs; i++) {
		if (argTypes[i] == &ffi_type_sint8) {
			argv[i] = *(int8_t*)args[i];
		} else if (argTypes[i] == &ffi_type_sint16) {
			argv[i] = *(int16_t*)args[i];
		} else if (argTypes[i] == &ffi_type_sint32) {
			argv[i] = *(int32_t*)args[i];
		} else if (argTypes[i] == &ffi_type_sint64) {
			argv[i] = *(int64_t*)args[i];
		} else if (argTypes[i] == &ffi_type_float) {
			argv[i] = *(float*)args[i];
		} else if (argTypes[i] == &ffi_type_double) {
			argv[i] = *(double*)args[i];
		} else if (argTypes[i] == &ffi_type_uint16) {
			argv[i] = *(char16_t*)args[i];
		} else if (argTypes[i] == &ffi_type_pointer) {
			argv[i] = *($Object**)args[i];
		}
	}
	$Value retValue = ffiClosure->method->invokev(argv[0].is<$Object>(), argv + 1);
	*($Value*)ret = retValue;
}

void memberFunction(ffi_cif* cif, void* ret, void** args, void* userdata) {
	FFIClosure* ffiClosure = (FFIClosure*)userdata;
	ffi_type** argTypes = cif->arg_types;
	$var($bytes, data, $new<$bytes>(cif->nargs * sizeof($Value)));
	$Value* argv = ($Value*)data->begin();
	for (uint32_t i = 0; i < cif->nargs; i++) {
		if (argTypes[i] == &ffi_type_sint8) {
			argv[i] = *(int8_t*)args[i];
		} else if (argTypes[i] == &ffi_type_sint16) {
			argv[i] = *(int16_t*)args[i];
		} else if (argTypes[i] == &ffi_type_sint32) {
			argv[i] = *(int32_t*)args[i];
		} else if (argTypes[i] == &ffi_type_sint64) {
			argv[i] = *(int64_t*)args[i];
		} else if (argTypes[i] == &ffi_type_float) {
			argv[i] = *(float*)args[i];
		} else if (argTypes[i] == &ffi_type_double) {
			argv[i] = *(double*)args[i];
		} else if (argTypes[i] == &ffi_type_uint16) {
			argv[i] = *(char16_t*)args[i];
		} else if (argTypes[i] == &ffi_type_pointer) {
			argv[i] = *($Object**)args[i];
		}
	}
	$Value retValue = ffiClosure->method->invokev(argv[0].is<$Object>(), argv + 1);
	*($Value*)ret = retValue;
}

// please make sure method is live forever
void* Platform::prepareClosure(int32_t toObject0Offset, ::java::lang::reflect::Method* method) {
	FFIClosure* ffiClosure = new FFIClosure;
	ffiClosure->method = method;
	ffiClosure->toObject0Offset = toObject0Offset;
	ffiClosure->closure = (ffi_closure*)ffi_closure_alloc(sizeof(ffi_closure), &ffiClosure->functionEntry);
	// TODO error handle
	if (ffiClosure->closure) {
		$ClassArray* parameterTypes = method->getSharedParameterTypes();
		int32_t parameterTypesLength = parameterTypes->length;
		int32_t argCount = parameterTypesLength;
		if (!method->isStatic()) {
			argCount++;
		}
		$var($bytes, typeBytes, prepareParameterTypes(method->isStatic(), parameterTypes));
		$bytes* typeBytesStatic = $allocStatic<$bytes>(typeBytes->length);
		typeBytesStatic->setArray(0, typeBytes);
		// ObjectManager::scanMarkConstGlobal(typeBytes);
		ffi_type** types = (ffi_type**)typeBytesStatic->begin();
		ffiClosure->retType = prepareReturnType(method->getReturnType());
		// TODO error handle
		if (ffi_prep_cif(&ffiClosure->cif, FFI_DEFAULT_ABI, argCount,
			&ffiClosure->retType, types) == FFI_OK) {
			void (*fun)(ffi_cif*, void*, void**, void*);
			if (parameterTypesLength == 0) {
				fun = memberFunction0;
			} else if (parameterTypesLength < 16) {
				fun = memberFunction16;
			} else {
				fun = memberFunction;
			}
			// TODO error handle
			if (ffi_prep_closure_loc(ffiClosure->closure, &ffiClosure->cif, fun,
				ffiClosure, ffiClosure->functionEntry) == FFI_OK) {
			}
		}
	}

	//	ffi_closure_free(closure);

	return ffiClosure->functionEntry;
}

Object* Platform::resolveRef(Object$* ref) {
	if (ref == nullptr) {
		return nullptr;
	}
	Object* obj = (Object*)ref;
	Object0* obj0 = $toObject0(ref);
	ObjectHead* oh = toOh(obj0);
	if (oh->isGlobalRef()) {
		::java::lang::ref::Reference* reference = (::java::lang::ref::Reference*)obj0;
		return reference->get();
	}
	return obj;
}

bool Platform::isGlobalRef(Object$* ref) {
	if (ref == nullptr) {
		return false;
	}
	Object* obj = (Object*)ref;
	Object0* obj0 = $toObject0(ref);
	ObjectHead* oh = toOh(obj0);
	return oh->isGlobalRef();
}

	} // namespace lang
} // namespace java