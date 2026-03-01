#include <jdk/internal/logger/DefaultLoggerFinder.h>

#include <java/io/Serializable.h>
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
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/Function.h>
#include <jdk/internal/logger/DefaultLoggerFinder$1.h>
#include <jdk/internal/logger/DefaultLoggerFinder$SharedLoggers.h>
#include <jdk/internal/logger/SimpleConsoleLogger.h>
#include <jcpp.h>

#undef LOGGERFINDER_PERMISSION

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $System$Logger = ::java::lang::System$Logger;
using $System$LoggerFinder = ::java::lang::System$LoggerFinder;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Function = ::java::util::function::Function;
using $DefaultLoggerFinder$1 = ::jdk::internal::logger::DefaultLoggerFinder$1;
using $DefaultLoggerFinder$SharedLoggers = ::jdk::internal::logger::DefaultLoggerFinder$SharedLoggers;
using $SimpleConsoleLogger = ::jdk::internal::logger::SimpleConsoleLogger;

namespace jdk {
	namespace internal {
		namespace logger {

class DefaultLoggerFinder$$Lambda$makeSimpleLogger : public $Function {
	$class(DefaultLoggerFinder$$Lambda$makeSimpleLogger, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* name) override {
		 return $of($SimpleConsoleLogger::makeSimpleLogger($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DefaultLoggerFinder$$Lambda$makeSimpleLogger>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DefaultLoggerFinder$$Lambda$makeSimpleLogger::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DefaultLoggerFinder$$Lambda$makeSimpleLogger, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DefaultLoggerFinder$$Lambda$makeSimpleLogger, apply, $Object*, Object$*)},
	{}
};
$ClassInfo DefaultLoggerFinder$$Lambda$makeSimpleLogger::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.logger.DefaultLoggerFinder$$Lambda$makeSimpleLogger",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* DefaultLoggerFinder$$Lambda$makeSimpleLogger::load$($String* name, bool initialize) {
	$loadClass(DefaultLoggerFinder$$Lambda$makeSimpleLogger, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DefaultLoggerFinder$$Lambda$makeSimpleLogger::class$ = nullptr;

$FieldInfo _DefaultLoggerFinder_FieldInfo_[] = {
	{"LOGGERFINDER_PERMISSION", "Ljava/lang/RuntimePermission;", nullptr, $STATIC | $FINAL, $staticField(DefaultLoggerFinder, LOGGERFINDER_PERMISSION)},
	{}
};

$MethodInfo _DefaultLoggerFinder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(DefaultLoggerFinder, init$, void)},
	{"<init>", "(Ljava/lang/Void;)V", nullptr, $PRIVATE, $method(DefaultLoggerFinder, init$, void, $Void*)},
	{"checkPermission", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(DefaultLoggerFinder, checkPermission, $Void*)},
	{"demandLoggerFor", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PROTECTED, $virtualMethod(DefaultLoggerFinder, demandLoggerFor, $System$Logger*, $String*, $Module*)},
	{"getLocalizedLogger", "(Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PUBLIC | $FINAL, $virtualMethod(DefaultLoggerFinder, getLocalizedLogger, $System$Logger*, $String*, $ResourceBundle*, $Module*)},
	{"getLogger", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PUBLIC | $FINAL, $virtualMethod(DefaultLoggerFinder, getLogger, $System$Logger*, $String*, $Module*)},
	{"isSystem", "(Ljava/lang/Module;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(DefaultLoggerFinder, isSystem, bool, $Module*)},
	{}
};

$InnerClassInfo _DefaultLoggerFinder_InnerClassesInfo_[] = {
	{"java.lang.System$LoggerFinder", "java.lang.System", "LoggerFinder", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.logger.DefaultLoggerFinder$SharedLoggers", "jdk.internal.logger.DefaultLoggerFinder", "SharedLoggers", $STATIC | $FINAL},
	{"jdk.internal.logger.DefaultLoggerFinder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DefaultLoggerFinder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.logger.DefaultLoggerFinder",
	"java.lang.System$LoggerFinder",
	nullptr,
	_DefaultLoggerFinder_FieldInfo_,
	_DefaultLoggerFinder_MethodInfo_,
	nullptr,
	nullptr,
	_DefaultLoggerFinder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.logger.DefaultLoggerFinder$SharedLoggers,jdk.internal.logger.DefaultLoggerFinder$1"
};

$Object* allocate$DefaultLoggerFinder($Class* clazz) {
	return $of($alloc(DefaultLoggerFinder));
}

$RuntimePermission* DefaultLoggerFinder::LOGGERFINDER_PERMISSION = nullptr;

void DefaultLoggerFinder::init$() {
	DefaultLoggerFinder::init$($(checkPermission()));
}

void DefaultLoggerFinder::init$($Void* unused) {
	$System$LoggerFinder::init$();
}

$Void* DefaultLoggerFinder::checkPermission() {
	$init(DefaultLoggerFinder);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(DefaultLoggerFinder::LOGGERFINDER_PERMISSION);
	}
	return nullptr;
}

bool DefaultLoggerFinder::isSystem($Module* m) {
	$init(DefaultLoggerFinder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($DefaultLoggerFinder$1, m)))))))->booleanValue();
}

$System$Logger* DefaultLoggerFinder::getLogger($String* name, $Module* module) {
	$Objects::requireNonNull($of(name), "name"_s);
	$Objects::requireNonNull($of(module), "module"_s);
	checkPermission();
	return demandLoggerFor(name, module);
}

$System$Logger* DefaultLoggerFinder::getLocalizedLogger($String* name, $ResourceBundle* bundle, $Module* module) {
	return $System$LoggerFinder::getLocalizedLogger(name, bundle, module);
}

$System$Logger* DefaultLoggerFinder::demandLoggerFor($String* name, $Module* module) {
	$useLocalCurrentObjectStackCache();
	checkPermission();
	if (isSystem(module)) {
		$init($DefaultLoggerFinder$SharedLoggers);
		return $nc($DefaultLoggerFinder$SharedLoggers::system)->get(static_cast<$Function*>($$new(DefaultLoggerFinder$$Lambda$makeSimpleLogger)), name);
	} else {
		$init($DefaultLoggerFinder$SharedLoggers);
		return $nc($DefaultLoggerFinder$SharedLoggers::application)->get(static_cast<$Function*>($$new(DefaultLoggerFinder$$Lambda$makeSimpleLogger)), name);
	}
}

void clinit$DefaultLoggerFinder($Class* class$) {
	$assignStatic(DefaultLoggerFinder::LOGGERFINDER_PERMISSION, $new($RuntimePermission, "loggerFinder"_s));
}

DefaultLoggerFinder::DefaultLoggerFinder() {
}

$Class* DefaultLoggerFinder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DefaultLoggerFinder$$Lambda$makeSimpleLogger::classInfo$.name)) {
			return DefaultLoggerFinder$$Lambda$makeSimpleLogger::load$(name, initialize);
		}
	}
	$loadClass(DefaultLoggerFinder, name, initialize, &_DefaultLoggerFinder_ClassInfo_, clinit$DefaultLoggerFinder, allocate$DefaultLoggerFinder);
	return class$;
}

$Class* DefaultLoggerFinder::class$ = nullptr;

		} // logger
	} // internal
} // jdk