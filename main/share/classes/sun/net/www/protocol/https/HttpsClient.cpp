#include <sun/net/www/protocol/https/HttpsClient.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/AbstractMethodError.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/URL.h>
#include <java/security/Principal.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/StringTokenizer.h>
#include <java/util/Vector.h>
#include <javax/net/ssl/HandshakeCompletedEvent.h>
#include <javax/net/ssl/HandshakeCompletedListener.h>
#include <javax/net/ssl/HostnameVerifier.h>
#include <javax/net/ssl/SNIHostName.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLPeerUnverifiedException.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/net/NetworkClient.h>
#include <sun/net/www/http/HttpClient.h>
#include <sun/net/www/http/KeepAliveCache.h>
#include <sun/net/www/protocol/http/AuthenticatorKeys.h>
#include <sun/net/www/protocol/http/HttpURLConnection$TunnelState.h>
#include <sun/net/www/protocol/http/HttpURLConnection.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/ssl/SSLSocketImpl.h>
#include <sun/security/util/HostnameChecker.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef DEFAULT
#undef DIRECT
#undef FINEST
#undef NO_PROXY
#undef SOCKS
#undef TUNNELING
#undef TYPE_TLS

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $AbstractMethodError = ::java::lang::AbstractMethodError;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $Socket = ::java::net::Socket;
using $SocketException = ::java::net::SocketException;
using $URL = ::java::net::URL;
using $Principal = ::java::security::Principal;
using $CertificateException = ::java::security::cert::CertificateException;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Vector = ::java::util::Vector;
using $HandshakeCompletedEvent = ::javax::net::ssl::HandshakeCompletedEvent;
using $HandshakeCompletedListener = ::javax::net::ssl::HandshakeCompletedListener;
using $HostnameVerifier = ::javax::net::ssl::HostnameVerifier;
using $SNIHostName = ::javax::net::ssl::SNIHostName;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLPeerUnverifiedException = ::javax::net::ssl::SSLPeerUnverifiedException;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;
using $NetworkClient = ::sun::net::NetworkClient;
using $HttpClient = ::sun::net::www::http::HttpClient;
using $KeepAliveCache = ::sun::net::www::http::KeepAliveCache;
using $AuthenticatorKeys = ::sun::net::www::protocol::http::AuthenticatorKeys;
using $HttpURLConnection = ::sun::net::www::protocol::http::HttpURLConnection;
using $HttpURLConnection$TunnelState = ::sun::net::www::protocol::http::HttpURLConnection$TunnelState;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $SSLSocketImpl = ::sun::security::ssl::SSLSocketImpl;
using $HostnameChecker = ::sun::security::util::HostnameChecker;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace https {

$FieldInfo _HttpsClient_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpsClient, $assertionsDisabled)},
	{"httpsPortNumber", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpsClient, httpsPortNumber)},
	{"defaultHVCanonicalName", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpsClient, defaultHVCanonicalName)},
	{"hv", "Ljavax/net/ssl/HostnameVerifier;", nullptr, $PRIVATE, $field(HttpsClient, hv)},
	{"sslSocketFactory", "Ljavax/net/ssl/SSLSocketFactory;", nullptr, $PRIVATE, $field(HttpsClient, sslSocketFactory)},
	{"session", "Ljavax/net/ssl/SSLSession;", nullptr, $PRIVATE, $field(HttpsClient, session)},
	{}
};

$MethodInfo _HttpsClient_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;)V", nullptr, $PRIVATE, $method(HttpsClient, init$, void, $SSLSocketFactory*, $URL*), "java.io.IOException"},
	{"<init>", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljava/lang/String;I)V", nullptr, 0, $method(HttpsClient, init$, void, $SSLSocketFactory*, $URL*, $String*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljava/lang/String;II)V", nullptr, 0, $method(HttpsClient, init$, void, $SSLSocketFactory*, $URL*, $String*, int32_t, int32_t), "java.io.IOException"},
	{"<init>", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljava/net/Proxy;I)V", nullptr, 0, $method(HttpsClient, init$, void, $SSLSocketFactory*, $URL*, $Proxy*, int32_t), "java.io.IOException"},
	{"New", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljavax/net/ssl/HostnameVerifier;Lsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $STATIC, $staticMethod(HttpsClient, New, $HttpClient*, $SSLSocketFactory*, $URL*, $HostnameVerifier*, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljavax/net/ssl/HostnameVerifier;ZLsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $STATIC, $staticMethod(HttpsClient, New, $HttpClient*, $SSLSocketFactory*, $URL*, $HostnameVerifier*, bool, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljavax/net/ssl/HostnameVerifier;Ljava/lang/String;ILsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $STATIC, $staticMethod(HttpsClient, New, $HttpClient*, $SSLSocketFactory*, $URL*, $HostnameVerifier*, $String*, int32_t, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljavax/net/ssl/HostnameVerifier;Ljava/lang/String;IZLsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $STATIC, $staticMethod(HttpsClient, New, $HttpClient*, $SSLSocketFactory*, $URL*, $HostnameVerifier*, $String*, int32_t, bool, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljavax/net/ssl/HostnameVerifier;Ljava/lang/String;IZILsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $STATIC, $staticMethod(HttpsClient, New, $HttpClient*, $SSLSocketFactory*, $URL*, $HostnameVerifier*, $String*, int32_t, bool, int32_t, $HttpURLConnection*), "java.io.IOException"},
	{"New", "(Ljavax/net/ssl/SSLSocketFactory;Ljava/net/URL;Ljavax/net/ssl/HostnameVerifier;Ljava/net/Proxy;ZILsun/net/www/protocol/http/HttpURLConnection;)Lsun/net/www/http/HttpClient;", nullptr, $STATIC, $staticMethod(HttpsClient, New, $HttpClient*, $SSLSocketFactory*, $URL*, $HostnameVerifier*, $Proxy*, bool, int32_t, $HttpURLConnection*), "java.io.IOException"},
	{"afterConnect", "()V", nullptr, $PUBLIC, $virtualMethod(HttpsClient, afterConnect, void), "java.io.IOException,java.net.UnknownHostException"},
	{"checkURLSpoofing", "(Ljavax/net/ssl/HostnameVerifier;)V", nullptr, $PRIVATE, $method(HttpsClient, checkURLSpoofing, void, $HostnameVerifier*), "java.io.IOException"},
	{"closeIdleConnection", "()V", nullptr, $PUBLIC, $virtualMethod(HttpsClient, closeIdleConnection, void)},
	{"createSocket", "()Ljava/net/Socket;", nullptr, $PROTECTED, $virtualMethod(HttpsClient, createSocket, $Socket*), "java.io.IOException"},
	{"getCipherSuite", "()Ljava/lang/String;", nullptr, 0, $method(HttpsClient, getCipherSuite, $String*)},
	{"getCipherSuites", "()[Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpsClient, getCipherSuites, $StringArray*)},
	{"getDefaultPort", "()I", nullptr, $PROTECTED, $virtualMethod(HttpsClient, getDefaultPort, int32_t)},
	{"getLocalCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $method(HttpsClient, getLocalCertificates, $CertificateArray*)},
	{"getLocalPrincipal", "()Ljava/security/Principal;", nullptr, 0, $method(HttpsClient, getLocalPrincipal, $Principal*)},
	{"getPeerPrincipal", "()Ljava/security/Principal;", nullptr, 0, $method(HttpsClient, getPeerPrincipal, $Principal*), "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getProtocols", "()[Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpsClient, getProtocols, $StringArray*)},
	{"getProxyHostUsed", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpsClient, getProxyHostUsed, $String*)},
	{"getProxyPortUsed", "()I", nullptr, $PUBLIC, $virtualMethod(HttpsClient, getProxyPortUsed, int32_t)},
	{"getSSLSession", "()Ljavax/net/ssl/SSLSession;", nullptr, 0, $method(HttpsClient, getSSLSession, $SSLSession*)},
	{"getSSLSocketFactory", "()Ljavax/net/ssl/SSLSocketFactory;", nullptr, 0, $method(HttpsClient, getSSLSocketFactory, $SSLSocketFactory*)},
	{"getServerCertificates", "()[Ljava/security/cert/Certificate;", nullptr, 0, $method(HttpsClient, getServerCertificates, $CertificateArray*), "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getUserAgent", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpsClient, getUserAgent, $String*)},
	{"handshakeCompleted", "(Ljavax/net/ssl/HandshakeCompletedEvent;)V", nullptr, $PUBLIC, $virtualMethod(HttpsClient, handshakeCompleted, void, $HandshakeCompletedEvent*)},
	{"needsTunneling", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpsClient, needsTunneling, bool)},
	{"putInKeepAliveCache", "()V", nullptr, $PROTECTED, $virtualMethod(HttpsClient, putInKeepAliveCache, void)},
	{"setHostnameVerifier", "(Ljavax/net/ssl/HostnameVerifier;)V", nullptr, 0, $method(HttpsClient, setHostnameVerifier, void, $HostnameVerifier*)},
	{"setSSLSocketFactory", "(Ljavax/net/ssl/SSLSocketFactory;)V", nullptr, 0, $method(HttpsClient, setSSLSocketFactory, void, $SSLSocketFactory*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HttpsClient_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.net.www.protocol.https.HttpsClient",
	"sun.net.www.http.HttpClient",
	"javax.net.ssl.HandshakeCompletedListener",
	_HttpsClient_FieldInfo_,
	_HttpsClient_MethodInfo_
};

$Object* allocate$HttpsClient($Class* clazz) {
	return $of($alloc(HttpsClient));
}

$String* HttpsClient::toString() {
	 return this->$HttpClient::toString();
}

int32_t HttpsClient::hashCode() {
	 return this->$HttpClient::hashCode();
}

bool HttpsClient::equals(Object$* obj) {
	 return this->$HttpClient::equals(obj);
}

$Object* HttpsClient::clone() {
	 return this->$HttpClient::clone();
}

void HttpsClient::finalize() {
	this->$HttpClient::finalize();
}

bool HttpsClient::$assertionsDisabled = false;
$String* HttpsClient::defaultHVCanonicalName = nullptr;

int32_t HttpsClient::getDefaultPort() {
	return HttpsClient::httpsPortNumber;
}

$StringArray* HttpsClient::getCipherSuites() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, ciphers, nullptr);
	$var($String, cipherString, $GetPropertyAction::privilegedGetProperty("https.cipherSuites"_s));
	if (cipherString == nullptr || $nc(cipherString)->isEmpty()) {
		$assign(ciphers, nullptr);
	} else {
		$var($StringTokenizer, tokenizer, nullptr);
		$var($Vector, v, $new($Vector));
		$assign(tokenizer, $new($StringTokenizer, cipherString, ","_s));
		while (tokenizer->hasMoreTokens()) {
			v->addElement($(tokenizer->nextToken()));
		}
		$assign(ciphers, $new($StringArray, v->size()));
		for (int32_t i = 0; i < ciphers->length; ++i) {
			ciphers->set(i, $cast($String, $(v->elementAt(i))));
		}
	}
	return ciphers;
}

$StringArray* HttpsClient::getProtocols() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, protocols, nullptr);
	$var($String, protocolString, $GetPropertyAction::privilegedGetProperty("https.protocols"_s));
	if (protocolString == nullptr || $nc(protocolString)->isEmpty()) {
		$assign(protocols, nullptr);
	} else {
		$var($StringTokenizer, tokenizer, nullptr);
		$var($Vector, v, $new($Vector));
		$assign(tokenizer, $new($StringTokenizer, protocolString, ","_s));
		while (tokenizer->hasMoreTokens()) {
			v->addElement($(tokenizer->nextToken()));
		}
		$assign(protocols, $new($StringArray, v->size()));
		for (int32_t i = 0; i < protocols->length; ++i) {
			protocols->set(i, $cast($String, $(v->elementAt(i))));
		}
	}
	return protocols;
}

$String* HttpsClient::getUserAgent() {
	$var($String, userAgent, $GetPropertyAction::privilegedGetProperty("https.agent"_s));
	if (userAgent == nullptr || $nc(userAgent)->isEmpty()) {
		$assign(userAgent, "JSSE"_s);
	}
	return userAgent;
}

void HttpsClient::init$($SSLSocketFactory* sf, $URL* url) {
	HttpsClient::init$(sf, url, ($String*)nullptr, -1);
}

void HttpsClient::init$($SSLSocketFactory* sf, $URL* url, $String* proxyHost, int32_t proxyPort) {
	HttpsClient::init$(sf, url, proxyHost, proxyPort, -1);
}

void HttpsClient::init$($SSLSocketFactory* sf, $URL* url, $String* proxyHost, int32_t proxyPort, int32_t connectTimeout) {
	HttpsClient::init$(sf, url, (proxyHost == nullptr ? ($Proxy*)nullptr : $($HttpClient::newHttpProxy(proxyHost, proxyPort, "https"_s))), connectTimeout);
}

void HttpsClient::init$($SSLSocketFactory* sf, $URL* url, $Proxy* proxy, int32_t connectTimeout) {
	$useLocalCurrentObjectStackCache();
	$HttpClient::init$();
	$var($PlatformLogger, logger, $HttpURLConnection::getHttpLogger());
	$init($PlatformLogger$Level);
	if ($nc(logger)->isLoggable($PlatformLogger$Level::FINEST)) {
		logger->finest($$str({"Creating new HttpsClient with url:"_s, url, " and proxy:"_s, proxy, " with connect timeout:"_s, $$str(connectTimeout)}));
	}
	$set(this, proxy, proxy);
	setSSLSocketFactory(sf);
	this->proxyDisabled = true;
	$set(this, host, $nc(url)->getHost());
	$set(this, url, url);
	this->port = url->getPort();
	if (this->port == -1) {
		this->port = getDefaultPort();
	}
	setConnectTimeout(connectTimeout);
	openServer();
}

$HttpClient* HttpsClient::New($SSLSocketFactory* sf, $URL* url, $HostnameVerifier* hv, $HttpURLConnection* httpuc) {
	$init(HttpsClient);
	return HttpsClient::New(sf, url, hv, true, httpuc);
}

$HttpClient* HttpsClient::New($SSLSocketFactory* sf, $URL* url, $HostnameVerifier* hv, bool useCache, $HttpURLConnection* httpuc) {
	$init(HttpsClient);
	return HttpsClient::New(sf, url, hv, ($String*)nullptr, -1, useCache, httpuc);
}

$HttpClient* HttpsClient::New($SSLSocketFactory* sf, $URL* url, $HostnameVerifier* hv, $String* proxyHost, int32_t proxyPort, $HttpURLConnection* httpuc) {
	$init(HttpsClient);
	return HttpsClient::New(sf, url, hv, proxyHost, proxyPort, true, httpuc);
}

$HttpClient* HttpsClient::New($SSLSocketFactory* sf, $URL* url, $HostnameVerifier* hv, $String* proxyHost, int32_t proxyPort, bool useCache, $HttpURLConnection* httpuc) {
	$init(HttpsClient);
	return HttpsClient::New(sf, url, hv, proxyHost, proxyPort, useCache, -1, httpuc);
}

$HttpClient* HttpsClient::New($SSLSocketFactory* sf, $URL* url, $HostnameVerifier* hv, $String* proxyHost, int32_t proxyPort, bool useCache, int32_t connectTimeout, $HttpURLConnection* httpuc) {
	$init(HttpsClient);
	return HttpsClient::New(sf, url, hv, (proxyHost == nullptr ? ($Proxy*)nullptr : $($HttpClient::newHttpProxy(proxyHost, proxyPort, "https"_s))), useCache, connectTimeout, httpuc);
}

$HttpClient* HttpsClient::New($SSLSocketFactory* sf, $URL* url, $HostnameVerifier* hv, $Proxy* p$renamed, bool useCache, int32_t connectTimeout, $HttpURLConnection* httpuc) {
	$init(HttpsClient);
	$useLocalCurrentObjectStackCache();
	$var($Proxy, p, p$renamed);
	if (p == nullptr) {
		$init($Proxy);
		$assign(p, $Proxy::NO_PROXY);
	}
	$var($PlatformLogger, logger, $HttpURLConnection::getHttpLogger());
	$init($PlatformLogger$Level);
	if ($nc(logger)->isLoggable($PlatformLogger$Level::FINEST)) {
		logger->finest($$str({"Looking for HttpClient for URL "_s, url, " and proxy value of "_s, p}));
	}
	$var(HttpsClient, ret, nullptr);
	if (useCache) {
		$init($HttpClient);
		$assign(ret, $cast(HttpsClient, $nc($HttpClient::kac)->get(url, sf)));
		bool var$0 = ret != nullptr && httpuc != nullptr && httpuc->streaming();
		if (var$0 && httpuc->getRequestMethod() == "POST"_s) {
			if (!ret->available()) {
				$assign(ret, nullptr);
			}
		}
		if (ret != nullptr) {
			$init($AuthenticatorKeys);
			$var($String, ak, httpuc == nullptr ? $AuthenticatorKeys::DEFAULT : $nc(httpuc)->getAuthenticatorKey());
			$init($Proxy);
			bool var$1 = ((ret->proxy != nullptr && $nc(ret->proxy)->equals(p)) || (ret->proxy == nullptr && p == $Proxy::NO_PROXY));
			bool compatible = var$1 && $Objects::equals($(ret->getAuthenticatorKey()), ak);
			if (compatible) {
				ret->lock();
				{
					$var($Throwable, var$2, nullptr);
					try {
						ret->cachedHttpClient = true;
						if (!HttpsClient::$assertionsDisabled && !ret->inCache) {
							$throwNew($AssertionError);
						}
						ret->inCache = false;
						if (httpuc != nullptr && ret->needsTunneling()) {
							$init($HttpURLConnection$TunnelState);
							httpuc->setTunnelState($HttpURLConnection$TunnelState::TUNNELING);
						}
						if ($nc(logger)->isLoggable($PlatformLogger$Level::FINEST)) {
							logger->finest($$str({"KeepAlive stream retrieved from the cache, "_s, ret}));
						}
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
						if ($nc(logger)->isLoggable($PlatformLogger$Level::FINEST)) {
							logger->finest($$str({"Not returning this connection to cache: "_s, ret}));
						}
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
		$assign(ret, $new(HttpsClient, sf, url, p, connectTimeout));
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
	$nc(ret)->setHostnameVerifier(hv);
	return ret;
}

void HttpsClient::setHostnameVerifier($HostnameVerifier* hv) {
	$set(this, hv, hv);
}

void HttpsClient::setSSLSocketFactory($SSLSocketFactory* sf) {
	$set(this, sslSocketFactory, sf);
}

$SSLSocketFactory* HttpsClient::getSSLSocketFactory() {
	return this->sslSocketFactory;
}

$Socket* HttpsClient::createSocket() {
	try {
		return $nc(this->sslSocketFactory)->createSocket();
	} catch ($SocketException& se) {
		$var($Throwable, t, se->getCause());
		if ($instanceOf($UnsupportedOperationException, t)) {
			return $HttpClient::createSocket();
		} else {
			$throw(se);
		}
	}
	$shouldNotReachHere();
}

bool HttpsClient::needsTunneling() {
	$init($Proxy$Type);
	bool var$0 = this->proxy != nullptr && $nc(this->proxy)->type() != $Proxy$Type::DIRECT;
	return (var$0 && $nc(this->proxy)->type() != $Proxy$Type::SOCKS);
}

void HttpsClient::afterConnect() {
	$useLocalCurrentObjectStackCache();
	if (!isCachedConnection()) {
		$var($SSLSocket, s, nullptr);
		$var($SSLSocketFactory, factory, this->sslSocketFactory);
		try {
			if (!($instanceOf($SSLSocket, this->serverSocket))) {
				$assign(s, $cast($SSLSocket, $nc(factory)->createSocket(this->serverSocket, this->host, this->port, true)));
			} else {
				$assign(s, $cast($SSLSocket, this->serverSocket));
				if ($instanceOf($SSLSocketImpl, s)) {
					$nc(($cast($SSLSocketImpl, s)))->setHost(this->host);
				}
			}
		} catch ($IOException& ex) {
			try {
				$assign(s, $cast($SSLSocket, $nc(factory)->createSocket(this->host, this->port)));
			} catch ($IOException& ignored) {
				$throw(ex);
			}
		}
		$var($StringArray, protocols, getProtocols());
		$var($StringArray, ciphers, getCipherSuites());
		if (protocols != nullptr) {
			$nc(s)->setEnabledProtocols(protocols);
		}
		if (ciphers != nullptr) {
			$nc(s)->setEnabledCipherSuites(ciphers);
		}
		$nc(s)->addHandshakeCompletedListener(this);
		bool needToCheckSpoofing = true;
		$var($String, identification, $nc($(s->getSSLParameters()))->getEndpointIdentificationAlgorithm());
		if (identification != nullptr && identification->length() != 0) {
			if (identification->equalsIgnoreCase("HTTPS"_s)) {
				needToCheckSpoofing = false;
			}
		} else {
			bool isDefaultHostnameVerifier = false;
			if (this->hv != nullptr) {
				$var($String, canonicalName, $nc($of(this->hv))->getClass()->getCanonicalName());
				if (canonicalName != nullptr && canonicalName->equalsIgnoreCase(HttpsClient::defaultHVCanonicalName)) {
					isDefaultHostnameVerifier = true;
				}
			} else {
				isDefaultHostnameVerifier = true;
			}
			if (isDefaultHostnameVerifier) {
				$var($SSLParameters, paramaters, s->getSSLParameters());
				$nc(paramaters)->setEndpointIdentificationAlgorithm("HTTPS"_s);
				if (!($instanceOf($SSLSocketImpl, s))) {
					paramaters->setServerNames($($List::of($of($$new($SNIHostName, this->host)))));
				}
				s->setSSLParameters(paramaters);
				needToCheckSpoofing = false;
			}
		}
		s->startHandshake();
		$set(this, session, s->getSession());
		$set(this, serverSocket, s);
		try {
			$init($NetworkClient);
			$set(this, serverOutput, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, $($nc(this->serverSocket)->getOutputStream()))), false, $NetworkClient::encoding));
		} catch ($UnsupportedEncodingException& e) {
			$init($NetworkClient);
			$throwNew($InternalError, $$str({$NetworkClient::encoding, " encoding not found"_s}));
		}
		if (needToCheckSpoofing) {
			checkURLSpoofing(this->hv);
		}
	} else {
		$set(this, session, $nc(($cast($SSLSocket, this->serverSocket)))->getSession());
	}
}

void HttpsClient::checkURLSpoofing($HostnameVerifier* hostnameVerifier) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, $nc(this->url)->getHost());
	bool var$0 = host != nullptr && host->startsWith("["_s);
	if (var$0 && host->endsWith("]"_s)) {
		$assign(host, host->substring(1, host->length() - 1));
	}
	$var($CertificateArray, peerCerts, nullptr);
	$var($String, cipher, $nc(this->session)->getCipherSuite());
	try {
		$var($HostnameChecker, checker, $HostnameChecker::getInstance($HostnameChecker::TYPE_TLS));
		$assign(peerCerts, $nc(this->session)->getPeerCertificates());
		$var($X509Certificate, peerCert, nullptr);
		if ($instanceOf($X509Certificate, $nc(peerCerts)->get(0))) {
			$assign(peerCert, $cast($X509Certificate, peerCerts->get(0)));
		} else {
			$throwNew($SSLPeerUnverifiedException, ""_s);
		}
		$nc(checker)->match(host, peerCert);
		return;
	} catch ($SSLPeerUnverifiedException& e) {
	} catch ($CertificateException& cpe) {
	}
	if ((cipher != nullptr) && (cipher->indexOf("_anon_"_s) != -1)) {
		return;
	} else if ((hostnameVerifier != nullptr) && (hostnameVerifier->verify(host, this->session))) {
		return;
	}
	$nc(this->serverSocket)->close();
	$nc(this->session)->invalidate();
	$throwNew($IOException, $$str({"HTTPS hostname wrong:  should be <"_s, $($nc(this->url)->getHost()), ">"_s}));
}

void HttpsClient::putInKeepAliveCache() {
	if (this->inCache) {
		if (!HttpsClient::$assertionsDisabled) {
			$throwNew($AssertionError, $of("Duplicate put to keep alive cache"_s));
		}
		return;
	}
	this->inCache = true;
	$init($HttpClient);
	$nc($HttpClient::kac)->put(this->url, this->sslSocketFactory, this);
}

void HttpsClient::closeIdleConnection() {
	$init($HttpClient);
	$var($HttpClient, http, $nc($HttpClient::kac)->get(this->url, this->sslSocketFactory));
	if (http != nullptr) {
		http->closeServer();
	}
}

$String* HttpsClient::getCipherSuite() {
	return $nc(this->session)->getCipherSuite();
}

$CertificateArray* HttpsClient::getLocalCertificates() {
	return $nc(this->session)->getLocalCertificates();
}

$CertificateArray* HttpsClient::getServerCertificates() {
	return $nc(this->session)->getPeerCertificates();
}

$Principal* HttpsClient::getPeerPrincipal() {
	$useLocalCurrentObjectStackCache();
	$var($Principal, principal, nullptr);
	try {
		$assign(principal, $nc(this->session)->getPeerPrincipal());
	} catch ($AbstractMethodError& e) {
		$var($CertificateArray, certs, $nc(this->session)->getPeerCertificates());
		$assign(principal, $nc(($cast($X509Certificate, $nc(certs)->get(0))))->getSubjectX500Principal());
	}
	return principal;
}

$Principal* HttpsClient::getLocalPrincipal() {
	$useLocalCurrentObjectStackCache();
	$var($Principal, principal, nullptr);
	try {
		$assign(principal, $nc(this->session)->getLocalPrincipal());
	} catch ($AbstractMethodError& e) {
		$assign(principal, nullptr);
		$var($CertificateArray, certs, $nc(this->session)->getLocalCertificates());
		if (certs != nullptr) {
			$assign(principal, $nc(($cast($X509Certificate, certs->get(0))))->getSubjectX500Principal());
		}
	}
	return principal;
}

$SSLSession* HttpsClient::getSSLSession() {
	return this->session;
}

void HttpsClient::handshakeCompleted($HandshakeCompletedEvent* event) {
	$set(this, session, $nc(event)->getSession());
}

$String* HttpsClient::getProxyHostUsed() {
	if (!needsTunneling()) {
		return nullptr;
	} else {
		return $HttpClient::getProxyHostUsed();
	}
}

int32_t HttpsClient::getProxyPortUsed() {
	$init($Proxy$Type);
	bool var$0 = this->proxy == nullptr || $nc(this->proxy)->type() == $Proxy$Type::DIRECT;
	return (var$0 || $nc(this->proxy)->type() == $Proxy$Type::SOCKS) ? -1 : $nc(($cast($InetSocketAddress, $($nc(this->proxy)->address()))))->getPort();
}

void clinit$HttpsClient($Class* class$) {
	$assignStatic(HttpsClient::defaultHVCanonicalName, "javax.net.ssl.HttpsURLConnection.DefaultHostnameVerifier"_s);
	HttpsClient::$assertionsDisabled = !HttpsClient::class$->desiredAssertionStatus();
}

HttpsClient::HttpsClient() {
}

$Class* HttpsClient::load$($String* name, bool initialize) {
	$loadClass(HttpsClient, name, initialize, &_HttpsClient_ClassInfo_, clinit$HttpsClient, allocate$HttpsClient);
	return class$;
}

$Class* HttpsClient::class$ = nullptr;

				} // https
			} // protocol
		} // www
	} // net
} // sun