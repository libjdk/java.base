#include <sun/net/www/http/HttpClient.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/CacheRequest.h>
#include <java/net/CookieHandler.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/MalformedURLException.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketTimeoutException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Properties.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <sun/net/NetworkClient.h>
#include <sun/net/ProgressSource.h>
#include <sun/net/www/HeaderParser.h>
#include <sun/net/www/MessageHeader.h>
#include <sun/net/www/MeteredStream.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/URLConnection.h>
#include <sun/net/www/http/ChunkedInputStream.h>
#include <sun/net/www/http/HttpCapture.h>
#include <sun/net/www/http/HttpCaptureInputStream.h>
#include <sun/net/www/http/HttpCaptureOutputStream.h>
#include <sun/net/www/http/HttpClient$1.h>
#include <sun/net/www/http/KeepAliveCache.h>
#include <sun/net/www/http/KeepAliveStream.h>
#include <sun/net/www/http/PosterOutputStream.h>
#include <sun/net/www/protocol/http/AuthenticatorKeys.h>
#include <sun/net/www/protocol/http/HttpURLConnection$TunnelState.h>
#include <sun/net/www/protocol/http/HttpURLConnection.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef DEFAULT
#undef FINEST
#undef HTTP
#undef HTTP_CONTINUE
#undef HTTP_NOT_MODIFIED
#undef HTTP_NO_CONTENT
#undef NO_PROXY
#undef TUNNELING
#undef US

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $SecurityManager = ::java::lang::SecurityManager;
using $CacheRequest = ::java::net::CacheRequest;
using $CookieHandler = ::java::net::CookieHandler;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $MalformedURLException = ::java::net::MalformedURLException;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $Properties = ::java::util::Properties;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $NetworkClient = ::sun::net::NetworkClient;
using $ProgressSource = ::sun::net::ProgressSource;
using $HeaderParser = ::sun::net::www::HeaderParser;
using $MessageHeader = ::sun::net::www::MessageHeader;
using $MeteredStream = ::sun::net::www::MeteredStream;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $URLConnection = ::sun::net::www::URLConnection;
using $ChunkedInputStream = ::sun::net::www::http::ChunkedInputStream;
using $HttpCapture = ::sun::net::www::http::HttpCapture;
using $HttpCaptureInputStream = ::sun::net::www::http::HttpCaptureInputStream;
using $HttpCaptureOutputStream = ::sun::net::www::http::HttpCaptureOutputStream;
using $HttpClient$1 = ::sun::net::www::http::HttpClient$1;
using $KeepAliveCache = ::sun::net::www::http::KeepAliveCache;
using $KeepAliveStream = ::sun::net::www::http::KeepAliveStream;
using $PosterOutputStream = ::sun::net::www::http::PosterOutputStream;
using $AuthenticatorKeys = ::sun::net::www::protocol::http::AuthenticatorKeys;
using $HttpURLConnection = ::sun::net::www::protocol::http::HttpURLConnection;
using $HttpURLConnection$TunnelState = ::sun::net::www::protocol::http::HttpURLConnection$TunnelState;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace sun {
	namespace net {
		namespace www {
			namespace http {

$CompoundAttribute _HttpClient_MethodAnnotations_resetProperties44[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _HttpClient_MethodAnnotations_writeRequests51[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _HttpClient_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClient, $assertionsDisabled)},
	{"clientLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(HttpClient, clientLock)},
	{"cachedHttpClient", "Z", nullptr, $PROTECTED, $field(HttpClient, cachedHttpClient)},
	{"inCache", "Z", nullptr, $PROTECTED, $field(HttpClient, inCache)},
	{"requests", "Lsun/net/www/MessageHeader;", nullptr, 0, $field(HttpClient, requests)},
	{"poster", "Lsun/net/www/http/PosterOutputStream;", nullptr, 0, $field(HttpClient, poster)},
	{"streaming", "Z", nullptr, 0, $field(HttpClient, streaming)},
	{"failedOnce", "Z", nullptr, 0, $field(HttpClient, failedOnce)},
	{"ignoreContinue", "Z", nullptr, $PRIVATE, $field(HttpClient, ignoreContinue)},
	{"HTTP_CONTINUE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpClient, HTTP_CONTINUE)},
	{"httpPortNumber", "I", nullptr, $STATIC | $FINAL, $constField(HttpClient, httpPortNumber)},
	{"proxyDisabled", "Z", nullptr, $PROTECTED, $field(HttpClient, proxyDisabled)},
	{"usingProxy", "Z", nullptr, $PUBLIC, $field(HttpClient, usingProxy)},
	{"host", "Ljava/lang/String;", nullptr, $PROTECTED, $field(HttpClient, host)},
	{"port", "I", nullptr, $PROTECTED, $field(HttpClient, port)},
	{"kac", "Lsun/net/www/http/KeepAliveCache;", nullptr, $PROTECTED | $STATIC, $staticField(HttpClient, kac)},
	{"keepAliveProp", "Z", nullptr, $PRIVATE | $STATIC, $staticField(HttpClient, keepAliveProp)},
	{"retryPostProp", "Z", nullptr, $PRIVATE | $STATIC, $staticField(HttpClient, retryPostProp)},
	{"cacheNTLMProp", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpClient, cacheNTLMProp)},
	{"cacheSPNEGOProp", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpClient, cacheSPNEGOProp)},
	{"keepingAlive", "Z", nullptr, $VOLATILE, $field(HttpClient, keepingAlive)},
	{"disableKeepAlive", "Z", nullptr, $VOLATILE, $field(HttpClient, disableKeepAlive)},
	{"keepAliveConnections", "I", nullptr, 0, $field(HttpClient, keepAliveConnections)},
	{"keepAliveTimeout", "I", nullptr, 0, $field(HttpClient, keepAliveTimeout)},
	{"cacheRequest", "Ljava/net/CacheRequest;", nullptr, $PRIVATE, $field(HttpClient, cacheRequest)},
	{"url", "Ljava/net/URL;", nullptr, $PROTECTED, $field(HttpClient, url)},
	{"reuse", "Z", nullptr, $PUBLIC, $field(HttpClient, reuse)},
	{"capture", "Lsun/net/www/http/HttpCapture;", nullptr, $PRIVATE, $field(HttpClient, capture)},
	{"logger", "Lsun/util/logging/PlatformLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpClient, logger)},
	{"authenticatorKey", "Ljava/lang/String;", nullptr, $PROTECTED | $VOLATILE, $field(HttpClient, authenticatorKey)},
	{}
};

$MethodInfo _HttpClient_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(HttpClient, init$, void)},
	{"<init>", "(Ljava/net/URL;)V", nullptr, $PRIVATE, $method(HttpClient, init$, void, $URL*), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Z)V", nullptr, $PROTECTED, $method(HttpClient, init$, void, $URL*, bool), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(HttpClient, init$, void, $URL*, $String*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/net/Proxy;I)V", nullptr, $PROTECTED, $method(HttpClient, init$, void, $URL*, $Proxy*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/lang/String;IZ)V", nullptr, $PRIVATE, $method(HttpClient, init$, void, $URL*, $String*, int32_t, bool), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/lang/String;IZI)V", nullptr, $PUBLIC, $method(HttpClient, init$, void, $URL*, $String*, int32_t, bool, int32_t), "java.io.IOException"},
	{"New", "(Ljava/net/URL;)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpClient, New, HttpClient*, $URL*), "java.io.IOException"},
	{"New", "(Ljava/net/URL;Z)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpClient, New, HttpClient*, $URL*, bool), "java.io.IOException"},
	{"New", "(Ljava/net/URL;Ljava/net/Proxy;IZLsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpClient, New, HttpClient*, $URL*, $Proxy*, int32_t, bool, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljava/net/URL;Ljava/net/Proxy;ILsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpClient, New, HttpClient*, $URL*, $Proxy*, int32_t, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljava/net/URL;Ljava/lang/String;IZ)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpClient, New, HttpClient*, $URL*, $String*, int32_t, bool), "java.io.IOException"},
	{"New", "(Ljava/net/URL;Ljava/lang/String;IZILsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpClient, New, HttpClient*, $URL*, $String*, int32_t, bool, int32_t, $HttpURLConnection*), "java.io.IOException"},
	{"afterConnect", "()V", nullptr, $PUBLIC, $virtualMethod(HttpClient, afterConnect, void), "java.io.IOException,java.net.UnknownHostException"},
	{"available", "()Z", nullptr, $PROTECTED, $virtualMethod(HttpClient, available, bool)},
	{"checkTunneling", "(Lsun/net/www/protocol/http/HttpURLConnection;)V", nullptr, $PRIVATE, $method(HttpClient, checkTunneling, void, $HttpURLConnection*), "java.io.IOException"},
	{"closeIdleConnection", "()V", nullptr, $PUBLIC, $virtualMethod(HttpClient, closeIdleConnection, void)},
	{"closeServer", "()V", nullptr, $PUBLIC, $virtualMethod(HttpClient, closeServer, void)},
	{"finished", "()V", nullptr, $PUBLIC, $virtualMethod(HttpClient, finished, void)},
	{"getAuthenticatorKey", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(HttpClient, getAuthenticatorKey, $String*)},
	{"getCacheRequest", "()Ljava/net/CacheRequest;", nullptr, 0, $virtualMethod(HttpClient, getCacheRequest, $CacheRequest*)},
	{"getDefaultPort", "()I", nullptr, $PROTECTED, $virtualMethod(HttpClient, getDefaultPort, int32_t)},
	{"getDefaultPort", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpClient, getDefaultPort, int32_t, $String*)},
	{"getHttpKeepAliveSet", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpClient, getHttpKeepAliveSet, bool)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(HttpClient, getInputStream, $InputStream*)},
	{"getKeepAliveTimeout", "()I", nullptr, 0, $virtualMethod(HttpClient, getKeepAliveTimeout, int32_t)},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(HttpClient, getOutputStream, $OutputStream*)},
	{"getProxyHostUsed", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpClient, getProxyHostUsed, $String*)},
	{"getProxyPortUsed", "()I", nullptr, $PUBLIC, $virtualMethod(HttpClient, getProxyPortUsed, int32_t)},
	{"getRequestMethod", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(HttpClient, getRequestMethod, $String*)},
	{"getURLFile", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpClient, getURLFile, $String*), "java.io.IOException"},
	{"isCachedConnection", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpClient, isCachedConnection, bool)},
	{"isInKeepAliveCache", "()Z", nullptr, $PROTECTED, $virtualMethod(HttpClient, isInKeepAliveCache, bool)},
	{"isKeepingAlive", "()Z", nullptr, $PUBLIC | $FINAL, $method(HttpClient, isKeepingAlive, bool)},
	{"lock", "()V", nullptr, $PUBLIC | $FINAL, $method(HttpClient, lock, void)},
	{"logFinest", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpClient, logFinest, void, $String*)},
	{"needsTunneling", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpClient, needsTunneling, bool)},
	{"newHttpProxy", "(Ljava/lang/String;ILjava/lang/String;)Ljava/net/Proxy;", nullptr, $PROTECTED | $STATIC, $staticMethod(HttpClient, newHttpProxy, $Proxy*, $String*, int32_t, $String*)},
	{"openServer", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(HttpClient, openServer, void, $String*, int32_t), "java.io.IOException"},
	{"openServer", "()V", nullptr, $PROTECTED, $virtualMethod(HttpClient, openServer, void), "java.io.IOException"},
	{"parseHTTP", "(Lsun/net/www/MessageHeader;Lsun/net/ProgressSource;Lsun/net/www/protocol/http/HttpURLConnection;)Z", nullptr, $PUBLIC, $virtualMethod(HttpClient, parseHTTP, bool, $MessageHeader*, $ProgressSource*, $HttpURLConnection*), "java.io.IOException"},
	{"parseHTTPHeader", "(Lsun/net/www/MessageHeader;Lsun/net/ProgressSource;Lsun/net/www/protocol/http/HttpURLConnection;)Z", nullptr, $PRIVATE, $method(HttpClient, parseHTTPHeader, bool, $MessageHeader*, $ProgressSource*, $HttpURLConnection*), "java.io.IOException"},
	{"privilegedOpenServer", "(Ljava/net/InetSocketAddress;)V", nullptr, $PRIVATE, $method(HttpClient, privilegedOpenServer, void, $InetSocketAddress*), "java.io.IOException"},
	{"putInKeepAliveCache", "()V", nullptr, $PROTECTED, $virtualMethod(HttpClient, putInKeepAliveCache, void)},
	{"resetProperties", "()V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED | $DEPRECATED, $staticMethod(HttpClient, resetProperties, void), nullptr, nullptr, _HttpClient_MethodAnnotations_resetProperties44},
	{"setCacheRequest", "(Ljava/net/CacheRequest;)V", nullptr, $PUBLIC, $virtualMethod(HttpClient, setCacheRequest, void, $CacheRequest*)},
	{"setDoNotRetry", "(Z)V", nullptr, $PUBLIC, $virtualMethod(HttpClient, setDoNotRetry, void, bool)},
	{"setIgnoreContinue", "(Z)V", nullptr, $PUBLIC, $virtualMethod(HttpClient, setIgnoreContinue, void, bool)},
	{"superOpenServer", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(HttpClient, superOpenServer, void, $String*, int32_t), "java.io.IOException,java.net.UnknownHostException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpClient, toString, $String*)},
	{"unlock", "()V", nullptr, $PUBLIC | $FINAL, $method(HttpClient, unlock, void)},
	{"writeRequests", "(Lsun/net/www/MessageHeader;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(HttpClient, writeRequests, void, $MessageHeader*), nullptr, nullptr, _HttpClient_MethodAnnotations_writeRequests51},
	{"writeRequests", "(Lsun/net/www/MessageHeader;Lsun/net/www/http/PosterOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(HttpClient, writeRequests, void, $MessageHeader*, $PosterOutputStream*), "java.io.IOException"},
	{"writeRequests", "(Lsun/net/www/MessageHeader;Lsun/net/www/http/PosterOutputStream;Z)V", nullptr, $PUBLIC, $virtualMethod(HttpClient, writeRequests, void, $MessageHeader*, $PosterOutputStream*, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _HttpClient_InnerClassesInfo_[] = {
	{"sun.net.www.http.HttpClient$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HttpClient_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.http.HttpClient",
	"sun.net.NetworkClient",
	nullptr,
	_HttpClient_FieldInfo_,
	_HttpClient_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClient_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.www.http.HttpClient$1"
};

$Object* allocate$HttpClient($Class* clazz) {
	return $of($alloc(HttpClient));
}

bool HttpClient::$assertionsDisabled = false;
$KeepAliveCache* HttpClient::kac = nullptr;
bool HttpClient::keepAliveProp = false;
bool HttpClient::retryPostProp = false;
bool HttpClient::cacheNTLMProp = false;
bool HttpClient::cacheSPNEGOProp = false;
$PlatformLogger* HttpClient::logger = nullptr;

int32_t HttpClient::getDefaultPort() {
	return HttpClient::httpPortNumber;
}

int32_t HttpClient::getDefaultPort($String* proto) {
	$init(HttpClient);
	if ("http"_s->equalsIgnoreCase(proto)) {
		return 80;
	}
	if ("https"_s->equalsIgnoreCase(proto)) {
		return 443;
	}
	return -1;
}

void HttpClient::logFinest($String* msg) {
	$init(HttpClient);
	$init($PlatformLogger$Level);
	if ($nc(HttpClient::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
		$nc(HttpClient::logger)->finest(msg);
	}
}

void HttpClient::resetProperties() {
	$load(HttpClient);
	$synchronized(class$) {
		$init(HttpClient);
	}
}

int32_t HttpClient::getKeepAliveTimeout() {
	return this->keepAliveTimeout;
}

bool HttpClient::getHttpKeepAliveSet() {
	return HttpClient::keepAliveProp;
}

void HttpClient::init$() {
	$NetworkClient::init$();
	$set(this, clientLock, $new($ReentrantLock));
	this->cachedHttpClient = false;
	$set(this, poster, nullptr);
	this->failedOnce = false;
	this->ignoreContinue = true;
	this->usingProxy = false;
	this->keepAliveConnections = -1;
	this->keepAliveTimeout = 0;
	$set(this, cacheRequest, nullptr);
	this->reuse = false;
	$set(this, capture, nullptr);
}

void HttpClient::init$($URL* url) {
	HttpClient::init$(url, ($String*)nullptr, -1, false);
}

void HttpClient::init$($URL* url, bool proxyDisabled) {
	HttpClient::init$(url, nullptr, -1, proxyDisabled);
}

void HttpClient::init$($URL* url, $String* proxyHost, int32_t proxyPort) {
	HttpClient::init$(url, proxyHost, proxyPort, false);
}

void HttpClient::init$($URL* url, $Proxy* p, int32_t to) {
	$NetworkClient::init$();
	$set(this, clientLock, $new($ReentrantLock));
	this->cachedHttpClient = false;
	$set(this, poster, nullptr);
	this->failedOnce = false;
	this->ignoreContinue = true;
	this->usingProxy = false;
	this->keepAliveConnections = -1;
	this->keepAliveTimeout = 0;
	$set(this, cacheRequest, nullptr);
	this->reuse = false;
	$set(this, capture, nullptr);
	$init($Proxy);
	$set(this, proxy, (p == nullptr) ? $Proxy::NO_PROXY : p);
	$set(this, host, $nc(url)->getHost());
	$set(this, url, url);
	this->port = url->getPort();
	if (this->port == -1) {
		this->port = getDefaultPort();
	}
	setConnectTimeout(to);
	$set(this, capture, $HttpCapture::getCapture(url));
	openServer();
}

$Proxy* HttpClient::newHttpProxy($String* proxyHost, int32_t proxyPort, $String* proto) {
	$init(HttpClient);
	if (proxyHost == nullptr || proto == nullptr) {
		$init($Proxy);
		return $Proxy::NO_PROXY;
	}
	int32_t pport = proxyPort < 0 ? getDefaultPort(proto) : proxyPort;
	$var($InetSocketAddress, saddr, $InetSocketAddress::createUnresolved(proxyHost, pport));
	$init($Proxy$Type);
	return $new($Proxy, $Proxy$Type::HTTP, saddr);
}

void HttpClient::init$($URL* url, $String* proxyHost, int32_t proxyPort, bool proxyDisabled) {
	$init($Proxy);
	HttpClient::init$(url, proxyDisabled ? $Proxy::NO_PROXY : $(newHttpProxy(proxyHost, proxyPort, "http"_s)), -1);
}

void HttpClient::init$($URL* url, $String* proxyHost, int32_t proxyPort, bool proxyDisabled, int32_t to) {
	$init($Proxy);
	HttpClient::init$(url, proxyDisabled ? $Proxy::NO_PROXY : $(newHttpProxy(proxyHost, proxyPort, "http"_s)), to);
}

HttpClient* HttpClient::New($URL* url) {
	$init(HttpClient);
	$init($Proxy);
	return HttpClient::New(url, $Proxy::NO_PROXY, -1, true, nullptr);
}

HttpClient* HttpClient::New($URL* url, bool useCache) {
	$init(HttpClient);
	$init($Proxy);
	return HttpClient::New(url, $Proxy::NO_PROXY, -1, useCache, nullptr);
}

HttpClient* HttpClient::New($URL* url, $Proxy* p$renamed, int32_t to, bool useCache, $HttpURLConnection* httpuc) {
	$init(HttpClient);
	$useLocalCurrentObjectStackCache();
	$var($Proxy, p, p$renamed);
	if (p == nullptr) {
		$init($Proxy);
		$assign(p, $Proxy::NO_PROXY);
	}
	$var(HttpClient, ret, nullptr);
	if (useCache) {
		$assign(ret, $nc(HttpClient::kac)->get(url, nullptr));
		bool var$0 = ret != nullptr && httpuc != nullptr && httpuc->streaming();
		if (var$0 && httpuc->getRequestMethod() == "POST"_s) {
			if (!ret->available()) {
				ret->inCache = false;
				ret->closeServer();
				$assign(ret, nullptr);
			}
		}
		if (ret != nullptr) {
			$init($AuthenticatorKeys);
			$var($String, ak, httpuc == nullptr ? $AuthenticatorKeys::DEFAULT : $nc(httpuc)->getAuthenticatorKey());
			bool var$1 = $Objects::equals(ret->proxy, p);
			bool compatible = var$1 && $Objects::equals($(ret->getAuthenticatorKey()), ak);
			if (compatible) {
				ret->lock();
				{
					$var($Throwable, var$2, nullptr);
					try {
						ret->cachedHttpClient = true;
						if (!HttpClient::$assertionsDisabled && !ret->inCache) {
							$throwNew($AssertionError);
						}
						ret->inCache = false;
						if (httpuc != nullptr && ret->needsTunneling()) {
							$init($HttpURLConnection$TunnelState);
							httpuc->setTunnelState($HttpURLConnection$TunnelState::TUNNELING);
						}
						logFinest($$str({"KeepAlive stream retrieved from the cache, "_s, ret}));
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						ret->unlock();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
			} else {
				ret->lock();
				{
					$var($Throwable, var$4, nullptr);
					try {
						ret->inCache = false;
						ret->closeServer();
					} catch ($Throwable& var$5) {
						$assign(var$4, var$5);
					} /*finally*/ {
						ret->unlock();
					}
					if (var$4 != nullptr) {
						$throw(var$4);
					}
				}
				$assign(ret, nullptr);
			}
		}
	}
	if (ret == nullptr) {
		$assign(ret, $new(HttpClient, url, p, to));
		if (httpuc != nullptr) {
			$set(ret, authenticatorKey, httpuc->getAuthenticatorKey());
		}
	} else {
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			$init($Proxy);
			if ($nc(ret)->proxy == $Proxy::NO_PROXY || $nc(ret)->proxy == nullptr) {
				$var($String, var$6, $nc($($InetAddress::getByName($($nc(url)->getHost()))))->getHostAddress());
				security->checkConnect(var$6, $nc(url)->getPort());
			} else {
				$var($String, var$7, $nc(url)->getHost());
				security->checkConnect(var$7, url->getPort());
			}
		}
		$set($nc(ret), url, url);
	}
	return ret;
}

HttpClient* HttpClient::New($URL* url, $Proxy* p, int32_t to, $HttpURLConnection* httpuc) {
	$init(HttpClient);
	return New(url, p, to, true, httpuc);
}

HttpClient* HttpClient::New($URL* url, $String* proxyHost, int32_t proxyPort, bool useCache) {
	$init(HttpClient);
	return New(url, $(newHttpProxy(proxyHost, proxyPort, "http"_s)), -1, useCache, nullptr);
}

HttpClient* HttpClient::New($URL* url, $String* proxyHost, int32_t proxyPort, bool useCache, int32_t to, $HttpURLConnection* httpuc) {
	$init(HttpClient);
	return New(url, $(newHttpProxy(proxyHost, proxyPort, "http"_s)), to, useCache, httpuc);
}

$String* HttpClient::getAuthenticatorKey() {
	$var($String, k, this->authenticatorKey);
	if (k == nullptr) {
		$init($AuthenticatorKeys);
		return $AuthenticatorKeys::DEFAULT;
	}
	return k;
}

void HttpClient::finished() {
	if (this->reuse) {
		return;
	}
	--this->keepAliveConnections;
	$set(this, poster, nullptr);
	bool var$0 = this->keepAliveConnections > 0 && isKeepingAlive();
	if (var$0 && !($nc(this->serverOutput)->checkError())) {
		putInKeepAliveCache();
	} else {
		closeServer();
	}
}

bool HttpClient::available() {
	$useLocalCurrentObjectStackCache();
	bool available = true;
	int32_t old = -1;
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				{
					$var($Throwable, var$1, nullptr);
					try {
						try {
							old = $nc(this->serverSocket)->getSoTimeout();
							$nc(this->serverSocket)->setSoTimeout(1);
							$var($BufferedInputStream, tmpbuf, $new($BufferedInputStream, $($nc(this->serverSocket)->getInputStream())));
							int32_t r = tmpbuf->read();
							if (r == -1) {
								logFinest("HttpClient.available(): read returned -1: not available"_s);
								available = false;
							}
						} catch ($SocketTimeoutException& e) {
							logFinest("HttpClient.available(): SocketTimeout: its available"_s);
						}
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						if (old != -1) {
							$nc(this->serverSocket)->setSoTimeout(old);
						}
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			} catch ($IOException& e) {
				logFinest("HttpClient.available(): SocketException: not available"_s);
				available = false;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return available;
}

void HttpClient::putInKeepAliveCache() {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->inCache) {
				if (!HttpClient::$assertionsDisabled) {
					$throwNew($AssertionError, $of("Duplicate put to keep alive cache"_s));
				}
				return$1 = true;
				goto $finally;
			}
			this->inCache = true;
			$nc(HttpClient::kac)->put(this->url, nullptr, this);
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

bool HttpClient::isInKeepAliveCache() {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = this->inCache;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
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

void HttpClient::closeIdleConnection() {
	$var(HttpClient, http, $nc(HttpClient::kac)->get(this->url, nullptr));
	if (http != nullptr) {
		http->closeServer();
	}
}

void HttpClient::openServer($String* server, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$set(this, serverSocket, doConnect(server, port));
	try {
		$var($OutputStream, out, $nc(this->serverSocket)->getOutputStream());
		if (this->capture != nullptr) {
			$assign(out, $new($HttpCaptureOutputStream, out, this->capture));
		}
		$init($NetworkClient);
		$set(this, serverOutput, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, out)), false, $NetworkClient::encoding));
	} catch ($UnsupportedEncodingException& e) {
		$init($NetworkClient);
		$throwNew($InternalError, $$str({$NetworkClient::encoding, " encoding not found"_s}), e);
	}
	$nc(this->serverSocket)->setTcpNoDelay(true);
}

bool HttpClient::needsTunneling() {
	return false;
}

bool HttpClient::isCachedConnection() {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = this->cachedHttpClient;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
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

void HttpClient::afterConnect() {
}

void HttpClient::privilegedOpenServer($InetSocketAddress* server) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!HttpClient::$assertionsDisabled && !$nc(this->clientLock)->isHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	try {
		$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($HttpClient$1, this, server)));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getException())));
	}
}

void HttpClient::superOpenServer($String* proxyHost, int32_t proxyPort) {
	$NetworkClient::openServer(proxyHost, proxyPort);
}

void HttpClient::openServer() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (security != nullptr) {
				security->checkConnect(this->host, this->port);
			}
			if (this->keepingAlive) {
				return$1 = true;
				goto $finally;
			}
			bool var$2 = $nc($($nc(this->url)->getProtocol()))->equals("http"_s);
			if (var$2 || $nc($($nc(this->url)->getProtocol()))->equals("https"_s)) {
				$init($Proxy$Type);
				if ((this->proxy != nullptr) && ($nc(this->proxy)->type() == $Proxy$Type::HTTP)) {
					$URLConnection::setProxiedHost(this->host);
					privilegedOpenServer($cast($InetSocketAddress, $($nc(this->proxy)->address())));
					this->usingProxy = true;
					return$1 = true;
					goto $finally;
				} else {
					openServer(this->host, this->port);
					this->usingProxy = false;
					return$1 = true;
					goto $finally;
				}
			} else {
				$init($Proxy$Type);
				if ((this->proxy != nullptr) && ($nc(this->proxy)->type() == $Proxy$Type::HTTP)) {
					$URLConnection::setProxiedHost(this->host);
					privilegedOpenServer($cast($InetSocketAddress, $($nc(this->proxy)->address())));
					this->usingProxy = true;
					return$1 = true;
					goto $finally;
				} else {
					$NetworkClient::openServer(this->host, this->port);
					this->usingProxy = false;
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

$String* HttpClient::getURLFile() {
	$useLocalCurrentObjectStackCache();
	$var($String, fileName, nullptr);
	if (this->usingProxy && !this->proxyDisabled) {
		$var($StringBuilder, result, $new($StringBuilder, 128));
		result->append($($nc(this->url)->getProtocol()));
		result->append(":"_s);
		bool var$0 = $nc(this->url)->getAuthority() != nullptr;
		if (var$0 && !$nc($($nc(this->url)->getAuthority()))->isEmpty()) {
			result->append("//"_s);
			result->append($($nc(this->url)->getAuthority()));
		}
		if ($nc(this->url)->getPath() != nullptr) {
			result->append($($nc(this->url)->getPath()));
		}
		if ($nc(this->url)->getQuery() != nullptr) {
			result->append(u'?');
			result->append($($nc(this->url)->getQuery()));
		}
		$assign(fileName, result->toString());
	} else {
		$assign(fileName, $nc(this->url)->getFile());
		if ((fileName == nullptr) || ($nc(fileName)->isEmpty())) {
			$assign(fileName, "/"_s);
		} else if (fileName->charAt(0) == u'?') {
			$assign(fileName, $str({"/"_s, fileName}));
		}
	}
	if ($nc(fileName)->indexOf((int32_t)u'\n') == -1) {
		return fileName;
	} else {
		$throwNew($MalformedURLException, "Illegal character in URL"_s);
	}
}

void HttpClient::writeRequests($MessageHeader* head) {
	$set(this, requests, head);
	$nc(this->requests)->print(this->serverOutput);
	$nc(this->serverOutput)->flush();
}

void HttpClient::writeRequests($MessageHeader* head, $PosterOutputStream* pos) {
	$set(this, requests, head);
	$nc(this->requests)->print(this->serverOutput);
	$set(this, poster, pos);
	if (this->poster != nullptr) {
		$nc(this->poster)->writeTo(this->serverOutput);
	}
	$nc(this->serverOutput)->flush();
}

void HttpClient::writeRequests($MessageHeader* head, $PosterOutputStream* pos, bool streaming) {
	this->streaming = streaming;
	writeRequests(head, pos);
}

bool HttpClient::parseHTTP($MessageHeader* responses, $ProgressSource* pi, $HttpURLConnection* httpuc) {
	$useLocalCurrentObjectStackCache();
	try {
		$set(this, serverInput, $nc(this->serverSocket)->getInputStream());
		if (this->capture != nullptr) {
			$set(this, serverInput, $new($HttpCaptureInputStream, this->serverInput, this->capture));
		}
		$set(this, serverInput, $new($BufferedInputStream, this->serverInput));
		return (parseHTTPHeader(responses, pi, httpuc));
	} catch ($SocketTimeoutException& stex) {
		if (this->ignoreContinue) {
			closeServer();
		}
		$throw(stex);
	} catch ($IOException& e) {
		closeServer();
		this->cachedHttpClient = false;
		if (!this->failedOnce && this->requests != nullptr) {
			this->failedOnce = true;
			bool var$0 = $nc($(getRequestMethod()))->equals("CONNECT"_s) || this->streaming;
			if (var$0 || ($nc($($nc(httpuc)->getRequestMethod()))->equals("POST"_s) && !HttpClient::retryPostProp)) {
			} else {
				openServer();
				checkTunneling(httpuc);
				afterConnect();
				writeRequests(this->requests, this->poster);
				return parseHTTP(responses, pi, httpuc);
			}
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

void HttpClient::checkTunneling($HttpURLConnection* httpuc) {
	$useLocalCurrentObjectStackCache();
	if (needsTunneling()) {
		$var($MessageHeader, origRequests, this->requests);
		$var($PosterOutputStream, origPoster, this->poster);
		$nc(httpuc)->doTunneling();
		$set(this, requests, origRequests);
		$set(this, poster, origPoster);
	}
}

bool HttpClient::parseHTTPHeader($MessageHeader* responses, $ProgressSource* pi, $HttpURLConnection* httpuc) {
	$useLocalCurrentObjectStackCache();
	this->keepAliveConnections = -1;
	this->keepAliveTimeout = 0;
	bool ret = false;
	$var($bytes, b, $new($bytes, 8));
	try {
		int32_t nread = 0;
		$nc(this->serverInput)->mark(10);
		while (nread < 8) {
			int32_t r = $nc(this->serverInput)->read(b, nread, 8 - nread);
			if (r < 0) {
				break;
			}
			nread += r;
		}
		$var($String, keep, nullptr);
		$var($String, authenticate, nullptr);
		ret = b->get(0) == u'H' && b->get(1) == u'T' && b->get(2) == u'T' && b->get(3) == u'P' && b->get(4) == u'/' && b->get(5) == u'1' && b->get(6) == u'.';
		$nc(this->serverInput)->reset();
		if (ret) {
			$nc(responses)->parseHeader(this->serverInput);
			$var($CookieHandler, cookieHandler, $nc(httpuc)->getCookieHandler());
			if (cookieHandler != nullptr) {
				$var($URI, uri, $ParseUtil::toURI(this->url));
				if (uri != nullptr) {
					cookieHandler->put(uri, $(responses->getHeaders()));
				}
			}
			if (this->usingProxy) {
				$assign(keep, responses->findValue("Proxy-Connection"_s));
				$assign(authenticate, responses->findValue("Proxy-Authenticate"_s));
			}
			if (keep == nullptr) {
				$assign(keep, responses->findValue("Connection"_s));
				$assign(authenticate, responses->findValue("WWW-Authenticate"_s));
			}
			bool canKeepAlive = !this->disableKeepAlive;
			if (canKeepAlive && (HttpClient::cacheNTLMProp == false || HttpClient::cacheSPNEGOProp == false) && authenticate != nullptr) {
				$init($Locale);
				$assign(authenticate, authenticate->toLowerCase($Locale::US));
				if (HttpClient::cacheNTLMProp == false) {
					canKeepAlive &= !authenticate->startsWith("ntlm "_s);
				}
				if (HttpClient::cacheSPNEGOProp == false) {
					canKeepAlive &= !authenticate->startsWith("negotiate "_s);
					canKeepAlive &= !authenticate->startsWith("kerberos "_s);
				}
			}
			this->disableKeepAlive |= !canKeepAlive;
			$init($Locale);
			if (keep != nullptr && $(keep->toLowerCase($Locale::US))->equals("keep-alive"_s)) {
				if (this->disableKeepAlive) {
					this->keepAliveConnections = 1;
				} else {
					$var($HeaderParser, p, $new($HeaderParser, $(responses->findValue("Keep-Alive"_s))));
					this->keepAliveConnections = p->findInt("max"_s, this->usingProxy ? 50 : 5);
					this->keepAliveTimeout = p->findInt("timeout"_s, this->usingProxy ? 60 : 5);
				}
			} else if (b->get(7) != u'0') {
				if (keep != nullptr || this->disableKeepAlive) {
					this->keepAliveConnections = 1;
				} else {
					this->keepAliveConnections = 5;
				}
			}
		} else if (nread != 8) {
			if (!this->failedOnce && this->requests != nullptr) {
				this->failedOnce = true;
				bool var$0 = $nc($(getRequestMethod()))->equals("CONNECT"_s) || this->streaming;
				if (var$0 || ($nc($($nc(httpuc)->getRequestMethod()))->equals("POST"_s) && !HttpClient::retryPostProp)) {
				} else {
					closeServer();
					this->cachedHttpClient = false;
					openServer();
					checkTunneling(httpuc);
					afterConnect();
					writeRequests(this->requests, this->poster);
					return parseHTTP(responses, pi, httpuc);
				}
			}
			$throwNew($SocketException, "Unexpected end of file from server"_s);
		} else {
			$nc(responses)->set("Content-type"_s, "unknown/unknown"_s);
		}
	} catch ($IOException& e) {
		$throw(e);
	}
	int32_t code = -1;
	try {
		$var($String, resp, nullptr);
		$assign(resp, $nc(responses)->getValue(0));
		int32_t ind = 0;
		ind = $nc(resp)->indexOf((int32_t)u' ');
		while (resp->charAt(ind) == u' ') {
			++ind;
		}
		code = $Integer::parseInt(resp, ind, ind + 3, 10);
	} catch ($Exception& e) {
	}
	if (code == HttpClient::HTTP_CONTINUE && this->ignoreContinue) {
		$nc(responses)->reset();
		return parseHTTPHeader(responses, pi, httpuc);
	}
	int64_t cl = -1;
	$var($String, te, $nc(responses)->findValue("Transfer-Encoding"_s));
	if (te != nullptr && te->equalsIgnoreCase("chunked"_s)) {
		$set(this, serverInput, $new($ChunkedInputStream, this->serverInput, this, responses));
		if (this->keepAliveConnections <= 1) {
			this->keepAliveConnections = 1;
			this->keepingAlive = false;
		} else {
			this->keepingAlive = !this->disableKeepAlive;
		}
		this->failedOnce = false;
	} else {
		$var($String, cls, responses->findValue("content-length"_s));
		if (cls != nullptr) {
			try {
				cl = $Long::parseLong(cls);
			} catch ($NumberFormatException& e) {
				cl = -1;
			}
		}
		$var($String, requestLine, $nc(this->requests)->getKey(0));
		if ((requestLine != nullptr && (requestLine->startsWith("HEAD"_s))) || code == $HttpURLConnection::HTTP_NOT_MODIFIED || code == $HttpURLConnection::HTTP_NO_CONTENT) {
			cl = 0;
		}
		if (this->keepAliveConnections > 1 && (cl >= 0 || code == $HttpURLConnection::HTTP_NOT_MODIFIED || code == $HttpURLConnection::HTTP_NO_CONTENT)) {
			this->keepingAlive = !this->disableKeepAlive;
			this->failedOnce = false;
		} else if (this->keepingAlive) {
			this->keepingAlive = false;
		}
	}
	if (cl > 0) {
		if (pi != nullptr) {
			pi->setContentType($(responses->findValue("content-type"_s)));
		}
		bool useKeepAliveStream = isKeepingAlive() || this->disableKeepAlive;
		if (useKeepAliveStream) {
			logFinest($$str({"KeepAlive stream used: "_s, this->url}));
			$set(this, serverInput, $new($KeepAliveStream, this->serverInput, pi, cl, this));
			this->failedOnce = false;
		} else {
			$set(this, serverInput, $new($MeteredStream, this->serverInput, pi, cl));
		}
	} else if (cl == -1) {
		if (pi != nullptr) {
			pi->setContentType($(responses->findValue("content-type"_s)));
			$set(this, serverInput, $new($MeteredStream, this->serverInput, pi, cl));
		} else {
		}
	} else if (pi != nullptr) {
		pi->finishTracking();
	}
	return ret;
}

$InputStream* HttpClient::getInputStream() {
	$useLocalCurrentObjectStackCache();
	lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($InputStream, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, this->serverInput);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
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

$OutputStream* HttpClient::getOutputStream() {
	return this->serverOutput;
}

$String* HttpClient::toString() {
	return $str({$($of(this)->getClass()->getName()), "("_s, this->url, ")"_s});
}

bool HttpClient::isKeepingAlive() {
	return getHttpKeepAliveSet() && this->keepingAlive;
}

void HttpClient::setCacheRequest($CacheRequest* cacheRequest) {
	$set(this, cacheRequest, cacheRequest);
}

$CacheRequest* HttpClient::getCacheRequest() {
	return this->cacheRequest;
}

$String* HttpClient::getRequestMethod() {
	$useLocalCurrentObjectStackCache();
	if (this->requests != nullptr) {
		$var($String, requestLine, $nc(this->requests)->getKey(0));
		if (requestLine != nullptr) {
			return $(requestLine->split("\\s+"_s))->get(0);
		}
	}
	return ""_s;
}

void HttpClient::setDoNotRetry(bool value) {
	this->failedOnce = value;
}

void HttpClient::setIgnoreContinue(bool value) {
	this->ignoreContinue = value;
}

void HttpClient::closeServer() {
	try {
		this->keepingAlive = false;
		$nc(this->serverSocket)->close();
	} catch ($Exception& e) {
	}
}

$String* HttpClient::getProxyHostUsed() {
	if (!this->usingProxy) {
		return nullptr;
	} else {
		return $nc(($cast($InetSocketAddress, $($nc(this->proxy)->address()))))->getHostString();
	}
}

int32_t HttpClient::getProxyPortUsed() {
	if (this->usingProxy) {
		return $nc(($cast($InetSocketAddress, $($nc(this->proxy)->address()))))->getPort();
	}
	return -1;
}

void HttpClient::lock() {
	$nc(this->clientLock)->lock();
}

void HttpClient::unlock() {
	$nc(this->clientLock)->unlock();
}

void clinit$HttpClient($Class* class$) {
	$useLocalCurrentObjectStackCache();
	HttpClient::$assertionsDisabled = !HttpClient::class$->desiredAssertionStatus();
	$assignStatic(HttpClient::kac, $new($KeepAliveCache));
	HttpClient::keepAliveProp = true;
	HttpClient::retryPostProp = true;
	$assignStatic(HttpClient::logger, $HttpURLConnection::getHttpLogger());
	{
		$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
		$var($String, keepAlive, $nc(props)->getProperty("http.keepAlive"_s));
		$var($String, retryPost, props->getProperty("sun.net.http.retryPost"_s));
		$var($String, cacheNTLM, props->getProperty("jdk.ntlm.cache"_s));
		$var($String, cacheSPNEGO, props->getProperty("jdk.spnego.cache"_s));
		if (keepAlive != nullptr) {
			HttpClient::keepAliveProp = $Boolean::parseBoolean(keepAlive);
		} else {
			HttpClient::keepAliveProp = true;
		}
		if (retryPost != nullptr) {
			HttpClient::retryPostProp = $Boolean::parseBoolean(retryPost);
		} else {
			HttpClient::retryPostProp = true;
		}
		if (cacheNTLM != nullptr) {
			HttpClient::cacheNTLMProp = $Boolean::parseBoolean(cacheNTLM);
		} else {
			HttpClient::cacheNTLMProp = true;
		}
		if (cacheSPNEGO != nullptr) {
			HttpClient::cacheSPNEGOProp = $Boolean::parseBoolean(cacheSPNEGO);
		} else {
			HttpClient::cacheSPNEGOProp = true;
		}
	}
}

HttpClient::HttpClient() {
}

$Class* HttpClient::load$($String* name, bool initialize) {
	$loadClass(HttpClient, name, initialize, &_HttpClient_ClassInfo_, clinit$HttpClient, allocate$HttpClient);
	return class$;
}

$Class* HttpClient::class$ = nullptr;

			} // http
		} // www
	} // net
} // sun