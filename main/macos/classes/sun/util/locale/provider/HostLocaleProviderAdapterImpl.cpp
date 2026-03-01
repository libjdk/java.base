#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl.h>

#include <java/lang/CharSequence.h>
#include <java/text/spi/DateFormatProvider.h>
#include <java/text/spi/DateFormatSymbolsProvider.h>
#include <java/text/spi/DecimalFormatSymbolsProvider.h>
#include <java/text/spi/NumberFormatProvider.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Locale$Builder.h>
#include <java/util/Locale.h>
#include <java/util/ResourceBundle$Control.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/spi/CalendarDataProvider.h>
#include <java/util/spi/CalendarNameProvider.h>
#include <java/util/spi/CurrencyNameProvider.h>
#include <java/util/spi/LocaleNameProvider.h>
#include <java/util/spi/TimeZoneNameProvider.h>
#include <sun/text/spi/JavaTimeDateTimePatternProvider.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$1.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$10.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$11.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$2.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$3.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$4.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$5.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$6.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$7.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$8.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$9.h>
#include <sun/util/locale/provider/JRELocaleConstants.h>
#include <sun/util/spi/CalendarProvider.h>
#include <jcpp.h>

#undef CAT_DISPLAY
#undef CAT_FORMAT
#undef CD_FIRSTDAYOFWEEK
#undef CD_MINIMALDAYSINFIRSTWEEK
#undef DN_CURRENCY_CODE
#undef DN_CURRENCY_SYMBOL
#undef DN_LOCALE_LANGUAGE
#undef DN_LOCALE_REGION
#undef DN_LOCALE_SCRIPT
#undef DN_LOCALE_VARIANT
#undef DN_TZ_LONG_DST
#undef DN_TZ_LONG_STANDARD
#undef DN_TZ_SHORT_DST
#undef DN_TZ_SHORT_STANDARD
#undef FORMAT_DEFAULT
#undef JAPAN
#undef JA_JP_JP
#undef NF_CURRENCY
#undef NF_INTEGER
#undef NF_MAX
#undef NF_NUMBER
#undef NF_PERCENT

using $LocaleArray = $Array<::java::util::Locale>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateFormatProvider = ::java::text::spi::DateFormatProvider;
using $DateFormatSymbolsProvider = ::java::text::spi::DateFormatSymbolsProvider;
using $DecimalFormatSymbolsProvider = ::java::text::spi::DecimalFormatSymbolsProvider;
using $NumberFormatProvider = ::java::text::spi::NumberFormatProvider;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Locale = ::java::util::Locale;
using $Locale$Builder = ::java::util::Locale$Builder;
using $ResourceBundle$Control = ::java::util::ResourceBundle$Control;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDataProvider = ::java::util::spi::CalendarDataProvider;
using $CalendarNameProvider = ::java::util::spi::CalendarNameProvider;
using $CurrencyNameProvider = ::java::util::spi::CurrencyNameProvider;
using $LocaleNameProvider = ::java::util::spi::LocaleNameProvider;
using $TimeZoneNameProvider = ::java::util::spi::TimeZoneNameProvider;
using $JavaTimeDateTimePatternProvider = ::sun::text::spi::JavaTimeDateTimePatternProvider;
using $HostLocaleProviderAdapterImpl$1 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$1;
using $HostLocaleProviderAdapterImpl$10 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$10;
using $HostLocaleProviderAdapterImpl$11 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$11;
using $HostLocaleProviderAdapterImpl$2 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$2;
using $HostLocaleProviderAdapterImpl$3 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$3;
using $HostLocaleProviderAdapterImpl$4 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$4;
using $HostLocaleProviderAdapterImpl$5 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$5;
using $HostLocaleProviderAdapterImpl$6 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$6;
using $HostLocaleProviderAdapterImpl$7 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$7;
using $HostLocaleProviderAdapterImpl$8 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$8;
using $HostLocaleProviderAdapterImpl$9 = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl$9;
using $JRELocaleConstants = ::sun::util::locale::provider::JRELocaleConstants;
using $CalendarProvider = ::sun::util::spi::CalendarProvider;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _HostLocaleProviderAdapterImpl_FieldInfo_[] = {
	{"dateFormatPatternsMap", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<Ljava/util/concurrent/atomic/AtomicReferenceArray<Ljava/lang/String;>;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HostLocaleProviderAdapterImpl, dateFormatPatternsMap)},
	{"numberFormatPatternsMap", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<Ljava/util/concurrent/atomic/AtomicReferenceArray<Ljava/lang/String;>;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HostLocaleProviderAdapterImpl, numberFormatPatternsMap)},
	{"dateFormatSymbolsMap", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<Ljava/text/DateFormatSymbols;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HostLocaleProviderAdapterImpl, dateFormatSymbolsMap)},
	{"decimalFormatSymbolsMap", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<Ljava/text/DecimalFormatSymbols;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HostLocaleProviderAdapterImpl, decimalFormatSymbolsMap)},
	{"CAT_DISPLAY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, CAT_DISPLAY)},
	{"CAT_FORMAT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, CAT_FORMAT)},
	{"NF_NUMBER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, NF_NUMBER)},
	{"NF_CURRENCY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, NF_CURRENCY)},
	{"NF_PERCENT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, NF_PERCENT)},
	{"NF_INTEGER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, NF_INTEGER)},
	{"NF_MAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, NF_MAX)},
	{"CD_FIRSTDAYOFWEEK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, CD_FIRSTDAYOFWEEK)},
	{"CD_MINIMALDAYSINFIRSTWEEK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, CD_MINIMALDAYSINFIRSTWEEK)},
	{"DN_LOCALE_LANGUAGE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_LOCALE_LANGUAGE)},
	{"DN_LOCALE_SCRIPT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_LOCALE_SCRIPT)},
	{"DN_LOCALE_REGION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_LOCALE_REGION)},
	{"DN_LOCALE_VARIANT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_LOCALE_VARIANT)},
	{"DN_CURRENCY_CODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_CURRENCY_CODE)},
	{"DN_CURRENCY_SYMBOL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_CURRENCY_SYMBOL)},
	{"DN_TZ_SHORT_STANDARD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_TZ_SHORT_STANDARD)},
	{"DN_TZ_SHORT_DST", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_TZ_SHORT_DST)},
	{"DN_TZ_LONG_STANDARD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_TZ_LONG_STANDARD)},
	{"DN_TZ_LONG_DST", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostLocaleProviderAdapterImpl, DN_TZ_LONG_DST)},
	{"supportedLocaleSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Locale;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HostLocaleProviderAdapterImpl, supportedLocaleSet)},
	{"supportedLocale", "[Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HostLocaleProviderAdapterImpl, supportedLocale)},
	{}
};

$MethodInfo _HostLocaleProviderAdapterImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HostLocaleProviderAdapterImpl, init$, void)},
	{"appendN", "(CILjava/lang/StringBuilder;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, appendN, void, char16_t, int32_t, $StringBuilder*)},
	{"convert", "(Ljava/lang/String;CILjava/lang/StringBuilder;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, convert, void, $String*, char16_t, int32_t, $StringBuilder*)},
	{"convertMacOSXLocaleToJavaLocale", "(Ljava/lang/String;)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, convertMacOSXLocaleToJavaLocale, $Locale*, $String*)},
	{"getAmPmStrings", "(Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getAmPmStrings, $StringArray*, $String*, $StringArray*)},
	{"getCalendarDataProvider", "()Ljava/util/spi/CalendarDataProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarDataProvider, $CalendarDataProvider*)},
	{"getCalendarDisplayStrings", "(Ljava/lang/String;II)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarDisplayStrings, $StringArray*, $String*, int32_t, int32_t)},
	{"getCalendarID", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarID, $String*, $String*)},
	{"getCalendarInt", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarInt, int32_t, $String*, int32_t)},
	{"getCalendarLocale", "(Ljava/util/Locale;)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarLocale, $Locale*, $Locale*)},
	{"getCalendarNameProvider", "()Ljava/util/spi/CalendarNameProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarNameProvider, $CalendarNameProvider*)},
	{"getCalendarProvider", "()Lsun/util/spi/CalendarProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getCalendarProvider, $CalendarProvider*)},
	{"getCurrencyNameProvider", "()Ljava/util/spi/CurrencyNameProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getCurrencyNameProvider, $CurrencyNameProvider*)},
	{"getCurrencySymbol", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getCurrencySymbol, $String*, $String*, $String*)},
	{"getDateFormatProvider", "()Ljava/text/spi/DateFormatProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getDateFormatProvider, $DateFormatProvider*)},
	{"getDateFormatSymbolsProvider", "()Ljava/text/spi/DateFormatSymbolsProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getDateFormatSymbolsProvider, $DateFormatSymbolsProvider*)},
	{"getDateTimePatternNative", "(IILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getDateTimePatternNative, $String*, int32_t, int32_t, $String*)},
	{"getDecimalFormatSymbolsProvider", "()Ljava/text/spi/DecimalFormatSymbolsProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getDecimalFormatSymbolsProvider, $DecimalFormatSymbolsProvider*)},
	{"getDecimalSeparator", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getDecimalSeparator, char16_t, $String*, char16_t)},
	{"getDefaultLocale", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getDefaultLocale, $String*, int32_t)},
	{"getDisplayString", "(Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getDisplayString, $String*, $String*, int32_t, $String*)},
	{"getEras", "(Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getEras, $StringArray*, $String*, $StringArray*)},
	{"getExponentSeparator", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getExponentSeparator, $String*, $String*, $String*)},
	{"getGroupingSeparator", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getGroupingSeparator, char16_t, $String*, char16_t)},
	{"getInfinity", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getInfinity, $String*, $String*, $String*)},
	{"getInternationalCurrencySymbol", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getInternationalCurrencySymbol, $String*, $String*, $String*)},
	{"getJavaTimeDateTimePatternProvider", "()Lsun/text/spi/JavaTimeDateTimePatternProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getJavaTimeDateTimePatternProvider, $JavaTimeDateTimePatternProvider*)},
	{"getLocaleNameProvider", "()Ljava/util/spi/LocaleNameProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getLocaleNameProvider, $LocaleNameProvider*)},
	{"getMinusSign", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getMinusSign, char16_t, $String*, char16_t)},
	{"getMonetaryDecimalSeparator", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getMonetaryDecimalSeparator, char16_t, $String*, char16_t)},
	{"getMonths", "(Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getMonths, $StringArray*, $String*, $StringArray*)},
	{"getNaN", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getNaN, $String*, $String*, $String*)},
	{"getNumberFormatProvider", "()Ljava/text/spi/NumberFormatProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getNumberFormatProvider, $NumberFormatProvider*)},
	{"getNumberPatternNative", "(ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getNumberPatternNative, $String*, int32_t, $String*)},
	{"getPerMill", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getPerMill, char16_t, $String*, char16_t)},
	{"getPercent", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getPercent, char16_t, $String*, char16_t)},
	{"getShortMonths", "(Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getShortMonths, $StringArray*, $String*, $StringArray*)},
	{"getShortWeekdays", "(Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getShortWeekdays, $StringArray*, $String*, $StringArray*)},
	{"getSupportedCalendarLocales", "()[Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getSupportedCalendarLocales, $LocaleArray*)},
	{"getTimeZoneDisplayString", "(Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getTimeZoneDisplayString, $String*, $String*, int32_t, $String*)},
	{"getTimeZoneNameProvider", "()Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, getTimeZoneNameProvider, $TimeZoneNameProvider*)},
	{"getWeekdays", "(Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getWeekdays, $StringArray*, $String*, $StringArray*)},
	{"getZeroDigit", "(Ljava/lang/String;C)C", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(HostLocaleProviderAdapterImpl, getZeroDigit, char16_t, $String*, char16_t)},
	{"isJapaneseCalendar", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, isJapaneseCalendar, bool)},
	{"isSupportedCalendarLocale", "(Ljava/util/Locale;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, isSupportedCalendarLocale, bool, $Locale*)},
	{"translateDateFormatLetters", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(HostLocaleProviderAdapterImpl, translateDateFormatLetters, $String*, $String*, $String*)},
	{}
};

#define _METHOD_INDEX_getAmPmStrings 4
#define _METHOD_INDEX_getCalendarDisplayStrings 6
#define _METHOD_INDEX_getCalendarID 7
#define _METHOD_INDEX_getCalendarInt 8
#define _METHOD_INDEX_getCurrencySymbol 13
#define _METHOD_INDEX_getDateTimePatternNative 16
#define _METHOD_INDEX_getDecimalSeparator 18
#define _METHOD_INDEX_getDefaultLocale 19
#define _METHOD_INDEX_getDisplayString 20
#define _METHOD_INDEX_getEras 21
#define _METHOD_INDEX_getExponentSeparator 22
#define _METHOD_INDEX_getGroupingSeparator 23
#define _METHOD_INDEX_getInfinity 24
#define _METHOD_INDEX_getInternationalCurrencySymbol 25
#define _METHOD_INDEX_getMinusSign 28
#define _METHOD_INDEX_getMonetaryDecimalSeparator 29
#define _METHOD_INDEX_getMonths 30
#define _METHOD_INDEX_getNaN 31
#define _METHOD_INDEX_getNumberPatternNative 33
#define _METHOD_INDEX_getPerMill 34
#define _METHOD_INDEX_getPercent 35
#define _METHOD_INDEX_getShortMonths 36
#define _METHOD_INDEX_getShortWeekdays 37
#define _METHOD_INDEX_getTimeZoneDisplayString 39
#define _METHOD_INDEX_getWeekdays 41
#define _METHOD_INDEX_getZeroDigit 42

$InnerClassInfo _HostLocaleProviderAdapterImpl_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$11", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$10", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$9", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$8", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$7", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$6", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$5", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$4", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$3", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$2", nullptr, nullptr, 0},
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HostLocaleProviderAdapterImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl",
	"java.lang.Object",
	nullptr,
	_HostLocaleProviderAdapterImpl_FieldInfo_,
	_HostLocaleProviderAdapterImpl_MethodInfo_,
	nullptr,
	nullptr,
	_HostLocaleProviderAdapterImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl$11,sun.util.locale.provider.HostLocaleProviderAdapterImpl$10,sun.util.locale.provider.HostLocaleProviderAdapterImpl$9,sun.util.locale.provider.HostLocaleProviderAdapterImpl$8,sun.util.locale.provider.HostLocaleProviderAdapterImpl$7,sun.util.locale.provider.HostLocaleProviderAdapterImpl$6,sun.util.locale.provider.HostLocaleProviderAdapterImpl$5,sun.util.locale.provider.HostLocaleProviderAdapterImpl$4,sun.util.locale.provider.HostLocaleProviderAdapterImpl$3,sun.util.locale.provider.HostLocaleProviderAdapterImpl$2,sun.util.locale.provider.HostLocaleProviderAdapterImpl$1"
};

$Object* allocate$HostLocaleProviderAdapterImpl($Class* clazz) {
	return $of($alloc(HostLocaleProviderAdapterImpl));
}

$ConcurrentMap* HostLocaleProviderAdapterImpl::dateFormatPatternsMap = nullptr;
$ConcurrentMap* HostLocaleProviderAdapterImpl::numberFormatPatternsMap = nullptr;
$ConcurrentMap* HostLocaleProviderAdapterImpl::dateFormatSymbolsMap = nullptr;
$ConcurrentMap* HostLocaleProviderAdapterImpl::decimalFormatSymbolsMap = nullptr;
$Set* HostLocaleProviderAdapterImpl::supportedLocaleSet = nullptr;
$LocaleArray* HostLocaleProviderAdapterImpl::supportedLocale = nullptr;

void HostLocaleProviderAdapterImpl::init$() {
}

$Locale* HostLocaleProviderAdapterImpl::convertMacOSXLocaleToJavaLocale($String* macosxloc) {
	$init(HostLocaleProviderAdapterImpl);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, tmp, $nc(macosxloc)->split("@"_s));
	$var($String, langTag, $nc(tmp->get(0))->replace(u'_', u'-'));
	if (tmp->length > 1) {
		$var($StringArray, ext, $nc(tmp->get(1))->split(";"_s));
		{
			$var($StringArray, arr$, ext);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, keyval, arr$->get(i$));
				{
					if ($nc(keyval)->startsWith("calendar="_s)) {
						$var($String, calid, keyval->substring(keyval->indexOf((int32_t)u'=') + 1));
						{
							$var($String, s5848$, calid);
							int32_t tmp5848$ = -1;
							switch (s5848$->hashCode()) {
							case 0x7EB8C6E6:
								{
									if (s5848$->equals("gregorian"_s)) {
										tmp5848$ = 0;
									}
									break;
								}
							case (int32_t)0xD3223FB1:
								{
									if (s5848$->equals("japanese"_s)) {
										tmp5848$ = 1;
									}
									break;
								}
							}
							switch (tmp5848$) {
							case 0:
								{
									$plusAssign(langTag, "-u-ca-gregory"_s);
									break;
								}
							case 1:
								{
									if ($nc(tmp->get(0))->equals("ja_JP"_s)) {
										$init($JRELocaleConstants);
										return $JRELocaleConstants::JA_JP_JP;
									}
								}
							default:
								{
									$plusAssign(langTag, $$str({"-u-ca-"_s, calid}));
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	return $Locale::forLanguageTag(langTag);
}

$JavaTimeDateTimePatternProvider* HostLocaleProviderAdapterImpl::getJavaTimeDateTimePatternProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$1);
}

$DateFormatProvider* HostLocaleProviderAdapterImpl::getDateFormatProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$2);
}

$DateFormatSymbolsProvider* HostLocaleProviderAdapterImpl::getDateFormatSymbolsProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$3);
}

$NumberFormatProvider* HostLocaleProviderAdapterImpl::getNumberFormatProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$4);
}

$DecimalFormatSymbolsProvider* HostLocaleProviderAdapterImpl::getDecimalFormatSymbolsProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$5);
}

$CalendarDataProvider* HostLocaleProviderAdapterImpl::getCalendarDataProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$6);
}

$CalendarNameProvider* HostLocaleProviderAdapterImpl::getCalendarNameProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$7);
}

$CalendarProvider* HostLocaleProviderAdapterImpl::getCalendarProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$8);
}

$CurrencyNameProvider* HostLocaleProviderAdapterImpl::getCurrencyNameProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$9);
}

$LocaleNameProvider* HostLocaleProviderAdapterImpl::getLocaleNameProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$10);
}

$TimeZoneNameProvider* HostLocaleProviderAdapterImpl::getTimeZoneNameProvider() {
	$init(HostLocaleProviderAdapterImpl);
	return $new($HostLocaleProviderAdapterImpl$11);
}

$LocaleArray* HostLocaleProviderAdapterImpl::getSupportedCalendarLocales() {
	$init(HostLocaleProviderAdapterImpl);
	$init($Locale);
	bool var$0 = $nc(HostLocaleProviderAdapterImpl::supportedLocale)->length != 0 && $nc(HostLocaleProviderAdapterImpl::supportedLocaleSet)->contains($Locale::JAPAN);
	if (var$0 && isJapaneseCalendar()) {
		$var($LocaleArray, sup, $new($LocaleArray, $nc(HostLocaleProviderAdapterImpl::supportedLocale)->length + 1));
		$init($JRELocaleConstants);
		sup->set(0, $JRELocaleConstants::JA_JP_JP);
		$System::arraycopy(HostLocaleProviderAdapterImpl::supportedLocale, 0, sup, 1, $nc(HostLocaleProviderAdapterImpl::supportedLocale)->length);
		return sup;
	}
	return HostLocaleProviderAdapterImpl::supportedLocale;
}

bool HostLocaleProviderAdapterImpl::isSupportedCalendarLocale($Locale* locale) {
	$init(HostLocaleProviderAdapterImpl);
	$useLocalCurrentObjectStackCache();
	$var($Locale, base, locale);
	bool var$0 = $nc(base)->hasExtensions();
	if (var$0 || $nc(base)->getVariant() != ""_s) {
		$assign(base, $nc($($nc($($$new($Locale$Builder)->setLocale(locale)))->clearExtensions()))->build());
	}
	if (!$nc(HostLocaleProviderAdapterImpl::supportedLocaleSet)->contains(base)) {
		return false;
	}
	$var($String, requestedCalType, $nc(locale)->getUnicodeLocaleType("ca"_s));
	$var($String, nativeCalType, $nc($(getCalendarID($($nc(base)->toLanguageTag()))))->replaceFirst("gregorian"_s, "gregory"_s));
	if (requestedCalType == nullptr) {
		return $nc($($Calendar::getAvailableCalendarTypes()))->contains(nativeCalType);
	} else {
		return $nc(requestedCalType)->equals(nativeCalType);
	}
}

bool HostLocaleProviderAdapterImpl::isJapaneseCalendar() {
	$init(HostLocaleProviderAdapterImpl);
	return $nc($(getCalendarID("ja-JP"_s)))->equals("japanese"_s);
}

$Locale* HostLocaleProviderAdapterImpl::getCalendarLocale($Locale* locale) {
	$init(HostLocaleProviderAdapterImpl);
	$useLocalCurrentObjectStackCache();
	$var($String, nativeCalType, $nc($(getCalendarID($($nc(locale)->toLanguageTag()))))->replaceFirst("gregorian"_s, "gregory"_s));
	if ($nc($($Calendar::getAvailableCalendarTypes()))->contains(nativeCalType)) {
		return $nc($($nc($($$new($Locale$Builder)->setLocale(locale)))->setUnicodeLocaleKeyword("ca"_s, nativeCalType)))->build();
	} else {
		return locale;
	}
}

$String* HostLocaleProviderAdapterImpl::translateDateFormatLetters($String* calendarType, $String* cldrFormat) {
	$init(HostLocaleProviderAdapterImpl);
	$useLocalCurrentObjectStackCache();
	$var($String, pattern, cldrFormat);
	int32_t length = $nc(pattern)->length();
	bool inQuote = false;
	$var($StringBuilder, jrePattern, $new($StringBuilder, length));
	int32_t count = 0;
	char16_t lastLetter = (char16_t)0;
	for (int32_t i = 0; i < length; ++i) {
		char16_t c = pattern->charAt(i);
		if (c == u'\'') {
			if ((i + 1) < length) {
				char16_t nextc = pattern->charAt(i + 1);
				if (nextc == u'\'') {
					++i;
					if (count != 0) {
						convert(calendarType, lastLetter, count, jrePattern);
						lastLetter = (char16_t)0;
						count = 0;
					}
					jrePattern->append("\'\'"_s);
					continue;
				}
			}
			if (!inQuote) {
				if (count != 0) {
					convert(calendarType, lastLetter, count, jrePattern);
					lastLetter = (char16_t)0;
					count = 0;
				}
				inQuote = true;
			} else {
				inQuote = false;
			}
			jrePattern->append(c);
			continue;
		}
		if (inQuote) {
			jrePattern->append(c);
			continue;
		}
		if (!(c >= u'a' && c <= u'z' || c >= u'A' && c <= u'Z')) {
			if (count != 0) {
				convert(calendarType, lastLetter, count, jrePattern);
				lastLetter = (char16_t)0;
				count = 0;
			}
			jrePattern->append(c);
			continue;
		}
		if (lastLetter == 0 || lastLetter == c) {
			lastLetter = c;
			++count;
			continue;
		}
		convert(calendarType, lastLetter, count, jrePattern);
		lastLetter = c;
		count = 1;
	}
	if (count != 0) {
		convert(calendarType, lastLetter, count, jrePattern);
	}
	if ($nc(cldrFormat)->contentEquals(static_cast<$CharSequence*>(jrePattern))) {
		return cldrFormat;
	}
	return jrePattern->toString();
}

void HostLocaleProviderAdapterImpl::convert($String* calendarType, char16_t cldrLetter, int32_t count, $StringBuilder* sb) {
	$init(HostLocaleProviderAdapterImpl);
	switch (cldrLetter) {
	case u'G':
		{
			if (!$nc(calendarType)->equals("gregorian"_s)) {
				if (count == 5) {
					count = 1;
				} else if (count == 1) {
					count = 4;
				}
			}
			appendN(cldrLetter, count, sb);
			break;
		}
	case u'c':
		{}
	case u'e':
		{
			switch (count) {
			case 1:
				{
					$nc(sb)->append(u'u');
					break;
				}
			case 3:
				{}
			case 4:
				{
					appendN(u'E', count, sb);
					break;
				}
			case 5:
				{
					appendN(u'E', 3, sb);
					break;
				}
			}
			break;
		}
	case u'v':
		{}
	case u'V':
		{
			appendN(u'z', count, sb);
			break;
		}
	case u'Z':
		{
			if (count == 4 || count == 5) {
				$nc(sb)->append("XXX"_s);
			}
			break;
		}
	case u'u':
		{}
	case u'U':
		{}
	case u'q':
		{}
	case u'Q':
		{}
	case u'l':
		{}
	case u'g':
		{}
	case u'j':
		{}
	case u'A':
		{
			$nc(sb)->append(u'\'');
			$nc(sb)->append(cldrLetter);
			$nc(sb)->append(u'\'');
			break;
		}
	default:
		{
			appendN(cldrLetter, count, sb);
			break;
		}
	}
}

void HostLocaleProviderAdapterImpl::appendN(char16_t c, int32_t n, $StringBuilder* sb) {
	$init(HostLocaleProviderAdapterImpl);
	for (int32_t i = 0; i < n; ++i) {
		$nc(sb)->append(c);
	}
}

$String* HostLocaleProviderAdapterImpl::getDefaultLocale(int32_t cat) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getDefaultLocale, $String*, int32_t cat);
	$assign($ret, $invokeNativeStaticObject(cat));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getDateTimePatternNative(int32_t dateStyle, int32_t timeStyle, $String* langtag) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getDateTimePatternNative, $String*, int32_t dateStyle, int32_t timeStyle, $String* langtag);
	$assign($ret, $invokeNativeStaticObject(dateStyle, timeStyle, langtag));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getCalendarID($String* langTag) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getCalendarID, $String*, $String* langTag);
	$assign($ret, $invokeNativeStaticObject(langTag));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getNumberPatternNative(int32_t style, $String* langtag) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getNumberPatternNative, $String*, int32_t style, $String* langtag);
	$assign($ret, $invokeNativeStaticObject(style, langtag));
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getAmPmStrings($String* langTag, $StringArray* ampm) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getAmPmStrings, $StringArray*, $String* langTag, $StringArray* ampm);
	$assign($ret, $invokeNativeStaticObject(langTag, ampm));
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getEras($String* langTag, $StringArray* eras) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getEras, $StringArray*, $String* langTag, $StringArray* eras);
	$assign($ret, $invokeNativeStaticObject(langTag, eras));
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getMonths($String* langTag, $StringArray* months) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getMonths, $StringArray*, $String* langTag, $StringArray* months);
	$assign($ret, $invokeNativeStaticObject(langTag, months));
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getShortMonths($String* langTag, $StringArray* smonths) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getShortMonths, $StringArray*, $String* langTag, $StringArray* smonths);
	$assign($ret, $invokeNativeStaticObject(langTag, smonths));
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getWeekdays($String* langTag, $StringArray* wdays) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getWeekdays, $StringArray*, $String* langTag, $StringArray* wdays);
	$assign($ret, $invokeNativeStaticObject(langTag, wdays));
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getShortWeekdays($String* langTag, $StringArray* swdays) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getShortWeekdays, $StringArray*, $String* langTag, $StringArray* swdays);
	$assign($ret, $invokeNativeStaticObject(langTag, swdays));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getCurrencySymbol($String* langTag, $String* currencySymbol) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getCurrencySymbol, $String*, $String* langTag, $String* currencySymbol);
	$assign($ret, $invokeNativeStaticObject(langTag, currencySymbol));
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getDecimalSeparator($String* langTag, char16_t decimalSeparator) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getDecimalSeparator, char16_t, $String* langTag, char16_t decimalSeparator);
	$ret = $invokeNativeStatic(langTag, decimalSeparator);
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getGroupingSeparator($String* langTag, char16_t groupingSeparator) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getGroupingSeparator, char16_t, $String* langTag, char16_t groupingSeparator);
	$ret = $invokeNativeStatic(langTag, groupingSeparator);
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getInfinity($String* langTag, $String* infinity) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getInfinity, $String*, $String* langTag, $String* infinity);
	$assign($ret, $invokeNativeStaticObject(langTag, infinity));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getInternationalCurrencySymbol($String* langTag, $String* internationalCurrencySymbol) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getInternationalCurrencySymbol, $String*, $String* langTag, $String* internationalCurrencySymbol);
	$assign($ret, $invokeNativeStaticObject(langTag, internationalCurrencySymbol));
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getMinusSign($String* langTag, char16_t minusSign) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getMinusSign, char16_t, $String* langTag, char16_t minusSign);
	$ret = $invokeNativeStatic(langTag, minusSign);
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getMonetaryDecimalSeparator($String* langTag, char16_t monetaryDecimalSeparator) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getMonetaryDecimalSeparator, char16_t, $String* langTag, char16_t monetaryDecimalSeparator);
	$ret = $invokeNativeStatic(langTag, monetaryDecimalSeparator);
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getNaN($String* langTag, $String* nan) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getNaN, $String*, $String* langTag, $String* nan);
	$assign($ret, $invokeNativeStaticObject(langTag, nan));
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getPercent($String* langTag, char16_t percent) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getPercent, char16_t, $String* langTag, char16_t percent);
	$ret = $invokeNativeStatic(langTag, percent);
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getPerMill($String* langTag, char16_t perMill) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getPerMill, char16_t, $String* langTag, char16_t perMill);
	$ret = $invokeNativeStatic(langTag, perMill);
	$finishNativeStatic();
	return $ret;
}

char16_t HostLocaleProviderAdapterImpl::getZeroDigit($String* langTag, char16_t zeroDigit) {
	$init(HostLocaleProviderAdapterImpl);
	char16_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getZeroDigit, char16_t, $String* langTag, char16_t zeroDigit);
	$ret = $invokeNativeStatic(langTag, zeroDigit);
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getExponentSeparator($String* langTag, $String* exponent) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getExponentSeparator, $String*, $String* langTag, $String* exponent);
	$assign($ret, $invokeNativeStaticObject(langTag, exponent));
	$finishNativeStatic();
	return $ret;
}

int32_t HostLocaleProviderAdapterImpl::getCalendarInt($String* langTag, int32_t type) {
	$init(HostLocaleProviderAdapterImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getCalendarInt, int32_t, $String* langTag, int32_t type);
	$ret = $invokeNativeStatic(langTag, type);
	$finishNativeStatic();
	return $ret;
}

$StringArray* HostLocaleProviderAdapterImpl::getCalendarDisplayStrings($String* langTag, int32_t field, int32_t style) {
	$init(HostLocaleProviderAdapterImpl);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getCalendarDisplayStrings, $StringArray*, $String* langTag, int32_t field, int32_t style);
	$assign($ret, $invokeNativeStaticObject(langTag, field, style));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getDisplayString($String* langTag, int32_t key, $String* value) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getDisplayString, $String*, $String* langTag, int32_t key, $String* value);
	$assign($ret, $invokeNativeStaticObject(langTag, key, value));
	$finishNativeStatic();
	return $ret;
}

