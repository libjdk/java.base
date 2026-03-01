#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl$6.h>

#include <java/util/Calendar.h>
#include <java/util/HashMap.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/spi/CalendarNameProvider.h>
#include <sun/util/locale/provider/HostLocaleProviderAdapterImpl.h>
#include <jcpp.h>

#undef DAY_OF_WEEK

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Calendar = ::java::util::Calendar;
using $HashMap = ::java::util::HashMap;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $CalendarNameProvider = ::java::util::spi::CalendarNameProvider;
using $HostLocaleProviderAdapterImpl = ::sun::util::locale::provider::HostLocaleProviderAdapterImpl;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$MethodInfo _HostLocaleProviderAdapterImpl$6_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(HostLocaleProviderAdapterImpl$6, init$, void)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$6, getAvailableLocales, $LocaleArray*)},
	{"getDisplayName", "(Ljava/lang/String;IIILjava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$6, getDisplayName, $String*, $String*, int32_t, int32_t, int32_t, $Locale*)},
	{"getDisplayNames", "(Ljava/lang/String;IILjava/util/Locale;)Ljava/util/Map;", "(Ljava/lang/String;IILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$6, getDisplayNames, $Map*, $String*, int32_t, int32_t, $Locale*)},
	{"isSupportedLocale", "(Ljava/util/Locale;)Z", nullptr, $PUBLIC, $virtualMethod(HostLocaleProviderAdapterImpl$6, isSupportedLocale, bool, $Locale*)},
	{}
};

$EnclosingMethodInfo _HostLocaleProviderAdapterImpl$6_EnclosingMethodInfo_ = {
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl",
	"getCalendarNameProvider",
	"()Ljava/util/spi/CalendarNameProvider;"
};

$InnerClassInfo _HostLocaleProviderAdapterImpl$6_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.HostLocaleProviderAdapterImpl$6", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HostLocaleProviderAdapterImpl$6_ClassInfo_ = {
	$ACC_SUPER,
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl$6",
	"java.util.spi.CalendarNameProvider",
	nullptr,
	nullptr,
	_HostLocaleProviderAdapterImpl$6_MethodInfo_,
	nullptr,
	&_HostLocaleProviderAdapterImpl$6_EnclosingMethodInfo_,
	_HostLocaleProviderAdapterImpl$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.locale.provider.HostLocaleProviderAdapterImpl"
};

$Object* allocate$HostLocaleProviderAdapterImpl$6($Class* clazz) {
	return $of($alloc(HostLocaleProviderAdapterImpl$6));
}

void HostLocaleProviderAdapterImpl$6::init$() {
	$CalendarNameProvider::init$();
}

$LocaleArray* HostLocaleProviderAdapterImpl$6::getAvailableLocales() {
	return $HostLocaleProviderAdapterImpl::getSupportedCalendarLocales();
}

bool HostLocaleProviderAdapterImpl$6::isSupportedLocale($Locale* locale) {
	return $HostLocaleProviderAdapterImpl::isSupportedCalendarLocale(locale);
}

$String* HostLocaleProviderAdapterImpl$6::getDisplayName($String* calendarType, int32_t field, int32_t value, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc($($HostLocaleProviderAdapterImpl::removeExtensions(locale)))->toLanguageTag());
	$var($StringArray, names, $HostLocaleProviderAdapterImpl::getCalendarDisplayStrings(var$0, $HostLocaleProviderAdapterImpl::getCalendarIDFromLDMLType(calendarType), field, style));
	if (field == $Calendar::DAY_OF_WEEK) {
		--value;
	}
	if (names != nullptr && value >= 0 && value < names->length) {
		return names->get(value);
	} else {
		return nullptr;
	}
}

$Map* HostLocaleProviderAdapterImpl$6::getDisplayNames($String* calendarType, int32_t field, int32_t style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, nullptr);
	$var($String, var$0, $nc($($HostLocaleProviderAdapterImpl::removeExtensions(locale)))->toLanguageTag());
	$var($StringArray, names, $HostLocaleProviderAdapterImpl::getCalendarDisplayStrings(var$0, $HostLocaleProviderAdapterImpl::getCalendarIDFromLDMLType(calendarType), field, style));
	if (names != nullptr) {
		$assign(map, $new($HashMap));
		for (int32_t value = 0; value < names->length; ++value) {
			if (names->get(value) != nullptr) {
				map->put(names->get(value), $($Integer::valueOf(field == $Calendar::DAY_OF_WEEK ? value + 1 : value)));
			}
		}
		$assign(map, map->isEmpty() ? ($Map*)nullptr : map);
	}
	return map;
}

HostLocaleProviderAdapterImpl$6::HostLocaleProviderAdapterImpl$6() {
}

$Class* HostLocaleProviderAdapterImpl$6::load$($String* name, bool initialize) {
	$loadClass(HostLocaleProviderAdapterImpl$6, name, initialize, &_HostLocaleProviderAdapterImpl$6_ClassInfo_, allocate$HostLocaleProviderAdapterImpl$6);
	return class$;
}

$Class* HostLocaleProviderAdapterImpl$6::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun