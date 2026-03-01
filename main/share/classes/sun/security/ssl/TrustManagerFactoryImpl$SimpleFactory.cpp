#include <sun/security/ssl/TrustManagerFactoryImpl$SimpleFactory.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/util/Collection.h>
#include <javax/net/ssl/ManagerFactoryParameters.h>
#include <javax/net/ssl/X509TrustManager.h>
#include <sun/security/ssl/TrustManagerFactoryImpl.h>
#include <sun/security/ssl/X509TrustManagerImpl.h>
#include <sun/security/validator/Validator.h>
#include <jcpp.h>

#undef TYPE_SIMPLE

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Collection = ::java::util::Collection;
using $ManagerFactoryParameters = ::javax::net::ssl::ManagerFactoryParameters;
using $X509TrustManager = ::javax::net::ssl::X509TrustManager;
using $TrustManagerFactoryImpl = ::sun::security::ssl::TrustManagerFactoryImpl;
using $X509TrustManagerImpl = ::sun::security::ssl::X509TrustManagerImpl;
using $Validator = ::sun::security::validator::Validator;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _TrustManagerFactoryImpl$SimpleFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TrustManagerFactoryImpl$SimpleFactory, init$, void)},
	{"getInstance", "(Ljava/util/Collection;)Ljavax/net/ssl/X509TrustManager;", "(Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)Ljavax/net/ssl/X509TrustManager;", 0, $virtualMethod(TrustManagerFactoryImpl$SimpleFactory, getInstance, $X509TrustManager*, $Collection*)},
	{"getInstance", "(Ljavax/net/ssl/ManagerFactoryParameters;)Ljavax/net/ssl/X509TrustManager;", nullptr, 0, $virtualMethod(TrustManagerFactoryImpl$SimpleFactory, getInstance, $X509TrustManager*, $ManagerFactoryParameters*), "java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _TrustManagerFactoryImpl$SimpleFactory_InnerClassesInfo_[] = {
	{"sun.security.ssl.TrustManagerFactoryImpl$SimpleFactory", "sun.security.ssl.TrustManagerFactoryImpl", "SimpleFactory", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _TrustManagerFactoryImpl$SimpleFactory_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.TrustManagerFactoryImpl$SimpleFactory",
	"sun.security.ssl.TrustManagerFactoryImpl",
	nullptr,
	nullptr,
	_TrustManagerFactoryImpl$SimpleFactory_MethodInfo_,
	nullptr,
	nullptr,
	_TrustManagerFactoryImpl$SimpleFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.TrustManagerFactoryImpl"
};

$Object* allocate$TrustManagerFactoryImpl$SimpleFactory($Class* clazz) {
	return $of($alloc(TrustManagerFactoryImpl$SimpleFactory));
}

void TrustManagerFactoryImpl$SimpleFactory::init$() {
	$TrustManagerFactoryImpl::init$();
}

$X509TrustManager* TrustManagerFactoryImpl$SimpleFactory::getInstance($Collection* trustedCerts) {
	$init($Validator);
	return $new($X509TrustManagerImpl, $Validator::TYPE_SIMPLE, trustedCerts);
}

$X509TrustManager* TrustManagerFactoryImpl$SimpleFactory::getInstance($ManagerFactoryParameters* spec) {
	$throwNew($InvalidAlgorithmParameterException, "SunX509 TrustManagerFactory does not use ManagerFactoryParameters"_s);
	$shouldNotReachHere();
}

TrustManagerFactoryImpl$SimpleFactory::TrustManagerFactoryImpl$SimpleFactory() {
}

$Class* TrustManagerFactoryImpl$SimpleFactory::load$($String* name, bool initialize) {
	$loadClass(TrustManagerFactoryImpl$SimpleFactory, name, initialize, &_TrustManagerFactoryImpl$SimpleFactory_ClassInfo_, allocate$TrustManagerFactoryImpl$SimpleFactory);
	return class$;
}

$Class* TrustManagerFactoryImpl$SimpleFactory::class$ = nullptr;

		} // ssl
	} // security
} // sun