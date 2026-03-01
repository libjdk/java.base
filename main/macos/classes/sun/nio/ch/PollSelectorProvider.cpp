#include <sun/nio/ch/PollSelectorProvider.h>

#include <java/nio/channels/Channel.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <sun/nio/ch/InheritedChannel.h>
#include <sun/nio/ch/PollSelectorImpl.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Channel = ::java::nio::channels::Channel;
using $AbstractSelector = ::java::nio::channels::spi::AbstractSelector;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $InheritedChannel = ::sun::nio::ch::InheritedChannel;
using $PollSelectorImpl = ::sun::nio::ch::PollSelectorImpl;
using $SelectorProviderImpl = ::sun::nio::ch::SelectorProviderImpl;

namespace sun {
	namespace nio {
		namespace ch {

$MethodInfo _PollSelectorProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PollSelectorProvider, init$, void)},
	{"inheritedChannel", "()Ljava/nio/channels/Channel;", nullptr, $PUBLIC, $virtualMethod(PollSelectorProvider, inheritedChannel, $Channel*), "java.io.IOException"},
	{"openSelector", "()Ljava/nio/channels/spi/AbstractSelector;", nullptr, $PUBLIC, $virtualMethod(PollSelectorProvider, openSelector, $AbstractSelector*), "java.io.IOException"},
	{}
};

$ClassInfo _PollSelectorProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.PollSelectorProvider",
	"sun.nio.ch.SelectorProviderImpl",
	nullptr,
	nullptr,
	_PollSelectorProvider_MethodInfo_
};

$Object* allocate$PollSelectorProvider($Class* clazz) {
	return $of($alloc(PollSelectorProvider));
}

void PollSelectorProvider::init$() {
	$SelectorProviderImpl::init$();
}

$AbstractSelector* PollSelectorProvider::openSelector() {
	return $new($PollSelectorImpl, this);
}

$Channel* PollSelectorProvider::inheritedChannel() {
	return $InheritedChannel::getChannel();
}

PollSelectorProvider::PollSelectorProvider() {
}

$Class* PollSelectorProvider::load$($String* name, bool initialize) {
	$loadClass(PollSelectorProvider, name, initialize, &_PollSelectorProvider_ClassInfo_, allocate$PollSelectorProvider);
	return class$;
}

$Class* PollSelectorProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun