#include <sun/nio/ch/WindowsAsynchronousServerSocketChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/InetSocketAddress.h>
#include <java/nio/channels/AcceptPendingException.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/NotYetBoundException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/AsynchronousServerSocketChannelImpl.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/Iocp$OverlappedChannel.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache.h>
#include <sun/nio/ch/WindowsAsynchronousServerSocketChannelImpl$AcceptTask.h>
#include <sun/nio/ch/WindowsAsynchronousSocketChannelImpl.h>
#include <jcpp.h>

#undef DATA_BUFFER_SIZE

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AcceptPendingException = ::java::nio::channels::AcceptPendingException;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $NotYetBoundException = ::java::nio::channels::NotYetBoundException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Future = ::java::util::concurrent::Future;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $AsynchronousServerSocketChannelImpl = ::sun::nio::ch::AsynchronousServerSocketChannelImpl;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Invoker = ::sun::nio::ch::Invoker;
using $Iocp = ::sun::nio::ch::Iocp;
using $Iocp$OverlappedChannel = ::sun::nio::ch::Iocp$OverlappedChannel;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache = ::sun::nio::ch::PendingIoCache;
using $WindowsAsynchronousServerSocketChannelImpl$AcceptTask = ::sun::nio::ch::WindowsAsynchronousServerSocketChannelImpl$AcceptTask;
using $WindowsAsynchronousSocketChannelImpl = ::sun::nio::ch::WindowsAsynchronousSocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WindowsAsynchronousServerSocketChannelImpl_FieldInfo_[] = {
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsAsynchronousServerSocketChannelImpl, unsafe)},
	{"DATA_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsAsynchronousServerSocketChannelImpl, DATA_BUFFER_SIZE)},
	{"handle", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl, handle)},
	{"completionKey", "I", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl, completionKey)},
	{"iocp", "Lsun/nio/ch/Iocp;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl, iocp)},
	{"ioCache", "Lsun/nio/ch/PendingIoCache;", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl, ioCache)},
	{"dataBuffer", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsAsynchronousServerSocketChannelImpl, dataBuffer)},
	{"accepting", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE, $field(WindowsAsynchronousServerSocketChannelImpl, accepting)},
	{}
};

$MethodInfo _WindowsAsynchronousServerSocketChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/Iocp;)V", nullptr, 0, $method(WindowsAsynchronousServerSocketChannelImpl, init$, void, $Iocp*), "java.io.IOException"},
	{"accept0", "(JJJJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousServerSocketChannelImpl, accept0, int32_t, int64_t, int64_t, int64_t, int64_t), "java.io.IOException"},
	{"closesocket0", "(J)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousServerSocketChannelImpl, closesocket0, void, int64_t), "java.io.IOException"},
	{"getByOverlapped", "(J)Lsun/nio/ch/PendingFuture;", "<V:Ljava/lang/Object;A:Ljava/lang/Object;>(J)Lsun/nio/ch/PendingFuture<TV;TA;>;", $PUBLIC, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl, getByOverlapped, $PendingFuture*, int64_t)},
	{"group", "()Lsun/nio/ch/AsynchronousChannelGroupImpl;", nullptr, $PUBLIC, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl, group, $AsynchronousChannelGroupImpl*)},
	{"implAccept", "(Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "(Ljava/lang/Object;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/AsynchronousSocketChannel;Ljava/lang/Object;>;)Ljava/util/concurrent/Future<Ljava/nio/channels/AsynchronousSocketChannel;>;", 0, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl, implAccept, $Future*, Object$*, $CompletionHandler*)},
	{"implClose", "()V", nullptr, 0, $virtualMethod(WindowsAsynchronousServerSocketChannelImpl, implClose, void), "java.io.IOException"},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousServerSocketChannelImpl, initIDs, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"updateAcceptContext", "(JJ)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(WindowsAsynchronousServerSocketChannelImpl, updateAcceptContext, void, int64_t, int64_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_accept0 6
#define _METHOD_INDEX_closesocket0 7
#define _METHOD_INDEX_initIDs 12
#define _METHOD_INDEX_updateAcceptContext 14

$InnerClassInfo _WindowsAsynchronousServerSocketChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.Iocp$OverlappedChannel", "sun.nio.ch.Iocp", "OverlappedChannel", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl$AcceptTask", "sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl", "AcceptTask", $PRIVATE},
	{}
};

$ClassInfo _WindowsAsynchronousServerSocketChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl",
	"sun.nio.ch.AsynchronousServerSocketChannelImpl",
	"sun.nio.ch.Iocp$OverlappedChannel",
	_WindowsAsynchronousServerSocketChannelImpl_FieldInfo_,
	_WindowsAsynchronousServerSocketChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsAsynchronousServerSocketChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl$AcceptTask,sun.nio.ch.WindowsAsynchronousServerSocketChannelImpl$AcceptTask$1"
};

$Object* allocate$WindowsAsynchronousServerSocketChannelImpl($Class* clazz) {
	return $of($alloc(WindowsAsynchronousServerSocketChannelImpl));
}

void WindowsAsynchronousServerSocketChannelImpl::close() {
	this->$AsynchronousServerSocketChannelImpl::close();
}

$String* WindowsAsynchronousServerSocketChannelImpl::toString() {
	 return this->$AsynchronousServerSocketChannelImpl::toString();
}

int32_t WindowsAsynchronousServerSocketChannelImpl::hashCode() {
	 return this->$AsynchronousServerSocketChannelImpl::hashCode();
}

bool WindowsAsynchronousServerSocketChannelImpl::equals(Object$* obj) {
	 return this->$AsynchronousServerSocketChannelImpl::equals(obj);
}

$Object* WindowsAsynchronousServerSocketChannelImpl::clone() {
	 return this->$AsynchronousServerSocketChannelImpl::clone();
}

void WindowsAsynchronousServerSocketChannelImpl::finalize() {
	this->$AsynchronousServerSocketChannelImpl::finalize();
}

$Unsafe* WindowsAsynchronousServerSocketChannelImpl::unsafe = nullptr;

void WindowsAsynchronousServerSocketChannelImpl::init$($Iocp* iocp) {
	$AsynchronousServerSocketChannelImpl::init$(iocp);
	$set(this, accepting, $new($AtomicBoolean));
	int64_t h = $IOUtil::fdVal(this->fd);
	int32_t key = 0;
	try {
		key = $nc(iocp)->associate(this, h);
	} catch ($IOException& x) {
		closesocket0(h);
		$throw(x);
	}
	this->handle = h;
	this->completionKey = key;
	$set(this, iocp, iocp);
	$set(this, ioCache, $new($PendingIoCache));
	this->dataBuffer = $nc(WindowsAsynchronousServerSocketChannelImpl::unsafe)->allocateMemory(WindowsAsynchronousServerSocketChannelImpl::DATA_BUFFER_SIZE);
}

$PendingFuture* WindowsAsynchronousServerSocketChannelImpl::getByOverlapped(int64_t overlapped) {
	return $nc(this->ioCache)->remove(overlapped);
}

void WindowsAsynchronousServerSocketChannelImpl::implClose() {
	closesocket0(this->handle);
	$nc(this->ioCache)->close();
	$nc(this->iocp)->disassociate(this->completionKey);
	$nc(WindowsAsynchronousServerSocketChannelImpl::unsafe)->freeMemory(this->dataBuffer);
}

$AsynchronousChannelGroupImpl* WindowsAsynchronousServerSocketChannelImpl::group() {
	return this->iocp;
}

$Future* WindowsAsynchronousServerSocketChannelImpl::implAccept(Object$* attachment, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!isOpen()) {
		$var($Throwable, exc, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(exc);
		}
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, attachment, ($Object*)nullptr, exc);
		return nullptr;
	}
	if (isAcceptKilled()) {
		$throwNew($RuntimeException, "Accept not allowed due to cancellation"_s);
	}
	if (this->localAddress == nullptr) {
		$throwNew($NotYetBoundException);
	}
	$var($WindowsAsynchronousSocketChannelImpl, ch, nullptr);
	$var($IOException, ioe, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				begin();
				$assign(ch, $new($WindowsAsynchronousSocketChannelImpl, this->iocp, false));
			} catch ($IOException& x) {
				$assign(ioe, x);
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
	if (ioe != nullptr) {
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(ioe);
		}
		$Invoker::invokeIndirectly(static_cast<$AsynchronousChannel*>(this), handler, attachment, ($Object*)nullptr, static_cast<$Throwable*>(ioe));
		return nullptr;
	}
	$var($AccessControlContext, acc, ($System::getSecurityManager() == nullptr) ? ($AccessControlContext*)nullptr : $AccessController::getContext());
	$var($PendingFuture, result, $new($PendingFuture, this, handler, attachment));
	$var($WindowsAsynchronousServerSocketChannelImpl$AcceptTask, task, $new($WindowsAsynchronousServerSocketChannelImpl$AcceptTask, this, ch, acc, result));
	result->setContext(task);
	if (!$nc(this->accepting)->compareAndSet(false, true)) {
		$throwNew($AcceptPendingException);
	}
	task->run();
	return result;
}

void WindowsAsynchronousServerSocketChannelImpl::initIDs() {
	$init(WindowsAsynchronousServerSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousServerSocketChannelImpl, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

int32_t WindowsAsynchronousServerSocketChannelImpl::accept0(int64_t listenSocket, int64_t acceptSocket, int64_t overlapped, int64_t dataBuffer) {
	$init(WindowsAsynchronousServerSocketChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(WindowsAsynchronousServerSocketChannelImpl, accept0, int32_t, int64_t listenSocket, int64_t acceptSocket, int64_t overlapped, int64_t dataBuffer);
	$ret = $invokeNativeStatic(listenSocket, acceptSocket, overlapped, dataBuffer);
	$finishNativeStatic();
	return $ret;
}

void WindowsAsynchronousServerSocketChannelImpl::updateAcceptContext(int64_t listenSocket, int64_t acceptSocket) {
	$init(WindowsAsynchronousServerSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousServerSocketChannelImpl, updateAcceptContext, void, int64_t listenSocket, int64_t acceptSocket);
	$invokeNativeStatic(listenSocket, acceptSocket);
	$finishNativeStatic();
}

void WindowsAsynchronousServerSocketChannelImpl::closesocket0(int64_t socket) {
	$init(WindowsAsynchronousServerSocketChannelImpl);
	$prepareNativeStatic(WindowsAsynchronousServerSocketChannelImpl, closesocket0, void, int64_t socket);
	$invokeNativeStatic(socket);
	$finishNativeStatic();
}

void clinit$WindowsAsynchronousServerSocketChannelImpl($Class* class$) {
	$assignStatic(WindowsAsynchronousServerSocketChannelImpl::unsafe, $Unsafe::getUnsafe());
	{
		$IOUtil::load();
		WindowsAsynchronousServerSocketChannelImpl::initIDs();
	}
}

WindowsAsynchronousServerSocketChannelImpl::WindowsAsynchronousServerSocketChannelImpl() {
}

$Class* WindowsAsynchronousServerSocketChannelImpl::load$($String* name, bool initialize) {
	$loadClass(WindowsAsynchronousServerSocketChannelImpl, name, initialize, &_WindowsAsynchronousServerSocketChannelImpl_ClassInfo_, clinit$WindowsAsynchronousServerSocketChannelImpl, allocate$WindowsAsynchronousServerSocketChannelImpl);
	return class$;
}

$Class* WindowsAsynchronousServerSocketChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun