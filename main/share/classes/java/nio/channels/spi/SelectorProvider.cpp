#include <java/nio/channels/spi/SelectorProvider.h>

#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/ProtocolFamily.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/Pipe.h>
#include <java/nio/channels/ServerSocketChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider$Holder.h>
#include <java/security/Permission.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef INSTANCE

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $ProtocolFamily = ::java::net::ProtocolFamily;
using $Channel = ::java::nio::channels::Channel;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $Pipe = ::java::nio::channels::Pipe;
using $ServerSocketChannel = ::java::nio::channels::ServerSocketChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractSelector = ::java::nio::channels::spi::AbstractSelector;
using $SelectorProvider$Holder = ::java::nio::channels::spi::SelectorProvider$Holder;
using $Permission = ::java::security::Permission;
using $Objects = ::java::util::Objects;

namespace java {
	namespace nio {
		namespace channels {
			namespace spi {

$MethodInfo _SelectorProvider_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Void;)V", nullptr, $PRIVATE, $method(SelectorProvider, init$, void, $Void*)},
	{"<init>", "()V", nullptr, $PROTECTED, $method(SelectorProvider, init$, void)},
	{"checkPermission", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(SelectorProvider, checkPermission, $Void*)},
	{"inheritedChannel", "()Ljava/nio/channels/Channel;", nullptr, $PUBLIC, $virtualMethod(SelectorProvider, inheritedChannel, $Channel*), "java.io.IOException"},
	{"openDatagramChannel", "()Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SelectorProvider, openDatagramChannel, $DatagramChannel*), "java.io.IOException"},
	{"openDatagramChannel", "(Ljava/net/ProtocolFamily;)Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SelectorProvider, openDatagramChannel, $DatagramChannel*, $ProtocolFamily*), "java.io.IOException"},
	{"openPipe", "()Ljava/nio/channels/Pipe;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SelectorProvider, openPipe, $Pipe*), "java.io.IOException"},
	{"openSelector", "()Ljava/nio/channels/spi/AbstractSelector;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SelectorProvider, openSelector, $AbstractSelector*), "java.io.IOException"},
	{"openServerSocketChannel", "()Ljava/nio/channels/ServerSocketChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SelectorProvider, openServerSocketChannel, $ServerSocketChannel*), "java.io.IOException"},
	{"openServerSocketChannel", "(Ljava/net/ProtocolFamily;)Ljava/nio/channels/ServerSocketChannel;", nullptr, $PUBLIC, $virtualMethod(SelectorProvider, openServerSocketChannel, $ServerSocketChannel*, $ProtocolFamily*), "java.io.IOException"},
	{"openSocketChannel", "()Ljava/nio/channels/SocketChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SelectorProvider, openSocketChannel, $SocketChannel*), "java.io.IOException"},
	{"openSocketChannel", "(Ljava/net/ProtocolFamily;)Ljava/nio/channels/SocketChannel;", nullptr, $PUBLIC, $virtualMethod(SelectorProvider, openSocketChannel, $SocketChannel*, $ProtocolFamily*), "java.io.IOException"},
	{"provider", "()Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(SelectorProvider, provider, SelectorProvider*)},
	{}
};

$InnerClassInfo _SelectorProvider_InnerClassesInfo_[] = {
	{"java.nio.channels.spi.SelectorProvider$Holder", "java.nio.channels.spi.SelectorProvider", "Holder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SelectorProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.channels.spi.SelectorProvider",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SelectorProvider_MethodInfo_,
	nullptr,
	nullptr,
	_SelectorProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.channels.spi.SelectorProvider$Holder"
};

$Object* allocate$SelectorProvider($Class* clazz) {
	return $of($alloc(SelectorProvider));
}

$Void* SelectorProvider::checkPermission() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "selectorProvider"_s));
	}
	return nullptr;
}

void SelectorProvider::init$($Void* ignore) {
}

void SelectorProvider::init$() {
	SelectorProvider::init$($(checkPermission()));
}

SelectorProvider* SelectorProvider::provider() {
	$init($SelectorProvider$Holder);
	return $SelectorProvider$Holder::INSTANCE;
}

$Channel* SelectorProvider::inheritedChannel() {
	return nullptr;
}

$SocketChannel* SelectorProvider::openSocketChannel($ProtocolFamily* family) {
	$Objects::requireNonNull(family);
	$throwNew($UnsupportedOperationException, "Protocol family not supported"_s);
	$shouldNotReachHere();
}

$ServerSocketChannel* SelectorProvider::openServerSocketChannel($ProtocolFamily* family) {
	$Objects::requireNonNull(family);
	$throwNew($UnsupportedOperationException, "Protocol family not supported"_s);
	$shouldNotReachHere();
}

SelectorProvider::SelectorProvider() {
}

$Class* SelectorProvider::load$($String* name, bool initialize) {
	$loadClass(SelectorProvider, name, initialize, &_SelectorProvider_ClassInfo_, allocate$SelectorProvider);
	return class$;
}

$Class* SelectorProvider::class$ = nullptr;

			} // spi
		} // channels
	} // nio
} // java