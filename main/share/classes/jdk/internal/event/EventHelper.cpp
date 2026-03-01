#include <jdk/internal/event/EventHelper.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Error.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/time/temporal/Temporal.h>
#include <java/util/Date.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaUtilJarAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef DEBUG
#undef JUJA
#undef LOGGER_HANDLE
#undef LOG_LEVEL
#undef MIN
#undef SECURITY_LOGGER_NAME

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $Temporal = ::java::time::temporal::Temporal;
using $Date = ::java::util::Date;
using $IntFunction = ::java::util::function::IntFunction;
using $Collectors = ::java::util::stream::Collectors;
using $IntStream = ::java::util::stream::IntStream;
using $Stream = ::java::util::stream::Stream;
using $JavaUtilJarAccess = ::jdk::internal::access::JavaUtilJarAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace jdk {
	namespace internal {
		namespace event {

class EventHelper$$Lambda$toString : public $IntFunction {
	$class(EventHelper$$Lambda$toString, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t i) override {
		 return $of($Integer::toString(i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<EventHelper$$Lambda$toString>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo EventHelper$$Lambda$toString::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(EventHelper$$Lambda$toString, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(EventHelper$$Lambda$toString, apply, $Object*, int32_t)},
	{}
};
$ClassInfo EventHelper$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.event.EventHelper$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* EventHelper$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(EventHelper$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* EventHelper$$Lambda$toString::class$ = nullptr;

$FieldInfo _EventHelper_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(EventHelper, $assertionsDisabled)},
	{"JUJA", "Ljdk/internal/access/JavaUtilJarAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EventHelper, JUJA)},
	{"loggingSecurity", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(EventHelper, loggingSecurity)},
	{"securityLogger", "Ljava/lang/System$Logger;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(EventHelper, securityLogger)},
	{"LOGGER_HANDLE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EventHelper, LOGGER_HANDLE)},
	{"LOG_LEVEL", "Ljava/lang/System$Logger$Level;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EventHelper, LOG_LEVEL)},
	{"SECURITY_LOGGER_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EventHelper, SECURITY_LOGGER_NAME)},
	{}
};

$MethodInfo _EventHelper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(EventHelper, init$, void)},
	{"getDurationString", "(Ljava/time/Instant;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(EventHelper, getDurationString, $String*, $Instant*)},
	{"isLoggingSecurity", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(EventHelper, isLoggingSecurity, bool)},
	{"logSecurityPropertyEvent", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(EventHelper, logSecurityPropertyEvent, void, $String*, $String*)},
	{"logTLSHandshakeEvent", "(Ljava/time/Instant;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;J)V", nullptr, $PUBLIC | $STATIC, $staticMethod(EventHelper, logTLSHandshakeEvent, void, $Instant*, $String*, int32_t, $String*, $String*, int64_t)},
	{"logX509CertificateEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;IJJJ)V", nullptr, $PUBLIC | $STATIC, $staticMethod(EventHelper, logX509CertificateEvent, void, $String*, $String*, $String*, $String*, $String*, int32_t, int64_t, int64_t, int64_t)},
	{"logX509ValidationEvent", "(I[I)V", nullptr, $PUBLIC | $STATIC, $staticMethod(EventHelper, logX509ValidationEvent, void, int32_t, $ints*)},
	{}
};

$ClassInfo _EventHelper_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.event.EventHelper",
	"java.lang.Object",
	nullptr,
	_EventHelper_FieldInfo_,
	_EventHelper_MethodInfo_
};

$Object* allocate$EventHelper($Class* clazz) {
	return $of($alloc(EventHelper));
}

bool EventHelper::$assertionsDisabled = false;
$JavaUtilJarAccess* EventHelper::JUJA = nullptr;
$volatile(bool) EventHelper::loggingSecurity = false;
$volatile($System$Logger*) EventHelper::securityLogger = nullptr;
$VarHandle* EventHelper::LOGGER_HANDLE = nullptr;
$System$Logger$Level* EventHelper::LOG_LEVEL = nullptr;
$String* EventHelper::SECURITY_LOGGER_NAME = nullptr;

void EventHelper::init$() {
}

void EventHelper::logTLSHandshakeEvent($Instant* start, $String* peerHost, int32_t peerPort, $String* cipherSuite, $String* protocolVersion, int64_t peerCertId) {
	$init(EventHelper);
	$useLocalCurrentObjectStackCache();
	if (!EventHelper::$assertionsDisabled && !(EventHelper::securityLogger != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($String, prepend, getDurationString(start));
	$nc(EventHelper::securityLogger)->log(EventHelper::LOG_LEVEL, $$str({prepend, " TLSHandshake: {0}:{1,number,#}, {2}, {3}, {4,number,#}"_s}), $$new($ObjectArray, {
		$of(peerHost),
		$($of($Integer::valueOf(peerPort))),
		$of(protocolVersion),
		$of(cipherSuite),
		$($of($Long::valueOf(peerCertId)))
	}));
}

void EventHelper::logSecurityPropertyEvent($String* key, $String* value) {
	$init(EventHelper);
	if (!EventHelper::$assertionsDisabled && !(EventHelper::securityLogger != nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(EventHelper::securityLogger)->log(EventHelper::LOG_LEVEL, "SecurityPropertyModification: key:{0}, value:{1}"_s, $$new($ObjectArray, {
		$of(key),
		$of(value)
	}));
}

void EventHelper::logX509ValidationEvent(int32_t anchorCertId, $ints* certIds) {
	$init(EventHelper);
	$useLocalCurrentObjectStackCache();
	if (!EventHelper::$assertionsDisabled && !(EventHelper::securityLogger != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($String, codes, $cast($String, $nc($($nc($($IntStream::of(certIds)))->mapToObj(static_cast<$IntFunction*>($$new(EventHelper$$Lambda$toString)))))->collect($($Collectors::joining(", "_s)))));
	$nc(EventHelper::securityLogger)->log(EventHelper::LOG_LEVEL, "ValidationChain: {0,number,#}, {1}"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(anchorCertId))),
		$of(codes)
	}));
}

void EventHelper::logX509CertificateEvent($String* algId, $String* serialNum, $String* subject, $String* issuer, $String* keyType, int32_t length, int64_t certId, int64_t beginDate, int64_t endDate) {
	$init(EventHelper);
	$useLocalCurrentObjectStackCache();
	if (!EventHelper::$assertionsDisabled && !(EventHelper::securityLogger != nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(EventHelper::securityLogger)->log(EventHelper::LOG_LEVEL, "X509Certificate: Alg:{0}, Serial:{1}, Subject:{2}, Issuer:{3}, Key type:{4}, Length:{5,number,#}, Cert Id:{6,number,#}, Valid from:{7}, Valid until:{8}"_s, $$new($ObjectArray, {
		$of(algId),
		$of(serialNum),
		$of(subject),
		$of(issuer),
		$of(keyType),
		$($of($Integer::valueOf(length))),
		$($of($Long::valueOf(certId))),
		$of($$new($Date, beginDate)),
		$of($$new($Date, endDate))
	}));
}

$String* EventHelper::getDurationString($Instant* start) {
	$init(EventHelper);
	$useLocalCurrentObjectStackCache();
	if (start != nullptr) {
		$init($Instant);
		if (start->equals($Instant::MIN)) {
			return "N/A"_s;
		}
		$var($Duration, duration, $Duration::between(start, $($Instant::now())));
		int64_t micros = $nc(duration)->toNanos() / 1000;
		if (micros < 0x000F4240) {
			return $str({"duration = "_s, $$str((micros / 1000.0)), " ms:"_s});
		} else {
			return $str({"duration = "_s, $$str(((micros / 1000) / 1000.0)), " s:"_s});
		}
	} else {
		return ""_s;
	}
}

bool EventHelper::isLoggingSecurity() {
	$init(EventHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (EventHelper::securityLogger == nullptr && !$nc(EventHelper::JUJA)->isInitializing()) {
		$nc(EventHelper::LOGGER_HANDLE)->compareAndSet($$new($ObjectArray, {($Object*)nullptr, $($of($System::getLogger(EventHelper::SECURITY_LOGGER_NAME)))}));
		EventHelper::loggingSecurity = $nc(EventHelper::securityLogger)->isLoggable(EventHelper::LOG_LEVEL);
	}
	return EventHelper::loggingSecurity;
}

void clinit$EventHelper($Class* class$) {
	$assignStatic(EventHelper::SECURITY_LOGGER_NAME, "jdk.event.security"_s);
	$beforeCallerSensitive();
	EventHelper::$assertionsDisabled = !EventHelper::class$->desiredAssertionStatus();
	$assignStatic(EventHelper::JUJA, $SharedSecrets::javaUtilJarAccess());
	{
		try {
			$load($System$Logger);
			$assignStatic(EventHelper::LOGGER_HANDLE, $nc($($MethodHandles::lookup()))->findStaticVarHandle(EventHelper::class$, "securityLogger"_s, $System$Logger::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($Error, static_cast<$Throwable*>(e));
		}
	}
	$init($System$Logger$Level);
	$assignStatic(EventHelper::LOG_LEVEL, $System$Logger$Level::DEBUG);
}

EventHelper::EventHelper() {
}

$Class* EventHelper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(EventHelper$$Lambda$toString::classInfo$.name)) {
			return EventHelper$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(EventHelper, name, initialize, &_EventHelper_ClassInfo_, clinit$EventHelper, allocate$EventHelper);
	return class$;
}

$Class* EventHelper::class$ = nullptr;

		} // event
	} // internal
} // jdk