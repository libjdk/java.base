#include <sun/util/locale/provider/LocaleServiceProviderPool.h>

#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/text/spi/BreakIteratorProvider.h>
#include <java/text/spi/CollatorProvider.h>
#include <java/text/spi/DateFormatProvider.h>
#include <java/text/spi/DateFormatSymbolsProvider.h>
#include <java/text/spi/DecimalFormatSymbolsProvider.h>
#include <java/text/spi/NumberFormatProvider.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/IllformedLocaleException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale$Builder.h>
#include <java/util/Locale.h>
#include <java/util/ResourceBundle$Control.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/spi/CalendarDataProvider.h>
#include <java/util/spi/CurrencyNameProvider.h>
#include <java/util/spi/LocaleNameProvider.h>
#include <java/util/spi/LocaleServiceProvider.h>
#include <java/util/spi/TimeZoneNameProvider.h>
#include <sun/util/locale/provider/JRELocaleConstants.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool$AllAvailableLocales.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter.h>
#include <jcpp.h>

#undef FORMAT_DEFAULT
#undef INFO
#undef JA_JP_JP
#undef NULL_LIST
#undef TH_TH_TH

using $LocaleArray = $Array<::java::util::Locale>;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $BreakIteratorProvider = ::java::text::spi::BreakIteratorProvider;
using $CollatorProvider = ::java::text::spi::CollatorProvider;
using $DateFormatProvider = ::java::text::spi::DateFormatProvider;
using $DateFormatSymbolsProvider = ::java::text::spi::DateFormatSymbolsProvider;
using $DecimalFormatSymbolsProvider = ::java::text::spi::DecimalFormatSymbolsProvider;
using $NumberFormatProvider = ::java::text::spi::NumberFormatProvider;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $IllformedLocaleException = ::java::util::IllformedLocaleException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$Builder = ::java::util::Locale$Builder;
using $ResourceBundle$Control = ::java::util::ResourceBundle$Control;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDataProvider = ::java::util::spi::CalendarDataProvider;
using $CurrencyNameProvider = ::java::util::spi::CurrencyNameProvider;
using $LocaleNameProvider = ::java::util::spi::LocaleNameProvider;
using $LocaleServiceProvider = ::java::util::spi::LocaleServiceProvider;
using $TimeZoneNameProvider = ::java::util::spi::TimeZoneNameProvider;
using $JRELocaleConstants = ::sun::util::locale::provider::JRELocaleConstants;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleServiceProviderPool$AllAvailableLocales = ::sun::util::locale::provider::LocaleServiceProviderPool$AllAvailableLocales;
using $LocaleServiceProviderPool$LocalizedObjectGetter = ::sun::util::locale::provider::LocaleServiceProviderPool$LocalizedObjectGetter;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _LocaleServiceProviderPool_FieldInfo_[] = {
	{"poolOfPools", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;Lsun/util/locale/provider/LocaleServiceProviderPool;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LocaleServiceProviderPool, poolOfPools)},
	{"providersCache", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/util/List<Ljava/util/spi/LocaleServiceProvider;>;>;", $PRIVATE | $FINAL, $field(LocaleServiceProviderPool, providersCache)},
	{"availableLocales", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Locale;>;", $PRIVATE, $field(LocaleServiceProviderPool, availableLocales)},
	{"providerClass", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;", $PRIVATE | $FINAL, $field(LocaleServiceProviderPool, providerClass)},
	{"spiClasses", "[Ljava/lang/Class;", "[Ljava/lang/Class<Ljava/util/spi/LocaleServiceProvider;>;", $STATIC | $FINAL, $staticField(LocaleServiceProviderPool, spiClasses)},
	{"NULL_LIST", "Ljava/util/List;", "Ljava/util/List<Ljava/util/spi/LocaleServiceProvider;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LocaleServiceProviderPool, NULL_LIST)},
	{}
};

$MethodInfo _LocaleServiceProviderPool_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;)V", $PRIVATE, $method(LocaleServiceProviderPool, init$, void, $Class*)},
	{"findProviders", "(Ljava/util/Locale;Z)Ljava/util/List;", "(Ljava/util/Locale;Z)Ljava/util/List<Ljava/util/spi/LocaleServiceProvider;>;", $PRIVATE, $method(LocaleServiceProviderPool, findProviders, $List*, $Locale*, bool)},
	{"getAllAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(LocaleServiceProviderPool, getAllAvailableLocales, $LocaleArray*)},
	{"getAvailableLocaleSet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Locale;>;", $PRIVATE | $SYNCHRONIZED, $method(LocaleServiceProviderPool, getAvailableLocaleSet, $Set*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $method(LocaleServiceProviderPool, getAvailableLocales, $LocaleArray*)},
	{"getLocalizedObject", "(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter;Ljava/util/Locale;[Ljava/lang/Object;)Ljava/lang/Object;", "<P:Ljava/util/spi/LocaleServiceProvider;S:Ljava/lang/Object;>(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter<TP;TS;>;Ljava/util/Locale;[Ljava/lang/Object;)TS;", $PUBLIC | $TRANSIENT, $method(LocaleServiceProviderPool, getLocalizedObject, $Object*, $LocaleServiceProviderPool$LocalizedObjectGetter*, $Locale*, $ObjectArray*)},
	{"getLocalizedObject", "(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter;Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;", "<P:Ljava/util/spi/LocaleServiceProvider;S:Ljava/lang/Object;>(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter<TP;TS;>;Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)TS;", $PUBLIC | $TRANSIENT, $method(LocaleServiceProviderPool, getLocalizedObject, $Object*, $LocaleServiceProviderPool$LocalizedObjectGetter*, $Locale*, $String*, $ObjectArray*)},
	{"getLocalizedObject", "(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter;Ljava/util/Locale;Ljava/lang/Boolean;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;", "<P:Ljava/util/spi/LocaleServiceProvider;S:Ljava/lang/Object;>(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter<TP;TS;>;Ljava/util/Locale;Ljava/lang/Boolean;Ljava/lang/String;[Ljava/lang/Object;)TS;", $PUBLIC | $TRANSIENT, $method(LocaleServiceProviderPool, getLocalizedObject, $Object*, $LocaleServiceProviderPool$LocalizedObjectGetter*, $Locale*, $Boolean*, $String*, $ObjectArray*)},
	{"getLocalizedObjectImpl", "(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter;Ljava/util/Locale;ZLjava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;", "<P:Ljava/util/spi/LocaleServiceProvider;S:Ljava/lang/Object;>(Lsun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter<TP;TS;>;Ljava/util/Locale;ZLjava/lang/String;[Ljava/lang/Object;)TS;", $PRIVATE | $TRANSIENT, $method(LocaleServiceProviderPool, getLocalizedObjectImpl, $Object*, $LocaleServiceProviderPool$LocalizedObjectGetter*, $Locale*, bool, $String*, $ObjectArray*)},
	{"getLookupLocale", "(Ljava/util/Locale;)Ljava/util/Locale;", nullptr, $STATIC, $staticMethod(LocaleServiceProviderPool, getLookupLocale, $Locale*, $Locale*)},
	{"getLookupLocales", "(Ljava/util/Locale;)Ljava/util/List;", "(Ljava/util/Locale;)Ljava/util/List<Ljava/util/Locale;>;", $STATIC, $staticMethod(LocaleServiceProviderPool, getLookupLocales, $List*, $Locale*)},
	{"getPool", "(Ljava/lang/Class;)Lsun/util/locale/provider/LocaleServiceProviderPool;", "(Ljava/lang/Class<+Ljava/util/spi/LocaleServiceProvider;>;)Lsun/util/locale/provider/LocaleServiceProviderPool;", $PUBLIC | $STATIC, $staticMethod(LocaleServiceProviderPool, getPool, LocaleServiceProviderPool*, $Class*)},
	{}
};

$InnerClassInfo _LocaleServiceProviderPool_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.LocaleServiceProviderPool$LocalizedObjectGetter", "sun.util.locale.provider.LocaleServiceProviderPool", "LocalizedObjectGetter", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.locale.provider.LocaleServiceProviderPool$AllAvailableLocales", "sun.util.locale.provider.LocaleServiceProviderPool", "AllAvailableLocales", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LocaleServiceProviderPool_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.util.locale.provider.LocaleServiceProviderPool",
	"java.lang.Object",
	nullptr,
	_LocaleServiceProviderPool_FieldInfo_,
	_LocaleServiceProviderPool_MethodInfo_,
	nullptr,
	nullptr,
	_LocaleServiceProviderPool_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.LocaleServiceProviderPool$LocalizedObjectGetter,sun.util.locale.provider.LocaleServiceProviderPool$AllAvailableLocales"
};

$Object* allocate$LocaleServiceProviderPool($Class* clazz) {
	return $of($alloc(LocaleServiceProviderPool));
}

$ConcurrentMap* LocaleServiceProviderPool::poolOfPools = nullptr;
$ClassArray* LocaleServiceProviderPool::spiClasses = nullptr;
$List* LocaleServiceProviderPool::NULL_LIST = nullptr;

LocaleServiceProviderPool* LocaleServiceProviderPool::getPool($Class* providerClass) {
	$init(LocaleServiceProviderPool);
	$useLocalCurrentObjectStackCache();
	$var(LocaleServiceProviderPool, pool, $cast(LocaleServiceProviderPool, $nc(LocaleServiceProviderPool::poolOfPools)->get(providerClass)));
	if (pool == nullptr) {
		$var(LocaleServiceProviderPool, newPool, $new(LocaleServiceProviderPool, providerClass));
		$assign(pool, $cast(LocaleServiceProviderPool, $nc(LocaleServiceProviderPool::poolOfPools)->putIfAbsent(providerClass, newPool)));
		if (pool == nullptr) {
			$assign(pool, newPool);
		}
	}
	return pool;
}

void LocaleServiceProviderPool::init$($Class* c) {
	$set(this, providersCache, $new($ConcurrentHashMap));
	$set(this, availableLocales, nullptr);
	$set(this, providerClass, c);
}

$LocaleArray* LocaleServiceProviderPool::getAllAvailableLocales() {
	$init(LocaleServiceProviderPool);
	$init($LocaleServiceProviderPool$AllAvailableLocales);
	return $cast($LocaleArray, $nc($LocaleServiceProviderPool$AllAvailableLocales::allAvailableLocales)->clone());
}

$LocaleArray* LocaleServiceProviderPool::getAvailableLocales() {
	$useLocalCurrentObjectStackCache();
	$var($Set, locList, $new($HashSet));
	locList->addAll($(getAvailableLocaleSet()));
	locList->addAll($($Arrays::asList($($nc($($LocaleProviderAdapter::forJRE()))->getAvailableLocales()))));
	$var($LocaleArray, tmp, $new($LocaleArray, locList->size()));
	locList->toArray(tmp);
	return tmp;
}

$Set* LocaleServiceProviderPool::getAvailableLocaleSet() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->availableLocales == nullptr) {
			$set(this, availableLocales, $new($HashSet));
			{
				$var($Iterator, i$, $nc($($LocaleProviderAdapter::getAdapterPreference()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$LocaleProviderAdapter$Type* type = $cast($LocaleProviderAdapter$Type, i$->next());
					{
						$var($LocaleProviderAdapter, lda, $LocaleProviderAdapter::forType(type));
						if (lda != nullptr) {
							$var($LocaleServiceProvider, lsp, lda->getLocaleServiceProvider(this->providerClass));
							if (lsp != nullptr) {
								$var($LocaleArray, locales, lsp->getAvailableLocales());
								{
									$var($LocaleArray, arr$, locales);
									int32_t len$ = $nc(arr$)->length;
									int32_t i$ = 0;
									for (; i$ < len$; ++i$) {
										$var($Locale, locale, arr$->get(i$));
										{
											$nc(this->availableLocales)->add($(getLookupLocale(locale)));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return this->availableLocales;
	}
}

$Object* LocaleServiceProviderPool::getLocalizedObject($LocaleServiceProviderPool$LocalizedObjectGetter* getter, $Locale* locale, $ObjectArray* params) {
	return $of(getLocalizedObjectImpl(getter, locale, true, nullptr, params));
}

$Object* LocaleServiceProviderPool::getLocalizedObject($LocaleServiceProviderPool$LocalizedObjectGetter* getter, $Locale* locale, $String* key, $ObjectArray* params) {
	return $of(getLocalizedObjectImpl(getter, locale, false, key, params));
}

$Object* LocaleServiceProviderPool::getLocalizedObject($LocaleServiceProviderPool$LocalizedObjectGetter* getter, $Locale* locale, $Boolean* isObjectProvider, $String* key, $ObjectArray* params) {
	return $of(getLocalizedObjectImpl(getter, locale, $nc(isObjectProvider)->booleanValue(), key, params));
}

$Object* LocaleServiceProviderPool::getLocalizedObjectImpl($LocaleServiceProviderPool$LocalizedObjectGetter* getter, $Locale* locale, bool isObjectProvider, $String* key, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (locale == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($List, lookupLocales, getLookupLocales(locale));
	{
		$var($Iterator, i$, $nc(lookupLocales)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale, current, $cast($Locale, i$->next()));
			{
				$var($Object, providersObj, nullptr);
				{
					$var($Iterator, i$, $nc($(findProviders(current, isObjectProvider)))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($LocaleServiceProvider, lsp, $cast($LocaleServiceProvider, i$->next()));
						{
							$assign(providersObj, $nc(getter)->getObject(lsp, locale, key, params));
							if (providersObj != nullptr) {
								return $of(providersObj);
							} else if (isObjectProvider) {
								$init($System$Logger$Level);
								$nc($($System::getLogger($(LocaleServiceProviderPool::class$->getCanonicalName()))))->log($System$Logger$Level::INFO, $$str({"A locale sensitive service object provider returned null, which should not happen. Provider: "_s, lsp, " Locale: "_s, locale}));
							}
						}
					}
				}
			}
		}
	}
	return $of(nullptr);
}

$List* LocaleServiceProviderPool::findProviders($Locale* locale, bool isObjectProvider) {
	$useLocalCurrentObjectStackCache();
	$var($List, providersList, $cast($List, $nc(this->providersCache)->get(locale)));
	if (providersList == nullptr) {
		{
			$var($Iterator, i$, $nc($($LocaleProviderAdapter::getAdapterPreference()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$LocaleProviderAdapter$Type* type = $cast($LocaleProviderAdapter$Type, i$->next());
				{
					$var($LocaleProviderAdapter, lda, $LocaleProviderAdapter::forType(type));
					if (lda != nullptr) {
						$var($LocaleServiceProvider, lsp, lda->getLocaleServiceProvider(this->providerClass));
						if (lsp != nullptr) {
							if (lsp->isSupportedLocale(locale)) {
								if (providersList == nullptr) {
									$assign(providersList, $new($ArrayList, 2));
								}
								$nc(providersList)->add(lsp);
								if (isObjectProvider) {
									break;
								}
							}
						}
					}
				}
			}
		}
		if (providersList == nullptr) {
			$assign(providersList, LocaleServiceProviderPool::NULL_LIST);
		}
		$var($List, val, $cast($List, $nc(this->providersCache)->putIfAbsent(locale, providersList)));
		if (val != nullptr) {
			$assign(providersList, val);
		}
	}
	return providersList;
}

$List* LocaleServiceProviderPool::getLookupLocales($Locale* locale) {
	$init(LocaleServiceProviderPool);
	$init($ResourceBundle$Control);
	return $nc($($ResourceBundle$Control::getNoFallbackControl($ResourceBundle$Control::FORMAT_DEFAULT)))->getCandidateLocales(""_s, locale);
}

$Locale* LocaleServiceProviderPool::getLookupLocale($Locale* locale) {
	$init(LocaleServiceProviderPool);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Locale, lookupLocale, locale);
	bool var$1 = $nc(locale)->hasExtensions();
	$init($JRELocaleConstants);
	bool var$0 = var$1 && !locale->equals($JRELocaleConstants::JA_JP_JP);
	if (var$0 && !locale->equals($JRELocaleConstants::TH_TH_TH)) {
		$var($Locale$Builder, locbld, $new($Locale$Builder));
		try {
			locbld->setLocale(locale);
			locbld->clearExtensions();
			$assign(lookupLocale, locbld->build());
		} catch ($IllformedLocaleException& e) {
			$init($System$Logger$Level);
			$nc($($System::getLogger($(LocaleServiceProviderPool::class$->getCanonicalName()))))->log($System$Logger$Level::INFO, $$str({"A locale("_s, locale, ") has non-empty extensions, but has illformed fields."_s}));
			$var($String, var$2, locale->getLanguage());
			$var($String, var$3, locale->getCountry());
			$assign(lookupLocale, $new($Locale, var$2, var$3, $(locale->getVariant())));
		}
	}
	return lookupLocale;
}

void clinit$LocaleServiceProviderPool($Class* class$) {
	$assignStatic(LocaleServiceProviderPool::poolOfPools, $new($ConcurrentHashMap));
	$load($BreakIteratorProvider);
	$load($CollatorProvider);
	$load($DateFormatProvider);
	$load($DateFormatSymbolsProvider);
	$load($DecimalFormatSymbolsProvider);
	$load($NumberFormatProvider);
	$load($CurrencyNameProvider);
	$load($LocaleNameProvider);
	$load($TimeZoneNameProvider);
	$load($CalendarDataProvider);
	$assignStatic(LocaleServiceProviderPool::spiClasses, $new($ClassArray, {
		$BreakIteratorProvider::class$,
		$CollatorProvider::class$,
		$DateFormatProvider::class$,
		$DateFormatSymbolsProvider::class$,
		$DecimalFormatSymbolsProvider::class$,
		$NumberFormatProvider::class$,
		$CurrencyNameProvider::class$,
		$LocaleNameProvider::class$,
		$TimeZoneNameProvider::class$,
		$CalendarDataProvider::class$
	}));
	$assignStatic(LocaleServiceProviderPool::NULL_LIST, $Collections::emptyList());
}

LocaleServiceProviderPool::LocaleServiceProviderPool() {
}

$Class* LocaleServiceProviderPool::load$($String* name, bool initialize) {
	$loadClass(LocaleServiceProviderPool, name, initialize, &_LocaleServiceProviderPool_ClassInfo_, clinit$LocaleServiceProviderPool, allocate$LocaleServiceProviderPool);
	return class$;
}

$Class* LocaleServiceProviderPool::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun