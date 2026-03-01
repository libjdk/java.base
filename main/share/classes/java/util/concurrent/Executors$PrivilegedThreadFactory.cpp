#include <java/util/concurrent/Executors$PrivilegedThreadFactory.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/Runnable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/util/concurrent/Executors$DefaultThreadFactory.h>
#include <java/util/concurrent/Executors$PrivilegedThreadFactory$1.h>
#include <java/util/concurrent/Executors.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef GET_CLASSLOADER_PERMISSION

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $Executors$DefaultThreadFactory = ::java::util::concurrent::Executors$DefaultThreadFactory;
using $Executors$PrivilegedThreadFactory$1 = ::java::util::concurrent::Executors$PrivilegedThreadFactory$1;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _Executors$PrivilegedThreadFactory_FieldInfo_[] = {
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL, $field(Executors$PrivilegedThreadFactory, acc)},
	{"ccl", "Ljava/lang/ClassLoader;", nullptr, $FINAL, $field(Executors$PrivilegedThreadFactory, ccl)},
	{}
};

$MethodInfo _Executors$PrivilegedThreadFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Executors$PrivilegedThreadFactory, init$, void)},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC, $virtualMethod(Executors$PrivilegedThreadFactory, newThread, $Thread*, $Runnable*)},
	{}
};

$InnerClassInfo _Executors$PrivilegedThreadFactory_InnerClassesInfo_[] = {
	{"java.util.concurrent.Executors$PrivilegedThreadFactory", "java.util.concurrent.Executors", "PrivilegedThreadFactory", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$DefaultThreadFactory", "java.util.concurrent.Executors", "DefaultThreadFactory", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$PrivilegedThreadFactory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Executors$PrivilegedThreadFactory_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.concurrent.Executors$PrivilegedThreadFactory",
	"java.util.concurrent.Executors$DefaultThreadFactory",
	nullptr,
	_Executors$PrivilegedThreadFactory_FieldInfo_,
	_Executors$PrivilegedThreadFactory_MethodInfo_,
	nullptr,
	nullptr,
	_Executors$PrivilegedThreadFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.Executors"
};

$Object* allocate$Executors$PrivilegedThreadFactory($Class* clazz) {
	return $of($alloc(Executors$PrivilegedThreadFactory));
}

void Executors$PrivilegedThreadFactory::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Executors$DefaultThreadFactory::init$();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
		sm->checkPermission($$new($RuntimePermission, "setContextClassLoader"_s));
	}
	$set(this, acc, $AccessController::getContext());
	$set(this, ccl, $($Thread::currentThread())->getContextClassLoader());
}

$Thread* Executors$PrivilegedThreadFactory::newThread($Runnable* r) {
	return $Executors$DefaultThreadFactory::newThread($$new($Executors$PrivilegedThreadFactory$1, this, r));
}

Executors$PrivilegedThreadFactory::Executors$PrivilegedThreadFactory() {
}

$Class* Executors$PrivilegedThreadFactory::load$($String* name, bool initialize) {
	$loadClass(Executors$PrivilegedThreadFactory, name, initialize, &_Executors$PrivilegedThreadFactory_ClassInfo_, allocate$Executors$PrivilegedThreadFactory);
	return class$;
}

$Class* Executors$PrivilegedThreadFactory::class$ = nullptr;

		} // concurrent
	} // util
} // java