#include <java/time/chrono/HijrahChronology.h>

#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/AbstractChronology.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/HijrahChronology$1.h>
#include <java/time/chrono/HijrahDate.h>
#include <java/time/chrono/HijrahEra.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Arrays.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef AH
#undef CONF_PATH
#undef EPOCH_DAY
#undef INSTANCE
#undef KEY_ID
#undef KEY_ISO_START
#undef KEY_TYPE
#undef KEY_VERSION
#undef MAX_VALUE
#undef MIN_VALUE
#undef READ
#undef RESOURCE_PREFIX
#undef RESOURCE_SUFFIX

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $PermissionArray = $Array<::java::security::Permission>;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Files = ::java::nio::file::Files;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $ZoneId = ::java::time::ZoneId;
using $AbstractChronology = ::java::time::chrono::AbstractChronology;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
using $Chronology = ::java::time::chrono::Chronology;
using $Era = ::java::time::chrono::Era;
using $HijrahChronology$1 = ::java::time::chrono::HijrahChronology$1;
using $HijrahDate = ::java::time::chrono::HijrahDate;
using $HijrahEra = ::java::time::chrono::HijrahEra;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Arrays = ::java::util::Arrays;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;

namespace java {
	namespace time {
		namespace chrono {

class HijrahChronology$$Lambda$lambda$readConfigProperties$1 : public $PrivilegedAction {
	$class(HijrahChronology$$Lambda$lambda$readConfigProperties$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* resourceName) {
		$set(this, resourceName, resourceName);
	}
	virtual $Object* run() override {
		 return $of(HijrahChronology::lambda$readConfigProperties$1(resourceName));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$readConfigProperties$1>());
	}
	$String* resourceName = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HijrahChronology$$Lambda$lambda$readConfigProperties$1::fieldInfos[2] = {
	{"resourceName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HijrahChronology$$Lambda$lambda$readConfigProperties$1, resourceName)},
	{}
};
$MethodInfo HijrahChronology$$Lambda$lambda$readConfigProperties$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$readConfigProperties$1, init$, void, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$readConfigProperties$1, run, $Object*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$readConfigProperties$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$readConfigProperties$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$readConfigProperties$1::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$readConfigProperties$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$readConfigProperties$1::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$readConfigProperties$2$1 : public $PrivilegedAction {
	$class(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* resourceName) {
		$set(this, resourceName, resourceName);
	}
	virtual $Object* run() override {
		 return $of(HijrahChronology::lambda$readConfigProperties$2(resourceName));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$readConfigProperties$2$1>());
	}
	$String* resourceName = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::fieldInfos[2] = {
	{"resourceName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1, resourceName)},
	{}
};
$MethodInfo HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1, init$, void, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1, run, $Object*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$readConfigProperties$2$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2 : public $PrivilegedAction {
	$class(HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(HijrahChronology::lambda$registerCustomChrono$7());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2, run, $Object*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3 : public $Function {
	$class(HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* p) override {
		 return $of(HijrahChronology::lambda$registerCustomChrono$3($cast($Path, p)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4 : public $Predicate {
	$class(HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* fn) override {
		 return HijrahChronology::lambda$registerCustomChrono$4($cast($String, fn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4, test, bool, Object$*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5 : public $Function {
	$class(HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* fn) override {
		 return $of(HijrahChronology::lambda$registerCustomChrono$5($cast($String, fn)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5, apply, $Object*, Object$*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6 : public $Consumer {
	$class(HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* idtype) override {
		HijrahChronology::lambda$registerCustomChrono$6($cast($String, idtype));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6, accept, void, Object$*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6::class$ = nullptr;

class HijrahChronology$$Lambda$lambda$static$0$7 : public $PrivilegedAction {
	$class(HijrahChronology$$Lambda$lambda$static$0$7, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(HijrahChronology::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HijrahChronology$$Lambda$lambda$static$0$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HijrahChronology$$Lambda$lambda$static$0$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HijrahChronology$$Lambda$lambda$static$0$7, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology$$Lambda$lambda$static$0$7, run, $Object*)},
	{}
};
$ClassInfo HijrahChronology$$Lambda$lambda$static$0$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.chrono.HijrahChronology$$Lambda$lambda$static$0$7",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* HijrahChronology$$Lambda$lambda$static$0$7::load$($String* name, bool initialize) {
	$loadClass(HijrahChronology$$Lambda$lambda$static$0$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HijrahChronology$$Lambda$lambda$static$0$7::class$ = nullptr;

$FieldInfo _HijrahChronology_FieldInfo_[] = {
	{"typeId", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(HijrahChronology, typeId)},
	{"calendarType", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(HijrahChronology, calendarType)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HijrahChronology, serialVersionUID)},
	{"INSTANCE", "Ljava/time/chrono/HijrahChronology;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(HijrahChronology, INSTANCE)},
	{"initComplete", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(HijrahChronology, initComplete)},
	{"hijrahEpochMonthStartDays", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, hijrahEpochMonthStartDays)},
	{"minEpochDay", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, minEpochDay)},
	{"maxEpochDay", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, maxEpochDay)},
	{"hijrahStartEpochMonth", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, hijrahStartEpochMonth)},
	{"minMonthLength", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, minMonthLength)},
	{"maxMonthLength", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, maxMonthLength)},
	{"minYearLength", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, minYearLength)},
	{"maxYearLength", "I", nullptr, $PRIVATE | $TRANSIENT, $field(HijrahChronology, maxYearLength)},
	{"RESOURCE_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, RESOURCE_PREFIX)},
	{"RESOURCE_SUFFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, RESOURCE_SUFFIX)},
	{"KEY_ID", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, KEY_ID)},
	{"KEY_TYPE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, KEY_TYPE)},
	{"KEY_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, KEY_VERSION)},
	{"KEY_ISO_START", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, KEY_ISO_START)},
	{"CONF_PATH", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HijrahChronology, CONF_PATH)},
	{}
};

$MethodInfo _HijrahChronology_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(HijrahChronology, init$, void, $String*, $String*)},
	{"checkCalendarInit", "()V", nullptr, $PRIVATE, $method(HijrahChronology, checkCalendarInit, void)},
	{"checkValidDayOfYear", "(I)V", nullptr, 0, $method(HijrahChronology, checkValidDayOfYear, void, int32_t)},
	{"checkValidMonth", "(I)V", nullptr, 0, $method(HijrahChronology, checkValidMonth, void, int32_t)},
	{"checkValidYear", "(J)I", nullptr, 0, $method(HijrahChronology, checkValidYear, int32_t, int64_t)},
	{"createEpochMonths", "(IIILjava/util/Map;)[I", "(IIILjava/util/Map<Ljava/lang/Integer;[I>;)[I", $PRIVATE, $method(HijrahChronology, createEpochMonths, $ints*, int32_t, int32_t, int32_t, $Map*)},
	{"date", "(Ljava/time/chrono/Era;III)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, date, $ChronoLocalDate*, $Era*, int32_t, int32_t, int32_t)},
	{"date", "(III)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, date, $ChronoLocalDate*, int32_t, int32_t, int32_t)},
	{"date", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, date, $ChronoLocalDate*, $TemporalAccessor*)},
	{"dateEpochDay", "(J)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, dateEpochDay, $ChronoLocalDate*, int64_t)},
	{"dateNow", "()Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, dateNow, $ChronoLocalDate*)},
	{"dateNow", "(Ljava/time/ZoneId;)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, dateNow, $ChronoLocalDate*, $ZoneId*)},
	{"dateNow", "(Ljava/time/Clock;)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, dateNow, $ChronoLocalDate*, $Clock*)},
	{"dateYearDay", "(Ljava/time/chrono/Era;II)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, dateYearDay, $ChronoLocalDate*, $Era*, int32_t, int32_t)},
	{"dateYearDay", "(II)Ljava/time/chrono/HijrahDate;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, dateYearDay, $ChronoLocalDate*, int32_t, int32_t)},
	{"epochDayToEpochMonth", "(I)I", nullptr, $PRIVATE, $method(HijrahChronology, epochDayToEpochMonth, int32_t, int32_t)},
	{"epochMonthLength", "(I)I", nullptr, $PRIVATE, $method(HijrahChronology, epochMonthLength, int32_t, int32_t)},
	{"epochMonthToEpochDay", "(I)I", nullptr, $PRIVATE, $method(HijrahChronology, epochMonthToEpochDay, int32_t, int32_t)},
	{"epochMonthToMonth", "(I)I", nullptr, $PRIVATE, $method(HijrahChronology, epochMonthToMonth, int32_t, int32_t)},
	{"epochMonthToYear", "(I)I", nullptr, $PRIVATE, $method(HijrahChronology, epochMonthToYear, int32_t, int32_t)},
	{"eraOf", "(I)Ljava/time/chrono/HijrahEra;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, eraOf, $Era*, int32_t)},
	{"eras", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/chrono/Era;>;", $PUBLIC, $virtualMethod(HijrahChronology, eras, $List*)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, getCalendarType, $String*)},
	{"getDayOfYear", "(II)I", nullptr, 0, $method(HijrahChronology, getDayOfYear, int32_t, int32_t, int32_t)},
	{"getEpochDay", "(III)J", nullptr, 0, $method(HijrahChronology, getEpochDay, int64_t, int32_t, int32_t, int32_t)},
	{"getHijrahDateInfo", "(I)[I", nullptr, 0, $method(HijrahChronology, getHijrahDateInfo, $ints*, int32_t)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, getId, $String*)},
	{"getMaximumDayOfYear", "()I", nullptr, 0, $method(HijrahChronology, getMaximumDayOfYear, int32_t)},
	{"getMaximumMonthLength", "()I", nullptr, 0, $method(HijrahChronology, getMaximumMonthLength, int32_t)},
	{"getMaximumYear", "()I", nullptr, 0, $method(HijrahChronology, getMaximumYear, int32_t)},
	{"getMinimumMonthLength", "()I", nullptr, 0, $method(HijrahChronology, getMinimumMonthLength, int32_t)},
	{"getMinimumYear", "()I", nullptr, 0, $method(HijrahChronology, getMinimumYear, int32_t)},
	{"getMonthLength", "(II)I", nullptr, 0, $method(HijrahChronology, getMonthLength, int32_t, int32_t, int32_t)},
	{"getSmallestMaximumDayOfYear", "()I", nullptr, 0, $method(HijrahChronology, getSmallestMaximumDayOfYear, int32_t)},
	{"getYearLength", "(I)I", nullptr, 0, $method(HijrahChronology, getYearLength, int32_t, int32_t)},
	{"isLeapYear", "(J)Z", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, isLeapYear, bool, int64_t)},
	{"lambda$readConfigProperties$1", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$readConfigProperties$1, $InputStream*, $String*)},
	{"lambda$readConfigProperties$2", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$readConfigProperties$2, $InputStream*, $String*)},
	{"lambda$registerCustomChrono$3", "(Ljava/nio/file/Path;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$registerCustomChrono$3, $String*, $Path*)},
	{"lambda$registerCustomChrono$4", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$registerCustomChrono$4, bool, $String*)},
	{"lambda$registerCustomChrono$5", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$registerCustomChrono$5, $String*, $String*)},
	{"lambda$registerCustomChrono$6", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$registerCustomChrono$6, void, $String*)},
	{"lambda$registerCustomChrono$7", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$registerCustomChrono$7, $Void*)},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HijrahChronology, lambda$static$0, $String*)},
	{"loadCalendarData", "()V", nullptr, $PRIVATE, $method(HijrahChronology, loadCalendarData, void)},
	{"localDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/HijrahDate;>;", $PUBLIC, $virtualMethod(HijrahChronology, localDateTime, $ChronoLocalDateTime*, $TemporalAccessor*)},
	{"parseMonths", "(Ljava/lang/String;)[I", nullptr, $PRIVATE, $method(HijrahChronology, parseMonths, $ints*, $String*)},
	{"parseYMD", "(Ljava/lang/String;)[I", nullptr, $PRIVATE, $method(HijrahChronology, parseYMD, $ints*, $String*)},
	{"prolepticYear", "(Ljava/time/chrono/Era;I)I", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, prolepticYear, int32_t, $Era*, int32_t)},
	{"range", "(Ljava/time/temporal/ChronoField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(HijrahChronology, range, $ValueRange*, $ChronoField*)},
	{"readConfigProperties", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/Properties;", nullptr, $PRIVATE | $STATIC, $staticMethod(HijrahChronology, readConfigProperties, $Properties*, $String*, $String*), "java.lang.Exception"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(HijrahChronology, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"registerCustomChrono", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(HijrahChronology, registerCustomChrono, void)},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/HijrahDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/HijrahDate;", $PUBLIC, $virtualMethod(HijrahChronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(HijrahChronology, writeReplace, $Object*)},
	{"yearMonthToDayOfYear", "(II)I", nullptr, $PRIVATE, $method(HijrahChronology, yearMonthToDayOfYear, int32_t, int32_t, int32_t)},
	{"yearToEpochMonth", "(I)I", nullptr, $PRIVATE, $method(HijrahChronology, yearToEpochMonth, int32_t, int32_t)},
	{"zonedDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/HijrahDate;>;", $PUBLIC, $virtualMethod(HijrahChronology, zonedDateTime, $ChronoZonedDateTime*, $TemporalAccessor*)},
	{"zonedDateTime", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/HijrahDate;>;", $PUBLIC, $virtualMethod(HijrahChronology, zonedDateTime, $ChronoZonedDateTime*, $Instant*, $ZoneId*)},
	{}
};

$InnerClassInfo _HijrahChronology_InnerClassesInfo_[] = {
	{"java.time.chrono.HijrahChronology$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _HijrahChronology_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.HijrahChronology",
	"java.time.chrono.AbstractChronology",
	"java.io.Serializable",
	_HijrahChronology_FieldInfo_,
	_HijrahChronology_MethodInfo_,
	nullptr,
	nullptr,
	_HijrahChronology_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.chrono.HijrahChronology$1"
};

$Object* allocate$HijrahChronology($Class* clazz) {
	return $of($alloc(HijrahChronology));
}

bool HijrahChronology::equals(Object$* obj) {
	 return this->$AbstractChronology::equals(obj);
}

int32_t HijrahChronology::hashCode() {
	 return this->$AbstractChronology::hashCode();
}

$String* HijrahChronology::toString() {
	 return this->$AbstractChronology::toString();
}

$Object* HijrahChronology::clone() {
	 return this->$AbstractChronology::clone();
}

void HijrahChronology::finalize() {
	this->$AbstractChronology::finalize();
}

HijrahChronology* HijrahChronology::INSTANCE = nullptr;
$String* HijrahChronology::RESOURCE_PREFIX = nullptr;
$String* HijrahChronology::RESOURCE_SUFFIX = nullptr;
$String* HijrahChronology::KEY_ID = nullptr;
$String* HijrahChronology::KEY_TYPE = nullptr;
$String* HijrahChronology::KEY_VERSION = nullptr;
$String* HijrahChronology::KEY_ISO_START = nullptr;
$Path* HijrahChronology::CONF_PATH = nullptr;

void HijrahChronology::init$($String* id, $String* calType) {
	$AbstractChronology::init$();
	if ($nc(id)->isEmpty()) {
		$throwNew($IllegalArgumentException, "calendar id is empty"_s);
	}
	if ($nc(calType)->isEmpty()) {
		$throwNew($IllegalArgumentException, "calendar typeId is empty"_s);
	}
	$set(this, typeId, id);
	$set(this, calendarType, calType);
}

void HijrahChronology::checkCalendarInit() {
	if (this->initComplete == false) {
		loadCalendarData();
		this->initComplete = true;
	}
}

$String* HijrahChronology::getId() {
	return this->typeId;
}

$String* HijrahChronology::getCalendarType() {
	return this->calendarType;
}

$ChronoLocalDate* HijrahChronology::date($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	return date(prolepticYear(era, yearOfEra), month, dayOfMonth);
}

$ChronoLocalDate* HijrahChronology::date(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	return $HijrahDate::of(this, prolepticYear, month, dayOfMonth);
}

$ChronoLocalDate* HijrahChronology::dateYearDay($Era* era, int32_t yearOfEra, int32_t dayOfYear) {
	return dateYearDay(prolepticYear(era, yearOfEra), dayOfYear);
}

$ChronoLocalDate* HijrahChronology::dateYearDay(int32_t prolepticYear, int32_t dayOfYear) {
	$useLocalCurrentObjectStackCache();
	$var($HijrahDate, date, $HijrahDate::of(this, prolepticYear, 1, 1));
	if (dayOfYear > $nc(date)->lengthOfYear()) {
		$throwNew($DateTimeException, $$str({"Invalid dayOfYear: "_s, $$str(dayOfYear)}));
	}
	return $nc(date)->plusDays(dayOfYear - 1);
}

$ChronoLocalDate* HijrahChronology::dateEpochDay(int64_t epochDay) {
	return $HijrahDate::ofEpochDay(this, epochDay);
}

$ChronoLocalDate* HijrahChronology::dateNow() {
	return dateNow($($Clock::systemDefaultZone()));
}

$ChronoLocalDate* HijrahChronology::dateNow($ZoneId* zone) {
	return dateNow($($Clock::system(zone)));
}

$ChronoLocalDate* HijrahChronology::dateNow($Clock* clock) {
	return date($($LocalDate::now(clock)));
}

$ChronoLocalDate* HijrahChronology::date($TemporalAccessor* temporal) {
	if ($instanceOf($HijrahDate, temporal)) {
		return $cast($HijrahDate, temporal);
	}
	$init($ChronoField);
	return $HijrahDate::ofEpochDay(this, $nc(temporal)->getLong($ChronoField::EPOCH_DAY));
}

$ChronoLocalDateTime* HijrahChronology::localDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::localDateTime(temporal);
}

$ChronoZonedDateTime* HijrahChronology::zonedDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::zonedDateTime(temporal);
}

$ChronoZonedDateTime* HijrahChronology::zonedDateTime($Instant* instant, $ZoneId* zone) {
	return $AbstractChronology::zonedDateTime(instant, zone);
}

bool HijrahChronology::isLeapYear(int64_t prolepticYear) {
	checkCalendarInit();
	bool var$0 = prolepticYear < getMinimumYear();
	if (var$0 || prolepticYear > getMaximumYear()) {
		return false;
	}
	int32_t len = getYearLength((int32_t)prolepticYear);
	return (len > 354);
}

int32_t HijrahChronology::prolepticYear($Era* era, int32_t yearOfEra) {
	if (!($instanceOf($HijrahEra, era))) {
		$throwNew($ClassCastException, "Era must be HijrahEra"_s);
	}
	return yearOfEra;
}

$Era* HijrahChronology::eraOf(int32_t eraValue) {
	switch (eraValue) {
	case 1:
		{
			$init($HijrahEra);
			return $HijrahEra::AH;
		}
	default:
		{
			$throwNew($DateTimeException, "invalid Hijrah era"_s);
		}
	}
}

$List* HijrahChronology::eras() {
	return $List::of($($HijrahEra::values()));
}

$ValueRange* HijrahChronology::range($ChronoField* field) {
	checkCalendarInit();
	if ($instanceOf($ChronoField, field)) {
		$ChronoField* f = field;
		$init($HijrahChronology$1);
		switch ($nc($HijrahChronology$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((f))->ordinal())) {
		case 1:
			{
				int64_t var$0 = (int64_t)getMinimumMonthLength();
				return $ValueRange::of(1, 1, var$0, getMaximumMonthLength());
			}
		case 2:
			{
				return $ValueRange::of(1, getMaximumDayOfYear());
			}
		case 3:
			{
				return $ValueRange::of(1, 5);
			}
		case 4:
			{}
		case 5:
			{
				int64_t var$1 = (int64_t)getMinimumYear();
				return $ValueRange::of(var$1, getMaximumYear());
			}
		case 6:
			{
				return $ValueRange::of(1, 1);
			}
		default:
			{
				return $nc(field)->range();
			}
		}
	}
	return $nc(field)->range();
}

$ChronoLocalDate* HijrahChronology::resolveDate($Map* fieldValues, $ResolverStyle* resolverStyle) {
	return $cast($HijrahDate, $AbstractChronology::resolveDate(fieldValues, resolverStyle));
}

int32_t HijrahChronology::checkValidYear(int64_t prolepticYear) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = prolepticYear < getMinimumYear();
	if (var$0 || prolepticYear > getMaximumYear()) {
		$throwNew($DateTimeException, $$str({"Invalid Hijrah year: "_s, $$str(prolepticYear)}));
	}
	return (int32_t)prolepticYear;
}

void HijrahChronology::checkValidDayOfYear(int32_t dayOfYear) {
	$useLocalCurrentObjectStackCache();
	if (dayOfYear < 1 || dayOfYear > getMaximumDayOfYear()) {
		$throwNew($DateTimeException, $$str({"Invalid Hijrah day of year: "_s, $$str(dayOfYear)}));
	}
}

void HijrahChronology::checkValidMonth(int32_t month) {
	$useLocalCurrentObjectStackCache();
	if (month < 1 || month > 12) {
		$throwNew($DateTimeException, $$str({"Invalid Hijrah month: "_s, $$str(month)}));
	}
}

$ints* HijrahChronology::getHijrahDateInfo(int32_t epochDay) {
	checkCalendarInit();
	if (epochDay < this->minEpochDay || epochDay >= this->maxEpochDay) {
		$throwNew($DateTimeException, "Hijrah date out of range"_s);
	}
	int32_t epochMonth = epochDayToEpochMonth(epochDay);
	int32_t year = epochMonthToYear(epochMonth);
	int32_t month = epochMonthToMonth(epochMonth);
	int32_t day1 = epochMonthToEpochDay(epochMonth);
	int32_t date = epochDay - day1;
	$var($ints, dateInfo, $new($ints, 3));
	dateInfo->set(0, year);
	dateInfo->set(1, month + 1);
	dateInfo->set(2, date + 1);
	return dateInfo;
}

int64_t HijrahChronology::getEpochDay(int32_t prolepticYear, int32_t monthOfYear, int32_t dayOfMonth) {
	$useLocalCurrentObjectStackCache();
	checkCalendarInit();
	checkValidMonth(monthOfYear);
	int32_t epochMonth = yearToEpochMonth(prolepticYear) + (monthOfYear - 1);
	if (epochMonth < 0 || epochMonth >= $nc(this->hijrahEpochMonthStartDays)->length) {
		$throwNew($DateTimeException, $$str({"Invalid Hijrah date, year: "_s, $$str(prolepticYear), ", month: "_s, $$str(monthOfYear)}));
	}
	if (dayOfMonth < 1 || dayOfMonth > getMonthLength(prolepticYear, monthOfYear)) {
		$throwNew($DateTimeException, $$str({"Invalid Hijrah day of month: "_s, $$str(dayOfMonth)}));
	}
	return epochMonthToEpochDay(epochMonth) + (dayOfMonth - 1);
}

int32_t HijrahChronology::getDayOfYear(int32_t prolepticYear, int32_t month) {
	return yearMonthToDayOfYear(prolepticYear, (month - 1));
}

int32_t HijrahChronology::getMonthLength(int32_t prolepticYear, int32_t monthOfYear) {
	$useLocalCurrentObjectStackCache();
	int32_t epochMonth = yearToEpochMonth(prolepticYear) + (monthOfYear - 1);
	if (epochMonth < 0 || epochMonth >= $nc(this->hijrahEpochMonthStartDays)->length) {
		$throwNew($DateTimeException, $$str({"Invalid Hijrah date, year: "_s, $$str(prolepticYear), ", month: "_s, $$str(monthOfYear)}));
	}
	return epochMonthLength(epochMonth);
}

int32_t HijrahChronology::getYearLength(int32_t prolepticYear) {
	return yearMonthToDayOfYear(prolepticYear, 12);
}

int32_t HijrahChronology::getMinimumYear() {
	return epochMonthToYear(0);
}

int32_t HijrahChronology::getMaximumYear() {
	return epochMonthToYear($nc(this->hijrahEpochMonthStartDays)->length - 1) - 1;
}

int32_t HijrahChronology::getMaximumMonthLength() {
	return this->maxMonthLength;
}

int32_t HijrahChronology::getMinimumMonthLength() {
	return this->minMonthLength;
}

int32_t HijrahChronology::getMaximumDayOfYear() {
	return this->maxYearLength;
}

int32_t HijrahChronology::getSmallestMaximumDayOfYear() {
	return this->minYearLength;
}

int32_t HijrahChronology::epochDayToEpochMonth(int32_t epochDay) {
	int32_t ndx = $Arrays::binarySearch(this->hijrahEpochMonthStartDays, epochDay);
	if (ndx < 0) {
		ndx = -ndx - 2;
	}
	return ndx;
}

int32_t HijrahChronology::epochMonthToYear(int32_t epochMonth) {
	return (epochMonth + this->hijrahStartEpochMonth) / 12;
}

int32_t HijrahChronology::yearToEpochMonth(int32_t year) {
	return (year * 12) - this->hijrahStartEpochMonth;
}

int32_t HijrahChronology::epochMonthToMonth(int32_t epochMonth) {
	return (epochMonth + this->hijrahStartEpochMonth) % 12;
}

int32_t HijrahChronology::epochMonthToEpochDay(int32_t epochMonth) {
	return $nc(this->hijrahEpochMonthStartDays)->get(epochMonth);
}

int32_t HijrahChronology::yearMonthToDayOfYear(int32_t prolepticYear, int32_t month) {
	int32_t epochMonthFirst = yearToEpochMonth(prolepticYear);
	int32_t var$0 = epochMonthToEpochDay(epochMonthFirst + month);
	return var$0 - epochMonthToEpochDay(epochMonthFirst);
}

int32_t HijrahChronology::epochMonthLength(int32_t epochMonth) {
	return $nc(this->hijrahEpochMonthStartDays)->get(epochMonth + 1) - $nc(this->hijrahEpochMonthStartDays)->get(epochMonth);
}

$Properties* HijrahChronology::readConfigProperties($String* chronologyId, $String* calendarType) {
	$init(HijrahChronology);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, resourceName, $str({HijrahChronology::RESOURCE_PREFIX, chronologyId, "_"_s, calendarType, HijrahChronology::RESOURCE_SUFFIX}));
	$var($PrivilegedAction, getResourceAction, $nc(calendarType)->equals("islamic-umalqura"_s) ? static_cast<$PrivilegedAction*>($new(HijrahChronology$$Lambda$lambda$readConfigProperties$1, resourceName)) : static_cast<$PrivilegedAction*>($new(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1, resourceName)));
	$var($FilePermission, perm1, $new($FilePermission, "<<ALL FILES>>"_s, "read"_s));
	$var($RuntimePermission, perm2, $new($RuntimePermission, "accessSystemModules"_s));
	{
		$var($InputStream, is, $cast($InputStream, $AccessController::doPrivileged(getResourceAction, ($AccessControlContext*)nullptr, $$new($PermissionArray, {
			static_cast<$Permission*>(perm1),
			static_cast<$Permission*>(perm2)
		}))));
		{
			$var($Throwable, var$0, nullptr);
			$var($Properties, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					if (is == nullptr) {
						$throwNew($RuntimeException, $$str({"Hijrah calendar resource not found: "_s, resourceName}));
					}
					$var($Properties, props, $new($Properties));
					props->load(is);
					$assign(var$2, props);
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					if (is != nullptr) {
						try {
							is->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (is != nullptr) {
					is->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

void HijrahChronology::loadCalendarData() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Properties, props, readConfigProperties(this->typeId, this->calendarType));
		$var($Map, years, $new($HashMap));
		int32_t minYear = $Integer::MAX_VALUE;
		int32_t maxYear = $Integer::MIN_VALUE;
		$var($String, id, nullptr);
		$var($String, type, nullptr);
		$var($String, version, nullptr);
		int32_t isoStart = 0;
		{
			$var($Iterator, i$, $nc($($nc(props)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($String, key, $cast($String, $nc(entry)->getKey()));
					{
						$var($String, s31619$, key);
						int32_t tmp31619$ = -1;
						switch ($nc(s31619$)->hashCode()) {
						case 3355:
							{
								if (s31619$->equals("id"_s)) {
									tmp31619$ = 0;
								}
								break;
							}
						case 0x00368F3A:
							{
								if (s31619$->equals("type"_s)) {
									tmp31619$ = 1;
								}
								break;
							}
						case 0x14F51CD8:
							{
								if (s31619$->equals("version"_s)) {
									tmp31619$ = 2;
								}
								break;
							}
						case (int32_t)0xBD61391A:
							{
								if (s31619$->equals("iso-start"_s)) {
									tmp31619$ = 3;
								}
								break;
							}
						}
						switch (tmp31619$) {
						case 0:
							{
								$assign(id, $cast($String, entry->getValue()));
								break;
							}
						case 1:
							{
								$assign(type, $cast($String, entry->getValue()));
								break;
							}
						case 2:
							{
								$assign(version, $cast($String, entry->getValue()));
								break;
							}
						case 3:
							{
								{
									$var($ints, ymd, parseYMD($cast($String, $(entry->getValue()))));
									isoStart = (int32_t)$nc($($LocalDate::of($nc(ymd)->get(0), ymd->get(1), ymd->get(2))))->toEpochDay();
									break;
								}
							}
						default:
							{
								try {
									int32_t year = $Integer::parseInt(key);
									$var($ints, months, parseMonths($cast($String, $(entry->getValue()))));
									years->put($($Integer::valueOf(year)), months);
									maxYear = $Math::max(maxYear, year);
									minYear = $Math::min(minYear, year);
								} catch ($NumberFormatException& nfe) {
									$throwNew($IllegalArgumentException, $$str({"bad key: "_s, key}));
								}
							}
						}
					}
				}
			}
		}
		if (!$nc($(getId()))->equals(id)) {
			$throwNew($IllegalArgumentException, $$str({"Configuration is for a different calendar: "_s, id}));
		}
		if (!$nc($(getCalendarType()))->equals(type)) {
			$throwNew($IllegalArgumentException, $$str({"Configuration is for a different calendar type: "_s, type}));
		}
		if (version == nullptr || $nc(version)->isEmpty()) {
			$throwNew($IllegalArgumentException, "Configuration does not contain a version"_s);
		}
		if (isoStart == 0) {
			$throwNew($IllegalArgumentException, "Configuration does not contain a ISO start date"_s);
		}
		this->hijrahStartEpochMonth = minYear * 12;
		this->minEpochDay = isoStart;
		$set(this, hijrahEpochMonthStartDays, createEpochMonths(this->minEpochDay, minYear, maxYear, years));
		this->maxEpochDay = $nc(this->hijrahEpochMonthStartDays)->get($nc(this->hijrahEpochMonthStartDays)->length - 1);
		for (int32_t year = minYear; year < maxYear; ++year) {
			int32_t length = getYearLength(year);
			this->minYearLength = $Math::min(this->minYearLength, length);
			this->maxYearLength = $Math::max(this->maxYearLength, length);
		}
	} catch ($Exception& ex) {
		$var($PlatformLogger, logger, $PlatformLogger::getLogger("java.time.chrono"_s));
		$nc(logger)->severe($$str({"Unable to initialize Hijrah calendar proxy: "_s, this->typeId}), static_cast<$Throwable*>(ex));
		$throwNew($DateTimeException, $$str({"Unable to initialize HijrahCalendar: "_s, this->typeId}), ex);
	}
}

$ints* HijrahChronology::createEpochMonths(int32_t epochDay, int32_t minYear, int32_t maxYear, $Map* years) {
	$useLocalCurrentObjectStackCache();
	int32_t numMonths = (maxYear - minYear + 1) * 12 + 1;
	int32_t epochMonth = 0;
	$var($ints, epochMonths, $new($ints, numMonths));
	this->minMonthLength = $Integer::MAX_VALUE;
	this->maxMonthLength = $Integer::MIN_VALUE;
	for (int32_t year = minYear; year <= maxYear; ++year) {
		$var($ints, months, $cast($ints, $nc(years)->get($($Integer::valueOf(year)))));
		for (int32_t month = 0; month < 12; ++month) {
			int32_t length = $nc(months)->get(month);
			epochMonths->set(epochMonth++, epochDay);
			if (length < 29 || length > 32) {
				$throwNew($IllegalArgumentException, $$str({"Invalid month length in year: "_s, $$str(minYear)}));
			}
			epochDay += length;
			this->minMonthLength = $Math::min(this->minMonthLength, length);
			this->maxMonthLength = $Math::max(this->maxMonthLength, length);
		}
	}
	epochMonths->set(epochMonth++, epochDay);
	if (epochMonth != epochMonths->length) {
		$throwNew($IllegalStateException, $$str({"Did not fill epochMonths exactly: ndx = "_s, $$str(epochMonth), " should be "_s, $$str(epochMonths->length)}));
	}
	return epochMonths;
}

$ints* HijrahChronology::parseMonths($String* line) {
	$useLocalCurrentObjectStackCache();
	$var($ints, months, $new($ints, 12));
	$var($StringArray, numbers, $nc(line)->split("\\s"_s));
	if (numbers->length != 12) {
		$throwNew($IllegalArgumentException, $$str({"wrong number of months on line: "_s, $($Arrays::toString(numbers)), "; count: "_s, $$str(numbers->length)}));
	}
	for (int32_t i = 0; i < 12; ++i) {
		try {
			months->set(i, $Integer::parseInt(numbers->get(i)));
		} catch ($NumberFormatException& nfe) {
			$throwNew($IllegalArgumentException, $$str({"bad key: "_s, numbers->get(i)}));
		}
	}
	return months;
}

$ints* HijrahChronology::parseYMD($String* string$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, string, string$renamed);
	$assign(string, $nc(string)->trim());
	try {
		bool var$0 = string->charAt(4) != u'-';
		if (var$0 || string->charAt(7) != u'-') {
			$throwNew($IllegalArgumentException, "date must be yyyy-MM-dd"_s);
		}
		$var($ints, ymd, $new($ints, 3));
		ymd->set(0, $Integer::parseInt(string, 0, 4, 10));
		ymd->set(1, $Integer::parseInt(string, 5, 7, 10));
		ymd->set(2, $Integer::parseInt(string, 8, 10, 10));
		return ymd;
	} catch ($NumberFormatException& ex) {
		$throwNew($IllegalArgumentException, "date must be yyyy-MM-dd"_s, ex);
	}
	$shouldNotReachHere();
}

void HijrahChronology::registerCustomChrono() {
	$init(HijrahChronology);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new(HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2)));
	$AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($FilePermission, "<<ALL FILES>>"_s, "read"_s))}));
}

$Object* HijrahChronology::writeReplace() {
	return $of($AbstractChronology::writeReplace());
}

void HijrahChronology::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

$Void* HijrahChronology::lambda$registerCustomChrono$7() {
	$init(HijrahChronology);
	$useLocalCurrentObjectStackCache();
	if ($Files::isDirectory(HijrahChronology::CONF_PATH, $$new($LinkOptionArray, 0))) {
		try {
			$nc($($nc($($nc($($nc($($Files::list(HijrahChronology::CONF_PATH)))->map(static_cast<$Function*>($$new(HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3)))))->filter(static_cast<$Predicate*>($$new(HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4)))))->map(static_cast<$Function*>($$new(HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5)))))->forEach(static_cast<$Consumer*>($$new(HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6)));
		} catch ($IOException& e) {
			$nc($($PlatformLogger::getLogger("java.time.chrono"_s)))->warning("Hijrah custom config init failed."_s, static_cast<$Throwable*>(e));
		}
	}
	return nullptr;
}

void HijrahChronology::lambda$registerCustomChrono$6($String* idtype) {
	$init(HijrahChronology);
	$useLocalCurrentObjectStackCache();
	int32_t delimiterPos = $nc(idtype)->indexOf((int32_t)u'_');
	if (delimiterPos > 1 && delimiterPos < idtype->length() - 1) {
		$var($String, var$0, idtype->substring(0, delimiterPos));
		$AbstractChronology::registerChrono($$new(HijrahChronology, var$0, $(idtype->substring(delimiterPos + 1))));
	} else {
		$nc($($PlatformLogger::getLogger("java.time.chrono"_s)))->warning($$str({"Hijrah custom config init failed.\'<id>_<type>\' name convention not followed: "_s, idtype}));
	}
}

$String* HijrahChronology::lambda$registerCustomChrono$5($String* fn) {
	$init(HijrahChronology);
	return $nc(fn)->replaceAll("(hijrah-config-|\\.properties)"_s, ""_s);
}

bool HijrahChronology::lambda$registerCustomChrono$4($String* fn) {
	$init(HijrahChronology);
	return $nc(fn)->matches("hijrah-config-[^\\.]+\\.properties"_s);
}

$String* HijrahChronology::lambda$registerCustomChrono$3($Path* p) {
	$init(HijrahChronology);
	return $nc($($nc(p)->getFileName()))->toString();
}

$InputStream* HijrahChronology::lambda$readConfigProperties$2($String* resourceName) {
	$init(HijrahChronology);
	$useLocalCurrentObjectStackCache();
	try {
		$init($StandardOpenOption);
		return $Files::newInputStream($($nc(HijrahChronology::CONF_PATH)->resolve(resourceName)), $$new($OpenOptionArray, {static_cast<$OpenOption*>($StandardOpenOption::READ)}));
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

$InputStream* HijrahChronology::lambda$readConfigProperties$1($String* resourceName) {
	$init(HijrahChronology);
	$beforeCallerSensitive();
	return HijrahChronology::class$->getResourceAsStream(resourceName);
}

$String* HijrahChronology::lambda$static$0() {
	$init(HijrahChronology);
	return $System::getProperty("java.home"_s);
}

void clinit$HijrahChronology($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(HijrahChronology::RESOURCE_PREFIX, "hijrah-config-"_s);
	$assignStatic(HijrahChronology::RESOURCE_SUFFIX, ".properties"_s);
	$assignStatic(HijrahChronology::KEY_ID, "id"_s);
	$assignStatic(HijrahChronology::KEY_TYPE, "type"_s);
	$assignStatic(HijrahChronology::KEY_VERSION, "version"_s);
	$assignStatic(HijrahChronology::KEY_ISO_START, "iso-start"_s);
	$beforeCallerSensitive();
	{
		$assignStatic(HijrahChronology::INSTANCE, $new(HijrahChronology, "Hijrah-umalqura"_s, "islamic-umalqura"_s));
		$AbstractChronology::registerChrono(HijrahChronology::INSTANCE, "Hijrah"_s);
		$AbstractChronology::registerChrono(HijrahChronology::INSTANCE, "islamic"_s);
		$assignStatic(HijrahChronology::CONF_PATH, $Path::of($cast($String, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(HijrahChronology$$Lambda$lambda$static$0$7))))), $$new($StringArray, {
			"conf"_s,
			"chronology"_s
		})));
		HijrahChronology::registerCustomChrono();
	}
}

HijrahChronology::HijrahChronology() {
}

$Class* HijrahChronology::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HijrahChronology$$Lambda$lambda$readConfigProperties$1::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$readConfigProperties$1::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$readConfigProperties$2$1::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$registerCustomChrono$7$2::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$registerCustomChrono$3$3::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$registerCustomChrono$4$4::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$registerCustomChrono$5$5::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$registerCustomChrono$6$6::load$(name, initialize);
		}
		if (name->equals(HijrahChronology$$Lambda$lambda$static$0$7::classInfo$.name)) {
			return HijrahChronology$$Lambda$lambda$static$0$7::load$(name, initialize);
		}
	}
	$loadClass(HijrahChronology, name, initialize, &_HijrahChronology_ClassInfo_, clinit$HijrahChronology, allocate$HijrahChronology);
	return class$;
}

$Class* HijrahChronology::class$ = nullptr;

		} // chrono
	} // time
} // java