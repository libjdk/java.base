#include <sun/nio/ch/WEPollSelectorProvider.h>

#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <sun/nio/ch/WEPollSelectorImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSelector = ::java::nio::channels::spi::AbstractSelector;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $SelectorProviderImpl = ::sun::nio::ch::SelectorProviderImpl;
using $WEPollSelectorImpl = ::sun::nio::ch::WEPollSelectorImpl;

namespace sun {
	namespace nio {
		namespace ch {

$MethodInfo _WEPollSelectorProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WEPollSelectorProvider, init$, void)},
	{"openSelector", "()Ljava/nio/channels/spi/AbstractSelector;", nullptr, $PUBLIC, $virtualMethod(WEPollSelectorProvider, openSelector, $AbstractSelector*), "java.io.IOException"},
	{}
};

$ClassInfo _WEPollSelectorProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.WEPollSelectorProvider",
	"sun.nio.ch.SelectorProviderImpl",
	nullptr,
	nullptr,
	_WEPollSelectorProvider_MethodInfo_
};

$Object* allocate$WEPollSelectorProvider($Class* clazz) {
	return $of($alloc(WEPollSelectorProvider));
}

void WEPollSelectorProvider::init$() {
	$SelectorProviderImpl::init$();
}

$AbstractSelector* WEPollSelectorProvider::openSelector() {
	return $new($WEPollSelectorImpl, this);
}

WEPollSelectorProvider::WEPollSelectorProvider() {
}

$Class* WEPollSelectorProvider::load$($String* name, bool initialize) {
	$loadClass(WEPollSelectorProvider, name, initialize, &_WEPollSelectorProvider_ClassInfo_, allocate$WEPollSelectorProvider);
	return class$;
}

$Class* WEPollSelectorProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun