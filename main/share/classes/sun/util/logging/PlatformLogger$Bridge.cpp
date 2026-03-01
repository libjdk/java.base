#include <sun/util/logging/PlatformLogger$Bridge.h>

#include <java/lang/System$Logger.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/logger/LoggerWrapper.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Supplier = ::java::util::function::Supplier;
using $LoggerWrapper = ::jdk::internal::logger::LoggerWrapper;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace sun {
	namespace util {
		namespace logging {

$MethodInfo _PlatformLogger$Bridge_MethodInfo_[] = {
	{"convert", "(Ljava/lang/System$Logger;)Lsun/util/logging/PlatformLogger$Bridge;", nullptr, $PUBLIC | $STATIC, $staticMethod(PlatformLogger$Bridge, convert, PlatformLogger$Bridge*, $System$Logger*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, getName, $String*)},
	{"isEnabled", "()Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, isEnabled, bool)},
	{"isLoggable", "(Lsun/util/logging/PlatformLogger$Level;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, isLoggable, bool, $PlatformLogger$Level*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, log, void, $PlatformLogger$Level*, $String*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, log, void, $PlatformLogger$Level*, $String*, $Throwable*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, log, void, $PlatformLogger$Level*, $String*, $ObjectArray*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, log, void, $PlatformLogger$Level*, $Supplier*)},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, log, void, $PlatformLogger$Level*, $Throwable*, $Supplier*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logp, void, $PlatformLogger$Level*, $String*, $String*, $String*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logp, void, $PlatformLogger$Level*, $String*, $String*, $Supplier*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logp, void, $PlatformLogger$Level*, $String*, $String*, $String*, $ObjectArray*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logp, void, $PlatformLogger$Level*, $String*, $String*, $String*, $Throwable*)},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logp, void, $PlatformLogger$Level*, $String*, $String*, $Throwable*, $Supplier*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logrb, void, $PlatformLogger$Level*, $String*, $String*, $ResourceBundle*, $String*, $ObjectArray*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logrb, void, $PlatformLogger$Level*, $String*, $String*, $ResourceBundle*, $String*, $Throwable*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logrb, void, $PlatformLogger$Level*, $ResourceBundle*, $String*, $ObjectArray*)},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(PlatformLogger$Bridge, logrb, void, $PlatformLogger$Level*, $ResourceBundle*, $String*, $Throwable*)},
	{}
};

$InnerClassInfo _PlatformLogger$Bridge_InnerClassesInfo_[] = {
	{"sun.util.logging.PlatformLogger$Bridge", "sun.util.logging.PlatformLogger", "Bridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PlatformLogger$Bridge_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.util.logging.PlatformLogger$Bridge",
	nullptr,
	nullptr,
	nullptr,
	_PlatformLogger$Bridge_MethodInfo_,
	nullptr,
	nullptr,
	_PlatformLogger$Bridge_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.logging.PlatformLogger"
};

$Object* allocate$PlatformLogger$Bridge($Class* clazz) {
	return $of($alloc(PlatformLogger$Bridge));
}

PlatformLogger$Bridge* PlatformLogger$Bridge::convert($System$Logger* logger) {
	if ($instanceOf(PlatformLogger$Bridge, logger)) {
		return $cast(PlatformLogger$Bridge, logger);
	} else {
		return $new($LoggerWrapper, logger);
	}
}

$Class* PlatformLogger$Bridge::load$($String* name, bool initialize) {
	$loadClass(PlatformLogger$Bridge, name, initialize, &_PlatformLogger$Bridge_ClassInfo_, allocate$PlatformLogger$Bridge);
	return class$;
}

$Class* PlatformLogger$Bridge::class$ = nullptr;

		} // logging
	} // util
} // sun