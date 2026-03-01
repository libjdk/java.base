#include <java/time/MonthDay.h>

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
#include <java/time/MonthDay$1.h>
#include <java/time/Ser.h>
#include <java/time/Year.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef DAY_OF_MONTH
#undef INSTANCE
#undef MONTH_DAY_TYPE
#undef MONTH_OF_YEAR
#undef PARSER

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
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $LocalDate = ::java::time::LocalDate;
using $Month = ::java::time::Month;
using $MonthDay$1 = ::java::time::MonthDay$1;
using $Ser = ::java::time::Ser;
using $Year = ::java::time::Year;
using $ZoneId = ::java::time::ZoneId;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $ChronoField = ::java::time::temporal::ChronoField;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {

class MonthDay$$Lambda$from : public $TemporalQuery {
	$class(MonthDay$$Lambda$from, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(MonthDay::from(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MonthDay$$Lambda$from>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MonthDay$$Lambda$from::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MonthDay$$Lambda$from, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MonthDay$$Lambda$from, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo MonthDay$$Lambda$from::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.MonthDay$$Lambda$from",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* MonthDay$$Lambda$from::load$($String* name, bool initialize) {
	$loadClass(MonthDay$$Lambda$from, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MonthDay$$Lambda$from::class$ = nullptr;

$CompoundAttribute _MonthDay_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$FieldInfo _MonthDay_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MonthDay, serialVersionUID)},
	{"PARSER", "Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MonthDay, PARSER)},
	{"month", "I", nullptr, $PRIVATE | $FINAL, $field(MonthDay, month)},
	{"day", "I", nullptr, $PRIVATE | $FINAL, $field(MonthDay, day)},
	{}
};

$MethodInfo _MonthDay_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(II)V", nullptr, $PRIVATE, $method(MonthDay, init$, void, int32_t, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;)Ljava/time/temporal/Temporal;", nullptr, $PUBLIC, $virtualMethod(MonthDay, adjustInto, $Temporal*, $Temporal*)},
	{"atYear", "(I)Ljava/time/LocalDate;", nullptr, $PUBLIC, $method(MonthDay, atYear, $LocalDate*, int32_t)},
	{"compareTo", "(Ljava/time/MonthDay;)I", nullptr, $PUBLIC, $method(MonthDay, compareTo, int32_t, MonthDay*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MonthDay, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(MonthDay, equals, bool, Object$*)},
	{"format", "(Ljava/time/format/DateTimeFormatter;)Ljava/lang/String;", nullptr, $PUBLIC, $method(MonthDay, format, $String*, $DateTimeFormatter*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, from, MonthDay*, $TemporalAccessor*)},
	{"get", "(Ljava/time/temporal/TemporalField;)I", nullptr, $PUBLIC, $virtualMethod(MonthDay, get, int32_t, $TemporalField*)},
	{"getDayOfMonth", "()I", nullptr, $PUBLIC, $method(MonthDay, getDayOfMonth, int32_t)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(MonthDay, getLong, int64_t, $TemporalField*)},
	{"getMonth", "()Ljava/time/Month;", nullptr, $PUBLIC, $method(MonthDay, getMonth, $Month*)},
	{"getMonthValue", "()I", nullptr, $PUBLIC, $method(MonthDay, getMonthValue, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(MonthDay, hashCode, int32_t)},
	{"isAfter", "(Ljava/time/MonthDay;)Z", nullptr, $PUBLIC, $method(MonthDay, isAfter, bool, MonthDay*)},
	{"isBefore", "(Ljava/time/MonthDay;)Z", nullptr, $PUBLIC, $method(MonthDay, isBefore, bool, MonthDay*)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(MonthDay, isSupported, bool, $TemporalField*)},
	{"isValidYear", "(I)Z", nullptr, $PUBLIC, $method(MonthDay, isValidYear, bool, int32_t)},
	{"now", "()Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, now, MonthDay*)},
	{"now", "(Ljava/time/ZoneId;)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, now, MonthDay*, $ZoneId*)},
	{"now", "(Ljava/time/Clock;)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, now, MonthDay*, $Clock*)},
	{"of", "(Ljava/time/Month;I)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, of, MonthDay*, $Month*, int32_t)},
	{"of", "(II)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, of, MonthDay*, int32_t, int32_t)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, parse, MonthDay*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/format/DateTimeFormatter;)Ljava/time/MonthDay;", nullptr, $PUBLIC | $STATIC, $staticMethod(MonthDay, parse, MonthDay*, $CharSequence*, $DateTimeFormatter*)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(MonthDay, query, $Object*, $TemporalQuery*)},
	{"range", "(Ljava/time/temporal/TemporalField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(MonthDay, range, $ValueRange*, $TemporalField*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/MonthDay;", nullptr, $STATIC, $staticMethod(MonthDay, readExternal, MonthDay*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(MonthDay, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MonthDay, toString, $String*)},
	{"with", "(Ljava/time/Month;)Ljava/time/MonthDay;", nullptr, $PUBLIC, $method(MonthDay, with, MonthDay*, $Month*)},
	{"withDayOfMonth", "(I)Ljava/time/MonthDay;", nullptr, $PUBLIC, $method(MonthDay, withDayOfMonth, MonthDay*, int32_t)},
	{"withMonth", "(I)Ljava/time/MonthDay;", nullptr, $PUBLIC, $method(MonthDay, withMonth, MonthDay*, int32_t)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $method(MonthDay, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(MonthDay, writeReplace, $Object*)},
	{}
};

$InnerClassInfo _MonthDay_InnerClassesInfo_[] = {
	{"java.time.MonthDay$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _MonthDay_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.MonthDay",
	"java.lang.Object",
	"java.time.temporal.TemporalAccessor,java.time.temporal.TemporalAdjuster,java.lang.Comparable,java.io.Serializable",
	_MonthDay_FieldInfo_,
	_MonthDay_MethodInfo_,
	"Ljava/lang/Object;Ljava/time/temporal/TemporalAccessor;Ljava/time/temporal/TemporalAdjuster;Ljava/lang/Comparable<Ljava/time/MonthDay;>;Ljava/io/Serializable;",
	nullptr,
	_MonthDay_InnerClassesInfo_,
	_MonthDay_Annotations_,
	nullptr,
	"java.time.MonthDay$1"
};

$Object* allocate$MonthDay($Class* clazz) {
	return $of($alloc(MonthDay));
}

$Object* MonthDay::clone() {
	 return this->$TemporalAccessor::clone();
}

void MonthDay::finalize() {
	this->$TemporalAccessor::finalize();
}

$DateTimeFormatter* MonthDay::PARSER = nullptr;

MonthDay* MonthDay::now() {
	$init(MonthDay);
	return now($($Clock::systemDefaultZone()));
}

MonthDay* MonthDay::now($ZoneId* zone) {
	$init(MonthDay);
	return now($($Clock::system(zone)));
}

MonthDay* MonthDay::now($Clock* clock) {
	$init(MonthDay);
	$useLocalCurrentObjectStackCache();
	$var($LocalDate, now, $LocalDate::now(clock));
	$var($Month, var$0, $nc(now)->getMonth());
	return MonthDay::of(var$0, now->getDayOfMonth());
}

MonthDay* MonthDay::of($Month* month, int32_t dayOfMonth) {
	$init(MonthDay);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(month), "month"_s);
	$init($ChronoField);
	$ChronoField::DAY_OF_MONTH->checkValidValue(dayOfMonth);
	if (dayOfMonth > $nc(month)->maxLength()) {
		$throwNew($DateTimeException, $$str({"Illegal value for DayOfMonth field, value "_s, $$str(dayOfMonth), " is not valid for month "_s, $(month->name())}));
	}
	return $new(MonthDay, $nc(month)->getValue(), dayOfMonth);
}

MonthDay* MonthDay::of(int32_t month, int32_t dayOfMonth) {
	$init(MonthDay);
	return of($($Month::of(month)), dayOfMonth);
}

MonthDay* MonthDay::from($TemporalAccessor* temporal$renamed) {
	$init(MonthDay);
	$useLocalCurrentObjectStackCache();
	$var($TemporalAccessor, temporal, temporal$renamed);
	if ($instanceOf(MonthDay, temporal)) {
		return $cast(MonthDay, temporal);
	}
	try {
		$init($IsoChronology);
		if ($nc($IsoChronology::INSTANCE)->equals($($Chronology::from(temporal))) == false) {
			$assign(temporal, $LocalDate::from(temporal));
		}
		$init($ChronoField);
		int32_t var$0 = $nc(temporal)->get($ChronoField::MONTH_OF_YEAR);
		return of(var$0, temporal->get($ChronoField::DAY_OF_MONTH));
	} catch ($DateTimeException& ex) {
		$var($String, var$1, $$str({"Unable to obtain MonthDay from TemporalAccessor: "_s, temporal, " of type "_s}));
		$throwNew($DateTimeException, $$concat(var$1, $($nc($of(temporal))->getClass()->getName())), ex);
	}
	$shouldNotReachHere();
}

MonthDay* MonthDay::parse($CharSequence* text) {
	$init(MonthDay);
	return parse(text, MonthDay::PARSER);
}

MonthDay* MonthDay::parse($CharSequence* text, $DateTimeFormatter* formatter) {
	$init(MonthDay);
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $cast(MonthDay, $nc(formatter)->parse(text, static_cast<$TemporalQuery*>($$new(MonthDay$$Lambda$from))));
}

void MonthDay::init$(int32_t month, int32_t dayOfMonth) {
	this->month = month;
	this->day = dayOfMonth;
}

bool MonthDay::isSupported($TemporalField* field) {
	if ($instanceOf($ChronoField, field)) {
		$init($ChronoField);
		return $equals(field, $ChronoField::MONTH_OF_YEAR) || $equals(field, $ChronoField::DAY_OF_MONTH);
	}
	return field != nullptr && field->isSupportedBy(this);
}

$ValueRange* MonthDay::range($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	if ($equals(field, $ChronoField::MONTH_OF_YEAR)) {
		return field->range();
	} else {
		if ($equals(field, $ChronoField::DAY_OF_MONTH)) {
			int64_t var$0 = (int64_t)$nc($(getMonth()))->minLength();
			return $ValueRange::of(1, var$0, $nc($(getMonth()))->maxLength());
		}
	}
	return $TemporalAccessor::range(field);
}

int32_t MonthDay::get($TemporalField* field) {
	return $nc($(range(field)))->checkValidIntValue(getLong(field), field);
}

int64_t MonthDay::getLong($TemporalField* field) {
	{
		$ChronoField* chronoField = nullptr;
		bool var$0 = $instanceOf($ChronoField, field);
		if (var$0) {
			chronoField = $cast($ChronoField, field);
			var$0 = true;
		}
		if (var$0) {
			$init($MonthDay$1);
			switch ($nc($MonthDay$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((chronoField))->ordinal())) {
			case 1:
				{
					return this->day;
				}
			case 2:
				{
					return this->month;
				}
			}
			$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
		}
	}
	return $nc(field)->getFrom(this);
}

int32_t MonthDay::getMonthValue() {
	return this->month;
}

$Month* MonthDay::getMonth() {
	return $Month::of(this->month);
}

int32_t MonthDay::getDayOfMonth() {
	return this->day;
}

bool MonthDay::isValidYear(int32_t year) {
	return (this->day == 29 && this->month == 2 && $Year::isLeap(year) == false) == false;
}

MonthDay* MonthDay::withMonth(int32_t month) {
	return with($($Month::of(month)));
}

MonthDay* MonthDay::with($Month* month) {
	$Objects::requireNonNull($of(month), "month"_s);
	if ($nc(month)->getValue() == this->month) {
		return this;
	}
	int32_t day = $Math::min(this->day, $nc(month)->maxLength());
	return $new(MonthDay, $nc(month)->getValue(), day);
}

MonthDay* MonthDay::withDayOfMonth(int32_t dayOfMonth) {
	if (dayOfMonth == this->day) {
		return this;
	}
	return of(this->month, dayOfMonth);
}

$Object* MonthDay::query($TemporalQuery* query) {
	if (query == $TemporalQueries::chronology()) {
		$init($IsoChronology);
		return $of($of($IsoChronology::INSTANCE));
	}
	return $of($TemporalAccessor::query(query));
}

$Temporal* MonthDay::adjustInto($Temporal* temporal$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Temporal, temporal, temporal$renamed);
	$init($IsoChronology);
	if ($nc($($Chronology::from(temporal)))->equals($IsoChronology::INSTANCE) == false) {
		$throwNew($DateTimeException, "Adjustment only supported on ISO date-time"_s);
	}
	$init($ChronoField);
	$assign(temporal, $nc(temporal)->with($ChronoField::MONTH_OF_YEAR, this->month));
	return temporal->with($ChronoField::DAY_OF_MONTH, $Math::min($nc($(temporal->range($ChronoField::DAY_OF_MONTH)))->getMaximum(), (int64_t)this->day));
}

$String* MonthDay::format($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	return $nc(formatter)->format(this);
}

$LocalDate* MonthDay::atYear(int32_t year) {
	return $LocalDate::of(year, this->month, isValidYear(year) ? this->day : 28);
}

int32_t MonthDay::compareTo(MonthDay* other) {
	int32_t cmp = (this->month - $nc(other)->month);
	if (cmp == 0) {
		cmp = (this->day - other->day);
	}
	return cmp;
}

bool MonthDay::isAfter(MonthDay* other) {
	return compareTo(other) > 0;
}

bool MonthDay::isBefore(MonthDay* other) {
	return compareTo(other) < 0;
}

bool MonthDay::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(MonthDay, other, nullptr);
	bool var$2 = $instanceOf(MonthDay, obj);
	if (var$2) {
		$assign(other, $cast(MonthDay, obj));
		var$2 = true;
	}
	bool var$1 = (var$2);
	bool var$0 = var$1 && this->month == $nc(other)->month;
	return var$0 && this->day == other->day;
}

int32_t MonthDay::hashCode() {
	return (this->month << 6) + this->day;
}

$String* MonthDay::toString() {
	return $$new($StringBuilder, 10)->append("--"_s)->append(this->month < 10 ? "0"_s : ""_s)->append(this->month)->append(this->day < 10 ? "-0"_s : "-"_s)->append(this->day)->toString();
}

$Object* MonthDay::writeReplace() {
	return $of($new($Ser, $Ser::MONTH_DAY_TYPE, this));
}

void MonthDay::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void MonthDay::writeExternal($DataOutput* out) {
	$nc(out)->writeByte(this->month);
	out->writeByte(this->day);
}

MonthDay* MonthDay::readExternal($DataInput* in) {
	$init(MonthDay);
	int8_t month = $nc(in)->readByte();
	int8_t day = in->readByte();
	return MonthDay::of((int32_t)month, (int32_t)day);
}

int32_t MonthDay::compareTo(Object$* other) {
	return this->compareTo($cast(MonthDay, other));
}

void clinit$MonthDay($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$assignStatic(MonthDay::PARSER, $nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->appendLiteral("--"_s)))->appendValue($ChronoField::MONTH_OF_YEAR, 2)))->appendLiteral(u'-')))->appendValue($ChronoField::DAY_OF_MONTH, 2)))->toFormatter());
}

MonthDay::MonthDay() {
}

$Class* MonthDay::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MonthDay$$Lambda$from::classInfo$.name)) {
			return MonthDay$$Lambda$from::load$(name, initialize);
		}
	}
	$loadClass(MonthDay, name, initialize, &_MonthDay_ClassInfo_, clinit$MonthDay, allocate$MonthDay);
	return class$;
}

$Class* MonthDay::class$ = nullptr;

	} // time
} // java