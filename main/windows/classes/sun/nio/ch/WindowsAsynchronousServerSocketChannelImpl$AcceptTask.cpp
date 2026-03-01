#include <sun/nio/ch/WindowsAsynchronousServerSocketChannelImpl$AcceptTask.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityException.h>
#include <java/net/InetSocketAddress.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/ShutdownChannelGroupException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/WindowsAsynchronousServerSocketChannelImpl$AcceptTask$1.h>
#include <sun/nio/ch/WindowsAsynchronousServerSocketChannelImpl.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

#undef UNAVAILABLE

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SecurityException = ::java::lang::SecurityException;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $ShutdownChannelGroupException = ::java::nio::channels::ShutdownChannelGroupException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $Invoker = ::sun::nio::ch::Invoker;
using $Iocp = ::sun::nio::ch::Iocp;
using $Net = ::sun::nio::ch::Net;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $WindowsAsynchronousServerSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousServerSocketChannelImpl;
using $WindowsAsynchronousServerSocketChannelImpl$AcceptTask$1 = ::sun::nio::ch::WindowsAsynchronousServerSocketChannelImpl$AcceptTask$1;
using $WindowsAsynchronousSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousServerSocketChannelImpl$AcceptTask_FieldInfo_[] = {
	{"this$0", "Lsun/nio/ch/WindowsAsynchronousServerSocketChannelImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, this$0)},
	{"channel", "Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, channel)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, acc)},
	{"result", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/nio/channels/AsynchronousSocketChannel;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, result)},
	{}
};

$MethodInfo _WindowsAsynchronousServerSocketChannelImpl$AcceptTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/WindowsAsynchronousServerSocketChannelImpl;Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;Ljava/security/AccessControlContext;Lsun/nio/ch/PendingFuture;)V", "(Lsun/nio/ch/WindowsAsynchronousSocketChannelImpl;Ljava/security/AccessControlContext;Lsun/nio/ch/PendingFuture<Ljava/nio/channels/AsynchronousSocketChannel;Ljava/lang/Object;>;)V", 0, $method(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, init$, void, $WindowsAsynchronousServerSocketChannelImpl*, $WindowsAsynchronousSocketChannelImpl*, $AccessControlContext*, $PendingFuture*)},
	{"closeChildChannel", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, closeChildChannel, void)},
	{"completed", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, completed, void, int32_t, bool)},
	{"enableAccept", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, enableAccept, void)},
	{"failed", "(ILjava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, failed, void, int32_t, $IOException*)},
	{"finishAccept", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, finishAccept, void), "java.io.IOException"},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, run, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _WindowsAsynchronousServerSocketChannelImpl$AcceptTask_InnerClassesInfo_[] = {
	{"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl$AcceptTask", "sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl", "AcceptTask", $PRIVATE},
	{"sun.nio.ch.Iocp$ResultHandler", "sun.nio.ch.Iocp", "ResultHandler", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl$AcceptTask$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WindowsAsynchronousServerSocketChannelImpl$AcceptTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl$AcceptTask",
	"java.lang.Object",
	"java.lang.Runnable,sun.nio.ch.Iocp$ResultHandler",
	_WindowsAsynchronousServerSocketChannelImpl$AcceptTask_FieldInfo_,
	_WindowsAsynchronousServerSocketChannelImpl$AcceptTask_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsAsynchronousServerSocketChannelImpl$AcceptTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl"
};

$Object* allocate$WindowsAsynchronousServerSocketChannelImpl$AcceptTask($Class* clazz) {
	return $of($alloc(WindowsAsynchronousServerSocketChannelImpl$AcceptTask));
}

int32_t WindowsAsynchronousServerSocketChannelImpl$AcceptTask::hashCode() {
	 return this->$Runnable::hashCode();
}

bool WindowsAsynchronousServerSocketChannelImpl$AcceptTask::equals(Object$* obj) {
	 return this->$Runnable::equals(obj);
}

$Object* WindowsAsynchronousServerSocketChannelImpl$AcceptTask::clone() {
	 return this->$Runnable::clone();
}

$String* WindowsAsynchronousServerSocketChannelImpl$AcceptTask::toString() {
	 return this->$Runnable::toString();
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::finalize() {
	this->$Runnable::finalize();
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::init$($WindowsAsynchronousServerSocketChannelImpl* this$0, $WindowsAsynchronousSocketChannelImpl* channel, $AccessControlContext* acc, $PendingFuture* result) {
	$set(this, this$0, this$0);
	$set(this, channel, channel);
	$set(this, acc, acc);
	$set(this, result, result);
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::enableAccept() {
	$nc(this->this$0->accepting)->set(false);
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::closeChildChannel() {
	try {
		$nc(this->channel)->close();
	} catch ($IOException& ignore) {
	}
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::finishAccept() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$WindowsAsynchronousServerSocketChannelImpl::updateAcceptContext(this->this$0->handle, $nc(this->channel)->handle());
	$var($InetSocketAddress, local, $Net::localAddress($nc(this->channel)->fd));
	$var($InetSocketAddress, remote, $Net::remoteAddress($nc(this->channel)->fd));
	$nc(this->channel)->setConnected(local, remote);
	if (this->acc != nullptr) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($WindowsAsynchronousServerSocketChannelImpl$AcceptTask$1, this, remote)), this->acc);
	}
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::run() {
	$useLocalCurrentObjectStackCache();
	int64_t overlapped = 0;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				this->this$0->begin();
				{
					$var($Throwable, var$2, nullptr);
					bool return$3 = false;
					try {
						$nc(this->channel)->begin();
						$synchronized(this->result) {
							overlapped = $nc(this->this$0->ioCache)->add(this->result);
							int32_t n = $WindowsAsynchronousServerSocketChannelImpl::accept0(this->this$0->handle, $nc(this->channel)->handle(), overlapped, this->this$0->dataBuffer);
							if (n == $IOStatus::UNAVAILABLE) {
								return$3 = true;
								goto $finally1;
							}
							finishAccept();
							enableAccept();
							$nc(this->result)->setResult(this->channel);
						}
					} catch ($Throwable& var$4) {
						$assign(var$2, var$4);
					} $finally1: {
						$nc(this->channel)->end();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
					if (return$3) {
						return$1 = true;
						goto $finally;
					}
				}
			} catch ($Throwable& x) {
				if (overlapped != (int64_t)0) {
					$nc(this->this$0->ioCache)->remove(overlapped);
				}
				closeChildChannel();
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				if (!($instanceOf($IOException, x)) && !($instanceOf($SecurityException, x))) {
					$assign(x, $new($IOException, $cast($Throwable, x)));
				}
				enableAccept();
				$nc(this->result)->setFailure(x);
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
	if ($nc(this->result)->isCancelled()) {
		closeChildChannel();
	}
	$Invoker::invokeIndirectly(this->result);
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::completed(int32_t bytesTransferred, bool canInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	try {
		if ($nc(this->this$0->iocp)->isShutdown()) {
			$throwNew($IOException, static_cast<$Throwable*>($$new($ShutdownChannelGroupException)));
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				this->this$0->begin();
				{
					$var($Throwable, var$1, nullptr);
					try {
						$nc(this->channel)->begin();
						finishAccept();
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						$nc(this->channel)->end();
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				this->this$0->end();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		enableAccept();
		$nc(this->result)->setResult(this->channel);
	} catch ($Throwable& x) {
		enableAccept();
		closeChildChannel();
		if ($instanceOf($ClosedChannelException, x)) {
			$assign(x, $new($AsynchronousCloseException));
		}
		if (!($instanceOf($IOException, x)) && !($instanceOf($SecurityException, x))) {
			$assign(x, $new($IOException, $cast($Throwable, x)));
		}
		$nc(this->result)->setFailure(x);
	}
	if ($nc(this->result)->isCancelled()) {
		closeChildChannel();
	}
	$Invoker::invokeIndirectly(this->result);
}

void WindowsAsynchronousServerSocketChannelImpl$AcceptTask::failed(int32_t error, $IOException* x) {
	enableAccept();
	closeChildChannel();
	if (this->this$0->isOpen()) {
		$nc(this->result)->setFailure(x);
	} else {
		$nc(this->result)->setFailure($$new($AsynchronousCloseException));
	}
	$Invoker::invokeIndirectly(this->result);
}

WindowsAsynchronousServerSocketChannelImpl$AcceptTask::WindowsAsynchronousServerSocketChannelImpl$AcceptTask() {
}

$Class* WindowsAsynchronousServerSocketChannelImpl$AcceptTask::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousServerSocketChannelImpl$AcceptTask, name, initialize, &_WindowsAsynchronousServerSocketChannelImpl$AcceptTask_ClassInfo_, allocate$WindowsAsynchronousServerSocketChannelImpl$AcceptTask);
	return class$;
}

$Class* WindowsAsynchronousServerSocketChannelImpl$AcceptTask::class$ = nullptr;

		} // ch
	} // nio
} // sun