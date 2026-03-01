#include <sun/security/ssl/SSLServerSocketFactoryImpl.h>

#include <java/net/InetAddress.h>
#include <java/net/ServerSocket.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLServerSocketFactory.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/SSLContextImpl$DefaultSSLContext.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLServerSocketImpl.h>
#include <jcpp.h>

#undef DEFAULT_BACKLOG

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $SSLServerSocketFactory = ::javax::net::ssl::SSLServerSocketFactory;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLContextImpl$DefaultSSLContext = ::sun::security::ssl::SSLContextImpl$DefaultSSLContext;
using $SSLServerSocketImpl = ::sun::security::ssl::SSLServerSocketImpl;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLServerSocketFactoryImpl_FieldInfo_[] = {
	{"DEFAULT_BACKLOG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLServerSocketFactoryImpl, DEFAULT_BACKLOG)},
	{"context", "Lsun/security/ssl/SSLContextImpl;", nullptr, $PRIVATE | $FINAL, $field(SSLServerSocketFactoryImpl, context)},
	{}
};

$MethodInfo _SSLServerSocketFactoryImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SSLServerSocketFactoryImpl, init$, void), "java.lang.Exception"},
	{"<init>", "(Lsun/security/ssl/SSLContextImpl;)V", nullptr, 0, $method(SSLServerSocketFactoryImpl, init$, void, $SSLContextImpl*)},
	{"createServerSocket", "()Ljava/net/ServerSocket;", nullptr, $PUBLIC, $virtualMethod(SSLServerSocketFactoryImpl, createServerSocket, $ServerSocket*), "java.io.IOException"},
	{"createServerSocket", "(I)Ljava/net/ServerSocket;", nullptr, $PUBLIC, $virtualMethod(SSLServerSocketFactoryImpl, createServerSocket, $ServerSocket*, int32_t), "java.io.IOException"},
	{"createServerSocket", "(II)Ljava/net/ServerSocket;", nullptr, $PUBLIC, $virtualMethod(SSLServerSocketFactoryImpl, createServerSocket, $ServerSocket*, int32_t, int32_t), "java.io.IOException"},
	{"createServerSocket", "(IILjava/net/InetAddress;)Ljava/net/ServerSocket;", nullptr, $PUBLIC, $virtualMethod(SSLServerSocketFactoryImpl, createServerSocket, $ServerSocket*, int32_t, int32_t, $InetAddress*), "java.io.IOException"},
	{"getDefaultCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLServerSocketFactoryImpl, getDefaultCipherSuites, $StringArray*)},
	{"getSupportedCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLServerSocketFactoryImpl, getSupportedCipherSuites, $StringArray*)},
	{}
};

$ClassInfo _SSLServerSocketFactoryImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLServerSocketFactoryImpl",
	"javax.net.ssl.SSLServerSocketFactory",
	nullptr,
	_SSLServerSocketFactoryImpl_FieldInfo_,
	_SSLServerSocketFactoryImpl_MethodInfo_
};

$Object* allocate$SSLServerSocketFactoryImpl($Class* clazz) {
	return $of($alloc(SSLServerSocketFactoryImpl));
}

void SSLServerSocketFactoryImpl::init$() {
	$SSLServerSocketFactory::init$();
	$set(this, context, $SSLContextImpl$DefaultSSLContext::getDefaultImpl());
}

void SSLServerSocketFactoryImpl::init$($SSLContextImpl* context) {
	$SSLServerSocketFactory::init$();
	$set(this, context, context);
}

$ServerSocket* SSLServerSocketFactoryImpl::createServerSocket() {
	return $new($SSLServerSocketImpl, this->context);
}

$ServerSocket* SSLServerSocketFactoryImpl::createServerSocket(int32_t port) {
	return $new($SSLServerSocketImpl, this->context, port, SSLServerSocketFactoryImpl::DEFAULT_BACKLOG);
}

$ServerSocket* SSLServerSocketFactoryImpl::createServerSocket(int32_t port, int32_t backlog) {
	return $new($SSLServerSocketImpl, this->context, port, backlog);
}

$ServerSocket* SSLServerSocketFactoryImpl::createServerSocket(int32_t port, int32_t backlog, $InetAddress* ifAddress) {
	return $new($SSLServerSocketImpl, this->context, port, backlog, ifAddress);
}

$StringArray* SSLServerSocketFactoryImpl::getDefaultCipherSuites() {
	return $CipherSuite::namesOf($($nc(this->context)->getDefaultCipherSuites(true)));
}

$StringArray* SSLServerSocketFactoryImpl::getSupportedCipherSuites() {
	return $CipherSuite::namesOf($($nc(this->context)->getSupportedCipherSuites()));
}

SSLServerSocketFactoryImpl::SSLServerSocketFactoryImpl() {
}

$Class* SSLServerSocketFactoryImpl::load$($String* name, bool initialize) {
	$loadClass(SSLServerSocketFactoryImpl, name, initialize, &_SSLServerSocketFactoryImpl_ClassInfo_, allocate$SSLServerSocketFactoryImpl);
	return class$;
}

$Class* SSLServerSocketFactoryImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun