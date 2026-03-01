#include <java/util/Calendar.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OptionalDataException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/text/DateFormat.h>
#include <java/text/DateFormatSymbols.h>
#include <java/time/Instant.h>
#include <java/util/Calendar$1.h>
#include <java/util/Calendar$AvailableCalendarTypes.h>
#include <java/util/Calendar$CalendarAccessControlContext.h>
#include <java/util/Date.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/HashMap.h>
#include <java/util/JapaneseImperialCalendar.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/SimpleTimeZone.h>
#include <java/util/TimeZone.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/Function.h>
#include <sun/util/BuddhistCalendar.h>
#include <sun/util/calendar/ZoneInfo.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <sun/util/spi/CalendarProvider.h>
#include <jcpp.h>

#undef ALL_FIELDS
#undef ALL_STYLES
#undef AM
#undef AM_PM
#undef AM_PM_MASK
#undef APRIL
#undef AUGUST
#undef COMPUTED
#undef DATE
#undef DATE_MASK
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
#undef ERA
#undef ERA_MASK
#undef FEBRUARY
#undef FIELD_COUNT
#undef FIELD_NAME
#undef FORMAT
#undef FRIDAY
#undef HOUR
#undef HOUR_MASK
#undef HOUR_OF_DAY
#undef HOUR_OF_DAY_MASK
#undef ID
#undef INSTANCE
#undef JANUARY
#undef JULY
#undef JUNE
#undef LONG
#undef LONG_FORMAT
#undef LONG_STANDALONE
#undef MARCH
#undef MAX_VALUE
#undef MAY
#undef MILLISECOND
#undef MILLISECOND_MASK
#undef MINIMUM_USER_STAMP
#undef MINUTE
#undef MINUTE_MASK
#undef MONDAY
#undef MONTH
#undef MONTH_MASK
#undef NARROW_FORMAT
#undef NARROW_STANDALONE
#undef NOVEMBER
#undef OCTOBER
#undef PM
#undef SATURDAY
#undef SECOND
#undef SECOND_MASK
#undef SEPTEMBER
#undef SET
#undef SHORT
#undef SHORT_FORMAT
#undef SHORT_STANDALONE
#undef STANDALONE_MASK
#undef SUNDAY
#undef THURSDAY
#undef TUESDAY
#undef UNDECIMBER
#undef UNSET
#undef WEDNESDAY
#undef WEEK_OF_MONTH
#undef WEEK_OF_MONTH_MASK
#undef WEEK_OF_YEAR
#undef WEEK_OF_YEAR_MASK
#undef YEAR
#undef YEAR_MASK
#undef ZONE_OFFSET
#undef ZONE_OFFSET_MASK

using $LocaleArray = $Array<::java::util::Locale>;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OptionalDataException = ::java::io::OptionalDataException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $DateFormat = ::java::text::DateFormat;
using $DateFormatSymbols = ::java::text::DateFormatSymbols;
using $Instant = ::java::time::Instant;
using $Calendar$1 = ::java::util::Calendar$1;
using $Calendar$AvailableCalendarTypes = ::java::util::Calendar$AvailableCalendarTypes;
using $Calendar$CalendarAccessControlContext = ::java::util::Calendar$CalendarAccessControlContext;
using $Date = ::java::util::Date;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $HashMap = ::java::util::HashMap;
using $JapaneseImperialCalendar = ::java::util::JapaneseImperialCalendar;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $SimpleTimeZone = ::java::util::SimpleTimeZone;
using $TimeZone = ::java::util::TimeZone;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $Function = ::java::util::function::Function;
using $BuddhistCalendar = ::sun::util::BuddhistCalendar;
using $ZoneInfo = ::sun::util::calendar::ZoneInfo;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;
using $CalendarProvider = ::sun::util::spi::CalendarProvider;

namespace java {
	namespace util {

class Calendar$$Lambda$getTimeZone : public $Function {
	$class(Calendar$$Lambda$getTimeZone, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* ID) override {
		 return $of($TimeZone::getTimeZone($cast($String, ID)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Calendar$$Lambda$getTimeZone>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Calendar$$Lambda$getTimeZone::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Calendar$$Lambda$getTimeZone, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Calendar$$Lambda$getTimeZone, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Calendar$$Lambda$getTimeZone::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Calendar$$Lambda$getTimeZone",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Calendar$$Lambda$getTimeZone::load$($String* name, bool initialize) {
	$loadClass(Calendar$$Lambda$getTimeZone, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Calendar$$Lambda$getTimeZone::class$ = nullptr;

$FieldInfo _Calendar_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Calendar, $assertionsDisabled)},
	{"ERA", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, ERA)},
	{"YEAR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, YEAR)},
	{"MONTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, MONTH)},
	{"WEEK_OF_YEAR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, WEEK_OF_YEAR)},
	{"WEEK_OF_MONTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, WEEK_OF_MONTH)},
	{"DATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DATE)},
	{"DAY_OF_MONTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DAY_OF_MONTH)},
	{"DAY_OF_YEAR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DAY_OF_YEAR)},
	{"DAY_OF_WEEK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DAY_OF_WEEK)},
	{"DAY_OF_WEEK_IN_MONTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DAY_OF_WEEK_IN_MONTH)},
	{"AM_PM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, AM_PM)},
	{"HOUR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, HOUR)},
	{"HOUR_OF_DAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, HOUR_OF_DAY)},
	{"MINUTE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, MINUTE)},
	{"SECOND", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SECOND)},
	{"MILLISECOND", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, MILLISECOND)},
	{"ZONE_OFFSET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, ZONE_OFFSET)},
	{"DST_OFFSET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DST_OFFSET)},
	{"FIELD_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, FIELD_COUNT)},
	{"SUNDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SUNDAY)},
	{"MONDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, MONDAY)},
	{"TUESDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, TUESDAY)},
	{"WEDNESDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, WEDNESDAY)},
	{"THURSDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, THURSDAY)},
	{"FRIDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, FRIDAY)},
	{"SATURDAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SATURDAY)},
	{"JANUARY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, JANUARY)},
	{"FEBRUARY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, FEBRUARY)},
	{"MARCH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, MARCH)},
	{"APRIL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, APRIL)},
	{"MAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, MAY)},
	{"JUNE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, JUNE)},
	{"JULY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, JULY)},
	{"AUGUST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, AUGUST)},
	{"SEPTEMBER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SEPTEMBER)},
	{"OCTOBER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, OCTOBER)},
	{"NOVEMBER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, NOVEMBER)},
	{"DECEMBER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, DECEMBER)},
	{"UNDECIMBER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, UNDECIMBER)},
	{"AM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, AM)},
	{"PM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, PM)},
	{"ALL_STYLES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, ALL_STYLES)},
	{"STANDALONE_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, STANDALONE_MASK)},
	{"SHORT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SHORT)},
	{"LONG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, LONG)},
	{"NARROW_FORMAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, NARROW_FORMAT)},
	{"NARROW_STANDALONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, NARROW_STANDALONE)},
	{"SHORT_FORMAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SHORT_FORMAT)},
	{"LONG_FORMAT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, LONG_FORMAT)},
	{"SHORT_STANDALONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, SHORT_STANDALONE)},
	{"LONG_STANDALONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Calendar, LONG_STANDALONE)},
	{"fields", "[I", nullptr, $PROTECTED, $field(Calendar, fields)},
	{"isSet", "[Z", nullptr, $PROTECTED, $field(Calendar, isSet$)},
	{"stamp", "[I", nullptr, $PRIVATE | $TRANSIENT, $field(Calendar, stamp)},
	{"time", "J", nullptr, $PROTECTED, $field(Calendar, time)},
	{"isTimeSet", "Z", nullptr, $PROTECTED, $field(Calendar, isTimeSet)},
	{"areFieldsSet", "Z", nullptr, $PROTECTED, $field(Calendar, areFieldsSet)},
	{"areAllFieldsSet", "Z", nullptr, $TRANSIENT, $field(Calendar, areAllFieldsSet)},
	{"lenient", "Z", nullptr, $PRIVATE, $field(Calendar, lenient)},
	{"zone", "Ljava/util/TimeZone;", nullptr, $PRIVATE, $field(Calendar, zone)},
	{"sharedZone", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(Calendar, sharedZone)},
	{"firstDayOfWeek", "I", nullptr, $PRIVATE, $field(Calendar, firstDayOfWeek)},
	{"minimalDaysInFirstWeek", "I", nullptr, $PRIVATE, $field(Calendar, minimalDaysInFirstWeek)},
	{"cachedLocaleData", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;[I>;", $PRIVATE | $STATIC | $FINAL, $staticField(Calendar, cachedLocaleData)},
	{"UNSET", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Calendar, UNSET)},
	{"COMPUTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Calendar, COMPUTED)},
	{"MINIMUM_USER_STAMP", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Calendar, MINIMUM_USER_STAMP)},
	{"ALL_FIELDS", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, ALL_FIELDS)},
	{"nextStamp", "I", nullptr, $PRIVATE, $field(Calendar, nextStamp)},
	{"currentSerialVersion", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, currentSerialVersion)},
	{"serialVersionOnStream", "I", nullptr, $PRIVATE, $field(Calendar, serialVersionOnStream)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(Calendar, serialVersionUID)},
	{"ERA_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, ERA_MASK)},
	{"YEAR_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, YEAR_MASK)},
	{"MONTH_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, MONTH_MASK)},
	{"WEEK_OF_YEAR_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, WEEK_OF_YEAR_MASK)},
	{"WEEK_OF_MONTH_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, WEEK_OF_MONTH_MASK)},
	{"DAY_OF_MONTH_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, DAY_OF_MONTH_MASK)},
	{"DATE_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, DATE_MASK)},
	{"DAY_OF_YEAR_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, DAY_OF_YEAR_MASK)},
	{"DAY_OF_WEEK_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, DAY_OF_WEEK_MASK)},
	{"DAY_OF_WEEK_IN_MONTH_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, DAY_OF_WEEK_IN_MONTH_MASK)},
	{"AM_PM_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, AM_PM_MASK)},
	{"HOUR_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, HOUR_MASK)},
	{"HOUR_OF_DAY_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, HOUR_OF_DAY_MASK)},
	{"MINUTE_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, MINUTE_MASK)},
	{"SECOND_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, SECOND_MASK)},
	{"MILLISECOND_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, MILLISECOND_MASK)},
	{"ZONE_OFFSET_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, ZONE_OFFSET_MASK)},
	{"DST_OFFSET_MASK", "I", nullptr, $STATIC | $FINAL, $constField(Calendar, DST_OFFSET_MASK)},
	{"FIELD_NAME", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Calendar, FIELD_NAME)},
	{}
};

$MethodInfo _Calendar_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PROTECTED, $method(Calendar, init$, void)},
	{"<init>", "(Ljava/util/TimeZone;Ljava/util/Locale;)V", nullptr, $PROTECTED, $method(Calendar, init$, void, $TimeZone*, $Locale*)},
	{"add", "(II)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Calendar, add, void, int32_t, int32_t)},
	{"adjustStamp", "()V", nullptr, $PRIVATE, $method(Calendar, adjustStamp, void)},
	{"after", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Calendar, after, bool, Object$*)},
	{"aggregateStamp", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Calendar, aggregateStamp, int32_t, int32_t, int32_t)},
	{"appendValue", "(Ljava/lang/StringBuilder;Ljava/lang/String;ZJ)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Calendar, appendValue, void, $StringBuilder*, $String*, bool, int64_t)},
	{"before", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Calendar, before, bool, Object$*)},
	{"checkDisplayNameParams", "(IIIILjava/util/Locale;I)Z", nullptr, 0, $virtualMethod(Calendar, checkDisplayNameParams, bool, int32_t, int32_t, int32_t, int32_t, $Locale*, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC | $FINAL, $method(Calendar, clear, void)},
	{"clear", "(I)V", nullptr, $PUBLIC | $FINAL, $method(Calendar, clear, void, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Calendar, clone, $Object*)},
	{"compareTo", "(Ljava/util/Calendar;)I", nullptr, $PUBLIC, $virtualMethod(Calendar, compareTo, int32_t, Calendar*)},
	{"compareTo", "(J)I", nullptr, $PRIVATE, $method(Calendar, compareTo, int32_t, int64_t)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Calendar, compareTo, int32_t, Object$*)},
	{"complete", "()V", nullptr, $PROTECTED, $virtualMethod(Calendar, complete, void)},
	{"computeFields", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Calendar, computeFields, void)},
	{"computeTime", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Calendar, computeTime, void)},
	{"createCalendar", "(Ljava/util/TimeZone;Ljava/util/Locale;)Ljava/util/Calendar;", nullptr, $PRIVATE | $STATIC, $staticMethod(Calendar, createCalendar, Calendar*, $TimeZone*, $Locale*)},
	{"defaultTimeZone", "(Ljava/util/Locale;)Ljava/util/TimeZone;", nullptr, $PRIVATE | $STATIC, $staticMethod(Calendar, defaultTimeZone, $TimeZone*, $Locale*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Calendar, equals, bool, Object$*)},
	{"get", "(I)I", nullptr, $PUBLIC, $virtualMethod(Calendar, get, int32_t, int32_t)},
	{"getActualMaximum", "(I)I", nullptr, $PUBLIC, $virtualMethod(Calendar, getActualMaximum, int32_t, int32_t)},
	{"getActualMinimum", "(I)I", nullptr, $PUBLIC, $virtualMethod(Calendar, getActualMinimum, int32_t, int32_t)},
	{"getAvailableCalendarTypes", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Calendar, getAvailableCalendarTypes, $Set*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Calendar, getAvailableLocales, $LocaleArray*)},
	{"getBaseStyle", "(I)I", nullptr, 0, $virtualMethod(Calendar, getBaseStyle, int32_t, int32_t)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Calendar, getCalendarType, $String*)},
	{"getDisplayName", "(IILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Calendar, getDisplayName, $String*, int32_t, int32_t, $Locale*)},
	{"getDisplayNames", "(IILjava/util/Locale;)Ljava/util/Map;", "(IILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PUBLIC, $virtualMethod(Calendar, getDisplayNames, $Map*, int32_t, int32_t, $Locale*)},
	{"getDisplayNamesImpl", "(IILjava/util/Locale;)Ljava/util/Map;", "(IILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE, $method(Calendar, getDisplayNamesImpl, $Map*, int32_t, int32_t, $Locale*)},
	{"getFieldName", "(I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Calendar, getFieldName, $String*, int32_t)},
	{"getFieldStrings", "(IILjava/text/DateFormatSymbols;)[Ljava/lang/String;", nullptr, $PRIVATE, $method(Calendar, getFieldStrings, $StringArray*, int32_t, int32_t, $DateFormatSymbols*)},
	{"getFirstDayOfWeek", "()I", nullptr, $PUBLIC, $virtualMethod(Calendar, getFirstDayOfWeek, int32_t)},
	{"getGreatestMinimum", "(I)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Calendar, getGreatestMinimum, int32_t, int32_t)},
	{"getInstance", "()Ljava/util/Calendar;", nullptr, $PUBLIC | $STATIC, $staticMethod(Calendar, getInstance, Calendar*)},
	{"getInstance", "(Ljava/util/TimeZone;)Ljava/util/Calendar;", nullptr, $PUBLIC | $STATIC, $staticMethod(Calendar, getInstance, Calendar*, $TimeZone*)},
	{"getInstance", "(Ljava/util/Locale;)Ljava/util/Calendar;", nullptr, $PUBLIC | $STATIC, $staticMethod(Calendar, getInstance, Calendar*, $Locale*)},
	{"getInstance", "(Ljava/util/TimeZone;Ljava/util/Locale;)Ljava/util/Calendar;", nullptr, $PUBLIC | $STATIC, $staticMethod(Calendar, getInstance, Calendar*, $TimeZone*, $Locale*)},
	{"getLeastMaximum", "(I)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Calendar, getLeastMaximum, int32_t, int32_t)},
	{"getMaximum", "(I)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Calendar, getMaximum, int32_t, int32_t)},
	{"getMillisOf", "(Ljava/util/Calendar;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(Calendar, getMillisOf, int64_t, Calendar*)},
	{"getMinimalDaysInFirstWeek", "()I", nullptr, $PUBLIC, $virtualMethod(Calendar, getMinimalDaysInFirstWeek, int32_t)},
	{"getMinimum", "(I)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Calendar, getMinimum, int32_t, int32_t)},
	{"getSetStateFields", "()I", nullptr, $FINAL, $method(Calendar, getSetStateFields, int32_t)},
	{"getTime", "()Ljava/util/Date;", nullptr, $PUBLIC | $FINAL, $method(Calendar, getTime, $Date*)},
	{"getTimeInMillis", "()J", nullptr, $PUBLIC, $virtualMethod(Calendar, getTimeInMillis, int64_t)},
	{"getTimeZone", "()Ljava/util/TimeZone;", nullptr, $PUBLIC, $virtualMethod(Calendar, getTimeZone, $TimeZone*)},
	{"getWeekYear", "()I", nullptr, $PUBLIC, $virtualMethod(Calendar, getWeekYear, int32_t)},
	{"getWeeksInWeekYear", "()I", nullptr, $PUBLIC, $virtualMethod(Calendar, getWeeksInWeekYear, int32_t)},
	{"getZone", "()Ljava/util/TimeZone;", nullptr, 0, $virtualMethod(Calendar, getZone, $TimeZone*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Calendar, hashCode, int32_t)},
	{"internalGet", "(I)I", nullptr, $PROTECTED | $FINAL, $method(Calendar, internalGet, int32_t, int32_t)},
	{"internalSet", "(II)V", nullptr, $FINAL, $method(Calendar, internalSet, void, int32_t, int32_t)},
	{"invalidateWeekFields", "()V", nullptr, $PRIVATE, $method(Calendar, invalidateWeekFields, void)},
	{"isExternallySet", "(I)Z", nullptr, $FINAL, $method(Calendar, isExternallySet, bool, int32_t)},
	{"isFieldSet", "(II)Z", nullptr, $STATIC, $staticMethod(Calendar, isFieldSet, bool, int32_t, int32_t)},
	{"isFullyNormalized", "()Z", nullptr, $FINAL, $method(Calendar, isFullyNormalized, bool)},
	{"isLenient", "()Z", nullptr, $PUBLIC, $virtualMethod(Calendar, isLenient, bool)},
	{"isNarrowFormatStyle", "(I)Z", nullptr, $PRIVATE, $method(Calendar, isNarrowFormatStyle, bool, int32_t)},
	{"isNarrowStyle", "(I)Z", nullptr, $PRIVATE, $method(Calendar, isNarrowStyle, bool, int32_t)},
	{"isPartiallyNormalized", "()Z", nullptr, $FINAL, $method(Calendar, isPartiallyNormalized, bool)},
	{"isSet", "(I)Z", nullptr, $PUBLIC | $FINAL, $method(Calendar, isSet, bool, int32_t)},
	{"isStandaloneStyle", "(I)Z", nullptr, $PRIVATE, $method(Calendar, isStandaloneStyle, bool, int32_t)},
	{"isWeekDateSupported", "()Z", nullptr, $PUBLIC, $virtualMethod(Calendar, isWeekDateSupported, bool)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Calendar, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"roll", "(IZ)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Calendar, roll, void, int32_t, bool)},
	{"roll", "(II)V", nullptr, $PUBLIC, $virtualMethod(Calendar, roll, void, int32_t, int32_t)},
	{"selectFields", "()I", nullptr, $FINAL, $method(Calendar, selectFields, int32_t)},
	{"set", "(II)V", nullptr, $PUBLIC, $virtualMethod(Calendar, set, void, int32_t, int32_t)},
	{"set", "(III)V", nullptr, $PUBLIC | $FINAL, $method(Calendar, set, void, int32_t, int32_t, int32_t)},
	{"set", "(IIIII)V", nullptr, $PUBLIC | $FINAL, $method(Calendar, set, void, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"set", "(IIIIII)V", nullptr, $PUBLIC | $FINAL, $method(Calendar, set, void, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"setFieldsComputed", "(I)V", nullptr, $FINAL, $method(Calendar, setFieldsComputed, void, int32_t)},
	{"setFieldsNormalized", "(I)V", nullptr, $FINAL, $method(Calendar, setFieldsNormalized, void, int32_t)},
	{"setFirstDayOfWeek", "(I)V", nullptr, $PUBLIC, $virtualMethod(Calendar, setFirstDayOfWeek, void, int32_t)},
	{"setLenient", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Calendar, setLenient, void, bool)},
	{"setMinimalDaysInFirstWeek", "(I)V", nullptr, $PUBLIC, $virtualMethod(Calendar, setMinimalDaysInFirstWeek, void, int32_t)},
	{"setTime", "(Ljava/util/Date;)V", nullptr, $PUBLIC | $FINAL, $method(Calendar, setTime, void, $Date*)},
	{"setTimeInMillis", "(J)V", nullptr, $PUBLIC, $virtualMethod(Calendar, setTimeInMillis, void, int64_t)},
	{"setTimeZone", "(Ljava/util/TimeZone;)V", nullptr, $PUBLIC, $virtualMethod(Calendar, setTimeZone, void, $TimeZone*)},
	{"setUnnormalized", "()V", nullptr, $FINAL, $method(Calendar, setUnnormalized, void)},
	{"setWeekCountData", "(Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Calendar, setWeekCountData, void, $Locale*)},
	{"setWeekDate", "(III)V", nullptr, $PUBLIC, $virtualMethod(Calendar, setWeekDate, void, int32_t, int32_t, int32_t)},
	{"setZoneShared", "(Z)V", nullptr, 0, $virtualMethod(Calendar, setZoneShared, void, bool)},
	{"toInstant", "()Ljava/time/Instant;", nullptr, $PUBLIC | $FINAL, $method(Calendar, toInstant, $Instant*)},
	{"toStandaloneStyle", "(I)I", nullptr, $PRIVATE, $method(Calendar, toStandaloneStyle, int32_t, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Calendar, toString, $String*)},
	{"updateTime", "()V", nullptr, $PRIVATE, $method(Calendar, updateTime, void)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(Calendar, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Calendar_InnerClassesInfo_[] = {
	{"java.util.Calendar$CalendarAccessControlContext", "java.util.Calendar", "CalendarAccessControlContext", $PRIVATE | $STATIC},
	{"java.util.Calendar$AvailableCalendarTypes", "java.util.Calendar", "AvailableCalendarTypes", $PRIVATE | $STATIC},
	{"java.util.Calendar$Builder", "java.util.Calendar", "Builder", $PUBLIC | $STATIC},
	{"java.util.Calendar$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Calendar_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.Calendar",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable,java.lang.Comparable",
	_Calendar_FieldInfo_,
	_Calendar_MethodInfo_,
	"Ljava/lang/Object;Ljava/io/Serializable;Ljava/lang/Cloneable;Ljava/lang/Comparable<Ljava/util/Calendar;>;",
	nullptr,
	_Calendar_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Calendar$CalendarAccessControlContext,java.util.Calendar$AvailableCalendarTypes,java.util.Calendar$Builder,java.util.Calendar$1"
};

$Object* allocate$Calendar($Class* clazz) {
	return $of($alloc(Calendar));
}

void Calendar::finalize() {
	this->$Serializable::finalize();
}

bool Calendar::$assertionsDisabled = false;
$ConcurrentMap* Calendar::cachedLocaleData = nullptr;
$StringArray* Calendar::FIELD_NAME = nullptr;

void Calendar::init$() {
	$useLocalCurrentObjectStackCache();
	$var($TimeZone, var$0, $TimeZone::getDefaultRef());
	$init($Locale$Category);
	Calendar::init$(var$0, $($Locale::getDefault($Locale$Category::FORMAT)));
	this->sharedZone = true;
}

void Calendar::init$($TimeZone* zone, $Locale* aLocale) {
	this->lenient = true;
	this->sharedZone = false;
	this->nextStamp = Calendar::MINIMUM_USER_STAMP;
	this->serialVersionOnStream = Calendar::currentSerialVersion;
	$set(this, fields, $new($ints, Calendar::FIELD_COUNT));
	$set(this, isSet$, $new($booleans, Calendar::FIELD_COUNT));
	$set(this, stamp, $new($ints, Calendar::FIELD_COUNT));
	$set(this, zone, zone);
	setWeekCountData(aLocale);
}

Calendar* Calendar::getInstance() {
	$init(Calendar);
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	$var($Locale, aLocale, $Locale::getDefault($Locale$Category::FORMAT));
	return createCalendar($(defaultTimeZone(aLocale)), aLocale);
}

Calendar* Calendar::getInstance($TimeZone* zone) {
	$init(Calendar);
	$init($Locale$Category);
	return createCalendar(zone, $($Locale::getDefault($Locale$Category::FORMAT)));
}

Calendar* Calendar::getInstance($Locale* aLocale) {
	$init(Calendar);
	return createCalendar($(defaultTimeZone(aLocale)), aLocale);
}

Calendar* Calendar::getInstance($TimeZone* zone, $Locale* aLocale) {
	$init(Calendar);
	return createCalendar(zone, aLocale);
}

$TimeZone* Calendar::defaultTimeZone($Locale* l) {
	$init(Calendar);
	$useLocalCurrentObjectStackCache();
	$var($TimeZone, defaultTZ, $TimeZone::getDefault());
	$var($String, shortTZID, $nc(l)->getUnicodeLocaleType("tz"_s));
	return shortTZID != nullptr ? $cast($TimeZone, $nc($($nc($($TimeZoneNameUtility::convertLDMLShortID(shortTZID)))->map(static_cast<$Function*>($$new(Calendar$$Lambda$getTimeZone)))))->orElse(defaultTZ)) : defaultTZ;
}

Calendar* Calendar::createCalendar($TimeZone* zone, $Locale* aLocale) {
	$init(Calendar);
	$useLocalCurrentObjectStackCache();
	$load($CalendarProvider);
	$var($CalendarProvider, provider, $nc($($LocaleProviderAdapter::getAdapter($CalendarProvider::class$, aLocale)))->getCalendarProvider());
	if (provider != nullptr) {
		try {
			return provider->getInstance(zone, aLocale);
		} catch ($IllegalArgumentException& iae) {
		}
	}
	$var(Calendar, cal, nullptr);
	if ($nc(aLocale)->hasExtensions()) {
		$var($String, caltype, aLocale->getUnicodeLocaleType("ca"_s));
		if (caltype != nullptr) {
			$var($String, s69020$, caltype);
			int32_t tmp69020$ = -1;
			switch (s69020$->hashCode()) {
			case (int32_t)0xA1C2EDB5:
				{
					if (s69020$->equals("buddhist"_s)) {
						tmp69020$ = 0;
					}
					break;
				}
			case (int32_t)0xD3223FB1:
				{
					if (s69020$->equals("japanese"_s)) {
						tmp69020$ = 1;
					}
					break;
				}
			case 0x10EA1509:
				{
					if (s69020$->equals("gregory"_s)) {
						tmp69020$ = 2;
					}
					break;
				}
			}

			$var(Calendar, var$0, nullptr)
			switch (tmp69020$) {
			case 0:
				{
					$assign(var$0, $new($BuddhistCalendar, zone, aLocale));
					break;
				}
			case 1:
				{
					$assign(var$0, $new($JapaneseImperialCalendar, zone, aLocale));
					break;
				}
			case 2:
				{
					$assign(var$0, $new($GregorianCalendar, zone, aLocale));
					break;
				}
			default:
				{
					$assign(var$0, nullptr);
					break;
				}
			}
			$assign(cal, var$0);
		}
	}
	if (cal == nullptr) {
		bool var$1 = $nc(aLocale)->getLanguage() == "th"_s;
		if (var$1 && aLocale->getCountry() == "TH"_s) {
			$assign(cal, $new($BuddhistCalendar, zone, aLocale));
		} else {
			bool var$5 = aLocale->getVariant() == "JP"_s;
			bool var$4 = var$5 && aLocale->getLanguage() == "ja"_s;
			if (var$4 && aLocale->getCountry() == "JP"_s) {
				$assign(cal, $new($JapaneseImperialCalendar, zone, aLocale));
			} else {
				$assign(cal, $new($GregorianCalendar, zone, aLocale));
			}
		}
	}
	return cal;
}

$LocaleArray* Calendar::getAvailableLocales() {
	$load(Calendar);
	$synchronized(class$) {
		$init(Calendar);
		return $DateFormat::getAvailableLocales();
	}
}

$Date* Calendar::getTime() {
	return $new($Date, getTimeInMillis());
}

void Calendar::setTime($Date* date) {
	$Objects::requireNonNull($of(date), "date must not be null"_s);
	setTimeInMillis($nc(date)->getTime());
}

int64_t Calendar::getTimeInMillis() {
	if (!this->isTimeSet) {
		updateTime();
	}
	return this->time;
}

void Calendar::setTimeInMillis(int64_t millis) {
	if (this->time == millis && this->isTimeSet && this->areFieldsSet && this->areAllFieldsSet && ($instanceOf($ZoneInfo, this->zone)) && !$nc(($cast($ZoneInfo, this->zone)))->isDirty()) {
		return;
	}
	this->time = millis;
	this->isTimeSet = true;
	this->areFieldsSet = false;
	computeFields();
	this->areAllFieldsSet = (this->areFieldsSet = true);
}

int32_t Calendar::get(int32_t field) {
	complete();
	return internalGet(field);
}

int32_t Calendar::internalGet(int32_t field) {
	return $nc(this->fields)->get(field);
}

void Calendar::internalSet(int32_t field, int32_t value) {
	$nc(this->fields)->set(field, value);
}

void Calendar::set(int32_t field, int32_t value) {
	if (this->areFieldsSet && !this->areAllFieldsSet) {
		computeFields();
	}
	internalSet(field, value);
	this->isTimeSet = false;
	this->areFieldsSet = false;
	$nc(this->isSet$)->set(field, true);
	$nc(this->stamp)->set(field, this->nextStamp++);
	if (this->nextStamp == $Integer::MAX_VALUE) {
		adjustStamp();
	}
}

void Calendar::set(int32_t year, int32_t month, int32_t date) {
	set(Calendar::YEAR, year);
	set(Calendar::MONTH, month);
	set(Calendar::DATE, date);
}

void Calendar::set(int32_t year, int32_t month, int32_t date, int32_t hourOfDay, int32_t minute) {
	set(Calendar::YEAR, year);
	set(Calendar::MONTH, month);
	set(Calendar::DATE, date);
	set(Calendar::HOUR_OF_DAY, hourOfDay);
	set(Calendar::MINUTE, minute);
}

void Calendar::set(int32_t year, int32_t month, int32_t date, int32_t hourOfDay, int32_t minute, int32_t second) {
	set(Calendar::YEAR, year);
	set(Calendar::MONTH, month);
	set(Calendar::DATE, date);
	set(Calendar::HOUR_OF_DAY, hourOfDay);
	set(Calendar::MINUTE, minute);
	set(Calendar::SECOND, second);
}

void Calendar::clear() {
	for (int32_t i = 0; i < $nc(this->fields)->length;) {
		int32_t var$0 = i;
		$nc(this->stamp)->set(var$0, $nc(this->fields)->set(i, 0));
		$nc(this->isSet$)->set(i++, false);
	}
	this->areAllFieldsSet = (this->areFieldsSet = false);
	this->isTimeSet = false;
}

void Calendar::clear(int32_t field) {
	$nc(this->fields)->set(field, 0);
	$nc(this->stamp)->set(field, Calendar::UNSET);
	$nc(this->isSet$)->set(field, false);
	this->areAllFieldsSet = (this->areFieldsSet = false);
	this->isTimeSet = false;
}

bool Calendar::isSet(int32_t field) {
	return $nc(this->stamp)->get(field) != Calendar::UNSET;
}

$String* Calendar::getDisplayName(int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (!checkDisplayNameParams(field, style, Calendar::SHORT, Calendar::NARROW_FORMAT, locale, ((Calendar::ERA_MASK | Calendar::MONTH_MASK) | Calendar::DAY_OF_WEEK_MASK) | Calendar::AM_PM_MASK)) {
		return nullptr;
	}
	$var($String, calendarType, getCalendarType());
	int32_t fieldValue = get(field);
	bool var$0 = isStandaloneStyle(style);
	if (var$0 || isNarrowFormatStyle(style) || field == Calendar::ERA && ((int32_t)(style & (uint32_t)Calendar::SHORT)) == Calendar::SHORT) {
		$var($String, val, $CalendarDataUtility::retrieveFieldValueName(calendarType, field, fieldValue, style, locale));
		if (val == nullptr) {
			if (isNarrowFormatStyle(style)) {
				$assign(val, $CalendarDataUtility::retrieveFieldValueName(calendarType, field, fieldValue, toStandaloneStyle(style), locale));
			} else if (isStandaloneStyle(style)) {
				$assign(val, $CalendarDataUtility::retrieveFieldValueName(calendarType, field, fieldValue, getBaseStyle(style), locale));
			}
		}
		return val;
	}
	$var($DateFormatSymbols, symbols, $DateFormatSymbols::getInstance(locale));
	$var($StringArray, strings, getFieldStrings(field, style, symbols));
	if (strings != nullptr) {
		if (fieldValue < strings->length) {
			return strings->get(fieldValue);
		}
	}
	return nullptr;
}

$Map* Calendar::getDisplayNames(int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (!checkDisplayNameParams(field, style, Calendar::ALL_STYLES, Calendar::NARROW_FORMAT, locale, ((Calendar::ERA_MASK | Calendar::MONTH_MASK) | Calendar::DAY_OF_WEEK_MASK) | Calendar::AM_PM_MASK)) {
		return nullptr;
	}
	$var($String, calendarType, getCalendarType());
	bool var$0 = style == Calendar::ALL_STYLES || isStandaloneStyle(style);
	if (var$0 || isNarrowFormatStyle(style) || field == Calendar::ERA && ((int32_t)(style & (uint32_t)Calendar::SHORT)) == Calendar::SHORT) {
		$var($Map, map, nullptr);
		$assign(map, $CalendarDataUtility::retrieveFieldValueNames(calendarType, field, style, locale));
		if (map == nullptr) {
			if (isNarrowFormatStyle(style)) {
				$assign(map, $CalendarDataUtility::retrieveFieldValueNames(calendarType, field, toStandaloneStyle(style), locale));
			} else if (style != Calendar::ALL_STYLES) {
				$assign(map, $CalendarDataUtility::retrieveFieldValueNames(calendarType, field, getBaseStyle(style), locale));
			}
		}
		return map;
	}
	return getDisplayNamesImpl(field, style, locale);
}

$Map* Calendar::getDisplayNamesImpl(int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($DateFormatSymbols, symbols, $DateFormatSymbols::getInstance(locale));
	$var($StringArray, strings, getFieldStrings(field, style, symbols));
	if (strings != nullptr) {
		$var($Map, names, $new($HashMap));
		for (int32_t i = 0; i < strings->length; ++i) {
			if ($nc(strings->get(i))->isEmpty()) {
				continue;
			}
			names->put(strings->get(i), $($Integer::valueOf(i)));
		}
		return names;
	}
	return nullptr;
}

bool Calendar::checkDisplayNameParams(int32_t field, int32_t style, int32_t minStyle, int32_t maxStyle, $Locale* locale, int32_t fieldMask) {
	int32_t baseStyle = getBaseStyle(style);
	if (field < 0 || field >= $nc(this->fields)->length || baseStyle < minStyle || baseStyle > maxStyle || baseStyle == 3) {
		$throwNew($IllegalArgumentException);
	}
	if (locale == nullptr) {
		$throwNew($NullPointerException);
	}
	return isFieldSet(fieldMask, field);
}

$StringArray* Calendar::getFieldStrings(int32_t field, int32_t style, $DateFormatSymbols* symbols) {
	int32_t baseStyle = getBaseStyle(style);
	if (baseStyle == Calendar::NARROW_FORMAT) {
		return nullptr;
	}

	$var($StringArray, var$0, nullptr)
	switch (field) {
	case Calendar::ERA:
		{
			$assign(var$0, $nc(symbols)->getEras());
			break;
		}
	case Calendar::MONTH:
		{
			$assign(var$0, (baseStyle == Calendar::LONG) ? $nc(symbols)->getMonths() : symbols->getShortMonths());
			break;
		}
	case Calendar::DAY_OF_WEEK:
		{
			$assign(var$0, (baseStyle == Calendar::LONG) ? $nc(symbols)->getWeekdays() : symbols->getShortWeekdays());
			break;
		}
	case Calendar::AM_PM:
		{
			$assign(var$0, $nc(symbols)->getAmPmStrings());
			break;
		}
	default:
		{
			$assign(var$0, nullptr);
			break;
		}
	}
	return var$0;
}

void Calendar::complete() {
	if (!this->isTimeSet) {
		updateTime();
	}
	if (!this->areFieldsSet || !this->areAllFieldsSet) {
		computeFields();
		this->areAllFieldsSet = (this->areFieldsSet = true);
	}
}

bool Calendar::isExternallySet(int32_t field) {
	return $nc(this->stamp)->get(field) >= Calendar::MINIMUM_USER_STAMP;
}

int32_t Calendar::getSetStateFields() {
	int32_t mask = 0;
	for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
		if ($nc(this->stamp)->get(i) != Calendar::UNSET) {
			mask |= $sl(1, i);
		}
	}
	return mask;
}

void Calendar::setFieldsComputed(int32_t fieldMask) {
	if (fieldMask == Calendar::ALL_FIELDS) {
		for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
			$nc(this->stamp)->set(i, Calendar::COMPUTED);
			$nc(this->isSet$)->set(i, true);
		}
		this->areFieldsSet = (this->areAllFieldsSet = true);
	} else {
		for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
			if (((int32_t)(fieldMask & (uint32_t)1)) == 1) {
				$nc(this->stamp)->set(i, Calendar::COMPUTED);
				$nc(this->isSet$)->set(i, true);
			} else if (this->areAllFieldsSet && !$nc(this->isSet$)->get(i)) {
				this->areAllFieldsSet = false;
			}
			$usrAssign(fieldMask, 1);
		}
	}
}

void Calendar::setFieldsNormalized(int32_t fieldMask) {
	if (fieldMask != Calendar::ALL_FIELDS) {
		for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
			if (((int32_t)(fieldMask & (uint32_t)1)) == 0) {
				int32_t var$0 = i;
				$nc(this->stamp)->set(var$0, $nc(this->fields)->set(i, 0));
				$nc(this->isSet$)->set(i, false);
			}
			fieldMask >>= 1;
		}
	}
	this->areFieldsSet = true;
	this->areAllFieldsSet = false;
}

bool Calendar::isPartiallyNormalized() {
	return this->areFieldsSet && !this->areAllFieldsSet;
}

bool Calendar::isFullyNormalized() {
	return this->areFieldsSet && this->areAllFieldsSet;
}

void Calendar::setUnnormalized() {
	this->areFieldsSet = (this->areAllFieldsSet = false);
}

bool Calendar::isFieldSet(int32_t fieldMask, int32_t field) {
	$init(Calendar);
	return ((int32_t)(fieldMask & (uint32_t)($sl(1, field)))) != 0;
}

int32_t Calendar::selectFields() {
	int32_t fieldMask = Calendar::YEAR_MASK;
	if ($nc(this->stamp)->get(Calendar::ERA) != Calendar::UNSET) {
		fieldMask |= Calendar::ERA_MASK;
	}
	int32_t dowStamp = $nc(this->stamp)->get(Calendar::DAY_OF_WEEK);
	int32_t monthStamp = $nc(this->stamp)->get(Calendar::MONTH);
	int32_t domStamp = $nc(this->stamp)->get(Calendar::DAY_OF_MONTH);
	int32_t womStamp = aggregateStamp($nc(this->stamp)->get(Calendar::WEEK_OF_MONTH), dowStamp);
	int32_t dowimStamp = aggregateStamp($nc(this->stamp)->get(Calendar::DAY_OF_WEEK_IN_MONTH), dowStamp);
	int32_t doyStamp = $nc(this->stamp)->get(Calendar::DAY_OF_YEAR);
	int32_t woyStamp = aggregateStamp($nc(this->stamp)->get(Calendar::WEEK_OF_YEAR), dowStamp);
	int32_t bestStamp = domStamp;
	if (womStamp > bestStamp) {
		bestStamp = womStamp;
	}
	if (dowimStamp > bestStamp) {
		bestStamp = dowimStamp;
	}
	if (doyStamp > bestStamp) {
		bestStamp = doyStamp;
	}
	if (woyStamp > bestStamp) {
		bestStamp = woyStamp;
	}
	if (bestStamp == Calendar::UNSET) {
		womStamp = $nc(this->stamp)->get(Calendar::WEEK_OF_MONTH);
		dowimStamp = $Math::max($nc(this->stamp)->get(Calendar::DAY_OF_WEEK_IN_MONTH), dowStamp);
		woyStamp = $nc(this->stamp)->get(Calendar::WEEK_OF_YEAR);
		bestStamp = $Math::max($Math::max(womStamp, dowimStamp), woyStamp);
		if (bestStamp == Calendar::UNSET) {
			bestStamp = (domStamp = monthStamp);
		}
	}
	if (bestStamp == domStamp || (bestStamp == womStamp && $nc(this->stamp)->get(Calendar::WEEK_OF_MONTH) >= $nc(this->stamp)->get(Calendar::WEEK_OF_YEAR)) || (bestStamp == dowimStamp && $nc(this->stamp)->get(Calendar::DAY_OF_WEEK_IN_MONTH) >= $nc(this->stamp)->get(Calendar::WEEK_OF_YEAR))) {
		fieldMask |= Calendar::MONTH_MASK;
		if (bestStamp == domStamp) {
			fieldMask |= Calendar::DAY_OF_MONTH_MASK;
		} else {
			if (!Calendar::$assertionsDisabled && !(bestStamp == womStamp || bestStamp == dowimStamp)) {
				$throwNew($AssertionError);
			}
			if (dowStamp != Calendar::UNSET) {
				fieldMask |= Calendar::DAY_OF_WEEK_MASK;
			}
			if (womStamp == dowimStamp) {
				if ($nc(this->stamp)->get(Calendar::WEEK_OF_MONTH) >= $nc(this->stamp)->get(Calendar::DAY_OF_WEEK_IN_MONTH)) {
					fieldMask |= Calendar::WEEK_OF_MONTH_MASK;
				} else {
					fieldMask |= Calendar::DAY_OF_WEEK_IN_MONTH_MASK;
				}
			} else if (bestStamp == womStamp) {
				fieldMask |= Calendar::WEEK_OF_MONTH_MASK;
			} else {
				if (!Calendar::$assertionsDisabled && !(bestStamp == dowimStamp)) {
					$throwNew($AssertionError);
				}
				if ($nc(this->stamp)->get(Calendar::DAY_OF_WEEK_IN_MONTH) != Calendar::UNSET) {
					fieldMask |= Calendar::DAY_OF_WEEK_IN_MONTH_MASK;
				}
			}
		}
	} else {
		if (!Calendar::$assertionsDisabled && !(bestStamp == doyStamp || bestStamp == woyStamp || bestStamp == Calendar::UNSET)) {
			$throwNew($AssertionError);
		}
		if (bestStamp == doyStamp) {
			fieldMask |= Calendar::DAY_OF_YEAR_MASK;
		} else {
			if (!Calendar::$assertionsDisabled && !(bestStamp == woyStamp)) {
				$throwNew($AssertionError);
			}
			if (dowStamp != Calendar::UNSET) {
				fieldMask |= Calendar::DAY_OF_WEEK_MASK;
			}
			fieldMask |= Calendar::WEEK_OF_YEAR_MASK;
		}
	}
	int32_t hourOfDayStamp = $nc(this->stamp)->get(Calendar::HOUR_OF_DAY);
	int32_t hourStamp = aggregateStamp($nc(this->stamp)->get(Calendar::HOUR), $nc(this->stamp)->get(Calendar::AM_PM));
	bestStamp = (hourStamp > hourOfDayStamp) ? hourStamp : hourOfDayStamp;
	if (bestStamp == Calendar::UNSET) {
		bestStamp = $Math::max($nc(this->stamp)->get(Calendar::HOUR), $nc(this->stamp)->get(Calendar::AM_PM));
	}
	if (bestStamp != Calendar::UNSET) {
		if (bestStamp == hourOfDayStamp) {
			fieldMask |= Calendar::HOUR_OF_DAY_MASK;
		} else {
			fieldMask |= Calendar::HOUR_MASK;
			if ($nc(this->stamp)->get(Calendar::AM_PM) != Calendar::UNSET) {
				fieldMask |= Calendar::AM_PM_MASK;
			}
		}
	}
	if ($nc(this->stamp)->get(Calendar::MINUTE) != Calendar::UNSET) {
		fieldMask |= Calendar::MINUTE_MASK;
	}
	if ($nc(this->stamp)->get(Calendar::SECOND) != Calendar::UNSET) {
		fieldMask |= Calendar::SECOND_MASK;
	}
	if ($nc(this->stamp)->get(Calendar::MILLISECOND) != Calendar::UNSET) {
		fieldMask |= Calendar::MILLISECOND_MASK;
	}
	if ($nc(this->stamp)->get(Calendar::ZONE_OFFSET) >= Calendar::MINIMUM_USER_STAMP) {
		fieldMask |= Calendar::ZONE_OFFSET_MASK;
	}
	if ($nc(this->stamp)->get(Calendar::DST_OFFSET) >= Calendar::MINIMUM_USER_STAMP) {
		fieldMask |= Calendar::DST_OFFSET_MASK;
	}
	return fieldMask;
}

int32_t Calendar::getBaseStyle(int32_t style) {
	return (int32_t)(style & (uint32_t)~Calendar::STANDALONE_MASK);
}

int32_t Calendar::toStandaloneStyle(int32_t style) {
	return style | Calendar::STANDALONE_MASK;
}

bool Calendar::isStandaloneStyle(int32_t style) {
	return ((int32_t)(style & (uint32_t)Calendar::STANDALONE_MASK)) != 0;
}

bool Calendar::isNarrowStyle(int32_t style) {
	return style == Calendar::NARROW_FORMAT || style == Calendar::NARROW_STANDALONE;
}

bool Calendar::isNarrowFormatStyle(int32_t style) {
	return style == Calendar::NARROW_FORMAT;
}

int32_t Calendar::aggregateStamp(int32_t stamp_a, int32_t stamp_b) {
	$init(Calendar);
	if (stamp_a == Calendar::UNSET || stamp_b == Calendar::UNSET) {
		return Calendar::UNSET;
	}
	return (stamp_a > stamp_b) ? stamp_a : stamp_b;
}

$Set* Calendar::getAvailableCalendarTypes() {
	$init(Calendar);
	$init($Calendar$AvailableCalendarTypes);
	return $Calendar$AvailableCalendarTypes::SET;
}

$String* Calendar::getCalendarType() {
	return $of(this)->getClass()->getName();
}

bool Calendar::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	try {
		$var(Calendar, that, $cast(Calendar, obj));
		bool var$0 = compareTo(getMillisOf(that)) == 0 && this->lenient == $nc(that)->lenient && this->firstDayOfWeek == that->firstDayOfWeek && this->minimalDaysInFirstWeek == that->minimalDaysInFirstWeek;
		return var$0 && ($instanceOf($ZoneInfo, this->zone) ? $nc($of(this->zone))->equals(that->zone) : $nc($of(this->zone))->equals($(that->getTimeZone())));
	} catch ($Exception& e) {
	}
	return false;
}

int32_t Calendar::hashCode() {
	int32_t otheritems = (((this->lenient ? 1 : 0) | (this->firstDayOfWeek << 1)) | (this->minimalDaysInFirstWeek << 4)) | ($nc($of(this->zone))->hashCode() << 7);
	int64_t t = getMillisOf(this);
	return ((int32_t)t ^ (int32_t)(t >> 32)) ^ otheritems;
}

bool Calendar::before(Object$* when) {
	return $instanceOf(Calendar, when) && compareTo($cast(Calendar, when)) < 0;
}

bool Calendar::after(Object$* when) {
	return $instanceOf(Calendar, when) && compareTo($cast(Calendar, when)) > 0;
}

int32_t Calendar::compareTo(Calendar* anotherCalendar) {
	return compareTo(getMillisOf(anotherCalendar));
}

void Calendar::roll(int32_t field, int32_t amount) {
	while (amount > 0) {
		roll(field, true);
		--amount;
	}
	while (amount < 0) {
		roll(field, false);
		++amount;
	}
}

void Calendar::setTimeZone($TimeZone* value) {
	$set(this, zone, value);
	this->sharedZone = false;
	this->areAllFieldsSet = (this->areFieldsSet = false);
}

$TimeZone* Calendar::getTimeZone() {
	if (this->sharedZone) {
		$set(this, zone, $cast($TimeZone, $nc(this->zone)->clone()));
		this->sharedZone = false;
	}
	return this->zone;
}

$TimeZone* Calendar::getZone() {
	return this->zone;
}

void Calendar::setZoneShared(bool shared) {
	this->sharedZone = shared;
}

void Calendar::setLenient(bool lenient) {
	this->lenient = lenient;
}

bool Calendar::isLenient() {
	return this->lenient;
}

void Calendar::setFirstDayOfWeek(int32_t value) {
	if (this->firstDayOfWeek == value) {
		return;
	}
	this->firstDayOfWeek = value;
	invalidateWeekFields();
}

int32_t Calendar::getFirstDayOfWeek() {
	return this->firstDayOfWeek;
}

void Calendar::setMinimalDaysInFirstWeek(int32_t value) {
	if (this->minimalDaysInFirstWeek == value) {
		return;
	}
	this->minimalDaysInFirstWeek = value;
	invalidateWeekFields();
}

int32_t Calendar::getMinimalDaysInFirstWeek() {
	return this->minimalDaysInFirstWeek;
}

bool Calendar::isWeekDateSupported() {
	return false;
}

int32_t Calendar::getWeekYear() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void Calendar::setWeekDate(int32_t weekYear, int32_t weekOfYear, int32_t dayOfWeek) {
	$throwNew($UnsupportedOperationException);
}

int32_t Calendar::getWeeksInWeekYear() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t Calendar::getActualMinimum(int32_t field) {
	int32_t fieldValue = getGreatestMinimum(field);
	int32_t endValue = getMinimum(field);
	if (fieldValue == endValue) {
		return fieldValue;
	}
	$var(Calendar, work, $cast(Calendar, this->clone()));
	$nc(work)->setLenient(true);
	int32_t result = fieldValue;
	do {
		work->set(field, fieldValue);
		if (work->get(field) != fieldValue) {
			break;
		} else {
			result = fieldValue;
			--fieldValue;
		}
	} while (fieldValue >= endValue);
	return result;
}

int32_t Calendar::getActualMaximum(int32_t field) {
	int32_t fieldValue = getLeastMaximum(field);
	int32_t endValue = getMaximum(field);
	if (fieldValue == endValue) {
		return fieldValue;
	}
	$var(Calendar, work, $cast(Calendar, this->clone()));
	$nc(work)->setLenient(true);
	if (field == Calendar::WEEK_OF_YEAR || field == Calendar::WEEK_OF_MONTH) {
		work->set(Calendar::DAY_OF_WEEK, this->firstDayOfWeek);
	}
	int32_t result = fieldValue;
	do {
		work->set(field, fieldValue);
		if (work->get(field) != fieldValue) {
			break;
		} else {
			result = fieldValue;
			++fieldValue;
		}
	} while (fieldValue <= endValue);
	return result;
}

$Object* Calendar::clone() {
	try {
		$var(Calendar, other, $cast(Calendar, $Serializable::clone()));
		$set($nc(other), fields, $new($ints, Calendar::FIELD_COUNT));
		$set(other, isSet$, $new($booleans, Calendar::FIELD_COUNT));
		$set(other, stamp, $new($ints, Calendar::FIELD_COUNT));
		for (int32_t i = 0; i < Calendar::FIELD_COUNT; ++i) {
			$nc(other->fields)->set(i, $nc(this->fields)->get(i));
			$nc(other->stamp)->set(i, $nc(this->stamp)->get(i));
			$nc(other->isSet$)->set(i, $nc(this->isSet$)->get(i));
		}
		if (!this->sharedZone) {
			$set(other, zone, $cast($TimeZone, $nc(this->zone)->clone()));
		}
		return $of(other);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$String* Calendar::getFieldName(int32_t field) {
	$init(Calendar);
	return $nc(Calendar::FIELD_NAME)->get(field);
}

$String* Calendar::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, buffer, $new($StringBuilder, 800));
	buffer->append($($of(this)->getClass()->getName()))->append(u'[');
	appendValue(buffer, "time"_s, this->isTimeSet, this->time);
	buffer->append(",areFieldsSet="_s)->append(this->areFieldsSet);
	buffer->append(",areAllFieldsSet="_s)->append(this->areAllFieldsSet);
	buffer->append(",lenient="_s)->append(this->lenient);
	buffer->append(",zone="_s)->append($of(this->zone));
	appendValue(buffer, ",firstDayOfWeek"_s, true, (int64_t)this->firstDayOfWeek);
	appendValue(buffer, ",minimalDaysInFirstWeek"_s, true, (int64_t)this->minimalDaysInFirstWeek);
	for (int32_t i = 0; i < Calendar::FIELD_COUNT; ++i) {
		buffer->append(u',');
		appendValue(buffer, $nc(Calendar::FIELD_NAME)->get(i), isSet(i), (int64_t)$nc(this->fields)->get(i));
	}
	buffer->append(u']');
	return buffer->toString();
}

void Calendar::appendValue($StringBuilder* sb, $String* item, bool valid, int64_t value) {
	$init(Calendar);
	$nc(sb)->append(item)->append(u'=');
	if (valid) {
		sb->append(value);
	} else {
		sb->append(u'?');
	}
}

void Calendar::setWeekCountData($Locale* desiredLocale) {
	$var($ints, data, $cast($ints, $nc(Calendar::cachedLocaleData)->get(desiredLocale)));
	if (data == nullptr) {
		$assign(data, $new($ints, 2));
		data->set(0, $CalendarDataUtility::retrieveFirstDayOfWeek(desiredLocale));
		data->set(1, $CalendarDataUtility::retrieveMinimalDaysInFirstWeek(desiredLocale));
		$nc(Calendar::cachedLocaleData)->putIfAbsent(desiredLocale, data);
	}
	this->firstDayOfWeek = $nc(data)->get(0);
	this->minimalDaysInFirstWeek = data->get(1);
}

void Calendar::updateTime() {
	computeTime();
	this->isTimeSet = true;
}

int32_t Calendar::compareTo(int64_t t) {
	int64_t thisTime = getMillisOf(this);
	return (thisTime > t) ? 1 : (thisTime == t) ? 0 : -1;
}

int64_t Calendar::getMillisOf(Calendar* calendar) {
	$init(Calendar);
	if ($nc(calendar)->isTimeSet) {
		return calendar->time;
	}
	$var(Calendar, cal, $cast(Calendar, $nc(calendar)->clone()));
	$nc(cal)->setLenient(true);
	return cal->getTimeInMillis();
}

void Calendar::adjustStamp() {
	$useLocalCurrentObjectStackCache();
	int32_t max = Calendar::MINIMUM_USER_STAMP;
	int32_t newStamp = Calendar::MINIMUM_USER_STAMP;
	for (;;) {
		int32_t min = $Integer::MAX_VALUE;
		{
			$var($ints, arr$, this->stamp);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				int32_t v = arr$->get(i$);
				{
					if (v >= newStamp && min > v) {
						min = v;
					}
					if (max < v) {
						max = v;
					}
				}
			}
		}
		if (max != min && min == $Integer::MAX_VALUE) {
			break;
		}
		for (int32_t i = 0; i < $nc(this->stamp)->length; ++i) {
			if ($nc(this->stamp)->get(i) == min) {
				$nc(this->stamp)->set(i, newStamp);
			}
		}
		++newStamp;
		if (min == max) {
			break;
		}
	}
	this->nextStamp = newStamp;
}

void Calendar::invalidateWeekFields() {
	if ($nc(this->stamp)->get(Calendar::WEEK_OF_MONTH) != Calendar::COMPUTED && $nc(this->stamp)->get(Calendar::WEEK_OF_YEAR) != Calendar::COMPUTED) {
		return;
	}
	$var(Calendar, cal, $cast(Calendar, clone()));
	$nc(cal)->setLenient(true);
	cal->clear(Calendar::WEEK_OF_MONTH);
	cal->clear(Calendar::WEEK_OF_YEAR);
	if ($nc(this->stamp)->get(Calendar::WEEK_OF_MONTH) == Calendar::COMPUTED) {
		int32_t weekOfMonth = cal->get(Calendar::WEEK_OF_MONTH);
		if ($nc(this->fields)->get(Calendar::WEEK_OF_MONTH) != weekOfMonth) {
			$nc(this->fields)->set(Calendar::WEEK_OF_MONTH, weekOfMonth);
		}
	}
	if ($nc(this->stamp)->get(Calendar::WEEK_OF_YEAR) == Calendar::COMPUTED) {
		int32_t weekOfYear = cal->get(Calendar::WEEK_OF_YEAR);
		if ($nc(this->fields)->get(Calendar::WEEK_OF_YEAR) != weekOfYear) {
			$nc(this->fields)->set(Calendar::WEEK_OF_YEAR, weekOfYear);
		}
	}
}

void Calendar::writeObject($ObjectOutputStream* stream) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (!this->isTimeSet) {
			try {
				updateTime();
			} catch ($IllegalArgumentException& e) {
			}
		}
		$var($TimeZone, savedZone, nullptr);
		if ($instanceOf($ZoneInfo, this->zone)) {
			$var($SimpleTimeZone, stz, $nc(($cast($ZoneInfo, this->zone)))->getLastRuleInstance());
			if (stz == nullptr) {
				int32_t var$0 = $nc(this->zone)->getRawOffset();
				$assign(stz, $new($SimpleTimeZone, var$0, $($nc(this->zone)->getID())));
			}
			$assign(savedZone, this->zone);
			$set(this, zone, stz);
		}
		$nc(stream)->defaultWriteObject();
		stream->writeObject(savedZone);
		if (savedZone != nullptr) {
			$set(this, zone, savedZone);
		}
	}
}

void Calendar::readObject($ObjectInputStream* stream) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ObjectInputStream, input, stream);
	$nc(input)->defaultReadObject();
	$set(this, stamp, $new($ints, Calendar::FIELD_COUNT));
	if (this->serialVersionOnStream >= 2) {
		this->isTimeSet = true;
		if (this->fields == nullptr) {
			$set(this, fields, $new($ints, Calendar::FIELD_COUNT));
		}
		if (this->isSet$ == nullptr) {
			$set(this, isSet$, $new($booleans, Calendar::FIELD_COUNT));
		}
	} else if (this->serialVersionOnStream >= 0) {
		for (int32_t i = 0; i < Calendar::FIELD_COUNT; ++i) {
			$nc(this->stamp)->set(i, $nc(this->isSet$)->get(i) ? Calendar::COMPUTED : Calendar::UNSET);
		}
	}
	this->serialVersionOnStream = Calendar::currentSerialVersion;
	$var($ZoneInfo, zi, nullptr);
	try {
		$init($Calendar$CalendarAccessControlContext);
		$assign(zi, $cast($ZoneInfo, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($Calendar$1, this, input)), $Calendar$CalendarAccessControlContext::INSTANCE)));
	} catch ($PrivilegedActionException& pae) {
		$var($Exception, e, pae->getException());
		if (!($instanceOf($OptionalDataException, e))) {
			if ($instanceOf($RuntimeException, e)) {
				$throw($cast($RuntimeException, e));
			} else if ($instanceOf($IOException, e)) {
				$throw($cast($IOException, e));
			} else if ($instanceOf($ClassNotFoundException, e)) {
				$throw($cast($ClassNotFoundException, e));
			}
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
	if (zi != nullptr) {
		$set(this, zone, zi);
	}
	if ($instanceOf($SimpleTimeZone, this->zone)) {
		$var($String, id, $nc(this->zone)->getID());
		$var($TimeZone, tz, $TimeZone::getTimeZone(id));
		bool var$0 = tz != nullptr && tz->hasSameRules(this->zone);
		if (var$0 && $nc($(tz->getID()))->equals(id)) {
			$set(this, zone, tz);
		}
	}
}

$Instant* Calendar::toInstant() {
	return $Instant::ofEpochMilli(getTimeInMillis());
}

int32_t Calendar::compareTo(Object$* anotherCalendar) {
	return this->compareTo($cast(Calendar, anotherCalendar));
}

void clinit$Calendar($Class* class$) {
	Calendar::$assertionsDisabled = !Calendar::class$->desiredAssertionStatus();
	$assignStatic(Calendar::cachedLocaleData, $new($ConcurrentHashMap, 3));
	$assignStatic(Calendar::FIELD_NAME, $new($StringArray, {
		"ERA"_s,
		"YEAR"_s,
		"MONTH"_s,
		"WEEK_OF_YEAR"_s,
		"WEEK_OF_MONTH"_s,
		"DAY_OF_MONTH"_s,
		"DAY_OF_YEAR"_s,
		"DAY_OF_WEEK"_s,
		"DAY_OF_WEEK_IN_MONTH"_s,
		"AM_PM"_s,
		"HOUR"_s,
		"HOUR_OF_DAY"_s,
		"MINUTE"_s,
		"SECOND"_s,
		"MILLISECOND"_s,
		"ZONE_OFFSET"_s,
		"DST_OFFSET"_s
	}));
}

Calendar::Calendar() {
}

$Class* Calendar::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Calendar$$Lambda$getTimeZone::classInfo$.name)) {
			return Calendar$$Lambda$getTimeZone::load$(name, initialize);
		}
	}
	$loadClass(Calendar, name, initialize, &_Calendar_ClassInfo_, clinit$Calendar, allocate$Calendar);
	return class$;
}

$Class* Calendar::class$ = nullptr;

	} // util
} // java