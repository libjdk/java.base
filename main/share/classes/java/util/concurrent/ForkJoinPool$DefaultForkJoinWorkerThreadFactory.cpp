#include <java/util/concurrent/ForkJoinPool$DefaultForkJoinWorkerThreadFactory.h>

#include <java/lang/RuntimePermission.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/ForkJoinPool$DefaultForkJoinWorkerThreadFactory$1.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/ForkJoinWorkerThread.h>
#include <jcpp.h>

#undef ACC

using $PermissionArray = $Array<::java::security::Permission>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$DefaultForkJoinWorkerThreadFactory$1 = ::java::util::concurrent::ForkJoinPool$DefaultForkJoinWorkerThreadFactory$1;
using $ForkJoinWorkerThread = ::java::util::concurrent::ForkJoinWorkerThread;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ForkJoinPool$DefaultForkJoinWorkerThreadFactory_FieldInfo_[] = {
	{"ACC", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool$DefaultForkJoinWorkerThreadFactory, ACC)},
	{}
};

$MethodInfo _ForkJoinPool$DefaultForkJoinWorkerThreadFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ForkJoinPool$DefaultForkJoinWorkerThreadFactory, init$, void)},
	{"newThread", "(Ljava/util/concurrent/ForkJoinPool;)Ljava/util/concurrent/ForkJoinWorkerThread;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ForkJoinPool$DefaultForkJoinWorkerThreadFactory, newThread, $ForkJoinWorkerThread*, $ForkJoinPool*)},
	{}
};

$InnerClassInfo _ForkJoinPool$DefaultForkJoinWorkerThreadFactory_InnerClassesInfo_[] = {
	{"java.util.concurrent.ForkJoinPool$DefaultForkJoinWorkerThreadFactory", "java.util.concurrent.ForkJoinPool", "DefaultForkJoinWorkerThreadFactory", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$ForkJoinWorkerThreadFactory", "java.util.concurrent.ForkJoinPool", "ForkJoinWorkerThreadFactory", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.ForkJoinPool$DefaultForkJoinWorkerThreadFactory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ForkJoinPool$DefaultForkJoinWorkerThreadFactory_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.ForkJoinPool$DefaultForkJoinWorkerThreadFactory",
	"java.lang.Object",
	"java.util.concurrent.ForkJoinPool$ForkJoinWorkerThreadFactory",
	_ForkJoinPool$DefaultForkJoinWorkerThreadFactory_FieldInfo_,
	_ForkJoinPool$DefaultForkJoinWorkerThreadFactory_MethodInfo_,
	nullptr,
	nullptr,
	_ForkJoinPool$DefaultForkJoinWorkerThreadFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.ForkJoinPool"
};

$Object* allocate$ForkJoinPool$DefaultForkJoinWorkerThreadFactory($Class* clazz) {
	return $of($alloc(ForkJoinPool$DefaultForkJoinWorkerThreadFactory));
}

$AccessControlContext* ForkJoinPool$DefaultForkJoinWorkerThreadFactory::ACC = nullptr;

void ForkJoinPool$DefaultForkJoinWorkerThreadFactory::init$() {
}

$ForkJoinWorkerThread* ForkJoinPool$DefaultForkJoinWorkerThreadFactory::newThread($ForkJoinPool* pool) {
	$beforeCallerSensitive();
	return $cast($ForkJoinWorkerThread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ForkJoinPool$DefaultForkJoinWorkerThreadFactory$1, this, pool)), ForkJoinPool$DefaultForkJoinWorkerThreadFactory::ACC));
}

void clinit$ForkJoinPool$DefaultForkJoinWorkerThreadFactory($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ForkJoinPool$DefaultForkJoinWorkerThreadFactory::ACC, $ForkJoinPool::contextWithPermissions($$new($PermissionArray, {
		static_cast<$Permission*>($$new($RuntimePermission, "getClassLoader"_s)),
		static_cast<$Permission*>($$new($RuntimePermission, "setContextClassLoader"_s))
	})));
}

ForkJoinPool$DefaultForkJoinWorkerThreadFactory::ForkJoinPool$DefaultForkJoinWorkerThreadFactory() {
}

$Class* ForkJoinPool$DefaultForkJoinWorkerThreadFactory::load$($String* name, bool initialize) {
	$loadClass(ForkJoinPool$DefaultForkJoinWorkerThreadFactory, name, initialize, &_ForkJoinPool$DefaultForkJoinWorkerThreadFactory_ClassInfo_, clinit$ForkJoinPool$DefaultForkJoinWorkerThreadFactory, allocate$ForkJoinPool$DefaultForkJoinWorkerThreadFactory);
	return class$;
}

$Class* ForkJoinPool$DefaultForkJoinWorkerThreadFactory::class$ = nullptr;

		} // concurrent
	} // util
} // java