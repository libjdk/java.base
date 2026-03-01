#include <java/time/chrono/JapaneseChronology.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/Math.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/Year.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/AbstractChronology.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/chrono/JapaneseChronology$1.h>
#include <java/time/chrono/JapaneseDate.h>
#include <java/time/chrono/JapaneseEra.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalAdjusters.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Calendar.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/TimeZone.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/CalendarSystem.h>
#include <sun/util/calendar/Era.h>
#include <sun/util/calendar/LocalGregorianCalendar$Date.h>
#include <sun/util/calendar/LocalGregorianCalendar.h>
#include <jcpp.h>

#undef DAYS
#undef DAY_OF_MONTH
#undef DAY_OF_YEAR
#undef ERA
#undef INSTANCE
#undef JCAL
#undef LENIENT
#undef LOCALE
#undef MAX_VALUE
#undef MEIJI
#undef MEIJI_6_ISODATE
#undef MIN_VALUE
#undef MONTHS
#undef MONTH_OF_YEAR
#undef SMART
#undef STRICT
#undef YEAR
#undef YEAR_OF_ERA

using $JapaneseEraArray = $Array<::java::time::chrono::JapaneseEra>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $Year = ::java::time::Year;
using $ZoneId = ::java::time::ZoneId;
using $AbstractChronology = ::java::time::chrono::AbstractChronology;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
using $Era = ::java::time::chrono::Era;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $JapaneseChronology$1 = ::java::time::chrono::JapaneseChronology$1;
using $JapaneseDate = ::java::time::chrono::JapaneseDate;
using $JapaneseEra = ::java::time::chrono::JapaneseEra;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAdjusters = ::java::time::temporal::TemporalAdjusters;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Calendar = ::java::util::Calendar;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $TimeZone = ::java::util::TimeZone;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $CalendarSystem = ::sun::util::calendar::CalendarSystem;
using $1Era = ::sun::util::calendar::Era;
using $LocalGregorianCalendar = ::sun::util::calendar::LocalGregorianCalendar;
using $LocalGregorianCalendar$Date = ::sun::util::calendar::LocalGregorianCalendar$Date;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _JapaneseChronology_FieldInfo_[] = {
	{"JCAL", "Lsun/util/calendar/LocalGregorianCalendar;", nullptr, $STATIC | $FINAL, $staticField(JapaneseChronology, JCAL)},
	{"LOCALE", "Ljava/util/Locale;", nullptr, $STATIC | $FINAL, $staticField(JapaneseChronology, LOCALE)},
	{"INSTANCE", "Ljava/time/chrono/JapaneseChronology;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(JapaneseChronology, INSTANCE)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseChronology, serialVersionUID)},
	{}
};

$MethodInfo _JapaneseChronology_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PRIVATE, $method(JapaneseChronology, init$, void)},
	{"date", "(Ljava/time/chrono/Era;III)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, date, $ChronoLocalDate*, $Era*, int32_t, int32_t, int32_t)},
	{"date", "(III)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, date, $ChronoLocalDate*, int32_t, int32_t, int32_t)},
	{"date", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, date, $ChronoLocalDate*, $TemporalAccessor*)},
	{"dateEpochDay", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, dateEpochDay, $ChronoLocalDate*, int64_t)},
	{"dateNow", "()Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, dateNow, $ChronoLocalDate*)},
	{"dateNow", "(Ljava/time/ZoneId;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, dateNow, $ChronoLocalDate*, $ZoneId*)},
	{"dateNow", "(Ljava/time/Clock;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, dateNow, $ChronoLocalDate*, $Clock*)},
	{"dateYearDay", "(Ljava/time/chrono/Era;II)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, dateYearDay, $ChronoLocalDate*, $Era*, int32_t, int32_t)},
	{"dateYearDay", "(II)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, dateYearDay, $ChronoLocalDate*, int32_t, int32_t)},
	{"eraOf", "(I)Ljava/time/chrono/JapaneseEra;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, eraOf, $Era*, int32_t)},
	{"eras", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/chrono/Era;>;", $PUBLIC, $virtualMethod(JapaneseChronology, eras, $List*)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, getCalendarType, $String*)},
	{"getCurrentEra", "()Ljava/time/chrono/JapaneseEra;", nullptr, 0, $method(JapaneseChronology, getCurrentEra, $JapaneseEra*)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, getId, $String*)},
	{"isLeapYear", "(J)Z", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, isLeapYear, bool, int64_t)},
	{"localDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/JapaneseDate;>;", $PUBLIC, $virtualMethod(JapaneseChronology, localDateTime, $ChronoLocalDateTime*, $TemporalAccessor*)},
	{"prolepticYear", "(Ljava/time/chrono/Era;I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, prolepticYear, int32_t, $Era*, int32_t)},
	{"prolepticYearLenient", "(Ljava/time/chrono/JapaneseEra;I)I", nullptr, $PRIVATE, $method(JapaneseChronology, prolepticYearLenient, int32_t, $JapaneseEra*, int32_t)},
	{"range", "(Ljava/time/temporal/ChronoField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(JapaneseChronology, range, $ValueRange*, $ChronoField*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(JapaneseChronology, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/JapaneseDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/JapaneseDate;", $PUBLIC, $virtualMethod(JapaneseChronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYD", "(Ljava/time/chrono/JapaneseEra;ILjava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/time/chrono/JapaneseEra;ILjava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", $PRIVATE, $method(JapaneseChronology, resolveYD, $ChronoLocalDate*, $JapaneseEra*, int32_t, $Map*, $ResolverStyle*)},
	{"resolveYMD", "(Ljava/time/chrono/JapaneseEra;ILjava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/time/chrono/JapaneseEra;ILjava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", $PRIVATE, $method(JapaneseChronology, resolveYMD, $ChronoLocalDate*, $JapaneseEra*, int32_t, $Map*, $ResolverStyle*)},
	{"resolveYearOfEra", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(JapaneseChronology, resolveYearOfEra, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(JapaneseChronology, writeReplace, $Object*)},
	{"zonedDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/JapaneseDate;>;", $PUBLIC, $virtualMethod(JapaneseChronology, zonedDateTime, $ChronoZonedDateTime*, $TemporalAccessor*)},
	{"zonedDateTime", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/JapaneseDate;>;", $PUBLIC, $virtualMethod(JapaneseChronology, zonedDateTime, $ChronoZonedDateTime*, $Instant*, $ZoneId*)},
	{}
};

$InnerClassInfo _JapaneseChronology_InnerClassesInfo_[] = {
	{"java.time.chrono.JapaneseChronology$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _JapaneseChronology_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.JapaneseChronology",
	"java.time.chrono.AbstractChronology",
	"java.io.Serializable",
	_JapaneseChronology_FieldInfo_,
	_JapaneseChronology_MethodInfo_,
	nullptr,
	nullptr,
	_JapaneseChronology_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.chrono.JapaneseChronology$1"
};

$Object* allocate$JapaneseChronology($Class* clazz) {
	return $of($alloc(JapaneseChronology));
}

bool JapaneseChronology::equals(Object$* obj) {
	 return this->$AbstractChronology::equals(obj);
}

int32_t JapaneseChronology::hashCode() {
	 return this->$AbstractChronology::hashCode();
}

$String* JapaneseChronology::toString() {
	 return this->$AbstractChronology::toString();
}

$Object* JapaneseChronology::clone() {
	 return this->$AbstractChronology::clone();
}

void JapaneseChronology::finalize() {
	this->$AbstractChronology::finalize();
}

$LocalGregorianCalendar* JapaneseChronology::JCAL = nullptr;
$Locale* JapaneseChronology::LOCALE = nullptr;
JapaneseChronology* JapaneseChronology::INSTANCE = nullptr;

void JapaneseChronology::init$() {
	$AbstractChronology::init$();
}

$String* JapaneseChronology::getId() {
	return "Japanese"_s;
}

$String* JapaneseChronology::getCalendarType() {
	return "japanese"_s;
}

$ChronoLocalDate* JapaneseChronology::date($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	$var($JapaneseEra, jera, nullptr);
	bool var$0 = $instanceOf($JapaneseEra, era);
	if (var$0) {
		$assign(jera, $cast($JapaneseEra, era));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($ClassCastException, "Era must be JapaneseEra"_s);
	}
	return $JapaneseDate::of(jera, yearOfEra, month, dayOfMonth);
}

$ChronoLocalDate* JapaneseChronology::date(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	return $new($JapaneseDate, $($LocalDate::of(prolepticYear, month, dayOfMonth)));
}

$ChronoLocalDate* JapaneseChronology::dateYearDay($Era* era, int32_t yearOfEra, int32_t dayOfYear) {
	return $JapaneseDate::ofYearDay($cast($JapaneseEra, era), yearOfEra, dayOfYear);
}

$ChronoLocalDate* JapaneseChronology::dateYearDay(int32_t prolepticYear, int32_t dayOfYear) {
	return $new($JapaneseDate, $($LocalDate::ofYearDay(prolepticYear, dayOfYear)));
}

$ChronoLocalDate* JapaneseChronology::dateEpochDay(int64_t epochDay) {
	return $new($JapaneseDate, $($LocalDate::ofEpochDay(epochDay)));
}

$ChronoLocalDate* JapaneseChronology::dateNow() {
	return dateNow($($Clock::systemDefaultZone()));
}

$ChronoLocalDate* JapaneseChronology::dateNow($ZoneId* zone) {
	return dateNow($($Clock::system(zone)));
}

$ChronoLocalDate* JapaneseChronology::dateNow($Clock* clock) {
	return date($($LocalDate::now(clock)));
}

$ChronoLocalDate* JapaneseChronology::date($TemporalAccessor* temporal) {
	if ($instanceOf($JapaneseDate, temporal)) {
		return $cast($JapaneseDate, temporal);
	}
	return $new($JapaneseDate, $($LocalDate::from(temporal)));
}

$ChronoLocalDateTime* JapaneseChronology::localDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::localDateTime(temporal);
}

$ChronoZonedDateTime* JapaneseChronology::zonedDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::zonedDateTime(temporal);
}

$ChronoZonedDateTime* JapaneseChronology::zonedDateTime($Instant* instant, $ZoneId* zone) {
	return $AbstractChronology::zonedDateTime(instant, zone);
}

bool JapaneseChronology::isLeapYear(int64_t prolepticYear) {
	$init($IsoChronology);
	return $nc($IsoChronology::INSTANCE)->isLeapYear(prolepticYear);
}

int32_t JapaneseChronology::prolepticYear($Era* era, int32_t yearOfEra) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($JapaneseEra, era) == false) {
		$throwNew($ClassCastException, "Era must be JapaneseEra"_s);
	}
	$var($JapaneseEra, jera, $cast($JapaneseEra, era));
	int32_t gregorianYear = $nc($($nc($($nc(jera)->getPrivateEra()))->getSinceDate()))->getYear() + yearOfEra - 1;
	if (yearOfEra == 1) {
		return gregorianYear;
	}
	if (gregorianYear >= $Year::MIN_VALUE && gregorianYear <= $Year::MAX_VALUE) {
		$var($LocalGregorianCalendar$Date, jdate, $cast($LocalGregorianCalendar$Date, $nc(JapaneseChronology::JCAL)->newCalendarDate(nullptr)));
		$nc($($nc(jdate)->setEra($(jera->getPrivateEra()))))->setDate(yearOfEra, 1, 1);
		if ($nc(JapaneseChronology::JCAL)->validate(jdate)) {
			return gregorianYear;
		}
	}
	$throwNew($DateTimeException, "Invalid yearOfEra value"_s);
}

$Era* JapaneseChronology::eraOf(int32_t eraValue) {
	return $JapaneseEra::of(eraValue);
}

$List* JapaneseChronology::eras() {
	return $List::of($($JapaneseEra::values()));
}

$JapaneseEra* JapaneseChronology::getCurrentEra() {
	$var($JapaneseEraArray, eras, $JapaneseEra::values());
	return $nc(eras)->get(eras->length - 1);
}

$ValueRange* JapaneseChronology::range($ChronoField* field) {
	$useLocalCurrentObjectStackCache();
	$init($JapaneseChronology$1);
	switch ($nc($JapaneseChronology$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((field))->ordinal())) {
	case 1:
		{}
	case 2:
		{}
	case 3:
		{}
	case 4:
		{
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	case 5:
		{
			{
				$var($Calendar, jcal, $Calendar::getInstance(JapaneseChronology::LOCALE));
				int32_t startYear = $nc($($nc($($nc($(getCurrentEra()))->getPrivateEra()))->getSinceDate()))->getYear();
				int64_t var$0 = (int64_t)$nc(jcal)->getGreatestMinimum($Calendar::YEAR);
				return $ValueRange::of(1, var$0, jcal->getLeastMaximum($Calendar::YEAR) + 1, $Year::MAX_VALUE - startYear);
			}
		}
	case 6:
		{
			{
				$var($Calendar, jcal, $Calendar::getInstance(JapaneseChronology::LOCALE));
				int32_t fieldIndex = $Calendar::DAY_OF_YEAR;
				int64_t var$1 = (int64_t)$nc(jcal)->getMinimum(fieldIndex);
				int64_t var$2 = (int64_t)jcal->getGreatestMinimum(fieldIndex);
				int64_t var$3 = (int64_t)jcal->getLeastMaximum(fieldIndex);
				return $ValueRange::of(var$1, var$2, var$3, jcal->getMaximum(fieldIndex));
			}
		}
	case 7:
		{
			$init($JapaneseDate);
			return $ValueRange::of($nc($JapaneseDate::MEIJI_6_ISODATE)->getYear(), $Year::MAX_VALUE);
		}
	case 8:
		{
			$init($JapaneseEra);
			int64_t var$4 = (int64_t)$nc($JapaneseEra::MEIJI)->getValue();
			return $ValueRange::of(var$4, $nc($(getCurrentEra()))->getValue());
		}
	default:
		{
			return field->range();
		}
	}
}

$ChronoLocalDate* JapaneseChronology::resolveDate($Map* fieldValues, $ResolverStyle* resolverStyle) {
	return $cast($JapaneseDate, $AbstractChronology::resolveDate(fieldValues, resolverStyle));
}

$ChronoLocalDate* JapaneseChronology::resolveYearOfEra($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Long, eraLong, $cast($Long, $nc(fieldValues)->get($ChronoField::ERA)));
	$var($JapaneseEra, era, nullptr);
	if (eraLong != nullptr) {
		$assign(era, $cast($JapaneseEra, eraOf($nc($(range($ChronoField::ERA)))->checkValidIntValue(eraLong->longValue(), $ChronoField::ERA))));
	}
	$var($Long, yoeLong, $cast($Long, fieldValues->get($ChronoField::YEAR_OF_ERA)));
	int32_t yoe = 0;
	if (yoeLong != nullptr) {
		yoe = $nc($(range($ChronoField::YEAR_OF_ERA)))->checkValidIntValue(yoeLong->longValue(), $ChronoField::YEAR_OF_ERA);
	}
	$init($ResolverStyle);
	if (era == nullptr && yoeLong != nullptr && fieldValues->containsKey($ChronoField::YEAR) == false && resolverStyle != $ResolverStyle::STRICT) {
		$assign(era, $nc($($JapaneseEra::values()))->get($nc($($JapaneseEra::values()))->length - 1));
	}
	if (yoeLong != nullptr && era != nullptr) {
		if (fieldValues->containsKey($ChronoField::MONTH_OF_YEAR)) {
			if (fieldValues->containsKey($ChronoField::DAY_OF_MONTH)) {
				return resolveYMD(era, yoe, fieldValues, resolverStyle);
			}
		}
		if (fieldValues->containsKey($ChronoField::DAY_OF_YEAR)) {
			return resolveYD(era, yoe, fieldValues, resolverStyle);
		}
	}
	return nullptr;
}

int32_t JapaneseChronology::prolepticYearLenient($JapaneseEra* era, int32_t yearOfEra) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc(era)->getPrivateEra()))->getSinceDate()))->getYear() + yearOfEra - 1;
}

$ChronoLocalDate* JapaneseChronology::resolveYMD($JapaneseEra* era, int32_t yoe, $Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$nc(fieldValues)->remove($ChronoField::ERA);
	fieldValues->remove($ChronoField::YEAR_OF_ERA);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int32_t y = prolepticYearLenient(era, yoe);
		int64_t months = $Math::subtractExact($nc(($cast($Long, $(fieldValues->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t days = $Math::subtractExact($nc(($cast($Long, $(fieldValues->remove($ChronoField::DAY_OF_MONTH)))))->longValue(), (int64_t)1);
		$init($ChronoUnit);
		return $nc($($nc($($cast($JapaneseDate, date(y, 1, 1))))->plus(months, $ChronoUnit::MONTHS)))->plus(days, $ChronoUnit::DAYS);
	}
	int32_t moy = $nc($(range($ChronoField::MONTH_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $(fieldValues->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), $ChronoField::MONTH_OF_YEAR);
	int32_t dom = $nc($(range($ChronoField::DAY_OF_MONTH)))->checkValidIntValue($nc(($cast($Long, $(fieldValues->remove($ChronoField::DAY_OF_MONTH)))))->longValue(), $ChronoField::DAY_OF_MONTH);
	if (resolverStyle == $ResolverStyle::SMART) {
		if (yoe < 1) {
			$throwNew($DateTimeException, $$str({"Invalid YearOfEra: "_s, $$str(yoe)}));
		}
		int32_t y = prolepticYearLenient(era, yoe);
		$var($JapaneseDate, result, nullptr);
		try {
			$assign(result, $cast($JapaneseDate, date(y, moy, dom)));
		} catch ($DateTimeException& ex) {
			$assign(result, $nc($($cast($JapaneseDate, date(y, moy, 1))))->with($($TemporalAdjusters::lastDayOfMonth())));
		}
		bool var$0 = $cast($JapaneseEra, $nc(result)->getEra()) != era;
		if (var$0 && result->get($ChronoField::YEAR_OF_ERA) > 1 && yoe > 1) {
			$throwNew($DateTimeException, $$str({"Invalid YearOfEra for Era: "_s, era, " "_s, $$str(yoe)}));
		}
		return result;
	}
	return date(era, yoe, moy, dom);
}

$ChronoLocalDate* JapaneseChronology::resolveYD($JapaneseEra* era, int32_t yoe, $Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$nc(fieldValues)->remove($ChronoField::ERA);
	fieldValues->remove($ChronoField::YEAR_OF_ERA);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int32_t y = prolepticYearLenient(era, yoe);
		int64_t days = $Math::subtractExact($nc(($cast($Long, $(fieldValues->remove($ChronoField::DAY_OF_YEAR)))))->longValue(), (int64_t)1);
		$init($ChronoUnit);
		return $nc($($cast($JapaneseDate, dateYearDay(y, 1))))->plus(days, $ChronoUnit::DAYS);
	}
	int32_t doy = $nc($(range($ChronoField::DAY_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $(fieldValues->remove($ChronoField::DAY_OF_YEAR)))))->longValue(), $ChronoField::DAY_OF_YEAR);
	return dateYearDay(era, yoe, doy);
}

$Object* JapaneseChronology::writeReplace() {
	return $of($AbstractChronology::writeReplace());
}

void JapaneseChronology::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void clinit$JapaneseChronology($Class* class$) {
	$assignStatic(JapaneseChronology::JCAL, $cast($LocalGregorianCalendar, $CalendarSystem::forName("japanese"_s)));
	$assignStatic(JapaneseChronology::LOCALE, $Locale::forLanguageTag("ja-JP-u-ca-japanese"_s));
	$assignStatic(JapaneseChronology::INSTANCE, $new(JapaneseChronology));
}

JapaneseChronology::JapaneseChronology() {
}

$Class* JapaneseChronology::load$($String* name, bool initialize) {
	$loadClass(JapaneseChronology, name, initialize, &_JapaneseChronology_ClassInfo_, clinit$JapaneseChronology, allocate$JapaneseChronology);
	return class$;
}

$Class* JapaneseChronology::class$ = nullptr;

		} // chrono
	} // time
} // java