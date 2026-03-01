#include <java/time/Duration.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/math/BigDecimal.h>
#include <java/math/BigInteger.h>
#include <java/math/RoundingMode.h>
#include <java/time/DateTimeException.h>
#include <java/time/Duration$1.h>
#include <java/time/Duration$DurationUnits.h>
#include <java/time/Duration$Lazy.h>
#include <java/time/LocalTime.h>
#include <java/time/Ser.h>
#include <java/time/format/DateTimeParseException.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef BI_NANOS_PER_SECOND
#undef DAYS
#undef DOWN
#undef DURATION_TYPE
#undef MAX_VALUE
#undef MIN_VALUE
#undef NANOS
#undef NANOS_PER_DAY
#undef NANOS_PER_SECOND
#undef NANO_OF_SECOND
#undef PATTERN
#undef SECONDS
#undef SECONDS_PER_DAY
#undef UNITS
#undef ZERO

using $BigIntegerArray = $Array<::java::math::BigInteger>;
using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $BigDecimal = ::java::math::BigDecimal;
using $BigInteger = ::java::math::BigInteger;
using $RoundingMode = ::java::math::RoundingMode;
using $DateTimeException = ::java::time::DateTimeException;
using $Duration$1 = ::java::time::Duration$1;
using $Duration$DurationUnits = ::java::time::Duration$DurationUnits;
using $Duration$Lazy = ::java::time::Duration$Lazy;
using $LocalTime = ::java::time::LocalTime;
using $Ser = ::java::time::Ser;
using $DateTimeParseException = ::java::time::format::DateTimeParseException;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;

namespace java {
	namespace time {

$CompoundAttribute _Duration_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _Duration_FieldInfo_[] = {
	{"ZERO", "Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Duration, ZERO)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Duration, serialVersionUID)},
	{"BI_NANOS_PER_SECOND", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Duration, BI_NANOS_PER_SECOND)},
	{"seconds", "J", nullptr, $PRIVATE | $FINAL, $field(Duration, seconds)},
	{"nanos", "I", nullptr, $PRIVATE | $FINAL, $field(Duration, nanos)},
	{}
};

$MethodInfo _Duration_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(JI)V", nullptr, $PRIVATE, $method(Duration, init$, void, int64_t, int32_t)},
	{"abs", "()Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, abs, Duration*)},
	{"addTo", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Duration, addTo, $Temporal*, $Temporal*)},
	{"between", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, between, Duration*, $Temporal*, $Temporal*)},
	{"charMatch", "(Ljava/lang/CharSequence;IIC)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Duration, charMatch, bool, $CharSequence*, int32_t, int32_t, char16_t)},
	{"compareTo", "(Ljava/time/Duration;)I", nullptr, $PUBLIC, $method(Duration, compareTo, int32_t, Duration*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Duration, compareTo, int32_t, Object$*)},
	{"create", "(ZJJJJI)Ljava/time/Duration;", nullptr, $PRIVATE | $STATIC, $staticMethod(Duration, create, Duration*, bool, int64_t, int64_t, int64_t, int64_t, int32_t)},
	{"create", "(JI)Ljava/time/Duration;", nullptr, $PRIVATE | $STATIC, $staticMethod(Duration, create, Duration*, int64_t, int32_t)},
	{"create", "(Ljava/math/BigDecimal;)Ljava/time/Duration;", nullptr, $PRIVATE | $STATIC, $staticMethod(Duration, create, Duration*, $BigDecimal*)},
	{"dividedBy", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, dividedBy, Duration*, int64_t)},
	{"dividedBy", "(Ljava/time/Duration;)J", nullptr, $PUBLIC, $method(Duration, dividedBy, int64_t, Duration*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Duration, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, from, Duration*, $TemporalAmount*)},
	{"get", "(Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(Duration, get, int64_t, $TemporalUnit*)},
	{"getNano", "()I", nullptr, $PUBLIC, $method(Duration, getNano, int32_t)},
	{"getSeconds", "()J", nullptr, $PUBLIC, $method(Duration, getSeconds, int64_t)},
	{"getUnits", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/temporal/TemporalUnit;>;", $PUBLIC, $virtualMethod(Duration, getUnits, $List*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Duration, hashCode, int32_t)},
	{"isNegative", "()Z", nullptr, $PUBLIC, $method(Duration, isNegative, bool)},
	{"isZero", "()Z", nullptr, $PUBLIC, $method(Duration, isZero, bool)},
	{"minus", "(Ljava/time/Duration;)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minus, Duration*, Duration*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minus, Duration*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minusDays, Duration*, int64_t)},
	{"minusHours", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minusHours, Duration*, int64_t)},
	{"minusMillis", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minusMillis, Duration*, int64_t)},
	{"minusMinutes", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minusMinutes, Duration*, int64_t)},
	{"minusNanos", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minusNanos, Duration*, int64_t)},
	{"minusSeconds", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, minusSeconds, Duration*, int64_t)},
	{"multipliedBy", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, multipliedBy, Duration*, int64_t)},
	{"negated", "()Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, negated, Duration*)},
	{"of", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, of, Duration*, int64_t, $TemporalUnit*)},
	{"ofDays", "(J)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofDays, Duration*, int64_t)},
	{"ofHours", "(J)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofHours, Duration*, int64_t)},
	{"ofMillis", "(J)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofMillis, Duration*, int64_t)},
	{"ofMinutes", "(J)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofMinutes, Duration*, int64_t)},
	{"ofNanos", "(J)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofNanos, Duration*, int64_t)},
	{"ofSeconds", "(J)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofSeconds, Duration*, int64_t)},
	{"ofSeconds", "(JJ)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, ofSeconds, Duration*, int64_t, int64_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/Duration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Duration, parse, Duration*, $CharSequence*)},
	{"parseFraction", "(Ljava/lang/CharSequence;III)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Duration, parseFraction, int32_t, $CharSequence*, int32_t, int32_t, int32_t)},
	{"parseNumber", "(Ljava/lang/CharSequence;IIILjava/lang/String;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(Duration, parseNumber, int64_t, $CharSequence*, int32_t, int32_t, int32_t, $String*)},
	{"plus", "(Ljava/time/Duration;)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plus, Duration*, Duration*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plus, Duration*, int64_t, $TemporalUnit*)},
	{"plus", "(JJ)Ljava/time/Duration;", nullptr, $PRIVATE, $method(Duration, plus, Duration*, int64_t, int64_t)},
	{"plusDays", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plusDays, Duration*, int64_t)},
	{"plusHours", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plusHours, Duration*, int64_t)},
	{"plusMillis", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plusMillis, Duration*, int64_t)},
	{"plusMinutes", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plusMinutes, Duration*, int64_t)},
	{"plusNanos", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plusNanos, Duration*, int64_t)},
	{"plusSeconds", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, plusSeconds, Duration*, int64_t)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/Duration;", nullptr, $STATIC, $staticMethod(Duration, readExternal, Duration*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Duration, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"subtractFrom", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Duration, subtractFrom, $Temporal*, $Temporal*)},
	{"toBigDecimalSeconds", "()Ljava/math/BigDecimal;", nullptr, $PRIVATE, $method(Duration, toBigDecimalSeconds, $BigDecimal*)},
	{"toDays", "()J", nullptr, $PUBLIC, $method(Duration, toDays, int64_t)},
	{"toDaysPart", "()J", nullptr, $PUBLIC, $method(Duration, toDaysPart, int64_t)},
	{"toHours", "()J", nullptr, $PUBLIC, $method(Duration, toHours, int64_t)},
	{"toHoursPart", "()I", nullptr, $PUBLIC, $method(Duration, toHoursPart, int32_t)},
	{"toMillis", "()J", nullptr, $PUBLIC, $method(Duration, toMillis, int64_t)},
	{"toMillisPart", "()I", nullptr, $PUBLIC, $method(Duration, toMillisPart, int32_t)},
	{"toMinutes", "()J", nullptr, $PUBLIC, $method(Duration, toMinutes, int64_t)},
	{"toMinutesPart", "()I", nullptr, $PUBLIC, $method(Duration, toMinutesPart, int32_t)},
	{"toNanos", "()J", nullptr, $PUBLIC, $method(Duration, toNanos, int64_t)},
	{"toNanosPart", "()I", nullptr, $PUBLIC, $method(Duration, toNanosPart, int32_t)},
	{"toSeconds", "()J", nullptr, $PUBLIC, $method(Duration, toSeconds, int64_t)},
	{"toSecondsPart", "()I", nullptr, $PUBLIC, $method(Duration, toSecondsPart, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Duration, toString, $String*)},
	{"truncatedTo", "(Ljava/time/temporal/TemporalUnit;)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, truncatedTo, Duration*, $TemporalUnit*)},
	{"withNanos", "(I)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, withNanos, Duration*, int32_t)},
	{"withSeconds", "(J)Ljava/time/Duration;", nullptr, $PUBLIC, $method(Duration, withSeconds, Duration*, int64_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(Duration, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Duration, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _Duration_InnerClassesInfo_[] = {
	{"java.time.Duration$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.time.Duration$DurationUnits", "java.time.Duration", "DurationUnits", $PRIVATE | $STATIC},
	{"java.time.Duration$Lazy", "java.time.Duration", "Lazy", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Duration_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.Duration",
	"java.lang.Object",
	"java.time.temporal.TemporalAmount,java.lang.Comparable,java.io.Serializable",
	_Duration_FieldInfo_,
	_Duration_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/TemporalAmount;Ljava/lang/Comparable<Ljava/time/Duration;>;Ljava/io/Serializable;",
	nullptr,
	_Duration_InnerClassesInfo_,
	_Duration_Annotations_,
	nullptr,
	"java.time.Duration$1,java.time.Duration$DurationUnits,java.time.Duration$Lazy"
};

$Object* allocate$Duration($Class* clazz) {
	return $of($alloc(Duration));
}

$Object* Duration::clone() {
	 return this->$TemporalAmount::clone();
}

void Duration::finalize() {
	this->$TemporalAmount::finalize();
}

Duration* Duration::ZERO = nullptr;
$BigInteger* Duration::BI_NANOS_PER_SECOND = nullptr;

Duration* Duration::ofDays(int64_t days) {
	$init(Duration);
	return create($Math::multiplyExact(days, 0x00015180), 0);
}

Duration* Duration::ofHours(int64_t hours) {
	$init(Duration);
	return create($Math::multiplyExact(hours, 3600), 0);
}

Duration* Duration::ofMinutes(int64_t minutes) {
	$init(Duration);
	return create($Math::multiplyExact(minutes, 60), 0);
}

Duration* Duration::ofSeconds(int64_t seconds) {
	$init(Duration);
	return create(seconds, 0);
}

Duration* Duration::ofSeconds(int64_t seconds, int64_t nanoAdjustment) {
	$init(Duration);
	int64_t secs = $Math::addExact(seconds, $Math::floorDiv(nanoAdjustment, (int64_t)1000000000));
	int32_t nos = (int32_t)$Math::floorMod(nanoAdjustment, (int64_t)1000000000);
	return create(secs, nos);
}

Duration* Duration::ofMillis(int64_t millis) {
	$init(Duration);
	int64_t secs = millis / 1000;
	int32_t mos = (int32_t)(millis % 1000);
	if (mos < 0) {
		mos += 1000;
		--secs;
	}
	return create(secs, mos * 0x000F4240);
}

Duration* Duration::ofNanos(int64_t nanos) {
	$init(Duration);
	int64_t secs = $div(nanos, (int64_t)1000000000);
	int32_t nos = (int32_t)($mod(nanos, (int64_t)1000000000));
	if (nos < 0) {
		nos += 1000000000;
		--secs;
	}
	return create(secs, nos);
}

Duration* Duration::of(int64_t amount, $TemporalUnit* unit) {
	$init(Duration);
	return $nc(Duration::ZERO)->plus(amount, unit);
}

Duration* Duration::from($TemporalAmount* amount) {
	$init(Duration);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(amount), "amount"_s);
	$var(Duration, duration, Duration::ZERO);
	{
		$var($Iterator, i$, $nc($($nc(amount)->getUnits()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TemporalUnit, unit, $cast($TemporalUnit, i$->next()));
			{
				$assign(duration, $nc(duration)->plus(amount->get(unit), unit));
			}
		}
	}
	return duration;
}

Duration* Duration::parse($CharSequence* text) {
	$init(Duration);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(text), "text"_s);
	$init($Duration$Lazy);
	$var($Matcher, matcher, $nc($Duration$Lazy::PATTERN)->matcher(text));
	if ($nc(matcher)->matches()) {
		$var($CharSequence, var$0, text);
		int32_t var$1 = matcher->start(3);
		if (!charMatch(var$0, var$1, matcher->end(3), u'T')) {
			$var($CharSequence, var$2, text);
			int32_t var$3 = matcher->start(1);
			bool negate = charMatch(var$2, var$3, matcher->end(1), u'-');
			int32_t dayStart = matcher->start(2);
			int32_t dayEnd = matcher->end(2);
			int32_t hourStart = matcher->start(4);
			int32_t hourEnd = matcher->end(4);
			int32_t minuteStart = matcher->start(5);
			int32_t minuteEnd = matcher->end(5);
			int32_t secondStart = matcher->start(6);
			int32_t secondEnd = matcher->end(6);
			int32_t fractionStart = matcher->start(7);
			int32_t fractionEnd = matcher->end(7);
			if (dayStart >= 0 || hourStart >= 0 || minuteStart >= 0 || secondStart >= 0) {
				int64_t daysAsSecs = parseNumber(text, dayStart, dayEnd, 0x00015180, "days"_s);
				int64_t hoursAsSecs = parseNumber(text, hourStart, hourEnd, 3600, "hours"_s);
				int64_t minsAsSecs = parseNumber(text, minuteStart, minuteEnd, 60, "minutes"_s);
				int64_t seconds = parseNumber(text, secondStart, secondEnd, 1, "seconds"_s);
				bool negativeSecs = secondStart >= 0 && $nc(text)->charAt(secondStart) == u'-';
				int32_t nanos = parseFraction(text, fractionStart, fractionEnd, negativeSecs ? -1 : 1);
				try {
					return create(negate, daysAsSecs, hoursAsSecs, minsAsSecs, seconds, nanos);
				} catch ($ArithmeticException& ex) {
					$throw($cast($DateTimeParseException, $($$new($DateTimeParseException, "Text cannot be parsed to a Duration: overflow"_s, text, 0)->initCause(ex))));
				}
			}
		}
	}
	$throwNew($DateTimeParseException, "Text cannot be parsed to a Duration"_s, text, 0);
	$shouldNotReachHere();
}

bool Duration::charMatch($CharSequence* text, int32_t start, int32_t end, char16_t c) {
	$init(Duration);
	return (start >= 0 && end == start + 1 && $nc(text)->charAt(start) == c);
}

int64_t Duration::parseNumber($CharSequence* text, int32_t start, int32_t end, int32_t multiplier, $String* errorText) {
	$init(Duration);
	$useLocalCurrentObjectStackCache();
	if (start < 0 || end < 0) {
		return 0;
	}
	try {
		int64_t val = $Long::parseLong(text, start, end, 10);
		return $Math::multiplyExact(val, multiplier);
	} catch ($NumberFormatException& ex) {
		$throw($cast($DateTimeParseException, $($$new($DateTimeParseException, $$str({"Text cannot be parsed to a Duration: "_s, errorText}), text, 0)->initCause(ex))));
	} catch ($ArithmeticException& ex) {
		$throw($cast($DateTimeParseException, $($$new($DateTimeParseException, $$str({"Text cannot be parsed to a Duration: "_s, errorText}), text, 0)->initCause(ex))));
	}
	$shouldNotReachHere();
}

int32_t Duration::parseFraction($CharSequence* text, int32_t start, int32_t end, int32_t negate) {
	$init(Duration);
	$useLocalCurrentObjectStackCache();
	if (start < 0 || end < 0 || end - start == 0) {
		return 0;
	}
	try {
		int32_t fraction = $Integer::parseInt(text, start, end, 10);
		for (int32_t i = end - start; i < 9; ++i) {
			fraction *= 10;
		}
		return fraction * negate;
	} catch ($NumberFormatException& ex) {
		$throw($cast($DateTimeParseException, $($$new($DateTimeParseException, "Text cannot be parsed to a Duration: fraction"_s, text, 0)->initCause(ex))));
	} catch ($ArithmeticException& ex) {
		$throw($cast($DateTimeParseException, $($$new($DateTimeParseException, "Text cannot be parsed to a Duration: fraction"_s, text, 0)->initCause(ex))));
	}
	$shouldNotReachHere();
}

Duration* Duration::create(bool negate, int64_t daysAsSecs, int64_t hoursAsSecs, int64_t minsAsSecs, int64_t secs, int32_t nanos) {
	$init(Duration);
	int64_t seconds = $Math::addExact(daysAsSecs, $Math::addExact(hoursAsSecs, $Math::addExact(minsAsSecs, secs)));
	if (negate) {
		return $nc($(ofSeconds(seconds, nanos)))->negated();
	}
	return ofSeconds(seconds, nanos);
}

Duration* Duration::between($Temporal* startInclusive, $Temporal* endExclusive) {
	$init(Duration);
	try {
		$init($ChronoUnit);
		return ofNanos($nc(startInclusive)->until(endExclusive, $ChronoUnit::NANOS));
	} catch ($DateTimeException& ex) {
		$init($ChronoUnit);
		int64_t secs = $nc(startInclusive)->until(endExclusive, $ChronoUnit::SECONDS);
		int64_t nanos = 0;
		try {
			$init($ChronoField);
			int64_t var$0 = $nc(endExclusive)->getLong($ChronoField::NANO_OF_SECOND);
			nanos = var$0 - startInclusive->getLong($ChronoField::NANO_OF_SECOND);
			if (secs > 0 && nanos < 0) {
				++secs;
			} else if (secs < 0 && nanos > 0) {
				--secs;
			}
		} catch ($DateTimeException& ex2) {
			nanos = 0;
		}
		return ofSeconds(secs, nanos);
	} catch ($ArithmeticException& ex) {
		$init($ChronoUnit);
		int64_t secs = $nc(startInclusive)->until(endExclusive, $ChronoUnit::SECONDS);
		int64_t nanos = 0;
		try {
			$init($ChronoField);
			int64_t var$1 = $nc(endExclusive)->getLong($ChronoField::NANO_OF_SECOND);
			nanos = var$1 - startInclusive->getLong($ChronoField::NANO_OF_SECOND);
			if (secs > 0 && nanos < 0) {
				++secs;
			} else if (secs < 0 && nanos > 0) {
				--secs;
			}
		} catch ($DateTimeException& ex2) {
			nanos = 0;
		}
		return ofSeconds(secs, nanos);
	}
	$shouldNotReachHere();
}

Duration* Duration::create(int64_t seconds, int32_t nanoAdjustment) {
	$init(Duration);
	if ((seconds | nanoAdjustment) == 0) {
		return Duration::ZERO;
	}
	return $new(Duration, seconds, nanoAdjustment);
}

void Duration::init$(int64_t seconds, int32_t nanos) {
	this->seconds = seconds;
	this->nanos = nanos;
}

int64_t Duration::get($TemporalUnit* unit) {
	$init($ChronoUnit);
	if ($equals(unit, $ChronoUnit::SECONDS)) {
		return this->seconds;
	} else {
		if ($equals(unit, $ChronoUnit::NANOS)) {
			return this->nanos;
		} else {
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
}

$List* Duration::getUnits() {
	$init($Duration$DurationUnits);
	return $Duration$DurationUnits::UNITS;
}

bool Duration::isZero() {
	return (this->seconds | this->nanos) == 0;
}

bool Duration::isNegative() {
	return this->seconds < 0;
}

int64_t Duration::getSeconds() {
	return this->seconds;
}

int32_t Duration::getNano() {
	return this->nanos;
}

Duration* Duration::withSeconds(int64_t seconds) {
	return create(seconds, this->nanos);
}

Duration* Duration::withNanos(int32_t nanoOfSecond) {
	$init($ChronoField);
	$ChronoField::NANO_OF_SECOND->checkValidIntValue(nanoOfSecond);
	return create(this->seconds, nanoOfSecond);
}

Duration* Duration::plus(Duration* duration) {
	int64_t var$0 = $nc(duration)->getSeconds();
	return plus(var$0, (int64_t)duration->getNano());
}

Duration* Duration::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(unit), "unit"_s);
	$init($ChronoUnit);
	if ($equals(unit, $ChronoUnit::DAYS)) {
		return plus($Math::multiplyExact(amountToAdd, 0x00015180), (int64_t)0);
	}
	if ($nc(unit)->isDurationEstimated()) {
		$throwNew($UnsupportedTemporalTypeException, "Unit must not have an estimated duration"_s);
	}
	if (amountToAdd == 0) {
		return this;
	}
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			$init($Duration$1);
			switch ($nc($Duration$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return plusNanos(amountToAdd);
				}
			case 2:
				{
					return $nc($(plusSeconds(($div(amountToAdd, ((int64_t)1000000 * 1000))) * 1000)))->plusNanos(($mod(amountToAdd, ((int64_t)1000000 * 1000))) * 1000);
				}
			case 3:
				{
					return plusMillis(amountToAdd);
				}
			case 4:
				{
					return plusSeconds(amountToAdd);
				}
			}
			return plusSeconds($Math::multiplyExact($nc($($nc(unit)->getDuration()))->seconds, amountToAdd));
		}
	}
	$var(Duration, duration, $nc($($nc(unit)->getDuration()))->multipliedBy(amountToAdd));
	return $nc($(plusSeconds($nc(duration)->getSeconds())))->plusNanos($nc(duration)->getNano());
}

Duration* Duration::plusDays(int64_t daysToAdd) {
	return plus($Math::multiplyExact(daysToAdd, 0x00015180), (int64_t)0);
}

Duration* Duration::plusHours(int64_t hoursToAdd) {
	return plus($Math::multiplyExact(hoursToAdd, 3600), (int64_t)0);
}

Duration* Duration::plusMinutes(int64_t minutesToAdd) {
	return plus($Math::multiplyExact(minutesToAdd, 60), (int64_t)0);
}

Duration* Duration::plusSeconds(int64_t secondsToAdd) {
	return plus(secondsToAdd, (int64_t)0);
}

Duration* Duration::plusMillis(int64_t millisToAdd) {
	return plus(millisToAdd / 1000, (millisToAdd % 1000) * 0x000F4240);
}

Duration* Duration::plusNanos(int64_t nanosToAdd) {
	return plus((int64_t)0, nanosToAdd);
}

Duration* Duration::plus(int64_t secondsToAdd, int64_t nanosToAdd) {
	if ((secondsToAdd | nanosToAdd) == 0) {
		return this;
	}
	int64_t epochSec = $Math::addExact(this->seconds, secondsToAdd);
	epochSec = $Math::addExact(epochSec, $div(nanosToAdd, (int64_t)1000000000));
	nanosToAdd = $mod(nanosToAdd, (int64_t)1000000000);
	int64_t nanoAdjustment = this->nanos + nanosToAdd;
	return ofSeconds(epochSec, nanoAdjustment);
}

Duration* Duration::minus(Duration* duration) {
	int64_t secsToSubtract = $nc(duration)->getSeconds();
	int32_t nanosToSubtract = duration->getNano();
	if (secsToSubtract == $Long::MIN_VALUE) {
		return $nc($(plus($Long::MAX_VALUE, (int64_t)(-nanosToSubtract))))->plus((int64_t)1, (int64_t)0);
	}
	return plus(-secsToSubtract, (int64_t)(-nanosToSubtract));
}

Duration* Duration::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus((int64_t)1, unit) : plus(-amountToSubtract, unit));
}

Duration* Duration::minusDays(int64_t daysToSubtract) {
	return (daysToSubtract == $Long::MIN_VALUE ? $nc($(plusDays($Long::MAX_VALUE)))->plusDays(1) : plusDays(-daysToSubtract));
}

Duration* Duration::minusHours(int64_t hoursToSubtract) {
	return (hoursToSubtract == $Long::MIN_VALUE ? $nc($(plusHours($Long::MAX_VALUE)))->plusHours(1) : plusHours(-hoursToSubtract));
}

Duration* Duration::minusMinutes(int64_t minutesToSubtract) {
	return (minutesToSubtract == $Long::MIN_VALUE ? $nc($(plusMinutes($Long::MAX_VALUE)))->plusMinutes(1) : plusMinutes(-minutesToSubtract));
}

Duration* Duration::minusSeconds(int64_t secondsToSubtract) {
	return (secondsToSubtract == $Long::MIN_VALUE ? $nc($(plusSeconds($Long::MAX_VALUE)))->plusSeconds(1) : plusSeconds(-secondsToSubtract));
}

Duration* Duration::minusMillis(int64_t millisToSubtract) {
	return (millisToSubtract == $Long::MIN_VALUE ? $nc($(plusMillis($Long::MAX_VALUE)))->plusMillis(1) : plusMillis(-millisToSubtract));
}

Duration* Duration::minusNanos(int64_t nanosToSubtract) {
	return (nanosToSubtract == $Long::MIN_VALUE ? $nc($(plusNanos($Long::MAX_VALUE)))->plusNanos(1) : plusNanos(-nanosToSubtract));
}

Duration* Duration::multipliedBy(int64_t multiplicand) {
	$useLocalCurrentObjectStackCache();
	if (multiplicand == 0) {
		return Duration::ZERO;
	}
	if (multiplicand == 1) {
		return this;
	}
	return create($($nc($(toBigDecimalSeconds()))->multiply($($BigDecimal::valueOf(multiplicand)))));
}

Duration* Duration::dividedBy(int64_t divisor) {
	$useLocalCurrentObjectStackCache();
	if (divisor == 0) {
		$throwNew($ArithmeticException, "Cannot divide by zero"_s);
	}
	if (divisor == 1) {
		return this;
	}
	$init($RoundingMode);
	return create($($nc($(toBigDecimalSeconds()))->divide($($BigDecimal::valueOf(divisor)), $RoundingMode::DOWN)));
}

int64_t Duration::dividedBy(Duration* divisor) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(divisor), "divisor"_s);
	$var($BigDecimal, dividendBigD, toBigDecimalSeconds());
	$var($BigDecimal, divisorBigD, $nc(divisor)->toBigDecimalSeconds());
	return $nc($($nc(dividendBigD)->divideToIntegralValue(divisorBigD)))->longValueExact();
}

$BigDecimal* Duration::toBigDecimalSeconds() {
	$useLocalCurrentObjectStackCache();
	return $nc($($BigDecimal::valueOf(this->seconds)))->add($($BigDecimal::valueOf(this->nanos, 9)));
}

Duration* Duration::create($BigDecimal* seconds) {
	$init(Duration);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, nanos, $nc($($nc(seconds)->movePointRight(9)))->toBigIntegerExact());
	$var($BigIntegerArray, divRem, $nc(nanos)->divideAndRemainder(Duration::BI_NANOS_PER_SECOND));
	if ($nc($nc(divRem)->get(0))->bitLength() > 63) {
		$throwNew($ArithmeticException, $$str({"Exceeds capacity of Duration: "_s, nanos}));
	}
	int64_t var$0 = $nc($nc(divRem)->get(0))->longValue();
	return ofSeconds(var$0, $nc(divRem->get(1))->intValue());
}

Duration* Duration::negated() {
	return multipliedBy(-1);
}

Duration* Duration::abs() {
	return isNegative() ? negated() : this;
}

$Temporal* Duration::addTo($Temporal* temporal$renamed) {
	$var($Temporal, temporal, temporal$renamed);
	if (this->seconds != 0) {
		$init($ChronoUnit);
		$assign(temporal, $nc(temporal)->plus(this->seconds, $ChronoUnit::SECONDS));
	}
	if (this->nanos != 0) {
		$init($ChronoUnit);
		$assign(temporal, $nc(temporal)->plus(this->nanos, $ChronoUnit::NANOS));
	}
	return temporal;
}

$Temporal* Duration::subtractFrom($Temporal* temporal$renamed) {
	$var($Temporal, temporal, temporal$renamed);
	if (this->seconds != 0) {
		$init($ChronoUnit);
		$assign(temporal, $nc(temporal)->minus(this->seconds, $ChronoUnit::SECONDS));
	}
	if (this->nanos != 0) {
		$init($ChronoUnit);
		$assign(temporal, $nc(temporal)->minus(this->nanos, $ChronoUnit::NANOS));
	}
	return temporal;
}

int64_t Duration::toDays() {
	return this->seconds / 0x00015180;
}

int64_t Duration::toHours() {
	return this->seconds / 3600;
}

int64_t Duration::toMinutes() {
	return this->seconds / 60;
}

int64_t Duration::toSeconds() {
	return this->seconds;
}

int64_t Duration::toMillis() {
	int64_t tempSeconds = this->seconds;
	int64_t tempNanos = this->nanos;
	if (tempSeconds < 0) {
		tempSeconds = tempSeconds + 1;
		tempNanos = tempNanos - (int64_t)1000000000;
	}
	int64_t millis = $Math::multiplyExact(tempSeconds, 1000);
	millis = $Math::addExact(millis, $div(tempNanos, (int64_t)1000000));
	return millis;
}

int64_t Duration::toNanos() {
	int64_t tempSeconds = this->seconds;
	int64_t tempNanos = this->nanos;
	if (tempSeconds < 0) {
		tempSeconds = tempSeconds + 1;
		tempNanos = tempNanos - (int64_t)1000000000;
	}
	int64_t totalNanos = $Math::multiplyExact(tempSeconds, (int64_t)1000000000);
	totalNanos = $Math::addExact(totalNanos, tempNanos);
	return totalNanos;
}

int64_t Duration::toDaysPart() {
	return this->seconds / 0x00015180;
}

int32_t Duration::toHoursPart() {
	return (int32_t)(toHours() % 24);
}

int32_t Duration::toMinutesPart() {
	return (int32_t)(toMinutes() % 60);
}

int32_t Duration::toSecondsPart() {
	return (int32_t)(this->seconds % 60);
}

int32_t Duration::toMillisPart() {
	return this->nanos / 0x000F4240;
}

int32_t Duration::toNanosPart() {
	return this->nanos;
}

Duration* Duration::truncatedTo($TemporalUnit* unit) {
	$Objects::requireNonNull($of(unit), "unit"_s);
	$init($ChronoUnit);
	if ($equals(unit, $ChronoUnit::SECONDS) && (this->seconds >= 0 || this->nanos == 0)) {
		return $new(Duration, this->seconds, 0);
	} else {
		if ($equals(unit, $ChronoUnit::NANOS)) {
			return this;
		}
	}
	$var(Duration, unitDur, $nc(unit)->getDuration());
	if ($nc(unitDur)->getSeconds() > $LocalTime::SECONDS_PER_DAY) {
		$throwNew($UnsupportedTemporalTypeException, "Unit is too large to be used for truncation"_s);
	}
	int64_t dur = $nc(unitDur)->toNanos();
	if (($mod($LocalTime::NANOS_PER_DAY, dur)) != 0) {
		$throwNew($UnsupportedTemporalTypeException, "Unit must divide into a standard day without remainder"_s);
	}
	int64_t nod = ($mod(this->seconds, $LocalTime::SECONDS_PER_DAY)) * $LocalTime::NANOS_PER_SECOND + this->nanos;
	int64_t result = ($div(nod, dur)) * dur;
	return plusNanos(result - nod);
}

int32_t Duration::compareTo(Duration* otherDuration) {
	int32_t cmp = $Long::compare(this->seconds, $nc(otherDuration)->seconds);
	if (cmp != 0) {
		return cmp;
	}
	return this->nanos - $nc(otherDuration)->nanos;
}

bool Duration::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	$var(Duration, otherDuration, nullptr);
	bool var$2 = $instanceOf(Duration, other);
	if (var$2) {
		$assign(otherDuration, $cast(Duration, other));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && this->seconds == $nc(otherDuration)->seconds;
	return var$0 && this->nanos == otherDuration->nanos;
}

int32_t Duration::hashCode() {
	return ((int32_t)(this->seconds ^ ((int64_t)((uint64_t)this->seconds >> 32)))) + (51 * this->nanos);
}

$String* Duration::toString() {
	if (this == Duration::ZERO) {
		return "PT0S"_s;
	}
	int64_t effectiveTotalSecs = this->seconds;
	if (this->seconds < 0 && this->nanos > 0) {
		++effectiveTotalSecs;
	}
	int64_t hours = effectiveTotalSecs / 3600;
	int32_t minutes = (int32_t)((effectiveTotalSecs % 3600) / 60);
	int32_t secs = (int32_t)(effectiveTotalSecs % 60);
	$var($StringBuilder, buf, $new($StringBuilder, 24));
	buf->append("PT"_s);
	if (hours != 0) {
		buf->append(hours)->append(u'H');
	}
	if (minutes != 0) {
		buf->append(minutes)->append(u'M');
	}
	if (secs == 0 && this->nanos == 0 && buf->length() > 2) {
		return buf->toString();
	}
	if (this->seconds < 0 && this->nanos > 0) {
		if (secs == 0) {
			buf->append("-0"_s);
		} else {
			buf->append(secs);
		}
	} else {
		buf->append(secs);
	}
	if (this->nanos > 0) {
		int32_t pos = buf->length();
		if (this->seconds < 0) {
			buf->append(2 * (int64_t)1000000000 - this->nanos);
		} else {
			buf->append(this->nanos + (int64_t)1000000000);
		}
		while (buf->charAt(buf->length() - 1) == u'0') {
			buf->setLength(buf->length() - 1);
		}
		buf->setCharAt(pos, u'.');
	}
	buf->append(u'S');
	return buf->toString();
}

$Object* Duration::writeReplace() {
	return $of($new($Ser, $Ser::DURATION_TYPE, this));
}

void Duration::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void Duration::writeExternal($DataOutput* out) {
	$nc(out)->writeLong(this->seconds);
	out->writeInt(this->nanos);
}

Duration* Duration::readExternal($DataInput* in) {
	$init(Duration);
	int64_t seconds = $nc(in)->readLong();
	int32_t nanos = in->readInt();
	return Duration::ofSeconds(seconds, nanos);
}

int32_t Duration::compareTo(Object$* otherDuration) {
	return this->compareTo($cast(Duration, otherDuration));
}

void clinit$Duration($Class* class$) {
	$assignStatic(Duration::ZERO, $new(Duration, 0, 0));
	$assignStatic(Duration::BI_NANOS_PER_SECOND, $BigInteger::valueOf((int64_t)1000000000));
}

Duration::Duration() {
}

$Class* Duration::load$($String* name, bool initialize) {
	$loadClass(Duration, name, initialize, &_Duration_ClassInfo_, clinit$Duration, allocate$Duration);
	return class$;
}

$Class* Duration::class$ = nullptr;

	} // time
} // java