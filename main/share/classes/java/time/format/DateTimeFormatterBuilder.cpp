#include <java/time/format/DateTimeFormatterBuilder.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/LocalDate.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder$1.h>
#include <java/time/format/DateTimeFormatterBuilder$2.h>
#include <java/time/format/DateTimeFormatterBuilder$CharLiteralPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$ChronoPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$CompositePrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$DateTimePrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$DayPeriodPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$DefaultValueParser.h>
#include <java/time/format/DateTimeFormatterBuilder$FractionPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$InstantPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$LocalizedOffsetIdPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$LocalizedPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$NumberPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$OffsetIdPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$PadPrinterParserDecorator.h>
#include <java/time/format/DateTimeFormatterBuilder$ReducedPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$SettingsParser.h>
#include <java/time/format/DateTimeFormatterBuilder$StringLiteralPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$TextPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$WeekBasedFieldPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$ZoneIdPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder$ZoneTextPrinterParser.h>
#include <java/time/format/DateTimeTextProvider$LocaleStore.h>
#include <java/time/format/DateTimeTextProvider.h>
#include <java/time/format/DecimalStyle.h>
#include <java/time/format/FormatStyle.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/format/SignStyle.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/IsoFields.h>
#include <java/time/temporal/JulianFields.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <sun/text/spi/JavaTimeDateTimePatternProvider.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <jcpp.h>

#undef ALIGNED_DAY_OF_WEEK_IN_MONTH
#undef AMPM_OF_DAY
#undef BASE_DATE
#undef CLOCK_HOUR_OF_AMPM
#undef CLOCK_HOUR_OF_DAY
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_YEAR
#undef ERA
#undef EXCEEDS_PAD
#undef FIELD_MAP
#undef FORMAT
#undef FULL
#undef FULL_STANDALONE
#undef HOUR_OF_AMPM
#undef HOUR_OF_DAY
#undef INSENSITIVE
#undef INSTANCE_ID_Z
#undef LENIENT
#undef MILLI_OF_DAY
#undef MINUTE_OF_HOUR
#undef MODIFIED_JULIAN_DAY
#undef MONTH_OF_YEAR
#undef NANO_OF_DAY
#undef NANO_OF_SECOND
#undef NARROW
#undef NARROW_STANDALONE
#undef NORMAL
#undef NOT_NEGATIVE
#undef PATTERNS
#undef QUARTER_OF_YEAR
#undef QUERY_REGION_ONLY
#undef SECOND_OF_MINUTE
#undef SENSITIVE
#undef SHORT
#undef SHORT_STANDALONE
#undef SMART
#undef STANDARD
#undef STRICT
#undef YEAR
#undef YEAR_OF_ERA

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $Chronology = ::java::time::chrono::Chronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder$1 = ::java::time::format::DateTimeFormatterBuilder$1;
using $DateTimeFormatterBuilder$2 = ::java::time::format::DateTimeFormatterBuilder$2;
using $DateTimeFormatterBuilder$CharLiteralPrinterParser = ::java::time::format::DateTimeFormatterBuilder$CharLiteralPrinterParser;
using $DateTimeFormatterBuilder$ChronoPrinterParser = ::java::time::format::DateTimeFormatterBuilder$ChronoPrinterParser;
using $DateTimeFormatterBuilder$CompositePrinterParser = ::java::time::format::DateTimeFormatterBuilder$CompositePrinterParser;
using $DateTimeFormatterBuilder$DateTimePrinterParser = ::java::time::format::DateTimeFormatterBuilder$DateTimePrinterParser;
using $DateTimeFormatterBuilder$DayPeriodPrinterParser = ::java::time::format::DateTimeFormatterBuilder$DayPeriodPrinterParser;
using $DateTimeFormatterBuilder$DefaultValueParser = ::java::time::format::DateTimeFormatterBuilder$DefaultValueParser;
using $DateTimeFormatterBuilder$FractionPrinterParser = ::java::time::format::DateTimeFormatterBuilder$FractionPrinterParser;
using $DateTimeFormatterBuilder$InstantPrinterParser = ::java::time::format::DateTimeFormatterBuilder$InstantPrinterParser;
using $DateTimeFormatterBuilder$LocalizedOffsetIdPrinterParser = ::java::time::format::DateTimeFormatterBuilder$LocalizedOffsetIdPrinterParser;
using $DateTimeFormatterBuilder$LocalizedPrinterParser = ::java::time::format::DateTimeFormatterBuilder$LocalizedPrinterParser;
using $DateTimeFormatterBuilder$NumberPrinterParser = ::java::time::format::DateTimeFormatterBuilder$NumberPrinterParser;
using $DateTimeFormatterBuilder$OffsetIdPrinterParser = ::java::time::format::DateTimeFormatterBuilder$OffsetIdPrinterParser;
using $DateTimeFormatterBuilder$PadPrinterParserDecorator = ::java::time::format::DateTimeFormatterBuilder$PadPrinterParserDecorator;
using $DateTimeFormatterBuilder$ReducedPrinterParser = ::java::time::format::DateTimeFormatterBuilder$ReducedPrinterParser;
using $DateTimeFormatterBuilder$SettingsParser = ::java::time::format::DateTimeFormatterBuilder$SettingsParser;
using $DateTimeFormatterBuilder$StringLiteralPrinterParser = ::java::time::format::DateTimeFormatterBuilder$StringLiteralPrinterParser;
using $DateTimeFormatterBuilder$TextPrinterParser = ::java::time::format::DateTimeFormatterBuilder$TextPrinterParser;
using $DateTimeFormatterBuilder$WeekBasedFieldPrinterParser = ::java::time::format::DateTimeFormatterBuilder$WeekBasedFieldPrinterParser;
using $DateTimeFormatterBuilder$ZoneIdPrinterParser = ::java::time::format::DateTimeFormatterBuilder$ZoneIdPrinterParser;
using $DateTimeFormatterBuilder$ZoneTextPrinterParser = ::java::time::format::DateTimeFormatterBuilder$ZoneTextPrinterParser;
using $DateTimeTextProvider = ::java::time::format::DateTimeTextProvider;
using $DateTimeTextProvider$LocaleStore = ::java::time::format::DateTimeTextProvider$LocaleStore;
using $DecimalStyle = ::java::time::format::DecimalStyle;
using $FormatStyle = ::java::time::format::FormatStyle;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $SignStyle = ::java::time::format::SignStyle;
using $TextStyle = ::java::time::format::TextStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $IsoFields = ::java::time::temporal::IsoFields;
using $JulianFields = ::java::time::temporal::JulianFields;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $JavaTimeDateTimePatternProvider = ::sun::text::spi::JavaTimeDateTimePatternProvider;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;

namespace java {
	namespace time {
		namespace format {

class DateTimeFormatterBuilder$$Lambda$lambda$static$0 : public $TemporalQuery {
	$class(DateTimeFormatterBuilder$$Lambda$lambda$static$0, $NO_CLASS_INIT, $TemporalQuery)
public:
	void init$() {
	}
	virtual $Object* queryFrom($TemporalAccessor* temporal) override {
		 return $of(DateTimeFormatterBuilder::lambda$static$0(temporal));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatterBuilder$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DateTimeFormatterBuilder$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder$$Lambda$lambda$static$0, init$, void)},
	{"queryFrom", "(Ljava/time/temporal/TemporalAccessor;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$$Lambda$lambda$static$0, queryFrom, $Object*, $TemporalAccessor*)},
	{}
};
$ClassInfo DateTimeFormatterBuilder$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatterBuilder$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.time.temporal.TemporalQuery",
	nullptr,
	methodInfos
};
$Class* DateTimeFormatterBuilder$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatterBuilder$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatterBuilder$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _DateTimeFormatterBuilder_FieldInfo_[] = {
	{"QUERY_REGION_ONLY", "Ljava/time/temporal/TemporalQuery;", "Ljava/time/temporal/TemporalQuery<Ljava/time/ZoneId;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeFormatterBuilder, QUERY_REGION_ONLY)},
	{"active", "Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PRIVATE, $field(DateTimeFormatterBuilder, active)},
	{"parent", "Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder, parent)},
	{"printerParsers", "Ljava/util/List;", "Ljava/util/List<Ljava/time/format/DateTimeFormatterBuilder$DateTimePrinterParser;>;", $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder, printerParsers)},
	{"optional", "Z", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder, optional)},
	{"padNextWidth", "I", nullptr, $PRIVATE, $field(DateTimeFormatterBuilder, padNextWidth)},
	{"padNextChar", "C", nullptr, $PRIVATE, $field(DateTimeFormatterBuilder, padNextChar)},
	{"valueParserIndex", "I", nullptr, $PRIVATE, $field(DateTimeFormatterBuilder, valueParserIndex)},
	{"FIELD_MAP", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Character;Ljava/time/temporal/TemporalField;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeFormatterBuilder, FIELD_MAP)},
	{}
};

$MethodInfo _DateTimeFormatterBuilder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, init$, void)},
	{"<init>", "(Ljava/time/format/DateTimeFormatterBuilder;Z)V", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder, init$, void, DateTimeFormatterBuilder*, bool)},
	{"append", "(Ljava/time/format/DateTimeFormatter;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, append, DateTimeFormatterBuilder*, $DateTimeFormatter*)},
	{"appendChronologyId", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendChronologyId, DateTimeFormatterBuilder*)},
	{"appendChronologyText", "(Ljava/time/format/TextStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendChronologyText, DateTimeFormatterBuilder*, $TextStyle*)},
	{"appendDayPeriodText", "(Ljava/time/format/TextStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendDayPeriodText, DateTimeFormatterBuilder*, $TextStyle*)},
	{"appendFraction", "(Ljava/time/temporal/TemporalField;IIZ)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendFraction, DateTimeFormatterBuilder*, $TemporalField*, int32_t, int32_t, bool)},
	{"appendGenericZoneText", "(Ljava/time/format/TextStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendGenericZoneText, DateTimeFormatterBuilder*, $TextStyle*)},
	{"appendGenericZoneText", "(Ljava/time/format/TextStyle;Ljava/util/Set;)Ljava/time/format/DateTimeFormatterBuilder;", "(Ljava/time/format/TextStyle;Ljava/util/Set<Ljava/time/ZoneId;>;)Ljava/time/format/DateTimeFormatterBuilder;", $PUBLIC, $method(DateTimeFormatterBuilder, appendGenericZoneText, DateTimeFormatterBuilder*, $TextStyle*, $Set*)},
	{"appendInstant", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendInstant, DateTimeFormatterBuilder*)},
	{"appendInstant", "(I)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendInstant, DateTimeFormatterBuilder*, int32_t)},
	{"appendInternal", "(Ljava/time/format/DateTimeFormatterBuilder$DateTimePrinterParser;)I", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder, appendInternal, int32_t, $DateTimeFormatterBuilder$DateTimePrinterParser*)},
	{"appendLiteral", "(C)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendLiteral, DateTimeFormatterBuilder*, char16_t)},
	{"appendLiteral", "(Ljava/lang/String;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendLiteral, DateTimeFormatterBuilder*, $String*)},
	{"appendLocalized", "(Ljava/time/format/FormatStyle;Ljava/time/format/FormatStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendLocalized, DateTimeFormatterBuilder*, $FormatStyle*, $FormatStyle*)},
	{"appendLocalizedOffset", "(Ljava/time/format/TextStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendLocalizedOffset, DateTimeFormatterBuilder*, $TextStyle*)},
	{"appendOffset", "(Ljava/lang/String;Ljava/lang/String;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendOffset, DateTimeFormatterBuilder*, $String*, $String*)},
	{"appendOffsetId", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendOffsetId, DateTimeFormatterBuilder*)},
	{"appendOptional", "(Ljava/time/format/DateTimeFormatter;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendOptional, DateTimeFormatterBuilder*, $DateTimeFormatter*)},
	{"appendPattern", "(Ljava/lang/String;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendPattern, DateTimeFormatterBuilder*, $String*)},
	{"appendText", "(Ljava/time/temporal/TemporalField;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendText, DateTimeFormatterBuilder*, $TemporalField*)},
	{"appendText", "(Ljava/time/temporal/TemporalField;Ljava/time/format/TextStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendText, DateTimeFormatterBuilder*, $TemporalField*, $TextStyle*)},
	{"appendText", "(Ljava/time/temporal/TemporalField;Ljava/util/Map;)Ljava/time/format/DateTimeFormatterBuilder;", "(Ljava/time/temporal/TemporalField;Ljava/util/Map<Ljava/lang/Long;Ljava/lang/String;>;)Ljava/time/format/DateTimeFormatterBuilder;", $PUBLIC, $method(DateTimeFormatterBuilder, appendText, DateTimeFormatterBuilder*, $TemporalField*, $Map*)},
	{"appendValue", "(Ljava/time/temporal/TemporalField;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendValue, DateTimeFormatterBuilder*, $TemporalField*)},
	{"appendValue", "(Ljava/time/temporal/TemporalField;I)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendValue, DateTimeFormatterBuilder*, $TemporalField*, int32_t)},
	{"appendValue", "(Ljava/time/temporal/TemporalField;IILjava/time/format/SignStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendValue, DateTimeFormatterBuilder*, $TemporalField*, int32_t, int32_t, $SignStyle*)},
	{"appendValue", "(Ljava/time/format/DateTimeFormatterBuilder$NumberPrinterParser;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder, appendValue, DateTimeFormatterBuilder*, $DateTimeFormatterBuilder$NumberPrinterParser*)},
	{"appendValueReduced", "(Ljava/time/temporal/TemporalField;III)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendValueReduced, DateTimeFormatterBuilder*, $TemporalField*, int32_t, int32_t, int32_t)},
	{"appendValueReduced", "(Ljava/time/temporal/TemporalField;IILjava/time/chrono/ChronoLocalDate;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendValueReduced, DateTimeFormatterBuilder*, $TemporalField*, int32_t, int32_t, $ChronoLocalDate*)},
	{"appendZoneId", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendZoneId, DateTimeFormatterBuilder*)},
	{"appendZoneOrOffsetId", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendZoneOrOffsetId, DateTimeFormatterBuilder*)},
	{"appendZoneRegionId", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendZoneRegionId, DateTimeFormatterBuilder*)},
	{"appendZoneText", "(Ljava/time/format/TextStyle;)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, appendZoneText, DateTimeFormatterBuilder*, $TextStyle*)},
	{"appendZoneText", "(Ljava/time/format/TextStyle;Ljava/util/Set;)Ljava/time/format/DateTimeFormatterBuilder;", "(Ljava/time/format/TextStyle;Ljava/util/Set<Ljava/time/ZoneId;>;)Ljava/time/format/DateTimeFormatterBuilder;", $PUBLIC, $method(DateTimeFormatterBuilder, appendZoneText, DateTimeFormatterBuilder*, $TextStyle*, $Set*)},
	{"convertStyle", "(Ljava/time/format/FormatStyle;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(DateTimeFormatterBuilder, convertStyle, int32_t, $FormatStyle*)},
	{"getLocalizedDateTimePattern", "(Ljava/time/format/FormatStyle;Ljava/time/format/FormatStyle;Ljava/time/chrono/Chronology;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateTimeFormatterBuilder, getLocalizedDateTimePattern, $String*, $FormatStyle*, $FormatStyle*, $Chronology*, $Locale*)},
	{"lambda$static$0", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/ZoneId;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DateTimeFormatterBuilder, lambda$static$0, $ZoneId*, $TemporalAccessor*)},
	{"optionalEnd", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, optionalEnd, DateTimeFormatterBuilder*)},
	{"optionalStart", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, optionalStart, DateTimeFormatterBuilder*)},
	{"padNext", "(I)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, padNext, DateTimeFormatterBuilder*, int32_t)},
	{"padNext", "(IC)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, padNext, DateTimeFormatterBuilder*, int32_t, char16_t)},
	{"parseCaseInsensitive", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, parseCaseInsensitive, DateTimeFormatterBuilder*)},
	{"parseCaseSensitive", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, parseCaseSensitive, DateTimeFormatterBuilder*)},
	{"parseDefaulting", "(Ljava/time/temporal/TemporalField;J)Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, parseDefaulting, DateTimeFormatterBuilder*, $TemporalField*, int64_t)},
	{"parseField", "(CILjava/time/temporal/TemporalField;)V", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder, parseField, void, char16_t, int32_t, $TemporalField*)},
	{"parseLenient", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, parseLenient, DateTimeFormatterBuilder*)},
	{"parsePattern", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder, parsePattern, void, $String*)},
	{"parseStrict", "()Ljava/time/format/DateTimeFormatterBuilder;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, parseStrict, DateTimeFormatterBuilder*)},
	{"toFormatter", "()Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, toFormatter, $DateTimeFormatter*)},
	{"toFormatter", "(Ljava/util/Locale;)Ljava/time/format/DateTimeFormatter;", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder, toFormatter, $DateTimeFormatter*, $Locale*)},
	{"toFormatter", "(Ljava/time/format/ResolverStyle;Ljava/time/chrono/Chronology;)Ljava/time/format/DateTimeFormatter;", nullptr, 0, $method(DateTimeFormatterBuilder, toFormatter, $DateTimeFormatter*, $ResolverStyle*, $Chronology*)},
	{"toFormatter", "(Ljava/util/Locale;Ljava/time/format/ResolverStyle;Ljava/time/chrono/Chronology;)Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder, toFormatter, $DateTimeFormatter*, $Locale*, $ResolverStyle*, $Chronology*)},
	{}
};

$InnerClassInfo _DateTimeFormatterBuilder_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeFormatterBuilder$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.time.format.DateTimeFormatterBuilder$DayPeriod", "java.time.format.DateTimeFormatterBuilder", "DayPeriod", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$DayPeriodPrinterParser", "java.time.format.DateTimeFormatterBuilder", "DayPeriodPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$WeekBasedFieldPrinterParser", "java.time.format.DateTimeFormatterBuilder", "WeekBasedFieldPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$LocalizedPrinterParser", "java.time.format.DateTimeFormatterBuilder", "LocalizedPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$ChronoPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ChronoPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$PrefixTree", "java.time.format.DateTimeFormatterBuilder", "PrefixTree", $STATIC},
	{"java.time.format.DateTimeFormatterBuilder$ZoneIdPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ZoneIdPrinterParser", $STATIC},
	{"java.time.format.DateTimeFormatterBuilder$ZoneTextPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ZoneTextPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$LocalizedOffsetIdPrinterParser", "java.time.format.DateTimeFormatterBuilder", "LocalizedOffsetIdPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$OffsetIdPrinterParser", "java.time.format.DateTimeFormatterBuilder", "OffsetIdPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$InstantPrinterParser", "java.time.format.DateTimeFormatterBuilder", "InstantPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$TextPrinterParser", "java.time.format.DateTimeFormatterBuilder", "TextPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$FractionPrinterParser", "java.time.format.DateTimeFormatterBuilder", "FractionPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$ReducedPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ReducedPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$NumberPrinterParser", "java.time.format.DateTimeFormatterBuilder", "NumberPrinterParser", $STATIC},
	{"java.time.format.DateTimeFormatterBuilder$StringLiteralPrinterParser", "java.time.format.DateTimeFormatterBuilder", "StringLiteralPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$CharLiteralPrinterParser", "java.time.format.DateTimeFormatterBuilder", "CharLiteralPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$DefaultValueParser", "java.time.format.DateTimeFormatterBuilder", "DefaultValueParser", $STATIC},
	{"java.time.format.DateTimeFormatterBuilder$SettingsParser", "java.time.format.DateTimeFormatterBuilder", "SettingsParser", $STATIC | $FINAL | $ENUM},
	{"java.time.format.DateTimeFormatterBuilder$PadPrinterParserDecorator", "java.time.format.DateTimeFormatterBuilder", "PadPrinterParserDecorator", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$CompositePrinterParser", "java.time.format.DateTimeFormatterBuilder", "CompositePrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$DateTimePrinterParser", "java.time.format.DateTimeFormatterBuilder", "DateTimePrinterParser", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.time.format.DateTimeFormatterBuilder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DateTimeFormatterBuilder_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.format.DateTimeFormatterBuilder",
	"java.lang.Object",
	nullptr,
	_DateTimeFormatterBuilder_FieldInfo_,
	_DateTimeFormatterBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeFormatterBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.format.DateTimeFormatterBuilder$2,java.time.format.DateTimeFormatterBuilder$DayPeriod,java.time.format.DateTimeFormatterBuilder$DayPeriodPrinterParser,java.time.format.DateTimeFormatterBuilder$WeekBasedFieldPrinterParser,java.time.format.DateTimeFormatterBuilder$LocalizedPrinterParser,java.time.format.DateTimeFormatterBuilder$ChronoPrinterParser,java.time.format.DateTimeFormatterBuilder$PrefixTree,java.time.format.DateTimeFormatterBuilder$PrefixTree$LENIENT,java.time.format.DateTimeFormatterBuilder$PrefixTree$CI,java.time.format.DateTimeFormatterBuilder$ZoneIdPrinterParser,java.time.format.DateTimeFormatterBuilder$ZoneTextPrinterParser,java.time.format.DateTimeFormatterBuilder$LocalizedOffsetIdPrinterParser,java.time.format.DateTimeFormatterBuilder$OffsetIdPrinterParser,java.time.format.DateTimeFormatterBuilder$InstantPrinterParser,java.time.format.DateTimeFormatterBuilder$TextPrinterParser,java.time.format.DateTimeFormatterBuilder$FractionPrinterParser,java.time.format.DateTimeFormatterBuilder$ReducedPrinterParser,java.time.format.DateTimeFormatterBuilder$NumberPrinterParser,java.time.format.DateTimeFormatterBuilder$StringLiteralPrinterParser,java.time.format.DateTimeFormatterBuilder$CharLiteralPrinterParser,java.time.format.DateTimeFormatterBuilder$DefaultValueParser,java.time.format.DateTimeFormatterBuilder$SettingsParser,java.time.format.DateTimeFormatterBuilder$PadPrinterParserDecorator,java.time.format.DateTimeFormatterBuilder$CompositePrinterParser,java.time.format.DateTimeFormatterBuilder$DateTimePrinterParser,java.time.format.DateTimeFormatterBuilder$1"
};

$Object* allocate$DateTimeFormatterBuilder($Class* clazz) {
	return $of($alloc(DateTimeFormatterBuilder));
}

$TemporalQuery* DateTimeFormatterBuilder::QUERY_REGION_ONLY = nullptr;
$Map* DateTimeFormatterBuilder::FIELD_MAP = nullptr;

$String* DateTimeFormatterBuilder::getLocalizedDateTimePattern($FormatStyle* dateStyle, $FormatStyle* timeStyle, $Chronology* chrono, $Locale* locale) {
	$init(DateTimeFormatterBuilder);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(locale), "locale"_s);
	$Objects::requireNonNull($of(chrono), "chrono"_s);
	if (dateStyle == nullptr && timeStyle == nullptr) {
		$throwNew($IllegalArgumentException, "Either dateStyle or timeStyle must be non-null"_s);
	}
	$load($JavaTimeDateTimePatternProvider);
	$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($JavaTimeDateTimePatternProvider::class$, locale));
	$var($JavaTimeDateTimePatternProvider, provider, $nc(adapter)->getJavaTimeDateTimePatternProvider());
	int32_t var$0 = convertStyle(timeStyle);
	int32_t var$1 = convertStyle(dateStyle);
	$var($String, var$2, $nc(chrono)->getCalendarType());
	return $nc(provider)->getJavaTimeDateTimePattern(var$0, var$1, var$2, $($CalendarDataUtility::findRegionOverride(locale)));
}

int32_t DateTimeFormatterBuilder::convertStyle($FormatStyle* style) {
	$init(DateTimeFormatterBuilder);
	if (style == nullptr) {
		return -1;
	}
	return $nc(style)->ordinal();
}

void DateTimeFormatterBuilder::init$() {
	$set(this, active, this);
	$set(this, printerParsers, $new($ArrayList));
	this->valueParserIndex = -1;
	$set(this, parent, nullptr);
	this->optional = false;
}

void DateTimeFormatterBuilder::init$(DateTimeFormatterBuilder* parent, bool optional) {
	$set(this, active, this);
	$set(this, printerParsers, $new($ArrayList));
	this->valueParserIndex = -1;
	$set(this, parent, parent);
	this->optional = optional;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::parseCaseSensitive() {
	$init($DateTimeFormatterBuilder$SettingsParser);
	appendInternal($DateTimeFormatterBuilder$SettingsParser::SENSITIVE);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::parseCaseInsensitive() {
	$init($DateTimeFormatterBuilder$SettingsParser);
	appendInternal($DateTimeFormatterBuilder$SettingsParser::INSENSITIVE);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::parseStrict() {
	$init($DateTimeFormatterBuilder$SettingsParser);
	appendInternal($DateTimeFormatterBuilder$SettingsParser::STRICT);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::parseLenient() {
	$init($DateTimeFormatterBuilder$SettingsParser);
	appendInternal($DateTimeFormatterBuilder$SettingsParser::LENIENT);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::parseDefaulting($TemporalField* field, int64_t value) {
	$Objects::requireNonNull($of(field), "field"_s);
	appendInternal($$new($DateTimeFormatterBuilder$DefaultValueParser, field, value));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendValue($TemporalField* field) {
	$Objects::requireNonNull($of(field), "field"_s);
	$init($SignStyle);
	appendValue($$new($DateTimeFormatterBuilder$NumberPrinterParser, field, 1, 19, $SignStyle::NORMAL));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendValue($TemporalField* field, int32_t width) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(field), "field"_s);
	if (width < 1 || width > 19) {
		$throwNew($IllegalArgumentException, $$str({"The width must be from 1 to 19 inclusive but was "_s, $$str(width)}));
	}
	$init($SignStyle);
	$var($DateTimeFormatterBuilder$NumberPrinterParser, pp, $new($DateTimeFormatterBuilder$NumberPrinterParser, field, width, width, $SignStyle::NOT_NEGATIVE));
	appendValue(pp);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendValue($TemporalField* field, int32_t minWidth, int32_t maxWidth, $SignStyle* signStyle) {
	$useLocalCurrentObjectStackCache();
	$init($SignStyle);
	if (minWidth == maxWidth && signStyle == $SignStyle::NOT_NEGATIVE) {
		return appendValue(field, maxWidth);
	}
	$Objects::requireNonNull($of(field), "field"_s);
	$Objects::requireNonNull($of(signStyle), "signStyle"_s);
	if (minWidth < 1 || minWidth > 19) {
		$throwNew($IllegalArgumentException, $$str({"The minimum width must be from 1 to 19 inclusive but was "_s, $$str(minWidth)}));
	}
	if (maxWidth < 1 || maxWidth > 19) {
		$throwNew($IllegalArgumentException, $$str({"The maximum width must be from 1 to 19 inclusive but was "_s, $$str(maxWidth)}));
	}
	if (maxWidth < minWidth) {
		$throwNew($IllegalArgumentException, $$str({"The maximum width must exceed or equal the minimum width but "_s, $$str(maxWidth), " < "_s, $$str(minWidth)}));
	}
	$var($DateTimeFormatterBuilder$NumberPrinterParser, pp, $new($DateTimeFormatterBuilder$NumberPrinterParser, field, minWidth, maxWidth, signStyle));
	appendValue(pp);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendValueReduced($TemporalField* field, int32_t width, int32_t maxWidth, int32_t baseValue) {
	$Objects::requireNonNull($of(field), "field"_s);
	$var($DateTimeFormatterBuilder$ReducedPrinterParser, pp, $new($DateTimeFormatterBuilder$ReducedPrinterParser, field, width, maxWidth, baseValue, nullptr));
	appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>(pp));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendValueReduced($TemporalField* field, int32_t width, int32_t maxWidth, $ChronoLocalDate* baseDate) {
	$Objects::requireNonNull($of(field), "field"_s);
	$Objects::requireNonNull($of(baseDate), "baseDate"_s);
	$var($DateTimeFormatterBuilder$ReducedPrinterParser, pp, $new($DateTimeFormatterBuilder$ReducedPrinterParser, field, width, maxWidth, 0, baseDate));
	appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>(pp));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendValue($DateTimeFormatterBuilder$NumberPrinterParser* pp) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->active)->valueParserIndex >= 0) {
		int32_t activeValueParser = $nc(this->active)->valueParserIndex;
		$var($DateTimeFormatterBuilder$NumberPrinterParser, basePP, $cast($DateTimeFormatterBuilder$NumberPrinterParser, $nc($nc(this->active)->printerParsers)->get(activeValueParser)));
		$init($SignStyle);
		if ($nc(pp)->minWidth == pp->maxWidth && pp->signStyle == $SignStyle::NOT_NEGATIVE) {
			$assign(basePP, $nc(basePP)->withSubsequentWidth(pp->maxWidth));
			appendInternal($(pp->withFixedWidth()));
			$nc(this->active)->valueParserIndex = activeValueParser;
		} else {
			$assign(basePP, $nc(basePP)->withFixedWidth());
			$nc(this->active)->valueParserIndex = appendInternal(pp);
		}
		$nc($nc(this->active)->printerParsers)->set(activeValueParser, basePP);
	} else {
		$nc(this->active)->valueParserIndex = appendInternal(pp);
	}
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendFraction($TemporalField* field, int32_t minWidth, int32_t maxWidth, bool decimalPoint) {
	$useLocalCurrentObjectStackCache();
	if (minWidth == maxWidth && decimalPoint == false) {
		appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$FractionPrinterParser, field, minWidth, maxWidth, decimalPoint)));
	} else {
		appendInternal($$new($DateTimeFormatterBuilder$FractionPrinterParser, field, minWidth, maxWidth, decimalPoint));
	}
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendText($TemporalField* field) {
	$init($TextStyle);
	return appendText(field, $TextStyle::FULL);
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendText($TemporalField* field, $TextStyle* textStyle) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(field), "field"_s);
	$Objects::requireNonNull($of(textStyle), "textStyle"_s);
	appendInternal($$new($DateTimeFormatterBuilder$TextPrinterParser, field, textStyle, $($DateTimeTextProvider::getInstance())));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendText($TemporalField* field, $Map* textLookup) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(field), "field"_s);
	$Objects::requireNonNull($of(textLookup), "textLookup"_s);
	$var($Map, copy, $new($LinkedHashMap, textLookup));
	$init($TextStyle);
	$var($Map, map, $Collections::singletonMap($TextStyle::FULL, copy));
	$var($DateTimeTextProvider$LocaleStore, store, $new($DateTimeTextProvider$LocaleStore, map));
	$var($DateTimeTextProvider, provider, $new($DateTimeFormatterBuilder$1, this, store));
	appendInternal($$new($DateTimeFormatterBuilder$TextPrinterParser, field, $TextStyle::FULL, provider));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendInstant() {
	appendInternal($$new($DateTimeFormatterBuilder$InstantPrinterParser, -2));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendInstant(int32_t fractionalDigits) {
	$useLocalCurrentObjectStackCache();
	if (fractionalDigits < -1 || fractionalDigits > 9) {
		$throwNew($IllegalArgumentException, $$str({"The fractional digits must be from -1 to 9 inclusive but was "_s, $$str(fractionalDigits)}));
	}
	appendInternal($$new($DateTimeFormatterBuilder$InstantPrinterParser, fractionalDigits));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendOffsetId() {
	$init($DateTimeFormatterBuilder$OffsetIdPrinterParser);
	appendInternal($DateTimeFormatterBuilder$OffsetIdPrinterParser::INSTANCE_ID_Z);
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendOffset($String* pattern, $String* noOffsetText) {
	appendInternal($$new($DateTimeFormatterBuilder$OffsetIdPrinterParser, pattern, noOffsetText));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendLocalizedOffset($TextStyle* style) {
	$Objects::requireNonNull($of(style), "style"_s);
	$init($TextStyle);
	if (style != $TextStyle::FULL && style != $TextStyle::SHORT) {
		$throwNew($IllegalArgumentException, "Style must be either full or short"_s);
	}
	appendInternal($$new($DateTimeFormatterBuilder$LocalizedOffsetIdPrinterParser, style));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendZoneId() {
	$useLocalCurrentObjectStackCache();
	appendInternal($$new($DateTimeFormatterBuilder$ZoneIdPrinterParser, $($TemporalQueries::zoneId()), "ZoneId()"_s));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendZoneRegionId() {
	appendInternal($$new($DateTimeFormatterBuilder$ZoneIdPrinterParser, DateTimeFormatterBuilder::QUERY_REGION_ONLY, "ZoneRegionId()"_s));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendZoneOrOffsetId() {
	$useLocalCurrentObjectStackCache();
	appendInternal($$new($DateTimeFormatterBuilder$ZoneIdPrinterParser, $($TemporalQueries::zone()), "ZoneOrOffsetId()"_s));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendZoneText($TextStyle* textStyle) {
	appendInternal($$new($DateTimeFormatterBuilder$ZoneTextPrinterParser, textStyle, nullptr, false));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendZoneText($TextStyle* textStyle, $Set* preferredZones) {
	$Objects::requireNonNull($of(preferredZones), "preferredZones"_s);
	appendInternal($$new($DateTimeFormatterBuilder$ZoneTextPrinterParser, textStyle, preferredZones, false));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendGenericZoneText($TextStyle* textStyle) {
	appendInternal($$new($DateTimeFormatterBuilder$ZoneTextPrinterParser, textStyle, nullptr, true));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendGenericZoneText($TextStyle* textStyle, $Set* preferredZones) {
	appendInternal($$new($DateTimeFormatterBuilder$ZoneTextPrinterParser, textStyle, preferredZones, true));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendChronologyId() {
	appendInternal($$new($DateTimeFormatterBuilder$ChronoPrinterParser, nullptr));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendChronologyText($TextStyle* textStyle) {
	$Objects::requireNonNull($of(textStyle), "textStyle"_s);
	appendInternal($$new($DateTimeFormatterBuilder$ChronoPrinterParser, textStyle));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendLocalized($FormatStyle* dateStyle, $FormatStyle* timeStyle) {
	if (dateStyle == nullptr && timeStyle == nullptr) {
		$throwNew($IllegalArgumentException, "Either the date or time style must be non-null"_s);
	}
	appendInternal($$new($DateTimeFormatterBuilder$LocalizedPrinterParser, dateStyle, timeStyle));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendLiteral(char16_t literal) {
	appendInternal($$new($DateTimeFormatterBuilder$CharLiteralPrinterParser, literal));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendLiteral($String* literal) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(literal), "literal"_s);
	if (!$nc(literal)->isEmpty()) {
		if (literal->length() == 1) {
			appendInternal($$new($DateTimeFormatterBuilder$CharLiteralPrinterParser, literal->charAt(0)));
		} else {
			appendInternal($$new($DateTimeFormatterBuilder$StringLiteralPrinterParser, literal));
		}
	}
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendDayPeriodText($TextStyle* style$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($TextStyle, style, style$renamed);
	$Objects::requireNonNull($of(style), "style"_s);
	$init($DateTimeFormatterBuilder$2);
	switch ($nc($DateTimeFormatterBuilder$2::$SwitchMap$java$time$format$TextStyle)->get($nc((style))->ordinal())) {
	case 1:
		{
			$init($TextStyle);
			style = $TextStyle::FULL;
			break;
		}
	case 2:
		{
			$init($TextStyle);
			style = $TextStyle::SHORT;
			break;
		}
	case 3:
		{
			$init($TextStyle);
			style = $TextStyle::NARROW;
			break;
		}
	}
	appendInternal($$new($DateTimeFormatterBuilder$DayPeriodPrinterParser, style));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::append($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	appendInternal($($nc(formatter)->toPrinterParser(false)));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendOptional($DateTimeFormatter* formatter) {
	$Objects::requireNonNull($of(formatter), "formatter"_s);
	appendInternal($($nc(formatter)->toPrinterParser(true)));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::appendPattern($String* pattern) {
	$Objects::requireNonNull($of(pattern), "pattern"_s);
	parsePattern(pattern);
	return this;
}

void DateTimeFormatterBuilder::parsePattern($String* pattern) {
	$useLocalCurrentObjectStackCache();
	for (int32_t pos = 0; pos < $nc(pattern)->length(); ++pos) {
		char16_t cur = pattern->charAt(pos);
		if ((cur >= u'A' && cur <= u'Z') || (cur >= u'a' && cur <= u'z')) {
			int32_t start = pos++;
			{
				/*missing*/;
				for (;; ++pos) {
					bool var$0 = pos < pattern->length();
					if (!(var$0 && pattern->charAt(pos) == cur)) {
						break;
					}
					{
					}
				}
			}
			int32_t count = pos - start;
			if (cur == u'p') {
				int32_t pad = 0;
				if (pos < pattern->length()) {
					cur = pattern->charAt(pos);
					if ((cur >= u'A' && cur <= u'Z') || (cur >= u'a' && cur <= u'z')) {
						pad = count;
						start = pos++;
						{
							/*missing*/;
							for (;; ++pos) {
								bool var$1 = pos < pattern->length();
								if (!(var$1 && pattern->charAt(pos) == cur)) {
									break;
								}
								{
								}
							}
						}
						count = pos - start;
					}
				}
				if (pad == 0) {
					$throwNew($IllegalArgumentException, $$str({"Pad letter \'p\' must be followed by valid pad pattern: "_s, pattern}));
				}
				padNext(pad);
			}
			$var($TemporalField, field, $cast($TemporalField, $nc(DateTimeFormatterBuilder::FIELD_MAP)->get($($Character::valueOf(cur)))));
			if (field != nullptr) {
				parseField(cur, count, field);
			} else if (cur == u'z') {
				if (count > 4) {
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				} else if (count == 4) {
					$init($TextStyle);
					appendZoneText($TextStyle::FULL);
				} else {
					$init($TextStyle);
					appendZoneText($TextStyle::SHORT);
				}
			} else if (cur == u'V') {
				if (count != 2) {
					$throwNew($IllegalArgumentException, $$str({"Pattern letter count must be 2: "_s, $$str(cur)}));
				}
				appendZoneId();
			} else if (cur == u'v') {
				if (count == 1) {
					$init($TextStyle);
					appendGenericZoneText($TextStyle::SHORT);
				} else if (count == 4) {
					$init($TextStyle);
					appendGenericZoneText($TextStyle::FULL);
				} else {
					$throwNew($IllegalArgumentException, $$str({"Wrong number of pattern letters: "_s, $$str(cur)}));
				}
			} else if (cur == u'Z') {
				if (count < 4) {
					appendOffset("+HHMM"_s, "+0000"_s);
				} else if (count == 4) {
					$init($TextStyle);
					appendLocalizedOffset($TextStyle::FULL);
				} else if (count == 5) {
					appendOffset("+HH:MM:ss"_s, "Z"_s);
				} else {
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
			} else if (cur == u'O') {
				if (count == 1) {
					$init($TextStyle);
					appendLocalizedOffset($TextStyle::SHORT);
				} else if (count == 4) {
					$init($TextStyle);
					appendLocalizedOffset($TextStyle::FULL);
				} else {
					$throwNew($IllegalArgumentException, $$str({"Pattern letter count must be 1 or 4: "_s, $$str(cur)}));
				}
			} else if (cur == u'X') {
				if (count > 5) {
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
				$init($DateTimeFormatterBuilder$OffsetIdPrinterParser);
				appendOffset($nc($DateTimeFormatterBuilder$OffsetIdPrinterParser::PATTERNS)->get(count + (count == 1 ? 0 : 1)), "Z"_s);
			} else if (cur == u'x') {
				if (count > 5) {
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
				$var($String, zero, count == 1 ? "+00"_s : (count % 2 == 0 ? "+0000"_s : "+00:00"_s));
				$init($DateTimeFormatterBuilder$OffsetIdPrinterParser);
				appendOffset($nc($DateTimeFormatterBuilder$OffsetIdPrinterParser::PATTERNS)->get(count + (count == 1 ? 0 : 1)), zero);
			} else if (cur == u'W') {
				if (count > 1) {
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
				appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$WeekBasedFieldPrinterParser, cur, count, count, count)));
			} else if (cur == u'w') {
				if (count > 2) {
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
				appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$WeekBasedFieldPrinterParser, cur, count, count, 2)));
			} else if (cur == u'Y') {
				if (count == 2) {
					appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$WeekBasedFieldPrinterParser, cur, count, count, 2)));
				} else {
					appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$WeekBasedFieldPrinterParser, cur, count, count, 19)));
				}
			} else if (cur == u'B') {
				switch (count) {
				case 1:
					{
						$init($TextStyle);
						appendDayPeriodText($TextStyle::SHORT);
						break;
					}
				case 4:
					{
						$init($TextStyle);
						appendDayPeriodText($TextStyle::FULL);
						break;
					}
				case 5:
					{
						$init($TextStyle);
						appendDayPeriodText($TextStyle::NARROW);
						break;
					}
				default:
					{
						$throwNew($IllegalArgumentException, $$str({"Wrong number of pattern letters: "_s, $$str(cur)}));
					}
				}
			} else {
				$throwNew($IllegalArgumentException, $$str({"Unknown pattern letter: "_s, $$str(cur)}));
			}
			--pos;
		} else if (cur == u'\'') {
			int32_t start = pos++;
			for (; pos < pattern->length(); ++pos) {
				if (pattern->charAt(pos) == u'\'') {
					bool var$2 = pos + 1 < pattern->length();
					if (var$2 && pattern->charAt(pos + 1) == u'\'') {
						++pos;
					} else {
						break;
					}
				}
			}
			if (pos >= pattern->length()) {
				$throwNew($IllegalArgumentException, $$str({"Pattern ends with an incomplete string literal: "_s, pattern}));
			}
			$var($String, str, pattern->substring(start + 1, pos));
			if (str->isEmpty()) {
				appendLiteral(u'\'');
			} else {
				appendLiteral($(str->replace(static_cast<$CharSequence*>("\'\'"_s), static_cast<$CharSequence*>("\'"_s))));
			}
		} else if (cur == u'[') {
			optionalStart();
		} else if (cur == u']') {
			if ($nc(this->active)->parent == nullptr) {
				$throwNew($IllegalArgumentException, "Pattern invalid as it contains ] without previous ["_s);
			}
			optionalEnd();
		} else if (cur == u'{' || cur == u'}' || cur == u'#') {
			$throwNew($IllegalArgumentException, $$str({"Pattern includes reserved character: \'"_s, $$str(cur), "\'"_s}));
		} else {
			appendLiteral(cur);
		}
	}
}

void DateTimeFormatterBuilder::parseField(char16_t cur, int32_t count, $TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	bool standalone = false;
	switch (cur) {
	case u'u':
		{}
	case u'y':
		{
			if (count == 2) {
				$init($DateTimeFormatterBuilder$ReducedPrinterParser);
				appendValueReduced(field, 2, 2, static_cast<$ChronoLocalDate*>($DateTimeFormatterBuilder$ReducedPrinterParser::BASE_DATE));
			} else if (count < 4) {
				$init($SignStyle);
				appendValue(field, count, 19, $SignStyle::NORMAL);
			} else {
				$init($SignStyle);
				appendValue(field, count, 19, $SignStyle::EXCEEDS_PAD);
			}
			break;
		}
	case u'c':
		{
			if (count == 1) {
				appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$WeekBasedFieldPrinterParser, cur, count, count, count)));
				break;
			} else if (count == 2) {
				$throwNew($IllegalArgumentException, "Invalid pattern \"cc\""_s);
			}
		}
	case u'L':
		{}
	case u'q':
		{
			standalone = true;
		}
	case u'M':
		{}
	case u'Q':
		{}
	case u'E':
		{}
	case u'e':
		{
			switch (count) {
			case 1:
				{}
			case 2:
				{
					if (cur == u'e') {
						appendValue(static_cast<$DateTimeFormatterBuilder$NumberPrinterParser*>($$new($DateTimeFormatterBuilder$WeekBasedFieldPrinterParser, cur, count, count, count)));
					} else if (cur == u'E') {
						$init($TextStyle);
						appendText(field, $TextStyle::SHORT);
					} else if (count == 1) {
						appendValue(field);
					} else {
						appendValue(field, 2);
					}
					break;
				}
			case 3:
				{
					$init($TextStyle);
					appendText(field, standalone ? $TextStyle::SHORT_STANDALONE : $TextStyle::SHORT);
					break;
				}
			case 4:
				{
					$init($TextStyle);
					appendText(field, standalone ? $TextStyle::FULL_STANDALONE : $TextStyle::FULL);
					break;
				}
			case 5:
				{
					$init($TextStyle);
					appendText(field, standalone ? $TextStyle::NARROW_STANDALONE : $TextStyle::NARROW);
					break;
				}
			default:
				{
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
			}
			break;
		}
	case u'a':
		{
			if (count == 1) {
				$init($TextStyle);
				appendText(field, $TextStyle::SHORT);
			} else {
				$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
			}
			break;
		}
	case u'G':
		{
			switch (count) {
			case 1:
				{}
			case 2:
				{}
			case 3:
				{
					$init($TextStyle);
					appendText(field, $TextStyle::SHORT);
					break;
				}
			case 4:
				{
					$init($TextStyle);
					appendText(field, $TextStyle::FULL);
					break;
				}
			case 5:
				{
					$init($TextStyle);
					appendText(field, $TextStyle::NARROW);
					break;
				}
			default:
				{
					$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
				}
			}
			break;
		}
	case u'S':
		{
			$init($ChronoField);
			appendFraction($ChronoField::NANO_OF_SECOND, count, count, false);
			break;
		}
	case u'F':
		{
			if (count == 1) {
				appendValue(field);
			} else {
				$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
			}
			break;
		}
	case u'd':
		{}
	case u'h':
		{}
	case u'H':
		{}
	case u'k':
		{}
	case u'K':
		{}
	case u'm':
		{}
	case u's':
		{
			if (count == 1) {
				appendValue(field);
			} else if (count == 2) {
				appendValue(field, count);
			} else {
				$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
			}
			break;
		}
	case u'D':
		{
			if (count == 1) {
				appendValue(field);
			} else if (count == 2 || count == 3) {
				$init($SignStyle);
				appendValue(field, count, 3, $SignStyle::NOT_NEGATIVE);
			} else {
				$throwNew($IllegalArgumentException, $$str({"Too many pattern letters: "_s, $$str(cur)}));
			}
			break;
		}
	case u'g':
		{
			$init($SignStyle);
			appendValue(field, count, 19, $SignStyle::NORMAL);
			break;
		}
	case u'A':
		{}
	case u'n':
		{}
	case u'N':
		{
			$init($SignStyle);
			appendValue(field, count, 19, $SignStyle::NOT_NEGATIVE);
			break;
		}
	default:
		{
			if (count == 1) {
				appendValue(field);
			} else {
				appendValue(field, count);
			}
			break;
		}
	}
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::padNext(int32_t padWidth) {
	return padNext(padWidth, u' ');
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::padNext(int32_t padWidth, char16_t padChar) {
	$useLocalCurrentObjectStackCache();
	if (padWidth < 1) {
		$throwNew($IllegalArgumentException, $$str({"The pad width must be at least one but was "_s, $$str(padWidth)}));
	}
	$nc(this->active)->padNextWidth = padWidth;
	$nc(this->active)->padNextChar = padChar;
	$nc(this->active)->valueParserIndex = -1;
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::optionalStart() {
	$nc(this->active)->valueParserIndex = -1;
	$set(this, active, $new(DateTimeFormatterBuilder, this->active, true));
	return this;
}

DateTimeFormatterBuilder* DateTimeFormatterBuilder::optionalEnd() {
	if ($nc(this->active)->parent == nullptr) {
		$throwNew($IllegalStateException, "Cannot call optionalEnd() as there was no previous call to optionalStart()"_s);
	}
	if ($nc($nc(this->active)->printerParsers)->size() > 0) {
		$var($DateTimeFormatterBuilder$CompositePrinterParser, cpp, $new($DateTimeFormatterBuilder$CompositePrinterParser, $nc(this->active)->printerParsers, $nc(this->active)->optional));
		$set(this, active, $nc(this->active)->parent);
		appendInternal(cpp);
	} else {
		$set(this, active, $nc(this->active)->parent);
	}
	return this;
}

int32_t DateTimeFormatterBuilder::appendInternal($DateTimeFormatterBuilder$DateTimePrinterParser* pp$renamed) {
	$var($DateTimeFormatterBuilder$DateTimePrinterParser, pp, pp$renamed);
	$Objects::requireNonNull($of(pp), "pp"_s);
	if ($nc(this->active)->padNextWidth > 0) {
		$assign(pp, $new($DateTimeFormatterBuilder$PadPrinterParserDecorator, pp, $nc(this->active)->padNextWidth, $nc(this->active)->padNextChar));
		$nc(this->active)->padNextWidth = 0;
		$nc(this->active)->padNextChar = (char16_t)0;
	}
	$nc($nc(this->active)->printerParsers)->add(pp);
	$nc(this->active)->valueParserIndex = -1;
	return $nc($nc(this->active)->printerParsers)->size() - 1;
}

$DateTimeFormatter* DateTimeFormatterBuilder::toFormatter() {
	$init($Locale$Category);
	return toFormatter($($Locale::getDefault($Locale$Category::FORMAT)));
}

$DateTimeFormatter* DateTimeFormatterBuilder::toFormatter($Locale* locale) {
	$init($ResolverStyle);
	return toFormatter(locale, $ResolverStyle::SMART, nullptr);
}

$DateTimeFormatter* DateTimeFormatterBuilder::toFormatter($ResolverStyle* resolverStyle, $Chronology* chrono) {
	$init($Locale$Category);
	return toFormatter($($Locale::getDefault($Locale$Category::FORMAT)), resolverStyle, chrono);
}

$DateTimeFormatter* DateTimeFormatterBuilder::toFormatter($Locale* locale, $ResolverStyle* resolverStyle, $Chronology* chrono) {
	$Objects::requireNonNull($of(locale), "locale"_s);
	while ($nc(this->active)->parent != nullptr) {
		optionalEnd();
	}
	$var($DateTimeFormatterBuilder$CompositePrinterParser, pp, $new($DateTimeFormatterBuilder$CompositePrinterParser, this->printerParsers, false));
	$init($DecimalStyle);
	return $new($DateTimeFormatter, pp, locale, $DecimalStyle::STANDARD, resolverStyle, nullptr, chrono, nullptr);
}

$ZoneId* DateTimeFormatterBuilder::lambda$static$0($TemporalAccessor* temporal) {
	$init(DateTimeFormatterBuilder);
	$useLocalCurrentObjectStackCache();
	$var($ZoneId, zone, $cast($ZoneId, $nc(temporal)->query($($TemporalQueries::zoneId()))));
	return $instanceOf($ZoneOffset, zone) ? ($ZoneId*)nullptr : zone;
}

void clinit$DateTimeFormatterBuilder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DateTimeFormatterBuilder::QUERY_REGION_ONLY, static_cast<$TemporalQuery*>($new(DateTimeFormatterBuilder$$Lambda$lambda$static$0)));
	$assignStatic(DateTimeFormatterBuilder::FIELD_MAP, $new($HashMap));
	{
		$init($ChronoField);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'G')), $ChronoField::ERA);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'y')), $ChronoField::YEAR_OF_ERA);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'u')), $ChronoField::YEAR);
		$init($IsoFields);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'Q')), $IsoFields::QUARTER_OF_YEAR);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'q')), $IsoFields::QUARTER_OF_YEAR);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'M')), $ChronoField::MONTH_OF_YEAR);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'L')), $ChronoField::MONTH_OF_YEAR);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'D')), $ChronoField::DAY_OF_YEAR);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'd')), $ChronoField::DAY_OF_MONTH);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'F')), $ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'E')), $ChronoField::DAY_OF_WEEK);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'c')), $ChronoField::DAY_OF_WEEK);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'e')), $ChronoField::DAY_OF_WEEK);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'a')), $ChronoField::AMPM_OF_DAY);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'H')), $ChronoField::HOUR_OF_DAY);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'k')), $ChronoField::CLOCK_HOUR_OF_DAY);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'K')), $ChronoField::HOUR_OF_AMPM);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'h')), $ChronoField::CLOCK_HOUR_OF_AMPM);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'm')), $ChronoField::MINUTE_OF_HOUR);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u's')), $ChronoField::SECOND_OF_MINUTE);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'S')), $ChronoField::NANO_OF_SECOND);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'A')), $ChronoField::MILLI_OF_DAY);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'n')), $ChronoField::NANO_OF_SECOND);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'N')), $ChronoField::NANO_OF_DAY);
		$init($JulianFields);
		$nc(DateTimeFormatterBuilder::FIELD_MAP)->put($($Character::valueOf(u'g')), $JulianFields::MODIFIED_JULIAN_DAY);
	}
}

DateTimeFormatterBuilder::DateTimeFormatterBuilder() {
}

$Class* DateTimeFormatterBuilder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DateTimeFormatterBuilder$$Lambda$lambda$static$0::classInfo$.name)) {
			return DateTimeFormatterBuilder$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(DateTimeFormatterBuilder, name, initialize, &_DateTimeFormatterBuilder_ClassInfo_, clinit$DateTimeFormatterBuilder, allocate$DateTimeFormatterBuilder);
	return class$;
}

$Class* DateTimeFormatterBuilder::class$ = nullptr;

		} // format
	} // time
} // java