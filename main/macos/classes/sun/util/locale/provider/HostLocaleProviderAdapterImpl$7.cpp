#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$7.h>

#include <java/lang/Math.h>
#include <java/util/HashMap.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/spi/CalendarNameProvider.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl.h>
#include <jcpp.h>

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $CalendarNameProvider = ::java::util::spi::CalendarNameProvider;
using $HostLocaleProviderAdapterImpl = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$MethodInfo _HostLocaleProviderAdapterImpl$7_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(HostLocaleProviderAdapterImpl$7, init$, void)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$7, getAvailableLocales, $LocaleArray*)},
	{"getDisplayName", "(Ljava/lang/String;IIILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$7, getDisplayName, $String*, $String*, int32_t, int32_t, int32_t, $Locale*)},
	{"getDisplayNames", "(Ljava/lang/String;IILjava/util/Locale;)Ljava/util/Map;", "(Ljava/lang/String;IILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$7, getDisplayNames, $Map*, $String*, int32_t, int32_t, $Locale*)},
	{"isSupportedLocale", "(Ljava/util/Locale;)Z", nullptr, $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$7, isSupportedLocale, bool, $Locale*)},
	{}
};

$EnclosingMethodInfo _HostLocaleProviderAdapterImpl$7_EnclosingMethodInfo_ = {
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl",
	"getCalendarNameProvider",
	"()Ljava/util/spi/CalendarNameProvider;"
};

$InnerClassInfo _HostLocaleProviderAdapterImpl$7_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$7", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HostLocaleProviderAdapterImpl$7_ClassInfo_ = {
	$ACC_SUPER,
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl$7",
	"java.util.spi.CalendarNameProvider",
	nullptr,
	nullptr,
	_HostLocaleProviderAdapterImpl$7_MethodInfo_,
	nullptr,
	&_HostLocaleProviderAdapterImpl$7_EnclosingMethodInfo_,
	_HostLocaleProviderAdapterImpl$7_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl"
};

$Object* allocate$HostLocaleProviderAdapterImpl$7($Class* clazz) {
	return $of($alloc(HostLocaleProviderAdapterImpl$7));
}

void HostLocaleProviderAdapterImpl$7::init$() {
	$CalendarNameProvider::init$();
}

$LocaleArray* HostLocaleProviderAdapterImpl$7::getAvailableLocales() {
	return $HostLocaleProviderAdapterImpl::getSupportedCalendarLocales();
}

bool HostLocaleProviderAdapterImpl$7::isSupportedLocale($Locale* locale) {
	return $HostLocaleProviderAdapterImpl::isSupportedCalendarLocale(locale);
}

$String* HostLocaleProviderAdapterImpl$7::getDisplayName($String* calendarType, int32_t field, int32_t value, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, names, $HostLocaleProviderAdapterImpl::getCalendarDisplayStrings($($nc(locale)->toLanguageTag()), field, style));
	if (names != nullptr && value >= 0 && value < names->length) {
		return names->get(value);
	} else {
		return nullptr;
	}
}

$Map* HostLocaleProviderAdapterImpl$7::getDisplayNames($String* calendarType, int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, nullptr);
	$var($StringArray, names, $HostLocaleProviderAdapterImpl::getCalendarDisplayStrings($($nc(locale)->toLanguageTag()), field, style));
	if (names != nullptr) {
		$assign(map, $new($HashMap, $cast(int32_t, $Math::ceil(names->length / 0.75))));
		for (int32_t value = 0; value < names->length; ++value) {
			if (names->get(value) != nullptr) {
				map->put(names->get(value), $($Integer::valueOf(value)));
			}
		}
		$assign(map, map->isEmpty() ? ($Map*)nullptr : map);
	}
	return map;
}

HostLocaleProviderAdapterImpl$7::HostLocaleProviderAdapterImpl$7() {
}

$Class* HostLocaleProviderAdapterImpl$7::load$($String* name, bool initialize) {
	$loadClass(HostLocaleProviderAdapterImpl$7, name, initialize, &_HostLocaleProviderAdapterImpl$7_ClassInfo_, allocate$HostLocaleProviderAdapterImpl$7);
	return class$;
}

$Class* HostLocaleProviderAdapterImpl$7::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun