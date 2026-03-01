#include <java/time/format/DateTimeFormatter.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/text/Format.h>
#include <java/text/ParsePosition.h>
#include <java/time/DateTimeException.h>
#include <java/time/Period.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeFormatter$ClassicFormat.h>
#include <java/time/format/DateTimeFormatterBuilder$CompositePrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/DateTimeParseContext.h>
#include <java/time/format/DateTimeParseException.h>
#include <java/time/format/DateTimePrintContext.h>
#include <java/time/format/DecimalStyle.h>
#include <java/time/format/FormatStyle.h>
#include <java/time/format/Parsed.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/format/SignStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/IsoFields.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <jcpp.h>

#undef BASIC_ISO_DATE
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_YEAR
#undef EXCEEDS_PAD
#undef FALSE
#undef HOUR_OF_DAY
#undef INSTANCE
#undef ISO_DATE
#undef ISO_DATE_TIME
#undef ISO_INSTANT
#undef ISO_LOCAL_DATE
#undef ISO_LOCAL_DATE_TIME
#undef ISO_LOCAL_TIME
#undef ISO_OFFSET_DATE
#undef ISO_OFFSET_DATE_TIME
#undef ISO_OFFSET_TIME
#undef ISO_ORDINAL_DATE
#undef ISO_TIME
#undef ISO_WEEK_DATE
#undef ISO_ZONED_DATE_TIME
#undef MINUTE_OF_HOUR
#undef MONTH_OF_YEAR
#undef NANO_OF_SECOND
#undef NOT_NEGATIVE
#undef PARSED_EXCESS_DAYS
#undef PARSED_LEAP_SECOND
#undef SECOND_OF_MINUTE
#undef SMART
#undef STRICT
#undef WEEK_BASED_YEAR
#undef WEEK_OF_WEEK_BASED_YEAR
#undef YEAR
#undef ZERO

using $TemporalFieldArray = $Array<::java::time::temporal::TemporalField>;
using $TemporalQueryArray = $Array<::java::time::temporal::TemporalQuery>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $Appendable = ::java::lang::Appendable;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Format = ::java::text::Format;
using $ParsePosition = ::java::text::ParsePosition;
using $DateTimeException = ::java::time::DateTimeException;
using $Period = ::java::time::Period;
using $ZoneId = ::java::time::ZoneId;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeFormatter$ClassicFormat = ::java::time::format::DateTimeFormatter$ClassicFormat;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $DateTimeFormatterBuilder$CompositePrinterParser = ::java::time::format::DateTimeFormatterBuilder$CompositePrinterParser;
using $DateTimeParseContext = ::java::time::format::DateTimeParseContext;
using $DateTimeParseException = ::java::time::format::DateTimeParseException;
using $DateTimePrintContext = ::java::time::format::DateTimePrintContext;
using $DecimalStyle = ::java::time::format::DecimalStyle;
using $FormatStyle = ::java::time::format::FormatStyle;
using $Parsed = ::java::time::format::Parsed;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $SignStyle = ::java::time::format::SignStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $IsoFields = ::java::time::temporal::IsoFields;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;

namespace java {
	namespace time {
		namespace format {

class DateTimeFormatter$$Lambda$lambda$static$0 : public $TemporalQuery {
	$class(DateTimeFormatter$$Lambda$lambda$static$0, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* t) override {
		 return $of(DateTimeFormatter::lambda$static$0(t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatter$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DateTimeFormatter$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateTimeFormatter$$Lambda$lambda$static$0, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatter$$Lambda$lambda$static$0, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo DateTimeFormatter$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatter$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* DateTimeFormatter$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatter$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatter$$Lambda$lambda$static$0::class$ = nullptr;

class DateTimeFormatter$$Lambda$lambda$static$1$1 : public $TemporalQuery {
	$class(DateTimeFormatter$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* t) override {
		 return $of(DateTimeFormatter::lambda$static$1(t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatter$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DateTimeFormatter$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateTimeFormatter$$Lambda$lambda$static$1$1, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatter$$Lambda$lambda$static$1$1, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo DateTimeFormatter$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatter$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* DateTimeFormatter$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatter$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatter$$Lambda$lambda$static$1$1::class$ = nullptr;

class DateTimeFormatter$$Lambda$of$2 : public $Function {
	$class(DateTimeFormatter$$Lambda$of$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* zoneId) override {
		 return $of($ZoneId::of($cast($String, zoneId)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatter$$Lambda$of$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DateTimeFormatter$$Lambda$of$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateTimeFormatter$$Lambda$of$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatter$$Lambda$of$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo DateTimeFormatter$$Lambda$of$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatter$$Lambda$of$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* DateTimeFormatter$$Lambda$of$2::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatter$$Lambda$of$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatter$$Lambda$of$2::class$ = nullptr;

$FieldInfo _DateTimeFormatter_FieldInfo_[] = {
	{"printerParser", "Ljava/time/format/DateTimeFormatterBuilder$CompositePrinterParser;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatter, printerParser)},
	{"locale", "Ljava/util/Locale;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatter, locale)},
	{"decimalStyle", "Ljava/time/format/DecimalStyle;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatter, decimalStyle)},
	{"resolverStyle", "Ljava/time/format/ResolverStyle;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatter, resolverStyle)},
	{"resolverFields", "Ljava/util/Set;", "Ljava/util/Set<Ljava/time/temporal/TemporalField;>;", $PRIVATE | $FINAL, $field(DateTimeFormatter, resolverFields)},
	{"chrono", "Ljava/time/chrono/Chronology;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatter, chrono)},
	{"zone", "Ljava/time/ZoneId;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatter, zone)},
	{"ISO_LOCAL_DATE", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_LOCAL_DATE)},
	{"ISO_OFFSET_DATE", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_OFFSET_DATE)},
	{"ISO_DATE", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_DATE)},
	{"ISO_LOCAL_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_LOCAL_TIME)},
	{"ISO_OFFSET_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_OFFSET_TIME)},
	{"ISO_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_TIME)},
	{"ISO_LOCAL_DATE_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_LOCAL_DATE_TIME)},
	{"ISO_OFFSET_DATE_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_OFFSET_DATE_TIME)},
	{"ISO_ZONED_DATE_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_ZONED_DATE_TIME)},
	{"ISO_DATE_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_DATE_TIME)},
	{"ISO_ORDINAL_DATE", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_ORDINAL_DATE)},
	{"ISO_WEEK_DATE", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_WEEK_DATE)},
	{"ISO_INSTANT", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, ISO_INSTANT)},
	{"BASIC_ISO_DATE", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, BASIC_ISO_DATE)},
	{"RFC_1123_DATE_TIME", "Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DateTimeFormatter, RFC_1123_DATE_TIME)},
	{"PARSED_EXCESS_DAYS", "Ljava/time/temporal/TemporalQuery;", "Ljava/time/temporal/TemporalQuery<Ljava/time/Period;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeFormatter, PARSED_EXCESS_DAYS)},
	{"PARSED_LEAP_SECOND", "Ljava/time/temporal/TemporalQuery;", "Ljava/time/temporal/TemporalQuery<Ljava/lang/Boolean;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeFormatter, PARSED_LEAP_SECOND)},
	{}
};

$MethodInfo _DateTimeFormatter_MethodInfo_[] = {
	{"<init>", "(Ljava/time/format/DateTimeFormatterBuilder$CompositePrinterParser;Ljava/util/Locale;Ljava/time/format/DecimalStyle;Ljava/time/format/ResolverStyle;Ljava/util/Set;Ljava/time/chrono/Chronology;Ljava/time/ZoneId;)V", "(Ljava/time/format/DateTimeFormatterBuilder$CompositePrinterParser;Ljava/util/Locale;Ljava/time/format/DecimalStyle;Ljava/time/format/ResolverStyle;Ljava/util/Set<Ljava/time/temporal/TemporalField;>;Ljava/time/chrono/Chronology;Ljava/time/ZoneId;)V", 0, $method(DateTimeFormatter, init$, void, $DateTimeFormatterBuilder$CompositePrinterParser*, $Locale*, $DecimalStyle*, $ResolverStyle*, $Set*, $Chronology*, $ZoneId*)},
	{"createError", "(Ljava/lang/CharSequence;Ljava/lang/RuntimeException;)Ljava/time/format/DateTimeParseException;", nullptr, $PRIVATE, $method(DateTimeFormatter, createError, $DateTimeParseException*, $CharSequence*, $RuntimeException*)},
	{"format", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/String;", nullptr, $PUBLIC, $method(DateTimeFormatter, format, $String*, $TemporalAccessor*)},
	{"formatTo", "(Ljava/time/temporal/TemporalAccessor;Ljava/lang/Appendable;)V", nullptr, $PUBLIC, $method(DateTimeFormatter, formatTo, void, $TemporalAccessor*, $Appendable*)},
	{"getChronology", "()Ljava/time/chrono/Chronology;", nullptr, $PUBLIC, $method(DateTimeFormatter, getChronology, $Chronology*)},
	{"getDecimalStyle", "()Ljava/time/format/DecimalStyle;", nullptr, $PUBLIC, $method(DateTimeFormatter, getDecimalStyle, $DecimalStyle*)},
	{"getLocale", "()Ljava/util/Locale;", nullptr, $PUBLIC, $method(DateTimeFormatter, getLocale, $Locale*)},
	{"getResolverFields", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/time/temporal/TemporalField;>;", $PUBLIC, $method(DateTimeFormatter, getResolverFields, $Set*)},
	{"getResolverStyle", "()Ljava/time/format/ResolverStyle;", nullptr, $PUBLIC, $method(DateTimeFormatter, getResolverStyle, $ResolverStyle*)},
	{"getZone", "()Ljava/time/ZoneId;", nullptr, $PUBLIC, $method(DateTimeFormatter, getZone, $ZoneId*)},
	{"lambda$static$0", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/Period;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DateTimeFormatter, lambda$static$0, $Period*, $TemporalAccessor*)},
	{"lambda$static$1", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DateTimeFormatter, lambda$static$1, $Boolean*, $TemporalAccessor*)},
	{"localizedBy", "(Ljava/util/Locale;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatter, localizedBy, DateTimeFormatter*, $Locale*)},
	{"ofLocalizedDate", "(Ljava/time/format/FormatStyle;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatter, ofLocalizedDate, DateTimeFormatter*, $FormatStyle*)},
	{"ofLocalizedDateTime", "(Ljava/time/format/FormatStyle;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatter, ofLocalizedDateTime, DateTimeFormatter*, $FormatStyle*)},
	{"ofLocalizedDateTime", "(Ljava/time/format/FormatStyle;Ljava/time/format/FormatStyle;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatter, ofLocalizedDateTime, DateTimeFormatter*, $FormatStyle*, $FormatStyle*)},
	{"ofLocalizedTime", "(Ljava/time/format/FormatStyle;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatter, ofLocalizedTime, DateTimeFormatter*, $FormatStyle*)},
	{"ofPattern", "(Ljava/lang/String;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatter, ofPattern, DateTimeFormatter*, $String*)},
	{"ofPattern", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatter, ofPattern, DateTimeFormatter*, $String*, $Locale*)},
	{"parse", "(Ljava/lang/CharSequence;)Ljava/time/temporal/TemporalAccessor;", nullptr, $PUBLIC, $method(DateTimeFormatter, parse, $TemporalAccessor*, $CharSequence*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/text/ParsePosition;)Ljava/time/temporal/TemporalAccessor;", nullptr, $PUBLIC, $method(DateTimeFormatter, parse, $TemporalAccessor*, $CharSequence*, $ParsePosition*)},
	{"parse", "(Ljava/lang/CharSequence;Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/CharSequence;Ljava/time/temporal/TemporalQuery<TT;>;)TT;", $PUBLIC, $method(DateTimeFormatter, parse, $Object*, $CharSequence*, $TemporalQuery*)},
	{"parseBest", "(Ljava/lang/CharSequence;[Ljava/time/temporal/TemporalQuery;)Ljava/time/temporal/TemporalAccessor;", "(Ljava/lang/CharSequence;[Ljava/time/temporal/TemporalQuery<*>;)Ljava/time/temporal/TemporalAccessor;", $PUBLIC | $TRANSIENT, $method(DateTimeFormatter, parseBest, $TemporalAccessor*, $CharSequence*, $TemporalQueryArray*)},
	{"parseResolved0", "(Ljava/lang/CharSequence;Ljava/text/ParsePosition;)Ljava/time/temporal/TemporalAccessor;", nullptr, $PRIVATE, $method(DateTimeFormatter, parseResolved0, $TemporalAccessor*, $CharSequence*, $ParsePosition*)},
	{"parseUnresolved", "(Ljava/lang/CharSequence;Ljava/text/ParsePosition;)Ljava/time/temporal/TemporalAccessor;", nullptr, $PUBLIC, $method(DateTimeFormatter, parseUnresolved, $TemporalAccessor*, $CharSequence*, $ParsePosition*)},
	{"parseUnresolved0", "(Ljava/lang/CharSequence;Ljava/text/ParsePosition;)Ljava/time/format/DateTimeParseContext;", nullptr, $PRIVATE, $method(DateTimeFormatter, parseUnresolved0, $DateTimeParseContext*, $CharSequence*, $ParsePosition*)},
	{"parsedExcessDays", "()Ljava/time/temporal/TemporalQuery;", "()Ljava/time/temporal/TemporalQuery<Ljava/time/Period;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(DateTimeFormatter, parsedExcessDays, $TemporalQuery*)},
	{"parsedLeapSecond", "()Ljava/time/temporal/TemporalQuery;", "()Ljava/time/temporal/TemporalQuery<Ljava/lang/Boolean;>;", $PUBLIC | $STATIC | $FINAL, $staticMethod(DateTimeFormatter, parsedLeapSecond, $TemporalQuery*)},
	{"toFormat", "()Ljava/text/Format;", nullptr, $PUBLIC, $method(DateTimeFormatter, toFormat, $Format*)},
	{"toFormat", "(Ljava/time/temporal/TemporalQuery;)Ljava/text/Format;", "(Ljava/time/temporal/TemporalQuery<*>;)Ljava/text/Format;", $PUBLIC, $method(DateTimeFormatter, toFormat, $Format*, $TemporalQuery*)},
	{"toPrinterParser", "(Z)Ljava/time/format/DateTimeFormatterBuilder$CompositePrinterParser;", nullptr, 0, $method(DateTimeFormatter, toPrinterParser, $DateTimeFormatterBuilder$CompositePrinterParser*, bool)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatter, toString, $String*)},
	{"withChronology", "(Ljava/time/chrono/Chronology;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatter, withChronology, DateTimeFormatter*, $Chronology*)},
	{"withDecimalStyle", "(Ljava/time/format/DecimalStyle;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatter, withDecimalStyle, DateTimeFormatter*, $DecimalStyle*)},
	{"withLocale", "(Ljava/util/Locale;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatter, withLocale, DateTimeFormatter*, $Locale*)},
	{"withResolverFields", "([Ljava/time/temporal/TemporalField;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC | $TRANSIENT, $method(DateTimeFormatter, withResolverFields, DateTimeFormatter*, $TemporalFieldArray*)},
	{"withResolverFields", "(Ljava/util/Set;)Ljava/time/format/DateTimeFormatter;", "(Ljava/util/Set<Ljava/time/temporal/TemporalField;>;)Ljava/time/format/DateTimeFormatter;", $PUBLIC, $method(DateTimeFormatter, withResolverFields, DateTimeFormatter*, $Set*)},
	{"withResolverStyle", "(Ljava/time/format/ResolverStyle;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatter, withResolverStyle, DateTimeFormatter*, $ResolverStyle*)},
	{"withZone", "(Ljava/time/ZoneId;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatter, withZone, DateTimeFormatter*, $ZoneId*)},
	{}
};

$InnerClassInfo _DateTimeFormatter_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeFormatter$ClassicFormat", "java.time.format.DateTimeFormatter", "ClassicFormat", $STATIC},
	{}
};

$ClassInfo _DateTimeFormatter_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.format.DateTimeFormatter",
	"java.lang.Object",
	nullptr,
	_DateTimeFormatter_FieldInfo_,
	_DateTimeFormatter_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeFormatter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.format.DateTimeFormatter$ClassicFormat"
};

$Object* allocate$DateTimeFormatter($Class* clazz) {
	return $of($alloc(DateTimeFormatter));
}

DateTimeFormatter* DateTimeFormatter::ISO_LOCAL_DATE = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_OFFSET_DATE = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_DATE = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_LOCAL_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_OFFSET_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_LOCAL_DATE_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_OFFSET_DATE_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_ZONED_DATE_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_DATE_TIME = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_ORDINAL_DATE = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_WEEK_DATE = nullptr;
DateTimeFormatter* DateTimeFormatter::ISO_INSTANT = nullptr;
DateTimeFormatter* DateTimeFormatter::BASIC_ISO_DATE = nullptr;
DateTimeFormatter* DateTimeFormatter::RFC_1123_DATE_TIME = nullptr;
$TemporalQuery* DateTimeFormatter::PARSED_EXCESS_DAYS = nullptr;
$TemporalQuery* DateTimeFormatter::PARSED_LEAP_SECOND = nullptr;

DateTimeFormatter* DateTimeFormatter::ofPattern($String* pattern) {
	$init(DateTimeFormatter);
	$useLocalCurrentObjectStackCache();
	return $nc($($$new($DateTimeFormatterBuilder)->appendPattern(pattern)))->toFormatter();
}

DateTimeFormatter* DateTimeFormatter::ofPattern($String* pattern, $Locale* locale) {
	$init(DateTimeFormatter);
	$useLocalCurrentObjectStackCache();
	return $nc($($$new($DateTimeFormatterBuilder)->appendPattern(pattern)))->toFormatter(locale);
}

DateTimeFormatter* DateTimeFormatter::ofLocalizedDate($FormatStyle* dateStyle) {
	$init(DateTimeFormatter);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(dateStyle), "dateStyle"_s);
	$init($ResolverStyle);
	$init($IsoChronology);
	return $nc($($$new($DateTimeFormatterBuilder)->appendLocalized(dateStyle, nullptr)))->toFormatter($ResolverStyle::SMART, $IsoChronology::INSTANCE);
}

DateTimeFormatter* DateTimeFormatter::ofLocalizedTime($FormatStyle* timeStyle) {
	$init(DateTimeFormatter);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(timeStyle), "timeStyle"_s);
	$init($ResolverStyle);
	$init($IsoChronology);
	return $nc($($$new($DateTimeFormatterBuilder)->appendLocalized(nullptr, timeStyle)))->toFormatter($ResolverStyle::SMART, $IsoChronology::INSTANCE);
}

DateTimeFormatter* DateTimeFormatter::ofLocalizedDateTime($FormatStyle* dateTimeStyle) {
	$init(DateTimeFormatter);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(dateTimeStyle), "dateTimeStyle"_s);
	$init($ResolverStyle);
	$init($IsoChronology);
	return $nc($($$new($DateTimeFormatterBuilder)->appendLocalized(dateTimeStyle, dateTimeStyle)))->toFormatter($ResolverStyle::SMART, $IsoChronology::INSTANCE);
}

DateTimeFormatter* DateTimeFormatter::ofLocalizedDateTime($FormatStyle* dateStyle, $FormatStyle* timeStyle) {
	$init(DateTimeFormatter);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(dateStyle), "dateStyle"_s);
	$Objects::requireNonNull($of(timeStyle), "timeStyle"_s);
	$init($ResolverStyle);
	$init($IsoChronology);
	return $nc($($$new($DateTimeFormatterBuilder)->appendLocalized(dateStyle, timeStyle)))->toFormatter($ResolverStyle::SMART, $IsoChronology::INSTANCE);
}

$TemporalQuery* DateTimeFormatter::parsedExcessDays() {
	$init(DateTimeFormatter);
	return DateTimeFormatter::PARSED_EXCESS_DAYS;
}

$TemporalQuery* DateTimeFormatter::parsedLeapSecond() {
	$init(DateTimeFormatter);
	return DateTimeFormatter::PARSED_LEAP_SECOND;
}

void DateTimeFormatter::init$($DateTimeFormatterBuilder$CompositePrinterParser* printerParser, $Locale* locale, $DecimalStyle* decimalStyle, $ResolverStyle* resolverStyle, $Set* resolverFields, $Chronology* chrono, $ZoneId* zone) {
	$set(this, printerParser, $cast($DateTimeFormatterBuilder$CompositePrinterParser, $Objects::requireNonNull($of(printerParser), "printerParser"_s)));
	$set(this, resolverFields, resolverFields);
	$set(this, locale, $cast($Locale, $Objects::requireNonNull($of(locale), "locale"_s)));
	$set(this, decimalStyle, $cast($DecimalStyle, $Objects::requireNonNull($of(decimalStyle), "decimalStyle"_s)));
	$set(this, resolverStyle, $cast($ResolverStyle, $Objects::requireNonNull($of(resolverStyle), "resolverStyle"_s)));
	$set(this, chrono, chrono);
	$set(this, zone, zone);
}

$Locale* DateTimeFormatter::getLocale() {
	return this->locale;
}

DateTimeFormatter* DateTimeFormatter::withLocale($Locale* locale) {
	if ($nc(this->locale)->equals(locale)) {
		return this;
	}
	return $new(DateTimeFormatter, this->printerParser, locale, this->decimalStyle, this->resolverStyle, this->resolverFields, this->chrono, this->zone);
}

DateTimeFormatter* DateTimeFormatter::localizedBy($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($String, tzType, $nc(locale)->getUnicodeLocaleType("tz"_s));
	$var($ZoneId, z, tzType != nullptr ? $cast($ZoneId, $nc($($nc($($TimeZoneNameUtility::convertLDMLShortID(tzType)))->map(static_cast<$Function*>($$new(DateTimeFormatter$$Lambda$of$2)))))->orElse(this->zone)) : this->zone);
	$var($Chronology, c, $Chronology::ofLocale(locale));
	$var($DecimalStyle, ds, $DecimalStyle::of(locale));
	bool var$2 = $nc(this->locale)->equals(locale);
	bool var$1 = var$2 && $nc(c)->equals(this->chrono);
	bool var$0 = var$1 && $nc(ds)->equals(this->decimalStyle);
	if (var$0 && $Objects::equals(z, this->zone)) {
		return this;
	} else {
		return $new(DateTimeFormatter, this->printerParser, locale, ds, this->resolverStyle, this->resolverFields, c, z);
	}
}

$DecimalStyle* DateTimeFormatter::getDecimalStyle() {
	return this->decimalStyle;
}

DateTimeFormatter* DateTimeFormatter::withDecimalStyle($DecimalStyle* decimalStyle) {
	if ($nc(this->decimalStyle)->equals(decimalStyle)) {
		return this;
	}
	return $new(DateTimeFormatter, this->printerParser, this->locale, decimalStyle, this->resolverStyle, this->resolverFields, this->chrono, this->zone);
}

$Chronology* DateTimeFormatter::getChronology() {
	return this->chrono;
}

DateTimeFormatter* DateTimeFormatter::withChronology($Chronology* chrono) {
	if ($Objects::equals(this->chrono, chrono)) {
		return this;
	}
	return $new(DateTimeFormatter, this->printerParser, this->locale, this->decimalStyle, this->resolverStyle, this->resolverFields, chrono, this->zone);
}

$ZoneId* DateTimeFormatter::getZone() {
	return this->zone;
}

DateTimeFormatter* DateTimeFormatter::withZone($ZoneId* zone) {
	if ($Objects::equals(this->zone, zone)) {
		return this;
	}
	return $new(DateTimeFormatter, this->printerParser, this->locale, this->decimalStyle, this->resolverStyle, this->resolverFields, this->chrono, zone);
}

$ResolverStyle* DateTimeFormatter::getResolverStyle() {
	return this->resolverStyle;
}

DateTimeFormatter* DateTimeFormatter::withResolverStyle($ResolverStyle* resolverStyle) {
	$Objects::requireNonNull($of(resolverStyle), "resolverStyle"_s);
	if ($Objects::equals(this->resolverStyle, resolverStyle)) {
		return this;
	}
	return $new(DateTimeFormatter, this->printerParser, this->locale, this->decimalStyle, resolverStyle, this->resolverFields, this->chrono, this->zone);
}

$Set* DateTimeFormatter::getResolverFields() {
	return this->resolverFields;
}

DateTimeFormatter* DateTimeFormatter::withResolverFields($TemporalFieldArray* resolverFields) {
	$useLocalCurrentObjectStackCache();
	$var($Set, fields, nullptr);
	if (resolverFields != nullptr) {
		$assign(fields, $Collections::unmodifiableSet($$new($HashSet, $(static_cast<$Collection*>($Arrays::asList(resolverFields))))));
	}
	if ($Objects::equals(this->resolverFields, fields)) {
		return this;
	}
	return $new(DateTimeFormatter, this->printerParser, this->locale, this->decimalStyle, this->resolverStyle, fields, this->chrono, this->zone);
}

DateTimeFormatter* DateTimeFormatter::withResolverFields($Set* resolverFields$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Set, resolverFields, resolverFields$renamed);
	if ($Objects::equals(this->resolverFields, resolverFields)) {
		return this;
	}
	if (resolverFields != nullptr) {
		$assign(resolverFields, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(resolverFields))));
	}
	return $new(DateTimeFormatter, this->printerParser, this->locale, this->decimalStyle, this->resolverStyle, resolverFields, this->chrono, this->zone);
}

$String* DateTimeFormatter::format($TemporalAccessor* temporal) {
	$var($StringBuilder, buf, $new($StringBuilder, 32));
	formatTo(temporal, buf);
	return buf->toString();
}

void DateTimeFormatter::formatTo($TemporalAccessor* temporal, $Appendable* appendable) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	$Objects::requireNonNull($of(appendable), "appendable"_s);
	try {
		$var($DateTimePrintContext, context, $new($DateTimePrintContext, temporal, this));
		if ($instanceOf($StringBuilder, appendable)) {
			$nc(this->printerParser)->format(context, $cast($StringBuilder, appendable));
		} else {
			$var($StringBuilder, buf, $new($StringBuilder, 32));
			$nc(this->printerParser)->format(context, buf);
			$nc(appendable)->append(static_cast<$CharSequence*>(buf));
		}
	} catch ($IOException& ex) {
		$throwNew($DateTimeException, $(ex->getMessage()), ex);
	}
}

$TemporalAccessor* DateTimeFormatter::parse($CharSequence* text) {
	$Objects::requireNonNull($of(text), "text"_s);
	try {
		return parseResolved0(text, nullptr);
	} catch ($DateTimeParseException& ex) {
		$throw(ex);
	} catch ($RuntimeException& ex) {
		$throw($(createError(text, ex)));
	}
	$shouldNotReachHere();
}

$TemporalAccessor* DateTimeFormatter::parse($CharSequence* text, $ParsePosition* position) {
	$Objects::requireNonNull($of(text), "text"_s);
	$Objects::requireNonNull($of(position), "position"_s);
	try {
		return parseResolved0(text, position);
	} catch ($DateTimeParseException& ex) {
		$throw(ex);
	} catch ($IndexOutOfBoundsException& ex) {
		$throw(ex);
	} catch ($RuntimeException& ex) {
		$throw($(createError(text, ex)));
	}
	$shouldNotReachHere();
}

$Object* DateTimeFormatter::parse($CharSequence* text, $TemporalQuery* query) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(text), "text"_s);
	$Objects::requireNonNull($of(query), "query"_s);
	try {
		return $of($nc($(parseResolved0(text, nullptr)))->query(query));
	} catch ($DateTimeParseException& ex) {
		$throw(ex);
	} catch ($RuntimeException& ex) {
		$throw($(createError(text, ex)));
	}
	$shouldNotReachHere();
}

$TemporalAccessor* DateTimeFormatter::parseBest($CharSequence* text, $TemporalQueryArray* queries) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(text), "text"_s);
	$Objects::requireNonNull($of(queries), "queries"_s);
	if ($nc(queries)->length < 2) {
		$throwNew($IllegalArgumentException, "At least two queries must be specified"_s);
	}
	try {
		$var($TemporalAccessor, resolved, parseResolved0(text, nullptr));
		{
			$var($TemporalQueryArray, arr$, queries);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($TemporalQuery, query, arr$->get(i$));
				{
					try {
						return $cast($TemporalAccessor, $nc(resolved)->query(query));
					} catch ($RuntimeException& ex) {
					}
				}
			}
		}
		$throwNew($DateTimeException, "Unable to convert parsed text using any of the specified queries"_s);
	} catch ($DateTimeParseException& ex) {
		$throw(ex);
	} catch ($RuntimeException& ex) {
		$throw($(createError(text, ex)));
	}
	$shouldNotReachHere();
}

$DateTimeParseException* DateTimeFormatter::createError($CharSequence* text, $RuntimeException* ex) {
	$useLocalCurrentObjectStackCache();
	$var($String, abbr, nullptr);
	if ($nc(text)->length() > 64) {
		$assign(abbr, $str({$($nc($(text->subSequence(0, 64)))->toString()), "..."_s}));
	} else {
		$assign(abbr, text->toString());
	}
	return $new($DateTimeParseException, $$str({"Text \'"_s, abbr, "\' could not be parsed: "_s, $($nc(ex)->getMessage())}), text, 0, ex);
}

$TemporalAccessor* DateTimeFormatter::parseResolved0($CharSequence* text, $ParsePosition* position) {
	$useLocalCurrentObjectStackCache();
	$var($ParsePosition, pos, position != nullptr ? position : $new($ParsePosition, 0));
	$var($DateTimeParseContext, context, parseUnresolved0(text, pos));
	bool var$0 = context == nullptr || $nc(pos)->getErrorIndex() >= 0;
	if (!var$0) {
		bool var$1 = position == nullptr;
		if (var$1) {
			int32_t var$2 = $nc(pos)->getIndex();
			var$1 = var$2 < $nc(text)->length();
		}
		var$0 = (var$1);
	}
	if (var$0) {
		$var($String, abbr, nullptr);
		if (text->length() > 64) {
			$assign(abbr, $str({$($nc($(text->subSequence(0, 64)))->toString()), "..."_s}));
		} else {
			$assign(abbr, text->toString());
		}
		if (pos->getErrorIndex() >= 0) {
			$var($String, var$3, $str({"Text \'"_s, abbr, "\' could not be parsed at index "_s, $$str(pos->getErrorIndex())}));
			$var($CharSequence, var$4, text);
			$throwNew($DateTimeParseException, var$3, var$4, pos->getErrorIndex());
		} else {
			$var($String, var$5, $str({"Text \'"_s, abbr, "\' could not be parsed, unparsed text found at index "_s, $$str(pos->getIndex())}));
			$var($CharSequence, var$6, text);
			$throwNew($DateTimeParseException, var$5, var$6, pos->getIndex());
		}
	}
	return $nc(context)->toResolved(this->resolverStyle, this->resolverFields);
}

$TemporalAccessor* DateTimeFormatter::parseUnresolved($CharSequence* text, $ParsePosition* position) {
	$var($DateTimeParseContext, context, parseUnresolved0(text, position));
	if (context == nullptr) {
		return nullptr;
	}
	return $nc(context)->toUnresolved();
}

$DateTimeParseContext* DateTimeFormatter::parseUnresolved0($CharSequence* text, $ParsePosition* position) {
	$Objects::requireNonNull($of(text), "text"_s);
	$Objects::requireNonNull($of(position), "position"_s);
	$var($DateTimeParseContext, context, $new($DateTimeParseContext, this));
	int32_t pos = $nc(position)->getIndex();
	pos = $nc(this->printerParser)->parse(context, text, pos);
	if (pos < 0) {
		position->setErrorIndex(~pos);
		return nullptr;
	}
	position->setIndex(pos);
	return context;
}

$DateTimeFormatterBuilder$CompositePrinterParser* DateTimeFormatter::toPrinterParser(bool optional) {
	return $nc(this->printerParser)->withOptional(optional);
}

$Format* DateTimeFormatter::toFormat() {
	return $new($DateTimeFormatter$ClassicFormat, this, nullptr);
}

$Format* DateTimeFormatter::toFormat($TemporalQuery* parseQuery) {
	$Objects::requireNonNull($of(parseQuery), "parseQuery"_s);
	return $new($DateTimeFormatter$ClassicFormat, this, parseQuery);
}

$String* DateTimeFormatter::toString() {
	$var($String, pattern, $nc(this->printerParser)->toString());
	$assign(pattern, $nc(pattern)->startsWith("["_s) ? pattern : $nc(pattern)->substring(1, pattern->length() - 1));
	return pattern;
}

$Boolean* DateTimeFormatter::lambda$static$1($TemporalAccessor* t) {
	$init(DateTimeFormatter);
	if ($instanceOf($Parsed, t)) {
		return $Boolean::valueOf($nc(($cast($Parsed, t)))->leapSecond);
	} else {
		$init($Boolean);
		return $Boolean::FALSE;
	}
}

$Period* DateTimeFormatter::lambda$static$0($TemporalAccessor* t) {
	$init(DateTimeFormatter);
	if ($instanceOf($Parsed, t)) {
		return $nc(($cast($Parsed, t)))->excessDays;
	} else {
		$init($Period);
		return $Period::ZERO;
	}
}

void clinit$DateTimeFormatter($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$init($ChronoField);
		$init($SignStyle);
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_LOCAL_DATE, $nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->appendValue($ChronoField::YEAR, 4, 10, $SignStyle::EXCEEDS_PAD)))->appendLiteral(u'-')))->appendValue($ChronoField::MONTH_OF_YEAR, 2)))->appendLiteral(u'-')))->appendValue($ChronoField::DAY_OF_MONTH, 2)))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_OFFSET_DATE, $nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->append(DateTimeFormatter::ISO_LOCAL_DATE)))->appendOffsetId()))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_DATE, $nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->append(DateTimeFormatter::ISO_LOCAL_DATE)))->optionalStart()))->appendOffsetId()))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ChronoField);
		$init($ResolverStyle);
		$assignStatic(DateTimeFormatter::ISO_LOCAL_TIME, $nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->appendValue($ChronoField::HOUR_OF_DAY, 2)))->appendLiteral(u':')))->appendValue($ChronoField::MINUTE_OF_HOUR, 2)))->optionalStart()))->appendLiteral(u':')))->appendValue($ChronoField::SECOND_OF_MINUTE, 2)))->optionalStart()))->appendFraction($ChronoField::NANO_OF_SECOND, 0, 9, true)))->toFormatter($ResolverStyle::STRICT, nullptr));
	}
	{
		$init($ResolverStyle);
		$assignStatic(DateTimeFormatter::ISO_OFFSET_TIME, $nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->append(DateTimeFormatter::ISO_LOCAL_TIME)))->appendOffsetId()))->toFormatter($ResolverStyle::STRICT, nullptr));
	}
	{
		$init($ResolverStyle);
		$assignStatic(DateTimeFormatter::ISO_TIME, $nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->append(DateTimeFormatter::ISO_LOCAL_TIME)))->optionalStart()))->appendOffsetId()))->toFormatter($ResolverStyle::STRICT, nullptr));
	}
	{
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_LOCAL_DATE_TIME, $nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->append(DateTimeFormatter::ISO_LOCAL_DATE)))->appendLiteral(u'T')))->append(DateTimeFormatter::ISO_LOCAL_TIME)))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_OFFSET_DATE_TIME, $nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->append(DateTimeFormatter::ISO_LOCAL_DATE_TIME)))->parseLenient()))->appendOffsetId()))->parseStrict()))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_ZONED_DATE_TIME, $nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->append(DateTimeFormatter::ISO_OFFSET_DATE_TIME)))->optionalStart()))->appendLiteral(u'[')))->parseCaseSensitive()))->appendZoneRegionId()))->appendLiteral(u']')))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_DATE_TIME, $nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->append(DateTimeFormatter::ISO_LOCAL_DATE_TIME)))->optionalStart()))->appendOffsetId()))->optionalStart()))->appendLiteral(u'[')))->parseCaseSensitive()))->appendZoneRegionId()))->appendLiteral(u']')))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ChronoField);
		$init($SignStyle);
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_ORDINAL_DATE, $nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->appendValue($ChronoField::YEAR, 4, 10, $SignStyle::EXCEEDS_PAD)))->appendLiteral(u'-')))->appendValue($ChronoField::DAY_OF_YEAR, 3)))->optionalStart()))->appendOffsetId()))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($IsoFields);
		$init($SignStyle);
		$init($ChronoField);
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::ISO_WEEK_DATE, $nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->appendValue($IsoFields::WEEK_BASED_YEAR, 4, 10, $SignStyle::EXCEEDS_PAD)))->appendLiteral("-W"_s)))->appendValue($IsoFields::WEEK_OF_WEEK_BASED_YEAR, 2)))->appendLiteral(u'-')))->appendValue($ChronoField::DAY_OF_WEEK, 1)))->optionalStart()))->appendOffsetId()))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$init($ResolverStyle);
		$assignStatic(DateTimeFormatter::ISO_INSTANT, $nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->appendInstant()))->toFormatter($ResolverStyle::STRICT, nullptr));
	}
	{
		$init($ChronoField);
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::BASIC_ISO_DATE, $nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->appendValue($ChronoField::YEAR, 4)))->appendValue($ChronoField::MONTH_OF_YEAR, 2)))->appendValue($ChronoField::DAY_OF_MONTH, 2)))->optionalStart()))->parseLenient()))->appendOffset("+HHMMss"_s, "Z"_s)))->parseStrict()))->toFormatter($ResolverStyle::STRICT, $IsoChronology::INSTANCE));
	}
	{
		$var($Map, dow, $new($HashMap));
		dow->put($($Long::valueOf((int64_t)1)), "Mon"_s);
		dow->put($($Long::valueOf((int64_t)2)), "Tue"_s);
		dow->put($($Long::valueOf((int64_t)3)), "Wed"_s);
		dow->put($($Long::valueOf((int64_t)4)), "Thu"_s);
		dow->put($($Long::valueOf((int64_t)5)), "Fri"_s);
		dow->put($($Long::valueOf((int64_t)6)), "Sat"_s);
		dow->put($($Long::valueOf((int64_t)7)), "Sun"_s);
		$var($Map, moy, $new($HashMap));
		moy->put($($Long::valueOf((int64_t)1)), "Jan"_s);
		moy->put($($Long::valueOf((int64_t)2)), "Feb"_s);
		moy->put($($Long::valueOf((int64_t)3)), "Mar"_s);
		moy->put($($Long::valueOf((int64_t)4)), "Apr"_s);
		moy->put($($Long::valueOf((int64_t)5)), "May"_s);
		moy->put($($Long::valueOf((int64_t)6)), "Jun"_s);
		moy->put($($Long::valueOf((int64_t)7)), "Jul"_s);
		moy->put($($Long::valueOf((int64_t)8)), "Aug"_s);
		moy->put($($Long::valueOf((int64_t)9)), "Sep"_s);
		moy->put($($Long::valueOf((int64_t)10)), "Oct"_s);
		moy->put($($Long::valueOf((int64_t)11)), "Nov"_s);
		moy->put($($Long::valueOf((int64_t)12)), "Dec"_s);
		$init($ChronoField);
		$init($SignStyle);
		$init($ResolverStyle);
		$init($IsoChronology);
		$assignStatic(DateTimeFormatter::RFC_1123_DATE_TIME, $nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($nc($($$new($DateTimeFormatterBuilder)->parseCaseInsensitive()))->parseLenient()))->optionalStart()))->appendText(static_cast<$TemporalField*>($ChronoField::DAY_OF_WEEK), dow)))->appendLiteral(", "_s)))->optionalEnd()))->appendValue($ChronoField::DAY_OF_MONTH, 1, 2, $SignStyle::NOT_NEGATIVE)))->appendLiteral(u' ')))->appendText(static_cast<$TemporalField*>($ChronoField::MONTH_OF_YEAR), moy)))->appendLiteral(u' ')))->appendValue($ChronoField::YEAR, 4)))->appendLiteral(u' ')))->appendValue($ChronoField::HOUR_OF_DAY, 2)))->appendLiteral(u':')))->appendValue($ChronoField::MINUTE_OF_HOUR, 2)))->optionalStart()))->appendLiteral(u':')))->appendValue($ChronoField::SECOND_OF_MINUTE, 2)))->optionalEnd()))->appendLiteral(u' ')))->appendOffset("+HHMM"_s, "GMT"_s)))->toFormatter($ResolverStyle::SMART, $IsoChronology::INSTANCE));
	}
	$assignStatic(DateTimeFormatter::PARSED_EXCESS_DAYS, static_cast<$TemporalQuery*>($new(DateTimeFormatter$$Lambda$lambda$static$0)));
	$assignStatic(DateTimeFormatter::PARSED_LEAP_SECOND, static_cast<$TemporalQuery*>($new(DateTimeFormatter$$Lambda$lambda$static$1$1)));
}

DateTimeFormatter::DateTimeFormatter() {
}

$Class* DateTimeFormatter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DateTimeFormatter$$Lambda$lambda$static$0::classInfo$.name)) {
			return DateTimeFormatter$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(DateTimeFormatter$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return DateTimeFormatter$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(DateTimeFormatter$$Lambda$of$2::classInfo$.name)) {
			return DateTimeFormatter$$Lambda$of$2::load$(name, initialize);
		}
	}
	$loadClass(DateTimeFormatter, name, initialize, &_DateTimeFormatter_ClassInfo_, clinit$DateTimeFormatter, allocate$DateTimeFormatter);
	return class$;
}

$Class* DateTimeFormatter::class$ = nullptr;

		} // format
	} // time
} // java