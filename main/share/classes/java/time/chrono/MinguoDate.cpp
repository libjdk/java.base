#include <java/time/chrono/MinguoDate.h>

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
#include <java/time/chrono/MinguoChronology.h>
#include <java/time/chrono/MinguoDate$1.h>
#include <java/time/chrono/MinguoEra.h>
#include <java/time/chrono/Ser.h>
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

#undef BEFORE_ROC
#undef DAY_OF_MONTH
#undef INSTANCE
#undef MINGUO_DATE_TYPE
#undef MONTH_OF_YEAR
#undef ROC
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
using $MinguoChronology = ::java::time::chrono::MinguoChronology;
using $MinguoDate$1 = ::java::time::chrono::MinguoDate$1;
using $MinguoEra = ::java::time::chrono::MinguoEra;
using $Ser = ::java::time::chrono::Ser;
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

$CompoundAttribute _MinguoDate_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _MinguoDate_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MinguoDate, serialVersionUID)},
	{"isoDate", "Ljava/time/LocalDate;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(MinguoDate, isoDate)},
	{}
};

$MethodInfo _MinguoDate_MethodInfo_[] = {
	{"<init>", "(Ljava/time/LocalDate;)V", nullptr, 0, $method(MinguoDate, init$, void, $LocalDate*)},
	{"atTime", "(Ljava/time/LocalTime;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/LocalTime;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/MinguoDate;>;", $PUBLIC | $FINAL, $virtualMethod(MinguoDate, atTime, $ChronoLocalDateTime*, $LocalTime*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(MinguoDate, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(MinguoDate, from, MinguoDate*, $TemporalAccessor*)},
	{"getChronology", "()Ljava/time/chrono/MinguoChronology;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, getChronology, $Chronology*)},
	{"getEra", "()Ljava/time/chrono/MinguoEra;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, getEra, $Era*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(MinguoDate, getLong, int64_t, $TemporalField*)},
	{"getProlepticMonth", "()J", nullptr, $PRIVATE, $method(MinguoDate, getProlepticMonth, int64_t)},
	{"getProlepticYear", "()I", nullptr, $PRIVATE, $method(MinguoDate, getProlepticYear, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(MinguoDate, hashCode, int32_t)},
	{"lengthOfMonth", "()I", nullptr, $PUBLIC, $virtualMethod(MinguoDate, lengthOfMonth, int32_t)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, minus, MinguoDate*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, minus, MinguoDate*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, minusDays, MinguoDate*, int64_t)},
	{"minusMonths", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, minusMonths, MinguoDate*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, minusWeeks, MinguoDate*, int64_t)},
	{"minusYears", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, minusYears, MinguoDate*, int64_t)},
	{"now", "()Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(MinguoDate, now, MinguoDate*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(MinguoDate, now, MinguoDate*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(MinguoDate, now, MinguoDate*, $Clock*)},
	{"of", "(III)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(MinguoDate, of, MinguoDate*, int32_t, int32_t, int32_t)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, plus, MinguoDate*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, plus, MinguoDate*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, plusDays, MinguoDate*, int64_t)},
	{"plusMonths", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, plusMonths, MinguoDate*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, plusWeeks, MinguoDate*, int64_t)},
	{"plusYears", "(J)Ljava/time/chrono/MinguoDate;", nullptr, 0, $virtualMethod(MinguoDate, plusYears, MinguoDate*, int64_t)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/chrono/MinguoDate;", nullptr, $STATIC, $staticMethod(MinguoDate, readExternal, MinguoDate*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(MinguoDate, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toEpochDay", "()J", nullptr, $PUBLIC, $virtualMethod(MinguoDate, toEpochDay, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MinguoDate, toString, $String*)},
	{"until", "(Ljava/time/chrono/ChronoLocalDate;)Ljava/time/chrono/ChronoPeriod;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, until, $ChronoPeriod*, $ChronoLocalDate*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MinguoDate, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, with, MinguoDate*, $TemporalField*, int64_t)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoDate, with, MinguoDate*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/LocalDate;)Ljava/time/chrono/MinguoDate;", nullptr, $PRIVATE, $method(MinguoDate, with, MinguoDate*, $LocalDate*)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(MinguoDate, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(MinguoDate, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _MinguoDate_InnerClassesInfo_[] = {
	{"java.time.chrono.MinguoDate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _MinguoDate_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.MinguoDate",
	"java.time.chrono.ChronoLocalDateImpl",
	nullptr,
	_MinguoDate_FieldInfo_,
	_MinguoDate_MethodInfo_,
	"Ljava/time/chrono/ChronoLocalDateImpl<Ljava/time/chrono/MinguoDate;>;Ljava/time/chrono/ChronoLocalDate;Ljava/io/Serializable;",
	nullptr,
	_MinguoDate_InnerClassesInfo_,
	_MinguoDate_Annotations_,
	nullptr,
	"java.time.chrono.MinguoDate$1"
};

$Object* allocate$MinguoDate($Class* clazz) {
	return $of($alloc(MinguoDate));
}

MinguoDate* MinguoDate::now() {
	$init(MinguoDate);
	return now($($Clock::systemDefaultZone()));
}

MinguoDate* MinguoDate::now($ZoneId* zone) {
	$init(MinguoDate);
	return now($($Clock::system(zone)));
}

MinguoDate* MinguoDate::now($Clock* clock) {
	$init(MinguoDate);
	return $new(MinguoDate, $($LocalDate::now(clock)));
}

MinguoDate* MinguoDate::of(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	$init(MinguoDate);
	return $new(MinguoDate, $($LocalDate::of(prolepticYear + 1911, month, dayOfMonth)));
}

MinguoDate* MinguoDate::from($TemporalAccessor* temporal) {
	$init(MinguoDate);
	$init($MinguoChronology);
	return $cast(MinguoDate, $nc($MinguoChronology::INSTANCE)->date(temporal));
}

void MinguoDate::init$($LocalDate* isoDate) {
	$ChronoLocalDateImpl::init$();
	$Objects::requireNonNull($of(isoDate), "isoDate"_s);
	$set(this, isoDate, isoDate);
}

$Chronology* MinguoDate::getChronology() {
	$init($MinguoChronology);
	return $MinguoChronology::INSTANCE;
}

$Era* MinguoDate::getEra() {
	$init($MinguoEra);
	return ((getProlepticYear() >= 1 ? $MinguoEra::ROC : $MinguoEra::BEFORE_ROC));
}

int32_t MinguoDate::lengthOfMonth() {
	return $nc(this->isoDate)->lengthOfMonth();
}

$ValueRange* MinguoDate::range($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoField, field)) {
		if (isSupported(field)) {
			$ChronoField* f = $cast($ChronoField, field);
			$init($MinguoDate$1);
			switch ($nc($MinguoDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((f))->ordinal())) {
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
						int64_t max = (getProlepticYear() <= 0 ? -$nc(range)->getMinimum() + 1 + 1911 : range->getMaximum() - 1911);
						return $ValueRange::of(1, max);
					}
				}
			}
			return $nc($($cast($MinguoChronology, getChronology())))->range(f);
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->rangeRefinedBy(this);
}

int64_t MinguoDate::getLong($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($MinguoDate$1);
		switch ($nc($MinguoDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
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

int64_t MinguoDate::getProlepticMonth() {
	int64_t var$0 = getProlepticYear() * (int64_t)12;
	return var$0 + $nc(this->isoDate)->getMonthValue() - 1;
}

int32_t MinguoDate::getProlepticYear() {
	return $nc(this->isoDate)->getYear() - 1911;
}

MinguoDate* MinguoDate::with($TemporalField* field, int64_t newValue) {
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
			$init($MinguoDate$1);
			switch ($nc($MinguoDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 5:
				{
					$nc($($nc($($cast($MinguoChronology, getChronology())))->range(chronoField)))->checkValidValue(newValue, chronoField);
					return plusMonths(newValue - getProlepticMonth());
				}
			case 4:
				{}
			case 6:
				{}
			case 7:
				{
					{
						int32_t nvalue = $nc($($nc($($cast($MinguoChronology, getChronology())))->range(chronoField)))->checkValidIntValue(newValue, chronoField);
						switch ($nc($MinguoDate$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
						case 4:
							{
								return with($($nc(this->isoDate)->withYear(getProlepticYear() >= 1 ? nvalue + 1911 : (1 - nvalue) + 1911)));
							}
						case 6:
							{
								return with($($nc(this->isoDate)->withYear(nvalue + 1911)));
							}
						case 7:
							{
								return with($($nc(this->isoDate)->withYear((1 - getProlepticYear()) + 1911)));
							}
						}
					}
				}
			}
			return with($($nc(this->isoDate)->with(field, newValue)));
		}
	}
	return $cast(MinguoDate, $ChronoLocalDateImpl::with(field, newValue));
}

MinguoDate* MinguoDate::with($TemporalAdjuster* adjuster) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::with(adjuster));
}

MinguoDate* MinguoDate::plus($TemporalAmount* amount) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::plus(amount));
}

MinguoDate* MinguoDate::minus($TemporalAmount* amount) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::minus(amount));
}

MinguoDate* MinguoDate::plusYears(int64_t years) {
	return with($($nc(this->isoDate)->plusYears(years)));
}

MinguoDate* MinguoDate::plusMonths(int64_t months) {
	return with($($nc(this->isoDate)->plusMonths(months)));
}

MinguoDate* MinguoDate::plusWeeks(int64_t weeksToAdd) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::plusWeeks(weeksToAdd));
}

MinguoDate* MinguoDate::plusDays(int64_t days) {
	return with($($nc(this->isoDate)->plusDays(days)));
}

MinguoDate* MinguoDate::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::plus(amountToAdd, unit));
}

MinguoDate* MinguoDate::minus(int64_t amountToAdd, $TemporalUnit* unit) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::minus(amountToAdd, unit));
}

MinguoDate* MinguoDate::minusYears(int64_t yearsToSubtract) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::minusYears(yearsToSubtract));
}

MinguoDate* MinguoDate::minusMonths(int64_t monthsToSubtract) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::minusMonths(monthsToSubtract));
}

MinguoDate* MinguoDate::minusWeeks(int64_t weeksToSubtract) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::minusWeeks(weeksToSubtract));
}

MinguoDate* MinguoDate::minusDays(int64_t daysToSubtract) {
	return $cast(MinguoDate, $ChronoLocalDateImpl::minusDays(daysToSubtract));
}

MinguoDate* MinguoDate::with($LocalDate* newDate) {
	return ($nc(newDate)->equals(this->isoDate) ? this : $new(MinguoDate, newDate));
}

$ChronoLocalDateTime* MinguoDate::atTime($LocalTime* localTime) {
	return $ChronoLocalDateImpl::atTime(localTime);
}

$ChronoPeriod* MinguoDate::until($ChronoLocalDate* endDate) {
	$useLocalCurrentObjectStackCache();
	$var($Period, period, $cast($Period, $nc(this->isoDate)->until(endDate)));
	int32_t var$0 = $nc(period)->getYears();
	int32_t var$1 = period->getMonths();
	return $nc($($cast($MinguoChronology, getChronology())))->period(var$0, var$1, period->getDays());
}

int64_t MinguoDate::toEpochDay() {
	return $nc(this->isoDate)->toEpochDay();
}

bool MinguoDate::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(MinguoDate, otherDate, nullptr);
	bool var$1 = $instanceOf(MinguoDate, obj);
	if (var$1) {
		$assign(otherDate, $cast(MinguoDate, obj));
		var$1 = true;
	}
	bool var$0 = (var$1);
	return var$0 && $nc(this->isoDate)->equals($nc(otherDate)->isoDate);
}

int32_t MinguoDate::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc($($nc($($cast($MinguoChronology, getChronology())))->getId()))->hashCode();
	return var$0 ^ $nc(this->isoDate)->hashCode();
}

void MinguoDate::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

$Object* MinguoDate::writeReplace() {
	return $of($new($Ser, $Ser::MINGUO_DATE_TYPE, this));
}

void MinguoDate::writeExternal($DataOutput* out) {
	$init($ChronoField);
	$nc(out)->writeInt(get($ChronoField::YEAR));
	out->writeByte(get($ChronoField::MONTH_OF_YEAR));
	out->writeByte(get($ChronoField::DAY_OF_MONTH));
}

MinguoDate* MinguoDate::readExternal($DataInput* in) {
	$init(MinguoDate);
	int32_t year = $nc(in)->readInt();
	int32_t month = in->readByte();
	int32_t dayOfMonth = in->readByte();
	$init($MinguoChronology);
	return $cast(MinguoDate, $nc($MinguoChronology::INSTANCE)->date(year, month, dayOfMonth));
}

$String* MinguoDate::toString() {
	return $ChronoLocalDateImpl::toString();
}

int64_t MinguoDate::until($Temporal* endExclusive, $TemporalUnit* unit) {
	return $ChronoLocalDateImpl::until(endExclusive, unit);
}

MinguoDate::MinguoDate() {
}

$Class* MinguoDate::load$($String* name, bool initialize) {
	$loadClass(MinguoDate, name, initialize, &_MinguoDate_ClassInfo_, allocate$MinguoDate);
	return class$;
}

$Class* MinguoDate::class$ = nullptr;

		} // chrono
	} // time
} // java