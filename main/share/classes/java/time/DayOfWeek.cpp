#include <java/time/DayOfWeek.h>

#include <java/lang/Enum.h>
#include <java/time/DateTimeException.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef DAYS
#undef DAY_OF_WEEK
#undef ENUMS
#undef FRIDAY
#undef MONDAY
#undef SATURDAY
#undef SUNDAY
#undef THURSDAY
#undef TUESDAY
#undef WEDNESDAY

using $DayOfWeekArray = $Array<::java::time::DayOfWeek>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $TextStyle = ::java::time::format::TextStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Locale = ::java::util::Locale;

namespace java {
	namespace time {

$FieldInfo _DayOfWeek_FieldInfo_[] = {
	{"MONDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, MONDAY)},
	{"TUESDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, TUESDAY)},
	{"WEDNESDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, WEDNESDAY)},
	{"THURSDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, THURSDAY)},
	{"FRIDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, FRIDAY)},
	{"SATURDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, SATURDAY)},
	{"SUNDAY", "Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(DayOfWeek, SUNDAY)},
	{"$VALUES", "[Ljava/time/DayOfWeek;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(DayOfWeek, $VALUES)},
	{"ENUMS", "[Ljava/time/DayOfWeek;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DayOfWeek, ENUMS)},
	{}
};

$MethodInfo _DayOfWeek_MethodInfo_[] = {
	{"$values", "()[Ljava/time/DayOfWeek;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DayOfWeek, $values, $DayOfWeekArray*)},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $FINAL},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(DayOfWeek, init$, void, $String*, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(DayOfWeek, adjustInto, $Temporal*, $Temporal*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC, $staticMethod(DayOfWeek, from, DayOfWeek*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(DayOfWeek, get, int32_t, $TemporalField*)},
	{"getDisplayName", "(Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(DayOfWeek, getDisplayName, $String*, $TextStyle*, $Locale*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(DayOfWeek, getLong, int64_t, $TemporalField*)},
	{"getValue", "()I", nullptr, $PUBLIC, $method(DayOfWeek, getValue, int32_t)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(DayOfWeek, isSupported, bool, $TemporalField*)},
	{"minus", "(J)Ljava/time/DayOfWeek;", nullptr, $PUBLIC, $method(DayOfWeek, minus, DayOfWeek*, int64_t)},
	{"of", "(I)Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC, $staticMethod(DayOfWeek, of, DayOfWeek*, int32_t)},
	{"plus", "(J)Ljava/time/DayOfWeek;", nullptr, $PUBLIC, $method(DayOfWeek, plus, DayOfWeek*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(DayOfWeek, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(DayOfWeek, range, $ValueRange*, $TemporalField*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"valueOf", "(Ljava/lang/String;)Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC, $staticMethod(DayOfWeek, valueOf, DayOfWeek*, $String*)},
	{"values", "()[Ljava/time/DayOfWeek;", nullptr, $PUBLIC | $STATIC, $staticMethod(DayOfWeek, values, $DayOfWeekArray*)},
	{}
};

$ClassInfo _DayOfWeek_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"java.time.DayOfWeek",
	"java.lang.Enum",
	"java.time.temporal.TemporalAccessor,java.time.temporal.TemporalAdjuster",
	_DayOfWeek_FieldInfo_,
	_DayOfWeek_MethodInfo_,
	"Ljava/lang/Enum<Ljava/time/DayOfWeek;>;Ljava/time/temporal/TemporalAccessor;Ljava/time/temporal/TemporalAdjuster;"
};

$Object* allocate$DayOfWeek($Class* clazz) {
	return $of($alloc(DayOfWeek));
}

$String* DayOfWeek::toString() {
	 return this->$Enum::toString();
}

bool DayOfWeek::equals(Object$* other) {
	 return this->$Enum::equals(other);
}

int32_t DayOfWeek::hashCode() {
	 return this->$Enum::hashCode();
}

$Object* DayOfWeek::clone() {
	 return this->$Enum::clone();
}

void DayOfWeek::finalize() {
	this->$Enum::finalize();
}

DayOfWeek* DayOfWeek::MONDAY = nullptr;
DayOfWeek* DayOfWeek::TUESDAY = nullptr;
DayOfWeek* DayOfWeek::WEDNESDAY = nullptr;
DayOfWeek* DayOfWeek::THURSDAY = nullptr;
DayOfWeek* DayOfWeek::FRIDAY = nullptr;
DayOfWeek* DayOfWeek::SATURDAY = nullptr;
DayOfWeek* DayOfWeek::SUNDAY = nullptr;
$DayOfWeekArray* DayOfWeek::$VALUES = nullptr;
$DayOfWeekArray* DayOfWeek::ENUMS = nullptr;

$DayOfWeekArray* DayOfWeek::$values() {
	$init(DayOfWeek);
	return $new($DayOfWeekArray, {
		DayOfWeek::MONDAY,
		DayOfWeek::TUESDAY,
		DayOfWeek::WEDNESDAY,
		DayOfWeek::THURSDAY,
		DayOfWeek::FRIDAY,
		DayOfWeek::SATURDAY,
		DayOfWeek::SUNDAY
	});
}

$DayOfWeekArray* DayOfWeek::values() {
	$init(DayOfWeek);
	return $cast($DayOfWeekArray, DayOfWeek::$VALUES->clone());
}

DayOfWeek* DayOfWeek::valueOf($String* name) {
	$init(DayOfWeek);
	return $cast(DayOfWeek, $Enum::valueOf(DayOfWeek::class$, name));
}

void DayOfWeek::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

DayOfWeek* DayOfWeek::of(int32_t dayOfWeek) {
	$init(DayOfWeek);
	$useLocalCurrentObjectStackCache();
	if (dayOfWeek < 1 || dayOfWeek > 7) {
		$throwNew($DateTimeException, $$str({"Invalid value for DayOfWeek: "_s, $$str(dayOfWeek)}));
	}
	return $nc(DayOfWeek::ENUMS)->get(dayOfWeek - 1);
}

DayOfWeek* DayOfWeek::from($TemporalAccessor* temporal) {
	$init(DayOfWeek);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf(DayOfWeek, temporal)) {
		return $cast(DayOfWeek, temporal);
	}
	try {
		$init($ChronoField);
		return of($nc(temporal)->get($ChronoField::DAY_OF_WEEK));
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain DayOfWeek from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

int32_t DayOfWeek::getValue() {
	return ordinal() + 1;
}

$String* DayOfWeek::getDisplayName($TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	return $nc($($nc($($$new($DateTimeFormatterBuilder)->appendText(static_cast<$TemporalField*>($ChronoField::DAY_OF_WEEK), style)))->toFormatter(locale)))->format(this);
}

bool DayOfWeek::isSupported($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		return $equals(field, $ChronoField::DAY_OF_WEEK);
	}
	return field != nullptr && field->isSupportedBy(this);
}

$ValueRange* DayOfWeek::range($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::DAY_OF_WEEK)) {
		return field->range();
	}
	return $TemporalAccessor::range(field);
}

int32_t DayOfWeek::get($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::DAY_OF_WEEK)) {
		return getValue();
	}
	return $TemporalAccessor::get(field);
}

int64_t DayOfWeek::getLong($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::DAY_OF_WEEK)) {
		return getValue();
	} else if ($instanceOf($ChronoField, field)) {
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->getFrom(this);
}

DayOfWeek* DayOfWeek::plus(int64_t days) {
	int32_t amount = (int32_t)(days % 7);
	return $nc(DayOfWeek::ENUMS)->get((ordinal() + (amount + 7)) % 7);
}

DayOfWeek* DayOfWeek::minus(int64_t days) {
	return plus(-(days % 7));
}

$Object* DayOfWeek::query($TemporalQuery* query) {
	if (query == $TemporalQueries::precision()) {
		$init($ChronoUnit);
		return $of($of($ChronoUnit::DAYS));
	}
	return $of($TemporalAccessor::query(query));
}

$Temporal* DayOfWeek::adjustInto($Temporal* temporal) {
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::DAY_OF_WEEK, getValue());
}

void clinit$DayOfWeek($Class* class$) {
	$assignStatic(DayOfWeek::MONDAY, $new(DayOfWeek, "MONDAY"_s, 0));
	$assignStatic(DayOfWeek::TUESDAY, $new(DayOfWeek, "TUESDAY"_s, 1));
	$assignStatic(DayOfWeek::WEDNESDAY, $new(DayOfWeek, "WEDNESDAY"_s, 2));
	$assignStatic(DayOfWeek::THURSDAY, $new(DayOfWeek, "THURSDAY"_s, 3));
	$assignStatic(DayOfWeek::FRIDAY, $new(DayOfWeek, "FRIDAY"_s, 4));
	$assignStatic(DayOfWeek::SATURDAY, $new(DayOfWeek, "SATURDAY"_s, 5));
	$assignStatic(DayOfWeek::SUNDAY, $new(DayOfWeek, "SUNDAY"_s, 6));
	$assignStatic(DayOfWeek::$VALUES, DayOfWeek::$values());
	$assignStatic(DayOfWeek::ENUMS, DayOfWeek::values());
}

DayOfWeek::DayOfWeek() {
}

$Class* DayOfWeek::load$($String* name, bool initialize) {
	$loadClass(DayOfWeek, name, initialize, &_DayOfWeek_ClassInfo_, clinit$DayOfWeek, allocate$DayOfWeek);
	return class$;
}

$Class* DayOfWeek::class$ = nullptr;

	} // time
} // java