#include <sun/security/ssl/KeyManagerFactoryImpl$X509.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/KeyStore$Builder.h>
#include <java/security/KeyStore$PasswordProtection.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <javax/net/ssl/KeyStoreBuilderParameters.h>
#include <javax/net/ssl/ManagerFactoryParameters.h>
#include <javax/net/ssl/X509ExtendedKeyManager.h>
#include <sun/security/ssl/KeyManagerFactoryImpl.h>
#include <sun/security/ssl/X509KeyManagerImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $KeyStore = ::java::security::KeyStore;
using $KeyStore$Builder = ::java::security::KeyStore$Builder;
using $KeyStore$PasswordProtection = ::java::security::KeyStore$PasswordProtection;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStoreException = ::java::security::KeyStoreException;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $KeyStoreBuilderParameters = ::javax::net::ssl::KeyStoreBuilderParameters;
using $ManagerFactoryParameters = ::javax::net::ssl::ManagerFactoryParameters;
using $X509ExtendedKeyManager = ::javax::net::ssl::X509ExtendedKeyManager;
using $KeyManagerFactoryImpl = ::sun::security::ssl::KeyManagerFactoryImpl;
using $X509KeyManagerImpl = ::sun::security::ssl::X509KeyManagerImpl;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _KeyManagerFactoryImpl$X509_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(KeyManagerFactoryImpl$X509, init$, void)},
	{"engineInit", "(Ljava/security/KeyStore;[C)V", nullptr, $PROTECTED, $virtualMethod(KeyManagerFactoryImpl$X509, engineInit, void, $KeyStore*, $chars*), "java.security.KeyStoreException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineInit", "(Ljavax/net/ssl/ManagerFactoryParameters;)V", nullptr, $PROTECTED, $virtualMethod(KeyManagerFactoryImpl$X509, engineInit, void, $ManagerFactoryParameters*), "java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _KeyManagerFactoryImpl$X509_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyManagerFactoryImpl$X509", "sun.security.ssl.KeyManagerFactoryImpl", "X509", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _KeyManagerFactoryImpl$X509_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.KeyManagerFactoryImpl$X509",
	"sun.security.ssl.KeyManagerFactoryImpl",
	nullptr,
	nullptr,
	_KeyManagerFactoryImpl$X509_MethodInfo_,
	nullptr,
	nullptr,
	_KeyManagerFactoryImpl$X509_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyManagerFactoryImpl"
};

$Object* allocate$KeyManagerFactoryImpl$X509($Class* clazz) {
	return $of($alloc(KeyManagerFactoryImpl$X509));
}

void KeyManagerFactoryImpl$X509::init$() {
	$KeyManagerFactoryImpl::init$();
}

void KeyManagerFactoryImpl$X509::engineInit($KeyStore* ks, $chars* password) {
	$useLocalCurrentObjectStackCache();
	if (ks == nullptr) {
		$set(this, keyManager, $new($X509KeyManagerImpl, $($Collections::emptyList())));
	} else {
		try {
			$var($KeyStore$Builder, builder, $KeyStore$Builder::newInstance(ks, static_cast<$KeyStore$ProtectionParameter*>($$new($KeyStore$PasswordProtection, password))));
			$set(this, keyManager, $new($X509KeyManagerImpl, builder));
		} catch ($RuntimeException& e) {
			$throwNew($KeyStoreException, "initialization failed"_s, e);
		}
	}
	this->isInitialized = true;
}

void KeyManagerFactoryImpl$X509::engineInit($ManagerFactoryParameters* params) {
	if (!($instanceOf($KeyStoreBuilderParameters, params))) {
		$throwNew($InvalidAlgorithmParameterException, "Parameters must be instance of KeyStoreBuilderParameters"_s);
	}
	$var($List, builders, $nc(($cast($KeyStoreBuilderParameters, params)))->getParameters());
	$set(this, keyManager, $new($X509KeyManagerImpl, builders));
	this->isInitialized = true;
}

KeyManagerFactoryImpl$X509::KeyManagerFactoryImpl$X509() {
}

$Class* KeyManagerFactoryImpl$X509::load$($String* name, bool initialize) {
	$loadClass(KeyManagerFactoryImpl$X509, name, initialize, &_KeyManagerFactoryImpl$X509_ClassInfo_, allocate$KeyManagerFactoryImpl$X509);
	return class$;
}

$Class* KeyManagerFactoryImpl$X509::class$ = nullptr;

		} // ssl
	} // security
} // sun