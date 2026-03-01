#include <sun/nio/ch/Port.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/ShutdownChannelGroupException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReadWriteLock.h>
#include <java/util/concurrent/locks/ReentrantReadWriteLock.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Port$1.h>
#include <sun/nio/ch/Port$PollableChannel.h>
#include <sun/nio/ch/ThreadPool.h>
#include <jcpp.h>

#undef MAX_BATCH_SIZE

using $Port$PollableChannelArray = $Array<::sun::nio::ch::Port$PollableChannel>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Channel = ::java::nio::channels::Channel;
using $ShutdownChannelGroupException = ::java::nio::channels::ShutdownChannelGroupException;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReadWriteLock = ::java::util::concurrent::locks::ReadWriteLock;
using $ReentrantReadWriteLock = ::java::util::concurrent::locks::ReentrantReadWriteLock;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Port$1 = ::sun::nio::ch::Port$1;
using $Port$PollableChannel = ::sun::nio::ch::Port$PollableChannel;
using $ThreadPool = ::sun::nio::ch::ThreadPool;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _Port_FieldInfo_[] = {
	{"fdToChannelLock", "Ljava/util/concurrent/locks/ReadWriteLock;", nullptr, $PROTECTED | $FINAL, $field(Port, fdToChannelLock)},
	{"fdToChannel", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/ch/Port$PollableChannel;>;", $PROTECTED | $FINAL, $field(Port, fdToChannel)},
	{}
};

$MethodInfo _Port_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/AsynchronousChannelProvider;Lsun/nio/ch/ThreadPool;)V", nullptr, 0, $method(Port, init$, void, $AsynchronousChannelProvider*, $ThreadPool*)},
	{"attachForeignChannel", "(Ljava/nio/channels/Channel;Ljava/io/FileDescriptor;)Ljava/lang/Object;", nullptr, $FINAL, $virtualMethod(Port, attachForeignChannel, $Object*, $Channel*, $FileDescriptor*)},
	{"closeAllChannels", "()V", nullptr, $FINAL, $virtualMethod(Port, closeAllChannels, void)},
	{"detachForeignChannel", "(Ljava/lang/Object;)V", nullptr, $FINAL, $virtualMethod(Port, detachForeignChannel, void, Object$*)},
	{"isEmpty", "()Z", nullptr, $FINAL, $virtualMethod(Port, isEmpty, bool)},
	{"preUnregister", "(I)V", nullptr, $PROTECTED, $virtualMethod(Port, preUnregister, void, int32_t)},
	{"register", "(ILsun/nio/ch/Port$PollableChannel;)V", nullptr, $FINAL, $method(Port, register$, void, int32_t, $Port$PollableChannel*)},
	{"startPoll", "(II)V", nullptr, $ABSTRACT, $virtualMethod(Port, startPoll, void, int32_t, int32_t)},
	{"unregister", "(I)V", nullptr, $FINAL, $method(Port, unregister, void, int32_t)},
	{}
};

$InnerClassInfo _Port_InnerClassesInfo_[] = {
	{"sun.nio.ch.Port$PollableChannel", "sun.nio.ch.Port", "PollableChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.Port$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Port_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.ch.Port",
	"sun.nio.ch.AsynchronousChannelGroupImpl",
	nullptr,
	_Port_FieldInfo_,
	_Port_MethodInfo_,
	nullptr,
	nullptr,
	_Port_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.Port$PollableChannel,sun.nio.ch.Port$1"
};

$Object* allocate$Port($Class* clazz) {
	return $of($alloc(Port));
}

void Port::init$($AsynchronousChannelProvider* provider, $ThreadPool* pool) {
	$AsynchronousChannelGroupImpl::init$(provider, pool);
	$set(this, fdToChannelLock, $new($ReentrantReadWriteLock));
	$set(this, fdToChannel, $new($HashMap));
}

void Port::register$(int32_t fd, $Port$PollableChannel* ch) {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->fdToChannelLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (isShutdown()) {
				$throwNew($ShutdownChannelGroupException);
			}
			$nc(this->fdToChannel)->put($($Integer::valueOf(fd)), ch);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc($($nc(this->fdToChannelLock)->writeLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Port::preUnregister(int32_t fd) {
}

void Port::unregister(int32_t fd) {
	$useLocalCurrentObjectStackCache();
	bool checkForShutdown = false;
	preUnregister(fd);
	$nc($($nc(this->fdToChannelLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->fdToChannel)->remove($($Integer::valueOf(fd)));
			if ($nc(this->fdToChannel)->isEmpty()) {
				checkForShutdown = true;
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc($($nc(this->fdToChannelLock)->writeLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (checkForShutdown && isShutdown()) {
		try {
			shutdownNow();
		} catch ($IOException& ignore) {
		}
	}
}

bool Port::isEmpty() {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->fdToChannelLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = $nc(this->fdToChannel)->isEmpty();
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc($($nc(this->fdToChannelLock)->writeLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* Port::attachForeignChannel($Channel* channel, $FileDescriptor* fd) {
	int32_t fdVal = $IOUtil::fdVal(fd);
	register$(fdVal, $$new($Port$1, this, channel));
	return $of($Integer::valueOf(fdVal));
}

void Port::detachForeignChannel(Object$* key) {
	unregister($nc(($cast($Integer, key)))->intValue());
}

void Port::closeAllChannels() {
	$useLocalCurrentObjectStackCache();
	int32_t MAX_BATCH_SIZE = 128;
	$var($Port$PollableChannelArray, channels, $new($Port$PollableChannelArray, MAX_BATCH_SIZE));
	int32_t count = 0;
	do {
		$nc($($nc(this->fdToChannelLock)->writeLock()))->lock();
		count = 0;
		{
			$var($Throwable, var$0, nullptr);
			try {
				{
					$var($Iterator, i$, $nc($($nc(this->fdToChannel)->keySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Integer, fd, $cast($Integer, i$->next()));
						{
							channels->set(count++, $cast($Port$PollableChannel, $($nc(this->fdToChannel)->get(fd))));
							if (count >= MAX_BATCH_SIZE) {
								break;
							}
						}
					}
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc($($nc(this->fdToChannelLock)->writeLock()))->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		for (int32_t i = 0; i < count; ++i) {
			try {
				$nc(channels->get(i))->close();
			} catch ($IOException& ignore) {
			}
		}
	} while (count > 0);
}

Port::Port() {
}

$Class* Port::load$($String* name, bool initialize) {
	$loadClass(Port, name, initialize, &_Port_ClassInfo_, allocate$Port);
	return class$;
}

$Class* Port::class$ = nullptr;

		} // ch
	} // nio
} // sun