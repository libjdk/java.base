#include <jdk/internal/logger/BootstrapLogger.h>

#include <java/lang/AssertionError.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/util/Map.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/BooleanSupplier.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/logger/BootstrapLogger$BootstrapExecutors.h>
#include <jdk/internal/logger/BootstrapLogger$DetectBackend.h>
#include <jdk/internal/logger/BootstrapLogger$LogEvent.h>
#include <jdk/internal/logger/BootstrapLogger$LoggingBackend.h>
#include <jdk/internal/logger/BootstrapLogger$RedirectedLoggers.h>
#include <jdk/internal/logger/LazyLoggers$LazyLoggerAccessor.h>
#include <jdk/internal/logger/SurrogateLogger.h>
#include <jdk/internal/misc/VM.h>
#include <sun/util/logging/PlatformLogger$Bridge.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge$LoggerConfiguration.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <jcpp.h>

#undef CUSTOM
#undef INFO
#undef INSTANCE
#undef JUL_DEFAULT

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $Map = ::java::util::Map;
using $ResourceBundle = ::java::util::ResourceBundle;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $Supplier = ::java::util::function::Supplier;
using $BootstrapLogger$BootstrapExecutors = ::jdk::internal::logger::BootstrapLogger$BootstrapExecutors;
using $BootstrapLogger$DetectBackend = ::jdk::internal::logger::BootstrapLogger$DetectBackend;
using $BootstrapLogger$LogEvent = ::jdk::internal::logger::BootstrapLogger$LogEvent;
using $BootstrapLogger$LoggingBackend = ::jdk::internal::logger::BootstrapLogger$LoggingBackend;
using $BootstrapLogger$RedirectedLoggers = ::jdk::internal::logger::BootstrapLogger$RedirectedLoggers;
using $LazyLoggers$LazyLoggerAccessor = ::jdk::internal::logger::LazyLoggers$LazyLoggerAccessor;
using $VM = ::jdk::internal::misc::VM;
using $PlatformLogger$Bridge = ::sun::util::logging::PlatformLogger$Bridge;
using $PlatformLogger$ConfigurableBridge = ::sun::util::logging::PlatformLogger$ConfigurableBridge;
using $PlatformLogger$ConfigurableBridge$LoggerConfiguration = ::sun::util::logging::PlatformLogger$ConfigurableBridge$LoggerConfiguration;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace jdk {
	namespace internal {
		namespace logger {

$FieldInfo _BootstrapLogger_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BootstrapLogger, $assertionsDisabled)},
	{"holder", "Ljdk/internal/logger/LazyLoggers$LazyLoggerAccessor;", nullptr, $FINAL, $field(BootstrapLogger, holder)},
	{"isBooted", "Ljava/util/function/BooleanSupplier;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(BootstrapLogger, isBooted$)},
	{"logManagerConfigured", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(BootstrapLogger, logManagerConfigured)},
	{}
};

$MethodInfo _BootstrapLogger_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljdk/internal/logger/LazyLoggers$LazyLoggerAccessor;)V", nullptr, 0, $method(BootstrapLogger, init$, void, $LazyLoggers$LazyLoggerAccessor*)},
	{"awaitPendingTasks", "()V", nullptr, $STATIC, $staticMethod(BootstrapLogger, awaitPendingTasks, void)},
	{"checkBootstrapping", "()Z", nullptr, 0, $method(BootstrapLogger, checkBootstrapping, bool)},
	{"createSurrogateLogger", "(Ljdk/internal/logger/LazyLoggers$LazyLoggerAccessor;)Ljava/lang/System$Logger;", nullptr, $STATIC | $SYNCHRONIZED, $staticMethod(BootstrapLogger, createSurrogateLogger, $System$Logger*, $LazyLoggers$LazyLoggerAccessor*)},
	{"flush", "(Ljdk/internal/logger/BootstrapLogger$LogEvent;)V", nullptr, 0, $method(BootstrapLogger, flush, void, $BootstrapLogger$LogEvent*)},
	{"getLogger", "(Ljdk/internal/logger/LazyLoggers$LazyLoggerAccessor;)Ljava/lang/System$Logger;", nullptr, $STATIC, $staticMethod(BootstrapLogger, getLogger, $System$Logger*, $LazyLoggers$LazyLoggerAccessor*)},
	{"getLoggerConfiguration", "()Lsun/util/logging/PlatformLogger$ConfigurableBridge$LoggerConfiguration;", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, getLoggerConfiguration, $PlatformLogger$ConfigurableBridge$LoggerConfiguration*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, getName, $String*)},
	{"isAlive", "()Z", nullptr, $STATIC, $staticMethod(BootstrapLogger, isAlive, bool)},
	{"isBooted", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(BootstrapLogger, isBooted, bool)},
	{"isEnabled", "()Z", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, isEnabled, bool)},
	{"isLoggable", "(Ljava/lang/System$Logger$Level;)Z", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, isLoggable, bool, $System$Logger$Level*)},
	{"isLoggable", "(Lsun/util/logging/PlatformLogger$Level;)Z", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, isLoggable, bool, $PlatformLogger$Level*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $ResourceBundle*, $String*, $Throwable*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $ResourceBundle*, $String*, $ObjectArray*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $String*, $Throwable*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $String*, $ObjectArray*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier;)V", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $Supplier*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, Object$*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $String*)},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier;Ljava/lang/Throwable;)V", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/Throwable;)V", $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $System$Logger$Level*, $Supplier*, $Throwable*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $PlatformLogger$Level*, $String*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $PlatformLogger$Level*, $String*, $Throwable*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BootstrapLogger, log, void, $PlatformLogger$Level*, $String*, $ObjectArray*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $PlatformLogger$Level*, $Supplier*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(BootstrapLogger, log, void, $PlatformLogger$Level*, $Throwable*, $Supplier*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, logp, void, $PlatformLogger$Level*, $String*, $String*, $String*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(BootstrapLogger, logp, void, $PlatformLogger$Level*, $String*, $String*, $Supplier*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BootstrapLogger, logp, void, $PlatformLogger$Level*, $String*, $String*, $String*, $ObjectArray*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, logp, void, $PlatformLogger$Level*, $String*, $String*, $String*, $Throwable*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(BootstrapLogger, logp, void, $PlatformLogger$Level*, $String*, $String*, $Throwable*, $Supplier*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BootstrapLogger, logrb, void, $PlatformLogger$Level*, $String*, $String*, $ResourceBundle*, $String*, $ObjectArray*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, logrb, void, $PlatformLogger$Level*, $String*, $String*, $ResourceBundle*, $String*, $Throwable*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BootstrapLogger, logrb, void, $PlatformLogger$Level*, $ResourceBundle*, $String*, $ObjectArray*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(BootstrapLogger, logrb, void, $PlatformLogger$Level*, $ResourceBundle*, $String*, $Throwable*)},
	{"push", "(Ljdk/internal/logger/BootstrapLogger$LogEvent;)V", nullptr, 0, $method(BootstrapLogger, push, void, $BootstrapLogger$LogEvent*)},
	{"redirectTemporaryLoggers", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(BootstrapLogger, redirectTemporaryLoggers, void)},
	{"releaseSurrogateLoggers", "()Ljava/util/Map;", "()Ljava/util/Map<Ljdk/internal/logger/LazyLoggers$LazyLoggerAccessor;Ljdk/internal/logger/SurrogateLogger;>;", $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(BootstrapLogger, releaseSurrogateLoggers, $Map*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"useLazyLoggers", "()Z", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(BootstrapLogger, useLazyLoggers, bool)},
	{"useSurrogateLoggers", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapLogger, useSurrogateLoggers, bool)},
	{}
};

$InnerClassInfo _BootstrapLogger_InnerClassesInfo_[] = {
	{"java.lang.System$Logger", "java.lang.System", "Logger", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.PlatformLogger$Bridge", "sun.util.logging.PlatformLogger", "Bridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.PlatformLogger$ConfigurableBridge", "sun.util.logging.PlatformLogger", "ConfigurableBridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.logger.BootstrapLogger$RedirectedLoggers", "jdk.internal.logger.BootstrapLogger", "RedirectedLoggers", $STATIC | $FINAL},
	{"jdk.internal.logger.BootstrapLogger$DetectBackend", "jdk.internal.logger.BootstrapLogger", "DetectBackend", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.logger.BootstrapLogger$LoggingBackend", "jdk.internal.logger.BootstrapLogger", "LoggingBackend", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"jdk.internal.logger.BootstrapLogger$LogEvent", "jdk.internal.logger.BootstrapLogger", "LogEvent", $STATIC | $FINAL},
	{"jdk.internal.logger.BootstrapLogger$BootstrapExecutors", "jdk.internal.logger.BootstrapLogger", "BootstrapExecutors", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _BootstrapLogger_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.logger.BootstrapLogger",
	"java.lang.Object",
	"java.lang.System$Logger,sun.util.logging.PlatformLogger$Bridge,sun.util.logging.PlatformLogger$ConfigurableBridge",
	_BootstrapLogger_FieldInfo_,
	_BootstrapLogger_MethodInfo_,
	nullptr,
	nullptr,
	_BootstrapLogger_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.logger.BootstrapLogger$RedirectedLoggers,jdk.internal.logger.BootstrapLogger$DetectBackend,jdk.internal.logger.BootstrapLogger$DetectBackend$1,jdk.internal.logger.BootstrapLogger$LoggingBackend,jdk.internal.logger.BootstrapLogger$LogEvent,jdk.internal.logger.BootstrapLogger$BootstrapExecutors,jdk.internal.logger.BootstrapLogger$BootstrapExecutors$BootstrapMessageLoggerTask,jdk.internal.logger.BootstrapLogger$BootstrapExecutors$1"
};

$Object* allocate$BootstrapLogger($Class* clazz) {
	return $of($alloc(BootstrapLogger));
}

int32_t BootstrapLogger::hashCode() {
	 return this->$System$Logger::hashCode();
}

bool BootstrapLogger::equals(Object$* obj) {
	 return this->$System$Logger::equals(obj);
}

$Object* BootstrapLogger::clone() {
	 return this->$System$Logger::clone();
}

$String* BootstrapLogger::toString() {
	 return this->$System$Logger::toString();
}

void BootstrapLogger::finalize() {
	this->$System$Logger::finalize();
}

bool BootstrapLogger::$assertionsDisabled = false;
$volatile($BooleanSupplier*) BootstrapLogger::isBooted$ = nullptr;
$volatile(bool) BootstrapLogger::logManagerConfigured = false;

void BootstrapLogger::init$($LazyLoggers$LazyLoggerAccessor* holder) {
	$set(this, holder, holder);
}

void BootstrapLogger::push($BootstrapLogger$LogEvent* log) {
	$BootstrapLogger$BootstrapExecutors::enqueue(log);
	checkBootstrapping();
}

void BootstrapLogger::flush($BootstrapLogger$LogEvent* event) {
	$useLocalCurrentObjectStackCache();
	if (!BootstrapLogger::$assertionsDisabled && !($nc(event)->bootstrap == this)) {
		$throwNew($AssertionError);
	}
	if ($nc(event)->platformLevel != nullptr) {
		$var($PlatformLogger$Bridge, concrete, $nc(this->holder)->getConcretePlatformLogger(this));
		$BootstrapLogger$LogEvent::log(event, concrete);
	} else {
		$var($System$Logger, concrete, $nc(this->holder)->getConcreteLogger(this));
		$BootstrapLogger$LogEvent::log(event, concrete);
	}
}

$String* BootstrapLogger::getName() {
	return $nc(this->holder)->name;
}

bool BootstrapLogger::checkBootstrapping() {
	if (isBooted()) {
		$BootstrapLogger$BootstrapExecutors::flush();
		return false;
	}
	return true;
}

bool BootstrapLogger::isLoggable($System$Logger$Level* level) {
	if (checkBootstrapping()) {
		int32_t var$0 = $nc(level)->getSeverity();
		return var$0 >= $System$Logger$Level::INFO->getSeverity();
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		return $nc(spi)->isLoggable(level);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $ResourceBundle* bundle, $String* key, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, bundle, key, thrown)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, bundle, key, thrown);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $ResourceBundle* bundle, $String* format, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, bundle, format, params)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, bundle, format, params);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $String* msg, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, ($ResourceBundle*)nullptr, msg, thrown)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, msg, thrown);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $String* format, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, ($ResourceBundle*)nullptr, format, params)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, format, params);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, msgSupplier)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, msgSupplier);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, Object$* obj) {
	if (checkBootstrapping()) {
		$System$Logger::log(level, obj);
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, obj);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $String* msg) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, ($ResourceBundle*)nullptr, msg, ($ObjectArray*)nullptr)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, msg);
	}
}

void BootstrapLogger::log($System$Logger$Level* level, $Supplier* msgSupplier, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, msgSupplier, thrown)));
	} else {
		$var($System$Logger, spi, $nc(this->holder)->wrapped());
		$nc(spi)->log(level, msgSupplier, thrown);
	}
}

bool BootstrapLogger::isLoggable($PlatformLogger$Level* level) {
	if (checkBootstrapping()) {
		int32_t var$0 = $nc(level)->intValue();
		return var$0 >= $PlatformLogger$Level::INFO->intValue();
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		return $nc(spi)->isLoggable(level);
	}
}

bool BootstrapLogger::isEnabled() {
	if (checkBootstrapping()) {
		return true;
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		return $nc(spi)->isEnabled();
	}
}

void BootstrapLogger::log($PlatformLogger$Level* level, $String* msg) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, msg)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->log(level, msg);
	}
}

void BootstrapLogger::log($PlatformLogger$Level* level, $String* msg, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, msg, thrown)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->log(level, msg, thrown);
	}
}

void BootstrapLogger::log($PlatformLogger$Level* level, $String* msg, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, msg, params)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->log(level, msg, params);
	}
}

void BootstrapLogger::log($PlatformLogger$Level* level, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, msgSupplier)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->log(level, msgSupplier);
	}
}

void BootstrapLogger::log($PlatformLogger$Level* level, $Throwable* thrown, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::vaueOf(this, level, msgSupplier, thrown)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->log(level, thrown, msgSupplier);
	}
}

void BootstrapLogger::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, ($ResourceBundle*)nullptr, msg, ($ObjectArray*)nullptr)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logp(level, sourceClass, sourceMethod, msg);
	}
}

void BootstrapLogger::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, msgSupplier, nullptr)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logp(level, sourceClass, sourceMethod, msgSupplier);
	}
}

void BootstrapLogger::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, ($ResourceBundle*)nullptr, msg, params)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logp(level, sourceClass, sourceMethod, msg, params);
	}
}

void BootstrapLogger::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, ($ResourceBundle*)nullptr, msg, thrown)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logp(level, sourceClass, sourceMethod, msg, thrown);
	}
}

void BootstrapLogger::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $Throwable* thrown, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, msgSupplier, thrown)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logp(level, sourceClass, sourceMethod, thrown, msgSupplier);
	}
}

void BootstrapLogger::logrb($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $ResourceBundle* bundle, $String* msg, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, bundle, msg, params)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logrb(level, sourceClass, sourceMethod, bundle, msg, params);
	}
}

void BootstrapLogger::logrb($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $ResourceBundle* bundle, $String* msg, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, sourceClass, sourceMethod, bundle, msg, thrown)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logrb(level, sourceClass, sourceMethod, bundle, msg, thrown);
	}
}

void BootstrapLogger::logrb($PlatformLogger$Level* level, $ResourceBundle* bundle, $String* msg, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, ($String*)nullptr, ($String*)nullptr, bundle, msg, params)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logrb(level, bundle, msg, params);
	}
}

void BootstrapLogger::logrb($PlatformLogger$Level* level, $ResourceBundle* bundle, $String* msg, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (checkBootstrapping()) {
		push($($BootstrapLogger$LogEvent::valueOf(this, level, ($String*)nullptr, ($String*)nullptr, bundle, msg, thrown)));
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		$nc(spi)->logrb(level, bundle, msg, thrown);
	}
}

$PlatformLogger$ConfigurableBridge$LoggerConfiguration* BootstrapLogger::getLoggerConfiguration() {
	if (checkBootstrapping()) {
		return $PlatformLogger$ConfigurableBridge::getLoggerConfiguration();
	} else {
		$var($PlatformLogger$Bridge, spi, $nc(this->holder)->platform());
		return $PlatformLogger$ConfigurableBridge::getLoggerConfiguration(spi);
	}
}

bool BootstrapLogger::isBooted() {
	$init(BootstrapLogger);
	if (BootstrapLogger::isBooted$ != nullptr) {
		return $nc(BootstrapLogger::isBooted$)->getAsBoolean();
	} else {
		return $VM::isBooted();
	}
}

bool BootstrapLogger::useSurrogateLoggers() {
	$init(BootstrapLogger);
	if (!isBooted()) {
		return true;
	}
	$init($BootstrapLogger$DetectBackend);
	$init($BootstrapLogger$LoggingBackend);
	return $BootstrapLogger$DetectBackend::detectedBackend == $BootstrapLogger$LoggingBackend::JUL_DEFAULT && !BootstrapLogger::logManagerConfigured;
}

bool BootstrapLogger::useLazyLoggers() {
	$load(BootstrapLogger);
	$synchronized(class$) {
		$init(BootstrapLogger);
		$init($BootstrapLogger$DetectBackend);
		$init($BootstrapLogger$LoggingBackend);
		bool var$0 = !BootstrapLogger::isBooted() || $BootstrapLogger$DetectBackend::detectedBackend == $BootstrapLogger$LoggingBackend::CUSTOM;
		return var$0 || useSurrogateLoggers();
	}
}

$System$Logger* BootstrapLogger::getLogger($LazyLoggers$LazyLoggerAccessor* accessor) {
	$init(BootstrapLogger);
	if (!BootstrapLogger::isBooted()) {
		return $new(BootstrapLogger, accessor);
	} else {
		if (useSurrogateLoggers()) {
			$synchronized(BootstrapLogger::class$) {
				if (useSurrogateLoggers()) {
					return createSurrogateLogger(accessor);
				}
			}
		}
		return $nc(accessor)->createLogger();
	}
}

$System$Logger* BootstrapLogger::createSurrogateLogger($LazyLoggers$LazyLoggerAccessor* a) {
	$load(BootstrapLogger);
	$synchronized(class$) {
		$init(BootstrapLogger);
		$init($BootstrapLogger$RedirectedLoggers);
		return $nc($BootstrapLogger$RedirectedLoggers::INSTANCE)->get(a);
	}
}

$Map* BootstrapLogger::releaseSurrogateLoggers() {
	$load(BootstrapLogger);
	$synchronized(class$) {
		$init(BootstrapLogger);
		bool releaseSurrogateLoggers = useSurrogateLoggers();
		BootstrapLogger::logManagerConfigured = true;
		if (releaseSurrogateLoggers) {
			$init($BootstrapLogger$RedirectedLoggers);
			return $nc($BootstrapLogger$RedirectedLoggers::INSTANCE)->drainLoggersMap();
		} else {
			return nullptr;
		}
	}
}

void BootstrapLogger::redirectTemporaryLoggers() {
	$init(BootstrapLogger);
	$var($Map, accessors, releaseSurrogateLoggers());
	if (accessors != nullptr) {
		$BootstrapLogger$RedirectedLoggers::replaceSurrogateLoggers(accessors);
	}
	$BootstrapLogger$BootstrapExecutors::flush();
}

void BootstrapLogger::awaitPendingTasks() {
	$init(BootstrapLogger);
	$BootstrapLogger$BootstrapExecutors::awaitPendingTasks();
}

bool BootstrapLogger::isAlive() {
	$init(BootstrapLogger);
	return $BootstrapLogger$BootstrapExecutors::isAlive();
}

void clinit$BootstrapLogger($Class* class$) {
	BootstrapLogger::$assertionsDisabled = !BootstrapLogger::class$->desiredAssertionStatus();
}

BootstrapLogger::BootstrapLogger() {
}

$Class* BootstrapLogger::load$($String* name, bool initialize) {
	$loadClass(BootstrapLogger, name, initialize, &_BootstrapLogger_ClassInfo_, clinit$BootstrapLogger, allocate$BootstrapLogger);
	return class$;
}

$Class* BootstrapLogger::class$ = nullptr;

		} // logger
	} // internal
} // jdk