$String* HostLocaleProviderAdapterImpl::getTimeZoneDisplayString($String* langTag, int32_t style, $String* value) {
	$init(HostLocaleProviderAdapterImpl);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(HostLocaleProviderAdapterImpl, getTimeZoneDisplayString, $String*, $String* langTag, int32_t style, $String* value);
	$assign($ret, $invokeNativeStaticObject(langTag, style, value));
	$finishNativeStatic();
	return $ret;
}

void clinit$HostLocaleProviderAdapterImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(HostLocaleProviderAdapterImpl::dateFormatPatternsMap, $new($ConcurrentHashMap, 2));
	$assignStatic(HostLocaleProviderAdapterImpl::numberFormatPatternsMap, $new($ConcurrentHashMap, 2));
	$assignStatic(HostLocaleProviderAdapterImpl::dateFormatSymbolsMap, $new($ConcurrentHashMap, 2));
	$assignStatic(HostLocaleProviderAdapterImpl::decimalFormatSymbolsMap, $new($ConcurrentHashMap, 2));
	{
		$var($Set, tmpSet, $new($HashSet));
		$var($Locale, l, HostLocaleProviderAdapterImpl::convertMacOSXLocaleToJavaLocale($(HostLocaleProviderAdapterImpl::getDefaultLocale(HostLocaleProviderAdapterImpl::CAT_FORMAT))));
		$init($ResourceBundle$Control);
		tmpSet->addAll($($nc($($ResourceBundle$Control::getNoFallbackControl($ResourceBundle$Control::FORMAT_DEFAULT)))->getCandidateLocales(""_s, l)));
		$assign(l, HostLocaleProviderAdapterImpl::convertMacOSXLocaleToJavaLocale($(HostLocaleProviderAdapterImpl::getDefaultLocale(HostLocaleProviderAdapterImpl::CAT_DISPLAY))));
		tmpSet->addAll($($nc($($ResourceBundle$Control::getNoFallbackControl($ResourceBundle$Control::FORMAT_DEFAULT)))->getCandidateLocales(""_s, l)));
		$assignStatic(HostLocaleProviderAdapterImpl::supportedLocaleSet, $Collections::unmodifiableSet(tmpSet));
	}
	$assignStatic(HostLocaleProviderAdapterImpl::supportedLocale, $fcast($LocaleArray, $nc(HostLocaleProviderAdapterImpl::supportedLocaleSet)->toArray($$new($LocaleArray, 0))));
}

HostLocaleProviderAdapterImpl::HostLocaleProviderAdapterImpl() {
}

$Class* HostLocaleProviderAdapterImpl::load$($String* name, bool initialize) {
	$loadClass(HostLocaleProviderAdapterImpl, name, initialize, &_HostLocaleProviderAdapterImpl_ClassInfo_, clinit$HostLocaleProviderAdapterImpl, allocate$HostLocaleProviderAdapterImpl);
	return class$;
}

$Class* HostLocaleProviderAdapterImpl::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun