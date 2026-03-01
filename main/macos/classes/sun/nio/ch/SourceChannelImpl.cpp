#include <sun/nio/ch/SourceChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/Pipe$SourceChannel.h>
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

#undef OP_READ
#undef POLLERR
#undef POLLHUP
#undef POLLIN
#undef POLLNVAL
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
using $Pipe$SourceChannel = ::java::nio::channels::Pipe$SourceChannel;
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

$FieldInfo _SourceChannelImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SourceChannelImpl, $assertionsDisabled)},
	{"nd", "Lsun/nio/ch/NativeDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SourceChannelImpl, nd)},
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(SourceChannelImpl, fd)},
	{"fdVal", "I", nullptr, $PRIVATE | $FINAL, $field(SourceChannelImpl, fdVal)},
	{"readLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(SourceChannelImpl, readLock)},
	{"stateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(SourceChannelImpl, stateLock)},
	{"ST_INUSE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SourceChannelImpl, ST_INUSE)},
	{"ST_CLOSING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SourceChannelImpl, ST_CLOSING)},
	{"ST_CLOSED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SourceChannelImpl, ST_CLOSED)},
	{"state", "I", nullptr, $PRIVATE, $field(SourceChannelImpl, state)},
	{"thread", "J", nullptr, $PRIVATE, $field(SourceChannelImpl, thread)},
	{}
};

$MethodInfo _SourceChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;Ljava/io/FileDescriptor;)V", nullptr, 0, $method(SourceChannelImpl, init$, void, $SelectorProvider*, $FileDescriptor*)},
	{"beginRead", "(Z)V", nullptr, $PRIVATE, $method(SourceChannelImpl, beginRead, void, bool), "java.nio.channels.ClosedChannelException"},
	{"endRead", "(ZZ)V", nullptr, $PRIVATE, $method(SourceChannelImpl, endRead, void, bool, bool), "java.nio.channels.AsynchronousCloseException"},
	{"getFD", "()Ljava/io/FileDescriptor;", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, getFD, $FileDescriptor*)},
	{"getFDVal", "()I", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, getFDVal, int32_t)},
	{"implCloseBlockingMode", "()V", nullptr, $PRIVATE, $method(SourceChannelImpl, implCloseBlockingMode, void), "java.io.IOException"},
	{"implCloseNonBlockingMode", "()V", nullptr, $PRIVATE, $method(SourceChannelImpl, implCloseNonBlockingMode, void), "java.io.IOException"},
	{"implCloseSelectableChannel", "()V", nullptr, $PROTECTED, $virtualMethod(SourceChannelImpl, implCloseSelectableChannel, void), "java.io.IOException"},
	{"implConfigureBlocking", "(Z)V", nullptr, $PROTECTED, $virtualMethod(SourceChannelImpl, implConfigureBlocking, void, bool), "java.io.IOException"},
	{"*isOpen", "()Z", nullptr, $PUBLIC | $FINAL},
	{"kill", "()V", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, kill, void)},
	{"read", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, read, int32_t, $ByteBuffer*), "java.io.IOException"},
	{"read", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, read, int64_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"read", "([Ljava/nio/ByteBuffer;)J", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, read, int64_t, $ByteBufferArray*), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"translateAndSetReadyOps", "(ILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, translateAndSetReadyOps, bool, int32_t, $SelectionKeyImpl*)},
	{"translateAndUpdateReadyOps", "(ILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, translateAndUpdateReadyOps, bool, int32_t, $SelectionKeyImpl*)},
	{"translateInterestOps", "(I)I", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, translateInterestOps, int32_t, int32_t)},
	{"translateReadyOps", "(IILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(SourceChannelImpl, translateReadyOps, bool, int32_t, int32_t, $SelectionKeyImpl*)},
	{"tryClose", "()Z", nullptr, $PRIVATE, $method(SourceChannelImpl, tryClose, bool), "java.io.IOException"},
	{"tryFinishClose", "()V", nullptr, $PRIVATE, $method(SourceChannelImpl, tryFinishClose, void)},
	{}
};

$InnerClassInfo _SourceChannelImpl_InnerClassesInfo_[] = {
	{"java.nio.channels.Pipe$SourceChannel", "java.nio.channels.Pipe", "SourceChannel", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SourceChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.SourceChannelImpl",
	"java.nio.channels.Pipe$SourceChannel",
	"sun.nio.ch.SelChImpl",
	_SourceChannelImpl_FieldInfo_,
	_SourceChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SourceChannelImpl_InnerClassesInfo_
};

$Object* allocate$SourceChannelImpl($Class* clazz) {
	return $of($alloc(SourceChannelImpl));
}

void SourceChannelImpl::close() {
	this->$Pipe$SourceChannel::close();
}

bool SourceChannelImpl::isOpen() {
	 return this->$Pipe$SourceChannel::isOpen();
}

int32_t SourceChannelImpl::hashCode() {
	 return this->$Pipe$SourceChannel::hashCode();
}

bool SourceChannelImpl::equals(Object$* obj) {
	 return this->$Pipe$SourceChannel::equals(obj);
}

$Object* SourceChannelImpl::clone() {
	 return this->$Pipe$SourceChannel::clone();
}

$String* SourceChannelImpl::toString() {
	 return this->$Pipe$SourceChannel::toString();
}

void SourceChannelImpl::finalize() {
	this->$Pipe$SourceChannel::finalize();
}

bool SourceChannelImpl::$assertionsDisabled = false;
$NativeDispatcher* SourceChannelImpl::nd = nullptr;

$FileDescriptor* SourceChannelImpl::getFD() {
	return this->fd;
}

int32_t SourceChannelImpl::getFDVal() {
	return this->fdVal;
}

void SourceChannelImpl::init$($SelectorProvider* sp, $FileDescriptor* fd) {
	$Pipe$SourceChannel::init$(sp);
	$set(this, readLock, $new($ReentrantLock));
	$set(this, stateLock, $new($Object));
	$set(this, fd, fd);
	this->fdVal = $IOUtil::fdVal(fd);
}

bool SourceChannelImpl::tryClose() {
	if (!SourceChannelImpl::$assertionsDisabled && !($Thread::holdsLock(this->stateLock) && this->state == SourceChannelImpl::ST_CLOSING)) {
		$throwNew($AssertionError);
	}
	if (this->thread == 0 && !isRegistered()) {
		this->state = SourceChannelImpl::ST_CLOSED;
		$nc(SourceChannelImpl::nd)->close(this->fd);
		return true;
	} else {
		return false;
	}
}

void SourceChannelImpl::tryFinishClose() {
	try {
		tryClose();
	} catch ($IOException& ignore) {
	}
}

void SourceChannelImpl::implCloseBlockingMode() {
	$synchronized(this->stateLock) {
		if (!SourceChannelImpl::$assertionsDisabled && !(this->state < SourceChannelImpl::ST_CLOSING)) {
			$throwNew($AssertionError);
		}
		this->state = SourceChannelImpl::ST_CLOSING;
		if (!tryClose()) {
			int64_t th = this->thread;
			if (th != 0) {
				$nc(SourceChannelImpl::nd)->preClose(this->fd);
				$NativeThread::signal(th);
			}
		}
	}
}

void SourceChannelImpl::implCloseNonBlockingMode() {
	$synchronized(this->stateLock) {
		if (!SourceChannelImpl::$assertionsDisabled && !(this->state < SourceChannelImpl::ST_CLOSING)) {
			$throwNew($AssertionError);
		}
		this->state = SourceChannelImpl::ST_CLOSING;
	}
	$nc(this->readLock)->lock();
	$nc(this->readLock)->unlock();
	$synchronized(this->stateLock) {
		if (this->state == SourceChannelImpl::ST_CLOSING) {
			tryClose();
		}
	}
}

void SourceChannelImpl::implCloseSelectableChannel() {
	if (!SourceChannelImpl::$assertionsDisabled && ! !isOpen()) {
		$throwNew($AssertionError);
	}
	if (isBlocking()) {
		implCloseBlockingMode();
	} else {
		implCloseNonBlockingMode();
	}
}

void SourceChannelImpl::kill() {
	$synchronized(this->stateLock) {
		if (!SourceChannelImpl::$assertionsDisabled && ! !isOpen()) {
			$throwNew($AssertionError);
		}
		if (this->state == SourceChannelImpl::ST_CLOSING) {
			tryFinishClose();
		}
	}
}

void SourceChannelImpl::implConfigureBlocking(bool block) {
	$nc(this->readLock)->lock();
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
			$nc(this->readLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool SourceChannelImpl::translateReadyOps(int32_t ops, int32_t initialOps, $SelectionKeyImpl* ski) {
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
	if ((((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLIN)) != 0) && (((int32_t)(intOps & (uint32_t)$SelectionKey::OP_READ)) != 0)) {
		newOps |= $SelectionKey::OP_READ;
	}
	ski->nioReadyOps(newOps);
	return ((int32_t)(newOps & (uint32_t)~oldOps)) != 0;
}

bool SourceChannelImpl::translateAndUpdateReadyOps(int32_t ops, $SelectionKeyImpl* ski) {
	return translateReadyOps(ops, $nc(ski)->nioReadyOps(), ski);
}

bool SourceChannelImpl::translateAndSetReadyOps(int32_t ops, $SelectionKeyImpl* ski) {
	return translateReadyOps(ops, 0, ski);
}

int32_t SourceChannelImpl::translateInterestOps(int32_t ops) {
	int32_t newOps = 0;
	if (ops == $SelectionKey::OP_READ) {
		$init($Net);
		newOps |= $Net::POLLIN;
	}
	return newOps;
}

void SourceChannelImpl::beginRead(bool blocking) {
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

void SourceChannelImpl::endRead(bool blocking, bool completed) {
	if (blocking) {
		$synchronized(this->stateLock) {
			this->thread = 0;
			if (this->state == SourceChannelImpl::ST_CLOSING) {
				tryFinishClose();
			}
		}
		end(completed);
	}
}

int32_t SourceChannelImpl::read($ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(dst);
	$nc(this->readLock)->lock();
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
					beginRead(blocking);
					n = $IOUtil::read(this->fd, dst, (int64_t)-1, SourceChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLIN);
								n = $IOUtil::read(this->fd, dst, (int64_t)-1, SourceChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endRead(blocking, n > 0);
					if (!SourceChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
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
			$nc(this->readLock)->unlock();
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

int64_t SourceChannelImpl::read($ByteBufferArray* dsts, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$Objects::checkFromIndexSize(offset, length, $nc(dsts)->length);
	$nc(this->readLock)->lock();
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
					beginRead(blocking);
					n = $IOUtil::read(this->fd, dsts, offset, length, SourceChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLIN);
								n = $IOUtil::read(this->fd, dsts, offset, length, SourceChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endRead(blocking, n > 0);
					if (!SourceChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
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
			$nc(this->readLock)->unlock();
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

int64_t SourceChannelImpl::read($ByteBufferArray* dsts) {
	return read(dsts, 0, $nc(dsts)->length);
}

void clinit$SourceChannelImpl($Class* class$) {
	SourceChannelImpl::$assertionsDisabled = !SourceChannelImpl::class$->desiredAssertionStatus();
	$assignStatic(SourceChannelImpl::nd, $new($FileDispatcherImpl));
}

SourceChannelImpl::SourceChannelImpl() {
}

$Class* SourceChannelImpl::load$($String* name, bool initialize) {
	$loadClass(SourceChannelImpl, name, initialize, &_SourceChannelImpl_ClassInfo_, clinit$SourceChannelImpl, allocate$SourceChannelImpl);
	return class$;
}

$Class* SourceChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun