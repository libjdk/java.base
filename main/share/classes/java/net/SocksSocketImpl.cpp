#include <java/net/SocksSocketImpl.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/net/DelegatingSocketImpl.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/PasswordAuthentication.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ProxySelector.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketImpl.h>
#include <java/net/SocketOptions.h>
#include <java/net/SocketTimeoutException.h>
#include <java/net/SocksConsts.h>
#include <java/net/SocksSocketImpl$1.h>
#include <java/net/SocksSocketImpl$2.h>
#include <java/net/SocksSocketImpl$3.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/net/SocksProxy.h>
#include <sun/net/spi/DefaultProxySelector.h>
#include <sun/net/www/ParseUtil.h>
#include <jcpp.h>

#undef ADDR_TYPE_NOT_SUP
#undef CMD_NOT_SUPPORTED
#undef CONNECT
#undef CONN_REFUSED
#undef DEFAULT_PORT
#undef DOMAIN_NAME
#undef GENERAL_FAILURE
#undef HOST_UNREACHABLE
#undef IPV4
#undef IPV6
#undef MAX_VALUE
#undef NET_UNREACHABLE
#undef NOT_ALLOWED
#undef NO_AUTH
#undef NO_METHODS
#undef PROTO_VERS
#undef PROTO_VERS4
#undef REQUEST_OK
#undef SOCKS
#undef SO_TIMEOUT
#undef TTL_EXPIRED
#undef USER_PASSW

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $DelegatingSocketImpl = ::java::net::DelegatingSocketImpl;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $PasswordAuthentication = ::java::net::PasswordAuthentication;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ProxySelector = ::java::net::ProxySelector;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketImpl = ::java::net::SocketImpl;
using $SocketOptions = ::java::net::SocketOptions;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $SocksConsts = ::java::net::SocksConsts;
using $SocksSocketImpl$1 = ::java::net::SocksSocketImpl$1;
using $SocksSocketImpl$2 = ::java::net::SocksSocketImpl$2;
using $SocksSocketImpl$3 = ::java::net::SocksSocketImpl$3;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $UnknownHostException = ::java::net::UnknownHostException;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $SocksProxy = ::sun::net::SocksProxy;
using $DefaultProxySelector = ::sun::net::spi::DefaultProxySelector;
using $ParseUtil = ::sun::net::www::ParseUtil;

namespace java {
	namespace net {

$FieldInfo _SocksSocketImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocksSocketImpl, $assertionsDisabled)},
	{"server", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SocksSocketImpl, server)},
	{"serverPort", "I", nullptr, $PRIVATE, $field(SocksSocketImpl, serverPort)},
	{"external_address", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(SocksSocketImpl, external_address)},
	{"useV4", "Z", nullptr, $PRIVATE, $field(SocksSocketImpl, useV4$)},
	{"cmdsock", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(SocksSocketImpl, cmdsock)},
	{"cmdIn", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(SocksSocketImpl, cmdIn)},
	{"cmdOut", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(SocksSocketImpl, cmdOut)},
	{}
};

$MethodInfo _SocksSocketImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/net/SocketImpl;)V", nullptr, 0, $method(SocksSocketImpl, init$, void, $SocketImpl*)},
	{"<init>", "(Ljava/net/Proxy;Ljava/net/SocketImpl;)V", nullptr, 0, $method(SocksSocketImpl, init$, void, $Proxy*, $SocketImpl*)},
	{"accept", "(Ljava/net/SocketImpl;)V", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, accept, void, $SocketImpl*)},
	{"authenticate", "(BLjava/io/InputStream;Ljava/io/BufferedOutputStream;J)Z", nullptr, $PRIVATE, $method(SocksSocketImpl, authenticate, bool, int8_t, $InputStream*, $BufferedOutputStream*, int64_t), "java.io.IOException"},
	{"close", "()V", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, close, void), "java.io.IOException"},
	{"connect", "(Ljava/lang/String;I)V", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, connect, void, $String*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, connect, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)V", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, connect, void, $SocketAddress*, int32_t), "java.io.IOException"},
	{"connectV4", "(Ljava/io/InputStream;Ljava/io/OutputStream;Ljava/net/InetSocketAddress;J)V", nullptr, $PRIVATE, $method(SocksSocketImpl, connectV4, void, $InputStream*, $OutputStream*, $InetSocketAddress*, int64_t), "java.io.IOException"},
	{"getInetAddress", "()Ljava/net/InetAddress;", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, getInetAddress, $InetAddress*)},
	{"getPort", "()I", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, getPort, int32_t)},
	{"getUserName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(SocksSocketImpl, getUserName, $String*)},
	{"listen", "(I)V", nullptr, $PROTECTED, $virtualMethod(SocksSocketImpl, listen, void, int32_t)},
	{"privilegedConnect", "(Ljava/lang/String;II)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(SocksSocketImpl, privilegedConnect, void, $String*, int32_t, int32_t), "java.io.IOException"},
	{"readSocksReply", "(Ljava/io/InputStream;[BJ)I", nullptr, $PRIVATE, $method(SocksSocketImpl, readSocksReply, int32_t, $InputStream*, $bytes*, int64_t), "java.io.IOException"},
	{"remainingMillis", "(J)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SocksSocketImpl, remainingMillis, int32_t, int64_t), "java.io.IOException"},
	{"reset", "()V", nullptr, 0, $virtualMethod(SocksSocketImpl, reset, void)},
	{"superConnectServer", "(Ljava/lang/String;II)V", nullptr, $PRIVATE, $method(SocksSocketImpl, superConnectServer, void, $String*, int32_t, int32_t), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"useV4", "(Ljava/net/Proxy;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(SocksSocketImpl, useV4, bool, $Proxy*)},
	{}
};

$InnerClassInfo _SocksSocketImpl_InnerClassesInfo_[] = {
	{"java.net.SocksSocketImpl$3", nullptr, nullptr, 0},
	{"java.net.SocksSocketImpl$2", nullptr, nullptr, 0},
	{"java.net.SocksSocketImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SocksSocketImpl_ClassInfo_ = {
	$ACC_SUPER,
	"java.net.SocksSocketImpl",
	"java.net.DelegatingSocketImpl",
	"java.net.SocksConsts",
	_SocksSocketImpl_FieldInfo_,
	_SocksSocketImpl_MethodInfo_,
	nullptr,
	nullptr,
	_SocksSocketImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.SocksSocketImpl$3,java.net.SocksSocketImpl$2,java.net.SocksSocketImpl$1"
};

$Object* allocate$SocksSocketImpl($Class* clazz) {
	return $of($alloc(SocksSocketImpl));
}

$String* SocksSocketImpl::toString() {
	 return this->$DelegatingSocketImpl::toString();
}

int32_t SocksSocketImpl::hashCode() {
	 return this->$DelegatingSocketImpl::hashCode();
}

bool SocksSocketImpl::equals(Object$* obj) {
	 return this->$DelegatingSocketImpl::equals(obj);
}

$Object* SocksSocketImpl::clone() {
	 return this->$DelegatingSocketImpl::clone();
}

void SocksSocketImpl::finalize() {
	this->$DelegatingSocketImpl::finalize();
}

bool SocksSocketImpl::$assertionsDisabled = false;

void SocksSocketImpl::init$($SocketImpl* delegate) {
	$DelegatingSocketImpl::init$(delegate);
	$set(this, server, nullptr);
	this->serverPort = $SocksConsts::DEFAULT_PORT;
	this->useV4$ = false;
	$set(this, cmdsock, nullptr);
	$set(this, cmdIn, nullptr);
	$set(this, cmdOut, nullptr);
}

void SocksSocketImpl::init$($Proxy* proxy, $SocketImpl* delegate) {
	$useLocalCurrentObjectStackCache();
	$DelegatingSocketImpl::init$(delegate);
	$set(this, server, nullptr);
	this->serverPort = $SocksConsts::DEFAULT_PORT;
	this->useV4$ = false;
	$set(this, cmdsock, nullptr);
	$set(this, cmdIn, nullptr);
	$set(this, cmdOut, nullptr);
	$var($SocketAddress, a, $nc(proxy)->address());
	{
		$var($InetSocketAddress, ad, nullptr);
		bool var$0 = $instanceOf($InetSocketAddress, a);
		if (var$0) {
			$assign(ad, $cast($InetSocketAddress, a));
			var$0 = true;
		}
		if (var$0) {
			$set(this, server, $nc(ad)->getHostString());
			this->serverPort = ad->getPort();
		}
	}
	this->useV4$ = useV4(proxy);
}

bool SocksSocketImpl::useV4($Proxy* proxy) {
	$init(SocksSocketImpl);
	if ($instanceOf($SocksProxy, proxy) && $nc(($cast($SocksProxy, proxy)))->protocolVersion() == 4) {
		return true;
	}
	return $DefaultProxySelector::socksProxyVersion() == 4;
}

void SocksSocketImpl::privilegedConnect($String* host, int32_t port, int32_t timeout) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		try {
			$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($SocksSocketImpl$1, this, host, port, timeout)));
		} catch ($PrivilegedActionException& pae) {
			$throw($cast($IOException, $(pae->getException())));
		}
	}
}

void SocksSocketImpl::superConnectServer($String* host, int32_t port, int32_t timeout) {
	$nc(this->delegate$)->connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, host, port)), timeout);
}

int32_t SocksSocketImpl::remainingMillis(int64_t deadlineMillis) {
	$init(SocksSocketImpl);
	if (deadlineMillis == (int64_t)0) {
		return 0;
	}
	int64_t remaining = deadlineMillis - $System::currentTimeMillis();
	if (remaining > 0) {
		return (int32_t)remaining;
	}
	$throwNew($SocketTimeoutException);
}

int32_t SocksSocketImpl::readSocksReply($InputStream* in, $bytes* data, int64_t deadlineMillis) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(data)->length;
	int32_t received = 0;
	int32_t originalTimeout = $nc(($cast($Integer, $(getOption($SocketOptions::SO_TIMEOUT)))))->intValue();
	{
		$var($Throwable, var$0, nullptr);
		try {
			while (received < len) {
				int32_t count = 0;
				int32_t remaining = remainingMillis(deadlineMillis);
				setOption($SocketOptions::SO_TIMEOUT, $($of($Integer::valueOf(remaining))));
				try {
					count = $nc(in)->read(data, received, len - received);
				} catch ($SocketTimeoutException& e) {
					$throwNew($SocketTimeoutException, "Connect timed out"_s);
				}
				if (count < 0) {
					$throwNew($SocketException, "Malformed reply from SOCKS server"_s);
				}
				received += count;
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			setOption($SocketOptions::SO_TIMEOUT, $($of($Integer::valueOf(originalTimeout))));
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return received;
}

bool SocksSocketImpl::authenticate(int8_t method, $InputStream* in, $BufferedOutputStream* out, int64_t deadlineMillis) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (method == $SocksConsts::NO_AUTH) {
		return true;
	}
	if (method == $SocksConsts::USER_PASSW) {
		$var($String, userName, nullptr);
		$var($String, password, nullptr);
		$var($InetAddress, addr, $InetAddress::getByName(this->server));
		$var($PasswordAuthentication, pw, $cast($PasswordAuthentication, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SocksSocketImpl$2, this, addr)))));
		if (pw != nullptr) {
			$assign(userName, pw->getUserName());
			$assign(password, $new($String, $(pw->getPassword())));
		} else {
			$assign(userName, $StaticProperty::userName());
		}
		if (userName == nullptr) {
			return false;
		}
		$nc(out)->write(1);
		out->write($nc(userName)->length());
		$init($StandardCharsets);
		out->write($($nc(userName)->getBytes($StandardCharsets::ISO_8859_1)));
		if (password != nullptr) {
			out->write(password->length());
			out->write($(password->getBytes($StandardCharsets::ISO_8859_1)));
		} else {
			out->write(0);
		}
		out->flush();
		$var($bytes, data, $new($bytes, 2));
		int32_t i = readSocksReply(in, data, deadlineMillis);
		if (i != 2 || data->get(1) != 0) {
			out->close();
			$nc(in)->close();
			return false;
		}
		return true;
	}
	return false;
}

void SocksSocketImpl::connectV4($InputStream* in, $OutputStream* out, $InetSocketAddress* endpoint, int64_t deadlineMillis) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($Inet4Address, $($nc(endpoint)->getAddress())))) {
		$throwNew($SocketException, "SOCKS V4 requires IPv4 only addresses"_s);
	}
	$nc(out)->write($SocksConsts::PROTO_VERS4);
	out->write($SocksConsts::CONNECT);
	out->write((int32_t)(($nc(endpoint)->getPort() >> 8) & (uint32_t)255));
	out->write((int32_t)(($nc(endpoint)->getPort() >> 0) & (uint32_t)255));
	out->write($($nc($($nc(endpoint)->getAddress()))->getAddress()));
	$var($String, userName, getUserName());
	$init($StandardCharsets);
	out->write($($nc(userName)->getBytes($StandardCharsets::ISO_8859_1)));
	out->write(0);
	out->flush();
	$var($bytes, data, $new($bytes, 8));
	int32_t n = readSocksReply(in, data, deadlineMillis);
	if (n != 8) {
		$throwNew($SocketException, $$str({"Reply from SOCKS server has bad length: "_s, $$str(n)}));
	}
	if (data->get(0) != 0 && data->get(0) != 4) {
		$throwNew($SocketException, "Reply from SOCKS server has bad version"_s);
	}

	$var($SocketException, var$0, nullptr)
	switch (data->get(1)) {
	case 90:
		{
			{
				$set(this, external_address, endpoint);
				$assign(var$0, nullptr);
				break;
			}
		}
	case 91:
		{
			$assign(var$0, $new($SocketException, "SOCKS request rejected"_s));
			break;
		}
	case 92:
		{
			$assign(var$0, $new($SocketException, "SOCKS server couldn\'t reach destination"_s));
			break;
		}
	case 93:
		{
			$assign(var$0, $new($SocketException, "SOCKS authentication failed"_s));
			break;
		}
	default:
		{
			$assign(var$0, $new($SocketException, "Reply from SOCKS server contains bad status"_s));
			break;
		}
	}
	$var($SocketException, ex, var$0);
	if (ex != nullptr) {
		$nc(in)->close();
		out->close();
		$throw(ex);
	}
}

void SocksSocketImpl::connect($String* host, int32_t port) {
	connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, host, port)), 0);
}

void SocksSocketImpl::connect($InetAddress* address, int32_t port) {
	connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, address, port)), 0);
}

void SocksSocketImpl::connect($SocketAddress* endpoint, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int64_t deadlineMillis = 0;
	if (timeout == 0) {
		deadlineMillis = 0;
	} else {
		int64_t finish = $System::currentTimeMillis() + timeout;
		deadlineMillis = finish < 0 ? $Long::MAX_VALUE : finish;
	}
	$var($SecurityManager, security, $System::getSecurityManager());
	$var($InetSocketAddress, epoint, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, endpoint);
	if (var$0) {
		$assign(epoint, $cast($InetSocketAddress, endpoint));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	if (security != nullptr) {
		if ($nc(epoint)->isUnresolved()) {
			$var($String, var$1, epoint->getHostName());
			security->checkConnect(var$1, epoint->getPort());
		} else {
			$var($String, var$2, $nc($(epoint->getAddress()))->getHostAddress());
			security->checkConnect(var$2, epoint->getPort());
		}
	}
	if (this->server == nullptr) {
		$var($ProxySelector, sel, $cast($ProxySelector, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SocksSocketImpl$3, this)))));
		if (sel == nullptr) {
			$nc(this->delegate$)->connect(static_cast<$SocketAddress*>(epoint), remainingMillis(deadlineMillis));
			return;
		}
		$var($URI, uri, nullptr);
		$var($String, host, $nc(epoint)->getHostString());
		bool var$4 = $instanceOf($Inet6Address, $(epoint->getAddress()));
		bool var$3 = var$4 && (!$nc(host)->startsWith("["_s));
		if (var$3 && (host->indexOf((int32_t)u':') >= 0)) {
			$assign(host, $str({"["_s, host, "]"_s}));
		}
		try {
			$var($String, var$5, $$str({"socket://"_s, $($ParseUtil::encodePath(host)), ":"_s}));
			$assign(uri, $new($URI, $$concat(var$5, $$str(epoint->getPort()))));
		} catch ($URISyntaxException& e) {
			if (!SocksSocketImpl::$assertionsDisabled) {
				$throwNew($AssertionError, $of(e));
			}
			$assign(uri, nullptr);
		}
		$var($Proxy, p, nullptr);
		$var($IOException, savedExc, nullptr);
		$var($Iterator, iProxy, nullptr);
		try {
			$assign(iProxy, $nc($($nc(sel)->select(uri)))->iterator());
		} catch ($IllegalArgumentException& iae) {
			$throwNew($IOException, "Failed to select a proxy"_s, iae);
		}
		if (iProxy == nullptr || !($nc(iProxy)->hasNext())) {
			$nc(this->delegate$)->connect(static_cast<$SocketAddress*>(epoint), remainingMillis(deadlineMillis));
			return;
		}
		while ($nc(iProxy)->hasNext()) {
			$assign(p, $cast($Proxy, iProxy->next()));
			$init($Proxy$Type);
			if (p == nullptr || $nc(p)->type() != $Proxy$Type::SOCKS) {
				$nc(this->delegate$)->connect(static_cast<$SocketAddress*>(epoint), remainingMillis(deadlineMillis));
				return;
			}
			if (!($instanceOf($InetSocketAddress, $($nc(p)->address())))) {
				$throwNew($SocketException, $$str({"Unknown address type for proxy: "_s, p}));
			}
			$set(this, server, $nc(($cast($InetSocketAddress, $($nc(p)->address()))))->getHostString());
			this->serverPort = $nc(($cast($InetSocketAddress, $(p->address()))))->getPort();
			this->useV4$ = useV4(p);
			try {
				privilegedConnect(this->server, this->serverPort, remainingMillis(deadlineMillis));
				break;
			} catch ($IOException& e) {
				$nc(sel)->connectFailed(uri, $(p->address()), e);
				$set(this, server, nullptr);
				this->serverPort = -1;
				$assign(savedExc, e);
			}
		}
		if (this->server == nullptr) {
			$throwNew($SocketException, $$str({"Can\'t connect to SOCKS proxy:"_s, $($nc(savedExc)->getMessage())}));
		}
	} else {
		try {
			privilegedConnect(this->server, this->serverPort, remainingMillis(deadlineMillis));
		} catch ($IOException& e) {
			$throwNew($SocketException, $(e->getMessage()));
		}
	}
	$var($BufferedOutputStream, out, $new($BufferedOutputStream, this->cmdOut, 512));
	$var($InputStream, in, this->cmdIn);
	if (this->useV4$) {
		if ($nc(epoint)->isUnresolved()) {
			$throwNew($UnknownHostException, $(epoint->toString()));
		}
		connectV4(in, out, epoint, deadlineMillis);
		return;
	}
	out->write($SocksConsts::PROTO_VERS);
	out->write(2);
	out->write($SocksConsts::NO_AUTH);
	out->write($SocksConsts::USER_PASSW);
	out->flush();
	$var($bytes, data, $new($bytes, 2));
	int32_t i = readSocksReply(in, data, deadlineMillis);
	if (i != 2 || ((int32_t)data->get(0)) != $SocksConsts::PROTO_VERS) {
		if ($nc(epoint)->isUnresolved()) {
			$throwNew($UnknownHostException, $(epoint->toString()));
		}
		connectV4(in, out, epoint, deadlineMillis);
		return;
	}
	if (((int32_t)data->get(1)) == $SocksConsts::NO_METHODS) {
		$throwNew($SocketException, "SOCKS : No acceptable methods"_s);
	}
	if (!authenticate(data->get(1), in, out, deadlineMillis)) {
		$throwNew($SocketException, "SOCKS : authentication failed"_s);
	}
	out->write($SocksConsts::PROTO_VERS);
	out->write($SocksConsts::CONNECT);
	out->write(0);
	if ($nc(epoint)->isUnresolved()) {
		out->write($SocksConsts::DOMAIN_NAME);
		out->write($nc($(epoint->getHostName()))->length());
		$init($StandardCharsets);
		out->write($($nc($(epoint->getHostName()))->getBytes($StandardCharsets::ISO_8859_1)));
		out->write((int32_t)((epoint->getPort() >> 8) & (uint32_t)255));
		out->write((int32_t)((epoint->getPort() >> 0) & (uint32_t)255));
	} else if ($instanceOf($Inet6Address, $(epoint->getAddress()))) {
		out->write($SocksConsts::IPV6);
		out->write($($nc($(epoint->getAddress()))->getAddress()));
		out->write((int32_t)((epoint->getPort() >> 8) & (uint32_t)255));
		out->write((int32_t)((epoint->getPort() >> 0) & (uint32_t)255));
	} else {
		out->write($SocksConsts::IPV4);
		out->write($($nc($(epoint->getAddress()))->getAddress()));
		out->write((int32_t)((epoint->getPort() >> 8) & (uint32_t)255));
		out->write((int32_t)((epoint->getPort() >> 0) & (uint32_t)255));
	}
	out->flush();
	$assign(data, $new($bytes, 4));
	i = readSocksReply(in, data, deadlineMillis);
	if (i != 4) {
		$throwNew($SocketException, "Reply from SOCKS server has bad length"_s);
	}
	$var($SocketException, ex, nullptr);
	int32_t len = 0;
	$var($bytes, addr, nullptr);
	switch (data->get(1)) {
	case $SocksConsts::REQUEST_OK:
		{
			{
				$var($bytes, lenByte, nullptr)
				$var($bytes, host, nullptr)
				switch (data->get(3)) {
				case $SocksConsts::IPV4:
					{
						$assign(addr, $new($bytes, 4));
						i = readSocksReply(in, addr, deadlineMillis);
						if (i != 4) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						$assign(data, $new($bytes, 2));
						i = readSocksReply(in, data, deadlineMillis);
						if (i != 2) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						break;
					}
				case $SocksConsts::DOMAIN_NAME:
					{
						$assign(lenByte, $new($bytes, 1));
						i = readSocksReply(in, lenByte, deadlineMillis);
						if (i != 1) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						len = (int32_t)($nc(lenByte)->get(0) & (uint32_t)255);
						$assign(host, $new($bytes, len));
						i = readSocksReply(in, host, deadlineMillis);
						if (i != len) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						$assign(data, $new($bytes, 2));
						i = readSocksReply(in, data, deadlineMillis);
						if (i != 2) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						break;
					}
				case $SocksConsts::IPV6:
					{
						len = 16;
						$assign(addr, $new($bytes, len));
						i = readSocksReply(in, addr, deadlineMillis);
						if (i != len) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						$assign(data, $new($bytes, 2));
						i = readSocksReply(in, data, deadlineMillis);
						if (i != 2) {
							$throwNew($SocketException, "Reply from SOCKS server badly formatted"_s);
						}
						break;
					}
				default:
					{
						$assign(ex, $new($SocketException, "Reply from SOCKS server contains wrong code"_s));
						break;
					}
				}
			}
			break;
		}
	case $SocksConsts::GENERAL_FAILURE:
		{
			$assign(ex, $new($SocketException, "SOCKS server general failure"_s));
			break;
		}
	case $SocksConsts::NOT_ALLOWED:
		{
			$assign(ex, $new($SocketException, "SOCKS: Connection not allowed by ruleset"_s));
			break;
		}
	case $SocksConsts::NET_UNREACHABLE:
		{
			$assign(ex, $new($SocketException, "SOCKS: Network unreachable"_s));
			break;
		}
	case $SocksConsts::HOST_UNREACHABLE:
		{
			$assign(ex, $new($SocketException, "SOCKS: Host unreachable"_s));
			break;
		}
	case $SocksConsts::CONN_REFUSED:
		{
			$assign(ex, $new($SocketException, "SOCKS: Connection refused"_s));
			break;
		}
	case $SocksConsts::TTL_EXPIRED:
		{
			$assign(ex, $new($SocketException, "SOCKS: TTL expired"_s));
			break;
		}
	case $SocksConsts::CMD_NOT_SUPPORTED:
		{
			$assign(ex, $new($SocketException, "SOCKS: Command not supported"_s));
			break;
		}
	case $SocksConsts::ADDR_TYPE_NOT_SUP:
		{
			$assign(ex, $new($SocketException, "SOCKS: address type not supported"_s));
			break;
		}
	}
	if (ex != nullptr) {
		$nc(in)->close();
		out->close();
		$throw(ex);
	}
	$set(this, external_address, epoint);
}

void SocksSocketImpl::listen(int32_t backlog) {
	$throwNew($InternalError, "should not get here"_s);
}

void SocksSocketImpl::accept($SocketImpl* s) {
	$throwNew($InternalError, "should not get here"_s);
}

$InetAddress* SocksSocketImpl::getInetAddress() {
	if (this->external_address != nullptr) {
		return $nc(this->external_address)->getAddress();
	} else {
		return $nc(this->delegate$)->getInetAddress();
	}
}

int32_t SocksSocketImpl::getPort() {
	if (this->external_address != nullptr) {
		return $nc(this->external_address)->getPort();
	} else {
		return $nc(this->delegate$)->getPort();
	}
}

void SocksSocketImpl::close() {
	if (this->cmdsock != nullptr) {
		$nc(this->cmdsock)->close();
	}
	$set(this, cmdsock, nullptr);
	$nc(this->delegate$)->close();
}

$String* SocksSocketImpl::getUserName() {
	return $StaticProperty::userName();
}

void SocksSocketImpl::reset() {
	$throwNew($InternalError, "should not get here"_s);
}

void clinit$SocksSocketImpl($Class* class$) {
	SocksSocketImpl::$assertionsDisabled = !SocksSocketImpl::class$->desiredAssertionStatus();
}

SocksSocketImpl::SocksSocketImpl() {
}

$Class* SocksSocketImpl::load$($String* name, bool initialize) {
	$loadClass(SocksSocketImpl, name, initialize, &_SocksSocketImpl_ClassInfo_, clinit$SocksSocketImpl, allocate$SocksSocketImpl);
	return class$;
}

$Class* SocksSocketImpl::class$ = nullptr;

	} // net
} // java