#include <java/lang/ProcessImpl.h>

#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalThreadStateException.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder$NullInputStream.h>
#include <java/lang/ProcessBuilder$NullOutputStream.h>
#include <java/lang/ProcessBuilder$Redirect.h>
#include <java/lang/ProcessBuilder$RedirectPipeImpl.h>
#include <java/lang/ProcessEnvironment.h>
#include <java/lang/ProcessHandle.h>
#include <java/lang/ProcessHandleImpl.h>
#include <java/lang/ProcessImpl$1.h>
#include <java/lang/ProcessImpl$DeferredCloseProcessPipeInputStream.h>
#include <java/lang/ProcessImpl$LaunchMechanism.h>
#include <java/lang/ProcessImpl$Platform.h>
#include <java/lang/ProcessImpl$ProcessPipeInputStream.h>
#include <java/lang/ProcessImpl$ProcessPipeOutputStream.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Map.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/function/BiFunction.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/util/StaticProperty.h>
#include <jcpp.h>

#include "core/unix/_java_lang_ProcessImpl.h"

#undef INHERIT
#undef INSTANCE
#undef NANOSECONDS
#undef PIPE
#undef SUPPORTS_NORMAL_TERMINATION

using $ProcessBuilder$RedirectArray = $Array<::java::lang::ProcessBuilder$Redirect>;
using $byteArray2 = $Array<int8_t, 2>;
using $File = ::java::io::File;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalThreadStateException = ::java::lang::IllegalThreadStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process = ::java::lang::Process;
using $ProcessBuilder$NullInputStream = ::java::lang::ProcessBuilder$NullInputStream;
using $ProcessBuilder$NullOutputStream = ::java::lang::ProcessBuilder$NullOutputStream;
using $ProcessBuilder$Redirect = ::java::lang::ProcessBuilder$Redirect;
using $ProcessBuilder$RedirectPipeImpl = ::java::lang::ProcessBuilder$RedirectPipeImpl;
using $ProcessEnvironment = ::java::lang::ProcessEnvironment;
using $ProcessHandle = ::java::lang::ProcessHandle;
using $ProcessHandleImpl = ::java::lang::ProcessHandleImpl;
using $ProcessImpl$1 = ::java::lang::ProcessImpl$1;
using $ProcessImpl$DeferredCloseProcessPipeInputStream = ::java::lang::ProcessImpl$DeferredCloseProcessPipeInputStream;
using $ProcessImpl$LaunchMechanism = ::java::lang::ProcessImpl$LaunchMechanism;
using $ProcessImpl$Platform = ::java::lang::ProcessImpl$Platform;
using $ProcessImpl$ProcessPipeInputStream = ::java::lang::ProcessImpl$ProcessPipeInputStream;
using $ProcessImpl$ProcessPipeOutputStream = ::java::lang::ProcessImpl$ProcessPipeOutputStream;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Map = ::java::util::Map;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $BiFunction = ::java::util::function::BiFunction;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $StaticProperty = ::jdk::internal::util::StaticProperty;

namespace java {
	namespace lang {

class ProcessImpl$$Lambda$lambda$new$0 : public $PrivilegedExceptionAction {
	$class(ProcessImpl$$Lambda$lambda$new$0, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$(ProcessImpl* inst, $ints* fds, bool forceNullOutputStream) {
		$set(this, inst$, inst);
		$set(this, fds, fds);
		this->forceNullOutputStream = forceNullOutputStream;
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$new$0(fds, forceNullOutputStream));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$$Lambda$lambda$new$0>());
	}
	ProcessImpl* inst$ = nullptr;
	$ints* fds = nullptr;
	bool forceNullOutputStream = false;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$$Lambda$lambda$new$0::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$new$0, inst$)},
	{"fds", "[I", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$new$0, fds)},
	{"forceNullOutputStream", "Z", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$new$0, forceNullOutputStream)},
	{}
};
$MethodInfo ProcessImpl$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ProcessImpl;[IZ)V", nullptr, $PUBLIC, $method(ProcessImpl$$Lambda$lambda$new$0, init$, void, ProcessImpl*, $ints*, bool)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$$Lambda$lambda$new$0, run, $Object*)},
	{}
};
$ClassInfo ProcessImpl$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$$Lambda$lambda$new$0::class$ = nullptr;

class ProcessImpl$$Lambda$lambda$initStreams$1$1 : public $BiFunction {
	$class(ProcessImpl$$Lambda$lambda$initStreams$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(ProcessImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* exitcode, Object$* throwable) override {
		 return $nc(inst$)->lambda$initStreams$1($cast($Integer, exitcode), $cast($Throwable, throwable));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$$Lambda$lambda$initStreams$1$1>());
	}
	ProcessImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$$Lambda$lambda$initStreams$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$initStreams$1$1, inst$)},
	{}
};
$MethodInfo ProcessImpl$$Lambda$lambda$initStreams$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ProcessImpl;)V", nullptr, $PUBLIC, $method(ProcessImpl$$Lambda$lambda$initStreams$1$1, init$, void, ProcessImpl*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$$Lambda$lambda$initStreams$1$1, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo ProcessImpl$$Lambda$lambda$initStreams$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$$Lambda$lambda$initStreams$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$$Lambda$lambda$initStreams$1$1::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$$Lambda$lambda$initStreams$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$$Lambda$lambda$initStreams$1$1::class$ = nullptr;

class ProcessImpl$$Lambda$lambda$initStreams$2$2 : public $BiFunction {
	$class(ProcessImpl$$Lambda$lambda$initStreams$2$2, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(ProcessImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* exitcode, Object$* throwable) override {
		 return $nc(inst$)->lambda$initStreams$2($cast($Integer, exitcode), $cast($Throwable, throwable));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$$Lambda$lambda$initStreams$2$2>());
	}
	ProcessImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$$Lambda$lambda$initStreams$2$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$initStreams$2$2, inst$)},
	{}
};
$MethodInfo ProcessImpl$$Lambda$lambda$initStreams$2$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ProcessImpl;)V", nullptr, $PUBLIC, $method(ProcessImpl$$Lambda$lambda$initStreams$2$2, init$, void, ProcessImpl*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$$Lambda$lambda$initStreams$2$2, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo ProcessImpl$$Lambda$lambda$initStreams$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$$Lambda$lambda$initStreams$2$2",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$$Lambda$lambda$initStreams$2$2::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$$Lambda$lambda$initStreams$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$$Lambda$lambda$initStreams$2$2::class$ = nullptr;

class ProcessImpl$$Lambda$lambda$onExit$3$3 : public $BiFunction {
	$class(ProcessImpl$$Lambda$lambda$onExit$3$3, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(ProcessImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unusedExitStatus, Object$* unusedThrowable) override {
		 return $of($nc(inst$)->lambda$onExit$3($cast($Integer, unusedExitStatus), $cast($Throwable, unusedThrowable)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$$Lambda$lambda$onExit$3$3>());
	}
	ProcessImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$$Lambda$lambda$onExit$3$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ProcessImpl$$Lambda$lambda$onExit$3$3, inst$)},
	{}
};
$MethodInfo ProcessImpl$$Lambda$lambda$onExit$3$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ProcessImpl;)V", nullptr, $PUBLIC, $method(ProcessImpl$$Lambda$lambda$onExit$3$3, init$, void, ProcessImpl*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$$Lambda$lambda$onExit$3$3, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo ProcessImpl$$Lambda$lambda$onExit$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$$Lambda$lambda$onExit$3$3",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$$Lambda$lambda$onExit$3$3::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$$Lambda$lambda$onExit$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$$Lambda$lambda$onExit$3$3::class$ = nullptr;

$FieldInfo _ProcessImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ProcessImpl, $assertionsDisabled)},
	{"fdAccess", "Ljdk/internal/access/JavaIOFileDescriptorAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, fdAccess)},
	{"SUPPORTS_NORMAL_TERMINATION", "Z", nullptr, $STATIC | $FINAL, $constField(ProcessImpl, SUPPORTS_NORMAL_TERMINATION)},
	{"pid", "I", nullptr, $PRIVATE | $FINAL, $field(ProcessImpl, pid$)},
	{"processHandle", "Ljava/lang/ProcessHandleImpl;", nullptr, $PRIVATE | $FINAL, $field(ProcessImpl, processHandle)},
	{"exitcode", "I", nullptr, $PRIVATE, $field(ProcessImpl, exitcode)},
	{"hasExited", "Z", nullptr, $PRIVATE, $field(ProcessImpl, hasExited)},
	{"stdin", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(ProcessImpl, stdin)},
	{"stdout", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(ProcessImpl, stdout)},
	{"stderr", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(ProcessImpl, stderr)},
	{"platform", "Ljava/lang/ProcessImpl$Platform;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, platform)},
	{"launchMechanism", "Ljava/lang/ProcessImpl$LaunchMechanism;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, launchMechanism)},
	{"helperpath", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProcessImpl, helperpath)},
	{}
};

$MethodInfo _ProcessImpl_MethodInfo_[] = {
	{"<init>", "([B[BI[BI[B[IZZ)V", nullptr, $PRIVATE, $method(ProcessImpl, init$, void, $bytes*, $bytes*, int32_t, $bytes*, int32_t, $bytes*, $ints*, bool, bool), "java.io.IOException"},
	{"destroy", "(Z)V", nullptr, $PRIVATE, $method(ProcessImpl, destroy, void, bool)},
	{"destroy", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, destroy, void)},
	{"destroyForcibly", "()Ljava/lang/Process;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, destroyForcibly, $Process*)},
	{"exitValue", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ProcessImpl, exitValue, int32_t)},
	{"forkAndExec", "(I[B[B[BI[BI[B[IZ)I", nullptr, $PRIVATE | $NATIVE, $method(ProcessImpl, forkAndExec, int32_t, int32_t, $bytes*, $bytes*, $bytes*, int32_t, $bytes*, int32_t, $bytes*, $ints*, bool), "java.io.IOException"},
	{"getErrorStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, getErrorStream, $InputStream*)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, getInputStream, $InputStream*)},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, getOutputStream, $OutputStream*)},
	{"init", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ProcessImpl, init, void)},
	{"initStreams", "([IZ)V", nullptr, 0, $method(ProcessImpl, initStreams, void, $ints*, bool), "java.io.IOException"},
	{"isAlive", "()Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ProcessImpl, isAlive, bool)},
	{"lambda$initStreams$1", "(Ljava/lang/Integer;Ljava/lang/Throwable;)Ljava/lang/Object;", nullptr, $PRIVATE | $SYNTHETIC, $method(ProcessImpl, lambda$initStreams$1, $Object*, $Integer*, $Throwable*)},
	{"lambda$initStreams$2", "(Ljava/lang/Integer;Ljava/lang/Throwable;)Ljava/lang/Object;", nullptr, $PRIVATE | $SYNTHETIC, $method(ProcessImpl, lambda$initStreams$2, $Object*, $Integer*, $Throwable*)},
	{"lambda$new$0", "([IZ)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(ProcessImpl, lambda$new$0, $Void*, $ints*, bool), "java.lang.Exception"},
	{"lambda$onExit$3", "(Ljava/lang/Integer;Ljava/lang/Throwable;)Ljava/lang/Process;", nullptr, $PRIVATE | $SYNTHETIC, $method(ProcessImpl, lambda$onExit$3, $Process*, $Integer*, $Throwable*)},
	{"newFileDescriptor", "(I)Ljava/io/FileDescriptor;", nullptr, $STATIC, $staticMethod(ProcessImpl, newFileDescriptor, $FileDescriptor*, int32_t)},
	{"onExit", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Process;>;", $PUBLIC, $virtualMethod(ProcessImpl, onExit, $CompletableFuture*)},
	{"pid", "()J", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, pid, int64_t)},
	{"start", "([Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;[Ljava/lang/ProcessBuilder$Redirect;Z)Ljava/lang/Process;", "([Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;Ljava/lang/String;[Ljava/lang/ProcessBuilder$Redirect;Z)Ljava/lang/Process;", $STATIC, $staticMethod(ProcessImpl, start, $Process*, $StringArray*, $Map*, $String*, $ProcessBuilder$RedirectArray*, bool), "java.io.IOException"},
	{"supportsNormalTermination", "()Z", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, supportsNormalTermination, bool)},
	{"toCString", "(Ljava/lang/String;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(ProcessImpl, toCString, $bytes*, $String*)},
	{"toHandle", "()Ljava/lang/ProcessHandle;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, toHandle, $ProcessHandle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl, toString, $String*)},
	{"waitFor", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ProcessImpl, waitFor, int32_t), "java.lang.InterruptedException"},
	{"waitFor", "(JLjava/util/concurrent/TimeUnit;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ProcessImpl, waitFor, bool, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{}
};

#define _METHOD_INDEX_forkAndExec 5
#define _METHOD_INDEX_init 9

$InnerClassInfo _ProcessImpl_InnerClassesInfo_[] = {
	{"java.lang.ProcessImpl$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.lang.ProcessImpl$DeferredCloseProcessPipeInputStream", "java.lang.ProcessImpl", "DeferredCloseProcessPipeInputStream", $PRIVATE | $STATIC},
	{"java.lang.ProcessImpl$DeferredCloseInputStream", "java.lang.ProcessImpl", "DeferredCloseInputStream", $PRIVATE | $STATIC},
	{"java.lang.ProcessImpl$ProcessPipeOutputStream", "java.lang.ProcessImpl", "ProcessPipeOutputStream", $PRIVATE | $STATIC},
	{"java.lang.ProcessImpl$ProcessPipeInputStream", "java.lang.ProcessImpl", "ProcessPipeInputStream", $PRIVATE | $STATIC},
	{"java.lang.ProcessImpl$Platform", "java.lang.ProcessImpl", "Platform", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"java.lang.ProcessImpl$LaunchMechanism", "java.lang.ProcessImpl", "LaunchMechanism", $PRIVATE | $STATIC | $FINAL | $ENUM},
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
	"java.lang.ProcessImpl$1,java.lang.ProcessImpl$DeferredCloseProcessPipeInputStream,java.lang.ProcessImpl$DeferredCloseInputStream,java.lang.ProcessImpl$ProcessPipeOutputStream,java.lang.ProcessImpl$ProcessPipeInputStream,java.lang.ProcessImpl$Platform,java.lang.ProcessImpl$LaunchMechanism"
};

$Object* allocate$ProcessImpl($Class* clazz) {
	return $of($alloc(ProcessImpl));
}

bool ProcessImpl::$assertionsDisabled = false;
$JavaIOFileDescriptorAccess* ProcessImpl::fdAccess = nullptr;
$ProcessImpl$Platform* ProcessImpl::platform = nullptr;
$ProcessImpl$LaunchMechanism* ProcessImpl::launchMechanism = nullptr;
$bytes* ProcessImpl::helperpath = nullptr;

$bytes* ProcessImpl::toCString($String* s) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	if (s == nullptr) {
		return nullptr;
	}
	$var($bytes, bytes, $nc(s)->getBytes());
	$var($bytes, result, $new($bytes, bytes->length + 1));
	$System::arraycopy(bytes, 0, result, 0, bytes->length);
	result->set(result->length - 1, (int8_t)0);
	return result;
}

$Process* ProcessImpl::start($StringArray* cmdarray, $Map* environment, $String* dir, $ProcessBuilder$RedirectArray* redirects, bool redirectErrorStream) {
	$init(ProcessImpl);
	$useLocalCurrentObjectStackCache();
	if (!ProcessImpl::$assertionsDisabled && !(cmdarray != nullptr && cmdarray->length > 0)) {
		$throwNew($AssertionError);
	}
	$var($byteArray2, args, $new($byteArray2, $nc(cmdarray)->length - 1));
	int32_t size = args->length;
	for (int32_t i = 0; i < args->length; ++i) {
		args->set(i, $($nc(cmdarray->get(i + 1))->getBytes()));
		size += $nc(args->get(i))->length;
	}
	$var($bytes, argBlock, $new($bytes, size));
	int32_t i = 0;
	{
		$var($byteArray2, arr$, args);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($bytes, arg, arr$->get(i$));
			{
				$System::arraycopy(arg, 0, argBlock, i, $nc(arg)->length);
				i += $nc(arg)->length + 1;
			}
		}
	}
	$var($ints, envc, $new($ints, 1));
	$var($bytes, envBlock, $ProcessEnvironment::toEnvironmentBlock(environment, envc));
	$var($ints, std_fds, nullptr);
	$var($FileInputStream, f0, nullptr);
	$var($FileOutputStream, f1, nullptr);
	$var($FileOutputStream, f2, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($Process, var$2, nullptr);
		bool return$1 = false;
		try {
			bool forceNullOutputStream = false;
			if (redirects == nullptr) {
				$assign(std_fds, $new($ints, {
					-1,
					-1,
					-1
				}));
			} else {
				$assign(std_fds, $new($ints, 3));
				$init($ProcessBuilder$Redirect);
				if ($nc(redirects)->get(0) == $ProcessBuilder$Redirect::PIPE) {
					std_fds->set(0, -1);
				} else {
					if (redirects->get(0) == $ProcessBuilder$Redirect::INHERIT) {
						std_fds->set(0, 0);
					} else if ($instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(0))) {
						std_fds->set(0, $nc(ProcessImpl::fdAccess)->get($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(0))))->getFd())));
					} else {
						$assign(f0, $new($FileInputStream, $($nc(redirects->get(0))->file())));
						std_fds->set(0, $nc(ProcessImpl::fdAccess)->get($(f0->getFD())));
					}
				}
				if ($nc(redirects)->get(1) == $ProcessBuilder$Redirect::PIPE) {
					std_fds->set(1, -1);
				} else {
					if (redirects->get(1) == $ProcessBuilder$Redirect::INHERIT) {
						std_fds->set(1, 1);
					} else if ($instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(1))) {
						std_fds->set(1, $nc(ProcessImpl::fdAccess)->get($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(1))))->getFd())));
						forceNullOutputStream = true;
					} else {
						$var($File, var$3, $nc(redirects->get(1))->file());
						$assign(f1, $new($FileOutputStream, var$3, $nc(redirects->get(1))->append()));
						std_fds->set(1, $nc(ProcessImpl::fdAccess)->get($(f1->getFD())));
					}
				}
				if ($nc(redirects)->get(2) == $ProcessBuilder$Redirect::PIPE) {
					std_fds->set(2, -1);
				} else {
					if (redirects->get(2) == $ProcessBuilder$Redirect::INHERIT) {
						std_fds->set(2, 2);
					} else if ($instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(2))) {
						std_fds->set(2, $nc(ProcessImpl::fdAccess)->get($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(2))))->getFd())));
					} else {
						$var($File, var$4, $nc(redirects->get(2))->file());
						$assign(f2, $new($FileOutputStream, var$4, $nc(redirects->get(2))->append()));
						std_fds->set(2, $nc(ProcessImpl::fdAccess)->get($(f2->getFD())));
					}
				}
			}
			$var($bytes, var$5, toCString(cmdarray->get(0)));
			$var($bytes, var$6, argBlock);
			int32_t var$7 = args->length;
			$var($bytes, var$8, envBlock);
			int32_t var$9 = envc->get(0);
			$var($Process, p, $new(ProcessImpl, var$5, var$6, var$7, var$8, var$9, $(toCString(dir)), std_fds, forceNullOutputStream, redirectErrorStream));
			if (redirects != nullptr) {
				if ($nc(std_fds)->get(0) >= 0 && $instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(0))) {
					$nc(ProcessImpl::fdAccess)->set($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(0))))->getFd()), std_fds->get(0));
				}
				if ($nc(std_fds)->get(1) >= 0 && $instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(1))) {
					$nc(ProcessImpl::fdAccess)->set($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(1))))->getFd()), std_fds->get(1));
				}
				if ($nc(std_fds)->get(2) >= 0 && $instanceOf($ProcessBuilder$RedirectPipeImpl, redirects->get(2))) {
					$nc(ProcessImpl::fdAccess)->set($($nc(($cast($ProcessBuilder$RedirectPipeImpl, redirects->get(2))))->getFd()), std_fds->get(2));
				}
			}
			$assign(var$2, p);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$10) {
			$assign(var$0, var$10);
		} $finally: {
			{
				$var($Throwable, var$11, nullptr);
				try {
					if (f0 != nullptr) {
						f0->close();
					}
				} catch ($Throwable& var$12) {
					$assign(var$11, var$12);
				} /*finally*/ {
					{
						$var($Throwable, var$13, nullptr);
						try {
							if (f1 != nullptr) {
								f1->close();
							}
						} catch ($Throwable& var$14) {
							$assign(var$13, var$14);
						} /*finally*/ {
							if (f2 != nullptr) {
								f2->close();
							}
						}
						if (var$13 != nullptr) {
							$throw(var$13);
						}
					}
				}
				if (var$11 != nullptr) {
					$throw(var$11);
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

int32_t ProcessImpl::forkAndExec(int32_t mode, $bytes* helperpath, $bytes* prog, $bytes* argBlock, int32_t argc, $bytes* envBlock, int32_t envc, $bytes* dir, $ints* fds, bool redirectErrorStream) {
	return _Java_java_lang_ProcessImpl_forkAndExec(this, mode, helperpath, prog, argBlock, argc, envBlock, envc, dir, fds, redirectErrorStream);
}

void ProcessImpl::init$($bytes* prog, $bytes* argBlock, int32_t argc, $bytes* envBlock, int32_t envc, $bytes* dir, $ints* fds, bool forceNullOutputStream, bool redirectErrorStream) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Process::init$();
	this->pid$ = forkAndExec(ProcessImpl::launchMechanism->ordinal() + 1, ProcessImpl::helperpath, prog, argBlock, argc, envBlock, envc, dir, fds, redirectErrorStream);
	$set(this, processHandle, $ProcessHandleImpl::getInternal(this->pid$));
	try {
		$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new(ProcessImpl$$Lambda$lambda$new$0, this, fds, forceNullOutputStream)));
	} catch ($PrivilegedActionException& ex) {
		$throw($cast($IOException, $(ex->getCause())));
	}
}

$FileDescriptor* ProcessImpl::newFileDescriptor(int32_t fd) {
	$init(ProcessImpl);
	$var($FileDescriptor, fileDescriptor, $new($FileDescriptor));
	$nc(ProcessImpl::fdAccess)->set(fileDescriptor, fd);
	return fileDescriptor;
}

void ProcessImpl::initStreams($ints* fds, bool forceNullOutputStream) {
	$useLocalCurrentObjectStackCache();
	$init($ProcessImpl$1);
	switch ($nc($ProcessImpl$1::$SwitchMap$java$lang$ProcessImpl$Platform)->get((ProcessImpl::platform)->ordinal())) {
	case 1:
		{}
	case 2:
		{
			$init($ProcessBuilder$NullOutputStream);
			$set(this, stdin, ($nc(fds)->get(0) == -1) ? static_cast<$OutputStream*>($ProcessBuilder$NullOutputStream::INSTANCE) : static_cast<$OutputStream*>($new($ProcessImpl$ProcessPipeOutputStream, $nc(fds)->get(0))));
			$init($ProcessBuilder$NullInputStream);
			$set(this, stdout, ($nc(fds)->get(1) == -1 || forceNullOutputStream) ? static_cast<$InputStream*>($ProcessBuilder$NullInputStream::INSTANCE) : static_cast<$InputStream*>($new($ProcessImpl$ProcessPipeInputStream, $nc(fds)->get(1))));
			$init($ProcessBuilder$NullInputStream);
			$set(this, stderr, ($nc(fds)->get(2) == -1) ? static_cast<$InputStream*>($ProcessBuilder$NullInputStream::INSTANCE) : static_cast<$InputStream*>($new($ProcessImpl$ProcessPipeInputStream, $nc(fds)->get(2))));
			$nc($($ProcessHandleImpl::completion(this->pid$, true)))->handle(static_cast<$BiFunction*>($$new(ProcessImpl$$Lambda$lambda$initStreams$1$1, this)));
			break;
		}
	case 3:
		{
			$init($ProcessBuilder$NullOutputStream);
			$set(this, stdin, ($nc(fds)->get(0) == -1) ? static_cast<$OutputStream*>($ProcessBuilder$NullOutputStream::INSTANCE) : static_cast<$OutputStream*>($new($ProcessImpl$ProcessPipeOutputStream, $nc(fds)->get(0))));
			$init($ProcessBuilder$NullInputStream);
			$set(this, stdout, ($nc(fds)->get(1) == -1 || forceNullOutputStream) ? static_cast<$InputStream*>($ProcessBuilder$NullInputStream::INSTANCE) : static_cast<$InputStream*>($new($ProcessImpl$DeferredCloseProcessPipeInputStream, $nc(fds)->get(1))));
			$init($ProcessBuilder$NullInputStream);
			$set(this, stderr, ($nc(fds)->get(2) == -1) ? static_cast<$InputStream*>($ProcessBuilder$NullInputStream::INSTANCE) : static_cast<$InputStream*>($new($ProcessImpl$DeferredCloseProcessPipeInputStream, $nc(fds)->get(2))));
			$nc($($ProcessHandleImpl::completion(this->pid$, true)))->handle(static_cast<$BiFunction*>($$new(ProcessImpl$$Lambda$lambda$initStreams$2$2, this)));
			break;
		}
	default:
		{
			$throwNew($AssertionError, $of($$str({"Unsupported platform: "_s, ProcessImpl::platform})));
		}
	}
}

$OutputStream* ProcessImpl::getOutputStream() {
	return this->stdin;
}

$InputStream* ProcessImpl::getInputStream() {
	return this->stdout;
}

$InputStream* ProcessImpl::getErrorStream() {
	return this->stderr;
}

int32_t ProcessImpl::waitFor() {
	$synchronized(this) {
		while (!this->hasExited) {
			$of(this)->wait();
		}
		return this->exitcode;
	}
}

bool ProcessImpl::waitFor(int64_t timeout, $TimeUnit* unit) {
	$synchronized(this) {
		int64_t remainingNanos = $nc(unit)->toNanos(timeout);
		if (this->hasExited) {
			return true;
		}
		if (timeout <= 0) {
			return false;
		}
		int64_t deadline = $System::nanoTime() + remainingNanos;
		do {
			$TimeUnit::NANOSECONDS->timedWait(this, remainingNanos);
			if (this->hasExited) {
				return true;
			}
			remainingNanos = deadline - $System::nanoTime();
		} while (remainingNanos > 0);
		return this->hasExited;
	}
}

int32_t ProcessImpl::exitValue() {
	$synchronized(this) {
		if (!this->hasExited) {
			$throwNew($IllegalThreadStateException, "process hasn\'t exited"_s);
		}
		return this->exitcode;
	}
}

void ProcessImpl::destroy(bool force) {
	$init($ProcessImpl$1);
	switch ($nc($ProcessImpl$1::$SwitchMap$java$lang$ProcessImpl$Platform)->get((ProcessImpl::platform)->ordinal())) {
	case 1:
		{}
	case 2:
		{}
	case 3:
		{
			$synchronized(this) {
				if (!this->hasExited) {
					$nc(this->processHandle)->destroyProcess(force);
				}
			}
			try {
				$nc(this->stdin)->close();
			} catch ($IOException& ignored) {
			}
			try {
				$nc(this->stdout)->close();
			} catch ($IOException& ignored) {
			}
			try {
				$nc(this->stderr)->close();
			} catch ($IOException& ignored) {
			}
			break;
		}
	default:
		{
			$throwNew($AssertionError, $of($$str({"Unsupported platform: "_s, ProcessImpl::platform})));
		}
	}
}

$CompletableFuture* ProcessImpl::onExit() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($ProcessHandleImpl::completion(this->pid$, false)))->handleAsync(static_cast<$BiFunction*>($$new(ProcessImpl$$Lambda$lambda$onExit$3$3, this))));
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

void ProcessImpl::destroy() {
	destroy(false);
}

$Process* ProcessImpl::destroyForcibly() {
	destroy(true);
	return this;
}

int64_t ProcessImpl::pid() {
	return this->pid$;
}

bool ProcessImpl::isAlive() {
	$synchronized(this) {
		return !this->hasExited;
	}
}

$String* ProcessImpl::toString() {
	$useLocalCurrentObjectStackCache();
	return $$new($StringBuilder, "Process[pid="_s)->append(this->pid$)->append(", exitValue="_s)->append(this->hasExited ? $($of($Integer::valueOf(this->exitcode))) : $of("\"not exited\""_s))->append("]"_s)->toString();
}

void ProcessImpl::init() {
	_Java_java_lang_ProcessImpl_init();
}

$Process* ProcessImpl::lambda$onExit$3($Integer* unusedExitStatus, $Throwable* unusedThrowable) {
	bool interrupted = false;
	while (true) {
		try {
			waitFor();
			break;
		} catch ($InterruptedException& ie) {
			interrupted = true;
		}
	}
	if (interrupted) {
		$($Thread::currentThread())->interrupt();
	}
	return this;
}

$Object* ProcessImpl::lambda$initStreams$2($Integer* exitcode, $Throwable* throwable) {
	$synchronized(this) {
		this->exitcode = (exitcode == nullptr) ? -1 : $nc(exitcode)->intValue();
		this->hasExited = true;
		$of(this)->notifyAll();
	}
	if ($instanceOf($ProcessImpl$DeferredCloseProcessPipeInputStream, this->stdout)) {
		$nc(($cast($ProcessImpl$DeferredCloseProcessPipeInputStream, this->stdout)))->processExited();
	}
	if ($instanceOf($ProcessImpl$DeferredCloseProcessPipeInputStream, this->stderr)) {
		$nc(($cast($ProcessImpl$DeferredCloseProcessPipeInputStream, this->stderr)))->processExited();
	}
	if ($instanceOf($ProcessImpl$ProcessPipeOutputStream, this->stdin)) {
		$nc(($cast($ProcessImpl$ProcessPipeOutputStream, this->stdin)))->processExited();
	}
	return $of(nullptr);
}

$Object* ProcessImpl::lambda$initStreams$1($Integer* exitcode, $Throwable* throwable) {
	$synchronized(this) {
		this->exitcode = (exitcode == nullptr) ? -1 : $nc(exitcode)->intValue();
		this->hasExited = true;
		$of(this)->notifyAll();
	}
	if ($instanceOf($ProcessImpl$ProcessPipeInputStream, this->stdout)) {
		$nc(($cast($ProcessImpl$ProcessPipeInputStream, this->stdout)))->processExited();
	}
	if ($instanceOf($ProcessImpl$ProcessPipeInputStream, this->stderr)) {
		$nc(($cast($ProcessImpl$ProcessPipeInputStream, this->stderr)))->processExited();
	}
	if ($instanceOf($ProcessImpl$ProcessPipeOutputStream, this->stdin)) {
		$nc(($cast($ProcessImpl$ProcessPipeOutputStream, this->stdin)))->processExited();
	}
	return $of(nullptr);
}

$Void* ProcessImpl::lambda$new$0($ints* fds, bool forceNullOutputStream) {
	initStreams(fds, forceNullOutputStream);
	return nullptr;
}

void clinit$ProcessImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	ProcessImpl::$assertionsDisabled = !ProcessImpl::class$->desiredAssertionStatus();
	$assignStatic(ProcessImpl::fdAccess, $SharedSecrets::getJavaIOFileDescriptorAccess());
	$assignStatic(ProcessImpl::platform, $ProcessImpl$Platform::get());
	$assignStatic(ProcessImpl::launchMechanism, ProcessImpl::platform->launchMechanism());
	$assignStatic(ProcessImpl::helperpath, ProcessImpl::toCString($$str({$($StaticProperty::javaHome()), "/lib/jspawnhelper"_s})));
	{
		ProcessImpl::init();
	}
}

ProcessImpl::ProcessImpl() {
}

$Class* ProcessImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ProcessImpl$$Lambda$lambda$new$0::classInfo$.name)) {
			return ProcessImpl$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(ProcessImpl$$Lambda$lambda$initStreams$1$1::classInfo$.name)) {
			return ProcessImpl$$Lambda$lambda$initStreams$1$1::load$(name, initialize);
		}
		if (name->equals(ProcessImpl$$Lambda$lambda$initStreams$2$2::classInfo$.name)) {
			return ProcessImpl$$Lambda$lambda$initStreams$2$2::load$(name, initialize);
		}
		if (name->equals(ProcessImpl$$Lambda$lambda$onExit$3$3::classInfo$.name)) {
			return ProcessImpl$$Lambda$lambda$onExit$3$3::load$(name, initialize);
		}
	}
	$loadClass(ProcessImpl, name, initialize, &_ProcessImpl_ClassInfo_, clinit$ProcessImpl, allocate$ProcessImpl);
	return class$;
}

$Class* ProcessImpl::class$ = nullptr;

	} // lang
} // java