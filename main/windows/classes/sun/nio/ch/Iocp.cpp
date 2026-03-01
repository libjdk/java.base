#include <sun/nio/ch/Iocp.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/ShutdownChannelGroupException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/RejectedExecutionException.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReadWriteLock.h>
#include <java/util/concurrent/locks/ReentrantReadWriteLock.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Iocp$1.h>
#include <sun/nio/ch/Iocp$CompletionStatus.h>
#include <sun/nio/ch/Iocp$EventHandlerTask.h>
#include <sun/nio/ch/Iocp$OverlappedChannel.h>
#include <sun/nio/ch/ThreadPool.h>
#include <jcpp.h>

#undef INVALID_HANDLE_VALUE
#undef MAX_BATCH_SIZE

using $Iocp$OverlappedChannelArray = $Array<::sun::nio::ch::Iocp$OverlappedChannel>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Channel = ::java::nio::channels::Channel;
using $ShutdownChannelGroupException = ::java::nio::channels::ShutdownChannelGroupException;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $RejectedExecutionException = ::java::util::concurrent::RejectedExecutionException;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReadWriteLock = ::java::util::concurrent::locks::ReadWriteLock;
using $ReentrantReadWriteLock = ::java::util::concurrent::locks::ReentrantReadWriteLock;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Iocp$1 = ::sun::nio::ch::Iocp$1;
using $Iocp$CompletionStatus = ::sun::nio::ch::Iocp$CompletionStatus;
using $Iocp$EventHandlerTask = ::sun::nio::ch::Iocp$EventHandlerTask;
using $Iocp$OverlappedChannel = ::sun::nio::ch::Iocp$OverlappedChannel;
using $ThreadPool = ::sun::nio::ch::ThreadPool;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _Iocp_FieldInfo_[] = {
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Iocp, unsafe)},
	{"INVALID_HANDLE_VALUE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Iocp, INVALID_HANDLE_VALUE)},
	{"keyToChannelLock", "Ljava/util/concurrent/locks/ReadWriteLock;", nullptr, $PRIVATE | $FINAL, $field(Iocp, keyToChannelLock)},
	{"keyToChannel", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/ch/Iocp$OverlappedChannel;>;", $PRIVATE | $FINAL, $field(Iocp, keyToChannel)},
	{"nextCompletionKey", "I", nullptr, $PRIVATE, $field(Iocp, nextCompletionKey)},
	{"port", "J", nullptr, $PRIVATE | $FINAL, $field(Iocp, port)},
	{"closed", "Z", nullptr, $PRIVATE, $field(Iocp, closed)},
	{"staleIoSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Long;>;", $PRIVATE | $FINAL, $field(Iocp, staleIoSet)},
	{}
};

$MethodInfo _Iocp_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/AsynchronousChannelProvider;Lsun/nio/ch/ThreadPool;)V", nullptr, 0, $method(Iocp, init$, void, $AsynchronousChannelProvider*, $ThreadPool*), "java.io.IOException"},
	{"associate", "(Lsun/nio/ch/Iocp$OverlappedChannel;J)I", nullptr, 0, $virtualMethod(Iocp, associate, int32_t, $Iocp$OverlappedChannel*, int64_t), "java.io.IOException"},
	{"attachForeignChannel", "(Ljava/nio/channels/Channel;Ljava/io/FileDescriptor;)Ljava/lang/Object;", nullptr, $FINAL, $virtualMethod(Iocp, attachForeignChannel, $Object*, $Channel*, $FileDescriptor*), "java.io.IOException"},
	{"checkIfStale", "(J)V", nullptr, $PRIVATE, $method(Iocp, checkIfStale, void, int64_t)},
	{"close0", "(J)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Iocp, close0, void, int64_t)},
	{"closeAllChannels", "()V", nullptr, 0, $virtualMethod(Iocp, closeAllChannels, void)},
	{"createIoCompletionPort", "(JJII)J", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Iocp, createIoCompletionPort, int64_t, int64_t, int64_t, int32_t, int32_t), "java.io.IOException"},
	{"detachForeignChannel", "(Ljava/lang/Object;)V", nullptr, $FINAL, $virtualMethod(Iocp, detachForeignChannel, void, Object$*)},
	{"disassociate", "(I)V", nullptr, 0, $virtualMethod(Iocp, disassociate, void, int32_t)},
	{"executeOnHandlerTask", "(Ljava/lang/Runnable;)V", nullptr, 0, $virtualMethod(Iocp, executeOnHandlerTask, void, $Runnable*)},
	{"getErrorMessage", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Iocp, getErrorMessage, $String*, int32_t)},
	{"getQueuedCompletionStatus", "(JLsun/nio/ch/Iocp$CompletionStatus;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Iocp, getQueuedCompletionStatus, void, int64_t, $Iocp$CompletionStatus*), "java.io.IOException"},
	{"implClose", "()V", nullptr, 0, $virtualMethod(Iocp, implClose, void)},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Iocp, initIDs, void)},
	{"isEmpty", "()Z", nullptr, 0, $virtualMethod(Iocp, isEmpty, bool)},
	{"makeStale", "(Ljava/lang/Long;)V", nullptr, 0, $virtualMethod(Iocp, makeStale, void, $Long*)},
	{"postQueuedCompletionStatus", "(JI)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Iocp, postQueuedCompletionStatus, void, int64_t, int32_t), "java.io.IOException"},
	{"shutdownHandlerTasks", "()V", nullptr, 0, $virtualMethod(Iocp, shutdownHandlerTasks, void)},
	{"start", "()Lsun/nio/ch/Iocp;", nullptr, 0, $virtualMethod(Iocp, start, Iocp*)},
	{"translateErrorToIOException", "(I)Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC, $staticMethod(Iocp, translateErrorToIOException, $IOException*, int32_t)},
	{"wakeup", "()V", nullptr, $PRIVATE, $method(Iocp, wakeup, void)},
	{}
};

#define _METHOD_INDEX_close0 4
#define _METHOD_INDEX_createIoCompletionPort 6
#define _METHOD_INDEX_getErrorMessage 10
#define _METHOD_INDEX_getQueuedCompletionStatus 11
#define _METHOD_INDEX_initIDs 13
#define _METHOD_INDEX_postQueuedCompletionStatus 16

$InnerClassInfo _Iocp_InnerClassesInfo_[] = {
	{"sun.nio.ch.Iocp$CompletionStatus", "sun.nio.ch.Iocp", "CompletionStatus", $PRIVATE | $STATIC},
	{"sun.nio.ch.Iocp$EventHandlerTask", "sun.nio.ch.Iocp", "EventHandlerTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.Iocp$OverlappedChannel", "sun.nio.ch.Iocp", "OverlappedChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.Iocp$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Iocp_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.Iocp",
	"sun.nio.ch.AsynchronousChannelGroupImpl",
	nullptr,
	_Iocp_FieldInfo_,
	_Iocp_MethodInfo_,
	nullptr,
	nullptr,
	_Iocp_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.Iocp$CompletionStatus,sun.nio.ch.Iocp$EventHandlerTask,sun.nio.ch.Iocp$ResultHandler,sun.nio.ch.Iocp$OverlappedChannel,sun.nio.ch.Iocp$1"
};

$Object* allocate$Iocp($Class* clazz) {
	return $of($alloc(Iocp));
}

$Unsafe* Iocp::unsafe = nullptr;

void Iocp::init$($AsynchronousChannelProvider* provider, $ThreadPool* pool) {
	$AsynchronousChannelGroupImpl::init$(provider, pool);
	$set(this, keyToChannelLock, $new($ReentrantReadWriteLock));
	$set(this, keyToChannel, $new($HashMap));
	$set(this, staleIoSet, $new($HashSet));
	this->port = createIoCompletionPort(Iocp::INVALID_HANDLE_VALUE, 0, 0, fixedThreadCount());
	this->nextCompletionKey = 1;
}

Iocp* Iocp::start() {
	startThreads($$new($Iocp$EventHandlerTask, this));
	return this;
}

void Iocp::implClose() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this) {
		if (this->closed) {
			return;
		}
		this->closed = true;
	}
	close0(this->port);
	$synchronized(this->staleIoSet) {
		{
			$var($Iterator, i$, $nc(this->staleIoSet)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Long, ov, $cast($Long, i$->next()));
				{
					$nc(Iocp::unsafe)->freeMemory($nc(ov)->longValue());
				}
			}
		}
		$nc(this->staleIoSet)->clear();
	}
}

bool Iocp::isEmpty() {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->keyToChannelLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = $nc(this->keyToChannel)->isEmpty();
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc($($nc(this->keyToChannelLock)->writeLock()))->unlock();
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

$Object* Iocp::attachForeignChannel($Channel* channel, $FileDescriptor* fdObj) {
	int32_t key = associate($$new($Iocp$1, this, channel), 0);
	return $of($Integer::valueOf(key));
}

void Iocp::detachForeignChannel(Object$* key) {
	disassociate($nc(($cast($Integer, key)))->intValue());
}

void Iocp::closeAllChannels() {
	$useLocalCurrentObjectStackCache();
	int32_t MAX_BATCH_SIZE = 32;
	$var($Iocp$OverlappedChannelArray, channels, $new($Iocp$OverlappedChannelArray, MAX_BATCH_SIZE));
	int32_t count = 0;
	do {
		$nc($($nc(this->keyToChannelLock)->writeLock()))->lock();
		count = 0;
		{
			$var($Throwable, var$0, nullptr);
			try {
				{
					$var($Iterator, i$, $nc($($nc(this->keyToChannel)->keySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Integer, key, $cast($Integer, i$->next()));
						{
							channels->set(count++, $cast($Iocp$OverlappedChannel, $($nc(this->keyToChannel)->get(key))));
							if (count >= MAX_BATCH_SIZE) {
								break;
							}
						}
					}
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc($($nc(this->keyToChannelLock)->writeLock()))->unlock();
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

void Iocp::wakeup() {
	try {
		postQueuedCompletionStatus(this->port, 0);
	} catch ($IOException& e) {
		$throwNew($AssertionError, $of(e));
	}
}

void Iocp::executeOnHandlerTask($Runnable* task) {
	$synchronized(this) {
		if (this->closed) {
			$throwNew($RejectedExecutionException);
		}
		offerTask(task);
		wakeup();
	}
}

void Iocp::shutdownHandlerTasks() {
	int32_t nThreads = threadCount();
	while (nThreads-- > 0) {
		wakeup();
	}
}

int32_t Iocp::associate($Iocp$OverlappedChannel* ch, int64_t handle) {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->keyToChannelLock)->writeLock()))->lock();
	int32_t key = 0;
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (isShutdown()) {
				$throwNew($ShutdownChannelGroupException);
			}
			do {
				key = this->nextCompletionKey++;
			} while ((key == 0) || $nc(this->keyToChannel)->containsKey($($Integer::valueOf(key))));
			if (handle != (int64_t)0) {
				createIoCompletionPort(handle, this->port, key, 0);
			}
			$nc(this->keyToChannel)->put($($Integer::valueOf(key)), ch);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc($($nc(this->keyToChannelLock)->writeLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return key;
}

void Iocp::disassociate(int32_t key) {
	$useLocalCurrentObjectStackCache();
	bool checkForShutdown = false;
	$nc($($nc(this->keyToChannelLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->keyToChannel)->remove($($Integer::valueOf(key)));
			if ($nc(this->keyToChannel)->isEmpty()) {
				checkForShutdown = true;
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc($($nc(this->keyToChannelLock)->writeLock()))->unlock();
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

void Iocp::makeStale($Long* overlapped) {
	$synchronized(this->staleIoSet) {
		$nc(this->staleIoSet)->add(overlapped);
	}
}

void Iocp::checkIfStale(int64_t ov) {
	$synchronized(this->staleIoSet) {
		bool removed = $nc(this->staleIoSet)->remove($($Long::valueOf(ov)));
		if (removed) {
			$nc(Iocp::unsafe)->freeMemory(ov);
		}
	}
}

$IOException* Iocp::translateErrorToIOException(int32_t error) {
	$init(Iocp);
	$useLocalCurrentObjectStackCache();
	$var($String, msg, getErrorMessage(error));
	if (msg == nullptr) {
		$assign(msg, $str({"Unknown error: 0x0"_s, $($Integer::toHexString(error))}));
	}
	return $new($IOException, msg);
}

void Iocp::initIDs() {
	$init(Iocp);
	$prepareNativeStatic(Iocp, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

int64_t Iocp::createIoCompletionPort(int64_t handle, int64_t existingPort, int32_t completionKey, int32_t concurrency) {
	$init(Iocp);
	int64_t $ret = 0;
	$prepareNativeStatic(Iocp, createIoCompletionPort, int64_t, int64_t handle, int64_t existingPort, int32_t completionKey, int32_t concurrency);
	$ret = $invokeNativeStatic(handle, existingPort, completionKey, concurrency);
	$finishNativeStatic();
	return $ret;
}

void Iocp::close0(int64_t handle) {
	$init(Iocp);
	$prepareNativeStatic(Iocp, close0, void, int64_t handle);
	$invokeNativeStatic(handle);
	$finishNativeStatic();
}

void Iocp::getQueuedCompletionStatus(int64_t completionPort, $Iocp$CompletionStatus* status) {
	$init(Iocp);
	$prepareNativeStatic(Iocp, getQueuedCompletionStatus, void, int64_t completionPort, $Iocp$CompletionStatus* status);
	$invokeNativeStatic(completionPort, status);
	$finishNativeStatic();
}

void Iocp::postQueuedCompletionStatus(int64_t completionPort, int32_t completionKey) {
	$init(Iocp);
	$prepareNativeStatic(Iocp, postQueuedCompletionStatus, void, int64_t completionPort, int32_t completionKey);
	$invokeNativeStatic(completionPort, completionKey);
	$finishNativeStatic();
}

$String* Iocp::getErrorMessage(int32_t error) {
	$init(Iocp);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(Iocp, getErrorMessage, $String*, int32_t error);
	$assign($ret, $invokeNativeStaticObject(error));
	$finishNativeStatic();
	return $ret;
}

void clinit$Iocp($Class* class$) {
	$assignStatic(Iocp::unsafe, $Unsafe::getUnsafe());
	{
		$IOUtil::load();
		Iocp::initIDs();
	}
}

Iocp::Iocp() {
}

$Class* Iocp::load$($String* name, bool initialize) {
	$loadClass(Iocp, name, initialize, &_Iocp_ClassInfo_, clinit$Iocp, allocate$Iocp);
	return class$;
}

$Class* Iocp::class$ = nullptr;

		} // ch
	} // nio
} // sun