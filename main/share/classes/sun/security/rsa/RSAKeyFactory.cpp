#include <sun/security/rsa/RSAKeyFactory.h>

#include <java/lang/Math.h>
#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactorySpi.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/interfaces/RSAKey.h>
#include <java/security/interfaces/RSAPrivateCrtKey.h>
#include <java/security/interfaces/RSAPrivateKey.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <java/security/spec/RSAPrivateCrtKeySpec.h>
#include <java/security/spec/RSAPrivateKeySpec.h>
#include <java/security/spec/RSAPublicKeySpec.h>
#include <java/security/spec/X509EncodedKeySpec.h>
#include <java/util/Arrays.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/pkcs/PKCS8Key.h>
#include <sun/security/rsa/RSAPrivateCrtKeyImpl.h>
#include <sun/security/rsa/RSAPrivateKeyImpl.h>
#include <sun/security/rsa/RSAPublicKeyImpl.h>
#include <sun/security/rsa/RSAUtil$KeyType.h>
#include <sun/security/x509/X509Key.h>
#include <jcpp.h>

#undef MAX_MODLEN
#undef MAX_MODLEN_RESTRICT_EXP
#undef MAX_RESTRICTED_EXPLEN
#undef MAX_VALUE
#undef MIN_MODLEN
#undef PKCS8_KEYSPEC_CLS
#undef RSA
#undef RSA_PRIVCRT_KEYSPEC_CLS
#undef RSA_PRIV_KEYSPEC_CLS
#undef RSA_PUB_KEYSPEC_CLS
#undef X509_KEYSPEC_CLS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $KeyFactorySpi = ::java::security::KeyFactorySpi;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $RSAKey = ::java::security::interfaces::RSAKey;
using $RSAPrivateCrtKey = ::java::security::interfaces::RSAPrivateCrtKey;
using $RSAPrivateKey = ::java::security::interfaces::RSAPrivateKey;
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $RSAPrivateCrtKeySpec = ::java::security::spec::RSAPrivateCrtKeySpec;
using $RSAPrivateKeySpec = ::java::security::spec::RSAPrivateKeySpec;
using $RSAPublicKeySpec = ::java::security::spec::RSAPublicKeySpec;
using $X509EncodedKeySpec = ::java::security::spec::X509EncodedKeySpec;
using $Arrays = ::java::util::Arrays;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $PKCS8Key = ::sun::security::pkcs::PKCS8Key;
using $RSAPrivateCrtKeyImpl = ::sun::security::rsa::RSAPrivateCrtKeyImpl;
using $RSAPrivateKeyImpl = ::sun::security::rsa::RSAPrivateKeyImpl;
using $RSAPublicKeyImpl = ::sun::security::rsa::RSAPublicKeyImpl;
using $RSAUtil$KeyType = ::sun::security::rsa::RSAUtil$KeyType;
using $X509Key = ::sun::security::x509::X509Key;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _RSAKeyFactory_FieldInfo_[] = {
	{"RSA_PUB_KEYSPEC_CLS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyFactory, RSA_PUB_KEYSPEC_CLS)},
	{"RSA_PRIV_KEYSPEC_CLS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyFactory, RSA_PRIV_KEYSPEC_CLS)},
	{"RSA_PRIVCRT_KEYSPEC_CLS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyFactory, RSA_PRIVCRT_KEYSPEC_CLS)},
	{"X509_KEYSPEC_CLS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyFactory, X509_KEYSPEC_CLS)},
	{"PKCS8_KEYSPEC_CLS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyFactory, PKCS8_KEYSPEC_CLS)},
	{"MIN_MODLEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAKeyFactory, MIN_MODLEN)},
	{"MAX_MODLEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAKeyFactory, MAX_MODLEN)},
	{"type", "Lsun/security/rsa/RSAUtil$KeyType;", nullptr, $PRIVATE | $FINAL, $field(RSAKeyFactory, type)},
	{"MAX_MODLEN_RESTRICT_EXP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAKeyFactory, MAX_MODLEN_RESTRICT_EXP)},
	{"MAX_RESTRICTED_EXPLEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAKeyFactory, MAX_RESTRICTED_EXPLEN)},
	{"restrictExpLen", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyFactory, restrictExpLen)},
	{}
};

$MethodInfo _RSAKeyFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(RSAKeyFactory, init$, void)},
	{"<init>", "(Lsun/security/rsa/RSAUtil$KeyType;)V", nullptr, $PUBLIC, $method(RSAKeyFactory, init$, void, $RSAUtil$KeyType*)},
	{"checkKeyAlgo", "(Ljava/security/Key;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(RSAKeyFactory, checkKeyAlgo, void, $Key*, $String*), "java.security.InvalidKeyException"},
	{"checkKeyLengths", "(ILjava/math/BigInteger;II)V", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAKeyFactory, checkKeyLengths, void, int32_t, $BigInteger*, int32_t, int32_t), "java.security.InvalidKeyException"},
	{"checkRSAProviderKeyLengths", "(ILjava/math/BigInteger;)V", nullptr, $STATIC, $staticMethod(RSAKeyFactory, checkRSAProviderKeyLengths, void, int32_t, $BigInteger*), "java.security.InvalidKeyException"},
	{"engineGeneratePrivate", "(Ljava/security/spec/KeySpec;)Ljava/security/PrivateKey;", nullptr, $PROTECTED, $virtualMethod(RSAKeyFactory, engineGeneratePrivate, $PrivateKey*, $KeySpec*), "java.security.spec.InvalidKeySpecException"},
	{"engineGeneratePublic", "(Ljava/security/spec/KeySpec;)Ljava/security/PublicKey;", nullptr, $PROTECTED, $virtualMethod(RSAKeyFactory, engineGeneratePublic, $PublicKey*, $KeySpec*), "java.security.spec.InvalidKeySpecException"},
	{"engineGetKeySpec", "(Ljava/security/Key;Ljava/lang/Class;)Ljava/security/spec/KeySpec;", "<T::Ljava/security/spec/KeySpec;>(Ljava/security/Key;Ljava/lang/Class<TT;>;)TT;", $PROTECTED, $virtualMethod(RSAKeyFactory, engineGetKeySpec, $KeySpec*, $Key*, $Class*), "java.security.spec.InvalidKeySpecException"},
	{"engineTranslateKey", "(Ljava/security/Key;)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(RSAKeyFactory, engineTranslateKey, $Key*, $Key*), "java.security.InvalidKeyException"},
	{"generatePrivate", "(Ljava/security/spec/KeySpec;)Ljava/security/PrivateKey;", nullptr, $PRIVATE, $method(RSAKeyFactory, generatePrivate, $PrivateKey*, $KeySpec*), "java.security.GeneralSecurityException"},
	{"generatePublic", "(Ljava/security/spec/KeySpec;)Ljava/security/PublicKey;", nullptr, $PRIVATE, $method(RSAKeyFactory, generatePublic, $PublicKey*, $KeySpec*), "java.security.GeneralSecurityException"},
	{"getInstance", "(Lsun/security/rsa/RSAUtil$KeyType;)Lsun/security/rsa/RSAKeyFactory;", nullptr, $STATIC, $staticMethod(RSAKeyFactory, getInstance, RSAKeyFactory*, $RSAUtil$KeyType*)},
	{"toRSAKey", "(Ljava/security/Key;)Ljava/security/interfaces/RSAKey;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAKeyFactory, toRSAKey, $RSAKey*, $Key*), "java.security.InvalidKeyException"},
	{"translatePrivateKey", "(Ljava/security/PrivateKey;)Ljava/security/PrivateKey;", nullptr, $PRIVATE, $method(RSAKeyFactory, translatePrivateKey, $PrivateKey*, $PrivateKey*), "java.security.InvalidKeyException"},
	{"translatePublicKey", "(Ljava/security/PublicKey;)Ljava/security/PublicKey;", nullptr, $PRIVATE, $method(RSAKeyFactory, translatePublicKey, $PublicKey*, $PublicKey*), "java.security.InvalidKeyException"},
	{}
};

$InnerClassInfo _RSAKeyFactory_InnerClassesInfo_[] = {
	{"sun.security.rsa.RSAKeyFactory$PSS", "sun.security.rsa.RSAKeyFactory", "PSS", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSAKeyFactory$Legacy", "sun.security.rsa.RSAKeyFactory", "Legacy", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSAKeyFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.rsa.RSAKeyFactory",
	"java.security.KeyFactorySpi",
	nullptr,
	_RSAKeyFactory_FieldInfo_,
	_RSAKeyFactory_MethodInfo_,
	nullptr,
	nullptr,
	_RSAKeyFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.rsa.RSAKeyFactory$PSS,sun.security.rsa.RSAKeyFactory$Legacy"
};

$Object* allocate$RSAKeyFactory($Class* clazz) {
	return $of($alloc(RSAKeyFactory));
}

$Class* RSAKeyFactory::RSA_PUB_KEYSPEC_CLS = nullptr;
$Class* RSAKeyFactory::RSA_PRIV_KEYSPEC_CLS = nullptr;
$Class* RSAKeyFactory::RSA_PRIVCRT_KEYSPEC_CLS = nullptr;
$Class* RSAKeyFactory::X509_KEYSPEC_CLS = nullptr;
$Class* RSAKeyFactory::PKCS8_KEYSPEC_CLS = nullptr;
bool RSAKeyFactory::restrictExpLen = false;

RSAKeyFactory* RSAKeyFactory::getInstance($RSAUtil$KeyType* type) {
	$init(RSAKeyFactory);
	return $new(RSAKeyFactory, type);
}

void RSAKeyFactory::checkKeyAlgo($Key* key, $String* expectedAlg) {
	$init(RSAKeyFactory);
	$useLocalCurrentObjectStackCache();
	$var($String, keyAlg, $nc(key)->getAlgorithm());
	if (keyAlg == nullptr || !($nc(keyAlg)->equalsIgnoreCase(expectedAlg))) {
		$throwNew($InvalidKeyException, $$str({"Expected a "_s, expectedAlg, " key, but got "_s, keyAlg}));
	}
}

$RSAKey* RSAKeyFactory::toRSAKey($Key* key) {
	$init(RSAKeyFactory);
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($InvalidKeyException, "Key must not be null"_s);
	}
	if (($instanceOf($RSAPrivateKeyImpl, key)) || ($instanceOf($RSAPrivateCrtKeyImpl, key)) || ($instanceOf($RSAPublicKeyImpl, key))) {
		return $cast($RSAKey, key);
	} else {
		try {
			$RSAUtil$KeyType* type = $RSAUtil$KeyType::lookup($($nc(key)->getAlgorithm()));
			$var(RSAKeyFactory, kf, RSAKeyFactory::getInstance(type));
			return $cast($RSAKey, $nc(kf)->engineTranslateKey(key));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
		}
	}
	$shouldNotReachHere();
}

void RSAKeyFactory::checkRSAProviderKeyLengths(int32_t modulusLen, $BigInteger* exponent) {
	$init(RSAKeyFactory);
	checkKeyLengths(((int32_t)((modulusLen + 7) & (uint32_t)~7)), exponent, RSAKeyFactory::MIN_MODLEN, $Integer::MAX_VALUE);
}

void RSAKeyFactory::checkKeyLengths(int32_t modulusLen, $BigInteger* exponent, int32_t minModulusLen, int32_t maxModulusLen) {
	$init(RSAKeyFactory);
	$useLocalCurrentObjectStackCache();
	if ((minModulusLen > 0) && (modulusLen < (minModulusLen))) {
		$throwNew($InvalidKeyException, $$str({"RSA keys must be at least "_s, $$str(minModulusLen), " bits long"_s}));
	}
	int32_t maxLen = $Math::min(maxModulusLen, RSAKeyFactory::MAX_MODLEN);
	if (modulusLen > maxLen) {
		$throwNew($InvalidKeyException, $$str({"RSA keys must be no longer than "_s, $$str(maxLen), " bits"_s}));
	}
	if (RSAKeyFactory::restrictExpLen && (exponent != nullptr) && (modulusLen > RSAKeyFactory::MAX_MODLEN_RESTRICT_EXP) && (exponent->bitLength() > RSAKeyFactory::MAX_RESTRICTED_EXPLEN)) {
		$throwNew($InvalidKeyException, $$str({"RSA exponents can be no longer than "_s, $$str(RSAKeyFactory::MAX_RESTRICTED_EXPLEN), " bits  if modulus is greater than "_s, $$str(RSAKeyFactory::MAX_MODLEN_RESTRICT_EXP), " bits"_s}));
	}
}

void RSAKeyFactory::init$() {
	$KeyFactorySpi::init$();
	$init($RSAUtil$KeyType);
	$set(this, type, $RSAUtil$KeyType::RSA);
}

void RSAKeyFactory::init$($RSAUtil$KeyType* type) {
	$KeyFactorySpi::init$();
	$set(this, type, type);
}

$Key* RSAKeyFactory::engineTranslateKey($Key* key) {
	if (key == nullptr) {
		$throwNew($InvalidKeyException, "Key must not be null"_s);
	}
	checkKeyAlgo(key, this->type->keyAlgo);
	if (($instanceOf($RSAPrivateKeyImpl, key)) || ($instanceOf($RSAPrivateCrtKeyImpl, key)) || ($instanceOf($RSAPublicKeyImpl, key))) {
		return key;
	}
	if ($instanceOf($PublicKey, key)) {
		return translatePublicKey($cast($PublicKey, key));
	} else if ($instanceOf($PrivateKey, key)) {
		return translatePrivateKey($cast($PrivateKey, key));
	} else {
		$throwNew($InvalidKeyException, "Neither a public nor a private key"_s);
	}
}

$PublicKey* RSAKeyFactory::engineGeneratePublic($KeySpec* keySpec) {
	try {
		return generatePublic(keySpec);
	} catch ($InvalidKeySpecException& e) {
		$throw(e);
	} catch ($GeneralSecurityException& e) {
		$throwNew($InvalidKeySpecException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$PrivateKey* RSAKeyFactory::engineGeneratePrivate($KeySpec* keySpec) {
	try {
		return generatePrivate(keySpec);
	} catch ($InvalidKeySpecException& e) {
		$throw(e);
	} catch ($GeneralSecurityException& e) {
		$throwNew($InvalidKeySpecException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$PublicKey* RSAKeyFactory::translatePublicKey($PublicKey* key) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($RSAPublicKey, key)) {
		$var($RSAPublicKey, rsaKey, $cast($RSAPublicKey, key));
		try {
			$var($RSAUtil$KeyType, var$0, this->type);
			$var($AlgorithmParameterSpec, var$1, $nc(rsaKey)->getParams());
			$var($BigInteger, var$2, rsaKey->getModulus());
			return static_cast<$PublicKey*>(static_cast<$X509Key*>($new($RSAPublicKeyImpl, var$0, var$1, var$2, $(rsaKey->getPublicExponent()))));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeyException, "Invalid key"_s, e);
		}
	} else {
		$var($RSAUtil$KeyType, var$3, this->type);
		$var($String, var$4, $nc(key)->getFormat());
		return $RSAPublicKeyImpl::newKey(var$3, var$4, $(key->getEncoded()));
	}
}

$PrivateKey* RSAKeyFactory::translatePrivateKey($PrivateKey* key) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($RSAPrivateCrtKey, key)) {
		$var($RSAPrivateCrtKey, rsaKey, $cast($RSAPrivateCrtKey, key));
		try {
			$var($RSAUtil$KeyType, var$0, this->type);
			$var($AlgorithmParameterSpec, var$1, $nc(rsaKey)->getParams());
			$var($BigInteger, var$2, rsaKey->getModulus());
			$var($BigInteger, var$3, rsaKey->getPublicExponent());
			$var($BigInteger, var$4, rsaKey->getPrivateExponent());
			$var($BigInteger, var$5, rsaKey->getPrimeP());
			$var($BigInteger, var$6, rsaKey->getPrimeQ());
			$var($BigInteger, var$7, rsaKey->getPrimeExponentP());
			$var($BigInteger, var$8, rsaKey->getPrimeExponentQ());
			return static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>($new($RSAPrivateCrtKeyImpl, var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, $(rsaKey->getCrtCoefficient()))));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeyException, "Invalid key"_s, e);
		}
	} else if ($instanceOf($RSAPrivateKey, key)) {
		$var($RSAPrivateKey, rsaKey, $cast($RSAPrivateKey, key));
		try {
			$var($RSAUtil$KeyType, var$9, this->type);
			$var($AlgorithmParameterSpec, var$10, $nc(rsaKey)->getParams());
			$var($BigInteger, var$11, rsaKey->getModulus());
			return static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>($new($RSAPrivateKeyImpl, var$9, var$10, var$11, $(rsaKey->getPrivateExponent()))));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeyException, "Invalid key"_s, e);
		}
	} else {
		$var($bytes, encoded, $nc(key)->getEncoded());
		{
			$var($Throwable, var$12, nullptr);
			$var($PrivateKey, var$14, nullptr);
			bool return$13 = false;
			try {
				$assign(var$14, $RSAPrivateCrtKeyImpl::newKey(this->type, $(key->getFormat()), encoded));
				return$13 = true;
				goto $finally;
			} catch ($Throwable& var$15) {
				$assign(var$12, var$15);
			} $finally: {
				if (encoded != nullptr) {
					$Arrays::fill(encoded, (int8_t)0);
				}
			}
			if (var$12 != nullptr) {
				$throw(var$12);
			}
			if (return$13) {
				return var$14;
			}
		}
	}
	$shouldNotReachHere();
}

$PublicKey* RSAKeyFactory::generatePublic($KeySpec* keySpec) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($X509EncodedKeySpec, keySpec)) {
		return $RSAPublicKeyImpl::newKey(this->type, "X.509"_s, $($nc(($cast($X509EncodedKeySpec, keySpec)))->getEncoded()));
	} else if ($instanceOf($RSAPublicKeySpec, keySpec)) {
		$var($RSAPublicKeySpec, rsaSpec, $cast($RSAPublicKeySpec, keySpec));
		try {
			$var($RSAUtil$KeyType, var$0, this->type);
			$var($AlgorithmParameterSpec, var$1, $nc(rsaSpec)->getParams());
			$var($BigInteger, var$2, rsaSpec->getModulus());
			return static_cast<$PublicKey*>(static_cast<$X509Key*>($new($RSAPublicKeyImpl, var$0, var$1, var$2, $(rsaSpec->getPublicExponent()))));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeySpecException, static_cast<$Throwable*>(e));
		}
	} else {
		$throwNew($InvalidKeySpecException, "Only RSAPublicKeySpec and X509EncodedKeySpec supported for RSA public keys"_s);
	}
	$shouldNotReachHere();
}

$PrivateKey* RSAKeyFactory::generatePrivate($KeySpec* keySpec) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($PKCS8EncodedKeySpec, keySpec)) {
		$var($bytes, encoded, $nc(($cast($PKCS8EncodedKeySpec, keySpec)))->getEncoded());
		{
			$var($Throwable, var$0, nullptr);
			$var($PrivateKey, var$2, nullptr);
			bool return$1 = false;
			try {
				$assign(var$2, $RSAPrivateCrtKeyImpl::newKey(this->type, "PKCS#8"_s, encoded));
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$Arrays::fill(encoded, (int8_t)0);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} else if ($instanceOf($RSAPrivateCrtKeySpec, keySpec)) {
		$var($RSAPrivateCrtKeySpec, rsaSpec, $cast($RSAPrivateCrtKeySpec, keySpec));
		try {
			$var($RSAUtil$KeyType, var$4, this->type);
			$var($AlgorithmParameterSpec, var$5, $nc(rsaSpec)->getParams());
			$var($BigInteger, var$6, rsaSpec->getModulus());
			$var($BigInteger, var$7, rsaSpec->getPublicExponent());
			$var($BigInteger, var$8, rsaSpec->getPrivateExponent());
			$var($BigInteger, var$9, rsaSpec->getPrimeP());
			$var($BigInteger, var$10, rsaSpec->getPrimeQ());
			$var($BigInteger, var$11, rsaSpec->getPrimeExponentP());
			$var($BigInteger, var$12, rsaSpec->getPrimeExponentQ());
			return static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>($new($RSAPrivateCrtKeyImpl, var$4, var$5, var$6, var$7, var$8, var$9, var$10, var$11, var$12, $(rsaSpec->getCrtCoefficient()))));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeySpecException, static_cast<$Throwable*>(e));
		}
	} else if ($instanceOf($RSAPrivateKeySpec, keySpec)) {
		$var($RSAPrivateKeySpec, rsaSpec, $cast($RSAPrivateKeySpec, keySpec));
		try {
			$var($RSAUtil$KeyType, var$13, this->type);
			$var($AlgorithmParameterSpec, var$14, $nc(rsaSpec)->getParams());
			$var($BigInteger, var$15, rsaSpec->getModulus());
			return static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>($new($RSAPrivateKeyImpl, var$13, var$14, var$15, $(rsaSpec->getPrivateExponent()))));
		} catch ($ProviderException& e) {
			$throwNew($InvalidKeySpecException, static_cast<$Throwable*>(e));
		}
	} else {
		$throwNew($InvalidKeySpecException, "Only RSAPrivate(Crt)KeySpec and PKCS8EncodedKeySpec supported for RSA private keys"_s);
	}
	$shouldNotReachHere();
}

$KeySpec* RSAKeyFactory::engineGetKeySpec($Key* key$renamed, $Class* keySpec) {
	$useLocalCurrentObjectStackCache();
	$var($Key, key, key$renamed);
	try {
		$assign(key, engineTranslateKey(key));
	} catch ($InvalidKeyException& e) {
		$throwNew($InvalidKeySpecException, static_cast<$Throwable*>(e));
	}
	if ($instanceOf($RSAPublicKey, key)) {
		$var($RSAPublicKey, rsaKey, $cast($RSAPublicKey, key));
		if ($nc(keySpec)->isAssignableFrom(RSAKeyFactory::RSA_PUB_KEYSPEC_CLS)) {
			$var($BigInteger, var$0, $nc(rsaKey)->getModulus());
			$var($BigInteger, var$1, rsaKey->getPublicExponent());
			return $cast($KeySpec, keySpec->cast($$new($RSAPublicKeySpec, var$0, var$1, $(rsaKey->getParams()))));
		} else if (keySpec->isAssignableFrom(RSAKeyFactory::X509_KEYSPEC_CLS)) {
			return $cast($KeySpec, keySpec->cast($$new($X509EncodedKeySpec, $($nc(key)->getEncoded()))));
		} else {
			$throwNew($InvalidKeySpecException, "KeySpec must be RSAPublicKeySpec or X509EncodedKeySpec for RSA public keys"_s);
		}
	} else if ($instanceOf($RSAPrivateKey, key)) {
		if ($nc(keySpec)->isAssignableFrom(RSAKeyFactory::PKCS8_KEYSPEC_CLS)) {
			$var($bytes, encoded, $nc(key)->getEncoded());
			{
				$var($Throwable, var$2, nullptr);
				$var($KeySpec, var$4, nullptr);
				bool return$3 = false;
				try {
					$assign(var$4, $cast($KeySpec, keySpec->cast($$new($PKCS8EncodedKeySpec, encoded))));
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
		} else if (keySpec->isAssignableFrom(RSAKeyFactory::RSA_PRIVCRT_KEYSPEC_CLS)) {
			if ($instanceOf($RSAPrivateCrtKey, key)) {
				$var($RSAPrivateCrtKey, crtKey, $cast($RSAPrivateCrtKey, key));
				$var($BigInteger, var$6, $nc(crtKey)->getModulus());
				$var($BigInteger, var$7, crtKey->getPublicExponent());
				$var($BigInteger, var$8, crtKey->getPrivateExponent());
				$var($BigInteger, var$9, crtKey->getPrimeP());
				$var($BigInteger, var$10, crtKey->getPrimeQ());
				$var($BigInteger, var$11, crtKey->getPrimeExponentP());
				$var($BigInteger, var$12, crtKey->getPrimeExponentQ());
				$var($BigInteger, var$13, crtKey->getCrtCoefficient());
				return $cast($KeySpec, keySpec->cast($$new($RSAPrivateCrtKeySpec, var$6, var$7, var$8, var$9, var$10, var$11, var$12, var$13, $(crtKey->getParams()))));
			} else {
				if (!keySpec->isAssignableFrom(RSAKeyFactory::RSA_PRIV_KEYSPEC_CLS)) {
					$throwNew($InvalidKeySpecException, "RSAPrivateCrtKeySpec can only be used with CRT keys"_s);
				}
				$var($RSAPrivateKey, rsaKey, $cast($RSAPrivateKey, key));
				$var($BigInteger, var$14, $nc(rsaKey)->getModulus());
				$var($BigInteger, var$15, rsaKey->getPrivateExponent());
				return $cast($KeySpec, keySpec->cast($$new($RSAPrivateKeySpec, var$14, var$15, $(rsaKey->getParams()))));
			}
		} else {
			$throwNew($InvalidKeySpecException, "KeySpec must be RSAPrivate(Crt)KeySpec or PKCS8EncodedKeySpec for RSA private keys"_s);
		}
	} else {
		$throwNew($InvalidKeySpecException, "Neither public nor private key"_s);
	}
}

void clinit$RSAKeyFactory($Class* class$) {
	$load($RSAPublicKeySpec);
	$assignStatic(RSAKeyFactory::RSA_PUB_KEYSPEC_CLS, $RSAPublicKeySpec::class$);
	$load($RSAPrivateKeySpec);
	$assignStatic(RSAKeyFactory::RSA_PRIV_KEYSPEC_CLS, $RSAPrivateKeySpec::class$);
	$load($RSAPrivateCrtKeySpec);
	$assignStatic(RSAKeyFactory::RSA_PRIVCRT_KEYSPEC_CLS, $RSAPrivateCrtKeySpec::class$);
	$load($X509EncodedKeySpec);
	$assignStatic(RSAKeyFactory::X509_KEYSPEC_CLS, $X509EncodedKeySpec::class$);
	$load($PKCS8EncodedKeySpec);
	$assignStatic(RSAKeyFactory::PKCS8_KEYSPEC_CLS, $PKCS8EncodedKeySpec::class$);
	RSAKeyFactory::restrictExpLen = "true"_s->equalsIgnoreCase($($GetPropertyAction::privilegedGetProperty("sun.security.rsa.restrictRSAExponent"_s, "true"_s)));
}

RSAKeyFactory::RSAKeyFactory() {
}

$Class* RSAKeyFactory::load$($String* name, bool initialize) {
	$loadClass(RSAKeyFactory, name, initialize, &_RSAKeyFactory_ClassInfo_, clinit$RSAKeyFactory, allocate$RSAKeyFactory);
	return class$;
}

$Class* RSAKeyFactory::class$ = nullptr;

		} // rsa
	} // security
} // sun