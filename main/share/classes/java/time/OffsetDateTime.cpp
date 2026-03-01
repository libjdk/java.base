#include <java/time/OffsetDateTime.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutput.h>
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
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalDateTime.h>
#include <java/time/LocalTime.h>
#include <java/time/Month.h>
#include <java/time/OffsetDateTime$1.h>
#include <java/time/OffsetTime.h>
#include <java/time/Ser.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/IsoChronology.h>
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
#include <java/time/zone/ZoneRules.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef EPOCH_DAY
#undef FOREVER
#undef INSTANCE
#undef INSTANT_SECONDS
#undef ISO_OFFSET_DATE_TIME
#undef MAX
#undef MAX_VALUE
#undef MIN
#undef MIN_VALUE
#undef NANOS
#undef NANO_OF_DAY
#undef OFFSET_DATE_TIME_TYPE
#undef OFFSET_SECONDS

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutput = ::java::io::ObjectOutput;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $DayOfWeek = ::java::time::DayOfWeek;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalDateTime = ::java::time::LocalDateTime;
using $LocalTime = ::java::time::LocalTime;
using $Month = ::java::time::Month;
using $OffsetDateTime$1 = ::java::time::OffsetDateTime$1;
using $OffsetTime = ::java::time::OffsetTime;
using $Ser = ::java::time::Ser;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $IsoChronology = ::java::time::chrono::IsoChronology;
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
using $ZoneRules = ::java::time::zone::ZoneRules;
using $Comparator = ::java::util::Comparator;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {

class OffsetDateTime$$Lambda$compareInstant : public $Comparator {
	$class(OffsetDateTime$$Lambda$compareInstant, $NO_CLASS_INIT, $Comparator)
public:
	void init$() {
	}
	virtual int32_t compare(Object$* datetime1, Object$* datetime2) override {
		 return OffsetDateTime::compareInstant($cast(OffsetDateTime, datetime1), $cast(OffsetDateTime, datetime2));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<OffsetDateTime$$Lambda$compareInstant>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo OffsetDateTime$$Lambda$compareInstant::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(OffsetDateTime$$Lambda$compareInstant, init$, void)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime$$Lambda$compareInstant, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo OffsetDateTime$$Lambda$compareInstant::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.OffsetDateTime$$Lambda$compareInstant",
	"java.lang.Object",
	"java.util.Comparator",
	nullptr,
	methodInfos
};
$Class* OffsetDateTime$$Lambda$compareInstant::load$($String* name, bool initialize) {
	$loadClass(OffsetDateTime$$Lambda$compareInstant, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* OffsetDateTime$$Lambda$compareInstant::class$ = nullptr;

class OffsetDateTime$$Lambda$from$1 : public $TemporalQuery {
	$class(OffsetDateTime$$Lambda$from$1, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(OffsetDateTime::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<OffsetDateTime$$Lambda$from$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo OffsetDateTime$$Lambda$from$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(OffsetDateTime$$Lambda$from$1, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime$$Lambda$from$1, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo OffsetDateTime$$Lambda$from$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.OffsetDateTime$$Lambda$from$1",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* OffsetDateTime$$Lambda$from$1::load$($String* name, bool initialize) {
	$loadClass(OffsetDateTime$$Lambda$from$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* OffsetDateTime$$Lambda$from$1::class$ = nullptr;

$CompoundAttribute _OffsetDateTime_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _OffsetDateTime_FieldInfo_[] = {
	{"MIN", "Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(OffsetDateTime, MIN)},
	{"MAX", "Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(OffsetDateTime, MAX)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OffsetDateTime, serialVersionUID)},
	{"dateTime", "Ljava/time/LocalDateTime;", nullptr, $PRIVATE | $FINAL, $field(OffsetDateTime, dateTime)},
	{"offset", "Ljava/time/ZoneOffset;", nullptr, $PRIVATE | $FINAL, $field(OffsetDateTime, offset)},
	{}
};

$MethodInfo _OffsetDateTime_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;)V", nullptr, $PRIVATE, $method(OffsetDateTime, init$, void, $LocalDateTime*, $ZoneOffset*)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, adjustInto, $Temporal*, $Temporal*)},
	{"atZoneSameInstant", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, atZoneSameInstant, $ZonedDateTime*, $ZoneId*)},
	{"atZoneSimilarLocal", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, atZoneSimilarLocal, $ZonedDateTime*, $ZoneId*)},
	{"compareInstant", "(Ljava/time/OffsetDateTime;Ljava/time/OffsetDateTime;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(OffsetDateTime, compareInstant, int32_t, OffsetDateTime*, OffsetDateTime*)},
	{"compareTo", "(Ljava/time/OffsetDateTime;)I", nullptr, $PUBLIC, $method(OffsetDateTime, compareTo, int32_t, OffsetDateTime*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(OffsetDateTime, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $method(OffsetDateTime, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, from, OffsetDateTime*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, get, int32_t, $TemporalField*)},
	{"getDayOfMonth", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getDayOfMonth, int32_t)},
	{"getDayOfWeek", "()Ljava/time/DayOfWeek;", nullptr, $PUBLIC, $method(OffsetDateTime, getDayOfWeek, $DayOfWeek*)},
	{"getDayOfYear", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getDayOfYear, int32_t)},
	{"getHour", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getHour, int32_t)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, getLong, int64_t, $TemporalField*)},
	{"getMinute", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getMinute, int32_t)},
	{"getMonth", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(OffsetDateTime, getMonth, $Month*)},
	{"getMonthValue", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getMonthValue, int32_t)},
	{"getNano", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getNano, int32_t)},
	{"getOffset", "()Ljava/time/ZoneOffset;", nullptr, $PUBLIC, $method(OffsetDateTime, getOffset, $ZoneOffset*)},
	{"getSecond", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getSecond, int32_t)},
	{"getYear", "()I", nullptr, $PUBLIC, $method(OffsetDateTime, getYear, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/OffsetDateTime;)Z", nullptr, $PUBLIC, $method(OffsetDateTime, isAfter, bool, OffsetDateTime*)},
	{"isBefore", "(Ljava/time/OffsetDateTime;)Z", nullptr, $PUBLIC, $method(OffsetDateTime, isBefore, bool, OffsetDateTime*)},
	{"isEqual", "(Ljava/time/OffsetDateTime;)Z", nullptr, $PUBLIC, $method(OffsetDateTime, isEqual, bool, OffsetDateTime*)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, isSupported, bool, $TemporalUnit*)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, minus, OffsetDateTime*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, minus, OffsetDateTime*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusDays, OffsetDateTime*, int64_t)},
	{"minusHours", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusHours, OffsetDateTime*, int64_t)},
	{"minusMinutes", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusMinutes, OffsetDateTime*, int64_t)},
	{"minusMonths", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusMonths, OffsetDateTime*, int64_t)},
	{"minusNanos", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusNanos, OffsetDateTime*, int64_t)},
	{"minusSeconds", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusSeconds, OffsetDateTime*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusWeeks, OffsetDateTime*, int64_t)},
	{"minusYears", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, minusYears, OffsetDateTime*, int64_t)},
	{"now", "()Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, now, OffsetDateTime*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, now, OffsetDateTime*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, now, OffsetDateTime*, $Clock*)},
	{"of", "(Ljava/time/LocalDate;Ljava/time/LocalTime;Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, of, OffsetDateTime*, $LocalDate*, $LocalTime*, $ZoneOffset*)},
	{"of", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, of, OffsetDateTime*, $LocalDateTime*, $ZoneOffset*)},
	{"of", "(IIIIIIILjava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, of, OffsetDateTime*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, $ZoneOffset*)},
	{"ofInstant", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, ofInstant, OffsetDateTime*, $Instant*, $ZoneId*)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, parse, OffsetDateTime*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, parse, OffsetDateTime*, $CharSequence*, $DateTimeFormatter*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, plus, OffsetDateTime*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, plus, OffsetDateTime*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusDays, OffsetDateTime*, int64_t)},
	{"plusHours", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusHours, OffsetDateTime*, int64_t)},
	{"plusMinutes", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusMinutes, OffsetDateTime*, int64_t)},
	{"plusMonths", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusMonths, OffsetDateTime*, int64_t)},
	{"plusNanos", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusNanos, OffsetDateTime*, int64_t)},
	{"plusSeconds", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusSeconds, OffsetDateTime*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusWeeks, OffsetDateTime*, int64_t)},
	{"plusYears", "(J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, plusYears, OffsetDateTime*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(OffsetDateTime, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/ObjectInput;)Ljava/time/OffsetDateTime;", nullptr, $STATIC, $staticMethod(OffsetDateTime, readExternal, OffsetDateTime*, $ObjectInput*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(OffsetDateTime, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"timeLineOrder", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<Ljava/time/OffsetDateTime;>;", $PUBLIC | $STATIC, $staticMethod(OffsetDateTime, timeLineOrder, $Comparator*)},
	{"toEpochSecond", "()J", nullptr, $PUBLIC, $method(OffsetDateTime, toEpochSecond, int64_t)},
	{"toInstant", "()Ljava/time/Instant;", nullptr, $PUBLIC, $method(OffsetDateTime, toInstant, $Instant*)},
	{"toLocalDate", "()Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(OffsetDateTime, toLocalDate, $LocalDate*)},
	{"toLocalDateTime", "()Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, toLocalDateTime, $LocalDateTime*)},
	{"toLocalTime", "()Ljava/time/LocalTime;", nullptr, $PUBLIC, $method(OffsetDateTime, toLocalTime, $LocalTime*)},
	{"toOffsetTime", "()Ljava/time/OffsetTime;", nullptr, $PUBLIC, $method(OffsetDateTime, toOffsetTime, $OffsetTime*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, toString, $String*)},
	{"toZonedDateTime", "()Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, toZonedDateTime, $ZonedDateTime*)},
	{"truncatedTo", "(Ljava/time/temporal/TemporalUnit;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, truncatedTo, OffsetDateTime*, $TemporalUnit*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/LocalDateTime;Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PRIVATE, $method(OffsetDateTime, with, OffsetDateTime*, $LocalDateTime*, $ZoneOffset*)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, with, OffsetDateTime*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $virtualMethod(OffsetDateTime, with, OffsetDateTime*, $TemporalField*, int64_t)},
	{"withDayOfMonth", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withDayOfMonth, OffsetDateTime*, int32_t)},
	{"withDayOfYear", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withDayOfYear, OffsetDateTime*, int32_t)},
	{"withHour", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withHour, OffsetDateTime*, int32_t)},
	{"withMinute", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withMinute, OffsetDateTime*, int32_t)},
	{"withMonth", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withMonth, OffsetDateTime*, int32_t)},
	{"withNano", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withNano, OffsetDateTime*, int32_t)},
	{"withOffsetSameInstant", "(Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withOffsetSameInstant, OffsetDateTime*, $ZoneOffset*)},
	{"withOffsetSameLocal", "(Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withOffsetSameLocal, OffsetDateTime*, $ZoneOffset*)},
	{"withSecond", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withSecond, OffsetDateTime*, int32_t)},
	{"withYear", "(I)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(OffsetDateTime, withYear, OffsetDateTime*, int32_t)},
	{"writeExternal", "(Ljava/io/ObjectOutput;)V", nullptr, 0, $method(OffsetDateTime, writeExternal, void, $ObjectOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(OffsetDateTime, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _OffsetDateTime_InnerClassesInfo_[] = {
	{"java.time.OffsetDateTime$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _OffsetDateTime_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.OffsetDateTime",
	"java.lang.Object",
	"java.time.temporal.Temporal,java.time.temporal.TemporalAdjuster,java.lang.Comparable,java.io.Serializable",
	_OffsetDateTime_FieldInfo_,
	_OffsetDateTime_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalAdjuster;Ljava/lang/Comparable<Ljava/time/OffsetDateTime;>;Ljava/io/Serializable;",
	nullptr,
	_OffsetDateTime_InnerClassesInfo_,
	_OffsetDateTime_Annotations_,
	nullptr,
	"java.time.OffsetDateTime$1"
};

$Object* allocate$OffsetDateTime($Class* clazz) {
	return $of($alloc(OffsetDateTime));
}

$Object* OffsetDateTime::clone() {
	 return this->$Temporal::clone();
}

void OffsetDateTime::finalize() {
	this->$Temporal::finalize();
}

OffsetDateTime* OffsetDateTime::MIN = nullptr;
OffsetDateTime* OffsetDateTime::MAX = nullptr;

$Comparator* OffsetDateTime::timeLineOrder() {
	$init(OffsetDateTime);
	return static_cast<$Comparator*>($new(OffsetDateTime$$Lambda$compareInstant));
}

int32_t OffsetDateTime::compareInstant(OffsetDateTime* datetime1, OffsetDateTime* datetime2) {
	$init(OffsetDateTime);
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(datetime1)->getOffset()))->equals($($nc(datetime2)->getOffset()))) {
		return $nc($(datetime1->toLocalDateTime()))->compareTo($(static_cast<$ChronoLocalDateTime*>($nc(datetime2)->toLocalDateTime())));
	}
	int64_t var$0 = $nc(datetime1)->toEpochSecond();
	int32_t cmp = $Long::compare(var$0, $nc(datetime2)->toEpochSecond());
	if (cmp == 0) {
		int32_t var$1 = $nc($($nc(datetime1)->toLocalTime()))->getNano();
		cmp = var$1 - $nc($($nc(datetime2)->toLocalTime()))->getNano();
	}
	return cmp;
}

OffsetDateTime* OffsetDateTime::now() {
	$init(OffsetDateTime);
	return now($($Clock::systemDefaultZone()));
}

OffsetDateTime* OffsetDateTime::now($ZoneId* zone) {
	$init(OffsetDateTime);
	return now($($Clock::system(zone)));
}

OffsetDateTime* OffsetDateTime::now($Clock* clock) {
	$init(OffsetDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(clock), "clock"_s);
	$var($Instant, now, $nc(clock)->instant());
	return ofInstant(now, $($nc($($nc($(clock->getZone()))->getRules()))->getOffset(now)));
}

OffsetDateTime* OffsetDateTime::of($LocalDate* date, $LocalTime* time, $ZoneOffset* offset) {
	$init(OffsetDateTime);
	$var($LocalDateTime, dt, $LocalDateTime::of(date, time));
	return $new(OffsetDateTime, dt, offset);
}

OffsetDateTime* OffsetDateTime::of($LocalDateTime* dateTime, $ZoneOffset* offset) {
	$init(OffsetDateTime);
	return $new(OffsetDateTime, dateTime, offset);
}

OffsetDateTime* OffsetDateTime::of(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, int32_t nanoOfSecond, $ZoneOffset* offset) {
	$init(OffsetDateTime);
	$var($LocalDateTime, dt, $LocalDateTime::of(year, month, dayOfMonth, hour, minute, second, nanoOfSecond));
	return $new(OffsetDateTime, dt, offset);
}

OffsetDateTime* OffsetDateTime::ofInstant($Instant* instant, $ZoneId* zone) {
	$init(OffsetDateTime);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(instant), "instant"_s);
	$Objects::requireNonNull($of(zone), "zone"_s);
	$var($ZoneRules, rules, $nc(zone)->getRules());
	$var($ZoneOffset, offset, $nc(rules)->getOffset(instant));
	int64_t var$0 = $nc(instant)->getEpochSecond();
	$var($LocalDateTime, ldt, $LocalDateTime::ofEpochSecond(var$0, instant->getNano(), offset));
	return $new(OffsetDateTime, ldt, offset);
}

OffsetDateTime* OffsetDateTime::from($TemporalAccessor* temporal) {
	$init(OffsetDateTime);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf(OffsetDateTime, temporal)) {
		return $cast(OffsetDateTime, temporal);
	}
	try {
		$var($ZoneOffset, offset, $ZoneOffset::from(temporal));
		$var($LocalDate, date, $cast($LocalDate, $nc(temporal)->query($($TemporalQueries::localDate()))));
		$var($LocalTime, time, $cast($LocalTime, temporal->query($($TemporalQueries::localTime()))));
		if (date != nullptr && time != nullptr) {
			return OffsetDateTime::of(date, time, offset);
		} else {
			$var($Instant, instant, $Instant::from(temporal));
			return OffsetDateTime::ofInstant(instant, offset);
		}
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain OffsetDateTime from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

OffsetDateTime* OffsetDateTime::parse($CharSequence* text) {
	$init(OffsetDateTime);
	$init($DateTimeFormatter);
	return parse(text, $DateTimeFormatter::ISO_OFFSET_DATE_TIME);
}

OffsetDateTime* OffsetDateTime::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(OffsetDateTime);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(OffsetDateTime, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(OffsetDateTime$$Lambda$from$1))));
}

void OffsetDateTime::init$($LocalDateTime* dateTime, $ZoneOffset* offset) {
	$set(this, dateTime, $cast($LocalDateTime, $Objects::requireNonNull($of(dateTime), "dateTime"_s)));
	$set(this, offset, $cast($ZoneOffset, $Objects::requireNonNull($of(offset), "offset"_s)));
}

OffsetDateTime* OffsetDateTime::with($LocalDateTime* dateTime, $ZoneOffset* offset) {
	if (this->dateTime == dateTime && $nc(this->offset)->equals(offset)) {
		return this;
	}
	return $new(OffsetDateTime, dateTime, offset);
}

bool OffsetDateTime::isSupported($TemporalField* field) {
	return $instanceOf($ChronoField, field) || (field != nullptr && field->isSupportedBy(this));
}

bool OffsetDateTime::isSupported($TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		$init($ChronoUnit);
		return !$equals(unit, $ChronoUnit::FOREVER);
	}
	return unit != nullptr && unit->isSupportedBy(this);
}

$ValueRange* OffsetDateTime::range($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		if ($equals(field, $ChronoField::INSTANT_SECONDS) || $equals(field, $ChronoField::OFFSET_SECONDS)) {
			return field->range();
		}
		return $nc(this->dateTime)->range(field);
	}
	return $nc(field)->rangeRefinedBy(this);
}

int32_t OffsetDateTime::get($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($OffsetDateTime$1);
			switch ($nc($OffsetDateTime$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
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
	return $Temporal::get(field);
}

int64_t OffsetDateTime::getLong($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($OffsetDateTime$1);
			switch ($nc($OffsetDateTime$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
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

$ZoneOffset* OffsetDateTime::getOffset() {
	return this->offset;
}

OffsetDateTime* OffsetDateTime::withOffsetSameLocal($ZoneOffset* offset) {
	return with(this->dateTime, offset);
}

OffsetDateTime* OffsetDateTime::withOffsetSameInstant($ZoneOffset* offset) {
	if ($nc(offset)->equals(this->offset)) {
		return this;
	}
	int32_t var$0 = $nc(offset)->getTotalSeconds();
	int32_t difference = var$0 - $nc(this->offset)->getTotalSeconds();
	$var($LocalDateTime, adjusted, $nc(this->dateTime)->plusSeconds(difference));
	return $new(OffsetDateTime, adjusted, offset);
}

$LocalDateTime* OffsetDateTime::toLocalDateTime() {
	return this->dateTime;
}

$LocalDate* OffsetDateTime::toLocalDate() {
	return $cast($LocalDate, $nc(this->dateTime)->toLocalDate());
}

int32_t OffsetDateTime::getYear() {
	return $nc(this->dateTime)->getYear();
}

int32_t OffsetDateTime::getMonthValue() {
	return $nc(this->dateTime)->getMonthValue();
}

$Month* OffsetDateTime::getMonth() {
	return $nc(this->dateTime)->getMonth();
}

int32_t OffsetDateTime::getDayOfMonth() {
	return $nc(this->dateTime)->getDayOfMonth();
}

int32_t OffsetDateTime::getDayOfYear() {
	return $nc(this->dateTime)->getDayOfYear();
}

$DayOfWeek* OffsetDateTime::getDayOfWeek() {
	return $nc(this->dateTime)->getDayOfWeek();
}

$LocalTime* OffsetDateTime::toLocalTime() {
	return $nc(this->dateTime)->toLocalTime();
}

int32_t OffsetDateTime::getHour() {
	return $nc(this->dateTime)->getHour();
}

int32_t OffsetDateTime::getMinute() {
	return $nc(this->dateTime)->getMinute();
}

int32_t OffsetDateTime::getSecond() {
	return $nc(this->dateTime)->getSecond();
}

int32_t OffsetDateTime::getNano() {
	return $nc(this->dateTime)->getNano();
}

OffsetDateTime* OffsetDateTime::with($TemporalAdjuster* adjuster) {
	if ($instanceOf($LocalDate, adjuster) || $instanceOf($LocalTime, adjuster) || $instanceOf($LocalDateTime, adjuster)) {
		return with($($nc(this->dateTime)->with(adjuster)), this->offset);
	} else if ($instanceOf($Instant, adjuster)) {
		return ofInstant($cast($Instant, adjuster), this->offset);
	} else if ($instanceOf($ZoneOffset, adjuster)) {
		return with(this->dateTime, $cast($ZoneOffset, adjuster));
	} else if ($instanceOf(OffsetDateTime, adjuster)) {
		return $cast(OffsetDateTime, adjuster);
	}
	return $cast(OffsetDateTime, $nc(adjuster)->adjustInto(this));
}

OffsetDateTime* OffsetDateTime::with($TemporalField* field, int64_t newValue) {
	$useLocalCurrentObjectStackCache();
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($OffsetDateTime$1);
			switch ($nc($OffsetDateTime$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 1:
				{
					return ofInstant($($Instant::ofEpochSecond(newValue, getNano())), this->offset);
				}
			case 2:
				{
					{
						return with(this->dateTime, $($ZoneOffset::ofTotalSeconds(chronoField->checkValidIntValue(newValue))));
					}
				}
			}
			return with($($nc(this->dateTime)->with(field, newValue)), this->offset);
		}
	}
	return $cast(OffsetDateTime, $nc(field)->adjustInto(this, newValue));
}

OffsetDateTime* OffsetDateTime::withYear(int32_t year) {
	return with($($nc(this->dateTime)->withYear(year)), this->offset);
}

OffsetDateTime* OffsetDateTime::withMonth(int32_t month) {
	return with($($nc(this->dateTime)->withMonth(month)), this->offset);
}

OffsetDateTime* OffsetDateTime::withDayOfMonth(int32_t dayOfMonth) {
	return with($($nc(this->dateTime)->withDayOfMonth(dayOfMonth)), this->offset);
}

OffsetDateTime* OffsetDateTime::withDayOfYear(int32_t dayOfYear) {
	return with($($nc(this->dateTime)->withDayOfYear(dayOfYear)), this->offset);
}

OffsetDateTime* OffsetDateTime::withHour(int32_t hour) {
	return with($($nc(this->dateTime)->withHour(hour)), this->offset);
}

OffsetDateTime* OffsetDateTime::withMinute(int32_t minute) {
	return with($($nc(this->dateTime)->withMinute(minute)), this->offset);
}

OffsetDateTime* OffsetDateTime::withSecond(int32_t second) {
	return with($($nc(this->dateTime)->withSecond(second)), this->offset);
}

OffsetDateTime* OffsetDateTime::withNano(int32_t nanoOfSecond) {
	return with($($nc(this->dateTime)->withNano(nanoOfSecond)), this->offset);
}

OffsetDateTime* OffsetDateTime::truncatedTo($TemporalUnit* unit) {
	return with($($nc(this->dateTime)->truncatedTo(unit)), this->offset);
}

OffsetDateTime* OffsetDateTime::plus($TemporalAmount* amountToAdd) {
	return $cast(OffsetDateTime, $nc(amountToAdd)->addTo(this));
}

OffsetDateTime* OffsetDateTime::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		return with($($nc(this->dateTime)->plus(amountToAdd, unit)), this->offset);
	}
	return $cast(OffsetDateTime, $nc(unit)->addTo(this, amountToAdd));
}

OffsetDateTime* OffsetDateTime::plusYears(int64_t years) {
	return with($($nc(this->dateTime)->plusYears(years)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusMonths(int64_t months) {
	return with($($nc(this->dateTime)->plusMonths(months)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusWeeks(int64_t weeks) {
	return with($($nc(this->dateTime)->plusWeeks(weeks)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusDays(int64_t days) {
	return with($($nc(this->dateTime)->plusDays(days)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusHours(int64_t hours) {
	return with($($nc(this->dateTime)->plusHours(hours)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusMinutes(int64_t minutes) {
	return with($($nc(this->dateTime)->plusMinutes(minutes)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusSeconds(int64_t seconds) {
	return with($($nc(this->dateTime)->plusSeconds(seconds)), this->offset);
}

OffsetDateTime* OffsetDateTime::plusNanos(int64_t nanos) {
	return with($($nc(this->dateTime)->plusNanos(nanos)), this->offset);
}

OffsetDateTime* OffsetDateTime::minus($TemporalAmount* amountToSubtract) {
	return $cast(OffsetDateTime, $nc(amountToSubtract)->subtractFrom(this));
}

OffsetDateTime* OffsetDateTime::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus(1, unit) : plus(-amountToSubtract, unit));
}

OffsetDateTime* OffsetDateTime::minusYears(int64_t years) {
	return (years == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-years));
}

OffsetDateTime* OffsetDateTime::minusMonths(int64_t months) {
	return (months == $Long::MIN_VALUE ? $nc($(plusMonths($Long::MAX_VALUE)))->plusMonths(1) : plusMonths(-months));
}

OffsetDateTime* OffsetDateTime::minusWeeks(int64_t weeks) {
	return (weeks == $Long::MIN_VALUE ? $nc($(plusWeeks($Long::MAX_VALUE)))->plusWeeks(1) : plusWeeks(-weeks));
}

OffsetDateTime* OffsetDateTime::minusDays(int64_t days) {
	return (days == $Long::MIN_VALUE ? $nc($(plusDays($Long::MAX_VALUE)))->plusDays(1) : plusDays(-days));
}

OffsetDateTime* OffsetDateTime::minusHours(int64_t hours) {
	return (hours == $Long::MIN_VALUE ? $nc($(plusHours($Long::MAX_VALUE)))->plusHours(1) : plusHours(-hours));
}

OffsetDateTime* OffsetDateTime::minusMinutes(int64_t minutes) {
	return (minutes == $Long::MIN_VALUE ? $nc($(plusMinutes($Long::MAX_VALUE)))->plusMinutes(1) : plusMinutes(-minutes));
}

OffsetDateTime* OffsetDateTime::minusSeconds(int64_t seconds) {
	return (seconds == $Long::MIN_VALUE ? $nc($(plusSeconds($Long::MAX_VALUE)))->plusSeconds(1) : plusSeconds(-seconds));
}

OffsetDateTime* OffsetDateTime::minusNanos(int64_t nanos) {
	return (nanos == $Long::MIN_VALUE ? $nc($(plusNanos($Long::MAX_VALUE)))->plusNanos(1) : plusNanos(-nanos));
}

$Object* OffsetDateTime::query($TemporalQuery* query) {
	bool var$0 = query == $TemporalQueries::offset();
	if (var$0 || query == $TemporalQueries::zone()) {
		return $of($of(getOffset()));
	} else if (query == $TemporalQueries::zoneId()) {
		return $of(nullptr);
	} else if (query == $TemporalQueries::localDate()) {
		return $of($of(toLocalDate()));
	} else if (query == $TemporalQueries::localTime()) {
		return $of($of(toLocalTime()));
	} else if (query == $TemporalQueries::chronology()) {
		$init($IsoChronology);
		return $of($of($IsoChronology::INSTANCE));
	} else if (query == $TemporalQueries::precision()) {
		$init($ChronoUnit);
		return $of($of($ChronoUnit::NANOS));
	}
	return $of($nc(query)->queryFrom(this));
}

$Temporal* OffsetDateTime::adjustInto($Temporal* temporal) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	return $nc($($nc($($nc(temporal)->with($ChronoField::EPOCH_DAY, $nc($(toLocalDate()))->toEpochDay())))->with($ChronoField::NANO_OF_DAY, $nc($(toLocalTime()))->toNanoOfDay())))->with($ChronoField::OFFSET_SECONDS, $nc($(getOffset()))->getTotalSeconds());
}

int64_t OffsetDateTime::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(OffsetDateTime, end, OffsetDateTime::from(endExclusive));
	if ($instanceOf($ChronoUnit, unit)) {
		$var(OffsetDateTime, start, this);
		try {
			$assign(end, $nc(end)->withOffsetSameInstant(this->offset));
		} catch ($DateTimeException& ex) {
			$assign(start, withOffsetSameInstant($nc(end)->offset));
		}
		return $nc(start->dateTime)->until($nc(end)->dateTime, unit);
	}
	return $nc(unit)->between(this, end);
}

$String* OffsetDateTime::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$ZonedDateTime* OffsetDateTime::atZoneSameInstant($ZoneId* zone) {
	return $ZonedDateTime::ofInstant(this->dateTime, this->offset, zone);
}

$ZonedDateTime* OffsetDateTime::atZoneSimilarLocal($ZoneId* zone) {
	return $ZonedDateTime::ofLocal(this->dateTime, zone, this->offset);
}

$OffsetTime* OffsetDateTime::toOffsetTime() {
	return $OffsetTime::of($($nc(this->dateTime)->toLocalTime()), this->offset);
}

$ZonedDateTime* OffsetDateTime::toZonedDateTime() {
	return $ZonedDateTime::of(this->dateTime, this->offset);
}

$Instant* OffsetDateTime::toInstant() {
	return $nc(this->dateTime)->toInstant(this->offset);
}

int64_t OffsetDateTime::toEpochSecond() {
	return $nc(this->dateTime)->toEpochSecond(this->offset);
}

int32_t OffsetDateTime::compareTo(OffsetDateTime* other) {
	$useLocalCurrentObjectStackCache();
	int32_t cmp = compareInstant(this, other);
	if (cmp == 0) {
		cmp = $nc($(toLocalDateTime()))->compareTo($(static_cast<$ChronoLocalDateTime*>($nc(other)->toLocalDateTime())));
	}
	return cmp;
}

bool OffsetDateTime::isAfter(OffsetDateTime* other) {
	$useLocalCurrentObjectStackCache();
	int64_t thisEpochSec = toEpochSecond();
	int64_t otherEpochSec = $nc(other)->toEpochSecond();
	bool var$0 = thisEpochSec > otherEpochSec;
	if (!var$0) {
		bool var$1 = thisEpochSec == otherEpochSec;
		if (var$1) {
			int32_t var$2 = $nc($(toLocalTime()))->getNano();
			var$1 = var$2 > $nc($(other->toLocalTime()))->getNano();
		}
		var$0 = (var$1);
	}
	return var$0;
}

bool OffsetDateTime::isBefore(OffsetDateTime* other) {
	$useLocalCurrentObjectStackCache();
	int64_t thisEpochSec = toEpochSecond();
	int64_t otherEpochSec = $nc(other)->toEpochSecond();
	bool var$0 = thisEpochSec < otherEpochSec;
	if (!var$0) {
		bool var$1 = thisEpochSec == otherEpochSec;
		if (var$1) {
			int32_t var$2 = $nc($(toLocalTime()))->getNano();
			var$1 = var$2 < $nc($(other->toLocalTime()))->getNano();
		}
		var$0 = (var$1);
	}
	return var$0;
}

bool OffsetDateTime::isEqual(OffsetDateTime* other) {
	$useLocalCurrentObjectStackCache();
	int64_t var$1 = toEpochSecond();
	bool var$0 = var$1 == $nc(other)->toEpochSecond();
	if (var$0) {
		int32_t var$2 = $nc($(toLocalTime()))->getNano();
		var$0 = var$2 == $nc($(other->toLocalTime()))->getNano();
	}
	return var$0;
}

bool OffsetDateTime::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(OffsetDateTime, other, nullptr);
	bool var$2 = $instanceOf(OffsetDateTime, obj);
	if (var$2) {
		$assign(other, $cast(OffsetDateTime, obj));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && $nc(this->dateTime)->equals($nc(other)->dateTime);
	return var$0 && $nc(this->offset)->equals($nc(other)->offset);
}

int32_t OffsetDateTime::hashCode() {
	int32_t var$0 = $nc(this->dateTime)->hashCode();
	return var$0 ^ $nc(this->offset)->hashCode();
}

$String* OffsetDateTime::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $($nc(this->dateTime)->toString()));
	return $concat(var$0, $($nc(this->offset)->toString()));
}

$Object* OffsetDateTime::writeReplace() {
	return $of($new($Ser, $Ser::OFFSET_DATE_TIME_TYPE, this));
}

void OffsetDateTime::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void OffsetDateTime::writeExternal($ObjectOutput* out) {
	$nc(this->dateTime)->writeExternal(out);
	$nc(this->offset)->writeExternal(out);
}

OffsetDateTime* OffsetDateTime::readExternal($ObjectInput* in) {
	$init(OffsetDateTime);
	$useLocalCurrentObjectStackCache();
	$var($LocalDateTime, dateTime, $LocalDateTime::readExternal(in));
	$var($ZoneOffset, offset, $ZoneOffset::readExternal(in));
	return OffsetDateTime::of(dateTime, offset);
}

int32_t OffsetDateTime::compareTo(Object$* other) {
	return this->compareTo($cast(OffsetDateTime, other));
}

void clinit$OffsetDateTime($Class* class$) {
	$init($LocalDateTime);
	$init($ZoneOffset);
	$assignStatic(OffsetDateTime::MIN, $nc($LocalDateTime::MIN)->atOffset($ZoneOffset::MAX));
	$assignStatic(OffsetDateTime::MAX, $nc($LocalDateTime::MAX)->atOffset($ZoneOffset::MIN));
}

OffsetDateTime::OffsetDateTime() {
}

$Class* OffsetDateTime::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(OffsetDateTime$$Lambda$compareInstant::classInfo$.name)) {
			return OffsetDateTime$$Lambda$compareInstant::load$(name, initialize);
		}
		if (name->equals(OffsetDateTime$$Lambda$from$1::classInfo$.name)) {
			return OffsetDateTime$$Lambda$from$1::load$(name, initialize);
		}
	}
	$loadClass(OffsetDateTime, name, initialize, &_OffsetDateTime_ClassInfo_, clinit$OffsetDateTime, allocate$OffsetDateTime);
	return class$;
}

$Class* OffsetDateTime::class$ = nullptr;

	} // time
} // java