#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Number.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityManager.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AlreadyConnectedException.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/ConnectionPendingException.h>
#include <java/nio/channels/ShutdownChannelGroupException.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/TimeUnit.h>
#include <sun/net/ConnectionResetException.h>
#include <sun/net/NetHooks.h>
#include <sun/net/util/SocketExceptions.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/AsynchronousSocketChannelImpl.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker$GroupAndInvokeCount.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/Port$PollableChannel.h>
#include <sun/nio/ch/Port.h>
#include <sun/nio/ch/SocketDispatcher.h>
#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl$1.h>
#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl$2.h>
#include <sun/nio/ch/UnixAsynchronousSocketChannelImpl$OpType.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef CONNECT
#undef POLLERR
#undef POLLHUP
#undef POLLIN
#undef POLLOUT
#undef READ
#undef ST_CONNECTED
#undef ST_PENDING
#undef UNAVAILABLE
#undef WRITE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Number = ::java::lang::Number;
using $Runnable = ::java::lang::Runnable;
using $SecurityManager = ::java::lang::SecurityManager;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlreadyConnectedException = ::java::nio::channels::AlreadyConnectedException;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $ConnectionPendingException = ::java::nio::channels::ConnectionPendingException;
using $ShutdownChannelGroupException = ::java::nio::channels::ShutdownChannelGroupException;
using $Future = ::java::util::concurrent::Future;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $ConnectionResetException = ::sun::net::ConnectionResetException;
using $NetHooks = ::sun::net::NetHooks;
using $SocketExceptions = ::sun::net::util::SocketExceptions;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $AsynchronousSocketChannelImpl = ::sun::nio::ch::AsynchronousSocketChannelImpl;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $Invoker$GroupAndInvokeCount = ::sun::nio::ch::Invoker$GroupAndInvokeCount;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $Net = ::sun::nio::ch::Net;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $Port = ::sun::nio::ch::Port;
using $Port$PollableChannel = ::sun::nio::ch::Port$PollableChannel;
using $SocketDispatcher = ::sun::nio::ch::SocketDispatcher;
using $UnixAsynchronousSocketChannelImpl$1 = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl$1;
using $UnixAsynchronousSocketChannelImpl$2 = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl$2;
using $UnixAsynchronousSocketChannelImpl$OpType = ::sun::nio::ch::UnixAsynchronousSocketChannelImpl$OpType;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _UnixAsynchronousSocketChannelImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(UnixAsynchronousSocketChannelImpl, $assertionsDisabled)},
	{"nd", "Lsun/nio/ch/NativeDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixAsynchronousSocketChannelImpl, nd)},
	{"disableSynchronousRead", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixAsynchronousSocketChannelImpl, disableSynchronousRead)},
	{"port", "Lsun/nio/ch/Port;", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousSocketChannelImpl, port)},
	{"fdVal", "I", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousSocketChannelImpl, fdVal)},
	{"updateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(UnixAsynchronousSocketChannelImpl, updateLock)},
	{"connectPending", "Z", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, connectPending)},
	{"connectHandler", "Ljava/nio/channels/CompletionHandler;", "Ljava/nio/channels/CompletionHandler<Ljava/lang/Void;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, connectHandler)},
	{"connectAttachment", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, connectAttachment)},
	{"connectFuture", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/lang/Void;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, connectFuture)},
	{"pendingRemote", "Ljava/net/SocketAddress;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, pendingRemote)},
	{"readPending", "Z", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readPending)},
	{"isScatteringRead", "Z", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, isScatteringRead)},
	{"readBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readBuffer)},
	{"readBuffers", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readBuffers)},
	{"readScopeHandleReleasers", "Ljava/lang/Runnable;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readScopeHandleReleasers)},
	{"readHandler", "Ljava/nio/channels/CompletionHandler;", "Ljava/nio/channels/CompletionHandler<Ljava/lang/Number;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readHandler)},
	{"readAttachment", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readAttachment)},
	{"readFuture", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/lang/Number;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readFuture)},
	{"readTimer", "Ljava/util/concurrent/Future;", "Ljava/util/concurrent/Future<*>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readTimer)},
	{"writePending", "Z", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writePending)},
	{"isGatheringWrite", "Z", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, isGatheringWrite)},
	{"writeBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeBuffer)},
	{"writeBuffers", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeBuffers)},
	{"writeScopeHandleReleasers", "Ljava/lang/Runnable;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeScopeHandleReleasers)},
	{"writeHandler", "Ljava/nio/channels/CompletionHandler;", "Ljava/nio/channels/CompletionHandler<Ljava/lang/Number;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeHandler)},
	{"writeAttachment", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeAttachment)},
	{"writeFuture", "Lsun/nio/ch/PendingFuture;", "Lsun/nio/ch/PendingFuture<Ljava/lang/Number;Ljava/lang/Object;>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeFuture)},
	{"writeTimer", "Ljava/util/concurrent/Future;", "Ljava/util/concurrent/Future<*>;", $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeTimer)},
	{"readTimeoutTask", "Ljava/lang/Runnable;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, readTimeoutTask)},
	{"writeTimeoutTask", "Ljava/lang/Runnable;", nullptr, $PRIVATE, $field(UnixAsynchronousSocketChannelImpl, writeTimeoutTask)},
	{}
};

$MethodInfo _UnixAsynchronousSocketChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/Port;)V", nullptr, 0, $method(UnixAsynchronousSocketChannelImpl, init$, void, $Port*), "java.io.IOException"},
	{"<init>", "(Lsun/nio/ch/Port;Ljava/io/FileDescriptor;Ljava/net/InetSocketAddress;)V", nullptr, 0, $method(UnixAsynchronousSocketChannelImpl, init$, void, $Port*, $FileDescriptor*, $InetSocketAddress*), "java.io.IOException"},
	{"checkConnect", "(I)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(UnixAsynchronousSocketChannelImpl, checkConnect, void, int32_t), "java.io.IOException"},
	{"finish", "(ZZZ)V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, finish, void, bool, bool, bool)},
	{"finishConnect", "(Z)V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, finishConnect, void, bool)},
	{"finishRead", "(Z)V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, finishRead, void, bool)},
	{"finishWrite", "(Z)V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, finishWrite, void, bool)},
	{"group", "()Lsun/nio/ch/AsynchronousChannelGroupImpl;", nullptr, $PUBLIC, $virtualMethod(UnixAsynchronousSocketChannelImpl, group, $AsynchronousChannelGroupImpl*)},
	{"implClose", "()V", nullptr, 0, $virtualMethod(UnixAsynchronousSocketChannelImpl, implClose, void), "java.io.IOException"},
	{"implConnect", "(Ljava/net/SocketAddress;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/net/SocketAddress;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Void;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Void;>;", 0, $virtualMethod(UnixAsynchronousSocketChannelImpl, implConnect, $Future*, $SocketAddress*, Object$*, $CompletionHandler*)},
	{"implRead", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", 0, $virtualMethod(UnixAsynchronousSocketChannelImpl, implRead, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"implWrite", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", 0, $virtualMethod(UnixAsynchronousSocketChannelImpl, implWrite, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"lockAndUpdateEvents", "()V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, lockAndUpdateEvents, void)},
	{"onCancel", "(Lsun/nio/ch/PendingFuture;)V", "(Lsun/nio/ch/PendingFuture<**>;)V", $PUBLIC, $virtualMethod(UnixAsynchronousSocketChannelImpl, onCancel, void, $PendingFuture*)},
	{"onEvent", "(IZ)V", nullptr, $PUBLIC, $virtualMethod(UnixAsynchronousSocketChannelImpl, onEvent, void, int32_t, bool)},
	{"setConnected", "()V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, setConnected, void), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"updateEvents", "()V", nullptr, $PRIVATE, $method(UnixAsynchronousSocketChannelImpl, updateEvents, void)},
	{}
};

#define _METHOD_INDEX_checkConnect 7

$InnerClassInfo _UnixAsynchronousSocketChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.Port$PollableChannel", "sun.nio.ch.Port", "PollableChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.UnixAsynchronousSocketChannelImpl$OpType", "sun.nio.ch.UnixAsynchronousSocketChannelImpl", "OpType", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"sun.nio.ch.UnixAsynchronousSocketChannelImpl$2", nullptr, nullptr, 0},
	{"sun.nio.ch.UnixAsynchronousSocketChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnixAsynchronousSocketChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.UnixAsynchronousSocketChannelImpl",
	"sun.nio.ch.AsynchronousSocketChannelImpl",
	"sun.nio.ch.Port$PollableChannel",
	_UnixAsynchronousSocketChannelImpl_FieldInfo_,
	_UnixAsynchronousSocketChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_UnixAsynchronousSocketChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.UnixAsynchronousSocketChannelImpl$OpType,sun.nio.ch.UnixAsynchronousSocketChannelImpl$2,sun.nio.ch.UnixAsynchronousSocketChannelImpl$1"
};

$Object* allocate$UnixAsynchronousSocketChannelImpl($Class* clazz) {
	return $of($alloc(UnixAsynchronousSocketChannelImpl));
}

void UnixAsynchronousSocketChannelImpl::close() {
	this->$AsynchronousSocketChannelImpl::close();
}

$String* UnixAsynchronousSocketChannelImpl::toString() {
	 return this->$AsynchronousSocketChannelImpl::toString();
}

int32_t UnixAsynchronousSocketChannelImpl::hashCode() {
	 return this->$AsynchronousSocketChannelImpl::hashCode();
}

bool UnixAsynchronousSocketChannelImpl::equals(Object$* obj) {
	 return this->$AsynchronousSocketChannelImpl::equals(obj);
}

$Object* UnixAsynchronousSocketChannelImpl::clone() {
	 return this->$AsynchronousSocketChannelImpl::clone();
}

void UnixAsynchronousSocketChannelImpl::finalize() {
	this->$AsynchronousSocketChannelImpl::finalize();
}

bool UnixAsynchronousSocketChannelImpl::$assertionsDisabled = false;
$NativeDispatcher* UnixAsynchronousSocketChannelImpl::nd = nullptr;
bool UnixAsynchronousSocketChannelImpl::disableSynchronousRead = false;

void UnixAsynchronousSocketChannelImpl::init$($Port* port) {
	$AsynchronousSocketChannelImpl::init$(port);
	$set(this, updateLock, $new($Object));
	$set(this, readTimeoutTask, $new($UnixAsynchronousSocketChannelImpl$1, this));
	$set(this, writeTimeoutTask, $new($UnixAsynchronousSocketChannelImpl$2, this));
	try {
		$IOUtil::configureBlocking(this->fd, false);
	} catch ($IOException& x) {
		$nc(UnixAsynchronousSocketChannelImpl::nd)->close(this->fd);
		$throw(x);
	}
	$set(this, port, port);
	this->fdVal = $IOUtil::fdVal(this->fd);
	$nc(port)->register$(this->fdVal, this);
}

void UnixAsynchronousSocketChannelImpl::init$($Port* port, $FileDescriptor* fd, $InetSocketAddress* remote) {
	$AsynchronousSocketChannelImpl::init$(port, fd, remote);
	$set(this, updateLock, $new($Object));
	$set(this, readTimeoutTask, $new($UnixAsynchronousSocketChannelImpl$1, this));
	$set(this, writeTimeoutTask, $new($UnixAsynchronousSocketChannelImpl$2, this));
	this->fdVal = $IOUtil::fdVal(fd);
	$IOUtil::configureBlocking(fd, false);
	try {
		$nc(port)->register$(this->fdVal, this);
	} catch ($ShutdownChannelGroupException& x) {
		$throwNew($IOException, static_cast<$Throwable*>(x));
	}
	$set(this, port, port);
}

$AsynchronousChannelGroupImpl* UnixAsynchronousSocketChannelImpl::group() {
	return this->port;
}

void UnixAsynchronousSocketChannelImpl::updateEvents() {
	if (!UnixAsynchronousSocketChannelImpl::$assertionsDisabled && !$Thread::holdsLock(this->updateLock)) {
		$throwNew($AssertionError);
	}
	int32_t events = 0;
	if (this->readPending) {
		$init($Net);
		events |= $Net::POLLIN;
	}
	if (this->connectPending || this->writePending) {
		$init($Net);
		events |= $Net::POLLOUT;
	}
	if (events != 0) {
		$nc(this->port)->startPoll(this->fdVal, events);
	}
}

void UnixAsynchronousSocketChannelImpl::lockAndUpdateEvents() {
	$synchronized(this->updateLock) {
		updateEvents();
	}
}

void UnixAsynchronousSocketChannelImpl::finish(bool mayInvokeDirect, bool readable, bool writable) {
	bool finishRead = false;
	bool finishWrite = false;
	bool finishConnect = false;
	$synchronized(this->updateLock) {
		if (readable && this->readPending) {
			this->readPending = false;
			finishRead = true;
		}
		if (writable) {
			if (this->writePending) {
				this->writePending = false;
				finishWrite = true;
			} else if (this->connectPending) {
				this->connectPending = false;
				finishConnect = true;
			}
		}
	}
	if (finishRead) {
		if (finishWrite) {
			this->finishWrite(false);
		}
		this->finishRead(mayInvokeDirect);
		return;
	}
	if (finishWrite) {
		this->finishWrite(mayInvokeDirect);
	}
	if (finishConnect) {
		this->finishConnect(mayInvokeDirect);
	}
}

void UnixAsynchronousSocketChannelImpl::onEvent(int32_t events, bool mayInvokeDirect) {
	$init($Net);
	bool readable = ((int32_t)(events & (uint32_t)(int32_t)$Net::POLLIN)) > 0;
	bool writable = ((int32_t)(events & (uint32_t)(int32_t)$Net::POLLOUT)) > 0;
	if (((int32_t)(events & (uint32_t)($Net::POLLERR | $Net::POLLHUP))) > 0) {
		readable = true;
		writable = true;
	}
	finish(mayInvokeDirect, readable, writable);
}

void UnixAsynchronousSocketChannelImpl::implClose() {
	$nc(this->port)->unregister(this->fdVal);
	$nc(UnixAsynchronousSocketChannelImpl::nd)->close(this->fd);
	finish(false, true, true);
}

void UnixAsynchronousSocketChannelImpl::onCancel($PendingFuture* task) {
	$init($UnixAsynchronousSocketChannelImpl$OpType);
	if ($equals($nc(task)->getContext(), $UnixAsynchronousSocketChannelImpl$OpType::CONNECT)) {
		killConnect();
	}
	if ($equals($nc(task)->getContext(), $UnixAsynchronousSocketChannelImpl$OpType::READ)) {
		killReading();
	}
	if ($equals($nc(task)->getContext(), $UnixAsynchronousSocketChannelImpl$OpType::WRITE)) {
		killWriting();
	}
}

void UnixAsynchronousSocketChannelImpl::setConnected() {
	$synchronized(this->stateLock) {
		this->state = $AsynchronousSocketChannelImpl::ST_CONNECTED;
		$set(this, localAddress, $Net::localAddress(this->fd));
		$set(this, remoteAddress, $cast($InetSocketAddress, this->pendingRemote));
	}
}

void UnixAsynchronousSocketChannelImpl::finishConnect(bool mayInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, e, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				begin();
				checkConnect(this->fdVal);
				setConnected();
			} catch ($Throwable& x) {
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				$assign(e, x);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (e != nullptr) {
		if ($instanceOf($IOException, e)) {
			$var($InetSocketAddress, isa, $cast($InetSocketAddress, this->pendingRemote));
			$assign(e, $SocketExceptions::of($cast($IOException, e), isa));
		}
		try {
			close();
		} catch ($Throwable& suppressed) {
			e->addSuppressed(suppressed);
		}
	}
	$var($CompletionHandler, handler, this->connectHandler);
	$set(this, connectHandler, nullptr);
	$var($Object, att, this->connectAttachment);
	$var($PendingFuture, future, this->connectFuture);
	if (handler == nullptr) {
		$nc(future)->setResult(nullptr, e);
	} else if (mayInvokeDirect) {
		$Invoker::invokeUnchecked(handler, att, nullptr, e);
	} else {
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, att, ($Object*)nullptr, e);
	}
}

$Future* UnixAsynchronousSocketChannelImpl::implConnect($SocketAddress* remote, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!isOpen()) {
		$var($Throwable, e, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(e);
		} else {
			$Invoker::invoke(this, handler, attachment, nullptr, e);
			return nullptr;
		}
	}
	$var($InetSocketAddress, isa, $Net::checkAddress(remote));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($String, var$0, $nc($($nc(isa)->getAddress()))->getHostAddress());
		sm->checkConnect(var$0, isa->getPort());
	}
	bool notifyBeforeTcpConnect = false;
	$synchronized(this->stateLock) {
		if (this->state == $AsynchronousSocketChannelImpl::ST_CONNECTED) {
			$throwNew($AlreadyConnectedException);
		}
		if (this->state == $AsynchronousSocketChannelImpl::ST_PENDING) {
			$throwNew($ConnectionPendingException);
		}
		this->state = $AsynchronousSocketChannelImpl::ST_PENDING;
		$set(this, pendingRemote, remote);
		notifyBeforeTcpConnect = (this->localAddress == nullptr);
	}
	$var($Throwable, e, nullptr);
	{
		$var($Throwable, var$1, nullptr);
		$var($Future, var$3, nullptr);
		bool return$2 = false;
		try {
			try {
				begin();
				if (notifyBeforeTcpConnect) {
					$var($FileDescriptor, var$4, this->fd);
					$var($InetAddress, var$5, $nc(isa)->getAddress());
					$NetHooks::beforeTcpConnect(var$4, var$5, isa->getPort());
				}
				$var($FileDescriptor, var$6, this->fd);
				$var($InetAddress, var$7, $nc(isa)->getAddress());
				int32_t n = $Net::connect(var$6, var$7, isa->getPort());
				if (n == $IOStatus::UNAVAILABLE) {
					$var($PendingFuture, result, nullptr);
					$synchronized(this->updateLock) {
						if (handler == nullptr) {
							$init($UnixAsynchronousSocketChannelImpl$OpType);
							$assign(result, $new($PendingFuture, this, $UnixAsynchronousSocketChannelImpl$OpType::CONNECT));
							$set(this, connectFuture, result);
						} else {
							$set(this, connectHandler, handler);
							$set(this, connectAttachment, attachment);
						}
						this->connectPending = true;
						updateEvents();
					}
					$assign(var$3, result);
					return$2 = true;
					goto $finally;
				}
				setConnected();
			} catch ($Throwable& x) {
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				$assign(e, x);
			}
		} catch ($Throwable& var$8) {
			$assign(var$1, var$8);
		} $finally: {
			end();
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return var$3;
		}
	}
	if (e != nullptr) {
		if ($instanceOf($IOException, e)) {
			$assign(e, $SocketExceptions::of($cast($IOException, e), isa));
		}
		try {
			close();
		} catch ($Throwable& suppressed) {
			e->addSuppressed(suppressed);
		}
	}
	if (handler == nullptr) {
		return $CompletedFuture::withResult(nullptr, e);
	} else {
		$Invoker::invoke(this, handler, attachment, nullptr, e);
		return nullptr;
	}
}

void UnixAsynchronousSocketChannelImpl::finishRead(bool mayInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	int32_t n = -1;
	$var($Throwable, exc, nullptr);
	bool scattering = this->isScatteringRead;
	$var($CompletionHandler, handler, this->readHandler);
	$var($Object, att, this->readAttachment);
	$var($PendingFuture, future, this->readFuture);
	$var($Future, timeout, this->readTimer);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				begin();
				if (scattering) {
					n = (int32_t)$IOUtil::read(this->fd, this->readBuffers, true, UnixAsynchronousSocketChannelImpl::nd);
				} else {
					n = $IOUtil::read(this->fd, this->readBuffer, (int64_t)-1, true, UnixAsynchronousSocketChannelImpl::nd);
				}
				if (n == $IOStatus::UNAVAILABLE) {
					$synchronized(this->updateLock) {
						this->readPending = true;
					}
					return$1 = true;
					goto $finally;
				}
				$set(this, readBuffer, nullptr);
				$set(this, readBuffers, nullptr);
				$set(this, readAttachment, nullptr);
				$set(this, readHandler, nullptr);
				$IOUtil::releaseScopes(this->readScopeHandleReleasers);
				enableReading();
			} catch ($Throwable& x) {
				enableReading();
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				if ($instanceOf($ConnectionResetException, x)) {
					$assign(x, $new($IOException, $(x->getMessage())));
				}
				$assign(exc, x);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if (!($instanceOf($AsynchronousCloseException, exc))) {
				lockAndUpdateEvents();
			}
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	if (timeout != nullptr) {
		timeout->cancel(false);
	}
	$var($Number, result, (exc != nullptr) ? ($Number*)nullptr : (scattering) ? static_cast<$Number*>($Long::valueOf((int64_t)n)) : static_cast<$Number*>($Integer::valueOf(n)));
	if (handler == nullptr) {
		$nc(future)->setResult(result, exc);
	} else if (mayInvokeDirect) {
		$Invoker::invokeUnchecked(handler, att, result, exc);
	} else {
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, att, $of(result), exc);
	}
}

$Future* UnixAsynchronousSocketChannelImpl::implRead(bool isScatteringRead, $ByteBuffer* dst, $ByteBufferArray* dsts, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	$var($Invoker$GroupAndInvokeCount, myGroupAndInvokeCount, nullptr);
	bool invokeDirect = false;
	bool attemptRead = false;
	if (!UnixAsynchronousSocketChannelImpl::disableSynchronousRead) {
		if (handler == nullptr) {
			attemptRead = true;
		} else {
			$assign(myGroupAndInvokeCount, $Invoker::getGroupAndInvokeCount());
			invokeDirect = $Invoker::mayInvokeDirect(myGroupAndInvokeCount, this->port);
			attemptRead = invokeDirect || !$nc(this->port)->isFixedThreadPool();
		}
	}
	int32_t n = $IOStatus::UNAVAILABLE;
	$var($Throwable, exc, nullptr);
	bool pending = false;
	{
		$var($Throwable, var$0, nullptr);
		$var($Future, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				begin();
				if (attemptRead) {
					if (isScatteringRead) {
						n = (int32_t)$IOUtil::read(this->fd, dsts, true, UnixAsynchronousSocketChannelImpl::nd);
					} else {
						n = $IOUtil::read(this->fd, dst, (int64_t)-1, true, UnixAsynchronousSocketChannelImpl::nd);
					}
				}
				if (n == $IOStatus::UNAVAILABLE) {
					$var($PendingFuture, result, nullptr);
					$synchronized(this->updateLock) {
						this->isScatteringRead = isScatteringRead;
						$set(this, readScopeHandleReleasers, $IOUtil::acquireScopes(dst, dsts));
						$set(this, readBuffer, dst);
						$set(this, readBuffers, dsts);
						if (handler == nullptr) {
							$set(this, readHandler, nullptr);
							$init($UnixAsynchronousSocketChannelImpl$OpType);
							$assign(result, $new($PendingFuture, this, $UnixAsynchronousSocketChannelImpl$OpType::READ));
							$set(this, readFuture, result);
							$set(this, readAttachment, nullptr);
						} else {
							$set(this, readHandler, handler);
							$set(this, readAttachment, attachment);
							$set(this, readFuture, nullptr);
						}
						if (timeout > (int64_t)0) {
							$set(this, readTimer, $nc(this->port)->schedule(this->readTimeoutTask, timeout, unit));
						}
						this->readPending = true;
						updateEvents();
					}
					pending = true;
					$assign(var$2, result);
					return$1 = true;
					goto $finally;
				}
			} catch ($Throwable& x) {
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				if ($instanceOf($ConnectionResetException, x)) {
					$assign(x, $new($IOException, $(x->getMessage())));
				}
				$assign(exc, x);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (!pending) {
				enableReading();
			}
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$var($Number, result, (exc != nullptr) ? ($Number*)nullptr : (isScatteringRead) ? static_cast<$Number*>($Long::valueOf((int64_t)n)) : static_cast<$Number*>($Integer::valueOf(n)));
	if (handler != nullptr) {
		if (invokeDirect) {
			$Invoker::invokeDirect(myGroupAndInvokeCount, handler, attachment, result, exc);
		} else {
			$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, attachment, result, exc);
		}
		return nullptr;
	} else {
		return $CompletedFuture::withResult(result, exc);
	}
}

void UnixAsynchronousSocketChannelImpl::finishWrite(bool mayInvokeDirect) {
	$useLocalCurrentObjectStackCache();
	int32_t n = -1;
	$var($Throwable, exc, nullptr);
	bool gathering = this->isGatheringWrite;
	$var($CompletionHandler, handler, this->writeHandler);
	$var($Object, att, this->writeAttachment);
	$var($PendingFuture, future, this->writeFuture);
	$var($Future, timer, this->writeTimer);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				begin();
				if (gathering) {
					n = (int32_t)$IOUtil::write(this->fd, this->writeBuffers, true, UnixAsynchronousSocketChannelImpl::nd);
				} else {
					n = $IOUtil::write(this->fd, this->writeBuffer, (int64_t)-1, true, UnixAsynchronousSocketChannelImpl::nd);
				}
				if (n == $IOStatus::UNAVAILABLE) {
					$synchronized(this->updateLock) {
						this->writePending = true;
					}
					return$1 = true;
					goto $finally;
				}
				$set(this, writeBuffer, nullptr);
				$set(this, writeBuffers, nullptr);
				$set(this, writeAttachment, nullptr);
				$set(this, writeHandler, nullptr);
				$IOUtil::releaseScopes(this->writeScopeHandleReleasers);
				enableWriting();
			} catch ($Throwable& x) {
				enableWriting();
				if ($instanceOf($ClosedChannelException, x)) {
					$assign(x, $new($AsynchronousCloseException));
				}
				$assign(exc, x);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if (!($instanceOf($AsynchronousCloseException, exc))) {
				lockAndUpdateEvents();
			}
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	if (timer != nullptr) {
		timer->cancel(false);
	}
	$var($Number, result, (exc != nullptr) ? ($Number*)nullptr : (gathering) ? static_cast<$Number*>($Long::valueOf((int64_t)n)) : static_cast<$Number*>($Integer::valueOf(n)));
	if (handler == nullptr) {
		$nc(future)->setResult(result, exc);
	} else if (mayInvokeDirect) {
		$Invoker::invokeUnchecked(handler, att, result, exc);
	} else {
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, att, $of(result), exc);
	}
}

$Future* UnixAsynchronousSocketChannelImpl::implWrite(bool isGatheringWrite, $ByteBuffer* src, $ByteBufferArray* srcs, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	$var($Invoker$GroupAndInvokeCount, myGroupAndInvokeCount, $Invoker::getGroupAndInvokeCount());
	bool invokeDirect = $Invoker::mayInvokeDirect(myGroupAndInvokeCount, this->port);
	bool attemptWrite = (handler == nullptr) || invokeDirect || !$nc(this->port)->isFixedThreadPool();
	int32_t n = $IOStatus::UNAVAILABLE;
	$var($Throwable, exc, nullptr);
	bool pending = false;
	{
		$var($Throwable, var$0, nullptr);
		$var($Future, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				begin();
				if (attemptWrite) {
					if (isGatheringWrite) {
						n = (int32_t)$IOUtil::write(this->fd, srcs, true, UnixAsynchronousSocketChannelImpl::nd);
					} else {
						n = $IOUtil::write(this->fd, src, (int64_t)-1, true, UnixAsynchronousSocketChannelImpl::nd);
					}
				}
				if (n == $IOStatus::UNAVAILABLE) {
					$var($PendingFuture, result, nullptr);
					$synchronized(this->updateLock) {
						this->isGatheringWrite = isGatheringWrite;
						$set(this, writeScopeHandleReleasers, $IOUtil::acquireScopes(src, srcs));
						$set(this, writeBuffer, src);
						$set(this, writeBuffers, srcs);
						if (handler == nullptr) {
							$set(this, writeHandler, nullptr);
							$init($UnixAsynchronousSocketChannelImpl$OpType);
							$assign(result, $new($PendingFuture, this, $UnixAsynchronousSocketChannelImpl$OpType::WRITE));
							$set(this, writeFuture, result);
							$set(this, writeAttachment, nullptr);
						} else {
							$set(this, writeHandler, handler);
							$set(this, writeAttachment, attachment);
							$set(this, writeFuture, nullptr);
						}
						if (timeout > (int64_t)0) {
							$set(this, writeTimer, $nc(this->port)->schedule(this->writeTimeoutTask, timeout, unit));
						}
						this->writePending = true;
						updateEvents();
					}
					pending = true;
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
			if (!pending) {
				enableWriting();
			}
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$var($Number, result, (exc != nullptr) ? ($Number*)nullptr : (isGatheringWrite) ? static_cast<$Number*>($Long::valueOf((int64_t)n)) : static_cast<$Number*>($Integer::valueOf(n)));
	if (handler != nullptr) {
		if (invokeDirect) {
			$Invoker::invokeDirect(myGroupAndInvokeCount, handler, attachment, result, exc);
		} else {
			$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, attachment, result, exc);
		}
		return nullptr;
	} else {
		return $CompletedFuture::withResult(result, exc);
	}
}

void UnixAsynchronousSocketChannelImpl::checkConnect(int32_t fdVal) {
	$init(UnixAsynchronousSocketChannelImpl);
	$prepareNativeStatic(UnixAsynchronousSocketChannelImpl, checkConnect, void, int32_t fdVal);
	$invokeNativeStatic(fdVal);
	$finishNativeStatic();
}

void clinit$UnixAsynchronousSocketChannelImpl($Class* class$) {
	UnixAsynchronousSocketChannelImpl::$assertionsDisabled = !UnixAsynchronousSocketChannelImpl::class$->desiredAssertionStatus();
	$assignStatic(UnixAsynchronousSocketChannelImpl::nd, $new($SocketDispatcher));
	{
		$var($String, propValue, $GetPropertyAction::privilegedGetProperty("sun.nio.ch.disableSynchronousRead"_s, "false"_s));
		UnixAsynchronousSocketChannelImpl::disableSynchronousRead = $nc(propValue)->isEmpty() ? true : $Boolean::parseBoolean(propValue);
	}
	{
		$IOUtil::load();
	}
}

UnixAsynchronousSocketChannelImpl::UnixAsynchronousSocketChannelImpl() {
}

$Class* UnixAsynchronousSocketChannelImpl::load$($String* name, bool initialize) {
	$loadClass(UnixAsynchronousSocketChannelImpl, name, initialize, &_UnixAsynchronousSocketChannelImpl_ClassInfo_, clinit$UnixAsynchronousSocketChannelImpl, allocate$UnixAsynchronousSocketChannelImpl);
	return class$;
}

$Class* UnixAsynchronousSocketChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun