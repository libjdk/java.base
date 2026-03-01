#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/FileLock.h>
#include <java/nio/channels/NonReadableChannelException.h>
#include <java/nio/channels/NonWritableChannelException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReadWriteLock.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/AsynchronousFileChannelImpl.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/FileDispatcher.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/FileLockImpl.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/Iocp$OverlappedChannel.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$DefaultIocpHolder.h>
#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$LockTask.h>
#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$ReadTask.h>
#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$WriteTask.h>
#include <jcpp.h>

#undef ERROR_HANDLE_EOF
#undef LOCKED
#undef NO_LOCK

using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $FileLock = ::java::nio::channels::FileLock;
using $NonReadableChannelException = ::java::nio::channels::NonReadableChannelException;
using $NonWritableChannelException = ::java::nio::channels::NonWritableChannelException;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $Future = ::java::util::concurrent::Future;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReadWriteLock = ::java::util::concurrent::locks::ReadWriteLock;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $AsynchronousFileChannelImpl = ::sun::nio::ch::AsynchronousFileChannelImpl;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $FileDispatcher = ::sun::nio::ch::FileDispatcher;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $FileLockImpl = ::sun::nio::ch::FileLockImpl;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $Iocp = ::sun::nio::ch::Iocp;
using $Iocp$OverlappedChannel = ::sun::nio::ch::Iocp$OverlappedChannel;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $WindowsAsynchronousFileChannelImpl$DefaultIocpHolder = ::sun::nio::ch::WindowsAsynchronousFileChannelImpl$DefaultIocpHolder;
using $WindowsAsynchronousFileChannelImpl$LockTask = ::sun::nio::ch::WindowsAsynchronousFileChannelImpl$LockTask;
using $WindowsAsynchronousFileChannelImpl$ReadTask = ::sun::nio::ch::WindowsAsynchronousFileChannelImpl$ReadTask;
using $WindowsAsynchronousFileChannelImpl$WriteTask = ::sun::nio::ch::WindowsAsynchronousFileChannelImpl$WriteTask;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousFileChannelImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowsAsynchronousFileChannelImpl, $assertionsDisabled)},
	{"fdAccess", "Ljdk/internal/access/JavaIOFileDescriptorAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousFileChannelImpl, fdAccess)},
	{"ERROR_HANDLE_EOF", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsAsynchronousFileChannelImpl, ERROR_HANDLE_EOF)},
	{"nd", "Lsun/nio/ch/FileDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousFileChannelImpl, nd)},
	{"handle", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl, handle)},
	{"completionKey", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl, completionKey)},
	{"iocp", "Lsun/nio/ch/Iocp;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl, iocp)},
	{"isDefaultIocp", "Z", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl, isDefaultIocp)},
	{"ioCache", "Lsun/nio/ch/PendingIoCache;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl, ioCache)},
	{"NO_LOCK", "I", nullptr, $STATIC | $FINAL, $constField(WindowsAsynchronousFileChannelImpl, NO_LOCK)},
	{"LOCKED", "I", nullptr, $STATIC | $FINAL, $constField(WindowsAsynchronousFileChannelImpl, LOCKED)},
	{}
};

$MethodInfo _WindowsAsynchronousFileChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/FileDescriptor;ZZLsun/nio/ch/Iocp;Z)V", nullptr, $PRIVATE, $method(WindowsAsynchronousFileChannelImpl, init$, void, $FileDescriptor*, bool, bool, $Iocp*, bool), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, close, void), "java.io.IOException"},
	{"force", "(Z)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, force, void, bool), "java.io.IOException"},
	{"getByOverlapped", "(J)Lsun/nio/ch/PendingFuture;", "<V:Ljava/lang/Object;A:Ljava/lang/Object;>(J)Lsun/nio/ch/PendingFuture<TV;TA;>;", $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, getByOverlapped, $PendingFuture*, int64_t)},
	{"group", "()Lsun/nio/ch/AsynchronousChannelGroupImpl;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, group, $AsynchronousChannelGroupImpl*)},
	{"implLock", "(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(JJZTA;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/FileLock;-TA;>;)Ljava/util/concurrent/Future<Ljava/nio/channels/FileLock;>;", 0, $virtualMethod(WindowsAsynchronousFileChannelImpl, implLock, $Future*, int64_t, int64_t, bool, Object$*, $CompletionHandler*)},
	{"implRead", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", 0, $virtualMethod(WindowsAsynchronousFileChannelImpl, implRead, $Future*, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"implRelease", "(Lsun/nio/ch/FileLockImpl;)V", nullptr, $PROTECTED, $virtualMethod(WindowsAsynchronousFileChannelImpl, implRelease, void, $FileLockImpl*), "java.io.IOException"},
	{"implWrite", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", 0, $virtualMethod(WindowsAsynchronousFileChannelImpl, implWrite, $Future*, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"lockFile", "(JJJZJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousFileChannelImpl, lockFile, int32_t, int64_t, int64_t, int64_t, bool, int64_t), "java.io.IOException"},
	{"open", "(Ljava/io/FileDescriptor;ZZLsun/nio/ch/ThreadPool;)Ljava/nio/channels/AsynchronousFileChannel;", nullptr, $PUBLIC | $STATIC, $staticMethod(WindowsAsynchronousFileChannelImpl, open, $AsynchronousFileChannel*, $FileDescriptor*, bool, bool, $ThreadPool*), "java.io.IOException"},
	{"readFile", "(JJIJJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousFileChannelImpl, readFile, int32_t, int64_t, int64_t, int32_t, int64_t, int64_t), "java.io.IOException"},
	{"size", "()J", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, size, int64_t), "java.io.IOException"},
	{"toIOException", "(Ljava/lang/Throwable;)Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsAsynchronousFileChannelImpl, toIOException, $IOException*, $Throwable*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"truncate", "(J)Ljava/nio/channels/AsynchronousFileChannel;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, truncate, $AsynchronousFileChannel*, int64_t), "java.io.IOException"},
	{"tryLock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl, tryLock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{"writeFile", "(JJIJJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousFileChannelImpl, writeFile, int32_t, int64_t, int64_t, int32_t, int64_t, int64_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_lockFile 13
#define _METHOD_INDEX_readFile 15
#define _METHOD_INDEX_writeFile 21

$InnerClassInfo _WindowsAsynchronousFileChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.Iocp$OverlappedChannel", "sun.nio.ch.Iocp", "OverlappedChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$WriteTask", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "WriteTask", $PRIVATE},
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$ReadTask", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "ReadTask", $PRIVATE},
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$LockTask", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "LockTask", $PRIVATE},
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$DefaultIocpHolder", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "DefaultIocpHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WindowsAsynchronousFileChannelImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl",
	"sun.nio.ch.AsynchronousFileChannelImpl",
	"sun.nio.ch.Iocp$OverlappedChannel,sun.nio.ch.Groupable",
	_WindowsAsynchronousFileChannelImpl_FieldInfo_,
	_WindowsAsynchronousFileChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsAsynchronousFileChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl$WriteTask,sun.nio.ch.WindowsAsynchronousFileChannelImpl$ReadTask,sun.nio.ch.WindowsAsynchronousFileChannelImpl$LockTask,sun.nio.ch.WindowsAsynchronousFileChannelImpl$DefaultIocpHolder"
};

$Object* allocate$WindowsAsynchronousFileChannelImpl($Class* clazz) {
	return $of($alloc(WindowsAsynchronousFileChannelImpl));
}

int32_t WindowsAsynchronousFileChannelImpl::hashCode() {
	 return this->$AsynchronousFileChannelImpl::hashCode();
}

bool WindowsAsynchronousFileChannelImpl::equals(Object$* obj) {
	 return this->$AsynchronousFileChannelImpl::equals(obj);
}

$Object* WindowsAsynchronousFileChannelImpl::clone() {
	 return this->$AsynchronousFileChannelImpl::clone();
}

$String* WindowsAsynchronousFileChannelImpl::toString() {
	 return this->$AsynchronousFileChannelImpl::toString();
}

void WindowsAsynchronousFileChannelImpl::finalize() {
	this->$AsynchronousFileChannelImpl::finalize();
}

bool WindowsAsynchronousFileChannelImpl::$assertionsDisabled = false;
$JavaIOFileDescriptorAccess* WindowsAsynchronousFileChannelImpl::fdAccess = nullptr;
$FileDispatcher* WindowsAsynchronousFileChannelImpl::nd = nullptr;

void WindowsAsynchronousFileChannelImpl::init$($FileDescriptor* fdObj, bool reading, bool writing, $Iocp* iocp, bool isDefaultIocp) {
	$AsynchronousFileChannelImpl::init$(fdObj, reading, writing, $($nc(iocp)->executor()));
	this->handle = $nc(WindowsAsynchronousFileChannelImpl::fdAccess)->getHandle(fdObj);
	$set(this, iocp, iocp);
	this->isDefaultIocp = isDefaultIocp;
	$set(this, ioCache, $new($PendingIoCache));
	this->completionKey = $nc(iocp)->associate(this, this->handle);
}

$AsynchronousFileChannel* WindowsAsynchronousFileChannelImpl::open($FileDescriptor* fdo, bool reading, bool writing, $ThreadPool* pool) {
	$init(WindowsAsynchronousFileChannelImpl);
	$useLocalCurrentObjectStackCache();
	$var($Iocp, iocp, nullptr);
	bool isDefaultIocp = false;
	if (pool == nullptr) {
		$init($WindowsAsynchronousFileChannelImpl$DefaultIocpHolder);
		$assign(iocp, $WindowsAsynchronousFileChannelImpl$DefaultIocpHolder::defaultIocp$);
		isDefaultIocp = true;
	} else {
		$assign(iocp, $$new($Iocp, nullptr, pool)->start());
		isDefaultIocp = false;
	}
	try {
		return $new(WindowsAsynchronousFileChannelImpl, fdo, reading, writing, iocp, isDefaultIocp);
	} catch ($IOException& x) {
		if (!isDefaultIocp) {
			$nc(iocp)->implClose();
		}
		$throw(x);
	}
	$shouldNotReachHere();
}

$PendingFuture* WindowsAsynchronousFileChannelImpl::getByOverlapped(int64_t overlapped) {
	return $nc(this->ioCache)->remove(overlapped);
}

void WindowsAsynchronousFileChannelImpl::close() {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->closeLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->closed) {
				return$1 = true;
				goto $finally;
			}
			this->closed = true;
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc($($nc(this->closeLock)->writeLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	invalidateAllLocks();
	$nc(WindowsAsynchronousFileChannelImpl::nd)->close(this->fdObj);
	$nc(this->ioCache)->close();
	$nc(this->iocp)->disassociate(this->completionKey);
	if (!this->isDefaultIocp) {
		$nc(this->iocp)->detachFromThreadPool();
	}
}

$AsynchronousChannelGroupImpl* WindowsAsynchronousFileChannelImpl::group() {
	return this->iocp;
}

$IOException* WindowsAsynchronousFileChannelImpl::toIOException($Throwable* x$renamed) {
	$init(WindowsAsynchronousFileChannelImpl);
	$var($Throwable, x, x$renamed);
	if ($instanceOf($IOException, x)) {
		if ($instanceOf($ClosedChannelException, x)) {
			$assign(x, $new($AsynchronousCloseException));
		}
		return $cast($IOException, x);
	}
	return $new($IOException, x);
}

int64_t WindowsAsynchronousFileChannelImpl::size() {
	{
		$var($Throwable, var$0, nullptr);
		int64_t var$2 = 0;
		bool return$1 = false;
		try {
			begin();
			var$2 = $nc(WindowsAsynchronousFileChannelImpl::nd)->size(this->fdObj);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			end();
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

$AsynchronousFileChannel* WindowsAsynchronousFileChannelImpl::truncate(int64_t size) {
	$useLocalCurrentObjectStackCache();
	if (size < 0) {
		$throwNew($IllegalArgumentException, "Negative size"_s);
	}
	if (!this->writing) {
		$throwNew($NonWritableChannelException);
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($AsynchronousFileChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			begin();
			if (size > $nc(WindowsAsynchronousFileChannelImpl::nd)->size(this->fdObj)) {
				$assign(var$2, this);
				return$1 = true;
				goto $finally;
			}
			$nc(WindowsAsynchronousFileChannelImpl::nd)->truncate(this->fdObj, size);
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return this;
}

void WindowsAsynchronousFileChannelImpl::force(bool metaData) {
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin();
			$nc(WindowsAsynchronousFileChannelImpl::nd)->force(this->fdObj, metaData);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Future* WindowsAsynchronousFileChannelImpl::implLock(int64_t position, int64_t size, bool shared, Object$* attachment, $CompletionHandler* handler) {
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
		$Invoker::invoke(this, handler, attachment, nullptr, exc);
		return nullptr;
	}
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($WindowsAsynchronousFileChannelImpl$LockTask, lockTask, $new($WindowsAsynchronousFileChannelImpl$LockTask, this, position, fli, result));
	result->setContext(lockTask);
	lockTask->run();
	return result;
}

$FileLock* WindowsAsynchronousFileChannelImpl::tryLock(int64_t position, int64_t size, bool shared) {
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
	bool gotLock = false;
	{
		$var($Throwable, var$0, nullptr);
		$var($FileLock, var$2, nullptr);
		bool return$1 = false;
		try {
			begin();
			int32_t res = $nc(WindowsAsynchronousFileChannelImpl::nd)->lock(this->fdObj, false, position, size, shared);
			if (res == WindowsAsynchronousFileChannelImpl::NO_LOCK) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			gotLock = true;
			$assign(var$2, fli);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (!gotLock) {
				removeFromFileLockTable(fli);
			}
			end();
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

void WindowsAsynchronousFileChannelImpl::implRelease($FileLockImpl* fli) {
	$var($FileDescriptor, var$0, this->fdObj);
	int64_t var$1 = $nc(fli)->position();
	$nc(WindowsAsynchronousFileChannelImpl::nd)->release(var$0, var$1, fli->size());
}

$Future* WindowsAsynchronousFileChannelImpl::implRead($ByteBuffer* dst, int64_t position, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!this->reading) {
		$throwNew($NonReadableChannelException);
	}
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if ($nc(dst)->isReadOnly()) {
		$throwNew($IllegalArgumentException, "Read-only buffer"_s);
	}
	if (!isOpen()) {
		$var($Throwable, exc, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(exc);
		}
		$Invoker::invoke(this, handler, attachment, nullptr, exc);
		return nullptr;
	}
	int32_t pos = $nc(dst)->position();
	int32_t lim = dst->limit();
	if (!WindowsAsynchronousFileChannelImpl::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	if (rem == 0) {
		if (handler == nullptr) {
			return $CompletedFuture::withResult($($Integer::valueOf(0)));
		}
		$Invoker::invoke(this, handler, attachment, $($Integer::valueOf(0)), nullptr);
		return nullptr;
	}
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($WindowsAsynchronousFileChannelImpl$ReadTask, readTask, $new($WindowsAsynchronousFileChannelImpl$ReadTask, this, dst, pos, rem, position, result));
	result->setContext(readTask);
	readTask->run();
	return result;
}

$Future* WindowsAsynchronousFileChannelImpl::implWrite($ByteBuffer* src, int64_t position, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!this->writing) {
		$throwNew($NonWritableChannelException);
	}
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if (!isOpen()) {
		$var($Throwable, exc, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(exc);
		}
		$Invoker::invoke(this, handler, attachment, nullptr, exc);
		return nullptr;
	}
	int32_t pos = $nc(src)->position();
	int32_t lim = src->limit();
	if (!WindowsAsynchronousFileChannelImpl::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	if (rem == 0) {
		if (handler == nullptr) {
			return $CompletedFuture::withResult($($Integer::valueOf(0)));
		}
		$Invoker::invoke(this, handler, attachment, $($Integer::valueOf(0)), nullptr);
		return nullptr;
	}
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($WindowsAsynchronousFileChannelImpl$WriteTask, writeTask, $new($WindowsAsynchronousFileChannelImpl$WriteTask, this, src, pos, rem, position, result));
	result->setContext(writeTask);
	writeTask->run();
	return result;
}

int32_t WindowsAsynchronousFileChannelImpl::readFile(int64_t handle, int64_t address, int32_t len, int64_t offset, int64_t overlapped) {
	$init(WindowsAsynchronousFileChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousFileChannelImpl, readFile, int32_t, int64_t handle, int64_t address, int32_t len, int64_t offset, int64_t overlapped);
	$ret = $invokeNativeStatic(handle, address, len, offset, overlapped);
	$finishNativeStatic();
	return $ret;
}

int32_t WindowsAsynchronousFileChannelImpl::writeFile(int64_t handle, int64_t address, int32_t len, int64_t offset, int64_t overlapped) {
	$init(WindowsAsynchronousFileChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousFileChannelImpl, writeFile, int32_t, int64_t handle, int64_t address, int32_t len, int64_t offset, int64_t overlapped);
	$ret = $invokeNativeStatic(handle, address, len, offset, overlapped);
	$finishNativeStatic();
	return $ret;
}

int32_t WindowsAsynchronousFileChannelImpl::lockFile(int64_t handle, int64_t position, int64_t size, bool shared, int64_t overlapped) {
	$init(WindowsAsynchronousFileChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousFileChannelImpl, lockFile, int32_t, int64_t handle, int64_t position, int64_t size, bool shared, int64_t overlapped);
	$ret = $invokeNativeStatic(handle, position, size, shared, overlapped);
	$finishNativeStatic();
	return $ret;
}

void clinit$WindowsAsynchronousFileChannelImpl($Class* class$) {
	WindowsAsynchronousFileChannelImpl::$assertionsDisabled = !WindowsAsynchronousFileChannelImpl::class$->desiredAssertionStatus();
	$assignStatic(WindowsAsynchronousFileChannelImpl::fdAccess, $SharedSecrets::getJavaIOFileDescriptorAccess());
	$assignStatic(WindowsAsynchronousFileChannelImpl::nd, $new($FileDispatcherImpl));
	{
		$IOUtil::load();
	}
}

WindowsAsynchronousFileChannelImpl::WindowsAsynchronousFileChannelImpl() {
}

$Class* WindowsAsynchronousFileChannelImpl::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousFileChannelImpl, name, initialize, &_WindowsAsynchronousFileChannelImpl_ClassInfo_, clinit$WindowsAsynchronousFileChannelImpl, allocate$WindowsAsynchronousFileChannelImpl);
	return class$;
}

$Class* WindowsAsynchronousFileChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun