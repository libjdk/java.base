#include <java/time/format/DateTimeFormatterBuilder$ReducedPrinterParser.h>

#include <java/io/Serializable.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/DateTimeException.h>
#include <java/time/LocalDate.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/format/DateTimeFormatterBuilder$NumberPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/DateTimeParseContext.h>
#include <java/time/format/DateTimePrintContext.h>
#include <java/time/format/SignStyle.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Objects.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

#undef BASE_DATE
#undef EXCEED_POINTS
#undef MAX_VALUE
#undef NOT_NEGATIVE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DateTimeException = ::java::time::DateTimeException;
using $LocalDate = ::java::time::LocalDate;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $Chronology = ::java::time::chrono::Chronology;
using $DateTimeFormatterBuilder$NumberPrinterParser = ::java::time::format::DateTimeFormatterBuilder$NumberPrinterParser;
using $DateTimeParseContext = ::java::time::format::DateTimeParseContext;
using $DateTimePrintContext = ::java::time::format::DateTimePrintContext;
using $SignStyle = ::java::time::format::SignStyle;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Objects = ::java::util::Objects;
using $Consumer = ::java::util::function::Consumer;

namespace java {
	namespace time {
		namespace format {

class DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0 : public $Consumer {
	$class(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$(DateTimeFormatterBuilder$ReducedPrinterParser* inst, $DateTimeParseContext* context, int64_t initialValue, int32_t errorPos, int32_t successPos) {
		$set(this, inst$, inst);
		$set(this, context, context);
		this->initialValue = initialValue;
		this->errorPos = errorPos;
		this->successPos = successPos;
	}
	virtual void accept(Object$* _unused) override {
		$nc(inst$)->lambda$setValue$0(context, initialValue, errorPos, successPos, $cast($Chronology, _unused));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0>());
	}
	DateTimeFormatterBuilder$ReducedPrinterParser* inst$ = nullptr;
	$DateTimeParseContext* context = nullptr;
	int64_t initialValue = 0;
	int32_t errorPos = 0;
	int32_t successPos = 0;
	static $FieldInfo fieldInfos[6];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::fieldInfos[6] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, inst$)},
	{"context", "Ljava/time/format/DateTimeParseContext;", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, context)},
	{"initialValue", "J", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, initialValue)},
	{"errorPos", "I", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, errorPos)},
	{"successPos", "I", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, successPos)},
	{}
};
$MethodInfo DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::methodInfos[3] = {
	{"<init>", "(Ljava/time/format/DateTimeFormatterBuilder$ReducedPrinterParser;Ljava/time/format/DateTimeParseContext;JII)V", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, init$, void, DateTimeFormatterBuilder$ReducedPrinterParser*, $DateTimeParseContext*, int64_t, int32_t, int32_t)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, accept, void, Object$*)},
	{}
};
$ClassInfo DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::class$ = nullptr;

$FieldInfo _DateTimeFormatterBuilder$ReducedPrinterParser_FieldInfo_[] = {
	{"BASE_DATE", "Ljava/time/LocalDate;", nullptr, $STATIC | $FINAL, $staticField(DateTimeFormatterBuilder$ReducedPrinterParser, BASE_DATE)},
	{"baseValue", "I", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$ReducedPrinterParser, baseValue)},
	{"baseDate", "Ljava/time/chrono/ChronoLocalDate;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$ReducedPrinterParser, baseDate)},
	{}
};

$MethodInfo _DateTimeFormatterBuilder$ReducedPrinterParser_MethodInfo_[] = {
	{"<init>", "(Ljava/time/temporal/TemporalField;IIILjava/time/chrono/ChronoLocalDate;)V", nullptr, 0, $method(DateTimeFormatterBuilder$ReducedPrinterParser, init$, void, $TemporalField*, int32_t, int32_t, int32_t, $ChronoLocalDate*)},
	{"<init>", "(Ljava/time/temporal/TemporalField;IIILjava/time/chrono/ChronoLocalDate;I)V", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder$ReducedPrinterParser, init$, void, $TemporalField*, int32_t, int32_t, int32_t, $ChronoLocalDate*, int32_t)},
	{"getValue", "(Ljava/time/format/DateTimePrintContext;J)J", nullptr, 0, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser, getValue, int64_t, $DateTimePrintContext*, int64_t)},
	{"isFixedWidth", "(Ljava/time/format/DateTimeParseContext;)Z", nullptr, 0, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser, isFixedWidth, bool, $DateTimeParseContext*)},
	{"lambda$setValue$0", "(Ljava/time/format/DateTimeParseContext;JIILjava/time/chrono/Chronology;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(DateTimeFormatterBuilder$ReducedPrinterParser, lambda$setValue$0, void, $DateTimeParseContext*, int64_t, int32_t, int32_t, $Chronology*)},
	{"setValue", "(Ljava/time/format/DateTimeParseContext;JII)I", nullptr, 0, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser, setValue, int32_t, $DateTimeParseContext*, int64_t, int32_t, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser, toString, $String*)},
	{"withFixedWidth", "()Ljava/time/format/DateTimeFormatterBuilder$ReducedPrinterParser;", nullptr, 0, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser, withFixedWidth, DateTimeFormatterBuilder$ReducedPrinterParser*)},
	{"withSubsequentWidth", "(I)Ljava/time/format/DateTimeFormatterBuilder$ReducedPrinterParser;", nullptr, 0, $virtualMethod(DateTimeFormatterBuilder$ReducedPrinterParser, withSubsequentWidth, DateTimeFormatterBuilder$ReducedPrinterParser*, int32_t)},
	{}
};

$InnerClassInfo _DateTimeFormatterBuilder$ReducedPrinterParser_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeFormatterBuilder$ReducedPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ReducedPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$NumberPrinterParser", "java.time.format.DateTimeFormatterBuilder", "NumberPrinterParser", $STATIC},
	{}
};

$ClassInfo _DateTimeFormatterBuilder$ReducedPrinterParser_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.DateTimeFormatterBuilder$ReducedPrinterParser",
	"java.time.format.DateTimeFormatterBuilder$NumberPrinterParser",
	nullptr,
	_DateTimeFormatterBuilder$ReducedPrinterParser_FieldInfo_,
	_DateTimeFormatterBuilder$ReducedPrinterParser_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeFormatterBuilder$ReducedPrinterParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.format.DateTimeFormatterBuilder"
};

$Object* allocate$DateTimeFormatterBuilder$ReducedPrinterParser($Class* clazz) {
	return $of($alloc(DateTimeFormatterBuilder$ReducedPrinterParser));
}

$LocalDate* DateTimeFormatterBuilder$ReducedPrinterParser::BASE_DATE = nullptr;

void DateTimeFormatterBuilder$ReducedPrinterParser::init$($TemporalField* field, int32_t minWidth, int32_t maxWidth, int32_t baseValue, $ChronoLocalDate* baseDate) {
	$useLocalCurrentObjectStackCache();
	DateTimeFormatterBuilder$ReducedPrinterParser::init$(field, minWidth, maxWidth, baseValue, baseDate, 0);
	if (minWidth < 1 || minWidth > 10) {
		$throwNew($IllegalArgumentException, $$str({"The minWidth must be from 1 to 10 inclusive but was "_s, $$str(minWidth)}));
	}
	if (maxWidth < 1 || maxWidth > 10) {
		$throwNew($IllegalArgumentException, $$str({"The maxWidth must be from 1 to 10 inclusive but was "_s, $$str(minWidth)}));
	}
	if (maxWidth < minWidth) {
		$throwNew($IllegalArgumentException, $$str({"Maximum width must exceed or equal the minimum width but "_s, $$str(maxWidth), " < "_s, $$str(minWidth)}));
	}
	if (baseDate == nullptr) {
		if ($nc($($nc(field)->range()))->isValidValue(baseValue) == false) {
			$throwNew($IllegalArgumentException, "The base value must be within the range of the field"_s);
		}
		$init($DateTimeFormatterBuilder$NumberPrinterParser);
		if ((((int64_t)baseValue) + $nc($DateTimeFormatterBuilder$NumberPrinterParser::EXCEED_POINTS)->get(maxWidth)) > $Integer::MAX_VALUE) {
			$throwNew($DateTimeException, "Unable to add printer-parser as the range exceeds the capacity of an int"_s);
		}
	}
}

void DateTimeFormatterBuilder$ReducedPrinterParser::init$($TemporalField* field, int32_t minWidth, int32_t maxWidth, int32_t baseValue, $ChronoLocalDate* baseDate, int32_t subsequentWidth) {
	$init($SignStyle);
	$DateTimeFormatterBuilder$NumberPrinterParser::init$(field, minWidth, maxWidth, $SignStyle::NOT_NEGATIVE, subsequentWidth);
	this->baseValue = baseValue;
	$set(this, baseDate, baseDate);
}

int64_t DateTimeFormatterBuilder$ReducedPrinterParser::getValue($DateTimePrintContext* context, int64_t value) {
	$useLocalCurrentObjectStackCache();
	int64_t absValue = $Math::abs(value);
	int32_t baseValue = this->baseValue;
	if (this->baseDate != nullptr) {
		$var($Chronology, chrono, $Chronology::from($($nc(context)->getTemporal())));
		baseValue = $nc($($nc(chrono)->date(this->baseDate)))->get(this->field);
	}
	$init($DateTimeFormatterBuilder$NumberPrinterParser);
	if (value >= baseValue && value < baseValue + $nc($DateTimeFormatterBuilder$NumberPrinterParser::EXCEED_POINTS)->get(this->minWidth)) {
		return $mod(absValue, $nc($DateTimeFormatterBuilder$NumberPrinterParser::EXCEED_POINTS)->get(this->minWidth));
	}
	return $mod(absValue, $nc($DateTimeFormatterBuilder$NumberPrinterParser::EXCEED_POINTS)->get(this->maxWidth));
}

int32_t DateTimeFormatterBuilder$ReducedPrinterParser::setValue($DateTimeParseContext* context, int64_t value, int32_t errorPos, int32_t successPos) {
	$useLocalCurrentObjectStackCache();
	int32_t baseValue = this->baseValue;
	if (this->baseDate != nullptr) {
		$var($Chronology, chrono, $nc(context)->getEffectiveChronology());
		baseValue = $nc($($nc(chrono)->date(this->baseDate)))->get(this->field);
		int64_t initialValue = value;
		context->addChronoChangedListener(static_cast<$Consumer*>($$new(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0, this, context, initialValue, errorPos, successPos)));
	}
	int32_t parseLen = successPos - errorPos;
	if (parseLen == this->minWidth && value >= 0) {
		$init($DateTimeFormatterBuilder$NumberPrinterParser);
		int64_t range = $nc($DateTimeFormatterBuilder$NumberPrinterParser::EXCEED_POINTS)->get(this->minWidth);
		int64_t lastPart = $mod(baseValue, range);
		int64_t basePart = baseValue - lastPart;
		if (baseValue > 0) {
			value = basePart + value;
		} else {
			value = basePart - value;
		}
		if (value < baseValue) {
			value += range;
		}
	}
	return $nc(context)->setParsedField(this->field, value, errorPos, successPos);
}

DateTimeFormatterBuilder$ReducedPrinterParser* DateTimeFormatterBuilder$ReducedPrinterParser::withFixedWidth() {
	if (this->subsequentWidth == -1) {
		return this;
	}
	return $new(DateTimeFormatterBuilder$ReducedPrinterParser, this->field, this->minWidth, this->maxWidth, this->baseValue, this->baseDate, -1);
}

DateTimeFormatterBuilder$ReducedPrinterParser* DateTimeFormatterBuilder$ReducedPrinterParser::withSubsequentWidth(int32_t subsequentWidth) {
	return $new(DateTimeFormatterBuilder$ReducedPrinterParser, this->field, this->minWidth, this->maxWidth, this->baseValue, this->baseDate, this->subsequentWidth + subsequentWidth);
}

bool DateTimeFormatterBuilder$ReducedPrinterParser::isFixedWidth($DateTimeParseContext* context) {
	if ($nc(context)->isStrict() == false) {
		return false;
	}
	return $DateTimeFormatterBuilder$NumberPrinterParser::isFixedWidth(context);
}

$String* DateTimeFormatterBuilder$ReducedPrinterParser::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$1, $$str({"ReducedValue("_s, this->field, ","_s, $$str(this->minWidth), ","_s, $$str(this->maxWidth), ","_s}));
	$var($String, var$0, $$concat(var$1, $($Objects::requireNonNullElse(this->baseDate, $($Integer::valueOf(this->baseValue))))));
	return $concat(var$0, ")"_s);
}

void DateTimeFormatterBuilder$ReducedPrinterParser::lambda$setValue$0($DateTimeParseContext* context, int64_t initialValue, int32_t errorPos, int32_t successPos, $Chronology* _unused) {
	setValue(context, initialValue, errorPos, successPos);
}

void clinit$DateTimeFormatterBuilder$ReducedPrinterParser($Class* class$) {
	$assignStatic(DateTimeFormatterBuilder$ReducedPrinterParser::BASE_DATE, $LocalDate::of(2000, 1, 1));
}

DateTimeFormatterBuilder$ReducedPrinterParser::DateTimeFormatterBuilder$ReducedPrinterParser() {
}

$Class* DateTimeFormatterBuilder$ReducedPrinterParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::classInfo$.name)) {
			return DateTimeFormatterBuilder$ReducedPrinterParser$$Lambda$lambda$setValue$0::load$(name, initialize);
		}
	}
	$loadClass(DateTimeFormatterBuilder$ReducedPrinterParser, name, initialize, &_DateTimeFormatterBuilder$ReducedPrinterParser_ClassInfo_, clinit$DateTimeFormatterBuilder$ReducedPrinterParser, allocate$DateTimeFormatterBuilder$ReducedPrinterParser);
	return class$;
}

$Class* DateTimeFormatterBuilder$ReducedPrinterParser::class$ = nullptr;

		} // format
	} // time
} // java