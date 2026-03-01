#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$ConnectTask.h>

#include <java/io/IOException.h>
#include <java/lang/Runnable.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <sun/net/util/SocketExceptions.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

#undef UNAVAILABLE

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $SocketExceptions = ::sun::net::util::SocketExceptions;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $Invoker = ::sun::nio::ch::Invoker;
using $Net = ::sun::nio::ch::Net;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $WindowsAsynchronousSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousSocketChannelImpl$ConnectTask_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WindowsAsynchronousSocketChannelImpl$ConnectTask, this$0)},
	{"remote", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$ConnectTask, remote)},
	{"result", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/lang/Void;TA;>;", $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl$ConnectTask, result)},
	{}
};

$MethodInfo _WindowsAsynchronousSocketChannelImpl$ConnectTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;Ljava/net/InetSocketAddress;Lsun/nio/ch/PendingFuture;)V", "(Ljava/net/InetSocketAddress;Lsun/nio/ch/PendingFuture<Ljava/lang/Void;TA;>;)V", 0, $method(WindowsAsynchronousSocketChannelImpl$ConnectTask, init$, void, $WindowsAsynchronousSocketChannelImpl*, $InetSocketAddress*, $PendingFuture*)},
	{"afterConnect", "()V", nullptr, $PRIVATE, $method(WindowsAsynchronousSocketChannelImpl$ConnectTask, afterConnect, void), "java.io.IOException"},
	{"closeChannel", "()V", nullptr, $PRIVATE, $method(WindowsAsynchronousSocketChannelImpl$ConnectTask, closeChannel, void)},
	{"completed", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ConnectTask, completed, void, int32_t, bool)},
	{"failed", "(ILjava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ConnectTask, failed, void, int32_t, $IOException*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl$ConnectTask, run, void)},
	{"toIOException", "(Ljava/lang/Throwable;)Ljava/io/IOException;", nullptr, $PRIVATE, $method(WindowsAsynchronousSocketChannelImpl$ConnectTask, toIOException, $IOException*, $Throwable*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _WindowsAsynchronousSocketChannelImpl$ConnectTask_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ConnectTask", "sun.nio.ch.WindowsAsynchronousSocketChannelImpl", "ConnectTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WindowsAsynchronousSocketChannelImpl$ConnectTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ConnectTask",
	"java.lang.Object",
	"java.lang.Runnable,sun.nio.ch.Iocp$ResultHandler",
	_WindowsAsynchronousSocketChannelImpl$ConnectTask_FieldInfo_,
	_WindowsAsynchronousSocketChannelImpl$ConnectTask_MethodInfo_,
	"<A:Ljava/lang/Object;>Ljava/lang/Object;Ljava/lang/Runnable;Lsun/nio/ch/Iocp$ResultHandler;",
	nullptr,
	_WindowsAsynchronousSocketChannelImpl$ConnectTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl"
};

$Object* allocate$WindowsAsynchronousSocketChannelImpl$ConnectTask($Class* clazz) {
	return $of($alloc(WindowsAsynchronousSocketChannelImpl$ConnectTask));
}

int32_t WindowsAsynchronousSocketChannelImpl$ConnectTask::hashCode() {
	 return this->$Runnable::hashCode();
}

bool WindowsAsynchronousSocketChannelImpl$ConnectTask::equals(Object$* obj) {
	 return this->$Runnable::equals(obj);
}

$Object* WindowsAsynchronousSocketChannelImpl$ConnectTask::clone() {
	 return this->$Runnable::clone();
}

$String* WindowsAsynchronousSocketChannelImpl$ConnectTask::toString() {
	 return this->$Runnable::toString();
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::finalize() {
	this->$Runnable::finalize();
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::init$($WindowsAsynchronousSocketChannelImpl* this$0, $InetSocketAddress* remote, $PendingFuture* result) {
	$set(this, this$0, this$0);
	$set(this, remote, remote);
	$set(this, result, result);
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::closeChannel() {
	try {
		this->this$0->close();
	} catch ($IOException& ignore) {
	}
}

$IOException* WindowsAsynchronousSocketChannelImpl$ConnectTask::toIOException($Throwable* x$renamed) {
	$var($Throwable, x, x$renamed);
	if ($instanceOf($IOException, x)) {
		if ($instanceOf($ClosedChannelException, x)) {
			$assign(x, $new($AsynchronousCloseException));
		}
		return $cast($IOException, x);
	}
	return $new($IOException, x);
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::afterConnect() {
	$WindowsAsynchronousSocketChannelImpl::updateConnectContext(this->this$0->handle$);
	$synchronized(this->this$0->stateLock) {
		this->this$0->state = 2;
		$set(this->this$0, remoteAddress, this->remote);
	}
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::run() {
	$useLocalCurrentObjectStackCache();
	int64_t overlapped = 0;
	$var($Throwable, exc, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				this->this$0->begin();
				$synchronized(this->result) {
					overlapped = $nc(this->this$0->ioCache)->add(this->result);
					int64_t var$2 = this->this$0->handle$;
					bool var$3 = $Net::isIPv6Available();
					$var($InetAddress, var$4, $nc(this->remote)->getAddress());
					int32_t n = $WindowsAsynchronousSocketChannelImpl::connect0(var$2, var$3, var$4, $nc(this->remote)->getPort(), overlapped);
					if (n == $IOStatus::UNAVAILABLE) {
						return$1 = true;
						goto $finally;
					}
					afterConnect();
					$nc(this->result)->setResult(nullptr);
				}
			} catch ($Throwable& x) {
				if (overlapped != (int64_t)0) {
					$nc(this->this$0->ioCache)->remove(overlapped);
				}
				$assign(exc, x);
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
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
	if (exc != nullptr) {
		closeChannel();
		$assign(exc, $SocketExceptions::of($(toIOException(exc)), this->remote));
		$nc(this->result)->setFailure(exc);
	}
	$Invoker::invoke(this->result);
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::completed(int32_t bytesTransferred, bool canInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, exc, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				this->this$0->begin();
				afterConnect();
				$nc(this->result)->setResult(nullptr);
			} catch ($Throwable& x) {
				$assign(exc, x);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (exc != nullptr) {
		closeChannel();
		$var($IOException, ee, toIOException(exc));
		$assign(ee, $SocketExceptions::of(ee, this->remote));
		$nc(this->result)->setFailure(ee);
	}
	if (canInvokeDirect) {
		$Invoker::invokeUnchecked(this->result);
	} else {
		$Invoker::invoke(this->result);
	}
}

void WindowsAsynchronousSocketChannelImpl$ConnectTask::failed(int32_t error, $IOException* x$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($IOException, x, x$renamed);
	$assign(x, $SocketExceptions::of(x, this->remote));
	if (this->this$0->isOpen()) {
		closeChannel();
		$nc(this->result)->setFailure(x);
	} else {
		$assign(x, $SocketExceptions::of($$new($AsynchronousCloseException), this->remote));
		$nc(this->result)->setFailure(x);
	}
	$Invoker::invoke(this->result);
}

WindowsAsynchronousSocketChannelImpl$ConnectTask::WindowsAsynchronousSocketChannelImpl$ConnectTask() {
}

$Class* WindowsAsynchronousSocketChannelImpl$ConnectTask::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousSocketChannelImpl$ConnectTask, name, initialize, &_WindowsAsynchronousSocketChannelImpl$ConnectTask_ClassInfo_, allocate$WindowsAsynchronousSocketChannelImpl$ConnectTask);
	return class$;
}

$Class* WindowsAsynchronousSocketChannelImpl$ConnectTask::class$ = nullptr;

		} // ch
	} // nio
} // sun