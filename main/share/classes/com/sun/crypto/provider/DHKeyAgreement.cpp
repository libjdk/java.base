#include <com/sun/crypto/provider/DHKeyAgreement.h>

#include <com/sun/crypto/provider/AESConstants.h>
#include <com/sun/crypto/provider/BlowfishConstants.h>
#include <com/sun/crypto/provider/DESKey.h>
#include <com/sun/crypto/provider/DESedeKey.h>
#include <com/sun/crypto/provider/DHKeyAgreement$AllowKDF.h>
#include <com/sun/crypto/provider/DHPublicKey.h>
#include <java/lang/IllegalStateException.h>
#include <java/math/BigInteger.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/ProviderException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/KeyAgreementSpi.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/ShortBufferException.h>
#include <javax/crypto/interfaces/DHPrivateKey.h>
#include <javax/crypto/interfaces/DHPublicKey.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/util/KeyUtil.h>
#include <jcpp.h>

#undef AES_KEYSIZES
#undef BLOWFISH_MAX_KEYSIZE
#undef ONE
#undef VALUE
#undef ZERO

using $AESConstants = ::com::sun::crypto::provider::AESConstants;
using $BlowfishConstants = ::com::sun::crypto::provider::BlowfishConstants;
using $DESKey = ::com::sun::crypto::provider::DESKey;
using $DESedeKey = ::com::sun::crypto::provider::DESedeKey;
using $DHKeyAgreement$AllowKDF = ::com::sun::crypto::provider::DHKeyAgreement$AllowKDF;
using $1DHPublicKey = ::com::sun::crypto::provider::DHPublicKey;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ProviderException = ::java::security::ProviderException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeyAgreementSpi = ::javax::crypto::KeyAgreementSpi;
using $SecretKey = ::javax::crypto::SecretKey;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $DHPrivateKey = ::javax::crypto::interfaces::DHPrivateKey;
using $DHPublicKey = ::javax::crypto::interfaces::DHPublicKey;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $KeyUtil = ::sun::security::util::KeyUtil;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _DHKeyAgreement_FieldInfo_[] = {
	{"generateSecret", "Z", nullptr, $PRIVATE, $field(DHKeyAgreement, generateSecret)},
	{"init_p", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHKeyAgreement, init_p)},
	{"init_g", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHKeyAgreement, init_g)},
	{"x", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHKeyAgreement, x)},
	{"y", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHKeyAgreement, y)},
	{}
};

$MethodInfo _DHKeyAgreement_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DHKeyAgreement, init$, void)},
	{"engineDoPhase", "(Ljava/security/Key;Z)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(DHKeyAgreement, engineDoPhase, $Key*, $Key*, bool), "java.security.InvalidKeyException,java.lang.IllegalStateException"},
	{"engineGenerateSecret", "()[B", nullptr, $PROTECTED, $virtualMethod(DHKeyAgreement, engineGenerateSecret, $bytes*), "java.lang.IllegalStateException"},
	{"engineGenerateSecret", "([BI)I", nullptr, $PROTECTED, $virtualMethod(DHKeyAgreement, engineGenerateSecret, int32_t, $bytes*, int32_t), "java.lang.IllegalStateException,javax.crypto.ShortBufferException"},
	{"engineGenerateSecret", "(Ljava/lang/String;)Ljavax/crypto/SecretKey;", nullptr, $PROTECTED, $virtualMethod(DHKeyAgreement, engineGenerateSecret, $SecretKey*, $String*), "java.lang.IllegalStateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"engineInit", "(Ljava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DHKeyAgreement, engineInit, void, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DHKeyAgreement, engineInit, void, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _DHKeyAgreement_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.DHKeyAgreement$AllowKDF", "com.sun.crypto.provider.DHKeyAgreement", "AllowKDF", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DHKeyAgreement_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.DHKeyAgreement",
	"javax.crypto.KeyAgreementSpi",
	nullptr,
	_DHKeyAgreement_FieldInfo_,
	_DHKeyAgreement_MethodInfo_,
	nullptr,
	nullptr,
	_DHKeyAgreement_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.DHKeyAgreement$AllowKDF"
};

$Object* allocate$DHKeyAgreement($Class* clazz) {
	return $of($alloc(DHKeyAgreement));
}

void DHKeyAgreement::init$() {
	$KeyAgreementSpi::init$();
	this->generateSecret = false;
	$set(this, init_p, nullptr);
	$set(this, init_g, nullptr);
	$init($BigInteger);
	$set(this, x, $BigInteger::ZERO);
	$set(this, y, $BigInteger::ZERO);
}

void DHKeyAgreement::engineInit($Key* key, $SecureRandom* random) {
	try {
		engineInit(key, nullptr, random);
	} catch ($InvalidAlgorithmParameterException& e) {
	}
}

void DHKeyAgreement::engineInit($Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	this->generateSecret = false;
	$set(this, init_p, nullptr);
	$set(this, init_g, nullptr);
	if ((params != nullptr) && !($instanceOf($DHParameterSpec, params))) {
		$throwNew($InvalidAlgorithmParameterException, "Diffie-Hellman parameters expected"_s);
	}
	if (!($instanceOf($DHPrivateKey, key))) {
		$throwNew($InvalidKeyException, "Diffie-Hellman private key expected"_s);
	}
	$var($DHPrivateKey, dhPrivKey, nullptr);
	$assign(dhPrivKey, $cast($DHPrivateKey, key));
	if (params != nullptr) {
		$set(this, init_p, $nc(($cast($DHParameterSpec, params)))->getP());
		$set(this, init_g, ($cast($DHParameterSpec, params))->getG());
	}
	$var($BigInteger, priv_p, $nc($($nc(dhPrivKey)->getParams()))->getP());
	$var($BigInteger, priv_g, $nc($(dhPrivKey->getParams()))->getG());
	if (this->init_p != nullptr && priv_p != nullptr && !($nc(this->init_p)->equals(priv_p))) {
		$throwNew($InvalidKeyException, "Incompatible parameters"_s);
	}
	if (this->init_g != nullptr && priv_g != nullptr && !($nc(this->init_g)->equals(priv_g))) {
		$throwNew($InvalidKeyException, "Incompatible parameters"_s);
	}
	if ((this->init_p == nullptr && priv_p == nullptr) || (this->init_g == nullptr && priv_g == nullptr)) {
		$throwNew($InvalidKeyException, "Missing parameters"_s);
	}
	$set(this, init_p, priv_p);
	$set(this, init_g, priv_g);
	$set(this, x, dhPrivKey->getX());
}

$Key* DHKeyAgreement::engineDoPhase($Key* key, bool lastPhase) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($DHPublicKey, key))) {
		$throwNew($InvalidKeyException, "Diffie-Hellman public key expected"_s);
	}
	$var($DHPublicKey, dhPubKey, nullptr);
	$assign(dhPubKey, $cast($DHPublicKey, key));
	if (this->init_p == nullptr || this->init_g == nullptr) {
		$throwNew($IllegalStateException, "Not initialized"_s);
	}
	$var($BigInteger, pub_p, $nc($($nc(dhPubKey)->getParams()))->getP());
	$var($BigInteger, pub_g, $nc($(dhPubKey->getParams()))->getG());
	if (pub_p != nullptr && !($nc(this->init_p)->equals(pub_p))) {
		$throwNew($InvalidKeyException, "Incompatible parameters"_s);
	}
	if (pub_g != nullptr && !($nc(this->init_g)->equals(pub_g))) {
		$throwNew($InvalidKeyException, "Incompatible parameters"_s);
	}
	$KeyUtil::validate(static_cast<$Key*>(dhPubKey));
	$set(this, y, dhPubKey->getY());
	this->generateSecret = true;
	if (lastPhase == false) {
		$var($bytes, intermediate, engineGenerateSecret());
		return $new($1DHPublicKey, $$new($BigInteger, 1, intermediate), this->init_p, this->init_g);
	} else {
		return nullptr;
	}
}

$bytes* DHKeyAgreement::engineGenerateSecret() {
	int32_t expectedLen = (int32_t)((uint32_t)($nc(this->init_p)->bitLength() + 7) >> 3);
	$var($bytes, result, $new($bytes, expectedLen));
	try {
		engineGenerateSecret(result, 0);
	} catch ($ShortBufferException& sbe) {
	}
	return result;
}

int32_t DHKeyAgreement::engineGenerateSecret($bytes* sharedSecret, int32_t offset) {
	$useLocalCurrentObjectStackCache();
	if (this->generateSecret == false) {
		$throwNew($IllegalStateException, "Key agreement has not been completed yet"_s);
	}
	if (sharedSecret == nullptr) {
		$throwNew($ShortBufferException, "No buffer provided for shared secret"_s);
	}
	$var($BigInteger, modulus, this->init_p);
	int32_t expectedLen = (int32_t)((uint32_t)($nc(modulus)->bitLength() + 7) >> 3);
	if (($nc(sharedSecret)->length - offset) < expectedLen) {
		$throwNew($ShortBufferException, "Buffer too short for shared secret"_s);
	}
	this->generateSecret = false;
	$var($BigInteger, z, $nc(this->y)->modPow(this->x, modulus));
	bool var$0 = ($nc(z)->compareTo($BigInteger::ONE) <= 0);
	if (var$0 || $nc(z)->equals($(modulus->subtract($BigInteger::ONE)))) {
		$throwNew($ProviderException, "Generated secret is out-of-range of (1, p -1)"_s);
	}
	$var($bytes, secret, $nc(z)->toByteArray());
	if ($nc(secret)->length == expectedLen) {
		$System::arraycopy(secret, 0, sharedSecret, offset, secret->length);
	} else if (secret->length < expectedLen) {
		$System::arraycopy(secret, 0, sharedSecret, offset + (expectedLen - secret->length), secret->length);
	} else if ((secret->length == (expectedLen + 1)) && secret->get(0) == 0) {
		$System::arraycopy(secret, 1, sharedSecret, offset, expectedLen);
	} else {
		$throwNew($ProviderException, "Generated secret is out-of-range"_s);
	}
	return expectedLen;
}

$SecretKey* DHKeyAgreement::engineGenerateSecret($String* algorithm) {
	$useLocalCurrentObjectStackCache();
	if (algorithm == nullptr) {
		$throwNew($NoSuchAlgorithmException, "null algorithm"_s);
	}
	$init($DHKeyAgreement$AllowKDF);
	if (!$nc(algorithm)->equalsIgnoreCase("TlsPremasterSecret"_s) && !$DHKeyAgreement$AllowKDF::VALUE) {
		$throwNew($NoSuchAlgorithmException, $$str({"Unsupported secret key algorithm: "_s, algorithm}));
	}
	$var($bytes, secret, engineGenerateSecret());
	if ($nc(algorithm)->equalsIgnoreCase("DES"_s)) {
		return $new($DESKey, secret);
	} else {
		bool var$1 = algorithm->equalsIgnoreCase("DESede"_s);
		if (var$1 || algorithm->equalsIgnoreCase("TripleDES"_s)) {
			return $new($DESedeKey, secret);
		} else if (algorithm->equalsIgnoreCase("Blowfish"_s)) {
			int32_t keysize = $nc(secret)->length;
			if (keysize >= $BlowfishConstants::BLOWFISH_MAX_KEYSIZE) {
				keysize = $BlowfishConstants::BLOWFISH_MAX_KEYSIZE;
			}
			$var($SecretKeySpec, skey, $new($SecretKeySpec, secret, 0, keysize, "Blowfish"_s));
			return skey;
		} else if (algorithm->equalsIgnoreCase("AES"_s)) {
			int32_t keysize = $nc(secret)->length;
			$var($SecretKeySpec, skey, nullptr);
			$init($AESConstants);
			int32_t idx = $nc($AESConstants::AES_KEYSIZES)->length - 1;
			while (skey == nullptr && idx >= 0) {
				if (keysize >= $nc($AESConstants::AES_KEYSIZES)->get(idx)) {
					keysize = $nc($AESConstants::AES_KEYSIZES)->get(idx);
					$assign(skey, $new($SecretKeySpec, secret, 0, keysize, "AES"_s));
				}
				--idx;
			}
			if (skey == nullptr) {
				$throwNew($InvalidKeyException, "Key material is too short"_s);
			}
			return skey;
		} else if (algorithm->equals("TlsPremasterSecret"_s)) {
			return $new($SecretKeySpec, $($KeyUtil::trimZeroes(secret)), "TlsPremasterSecret"_s);
		} else {
			$throwNew($NoSuchAlgorithmException, $$str({"Unsupported secret key algorithm: "_s, algorithm}));
		}
	}
}

DHKeyAgreement::DHKeyAgreement() {
}

$Class* DHKeyAgreement::load$($String* name, bool initialize) {
	$loadClass(DHKeyAgreement, name, initialize, &_DHKeyAgreement_ClassInfo_, allocate$DHKeyAgreement);
	return class$;
}

$Class* DHKeyAgreement::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com