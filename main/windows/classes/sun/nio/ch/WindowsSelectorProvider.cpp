#include <sun/nio/ch/WindowsSelectorProvider.h>

#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <sun/nio/ch/WindowsSelectorImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSelector = ::java::nio::channels::spi::AbstractSelector;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $SelectorProviderImpl = ::sun::nio::ch::SelectorProviderImpl;
using $WindowsSelectorImpl = ::sun::nio::ch::WindowsSelectorImpl;

namespace sun {
	namespace nio {
		namespace ch {

$MethodInfo _WindowsSelectorProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WindowsSelectorProvider, init$, void)},
	{"openSelector", "()Ljava/nio/channels/spi/AbstractSelector;", nullptr, $PUBLIC, $virtualMethod(WindowsSelectorProvider, openSelector, $AbstractSelector*), "java.io.IOException"},
	{}
};

$ClassInfo _WindowsSelectorProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.WindowsSelectorProvider",
	"sun.nio.ch.SelectorProviderImpl",
	nullptr,
	nullptr,
	_WindowsSelectorProvider_MethodInfo_
};

$Object* allocate$WindowsSelectorProvider($Class* clazz) {
	return $of($alloc(WindowsSelectorProvider));
}

void WindowsSelectorProvider::init$() {
	$SelectorProviderImpl::init$();
}

$AbstractSelector* WindowsSelectorProvider::openSelector() {
	return $new($WindowsSelectorImpl, this);
}

WindowsSelectorProvider::WindowsSelectorProvider() {
}

$Class* WindowsSelectorProvider::load$($String* name, bool initialize) {
	$loadClass(WindowsSelectorProvider, name, initialize, &_WindowsSelectorProvider_ClassInfo_, allocate$WindowsSelectorProvider);
	return class$;
}

$Class* WindowsSelectorProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun