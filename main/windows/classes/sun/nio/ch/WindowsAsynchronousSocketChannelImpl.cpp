#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityManager.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AlreadyConnectedException.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/ConnectionPendingException.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/nio/channels/ShutdownChannelGroupException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/TimeUnit.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/AsynchronousSocketChannelImpl.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/Iocp$OverlappedChannel.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$1.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$2.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$3.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$ConnectTask.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$ReadTask.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl$WriteTask.h>
#include <jcpp.h>

#undef MAX_WSABUF
#undef OFFSETOF_BUF
#undef OFFSETOF_LEN
#undef SIZEOF_WSABUF
#undef SIZEOF_WSABUFARRAY
#undef ST_CONNECTED
#undef ST_PENDING

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SecurityManager = ::java::lang::SecurityManager;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlreadyConnectedException = ::java::nio::channels::AlreadyConnectedException;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $ConnectionPendingException = ::java::nio::channels::ConnectionPendingException;
using $ShutdownChannelGroupException = ::java::nio::channels::ShutdownChannelGroupException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Future = ::java::util::concurrent::Future;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $AsynchronousSocketChannelImpl = ::sun::nio::ch::AsynchronousSocketChannelImpl;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $Iocp = ::sun::nio::ch::Iocp;
using $Iocp$OverlappedChannel = ::sun::nio::ch::Iocp$OverlappedChannel;
using $Net = ::sun::nio::ch::Net;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $WindowsAsynchronousSocketChannelImpl$1 = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl$1;
using $WindowsAsynchronousSocketChannelImpl$2 = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl$2;
using $WindowsAsynchronousSocketChannelImpl$3 = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl$3;
using $WindowsAsynchronousSocketChannelImpl$ConnectTask = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl$ConnectTask;
using $WindowsAsynchronousSocketChannelImpl$ReadTask = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl$ReadTask;
using $WindowsAsynchronousSocketChannelImpl$WriteTask = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl$WriteTask;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousSocketChannelImpl_FieldInfo_[] = {
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousSocketChannelImpl, unsafe)},
	{"addressSize", "I", nullptr, $PRIVATE | $STATIC, $staticField(WindowsAsynchronousSocketChannelImpl, addressSize)},
	{"SIZEOF_WSABUF", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousSocketChannelImpl, SIZEOF_WSABUF)},
	{"OFFSETOF_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsAsynchronousSocketChannelImpl, OFFSETOF_LEN)},
	{"OFFSETOF_BUF", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousSocketChannelImpl, OFFSETOF_BUF)},
	{"MAX_WSABUF", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsAsynchronousSocketChannelImpl, MAX_WSABUF)},
	{"SIZEOF_WSABUFARRAY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousSocketChannelImpl, SIZEOF_WSABUFARRAY)},
	{"handle", "J", nullptr, $FINAL, $field(WindowsAsynchronousSocketChannelImpl, handle$)},
	{"iocp", "Lsun/nio/ch/Iocp;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl, iocp)},
	{"completionKey", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl, completionKey)},
	{"ioCache", "Lsun/nio/ch/PendingIoCache;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl, ioCache)},
	{"readBufferArray", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl, readBufferArray)},
	{"writeBufferArray", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousSocketChannelImpl, writeBufferArray)},
	{}
};

$MethodInfo _WindowsAsynchronousSocketChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/Iocp;Z)V", nullptr, 0, $method(WindowsAsynchronousSocketChannelImpl, init$, void, $Iocp*, bool), "java.io.IOException"},
	{"<init>", "(Lsun/nio/ch/Iocp;)V", nullptr, 0, $method(WindowsAsynchronousSocketChannelImpl, init$, void, $Iocp*), "java.io.IOException"},
	{"closesocket0", "(J)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, closesocket0, void, int64_t), "java.io.IOException"},
	{"connect0", "(JZLjava/net/InetAddress;IJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, connect0, int32_t, int64_t, bool, $InetAddress*, int32_t, int64_t), "java.io.IOException"},
	{"dependsArch", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsAsynchronousSocketChannelImpl, dependsArch, int32_t, int32_t, int32_t)},
	{"doPrivilegedBind", "(Ljava/net/SocketAddress;)V", nullptr, $PRIVATE, $method(WindowsAsynchronousSocketChannelImpl, doPrivilegedBind, void, $SocketAddress*), "java.io.IOException"},
	{"getByOverlapped", "(J)Lsun/nio/ch/PendingFuture;", "<V:Ljava/lang/Object;A:Ljava/lang/Object;>(J)Lsun/nio/ch/PendingFuture<TV;TA;>;", $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl, getByOverlapped, $PendingFuture*, int64_t)},
	{"group", "()Lsun/nio/ch/AsynchronousChannelGroupImpl;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl, group, $AsynchronousChannelGroupImpl*)},
	{"handle", "()J", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl, handle, int64_t)},
	{"implClose", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl, implClose, void), "java.io.IOException"},
	{"implConnect", "(Ljava/net/SocketAddress;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/net/SocketAddress;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Void;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Void;>;", 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl, implConnect, $Future*, $SocketAddress*, Object$*, $CompletionHandler*)},
	{"implRead", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl, implRead, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"implWrite", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl, implWrite, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, initIDs, void)},
	{"onCancel", "(Lsun/nio/ch/PendingFuture;)V", "(Lsun/nio/ch/PendingFuture<**>;)V", $PUBLIC, $virtualMethod(WindowsAsynchronousSocketChannelImpl, onCancel, void, $PendingFuture*)},
	{"read0", "(JIJJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, read0, int32_t, int64_t, int32_t, int64_t, int64_t), "java.io.IOException"},
	{"setConnected", "(Ljava/net/InetSocketAddress;Ljava/net/InetSocketAddress;)V", nullptr, 0, $virtualMethod(WindowsAsynchronousSocketChannelImpl, setConnected, void, $InetSocketAddress*, $InetSocketAddress*)},
	{"shutdown0", "(JI)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, shutdown0, void, int64_t, int32_t), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"updateConnectContext", "(J)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, updateConnectContext, void, int64_t), "java.io.IOException"},
	{"write0", "(JIJJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousSocketChannelImpl, write0, int32_t, int64_t, int32_t, int64_t, int64_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_closesocket0 7
#define _METHOD_INDEX_connect0 8
#define _METHOD_INDEX_initIDs 18
#define _METHOD_INDEX_read0 20
#define _METHOD_INDEX_shutdown0 22
#define _METHOD_INDEX_updateConnectContext 24
#define _METHOD_INDEX_write0 25

$InnerClassInfo _WindowsAsynchronousSocketChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.Iocp$OverlappedChannel", "sun.nio.ch.Iocp", "OverlappedChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$WriteTask", "sun.nio.ch.WindowsAsynchronousSocketChannelImpl", "WriteTask", $PRIVATE},
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ReadTask", "sun.nio.ch.WindowsAsynchronousSocketChannelImpl", "ReadTask", $PRIVATE},
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ConnectTask", "sun.nio.ch.WindowsAsynchronousSocketChannelImpl", "ConnectTask", $PRIVATE},
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$3", nullptr, nullptr, 0},
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$2", nullptr, nullptr, 0},
	{"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WindowsAsynchronousSocketChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl",
	"sun.nio.ch.AsynchronousSocketChannelImpl",
	"sun.nio.ch.Iocp$OverlappedChannel",
	_WindowsAsynchronousSocketChannelImpl_FieldInfo_,
	_WindowsAsynchronousSocketChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsAsynchronousSocketChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousSocketChannelImpl$WriteTask,sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ReadTask,sun.nio.ch.WindowsAsynchronousSocketChannelImpl$ConnectTask,sun.nio.ch.WindowsAsynchronousSocketChannelImpl$3,sun.nio.ch.WindowsAsynchronousSocketChannelImpl$2,sun.nio.ch.WindowsAsynchronousSocketChannelImpl$1"
};

$Object* allocate$WindowsAsynchronousSocketChannelImpl($Class* clazz) {
	return $of($alloc(WindowsAsynchronousSocketChannelImpl));
}

void WindowsAsynchronousSocketChannelImpl::close() {
	this->$AsynchronousSocketChannelImpl::close();
}

$String* WindowsAsynchronousSocketChannelImpl::toString() {
	 return this->$AsynchronousSocketChannelImpl::toString();
}

int32_t WindowsAsynchronousSocketChannelImpl::hashCode() {
	 return this->$AsynchronousSocketChannelImpl::hashCode();
}

bool WindowsAsynchronousSocketChannelImpl::equals(Object$* obj) {
	 return this->$AsynchronousSocketChannelImpl::equals(obj);
}

$Object* WindowsAsynchronousSocketChannelImpl::clone() {
	 return this->$AsynchronousSocketChannelImpl::clone();
}

void WindowsAsynchronousSocketChannelImpl::finalize() {
	this->$AsynchronousSocketChannelImpl::finalize();
}

$Unsafe* WindowsAsynchronousSocketChannelImpl::unsafe = nullptr;
int32_t WindowsAsynchronousSocketChannelImpl::addressSize = 0;
int32_t WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUF = 0;
int32_t WindowsAsynchronousSocketChannelImpl::OFFSETOF_BUF = 0;
int32_t WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUFARRAY = 0;

int32_t WindowsAsynchronousSocketChannelImpl::dependsArch(int32_t value32, int32_t value64) {
	$init(WindowsAsynchronousSocketChannelImpl);
	return (WindowsAsynchronousSocketChannelImpl::addressSize == 4) ? value32 : value64;
}

void WindowsAsynchronousSocketChannelImpl::init$($Iocp* iocp, bool failIfGroupShutdown) {
	$AsynchronousSocketChannelImpl::init$(iocp);
	int64_t h = $IOUtil::fdVal(this->fd);
	int32_t key = 0;
	try {
		key = $nc(iocp)->associate(this, h);
	} catch ($ShutdownChannelGroupException& x) {
		if (failIfGroupShutdown) {
			closesocket0(h);
			$throw(x);
		}
	} catch ($IOException& x) {
		closesocket0(h);
		$throw(x);
	}
	this->handle$ = h;
	$set(this, iocp, iocp);
	this->completionKey = key;
	$set(this, ioCache, $new($PendingIoCache));
	this->readBufferArray = $nc(WindowsAsynchronousSocketChannelImpl::unsafe)->allocateMemory(WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUFARRAY);
	this->writeBufferArray = $nc(WindowsAsynchronousSocketChannelImpl::unsafe)->allocateMemory(WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUFARRAY);
}

void WindowsAsynchronousSocketChannelImpl::init$($Iocp* iocp) {
	WindowsAsynchronousSocketChannelImpl::init$(iocp, true);
}

$AsynchronousChannelGroupImpl* WindowsAsynchronousSocketChannelImpl::group() {
	return this->iocp;
}

$PendingFuture* WindowsAsynchronousSocketChannelImpl::getByOverlapped(int64_t overlapped) {
	return $nc(this->ioCache)->remove(overlapped);
}

int64_t WindowsAsynchronousSocketChannelImpl::handle() {
	return this->handle$;
}

void WindowsAsynchronousSocketChannelImpl::setConnected($InetSocketAddress* localAddress, $InetSocketAddress* remoteAddress) {
	$synchronized(this->stateLock) {
		this->state = $AsynchronousSocketChannelImpl::ST_CONNECTED;
		$set(this, localAddress, localAddress);
		$set(this, remoteAddress, remoteAddress);
	}
}

void WindowsAsynchronousSocketChannelImpl::implClose() {
	closesocket0(this->handle$);
	$nc(this->ioCache)->close();
	$nc(WindowsAsynchronousSocketChannelImpl::unsafe)->freeMemory(this->readBufferArray);
	$nc(WindowsAsynchronousSocketChannelImpl::unsafe)->freeMemory(this->writeBufferArray);
	if (this->completionKey != 0) {
		$nc(this->iocp)->disassociate(this->completionKey);
	}
}

void WindowsAsynchronousSocketChannelImpl::onCancel($PendingFuture* task) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($WindowsAsynchronousSocketChannelImpl$ConnectTask, $($nc(task)->getContext()))) {
		killConnect();
	}
	if ($instanceOf($WindowsAsynchronousSocketChannelImpl$ReadTask, $($nc(task)->getContext()))) {
		killReading();
	}
	if ($instanceOf($WindowsAsynchronousSocketChannelImpl$WriteTask, $($nc(task)->getContext()))) {
		killWriting();
	}
}

void WindowsAsynchronousSocketChannelImpl::doPrivilegedBind($SocketAddress* sa) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($WindowsAsynchronousSocketChannelImpl$1, this, sa)));
	} catch ($PrivilegedActionException& e) {
		$throw($cast($IOException, $(e->getException())));
	}
}

$Future* WindowsAsynchronousSocketChannelImpl::implConnect($SocketAddress* remote, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!isOpen()) {
		$var($Throwable, exc, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(exc);
		}
		$Invoker::invoke(this, handler, attachment, nullptr, exc);
		return nullptr;
	}
	$var($InetSocketAddress, isa, $Net::checkAddress(remote));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($String, var$0, $nc($($nc(isa)->getAddress()))->getHostAddress());
		sm->checkConnect(var$0, isa->getPort());
	}
	$var($IOException, bindException, nullptr);
	$synchronized(this->stateLock) {
		if (this->state == $AsynchronousSocketChannelImpl::ST_CONNECTED) {
			$throwNew($AlreadyConnectedException);
		}
		if (this->state == $AsynchronousSocketChannelImpl::ST_PENDING) {
			$throwNew($ConnectionPendingException);
		}
		if (this->localAddress == nullptr) {
			try {
				$var($SocketAddress, any, $new($InetSocketAddress, 0));
				if (sm == nullptr) {
					bind(any);
				} else {
					doPrivilegedBind(any);
				}
			} catch ($IOException& x) {
				$assign(bindException, x);
			}
		}
		if (bindException == nullptr) {
			this->state = $AsynchronousSocketChannelImpl::ST_PENDING;
		}
	}
	if (bindException != nullptr) {
		try {
			close();
		} catch ($IOException& ignore) {
		}
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(bindException);
		}
		$Invoker::invoke(this, handler, attachment, nullptr, bindException);
		return nullptr;
	}
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($WindowsAsynchronousSocketChannelImpl$ConnectTask, task, $new($WindowsAsynchronousSocketChannelImpl$ConnectTask, this, isa, result));
	result->setContext(task);
	task->run();
	return result;
}

$Future* WindowsAsynchronousSocketChannelImpl::implRead(bool isScatteringRead, $ByteBuffer* dst, $ByteBufferArray* dsts, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($ByteBufferArray, bufs, nullptr);
	if (isScatteringRead) {
		$assign(bufs, dsts);
	} else {
		$assign(bufs, $new($ByteBufferArray, 1));
		bufs->set(0, dst);
	}
	$var($WindowsAsynchronousSocketChannelImpl$ReadTask, readTask, $new($WindowsAsynchronousSocketChannelImpl$ReadTask, this, bufs, isScatteringRead, result));
	result->setContext(readTask);
	if (timeout > (int64_t)0) {
		$var($Future, timeoutTask, $nc(this->iocp)->schedule($$new($WindowsAsynchronousSocketChannelImpl$2, this, readTask), timeout, unit));
		result->setTimeoutTask(timeoutTask);
	}
	readTask->run();
	return result;
}

$Future* WindowsAsynchronousSocketChannelImpl::implWrite(bool gatheringWrite, $ByteBuffer* src, $ByteBufferArray* srcs, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($ByteBufferArray, bufs, nullptr);
	if (gatheringWrite) {
		$assign(bufs, srcs);
	} else {
		$assign(bufs, $new($ByteBufferArray, 1));
		bufs->set(0, src);
	}
	$var($WindowsAsynchronousSocketChannelImpl$WriteTask, writeTask, $new($WindowsAsynchronousSocketChannelImpl$WriteTask, this, bufs, gatheringWrite, result));
	result->setContext(writeTask);
	if (timeout > (int64_t)0) {
		$var($Future, timeoutTask, $nc(this->iocp)->schedule($$new($WindowsAsynchronousSocketChannelImpl$3, this, writeTask), timeout, unit));
		result->setTimeoutTask(timeoutTask);
	}
	writeTask->run();
	return result;
}

void WindowsAsynchronousSocketChannelImpl::initIDs() {
	$init(WindowsAsynchronousSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

int32_t WindowsAsynchronousSocketChannelImpl::connect0(int64_t socket, bool preferIPv6, $InetAddress* remote, int32_t remotePort, int64_t overlapped) {
	$init(WindowsAsynchronousSocketChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, connect0, int32_t, int64_t socket, bool preferIPv6, $InetAddress* remote, int32_t remotePort, int64_t overlapped);
	$ret = $invokeNativeStatic(socket, preferIPv6, remote, remotePort, overlapped);
	$finishNativeStatic();
	return $ret;
}

void WindowsAsynchronousSocketChannelImpl::updateConnectContext(int64_t socket) {
	$init(WindowsAsynchronousSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, updateConnectContext, void, int64_t socket);
	$invokeNativeStatic(socket);
	$finishNativeStatic();
}

int32_t WindowsAsynchronousSocketChannelImpl::read0(int64_t socket, int32_t count, int64_t addres, int64_t overlapped) {
	$init(WindowsAsynchronousSocketChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, read0, int32_t, int64_t socket, int32_t count, int64_t addres, int64_t overlapped);
	$ret = $invokeNativeStatic(socket, count, addres, overlapped);
	$finishNativeStatic();
	return $ret;
}

int32_t WindowsAsynchronousSocketChannelImpl::write0(int64_t socket, int32_t count, int64_t address, int64_t overlapped) {
	$init(WindowsAsynchronousSocketChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, write0, int32_t, int64_t socket, int32_t count, int64_t address, int64_t overlapped);
	$ret = $invokeNativeStatic(socket, count, address, overlapped);
	$finishNativeStatic();
	return $ret;
}

void WindowsAsynchronousSocketChannelImpl::shutdown0(int64_t socket, int32_t how) {
	$init(WindowsAsynchronousSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, shutdown0, void, int64_t socket, int32_t how);
	$invokeNativeStatic(socket, how);
	$finishNativeStatic();
}

void WindowsAsynchronousSocketChannelImpl::closesocket0(int64_t socket) {
	$init(WindowsAsynchronousSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousSocketChannelImpl, closesocket0, void, int64_t socket);
	$invokeNativeStatic(socket);
	$finishNativeStatic();
}

void clinit$WindowsAsynchronousSocketChannelImpl($Class* class$) {
	$assignStatic(WindowsAsynchronousSocketChannelImpl::unsafe, $Unsafe::getUnsafe());
	WindowsAsynchronousSocketChannelImpl::addressSize = $nc(WindowsAsynchronousSocketChannelImpl::unsafe)->addressSize();
	WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUF = WindowsAsynchronousSocketChannelImpl::dependsArch(8, 16);
	WindowsAsynchronousSocketChannelImpl::OFFSETOF_BUF = WindowsAsynchronousSocketChannelImpl::dependsArch(4, 8);
	WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUFARRAY = WindowsAsynchronousSocketChannelImpl::MAX_WSABUF * WindowsAsynchronousSocketChannelImpl::SIZEOF_WSABUF;
	{
		$IOUtil::load();
		WindowsAsynchronousSocketChannelImpl::initIDs();
	}
}

WindowsAsynchronousSocketChannelImpl::WindowsAsynchronousSocketChannelImpl() {
}

$Class* WindowsAsynchronousSocketChannelImpl::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousSocketChannelImpl, name, initialize, &_WindowsAsynchronousSocketChannelImpl_ClassInfo_, clinit$WindowsAsynchronousSocketChannelImpl, allocate$WindowsAsynchronousSocketChannelImpl);
	return class$;
}

$Class* WindowsAsynchronousSocketChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun