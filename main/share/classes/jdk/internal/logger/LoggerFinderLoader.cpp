#include <jdk/internal/logger/LoggerFinderLoader.h>

#include <java/io/FilePermission.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/InternalError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/System$Logger$Level.h>
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
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader.h>
#include <jdk/internal/logger/BootstrapLogger.h>
#include <jdk/internal/logger/DefaultLoggerFinder.h>
#include <jdk/internal/logger/LoggerFinderLoader$ErrorPolicy.h>
#include <jdk/internal/logger/SimpleConsoleLogger.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef CLASSLOADER_PERMISSION
#undef DEBUG
#undef ERROR
#undef FILE_READ_ACTION
#undef GET_CLASSLOADER_PERMISSION
#undef LOGGERFINDER_PERMISSION
#undef QUIET
#undef READ_PERMISSION
#undef ROOT
#undef WARNING

using $PermissionArray = $Array<::java::security::Permission>;
using $FilePermission = ::java::io::FilePermission;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $System$LoggerFinder = ::java::lang::System$LoggerFinder;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader = ::java::util::ServiceLoader;
using $BootstrapLogger = ::jdk::internal::logger::BootstrapLogger;
using $DefaultLoggerFinder = ::jdk::internal::logger::DefaultLoggerFinder;
using $LoggerFinderLoader$ErrorPolicy = ::jdk::internal::logger::LoggerFinderLoader$ErrorPolicy;
using $SimpleConsoleLogger = ::jdk::internal::logger::SimpleConsoleLogger;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace jdk {
	namespace internal {
		namespace logger {

class LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0 : public $PrivilegedAction {
	$class(LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(LoggerFinderLoader::lambda$findLoggerFinderProviders$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0, run, $Object*)},
	{}
};
$ClassInfo LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.logger.LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0::load$($String* name, bool initialize) {
	$loadClass(LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0::class$ = nullptr;

class LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1 : public $PrivilegedAction {
	$class(LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(LoggerFinderLoader::lambda$loadDefaultImplementation$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1, run, $Object*)},
	{}
};
$ClassInfo LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.logger.LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1::load$($String* name, bool initialize) {
	$loadClass(LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1::class$ = nullptr;

$FieldInfo _LoggerFinderLoader_FieldInfo_[] = {
	{"service", "Ljava/lang/System$LoggerFinder;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(LoggerFinderLoader, service$)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoggerFinderLoader, lock)},
	{"CLASSLOADER_PERMISSION", "Ljava/security/Permission;", nullptr, $STATIC | $FINAL, $staticField(LoggerFinderLoader, CLASSLOADER_PERMISSION)},
	{"READ_PERMISSION", "Ljava/security/Permission;", nullptr, $STATIC | $FINAL, $staticField(LoggerFinderLoader, READ_PERMISSION)},
	{"LOGGERFINDER_PERMISSION", "Ljava/lang/RuntimePermission;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LoggerFinderLoader, LOGGERFINDER_PERMISSION)},
	{}
};

$MethodInfo _LoggerFinderLoader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LoggerFinderLoader, init$, void)},
	{"configurationErrorPolicy", "()Ljdk/internal/logger/LoggerFinderLoader$ErrorPolicy;", nullptr, $PRIVATE | $STATIC, $staticMethod(LoggerFinderLoader, configurationErrorPolicy, $LoggerFinderLoader$ErrorPolicy*)},
	{"ensureSingletonProvider", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(LoggerFinderLoader, ensureSingletonProvider, bool)},
	{"findLoggerFinderProviders", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/lang/System$LoggerFinder;>;", $PRIVATE | $STATIC, $staticMethod(LoggerFinderLoader, findLoggerFinderProviders, $Iterator*)},
	{"getLoggerFinder", "()Ljava/lang/System$LoggerFinder;", nullptr, $PUBLIC | $STATIC, $staticMethod(LoggerFinderLoader, getLoggerFinder, $System$LoggerFinder*)},
	{"lambda$findLoggerFinderProviders$0", "()Ljava/util/Iterator;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LoggerFinderLoader, lambda$findLoggerFinderProviders$0, $Iterator*)},
	{"lambda$loadDefaultImplementation$1", "()Ljava/util/Iterator;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LoggerFinderLoader, lambda$loadDefaultImplementation$1, $Iterator*)},
	{"loadDefaultImplementation", "()Ljava/lang/System$LoggerFinder;", nullptr, $PRIVATE | $STATIC, $staticMethod(LoggerFinderLoader, loadDefaultImplementation, $System$LoggerFinder*)},
	{"loadLoggerFinder", "()Ljava/lang/System$LoggerFinder;", nullptr, $PRIVATE | $STATIC, $staticMethod(LoggerFinderLoader, loadLoggerFinder, $System$LoggerFinder*)},
	{"service", "()Ljava/lang/System$LoggerFinder;", nullptr, $PRIVATE | $STATIC, $staticMethod(LoggerFinderLoader, service, $System$LoggerFinder*)},
	{}
};

$InnerClassInfo _LoggerFinderLoader_InnerClassesInfo_[] = {
	{"jdk.internal.logger.LoggerFinderLoader$ErrorPolicy", "jdk.internal.logger.LoggerFinderLoader", "ErrorPolicy", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _LoggerFinderLoader_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.logger.LoggerFinderLoader",
	"java.lang.Object",
	nullptr,
	_LoggerFinderLoader_FieldInfo_,
	_LoggerFinderLoader_MethodInfo_,
	nullptr,
	nullptr,
	_LoggerFinderLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.logger.LoggerFinderLoader$ErrorPolicy"
};

$Object* allocate$LoggerFinderLoader($Class* clazz) {
	return $of($alloc(LoggerFinderLoader));
}

$volatile($System$LoggerFinder*) LoggerFinderLoader::service$ = nullptr;
$Object* LoggerFinderLoader::lock = nullptr;
$Permission* LoggerFinderLoader::CLASSLOADER_PERMISSION = nullptr;
$Permission* LoggerFinderLoader::READ_PERMISSION = nullptr;
$RuntimePermission* LoggerFinderLoader::LOGGERFINDER_PERMISSION = nullptr;

void LoggerFinderLoader::init$() {
	$throwNew($InternalError, "LoggerFinderLoader cannot be instantiated"_s);
}

$System$LoggerFinder* LoggerFinderLoader::service() {
	$init(LoggerFinderLoader);
	if (LoggerFinderLoader::service$ != nullptr) {
		return LoggerFinderLoader::service$;
	}
	$synchronized(LoggerFinderLoader::lock) {
		if (LoggerFinderLoader::service$ != nullptr) {
			return LoggerFinderLoader::service$;
		}
		$assignStatic(LoggerFinderLoader::service$, loadLoggerFinder());
	}
	$BootstrapLogger::redirectTemporaryLoggers();
	return LoggerFinderLoader::service$;
}

$LoggerFinderLoader$ErrorPolicy* LoggerFinderLoader::configurationErrorPolicy() {
	$init(LoggerFinderLoader);
	$useLocalCurrentObjectStackCache();
	$var($String, errorPolicy, $GetPropertyAction::privilegedGetProperty("jdk.logger.finder.error"_s));
	if (errorPolicy == nullptr || $nc(errorPolicy)->isEmpty()) {
		$init($LoggerFinderLoader$ErrorPolicy);
		return $LoggerFinderLoader$ErrorPolicy::WARNING;
	}
	try {
		$init($Locale);
		return $LoggerFinderLoader$ErrorPolicy::valueOf($($nc(errorPolicy)->toUpperCase($Locale::ROOT)));
	} catch ($IllegalArgumentException& x) {
		$init($LoggerFinderLoader$ErrorPolicy);
		return $LoggerFinderLoader$ErrorPolicy::WARNING;
	}
	$shouldNotReachHere();
}

bool LoggerFinderLoader::ensureSingletonProvider() {
	$init(LoggerFinderLoader);
	return $Boolean::parseBoolean($($GetPropertyAction::privilegedGetProperty("jdk.logger.finder.singleton"_s)));
}

$Iterator* LoggerFinderLoader::findLoggerFinderProviders() {
	$init(LoggerFinderLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Iterator, iterator, nullptr);
	if ($System::getSecurityManager() == nullptr) {
		$load($System$LoggerFinder);
		$assign(iterator, $nc($($ServiceLoader::load($System$LoggerFinder::class$, $($ClassLoader::getSystemClassLoader()))))->iterator());
	} else {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0)));
		$assign(iterator, $cast($Iterator, $AccessController::doPrivileged(pa, ($AccessControlContext*)nullptr, $$new($PermissionArray, {
			static_cast<$Permission*>(LoggerFinderLoader::LOGGERFINDER_PERMISSION),
			LoggerFinderLoader::CLASSLOADER_PERMISSION,
			LoggerFinderLoader::READ_PERMISSION
		}))));
	}
	return iterator;
}

$System$LoggerFinder* LoggerFinderLoader::loadLoggerFinder() {
	$init(LoggerFinderLoader);
	$useLocalCurrentObjectStackCache();
	$var($System$LoggerFinder, result, nullptr);
	try {
		$var($Iterator, iterator, findLoggerFinderProviders());
		if ($nc(iterator)->hasNext()) {
			$assign(result, $cast($System$LoggerFinder, iterator->next()));
			bool var$0 = iterator->hasNext();
			if (var$0 && ensureSingletonProvider()) {
				$throwNew($ServiceConfigurationError, "More than on LoggerFinder implementation"_s);
			}
		} else {
			$assign(result, loadDefaultImplementation());
		}
	} catch ($Error& x) {
		$assignStatic(LoggerFinderLoader::service$, ($assign(result, $new($DefaultLoggerFinder))));
		$LoggerFinderLoader$ErrorPolicy* errorPolicy = configurationErrorPolicy();
		$init($LoggerFinderLoader$ErrorPolicy);
		if (errorPolicy == $LoggerFinderLoader$ErrorPolicy::ERROR) {
			if ($instanceOf($Error, x)) {
				$throw(x);
			} else {
				$throwNew($ServiceConfigurationError, "Failed to instantiate LoggerFinder provider; Using default."_s, x);
			}
		} else {
			if (errorPolicy != $LoggerFinderLoader$ErrorPolicy::QUIET) {
				$var($SimpleConsoleLogger, logger, $new($SimpleConsoleLogger, "jdk.internal.logger"_s, false));
				$init($System$Logger$Level);
				logger->log($System$Logger$Level::WARNING, "Failed to instantiate LoggerFinder provider; Using default."_s);
				if (errorPolicy == $LoggerFinderLoader$ErrorPolicy::DEBUG) {
					logger->log($System$Logger$Level::WARNING, "Exception raised trying to instantiate LoggerFinder"_s, $cast($Throwable, x));
				}
			}
		}
	} catch ($RuntimeException& x) {
		$assignStatic(LoggerFinderLoader::service$, ($assign(result, $new($DefaultLoggerFinder))));
		$LoggerFinderLoader$ErrorPolicy* errorPolicy = configurationErrorPolicy();
		$init($LoggerFinderLoader$ErrorPolicy);
		if (errorPolicy == $LoggerFinderLoader$ErrorPolicy::ERROR) {
			if ($instanceOf($Error, x)) {
				$throw(x);
			} else {
				$throwNew($ServiceConfigurationError, "Failed to instantiate LoggerFinder provider; Using default."_s, x);
			}
		} else {
			if (errorPolicy != $LoggerFinderLoader$ErrorPolicy::QUIET) {
				$var($SimpleConsoleLogger, logger, $new($SimpleConsoleLogger, "jdk.internal.logger"_s, false));
				$init($System$Logger$Level);
				logger->log($System$Logger$Level::WARNING, "Failed to instantiate LoggerFinder provider; Using default."_s);
				if (errorPolicy == $LoggerFinderLoader$ErrorPolicy::DEBUG) {
					logger->log($System$Logger$Level::WARNING, "Exception raised trying to instantiate LoggerFinder"_s, $cast($Throwable, x));
				}
			}
		}
	}
	return result;
}

$System$LoggerFinder* LoggerFinderLoader::loadDefaultImplementation() {
	$init(LoggerFinderLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	$var($Iterator, iterator, nullptr);
	if (sm == nullptr) {
		$load($DefaultLoggerFinder);
		$assign(iterator, $nc($($ServiceLoader::loadInstalled($DefaultLoggerFinder::class$)))->iterator());
	} else {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1)));
		$assign(iterator, $cast($Iterator, $AccessController::doPrivileged(pa, ($AccessControlContext*)nullptr, $$new($PermissionArray, {
			static_cast<$Permission*>(LoggerFinderLoader::LOGGERFINDER_PERMISSION),
			LoggerFinderLoader::CLASSLOADER_PERMISSION,
			LoggerFinderLoader::READ_PERMISSION
		}))));
	}
	$var($DefaultLoggerFinder, result, nullptr);
	try {
		if ($nc(iterator)->hasNext()) {
			$assign(result, $cast($DefaultLoggerFinder, iterator->next()));
		}
	} catch ($RuntimeException& x) {
		$throwNew($ServiceConfigurationError, "Failed to instantiate default LoggerFinder"_s, x);
	}
	if (result == nullptr) {
		$assign(result, $new($DefaultLoggerFinder));
	}
	return result;
}

$System$LoggerFinder* LoggerFinderLoader::getLoggerFinder() {
	$init(LoggerFinderLoader);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(LoggerFinderLoader::LOGGERFINDER_PERMISSION);
	}
	return service();
}

$Iterator* LoggerFinderLoader::lambda$loadDefaultImplementation$1() {
	$init(LoggerFinderLoader);
	$beforeCallerSensitive();
	$load($DefaultLoggerFinder);
	return $nc($($ServiceLoader::loadInstalled($DefaultLoggerFinder::class$)))->iterator();
}

$Iterator* LoggerFinderLoader::lambda$findLoggerFinderProviders$0() {
	$init(LoggerFinderLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($System$LoggerFinder);
	return $nc($($ServiceLoader::load($System$LoggerFinder::class$, $($ClassLoader::getSystemClassLoader()))))->iterator();
}

void clinit$LoggerFinderLoader($Class* class$) {
	$assignStatic(LoggerFinderLoader::lock, $new($ints, 0));
	$init($SecurityConstants);
	$assignStatic(LoggerFinderLoader::CLASSLOADER_PERMISSION, $SecurityConstants::GET_CLASSLOADER_PERMISSION);
	$assignStatic(LoggerFinderLoader::READ_PERMISSION, $new($FilePermission, "<<ALL FILES>>"_s, $SecurityConstants::FILE_READ_ACTION));
	$assignStatic(LoggerFinderLoader::LOGGERFINDER_PERMISSION, $new($RuntimePermission, "loggerFinder"_s));
}

LoggerFinderLoader::LoggerFinderLoader() {
}

$Class* LoggerFinderLoader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0::classInfo$.name)) {
			return LoggerFinderLoader$$Lambda$lambda$findLoggerFinderProviders$0::load$(name, initialize);
		}
		if (name->equals(LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1::classInfo$.name)) {
			return LoggerFinderLoader$$Lambda$lambda$loadDefaultImplementation$1$1::load$(name, initialize);
		}
	}
	$loadClass(LoggerFinderLoader, name, initialize, &_LoggerFinderLoader_ClassInfo_, clinit$LoggerFinderLoader, allocate$LoggerFinderLoader);
	return class$;
}

$Class* LoggerFinderLoader::class$ = nullptr;

		} // logger
	} // internal
} // jdk