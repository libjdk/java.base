#include <java/net/HttpConnectSocketImpl.h>

#include <java/io/IOException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/net/DelegatingSocketImpl.h>
#include <java/net/HttpConnectSocketImpl$1.h>
#include <java/net/HttpConnectSocketImpl$2.h>
#include <java/net/HttpURLConnection.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketImpl.h>
#include <java/net/SocketOptions.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef HTTP
#undef SO_TIMEOUT

using $IOException = ::java::io::IOException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Field = ::java::lang::reflect::Field;
using $Method = ::java::lang::reflect::Method;
using $DelegatingSocketImpl = ::java::net::DelegatingSocketImpl;
using $HttpConnectSocketImpl$1 = ::java::net::HttpConnectSocketImpl$1;
using $HttpConnectSocketImpl$2 = ::java::net::HttpConnectSocketImpl$2;
using $HttpURLConnection = ::java::net::HttpURLConnection;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketImpl = ::java::net::SocketImpl;
using $SocketOptions = ::java::net::SocketOptions;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

namespace java {
	namespace net {

$FieldInfo _HttpConnectSocketImpl_FieldInfo_[] = {
	{"httpURLClazzStr", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnectSocketImpl, httpURLClazzStr)},
	{"netClientClazzStr", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnectSocketImpl, netClientClazzStr)},
	{"doTunnelingStr", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnectSocketImpl, doTunnelingStr)},
	{"httpField", "Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnectSocketImpl, httpField)},
	{"serverSocketField", "Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnectSocketImpl, serverSocketField)},
	{"doTunneling", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnectSocketImpl, doTunneling$)},
	{"server", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HttpConnectSocketImpl, server)},
	{"socket", "Ljava/net/Socket;", nullptr, $PRIVATE | $FINAL, $field(HttpConnectSocketImpl, socket)},
	{"external_address", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(HttpConnectSocketImpl, external_address)},
	{"optionsMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/Integer;Ljava/lang/Object;>;", $PRIVATE, $field(HttpConnectSocketImpl, optionsMap)},
	{}
};

$MethodInfo _HttpConnectSocketImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/net/Proxy;Ljava/net/SocketImpl;Ljava/net/Socket;)V", nullptr, 0, $method(HttpConnectSocketImpl, init$, void, $Proxy*, $SocketImpl*, $Socket*)},
	{"accept", "(Ljava/net/SocketImpl;)V", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, accept, void, $SocketImpl*)},
	{"connect", "(Ljava/lang/String;I)V", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, connect, void, $String*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, connect, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)V", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, connect, void, $SocketAddress*, int32_t), "java.io.IOException"},
	{"doTunnel", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PRIVATE, $method(HttpConnectSocketImpl, doTunnel, $Socket*, $String*, int32_t), "java.io.IOException"},
	{"doTunneling", "(Ljava/net/HttpURLConnection;)V", nullptr, $PRIVATE, $method(HttpConnectSocketImpl, doTunneling, void, $HttpURLConnection*), "java.io.IOException"},
	{"getInetAddress", "()Ljava/net/InetAddress;", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, getInetAddress, $InetAddress*)},
	{"getPort", "()I", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, getPort, int32_t)},
	{"listen", "(I)V", nullptr, $PROTECTED, $virtualMethod(HttpConnectSocketImpl, listen, void, int32_t)},
	{"privilegedDoTunnel", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PRIVATE, $method(HttpConnectSocketImpl, privilegedDoTunnel, $Socket*, $String*, int32_t), "java.io.IOException"},
	{"reset", "()V", nullptr, 0, $virtualMethod(HttpConnectSocketImpl, reset, void)},
	{"setOption", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HttpConnectSocketImpl, setOption, void, int32_t, Object$*), "java.net.SocketException"},
	{}
};

$InnerClassInfo _HttpConnectSocketImpl_InnerClassesInfo_[] = {
	{"java.net.HttpConnectSocketImpl$2", nullptr, nullptr, 0},
	{"java.net.HttpConnectSocketImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HttpConnectSocketImpl_ClassInfo_ = {
	$ACC_SUPER,
	"java.net.HttpConnectSocketImpl",
	"java.net.DelegatingSocketImpl",
	nullptr,
	_HttpConnectSocketImpl_FieldInfo_,
	_HttpConnectSocketImpl_MethodInfo_,
	nullptr,
	nullptr,
	_HttpConnectSocketImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.HttpConnectSocketImpl$2,java.net.HttpConnectSocketImpl$1"
};

$Object* allocate$HttpConnectSocketImpl($Class* clazz) {
	return $of($alloc(HttpConnectSocketImpl));
}

$String* HttpConnectSocketImpl::httpURLClazzStr = nullptr;
$String* HttpConnectSocketImpl::netClientClazzStr = nullptr;
$String* HttpConnectSocketImpl::doTunnelingStr = nullptr;
$Field* HttpConnectSocketImpl::httpField = nullptr;
$Field* HttpConnectSocketImpl::serverSocketField = nullptr;
$Method* HttpConnectSocketImpl::doTunneling$ = nullptr;

void HttpConnectSocketImpl::init$($Proxy* proxy, $SocketImpl* delegate, $Socket* socket) {
	$useLocalCurrentObjectStackCache();
	$DelegatingSocketImpl::init$(delegate);
	$set(this, optionsMap, $new($HashMap));
	$set(this, socket, socket);
	$var($SocketAddress, a, $nc(proxy)->address());
	$var($InetSocketAddress, ad, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, a);
	if (var$0) {
		$assign(ad, $cast($InetSocketAddress, a));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	$set(this, server, $nc(ad)->getHostString());
	this->port = ad->getPort();
}

void HttpConnectSocketImpl::connect($String* host, int32_t port) {
	connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, host, port)), 0);
}

void HttpConnectSocketImpl::connect($InetAddress* address, int32_t port) {
	connect(static_cast<$SocketAddress*>($$new($InetSocketAddress, address, port)), 0);
}

void HttpConnectSocketImpl::connect($SocketAddress* endpoint, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, epoint, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, endpoint);
	if (var$0) {
		$assign(epoint, $cast($InetSocketAddress, endpoint));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	$var($String, destHost, $nc(epoint)->isUnresolved() ? $nc(epoint)->getHostName() : $nc($(epoint->getAddress()))->getHostAddress());
	int32_t destPort = epoint->getPort();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkConnect(destHost, destPort);
	}
	if ($nc(destHost)->contains(":"_s)) {
		$assign(destHost, $str({"["_s, destHost, "]"_s}));
	}
	$var($String, urlString, $str({"http://"_s, destHost, ":"_s, $$str(destPort)}));
	$var($Socket, httpSocket, privilegedDoTunnel(urlString, timeout));
	$set(this, external_address, epoint);
	close();
	$var($SocketImpl, si, $nc(httpSocket)->impl);
	$nc(this->socket)->setImpl(si);
	$var($Set, options, $nc(this->optionsMap)->entrySet());
	try {
		{
			$var($Iterator, i$, $nc(options)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					int32_t var$1 = $nc(($cast($Integer, $($nc(entry)->getKey()))))->intValue();
					$nc(si)->setOption(var$1, $(entry->getValue()));
				}
			}
		}
	} catch ($IOException& x) {
	}
}

void HttpConnectSocketImpl::listen(int32_t backlog) {
	$throwNew($InternalError, "should not get here"_s);
}

void HttpConnectSocketImpl::accept($SocketImpl* s) {
	$throwNew($InternalError, "should not get here"_s);
}

void HttpConnectSocketImpl::reset() {
	$throwNew($InternalError, "should not get here"_s);
}

void HttpConnectSocketImpl::setOption(int32_t opt, Object$* val) {
	$nc(this->delegate$)->setOption(opt, val);
	if (this->external_address != nullptr) {
		return;
	}
	$nc(this->optionsMap)->put($($Integer::valueOf(opt)), val);
}

$Socket* HttpConnectSocketImpl::privilegedDoTunnel($String* urlString, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $cast($Socket, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($HttpConnectSocketImpl$2, this, urlString, timeout))));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getException())));
	}
	$shouldNotReachHere();
}

$Socket* HttpConnectSocketImpl::doTunnel($String* urlString, int32_t connectTimeout) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($Proxy$Type);
	$var($Proxy, proxy, $new($Proxy, $Proxy$Type::HTTP, $$new($InetSocketAddress, this->server, this->port)));
	$var($URL, destURL, $new($URL, urlString));
	$var($HttpURLConnection, conn, $cast($HttpURLConnection, destURL->openConnection(proxy)));
	$nc(conn)->setConnectTimeout(connectTimeout);
	int32_t timeout = $nc(($cast($Integer, $(getOption($SocketOptions::SO_TIMEOUT)))))->intValue();
	if (timeout > 0) {
		conn->setReadTimeout(timeout);
	}
	conn->connect();
	doTunneling(conn);
	try {
		$var($Object, httpClient, $nc(HttpConnectSocketImpl::httpField)->get(conn));
		return $cast($Socket, $nc(HttpConnectSocketImpl::serverSocketField)->get(httpClient));
	} catch ($IllegalAccessException& x) {
		$throwNew($InternalError, "Should not reach here"_s, x);
	}
	$shouldNotReachHere();
}

void HttpConnectSocketImpl::doTunneling($HttpURLConnection* conn) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$nc(HttpConnectSocketImpl::doTunneling$)->invoke(conn, $$new($ObjectArray, 0));
	} catch ($ReflectiveOperationException& x) {
		$var($Throwable, cause, x->getCause());
		if ($instanceOf($IOException, cause)) {
			$throw($cast($IOException, cause));
		}
		$throwNew($InternalError, "Should not reach here"_s, x);
	}
}

$InetAddress* HttpConnectSocketImpl::getInetAddress() {
	if (this->external_address != nullptr) {
		return $nc(this->external_address)->getAddress();
	} else {
		return $nc(this->delegate$)->getInetAddress();
	}
}

int32_t HttpConnectSocketImpl::getPort() {
	if (this->external_address != nullptr) {
		return $nc(this->external_address)->getPort();
	} else {
		return $nc(this->delegate$)->getPort();
	}
}

void clinit$HttpConnectSocketImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(HttpConnectSocketImpl::httpURLClazzStr, "sun.net.www.protocol.http.HttpURLConnection"_s);
	$assignStatic(HttpConnectSocketImpl::netClientClazzStr, "sun.net.NetworkClient"_s);
	$assignStatic(HttpConnectSocketImpl::doTunnelingStr, "doTunneling"_s);
	$beforeCallerSensitive();
	{
		try {
			$Class* httpClazz = $Class::forName(HttpConnectSocketImpl::httpURLClazzStr, true, nullptr);
			$assignStatic(HttpConnectSocketImpl::httpField, $nc(httpClazz)->getDeclaredField("http"_s));
			$assignStatic(HttpConnectSocketImpl::doTunneling$, httpClazz->getDeclaredMethod(HttpConnectSocketImpl::doTunnelingStr, $$new($ClassArray, 0)));
			$Class* netClientClazz = $Class::forName(HttpConnectSocketImpl::netClientClazzStr, true, nullptr);
			$assignStatic(HttpConnectSocketImpl::serverSocketField, $nc(netClientClazz)->getDeclaredField("serverSocket"_s));
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($HttpConnectSocketImpl$1)));
		} catch ($ReflectiveOperationException& x) {
			$throwNew($InternalError, "Should not reach here"_s, x);
		}
	}
}

HttpConnectSocketImpl::HttpConnectSocketImpl() {
}

$Class* HttpConnectSocketImpl::load$($String* name, bool initialize) {
	$loadClass(HttpConnectSocketImpl, name, initialize, &_HttpConnectSocketImpl_ClassInfo_, clinit$HttpConnectSocketImpl, allocate$HttpConnectSocketImpl);
	return class$;
}

$Class* HttpConnectSocketImpl::class$ = nullptr;

	} // net
} // java