#include <java/time/chrono/ThaiBuddhistDate.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/time/Clock.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalTime.h>
#include <java/time/Period.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateImpl.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoPeriod.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/Ser.h>
#include <java/time/chrono/ThaiBuddhistChronology.h>
#include <java/time/chrono/ThaiBuddhistDate$1.h>
#include <java/time/chrono/ThaiBuddhistEra.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef BE
#undef BEFORE_BE
#undef DAY_OF_MONTH
#undef INSTANCE
#undef MONTH_OF_YEAR
#undef THAIBUDDHIST_DATE_TYPE
#undef YEAR

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Clock = ::java::time::Clock;
using $LocalDate = ::java::time::LocalDate;
using $LocalTime = ::java::time::LocalTime;
using $Period = ::java::time::Period;
using $ZoneId = ::java::time::ZoneId;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateImpl = ::java::time::chrono::ChronoLocalDateImpl;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoPeriod = ::java::time::chrono::ChronoPeriod;
using $Chronology = ::java::time::chrono::Chronology;
using $Era = ::java::time::chrono::Era;
using $Ser = ::java::time::chrono::Ser;
using $ThaiBuddhistChronology = ::java::time::chrono::ThaiBuddhistChronology;
using $ThaiBuddhistDate$1 = ::java::time::chrono::ThaiBuddhistDate$1;
using $ThaiBuddhistEra = ::java::time::chrono::ThaiBuddhistEra;
using $ChronoField = ::java::time::temporal::ChronoField;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAdjuster = ::java::time::temporal::TemporalAdjuster;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {
		namespace chrono {

$CompoundAttribute _ThaiBuddhistDate_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _ThaiBuddhistDate_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ThaiBuddhistDate, serialVersionUID)},
	{"isoDate", "Ljava/time/LocalDate;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(ThaiBuddhistDate, isoDate)},
	{}
};

$MethodInfo _ThaiBuddhistDate_MethodInfo_[] = {
	{"<init>", "(Ljava/time/LocalDate;)V", nullptr, 0, $method(ThaiBuddhistDate, init$, void, $LocalDate*)},
	{"atTime", "(Ljava/time/LocalTime;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/LocalTime;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/ThaiBuddhistDate;>;", $PUBLIC | $FINAL, $virtualMethod(ThaiBuddhistDate, atTime, $ChronoLocalDateTime*, $LocalTime*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistDate, from, ThaiBuddhistDate*, $TemporalAccessor*)},
	{"getChronology", "()Ljava/time/chrono/ThaiBuddhistChronology;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, getChronology, $Chronology*)},
	{"getEra", "()Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, getEra, $Era*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, getLong, int64_t, $TemporalField*)},
	{"getProlepticMonth", "()J", nullptr, $PRIVATE, $method(ThaiBuddhistDate, getProlepticMonth, int64_t)},
	{"getProlepticYear", "()I", nullptr, $PRIVATE, $method(ThaiBuddhistDate, getProlepticYear, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, hashCode, int32_t)},
	{"lengthOfMonth", "()I", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, lengthOfMonth, int32_t)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, minus, ThaiBuddhistDate*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, minus, ThaiBuddhistDate*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, minusDays, ThaiBuddhistDate*, int64_t)},
	{"minusMonths", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, minusMonths, ThaiBuddhistDate*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, minusWeeks, ThaiBuddhistDate*, int64_t)},
	{"minusYears", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, minusYears, ThaiBuddhistDate*, int64_t)},
	{"now", "()Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistDate, now, ThaiBuddhistDate*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistDate, now, ThaiBuddhistDate*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistDate, now, ThaiBuddhistDate*, $Clock*)},
	{"of", "(III)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThaiBuddhistDate, of, ThaiBuddhistDate*, int32_t, int32_t, int32_t)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, plus, ThaiBuddhistDate*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, plus, ThaiBuddhistDate*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, plusDays, ThaiBuddhistDate*, int64_t)},
	{"plusMonths", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, plusMonths, ThaiBuddhistDate*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, plusWeeks, ThaiBuddhistDate*, int64_t)},
	{"plusYears", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, 0, $virtualMethod(ThaiBuddhistDate, plusYears, ThaiBuddhistDate*, int64_t)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $STATIC, $staticMethod(ThaiBuddhistDate, readExternal, ThaiBuddhistDate*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ThaiBuddhistDate, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toEpochDay", "()J", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, toEpochDay, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ThaiBuddhistDate, toString, $String*)},
	{"until", "(Ljava/time/chrono/ChronoLocalDate;)Ljava/time/chrono/ChronoPeriod;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, until, $ChronoPeriod*, $ChronoLocalDate*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ThaiBuddhistDate, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, with, ThaiBuddhistDate*, $TemporalField*, int64_t)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistDate, with, ThaiBuddhistDate*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/LocalDate;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PRIVATE, $method(ThaiBuddhistDate, with, ThaiBuddhistDate*, $LocalDate*)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(ThaiBuddhistDate, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(ThaiBuddhistDate, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _ThaiBuddhistDate_InnerClassesInfo_[] = {
	{"java.time.chrono.ThaiBuddhistDate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _ThaiBuddhistDate_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.ThaiBuddhistDate",
	"java.time.chrono.ChronoLocalDateImpl",
	nullptr,
	_ThaiBuddhistDate_FieldInfo_,
	_ThaiBuddhistDate_MethodInfo_,
	"Ljava/time/chrono/ChronoLocalDateImpl<Ljava/time/chrono/ThaiBuddhistDate;>;Ljava/time/chrono/ChronoLocalDate;Ljava/io/Serializable;",
	nullptr,
	_ThaiBuddhistDate_InnerClassesInfo_,
	_ThaiBuddhistDate_Annotations_,
	nullptr,
	"java.time.chrono.ThaiBuddhistDate$1"
};

$Object* allocate$ThaiBuddhistDate($Class* clazz) {
	return $of($alloc(ThaiBuddhistDate));
}

ThaiBuddhistDate* ThaiBuddhistDate::now() {
	$init(ThaiBuddhistDate);
	return now($($Clock::systemDefaultZone()));
}

ThaiBuddhistDate* ThaiBuddhistDate::now($ZoneId* zone) {
	$init(ThaiBuddhistDate);
	return now($($Clock::system(zone)));
}

ThaiBuddhistDate* ThaiBuddhistDate::now($Clock* clock) {
	$init(ThaiBuddhistDate);
	return $new(ThaiBuddhistDate, $($LocalDate::now(clock)));
}

ThaiBuddhistDate* ThaiBuddhistDate::of(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	$init(ThaiBuddhistDate);
	return $new(ThaiBuddhistDate, $($LocalDate::of(prolepticYear - 543, month, dayOfMonth)));
}

ThaiBuddhistDate* ThaiBuddhistDate::from($TemporalAccessor* temporal) {
	$init(ThaiBuddhistDate);
	$init($ThaiBuddhistChronology);
	return $cast(ThaiBuddhistDate, $nc($ThaiBuddhistChronology::INSTANCE)->date(temporal));
}

void ThaiBuddhistDate::init$($LocalDate* isoDate) {
	$ChronoLocalDateImpl::init$();
	$Objects::requireNonNull($of(isoDate), "isoDate"_s);
	$set(this, isoDate, isoDate);
}

$Chronology* ThaiBuddhistDate::getChronology() {
	$init($ThaiBuddhistChronology);
	return $ThaiBuddhistChronology::INSTANCE;
}

$Era* ThaiBuddhistDate::getEra() {
	$init($ThaiBuddhistEra);
	return ((getProlepticYear() >= 1 ? $ThaiBuddhistEra::BE : $ThaiBuddhistEra::BEFORE_BE));
}

int32_t ThaiBuddhistDate::lengthOfMonth() {
	return $nc(this->isoDate)->lengthOfMonth();
}

$ValueRange* ThaiBuddhistDate::range($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoField, field)) {
		if (isSupported(field)) {
			$ChronoField* f = $cast($ChronoField, field);
			$init($ThaiBuddhistDate$1);
			switch ($nc($ThaiBuddhistDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((f))->ordinal())) {
			case 1:
				{}
			case 2:
				{}
			case 3:
				{
					return $nc(this->isoDate)->range(field);
				}
			case 4:
				{
					{
						$init($ChronoField);
						$var($ValueRange, range, $ChronoField::YEAR->range());
						int64_t max = (getProlepticYear() <= 0 ? -($nc(range)->getMinimum() + 543) + 1 : range->getMaximum() + 543);
						return $ValueRange::of(1, max);
					}
				}
			}
			return $nc($($cast($ThaiBuddhistChronology, getChronology())))->range(f);
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->rangeRefinedBy(this);
}

int64_t ThaiBuddhistDate::getLong($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ThaiBuddhistDate$1);
		switch ($nc($ThaiBuddhistDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
		case 5:
			{
				return getProlepticMonth();
			}
		case 4:
			{
				{
					int32_t prolepticYear = getProlepticYear();
					return (prolepticYear >= 1 ? prolepticYear : 1 - prolepticYear);
				}
			}
		case 6:
			{
				return getProlepticYear();
			}
		case 7:
			{
				return (getProlepticYear() >= 1 ? 1 : 0);
			}
		}
		return $nc(this->isoDate)->getLong(field);
	}
	return $nc(field)->getFrom(this);
}

int64_t ThaiBuddhistDate::getProlepticMonth() {
	int64_t var$0 = getProlepticYear() * (int64_t)12;
	return var$0 + $nc(this->isoDate)->getMonthValue() - 1;
}

int32_t ThaiBuddhistDate::getProlepticYear() {
	return $nc(this->isoDate)->getYear() + 543;
}

ThaiBuddhistDate* ThaiBuddhistDate::with($TemporalField* field, int64_t newValue) {
	$useLocalCurrentObjectStackCache();
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			if (getLong(chronoField) == newValue) {
				return this;
			}
			$init($ThaiBuddhistDate$1);
			switch ($nc($ThaiBuddhistDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 5:
				{
					$nc($($nc($($cast($ThaiBuddhistChronology, getChronology())))->range(chronoField)))->checkValidValue(newValue, chronoField);
					return plusMonths(newValue - getProlepticMonth());
				}
			case 4:
				{}
			case 6:
				{}
			case 7:
				{
					{
						int32_t nvalue = $nc($($nc($($cast($ThaiBuddhistChronology, getChronology())))->range(chronoField)))->checkValidIntValue(newValue, chronoField);
						switch ($nc($ThaiBuddhistDate$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
						case 4:
							{
								return with($($nc(this->isoDate)->withYear((getProlepticYear() >= 1 ? nvalue : 1 - nvalue) - 543)));
							}
						case 6:
							{
								return with($($nc(this->isoDate)->withYear(nvalue - 543)));
							}
						case 7:
							{
								return with($($nc(this->isoDate)->withYear((1 - getProlepticYear()) - 543)));
							}
						}
					}
				}
			}
			return with($($nc(this->isoDate)->with(field, newValue)));
		}
	}
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::with(field, newValue));
}

ThaiBuddhistDate* ThaiBuddhistDate::with($TemporalAdjuster* adjuster) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::with(adjuster));
}

ThaiBuddhistDate* ThaiBuddhistDate::plus($TemporalAmount* amount) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::plus(amount));
}

ThaiBuddhistDate* ThaiBuddhistDate::minus($TemporalAmount* amount) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::minus(amount));
}

ThaiBuddhistDate* ThaiBuddhistDate::plusYears(int64_t years) {
	return with($($nc(this->isoDate)->plusYears(years)));
}

ThaiBuddhistDate* ThaiBuddhistDate::plusMonths(int64_t months) {
	return with($($nc(this->isoDate)->plusMonths(months)));
}

ThaiBuddhistDate* ThaiBuddhistDate::plusWeeks(int64_t weeksToAdd) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::plusWeeks(weeksToAdd));
}

ThaiBuddhistDate* ThaiBuddhistDate::plusDays(int64_t days) {
	return with($($nc(this->isoDate)->plusDays(days)));
}

ThaiBuddhistDate* ThaiBuddhistDate::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::plus(amountToAdd, unit));
}

ThaiBuddhistDate* ThaiBuddhistDate::minus(int64_t amountToAdd, $TemporalUnit* unit) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::minus(amountToAdd, unit));
}

ThaiBuddhistDate* ThaiBuddhistDate::minusYears(int64_t yearsToSubtract) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::minusYears(yearsToSubtract));
}

ThaiBuddhistDate* ThaiBuddhistDate::minusMonths(int64_t monthsToSubtract) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::minusMonths(monthsToSubtract));
}

ThaiBuddhistDate* ThaiBuddhistDate::minusWeeks(int64_t weeksToSubtract) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::minusWeeks(weeksToSubtract));
}

ThaiBuddhistDate* ThaiBuddhistDate::minusDays(int64_t daysToSubtract) {
	return $cast(ThaiBuddhistDate, $ChronoLocalDateImpl::minusDays(daysToSubtract));
}

ThaiBuddhistDate* ThaiBuddhistDate::with($LocalDate* newDate) {
	return ($nc(newDate)->equals(this->isoDate) ? this : $new(ThaiBuddhistDate, newDate));
}

$ChronoLocalDateTime* ThaiBuddhistDate::atTime($LocalTime* localTime) {
	return $ChronoLocalDateImpl::atTime(localTime);
}

$ChronoPeriod* ThaiBuddhistDate::until($ChronoLocalDate* endDate) {
	$useLocalCurrentObjectStackCache();
	$var($Period, period, $cast($Period, $nc(this->isoDate)->until(endDate)));
	int32_t var$0 = $nc(period)->getYears();
	int32_t var$1 = period->getMonths();
	return $nc($($cast($ThaiBuddhistChronology, getChronology())))->period(var$0, var$1, period->getDays());
}

int64_t ThaiBuddhistDate::toEpochDay() {
	return $nc(this->isoDate)->toEpochDay();
}

bool ThaiBuddhistDate::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(ThaiBuddhistDate, otherDate, nullptr);
	bool var$1 = $instanceOf(ThaiBuddhistDate, obj);
	if (var$1) {
		$assign(otherDate, $cast(ThaiBuddhistDate, obj));
		var$1 = true;
	}
	bool var$0 = (var$1);
	return var$0 && $nc(this->isoDate)->equals($nc(otherDate)->isoDate);
}

int32_t ThaiBuddhistDate::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc($($nc($($cast($ThaiBuddhistChronology, getChronology())))->getId()))->hashCode();
	return var$0 ^ $nc(this->isoDate)->hashCode();
}

void ThaiBuddhistDate::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

$Object* ThaiBuddhistDate::writeReplace() {
	return $of($new($Ser, $Ser::THAIBUDDHIST_DATE_TYPE, this));
}

void ThaiBuddhistDate::writeExternal($DataOutput* out) {
	$init($ChronoField);
	$nc(out)->writeInt(this->get($ChronoField::YEAR));
	out->writeByte(this->get($ChronoField::MONTH_OF_YEAR));
	out->writeByte(this->get($ChronoField::DAY_OF_MONTH));
}

ThaiBuddhistDate* ThaiBuddhistDate::readExternal($DataInput* in) {
	$init(ThaiBuddhistDate);
	int32_t year = $nc(in)->readInt();
	int32_t month = in->readByte();
	int32_t dayOfMonth = in->readByte();
	$init($ThaiBuddhistChronology);
	return $cast(ThaiBuddhistDate, $nc($ThaiBuddhistChronology::INSTANCE)->date(year, month, dayOfMonth));
}

$String* ThaiBuddhistDate::toString() {
	return $ChronoLocalDateImpl::toString();
}

int64_t ThaiBuddhistDate::until($Temporal* endExclusive, $TemporalUnit* unit) {
	return $ChronoLocalDateImpl::until(endExclusive, unit);
}

ThaiBuddhistDate::ThaiBuddhistDate() {
}

$Class* ThaiBuddhistDate::load$($String* name, bool initialize) {
	$loadClass(ThaiBuddhistDate, name, initialize, &_ThaiBuddhistDate_ClassInfo_, allocate$ThaiBuddhistDate);
	return class$;
}

$Class* ThaiBuddhistDate::class$ = nullptr;

		} // chrono
	} // time
} // java