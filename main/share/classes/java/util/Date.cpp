#include <java/util/Date.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/text/DateFormat.h>
#include <java/time/Instant.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/Locale.h>
#include <java/util/TimeZone.h>
#include <sun/util/calendar/BaseCalendar$Date.h>
#include <sun/util/calendar/BaseCalendar.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/CalendarSystem.h>
#include <sun/util/calendar/CalendarUtils.h>
#include <sun/util/calendar/Era.h>
#include <sun/util/calendar/Gregorian.h>
#include <sun/util/calendar/ZoneInfo.h>
#include <jcpp.h>

#undef DEFAULT_GREGORIAN_CUTOVER
#undef MILLISECOND
#undef MIN_VALUE
#undef SHORT
#undef SUNDAY
#undef US
#undef UTC

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateFormat = ::java::text::DateFormat;
using $Instant = ::java::time::Instant;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $Locale = ::java::util::Locale;
using $TimeZone = ::java::util::TimeZone;
using $BaseCalendar = ::sun::util::calendar::BaseCalendar;
using $BaseCalendar$Date = ::sun::util::calendar::BaseCalendar$Date;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $CalendarSystem = ::sun::util::calendar::CalendarSystem;
using $CalendarUtils = ::sun::util::calendar::CalendarUtils;
using $ZoneInfo = ::sun::util::calendar::ZoneInfo;

namespace java {
	namespace util {

$CompoundAttribute _Date_MethodAnnotations_init$2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_init$3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_init$4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_init$5[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_UTC6[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getDate19[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getDay20[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getHours21[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getMinutes24[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getMonth25[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getSeconds26[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getTimezoneOffset29[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_getYear30[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_parse34[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_setDate36[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_setHours37[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_setMinutes38[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_setMonth39[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_setSeconds40[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_setYear42[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_toGMTString43[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Date_MethodAnnotations_toLocaleString45[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Date_FieldInfo_[] = {
	{"gcal", "Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Date, gcal)},
	{"jcal", "Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC, $staticField(Date, jcal)},
	{"fastTime", "J", nullptr, $PRIVATE | $TRANSIENT, $field(Date, fastTime)},
	{"cdate", "Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE | $TRANSIENT, $field(Date, cdate)},
	{"defaultCenturyStart", "I", nullptr, $PRIVATE | $STATIC, $staticField(Date, defaultCenturyStart)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Date, serialVersionUID)},
	{"wtb", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Date, wtb)},
	{"ttb", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Date, ttb)},
	{}
};

$MethodInfo _Date_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(Date, init$, void)},
	{"<init>", "(J)V", nullptr, $PUBLIC, $method(Date, init$, void, int64_t)},
	{"<init>", "(III)V", nullptr, $PUBLIC | $DEPRECATED, $method(Date, init$, void, int32_t, int32_t, int32_t), nullptr, nullptr, _Date_MethodAnnotations_init$2},
	{"<init>", "(IIIII)V", nullptr, $PUBLIC | $DEPRECATED, $method(Date, init$, void, int32_t, int32_t, int32_t, int32_t, int32_t), nullptr, nullptr, _Date_MethodAnnotations_init$3},
	{"<init>", "(IIIIII)V", nullptr, $PUBLIC | $DEPRECATED, $method(Date, init$, void, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t), nullptr, nullptr, _Date_MethodAnnotations_init$4},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(Date, init$, void, $String*), nullptr, nullptr, _Date_MethodAnnotations_init$5},
	{"UTC", "(IIIIII)J", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(Date, UTC, int64_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t), nullptr, nullptr, _Date_MethodAnnotations_UTC6},
	{"after", "(Ljava/util/Date;)Z", nullptr, $PUBLIC, $virtualMethod(Date, after, bool, Date*)},
	{"before", "(Ljava/util/Date;)Z", nullptr, $PUBLIC, $virtualMethod(Date, before, bool, Date*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Date, clone, $Object*)},
	{"compareTo", "(Ljava/util/Date;)I", nullptr, $PUBLIC, $virtualMethod(Date, compareTo, int32_t, Date*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Date, compareTo, int32_t, Object$*)},
	{"convertToAbbr", "(Ljava/lang/StringBuilder;Ljava/lang/String;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Date, convertToAbbr, $StringBuilder*, $StringBuilder*, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Date, equals, bool, Object$*)},
	{"from", "(Ljava/time/Instant;)Ljava/util/Date;", nullptr, $PUBLIC | $STATIC, $staticMethod(Date, from, Date*, $Instant*)},
	{"getCalendarDate", "()Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE | $FINAL, $method(Date, getCalendarDate, $BaseCalendar$Date*)},
	{"getCalendarSystem", "(I)Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Date, getCalendarSystem, $BaseCalendar*, int32_t)},
	{"getCalendarSystem", "(J)Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Date, getCalendarSystem, $BaseCalendar*, int64_t)},
	{"getCalendarSystem", "(Lsun/util/calendar/BaseCalendar$Date;)Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Date, getCalendarSystem, $BaseCalendar*, $BaseCalendar$Date*)},
	{"getDate", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getDate, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getDate19},
	{"getDay", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getDay, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getDay20},
	{"getHours", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getHours, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getHours21},
	{"getJulianCalendar", "()Lsun/util/calendar/BaseCalendar;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNCHRONIZED, $staticMethod(Date, getJulianCalendar, $BaseCalendar*)},
	{"getMillisOf", "(Ljava/util/Date;)J", nullptr, $STATIC | $FINAL, $staticMethod(Date, getMillisOf, int64_t, Date*)},
	{"getMinutes", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getMinutes, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getMinutes24},
	{"getMonth", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getMonth, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getMonth25},
	{"getSeconds", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getSeconds, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getSeconds26},
	{"getTime", "()J", nullptr, $PUBLIC, $virtualMethod(Date, getTime, int64_t)},
	{"getTimeImpl", "()J", nullptr, $PRIVATE | $FINAL, $method(Date, getTimeImpl, int64_t)},
	{"getTimezoneOffset", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getTimezoneOffset, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getTimezoneOffset29},
	{"getYear", "()I", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, getYear, int32_t), nullptr, nullptr, _Date_MethodAnnotations_getYear30},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Date, hashCode, int32_t)},
	{"normalize", "()Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE | $FINAL, $method(Date, normalize, $BaseCalendar$Date*)},
	{"normalize", "(Lsun/util/calendar/BaseCalendar$Date;)Lsun/util/calendar/BaseCalendar$Date;", nullptr, $PRIVATE | $FINAL, $method(Date, normalize, $BaseCalendar$Date*, $BaseCalendar$Date*)},
	{"parse", "(Ljava/lang/String;)J", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(Date, parse, int64_t, $String*), nullptr, nullptr, _Date_MethodAnnotations_parse34},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Date, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setDate", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, setDate, void, int32_t), nullptr, nullptr, _Date_MethodAnnotations_setDate36},
	{"setHours", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, setHours, void, int32_t), nullptr, nullptr, _Date_MethodAnnotations_setHours37},
	{"setMinutes", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, setMinutes, void, int32_t), nullptr, nullptr, _Date_MethodAnnotations_setMinutes38},
	{"setMonth", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, setMonth, void, int32_t), nullptr, nullptr, _Date_MethodAnnotations_setMonth39},
	{"setSeconds", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, setSeconds, void, int32_t), nullptr, nullptr, _Date_MethodAnnotations_setSeconds40},
	{"setTime", "(J)V", nullptr, $PUBLIC, $virtualMethod(Date, setTime, void, int64_t)},
	{"setYear", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, setYear, void, int32_t), nullptr, nullptr, _Date_MethodAnnotations_setYear42},
	{"toGMTString", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, toGMTString, $String*), nullptr, nullptr, _Date_MethodAnnotations_toGMTString43},
	{"toInstant", "()Ljava/time/Instant;", nullptr, $PUBLIC, $virtualMethod(Date, toInstant, $Instant*)},
	{"toLocaleString", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Date, toLocaleString, $String*), nullptr, nullptr, _Date_MethodAnnotations_toLocaleString45},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Date, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(Date, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _Date_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.Date",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable,java.lang.Comparable",
	_Date_FieldInfo_,
	_Date_MethodInfo_,
	"Ljava/lang/Object;Ljava/io/Serializable;Ljava/lang/Cloneable;Ljava/lang/Comparable<Ljava/util/Date;>;"
};

$Object* allocate$Date($Class* clazz) {
	return $of($alloc(Date));
}

void Date::finalize() {
	this->$Serializable::finalize();
}

$BaseCalendar* Date::gcal = nullptr;
$BaseCalendar* Date::jcal = nullptr;
int32_t Date::defaultCenturyStart = 0;
$StringArray* Date::wtb = nullptr;
$ints* Date::ttb = nullptr;

void Date::init$() {
	Date::init$($System::currentTimeMillis());
}

void Date::init$(int64_t date) {
	this->fastTime = date;
}

void Date::init$(int32_t year, int32_t month, int32_t date) {
	Date::init$(year, month, date, 0, 0, 0);
}

void Date::init$(int32_t year, int32_t month, int32_t date, int32_t hrs, int32_t min) {
	Date::init$(year, month, date, hrs, min, 0);
}

void Date::init$(int32_t year, int32_t month, int32_t date, int32_t hrs, int32_t min, int32_t sec) {
	$useLocalCurrentObjectStackCache();
	int32_t y = year + 1900;
	if (month >= 12) {
		y += month / 12;
		$modAssign(month, 12);
	} else if (month < 0) {
		y += $CalendarUtils::floorDivide(month, 12);
		month = $CalendarUtils::mod(month, 12);
	}
	$var($BaseCalendar, cal, getCalendarSystem(y));
	$set(this, cdate, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate($($TimeZone::getDefaultRef()))));
	$nc($($nc(this->cdate)->setNormalizedDate(y, month + 1, date)))->setTimeOfDay(hrs, min, sec, 0);
	getTimeImpl();
	$set(this, cdate, nullptr);
}

void Date::init$($String* s) {
	Date::init$(parse(s));
}

$Object* Date::clone() {
	$var(Date, d, nullptr);
	try {
		$assign(d, $cast(Date, $Serializable::clone()));
		if (this->cdate != nullptr) {
			$set($nc(d), cdate, $cast($BaseCalendar$Date, $nc(this->cdate)->clone()));
		}
	} catch ($CloneNotSupportedException& e) {
	}
	return $of(d);
}

int64_t Date::UTC(int32_t year, int32_t month, int32_t date, int32_t hrs, int32_t min, int32_t sec) {
	$init(Date);
	$useLocalCurrentObjectStackCache();
	int32_t y = year + 1900;
	if (month >= 12) {
		y += month / 12;
		$modAssign(month, 12);
	} else if (month < 0) {
		y += $CalendarUtils::floorDivide(month, 12);
		month = $CalendarUtils::mod(month, 12);
	}
	int32_t m = month + 1;
	$var($BaseCalendar, cal, getCalendarSystem(y));
	$var($BaseCalendar$Date, udate, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate(nullptr)));
	$nc($($nc(udate)->setNormalizedDate(y, m, date)))->setTimeOfDay(hrs, min, sec, 0);
	$var(Date, d, $new(Date, (int64_t)0));
	d->normalize(udate);
	return d->fastTime;
}

int64_t Date::parse($String* s) {
	$init(Date);
	$useLocalCurrentObjectStackCache();
	int32_t year = $Integer::MIN_VALUE;
	int32_t mon = -1;
	int32_t mday = -1;
	int32_t hour = -1;
	int32_t min = -1;
	int32_t sec = -1;
	int32_t millis = -1;
	int32_t c = -1;
	int32_t i = 0;
	int32_t n = -1;
	int32_t wst = -1;
	int32_t tzoffset = -1;
	int32_t prevc = 0;
	bool syntax$break = false;
	for (;;) {
		{
			if (s == nullptr) {
				syntax$break = true;
				break;
			}
			int32_t limit = $nc(s)->length();
			while (i < limit) {
				c = s->charAt(i);
				++i;
				if (c <= u' ' || c == u',') {
					continue;
				}
				if (c == u'(') {
					int32_t depth = 1;
					while (i < limit) {
						c = s->charAt(i);
						++i;
						if (c == u'(') {
							++depth;
						} else if (c == u')') {
							if (--depth <= 0) {
								break;
							}
						}
					}
					continue;
				}
				if (u'0' <= c && c <= u'9') {
					n = c - u'0';
					while (i < limit && u'0' <= (c = s->charAt(i)) && c <= u'9') {
						n = n * 10 + c - u'0';
						++i;
					}
					if (prevc == u'+' || prevc == u'-' && year != $Integer::MIN_VALUE) {
						if (n < 24) {
							n = n * 60;
						} else {
							n = n % 100 + n / 100 * 60;
						}
						if (prevc == u'+') {
							n = -n;
						}
						if (tzoffset != 0 && tzoffset != -1) {
							syntax$break = true;
							break;
						}
						tzoffset = n;
					} else if (n >= 70) {
						if (year != $Integer::MIN_VALUE) {
							syntax$break = true;
							break;
						} else if (c <= u' ' || c == u',' || c == u'/' || i >= limit) {
							year = n;
						} else {
							syntax$break = true;
							break;
						}
					} else if (c == u':') {
						if (hour < 0) {
							hour = (int8_t)n;
						} else if (min < 0) {
							min = (int8_t)n;
						} else {
							syntax$break = true;
							break;
						}
					} else if (c == u'/') {
						if (mon < 0) {
							mon = (int8_t)(n - 1);
						} else if (mday < 0) {
							mday = (int8_t)n;
						} else {
							syntax$break = true;
							break;
						}
					} else if (i < limit && c != u',' && c > u' ' && c != u'-') {
						syntax$break = true;
						break;
					} else if (hour >= 0 && min < 0) {
						min = (int8_t)n;
					} else if (min >= 0 && sec < 0) {
						sec = (int8_t)n;
					} else if (mday < 0) {
						mday = (int8_t)n;
					} else if (year == $Integer::MIN_VALUE && mon >= 0 && mday >= 0) {
						year = n;
					} else {
						syntax$break = true;
						break;
					}
					prevc = 0;
				} else if (c == u'/' || c == u':' || c == u'+' || c == u'-') {
					prevc = c;
				} else {
					int32_t st = i - 1;
					while (i < limit) {
						c = s->charAt(i);
						if (!(u'A' <= c && c <= u'Z' || u'a' <= c && c <= u'z')) {
							break;
						}
						++i;
					}
					if (i <= st + 1) {
						syntax$break = true;
						break;
					}
					int32_t k = 0;
					for (k = $nc(Date::wtb)->length; --k >= 0;) {
						if ($nc($nc(Date::wtb)->get(k))->regionMatches(true, 0, s, st, i - st)) {
							int32_t action = $nc(Date::ttb)->get(k);
							if (action != 0) {
								if (action == 1) {
									if (hour > 12 || hour < 1) {
										syntax$break = true;
										break;
									} else if (hour < 12) {
										hour += 12;
									}
								} else if (action == 14) {
									if (hour > 12 || hour < 1) {
										syntax$break = true;
										break;
									} else if (hour == 12) {
										hour = 0;
									}
								} else if (action <= 13) {
									if (mon < 0) {
										mon = (int8_t)(action - 2);
									} else {
										syntax$break = true;
										break;
									}
								} else {
									tzoffset = action - 10000;
								}
							}
							break;
						}
					}
					if (syntax$break) {
						break;
					}
					if (k < 0) {
						syntax$break = true;
						break;
					}
					prevc = 0;
				}
			}
			if (syntax$break) {
				break;
			}
			if (year == $Integer::MIN_VALUE || mon < 0 || mday < 0) {
				syntax$break = true;
				break;
			}
			if (year < 100) {
				$synchronized(Date::class$) {
					if (Date::defaultCenturyStart == 0) {
						Date::defaultCenturyStart = $nc($($nc(Date::gcal)->getCalendarDate()))->getYear() - 80;
					}
				}
				year += (Date::defaultCenturyStart / 100) * 100;
				if (year < Date::defaultCenturyStart) {
					year += 100;
				}
			}
			if (sec < 0) {
				sec = 0;
			}
			if (min < 0) {
				min = 0;
			}
			if (hour < 0) {
				hour = 0;
			}
			$var($BaseCalendar, cal, getCalendarSystem(year));
			if (tzoffset == -1) {
				$var($BaseCalendar$Date, ldate, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate($($TimeZone::getDefaultRef()))));
				$nc(ldate)->setDate(year, mon + 1, mday);
				ldate->setTimeOfDay(hour, min, sec, 0);
				return cal->getTime(ldate);
			}
			$var($BaseCalendar$Date, udate, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate(nullptr)));
			$nc(udate)->setDate(year, mon + 1, mday);
			udate->setTimeOfDay(hour, min, sec, 0);
			return cal->getTime(udate) + tzoffset * (60 * 1000);
		}
		break;
	}
	$throwNew($IllegalArgumentException);
}

int32_t Date::getYear() {
	return $nc($(normalize()))->getYear() - 1900;
}

void Date::setYear(int32_t year) {
	$nc($(getCalendarDate()))->setNormalizedYear(year + 1900);
}

int32_t Date::getMonth() {
	return $nc($(normalize()))->getMonth() - 1;
}

void Date::setMonth(int32_t month) {
	int32_t y = 0;
	if (month >= 12) {
		y = month / 12;
		$modAssign(month, 12);
	} else if (month < 0) {
		y = $CalendarUtils::floorDivide(month, 12);
		month = $CalendarUtils::mod(month, 12);
	}
	$var($BaseCalendar$Date, d, getCalendarDate());
	if (y != 0) {
		$nc(d)->setNormalizedYear(d->getNormalizedYear() + y);
	}
	$nc(d)->setMonth(month + 1);
}

int32_t Date::getDate() {
	return $nc($(normalize()))->getDayOfMonth();
}

void Date::setDate(int32_t date) {
	$nc($(getCalendarDate()))->setDayOfMonth(date);
}

int32_t Date::getDay() {
	return $nc($(normalize()))->getDayOfWeek() - $BaseCalendar::SUNDAY;
}

int32_t Date::getHours() {
	return $nc($(normalize()))->getHours();
}

void Date::setHours(int32_t hours) {
	$nc($(getCalendarDate()))->setHours(hours);
}

int32_t Date::getMinutes() {
	return $nc($(normalize()))->getMinutes();
}

void Date::setMinutes(int32_t minutes) {
	$nc($(getCalendarDate()))->setMinutes(minutes);
}

int32_t Date::getSeconds() {
	return $nc($(normalize()))->getSeconds();
}

void Date::setSeconds(int32_t seconds) {
	$nc($(getCalendarDate()))->setSeconds(seconds);
}

int64_t Date::getTime() {
	return getTimeImpl();
}

int64_t Date::getTimeImpl() {
	if (this->cdate != nullptr && !$nc(this->cdate)->isNormalized()) {
		normalize();
	}
	return this->fastTime;
}

void Date::setTime(int64_t time) {
	this->fastTime = time;
	$set(this, cdate, nullptr);
}

bool Date::before(Date* when) {
	int64_t var$0 = getMillisOf(this);
	return var$0 < getMillisOf(when);
}

bool Date::after(Date* when) {
	int64_t var$0 = getMillisOf(this);
	return var$0 > getMillisOf(when);
}

bool Date::equals(Object$* obj) {
	bool var$0 = $instanceOf(Date, obj);
	if (var$0) {
		int64_t var$1 = getTime();
		var$0 = var$1 == $nc(($cast(Date, obj)))->getTime();
	}
	return var$0;
}

int64_t Date::getMillisOf(Date* date) {
	$init(Date);
	if ($nc($of(date))->getClass() != Date::class$) {
		return date->getTime();
	}
	if ($nc(date)->cdate == nullptr || $nc($nc(date)->cdate)->isNormalized()) {
		return date->fastTime;
	}
	$var($BaseCalendar$Date, d, $cast($BaseCalendar$Date, $nc($nc(date)->cdate)->clone()));
	return $nc(Date::gcal)->getTime(d);
}

int32_t Date::compareTo(Date* anotherDate) {
	int64_t thisTime = getMillisOf(this);
	int64_t anotherTime = getMillisOf(anotherDate);
	return (thisTime < anotherTime ? -1 : (thisTime == anotherTime ? 0 : 1));
}

int32_t Date::hashCode() {
	int64_t ht = this->getTime();
	return (int32_t)ht ^ (int32_t)(ht >> 32);
}

$String* Date::toString() {
	$useLocalCurrentObjectStackCache();
	$var($BaseCalendar$Date, date, normalize());
	$var($StringBuilder, sb, $new($StringBuilder, 28));
	int32_t index = $nc(date)->getDayOfWeek();
	if (index == $BaseCalendar::SUNDAY) {
		index = 8;
	}
	$nc($(convertToAbbr(sb, $nc(Date::wtb)->get(index))))->append(u' ');
	$nc($(convertToAbbr(sb, $nc(Date::wtb)->get(date->getMonth() - 1 + 2 + 7))))->append(u' ');
	$nc($($CalendarUtils::sprintf0d(sb, date->getDayOfMonth(), 2)))->append(u' ');
	$nc($($CalendarUtils::sprintf0d(sb, date->getHours(), 2)))->append(u':');
	$nc($($CalendarUtils::sprintf0d(sb, date->getMinutes(), 2)))->append(u':');
	$nc($($CalendarUtils::sprintf0d(sb, date->getSeconds(), 2)))->append(u' ');
	$var($TimeZone, zi, date->getZone());
	if (zi != nullptr) {
		$init($Locale);
		sb->append($(zi->getDisplayName(date->isDaylightTime(), $TimeZone::SHORT, $Locale::US)));
	} else {
		sb->append("GMT"_s);
	}
	sb->append(u' ')->append(date->getYear());
	return sb->toString();
}

$StringBuilder* Date::convertToAbbr($StringBuilder* sb, $String* name) {
	$init(Date);
	$nc(sb)->append($Character::toUpperCase($nc(name)->charAt(0)));
	sb->append($nc(name)->charAt(1))->append($nc(name)->charAt(2));
	return sb;
}

$String* Date::toLocaleString() {
	$var($DateFormat, formatter, $DateFormat::getDateTimeInstance());
	return $nc(formatter)->format(this);
}

$String* Date::toGMTString() {
	$useLocalCurrentObjectStackCache();
	int64_t t = getTime();
	$var($BaseCalendar, cal, getCalendarSystem(t));
	$var($BaseCalendar$Date, date, $cast($BaseCalendar$Date, $nc(cal)->getCalendarDate(getTime(), ($TimeZone*)nullptr)));
	$var($StringBuilder, sb, $new($StringBuilder, 32));
	$nc($($CalendarUtils::sprintf0d(sb, $nc(date)->getDayOfMonth(), 1)))->append(u' ');
	$nc($(convertToAbbr(sb, $nc(Date::wtb)->get($nc(date)->getMonth() - 1 + 2 + 7))))->append(u' ');
	sb->append($nc(date)->getYear())->append(u' ');
	$nc($($CalendarUtils::sprintf0d(sb, $nc(date)->getHours(), 2)))->append(u':');
	$nc($($CalendarUtils::sprintf0d(sb, $nc(date)->getMinutes(), 2)))->append(u':');
	$CalendarUtils::sprintf0d(sb, $nc(date)->getSeconds(), 2);
	sb->append(" GMT"_s);
	return sb->toString();
}

int32_t Date::getTimezoneOffset() {
	int32_t zoneOffset = 0;
	if (this->cdate == nullptr) {
		$var($TimeZone, tz, $TimeZone::getDefaultRef());
		if ($instanceOf($ZoneInfo, tz)) {
			zoneOffset = $nc(($cast($ZoneInfo, tz)))->getOffsets(this->fastTime, nullptr);
		} else {
			zoneOffset = $nc(tz)->getOffset(this->fastTime);
		}
	} else {
		normalize();
		zoneOffset = $nc(this->cdate)->getZoneOffset();
	}
	return -zoneOffset / 0x0000EA60;
}

$BaseCalendar$Date* Date::getCalendarDate() {
	$useLocalCurrentObjectStackCache();
	if (this->cdate == nullptr) {
		$var($BaseCalendar, cal, getCalendarSystem(this->fastTime));
		$set(this, cdate, $cast($BaseCalendar$Date, $nc(cal)->getCalendarDate(this->fastTime, $($TimeZone::getDefaultRef()))));
	}
	return this->cdate;
}

$BaseCalendar$Date* Date::normalize() {
	$useLocalCurrentObjectStackCache();
	if (this->cdate == nullptr) {
		$var($BaseCalendar, cal, getCalendarSystem(this->fastTime));
		$set(this, cdate, $cast($BaseCalendar$Date, $nc(cal)->getCalendarDate(this->fastTime, $($TimeZone::getDefaultRef()))));
		return this->cdate;
	}
	if (!$nc(this->cdate)->isNormalized()) {
		$set(this, cdate, normalize(this->cdate));
	}
	$var($TimeZone, tz, $TimeZone::getDefaultRef());
	if (tz != $nc(this->cdate)->getZone()) {
		$nc(this->cdate)->setZone(tz);
		$var($CalendarSystem, cal, getCalendarSystem(this->cdate));
		$nc(cal)->getCalendarDate(this->fastTime, static_cast<$CalendarDate*>(this->cdate));
	}
	return this->cdate;
}

$BaseCalendar$Date* Date::normalize($BaseCalendar$Date* date$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($BaseCalendar$Date, date, date$renamed);
	int32_t y = $nc(date)->getNormalizedYear();
	int32_t m = date->getMonth();
	int32_t d = date->getDayOfMonth();
	int32_t hh = date->getHours();
	int32_t mm = date->getMinutes();
	int32_t ss = date->getSeconds();
	int32_t ms = date->getMillis();
	$var($TimeZone, tz, date->getZone());
	if (y == 1582 || y > 0x10B07600 || y < (int32_t)0xEF4F8A00) {
		if (tz == nullptr) {
			$assign(tz, $TimeZone::getTimeZone("GMT"_s));
		}
		$var($GregorianCalendar, gc, $new($GregorianCalendar, tz));
		gc->clear();
		gc->set($GregorianCalendar::MILLISECOND, ms);
		gc->set(y, m - 1, d, hh, mm, ss);
		this->fastTime = gc->getTimeInMillis();
		$var($BaseCalendar, cal, getCalendarSystem(this->fastTime));
		$assign(date, $cast($BaseCalendar$Date, $nc(cal)->getCalendarDate(this->fastTime, tz)));
		return date;
	}
	$var($BaseCalendar, cal, getCalendarSystem(y));
	if (cal != getCalendarSystem(date)) {
		$assign(date, $cast($BaseCalendar$Date, $nc(cal)->newCalendarDate(tz)));
		$nc($($nc(date)->setNormalizedDate(y, m, d)))->setTimeOfDay(hh, mm, ss, ms);
	}
	this->fastTime = $nc(cal)->getTime(date);
	$var($BaseCalendar, ncal, getCalendarSystem(this->fastTime));
	if (ncal != cal) {
		$assign(date, $cast($BaseCalendar$Date, $nc(ncal)->newCalendarDate(tz)));
		$nc($($nc(date)->setNormalizedDate(y, m, d)))->setTimeOfDay(hh, mm, ss, ms);
		this->fastTime = ncal->getTime(date);
	}
	return date;
}

$BaseCalendar* Date::getCalendarSystem(int32_t year) {
	$init(Date);
	if (year >= 1582) {
		return Date::gcal;
	}
	return getJulianCalendar();
}

$BaseCalendar* Date::getCalendarSystem(int64_t utc) {
	$init(Date);
	if (utc >= 0 || utc >= $GregorianCalendar::DEFAULT_GREGORIAN_CUTOVER - $nc($($TimeZone::getDefaultRef()))->getOffset(utc)) {
		return Date::gcal;
	}
	return getJulianCalendar();
}

$BaseCalendar* Date::getCalendarSystem($BaseCalendar$Date* cdate) {
	$init(Date);
	if (Date::jcal == nullptr) {
		return Date::gcal;
	}
	if ($nc(cdate)->getEra() != nullptr) {
		return Date::jcal;
	}
	return Date::gcal;
}

$BaseCalendar* Date::getJulianCalendar() {
	$load(Date);
	$synchronized(class$) {
		$init(Date);
		if (Date::jcal == nullptr) {
			$assignStatic(Date::jcal, $cast($BaseCalendar, $CalendarSystem::forName("julian"_s)));
		}
		return Date::jcal;
	}
}

void Date::writeObject($ObjectOutputStream* s) {
	$nc(s)->defaultWriteObject();
	s->writeLong(getTimeImpl());
}

void Date::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	this->fastTime = s->readLong();
}

Date* Date::from($Instant* instant) {
	$init(Date);
	try {
		return $new(Date, $nc(instant)->toEpochMilli());
	} catch ($ArithmeticException& ex) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(ex));
	}
	$shouldNotReachHere();
}

$Instant* Date::toInstant() {
	return $Instant::ofEpochMilli(getTime());
}

int32_t Date::compareTo(Object$* anotherDate) {
	return this->compareTo($cast(Date, anotherDate));
}

void clinit$Date($Class* class$) {
	$assignStatic(Date::gcal, $CalendarSystem::getGregorianCalendar());
	$assignStatic(Date::wtb, $new($StringArray, {
		"am"_s,
		"pm"_s,
		"monday"_s,
		"tuesday"_s,
		"wednesday"_s,
		"thursday"_s,
		"friday"_s,
		"saturday"_s,
		"sunday"_s,
		"january"_s,
		"february"_s,
		"march"_s,
		"april"_s,
		"may"_s,
		"june"_s,
		"july"_s,
		"august"_s,
		"september"_s,
		"october"_s,
		"november"_s,
		"december"_s,
		"gmt"_s,
		"ut"_s,
		"utc"_s,
		"est"_s,
		"edt"_s,
		"cst"_s,
		"cdt"_s,
		"mst"_s,
		"mdt"_s,
		"pst"_s,
		"pdt"_s
	}));
	$assignStatic(Date::ttb, $new($ints, {
		14,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12,
		13,
		10000 + 0,
		10000 + 0,
		10000 + 0,
		10000 + 5 * 60,
		10000 + 4 * 60,
		10000 + 6 * 60,
		10000 + 5 * 60,
		10000 + 7 * 60,
		10000 + 6 * 60,
		10000 + 8 * 60,
		10000 + 7 * 60
	}));
}

Date::Date() {
}

$Class* Date::load$($String* name, bool initialize) {
	$loadClass(Date, name, initialize, &_Date_ClassInfo_, clinit$Date, allocate$Date);
	return class$;
}

$Class* Date::class$ = nullptr;

	} // util
} // java