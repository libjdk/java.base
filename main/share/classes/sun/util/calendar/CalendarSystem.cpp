#include <sun/util/calendar/CalendarSystem.h>

#include <java/lang/InternalError.h>
#include <java/util/TimeZone.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/util/calendar/CalendarDate.h>
#include <sun/util/calendar/Era.h>
#include <sun/util/calendar/Gregorian.h>
#include <sun/util/calendar/LocalGregorianCalendar.h>
#include <jcpp.h>

#undef GREGORIAN_INSTANCE
#undef PACKAGE_NAME

using $EraArray = $Array<::sun::util::calendar::Era>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $TimeZone = ::java::util::TimeZone;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDate = ::sun::util::calendar::CalendarDate;
using $Era = ::sun::util::calendar::Era;
using $Gregorian = ::sun::util::calendar::Gregorian;
using $LocalGregorianCalendar = ::sun::util::calendar::LocalGregorianCalendar;

namespace sun {
	namespace util {
		namespace calendar {

$FieldInfo _CalendarSystem_FieldInfo_[] = {
	{"initialized", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(CalendarSystem, initialized)},
	{"names", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(CalendarSystem, names)},
	{"calendars", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Lsun/util/calendar/CalendarSystem;>;", $PRIVATE | $STATIC, $staticField(CalendarSystem, calendars)},
	{"PACKAGE_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CalendarSystem, PACKAGE_NAME)},
	{"namePairs", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CalendarSystem, namePairs)},
	{"GREGORIAN_INSTANCE", "Lsun/util/calendar/Gregorian;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CalendarSystem, GREGORIAN_INSTANCE)},
	{}
};

$MethodInfo _CalendarSystem_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CalendarSystem, init$, void)},
	{"forName", "(Ljava/lang/String;)Lsun/util/calendar/CalendarSystem;", nullptr, $PUBLIC | $STATIC, $staticMethod(CalendarSystem, forName, CalendarSystem*, $String*)},
	{"getCalendarDate", "()Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getCalendarDate, $CalendarDate*)},
	{"getCalendarDate", "(J)Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getCalendarDate, $CalendarDate*, int64_t)},
	{"getCalendarDate", "(JLsun/util/calendar/CalendarDate;)Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getCalendarDate, $CalendarDate*, int64_t, $CalendarDate*)},
	{"getCalendarDate", "(JLjava/util/TimeZone;)Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getCalendarDate, $CalendarDate*, int64_t, $TimeZone*)},
	{"getEra", "(Ljava/lang/String;)Lsun/util/calendar/Era;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getEra, $Era*, $String*)},
	{"getEras", "()[Lsun/util/calendar/Era;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getEras, $EraArray*)},
	{"getGregorianCalendar", "()Lsun/util/calendar/Gregorian;", nullptr, $PUBLIC | $STATIC, $staticMethod(CalendarSystem, getGregorianCalendar, $Gregorian*)},
	{"getMonthLength", "(Lsun/util/calendar/CalendarDate;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getMonthLength, int32_t, $CalendarDate*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getName, $String*)},
	{"getNthDayOfWeek", "(IILsun/util/calendar/CalendarDate;)Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getNthDayOfWeek, $CalendarDate*, int32_t, int32_t, $CalendarDate*)},
	{"getTime", "(Lsun/util/calendar/CalendarDate;)J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getTime, int64_t, $CalendarDate*)},
	{"getWeekLength", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getWeekLength, int32_t)},
	{"getYearLength", "(Lsun/util/calendar/CalendarDate;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getYearLength, int32_t, $CalendarDate*)},
	{"getYearLengthInMonths", "(Lsun/util/calendar/CalendarDate;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, getYearLengthInMonths, int32_t, $CalendarDate*)},
	{"initNames", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(CalendarSystem, initNames, void)},
	{"newCalendarDate", "()Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, newCalendarDate, $CalendarDate*)},
	{"newCalendarDate", "(Ljava/util/TimeZone;)Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, newCalendarDate, $CalendarDate*, $TimeZone*)},
	{"normalize", "(Lsun/util/calendar/CalendarDate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, normalize, bool, $CalendarDate*)},
	{"setEra", "(Lsun/util/calendar/CalendarDate;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, setEra, void, $CalendarDate*, $String*)},
	{"setTimeOfDay", "(Lsun/util/calendar/CalendarDate;I)Lsun/util/calendar/CalendarDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, setTimeOfDay, $CalendarDate*, $CalendarDate*, int32_t)},
	{"validate", "(Lsun/util/calendar/CalendarDate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CalendarSystem, validate, bool, $CalendarDate*)},
	{}
};

$ClassInfo _CalendarSystem_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.util.calendar.CalendarSystem",
	"java.lang.Object",
	nullptr,
	_CalendarSystem_FieldInfo_,
	_CalendarSystem_MethodInfo_
};

$Object* allocate$CalendarSystem($Class* clazz) {
	return $of($alloc(CalendarSystem));
}

$volatile(bool) CalendarSystem::initialized = false;
$ConcurrentMap* CalendarSystem::names = nullptr;
$ConcurrentMap* CalendarSystem::calendars = nullptr;
$String* CalendarSystem::PACKAGE_NAME = nullptr;
$StringArray* CalendarSystem::namePairs = nullptr;
$Gregorian* CalendarSystem::GREGORIAN_INSTANCE = nullptr;

void CalendarSystem::init$() {
}

void CalendarSystem::initNames() {
	$init(CalendarSystem);
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentMap, nameMap, $new($ConcurrentHashMap));
	$var($StringBuilder, clName, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(CalendarSystem::namePairs)->length; i += 2) {
		clName->setLength(0);
		$var($String, cl, clName->append(CalendarSystem::PACKAGE_NAME)->append($nc(CalendarSystem::namePairs)->get(i + 1))->toString());
		nameMap->put($nc(CalendarSystem::namePairs)->get(i), cl);
	}
	$synchronized(CalendarSystem::class$) {
		if (!CalendarSystem::initialized) {
			$assignStatic(CalendarSystem::names, nameMap);
			$assignStatic(CalendarSystem::calendars, $new($ConcurrentHashMap));
			CalendarSystem::initialized = true;
		}
	}
}

$Gregorian* CalendarSystem::getGregorianCalendar() {
	$init(CalendarSystem);
	return CalendarSystem::GREGORIAN_INSTANCE;
}

CalendarSystem* CalendarSystem::forName($String* calendarName) {
	$init(CalendarSystem);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ("gregorian"_s->equals(calendarName)) {
		return CalendarSystem::GREGORIAN_INSTANCE;
	}
	if (!CalendarSystem::initialized) {
		initNames();
	}
	$var(CalendarSystem, cal, $cast(CalendarSystem, $nc(CalendarSystem::calendars)->get(calendarName)));
	if (cal != nullptr) {
		return cal;
	}
	$var($String, className, $cast($String, $nc(CalendarSystem::names)->get(calendarName)));
	if (className == nullptr) {
		return nullptr;
	}
	if ($nc(className)->endsWith("LocalGregorianCalendar"_s)) {
		$assign(cal, $LocalGregorianCalendar::getLocalGregorianCalendar(calendarName));
	} else {
		try {
			$var($Object, tmp, $Class::forName(className)->newInstance());
			$assign(cal, $cast(CalendarSystem, tmp));
		} catch ($Exception& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	if (cal == nullptr) {
		return nullptr;
	}
	$var(CalendarSystem, cs, $cast(CalendarSystem, $nc(CalendarSystem::calendars)->putIfAbsent(calendarName, cal)));
	return (cs == nullptr) ? cal : cs;
}

void clinit$CalendarSystem($Class* class$) {
	$assignStatic(CalendarSystem::PACKAGE_NAME, "sun.util.calendar."_s);
	$assignStatic(CalendarSystem::namePairs, $new($StringArray, {
		"gregorian"_s,
		"Gregorian"_s,
		"japanese"_s,
		"LocalGregorianCalendar"_s,
		"julian"_s,
		"JulianCalendar"_s
	}));
	$assignStatic(CalendarSystem::GREGORIAN_INSTANCE, $new($Gregorian));
}

CalendarSystem::CalendarSystem() {
}

$Class* CalendarSystem::load$($String* name, bool initialize) {
	$loadClass(CalendarSystem, name, initialize, &_CalendarSystem_ClassInfo_, clinit$CalendarSystem, allocate$CalendarSystem);
	return class$;
}

$Class* CalendarSystem::class$ = nullptr;

		} // calendar
	} // util
} // sun