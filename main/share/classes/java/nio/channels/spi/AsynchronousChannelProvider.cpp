#include <java/nio/channels/spi/AsynchronousChannelProvider.h>

#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/channels/AsynchronousChannelGroup.h>
#include <java/nio/channels/AsynchronousServerSocketChannel.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider$ProviderHolder.h>
#include <java/security/Permission.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $AsynchronousChannelGroup = ::java::nio::channels::AsynchronousChannelGroup;
using $AsynchronousServerSocketChannel = ::java::nio::channels::AsynchronousServerSocketChannel;
using $AsynchronousSocketChannel = ::java::nio::channels::AsynchronousSocketChannel;
using $AsynchronousChannelProvider$ProviderHolder = ::java::nio::channels::spi::AsynchronousChannelProvider$ProviderHolder;
using $Permission = ::java::security::Permission;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;

namespace java {
	namespace nio {
		namespace channels {
			namespace spi {

$MethodInfo _AsynchronousChannelProvider_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Void;)V", nullptr, $PRIVATE, $method(AsynchronousChannelProvider, init$, void, $Void*)},
	{"<init>", "()V", nullptr, $PROTECTED, $method(AsynchronousChannelProvider, init$, void)},
	{"checkPermission", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(AsynchronousChannelProvider, checkPermission, $Void*)},
	{"openAsynchronousChannelGroup", "(ILjava/util/concurrent/ThreadFactory;)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, int32_t, $ThreadFactory*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(Ljava/util/concurrent/ExecutorService;I)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, $ExecutorService*, int32_t), "java.io.IOException"},
	{"openAsynchronousServerSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousServerSocketChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousChannelProvider, openAsynchronousServerSocketChannel, $AsynchronousServerSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"openAsynchronousSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousChannelProvider, openAsynchronousSocketChannel, $AsynchronousSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"provider", "()Ljava/nio/channels/spi/AsynchronousChannelProvider;", nullptr, $PUBLIC | $STATIC, $staticMethod(AsynchronousChannelProvider, provider, AsynchronousChannelProvider*)},
	{}
};

$InnerClassInfo _AsynchronousChannelProvider_InnerClassesInfo_[] = {
	{"java.nio.channels.spi.AsynchronousChannelProvider$ProviderHolder", "java.nio.channels.spi.AsynchronousChannelProvider", "ProviderHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AsynchronousChannelProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.channels.spi.AsynchronousChannelProvider",
	"java.lang.Object",
	nullptr,
	nullptr,
	_AsynchronousChannelProvider_MethodInfo_,
	nullptr,
	nullptr,
	_AsynchronousChannelProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.channels.spi.AsynchronousChannelProvider$ProviderHolder,java.nio.channels.spi.AsynchronousChannelProvider$ProviderHolder$1"
};

$Object* allocate$AsynchronousChannelProvider($Class* clazz) {
	return $of($alloc(AsynchronousChannelProvider));
}

$Void* AsynchronousChannelProvider::checkPermission() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "asynchronousChannelProvider"_s));
	}
	return nullptr;
}

void AsynchronousChannelProvider::init$($Void* ignore) {
}

void AsynchronousChannelProvider::init$() {
	AsynchronousChannelProvider::init$($(checkPermission()));
}

AsynchronousChannelProvider* AsynchronousChannelProvider::provider() {
	$init($AsynchronousChannelProvider$ProviderHolder);
	return $AsynchronousChannelProvider$ProviderHolder::provider;
}

AsynchronousChannelProvider::AsynchronousChannelProvider() {
}

$Class* AsynchronousChannelProvider::load$($String* name, bool initialize) {
	$loadClass(AsynchronousChannelProvider, name, initialize, &_AsynchronousChannelProvider_ClassInfo_, allocate$AsynchronousChannelProvider);
	return class$;
}

$Class* AsynchronousChannelProvider::class$ = nullptr;

			} // spi
		} // channels
	} // nio
} // java