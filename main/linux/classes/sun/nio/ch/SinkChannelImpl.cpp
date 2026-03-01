#include <sun/nio/ch/SinkChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/Pipe$SinkChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/NativeThread.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <jcpp.h>

#undef OP_WRITE
#undef POLLERR
#undef POLLHUP
#undef POLLNVAL
#undef POLLOUT
#undef ST_CLOSED
#undef ST_CLOSING
#undef ST_INUSE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $Pipe$SinkChannel = ::java::nio::channels::Pipe$SinkChannel;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $Objects = ::java::util::Objects;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $NativeThread = ::sun::nio::ch::NativeThread;
using $Net = ::sun::nio::ch::Net;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _SinkChannelImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SinkChannelImpl, $assertionsDisabled)},
	{"nd", "Lsun/nio/ch/NativeDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SinkChannelImpl, nd)},
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(SinkChannelImpl, fd)},
	{"fdVal", "I", nullptr, $PRIVATE | $FINAL, $field(SinkChannelImpl, fdVal)},
	{"writeLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(SinkChannelImpl, writeLock)},
	{"stateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(SinkChannelImpl, stateLock)},
	{"ST_INUSE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SinkChannelImpl, ST_INUSE)},
	{"ST_CLOSING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SinkChannelImpl, ST_CLOSING)},
	{"ST_CLOSED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SinkChannelImpl, ST_CLOSED)},
	{"state", "I", nullptr, $PRIVATE, $field(SinkChannelImpl, state)},
	{"thread", "J", nullptr, $PRIVATE, $field(SinkChannelImpl, thread)},
	{}
};

$MethodInfo _SinkChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;Ljava/io/FileDescriptor;)V", nullptr, 0, $method(SinkChannelImpl, init$, void, $SelectorProvider*, $FileDescriptor*)},
	{"beginWrite", "(Z)V", nullptr, $PRIVATE, $method(SinkChannelImpl, beginWrite, void, bool), "java.nio.channels.ClosedChannelException"},
	{"endWrite", "(ZZ)V", nullptr, $PRIVATE, $method(SinkChannelImpl, endWrite, void, bool, bool), "java.nio.channels.AsynchronousCloseException"},
	{"getFD", "()Ljava/io/FileDescriptor;", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, getFD, $FileDescriptor*)},
	{"getFDVal", "()I", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, getFDVal, int32_t)},
	{"implCloseBlockingMode", "()V", nullptr, $PRIVATE, $method(SinkChannelImpl, implCloseBlockingMode, void), "java.io.IOException"},
	{"implCloseNonBlockingMode", "()V", nullptr, $PRIVATE, $method(SinkChannelImpl, implCloseNonBlockingMode, void), "java.io.IOException"},
	{"implCloseSelectableChannel", "()V", nullptr, $PROTECTED, $virtualMethod(SinkChannelImpl, implCloseSelectableChannel, void), "java.io.IOException"},
	{"implConfigureBlocking", "(Z)V", nullptr, $PROTECTED, $virtualMethod(SinkChannelImpl, implConfigureBlocking, void, bool), "java.io.IOException"},
	{"*isOpen", "()Z", nullptr, $PUBLIC | $FINAL},
	{"kill", "()V", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, kill, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"translateAndSetReadyOps", "(ILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, translateAndSetReadyOps, bool, int32_t, $SelectionKeyImpl*)},
	{"translateAndUpdateReadyOps", "(ILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, translateAndUpdateReadyOps, bool, int32_t, $SelectionKeyImpl*)},
	{"translateInterestOps", "(I)I", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, translateInterestOps, int32_t, int32_t)},
	{"translateReadyOps", "(IILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, translateReadyOps, bool, int32_t, int32_t, $SelectionKeyImpl*)},
	{"tryClose", "()Z", nullptr, $PRIVATE, $method(SinkChannelImpl, tryClose, bool), "java.io.IOException"},
	{"tryFinishClose", "()V", nullptr, $PRIVATE, $method(SinkChannelImpl, tryFinishClose, void)},
	{"write", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, write, int32_t, $ByteBuffer*), "java.io.IOException"},
	{"write", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, write, int64_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"write", "([Ljava/nio/ByteBuffer;)J", nullptr, $PUBLIC, $virtualMethod(SinkChannelImpl, write, int64_t, $ByteBufferArray*), "java.io.IOException"},
	{}
};

$InnerClassInfo _SinkChannelImpl_InnerClassesInfo_[] = {
	{"java.nio.channels.Pipe$SinkChannel", "java.nio.channels.Pipe", "SinkChannel", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SinkChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.SinkChannelImpl",
	"java.nio.channels.Pipe$SinkChannel",
	"sun.nio.ch.SelChImpl",
	_SinkChannelImpl_FieldInfo_,
	_SinkChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SinkChannelImpl_InnerClassesInfo_
};

$Object* allocate$SinkChannelImpl($Class* clazz) {
	return $of($alloc(SinkChannelImpl));
}

void SinkChannelImpl::close() {
	this->$Pipe$SinkChannel::close();
}

bool SinkChannelImpl::isOpen() {
	 return this->$Pipe$SinkChannel::isOpen();
}

int32_t SinkChannelImpl::hashCode() {
	 return this->$Pipe$SinkChannel::hashCode();
}

bool SinkChannelImpl::equals(Object$* obj) {
	 return this->$Pipe$SinkChannel::equals(obj);
}

$Object* SinkChannelImpl::clone() {
	 return this->$Pipe$SinkChannel::clone();
}

$String* SinkChannelImpl::toString() {
	 return this->$Pipe$SinkChannel::toString();
}

void SinkChannelImpl::finalize() {
	this->$Pipe$SinkChannel::finalize();
}

bool SinkChannelImpl::$assertionsDisabled = false;
$NativeDispatcher* SinkChannelImpl::nd = nullptr;

$FileDescriptor* SinkChannelImpl::getFD() {
	return this->fd;
}

int32_t SinkChannelImpl::getFDVal() {
	return this->fdVal;
}

void SinkChannelImpl::init$($SelectorProvider* sp, $FileDescriptor* fd) {
	$Pipe$SinkChannel::init$(sp);
	$set(this, writeLock, $new($ReentrantLock));
	$set(this, stateLock, $new($Object));
	$set(this, fd, fd);
	this->fdVal = $IOUtil::fdVal(fd);
}

bool SinkChannelImpl::tryClose() {
	if (!SinkChannelImpl::$assertionsDisabled && !($Thread::holdsLock(this->stateLock) && this->state == SinkChannelImpl::ST_CLOSING)) {
		$throwNew($AssertionError);
	}
	if (this->thread == 0 && !isRegistered()) {
		this->state = SinkChannelImpl::ST_CLOSED;
		$nc(SinkChannelImpl::nd)->close(this->fd);
		return true;
	} else {
		return false;
	}
}

void SinkChannelImpl::tryFinishClose() {
	try {
		tryClose();
	} catch ($IOException& ignore) {
	}
}

void SinkChannelImpl::implCloseBlockingMode() {
	$synchronized(this->stateLock) {
		if (!SinkChannelImpl::$assertionsDisabled && !(this->state < SinkChannelImpl::ST_CLOSING)) {
			$throwNew($AssertionError);
		}
		this->state = SinkChannelImpl::ST_CLOSING;
		if (!tryClose()) {
			int64_t th = this->thread;
			if (th != 0) {
				$nc(SinkChannelImpl::nd)->preClose(this->fd);
				$NativeThread::signal(th);
			}
		}
	}
}

void SinkChannelImpl::implCloseNonBlockingMode() {
	$synchronized(this->stateLock) {
		if (!SinkChannelImpl::$assertionsDisabled && !(this->state < SinkChannelImpl::ST_CLOSING)) {
			$throwNew($AssertionError);
		}
		this->state = SinkChannelImpl::ST_CLOSING;
	}
	$nc(this->writeLock)->lock();
	$nc(this->writeLock)->unlock();
	$synchronized(this->stateLock) {
		if (this->state == SinkChannelImpl::ST_CLOSING) {
			tryClose();
		}
	}
}

void SinkChannelImpl::implCloseSelectableChannel() {
	if (!SinkChannelImpl::$assertionsDisabled && ! !isOpen()) {
		$throwNew($AssertionError);
	}
	if (isBlocking()) {
		implCloseBlockingMode();
	} else {
		implCloseNonBlockingMode();
	}
}

void SinkChannelImpl::kill() {
	$synchronized(this->stateLock) {
		if (this->state == SinkChannelImpl::ST_CLOSING) {
			tryFinishClose();
		}
	}
}

void SinkChannelImpl::implConfigureBlocking(bool block) {
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$synchronized(this->stateLock) {
				if (!isOpen()) {
					$throwNew($ClosedChannelException);
				}
				$IOUtil::configureBlocking(this->fd, block);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->writeLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SinkChannelImpl::translateReadyOps(int32_t ops, int32_t initialOps, $SelectionKeyImpl* ski) {
	int32_t intOps = $nc(ski)->nioInterestOps();
	int32_t oldOps = ski->nioReadyOps();
	int32_t newOps = initialOps;
	$init($Net);
	if (((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLNVAL)) != 0) {
		$throwNew($Error, "POLLNVAL detected"_s);
	}
	if (((int32_t)(ops & (uint32_t)($Net::POLLERR | $Net::POLLHUP))) != 0) {
		newOps = intOps;
		ski->nioReadyOps(newOps);
		return ((int32_t)(newOps & (uint32_t)~oldOps)) != 0;
	}
	if ((((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLOUT)) != 0) && (((int32_t)(intOps & (uint32_t)$SelectionKey::OP_WRITE)) != 0)) {
		newOps |= $SelectionKey::OP_WRITE;
	}
	ski->nioReadyOps(newOps);
	return ((int32_t)(newOps & (uint32_t)~oldOps)) != 0;
}

bool SinkChannelImpl::translateAndUpdateReadyOps(int32_t ops, $SelectionKeyImpl* ski) {
	return translateReadyOps(ops, $nc(ski)->nioReadyOps(), ski);
}

bool SinkChannelImpl::translateAndSetReadyOps(int32_t ops, $SelectionKeyImpl* ski) {
	return translateReadyOps(ops, 0, ski);
}

int32_t SinkChannelImpl::translateInterestOps(int32_t ops) {
	int32_t newOps = 0;
	if (ops == $SelectionKey::OP_WRITE) {
		$init($Net);
		newOps |= $Net::POLLOUT;
	}
	return newOps;
}

void SinkChannelImpl::beginWrite(bool blocking) {
	if (blocking) {
		begin();
	}
	$synchronized(this->stateLock) {
		if (!isOpen()) {
			$throwNew($ClosedChannelException);
		}
		if (blocking) {
			this->thread = $NativeThread::current();
		}
	}
}

void SinkChannelImpl::endWrite(bool blocking, bool completed) {
	if (blocking) {
		$synchronized(this->stateLock) {
			this->thread = 0;
			if (this->state == SinkChannelImpl::ST_CLOSING) {
				tryFinishClose();
			}
		}
		end(completed);
	}
}

int32_t SinkChannelImpl::write($ByteBuffer* src) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(src);
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int32_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				try {
					beginWrite(blocking);
					n = $IOUtil::write(this->fd, src, (int64_t)-1, SinkChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLOUT);
								n = $IOUtil::write(this->fd, src, (int64_t)-1, SinkChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endWrite(blocking, n > 0);
					if (!SinkChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			$nc(this->writeLock)->unlock();
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

int64_t SinkChannelImpl::write($ByteBufferArray* srcs, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$Objects::checkFromIndexSize(offset, length, $nc(srcs)->length);
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int64_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int64_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				try {
					beginWrite(blocking);
					n = $IOUtil::write(this->fd, srcs, offset, length, SinkChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLOUT);
								n = $IOUtil::write(this->fd, srcs, offset, length, SinkChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endWrite(blocking, n > 0);
					if (!SinkChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			$nc(this->writeLock)->unlock();
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

int64_t SinkChannelImpl::write($ByteBufferArray* srcs) {
	return write(srcs, 0, $nc(srcs)->length);
}

void clinit$SinkChannelImpl($Class* class$) {
	SinkChannelImpl::$assertionsDisabled = !SinkChannelImpl::class$->desiredAssertionStatus();
	$assignStatic(SinkChannelImpl::nd, $new($FileDispatcherImpl));
}

SinkChannelImpl::SinkChannelImpl() {
}

$Class* SinkChannelImpl::load$($String* name, bool initialize) {
	$loadClass(SinkChannelImpl, name, initialize, &_SinkChannelImpl_ClassInfo_, clinit$SinkChannelImpl, allocate$SinkChannelImpl);
	return class$;
}

$Class* SinkChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun