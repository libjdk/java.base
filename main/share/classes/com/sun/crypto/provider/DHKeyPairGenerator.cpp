#include <com/sun/crypto/provider/DHKeyPairGenerator.h>

#include <com/sun/crypto/provider/DHPrivateKey.h>
#include <com/sun/crypto/provider/DHPublicKey.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/KeyPair.h>
#include <java/security/KeyPairGeneratorSpi.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Random.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <sun/security/provider/ParameterCache.h>
#include <sun/security/util/SecurityProviderConstants.h>
#include <jcpp.h>

#undef DEF_DH_KEY_SIZE
#undef ONE
#undef TWO

using $DHPrivateKey = ::com::sun::crypto::provider::DHPrivateKey;
using $DHPublicKey = ::com::sun::crypto::provider::DHPublicKey;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $KeyPair = ::java::security::KeyPair;
using $KeyPairGeneratorSpi = ::java::security::KeyPairGeneratorSpi;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Random = ::java::util::Random;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $ParameterCache = ::sun::security::provider::ParameterCache;
using $SecurityProviderConstants = ::sun::security::util::SecurityProviderConstants;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _DHKeyPairGenerator_FieldInfo_[] = {
	{"params", "Ljavax/crypto/spec/DHParameterSpec;", nullptr, $PRIVATE, $field(DHKeyPairGenerator, params)},
	{"pSize", "I", nullptr, $PRIVATE, $field(DHKeyPairGenerator, pSize)},
	{"lSize", "I", nullptr, $PRIVATE, $field(DHKeyPairGenerator, lSize)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(DHKeyPairGenerator, random)},
	{}
};

$MethodInfo _DHKeyPairGenerator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DHKeyPairGenerator, init$, void)},
	{"checkKeySize", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(DHKeyPairGenerator, checkKeySize, void, int32_t), "java.security.InvalidParameterException"},
	{"generateKeyPair", "()Ljava/security/KeyPair;", nullptr, $PUBLIC, $virtualMethod(DHKeyPairGenerator, generateKeyPair, $KeyPair*)},
	{"initialize", "(ILjava/security/SecureRandom;)V", nullptr, $PUBLIC, $virtualMethod(DHKeyPairGenerator, initialize, void, int32_t, $SecureRandom*)},
	{"initialize", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC, $virtualMethod(DHKeyPairGenerator, initialize, void, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidAlgorithmParameterException"},
	{}
};

$ClassInfo _DHKeyPairGenerator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.DHKeyPairGenerator",
	"java.security.KeyPairGeneratorSpi",
	nullptr,
	_DHKeyPairGenerator_FieldInfo_,
	_DHKeyPairGenerator_MethodInfo_
};

$Object* allocate$DHKeyPairGenerator($Class* clazz) {
	return $of($alloc(DHKeyPairGenerator));
}

void DHKeyPairGenerator::init$() {
	$KeyPairGeneratorSpi::init$();
	$init($SecurityProviderConstants);
	initialize($SecurityProviderConstants::DEF_DH_KEY_SIZE, ($SecureRandom*)nullptr);
}

void DHKeyPairGenerator::checkKeySize(int32_t keysize) {
	$init(DHKeyPairGenerator);
	$useLocalCurrentObjectStackCache();
	if ((keysize < 512) || (keysize > 8192) || (((int32_t)(keysize & (uint32_t)63)) != 0)) {
		$throwNew($InvalidParameterException, $$str({"DH key size must be multiple of 64, and can only range from 512 to 8192 (inclusive). The specific key size "_s, $$str(keysize), " is not supported"_s}));
	}
}

void DHKeyPairGenerator::initialize(int32_t keysize, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	checkKeySize(keysize);
	$set(this, params, $ParameterCache::getCachedDHParameterSpec(keysize));
	if ((this->params == nullptr) && (keysize > 1024)) {
		$throwNew($InvalidParameterException, $$str({"Unsupported "_s, $$str(keysize), "-bit DH parameter generation"_s}));
	}
	this->pSize = keysize;
	this->lSize = 0;
	$set(this, random, random);
}

void DHKeyPairGenerator::initialize($AlgorithmParameterSpec* algParams, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($DHParameterSpec, algParams))) {
		$throwNew($InvalidAlgorithmParameterException, "Inappropriate parameter type"_s);
	}
	$set(this, params, $cast($DHParameterSpec, algParams));
	this->pSize = $nc($($nc(this->params)->getP()))->bitLength();
	try {
		checkKeySize(this->pSize);
	} catch ($InvalidParameterException& ipe) {
		$throwNew($InvalidAlgorithmParameterException, $(ipe->getMessage()));
	}
	this->lSize = $nc(this->params)->getL();
	if ((this->lSize != 0) && (this->lSize > this->pSize)) {
		$throwNew($InvalidAlgorithmParameterException, "Exponent size must not be larger than modulus size"_s);
	}
	$set(this, random, random);
}

$KeyPair* DHKeyPairGenerator::generateKeyPair() {
	$useLocalCurrentObjectStackCache();
	if (this->random == nullptr) {
		$set(this, random, $SunJCE::getRandom());
	}
	if (this->params == nullptr) {
		try {
			$set(this, params, $ParameterCache::getDHParameterSpec(this->pSize, this->random));
		} catch ($GeneralSecurityException& e) {
			$throwNew($ProviderException, static_cast<$Throwable*>(e));
		}
	}
	$var($BigInteger, p, $nc(this->params)->getP());
	$var($BigInteger, g, $nc(this->params)->getG());
	if (this->lSize <= 0) {
		this->lSize = this->pSize >> 1;
		if (this->lSize < 384) {
			this->lSize = 384;
		}
	}
	$var($BigInteger, x, nullptr);
	$init($BigInteger);
	$var($BigInteger, pMinus2, $nc(p)->subtract($BigInteger::TWO));
	bool var$0 = false;
	do {
		$assign(x, $new($BigInteger, this->lSize, static_cast<$Random*>(this->random)));
	bool var$1 = ($nc(x)->compareTo($BigInteger::ONE) < 0);
		var$0 = var$1 || ($nc(x)->compareTo(pMinus2) > 0);
	} while (var$0 || ($nc(x)->bitLength() != this->lSize));
	$var($BigInteger, y, $nc(g)->modPow(x, p));
	$var($DHPublicKey, pubKey, $new($DHPublicKey, y, p, g, this->lSize));
	$var($DHPrivateKey, privKey, $new($DHPrivateKey, x, p, g, this->lSize));
	return $new($KeyPair, pubKey, privKey);
}

DHKeyPairGenerator::DHKeyPairGenerator() {
}

$Class* DHKeyPairGenerator::load$($String* name, bool initialize) {
	$loadClass(DHKeyPairGenerator, name, initialize, &_DHKeyPairGenerator_ClassInfo_, allocate$DHKeyPairGenerator);
	return class$;
}

$Class* DHKeyPairGenerator::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com