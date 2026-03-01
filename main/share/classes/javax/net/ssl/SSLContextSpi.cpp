#include <javax/net/ssl/SSLContextSpi.h>

#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/Socket.h>
#include <java/security/SecureRandom.h>
#include <javax/net/ssl/KeyManager.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLServerSocketFactory.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <javax/net/ssl/TrustManager.h>
#include <jcpp.h>

using $KeyManagerArray = $Array<::javax::net::ssl::KeyManager>;
using $TrustManagerArray = $Array<::javax::net::ssl::TrustManager>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $SecureRandom = ::java::security::SecureRandom;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLServerSocketFactory = ::javax::net::ssl::SSLServerSocketFactory;
using $SSLSessionContext = ::javax::net::ssl::SSLSessionContext;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;

namespace javax {
	namespace net {
		namespace ssl {

$MethodInfo _SSLContextSpi_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SSLContextSpi, init$, void)},
	{"engineCreateSSLEngine", "()Ljavax/net/ssl/SSLEngine;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineCreateSSLEngine, $SSLEngine*)},
	{"engineCreateSSLEngine", "(Ljava/lang/String;I)Ljavax/net/ssl/SSLEngine;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineCreateSSLEngine, $SSLEngine*, $String*, int32_t)},
	{"engineGetClientSessionContext", "()Ljavax/net/ssl/SSLSessionContext;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineGetClientSessionContext, $SSLSessionContext*)},
	{"engineGetDefaultSSLParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, $PROTECTED, $virtualMethod(SSLContextSpi, engineGetDefaultSSLParameters, $SSLParameters*)},
	{"engineGetServerSessionContext", "()Ljavax/net/ssl/SSLSessionContext;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineGetServerSessionContext, $SSLSessionContext*)},
	{"engineGetServerSocketFactory", "()Ljavax/net/ssl/SSLServerSocketFactory;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineGetServerSocketFactory, $SSLServerSocketFactory*)},
	{"engineGetSocketFactory", "()Ljavax/net/ssl/SSLSocketFactory;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineGetSocketFactory, $SSLSocketFactory*)},
	{"engineGetSupportedSSLParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, $PROTECTED, $virtualMethod(SSLContextSpi, engineGetSupportedSSLParameters, $SSLParameters*)},
	{"engineInit", "([Ljavax/net/ssl/KeyManager;[Ljavax/net/ssl/TrustManager;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SSLContextSpi, engineInit, void, $KeyManagerArray*, $TrustManagerArray*, $SecureRandom*), "java.security.KeyManagementException"},
	{"getDefaultSocket", "()Ljavax/net/ssl/SSLSocket;", nullptr, $PRIVATE, $method(SSLContextSpi, getDefaultSocket, $SSLSocket*)},
	{}
};

$ClassInfo _SSLContextSpi_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"javax.net.ssl.SSLContextSpi",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SSLContextSpi_MethodInfo_
};

$Object* allocate$SSLContextSpi($Class* clazz) {
	return $of($alloc(SSLContextSpi));
}

void SSLContextSpi::init$() {
}

$SSLSocket* SSLContextSpi::getDefaultSocket() {
	try {
		$var($SSLSocketFactory, factory, engineGetSocketFactory());
		return $cast($SSLSocket, $nc(factory)->createSocket());
	} catch ($IOException& e) {
		$throwNew($UnsupportedOperationException, "Could not obtain parameters"_s, e);
	}
	$shouldNotReachHere();
}

$SSLParameters* SSLContextSpi::engineGetDefaultSSLParameters() {
	$var($SSLSocket, socket, getDefaultSocket());
	return $nc(socket)->getSSLParameters();
}

$SSLParameters* SSLContextSpi::engineGetSupportedSSLParameters() {
	$useLocalCurrentObjectStackCache();
	$var($SSLSocket, socket, getDefaultSocket());
	$var($SSLParameters, params, $nc(socket)->getSSLParameters());
	$nc(params)->setCipherSuites($(socket->getSupportedCipherSuites()));
	params->setProtocols($(socket->getSupportedProtocols()));
	return params;
}

SSLContextSpi::SSLContextSpi() {
}

$Class* SSLContextSpi::load$($String* name, bool initialize) {
	$loadClass(SSLContextSpi, name, initialize, &_SSLContextSpi_ClassInfo_, allocate$SSLContextSpi);
	return class$;
}

$Class* SSLContextSpi::class$ = nullptr;

		} // ssl
	} // net
} // javax