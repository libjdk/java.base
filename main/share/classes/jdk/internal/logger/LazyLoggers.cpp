#include <jdk/internal/logger/LazyLoggers.h>

#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/System$Logger.h>
#include <java/lang/System$LoggerFinder.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/function/BiFunction.h>
#include <jdk/internal/logger/BootstrapLogger.h>
#include <jdk/internal/logger/DefaultLoggerFinder.h>
#include <jdk/internal/logger/LazyLoggers$1.h>
#include <jdk/internal/logger/LazyLoggers$JdkLazyLogger.h>
#include <jdk/internal/logger/LazyLoggers$LazyLoggerFactories.h>
#include <jcpp.h>

#undef LOGGERFINDER_PERMISSION

using $PermissionArray = $Array<::java::security::Permission>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $System$Logger = ::java::lang::System$Logger;
using $System$LoggerFinder = ::java::lang::System$LoggerFinder;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $BiFunction = ::java::util::function::BiFunction;
using $BootstrapLogger = ::jdk::internal::logger::BootstrapLogger;
using $DefaultLoggerFinder = ::jdk::internal::logger::DefaultLoggerFinder;
using $LazyLoggers$1 = ::jdk::internal::logger::LazyLoggers$1;
using $LazyLoggers$JdkLazyLogger = ::jdk::internal::logger::LazyLoggers$JdkLazyLogger;
using $LazyLoggers$LazyLoggerFactories = ::jdk::internal::logger::LazyLoggers$LazyLoggerFactories;

namespace jdk {
	namespace internal {
		namespace logger {

class LazyLoggers$$Lambda$getLoggerFinder : public $PrivilegedAction {
	$class(LazyLoggers$$Lambda$getLoggerFinder, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of($System$LoggerFinder::getLoggerFinder());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LazyLoggers$$Lambda$getLoggerFinder>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LazyLoggers$$Lambda$getLoggerFinder::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LazyLoggers$$Lambda$getLoggerFinder, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LazyLoggers$$Lambda$getLoggerFinder, run, $Object*)},
	{}
};
$ClassInfo LazyLoggers$$Lambda$getLoggerFinder::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.logger.LazyLoggers$$Lambda$getLoggerFinder",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* LazyLoggers$$Lambda$getLoggerFinder::load$($String* name, bool initialize) {
	$loadClass(LazyLoggers$$Lambda$getLoggerFinder, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LazyLoggers$$Lambda$getLoggerFinder::class$ = nullptr;

class LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1 : public $PrivilegedAction {
	$class(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name, $Module* module) {
		$set(this, name, name);
		$set(this, module, module);
	}
	virtual $Object* run() override {
		 return $of(LazyLoggers::lambda$getLoggerFromFinder$0(name, module));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1>());
	}
	$String* name = nullptr;
	$Module* module = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::fieldInfos[3] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, name)},
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, module)},
	{}
};
$MethodInfo LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, init$, void, $String*, $Module*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, run, $Object*)},
	{}
};
$ClassInfo LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.logger.LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::load$($String* name, bool initialize) {
	$loadClass(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::class$ = nullptr;

$FieldInfo _LazyLoggers_FieldInfo_[] = {
	{"LOGGERFINDER_PERMISSION", "Ljava/lang/RuntimePermission;", nullptr, $STATIC | $FINAL, $staticField(LazyLoggers, LOGGERFINDER_PERMISSION)},
	{"provider", "Ljava/lang/System$LoggerFinder;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(LazyLoggers, provider)},
	{"loggerSupplier", "Ljava/util/function/BiFunction;", "Ljava/util/function/BiFunction<Ljava/lang/String;Ljava/lang/Module;Ljava/lang/System$Logger;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LazyLoggers, loggerSupplier)},
	{"factories", "Ljdk/internal/logger/LazyLoggers$LazyLoggerFactories;", "Ljdk/internal/logger/LazyLoggers$LazyLoggerFactories<Ljava/lang/System$Logger;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LazyLoggers, factories)},
	{}
};

$MethodInfo _LazyLoggers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LazyLoggers, init$, void)},
	{"accessLoggerFinder", "()Ljava/lang/System$LoggerFinder;", nullptr, $PRIVATE | $STATIC, $staticMethod(LazyLoggers, accessLoggerFinder, $System$LoggerFinder*)},
	{"getLazyLogger", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(LazyLoggers, getLazyLogger, $System$Logger*, $String*, $Module*)},
	{"getLogger", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(LazyLoggers, getLogger, $System$Logger*, $String*, $Module*)},
	{"getLoggerFromFinder", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $STATIC, $staticMethod(LazyLoggers, getLoggerFromFinder, $System$Logger*, $String*, $Module*)},
	{"lambda$getLoggerFromFinder$0", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LazyLoggers, lambda$getLoggerFromFinder$0, $System$Logger*, $String*, $Module*)},
	{}
};

$InnerClassInfo _LazyLoggers_InnerClassesInfo_[] = {
	{"jdk.internal.logger.LazyLoggers$JdkLazyLogger", "jdk.internal.logger.LazyLoggers", "JdkLazyLogger", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.logger.LazyLoggers$LazyLoggerWrapper", "jdk.internal.logger.LazyLoggers", "LazyLoggerWrapper", $PRIVATE | $STATIC},
	{"jdk.internal.logger.LazyLoggers$LazyLoggerAccessor", "jdk.internal.logger.LazyLoggers", "LazyLoggerAccessor", $STATIC | $FINAL},
	{"jdk.internal.logger.LazyLoggers$LoggerAccessor", "jdk.internal.logger.LazyLoggers", "LoggerAccessor", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.logger.LazyLoggers$LazyLoggerFactories", "jdk.internal.logger.LazyLoggers", "LazyLoggerFactories", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.logger.LazyLoggers$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LazyLoggers_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.logger.LazyLoggers",
	"java.lang.Object",
	nullptr,
	_LazyLoggers_FieldInfo_,
	_LazyLoggers_MethodInfo_,
	nullptr,
	nullptr,
	_LazyLoggers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.logger.LazyLoggers$JdkLazyLogger,jdk.internal.logger.LazyLoggers$LazyLoggerWrapper,jdk.internal.logger.LazyLoggers$LazyLoggerAccessor,jdk.internal.logger.LazyLoggers$LoggerAccessor,jdk.internal.logger.LazyLoggers$LazyLoggerFactories,jdk.internal.logger.LazyLoggers$1"
};

$Object* allocate$LazyLoggers($Class* clazz) {
	return $of($alloc(LazyLoggers));
}

$RuntimePermission* LazyLoggers::LOGGERFINDER_PERMISSION = nullptr;
$volatile($System$LoggerFinder*) LazyLoggers::provider = nullptr;
$BiFunction* LazyLoggers::loggerSupplier = nullptr;
$LazyLoggers$LazyLoggerFactories* LazyLoggers::factories = nullptr;

void LazyLoggers::init$() {
	$throwNew($InternalError);
}

$System$LoggerFinder* LazyLoggers::accessLoggerFinder() {
	$init(LazyLoggers);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($System$LoggerFinder, prov, LazyLoggers::provider);
	if (prov == nullptr) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		$assign(prov, sm == nullptr ? $System$LoggerFinder::getLoggerFinder() : $cast($System$LoggerFinder, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(LazyLoggers$$Lambda$getLoggerFinder)))));
		$assignStatic(LazyLoggers::provider, prov);
	}
	return prov;
}

$System$Logger* LazyLoggers::getLoggerFromFinder($String* name, $Module* module) {
	$init(LazyLoggers);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return $nc($(accessLoggerFinder()))->getLogger(name, module);
	} else {
		return $cast($System$Logger, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1, name, module)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>(LazyLoggers::LOGGERFINDER_PERMISSION)})));
	}
}

$System$Logger* LazyLoggers::getLogger($String* name, $Module* module) {
	$init(LazyLoggers);
	if ($DefaultLoggerFinder::isSystem(module)) {
		return getLazyLogger(name, module);
	} else {
		return getLoggerFromFinder(name, module);
	}
}

$System$Logger* LazyLoggers::getLazyLogger($String* name, $Module* module) {
	$init(LazyLoggers);
	bool useLazyLogger = $BootstrapLogger::useLazyLoggers();
	if (useLazyLogger) {
		return $new($LazyLoggers$JdkLazyLogger, name, module);
	} else {
		return getLoggerFromFinder(name, module);
	}
}

$System$Logger* LazyLoggers::lambda$getLoggerFromFinder$0($String* name, $Module* module) {
	$init(LazyLoggers);
	return $nc($(accessLoggerFinder()))->getLogger(name, module);
}

void clinit$LazyLoggers($Class* class$) {
	$assignStatic(LazyLoggers::LOGGERFINDER_PERMISSION, $new($RuntimePermission, "loggerFinder"_s));
	$assignStatic(LazyLoggers::loggerSupplier, $new($LazyLoggers$1));
	$assignStatic(LazyLoggers::factories, $new($LazyLoggers$LazyLoggerFactories, LazyLoggers::loggerSupplier));
}

LazyLoggers::LazyLoggers() {
}

$Class* LazyLoggers::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LazyLoggers$$Lambda$getLoggerFinder::classInfo$.name)) {
			return LazyLoggers$$Lambda$getLoggerFinder::load$(name, initialize);
		}
		if (name->equals(LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::classInfo$.name)) {
			return LazyLoggers$$Lambda$lambda$getLoggerFromFinder$0$1::load$(name, initialize);
		}
	}
	$loadClass(LazyLoggers, name, initialize, &_LazyLoggers_ClassInfo_, clinit$LazyLoggers, allocate$LazyLoggers);
	return class$;
}

$Class* LazyLoggers::class$ = nullptr;

		} // logger
	} // internal
} // jdk