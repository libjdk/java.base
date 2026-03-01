#include <java/util/JapaneseImperialCalendar.h>

#include <java/io/ObjectInputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TimeZone.h>
#include <sun/util/calendar/BaseCalendar$Date.h>
#include <sun/util/calendar/BaseCalendar.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/CalendarSystem.h>
#include <sun/util/calendar/CalendarUtils.h>
#include <sun/util/calendar/Era.h>
#include <sun/util/calendar/Gregorian$Date.h>
#include <sun/util/calendar/Gregorian.h>
#include <sun/util/calendar/LocalGregorianCalendar$Date.h>
#include <sun/util/calendar/LocalGregorianCalendar.h>
#include <sun/util/calendar/ZoneInfo.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <jcpp.h>

#undef ALL_FIELDS
#undef ALL_STYLES
#undef AM
#undef AM_PM
#undef AM_PM_MASK
#undef BEFORE_MEIJI
#undef BEFORE_MEIJI_ERA
#undef DAY_OF_MONTH
#undef DAY_OF_MONTH_MASK
#undef DAY_OF_WEEK
#undef DAY_OF_WEEK_IN_MONTH
#undef DAY_OF_WEEK_IN_MONTH_MASK
#undef DAY_OF_WEEK_MASK
#undef DAY_OF_YEAR
#undef DAY_OF_YEAR_MASK
#undef DECEMBER
#undef DST_OFFSET
#undef DST_OFFSET_MASK
#undef EPOCH_OFFSET
#undef ERA
#undef ERA_MASK
#undef FIELD_COUNT
#undef HEISEI
#undef HOUR
#undef HOUR_MASK
#undef HOUR_OF_DAY
#undef HOUR_OF_DAY_MASK
#undef JANUARY
#undef LEAP_MONTH_LENGTH
#undef LEAST_MAX_VALUES
#undef LONG
#undef MAX_VALUE
#undef MAX_VALUES
#undef MEIJI
#undef MILLISECOND
#undef MILLISECOND_MASK
#undef MINUTE
#undef MINUTE_MASK
#undef MIN_VALUE
#undef MIN_VALUES
#undef MONTH
#undef MONTH_LENGTH
#undef MONTH_MASK
#undef NARROW_FORMAT
#undef NO_TIMEZONE
#undef ONE_DAY
#undef ONE_HOUR
#undef ONE_MINUTE
#undef ONE_SECOND
#undef PM
#undef REIWA
#undef SATURDAY
#undef SECOND
#undef SECOND_MASK
#undef SHORT
#undef SHOWA
#undef SUNDAY
#undef TAISHO
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
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $TimeZone = ::java::util::TimeZone;
using $BaseCalendar = ::sun::util::calendar::BaseCalendar;
using $BaseCalendar$Date = ::sun::util::calendar::BaseCalendar$Date;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $CalendarSystem = ::sun::util::calendar::CalendarSystem;
using $CalendarUtils = ::sun::util::calendar::CalendarUtils;
using $Era = ::sun::util::calendar::Era;
using $Gregorian = ::sun::util::calendar::Gregorian;
using $LocalGregorianCalendar = ::sun::util::calendar::LocalGregorianCalendar;
using $LocalGregorianCalendar$Date = ::sun::util::calendar::LocalGregorianCalendar$Date;
using $ZoneInfo = ::sun::util::calendar::ZoneInfo;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;

namespace java {
	namespace util {

$FieldInfo _JapaneseImperialCalendar_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(JapaneseImperialCalendar, $assertionsDisabled)},
	{"BEFORE_MEIJI", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, BEFORE_MEIJI)},
	{"MEIJI", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, MEIJI)},
	{"TAISHO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, TAISHO)},
	{"SHOWA", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, SHOWA)},
	{"HEISEI", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, HEISEI)},
	{"REIWA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, REIWA)},
	{"EPOCH_OFFSET", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, EPOCH_OFFSET)},
	{"ONE_SECOND", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, ONE_SECOND)},
	{"ONE_MINUTE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, ONE_MINUTE)},
	{"ONE_HOUR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, ONE_HOUR)},
	{"ONE_DAY", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, ONE_DAY)},
	{"jcal", "Lsun/util/calendar/LocalGregorianCalendar;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, jcal)},
	{"gcal", "Lsun/util/calendar/Gregorian;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, gcal)},
	{"BEFORE_MEIJI_ERA", "Lsun/util/calendar/Era;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, BEFORE_MEIJI_ERA)},
	{"eras", "[Lsun/util/calendar/Era;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, eras)},
	{"sinceFixedDates", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, sinceFixedDates)},
	{"currentEra", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, currentEra)},
	{"MIN_VALUES", "[I", nullptr, $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, MIN_VALUES)},
	{"LEAST_MAX_VALUES", "[I", nullptr, $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, LEAST_MAX_VALUES)},
	{"MAX_VALUES", "[I", nullptr, $STATIC | $FINAL, $staticField(JapaneseImperialCalendar, MAX_VALUES)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JapaneseImperialCalendar, serialVersionUID)},
	{"jdate", "Lsun/util/calendar/LocalGregorianCalendar$Date;", nullptr, $PRIVATE | $TRANSIENT, $field(JapaneseImperialCalendar, jdate)},
	{"zoneOffsets", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(JapaneseImperialCalendar, zoneOffsets)},
	{"originalFields", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(JapaneseImperialCalendar, originalFields)},
	{"cachedFixedDate", "J", nullptr, $PRIVATE | $TRANSIENT, $field(JapaneseImperialCalendar, cachedFixedDate)},
	{}
};

$MethodInfo _JapaneseImperialCalendar_MethodInfo_[] = {
	{"<init>", "(Ljava/util/TimeZone;Ljava/util/Locale;)V", nullptr, 0, $method(JapaneseImperialCalendar, init$, void, $TimeZone*, $Locale*)},
	{"<init>", "(Ljava/util/TimeZone;Ljava/util/Locale;Z)V", nullptr, 0, $method(JapaneseImperialCalendar, init$, void, $TimeZone*, $Locale*, bool)},
	{"actualMonthLength", "()I", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, actualMonthLength, int32_t)},
	{"add", "(II)V", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, add, void, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, clone, $Object*)},
	{"computeFields", "()V", nullptr, $PROTECTED, $virtualMethod(JapaneseImperialCalendar, computeFields, void)},
	{"computeFields", "(II)I", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, computeFields, int32_t, int32_t, int32_t)},
	{"computeTime", "()V", nullptr, $PROTECTED, $virtualMethod(JapaneseImperialCalendar, computeTime, void)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, equals, bool, Object$*)},
	{"getActualMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getActualMaximum, int32_t, int32_t)},
	{"getActualMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getActualMinimum, int32_t, int32_t)},
	{"getCalendarDate", "(J)Lsun/util/calendar/LocalGregorianCalendar$Date;", nullptr, $PRIVATE | $STATIC, $staticMethod(JapaneseImperialCalendar, getCalendarDate, $LocalGregorianCalendar$Date*, int64_t)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getCalendarType, $String*)},
	{"getDisplayName", "(IILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getDisplayName, $String*, int32_t, int32_t, $Locale*)},
	{"getDisplayNames", "(IILjava/util/Locale;)Ljava/util/Map;", "(IILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getDisplayNames, $Map*, int32_t, int32_t, $Locale*)},
	{"getEraIndex", "(Lsun/util/calendar/LocalGregorianCalendar$Date;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(JapaneseImperialCalendar, getEraIndex, int32_t, $LocalGregorianCalendar$Date*)},
	{"getFixedDate", "(III)J", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, getFixedDate, int64_t, int32_t, int32_t, int32_t)},
	{"getFixedDateJan1", "(Lsun/util/calendar/LocalGregorianCalendar$Date;J)J", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, getFixedDateJan1, int64_t, $LocalGregorianCalendar$Date*, int64_t)},
	{"getFixedDateMonth1", "(Lsun/util/calendar/LocalGregorianCalendar$Date;J)J", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, getFixedDateMonth1, int64_t, $LocalGregorianCalendar$Date*, int64_t)},
	{"getGreatestMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getGreatestMinimum, int32_t, int32_t)},
	{"getLeastMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getLeastMaximum, int32_t, int32_t)},
	{"getMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getMaximum, int32_t, int32_t)},
	{"getMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getMinimum, int32_t, int32_t)},
	{"getNormalizedCalendar", "()Ljava/util/JapaneseImperialCalendar;", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, getNormalizedCalendar, JapaneseImperialCalendar*)},
	{"getRolledValue", "(IIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(JapaneseImperialCalendar, getRolledValue, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"getTimeZone", "()Ljava/util/TimeZone;", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, getTimeZone, $TimeZone*)},
	{"getTransitionEraIndex", "(Lsun/util/calendar/LocalGregorianCalendar$Date;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(JapaneseImperialCalendar, getTransitionEraIndex, int32_t, $LocalGregorianCalendar$Date*)},
	{"getWeekNumber", "(JJ)I", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, getWeekNumber, int32_t, int64_t, int64_t)},
	{"getYearOffsetInMillis", "(Lsun/util/calendar/CalendarDate;)J", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, getYearOffsetInMillis, int64_t, $CalendarDate*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, hashCode, int32_t)},
	{"internalGetEra", "()I", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, internalGetEra, int32_t)},
	{"isTransitionYear", "(I)Z", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, isTransitionYear, bool, int32_t)},
	{"monthLength", "(II)I", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, monthLength, int32_t, int32_t, int32_t)},
	{"monthLength", "(I)I", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, monthLength, int32_t, int32_t)},
	{"pinDayOfMonth", "(Lsun/util/calendar/LocalGregorianCalendar$Date;)V", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, pinDayOfMonth, void, $LocalGregorianCalendar$Date*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(JapaneseImperialCalendar, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"roll", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, roll, void, int32_t, bool)},
	{"roll", "(II)V", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, roll, void, int32_t, int32_t)},
	{"setTimeZone", "(Ljava/util/TimeZone;)V", nullptr, $PUBLIC, $virtualMethod(JapaneseImperialCalendar, setTimeZone, void, $TimeZone*)},
	{}
};

$ClassInfo _JapaneseImperialCalendar_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.JapaneseImperialCalendar",
	"java.util.Calendar",
	nullptr,
	_JapaneseImperialCalendar_FieldInfo_,
	_JapaneseImperialCalendar_MethodInfo_
};

$Object* allocate$JapaneseImperialCalendar($Class* clazz) {
	return $of($alloc(JapaneseImperialCalendar));
}

bool JapaneseImperialCalendar::$assertionsDisabled = false;
$LocalGregorianCalendar* JapaneseImperialCalendar::jcal = nullptr;
$Gregorian* JapaneseImperialCalendar::gcal = nullptr;
$Era* JapaneseImperialCalendar::BEFORE_MEIJI_ERA = nullptr;
$EraArray* JapaneseImperialCalendar::eras = nullptr;
$longs* JapaneseImperialCalendar::sinceFixedDates = nullptr;
int32_t JapaneseImperialCalendar::currentEra = 0;
$ints* JapaneseImperialCalendar::MIN_VALUES = nullptr;
$ints* JapaneseImperialCalendar::LEAST_MAX_VALUES = nullptr;
$ints* JapaneseImperialCalendar::MAX_VALUES = nullptr;

void JapaneseImperialCalendar::init$($TimeZone* zone, $Locale* aLocale) {
	$Calendar::init$(zone, aLocale);
	this->cachedFixedDate = $Long::MIN_VALUE;
	$set(this, jdate, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->newCalendarDate(zone)));
	setTimeInMillis($System::currentTimeMillis());
}

void JapaneseImperialCalendar::init$($TimeZone* zone, $Locale* aLocale, bool flag) {
	$Calendar::init$(zone, aLocale);
	this->cachedFixedDate = $Long::MIN_VALUE;
	$set(this, jdate, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->newCalendarDate(zone)));
}

$String* JapaneseImperialCalendar::getCalendarType() {
	return "japanese"_s;
}

bool JapaneseImperialCalendar::equals(Object$* obj) {
	return $instanceOf(JapaneseImperialCalendar, obj) && $Calendar::equals(obj);
}

int32_t JapaneseImperialCalendar::hashCode() {
	int32_t var$0 = $Calendar::hashCode();
	return var$0 ^ $nc(this->jdate)->hashCode();
}

void JapaneseImperialCalendar::add(int32_t field, int32_t amount) {
	$useLocalCurrentObjectStackCache();
	if (amount == 0) {
		return;
	}
	if (field < 0 || field >= $Calendar::ZONE_OFFSET) {
		$throwNew($IllegalArgumentException);
	}
	complete();
	if (field == $Calendar::YEAR) {
		$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(this->jdate)->clone()));
		$nc(d)->addYear(amount);
		pinDayOfMonth(d);
		set($Calendar::ERA, getEraIndex(d));
		set($Calendar::YEAR, d->getYear());
		set($Calendar::MONTH, d->getMonth() - 1);
		set($Calendar::DAY_OF_MONTH, d->getDayOfMonth());
	} else if (field == $Calendar::MONTH) {
		$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(this->jdate)->clone()));
		$nc(d)->addMonth(amount);
		pinDayOfMonth(d);
		set($Calendar::ERA, getEraIndex(d));
		set($Calendar::YEAR, d->getYear());
		set($Calendar::MONTH, d->getMonth() - 1);
		set($Calendar::DAY_OF_MONTH, d->getDayOfMonth());
	} else if (field == $Calendar::ERA) {
		int32_t era = internalGet($Calendar::ERA) + amount;
		if (era < 0) {
			era = 0;
		} else if (era > $nc(JapaneseImperialCalendar::eras)->length - 1) {
			era = $nc(JapaneseImperialCalendar::eras)->length - 1;
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
		int64_t fd = this->cachedFixedDate;
		timeOfDay += internalGet($Calendar::HOUR_OF_DAY);
		timeOfDay *= 60;
		timeOfDay += internalGet($Calendar::MINUTE);
		timeOfDay *= 60;
		timeOfDay += internalGet($Calendar::SECOND);
		timeOfDay *= 1000;
		timeOfDay += internalGet($Calendar::MILLISECOND);
		if (timeOfDay >= JapaneseImperialCalendar::ONE_DAY) {
			++fd;
			timeOfDay -= JapaneseImperialCalendar::ONE_DAY;
		} else if (timeOfDay < 0) {
			--fd;
			timeOfDay += JapaneseImperialCalendar::ONE_DAY;
		}
		fd += delta;
		int32_t var$0 = internalGet($Calendar::ZONE_OFFSET);
		int32_t zoneOffset = var$0 + internalGet($Calendar::DST_OFFSET);
		setTimeInMillis((fd - JapaneseImperialCalendar::EPOCH_OFFSET) * JapaneseImperialCalendar::ONE_DAY + timeOfDay - zoneOffset);
		int32_t var$1 = internalGet($Calendar::ZONE_OFFSET);
		zoneOffset -= var$1 + internalGet($Calendar::DST_OFFSET);
		if (zoneOffset != 0) {
			setTimeInMillis(this->time + zoneOffset);
			int64_t fd2 = this->cachedFixedDate;
			if (fd2 != fd) {
				setTimeInMillis(this->time - zoneOffset);
			}
		}
	}
}

void JapaneseImperialCalendar::roll(int32_t field, bool up) {
	roll(field, up ? +1 : -1);
}

void JapaneseImperialCalendar::roll(int32_t field, int32_t amount) {
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
	case $Calendar::ERA:
		{}
	case $Calendar::AM_PM:
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
				int32_t unit = max + 1;
				int32_t h = internalGet(field);
				int32_t nh = $mod((h + amount), unit);
				if (nh < 0) {
					nh += unit;
				}
				this->time += JapaneseImperialCalendar::ONE_HOUR * (nh - h);
				$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(this->time, $(getZone())));
				int32_t var$0 = internalGet($Calendar::DAY_OF_MONTH);
				if (var$0 != $nc(d)->getDayOfMonth()) {
					d->setEra($($nc(this->jdate)->getEra()));
					int32_t var$1 = internalGet($Calendar::YEAR);
					int32_t var$2 = internalGet($Calendar::MONTH) + 1;
					d->setDate(var$1, var$2, internalGet($Calendar::DAY_OF_MONTH));
					if (field == $Calendar::HOUR) {
						if (!JapaneseImperialCalendar::$assertionsDisabled && !(internalGet($Calendar::AM_PM) == $Calendar::PM)) {
							$throwNew($AssertionError);
						}
						d->addHours(+12);
					}
					this->time = $nc(JapaneseImperialCalendar::jcal)->getTime(d);
				}
				int32_t hourOfDay = $nc(d)->getHours();
				internalSet(field, $mod(hourOfDay, unit));
				if (field == $Calendar::HOUR) {
					internalSet($Calendar::HOUR_OF_DAY, hourOfDay);
				} else {
					internalSet($Calendar::AM_PM, hourOfDay / 12);
					internalSet($Calendar::HOUR, hourOfDay % 12);
				}
				int32_t zoneOffset = d->getZoneOffset();
				int32_t saving = d->getDaylightSaving();
				internalSet($Calendar::ZONE_OFFSET, zoneOffset - saving);
				internalSet($Calendar::DST_OFFSET, saving);
				return;
			}
		}
	case $Calendar::YEAR:
		{
			min = getActualMinimum(field);
			max = getActualMaximum(field);
			break;
		}
	case $Calendar::MONTH:
		{
			{
				if (!this->isTransitionYear($nc(this->jdate)->getNormalizedYear())) {
					int32_t year = $nc(this->jdate)->getYear();
					if (year == getMaximum($Calendar::YEAR)) {
						$var($CalendarDate, jd, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(this->time, $(getZone())));
						$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone())));
						max = $nc(d)->getMonth() - 1;
						int32_t n = getRolledValue(internalGet(field), amount, min, max);
						if (n == max) {
							$nc(jd)->addYear(-400);
							jd->setMonth(n + 1);
							int32_t var$3 = jd->getDayOfMonth();
							if (var$3 > d->getDayOfMonth()) {
								jd->setDayOfMonth(d->getDayOfMonth());
								$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
							}
							int32_t var$5 = jd->getDayOfMonth();
							bool var$4 = var$5 == d->getDayOfMonth();
							if (var$4) {
								int64_t var$6 = jd->getTimeOfDay();
								var$4 = var$6 > d->getTimeOfDay();
							}
							if (var$4) {
								jd->setMonth(n + 1);
								jd->setDayOfMonth(d->getDayOfMonth() - 1);
								$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
								n = jd->getMonth() - 1;
							}
							set($Calendar::DAY_OF_MONTH, jd->getDayOfMonth());
						}
						set($Calendar::MONTH, n);
					} else if (year == getMinimum($Calendar::YEAR)) {
						$var($CalendarDate, jd, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(this->time, $(getZone())));
						$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
						min = $nc(d)->getMonth() - 1;
						int32_t n = getRolledValue(internalGet(field), amount, min, max);
						if (n == min) {
							$nc(jd)->addYear(+400);
							jd->setMonth(n + 1);
							int32_t var$7 = jd->getDayOfMonth();
							if (var$7 < d->getDayOfMonth()) {
								jd->setDayOfMonth(d->getDayOfMonth());
								$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
							}
							int32_t var$9 = jd->getDayOfMonth();
							bool var$8 = var$9 == d->getDayOfMonth();
							if (var$8) {
								int64_t var$10 = jd->getTimeOfDay();
								var$8 = var$10 < d->getTimeOfDay();
							}
							if (var$8) {
								jd->setMonth(n + 1);
								jd->setDayOfMonth(d->getDayOfMonth() + 1);
								$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
								n = jd->getMonth() - 1;
							}
							set($Calendar::DAY_OF_MONTH, jd->getDayOfMonth());
						}
						set($Calendar::MONTH, n);
					} else {
						int32_t mon = (internalGet($Calendar::MONTH) + amount) % 12;
						if (mon < 0) {
							mon += 12;
						}
						set($Calendar::MONTH, mon);
						int32_t monthLen = this->monthLength(mon);
						if (internalGet($Calendar::DAY_OF_MONTH) > monthLen) {
							set($Calendar::DAY_OF_MONTH, monthLen);
						}
					}
				} else {
					int32_t eraIndex = getEraIndex(this->jdate);
					$var($CalendarDate, transition, nullptr);
					if ($nc(this->jdate)->getYear() == 1) {
						$assign(transition, $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex))->getSinceDate());
						min = $nc(transition)->getMonth() - 1;
					} else if (eraIndex < $nc(JapaneseImperialCalendar::eras)->length - 1) {
						$assign(transition, $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex + 1))->getSinceDate());
						int32_t var$11 = $nc(transition)->getYear();
						if (var$11 == $nc(this->jdate)->getNormalizedYear()) {
							max = transition->getMonth() - 1;
							if (transition->getDayOfMonth() == 1) {
								--max;
							}
						}
					}
					if (min == max) {
						return;
					}
					int32_t n = getRolledValue(internalGet(field), amount, min, max);
					set($Calendar::MONTH, n);
					if (n == min) {
						bool var$12 = $nc(transition)->getMonth() == $BaseCalendar::JANUARY;
						if (!(var$12 && transition->getDayOfMonth() == 1)) {
							int32_t var$13 = $nc(this->jdate)->getDayOfMonth();
							if (var$13 < transition->getDayOfMonth()) {
								set($Calendar::DAY_OF_MONTH, transition->getDayOfMonth());
							}
						}
					} else if (n == max && ($nc(transition)->getMonth() - 1 == n)) {
						int32_t dom = transition->getDayOfMonth();
						if ($nc(this->jdate)->getDayOfMonth() >= dom) {
							set($Calendar::DAY_OF_MONTH, dom - 1);
						}
					}
				}
				return;
			}
		}
	case $Calendar::WEEK_OF_YEAR:
		{
			{
				int32_t y = $nc(this->jdate)->getNormalizedYear();
				max = getActualMaximum($Calendar::WEEK_OF_YEAR);
				set($Calendar::DAY_OF_WEEK, internalGet($Calendar::DAY_OF_WEEK));
				int32_t woy = internalGet($Calendar::WEEK_OF_YEAR);
				int32_t value = woy + amount;
				if (!this->isTransitionYear($nc(this->jdate)->getNormalizedYear())) {
					int32_t year = $nc(this->jdate)->getYear();
					if (year == getMaximum($Calendar::YEAR)) {
						max = getActualMaximum($Calendar::WEEK_OF_YEAR);
					} else if (year == getMinimum($Calendar::YEAR)) {
						min = getActualMinimum($Calendar::WEEK_OF_YEAR);
						max = getActualMaximum($Calendar::WEEK_OF_YEAR);
						if (value > min && value < max) {
							set($Calendar::WEEK_OF_YEAR, value);
							return;
						}
					}
					if (value > min && value < max) {
						set($Calendar::WEEK_OF_YEAR, value);
						return;
					}
					int64_t fd = this->cachedFixedDate;
					int64_t day1 = fd - (7 * (woy - min));
					if (year != getMinimum($Calendar::YEAR)) {
						if ($nc(JapaneseImperialCalendar::gcal)->getYearFromFixedDate(day1) != y) {
							++min;
						}
					} else {
						$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
						if (day1 < $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d)) {
							++min;
						}
					}
					fd += 7 * (max - internalGet($Calendar::WEEK_OF_YEAR));
					if ($nc(JapaneseImperialCalendar::gcal)->getYearFromFixedDate(fd) != y) {
						--max;
					}
					break;
				}
				int64_t fd = this->cachedFixedDate;
				int64_t day1 = fd - (7 * (woy - min));
				$var($LocalGregorianCalendar$Date, d, getCalendarDate(day1));
				bool var$14 = $nc(d)->getEra() == $nc(this->jdate)->getEra();
				if (var$14) {
					int32_t var$15 = d->getYear();
					var$14 = var$15 == $nc(this->jdate)->getYear();
				}
				if (!(var$14)) {
					++min;
				}
				fd += 7 * (max - woy);
				$nc(JapaneseImperialCalendar::jcal)->getCalendarDateFromFixedDate(d, fd);
				bool var$16 = $nc(d)->getEra() == $nc(this->jdate)->getEra();
				if (var$16) {
					int32_t var$17 = d->getYear();
					var$16 = var$17 == $nc(this->jdate)->getYear();
				}
				if (!(var$16)) {
					--max;
				}
				value = getRolledValue(woy, amount, min, max) - 1;
				$assign(d, getCalendarDate(day1 + value * 7));
				set($Calendar::MONTH, $nc(d)->getMonth() - 1);
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	case $Calendar::WEEK_OF_MONTH:
		{
			{
				bool isTransitionYear = this->isTransitionYear($nc(this->jdate)->getNormalizedYear());
				int32_t var$18 = internalGet($Calendar::DAY_OF_WEEK);
				int32_t dow = var$18 - getFirstDayOfWeek();
				if (dow < 0) {
					dow += 7;
				}
				int64_t fd = this->cachedFixedDate;
				int64_t month1 = 0;
				int32_t monthLength = 0;
				if (isTransitionYear) {
					month1 = getFixedDateMonth1(this->jdate, fd);
					monthLength = actualMonthLength();
				} else {
					month1 = fd - internalGet($Calendar::DAY_OF_MONTH) + 1;
					monthLength = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(this->jdate);
				}
				int64_t monthDay1st = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(month1 + 6, getFirstDayOfWeek());
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
				set($Calendar::DAY_OF_MONTH, $nc($(getCalendarDate(nfd)))->getDayOfMonth());
				return;
			}
		}
	case $Calendar::DAY_OF_MONTH:
		{
			{
				if (!this->isTransitionYear($nc(this->jdate)->getNormalizedYear())) {
					max = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(this->jdate);
					break;
				}
				int64_t month1 = getFixedDateMonth1(this->jdate, this->cachedFixedDate);
				int32_t value = getRolledValue((int32_t)(this->cachedFixedDate - month1), amount, 0, actualMonthLength() - 1);
				$var($LocalGregorianCalendar$Date, d, getCalendarDate(month1 + value));
				bool var$19 = !JapaneseImperialCalendar::$assertionsDisabled;
				if (var$19) {
					int32_t var$22 = getEraIndex(d);
					bool var$21 = var$22 == internalGetEra();
					if (var$21) {
						int32_t var$23 = $nc(d)->getYear();
						var$21 = var$23 == internalGet($Calendar::YEAR);
					}
					bool var$20 = var$21;
					if (var$20) {
						int32_t var$24 = d->getMonth() - 1;
						var$20 = var$24 == internalGet($Calendar::MONTH);
					}
					var$19 = !var$20;
				}
				if (var$19) {
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
				if (!this->isTransitionYear($nc(this->jdate)->getNormalizedYear())) {
					break;
				}
				int32_t value = getRolledValue(internalGet($Calendar::DAY_OF_YEAR), amount, min, max);
				int64_t jan0 = this->cachedFixedDate - internalGet($Calendar::DAY_OF_YEAR);
				$var($LocalGregorianCalendar$Date, d, getCalendarDate(jan0 + value));
				bool var$25 = !JapaneseImperialCalendar::$assertionsDisabled;
				if (var$25) {
					int32_t var$27 = getEraIndex(d);
					bool var$26 = var$27 == internalGetEra();
					if (var$26) {
						int32_t var$28 = $nc(d)->getYear();
						var$26 = var$28 == internalGet($Calendar::YEAR);
					}
					var$25 = !var$26;
				}
				if (var$25) {
					$throwNew($AssertionError);
				}
				set($Calendar::MONTH, $nc(d)->getMonth() - 1);
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	case $Calendar::DAY_OF_WEEK:
		{
			{
				int32_t normalizedYear = $nc(this->jdate)->getNormalizedYear();
				bool var$29 = !this->isTransitionYear(normalizedYear);
				if (var$29 && !this->isTransitionYear(normalizedYear - 1)) {
					int32_t weekOfYear = internalGet($Calendar::WEEK_OF_YEAR);
					if (weekOfYear > 1 && weekOfYear < 52) {
						set($Calendar::WEEK_OF_YEAR, internalGet($Calendar::WEEK_OF_YEAR));
						max = $Calendar::SATURDAY;
						break;
					}
				}
				$modAssign(amount, 7);
				if (amount == 0) {
					return;
				}
				int64_t fd = this->cachedFixedDate;
				int64_t dowFirst = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(fd, getFirstDayOfWeek());
				fd += amount;
				if (fd < dowFirst) {
					fd += 7;
				} else if (fd >= dowFirst + 7) {
					fd -= 7;
				}
				$var($LocalGregorianCalendar$Date, d, getCalendarDate(fd));
				set($Calendar::ERA, getEraIndex(d));
				int32_t var$30 = $nc(d)->getYear();
				int32_t var$31 = d->getMonth() - 1;
				set(var$30, var$31, d->getDayOfMonth());
				return;
			}
		}
	case $Calendar::DAY_OF_WEEK_IN_MONTH:
		{
			{
				min = 1;
				if (!this->isTransitionYear($nc(this->jdate)->getNormalizedYear())) {
					int32_t dom = internalGet($Calendar::DAY_OF_MONTH);
					int32_t monthLength = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(this->jdate);
					int32_t lastDays = monthLength % 7;
					max = monthLength / 7;
					int32_t x = (dom - 1) % 7;
					if (x < lastDays) {
						++max;
					}
					set($Calendar::DAY_OF_WEEK, internalGet($Calendar::DAY_OF_WEEK));
					break;
				}
				int64_t fd = this->cachedFixedDate;
				int64_t month1 = getFixedDateMonth1(this->jdate, fd);
				int32_t monthLength = actualMonthLength();
				int32_t lastDays = monthLength % 7;
				max = monthLength / 7;
				int32_t x = (int32_t)(fd - month1) % 7;
				if (x < lastDays) {
					++max;
				}
				int32_t value = getRolledValue(internalGet(field), amount, min, max) - 1;
				fd = month1 + value * 7 + x;
				$var($LocalGregorianCalendar$Date, d, getCalendarDate(fd));
				set($Calendar::DAY_OF_MONTH, $nc(d)->getDayOfMonth());
				return;
			}
		}
	}
	set(field, getRolledValue(internalGet(field), amount, min, max));
}

$String* JapaneseImperialCalendar::getDisplayName(int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (!checkDisplayNameParams(field, style, $Calendar::SHORT, $Calendar::NARROW_FORMAT, locale, ((($Calendar::ERA_MASK | $Calendar::YEAR_MASK) | $Calendar::MONTH_MASK) | $Calendar::DAY_OF_WEEK_MASK) | $Calendar::AM_PM_MASK)) {
		return nullptr;
	}
	int32_t fieldValue = get(field);
	bool var$0 = field == $Calendar::YEAR;
	if (var$0) {
		bool var$1 = getBaseStyle(style) != $Calendar::LONG || fieldValue != 1;
		var$0 = (var$1 || get($Calendar::ERA) == 0);
	}
	if (var$0) {
		return nullptr;
	}
	$var($String, name, $CalendarDataUtility::retrieveFieldValueName($(getCalendarType()), field, fieldValue, style, locale));
	if ((name == nullptr || $nc(name)->isEmpty()) && field == $Calendar::ERA && fieldValue < $nc(JapaneseImperialCalendar::eras)->length) {
		$var($Era, era, $nc(JapaneseImperialCalendar::eras)->get(fieldValue));
		$assign(name, (style == $Calendar::SHORT) ? $nc(era)->getAbbreviation() : era->getName());
	}
	return name;
}

$Map* JapaneseImperialCalendar::getDisplayNames(int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (!checkDisplayNameParams(field, style, $Calendar::ALL_STYLES, $Calendar::NARROW_FORMAT, locale, ((($Calendar::ERA_MASK | $Calendar::YEAR_MASK) | $Calendar::MONTH_MASK) | $Calendar::DAY_OF_WEEK_MASK) | $Calendar::AM_PM_MASK)) {
		return nullptr;
	}
	$var($Map, names, nullptr);
	$assign(names, $CalendarDataUtility::retrieveFieldValueNames($(getCalendarType()), field, style, locale));
	if (names != nullptr) {
		if (field == $Calendar::ERA) {
			int32_t size = names->size();
			if (style == $Calendar::ALL_STYLES) {
				$var($Set, values, $new($HashSet));
				{
					$var($Iterator, i$, $nc($(names->keySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, key, $cast($String, i$->next()));
						{
							values->add($cast($Integer, $(names->get(key))));
						}
					}
				}
				size = values->size();
			}
			if (size < $nc(JapaneseImperialCalendar::eras)->length) {
				int32_t baseStyle = getBaseStyle(style);
				for (int32_t i = 0; i < $nc(JapaneseImperialCalendar::eras)->length; ++i) {
					if (!$nc($(names->values()))->contains($($Integer::valueOf(i)))) {
						$var($Era, era, $nc(JapaneseImperialCalendar::eras)->get(i));
						if (baseStyle == $Calendar::ALL_STYLES || baseStyle == $Calendar::SHORT || baseStyle == $Calendar::NARROW_FORMAT) {
							$var($Object, var$0, $of($nc(era)->getAbbreviation()));
							names->put(var$0, $($Integer::valueOf(i)));
						}
						if (baseStyle == $Calendar::ALL_STYLES || baseStyle == $Calendar::LONG) {
							$var($Object, var$1, $of($nc(era)->getName()));
							names->put(var$1, $($Integer::valueOf(i)));
						}
					}
				}
			}
		}
	}
	return names;
}

int32_t JapaneseImperialCalendar::getMinimum(int32_t field) {
	return $nc(JapaneseImperialCalendar::MIN_VALUES)->get(field);
}

int32_t JapaneseImperialCalendar::getMaximum(int32_t field) {
	$useLocalCurrentObjectStackCache();

	int32_t var$0 = 0;
	switch (field) {
	case $Calendar::YEAR:
		{
			{
				$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone()))));
				var$0 = $Math::max($nc(JapaneseImperialCalendar::LEAST_MAX_VALUES)->get($Calendar::YEAR), $nc(d)->getYear());
				break;
			}
		}
	default:
		{
			var$0 = $nc(JapaneseImperialCalendar::MAX_VALUES)->get(field);
			break;
		}
	}
	return var$0;
}

int32_t JapaneseImperialCalendar::getGreatestMinimum(int32_t field) {
	return field == $Calendar::YEAR ? 1 : $nc(JapaneseImperialCalendar::MIN_VALUES)->get(field);
}

int32_t JapaneseImperialCalendar::getLeastMaximum(int32_t field) {

	int32_t var$0 = 0;
	switch (field) {
	case $Calendar::YEAR:
		{
			var$0 = $Math::min($nc(JapaneseImperialCalendar::LEAST_MAX_VALUES)->get($Calendar::YEAR), getMaximum($Calendar::YEAR));
			break;
		}
	default:
		{
			var$0 = $nc(JapaneseImperialCalendar::LEAST_MAX_VALUES)->get(field);
			break;
		}
	}
	return var$0;
}

int32_t JapaneseImperialCalendar::getActualMinimum(int32_t field) {
	$useLocalCurrentObjectStackCache();
	if (!isFieldSet(($Calendar::YEAR_MASK | $Calendar::MONTH_MASK) | $Calendar::WEEK_OF_YEAR_MASK, field)) {
		return getMinimum(field);
	}
	int32_t value = 0;
	$var(JapaneseImperialCalendar, jc, getNormalizedCalendar());
	int64_t var$0 = $nc(jc)->getTimeInMillis();
	$var($LocalGregorianCalendar$Date, jd, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(var$0, $(getZone()))));
	int32_t eraIndex = getEraIndex(jd);
	switch (field) {
	case $Calendar::YEAR:
		{
			{
				if (eraIndex > JapaneseImperialCalendar::BEFORE_MEIJI) {
					value = 1;
					int64_t since = $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex))->getSince($(getZone()));
					$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(since, $(getZone())));
					$nc(jd)->setYear($nc(d)->getYear());
					$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
					bool var$1 = !JapaneseImperialCalendar::$assertionsDisabled;
					if (var$1) {
						bool var$2 = jd->isLeapYear();
						var$1 = !(var$2 == $nc(d)->isLeapYear());
					}
					if (var$1) {
						$throwNew($AssertionError);
					}
					int64_t var$3 = getYearOffsetInMillis(jd);
					if (var$3 < getYearOffsetInMillis(d)) {
						++value;
					}
				} else {
					value = getMinimum(field);
					$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
					int32_t y = $nc(d)->getYear();
					if (y > 400) {
						y -= 400;
					}
					$nc(jd)->setYear(y);
					$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
					int64_t var$4 = getYearOffsetInMillis(jd);
					if (var$4 < getYearOffsetInMillis(d)) {
						++value;
					}
				}
			}
			break;
		}
	case $Calendar::MONTH:
		{
			{
				if (eraIndex > JapaneseImperialCalendar::MEIJI && $nc(jd)->getYear() == 1) {
					int64_t since = $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex))->getSince($(getZone()));
					$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(since, $(getZone())));
					value = $nc(d)->getMonth() - 1;
					int32_t var$5 = jd->getDayOfMonth();
					if (var$5 < d->getDayOfMonth()) {
						++value;
					}
				}
			}
			break;
		}
	case $Calendar::WEEK_OF_YEAR:
		{
			{
				value = 1;
				$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
				$nc(d)->addYear(+400);
				$nc(JapaneseImperialCalendar::jcal)->normalize(d);
				$nc(jd)->setEra($(d->getEra()));
				jd->setYear(d->getYear());
				$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
				int64_t jan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
				int64_t fd = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(jd);
				int32_t woy = getWeekNumber(jan1, fd);
				int64_t day1 = fd - (7 * (woy - 1));
				bool var$6 = (day1 < jan1);
				if (!var$6) {
					bool var$7 = day1 == jan1;
					if (var$7) {
						int64_t var$8 = jd->getTimeOfDay();
						var$7 = var$8 < d->getTimeOfDay();
					}
					var$6 = (var$7);
				}
				if (var$6) {
					++value;
				}
			}
			break;
		}
	}
	return value;
}

int32_t JapaneseImperialCalendar::getActualMaximum(int32_t field) {
	$useLocalCurrentObjectStackCache();
	int32_t fieldsForFixedMax = (((((((($Calendar::ERA_MASK | $Calendar::DAY_OF_WEEK_MASK) | $Calendar::HOUR_MASK) | $Calendar::AM_PM_MASK) | $Calendar::HOUR_OF_DAY_MASK) | $Calendar::MINUTE_MASK) | $Calendar::SECOND_MASK) | $Calendar::MILLISECOND_MASK) | $Calendar::ZONE_OFFSET_MASK) | $Calendar::DST_OFFSET_MASK;
	if (((int32_t)(fieldsForFixedMax & (uint32_t)($sl(1, field)))) != 0) {
		return getMaximum(field);
	}
	$var(JapaneseImperialCalendar, jc, getNormalizedCalendar());
	$var($LocalGregorianCalendar$Date, date, $nc(jc)->jdate);

	int32_t var$0 = 0;
	switch (field) {
	case $Calendar::MONTH:
		{
			{
				int32_t month = $Calendar::DECEMBER;
				if (isTransitionYear($nc(date)->getNormalizedYear())) {
					int32_t eraIndex = getEraIndex(date);
					if ($nc(date)->getYear() != 1) {
						++eraIndex;
						if (!JapaneseImperialCalendar::$assertionsDisabled && !(eraIndex < $nc(JapaneseImperialCalendar::eras)->length)) {
							$throwNew($AssertionError);
						}
					}
					int64_t transition = $nc(JapaneseImperialCalendar::sinceFixedDates)->get(eraIndex);
					int64_t fd = jc->cachedFixedDate;
					if (fd < transition) {
						$var($LocalGregorianCalendar$Date, ldate, $cast($LocalGregorianCalendar$Date, $nc(date)->clone()));
						$nc(JapaneseImperialCalendar::jcal)->getCalendarDateFromFixedDate(ldate, transition - 1);
						month = $nc(ldate)->getMonth() - 1;
					}
				} else {
					$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone()))));
					bool var$1 = $nc(date)->getEra() == $nc(d)->getEra();
					if (var$1) {
						int32_t var$2 = date->getYear();
						var$1 = var$2 == d->getYear();
					}
					if (var$1) {
						month = d->getMonth() - 1;
					}
				}
				var$0 = month;
				break;
			}
		}
	case $Calendar::DAY_OF_MONTH:
		{
			var$0 = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(date);
			break;
		}
	case $Calendar::DAY_OF_YEAR:
		{
			{
				if (isTransitionYear($nc(date)->getNormalizedYear())) {
					int32_t eraIndex = getEraIndex(date);
					if ($nc(date)->getYear() != 1) {
						++eraIndex;
						if (!JapaneseImperialCalendar::$assertionsDisabled && !(eraIndex < $nc(JapaneseImperialCalendar::eras)->length)) {
							$throwNew($AssertionError);
						}
					}
					int64_t transition = $nc(JapaneseImperialCalendar::sinceFixedDates)->get(eraIndex);
					int64_t fd = jc->cachedFixedDate;
					$init($TimeZone);
					$var($CalendarDate, d, $nc(JapaneseImperialCalendar::gcal)->newCalendarDate($TimeZone::NO_TIMEZONE));
					$nc(d)->setDate($nc(date)->getNormalizedYear(), $BaseCalendar::JANUARY, 1);
					if (fd < transition) {
						var$0 = (int32_t)(transition - $nc(JapaneseImperialCalendar::gcal)->getFixedDate(d));
						break;
					}
					d->addYear(1);
					var$0 = (int32_t)($nc(JapaneseImperialCalendar::gcal)->getFixedDate(d) - transition);
					break;
				}
				$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone()))));
				bool var$3 = $nc(date)->getEra() == $nc(d)->getEra();
				if (var$3) {
					int32_t var$4 = date->getYear();
					var$3 = var$4 == d->getYear();
				}
				if (var$3) {
					int64_t fd = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
					int64_t jan1 = getFixedDateJan1(d, fd);
					var$0 = (int32_t)(fd - jan1) + 1;
					break;
				} else {
					int32_t var$6 = date->getYear();
					if (var$6 == getMinimum($Calendar::YEAR)) {
						$var($CalendarDate, d1, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
						int64_t fd1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d1);
						$nc(d1)->addYear(1);
						$nc($(d1->setMonth($BaseCalendar::JANUARY)))->setDayOfMonth(1);
						$nc(JapaneseImperialCalendar::jcal)->normalize(d1);
						int64_t fd2 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d1);
						var$0 = (int32_t)(fd2 - fd1);
						break;
					} else {
						var$0 = $nc(JapaneseImperialCalendar::jcal)->getYearLength(date);
						break;
					}
				}
			}
		}
	case $Calendar::WEEK_OF_YEAR:
		{
			{
				if (!isTransitionYear($nc(date)->getNormalizedYear())) {
					$var($LocalGregorianCalendar$Date, jd, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone()))));
					bool var$7 = $nc(date)->getEra() == $nc(jd)->getEra();
					if (var$7) {
						int32_t var$8 = date->getYear();
						var$7 = var$8 == jd->getYear();
					}
					if (var$7) {
						int64_t fd = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(jd);
						int64_t jan1 = getFixedDateJan1(jd, fd);
						var$0 = getWeekNumber(jan1, fd);
						break;
					} else {
						bool var$11 = date->getEra() == nullptr;
						if (var$11) {
							int32_t var$12 = date->getYear();
							var$11 = var$12 == getMinimum($Calendar::YEAR);
						}
						if (var$11) {
							$var($CalendarDate, d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
							$nc(d)->addYear(+400);
							$nc(JapaneseImperialCalendar::jcal)->normalize(d);
							jd->setEra($(d->getEra()));
							jd->setDate(d->getYear() + 1, $BaseCalendar::JANUARY, 1);
							$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
							int64_t jan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
							int64_t nextJan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(jd);
							int64_t nextJan1st = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(nextJan1 + 6, getFirstDayOfWeek());
							int32_t ndays = (int32_t)(nextJan1st - nextJan1);
							if (ndays >= getMinimalDaysInFirstWeek()) {
								nextJan1st -= 7;
							}
							var$0 = getWeekNumber(jan1, nextJan1st);
							break;
						}
					}
					$init($TimeZone);
					$var($CalendarDate, d, $nc(JapaneseImperialCalendar::gcal)->newCalendarDate($TimeZone::NO_TIMEZONE));
					$nc(d)->setDate($nc(date)->getNormalizedYear(), $BaseCalendar::JANUARY, 1);
					int32_t dayOfWeek = $nc(JapaneseImperialCalendar::gcal)->getDayOfWeek(d);
					dayOfWeek -= getFirstDayOfWeek();
					if (dayOfWeek < 0) {
						dayOfWeek += 7;
					}
					int32_t magic = dayOfWeek + getMinimalDaysInFirstWeek() - 1;
					if ((magic == 6) || ($nc(date)->isLeapYear() && (magic == 5 || magic == 12))) {
						var$0 = 53;
						break;
					}
					var$0 = 52;
					break;
				}
				if (jc == this) {
					$assign(jc, $cast(JapaneseImperialCalendar, jc->clone()));
				}
				int32_t max = getActualMaximum($Calendar::DAY_OF_YEAR);
				jc->set($Calendar::DAY_OF_YEAR, max);
				int32_t weekOfYear = jc->get($Calendar::WEEK_OF_YEAR);
				if (weekOfYear == 1 && max > 7) {
					jc->add($Calendar::WEEK_OF_YEAR, -1);
					weekOfYear = jc->get($Calendar::WEEK_OF_YEAR);
				}
				var$0 = weekOfYear;
				break;
			}
		}
	case $Calendar::WEEK_OF_MONTH:
		{
			{
				$var($LocalGregorianCalendar$Date, jd, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone()))));
				bool var$13 = $nc(date)->getEra() == $nc(jd)->getEra();
				if (var$13) {
					int32_t var$14 = date->getYear();
					var$13 = var$14 == jd->getYear();
				}
				if (var$13) {
					int64_t fd = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(jd);
					int64_t month1 = fd - jd->getDayOfMonth() + 1;
					var$0 = getWeekNumber(month1, fd);
					break;
				}
				$init($TimeZone);
				$var($CalendarDate, d, $nc(JapaneseImperialCalendar::gcal)->newCalendarDate($TimeZone::NO_TIMEZONE));
				int32_t var$15 = $nc(date)->getNormalizedYear();
				$nc(d)->setDate(var$15, date->getMonth(), 1);
				int32_t dayOfWeek = $nc(JapaneseImperialCalendar::gcal)->getDayOfWeek(d);
				int32_t monthLength = actualMonthLength();
				dayOfWeek -= getFirstDayOfWeek();
				if (dayOfWeek < 0) {
					dayOfWeek += 7;
				}
				int32_t nDaysFirstWeek = 7 - dayOfWeek;
				int32_t weekOfMonth = 3;
				if (nDaysFirstWeek >= getMinimalDaysInFirstWeek()) {
					++weekOfMonth;
				}
				monthLength -= nDaysFirstWeek + 7 * 3;
				if (monthLength > 0) {
					++weekOfMonth;
					if (monthLength > 7) {
						++weekOfMonth;
					}
				}
				var$0 = weekOfMonth;
				break;
			}
		}
	case $Calendar::DAY_OF_WEEK_IN_MONTH:
		{
			{
				int32_t ndays = 0;
				int32_t dow1 = 0;
				int32_t dow = $nc(date)->getDayOfWeek();
				$var($BaseCalendar$Date, d, $cast($BaseCalendar$Date, date->clone()));
				ndays = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(d);
				$nc(d)->setDayOfMonth(1);
				$nc(JapaneseImperialCalendar::jcal)->normalize(d);
				dow1 = d->getDayOfWeek();
				int32_t x = dow - dow1;
				if (x < 0) {
					x += 7;
				}
				ndays -= x;
				var$0 = (ndays + 6) / 7;
				break;
			}
		}
	case $Calendar::YEAR:
		{
			{
				int64_t var$16 = jc->getTimeInMillis();
				$var($CalendarDate, jd, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(var$16, $(getZone())));
				$var($CalendarDate, d, nullptr);
				int32_t eraIndex = getEraIndex(date);
				int32_t year = 0;
				if (eraIndex == $nc(JapaneseImperialCalendar::eras)->length - 1) {
					$assign(d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MAX_VALUE, $(getZone())));
					year = $nc(d)->getYear();
					if (year > 400) {
						$nc(jd)->setYear(year - 400);
					}
				} else {
					int64_t var$17 = $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex + 1))->getSince($(getZone())) - 1;
					$assign(d, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(var$17, $(getZone())));
					year = $nc(d)->getYear();
					$nc(jd)->setYear(year);
				}
				$nc(JapaneseImperialCalendar::jcal)->normalize(jd);
				int64_t var$18 = getYearOffsetInMillis(jd);
				if (var$18 > getYearOffsetInMillis(d)) {
					--year;
				}
				var$0 = year;
				break;
			}
		}
	default:
		{
			$throwNew($ArrayIndexOutOfBoundsException, field);
		}
	}
	return var$0;
}

int64_t JapaneseImperialCalendar::getYearOffsetInMillis($CalendarDate* date) {
	int64_t t = ($nc(JapaneseImperialCalendar::jcal)->getDayOfYear(date) - 1) * JapaneseImperialCalendar::ONE_DAY;
	int64_t var$0 = t + $nc(date)->getTimeOfDay();
	return var$0 - date->getZoneOffset();
}

$Object* JapaneseImperialCalendar::clone() {
	$var(JapaneseImperialCalendar, other, $cast(JapaneseImperialCalendar, $Calendar::clone()));
	$set($nc(other), jdate, $cast($LocalGregorianCalendar$Date, $nc(this->jdate)->clone()));
	$set(other, originalFields, nullptr);
	$set(other, zoneOffsets, nullptr);
	return $of(other);
}

$TimeZone* JapaneseImperialCalendar::getTimeZone() {
	$var($TimeZone, zone, $Calendar::getTimeZone());
	$nc(this->jdate)->setZone(zone);
	return zone;
}

void JapaneseImperialCalendar::setTimeZone($TimeZone* zone) {
	$Calendar::setTimeZone(zone);
	$nc(this->jdate)->setZone(zone);
}

void JapaneseImperialCalendar::computeFields() {
	int32_t mask = 0;
	if (isPartiallyNormalized()) {
		mask = getSetStateFields();
		int32_t fieldMask = (int32_t)(~mask & (uint32_t)$Calendar::ALL_FIELDS);
		if (fieldMask != 0 || this->cachedFixedDate == $Long::MIN_VALUE) {
			mask |= computeFields(fieldMask, (int32_t)(mask & (uint32_t)($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK)));
			if (!JapaneseImperialCalendar::$assertionsDisabled && !(mask == $Calendar::ALL_FIELDS)) {
				$throwNew($AssertionError);
			}
		}
	} else {
		mask = $Calendar::ALL_FIELDS;
		computeFields(mask, 0);
	}
	setFieldsComputed(mask);
}

int32_t JapaneseImperialCalendar::computeFields(int32_t fieldMask, int32_t tzMask) {
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
	int64_t fixedDate = $div(zoneOffset, JapaneseImperialCalendar::ONE_DAY);
	int32_t timeOfDay = $mod(zoneOffset, (int32_t)JapaneseImperialCalendar::ONE_DAY);
	fixedDate += $div(this->time, JapaneseImperialCalendar::ONE_DAY);
	timeOfDay += (int32_t)($mod(this->time, JapaneseImperialCalendar::ONE_DAY));
	if (timeOfDay >= JapaneseImperialCalendar::ONE_DAY) {
		timeOfDay -= JapaneseImperialCalendar::ONE_DAY;
		++fixedDate;
	} else {
		while (timeOfDay < 0) {
			timeOfDay += JapaneseImperialCalendar::ONE_DAY;
			--fixedDate;
		}
	}
	fixedDate += JapaneseImperialCalendar::EPOCH_OFFSET;
	if (fixedDate != this->cachedFixedDate || fixedDate < 0) {
		$nc(JapaneseImperialCalendar::jcal)->getCalendarDateFromFixedDate(this->jdate, fixedDate);
		this->cachedFixedDate = fixedDate;
	}
	int32_t era = getEraIndex(this->jdate);
	int32_t year = $nc(this->jdate)->getYear();
	internalSet($Calendar::ERA, era);
	internalSet($Calendar::YEAR, year);
	int32_t mask = fieldMask | ($Calendar::ERA_MASK | $Calendar::YEAR_MASK);
	int32_t month = $nc(this->jdate)->getMonth() - 1;
	int32_t dayOfMonth = $nc(this->jdate)->getDayOfMonth();
	if (((int32_t)(fieldMask & (uint32_t)(($Calendar::MONTH_MASK | $Calendar::DAY_OF_MONTH_MASK) | $Calendar::DAY_OF_WEEK_MASK))) != 0) {
		internalSet($Calendar::MONTH, month);
		internalSet($Calendar::DAY_OF_MONTH, dayOfMonth);
		internalSet($Calendar::DAY_OF_WEEK, $nc(this->jdate)->getDayOfWeek());
		mask |= ($Calendar::MONTH_MASK | $Calendar::DAY_OF_MONTH_MASK) | $Calendar::DAY_OF_WEEK_MASK;
	}
	if (((int32_t)(fieldMask & (uint32_t)((((($Calendar::HOUR_OF_DAY_MASK | $Calendar::AM_PM_MASK) | $Calendar::HOUR_MASK) | $Calendar::MINUTE_MASK) | $Calendar::SECOND_MASK) | $Calendar::MILLISECOND_MASK))) != 0) {
		if (timeOfDay != 0) {
			int32_t hours = $div(timeOfDay, JapaneseImperialCalendar::ONE_HOUR);
			internalSet($Calendar::HOUR_OF_DAY, hours);
			internalSet($Calendar::AM_PM, hours / 12);
			internalSet($Calendar::HOUR, hours % 12);
			int32_t r = $mod(timeOfDay, JapaneseImperialCalendar::ONE_HOUR);
			internalSet($Calendar::MINUTE, $div(r, JapaneseImperialCalendar::ONE_MINUTE));
			$modAssign(r, JapaneseImperialCalendar::ONE_MINUTE);
			internalSet($Calendar::SECOND, $div(r, JapaneseImperialCalendar::ONE_SECOND));
			internalSet($Calendar::MILLISECOND, $mod(r, JapaneseImperialCalendar::ONE_SECOND));
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
		int32_t normalizedYear = $nc(this->jdate)->getNormalizedYear();
		bool transitionYear = isTransitionYear($nc(this->jdate)->getNormalizedYear());
		int32_t dayOfYear = 0;
		int64_t fixedDateJan1 = 0;
		if (transitionYear) {
			fixedDateJan1 = getFixedDateJan1(this->jdate, fixedDate);
			dayOfYear = (int32_t)(fixedDate - fixedDateJan1) + 1;
		} else if (normalizedYear == $nc(JapaneseImperialCalendar::MIN_VALUES)->get($Calendar::YEAR)) {
			$var($CalendarDate, dx, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
			fixedDateJan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(dx);
			dayOfYear = (int32_t)(fixedDate - fixedDateJan1) + 1;
		} else {
			dayOfYear = (int32_t)$nc(JapaneseImperialCalendar::jcal)->getDayOfYear(this->jdate);
			fixedDateJan1 = fixedDate - dayOfYear + 1;
		}
		int64_t fixedDateMonth1 = transitionYear ? getFixedDateMonth1(this->jdate, fixedDate) : fixedDate - dayOfMonth + 1;
		internalSet($Calendar::DAY_OF_YEAR, dayOfYear);
		internalSet($Calendar::DAY_OF_WEEK_IN_MONTH, (dayOfMonth - 1) / 7 + 1);
		int32_t weekOfYear = getWeekNumber(fixedDateJan1, fixedDate);
		if (weekOfYear == 0) {
			int64_t fixedDec31 = fixedDateJan1 - 1;
			int64_t prevJan1 = 0;
			$var($LocalGregorianCalendar$Date, d, getCalendarDate(fixedDec31));
			if (!(transitionYear || isTransitionYear($nc(d)->getNormalizedYear()))) {
				prevJan1 = fixedDateJan1 - 365;
				if ($nc(d)->isLeapYear()) {
					--prevJan1;
				}
			} else if (transitionYear) {
				if ($nc(this->jdate)->getYear() == 1) {
					if (era > JapaneseImperialCalendar::REIWA) {
						$var($CalendarDate, pd, $nc($nc(JapaneseImperialCalendar::eras)->get(era - 1))->getSinceDate());
						if (normalizedYear == $nc(pd)->getYear()) {
							$nc($($nc(d)->setMonth(pd->getMonth())))->setDayOfMonth(pd->getDayOfMonth());
						}
					} else {
						$nc($($nc(d)->setMonth($LocalGregorianCalendar::JANUARY)))->setDayOfMonth(1);
					}
					$nc(JapaneseImperialCalendar::jcal)->normalize(d);
					prevJan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
				} else {
					prevJan1 = fixedDateJan1 - 365;
					if ($nc(d)->isLeapYear()) {
						--prevJan1;
					}
				}
			} else {
				$var($CalendarDate, cd, $nc($nc(JapaneseImperialCalendar::eras)->get(getEraIndex(this->jdate)))->getSinceDate());
				$nc($($nc(d)->setMonth($nc(cd)->getMonth())))->setDayOfMonth($nc(cd)->getDayOfMonth());
				$nc(JapaneseImperialCalendar::jcal)->normalize(d);
				prevJan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
			}
			weekOfYear = getWeekNumber(prevJan1, fixedDec31);
		} else if (!transitionYear) {
			if (weekOfYear >= 52) {
				int64_t nextJan1 = fixedDateJan1 + 365;
				if ($nc(this->jdate)->isLeapYear()) {
					++nextJan1;
				}
				int64_t nextJan1st = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(nextJan1 + 6, getFirstDayOfWeek());
				int32_t ndays = (int32_t)(nextJan1st - nextJan1);
				if (ndays >= getMinimalDaysInFirstWeek() && fixedDate >= (nextJan1st - 7)) {
					weekOfYear = 1;
				}
			}
		} else {
			$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(this->jdate)->clone()));
			int64_t nextJan1 = 0;
			if ($nc(this->jdate)->getYear() == 1) {
				$nc(d)->addYear(+1);
				$nc($(d->setMonth($LocalGregorianCalendar::JANUARY)))->setDayOfMonth(1);
				nextJan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
			} else {
				int32_t nextEraIndex = getEraIndex(d) + 1;
				$var($CalendarDate, cd, $nc($nc(JapaneseImperialCalendar::eras)->get(nextEraIndex))->getSinceDate());
				$nc(d)->setEra($nc(JapaneseImperialCalendar::eras)->get(nextEraIndex));
				int32_t var$0 = $nc(cd)->getMonth();
				d->setDate(1, var$0, cd->getDayOfMonth());
				$nc(JapaneseImperialCalendar::jcal)->normalize(d);
				nextJan1 = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(d);
			}
			int64_t nextJan1st = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(nextJan1 + 6, getFirstDayOfWeek());
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

int32_t JapaneseImperialCalendar::getWeekNumber(int64_t fixedDay1, int64_t fixedDate) {
	int64_t fixedDay1st = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(fixedDay1 + 6, getFirstDayOfWeek());
	int32_t ndays = (int32_t)(fixedDay1st - fixedDay1);
	if (!JapaneseImperialCalendar::$assertionsDisabled && !(ndays <= 7)) {
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

void JapaneseImperialCalendar::computeTime() {
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
	int32_t year = 0;
	int32_t era = 0;
	if (isSet($Calendar::ERA)) {
		era = internalGet($Calendar::ERA);
		year = isSet($Calendar::YEAR) ? internalGet($Calendar::YEAR) : 1;
	} else if (isSet($Calendar::YEAR)) {
		era = JapaneseImperialCalendar::currentEra;
		year = internalGet($Calendar::YEAR);
	} else {
		era = JapaneseImperialCalendar::SHOWA;
		year = 45;
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
	int64_t fixedDate = $div(timeOfDay, JapaneseImperialCalendar::ONE_DAY);
	$modAssign(timeOfDay, JapaneseImperialCalendar::ONE_DAY);
	while (timeOfDay < 0) {
		timeOfDay += JapaneseImperialCalendar::ONE_DAY;
		--fixedDate;
	}
	fixedDate += getFixedDate(era, year, fieldMask);
	int64_t millis = (fixedDate - JapaneseImperialCalendar::EPOCH_OFFSET) * JapaneseImperialCalendar::ONE_DAY + timeOfDay;
	$var($TimeZone, zone, getZone());
	if (this->zoneOffsets == nullptr) {
		$set(this, zoneOffsets, $new($ints, 2));
	}
	int32_t tzMask = (int32_t)(fieldMask & (uint32_t)($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK));
	if (tzMask != ($Calendar::ZONE_OFFSET_MASK | $Calendar::DST_OFFSET_MASK)) {
		if ($instanceOf($ZoneInfo, zone)) {
			$nc(($cast($ZoneInfo, zone)))->getOffsetsByWall(millis, this->zoneOffsets);
		} else {
			$nc(zone)->getOffsets(millis - zone->getRawOffset(), this->zoneOffsets);
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
				int32_t wrongValue = internalGet(field);
				$System::arraycopy(this->originalFields, 0, this->fields, 0, $nc(this->fields)->length);
				$throwNew($IllegalArgumentException, $$str({$(getFieldName(field)), "="_s, $$str(wrongValue), ", expected "_s, $$str($nc(this->originalFields)->get(field))}));
			}
		}
	}
	setFieldsNormalized(mask);
}

int64_t JapaneseImperialCalendar::getFixedDate(int32_t era, int32_t year, int32_t fieldMask) {
	$useLocalCurrentObjectStackCache();
	int32_t month = $Calendar::JANUARY;
	int32_t firstDayOfMonth = 1;
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
	} else if (year == 1 && era != 0) {
		$var($CalendarDate, d, $nc($nc(JapaneseImperialCalendar::eras)->get(era))->getSinceDate());
		month = $nc(d)->getMonth() - 1;
		firstDayOfMonth = d->getDayOfMonth();
	}
	if (year == $nc(JapaneseImperialCalendar::MIN_VALUES)->get($Calendar::YEAR)) {
		$var($CalendarDate, dx, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone())));
		int32_t m = $nc(dx)->getMonth() - 1;
		if (month < m) {
			month = m;
		}
		if (month == m) {
			firstDayOfMonth = dx->getDayOfMonth();
		}
	}
	$init($TimeZone);
	$var($LocalGregorianCalendar$Date, date, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->newCalendarDate($TimeZone::NO_TIMEZONE)));
	$nc(date)->setEra(era > 0 ? $nc(JapaneseImperialCalendar::eras)->get(era) : ($Era*)nullptr);
	date->setDate(year, month + 1, firstDayOfMonth);
	$nc(JapaneseImperialCalendar::jcal)->normalize(date);
	int64_t fixedDate = $nc(JapaneseImperialCalendar::jcal)->getFixedDate(date);
	if (isFieldSet(fieldMask, $Calendar::MONTH)) {
		if (isFieldSet(fieldMask, $Calendar::DAY_OF_MONTH)) {
			if (isSet($Calendar::DAY_OF_MONTH)) {
				fixedDate += internalGet($Calendar::DAY_OF_MONTH);
				fixedDate -= firstDayOfMonth;
			}
		} else if (isFieldSet(fieldMask, $Calendar::WEEK_OF_MONTH)) {
			int64_t firstDayOfWeek = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(fixedDate + 6, getFirstDayOfWeek());
			if ((firstDayOfWeek - fixedDate) >= getMinimalDaysInFirstWeek()) {
				firstDayOfWeek -= 7;
			}
			if (isFieldSet(fieldMask, $Calendar::DAY_OF_WEEK)) {
				firstDayOfWeek = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(firstDayOfWeek + 6, internalGet($Calendar::DAY_OF_WEEK));
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
				fixedDate = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(fixedDate + (7 * dowim) - 1, dayOfWeek);
			} else {
				int32_t lastDate = monthLength(month, year) + (7 * (dowim + 1));
				fixedDate = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(fixedDate + lastDate - 1, dayOfWeek);
			}
		}
	} else if (isFieldSet(fieldMask, $Calendar::DAY_OF_YEAR)) {
		if (isTransitionYear(date->getNormalizedYear())) {
			fixedDate = getFixedDateJan1(date, fixedDate);
		}
		fixedDate += internalGet($Calendar::DAY_OF_YEAR);
		--fixedDate;
	} else {
		int64_t firstDayOfWeek = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(fixedDate + 6, getFirstDayOfWeek());
		if ((firstDayOfWeek - fixedDate) >= getMinimalDaysInFirstWeek()) {
			firstDayOfWeek -= 7;
		}
		if (isFieldSet(fieldMask, $Calendar::DAY_OF_WEEK)) {
			int32_t dayOfWeek = internalGet($Calendar::DAY_OF_WEEK);
			if (dayOfWeek != getFirstDayOfWeek()) {
				firstDayOfWeek = $LocalGregorianCalendar::getDayOfWeekDateOnOrBefore(firstDayOfWeek + 6, dayOfWeek);
			}
		}
		fixedDate = firstDayOfWeek + 7 * ((int64_t)internalGet($Calendar::WEEK_OF_YEAR) - 1);
	}
	return fixedDate;
}

int64_t JapaneseImperialCalendar::getFixedDateJan1($LocalGregorianCalendar$Date* date, int64_t fixedDate) {
	$useLocalCurrentObjectStackCache();
	$var($Era, era, $nc(date)->getEra());
	bool var$0 = date->getEra() != nullptr;
	if (var$0 && date->getYear() == 1) {
		for (int32_t eraIndex = getEraIndex(date); eraIndex > 0; --eraIndex) {
			$var($CalendarDate, d, $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex))->getSinceDate());
			int64_t fd = $nc(JapaneseImperialCalendar::gcal)->getFixedDate(d);
			if (fd > fixedDate) {
				continue;
			}
			return fd;
		}
	}
	$init($TimeZone);
	$var($CalendarDate, d, $nc(JapaneseImperialCalendar::gcal)->newCalendarDate($TimeZone::NO_TIMEZONE));
	$nc(d)->setDate(date->getNormalizedYear(), $Gregorian::JANUARY, 1);
	return $nc(JapaneseImperialCalendar::gcal)->getFixedDate(d);
}

int64_t JapaneseImperialCalendar::getFixedDateMonth1($LocalGregorianCalendar$Date* date, int64_t fixedDate) {
	int32_t eraIndex = getTransitionEraIndex(date);
	if (eraIndex != -1) {
		int64_t transition = $nc(JapaneseImperialCalendar::sinceFixedDates)->get(eraIndex);
		if (transition <= fixedDate) {
			return transition;
		}
	}
	return fixedDate - $nc(date)->getDayOfMonth() + 1;
}

$LocalGregorianCalendar$Date* JapaneseImperialCalendar::getCalendarDate(int64_t fd) {
	$init(JapaneseImperialCalendar);
	$init($TimeZone);
	$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->newCalendarDate($TimeZone::NO_TIMEZONE)));
	$nc(JapaneseImperialCalendar::jcal)->getCalendarDateFromFixedDate(d, fd);
	return d;
}

int32_t JapaneseImperialCalendar::monthLength(int32_t month, int32_t gregorianYear) {
	$init($GregorianCalendar);
	return $CalendarUtils::isGregorianLeapYear(gregorianYear) ? $nc($GregorianCalendar::LEAP_MONTH_LENGTH)->get(month) : $nc($GregorianCalendar::MONTH_LENGTH)->get(month);
}

int32_t JapaneseImperialCalendar::monthLength(int32_t month) {
	if (!JapaneseImperialCalendar::$assertionsDisabled && !$nc(this->jdate)->isNormalized()) {
		$throwNew($AssertionError);
	}
	$init($GregorianCalendar);
	return $nc(this->jdate)->isLeapYear() ? $nc($GregorianCalendar::LEAP_MONTH_LENGTH)->get(month) : $nc($GregorianCalendar::MONTH_LENGTH)->get(month);
}

int32_t JapaneseImperialCalendar::actualMonthLength() {
	int32_t length = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(this->jdate);
	int32_t eraIndex = getTransitionEraIndex(this->jdate);
	if (eraIndex != -1) {
		int64_t transitionFixedDate = $nc(JapaneseImperialCalendar::sinceFixedDates)->get(eraIndex);
		$var($CalendarDate, d, $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex))->getSinceDate());
		if (transitionFixedDate <= this->cachedFixedDate) {
			length -= $nc(d)->getDayOfMonth() - 1;
		} else {
			length = $nc(d)->getDayOfMonth() - 1;
		}
	}
	return length;
}

int32_t JapaneseImperialCalendar::getTransitionEraIndex($LocalGregorianCalendar$Date* date) {
	$init(JapaneseImperialCalendar);
	int32_t eraIndex = getEraIndex(date);
	$var($CalendarDate, transitionDate, $nc($nc(JapaneseImperialCalendar::eras)->get(eraIndex))->getSinceDate());
	int32_t var$1 = $nc(transitionDate)->getYear();
	bool var$0 = var$1 == $nc(date)->getNormalizedYear();
	if (var$0) {
		int32_t var$2 = transitionDate->getMonth();
		var$0 = var$2 == date->getMonth();
	}
	if (var$0) {
		return eraIndex;
	}
	if (eraIndex < $nc(JapaneseImperialCalendar::eras)->length - 1) {
		$assign(transitionDate, $nc($nc(JapaneseImperialCalendar::eras)->get(++eraIndex))->getSinceDate());
		int32_t var$4 = $nc(transitionDate)->getYear();
		bool var$3 = var$4 == $nc(date)->getNormalizedYear();
		if (var$3) {
			int32_t var$5 = transitionDate->getMonth();
			var$3 = var$5 == date->getMonth();
		}
		if (var$3) {
			return eraIndex;
		}
	}
	return -1;
}

bool JapaneseImperialCalendar::isTransitionYear(int32_t normalizedYear) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = $nc(JapaneseImperialCalendar::eras)->length - 1; i > 0; --i) {
		int32_t transitionYear = $nc($($nc($nc(JapaneseImperialCalendar::eras)->get(i))->getSinceDate()))->getYear();
		if (normalizedYear == transitionYear) {
			return true;
		}
		if (normalizedYear > transitionYear) {
			break;
		}
	}
	return false;
}

int32_t JapaneseImperialCalendar::getEraIndex($LocalGregorianCalendar$Date* date) {
	$init(JapaneseImperialCalendar);
	$var($Era, era, $nc(date)->getEra());
	for (int32_t i = $nc(JapaneseImperialCalendar::eras)->length - 1; i > 0; --i) {
		if ($nc(JapaneseImperialCalendar::eras)->get(i) == era) {
			return i;
		}
	}
	return 0;
}

JapaneseImperialCalendar* JapaneseImperialCalendar::getNormalizedCalendar() {
	$var(JapaneseImperialCalendar, jc, nullptr);
	if (isFullyNormalized()) {
		$assign(jc, this);
	} else {
		$assign(jc, $cast(JapaneseImperialCalendar, this->clone()));
		$nc(jc)->setLenient(true);
		jc->complete();
	}
	return jc;
}

void JapaneseImperialCalendar::pinDayOfMonth($LocalGregorianCalendar$Date* date) {
	$useLocalCurrentObjectStackCache();
	int32_t year = $nc(date)->getYear();
	int32_t dom = date->getDayOfMonth();
	if (year != getMinimum($Calendar::YEAR)) {
		date->setDayOfMonth(1);
		$nc(JapaneseImperialCalendar::jcal)->normalize(date);
		int32_t monthLength = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(date);
		if (dom > monthLength) {
			date->setDayOfMonth(monthLength);
		} else {
			date->setDayOfMonth(dom);
		}
		$nc(JapaneseImperialCalendar::jcal)->normalize(date);
	} else {
		$var($LocalGregorianCalendar$Date, d, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate($Long::MIN_VALUE, $(getZone()))));
		$var($LocalGregorianCalendar$Date, realDate, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->getCalendarDate(this->time, $(getZone()))));
		int64_t tod = $nc(realDate)->getTimeOfDay();
		realDate->addYear(+400);
		realDate->setMonth(date->getMonth());
		realDate->setDayOfMonth(1);
		$nc(JapaneseImperialCalendar::jcal)->normalize(realDate);
		int32_t monthLength = $nc(JapaneseImperialCalendar::jcal)->getMonthLength(realDate);
		if (dom > monthLength) {
			realDate->setDayOfMonth(monthLength);
		} else if (dom < $nc(d)->getDayOfMonth()) {
			realDate->setDayOfMonth(d->getDayOfMonth());
		} else {
			realDate->setDayOfMonth(dom);
		}
		int32_t var$1 = realDate->getDayOfMonth();
		bool var$0 = var$1 == $nc(d)->getDayOfMonth();
		if (var$0 && tod < d->getTimeOfDay()) {
			realDate->setDayOfMonth($Math::min(dom + 1, monthLength));
		}
		int32_t var$2 = year;
		int32_t var$3 = realDate->getMonth();
		date->setDate(var$2, var$3, realDate->getDayOfMonth());
	}
}

int32_t JapaneseImperialCalendar::getRolledValue(int32_t value, int32_t amount, int32_t min, int32_t max) {
	$init(JapaneseImperialCalendar);
	if (!JapaneseImperialCalendar::$assertionsDisabled && !(value >= min && value <= max)) {
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
	if (!JapaneseImperialCalendar::$assertionsDisabled && !(n >= min && n <= max)) {
		$throwNew($AssertionError);
	}
	return n;
}

int32_t JapaneseImperialCalendar::internalGetEra() {
	return isSet($Calendar::ERA) ? internalGet($Calendar::ERA) : JapaneseImperialCalendar::currentEra;
}

void JapaneseImperialCalendar::readObject($ObjectInputStream* stream) {
	$nc(stream)->defaultReadObject();
	if (this->jdate == nullptr) {
		$set(this, jdate, $cast($LocalGregorianCalendar$Date, $nc(JapaneseImperialCalendar::jcal)->newCalendarDate($(getZone()))));
		this->cachedFixedDate = $Long::MIN_VALUE;
	}
}

void clinit$JapaneseImperialCalendar($Class* class$) {
	$useLocalCurrentObjectStackCache();
	JapaneseImperialCalendar::$assertionsDisabled = !JapaneseImperialCalendar::class$->desiredAssertionStatus();
	$assignStatic(JapaneseImperialCalendar::jcal, $cast($LocalGregorianCalendar, $CalendarSystem::forName("japanese"_s)));
	$assignStatic(JapaneseImperialCalendar::gcal, $CalendarSystem::getGregorianCalendar());
	$assignStatic(JapaneseImperialCalendar::BEFORE_MEIJI_ERA, $new($Era, "BeforeMeiji"_s, "BM"_s, $Long::MIN_VALUE, false));
	$assignStatic(JapaneseImperialCalendar::MIN_VALUES, $new($ints, {
		0,
		(int32_t)0xEE943C91,
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
		-13 * JapaneseImperialCalendar::ONE_HOUR,
		0
	}));
	$assignStatic(JapaneseImperialCalendar::LEAST_MAX_VALUES, $new($ints, {
		0,
		0,
		$Calendar::JANUARY,
		0,
		4,
		28,
		0,
		$Calendar::SATURDAY,
		4,
		$Calendar::PM,
		11,
		23,
		59,
		59,
		999,
		14 * JapaneseImperialCalendar::ONE_HOUR,
		20 * JapaneseImperialCalendar::ONE_MINUTE
	}));
	$assignStatic(JapaneseImperialCalendar::MAX_VALUES, $new($ints, {
		0,
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
		14 * JapaneseImperialCalendar::ONE_HOUR,
		2 * JapaneseImperialCalendar::ONE_HOUR
	}));
	{
		$var($EraArray, es, $nc(JapaneseImperialCalendar::jcal)->getEras());
		int32_t length = $nc(es)->length + 1;
		$assignStatic(JapaneseImperialCalendar::eras, $new($EraArray, length));
		$assignStatic(JapaneseImperialCalendar::sinceFixedDates, $new($longs, length));
		int32_t index = JapaneseImperialCalendar::BEFORE_MEIJI;
		int32_t current = index;
		$nc(JapaneseImperialCalendar::sinceFixedDates)->set(index, $nc(JapaneseImperialCalendar::gcal)->getFixedDate($($nc(JapaneseImperialCalendar::BEFORE_MEIJI_ERA)->getSinceDate())));
		$nc(JapaneseImperialCalendar::eras)->set(index++, JapaneseImperialCalendar::BEFORE_MEIJI_ERA);
		{
			$var($EraArray, arr$, es);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Era, e, arr$->get(i$));
				{
					$init($TimeZone);
					int64_t var$0 = $nc(e)->getSince($TimeZone::NO_TIMEZONE);
					if (var$0 < $System::currentTimeMillis()) {
						current = index;
					}
					$var($CalendarDate, d, $nc(e)->getSinceDate());
					$nc(JapaneseImperialCalendar::sinceFixedDates)->set(index, $nc(JapaneseImperialCalendar::gcal)->getFixedDate(d));
					$nc(JapaneseImperialCalendar::eras)->set(index++, e);
				}
			}
		}
		JapaneseImperialCalendar::currentEra = current;
		int32_t var$1 = $Calendar::ERA;
		$nc(JapaneseImperialCalendar::LEAST_MAX_VALUES)->set(var$1, $nc(JapaneseImperialCalendar::MAX_VALUES)->set($Calendar::ERA, $nc(JapaneseImperialCalendar::eras)->length - 1));
		int32_t year = $Integer::MAX_VALUE;
		int32_t dayOfYear = $Integer::MAX_VALUE;
		$init($TimeZone);
		$var($CalendarDate, date, $nc(JapaneseImperialCalendar::gcal)->newCalendarDate($TimeZone::NO_TIMEZONE));
		for (int32_t i = 1; i < $nc(JapaneseImperialCalendar::eras)->length; ++i) {
			int64_t fd = $nc(JapaneseImperialCalendar::sinceFixedDates)->get(i);
			$var($CalendarDate, transitionDate, $nc($nc(JapaneseImperialCalendar::eras)->get(i))->getSinceDate());
			$nc(date)->setDate($nc(transitionDate)->getYear(), $BaseCalendar::JANUARY, 1);
			int64_t fdd = $nc(JapaneseImperialCalendar::gcal)->getFixedDate(date);
			if (fd != fdd) {
				dayOfYear = $Math::min((int32_t)(fd - fdd) + 1, dayOfYear);
			}
			date->setDate($nc(transitionDate)->getYear(), $BaseCalendar::DECEMBER, 31);
			fdd = $nc(JapaneseImperialCalendar::gcal)->getFixedDate(date);
			if (fd != fdd) {
				dayOfYear = $Math::min((int32_t)(fdd - fd) + 1, dayOfYear);
			}
			$var($LocalGregorianCalendar$Date, lgd, JapaneseImperialCalendar::getCalendarDate(fd - 1));
			int32_t y = $nc(lgd)->getYear();
			bool var$2 = lgd->getMonth() == $BaseCalendar::JANUARY;
			if (!(var$2 && lgd->getDayOfMonth() == 1)) {
				--y;
			}
			year = $Math::min(y, year);
		}
		$nc(JapaneseImperialCalendar::LEAST_MAX_VALUES)->set($Calendar::YEAR, year);
		$nc(JapaneseImperialCalendar::LEAST_MAX_VALUES)->set($Calendar::DAY_OF_YEAR, dayOfYear);
	}
}

JapaneseImperialCalendar::JapaneseImperialCalendar() {
}

$Class* JapaneseImperialCalendar::load$($String* name, bool initialize) {
	$loadClass(JapaneseImperialCalendar, name, initialize, &_JapaneseImperialCalendar_ClassInfo_, clinit$JapaneseImperialCalendar, allocate$JapaneseImperialCalendar);
	return class$;
}

$Class* JapaneseImperialCalendar::class$ = nullptr;

	} // util
} // java