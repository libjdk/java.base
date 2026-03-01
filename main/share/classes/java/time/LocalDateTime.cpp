#include <java/time/LocalDateTime.h>

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
#include <java/time/LocalDate.h>
#include <java/time/LocalDateTime$1.h>
#include <java/time/LocalTime.h>
#include <java/time/Month.h>
#include <java/time/OffsetDateTime.h>
#include <java/time/Period.h>
#include <java/time/Ser.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
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
#include <java/time/temporal/ValueRange.h>
#include <java/time/zone/ZoneRules.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef ISO_LOCAL_DATE_TIME
#undef LOCAL_DATE_TIME_TYPE
#undef MAX
#undef MAX_VALUE
#undef MIN
#undef MIN_VALUE
#undef NANO_OF_SECOND

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $DayOfWeek = ::java::time::DayOfWeek;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalDateTime$1 = ::java::time::LocalDateTime$1;
using $LocalTime = ::java::time::LocalTime;
using $Month = ::java::time::Month;
using $OffsetDateTime = ::java::time::OffsetDateTime;
using $Period = ::java::time::Period;
using $Ser = ::java::time::Ser;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
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
using $ValueRange = ::java::time::temporal::ValueRange;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {

class LocalDateTime$$Lambda$from : public $TemporalQuery {
	$class(LocalDateTime$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(LocalDateTime::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocalDateTime$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LocalDateTime$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LocalDateTime$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo LocalDateTime$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.LocalDateTime$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* LocalDateTime$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(LocalDateTime$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocalDateTime$$Lambda$from::class$ = nullptr;

$CompoundAttribute _LocalDateTime_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _LocalDateTime_FieldInfo_[] = {
	{"MIN", "Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocalDateTime, MIN)},
	{"MAX", "Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocalDateTime, MAX)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LocalDateTime, serialVersionUID)},
	{"date", "Ljava/time/LocalDate;", nullptr, $PRIVATE | $FINAL, $field(LocalDateTime, date)},
	{"time", "Ljava/time/LocalTime;", nullptr, $PRIVATE | $FINAL, $field(LocalDateTime, time)},
	{}
};

$MethodInfo _LocalDateTime_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/time/LocalDate;Ljava/time/LocalTime;)V", nullptr, $PRIVATE, $method(LocalDateTime, init$, void, $LocalDate*, $LocalTime*)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, adjustInto, $Temporal*, $Temporal*)},
	{"atOffset", "(Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, atOffset, $OffsetDateTime*, $ZoneOffset*)},
	{"atZone", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, atZone, $ChronoZonedDateTime*, $ZoneId*)},
	{"compareTo", "(Ljava/time/chrono/ChronoLocalDateTime;)I", "(Ljava/time/chrono/ChronoLocalDateTime<*>;)I", $PUBLIC, $virtualMethod(LocalDateTime, compareTo, int32_t, $ChronoLocalDateTime*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(LocalDateTime, compareTo, int32_t, Object$*)},
	{"compareTo0", "(Ljava/time/LocalDateTime;)I", nullptr, $PRIVATE, $method(LocalDateTime, compareTo0, int32_t, LocalDateTime*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, from, LocalDateTime*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, get, int32_t, $TemporalField*)},
	{"getDayOfMonth", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getDayOfMonth, int32_t)},
	{"getDayOfWeek", "()Ljava/time/DayOfWeek;", nullptr, $PUBLIC, $method(LocalDateTime, getDayOfWeek, $DayOfWeek*)},
	{"getDayOfYear", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getDayOfYear, int32_t)},
	{"getHour", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getHour, int32_t)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, getLong, int64_t, $TemporalField*)},
	{"getMinute", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getMinute, int32_t)},
	{"getMonth", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(LocalDateTime, getMonth, $Month*)},
	{"getMonthValue", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getMonthValue, int32_t)},
	{"getNano", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getNano, int32_t)},
	{"getSecond", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getSecond, int32_t)},
	{"getYear", "()I", nullptr, $PUBLIC, $method(LocalDateTime, getYear, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/chrono/ChronoLocalDateTime;)Z", "(Ljava/time/chrono/ChronoLocalDateTime<*>;)Z", $PUBLIC, $virtualMethod(LocalDateTime, isAfter, bool, $ChronoLocalDateTime*)},
	{"isBefore", "(Ljava/time/chrono/ChronoLocalDateTime;)Z", "(Ljava/time/chrono/ChronoLocalDateTime<*>;)Z", $PUBLIC, $virtualMethod(LocalDateTime, isBefore, bool, $ChronoLocalDateTime*)},
	{"isEqual", "(Ljava/time/chrono/ChronoLocalDateTime;)Z", "(Ljava/time/chrono/ChronoLocalDateTime<*>;)Z", $PUBLIC, $virtualMethod(LocalDateTime, isEqual, bool, $ChronoLocalDateTime*)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, isSupported, bool, $TemporalUnit*)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, minus, LocalDateTime*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, minus, LocalDateTime*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusDays, LocalDateTime*, int64_t)},
	{"minusHours", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusHours, LocalDateTime*, int64_t)},
	{"minusMinutes", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusMinutes, LocalDateTime*, int64_t)},
	{"minusMonths", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusMonths, LocalDateTime*, int64_t)},
	{"minusNanos", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusNanos, LocalDateTime*, int64_t)},
	{"minusSeconds", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusSeconds, LocalDateTime*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusWeeks, LocalDateTime*, int64_t)},
	{"minusYears", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, minusYears, LocalDateTime*, int64_t)},
	{"now", "()Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, now, LocalDateTime*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, now, LocalDateTime*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, now, LocalDateTime*, $Clock*)},
	{"of", "(ILjava/time/Month;III)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, int32_t, $Month*, int32_t, int32_t, int32_t)},
	{"of", "(ILjava/time/Month;IIII)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, int32_t, $Month*, int32_t, int32_t, int32_t, int32_t)},
	{"of", "(ILjava/time/Month;IIIII)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, int32_t, $Month*, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"of", "(IIIII)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"of", "(IIIIII)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"of", "(IIIIIII)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"of", "(Ljava/time/LocalDate;Ljava/time/LocalTime;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, of, LocalDateTime*, $LocalDate*, $LocalTime*)},
	{"ofEpochSecond", "(JILjava/time/ZoneOffset;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, ofEpochSecond, LocalDateTime*, int64_t, int32_t, $ZoneOffset*)},
	{"ofInstant", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, ofInstant, LocalDateTime*, $Instant*, $ZoneId*)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, parse, LocalDateTime*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalDateTime, parse, LocalDateTime*, $CharSequence*, $DateTimeFormatter*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, plus, LocalDateTime*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, plus, LocalDateTime*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusDays, LocalDateTime*, int64_t)},
	{"plusHours", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusHours, LocalDateTime*, int64_t)},
	{"plusMinutes", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusMinutes, LocalDateTime*, int64_t)},
	{"plusMonths", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusMonths, LocalDateTime*, int64_t)},
	{"plusNanos", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusNanos, LocalDateTime*, int64_t)},
	{"plusSeconds", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusSeconds, LocalDateTime*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusWeeks, LocalDateTime*, int64_t)},
	{"plusWithOverflow", "(Ljava/time/LocalDate;JJJJI)Ljava/time/LocalDateTime;", nullptr, $PRIVATE, $method(LocalDateTime, plusWithOverflow, LocalDateTime*, $LocalDate*, int64_t, int64_t, int64_t, int64_t, int32_t)},
	{"plusYears", "(J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, plusYears, LocalDateTime*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(LocalDateTime, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/LocalDateTime;", nullptr, $STATIC, $staticMethod(LocalDateTime, readExternal, LocalDateTime*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(LocalDateTime, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toLocalDate", "()Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, toLocalDate, $ChronoLocalDate*)},
	{"toLocalTime", "()Ljava/time/LocalTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, toLocalTime, $LocalTime*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, toString, $String*)},
	{"truncatedTo", "(Ljava/time/temporal/TemporalUnit;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, truncatedTo, LocalDateTime*, $TemporalUnit*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/LocalDate;Ljava/time/LocalTime;)Ljava/time/LocalDateTime;", nullptr, $PRIVATE, $method(LocalDateTime, with, LocalDateTime*, $LocalDate*, $LocalTime*)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, with, LocalDateTime*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(LocalDateTime, with, LocalDateTime*, $TemporalField*, int64_t)},
	{"withDayOfMonth", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withDayOfMonth, LocalDateTime*, int32_t)},
	{"withDayOfYear", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withDayOfYear, LocalDateTime*, int32_t)},
	{"withHour", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withHour, LocalDateTime*, int32_t)},
	{"withMinute", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withMinute, LocalDateTime*, int32_t)},
	{"withMonth", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withMonth, LocalDateTime*, int32_t)},
	{"withNano", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withNano, LocalDateTime*, int32_t)},
	{"withSecond", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withSecond, LocalDateTime*, int32_t)},
	{"withYear", "(I)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(LocalDateTime, withYear, LocalDateTime*, int32_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(LocalDateTime, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(LocalDateTime, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _LocalDateTime_InnerClassesInfo_[] = {
	{"java.time.LocalDateTime$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _LocalDateTime_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.LocalDateTime",
	"java.lang.Object",
	"java.time.chrono.ChronoLocalDateTime,java.io.Serializable",
	_LocalDateTime_FieldInfo_,
	_LocalDateTime_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalAdjuster;Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/LocalDate;>;Ljava/io/Serializable;",
	nullptr,
	_LocalDateTime_InnerClassesInfo_,
	_LocalDateTime_Annotations_,
	nullptr,
	"java.time.LocalDateTime$1"
};

$Object* allocate$LocalDateTime($Class* clazz) {
	return $of($alloc(LocalDateTime));
}

$Object* LocalDateTime::clone() {
	 return this->$ChronoLocalDateTime::clone();
}

void LocalDateTime::finalize() {
	this->$ChronoLocalDateTime::finalize();
}

LocalDateTime* LocalDateTime::MIN = nullptr;
LocalDateTime* LocalDateTime::MAX = nullptr;

LocalDateTime* LocalDateTime::now() {
	$init(LocalDateTime);
	return now($($Clock::systemDefaultZone()));
}

LocalDateTime* LocalDateTime::now($ZoneId* zone) {
	$init(LocalDateTime);
	return now($($Clock::system(zone)));
}

LocalDateTime* LocalDateTime::now($Clock* clock) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(clock), "clock"_s);
	$var($Instant, now, $nc(clock)->instant());
	$var($ZoneOffset, offset, $nc($($nc($(clock->getZone()))->getRules()))->getOffset(now));
	int64_t var$0 = $nc(now)->getEpochSecond();
	return ofEpochSecond(var$0, now->getNano(), offset);
}

LocalDateTime* LocalDateTime::of(int32_t year, $Month* month, int32_t dayOfMonth, int32_t hour, int32_t minute) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::of(year, month, dayOfMonth));
	$var($LocalTime, time, $LocalTime::of(hour, minute));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::of(int32_t year, $Month* month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::of(year, month, dayOfMonth));
	$var($LocalTime, time, $LocalTime::of(hour, minute, second));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::of(int32_t year, $Month* month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, int32_t nanoOfSecond) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::of(year, month, dayOfMonth));
	$var($LocalTime, time, $LocalTime::of(hour, minute, second, nanoOfSecond));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::of(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::of(year, month, dayOfMonth));
	$var($LocalTime, time, $LocalTime::of(hour, minute));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::of(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::of(year, month, dayOfMonth));
	$var($LocalTime, time, $LocalTime::of(hour, minute, second));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::of(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, int32_t nanoOfSecond) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::of(year, month, dayOfMonth));
	$var($LocalTime, time, $LocalTime::of(hour, minute, second, nanoOfSecond));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::of($LocalDate* date, $LocalTime* time) {
	$init(LocalDateTime);
	$Objects::requireNonNull($of(date), "date"_s);
	$Objects::requireNonNull($of(time), "time"_s);
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::ofInstant($Instant* instant, $ZoneId* zone) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(instant), "instant"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	$var($ZoneRules, rules, $nc(zone)->getRules());
	$var($ZoneOffset, offset, $nc(rules)->getOffset(instant));
	int64_t var$0 = $nc(instant)->getEpochSecond();
	return ofEpochSecond(var$0, instant->getNano(), offset);
}

LocalDateTime* LocalDateTime::ofEpochSecond(int64_t epochSecond, int32_t nanoOfSecond, $ZoneOffset* offset) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(offset), "offset"_s);
	$init($ChronoField);
	$ChronoField::NANO_OF_SECOND->checkValidValue(nanoOfSecond);
	int64_t localSecond = epochSecond + $nc(offset)->getTotalSeconds();
	int64_t localEpochDay = $Math::floorDiv(localSecond, 0x00015180);
	int32_t secsOfDay = $Math::floorMod(localSecond, 0x00015180);
	$var($LocalDate, date, $LocalDate::ofEpochDay(localEpochDay));
	$var($LocalTime, time, $LocalTime::ofNanoOfDay(secsOfDay * (int64_t)1000000000 + nanoOfSecond));
	return $new(LocalDateTime, date, time);
}

LocalDateTime* LocalDateTime::from($TemporalAccessor* temporal) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf(LocalDateTime, temporal)) {
		return $cast(LocalDateTime, temporal);
	} else if ($instanceOf($ZonedDateTime, temporal)) {
		return $cast(LocalDateTime, $nc(($cast($ZonedDateTime, temporal)))->toLocalDateTime());
	} else if ($instanceOf($OffsetDateTime, temporal)) {
		return $nc(($cast($OffsetDateTime, temporal)))->toLocalDateTime();
	}
	try {
		$var($LocalDate, date, $LocalDate::from(temporal));
		$var($LocalTime, time, $LocalTime::from(temporal));
		return $new(LocalDateTime, date, time);
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain LocalDateTime from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

LocalDateTime* LocalDateTime::parse($CharSequence* text) {
	$init(LocalDateTime);
	$init($DateTimeFormatter);
	return parse(text, $DateTimeFormatter::ISO_LOCAL_DATE_TIME);
}

LocalDateTime* LocalDateTime::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(LocalDateTime);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(LocalDateTime, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(LocalDateTime$$Lambda$from))));
}

void LocalDateTime::init$($LocalDate* date, $LocalTime* time) {
	$set(this, date, date);
	$set(this, time, time);
}

LocalDateTime* LocalDateTime::with($LocalDate* newDate, $LocalTime* newTime) {
	if (this->date == newDate && this->time == newTime) {
		return this;
	}
	return $new(LocalDateTime, newDate, newTime);
}

bool LocalDateTime::isSupported($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			bool var$1 = $nc(chronoField)->isDateBased();
			return var$1 || $nc(chronoField)->isTimeBased();
		}
	}
	return field != nullptr && field->isSupportedBy(this);
}

bool LocalDateTime::isSupported($TemporalUnit* unit) {
	return $ChronoLocalDateTime::isSupported(unit);
}

$ValueRange* LocalDateTime::range($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			return ($nc(chronoField)->isTimeBased() ? $nc(this->time)->range(field) : $nc(this->date)->range(field));
		}
	}
	return $nc(field)->rangeRefinedBy(this);
}

int32_t LocalDateTime::get($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			return ($nc(chronoField)->isTimeBased() ? $nc(this->time)->get(field) : $nc(this->date)->get(field));
		}
	}
	return $ChronoLocalDateTime::get(field);
}

int64_t LocalDateTime::getLong($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			return ($nc(chronoField)->isTimeBased() ? $nc(this->time)->getLong(field) : $nc(this->date)->getLong(field));
		}
	}
	return $nc(field)->getFrom(this);
}

$ChronoLocalDate* LocalDateTime::toLocalDate() {
	return this->date;
}

int32_t LocalDateTime::getYear() {
	return $nc(this->date)->getYear();
}

int32_t LocalDateTime::getMonthValue() {
	return $nc(this->date)->getMonthValue();
}

$Month* LocalDateTime::getMonth() {
	return $nc(this->date)->getMonth();
}

int32_t LocalDateTime::getDayOfMonth() {
	return $nc(this->date)->getDayOfMonth();
}

int32_t LocalDateTime::getDayOfYear() {
	return $nc(this->date)->getDayOfYear();
}

$DayOfWeek* LocalDateTime::getDayOfWeek() {
	return $nc(this->date)->getDayOfWeek();
}

$LocalTime* LocalDateTime::toLocalTime() {
	return this->time;
}

int32_t LocalDateTime::getHour() {
	return $nc(this->time)->getHour();
}

int32_t LocalDateTime::getMinute() {
	return $nc(this->time)->getMinute();
}

int32_t LocalDateTime::getSecond() {
	return $nc(this->time)->getSecond();
}

int32_t LocalDateTime::getNano() {
	return $nc(this->time)->getNano();
}

LocalDateTime* LocalDateTime::with($TemporalAdjuster* adjuster) {
	if ($instanceOf($LocalDate, adjuster)) {
		return with($cast($LocalDate, adjuster), this->time);
	} else if ($instanceOf($LocalTime, adjuster)) {
		return with(this->date, $cast($LocalTime, adjuster));
	} else if ($instanceOf(LocalDateTime, adjuster)) {
		return $cast(LocalDateTime, adjuster);
	}
	return $cast(LocalDateTime, $nc(adjuster)->adjustInto(this));
}

LocalDateTime* LocalDateTime::with($TemporalField* field, int64_t newValue) {
	$useLocalCurrentObjectStackCache();
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			if ($nc(chronoField)->isTimeBased()) {
				return with(this->date, $($nc(this->time)->with(field, newValue)));
			} else {
				return with($($nc(this->date)->with(field, newValue)), this->time);
			}
		}
	}
	return $cast(LocalDateTime, $nc(field)->adjustInto(this, newValue));
}

LocalDateTime* LocalDateTime::withYear(int32_t year) {
	return with($($nc(this->date)->withYear(year)), this->time);
}

LocalDateTime* LocalDateTime::withMonth(int32_t month) {
	return with($($nc(this->date)->withMonth(month)), this->time);
}

LocalDateTime* LocalDateTime::withDayOfMonth(int32_t dayOfMonth) {
	return with($($nc(this->date)->withDayOfMonth(dayOfMonth)), this->time);
}

LocalDateTime* LocalDateTime::withDayOfYear(int32_t dayOfYear) {
	return with($($nc(this->date)->withDayOfYear(dayOfYear)), this->time);
}

LocalDateTime* LocalDateTime::withHour(int32_t hour) {
	$var($LocalTime, newTime, $nc(this->time)->withHour(hour));
	return with(this->date, newTime);
}

LocalDateTime* LocalDateTime::withMinute(int32_t minute) {
	$var($LocalTime, newTime, $nc(this->time)->withMinute(minute));
	return with(this->date, newTime);
}

LocalDateTime* LocalDateTime::withSecond(int32_t second) {
	$var($LocalTime, newTime, $nc(this->time)->withSecond(second));
	return with(this->date, newTime);
}

LocalDateTime* LocalDateTime::withNano(int32_t nanoOfSecond) {
	$var($LocalTime, newTime, $nc(this->time)->withNano(nanoOfSecond));
	return with(this->date, newTime);
}

LocalDateTime* LocalDateTime::truncatedTo($TemporalUnit* unit) {
	return with(this->date, $($nc(this->time)->truncatedTo(unit)));
}

LocalDateTime* LocalDateTime::plus($TemporalAmount* amountToAdd) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Period, periodToAdd, nullptr);
		bool var$0 = $instanceOf($Period, amountToAdd);
		if (var$0) {
			$assign(periodToAdd, $cast($Period, amountToAdd));
			var$0 = true;
		}
		if (var$0) {
			return with($($nc(this->date)->plus(periodToAdd)), this->time);
		}
	}
	$Objects::requireNonNull($of(amountToAdd), "amountToAdd"_s);
	return $cast(LocalDateTime, $nc(amountToAdd)->addTo(this));
}

