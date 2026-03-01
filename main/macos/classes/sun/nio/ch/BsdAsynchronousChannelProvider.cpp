#include <sun/nio/ch/BsdAsynchronousChannelProvider.h>

#include <java/nio/channels/AsynchronousChannelGroup.h>
#include <java/nio/channels/AsynchronousServerSocketChannel.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/IllegalChannelGroupException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <sun/nio/ch/KQueuePort.h>
#include <sun/nio/ch/Port.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/nio/ch/UnixAsynchronousServerSocketChannelImpl.h>
#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AsynchronousChannelGroup = ::java::nio::channels::AsynchronousChannelGroup;
using $AsynchronousServerSocketChannel = ::java::nio::channels::AsynchronousServerSocketChannel;
using $AsynchronousSocketChannel = ::java::nio::channels::AsynchronousSocketChannel;
using $IllegalChannelGroupException = ::java::nio::channels::IllegalChannelGroupException;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $KQueuePort = ::sun::nio::ch::KQueuePort;
using $Port = ::sun::nio::ch::Port;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $UnixAsynchronousServerSocketChannelImpl = ::sun::nio::ch::UnixAsynchronousServerSocketChannelImpl;
using $UnixAsynchronousSocketChannelImpl = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _BsdAsynchronousChannelProvider_FieldInfo_[] = {
	{"defaultPort", "Lsun/nio/ch/KQueuePort;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(BsdAsynchronousChannelProvider, defaultPort)},
	{}
};

$MethodInfo _BsdAsynchronousChannelProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BsdAsynchronousChannelProvider, init$, void)},
	{"defaultEventPort", "()Lsun/nio/ch/KQueuePort;", nullptr, $PRIVATE, $method(BsdAsynchronousChannelProvider, defaultEventPort, $KQueuePort*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(ILjava/util/concurrent/ThreadFactory;)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC, $virtualMethod(BsdAsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, int32_t, $ThreadFactory*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(Ljava/util/concurrent/ExecutorService;I)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC, $virtualMethod(BsdAsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, $ExecutorService*, int32_t), "java.io.IOException"},
	{"openAsynchronousServerSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousServerSocketChannel;", nullptr, $PUBLIC, $virtualMethod(BsdAsynchronousChannelProvider, openAsynchronousServerSocketChannel, $AsynchronousServerSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"openAsynchronousSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC, $virtualMethod(BsdAsynchronousChannelProvider, openAsynchronousSocketChannel, $AsynchronousSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"toPort", "(Ljava/nio/channels/AsynchronousChannelGroup;)Lsun/nio/ch/Port;", nullptr, $PRIVATE, $method(BsdAsynchronousChannelProvider, toPort, $Port*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{}
};

$ClassInfo _BsdAsynchronousChannelProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.BsdAsynchronousChannelProvider",
	"java.nio.channels.spi.AsynchronousChannelProvider",
	nullptr,
	_BsdAsynchronousChannelProvider_FieldInfo_,
	_BsdAsynchronousChannelProvider_MethodInfo_
};

$Object* allocate$BsdAsynchronousChannelProvider($Class* clazz) {
	return $of($alloc(BsdAsynchronousChannelProvider));
}

$volatile($KQueuePort*) BsdAsynchronousChannelProvider::defaultPort = nullptr;

$KQueuePort* BsdAsynchronousChannelProvider::defaultEventPort() {
	$useLocalCurrentObjectStackCache();
	if (BsdAsynchronousChannelProvider::defaultPort == nullptr) {
		$synchronized(BsdAsynchronousChannelProvider::class$) {
			if (BsdAsynchronousChannelProvider::defaultPort == nullptr) {
				$assignStatic(BsdAsynchronousChannelProvider::defaultPort, $$new($KQueuePort, this, $($ThreadPool::getDefault()))->start());
			}
		}
	}
	return BsdAsynchronousChannelProvider::defaultPort;
}

void BsdAsynchronousChannelProvider::init$() {
	$AsynchronousChannelProvider::init$();
}

$AsynchronousChannelGroup* BsdAsynchronousChannelProvider::openAsynchronousChannelGroup(int32_t nThreads, $ThreadFactory* factory) {
	$useLocalCurrentObjectStackCache();
	return $$new($KQueuePort, this, $($ThreadPool::create(nThreads, factory)))->start();
}

$AsynchronousChannelGroup* BsdAsynchronousChannelProvider::openAsynchronousChannelGroup($ExecutorService* executor, int32_t initialSize) {
	$useLocalCurrentObjectStackCache();
	return $$new($KQueuePort, this, $($ThreadPool::wrap(executor, initialSize)))->start();
}

$Port* BsdAsynchronousChannelProvider::toPort($AsynchronousChannelGroup* group) {
	if (group == nullptr) {
		return defaultEventPort();
	} else {
		if (!($instanceOf($KQueuePort, group))) {
			$throwNew($IllegalChannelGroupException);
		}
		return $cast($Port, group);
	}
}

$AsynchronousServerSocketChannel* BsdAsynchronousChannelProvider::openAsynchronousServerSocketChannel($AsynchronousChannelGroup* group) {
	return $new($UnixAsynchronousServerSocketChannelImpl, $(toPort(group)));
}

$AsynchronousSocketChannel* BsdAsynchronousChannelProvider::openAsynchronousSocketChannel($AsynchronousChannelGroup* group) {
	return $new($UnixAsynchronousSocketChannelImpl, $(toPort(group)));
}

BsdAsynchronousChannelProvider::BsdAsynchronousChannelProvider() {
}

$Class* BsdAsynchronousChannelProvider::load$($String* name, bool initialize) {
	$loadClass(BsdAsynchronousChannelProvider, name, initialize, &_BsdAsynchronousChannelProvider_ClassInfo_, allocate$BsdAsynchronousChannelProvider);
	return class$;
}

$Class* BsdAsynchronousChannelProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun