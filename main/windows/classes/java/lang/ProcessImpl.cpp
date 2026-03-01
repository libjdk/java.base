#include <java/lang/ProcessImpl.h>

#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalThreadStateException.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder$Redirect.h>
#include <java/lang/ProcessBuilder$RedirectPipeImpl.h>
#include <java/lang/ProcessEnvironment.h>
#include <java/lang/ProcessHandle.h>
#include <java/lang/ProcessHandleImpl.h>
#include <java/lang/ProcessImpl$1.h>
#include <java/lang/ProcessImpl$2.h>
#include <java/lang/ProcessImpl$LazyPattern.h>
#include <java/lang/Runnable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/function/BiFunction.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef BACKSLASH
#undef DOUBLEQUOTE
#undef ESCAPE_VERIFICATION
#undef INHERIT
#undef MAX_VALUE
#undef NANOSECONDS
#undef PATTERN
#undef PIPE
#undef ROOT
#undef STILL_ACTIVE
#undef SUPPORTS_NORMAL_TERMINATION
#undef VERIFICATION_CMD_BAT
#undef VERIFICATION_LEGACY
#undef VERIFICATION_WIN32
#undef VERIFICATION_WIN32_SAFE

using $ProcessBuilder$RedirectArray = $Array<::java::lang::ProcessBuilder$Redirect>;
using $charArray2 = $Array<char16_t, 2>;
using $File = ::java::io::File;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalThreadStateException = ::java::lang::IllegalThreadStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process = ::java::lang::Process;
using $ProcessBuilder$Redirect = ::java::lang::ProcessBuilder$Redirect;
using $ProcessBuilder$RedirectPipeImpl = ::java::lang::ProcessBuilder$RedirectPipeImpl;
using $ProcessEnvironment = ::java::lang::ProcessEnvironment;
using $ProcessHandle = ::java::lang::ProcessHandle;
using $ProcessHandleImpl = ::java::lang::ProcessHandleImpl;
using $ProcessImpl$1 = ::java::lang::ProcessImpl$1;
using $ProcessImpl$2 = ::java::lang::ProcessImpl$2;
using $ProcessImpl$LazyPattern = ::java::lang::ProcessImpl$LazyPattern;
using $Runnable = ::java::lang::Runnable;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Cleaner = ::java::lang::ref::Cleaner;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $BiFunction = ::java::util::function::BiFunction;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace lang {

class ProcessImpl$$Lambda$lambda$new$0 : public $Runnable {
	$class(ProcessImpl$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Runnable)
public:
	void init$(int64_t local_handle) {
		this->local_handle = local_handle;
	}
	virtual void run() override {
		ProcessImpl::lambda$new$0(local_handle);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$$Lambda$lambda$new$0>());
	}
	int64_t local_handle = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"local_handle", "J", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$new$0, local_handle)},
	{}
};
$MethodInfo ProcessImpl$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(J)V", nullptr, $PUBLIC, $method(ProcessImpl$$Lambda$lambda$new$0, init$, void, int64_t)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$$Lambda$lambda$new$0, run, void)},
	{}
};
$ClassInfo ProcessImpl$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$$Lambda$lambda$new$0::class$ = nullptr;

class ProcessImpl$$Lambda$lambda$onExit$1$1 : public $BiFunction {
	$class(ProcessImpl$$Lambda$lambda$onExit$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(ProcessImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* exitStatus, Object$* unusedThrowable) override {
		 return $of($nc(inst$)->lambda$onExit$1($cast($Integer, exitStatus), $cast($Throwable, unusedThrowable)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$$Lambda$lambda$onExit$1$1>());
	}
	ProcessImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$$Lambda$lambda$onExit$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$onExit$1$1, inst$)},
	{}
};
$MethodInfo ProcessImpl$$Lambda$lambda$onExit$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ProcessImpl;)V", nullptr, $PUBLIC, $method(ProcessImpl$$Lambda$lambda$onExit$1$1, init$, void, ProcessImpl*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$$Lambda$lambda$onExit$1$1, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo ProcessImpl$$Lambda$lambda$onExit$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$$Lambda$lambda$onExit$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$$Lambda$lambda$onExit$1$1::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$$Lambda$lambda$onExit$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$$Lambda$lambda$onExit$1$1::class$ = nullptr;

$FieldInfo _ProcessImpl_FieldInfo_[] = {
	{"fdAccess", "Ljdk/internal/access/JavaIOFileDescriptorAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, fdAccess)},
	{"SUPPORTS_NORMAL_TERMINATION", "Z", nullptr, $STATIC | $FINAL, $constField(ProcessImpl, SUPPORTS_NORMAL_TERMINATION)},
	{"VERIFICATION_CMD_BAT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessImpl, VERIFICATION_CMD_BAT)},
	{"VERIFICATION_WIN32", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessImpl, VERIFICATION_WIN32)},
	{"VERIFICATION_WIN32_SAFE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessImpl, VERIFICATION_WIN32_SAFE)},
	{"VERIFICATION_LEGACY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessImpl, VERIFICATION_LEGACY)},
	{"ESCAPE_VERIFICATION", "[[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, ESCAPE_VERIFICATION)},
	{"DOUBLEQUOTE", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessImpl, DOUBLEQUOTE)},
	{"BACKSLASH", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProcessImpl, BACKSLASH)},
	{"handle", "J", nullptr, $PRIVATE | $FINAL, $field(ProcessImpl, handle)},
	{"processHandle", "Ljava/lang/ProcessHandle;", nullptr, $PRIVATE | $FINAL, $field(ProcessImpl, processHandle)},
	{"stdin_stream", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(ProcessImpl, stdin_stream)},
	{"stdout_stream", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(ProcessImpl, stdout_stream)},
	{"stderr_stream", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(ProcessImpl, stderr_stream)},
	{"STILL_ACTIVE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, STILL_ACTIVE)},
	{}
};

$MethodInfo _ProcessImpl_MethodInfo_[] = {
	{"<init>", "([Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[JZZ)V", nullptr, $PRIVATE, $method(ProcessImpl, init$, void, $StringArray*, $String*, $String*, $longs*, bool, bool), "java.io.IOException"},
	{"closeHandle", "(J)Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, closeHandle, bool, int64_t)},
	{"countLeadingBackslash", "(ILjava/lang/CharSequence;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, countLeadingBackslash, int32_t, int32_t, $CharSequence*, int32_t)},
	{"create", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[JZ)J", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED | $NATIVE, $staticMethod(ProcessImpl, create, int64_t, $String*, $String*, $String*, $longs*, bool), "java.io.IOException"},
	{"createCommandLine", "(ILjava/lang/String;[Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, createCommandLine, $String*, int32_t, $String*, $StringArray*)},
	{"destroy", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, destroy, void)},
	{"destroyForcibly", "()Ljava/lang/Process;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, destroyForcibly, $Process*)},
	{"exitValue", "()I", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, exitValue, int32_t)},
	{"getErrorStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, getErrorStream, $InputStream*)},
	{"getExecutablePath", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, getExecutablePath, $String*, $String*), "java.io.IOException"},
	{"getExitCodeProcess", "(J)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, getExitCodeProcess, int32_t, int64_t)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, getInputStream, $InputStream*)},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, getOutputStream, $OutputStream*)},
	{"getProcessId0", "(J)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, getProcessId0, int32_t, int64_t)},
	{"getStillActive", "()I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, getStillActive, int32_t)},
	{"getTokensFromCommand", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, getTokensFromCommand, $StringArray*, $String*)},
	{"isAlive", "()Z", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, isAlive, bool)},
	{"isExe", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(ProcessImpl, isExe, bool, $String*)},
	{"isProcessAlive", "(J)Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, isProcessAlive, bool, int64_t)},
	{"isShellFile", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(ProcessImpl, isShellFile, bool, $String*)},
	{"lambda$new$0", "(J)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ProcessImpl, lambda$new$0, void, int64_t)},
	{"lambda$onExit$1", "(Ljava/lang/Integer;Ljava/lang/Throwable;)Ljava/lang/Process;", nullptr, $PRIVATE | $SYNTHETIC, $method(ProcessImpl, lambda$onExit$1, $Process*, $Integer*, $Throwable*)},
	{"needsEscaping", "(ILjava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, needsEscaping, bool, int32_t, $String*)},
	{"newFileOutputStream", "(Ljava/io/File;Z)Ljava/io/FileOutputStream;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, newFileOutputStream, $FileOutputStream*, $File*, bool), "java.io.IOException"},
	{"onExit", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Process;>;", $PUBLIC, $virtualMethod(ProcessImpl, onExit, $CompletableFuture*)},
	{"openForAtomicAppend", "(Ljava/lang/String;)J", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, openForAtomicAppend, int64_t, $String*), "java.io.IOException"},
	{"pid", "()J", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, pid, int64_t)},
	{"quoteString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ProcessImpl, quoteString, $String*, $String*)},
	{"start", "([Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;[Ljava/lang/ProcessBuilder$Redirect;Z)Ljava/lang/Process;", "([Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;Ljava/lang/String;[Ljava/lang/ProcessBuilder$Redirect;Z)Ljava/lang/Process;", $STATIC, $staticMethod(ProcessImpl, start, $Process*, $StringArray*, $Map*, $String*, $ProcessBuilder$RedirectArray*, bool), "java.io.IOException"},
	{"supportsNormalTermination", "()Z", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, supportsNormalTermination, bool)},
	{"terminateProcess", "(J)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, terminateProcess, void, int64_t)},
	{"toHandle", "()Ljava/lang/ProcessHandle;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, toHandle, $ProcessHandle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, toString, $String*)},
	{"unQuote", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, unQuote, $String*, $String*)},
	{"waitFor", "()I", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, waitFor, int32_t), "java.lang.InterruptedException"},
	{"waitFor", "(JLjava/util/concurrent/TimeUnit;)Z", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, waitFor, bool, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"waitForInterruptibly", "(J)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, waitForInterruptibly, void, int64_t)},
	{"waitForTimeoutInterruptibly", "(JJ)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, waitForTimeoutInterruptibly, void, int64_t, int64_t)},
	{}
};

#define _METHOD_INDEX_closeHandle 1
#define _METHOD_INDEX_create 3
#define _METHOD_INDEX_getExitCodeProcess 10
#define _METHOD_INDEX_getProcessId0 13
#define _METHOD_INDEX_getStillActive 14
#define _METHOD_INDEX_isProcessAlive 18
#define _METHOD_INDEX_openForAtomicAppend 25
#define _METHOD_INDEX_terminateProcess 30
#define _METHOD_INDEX_waitForInterruptibly 36
#define _METHOD_INDEX_waitForTimeoutInterruptibly 37

$InnerClassInfo _ProcessImpl_InnerClassesInfo_[] = {
	{"java.lang.ProcessImpl$LazyPattern", "java.lang.ProcessImpl", "LazyPattern", $PRIVATE | $STATIC},
	{"java.lang.ProcessImpl$2", nullptr, nullptr, 0},
	{"java.lang.ProcessImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProcessImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.ProcessImpl",
	"java.lang.Process",
	nullptr,
	_ProcessImpl_FieldInfo_,
	_ProcessImpl_MethodInfo_,
	nullptr,
	nullptr,
	_ProcessImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.ProcessImpl$LazyPattern,java.lang.ProcessImpl$2,java.lang.ProcessImpl$1"
};

$Object* allocate$ProcessImpl($Class* clazz) {
	return $of($alloc(ProcessImpl));
}

$JavaIOFileDescriptorAccess* ProcessImpl::fdAccess = nullptr;
$charArray2* ProcessImpl::ESCAPE_VERIFICATION = nullptr;
int32_t ProcessImpl::STILL_ACTIVE = 0;

$FileOutputStream* ProcessImpl::newFileOutputStream($File* f, bool append) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (append) {
		$var($String, path, $nc(f)->getPath());
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkWrite(path);
		}
		int64_t handle = openForAtomicAppend(path);
		$var($FileDescriptor, fd, $new($FileDescriptor));
		$nc(ProcessImpl::fdAccess)->setHandle(fd, handle);
		return $cast($FileOutputStream, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ProcessImpl$1, fd))));
	} else {
		return $new($FileOutputStream, f);
	}
}

$Process* ProcessImpl::start($StringArray* cmdarray, $Map* environment, $String* dir, $ProcessBuilder$RedirectArray* redirects, bool redirectErrorStream) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	$var($String, envblock, $ProcessEnvironment::toEnvironmentBlock(environment));
	$var($FileInputStream, f0, nullptr);
	$var($FileOutputStream, f1, nullptr);
	$var($FileOutputStream, f2, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($Process, var$2, nullptr);
		bool return$1 = false;
		try {
			bool forceNullOutputStream = false;
			$var($longs, stdHandles, nullptr);
			if (redirects == nullptr) {
				$assign(stdHandles, $new($longs, {
					(int64_t)-1,
					(int64_t)-1,
					(int64_t)-1
				}));
			} else {
				$assign(stdHandles, $new($longs, 3));
				$init($ProcessBuilder$Redirect);
				if ($nc(redirects)->get(0) == $ProcessBuilder$Redirect::PIPE) {
					stdHandles->set(0, -1);
				} else {
					if (redirects->get(0) == $ProcessBuilder$Redirect::INHERIT) {
						$init($FileDescriptor);
						stdHandles->set(0, $nc(ProcessImpl::fdAccess)->getHandle($FileDescriptor::in));
					} else if ($instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(0))) {
						stdHandles->set(0, $nc(ProcessImpl::fdAccess)->getHandle($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(0))))->getFd())));
					} else {
						$assign(f0, $new($FileInputStream, $($nc(redirects->get(0))->file())));
						stdHandles->set(0, $nc(ProcessImpl::fdAccess)->getHandle($(f0->getFD())));
					}
				}
				if ($nc(redirects)->get(1) == $ProcessBuilder$Redirect::PIPE) {
					stdHandles->set(1, -1);
				} else {
					if (redirects->get(1) == $ProcessBuilder$Redirect::INHERIT) {
						$init($FileDescriptor);
						stdHandles->set(1, $nc(ProcessImpl::fdAccess)->getHandle($FileDescriptor::out));
					} else if ($instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(1))) {
						stdHandles->set(1, $nc(ProcessImpl::fdAccess)->getHandle($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(1))))->getFd())));
						forceNullOutputStream = true;
					} else {
						$var($File, var$3, $nc(redirects->get(1))->file());
						$assign(f1, newFileOutputStream(var$3, $nc(redirects->get(1))->append()));
						stdHandles->set(1, $nc(ProcessImpl::fdAccess)->getHandle($($nc(f1)->getFD())));
					}
				}
				if ($nc(redirects)->get(2) == $ProcessBuilder$Redirect::PIPE) {
					stdHandles->set(2, -1);
				} else {
					if (redirects->get(2) == $ProcessBuilder$Redirect::INHERIT) {
						$init($FileDescriptor);
						stdHandles->set(2, $nc(ProcessImpl::fdAccess)->getHandle($FileDescriptor::err));
					} else if ($instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(2))) {
						stdHandles->set(2, $nc(ProcessImpl::fdAccess)->getHandle($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(2))))->getFd())));
					} else {
						$var($File, var$4, $nc(redirects->get(2))->file());
						$assign(f2, newFileOutputStream(var$4, $nc(redirects->get(2))->append()));
						stdHandles->set(2, $nc(ProcessImpl::fdAccess)->getHandle($($nc(f2)->getFD())));
					}
				}
			}
			$var($Process, p, $new(ProcessImpl, cmdarray, envblock, dir, stdHandles, forceNullOutputStream, redirectErrorStream));
			if (redirects != nullptr) {
				if ($nc(stdHandles)->get(0) >= 0 && $instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(0))) {
					$nc(ProcessImpl::fdAccess)->setHandle($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(0))))->getFd()), stdHandles->get(0));
				}
				if ($nc(stdHandles)->get(1) >= 0 && $instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(1))) {
					$nc(ProcessImpl::fdAccess)->setHandle($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(1))))->getFd()), stdHandles->get(1));
				}
				if ($nc(stdHandles)->get(2) >= 0 && $instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(2))) {
					$nc(ProcessImpl::fdAccess)->setHandle($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(2))))->getFd()), stdHandles->get(2));
				}
			}
			$assign(var$2, p);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} $finally: {
			{
				$var($Throwable, var$6, nullptr);
				try {
					if (f0 != nullptr) {
						f0->close();
					}
				} catch ($Throwable& var$7) {
					$assign(var$6, var$7);
				} /*finally*/ {
					{
						$var($Throwable, var$8, nullptr);
						try {
							if (f1 != nullptr) {
								f1->close();
							}
						} catch ($Throwable& var$9) {
							$assign(var$8, var$9);
						} /*finally*/ {
							if (f2 != nullptr) {
								f2->close();
							}
						}
						if (var$8 != nullptr) {
							$throw(var$8);
						}
					}
				}
				if (var$6 != nullptr) {
					$throw(var$6);
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$StringArray* ProcessImpl::getTokensFromCommand($String* command) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, matchList, $new($ArrayList, 8));
	$init($ProcessImpl$LazyPattern);
	$var($Matcher, regexMatcher, $nc($ProcessImpl$LazyPattern::PATTERN)->matcher(command));
	while ($nc(regexMatcher)->find()) {
		matchList->add($(regexMatcher->group()));
	}
	return $fcast($StringArray, matchList->toArray($$new($StringArray, matchList->size())));
}

$String* ProcessImpl::createCommandLine(int32_t verificationType, $String* executablePath, $StringArray* cmd) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, cmdbuf, $new($StringBuilder, 80));
	cmdbuf->append(executablePath);
	for (int32_t i = 1; i < $nc(cmd)->length; ++i) {
		cmdbuf->append(u' ');
		$var($String, s, cmd->get(i));
		if (needsEscaping(verificationType, s)) {
			cmdbuf->append(u'\"');
			if (verificationType == ProcessImpl::VERIFICATION_WIN32_SAFE) {
				int32_t length = $nc(s)->length();
				for (int32_t j = 0; j < length; ++j) {
					char16_t c = s->charAt(j);
					if (c == ProcessImpl::DOUBLEQUOTE) {
						int32_t count = countLeadingBackslash(verificationType, s, j);
						while (count-- > 0) {
							cmdbuf->append(ProcessImpl::BACKSLASH);
						}
						cmdbuf->append(ProcessImpl::BACKSLASH);
					}
					cmdbuf->append(c);
				}
			} else {
				cmdbuf->append(s);
			}
			int32_t count = countLeadingBackslash(verificationType, s, $nc(s)->length());
			while (count-- > 0) {
				cmdbuf->append(ProcessImpl::BACKSLASH);
			}
			cmdbuf->append(u'\"');
		} else {
			cmdbuf->append(s);
		}
	}
	return cmdbuf->toString();
}

$String* ProcessImpl::unQuote($String* str) {
	$init(ProcessImpl);
	bool var$1 = !$nc(str)->startsWith("\""_s);
	bool var$0 = var$1 || !$nc(str)->endsWith("\""_s);
	if (var$0 || $nc(str)->length() < 2) {
		return str;
	}
	if ($nc(str)->endsWith("\\\""_s)) {
		return str;
	}
	return $nc(str)->substring(1, str->length() - 1);
}

bool ProcessImpl::needsEscaping(int32_t verificationType, $String* arg) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	if ($nc(arg)->isEmpty()) {
		return true;
	}
	$var($String, unquotedArg, unQuote(arg));
	bool argIsQuoted = !$nc(arg)->equals(unquotedArg);
	bool embeddedQuote = $nc(unquotedArg)->indexOf((int32_t)ProcessImpl::DOUBLEQUOTE) >= 0;
	switch (verificationType) {
	case ProcessImpl::VERIFICATION_CMD_BAT:
		{
			if (embeddedQuote) {
				$throwNew($IllegalArgumentException, "Argument has embedded quote, use the explicit CMD.EXE call."_s);
			}
			break;
		}
	case ProcessImpl::VERIFICATION_WIN32_SAFE:
		{
			if (argIsQuoted && embeddedQuote) {
				$throwNew($IllegalArgumentException, $$str({"Malformed argument has embedded quote: "_s, unquotedArg}));
			}
			break;
		}
	default:
		{
			break;
		}
	}
	if (!argIsQuoted) {
		$var($chars, testEscape, $nc(ProcessImpl::ESCAPE_VERIFICATION)->get(verificationType));
		for (int32_t i = 0; i < $nc(testEscape)->length; ++i) {
			if (arg->indexOf((int32_t)testEscape->get(i)) >= 0) {
				return true;
			}
		}
	}
	return false;
}

$String* ProcessImpl::getExecutablePath($String* path) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	$var($String, name, unQuote(path));
	if ($nc(name)->indexOf((int32_t)ProcessImpl::DOUBLEQUOTE) >= 0) {
		$throwNew($IllegalArgumentException, $$str({"Executable name has embedded quote, split the arguments: "_s, name}));
	}
	$var($File, fileToRun, $new($File, name));
	return fileToRun->getPath();
}

bool ProcessImpl::isExe($String* executablePath) {
	$useLocalCurrentObjectStackCache();
	$var($File, file, $new($File, executablePath));
	$init($Locale);
	$var($String, upName, $nc($(file->getName()))->toUpperCase($Locale::ROOT));
	bool var$0 = upName->endsWith(".EXE"_s);
	return (var$0 || upName->indexOf((int32_t)u'.') < 0);
}

bool ProcessImpl::isShellFile($String* executablePath) {
	$var($String, upPath, $nc(executablePath)->toUpperCase());
	bool var$0 = upPath->endsWith(".CMD"_s);
	return (var$0 || upPath->endsWith(".BAT"_s));
}

$String* ProcessImpl::quoteString($String* arg) {
	$var($StringBuilder, argbuf, $new($StringBuilder, $nc(arg)->length() + 2));
	return argbuf->append(u'\"')->append(arg)->append(u'\"')->toString();
}

int32_t ProcessImpl::countLeadingBackslash(int32_t verificationType, $CharSequence* input, int32_t start) {
	$init(ProcessImpl);
	if (verificationType == ProcessImpl::VERIFICATION_CMD_BAT) {
		return 0;
	}
	int32_t j = 0;
	for (j = start - 1; j >= 0 && $nc(input)->charAt(j) == ProcessImpl::BACKSLASH; --j) {
	}
	return (start - 1) - j;
}

void ProcessImpl::init$($StringArray* cmd$renamed, $String* envblock, $String* path, $longs* stdHandles, bool forceNullOutputStream, bool redirectErrorStream) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, cmd, cmd$renamed);
	$beforeCallerSensitive();
	$Process::init$();
	$var($String, cmdstr, nullptr);
	$var($SecurityManager, security, $System::getSecurityManager());
	$var($String, value, $GetPropertyAction::privilegedGetProperty("jdk.lang.Process.allowAmbiguousCommands"_s, (security == nullptr ? "true"_s : "false"_s)));
	bool allowAmbiguousCommands = !"false"_s->equalsIgnoreCase(value);
	if (allowAmbiguousCommands && security == nullptr) {
		$var($String, executablePath, $$new($File, $nc(cmd)->get(0))->getPath());
		if (needsEscaping(ProcessImpl::VERIFICATION_LEGACY, executablePath)) {
			$assign(executablePath, quoteString(executablePath));
		}
		$assign(cmdstr, createCommandLine(ProcessImpl::VERIFICATION_LEGACY, executablePath, cmd));
	} else {
		$var($String, executablePath, nullptr);
		try {
			$assign(executablePath, getExecutablePath($nc(cmd)->get(0)));
		} catch ($IllegalArgumentException& e) {
			$var($StringBuilder, join, $new($StringBuilder));
			{
				$var($StringArray, arr$, cmd);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, s, arr$->get(i$));
					join->append(s)->append(u' ');
				}
			}
			$assign(cmd, getTokensFromCommand($(join->toString())));
			$assign(executablePath, getExecutablePath($nc(cmd)->get(0)));
			if (security != nullptr) {
				security->checkExec(executablePath);
			}
		}
		bool isShell = allowAmbiguousCommands ? isShellFile(executablePath) : !isExe(executablePath);
		$assign(cmdstr, createCommandLine(isShell ? ProcessImpl::VERIFICATION_CMD_BAT : (allowAmbiguousCommands ? ProcessImpl::VERIFICATION_WIN32 : ProcessImpl::VERIFICATION_WIN32_SAFE), $(quoteString(executablePath)), cmd));
	}
	this->handle = create(cmdstr, envblock, path, stdHandles, redirectErrorStream);
	int64_t local_handle = this->handle;
	$nc($($CleanerFactory::cleaner()))->register$(this, static_cast<$Runnable*>($$new(ProcessImpl$$Lambda$lambda$new$0, local_handle)));
	$set(this, processHandle, $ProcessHandleImpl::getInternal(getProcessId0(this->handle)));
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ProcessImpl$2, this, stdHandles, forceNullOutputStream)));
}

$OutputStream* ProcessImpl::getOutputStream() {
	return this->stdin_stream;
}

$InputStream* ProcessImpl::getInputStream() {
	return this->stdout_stream;
}

$InputStream* ProcessImpl::getErrorStream() {
	return this->stderr_stream;
}

int32_t ProcessImpl::getStillActive() {
	$init(ProcessImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(ProcessImpl, getStillActive, int32_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

int32_t ProcessImpl::exitValue() {
	int32_t exitCode = getExitCodeProcess(this->handle);
	if (exitCode == ProcessImpl::STILL_ACTIVE) {
		$throwNew($IllegalThreadStateException, "process has not exited"_s);
	}
	return exitCode;
}

int32_t ProcessImpl::getExitCodeProcess(int64_t handle) {
	$init(ProcessImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(ProcessImpl, getExitCodeProcess, int32_t, int64_t handle);
	$ret = $invokeNativeStatic(handle);
	$finishNativeStatic();
	return $ret;
}

int32_t ProcessImpl::waitFor() {
	waitForInterruptibly(this->handle);
	if ($Thread::interrupted()) {
		$throwNew($InterruptedException);
	}
	return exitValue();
}

void ProcessImpl::waitForInterruptibly(int64_t handle) {
	$init(ProcessImpl);
	$prepareNativeStatic(ProcessImpl, waitForInterruptibly, void, int64_t handle);
	$invokeNativeStatic(handle);
	$finishNativeStatic();
}

bool ProcessImpl::waitFor(int64_t timeout, $TimeUnit* unit) {
	int64_t remainingNanos = $nc(unit)->toNanos(timeout);
	if (getExitCodeProcess(this->handle) != ProcessImpl::STILL_ACTIVE) {
		return true;
	}
	if (timeout <= 0) {
		return false;
	}
	int64_t deadline = $System::nanoTime() + remainingNanos;
	do {
		int64_t msTimeout = $TimeUnit::NANOSECONDS->toMillis(remainingNanos + (int64_t)999999);
		if (msTimeout < 0) {
			msTimeout = $Integer::MAX_VALUE;
		}
		waitForTimeoutInterruptibly(this->handle, msTimeout);
		if ($Thread::interrupted()) {
			$throwNew($InterruptedException);
		}
		if (getExitCodeProcess(this->handle) != ProcessImpl::STILL_ACTIVE) {
			return true;
		}
		remainingNanos = deadline - $System::nanoTime();
	} while (remainingNanos > 0);
	return (getExitCodeProcess(this->handle) != ProcessImpl::STILL_ACTIVE);
}

void ProcessImpl::waitForTimeoutInterruptibly(int64_t handle, int64_t timeoutMillis) {
	$init(ProcessImpl);
	$prepareNativeStatic(ProcessImpl, waitForTimeoutInterruptibly, void, int64_t handle, int64_t timeoutMillis);
	$invokeNativeStatic(handle, timeoutMillis);
	$finishNativeStatic();
}

void ProcessImpl::destroy() {
	terminateProcess(this->handle);
}

$CompletableFuture* ProcessImpl::onExit() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($ProcessHandleImpl::completion(pid(), false)))->handleAsync(static_cast<$BiFunction*>($$new(ProcessImpl$$Lambda$lambda$onExit$1$1, this))));
}

$ProcessHandle* ProcessImpl::toHandle() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "manageProcess"_s));
	}
	return this->processHandle;
}

bool ProcessImpl::supportsNormalTermination() {
	return ProcessImpl::SUPPORTS_NORMAL_TERMINATION;
}

$Process* ProcessImpl::destroyForcibly() {
	destroy();
	return this;
}

void ProcessImpl::terminateProcess(int64_t handle) {
	$init(ProcessImpl);
	$prepareNativeStatic(ProcessImpl, terminateProcess, void, int64_t handle);
	$invokeNativeStatic(handle);
	$finishNativeStatic();
}

int64_t ProcessImpl::pid() {
	return $nc(this->processHandle)->pid();
}

int32_t ProcessImpl::getProcessId0(int64_t handle) {
	$init(ProcessImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(ProcessImpl, getProcessId0, int32_t, int64_t handle);
	$ret = $invokeNativeStatic(handle);
	$finishNativeStatic();
	return $ret;
}

bool ProcessImpl::isAlive() {
	return isProcessAlive(this->handle);
}

bool ProcessImpl::isProcessAlive(int64_t handle) {
	$init(ProcessImpl);
	bool $ret = false;
	$prepareNativeStatic(ProcessImpl, isProcessAlive, bool, int64_t handle);
	$ret = $invokeNativeStatic(handle);
	$finishNativeStatic();
	return $ret;
}

$String* ProcessImpl::toString() {
	$useLocalCurrentObjectStackCache();
	int32_t exitCode = getExitCodeProcess(this->handle);
	return $$new($StringBuilder, "Process[pid="_s)->append(pid())->append(", exitValue="_s)->append(exitCode == ProcessImpl::STILL_ACTIVE ? $of("\"not exited\""_s) : $($of($Integer::valueOf(exitCode))))->append("]"_s)->toString();
}

int64_t ProcessImpl::create($String* cmdstr, $String* envblock, $String* dir, $longs* stdHandles, bool redirectErrorStream) {
	$init(ProcessImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(ProcessImpl, create, int64_t, $String* cmdstr, $String* envblock, $String* dir, $longs* stdHandles, bool redirectErrorStream);
	$ret = $invokeNativeStatic(cmdstr, envblock, dir, stdHandles, redirectErrorStream);
	$finishNativeStatic();
	return $ret;
}

int64_t ProcessImpl::openForAtomicAppend($String* path) {
	$init(ProcessImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(ProcessImpl, openForAtomicAppend, int64_t, $String* path);
	$ret = $invokeNativeStatic(path);
	$finishNativeStatic();
	return $ret;
}

bool ProcessImpl::closeHandle(int64_t handle) {
	$init(ProcessImpl);
	bool $ret = false;
	$prepareNativeStatic(ProcessImpl, closeHandle, bool, int64_t handle);
	$ret = $invokeNativeStatic(handle);
	$finishNativeStatic();
	return $ret;
}

$Process* ProcessImpl::lambda$onExit$1($Integer* exitStatus, $Throwable* unusedThrowable) {
	return this;
}

void ProcessImpl::lambda$new$0(int64_t local_handle) {
	$init(ProcessImpl);
	closeHandle(local_handle);
}

void clinit$ProcessImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ProcessImpl::fdAccess, $SharedSecrets::getJavaIOFileDescriptorAccess());
	$assignStatic(ProcessImpl::ESCAPE_VERIFICATION, $new($charArray2, {
		$$new($chars, {
			u' ',
			u'\t',
			u'\"',
			u'<',
			u'>',
			u'&',
			u'|',
			u'^'
		}),
		$$new($chars, {
			u' ',
			u'\t',
			u'\"',
			u'<',
			u'>'
		}),
		$$new($chars, {
			u' ',
			u'\t',
			u'\"',
			u'<',
			u'>'
		}),
		$$new($chars, {
			u' ',
			u'\t'
		})
	}));
	ProcessImpl::STILL_ACTIVE = ProcessImpl::getStillActive();
}

ProcessImpl::ProcessImpl() {
}

$Class* ProcessImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ProcessImpl$$Lambda$lambda$new$0::classInfo$.name)) {
			return ProcessImpl$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(ProcessImpl$$Lambda$lambda$onExit$1$1::classInfo$.name)) {
			return ProcessImpl$$Lambda$lambda$onExit$1$1::load$(name, initialize);
		}
	}
	$loadClass(ProcessImpl, name, initialize, &_ProcessImpl_ClassInfo_, clinit$ProcessImpl, allocate$ProcessImpl);
	return class$;
}

$Class* ProcessImpl::class$ = nullptr;

	} // lang
} // java