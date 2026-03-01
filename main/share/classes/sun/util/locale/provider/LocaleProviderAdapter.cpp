#include <sun/util/locale/provider/LocaleProviderAdapter.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/text/spi/BreakIteratorProvider.h>
#include <java/text/spi/CollatorProvider.h>
#include <java/text/spi/DateFormatProvider.h>
#include <java/text/spi/DateFormatSymbolsProvider.h>
#include <java/text/spi/DecimalFormatSymbolsProvider.h>
#include <java/text/spi/NumberFormatProvider.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/ResourceBundle$Control.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/spi/CalendarDataProvider.h>
#include <java/util/spi/CalendarNameProvider.h>
#include <java/util/spi/CurrencyNameProvider.h>
#include <java/util/spi/LocaleNameProvider.h>
#include <java/util/spi/LocaleServiceProvider.h>
#include <java/util/spi/TimeZoneNameProvider.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/text/spi/JavaTimeDateTimePatternProvider.h>
#include <sun/util/locale/provider/JRELocaleConstants.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$1.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/spi/CalendarProvider.h>
#include <jcpp.h>

#undef CLDR
#undef FALLBACK
#undef FORMAT_DEFAULT
#undef INFO
#undef JA_JP_JP
#undef JRE
#undef ROOT
#undef TH_TH_TH

using $LocaleArray = $Array<::java::util::Locale>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $BreakIteratorProvider = ::java::text::spi::BreakIteratorProvider;
using $CollatorProvider = ::java::text::spi::CollatorProvider;
using $DateFormatProvider = ::java::text::spi::DateFormatProvider;
using $DateFormatSymbolsProvider = ::java::text::spi::DateFormatSymbolsProvider;
using $DecimalFormatSymbolsProvider = ::java::text::spi::DecimalFormatSymbolsProvider;
using $NumberFormatProvider = ::java::text::spi::NumberFormatProvider;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $ResourceBundle$Control = ::java::util::ResourceBundle$Control;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDataProvider = ::java::util::spi::CalendarDataProvider;
using $CalendarNameProvider = ::java::util::spi::CalendarNameProvider;
using $CurrencyNameProvider = ::java::util::spi::CurrencyNameProvider;
using $LocaleNameProvider = ::java::util::spi::LocaleNameProvider;
using $LocaleServiceProvider = ::java::util::spi::LocaleServiceProvider;
using $TimeZoneNameProvider = ::java::util::spi::TimeZoneNameProvider;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $JavaTimeDateTimePatternProvider = ::sun::text::spi::JavaTimeDateTimePatternProvider;
using $JRELocaleConstants = ::sun::util::locale::provider::JRELocaleConstants;
using $LocaleProviderAdapter$1 = ::sun::util::locale::provider::LocaleProviderAdapter$1;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $CalendarProvider = ::sun::util::spi::CalendarProvider;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _LocaleProviderAdapter_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LocaleProviderAdapter, $assertionsDisabled)},
	{"adapterPreference", "Ljava/util/List;", "Ljava/util/List<Lsun/util/locale/provider/LocaleProviderAdapter$Type;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LocaleProviderAdapter, adapterPreference)},
	{"adapterInstances", "Ljava/util/Map;", "Ljava/util/Map<Lsun/util/locale/provider/LocaleProviderAdapter$Type;Lsun/util/locale/provider/LocaleProviderAdapter;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LocaleProviderAdapter, adapterInstances)},
	{"defaultLocaleProviderAdapter", "Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $STATIC | $VOLATILE, $staticField(LocaleProviderAdapter, defaultLocaleProviderAdapter)},
	{"adapterCache", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Lsun/util/locale/provider/LocaleProviderAdapter;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LocaleProviderAdapter, adapterCache)},
	{}
};

$MethodInfo _LocaleProviderAdapter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LocaleProviderAdapter, init$, void)},
	{"findAdapter", "(Ljava/lang/Class;Ljava/util/Locale;)Lsun/util/locale/provider/LocaleProviderAdapter;", "(Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;Ljava/util/Locale;)Lsun/util/locale/provider/LocaleProviderAdapter;", $PRIVATE | $STATIC, $staticMethod(LocaleProviderAdapter, findAdapter, LocaleProviderAdapter*, $Class*, $Locale*)},
	{"forJRE", "()Lsun/util/locale/provider/LocaleProviderAdapter;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocaleProviderAdapter, forJRE, LocaleProviderAdapter*)},
	{"forType", "(Lsun/util/locale/provider/LocaleProviderAdapter$Type;)Lsun/util/locale/provider/LocaleProviderAdapter;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocaleProviderAdapter, forType, LocaleProviderAdapter*, $LocaleProviderAdapter$Type*)},
	{"getAdapter", "(Ljava/lang/Class;Ljava/util/Locale;)Lsun/util/locale/provider/LocaleProviderAdapter;", "(Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;Ljava/util/Locale;)Lsun/util/locale/provider/LocaleProviderAdapter;", $PUBLIC | $STATIC, $staticMethod(LocaleProviderAdapter, getAdapter, LocaleProviderAdapter*, $Class*, $Locale*)},
	{"getAdapterPreference", "()Ljava/util/List;", "()Ljava/util/List<Lsun/util/locale/provider/LocaleProviderAdapter$Type;>;", $PUBLIC | $STATIC, $staticMethod(LocaleProviderAdapter, getAdapterPreference, $List*)},
	{"getAdapterType", "()Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getAdapterType, $LocaleProviderAdapter$Type*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getAvailableLocales, $LocaleArray*)},
	{"getBreakIteratorProvider", "()Ljava/text/spi/BreakIteratorProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getBreakIteratorProvider, $BreakIteratorProvider*)},
	{"getCalendarDataProvider", "()Ljava/util/spi/CalendarDataProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getCalendarDataProvider, $CalendarDataProvider*)},
	{"getCalendarNameProvider", "()Ljava/util/spi/CalendarNameProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getCalendarNameProvider, $CalendarNameProvider*)},
	{"getCalendarProvider", "()Lsun/util/spi/CalendarProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getCalendarProvider, $CalendarProvider*)},
	{"getCollatorProvider", "()Ljava/text/spi/CollatorProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getCollatorProvider, $CollatorProvider*)},
	{"getCurrencyNameProvider", "()Ljava/util/spi/CurrencyNameProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getCurrencyNameProvider, $CurrencyNameProvider*)},
	{"getDateFormatProvider", "()Ljava/text/spi/DateFormatProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getDateFormatProvider, $DateFormatProvider*)},
	{"getDateFormatSymbolsProvider", "()Ljava/text/spi/DateFormatSymbolsProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getDateFormatSymbolsProvider, $DateFormatSymbolsProvider*)},
	{"getDecimalFormatSymbolsProvider", "()Ljava/text/spi/DecimalFormatSymbolsProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getDecimalFormatSymbolsProvider, $DecimalFormatSymbolsProvider*)},
	{"getJavaTimeDateTimePatternProvider", "()Lsun/text/spi/JavaTimeDateTimePatternProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getJavaTimeDateTimePatternProvider, $JavaTimeDateTimePatternProvider*)},
	{"getLocaleNameProvider", "()Ljava/util/spi/LocaleNameProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getLocaleNameProvider, $LocaleNameProvider*)},
	{"getLocaleResources", "(Ljava/util/Locale;)Lsun/util/locale/provider/LocaleResources;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getLocaleResources, $LocaleResources*, $Locale*)},
	{"getLocaleServiceProvider", "(Ljava/lang/Class;)Ljava/util/spi/LocaleServiceProvider;", "<P:Ljava/util/spi/LocaleServiceProvider;>(Ljava/lang/Class<TP;>;)TP;", $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getLocaleServiceProvider, $LocaleServiceProvider*, $Class*)},
	{"getNumberFormatProvider", "()Ljava/text/spi/NumberFormatProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getNumberFormatProvider, $NumberFormatProvider*)},
	{"getResourceBundleBased", "()Lsun/util/locale/provider/LocaleProviderAdapter;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocaleProviderAdapter, getResourceBundleBased, LocaleProviderAdapter*)},
	{"getTimeZoneNameProvider", "()Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleProviderAdapter, getTimeZoneNameProvider, $TimeZoneNameProvider*)},
	{"isSupportedProviderLocale", "(Ljava/util/Locale;Ljava/util/Set;)Z", "(Ljava/util/Locale;Ljava/util/Set<Ljava/lang/String;>;)Z", $PUBLIC, $virtualMethod(LocaleProviderAdapter, isSupportedProviderLocale, bool, $Locale*, $Set*)},
	{"toLocaleArray", "(Ljava/util/Set;)[Ljava/util/Locale;", "(Ljava/util/Set<Ljava/lang/String;>;)[Ljava/util/Locale;", $PUBLIC | $STATIC, $staticMethod(LocaleProviderAdapter, toLocaleArray, $LocaleArray*, $Set*)},
	{}
};

$InnerClassInfo _LocaleProviderAdapter_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.LocaleProviderAdapter$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.util.locale.provider.LocaleProviderAdapter$Type", "sun.util.locale.provider.LocaleProviderAdapter", "Type", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _LocaleProviderAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.util.locale.provider.LocaleProviderAdapter",
	"java.lang.Object",
	nullptr,
	_LocaleProviderAdapter_FieldInfo_,
	_LocaleProviderAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_LocaleProviderAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.LocaleProviderAdapter$1,sun.util.locale.provider.LocaleProviderAdapter$Type"
};

$Object* allocate$LocaleProviderAdapter($Class* clazz) {
	return $of($alloc(LocaleProviderAdapter));
}

bool LocaleProviderAdapter::$assertionsDisabled = false;
$List* LocaleProviderAdapter::adapterPreference = nullptr;
$Map* LocaleProviderAdapter::adapterInstances = nullptr;
$volatile($LocaleProviderAdapter$Type*) LocaleProviderAdapter::defaultLocaleProviderAdapter = nullptr;
$ConcurrentMap* LocaleProviderAdapter::adapterCache = nullptr;

void LocaleProviderAdapter::init$() {
}

LocaleProviderAdapter* LocaleProviderAdapter::forType($LocaleProviderAdapter$Type* type) {
	$init(LocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($LocaleProviderAdapter$1);
	{
		$var(LocaleProviderAdapter, adapter, nullptr)
		switch ($nc($LocaleProviderAdapter$1::$SwitchMap$sun$util$locale$provider$LocaleProviderAdapter$Type)->get($nc((type))->ordinal())) {
		case 1:
			{}
		case 2:
			{}
		case 3:
			{}
		case 4:
			{}
		case 5:
			{
				$assign(adapter, $cast(LocaleProviderAdapter, $nc(LocaleProviderAdapter::adapterInstances)->get(type)));
				if (adapter == nullptr) {
					try {
						$assign(adapter, $cast(LocaleProviderAdapter, $nc($($Class::forName($(type->getAdapterClassName()))->getDeclaredConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0))));
						$var(LocaleProviderAdapter, cached, $cast(LocaleProviderAdapter, $nc(LocaleProviderAdapter::adapterInstances)->putIfAbsent(type, adapter)));
						if (cached != nullptr) {
							$assign(adapter, cached);
						}
					} catch ($NoSuchMethodException& e) {
						$throwNew($ServiceConfigurationError, $$str({"Locale provider adapter \""_s, type, "\"cannot be instantiated."_s}), e);
					} catch ($InvocationTargetException& e) {
						$throwNew($ServiceConfigurationError, $$str({"Locale provider adapter \""_s, type, "\"cannot be instantiated."_s}), e);
					} catch ($ClassNotFoundException& e) {
						$throwNew($ServiceConfigurationError, $$str({"Locale provider adapter \""_s, type, "\"cannot be instantiated."_s}), e);
					} catch ($IllegalAccessException& e) {
						$throwNew($ServiceConfigurationError, $$str({"Locale provider adapter \""_s, type, "\"cannot be instantiated."_s}), e);
					} catch ($InstantiationException& e) {
						$throwNew($ServiceConfigurationError, $$str({"Locale provider adapter \""_s, type, "\"cannot be instantiated."_s}), e);
					} catch ($UnsupportedOperationException& e) {
						$throwNew($ServiceConfigurationError, $$str({"Locale provider adapter \""_s, type, "\"cannot be instantiated."_s}), e);
					}
				}
				return adapter;
			}
		default:
			{
				$throwNew($InternalError, "unknown locale data adapter type"_s);
			}
		}
	}
}

LocaleProviderAdapter* LocaleProviderAdapter::forJRE() {
	$init(LocaleProviderAdapter);
	$init($LocaleProviderAdapter$Type);
	return forType($LocaleProviderAdapter$Type::JRE);
}

LocaleProviderAdapter* LocaleProviderAdapter::getResourceBundleBased() {
	$init(LocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($(getAdapterPreference()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$LocaleProviderAdapter$Type* type = $cast($LocaleProviderAdapter$Type, i$->next());
			{
				$init($LocaleProviderAdapter$Type);
				if (type == $LocaleProviderAdapter$Type::JRE || type == $LocaleProviderAdapter$Type::CLDR || type == $LocaleProviderAdapter$Type::FALLBACK) {
					$var(LocaleProviderAdapter, adapter, forType(type));
					if (adapter != nullptr) {
						return adapter;
					}
				}
			}
		}
	}
	$throwNew($InternalError);
}

$List* LocaleProviderAdapter::getAdapterPreference() {
	$init(LocaleProviderAdapter);
	return LocaleProviderAdapter::adapterPreference;
}

LocaleProviderAdapter* LocaleProviderAdapter::getAdapter($Class* providerClass, $Locale* locale) {
	$init(LocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$var(LocaleProviderAdapter, adapter, nullptr);
	$var($ConcurrentMap, adapterMap, $cast($ConcurrentMap, $nc(LocaleProviderAdapter::adapterCache)->get(providerClass)));
	if (adapterMap != nullptr) {
		if (($assign(adapter, $cast(LocaleProviderAdapter, adapterMap->get(locale)))) != nullptr) {
			return adapter;
		}
	} else {
		$assign(adapterMap, $new($ConcurrentHashMap));
		$nc(LocaleProviderAdapter::adapterCache)->putIfAbsent(providerClass, adapterMap);
	}
	$assign(adapter, findAdapter(providerClass, locale));
	if (adapter != nullptr) {
		$nc(adapterMap)->putIfAbsent(locale, adapter);
		return adapter;
	}
	$init($ResourceBundle$Control);
	$var($List, lookupLocales, $nc($($ResourceBundle$Control::getControl($ResourceBundle$Control::FORMAT_DEFAULT)))->getCandidateLocales(""_s, locale));
	{
		$var($Iterator, i$, $nc(lookupLocales)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale, loc, $cast($Locale, i$->next()));
			{
				if ($nc(loc)->equals(locale)) {
					continue;
				}
				$assign(adapter, findAdapter(providerClass, loc));
				if (adapter != nullptr) {
					$nc(adapterMap)->putIfAbsent(locale, adapter);
					return adapter;
				}
			}
		}
	}
	$init($LocaleProviderAdapter$Type);
	$nc(adapterMap)->putIfAbsent(locale, $(forType($LocaleProviderAdapter$Type::FALLBACK)));
	return forType($LocaleProviderAdapter$Type::FALLBACK);
}

LocaleProviderAdapter* LocaleProviderAdapter::findAdapter($Class* providerClass, $Locale* locale) {
	$init(LocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($(getAdapterPreference()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$LocaleProviderAdapter$Type* type = $cast($LocaleProviderAdapter$Type, i$->next());
			{
				$var(LocaleProviderAdapter, adapter, forType(type));
				if (adapter != nullptr) {
					$var($LocaleServiceProvider, provider, adapter->getLocaleServiceProvider(providerClass));
					if (provider != nullptr) {
						if (provider->isSupportedLocale(locale)) {
							return adapter;
						}
					}
				}
			}
		}
	}
	return nullptr;
}

bool LocaleProviderAdapter::isSupportedProviderLocale($Locale* locale, $Set* langtags) {
	$LocaleProviderAdapter$Type* type = getAdapterType();
	$init($LocaleProviderAdapter$Type);
	if (!LocaleProviderAdapter::$assertionsDisabled && !(type == $LocaleProviderAdapter$Type::JRE || type == $LocaleProviderAdapter$Type::CLDR || type == $LocaleProviderAdapter$Type::FALLBACK)) {
		$throwNew($AssertionError);
	}
	return false;
}

$LocaleArray* LocaleProviderAdapter::toLocaleArray($Set* tags) {
	$init(LocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$var($LocaleArray, locs, $new($LocaleArray, $nc(tags)->size() + 1));
	int32_t index = 0;
	$init($Locale);
	locs->set(index++, $Locale::ROOT);
	{
		$var($Iterator, i$, tags->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, tag, $cast($String, i$->next()));
			{
				{
					$var($String, s12034$, tag);
					int32_t tmp12034$ = -1;
					switch ($nc(s12034$)->hashCode()) {
					case 0x5F7AF717:
						{
							if (s12034$->equals("ja-JP-JP"_s)) {
								tmp12034$ = 0;
							}
							break;
						}
					case (int32_t)0xE11B9FD4:
						{
							if (s12034$->equals("th-TH-TH"_s)) {
								tmp12034$ = 1;
							}
							break;
						}
					}
					switch (tmp12034$) {
					case 0:
						{
							$init($JRELocaleConstants);
							locs->set(index++, $JRELocaleConstants::JA_JP_JP);
							break;
						}
					case 1:
						{
							$init($JRELocaleConstants);
							locs->set(index++, $JRELocaleConstants::TH_TH_TH);
							break;
						}
					default:
						{
							locs->set(index++, $($Locale::forLanguageTag(tag)));
							break;
						}
					}
				}
			}
		}
	}
	return locs;
}

void clinit$LocaleProviderAdapter($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	LocaleProviderAdapter::$assertionsDisabled = !LocaleProviderAdapter::class$->desiredAssertionStatus();
	$assignStatic(LocaleProviderAdapter::adapterInstances, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$assignStatic(LocaleProviderAdapter::adapterCache, $new($ConcurrentHashMap));
	{
		$var($String, order, $GetPropertyAction::privilegedGetProperty("java.locale.providers"_s));
		$var($ArrayList, typeList, $new($ArrayList));
		$var($String, invalidTypeMessage, nullptr);
		if (order != nullptr && !order->isEmpty()) {
			$var($StringArray, types, order->split(","_s));
			{
				$var($StringArray, arr$, types);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, type, arr$->get(i$));
					{
						$init($Locale);
						$assign(type, $($nc(type)->trim())->toUpperCase($Locale::ROOT));
						if (type->equals("COMPAT"_s)) {
							$assign(type, "JRE"_s);
						}
						try {
							$LocaleProviderAdapter$Type* aType = $LocaleProviderAdapter$Type::valueOf($($(type->trim())->toUpperCase($Locale::ROOT)));
							if (!typeList->contains(aType)) {
								typeList->add(aType);
							}
						} catch ($IllegalArgumentException& e) {
							$assign(invalidTypeMessage, $str({"Invalid locale provider adapter \""_s, type, "\" ignored."_s}));
						}
					}
				}
			}
		}
		$init($LocaleProviderAdapter$Type);
		$assignStatic(LocaleProviderAdapter::defaultLocaleProviderAdapter, $LocaleProviderAdapter$Type::CLDR);
		if (!typeList->isEmpty()) {
			bool var$0 = typeList->contains($LocaleProviderAdapter$Type::CLDR);
			if (!(var$0 || typeList->contains($LocaleProviderAdapter$Type::JRE))) {
				typeList->add($LocaleProviderAdapter$Type::FALLBACK);
				$assignStatic(LocaleProviderAdapter::defaultLocaleProviderAdapter, $LocaleProviderAdapter$Type::FALLBACK);
			}
		} else {
			typeList->add($LocaleProviderAdapter$Type::CLDR);
			typeList->add($LocaleProviderAdapter$Type::JRE);
		}
		$assignStatic(LocaleProviderAdapter::adapterPreference, $Collections::unmodifiableList(typeList));
		if (invalidTypeMessage != nullptr) {
			$init($System$Logger$Level);
			$nc($($System::getLogger($(LocaleProviderAdapter::class$->getCanonicalName()))))->log($System$Logger$Level::INFO, invalidTypeMessage);
		}
	}
}

LocaleProviderAdapter::LocaleProviderAdapter() {
}

$Class* LocaleProviderAdapter::load$($String* name, bool initialize) {
	$loadClass(LocaleProviderAdapter, name, initialize, &_LocaleProviderAdapter_ClassInfo_, clinit$LocaleProviderAdapter, allocate$LocaleProviderAdapter);
	return class$;
}

$Class* LocaleProviderAdapter::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun