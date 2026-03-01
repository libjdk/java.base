#include <sun/nio/ch/NioSocketImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ProtocolFamily.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketImpl.h>
#include <java/net/SocketOption.h>
#include <java/net/SocketOptions.h>
#include <java/net/SocketTimeoutException.h>
#include <java/net/StandardProtocolFamily.h>
#include <java/net/StandardSocketOptions.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <sun/net/ConnectionResetException.h>
#include <sun/net/NetHooks.h>
#include <sun/net/ResourceManager.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/net/util/SocketExceptions.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/ch/ExtendedSocketOption.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/NativeThread.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/NioSocketImpl$1.h>
#include <sun/nio/ch/NioSocketImpl$2.h>
#include <sun/nio/ch/SocketDispatcher.h>
#include <sun/nio/ch/Util.h>
#include <jcpp.h>

#undef FALSE
#undef INET
#undef INET6
#undef INTERRUPTED
#undef IP_TOS
#undef MAX_BUFFER_SIZE
#undef MILLISECONDS
#undef NANOSECONDS
#undef POLLIN
#undef POLLOUT
#undef SHUT_RD
#undef SHUT_WR
#undef SO_BINDADDR
#undef SO_KEEPALIVE
#undef SO_LINGER
#undef SO_OOBINLINE
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_REUSEPORT
#undef SO_SNDBUF
#undef SO_TIMEOUT
#undef ST_CLOSED
#undef ST_CLOSING
#undef ST_CONNECTED
#undef ST_CONNECTING
#undef ST_NEW
#undef ST_UNCONNECTED
#undef TCP_NODELAY
#undef UNAVAILABLE

using $InetSocketAddressArray = $Array<::java::net::InetSocketAddress>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Cleaner = ::java::lang::ref::Cleaner;
using $Cleaner$Cleanable = ::java::lang::ref::Cleaner$Cleanable;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ProtocolFamily = ::java::net::ProtocolFamily;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketImpl = ::java::net::SocketImpl;
using $SocketOption = ::java::net::SocketOption;
using $SocketOptions = ::java::net::SocketOptions;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $StandardProtocolFamily = ::java::net::StandardProtocolFamily;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $UnknownHostException = ::java::net::UnknownHostException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;
using $ConnectionResetException = ::sun::net::ConnectionResetException;
using $NetHooks = ::sun::net::NetHooks;
using $ResourceManager = ::sun::net::ResourceManager;
using $ExtendedSocketOptions = ::sun::net::ext::ExtendedSocketOptions;
using $SocketExceptions = ::sun::net::util::SocketExceptions;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $ExtendedSocketOption = ::sun::nio::ch::ExtendedSocketOption;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $NativeThread = ::sun::nio::ch::NativeThread;
using $Net = ::sun::nio::ch::Net;
using $NioSocketImpl$1 = ::sun::nio::ch::NioSocketImpl$1;
using $NioSocketImpl$2 = ::sun::nio::ch::NioSocketImpl$2;
using $SocketDispatcher = ::sun::nio::ch::SocketDispatcher;
using $Util = ::sun::nio::ch::Util;

namespace sun {
	namespace nio {
		namespace ch {

class NioSocketImpl$$Lambda$lambda$closerFor$0 : public $Runnable {
	$class(NioSocketImpl$$Lambda$lambda$closerFor$0, $NO_CLASS_INIT, $Runnable)
public:
	void init$($FileDescriptor* fd) {
		$set(this, fd, fd);
	}
	virtual void run() override {
		NioSocketImpl::lambda$closerFor$0(fd);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<NioSocketImpl$$Lambda$lambda$closerFor$0>());
	}
	$FileDescriptor* fd = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo NioSocketImpl$$Lambda$lambda$closerFor$0::fieldInfos[2] = {
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PUBLIC, $field(NioSocketImpl$$Lambda$lambda$closerFor$0, fd)},
	{}
};
$MethodInfo NioSocketImpl$$Lambda$lambda$closerFor$0::methodInfos[3] = {
	{"<init>", "(Ljava/io/FileDescriptor;)V", nullptr, $PUBLIC, $method(NioSocketImpl$$Lambda$lambda$closerFor$0, init$, void, $FileDescriptor*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(NioSocketImpl$$Lambda$lambda$closerFor$0, run, void)},
	{}
};
$ClassInfo NioSocketImpl$$Lambda$lambda$closerFor$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.NioSocketImpl$$Lambda$lambda$closerFor$0",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* NioSocketImpl$$Lambda$lambda$closerFor$0::load$($String* name, bool initialize) {
	$loadClass(NioSocketImpl$$Lambda$lambda$closerFor$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* NioSocketImpl$$Lambda$lambda$closerFor$0::class$ = nullptr;

class NioSocketImpl$$Lambda$lambda$closerFor$1$1 : public $Runnable {
	$class(NioSocketImpl$$Lambda$lambda$closerFor$1$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$($FileDescriptor* fd) {
		$set(this, fd, fd);
	}
	virtual void run() override {
		NioSocketImpl::lambda$closerFor$1(fd);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<NioSocketImpl$$Lambda$lambda$closerFor$1$1>());
	}
	$FileDescriptor* fd = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo NioSocketImpl$$Lambda$lambda$closerFor$1$1::fieldInfos[2] = {
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PUBLIC, $field(NioSocketImpl$$Lambda$lambda$closerFor$1$1, fd)},
	{}
};
$MethodInfo NioSocketImpl$$Lambda$lambda$closerFor$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/io/FileDescriptor;)V", nullptr, $PUBLIC, $method(NioSocketImpl$$Lambda$lambda$closerFor$1$1, init$, void, $FileDescriptor*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(NioSocketImpl$$Lambda$lambda$closerFor$1$1, run, void)},
	{}
};
$ClassInfo NioSocketImpl$$Lambda$lambda$closerFor$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.NioSocketImpl$$Lambda$lambda$closerFor$1$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* NioSocketImpl$$Lambda$lambda$closerFor$1$1::load$($String* name, bool initialize) {
	$loadClass(NioSocketImpl$$Lambda$lambda$closerFor$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* NioSocketImpl$$Lambda$lambda$closerFor$1$1::class$ = nullptr;

$FieldInfo _NioSocketImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(NioSocketImpl, $assertionsDisabled)},
	{"nd", "Lsun/nio/ch/NativeDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NioSocketImpl, nd)},
	{"MAX_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, MAX_BUFFER_SIZE)},
	{"server", "Z", nullptr, $PRIVATE | $FINAL, $field(NioSocketImpl, server)},
	{"readLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(NioSocketImpl, readLock)},
	{"writeLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(NioSocketImpl, writeLock)},
	{"stateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(NioSocketImpl, stateLock)},
	{"ST_NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, ST_NEW)},
	{"ST_UNCONNECTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, ST_UNCONNECTED)},
	{"ST_CONNECTING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, ST_CONNECTING)},
	{"ST_CONNECTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, ST_CONNECTED)},
	{"ST_CLOSING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, ST_CLOSING)},
	{"ST_CLOSED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NioSocketImpl, ST_CLOSED)},
	{"state", "I", nullptr, $PRIVATE | $VOLATILE, $field(NioSocketImpl, state)},
	{"stream", "Z", nullptr, $PRIVATE, $field(NioSocketImpl, stream)},
	{"cleaner", "Ljava/lang/ref/Cleaner$Cleanable;", nullptr, $PRIVATE, $field(NioSocketImpl, cleaner)},
	{"nonBlocking", "Z", nullptr, $PRIVATE | $VOLATILE, $field(NioSocketImpl, nonBlocking)},
	{"readerThread", "J", nullptr, $PRIVATE, $field(NioSocketImpl, readerThread)},
	{"writerThread", "J", nullptr, $PRIVATE, $field(NioSocketImpl, writerThread)},
	{"isReuseAddress", "Z", nullptr, $PRIVATE, $field(NioSocketImpl, isReuseAddress)},
	{"timeout", "I", nullptr, $PRIVATE | $VOLATILE, $field(NioSocketImpl, timeout)},
	{"isInputClosed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(NioSocketImpl, isInputClosed)},
	{"isOutputClosed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(NioSocketImpl, isOutputClosed)},
	{"readEOF", "Z", nullptr, $PRIVATE, $field(NioSocketImpl, readEOF)},
	{"connectionReset", "Z", nullptr, $PRIVATE, $field(NioSocketImpl, connectionReset)},
	{"clientSocketOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(NioSocketImpl, clientSocketOptions)},
	{"serverSocketOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(NioSocketImpl, serverSocketOptions)},
	{}
};

$MethodInfo _NioSocketImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Z)V", nullptr, $PUBLIC, $method(NioSocketImpl, init$, void, bool)},
	{"accept", "(Ljava/net/SocketImpl;)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, accept, void, $SocketImpl*), "java.io.IOException"},
	{"available", "()I", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, available, int32_t), "java.io.IOException"},
	{"beginAccept", "()Ljava/io/FileDescriptor;", nullptr, $PRIVATE, $method(NioSocketImpl, beginAccept, $FileDescriptor*), "java.net.SocketException"},
	{"beginConnect", "(Ljava/net/InetAddress;I)Ljava/io/FileDescriptor;", nullptr, $PRIVATE, $method(NioSocketImpl, beginConnect, $FileDescriptor*, $InetAddress*, int32_t), "java.io.IOException"},
	{"beginRead", "()Ljava/io/FileDescriptor;", nullptr, $PRIVATE, $method(NioSocketImpl, beginRead, $FileDescriptor*), "java.net.SocketException"},
	{"beginWrite", "()Ljava/io/FileDescriptor;", nullptr, $PRIVATE, $method(NioSocketImpl, beginWrite, $FileDescriptor*), "java.net.SocketException"},
	{"bind", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, bind, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"booleanValue", "(Ljava/lang/Object;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(NioSocketImpl, booleanValue, bool, Object$*, $String*), "java.net.SocketException"},
	{"close", "()V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, close, void), "java.io.IOException"},
	{"closerFor", "(Ljava/io/FileDescriptor;Z)Ljava/lang/Runnable;", nullptr, $PRIVATE | $STATIC, $staticMethod(NioSocketImpl, closerFor, $Runnable*, $FileDescriptor*, bool)},
	{"configureBlocking", "(Ljava/io/FileDescriptor;)V", nullptr, $PRIVATE, $method(NioSocketImpl, configureBlocking, void, $FileDescriptor*), "java.io.IOException"},
	{"configureNonBlocking", "(Ljava/io/FileDescriptor;)V", nullptr, $PRIVATE, $method(NioSocketImpl, configureNonBlocking, void, $FileDescriptor*), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, connect, void, $SocketAddress*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/lang/String;I)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, connect, void, $String*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, connect, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"create", "(Z)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, create, void, bool), "java.io.IOException"},
	{"endAccept", "(Z)V", nullptr, $PRIVATE, $method(NioSocketImpl, endAccept, void, bool), "java.net.SocketException"},
	{"endConnect", "(Ljava/io/FileDescriptor;Z)V", nullptr, $PRIVATE, $method(NioSocketImpl, endConnect, void, $FileDescriptor*, bool), "java.io.IOException"},
	{"endRead", "(Z)V", nullptr, $PRIVATE, $method(NioSocketImpl, endRead, void, bool), "java.net.SocketException"},
	{"endWrite", "(Z)V", nullptr, $PRIVATE, $method(NioSocketImpl, endWrite, void, bool), "java.net.SocketException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(NioSocketImpl, ensureOpen, void), "java.net.SocketException"},
	{"ensureOpenAndConnected", "()V", nullptr, $PRIVATE, $method(NioSocketImpl, ensureOpenAndConnected, void), "java.net.SocketException"},
	{"family", "()Ljava/net/ProtocolFamily;", nullptr, $PRIVATE | $STATIC, $staticMethod(NioSocketImpl, family, $ProtocolFamily*)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, getInputStream, $InputStream*)},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PROTECTED, $virtualMethod(NioSocketImpl, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getOption", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(NioSocketImpl, getOption, $Object*, int32_t), "java.net.SocketException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, getOutputStream, $OutputStream*)},
	{"implRead", "([BII)I", nullptr, $PRIVATE, $method(NioSocketImpl, implRead, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"implWrite", "([BII)I", nullptr, $PRIVATE, $method(NioSocketImpl, implWrite, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"intValue", "(Ljava/lang/Object;Ljava/lang/String;)I", nullptr, $PRIVATE, $method(NioSocketImpl, intValue, int32_t, Object$*, $String*), "java.net.SocketException"},
	{"isOpen", "()Z", nullptr, $PRIVATE, $method(NioSocketImpl, isOpen, bool)},
	{"lambda$closerFor$0", "(Ljava/io/FileDescriptor;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(NioSocketImpl, lambda$closerFor$0, void, $FileDescriptor*)},
	{"lambda$closerFor$1", "(Ljava/io/FileDescriptor;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(NioSocketImpl, lambda$closerFor$1, void, $FileDescriptor*)},
	{"listen", "(I)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, listen, void, int32_t), "java.io.IOException"},
	{"park", "(Ljava/io/FileDescriptor;IJ)V", nullptr, $PRIVATE, $method(NioSocketImpl, park, void, $FileDescriptor*, int32_t, int64_t), "java.io.IOException"},
	{"park", "(Ljava/io/FileDescriptor;I)V", nullptr, $PRIVATE, $method(NioSocketImpl, park, void, $FileDescriptor*, int32_t), "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PRIVATE, $method(NioSocketImpl, read, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"sendUrgentData", "(I)V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, sendUrgentData, void, int32_t), "java.io.IOException"},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)V", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)V", $PROTECTED, $virtualMethod(NioSocketImpl, setOption, void, $SocketOption*, Object$*), "java.io.IOException"},
	{"setOption", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(NioSocketImpl, setOption, void, int32_t, Object$*), "java.net.SocketException"},
	{"shutdownInput", "()V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, shutdownInput, void), "java.io.IOException"},
	{"shutdownOutput", "()V", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, shutdownOutput, void), "java.io.IOException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PROTECTED, $virtualMethod(NioSocketImpl, supportedOptions, $Set*)},
	{"supportsUrgentData", "()Z", nullptr, $PROTECTED, $virtualMethod(NioSocketImpl, supportsUrgentData, bool)},
	{"timedAccept", "(Ljava/io/FileDescriptor;Ljava/io/FileDescriptor;[Ljava/net/InetSocketAddress;J)I", nullptr, $PRIVATE, $method(NioSocketImpl, timedAccept, int32_t, $FileDescriptor*, $FileDescriptor*, $InetSocketAddressArray*, int64_t), "java.io.IOException"},
	{"timedFinishConnect", "(Ljava/io/FileDescriptor;J)Z", nullptr, $PRIVATE, $method(NioSocketImpl, timedFinishConnect, bool, $FileDescriptor*, int64_t), "java.io.IOException"},
	{"timedRead", "(Ljava/io/FileDescriptor;[BIIJ)I", nullptr, $PRIVATE, $method(NioSocketImpl, timedRead, int32_t, $FileDescriptor*, $bytes*, int32_t, int32_t, int64_t), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryClose", "()Z", nullptr, $PRIVATE, $method(NioSocketImpl, tryClose, bool), "java.io.IOException"},
	{"tryFinishClose", "()V", nullptr, $PRIVATE, $method(NioSocketImpl, tryFinishClose, void)},
	{"tryLock", "(Ljava/util/concurrent/locks/ReentrantLock;JLjava/util/concurrent/TimeUnit;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(NioSocketImpl, tryLock, int64_t, $ReentrantLock*, int64_t, $TimeUnit*)},
	{"tryRead", "(Ljava/io/FileDescriptor;[BII)I", nullptr, $PRIVATE, $method(NioSocketImpl, tryRead, int32_t, $FileDescriptor*, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"tryWrite", "(Ljava/io/FileDescriptor;[BII)I", nullptr, $PRIVATE, $method(NioSocketImpl, tryWrite, int32_t, $FileDescriptor*, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"write", "([BII)V", nullptr, $PRIVATE, $method(NioSocketImpl, write, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{}
};

$InnerClassInfo _NioSocketImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.NioSocketImpl$2", nullptr, nullptr, 0},
	{"sun.nio.ch.NioSocketImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NioSocketImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.nio.ch.NioSocketImpl",
	"java.net.SocketImpl",
	"sun.net.PlatformSocketImpl",
	_NioSocketImpl_FieldInfo_,
	_NioSocketImpl_MethodInfo_,
	nullptr,
	nullptr,
	_NioSocketImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.NioSocketImpl$2,sun.nio.ch.NioSocketImpl$1"
};

$Object* allocate$NioSocketImpl($Class* clazz) {
	return $of($alloc(NioSocketImpl));
}

$String* NioSocketImpl::toString() {
	 return this->$SocketImpl::toString();
}

int32_t NioSocketImpl::hashCode() {
	 return this->$SocketImpl::hashCode();
}

bool NioSocketImpl::equals(Object$* obj) {
	 return this->$SocketImpl::equals(obj);
}

$Object* NioSocketImpl::clone() {
	 return this->$SocketImpl::clone();
}

void NioSocketImpl::finalize() {
	this->$SocketImpl::finalize();
}

bool NioSocketImpl::$assertionsDisabled = false;
$NativeDispatcher* NioSocketImpl::nd = nullptr;
$volatile($Set*) NioSocketImpl::clientSocketOptions = nullptr;
$volatile($Set*) NioSocketImpl::serverSocketOptions = nullptr;

void NioSocketImpl::init$(bool server) {
	$SocketImpl::init$();
	$set(this, readLock, $new($ReentrantLock));
	$set(this, writeLock, $new($ReentrantLock));
	$set(this, stateLock, $new($Object));
	this->server = server;
}

bool NioSocketImpl::isOpen() {
	return this->state < NioSocketImpl::ST_CLOSING;
}

void NioSocketImpl::ensureOpen() {
	int32_t state = this->state;
	if (state == NioSocketImpl::ST_NEW) {
		$throwNew($SocketException, "Socket not created"_s);
	}
	if (state >= NioSocketImpl::ST_CLOSING) {
		$throwNew($SocketException, "Socket closed"_s);
	}
}

void NioSocketImpl::ensureOpenAndConnected() {
	int32_t state = this->state;
	if (state < NioSocketImpl::ST_CONNECTED) {
		$throwNew($SocketException, "Not connected"_s);
	}
	if (state > NioSocketImpl::ST_CONNECTED) {
		$throwNew($SocketException, "Socket closed"_s);
	}
}

void NioSocketImpl::park($FileDescriptor* fd, int32_t event, int64_t nanos) {
	int64_t millis = 0;
	if (nanos == 0) {
		millis = -1;
	} else {
		$init($TimeUnit);
		millis = $TimeUnit::NANOSECONDS->toMillis(nanos);
	}
	$Net::poll(fd, event, millis);
}

void NioSocketImpl::park($FileDescriptor* fd, int32_t event) {
	park(fd, event, 0);
}

void NioSocketImpl::configureBlocking($FileDescriptor* fd) {
	if (!NioSocketImpl::$assertionsDisabled && !$nc(this->readLock)->isHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	if (this->nonBlocking) {
		$synchronized(this->stateLock) {
			ensureOpen();
			$IOUtil::configureBlocking(fd, true);
			this->nonBlocking = false;
		}
	}
}

void NioSocketImpl::configureNonBlocking($FileDescriptor* fd) {
	if (!NioSocketImpl::$assertionsDisabled && !$nc(this->readLock)->isHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	if (!this->nonBlocking) {
		$synchronized(this->stateLock) {
			ensureOpen();
			$IOUtil::configureBlocking(fd, false);
			this->nonBlocking = true;
		}
	}
}

$FileDescriptor* NioSocketImpl::beginRead() {
	$synchronized(this->stateLock) {
		ensureOpenAndConnected();
		this->readerThread = $NativeThread::current();
		return this->fd;
	}
}

void NioSocketImpl::endRead(bool completed) {
	$synchronized(this->stateLock) {
		this->readerThread = 0;
		int32_t state = this->state;
		if (state == NioSocketImpl::ST_CLOSING) {
			tryFinishClose();
		}
		if (!completed && state >= NioSocketImpl::ST_CLOSING) {
			$throwNew($SocketException, "Socket closed"_s);
		}
	}
}

int32_t NioSocketImpl::tryRead($FileDescriptor* fd, $bytes* b, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, dst, $Util::getTemporaryDirectBuffer(len));
	if (!NioSocketImpl::$assertionsDisabled && !($nc(dst)->position() == 0)) {
		$throwNew($AssertionError);
	}
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			int32_t n = $nc(NioSocketImpl::nd)->read(fd, $nc(($cast($DirectBuffer, dst)))->address(), len);
			if (n > 0) {
				$nc(dst)->get(b, off, n);
			}
			var$2 = n;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Util::offerFirstTemporaryDirectBuffer(dst);
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

int32_t NioSocketImpl::timedRead($FileDescriptor* fd, $bytes* b, int32_t off, int32_t len, int64_t nanos) {
	int64_t startNanos = $System::nanoTime();
	int32_t n = tryRead(fd, b, off, len);
	while (n == $IOStatus::UNAVAILABLE && isOpen()) {
		int64_t remainingNanos = nanos - ($System::nanoTime() - startNanos);
		if (remainingNanos <= 0) {
			$throwNew($SocketTimeoutException, "Read timed out"_s);
		}
		$init($Net);
		park(fd, $Net::POLLIN, remainingNanos);
		n = tryRead(fd, b, off, len);
	}
	return n;
}

int32_t NioSocketImpl::implRead($bytes* b, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	int32_t n = 0;
	$var($FileDescriptor, fd, beginRead());
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			try {
				if (this->connectionReset) {
					$throwNew($SocketException, "Connection reset"_s);
				}
				if (this->isInputClosed) {
					var$2 = -1;
					return$1 = true;
					goto $finally;
				}
				int32_t timeout = this->timeout;
				if (timeout > 0) {
					configureNonBlocking(fd);
					$init($TimeUnit);
					n = timedRead(fd, b, off, len, $TimeUnit::MILLISECONDS->toNanos(timeout));
				} else {
					n = tryRead(fd, b, off, len);
					while (true) {
						bool var$3 = $IOStatus::okayToRetry(n);
						if (!(var$3 && isOpen())) {
							break;
						}
						{
							$init($Net);
							park(fd, $Net::POLLIN);
							n = tryRead(fd, b, off, len);
						}
					}
				}
				var$2 = n;
				return$1 = true;
				goto $finally;
			} catch ($SocketTimeoutException& e) {
				$throw(e);
			} catch ($ConnectionResetException& e) {
				this->connectionReset = true;
				$throwNew($SocketException, "Connection reset"_s);
			} catch ($IOException& ioe) {
				$throwNew($SocketException, $(ioe->getMessage()));
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			endRead(n > 0);
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

int32_t NioSocketImpl::read($bytes* b, int32_t off, int32_t len) {
	$Objects::checkFromIndexSize(off, len, $nc(b)->length);
	if (len == 0) {
		return 0;
	} else {
		$nc(this->readLock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			int32_t var$2 = 0;
			bool return$1 = false;
			try {
				if (this->readEOF) {
					var$2 = -1;
					return$1 = true;
					goto $finally;
				}
				int32_t size = $Math::min(len, NioSocketImpl::MAX_BUFFER_SIZE);
				int32_t n = implRead(b, off, size);
				if (n == -1) {
					this->readEOF = true;
				}
				var$2 = n;
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->readLock)->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

$FileDescriptor* NioSocketImpl::beginWrite() {
	$synchronized(this->stateLock) {
		ensureOpenAndConnected();
		this->writerThread = $NativeThread::current();
		return this->fd;
	}
}

void NioSocketImpl::endWrite(bool completed) {
	$synchronized(this->stateLock) {
		this->writerThread = 0;
		int32_t state = this->state;
		if (state == NioSocketImpl::ST_CLOSING) {
			tryFinishClose();
		}
		if (!completed && state >= NioSocketImpl::ST_CLOSING) {
			$throwNew($SocketException, "Socket closed"_s);
		}
	}
}

int32_t NioSocketImpl::tryWrite($FileDescriptor* fd, $bytes* b, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, src, $Util::getTemporaryDirectBuffer(len));
	if (!NioSocketImpl::$assertionsDisabled && !($nc(src)->position() == 0)) {
		$throwNew($AssertionError);
	}
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			$nc(src)->put(b, off, len);
			var$2 = $nc(NioSocketImpl::nd)->write(fd, $nc(($cast($DirectBuffer, src)))->address(), len);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Util::offerFirstTemporaryDirectBuffer(src);
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

int32_t NioSocketImpl::implWrite($bytes* b, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	int32_t n = 0;
	$var($FileDescriptor, fd, beginWrite());
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			try {
				n = tryWrite(fd, b, off, len);
				while (true) {
					bool var$3 = $IOStatus::okayToRetry(n);
					if (!(var$3 && isOpen())) {
						break;
					}
					{
						$init($Net);
						park(fd, $Net::POLLOUT);
						n = tryWrite(fd, b, off, len);
					}
				}
				var$2 = n;
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$throwNew($SocketException, $(ioe->getMessage()));
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			endWrite(n > 0);
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

void NioSocketImpl::write($bytes* b, int32_t off, int32_t len) {
	$Objects::checkFromIndexSize(off, len, $nc(b)->length);
	if (len > 0) {
		$nc(this->writeLock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				int32_t pos = off;
				int32_t end = off + len;
				while (pos < end) {
					int32_t size = $Math::min((end - pos), NioSocketImpl::MAX_BUFFER_SIZE);
					int32_t n = implWrite(b, pos, size);
					pos += n;
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->writeLock)->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void NioSocketImpl::create(bool stream) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->stateLock) {
		if (this->state != NioSocketImpl::ST_NEW) {
			$throwNew($IOException, "Already created"_s);
		}
		if (!stream) {
			$ResourceManager::beforeUdpCreate();
		}
		$var($FileDescriptor, fd, nullptr);
		try {
			if (this->server) {
				if (!NioSocketImpl::$assertionsDisabled && !stream) {
					$throwNew($AssertionError);
				}
				$assign(fd, $Net::serverSocket(true));
			} else {
				$assign(fd, $Net::socket(stream));
			}
		} catch ($IOException& ioe) {
			if (!stream) {
				$ResourceManager::afterUdpClose();
			}
			$throw(ioe);
		}
		$var($Runnable, closer, closerFor(fd, stream));
		$set(this, fd, fd);
		this->stream = stream;
		$set(this, cleaner, $nc($($CleanerFactory::cleaner()))->register$(this, closer));
		this->state = NioSocketImpl::ST_UNCONNECTED;
	}
}

$FileDescriptor* NioSocketImpl::beginConnect($InetAddress* address, int32_t port) {
	$synchronized(this->stateLock) {
		int32_t state = this->state;
		if (state != NioSocketImpl::ST_UNCONNECTED) {
			if (state == NioSocketImpl::ST_NEW) {
				$throwNew($SocketException, "Not created"_s);
			}
			if (state == NioSocketImpl::ST_CONNECTING) {
				$throwNew($SocketException, "Connection in progress"_s);
			}
			if (state == NioSocketImpl::ST_CONNECTED) {
				$throwNew($SocketException, "Already connected"_s);
			}
			if (state >= NioSocketImpl::ST_CLOSING) {
				$throwNew($SocketException, "Socket closed"_s);
			}
			if (!NioSocketImpl::$assertionsDisabled) {
				$throwNew($AssertionError);
			}
		}
		this->state = NioSocketImpl::ST_CONNECTING;
		if (this->localport == 0) {
			$NetHooks::beforeTcpConnect(this->fd, address, port);
		}
		$set(this, address, address);
		this->port = port;
		this->readerThread = $NativeThread::current();
		return this->fd;
	}
}

void NioSocketImpl::endConnect($FileDescriptor* fd, bool completed) {
	$synchronized(this->stateLock) {
		this->readerThread = 0;
		int32_t state = this->state;
		if (state == NioSocketImpl::ST_CLOSING) {
			tryFinishClose();
		}
		if (completed && state == NioSocketImpl::ST_CONNECTING) {
			this->state = NioSocketImpl::ST_CONNECTED;
			this->localport = $nc($($Net::localAddress(fd)))->getPort();
		} else if (!completed && state >= NioSocketImpl::ST_CLOSING) {
			$throwNew($SocketException, "Socket closed"_s);
		}
	}
}

bool NioSocketImpl::timedFinishConnect($FileDescriptor* fd, int64_t nanos) {
	int64_t startNanos = $System::nanoTime();
	bool polled = $Net::pollConnectNow(fd);
	while (!polled && isOpen()) {
		int64_t remainingNanos = nanos - ($System::nanoTime() - startNanos);
		if (remainingNanos <= 0) {
			$throwNew($SocketTimeoutException, "Connect timed out"_s);
		}
		park(fd, $Net::POLLOUT, remainingNanos);
		polled = $Net::pollConnectNow(fd);
	}
	return polled && isOpen();
}

void NioSocketImpl::connect($SocketAddress* remote, int32_t millis) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($InetSocketAddress, remote))) {
		$throwNew($IOException, "Unsupported address type"_s);
	}
	$var($InetSocketAddress, isa, $cast($InetSocketAddress, remote));
	if ($nc(isa)->isUnresolved()) {
		$throwNew($UnknownHostException, $(isa->getHostName()));
	}
	$var($InetAddress, address, $nc(isa)->getAddress());
	if ($nc(address)->isAnyLocalAddress()) {
		$assign(address, $InetAddress::getLocalHost());
	}
	int32_t port = isa->getPort();
	$var($ReentrantLock, connectLock, this->readLock);
	try {
		$nc(connectLock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				bool connected = false;
				$var($FileDescriptor, fd, beginConnect(address, port));
				{
					$var($Throwable, var$1, nullptr);
					try {
						if (millis > 0) {
							configureNonBlocking(fd);
						}
						int32_t n = $Net::connect(fd, address, port);
						if (n > 0) {
							connected = true;
						} else {
							if (!NioSocketImpl::$assertionsDisabled && !$IOStatus::okayToRetry(n)) {
								$throwNew($AssertionError);
							}
							if (millis > 0) {
								$init($TimeUnit);
								int64_t nanos = $TimeUnit::MILLISECONDS->toNanos(millis);
								connected = timedFinishConnect(fd, nanos);
							} else {
								bool polled = false;
								while (!polled && isOpen()) {
									park(fd, $Net::POLLOUT);
									polled = $Net::pollConnectNow(fd);
								}
								connected = polled && isOpen();
							}
						}
						if (connected && millis > 0) {
							configureBlocking(fd);
						}
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						endConnect(fd, connected);
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				connectLock->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& ioe) {
		close();
		$throw($($SocketExceptions::of(ioe, isa)));
	}
}

void NioSocketImpl::connect($String* host, int32_t port) {
	connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, host, port)), 0);
}

void NioSocketImpl::connect($InetAddress* address, int32_t port) {
	connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, address, port)), 0);
}

void NioSocketImpl::bind($InetAddress* host, int32_t port) {
	$synchronized(this->stateLock) {
		ensureOpen();
		if (this->localport != 0) {
			$throwNew($SocketException, "Already bound"_s);
		}
		$NetHooks::beforeTcpBind(this->fd, host, port);
		$Net::bind(this->fd, host, port);
		$set(this, address, host);
		this->localport = $nc($($Net::localAddress(this->fd)))->getPort();
	}
}

void NioSocketImpl::listen(int32_t backlog) {
	$synchronized(this->stateLock) {
		ensureOpen();
		if (this->localport == 0) {
			$throwNew($SocketException, "Not bound"_s);
		}
		$Net::listen(this->fd, backlog < 1 ? 50 : backlog);
	}
}

$FileDescriptor* NioSocketImpl::beginAccept() {
	$synchronized(this->stateLock) {
		ensureOpen();
		if (!this->stream) {
			$throwNew($SocketException, "Not a stream socket"_s);
		}
		if (this->localport == 0) {
			$throwNew($SocketException, "Not bound"_s);
		}
		this->readerThread = $NativeThread::current();
		return this->fd;
	}
}

void NioSocketImpl::endAccept(bool completed) {
	$synchronized(this->stateLock) {
		int32_t state = this->state;
		this->readerThread = 0;
		if (state == NioSocketImpl::ST_CLOSING) {
			tryFinishClose();
		}
		if (!completed && state >= NioSocketImpl::ST_CLOSING) {
			$throwNew($SocketException, "Socket closed"_s);
		}
	}
}

int32_t NioSocketImpl::timedAccept($FileDescriptor* fd, $FileDescriptor* newfd, $InetSocketAddressArray* isaa, int64_t nanos) {
	int64_t startNanos = $System::nanoTime();
	int32_t n = $Net::accept(fd, newfd, isaa);
	while (n == $IOStatus::UNAVAILABLE && isOpen()) {
		int64_t remainingNanos = nanos - ($System::nanoTime() - startNanos);
		if (remainingNanos <= 0) {
			$throwNew($SocketTimeoutException, "Accept timed out"_s);
		}
		park(fd, $Net::POLLIN, remainingNanos);
		n = $Net::accept(fd, newfd, isaa);
	}
	return n;
}

void NioSocketImpl::accept($SocketImpl* si) {
	$useLocalCurrentObjectStackCache();
	$var(NioSocketImpl, nsi, $cast(NioSocketImpl, si));
	if ($nc(nsi)->state != NioSocketImpl::ST_NEW) {
		$throwNew($SocketException, "Not a newly created SocketImpl"_s);
	}
	$var($FileDescriptor, newfd, $new($FileDescriptor));
	$var($InetSocketAddressArray, isaa, $new($InetSocketAddressArray, 1));
	$var($ReentrantLock, acceptLock, this->readLock);
	int32_t timeout = this->timeout;
	int64_t remainingNanos = 0;
	if (timeout > 0) {
		$init($TimeUnit);
		remainingNanos = tryLock(acceptLock, timeout, $TimeUnit::MILLISECONDS);
		if (remainingNanos <= 0) {
			if (!NioSocketImpl::$assertionsDisabled && ! !$nc(acceptLock)->isHeldByCurrentThread()) {
				$throwNew($AssertionError);
			}
			$throwNew($SocketTimeoutException, "Accept timed out"_s);
		}
	} else {
		$nc(acceptLock)->lock();
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			int32_t n = 0;
			$var($FileDescriptor, fd, beginAccept());
			{
				$var($Throwable, var$1, nullptr);
				try {
					if (remainingNanos > 0) {
						configureNonBlocking(fd);
						n = timedAccept(fd, newfd, isaa, remainingNanos);
					} else {
						n = $Net::accept(fd, newfd, isaa);
						while (true) {
							bool var$2 = $IOStatus::okayToRetry(n);
							if (!(var$2 && isOpen())) {
								break;
							}
							{
								park(fd, $Net::POLLIN);
								n = $Net::accept(fd, newfd, isaa);
							}
						}
					}
				} catch ($Throwable& var$3) {
					$assign(var$1, var$3);
				} /*finally*/ {
					endAccept(n > 0);
					if (!NioSocketImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} /*finally*/ {
			$nc(acceptLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($InetSocketAddress, localAddress, nullptr);
	try {
		$assign(localAddress, $Net::localAddress(newfd));
		$IOUtil::configureBlocking(newfd, true);
	} catch ($IOException& ioe) {
		$nc(NioSocketImpl::nd)->close(newfd);
		$throw(ioe);
	}
	$var($Runnable, closer, closerFor(newfd, true));
	$synchronized($nc(nsi)->stateLock) {
		$set(nsi, fd, newfd);
		nsi->stream = true;
		$set(nsi, cleaner, $nc($($CleanerFactory::cleaner()))->register$(nsi, closer));
		nsi->localport = $nc(localAddress)->getPort();
		$set(nsi, address, $nc(isaa->get(0))->getAddress());
		nsi->port = $nc(isaa->get(0))->getPort();
		nsi->state = NioSocketImpl::ST_CONNECTED;
	}
}

$InputStream* NioSocketImpl::getInputStream() {
	return $new($NioSocketImpl$1, this);
}

$OutputStream* NioSocketImpl::getOutputStream() {
	return $new($NioSocketImpl$2, this);
}

int32_t NioSocketImpl::available() {
	$synchronized(this->stateLock) {
		ensureOpenAndConnected();
		if (this->isInputClosed) {
			return 0;
		} else {
			return $Net::available(this->fd);
		}
	}
}

bool NioSocketImpl::tryClose() {
	$useLocalCurrentObjectStackCache();
	if (!NioSocketImpl::$assertionsDisabled && !($Thread::holdsLock(this->stateLock) && this->state == NioSocketImpl::ST_CLOSING)) {
		$throwNew($AssertionError);
	}
	if (this->readerThread == 0 && this->writerThread == 0) {
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$nc(this->cleaner)->clean();
				} catch ($UncheckedIOException& ioe) {
					$throw($($cast($IOException, ioe->getCause())));
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				this->state = NioSocketImpl::ST_CLOSED;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		return true;
	} else {
		return false;
	}
}

void NioSocketImpl::tryFinishClose() {
	try {
		tryClose();
	} catch ($IOException& ignore) {
	}
}

void NioSocketImpl::close() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->stateLock) {
		int32_t state = this->state;
		if (state >= NioSocketImpl::ST_CLOSING) {
			return;
		}
		if (state == NioSocketImpl::ST_NEW) {
			this->state = NioSocketImpl::ST_CLOSED;
			return;
		}
		this->state = NioSocketImpl::ST_CLOSING;
		try {
			$init($StandardSocketOptions);
			$var($SocketOption, SO_LINGER, $StandardSocketOptions::SO_LINGER);
			if ($nc(($cast($Integer, $($Net::getSocketOption(this->fd, SO_LINGER)))))->intValue() != 0) {
				$Net::shutdown(this->fd, $Net::SHUT_WR);
			}
		} catch ($IOException& ignore) {
		}
		if (!tryClose()) {
			$nc(NioSocketImpl::nd)->preClose(this->fd);
			int64_t reader = this->readerThread;
			if (reader != 0) {
				$NativeThread::signal(reader);
			}
			int64_t writer = this->writerThread;
			if (writer != 0) {
				$NativeThread::signal(writer);
			}
		}
	}
}

$Set* NioSocketImpl::supportedOptions() {
	$useLocalCurrentObjectStackCache();
	$var($Set, options, (this->server) ? $cast($Set, NioSocketImpl::serverSocketOptions) : $cast($Set, NioSocketImpl::clientSocketOptions));
	if (options == nullptr) {
		$assign(options, $new($HashSet));
		$init($StandardSocketOptions);
		options->add($StandardSocketOptions::SO_RCVBUF);
		options->add($StandardSocketOptions::SO_REUSEADDR);
		if (this->server) {
			options->add($StandardSocketOptions::IP_TOS);
			options->addAll($($ExtendedSocketOptions::serverSocketOptions()));
		} else {
			options->add($StandardSocketOptions::IP_TOS);
			options->add($StandardSocketOptions::SO_KEEPALIVE);
			options->add($StandardSocketOptions::SO_SNDBUF);
			options->add($StandardSocketOptions::SO_LINGER);
			options->add($StandardSocketOptions::TCP_NODELAY);
			options->addAll($($ExtendedSocketOptions::clientSocketOptions()));
		}
		if ($Net::isReusePortAvailable()) {
			options->add($StandardSocketOptions::SO_REUSEPORT);
		}
		$assign(options, $Collections::unmodifiableSet(options));
		if (this->server) {
			$assignStatic(NioSocketImpl::serverSocketOptions, options);
		} else {
			$assignStatic(NioSocketImpl::clientSocketOptions, options);
		}
	}
	return options;
}

void NioSocketImpl::setOption($SocketOption* opt, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($(supportedOptions()))->contains(opt)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, opt, "\' not supported"_s}));
	}
	if (!$nc($nc(opt)->type())->isInstance(value)) {
		$throwNew($IllegalArgumentException, $$str({"Invalid value \'"_s, value, "\'"_s}));
	}
	$synchronized(this->stateLock) {
		ensureOpen();
		$init($StandardSocketOptions);
		if (opt == $StandardSocketOptions::IP_TOS) {
			$Net::setSocketOption(this->fd, $(family()), opt, value);
		} else {
			if (opt == $StandardSocketOptions::SO_REUSEADDR) {
				bool b = $nc(($cast($Boolean, value)))->booleanValue();
				if ($Net::useExclusiveBind()) {
					this->isReuseAddress = b;
				} else {
					$Net::setSocketOption(this->fd, opt, $($Boolean::valueOf(b)));
				}
			} else {
				$Net::setSocketOption(this->fd, opt, value);
			}
		}
	}
}

$Object* NioSocketImpl::getOption($SocketOption* opt) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($(supportedOptions()))->contains(opt)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, opt, "\' not supported"_s}));
	}
	$synchronized(this->stateLock) {
		ensureOpen();
		$init($StandardSocketOptions);
		if (opt == $StandardSocketOptions::IP_TOS) {
			return $of($Net::getSocketOption(this->fd, $(family()), opt));
		} else {
			if (opt == $StandardSocketOptions::SO_REUSEADDR) {
				if ($Net::useExclusiveBind()) {
					return $of($of($Boolean::valueOf(this->isReuseAddress)));
				} else {
					return $of($Net::getSocketOption(this->fd, opt));
				}
			} else {
				return $of($Net::getSocketOption(this->fd, opt));
			}
		}
	}
}

bool NioSocketImpl::booleanValue(Object$* value, $String* desc) {
	if (!($instanceOf($Boolean, value))) {
		$throwNew($SocketException, $$str({"Bad value for "_s, desc}));
	}
	return $nc(($cast($Boolean, value)))->booleanValue();
}

int32_t NioSocketImpl::intValue(Object$* value, $String* desc) {
	if (!($instanceOf($Integer, value))) {
		$throwNew($SocketException, $$str({"Bad value for "_s, desc}));
	}
	return $nc(($cast($Integer, value)))->intValue();
}

void NioSocketImpl::setOption(int32_t opt, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->stateLock) {
		ensureOpen();
		try {
			switch (opt) {
			case $SocketOptions::SO_LINGER:
				{
					{
						int32_t i = 0;
						if ($instanceOf($Boolean, value) && ($nc(($cast($Boolean, value)))->booleanValue()) == false) {
							i = -1;
						} else {
							i = intValue(value, "SO_LINGER"_s);
						}
						$init($StandardSocketOptions);
						$Net::setSocketOption(this->fd, $StandardSocketOptions::SO_LINGER, $($Integer::valueOf(i)));
						break;
					}
				}
			case $SocketOptions::SO_TIMEOUT:
				{
					{
						int32_t i = intValue(value, "SO_TIMEOUT"_s);
						if (i < 0) {
							$throwNew($IllegalArgumentException, "timeout < 0"_s);
						}
						this->timeout = i;
						break;
					}
				}
			case $SocketOptions::IP_TOS:
				{
					{
						int32_t i = intValue(value, "IP_TOS"_s);
						$var($FileDescriptor, var$0, this->fd);
						$var($ProtocolFamily, var$1, family());
						$init($StandardSocketOptions);
						$var($SocketOption, var$2, $StandardSocketOptions::IP_TOS);
						$Net::setSocketOption(var$0, var$1, var$2, $($Integer::valueOf(i)));
						break;
					}
				}
			case $SocketOptions::TCP_NODELAY:
				{
					{
						bool b = booleanValue(value, "TCP_NODELAY"_s);
						$init($StandardSocketOptions);
						$Net::setSocketOption(this->fd, $StandardSocketOptions::TCP_NODELAY, $($Boolean::valueOf(b)));
						break;
					}
				}
			case $SocketOptions::SO_SNDBUF:
				{
					{
						int32_t i = intValue(value, "SO_SNDBUF"_s);
						if (i <= 0) {
							$throwNew($SocketException, "SO_SNDBUF <= 0"_s);
						}
						$init($StandardSocketOptions);
						$Net::setSocketOption(this->fd, $StandardSocketOptions::SO_SNDBUF, $($Integer::valueOf(i)));
						break;
					}
				}
			case $SocketOptions::SO_RCVBUF:
				{
					{
						int32_t i = intValue(value, "SO_RCVBUF"_s);
						if (i <= 0) {
							$throwNew($SocketException, "SO_RCVBUF <= 0"_s);
						}
						$init($StandardSocketOptions);
						$Net::setSocketOption(this->fd, $StandardSocketOptions::SO_RCVBUF, $($Integer::valueOf(i)));
						break;
					}
				}
			case $SocketOptions::SO_KEEPALIVE:
				{
					{
						bool b = booleanValue(value, "SO_KEEPALIVE"_s);
						$init($StandardSocketOptions);
						$Net::setSocketOption(this->fd, $StandardSocketOptions::SO_KEEPALIVE, $($Boolean::valueOf(b)));
						break;
					}
				}
			case $SocketOptions::SO_OOBINLINE:
				{
					{
						bool b = booleanValue(value, "SO_OOBINLINE"_s);
						$init($ExtendedSocketOption);
						$Net::setSocketOption(this->fd, $ExtendedSocketOption::SO_OOBINLINE, $($Boolean::valueOf(b)));
						break;
					}
				}
			case $SocketOptions::SO_REUSEADDR:
				{
					{
						bool b = booleanValue(value, "SO_REUSEADDR"_s);
						if ($Net::useExclusiveBind()) {
							this->isReuseAddress = b;
						} else {
							$init($StandardSocketOptions);
							$Net::setSocketOption(this->fd, $StandardSocketOptions::SO_REUSEADDR, $($Boolean::valueOf(b)));
						}
						break;
					}
				}
			case $SocketOptions::SO_REUSEPORT:
				{
					{
						if (!$Net::isReusePortAvailable()) {
							$throwNew($SocketException, "SO_REUSEPORT not supported"_s);
						}
						bool b = booleanValue(value, "SO_REUSEPORT"_s);
						$init($StandardSocketOptions);
						$Net::setSocketOption(this->fd, $StandardSocketOptions::SO_REUSEPORT, $($Boolean::valueOf(b)));
						break;
					}
				}
			default:
				{
					$throwNew($SocketException, $$str({"Unknown option "_s, $$str(opt)}));
				}
			}
		} catch ($SocketException& e) {
			$throw(e);
		} catch ($IllegalArgumentException& e) {
			$throwNew($SocketException, $(e->getMessage()));
		} catch ($IOException& e) {
			$throwNew($SocketException, $(e->getMessage()));
		}
	}
}

$Object* NioSocketImpl::getOption(int32_t opt) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->stateLock) {
		ensureOpen();
		try {
			switch (opt) {
			case $SocketOptions::SO_TIMEOUT:
				{
					return $of($Integer::valueOf(this->timeout));
				}
			case $SocketOptions::TCP_NODELAY:
				{
					$init($StandardSocketOptions);
					return $of($Net::getSocketOption(this->fd, $StandardSocketOptions::TCP_NODELAY));
				}
			case $SocketOptions::SO_OOBINLINE:
				{
					$init($ExtendedSocketOption);
					return $of($Net::getSocketOption(this->fd, $ExtendedSocketOption::SO_OOBINLINE));
				}
			case $SocketOptions::SO_LINGER:
				{
					{
						$init($StandardSocketOptions);
						int32_t i = $nc(($cast($Integer, $($Net::getSocketOption(this->fd, $StandardSocketOptions::SO_LINGER)))))->intValue();
						if (i == -1) {
							$init($Boolean);
							return $of($Boolean::FALSE);
						} else {
							return $of($Integer::valueOf(i));
						}
					}
				}
			case $SocketOptions::SO_REUSEADDR:
				{
					if ($Net::useExclusiveBind()) {
						return $of($Boolean::valueOf(this->isReuseAddress));
					} else {
						$init($StandardSocketOptions);
						return $of($Net::getSocketOption(this->fd, $StandardSocketOptions::SO_REUSEADDR));
					}
				}
			case $SocketOptions::SO_BINDADDR:
				{
					return $of($nc($($Net::localAddress(this->fd)))->getAddress());
				}
			case $SocketOptions::SO_SNDBUF:
				{
					$init($StandardSocketOptions);
					return $of($Net::getSocketOption(this->fd, $StandardSocketOptions::SO_SNDBUF));
				}
			case $SocketOptions::SO_RCVBUF:
				{
					$init($StandardSocketOptions);
					return $of($Net::getSocketOption(this->fd, $StandardSocketOptions::SO_RCVBUF));
				}
			case $SocketOptions::IP_TOS:
				{
					$init($StandardSocketOptions);
					return $of($Net::getSocketOption(this->fd, $(family()), $StandardSocketOptions::IP_TOS));
				}
			case $SocketOptions::SO_KEEPALIVE:
				{
					$init($StandardSocketOptions);
					return $of($Net::getSocketOption(this->fd, $StandardSocketOptions::SO_KEEPALIVE));
				}
			case $SocketOptions::SO_REUSEPORT:
				{
					if (!$Net::isReusePortAvailable()) {
						$throwNew($SocketException, "SO_REUSEPORT not supported"_s);
					}
					$init($StandardSocketOptions);
					return $of($Net::getSocketOption(this->fd, $StandardSocketOptions::SO_REUSEPORT));
				}
			default:
				{
					$throwNew($SocketException, $$str({"Unknown option "_s, $$str(opt)}));
				}
			}
		} catch ($SocketException& e) {
			$throw(e);
		} catch ($IllegalArgumentException& e) {
			$throwNew($SocketException, $(e->getMessage()));
		} catch ($IOException& e) {
			$throwNew($SocketException, $(e->getMessage()));
		}
	}
	$shouldNotReachHere();
}

void NioSocketImpl::shutdownInput() {
	$synchronized(this->stateLock) {
		ensureOpenAndConnected();
		if (!this->isInputClosed) {
			$Net::shutdown(this->fd, $Net::SHUT_RD);
			this->isInputClosed = true;
		}
	}
}

void NioSocketImpl::shutdownOutput() {
	$synchronized(this->stateLock) {
		ensureOpenAndConnected();
		if (!this->isOutputClosed) {
			$Net::shutdown(this->fd, $Net::SHUT_WR);
			this->isOutputClosed = true;
		}
	}
}

bool NioSocketImpl::supportsUrgentData() {
	return true;
}

void NioSocketImpl::sendUrgentData(int32_t data) {
	$useLocalCurrentObjectStackCache();
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			int32_t n = 0;
			$var($FileDescriptor, fd, beginWrite());
			{
				$var($Throwable, var$1, nullptr);
				try {
					do {
						n = $Net::sendOOB(fd, (int8_t)data);
					} while (n == $IOStatus::INTERRUPTED && isOpen());
					if (n == $IOStatus::UNAVAILABLE) {
						$throwNew($SocketException, "No buffer space available"_s);
					}
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					endWrite(n > 0);
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->writeLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Runnable* NioSocketImpl::closerFor($FileDescriptor* fd, bool stream) {
	$init(NioSocketImpl);
	if (stream) {
		return static_cast<$Runnable*>($new(NioSocketImpl$$Lambda$lambda$closerFor$0, fd));
	} else {
		return static_cast<$Runnable*>($new(NioSocketImpl$$Lambda$lambda$closerFor$1$1, fd));
	}
}

int64_t NioSocketImpl::tryLock($ReentrantLock* lock, int64_t timeout, $TimeUnit* unit) {
	$init(NioSocketImpl);
	if (!NioSocketImpl::$assertionsDisabled && !(timeout > 0)) {
		$throwNew($AssertionError);
	}
	bool interrupted = false;
	$init($TimeUnit);
	int64_t nanos = $TimeUnit::NANOSECONDS->convert(timeout, unit);
	int64_t remainingNanos = nanos;
	int64_t startNanos = $System::nanoTime();
	bool acquired = false;
	while (!acquired && (remainingNanos > 0)) {
		try {
			acquired = $nc(lock)->tryLock(remainingNanos, $TimeUnit::NANOSECONDS);
		} catch ($InterruptedException& e) {
			interrupted = true;
		}
		remainingNanos = nanos - ($System::nanoTime() - startNanos);
	}
	if (acquired && remainingNanos <= (int64_t)0) {
		$nc(lock)->unlock();
	}
	if (interrupted) {
		$($Thread::currentThread())->interrupt();
	}
	return remainingNanos;
}

$ProtocolFamily* NioSocketImpl::family() {
	$init(NioSocketImpl);
	if ($Net::isIPv6Available()) {
		$init($StandardProtocolFamily);
		return $StandardProtocolFamily::INET6;
	} else {
		$init($StandardProtocolFamily);
		return $StandardProtocolFamily::INET;
	}
}

void NioSocketImpl::lambda$closerFor$1($FileDescriptor* fd) {
	$init(NioSocketImpl);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(NioSocketImpl::nd)->close(fd);
			} catch ($IOException& ioe) {
				$throwNew($UncheckedIOException, ioe);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$ResourceManager::afterUdpClose();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void NioSocketImpl::lambda$closerFor$0($FileDescriptor* fd) {
	$init(NioSocketImpl);
	try {
		$nc(NioSocketImpl::nd)->close(fd);
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
}

void clinit$NioSocketImpl($Class* class$) {
	NioSocketImpl::$assertionsDisabled = !NioSocketImpl::class$->desiredAssertionStatus();
	$assignStatic(NioSocketImpl::nd, $new($SocketDispatcher));
}

NioSocketImpl::NioSocketImpl() {
}

$Class* NioSocketImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(NioSocketImpl$$Lambda$lambda$closerFor$0::classInfo$.name)) {
			return NioSocketImpl$$Lambda$lambda$closerFor$0::load$(name, initialize);
		}
		if (name->equals(NioSocketImpl$$Lambda$lambda$closerFor$1$1::classInfo$.name)) {
			return NioSocketImpl$$Lambda$lambda$closerFor$1$1::load$(name, initialize);
		}
	}
	$loadClass(NioSocketImpl, name, initialize, &_NioSocketImpl_ClassInfo_, clinit$NioSocketImpl, allocate$NioSocketImpl);
	return class$;
}

$Class* NioSocketImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun