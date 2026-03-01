#include <tck/java/time/chrono/CopticDate.h>

#include <java/lang/Math.h>
#include <java/time/LocalDate.h>
#include <java/time/Period.h>
#include <java/time/Year.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoPeriod.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <tck/java/time/chrono/CopticChronology.h>
#include <tck/java/time/chrono/CopticDate$1.h>
#include <jcpp.h>

#undef ALIGNED_DAY_OF_WEEK_IN_MONTH
#undef ALIGNED_DAY_OF_WEEK_IN_YEAR
#undef ALIGNED_WEEK_OF_MONTH
#undef ALIGNED_WEEK_OF_YEAR
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_YEAR
#undef DOM_RANGE
#undef DOM_RANGE_LEAP
#undef DOM_RANGE_NONLEAP
#undef EPOCH_DAY_DIFFERENCE
#undef INSTANCE
#undef MAX_VALUE
#undef MONTH_OF_YEAR
#undef MOY_RANGE
#undef YEAR_OF_ERA

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $LocalDate = ::java::time::LocalDate;
using $Period = ::java::time::Period;
using $Year = ::java::time::Year;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoPeriod = ::java::time::chrono::ChronoPeriod;
using $Chronology = ::java::time::chrono::Chronology;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $CopticChronology = ::tck::java::time::chrono::CopticChronology;
using $CopticDate$1 = ::tck::java::time::chrono::CopticDate$1;

namespace tck {
	namespace java {
		namespace time {
			namespace chrono {

$FieldInfo _CopticDate_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CopticDate, serialVersionUID)},
	{"EPOCH_DAY_DIFFERENCE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CopticDate, EPOCH_DAY_DIFFERENCE)},
	{"prolepticYear", "I", nullptr, $PRIVATE | $FINAL, $field(CopticDate, prolepticYear)},
	{"month", "S", nullptr, $PRIVATE | $FINAL, $field(CopticDate, month)},
	{"day", "S", nullptr, $PRIVATE | $FINAL, $field(CopticDate, day)},
	{}
};

$MethodInfo _CopticDate_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(III)V", nullptr, 0, $method(CopticDate, init$, void, int32_t, int32_t, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CopticDate, equals, bool, Object$*)},
	{"getChronology", "()Ltck/java/time/chrono/CopticChronology;", nullptr, $PUBLIC, $virtualMethod(CopticDate, getChronology, $Chronology*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(CopticDate, getLong, int64_t, $TemporalField*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CopticDate, hashCode, int32_t)},
	{"lengthOfMonth", "()I", nullptr, $PUBLIC, $virtualMethod(CopticDate, lengthOfMonth, int32_t)},
	{"ofEpochDay", "(J)Ltck/java/time/chrono/CopticDate;", nullptr, $STATIC, $staticMethod(CopticDate, ofEpochDay, CopticDate*, int64_t)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ltck/java/time/chrono/CopticDate;", nullptr, $PUBLIC, $virtualMethod(CopticDate, plus, CopticDate*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ltck/java/time/chrono/CopticDate;", nullptr, $PRIVATE, $method(CopticDate, plusDays, CopticDate*, int64_t)},
	{"plusMonths", "(J)Ltck/java/time/chrono/CopticDate;", nullptr, $PRIVATE, $method(CopticDate, plusMonths, CopticDate*, int64_t)},
	{"plusYears", "(J)Ltck/java/time/chrono/CopticDate;", nullptr, $PRIVATE, $method(CopticDate, plusYears, CopticDate*, int64_t)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(CopticDate, range, $ValueRange*, $TemporalField*)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(CopticDate, readResolve, $Object*)},
	{"resolvePreviousValid", "(III)Ltck/java/time/chrono/CopticDate;", nullptr, $PRIVATE | $STATIC, $staticMethod(CopticDate, resolvePreviousValid, CopticDate*, int32_t, int32_t, int32_t)},
	{"toEpochDay", "()J", nullptr, $PUBLIC, $virtualMethod(CopticDate, toEpochDay, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CopticDate, toString, $String*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(CopticDate, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"until", "(Ljava/time/chrono/ChronoLocalDate;)Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(CopticDate, until, $ChronoPeriod*, $ChronoLocalDate*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ltck/java/time/chrono/CopticDate;", nullptr, $PUBLIC, $virtualMethod(CopticDate, with, CopticDate*, $TemporalField*, int64_t)},
	{}
};

$InnerClassInfo _CopticDate_InnerClassesInfo_[] = {
	{"tck.java.time.chrono.CopticDate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _CopticDate_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"tck.java.time.chrono.CopticDate",
	"java.lang.Object",
	"java.time.chrono.ChronoLocalDate,java.io.Serializable",
	_CopticDate_FieldInfo_,
	_CopticDate_MethodInfo_,
	nullptr,
	nullptr,
	_CopticDate_InnerClassesInfo_,
	nullptr,
	nullptr,
	"tck.java.time.chrono.CopticDate$1"
};

$Object* allocate$CopticDate($Class* clazz) {
	return $of($alloc(CopticDate));
}

$Object* CopticDate::clone() {
	 return this->$ChronoLocalDate::clone();
}

void CopticDate::finalize() {
	this->$ChronoLocalDate::finalize();
}

CopticDate* CopticDate::ofEpochDay(int64_t epochDay) {
	$init(CopticDate);
	epochDay += CopticDate::EPOCH_DAY_DIFFERENCE;
	int32_t prolepticYear = (int32_t)(((epochDay * 4) + 1463) / 1461);
	int32_t startYearEpochDay = (prolepticYear - 1) * 365 + (prolepticYear / 4);
	int32_t doy0 = (int32_t)(epochDay - startYearEpochDay);
	int32_t month = doy0 / 30 + 1;
	int32_t dom = doy0 % 30 + 1;
	return $new(CopticDate, prolepticYear, month, dom);
}

CopticDate* CopticDate::resolvePreviousValid(int32_t prolepticYear, int32_t month, int32_t day) {
	$init(CopticDate);
	if (month == 13 && day > 5) {
		$init($CopticChronology);
		day = $nc($CopticChronology::INSTANCE)->isLeapYear(prolepticYear) ? 6 : 5;
	}
	return $new(CopticDate, prolepticYear, month, day);
}

void CopticDate::init$(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	$init($CopticChronology);
	$init($ChronoField);
	$nc($CopticChronology::MOY_RANGE)->checkValidValue(month, $ChronoField::MONTH_OF_YEAR);
	$var($ValueRange, range, nullptr);
	if (month == 13) {
		$assign(range, $nc($CopticChronology::INSTANCE)->isLeapYear(prolepticYear) ? $CopticChronology::DOM_RANGE_LEAP : $CopticChronology::DOM_RANGE_NONLEAP);
	} else {
		$assign(range, $CopticChronology::DOM_RANGE);
	}
	$nc(range)->checkValidValue(dayOfMonth, $ChronoField::DAY_OF_MONTH);
	this->prolepticYear = prolepticYear;
	this->month = (int16_t)month;
	this->day = (int16_t)dayOfMonth;
}

$Object* CopticDate::readResolve() {
	return $of(this);
}

$Chronology* CopticDate::getChronology() {
	$init($CopticChronology);
	return $CopticChronology::INSTANCE;
}

int32_t CopticDate::lengthOfMonth() {
	switch (this->month) {
	case 13:
		{
			return (isLeapYear() ? 6 : 5);
		}
	default:
		{
			return 30;
		}
	}
}

$ValueRange* CopticDate::range($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoField, field)) {
		if (isSupported(field)) {
			$ChronoField* f = $cast($ChronoField, field);
			$init($CopticDate$1);
			switch ($nc($CopticDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((f))->ordinal())) {
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
					return $ValueRange::of(1, this->month == 13 ? 1 : 5);
				}
			case 4:
				{}
			case 5:
				{
					return (this->prolepticYear <= 0 ? $ValueRange::of(1, $Year::MAX_VALUE + 1) : $ValueRange::of(1, $Year::MAX_VALUE));
				}
			}
			return $nc($($cast($CopticChronology, getChronology())))->range(f);
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->rangeRefinedBy(this);
}

int64_t CopticDate::getLong($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($CopticDate$1);
		switch ($nc($CopticDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
		case 6:
			{
				return $Math::floorMod(toEpochDay() + 3, 7) + 1;
			}
		case 7:
			{
				return ((this->day - 1) % 7) + 1;
			}
		case 8:
			{
				$init($ChronoField);
				return ((get($ChronoField::DAY_OF_YEAR) - 1) % 7) + 1;
			}
		case 1:
			{
				return this->day;
			}
		case 2:
			{
				return (this->month - 1) * 30 + this->day;
			}
		case 9:
			{
				return toEpochDay();
			}
		case 3:
			{
				return ((this->day - 1) / 7) + 1;
			}
		case 10:
			{
				$init($ChronoField);
				return ((get($ChronoField::DAY_OF_YEAR) - 1) / 7) + 1;
			}
		case 11:
			{
				return this->month;
			}
		case 5:
			{
				return (this->prolepticYear >= 1 ? this->prolepticYear : 1 - this->prolepticYear);
			}
		case 4:
			{
				return this->prolepticYear;
			}
		case 12:
			{
				return (this->prolepticYear >= 1 ? 1 : 0);
			}
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->getFrom(this);
}

CopticDate* CopticDate::with($TemporalField* field, int64_t newValue) {
	if ($instanceOf($ChronoField, field)) {
		$ChronoField* f = $cast($ChronoField, field);
		$nc(f)->checkValidValue(newValue);
		int32_t nvalue = (int32_t)newValue;
		$init($CopticDate$1);
		switch ($nc($CopticDate$1::$SwitchMap$java$time$temporal$ChronoField)->get((f)->ordinal())) {
		case 6:
			{
				return plusDays(newValue - get($ChronoField::DAY_OF_WEEK));
			}
		case 7:
			{
				return plusDays(newValue - getLong($ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH));
			}
		case 8:
			{
				return plusDays(newValue - getLong($ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR));
			}
		case 1:
			{
				return resolvePreviousValid(this->prolepticYear, this->month, nvalue);
			}
		case 2:
			{
				return resolvePreviousValid(this->prolepticYear, ((nvalue - 1) / 30) + 1, ((nvalue - 1) % 30) + 1);
			}
		case 9:
			{
				return ofEpochDay(nvalue);
			}
		case 3:
			{
				return plusDays((newValue - getLong($ChronoField::ALIGNED_WEEK_OF_MONTH)) * 7);
			}
		case 10:
			{
				return plusDays((newValue - getLong($ChronoField::ALIGNED_WEEK_OF_YEAR)) * 7);
			}
		case 11:
			{
				return resolvePreviousValid(this->prolepticYear, nvalue, this->day);
			}
		case 5:
			{
				return resolvePreviousValid(this->prolepticYear >= 1 ? nvalue : 1 - nvalue, this->month, this->day);
			}
		case 4:
			{
				return resolvePreviousValid(nvalue, this->month, this->day);
			}
		case 12:
			{
				return resolvePreviousValid(1 - this->prolepticYear, this->month, this->day);
			}
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $cast(CopticDate, $nc(field)->adjustInto(this, newValue));
}

CopticDate* CopticDate::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		$ChronoUnit* f = $cast($ChronoUnit, unit);
		$init($CopticDate$1);
		switch ($nc($CopticDate$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((f))->ordinal())) {
		case 1:
			{
				return plusDays(amountToAdd);
			}
		case 2:
			{
				return plusDays($Math::multiplyExact(amountToAdd, 7));
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
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
	}
	return $cast(CopticDate, $nc(unit)->addTo(this, amountToAdd));
}

CopticDate* CopticDate::plusYears(int64_t years) {
	return plusMonths($Math::multiplyExact(years, 13));
}

CopticDate* CopticDate::plusMonths(int64_t months) {
	if (months == 0) {
		return this;
	}
	int64_t curEm = this->prolepticYear * (int64_t)13 + (this->month - 1);
	int64_t calcEm = $Math::addExact(curEm, months);
	int32_t newYear = $Math::toIntExact($Math::floorDiv(calcEm, 13));
	int32_t newMonth = $Math::floorMod(calcEm, 13) + 1;
	return resolvePreviousValid(newYear, newMonth, this->day);
}

CopticDate* CopticDate::plusDays(int64_t days) {
	if (days == 0) {
		return this;
	}
	return CopticDate::ofEpochDay($Math::addExact(toEpochDay(), days));
}

int64_t CopticDate::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(CopticDate, end, $cast(CopticDate, $nc($($cast($CopticChronology, getChronology())))->date(endExclusive)));
	if ($instanceOf($ChronoUnit, unit)) {
		return $nc($($LocalDate::from(this)))->until(end, unit);
	}
	return $nc(unit)->between(this, end);
}

$ChronoPeriod* CopticDate::until($ChronoLocalDate* endDate) {
	$useLocalCurrentObjectStackCache();
	$var(CopticDate, end, $cast(CopticDate, $nc($($cast($CopticChronology, getChronology())))->date(endDate)));
	int64_t totalMonths = ($nc(end)->prolepticYear - this->prolepticYear) * 13 + (end->month - this->month);
	int32_t days = end->day - this->day;
	if (totalMonths > 0 && days < 0) {
		--totalMonths;
		$var(CopticDate, calcDate, this->plusMonths(totalMonths));
		int64_t var$0 = end->toEpochDay();
		days = (int32_t)(var$0 - $nc(calcDate)->toEpochDay());
	} else if (totalMonths < 0 && days > 0) {
		++totalMonths;
		days -= end->lengthOfMonth();
	}
	int64_t years = totalMonths / 13;
	int32_t months = (int32_t)(totalMonths % 13);
	return $Period::of($Math::toIntExact(years), months, days);
}

int64_t CopticDate::toEpochDay() {
	int64_t year = (int64_t)this->prolepticYear;
	int64_t var$0 = ((year - 1) * 365) + $Math::floorDiv(year, 4);
	$init($ChronoField);
	int64_t copticEpochDay = var$0 + (get($ChronoField::DAY_OF_YEAR) - 1);
	return copticEpochDay - CopticDate::EPOCH_DAY_DIFFERENCE;
}

$String* CopticDate::toString() {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int64_t yoe = getLong($ChronoField::YEAR_OF_ERA);
	int64_t moy = getLong($ChronoField::MONTH_OF_YEAR);
	int64_t dom = getLong($ChronoField::DAY_OF_MONTH);
	$var($StringBuilder, buf, $new($StringBuilder, 30));
	buf->append($($nc($($cast($CopticChronology, getChronology())))->toString()))->append(" "_s)->append($($of(getEra())))->append(" "_s)->append(yoe)->append(moy < 10 ? "-0"_s : "-"_s)->append(moy)->append(dom < 10 ? "-0"_s : "-"_s)->append(dom);
	return buf->toString();
}

bool CopticDate::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(CopticDate, obj)) {
		$var(CopticDate, cd, $cast(CopticDate, obj));
		if (this->prolepticYear == $nc(cd)->prolepticYear && this->month == cd->month && this->day == cd->day) {
			return true;
		}
	}
	return false;
}

int32_t CopticDate::hashCode() {
	int64_t epDay = toEpochDay();
	return $nc($($cast($CopticChronology, getChronology())))->hashCode() ^ ((int32_t)(epDay ^ ((int64_t)((uint64_t)epDay >> 32))));
}

CopticDate::CopticDate() {
}

$Class* CopticDate::load$($String* name, bool initialize) {
	$loadClass(CopticDate, name, initialize, &_CopticDate_ClassInfo_, allocate$CopticDate);
	return class$;
}

$Class* CopticDate::class$ = nullptr;

			} // chrono
		} // time
	} // java
} // tck