#include <com/sun/crypto/provider/DHKeyFactory.h>

#include <com/sun/crypto/provider/DHPrivateKey.h>
#include <com/sun/crypto/provider/DHPublicKey.h>
#include <java/math/BigInteger.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactorySpi.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <java/security/spec/X509EncodedKeySpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/interfaces/DHPrivateKey.h>
#include <javax/crypto/interfaces/DHPublicKey.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <javax/crypto/spec/DHPrivateKeySpec.h>
#include <javax/crypto/spec/DHPublicKeySpec.h>
#include <jcpp.h>

using $DHPrivateKey = ::com::sun::crypto::provider::DHPrivateKey;
using $DHPublicKey = ::com::sun::crypto::provider::DHPublicKey;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $KeyFactorySpi = ::java::security::KeyFactorySpi;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $X509EncodedKeySpec = ::java::security::spec::X509EncodedKeySpec;
using $Arrays = ::java::util::Arrays;
using $1DHPrivateKey = ::javax::crypto::interfaces::DHPrivateKey;
using $1DHPublicKey = ::javax::crypto::interfaces::DHPublicKey;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $DHPrivateKeySpec = ::javax::crypto::spec::DHPrivateKeySpec;
using $DHPublicKeySpec = ::javax::crypto::spec::DHPublicKeySpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$MethodInfo _DHKeyFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DHKeyFactory, init$, void)},
	{"engineGeneratePrivate", "(Ljava/security/spec/KeySpec;)Ljava/security/PrivateKey;", nullptr, $PROTECTED, $virtualMethod(DHKeyFactory, engineGeneratePrivate, $PrivateKey*, $KeySpec*), "java.security.spec.InvalidKeySpecException"},
	{"engineGeneratePublic", "(Ljava/security/spec/KeySpec;)Ljava/security/PublicKey;", nullptr, $PROTECTED, $virtualMethod(DHKeyFactory, engineGeneratePublic, $PublicKey*, $KeySpec*), "java.security.spec.InvalidKeySpecException"},
	{"engineGetKeySpec", "(Ljava/security/Key;Ljava/lang/Class;)Ljava/security/spec/KeySpec;", "<T::Ljava/security/spec/KeySpec;>(Ljava/security/Key;Ljava/lang/Class<TT;>;)TT;", $PROTECTED, $virtualMethod(DHKeyFactory, engineGetKeySpec, $KeySpec*, $Key*, $Class*), "java.security.spec.InvalidKeySpecException"},
	{"engineTranslateKey", "(Ljava/security/Key;)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(DHKeyFactory, engineTranslateKey, $Key*, $Key*), "java.security.InvalidKeyException"},
	{}
};

$ClassInfo _DHKeyFactory_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.DHKeyFactory",
	"java.security.KeyFactorySpi",
	nullptr,
	nullptr,
	_DHKeyFactory_MethodInfo_
};

$Object* allocate$DHKeyFactory($Class* clazz) {
	return $of($alloc(DHKeyFactory));
}

void DHKeyFactory::init$() {
	$KeyFactorySpi::init$();
}

$PublicKey* DHKeyFactory::engineGeneratePublic($KeySpec* keySpec) {
	$useLocalCurrentObjectStackCache();
	try {
		if ($instanceOf($DHPublicKeySpec, keySpec)) {
			$var($DHPublicKeySpec, dhPubKeySpec, $cast($DHPublicKeySpec, keySpec));
			$var($BigInteger, var$0, $nc(dhPubKeySpec)->getY());
			$var($BigInteger, var$1, dhPubKeySpec->getP());
			return $new($DHPublicKey, var$0, var$1, $(dhPubKeySpec->getG()));
		} else if ($instanceOf($X509EncodedKeySpec, keySpec)) {
			return $new($DHPublicKey, $($nc(($cast($X509EncodedKeySpec, keySpec)))->getEncoded()));
		} else {
			$throwNew($InvalidKeySpecException, "Inappropriate key specification"_s);
		}
	} catch ($InvalidKeyException& e) {
		$throwNew($InvalidKeySpecException, "Inappropriate key specification"_s, e);
	}
	$shouldNotReachHere();
}

$PrivateKey* DHKeyFactory::engineGeneratePrivate($KeySpec* keySpec) {
	$useLocalCurrentObjectStackCache();
	try {
		if ($instanceOf($DHPrivateKeySpec, keySpec)) {
			$var($DHPrivateKeySpec, dhPrivKeySpec, $cast($DHPrivateKeySpec, keySpec));
			$var($BigInteger, var$0, $nc(dhPrivKeySpec)->getX());
			$var($BigInteger, var$1, dhPrivKeySpec->getP());
			return $new($DHPrivateKey, var$0, var$1, $(dhPrivKeySpec->getG()));
		} else if ($instanceOf($PKCS8EncodedKeySpec, keySpec)) {
			$var($bytes, encoded, $nc(($cast($PKCS8EncodedKeySpec, keySpec)))->getEncoded());
			{
				$var($Throwable, var$2, nullptr);
				$var($PrivateKey, var$4, nullptr);
				bool return$3 = false;
				try {
					$assign(var$4, $new($DHPrivateKey, encoded));
					return$3 = true;
					goto $finally;
				} catch ($Throwable& var$5) {
					$assign(var$2, var$5);
				} $finally: {
					$Arrays::fill(encoded, (int8_t)0);
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
				if (return$3) {
					return var$4;
				}
			}
		} else {
			$throwNew($InvalidKeySpecException, "Inappropriate key specification"_s);
		}
	} catch ($InvalidKeyException& e) {
		$throwNew($InvalidKeySpecException, "Inappropriate key specification"_s, e);
	}
	$shouldNotReachHere();
}

$KeySpec* DHKeyFactory::engineGetKeySpec($Key* key, $Class* keySpec) {
	$useLocalCurrentObjectStackCache();
	$var($DHParameterSpec, params, nullptr);
	if ($instanceOf($1DHPublicKey, key)) {
		$load($DHPublicKeySpec);
		if ($nc(keySpec)->isAssignableFrom($DHPublicKeySpec::class$)) {
			$var($1DHPublicKey, dhPubKey, $cast($1DHPublicKey, key));
			$assign(params, $nc(dhPubKey)->getParams());
			$var($BigInteger, var$0, dhPubKey->getY());
			$var($BigInteger, var$1, $nc(params)->getP());
			return $cast($KeySpec, keySpec->cast($$new($DHPublicKeySpec, var$0, var$1, $(params->getG()))));
		} else {
			$load($X509EncodedKeySpec);
			if (keySpec->isAssignableFrom($X509EncodedKeySpec::class$)) {
				return $cast($KeySpec, keySpec->cast($$new($X509EncodedKeySpec, $($nc(key)->getEncoded()))));
			} else {
				$throwNew($InvalidKeySpecException, "Inappropriate key specification"_s);
			}
		}
	} else if ($instanceOf($1DHPrivateKey, key)) {
		$load($DHPrivateKeySpec);
		if ($nc(keySpec)->isAssignableFrom($DHPrivateKeySpec::class$)) {
			$var($1DHPrivateKey, dhPrivKey, $cast($1DHPrivateKey, key));
			$assign(params, $nc(dhPrivKey)->getParams());
			$var($BigInteger, var$2, dhPrivKey->getX());
			$var($BigInteger, var$3, $nc(params)->getP());
			return $cast($KeySpec, keySpec->cast($$new($DHPrivateKeySpec, var$2, var$3, $(params->getG()))));
		} else {
			$load($PKCS8EncodedKeySpec);
			if (keySpec->isAssignableFrom($PKCS8EncodedKeySpec::class$)) {
				$var($bytes, encoded, $nc(key)->getEncoded());
				{
					$var($Throwable, var$4, nullptr);
					$var($KeySpec, var$6, nullptr);
					bool return$5 = false;
					try {
						$assign(var$6, $cast($KeySpec, keySpec->cast($$new($PKCS8EncodedKeySpec, encoded))));
						return$5 = true;
						goto $finally;
					} catch ($Throwable& var$7) {
						$assign(var$4, var$7);
					} $finally: {
						$Arrays::fill(encoded, (int8_t)0);
					}
					if (var$4 != nullptr) {
						$throw(var$4);
					}
					if (return$5) {
						return var$6;
					}
				}
			} else {
				$throwNew($InvalidKeySpecException, "Inappropriate key specification"_s);
			}
		}
	} else {
		$throwNew($InvalidKeySpecException, "Inappropriate key type"_s);
	}
	$shouldNotReachHere();
}

$Key* DHKeyFactory::engineTranslateKey($Key* key) {
	$useLocalCurrentObjectStackCache();
	try {
		if ($instanceOf($1DHPublicKey, key)) {
			if ($instanceOf($DHPublicKey, key)) {
				return key;
			}
			$load($DHPublicKeySpec);
			$var($DHPublicKeySpec, dhPubKeySpec, $cast($DHPublicKeySpec, engineGetKeySpec(key, $DHPublicKeySpec::class$)));
			return engineGeneratePublic(dhPubKeySpec);
		} else if ($instanceOf($1DHPrivateKey, key)) {
			if ($instanceOf($DHPrivateKey, key)) {
				return key;
			}
			$load($DHPrivateKeySpec);
			$var($DHPrivateKeySpec, dhPrivKeySpec, $cast($DHPrivateKeySpec, engineGetKeySpec(key, $DHPrivateKeySpec::class$)));
			return engineGeneratePrivate(dhPrivKeySpec);
		} else {
			$throwNew($InvalidKeyException, "Wrong algorithm type"_s);
		}
	} catch ($InvalidKeySpecException& e) {
		$throwNew($InvalidKeyException, "Cannot translate key"_s, e);
	}
	$shouldNotReachHere();
}

DHKeyFactory::DHKeyFactory() {
}

$Class* DHKeyFactory::load$($String* name, bool initialize) {
	$loadClass(DHKeyFactory, name, initialize, &_DHKeyFactory_ClassInfo_, allocate$DHKeyFactory);
	return class$;
}

$Class* DHKeyFactory::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com