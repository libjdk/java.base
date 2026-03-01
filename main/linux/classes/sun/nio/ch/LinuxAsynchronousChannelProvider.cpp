#include <sun/nio/ch/LinuxAsynchronousChannelProvider.h>

#include <java/nio/channels/AsynchronousChannelGroup.h>
#include <java/nio/channels/AsynchronousServerSocketChannel.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/IllegalChannelGroupException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <sun/nio/ch/EPollPort.h>
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
using $EPollPort = ::sun::nio::ch::EPollPort;
using $Port = ::sun::nio::ch::Port;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $UnixAsynchronousServerSocketChannelImpl = ::sun::nio::ch::UnixAsynchronousServerSocketChannelImpl;
using $UnixAsynchronousSocketChannelImpl = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _LinuxAsynchronousChannelProvider_FieldInfo_[] = {
	{"defaultPort", "Lsun/nio/ch/EPollPort;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(LinuxAsynchronousChannelProvider, defaultPort)},
	{}
};

$MethodInfo _LinuxAsynchronousChannelProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LinuxAsynchronousChannelProvider, init$, void)},
	{"defaultEventPort", "()Lsun/nio/ch/EPollPort;", nullptr, $PRIVATE, $method(LinuxAsynchronousChannelProvider, defaultEventPort, $EPollPort*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(ILjava/util/concurrent/ThreadFactory;)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC, $virtualMethod(LinuxAsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, int32_t, $ThreadFactory*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(Ljava/util/concurrent/ExecutorService;I)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC, $virtualMethod(LinuxAsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, $ExecutorService*, int32_t), "java.io.IOException"},
	{"openAsynchronousServerSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousServerSocketChannel;", nullptr, $PUBLIC, $virtualMethod(LinuxAsynchronousChannelProvider, openAsynchronousServerSocketChannel, $AsynchronousServerSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"openAsynchronousSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC, $virtualMethod(LinuxAsynchronousChannelProvider, openAsynchronousSocketChannel, $AsynchronousSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"toPort", "(Ljava/nio/channels/AsynchronousChannelGroup;)Lsun/nio/ch/Port;", nullptr, $PRIVATE, $method(LinuxAsynchronousChannelProvider, toPort, $Port*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{}
};

$ClassInfo _LinuxAsynchronousChannelProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.LinuxAsynchronousChannelProvider",
	"java.nio.channels.spi.AsynchronousChannelProvider",
	nullptr,
	_LinuxAsynchronousChannelProvider_FieldInfo_,
	_LinuxAsynchronousChannelProvider_MethodInfo_
};

$Object* allocate$LinuxAsynchronousChannelProvider($Class* clazz) {
	return $of($alloc(LinuxAsynchronousChannelProvider));
}

$volatile($EPollPort*) LinuxAsynchronousChannelProvider::defaultPort = nullptr;

$EPollPort* LinuxAsynchronousChannelProvider::defaultEventPort() {
	$useLocalCurrentObjectStackCache();
	if (LinuxAsynchronousChannelProvider::defaultPort == nullptr) {
		$synchronized(LinuxAsynchronousChannelProvider::class$) {
			if (LinuxAsynchronousChannelProvider::defaultPort == nullptr) {
				$assignStatic(LinuxAsynchronousChannelProvider::defaultPort, $$new($EPollPort, this, $($ThreadPool::getDefault()))->start());
			}
		}
	}
	return LinuxAsynchronousChannelProvider::defaultPort;
}

void LinuxAsynchronousChannelProvider::init$() {
	$AsynchronousChannelProvider::init$();
}

$AsynchronousChannelGroup* LinuxAsynchronousChannelProvider::openAsynchronousChannelGroup(int32_t nThreads, $ThreadFactory* factory) {
	$useLocalCurrentObjectStackCache();
	return $$new($EPollPort, this, $($ThreadPool::create(nThreads, factory)))->start();
}

$AsynchronousChannelGroup* LinuxAsynchronousChannelProvider::openAsynchronousChannelGroup($ExecutorService* executor, int32_t initialSize) {
	$useLocalCurrentObjectStackCache();
	return $$new($EPollPort, this, $($ThreadPool::wrap(executor, initialSize)))->start();
}

$Port* LinuxAsynchronousChannelProvider::toPort($AsynchronousChannelGroup* group) {
	if (group == nullptr) {
		return defaultEventPort();
	} else {
		if (!($instanceOf($EPollPort, group))) {
			$throwNew($IllegalChannelGroupException);
		}
		return $cast($Port, group);
	}
}

$AsynchronousServerSocketChannel* LinuxAsynchronousChannelProvider::openAsynchronousServerSocketChannel($AsynchronousChannelGroup* group) {
	return $new($UnixAsynchronousServerSocketChannelImpl, $(toPort(group)));
}

$AsynchronousSocketChannel* LinuxAsynchronousChannelProvider::openAsynchronousSocketChannel($AsynchronousChannelGroup* group) {
	return $new($UnixAsynchronousSocketChannelImpl, $(toPort(group)));
}

LinuxAsynchronousChannelProvider::LinuxAsynchronousChannelProvider() {
}

$Class* LinuxAsynchronousChannelProvider::load$($String* name, bool initialize) {
	$loadClass(LinuxAsynchronousChannelProvider, name, initialize, &_LinuxAsynchronousChannelProvider_ClassInfo_, allocate$LinuxAsynchronousChannelProvider);
	return class$;
}

$Class* LinuxAsynchronousChannelProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun