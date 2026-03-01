#include <java/text/DateFormat$Field.h>

#include <java/io/InvalidObjectException.h>
#include <java/text/AttributedCharacterIterator$Attribute.h>
#include <java/text/DateFormat.h>
#include <java/text/Format$Field.h>
#include <java/util/Calendar.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef AM_PM
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_WEEK_IN_MONTH
#undef DAY_OF_YEAR
#undef ERA
#undef FIELD_COUNT
#undef HOUR
#undef HOUR0
#undef HOUR1
#undef HOUR_OF_DAY
#undef HOUR_OF_DAY0
#undef HOUR_OF_DAY1
#undef MILLISECOND
#undef MINUTE
#undef MONTH
#undef SECOND
#undef TIME_ZONE
#undef WEEK_OF_MONTH
#undef WEEK_OF_YEAR
#undef YEAR

using $DateFormat$FieldArray = $Array<::java::text::DateFormat$Field>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Format$Field = ::java::text::Format$Field;
using $Calendar = ::java::util::Calendar;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace java {
	namespace text {

$FieldInfo _DateFormat$Field_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DateFormat$Field, serialVersionUID)},
	{"instanceMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/text/DateFormat$Field;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateFormat$Field, instanceMap)},
	{"calendarToFieldMapping", "[Ljava/text/DateFormat$Field;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DateFormat$Field, calendarToFieldMapping)},
	{"calendarField", "I", nullptr, $PRIVATE, $field(DateFormat$Field, calendarField)},
	{"ERA", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, ERA)},
	{"YEAR", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, YEAR)},
	{"MONTH", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, MONTH)},
	{"DAY_OF_MONTH", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, DAY_OF_MONTH)},
	{"HOUR_OF_DAY1", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, HOUR_OF_DAY1)},
	{"HOUR_OF_DAY0", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, HOUR_OF_DAY0)},
	{"MINUTE", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, MINUTE)},
	{"SECOND", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, SECOND)},
	{"MILLISECOND", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, MILLISECOND)},
	{"DAY_OF_WEEK", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, DAY_OF_WEEK)},
	{"DAY_OF_YEAR", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, DAY_OF_YEAR)},
	{"DAY_OF_WEEK_IN_MONTH", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, DAY_OF_WEEK_IN_MONTH)},
	{"WEEK_OF_YEAR", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, WEEK_OF_YEAR)},
	{"WEEK_OF_MONTH", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, WEEK_OF_MONTH)},
	{"AM_PM", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, AM_PM)},
	{"HOUR1", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, HOUR1)},
	{"HOUR0", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, HOUR0)},
	{"TIME_ZONE", "Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateFormat$Field, TIME_ZONE)},
	{}
};

$MethodInfo _DateFormat$Field_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PROTECTED, $method(DateFormat$Field, init$, void, $String*, int32_t)},
	{"getCalendarField", "()I", nullptr, $PUBLIC, $virtualMethod(DateFormat$Field, getCalendarField, int32_t)},
	{"ofCalendarField", "(I)Ljava/text/DateFormat$Field;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateFormat$Field, ofCalendarField, DateFormat$Field*, int32_t)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(DateFormat$Field, readResolve, $Object*), "java.io.InvalidObjectException"},
	{}
};

$InnerClassInfo _DateFormat$Field_InnerClassesInfo_[] = {
	{"java.text.DateFormat$Field", "java.text.DateFormat", "Field", $PUBLIC | $STATIC},
	{"java.text.Format$Field", "java.text.Format", "Field", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _DateFormat$Field_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.DateFormat$Field",
	"java.text.Format$Field",
	nullptr,
	_DateFormat$Field_FieldInfo_,
	_DateFormat$Field_MethodInfo_,
	nullptr,
	nullptr,
	_DateFormat$Field_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.text.DateFormat"
};

$Object* allocate$DateFormat$Field($Class* clazz) {
	return $of($alloc(DateFormat$Field));
}

$Map* DateFormat$Field::instanceMap = nullptr;
$DateFormat$FieldArray* DateFormat$Field::calendarToFieldMapping = nullptr;
DateFormat$Field* DateFormat$Field::ERA = nullptr;
DateFormat$Field* DateFormat$Field::YEAR = nullptr;
DateFormat$Field* DateFormat$Field::MONTH = nullptr;
DateFormat$Field* DateFormat$Field::DAY_OF_MONTH = nullptr;
DateFormat$Field* DateFormat$Field::HOUR_OF_DAY1 = nullptr;
DateFormat$Field* DateFormat$Field::HOUR_OF_DAY0 = nullptr;
DateFormat$Field* DateFormat$Field::MINUTE = nullptr;
DateFormat$Field* DateFormat$Field::SECOND = nullptr;
DateFormat$Field* DateFormat$Field::MILLISECOND = nullptr;
DateFormat$Field* DateFormat$Field::DAY_OF_WEEK = nullptr;
DateFormat$Field* DateFormat$Field::DAY_OF_YEAR = nullptr;
DateFormat$Field* DateFormat$Field::DAY_OF_WEEK_IN_MONTH = nullptr;
DateFormat$Field* DateFormat$Field::WEEK_OF_YEAR = nullptr;
DateFormat$Field* DateFormat$Field::WEEK_OF_MONTH = nullptr;
DateFormat$Field* DateFormat$Field::AM_PM = nullptr;
DateFormat$Field* DateFormat$Field::HOUR1 = nullptr;
DateFormat$Field* DateFormat$Field::HOUR0 = nullptr;
DateFormat$Field* DateFormat$Field::TIME_ZONE = nullptr;

DateFormat$Field* DateFormat$Field::ofCalendarField(int32_t calendarField) {
	$init(DateFormat$Field);
	$useLocalCurrentObjectStackCache();
	if (calendarField < 0 || calendarField >= $nc(DateFormat$Field::calendarToFieldMapping)->length) {
		$throwNew($IllegalArgumentException, $$str({"Unknown Calendar constant "_s, $$str(calendarField)}));
	}
	return $nc(DateFormat$Field::calendarToFieldMapping)->get(calendarField);
}

void DateFormat$Field::init$($String* name, int32_t calendarField) {
	$Format$Field::init$(name);
	this->calendarField = calendarField;
	if ($of(this)->getClass() == DateFormat$Field::class$) {
		$nc(DateFormat$Field::instanceMap)->put(name, this);
		if (calendarField >= 0) {
			$nc(DateFormat$Field::calendarToFieldMapping)->set(calendarField, this);
		}
	}
}

int32_t DateFormat$Field::getCalendarField() {
	return this->calendarField;
}

$Object* DateFormat$Field::readResolve() {
	$useLocalCurrentObjectStackCache();
	if ($of(this)->getClass() != DateFormat$Field::class$) {
		$throwNew($InvalidObjectException, "subclass didn\'t correctly implement readResolve"_s);
	}
	$var($Object, instance, $nc(DateFormat$Field::instanceMap)->get($(getName())));
	if (instance != nullptr) {
		return $of(instance);
	} else {
		$throwNew($InvalidObjectException, "unknown attribute name"_s);
	}
}

void clinit$DateFormat$Field($Class* class$) {
	$assignStatic(DateFormat$Field::instanceMap, $new($HashMap, 18));
	$assignStatic(DateFormat$Field::calendarToFieldMapping, $new($DateFormat$FieldArray, $Calendar::FIELD_COUNT));
	$assignStatic(DateFormat$Field::ERA, $new(DateFormat$Field, "era"_s, $Calendar::ERA));
	$assignStatic(DateFormat$Field::YEAR, $new(DateFormat$Field, "year"_s, $Calendar::YEAR));
	$assignStatic(DateFormat$Field::MONTH, $new(DateFormat$Field, "month"_s, $Calendar::MONTH));
	$assignStatic(DateFormat$Field::DAY_OF_MONTH, $new(DateFormat$Field, "day of month"_s, $Calendar::DAY_OF_MONTH));
	$assignStatic(DateFormat$Field::HOUR_OF_DAY1, $new(DateFormat$Field, "hour of day 1"_s, -1));
	$assignStatic(DateFormat$Field::HOUR_OF_DAY0, $new(DateFormat$Field, "hour of day"_s, $Calendar::HOUR_OF_DAY));
	$assignStatic(DateFormat$Field::MINUTE, $new(DateFormat$Field, "minute"_s, $Calendar::MINUTE));
	$assignStatic(DateFormat$Field::SECOND, $new(DateFormat$Field, "second"_s, $Calendar::SECOND));
	$assignStatic(DateFormat$Field::MILLISECOND, $new(DateFormat$Field, "millisecond"_s, $Calendar::MILLISECOND));
	$assignStatic(DateFormat$Field::DAY_OF_WEEK, $new(DateFormat$Field, "day of week"_s, $Calendar::DAY_OF_WEEK));
	$assignStatic(DateFormat$Field::DAY_OF_YEAR, $new(DateFormat$Field, "day of year"_s, $Calendar::DAY_OF_YEAR));
	$assignStatic(DateFormat$Field::DAY_OF_WEEK_IN_MONTH, $new(DateFormat$Field, "day of week in month"_s, $Calendar::DAY_OF_WEEK_IN_MONTH));
	$assignStatic(DateFormat$Field::WEEK_OF_YEAR, $new(DateFormat$Field, "week of year"_s, $Calendar::WEEK_OF_YEAR));
	$assignStatic(DateFormat$Field::WEEK_OF_MONTH, $new(DateFormat$Field, "week of month"_s, $Calendar::WEEK_OF_MONTH));
	$assignStatic(DateFormat$Field::AM_PM, $new(DateFormat$Field, "am pm"_s, $Calendar::AM_PM));
	$assignStatic(DateFormat$Field::HOUR1, $new(DateFormat$Field, "hour 1"_s, -1));
	$assignStatic(DateFormat$Field::HOUR0, $new(DateFormat$Field, "hour"_s, $Calendar::HOUR));
	$assignStatic(DateFormat$Field::TIME_ZONE, $new(DateFormat$Field, "time zone"_s, -1));
}

DateFormat$Field::DateFormat$Field() {
}

$Class* DateFormat$Field::load$($String* name, bool initialize) {
	$loadClass(DateFormat$Field, name, initialize, &_DateFormat$Field_ClassInfo_, clinit$DateFormat$Field, allocate$DateFormat$Field);
	return class$;
}

$Class* DateFormat$Field::class$ = nullptr;

	} // text
} // java