#include <sun/nio/ch/KQueueSelectorProvider.h>

#include <java/nio/channels/Channel.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <sun/nio/ch/InheritedChannel.h>
#include <sun/nio/ch/KQueueSelectorImpl.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Channel = ::java::nio::channels::Channel;
using $AbstractSelector = ::java::nio::channels::spi::AbstractSelector;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $InheritedChannel = ::sun::nio::ch::InheritedChannel;
using $KQueueSelectorImpl = ::sun::nio::ch::KQueueSelectorImpl;
using $SelectorProviderImpl = ::sun::nio::ch::SelectorProviderImpl;

namespace sun {
	namespace nio {
		namespace ch {

$MethodInfo _KQueueSelectorProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(KQueueSelectorProvider, init$, void)},
	{"inheritedChannel", "()Ljava/nio/channels/Channel;", nullptr, $PUBLIC, $virtualMethod(KQueueSelectorProvider, inheritedChannel, $Channel*), "java.io.IOException"},
	{"openSelector", "()Ljava/nio/channels/spi/AbstractSelector;", nullptr, $PUBLIC, $virtualMethod(KQueueSelectorProvider, openSelector, $AbstractSelector*), "java.io.IOException"},
	{}
};

$ClassInfo _KQueueSelectorProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.KQueueSelectorProvider",
	"sun.nio.ch.SelectorProviderImpl",
	nullptr,
	nullptr,
	_KQueueSelectorProvider_MethodInfo_
};

$Object* allocate$KQueueSelectorProvider($Class* clazz) {
	return $of($alloc(KQueueSelectorProvider));
}

void KQueueSelectorProvider::init$() {
	$SelectorProviderImpl::init$();
}

$AbstractSelector* KQueueSelectorProvider::openSelector() {
	return $new($KQueueSelectorImpl, this);
}

$Channel* KQueueSelectorProvider::inheritedChannel() {
	return $InheritedChannel::getChannel();
}

KQueueSelectorProvider::KQueueSelectorProvider() {
}

$Class* KQueueSelectorProvider::load$($String* name, bool initialize) {
	$loadClass(KQueueSelectorProvider, name, initialize, &_KQueueSelectorProvider_ClassInfo_, allocate$KQueueSelectorProvider);
	return class$;
}

$Class* KQueueSelectorProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun