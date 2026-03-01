#include <sun/util/logging/PlatformLogger.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Module.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/ref/WeakReference.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jdk/internal/logger/LazyLoggers.h>
#include <sun/util/logging/PlatformLogger$Bridge.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge$LoggerConfiguration.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <jcpp.h>

#undef ALL
#undef CONFIG
#undef FINE
#undef FINER
#undef FINEST
#undef INFO
#undef OFF
#undef SEVERE
#undef WARNING

using $PlatformLogger$LevelArray = $Array<::sun::util::logging::PlatformLogger$Level>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $WeakReference = ::java::lang::ref::WeakReference;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $LazyLoggers = ::jdk::internal::logger::LazyLoggers;
using $PlatformLogger$Bridge = ::sun::util::logging::PlatformLogger$Bridge;
using $PlatformLogger$ConfigurableBridge = ::sun::util::logging::PlatformLogger$ConfigurableBridge;
using $PlatformLogger$ConfigurableBridge$LoggerConfiguration = ::sun::util::logging::PlatformLogger$ConfigurableBridge$LoggerConfiguration;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace sun {
	namespace util {
		namespace logging {

$CompoundAttribute _PlatformLogger_MethodAnnotations_setLevel21[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _PlatformLogger_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(PlatformLogger, $assertionsDisabled)},
	{"loggers", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/ref/WeakReference<Lsun/util/logging/PlatformLogger;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(PlatformLogger, loggers)},
	{"loggerProxy", "Lsun/util/logging/PlatformLogger$Bridge;", nullptr, $PRIVATE | $FINAL, $field(PlatformLogger, loggerProxy)},
	{"spi2platformLevelMapping", "[Lsun/util/logging/PlatformLogger$Level;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PlatformLogger, spi2platformLevelMapping)},
	{}
};

$MethodInfo _PlatformLogger_MethodInfo_[] = {
	{"<init>", "(Lsun/util/logging/PlatformLogger$Bridge;)V", nullptr, $PRIVATE, $method(PlatformLogger, init$, void, $PlatformLogger$Bridge*)},
	{"config", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, config, void, $String*)},
	{"config", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, config, void, $String*, $Throwable*)},
	{"config", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, config, void, $String*, $ObjectArray*)},
	{"fine", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, fine, void, $String*)},
	{"fine", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, fine, void, $String*, $Throwable*)},
	{"fine", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, fine, void, $String*, $ObjectArray*)},
	{"finer", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, finer, void, $String*)},
	{"finer", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, finer, void, $String*, $Throwable*)},
	{"finer", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, finer, void, $String*, $ObjectArray*)},
	{"finest", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, finest, void, $String*)},
	{"finest", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, finest, void, $String*, $Throwable*)},
	{"finest", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, finest, void, $String*, $ObjectArray*)},
	{"getLogger", "(Ljava/lang/String;)Lsun/util/logging/PlatformLogger;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(PlatformLogger, getLogger, PlatformLogger*, $String*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, getName, $String*)},
	{"info", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, info, void, $String*)},
	{"info", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, info, void, $String*, $Throwable*)},
	{"info", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, info, void, $String*, $ObjectArray*)},
	{"isEnabled", "()Z", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, isEnabled, bool)},
	{"isLoggable", "(Lsun/util/logging/PlatformLogger$Level;)Z", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, isLoggable, bool, $PlatformLogger$Level*)},
	{"level", "()Lsun/util/logging/PlatformLogger$Level;", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, level, $PlatformLogger$Level*)},
	{"setLevel", "(Lsun/util/logging/PlatformLogger$Level;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(PlatformLogger, setLevel, void, $PlatformLogger$Level*), nullptr, nullptr, _PlatformLogger_MethodAnnotations_setLevel21},
	{"severe", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, severe, void, $String*)},
	{"severe", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, severe, void, $String*, $Throwable*)},
	{"severe", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, severe, void, $String*, $ObjectArray*)},
	{"toPlatformLevel", "(Ljava/lang/System$Logger$Level;)Lsun/util/logging/PlatformLogger$Level;", nullptr, $PUBLIC | $STATIC, $staticMethod(PlatformLogger, toPlatformLevel, $PlatformLogger$Level*, $System$Logger$Level*)},
	{"warning", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, warning, void, $String*)},
	{"warning", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(PlatformLogger, warning, void, $String*, $Throwable*)},
	{"warning", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PlatformLogger, warning, void, $String*, $ObjectArray*)},
	{}
};

$InnerClassInfo _PlatformLogger_InnerClassesInfo_[] = {
	{"sun.util.logging.PlatformLogger$ConfigurableBridge", "sun.util.logging.PlatformLogger", "ConfigurableBridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.PlatformLogger$Bridge", "sun.util.logging.PlatformLogger", "Bridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.PlatformLogger$Level", "sun.util.logging.PlatformLogger", "Level", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _PlatformLogger_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.logging.PlatformLogger",
	"java.lang.Object",
	nullptr,
	_PlatformLogger_FieldInfo_,
	_PlatformLogger_MethodInfo_,
	nullptr,
	nullptr,
	_PlatformLogger_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.logging.PlatformLogger$ConfigurableBridge,sun.util.logging.PlatformLogger$ConfigurableBridge$LoggerConfiguration,sun.util.logging.PlatformLogger$Bridge,sun.util.logging.PlatformLogger$Level"
};

$Object* allocate$PlatformLogger($Class* clazz) {
	return $of($alloc(PlatformLogger));
}

bool PlatformLogger::$assertionsDisabled = false;
$Map* PlatformLogger::loggers = nullptr;
$PlatformLogger$LevelArray* PlatformLogger::spi2platformLevelMapping = nullptr;

PlatformLogger* PlatformLogger::getLogger($String* name) {
	$load(PlatformLogger);
	$synchronized(class$) {
		$init(PlatformLogger);
		$useLocalCurrentObjectStackCache();
		$var(PlatformLogger, log, nullptr);
		$var($WeakReference, ref, $cast($WeakReference, $nc(PlatformLogger::loggers)->get(name)));
		if (ref != nullptr) {
			$assign(log, $cast(PlatformLogger, ref->get()));
		}
		if (log == nullptr) {
			$assign(log, $new(PlatformLogger, $($PlatformLogger$Bridge::convert($($LazyLoggers::getLazyLogger(name, $(PlatformLogger::class$->getModule())))))));
			$nc(PlatformLogger::loggers)->put(name, $$new($WeakReference, log));
		}
		return log;
	}
}

void PlatformLogger::init$($PlatformLogger$Bridge* loggerProxy) {
	$set(this, loggerProxy, loggerProxy);
}

bool PlatformLogger::isEnabled() {
	return $nc(this->loggerProxy)->isEnabled();
}

$String* PlatformLogger::getName() {
	return $nc(this->loggerProxy)->getName();
}

bool PlatformLogger::isLoggable($PlatformLogger$Level* level) {
	if (level == nullptr) {
		$throwNew($NullPointerException);
	}
	return $nc(this->loggerProxy)->isLoggable(level);
}

$PlatformLogger$Level* PlatformLogger::level() {
	$var($PlatformLogger$ConfigurableBridge$LoggerConfiguration, spi, $PlatformLogger$ConfigurableBridge::getLoggerConfiguration(this->loggerProxy));
	return spi == nullptr ? ($PlatformLogger$Level*)nullptr : $nc(spi)->getPlatformLevel();
}

void PlatformLogger::setLevel($PlatformLogger$Level* newLevel) {
	$var($PlatformLogger$ConfigurableBridge$LoggerConfiguration, spi, $PlatformLogger$ConfigurableBridge::getLoggerConfiguration(this->loggerProxy));
	if (spi != nullptr) {
		spi->setPlatformLevel(newLevel);
	}
}

void PlatformLogger::severe($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::SEVERE, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::severe($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::SEVERE, msg, t);
}

void PlatformLogger::severe($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::SEVERE, msg, params);
}

void PlatformLogger::warning($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::WARNING, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::warning($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::WARNING, msg, t);
}

void PlatformLogger::warning($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::WARNING, msg, params);
}

void PlatformLogger::info($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::INFO, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::info($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::INFO, msg, t);
}

void PlatformLogger::info($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::INFO, msg, params);
}

void PlatformLogger::config($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::CONFIG, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::config($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::CONFIG, msg, t);
}

void PlatformLogger::config($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::CONFIG, msg, params);
}

void PlatformLogger::fine($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINE, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::fine($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINE, msg, t);
}

void PlatformLogger::fine($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINE, msg, params);
}

void PlatformLogger::finer($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINER, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::finer($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINER, msg, t);
}

void PlatformLogger::finer($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINER, msg, params);
}

void PlatformLogger::finest($String* msg) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINEST, msg, ($ObjectArray*)nullptr);
}

void PlatformLogger::finest($String* msg, $Throwable* t) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINEST, msg, t);
}

void PlatformLogger::finest($String* msg, $ObjectArray* params) {
	$init($PlatformLogger$Level);
	$nc(this->loggerProxy)->log($PlatformLogger$Level::FINEST, msg, params);
}

$PlatformLogger$Level* PlatformLogger::toPlatformLevel($System$Logger$Level* level) {
	$init(PlatformLogger);
	if (level == nullptr) {
		return nullptr;
	}
	if (!PlatformLogger::$assertionsDisabled && !($nc(level)->ordinal() < $nc(PlatformLogger::spi2platformLevelMapping)->length)) {
		$throwNew($AssertionError);
	}
	return $nc(PlatformLogger::spi2platformLevelMapping)->get($nc(level)->ordinal());
}

void clinit$PlatformLogger($Class* class$) {
	PlatformLogger::$assertionsDisabled = !PlatformLogger::class$->desiredAssertionStatus();
	$assignStatic(PlatformLogger::loggers, $new($HashMap));
	$init($PlatformLogger$Level);
	$assignStatic(PlatformLogger::spi2platformLevelMapping, $new($PlatformLogger$LevelArray, {
		$PlatformLogger$Level::ALL,
		$PlatformLogger$Level::FINER,
		$PlatformLogger$Level::FINE,
		$PlatformLogger$Level::INFO,
		$PlatformLogger$Level::WARNING,
		$PlatformLogger$Level::SEVERE,
		$PlatformLogger$Level::OFF
	}));
}

PlatformLogger::PlatformLogger() {
}

$Class* PlatformLogger::load$($String* name, bool initialize) {
	$loadClass(PlatformLogger, name, initialize, &_PlatformLogger_ClassInfo_, clinit$PlatformLogger, allocate$PlatformLogger);
	return class$;
}

$Class* PlatformLogger::class$ = nullptr;

		} // logging
	} // util
} // sun