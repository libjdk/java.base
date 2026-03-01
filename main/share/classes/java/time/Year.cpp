#include <java/time/Year.h>

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
#include <java/time/MonthDay.h>
#include <java/time/Ser.h>
#include <java/time/Year$1.h>
#include <java/time/YearMonth.h>
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
#undef INSTANCE
#undef MAX_VALUE
#undef MILLENNIA
#undef MIN_VALUE
#undef NORMAL
#undef PARSER
#undef YEAR
#undef YEARS
#undef YEAR_OF_ERA
#undef YEAR_TYPE

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
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $LocalDate = ::java::time::LocalDate;
using $Month = ::java::time::Month;
using $MonthDay = ::java::time::MonthDay;
using $Ser = ::java::time::Ser;
using $Year$1 = ::java::time::Year$1;
using $YearMonth = ::java::time::YearMonth;
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

class Year$$Lambda$from : public $TemporalQuery {
	$class(Year$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(Year::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Year$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Year$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Year$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Year$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo Year$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.Year$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* Year$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(Year$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Year$$Lambda$from::class$ = nullptr;

$CompoundAttribute _Year_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _Year_FieldInfo_[] = {
	{"MIN_VALUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Year, MIN_VALUE)},
	{"MAX_VALUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Year, MAX_VALUE)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Year, serialVersionUID)},
	{"PARSER", "Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Year, PARSER)},
	{"year", "I", nullptr, $PRIVATE | $FINAL, $field(Year, year)},
	{}
};

$MethodInfo _Year_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(I)V", nullptr, $PRIVATE, $method(Year, init$, void, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(Year, adjustInto, $Temporal*, $Temporal*)},
	{"atDay", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(Year, atDay, $LocalDate*, int32_t)},
	{"atMonth", "(Ljava/time/Month;)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(Year, atMonth, $YearMonth*, $Month*)},
	{"atMonth", "(I)Ljava/time/YearMonth;", nullptr, $PUBLIC, $method(Year, atMonth, $YearMonth*, int32_t)},
	{"atMonthDay", "(Ljava/time/MonthDay;)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(Year, atMonthDay, $LocalDate*, $MonthDay*)},
	{"compareTo", "(Ljava/time/Year;)I", nullptr, $PUBLIC, $method(Year, compareTo, int32_t, Year*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Year, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Year, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $method(Year, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, from, Year*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(Year, get, int32_t, $TemporalField*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(Year, getLong, int64_t, $TemporalField*)},
	{"getValue", "()I", nullptr, $PUBLIC, $method(Year, getValue, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Year, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/Year;)Z", nullptr, $PUBLIC, $method(Year, isAfter, bool, Year*)},
	{"isBefore", "(Ljava/time/Year;)Z", nullptr, $PUBLIC, $method(Year, isBefore, bool, Year*)},
	{"isLeap", "(J)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, isLeap, bool, int64_t)},
	{"isLeap", "()Z", nullptr, $PUBLIC, $method(Year, isLeap, bool)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(Year, isSupported, bool, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalUnit;)Z", nullptr, $PUBLIC, $virtualMethod(Year, isSupported, bool, $TemporalUnit*)},
	{"isValidMonthDay", "(Ljava/time/MonthDay;)Z", nullptr, $PUBLIC, $method(Year, isValidMonthDay, bool, $MonthDay*)},
	{"length", "()I", nullptr, $PUBLIC, $method(Year, length, int32_t)},
	{"minus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Year;", nullptr, $PUBLIC, $virtualMethod(Year, minus, Year*, $TemporalAmount*)},
	{"minus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Year;", nullptr, $PUBLIC, $virtualMethod(Year, minus, Year*, int64_t, $TemporalUnit*)},
	{"minusYears", "(J)Ljava/time/Year;", nullptr, $PUBLIC, $method(Year, minusYears, Year*, int64_t)},
	{"now", "()Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, now, Year*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, now, Year*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, now, Year*, $Clock*)},
	{"of", "(I)Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, of, Year*, int32_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, parse, Year*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/Year;", nullptr, $PUBLIC | $STATIC, $staticMethod(Year, parse, Year*, $CharSequence*, $DateTimeFormatter*)},
	{"plus", "(Ljava/time/temporal/TemporalAmount;)Ljava/time/Year;", nullptr, $PUBLIC, $virtualMethod(Year, plus, Year*, $TemporalAmount*)},
	{"plus", "(JLjava/time/temporal/TemporalUnit;)Ljava/time/Year;", nullptr, $PUBLIC, $virtualMethod(Year, plus, Year*, int64_t, $TemporalUnit*)},
	{"plusYears", "(J)Ljava/time/Year;", nullptr, $PUBLIC, $method(Year, plusYears, Year*, int64_t)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(Year, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(Year, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/Year;", nullptr, $STATIC, $staticMethod(Year, readExternal, Year*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Year, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Year, toString, $String*)},
	{"until", "(Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalUnit;)J", nullptr, $PUBLIC, $virtualMethod(Year, until, int64_t, $Temporal*, $TemporalUnit*)},
	{"with", "(Ljava/time/temporal/TemporalAdjuster;)Ljava/time/Year;", nullptr, $PUBLIC, $virtualMethod(Year, with, Year*, $TemporalAdjuster*)},
	{"with", "(Ljava/time/temporal/TemporalField;J)Ljava/time/Year;", nullptr, $PUBLIC, $virtualMethod(Year, with, Year*, $TemporalField*, int64_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(Year, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Year, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _Year_InnerClassesInfo_[] = {
	{"java.time.Year$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _Year_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.Year",
	"java.lang.Object",
	"java.time.temporal.Temporal,java.time.temporal.TemporalAdjuster,java.lang.Comparable,java.io.Serializable",
	_Year_FieldInfo_,
	_Year_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/Temporal;Ljava/time/temporal/TemporalAdjuster;Ljava/lang/Comparable<Ljava/time/Year;>;Ljava/io/Serializable;",
	nullptr,
	_Year_InnerClassesInfo_,
	_Year_Annotations_,
	nullptr,
	"java.time.Year$1"
};

$Object* allocate$Year($Class* clazz) {
	return $of($alloc(Year));
}

$Object* Year::clone() {
	 return this->$Temporal::clone();
}

void Year::finalize() {
	this->$Temporal::finalize();
}

$DateTimeFormatter* Year::PARSER = nullptr;

Year* Year::now() {
	$init(Year);
	return now($($Clock::systemDefaultZone()));
}

Year* Year::now($ZoneId* zone) {
	$init(Year);
	return now($($Clock::system(zone)));
}

Year* Year::now($Clock* clock) {
	$init(Year);
	$var($LocalDate, now, $LocalDate::now(clock));
	return Year::of($nc(now)->getYear());
}

Year* Year::of(int32_t isoYear) {
	$init(Year);
	$init($ChronoField);
	$ChronoField::YEAR->checkValidValue(isoYear);
	return $new(Year, isoYear);
}

Year* Year::from($TemporalAccessor* temporal$renamed) {
	$init(Year);
	$useLocalCurrentObjectStackCache();
	$var($TemporalAccessor, temporal, temporal$renamed);
	if ($instanceOf(Year, temporal)) {
		return $cast(Year, temporal);
	}
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	try {
		$init($IsoChronology);
		if ($nc($IsoChronology::INSTANCE)->equals($($Chronology::from(temporal))) == false) {
			$assign(temporal, $LocalDate::from(temporal));
		}
		$init($ChronoField);
		return of($nc(temporal)->get($ChronoField::YEAR));
	} catch ($DateTimeException& ex) {
		$var($String, var$0, $$str({"Unable to obtain Year from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$0, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

Year* Year::parse($CharSequence* text) {
	$init(Year);
	return parse(text, Year::PARSER);
}

Year* Year::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(Year);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(Year, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(Year$$Lambda$from))));
}

bool Year::isLeap(int64_t year) {
	$init(Year);
	return (((int64_t)(year & (uint64_t)(int64_t)3)) == 0) && ((year % 100) != 0 || (year % 400) == 0);
}

void Year::init$(int32_t year) {
	this->year = year;
}

int32_t Year::getValue() {
	return this->year;
}

bool Year::isSupported($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		return $equals(field, $ChronoField::YEAR) || $equals(field, $ChronoField::YEAR_OF_ERA) || $equals(field, $ChronoField::ERA);
	}
	return field != nullptr && field->isSupportedBy(this);
}

bool Year::isSupported($TemporalUnit* unit) {
	if ($instanceOf($ChronoUnit, unit)) {
		$init($ChronoUnit);
		return $equals(unit, $ChronoUnit::YEARS) || $equals(unit, $ChronoUnit::DECADES) || $equals(unit, $ChronoUnit::CENTURIES) || $equals(unit, $ChronoUnit::MILLENNIA) || $equals(unit, $ChronoUnit::ERAS);
	}
	return unit != nullptr && unit->isSupportedBy(this);
}

$ValueRange* Year::range($TemporalField* field) {
	$init($ChronoField);
	if ($equals(field, $ChronoField::YEAR_OF_ERA)) {
		return (this->year <= 0 ? $ValueRange::of(1, Year::MAX_VALUE + 1) : $ValueRange::of(1, Year::MAX_VALUE));
	}
	return $Temporal::range(field);
}

int32_t Year::get($TemporalField* field) {
	return $nc($(range(field)))->checkValidIntValue(getLong(field), field);
}

int64_t Year::getLong($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($Year$1);
			switch ($nc($Year$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 1:
				{
					return (this->year < 1 ? 1 - this->year : this->year);
				}
			case 2:
				{
					return this->year;
				}
			case 3:
				{
					return (this->year < 1 ? 0 : 1);
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $nc(field)->getFrom(this);
}

bool Year::isLeap() {
	return Year::isLeap(this->year);
}

bool Year::isValidMonthDay($MonthDay* monthDay) {
	return monthDay != nullptr && monthDay->isValidYear(this->year);
}

int32_t Year::length() {
	return isLeap() ? 366 : 365;
}

Year* Year::with($TemporalAdjuster* adjuster) {
	return $cast(Year, $nc(adjuster)->adjustInto(this));
}

Year* Year::with($TemporalField* field, int64_t newValue) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$nc(chronoField)->checkValidValue(newValue);
			$init($Year$1);
			switch ($nc($Year$1::$SwitchMap$java$time$temporal$ChronoField)->get((chronoField)->ordinal())) {
			case 1:
				{
					return Year::of((int32_t)(this->year < 1 ? 1 - newValue : newValue));
				}
			case 2:
				{
					return Year::of((int32_t)newValue);
				}
			case 3:
				{
					return (getLong($ChronoField::ERA) == newValue ? this : Year::of(1 - this->year));
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $cast(Year, $nc(field)->adjustInto(this, newValue));
}

Year* Year::plus($TemporalAmount* amountToAdd) {
	return $cast(Year, $nc(amountToAdd)->addTo(this));
}

Year* Year::plus(int64_t amountToAdd, $TemporalUnit* unit) {
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			$init($Year$1);
			switch ($nc($Year$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return plusYears(amountToAdd);
				}
			case 2:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 10));
				}
			case 3:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 100));
				}
			case 4:
				{
					return plusYears($Math::multiplyExact(amountToAdd, 1000));
				}
			case 5:
				{
					$init($ChronoField);
					return with($ChronoField::ERA, $Math::addExact(getLong($ChronoField::ERA), amountToAdd));
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
	return $cast(Year, $nc(unit)->addTo(this, amountToAdd));
}

Year* Year::plusYears(int64_t yearsToAdd) {
	if (yearsToAdd == 0) {
		return this;
	}
	$init($ChronoField);
	return of($ChronoField::YEAR->checkValidIntValue(this->year + yearsToAdd));
}

Year* Year::minus($TemporalAmount* amountToSubtract) {
	return $cast(Year, $nc(amountToSubtract)->subtractFrom(this));
}

Year* Year::minus(int64_t amountToSubtract, $TemporalUnit* unit) {
	return (amountToSubtract == $Long::MIN_VALUE ? $nc($(plus($Long::MAX_VALUE, unit)))->plus(1, unit) : plus(-amountToSubtract, unit));
}

Year* Year::minusYears(int64_t yearsToSubtract) {
	return (yearsToSubtract == $Long::MIN_VALUE ? $nc($(plusYears($Long::MAX_VALUE)))->plusYears(1) : plusYears(-yearsToSubtract));
}

$Object* Year::query($TemporalQuery* query) {
	if (query == $TemporalQueries::chronology()) {
		$init($IsoChronology);
		return $of($of($IsoChronology::INSTANCE));
	} else if (query == $TemporalQueries::precision()) {
		$init($ChronoUnit);
		return $of($of($ChronoUnit::YEARS));
	}
	return $of($Temporal::query(query));
}

$Temporal* Year::adjustInto($Temporal* temporal) {
	$init($IsoChronology);
	if ($nc($($Chronology::from(temporal)))->equals($IsoChronology::INSTANCE) == false) {
		$throwNew($DateTimeException, "Adjustment only supported on ISO date-time"_s);
	}
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::YEAR, this->year);
}

int64_t Year::until($Temporal* endExclusive, $TemporalUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var(Year, end, Year::from(endExclusive));
	{
		$ChronoUnit* chronoUnit = nullptr;
		bool var$0 = $instanceOf($ChronoUnit, unit);
		if (var$0) {
			chronoUnit = $cast($ChronoUnit, unit);
			var$0 = true;
		}
		if (var$0) {
			int64_t yearsUntil = ((int64_t)$nc(end)->year) - this->year;
			$init($Year$1);
			switch ($nc($Year$1::$SwitchMap$java$time$temporal$ChronoUnit)->get($nc((chronoUnit))->ordinal())) {
			case 1:
				{
					return yearsUntil;
				}
			case 2:
				{
					return yearsUntil / 10;
				}
			case 3:
				{
					return yearsUntil / 100;
				}
			case 4:
				{
					return yearsUntil / 1000;
				}
			case 5:
				{
					$init($ChronoField);
					int64_t var$1 = end->getLong($ChronoField::ERA);
					return var$1 - getLong($ChronoField::ERA);
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported unit: "_s, unit}));
		}
	}
	return $nc(unit)->between(this, end);
}

$String* Year::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$LocalDate* Year::atDay(int32_t dayOfYear) {
	return $LocalDate::ofYearDay(this->year, dayOfYear);
}

$YearMonth* Year::atMonth($Month* month) {
	return $YearMonth::of(this->year, month);
}

$YearMonth* Year::atMonth(int32_t month) {
	return $YearMonth::of(this->year, month);
}

$LocalDate* Year::atMonthDay($MonthDay* monthDay) {
	return $nc(monthDay)->atYear(this->year);
}

int32_t Year::compareTo(Year* other) {
	return this->year - $nc(other)->year;
}

bool Year::isAfter(Year* other) {
	return this->year > $nc(other)->year;
}

bool Year::isBefore(Year* other) {
	return this->year < $nc(other)->year;
}

bool Year::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(Year, obj)) {
		return this->year == $nc(($cast(Year, obj)))->year;
	}
	return false;
}

int32_t Year::hashCode() {
	return this->year;
}

$String* Year::toString() {
	return $Integer::toString(this->year);
}

$Object* Year::writeReplace() {
	return $of($new($Ser, $Ser::YEAR_TYPE, this));
}

void Year::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void Year::writeExternal($DataOutput* out) {
	$nc(out)->writeInt(this->year);
}

Year* Year::readExternal($DataInput* in) {
	$init(Year);
	return Year::of($nc(in)->readInt());
}

int32_t Year::compareTo(Object$* other) {
	return this->compareTo($cast(Year, other));
}

void clinit$Year($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$init($SignStyle);
	$assignStatic(Year::PARSER, $nc($($nc($($$new($DateTimeFormatterBuilder)->parseLenient()))->appendValue($ChronoField::YEAR, 1, 10, $SignStyle::NORMAL)))->toFormatter());
}

Year::Year() {
}

$Class* Year::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Year$$Lambda$from::classInfo$.name)) {
			return Year$$Lambda$from::load$(name, initialize);
		}
	}
	$loadClass(Year, name, initialize, &_Year_ClassInfo_, clinit$Year, allocate$Year);
	return class$;
}

$Class* Year::class$ = nullptr;

	} // time
} // java