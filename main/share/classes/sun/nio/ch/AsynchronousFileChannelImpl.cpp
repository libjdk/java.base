#include <sun/nio/ch/AsynchronousFileChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/FileLock.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReadWriteLock.h>
#include <java/util/concurrent/locks/ReentrantReadWriteLock.h>
#include <sun/nio/ch/FileLockImpl.h>
#include <sun/nio/ch/FileLockTable.h>
#include <jcpp.h>

using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $Channel = ::java::nio::channels::Channel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $FileLock = ::java::nio::channels::FileLock;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Future = ::java::util::concurrent::Future;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReadWriteLock = ::java::util::concurrent::locks::ReadWriteLock;
using $ReentrantReadWriteLock = ::java::util::concurrent::locks::ReentrantReadWriteLock;
using $FileLockImpl = ::sun::nio::ch::FileLockImpl;
using $FileLockTable = ::sun::nio::ch::FileLockTable;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _AsynchronousFileChannelImpl_FieldInfo_[] = {
	{"closeLock", "Ljava/util/concurrent/locks/ReadWriteLock;", nullptr, $PROTECTED | $FINAL, $field(AsynchronousFileChannelImpl, closeLock)},
	{"closed", "Z", nullptr, $PROTECTED | $VOLATILE, $field(AsynchronousFileChannelImpl, closed)},
	{"fdObj", "Ljava/io/FileDescriptor;", nullptr, $PROTECTED | $FINAL, $field(AsynchronousFileChannelImpl, fdObj)},
	{"reading", "Z", nullptr, $PROTECTED | $FINAL, $field(AsynchronousFileChannelImpl, reading)},
	{"writing", "Z", nullptr, $PROTECTED | $FINAL, $field(AsynchronousFileChannelImpl, writing)},
	{"executor", "Ljava/util/concurrent/ExecutorService;", nullptr, $PROTECTED | $FINAL, $field(AsynchronousFileChannelImpl, executor$)},
	{"fileLockTable", "Lsun/nio/ch/FileLockTable;", nullptr, $PRIVATE | $VOLATILE, $field(AsynchronousFileChannelImpl, fileLockTable)},
	{}
};

$MethodInfo _AsynchronousFileChannelImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/io/FileDescriptor;ZZLjava/util/concurrent/ExecutorService;)V", nullptr, $PROTECTED, $method(AsynchronousFileChannelImpl, init$, void, $FileDescriptor*, bool, bool, $ExecutorService*)},
	{"addToFileLockTable", "(JJZ)Lsun/nio/ch/FileLockImpl;", nullptr, $PROTECTED | $FINAL, $method(AsynchronousFileChannelImpl, addToFileLockTable, $FileLockImpl*, int64_t, int64_t, bool)},
	{"begin", "()V", nullptr, $PROTECTED | $FINAL, $method(AsynchronousFileChannelImpl, begin, void), "java.io.IOException"},
	{"end", "()V", nullptr, $PROTECTED | $FINAL, $method(AsynchronousFileChannelImpl, end, void)},
	{"end", "(Z)V", nullptr, $PROTECTED | $FINAL, $method(AsynchronousFileChannelImpl, end, void, bool), "java.io.IOException"},
	{"ensureFileLockTableInitialized", "()V", nullptr, $FINAL, $method(AsynchronousFileChannelImpl, ensureFileLockTableInitialized, void), "java.io.IOException"},
	{"executor", "()Ljava/util/concurrent/ExecutorService;", nullptr, $FINAL, $method(AsynchronousFileChannelImpl, executor, $ExecutorService*)},
	{"implLock", "(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(JJZTA;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/FileLock;-TA;>;)Ljava/util/concurrent/Future<Ljava/nio/channels/FileLock;>;", $ABSTRACT, $virtualMethod(AsynchronousFileChannelImpl, implLock, $Future*, int64_t, int64_t, bool, Object$*, $CompletionHandler*)},
	{"implRead", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $ABSTRACT, $virtualMethod(AsynchronousFileChannelImpl, implRead, $Future*, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"implRelease", "(Lsun/nio/ch/FileLockImpl;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AsynchronousFileChannelImpl, implRelease, void, $FileLockImpl*), "java.io.IOException"},
	{"implWrite", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $ABSTRACT, $virtualMethod(AsynchronousFileChannelImpl, implWrite, $Future*, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"invalidateAllLocks", "()V", nullptr, $FINAL, $method(AsynchronousFileChannelImpl, invalidateAllLocks, void), "java.io.IOException"},
	{"isOpen", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, isOpen, bool)},
	{"lock", "(JJZ)Ljava/util/concurrent/Future;", "(JJZ)Ljava/util/concurrent/Future<Ljava/nio/channels/FileLock;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, lock, $Future*, int64_t, int64_t, bool)},
	{"lock", "(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(JJZTA;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/FileLock;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, lock, void, int64_t, int64_t, bool, Object$*, $CompletionHandler*)},
	{"read", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future;", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, read, $Future*, $ByteBuffer*, int64_t)},
	{"read", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, read, void, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"release", "(Lsun/nio/ch/FileLockImpl;)V", nullptr, $FINAL, $method(AsynchronousFileChannelImpl, release, void, $FileLockImpl*), "java.io.IOException"},
	{"removeFromFileLockTable", "(Lsun/nio/ch/FileLockImpl;)V", nullptr, $PROTECTED | $FINAL, $method(AsynchronousFileChannelImpl, removeFromFileLockTable, void, $FileLockImpl*)},
	{"write", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future;", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, write, $Future*, $ByteBuffer*, int64_t)},
	{"write", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousFileChannelImpl, write, void, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{}
};

$ClassInfo _AsynchronousFileChannelImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.ch.AsynchronousFileChannelImpl",
	"java.nio.channels.AsynchronousFileChannel",
	nullptr,
	_AsynchronousFileChannelImpl_FieldInfo_,
	_AsynchronousFileChannelImpl_MethodInfo_
};

$Object* allocate$AsynchronousFileChannelImpl($Class* clazz) {
	return $of($alloc(AsynchronousFileChannelImpl));
}

void AsynchronousFileChannelImpl::init$($FileDescriptor* fdObj, bool reading, bool writing, $ExecutorService* executor) {
	$AsynchronousFileChannel::init$();
	$set(this, closeLock, $new($ReentrantReadWriteLock));
	$set(this, fdObj, fdObj);
	this->reading = reading;
	this->writing = writing;
	$set(this, executor$, executor);
}

$ExecutorService* AsynchronousFileChannelImpl::executor() {
	return this->executor$;
}

bool AsynchronousFileChannelImpl::isOpen() {
	return !this->closed;
}

void AsynchronousFileChannelImpl::begin() {
	$nc($($nc(this->closeLock)->readLock()))->lock();
	if (this->closed) {
		$throwNew($ClosedChannelException);
	}
}

void AsynchronousFileChannelImpl::end() {
	$nc($($nc(this->closeLock)->readLock()))->unlock();
}

void AsynchronousFileChannelImpl::end(bool completed) {
	end();
	if (!completed && !isOpen()) {
		$throwNew($AsynchronousCloseException);
	}
}

$Future* AsynchronousFileChannelImpl::lock(int64_t position, int64_t size, bool shared) {
	return implLock(position, size, shared, nullptr, nullptr);
}

void AsynchronousFileChannelImpl::lock(int64_t position, int64_t size, bool shared, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	implLock(position, size, shared, attachment, handler);
}

void AsynchronousFileChannelImpl::ensureFileLockTableInitialized() {
	if (this->fileLockTable == nullptr) {
		$synchronized(this) {
			if (this->fileLockTable == nullptr) {
				$set(this, fileLockTable, $new($FileLockTable, this, this->fdObj));
			}
		}
	}
}

void AsynchronousFileChannelImpl::invalidateAllLocks() {
	$useLocalCurrentObjectStackCache();
	if (this->fileLockTable != nullptr) {
		{
			$var($Iterator, i$, $nc($($nc(this->fileLockTable)->removeAll()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($FileLock, fl, $cast($FileLock, i$->next()));
				{
					$synchronized(fl) {
						if ($nc(fl)->isValid()) {
							$var($FileLockImpl, fli, $cast($FileLockImpl, fl));
							implRelease(fli);
							fli->invalidate();
						}
					}
				}
			}
		}
	}
}

$FileLockImpl* AsynchronousFileChannelImpl::addToFileLockTable(int64_t position, int64_t size, bool shared) {
	$useLocalCurrentObjectStackCache();
	$var($FileLockImpl, fli, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($FileLockImpl, var$2, nullptr);
		bool return$1 = false;
		try {
			$nc($($nc(this->closeLock)->readLock()))->lock();
			if (this->closed) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			try {
				ensureFileLockTableInitialized();
			} catch ($IOException& x) {
				$throwNew($AssertionError, $of(x));
			}
			$assign(fli, $new($FileLockImpl, static_cast<$AsynchronousFileChannel*>(this), position, size, shared));
			$nc(this->fileLockTable)->add(fli);
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
	return fli;
}

void AsynchronousFileChannelImpl::removeFromFileLockTable($FileLockImpl* fli) {
	$nc(this->fileLockTable)->remove(fli);
}

void AsynchronousFileChannelImpl::release($FileLockImpl* fli) {
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin();
			implRelease(fli);
			removeFromFileLockTable(fli);
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

$Future* AsynchronousFileChannelImpl::read($ByteBuffer* dst, int64_t position) {
	return implRead(dst, position, nullptr, nullptr);
}

void AsynchronousFileChannelImpl::read($ByteBuffer* dst, int64_t position, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	implRead(dst, position, attachment, handler);
}

$Future* AsynchronousFileChannelImpl::write($ByteBuffer* src, int64_t position) {
	return implWrite(src, position, nullptr, nullptr);
}

void AsynchronousFileChannelImpl::write($ByteBuffer* src, int64_t position, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	implWrite(src, position, attachment, handler);
}

AsynchronousFileChannelImpl::AsynchronousFileChannelImpl() {
}

$Class* AsynchronousFileChannelImpl::load$($String* name, bool initialize) {
	$loadClass(AsynchronousFileChannelImpl, name, initialize, &_AsynchronousFileChannelImpl_ClassInfo_, allocate$AsynchronousFileChannelImpl);
	return class$;
}

$Class* AsynchronousFileChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun