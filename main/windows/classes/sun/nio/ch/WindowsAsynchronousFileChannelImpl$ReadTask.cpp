#include <sun/nio/ch/WindowsAsynchronousFileChannelImpl$ReadTask.h>

#include <java/io/IOException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/nio/BufferOverflowException.h>
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

#undef EOF
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
using $BufferOverflowException = ::java::nio::BufferOverflowException;
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

$FieldInfo _WindowsAsynchronousFileChannelImpl$ReadTask_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/WindowsAsynchronousFileChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WindowsAsynchronousFileChannelImpl$ReadTask, this$0)},
	{"dst", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$ReadTask, dst)},
	{"pos", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$ReadTask, pos)},
	{"rem", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$ReadTask, rem)},
	{"position", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$ReadTask, position)},
	{"result", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/lang/Integer;TA;>;", $PRIVATE | $FINAL, $field(WindowsAsynchronousFileChannelImpl$ReadTask, result)},
	{"buf", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $VOLATILE, $field(WindowsAsynchronousFileChannelImpl$ReadTask, buf)},
	{}
};

$MethodInfo _WindowsAsynchronousFileChannelImpl$ReadTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/WindowsAsynchronousFileChannelImpl;Ljava/nio/ByteBuffer;IIJLsun/nio/ch/PendingFuture;)V", "(Ljava/nio/ByteBuffer;IIJLsun/nio/ch/PendingFuture<Ljava/lang/Integer;TA;>;)V", 0, $method(WindowsAsynchronousFileChannelImpl$ReadTask, init$, void, $WindowsAsynchronousFileChannelImpl*, $ByteBuffer*, int32_t, int32_t, int64_t, $PendingFuture*)},
	{"completed", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl$ReadTask, completed, void, int32_t, bool)},
	{"failed", "(ILjava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl$ReadTask, failed, void, int32_t, $IOException*)},
	{"releaseBufferIfSubstituted", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousFileChannelImpl$ReadTask, releaseBufferIfSubstituted, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousFileChannelImpl$ReadTask, run, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"updatePosition", "(I)V", nullptr, 0, $virtualMethod(WindowsAsynchronousFileChannelImpl$ReadTask, updatePosition, void, int32_t)},
	{}
};

$InnerClassInfo _WindowsAsynchronousFileChannelImpl$ReadTask_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousFileChannelImpl$ReadTask", "sun.nio.ch.WindowsAsynchronousFileChannelImpl", "ReadTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WindowsAsynchronousFileChannelImpl$ReadTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl$ReadTask",
	"java.lang.Object",
	"java.lang.Runnable,sun.nio.ch.Iocp$ResultHandler",
	_WindowsAsynchronousFileChannelImpl$ReadTask_FieldInfo_,
	_WindowsAsynchronousFileChannelImpl$ReadTask_MethodInfo_,
	"<A:Ljava/lang/Object;>Ljava/lang/Object;Ljava/lang/Runnable;Lsun/nio/ch/Iocp$ResultHandler;",
	nullptr,
	_WindowsAsynchronousFileChannelImpl$ReadTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousFileChannelImpl"
};

$Object* allocate$WindowsAsynchronousFileChannelImpl$ReadTask($Class* clazz) {
	return $of($alloc(WindowsAsynchronousFileChannelImpl$ReadTask));
}

int32_t WindowsAsynchronousFileChannelImpl$ReadTask::hashCode() {
	 return this->$Runnable::hashCode();
}

bool WindowsAsynchronousFileChannelImpl$ReadTask::equals(Object$* obj) {
	 return this->$Runnable::equals(obj);
}

$Object* WindowsAsynchronousFileChannelImpl$ReadTask::clone() {
	 return this->$Runnable::clone();
}

$String* WindowsAsynchronousFileChannelImpl$ReadTask::toString() {
	 return this->$Runnable::toString();
}

void WindowsAsynchronousFileChannelImpl$ReadTask::finalize() {
	this->$Runnable::finalize();
}

void WindowsAsynchronousFileChannelImpl$ReadTask::init$($WindowsAsynchronousFileChannelImpl* this$0, $ByteBuffer* dst, int32_t pos, int32_t rem, int64_t position, $PendingFuture* result) {
	$set(this, this$0, this$0);
	$set(this, dst, dst);
	this->pos = pos;
	this->rem = rem;
	this->position = position;
	$set(this, result, result);
}

void WindowsAsynchronousFileChannelImpl$ReadTask::releaseBufferIfSubstituted() {
	if (this->buf != this->dst) {
		$Util::releaseTemporaryDirectBuffer(this->buf);
	}
}

void WindowsAsynchronousFileChannelImpl$ReadTask::updatePosition(int32_t bytesTransferred) {
	if (bytesTransferred > 0) {
		if (this->buf == this->dst) {
			try {
				$nc(this->dst)->position(this->pos + bytesTransferred);
			} catch ($IllegalArgumentException& x) {
			}
		} else {
			$nc($($nc(this->buf)->position(bytesTransferred)))->flip();
			try {
				$nc(this->dst)->put(this->buf);
			} catch ($BufferOverflowException& x) {
			}
		}
	}
}

void WindowsAsynchronousFileChannelImpl$ReadTask::run() {
	$useLocalCurrentObjectStackCache();
	int32_t n = -1;
	int64_t overlapped = 0;
	int64_t address = 0;
	if ($instanceOf($DirectBuffer, this->dst)) {
		$set(this, buf, this->dst);
		address = $nc(($cast($DirectBuffer, this->dst)))->address() + this->pos;
	} else {
		$set(this, buf, $Util::getTemporaryDirectBuffer(this->rem));
		address = $nc(($cast($DirectBuffer, this->buf)))->address();
	}
	bool pending = false;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				this->this$0->begin();
				overlapped = $nc(this->this$0->ioCache)->add(this->result);
				n = $WindowsAsynchronousFileChannelImpl::readFile(this->this$0->handle, address, this->rem, this->position, overlapped);
				if (n == $IOStatus::UNAVAILABLE) {
					pending = true;
					return$1 = true;
					goto $finally;
				} else if (n == $IOStatus::EOF) {
					$nc(this->result)->setResult($($Integer::valueOf(n)));
				} else {
					$throwNew($InternalError, $$str({"Unexpected result: "_s, $$str(n)}));
				}
			} catch ($Throwable& x) {
				$nc(this->result)->setFailure($($WindowsAsynchronousFileChannelImpl::toIOException(x)));
				if (overlapped != (int64_t)0) {
					$nc(this->this$0->ioCache)->remove(overlapped);
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if (!pending) {
				releaseBufferIfSubstituted();
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

void WindowsAsynchronousFileChannelImpl$ReadTask::completed(int32_t bytesTransferred, bool canInvokeDirect) {
	updatePosition(bytesTransferred);
	releaseBufferIfSubstituted();
	$nc(this->result)->setResult($($Integer::valueOf(bytesTransferred)));
	if (canInvokeDirect) {
		$Invoker::invokeUnchecked(this->result);
	} else {
		$Invoker::invoke(this->result);
	}
}

void WindowsAsynchronousFileChannelImpl$ReadTask::failed(int32_t error, $IOException* x) {
	if (error == 38) {
		completed(-1, false);
	} else {
		releaseBufferIfSubstituted();
		if (this->this$0->isOpen()) {
			$nc(this->result)->setFailure(x);
		} else {
			$nc(this->result)->setFailure($$new($AsynchronousCloseException));
		}
		$Invoker::invoke(this->result);
	}
}

WindowsAsynchronousFileChannelImpl$ReadTask::WindowsAsynchronousFileChannelImpl$ReadTask() {
}

$Class* WindowsAsynchronousFileChannelImpl$ReadTask::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousFileChannelImpl$ReadTask, name, initialize, &_WindowsAsynchronousFileChannelImpl$ReadTask_ClassInfo_, allocate$WindowsAsynchronousFileChannelImpl$ReadTask);
	return class$;
}

$Class* WindowsAsynchronousFileChannelImpl$ReadTask::class$ = nullptr;

		} // ch
	} // nio
} // sun