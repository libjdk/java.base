#include <java/util/GregorianCalendar.h>

#include <java/io/ObjectInputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/time/Instant.h>
#include <java/time/ZoneId.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalField.h>
#include <java/util/Calendar.h>
#include <java/util/Date.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/TimeZone.h>
#include <sun/util/calendar/BaseCalendar$Date.h>
#include <sun/util/calendar/BaseCalendar.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/CalendarSystem.h>
#include <sun/util/calendar/CalendarUtils.h>
#include <sun/util/calendar/Era.h>
#include <sun/util/calendar/Gregorian$Date.h>
#include <sun/util/calendar/Gregorian.h>
#include <sun/util/calendar/JulianCalendar$Date.h>
#include <sun/util/calendar/JulianCalendar.h>
#include <sun/util/calendar/ZoneInfo.h>
#include <jcpp.h>

#undef AD
#undef ALL_FIELDS
#undef AM
#undef AM_PM
#undef AM_PM_MASK
#undef BC
#undef BCE
#undef CE
#undef DAY_OF_MONTH
#undef DAY_OF_MONTH_MASK
#undef DAY_OF_WEEK
#undef DAY_OF_WEEK_IN_MONTH
#undef DAY_OF_WEEK_IN_MONTH_MASK
#undef DAY_OF_WEEK_MASK
#undef DAY_OF_YEAR
#undef DAY_OF_YEAR_MASK
#undef DECEMBER
#undef DEFAULT_GREGORIAN_CUTOVER
#undef DST_OFFSET
#undef DST_OFFSET_MASK
#undef EPOCH_OFFSET
#undef EPOCH_YEAR
#undef ERA
#undef ERA_MASK
#undef FIELD_COUNT
#undef FORMAT
#undef HOUR
#undef HOUR_MASK
#undef HOUR_OF_DAY
#undef HOUR_OF_DAY_MASK
#undef JANUARY
#undef LEAP_MONTH_LENGTH
#undef LEAST_MAX_VALUES
#undef MARCH
#undef MAX_VALUE
#undef MAX_VALUES
#undef MILLISECOND
#undef MILLISECOND_MASK
#undef MILLI_OF_SECOND
#undef MINUTE
#undef MINUTE_MASK
#undef MIN_VALUE
#undef MIN_VALUES
#undef MONDAY
#undef MONTH
#undef MONTH_LENGTH
#undef MONTH_MASK
#undef NO_TIMEZONE
#undef ONE_DAY
#undef ONE_HOUR
#undef ONE_MINUTE
#undef ONE_SECOND
#undef ONE_WEEK
#undef PM
#undef SATURDAY
#undef SECOND
#undef SECOND_MASK
#undef SUNDAY
#undef WEEK_OF_MONTH
#undef WEEK_OF_MONTH_MASK
#undef WEEK_OF_YEAR
#undef WEEK_OF_YEAR_MASK
#undef YEAR
#undef YEAR_MASK
#undef ZONE_OFFSET
#undef ZONE_OFFSET_MASK

using $EraArray = $Array<::sun::util::calendar::Era>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Instant = ::java::time::Instant;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalField = ::java::time::temporal::TemporalField;
using $Calendar = ::java::util::Calendar;
using $Date = ::java::util::Date;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $TimeZone = ::java::util::TimeZone;
using $BaseCalendar = ::sun::util::calendar::BaseCalendar;
using $BaseCalendar$Date = ::sun::util::calendar::BaseCalendar$Date;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $CalendarSystem = ::sun::util::calendar::CalendarSystem;
using $CalendarUtils = ::sun::util::calendar::CalendarUtils;
using $Era = ::sun::util::calendar::Era;
using $Gregorian = ::sun::util::calendar::Gregorian;
using $Gregorian$Date = ::sun::util::calendar::Gregorian$Date;
using $JulianCalendar = ::sun::util::calendar::JulianCalendar;
using $JulianCalendar$Date = ::sun::util::calendar::JulianCalendar$Date;
using $ZoneInfo = ::sun::util::calendar::ZoneInfo;

namespace java {
	namespace util {

$FieldInfo _GregorianCalendar_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(GregorianCalendar, $assertionsDisabled)},
	{"BC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GregorianCalendar, BC)},
	{"BCE", "I", nullptr, $STATIC | $FINAL, $constField(GregorianCalendar, BCE)},
	{"AD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GregorianCalendar, AD)},
	{"CE", "I", nullptr, $STATIC | $FINAL, $constField(GregorianCalendar, CE)},
	{"EPOCH_OFFSET", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, EPOCH_OFFSET)},
	{"EPOCH_YEAR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, EPOCH_YEAR)},
	{"MONTH_LENGTH", "[I", nullptr, $STATIC | $FINAL, $staticField(GregorianCalendar, MONTH_LENGTH)},
	{"LEAP_MONTH_LENGTH", "[I", nullptr, $STATIC | $FINAL, $staticField(GregorianCalendar, LEAP_MONTH_LENGTH)},
	{"ONE_SECOND", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, ONE_SECOND)},
	{"ONE_MINUTE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, ONE_MINUTE)},
	{"ONE_HOUR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, ONE_HOUR)},
	{"ONE_DAY", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, ONE_DAY)},
	{"ONE_WEEK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GregorianCalendar, ONE_WEEK)},
	{"MIN_VALUES", "[I", nullptr, $STATIC | $FINAL, $staticField(GregorianCalendar, MIN_VALUES)},
	{"LEAST_MAX_VALUES", "[I", nullptr, $STATIC | $FINAL, $staticField(GregorianCalendar, LEAST_MAX_VALUES)},
	{"MAX_VALUES", "[I", nullptr, $STATIC | $FINAL, $staticField(GregorianCalendar, MAX_VALUES)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(GregorianCalendar, serialVersionUID)},
	{"gcal", "Lsun/util/calendar/Gregorian;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GregorianCalendar, gcal)},
	{"jcal", "Lsun/util/calendar/JulianCalendar;", nullptr, $PRIVATE | $STATIC, $staticField(GregorianCalendar, jcal)},
	{"jeras", "[Lsun/util/calendar/Era;", nullptr, $PRIVATE | $STATIC, $staticField(GregorianCalendar, jeras)},
	{"DEFAULT_GREGORIAN_CUTOVER", "J", nullptr, $STATIC | $FINAL, $constField(GregorianCalendar, DEFAULT_GREGORIAN_CUTOVER)},
	{"gregorianCutover", "J", nullptr, $PRIVATE, $field(GregorianCalendar, gregorianCutover)},
	{"gregorianCutoverDate", "J", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, gregorianCutoverDate)},
	{"gregorianCutoverYear", "I", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, gregorianCutoverYear)},
	{"gregorianCutoverYearJulian", "I", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, gregorianCutoverYearJulian)},
	{"gdate", "Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, gdate)},
	{"cdate", "Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, cdate)},
	{"calsys", "Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, calsys)},
	{"zoneOffsets", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, zoneOffsets)},
	{"originalFields", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, originalFields)},
	{"cachedFixedDate", "J", nullptr, $PRIVATE | $TRANSIENT, $field(GregorianCalendar, cachedFixedDate)},
	{}
};

$MethodInfo _GregorianCalendar_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void)},
	{"<init>", "(Ljava/util/TimeZone;)V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void, $TimeZone*)},
	{"<init>", "(Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void, $Locale*)},
	{"<init>", "(Ljava/util/TimeZone;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void, $TimeZone*, $Locale*)},
	{"<init>", "(III)V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void, int32_t, int32_t, int32_t)},
	{"<init>", "(IIIII)V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"<init>", "(IIIIII)V", nullptr, $PUBLIC, $method(GregorianCalendar, init$, void, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"<init>", "(IIIIIII)V", nullptr, 0, $method(GregorianCalendar, init$, void, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"<init>", "(Ljava/util/TimeZone;Ljava/util/Locale;Z)V", nullptr, 0, $method(GregorianCalendar, init$, void, $TimeZone*, $Locale*, bool)},
	{"actualMonthLength", "()I", nullptr, $PRIVATE, $method(GregorianCalendar, actualMonthLength, int32_t)},
	{"add", "(II)V", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, add, void, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, clone, $Object*)},
	{"computeFields", "()V", nullptr, $PROTECTED, $virtualMethod(GregorianCalendar, computeFields, void)},
	{"computeFields", "(II)I", nullptr, $PRIVATE, $method(GregorianCalendar, computeFields, int32_t, int32_t, int32_t)},
	{"computeTime", "()V", nullptr, $PROTECTED, $virtualMethod(GregorianCalendar, computeTime, void)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, equals, bool, Object$*)},
	{"from", "(Ljava/time/ZonedDateTime;)Ljava/util/GregorianCalendar;", nullptr, $PUBLIC | $STATIC, $staticMethod(GregorianCalendar, from, GregorianCalendar*, $ZonedDateTime*)},
	{"getActualMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getActualMaximum, int32_t, int32_t)},
	{"getActualMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getActualMinimum, int32_t, int32_t)},
	{"getCalendarDate", "(J)Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE, $method(GregorianCalendar, getCalendarDate, $BaseCalendar$Date*, int64_t)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getCalendarType, $String*)},
	{"getCurrentFixedDate", "()J", nullptr, $PRIVATE, $method(GregorianCalendar, getCurrentFixedDate, int64_t)},
	{"getCutoverCalendarSystem", "()Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE, $method(GregorianCalendar, getCutoverCalendarSystem, $BaseCalendar*)},
	{"getFixedDate", "(Lsun/util/calendar/BaseCalendar;II)J", nullptr, $PRIVATE, $method(GregorianCalendar, getFixedDate, int64_t, $BaseCalendar*, int32_t, int32_t)},
	{"getFixedDateJan1", "(Lsun/util/calendar/BaseCalendar$Date;J)J", nullptr, $PRIVATE, $method(GregorianCalendar, getFixedDateJan1, int64_t, $BaseCalendar$Date*, int64_t)},
	{"getFixedDateMonth1", "(Lsun/util/calendar/BaseCalendar$Date;J)J", nullptr, $PRIVATE, $method(GregorianCalendar, getFixedDateMonth1, int64_t, $BaseCalendar$Date*, int64_t)},
	{"getGreatestMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getGreatestMinimum, int32_t, int32_t)},
	{"getGregorianChange", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(GregorianCalendar, getGregorianChange, $Date*)},
	{"getGregorianCutoverDate", "()Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE, $method(GregorianCalendar, getGregorianCutoverDate, $BaseCalendar$Date*)},
	{"getJulianCalendarSystem", "()Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(GregorianCalendar, getJulianCalendarSystem, $BaseCalendar*)},
	{"getLastJulianDate", "()Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE, $method(GregorianCalendar, getLastJulianDate, $BaseCalendar$Date*)},
	{"getLeastMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getLeastMaximum, int32_t, int32_t)},
	{"getMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getMaximum, int32_t, int32_t)},
	{"getMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getMinimum, int32_t, int32_t)},
	{"getNormalizedCalendar", "()Ljava/util/GregorianCalendar;", nullptr, $PRIVATE, $method(GregorianCalendar, getNormalizedCalendar, GregorianCalendar*)},
	{"getRolledValue", "(IIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(GregorianCalendar, getRolledValue, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"getTimeZone", "()Ljava/util/TimeZone;", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getTimeZone, $TimeZone*)},
	{"getWeekNumber", "(JJ)I", nullptr, $PRIVATE, $method(GregorianCalendar, getWeekNumber, int32_t, int64_t, int64_t)},
	{"getWeekYear", "()I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getWeekYear, int32_t)},
	{"getWeeksInWeekYear", "()I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, getWeeksInWeekYear, int32_t)},
	{"getYearOffsetInMillis", "()J", nullptr, $PRIVATE, $method(GregorianCalendar, getYearOffsetInMillis, int64_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, hashCode, int32_t)},
	{"internalGetEra", "()I", nullptr, $PRIVATE, $method(GregorianCalendar, internalGetEra, int32_t)},
	{"isCutoverYear", "(I)Z", nullptr, $PRIVATE, $method(GregorianCalendar, isCutoverYear, bool, int32_t)},
	{"isLeapYear", "(I)Z", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, isLeapYear, bool, int32_t)},
	{"isWeekDateSupported", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(GregorianCalendar, isWeekDateSupported, bool)},
	{"monthLength", "(II)I", nullptr, $PRIVATE, $method(GregorianCalendar, monthLength, int32_t, int32_t, int32_t)},
	{"monthLength", "(I)I", nullptr, $PRIVATE, $method(GregorianCalendar, monthLength, int32_t, int32_t)},
	{"pinDayOfMonth", "()V", nullptr, $PRIVATE, $method(GregorianCalendar, pinDayOfMonth, void)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(GregorianCalendar, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"roll", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, roll, void, int32_t, bool)},
	{"roll", "(II)V", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, roll, void, int32_t, int32_t)},
	{"setGregorianChange", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, setGregorianChange, void, $Date*)},
	{"setGregorianChange", "(J)V", nullptr, $PRIVATE, $method(GregorianCalendar, setGregorianChange, void, int64_t)},
	{"setTimeZone", "(Ljava/util/TimeZone;)V", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, setTimeZone, void, $TimeZone*)},
	{"setWeekDate", "(III)V", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, setWeekDate, void, int32_t, int32_t, int32_t)},
	{"toZonedDateTime", "()Ljava/time/ZonedDateTime;", nullptr, $PUBLIC, $virtualMethod(GregorianCalendar, toZonedDateTime, $ZonedDateTime*)},
	{"yearLength", "(I)I", nullptr, $PRIVATE, $method(GregorianCalendar, yearLength, int32_t, int32_t)},
	{"yearLength", "()I", nullptr, $PRIVATE, $method(GregorianCalendar, yearLength, int32_t)},
	{}
};

$ClassInfo _GregorianCalendar_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.GregorianCalendar",
	"java.util.Calendar",
	nullptr,
	_GregorianCalendar_FieldInfo_,
	_GregorianCalendar_MethodInfo_
};

$Object* allocate$GregorianCalendar($Class* clazz) {
	return $of($alloc(GregorianCalendar));
}

bool GregorianCalendar::$assertionsDisabled = false;
$ints* GregorianCalendar::MONTH_LENGTH = nullptr;
$ints* GregorianCalendar::LEAP_MONTH_LENGTH = nullptr;
$ints* GregorianCalendar::MIN_VALUES = nullptr;
$ints* GregorianCalendar::LEAST_MAX_VALUES = nullptr;
$ints* GregorianCalendar::MAX_VALUES = nullptr;
$Gregorian* GregorianCalendar::gcal = nullptr;
$JulianCalendar* GregorianCalendar::jcal = nullptr;
$EraArray* GregorianCalendar::jeras = nullptr;

void GregorianCalendar::init$() {
	$useLocalCurrentObjectStackCache();
	$var($TimeZone, var$0, $TimeZone::getDefaultRef());
	$init($Locale$Category);
	GregorianCalendar::init$(var$0, $($Locale::getDefault($Locale$Category::FORMAT)));
	setZoneShared(true);
}

void GregorianCalendar::init$($TimeZone* zone) {
	$init($Locale$Category);
	GregorianCalendar::init$(zone, $($Locale::getDefault($Locale$Category::FORMAT)));
}

void GregorianCalendar::init$($Locale* aLocale) {
	GregorianCalendar::init$($($TimeZone::getDefaultRef()), aLocale);
	setZoneShared(true);
}

void GregorianCalendar::init$($TimeZone* zone, $Locale* aLocale) {
	$Calendar::init$(zone, aLocale);
	this->gregorianCutover = GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER;
	this->gregorianCutoverDate = (($div((GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER + 1), GregorianCalendar::ONE_DAY)) - 1) + GregorianCalendar::EPOCH_OFFSET;
	this->gregorianCutoverYear = 1582;
	this->gregorianCutoverYearJulian = 1582;
	this->cachedFixedDate = $Long::MIN_VALUE;
	$set(this, gdate, static_cast<$BaseCalendar$Date*>($cast($Gregorian$Date, $nc(GregorianCalendar::gcal)->newCalendarDate(zone))));
	setTimeInMillis($System::currentTimeMillis());
}

void GregorianCalendar::init$(int32_t year, int32_t month, int32_t dayOfMonth) {
	GregorianCalendar::init$(year, month, dayOfMonth, 0, 0, 0, 0);
}

void GregorianCalendar::init$(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hourOfDay, int32_t minute) {
	GregorianCalendar::init$(year, month, dayOfMonth, hourOfDay, minute, 0, 0);
}

void GregorianCalendar::init$(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hourOfDay, int32_t minute, int32_t second) {
	GregorianCalendar::init$(year, month, dayOfMonth, hourOfDay, minute, second, 0);
}

void GregorianCalendar::init$(int32_t year, int32_t month, int32_t dayOfMonth, int32_t hourOfDay, int32_t minute, int32_t second, int32_t millis) {
	$Calendar::init$();
	this->gregorianCutover = GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER;
	this->gregorianCutoverDate = (($div((GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER + 1), GregorianCalendar::ONE_DAY)) - 1) + GregorianCalendar::EPOCH_OFFSET;
	this->gregorianCutoverYear = 1582;
	this->gregorianCutoverYearJulian = 1582;
	this->cachedFixedDate = $Long::MIN_VALUE;
	$set(this, gdate, static_cast<$BaseCalendar$Date*>($cast($Gregorian$Date, $nc(GregorianCalendar::gcal)->newCalendarDate($(getZone())))));
	this->set($Calendar::YEAR, year);
	this->set($Calendar::MONTH, month);
	this->set($Calendar::DAY_OF_MONTH, dayOfMonth);
	if (hourOfDay >= 12 && hourOfDay <= 23) {
		this->internalSet($Calendar::AM_PM, $Calendar::PM);
		this->internalSet($Calendar::HOUR, hourOfDay - 12);
	} else {
		this->internalSet($Calendar::HOUR, hourOfDay);
	}
	setFieldsComputed($Calendar::HOUR_MASK | $Calendar::AM_PM_MASK);
	this->set($Calendar::HOUR_OF_DAY, hourOfDay);
	this->set($Calendar::MINUTE, minute);
	this->set($Calendar::SECOND, second);
	this->internalSet($Calendar::MILLISECOND, millis);
}

void GregorianCalendar::init$($TimeZone* zone, $Locale* locale, bool flag) {
	$Calendar::init$(zone, locale);
	this->gregorianCutover = GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER;
	this->gregorianCutoverDate = (($div((GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER + 1), GregorianCalendar::ONE_DAY)) - 1) + GregorianCalendar::EPOCH_OFFSET;
	this->gregorianCutoverYear = 1582;
	this->gregorianCutoverYearJulian = 1582;
	this->cachedFixedDate = $Long::MIN_VALUE;
	$set(this, gdate, static_cast<$BaseCalendar$Date*>($cast($Gregorian$Date, $nc(GregorianCalendar::gcal)->newCalendarDate($(getZone())))));
}

void GregorianCalendar::setGregorianChange($Date* date) {
	int64_t cutoverTime = $nc(date)->getTime();
	if (cutoverTime == this->gregorianCutover) {
		return;
	}
	complete();
	setGregorianChange(cutoverTime);
}

void GregorianCalendar::setGregorianChange(int64_t cutoverTime) {
	$useLocalCurrentObjectStackCache();
	this->gregorianCutover = cutoverTime;
	this->gregorianCutoverDate = $CalendarUtils::floorDivide(cutoverTime, GregorianCalendar::ONE_DAY) + GregorianCalendar::EPOCH_OFFSET;
	if (cutoverTime == $Long::MAX_VALUE) {
		++this->gregorianCutoverDate;
	}
	$var($BaseCalendar$Date, d, getGregorianCutoverDate());
	this->gregorianCutoverYear = $nc(d)->getYear();
	$var($BaseCalendar, julianCal, getJulianCalendarSystem());
	$init($TimeZone);
	$assign(d, $cast($BaseCalendar$Date, $nc(julianCal)->newCalendarDate($TimeZone::NO_TIMEZONE)));
	julianCal->getCalendarDateFromFixedDate(d, this->gregorianCutoverDate - 1);
	this->gregorianCutoverYearJulian = d->getNormalizedYear();
	if (this->time < this->gregorianCutover) {
		setUnnormalized();
	}
}

$Date* GregorianCalendar::getGregorianChange() {
	return $new($Date, this->gregorianCutover);
}

bool GregorianCalendar::isLeapYear(int32_t year) {
	if (((int32_t)(year & (uint32_t)3)) != 0) {
		return false;
	}
	if (year > this->gregorianCutoverYear) {
		return (year % 100 != 0) || (year % 400 == 0);
	}
	if (year < this->gregorianCutoverYearJulian) {
		return true;
	}
	bool gregorian = false;
	if (this->gregorianCutoverYear == this->gregorianCutoverYearJulian) {
		$var($BaseCalendar$Date, d, getCalendarDate(this->gregorianCutoverDate));
		gregorian = $nc(d)->getMonth() < $BaseCalendar::MARCH;
	} else {
		gregorian = year == this->gregorianCutoverYear;
	}
	return gregorian ? (year % 100 != 0) || (year % 400 == 0) : true;
}

$String* GregorianCalendar::getCalendarType() {
	return "gregory"_s;
}

bool GregorianCalendar::equals(Object$* obj) {
	return $instanceOf(GregorianCalendar, obj) && $Calendar::equals(obj) && this->gregorianCutover == $nc(($cast(GregorianCalendar, obj)))->gregorianCutover;
}

int32_t GregorianCalendar::hashCode() {
	return $Calendar::hashCode() ^ (int32_t)this->gregorianCutoverDate;
}

void GregorianCalendar::add(int32_t field, int32_t amount) {
	if (amount == 0) {
		return;
	}
	if (field < 0 || field >= $Calendar::ZONE_OFFSET) {
		$throwNew($IllegalArgumentException);
	}
	complete();
	if (field == $Calendar::YEAR) {
		int32_t year = internalGet($Calendar::YEAR);
		if (internalGetEra() == GregorianCalendar::CE) {
			year += amount;
			if (year > 0) {
				set($Calendar::YEAR, year);
			} else {
				set($Calendar::YEAR, 1 - year);
				set($Calendar::ERA, GregorianCalendar::BCE);
			}
		} else {
			year -= amount;
			if (year > 0) {
				set($Calendar::YEAR, year);
			} else {
				set($Calendar::YEAR, 1 - year);
				set($Calendar::ERA, GregorianCalendar::CE);
			}
		}
		pinDayOfMonth();
	} else if (field == $Calendar::MONTH) {
		int32_t month = internalGet($Calendar::MONTH) + amount;
		int32_t year = internalGet($Calendar::YEAR);
		int32_t y_amount = 0;
		if (month >= 0) {
			y_amount = month / 12;
		} else {
			y_amount = (month + 1) / 12 - 1;
		}
		if (y_amount != 0) {
			if (internalGetEra() == GregorianCalendar::CE) {
				year += y_amount;
				if (year > 0) {
					set($Calendar::YEAR, year);
				} else {
					set($Calendar::YEAR, 1 - year);
					set($Calendar::ERA, GregorianCalendar::BCE);
				}
			} else {
				year -= y_amount;
				if (year > 0) {
					set($Calendar::YEAR, year);
				} else {
					set($Calendar::YEAR, 1 - year);
					set($Calendar::ERA, GregorianCalendar::CE);
				}
			}
		}
		if (month >= 0) {
			set($Calendar::MONTH, month % 12);
		} else {
			$modAssign(month, 12);
			if (month < 0) {
				month += 12;
			}
			set($Calendar::MONTH, $Calendar::JANUARY + month);
		}
		pinDayOfMonth();
	} else if (field == $Calendar::ERA) {
		int32_t era = internalGet($Calendar::ERA) + amount;
		if (era < 0) {
			era = 0;
		}
		if (era > 1) {
			era = 1;
		}
		set($Calendar::ERA, era);
	} else {
		int64_t delta = amount;
		int64_t timeOfDay = 0;
		switch (field) {
		case $Calendar::HOUR:
			{}
		case $Calendar::HOUR_OF_DAY:
			{
				delta *= 60 * 60 * 1000;
				break;
			}
		case $Calendar::MINUTE:
			{
				delta *= 60 * 1000;
				break;
			}
		case $Calendar::SECOND:
			{
				delta *= 1000;
				break;
			}
		case $Calendar::MILLISECOND:
			{
				break;
			}
		case $Calendar::WEEK_OF_YEAR:
			{}
		case $Calendar::WEEK_OF_MONTH:
			{}
		case $Calendar::DAY_OF_WEEK_IN_MONTH:
			{
				delta *= 7;
				break;
			}
		case $Calendar::DAY_OF_MONTH:
			{}
		case $Calendar::DAY_OF_YEAR:
			{}
		case $Calendar::DAY_OF_WEEK:
			{
				break;
			}
		case $Calendar::AM_PM:
			{
				delta = amount / 2;
				timeOfDay = 12 * (amount % 2);
				break;
			}
		}
		if (field >= $Calendar::HOUR) {
			setTimeInMillis(this->time + delta);
			return;
		}
		int64_t fd = getCurrentFixedDate();
		timeOfDay += internalGet($Calendar::HOUR_OF_DAY);
		timeOfDay *= 60;
		timeOfDay += internalGet($Calendar::MINUTE);
		timeOfDay *= 60;
		timeOfDay += internalGet($Calendar::SECOND);
		timeOfDay *= 1000;
		timeOfDay += internalGet($Calendar::MILLISECOND);
		if (timeOfDay >= GregorianCalendar::ONE_DAY) {
			++fd;
			timeOfDay -= GregorianCalendar::ONE_DAY;
		} else if (timeOfDay < 0) {
			--fd;
			timeOfDay += GregorianCalendar::ONE_DAY;
		}
		fd += delta;
		int32_t var$0 = internalGet($Calendar::ZONE_OFFSET);
		int32_t zoneOffset = var$0 + internalGet($Calendar::DST_OFFSET);
		setTimeInMillis((fd - GregorianCalendar::EPOCH_OFFSET) * GregorianCalendar::ONE_DAY + timeOfDay - zoneOffset);
		int32_t var$1 = internalGet($Calendar::ZONE_OFFSET);
		zoneOffset -= var$1 + internalGet($Calendar::DST_OFFSET);
		if (zoneOffset != 0) {
			setTimeInMillis(this->time + zoneOffset);
			int64_t fd2 = getCurrentFixedDate();
			if (fd2 != fd) {
				setTimeInMillis(this->time - zoneOffset);
			}
		}
	}
}

void GregorianCalendar::roll(int32_t field, bool up) {
	roll(field, up ? +1 : -1);
}

void GregorianCalendar::roll(int32_t field, int32_t amount) {
	$useLocalCurrentObjectStackCache();
	if (amount == 0) {
		return;
	}
	if (field < 0 || field >= $Calendar::ZONE_OFFSET) {
		$throwNew($IllegalArgumentException);
	}
	complete();
	int32_t min = getMinimum(field);
	int32_t max = getMaximum(field);
	switch (field) {
	case $Calendar::AM_PM:
		{}
	case $Calendar::ERA:
		{}
	case $Calendar::YEAR:
		{}
	case $Calendar::MINUTE:
		{}
	case $Calendar::SECOND:
		{}
	case $Calendar::MILLISECOND:
		{
			break;
		}
	case $Calendar::HOUR:
		{}
	case $Calendar::HOUR_OF_DAY:
		{
			{
				int32_t rolledValue = getRolledValue(internalGet(field), amount, min, max);
				int32_t hourOfDay = rolledValue;
				if (field == $Calendar::HOUR && internalGet($Calendar::AM_PM) == $Calendar::PM) {
					hourOfDay += 12;
				}
				$var($CalendarDate, d, $nc(this->calsys)->getCalendarDate(this->time, $(getZone())));
				$nc(d)->setHours(hourOfDay);
				this->time = $nc(this->calsys)->getTime(d);
				int32_t var$0 = internalGet($Calendar::HOUR_OF_DAY);
				if (var$0 == d->getHours()) {
					hourOfDay = getRolledValue(rolledValue, amount > 0 ? +1 : -1, min, max);
					if (field == $Calendar::HOUR && internalGet($Calendar::AM_PM) == $Calendar::PM) {
						hourOfDay += 12;
					}
					d->setHours(hourOfDay);
					this->time = $nc(this->calsys)->getTime(d);
				}
				hourOfDay = d->getHours();
				internalSet($Calendar::HOUR_OF_DAY, hourOfDay);
				internalSet($Calendar::AM_PM, hourOfDay / 12);
				internalSet($Calendar::HOUR, hourOfDay % 12);
				int32_t zoneOffset = d->getZoneOffset();
				int32_t saving = d->getDaylightSaving();
				internalSet($Calendar::ZONE_OFFSET, zoneOffset - saving);
				internalSet($Calendar::DST_OFFSET, saving);
				return;
			}
		}
	case $Calendar::MONTH:
		{
			{
				if (!this->isCutoverYear($nc(this->cdate)->getNormalizedYear())) {
					int32_t mon = (internalGet($Calendar::MONTH) + amount) % 12;
					if (mon < 0) {
						mon += 12;
					}
					set($Calendar::MONTH, mon);
					int32_t monthLen = this->monthLength(mon);
					if (internalGet($Calendar::DAY_OF_MONTH) > monthLen) {
						set($Calendar::DAY_OF_MONTH, monthLen);
					}
				} else {
					int32_t yearLength = getActualMaximum($Calendar::MONTH) + 1;
					int32_t mon = $mod((internalGet($Calendar::MONTH) + amount), yearLength);
					if (mon < 0) {
						mon += yearLength;
					}
					set($Calendar::MONTH, mon);
					int32_t monthLen = getActualMaximum($Calendar::DAY_OF_MONTH);
					if (internalGet($Calendar::DAY_OF_MONTH) > monthLen) {
						set($Calendar::DAY_OF_MONTH, monthLen);
					}
				}
				return;
			}
		}
	case $Calendar::WEEK_OF_YEAR:
		{
			{
				int32_t y = $nc(this->cdate)->getNormalizedYear();
				max = getActualMaximum($Calendar::WEEK_OF_YEAR);
				set($Calendar::DAY_OF_WEEK, internalGet($Calendar::DAY_OF_WEEK));
				int32_t woy = internalGet($Calendar::WEEK_OF_YEAR);
				int32_t value = woy + amount;
				if (!this->isCutoverYear(y)) {
					int32_t weekYear = getWeekYear();
					if (weekYear == y) {
						if (value > min && value < max) {
							set($Calendar::WEEK_OF_YEAR, value);
							return;
						}
						int64_t fd = getCurrentFixedDate();
						int64_t day1 = fd - (7 * (woy - min));
						if ($nc(this->calsys)->getYearFromFixedDate(day1) != y) {
							++min;
						}
						fd += 7 * (max - internalGet($Calendar::WEEK_OF_YEAR));
						if ($nc(this->calsys)->getYearFromFixedDate(fd) != y) {
							--max;
						}
					} else if (weekYear > y) {
						if (amount < 0) {
							++amount;
						}
						woy = max;
					} else {
						if (amount > 0) {
							amount -= woy - max;
						}
						woy = min;
					}
					set(field, getRolledValue(woy, amount, min, max));
					return;
				}
				int64_t fd = getCurrentFixedDate();
				$var($BaseCalendar, cal, nullptr);
				if (this->gregorianCutoverYear == this->gregorianCutoverYearJulian) {
					$assign(cal, getCutoverCalendarSystem());
				} else if (y == this->gregorianCutoverYear) {
					$assign(cal, GregorianCalendar::gcal);
				} else {
					$assign(cal, getJulianCalendarSystem());
				}
				int64_t day1 = fd - (7 * (woy - min));
				if ($nc(cal)->getYearFromFixedDate(day1) != y) {
					++min;
				}
				fd += 7 * (max - woy);
				$assign(cal, (fd >= this->gregorianCutoverDate) ? static_cast<$BaseCalendar*>(GregorianCalendar::gcal) : getJulianCalendarSystem());
				if ($nc(cal)->getYearFromFixedDate(fd) != y) {
					--max;
				}
				value = getRolledValue(woy, amount, min, max) - 1;
				$var($BaseCalendar$Date, d, getCalendarDate(day1 + value * 7));
				set($Calendar::MONTH, $nc(d)->getMonth() - 1);
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	case $Calendar::WEEK_OF_MONTH:
		{
			{
				bool isCutoverYear = this->isCutoverYear($nc(this->cdate)->getNormalizedYear());
				int32_t var$1 = internalGet($Calendar::DAY_OF_WEEK);
				int32_t dow = var$1 - getFirstDayOfWeek();
				if (dow < 0) {
					dow += 7;
				}
				int64_t fd = getCurrentFixedDate();
				int64_t month1 = 0;
				int32_t monthLength = 0;
				if (isCutoverYear) {
					month1 = getFixedDateMonth1(this->cdate, fd);
					monthLength = actualMonthLength();
				} else {
					month1 = fd - internalGet($Calendar::DAY_OF_MONTH) + 1;
					monthLength = $nc(this->calsys)->getMonthLength(this->cdate);
				}
				int64_t monthDay1st = $BaseCalendar::getDayOfWeekDateOnOrBefore(month1 + 6, getFirstDayOfWeek());
				if ((int32_t)(monthDay1st - month1) >= getMinimalDaysInFirstWeek()) {
					monthDay1st -= 7;
				}
				max = getActualMaximum(field);
				int32_t value = getRolledValue(internalGet(field), amount, 1, max) - 1;
				int64_t nfd = monthDay1st + value * 7 + dow;
				if (nfd < month1) {
					nfd = month1;
				} else if (nfd >= (month1 + monthLength)) {
					nfd = month1 + monthLength - 1;
				}
				int32_t dayOfMonth = 0;
				if (isCutoverYear) {
					$var($BaseCalendar$Date, d, getCalendarDate(nfd));
					dayOfMonth = $nc(d)->getDayOfMonth();
				} else {
					dayOfMonth = (int32_t)(nfd - month1) + 1;
				}
				set($Calendar::DAY_OF_MONTH, dayOfMonth);
				return;
			}
		}
	case $Calendar::DAY_OF_MONTH:
		{
			{
				if (!this->isCutoverYear($nc(this->cdate)->getNormalizedYear())) {
					max = $nc(this->calsys)->getMonthLength(this->cdate);
					break;
				}
				int64_t fd = getCurrentFixedDate();
				int64_t month1 = getFixedDateMonth1(this->cdate, fd);
				int32_t value = getRolledValue((int32_t)(fd - month1), amount, 0, actualMonthLength() - 1);
				$var($BaseCalendar$Date, d, getCalendarDate(month1 + value));
				bool var$2 = !GregorianCalendar::$assertionsDisabled;
				if (var$2) {
					int32_t var$3 = $nc(d)->getMonth() - 1;
					var$2 = !(var$3 == internalGet($Calendar::MONTH));
				}
				if (var$2) {
					$throwNew($AssertionError);
				}
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	case $Calendar::DAY_OF_YEAR:
		{
			{
				max = getActualMaximum(field);
				if (!this->isCutoverYear($nc(this->cdate)->getNormalizedYear())) {
					break;
				}
				int64_t fd = getCurrentFixedDate();
				int64_t jan1 = fd - internalGet($Calendar::DAY_OF_YEAR) + 1;
				int32_t value = getRolledValue((int32_t)(fd - jan1) + 1, amount, min, max);
				$var($BaseCalendar$Date, d, getCalendarDate(jan1 + value - 1));
				set($Calendar::MONTH, $nc(d)->getMonth() - 1);
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	case $Calendar::DAY_OF_WEEK:
		{
			{
				if (!this->isCutoverYear($nc(this->cdate)->getNormalizedYear())) {
					int32_t weekOfYear = internalGet($Calendar::WEEK_OF_YEAR);
					if (weekOfYear > 1 && weekOfYear < 52) {
						set($Calendar::WEEK_OF_YEAR, weekOfYear);
						max = $Calendar::SATURDAY;
						break;
					}
				}
				$modAssign(amount, 7);
				if (amount == 0) {
					return;
				}
				int64_t fd = getCurrentFixedDate();
				int64_t dowFirst = $BaseCalendar::getDayOfWeekDateOnOrBefore(fd, getFirstDayOfWeek());
				fd += amount;
				if (fd < dowFirst) {
					fd += 7;
				} else if (fd >= dowFirst + 7) {
					fd -= 7;
				}
				$var($BaseCalendar$Date, d, getCalendarDate(fd));
				set($Calendar::ERA, ($nc(d)->getNormalizedYear() <= 0 ? GregorianCalendar::BCE : GregorianCalendar::CE));
				int32_t var$4 = $nc(d)->getYear();
				int32_t var$5 = d->getMonth() - 1;
				set(var$4, var$5, d->getDayOfMonth());
				return;
			}
		}
	case $Calendar::DAY_OF_WEEK_IN_MONTH:
		{
			{
				min = 1;
				if (!this->isCutoverYear($nc(this->cdate)->getNormalizedYear())) {
					int32_t dom = internalGet($Calendar::DAY_OF_MONTH);
					int32_t monthLength = $nc(this->calsys)->getMonthLength(this->cdate);
					int32_t lastDays = monthLength % 7;
					max = monthLength / 7;
					int32_t x = (dom - 1) % 7;
					if (x < lastDays) {
						++max;
					}
					set($Calendar::DAY_OF_WEEK, internalGet($Calendar::DAY_OF_WEEK));
					break;
				}
				int64_t fd = getCurrentFixedDate();
				int64_t month1 = getFixedDateMonth1(this->cdate, fd);
				int32_t monthLength = actualMonthLength();
				int32_t lastDays = monthLength % 7;
				max = monthLength / 7;
				int32_t x = (int32_t)(fd - month1) % 7;
				if (x < lastDays) {
					++max;
				}
				int32_t value = getRolledValue(internalGet(field), amount, min, max) - 1;
				fd = month1 + value * 7 + x;
				$var($BaseCalendar, cal, (fd >= this->gregorianCutoverDate) ? static_cast<$BaseCalendar*>(GregorianCalendar::gcal) : getJulianCalendarSystem());
				$init($TimeZone);
				$var($BaseCalendar$Date, d, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate($TimeZone::NO_TIMEZONE)));
				cal->getCalendarDateFromFixedDate(d, fd);
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	}
	set(field, getRolledValue(internalGet(field), amount, min, max));
}

int32_t GregorianCalendar::getMinimum(int32_t field) {
	return $nc(GregorianCalendar::MIN_VALUES)->get(field);
}

int32_t GregorianCalendar::getMaximum(int32_t field) {
	switch (field) {
	case $Calendar::MONTH:
		{}
	case $Calendar::DAY_OF_MONTH:
		{}
	case $Calendar::DAY_OF_YEAR:
		{}
	case $Calendar::WEEK_OF_YEAR:
		{}
	case $Calendar::WEEK_OF_MONTH:
		{}
	case $Calendar::DAY_OF_WEEK_IN_MONTH:
		{}
	case $Calendar::YEAR:
		{
			{
				if (this->gregorianCutoverYear > 200) {
					break;
				}
				$var(GregorianCalendar, gc, $cast(GregorianCalendar, clone()));
				$nc(gc)->setLenient(true);
				gc->setTimeInMillis(this->gregorianCutover);
				int32_t v1 = gc->getActualMaximum(field);
				gc->setTimeInMillis(this->gregorianCutover - 1);
				int32_t v2 = gc->getActualMaximum(field);
				return $Math::max($nc(GregorianCalendar::MAX_VALUES)->get(field), $Math::max(v1, v2));
			}
		}
	}
	return $nc(GregorianCalendar::MAX_VALUES)->get(field);
}

int32_t GregorianCalendar::getGreatestMinimum(int32_t field) {
	if (field == $Calendar::DAY_OF_MONTH) {
		$var($BaseCalendar$Date, d, getGregorianCutoverDate());
		int64_t mon1 = getFixedDateMonth1(d, this->gregorianCutoverDate);
		$assign(d, getCalendarDate(mon1));
		return $Math::max($nc(GregorianCalendar::MIN_VALUES)->get(field), $nc(d)->getDayOfMonth());
	}
	return $nc(GregorianCalendar::MIN_VALUES)->get(field);
}

int32_t GregorianCalendar::getLeastMaximum(int32_t field) {
	switch (field) {
	case $Calendar::MONTH:
		{}
	case $Calendar::DAY_OF_MONTH:
		{}
	case $Calendar::DAY_OF_YEAR:
		{}
	case $Calendar::WEEK_OF_YEAR:
		{}
	case $Calendar::WEEK_OF_MONTH:
		{}
	case $Calendar::DAY_OF_WEEK_IN_MONTH:
		{}
	case $Calendar::YEAR:
		{
			{
				$var(GregorianCalendar, gc, $cast(GregorianCalendar, clone()));
				$nc(gc)->setLenient(true);
				gc->setTimeInMillis(this->gregorianCutover);
				int32_t v1 = gc->getActualMaximum(field);
				gc->setTimeInMillis(this->gregorianCutover - 1);
				int32_t v2 = gc->getActualMaximum(field);
				return $Math::min($nc(GregorianCalendar::LEAST_MAX_VALUES)->get(field), $Math::min(v1, v2));
			}
		}
	}
	return $nc(GregorianCalendar::LEAST_MAX_VALUES)->get(field);
}

int32_t GregorianCalendar::getActualMinimum(int32_t field) {
	$useLocalCurrentObjectStackCache();
	if (field == $Calendar::DAY_OF_MONTH) {
		$var(GregorianCalendar, gc, getNormalizedCalendar());
		int32_t year = $nc($nc(gc)->cdate)->getNormalizedYear();
		if (year == this->gregorianCutoverYear || year == this->gregorianCutoverYearJulian) {
			int64_t month1 = getFixedDateMonth1(gc->cdate, $nc(gc->calsys)->getFixedDate(gc->cdate));
			$var($BaseCalendar$Date, d, getCalendarDate(month1));
			return $nc(d)->getDayOfMonth();
		}
	}
	return getMinimum(field);
}

int32_t GregorianCalendar::getActualMaximum(int32_t field) {
	$useLocalCurrentObjectStackCache();
	int32_t fieldsForFixedMax = (((((((($Calendar::ERA_MASK | $Calendar::DAY_OF_WEEK_MASK) | $Calendar::HOUR_MASK) | $Calendar::AM_PM_MASK) | $Calendar::HOUR_OF_DAY_MASK) | $Calendar::MINUTE_MASK) | $Calendar::SECOND_MASK) | $Calendar::MILLISECOND_MASK) | $Calendar::ZONE_OFFSET_MASK) | $Calendar::DST_OFFSET_MASK;
	if (((int32_t)(fieldsForFixedMax & (uint32_t)($sl(1, field)))) != 0) {
		return getMaximum(field);
	}
	$var(GregorianCalendar, gc, getNormalizedCalendar());
	$var($BaseCalendar$Date, date, $nc(gc)->cdate);
	$var($BaseCalendar, cal, gc->calsys);
	int32_t normalizedYear = $nc(date)->getNormalizedYear();
	int32_t value = -1;
	switch (field) {
	case $Calendar::MONTH:
		{
			{
				if (!gc->isCutoverYear(normalizedYear)) {
					value = $Calendar::DECEMBER;
					break;
				}
				int64_t nextJan1 = 0;
				do {
					nextJan1 = $nc(GregorianCalendar::gcal)->getFixedDate(++normalizedYear, $BaseCalendar::JANUARY, 1, nullptr);
				} while (nextJan1 < this->gregorianCutoverDate);
				$var($BaseCalendar$Date, d, $cast($BaseCalendar$Date, date->clone()));
				$nc(cal)->getCalendarDateFromFixedDate(d, nextJan1 - 1);
				value = $nc(d)->getMonth() - 1;
			}
			break;
		}
	case $Calendar::DAY_OF_MONTH:
		{
			{
				value = $nc(cal)->getMonthLength(date);
				bool var$0 = !gc->isCutoverYear(normalizedYear);
				if (var$0 || date->getDayOfMonth() == value) {
					break;
				}
				int64_t fd = gc->getCurrentFixedDate();
				if (fd >= this->gregorianCutoverDate) {
					break;
				}
				int32_t monthLength = gc->actualMonthLength();
				int64_t monthEnd = gc->getFixedDateMonth1(gc->cdate, fd) + monthLength - 1;
				$var($BaseCalendar$Date, d, gc->getCalendarDate(monthEnd));
				value = $nc(d)->getDayOfMonth();
			}
			break;
		}
	case $Calendar::DAY_OF_YEAR:
		{
			{
				if (!gc->isCutoverYear(normalizedYear)) {
					value = $nc(cal)->getYearLength(date);
					break;
				}
				int64_t jan1 = 0;
				if (this->gregorianCutoverYear == this->gregorianCutoverYearJulian) {
					$var($BaseCalendar, cocal, gc->getCutoverCalendarSystem());
					jan1 = $nc(cocal)->getFixedDate(normalizedYear, 1, 1, nullptr);
				} else if (normalizedYear == this->gregorianCutoverYearJulian) {
					jan1 = $nc(cal)->getFixedDate(normalizedYear, 1, 1, nullptr);
				} else {
					jan1 = this->gregorianCutoverDate;
				}
				int64_t nextJan1 = $nc(GregorianCalendar::gcal)->getFixedDate(++normalizedYear, 1, 1, nullptr);
				if (nextJan1 < this->gregorianCutoverDate) {
					nextJan1 = this->gregorianCutoverDate;
				}
				bool var$1 = !GregorianCalendar::$assertionsDisabled;
				if (var$1) {
					int64_t var$2 = jan1;
					int32_t var$4 = date->getNormalizedYear();
					int32_t var$5 = date->getMonth();
					int64_t var$3 = $nc(cal)->getFixedDate(var$4, var$5, date->getDayOfMonth(), date);
					var$1 = !(var$2 <= var$3);
				}
				if (var$1) {
					$throwNew($AssertionError);
				}
				bool var$6 = !GregorianCalendar::$assertionsDisabled;
				if (var$6) {
					int64_t var$7 = nextJan1;
					int32_t var$9 = date->getNormalizedYear();
					int32_t var$10 = date->getMonth();
					int64_t var$8 = $nc(cal)->getFixedDate(var$9, var$10, date->getDayOfMonth(), date);
					var$6 = !(var$7 >= var$8);
				}
				if (var$6) {
					$throwNew($AssertionError);
				}
				value = (int32_t)(nextJan1 - jan1);
			}
			break;
		}
	case $Calendar::WEEK_OF_YEAR:
		{
			{
				if (!gc->isCutoverYear(normalizedYear)) {
					$init($TimeZone);
					$var($CalendarDate, d, $nc(cal)->newCalendarDate($TimeZone::NO_TIMEZONE));
					$nc(d)->setDate(date->getYear(), $BaseCalendar::JANUARY, 1);
					int32_t dayOfWeek = cal->getDayOfWeek(d);
					dayOfWeek -= getFirstDayOfWeek();
					if (dayOfWeek < 0) {
						dayOfWeek += 7;
					}
					value = 52;
					int32_t magic = dayOfWeek + getMinimalDaysInFirstWeek() - 1;
					if ((magic == 6) || (date->isLeapYear() && (magic == 5 || magic == 12))) {
						++value;
					}
					break;
				}
				if (gc == this) {
					$assign(gc, $cast(GregorianCalendar, gc->clone()));
				}
				int32_t maxDayOfYear = getActualMaximum($Calendar::DAY_OF_YEAR);
				gc->set($Calendar::DAY_OF_YEAR, maxDayOfYear);
				value = gc->get($Calendar::WEEK_OF_YEAR);
				int32_t var$11 = internalGet($Calendar::YEAR);
				if (var$11 != gc->getWeekYear()) {
					gc->set($Calendar::DAY_OF_YEAR, maxDayOfYear - 7);
					value = gc->get($Calendar::WEEK_OF_YEAR);
				}
			}
			break;
		}
	case $Calendar::WEEK_OF_MONTH:
		{
			{
				if (!gc->isCutoverYear(normalizedYear)) {
					$var($CalendarDate, d, $nc(cal)->newCalendarDate(nullptr));
					int32_t var$12 = date->getYear();
					$nc(d)->setDate(var$12, date->getMonth(), 1);
					int32_t dayOfWeek = cal->getDayOfWeek(d);
					int32_t monthLength = cal->getMonthLength(d);
					dayOfWeek -= getFirstDayOfWeek();
					if (dayOfWeek < 0) {
						dayOfWeek += 7;
					}
					int32_t nDaysFirstWeek = 7 - dayOfWeek;
					value = 3;
					if (nDaysFirstWeek >= getMinimalDaysInFirstWeek()) {
						++value;
					}
					monthLength -= nDaysFirstWeek + 7 * 3;
					if (monthLength > 0) {
						++value;
						if (monthLength > 7) {
							++value;
						}
					}
					break;
				}
				if (gc == this) {
					$assign(gc, $cast(GregorianCalendar, gc->clone()));
				}
				int32_t y = gc->internalGet($Calendar::YEAR);
				int32_t m = gc->internalGet($Calendar::MONTH);
				bool var$13 = false;
				do {
					value = gc->get($Calendar::WEEK_OF_MONTH);
					gc->add($Calendar::WEEK_OF_MONTH, +1);
					var$13 = gc->get($Calendar::YEAR) == y;
				} while (var$13 && gc->get($Calendar::MONTH) == m);
			}
			break;
		}
	case $Calendar::DAY_OF_WEEK_IN_MONTH:
		{
			{
				int32_t ndays = 0;
				int32_t dow1 = 0;
				int32_t dow = date->getDayOfWeek();
				if (!gc->isCutoverYear(normalizedYear)) {
					$var($BaseCalendar$Date, d, $cast($BaseCalendar$Date, date->clone()));
					ndays = $nc(cal)->getMonthLength(d);
					$nc(d)->setDayOfMonth(1);
					cal->normalize(d);
					dow1 = d->getDayOfWeek();
				} else {
					if (gc == this) {
						$assign(gc, $cast(GregorianCalendar, clone()));
					}
					ndays = gc->actualMonthLength();
					gc->set($Calendar::DAY_OF_MONTH, gc->getActualMinimum($Calendar::DAY_OF_MONTH));
					dow1 = gc->get($Calendar::DAY_OF_WEEK);
				}
				int32_t x = dow - dow1;
				if (x < 0) {
					x += 7;
				}
				ndays -= x;
				value = (ndays + 6) / 7;
			}
			break;
		}
	case $Calendar::YEAR:
		{
			{
				if (gc == this) {
					$assign(gc, $cast(GregorianCalendar, clone()));
				}
				int64_t current = gc->getYearOffsetInMillis();
				if (gc->internalGetEra() == GregorianCalendar::CE) {
					gc->setTimeInMillis($Long::MAX_VALUE);
					value = gc->get($Calendar::YEAR);
					int64_t maxEnd = gc->getYearOffsetInMillis();
					if (current > maxEnd) {
						--value;
					}
				} else {
					$var($CalendarSystem, mincal, gc->getTimeInMillis() >= this->gregorianCutover ? static_cast<$CalendarSystem*>(GregorianCalendar::gcal) : static_cast<$CalendarSystem*>(getJulianCalendarSystem()));
					$var($CalendarDate, d, $nc(mincal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
					int64_t var$14 = ($nc(cal)->getDayOfYear(d) - 1) * 24;
					int64_t maxEnd = var$14 + $nc(d)->getHours();
					maxEnd *= 60;
					maxEnd += d->getMinutes();
					maxEnd *= 60;
					maxEnd += d->getSeconds();
					maxEnd *= 1000;
					maxEnd += d->getMillis();
					value = d->getYear();
					if (value <= 0) {
						if (!GregorianCalendar::$assertionsDisabled && !$equals(mincal, GregorianCalendar::gcal)) {
							$throwNew($AssertionError);
						}
						value = 1 - value;
					}
					if (current < maxEnd) {
						--value;
					}
				}
			}
			break;
		}
	default:
		{
			$throwNew($ArrayIndexOutOfBoundsException, field);
		}
	}
	return value;
}

int64_t GregorianCalendar::getYearOffsetInMillis() {
	int64_t t = (internalGet($Calendar::DAY_OF_YEAR) - 1) * 24;
	t += internalGet($Calendar::HOUR_OF_DAY);
	t *= 60;
	t += internalGet($Calendar::MINUTE);
	t *= 60;
	t += internalGet($Calendar::SECOND);
	t *= 1000;
	int64_t var$0 = t + internalGet($Calendar::MILLISECOND);
	int32_t var$2 = internalGet($Calendar::ZONE_OFFSET);
	int32_t var$1 = (var$2 + internalGet($Calendar::DST_OFFSET));
	return var$0 - var$1;
}

$Object* GregorianCalendar::clone() {
	$var(GregorianCalendar, other, $cast(GregorianCalendar, $Calendar::clone()));
	$set($nc(other), gdate, $cast($BaseCalendar$Date, $nc(this->gdate)->clone()));
	if (this->cdate != nullptr) {
		if (this->cdate != this->gdate) {
			$set(other, cdate, $cast($BaseCalendar$Date, $nc(this->cdate)->clone()));
		} else {
			$set(other, cdate, other->gdate);
		}
	}
	$set(other, originalFields, nullptr);
	$set(other, zoneOffsets, nullptr);
	return $of(other);
}

$TimeZone* GregorianCalendar::getTimeZone() {
	$var($TimeZone, zone, $Calendar::getTimeZone());
	$nc(this->gdate)->setZone(zone);
	if (this->cdate != nullptr && this->cdate != this->gdate) {
		$nc(this->cdate)->setZone(zone);
	}
	return zone;
}

void GregorianCalendar::setTimeZone($TimeZone* zone) {
	$Calendar::setTimeZone(zone);
	$nc(this->gdate)->setZone(zone);
	if (this->cdate != nullptr && this->cdate != this->gdate) {
		$nc(this->cdate)->setZone(zone);
	}
}

bool GregorianCalendar::isWeekDateSupported() {
	return true;
}

int32_t GregorianCalendar::getWeekYear() {
	$useLocalCurrentObjectStackCache();
	int32_t year = get($Calendar::YEAR);
	if (internalGetEra() == GregorianCalendar::BCE) {
		year = 1 - year;
	}
	if (year > this->gregorianCutoverYear + 1) {
		int32_t weekOfYear = internalGet($Calendar::WEEK_OF_YEAR);
		if (internalGet($Calendar::MONTH) == $Calendar::JANUARY) {
			if (weekOfYear >= 52) {
				--year;
			}
		} else if (weekOfYear == 1) {
			++year;
		}
		return year;
	}
	int32_t dayOfYear = internalGet($Calendar::DAY_OF_YEAR);
	int32_t maxDayOfYear = getActualMaximum($Calendar::DAY_OF_YEAR);
	int32_t minimalDays = getMinimalDaysInFirstWeek();
	if (dayOfYear > minimalDays && dayOfYear < (maxDayOfYear - 6)) {
		return year;
	}
	$var(GregorianCalendar, cal, $cast(GregorianCalendar, clone()));
	$nc(cal)->setLenient(true);
	cal->setTimeZone($($TimeZone::getTimeZone("GMT"_s)));
	cal->set($Calendar::DAY_OF_YEAR, 1);
	cal->complete();
	int32_t var$0 = getFirstDayOfWeek();
	int32_t delta = var$0 - cal->get($Calendar::DAY_OF_WEEK);
	if (delta != 0) {
		if (delta < 0) {
			delta += 7;
		}
		cal->add($Calendar::DAY_OF_YEAR, delta);
	}
	int32_t minDayOfYear = cal->get($Calendar::DAY_OF_YEAR);
	if (dayOfYear < minDayOfYear) {
		if (minDayOfYear <= minimalDays) {
			--year;
		}
	} else {
		cal->set($Calendar::YEAR, year + 1);
		cal->set($Calendar::DAY_OF_YEAR, 1);
		cal->complete();
		int32_t var$1 = getFirstDayOfWeek();
		int32_t del = var$1 - cal->get($Calendar::DAY_OF_WEEK);
		if (del != 0) {
			if (del < 0) {
				del += 7;
			}
			cal->add($Calendar::DAY_OF_YEAR, del);
		}
		minDayOfYear = cal->get($Calendar::DAY_OF_YEAR) - 1;
		if (minDayOfYear == 0) {
			minDayOfYear = 7;
		}
		if (minDayOfYear >= minimalDays) {
			int32_t days = maxDayOfYear - dayOfYear + 1;
			if (days <= (7 - minDayOfYear)) {
				++year;
			}
		}
	}
	return year;
}

void GregorianCalendar::setWeekDate(int32_t weekYear, int32_t weekOfYear, int32_t dayOfWeek) {
	$useLocalCurrentObjectStackCache();
	if (dayOfWeek < $Calendar::SUNDAY || dayOfWeek > $Calendar::SATURDAY) {
		$throwNew($IllegalArgumentException, $$str({"invalid dayOfWeek: "_s, $$str(dayOfWeek)}));
	}
	$var(GregorianCalendar, gc, $cast(GregorianCalendar, clone()));
	$nc(gc)->setLenient(true);
	int32_t era = gc->get($Calendar::ERA);
	gc->clear();
	gc->setTimeZone($($TimeZone::getTimeZone("GMT"_s)));
	gc->set($Calendar::ERA, era);
	gc->set($Calendar::YEAR, weekYear);
	gc->set($Calendar::WEEK_OF_YEAR, 1);
	gc->set($Calendar::DAY_OF_WEEK, getFirstDayOfWeek());
	int32_t days = dayOfWeek - getFirstDayOfWeek();
	if (days < 0) {
		days += 7;
	}
	days += 7 * (weekOfYear - 1);
	if (days != 0) {
		gc->add($Calendar::DAY_OF_YEAR, days);
	} else {
		gc->complete();
	}
	bool var$0 = !isLenient();
	if (var$0) {
		bool var$2 = gc->getWeekYear() != weekYear;
		bool var$1 = var$2 || gc->internalGet($Calendar::WEEK_OF_YEAR) != weekOfYear;
		var$0 = (var$1 || gc->internalGet($Calendar::DAY_OF_WEEK) != dayOfWeek);
	}
	if (var$0) {
		$throwNew($IllegalArgumentException);
	}
	set($Calendar::ERA, gc->internalGet($Calendar::ERA));
	set($Calendar::YEAR, gc->internalGet($Calendar::YEAR));
	set($Calendar::MONTH, gc->internalGet($Calendar::MONTH));
	set($Calendar::DAY_OF_MONTH, gc->internalGet($Calendar::DAY_OF_MONTH));
	internalSet($Calendar::WEEK_OF_YEAR, weekOfYear);
	complete();
}

int32_t GregorianCalendar::getWeeksInWeekYear() {
	$var(GregorianCalendar, gc, getNormalizedCalendar());
	int32_t weekYear = $nc(gc)->getWeekYear();
	if (weekYear == gc->internalGet($Calendar::YEAR)) {
		return gc->getActualMaximum($Calendar::WEEK_OF_YEAR);
	}
	if (gc == this) {
		$assign(gc, $cast(GregorianCalendar, gc->clone()));
	}
	gc->setWeekDate(weekYear, 2, internalGet($Calendar::DAY_OF_WEEK));
	return gc->getActualMaximum($Calendar::WEEK_OF_YEAR);
}

void GregorianCalendar::computeFields() {
	int32_t mask = 0;
	if (isPartiallyNormalized()) {
		mask = getSetStateFields();
		int32_t fieldMask = (int32_t)(~mask & (uint32_t)$Calendar::ALL_FIELDS);
		if (fieldMask != 0 || this->calsys == nullptr) {
			mask |= computeFields(fieldMask, (int32_t)(mask & (uint32_t)($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK)));
			if (!GregorianCalendar::$assertionsDisabled && !(mask == $Calendar::ALL_FIELDS)) {
				$throwNew($AssertionError);
			}
		}
	} else {
		mask = $Calendar::ALL_FIELDS;
		computeFields(mask, 0);
	}
	setFieldsComputed(mask);
}

int32_t GregorianCalendar::computeFields(int32_t fieldMask, int32_t tzMask) {
	$useLocalCurrentObjectStackCache();
	int32_t zoneOffset = 0;
	$var($TimeZone, tz, getZone());
	if (this->zoneOffsets == nullptr) {
		$set(this, zoneOffsets, $new($ints, 2));
	}
	if (tzMask != ($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK)) {
		if ($instanceOf($ZoneInfo, tz)) {
			zoneOffset = $nc(($cast($ZoneInfo, tz)))->getOffsets(this->time, this->zoneOffsets);
		} else {
			zoneOffset = $nc(tz)->getOffset(this->time);
			$nc(this->zoneOffsets)->set(0, tz->getRawOffset());
			$nc(this->zoneOffsets)->set(1, zoneOffset - $nc(this->zoneOffsets)->get(0));
		}
	}
	if (tzMask != 0) {
		if (isFieldSet(tzMask, $Calendar::ZONE_OFFSET)) {
			$nc(this->zoneOffsets)->set(0, internalGet($Calendar::ZONE_OFFSET));
		}
		if (isFieldSet(tzMask, $Calendar::DST_OFFSET)) {
			$nc(this->zoneOffsets)->set(1, internalGet($Calendar::DST_OFFSET));
		}
		zoneOffset = $nc(this->zoneOffsets)->get(0) + $nc(this->zoneOffsets)->get(1);
	}
	int64_t fixedDate = $div(zoneOffset, GregorianCalendar::ONE_DAY);
	int32_t timeOfDay = $mod(zoneOffset, (int32_t)GregorianCalendar::ONE_DAY);
	fixedDate += $div(this->time, GregorianCalendar::ONE_DAY);
	timeOfDay += (int32_t)($mod(this->time, GregorianCalendar::ONE_DAY));
	if (timeOfDay >= GregorianCalendar::ONE_DAY) {
		timeOfDay -= GregorianCalendar::ONE_DAY;
		++fixedDate;
	} else {
		while (timeOfDay < 0) {
			timeOfDay += GregorianCalendar::ONE_DAY;
			--fixedDate;
		}
	}
	fixedDate += GregorianCalendar::EPOCH_OFFSET;
	int32_t era = GregorianCalendar::CE;
	int32_t year = 0;
	if (fixedDate >= this->gregorianCutoverDate) {
		if (!GregorianCalendar::$assertionsDisabled && !(this->cachedFixedDate == $Long::MIN_VALUE || $nc(this->gdate)->isNormalized())) {
			$throwNew($AssertionError, $of("cache control: not normalized"_s));
		}
		bool var$0 = !GregorianCalendar::$assertionsDisabled;
		if (var$0) {
			bool var$1 = this->cachedFixedDate == $Long::MIN_VALUE;
			if (!var$1) {
				int32_t var$2 = $nc(this->gdate)->getNormalizedYear();
				int32_t var$3 = $nc(this->gdate)->getMonth();
				var$1 = $nc(GregorianCalendar::gcal)->getFixedDate(var$2, var$3, $nc(this->gdate)->getDayOfMonth(), this->gdate) == this->cachedFixedDate;
			}
			var$0 = !var$1;
		}
		if (var$0) {
			$var($String, var$6, $$str({"cache control: inconsictency, cachedFixedDate="_s, $$str(this->cachedFixedDate), ", computed="_s}));
			int32_t var$7 = $nc(this->gdate)->getNormalizedYear();
			int32_t var$8 = $nc(this->gdate)->getMonth();
			$var($String, var$5, $$concat(var$6, $$str($nc(GregorianCalendar::gcal)->getFixedDate(var$7, var$8, $nc(this->gdate)->getDayOfMonth(), this->gdate))));
			$var($String, var$4, $$concat(var$5, ", date="_s));
			$throwNew($AssertionError, $of(($$concat(var$4, this->gdate))));
		}
		if (fixedDate != this->cachedFixedDate) {
			$nc(GregorianCalendar::gcal)->getCalendarDateFromFixedDate(this->gdate, fixedDate);
			this->cachedFixedDate = fixedDate;
		}
		year = $nc(this->gdate)->getYear();
		if (year <= 0) {
			year = 1 - year;
			era = GregorianCalendar::BCE;
		}
		$set(this, calsys, GregorianCalendar::gcal);
		$set(this, cdate, this->gdate);
		if (!GregorianCalendar::$assertionsDisabled && !($nc(this->cdate)->getDayOfWeek() > 0)) {
			$throwNew($AssertionError, $of($$str({"dow="_s, $$str($nc(this->cdate)->getDayOfWeek()), ", date="_s, this->cdate})));
		}
	} else {
		$set(this, calsys, getJulianCalendarSystem());
		$set(this, cdate, static_cast<$BaseCalendar$Date*>($cast($JulianCalendar$Date, $nc(GregorianCalendar::jcal)->newCalendarDate($(getZone())))));
		$nc(GregorianCalendar::jcal)->getCalendarDateFromFixedDate(this->cdate, fixedDate);
		$var($Era, e, $nc(this->cdate)->getEra());
		if (e == $nc(GregorianCalendar::jeras)->get(0)) {
			era = GregorianCalendar::BCE;
		}
		year = $nc(this->cdate)->getYear();
	}
	internalSet($Calendar::ERA, era);
	internalSet($Calendar::YEAR, year);
	int32_t mask = fieldMask | ($Calendar::ERA_MASK | $Calendar::YEAR_MASK);
	int32_t month = $nc(this->cdate)->getMonth() - 1;
	int32_t dayOfMonth = $nc(this->cdate)->getDayOfMonth();
	if (((int32_t)(fieldMask & (uint32_t)(($Calendar::MONTH_MASK | $Calendar::DAY_OF_MONTH_MASK) | $Calendar::DAY_OF_WEEK_MASK))) != 0) {
		internalSet($Calendar::MONTH, month);
		internalSet($Calendar::DAY_OF_MONTH, dayOfMonth);
		internalSet($Calendar::DAY_OF_WEEK, $nc(this->cdate)->getDayOfWeek());
		mask |= ($Calendar::MONTH_MASK | $Calendar::DAY_OF_MONTH_MASK) | $Calendar::DAY_OF_WEEK_MASK;
	}
	if (((int32_t)(fieldMask & (uint32_t)((((($Calendar::HOUR_OF_DAY_MASK | $Calendar::AM_PM_MASK) | $Calendar::HOUR_MASK) | $Calendar::MINUTE_MASK) | $Calendar::SECOND_MASK) | $Calendar::MILLISECOND_MASK))) != 0) {
		if (timeOfDay != 0) {
			int32_t hours = $div(timeOfDay, GregorianCalendar::ONE_HOUR);
			internalSet($Calendar::HOUR_OF_DAY, hours);
			internalSet($Calendar::AM_PM, hours / 12);
			internalSet($Calendar::HOUR, hours % 12);
			int32_t r = $mod(timeOfDay, GregorianCalendar::ONE_HOUR);
			internalSet($Calendar::MINUTE, $div(r, GregorianCalendar::ONE_MINUTE));
			$modAssign(r, GregorianCalendar::ONE_MINUTE);
			internalSet($Calendar::SECOND, $div(r, GregorianCalendar::ONE_SECOND));
			internalSet($Calendar::MILLISECOND, $mod(r, GregorianCalendar::ONE_SECOND));
		} else {
			internalSet($Calendar::HOUR_OF_DAY, 0);
			internalSet($Calendar::AM_PM, $Calendar::AM);
			internalSet($Calendar::HOUR, 0);
			internalSet($Calendar::MINUTE, 0);
			internalSet($Calendar::SECOND, 0);
			internalSet($Calendar::MILLISECOND, 0);
		}
		mask |= ((((($Calendar::HOUR_OF_DAY_MASK | $Calendar::AM_PM_MASK) | $Calendar::HOUR_MASK) | $Calendar::MINUTE_MASK) | $Calendar::SECOND_MASK) | $Calendar::MILLISECOND_MASK);
	}
	if (((int32_t)(fieldMask & (uint32_t)($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK))) != 0) {
		internalSet($Calendar::ZONE_OFFSET, $nc(this->zoneOffsets)->get(0));
		internalSet($Calendar::DST_OFFSET, $nc(this->zoneOffsets)->get(1));
		mask |= ($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK);
	}
	if (((int32_t)(fieldMask & (uint32_t)((($Calendar::DAY_OF_YEAR_MASK | $Calendar::WEEK_OF_YEAR_MASK) | $Calendar::WEEK_OF_MONTH_MASK) | $Calendar::DAY_OF_WEEK_IN_MONTH_MASK))) != 0) {
		int32_t normalizedYear = $nc(this->cdate)->getNormalizedYear();
		int64_t fixedDateJan1 = $nc(this->calsys)->getFixedDate(normalizedYear, 1, 1, this->cdate);
		int32_t dayOfYear = (int32_t)(fixedDate - fixedDateJan1) + 1;
		int64_t fixedDateMonth1 = fixedDate - dayOfMonth + 1;
		int32_t cutoverGap = 0;
		int32_t cutoverYear = ($equals(this->calsys, GregorianCalendar::gcal)) ? this->gregorianCutoverYear : this->gregorianCutoverYearJulian;
		int32_t relativeDayOfMonth = dayOfMonth - 1;
		if (normalizedYear == cutoverYear) {
			if (this->gregorianCutoverYearJulian <= this->gregorianCutoverYear) {
				fixedDateJan1 = getFixedDateJan1(this->cdate, fixedDate);
				if (fixedDate >= this->gregorianCutoverDate) {
					fixedDateMonth1 = getFixedDateMonth1(this->cdate, fixedDate);
				}
			}
			int32_t realDayOfYear = (int32_t)(fixedDate - fixedDateJan1) + 1;
			cutoverGap = dayOfYear - realDayOfYear;
			dayOfYear = realDayOfYear;
			relativeDayOfMonth = (int32_t)(fixedDate - fixedDateMonth1);
		}
		internalSet($Calendar::DAY_OF_YEAR, dayOfYear);
		internalSet($Calendar::DAY_OF_WEEK_IN_MONTH, relativeDayOfMonth / 7 + 1);
		int32_t weekOfYear = getWeekNumber(fixedDateJan1, fixedDate);
		if (weekOfYear == 0) {
			int64_t fixedDec31 = fixedDateJan1 - 1;
			int64_t prevJan1 = fixedDateJan1 - 365;
			if (normalizedYear > (cutoverYear + 1)) {
				if ($CalendarUtils::isGregorianLeapYear(normalizedYear - 1)) {
					--prevJan1;
				}
			} else if (normalizedYear <= this->gregorianCutoverYearJulian) {
				if ($CalendarUtils::isJulianLeapYear(normalizedYear - 1)) {
					--prevJan1;
				}
			} else {
				$var($BaseCalendar, calForJan1, this->calsys);
				int32_t prevYear = $nc($(getCalendarDate(fixedDec31)))->getNormalizedYear();
				if (prevYear == this->gregorianCutoverYear) {
					$assign(calForJan1, getCutoverCalendarSystem());
					if ($equals(calForJan1, GregorianCalendar::jcal)) {
						prevJan1 = $nc(calForJan1)->getFixedDate(prevYear, $BaseCalendar::JANUARY, 1, nullptr);
					} else {
						prevJan1 = this->gregorianCutoverDate;
						$assign(calForJan1, GregorianCalendar::gcal);
					}
				} else if (prevYear <= this->gregorianCutoverYearJulian) {
					$assign(calForJan1, getJulianCalendarSystem());
					prevJan1 = $nc(calForJan1)->getFixedDate(prevYear, $BaseCalendar::JANUARY, 1, nullptr);
				}
			}
			weekOfYear = getWeekNumber(prevJan1, fixedDec31);
		} else if (normalizedYear > this->gregorianCutoverYear || normalizedYear < (this->gregorianCutoverYearJulian - 1)) {
			if (weekOfYear >= 52) {
				int64_t nextJan1 = fixedDateJan1 + 365;
				if ($nc(this->cdate)->isLeapYear()) {
					++nextJan1;
				}
				int64_t nextJan1st = $BaseCalendar::getDayOfWeekDateOnOrBefore(nextJan1 + 6, getFirstDayOfWeek());
				int32_t ndays = (int32_t)(nextJan1st - nextJan1);
				if (ndays >= getMinimalDaysInFirstWeek() && fixedDate >= (nextJan1st - 7)) {
					weekOfYear = 1;
				}
			}
		} else {
			$var($BaseCalendar, calForJan1, this->calsys);
			int32_t nextYear = normalizedYear + 1;
			if (nextYear == (this->gregorianCutoverYearJulian + 1) && nextYear < this->gregorianCutoverYear) {
				nextYear = this->gregorianCutoverYear;
			}
			if (nextYear == this->gregorianCutoverYear) {
				$assign(calForJan1, getCutoverCalendarSystem());
			}
			int64_t nextJan1 = 0;
			if (nextYear > this->gregorianCutoverYear || this->gregorianCutoverYearJulian == this->gregorianCutoverYear || nextYear == this->gregorianCutoverYearJulian) {
				nextJan1 = $nc(calForJan1)->getFixedDate(nextYear, $BaseCalendar::JANUARY, 1, nullptr);
			} else {
				nextJan1 = this->gregorianCutoverDate;
				$assign(calForJan1, GregorianCalendar::gcal);
			}
			int64_t nextJan1st = $BaseCalendar::getDayOfWeekDateOnOrBefore(nextJan1 + 6, getFirstDayOfWeek());
			int32_t ndays = (int32_t)(nextJan1st - nextJan1);
			if (ndays >= getMinimalDaysInFirstWeek() && fixedDate >= (nextJan1st - 7)) {
				weekOfYear = 1;
			}
		}
		internalSet($Calendar::WEEK_OF_YEAR, weekOfYear);
		internalSet($Calendar::WEEK_OF_MONTH, getWeekNumber(fixedDateMonth1, fixedDate));
		mask |= ((($Calendar::DAY_OF_YEAR_MASK | $Calendar::WEEK_OF_YEAR_MASK) | $Calendar::WEEK_OF_MONTH_MASK) | $Calendar::DAY_OF_WEEK_IN_MONTH_MASK);
	}
	return mask;
}

int32_t GregorianCalendar::getWeekNumber(int64_t fixedDay1, int64_t fixedDate) {
	int64_t fixedDay1st = $Gregorian::getDayOfWeekDateOnOrBefore(fixedDay1 + 6, getFirstDayOfWeek());
	int32_t ndays = (int32_t)(fixedDay1st - fixedDay1);
	if (!GregorianCalendar::$assertionsDisabled && !(ndays <= 7)) {
		$throwNew($AssertionError);
	}
	if (ndays >= getMinimalDaysInFirstWeek()) {
		fixedDay1st -= 7;
	}
	int32_t normalizedDayOfPeriod = (int32_t)(fixedDate - fixedDay1st);
	if (normalizedDayOfPeriod >= 0) {
		return normalizedDayOfPeriod / 7 + 1;
	}
	return $CalendarUtils::floorDivide(normalizedDayOfPeriod, 7) + 1;
}

void GregorianCalendar::computeTime() {
	$useLocalCurrentObjectStackCache();
	if (!isLenient()) {
		if (this->originalFields == nullptr) {
			$set(this, originalFields, $new($ints, $Calendar::FIELD_COUNT));
		}
		for (int32_t field = 0; field < $Calendar::FIELD_COUNT; ++field) {
			int32_t value = internalGet(field);
			if (isExternallySet(field)) {
				bool var$0 = value < getMinimum(field);
				if (var$0 || value > getMaximum(field)) {
					$throwNew($IllegalArgumentException, $(getFieldName(field)));
				}
			}
			$nc(this->originalFields)->set(field, value);
		}
	}
	int32_t fieldMask = selectFields();
	int32_t year = isSet($Calendar::YEAR) ? internalGet($Calendar::YEAR) : GregorianCalendar::EPOCH_YEAR;
	int32_t era = internalGetEra();
	if (era == GregorianCalendar::BCE) {
		year = 1 - year;
	} else if (era != GregorianCalendar::CE) {
		$throwNew($IllegalArgumentException, "Invalid era"_s);
	}
	if (year <= 0 && !isSet($Calendar::ERA)) {
		fieldMask |= $Calendar::ERA_MASK;
		setFieldsComputed($Calendar::ERA_MASK);
	}
	int64_t timeOfDay = 0;
	if (isFieldSet(fieldMask, $Calendar::HOUR_OF_DAY)) {
		timeOfDay += (int64_t)internalGet($Calendar::HOUR_OF_DAY);
	} else {
		timeOfDay += internalGet($Calendar::HOUR);
		if (isFieldSet(fieldMask, $Calendar::AM_PM)) {
			timeOfDay += 12 * internalGet($Calendar::AM_PM);
		}
	}
	timeOfDay *= 60;
	timeOfDay += internalGet($Calendar::MINUTE);
	timeOfDay *= 60;
	timeOfDay += internalGet($Calendar::SECOND);
	timeOfDay *= 1000;
	timeOfDay += internalGet($Calendar::MILLISECOND);
	int64_t fixedDate = $div(timeOfDay, GregorianCalendar::ONE_DAY);
	$modAssign(timeOfDay, GregorianCalendar::ONE_DAY);
	while (timeOfDay < 0) {
		timeOfDay += GregorianCalendar::ONE_DAY;
		--fixedDate;
	}
	bool calculateFixedDate$break = false;
	for (;;) {
		{
			int64_t gfd = 0;
			int64_t jfd = 0;
			if (year > this->gregorianCutoverYear && year > this->gregorianCutoverYearJulian) {
				gfd = fixedDate + getFixedDate(GregorianCalendar::gcal, year, fieldMask);
				if (gfd >= this->gregorianCutoverDate) {
					fixedDate = gfd;
					calculateFixedDate$break = true;
					break;
				}
				jfd = fixedDate + getFixedDate($(getJulianCalendarSystem()), year, fieldMask);
			} else if (year < this->gregorianCutoverYear && year < this->gregorianCutoverYearJulian) {
				jfd = fixedDate + getFixedDate($(getJulianCalendarSystem()), year, fieldMask);
				if (jfd < this->gregorianCutoverDate) {
					fixedDate = jfd;
					calculateFixedDate$break = true;
					break;
				}
				gfd = jfd;
			} else {
				jfd = fixedDate + getFixedDate($(getJulianCalendarSystem()), year, fieldMask);
				gfd = fixedDate + getFixedDate(GregorianCalendar::gcal, year, fieldMask);
			}
			bool var$1 = isFieldSet(fieldMask, $Calendar::DAY_OF_YEAR);
			if (var$1 || isFieldSet(fieldMask, $Calendar::WEEK_OF_YEAR)) {
				if (this->gregorianCutoverYear == this->gregorianCutoverYearJulian) {
					fixedDate = jfd;
					calculateFixedDate$break = true;
					break;
				} else if (year == this->gregorianCutoverYear) {
					fixedDate = gfd;
					calculateFixedDate$break = true;
					break;
				}
			}
			if (gfd >= this->gregorianCutoverDate) {
				if (jfd >= this->gregorianCutoverDate) {
					fixedDate = gfd;
				} else if ($equals(this->calsys, GregorianCalendar::gcal) || this->calsys == nullptr) {
					fixedDate = gfd;
				} else {
					fixedDate = jfd;
				}
			} else if (jfd < this->gregorianCutoverDate) {
				fixedDate = jfd;
			} else {
				if (!isLenient()) {
					$throwNew($IllegalArgumentException, "the specified date doesn\'t exist"_s);
				}
				fixedDate = jfd;
			}
		}
		break;
	}
	int64_t millis = (fixedDate - GregorianCalendar::EPOCH_OFFSET) * GregorianCalendar::ONE_DAY + timeOfDay;
	$var($TimeZone, zone, getZone());
	if (this->zoneOffsets == nullptr) {
		$set(this, zoneOffsets, $new($ints, 2));
	}
	int32_t tzMask = (int32_t)(fieldMask & (uint32_t)($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK));
	if (tzMask != ($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK)) {
		if ($instanceOf($ZoneInfo, zone)) {
			$nc(($cast($ZoneInfo, zone)))->getOffsetsByWall(millis, this->zoneOffsets);
		} else {
			int32_t gmtOffset = isFieldSet(fieldMask, $Calendar::ZONE_OFFSET) ? internalGet($Calendar::ZONE_OFFSET) : $nc(zone)->getRawOffset();
			zone->getOffsets(millis - gmtOffset, this->zoneOffsets);
		}
	}
	if (tzMask != 0) {
		if (isFieldSet(tzMask, $Calendar::ZONE_OFFSET)) {
			$nc(this->zoneOffsets)->set(0, internalGet($Calendar::ZONE_OFFSET));
		}
		if (isFieldSet(tzMask, $Calendar::DST_OFFSET)) {
			$nc(this->zoneOffsets)->set(1, internalGet($Calendar::DST_OFFSET));
		}
	}
	millis -= $nc(this->zoneOffsets)->get(0) + $nc(this->zoneOffsets)->get(1);
	this->time = millis;
	int32_t mask = computeFields(fieldMask | getSetStateFields(), tzMask);
	if (!isLenient()) {
		for (int32_t field = 0; field < $Calendar::FIELD_COUNT; ++field) {
			if (!isExternallySet(field)) {
				continue;
			}
			if ($nc(this->originalFields)->get(field) != internalGet(field)) {
				$var($String, s, $str({$$str($nc(this->originalFields)->get(field)), " -> "_s, $$str(internalGet(field))}));
				$System::arraycopy(this->originalFields, 0, this->fields, 0, $nc(this->fields)->length);
				$throwNew($IllegalArgumentException, $$str({$(getFieldName(field)), ": "_s, s}));
			}
		}
	}
	setFieldsNormalized(mask);
}

int64_t GregorianCalendar::getFixedDate($BaseCalendar* cal, int32_t year, int32_t fieldMask) {
	int32_t month = $Calendar::JANUARY;
	if (isFieldSet(fieldMask, $Calendar::MONTH)) {
		month = internalGet($Calendar::MONTH);
		if (month > $Calendar::DECEMBER) {
			year += month / 12;
			$modAssign(month, 12);
		} else if (month < $Calendar::JANUARY) {
			$var($ints, rem, $new($ints, 1));
			year += $CalendarUtils::floorDivide(month, 12, rem);
			month = rem->get(0);
		}
	}
	int64_t fixedDate = $nc(cal)->getFixedDate(year, month + 1, 1, $equals(cal, GregorianCalendar::gcal) ? this->gdate : ($BaseCalendar$Date*)nullptr);
	if (isFieldSet(fieldMask, $Calendar::MONTH)) {
		if (isFieldSet(fieldMask, $Calendar::DAY_OF_MONTH)) {
			if (isSet($Calendar::DAY_OF_MONTH)) {
				fixedDate += internalGet($Calendar::DAY_OF_MONTH);
				--fixedDate;
			}
		} else if (isFieldSet(fieldMask, $Calendar::WEEK_OF_MONTH)) {
			int64_t firstDayOfWeek = $BaseCalendar::getDayOfWeekDateOnOrBefore(fixedDate + 6, getFirstDayOfWeek());
			if ((firstDayOfWeek - fixedDate) >= getMinimalDaysInFirstWeek()) {
				firstDayOfWeek -= 7;
			}
			if (isFieldSet(fieldMask, $Calendar::DAY_OF_WEEK)) {
				firstDayOfWeek = $BaseCalendar::getDayOfWeekDateOnOrBefore(firstDayOfWeek + 6, internalGet($Calendar::DAY_OF_WEEK));
			}
			fixedDate = firstDayOfWeek + 7 * (internalGet($Calendar::WEEK_OF_MONTH) - 1);
		} else {
			int32_t dayOfWeek = 0;
			if (isFieldSet(fieldMask, $Calendar::DAY_OF_WEEK)) {
				dayOfWeek = internalGet($Calendar::DAY_OF_WEEK);
			} else {
				dayOfWeek = getFirstDayOfWeek();
			}
			int32_t dowim = 0;
			if (isFieldSet(fieldMask, $Calendar::DAY_OF_WEEK_IN_MONTH)) {
				dowim = internalGet($Calendar::DAY_OF_WEEK_IN_MONTH);
			} else {
				dowim = 1;
			}
			if (dowim >= 0) {
				fixedDate = $BaseCalendar::getDayOfWeekDateOnOrBefore(fixedDate + (7 * dowim) - 1, dayOfWeek);
			} else {
				int32_t lastDate = monthLength(month, year) + (7 * (dowim + 1));
				fixedDate = $BaseCalendar::getDayOfWeekDateOnOrBefore(fixedDate + lastDate - 1, dayOfWeek);
			}
		}
	} else {
		if (year == this->gregorianCutoverYear && $equals(cal, GregorianCalendar::gcal) && fixedDate < this->gregorianCutoverDate && this->gregorianCutoverYear != this->gregorianCutoverYearJulian) {
			fixedDate = this->gregorianCutoverDate;
		}
		if (isFieldSet(fieldMask, $Calendar::DAY_OF_YEAR)) {
			fixedDate += internalGet($Calendar::DAY_OF_YEAR);
			--fixedDate;
		} else {
			int64_t firstDayOfWeek = $BaseCalendar::getDayOfWeekDateOnOrBefore(fixedDate + 6, getFirstDayOfWeek());
			if ((firstDayOfWeek - fixedDate) >= getMinimalDaysInFirstWeek()) {
				firstDayOfWeek -= 7;
			}
			if (isFieldSet(fieldMask, $Calendar::DAY_OF_WEEK)) {
				int32_t dayOfWeek = internalGet($Calendar::DAY_OF_WEEK);
				if (dayOfWeek != getFirstDayOfWeek()) {
					firstDayOfWeek = $BaseCalendar::getDayOfWeekDateOnOrBefore(firstDayOfWeek + 6, dayOfWeek);
				}
			}
			fixedDate = firstDayOfWeek + 7 * ((int64_t)internalGet($Calendar::WEEK_OF_YEAR) - 1);
		}
	}
	return fixedDate;
}

GregorianCalendar* GregorianCalendar::getNormalizedCalendar() {
	$var(GregorianCalendar, gc, nullptr);
	if (isFullyNormalized()) {
		$assign(gc, this);
	} else {
		$assign(gc, $cast(GregorianCalendar, this->clone()));
		$nc(gc)->setLenient(true);
		gc->complete();
	}
	return gc;
}

$BaseCalendar* GregorianCalendar::getJulianCalendarSystem() {
	$load(GregorianCalendar);
	$synchronized(class$) {
		$init(GregorianCalendar);
		if (GregorianCalendar::jcal == nullptr) {
			$assignStatic(GregorianCalendar::jcal, $cast($JulianCalendar, $CalendarSystem::forName("julian"_s)));
			$assignStatic(GregorianCalendar::jeras, $nc(GregorianCalendar::jcal)->getEras());
		}
		return GregorianCalendar::jcal;
	}
}

$BaseCalendar* GregorianCalendar::getCutoverCalendarSystem() {
	if (this->gregorianCutoverYearJulian < this->gregorianCutoverYear) {
		return GregorianCalendar::gcal;
	}
	return getJulianCalendarSystem();
}

bool GregorianCalendar::isCutoverYear(int32_t normalizedYear) {
	int32_t cutoverYear = ($equals(this->calsys, GregorianCalendar::gcal)) ? this->gregorianCutoverYear : this->gregorianCutoverYearJulian;
	return normalizedYear == cutoverYear;
}

int64_t GregorianCalendar::getFixedDateJan1($BaseCalendar$Date* date, int64_t fixedDate) {
	bool var$0 = !GregorianCalendar::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(date)->getNormalizedYear() == this->gregorianCutoverYear;
		var$0 = !(var$1 || $nc(date)->getNormalizedYear() == this->gregorianCutoverYearJulian);
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	if (this->gregorianCutoverYear != this->gregorianCutoverYearJulian) {
		if (fixedDate >= this->gregorianCutoverDate) {
			return this->gregorianCutoverDate;
		}
	}
	$var($BaseCalendar, juliancal, getJulianCalendarSystem());
	return $nc(juliancal)->getFixedDate($nc(date)->getNormalizedYear(), $BaseCalendar::JANUARY, 1, nullptr);
}

int64_t GregorianCalendar::getFixedDateMonth1($BaseCalendar$Date* date, int64_t fixedDate) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !GregorianCalendar::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(date)->getNormalizedYear() == this->gregorianCutoverYear;
		var$0 = !(var$1 || $nc(date)->getNormalizedYear() == this->gregorianCutoverYearJulian);
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($BaseCalendar$Date, gCutover, getGregorianCutoverDate());
	bool var$2 = $nc(gCutover)->getMonth() == $BaseCalendar::JANUARY;
	if (var$2 && gCutover->getDayOfMonth() == 1) {
		return fixedDate - $nc(date)->getDayOfMonth() + 1;
	}
	int64_t fixedDateMonth1 = 0;
	int32_t var$3 = $nc(date)->getMonth();
	if (var$3 == $nc(gCutover)->getMonth()) {
		$var($BaseCalendar$Date, jLastDate, getLastJulianDate());
		bool var$4 = this->gregorianCutoverYear == this->gregorianCutoverYearJulian;
		if (var$4) {
			int32_t var$5 = gCutover->getMonth();
			var$4 = var$5 == $nc(jLastDate)->getMonth();
		}
		if (var$4) {
			int32_t var$6 = date->getNormalizedYear();
			fixedDateMonth1 = $nc(GregorianCalendar::jcal)->getFixedDate(var$6, date->getMonth(), 1, nullptr);
		} else {
			fixedDateMonth1 = this->gregorianCutoverDate;
		}
	} else {
		fixedDateMonth1 = fixedDate - date->getDayOfMonth() + 1;
	}
	return fixedDateMonth1;
}

$BaseCalendar$Date* GregorianCalendar::getCalendarDate(int64_t fd) {
	$useLocalCurrentObjectStackCache();
	$var($BaseCalendar, cal, (fd >= this->gregorianCutoverDate) ? static_cast<$BaseCalendar*>(GregorianCalendar::gcal) : getJulianCalendarSystem());
	$init($TimeZone);
	$var($BaseCalendar$Date, d, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate($TimeZone::NO_TIMEZONE)));
	cal->getCalendarDateFromFixedDate(d, fd);
	return d;
}

$BaseCalendar$Date* GregorianCalendar::getGregorianCutoverDate() {
	return getCalendarDate(this->gregorianCutoverDate);
}

$BaseCalendar$Date* GregorianCalendar::getLastJulianDate() {
	return getCalendarDate(this->gregorianCutoverDate - 1);
}

int32_t GregorianCalendar::monthLength(int32_t month, int32_t year) {
	return isLeapYear(year) ? $nc(GregorianCalendar::LEAP_MONTH_LENGTH)->get(month) : $nc(GregorianCalendar::MONTH_LENGTH)->get(month);
}

int32_t GregorianCalendar::monthLength(int32_t month) {
	int32_t year = internalGet($Calendar::YEAR);
	if (internalGetEra() == GregorianCalendar::BCE) {
		year = 1 - year;
	}
	return monthLength(month, year);
}

int32_t GregorianCalendar::actualMonthLength() {
	int32_t year = $nc(this->cdate)->getNormalizedYear();
	if (year != this->gregorianCutoverYear && year != this->gregorianCutoverYearJulian) {
		return $nc(this->calsys)->getMonthLength(this->cdate);
	}
	$var($BaseCalendar$Date, date, $cast($BaseCalendar$Date, $nc(this->cdate)->clone()));
	int64_t fd = $nc(this->calsys)->getFixedDate(date);
	int64_t month1 = getFixedDateMonth1(date, fd);
	int64_t next1 = month1 + $nc(this->calsys)->getMonthLength(date);
	if (next1 < this->gregorianCutoverDate) {
		return (int32_t)(next1 - month1);
	}
	if (this->cdate != this->gdate) {
		$init($TimeZone);
		$assign(date, static_cast<$BaseCalendar$Date*>($cast($Gregorian$Date, $nc(GregorianCalendar::gcal)->newCalendarDate($TimeZone::NO_TIMEZONE))));
	}
	$nc(GregorianCalendar::gcal)->getCalendarDateFromFixedDate(date, next1);
	next1 = getFixedDateMonth1(date, next1);
	return (int32_t)(next1 - month1);
}

int32_t GregorianCalendar::yearLength(int32_t year) {
	return isLeapYear(year) ? 366 : 365;
}

int32_t GregorianCalendar::yearLength() {
	int32_t year = internalGet($Calendar::YEAR);
	if (internalGetEra() == GregorianCalendar::BCE) {
		year = 1 - year;
	}
	return yearLength(year);
}

void GregorianCalendar::pinDayOfMonth() {
	int32_t year = internalGet($Calendar::YEAR);
	int32_t monthLen = 0;
	if (year > this->gregorianCutoverYear || year < this->gregorianCutoverYearJulian) {
		monthLen = monthLength(internalGet($Calendar::MONTH));
	} else {
		$var(GregorianCalendar, gc, getNormalizedCalendar());
		monthLen = $nc(gc)->getActualMaximum($Calendar::DAY_OF_MONTH);
	}
	int32_t dom = internalGet($Calendar::DAY_OF_MONTH);
	if (dom > monthLen) {
		set($Calendar::DAY_OF_MONTH, monthLen);
	}
}

int64_t GregorianCalendar::getCurrentFixedDate() {
	return ($equals(this->calsys, GregorianCalendar::gcal)) ? this->cachedFixedDate : $nc(this->calsys)->getFixedDate(this->cdate);
}

int32_t GregorianCalendar::getRolledValue(int32_t value, int32_t amount, int32_t min, int32_t max) {
	$init(GregorianCalendar);
	if (!GregorianCalendar::$assertionsDisabled && !(value >= min && value <= max)) {
		$throwNew($AssertionError);
	}
	int32_t range = max - min + 1;
	$modAssign(amount, range);
	int32_t n = value + amount;
	if (n > max) {
		n -= range;
	} else if (n < min) {
		n += range;
	}
	if (!GregorianCalendar::$assertionsDisabled && !(n >= min && n <= max)) {
		$throwNew($AssertionError);
	}
	return n;
}

int32_t GregorianCalendar::internalGetEra() {
	return isSet($Calendar::ERA) ? internalGet($Calendar::ERA) : GregorianCalendar::CE;
}

void GregorianCalendar::readObject($ObjectInputStream* stream) {
	$nc(stream)->defaultReadObject();
	if (this->gdate == nullptr) {
		$set(this, gdate, static_cast<$BaseCalendar$Date*>($cast($Gregorian$Date, $nc(GregorianCalendar::gcal)->newCalendarDate($(getZone())))));
		this->cachedFixedDate = $Long::MIN_VALUE;
	}
	setGregorianChange(this->gregorianCutover);
}

$ZonedDateTime* GregorianCalendar::toZonedDateTime() {
	$useLocalCurrentObjectStackCache();
	$var($Instant, var$0, $Instant::ofEpochMilli(getTimeInMillis()));
	return $ZonedDateTime::ofInstant(var$0, $($nc($(getTimeZone()))->toZoneId()));
}

GregorianCalendar* GregorianCalendar::from($ZonedDateTime* zdt) {
	$init(GregorianCalendar);
	$useLocalCurrentObjectStackCache();
	$var(GregorianCalendar, cal, $new(GregorianCalendar, $($TimeZone::getTimeZone($($nc(zdt)->getZone())))));
	cal->setGregorianChange($$new($Date, $Long::MIN_VALUE));
	cal->setFirstDayOfWeek($Calendar::MONDAY);
	cal->setMinimalDaysInFirstWeek(4);
	try {
		int64_t var$0 = $Math::multiplyExact($nc(zdt)->toEpochSecond(), 1000);
		$init($ChronoField);
		cal->setTimeInMillis($Math::addExact(var$0, (int64_t)$nc(zdt)->get($ChronoField::MILLI_OF_SECOND)));
	} catch ($ArithmeticException& ex) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(ex));
	}
	return cal;
}

void clinit$GregorianCalendar($Class* class$) {
	GregorianCalendar::$assertionsDisabled = !GregorianCalendar::class$->desiredAssertionStatus();
	$assignStatic(GregorianCalendar::MONTH_LENGTH, $new($ints, {
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	}));
	$assignStatic(GregorianCalendar::LEAP_MONTH_LENGTH, $new($ints, {
		31,
		29,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	}));
	$assignStatic(GregorianCalendar::MIN_VALUES, $new($ints, {
		GregorianCalendar::BCE,
		1,
		$Calendar::JANUARY,
		1,
		0,
		1,
		1,
		$Calendar::SUNDAY,
		1,
		$Calendar::AM,
		0,
		0,
		0,
		0,
		0,
		-13 * GregorianCalendar::ONE_HOUR,
		0
	}));
	$assignStatic(GregorianCalendar::LEAST_MAX_VALUES, $new($ints, {
		GregorianCalendar::CE,
		0x116BABFE,
		$Calendar::DECEMBER,
		52,
		4,
		28,
		365,
		$Calendar::SATURDAY,
		4,
		$Calendar::PM,
		11,
		23,
		59,
		59,
		999,
		14 * GregorianCalendar::ONE_HOUR,
		20 * GregorianCalendar::ONE_MINUTE
	}));
	$assignStatic(GregorianCalendar::MAX_VALUES, $new($ints, {
		GregorianCalendar::CE,
		0x116BD2D2,
		$Calendar::DECEMBER,
		53,
		6,
		31,
		366,
		$Calendar::SATURDAY,
		6,
		$Calendar::PM,
		11,
		23,
		59,
		59,
		999,
		14 * GregorianCalendar::ONE_HOUR,
		2 * GregorianCalendar::ONE_HOUR
	}));
	$assignStatic(GregorianCalendar::gcal, $CalendarSystem::getGregorianCalendar());
}

GregorianCalendar::GregorianCalendar() {
}

$Class* GregorianCalendar::load$($String* name, bool initialize) {
	$loadClass(GregorianCalendar, name, initialize, &_GregorianCalendar_ClassInfo_, clinit$GregorianCalendar, allocate$GregorianCalendar);
	return class$;
}

$Class* GregorianCalendar::class$ = nullptr;

	} // util
} // java