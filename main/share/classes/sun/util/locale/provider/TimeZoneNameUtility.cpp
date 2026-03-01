#include <sun/util/locale/provider/TimeZoneNameUtility.h>

#include <java/lang/ref/SoftReference.h>
#include <java/util/AbstractMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/spi/TimeZoneNameProvider.h>
#include <sun/util/cldr/CLDRLocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool$LocalizedObjectGetter.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <sun/util/locale/provider/TimeZoneNameProviderImpl.h>
#include <sun/util/locale/provider/TimeZoneNameUtility$TimeZoneNameGetter.h>
#include <jcpp.h>

#undef CLDR
#undef ENGLISH
#undef INSTANCE
#undef ROOT

using $StringArray2 = $Array<::java::lang::String, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $SoftReference = ::java::lang::ref::SoftReference;
using $AbstractMap = ::java::util::AbstractMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $TimeZoneNameProvider = ::java::util::spi::TimeZoneNameProvider;
using $CLDRLocaleProviderAdapter = ::sun::util::cldr::CLDRLocaleProviderAdapter;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;
using $LocaleServiceProviderPool$LocalizedObjectGetter = ::sun::util::locale::provider::LocaleServiceProviderPool$LocalizedObjectGetter;
using $TimeZoneNameProviderImpl = ::sun::util::locale::provider::TimeZoneNameProviderImpl;
using $TimeZoneNameUtility$TimeZoneNameGetter = ::sun::util::locale::provider::TimeZoneNameUtility$TimeZoneNameGetter;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _TimeZoneNameUtility_FieldInfo_[] = {
	{"cachedZoneData", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<[[Ljava/lang/String;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(TimeZoneNameUtility, cachedZoneData)},
	{"cachedDisplayNames", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/ref/SoftReference<Ljava/util/Map<Ljava/util/Locale;[Ljava/lang/String;>;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(TimeZoneNameUtility, cachedDisplayNames)},
	{}
};

$MethodInfo _TimeZoneNameUtility_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(TimeZoneNameUtility, init$, void)},
	{"canonicalTZID", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(TimeZoneNameUtility, canonicalTZID, $Optional*, $String*)},
	{"convertLDMLShortID", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(TimeZoneNameUtility, convertLDMLShortID, $Optional*, $String*)},
	{"getZoneStrings", "(Ljava/util/Locale;)[[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZoneNameUtility, getZoneStrings, $StringArray2*, $Locale*)},
	{"loadZoneStrings", "(Ljava/util/Locale;)[[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(TimeZoneNameUtility, loadZoneStrings, $StringArray2*, $Locale*)},
	{"retrieveDisplayName", "(Ljava/lang/String;ZILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZoneNameUtility, retrieveDisplayName, $String*, $String*, bool, int32_t, $Locale*)},
	{"retrieveDisplayNames", "(Ljava/lang/String;Ljava/util/Locale;)[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZoneNameUtility, retrieveDisplayNames, $StringArray*, $String*, $Locale*)},
	{"retrieveDisplayNamesImpl", "(Ljava/lang/String;Ljava/util/Locale;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(TimeZoneNameUtility, retrieveDisplayNamesImpl, $StringArray*, $String*, $Locale*)},
	{"retrieveGenericDisplayName", "(Ljava/lang/String;ILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(TimeZoneNameUtility, retrieveGenericDisplayName, $String*, $String*, int32_t, $Locale*)},
	{}
};

$InnerClassInfo _TimeZoneNameUtility_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.TimeZoneNameUtility$TimeZoneNameGetter", "sun.util.locale.provider.TimeZoneNameUtility", "TimeZoneNameGetter", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _TimeZoneNameUtility_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.util.locale.provider.TimeZoneNameUtility",
	"java.lang.Object",
	nullptr,
	_TimeZoneNameUtility_FieldInfo_,
	_TimeZoneNameUtility_MethodInfo_,
	nullptr,
	nullptr,
	_TimeZoneNameUtility_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.TimeZoneNameUtility$TimeZoneNameGetter"
};

$Object* allocate$TimeZoneNameUtility($Class* clazz) {
	return $of($alloc(TimeZoneNameUtility));
}

$ConcurrentHashMap* TimeZoneNameUtility::cachedZoneData = nullptr;
$Map* TimeZoneNameUtility::cachedDisplayNames = nullptr;

$StringArray2* TimeZoneNameUtility::getZoneStrings($Locale* locale) {
	$init(TimeZoneNameUtility);
	$useLocalCurrentObjectStackCache();
	$var($StringArray2, zones, nullptr);
	$var($SoftReference, data, $cast($SoftReference, $nc(TimeZoneNameUtility::cachedZoneData)->get(locale)));
	if (data == nullptr || (($assign(zones, $cast($StringArray2, $nc(data)->get()))) == nullptr)) {
		$assign(zones, loadZoneStrings(locale));
		$assign(data, $new($SoftReference, zones));
		$nc(TimeZoneNameUtility::cachedZoneData)->put(locale, data);
	}
	return zones;
}

$StringArray2* TimeZoneNameUtility::loadZoneStrings($Locale* locale) {
	$init(TimeZoneNameUtility);
	$useLocalCurrentObjectStackCache();
	$load($TimeZoneNameProvider);
	$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($TimeZoneNameProvider::class$, locale));
	$var($TimeZoneNameProvider, provider, $nc(adapter)->getTimeZoneNameProvider());
	if ($instanceOf($TimeZoneNameProviderImpl, provider)) {
		$var($StringArray2, zoneStrings, $nc(($cast($TimeZoneNameProviderImpl, provider)))->getZoneStrings(locale));
		$init($Locale);
		if ($nc(zoneStrings)->length == 0 && $nc(locale)->equals($Locale::ROOT)) {
			$assign(zoneStrings, getZoneStrings($Locale::ENGLISH));
		}
		return zoneStrings;
	}
	$var($Set, zoneIDs, $nc($($nc($($LocaleProviderAdapter::forJRE()))->getLocaleResources(locale)))->getZoneIDs());
	$var($List, zones, $new($LinkedList));
	{
		$var($Iterator, i$, $nc(zoneIDs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, key, $cast($String, i$->next()));
			{
				$var($StringArray, names, retrieveDisplayNamesImpl(key, locale));
				if (names != nullptr) {
					zones->add(names);
				}
			}
		}
	}
	$var($StringArray2, zonesArray, $new($StringArray2, zones->size()));
	return $fcast($StringArray2, zones->toArray(zonesArray));
}

$StringArray* TimeZoneNameUtility::retrieveDisplayNames($String* id, $Locale* locale) {
	$init(TimeZoneNameUtility);
	$Objects::requireNonNull(id);
	$Objects::requireNonNull(locale);
	return retrieveDisplayNamesImpl(id, locale);
}

$String* TimeZoneNameUtility::retrieveGenericDisplayName($String* id, int32_t style, $Locale* locale) {
	$init(TimeZoneNameUtility);
	$var($StringArray, names, retrieveDisplayNamesImpl(id, locale));
	if ($Objects::nonNull(names)) {
		return $nc(names)->get(6 - style);
	} else {
		return nullptr;
	}
}

$String* TimeZoneNameUtility::retrieveDisplayName($String* id, bool daylight, int32_t style, $Locale* locale) {
	$init(TimeZoneNameUtility);
	$var($StringArray, names, retrieveDisplayNamesImpl(id, locale));
	if ($Objects::nonNull(names)) {
		return $nc(names)->get((daylight ? 4 : 2) - style);
	} else {
		return nullptr;
	}
}

$Optional* TimeZoneNameUtility::convertLDMLShortID($String* shortID) {
	$init(TimeZoneNameUtility);
	return canonicalTZID(shortID);
}

$Optional* TimeZoneNameUtility::canonicalTZID($String* id) {
	$init(TimeZoneNameUtility);
	$init($LocaleProviderAdapter$Type);
	return $nc(($cast($CLDRLocaleProviderAdapter, $($LocaleProviderAdapter::forType($LocaleProviderAdapter$Type::CLDR)))))->canonicalTZID(id);
}

$StringArray* TimeZoneNameUtility::retrieveDisplayNamesImpl($String* id, $Locale* locale) {
	$init(TimeZoneNameUtility);
	$useLocalCurrentObjectStackCache();
	$load($TimeZoneNameProvider);
	$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($TimeZoneNameProvider::class$));
	$var($StringArray, names, nullptr);
	$var($Map, perLocale, nullptr);
	$var($SoftReference, ref, $cast($SoftReference, $nc(TimeZoneNameUtility::cachedDisplayNames)->get(id)));
	if ($Objects::nonNull(ref)) {
		$assign(perLocale, $cast($Map, $nc(ref)->get()));
		if ($Objects::nonNull(perLocale)) {
			$assign(names, $cast($StringArray, $nc(perLocale)->get(locale)));
			if ($Objects::nonNull(names)) {
				return names;
			}
		}
	}
	$assign(names, $new($StringArray, 7));
	names->set(0, id);
	for (int32_t i = 1; i <= 6; ++i) {
		$init($TimeZoneNameUtility$TimeZoneNameGetter);
		names->set(i, $cast($String, $($nc(pool)->getLocalizedObject($TimeZoneNameUtility$TimeZoneNameGetter::INSTANCE, locale, i < 5 ? (i < 3 ? "std"_s : "dst"_s) : "generic"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(i % 2))),
			$of(id)
		})))));
	}
	if ($Objects::isNull(perLocale)) {
		$assign(perLocale, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	}
	$nc(perLocale)->put(locale, names);
	$assign(ref, $new($SoftReference, perLocale));
	$nc(TimeZoneNameUtility::cachedDisplayNames)->put(id, ref);
	return names;
}

void TimeZoneNameUtility::init$() {
}

void clinit$TimeZoneNameUtility($Class* class$) {
	$assignStatic(TimeZoneNameUtility::cachedZoneData, $new($ConcurrentHashMap));
	$assignStatic(TimeZoneNameUtility::cachedDisplayNames, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
}

TimeZoneNameUtility::TimeZoneNameUtility() {
}

$Class* TimeZoneNameUtility::load$($String* name, bool initialize) {
	$loadClass(TimeZoneNameUtility, name, initialize, &_TimeZoneNameUtility_ClassInfo_, clinit$TimeZoneNameUtility, allocate$TimeZoneNameUtility);
	return class$;
}

$Class* TimeZoneNameUtility::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun