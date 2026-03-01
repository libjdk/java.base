#include <java/time/chrono/JapaneseDate.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
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
#include <java/time/chrono/JapaneseChronology.h>
#include <java/time/chrono/JapaneseDate$1.h>
#include <java/time/chrono/JapaneseEra.h>
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
#include <java/util/Calendar.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/TimeZone.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/Era.h>
#include <sun/util/calendar/LocalGregorianCalendar$Date.h>
#include <sun/util/calendar/LocalGregorianCalendar.h>
#include <jcpp.h>

#undef ALIGNED_DAY_OF_WEEK_IN_MONTH
#undef ALIGNED_DAY_OF_WEEK_IN_YEAR
#undef ALIGNED_WEEK_OF_MONTH
#undef ALIGNED_WEEK_OF_YEAR
#undef DAY_OF_MONTH
#undef DAY_OF_YEAR
#undef ERA
#undef ERA_OFFSET
#undef INSTANCE
#undef JAPANESE_DATE_TYPE
#undef JCAL
#undef LOCALE
#undef MEIJI_6_ISODATE
#undef MONTH_OF_YEAR
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
using $DateTimeException = ::java::time::DateTimeException;
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
using $JapaneseChronology = ::java::time::chrono::JapaneseChronology;
using $JapaneseDate$1 = ::java::time::chrono::JapaneseDate$1;
using $JapaneseEra = ::java::time::chrono::JapaneseEra;
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
using $Calendar = ::java::util::Calendar;
using $Objects = ::java::util::Objects;
using $TimeZone = ::java::util::TimeZone;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $1Era = ::sun::util::calendar::Era;
using $LocalGregorianCalendar = ::sun::util::calendar::LocalGregorianCalendar;
using $LocalGregorianCalendar$Date = ::sun::util::calendar::LocalGregorianCalendar$Date;

namespace java {
	namespace time {
		namespace chrono {

$CompoundAttribute _JapaneseDate_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _JapaneseDate_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseDate, serialVersionUID)},
	{"isoDate", "Ljava/time/LocalDate;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(JapaneseDate, isoDate)},
	{"era", "Ljava/time/chrono/JapaneseEra;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(JapaneseDate, era)},
	{"yearOfEra", "I", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(JapaneseDate, yearOfEra)},
	{"MEIJI_6_ISODATE", "Ljava/time/LocalDate;", nullptr, $STATIC | $FINAL, $staticField(JapaneseDate, MEIJI_6_ISODATE)},
	{}
};

$MethodInfo _JapaneseDate_MethodInfo_[] = {
	{"<init>", "(Ljava/time/LocalDate;)V", nullptr, 0, $method(JapaneseDate, init$, void, $LocalDate*)},
	{"<init>", "(Ljava/time/chrono/JapaneseEra;ILjava/time/LocalDate;)V", nullptr, 0, $method(JapaneseDate, init$, void, $JapaneseEra*, int32_t, $LocalDate*)},
	{"atTime", "(Ljava/time/LocalTime;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/LocalTime;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/JapaneseDate;>;", $PUBLIC | $FINAL, $virtualMethod(JapaneseDate, atTime, $ChronoLocalDateTime*, $LocalTime*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, equals, bool, Object$*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(JapaneseDate, from, JapaneseDate*, $TemporalAccessor*)},
	{"getChronology", "()Ljava/time/chrono/JapaneseChronology;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, getChronology, $Chronology*)},
	{"getEra", "()Ljava/time/chrono/JapaneseEra;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, getEra, $Era*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, getLong, int64_t, $TemporalField*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, hashCode, int32_t)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, isSupported, bool, $TemporalField*)},
	{"lengthOfMonth", "()I", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, lengthOfMonth, int32_t)},
	{"lengthOfYear", "()I", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, lengthOfYear, int32_t)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, minus, JapaneseDate*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, minus, JapaneseDate*, int64_t, $TemporalUnit*)},
	{"minusDays", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, minusDays, JapaneseDate*, int64_t)},
	{"minusMonths", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, minusMonths, JapaneseDate*, int64_t)},
	{"minusWeeks", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, minusWeeks, JapaneseDate*, int64_t)},
	{"minusYears", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, minusYears, JapaneseDate*, int64_t)},
	{"now", "()Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(JapaneseDate, now, JapaneseDate*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(JapaneseDate, now, JapaneseDate*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(JapaneseDate, now, JapaneseDate*, $Clock*)},
	{"of", "(Ljava/time/chrono/JapaneseEra;III)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(JapaneseDate, of, JapaneseDate*, $JapaneseEra*, int32_t, int32_t, int32_t)},
	{"of", "(III)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC | $STATIC, $staticMethod(JapaneseDate, of, JapaneseDate*, int32_t, int32_t, int32_t)},
	{"ofYearDay", "(Ljava/time/chrono/JapaneseEra;II)Ljava/time/chrono/JapaneseDate;", nullptr, $STATIC, $staticMethod(JapaneseDate, ofYearDay, JapaneseDate*, $JapaneseEra*, int32_t, int32_t)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, plus, JapaneseDate*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, plus, JapaneseDate*, int64_t, $TemporalUnit*)},
	{"plusDays", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, plusDays, JapaneseDate*, int64_t)},
	{"plusMonths", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, plusMonths, JapaneseDate*, int64_t)},
	{"plusWeeks", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, plusWeeks, JapaneseDate*, int64_t)},
	{"plusYears", "(J)Ljava/time/chrono/JapaneseDate;", nullptr, 0, $virtualMethod(JapaneseDate, plusYears, JapaneseDate*, int64_t)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/chrono/JapaneseDate;", nullptr, $STATIC, $staticMethod(JapaneseDate, readExternal, JapaneseDate*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(JapaneseDate, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toEpochDay", "()J", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, toEpochDay, int64_t)},
	{"toPrivateJapaneseDate", "(Ljava/time/LocalDate;)Lsun/util/calendar/LocalGregorianCalendar$Date;", nullptr, $PRIVATE | $STATIC, $staticMethod(JapaneseDate, toPrivateJapaneseDate, $LocalGregorianCalendar$Date*, $LocalDate*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(JapaneseDate, toString, $String*)},
	{"until", "(Ljava/time/chrono/ChronoLocalDate;)Ljava/time/chrono/ChronoPeriod;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, until, $ChronoPeriod*, $ChronoLocalDate*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(JapaneseDate, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, with, JapaneseDate*, $TemporalField*, int64_t)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/chrono/JapaneseDate;", nullptr, $PUBLIC, $virtualMethod(JapaneseDate, with, JapaneseDate*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/LocalDate;)Ljava/time/chrono/JapaneseDate;", nullptr, $PRIVATE, $method(JapaneseDate, with, JapaneseDate*, $LocalDate*)},
	{"withYear", "(Ljava/time/chrono/JapaneseEra;I)Ljava/time/chrono/JapaneseDate;", nullptr, $PRIVATE, $method(JapaneseDate, withYear, JapaneseDate*, $JapaneseEra*, int32_t)},
	{"withYear", "(I)Ljava/time/chrono/JapaneseDate;", nullptr, $PRIVATE, $method(JapaneseDate, withYear, JapaneseDate*, int32_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(JapaneseDate, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(JapaneseDate, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _JapaneseDate_InnerClassesInfo_[] = {
	{"java.time.chrono.JapaneseDate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _JapaneseDate_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.JapaneseDate",
	"java.time.chrono.ChronoLocalDateImpl",
	nullptr,
	_JapaneseDate_FieldInfo_,
	_JapaneseDate_MethodInfo_,
	"Ljava/time/chrono/ChronoLocalDateImpl<Ljava/time/chrono/JapaneseDate;>;Ljava/time/chrono/ChronoLocalDate;Ljava/io/Serializable;",
	nullptr,
	_JapaneseDate_InnerClassesInfo_,
	_JapaneseDate_Annotations_,
	nullptr,
	"java.time.chrono.JapaneseDate$1"
};

$Object* allocate$JapaneseDate($Class* clazz) {
	return $of($alloc(JapaneseDate));
}

$LocalDate* JapaneseDate::MEIJI_6_ISODATE = nullptr;

JapaneseDate* JapaneseDate::now() {
	$init(JapaneseDate);
	return now($($Clock::systemDefaultZone()));
}

JapaneseDate* JapaneseDate::now($ZoneId* zone) {
	$init(JapaneseDate);
	return now($($Clock::system(zone)));
}

JapaneseDate* JapaneseDate::now($Clock* clock) {
	$init(JapaneseDate);
	return $new(JapaneseDate, $($LocalDate::now(clock)));
}

JapaneseDate* JapaneseDate::of($JapaneseEra* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	$init(JapaneseDate);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(era), "era"_s);
	$init($JapaneseChronology);
	$var($LocalGregorianCalendar$Date, jdate, $cast($LocalGregorianCalendar$Date, $nc($JapaneseChronology::JCAL)->newCalendarDate(nullptr)));
	$nc($($nc(jdate)->setEra($($nc(era)->getPrivateEra()))))->setDate(yearOfEra, month, dayOfMonth);
	if (!$nc($JapaneseChronology::JCAL)->validate(jdate)) {
		$throwNew($DateTimeException, "year, month, and day not valid for Era"_s);
	}
	$var($LocalDate, date, $LocalDate::of(jdate->getNormalizedYear(), month, dayOfMonth));
	return $new(JapaneseDate, era, yearOfEra, date);
}

JapaneseDate* JapaneseDate::of(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	$init(JapaneseDate);
	return $new(JapaneseDate, $($LocalDate::of(prolepticYear, month, dayOfMonth)));
}

JapaneseDate* JapaneseDate::ofYearDay($JapaneseEra* era, int32_t yearOfEra, int32_t dayOfYear) {
	$init(JapaneseDate);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(era), "era"_s);
	$var($CalendarDate, firstDay, $nc($($nc(era)->getPrivateEra()))->getSinceDate());
	$init($JapaneseChronology);
	$var($LocalGregorianCalendar$Date, jdate, $cast($LocalGregorianCalendar$Date, $nc($JapaneseChronology::JCAL)->newCalendarDate(nullptr)));
	$nc(jdate)->setEra($(era->getPrivateEra()));
	if (yearOfEra == 1) {
		int32_t var$0 = yearOfEra;
		int32_t var$1 = $nc(firstDay)->getMonth();
		jdate->setDate(var$0, var$1, firstDay->getDayOfMonth() + dayOfYear - 1);
	} else {
		jdate->setDate(yearOfEra, 1, dayOfYear);
	}
	$nc($JapaneseChronology::JCAL)->normalize(jdate);
	bool var$2 = era->getPrivateEra() != jdate->getEra();
	if (var$2 || yearOfEra != jdate->getYear()) {
		$throwNew($DateTimeException, "Invalid parameters"_s);
	}
	int32_t var$3 = jdate->getNormalizedYear();
	int32_t var$4 = jdate->getMonth();
	$var($LocalDate, localdate, $LocalDate::of(var$3, var$4, jdate->getDayOfMonth()));
	return $new(JapaneseDate, era, yearOfEra, localdate);
}

JapaneseDate* JapaneseDate::from($TemporalAccessor* temporal) {
	$init(JapaneseDate);
	$init($JapaneseChronology);
	return $cast(JapaneseDate, $nc($JapaneseChronology::INSTANCE)->date(temporal));
}

void JapaneseDate::init$($LocalDate* isoDate) {
	$useLocalCurrentObjectStackCache();
	$ChronoLocalDateImpl::init$();
	if ($nc(isoDate)->isBefore(JapaneseDate::MEIJI_6_ISODATE)) {
		$throwNew($DateTimeException, "JapaneseDate before Meiji 6 is not supported"_s);
	}
	$var($LocalGregorianCalendar$Date, jdate, toPrivateJapaneseDate(isoDate));
	$set(this, era, $JapaneseEra::toJapaneseEra($($nc(jdate)->getEra())));
	this->yearOfEra = $nc(jdate)->getYear();
	$set(this, isoDate, isoDate);
}

void JapaneseDate::init$($JapaneseEra* era, int32_t year, $LocalDate* isoDate) {
	$ChronoLocalDateImpl::init$();
	if ($nc(isoDate)->isBefore(JapaneseDate::MEIJI_6_ISODATE)) {
		$throwNew($DateTimeException, "JapaneseDate before Meiji 6 is not supported"_s);
	}
	$set(this, era, era);
	this->yearOfEra = year;
	$set(this, isoDate, isoDate);
}

$Chronology* JapaneseDate::getChronology() {
	$init($JapaneseChronology);
	return $JapaneseChronology::INSTANCE;
}

$Era* JapaneseDate::getEra() {
	return this->era;
}

int32_t JapaneseDate::lengthOfMonth() {
	return $nc(this->isoDate)->lengthOfMonth();
}

int32_t JapaneseDate::lengthOfYear() {
	$init($JapaneseChronology);
	$var($Calendar, jcal, $Calendar::getInstance($JapaneseChronology::LOCALE));
	$nc(jcal)->set($Calendar::ERA, $nc(this->era)->getValue() + $JapaneseEra::ERA_OFFSET);
	int32_t var$0 = this->yearOfEra;
	int32_t var$1 = $nc(this->isoDate)->getMonthValue() - 1;
	jcal->set(var$0, var$1, $nc(this->isoDate)->getDayOfMonth());
	return jcal->getActualMaximum($Calendar::DAY_OF_YEAR);
}

bool JapaneseDate::isSupported($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH) || $equals(field, $ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR) || $equals(field, $ChronoField::ALIGNED_WEEK_OF_MONTH) || $equals(field, $ChronoField::ALIGNED_WEEK_OF_YEAR)) {
		return false;
	}
	return $ChronoLocalDateImpl::isSupported(field);
}

$ValueRange* JapaneseDate::range($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoField, field)) {
		if (isSupported(field)) {
			$ChronoField* f = $cast($ChronoField, field);
			$init($JapaneseDate$1);
			switch ($nc($JapaneseDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((f))->ordinal())) {
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
					{
						$init($JapaneseChronology);
						$var($Calendar, jcal, $Calendar::getInstance($JapaneseChronology::LOCALE));
						$nc(jcal)->set($Calendar::ERA, $nc(this->era)->getValue() + $JapaneseEra::ERA_OFFSET);
						int32_t var$0 = this->yearOfEra;
						int32_t var$1 = $nc(this->isoDate)->getMonthValue() - 1;
						jcal->set(var$0, var$1, $nc(this->isoDate)->getDayOfMonth());
						return $ValueRange::of(1, jcal->getActualMaximum($Calendar::YEAR));
					}
				}
			}
			return $nc($($cast($JapaneseChronology, getChronology())))->range(f);
		}
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->rangeRefinedBy(this);
}

int64_t JapaneseDate::getLong($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ChronoField, field)) {
		$init($JapaneseDate$1);
		{
			$var($Calendar, jcal, nullptr)
			switch ($nc($JapaneseDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
			case 4:
				{}
			case 5:
				{}
			case 6:
				{}
			case 7:
				{
					$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
				}
			case 3:
				{
					return this->yearOfEra;
				}
			case 8:
				{
					return $nc(this->era)->getValue();
				}
			case 2:
				{
					$init($JapaneseChronology);
					$assign(jcal, $Calendar::getInstance($JapaneseChronology::LOCALE));
					$nc(jcal)->set($Calendar::ERA, $nc(this->era)->getValue() + $JapaneseEra::ERA_OFFSET);
					int32_t var$0 = this->yearOfEra;
					int32_t var$1 = $nc(this->isoDate)->getMonthValue() - 1;
					$nc(jcal)->set(var$0, var$1, $nc(this->isoDate)->getDayOfMonth());
					return $nc(jcal)->get($Calendar::DAY_OF_YEAR);
				}
			}
		}
		return $nc(this->isoDate)->getLong(field);
	}
	return $nc(field)->getFrom(this);
}

$LocalGregorianCalendar$Date* JapaneseDate::toPrivateJapaneseDate($LocalDate* isoDate) {
	$init(JapaneseDate);
	$useLocalCurrentObjectStackCache();
	$init($JapaneseChronology);
	$var($LocalGregorianCalendar$Date, jdate, $cast($LocalGregorianCalendar$Date, $nc($JapaneseChronology::JCAL)->newCalendarDate(nullptr)));
	$var($1Era, sunEra, $JapaneseEra::privateEraFrom(isoDate));
	int32_t year = $nc(isoDate)->getYear();
	if (sunEra != nullptr) {
		year -= $nc($(sunEra->getSinceDate()))->getYear() - 1;
	}
	$nc($($nc($($nc($($nc(jdate)->setEra(sunEra)))->setYear(year)))->setMonth(isoDate->getMonthValue())))->setDayOfMonth(isoDate->getDayOfMonth());
	$nc($JapaneseChronology::JCAL)->normalize(jdate);
	return jdate;
}

JapaneseDate* JapaneseDate::with($TemporalField* field, int64_t newValue) {
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
			$init($JapaneseDate$1);
			switch ($nc($JapaneseDate$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 3:
				{}
			case 9:
				{}
			case 8:
				{
					{
						int32_t nvalue = $nc($($nc($($cast($JapaneseChronology, getChronology())))->range(chronoField)))->checkValidIntValue(newValue, chronoField);
						switch ($nc($JapaneseDate$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
						case 3:
							{
								return this->withYear(nvalue);
							}
						case 9:
							{
								return with($($nc(this->isoDate)->withYear(nvalue)));
							}
						case 8:
							{
								{
									return this->withYear($($JapaneseEra::of(nvalue)), this->yearOfEra);
								}
							}
						}
					}
				}
			}
			return with($($nc(this->isoDate)->with(field, newValue)));
		}
	}
	return $cast(JapaneseDate, $ChronoLocalDateImpl::with(field, newValue));
}

JapaneseDate* JapaneseDate::with($TemporalAdjuster* adjuster) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::with(adjuster));
}

JapaneseDate* JapaneseDate::plus($TemporalAmount* amount) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::plus(amount));
}

JapaneseDate* JapaneseDate::minus($TemporalAmount* amount) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::minus(amount));
}

JapaneseDate* JapaneseDate::withYear($JapaneseEra* era, int32_t yearOfEra) {
	$init($JapaneseChronology);
	int32_t year = $nc($JapaneseChronology::INSTANCE)->prolepticYear(era, yearOfEra);
	return with($($nc(this->isoDate)->withYear(year)));
}

JapaneseDate* JapaneseDate::withYear(int32_t year) {
	return withYear($($cast($JapaneseEra, getEra())), year);
}

JapaneseDate* JapaneseDate::plusYears(int64_t years) {
	return with($($nc(this->isoDate)->plusYears(years)));
}

JapaneseDate* JapaneseDate::plusMonths(int64_t months) {
	return with($($nc(this->isoDate)->plusMonths(months)));
}

JapaneseDate* JapaneseDate::plusWeeks(int64_t weeksToAdd) {
	return with($($nc(this->isoDate)->plusWeeks(weeksToAdd)));
}

JapaneseDate* JapaneseDate::plusDays(int64_t days) {
	return with($($nc(this->isoDate)->plusDays(days)));
}

JapaneseDate* JapaneseDate::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::plus(amountToAdd, unit));
}

JapaneseDate* JapaneseDate::minus(int64_t amountToAdd, $TemporalUnit* unit) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::minus(amountToAdd, unit));
}

JapaneseDate* JapaneseDate::minusYears(int64_t yearsToSubtract) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::minusYears(yearsToSubtract));
}

JapaneseDate* JapaneseDate::minusMonths(int64_t monthsToSubtract) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::minusMonths(monthsToSubtract));
}

JapaneseDate* JapaneseDate::minusWeeks(int64_t weeksToSubtract) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::minusWeeks(weeksToSubtract));
}

JapaneseDate* JapaneseDate::minusDays(int64_t daysToSubtract) {
	return $cast(JapaneseDate, $ChronoLocalDateImpl::minusDays(daysToSubtract));
}

JapaneseDate* JapaneseDate::with($LocalDate* newDate) {
	return ($nc(newDate)->equals(this->isoDate) ? this : $new(JapaneseDate, newDate));
}

$ChronoLocalDateTime* JapaneseDate::atTime($LocalTime* localTime) {
	return $ChronoLocalDateImpl::atTime(localTime);
}

$ChronoPeriod* JapaneseDate::until($ChronoLocalDate* endDate) {
	$useLocalCurrentObjectStackCache();
	$var($Period, period, $cast($Period, $nc(this->isoDate)->until(endDate)));
	int32_t var$0 = $nc(period)->getYears();
	int32_t var$1 = period->getMonths();
	return $nc($($cast($JapaneseChronology, getChronology())))->period(var$0, var$1, period->getDays());
}

int64_t JapaneseDate::toEpochDay() {
	return $nc(this->isoDate)->toEpochDay();
}

bool JapaneseDate::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(JapaneseDate, otherDate, nullptr);
	bool var$1 = $instanceOf(JapaneseDate, obj);
	if (var$1) {
		$assign(otherDate, $cast(JapaneseDate, obj));
		var$1 = true;
	}
	bool var$0 = (var$1);
	return var$0 && $nc(this->isoDate)->equals($nc(otherDate)->isoDate);
}

int32_t JapaneseDate::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc($($nc($($cast($JapaneseChronology, getChronology())))->getId()))->hashCode();
	return var$0 ^ $nc(this->isoDate)->hashCode();
}

void JapaneseDate::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

$Object* JapaneseDate::writeReplace() {
	return $of($new($Ser, $Ser::JAPANESE_DATE_TYPE, this));
}

void JapaneseDate::writeExternal($DataOutput* out) {
	$init($ChronoField);
	$nc(out)->writeInt(get($ChronoField::YEAR));
	out->writeByte(get($ChronoField::MONTH_OF_YEAR));
	out->writeByte(get($ChronoField::DAY_OF_MONTH));
}

JapaneseDate* JapaneseDate::readExternal($DataInput* in) {
	$init(JapaneseDate);
	int32_t year = $nc(in)->readInt();
	int32_t month = in->readByte();
	int32_t dayOfMonth = in->readByte();
	$init($JapaneseChronology);
	return $cast(JapaneseDate, $nc($JapaneseChronology::INSTANCE)->date(year, month, dayOfMonth));
}

$String* JapaneseDate::toString() {
	return $ChronoLocalDateImpl::toString();
}

int64_t JapaneseDate::until($Temporal* endExclusive, $TemporalUnit* unit) {
	return $ChronoLocalDateImpl::until(endExclusive, unit);
}

void clinit$JapaneseDate($Class* class$) {
	$assignStatic(JapaneseDate::MEIJI_6_ISODATE, $LocalDate::of(1873, 1, 1));
}

JapaneseDate::JapaneseDate() {
}

$Class* JapaneseDate::load$($String* name, bool initialize) {
	$loadClass(JapaneseDate, name, initialize, &_JapaneseDate_ClassInfo_, clinit$JapaneseDate, allocate$JapaneseDate);
	return class$;
}

$Class* JapaneseDate::class$ = nullptr;

		} // chrono
	} // time
} // java