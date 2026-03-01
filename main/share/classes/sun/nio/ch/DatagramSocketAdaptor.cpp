#include <sun/nio/ch/DatagramSocketAdaptor.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/Error.h>
#include <java/lang/Math.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/DatagramPacket.h>
#include <java/net/DatagramSocket.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/MulticastSocket.h>
#include <java/net/NetworkInterface.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/AlreadyConnectedException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/MembershipKey.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/stream/Stream.h>
#include <sun/nio/ch/DatagramChannelImpl.h>
#include <sun/nio/ch/DatagramSocketAdaptor$DatagramPackets.h>
#include <sun/nio/ch/DatagramSocketAdaptor$DatagramSockets.h>
#include <sun/nio/ch/DatagramSocketAdaptor$NetworkInterfaces.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/Util.h>
#include <jcpp.h>

#undef IP_MULTICAST_IF
#undef IP_MULTICAST_LOOP
#undef IP_MULTICAST_TTL
#undef IP_TOS
#undef MILLISECONDS
#undef NO_DELEGATE
#undef SO_BROADCAST
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_SNDBUF

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DatagramPacket = ::java::net::DatagramPacket;
using $DatagramSocket = ::java::net::DatagramSocket;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $MulticastSocket = ::java::net::MulticastSocket;
using $NetworkInterface = ::java::net::NetworkInterface;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketOption = ::java::net::SocketOption;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlreadyConnectedException = ::java::nio::channels::AlreadyConnectedException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $MembershipKey = ::java::nio::channels::MembershipKey;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $Stream = ::java::util::stream::Stream;
using $DatagramChannelImpl = ::sun::nio::ch::DatagramChannelImpl;
using $DatagramSocketAdaptor$DatagramPackets = ::sun::nio::ch::DatagramSocketAdaptor$DatagramPackets;
using $DatagramSocketAdaptor$DatagramSockets = ::sun::nio::ch::DatagramSocketAdaptor$DatagramSockets;
using $DatagramSocketAdaptor$NetworkInterfaces = ::sun::nio::ch::DatagramSocketAdaptor$NetworkInterfaces;
using $Net = ::sun::nio::ch::Net;
using $Util = ::sun::nio::ch::Util;

namespace sun {
	namespace nio {
		namespace ch {

class DatagramSocketAdaptor$$Lambda$lambda$getInterface$0 : public $PrivilegedAction {
	$class(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($NetworkInterface* ni) {
		$set(this, ni, ni);
	}
	virtual $Object* run() override {
		 return $of(DatagramSocketAdaptor::lambda$getInterface$0(ni));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DatagramSocketAdaptor$$Lambda$lambda$getInterface$0>());
	}
	$NetworkInterface* ni = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::fieldInfos[2] = {
	{"ni", "Ljava/net/NetworkInterface;", nullptr, $PUBLIC, $field(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0, ni)},
	{}
};
$MethodInfo DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::methodInfos[3] = {
	{"<init>", "(Ljava/net/NetworkInterface;)V", nullptr, $PUBLIC, $method(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0, init$, void, $NetworkInterface*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0, run, $Object*)},
	{}
};
$ClassInfo DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.DatagramSocketAdaptor$$Lambda$lambda$getInterface$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::load$($String* name, bool initialize) {
	$loadClass(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::class$ = nullptr;

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_getInterface17[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_getLoopbackMode21[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_getTTL30[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_joinGroup36[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_leaveGroup39[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_send44[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_setInterface48[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_setLoopbackMode49[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DatagramSocketAdaptor_MethodAnnotations_setTTL56[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _DatagramSocketAdaptor_FieldInfo_[] = {
	{"dc", "Lsun/nio/ch/DatagramChannelImpl;", nullptr, $PRIVATE | $FINAL, $field(DatagramSocketAdaptor, dc)},
	{"timeout", "I", nullptr, $PRIVATE | $VOLATILE, $field(DatagramSocketAdaptor, timeout)},
	{"sendLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(DatagramSocketAdaptor, sendLock)},
	{"outgoingInterfaceLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(DatagramSocketAdaptor, outgoingInterfaceLock)},
	{"outgoingNetworkInterface", "Ljava/net/NetworkInterface;", nullptr, $PRIVATE, $field(DatagramSocketAdaptor, outgoingNetworkInterface$)},
	{"outgoingInetAddress", "Ljava/net/InetAddress;", nullptr, $PRIVATE, $field(DatagramSocketAdaptor, outgoingInetAddress)},
	{}
};

$MethodInfo _DatagramSocketAdaptor_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/ch/DatagramChannelImpl;)V", nullptr, $PRIVATE, $method(DatagramSocketAdaptor, init$, void, $DatagramChannelImpl*), "java.io.IOException"},
	{"anyInetAddress", "()Ljava/net/InetAddress;", nullptr, $PRIVATE, $method(DatagramSocketAdaptor, anyInetAddress, $InetAddress*)},
	{"anyNetworkInterface", "()Ljava/net/NetworkInterface;", nullptr, $PRIVATE, $method(DatagramSocketAdaptor, anyNetworkInterface, $NetworkInterface*)},
	{"bind", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, bind, void, $SocketAddress*), "java.net.SocketException"},
	{"checkGroup", "(Ljava/net/SocketAddress;)Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(DatagramSocketAdaptor, checkGroup, $InetAddress*, $SocketAddress*), "java.net.SocketException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, close, void)},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, connect, void, $InetAddress*, int32_t)},
	{"connect", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, connect, void, $SocketAddress*), "java.net.SocketException"},
	{"connectInternal", "(Ljava/net/SocketAddress;)V", nullptr, $PRIVATE, $method(DatagramSocketAdaptor, connectInternal, void, $SocketAddress*), "java.net.SocketException"},
	{"create", "(Lsun/nio/ch/DatagramChannelImpl;)Ljava/net/DatagramSocket;", nullptr, $STATIC, $staticMethod(DatagramSocketAdaptor, create, $DatagramSocket*, $DatagramChannelImpl*)},
	{"defaultNetworkInterface", "()Ljava/net/NetworkInterface;", nullptr, $PRIVATE, $method(DatagramSocketAdaptor, defaultNetworkInterface, $NetworkInterface*), "java.net.SocketException"},
	{"disconnect", "()V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, disconnect, void)},
	{"getBooleanOption", "(Ljava/net/SocketOption;)Z", "(Ljava/net/SocketOption<Ljava/lang/Boolean;>;)Z", $PRIVATE, $method(DatagramSocketAdaptor, getBooleanOption, bool, $SocketOption*), "java.net.SocketException"},
	{"getBroadcast", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getBroadcast, bool), "java.net.SocketException"},
	{"getChannel", "()Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getChannel, $DatagramChannel*)},
	{"getInetAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getInetAddress, $InetAddress*)},
	{"getIntOption", "(Ljava/net/SocketOption;)I", "(Ljava/net/SocketOption<Ljava/lang/Integer;>;)I", $PRIVATE, $method(DatagramSocketAdaptor, getIntOption, int32_t, $SocketOption*), "java.net.SocketException"},
	{"getInterface", "()Ljava/net/InetAddress;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, getInterface, $InetAddress*), "java.net.SocketException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_getInterface17},
	{"getLocalAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getLocalAddress, $InetAddress*)},
	{"getLocalPort", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getLocalPort, int32_t)},
	{"getLocalSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getLocalSocketAddress, $SocketAddress*)},
	{"getLoopbackMode", "()Z", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, getLoopbackMode, bool), "java.net.SocketException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_getLoopbackMode21},
	{"getNetworkInterface", "()Ljava/net/NetworkInterface;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getNetworkInterface, $NetworkInterface*), "java.net.SocketException"},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getPort", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getPort, int32_t)},
	{"getReceiveBufferSize", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getReceiveBufferSize, int32_t), "java.net.SocketException"},
	{"getRemoteSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getRemoteSocketAddress, $SocketAddress*)},
	{"getReuseAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getReuseAddress, bool), "java.net.SocketException"},
	{"getSendBufferSize", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getSendBufferSize, int32_t), "java.net.SocketException"},
	{"getSoTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getSoTimeout, int32_t), "java.net.SocketException"},
	{"getTTL", "()B", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, getTTL, int8_t), "java.io.IOException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_getTTL30},
	{"getTimeToLive", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getTimeToLive, int32_t), "java.io.IOException"},
	{"getTrafficClass", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, getTrafficClass, int32_t), "java.net.SocketException"},
	{"isBound", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, isBound, bool)},
	{"isClosed", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, isClosed, bool)},
	{"isConnected", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, isConnected, bool)},
	{"joinGroup", "(Ljava/net/InetAddress;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, joinGroup, void, $InetAddress*), "java.io.IOException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_joinGroup36},
	{"joinGroup", "(Ljava/net/SocketAddress;Ljava/net/NetworkInterface;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, joinGroup, void, $SocketAddress*, $NetworkInterface*), "java.io.IOException"},
	{"lambda$getInterface$0", "(Ljava/net/NetworkInterface;)Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DatagramSocketAdaptor, lambda$getInterface$0, $InetAddress*, $NetworkInterface*)},
	{"leaveGroup", "(Ljava/net/InetAddress;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, leaveGroup, void, $InetAddress*), "java.io.IOException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_leaveGroup39},
	{"leaveGroup", "(Ljava/net/SocketAddress;Ljava/net/NetworkInterface;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, leaveGroup, void, $SocketAddress*, $NetworkInterface*), "java.io.IOException"},
	{"outgoingNetworkInterface", "()Ljava/net/NetworkInterface;", nullptr, $PRIVATE, $method(DatagramSocketAdaptor, outgoingNetworkInterface, $NetworkInterface*), "java.net.SocketException"},
	{"receive", "(Ljava/net/DatagramPacket;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, receive, void, $DatagramPacket*), "java.io.IOException"},
	{"send", "(Ljava/net/DatagramPacket;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, send, void, $DatagramPacket*), "java.io.IOException"},
	{"send", "(Ljava/net/DatagramPacket;B)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, send, void, $DatagramPacket*, int8_t), "java.io.IOException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_send44},
	{"setBooleanOption", "(Ljava/net/SocketOption;Z)V", "(Ljava/net/SocketOption<Ljava/lang/Boolean;>;Z)V", $PRIVATE, $method(DatagramSocketAdaptor, setBooleanOption, void, $SocketOption*, bool), "java.net.SocketException"},
	{"setBroadcast", "(Z)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setBroadcast, void, bool), "java.net.SocketException"},
	{"setIntOption", "(Ljava/net/SocketOption;I)V", "(Ljava/net/SocketOption<Ljava/lang/Integer;>;I)V", $PRIVATE, $method(DatagramSocketAdaptor, setIntOption, void, $SocketOption*, int32_t), "java.net.SocketException"},
	{"setInterface", "(Ljava/net/InetAddress;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, setInterface, void, $InetAddress*), "java.net.SocketException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_setInterface48},
	{"setLoopbackMode", "(Z)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, setLoopbackMode, void, bool), "java.net.SocketException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_setLoopbackMode49},
	{"setNetworkInterface", "(Ljava/net/NetworkInterface;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setNetworkInterface, void, $NetworkInterface*), "java.net.SocketException"},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)Ljava/net/DatagramSocket;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)Ljava/net/DatagramSocket;", $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setOption, $DatagramSocket*, $SocketOption*, Object$*), "java.io.IOException"},
	{"setReceiveBufferSize", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setReceiveBufferSize, void, int32_t), "java.net.SocketException"},
	{"setReuseAddress", "(Z)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setReuseAddress, void, bool), "java.net.SocketException"},
	{"setSendBufferSize", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setSendBufferSize, void, int32_t), "java.net.SocketException"},
	{"setSoTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setSoTimeout, void, int32_t), "java.net.SocketException"},
	{"setTTL", "(B)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(DatagramSocketAdaptor, setTTL, void, int8_t), "java.io.IOException", nullptr, _DatagramSocketAdaptor_MethodAnnotations_setTTL56},
	{"setTimeToLive", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setTimeToLive, void, int32_t), "java.io.IOException"},
	{"setTrafficClass", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocketAdaptor, setTrafficClass, void, int32_t), "java.net.SocketException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PUBLIC, $virtualMethod(DatagramSocketAdaptor, supportedOptions, $Set*)},
	{}
};

$InnerClassInfo _DatagramSocketAdaptor_InnerClassesInfo_[] = {
	{"sun.nio.ch.DatagramSocketAdaptor$DatagramSockets", "sun.nio.ch.DatagramSocketAdaptor", "DatagramSockets", $PRIVATE | $STATIC},
	{"sun.nio.ch.DatagramSocketAdaptor$NetworkInterfaces", "sun.nio.ch.DatagramSocketAdaptor", "NetworkInterfaces", $PRIVATE | $STATIC},
	{"sun.nio.ch.DatagramSocketAdaptor$DatagramPackets", "sun.nio.ch.DatagramSocketAdaptor", "DatagramPackets", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DatagramSocketAdaptor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.DatagramSocketAdaptor",
	"java.net.MulticastSocket",
	nullptr,
	_DatagramSocketAdaptor_FieldInfo_,
	_DatagramSocketAdaptor_MethodInfo_,
	nullptr,
	nullptr,
	_DatagramSocketAdaptor_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.DatagramSocketAdaptor$DatagramSockets,sun.nio.ch.DatagramSocketAdaptor$NetworkInterfaces,sun.nio.ch.DatagramSocketAdaptor$DatagramPackets"
};

$Object* allocate$DatagramSocketAdaptor($Class* clazz) {
	return $of($alloc(DatagramSocketAdaptor));
}

void DatagramSocketAdaptor::init$($DatagramChannelImpl* dc) {
	$init($DatagramSocketAdaptor$DatagramSockets);
	$MulticastSocket::init$($DatagramSocketAdaptor$DatagramSockets::NO_DELEGATE);
	$set(this, sendLock, $new($ReentrantLock));
	$set(this, outgoingInterfaceLock, $new($Object));
	$set(this, dc, dc);
}

$DatagramSocket* DatagramSocketAdaptor::create($DatagramChannelImpl* dc) {
	$init(DatagramSocketAdaptor);
	try {
		return $new(DatagramSocketAdaptor, dc);
	} catch ($IOException& e) {
		$throwNew($Error, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void DatagramSocketAdaptor::connectInternal($SocketAddress* remote) {
	try {
		$nc(this->dc)->connect(remote, false);
	} catch ($ClosedChannelException& e) {
	} catch ($Exception& x) {
		$Net::translateToSocketException(x);
	}
}

void DatagramSocketAdaptor::bind($SocketAddress* local$renamed) {
	$var($SocketAddress, local, local$renamed);
	if (local != nullptr) {
		$assign(local, $Net::asInetSocketAddress(local));
	} else {
		$assign(local, $new($InetSocketAddress, 0));
	}
	try {
		$nc(this->dc)->bind(local);
	} catch ($Exception& x) {
		$Net::translateToSocketException(x);
	}
}

void DatagramSocketAdaptor::connect($InetAddress* address, int32_t port) {
	if (address == nullptr) {
		$throwNew($IllegalArgumentException, "Address can\'t be null"_s);
	}
	try {
		connectInternal($$new($InetSocketAddress, address, port));
	} catch ($SocketException& x) {
		$throwNew($UncheckedIOException, x);
	}
}

void DatagramSocketAdaptor::connect($SocketAddress* remote) {
	if (remote == nullptr) {
		$throwNew($IllegalArgumentException, "Address can\'t be null"_s);
	}
	connectInternal($($Net::asInetSocketAddress(remote)));
}

void DatagramSocketAdaptor::disconnect() {
	try {
		$nc(this->dc)->disconnect();
	} catch ($IOException& x) {
		$throwNew($UncheckedIOException, x);
	}
}

bool DatagramSocketAdaptor::isBound() {
	return $nc(this->dc)->localAddress() != nullptr;
}

bool DatagramSocketAdaptor::isConnected() {
	return $nc(this->dc)->remoteAddress() != nullptr;
}

$InetAddress* DatagramSocketAdaptor::getInetAddress() {
	$var($InetSocketAddress, remote, $nc(this->dc)->remoteAddress());
	return (remote != nullptr) ? $nc(remote)->getAddress() : ($InetAddress*)nullptr;
}

int32_t DatagramSocketAdaptor::getPort() {
	$var($InetSocketAddress, remote, $nc(this->dc)->remoteAddress());
	return (remote != nullptr) ? $nc(remote)->getPort() : -1;
}

$SocketAddress* DatagramSocketAdaptor::getRemoteSocketAddress() {
	return $nc(this->dc)->remoteAddress();
}

$SocketAddress* DatagramSocketAdaptor::getLocalSocketAddress() {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, local, $nc(this->dc)->localAddress());
	if (local == nullptr || isClosed()) {
		return nullptr;
	}
	$var($InetAddress, addr, $nc(local)->getAddress());
	if ($nc(addr)->isAnyLocalAddress()) {
		return local;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		try {
			sm->checkConnect($($nc(addr)->getHostAddress()), -1);
		} catch ($SecurityException& x) {
			return $new($InetSocketAddress, local->getPort());
		}
	}
	return local;
}

void DatagramSocketAdaptor::send($DatagramPacket* p) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, bb, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($InetSocketAddress, target, nullptr);
			$synchronized(p) {
				int32_t len = $nc(p)->getLength();
				$assign(bb, $Util::getTemporaryDirectBuffer(len));
				$var($bytes, var$1, p->getData());
				$nc(bb)->put(var$1, p->getOffset(), len);
				bb->flip();
				if (p->getAddress() == nullptr) {
					$var($InetSocketAddress, remote, $nc(this->dc)->remoteAddress());
					if (remote == nullptr) {
						$throwNew($IllegalArgumentException, "Address not set"_s);
					}
					p->setAddress($($nc(remote)->getAddress()));
					p->setPort($nc(remote)->getPort());
					$assign(target, remote);
				} else {
					$assign(target, $cast($InetSocketAddress, p->getSocketAddress()));
				}
			}
			try {
				$nc(this->dc)->blockingSend(bb, target);
			} catch ($AlreadyConnectedException& e) {
				$throwNew($IllegalArgumentException, "Connected and packet address differ"_s);
			} catch ($ClosedChannelException& e) {
				$var($SocketException, exc, $new($SocketException, "Socket closed"_s));
				exc->initCause(e);
				$throw(exc);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			if (bb != nullptr) {
				$Util::offerFirstTemporaryDirectBuffer(bb);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void DatagramSocketAdaptor::receive($DatagramPacket* p) {
	$useLocalCurrentObjectStackCache();
	int32_t bufLength = $DatagramSocketAdaptor$DatagramPackets::getBufLength(p);
	$var($ByteBuffer, bb, $Util::getTemporaryDirectBuffer(bufLength));
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$init($TimeUnit);
				int64_t nanos = $TimeUnit::MILLISECONDS->toNanos(this->timeout);
				$var($SocketAddress, sender, $nc(this->dc)->blockingReceive(bb, nanos));
				$nc(bb)->flip();
				$synchronized(p) {
					int32_t var$1 = bb->limit();
					int32_t len = $Math::min(var$1, $DatagramSocketAdaptor$DatagramPackets::getBufLength(p));
					$var($bytes, var$2, $nc(p)->getData());
					bb->get(var$2, p->getOffset(), len);
					$DatagramSocketAdaptor$DatagramPackets::setLength(p, len);
					$nc(p)->setSocketAddress(sender);
				}
			} catch ($ClosedChannelException& e) {
				$var($SocketException, exc, $new($SocketException, "Socket closed"_s));
				exc->initCause(e);
				$throw(exc);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$Util::offerFirstTemporaryDirectBuffer(bb);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$InetAddress* DatagramSocketAdaptor::getLocalAddress() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		return nullptr;
	}
	$var($InetSocketAddress, local, $nc(this->dc)->localAddress());
	if (local == nullptr) {
		$assign(local, $new($InetSocketAddress, 0));
	}
	$var($InetAddress, result, $nc(local)->getAddress());
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		try {
			sm->checkConnect($($nc(result)->getHostAddress()), -1);
		} catch ($SecurityException& x) {
			return $$new($InetSocketAddress, 0)->getAddress();
		}
	}
	return result;
}

int32_t DatagramSocketAdaptor::getLocalPort() {
	if (isClosed()) {
		return -1;
	}
	$var($InetSocketAddress, local, $nc(this->dc)->localAddress());
	if (local != nullptr) {
		return local->getPort();
	}
	return 0;
}

void DatagramSocketAdaptor::setSoTimeout(int32_t timeout) {
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeout < 0"_s);
	}
	this->timeout = timeout;
}

int32_t DatagramSocketAdaptor::getSoTimeout() {
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	return this->timeout;
}

void DatagramSocketAdaptor::setBooleanOption($SocketOption* name, bool value) {
	try {
		$nc(this->dc)->setOption(name, $($Boolean::valueOf(value)));
	} catch ($IOException& x) {
		$Net::translateToSocketException(x);
	}
}

void DatagramSocketAdaptor::setIntOption($SocketOption* name, int32_t value) {
	try {
		$nc(this->dc)->setOption(name, $($Integer::valueOf(value)));
	} catch ($IOException& x) {
		$Net::translateToSocketException(x);
	}
}

bool DatagramSocketAdaptor::getBooleanOption($SocketOption* name) {
	try {
		return $nc(($cast($Boolean, $($nc(this->dc)->getOption(name)))))->booleanValue();
	} catch ($IOException& x) {
		$Net::translateToSocketException(x);
		return false;
	}
	$shouldNotReachHere();
}

int32_t DatagramSocketAdaptor::getIntOption($SocketOption* name) {
	try {
		return $nc(($cast($Integer, $($nc(this->dc)->getOption(name)))))->intValue();
	} catch ($IOException& x) {
		$Net::translateToSocketException(x);
		return -1;
	}
	$shouldNotReachHere();
}

void DatagramSocketAdaptor::setSendBufferSize(int32_t size) {
	if (size <= 0) {
		$throwNew($IllegalArgumentException, "Invalid send size"_s);
	}
	$init($StandardSocketOptions);
	setIntOption($StandardSocketOptions::SO_SNDBUF, size);
}

int32_t DatagramSocketAdaptor::getSendBufferSize() {
	$init($StandardSocketOptions);
	return getIntOption($StandardSocketOptions::SO_SNDBUF);
}

void DatagramSocketAdaptor::setReceiveBufferSize(int32_t size) {
	if (size <= 0) {
		$throwNew($IllegalArgumentException, "Invalid receive size"_s);
	}
	$init($StandardSocketOptions);
	setIntOption($StandardSocketOptions::SO_RCVBUF, size);
}

int32_t DatagramSocketAdaptor::getReceiveBufferSize() {
	$init($StandardSocketOptions);
	return getIntOption($StandardSocketOptions::SO_RCVBUF);
}

void DatagramSocketAdaptor::setReuseAddress(bool on) {
	$init($StandardSocketOptions);
	setBooleanOption($StandardSocketOptions::SO_REUSEADDR, on);
}

bool DatagramSocketAdaptor::getReuseAddress() {
	$init($StandardSocketOptions);
	return getBooleanOption($StandardSocketOptions::SO_REUSEADDR);
}

void DatagramSocketAdaptor::setBroadcast(bool on) {
	$init($StandardSocketOptions);
	setBooleanOption($StandardSocketOptions::SO_BROADCAST, on);
}

bool DatagramSocketAdaptor::getBroadcast() {
	$init($StandardSocketOptions);
	return getBooleanOption($StandardSocketOptions::SO_BROADCAST);
}

void DatagramSocketAdaptor::setTrafficClass(int32_t tc) {
	$init($StandardSocketOptions);
	setIntOption($StandardSocketOptions::IP_TOS, tc);
}

int32_t DatagramSocketAdaptor::getTrafficClass() {
	$init($StandardSocketOptions);
	return getIntOption($StandardSocketOptions::IP_TOS);
}

void DatagramSocketAdaptor::close() {
	try {
		$nc(this->dc)->close();
	} catch ($IOException& x) {
		$throwNew($Error, static_cast<$Throwable*>(x));
	}
}

bool DatagramSocketAdaptor::isClosed() {
	return !$nc(this->dc)->isOpen();
}

$DatagramChannel* DatagramSocketAdaptor::getChannel() {
	return this->dc;
}

$DatagramSocket* DatagramSocketAdaptor::setOption($SocketOption* name, Object$* value) {
	$nc(this->dc)->setOption(name, value);
	return this;
}

$Object* DatagramSocketAdaptor::getOption($SocketOption* name) {
	return $of($nc(this->dc)->getOption(name));
}

$Set* DatagramSocketAdaptor::supportedOptions() {
	return $nc(this->dc)->supportedOptions();
}

void DatagramSocketAdaptor::setTTL(int8_t ttl) {
	setTimeToLive($Byte::toUnsignedInt(ttl));
}

void DatagramSocketAdaptor::setTimeToLive(int32_t ttl) {
	$nc(this->sendLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($StandardSocketOptions);
			setIntOption($StandardSocketOptions::IP_MULTICAST_TTL, ttl);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->sendLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int8_t DatagramSocketAdaptor::getTTL() {
	return (int8_t)getTimeToLive();
}

int32_t DatagramSocketAdaptor::getTimeToLive() {
	$nc(this->sendLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			$init($StandardSocketOptions);
			var$2 = getIntOption($StandardSocketOptions::IP_MULTICAST_TTL);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->sendLock)->unlock();
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

void DatagramSocketAdaptor::joinGroup($InetAddress* group) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(group);
	try {
		joinGroup($$new($InetSocketAddress, group, 0), nullptr);
	} catch ($IllegalArgumentException& iae) {
		$throw($cast($SocketException, $($$new($SocketException, "joinGroup failed"_s)->initCause(iae))));
	}
}

void DatagramSocketAdaptor::leaveGroup($InetAddress* group) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(group);
	try {
		leaveGroup($$new($InetSocketAddress, group, 0), nullptr);
	} catch ($IllegalArgumentException& iae) {
		$throw($cast($SocketException, $($$new($SocketException, "leaveGroup failed"_s)->initCause(iae))));
	}
}

$InetAddress* DatagramSocketAdaptor::checkGroup($SocketAddress* mcastaddr) {
	$init(DatagramSocketAdaptor);
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, addr, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, mcastaddr);
	if (var$0) {
		$assign(addr, $cast($InetSocketAddress, mcastaddr));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	$var($InetAddress, group, $nc(addr)->getAddress());
	if (group == nullptr) {
		$throwNew($IllegalArgumentException, "Unresolved address"_s);
	}
	if (!$nc(group)->isMulticastAddress()) {
		$throwNew($SocketException, "Not a multicast address"_s);
	}
	return group;
}

void DatagramSocketAdaptor::joinGroup($SocketAddress* mcastaddr, $NetworkInterface* netIf) {
	$useLocalCurrentObjectStackCache();
	$var($InetAddress, group, checkGroup(mcastaddr));
	$var($NetworkInterface, ni, (netIf != nullptr) ? netIf : defaultNetworkInterface());
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$synchronized(this) {
		$var($MembershipKey, key, $nc(this->dc)->findMembership(group, ni));
		if (key != nullptr) {
			$var($SecurityManager, sm, $System::getSecurityManager());
			if (sm != nullptr) {
				sm->checkMulticast(group);
			}
			$throwNew($SocketException, "Already a member of group"_s);
		}
		$nc(this->dc)->join(group, ni);
	}
}

void DatagramSocketAdaptor::leaveGroup($SocketAddress* mcastaddr, $NetworkInterface* netIf) {
	$useLocalCurrentObjectStackCache();
	$var($InetAddress, group, checkGroup(mcastaddr));
	$var($NetworkInterface, ni, (netIf != nullptr) ? netIf : defaultNetworkInterface());
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkMulticast(group);
	}
	$synchronized(this) {
		$var($MembershipKey, key, $nc(this->dc)->findMembership(group, ni));
		if (key == nullptr) {
			$throwNew($SocketException, "Not a member of group"_s);
		}
		$nc(key)->drop();
	}
}

void DatagramSocketAdaptor::setInterface($InetAddress* inf) {
	$useLocalCurrentObjectStackCache();
	if (inf == nullptr) {
		$throwNew($SocketException, "Invalid value \'null\'"_s);
	}
	$var($NetworkInterface, ni, $NetworkInterface::getByInetAddress(inf));
	if (ni == nullptr) {
		$var($String, address, $nc(inf)->getHostAddress());
		$throwNew($SocketException, $$str({"No network interface with address "_s, address}));
	}
	$synchronized(this->outgoingInterfaceLock) {
		setNetworkInterface(ni);
		$set(this, outgoingNetworkInterface$, ni);
		$set(this, outgoingInetAddress, inf);
	}
}

$InetAddress* DatagramSocketAdaptor::getInterface() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$synchronized(this->outgoingInterfaceLock) {
		$var($NetworkInterface, ni, outgoingNetworkInterface());
		if (ni != nullptr) {
			if (ni->equals(this->outgoingNetworkInterface$)) {
				return this->outgoingInetAddress;
			} else {
				$var($PrivilegedAction, pa, nullptr);
				$assign(pa, static_cast<$PrivilegedAction*>($new(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0, ni)));
				$var($InetAddress, ia, $cast($InetAddress, $AccessController::doPrivileged(pa)));
				if (ia == nullptr) {
					$throwNew($SocketException, "Network interface has no IP address"_s);
				}
				$set(this, outgoingNetworkInterface$, ni);
				$set(this, outgoingInetAddress, ia);
				return ia;
			}
		}
	}
	return anyInetAddress();
}

void DatagramSocketAdaptor::setNetworkInterface($NetworkInterface* netIf) {
	try {
		$init($StandardSocketOptions);
		setOption($StandardSocketOptions::IP_MULTICAST_IF, netIf);
	} catch ($IOException& e) {
		$Net::translateToSocketException(e);
	}
}

$NetworkInterface* DatagramSocketAdaptor::getNetworkInterface() {
	$var($NetworkInterface, ni, outgoingNetworkInterface());
	if (ni == nullptr) {
		$assign(ni, anyNetworkInterface());
	}
	return ni;
}

void DatagramSocketAdaptor::setLoopbackMode(bool disable) {
	bool enable = !disable;
	$init($StandardSocketOptions);
	setBooleanOption($StandardSocketOptions::IP_MULTICAST_LOOP, enable);
}

bool DatagramSocketAdaptor::getLoopbackMode() {
	$init($StandardSocketOptions);
	bool enabled = getBooleanOption($StandardSocketOptions::IP_MULTICAST_LOOP);
	return !enabled;
}

void DatagramSocketAdaptor::send($DatagramPacket* p, int8_t ttl) {
	$useLocalCurrentObjectStackCache();
	$nc(this->sendLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			int32_t oldValue = getTimeToLive();
			{
				$var($Throwable, var$1, nullptr);
				try {
					setTTL(ttl);
					send(p);
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					setTimeToLive(oldValue);
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->sendLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$NetworkInterface* DatagramSocketAdaptor::outgoingNetworkInterface() {
	try {
		$init($StandardSocketOptions);
		return $cast($NetworkInterface, getOption($StandardSocketOptions::IP_MULTICAST_IF));
	} catch ($IOException& e) {
		$Net::translateToSocketException(e);
		return nullptr;
	}
	$shouldNotReachHere();
}

$NetworkInterface* DatagramSocketAdaptor::defaultNetworkInterface() {
	$var($NetworkInterface, ni, outgoingNetworkInterface());
	if (ni == nullptr) {
		$assign(ni, $DatagramSocketAdaptor$NetworkInterfaces::getDefault());
	}
	if (ni == nullptr) {
		$assign(ni, anyNetworkInterface());
	}
	return ni;
}

$NetworkInterface* DatagramSocketAdaptor::anyNetworkInterface() {
	$useLocalCurrentObjectStackCache();
	$var($InetAddressArray, addrs, $new($InetAddressArray, 1));
	addrs->set(0, $(anyInetAddress()));
	return $DatagramSocketAdaptor$NetworkInterfaces::newNetworkInterface($($nc(addrs->get(0))->getHostName()), 0, addrs);
}

$InetAddress* DatagramSocketAdaptor::anyInetAddress() {
	return $$new($InetSocketAddress, 0)->getAddress();
}

$InetAddress* DatagramSocketAdaptor::lambda$getInterface$0($NetworkInterface* ni) {
	$init(DatagramSocketAdaptor);
	$useLocalCurrentObjectStackCache();
	return $cast($InetAddress, $nc($($nc($($nc(ni)->inetAddresses()))->findFirst()))->orElse(nullptr));
}

DatagramSocketAdaptor::DatagramSocketAdaptor() {
}

$Class* DatagramSocketAdaptor::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::classInfo$.name)) {
			return DatagramSocketAdaptor$$Lambda$lambda$getInterface$0::load$(name, initialize);
		}
	}
	$loadClass(DatagramSocketAdaptor, name, initialize, &_DatagramSocketAdaptor_ClassInfo_, allocate$DatagramSocketAdaptor);
	return class$;
}

$Class* DatagramSocketAdaptor::class$ = nullptr;

		} // ch
	} // nio
} // sun