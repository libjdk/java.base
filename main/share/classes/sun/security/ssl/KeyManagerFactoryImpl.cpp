#include <sun/security/ssl/KeyManagerFactoryImpl.h>

#include <java/lang/IllegalStateException.h>
#include <javax/net/ssl/KeyManager.h>
#include <javax/net/ssl/KeyManagerFactorySpi.h>
#include <javax/net/ssl/X509ExtendedKeyManager.h>
#include <jcpp.h>

using $KeyManagerArray = $Array<::javax::net::ssl::KeyManager>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KeyManager = ::javax::net::ssl::KeyManager;
using $KeyManagerFactorySpi = ::javax::net::ssl::KeyManagerFactorySpi;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _KeyManagerFactoryImpl_FieldInfo_[] = {
	{"keyManager", "Ljavax/net/ssl/X509ExtendedKeyManager;", nullptr, 0, $field(KeyManagerFactoryImpl, keyManager)},
	{"isInitialized", "Z", nullptr, 0, $field(KeyManagerFactoryImpl, isInitialized)},
	{}
};

$MethodInfo _KeyManagerFactoryImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(KeyManagerFactoryImpl, init$, void)},
	{"engineGetKeyManagers", "()[Ljavax/net/ssl/KeyManager;", nullptr, $PROTECTED, $virtualMethod(KeyManagerFactoryImpl, engineGetKeyManagers, $KeyManagerArray*)},
	{}
};

$InnerClassInfo _KeyManagerFactoryImpl_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyManagerFactoryImpl$X509", "sun.security.ssl.KeyManagerFactoryImpl", "X509", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.ssl.KeyManagerFactoryImpl$SunX509", "sun.security.ssl.KeyManagerFactoryImpl", "SunX509", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _KeyManagerFactoryImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.ssl.KeyManagerFactoryImpl",
	"javax.net.ssl.KeyManagerFactorySpi",
	nullptr,
	_KeyManagerFactoryImpl_FieldInfo_,
	_KeyManagerFactoryImpl_MethodInfo_,
	nullptr,
	nullptr,
	_KeyManagerFactoryImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyManagerFactoryImpl$X509,sun.security.ssl.KeyManagerFactoryImpl$SunX509"
};

$Object* allocate$KeyManagerFactoryImpl($Class* clazz) {
	return $of($alloc(KeyManagerFactoryImpl));
}

void KeyManagerFactoryImpl::init$() {
	$KeyManagerFactorySpi::init$();
}

$KeyManagerArray* KeyManagerFactoryImpl::engineGetKeyManagers() {
	if (!this->isInitialized) {
		$throwNew($IllegalStateException, "KeyManagerFactoryImpl is not initialized"_s);
	}
	return $new($KeyManagerArray, {static_cast<$KeyManager*>(this->keyManager)});
}

KeyManagerFactoryImpl::KeyManagerFactoryImpl() {
}

$Class* KeyManagerFactoryImpl::load$($String* name, bool initialize) {
	$loadClass(KeyManagerFactoryImpl, name, initialize, &_KeyManagerFactoryImpl_ClassInfo_, allocate$KeyManagerFactoryImpl);
	return class$;
}

$Class* KeyManagerFactoryImpl::class$ = nullptr;

		} // ssl
	} // security
} // sun