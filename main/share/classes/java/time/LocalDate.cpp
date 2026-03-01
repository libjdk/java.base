#include <java/time/LocalDate.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/DayOfWeek.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate$1.h>
#include <java/time/LocalDateTime.h>
#include <java/time/LocalTime.h>
#include <java/time/Month.h>
#include <java/time/OffsetDateTime.h>
#include <java/time/OffsetTime.h>
#include <java/time/Period.h>
#include <java/time/Ser.h>
#include <java/time/Year.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoPeriod.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/chrono/IsoEra.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/time/zone/ZoneOffsetTransition.h>
#include <java/time/zone/ZoneRules.h>
#include <java/util/Objects.h>
#include <java/util/function/LongFunction.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef ALIGNED_DAY_OF_WEEK_IN_MONTH
#undef ALIGNED_DAY_OF_WEEK_IN_YEAR
#undef ALIGNED_WEEK_OF_MONTH
#undef ALIGNED_WEEK_OF_YEAR
#undef BCE
#undef CE
#undef DAYS_PER_CYCLE
#undef DAY_OF_MONTH
#undef DAY_OF_YEAR
#undef EPOCH
#undef EPOCH_DAY
#undef ERA
#undef FEBRUARY
#undef INSTANCE
#undef ISO_LOCAL_DATE
#undef LOCAL_DATE_TYPE
#undef MAX
#undef MAX_VALUE
#undef MIDNIGHT
#undef MIN
#undef MIN_VALUE
#undef MONTH_OF_YEAR
#undef PROLEPTIC_MONTH
#undef YEAR

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $DayOfWeek = ::java::time::DayOfWeek;
using $Instant = ::java::time::Instant;
using $LocalDate$1 = ::java::time::LocalDate$1;
using $LocalDateTime = ::java::time::LocalDateTime;
using $LocalTime = ::java::time::LocalTime;
using $Month = ::java::time::Month;
using $OffsetDateTime = ::java::time::OffsetDateTime;
using $OffsetTime = ::java::time::OffsetTime;
using $Period = ::java::time::Period;
using $Ser = ::java::time::Ser;
using $Year = ::java::time::Year;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoPeriod = ::java::time::chrono::ChronoPeriod;
using $Chronology = ::java::time::chrono::Chronology;
using $Era = ::java::time::chrono::Era;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $IsoEra = ::java::time::chrono::IsoEra;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAdjuster = ::java::time::temporal::TemporalAdjuster;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $ZoneOffsetTransition = ::java::time::zone::ZoneOffsetTransition;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $Objects = ::java::util::Objects;
using $LongFunction = ::java::util::function::LongFunction;
using $LongStream = ::java::util::stream::LongStream;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace time {

class LocalDate$$Lambda$from : public $TemporalQuery {
	$class(LocalDate$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(LocalDate::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocalDate$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LocalDate$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LocalDate$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocalDate$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo LocalDate$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.LocalDate$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* LocalDate$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(LocalDate$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocalDate$$Lambda$from::class$ = nullptr;

class LocalDate$$Lambda$ofEpochDay$1 : public $LongFunction {
	$class(LocalDate$$Lambda$ofEpochDay$1, $NO_CLASS_INIT, $LongFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int64_t epochDay) override {
		 return $of(LocalDate::ofEpochDay(epochDay));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocalDate$$Lambda$ofEpochDay$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LocalDate$$Lambda$ofEpochDay$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LocalDate$$Lambda$ofEpochDay$1, init$, void)},
	{"apply", "(J)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocalDate$$Lambda$ofEpochDay$1, apply, $Object*, int64_t)},
	{}
};
$ClassInfo LocalDate$$Lambda$ofEpochDay$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.LocalDate$$Lambda$ofEpochDay$1",
	"java.lang.Object",
	"java.util.function.LongFunction",
	nullptr,
	methodInfos
};
$Class* LocalDate$$Lambda$ofEpochDay$1::load$($String* name, bool initialize) {
	$loadClass(LocalDate$$Lambda$ofEpochDay$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocalDate$$Lambda$ofEpochDay$1::class$ = nullptr;

class LocalDate$$Lambda$lambda$datesUntil$0$2 : public $LongFunction {
	$class(LocalDate$$Lambda$lambda$datesUntil$0$2, $NO_CLASS_INIT, $LongFunction)
public:
	void init$(int64_t start, int64_t days) {
		this->start = start;
		this->days = days;
	}
	virtual $Object* apply(int64_t n) override {
		 return $of(LocalDate::lambda$datesUntil$0(start, days, n));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocalDate$$Lambda$lambda$datesUntil$0$2>());
	}
	int64_t start = 0;
	int64_t days = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LocalDate$$Lambda$lambda$datesUntil$0$2::fieldInfos[3] = {
	{"start", "J", nullptr, $PUBLIC, $field(LocalDate$$Lambda$lambda$datesUntil$0$2, start)},
	{"days", "J", nullptr, $PUBLIC, $field(LocalDate$$Lambda$lambda$datesUntil$0$2, days)},
	{}
};
$MethodInfo LocalDate$$Lambda$lambda$datesUntil$0$2::methodInfos[3] = {
	{"<init>", "(JJ)V", nullptr, $PUBLIC, $method(LocalDate$$Lambda$lambda$datesUntil$0$2, init$, void, int64_t, int64_t)},
	{"apply", "(J)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocalDate$$Lambda$lambda$datesUntil$0$2, apply, $Object*, int64_t)},
	{}
};
$ClassInfo LocalDate$$Lambda$lambda$datesUntil$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.LocalDate$$Lambda$lambda$datesUntil$0$2",
	"java.lang.Object",
	"java.util.function.LongFunction",
	fieldInfos,
	methodInfos
};
$Class* LocalDate$$Lambda$lambda$datesUntil$0$2::load$($String* name, bool initialize) {
	$loadClass(LocalDate$$Lambda$lambda$datesUntil$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocalDate$$Lambda$lambda$datesUntil$0$2::class$ = nullptr;

class LocalDate$$Lambda$lambda$datesUntil$1$3 : public $LongFunction {
	$class(LocalDate$$Lambda$lambda$datesUntil$1$3, $NO_CLASS_INIT, $LongFunction)
public:
	void init$(LocalDate* inst, int64_t months, int64_t days) {
		$set(this, inst$, inst);
		this->months = months;
		this->days = days;
	}
	virtual $Object* apply(int64_t n) override {
		 return $of($nc(inst$)->lambda$datesUntil$1(months, days, n));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocalDate$$Lambda$lambda$datesUntil$1$3>());
	}
	LocalDate* inst$ = nullptr;
	int64_t months = 0;
	int64_t days = 0;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LocalDate$$Lambda$lambda$datesUntil$1$3::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LocalDate$$Lambda$lambda$datesUntil$1$3, inst$)},
	{"months", "J", nullptr, $PUBLIC, $field(LocalDate$$Lambda$lambda$datesUntil$1$3, months)},
	{"days", "J", nullptr, $PUBLIC, $field(LocalDate$$Lambda$lambda$datesUntil$1$3, days)},
	{}
};
$MethodInfo LocalDate$$Lambda$lambda$datesUntil$1$3::methodInfos[3] = {
	{"<init>", "(Ljava/time/LocalDate;JJ)V", nullptr, $PUBLIC, $method(LocalDate$$Lambda$lambda$datesUntil$1$3, init$, void, LocalDate*, int64_t, int64_t)},
	{"apply", "(J)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocalDate$$Lambda$lambda$datesUntil$1$3, apply, $Object*, int64_t)},
	{}
};
$ClassInfo LocalDate$$Lambda$lambda$datesUntil$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.LocalDate$$Lambda$lambda$datesUntil$1$3",
	"java.lang.Object",
	"java.util.function.LongFunction",
	fieldInfos,
	methodInfos
};
$Class* LocalDate$$Lambda$lambda$datesUntil$1$3::load$($String* name, bool initialize) {
	$loadClass(LocalDate$$Lambda$lambda$datesUntil$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocalDate$$Lambda$lambda$datesUntil$1$3::class$ = nullptr;

$CompoundAttribute _LocalDate_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _LocalDate_FieldInfo_[] = {
	{"MIN", "Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocalDate, MIN)},
	{"MAX", "Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocalDate, MAX)},
	{"EPOCH", "Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocalDate, EPOCH)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LocalDate, serialVersionUID)},
	{"DAYS_PER_CYCLE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LocalDate, DAYS_PER_CYCLE)},
	{"DAYS_0000_TO_1970", "J", nullptr, $STATIC | $FINAL, $constField(LocalDate, DAYS_0000_TO_1970)},
	{"year", "I", nullptr, $PRIVATE | $FINAL, $field(LocalDate, year)},
	{"month", "S", nullptr, $PRIVATE | $FINAL, $field(LocalDate, month)},
	{"day", "S", nullptr, $PRIVATE | $FINAL, $field(LocalDate, day)},
	{}
};

$MethodInfo _LocalDate_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(III)V", nullptr, $PRIVATE, $method(LocalDate, init$, void, int32_t, int32_t, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(LocalDate, adjustInto, $Temporal*, $Temporal*)},
	{"atStartOfDay", "()Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDate, atStartOfDay, $LocalDateTime*)},
	{"atStartOfDay", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(LocalDate, atStartOfDay, $ZonedDateTime*, $ZoneId*)},
	{"atTime", "(Ljava/time/LocalTime;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDate, atTime, $ChronoLocalDateTime*, $LocalTime*)},
	{"atTime", "(II)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDate, atTime, $LocalDateTime*, int32_t, int32_t)},
	{"atTime", "(III)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDate, atTime, $LocalDateTime*, int32_t, int32_t, int32_t)},
	{"atTime", "(IIII)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDate, atTime, $LocalDateTime*, int32_t, int32_t, int32_t, int32_t)},
	{"atTime", "(Ljava/time/OffsetTime;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(LocalDate, atTime, $OffsetDateTime*, $OffsetTime*)},
	{"compareTo", "(Ljava/time/chrono/ChronoLocalDate;)I", nullptr, $PUBLIC, $virtualMethod(LocalDate, compareTo, int32_t, $ChronoLocalDate*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(LocalDate, compareTo, int32_t, Object$*)},
	{"compareTo0", "(Ljava/time/LocalDate;)I", nullptr, 0, $method(LocalDate, compareTo0, int32_t, LocalDate*)},
	{"create", "(III)Ljava/time/LocalDate;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocalDate, create, LocalDate*, int32_t, int32_t, int32_t)},
	{"datesUntil", "(Ljava/time/LocalDate;)Ljava/util/stream/Stream;", "(Ljava/time/LocalDate;)Ljava/util/stream/Stream<Ljava/time/LocalDate;>;", $PUBLIC, $method(LocalDate, datesUntil, $Stream*, LocalDate*)},
	{"datesUntil", "(Ljava/time/LocalDate;Ljava/time/Period;)Ljava/util/stream/Stream;", "(Ljava/time/LocalDate;Ljava/time/Period;)Ljava/util/stream/Stream<Ljava/time/LocalDate;>;", $PUBLIC, $method(LocalDate, datesUntil, $Stream*, LocalDate*, $Period*)},
	{"daysUntil", "(Ljava/time/LocalDate;)J", nullptr, 0, $method(LocalDate, daysUntil, int64_t, LocalDate*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocalDate, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, from, LocalDate*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(LocalDate, get, int32_t, $TemporalField*)},
	{"get0", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PRIVATE, $method(LocalDate, get0, int32_t, $TemporalField*)},
	{"getChronology", "()Ljava/time/chrono/IsoChronology;", nullptr, $PUBLIC, $virtualMethod(LocalDate, getChronology, $Chronology*)},
	{"getDayOfMonth", "()I", nullptr, $PUBLIC, $method(LocalDate, getDayOfMonth, int32_t)},
	{"getDayOfWeek", "()Ljava/time/DayOfWeek;", nullptr, $PUBLIC, $method(LocalDate, getDayOfWeek, $DayOfWeek*)},
	{"getDayOfYear", "()I", nullptr, $PUBLIC, $method(LocalDate, getDayOfYear, int32_t)},
	{"getEra", "()Ljava/time/chrono/IsoEra;", nullptr, $PUBLIC, $virtualMethod(LocalDate, getEra, $Era*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(LocalDate, getLong, int64_t, $TemporalField*)},
	{"getMonth", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(LocalDate, getMonth, $Month*)},
	{"getMonthValue", "()I", nullptr, $PUBLIC, $method(LocalDate, getMonthValue, int32_t)},
	{"getProlepticMonth", "()J", nullptr, $PRIVATE, $method(LocalDate, getProlepticMonth, int64_t)},
	{"getYear", "()I", nullptr, $PUBLIC, $method(LocalDate, getYear, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(LocalDate, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/chrono/ChronoLocalDate;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, isAfter, bool, $ChronoLocalDate*)},
	{"isBefore", "(Ljava/time/chrono/ChronoLocalDate;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, isBefore, bool, $ChronoLocalDate*)},
	{"isEqual", "(Ljava/time/chrono/ChronoLocalDate;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, isEqual, bool, $ChronoLocalDate*)},
	{"isLeapYear", "()Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, isLeapYear, bool)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDate, isSupported, bool, $TemporalUnit*)},
	{"lambda$datesUntil$0", "(JJJ)Ljava/time/LocalDate;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LocalDate, lambda$datesUntil$0, LocalDate*, int64_t, int64_t, int64_t)},
	{"lambda$datesUntil$1", "(JJJ)Ljava/time/LocalDate;", nullptr, $PRIVATE | $SYNTHETIC, $method(LocalDate, lambda$datesUntil$1, LocalDate*, int64_t, int64_t, int64_t)},
	{"lengthOfMonth", "()I", nullptr, $PUBLIC, $virtualMethod(LocalDate, lengthOfMonth, int32_t)},
	{"lengthOfYear", "()I", nullptr, $PUBLIC, $virtualMethod(LocalDate, lengthOfYear, int32_t)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDate, minus, LocalDate*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDate, minus, LocalDate*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, minusDays, LocalDate*, int64_t)},
	{"minusMonths", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, minusMonths, LocalDate*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, minusWeeks, LocalDate*, int64_t)},
	{"minusYears", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, minusYears, LocalDate*, int64_t)},
	{"monthsUntil", "(Ljava/time/LocalDate;)J", nullptr, $PRIVATE, $method(LocalDate, monthsUntil, int64_t, LocalDate*)},
	{"now", "()Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, now, LocalDate*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, now, LocalDate*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, now, LocalDate*, $Clock*)},
	{"of", "(ILjava/time/Month;I)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, of, LocalDate*, int32_t, $Month*, int32_t)},
	{"of", "(III)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, of, LocalDate*, int32_t, int32_t, int32_t)},
	{"ofEpochDay", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, ofEpochDay, LocalDate*, int64_t)},
	{"ofInstant", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, ofInstant, LocalDate*, $Instant*, $ZoneId*)},
	{"ofYearDay", "(II)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, ofYearDay, LocalDate*, int32_t, int32_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, parse, LocalDate*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/LocalDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDate, parse, LocalDate*, $CharSequence*, $DateTimeFormatter*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDate, plus, LocalDate*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDate, plus, LocalDate*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, plusDays, LocalDate*, int64_t)},
	{"plusMonths", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, plusMonths, LocalDate*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, plusWeeks, LocalDate*, int64_t)},
	{"plusYears", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, plusYears, LocalDate*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(LocalDate, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(LocalDate, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/LocalDate;", nullptr, $STATIC, $staticMethod(LocalDate, readExternal, LocalDate*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(LocalDate, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"resolvePreviousValid", "(III)Ljava/time/LocalDate;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocalDate, resolvePreviousValid, LocalDate*, int32_t, int32_t, int32_t)},
	{"toEpochDay", "()J", nullptr, $PUBLIC, $virtualMethod(LocalDate, toEpochDay, int64_t)},
	{"toEpochSecond", "(Ljava/time/LocalTime;Ljava/time/ZoneOffset;)J", nullptr, $PUBLIC, $method(LocalDate, toEpochSecond, int64_t, $LocalTime*, $ZoneOffset*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocalDate, toString, $String*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(LocalDate, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"until", "(Ljava/time/chrono/ChronoLocalDate;)Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(LocalDate, until, $ChronoPeriod*, $ChronoLocalDate*)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDate, with, LocalDate*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDate, with, LocalDate*, $TemporalField*, int64_t)},
	{"withDayOfMonth", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, withDayOfMonth, LocalDate*, int32_t)},
	{"withDayOfYear", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, withDayOfYear, LocalDate*, int32_t)},
	{"withMonth", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, withMonth, LocalDate*, int32_t)},
	{"withYear", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(LocalDate, withYear, LocalDate*, int32_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(LocalDate, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(LocalDate, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _LocalDate_InnerClassesInfo_[] = {
	{"java.time.LocalDate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _LocalDate_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.LocalDate",
	"java.lang.Object",
	"java.time.chrono.ChronoLocalDate,java.io.Serializable",
	_LocalDate_FieldInfo_,
	_LocalDate_MethodInfo_,
	nullptr,
	nullptr,
	_LocalDate_InnerClassesInfo_,
	_LocalDate_Annotations_,
	nullptr,
	"java.time.LocalDate$1"
};

$Object* allocate$LocalDate($Class* clazz) {
	return $of($alloc(LocalDate));
}

$Object* LocalDate::clone() {
	 return this->$ChronoLocalDate::clone();
}

void LocalDate::finalize() {
	this->$ChronoLocalDate::finalize();
}

LocalDate* LocalDate::MIN = nullptr;
LocalDate* LocalDate::MAX = nullptr;
LocalDate* LocalDate::EPOCH = nullptr;

LocalDate* LocalDate::now() {
	$init(LocalDate);
	return now($($Clock::systemDefaultZone()));
}

LocalDate* LocalDate::now($ZoneId* zone) {
	$init(LocalDate);
	return now($($Clock::system(zone)));
}

LocalDate* LocalDate::now($Clock* clock) {
	$init(LocalDate);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(clock), "clock"_s);
	$var($Instant, now, $nc(clock)->instant());
	return ofInstant(now, $(clock->getZone()));
}

LocalDate* LocalDate::of(int32_t year, $Month* month, int32_t dayOfMonth) {
	$init(LocalDate);
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(year);
	$Objects::requireNonNull($of(month), "month"_s);
	$ChronoField::DAY_OF_MONTH->checkValidValue(dayOfMonth);
	return create(year, $nc(month)->getValue(), dayOfMonth);
}

LocalDate* LocalDate::of(int32_t year, int32_t month, int32_t dayOfMonth) {
	$init(LocalDate);
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(year);
	$ChronoField::MONTH_OF_YEAR->checkValidValue(month);
	$ChronoField::DAY_OF_MONTH->checkValidValue(dayOfMonth);
	return create(year, month, dayOfMonth);
}

LocalDate* LocalDate::ofYearDay(int32_t year, int32_t dayOfYear) {
	$init(LocalDate);
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(year);
	$ChronoField::DAY_OF_YEAR->checkValidValue(dayOfYear);
	$init($IsoChronology);
	bool leap = $nc($IsoChronology::INSTANCE)->isLeapYear(year);
	if (dayOfYear == 366 && leap == false) {
		$throwNew($DateTimeException, $$str({"Invalid date \'DayOfYear 366\' as \'"_s, $$str(year), "\' is not a leap year"_s}));
	}
	$Month* moy = $Month::of((dayOfYear - 1) / 31 + 1);
	int32_t var$0 = $nc(moy)->firstDayOfYear(leap);
	int32_t monthEnd = var$0 + moy->length(leap) - 1;
	if (dayOfYear > monthEnd) {
		moy = moy->plus(1);
	}
	int32_t dom = dayOfYear - moy->firstDayOfYear(leap) + 1;
	return $new(LocalDate, year, moy->getValue(), dom);
}

LocalDate* LocalDate::ofInstant($Instant* instant, $ZoneId* zone) {
	$init(LocalDate);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(instant), "instant"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	$var($ZoneRules, rules, $nc(zone)->getRules());
	$var($ZoneOffset, offset, $nc(rules)->getOffset(instant));
	int64_t var$0 = $nc(instant)->getEpochSecond();
	int64_t localSecond = var$0 + $nc(offset)->getTotalSeconds();
	int64_t localEpochDay = $Math::floorDiv(localSecond, 0x00015180);
	return ofEpochDay(localEpochDay);
}

LocalDate* LocalDate::ofEpochDay(int64_t epochDay) {
	$init(LocalDate);
	$init($ChronoField);
	$ChronoField::EPOCH_DAY->checkValidValue(epochDay);
	int64_t zeroDay = epochDay + LocalDate::DAYS_0000_TO_1970;
	zeroDay -= 60;
	int64_t adjust = 0;
	if (zeroDay < 0) {
		int64_t adjustCycles = $div((zeroDay + 1), LocalDate::DAYS_PER_CYCLE) - 1;
		adjust = adjustCycles * 400;
		zeroDay += -adjustCycles * LocalDate::DAYS_PER_CYCLE;
	}
	int64_t yearEst = $div((400 * zeroDay + 591), LocalDate::DAYS_PER_CYCLE);
	int64_t doyEst = zeroDay - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	if (doyEst < 0) {
		--yearEst;
		doyEst = zeroDay - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	}
	yearEst += adjust;
	int32_t marchDoy0 = (int32_t)doyEst;
	int32_t marchMonth0 = (marchDoy0 * 5 + 2) / 153;
	int32_t month = (marchMonth0 + 2) % 12 + 1;
	int32_t dom = marchDoy0 - (marchMonth0 * 306 + 5) / 10 + 1;
	yearEst += marchMonth0 / 10;
	int32_t year = $ChronoField::YEAR->checkValidIntValue(yearEst);
	return $new(LocalDate, year, month, dom);
}

LocalDate* LocalDate::from($TemporalAccessor* temporal) {
	$init(LocalDate);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	$var(LocalDate, date, $cast(LocalDate, $nc(temporal)->query($($TemporalQueries::localDate()))));
	if (date == nullptr) {
		$var($String, var$0, $$str({"Unable to obtain LocalDate from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($of(temporal)->getClass()->getName())));
	}
	return date;
}

LocalDate* LocalDate::parse($CharSequence* text) {
	$init(LocalDate);
	$init($DateTimeFormatter);
	return parse(text, $DateTimeFormatter::ISO_LOCAL_DATE);
}

LocalDate* LocalDate::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(LocalDate);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(LocalDate, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(LocalDate$$Lambda$from))));
}

LocalDate* LocalDate::create(int32_t year, int32_t month, int32_t dayOfMonth) {
	$init(LocalDate);
	$useLocalCurrentObjectStackCache();
	if (dayOfMonth > 28) {
		int32_t dom = 31;
		switch (month) {
		case 2:
			{
				$init($IsoChronology);
				dom = ($nc($IsoChronology::INSTANCE)->isLeapYear(year) ? 29 : 28);
				break;
			}
		case 4:
			{}
		case 6:
			{}
		case 9:
			{}
		case 11:
			{
				dom = 30;
				break;
			}
		}
		if (dayOfMonth > dom) {
			if (dayOfMonth == 29) {
				$throwNew($DateTimeException, $$str({"Invalid date \'February 29\' as \'"_s, $$str(year), "\' is not a leap year"_s}));
			} else {
				$throwNew($DateTimeException, $$str({"Invalid date \'"_s, $($nc($($Month::of(month)))->name()), " "_s, $$str(dayOfMonth), "\'"_s}));
			}
		}
	}
	return $new(LocalDate, year, month, dayOfMonth);
}

LocalDate* LocalDate::resolvePreviousValid(int32_t year, int32_t month, int32_t day) {
	$init(LocalDate);
	switch (month) {
	case 2:
		{
			$init($IsoChronology);
			day = $Math::min(day, $nc($IsoChronology::INSTANCE)->isLeapYear(year) ? 29 : 28);
			break;
		}
	case 4:
		{}
	case 6:
		{}
	case 9:
		{}
	case 11:
		{
			day = $Math::min(day, 30);
			break;
		}
	}
	return $new(LocalDate, year, month, day);
}

void LocalDate::init$(int32_t year, int32_t month, int32_t dayOfMonth) {
	this->year = year;
	this->month = (int16_t)month;
	this->day = (int16_t)dayOfMonth;
}

bool LocalDate::isSupported($TemporalField* field) {
	return $ChronoLocalDate::isSupported(field);
}

bool LocalDate::isSupported($TemporalUnit* unit) {
	return $ChronoLocalDate::isSupported(unit);
}

$ValueRange* LocalDate::range($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			if ($nc(chronoField)->isDateBased()) {
				$init($LocalDate$1);
				switch ($nc($LocalDate$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
				case 1:
					{
						return $ValueRange::of(1, lengthOfMonth());
					}
				case 2:
					{
						return $ValueRange::of(1, lengthOfYear());
					}
				case 3:
					{
						$init($Month);
						bool var$1 = getMonth() == $Month::FEBRUARY;
						return $ValueRange::of(1, var$1 && isLeapYear() == false ? 4 : 5);
					}
				case 4:
					{
						return (getYear() <= 0 ? $ValueRange::of(1, $Year::MAX_VALUE + 1) : $ValueRange::of(1, $Year::MAX_VALUE));
					}
				}
				return $nc(field)->range();
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $nc(field)->rangeRefinedBy(this);
}

int32_t LocalDate::get($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		return get0(field);
	}
	return $ChronoLocalDate::get(field);
}

int64_t LocalDate::getLong($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		if ($equals(field, $ChronoField::EPOCH_DAY)) {
			return toEpochDay();
		}
		if ($equals(field, $ChronoField::PROLEPTIC_MONTH)) {
			return getProlepticMonth();
		}
		return get0(field);
	}
	return $nc(field)->getFrom(this);
}

int32_t LocalDate::get0($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	$init($LocalDate$1);
	switch ($nc($LocalDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
	case 5:
		{
			return $nc($(getDayOfWeek()))->getValue();
		}
	case 6:
		{
			return ((this->day - 1) % 7) + 1;
		}
	case 7:
		{
			return ((getDayOfYear() - 1) % 7) + 1;
		}
	case 1:
		{
			return this->day;
		}
	case 2:
		{
			return getDayOfYear();
		}
	case 8:
		{
			$throwNew($UnsupportedTemporalTypeException, "Invalid field \'EpochDay\' for get() method, use getLong() instead"_s);
		}
	case 3:
		{
			return ((this->day - 1) / 7) + 1;
		}
	case 9:
		{
			return ((getDayOfYear() - 1) / 7) + 1;
		}
	case 10:
		{
			return this->month;
		}
	case 11:
		{
			$throwNew($UnsupportedTemporalTypeException, "Invalid field \'ProlepticMonth\' for get() method, use getLong() instead"_s);
		}
	case 4:
		{
			return (this->year >= 1 ? this->year : 1 - this->year);
		}
	case 12:
		{
			return this->year;
		}
	case 13:
		{
			return (this->year >= 1 ? 1 : 0);
		}
	}
	$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
}

int64_t LocalDate::getProlepticMonth() {
	return (this->year * (int64_t)12 + this->month - 1);
}

$Chronology* LocalDate::getChronology() {
	$init($IsoChronology);
	return $IsoChronology::INSTANCE;
}

$Era* LocalDate::getEra() {
	$init($IsoEra);
	return ((getYear() >= 1 ? $IsoEra::CE : $IsoEra::BCE));
}

int32_t LocalDate::getYear() {
	return this->year;
}

int32_t LocalDate::getMonthValue() {
	return this->month;
}

$Month* LocalDate::getMonth() {
	return $Month::of(this->month);
}

int32_t LocalDate::getDayOfMonth() {
	return this->day;
}

int32_t LocalDate::getDayOfYear() {
	return $nc($(getMonth()))->firstDayOfYear(isLeapYear()) + this->day - 1;
}

$DayOfWeek* LocalDate::getDayOfWeek() {
	int32_t dow0 = $Math::floorMod(toEpochDay() + 3, 7);
	return $DayOfWeek::of(dow0 + 1);
}

bool LocalDate::isLeapYear() {
	$init($IsoChronology);
	return $nc($IsoChronology::INSTANCE)->isLeapYear(this->year);
}

int32_t LocalDate::lengthOfMonth() {
	switch (this->month) {
	case 2:
		{
			return (isLeapYear() ? 29 : 28);
		}
	case 4:
		{}
	case 6:
		{}
	case 9:
		{}
	case 11:
		{
			return 30;
		}
	default:
		{
			return 31;
		}
	}
}

int32_t LocalDate::lengthOfYear() {
	return (isLeapYear() ? 366 : 365);
}

LocalDate* LocalDate::with($TemporalAdjuster* adjuster) {
	if ($instanceOf(LocalDate, adjuster)) {
		return $cast(LocalDate, adjuster);
	}
	return $cast(LocalDate, $nc(adjuster)->adjustInto(this));
}

LocalDate* LocalDate::with($TemporalField* field, int64_t newValue) {
	$useLocalCurrentObjectStackCache();
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$nc(chronoField)->checkValidValue(newValue);
			$init($LocalDate$1);
			switch ($nc($LocalDate$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
			case 5:
				{
					return plusDays(newValue - $nc($(getDayOfWeek()))->getValue());
				}
			case 6:
				{
					return plusDays(newValue - getLong($ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH));
				}
			case 7:
				{
					return plusDays(newValue - getLong($ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR));
				}
			case 1:
				{
					return withDayOfMonth((int32_t)newValue);
				}
			case 2:
				{
					return withDayOfYear((int32_t)newValue);
				}
			case 8:
				{
					return LocalDate::ofEpochDay(newValue);
				}
			case 3:
				{
					return plusWeeks(newValue - getLong($ChronoField::ALIGNED_WEEK_OF_MONTH));
				}
			case 9:
				{
					return plusWeeks(newValue - getLong($ChronoField::ALIGNED_WEEK_OF_YEAR));
				}
			case 10:
				{
					return withMonth((int32_t)newValue);
				}
			case 11:
				{
					return plusMonths(newValue - getProlepticMonth());
				}
			case 4:
				{
					return withYear((int32_t)(this->year >= 1 ? newValue : 1 - newValue));
				}
			case 12:
				{
					return withYear((int32_t)newValue);
				}
			case 13:
				{
					return (getLong($ChronoField::ERA) == newValue ? this : withYear(1 - this->year));
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $cast(LocalDate, $nc(field)->adjustInto(this, newValue));
}

LocalDate* LocalDate::withYear(int32_t year) {
	if (this->year == year) {
		return this;
	}
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(year);
	return resolvePreviousValid(year, this->month, this->day);
}

LocalDate* LocalDate::withMonth(int32_t month) {
	if (this->month == month) {
		return this;
	}
	$init($ChronoField);
	$ChronoField::MONTH_OF_YEAR->checkValidValue(month);
	return resolvePreviousValid(this->year, month, this->day);
}

LocalDate* LocalDate::withDayOfMonth(int32_t dayOfMonth) {
	if (this->day == dayOfMonth) {
		return this;
	}
	return of(this->year, (int32_t)this->month, dayOfMonth);
}

LocalDate* LocalDate::withDayOfYear(int32_t dayOfYear) {
	if (this->getDayOfYear() == dayOfYear) {
		return this;
	}
	return ofYearDay(this->year, dayOfYear);
}

LocalDate* LocalDate::plus($TemporalAmount* amountToAdd) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Period, periodToAdd, nullptr);
		bool var$0 = $instanceOf($Period, amountToAdd);
		if (var$0) {
			$assign(periodToAdd, $cast($Period, amountToAdd));
			var$0 = true;
		}
		if (var$0) {
			return $nc($(plusMonths($nc(periodToAdd)->toTotalMonths())))->plusDays($nc(periodToAdd)->getDays());
		}
	}
	$Objects::requireNonNull($of(amountToAdd), "amountToAdd"_s);
	return $cast(LocalDate, $nc(amountToAdd)->addTo(this));
}

LocalDate* LocalDate::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			$init($LocalDate$1);
			switch ($nc($LocalDate$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return plusDays(amountToAdd);
				}
			case 2:
				{
					return plusWeeks(amountToAdd);
				}
			case 3:
				{
					return plusMonths(amountToAdd);
				}
			case 4:
				{
					return plusYears(amountToAdd);
				}
			case 5:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 10));
				}
			case 6:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 100));
				}
			case 7:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 1000));
				}
			case 8:
				{
					$init($ChronoField);
					return with($ChronoField::ERA, $Math::addExact(getLong($ChronoField::ERA), amountToAdd));
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
	return $cast(LocalDate, $nc(unit)->addTo(this, amountToAdd));
}

LocalDate* LocalDate::plusYears(int64_t yearsToAdd) {
	if (yearsToAdd == 0) {
		return this;
	}
	$init($ChronoField);
	int32_t newYear = $ChronoField::YEAR->checkValidIntValue(this->year + yearsToAdd);
	return resolvePreviousValid(newYear, this->month, this->day);
}

LocalDate* LocalDate::plusMonths(int64_t monthsToAdd) {
	if (monthsToAdd == 0) {
		return this;
	}
	int64_t monthCount = this->year * (int64_t)12 + (this->month - 1);
	int64_t calcMonths = monthCount + monthsToAdd;
	$init($ChronoField);
	int32_t newYear = $ChronoField::YEAR->checkValidIntValue($Math::floorDiv(calcMonths, 12));
	int32_t newMonth = $Math::floorMod(calcMonths, 12) + 1;
	return resolvePreviousValid(newYear, newMonth, this->day);
}

LocalDate* LocalDate::plusWeeks(int64_t weeksToAdd) {
	return plusDays($Math::multiplyExact(weeksToAdd, 7));
}

LocalDate* LocalDate::plusDays(int64_t daysToAdd) {
	if (daysToAdd == 0) {
		return this;
	}
	int64_t dom = this->day + daysToAdd;
	if (dom > 0) {
		if (dom <= 28) {
			return $new(LocalDate, this->year, this->month, (int32_t)dom);
		} else if (dom <= 59) {
			int64_t monthLen = lengthOfMonth();
			if (dom <= monthLen) {
				return $new(LocalDate, this->year, this->month, (int32_t)dom);
			} else if (this->month < 12) {
				return $new(LocalDate, this->year, this->month + 1, (int32_t)(dom - monthLen));
			} else {
				$init($ChronoField);
				$ChronoField::YEAR->checkValidValue(this->year + 1);
				return $new(LocalDate, this->year + 1, 1, (int32_t)(dom - monthLen));
			}
		}
	}
	int64_t mjDay = $Math::addExact(toEpochDay(), daysToAdd);
	return LocalDate::ofEpochDay(mjDay);
}

LocalDate* LocalDate::minus($TemporalAmount* amountToSubtract) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Period, periodToSubtract, nullptr);
		bool var$0 = $instanceOf($Period, amountToSubtract);
		if (var$0) {
			$assign(periodToSubtract, $cast($Period, amountToSubtract));
			var$0 = true;
		}
		if (var$0) {
			return $nc($(minusMonths($nc(periodToSubtract)->toTotalMonths())))->minusDays($nc(periodToSubtract)->getDays());
		}
	}
	$Objects::requireNonNull($of(amountToSubtract), "amountToSubtract"_s);
	return $cast(LocalDate, $nc(amountToSubtract)->subtractFrom(this));
}

LocalDate* LocalDate::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus(1, unit) : plus(-amountToSubtract, unit));
}

LocalDate* LocalDate::minusYears(int64_t yearsToSubtract) {
	return (yearsToSubtract == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-yearsToSubtract));
}

LocalDate* LocalDate::minusMonths(int64_t monthsToSubtract) {
	return (monthsToSubtract == $Long::MIN_VALUE ? $nc($(plusMonths($Long::MAX_VALUE)))->plusMonths(1) : plusMonths(-monthsToSubtract));
}

LocalDate* LocalDate::minusWeeks(int64_t weeksToSubtract) {
	return (weeksToSubtract == $Long::MIN_VALUE ? $nc($(plusWeeks($Long::MAX_VALUE)))->plusWeeks(1) : plusWeeks(-weeksToSubtract));
}

LocalDate* LocalDate::minusDays(int64_t daysToSubtract) {
	return (daysToSubtract == $Long::MIN_VALUE ? $nc($(plusDays($Long::MAX_VALUE)))->plusDays(1) : plusDays(-daysToSubtract));
}

$Object* LocalDate::query($TemporalQuery* query) {
	if (query == $TemporalQueries::localDate()) {
		return $of($of(this));
	}
	return $of($ChronoLocalDate::query(query));
}

$Temporal* LocalDate::adjustInto($Temporal* temporal) {
	return $ChronoLocalDate::adjustInto(temporal);
}

int64_t LocalDate::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(LocalDate, end, LocalDate::from(endExclusive));
	if ($instanceOf($ChronoUnit, unit)) {
		$init($LocalDate$1);
		switch ($nc($LocalDate$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc(($cast($ChronoUnit, unit)))->ordinal())) {
		case 1:
			{
				return daysUntil(end);
			}
		case 2:
			{
				return daysUntil(end) / 7;
			}
		case 3:
			{
				return monthsUntil(end);
			}
		case 4:
			{
				return monthsUntil(end) / 12;
			}
		case 5:
			{
				return monthsUntil(end) / 120;
			}
		case 6:
			{
				return monthsUntil(end) / 1200;
			}
		case 7:
			{
				return monthsUntil(end) / 12000;
			}
		case 8:
			{
				$init($ChronoField);
				int64_t var$0 = $nc(end)->getLong($ChronoField::ERA);
				return var$0 - getLong($ChronoField::ERA);
			}
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
	}
	return $nc(unit)->between(this, end);
}

int64_t LocalDate::daysUntil(LocalDate* end) {
	int64_t var$0 = $nc(end)->toEpochDay();
	return var$0 - toEpochDay();
}

int64_t LocalDate::monthsUntil(LocalDate* end) {
	int64_t var$0 = getProlepticMonth() * (int64_t)32;
	int64_t packed1 = var$0 + getDayOfMonth();
	int64_t var$1 = $nc(end)->getProlepticMonth() * (int64_t)32;
	int64_t packed2 = var$1 + end->getDayOfMonth();
	return (packed2 - packed1) / 32;
}

$ChronoPeriod* LocalDate::until($ChronoLocalDate* endDateExclusive) {
	$useLocalCurrentObjectStackCache();
	$var(LocalDate, end, LocalDate::from(endDateExclusive));
	int64_t var$0 = $nc(end)->getProlepticMonth();
	int64_t totalMonths = var$0 - this->getProlepticMonth();
	int32_t days = end->day - this->day;
	if (totalMonths > 0 && days < 0) {
		--totalMonths;
		$var(LocalDate, calcDate, this->plusMonths(totalMonths));
		int64_t var$1 = end->toEpochDay();
		days = (int32_t)(var$1 - $nc(calcDate)->toEpochDay());
	} else if (totalMonths < 0 && days > 0) {
		++totalMonths;
		days -= end->lengthOfMonth();
	}
	int64_t years = totalMonths / 12;
	int32_t months = (int32_t)(totalMonths % 12);
	return $Period::of($Math::toIntExact(years), months, days);
}

$Stream* LocalDate::datesUntil(LocalDate* endExclusive) {
	$useLocalCurrentObjectStackCache();
	int64_t end = $nc(endExclusive)->toEpochDay();
	int64_t start = toEpochDay();
	if (end < start) {
		$throwNew($IllegalArgumentException, $$str({endExclusive, " < "_s, this}));
	}
	return $nc($($LongStream::range(start, end)))->mapToObj(static_cast<$LongFunction*>($$new(LocalDate$$Lambda$ofEpochDay$1)));
}

$Stream* LocalDate::datesUntil(LocalDate* endExclusive, $Period* step) {
	$useLocalCurrentObjectStackCache();
	if ($nc(step)->isZero()) {
		$throwNew($IllegalArgumentException, "step is zero"_s);
	}
	int64_t end = $nc(endExclusive)->toEpochDay();
	int64_t start = toEpochDay();
	int64_t until = end - start;
	int64_t months = $nc(step)->toTotalMonths();
	int64_t days = step->getDays();
	if ((months < 0 && days > 0) || (months > 0 && days < 0)) {
		$throwNew($IllegalArgumentException, "period months and days are of opposite sign"_s);
	}
	if (until == 0) {
		return $Stream::empty();
	}
	int32_t sign = months > 0 || days > 0 ? 1 : -1;
	if ((sign < 0) ^ (until < 0)) {
		$throwNew($IllegalArgumentException, $$str({endExclusive, (sign < 0 ? " > "_s : " < "_s), this}));
	}
	if (months == 0) {
		int64_t steps = $div((until - sign), days);
		return $nc($($LongStream::rangeClosed(0, steps)))->mapToObj(static_cast<$LongFunction*>($$new(LocalDate$$Lambda$lambda$datesUntil$0$2, start, days)));
	}
	int64_t steps = $div(until * 1600, (months * 0x0000BE3B + days * 1600)) + 1;
	int64_t addMonths = months * steps;
	int64_t addDays = days * steps;
	int64_t var$0 = 0;
	if (months > 0) {
		int64_t var$1 = $nc(LocalDate::MAX)->getProlepticMonth();
		var$0 = var$1 - getProlepticMonth();
	} else {
		int64_t var$2 = getProlepticMonth();
		var$0 = var$2 - $nc(LocalDate::MIN)->getProlepticMonth();
	}
	int64_t maxAddMonths = var$0;
	if (addMonths * sign > maxAddMonths || ($nc($(plusMonths(addMonths)))->toEpochDay() + addDays) * sign >= end * sign) {
		--steps;
		addMonths -= months;
		addDays -= days;
		if (addMonths * sign > maxAddMonths || ($nc($(plusMonths(addMonths)))->toEpochDay() + addDays) * sign >= end * sign) {
			--steps;
		}
	}
	return $nc($($LongStream::rangeClosed(0, steps)))->mapToObj(static_cast<$LongFunction*>($$new(LocalDate$$Lambda$lambda$datesUntil$1$3, this, months, days)));
}

$String* LocalDate::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$ChronoLocalDateTime* LocalDate::atTime($LocalTime* time) {
	return $LocalDateTime::of(this, time);
}

$LocalDateTime* LocalDate::atTime(int32_t hour, int32_t minute) {
	return $cast($LocalDateTime, atTime($($LocalTime::of(hour, minute))));
}

$LocalDateTime* LocalDate::atTime(int32_t hour, int32_t minute, int32_t second) {
	return $cast($LocalDateTime, atTime($($LocalTime::of(hour, minute, second))));
}

$LocalDateTime* LocalDate::atTime(int32_t hour, int32_t minute, int32_t second, int32_t nanoOfSecond) {
	return $cast($LocalDateTime, atTime($($LocalTime::of(hour, minute, second, nanoOfSecond))));
}

$OffsetDateTime* LocalDate::atTime($OffsetTime* time) {
	$useLocalCurrentObjectStackCache();
	$var($LocalDateTime, var$0, $LocalDateTime::of(this, $($nc(time)->toLocalTime())));
	return $OffsetDateTime::of(var$0, $($nc(time)->getOffset()));
}

$LocalDateTime* LocalDate::atStartOfDay() {
	$init($LocalTime);
	return $LocalDateTime::of(this, $LocalTime::MIDNIGHT);
}

$ZonedDateTime* LocalDate::atStartOfDay($ZoneId* zone) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(zone), "zone"_s);
	$init($LocalTime);
	$var($LocalDateTime, ldt, $cast($LocalDateTime, atTime($LocalTime::MIDNIGHT)));
	if (!($instanceOf($ZoneOffset, zone))) {
		$var($ZoneRules, rules, $nc(zone)->getRules());
		$var($ZoneOffsetTransition, trans, $nc(rules)->getTransition(ldt));
		if (trans != nullptr && trans->isGap()) {
			$assign(ldt, trans->getDateTimeAfter());
		}
	}
	return $ZonedDateTime::of(ldt, zone);
}

int64_t LocalDate::toEpochDay() {
	int64_t y = this->year;
	int64_t m = this->month;
	int64_t total = 0;
	total += 365 * y;
	if (y >= 0) {
		total += (y + 3) / 4 - (y + 99) / 100 + (y + 399) / 400;
	} else {
		total -= y / -4 - y / -100 + y / -400;
	}
	total += ((367 * m - 362) / 12);
	total += this->day - 1;
	if (m > 2) {
		--total;
		if (isLeapYear() == false) {
			--total;
		}
	}
	return total - LocalDate::DAYS_0000_TO_1970;
}

int64_t LocalDate::toEpochSecond($LocalTime* time, $ZoneOffset* offset) {
	$Objects::requireNonNull($of(time), "time"_s);
	$Objects::requireNonNull($of(offset), "offset"_s);
	int64_t var$0 = toEpochDay() * 0x00015180;
	int64_t secs = var$0 + $nc(time)->toSecondOfDay();
	secs -= $nc(offset)->getTotalSeconds();
	return secs;
}

int32_t LocalDate::compareTo($ChronoLocalDate* other) {
	if ($instanceOf(LocalDate, other)) {
		return compareTo0($cast(LocalDate, other));
	}
	return $ChronoLocalDate::compareTo(other);
}

int32_t LocalDate::compareTo0(LocalDate* otherDate) {
	int32_t cmp = (this->year - $nc(otherDate)->year);
	if (cmp == 0) {
		cmp = (this->month - otherDate->month);
		if (cmp == 0) {
			cmp = (this->day - otherDate->day);
		}
	}
	return cmp;
}

bool LocalDate::isAfter($ChronoLocalDate* other) {
	if ($instanceOf(LocalDate, other)) {
		return compareTo0($cast(LocalDate, other)) > 0;
	}
	return $ChronoLocalDate::isAfter(other);
}

bool LocalDate::isBefore($ChronoLocalDate* other) {
	if ($instanceOf(LocalDate, other)) {
		return compareTo0($cast(LocalDate, other)) < 0;
	}
	return $ChronoLocalDate::isBefore(other);
}

bool LocalDate::isEqual($ChronoLocalDate* other) {
	if ($instanceOf(LocalDate, other)) {
		return compareTo0($cast(LocalDate, other)) == 0;
	}
	return $ChronoLocalDate::isEqual(other);
}

bool LocalDate::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(LocalDate, obj)) {
		return compareTo0($cast(LocalDate, obj)) == 0;
	}
	return false;
}

int32_t LocalDate::hashCode() {
	int32_t yearValue = this->year;
	int32_t monthValue = this->month;
	int32_t dayValue = this->day;
	return ((int32_t)(yearValue & (uint32_t)-2048)) ^ ((yearValue << 11) + (monthValue << 6) + (dayValue));
}

$String* LocalDate::toString() {
	int32_t yearValue = this->year;
	int32_t monthValue = this->month;
	int32_t dayValue = this->day;
	int32_t absYear = $Math::abs(yearValue);
	$var($StringBuilder, buf, $new($StringBuilder, 10));
	if (absYear < 1000) {
		if (yearValue < 0) {
			buf->append(yearValue - 10000)->deleteCharAt(1);
		} else {
			buf->append(yearValue + 10000)->deleteCharAt(0);
		}
	} else {
		if (yearValue > 9999) {
			buf->append(u'+');
		}
		buf->append(yearValue);
	}
	return buf->append(monthValue < 10 ? "-0"_s : "-"_s)->append(monthValue)->append(dayValue < 10 ? "-0"_s : "-"_s)->append(dayValue)->toString();
}

$Object* LocalDate::writeReplace() {
	return $of($new($Ser, $Ser::LOCAL_DATE_TYPE, this));
}

void LocalDate::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void LocalDate::writeExternal($DataOutput* out) {
	$nc(out)->writeInt(this->year);
	out->writeByte(this->month);
	out->writeByte(this->day);
}

LocalDate* LocalDate::readExternal($DataInput* in) {
	$init(LocalDate);
	int32_t year = $nc(in)->readInt();
	int32_t month = in->readByte();
	int32_t dayOfMonth = in->readByte();
	return LocalDate::of(year, month, dayOfMonth);
}

int32_t LocalDate::compareTo(Object$* other) {
	return this->compareTo($cast($ChronoLocalDate, other));
}

LocalDate* LocalDate::lambda$datesUntil$1(int64_t months, int64_t days, int64_t n) {
	return $nc($(this->plusMonths(months * n)))->plusDays(days * n);
}

LocalDate* LocalDate::lambda$datesUntil$0(int64_t start, int64_t days, int64_t n) {
	$init(LocalDate);
	return LocalDate::ofEpochDay(start + n * days);
}

void clinit$LocalDate($Class* class$) {
	$assignStatic(LocalDate::MIN, LocalDate::of($Year::MIN_VALUE, 1, 1));
	$assignStatic(LocalDate::MAX, LocalDate::of($Year::MAX_VALUE, 12, 31));
	$assignStatic(LocalDate::EPOCH, LocalDate::of(1970, 1, 1));
}

LocalDate::LocalDate() {
}

$Class* LocalDate::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LocalDate$$Lambda$from::classInfo$.name)) {
			return LocalDate$$Lambda$from::load$(name, initialize);
		}
		if (name->equals(LocalDate$$Lambda$ofEpochDay$1::classInfo$.name)) {
			return LocalDate$$Lambda$ofEpochDay$1::load$(name, initialize);
		}
		if (name->equals(LocalDate$$Lambda$lambda$datesUntil$0$2::classInfo$.name)) {
			return LocalDate$$Lambda$lambda$datesUntil$0$2::load$(name, initialize);
		}
		if (name->equals(LocalDate$$Lambda$lambda$datesUntil$1$3::classInfo$.name)) {
			return LocalDate$$Lambda$lambda$datesUntil$1$3::load$(name, initialize);
		}
	}
	$loadClass(LocalDate, name, initialize, &_LocalDate_ClassInfo_, clinit$LocalDate, allocate$LocalDate);
	return class$;
}

$Class* LocalDate::class$ = nullptr;

	} // time
} // java