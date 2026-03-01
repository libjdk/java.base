#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$WriteTask.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/InterruptedByTimeoutException.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/Util.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

#undef EOF
#undef MAX_VALUE
#undef OFFSETOF_BUF
#undef SIZEOF_WSABUF
#undef UNAVAILABLE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $InterruptedByTimeoutException = ::java::nio::channels::InterruptedByTimeoutException;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $Util = ::sun::nio::ch::Util;
using $WindowsAsynchronousSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousSocketChannelImpl$WriteTask_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowsAsynchronousSocketChannelImpl$WriteTask, $assertionsDisabled)},
	{"bufs", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, bufs)},
	{"numBufs", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, numBufs)},
	{"gatheringWrite", "Z", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, gatheringWrite)},
	{"result", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<TV;TA;>;", $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, result)},
	{"shadow", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, shadow)},
	{"scopeHandleReleasers", "Ljava/lang/Runnable;", nullptr, $PRIVATE, $field(WindowsAsynchronousSocketChannelImpl$WriteTask, scopeHandleReleasers)},
	{}
};

$MethodInfo _WindowsAsynchronousSocketChannelImpl$WriteTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;[Ljava/nio/ByteBuffer;ZLsun/nio/ch/PendingFuture;)V", "([Ljava/nio/ByteBuffer;ZLsun/nio/ch/PendingFuture<TV;TA;>;)V", 0, $method(WindowsAsynchronousSocketChannelImpl$WriteTask, init$, void, $WindowsAsynchronousSocketChannelImpl*, $ByteBufferArray*, bool, $PendingFuture*)},
	{"completed", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, completed, void, int32_t, bool)},
	{"failed", "(ILjava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, failed, void, int32_t, $IOException*)},
	{"prepareBuffers", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, prepareBuffers, void)},
	{"releaseBuffers", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, releaseBuffers, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, run, void)},
	{"timeout", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, timeout, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"updateBuffers", "(I)V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$WriteTask, updateBuffers, void, int32_t)},
	{}
};

$InnerClassInfo _WindowsAsynchronousSocketChannelImpl$WriteTask_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$WriteTask", "sun.nio.ch.WindowsAsynchronousSocketChannelImpl", "WriteTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WindowsAsynchronousSocketChannelImpl$WriteTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$WriteTask",
	"java.lang.Object",
	"java.lang.Runnable,sun.nio.ch.Iocp$ResultHandler",
	_WindowsAsynchronousSocketChannelImpl$WriteTask_FieldInfo_,
	_WindowsAsynchronousSocketChannelImpl$WriteTask_MethodInfo_,
	"<V:Ljava/lang/Object;A:Ljava/lang/Object;>Ljava/lang/Object;Ljava/lang/Runnable;Lsun/nio/ch/Iocp$ResultHandler;",
	nullptr,
	_WindowsAsynchronousSocketChannelImpl$WriteTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl"
};

$Object* allocate$WindowsAsynchronousSocketChannelImpl$WriteTask($Class* clazz) {
	return $of($alloc(WindowsAsynchronousSocketChannelImpl$WriteTask));
}

int32_t WindowsAsynchronousSocketChannelImpl$WriteTask::hashCode() {
	 return this->$Runnable::hashCode();
}

bool WindowsAsynchronousSocketChannelImpl$WriteTask::equals(Object$* obj) {
	 return this->$Runnable::equals(obj);
}

$Object* WindowsAsynchronousSocketChannelImpl$WriteTask::clone() {
	 return this->$Runnable::clone();
}

$String* WindowsAsynchronousSocketChannelImpl$WriteTask::toString() {
	 return this->$Runnable::toString();
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::finalize() {
	this->$Runnable::finalize();
}

bool WindowsAsynchronousSocketChannelImpl$WriteTask::$assertionsDisabled = false;

void WindowsAsynchronousSocketChannelImpl$WriteTask::init$($WindowsAsynchronousSocketChannelImpl* this$0, $ByteBufferArray* bufs, bool gatheringWrite, $PendingFuture* result) {
	$set(this, this$0, this$0);
	$set(this, bufs, bufs);
	this->numBufs = ($nc(bufs)->length > 16) ? 16 : $nc(bufs)->length;
	this->gatheringWrite = gatheringWrite;
	$set(this, result, result);
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::prepareBuffers() {
	$useLocalCurrentObjectStackCache();
	$set(this, scopeHandleReleasers, $IOUtil::acquireScopes(this->bufs));
	$set(this, shadow, $new($ByteBufferArray, this->numBufs));
	int64_t address = this->this$0->writeBufferArray;
	for (int32_t i = 0; i < this->numBufs; ++i) {
		$var($ByteBuffer, src, $nc(this->bufs)->get(i));
		int32_t pos = $nc(src)->position();
		int32_t lim = src->limit();
		if (!WindowsAsynchronousSocketChannelImpl$WriteTask::$assertionsDisabled && !(pos <= lim)) {
			$throwNew($AssertionError);
		}
		int32_t rem = (pos <= lim ? lim - pos : 0);
		int64_t a = 0;
		if (!($instanceOf($DirectBuffer, src))) {
			$var($ByteBuffer, bb, $Util::getTemporaryDirectBuffer(rem));
			$nc(bb)->put(src);
			bb->flip();
			src->position(pos);
			$nc(this->shadow)->set(i, bb);
			a = $IOUtil::bufferAddress(bb);
		} else {
			$nc(this->shadow)->set(i, src);
			a = $IOUtil::bufferAddress(src) + pos;
		}
		$init($WindowsAsynchronousSocketChannelImpl);
		$nc($WindowsAsynchronousSocketChannelImpl::unsafe)->putAddress(address + $WindowsAsynchronousSocketChannelImpl::OFFSETOF_BUF, a);
		$nc($WindowsAsynchronousSocketChannelImpl::unsafe)->putInt(address + 0, rem);
		address += $WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUF;
	}
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::updateBuffers(int32_t bytesWritten) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < this->numBufs; ++i) {
		$var($ByteBuffer, nextBuffer, $nc(this->bufs)->get(i));
		int32_t pos = $nc(nextBuffer)->position();
		int32_t lim = nextBuffer->limit();
		int32_t len = (pos <= lim ? lim - pos : lim);
		if (bytesWritten >= len) {
			bytesWritten -= len;
			int32_t newPosition = pos + len;
			try {
				nextBuffer->position(newPosition);
			} catch ($IllegalArgumentException& x) {
			}
		} else {
			if (bytesWritten > 0) {
				if (!WindowsAsynchronousSocketChannelImpl$WriteTask::$assertionsDisabled && !(pos + bytesWritten < (int64_t)$Integer::MAX_VALUE)) {
					$throwNew($AssertionError);
				}
				int32_t newPosition = pos + bytesWritten;
				try {
					nextBuffer->position(newPosition);
				} catch ($IllegalArgumentException& x) {
				}
			}
			break;
		}
	}
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::releaseBuffers() {
	for (int32_t i = 0; i < this->numBufs; ++i) {
		if (!($instanceOf($DirectBuffer, $nc(this->bufs)->get(i)))) {
			$Util::releaseTemporaryDirectBuffer($nc(this->shadow)->get(i));
		}
	}
	$IOUtil::releaseScopes(this->scopeHandleReleasers);
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::run() {
	int64_t overlapped = 0;
	bool prepared = false;
	bool pending = false;
	bool shutdown = false;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				this->this$0->begin();
				prepareBuffers();
				prepared = true;
				overlapped = $nc(this->this$0->ioCache)->add(this->result);
				int32_t n = $WindowsAsynchronousSocketChannelImpl::write0(this->this$0->handle$, this->numBufs, this->this$0->writeBufferArray, overlapped);
				if (n == $IOStatus::UNAVAILABLE) {
					pending = true;
					return$1 = true;
					goto $finally;
				}
				if (n == $IOStatus::EOF) {
					shutdown = true;
					$throwNew($ClosedChannelException);
				}
				$throwNew($InternalError, "Write completed immediately"_s);
			} catch ($Throwable& x) {
				this->this$0->enableWriting();
				if (!shutdown && ($instanceOf($ClosedChannelException, x))) {
					$assign(x, $new($AsynchronousCloseException));
				}
				if (!($instanceOf($IOException, x))) {
					$assign(x, $new($IOException, $cast($Throwable, x)));
				}
				$nc(this->result)->setFailure(x);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if (!pending) {
				if (overlapped != (int64_t)0) {
					$nc(this->this$0->ioCache)->remove(overlapped);
				}
				if (prepared) {
					releaseBuffers();
				}
			}
			this->this$0->end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	$Invoker::invoke(this->result);
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::completed(int32_t bytesTransferred, bool canInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	updateBuffers(bytesTransferred);
	releaseBuffers();
	$synchronized(this->result) {
		if ($nc(this->result)->isDone()) {
			return;
		}
		this->this$0->enableWriting();
		if (this->gatheringWrite) {
			$nc(this->result)->setResult($of($($Long::valueOf((int64_t)bytesTransferred))));
		} else {
			$nc(this->result)->setResult($of($($Integer::valueOf(bytesTransferred))));
		}
	}
	if (canInvokeDirect) {
		$Invoker::invokeUnchecked(this->result);
	} else {
		$Invoker::invoke(this->result);
	}
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::failed(int32_t error, $IOException* x$renamed) {
	$var($IOException, x, x$renamed);
	releaseBuffers();
	if (!this->this$0->isOpen()) {
		$assign(x, $new($AsynchronousCloseException));
	}
	$synchronized(this->result) {
		if ($nc(this->result)->isDone()) {
			return;
		}
		this->this$0->enableWriting();
		$nc(this->result)->setFailure(x);
	}
	$Invoker::invoke(this->result);
}

void WindowsAsynchronousSocketChannelImpl$WriteTask::timeout() {
	$synchronized(this->result) {
		if ($nc(this->result)->isDone()) {
			return;
		}
		this->this$0->enableWriting(true);
		$nc(this->result)->setFailure($$new($InterruptedByTimeoutException));
	}
	$Invoker::invoke(this->result);
}

void clinit$WindowsAsynchronousSocketChannelImpl$WriteTask($Class* class$) {
	$load($WindowsAsynchronousSocketChannelImpl);
	WindowsAsynchronousSocketChannelImpl$WriteTask::$assertionsDisabled = !$WindowsAsynchronousSocketChannelImpl::class$->desiredAssertionStatus();
}

WindowsAsynchronousSocketChannelImpl$WriteTask::WindowsAsynchronousSocketChannelImpl$WriteTask() {
}

$Class* WindowsAsynchronousSocketChannelImpl$WriteTask::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousSocketChannelImpl$WriteTask, name, initialize, &_WindowsAsynchronousSocketChannelImpl$WriteTask_ClassInfo_, clinit$WindowsAsynchronousSocketChannelImpl$WriteTask, allocate$WindowsAsynchronousSocketChannelImpl$WriteTask);
	return class$;
}

$Class* WindowsAsynchronousSocketChannelImpl$WriteTask::class$ = nullptr;

		} // ch
	} // nio
} // sun