#include <sun/net/NetworkClient.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/InternalError.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <sun/net/NetworkClient$1.h>
#include <sun/net/NetworkClient$2.h>
#include <sun/net/NetworkClient$3.h>
#include <jcpp.h>

#undef DEFAULT_CONNECT_TIMEOUT
#undef DEFAULT_READ_TIMEOUT
#undef DIRECT
#undef NO_PROXY
#undef SOCKS

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $NetworkClient$1 = ::sun::net::NetworkClient$1;
using $NetworkClient$2 = ::sun::net::NetworkClient$2;
using $NetworkClient$3 = ::sun::net::NetworkClient$3;

namespace sun {
	namespace net {

$FieldInfo _NetworkClient_FieldInfo_[] = {
	{"DEFAULT_READ_TIMEOUT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NetworkClient, DEFAULT_READ_TIMEOUT)},
	{"DEFAULT_CONNECT_TIMEOUT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NetworkClient, DEFAULT_CONNECT_TIMEOUT)},
	{"proxy", "Ljava/net/Proxy;", nullptr, $PROTECTED, $field(NetworkClient, proxy)},
	{"serverSocket", "Ljava/net/Socket;", nullptr, $PROTECTED, $field(NetworkClient, serverSocket)},
	{"serverOutput", "Ljava/io/PrintStream;", nullptr, $PUBLIC, $field(NetworkClient, serverOutput)},
	{"serverInput", "Ljava/io/InputStream;", nullptr, $PUBLIC, $field(NetworkClient, serverInput)},
	{"defaultSoTimeout", "I", nullptr, $PROTECTED | $STATIC, $staticField(NetworkClient, defaultSoTimeout)},
	{"defaultConnectTimeout", "I", nullptr, $PROTECTED | $STATIC, $staticField(NetworkClient, defaultConnectTimeout)},
	{"readTimeout", "I", nullptr, $PROTECTED, $field(NetworkClient, readTimeout)},
	{"connectTimeout", "I", nullptr, $PROTECTED, $field(NetworkClient, connectTimeout)},
	{"encoding", "Ljava/lang/String;", nullptr, $PROTECTED | $STATIC, $staticField(NetworkClient, encoding)},
	{}
};

$MethodInfo _NetworkClient_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(NetworkClient, init$, void, $String*, int32_t), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(NetworkClient, init$, void)},
	{"closeServer", "()V", nullptr, $PUBLIC, $virtualMethod(NetworkClient, closeServer, void), "java.io.IOException"},
	{"createSocket", "()Ljava/net/Socket;", nullptr, $PROTECTED, $virtualMethod(NetworkClient, createSocket, $Socket*), "java.io.IOException"},
	{"doConnect", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PROTECTED, $virtualMethod(NetworkClient, doConnect, $Socket*, $String*, int32_t), "java.io.IOException,java.net.UnknownHostException"},
	{"getConnectTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(NetworkClient, getConnectTimeout, int32_t)},
	{"getLocalAddress", "()Ljava/net/InetAddress;", nullptr, $PROTECTED, $virtualMethod(NetworkClient, getLocalAddress, $InetAddress*), "java.io.IOException"},
	{"getReadTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(NetworkClient, getReadTimeout, int32_t)},
	{"isASCIISuperset", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(NetworkClient, isASCIISuperset, bool, $String*), "java.lang.Exception"},
	{"openServer", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(NetworkClient, openServer, void, $String*, int32_t), "java.io.IOException,java.net.UnknownHostException"},
	{"serverIsOpen", "()Z", nullptr, $PUBLIC, $virtualMethod(NetworkClient, serverIsOpen, bool)},
	{"setConnectTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(NetworkClient, setConnectTimeout, void, int32_t)},
	{"setReadTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(NetworkClient, setReadTimeout, void, int32_t)},
	{}
};

$InnerClassInfo _NetworkClient_InnerClassesInfo_[] = {
	{"sun.net.NetworkClient$3", nullptr, nullptr, 0},
	{"sun.net.NetworkClient$2", nullptr, nullptr, 0},
	{"sun.net.NetworkClient$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NetworkClient_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.NetworkClient",
	"java.lang.Object",
	nullptr,
	_NetworkClient_FieldInfo_,
	_NetworkClient_MethodInfo_,
	nullptr,
	nullptr,
	_NetworkClient_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.NetworkClient$3,sun.net.NetworkClient$2,sun.net.NetworkClient$1"
};

$Object* allocate$NetworkClient($Class* clazz) {
	return $of($alloc(NetworkClient));
}

int32_t NetworkClient::defaultSoTimeout = 0;
int32_t NetworkClient::defaultConnectTimeout = 0;
$String* NetworkClient::encoding = nullptr;

bool NetworkClient::isASCIISuperset($String* encoding) {
	$init(NetworkClient);
	$useLocalCurrentObjectStackCache();
	$var($String, chkS, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_.!~*\'();/?:@&=+$,"_s);
	$var($bytes, chkB, $new($bytes, {
		(int8_t)48,
		(int8_t)49,
		(int8_t)50,
		(int8_t)51,
		(int8_t)52,
		(int8_t)53,
		(int8_t)54,
		(int8_t)55,
		(int8_t)56,
		(int8_t)57,
		(int8_t)65,
		(int8_t)66,
		(int8_t)67,
		(int8_t)68,
		(int8_t)69,
		(int8_t)70,
		(int8_t)71,
		(int8_t)72,
		(int8_t)73,
		(int8_t)74,
		(int8_t)75,
		(int8_t)76,
		(int8_t)77,
		(int8_t)78,
		(int8_t)79,
		(int8_t)80,
		(int8_t)81,
		(int8_t)82,
		(int8_t)83,
		(int8_t)84,
		(int8_t)85,
		(int8_t)86,
		(int8_t)87,
		(int8_t)88,
		(int8_t)89,
		(int8_t)90,
		(int8_t)97,
		(int8_t)98,
		(int8_t)99,
		(int8_t)100,
		(int8_t)101,
		(int8_t)102,
		(int8_t)103,
		(int8_t)104,
		(int8_t)105,
		(int8_t)106,
		(int8_t)107,
		(int8_t)108,
		(int8_t)109,
		(int8_t)110,
		(int8_t)111,
		(int8_t)112,
		(int8_t)113,
		(int8_t)114,
		(int8_t)115,
		(int8_t)116,
		(int8_t)117,
		(int8_t)118,
		(int8_t)119,
		(int8_t)120,
		(int8_t)121,
		(int8_t)122,
		(int8_t)45,
		(int8_t)95,
		(int8_t)46,
		(int8_t)33,
		(int8_t)126,
		(int8_t)42,
		(int8_t)39,
		(int8_t)40,
		(int8_t)41,
		(int8_t)59,
		(int8_t)47,
		(int8_t)63,
		(int8_t)58,
		(int8_t)64,
		(int8_t)38,
		(int8_t)61,
		(int8_t)43,
		(int8_t)36,
		(int8_t)44
	}));
	$var($bytes, b, chkS->getBytes(encoding));
	return $Arrays::equals(b, chkB);
}

void NetworkClient::openServer($String* server, int32_t port) {
	$useLocalCurrentObjectStackCache();
	if (this->serverSocket != nullptr) {
		closeServer();
	}
	$set(this, serverSocket, doConnect(server, port));
	try {
		$set(this, serverOutput, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, $($nc(this->serverSocket)->getOutputStream()))), true, NetworkClient::encoding));
	} catch ($UnsupportedEncodingException& e) {
		$throwNew($InternalError, $$str({NetworkClient::encoding, "encoding not found"_s}), e);
	}
	$set(this, serverInput, $new($BufferedInputStream, $($nc(this->serverSocket)->getInputStream())));
}

$Socket* NetworkClient::doConnect($String* server, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Socket, s, nullptr);
	if (this->proxy != nullptr) {
		$init($Proxy$Type);
		if ($nc(this->proxy)->type() == $Proxy$Type::SOCKS) {
			$assign(s, $cast($Socket, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NetworkClient$2, this)))));
		} else {
			if ($nc(this->proxy)->type() == $Proxy$Type::DIRECT) {
				$assign(s, createSocket());
			} else {
				$init($Proxy);
				$assign(s, $new($Socket, $Proxy::NO_PROXY));
			}
		}
	} else {
		$assign(s, createSocket());
	}
	if (this->connectTimeout >= 0) {
		$nc(s)->connect($$new($InetSocketAddress, server, port), this->connectTimeout);
	} else if (NetworkClient::defaultConnectTimeout > 0) {
		$nc(s)->connect($$new($InetSocketAddress, server, port), NetworkClient::defaultConnectTimeout);
	} else {
		$nc(s)->connect($$new($InetSocketAddress, server, port));
	}
	if (this->readTimeout >= 0) {
		$nc(s)->setSoTimeout(this->readTimeout);
	} else if (NetworkClient::defaultSoTimeout > 0) {
		$nc(s)->setSoTimeout(NetworkClient::defaultSoTimeout);
	}
	return s;
}

$Socket* NetworkClient::createSocket() {
	$init($Proxy);
	return $new($Socket, $Proxy::NO_PROXY);
}

$InetAddress* NetworkClient::getLocalAddress() {
	$beforeCallerSensitive();
	if (this->serverSocket == nullptr) {
		$throwNew($IOException, "not connected"_s);
	}
	return $cast($InetAddress, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NetworkClient$3, this))));
}

void NetworkClient::closeServer() {
	if (!serverIsOpen()) {
		return;
	}
	$nc(this->serverSocket)->close();
	$set(this, serverSocket, nullptr);
	$set(this, serverInput, nullptr);
	$set(this, serverOutput, nullptr);
}

bool NetworkClient::serverIsOpen() {
	return this->serverSocket != nullptr;
}

void NetworkClient::init$($String* host, int32_t port) {
	$init($Proxy);
	$set(this, proxy, $Proxy::NO_PROXY);
	$set(this, serverSocket, nullptr);
	this->readTimeout = NetworkClient::DEFAULT_READ_TIMEOUT;
	this->connectTimeout = NetworkClient::DEFAULT_CONNECT_TIMEOUT;
	openServer(host, port);
}

void NetworkClient::init$() {
	$init($Proxy);
	$set(this, proxy, $Proxy::NO_PROXY);
	$set(this, serverSocket, nullptr);
	this->readTimeout = NetworkClient::DEFAULT_READ_TIMEOUT;
	this->connectTimeout = NetworkClient::DEFAULT_CONNECT_TIMEOUT;
}

void NetworkClient::setConnectTimeout(int32_t timeout) {
	this->connectTimeout = timeout;
}

int32_t NetworkClient::getConnectTimeout() {
	return this->connectTimeout;
}

void NetworkClient::setReadTimeout(int32_t timeout) {
	if (timeout == NetworkClient::DEFAULT_READ_TIMEOUT) {
		timeout = NetworkClient::defaultSoTimeout;
	}
	if (this->serverSocket != nullptr && timeout >= 0) {
		try {
			$nc(this->serverSocket)->setSoTimeout(timeout);
		} catch ($IOException& e) {
		}
	}
	this->readTimeout = timeout;
}

int32_t NetworkClient::getReadTimeout() {
	return this->readTimeout;
}

void clinit$NetworkClient($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($ints, vals, $new($ints, {
			0,
			0
		}));
		$var($StringArray, encs, $new($StringArray, {($String*)nullptr}));
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NetworkClient$1, vals, encs)));
		if (vals->get(0) != 0) {
			NetworkClient::defaultSoTimeout = vals->get(0);
		}
		if (vals->get(1) != 0) {
			NetworkClient::defaultConnectTimeout = vals->get(1);
		}
		$assignStatic(NetworkClient::encoding, encs->get(0));
		try {
			if (!NetworkClient::isASCIISuperset(NetworkClient::encoding)) {
				$assignStatic(NetworkClient::encoding, "ISO8859_1"_s);
			}
		} catch ($Exception& e) {
			$assignStatic(NetworkClient::encoding, "ISO8859_1"_s);
		}
	}
}

NetworkClient::NetworkClient() {
}

$Class* NetworkClient::load$($String* name, bool initialize) {
	$loadClass(NetworkClient, name, initialize, &_NetworkClient_ClassInfo_, clinit$NetworkClient, allocate$NetworkClient);
	return class$;
}

$Class* NetworkClient::class$ = nullptr;

	} // net
} // sun