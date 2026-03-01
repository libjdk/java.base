#include <java/time/Month.h>

#include <java/lang/Enum.h>
#include <java/time/DateTimeException.h>
#include <java/time/LocalDate.h>
#include <java/time/Month$1.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
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

#undef APRIL
#undef AUGUST
#undef DECEMBER
#undef ENUMS
#undef FEBRUARY
#undef INSTANCE
#undef JANUARY
#undef JULY
#undef JUNE
#undef MARCH
#undef MAY
#undef MONTHS
#undef MONTH_OF_YEAR
#undef NOVEMBER
#undef OCTOBER
#undef SEPTEMBER

using $MonthArray = $Array<::java::time::Month>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $LocalDate = ::java::time::LocalDate;
using $Month$1 = ::java::time::Month$1;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
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

$FieldInfo _Month_FieldInfo_[] = {
	{"JANUARY", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, JANUARY)},
	{"FEBRUARY", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, FEBRUARY)},
	{"MARCH", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, MARCH)},
	{"APRIL", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, APRIL)},
	{"MAY", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, MAY)},
	{"JUNE", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, JUNE)},
	{"JULY", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, JULY)},
	{"AUGUST", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, AUGUST)},
	{"SEPTEMBER", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, SEPTEMBER)},
	{"OCTOBER", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, OCTOBER)},
	{"NOVEMBER", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, NOVEMBER)},
	{"DECEMBER", "Ljava/time/Month;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Month, DECEMBER)},
	{"$VALUES", "[Ljava/time/Month;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(Month, $VALUES)},
	{"ENUMS", "[Ljava/time/Month;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Month, ENUMS)},
	{}
};

$MethodInfo _Month_MethodInfo_[] = {
	{"$values", "()[Ljava/time/Month;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Month, $values, $MonthArray*)},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $FINAL},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(Month, init$, void, $String*, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Month, adjustInto, $Temporal*, $Temporal*)},
	{"firstDayOfYear", "(Z)I", nullptr, $PUBLIC, $method(Month, firstDayOfYear, int32_t, bool)},
	{"firstMonthOfQuarter", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(Month, firstMonthOfQuarter, Month*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/Month;", nullptr, $PUBLIC | $STATIC, $staticMethod(Month, from, Month*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(Month, get, int32_t, $TemporalField*)},
	{"getDisplayName", "(Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Month, getDisplayName, $String*, $TextStyle*, $Locale*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(Month, getLong, int64_t, $TemporalField*)},
	{"getValue", "()I", nullptr, $PUBLIC, $method(Month, getValue, int32_t)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(Month, isSupported, bool, $TemporalField*)},
	{"length", "(Z)I", nullptr, $PUBLIC, $method(Month, length, int32_t, bool)},
	{"maxLength", "()I", nullptr, $PUBLIC, $method(Month, maxLength, int32_t)},
	{"minLength", "()I", nullptr, $PUBLIC, $method(Month, minLength, int32_t)},
	{"minus", "(J)Ljava/time/Month;", nullptr, $PUBLIC, $method(Month, minus, Month*, int64_t)},
	{"of", "(I)Ljava/time/Month;", nullptr, $PUBLIC | $STATIC, $staticMethod(Month, of, Month*, int32_t)},
	{"plus", "(J)Ljava/time/Month;", nullptr, $PUBLIC, $method(Month, plus, Month*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(Month, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(Month, range, $ValueRange*, $TemporalField*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"valueOf", "(Ljava/lang/String;)Ljava/time/Month;", nullptr, $PUBLIC | $STATIC, $staticMethod(Month, valueOf, Month*, $String*)},
	{"values", "()[Ljava/time/Month;", nullptr, $PUBLIC | $STATIC, $staticMethod(Month, values, $MonthArray*)},
	{}
};

$InnerClassInfo _Month_InnerClassesInfo_[] = {
	{"java.time.Month$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _Month_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"java.time.Month",
	"java.lang.Enum",
	"java.time.temporal.TemporalAccessor,java.time.temporal.TemporalAdjuster",
	_Month_FieldInfo_,
	_Month_MethodInfo_,
	"Ljava/lang/Enum<Ljava/time/Month;>;Ljava/time/temporal/TemporalAccessor;Ljava/time/temporal/TemporalAdjuster;",
	nullptr,
	_Month_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.Month$1"
};

$Object* allocate$Month($Class* clazz) {
	return $of($alloc(Month));
}

$String* Month::toString() {
	 return this->$Enum::toString();
}

bool Month::equals(Object$* other) {
	 return this->$Enum::equals(other);
}

int32_t Month::hashCode() {
	 return this->$Enum::hashCode();
}

$Object* Month::clone() {
	 return this->$Enum::clone();
}

void Month::finalize() {
	this->$Enum::finalize();
}

Month* Month::JANUARY = nullptr;
Month* Month::FEBRUARY = nullptr;
Month* Month::MARCH = nullptr;
Month* Month::APRIL = nullptr;
Month* Month::MAY = nullptr;
Month* Month::JUNE = nullptr;
Month* Month::JULY = nullptr;
Month* Month::AUGUST = nullptr;
Month* Month::SEPTEMBER = nullptr;
Month* Month::OCTOBER = nullptr;
Month* Month::NOVEMBER = nullptr;
Month* Month::DECEMBER = nullptr;
$MonthArray* Month::$VALUES = nullptr;
$MonthArray* Month::ENUMS = nullptr;

$MonthArray* Month::$values() {
	$init(Month);
	return $new($MonthArray, {
		Month::JANUARY,
		Month::FEBRUARY,
		Month::MARCH,
		Month::APRIL,
		Month::MAY,
		Month::JUNE,
		Month::JULY,
		Month::AUGUST,
		Month::SEPTEMBER,
		Month::OCTOBER,
		Month::NOVEMBER,
		Month::DECEMBER
	});
}

$MonthArray* Month::values() {
	$init(Month);
	return $cast($MonthArray, Month::$VALUES->clone());
}

Month* Month::valueOf($String* name) {
	$init(Month);
	return $cast(Month, $Enum::valueOf(Month::class$, name));
}

void Month::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

Month* Month::of(int32_t month) {
	$init(Month);
	$useLocalCurrentObjectStackCache();
	if (month < 1 || month > 12) {
		$throwNew($DateTimeException, $$str({"Invalid value for MonthOfYear: "_s, $$str(month)}));
	}
	return $nc(Month::ENUMS)->get(month - 1);
}

Month* Month::from($TemporalAccessor* temporal$renamed) {
	$init(Month);
	$useLocalCurrentObjectStackCache();
	$var($TemporalAccessor, temporal, temporal$renamed);
	if ($instanceOf(Month, temporal)) {
		return $cast(Month, temporal);
	}
	try {
		$init($IsoChronology);
		if ($nc($IsoChronology::INSTANCE)->equals($($Chronology::from(temporal))) == false) {
			$assign(temporal, $LocalDate::from(temporal));
		}
		$init($ChronoField);
		return of($nc(temporal)->get($ChronoField::MONTH_OF_YEAR));
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain Month from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

int32_t Month::getValue() {
	return ordinal() + 1;
}

$String* Month::getDisplayName($TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	return $nc($($nc($($$new($DateTimeFormatterBuilder)->appendText(static_cast<$TemporalField*>($ChronoField::MONTH_OF_YEAR), style)))->toFormatter(locale)))->format(this);
}

bool Month::isSupported($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		return $equals(field, $ChronoField::MONTH_OF_YEAR);
	}
	return field != nullptr && field->isSupportedBy(this);
}

$ValueRange* Month::range($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::MONTH_OF_YEAR)) {
		return field->range();
	}
	return $TemporalAccessor::range(field);
}

int32_t Month::get($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::MONTH_OF_YEAR)) {
		return getValue();
	}
	return $TemporalAccessor::get(field);
}

int64_t Month::getLong($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::MONTH_OF_YEAR)) {
		return getValue();
	} else if ($instanceOf($ChronoField, field)) {
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->getFrom(this);
}

Month* Month::plus(int64_t months) {
	int32_t amount = (int32_t)(months % 12);
	return $nc(Month::ENUMS)->get((ordinal() + (amount + 12)) % 12);
}

Month* Month::minus(int64_t months) {
	return plus(-(months % 12));
}

int32_t Month::length(bool leapYear) {
	$init($Month$1);
	switch ($nc($Month$1::$SwitchMap$java$time$Month)->get((this)->ordinal())) {
	case 1:
		{
			return (leapYear ? 29 : 28);
		}
	case 2:
		{}
	case 3:
		{}
	case 4:
		{}
	case 5:
		{
			return 30;
		}
	default:
		{
			return 31;
		}
	}
}

int32_t Month::minLength() {
	$init($Month$1);
	switch ($nc($Month$1::$SwitchMap$java$time$Month)->get((this)->ordinal())) {
	case 1:
		{
			return 28;
		}
	case 2:
		{}
	case 3:
		{}
	case 4:
		{}
	case 5:
		{
			return 30;
		}
	default:
		{
			return 31;
		}
	}
}

int32_t Month::maxLength() {
	$init($Month$1);
	switch ($nc($Month$1::$SwitchMap$java$time$Month)->get((this)->ordinal())) {
	case 1:
		{
			return 29;
		}
	case 2:
		{}
	case 3:
		{}
	case 4:
		{}
	case 5:
		{
			return 30;
		}
	default:
		{
			return 31;
		}
	}
}

int32_t Month::firstDayOfYear(bool leapYear) {
	int32_t leap = leapYear ? 1 : 0;
	$init($Month$1);
	switch ($nc($Month$1::$SwitchMap$java$time$Month)->get((this)->ordinal())) {
	case 6:
		{
			return 1;
		}
	case 1:
		{
			return 32;
		}
	case 7:
		{
			return 60 + leap;
		}
	case 2:
		{
			return 91 + leap;
		}
	case 8:
		{
			return 121 + leap;
		}
	case 3:
		{
			return 152 + leap;
		}
	case 9:
		{
			return 182 + leap;
		}
	case 10:
		{
			return 213 + leap;
		}
	case 4:
		{
			return 244 + leap;
		}
	case 11:
		{
			return 274 + leap;
		}
	case 5:
		{
			return 305 + leap;
		}
	case 12:
		{}
	default:
		{
			return 335 + leap;
		}
	}
}

Month* Month::firstMonthOfQuarter() {
	return $nc(Month::ENUMS)->get((ordinal() / 3) * 3);
}

$Object* Month::query($TemporalQuery* query) {
	if (query == $TemporalQueries::chronology()) {
		$init($IsoChronology);
		return $of($of($IsoChronology::INSTANCE));
	} else if (query == $TemporalQueries::precision()) {
		$init($ChronoUnit);
		return $of($of($ChronoUnit::MONTHS));
	}
	return $of($TemporalAccessor::query(query));
}

$Temporal* Month::adjustInto($Temporal* temporal) {
	$init($IsoChronology);
	if ($nc($($Chronology::from(temporal)))->equals($IsoChronology::INSTANCE) == false) {
		$throwNew($DateTimeException, "Adjustment only supported on ISO date-time"_s);
	}
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::MONTH_OF_YEAR, getValue());
}

void clinit$Month($Class* class$) {
	$assignStatic(Month::JANUARY, $new(Month, "JANUARY"_s, 0));
	$assignStatic(Month::FEBRUARY, $new(Month, "FEBRUARY"_s, 1));
	$assignStatic(Month::MARCH, $new(Month, "MARCH"_s, 2));
	$assignStatic(Month::APRIL, $new(Month, "APRIL"_s, 3));
	$assignStatic(Month::MAY, $new(Month, "MAY"_s, 4));
	$assignStatic(Month::JUNE, $new(Month, "JUNE"_s, 5));
	$assignStatic(Month::JULY, $new(Month, "JULY"_s, 6));
	$assignStatic(Month::AUGUST, $new(Month, "AUGUST"_s, 7));
	$assignStatic(Month::SEPTEMBER, $new(Month, "SEPTEMBER"_s, 8));
	$assignStatic(Month::OCTOBER, $new(Month, "OCTOBER"_s, 9));
	$assignStatic(Month::NOVEMBER, $new(Month, "NOVEMBER"_s, 10));
	$assignStatic(Month::DECEMBER, $new(Month, "DECEMBER"_s, 11));
	$assignStatic(Month::$VALUES, Month::$values());
	$assignStatic(Month::ENUMS, Month::values());
}

Month::Month() {
}

$Class* Month::load$($String* name, bool initialize) {
	$loadClass(Month, name, initialize, &_Month_ClassInfo_, clinit$Month, allocate$Month);
	return class$;
}

$Class* Month::class$ = nullptr;

	} // time
} // java