#include <sun/security/ssl/SSLSocketFactoryImpl.h>

#include <java/io/InputStream.h>
#include <java/net/InetAddress.h>
#include <java/net/Socket.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/SSLContextImpl$DefaultSSLContext.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLSocketImpl.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $InetAddress = ::java::net::InetAddress;
using $Socket = ::java::net::Socket;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLContextImpl$DefaultSSLContext = ::sun::security::ssl::SSLContextImpl$DefaultSSLContext;
using $SSLSocketImpl = ::sun::security::ssl::SSLSocketImpl;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSocketFactoryImpl_FieldInfo_[] = {
	{"context", "Lsun/security/ssl/SSLContextImpl;", nullptr, $PRIVATE | $FINAL, $field(SSLSocketFactoryImpl, context)},
	{}
};

$MethodInfo _SSLSocketFactoryImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SSLSocketFactoryImpl, init$, void), "java.lang.Exception"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;)V", nullptr, 0, $method(SSLSocketFactoryImpl, init$, void, $SSLContextImpl*)},
	{"createSocket", "()Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*)},
	{"createSocket", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*, $String*, int32_t), "java.io.IOException,java.net.UnknownHostException"},
	{"createSocket", "(Ljava/net/Socket;Ljava/lang/String;IZ)Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*, $Socket*, $String*, int32_t, bool), "java.io.IOException"},
	{"createSocket", "(Ljava/net/Socket;Ljava/io/InputStream;Z)Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*, $Socket*, $InputStream*, bool), "java.io.IOException"},
	{"createSocket", "(Ljava/net/InetAddress;I)Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*, $InetAddress*, int32_t), "java.io.IOException"},
	{"createSocket", "(Ljava/lang/String;ILjava/net/InetAddress;I)Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*, $String*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"createSocket", "(Ljava/net/InetAddress;ILjava/net/InetAddress;I)Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, createSocket, $Socket*, $InetAddress*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"getDefaultCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, getDefaultCipherSuites, $StringArray*)},
	{"getSupportedCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLSocketFactoryImpl, getSupportedCipherSuites, $StringArray*)},
	{}
};

$ClassInfo _SSLSocketFactoryImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLSocketFactoryImpl",
	"javax.net.ssl.SSLSocketFactory",
	nullptr,
	_SSLSocketFactoryImpl_FieldInfo_,
	_SSLSocketFactoryImpl_MethodInfo_
};

$Object* allocate$SSLSocketFactoryImpl($Class* clazz) {
	return $of($alloc(SSLSocketFactoryImpl));
}

void SSLSocketFactoryImpl::init$() {
	$SSLSocketFactory::init$();
	$set(this, context, $SSLContextImpl$DefaultSSLContext::getDefaultImpl());
}

void SSLSocketFactoryImpl::init$($SSLContextImpl* context) {
	$SSLSocketFactory::init$();
	$set(this, context, context);
}

$Socket* SSLSocketFactoryImpl::createSocket() {
	return $new($SSLSocketImpl, this->context);
}

$Socket* SSLSocketFactoryImpl::createSocket($String* host, int32_t port) {
	return $new($SSLSocketImpl, this->context, host, port);
}

$Socket* SSLSocketFactoryImpl::createSocket($Socket* s, $String* host, int32_t port, bool autoClose) {
	return $new($SSLSocketImpl, this->context, s, host, port, autoClose);
}

$Socket* SSLSocketFactoryImpl::createSocket($Socket* s, $InputStream* consumed, bool autoClose) {
	if (s == nullptr) {
		$throwNew($NullPointerException, "the existing socket cannot be null"_s);
	}
	return $new($SSLSocketImpl, this->context, s, consumed, autoClose);
}

$Socket* SSLSocketFactoryImpl::createSocket($InetAddress* address, int32_t port) {
	return $new($SSLSocketImpl, this->context, address, port);
}

$Socket* SSLSocketFactoryImpl::createSocket($String* host, int32_t port, $InetAddress* clientAddress, int32_t clientPort) {
	return $new($SSLSocketImpl, this->context, host, port, clientAddress, clientPort);
}

$Socket* SSLSocketFactoryImpl::createSocket($InetAddress* address, int32_t port, $InetAddress* clientAddress, int32_t clientPort) {
	return $new($SSLSocketImpl, this->context, address, port, clientAddress, clientPort);
}

$StringArray* SSLSocketFactoryImpl::getDefaultCipherSuites() {
	return $CipherSuite::namesOf($($nc(this->context)->getDefaultCipherSuites(false)));
}

$StringArray* SSLSocketFactoryImpl::getSupportedCipherSuites() {
	return $CipherSuite::namesOf($($nc(this->context)->getSupportedCipherSuites()));
}

SSLSocketFactoryImpl::SSLSocketFactoryImpl() {
}

$Class* SSLSocketFactoryImpl::load$($String* name, bool initialize) {
	$loadClass(SSLSocketFactoryImpl, name, initialize, &_SSLSocketFactoryImpl_ClassInfo_, allocate$SSLSocketFactoryImpl);
	return class$;
}

$Class* SSLSocketFactoryImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun