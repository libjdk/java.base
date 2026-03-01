#include <javax/net/ssl/SSLServerSocketFactory.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <javax/net/ServerSocketFactory.h>
#include <javax/net/ssl/DefaultSSLServerSocketFactory.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLServerSocketFactory$DefaultFactoryHolder.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ServerSocketFactory = ::javax::net::ServerSocketFactory;
using $DefaultSSLServerSocketFactory = ::javax::net::ssl::DefaultSSLServerSocketFactory;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLServerSocketFactory$DefaultFactoryHolder = ::javax::net::ssl::SSLServerSocketFactory$DefaultFactoryHolder;

namespace javax {
	namespace net {
		namespace ssl {

$MethodInfo _SSLServerSocketFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(SSLServerSocketFactory, init$, void)},
	{"getDefault", "()Ljavax/net/ServerSocketFactory;", nullptr, $PUBLIC | $STATIC, $staticMethod(SSLServerSocketFactory, getDefault, $ServerSocketFactory*)},
	{"getDefaultCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SSLServerSocketFactory, getDefaultCipherSuites, $StringArray*)},
	{"getSupportedCipherSuites", "()[Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SSLServerSocketFactory, getSupportedCipherSuites, $StringArray*)},
	{}
};

$InnerClassInfo _SSLServerSocketFactory_InnerClassesInfo_[] = {
	{"javax.net.ssl.SSLServerSocketFactory$DefaultFactoryHolder", "javax.net.ssl.SSLServerSocketFactory", "DefaultFactoryHolder", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SSLServerSocketFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"javax.net.ssl.SSLServerSocketFactory",
	"javax.net.ServerSocketFactory",
	nullptr,
	nullptr,
	_SSLServerSocketFactory_MethodInfo_,
	nullptr,
	nullptr,
	_SSLServerSocketFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.net.ssl.SSLServerSocketFactory$DefaultFactoryHolder"
};

$Object* allocate$SSLServerSocketFactory($Class* clazz) {
	return $of($alloc(SSLServerSocketFactory));
}

void SSLServerSocketFactory::init$() {
	$ServerSocketFactory::init$();
}

$ServerSocketFactory* SSLServerSocketFactory::getDefault() {
	$init(SSLServerSocketFactory);
	$init($SSLServerSocketFactory$DefaultFactoryHolder);
	if ($SSLServerSocketFactory$DefaultFactoryHolder::defaultFactory != nullptr) {
		return $SSLServerSocketFactory$DefaultFactoryHolder::defaultFactory;
	}
	try {
		return $nc($($SSLContext::getDefault()))->getServerSocketFactory();
	} catch ($NoSuchAlgorithmException& e) {
		return $new($DefaultSSLServerSocketFactory, e);
	} catch ($UnsupportedOperationException& e) {
		return $new($DefaultSSLServerSocketFactory, e);
	}
	$shouldNotReachHere();
}

SSLServerSocketFactory::SSLServerSocketFactory() {
}

$Class* SSLServerSocketFactory::load$($String* name, bool initialize) {
	$loadClass(SSLServerSocketFactory, name, initialize, &_SSLServerSocketFactory_ClassInfo_, allocate$SSLServerSocketFactory);
	return class$;
}

$Class* SSLServerSocketFactory::class$ = nullptr;

		} // ssl
	} // net
} // javax