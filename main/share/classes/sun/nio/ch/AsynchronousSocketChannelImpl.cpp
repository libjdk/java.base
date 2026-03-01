#include <sun/nio/ch/AsynchronousSocketChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Number.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ProtocolFamily.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AlreadyBoundException.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/nio/channels/AsynchronousSocketChannel.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/ConnectionPendingException.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/nio/channels/NotYetConnectedException.h>
#include <java/nio/channels/ReadPendingException.h>
#include <java/nio/channels/WritePendingException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/util/Set.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReadWriteLock.h>
#include <java/util/concurrent/locks/ReentrantReadWriteLock.h>
#include <sun/net/NetHooks.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/AsynchronousSocketChannelImpl$DefaultOptionsHolder.h>
#include <sun/nio/ch/CompletedFuture.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/Util.h>
#include <jcpp.h>

#undef MILLISECONDS
#undef SHUT_RD
#undef SHUT_WR
#undef SO_REUSEADDR
#undef ST_CONNECTED
#undef ST_PENDING
#undef ST_UNCONNECTED
#undef ST_UNINITIALIZED
#undef UNSPEC

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketOption = ::java::net::SocketOption;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlreadyBoundException = ::java::nio::channels::AlreadyBoundException;
using $AsynchronousChannel = ::java::nio::channels::AsynchronousChannel;
using $AsynchronousSocketChannel = ::java::nio::channels::AsynchronousSocketChannel;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $ConnectionPendingException = ::java::nio::channels::ConnectionPendingException;
using $NetworkChannel = ::java::nio::channels::NetworkChannel;
using $NotYetConnectedException = ::java::nio::channels::NotYetConnectedException;
using $ReadPendingException = ::java::nio::channels::ReadPendingException;
using $WritePendingException = ::java::nio::channels::WritePendingException;
using $Set = ::java::util::Set;
using $Future = ::java::util::concurrent::Future;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReadWriteLock = ::java::util::concurrent::locks::ReadWriteLock;
using $ReentrantReadWriteLock = ::java::util::concurrent::locks::ReentrantReadWriteLock;
using $NetHooks = ::sun::net::NetHooks;
using $AsynchronousChannelGroupImpl = ::sun::nio::ch::AsynchronousChannelGroupImpl;
using $AsynchronousSocketChannelImpl$DefaultOptionsHolder = ::sun::nio::ch::AsynchronousSocketChannelImpl$DefaultOptionsHolder;
using $CompletedFuture = ::sun::nio::ch::CompletedFuture;
using $Invoker = ::sun::nio::ch::Invoker;
using $Net = ::sun::nio::ch::Net;
using $Util = ::sun::nio::ch::Util;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _AsynchronousSocketChannelImpl_FieldInfo_[] = {
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PROTECTED | $FINAL, $field(AsynchronousSocketChannelImpl, fd)},
	{"stateLock", "Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL, $field(AsynchronousSocketChannelImpl, stateLock)},
	{"localAddress", "Ljava/net/InetSocketAddress;", nullptr, $PROTECTED | $VOLATILE, $field(AsynchronousSocketChannelImpl, localAddress)},
	{"remoteAddress", "Ljava/net/InetSocketAddress;", nullptr, $PROTECTED | $VOLATILE, $field(AsynchronousSocketChannelImpl, remoteAddress)},
	{"ST_UNINITIALIZED", "I", nullptr, $STATIC | $FINAL, $constField(AsynchronousSocketChannelImpl, ST_UNINITIALIZED)},
	{"ST_UNCONNECTED", "I", nullptr, $STATIC | $FINAL, $constField(AsynchronousSocketChannelImpl, ST_UNCONNECTED)},
	{"ST_PENDING", "I", nullptr, $STATIC | $FINAL, $constField(AsynchronousSocketChannelImpl, ST_PENDING)},
	{"ST_CONNECTED", "I", nullptr, $STATIC | $FINAL, $constField(AsynchronousSocketChannelImpl, ST_CONNECTED)},
	{"state", "I", nullptr, $PROTECTED | $VOLATILE, $field(AsynchronousSocketChannelImpl, state)},
	{"readLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousSocketChannelImpl, readLock)},
	{"reading", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, reading)},
	{"readShutdown", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, readShutdown)},
	{"readKilled", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, readKilled)},
	{"writeLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousSocketChannelImpl, writeLock)},
	{"writing", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, writing)},
	{"writeShutdown", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, writeShutdown)},
	{"writeKilled", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, writeKilled)},
	{"closeLock", "Ljava/util/concurrent/locks/ReadWriteLock;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousSocketChannelImpl, closeLock)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(AsynchronousSocketChannelImpl, closed)},
	{"isReuseAddress", "Z", nullptr, $PRIVATE, $field(AsynchronousSocketChannelImpl, isReuseAddress)},
	{}
};

$MethodInfo _AsynchronousSocketChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/ch/AsynchronousChannelGroupImpl;)V", nullptr, 0, $method(AsynchronousSocketChannelImpl, init$, void, $AsynchronousChannelGroupImpl*), "java.io.IOException"},
	{"<init>", "(Lsun/nio/ch/AsynchronousChannelGroupImpl;Ljava/io/FileDescriptor;Ljava/net/InetSocketAddress;)V", nullptr, 0, $method(AsynchronousSocketChannelImpl, init$, void, $AsynchronousChannelGroupImpl*, $FileDescriptor*, $InetSocketAddress*), "java.io.IOException"},
	{"begin", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, begin, void), "java.io.IOException"},
	{"bind", "(Ljava/net/SocketAddress;)Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, bind, $NetworkChannel*, $SocketAddress*), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, close, void), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;)Ljava/util/concurrent/Future;", "(Ljava/net/SocketAddress;)Ljava/util/concurrent/Future<Ljava/lang/Void;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, connect, $Future*, $SocketAddress*)},
	{"connect", "(Ljava/net/SocketAddress;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/net/SocketAddress;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Void;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, connect, void, $SocketAddress*, Object$*, $CompletionHandler*)},
	{"enableReading", "(Z)V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, enableReading, void, bool)},
	{"enableReading", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, enableReading, void)},
	{"enableWriting", "(Z)V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, enableWriting, void, bool)},
	{"enableWriting", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, enableWriting, void)},
	{"end", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, end, void)},
	{"getLocalAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, getLocalAddress, $SocketAddress*), "java.io.IOException"},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getRemoteAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, getRemoteAddress, $SocketAddress*), "java.io.IOException"},
	{"implClose", "()V", nullptr, $ABSTRACT, $virtualMethod(AsynchronousSocketChannelImpl, implClose, void), "java.io.IOException"},
	{"implConnect", "(Ljava/net/SocketAddress;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<A:Ljava/lang/Object;>(Ljava/net/SocketAddress;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Void;-TA;>;)Ljava/util/concurrent/Future<Ljava/lang/Void;>;", $ABSTRACT, $virtualMethod(AsynchronousSocketChannelImpl, implConnect, $Future*, $SocketAddress*, Object$*, $CompletionHandler*)},
	{"implRead", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", $ABSTRACT, $virtualMethod(AsynchronousSocketChannelImpl, implRead, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"implWrite", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", $ABSTRACT, $virtualMethod(AsynchronousSocketChannelImpl, implWrite, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"isOpen", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, isOpen, bool)},
	{"killConnect", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, killConnect, void)},
	{"killReading", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, killReading, void)},
	{"killWriting", "()V", nullptr, $FINAL, $method(AsynchronousSocketChannelImpl, killWriting, void)},
	{"read", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", $PRIVATE, $method(AsynchronousSocketChannelImpl, read, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"read", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/Future;", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, read, $Future*, $ByteBuffer*)},
	{"read", "(Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, read, void, $ByteBuffer*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"read", "([Ljava/nio/ByteBuffer;IIJLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>([Ljava/nio/ByteBuffer;IIJLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Long;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, read, void, $ByteBufferArray*, int32_t, int32_t, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)Ljava/nio/channels/AsynchronousSocketChannel;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)Ljava/nio/channels/AsynchronousSocketChannel;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, setOption, $NetworkChannel*, $SocketOption*, Object$*), "java.io.IOException"},
	{"shutdownInput", "()Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, shutdownInput, $AsynchronousSocketChannel*), "java.io.IOException"},
	{"shutdownOutput", "()Ljava/nio/channels/AsynchronousSocketChannel;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, shutdownOutput, $AsynchronousSocketChannel*), "java.io.IOException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, supportedOptions, $Set*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, toString, $String*)},
	{"write", "(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)Ljava/util/concurrent/Future;", "<V:Ljava/lang/Number;A:Ljava/lang/Object;>(ZLjava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<TV;-TA;>;)Ljava/util/concurrent/Future<TV;>;", $PRIVATE, $method(AsynchronousSocketChannelImpl, write, $Future*, bool, $ByteBuffer*, $ByteBufferArray*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"write", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/Future;", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, write, $Future*, $ByteBuffer*)},
	{"write", "(Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, write, void, $ByteBuffer*, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{"write", "([Ljava/nio/ByteBuffer;IIJLjava/util/concurrent/TimeUnit;Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>([Ljava/nio/ByteBuffer;IIJLjava/util/concurrent/TimeUnit;TA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Long;-TA;>;)V", $PUBLIC | $FINAL, $virtualMethod(AsynchronousSocketChannelImpl, write, void, $ByteBufferArray*, int32_t, int32_t, int64_t, $TimeUnit*, Object$*, $CompletionHandler*)},
	{}
};

$InnerClassInfo _AsynchronousSocketChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.AsynchronousSocketChannelImpl$DefaultOptionsHolder", "sun.nio.ch.AsynchronousSocketChannelImpl", "DefaultOptionsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AsynchronousSocketChannelImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.ch.AsynchronousSocketChannelImpl",
	"java.nio.channels.AsynchronousSocketChannel",
	"sun.nio.ch.Cancellable,sun.nio.ch.Groupable",
	_AsynchronousSocketChannelImpl_FieldInfo_,
	_AsynchronousSocketChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_AsynchronousSocketChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.AsynchronousSocketChannelImpl$DefaultOptionsHolder"
};

$Object* allocate$AsynchronousSocketChannelImpl($Class* clazz) {
	return $of($alloc(AsynchronousSocketChannelImpl));
}

int32_t AsynchronousSocketChannelImpl::hashCode() {
	 return this->$AsynchronousSocketChannel::hashCode();
}

bool AsynchronousSocketChannelImpl::equals(Object$* obj) {
	 return this->$AsynchronousSocketChannel::equals(obj);
}

$Object* AsynchronousSocketChannelImpl::clone() {
	 return this->$AsynchronousSocketChannel::clone();
}

void AsynchronousSocketChannelImpl::finalize() {
	this->$AsynchronousSocketChannel::finalize();
}

void AsynchronousSocketChannelImpl::init$($AsynchronousChannelGroupImpl* group) {
	$AsynchronousSocketChannel::init$($($nc(group)->provider()));
	$set(this, stateLock, $new($Object));
	this->state = AsynchronousSocketChannelImpl::ST_UNINITIALIZED;
	$set(this, readLock, $new($Object));
	$set(this, writeLock, $new($Object));
	$set(this, closeLock, $new($ReentrantReadWriteLock));
	$set(this, fd, $Net::socket(true));
	this->state = AsynchronousSocketChannelImpl::ST_UNCONNECTED;
}

void AsynchronousSocketChannelImpl::init$($AsynchronousChannelGroupImpl* group, $FileDescriptor* fd, $InetSocketAddress* remote) {
	$AsynchronousSocketChannel::init$($($nc(group)->provider()));
	$set(this, stateLock, $new($Object));
	this->state = AsynchronousSocketChannelImpl::ST_UNINITIALIZED;
	$set(this, readLock, $new($Object));
	$set(this, writeLock, $new($Object));
	$set(this, closeLock, $new($ReentrantReadWriteLock));
	$set(this, fd, fd);
	this->state = AsynchronousSocketChannelImpl::ST_CONNECTED;
	$set(this, localAddress, $Net::localAddress(fd));
	$set(this, remoteAddress, remote);
}

bool AsynchronousSocketChannelImpl::isOpen() {
	return !this->closed;
}

void AsynchronousSocketChannelImpl::begin() {
	$nc($($nc(this->closeLock)->readLock()))->lock();
	if (!isOpen()) {
		$throwNew($ClosedChannelException);
	}
}

void AsynchronousSocketChannelImpl::end() {
	$nc($($nc(this->closeLock)->readLock()))->unlock();
}

void AsynchronousSocketChannelImpl::close() {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->closeLock)->writeLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->closed) {
				return$1 = true;
				goto $finally;
			}
			this->closed = true;
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc($($nc(this->closeLock)->writeLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	implClose();
}

void AsynchronousSocketChannelImpl::enableReading(bool killed) {
	$synchronized(this->readLock) {
		this->reading = false;
		if (killed) {
			this->readKilled = true;
		}
	}
}

void AsynchronousSocketChannelImpl::enableReading() {
	enableReading(false);
}

void AsynchronousSocketChannelImpl::enableWriting(bool killed) {
	$synchronized(this->writeLock) {
		this->writing = false;
		if (killed) {
			this->writeKilled = true;
		}
	}
}

void AsynchronousSocketChannelImpl::enableWriting() {
	enableWriting(false);
}

void AsynchronousSocketChannelImpl::killReading() {
	$synchronized(this->readLock) {
		this->readKilled = true;
	}
}

void AsynchronousSocketChannelImpl::killWriting() {
	$synchronized(this->writeLock) {
		this->writeKilled = true;
	}
}

void AsynchronousSocketChannelImpl::killConnect() {
	killReading();
	killWriting();
}

$Future* AsynchronousSocketChannelImpl::connect($SocketAddress* remote) {
	return implConnect(remote, nullptr, nullptr);
}

void AsynchronousSocketChannelImpl::connect($SocketAddress* remote, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	implConnect(remote, attachment, handler);
}

$Future* AsynchronousSocketChannelImpl::read(bool isScatteringRead, $ByteBuffer* dst, $ByteBufferArray* dsts, int64_t timeout, $TimeUnit* unit, Object$* att, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (!isOpen()) {
		$var($Throwable, e, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(e);
		}
		$Invoker::invoke(this, handler, att, nullptr, e);
		return nullptr;
	}
	if (this->remoteAddress == nullptr) {
		$throwNew($NotYetConnectedException);
	}
	bool hasSpaceToRead = isScatteringRead || $nc(dst)->hasRemaining();
	bool shutdown = false;
	$synchronized(this->readLock) {
		if (this->readKilled) {
			$throwNew($IllegalStateException, "Reading not allowed due to timeout or cancellation"_s);
		}
		if (this->reading) {
			$throwNew($ReadPendingException);
		}
		if (this->readShutdown) {
			shutdown = true;
		} else if (hasSpaceToRead) {
			this->reading = true;
		}
	}
	if (shutdown || !hasSpaceToRead) {
		$var($Number, result, nullptr);
		if (isScatteringRead) {
			$assign(result, ((shutdown) ? $Long::valueOf((int64_t)-1) : $Long::valueOf((int64_t)0)));
		} else {
			$assign(result, $Integer::valueOf((shutdown) ? -1 : 0));
		}
		if (handler == nullptr) {
			return $CompletedFuture::withResult(result);
		}
		$Invoker::invoke(this, handler, att, result, nullptr);
		return nullptr;
	}
	return implRead(isScatteringRead, dst, dsts, timeout, unit, att, handler);
}

$Future* AsynchronousSocketChannelImpl::read($ByteBuffer* dst) {
	if ($nc(dst)->isReadOnly()) {
		$throwNew($IllegalArgumentException, "Read-only buffer"_s);
	}
	$init($TimeUnit);
	return read(false, dst, ($ByteBufferArray*)nullptr, (int64_t)0, $TimeUnit::MILLISECONDS, ($Object*)nullptr, ($CompletionHandler*)nullptr);
}

void AsynchronousSocketChannelImpl::read($ByteBuffer* dst, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	if ($nc(dst)->isReadOnly()) {
		$throwNew($IllegalArgumentException, "Read-only buffer"_s);
	}
	read(false, dst, ($ByteBufferArray*)nullptr, timeout, unit, attachment, handler);
}

void AsynchronousSocketChannelImpl::read($ByteBufferArray* dsts, int32_t offset, int32_t length, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	if ((offset < 0) || (length < 0) || (offset > $nc(dsts)->length - length)) {
		$throwNew($IndexOutOfBoundsException);
	}
	$var($ByteBufferArray, bufs, $Util::subsequence(dsts, offset, length));
	for (int32_t i = 0; i < $nc(bufs)->length; ++i) {
		if ($nc(bufs->get(i))->isReadOnly()) {
			$throwNew($IllegalArgumentException, "Read-only buffer"_s);
		}
	}
	read(true, ($ByteBuffer*)nullptr, bufs, timeout, unit, attachment, handler);
}

$Future* AsynchronousSocketChannelImpl::write(bool isGatheringWrite, $ByteBuffer* src, $ByteBufferArray* srcs, int64_t timeout, $TimeUnit* unit, Object$* att, $CompletionHandler* handler) {
	$useLocalCurrentObjectStackCache();
	bool hasDataToWrite = isGatheringWrite || $nc(src)->hasRemaining();
	bool closed = false;
	if (isOpen()) {
		if (this->remoteAddress == nullptr) {
			$throwNew($NotYetConnectedException);
		}
		$synchronized(this->writeLock) {
			if (this->writeKilled) {
				$throwNew($IllegalStateException, "Writing not allowed due to timeout or cancellation"_s);
			}
			if (this->writing) {
				$throwNew($WritePendingException);
			}
			if (this->writeShutdown) {
				closed = true;
			} else if (hasDataToWrite) {
				this->writing = true;
			}
		}
	} else {
		closed = true;
	}
	if (closed) {
		$var($Throwable, e, $new($ClosedChannelException));
		if (handler == nullptr) {
			return $CompletedFuture::withFailure(e);
		}
		$Invoker::invoke(this, handler, att, nullptr, e);
		return nullptr;
	}
	if (!hasDataToWrite) {
		$var($Number, result, (isGatheringWrite) ? static_cast<$Number*>($Long::valueOf((int64_t)0)) : static_cast<$Number*>($Integer::valueOf(0)));
		if (handler == nullptr) {
			return $CompletedFuture::withResult(result);
		}
		$Invoker::invoke(this, handler, att, result, nullptr);
		return nullptr;
	}
	return implWrite(isGatheringWrite, src, srcs, timeout, unit, att, handler);
}

$Future* AsynchronousSocketChannelImpl::write($ByteBuffer* src) {
	$init($TimeUnit);
	return write(false, src, ($ByteBufferArray*)nullptr, (int64_t)0, $TimeUnit::MILLISECONDS, ($Object*)nullptr, ($CompletionHandler*)nullptr);
}

void AsynchronousSocketChannelImpl::write($ByteBuffer* src, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	write(false, src, ($ByteBufferArray*)nullptr, timeout, unit, attachment, handler);
}

void AsynchronousSocketChannelImpl::write($ByteBufferArray* srcs$renamed, int32_t offset, int32_t length, int64_t timeout, $TimeUnit* unit, Object$* attachment, $CompletionHandler* handler) {
	$var($ByteBufferArray, srcs, srcs$renamed);
	if (handler == nullptr) {
		$throwNew($NullPointerException, "\'handler\' is null"_s);
	}
	if ((offset < 0) || (length < 0) || (offset > $nc(srcs)->length - length)) {
		$throwNew($IndexOutOfBoundsException);
	}
	$assign(srcs, $Util::subsequence(srcs, offset, length));
	write(true, ($ByteBuffer*)nullptr, srcs, timeout, unit, attachment, handler);
}

$NetworkChannel* AsynchronousSocketChannelImpl::bind($SocketAddress* local) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin();
			$synchronized(this->stateLock) {
				if (this->state == AsynchronousSocketChannelImpl::ST_PENDING) {
					$throwNew($ConnectionPendingException);
				}
				if (this->localAddress != nullptr) {
					$throwNew($AlreadyBoundException);
				}
				$var($InetSocketAddress, isa, (local == nullptr) ? $new($InetSocketAddress, 0) : $Net::checkAddress(local));
				$var($SecurityManager, sm, $System::getSecurityManager());
				if (sm != nullptr) {
					sm->checkListen($nc(isa)->getPort());
				}
				$var($FileDescriptor, var$1, this->fd);
				$var($InetAddress, var$2, $nc(isa)->getAddress());
				$NetHooks::beforeTcpBind(var$1, var$2, isa->getPort());
				$var($FileDescriptor, var$3, this->fd);
				$var($InetAddress, var$4, $nc(isa)->getAddress());
				$Net::bind(var$3, var$4, isa->getPort());
				$set(this, localAddress, $Net::localAddress(this->fd));
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} /*finally*/ {
			end();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return this;
}

$SocketAddress* AsynchronousSocketChannelImpl::getLocalAddress() {
	if (!isOpen()) {
		$throwNew($ClosedChannelException);
	}
	return $Net::getRevealedLocalAddress(this->localAddress);
}

$NetworkChannel* AsynchronousSocketChannelImpl::setOption($SocketOption* name, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($NetworkChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			begin();
			if (this->writeShutdown) {
				$throwNew($IOException, "Connection has been shutdown for writing"_s);
			}
			$init($StandardSocketOptions);
			if (name == $StandardSocketOptions::SO_REUSEADDR && $Net::useExclusiveBind()) {
				this->isReuseAddress = $nc(($cast($Boolean, value)))->booleanValue();
			} else {
				$init($Net);
				$Net::setSocketOption(this->fd, $Net::UNSPEC, name, value);
			}
			$assign(var$2, this);
			return$1 = true;
			goto $finally;
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
	$shouldNotReachHere();
}

$Object* AsynchronousSocketChannelImpl::getOption($SocketOption* name) {
	$useLocalCurrentObjectStackCache();
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			begin();
			$init($StandardSocketOptions);
			if (name == $StandardSocketOptions::SO_REUSEADDR && $Net::useExclusiveBind()) {
				$assign(var$2, $of($Boolean::valueOf(this->isReuseAddress)));
				return$1 = true;
				goto $finally;
			}
			$assign(var$2, $Net::getSocketOption(this->fd, $Net::UNSPEC, name));
			return$1 = true;
			goto $finally;
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
	$shouldNotReachHere();
}

$Set* AsynchronousSocketChannelImpl::supportedOptions() {
	$init($AsynchronousSocketChannelImpl$DefaultOptionsHolder);
	return $AsynchronousSocketChannelImpl$DefaultOptionsHolder::defaultOptions$;
}

$SocketAddress* AsynchronousSocketChannelImpl::getRemoteAddress() {
	if (!isOpen()) {
		$throwNew($ClosedChannelException);
	}
	return this->remoteAddress;
}

$AsynchronousSocketChannel* AsynchronousSocketChannelImpl::shutdownInput() {
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin();
			if (this->remoteAddress == nullptr) {
				$throwNew($NotYetConnectedException);
			}
			$synchronized(this->readLock) {
				if (!this->readShutdown) {
					$Net::shutdown(this->fd, $Net::SHUT_RD);
					this->readShutdown = true;
				}
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
	return this;
}

$AsynchronousSocketChannel* AsynchronousSocketChannelImpl::shutdownOutput() {
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin();
			if (this->remoteAddress == nullptr) {
				$throwNew($NotYetConnectedException);
			}
			$synchronized(this->writeLock) {
				if (!this->writeShutdown) {
					$Net::shutdown(this->fd, $Net::SHUT_WR);
					this->writeShutdown = true;
				}
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
	return this;
}

$String* AsynchronousSocketChannelImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($of(this)->getClass()->getName()));
	sb->append(u'[');
	$synchronized(this->stateLock) {
		if (!isOpen()) {
			sb->append("closed"_s);
		} else {
			switch (this->state) {
			case AsynchronousSocketChannelImpl::ST_UNCONNECTED:
				{
					sb->append("unconnected"_s);
					break;
				}
			case AsynchronousSocketChannelImpl::ST_PENDING:
				{
					sb->append("connection-pending"_s);
					break;
				}
			case AsynchronousSocketChannelImpl::ST_CONNECTED:
				{
					sb->append("connected"_s);
					if (this->readShutdown) {
						sb->append(" ishut"_s);
					}
					if (this->writeShutdown) {
						sb->append(" oshut"_s);
					}
					break;
				}
			}
			if (this->localAddress != nullptr) {
				sb->append(" local="_s);
				sb->append($($Net::getRevealedLocalAddressAsString(this->localAddress)));
			}
			if (this->remoteAddress != nullptr) {
				sb->append(" remote="_s);
				sb->append($($nc(this->remoteAddress)->toString()));
			}
		}
	}
	sb->append(u']');
	return sb->toString();
}

AsynchronousSocketChannelImpl::AsynchronousSocketChannelImpl() {
}

$Class* AsynchronousSocketChannelImpl::load$($String* name, bool initialize) {
	$loadClass(AsynchronousSocketChannelImpl, name, initialize, &_AsynchronousSocketChannelImpl_ClassInfo_, allocate$AsynchronousSocketChannelImpl);
	return class$;
}

$Class* AsynchronousSocketChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun