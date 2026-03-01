#include <java/util/concurrent/Executors$PrivilegedCallableUsingCurrentClassLoader.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/Executors$PrivilegedCallableUsingCurrentClassLoader$1.h>
#include <java/util/concurrent/Executors.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef GET_CLASSLOADER_PERMISSION

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Callable = ::java::util::concurrent::Callable;
using $Executors$PrivilegedCallableUsingCurrentClassLoader$1 = ::java::util::concurrent::Executors$PrivilegedCallableUsingCurrentClassLoader$1;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _Executors$PrivilegedCallableUsingCurrentClassLoader_FieldInfo_[] = {
	{"task", "Ljava/util/concurrent/Callable;", "Ljava/util/concurrent/Callable<TT;>;", $FINAL, $field(Executors$PrivilegedCallableUsingCurrentClassLoader, task)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL, $field(Executors$PrivilegedCallableUsingCurrentClassLoader, acc)},
	{"ccl", "Ljava/lang/ClassLoader;", nullptr, $FINAL, $field(Executors$PrivilegedCallableUsingCurrentClassLoader, ccl)},
	{}
};

$MethodInfo _Executors$PrivilegedCallableUsingCurrentClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Callable;)V", "(Ljava/util/concurrent/Callable<TT;>;)V", 0, $method(Executors$PrivilegedCallableUsingCurrentClassLoader, init$, void, $Callable*)},
	{"call", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $virtualMethod(Executors$PrivilegedCallableUsingCurrentClassLoader, call, $Object*), "java.lang.Exception"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Executors$PrivilegedCallableUsingCurrentClassLoader, toString, $String*)},
	{}
};

$InnerClassInfo _Executors$PrivilegedCallableUsingCurrentClassLoader_InnerClassesInfo_[] = {
	{"java.util.concurrent.Executors$PrivilegedCallableUsingCurrentClassLoader", "java.util.concurrent.Executors", "PrivilegedCallableUsingCurrentClassLoader", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.Executors$PrivilegedCallableUsingCurrentClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Executors$PrivilegedCallableUsingCurrentClassLoader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.Executors$PrivilegedCallableUsingCurrentClassLoader",
	"java.lang.Object",
	"java.util.concurrent.Callable",
	_Executors$PrivilegedCallableUsingCurrentClassLoader_FieldInfo_,
	_Executors$PrivilegedCallableUsingCurrentClassLoader_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Callable<TT;>;",
	nullptr,
	_Executors$PrivilegedCallableUsingCurrentClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.Executors"
};

$Object* allocate$Executors$PrivilegedCallableUsingCurrentClassLoader($Class* clazz) {
	return $of($alloc(Executors$PrivilegedCallableUsingCurrentClassLoader));
}

void Executors$PrivilegedCallableUsingCurrentClassLoader::init$($Callable* task) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
		sm->checkPermission($$new($RuntimePermission, "setContextClassLoader"_s));
	}
	$set(this, task, task);
	$set(this, acc, $AccessController::getContext());
	$set(this, ccl, $($Thread::currentThread())->getContextClassLoader());
}

$Object* Executors$PrivilegedCallableUsingCurrentClassLoader::call() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $of($AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($Executors$PrivilegedCallableUsingCurrentClassLoader$1, this)), this->acc));
	} catch ($PrivilegedActionException& e) {
		$throw($(e->getException()));
	}
	$shouldNotReachHere();
}

$String* Executors$PrivilegedCallableUsingCurrentClassLoader::toString() {
	return $str({$($Callable::toString()), "[Wrapped task = "_s, this->task, "]"_s});
}

Executors$PrivilegedCallableUsingCurrentClassLoader::Executors$PrivilegedCallableUsingCurrentClassLoader() {
}

$Class* Executors$PrivilegedCallableUsingCurrentClassLoader::load$($String* name, bool initialize) {
	$loadClass(Executors$PrivilegedCallableUsingCurrentClassLoader, name, initialize, &_Executors$PrivilegedCallableUsingCurrentClassLoader_ClassInfo_, allocate$Executors$PrivilegedCallableUsingCurrentClassLoader);
	return class$;
}

$Class* Executors$PrivilegedCallableUsingCurrentClassLoader::class$ = nullptr;

		} // concurrent
	} // util
} // java