LocalDateTime* LocalDateTime::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			$init($LocalDateTime$1);
			switch ($nc($LocalDateTime$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return plusNanos(amountToAdd);
				}
			case 2:
				{
					return $nc($(plusDays($div(amountToAdd, (int64_t)0x000000141DD76000))))->plusNanos(($mod(amountToAdd, (int64_t)0x000000141DD76000)) * 1000);
				}
			case 3:
				{
					return $nc($(plusDays($div(amountToAdd, (int64_t)86400000))))->plusNanos(($mod(amountToAdd, (int64_t)86400000)) * 0x000F4240);
				}
			case 4:
				{
					return plusSeconds(amountToAdd);
				}
			case 5:
				{
					return plusMinutes(amountToAdd);
				}
			case 6:
				{
					return plusHours(amountToAdd);
				}
			case 7:
				{
					return $nc($(plusDays(amountToAdd / 256)))->plusHours((amountToAdd % 256) * 12);
				}
			}
			return with($($nc(this->date)->plus(amountToAdd, unit)), this->time);
		}
	}
	return $cast(LocalDateTime, $nc(unit)->addTo(this, amountToAdd));
}

LocalDateTime* LocalDateTime::plusYears(int64_t years) {
	$var($LocalDate, newDate, $nc(this->date)->plusYears(years));
	return with(newDate, this->time);
}

LocalDateTime* LocalDateTime::plusMonths(int64_t months) {
	$var($LocalDate, newDate, $nc(this->date)->plusMonths(months));
	return with(newDate, this->time);
}

LocalDateTime* LocalDateTime::plusWeeks(int64_t weeks) {
	$var($LocalDate, newDate, $nc(this->date)->plusWeeks(weeks));
	return with(newDate, this->time);
}

LocalDateTime* LocalDateTime::plusDays(int64_t days) {
	$var($LocalDate, newDate, $nc(this->date)->plusDays(days));
	return with(newDate, this->time);
}

LocalDateTime* LocalDateTime::plusHours(int64_t hours) {
	return plusWithOverflow(this->date, hours, 0, 0, 0, 1);
}

LocalDateTime* LocalDateTime::plusMinutes(int64_t minutes) {
	return plusWithOverflow(this->date, 0, minutes, 0, 0, 1);
}

LocalDateTime* LocalDateTime::plusSeconds(int64_t seconds) {
	return plusWithOverflow(this->date, 0, 0, seconds, 0, 1);
}

LocalDateTime* LocalDateTime::plusNanos(int64_t nanos) {
	return plusWithOverflow(this->date, 0, 0, 0, nanos, 1);
}

LocalDateTime* LocalDateTime::minus($TemporalAmount* amountToSubtract) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Period, periodToSubtract, nullptr);
		bool var$0 = $instanceOf($Period, amountToSubtract);
		if (var$0) {
			$assign(periodToSubtract, $cast($Period, amountToSubtract));
			var$0 = true;
		}
		if (var$0) {
			return with($($nc(this->date)->minus(periodToSubtract)), this->time);
		}
	}
	$Objects::requireNonNull($of(amountToSubtract), "amountToSubtract"_s);
	return $cast(LocalDateTime, $nc(amountToSubtract)->subtractFrom(this));
}

LocalDateTime* LocalDateTime::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus(1, unit) : plus(-amountToSubtract, unit));
}

LocalDateTime* LocalDateTime::minusYears(int64_t years) {
	return (years == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-years));
}

LocalDateTime* LocalDateTime::minusMonths(int64_t months) {
	return (months == $Long::MIN_VALUE ? $nc($(plusMonths($Long::MAX_VALUE)))->plusMonths(1) : plusMonths(-months));
}

LocalDateTime* LocalDateTime::minusWeeks(int64_t weeks) {
	return (weeks == $Long::MIN_VALUE ? $nc($(plusWeeks($Long::MAX_VALUE)))->plusWeeks(1) : plusWeeks(-weeks));
}

LocalDateTime* LocalDateTime::minusDays(int64_t days) {
	return (days == $Long::MIN_VALUE ? $nc($(plusDays($Long::MAX_VALUE)))->plusDays(1) : plusDays(-days));
}

LocalDateTime* LocalDateTime::minusHours(int64_t hours) {
	return plusWithOverflow(this->date, hours, 0, 0, 0, -1);
}

LocalDateTime* LocalDateTime::minusMinutes(int64_t minutes) {
	return plusWithOverflow(this->date, 0, minutes, 0, 0, -1);
}

LocalDateTime* LocalDateTime::minusSeconds(int64_t seconds) {
	return plusWithOverflow(this->date, 0, 0, seconds, 0, -1);
}

LocalDateTime* LocalDateTime::minusNanos(int64_t nanos) {
	return plusWithOverflow(this->date, 0, 0, 0, nanos, -1);
}

LocalDateTime* LocalDateTime::plusWithOverflow($LocalDate* newDate, int64_t hours, int64_t minutes, int64_t seconds, int64_t nanos, int32_t sign) {
	$useLocalCurrentObjectStackCache();
	if ((((hours | minutes) | seconds) | nanos) == 0) {
		return with(newDate, this->time);
	}
	int64_t totDays = $div(nanos, (int64_t)0x00004E94914F0000) + seconds / 0x00015180 + minutes / 1440 + hours / 24;
	totDays *= sign;
	int64_t totNanos = $mod(nanos, (int64_t)0x00004E94914F0000) + (seconds % 0x00015180) * (int64_t)1000000000 + (minutes % 1440) * (int64_t)0x0000000DF8475800 + (hours % 24) * (int64_t)0x0000034630B8A000;
	int64_t curNoD = $nc(this->time)->toNanoOfDay();
	totNanos = totNanos * sign + curNoD;
	totDays += $Math::floorDiv(totNanos, (int64_t)0x00004E94914F0000);
	int64_t newNoD = $Math::floorMod(totNanos, (int64_t)0x00004E94914F0000);
	$var($LocalTime, newTime, newNoD == curNoD ? this->time : $LocalTime::ofNanoOfDay(newNoD));
	return with($($nc(newDate)->plusDays(totDays)), newTime);
}

$Object* LocalDateTime::query($TemporalQuery* query) {
	if (query == $TemporalQueries::localDate()) {
		return $of($of(this->date));
	}
	return $of($ChronoLocalDateTime::query(query));
}

$Temporal* LocalDateTime::adjustInto($Temporal* temporal) {
	return $ChronoLocalDateTime::adjustInto(temporal);
}

int64_t LocalDateTime::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(LocalDateTime, end, LocalDateTime::from(endExclusive));
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			if ($nc(unit)->isTimeBased()) {
				int64_t amount = $nc(this->date)->daysUntil($nc(end)->date);
				if (amount == 0) {
					return $nc(this->time)->until($nc(end)->time, unit);
				}
				int64_t var$1 = $nc($nc(end)->time)->toNanoOfDay();
				int64_t timePart = var$1 - $nc(this->time)->toNanoOfDay();
				if (amount > 0) {
					--amount;
					timePart += 0x00004E94914F0000;
				} else {
					++amount;
					timePart -= 0x00004E94914F0000;
				}
				$init($LocalDateTime$1);
				switch ($nc($LocalDateTime$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
				case 1:
					{
						amount = $Math::multiplyExact(amount, (int64_t)0x00004E94914F0000);
						break;
					}
				case 2:
					{
						amount = $Math::multiplyExact(amount, (int64_t)0x000000141DD76000);
						timePart = timePart / 1000;
						break;
					}
				case 3:
					{
						amount = $Math::multiplyExact(amount, (int64_t)86400000);
						timePart = timePart / 0x000F4240;
						break;
					}
				case 4:
					{
						amount = $Math::multiplyExact(amount, 0x00015180);
						timePart = $div(timePart, (int64_t)1000000000);
						break;
					}
				case 5:
					{
						amount = $Math::multiplyExact(amount, 1440);
						timePart = $div(timePart, (int64_t)0x0000000DF8475800);
						break;
					}
				case 6:
					{
						amount = $Math::multiplyExact(amount, 24);
						timePart = $div(timePart, (int64_t)0x0000034630B8A000);
						break;
					}
				case 7:
					{
						amount = $Math::multiplyExact(amount, 2);
						timePart = $div(timePart, ((int64_t)0x0000034630B8A000 * 12));
						break;
					}
				}
				return $Math::addExact(amount, timePart);
			}
			$var($LocalDate, endDate, $nc(end)->date);
			bool var$2 = $nc(endDate)->isAfter(this->date);
			if (var$2 && $nc(end->time)->isBefore(this->time)) {
				$assign(endDate, endDate->minusDays(1));
			} else {
				bool var$4 = endDate->isBefore(this->date);
				if (var$4 && $nc(end->time)->isAfter(this->time)) {
					$assign(endDate, endDate->plusDays(1));
				}
			}
			return $nc(this->date)->until(endDate, unit);
		}
	}
	return $nc(unit)->between(this, end);
}

$String* LocalDateTime::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$OffsetDateTime* LocalDateTime::atOffset($ZoneOffset* offset) {
	return $OffsetDateTime::of(this, offset);
}

$ChronoZonedDateTime* LocalDateTime::atZone($ZoneId* zone) {
	return $ZonedDateTime::of(this, zone);
}

int32_t LocalDateTime::compareTo($ChronoLocalDateTime* other) {
	if ($instanceOf(LocalDateTime, other)) {
		return compareTo0($cast(LocalDateTime, other));
	}
	return $ChronoLocalDateTime::compareTo(other);
}

int32_t LocalDateTime::compareTo0(LocalDateTime* other) {
	$useLocalCurrentObjectStackCache();
	int32_t cmp = $nc(this->date)->compareTo0($($cast($LocalDate, $nc(other)->toLocalDate())));
	if (cmp == 0) {
		cmp = $nc(this->time)->compareTo($($nc(other)->toLocalTime()));
	}
	return cmp;
}

bool LocalDateTime::isAfter($ChronoLocalDateTime* other) {
	if ($instanceOf(LocalDateTime, other)) {
		return compareTo0($cast(LocalDateTime, other)) > 0;
	}
	return $ChronoLocalDateTime::isAfter(other);
}

bool LocalDateTime::isBefore($ChronoLocalDateTime* other) {
	if ($instanceOf(LocalDateTime, other)) {
		return compareTo0($cast(LocalDateTime, other)) < 0;
	}
	return $ChronoLocalDateTime::isBefore(other);
}

bool LocalDateTime::isEqual($ChronoLocalDateTime* other) {
	if ($instanceOf(LocalDateTime, other)) {
		return compareTo0($cast(LocalDateTime, other)) == 0;
	}
	return $ChronoLocalDateTime::isEqual(other);
}

bool LocalDateTime::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(LocalDateTime, other, nullptr);
	bool var$2 = $instanceOf(LocalDateTime, obj);
	if (var$2) {
		$assign(other, $cast(LocalDateTime, obj));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && $nc(this->date)->equals($nc(other)->date);
	return var$0 && $nc(this->time)->equals($nc(other)->time);
}

int32_t LocalDateTime::hashCode() {
	int32_t var$0 = $nc(this->date)->hashCode();
	return var$0 ^ $nc(this->time)->hashCode();
}

$String* LocalDateTime::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($nc(this->date)->toString()), $$str(u'T')}));
	return $concat(var$0, $($nc(this->time)->toString()));
}

$Object* LocalDateTime::writeReplace() {
	return $of($new($Ser, $Ser::LOCAL_DATE_TIME_TYPE, this));
}

void LocalDateTime::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void LocalDateTime::writeExternal($DataOutput* out) {
	$nc(this->date)->writeExternal(out);
	$nc(this->time)->writeExternal(out);
}

LocalDateTime* LocalDateTime::readExternal($DataInput* in) {
	$init(LocalDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, date, $LocalDate::readExternal(in));
	$var($LocalTime, time, $LocalTime::readExternal(in));
	return LocalDateTime::of(date, time);
}

int32_t LocalDateTime::compareTo(Object$* other) {
	return this->compareTo($cast($ChronoLocalDateTime, other));
}

void clinit$LocalDateTime($Class* class$) {
	$init($LocalDate);
	$init($LocalTime);
	$assignStatic(LocalDateTime::MIN, LocalDateTime::of($LocalDate::MIN, $LocalTime::MIN));
	$assignStatic(LocalDateTime::MAX, LocalDateTime::of($LocalDate::MAX, $LocalTime::MAX));
}

LocalDateTime::LocalDateTime() {
}

$Class* LocalDateTime::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LocalDateTime$$Lambda$from::classInfo$.name)) {
			return LocalDateTime$$Lambda$from::load$(name, initialize);
		}
	}
	$loadClass(LocalDateTime, name, initialize, &_LocalDateTime_ClassInfo_, clinit$LocalDateTime, allocate$LocalDateTime);
	return class$;
}

$Class* LocalDateTime::class$ = nullptr;

	} // time
} // java