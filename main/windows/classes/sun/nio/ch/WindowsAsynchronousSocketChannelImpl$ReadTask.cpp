#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$ReadTask.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/nio/BufferOverflowException.h>
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
using $BufferOverflowException = ::java::nio::BufferOverflowException;
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

$FieldInfo _WindowsAsynchronousSocketChannelImpl$ReadTask_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowsAsynchronousSocketChannelImpl$ReadTask, $assertionsDisabled)},
	{"bufs", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, bufs)},
	{"numBufs", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, numBufs)},
	{"scatteringRead", "Z", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, scatteringRead)},
	{"result", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<TV;TA;>;", $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, result)},
	{"shadow", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, shadow)},
	{"scopeHandleReleasers", "Ljava/lang/Runnable;", nullptr, $PRIVATE, $field(WindowsAsynchronousSocketChannelImpl$ReadTask, scopeHandleReleasers)},
	{}
};

$MethodInfo _WindowsAsynchronousSocketChannelImpl$ReadTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;[Ljava/nio/ByteBuffer;ZLsun/nio/ch/PendingFuture;)V", "([Ljava/nio/ByteBuffer;ZLsun/nio/ch/PendingFuture<TV;TA;>;)V", 0, $method(WindowsAsynchronousSocketChannelImpl$ReadTask, init$, void, $WindowsAsynchronousSocketChannelImpl*, $ByteBufferArray*, bool, $PendingFuture*)},
	{"completed", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, completed, void, int32_t, bool)},
	{"failed", "(ILjava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, failed, void, int32_t, $IOException*)},
	{"prepareBuffers", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, prepareBuffers, void)},
	{"releaseBuffers", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, releaseBuffers, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, run, void)},
	{"timeout", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, timeout, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"updateBuffers", "(I)V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ReadTask, updateBuffers, void, int32_t)},
	{}
};

$InnerClassInfo _WindowsAsynchronousSocketChannelImpl$ReadTask_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ReadTask", "sun.nio.ch.WindowsAsynchronousSocketChannelImpl", "ReadTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WindowsAsynchronousSocketChannelImpl$ReadTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ReadTask",
	"java.lang.Object",
	"java.lang.Runnable,sun.nio.ch.Iocp$ResultHandler",
	_WindowsAsynchronousSocketChannelImpl$ReadTask_FieldInfo_,
	_WindowsAsynchronousSocketChannelImpl$ReadTask_MethodInfo_,
	"<V:Ljava/lang/Object;A:Ljava/lang/Object;>Ljava/lang/Object;Ljava/lang/Runnable;Lsun/nio/ch/Iocp$ResultHandler;",
	nullptr,
	_WindowsAsynchronousSocketChannelImpl$ReadTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl"
};

$Object* allocate$WindowsAsynchronousSocketChannelImpl$ReadTask($Class* clazz) {
	return $of($alloc(WindowsAsynchronousSocketChannelImpl$ReadTask));
}

int32_t WindowsAsynchronousSocketChannelImpl$ReadTask::hashCode() {
	 return this->$Runnable::hashCode();
}

bool WindowsAsynchronousSocketChannelImpl$ReadTask::equals(Object$* obj) {
	 return this->$Runnable::equals(obj);
}

$Object* WindowsAsynchronousSocketChannelImpl$ReadTask::clone() {
	 return this->$Runnable::clone();
}

$String* WindowsAsynchronousSocketChannelImpl$ReadTask::toString() {
	 return this->$Runnable::toString();
}

void WindowsAsynchronousSocketChannelImpl$ReadTask::finalize() {
	this->$Runnable::finalize();
}

bool WindowsAsynchronousSocketChannelImpl$ReadTask::$assertionsDisabled = false;

void WindowsAsynchronousSocketChannelImpl$ReadTask::init$($WindowsAsynchronousSocketChannelImpl* this$0, $ByteBufferArray* bufs, bool scatteringRead, $PendingFuture* result) {
	$set(this, this$0, this$0);
	$set(this, bufs, bufs);
	this->numBufs = ($nc(bufs)->length > 16) ? 16 : $nc(bufs)->length;
	this->scatteringRead = scatteringRead;
	$set(this, result, result);
}

void WindowsAsynchronousSocketChannelImpl$ReadTask::prepareBuffers() {
	$useLocalCurrentObjectStackCache();
	$set(this, scopeHandleReleasers, $IOUtil::acquireScopes(this->bufs));
	$set(this, shadow, $new($ByteBufferArray, this->numBufs));
	int64_t address = this->this$0->readBufferArray;
	for (int32_t i = 0; i < this->numBufs; ++i) {
		$var($ByteBuffer, dst, $nc(this->bufs)->get(i));
		int32_t pos = $nc(dst)->position();
		int32_t lim = dst->limit();
		if (!WindowsAsynchronousSocketChannelImpl$ReadTask::$assertionsDisabled && !(pos <= lim)) {
			$throwNew($AssertionError);
		}
		int32_t rem = (pos <= lim ? lim - pos : 0);
		int64_t a = 0;
		if (!($instanceOf($DirectBuffer, dst))) {
			$var($ByteBuffer, bb, $Util::getTemporaryDirectBuffer(rem));
			$nc(this->shadow)->set(i, bb);
			a = $IOUtil::bufferAddress(bb);
		} else {
			$nc(this->shadow)->set(i, dst);
			a = $IOUtil::bufferAddress(dst) + pos;
		}
		$init($WindowsAsynchronousSocketChannelImpl);
		$nc($WindowsAsynchronousSocketChannelImpl::unsafe)->putAddress(address + $WindowsAsynchronousSocketChannelImpl::OFFSETOF_BUF, a);
		$nc($WindowsAsynchronousSocketChannelImpl::unsafe)->putInt(address + 0, rem);
		address += $WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUF;
	}
}

void WindowsAsynchronousSocketChannelImpl$ReadTask::updateBuffers(int32_t bytesRead) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < this->numBufs; ++i) {
		$var($ByteBuffer, nextBuffer, $nc(this->shadow)->get(i));
		int32_t pos = $nc(nextBuffer)->position();
		int32_t len = nextBuffer->remaining();
		if (bytesRead >= len) {
			bytesRead -= len;
			int32_t newPosition = pos + len;
			try {
				nextBuffer->position(newPosition);
			} catch ($IllegalArgumentException& x) {
			}
		} else {
			if (bytesRead > 0) {
				if (!WindowsAsynchronousSocketChannelImpl$ReadTask::$assertionsDisabled && !(pos + bytesRead < (int64_t)$Integer::MAX_VALUE)) {
					$throwNew($AssertionError);
				}
				int32_t newPosition = pos + bytesRead;
				try {
					nextBuffer->position(newPosition);
				} catch ($IllegalArgumentException& x) {
				}
			}
			break;
		}
	}
	for (int32_t i = 0; i < this->numBufs; ++i) {
		if (!($instanceOf($DirectBuffer, $nc(this->bufs)->get(i)))) {
			$nc($nc(this->shadow)->get(i))->flip();
			try {
				$nc($nc(this->bufs)->get(i))->put($nc(this->shadow)->get(i));
			} catch ($BufferOverflowException& x) {
			}
		}
	}
}

void WindowsAsynchronousSocketChannelImpl$ReadTask::releaseBuffers() {
	for (int32_t i = 0; i < this->numBufs; ++i) {
		if (!($instanceOf($DirectBuffer, $nc(this->bufs)->get(i)))) {
			$Util::releaseTemporaryDirectBuffer($nc(this->shadow)->get(i));
		}
	}
	$IOUtil::releaseScopes(this->scopeHandleReleasers);
}

void WindowsAsynchronousSocketChannelImpl$ReadTask::run() {
	$useLocalCurrentObjectStackCache();
	int64_t overlapped = 0;
	bool prepared = false;
	bool pending = false;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				this->this$0->begin();
				prepareBuffers();
				prepared = true;
				overlapped = $nc(this->this$0->ioCache)->add(this->result);
				int32_t n = $WindowsAsynchronousSocketChannelImpl::read0(this->this$0->handle$, this->numBufs, this->this$0->readBufferArray, overlapped);
				if (n == $IOStatus::UNAVAILABLE) {
					pending = true;
					return$1 = true;
					goto $finally;
				}
				if (n == $IOStatus::EOF) {
					this->this$0->enableReading();
					if (this->scatteringRead) {
						$nc(this->result)->setResult($of($($Long::valueOf((int64_t)-1))));
					} else {
						$nc(this->result)->setResult($of($($Integer::valueOf(-1))));
					}
				} else {
					$throwNew($InternalError, "Read completed immediately"_s);
				}
			} catch ($Throwable& x) {
				this->this$0->enableReading();
				if ($instanceOf($ClosedChannelException, x)) {
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

void WindowsAsynchronousSocketChannelImpl$ReadTask::completed(int32_t bytesTransferred, bool canInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	if (bytesTransferred == 0) {
		bytesTransferred = -1;
	} else {
		updateBuffers(bytesTransferred);
	}
	releaseBuffers();
	$synchronized(this->result) {
		if ($nc(this->result)->isDone()) {
			return;
		}
		this->this$0->enableReading();
		if (this->scatteringRead) {
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

void WindowsAsynchronousSocketChannelImpl$ReadTask::failed(int32_t error, $IOException* x$renamed) {
	$var($IOException, x, x$renamed);
	releaseBuffers();
	if (!this->this$0->isOpen()) {
		$assign(x, $new($AsynchronousCloseException));
	}
	$synchronized(this->result) {
		if ($nc(this->result)->isDone()) {
			return;
		}
		this->this$0->enableReading();
		$nc(this->result)->setFailure(x);
	}
	$Invoker::invoke(this->result);
}

void WindowsAsynchronousSocketChannelImpl$ReadTask::timeout() {
	$synchronized(this->result) {
		if ($nc(this->result)->isDone()) {
			return;
		}
		this->this$0->enableReading(true);
		$nc(this->result)->setFailure($$new($InterruptedByTimeoutException));
	}
	$Invoker::invoke(this->result);
}

void clinit$WindowsAsynchronousSocketChannelImpl$ReadTask($Class* class$) {
	$load($WindowsAsynchronousSocketChannelImpl);
	WindowsAsynchronousSocketChannelImpl$ReadTask::$assertionsDisabled = !$WindowsAsynchronousSocketChannelImpl::class$->desiredAssertionStatus();
}

WindowsAsynchronousSocketChannelImpl$ReadTask::WindowsAsynchronousSocketChannelImpl$ReadTask() {
}

$Class* WindowsAsynchronousSocketChannelImpl$ReadTask::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousSocketChannelImpl$ReadTask, name, initialize, &_WindowsAsynchronousSocketChannelImpl$ReadTask_ClassInfo_, clinit$WindowsAsynchronousSocketChannelImpl$ReadTask, allocate$WindowsAsynchronousSocketChannelImpl$ReadTask);
	return class$;
}

$Class* WindowsAsynchronousSocketChannelImpl$ReadTask::class$ = nullptr;

		} // ch
	} // nio
} // sun