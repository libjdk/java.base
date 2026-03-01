#include <java/util/spi/LocaleServiceProvider.h>

#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/Permission.h>
#include <java/util/Locale.h>
#include <jcpp.h>

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $Permission = ::java::security::Permission;
using $Locale = ::java::util::Locale;

namespace java {
	namespace util {
		namespace spi {

$MethodInfo _LocaleServiceProvider_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Void;)V", nullptr, $PRIVATE, $method(LocaleServiceProvider, init$, void, $Void*)},
	{"<init>", "()V", nullptr, $PROTECTED, $method(LocaleServiceProvider, init$, void)},
	{"checkPermission", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleServiceProvider, checkPermission, $Void*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LocaleServiceProvider, getAvailableLocales, $LocaleArray*)},
	{"isSupportedLocale", "(Ljava/util/Locale;)Z", nullptr, $PUBLIC, $virtualMethod(LocaleServiceProvider, isSupportedLocale, bool, $Locale*)},
	{}
};

$ClassInfo _LocaleServiceProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.spi.LocaleServiceProvider",
	"java.lang.Object",
	nullptr,
	nullptr,
	_LocaleServiceProvider_MethodInfo_
};

$Object* allocate$LocaleServiceProvider($Class* clazz) {
	return $of($alloc(LocaleServiceProvider));
}

$Void* LocaleServiceProvider::checkPermission() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "localeServiceProvider"_s));
	}
	return nullptr;
}

void LocaleServiceProvider::init$($Void* ignore) {
}

void LocaleServiceProvider::init$() {
	LocaleServiceProvider::init$($(checkPermission()));
}

bool LocaleServiceProvider::isSupportedLocale($Locale* locale$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Locale, locale, locale$renamed);
	$assign(locale, $nc(locale)->stripExtensions());
	{
		$var($LocaleArray, arr$, getAvailableLocales());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Locale, available, arr$->get(i$));
			{
				if (locale->equals($($nc(available)->stripExtensions()))) {
					return true;
				}
			}
		}
	}
	return false;
}

LocaleServiceProvider::LocaleServiceProvider() {
}

$Class* LocaleServiceProvider::load$($String* name, bool initialize) {
	$loadClass(LocaleServiceProvider, name, initialize, &_LocaleServiceProvider_ClassInfo_, allocate$LocaleServiceProvider);
	return class$;
}

$Class* LocaleServiceProvider::class$ = nullptr;

		} // spi
	} // util
} // java