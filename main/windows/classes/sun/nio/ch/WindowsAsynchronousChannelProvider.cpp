#include <sun/nio/ch/WindowsAsynchronousChannelProvider.h>

#include <java/nio/channels/AsynchronousChannelGroup.h>
#include <java/nio/channels/AsynchronousServerSocketChannel.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/IllegalChannelGroupException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/nio/ch/WindowsAsynchronousServerSocketChannelImpl.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl.h>
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
using $Iocp = ::sun::nio::ch::Iocp;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $WindowsAsynchronousServerSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousServerSocketChannelImpl;
using $WindowsAsynchronousSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousChannelProvider_FieldInfo_[] = {
	{"defaultIocp", "Lsun/nio/ch/Iocp;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(WindowsAsynchronousChannelProvider, defaultIocp$)},
	{}
};

$MethodInfo _WindowsAsynchronousChannelProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WindowsAsynchronousChannelProvider, init$, void)},
	{"defaultIocp", "()Lsun/nio/ch/Iocp;", nullptr, $PRIVATE, $method(WindowsAsynchronousChannelProvider, defaultIocp, $Iocp*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(ILjava/util/concurrent/ThreadFactory;)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, int32_t, $ThreadFactory*), "java.io.IOException"},
	{"openAsynchronousChannelGroup", "(Ljava/util/concurrent/ExecutorService;I)Ljava/nio/channels/AsynchronousChannelGroup;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousChannelProvider, openAsynchronousChannelGroup, $AsynchronousChannelGroup*, $ExecutorService*, int32_t), "java.io.IOException"},
	{"openAsynchronousServerSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousServerSocketChannel;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousChannelProvider, openAsynchronousServerSocketChannel, $AsynchronousServerSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"openAsynchronousSocketChannel", "(Ljava/nio/channels/AsynchronousChannelGroup;)Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousChannelProvider, openAsynchronousSocketChannel, $AsynchronousSocketChannel*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{"toIocp", "(Ljava/nio/channels/AsynchronousChannelGroup;)Lsun/nio/ch/Iocp;", nullptr, $PRIVATE, $method(WindowsAsynchronousChannelProvider, toIocp, $Iocp*, $AsynchronousChannelGroup*), "java.io.IOException"},
	{}
};

$ClassInfo _WindowsAsynchronousChannelProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousChannelProvider",
	"java.nio.channels.spi.AsynchronousChannelProvider",
	nullptr,
	_WindowsAsynchronousChannelProvider_FieldInfo_,
	_WindowsAsynchronousChannelProvider_MethodInfo_
};

$Object* allocate$WindowsAsynchronousChannelProvider($Class* clazz) {
	return $of($alloc(WindowsAsynchronousChannelProvider));
}

$volatile($Iocp*) WindowsAsynchronousChannelProvider::defaultIocp$ = nullptr;

void WindowsAsynchronousChannelProvider::init$() {
	$AsynchronousChannelProvider::init$();
}

$Iocp* WindowsAsynchronousChannelProvider::defaultIocp() {
	$useLocalCurrentObjectStackCache();
	if (WindowsAsynchronousChannelProvider::defaultIocp$ == nullptr) {
		$synchronized(WindowsAsynchronousChannelProvider::class$) {
			if (WindowsAsynchronousChannelProvider::defaultIocp$ == nullptr) {
				$assignStatic(WindowsAsynchronousChannelProvider::defaultIocp$, $$new($Iocp, this, $($ThreadPool::getDefault()))->start());
			}
		}
	}
	return WindowsAsynchronousChannelProvider::defaultIocp$;
}

$AsynchronousChannelGroup* WindowsAsynchronousChannelProvider::openAsynchronousChannelGroup(int32_t nThreads, $ThreadFactory* factory) {
	$useLocalCurrentObjectStackCache();
	return $$new($Iocp, this, $($ThreadPool::create(nThreads, factory)))->start();
}

$AsynchronousChannelGroup* WindowsAsynchronousChannelProvider::openAsynchronousChannelGroup($ExecutorService* executor, int32_t initialSize) {
	$useLocalCurrentObjectStackCache();
	return $$new($Iocp, this, $($ThreadPool::wrap(executor, initialSize)))->start();
}

$Iocp* WindowsAsynchronousChannelProvider::toIocp($AsynchronousChannelGroup* group) {
	if (group == nullptr) {
		return defaultIocp();
	} else {
		if (!($instanceOf($Iocp, group))) {
			$throwNew($IllegalChannelGroupException);
		}
		return $cast($Iocp, group);
	}
}

$AsynchronousServerSocketChannel* WindowsAsynchronousChannelProvider::openAsynchronousServerSocketChannel($AsynchronousChannelGroup* group) {
	return $new($WindowsAsynchronousServerSocketChannelImpl, $(toIocp(group)));
}

$AsynchronousSocketChannel* WindowsAsynchronousChannelProvider::openAsynchronousSocketChannel($AsynchronousChannelGroup* group) {
	return $new($WindowsAsynchronousSocketChannelImpl, $(toIocp(group)));
}

WindowsAsynchronousChannelProvider::WindowsAsynchronousChannelProvider() {
}

$Class* WindowsAsynchronousChannelProvider::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousChannelProvider, name, initialize, &_WindowsAsynchronousChannelProvider_ClassInfo_, allocate$WindowsAsynchronousChannelProvider);
	return class$;
}

$Class* WindowsAsynchronousChannelProvider::class$ = nullptr;

		} // ch
	} // nio
} // sun