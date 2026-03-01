#include <java/time/format/DateTimeFormatterBuilder$LocalizedPrinterParser.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder$CompositePrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/DateTimeParseContext.h>
#include <java/time/format/DateTimePrintContext.h>
#include <java/time/format/FormatStyle.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/util/Locale.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <jcpp.h>

#undef FORMATTER_CACHE

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Chronology = ::java::time::chrono::Chronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $DateTimeFormatterBuilder$CompositePrinterParser = ::java::time::format::DateTimeFormatterBuilder$CompositePrinterParser;
using $DateTimeParseContext = ::java::time::format::DateTimeParseContext;
using $DateTimePrintContext = ::java::time::format::DateTimePrintContext;
using $FormatStyle = ::java::time::format::FormatStyle;
using $Locale = ::java::util::Locale;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _DateTimeFormatterBuilder$LocalizedPrinterParser_FieldInfo_[] = {
	{"FORMATTER_CACHE", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/time/format/DateTimeFormatter;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeFormatterBuilder$LocalizedPrinterParser, FORMATTER_CACHE)},
	{"dateStyle", "Ljava/time/format/FormatStyle;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$LocalizedPrinterParser, dateStyle)},
	{"timeStyle", "Ljava/time/format/FormatStyle;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$LocalizedPrinterParser, timeStyle)},
	{}
};

$MethodInfo _DateTimeFormatterBuilder$LocalizedPrinterParser_MethodInfo_[] = {
	{"<init>", "(Ljava/time/format/FormatStyle;Ljava/time/format/FormatStyle;)V", nullptr, 0, $method(DateTimeFormatterBuilder$LocalizedPrinterParser, init$, void, $FormatStyle*, $FormatStyle*)},
	{"format", "(Ljava/time/format/DateTimePrintContext;Ljava/lang/StringBuilder;)Z", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$LocalizedPrinterParser, format, bool, $DateTimePrintContext*, $StringBuilder*)},
	{"formatter", "(Ljava/util/Locale;Ljava/time/chrono/Chronology;)Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder$LocalizedPrinterParser, formatter, $DateTimeFormatter*, $Locale*, $Chronology*)},
	{"parse", "(Ljava/time/format/DateTimeParseContext;Ljava/lang/CharSequence;I)I", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$LocalizedPrinterParser, parse, int32_t, $DateTimeParseContext*, $CharSequence*, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$LocalizedPrinterParser, toString, $String*)},
	{}
};

$InnerClassInfo _DateTimeFormatterBuilder$LocalizedPrinterParser_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeFormatterBuilder$LocalizedPrinterParser", "java.time.format.DateTimeFormatterBuilder", "LocalizedPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$DateTimePrinterParser", "java.time.format.DateTimeFormatterBuilder", "DateTimePrinterParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _DateTimeFormatterBuilder$LocalizedPrinterParser_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.DateTimeFormatterBuilder$LocalizedPrinterParser",
	"java.lang.Object",
	"java.time.format.DateTimeFormatterBuilder$DateTimePrinterParser",
	_DateTimeFormatterBuilder$LocalizedPrinterParser_FieldInfo_,
	_DateTimeFormatterBuilder$LocalizedPrinterParser_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeFormatterBuilder$LocalizedPrinterParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.format.DateTimeFormatterBuilder"
};

$Object* allocate$DateTimeFormatterBuilder$LocalizedPrinterParser($Class* clazz) {
	return $of($alloc(DateTimeFormatterBuilder$LocalizedPrinterParser));
}

$ConcurrentMap* DateTimeFormatterBuilder$LocalizedPrinterParser::FORMATTER_CACHE = nullptr;

void DateTimeFormatterBuilder$LocalizedPrinterParser::init$($FormatStyle* dateStyle, $FormatStyle* timeStyle) {
	$set(this, dateStyle, dateStyle);
	$set(this, timeStyle, timeStyle);
}

bool DateTimeFormatterBuilder$LocalizedPrinterParser::format($DateTimePrintContext* context, $StringBuilder* buf) {
	$useLocalCurrentObjectStackCache();
	$var($Chronology, chrono, $Chronology::from($($nc(context)->getTemporal())));
	return $nc($($nc($(formatter($($nc(context)->getLocale()), chrono)))->toPrinterParser(false)))->format(context, buf);
}

int32_t DateTimeFormatterBuilder$LocalizedPrinterParser::parse($DateTimeParseContext* context, $CharSequence* text, int32_t position) {
	$useLocalCurrentObjectStackCache();
	$var($Chronology, chrono, $nc(context)->getEffectiveChronology());
	return $nc($($nc($(formatter($(context->getLocale()), chrono)))->toPrinterParser(false)))->parse(context, text, position);
}

$DateTimeFormatter* DateTimeFormatterBuilder$LocalizedPrinterParser::formatter($Locale* locale, $Chronology* chrono) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$3, $$str({$($nc(chrono)->getId()), $$str(u'|')}));
	$var($String, var$2, $$concat(var$3, $($nc(locale)->toString())));
	$var($String, var$1, $$concat(var$2, $$str(u'|')));
	$var($String, var$0, $$concat(var$1, this->dateStyle));
	$var($String, key, $concat(var$0, this->timeStyle));
	$var($DateTimeFormatter, formatter, $cast($DateTimeFormatter, $nc(DateTimeFormatterBuilder$LocalizedPrinterParser::FORMATTER_CACHE)->get(key)));
	if (formatter == nullptr) {
		$var($String, pattern, $DateTimeFormatterBuilder::getLocalizedDateTimePattern(this->dateStyle, this->timeStyle, chrono, locale));
		$assign(formatter, $nc($($$new($DateTimeFormatterBuilder)->appendPattern(pattern)))->toFormatter(locale));
		$var($DateTimeFormatter, old, $cast($DateTimeFormatter, $nc(DateTimeFormatterBuilder$LocalizedPrinterParser::FORMATTER_CACHE)->putIfAbsent(key, formatter)));
		if (old != nullptr) {
			$assign(formatter, old);
		}
	}
	return formatter;
}

$String* DateTimeFormatterBuilder$LocalizedPrinterParser::toString() {
	return $str({"Localized("_s, (this->dateStyle != nullptr ? static_cast<$Serializable*>(this->dateStyle) : static_cast<$Serializable*>(""_s)), ","_s, (this->timeStyle != nullptr ? static_cast<$Serializable*>(this->timeStyle) : static_cast<$Serializable*>(""_s)), ")"_s});
}

void clinit$DateTimeFormatterBuilder$LocalizedPrinterParser($Class* class$) {
	$assignStatic(DateTimeFormatterBuilder$LocalizedPrinterParser::FORMATTER_CACHE, $new($ConcurrentHashMap, 16, 0.75f, 2));
}

DateTimeFormatterBuilder$LocalizedPrinterParser::DateTimeFormatterBuilder$LocalizedPrinterParser() {
}

$Class* DateTimeFormatterBuilder$LocalizedPrinterParser::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatterBuilder$LocalizedPrinterParser, name, initialize, &_DateTimeFormatterBuilder$LocalizedPrinterParser_ClassInfo_, clinit$DateTimeFormatterBuilder$LocalizedPrinterParser, allocate$DateTimeFormatterBuilder$LocalizedPrinterParser);
	return class$;
}

$Class* DateTimeFormatterBuilder$LocalizedPrinterParser::class$ = nullptr;

		} // format
	} // time
} // java