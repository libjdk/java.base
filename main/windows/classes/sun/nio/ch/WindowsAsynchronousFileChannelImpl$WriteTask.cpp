#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$WriteTask.h>

#include <java/io/IOException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/Util.h>
#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl.h>
#include <jcpp.h>

#undef UNAVAILABLE

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $Invoker = ::sun::nio::ch::Invoker;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $Util = ::sun::nio::ch::Util;
using $WindowsAsynchronousFileChannelImpl = ::sun::nio::ch::WindowsAsynchronousFileChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousFileChannelImpl$WriteTask_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/WindowsAsynchronousFileChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WindowsAsynchronousFileChannelImpl$WriteTask, this$0)},
	{"src", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$WriteTask, src)},
	{"pos", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$WriteTask, pos)},
	{"rem", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$WriteTask, rem)},
	{"position", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$WriteTask, position)},
	{"result", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/lang/Integer;TA;>;", $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$WriteTask, result)},
	{"buf", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $VOLATILE, $field(WindowsAsynchronousFileChannelImpl$WriteTask, buf)},
	{}
};

$MethodInfo _WindowsAsynchronousFileChannelImpl$WriteTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/WindowsAsynchronousFileChannelImpl;Ljava/nio/ByteBuffer;IIJLsun/nio/ch/PendingFuture;)V", "(Ljava/nio/ByteBuffer;IIJLsun/nio/ch/PendingFuture<Ljava/lang/Integer;TA;>;)V", 0, $method(WindowsAsynchronousFileChannelImpl$WriteTask, init$, void, $WindowsAsynchronousFileChannelImpl*, $ByteBuffer*, int32_t, int32_t, int64_t, $PendingFuture*)},
	{"completed", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl$WriteTask, completed, void, int32_t, bool)},
	{"failed", "(ILjava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl$WriteTask, failed, void, int32_t, $IOException*)},
	{"releaseBufferIfSubstituted", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousFileChannelImpl$WriteTask, releaseBufferIfSubstituted, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl$WriteTask, run, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"updatePosition", "(I)V", nullptr, 0, $virtualMethod(WindowsAsynchronousFileChannelImpl$WriteTask, updatePosition, void, int32_t)},
	{}
};

$InnerClassInfo _WindowsAsynchronousFileChannelImpl$WriteTask_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$WriteTask", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "WriteTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WindowsAsynchronousFileChannelImpl$WriteTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl$WriteTask",
	"java.lang.Object",
	"java.lang.Runnable,sun.nio.ch.Iocp$ResultHandler",
	_WindowsAsynchronousFileChannelImpl$WriteTask_FieldInfo_,
	_WindowsAsynchronousFileChannelImpl$WriteTask_MethodInfo_,
	"<A:Ljava/lang/Object;>Ljava/lang/Object;Ljava/lang/Runnable;Lsun/nio/ch/Iocp$ResultHandler;",
	nullptr,
	_WindowsAsynchronousFileChannelImpl$WriteTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl"
};

$Object* allocate$WindowsAsynchronousFileChannelImpl$WriteTask($Class* clazz) {
	return $of($alloc(WindowsAsynchronousFileChannelImpl$WriteTask));
}

int32_t WindowsAsynchronousFileChannelImpl$WriteTask::hashCode() {
	 return this->$Runnable::hashCode();
}

bool WindowsAsynchronousFileChannelImpl$WriteTask::equals(Object$* obj) {
	 return this->$Runnable::equals(obj);
}

$Object* WindowsAsynchronousFileChannelImpl$WriteTask::clone() {
	 return this->$Runnable::clone();
}

$String* WindowsAsynchronousFileChannelImpl$WriteTask::toString() {
	 return this->$Runnable::toString();
}

void WindowsAsynchronousFileChannelImpl$WriteTask::finalize() {
	this->$Runnable::finalize();
}

void WindowsAsynchronousFileChannelImpl$WriteTask::init$($WindowsAsynchronousFileChannelImpl* this$0, $ByteBuffer* src, int32_t pos, int32_t rem, int64_t position, $PendingFuture* result) {
	$set(this, this$0, this$0);
	$set(this, src, src);
	this->pos = pos;
	this->rem = rem;
	this->position = position;
	$set(this, result, result);
}

void WindowsAsynchronousFileChannelImpl$WriteTask::releaseBufferIfSubstituted() {
	if (this->buf != this->src) {
		$Util::releaseTemporaryDirectBuffer(this->buf);
	}
}

void WindowsAsynchronousFileChannelImpl$WriteTask::updatePosition(int32_t bytesTransferred) {
	if (bytesTransferred > 0) {
		try {
			$nc(this->src)->position(this->pos + bytesTransferred);
		} catch ($IllegalArgumentException& x) {
		}
	}
}

void WindowsAsynchronousFileChannelImpl$WriteTask::run() {
	$useLocalCurrentObjectStackCache();
	int32_t n = -1;
	int64_t overlapped = 0;
	int64_t address = 0;
	if ($instanceOf($DirectBuffer, this->src)) {
		$set(this, buf, this->src);
		address = $nc(($cast($DirectBuffer, this->src)))->address() + this->pos;
	} else {
		$set(this, buf, $Util::getTemporaryDirectBuffer(this->rem));
		$nc(this->buf)->put(this->src);
		$nc(this->buf)->flip();
		$nc(this->src)->position(this->pos);
		address = $nc(($cast($DirectBuffer, this->buf)))->address();
	}
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				this->this$0->begin();
				overlapped = $nc(this->this$0->ioCache)->add(this->result);
				n = $WindowsAsynchronousFileChannelImpl::writeFile(this->this$0->handle, address, this->rem, this->position, overlapped);
				if (n == $IOStatus::UNAVAILABLE) {
					return$1 = true;
					goto $finally;
				} else {
					$throwNew($InternalError, $$str({"Unexpected result: "_s, $$str(n)}));
				}
			} catch ($Throwable& x) {
				$nc(this->result)->setFailure($($WindowsAsynchronousFileChannelImpl::toIOException(x)));
				releaseBufferIfSubstituted();
				if (overlapped != (int64_t)0) {
					$nc(this->this$0->ioCache)->remove(overlapped);
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
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

void WindowsAsynchronousFileChannelImpl$WriteTask::completed(int32_t bytesTransferred, bool canInvokeDirect) {
	updatePosition(bytesTransferred);
	releaseBufferIfSubstituted();
	$nc(this->result)->setResult($($Integer::valueOf(bytesTransferred)));
	if (canInvokeDirect) {
		$Invoker::invokeUnchecked(this->result);
	} else {
		$Invoker::invoke(this->result);
	}
}

void WindowsAsynchronousFileChannelImpl$WriteTask::failed(int32_t error, $IOException* x) {
	releaseBufferIfSubstituted();
	if (this->this$0->isOpen()) {
		$nc(this->result)->setFailure(x);
	} else {
		$nc(this->result)->setFailure($$new($AsynchronousCloseException));
	}
	$Invoker::invoke(this->result);
}

WindowsAsynchronousFileChannelImpl$WriteTask::WindowsAsynchronousFileChannelImpl$WriteTask() {
}

$Class* WindowsAsynchronousFileChannelImpl$WriteTask::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousFileChannelImpl$WriteTask, name, initialize, &_WindowsAsynchronousFileChannelImpl$WriteTask_ClassInfo_, allocate$WindowsAsynchronousFileChannelImpl$WriteTask);
	return class$;
}

$Class* WindowsAsynchronousFileChannelImpl$WriteTask::class$ = nullptr;

		} // ch
	} // nio
} // sun