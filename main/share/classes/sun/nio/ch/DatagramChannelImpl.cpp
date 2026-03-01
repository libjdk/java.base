#include <sun/nio/ch/DatagramChannelImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/net/DatagramSocket.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/NetworkInterface.h>
#include <java/net/PortUnreachableException.h>
#include <java/net/ProtocolFamily.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketOption.h>
#include <java/net/SocketTimeoutException.h>
#include <java/net/StandardProtocolFamily.h>
#include <java/net/StandardSocketOptions.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AlreadyBoundException.h>
#include <java/nio/channels/AlreadyConnectedException.h>
#include <java/nio/channels/AsynchronousCloseException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/IllegalBlockingModeException.h>
#include <java/nio/channels/MembershipKey.h>
#include <java/nio/channels/MulticastChannel.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/nio/channels/NotYetConnectedException.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <sun/net/ResourceManager.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/nio/ch/DatagramChannelImpl$AbstractSelectableChannels.h>
#include <sun/nio/ch/DatagramChannelImpl$DefaultOptionsHolder.h>
#include <sun/nio/ch/DatagramDispatcher.h>
#include <sun/nio/ch/DatagramSocketAdaptor.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/MembershipKeyImpl$Type4.h>
#include <sun/nio/ch/MembershipKeyImpl$Type6.h>
#include <sun/nio/ch/MembershipKeyImpl.h>
#include <sun/nio/ch/MembershipRegistry$ThrowingConsumer.h>
#include <sun/nio/ch/MembershipRegistry.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/NativeSocketAddress.h>
#include <sun/nio/ch/NativeThread.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/OptionKey.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <sun/nio/ch/SocketOptionRegistry.h>
#include <sun/nio/ch/Util.h>
#include <jcpp.h>

#undef INET
#undef INET6
#undef IP_MULTICAST_IF
#undef OP_CONNECT
#undef OP_READ
#undef OP_WRITE
#undef POLLERR
#undef POLLHUP
#undef POLLIN
#undef POLLNVAL
#undef POLLOUT
#undef SOCKET
#undef SO_REUSEADDR
#undef ST_CLOSED
#undef ST_CLOSING
#undef ST_CONNECTED
#undef ST_UNCONNECTED
#undef UNAVAILABLE
#undef UNSPEC

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $NativeSocketAddressArray = $Array<::sun::nio::ch::NativeSocketAddress>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Cleaner = ::java::lang::ref::Cleaner;
using $Cleaner$Cleanable = ::java::lang::ref::Cleaner$Cleanable;
using $DatagramSocket = ::java::net::DatagramSocket;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $NetworkInterface = ::java::net::NetworkInterface;
using $PortUnreachableException = ::java::net::PortUnreachableException;
using $ProtocolFamily = ::java::net::ProtocolFamily;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketOption = ::java::net::SocketOption;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $StandardProtocolFamily = ::java::net::StandardProtocolFamily;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlreadyBoundException = ::java::nio::channels::AlreadyBoundException;
using $AlreadyConnectedException = ::java::nio::channels::AlreadyConnectedException;
using $AsynchronousCloseException = ::java::nio::channels::AsynchronousCloseException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $IllegalBlockingModeException = ::java::nio::channels::IllegalBlockingModeException;
using $MembershipKey = ::java::nio::channels::MembershipKey;
using $MulticastChannel = ::java::nio::channels::MulticastChannel;
using $NetworkChannel = ::java::nio::channels::NetworkChannel;
using $NotYetConnectedException = ::java::nio::channels::NotYetConnectedException;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $Consumer = ::java::util::function::Consumer;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;
using $ResourceManager = ::sun::net::ResourceManager;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $DatagramChannelImpl$AbstractSelectableChannels = ::sun::nio::ch::DatagramChannelImpl$AbstractSelectableChannels;
using $DatagramChannelImpl$DefaultOptionsHolder = ::sun::nio::ch::DatagramChannelImpl$DefaultOptionsHolder;
using $DatagramDispatcher = ::sun::nio::ch::DatagramDispatcher;
using $DatagramSocketAdaptor = ::sun::nio::ch::DatagramSocketAdaptor;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $MembershipKeyImpl = ::sun::nio::ch::MembershipKeyImpl;
using $MembershipKeyImpl$Type4 = ::sun::nio::ch::MembershipKeyImpl$Type4;
using $MembershipKeyImpl$Type6 = ::sun::nio::ch::MembershipKeyImpl$Type6;
using $MembershipRegistry = ::sun::nio::ch::MembershipRegistry;
using $MembershipRegistry$ThrowingConsumer = ::sun::nio::ch::MembershipRegistry$ThrowingConsumer;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $NativeSocketAddress = ::sun::nio::ch::NativeSocketAddress;
using $NativeThread = ::sun::nio::ch::NativeThread;
using $Net = ::sun::nio::ch::Net;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;
using $SocketOptionRegistry = ::sun::nio::ch::SocketOptionRegistry;
using $Util = ::sun::nio::ch::Util;

namespace sun {
	namespace nio {
		namespace ch {

class DatagramChannelImpl$$Lambda$lambda$repairSocket$0 : public $MembershipRegistry$ThrowingConsumer {
	$class(DatagramChannelImpl$$Lambda$lambda$repairSocket$0, $NO_CLASS_INIT, $MembershipRegistry$ThrowingConsumer)
public:
	void init$(DatagramChannelImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* k) override {
		$nc(inst$)->lambda$repairSocket$0($cast($MembershipKeyImpl, k));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DatagramChannelImpl$$Lambda$lambda$repairSocket$0>());
	}
	DatagramChannelImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DatagramChannelImpl$$Lambda$lambda$repairSocket$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DatagramChannelImpl$$Lambda$lambda$repairSocket$0, inst$)},
	{}
};
$MethodInfo DatagramChannelImpl$$Lambda$lambda$repairSocket$0::methodInfos[3] = {
	{"<init>", "(Lsun/nio/ch/DatagramChannelImpl;)V", nullptr, $PUBLIC, $method(DatagramChannelImpl$$Lambda$lambda$repairSocket$0, init$, void, DatagramChannelImpl*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl$$Lambda$lambda$repairSocket$0, accept, void, Object$*)},
	{}
};
$ClassInfo DatagramChannelImpl$$Lambda$lambda$repairSocket$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.DatagramChannelImpl$$Lambda$lambda$repairSocket$0",
	"java.lang.Object",
	"sun.nio.ch.MembershipRegistry$ThrowingConsumer",
	fieldInfos,
	methodInfos
};
$Class* DatagramChannelImpl$$Lambda$lambda$repairSocket$0::load$($String* name, bool initialize) {
	$loadClass(DatagramChannelImpl$$Lambda$lambda$repairSocket$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DatagramChannelImpl$$Lambda$lambda$repairSocket$0::class$ = nullptr;

class DatagramChannelImpl$$Lambda$reset$1 : public $Consumer {
	$class(DatagramChannelImpl$$Lambda$reset$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$) override {
		$sure($SelectionKeyImpl, inst$)->reset();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DatagramChannelImpl$$Lambda$reset$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DatagramChannelImpl$$Lambda$reset$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DatagramChannelImpl$$Lambda$reset$1, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl$$Lambda$reset$1, accept, void, Object$*)},
	{}
};
$ClassInfo DatagramChannelImpl$$Lambda$reset$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.DatagramChannelImpl$$Lambda$reset$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* DatagramChannelImpl$$Lambda$reset$1::load$($String* name, bool initialize) {
	$loadClass(DatagramChannelImpl$$Lambda$reset$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DatagramChannelImpl$$Lambda$reset$1::class$ = nullptr;

class DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2 : public $Runnable {
	$class(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$($FileDescriptor* fd, $NativeSocketAddressArray* sockAddrs) {
		$set(this, fd, fd);
		$set(this, sockAddrs, sockAddrs);
	}
	virtual void run() override {
		DatagramChannelImpl::lambda$releaserFor$1(fd, sockAddrs);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2>());
	}
	$FileDescriptor* fd = nullptr;
	$NativeSocketAddressArray* sockAddrs = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::fieldInfos[3] = {
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PUBLIC, $field(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, fd)},
	{"sockAddrs", "[Lsun/nio/ch/NativeSocketAddress;", nullptr, $PUBLIC, $field(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, sockAddrs)},
	{}
};
$MethodInfo DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/io/FileDescriptor;[Lsun/nio/ch/NativeSocketAddress;)V", nullptr, $PUBLIC, $method(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, init$, void, $FileDescriptor*, $NativeSocketAddressArray*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, run, void)},
	{}
};
$ClassInfo DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::load$($String* name, bool initialize) {
	$loadClass(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::class$ = nullptr;

$FieldInfo _DatagramChannelImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(DatagramChannelImpl, $assertionsDisabled)},
	{"nd", "Lsun/nio/ch/NativeDispatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DatagramChannelImpl, nd)},
	{"interruptible", "Z", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, interruptible)},
	{"family", "Ljava/net/ProtocolFamily;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, family)},
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, fd)},
	{"fdVal", "I", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, fdVal)},
	{"sourceSockAddr", "Lsun/nio/ch/NativeSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, sourceSockAddr)},
	{"cachedSockAddr", "Lsun/nio/ch/NativeSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, cachedSockAddr)},
	{"cachedInetSocketAddress", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, cachedInetSocketAddress)},
	{"targetSockAddr", "Lsun/nio/ch/NativeSocketAddress;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, targetSockAddr)},
	{"previousTarget", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, previousTarget)},
	{"previousSockAddrLength", "I", nullptr, $PRIVATE, $field(DatagramChannelImpl, previousSockAddrLength)},
	{"cleaner", "Ljava/lang/ref/Cleaner$Cleanable;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, cleaner)},
	{"readLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, readLock)},
	{"writeLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, writeLock)},
	{"stateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(DatagramChannelImpl, stateLock)},
	{"ST_UNCONNECTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DatagramChannelImpl, ST_UNCONNECTED)},
	{"ST_CONNECTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DatagramChannelImpl, ST_CONNECTED)},
	{"ST_CLOSING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DatagramChannelImpl, ST_CLOSING)},
	{"ST_CLOSED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DatagramChannelImpl, ST_CLOSED)},
	{"state", "I", nullptr, $PRIVATE, $field(DatagramChannelImpl, state)},
	{"readerThread", "J", nullptr, $PRIVATE, $field(DatagramChannelImpl, readerThread)},
	{"writerThread", "J", nullptr, $PRIVATE, $field(DatagramChannelImpl, writerThread)},
	{"localAddress", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, localAddress$)},
	{"remoteAddress", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, remoteAddress$)},
	{"initialLocalAddress", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(DatagramChannelImpl, initialLocalAddress)},
	{"SOCKET", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DatagramChannelImpl, SOCKET)},
	{"socket", "Ljava/net/DatagramSocket;", nullptr, $PRIVATE | $VOLATILE, $field(DatagramChannelImpl, socket$)},
	{"registry", "Lsun/nio/ch/MembershipRegistry;", nullptr, $PRIVATE, $field(DatagramChannelImpl, registry)},
	{"reuseAddressEmulated", "Z", nullptr, $PRIVATE, $field(DatagramChannelImpl, reuseAddressEmulated)},
	{"isReuseAddress", "Z", nullptr, $PRIVATE, $field(DatagramChannelImpl, isReuseAddress)},
	{}
};

$MethodInfo _DatagramChannelImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;Z)V", nullptr, 0, $method(DatagramChannelImpl, init$, void, $SelectorProvider*, bool), "java.io.IOException"},
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;Ljava/net/ProtocolFamily;Z)V", nullptr, 0, $method(DatagramChannelImpl, init$, void, $SelectorProvider*, $ProtocolFamily*, bool), "java.io.IOException"},
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;Ljava/io/FileDescriptor;)V", nullptr, 0, $method(DatagramChannelImpl, init$, void, $SelectorProvider*, $FileDescriptor*), "java.io.IOException"},
	{"beginRead", "(ZZ)Ljava/net/SocketAddress;", nullptr, $PRIVATE, $method(DatagramChannelImpl, beginRead, $SocketAddress*, bool, bool), "java.io.IOException"},
	{"beginWrite", "(ZZ)Ljava/net/SocketAddress;", nullptr, $PRIVATE, $method(DatagramChannelImpl, beginWrite, $SocketAddress*, bool, bool), "java.io.IOException"},
	{"bind", "(Ljava/net/SocketAddress;)Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, bind, $NetworkChannel*, $SocketAddress*), "java.io.IOException"},
	{"bindInternal", "(Ljava/net/SocketAddress;)V", nullptr, $PRIVATE, $method(DatagramChannelImpl, bindInternal, void, $SocketAddress*), "java.io.IOException"},
	{"block", "(Lsun/nio/ch/MembershipKeyImpl;Ljava/net/InetAddress;)V", nullptr, 0, $virtualMethod(DatagramChannelImpl, block, void, $MembershipKeyImpl*, $InetAddress*), "java.io.IOException"},
	{"blockingReceive", "(Ljava/nio/ByteBuffer;J)Ljava/net/SocketAddress;", nullptr, 0, $virtualMethod(DatagramChannelImpl, blockingReceive, $SocketAddress*, $ByteBuffer*, int64_t), "java.io.IOException"},
	{"blockingSend", "(Ljava/nio/ByteBuffer;Ljava/net/SocketAddress;)V", nullptr, 0, $virtualMethod(DatagramChannelImpl, blockingSend, void, $ByteBuffer*, $SocketAddress*), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;)Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, connect, $DatagramChannel*, $SocketAddress*), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;Z)Ljava/nio/channels/DatagramChannel;", nullptr, 0, $virtualMethod(DatagramChannelImpl, connect, $DatagramChannel*, $SocketAddress*, bool), "java.io.IOException"},
	{"disconnect", "()Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, disconnect, $DatagramChannel*), "java.io.IOException"},
	{"disconnect0", "(Ljava/io/FileDescriptor;Z)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(DatagramChannelImpl, disconnect0, void, $FileDescriptor*, bool), "java.io.IOException"},
	{"drop", "(Lsun/nio/ch/MembershipKeyImpl;)V", nullptr, 0, $virtualMethod(DatagramChannelImpl, drop, void, $MembershipKeyImpl*)},
	{"endRead", "(ZZ)V", nullptr, $PRIVATE, $method(DatagramChannelImpl, endRead, void, bool, bool), "java.nio.channels.AsynchronousCloseException"},
	{"endWrite", "(ZZ)V", nullptr, $PRIVATE, $method(DatagramChannelImpl, endWrite, void, bool, bool), "java.nio.channels.AsynchronousCloseException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(DatagramChannelImpl, ensureOpen, void), "java.nio.channels.ClosedChannelException"},
	{"familyFor", "(Ljava/net/SocketOption;)Ljava/net/ProtocolFamily;", "(Ljava/net/SocketOption<*>;)Ljava/net/ProtocolFamily;", $PRIVATE, $method(DatagramChannelImpl, familyFor, $ProtocolFamily*, $SocketOption*)},
	{"findMembership", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;)Ljava/nio/channels/MembershipKey;", nullptr, 0, $virtualMethod(DatagramChannelImpl, findMembership, $MembershipKey*, $InetAddress*, $NetworkInterface*)},
	{"getFD", "()Ljava/io/FileDescriptor;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, getFD, $FileDescriptor*)},
	{"getFDVal", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, getFDVal, int32_t)},
	{"getLocalAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, getLocalAddress, $SocketAddress*), "java.io.IOException"},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PUBLIC, $virtualMethod(DatagramChannelImpl, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getRemoteAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, getRemoteAddress, $SocketAddress*), "java.io.IOException"},
	{"implCloseBlockingMode", "()V", nullptr, $PRIVATE, $method(DatagramChannelImpl, implCloseBlockingMode, void), "java.io.IOException"},
	{"implCloseNonBlockingMode", "()V", nullptr, $PRIVATE, $method(DatagramChannelImpl, implCloseNonBlockingMode, void), "java.io.IOException"},
	{"implCloseSelectableChannel", "()V", nullptr, $PROTECTED, $virtualMethod(DatagramChannelImpl, implCloseSelectableChannel, void), "java.io.IOException"},
	{"implConfigureBlocking", "(Z)V", nullptr, $PROTECTED, $virtualMethod(DatagramChannelImpl, implConfigureBlocking, void, bool), "java.io.IOException"},
	{"innerJoin", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;Ljava/net/InetAddress;)Ljava/nio/channels/MembershipKey;", nullptr, $PRIVATE, $method(DatagramChannelImpl, innerJoin, $MembershipKey*, $InetAddress*, $NetworkInterface*, $InetAddress*), "java.io.IOException"},
	{"isConnected", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, isConnected, bool)},
	{"*isOpen", "()Z", nullptr, $PUBLIC | $FINAL},
	{"join", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;)Ljava/nio/channels/MembershipKey;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, join, $MembershipKey*, $InetAddress*, $NetworkInterface*), "java.io.IOException"},
	{"join", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;Ljava/net/InetAddress;)Ljava/nio/channels/MembershipKey;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, join, $MembershipKey*, $InetAddress*, $NetworkInterface*, $InetAddress*), "java.io.IOException"},
	{"kill", "()V", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, kill, void)},
	{"lambda$releaserFor$1", "(Ljava/io/FileDescriptor;[Lsun/nio/ch/NativeSocketAddress;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DatagramChannelImpl, lambda$releaserFor$1, void, $FileDescriptor*, $NativeSocketAddressArray*)},
	{"lambda$repairSocket$0", "(Lsun/nio/ch/MembershipKeyImpl;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(DatagramChannelImpl, lambda$repairSocket$0, void, $MembershipKeyImpl*), "java.io.IOException"},
	{"localAddress", "()Ljava/net/InetSocketAddress;", nullptr, 0, $virtualMethod(DatagramChannelImpl, localAddress, $InetSocketAddress*)},
	{"lockedConfigureBlocking", "(Z)V", nullptr, $PRIVATE, $method(DatagramChannelImpl, lockedConfigureBlocking, void, bool), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, read, int32_t, $ByteBuffer*), "java.io.IOException"},
	{"read", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, read, int64_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"receive", "(Ljava/nio/ByteBuffer;)Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, receive, $SocketAddress*, $ByteBuffer*), "java.io.IOException"},
	{"receive", "(Ljava/nio/ByteBuffer;Z)I", nullptr, $PRIVATE, $method(DatagramChannelImpl, receive, int32_t, $ByteBuffer*, bool), "java.io.IOException"},
	{"receive0", "(Ljava/io/FileDescriptor;JIJZ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(DatagramChannelImpl, receive0, int32_t, $FileDescriptor*, int64_t, int32_t, int64_t, bool), "java.io.IOException"},
	{"receiveIntoNativeBuffer", "(Ljava/nio/ByteBuffer;IIZ)I", nullptr, $PRIVATE, $method(DatagramChannelImpl, receiveIntoNativeBuffer, int32_t, $ByteBuffer*, int32_t, int32_t, bool), "java.io.IOException"},
	{"releaserFor", "(Ljava/io/FileDescriptor;[Lsun/nio/ch/NativeSocketAddress;)Ljava/lang/Runnable;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(DatagramChannelImpl, releaserFor, $Runnable*, $FileDescriptor*, $NativeSocketAddressArray*)},
	{"remoteAddress", "()Ljava/net/InetSocketAddress;", nullptr, 0, $virtualMethod(DatagramChannelImpl, remoteAddress, $InetSocketAddress*)},
	{"repairSocket", "(Ljava/net/InetSocketAddress;)V", nullptr, $PRIVATE, $method(DatagramChannelImpl, repairSocket, void, $InetSocketAddress*), "java.io.IOException"},
	{"send", "(Ljava/nio/ByteBuffer;Ljava/net/SocketAddress;)I", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, send, int32_t, $ByteBuffer*, $SocketAddress*), "java.io.IOException"},
	{"send", "(Ljava/io/FileDescriptor;Ljava/nio/ByteBuffer;Ljava/net/InetSocketAddress;)I", nullptr, $PRIVATE, $method(DatagramChannelImpl, send, int32_t, $FileDescriptor*, $ByteBuffer*, $InetSocketAddress*), "java.io.IOException"},
	{"send0", "(Ljava/io/FileDescriptor;JIJI)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(DatagramChannelImpl, send0, int32_t, $FileDescriptor*, int64_t, int32_t, int64_t, int32_t), "java.io.IOException"},
	{"sendFromNativeBuffer", "(Ljava/io/FileDescriptor;Ljava/nio/ByteBuffer;Ljava/net/InetSocketAddress;)I", nullptr, $PRIVATE, $method(DatagramChannelImpl, sendFromNativeBuffer, int32_t, $FileDescriptor*, $ByteBuffer*, $InetSocketAddress*), "java.io.IOException"},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)Ljava/nio/channels/DatagramChannel;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)Ljava/nio/channels/DatagramChannel;", $PUBLIC, $virtualMethod(DatagramChannelImpl, setOption, $NetworkChannel*, $SocketOption*, Object$*), "java.io.IOException"},
	{"socket", "()Ljava/net/DatagramSocket;", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, socket, $DatagramSocket*)},
	{"sourceSocketAddress", "()Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $method(DatagramChannelImpl, sourceSocketAddress, $InetSocketAddress*), "java.io.IOException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PUBLIC | $FINAL, $virtualMethod(DatagramChannelImpl, supportedOptions, $Set*)},
	{"targetSocketAddress", "(Ljava/net/InetSocketAddress;)I", nullptr, $PRIVATE, $method(DatagramChannelImpl, targetSocketAddress, int32_t, $InetSocketAddress*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"translateAndSetReadyOps", "(ILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, translateAndSetReadyOps, bool, int32_t, $SelectionKeyImpl*)},
	{"translateAndUpdateReadyOps", "(ILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, translateAndUpdateReadyOps, bool, int32_t, $SelectionKeyImpl*)},
	{"translateInterestOps", "(I)I", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, translateInterestOps, int32_t, int32_t)},
	{"translateReadyOps", "(IILsun/nio/ch/SelectionKeyImpl;)Z", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, translateReadyOps, bool, int32_t, int32_t, $SelectionKeyImpl*)},
	{"trustedBlockingReceive", "(Ljava/nio/ByteBuffer;)Ljava/net/SocketAddress;", nullptr, $PRIVATE, $method(DatagramChannelImpl, trustedBlockingReceive, $SocketAddress*, $ByteBuffer*), "java.io.IOException"},
	{"trustedBlockingReceive", "(Ljava/nio/ByteBuffer;J)Ljava/net/SocketAddress;", nullptr, $PRIVATE, $method(DatagramChannelImpl, trustedBlockingReceive, $SocketAddress*, $ByteBuffer*, int64_t), "java.io.IOException"},
	{"tryClose", "()Z", nullptr, $PRIVATE, $method(DatagramChannelImpl, tryClose, bool), "java.io.IOException"},
	{"tryFinishClose", "()V", nullptr, $PRIVATE, $method(DatagramChannelImpl, tryFinishClose, void)},
	{"tryLockedConfigureBlocking", "(Z)Z", nullptr, $PRIVATE, $method(DatagramChannelImpl, tryLockedConfigureBlocking, bool, bool), "java.io.IOException"},
	{"unblock", "(Lsun/nio/ch/MembershipKeyImpl;Ljava/net/InetAddress;)V", nullptr, 0, $virtualMethod(DatagramChannelImpl, unblock, void, $MembershipKeyImpl*, $InetAddress*)},
	{"untrustedReceive", "(Ljava/nio/ByteBuffer;)Ljava/net/SocketAddress;", nullptr, $PRIVATE, $method(DatagramChannelImpl, untrustedReceive, $SocketAddress*, $ByteBuffer*), "java.io.IOException"},
	{"write", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, write, int32_t, $ByteBuffer*), "java.io.IOException"},
	{"write", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, $virtualMethod(DatagramChannelImpl, write, int64_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_disconnect0 18
#define _METHOD_INDEX_receive0 48
#define _METHOD_INDEX_send0 55

$InnerClassInfo _DatagramChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.DatagramChannelImpl$AbstractSelectableChannels", "sun.nio.ch.DatagramChannelImpl", "AbstractSelectableChannels", $PRIVATE | $STATIC},
	{"sun.nio.ch.DatagramChannelImpl$DefaultOptionsHolder", "sun.nio.ch.DatagramChannelImpl", "DefaultOptionsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DatagramChannelImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.DatagramChannelImpl",
	"java.nio.channels.DatagramChannel",
	"sun.nio.ch.SelChImpl",
	_DatagramChannelImpl_FieldInfo_,
	_DatagramChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_DatagramChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.DatagramChannelImpl$AbstractSelectableChannels,sun.nio.ch.DatagramChannelImpl$DefaultOptionsHolder"
};

$Object* allocate$DatagramChannelImpl($Class* clazz) {
	return $of($alloc(DatagramChannelImpl));
}

void DatagramChannelImpl::close() {
	this->$DatagramChannel::close();
}

bool DatagramChannelImpl::isOpen() {
	 return this->$DatagramChannel::isOpen();
}

int32_t DatagramChannelImpl::hashCode() {
	 return this->$DatagramChannel::hashCode();
}

bool DatagramChannelImpl::equals(Object$* obj) {
	 return this->$DatagramChannel::equals(obj);
}

$Object* DatagramChannelImpl::clone() {
	 return this->$DatagramChannel::clone();
}

$String* DatagramChannelImpl::toString() {
	 return this->$DatagramChannel::toString();
}

void DatagramChannelImpl::finalize() {
	this->$DatagramChannel::finalize();
}

bool DatagramChannelImpl::$assertionsDisabled = false;
$NativeDispatcher* DatagramChannelImpl::nd = nullptr;
$VarHandle* DatagramChannelImpl::SOCKET = nullptr;

void DatagramChannelImpl::init$($SelectorProvider* sp, bool interruptible) {
	$init($StandardProtocolFamily);
	DatagramChannelImpl::init$(sp, ($Net::isIPv6Available() ? static_cast<$ProtocolFamily*>($StandardProtocolFamily::INET6) : static_cast<$ProtocolFamily*>($StandardProtocolFamily::INET)), interruptible);
}

void DatagramChannelImpl::init$($SelectorProvider* sp, $ProtocolFamily* family, bool interruptible) {
	$useLocalCurrentObjectStackCache();
	$DatagramChannel::init$(sp);
	$set(this, readLock, $new($ReentrantLock));
	$set(this, writeLock, $new($ReentrantLock));
	$set(this, stateLock, $new($Object));
	$Objects::requireNonNull($of(family), "\'family\' is null"_s);
	$init($StandardProtocolFamily);
	if ((!$equals(family, $StandardProtocolFamily::INET)) && (!$equals(family, $StandardProtocolFamily::INET6))) {
		$throwNew($UnsupportedOperationException, "Protocol family not supported"_s);
	}
	if ($equals(family, $StandardProtocolFamily::INET6) && !$Net::isIPv6Available()) {
		$throwNew($UnsupportedOperationException, "IPv6 not available"_s);
	}
	$var($FileDescriptor, fd, nullptr);
	$var($NativeSocketAddressArray, sockAddrs, nullptr);
	$ResourceManager::beforeUdpCreate();
	bool initialized = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			this->interruptible = interruptible;
			$set(this, family, family);
			$set(this, fd, ($assign(fd, $Net::socket(family, false))));
			this->fdVal = $IOUtil::fdVal(fd);
			$assign(sockAddrs, $NativeSocketAddress::allocate(3));
			$nc(this->readLock)->lock();
			{
				$var($Throwable, var$1, nullptr);
				try {
					$set(this, sourceSockAddr, $nc(sockAddrs)->get(0));
					$set(this, cachedSockAddr, sockAddrs->get(1));
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					$nc(this->readLock)->unlock();
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
			$set(this, targetSockAddr, $nc(sockAddrs)->get(2));
			initialized = true;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			if (!initialized) {
				if (sockAddrs != nullptr) {
					$NativeSocketAddress::freeAll(sockAddrs);
				}
				if (fd != nullptr) {
					$nc(DatagramChannelImpl::nd)->close(fd);
				}
				$ResourceManager::afterUdpClose();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($Runnable, releaser, releaserFor(fd, sockAddrs));
	$set(this, cleaner, $nc($($CleanerFactory::cleaner()))->register$(this, releaser));
}

void DatagramChannelImpl::init$($SelectorProvider* sp, $FileDescriptor* fd) {
	$useLocalCurrentObjectStackCache();
	$DatagramChannel::init$(sp);
	$set(this, readLock, $new($ReentrantLock));
	$set(this, writeLock, $new($ReentrantLock));
	$set(this, stateLock, $new($Object));
	$var($NativeSocketAddressArray, sockAddrs, nullptr);
	$ResourceManager::beforeUdpCreate();
	bool initialized = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			this->interruptible = true;
			$init($StandardProtocolFamily);
			$set(this, family, $Net::isIPv6Available() ? static_cast<$ProtocolFamily*>($StandardProtocolFamily::INET6) : static_cast<$ProtocolFamily*>($StandardProtocolFamily::INET));
			$set(this, fd, fd);
			this->fdVal = $IOUtil::fdVal(fd);
			$assign(sockAddrs, $NativeSocketAddress::allocate(3));
			$nc(this->readLock)->lock();
			{
				$var($Throwable, var$1, nullptr);
				try {
					$set(this, sourceSockAddr, $nc(sockAddrs)->get(0));
					$set(this, cachedSockAddr, sockAddrs->get(1));
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					$nc(this->readLock)->unlock();
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
			$set(this, targetSockAddr, $nc(sockAddrs)->get(2));
			initialized = true;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			if (!initialized) {
				if (sockAddrs != nullptr) {
					$NativeSocketAddress::freeAll(sockAddrs);
				}
				$nc(DatagramChannelImpl::nd)->close(fd);
				$ResourceManager::afterUdpClose();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($Runnable, releaser, releaserFor(fd, sockAddrs));
	$set(this, cleaner, $nc($($CleanerFactory::cleaner()))->register$(this, releaser));
	$synchronized(this->stateLock) {
		$set(this, localAddress$, $Net::localAddress(fd));
	}
}

void DatagramChannelImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedChannelException);
	}
}

$DatagramSocket* DatagramChannelImpl::socket() {
	$useLocalCurrentObjectStackCache();
	$var($DatagramSocket, socket, this->socket$);
	if (socket == nullptr) {
		$assign(socket, $DatagramSocketAdaptor::create(this));
		if (!$nc(DatagramChannelImpl::SOCKET)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(socket)}))) {
			$assign(socket, this->socket$);
		}
	}
	return socket;
}

$SocketAddress* DatagramChannelImpl::getLocalAddress() {
	$synchronized(this->stateLock) {
		ensureOpen();
		return $Net::getRevealedLocalAddress(this->localAddress$);
	}
}

$SocketAddress* DatagramChannelImpl::getRemoteAddress() {
	$synchronized(this->stateLock) {
		ensureOpen();
		return this->remoteAddress$;
	}
}

$ProtocolFamily* DatagramChannelImpl::familyFor($SocketOption* name) {
	if (!DatagramChannelImpl::$assertionsDisabled && !$Thread::holdsLock(this->stateLock)) {
		$throwNew($AssertionError);
	}
	$init($Net);
	if ($SocketOptionRegistry::findOption(name, $Net::UNSPEC) != nullptr) {
		return $Net::UNSPEC;
	}
	$init($StandardProtocolFamily);
	if ($equals(this->family, $StandardProtocolFamily::INET)) {
		return $StandardProtocolFamily::INET;
	}
	if (this->localAddress$ == nullptr) {
		return $StandardProtocolFamily::INET6;
	}
	$var($InetAddress, address, $nc(this->localAddress$)->getAddress());
	if ($nc(address)->isAnyLocalAddress() || ($instanceOf($Inet6Address, address))) {
		return $StandardProtocolFamily::INET6;
	}
	if ($Net::canUseIPv6OptionsWithIPv4LocalAddress()) {
		return $StandardProtocolFamily::INET6;
	} else {
		return $StandardProtocolFamily::INET;
	}
}

$NetworkChannel* DatagramChannelImpl::setOption($SocketOption* name, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	if (!$nc(name->type())->isInstance(value)) {
		$throwNew($IllegalArgumentException, $$str({"Invalid value \'"_s, value, "\'"_s}));
	}
	$synchronized(this->stateLock) {
		ensureOpen();
		$var($ProtocolFamily, family, familyFor(name));
		$init($Net);
		$init($StandardProtocolFamily);
		bool needToSetIPv4Option = (family != $Net::UNSPEC) && ($equals(this->family, $StandardProtocolFamily::INET6)) && $Net::shouldSetBothIPv4AndIPv6Options();
		$init($StandardSocketOptions);
		if (name == $StandardSocketOptions::IP_MULTICAST_IF) {
			if (!DatagramChannelImpl::$assertionsDisabled && !(family != $Net::UNSPEC)) {
				$throwNew($AssertionError);
			}
			$var($NetworkInterface, interf, $cast($NetworkInterface, value));
			if ($equals(family, $StandardProtocolFamily::INET6)) {
				int32_t index = $nc(interf)->getIndex();
				if (index == -1) {
					$throwNew($IOException, "Network interface cannot be identified"_s);
				}
				$Net::setInterface6(this->fd, index);
			}
			if ($equals(family, $StandardProtocolFamily::INET) || needToSetIPv4Option) {
				$var($Inet4Address, target, $Net::anyInet4Address(interf));
				if (target != nullptr) {
					try {
						$Net::setInterface4(this->fd, $Net::inet4AsInt(target));
					} catch ($IOException& ioe) {
						if ($equals(family, $StandardProtocolFamily::INET)) {
							$throw(ioe);
						}
					}
				} else {
					if ($equals(family, $StandardProtocolFamily::INET)) {
						$throwNew($IOException, "Network interface not configured for IPv4"_s);
					}
				}
			}
			return this;
		}
		if (name == $StandardSocketOptions::SO_REUSEADDR && $Net::useExclusiveBind() && this->localAddress$ != nullptr) {
			this->reuseAddressEmulated = true;
			this->isReuseAddress = $nc(($cast($Boolean, value)))->booleanValue();
		}
		$Net::setSocketOption(this->fd, family, name, value);
		if (needToSetIPv4Option && !$equals(family, $StandardProtocolFamily::INET)) {
			try {
				$Net::setSocketOption(this->fd, $StandardProtocolFamily::INET, name, value);
			} catch ($IOException& ignore) {
			}
		}
		return this;
	}
}

$Object* DatagramChannelImpl::getOption($SocketOption* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	$synchronized(this->stateLock) {
		ensureOpen();
		$var($ProtocolFamily, family, familyFor(name));
		$init($StandardSocketOptions);
		if (name == $StandardSocketOptions::IP_MULTICAST_IF) {
			$init($StandardProtocolFamily);
			if ($equals(family, $StandardProtocolFamily::INET)) {
				int32_t address = $Net::getInterface4(this->fd);
				if (address == 0) {
					return $of(nullptr);
				}
				$var($InetAddress, ia, $Net::inet4FromInt(address));
				$var($NetworkInterface, ni, $NetworkInterface::getByInetAddress(ia));
				if (ni == nullptr) {
					$throwNew($IOException, "Unable to map address to interface"_s);
				}
				return $of($of(ni));
			} else {
				int32_t index = $Net::getInterface6(this->fd);
				if (index == 0) {
					return $of(nullptr);
				}
				$var($NetworkInterface, ni, $NetworkInterface::getByIndex(index));
				if (ni == nullptr) {
					$throwNew($IOException, "Unable to map index to interface"_s);
				}
				return $of($of(ni));
			}
		}
		if (name == $StandardSocketOptions::SO_REUSEADDR && this->reuseAddressEmulated) {
			return $of($of($Boolean::valueOf(this->isReuseAddress)));
		}
		return $of($Net::getSocketOption(this->fd, family, name));
	}
}

$Set* DatagramChannelImpl::supportedOptions() {
	$init($DatagramChannelImpl$DefaultOptionsHolder);
	return $DatagramChannelImpl$DefaultOptionsHolder::defaultOptions$;
}

$SocketAddress* DatagramChannelImpl::beginRead(bool blocking, bool mustBeConnected) {
	if (blocking && this->interruptible) {
		begin();
	}
	$var($SocketAddress, remote, nullptr);
	$synchronized(this->stateLock) {
		ensureOpen();
		$assign(remote, this->remoteAddress$);
		if ((remote == nullptr) && mustBeConnected) {
			$throwNew($NotYetConnectedException);
		}
		if (this->localAddress$ == nullptr) {
			bindInternal(nullptr);
		}
		if (blocking) {
			this->readerThread = $NativeThread::current();
		}
	}
	return remote;
}

void DatagramChannelImpl::endRead(bool blocking, bool completed) {
	if (blocking) {
		$synchronized(this->stateLock) {
			this->readerThread = 0;
			if (this->state == DatagramChannelImpl::ST_CLOSING) {
				tryFinishClose();
			}
		}
		if (this->interruptible) {
			end(completed);
		} else if (!completed && !isOpen()) {
			$throwNew($AsynchronousCloseException);
		}
	}
}

$SocketAddress* DatagramChannelImpl::receive($ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($nc(dst)->isReadOnly()) {
		$throwNew($IllegalArgumentException, "Read-only buffer"_s);
	}
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SocketAddress, var$2, nullptr);
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			$var($SocketAddress, sender, nullptr);
			{
				$var($Throwable, var$3, nullptr);
				$var($SocketAddress, var$5, nullptr);
				bool return$4 = false;
				try {
					$var($SocketAddress, remote, beginRead(blocking, false));
					bool connected = (remote != nullptr);
					$var($SecurityManager, sm, $System::getSecurityManager());
					if (connected || (sm == nullptr)) {
						int32_t n = receive(dst, connected);
						if (blocking) {
							while (true) {
								bool var$6 = $IOStatus::okayToRetry(n);
								if (!(var$6 && isOpen())) {
									break;
								}
								{
									$init($Net);
									park($Net::POLLIN);
									n = receive(dst, connected);
								}
							}
						}
						if (n >= 0) {
							$assign(sender, sourceSocketAddress());
						}
					} else {
						$assign(sender, untrustedReceive(dst));
					}
					$assign(var$5, sender);
					return$4 = true;
					goto $finally1;
				} catch ($Throwable& var$7) {
					$assign(var$3, var$7);
				} $finally1: {
					endRead(blocking, (sender != nullptr));
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
				if (return$4) {
					$assign(var$2, var$5);
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$8) {
			$assign(var$0, var$8);
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
	$shouldNotReachHere();
}

$SocketAddress* DatagramChannelImpl::untrustedReceive($ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (!DatagramChannelImpl::$assertionsDisabled && !($nc(this->readLock)->isHeldByCurrentThread() && sm != nullptr && this->remoteAddress$ == nullptr)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, bb, $Util::getTemporaryDirectBuffer($nc(dst)->remaining()));
	{
		$var($Throwable, var$0, nullptr);
		$var($SocketAddress, var$2, nullptr);
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			for (;;) {
				int32_t n = receive(bb, false);
				if (blocking) {
					while (true) {
						bool var$3 = $IOStatus::okayToRetry(n);
						if (!(var$3 && isOpen())) {
							break;
						}
						{
							$init($Net);
							park($Net::POLLIN);
							n = receive(bb, false);
						}
					}
				}
				if (n >= 0) {
					$var($InetSocketAddress, isa, sourceSocketAddress());
					try {
						$var($String, var$4, $nc($($nc(isa)->getAddress()))->getHostAddress());
						$nc(sm)->checkAccept(var$4, isa->getPort());
						$nc(bb)->flip();
						$nc(dst)->put(bb);
						$assign(var$2, isa);
						return$1 = true;
						goto $finally;
					} catch ($SecurityException& se) {
						$nc(bb)->clear();
					}
				} else {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} $finally: {
			$Util::releaseTemporaryDirectBuffer(bb);
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

$SocketAddress* DatagramChannelImpl::blockingReceive($ByteBuffer* dst, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($SocketAddress, var$2, nullptr);
		bool return$1 = false;
		try {
			ensureOpen();
			if (!isBlocking()) {
				$throwNew($IllegalBlockingModeException);
			}
			$var($SecurityManager, sm, $System::getSecurityManager());
			bool connected = isConnected();
			$var($SocketAddress, sender, nullptr);
			do {
				if (nanos > 0) {
					$assign(sender, trustedBlockingReceive(dst, nanos));
				} else {
					$assign(sender, trustedBlockingReceive(dst));
				}
				if (sm != nullptr && !connected) {
					$var($InetSocketAddress, isa, $cast($InetSocketAddress, sender));
					try {
						$var($String, var$3, $nc($($nc(isa)->getAddress()))->getHostAddress());
						sm->checkAccept(var$3, isa->getPort());
					} catch ($SecurityException& e) {
						$assign(sender, nullptr);
					}
				}
			} while (sender == nullptr);
			$assign(var$2, sender);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
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
	$shouldNotReachHere();
}

$SocketAddress* DatagramChannelImpl::trustedBlockingReceive($ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !DatagramChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(this->readLock)->isHeldByCurrentThread();
		var$0 = !(var$1 && isBlocking());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($SocketAddress, sender, nullptr);
	{
		$var($Throwable, var$2, nullptr);
		$var($SocketAddress, var$4, nullptr);
		bool return$3 = false;
		try {
			$var($SocketAddress, remote, beginRead(true, false));
			bool connected = (remote != nullptr);
			int32_t n = receive(dst, connected);
			while (true) {
				bool var$5 = $IOStatus::okayToRetry(n);
				if (!(var$5 && isOpen())) {
					break;
				}
				{
					$init($Net);
					park($Net::POLLIN);
					n = receive(dst, connected);
				}
			}
			if (n >= 0) {
				$assign(sender, sourceSocketAddress());
			}
			$assign(var$4, sender);
			return$3 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$2, var$6);
		} $finally: {
			endRead(true, (sender != nullptr));
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
		if (return$3) {
			return var$4;
		}
	}
	$shouldNotReachHere();
}

$SocketAddress* DatagramChannelImpl::trustedBlockingReceive($ByteBuffer* dst, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !DatagramChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(this->readLock)->isHeldByCurrentThread();
		var$0 = !(var$1 && isBlocking());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($SocketAddress, sender, nullptr);
	{
		$var($Throwable, var$2, nullptr);
		$var($SocketAddress, var$4, nullptr);
		bool return$3 = false;
		try {
			$var($SocketAddress, remote, beginRead(true, false));
			bool connected = (remote != nullptr);
			lockedConfigureBlocking(false);
			{
				$var($Throwable, var$5, nullptr);
				$var($SocketAddress, var$7, nullptr);
				bool return$6 = false;
				try {
					int64_t startNanos = $System::nanoTime();
					int32_t n = receive(dst, connected);
					while (n == $IOStatus::UNAVAILABLE && isOpen()) {
						int64_t remainingNanos = nanos - ($System::nanoTime() - startNanos);
						if (remainingNanos <= 0) {
							$throwNew($SocketTimeoutException, "Receive timed out"_s);
						}
						$init($Net);
						park($Net::POLLIN, remainingNanos);
						n = receive(dst, connected);
					}
					if (n >= 0) {
						$assign(sender, sourceSocketAddress());
					}
					$assign(var$7, sender);
					return$6 = true;
					goto $finally1;
				} catch ($Throwable& var$8) {
					$assign(var$5, var$8);
				} $finally1: {
					tryLockedConfigureBlocking(true);
				}
				if (var$5 != nullptr) {
					$throw(var$5);
				}
				if (return$6) {
					$assign(var$4, var$7);
					return$3 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$9) {
			$assign(var$2, var$9);
		} $finally: {
			endRead(true, (sender != nullptr));
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
		if (return$3) {
			return var$4;
		}
	}
	$shouldNotReachHere();
}

int32_t DatagramChannelImpl::receive($ByteBuffer* dst, bool connected) {
	$useLocalCurrentObjectStackCache();
	int32_t pos = $nc(dst)->position();
	int32_t lim = dst->limit();
	if (!DatagramChannelImpl::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	if ($instanceOf($DirectBuffer, dst) && rem > 0) {
		return receiveIntoNativeBuffer(dst, rem, pos, connected);
	}
	int32_t newSize = $Math::max(rem, 1);
	$var($ByteBuffer, bb, $Util::getTemporaryDirectBuffer(newSize));
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			int32_t n = receiveIntoNativeBuffer(bb, newSize, 0, connected);
			$nc(bb)->flip();
			if (n > 0 && rem > 0) {
				dst->put(bb);
			}
			var$2 = n;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Util::releaseTemporaryDirectBuffer(bb);
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

int32_t DatagramChannelImpl::receiveIntoNativeBuffer($ByteBuffer* bb, int32_t rem, int32_t pos, bool connected) {
	$var($FileDescriptor, var$0, this->fd);
	int64_t var$1 = $nc(($cast($DirectBuffer, bb)))->address() + pos;
	int32_t var$2 = rem;
	int32_t n = receive0(var$0, var$1, var$2, $nc(this->sourceSockAddr)->address(), connected);
	if (n > 0) {
		$nc(bb)->position(pos + n);
	}
	return n;
}

$InetSocketAddress* DatagramChannelImpl::sourceSocketAddress() {
	$useLocalCurrentObjectStackCache();
	if (!DatagramChannelImpl::$assertionsDisabled && !$nc(this->readLock)->isHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	if (this->cachedInetSocketAddress != nullptr && $nc(this->sourceSockAddr)->equals(this->cachedSockAddr)) {
		return this->cachedInetSocketAddress;
	}
	$var($InetSocketAddress, isa, $nc(this->sourceSockAddr)->decode());
	$var($NativeSocketAddress, tmp, this->cachedSockAddr);
	$set(this, cachedSockAddr, this->sourceSockAddr);
	$set(this, sourceSockAddr, tmp);
	$set(this, cachedInetSocketAddress, isa);
	return isa;
}

int32_t DatagramChannelImpl::send($ByteBuffer* src, $SocketAddress* target) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(src);
	$var($InetSocketAddress, isa, $Net::checkAddress(target, this->family));
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int32_t n = 0;
			bool completed = false;
			{
				$var($Throwable, var$3, nullptr);
				try {
					$var($SocketAddress, remote, beginWrite(blocking, false));
					if (remote != nullptr) {
						if (!$nc($of(target))->equals(remote)) {
							$throwNew($AlreadyConnectedException);
						}
						n = $IOUtil::write(this->fd, src, (int64_t)-1, DatagramChannelImpl::nd);
						if (blocking) {
							while (true) {
								bool var$4 = $IOStatus::okayToRetry(n);
								if (!(var$4 && isOpen())) {
									break;
								}
								{
									park($Net::POLLOUT);
									n = $IOUtil::write(this->fd, src, (int64_t)-1, DatagramChannelImpl::nd);
								}
							}
						}
						completed = (n > 0);
					} else {
						$var($SecurityManager, sm, $System::getSecurityManager());
						$var($InetAddress, ia, $nc(isa)->getAddress());
						if (sm != nullptr) {
							if ($nc(ia)->isMulticastAddress()) {
								sm->checkMulticast(ia);
							} else {
								$var($String, var$5, ia->getHostAddress());
								sm->checkConnect(var$5, isa->getPort());
							}
						}
						if ($nc(ia)->isLinkLocalAddress()) {
							$assign(isa, $IPAddressUtil::toScopedAddress(isa));
						}
						if (isa->getPort() == 0) {
							$throwNew($SocketException, "Can\'t send to port 0"_s);
						}
						n = send(this->fd, src, isa);
						if (blocking) {
							while (true) {
								bool var$6 = $IOStatus::okayToRetry(n);
								if (!(var$6 && isOpen())) {
									break;
								}
								{
									park($Net::POLLOUT);
									n = send(this->fd, src, isa);
								}
							}
						}
						completed = (n >= 0);
					}
				} catch ($Throwable& var$7) {
					$assign(var$3, var$7);
				} /*finally*/ {
					endWrite(blocking, completed);
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			if (!DatagramChannelImpl::$assertionsDisabled && !(n >= 0 || n == $IOStatus::UNAVAILABLE)) {
				$throwNew($AssertionError);
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$8) {
			$assign(var$0, var$8);
		} $finally: {
			$nc(this->writeLock)->unlock();
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

void DatagramChannelImpl::blockingSend($ByteBuffer* src, $SocketAddress* target) {
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			ensureOpen();
			if (!isBlocking()) {
				$throwNew($IllegalBlockingModeException);
			}
			send(src, target);
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

int32_t DatagramChannelImpl::send($FileDescriptor* fd, $ByteBuffer* src, $InetSocketAddress* target) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($DirectBuffer, src)) {
		return sendFromNativeBuffer(fd, src, target);
	}
	int32_t pos = $nc(src)->position();
	int32_t lim = src->limit();
	if (!DatagramChannelImpl::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	$var($ByteBuffer, bb, $Util::getTemporaryDirectBuffer(rem));
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			$nc(bb)->put(src);
			bb->flip();
			src->position(pos);
			int32_t n = sendFromNativeBuffer(fd, bb, target);
			if (n > 0) {
				src->position(pos + n);
			}
			var$2 = n;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Util::releaseTemporaryDirectBuffer(bb);
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

int32_t DatagramChannelImpl::sendFromNativeBuffer($FileDescriptor* fd, $ByteBuffer* bb, $InetSocketAddress* target) {
	int32_t pos = $nc(bb)->position();
	int32_t lim = bb->limit();
	if (!DatagramChannelImpl::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	int32_t written = 0;
	try {
		int32_t addressLen = targetSocketAddress(target);
		$var($FileDescriptor, var$0, fd);
		int64_t var$1 = $nc(($cast($DirectBuffer, bb)))->address() + pos;
		int32_t var$2 = rem;
		written = send0(var$0, var$1, var$2, $nc(this->targetSockAddr)->address(), addressLen);
	} catch ($PortUnreachableException& pue) {
		if (isConnected()) {
			$throw(pue);
		}
		written = rem;
	}
	if (written > 0) {
		bb->position(pos + written);
	}
	return written;
}

int32_t DatagramChannelImpl::targetSocketAddress($InetSocketAddress* isa) {
	if (!DatagramChannelImpl::$assertionsDisabled && !$nc(this->writeLock)->isHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	if (isa == this->previousTarget) {
		return this->previousSockAddrLength;
	}
	$set(this, previousTarget, nullptr);
	int32_t len = $nc(this->targetSockAddr)->encode(this->family, isa);
	$set(this, previousTarget, isa);
	this->previousSockAddrLength = len;
	return len;
}

int32_t DatagramChannelImpl::read($ByteBuffer* buf) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(buf);
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int32_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				try {
					beginRead(blocking, true);
					n = $IOUtil::read(this->fd, buf, (int64_t)-1, DatagramChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLIN);
								n = $IOUtil::read(this->fd, buf, (int64_t)-1, DatagramChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endRead(blocking, n > 0);
					if (!DatagramChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
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
	$shouldNotReachHere();
}

int64_t DatagramChannelImpl::read($ByteBufferArray* dsts, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$Objects::checkFromIndexSize(offset, length, $nc(dsts)->length);
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int64_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int64_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				try {
					beginRead(blocking, true);
					n = $IOUtil::read(this->fd, dsts, offset, length, DatagramChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLIN);
								n = $IOUtil::read(this->fd, dsts, offset, length, DatagramChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endRead(blocking, n > 0);
					if (!DatagramChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
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
	$shouldNotReachHere();
}

$SocketAddress* DatagramChannelImpl::beginWrite(bool blocking, bool mustBeConnected) {
	if (blocking && this->interruptible) {
		begin();
	}
	$var($SocketAddress, remote, nullptr);
	$synchronized(this->stateLock) {
		ensureOpen();
		$assign(remote, this->remoteAddress$);
		if ((remote == nullptr) && mustBeConnected) {
			$throwNew($NotYetConnectedException);
		}
		if (this->localAddress$ == nullptr) {
			bindInternal(nullptr);
		}
		if (blocking) {
			this->writerThread = $NativeThread::current();
		}
	}
	return remote;
}

void DatagramChannelImpl::endWrite(bool blocking, bool completed) {
	if (blocking) {
		$synchronized(this->stateLock) {
			this->writerThread = 0;
			if (this->state == DatagramChannelImpl::ST_CLOSING) {
				tryFinishClose();
			}
		}
		if (this->interruptible) {
			end(completed);
		} else if (!completed && !isOpen()) {
			$throwNew($AsynchronousCloseException);
		}
	}
}

int32_t DatagramChannelImpl::write($ByteBuffer* buf) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(buf);
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int32_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				try {
					beginWrite(blocking, true);
					n = $IOUtil::write(this->fd, buf, (int64_t)-1, DatagramChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLOUT);
								n = $IOUtil::write(this->fd, buf, (int64_t)-1, DatagramChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endWrite(blocking, n > 0);
					if (!DatagramChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			$nc(this->writeLock)->unlock();
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

int64_t DatagramChannelImpl::write($ByteBufferArray* srcs, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$Objects::checkFromIndexSize(offset, length, $nc(srcs)->length);
	$nc(this->writeLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int64_t var$2 = 0;
		bool return$1 = false;
		try {
			bool blocking = isBlocking();
			int64_t n = 0;
			{
				$var($Throwable, var$3, nullptr);
				try {
					beginWrite(blocking, true);
					n = $IOUtil::write(this->fd, srcs, offset, length, DatagramChannelImpl::nd);
					if (blocking) {
						while (true) {
							bool var$4 = $IOStatus::okayToRetry(n);
							if (!(var$4 && isOpen())) {
								break;
							}
							{
								$init($Net);
								park($Net::POLLOUT);
								n = $IOUtil::write(this->fd, srcs, offset, length, DatagramChannelImpl::nd);
							}
						}
					}
				} catch ($Throwable& var$5) {
					$assign(var$3, var$5);
				} /*finally*/ {
					endWrite(blocking, n > 0);
					if (!DatagramChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
						$throwNew($AssertionError);
					}
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			var$2 = $IOStatus::normalize(n);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			$nc(this->writeLock)->unlock();
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

void DatagramChannelImpl::implConfigureBlocking(bool block) {
	$useLocalCurrentObjectStackCache();
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->writeLock)->lock();
			{
				$var($Throwable, var$1, nullptr);
				try {
					lockedConfigureBlocking(block);
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					$nc(this->writeLock)->unlock();
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->readLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void DatagramChannelImpl::lockedConfigureBlocking(bool block) {
	bool var$0 = !DatagramChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(this->readLock)->isHeldByCurrentThread();
		var$0 = !(var$1 || $nc(this->writeLock)->isHeldByCurrentThread());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$synchronized(this->stateLock) {
		ensureOpen();
		$IOUtil::configureBlocking(this->fd, block);
	}
}

bool DatagramChannelImpl::tryLockedConfigureBlocking(bool block) {
	bool var$0 = !DatagramChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(this->readLock)->isHeldByCurrentThread();
		var$0 = !(var$1 || $nc(this->writeLock)->isHeldByCurrentThread());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$synchronized(this->stateLock) {
		if (isOpen()) {
			$IOUtil::configureBlocking(this->fd, block);
			return true;
		} else {
			return false;
		}
	}
}

$InetSocketAddress* DatagramChannelImpl::localAddress() {
	$synchronized(this->stateLock) {
		return this->localAddress$;
	}
}

$InetSocketAddress* DatagramChannelImpl::remoteAddress() {
	$synchronized(this->stateLock) {
		return this->remoteAddress$;
	}
}

$NetworkChannel* DatagramChannelImpl::bind($SocketAddress* local) {
	$useLocalCurrentObjectStackCache();
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->writeLock)->lock();
			{
				$var($Throwable, var$1, nullptr);
				try {
					$synchronized(this->stateLock) {
						ensureOpen();
						if (this->localAddress$ != nullptr) {
							$throwNew($AlreadyBoundException);
						}
						bindInternal(local);
					}
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					$nc(this->writeLock)->unlock();
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->readLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return this;
}

void DatagramChannelImpl::bindInternal($SocketAddress* local) {
	$useLocalCurrentObjectStackCache();
	if (!DatagramChannelImpl::$assertionsDisabled && !($Thread::holdsLock(this->stateLock) && (this->localAddress$ == nullptr))) {
		$throwNew($AssertionError);
	}
	$var($InetSocketAddress, isa, nullptr);
	if (local == nullptr) {
		$init($StandardProtocolFamily);
		if ($equals(this->family, $StandardProtocolFamily::INET)) {
			$assign(isa, $new($InetSocketAddress, $($InetAddress::getByName("0.0.0.0"_s)), 0));
		} else {
			$assign(isa, $new($InetSocketAddress, 0));
		}
	} else {
		$assign(isa, $Net::checkAddress(local, this->family));
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkListen($nc(isa)->getPort());
	}
	$var($ProtocolFamily, var$0, this->family);
	$var($FileDescriptor, var$1, this->fd);
	$var($InetAddress, var$2, $nc(isa)->getAddress());
	$Net::bind(var$0, var$1, var$2, isa->getPort());
	$set(this, localAddress$, $Net::localAddress(this->fd));
}

bool DatagramChannelImpl::isConnected() {
	$synchronized(this->stateLock) {
		return (this->state == DatagramChannelImpl::ST_CONNECTED);
	}
}

$DatagramChannel* DatagramChannelImpl::connect($SocketAddress* sa) {
	return connect(sa, true);
}

$DatagramChannel* DatagramChannelImpl::connect($SocketAddress* sa, bool check) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, isa, $Net::checkAddress(sa, this->family));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($InetAddress, ia, $nc(isa)->getAddress());
		if ($nc(ia)->isMulticastAddress()) {
			sm->checkMulticast(ia);
		} else {
			$var($String, var$0, ia->getHostAddress());
			sm->checkConnect(var$0, isa->getPort());
			$var($String, var$1, ia->getHostAddress());
			sm->checkAccept(var$1, isa->getPort());
		}
	}
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$2, nullptr);
		try {
			$nc(this->writeLock)->lock();
			{
				$var($Throwable, var$3, nullptr);
				try {
					$synchronized(this->stateLock) {
						ensureOpen();
						if (check && this->state == DatagramChannelImpl::ST_CONNECTED) {
							$throwNew($AlreadyConnectedException);
						}
						if ($nc(isa)->getPort() == 0) {
							$throwNew($SocketException, "Can\'t connect to port 0"_s);
						}
						if (this->localAddress$ == nullptr) {
							bindInternal(nullptr);
						}
						$set(this, initialLocalAddress, this->localAddress$);
						$var($ProtocolFamily, var$4, this->family);
						$var($FileDescriptor, var$5, this->fd);
						$var($InetAddress, var$6, $nc(isa)->getAddress());
						int32_t n = $Net::connect(var$4, var$5, var$6, isa->getPort());
						if (n <= 0) {
							$throwNew($Error);
						}
						$set(this, remoteAddress$, isa);
						this->state = DatagramChannelImpl::ST_CONNECTED;
						$set(this, localAddress$, $Net::localAddress(this->fd));
						bool blocking = isBlocking();
						if (blocking) {
							$IOUtil::configureBlocking(this->fd, false);
						}
						{
							$var($Throwable, var$7, nullptr);
							try {
								$var($ByteBuffer, buf, $ByteBuffer::allocate(100));
								while (receive(buf, false) >= 0) {
									$nc(buf)->clear();
								}
							} catch ($Throwable& var$8) {
								$assign(var$7, var$8);
							} /*finally*/ {
								if (blocking) {
									$IOUtil::configureBlocking(this->fd, true);
								}
							}
							if (var$7 != nullptr) {
								$throw(var$7);
							}
						}
					}
				} catch ($Throwable& var$9) {
					$assign(var$3, var$9);
				} /*finally*/ {
					$nc(this->writeLock)->unlock();
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
		} catch ($Throwable& var$10) {
			$assign(var$2, var$10);
		} /*finally*/ {
			$nc(this->readLock)->unlock();
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
	}
	return this;
}

$DatagramChannel* DatagramChannelImpl::disconnect() {
	$useLocalCurrentObjectStackCache();
	$nc(this->readLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($DatagramChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			$nc(this->writeLock)->lock();
			{
				$var($Throwable, var$3, nullptr);
				$var($DatagramChannel, var$5, nullptr);
				bool return$4 = false;
				try {
					$synchronized(this->stateLock) {
						if (!isOpen() || (this->state != DatagramChannelImpl::ST_CONNECTED)) {
							$assign(var$5, this);
							return$4 = true;
							goto $finally1;
						}
						$init($StandardProtocolFamily);
						bool isIPv6 = ($equals(this->family, $StandardProtocolFamily::INET6));
						disconnect0(this->fd, isIPv6);
						$set(this, remoteAddress$, nullptr);
						this->state = DatagramChannelImpl::ST_UNCONNECTED;
						$set(this, localAddress$, $Net::localAddress(this->fd));
						{
							$var($Throwable, var$6, nullptr);
							try {
								if (!$nc(this->localAddress$)->equals(this->initialLocalAddress)) {
									repairSocket(this->initialLocalAddress);
									bool var$7 = !DatagramChannelImpl::$assertionsDisabled;
									if (var$7) {
										bool var$8 = (this->localAddress$ != nullptr) && $nc(this->localAddress$)->equals($($Net::localAddress(this->fd)));
										var$7 = !(var$8 && $nc(this->localAddress$)->equals(this->initialLocalAddress));
									}
									if (var$7) {
										$throwNew($AssertionError);
									}
								}
							} catch ($Throwable& var$9) {
								$assign(var$6, var$9);
							} /*finally*/ {
								$set(this, initialLocalAddress, nullptr);
							}
							if (var$6 != nullptr) {
								$throw(var$6);
							}
						}
					}
				} catch ($Throwable& var$10) {
					$assign(var$3, var$10);
				} $finally1: {
					$nc(this->writeLock)->unlock();
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
				if (return$4) {
					$assign(var$2, var$5);
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$11) {
			$assign(var$0, var$11);
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
	return this;
}

void DatagramChannelImpl::repairSocket($InetSocketAddress* target) {
	$useLocalCurrentObjectStackCache();
	if (!DatagramChannelImpl::$assertionsDisabled && !$Thread::holdsLock(this->stateLock)) {
		$throwNew($AssertionError);
	}
	if ($nc(this->localAddress$)->getPort() == 0) {
		if (!DatagramChannelImpl::$assertionsDisabled && !$nc($($nc(this->localAddress$)->getAddress()))->equals($($nc(target)->getAddress()))) {
			$throwNew($AssertionError);
		}
		$var($ProtocolFamily, var$0, this->family);
		$var($FileDescriptor, var$1, this->fd);
		$var($InetAddress, var$2, $nc(target)->getAddress());
		$Net::bind(var$0, var$1, var$2, target->getPort());
		$set(this, localAddress$, $Net::localAddress(this->fd));
		return;
	}
	$var($Map, map, $new($HashMap));
	{
		$var($Iterator, i$, $nc($(supportedOptions()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SocketOption, option, $cast($SocketOption, i$->next()));
			{
				$var($Object, value, getOption(option));
				if (value != nullptr) {
					map->put(option, value);
				}
			}
		}
	}
	$var($FileDescriptor, newfd, $Net::socket(this->family, false));
	{
		$var($Throwable, var$3, nullptr);
		try {
			{
				$var($Iterator, i$, $nc($(map->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
					{
						$var($SocketOption, option, $cast($SocketOption, $nc(e)->getKey()));
						if ($SocketOptionRegistry::findOption(option, $Net::UNSPEC) != nullptr) {
							$var($Object, value, e->getValue());
							try {
								$Net::setSocketOption(newfd, $Net::UNSPEC, option, value);
							} catch ($IOException& ignore) {
							}
						}
					}
				}
			}
			if (!isBlocking()) {
				$IOUtil::configureBlocking(newfd, false);
			}
			$nc(DatagramChannelImpl::nd)->dup(newfd, this->fd);
		} catch ($Throwable& var$4) {
			$assign(var$3, var$4);
		} /*finally*/ {
			$nc(DatagramChannelImpl::nd)->close(newfd);
		}
		if (var$3 != nullptr) {
			$throw(var$3);
		}
	}
	try {
		$var($ProtocolFamily, var$5, this->family);
		$var($FileDescriptor, var$6, this->fd);
		$var($InetAddress, var$7, $nc(target)->getAddress());
		$Net::bind(var$5, var$6, var$7, target->getPort());
	} catch ($IOException& ioe) {
		$set(this, localAddress$, nullptr);
		$throw(ioe);
	}
	$set(this, localAddress$, $Net::localAddress(this->fd));
	{
		$var($Iterator, i$, $nc($(map->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($SocketOption, option, $cast($SocketOption, $nc(e)->getKey()));
				$var($Object, value, e->getValue());
				try {
					setOption(option, value);
				} catch ($IOException& ignore) {
				}
			}
		}
	}
	$var($MembershipRegistry, registry, this->registry);
	if (registry != nullptr) {
		registry->forEach(static_cast<$MembershipRegistry$ThrowingConsumer*>($$new(DatagramChannelImpl$$Lambda$lambda$repairSocket$0, this)));
	}
	$DatagramChannelImpl$AbstractSelectableChannels::forEach(this, static_cast<$Consumer*>($$new(DatagramChannelImpl$$Lambda$reset$1)));
}

$MembershipKey* DatagramChannelImpl::innerJoin($InetAddress* group, $NetworkInterface* interf, $InetAddress* source) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(group)->isMulticastAddress()) {
		$throwNew($IllegalArgumentException, "Group not a multicast address"_s);
	}
	if ($instanceOf($Inet4Address, group)) {
		$init($StandardProtocolFamily);
		if ($equals(this->family, $StandardProtocolFamily::INET6) && !$Net::canIPv6SocketJoinIPv4Group()) {
			$throwNew($IllegalArgumentException, "IPv6 socket cannot join IPv4 multicast group"_s);
		}
	} else if ($instanceOf($Inet6Address, group)) {
		$init($StandardProtocolFamily);
		if (!$equals(this->family, $StandardProtocolFamily::INET6)) {
			$throwNew($IllegalArgumentException, "Only IPv6 sockets can join IPv6 multicast group"_s);
		}
	} else {
		$throwNew($IllegalArgumentException, "Address type not supported"_s);
	}
	if (source != nullptr) {
		if (source->isAnyLocalAddress()) {
			$throwNew($IllegalArgumentException, "Source address is a wildcard address"_s);
		}
		if (source->isMulticastAddress()) {
			$throwNew($IllegalArgumentException, "Source address is multicast address"_s);
		}
		if ($of(source)->getClass() != $nc($of(group))->getClass()) {
			$throwNew($IllegalArgumentException, "Source address is different type to group"_s);
		}
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkMulticast(group);
	}
	$synchronized(this->stateLock) {
		ensureOpen();
		if (this->registry == nullptr) {
			$set(this, registry, $new($MembershipRegistry));
		} else {
			$var($MembershipKey, key, $nc(this->registry)->checkMembership(group, interf, source));
			if (key != nullptr) {
				return key;
			}
		}
		$var($MembershipKeyImpl, key, nullptr);
		$init($StandardProtocolFamily);
		if (($equals(this->family, $StandardProtocolFamily::INET6)) && (($instanceOf($Inet6Address, group)) || $Net::canJoin6WithIPv4Group())) {
			int32_t index = $nc(interf)->getIndex();
			if (index == -1) {
				$throwNew($IOException, "Network interface cannot be identified"_s);
			}
			$var($bytes, groupAddress, $Net::inet6AsByteArray(group));
			$var($bytes, sourceAddress, (source == nullptr) ? ($bytes*)nullptr : $Net::inet6AsByteArray(source));
			int32_t n = $Net::join6(this->fd, groupAddress, index, sourceAddress);
			if (n == $IOStatus::UNAVAILABLE) {
				$throwNew($UnsupportedOperationException);
			}
			$assign(key, $new($MembershipKeyImpl$Type6, this, group, interf, source, groupAddress, index, sourceAddress));
		} else {
			$var($Inet4Address, target, $Net::anyInet4Address(interf));
			if (target == nullptr) {
				$throwNew($IOException, "Network interface not configured for IPv4"_s);
			}
			int32_t groupAddress = $Net::inet4AsInt(group);
			int32_t targetAddress = $Net::inet4AsInt(target);
			int32_t sourceAddress = (source == nullptr) ? 0 : $Net::inet4AsInt(source);
			int32_t n = $Net::join4(this->fd, groupAddress, targetAddress, sourceAddress);
			if (n == $IOStatus::UNAVAILABLE) {
				$throwNew($UnsupportedOperationException);
			}
			$assign(key, $new($MembershipKeyImpl$Type4, this, group, interf, source, groupAddress, targetAddress, sourceAddress));
		}
		$nc(this->registry)->add(key);
		return key;
	}
}

$MembershipKey* DatagramChannelImpl::join($InetAddress* group, $NetworkInterface* interf) {
	return innerJoin(group, interf, nullptr);
}

$MembershipKey* DatagramChannelImpl::join($InetAddress* group, $NetworkInterface* interf, $InetAddress* source) {
	$Objects::requireNonNull(source);
	return innerJoin(group, interf, source);
}

void DatagramChannelImpl::drop($MembershipKeyImpl* key) {
	$useLocalCurrentObjectStackCache();
	if (!DatagramChannelImpl::$assertionsDisabled && !$equals($nc(key)->channel(), this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->stateLock) {
		if (!$nc(key)->isValid()) {
			return;
		}
		try {
			if ($instanceOf($MembershipKeyImpl$Type6, key)) {
				$var($MembershipKeyImpl$Type6, key6, $cast($MembershipKeyImpl$Type6, key));
				$var($FileDescriptor, var$0, this->fd);
				$var($bytes, var$1, $nc(key6)->groupAddress());
				int32_t var$2 = key6->index();
				$Net::drop6(var$0, var$1, var$2, $(key6->source()));
			} else {
				$var($MembershipKeyImpl$Type4, key4, $cast($MembershipKeyImpl$Type4, key));
				$var($FileDescriptor, var$3, this->fd);
				int32_t var$4 = $nc(key4)->groupAddress();
				int32_t var$5 = key4->interfaceAddress();
				$Net::drop4(var$3, var$4, var$5, key4->source());
			}
		} catch ($IOException& ioe) {
			$throwNew($AssertionError, $of(ioe));
		}
		$nc(key)->invalidate();
		$nc(this->registry)->remove(key);
	}
}

$MembershipKey* DatagramChannelImpl::findMembership($InetAddress* group, $NetworkInterface* interf) {
	$synchronized(this->stateLock) {
		if (this->registry != nullptr) {
			return $nc(this->registry)->checkMembership(group, interf, nullptr);
		} else {
			return nullptr;
		}
	}
}

void DatagramChannelImpl::block($MembershipKeyImpl* key, $InetAddress* source) {
	$useLocalCurrentObjectStackCache();
	if (!DatagramChannelImpl::$assertionsDisabled && !$equals($nc(key)->channel(), this)) {
		$throwNew($AssertionError);
	}
	if (!DatagramChannelImpl::$assertionsDisabled && !($nc(key)->sourceAddress() == nullptr)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->stateLock) {
		if (!$nc(key)->isValid()) {
			$throwNew($IllegalStateException, "key is no longer valid"_s);
		}
		if ($nc(source)->isAnyLocalAddress()) {
			$throwNew($IllegalArgumentException, "Source address is a wildcard address"_s);
		}
		if ($nc(source)->isMulticastAddress()) {
			$throwNew($IllegalArgumentException, "Source address is multicast address"_s);
		}
		if ($nc($of(source))->getClass() != $nc($of($($nc(key)->group())))->getClass()) {
			$throwNew($IllegalArgumentException, "Source address is different type to group"_s);
		}
		int32_t n = 0;
		if ($instanceOf($MembershipKeyImpl$Type6, key)) {
			$var($MembershipKeyImpl$Type6, key6, $cast($MembershipKeyImpl$Type6, key));
			$var($FileDescriptor, var$0, this->fd);
			$var($bytes, var$1, $nc(key6)->groupAddress());
			int32_t var$2 = key6->index();
			n = $Net::block6(var$0, var$1, var$2, $($Net::inet6AsByteArray(source)));
		} else {
			$var($MembershipKeyImpl$Type4, key4, $cast($MembershipKeyImpl$Type4, key));
			$var($FileDescriptor, var$3, this->fd);
			int32_t var$4 = $nc(key4)->groupAddress();
			int32_t var$5 = key4->interfaceAddress();
			n = $Net::block4(var$3, var$4, var$5, $Net::inet4AsInt(source));
		}
		if (n == $IOStatus::UNAVAILABLE) {
			$throwNew($UnsupportedOperationException);
		}
	}
}

void DatagramChannelImpl::unblock($MembershipKeyImpl* key, $InetAddress* source) {
	$useLocalCurrentObjectStackCache();
	if (!DatagramChannelImpl::$assertionsDisabled && !$equals($nc(key)->channel(), this)) {
		$throwNew($AssertionError);
	}
	if (!DatagramChannelImpl::$assertionsDisabled && !($nc(key)->sourceAddress() == nullptr)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->stateLock) {
		if (!$nc(key)->isValid()) {
			$throwNew($IllegalStateException, "key is no longer valid"_s);
		}
		try {
			if ($instanceOf($MembershipKeyImpl$Type6, key)) {
				$var($MembershipKeyImpl$Type6, key6, $cast($MembershipKeyImpl$Type6, key));
				$var($FileDescriptor, var$0, this->fd);
				$var($bytes, var$1, $nc(key6)->groupAddress());
				int32_t var$2 = key6->index();
				$Net::unblock6(var$0, var$1, var$2, $($Net::inet6AsByteArray(source)));
			} else {
				$var($MembershipKeyImpl$Type4, key4, $cast($MembershipKeyImpl$Type4, key));
				$var($FileDescriptor, var$3, this->fd);
				int32_t var$4 = $nc(key4)->groupAddress();
				int32_t var$5 = key4->interfaceAddress();
				$Net::unblock4(var$3, var$4, var$5, $Net::inet4AsInt(source));
			}
		} catch ($IOException& ioe) {
			$throwNew($AssertionError, $of(ioe));
		}
	}
}

bool DatagramChannelImpl::tryClose() {
	if (!DatagramChannelImpl::$assertionsDisabled && !($Thread::holdsLock(this->stateLock) && this->state == DatagramChannelImpl::ST_CLOSING)) {
		$throwNew($AssertionError);
	}
	if ((this->readerThread == 0) && (this->writerThread == 0) && !isRegistered()) {
		this->state = DatagramChannelImpl::ST_CLOSED;
		try {
			$nc(this->cleaner)->clean();
		} catch ($UncheckedIOException& ioe) {
			$throw($($cast($IOException, ioe->getCause())));
		}
		return true;
	} else {
		return false;
	}
}

void DatagramChannelImpl::tryFinishClose() {
	try {
		tryClose();
	} catch ($IOException& ignore) {
	}
}

void DatagramChannelImpl::implCloseBlockingMode() {
	$synchronized(this->stateLock) {
		if (!DatagramChannelImpl::$assertionsDisabled && !(this->state < DatagramChannelImpl::ST_CLOSING)) {
			$throwNew($AssertionError);
		}
		this->state = DatagramChannelImpl::ST_CLOSING;
		if (this->registry != nullptr) {
			$nc(this->registry)->invalidateAll();
		}
		if (!tryClose()) {
			int64_t reader = this->readerThread;
			int64_t writer = this->writerThread;
			if (reader != 0 || writer != 0) {
				$nc(DatagramChannelImpl::nd)->preClose(this->fd);
				if (reader != 0) {
					$NativeThread::signal(reader);
				}
				if (writer != 0) {
					$NativeThread::signal(writer);
				}
			}
		}
	}
}

void DatagramChannelImpl::implCloseNonBlockingMode() {
	$synchronized(this->stateLock) {
		if (!DatagramChannelImpl::$assertionsDisabled && !(this->state < DatagramChannelImpl::ST_CLOSING)) {
			$throwNew($AssertionError);
		}
		this->state = DatagramChannelImpl::ST_CLOSING;
		if (this->registry != nullptr) {
			$nc(this->registry)->invalidateAll();
		}
	}
	$nc(this->readLock)->lock();
	$nc(this->readLock)->unlock();
	$nc(this->writeLock)->lock();
	$nc(this->writeLock)->unlock();
	$synchronized(this->stateLock) {
		if (this->state == DatagramChannelImpl::ST_CLOSING) {
			tryClose();
		}
	}
}

void DatagramChannelImpl::implCloseSelectableChannel() {
	if (!DatagramChannelImpl::$assertionsDisabled && ! !isOpen()) {
		$throwNew($AssertionError);
	}
	if (isBlocking()) {
		implCloseBlockingMode();
	} else {
		implCloseNonBlockingMode();
	}
}

void DatagramChannelImpl::kill() {
	$synchronized(this->stateLock) {
		if (this->state == DatagramChannelImpl::ST_CLOSING) {
			tryFinishClose();
		}
	}
}

bool DatagramChannelImpl::translateReadyOps(int32_t ops, int32_t initialOps, $SelectionKeyImpl* ski) {
	int32_t intOps = $nc(ski)->nioInterestOps();
	int32_t oldOps = ski->nioReadyOps();
	int32_t newOps = initialOps;
	$init($Net);
	if (((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLNVAL)) != 0) {
		return false;
	}
	if (((int32_t)(ops & (uint32_t)($Net::POLLERR | $Net::POLLHUP))) != 0) {
		newOps = intOps;
		ski->nioReadyOps(newOps);
		return ((int32_t)(newOps & (uint32_t)~oldOps)) != 0;
	}
	if ((((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLIN)) != 0) && (((int32_t)(intOps & (uint32_t)$SelectionKey::OP_READ)) != 0)) {
		newOps |= $SelectionKey::OP_READ;
	}
	if ((((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLOUT)) != 0) && (((int32_t)(intOps & (uint32_t)$SelectionKey::OP_WRITE)) != 0)) {
		newOps |= $SelectionKey::OP_WRITE;
	}
	ski->nioReadyOps(newOps);
	return ((int32_t)(newOps & (uint32_t)~oldOps)) != 0;
}

bool DatagramChannelImpl::translateAndUpdateReadyOps(int32_t ops, $SelectionKeyImpl* ski) {
	return translateReadyOps(ops, $nc(ski)->nioReadyOps(), ski);
}

bool DatagramChannelImpl::translateAndSetReadyOps(int32_t ops, $SelectionKeyImpl* ski) {
	return translateReadyOps(ops, 0, ski);
}

int32_t DatagramChannelImpl::translateInterestOps(int32_t ops) {
	int32_t newOps = 0;
	if (((int32_t)(ops & (uint32_t)$SelectionKey::OP_READ)) != 0) {
		$init($Net);
		newOps |= $Net::POLLIN;
	}
	if (((int32_t)(ops & (uint32_t)$SelectionKey::OP_WRITE)) != 0) {
		$init($Net);
		newOps |= $Net::POLLOUT;
	}
	if (((int32_t)(ops & (uint32_t)$SelectionKey::OP_CONNECT)) != 0) {
		$init($Net);
		newOps |= $Net::POLLIN;
	}
	return newOps;
}

$FileDescriptor* DatagramChannelImpl::getFD() {
	return this->fd;
}

int32_t DatagramChannelImpl::getFDVal() {
	return this->fdVal;
}

$Runnable* DatagramChannelImpl::releaserFor($FileDescriptor* fd, $NativeSocketAddressArray* sockAddrs) {
	$init(DatagramChannelImpl);
	return static_cast<$Runnable*>($new(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2, fd, sockAddrs));
}

void DatagramChannelImpl::disconnect0($FileDescriptor* fd, bool isIPv6) {
	$init(DatagramChannelImpl);
	$prepareNativeStatic(DatagramChannelImpl, disconnect0, void, $FileDescriptor* fd, bool isIPv6);
	$invokeNativeStatic(fd, isIPv6);
	$finishNativeStatic();
}

int32_t DatagramChannelImpl::receive0($FileDescriptor* fd, int64_t address, int32_t len, int64_t senderAddress, bool connected) {
	$init(DatagramChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(DatagramChannelImpl, receive0, int32_t, $FileDescriptor* fd, int64_t address, int32_t len, int64_t senderAddress, bool connected);
	$ret = $invokeNativeStatic(fd, address, len, senderAddress, connected);
	$finishNativeStatic();
	return $ret;
}

int32_t DatagramChannelImpl::send0($FileDescriptor* fd, int64_t address, int32_t len, int64_t targetAddress, int32_t targetAddressLen) {
	$init(DatagramChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(DatagramChannelImpl, send0, int32_t, $FileDescriptor* fd, int64_t address, int32_t len, int64_t targetAddress, int32_t targetAddressLen);
	$ret = $invokeNativeStatic(fd, address, len, targetAddress, targetAddressLen);
	$finishNativeStatic();
	return $ret;
}

void DatagramChannelImpl::lambda$releaserFor$1($FileDescriptor* fd, $NativeSocketAddressArray* sockAddrs) {
	$init(DatagramChannelImpl);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(DatagramChannelImpl::nd)->close(fd);
			} catch ($IOException& ioe) {
				$throwNew($UncheckedIOException, ioe);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$ResourceManager::afterUdpClose();
			$NativeSocketAddress::freeAll(sockAddrs);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void DatagramChannelImpl::lambda$repairSocket$0($MembershipKeyImpl* k) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($MembershipKeyImpl$Type6, k)) {
		$var($MembershipKeyImpl$Type6, key6, $cast($MembershipKeyImpl$Type6, k));
		$var($FileDescriptor, var$0, this->fd);
		$var($bytes, var$1, $nc(key6)->groupAddress());
		int32_t var$2 = key6->index();
		$Net::join6(var$0, var$1, var$2, $(key6->source()));
	} else {
		$var($MembershipKeyImpl$Type4, key4, $cast($MembershipKeyImpl$Type4, k));
		$var($FileDescriptor, var$3, this->fd);
		int32_t var$4 = $nc(key4)->groupAddress();
		int32_t var$5 = key4->interfaceAddress();
		$Net::join4(var$3, var$4, var$5, key4->source());
	}
}

void clinit$DatagramChannelImpl($Class* class$) {
	$beforeCallerSensitive();
	DatagramChannelImpl::$assertionsDisabled = !DatagramChannelImpl::class$->desiredAssertionStatus();
	$assignStatic(DatagramChannelImpl::nd, $new($DatagramDispatcher));
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$load($DatagramSocket);
			$assignStatic(DatagramChannelImpl::SOCKET, $nc(l)->findVarHandle(DatagramChannelImpl::class$, "socket"_s, $DatagramSocket::class$));
		} catch ($Exception& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	{
		$IOUtil::load();
	}
}

DatagramChannelImpl::DatagramChannelImpl() {
}

$Class* DatagramChannelImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DatagramChannelImpl$$Lambda$lambda$repairSocket$0::classInfo$.name)) {
			return DatagramChannelImpl$$Lambda$lambda$repairSocket$0::load$(name, initialize);
		}
		if (name->equals(DatagramChannelImpl$$Lambda$reset$1::classInfo$.name)) {
			return DatagramChannelImpl$$Lambda$reset$1::load$(name, initialize);
		}
		if (name->equals(DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::classInfo$.name)) {
			return DatagramChannelImpl$$Lambda$lambda$releaserFor$1$2::load$(name, initialize);
		}
	}
	$loadClass(DatagramChannelImpl, name, initialize, &_DatagramChannelImpl_ClassInfo_, clinit$DatagramChannelImpl, allocate$DatagramChannelImpl);
	return class$;
}

$Class* DatagramChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun