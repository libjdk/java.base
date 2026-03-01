#include <sun/util/locale/provider/SPILocaleProviderAdapter.h>

#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/spi/LocaleServiceProvider.h>
#include <sun/util/locale/provider/AuxLocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/SPILocaleProviderAdapter$1.h>
#include <jcpp.h>

#undef SPI

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $LocaleServiceProvider = ::java::util::spi::LocaleServiceProvider;
using $AuxLocaleProviderAdapter = ::sun::util::locale::provider::AuxLocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $SPILocaleProviderAdapter$1 = ::sun::util::locale::provider::SPILocaleProviderAdapter$1;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$MethodInfo _SPILocaleProviderAdapter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SPILocaleProviderAdapter, init$, void)},
	{"findInstalledProvider", "(Ljava/lang/Class;)Ljava/util/spi/LocaleServiceProvider;", "<P:Ljava/util/spi/LocaleServiceProvider;>(Ljava/lang/Class<TP;>;)TP;", $PROTECTED, $virtualMethod(SPILocaleProviderAdapter, findInstalledProvider, $LocaleServiceProvider*, $Class*)},
	{"getAdapterType", "()Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PUBLIC, $virtualMethod(SPILocaleProviderAdapter, getAdapterType, $LocaleProviderAdapter$Type*)},
	{}
};

$InnerClassInfo _SPILocaleProviderAdapter_InnerClassesInfo_[] = {
	{"sun.util.locale.provider.SPILocaleProviderAdapter$TimeZoneNameProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "TimeZoneNameProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$LocaleNameProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "LocaleNameProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$CurrencyNameProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "CurrencyNameProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$CalendarNameProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "CalendarNameProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$CalendarDataProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "CalendarDataProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$NumberFormatProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "NumberFormatProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$DecimalFormatSymbolsProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "DecimalFormatSymbolsProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$DateFormatSymbolsProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "DateFormatSymbolsProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$DateFormatProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "DateFormatProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$CollatorProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "CollatorProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$BreakIteratorProviderDelegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "BreakIteratorProviderDelegate", $STATIC},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$Delegate", "sun.util.locale.provider.SPILocaleProviderAdapter", "Delegate", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.locale.provider.SPILocaleProviderAdapter$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SPILocaleProviderAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.SPILocaleProviderAdapter",
	"sun.util.locale.provider.AuxLocaleProviderAdapter",
	nullptr,
	nullptr,
	_SPILocaleProviderAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_SPILocaleProviderAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.locale.provider.SPILocaleProviderAdapter$TimeZoneNameProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$LocaleNameProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$CurrencyNameProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$CalendarNameProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$CalendarDataProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$NumberFormatProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$DecimalFormatSymbolsProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$DateFormatSymbolsProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$DateFormatProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$CollatorProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$BreakIteratorProviderDelegate,sun.util.locale.provider.SPILocaleProviderAdapter$Delegate,sun.util.locale.provider.SPILocaleProviderAdapter$1"
};

$Object* allocate$SPILocaleProviderAdapter($Class* clazz) {
	return $of($alloc(SPILocaleProviderAdapter));
}

void SPILocaleProviderAdapter::init$() {
	$AuxLocaleProviderAdapter::init$();
}

$LocaleProviderAdapter$Type* SPILocaleProviderAdapter::getAdapterType() {
	$init($LocaleProviderAdapter$Type);
	return $LocaleProviderAdapter$Type::SPI;
}

$LocaleServiceProvider* SPILocaleProviderAdapter::findInstalledProvider($Class* c) {
	$beforeCallerSensitive();
	try {
		return $cast($LocaleServiceProvider, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($SPILocaleProviderAdapter$1, this, c))));
	} catch ($PrivilegedActionException& e) {
		$throwNew($ServiceConfigurationError, "SPI locale provider cannot be instantiated."_s, e);
	}
	$shouldNotReachHere();
}

SPILocaleProviderAdapter::SPILocaleProviderAdapter() {
}

$Class* SPILocaleProviderAdapter::load$($String* name, bool initialize) {
	$loadClass(SPILocaleProviderAdapter, name, initialize, &_SPILocaleProviderAdapter_ClassInfo_, allocate$SPILocaleProviderAdapter);
	return class$;
}

$Class* SPILocaleProviderAdapter::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun