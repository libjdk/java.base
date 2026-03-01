#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/FileLock.h>
#include <java/nio/channels/NonReadableChannelException.h>
#include <java/nio/channels/NonWritableChannelException.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReadWriteLock.h>
#include <sun/nio/ch/AsynchronousFileChannelImpl.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/FileDispatcher.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/FileLockImpl.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/NativeThreadSet.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl$1.h>
#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl$2.h>
#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl$3.h>
#include <sun/nio/ch/SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder.h>
#include <sun/nio/ch/ThreadPool.h>
#include <jcpp.h>

#undef INTERRUPTED
#undef LOCKED
#undef NO_LOCK

using $FileDescriptor = ::java::io::FileDescriptor;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $FileLock = ::java::nio::channels::FileLock;
using $NonReadableChannelException = ::java::nio::channels::NonReadableChannelException;
using $NonWritableChannelException = ::java::nio::channels::NonWritableChannelException;
using $Executor = ::java::util::concurrent::Executor;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Future = ::java::util::concurrent::Future;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReadWriteLock = ::java::util::concurrent::locks::ReadWriteLock;
using $AsynchronousFileChannelImpl = ::sun::nio::ch::AsynchronousFileChannelImpl;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $FileDispatcher = ::sun::nio::ch::FileDispatcher;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $FileLockImpl = ::sun::nio::ch::FileLockImpl;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $Invoker = ::sun::nio::ch::Invoker;
using $NativeThreadSet = ::sun::nio::ch::NativeThreadSet;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $SimpleAsynchronousFileChannelImpl$1 = ::sun::nio::ch::SimpleAsynchronousFileChannelImpl$1;
using $SimpleAsynchronousFileChannelImpl$2 = ::sun::nio::ch::SimpleAsynchronousFileChannelImpl$2;
using $SimpleAsynchronousFileChannelImpl$3 = ::sun::nio::ch::SimpleAsynchronousFileChannelImpl$3;
using $SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder = ::sun::nio::ch::SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder;
using $ThreadPool = ::sun::nio::ch::ThreadPool;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _SimpleAsynchronousFileChannelImpl_FieldInfo_[] = {
	{"nd", "Lsun/nio/ch/FileDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleAsynchronousFileChannelImpl, nd)},
	{"threads", "Lsun/nio/ch/NativeThreadSet;", nullptr, $PRIVATE | $FINAL, $field(SimpleAsynchronousFileChannelImpl, threads)},
	{}
};

$MethodInfo _SimpleAsynchronousFileChannelImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/io/FileDescriptor;ZZLjava/util/concurrent/ExecutorService;)V", nullptr, 0, $method(SimpleAsynchronousFileChannelImpl, init$, void, $FileDescriptor*, bool, bool, $ExecutorService*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl, close, void), "java.io.IOException"},
	{"force", "(Z)V", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl, force, void, bool), "java.io.IOException"},
	{"implLock", "(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(JJZTA;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/FileLock;-TA;>;)Ljava/util/concurrent/Future<Ljava/nio/channels/FileLock;>;", 0, $virtualMethod(SimpleAsynchronousFileChannelImpl, implLock, $Future*, int64_t, int64_t, bool, Object$*, $CompletionHandler*)},
	{"implRead", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", 0, $virtualMethod(SimpleAsynchronousFileChannelImpl, implRead, $Future*, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"implRelease", "(Lsun/nio/ch/FileLockImpl;)V", nullptr, $PROTECTED, $virtualMethod(SimpleAsynchronousFileChannelImpl, implRelease, void, $FileLockImpl*), "java.io.IOException"},
	{"implWrite", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", 0, $virtualMethod(SimpleAsynchronousFileChannelImpl, implWrite, $Future*, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"open", "(Ljava/io/FileDescriptor;ZZLsun/nio/ch/ThreadPool;)Ljava/nio/channels/AsynchronousFileChannel;", nullptr, $PUBLIC | $STATIC, $staticMethod(SimpleAsynchronousFileChannelImpl, open, $AsynchronousFileChannel*, $FileDescriptor*, bool, bool, $ThreadPool*)},
	{"size", "()J", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl, size, int64_t), "java.io.IOException"},
	{"truncate", "(J)Ljava/nio/channels/AsynchronousFileChannel;", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl, truncate, $AsynchronousFileChannel*, int64_t), "java.io.IOException"},
	{"tryLock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC, $virtualMethod(SimpleAsynchronousFileChannelImpl, tryLock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _SimpleAsynchronousFileChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder", "sun.nio.ch.SimpleAsynchronousFileChannelImpl", "DefaultExecutorHolder", $PRIVATE | $STATIC},
	{"sun.nio.ch.SimpleAsynchronousFileChannelImpl$3", nullptr, nullptr, 0},
	{"sun.nio.ch.SimpleAsynchronousFileChannelImpl$2", nullptr, nullptr, 0},
	{"sun.nio.ch.SimpleAsynchronousFileChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SimpleAsynchronousFileChannelImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl",
	"sun.nio.ch.AsynchronousFileChannelImpl",
	nullptr,
	_SimpleAsynchronousFileChannelImpl_FieldInfo_,
	_SimpleAsynchronousFileChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SimpleAsynchronousFileChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder,sun.nio.ch.SimpleAsynchronousFileChannelImpl$3,sun.nio.ch.SimpleAsynchronousFileChannelImpl$2,sun.nio.ch.SimpleAsynchronousFileChannelImpl$1"
};

$Object* allocate$SimpleAsynchronousFileChannelImpl($Class* clazz) {
	return $of($alloc(SimpleAsynchronousFileChannelImpl));
}

$FileDispatcher* SimpleAsynchronousFileChannelImpl::nd = nullptr;

void SimpleAsynchronousFileChannelImpl::init$($FileDescriptor* fdObj, bool reading, bool writing, $ExecutorService* executor) {
	$AsynchronousFileChannelImpl::init$(fdObj, reading, writing, executor);
	$set(this, threads, $new($NativeThreadSet, 2));
}

$AsynchronousFileChannel* SimpleAsynchronousFileChannelImpl::open($FileDescriptor* fdo, bool reading, bool writing, $ThreadPool* pool) {
	$init(SimpleAsynchronousFileChannelImpl);
	$init($SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder);
	$var($ExecutorService, executor, (pool == nullptr) ? $SimpleAsynchronousFileChannelImpl$DefaultExecutorHolder::defaultExecutor : $nc(pool)->executor());
	return $new(SimpleAsynchronousFileChannelImpl, fdo, reading, writing, executor);
}

void SimpleAsynchronousFileChannelImpl::close() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->fdObj) {
		if (this->closed) {
			return;
		}
		this->closed = true;
	}
	invalidateAllLocks();
	$nc(this->threads)->signalAndWait();
	$nc($($nc(this->closeLock)->writeLock()))->lock();
	{
		$nc($($nc(this->closeLock)->writeLock()))->unlock();
	}
	$nc(SimpleAsynchronousFileChannelImpl::nd)->close(this->fdObj);
}

int64_t SimpleAsynchronousFileChannelImpl::size() {
	$useLocalCurrentObjectStackCache();
	int32_t ti = $nc(this->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		int64_t var$2 = 0;
		bool return$1 = false;
		try {
			int64_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				int64_t var$5 = 0;
				bool return$4 = false;
				try {
					begin();
					do {
						n = $nc(SimpleAsynchronousFileChannelImpl::nd)->size(this->fdObj);
					} while ((n == $IOStatus::INTERRUPTED) && isOpen());
					var$5 = n;
					return$4 = true;
					goto $finally1;
				} catch ($Throwable& var$6) {
					$assign(var$3, var$6);
				} $finally1: {
					end(n >= (int64_t)0);
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
				if (return$4) {
					var$2 = var$5;
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$7) {
			$assign(var$0, var$7);
		} $finally: {
			$nc(this->threads)->remove(ti);
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

$AsynchronousFileChannel* SimpleAsynchronousFileChannelImpl::truncate(int64_t size) {
	$useLocalCurrentObjectStackCache();
	if (size < (int64_t)0) {
		$throwNew($IllegalArgumentException, "Negative size"_s);
	}
	if (!this->writing) {
		$throwNew($NonWritableChannelException);
	}
	int32_t ti = $nc(this->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		$var($AsynchronousFileChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			int64_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				$var($AsynchronousFileChannel, var$5, nullptr);
				bool return$4 = false;
				try {
					begin();
					do {
						n = $nc(SimpleAsynchronousFileChannelImpl::nd)->size(this->fdObj);
					} while ((n == $IOStatus::INTERRUPTED) && isOpen());
					if (size < n && isOpen()) {
						do {
							n = $nc(SimpleAsynchronousFileChannelImpl::nd)->truncate(this->fdObj, size);
						} while ((n == $IOStatus::INTERRUPTED) && isOpen());
					}
					$assign(var$5, this);
					return$4 = true;
					goto $finally1;
				} catch ($Throwable& var$6) {
					$assign(var$3, var$6);
				} $finally1: {
					end(n > 0);
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
				if (return$4) {
					$assign(var$2, var$5);
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$7) {
			$assign(var$0, var$7);
		} $finally: {
			$nc(this->threads)->remove(ti);
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

void SimpleAsynchronousFileChannelImpl::force(bool metaData) {
	$useLocalCurrentObjectStackCache();
	int32_t ti = $nc(this->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		try {
			int32_t n = 0;
			{
				$var($Throwable, var$1, nullptr);
				try {
					begin();
					do {
						n = $nc(SimpleAsynchronousFileChannelImpl::nd)->force(this->fdObj, metaData);
					} while ((n == $IOStatus::INTERRUPTED) && isOpen());
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					end(n >= 0);
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->threads)->remove(ti);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Future* SimpleAsynchronousFileChannelImpl::implLock(int64_t position, int64_t size, bool shared, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (shared && !this->reading) {
		$throwNew($NonReadableChannelException);
	}
	if (!shared && !this->writing) {
		$throwNew($NonWritableChannelException);
	}
	$var($FileLockImpl, fli, addToFileLockTable(position, size, shared));
	if (fli == nullptr) {
		$var($Throwable, exc, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(exc);
		}
		$Invoker::invokeIndirectly(handler, attachment, ($Object*)nullptr, exc, static_cast<$Executor*>(this->executor$));
		return nullptr;
	}
	$var($PendingFuture, result, (handler == nullptr) ? $new($PendingFuture, this) : ($PendingFuture*)nullptr);
	$var($Runnable, task, $new($SimpleAsynchronousFileChannelImpl$1, this, position, size, shared, fli, handler, result, attachment));
	bool executed = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->executor$)->execute(task);
			executed = true;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!executed) {
				removeFromFileLockTable(fli);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return result;
}

$FileLock* SimpleAsynchronousFileChannelImpl::tryLock(int64_t position, int64_t size, bool shared) {
	$useLocalCurrentObjectStackCache();
	if (shared && !this->reading) {
		$throwNew($NonReadableChannelException);
	}
	if (!shared && !this->writing) {
		$throwNew($NonWritableChannelException);
	}
	$var($FileLockImpl, fli, addToFileLockTable(position, size, shared));
	if (fli == nullptr) {
		$throwNew($ClosedChannelException);
	}
	int32_t ti = $nc(this->threads)->add();
	bool gotLock = false;
	{
		$var($Throwable, var$0, nullptr);
		$var($FileLock, var$2, nullptr);
		bool return$1 = false;
		try {
			begin();
			int32_t n = 0;
			do {
				n = $nc(SimpleAsynchronousFileChannelImpl::nd)->lock(this->fdObj, false, position, size, shared);
			} while ((n == $FileDispatcher::INTERRUPTED) && isOpen());
			if (n == $FileDispatcher::LOCKED && isOpen()) {
				gotLock = true;
				$assign(var$2, fli);
				return$1 = true;
				goto $finally;
			}
			if (n == $FileDispatcher::NO_LOCK) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			if (n == $FileDispatcher::INTERRUPTED) {
				$throwNew($AsynchronousCloseException);
			}
			$throwNew($AssertionError);
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (!gotLock) {
				removeFromFileLockTable(fli);
			}
			end();
			$nc(this->threads)->remove(ti);
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

void SimpleAsynchronousFileChannelImpl::implRelease($FileLockImpl* fli) {
	$var($FileDescriptor, var$0, this->fdObj);
	int64_t var$1 = $nc(fli)->position();
	$nc(SimpleAsynchronousFileChannelImpl::nd)->release(var$0, var$1, fli->size());
}

$Future* SimpleAsynchronousFileChannelImpl::implRead($ByteBuffer* dst, int64_t position, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if (!this->reading) {
		$throwNew($NonReadableChannelException);
	}
	if ($nc(dst)->isReadOnly()) {
		$throwNew($IllegalArgumentException, "Read-only buffer"_s);
	}
	bool var$0 = !isOpen();
	if (var$0 || ($nc(dst)->remaining() == 0)) {
		$var($Throwable, exc, (isOpen()) ? ($Throwable*)nullptr : static_cast<$Throwable*>($new($ClosedChannelException)));
		if (handler == nullptr) {
			return $CompletedFuture::withResult($($Integer::valueOf(0)), exc);
		}
		$Invoker::invokeIndirectly(handler, attachment, $($of($Integer::valueOf(0))), exc, static_cast<$Executor*>(this->executor$));
		return nullptr;
	}
	$var($PendingFuture, result, (handler == nullptr) ? $new($PendingFuture, this) : ($PendingFuture*)nullptr);
	$var($Runnable, task, $new($SimpleAsynchronousFileChannelImpl$2, this, dst, position, handler, result, attachment));
	$nc(this->executor$)->execute(task);
	return result;
}

$Future* SimpleAsynchronousFileChannelImpl::implWrite($ByteBuffer* src, int64_t position, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if (!this->writing) {
		$throwNew($NonWritableChannelException);
	}
	bool var$0 = !isOpen();
	if (var$0 || ($nc(src)->remaining() == 0)) {
		$var($Throwable, exc, (isOpen()) ? ($Throwable*)nullptr : static_cast<$Throwable*>($new($ClosedChannelException)));
		if (handler == nullptr) {
			return $CompletedFuture::withResult($($Integer::valueOf(0)), exc);
		}
		$Invoker::invokeIndirectly(handler, attachment, $($of($Integer::valueOf(0))), exc, static_cast<$Executor*>(this->executor$));
		return nullptr;
	}
	$var($PendingFuture, result, (handler == nullptr) ? $new($PendingFuture, this) : ($PendingFuture*)nullptr);
	$var($Runnable, task, $new($SimpleAsynchronousFileChannelImpl$3, this, src, position, handler, result, attachment));
	$nc(this->executor$)->execute(task);
	return result;
}

void clinit$SimpleAsynchronousFileChannelImpl($Class* class$) {
	$assignStatic(SimpleAsynchronousFileChannelImpl::nd, $new($FileDispatcherImpl));
}

SimpleAsynchronousFileChannelImpl::SimpleAsynchronousFileChannelImpl() {
}

$Class* SimpleAsynchronousFileChannelImpl::load$($String* name, bool initialize) {
	$loadClass(SimpleAsynchronousFileChannelImpl, name, initialize, &_SimpleAsynchronousFileChannelImpl_ClassInfo_, clinit$SimpleAsynchronousFileChannelImpl, allocate$SimpleAsynchronousFileChannelImpl);
	return class$;
}

$Class* SimpleAsynchronousFileChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun