#include <java/time/YearMonth.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/LocalDate.h>
#include <java/time/Month.h>
#include <java/time/Ser.h>
#include <java/time/Year.h>
#include <java/time/YearMonth$1.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/SignStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef CENTURIES
#undef DECADES
#undef ERA
#undef ERAS
#undef EXCEEDS_PAD
#undef INSTANCE
#undef MAX_VALUE
#undef MILLENNIA
#undef MIN_VALUE
#undef MONTHS
#undef MONTH_OF_YEAR
#undef PARSER
#undef PROLEPTIC_MONTH
#undef YEAR
#undef YEARS
#undef YEAR_MONTH_TYPE
#undef YEAR_OF_ERA

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $LocalDate = ::java::time::LocalDate;
using $Month = ::java::time::Month;
using $Ser = ::java::time::Ser;
using $Year = ::java::time::Year;
using $YearMonth$1 = ::java::time::YearMonth$1;
using $ZoneId = ::java::time::ZoneId;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $SignStyle = ::java::time::format::SignStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAdjuster = ::java::time::temporal::TemporalAdjuster;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {

class YearMonth$$Lambda$from : public $TemporalQuery {
	$class(YearMonth$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(YearMonth::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<YearMonth$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo YearMonth$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(YearMonth$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(YearMonth$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo YearMonth$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.YearMonth$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* YearMonth$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(YearMonth$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* YearMonth$$Lambda$from::class$ = nullptr;

$CompoundAttribute _YearMonth_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _YearMonth_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(YearMonth, serialVersionUID)},
	{"PARSER", "Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(YearMonth, PARSER)},
	{"year", "I", nullptr, $PRIVATE | $FINAL, $field(YearMonth, year)},
	{"month", "I", nullptr, $PRIVATE | $FINAL, $field(YearMonth, month)},
	{}
};

$MethodInfo _YearMonth_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(II)V", nullptr, $PRIVATE, $method(YearMonth, init$, void, int32_t, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(YearMonth, adjustInto, $Temporal*, $Temporal*)},
	{"atDay", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(YearMonth, atDay, $LocalDate*, int32_t)},
	{"atEndOfMonth", "()Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(YearMonth, atEndOfMonth, $LocalDate*)},
	{"compareTo", "(Ljava/time/YearMonth;)I", nullptr, $PUBLIC, $method(YearMonth, compareTo, int32_t, YearMonth*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(YearMonth, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(YearMonth, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $method(YearMonth, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, from, YearMonth*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(YearMonth, get, int32_t, $TemporalField*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(YearMonth, getLong, int64_t, $TemporalField*)},
	{"getMonth", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(YearMonth, getMonth, $Month*)},
	{"getMonthValue", "()I", nullptr, $PUBLIC, $method(YearMonth, getMonthValue, int32_t)},
	{"getProlepticMonth", "()J", nullptr, $PRIVATE, $method(YearMonth, getProlepticMonth, int64_t)},
	{"getYear", "()I", nullptr, $PUBLIC, $method(YearMonth, getYear, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(YearMonth, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/YearMonth;)Z", nullptr, $PUBLIC, $method(YearMonth, isAfter, bool, YearMonth*)},
	{"isBefore", "(Ljava/time/YearMonth;)Z", nullptr, $PUBLIC, $method(YearMonth, isBefore, bool, YearMonth*)},
	{"isLeapYear", "()Z", nullptr, $PUBLIC, $method(YearMonth, isLeapYear, bool)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(YearMonth, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(YearMonth, isSupported, bool, $TemporalUnit*)},
	{"isValidDay", "(I)Z", nullptr, $PUBLIC, $method(YearMonth, isValidDay, bool, int32_t)},
	{"lengthOfMonth", "()I", nullptr, $PUBLIC, $method(YearMonth, lengthOfMonth, int32_t)},
	{"lengthOfYear", "()I", nullptr, $PUBLIC, $method(YearMonth, lengthOfYear, int32_t)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/YearMonth;", nullptr, $PUBLIC, $virtualMethod(YearMonth, minus, YearMonth*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/YearMonth;", nullptr, $PUBLIC, $virtualMethod(YearMonth, minus, YearMonth*, int64_t, $TemporalUnit*)},
	{"minusMonths", "(J)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(YearMonth, minusMonths, YearMonth*, int64_t)},
	{"minusYears", "(J)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(YearMonth, minusYears, YearMonth*, int64_t)},
	{"now", "()Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, now, YearMonth*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, now, YearMonth*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, now, YearMonth*, $Clock*)},
	{"of", "(ILjava/time/Month;)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, of, YearMonth*, int32_t, $Month*)},
	{"of", "(II)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, of, YearMonth*, int32_t, int32_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, parse, YearMonth*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/YearMonth;", nullptr, $PUBLIC | $STATIC, $staticMethod(YearMonth, parse, YearMonth*, $CharSequence*, $DateTimeFormatter*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/YearMonth;", nullptr, $PUBLIC, $virtualMethod(YearMonth, plus, YearMonth*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/YearMonth;", nullptr, $PUBLIC, $virtualMethod(YearMonth, plus, YearMonth*, int64_t, $TemporalUnit*)},
	{"plusMonths", "(J)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(YearMonth, plusMonths, YearMonth*, int64_t)},
	{"plusYears", "(J)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(YearMonth, plusYears, YearMonth*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(YearMonth, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(YearMonth, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/YearMonth;", nullptr, $STATIC, $staticMethod(YearMonth, readExternal, YearMonth*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(YearMonth, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(YearMonth, toString, $String*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(YearMonth, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(II)Ljava/time/YearMonth;", nullptr, $PRIVATE, $method(YearMonth, with, YearMonth*, int32_t, int32_t)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/YearMonth;", nullptr, $PUBLIC, $virtualMethod(YearMonth, with, YearMonth*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/YearMonth;", nullptr, $PUBLIC, $virtualMethod(YearMonth, with, YearMonth*, $TemporalField*, int64_t)},
	{"withMonth", "(I)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(YearMonth, withMonth, YearMonth*, int32_t)},
	{"withYear", "(I)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(YearMonth, withYear, YearMonth*, int32_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(YearMonth, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(YearMonth, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _YearMonth_InnerClassesInfo_[] = {
	{"java.time.YearMonth$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _YearMonth_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.YearMonth",
	"java.lang.Object",
	"java.time.temporal.Temporal,java.time.temporal.TemporalAdjuster,java.lang.Comparable,java.io.Serializable",
	_YearMonth_FieldInfo_,
	_YearMonth_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalAdjuster;Ljava/lang/Comparable<Ljava/time/YearMonth;>;Ljava/io/Serializable;",
	nullptr,
	_YearMonth_InnerClassesInfo_,
	_YearMonth_Annotations_,
	nullptr,
	"java.time.YearMonth$1"
};

$Object* allocate$YearMonth($Class* clazz) {
	return $of($alloc(YearMonth));
}

$Object* YearMonth::clone() {
	 return this->$Temporal::clone();
}

void YearMonth::finalize() {
	this->$Temporal::finalize();
}

$DateTimeFormatter* YearMonth::PARSER = nullptr;

YearMonth* YearMonth::now() {
	$init(YearMonth);
	return now($($Clock::systemDefaultZone()));
}

YearMonth* YearMonth::now($ZoneId* zone) {
	$init(YearMonth);
	return now($($Clock::system(zone)));
}

YearMonth* YearMonth::now($Clock* clock) {
	$init(YearMonth);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, now, $LocalDate::now(clock));
	int32_t var$0 = $nc(now)->getYear();
	return YearMonth::of(var$0, $(now->getMonth()));
}

YearMonth* YearMonth::of(int32_t year, $Month* month) {
	$init(YearMonth);
	$Objects::requireNonNull($of(month), "month"_s);
	return of(year, $nc(month)->getValue());
}

YearMonth* YearMonth::of(int32_t year, int32_t month) {
	$init(YearMonth);
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(year);
	$ChronoField::MONTH_OF_YEAR->checkValidValue(month);
	return $new(YearMonth, year, month);
}

YearMonth* YearMonth::from($TemporalAccessor* temporal$renamed) {
	$init(YearMonth);
	$useLocalCurrentObjectStackCache();
	$var($TemporalAccessor, temporal, temporal$renamed);
	if ($instanceOf(YearMonth, temporal)) {
		return $cast(YearMonth, temporal);
	}
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	try {
		$init($IsoChronology);
		if ($nc($IsoChronology::INSTANCE)->equals($($Chronology::from(temporal))) == false) {
			$assign(temporal, $LocalDate::from(temporal));
		}
		$init($ChronoField);
		int32_t var$0 = $nc(temporal)->get($ChronoField::YEAR);
		return of(var$0, temporal->get($ChronoField::MONTH_OF_YEAR));
	} catch ($DateTimeException& ex) {
		$var($String, var$1, $$str({"Unable to obtain YearMonth from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$1, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

YearMonth* YearMonth::parse($CharSequence* text) {
	$init(YearMonth);
	return parse(text, YearMonth::PARSER);
}

YearMonth* YearMonth::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(YearMonth);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(YearMonth, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(YearMonth$$Lambda$from))));
}

void YearMonth::init$(int32_t year, int32_t month) {
	this->year = year;
	this->month = month;
}

YearMonth* YearMonth::with(int32_t newYear, int32_t newMonth) {
	if (this->year == newYear && this->month == newMonth) {
		return this;
	}
	return $new(YearMonth, newYear, newMonth);
}

bool YearMonth::isSupported($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		return $equals(field, $ChronoField::YEAR) || $equals(field, $ChronoField::MONTH_OF_YEAR) || $equals(field, $ChronoField::PROLEPTIC_MONTH) || $equals(field, $ChronoField::YEAR_OF_ERA) || $equals(field, $ChronoField::ERA);
	}
	return field != nullptr && field->isSupportedBy(this);
}

bool YearMonth::isSupported($TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		$init($ChronoUnit);
		return $equals(unit, $ChronoUnit::MONTHS) || $equals(unit, $ChronoUnit::YEARS) || $equals(unit, $ChronoUnit::DECADES) || $equals(unit, $ChronoUnit::CENTURIES) || $equals(unit, $ChronoUnit::MILLENNIA) || $equals(unit, $ChronoUnit::ERAS);
	}
	return unit != nullptr && unit->isSupportedBy(this);
}

$ValueRange* YearMonth::range($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::YEAR_OF_ERA)) {
		return (getYear() <= 0 ? $ValueRange::of(1, $Year::MAX_VALUE + 1) : $ValueRange::of(1, $Year::MAX_VALUE));
	}
	return $Temporal::range(field);
}

int32_t YearMonth::get($TemporalField* field) {
	return $nc($(range(field)))->checkValidIntValue(getLong(field), field);
}

int64_t YearMonth::getLong($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($YearMonth$1);
			switch ($nc($YearMonth$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 1:
				{
					return this->month;
				}
			case 2:
				{
					return getProlepticMonth();
				}
			case 3:
				{
					return (this->year < 1 ? 1 - this->year : this->year);
				}
			case 4:
				{
					return this->year;
				}
			case 5:
				{
					return (this->year < 1 ? 0 : 1);
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $nc(field)->getFrom(this);
}

int64_t YearMonth::getProlepticMonth() {
	return (this->year * (int64_t)12 + this->month - 1);
}

int32_t YearMonth::getYear() {
	return this->year;
}

int32_t YearMonth::getMonthValue() {
	return this->month;
}

$Month* YearMonth::getMonth() {
	return $Month::of(this->month);
}

bool YearMonth::isLeapYear() {
	$init($IsoChronology);
	return $nc($IsoChronology::INSTANCE)->isLeapYear(this->year);
}

bool YearMonth::isValidDay(int32_t dayOfMonth) {
	return dayOfMonth >= 1 && dayOfMonth <= lengthOfMonth();
}

int32_t YearMonth::lengthOfMonth() {
	return $nc($(getMonth()))->length(isLeapYear());
}

int32_t YearMonth::lengthOfYear() {
	return (isLeapYear() ? 366 : 365);
}

YearMonth* YearMonth::with($TemporalAdjuster* adjuster) {
	return $cast(YearMonth, $nc(adjuster)->adjustInto(this));
}

YearMonth* YearMonth::with($TemporalField* field, int64_t newValue) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$nc(chronoField)->checkValidValue(newValue);
			$init($YearMonth$1);
			switch ($nc($YearMonth$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
			case 1:
				{
					return withMonth((int32_t)newValue);
				}
			case 2:
				{
					return plusMonths(newValue - getProlepticMonth());
				}
			case 3:
				{
					return withYear((int32_t)(this->year < 1 ? 1 - newValue : newValue));
				}
			case 4:
				{
					return withYear((int32_t)newValue);
				}
			case 5:
				{
					return (getLong($ChronoField::ERA) == newValue ? this : withYear(1 - this->year));
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $cast(YearMonth, $nc(field)->adjustInto(this, newValue));
}

YearMonth* YearMonth::withYear(int32_t year) {
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(year);
	return with(year, this->month);
}

YearMonth* YearMonth::withMonth(int32_t month) {
	$init($ChronoField);
	$ChronoField::MONTH_OF_YEAR->checkValidValue(month);
	return with(this->year, month);
}

YearMonth* YearMonth::plus($TemporalAmount* amountToAdd) {
	return $cast(YearMonth, $nc(amountToAdd)->addTo(this));
}

YearMonth* YearMonth::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			$init($YearMonth$1);
			switch ($nc($YearMonth$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return plusMonths(amountToAdd);
				}
			case 2:
				{
					return plusYears(amountToAdd);
				}
			case 3:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 10));
				}
			case 4:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 100));
				}
			case 5:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 1000));
				}
			case 6:
				{
					$init($ChronoField);
					return with(static_cast<$TemporalField*>($ChronoField::ERA), $Math::addExact(getLong($ChronoField::ERA), amountToAdd));
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
	return $cast(YearMonth, $nc(unit)->addTo(this, amountToAdd));
}

YearMonth* YearMonth::plusYears(int64_t yearsToAdd) {
	if (yearsToAdd == 0) {
		return this;
	}
	$init($ChronoField);
	int32_t newYear = $ChronoField::YEAR->checkValidIntValue(this->year + yearsToAdd);
	return with(newYear, this->month);
}

YearMonth* YearMonth::plusMonths(int64_t monthsToAdd) {
	if (monthsToAdd == 0) {
		return this;
	}
	int64_t monthCount = this->year * (int64_t)12 + (this->month - 1);
	int64_t calcMonths = monthCount + monthsToAdd;
	$init($ChronoField);
	int32_t newYear = $ChronoField::YEAR->checkValidIntValue($Math::floorDiv(calcMonths, 12));
	int32_t newMonth = $Math::floorMod(calcMonths, 12) + 1;
	return with(newYear, newMonth);
}

YearMonth* YearMonth::minus($TemporalAmount* amountToSubtract) {
	return $cast(YearMonth, $nc(amountToSubtract)->subtractFrom(this));
}

YearMonth* YearMonth::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus(1, unit) : plus(-amountToSubtract, unit));
}

YearMonth* YearMonth::minusYears(int64_t yearsToSubtract) {
	return (yearsToSubtract == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-yearsToSubtract));
}

YearMonth* YearMonth::minusMonths(int64_t monthsToSubtract) {
	return (monthsToSubtract == $Long::MIN_VALUE ? $nc($(plusMonths($Long::MAX_VALUE)))->plusMonths(1) : plusMonths(-monthsToSubtract));
}

$Object* YearMonth::query($TemporalQuery* query) {
	if (query == $TemporalQueries::chronology()) {
		$init($IsoChronology);
		return $of($of($IsoChronology::INSTANCE));
	} else if (query == $TemporalQueries::precision()) {
		$init($ChronoUnit);
		return $of($of($ChronoUnit::MONTHS));
	}
	return $of($Temporal::query(query));
}

$Temporal* YearMonth::adjustInto($Temporal* temporal) {
	$init($IsoChronology);
	if ($nc($($Chronology::from(temporal)))->equals($IsoChronology::INSTANCE) == false) {
		$throwNew($DateTimeException, "Adjustment only supported on ISO date-time"_s);
	}
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::PROLEPTIC_MONTH, getProlepticMonth());
}

int64_t YearMonth::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(YearMonth, end, YearMonth::from(endExclusive));
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			int64_t var$1 = $nc(end)->getProlepticMonth();
			int64_t monthsUntil = var$1 - getProlepticMonth();
			$init($YearMonth$1);
			switch ($nc($YearMonth$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return monthsUntil;
				}
			case 2:
				{
					return monthsUntil / 12;
				}
			case 3:
				{
					return monthsUntil / 120;
				}
			case 4:
				{
					return monthsUntil / 1200;
				}
			case 5:
				{
					return monthsUntil / 12000;
				}
			case 6:
				{
					$init($ChronoField);
					int64_t var$2 = end->getLong($ChronoField::ERA);
					return var$2 - getLong($ChronoField::ERA);
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
	return $nc(unit)->between(this, end);
}

$String* YearMonth::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$LocalDate* YearMonth::atDay(int32_t dayOfMonth) {
	return $LocalDate::of(this->year, this->month, dayOfMonth);
}

$LocalDate* YearMonth::atEndOfMonth() {
	return $LocalDate::of(this->year, this->month, lengthOfMonth());
}

int32_t YearMonth::compareTo(YearMonth* other) {
	int32_t cmp = (this->year - $nc(other)->year);
	if (cmp == 0) {
		cmp = (this->month - other->month);
	}
	return cmp;
}

bool YearMonth::isAfter(YearMonth* other) {
	return compareTo(other) > 0;
}

bool YearMonth::isBefore(YearMonth* other) {
	return compareTo(other) < 0;
}

bool YearMonth::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(YearMonth, other, nullptr);
	bool var$2 = $instanceOf(YearMonth, obj);
	if (var$2) {
		$assign(other, $cast(YearMonth, obj));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && this->year == $nc(other)->year;
	return var$0 && this->month == other->month;
}

int32_t YearMonth::hashCode() {
	return this->year ^ (this->month << 27);
}

$String* YearMonth::toString() {
	int32_t absYear = $Math::abs(this->year);
	$var($StringBuilder, buf, $new($StringBuilder, 9));
	if (absYear < 1000) {
		if (this->year < 0) {
			buf->append(this->year - 10000)->deleteCharAt(1);
		} else {
			buf->append(this->year + 10000)->deleteCharAt(0);
		}
	} else {
		buf->append(this->year);
	}
	return buf->append(this->month < 10 ? "-0"_s : "-"_s)->append(this->month)->toString();
}

$Object* YearMonth::writeReplace() {
	return $of($new($Ser, $Ser::YEAR_MONTH_TYPE, this));
}

void YearMonth::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void YearMonth::writeExternal($DataOutput* out) {
	$nc(out)->writeInt(this->year);
	out->writeByte(this->month);
}

YearMonth* YearMonth::readExternal($DataInput* in) {
	$init(YearMonth);
	int32_t year = $nc(in)->readInt();
	int8_t month = in->readByte();
	return YearMonth::of(year, (int32_t)month);
}

int32_t YearMonth::compareTo(Object$* other) {
	return this->compareTo($cast(YearMonth, other));
}

void clinit$YearMonth($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$init($SignStyle);
	$assignStatic(YearMonth::PARSER, $nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->appendValue($ChronoField::YEAR, 4, 10, $SignStyle::EXCEEDS_PAD)))->appendLiteral(u'-')))->appendValue($ChronoField::MONTH_OF_YEAR, 2)))->toFormatter());
}

YearMonth::YearMonth() {
}

$Class* YearMonth::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(YearMonth$$Lambda$from::classInfo$.name)) {
			return YearMonth$$Lambda$from::load$(name, initialize);
		}
	}
	$loadClass(YearMonth, name, initialize, &_YearMonth_ClassInfo_, clinit$YearMonth, allocate$YearMonth);
	return class$;
}

$Class* YearMonth::class$ = nullptr;

	} // time
} // java