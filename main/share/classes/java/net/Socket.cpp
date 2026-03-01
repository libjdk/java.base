#include <java/net/Socket.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/net/HttpConnectSocketImpl.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/NetPermission.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/Socket$SocketInputStream.h>
#include <java/net/Socket$SocketOutputStream.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketImpl.h>
#include <java/net/SocketImplFactory.h>
#include <java/net/SocketOption.h>
#include <java/net/SocketOptions.h>
#include <java/net/SocksSocketImpl.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/security/Permission.h>
#include <java/util/Collections.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <sun/net/ApplicationProxy.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef HTTP
#undef IN
#undef IP_TOS
#undef NO_PROXY
#undef OUT
#undef SET_SOCKETIMPL_PERMISSION
#undef SOCKS
#undef SO_BINDADDR
#undef SO_KEEPALIVE
#undef SO_LINGER
#undef SO_OOBINLINE
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_SNDBUF
#undef SO_TIMEOUT
#undef TCP_NODELAY

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $HttpConnectSocketImpl = ::java::net::HttpConnectSocketImpl;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $Socket$SocketInputStream = ::java::net::Socket$SocketInputStream;
using $Socket$SocketOutputStream = ::java::net::Socket$SocketOutputStream;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketImpl = ::java::net::SocketImpl;
using $SocketImplFactory = ::java::net::SocketImplFactory;
using $SocketOption = ::java::net::SocketOption;
using $SocketOptions = ::java::net::SocketOptions;
using $SocksSocketImpl = ::java::net::SocksSocketImpl;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $Permission = ::java::security::Permission;
using $Collections = ::java::util::Collections;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ApplicationProxy = ::sun::net::ApplicationProxy;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace net {

$CompoundAttribute _Socket_MethodAnnotations_init$7[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Socket_MethodAnnotations_init$8[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$NamedAttribute Socket_Attribute_var$0[] = {
	{"since", 's', "17"},
	{}
};

$CompoundAttribute _Socket_MethodAnnotations_setSocketImplFactory55[] = {
	{"Ljava/lang/Deprecated;", Socket_Attribute_var$0},
	{}
};

$FieldInfo _Socket_FieldInfo_[] = {
	{"created", "Z", nullptr, $PRIVATE, $field(Socket, created)},
	{"bound", "Z", nullptr, $PRIVATE, $field(Socket, bound)},
	{"connected", "Z", nullptr, $PRIVATE, $field(Socket, connected)},
	{"closed", "Z", nullptr, $PRIVATE, $field(Socket, closed)},
	{"closeLock", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(Socket, closeLock)},
	{"shutIn", "Z", nullptr, $PRIVATE, $field(Socket, shutIn)},
	{"shutOut", "Z", nullptr, $PRIVATE, $field(Socket, shutOut)},
	{"impl", "Ljava/net/SocketImpl;", nullptr, 0, $field(Socket, impl)},
	{"in", "Ljava/io/InputStream;", nullptr, $PRIVATE | $VOLATILE, $field(Socket, in)},
	{"out", "Ljava/io/OutputStream;", nullptr, $PRIVATE | $VOLATILE, $field(Socket, out)},
	{"IN", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Socket, IN)},
	{"OUT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Socket, OUT)},
	{"factory", "Ljava/net/SocketImplFactory;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Socket, factory)},
	{"options", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $VOLATILE, $field(Socket, options)},
	{}
};

$MethodInfo _Socket_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Socket, init$, void)},
	{"<init>", "(Ljava/net/Proxy;)V", nullptr, $PUBLIC, $method(Socket, init$, void, $Proxy*)},
	{"<init>", "(Ljava/net/SocketImpl;)V", nullptr, $PROTECTED, $method(Socket, init$, void, $SocketImpl*), "java.net.SocketException"},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(Socket, init$, void, $String*, int32_t), "java.net.UnknownHostException,java.io.IOException"},
	{"<init>", "(Ljava/net/InetAddress;I)V", nullptr, $PUBLIC, $method(Socket, init$, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;ILjava/net/InetAddress;I)V", nullptr, $PUBLIC, $method(Socket, init$, void, $String*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/net/InetAddress;ILjava/net/InetAddress;I)V", nullptr, $PUBLIC, $method(Socket, init$, void, $InetAddress*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;IZ)V", nullptr, $PUBLIC | $DEPRECATED, $method(Socket, init$, void, $String*, int32_t, bool), "java.io.IOException", nullptr, _Socket_MethodAnnotations_init$7},
	{"<init>", "(Ljava/net/InetAddress;IZ)V", nullptr, $PUBLIC | $DEPRECATED, $method(Socket, init$, void, $InetAddress*, int32_t, bool), "java.io.IOException", nullptr, _Socket_MethodAnnotations_init$8},
	{"<init>", "(Ljava/net/SocketAddress;Ljava/net/SocketAddress;Z)V", nullptr, $PRIVATE, $method(Socket, init$, void, $SocketAddress*, $SocketAddress*, bool), "java.io.IOException"},
	{"bind", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $virtualMethod(Socket, bind, void, $SocketAddress*), "java.io.IOException"},
	{"checkAddress", "(Ljava/net/InetAddress;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Socket, checkAddress, void, $InetAddress*, $String*)},
	{"checkPermission", "(Ljava/net/SocketImpl;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(Socket, checkPermission, $Void*, $SocketImpl*)},
	{"close", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, close, void), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $virtualMethod(Socket, connect, void, $SocketAddress*), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)V", nullptr, $PUBLIC, $virtualMethod(Socket, connect, void, $SocketAddress*, int32_t), "java.io.IOException"},
	{"createImpl", "(Z)V", nullptr, 0, $virtualMethod(Socket, createImpl, void, bool), "java.net.SocketException"},
	{"getChannel", "()Ljava/nio/channels/SocketChannel;", nullptr, $PUBLIC, $virtualMethod(Socket, getChannel, $SocketChannel*)},
	{"getImpl", "()Ljava/net/SocketImpl;", nullptr, 0, $virtualMethod(Socket, getImpl, $SocketImpl*), "java.net.SocketException"},
	{"getInetAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(Socket, getInetAddress, $InetAddress*)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(Socket, getInputStream, $InputStream*), "java.io.IOException"},
	{"getKeepAlive", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, getKeepAlive, bool), "java.net.SocketException"},
	{"getLocalAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(Socket, getLocalAddress, $InetAddress*)},
	{"getLocalPort", "()I", nullptr, $PUBLIC, $virtualMethod(Socket, getLocalPort, int32_t)},
	{"getLocalSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(Socket, getLocalSocketAddress, $SocketAddress*)},
	{"getOOBInline", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, getOOBInline, bool), "java.net.SocketException"},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PUBLIC, $virtualMethod(Socket, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(Socket, getOutputStream, $OutputStream*), "java.io.IOException"},
	{"getPort", "()I", nullptr, $PUBLIC, $virtualMethod(Socket, getPort, int32_t)},
	{"getReceiveBufferSize", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, getReceiveBufferSize, int32_t), "java.net.SocketException"},
	{"getRemoteSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(Socket, getRemoteSocketAddress, $SocketAddress*)},
	{"getReuseAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, getReuseAddress, bool), "java.net.SocketException"},
	{"getSendBufferSize", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, getSendBufferSize, int32_t), "java.net.SocketException"},
	{"getSoLinger", "()I", nullptr, $PUBLIC, $virtualMethod(Socket, getSoLinger, int32_t), "java.net.SocketException"},
	{"getSoTimeout", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, getSoTimeout, int32_t), "java.net.SocketException"},
	{"getTcpNoDelay", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, getTcpNoDelay, bool), "java.net.SocketException"},
	{"getTrafficClass", "()I", nullptr, $PUBLIC, $virtualMethod(Socket, getTrafficClass, int32_t), "java.net.SocketException"},
	{"isBound", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, isBound, bool)},
	{"isClosed", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, isClosed, bool)},
	{"isConnected", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, isConnected, bool)},
	{"isInputShutdown", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, isInputShutdown, bool)},
	{"isOutputShutdown", "()Z", nullptr, $PUBLIC, $virtualMethod(Socket, isOutputShutdown, bool)},
	{"postAccept", "()V", nullptr, $FINAL, $method(Socket, postAccept, void)},
	{"sendUrgentData", "(I)V", nullptr, $PUBLIC, $virtualMethod(Socket, sendUrgentData, void, int32_t), "java.io.IOException"},
	{"setImpl", "(Ljava/net/SocketImpl;)V", nullptr, 0, $virtualMethod(Socket, setImpl, void, $SocketImpl*)},
	{"setImpl", "()V", nullptr, 0, $virtualMethod(Socket, setImpl, void)},
	{"setKeepAlive", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Socket, setKeepAlive, void, bool), "java.net.SocketException"},
	{"setOOBInline", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Socket, setOOBInline, void, bool), "java.net.SocketException"},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)Ljava/net/Socket;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)Ljava/net/Socket;", $PUBLIC, $virtualMethod(Socket, setOption, Socket*, $SocketOption*, Object$*), "java.io.IOException"},
	{"setPerformancePreferences", "(III)V", nullptr, $PUBLIC, $virtualMethod(Socket, setPerformancePreferences, void, int32_t, int32_t, int32_t)},
	{"setReceiveBufferSize", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, setReceiveBufferSize, void, int32_t), "java.net.SocketException"},
	{"setReuseAddress", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Socket, setReuseAddress, void, bool), "java.net.SocketException"},
	{"setSendBufferSize", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, setSendBufferSize, void, int32_t), "java.net.SocketException"},
	{"setSoLinger", "(ZI)V", nullptr, $PUBLIC, $virtualMethod(Socket, setSoLinger, void, bool, int32_t), "java.net.SocketException"},
	{"setSoTimeout", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Socket, setSoTimeout, void, int32_t), "java.net.SocketException"},
	{"setSocketImplFactory", "(Ljava/net/SocketImplFactory;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED | $DEPRECATED, $staticMethod(Socket, setSocketImplFactory, void, $SocketImplFactory*), "java.io.IOException", nullptr, _Socket_MethodAnnotations_setSocketImplFactory55},
	{"setTcpNoDelay", "(Z)V", nullptr, $PUBLIC, $virtualMethod(Socket, setTcpNoDelay, void, bool), "java.net.SocketException"},
	{"setTrafficClass", "(I)V", nullptr, $PUBLIC, $virtualMethod(Socket, setTrafficClass, void, int32_t), "java.net.SocketException"},
	{"shutdownInput", "()V", nullptr, $PUBLIC, $virtualMethod(Socket, shutdownInput, void), "java.io.IOException"},
	{"shutdownOutput", "()V", nullptr, $PUBLIC, $virtualMethod(Socket, shutdownOutput, void), "java.io.IOException"},
	{"socketImplFactory", "()Ljava/net/SocketImplFactory;", nullptr, $STATIC, $staticMethod(Socket, socketImplFactory, $SocketImplFactory*)},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PUBLIC, $virtualMethod(Socket, supportedOptions, $Set*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Socket, toString, $String*)},
	{}
};

$InnerClassInfo _Socket_InnerClassesInfo_[] = {
	{"java.net.Socket$SocketOutputStream", "java.net.Socket", "SocketOutputStream", $PRIVATE | $STATIC},
	{"java.net.Socket$SocketInputStream", "java.net.Socket", "SocketInputStream", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Socket_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.Socket",
	"java.lang.Object",
	"java.io.Closeable",
	_Socket_FieldInfo_,
	_Socket_MethodInfo_,
	nullptr,
	nullptr,
	_Socket_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.Socket$SocketOutputStream,java.net.Socket$SocketInputStream"
};

$Object* allocate$Socket($Class* clazz) {
	return $of($alloc(Socket));
}

$VarHandle* Socket::IN = nullptr;
$VarHandle* Socket::OUT = nullptr;
$volatile($SocketImplFactory*) Socket::factory = nullptr;

void Socket::init$() {
	this->created = false;
	this->bound = false;
	this->connected = false;
	this->closed = false;
	$set(this, closeLock, $new($Object));
	this->shutIn = false;
	this->shutOut = false;
	setImpl();
}

void Socket::init$($Proxy* proxy) {
	$useLocalCurrentObjectStackCache();
	this->created = false;
	this->bound = false;
	this->connected = false;
	this->closed = false;
	$set(this, closeLock, $new($Object));
	this->shutIn = false;
	this->shutOut = false;
	if (proxy == nullptr) {
		$throwNew($IllegalArgumentException, "Invalid Proxy"_s);
	}
	$init($Proxy);
	$var($Proxy, p, proxy == $Proxy::NO_PROXY ? $Proxy::NO_PROXY : static_cast<$Proxy*>($ApplicationProxy::create(proxy)));
	$Proxy$Type* type = $nc(p)->type();
	$init($Proxy$Type);
	if (type == $Proxy$Type::SOCKS || type == $Proxy$Type::HTTP) {
		$var($SecurityManager, security, $System::getSecurityManager());
		$var($InetSocketAddress, epoint, $cast($InetSocketAddress, p->address()));
		if ($nc(epoint)->getAddress() != nullptr) {
			checkAddress($(epoint->getAddress()), "Socket"_s);
		}
		if (security != nullptr) {
			if ($nc(epoint)->isUnresolved()) {
				$var($String, var$0, epoint->getHostName());
				$assign(epoint, $new($InetSocketAddress, var$0, epoint->getPort()));
			}
			if ($nc(epoint)->isUnresolved()) {
				$var($String, var$1, epoint->getHostName());
				security->checkConnect(var$1, epoint->getPort());
			} else {
				$var($String, var$2, $nc($(epoint->getAddress()))->getHostAddress());
				security->checkConnect(var$2, epoint->getPort());
			}
		}
		$var($SocketImpl, delegate, $SocketImpl::createPlatformSocketImpl(false));
		$set(this, impl, (type == $Proxy$Type::SOCKS) ? static_cast<$SocketImpl*>($new($SocksSocketImpl, p, delegate)) : static_cast<$SocketImpl*>($new($HttpConnectSocketImpl, p, delegate, this)));
	} else {
		if (p == $Proxy::NO_PROXY) {
			$var($SocketImplFactory, factory, Socket::factory);
			if (factory == nullptr) {
				$set(this, impl, $SocketImpl::createPlatformSocketImpl(false));
			} else {
				$set(this, impl, $nc(factory)->createSocketImpl());
			}
		} else {
			$throwNew($IllegalArgumentException, "Invalid Proxy"_s);
		}
	}
}

void Socket::init$($SocketImpl* impl) {
	this->created = false;
	this->bound = false;
	this->connected = false;
	this->closed = false;
	$set(this, closeLock, $new($Object));
	this->shutIn = false;
	this->shutOut = false;
	checkPermission(impl);
	$set(this, impl, impl);
}

$Void* Socket::checkPermission($SocketImpl* impl) {
	$init(Socket);
	if (impl == nullptr) {
		return nullptr;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::SET_SOCKETIMPL_PERMISSION);
	}
	return nullptr;
}

void Socket::init$($String* host, int32_t port) {
	$useLocalCurrentObjectStackCache();
	Socket::init$(host != nullptr ? static_cast<$SocketAddress*>($$new($InetSocketAddress, host, port)) : static_cast<$SocketAddress*>($$new($InetSocketAddress, $($InetAddress::getByName(nullptr)), port)), ($SocketAddress*)nullptr, true);
}

void Socket::init$($InetAddress* address, int32_t port) {
	Socket::init$(address != nullptr ? static_cast<$SocketAddress*>($$new($InetSocketAddress, address, port)) : ($SocketAddress*)nullptr, ($SocketAddress*)nullptr, true);
}

void Socket::init$($String* host, int32_t port, $InetAddress* localAddr, int32_t localPort) {
	$useLocalCurrentObjectStackCache();
	$var($SocketAddress, var$0, host != nullptr ? static_cast<$SocketAddress*>($new($InetSocketAddress, host, port)) : static_cast<$SocketAddress*>($new($InetSocketAddress, $($InetAddress::getByName(nullptr)), port)));
	Socket::init$(var$0, static_cast<$SocketAddress*>($$new($InetSocketAddress, localAddr, localPort)), true);
}

void Socket::init$($InetAddress* address, int32_t port, $InetAddress* localAddr, int32_t localPort) {
	$useLocalCurrentObjectStackCache();
	$var($SocketAddress, var$0, address != nullptr ? static_cast<$SocketAddress*>($new($InetSocketAddress, address, port)) : ($SocketAddress*)nullptr);
	Socket::init$(var$0, static_cast<$SocketAddress*>($$new($InetSocketAddress, localAddr, localPort)), true);
}

void Socket::init$($String* host, int32_t port, bool stream) {
	$useLocalCurrentObjectStackCache();
	Socket::init$(host != nullptr ? static_cast<$SocketAddress*>($$new($InetSocketAddress, host, port)) : static_cast<$SocketAddress*>($$new($InetSocketAddress, $($InetAddress::getByName(nullptr)), port)), ($SocketAddress*)nullptr, stream);
}

void Socket::init$($InetAddress* host, int32_t port, bool stream) {
	$useLocalCurrentObjectStackCache();
	$var($SocketAddress, var$0, host != nullptr ? static_cast<$SocketAddress*>($new($InetSocketAddress, host, port)) : ($SocketAddress*)nullptr);
	Socket::init$(var$0, static_cast<$SocketAddress*>($$new($InetSocketAddress, 0)), stream);
}

void Socket::init$($SocketAddress* address, $SocketAddress* localAddr, bool stream) {
	this->created = false;
	this->bound = false;
	this->connected = false;
	this->closed = false;
	$set(this, closeLock, $new($Object));
	this->shutIn = false;
	this->shutOut = false;
	setImpl();
	if (address == nullptr) {
		$throwNew($NullPointerException);
	}
	try {
		createImpl(stream);
		if (localAddr != nullptr) {
			bind(localAddr);
		}
		connect(address);
	} catch ($IOException& e) {
		try {
			close();
		} catch ($IOException& ce) {
			e->addSuppressed(ce);
		}
		$throw(e);
	} catch ($IllegalArgumentException& e) {
		try {
			close();
		} catch ($IOException& ce) {
			e->addSuppressed(ce);
		}
		$throw(e);
	} catch ($SecurityException& e) {
		try {
			close();
		} catch ($IOException& ce) {
			e->addSuppressed(ce);
		}
		$throw(e);
	}
}

void Socket::createImpl(bool stream) {
	if (this->impl == nullptr) {
		setImpl();
	}
	try {
		$nc(this->impl)->create(stream);
		this->created = true;
	} catch ($IOException& e) {
		$throwNew($SocketException, $(e->getMessage()));
	}
}

void Socket::setImpl($SocketImpl* si) {
	$set(this, impl, si);
}

void Socket::setImpl() {
	$useLocalCurrentObjectStackCache();
	$var($SocketImplFactory, factory, Socket::factory);
	if (factory != nullptr) {
		$set(this, impl, factory->createSocketImpl());
	} else {
		$var($SocketImpl, delegate, $SocketImpl::createPlatformSocketImpl(false));
		$set(this, impl, $new($SocksSocketImpl, delegate));
	}
}

$SocketImpl* Socket::getImpl() {
	if (!this->created) {
		createImpl(true);
	}
	return this->impl;
}

void Socket::connect($SocketAddress* endpoint) {
	connect(endpoint, 0);
}

void Socket::connect($SocketAddress* endpoint, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	if (endpoint == nullptr) {
		$throwNew($IllegalArgumentException, "connect: The address can\'t be null"_s);
	}
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "connect: timeout can\'t be negative"_s);
	}
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (isConnected()) {
		$throwNew($SocketException, "already connected"_s);
	}
	$var($InetSocketAddress, epoint, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, endpoint);
	if (var$0) {
		$assign(epoint, $cast($InetSocketAddress, endpoint));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	$var($InetAddress, addr, $nc(epoint)->getAddress());
	int32_t port = epoint->getPort();
	checkAddress(addr, "connect"_s);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		if (epoint->isUnresolved()) {
			security->checkConnect($(epoint->getHostName()), port);
		} else {
			security->checkConnect($($nc(addr)->getHostAddress()), port);
		}
	}
	if (!this->created) {
		createImpl(true);
	}
	$nc(this->impl)->connect(static_cast<$SocketAddress*>(epoint), timeout);
	this->connected = true;
	this->bound = true;
}

void Socket::bind($SocketAddress* bindpoint) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (isBound()) {
		$throwNew($SocketException, "Already bound"_s);
	}
	if (bindpoint != nullptr && (!($instanceOf($InetSocketAddress, bindpoint)))) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	$var($InetSocketAddress, epoint, $cast($InetSocketAddress, bindpoint));
	if (epoint != nullptr && epoint->isUnresolved()) {
		$throwNew($SocketException, "Unresolved address"_s);
	}
	if (epoint == nullptr) {
		$assign(epoint, $new($InetSocketAddress, 0));
	}
	$var($InetAddress, addr, $nc(epoint)->getAddress());
	int32_t port = epoint->getPort();
	checkAddress(addr, "bind"_s);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkListen(port);
	}
	$nc($(getImpl()))->bind(addr, port);
	this->bound = true;
}

void Socket::checkAddress($InetAddress* addr, $String* op) {
	if (addr == nullptr) {
		return;
	}
	if (!($instanceOf($Inet4Address, addr) || $instanceOf($Inet6Address, addr))) {
		$throwNew($IllegalArgumentException, $$str({op, ": invalid address type"_s}));
	}
}

void Socket::postAccept() {
	this->connected = true;
	this->created = true;
	this->bound = true;
}

$InetAddress* Socket::getInetAddress() {
	if (!isConnected()) {
		return nullptr;
	}
	try {
		return $nc($(getImpl()))->getInetAddress();
	} catch ($SocketException& e) {
	}
	return nullptr;
}

$InetAddress* Socket::getLocalAddress() {
	$useLocalCurrentObjectStackCache();
	if (!isBound()) {
		return $InetAddress::anyLocalAddress();
	}
	$var($InetAddress, in, nullptr);
	try {
		$assign(in, $cast($InetAddress, $nc($(getImpl()))->getOption($SocketOptions::SO_BINDADDR)));
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkConnect($($nc(in)->getHostAddress()), -1);
		}
		if ($nc(in)->isAnyLocalAddress()) {
			$assign(in, $InetAddress::anyLocalAddress());
		}
	} catch ($SecurityException& e) {
		$assign(in, $InetAddress::getLoopbackAddress());
	} catch ($Exception& e) {
		$assign(in, $InetAddress::anyLocalAddress());
	}
	return in;
}

int32_t Socket::getPort() {
	if (!isConnected()) {
		return 0;
	}
	try {
		return $nc($(getImpl()))->getPort();
	} catch ($SocketException& e) {
	}
	return -1;
}

int32_t Socket::getLocalPort() {
	if (!isBound()) {
		return -1;
	}
	try {
		return $nc($(getImpl()))->getLocalPort();
	} catch ($SocketException& e) {
	}
	return -1;
}

$SocketAddress* Socket::getRemoteSocketAddress() {
	if (!isConnected()) {
		return nullptr;
	}
	$var($InetAddress, var$0, getInetAddress());
	return $new($InetSocketAddress, var$0, getPort());
}

$SocketAddress* Socket::getLocalSocketAddress() {
	if (!isBound()) {
		return nullptr;
	}
	$var($InetAddress, var$0, getLocalAddress());
	return $new($InetSocketAddress, var$0, getLocalPort());
}

$SocketChannel* Socket::getChannel() {
	return nullptr;
}

$InputStream* Socket::getInputStream() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (!isConnected()) {
		$throwNew($SocketException, "Socket is not connected"_s);
	}
	if (isInputShutdown()) {
		$throwNew($SocketException, "Socket input is shutdown"_s);
	}
	$var($InputStream, in, this->in);
	if (in == nullptr) {
		$assign(in, $new($Socket$SocketInputStream, this, $($nc(this->impl)->getInputStream())));
		if (!$nc(Socket::IN)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(in)}))) {
			$assign(in, this->in);
		}
	}
	return in;
}

$OutputStream* Socket::getOutputStream() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (!isConnected()) {
		$throwNew($SocketException, "Socket is not connected"_s);
	}
	if (isOutputShutdown()) {
		$throwNew($SocketException, "Socket output is shutdown"_s);
	}
	$var($OutputStream, out, this->out);
	if (out == nullptr) {
		$assign(out, $new($Socket$SocketOutputStream, this, $($nc(this->impl)->getOutputStream())));
		if (!$nc(Socket::OUT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(out)}))) {
			$assign(out, this->out);
		}
	}
	return out;
}

void Socket::setTcpNoDelay(bool on) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$nc($(getImpl()))->setOption($SocketOptions::TCP_NODELAY, $($Boolean::valueOf(on)));
}

bool Socket::getTcpNoDelay() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	return $nc(($cast($Boolean, $($nc($(getImpl()))->getOption($SocketOptions::TCP_NODELAY)))))->booleanValue();
}

void Socket::setSoLinger(bool on, int32_t linger) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (!on) {
		$nc($(getImpl()))->setOption($SocketOptions::SO_LINGER, $($Boolean::valueOf(on)));
	} else {
		if (linger < 0) {
			$throwNew($IllegalArgumentException, "invalid value for SO_LINGER"_s);
		}
		if (linger > 0x0000FFFF) {
			linger = 0x0000FFFF;
		}
		$nc($(getImpl()))->setOption($SocketOptions::SO_LINGER, $($Integer::valueOf(linger)));
	}
}

int32_t Socket::getSoLinger() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$var($Object, o, $nc($(getImpl()))->getOption($SocketOptions::SO_LINGER));
	if ($instanceOf($Integer, o)) {
		return $nc(($cast($Integer, o)))->intValue();
	} else {
		return -1;
	}
}

void Socket::sendUrgentData(int32_t data) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($(getImpl()))->supportsUrgentData()) {
		$throwNew($SocketException, "Urgent data not supported"_s);
	}
	$nc($(getImpl()))->sendUrgentData(data);
}

void Socket::setOOBInline(bool on) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$nc($(getImpl()))->setOption($SocketOptions::SO_OOBINLINE, $($Boolean::valueOf(on)));
}

bool Socket::getOOBInline() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	return $nc(($cast($Boolean, $($nc($(getImpl()))->getOption($SocketOptions::SO_OOBINLINE)))))->booleanValue();
}

void Socket::setSoTimeout(int32_t timeout) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (isClosed()) {
			$throwNew($SocketException, "Socket is closed"_s);
		}
		if (timeout < 0) {
			$throwNew($IllegalArgumentException, "timeout can\'t be negative"_s);
		}
		$nc($(getImpl()))->setOption($SocketOptions::SO_TIMEOUT, $($Integer::valueOf(timeout)));
	}
}

int32_t Socket::getSoTimeout() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (isClosed()) {
			$throwNew($SocketException, "Socket is closed"_s);
		}
		$var($Object, o, $nc($(getImpl()))->getOption($SocketOptions::SO_TIMEOUT));
		if ($instanceOf($Integer, o)) {
			return $nc(($cast($Integer, o)))->intValue();
		} else {
			return 0;
		}
	}
}

void Socket::setSendBufferSize(int32_t size) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (!(size > 0)) {
			$throwNew($IllegalArgumentException, "negative send size"_s);
		}
		if (isClosed()) {
			$throwNew($SocketException, "Socket is closed"_s);
		}
		$nc($(getImpl()))->setOption($SocketOptions::SO_SNDBUF, $($Integer::valueOf(size)));
	}
}

int32_t Socket::getSendBufferSize() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (isClosed()) {
			$throwNew($SocketException, "Socket is closed"_s);
		}
		int32_t result = 0;
		$var($Object, o, $nc($(getImpl()))->getOption($SocketOptions::SO_SNDBUF));
		if ($instanceOf($Integer, o)) {
			result = $nc(($cast($Integer, o)))->intValue();
		}
		return result;
	}
}

void Socket::setReceiveBufferSize(int32_t size) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (size <= 0) {
			$throwNew($IllegalArgumentException, "invalid receive size"_s);
		}
		if (isClosed()) {
			$throwNew($SocketException, "Socket is closed"_s);
		}
		$nc($(getImpl()))->setOption($SocketOptions::SO_RCVBUF, $($Integer::valueOf(size)));
	}
}

int32_t Socket::getReceiveBufferSize() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (isClosed()) {
			$throwNew($SocketException, "Socket is closed"_s);
		}
		int32_t result = 0;
		$var($Object, o, $nc($(getImpl()))->getOption($SocketOptions::SO_RCVBUF));
		if ($instanceOf($Integer, o)) {
			result = $nc(($cast($Integer, o)))->intValue();
		}
		return result;
	}
}

void Socket::setKeepAlive(bool on) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$nc($(getImpl()))->setOption($SocketOptions::SO_KEEPALIVE, $($Boolean::valueOf(on)));
}

bool Socket::getKeepAlive() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	return $nc(($cast($Boolean, $($nc($(getImpl()))->getOption($SocketOptions::SO_KEEPALIVE)))))->booleanValue();
}

void Socket::setTrafficClass(int32_t tc) {
	$useLocalCurrentObjectStackCache();
	if (tc < 0 || tc > 255) {
		$throwNew($IllegalArgumentException, "tc is not in range 0 -- 255"_s);
	}
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	try {
		$nc($(getImpl()))->setOption($SocketOptions::IP_TOS, $($Integer::valueOf(tc)));
	} catch ($SocketException& se) {
		if (!isConnected()) {
			$throw(se);
		}
	}
}

int32_t Socket::getTrafficClass() {
	$useLocalCurrentObjectStackCache();
	return $nc((($cast($Integer, $($nc($(getImpl()))->getOption($SocketOptions::IP_TOS))))))->intValue();
}

void Socket::setReuseAddress(bool on) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$nc($(getImpl()))->setOption($SocketOptions::SO_REUSEADDR, $($Boolean::valueOf(on)));
}

bool Socket::getReuseAddress() {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	return $nc((($cast($Boolean, $($nc($(getImpl()))->getOption($SocketOptions::SO_REUSEADDR))))))->booleanValue();
}

void Socket::close() {
	$synchronized(this) {
		$synchronized(this->closeLock) {
			if (isClosed()) {
				return;
			}
			if (this->created) {
				$nc(this->impl)->close();
			}
			this->closed = true;
		}
	}
}

void Socket::shutdownInput() {
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (!isConnected()) {
		$throwNew($SocketException, "Socket is not connected"_s);
	}
	if (isInputShutdown()) {
		$throwNew($SocketException, "Socket input is already shutdown"_s);
	}
	$nc($(getImpl()))->shutdownInput();
	this->shutIn = true;
}

void Socket::shutdownOutput() {
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	if (!isConnected()) {
		$throwNew($SocketException, "Socket is not connected"_s);
	}
	if (isOutputShutdown()) {
		$throwNew($SocketException, "Socket output is already shutdown"_s);
	}
	$nc($(getImpl()))->shutdownOutput();
	this->shutOut = true;
}

$String* Socket::toString() {
	$useLocalCurrentObjectStackCache();
	try {
		if (isConnected()) {
			$var($String, var$3, $$str({"Socket[addr="_s, $($nc($(getImpl()))->getInetAddress()), ",port="_s}));
			$var($String, var$2, $$concat(var$3, $$str($nc($(getImpl()))->getPort())));
			$var($String, var$1, $$concat(var$2, ",localport="_s));
			$var($String, var$0, $$concat(var$1, $$str($nc($(getImpl()))->getLocalPort())));
			return $concat(var$0, "]"_s);
		}
	} catch ($SocketException& e) {
	}
	return "Socket[unconnected]"_s;
}

bool Socket::isConnected() {
	return this->connected;
}

bool Socket::isBound() {
	return this->bound;
}

bool Socket::isClosed() {
	$synchronized(this->closeLock) {
		return this->closed;
	}
}

bool Socket::isInputShutdown() {
	return this->shutIn;
}

bool Socket::isOutputShutdown() {
	return this->shutOut;
}

$SocketImplFactory* Socket::socketImplFactory() {
	$init(Socket);
	return Socket::factory;
}

void Socket::setSocketImplFactory($SocketImplFactory* fac) {
	$load(Socket);
	$synchronized(class$) {
		$init(Socket);
		if (Socket::factory != nullptr) {
			$throwNew($SocketException, "factory already defined"_s);
		}
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			security->checkSetFactory();
		}
		$assignStatic(Socket::factory, fac);
	}
}

void Socket::setPerformancePreferences(int32_t connectionTime, int32_t latency, int32_t bandwidth) {
}

Socket* Socket::setOption($SocketOption* name, Object$* value) {
	$Objects::requireNonNull(name);
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	$nc($(getImpl()))->setOption(name, value);
	return this;
}

$Object* Socket::getOption($SocketOption* name) {
	$Objects::requireNonNull(name);
	if (isClosed()) {
		$throwNew($SocketException, "Socket is closed"_s);
	}
	return $of($nc($(getImpl()))->getOption(name));
}

$Set* Socket::supportedOptions() {
	$useLocalCurrentObjectStackCache();
	$var($Set, so, this->options);
	if (so != nullptr) {
		return so;
	}
	try {
		$var($SocketImpl, impl, getImpl());
		$set(this, options, $Collections::unmodifiableSet($($nc(impl)->supportedOptions())));
	} catch ($IOException& e) {
		$set(this, options, $Collections::emptySet());
	}
	return this->options;
}

void clinit$Socket($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$load($InputStream);
			$assignStatic(Socket::IN, $nc(l)->findVarHandle(Socket::class$, "in"_s, $InputStream::class$));
			$load($OutputStream);
			$assignStatic(Socket::OUT, l->findVarHandle(Socket::class$, "out"_s, $OutputStream::class$));
		} catch ($Exception& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
}

Socket::Socket() {
}

$Class* Socket::load$($String* name, bool initialize) {
	$loadClass(Socket, name, initialize, &_Socket_ClassInfo_, clinit$Socket, allocate$Socket);
	return class$;
}

$Class* Socket::class$ = nullptr;

	} // net
} // java