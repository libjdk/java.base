#include <java/time/Instant.h>

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
#include <java/time/Duration.h>
#include <java/time/Instant$1.h>
#include <java/time/LocalTime.h>
#include <java/time/OffsetDateTime.h>
#include <java/time/Ser.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
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
#include <java/util/Objects.h>
#include <jcpp.h>

#undef DAYS
#undef EPOCH
#undef INSTANT_SECONDS
#undef INSTANT_TYPE
#undef ISO_INSTANT
#undef MAX
#undef MAX_SECOND
#undef MAX_VALUE
#undef MICRO_OF_SECOND
#undef MILLI_OF_SECOND
#undef MIN
#undef MIN_SECOND
#undef MIN_VALUE
#undef NANOS
#undef NANOS_PER_DAY
#undef NANOS_PER_SECOND
#undef NANO_OF_SECOND
#undef SECONDS_PER_DAY

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
using $Duration = ::java::time::Duration;
using $Instant$1 = ::java::time::Instant$1;
using $LocalTime = ::java::time::LocalTime;
using $OffsetDateTime = ::java::time::OffsetDateTime;
using $Ser = ::java::time::Ser;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
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
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {

class Instant$$Lambda$from : public $TemporalQuery {
	$class(Instant$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(Instant::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Instant$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Instant$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Instant$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Instant$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo Instant$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.Instant$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* Instant$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(Instant$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Instant$$Lambda$from::class$ = nullptr;

$CompoundAttribute _Instant_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _Instant_FieldInfo_[] = {
	{"EPOCH", "Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Instant, EPOCH)},
	{"MIN_SECOND", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Instant, MIN_SECOND)},
	{"MAX_SECOND", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Instant, MAX_SECOND)},
	{"MIN", "Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Instant, MIN)},
	{"MAX", "Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Instant, MAX)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Instant, serialVersionUID)},
	{"seconds", "J", nullptr, $PRIVATE | $FINAL, $field(Instant, seconds)},
	{"nanos", "I", nullptr, $PRIVATE | $FINAL, $field(Instant, nanos)},
	{}
};

$MethodInfo _Instant_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(JI)V", nullptr, $PRIVATE, $method(Instant, init$, void, int64_t, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Instant, adjustInto, $Temporal*, $Temporal*)},
	{"atOffset", "(Ljava/time/ZoneOffset;)Ljava/time/OffsetDateTime;", nullptr, $PUBLIC, $method(Instant, atOffset, $OffsetDateTime*, $ZoneOffset*)},
	{"atZone", "(Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $method(Instant, atZone, $ZonedDateTime*, $ZoneId*)},
	{"compareTo", "(Ljava/time/Instant;)I", nullptr, $PUBLIC, $method(Instant, compareTo, int32_t, Instant*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Instant, compareTo, int32_t, Object$*)},
	{"create", "(JI)Ljava/time/Instant;", nullptr, $PRIVATE | $STATIC, $staticMethod(Instant, create, Instant*, int64_t, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Instant, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, from, Instant*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(Instant, get, int32_t, $TemporalField*)},
	{"getEpochSecond", "()J", nullptr, $PUBLIC, $method(Instant, getEpochSecond, int64_t)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(Instant, getLong, int64_t, $TemporalField*)},
	{"getNano", "()I", nullptr, $PUBLIC, $method(Instant, getNano, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Instant, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/Instant;)Z", nullptr, $PUBLIC, $method(Instant, isAfter, bool, Instant*)},
	{"isBefore", "(Ljava/time/Instant;)Z", nullptr, $PUBLIC, $method(Instant, isBefore, bool, Instant*)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(Instant, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(Instant, isSupported, bool, $TemporalUnit*)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Instant, minus, Instant*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Instant, minus, Instant*, int64_t, $TemporalUnit*)},
	{"minusMillis", "(J)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, minusMillis, Instant*, int64_t)},
	{"minusNanos", "(J)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, minusNanos, Instant*, int64_t)},
	{"minusSeconds", "(J)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, minusSeconds, Instant*, int64_t)},
	{"nanosUntil", "(Ljava/time/Instant;)J", nullptr, $PRIVATE, $method(Instant, nanosUntil, int64_t, Instant*)},
	{"now", "()Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, now, Instant*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, now, Instant*, $Clock*)},
	{"ofEpochMilli", "(J)Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, ofEpochMilli, Instant*, int64_t)},
	{"ofEpochSecond", "(J)Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, ofEpochSecond, Instant*, int64_t)},
	{"ofEpochSecond", "(JJ)Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, ofEpochSecond, Instant*, int64_t, int64_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/Instant;", nullptr, $PUBLIC | $STATIC, $staticMethod(Instant, parse, Instant*, $CharSequence*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Instant, plus, Instant*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Instant, plus, Instant*, int64_t, $TemporalUnit*)},
	{"plus", "(JJ)Ljava/time/Instant;", nullptr, $PRIVATE, $method(Instant, plus, Instant*, int64_t, int64_t)},
	{"plusMillis", "(J)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, plusMillis, Instant*, int64_t)},
	{"plusNanos", "(J)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, plusNanos, Instant*, int64_t)},
	{"plusSeconds", "(J)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, plusSeconds, Instant*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(Instant, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(Instant, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/Instant;", nullptr, $STATIC, $staticMethod(Instant, readExternal, Instant*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Instant, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"secondsUntil", "(Ljava/time/Instant;)J", nullptr, $PRIVATE, $method(Instant, secondsUntil, int64_t, Instant*)},
	{"toEpochMilli", "()J", nullptr, $PUBLIC, $method(Instant, toEpochMilli, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Instant, toString, $String*)},
	{"truncatedTo", "(Ljava/time/temporal/TemporalUnit;)Ljava/time/Instant;", nullptr, $PUBLIC, $method(Instant, truncatedTo, Instant*, $TemporalUnit*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(Instant, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Instant, with, Instant*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Instant, with, Instant*, $TemporalField*, int64_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(Instant, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Instant, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _Instant_InnerClassesInfo_[] = {
	{"java.time.Instant$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _Instant_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.Instant",
	"java.lang.Object",
	"java.time.temporal.Temporal,java.time.temporal.TemporalAdjuster,java.lang.Comparable,java.io.Serializable",
	_Instant_FieldInfo_,
	_Instant_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalAdjuster;Ljava/lang/Comparable<Ljava/time/Instant;>;Ljava/io/Serializable;",
	nullptr,
	_Instant_InnerClassesInfo_,
	_Instant_Annotations_,
	nullptr,
	"java.time.Instant$1"
};

$Object* allocate$Instant($Class* clazz) {
	return $of($alloc(Instant));
}

$Object* Instant::clone() {
	 return this->$Temporal::clone();
}

void Instant::finalize() {
	this->$Temporal::finalize();
}

Instant* Instant::EPOCH = nullptr;
Instant* Instant::MIN = nullptr;
Instant* Instant::MAX = nullptr;

Instant* Instant::now() {
	$init(Instant);
	return $Clock::currentInstant();
}

Instant* Instant::now($Clock* clock) {
	$init(Instant);
	$Objects::requireNonNull($of(clock), "clock"_s);
	return $nc(clock)->instant();
}

Instant* Instant::ofEpochSecond(int64_t epochSecond) {
	$init(Instant);
	return create(epochSecond, 0);
}

Instant* Instant::ofEpochSecond(int64_t epochSecond, int64_t nanoAdjustment) {
	$init(Instant);
	int64_t secs = $Math::addExact(epochSecond, $Math::floorDiv(nanoAdjustment, (int64_t)1000000000));
	int32_t nos = (int32_t)$Math::floorMod(nanoAdjustment, (int64_t)1000000000);
	return create(secs, nos);
}

Instant* Instant::ofEpochMilli(int64_t epochMilli) {
	$init(Instant);
	int64_t secs = $Math::floorDiv(epochMilli, 1000);
	int32_t mos = $Math::floorMod(epochMilli, 1000);
	return create(secs, mos * 0x000F4240);
}

Instant* Instant::from($TemporalAccessor* temporal) {
	$init(Instant);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf(Instant, temporal)) {
		return $cast(Instant, temporal);
	}
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	try {
		$init($ChronoField);
		int64_t instantSecs = $nc(temporal)->getLong($ChronoField::INSTANT_SECONDS);
		int32_t nanoOfSecond = temporal->get($ChronoField::NANO_OF_SECOND);
		return Instant::ofEpochSecond(instantSecs, nanoOfSecond);
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain Instant from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

Instant* Instant::parse($CharSequence* text) {
	$init(Instant);
	$init($DateTimeFormatter);
	return $cast(Instant, $nc($DateTimeFormatter::ISO_INSTANT)->parse(text, static_cast<$TemporalQuery*>($$new(Instant$$Lambda$from))));
}

Instant* Instant::create(int64_t seconds, int32_t nanoOfSecond) {
	$init(Instant);
	if ((seconds | nanoOfSecond) == 0) {
		return Instant::EPOCH;
	}
	if (seconds < Instant::MIN_SECOND || seconds > Instant::MAX_SECOND) {
		$throwNew($DateTimeException, "Instant exceeds minimum or maximum instant"_s);
	}
	return $new(Instant, seconds, nanoOfSecond);
}

void Instant::init$(int64_t epochSecond, int32_t nanos) {
	this->seconds = epochSecond;
	this->nanos = nanos;
}

bool Instant::isSupported($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		return $equals(field, $ChronoField::INSTANT_SECONDS) || $equals(field, $ChronoField::NANO_OF_SECOND) || $equals(field, $ChronoField::MICRO_OF_SECOND) || $equals(field, $ChronoField::MILLI_OF_SECOND);
	}
	return field != nullptr && field->isSupportedBy(this);
}

bool Instant::isSupported($TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		$init($ChronoUnit);
		return $nc(unit)->isTimeBased() || $equals(unit, $ChronoUnit::DAYS);
	}
	return unit != nullptr && unit->isSupportedBy(this);
}

$ValueRange* Instant::range($TemporalField* field) {
	return $Temporal::range(field);
}

int32_t Instant::get($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoField, field)) {
		$init($Instant$1);
		switch ($nc($Instant$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
		case 1:
			{
				return this->nanos;
			}
		case 2:
			{
				return this->nanos / 1000;
			}
		case 3:
			{
				return this->nanos / 0x000F4240;
			}
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc($(range(field)))->checkValidIntValue($nc(field)->getFrom(this), field);
}

int64_t Instant::getLong($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($Instant$1);
		switch ($nc($Instant$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
		case 1:
			{
				return this->nanos;
			}
		case 2:
			{
				return this->nanos / 1000;
			}
		case 3:
			{
				return this->nanos / 0x000F4240;
			}
		case 4:
			{
				return this->seconds;
			}
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->getFrom(this);
}

int64_t Instant::getEpochSecond() {
	return this->seconds;
}

int32_t Instant::getNano() {
	return this->nanos;
}

Instant* Instant::with($TemporalAdjuster* adjuster) {
	return $cast(Instant, $nc(adjuster)->adjustInto(this));
}

Instant* Instant::with($TemporalField* field, int64_t newValue) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$nc(chronoField)->checkValidValue(newValue);
			$init($Instant$1);
			switch ($nc($Instant$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
			case 3:
				{
					{
						int32_t nval = (int32_t)newValue * 0x000F4240;
						return (nval != this->nanos ? create(this->seconds, nval) : this);
					}
				}
			case 2:
				{
					{
						int32_t nval = (int32_t)newValue * 1000;
						return (nval != this->nanos ? create(this->seconds, nval) : this);
					}
				}
			case 1:
				{
					return (newValue != this->nanos ? create(this->seconds, (int32_t)newValue) : this);
				}
			case 4:
				{
					return (newValue != this->seconds ? create(newValue, this->nanos) : this);
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $cast(Instant, $nc(field)->adjustInto(this, newValue));
}

Instant* Instant::truncatedTo($TemporalUnit* unit) {
	$init($ChronoUnit);
	if ($equals(unit, $ChronoUnit::NANOS)) {
		return this;
	}
	$var($Duration, unitDur, $nc(unit)->getDuration());
	if ($nc(unitDur)->getSeconds() > $LocalTime::SECONDS_PER_DAY) {
		$throwNew($UnsupportedTemporalTypeException, "Unit is too large to be used for truncation"_s);
	}
	int64_t dur = $nc(unitDur)->toNanos();
	if (($mod($LocalTime::NANOS_PER_DAY, dur)) != 0) {
		$throwNew($UnsupportedTemporalTypeException, "Unit must divide into a standard day without remainder"_s);
	}
	int64_t nod = ($mod(this->seconds, $LocalTime::SECONDS_PER_DAY)) * $LocalTime::NANOS_PER_SECOND + this->nanos;
	int64_t result = $Math::floorDiv(nod, dur) * dur;
	return plusNanos(result - nod);
}

Instant* Instant::plus($TemporalAmount* amountToAdd) {
	return $cast(Instant, $nc(amountToAdd)->addTo(this));
}

Instant* Instant::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		$init($Instant$1);
		switch ($nc($Instant$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc(($cast($ChronoUnit, unit)))->ordinal())) {
		case 1:
			{
				return plusNanos(amountToAdd);
			}
		case 2:
			{
				return plus(amountToAdd / 0x000F4240, (amountToAdd % 0x000F4240) * 1000);
			}
		case 3:
			{
				return plusMillis(amountToAdd);
			}
		case 4:
			{
				return plusSeconds(amountToAdd);
			}
		case 5:
			{
				return plusSeconds($Math::multiplyExact(amountToAdd, 60));
			}
		case 6:
			{
				return plusSeconds($Math::multiplyExact(amountToAdd, 3600));
			}
		case 7:
			{
				return plusSeconds($Math::multiplyExact(amountToAdd, 0x00015180 / 2));
			}
		case 8:
			{
				return plusSeconds($Math::multiplyExact(amountToAdd, 0x00015180));
			}
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
	}
	return $cast(Instant, $nc(unit)->addTo(this, amountToAdd));
}

Instant* Instant::plusSeconds(int64_t secondsToAdd) {
	return plus(secondsToAdd, (int64_t)0);
}

Instant* Instant::plusMillis(int64_t millisToAdd) {
	return plus(millisToAdd / 1000, (millisToAdd % 1000) * 0x000F4240);
}

Instant* Instant::plusNanos(int64_t nanosToAdd) {
	return plus((int64_t)0, nanosToAdd);
}

Instant* Instant::plus(int64_t secondsToAdd, int64_t nanosToAdd) {
	if ((secondsToAdd | nanosToAdd) == 0) {
		return this;
	}
	int64_t epochSec = $Math::addExact(this->seconds, secondsToAdd);
	epochSec = $Math::addExact(epochSec, $div(nanosToAdd, (int64_t)1000000000));
	nanosToAdd = $mod(nanosToAdd, (int64_t)1000000000);
	int64_t nanoAdjustment = this->nanos + nanosToAdd;
	return ofEpochSecond(epochSec, nanoAdjustment);
}

Instant* Instant::minus($TemporalAmount* amountToSubtract) {
	return $cast(Instant, $nc(amountToSubtract)->subtractFrom(this));
}

Instant* Instant::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus((int64_t)1, unit) : plus(-amountToSubtract, unit));
}

Instant* Instant::minusSeconds(int64_t secondsToSubtract) {
	if (secondsToSubtract == $Long::MIN_VALUE) {
		return $nc($(plusSeconds($Long::MAX_VALUE)))->plusSeconds(1);
	}
	return plusSeconds(-secondsToSubtract);
}

Instant* Instant::minusMillis(int64_t millisToSubtract) {
	if (millisToSubtract == $Long::MIN_VALUE) {
		return $nc($(plusMillis($Long::MAX_VALUE)))->plusMillis(1);
	}
	return plusMillis(-millisToSubtract);
}

Instant* Instant::minusNanos(int64_t nanosToSubtract) {
	if (nanosToSubtract == $Long::MIN_VALUE) {
		return $nc($(plusNanos($Long::MAX_VALUE)))->plusNanos(1);
	}
	return plusNanos(-nanosToSubtract);
}

$Object* Instant::query($TemporalQuery* query) {
	if (query == $TemporalQueries::precision()) {
		$init($ChronoUnit);
		return $of($of($ChronoUnit::NANOS));
	}
	bool var$4 = query == $TemporalQueries::chronology();
	bool var$3 = var$4 || query == $TemporalQueries::zoneId();
	bool var$2 = var$3 || query == $TemporalQueries::zone();
	bool var$1 = var$2 || query == $TemporalQueries::offset();
	bool var$0 = var$1 || query == $TemporalQueries::localDate();
	if (var$0 || query == $TemporalQueries::localTime()) {
		return $of(nullptr);
	}
	return $of($nc(query)->queryFrom(this));
}

$Temporal* Instant::adjustInto($Temporal* temporal) {
	$init($ChronoField);
	return $nc($($nc(temporal)->with($ChronoField::INSTANT_SECONDS, this->seconds)))->with($ChronoField::NANO_OF_SECOND, this->nanos);
}

int64_t Instant::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(Instant, end, Instant::from(endExclusive));
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			$init($Instant$1);
			switch ($nc($Instant$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return nanosUntil(end);
				}
			case 2:
				{
					return nanosUntil(end) / 1000;
				}
			case 3:
				{
					int64_t var$1 = $nc(end)->toEpochMilli();
					return $Math::subtractExact(var$1, toEpochMilli());
				}
			case 4:
				{
					return secondsUntil(end);
				}
			case 5:
				{
					return secondsUntil(end) / 60;
				}
			case 6:
				{
					return secondsUntil(end) / 3600;
				}
			case 7:
				{
					return $div(secondsUntil(end), (12 * 3600));
				}
			case 8:
				{
					return secondsUntil(end) / 0x00015180;
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
	return $nc(unit)->between(this, end);
}

int64_t Instant::nanosUntil(Instant* end) {
	int64_t secsDiff = $Math::subtractExact($nc(end)->seconds, this->seconds);
	int64_t totalNanos = $Math::multiplyExact(secsDiff, (int64_t)1000000000);
	return $Math::addExact(totalNanos, (int64_t)($nc(end)->nanos - this->nanos));
}

int64_t Instant::secondsUntil(Instant* end) {
	int64_t secsDiff = $Math::subtractExact($nc(end)->seconds, this->seconds);
	int64_t nanosDiff = $nc(end)->nanos - this->nanos;
	if (secsDiff > 0 && nanosDiff < 0) {
		--secsDiff;
	} else if (secsDiff < 0 && nanosDiff > 0) {
		++secsDiff;
	}
	return secsDiff;
}

$OffsetDateTime* Instant::atOffset($ZoneOffset* offset) {
	return $OffsetDateTime::ofInstant(this, offset);
}

$ZonedDateTime* Instant::atZone($ZoneId* zone) {
	return $ZonedDateTime::ofInstant(this, zone);
}

int64_t Instant::toEpochMilli() {
	if (this->seconds < 0 && this->nanos > 0) {
		int64_t millis = $Math::multiplyExact(this->seconds + 1, 1000);
		int64_t adjustment = this->nanos / 0x000F4240 - 1000;
		return $Math::addExact(millis, adjustment);
	} else {
		int64_t millis = $Math::multiplyExact(this->seconds, 1000);
		return $Math::addExact(millis, (int64_t)(this->nanos / 0x000F4240));
	}
}

int32_t Instant::compareTo(Instant* otherInstant) {
	int32_t cmp = $Long::compare(this->seconds, $nc(otherInstant)->seconds);
	if (cmp != 0) {
		return cmp;
	}
	return this->nanos - $nc(otherInstant)->nanos;
}

bool Instant::isAfter(Instant* otherInstant) {
	return compareTo(otherInstant) > 0;
}

bool Instant::isBefore(Instant* otherInstant) {
	return compareTo(otherInstant) < 0;
}

bool Instant::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	$var(Instant, otherInstant, nullptr);
	bool var$2 = $instanceOf(Instant, other);
	if (var$2) {
		$assign(otherInstant, $cast(Instant, other));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && this->seconds == $nc(otherInstant)->seconds;
	return var$0 && this->nanos == otherInstant->nanos;
}

int32_t Instant::hashCode() {
	return ((int32_t)(this->seconds ^ ((int64_t)((uint64_t)this->seconds >> 32)))) + 51 * this->nanos;
}

$String* Instant::toString() {
	$init($DateTimeFormatter);
	return $nc($DateTimeFormatter::ISO_INSTANT)->format(this);
}

$Object* Instant::writeReplace() {
	return $of($new($Ser, $Ser::INSTANT_TYPE, this));
}

void Instant::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void Instant::writeExternal($DataOutput* out) {
	$nc(out)->writeLong(this->seconds);
	out->writeInt(this->nanos);
}

Instant* Instant::readExternal($DataInput* in) {
	$init(Instant);
	int64_t seconds = $nc(in)->readLong();
	int32_t nanos = in->readInt();
	return Instant::ofEpochSecond(seconds, nanos);
}

int32_t Instant::compareTo(Object$* otherInstant) {
	return this->compareTo($cast(Instant, otherInstant));
}

void clinit$Instant($Class* class$) {
	$assignStatic(Instant::EPOCH, $new(Instant, 0, 0));
	$assignStatic(Instant::MIN, Instant::ofEpochSecond(Instant::MIN_SECOND, 0));
	$assignStatic(Instant::MAX, Instant::ofEpochSecond(Instant::MAX_SECOND, 0x3B9AC9FF));
}

Instant::Instant() {
}

$Class* Instant::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Instant$$Lambda$from::classInfo$.name)) {
			return Instant$$Lambda$from::load$(name, initialize);
		}
	}
	$loadClass(Instant, name, initialize, &_Instant_ClassInfo_, clinit$Instant, allocate$Instant);
	return class$;
}

$Class* Instant::class$ = nullptr;

	} // time
} // java