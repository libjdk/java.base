#include <java/time/ZonedDateTime.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/DayOfWeek.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalDateTime.h>
#include <java/time/LocalTime.h>
#include <java/time/Month.h>
#include <java/time/OffsetDateTime.h>
#include <java/time/Period.h>
#include <java/time/Ser.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime$1.h>
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
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/time/zone/ZoneOffsetTransition.h>
#include <java/time/zone/ZoneRules.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef INSTANT_SECONDS
#undef ISO_ZONED_DATE_TIME
#undef MAX_VALUE
#undef MIN_VALUE
#undef NANO_OF_SECOND
#undef OFFSET_SECONDS
#undef ZONE_DATE_TIME_TYPE

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $DayOfWeek = ::java::time::DayOfWeek;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalDateTime = ::java::time::LocalDateTime;
using $LocalTime = ::java::time::LocalTime;
using $Month = ::java::time::Month;
using $OffsetDateTime = ::java::time::OffsetDateTime;
using $Period = ::java::time::Period;
using $Ser = ::java::time::Ser;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime$1 = ::java::time::ZonedDateTime$1;
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
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $ZoneOffsetTransition = ::java::time::zone::ZoneOffsetTransition;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {

class ZonedDateTime$$Lambda$from : public $TemporalQuery {
	$class(ZonedDateTime$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(ZonedDateTime::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ZonedDateTime$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ZonedDateTime$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ZonedDateTime$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo ZonedDateTime$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.ZonedDateTime$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* ZonedDateTime$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(ZonedDateTime$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ZonedDateTime$$Lambda$from::class$ = nullptr;

$CompoundAttribute _ZonedDateTime_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _ZonedDateTime_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZonedDateTime, serialVersionUID)},
	{"dateTime", "Ljava/time/LocalDateTime;", nullptr, $PRIVATE | $FINAL, $field(ZonedDateTime, dateTime)},
	{"offset", "Ljava/time/ZoneOffset;", nullptr, $PRIVATE | $FINAL, $field(ZonedDateTime, offset)},
	{"zone", "Ljava/time/ZoneId;", nullptr, $PRIVATE | $FINAL, $field(ZonedDateTime, zone)},
	{}
};

$MethodInfo _ZonedDateTime_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;Ljava/time/ZoneId;)V", nullptr, $PRIVATE, $method(ZonedDateTime, init$, void, $LocalDateTime*, $ZoneOffset*, $ZoneId*)},
	{"create", "(JILjava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PRIVATE | $STATIC, $staticMethod(ZonedDateTime, create, ZonedDateTime*, int64_t, int32_t, $ZoneId*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, from, ZonedDateTime*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, get, int32_t, $TemporalField*)},
	{"getDayOfMonth", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getDayOfMonth, int32_t)},
	{"getDayOfWeek", "()Ljava/time/DayOfWeek;", nullptr, $PUBLIC, $method(ZonedDateTime, getDayOfWeek, $DayOfWeek*)},
	{"getDayOfYear", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getDayOfYear, int32_t)},
	{"getHour", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getHour, int32_t)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, getLong, int64_t, $TemporalField*)},
	{"getMinute", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getMinute, int32_t)},
	{"getMonth", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(ZonedDateTime, getMonth, $Month*)},
	{"getMonthValue", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getMonthValue, int32_t)},
	{"getNano", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getNano, int32_t)},
	{"getOffset", "()Ljava/time/ZoneOffset;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, getOffset, $ZoneOffset*)},
	{"getSecond", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getSecond, int32_t)},
	{"getYear", "()I", nullptr, $PUBLIC, $method(ZonedDateTime, getYear, int32_t)},
	{"getZone", "()Ljava/time/ZoneId;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, getZone, $ZoneId*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, hashCode, int32_t)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, isSupported, bool, $TemporalUnit*)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, minus, ZonedDateTime*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, minus, ZonedDateTime*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusDays, ZonedDateTime*, int64_t)},
	{"minusHours", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusHours, ZonedDateTime*, int64_t)},
	{"minusMinutes", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusMinutes, ZonedDateTime*, int64_t)},
	{"minusMonths", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusMonths, ZonedDateTime*, int64_t)},
	{"minusNanos", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusNanos, ZonedDateTime*, int64_t)},
	{"minusSeconds", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusSeconds, ZonedDateTime*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusWeeks, ZonedDateTime*, int64_t)},
	{"minusYears", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, minusYears, ZonedDateTime*, int64_t)},
	{"now", "()Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, now, ZonedDateTime*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, now, ZonedDateTime*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, now, ZonedDateTime*, $Clock*)},
	{"of", "(Ljava/time/LocalDate;Ljava/time/LocalTime;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, of, ZonedDateTime*, $LocalDate*, $LocalTime*, $ZoneId*)},
	{"of", "(Ljava/time/LocalDateTime;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, of, ZonedDateTime*, $LocalDateTime*, $ZoneId*)},
	{"of", "(IIIIIIILjava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, of, ZonedDateTime*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, $ZoneId*)},
	{"ofInstant", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, ofInstant, ZonedDateTime*, $Instant*, $ZoneId*)},
	{"ofInstant", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, ofInstant, ZonedDateTime*, $LocalDateTime*, $ZoneOffset*, $ZoneId*)},
	{"ofLenient", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PRIVATE | $STATIC, $staticMethod(ZonedDateTime, ofLenient, ZonedDateTime*, $LocalDateTime*, $ZoneOffset*, $ZoneId*)},
	{"ofLocal", "(Ljava/time/LocalDateTime;Ljava/time/ZoneId;Ljava/time/ZoneOffset;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, ofLocal, ZonedDateTime*, $LocalDateTime*, $ZoneId*, $ZoneOffset*)},
	{"ofStrict", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, ofStrict, ZonedDateTime*, $LocalDateTime*, $ZoneOffset*, $ZoneId*)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, parse, ZonedDateTime*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZonedDateTime, parse, ZonedDateTime*, $CharSequence*, $DateTimeFormatter*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, plus, ZonedDateTime*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, plus, ZonedDateTime*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusDays, ZonedDateTime*, int64_t)},
	{"plusHours", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusHours, ZonedDateTime*, int64_t)},
	{"plusMinutes", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusMinutes, ZonedDateTime*, int64_t)},
	{"plusMonths", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusMonths, ZonedDateTime*, int64_t)},
	{"plusNanos", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusNanos, ZonedDateTime*, int64_t)},
	{"plusSeconds", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusSeconds, ZonedDateTime*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusWeeks, ZonedDateTime*, int64_t)},
	{"plusYears", "(J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, plusYears, ZonedDateTime*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(ZonedDateTime, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/ObjectInput;)Ljava/time/ZonedDateTime;", nullptr, $STATIC, $staticMethod(ZonedDateTime, readExternal, ZonedDateTime*, $ObjectInput*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ZonedDateTime, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"resolveInstant", "(Ljava/time/LocalDateTime;)Ljava/time/ZonedDateTime;", nullptr, $PRIVATE, $method(ZonedDateTime, resolveInstant, ZonedDateTime*, $LocalDateTime*)},
	{"resolveLocal", "(Ljava/time/LocalDateTime;)Ljava/time/ZonedDateTime;", nullptr, $PRIVATE, $method(ZonedDateTime, resolveLocal, ZonedDateTime*, $LocalDateTime*)},
	{"resolveOffset", "(Ljava/time/ZoneOffset;)Ljava/time/ZonedDateTime;", nullptr, $PRIVATE, $method(ZonedDateTime, resolveOffset, ZonedDateTime*, $ZoneOffset*)},
	{"toLocalDate", "()Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, toLocalDate, $ChronoLocalDate*)},
	{"toLocalDateTime", "()Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, toLocalDateTime, $ChronoLocalDateTime*)},
	{"toLocalTime", "()Ljava/time/LocalTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, toLocalTime, $LocalTime*)},
	{"toOffsetDateTime", "()Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, toOffsetDateTime, $OffsetDateTime*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, toString, $String*)},
	{"truncatedTo", "(Ljava/time/temporal/TemporalUnit;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, truncatedTo, ZonedDateTime*, $TemporalUnit*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, with, ZonedDateTime*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, with, ZonedDateTime*, $TemporalField*, int64_t)},
	{"withDayOfMonth", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withDayOfMonth, ZonedDateTime*, int32_t)},
	{"withDayOfYear", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withDayOfYear, ZonedDateTime*, int32_t)},
	{"withEarlierOffsetAtOverlap", "()Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, withEarlierOffsetAtOverlap, ZonedDateTime*)},
	{"withFixedOffsetZone", "()Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withFixedOffsetZone, ZonedDateTime*)},
	{"withHour", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withHour, ZonedDateTime*, int32_t)},
	{"withLaterOffsetAtOverlap", "()Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, withLaterOffsetAtOverlap, ZonedDateTime*)},
	{"withMinute", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withMinute, ZonedDateTime*, int32_t)},
	{"withMonth", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withMonth, ZonedDateTime*, int32_t)},
	{"withNano", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withNano, ZonedDateTime*, int32_t)},
	{"withSecond", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withSecond, ZonedDateTime*, int32_t)},
	{"withYear", "(I)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(ZonedDateTime, withYear, ZonedDateTime*, int32_t)},
	{"withZoneSameInstant", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, withZoneSameInstant, ZonedDateTime*, $ZoneId*)},
	{"withZoneSameLocal", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(ZonedDateTime, withZoneSameLocal, ZonedDateTime*, $ZoneId*)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(ZonedDateTime, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(ZonedDateTime, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _ZonedDateTime_InnerClassesInfo_[] = {
	{"java.time.ZonedDateTime$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _ZonedDateTime_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.ZonedDateTime",
	"java.lang.Object",
	"java.time.chrono.ChronoZonedDateTime,java.io.Serializable",
	_ZonedDateTime_FieldInfo_,
	_ZonedDateTime_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/Temporal;Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/LocalDate;>;Ljava/io/Serializable;",
	nullptr,
	_ZonedDateTime_InnerClassesInfo_,
	_ZonedDateTime_Annotations_,
	nullptr,
	"java.time.ZonedDateTime$1"
};

$Object* allocate$ZonedDateTime($Class* clazz) {
	return $of($alloc(ZonedDateTime));
}

$Object* ZonedDateTime::clone() {
	 return this->$ChronoZonedDateTime::clone();
}

void ZonedDateTime::finalize() {
	this->$ChronoZonedDateTime::finalize();
}

ZonedDateTime* ZonedDateTime::now() {
	$init(ZonedDateTime);
	return now($($Clock::systemDefaultZone()));
}

ZonedDateTime* ZonedDateTime::now($ZoneId* zone) {
	$init(ZonedDateTime);
	return now($($Clock::system(zone)));
}

ZonedDateTime* ZonedDateTime::now($Clock* clock) {
	$init(ZonedDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(clock), "clock"_s);
	$var($Instant, now, $nc(clock)->instant());
	return ofInstant(now, $(clock->getZone()));
}

ZonedDateTime* ZonedDateTime::of($LocalDate* date, $LocalTime* time, $ZoneId* zone) {
	$init(ZonedDateTime);
	return of($($LocalDateTime::of(date, time)), zone);
}

ZonedDateTime* ZonedDateTime::of($LocalDateTime* localDateTime, $ZoneId* zone) {
	$init(ZonedDateTime);
	return ofLocal(localDateTime, zone, nullptr);
}

ZonedDateTime* ZonedDateTime::of(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, int32_t nanoOfSecond, $ZoneId* zone) {
	$init(ZonedDateTime);
	$var($LocalDateTime, dt, $LocalDateTime::of(year, month, dayOfMonth, hour, minute, second, nanoOfSecond));
	return ofLocal(dt, zone, nullptr);
}

ZonedDateTime* ZonedDateTime::ofLocal($LocalDateTime* localDateTime$renamed, $ZoneId* zone, $ZoneOffset* preferredOffset) {
	$init(ZonedDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDateTime, localDateTime, localDateTime$renamed);
	$Objects::requireNonNull($of(localDateTime), "localDateTime"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	if ($instanceOf($ZoneOffset, zone)) {
		return $new(ZonedDateTime, localDateTime, $cast($ZoneOffset, zone), zone);
	}
	$var($ZoneRules, rules, $nc(zone)->getRules());
	$var($List, validOffsets, $nc(rules)->getValidOffsets(localDateTime));
	$var($ZoneOffset, offset, nullptr);
	if ($nc(validOffsets)->size() == 1) {
		$assign(offset, $cast($ZoneOffset, validOffsets->get(0)));
	} else if (validOffsets->size() == 0) {
		$var($ZoneOffsetTransition, trans, rules->getTransition(localDateTime));
		$assign(localDateTime, $nc(localDateTime)->plusSeconds($nc($($nc(trans)->getDuration()))->getSeconds()));
		$assign(offset, $nc(trans)->getOffsetAfter());
	} else if (preferredOffset != nullptr && validOffsets->contains(preferredOffset)) {
		$assign(offset, preferredOffset);
	} else {
		$assign(offset, $cast($ZoneOffset, $Objects::requireNonNull($cast($ZoneOffset, $(validOffsets->get(0))), "offset"_s)));
	}
	return $new(ZonedDateTime, localDateTime, offset, zone);
}

ZonedDateTime* ZonedDateTime::ofInstant($Instant* instant, $ZoneId* zone) {
	$init(ZonedDateTime);
	$Objects::requireNonNull($of(instant), "instant"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	int64_t var$0 = $nc(instant)->getEpochSecond();
	return create(var$0, instant->getNano(), zone);
}

ZonedDateTime* ZonedDateTime::ofInstant($LocalDateTime* localDateTime, $ZoneOffset* offset, $ZoneId* zone) {
	$init(ZonedDateTime);
	$Objects::requireNonNull($of(localDateTime), "localDateTime"_s);
	$Objects::requireNonNull($of(offset), "offset"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	if ($nc($($nc(zone)->getRules()))->isValidOffset(localDateTime, offset)) {
		return $new(ZonedDateTime, localDateTime, offset, zone);
	}
	int64_t var$0 = $nc(localDateTime)->toEpochSecond(offset);
	return create(var$0, localDateTime->getNano(), zone);
}

ZonedDateTime* ZonedDateTime::create(int64_t epochSecond, int32_t nanoOfSecond, $ZoneId* zone) {
	$init(ZonedDateTime);
	$useLocalCurrentObjectStackCache();
	$var($ZoneRules, rules, $nc(zone)->getRules());
	$var($Instant, instant, $Instant::ofEpochSecond(epochSecond, nanoOfSecond));
	$var($ZoneOffset, offset, $nc(rules)->getOffset(instant));
	$var($LocalDateTime, ldt, $LocalDateTime::ofEpochSecond(epochSecond, nanoOfSecond, offset));
	return $new(ZonedDateTime, ldt, offset, zone);
}

ZonedDateTime* ZonedDateTime::ofStrict($LocalDateTime* localDateTime, $ZoneOffset* offset, $ZoneId* zone) {
	$init(ZonedDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(localDateTime), "localDateTime"_s);
	$Objects::requireNonNull($of(offset), "offset"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	$var($ZoneRules, rules, $nc(zone)->getRules());
	if ($nc(rules)->isValidOffset(localDateTime, offset) == false) {
		$var($ZoneOffsetTransition, trans, rules->getTransition(localDateTime));
		if (trans != nullptr && trans->isGap()) {
			$throwNew($DateTimeException, $$str({"LocalDateTime \'"_s, localDateTime, "\' does not exist in zone \'"_s, zone, "\' due to a gap in the local time-line, typically caused by daylight savings"_s}));
		}
		$throwNew($DateTimeException, $$str({"ZoneOffset \'"_s, offset, "\' is not valid for LocalDateTime \'"_s, localDateTime, "\' in zone \'"_s, zone, "\'"_s}));
	}
	return $new(ZonedDateTime, localDateTime, offset, zone);
}

ZonedDateTime* ZonedDateTime::ofLenient($LocalDateTime* localDateTime, $ZoneOffset* offset, $ZoneId* zone) {
	$init(ZonedDateTime);
	$Objects::requireNonNull($of(localDateTime), "localDateTime"_s);
	$Objects::requireNonNull($of(offset), "offset"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	if ($instanceOf($ZoneOffset, zone) && $nc(offset)->equals(zone) == false) {
		$throwNew($IllegalArgumentException, "ZoneId must match ZoneOffset"_s);
	}
	return $new(ZonedDateTime, localDateTime, offset, zone);
}

ZonedDateTime* ZonedDateTime::from($TemporalAccessor* temporal) {
	$init(ZonedDateTime);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf(ZonedDateTime, temporal)) {
		return $cast(ZonedDateTime, temporal);
	}
	try {
		$var($ZoneId, zone, $ZoneId::from(temporal));
		$init($ChronoField);
		if ($nc(temporal)->isSupported($ChronoField::INSTANT_SECONDS)) {
			int64_t epochSecond = temporal->getLong($ChronoField::INSTANT_SECONDS);
			int32_t nanoOfSecond = temporal->get($ChronoField::NANO_OF_SECOND);
			return create(epochSecond, nanoOfSecond, zone);
		} else {
			$var($LocalDate, date, $LocalDate::from(temporal));
			$var($LocalTime, time, $LocalTime::from(temporal));
			return of(date, time, zone);
		}
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain ZonedDateTime from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

ZonedDateTime* ZonedDateTime::parse($CharSequence* text) {
	$init(ZonedDateTime);
	$init($DateTimeFormatter);
	return parse(text, $DateTimeFormatter::ISO_ZONED_DATE_TIME);
}

ZonedDateTime* ZonedDateTime::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(ZonedDateTime);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(ZonedDateTime, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(ZonedDateTime$$Lambda$from))));
}

void ZonedDateTime::init$($LocalDateTime* dateTime, $ZoneOffset* offset, $ZoneId* zone) {
	$set(this, dateTime, dateTime);
	$set(this, offset, offset);
	$set(this, zone, zone);
}

ZonedDateTime* ZonedDateTime::resolveLocal($LocalDateTime* newDateTime) {
	return ofLocal(newDateTime, this->zone, this->offset);
}

ZonedDateTime* ZonedDateTime::resolveInstant($LocalDateTime* newDateTime) {
	return ofInstant(newDateTime, this->offset, this->zone);
}

ZonedDateTime* ZonedDateTime::resolveOffset($ZoneOffset* offset) {
	bool var$0 = $nc(offset)->equals(this->offset) == false;
	if (var$0 && $nc($($nc(this->zone)->getRules()))->isValidOffset(this->dateTime, offset)) {
		return $new(ZonedDateTime, this->dateTime, offset, this->zone);
	}
	return this;
}

bool ZonedDateTime::isSupported($TemporalField* field) {
	return $instanceOf($ChronoField, field) || (field != nullptr && field->isSupportedBy(this));
}

bool ZonedDateTime::isSupported($TemporalUnit* unit) {
	return $ChronoZonedDateTime::isSupported(unit);
}

$ValueRange* ZonedDateTime::range($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		if ($equals(field, $ChronoField::INSTANT_SECONDS) || $equals(field, $ChronoField::OFFSET_SECONDS)) {
			return field->range();
		}
		return $nc(this->dateTime)->range(field);
	}
	return $nc(field)->rangeRefinedBy(this);
}

int32_t ZonedDateTime::get($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($ZonedDateTime$1);
			switch ($nc($ZonedDateTime$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 1:
				{
					$throwNew($UnsupportedTemporalTypeException, "Invalid field \'InstantSeconds\' for get() method, use getLong() instead"_s);
				}
			case 2:
				{
					return $nc($(getOffset()))->getTotalSeconds();
				}
			}
			return $nc(this->dateTime)->get(field);
		}
	}
	return $ChronoZonedDateTime::get(field);
}

int64_t ZonedDateTime::getLong($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($ZonedDateTime$1);
			switch ($nc($ZonedDateTime$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 1:
				{
					return toEpochSecond();
				}
			case 2:
				{
					return $nc($(getOffset()))->getTotalSeconds();
				}
			}
			return $nc(this->dateTime)->getLong(field);
		}
	}
	return $nc(field)->getFrom(this);
}

$ZoneOffset* ZonedDateTime::getOffset() {
	return this->offset;
}

ZonedDateTime* ZonedDateTime::withEarlierOffsetAtOverlap() {
	$useLocalCurrentObjectStackCache();
	$var($ZoneOffsetTransition, trans, $nc($($nc($(getZone()))->getRules()))->getTransition(this->dateTime));
	if (trans != nullptr && trans->isOverlap()) {
		$var($ZoneOffset, earlierOffset, trans->getOffsetBefore());
		if ($nc(earlierOffset)->equals(this->offset) == false) {
			return $new(ZonedDateTime, this->dateTime, earlierOffset, this->zone);
		}
	}
	return this;
}

ZonedDateTime* ZonedDateTime::withLaterOffsetAtOverlap() {
	$useLocalCurrentObjectStackCache();
	$var($ZoneOffsetTransition, trans, $nc($($nc($(getZone()))->getRules()))->getTransition($($cast($LocalDateTime, toLocalDateTime()))));
	if (trans != nullptr) {
		$var($ZoneOffset, laterOffset, trans->getOffsetAfter());
		if ($nc(laterOffset)->equals(this->offset) == false) {
			return $new(ZonedDateTime, this->dateTime, laterOffset, this->zone);
		}
	}
	return this;
}

$ZoneId* ZonedDateTime::getZone() {
	return this->zone;
}

ZonedDateTime* ZonedDateTime::withZoneSameLocal($ZoneId* zone) {
	$Objects::requireNonNull($of(zone), "zone"_s);
	return $nc(this->zone)->equals(zone) ? this : ofLocal(this->dateTime, zone, this->offset);
}

ZonedDateTime* ZonedDateTime::withZoneSameInstant($ZoneId* zone) {
	$Objects::requireNonNull($of(zone), "zone"_s);
	$var(ZonedDateTime, var$0, nullptr);
	if ($nc(this->zone)->equals(zone)) {
		$assign(var$0, this);
	} else {
		int64_t var$1 = $nc(this->dateTime)->toEpochSecond(this->offset);
		$assign(var$0, create(var$1, $nc(this->dateTime)->getNano(), zone));
	}
	return var$0;
}

ZonedDateTime* ZonedDateTime::withFixedOffsetZone() {
	return $nc(this->zone)->equals(this->offset) ? this : $new(ZonedDateTime, this->dateTime, this->offset, this->offset);
}

$ChronoLocalDateTime* ZonedDateTime::toLocalDateTime() {
	return this->dateTime;
}

$ChronoLocalDate* ZonedDateTime::toLocalDate() {
	return $nc(this->dateTime)->toLocalDate();
}

int32_t ZonedDateTime::getYear() {
	return $nc(this->dateTime)->getYear();
}

int32_t ZonedDateTime::getMonthValue() {
	return $nc(this->dateTime)->getMonthValue();
}

$Month* ZonedDateTime::getMonth() {
	return $nc(this->dateTime)->getMonth();
}

int32_t ZonedDateTime::getDayOfMonth() {
	return $nc(this->dateTime)->getDayOfMonth();
}

int32_t ZonedDateTime::getDayOfYear() {
	return $nc(this->dateTime)->getDayOfYear();
}

$DayOfWeek* ZonedDateTime::getDayOfWeek() {
	return $nc(this->dateTime)->getDayOfWeek();
}

$LocalTime* ZonedDateTime::toLocalTime() {
	return $nc(this->dateTime)->toLocalTime();
}

int32_t ZonedDateTime::getHour() {
	return $nc(this->dateTime)->getHour();
}

int32_t ZonedDateTime::getMinute() {
	return $nc(this->dateTime)->getMinute();
}

int32_t ZonedDateTime::getSecond() {
	return $nc(this->dateTime)->getSecond();
}

int32_t ZonedDateTime::getNano() {
	return $nc(this->dateTime)->getNano();
}

ZonedDateTime* ZonedDateTime::with($TemporalAdjuster* adjuster) {
	$useLocalCurrentObjectStackCache();
	{
		$var($OffsetDateTime, odt, nullptr);
		$var($Instant, instant, nullptr);
		if ($instanceOf($LocalDate, adjuster)) {
			return resolveLocal($($LocalDateTime::of($cast($LocalDate, adjuster), $($nc(this->dateTime)->toLocalTime()))));
		} else if ($instanceOf($LocalTime, adjuster)) {
			return resolveLocal($($LocalDateTime::of($($cast($LocalDate, $nc(this->dateTime)->toLocalDate())), $cast($LocalTime, adjuster))));
		} else if ($instanceOf($LocalDateTime, adjuster)) {
			return resolveLocal($cast($LocalDateTime, adjuster));
		} else {
			bool var$1 = $instanceOf($OffsetDateTime, adjuster);
			if (var$1) {
				$assign(odt, $cast($OffsetDateTime, adjuster));
				var$1 = true;
			}
			if (var$1) {
				$var($LocalDateTime, var$2, $nc(odt)->toLocalDateTime());
				$var($ZoneId, var$3, this->zone);
				return ofLocal(var$2, var$3, $(odt->getOffset()));
			} else {
				bool var$5 = $instanceOf($Instant, adjuster);
				if (var$5) {
					$assign(instant, $cast($Instant, adjuster));
					var$5 = true;
				}
				if (var$5) {
					int64_t var$6 = $nc(instant)->getEpochSecond();
					return create(var$6, instant->getNano(), this->zone);
				} else if ($instanceOf($ZoneOffset, adjuster)) {
					return resolveOffset($cast($ZoneOffset, adjuster));
				}
			}
		}
	}
	return $cast(ZonedDateTime, $nc(adjuster)->adjustInto(this));
}

ZonedDateTime* ZonedDateTime::with($TemporalField* field, int64_t newValue) {
	$useLocalCurrentObjectStackCache();
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($ZonedDateTime$1);
			{
				$var($ZoneOffset, offset, nullptr)
				switch ($nc($ZonedDateTime$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
				case 1:
					{
						return create(newValue, getNano(), this->zone);
					}
				case 2:
					{
						$assign(offset, $ZoneOffset::ofTotalSeconds(chronoField->checkValidIntValue(newValue)));
						return resolveOffset(offset);
					}
				}
			}
			return resolveLocal($($nc(this->dateTime)->with(field, newValue)));
		}
	}
	return $cast(ZonedDateTime, $nc(field)->adjustInto(this, newValue));
}

ZonedDateTime* ZonedDateTime::withYear(int32_t year) {
	return resolveLocal($($nc(this->dateTime)->withYear(year)));
}

ZonedDateTime* ZonedDateTime::withMonth(int32_t month) {
	return resolveLocal($($nc(this->dateTime)->withMonth(month)));
}

ZonedDateTime* ZonedDateTime::withDayOfMonth(int32_t dayOfMonth) {
	return resolveLocal($($nc(this->dateTime)->withDayOfMonth(dayOfMonth)));
}

ZonedDateTime* ZonedDateTime::withDayOfYear(int32_t dayOfYear) {
	return resolveLocal($($nc(this->dateTime)->withDayOfYear(dayOfYear)));
}

ZonedDateTime* ZonedDateTime::withHour(int32_t hour) {
	return resolveLocal($($nc(this->dateTime)->withHour(hour)));
}

ZonedDateTime* ZonedDateTime::withMinute(int32_t minute) {
	return resolveLocal($($nc(this->dateTime)->withMinute(minute)));
}

ZonedDateTime* ZonedDateTime::withSecond(int32_t second) {
	return resolveLocal($($nc(this->dateTime)->withSecond(second)));
}

ZonedDateTime* ZonedDateTime::withNano(int32_t nanoOfSecond) {
	return resolveLocal($($nc(this->dateTime)->withNano(nanoOfSecond)));
}

ZonedDateTime* ZonedDateTime::truncatedTo($TemporalUnit* unit) {
	return resolveLocal($($nc(this->dateTime)->truncatedTo(unit)));
}

ZonedDateTime* ZonedDateTime::plus($TemporalAmount* amountToAdd) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Period, periodToAdd, nullptr);
		bool var$0 = $instanceOf($Period, amountToAdd);
		if (var$0) {
			$assign(periodToAdd, $cast($Period, amountToAdd));
			var$0 = true;
		}
		if (var$0) {
			return resolveLocal($($nc(this->dateTime)->plus(periodToAdd)));
		}
	}
	$Objects::requireNonNull($of(amountToAdd), "amountToAdd"_s);
	return $cast(ZonedDateTime, $nc(amountToAdd)->addTo(this));
}

ZonedDateTime* ZonedDateTime::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoUnit, unit)) {
		if ($nc(unit)->isDateBased()) {
			return resolveLocal($($nc(this->dateTime)->plus(amountToAdd, unit)));
		} else {
			return resolveInstant($($nc(this->dateTime)->plus(amountToAdd, unit)));
		}
	}
	return $cast(ZonedDateTime, $nc(unit)->addTo(this, amountToAdd));
}

ZonedDateTime* ZonedDateTime::plusYears(int64_t years) {
	return resolveLocal($($nc(this->dateTime)->plusYears(years)));
}

ZonedDateTime* ZonedDateTime::plusMonths(int64_t months) {
	return resolveLocal($($nc(this->dateTime)->plusMonths(months)));
}

ZonedDateTime* ZonedDateTime::plusWeeks(int64_t weeks) {
	return resolveLocal($($nc(this->dateTime)->plusWeeks(weeks)));
}

ZonedDateTime* ZonedDateTime::plusDays(int64_t days) {
	return resolveLocal($($nc(this->dateTime)->plusDays(days)));
}

ZonedDateTime* ZonedDateTime::plusHours(int64_t hours) {
	return resolveInstant($($nc(this->dateTime)->plusHours(hours)));
}

ZonedDateTime* ZonedDateTime::plusMinutes(int64_t minutes) {
	return resolveInstant($($nc(this->dateTime)->plusMinutes(minutes)));
}

ZonedDateTime* ZonedDateTime::plusSeconds(int64_t seconds) {
	return resolveInstant($($nc(this->dateTime)->plusSeconds(seconds)));
}

ZonedDateTime* ZonedDateTime::plusNanos(int64_t nanos) {
	return resolveInstant($($nc(this->dateTime)->plusNanos(nanos)));
}

ZonedDateTime* ZonedDateTime::minus($TemporalAmount* amountToSubtract) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Period, periodToSubtract, nullptr);
		bool var$0 = $instanceOf($Period, amountToSubtract);
		if (var$0) {
			$assign(periodToSubtract, $cast($Period, amountToSubtract));
			var$0 = true;
		}
		if (var$0) {
			return resolveLocal($($nc(this->dateTime)->minus(periodToSubtract)));
		}
	}
	$Objects::requireNonNull($of(amountToSubtract), "amountToSubtract"_s);
	return $cast(ZonedDateTime, $nc(amountToSubtract)->subtractFrom(this));
}

ZonedDateTime* ZonedDateTime::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus(1, unit) : plus(-amountToSubtract, unit));
}

ZonedDateTime* ZonedDateTime::minusYears(int64_t years) {
	return (years == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-years));
}

ZonedDateTime* ZonedDateTime::minusMonths(int64_t months) {
	return (months == $Long::MIN_VALUE ? $nc($(plusMonths($Long::MAX_VALUE)))->plusMonths(1) : plusMonths(-months));
}

ZonedDateTime* ZonedDateTime::minusWeeks(int64_t weeks) {
	return (weeks == $Long::MIN_VALUE ? $nc($(plusWeeks($Long::MAX_VALUE)))->plusWeeks(1) : plusWeeks(-weeks));
}

ZonedDateTime* ZonedDateTime::minusDays(int64_t days) {
	return (days == $Long::MIN_VALUE ? $nc($(plusDays($Long::MAX_VALUE)))->plusDays(1) : plusDays(-days));
}

ZonedDateTime* ZonedDateTime::minusHours(int64_t hours) {
	return (hours == $Long::MIN_VALUE ? $nc($(plusHours($Long::MAX_VALUE)))->plusHours(1) : plusHours(-hours));
}

ZonedDateTime* ZonedDateTime::minusMinutes(int64_t minutes) {
	return (minutes == $Long::MIN_VALUE ? $nc($(plusMinutes($Long::MAX_VALUE)))->plusMinutes(1) : plusMinutes(-minutes));
}

ZonedDateTime* ZonedDateTime::minusSeconds(int64_t seconds) {
	return (seconds == $Long::MIN_VALUE ? $nc($(plusSeconds($Long::MAX_VALUE)))->plusSeconds(1) : plusSeconds(-seconds));
}

ZonedDateTime* ZonedDateTime::minusNanos(int64_t nanos) {
	return (nanos == $Long::MIN_VALUE ? $nc($(plusNanos($Long::MAX_VALUE)))->plusNanos(1) : plusNanos(-nanos));
}

$Object* ZonedDateTime::query($TemporalQuery* query) {
	if (query == $TemporalQueries::localDate()) {
		return $of($of($cast($LocalDate, toLocalDate())));
	}
	return $of($ChronoZonedDateTime::query(query));
}

int64_t ZonedDateTime::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(ZonedDateTime, end, ZonedDateTime::from(endExclusive));
	if ($instanceOf($ChronoUnit, unit)) {
		$var(ZonedDateTime, start, this);
		try {
			$assign(end, $nc(end)->withZoneSameInstant(this->zone));
		} catch ($DateTimeException& ex) {
			$assign(start, withZoneSameInstant($nc(end)->zone));
		}
		if ($nc(unit)->isDateBased()) {
			return $nc(start->dateTime)->until($nc(end)->dateTime, unit);
		} else {
			return $nc($(start->toOffsetDateTime()))->until($($nc(end)->toOffsetDateTime()), unit);
		}
	}
	return $nc(unit)->between(this, end);
}

$String* ZonedDateTime::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$OffsetDateTime* ZonedDateTime::toOffsetDateTime() {
	return $OffsetDateTime::of(this->dateTime, this->offset);
}

bool ZonedDateTime::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(ZonedDateTime, other, nullptr);
	bool var$3 = $instanceOf(ZonedDateTime, obj);
	if (var$3) {
		$assign(other, $cast(ZonedDateTime, obj));
		var$3 = true;
	}
	bool var$2 = var$3;
	bool var$1 = var$2 && $nc(this->dateTime)->equals($nc(other)->dateTime);
	bool var$0 = var$1 && $nc(this->offset)->equals($nc(other)->offset);
	return var$0 && $nc(this->zone)->equals($nc(other)->zone);
}

int32_t ZonedDateTime::hashCode() {
	int32_t var$1 = $nc(this->dateTime)->hashCode();
	int32_t var$0 = var$1 ^ $nc(this->offset)->hashCode();
	return var$0 ^ $Integer::rotateLeft($nc(this->zone)->hashCode(), 3);
}

$String* ZonedDateTime::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $($nc(this->dateTime)->toString()));
	$var($String, str, $concat(var$0, $($nc(this->offset)->toString())));
	if (!$equals(this->offset, this->zone)) {
		$plusAssign(str, $$str({$$str(u'['), $($nc(this->zone)->toString()), $$str(u']')}));
	}
	return str;
}

$Object* ZonedDateTime::writeReplace() {
	return $of($new($Ser, $Ser::ZONE_DATE_TIME_TYPE, this));
}

void ZonedDateTime::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void ZonedDateTime::writeExternal($DataOutput* out) {
	$nc(this->dateTime)->writeExternal(out);
	$nc(this->offset)->writeExternal(out);
	$nc(this->zone)->write(out);
}

ZonedDateTime* ZonedDateTime::readExternal($ObjectInput* in) {
	$init(ZonedDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDateTime, dateTime, $LocalDateTime::readExternal(in));
	$var($ZoneOffset, offset, $ZoneOffset::readExternal(in));
	$var($ZoneId, zone, $cast($ZoneId, $Ser::read(in)));
	return ZonedDateTime::ofLenient(dateTime, offset, zone);
}

ZonedDateTime::ZonedDateTime() {
}

$Class* ZonedDateTime::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ZonedDateTime$$Lambda$from::classInfo$.name)) {
			return ZonedDateTime$$Lambda$from::load$(name, initialize);
		}
	}
	$loadClass(ZonedDateTime, name, initialize, &_ZonedDateTime_ClassInfo_, allocate$ZonedDateTime);
	return class$;
}

$Class* ZonedDateTime::class$ = nullptr;

	} // time
} // java