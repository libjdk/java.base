#include <sun/security/ssl/TrustManagerFactoryImpl$PKIXFactory.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/cert/CertPathParameters.h>
#include <java/security/cert/PKIXBuilderParameters.h>
#include <java/util/Collection.h>
#include <javax/net/ssl/CertPathTrustManagerParameters.h>
#include <javax/net/ssl/ManagerFactoryParameters.h>
#include <javax/net/ssl/X509TrustManager.h>
#include <sun/security/ssl/TrustManagerFactoryImpl.h>
#include <sun/security/ssl/X509TrustManagerImpl.h>
#include <sun/security/validator/Validator.h>
#include <jcpp.h>

#undef TYPE_PKIX

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $CertPathParameters = ::java::security::cert::CertPathParameters;
using $PKIXBuilderParameters = ::java::security::cert::PKIXBuilderParameters;
using $Collection = ::java::util::Collection;
using $CertPathTrustManagerParameters = ::javax::net::ssl::CertPathTrustManagerParameters;
using $ManagerFactoryParameters = ::javax::net::ssl::ManagerFactoryParameters;
using $X509TrustManager = ::javax::net::ssl::X509TrustManager;
using $TrustManagerFactoryImpl = ::sun::security::ssl::TrustManagerFactoryImpl;
using $X509TrustManagerImpl = ::sun::security::ssl::X509TrustManagerImpl;
using $Validator = ::sun::security::validator::Validator;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _TrustManagerFactoryImpl$PKIXFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TrustManagerFactoryImpl$PKIXFactory, init$, void)},
	{"getInstance", "(Ljava/util/Collection;)Ljavax/net/ssl/X509TrustManager;", "(Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)Ljavax/net/ssl/X509TrustManager;", 0, $virtualMethod(TrustManagerFactoryImpl$PKIXFactory, getInstance, $X509TrustManager*, $Collection*)},
	{"getInstance", "(Ljavax/net/ssl/ManagerFactoryParameters;)Ljavax/net/ssl/X509TrustManager;", nullptr, 0, $virtualMethod(TrustManagerFactoryImpl$PKIXFactory, getInstance, $X509TrustManager*, $ManagerFactoryParameters*), "java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _TrustManagerFactoryImpl$PKIXFactory_InnerClassesInfo_[] = {
	{"sun.security.ssl.TrustManagerFactoryImpl$PKIXFactory", "sun.security.ssl.TrustManagerFactoryImpl", "PKIXFactory", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _TrustManagerFactoryImpl$PKIXFactory_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.TrustManagerFactoryImpl$PKIXFactory",
	"sun.security.ssl.TrustManagerFactoryImpl",
	nullptr,
	nullptr,
	_TrustManagerFactoryImpl$PKIXFactory_MethodInfo_,
	nullptr,
	nullptr,
	_TrustManagerFactoryImpl$PKIXFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.TrustManagerFactoryImpl"
};

$Object* allocate$TrustManagerFactoryImpl$PKIXFactory($Class* clazz) {
	return $of($alloc(TrustManagerFactoryImpl$PKIXFactory));
}

void TrustManagerFactoryImpl$PKIXFactory::init$() {
	$TrustManagerFactoryImpl::init$();
}

$X509TrustManager* TrustManagerFactoryImpl$PKIXFactory::getInstance($Collection* trustedCerts) {
	$init($Validator);
	return $new($X509TrustManagerImpl, $Validator::TYPE_PKIX, trustedCerts);
}

$X509TrustManager* TrustManagerFactoryImpl$PKIXFactory::getInstance($ManagerFactoryParameters* spec) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($CertPathTrustManagerParameters, spec))) {
		$throwNew($InvalidAlgorithmParameterException, "Parameters must be CertPathTrustManagerParameters"_s);
	}
	$var($CertPathParameters, params, $nc(($cast($CertPathTrustManagerParameters, spec)))->getParameters());
	if (!($instanceOf($PKIXBuilderParameters, params))) {
		$throwNew($InvalidAlgorithmParameterException, "Encapsulated parameters must be PKIXBuilderParameters"_s);
	}
	$var($PKIXBuilderParameters, pkixParams, $cast($PKIXBuilderParameters, params));
	$init($Validator);
	return $new($X509TrustManagerImpl, $Validator::TYPE_PKIX, pkixParams);
}

TrustManagerFactoryImpl$PKIXFactory::TrustManagerFactoryImpl$PKIXFactory() {
}

$Class* TrustManagerFactoryImpl$PKIXFactory::load$($String* name, bool initialize) {
	$loadClass(TrustManagerFactoryImpl$PKIXFactory, name, initialize, &_TrustManagerFactoryImpl$PKIXFactory_ClassInfo_, allocate$TrustManagerFactoryImpl$PKIXFactory);
	return class$;
}

$Class* TrustManagerFactoryImpl$PKIXFactory::class$ = nullptr;

		} // ssl
	} // security
} // sun