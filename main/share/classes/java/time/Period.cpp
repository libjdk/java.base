#include <java/time/Period.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/time/DateTimeException.h>
#include <java/time/LocalDate.h>
#include <java/time/Ser.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoPeriod.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeParseException.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef CASE_INSENSITIVE
#undef DAYS
#undef INSTANCE
#undef MAX_VALUE
#undef MIN_VALUE
#undef MONTHS
#undef PATTERN
#undef PERIOD_TYPE
#undef SUPPORTED_UNITS
#undef YEARS
#undef ZERO

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
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $DateTimeException = ::java::time::DateTimeException;
using $LocalDate = ::java::time::LocalDate;
using $Ser = ::java::time::Ser;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoPeriod = ::java::time::chrono::ChronoPeriod;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeParseException = ::java::time::format::DateTimeParseException;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;

namespace java {
	namespace time {

$CompoundAttribute _Period_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _Period_FieldInfo_[] = {
	{"ZERO", "Ljava/time/Period;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Period, ZERO)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Period, serialVersionUID)},
	{"PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Period, PATTERN)},
	{"SUPPORTED_UNITS", "Ljava/util/List;", "Ljava/util/List<Ljava/time/temporal/TemporalUnit;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Period, SUPPORTED_UNITS)},
	{"years", "I", nullptr, $PRIVATE | $FINAL, $field(Period, years)},
	{"months", "I", nullptr, $PRIVATE | $FINAL, $field(Period, months)},
	{"days", "I", nullptr, $PRIVATE | $FINAL, $field(Period, days)},
	{}
};

$MethodInfo _Period_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(III)V", nullptr, $PRIVATE, $method(Period, init$, void, int32_t, int32_t, int32_t)},
	{"addTo", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Period, addTo, $Temporal*, $Temporal*)},
	{"between", "(Ljava/time/LocalDate;Ljava/time/LocalDate;)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, between, Period*, $LocalDate*, $LocalDate*)},
	{"charMatch", "(Ljava/lang/CharSequence;IIC)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Period, charMatch, bool, $CharSequence*, int32_t, int32_t, char16_t)},
	{"create", "(III)Ljava/time/Period;", nullptr, $PRIVATE | $STATIC, $staticMethod(Period, create, Period*, int32_t, int32_t, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Period, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, from, Period*, $TemporalAmount*)},
	{"get", "(Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(Period, get, int64_t, $TemporalUnit*)},
	{"getChronology", "()Ljava/time/chrono/IsoChronology;", nullptr, $PUBLIC, $virtualMethod(Period, getChronology, $Chronology*)},
	{"getDays", "()I", nullptr, $PUBLIC, $method(Period, getDays, int32_t)},
	{"getMonths", "()I", nullptr, $PUBLIC, $method(Period, getMonths, int32_t)},
	{"getUnits", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/temporal/TemporalUnit;>;", $PUBLIC, $virtualMethod(Period, getUnits, $List*)},
	{"getYears", "()I", nullptr, $PUBLIC, $method(Period, getYears, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Period, hashCode, int32_t)},
	{"isNegative", "()Z", nullptr, $PUBLIC, $virtualMethod(Period, isNegative, bool)},
	{"isZero", "()Z", nullptr, $PUBLIC, $virtualMethod(Period, isZero, bool)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(Period, minus, Period*, $TemporalAmount*)},
	{"minusDays", "(J)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, minusDays, Period*, int64_t)},
	{"minusMonths", "(J)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, minusMonths, Period*, int64_t)},
	{"minusYears", "(J)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, minusYears, Period*, int64_t)},
	{"multipliedBy", "(I)Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(Period, multipliedBy, Period*, int32_t)},
	{"negated", "()Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(Period, negated, Period*)},
	{"normalized", "()Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(Period, normalized, Period*)},
	{"of", "(III)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, of, Period*, int32_t, int32_t, int32_t)},
	{"ofDays", "(I)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, ofDays, Period*, int32_t)},
	{"ofMonths", "(I)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, ofMonths, Period*, int32_t)},
	{"ofWeeks", "(I)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, ofWeeks, Period*, int32_t)},
	{"ofYears", "(I)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, ofYears, Period*, int32_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/Period;", nullptr, $PUBLIC | $STATIC, $staticMethod(Period, parse, Period*, $CharSequence*)},
	{"parseNumber", "(Ljava/lang/CharSequence;III)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Period, parseNumber, int32_t, $CharSequence*, int32_t, int32_t, int32_t)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(Period, plus, Period*, $TemporalAmount*)},
	{"plusDays", "(J)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, plusDays, Period*, int64_t)},
	{"plusMonths", "(J)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, plusMonths, Period*, int64_t)},
	{"plusYears", "(J)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, plusYears, Period*, int64_t)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/Period;", nullptr, $STATIC, $staticMethod(Period, readExternal, Period*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Period, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"subtractFrom", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Period, subtractFrom, $Temporal*, $Temporal*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Period, toString, $String*)},
	{"toTotalMonths", "()J", nullptr, $PUBLIC, $method(Period, toTotalMonths, int64_t)},
	{"validateChrono", "(Ljava/time/temporal/TemporalAccessor;)V", nullptr, $PRIVATE, $method(Period, validateChrono, void, $TemporalAccessor*)},
	{"withDays", "(I)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, withDays, Period*, int32_t)},
	{"withMonths", "(I)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, withMonths, Period*, int32_t)},
	{"withYears", "(I)Ljava/time/Period;", nullptr, $PUBLIC, $method(Period, withYears, Period*, int32_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(Period, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Period, writeReplace, $Object*)},
	{}
};

$ClassInfo _Period_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.Period",
	"java.lang.Object",
	"java.time.chrono.ChronoPeriod,java.io.Serializable",
	_Period_FieldInfo_,
	_Period_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_Period_Annotations_
};

$Object* allocate$Period($Class* clazz) {
	return $of($alloc(Period));
}

$Object* Period::clone() {
	 return this->$ChronoPeriod::clone();
}

void Period::finalize() {
	this->$ChronoPeriod::finalize();
}

Period* Period::ZERO = nullptr;
$Pattern* Period::PATTERN = nullptr;
$List* Period::SUPPORTED_UNITS = nullptr;

Period* Period::ofYears(int32_t years) {
	$init(Period);
	return create(years, 0, 0);
}

Period* Period::ofMonths(int32_t months) {
	$init(Period);
	return create(0, months, 0);
}

Period* Period::ofWeeks(int32_t weeks) {
	$init(Period);
	return create(0, 0, $Math::multiplyExact(weeks, 7));
}

Period* Period::ofDays(int32_t days) {
	$init(Period);
	return create(0, 0, days);
}

Period* Period::of(int32_t years, int32_t months, int32_t days) {
	$init(Period);
	return create(years, months, days);
}

Period* Period::from($TemporalAmount* amount) {
	$init(Period);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf(Period, amount)) {
		return $cast(Period, amount);
	}
	if ($instanceOf($ChronoPeriod, amount)) {
		$init($IsoChronology);
		if ($nc($IsoChronology::INSTANCE)->equals($($nc(($cast($ChronoPeriod, amount)))->getChronology())) == false) {
			$throwNew($DateTimeException, $$str({"Period requires ISO chronology: "_s, amount}));
		}
	}
	$Objects::requireNonNull($of(amount), "amount"_s);
	int32_t years = 0;
	int32_t months = 0;
	int32_t days = 0;
	{
		$var($Iterator, i$, $nc($($nc(amount)->getUnits()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TemporalUnit, unit, $cast($TemporalUnit, i$->next()));
			{
				int64_t unitAmount = amount->get(unit);
				$init($ChronoUnit);
				if ($equals(unit, $ChronoUnit::YEARS)) {
					years = $Math::toIntExact(unitAmount);
				} else {
					if ($equals(unit, $ChronoUnit::MONTHS)) {
						months = $Math::toIntExact(unitAmount);
					} else {
						if ($equals(unit, $ChronoUnit::DAYS)) {
							days = $Math::toIntExact(unitAmount);
						} else {
							$throwNew($DateTimeException, $$str({"Unit must be Years, Months or Days, but was "_s, unit}));
						}
					}
				}
			}
		}
	}
	return create(years, months, days);
}

Period* Period::parse($CharSequence* text) {
	$init(Period);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(text), "text"_s);
	$var($Matcher, matcher, $nc(Period::PATTERN)->matcher(text));
	if ($nc(matcher)->matches()) {
		$var($CharSequence, var$0, text);
		int32_t var$1 = matcher->start(1);
		int32_t negate = (charMatch(var$0, var$1, matcher->end(1), u'-') ? -1 : 1);
		int32_t yearStart = matcher->start(2);
		int32_t yearEnd = matcher->end(2);
		int32_t monthStart = matcher->start(3);
		int32_t monthEnd = matcher->end(3);
		int32_t weekStart = matcher->start(4);
		int32_t weekEnd = matcher->end(4);
		int32_t dayStart = matcher->start(5);
		int32_t dayEnd = matcher->end(5);
		if (yearStart >= 0 || monthStart >= 0 || weekStart >= 0 || dayStart >= 0) {
			try {
				int32_t years = parseNumber(text, yearStart, yearEnd, negate);
				int32_t months = parseNumber(text, monthStart, monthEnd, negate);
				int32_t weeks = parseNumber(text, weekStart, weekEnd, negate);
				int32_t days = parseNumber(text, dayStart, dayEnd, negate);
				days = $Math::addExact(days, $Math::multiplyExact(weeks, 7));
				return create(years, months, days);
			} catch ($NumberFormatException& ex) {
				$throwNew($DateTimeParseException, "Text cannot be parsed to a Period"_s, text, 0, ex);
			}
		}
	}
	$throwNew($DateTimeParseException, "Text cannot be parsed to a Period"_s, text, 0);
	$shouldNotReachHere();
}

bool Period::charMatch($CharSequence* text, int32_t start, int32_t end, char16_t c) {
	$init(Period);
	return (start >= 0 && end == start + 1 && $nc(text)->charAt(start) == c);
}

int32_t Period::parseNumber($CharSequence* text, int32_t start, int32_t end, int32_t negate) {
	$init(Period);
	if (start < 0 || end < 0) {
		return 0;
	}
	int32_t val = $Integer::parseInt(text, start, end, 10);
	try {
		return $Math::multiplyExact(val, negate);
	} catch ($ArithmeticException& ex) {
		$throwNew($DateTimeParseException, "Text cannot be parsed to a Period"_s, text, 0, ex);
	}
	$shouldNotReachHere();
}

Period* Period::between($LocalDate* startDateInclusive, $LocalDate* endDateExclusive) {
	$init(Period);
	return $cast(Period, $nc(startDateInclusive)->until(endDateExclusive));
}

Period* Period::create(int32_t years, int32_t months, int32_t days) {
	$init(Period);
	if (((years | months) | days) == 0) {
		return Period::ZERO;
	}
	return $new(Period, years, months, days);
}

void Period::init$(int32_t years, int32_t months, int32_t days) {
	this->years = years;
	this->months = months;
	this->days = days;
}

int64_t Period::get($TemporalUnit* unit) {
	$init($ChronoUnit);
	if ($equals(unit, $ChronoUnit::YEARS)) {
		return getYears();
	} else {
		if ($equals(unit, $ChronoUnit::MONTHS)) {
			return getMonths();
		} else {
			if ($equals(unit, $ChronoUnit::DAYS)) {
				return getDays();
			} else {
				$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
			}
		}
	}
}

$List* Period::getUnits() {
	return Period::SUPPORTED_UNITS;
}

$Chronology* Period::getChronology() {
	$init($IsoChronology);
	return $IsoChronology::INSTANCE;
}

bool Period::isZero() {
	return (this == Period::ZERO);
}

bool Period::isNegative() {
	return this->years < 0 || this->months < 0 || this->days < 0;
}

int32_t Period::getYears() {
	return this->years;
}

int32_t Period::getMonths() {
	return this->months;
}

int32_t Period::getDays() {
	return this->days;
}

Period* Period::withYears(int32_t years) {
	if (years == this->years) {
		return this;
	}
	return create(years, this->months, this->days);
}

Period* Period::withMonths(int32_t months) {
	if (months == this->months) {
		return this;
	}
	return create(this->years, months, this->days);
}

Period* Period::withDays(int32_t days) {
	if (days == this->days) {
		return this;
	}
	return create(this->years, this->months, days);
}

Period* Period::plus($TemporalAmount* amountToAdd) {
	$var(Period, isoAmount, Period::from(amountToAdd));
	int32_t var$0 = $Math::addExact(this->years, $nc(isoAmount)->years);
	int32_t var$1 = $Math::addExact(this->months, $nc(isoAmount)->months);
	return create(var$0, var$1, $Math::addExact(this->days, $nc(isoAmount)->days));
}

Period* Period::plusYears(int64_t yearsToAdd) {
	if (yearsToAdd == 0) {
		return this;
	}
	return create($Math::toIntExact($Math::addExact((int64_t)this->years, yearsToAdd)), this->months, this->days);
}

Period* Period::plusMonths(int64_t monthsToAdd) {
	if (monthsToAdd == 0) {
		return this;
	}
	return create(this->years, $Math::toIntExact($Math::addExact((int64_t)this->months, monthsToAdd)), this->days);
}

Period* Period::plusDays(int64_t daysToAdd) {
	if (daysToAdd == 0) {
		return this;
	}
	return create(this->years, this->months, $Math::toIntExact($Math::addExact((int64_t)this->days, daysToAdd)));
}

Period* Period::minus($TemporalAmount* amountToSubtract) {
	$var(Period, isoAmount, Period::from(amountToSubtract));
	int32_t var$0 = $Math::subtractExact(this->years, $nc(isoAmount)->years);
	int32_t var$1 = $Math::subtractExact(this->months, $nc(isoAmount)->months);
	return create(var$0, var$1, $Math::subtractExact(this->days, $nc(isoAmount)->days));
}

Period* Period::minusYears(int64_t yearsToSubtract) {
	return (yearsToSubtract == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-yearsToSubtract));
}

Period* Period::minusMonths(int64_t monthsToSubtract) {
	return (monthsToSubtract == $Long::MIN_VALUE ? $nc($(plusMonths($Long::MAX_VALUE)))->plusMonths(1) : plusMonths(-monthsToSubtract));
}

Period* Period::minusDays(int64_t daysToSubtract) {
	return (daysToSubtract == $Long::MIN_VALUE ? $nc($(plusDays($Long::MAX_VALUE)))->plusDays(1) : plusDays(-daysToSubtract));
}

Period* Period::multipliedBy(int32_t scalar) {
	if (this == Period::ZERO || scalar == 1) {
		return this;
	}
	int32_t var$0 = $Math::multiplyExact(this->years, scalar);
	int32_t var$1 = $Math::multiplyExact(this->months, scalar);
	return create(var$0, var$1, $Math::multiplyExact(this->days, scalar));
}

Period* Period::negated() {
	return multipliedBy(-1);
}

Period* Period::normalized() {
	int64_t totalMonths = toTotalMonths();
	int64_t splitYears = totalMonths / 12;
	int32_t splitMonths = (int32_t)(totalMonths % 12);
	if (splitYears == this->years && splitMonths == this->months) {
		return this;
	}
	return create($Math::toIntExact(splitYears), splitMonths, this->days);
}

int64_t Period::toTotalMonths() {
	return this->years * (int64_t)12 + this->months;
}

$Temporal* Period::addTo($Temporal* temporal$renamed) {
	$var($Temporal, temporal, temporal$renamed);
	validateChrono(temporal);
	if (this->months == 0) {
		if (this->years != 0) {
			$init($ChronoUnit);
			$assign(temporal, $nc(temporal)->plus(this->years, $ChronoUnit::YEARS));
		}
	} else {
		int64_t totalMonths = toTotalMonths();
		if (totalMonths != 0) {
			$init($ChronoUnit);
			$assign(temporal, $nc(temporal)->plus(totalMonths, $ChronoUnit::MONTHS));
		}
	}
	if (this->days != 0) {
		$init($ChronoUnit);
		$assign(temporal, $nc(temporal)->plus(this->days, $ChronoUnit::DAYS));
	}
	return temporal;
}

$Temporal* Period::subtractFrom($Temporal* temporal$renamed) {
	$var($Temporal, temporal, temporal$renamed);
	validateChrono(temporal);
	if (this->months == 0) {
		if (this->years != 0) {
			$init($ChronoUnit);
			$assign(temporal, $nc(temporal)->minus(this->years, $ChronoUnit::YEARS));
		}
	} else {
		int64_t totalMonths = toTotalMonths();
		if (totalMonths != 0) {
			$init($ChronoUnit);
			$assign(temporal, $nc(temporal)->minus(totalMonths, $ChronoUnit::MONTHS));
		}
	}
	if (this->days != 0) {
		$init($ChronoUnit);
		$assign(temporal, $nc(temporal)->minus(this->days, $ChronoUnit::DAYS));
	}
	return temporal;
}

void Period::validateChrono($TemporalAccessor* temporal) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	$var($Chronology, temporalChrono, $cast($Chronology, $nc(temporal)->query($($TemporalQueries::chronology()))));
	$init($IsoChronology);
	if (temporalChrono != nullptr && $nc($IsoChronology::INSTANCE)->equals(temporalChrono) == false) {
		$throwNew($DateTimeException, $$str({"Chronology mismatch, expected: ISO, actual: "_s, $(temporalChrono->getId())}));
	}
}

bool Period::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(Period, other, nullptr);
	bool var$3 = $instanceOf(Period, obj);
	if (var$3) {
		$assign(other, $cast(Period, obj));
		var$3 = true;
	}
	bool var$2 = (var$3);
	bool var$1 = var$2 && this->years == $nc(other)->years;
	bool var$0 = var$1 && this->months == other->months;
	return var$0 && this->days == other->days;
}

int32_t Period::hashCode() {
	int32_t var$0 = this->years + $Integer::rotateLeft(this->months, 8);
	return var$0 + $Integer::rotateLeft(this->days, 16);
}

$String* Period::toString() {
	if (this == Period::ZERO) {
		return "P0D"_s;
	} else {
		$var($StringBuilder, buf, $new($StringBuilder));
		buf->append(u'P');
		if (this->years != 0) {
			buf->append(this->years)->append(u'Y');
		}
		if (this->months != 0) {
			buf->append(this->months)->append(u'M');
		}
		if (this->days != 0) {
			buf->append(this->days)->append(u'D');
		}
		return buf->toString();
	}
}

$Object* Period::writeReplace() {
	return $of($new($Ser, $Ser::PERIOD_TYPE, this));
}

void Period::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void Period::writeExternal($DataOutput* out) {
	$nc(out)->writeInt(this->years);
	out->writeInt(this->months);
	out->writeInt(this->days);
}

Period* Period::readExternal($DataInput* in) {
	$init(Period);
	int32_t years = $nc(in)->readInt();
	int32_t months = in->readInt();
	int32_t days = in->readInt();
	return Period::of(years, months, days);
}

void clinit$Period($Class* class$) {
	$assignStatic(Period::ZERO, $new(Period, 0, 0, 0));
	$assignStatic(Period::PATTERN, $Pattern::compile("([-+]?)P(?:([-+]?[0-9]+)Y)?(?:([-+]?[0-9]+)M)?(?:([-+]?[0-9]+)W)?(?:([-+]?[0-9]+)D)?"_s, $Pattern::CASE_INSENSITIVE));
	$init($ChronoUnit);
	$assignStatic(Period::SUPPORTED_UNITS, $List::of($ChronoUnit::YEARS, $ChronoUnit::MONTHS, $ChronoUnit::DAYS));
}

Period::Period() {
}

$Class* Period::load$($String* name, bool initialize) {
	$loadClass(Period, name, initialize, &_Period_ClassInfo_, clinit$Period, allocate$Period);
	return class$;
}

$Class* Period::class$ = nullptr;

	} // time
} // java