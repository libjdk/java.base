#include <sun/util/locale/provider/LocaleServiceProviderPool$AllAvailableLocales.h>

#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Locale.h>
#include <java/util/Set.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <jcpp.h>

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _LocaleServiceProviderPool$AllAvailableLocales_FieldInfo_[] = {
	{"allAvailableLocales", "[Ljava/util/Locale;", nullptr, $STATIC | $FINAL, $staticField(LocaleServiceProviderPool$AllAvailableLocales, allAvailableLocales)},
	{}
};

$MethodInfo _LocaleServiceProviderPool$AllAvailableLocales_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LocaleServiceProviderPool$AllAvailableLocales, init$, void)},
	{}
};

$InnerClassInfo _LocaleServiceProviderPool$AllAvailableLocales_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.LocaleServiceProviderPool$AllAvailableLocales", "sun.util.locale.provider.LocaleServiceProviderPool", "AllAvailableLocales", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LocaleServiceProviderPool$AllAvailableLocales_ClassInfo_ = {
	$ACC_SUPER,
	"sun.util.locale.provider.LocaleServiceProviderPool$AllAvailableLocales",
	"java.lang.Object",
	nullptr,
	_LocaleServiceProviderPool$AllAvailableLocales_FieldInfo_,
	_LocaleServiceProviderPool$AllAvailableLocales_MethodInfo_,
	nullptr,
	nullptr,
	_LocaleServiceProviderPool$AllAvailableLocales_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.locale.provider.LocaleServiceProviderPool"
};

$Object* allocate$LocaleServiceProviderPool$AllAvailableLocales($Class* clazz) {
	return $of($alloc(LocaleServiceProviderPool$AllAvailableLocales));
}

$LocaleArray* LocaleServiceProviderPool$AllAvailableLocales::allAvailableLocales = nullptr;

void LocaleServiceProviderPool$AllAvailableLocales::init$() {
}

void clinit$LocaleServiceProviderPool$AllAvailableLocales($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Set, all, $new($HashSet));
		{
			$init($LocaleServiceProviderPool);
			$var($ClassArray, arr$, $LocaleServiceProviderPool::spiClasses);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$Class* c = arr$->get(i$);
				{
					$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool(c));
					all->addAll($($nc(pool)->getAvailableLocaleSet()));
				}
			}
		}
		$assignStatic(LocaleServiceProviderPool$AllAvailableLocales::allAvailableLocales, $fcast($LocaleArray, all->toArray($$new($LocaleArray, 0))));
	}
}

LocaleServiceProviderPool$AllAvailableLocales::LocaleServiceProviderPool$AllAvailableLocales() {
}

$Class* LocaleServiceProviderPool$AllAvailableLocales::load$($String* name, bool initialize) {
	$loadClass(LocaleServiceProviderPool$AllAvailableLocales, name, initialize, &_LocaleServiceProviderPool$AllAvailableLocales_ClassInfo_, clinit$LocaleServiceProviderPool$AllAvailableLocales, allocate$LocaleServiceProviderPool$AllAvailableLocales);
	return class$;
}

$Class* LocaleServiceProviderPool$AllAvailableLocales::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun