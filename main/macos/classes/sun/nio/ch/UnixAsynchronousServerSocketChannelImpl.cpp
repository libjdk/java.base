#include <sun/nio/ch/UnixAsynchronousServerSocketChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/StackTraceElement.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/nio/channels/AcceptPendingException.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/NotYetBoundException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/AsynchronousServerSocketChannelImpl.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/Port$PollableChannel.h>
#include <sun/nio/ch/Port.h>
#include <sun/nio/ch/SocketDispatcher.h>
#include <sun/nio/ch/UnixAsynchronousServerSocketChannelImpl$1.h>
#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

#undef POLLIN
#undef UNAVAILABLE

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $InetSocketAddressArray = $Array<::java::net::InetSocketAddress>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $AcceptPendingException = ::java::nio::channels::AcceptPendingException;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $AsynchronousSocketChannel = ::java::nio::channels::AsynchronousSocketChannel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $NotYetBoundException = ::java::nio::channels::NotYetBoundException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Future = ::java::util::concurrent::Future;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $AsynchronousServerSocketChannelImpl = ::sun::nio::ch::AsynchronousServerSocketChannelImpl;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $Net = ::sun::nio::ch::Net;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $Port = ::sun::nio::ch::Port;
using $Port$PollableChannel = ::sun::nio::ch::Port$PollableChannel;
using $SocketDispatcher = ::sun::nio::ch::SocketDispatcher;
using $UnixAsynchronousServerSocketChannelImpl$1 = ::sun::nio::ch::UnixAsynchronousServerSocketChannelImpl$1;
using $UnixAsynchronousSocketChannelImpl = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _UnixAsynchronousServerSocketChannelImpl_FieldInfo_[] = {
	{"nd", "Lsun/nio/ch/NativeDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixAsynchronousServerSocketChannelImpl, nd)},
	{"port", "Lsun/nio/ch/Port;", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousServerSocketChannelImpl, port)},
	{"fdVal", "I", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousServerSocketChannelImpl, fdVal)},
	{"accepting", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousServerSocketChannelImpl, accepting)},
	{"updateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousServerSocketChannelImpl, updateLock)},
	{"acceptPending", "Z", nullptr, $PRIVATE, $field(UnixAsynchronousServerSocketChannelImpl, acceptPending)},
	{"acceptHandler", "Ljava/nio/channels/CompletionHandler;", "Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/AsynchronousSocketChannel;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousServerSocketChannelImpl, acceptHandler)},
	{"acceptAttachment", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(UnixAsynchronousServerSocketChannelImpl, acceptAttachment)},
	{"acceptFuture", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/nio/channels/AsynchronousSocketChannel;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousServerSocketChannelImpl, acceptFuture)},
	{"acceptAcc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE, $field(UnixAsynchronousServerSocketChannelImpl, acceptAcc)},
	{}
};

$MethodInfo _UnixAsynchronousServerSocketChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/Port;)V", nullptr, 0, $method(UnixAsynchronousServerSocketChannelImpl, init$, void, $Port*), "java.io.IOException"},
	{"enableAccept", "()V", nullptr, $PRIVATE, $method(UnixAsynchronousServerSocketChannelImpl, enableAccept, void)},
	{"finishAccept", "(Ljava/io/FileDescriptor;Ljava/net/InetSocketAddress;Ljava/security/AccessControlContext;)Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PRIVATE, $method(UnixAsynchronousServerSocketChannelImpl, finishAccept, $AsynchronousSocketChannel*, $FileDescriptor*, $InetSocketAddress*, $AccessControlContext*), "java.io.IOException,java.lang.SecurityException"},
	{"group", "()Lsun/nio/ch/AsynchronousChannelGroupImpl;", nullptr, $PUBLIC, $virtualMethod(UnixAsynchronousServerSocketChannelImpl, group, $AsynchronousChannelGroupImpl*)},
	{"implAccept", "(Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "(Ljava/lang/Object;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/AsynchronousSocketChannel;Ljava/lang/Object;>;)Ljava/util/concurrent/Future<Ljava/nio/channels/AsynchronousSocketChannel;>;", 0, $virtualMethod(UnixAsynchronousServerSocketChannelImpl, implAccept, $Future*, Object$*, $CompletionHandler*)},
	{"implClose", "()V", nullptr, 0, $virtualMethod(UnixAsynchronousServerSocketChannelImpl, implClose, void), "java.io.IOException"},
	{"onEvent", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(UnixAsynchronousServerSocketChannelImpl, onEvent, void, int32_t, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _UnixAsynchronousServerSocketChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.Port$PollableChannel", "sun.nio.ch.Port", "PollableChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.UnixAsynchronousServerSocketChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnixAsynchronousServerSocketChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.UnixAsynchronousServerSocketChannelImpl",
	"sun.nio.ch.AsynchronousServerSocketChannelImpl",
	"sun.nio.ch.Port$PollableChannel",
	_UnixAsynchronousServerSocketChannelImpl_FieldInfo_,
	_UnixAsynchronousServerSocketChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_UnixAsynchronousServerSocketChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.UnixAsynchronousServerSocketChannelImpl$1"
};

$Object* allocate$UnixAsynchronousServerSocketChannelImpl($Class* clazz) {
	return $of($alloc(UnixAsynchronousServerSocketChannelImpl));
}

void UnixAsynchronousServerSocketChannelImpl::close() {
	this->$AsynchronousServerSocketChannelImpl::close();
}

$String* UnixAsynchronousServerSocketChannelImpl::toString() {
	 return this->$AsynchronousServerSocketChannelImpl::toString();
}

int32_t UnixAsynchronousServerSocketChannelImpl::hashCode() {
	 return this->$AsynchronousServerSocketChannelImpl::hashCode();
}

bool UnixAsynchronousServerSocketChannelImpl::equals(Object$* obj) {
	 return this->$AsynchronousServerSocketChannelImpl::equals(obj);
}

$Object* UnixAsynchronousServerSocketChannelImpl::clone() {
	 return this->$AsynchronousServerSocketChannelImpl::clone();
}

void UnixAsynchronousServerSocketChannelImpl::finalize() {
	this->$AsynchronousServerSocketChannelImpl::finalize();
}

$NativeDispatcher* UnixAsynchronousServerSocketChannelImpl::nd = nullptr;

void UnixAsynchronousServerSocketChannelImpl::enableAccept() {
	$nc(this->accepting)->set(false);
}

void UnixAsynchronousServerSocketChannelImpl::init$($Port* port) {
	$AsynchronousServerSocketChannelImpl::init$(port);
	$set(this, accepting, $new($AtomicBoolean));
	$set(this, updateLock, $new($Object));
	try {
		$IOUtil::configureBlocking(this->fd, false);
	} catch ($IOException& x) {
		$nc(UnixAsynchronousServerSocketChannelImpl::nd)->close(this->fd);
		$throw(x);
	}
	$set(this, port, port);
	this->fdVal = $IOUtil::fdVal(this->fd);
	$nc(port)->register$(this->fdVal, this);
}

void UnixAsynchronousServerSocketChannelImpl::implClose() {
	$useLocalCurrentObjectStackCache();
	$nc(this->port)->unregister(this->fdVal);
	$nc(UnixAsynchronousServerSocketChannelImpl::nd)->close(this->fd);
	$var($CompletionHandler, handler, nullptr);
	$var($Object, att, nullptr);
	$var($PendingFuture, future, nullptr);
	$synchronized(this->updateLock) {
		if (!this->acceptPending) {
			return;
		}
		this->acceptPending = false;
		$assign(handler, this->acceptHandler);
		$assign(att, this->acceptAttachment);
		$assign(future, this->acceptFuture);
	}
	$var($AsynchronousCloseException, x, $new($AsynchronousCloseException));
	x->setStackTrace($$new($StackTraceElementArray, 0));
	if (handler == nullptr) {
		$nc(future)->setFailure(x);
	} else {
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, att, ($Object*)nullptr, static_cast<$Throwable*>(x));
	}
}

$AsynchronousChannelGroupImpl* UnixAsynchronousServerSocketChannelImpl::group() {
	return this->port;
}

void UnixAsynchronousServerSocketChannelImpl::onEvent(int32_t events, bool mayInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->updateLock) {
		if (!this->acceptPending) {
			return;
		}
		this->acceptPending = false;
	}
	$var($FileDescriptor, newfd, $new($FileDescriptor));
	$var($InetSocketAddressArray, isaa, $new($InetSocketAddressArray, 1));
	$var($Throwable, exc, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				begin();
				int32_t n = $Net::accept(this->fd, newfd, isaa);
				if (n == $IOStatus::UNAVAILABLE) {
					$synchronized(this->updateLock) {
						this->acceptPending = true;
					}
					$nc(this->port)->startPoll(this->fdVal, $Net::POLLIN);
					return$1 = true;
					goto $finally;
				}
			} catch ($Throwable& x) {
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				$assign(exc, x);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	$var($AsynchronousSocketChannel, child, nullptr);
	if (exc == nullptr) {
		try {
			$assign(child, finishAccept(newfd, isaa->get(0), this->acceptAcc));
		} catch ($Throwable& x) {
			if (!($instanceOf($IOException, x)) && !($instanceOf($SecurityException, x))) {
				$assign(x, $new($IOException, $cast($Throwable, x)));
			}
			$assign(exc, x);
		}
	}
	$var($CompletionHandler, handler, this->acceptHandler);
	$var($Object, att, this->acceptAttachment);
	$var($PendingFuture, future, this->acceptFuture);
	enableAccept();
	if (handler == nullptr) {
		$nc(future)->setResult(child, exc);
		if (child != nullptr && future->isCancelled()) {
			try {
				child->close();
			} catch ($IOException& ignore) {
			}
		}
	} else {
		$Invoker::invoke(this, handler, att, child, exc);
	}
}

$AsynchronousSocketChannel* UnixAsynchronousServerSocketChannelImpl::finishAccept($FileDescriptor* newfd, $InetSocketAddress* remote, $AccessControlContext* acc) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($AsynchronousSocketChannel, ch, nullptr);
	try {
		$assign(ch, $new($UnixAsynchronousSocketChannelImpl, this->port, newfd, remote));
	} catch ($IOException& x) {
		$nc(UnixAsynchronousServerSocketChannelImpl::nd)->close(newfd);
		$throw(x);
	}
	try {
		if (acc != nullptr) {
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($UnixAsynchronousServerSocketChannelImpl$1, this, remote)), acc);
		} else {
			$var($SecurityManager, sm, $System::getSecurityManager());
			if (sm != nullptr) {
				$var($String, var$0, $nc($($nc(remote)->getAddress()))->getHostAddress());
				sm->checkAccept(var$0, remote->getPort());
			}
		}
	} catch ($SecurityException& x) {
		try {
			$nc(ch)->close();
		} catch ($Throwable& suppressed) {
			x->addSuppressed(suppressed);
		}
		$throw(x);
	}
	return ch;
}

$Future* UnixAsynchronousServerSocketChannelImpl::implAccept(Object$* att, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!isOpen()) {
		$var($Throwable, e, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(e);
		} else {
			$Invoker::invoke(this, handler, att, nullptr, e);
			return nullptr;
		}
	}
	if (this->localAddress == nullptr) {
		$throwNew($NotYetBoundException);
	}
	if (isAcceptKilled()) {
		$throwNew($RuntimeException, "Accept not allowed due cancellation"_s);
	}
	if (!$nc(this->accepting)->compareAndSet(false, true)) {
		$throwNew($AcceptPendingException);
	}
	$var($FileDescriptor, newfd, $new($FileDescriptor));
	$var($InetSocketAddressArray, isaa, $new($InetSocketAddressArray, 1));
	$var($Throwable, exc, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($Future, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				begin();
				int32_t n = $Net::accept(this->fd, newfd, isaa);
				if (n == $IOStatus::UNAVAILABLE) {
					$var($PendingFuture, result, nullptr);
					$synchronized(this->updateLock) {
						if (handler == nullptr) {
							$set(this, acceptHandler, nullptr);
							$assign(result, $new($PendingFuture, this));
							$set(this, acceptFuture, result);
						} else {
							$set(this, acceptHandler, handler);
							$set(this, acceptAttachment, att);
						}
						$set(this, acceptAcc, ($System::getSecurityManager() == nullptr) ? ($AccessControlContext*)nullptr : $AccessController::getContext());
						this->acceptPending = true;
					}
					$nc(this->port)->startPoll(this->fdVal, $Net::POLLIN);
					$assign(var$2, result);
					return$1 = true;
					goto $finally;
				}
			} catch ($Throwable& x) {
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				$assign(exc, x);
			}
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
	$var($AsynchronousSocketChannel, child, nullptr);
	if (exc == nullptr) {
		try {
			$assign(child, finishAccept(newfd, isaa->get(0), nullptr));
		} catch ($Throwable& x) {
			$assign(exc, x);
		}
	}
	enableAccept();
	if (handler == nullptr) {
		return $CompletedFuture::withResult(child, exc);
	} else {
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, att, $of(child), exc);
		return nullptr;
	}
}

void clinit$UnixAsynchronousServerSocketChannelImpl($Class* class$) {
	$assignStatic(UnixAsynchronousServerSocketChannelImpl::nd, $new($SocketDispatcher));
}

UnixAsynchronousServerSocketChannelImpl::UnixAsynchronousServerSocketChannelImpl() {
}

$Class* UnixAsynchronousServerSocketChannelImpl::load$($String* name, bool initialize) {
	$loadClass(UnixAsynchronousServerSocketChannelImpl, name, initialize, &_UnixAsynchronousServerSocketChannelImpl_ClassInfo_, clinit$UnixAsynchronousServerSocketChannelImpl, allocate$UnixAsynchronousServerSocketChannelImpl);
	return class$;
}

$Class* UnixAsynchronousServerSocketChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun