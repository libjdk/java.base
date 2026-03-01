#include <sun/util/locale/provider/LocaleResources.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/text/MessageFormat.h>
#include <java/text/NumberFormat$Style.h>
#include <java/util/Arrays.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <java/util/TimeZone.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources$ResourceReference.h>
#include <sun/util/locale/provider/ResourceBundleBasedAdapter.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <sun/util/resources/LocaleData.h>
#include <sun/util/resources/OpenListResourceBundle.h>
#include <sun/util/resources/ParallelListResourceBundle.h>
#include <sun/util/resources/TimeZoneNamesBundle.h>
#include <jcpp.h>

#undef BREAK_ITERATOR_INFO
#undef CALENDAR_DATA
#undef CALENDAR_NAMES
#undef CLDR
#undef COLLATION_DATA_CACHEKEY
#undef COMPACT_NUMBER_PATTERNS_CACHEKEY
#undef CURRENCY_NAMES
#undef DATE_TIME_PATTERN
#undef DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY
#undef LOCALE_NAMES
#undef LONG
#undef NULLOBJECT
#undef NUMBER_PATTERNS_CACHEKEY
#undef RULES_CACHEKEY
#undef TIME_ZONE_NAMES
#undef TRACE_ON
#undef TZNB_EXCITY_PREFIX
#undef ZONE_IDS_CACHEKEY

using $StringArray2 = $Array<::java::lang::String, 2>;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $MessageFormat = ::java::text::MessageFormat;
using $NumberFormat$Style = ::java::text::NumberFormat$Style;
using $Arrays = ::java::util::Arrays;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $TimeZone = ::java::util::TimeZone;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleResources$ResourceReference = ::sun::util::locale::provider::LocaleResources$ResourceReference;
using $ResourceBundleBasedAdapter = ::sun::util::locale::provider::ResourceBundleBasedAdapter;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;
using $LocaleData = ::sun::util::resources::LocaleData;
using $OpenListResourceBundle = ::sun::util::resources::OpenListResourceBundle;
using $ParallelListResourceBundle = ::sun::util::resources::ParallelListResourceBundle;
using $TimeZoneNamesBundle = ::sun::util::resources::TimeZoneNamesBundle;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

class LocaleResources$$Lambda$lambda$getZoneStrings$0 : public $Predicate {
	$class(LocaleResources$$Lambda$lambda$getZoneStrings$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* i) override {
		 return LocaleResources::lambda$getZoneStrings$0($cast($String, i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocaleResources$$Lambda$lambda$getZoneStrings$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LocaleResources$$Lambda$lambda$getZoneStrings$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LocaleResources$$Lambda$lambda$getZoneStrings$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LocaleResources$$Lambda$lambda$getZoneStrings$0, test, bool, Object$*)},
	{}
};
$ClassInfo LocaleResources$$Lambda$lambda$getZoneStrings$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.LocaleResources$$Lambda$lambda$getZoneStrings$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* LocaleResources$$Lambda$lambda$getZoneStrings$0::load$($String* name, bool initialize) {
	$loadClass(LocaleResources$$Lambda$lambda$getZoneStrings$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocaleResources$$Lambda$lambda$getZoneStrings$0::class$ = nullptr;

class LocaleResources$$Lambda$lambda$getZoneStrings$1$1 : public $Consumer {
	$class(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* keyset, $TimeZoneNamesBundle* rb, $Set* value) {
		$set(this, keyset, keyset);
		$set(this, rb, rb);
		$set(this, value, value);
	}
	virtual void accept(Object$* tzid) override {
		LocaleResources::lambda$getZoneStrings$1(keyset, rb, value, $cast($String, tzid));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocaleResources$$Lambda$lambda$getZoneStrings$1$1>());
	}
	$Set* keyset = nullptr;
	$TimeZoneNamesBundle* rb = nullptr;
	$Set* value = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LocaleResources$$Lambda$lambda$getZoneStrings$1$1::fieldInfos[4] = {
	{"keyset", "Ljava/util/Set;", nullptr, $PUBLIC, $field(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, keyset)},
	{"rb", "Lsun/util/resources/TimeZoneNamesBundle;", nullptr, $PUBLIC, $field(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, rb)},
	{"value", "Ljava/util/Set;", nullptr, $PUBLIC, $field(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, value)},
	{}
};
$MethodInfo LocaleResources$$Lambda$lambda$getZoneStrings$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;Lsun/util/resources/TimeZoneNamesBundle;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, init$, void, $Set*, $TimeZoneNamesBundle*, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo LocaleResources$$Lambda$lambda$getZoneStrings$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.provider.LocaleResources$$Lambda$lambda$getZoneStrings$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LocaleResources$$Lambda$lambda$getZoneStrings$1$1::load$($String* name, bool initialize) {
	$loadClass(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocaleResources$$Lambda$lambda$getZoneStrings$1$1::class$ = nullptr;

$FieldInfo _LocaleResources_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LocaleResources, $assertionsDisabled)},
	{"locale", "Ljava/util/Locale;", nullptr, $PRIVATE | $FINAL, $field(LocaleResources, locale)},
	{"localeData", "Lsun/util/resources/LocaleData;", nullptr, $PRIVATE | $FINAL, $field(LocaleResources, localeData)},
	{"type", "Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PRIVATE | $FINAL, $field(LocaleResources, type)},
	{"cache", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Lsun/util/locale/provider/LocaleResources$ResourceReference;>;", $PRIVATE | $FINAL, $field(LocaleResources, cache)},
	{"referenceQueue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(LocaleResources, referenceQueue)},
	{"BREAK_ITERATOR_INFO", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, BREAK_ITERATOR_INFO)},
	{"CALENDAR_DATA", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, CALENDAR_DATA)},
	{"COLLATION_DATA_CACHEKEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, COLLATION_DATA_CACHEKEY)},
	{"DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY)},
	{"CURRENCY_NAMES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, CURRENCY_NAMES)},
	{"LOCALE_NAMES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, LOCALE_NAMES)},
	{"TIME_ZONE_NAMES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, TIME_ZONE_NAMES)},
	{"ZONE_IDS_CACHEKEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, ZONE_IDS_CACHEKEY)},
	{"CALENDAR_NAMES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, CALENDAR_NAMES)},
	{"NUMBER_PATTERNS_CACHEKEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, NUMBER_PATTERNS_CACHEKEY)},
	{"COMPACT_NUMBER_PATTERNS_CACHEKEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, COMPACT_NUMBER_PATTERNS_CACHEKEY)},
	{"DATE_TIME_PATTERN", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, DATE_TIME_PATTERN)},
	{"RULES_CACHEKEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, RULES_CACHEKEY)},
	{"TZNB_EXCITY_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, TZNB_EXCITY_PREFIX)},
	{"NULLOBJECT", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, NULLOBJECT)},
	{"TRACE_ON", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LocaleResources, TRACE_ON)},
	{}
};

$MethodInfo _LocaleResources_MethodInfo_[] = {
	{"<init>", "(Lsun/util/locale/provider/ResourceBundleBasedAdapter;Ljava/util/Locale;)V", nullptr, 0, $method(LocaleResources, init$, void, $ResourceBundleBasedAdapter*, $Locale*)},
	{"getBreakIteratorInfo", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, 0, $virtualMethod(LocaleResources, getBreakIteratorInfo, $Object*, $String*)},
	{"getBreakIteratorResources", "(Ljava/lang/String;)[B", nullptr, 0, $virtualMethod(LocaleResources, getBreakIteratorResources, $bytes*, $String*)},
	{"getCNPatterns", "(Ljava/text/NumberFormat$Style;)[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getCNPatterns, $StringArray*, $NumberFormat$Style*)},
	{"getCalendarData", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getCalendarData, $String*, $String*)},
	{"getCalendarNames", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, 0, $virtualMethod(LocaleResources, getCalendarNames, $StringArray*, $String*)},
	{"getCollationData", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getCollationData, $String*)},
	{"getCurrencyName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getCurrencyName, $String*, $String*)},
	{"getDateTimePattern", "(IILjava/util/Calendar;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getDateTimePattern, $String*, int32_t, int32_t, $Calendar*)},
	{"getDateTimePattern", "(Ljava/lang/String;IILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(LocaleResources, getDateTimePattern, $String*, $String*, int32_t, int32_t, $String*)},
	{"getDateTimePattern", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(LocaleResources, getDateTimePattern, $String*, $String*, $String*, int32_t, $String*)},
	{"getDecimalFormatSymbolsData", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getDecimalFormatSymbolsData, $ObjectArray*)},
	{"getJavaTimeDateTimePattern", "(IILjava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getJavaTimeDateTimePattern, $String*, int32_t, int32_t, $String*)},
	{"getJavaTimeFormatData", "()Ljava/util/ResourceBundle;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getJavaTimeFormatData, $ResourceBundle*)},
	{"getJavaTimeNames", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, 0, $virtualMethod(LocaleResources, getJavaTimeNames, $StringArray*, $String*)},
	{"getLocaleName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getLocaleName, $String*, $String*)},
	{"getNumberPatterns", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getNumberPatterns, $StringArray*)},
	{"getNumberStrings", "(Ljava/util/ResourceBundle;Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE, $method(LocaleResources, getNumberStrings, $StringArray*, $ResourceBundle*, $String*)},
	{"getRules", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getRules, $StringArray*)},
	{"getTimeZoneNames", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LocaleResources, getTimeZoneNames, $Object*, $String*)},
	{"getZoneIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", 0, $virtualMethod(LocaleResources, getZoneIDs, $Set*)},
	{"getZoneStrings", "()[[Ljava/lang/String;", nullptr, 0, $virtualMethod(LocaleResources, getZoneStrings, $StringArray2*)},
	{"lambda$getZoneStrings$0", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LocaleResources, lambda$getZoneStrings$0, bool, $String*)},
	{"lambda$getZoneStrings$1", "(Ljava/util/Set;Lsun/util/resources/TimeZoneNamesBundle;Ljava/util/Set;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LocaleResources, lambda$getZoneStrings$1, void, $Set*, $TimeZoneNamesBundle*, $Set*, $String*)},
	{"removeEmptyReferences", "()V", nullptr, $PRIVATE, $method(LocaleResources, removeEmptyReferences, void)},
	{"trace", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(LocaleResources, trace, void, $String*, $ObjectArray*)},
	{}
};

$InnerClassInfo _LocaleResources_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.LocaleResources$ResourceReference", "sun.util.locale.provider.LocaleResources", "ResourceReference", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LocaleResources_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.LocaleResources",
	"java.lang.Object",
	nullptr,
	_LocaleResources_FieldInfo_,
	_LocaleResources_MethodInfo_,
	nullptr,
	nullptr,
	_LocaleResources_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.LocaleResources$ResourceReference"
};

$Object* allocate$LocaleResources($Class* clazz) {
	return $of($alloc(LocaleResources));
}

bool LocaleResources::$assertionsDisabled = false;
$String* LocaleResources::BREAK_ITERATOR_INFO = nullptr;
$String* LocaleResources::CALENDAR_DATA = nullptr;
$String* LocaleResources::COLLATION_DATA_CACHEKEY = nullptr;
$String* LocaleResources::DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY = nullptr;
$String* LocaleResources::CURRENCY_NAMES = nullptr;
$String* LocaleResources::LOCALE_NAMES = nullptr;
$String* LocaleResources::TIME_ZONE_NAMES = nullptr;
$String* LocaleResources::ZONE_IDS_CACHEKEY = nullptr;
$String* LocaleResources::CALENDAR_NAMES = nullptr;
$String* LocaleResources::NUMBER_PATTERNS_CACHEKEY = nullptr;
$String* LocaleResources::COMPACT_NUMBER_PATTERNS_CACHEKEY = nullptr;
$String* LocaleResources::DATE_TIME_PATTERN = nullptr;
$String* LocaleResources::RULES_CACHEKEY = nullptr;
$String* LocaleResources::TZNB_EXCITY_PREFIX = nullptr;
$Object* LocaleResources::NULLOBJECT = nullptr;
bool LocaleResources::TRACE_ON = false;

void LocaleResources::init$($ResourceBundleBasedAdapter* adapter, $Locale* locale) {
	$set(this, cache, $new($ConcurrentHashMap));
	$set(this, referenceQueue, $new($ReferenceQueue));
	$set(this, locale, locale);
	$set(this, localeData, $nc(adapter)->getLocaleData());
	$set(this, type, $nc(($cast($LocaleProviderAdapter, adapter)))->getAdapterType());
}

void LocaleResources::removeEmptyReferences() {
	$useLocalCurrentObjectStackCache();
	$var($Object, ref, nullptr);
	while (($assign(ref, $nc(this->referenceQueue)->poll())) != nullptr) {
		$nc(this->cache)->remove($($nc(($cast($LocaleResources$ResourceReference, ref)))->getCacheKey()));
	}
}

$Object* LocaleResources::getBreakIteratorInfo($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, biInfo, nullptr);
	$var($String, cacheKey, $str({LocaleResources::BREAK_ITERATOR_INFO, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data == nullptr || (($assign(biInfo, $nc(data)->get())) == nullptr)) {
		$assign(biInfo, $nc($($nc(this->localeData)->getBreakIteratorInfo(this->locale)))->getObject(key));
		$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, biInfo, this->referenceQueue));
	}
	return $of(biInfo);
}

$bytes* LocaleResources::getBreakIteratorResources($String* key) {
	return $cast($bytes, $nc($($nc(this->localeData)->getBreakIteratorResources(this->locale)))->getObject(key));
}

$String* LocaleResources::getCalendarData($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($String, caldata, ""_s);
	$var($String, cacheKey, $str({LocaleResources::CALENDAR_DATA, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data == nullptr || (($assign(caldata, $cast($String, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, rb, $nc(this->localeData)->getCalendarData(this->locale));
		if ($nc(rb)->containsKey(key)) {
			$assign(caldata, rb->getString(key));
		}
		$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, caldata, this->referenceQueue));
	}
	return caldata;
}

$String* LocaleResources::getCollationData() {
	$useLocalCurrentObjectStackCache();
	$var($String, key, "Rule"_s);
	$var($String, coldata, ""_s);
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(LocaleResources::COLLATION_DATA_CACHEKEY)));
	if (data == nullptr || (($assign(coldata, $cast($String, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, rb, $nc(this->localeData)->getCollationData(this->locale));
		if ($nc(rb)->containsKey(key)) {
			$assign(coldata, rb->getString(key));
		}
		$nc(this->cache)->put(LocaleResources::COLLATION_DATA_CACHEKEY, $$new($LocaleResources$ResourceReference, LocaleResources::COLLATION_DATA_CACHEKEY, coldata, this->referenceQueue));
	}
	return coldata;
}

$ObjectArray* LocaleResources::getDecimalFormatSymbolsData() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, dfsdata, nullptr);
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(LocaleResources::DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY)));
	if (data == nullptr || (($assign(dfsdata, $cast($ObjectArray, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, rb, $nc(this->localeData)->getNumberFormatData(this->locale));
		$assign(dfsdata, $new($ObjectArray, 3));
		dfsdata->set(0, $(getNumberStrings(rb, "NumberElements"_s)));
		$nc(this->cache)->put(LocaleResources::DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY, $$new($LocaleResources$ResourceReference, LocaleResources::DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY, dfsdata, this->referenceQueue));
	}
	return dfsdata;
}

$StringArray* LocaleResources::getNumberStrings($ResourceBundle* rb, $String* type) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, ret, nullptr);
	$var($String, key, nullptr);
	$var($String, numSys, nullptr);
	$assign(numSys, $nc(this->locale)->getUnicodeLocaleType("nu"_s));
	if (numSys != nullptr) {
		$assign(key, $str({numSys, "."_s, type}));
		if ($nc(rb)->containsKey(key)) {
			$assign(ret, rb->getStringArray(key));
		}
	}
	if (ret == nullptr && $nc(rb)->containsKey("DefaultNumberingSystem"_s)) {
		$assign(key, $str({$(rb->getString("DefaultNumberingSystem"_s)), "."_s, type}));
		if (rb->containsKey(key)) {
			$assign(ret, rb->getStringArray(key));
		}
	}
	if (ret == nullptr) {
		$assign(ret, $nc(rb)->getStringArray(type));
	}
	return ret;
}

$String* LocaleResources::getCurrencyName($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, currencyName, nullptr);
	$var($String, cacheKey, $str({LocaleResources::CURRENCY_NAMES, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data != nullptr && (($assign(currencyName, data->get())) != nullptr)) {
		if ($nc($of(currencyName))->equals(LocaleResources::NULLOBJECT)) {
			$assign(currencyName, nullptr);
		}
		return $cast($String, currencyName);
	}
	$var($OpenListResourceBundle, olrb, $nc(this->localeData)->getCurrencyNames(this->locale));
	if ($nc(olrb)->containsKey(key)) {
		$assign(currencyName, olrb->getObject(key));
		$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, currencyName, this->referenceQueue));
	}
	return $cast($String, currencyName);
}

$String* LocaleResources::getLocaleName($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, localeName, nullptr);
	$var($String, cacheKey, $str({LocaleResources::LOCALE_NAMES, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data != nullptr && (($assign(localeName, data->get())) != nullptr)) {
		if ($nc($of(localeName))->equals(LocaleResources::NULLOBJECT)) {
			$assign(localeName, nullptr);
		}
		return $cast($String, localeName);
	}
	$var($OpenListResourceBundle, olrb, $nc(this->localeData)->getLocaleNames(this->locale));
	if ($nc(olrb)->containsKey(key)) {
		$assign(localeName, olrb->getObject(key));
		$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, localeName, this->referenceQueue));
	}
	return $cast($String, localeName);
}

$Object* LocaleResources::getTimeZoneNames($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, val, nullptr);
	$var($String, cacheKey, $str({LocaleResources::TIME_ZONE_NAMES, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	bool var$0 = $Objects::isNull(data);
	if (var$0 || $Objects::isNull($assign(val, $nc(data)->get()))) {
		$var($TimeZoneNamesBundle, tznb, $nc(this->localeData)->getTimeZoneNames(this->locale));
		if ($nc(key)->startsWith(LocaleResources::TZNB_EXCITY_PREFIX)) {
			if ($nc(tznb)->containsKey(key)) {
				$assign(val, tznb->getString(key));
				if (!LocaleResources::$assertionsDisabled && !$instanceOf($String, val)) {
					$throwNew($AssertionError);
				}
				trace("tznb: %s key: %s, val: %s\n"_s, $$new($ObjectArray, {
					$of(tznb),
					$of(key),
					val
				}));
			}
		} else {
			$var($StringArray, names, nullptr);
			if ($nc(tznb)->containsKey(key)) {
				$assign(names, tznb->getStringArray(key));
			} else {
				$var($String, tz, $cast($String, $nc($($TimeZoneNameUtility::canonicalTZID(key)))->orElse(key)));
				if (tznb->containsKey(tz)) {
					$assign(names, tznb->getStringArray(tz));
				}
			}
			if (names != nullptr) {
				names->set(0, key);
				trace("tznb: %s key: %s, names: %s, %s, %s, %s, %s, %s, %s\n"_s, $$new($ObjectArray, {
					$of(tznb),
					$of(key),
					$of(names->get(0)),
					$of(names->get(1)),
					$of(names->get(2)),
					$of(names->get(3)),
					$of(names->get(4)),
					$of(names->get(5)),
					$of(names->get(6))
				}));
				$assign(val, names);
			}
		}
		if (val != nullptr) {
			$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, val, this->referenceQueue));
		}
	}
	return $of(val);
}

$Set* LocaleResources::getZoneIDs() {
	$useLocalCurrentObjectStackCache();
	$var($Set, zoneIDs, nullptr);
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(LocaleResources::ZONE_IDS_CACHEKEY)));
	if (data == nullptr || (($assign(zoneIDs, $cast($Set, $nc(data)->get()))) == nullptr)) {
		$var($TimeZoneNamesBundle, rb, $nc(this->localeData)->getTimeZoneNames(this->locale));
		$assign(zoneIDs, $nc(rb)->keySet());
		$nc(this->cache)->put(LocaleResources::ZONE_IDS_CACHEKEY, $$new($LocaleResources$ResourceReference, LocaleResources::ZONE_IDS_CACHEKEY, zoneIDs, this->referenceQueue));
	}
	return zoneIDs;
}

$StringArray2* LocaleResources::getZoneStrings() {
	$useLocalCurrentObjectStackCache();
	$var($TimeZoneNamesBundle, rb, $nc(this->localeData)->getTimeZoneNames(this->locale));
	$var($Set, keyset, getZoneIDs());
	$var($Set, value, $new($LinkedHashSet));
	$var($Set, tzIds, $new($HashSet, $(static_cast<$Collection*>($Arrays::asList($($TimeZone::getAvailableIDs()))))));
	{
		$var($Iterator, i$, $nc(keyset)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, key, $cast($String, i$->next()));
			{
				if (!$nc(key)->startsWith(LocaleResources::TZNB_EXCITY_PREFIX)) {
					value->add($($nc(rb)->getStringArray(key)));
					tzIds->remove(key);
				}
			}
		}
	}
	$init($LocaleProviderAdapter$Type);
	if (this->type == $LocaleProviderAdapter$Type::CLDR) {
		$nc($($nc($(tzIds->stream()))->filter(static_cast<$Predicate*>($$new(LocaleResources$$Lambda$lambda$getZoneStrings$0)))))->forEach(static_cast<$Consumer*>($$new(LocaleResources$$Lambda$lambda$getZoneStrings$1$1, keyset, rb, value)));
	}
	return $fcast($StringArray2, value->toArray($$new($StringArray2, 0)));
}

$StringArray* LocaleResources::getCalendarNames($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, names, nullptr);
	$var($String, cacheKey, $str({LocaleResources::CALENDAR_NAMES, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data == nullptr || (($assign(names, $cast($StringArray, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, rb, $nc(this->localeData)->getDateFormatData(this->locale));
		if ($nc(rb)->containsKey(key)) {
			$assign(names, rb->getStringArray(key));
			$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, names, this->referenceQueue));
		}
	}
	return names;
}

$StringArray* LocaleResources::getJavaTimeNames($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, names, nullptr);
	$var($String, cacheKey, $str({LocaleResources::CALENDAR_NAMES, key}));
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data == nullptr || (($assign(names, $cast($StringArray, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, rb, getJavaTimeFormatData());
		if ($nc(rb)->containsKey(key)) {
			$assign(names, rb->getStringArray(key));
			$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, names, this->referenceQueue));
		}
	}
	return names;
}

$String* LocaleResources::getDateTimePattern(int32_t timeStyle, int32_t dateStyle, $Calendar* cal$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Calendar, cal, cal$renamed);
	if (cal == nullptr) {
		$assign(cal, $Calendar::getInstance(this->locale));
	}
	return getDateTimePattern(($String*)nullptr, timeStyle, dateStyle, $($nc(cal)->getCalendarType()));
}

$String* LocaleResources::getJavaTimeDateTimePattern(int32_t timeStyle, int32_t dateStyle, $String* calType$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, calType, calType$renamed);
	$assign(calType, $CalendarDataUtility::normalizeCalendarType(calType));
	$var($String, pattern, nullptr);
	$assign(pattern, getDateTimePattern("java.time."_s, timeStyle, dateStyle, calType));
	if (pattern == nullptr) {
		$assign(pattern, getDateTimePattern(($String*)nullptr, timeStyle, dateStyle, calType));
	}
	return pattern;
}

$String* LocaleResources::getDateTimePattern($String* prefix, int32_t timeStyle, int32_t dateStyle, $String* calType) {
	$useLocalCurrentObjectStackCache();
	$var($String, pattern, nullptr);
	$var($String, timePattern, nullptr);
	$var($String, datePattern, nullptr);
	if (timeStyle >= 0) {
		if (prefix != nullptr) {
			$assign(timePattern, getDateTimePattern(prefix, "TimePatterns"_s, timeStyle, calType));
		}
		if (timePattern == nullptr) {
			$assign(timePattern, getDateTimePattern(($String*)nullptr, "TimePatterns"_s, timeStyle, calType));
		}
	}
	if (dateStyle >= 0) {
		if (prefix != nullptr) {
			$assign(datePattern, getDateTimePattern(prefix, "DatePatterns"_s, dateStyle, calType));
		}
		if (datePattern == nullptr) {
			$assign(datePattern, getDateTimePattern(($String*)nullptr, "DatePatterns"_s, dateStyle, calType));
		}
	}
	if (timeStyle >= 0) {
		if (dateStyle >= 0) {
			$var($String, dateTimePattern, nullptr);
			int32_t dateTimeStyle = $Math::max(dateStyle, timeStyle);
			if (prefix != nullptr) {
				$assign(dateTimePattern, getDateTimePattern(prefix, "DateTimePatterns"_s, dateTimeStyle, calType));
			}
			if (dateTimePattern == nullptr) {
				$assign(dateTimePattern, getDateTimePattern(($String*)nullptr, "DateTimePatterns"_s, dateTimeStyle, calType));
			}
			$var($String, s17321$, $cast($String, $Objects::requireNonNull(dateTimePattern)));
			int32_t tmp17321$ = -1;
			switch ($nc(s17321$)->hashCode()) {
			case (int32_t)0xC52DC88F:
				{
					if (s17321$->equals("{1} {0}"_s)) {
						tmp17321$ = 0;
					}
					break;
				}
			case (int32_t)0xC378F00F:
				{
					if (s17321$->equals("{0} {1}"_s)) {
						tmp17321$ = 1;
					}
					break;
				}
			}

			$var($String, var$0, nullptr)
			switch (tmp17321$) {
			case 0:
				{
					$assign(var$0, $str({datePattern, " "_s, timePattern}));
					break;
				}
			case 1:
				{
					$assign(var$0, $str({timePattern, " "_s, datePattern}));
					break;
				}
			default:
				{
					$assign(var$0, $MessageFormat::format($($nc(dateTimePattern)->replaceAll("\'"_s, "\'\'"_s)), $$new($ObjectArray, {
						$of(timePattern),
						$of(datePattern)
					})));
					break;
				}
			}
			$assign(pattern, var$0);
		} else {
			$assign(pattern, timePattern);
		}
	} else if (dateStyle >= 0) {
		$assign(pattern, datePattern);
	} else {
		$throwNew($IllegalArgumentException, "No date or time style specified"_s);
	}
	return pattern;
}

$StringArray* LocaleResources::getNumberPatterns() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, numberPatterns, nullptr);
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(LocaleResources::NUMBER_PATTERNS_CACHEKEY)));
	if (data == nullptr || (($assign(numberPatterns, $cast($StringArray, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, resource, $nc(this->localeData)->getNumberFormatData(this->locale));
		$assign(numberPatterns, getNumberStrings(resource, "NumberPatterns"_s));
		$nc(this->cache)->put(LocaleResources::NUMBER_PATTERNS_CACHEKEY, $$new($LocaleResources$ResourceReference, LocaleResources::NUMBER_PATTERNS_CACHEKEY, numberPatterns, this->referenceQueue));
	}
	return numberPatterns;
}

$StringArray* LocaleResources::getCNPatterns($NumberFormat$Style* formatStyle) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(formatStyle);
	$var($StringArray, compactNumberPatterns, nullptr);
	removeEmptyReferences();
	$init($NumberFormat$Style);
	$var($String, width, (formatStyle == $NumberFormat$Style::LONG) ? "long"_s : "short"_s);
	$var($String, cacheKey, $str({width, "."_s, LocaleResources::COMPACT_NUMBER_PATTERNS_CACHEKEY}));
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	if (data == nullptr || (($assign(compactNumberPatterns, $cast($StringArray, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, resource, $nc(this->localeData)->getNumberFormatData(this->locale));
		$assign(compactNumberPatterns, $cast($StringArray, $nc(resource)->getObject($$str({width, ".CompactNumberPatterns"_s}))));
		$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, compactNumberPatterns, this->referenceQueue));
	}
	return compactNumberPatterns;
}

$ResourceBundle* LocaleResources::getJavaTimeFormatData() {
	$var($ResourceBundle, rb, $nc(this->localeData)->getDateFormatData(this->locale));
	if ($instanceOf($ParallelListResourceBundle, rb)) {
		$nc(this->localeData)->setSupplementary($cast($ParallelListResourceBundle, rb));
	}
	return rb;
}

$String* LocaleResources::getDateTimePattern($String* prefix, $String* key, int32_t styleIndex, $String* calendarType) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (prefix != nullptr) {
		sb->append(prefix);
	}
	if (!"gregory"_s->equals(calendarType)) {
		sb->append(calendarType)->append(u'.');
	}
	sb->append(key);
	$var($String, resourceKey, sb->toString());
	$var($String, cacheKey, $nc(sb->insert(0, LocaleResources::DATE_TIME_PATTERN))->toString());
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(cacheKey)));
	$var($Object, value, LocaleResources::NULLOBJECT);
	if (data == nullptr || (($assign(value, $nc(data)->get())) == nullptr)) {
		$var($ResourceBundle, r, (prefix != nullptr) ? getJavaTimeFormatData() : $nc(this->localeData)->getDateFormatData(this->locale));
		if ($nc(r)->containsKey(resourceKey)) {
			$assign(value, r->getStringArray(resourceKey));
		} else {
			if (!LocaleResources::$assertionsDisabled && ! !$nc(resourceKey)->equals(key)) {
				$throwNew($AssertionError);
			}
			if (r->containsKey(key)) {
				$assign(value, r->getStringArray(key));
			}
		}
		$nc(this->cache)->put(cacheKey, $$new($LocaleResources$ResourceReference, cacheKey, value, this->referenceQueue));
	}
	if ($equals(value, LocaleResources::NULLOBJECT)) {
		if (!LocaleResources::$assertionsDisabled && !(prefix != nullptr)) {
			$throwNew($AssertionError);
		}
		return nullptr;
	}
	$var($StringArray, styles, $cast($StringArray, value));
	return ($nc(styles)->length > 1 ? $nc(styles)->get(styleIndex) : styles->get(0));
}

$StringArray* LocaleResources::getRules() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, rules, nullptr);
	removeEmptyReferences();
	$var($LocaleResources$ResourceReference, data, $cast($LocaleResources$ResourceReference, $nc(this->cache)->get(LocaleResources::RULES_CACHEKEY)));
	if (data == nullptr || (($assign(rules, $cast($StringArray, $nc(data)->get()))) == nullptr)) {
		$var($ResourceBundle, rb, $nc(this->localeData)->getDateFormatData(this->locale));
		$assign(rules, $new($StringArray, 2));
		rules->set(0, rules->set(1, ""_s));
		if ($nc(rb)->containsKey("PluralRules"_s)) {
			rules->set(0, $(rb->getString("PluralRules"_s)));
		}
		if ($nc(rb)->containsKey("DayPeriodRules"_s)) {
			rules->set(1, $(rb->getString("DayPeriodRules"_s)));
		}
		$nc(this->cache)->put(LocaleResources::RULES_CACHEKEY, $$new($LocaleResources$ResourceReference, LocaleResources::RULES_CACHEKEY, rules, this->referenceQueue));
	}
	return rules;
}

void LocaleResources::trace($String* format, $ObjectArray* params) {
	$init(LocaleResources);
	if (LocaleResources::TRACE_ON) {
		$nc($System::out)->format(format, params);
	}
}

void LocaleResources::lambda$getZoneStrings$1($Set* keyset, $TimeZoneNamesBundle* rb, $Set* value, $String* tzid) {
	$init(LocaleResources);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, val, $new($StringArray, 7));
	if ($nc(keyset)->contains(tzid)) {
		$assign(val, $nc(rb)->getStringArray(tzid));
	} else {
		$var($String, canonID, $cast($String, $nc($($TimeZoneNameUtility::canonicalTZID(tzid)))->orElse(tzid)));
		if (keyset->contains(canonID)) {
			$assign(val, $nc(rb)->getStringArray(canonID));
		}
	}
	val->set(0, tzid);
	$nc(value)->add(val);
}

bool LocaleResources::lambda$getZoneStrings$0($String* i) {
	$init(LocaleResources);
	bool var$1 = !$nc(i)->startsWith("Etc/GMT"_s);
	bool var$0 = var$1 && !i->startsWith("GMT"_s);
	return (var$0 && !i->startsWith("SystemV"_s));
}

void clinit$LocaleResources($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(LocaleResources::BREAK_ITERATOR_INFO, "BII."_s);
	$assignStatic(LocaleResources::CALENDAR_DATA, "CALD."_s);
	$assignStatic(LocaleResources::COLLATION_DATA_CACHEKEY, "COLD"_s);
	$assignStatic(LocaleResources::DECIMAL_FORMAT_SYMBOLS_DATA_CACHEKEY, "DFSD"_s);
	$assignStatic(LocaleResources::CURRENCY_NAMES, "CN."_s);
	$assignStatic(LocaleResources::LOCALE_NAMES, "LN."_s);
	$assignStatic(LocaleResources::TIME_ZONE_NAMES, "TZN."_s);
	$assignStatic(LocaleResources::ZONE_IDS_CACHEKEY, "ZID"_s);
	$assignStatic(LocaleResources::CALENDAR_NAMES, "CALN."_s);
	$assignStatic(LocaleResources::NUMBER_PATTERNS_CACHEKEY, "NP"_s);
	$assignStatic(LocaleResources::COMPACT_NUMBER_PATTERNS_CACHEKEY, "CNP"_s);
	$assignStatic(LocaleResources::DATE_TIME_PATTERN, "DTP."_s);
	$assignStatic(LocaleResources::RULES_CACHEKEY, "RULE"_s);
	$assignStatic(LocaleResources::TZNB_EXCITY_PREFIX, "timezone.excity."_s);
	LocaleResources::$assertionsDisabled = !LocaleResources::class$->desiredAssertionStatus();
	$assignStatic(LocaleResources::NULLOBJECT, $new($Object));
	LocaleResources::TRACE_ON = $nc($($Boolean::valueOf($($GetPropertyAction::privilegedGetProperty("locale.resources.debug"_s, "false"_s)))))->booleanValue();
}

LocaleResources::LocaleResources() {
}

$Class* LocaleResources::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LocaleResources$$Lambda$lambda$getZoneStrings$0::classInfo$.name)) {
			return LocaleResources$$Lambda$lambda$getZoneStrings$0::load$(name, initialize);
		}
		if (name->equals(LocaleResources$$Lambda$lambda$getZoneStrings$1$1::classInfo$.name)) {
			return LocaleResources$$Lambda$lambda$getZoneStrings$1$1::load$(name, initialize);
		}
	}
	$loadClass(LocaleResources, name, initialize, &_LocaleResources_ClassInfo_, clinit$LocaleResources, allocate$LocaleResources);
	return class$;
}

$Class* LocaleResources::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun