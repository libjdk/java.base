#include <java/time/chrono/IsoChronology.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/Math.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalDateTime.h>
#include <java/time/Month.h>
#include <java/time/Period.h>
#include <java/time/Year.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/chrono/AbstractChronology.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoPeriod.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/IsoEra.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef CE
#undef DAY_OF_MONTH
#undef ERA
#undef FEBRUARY
#undef HOUR_OF_DAY
#undef INSTANCE
#undef LENIENT
#undef MINUTE_OF_HOUR
#undef MONTH_OF_YEAR
#undef PROLEPTIC_MONTH
#undef SECOND_OF_MINUTE
#undef SMART
#undef STRICT
#undef YEAR
#undef YEAR_OF_ERA

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalDateTime = ::java::time::LocalDateTime;
using $Month = ::java::time::Month;
using $Period = ::java::time::Period;
using $Year = ::java::time::Year;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $AbstractChronology = ::java::time::chrono::AbstractChronology;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoPeriod = ::java::time::chrono::ChronoPeriod;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
using $Era = ::java::time::chrono::Era;
using $IsoEra = ::java::time::chrono::IsoEra;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $ValueRange = ::java::time::temporal::ValueRange;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _IsoChronology_FieldInfo_[] = {
	{"INSTANCE", "Ljava/time/chrono/IsoChronology;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(IsoChronology, INSTANCE)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IsoChronology, serialVersionUID)},
	{"DAYS_0000_TO_1970", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IsoChronology, DAYS_0000_TO_1970)},
	{}
};

$MethodInfo _IsoChronology_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PRIVATE, $method(IsoChronology, init$, void)},
	{"date", "(Ljava/time/chrono/Era;III)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, date, $ChronoLocalDate*, $Era*, int32_t, int32_t, int32_t)},
	{"date", "(III)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, date, $ChronoLocalDate*, int32_t, int32_t, int32_t)},
	{"date", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, date, $ChronoLocalDate*, $TemporalAccessor*)},
	{"dateEpochDay", "(J)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, dateEpochDay, $ChronoLocalDate*, int64_t)},
	{"dateNow", "()Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, dateNow, $ChronoLocalDate*)},
	{"dateNow", "(Ljava/time/ZoneId;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, dateNow, $ChronoLocalDate*, $ZoneId*)},
	{"dateNow", "(Ljava/time/Clock;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, dateNow, $ChronoLocalDate*, $Clock*)},
	{"dateYearDay", "(Ljava/time/chrono/Era;II)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, dateYearDay, $ChronoLocalDate*, $Era*, int32_t, int32_t)},
	{"dateYearDay", "(II)Ljava/time/LocalDate;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, dateYearDay, $ChronoLocalDate*, int32_t, int32_t)},
	{"epochSecond", "(IIIIIILjava/time/ZoneOffset;)J", nullptr, $PUBLIC, $virtualMethod(IsoChronology, epochSecond, int64_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, $ZoneOffset*)},
	{"eraOf", "(I)Ljava/time/chrono/IsoEra;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, eraOf, $Era*, int32_t)},
	{"eras", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/chrono/Era;>;", $PUBLIC, $virtualMethod(IsoChronology, eras, $List*)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, getCalendarType, $String*)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, getId, $String*)},
	{"isLeapYear", "(J)Z", nullptr, $PUBLIC, $virtualMethod(IsoChronology, isLeapYear, bool, int64_t)},
	{"localDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, localDateTime, $ChronoLocalDateTime*, $TemporalAccessor*)},
	{"numberOfDaysOfMonth", "(II)I", nullptr, $PRIVATE, $method(IsoChronology, numberOfDaysOfMonth, int32_t, int32_t, int32_t)},
	{"period", "(III)Ljava/time/Period;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, period, $ChronoPeriod*, int32_t, int32_t, int32_t)},
	{"prolepticYear", "(Ljava/time/chrono/Era;I)I", nullptr, $PUBLIC, $virtualMethod(IsoChronology, prolepticYear, int32_t, $Era*, int32_t)},
	{"range", "(Ljava/time/temporal/ChronoField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, range, $ValueRange*, $ChronoField*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(IsoChronology, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/LocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/LocalDate;", $PUBLIC, $virtualMethod(IsoChronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveProlepticMonth", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)V", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)V", 0, $virtualMethod(IsoChronology, resolveProlepticMonth, void, $Map*, $ResolverStyle*)},
	{"resolveYMD", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/LocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/LocalDate;", 0, $virtualMethod(IsoChronology, resolveYMD, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYearOfEra", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/LocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/LocalDate;", 0, $virtualMethod(IsoChronology, resolveYearOfEra, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(IsoChronology, writeReplace, $Object*)},
	{"zonedDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, zonedDateTime, $ChronoZonedDateTime*, $TemporalAccessor*)},
	{"zonedDateTime", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(IsoChronology, zonedDateTime, $ChronoZonedDateTime*, $Instant*, $ZoneId*)},
	{}
};

$ClassInfo _IsoChronology_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.IsoChronology",
	"java.time.chrono.AbstractChronology",
	"java.io.Serializable",
	_IsoChronology_FieldInfo_,
	_IsoChronology_MethodInfo_
};

$Object* allocate$IsoChronology($Class* clazz) {
	return $of($alloc(IsoChronology));
}

bool IsoChronology::equals(Object$* obj) {
	 return this->$AbstractChronology::equals(obj);
}

int32_t IsoChronology::hashCode() {
	 return this->$AbstractChronology::hashCode();
}

$String* IsoChronology::toString() {
	 return this->$AbstractChronology::toString();
}

$Object* IsoChronology::clone() {
	 return this->$AbstractChronology::clone();
}

void IsoChronology::finalize() {
	this->$AbstractChronology::finalize();
}

IsoChronology* IsoChronology::INSTANCE = nullptr;

void IsoChronology::init$() {
	$AbstractChronology::init$();
}

$String* IsoChronology::getId() {
	return "ISO"_s;
}

$String* IsoChronology::getCalendarType() {
	return "iso8601"_s;
}

$ChronoLocalDate* IsoChronology::date($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	return date(prolepticYear(era, yearOfEra), month, dayOfMonth);
}

$ChronoLocalDate* IsoChronology::date(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	return $LocalDate::of(prolepticYear, month, dayOfMonth);
}

$ChronoLocalDate* IsoChronology::dateYearDay($Era* era, int32_t yearOfEra, int32_t dayOfYear) {
	return dateYearDay(prolepticYear(era, yearOfEra), dayOfYear);
}

$ChronoLocalDate* IsoChronology::dateYearDay(int32_t prolepticYear, int32_t dayOfYear) {
	return $LocalDate::ofYearDay(prolepticYear, dayOfYear);
}

$ChronoLocalDate* IsoChronology::dateEpochDay(int64_t epochDay) {
	return $LocalDate::ofEpochDay(epochDay);
}

$ChronoLocalDate* IsoChronology::date($TemporalAccessor* temporal) {
	return $LocalDate::from(temporal);
}

int64_t IsoChronology::epochSecond(int32_t prolepticYear, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, $ZoneOffset* zoneOffset) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(prolepticYear);
	$ChronoField::MONTH_OF_YEAR->checkValidValue(month);
	$ChronoField::DAY_OF_MONTH->checkValidValue(dayOfMonth);
	$ChronoField::HOUR_OF_DAY->checkValidValue(hour);
	$ChronoField::MINUTE_OF_HOUR->checkValidValue(minute);
	$ChronoField::SECOND_OF_MINUTE->checkValidValue(second);
	$Objects::requireNonNull($of(zoneOffset), "zoneOffset"_s);
	if (dayOfMonth > 28) {
		int32_t dom = numberOfDaysOfMonth(prolepticYear, month);
		if (dayOfMonth > dom) {
			if (dayOfMonth == 29) {
				$throwNew($DateTimeException, $$str({"Invalid date \'February 29\' as \'"_s, $$str(prolepticYear), "\' is not a leap year"_s}));
			} else {
				$throwNew($DateTimeException, $$str({"Invalid date \'"_s, $($nc($($Month::of(month)))->name()), " "_s, $$str(dayOfMonth), "\'"_s}));
			}
		}
	}
	int64_t totalDays = 0;
	int32_t timeinSec = 0;
	totalDays += (int64_t)365 * prolepticYear;
	if (prolepticYear >= 0) {
		totalDays += (prolepticYear + (int64_t)3) / 4 - (prolepticYear + (int64_t)99) / 100 + (prolepticYear + (int64_t)399) / 400;
	} else {
		totalDays -= prolepticYear / -4 - prolepticYear / -100 + prolepticYear / -400;
	}
	totalDays += (367 * month - 362) / 12;
	totalDays += dayOfMonth - 1;
	if (month > 2) {
		--totalDays;
		if ($nc(IsoChronology::INSTANCE)->isLeapYear(prolepticYear) == false) {
			--totalDays;
		}
	}
	totalDays -= IsoChronology::DAYS_0000_TO_1970;
	timeinSec = (hour * 60 + minute) * 60 + second;
	int64_t var$0 = $Math::multiplyExact(totalDays, (int64_t)86400);
	return $Math::addExact(var$0, (int64_t)(timeinSec - $nc(zoneOffset)->getTotalSeconds()));
}

int32_t IsoChronology::numberOfDaysOfMonth(int32_t year, int32_t month) {
	int32_t dom = 0;
	switch (month) {
	case 2:
		{
			dom = ($nc(IsoChronology::INSTANCE)->isLeapYear(year) ? 29 : 28);
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
	default:
		{
			dom = 31;
			break;
		}
	}
	return dom;
}

$ChronoLocalDateTime* IsoChronology::localDateTime($TemporalAccessor* temporal) {
	return $LocalDateTime::from(temporal);
}

$ChronoZonedDateTime* IsoChronology::zonedDateTime($TemporalAccessor* temporal) {
	return $ZonedDateTime::from(temporal);
}

$ChronoZonedDateTime* IsoChronology::zonedDateTime($Instant* instant, $ZoneId* zone) {
	return $ZonedDateTime::ofInstant(instant, zone);
}

$ChronoLocalDate* IsoChronology::dateNow() {
	return dateNow($($Clock::systemDefaultZone()));
}

$ChronoLocalDate* IsoChronology::dateNow($ZoneId* zone) {
	return dateNow($($Clock::system(zone)));
}

$ChronoLocalDate* IsoChronology::dateNow($Clock* clock) {
	$Objects::requireNonNull($of(clock), "clock"_s);
	return date($($LocalDate::now(clock)));
}

bool IsoChronology::isLeapYear(int64_t prolepticYear) {
	return (((int64_t)(prolepticYear & (uint64_t)(int64_t)3)) == 0) && ((prolepticYear % 100) != 0 || (prolepticYear % 400) == 0);
}

int32_t IsoChronology::prolepticYear($Era* era, int32_t yearOfEra) {
	if (!($instanceOf($IsoEra, era))) {
		$throwNew($ClassCastException, "Era must be IsoEra"_s);
	}
	$init($IsoEra);
	return ($equals(era, $IsoEra::CE) ? yearOfEra : 1 - yearOfEra);
}

$Era* IsoChronology::eraOf(int32_t eraValue) {
	return $IsoEra::of(eraValue);
}

$List* IsoChronology::eras() {
	return $List::of($($IsoEra::values()));
}

$ChronoLocalDate* IsoChronology::resolveDate($Map* fieldValues, $ResolverStyle* resolverStyle) {
	return $cast($LocalDate, $AbstractChronology::resolveDate(fieldValues, resolverStyle));
}

void IsoChronology::resolveProlepticMonth($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$init($ChronoField);
	$var($Long, pMonth, $cast($Long, $nc(fieldValues)->remove($ChronoField::PROLEPTIC_MONTH)));
	if (pMonth != nullptr) {
		$init($ResolverStyle);
		if (resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::PROLEPTIC_MONTH->checkValidValue(pMonth->longValue());
		}
		addFieldValue(fieldValues, $ChronoField::MONTH_OF_YEAR, $Math::floorMod(pMonth->longValue(), 12) + 1);
		addFieldValue(fieldValues, $ChronoField::YEAR, $Math::floorDiv(pMonth->longValue(), 12));
	}
}

$ChronoLocalDate* IsoChronology::resolveYearOfEra($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Long, yoeLong, $cast($Long, $nc(fieldValues)->remove($ChronoField::YEAR_OF_ERA)));
	if (yoeLong != nullptr) {
		$init($ResolverStyle);
		if (resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::YEAR_OF_ERA->checkValidValue(yoeLong->longValue());
		}
		$var($Long, era, $cast($Long, fieldValues->remove($ChronoField::ERA)));
		if (era == nullptr) {
			$var($Long, year, $cast($Long, fieldValues->get($ChronoField::YEAR)));
			if (resolverStyle == $ResolverStyle::STRICT) {
				if (year != nullptr) {
					addFieldValue(fieldValues, $ChronoField::YEAR, (year->longValue() > 0 ? yoeLong->longValue() : $Math::subtractExact((int64_t)1, yoeLong->longValue())));
				} else {
					fieldValues->put($ChronoField::YEAR_OF_ERA, yoeLong);
				}
			} else {
				addFieldValue(fieldValues, $ChronoField::YEAR, (year == nullptr || $nc(year)->longValue() > 0 ? yoeLong->longValue() : $Math::subtractExact((int64_t)1, yoeLong->longValue())));
			}
		} else if ($nc(era)->longValue() == (int64_t)1) {
			addFieldValue(fieldValues, $ChronoField::YEAR, yoeLong->longValue());
		} else if (era->longValue() == (int64_t)0) {
			addFieldValue(fieldValues, $ChronoField::YEAR, $Math::subtractExact((int64_t)1, yoeLong->longValue()));
		} else {
			$throwNew($DateTimeException, $$str({"Invalid value for era: "_s, era}));
		}
	} else {
		if (fieldValues->containsKey($ChronoField::ERA)) {
			$ChronoField::ERA->checkValidValue($nc(($cast($Long, $(fieldValues->get($ChronoField::ERA)))))->longValue());
		}
	}
	return nullptr;
}

$ChronoLocalDate* IsoChronology::resolveYMD($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $ChronoField::YEAR->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue());
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t months = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t days = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_MONTH)))))->longValue(), (int64_t)1);
		return $nc($($nc($($LocalDate::of(y, 1, 1)))->plusMonths(months)))->plusDays(days);
	}
	int32_t moy = $ChronoField::MONTH_OF_YEAR->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue());
	int32_t dom = $ChronoField::DAY_OF_MONTH->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_MONTH)))))->longValue());
	if (resolverStyle == $ResolverStyle::SMART) {
		if (moy == 4 || moy == 6 || moy == 9 || moy == 11) {
			dom = $Math::min(dom, 30);
		} else if (moy == 2) {
			$init($Month);
			dom = $Math::min(dom, $Month::FEBRUARY->length($Year::isLeap(y)));
		}
	}
	return $LocalDate::of(y, moy, dom);
}

$ValueRange* IsoChronology::range($ChronoField* field) {
	return $nc(field)->range();
}

$ChronoPeriod* IsoChronology::period(int32_t years, int32_t months, int32_t days) {
	return $Period::of(years, months, days);
}

$Object* IsoChronology::writeReplace() {
	return $of($AbstractChronology::writeReplace());
}

void IsoChronology::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void clinit$IsoChronology($Class* class$) {
	$assignStatic(IsoChronology::INSTANCE, $new(IsoChronology));
}

IsoChronology::IsoChronology() {
}

$Class* IsoChronology::load$($String* name, bool initialize) {
	$loadClass(IsoChronology, name, initialize, &_IsoChronology_ClassInfo_, clinit$IsoChronology, allocate$IsoChronology);
	return class$;
}

$Class* IsoChronology::class$ = nullptr;

		} // chrono
	} // time
} // java