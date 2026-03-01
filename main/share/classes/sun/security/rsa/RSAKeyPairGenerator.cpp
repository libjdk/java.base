#include <sun/security/rsa/RSAKeyPairGenerator.h>

#include <java/math/BigInteger.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/KeyPair.h>
#include <java/security/KeyPairGeneratorSpi.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/RSAKeyGenParameterSpec.h>
#include <java/util/Random.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/pkcs/PKCS8Key.h>
#include <sun/security/rsa/RSAKeyFactory.h>
#include <sun/security/rsa/RSAPrivateCrtKeyImpl.h>
#include <sun/security/rsa/RSAPublicKeyImpl.h>
#include <sun/security/rsa/RSAUtil$KeyType.h>
#include <sun/security/rsa/RSAUtil.h>
#include <sun/security/x509/X509Key.h>
#include <jcpp.h>

#undef ONE
#undef TWO
#undef ZERO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $KeyPair = ::java::security::KeyPair;
using $KeyPairGeneratorSpi = ::java::security::KeyPairGeneratorSpi;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $RSAKeyGenParameterSpec = ::java::security::spec::RSAKeyGenParameterSpec;
using $Random = ::java::util::Random;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $PKCS8Key = ::sun::security::pkcs::PKCS8Key;
using $RSAKeyFactory = ::sun::security::rsa::RSAKeyFactory;
using $RSAPrivateCrtKeyImpl = ::sun::security::rsa::RSAPrivateCrtKeyImpl;
using $RSAPublicKeyImpl = ::sun::security::rsa::RSAPublicKeyImpl;
using $RSAUtil = ::sun::security::rsa::RSAUtil;
using $RSAUtil$KeyType = ::sun::security::rsa::RSAUtil$KeyType;
using $X509Key = ::sun::security::x509::X509Key;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _RSAKeyPairGenerator_FieldInfo_[] = {
	{"SQRT_2048", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyPairGenerator, SQRT_2048)},
	{"SQRT_3072", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyPairGenerator, SQRT_3072)},
	{"SQRT_4096", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSAKeyPairGenerator, SQRT_4096)},
	{"publicExponent", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAKeyPairGenerator, publicExponent)},
	{"keySize", "I", nullptr, $PRIVATE, $field(RSAKeyPairGenerator, keySize)},
	{"type", "Lsun/security/rsa/RSAUtil$KeyType;", nullptr, $PRIVATE | $FINAL, $field(RSAKeyPairGenerator, type)},
	{"keyParams", "Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PRIVATE, $field(RSAKeyPairGenerator, keyParams)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(RSAKeyPairGenerator, random)},
	{"useNew", "Z", nullptr, $PRIVATE, $field(RSAKeyPairGenerator, useNew)},
	{}
};

$MethodInfo _RSAKeyPairGenerator_MethodInfo_[] = {
	{"<init>", "(Lsun/security/rsa/RSAUtil$KeyType;I)V", nullptr, 0, $method(RSAKeyPairGenerator, init$, void, $RSAUtil$KeyType*, int32_t)},
	{"createKeyPair", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/security/KeyPair;", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAKeyPairGenerator, createKeyPair, $KeyPair*, $RSAUtil$KeyType*, $AlgorithmParameterSpec*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*)},
	{"generateKeyPair", "()Ljava/security/KeyPair;", nullptr, $PUBLIC, $virtualMethod(RSAKeyPairGenerator, generateKeyPair, $KeyPair*)},
	{"getSqrt", "(I)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAKeyPairGenerator, getSqrt, $BigInteger*, int32_t)},
	{"initialize", "(ILjava/security/SecureRandom;)V", nullptr, $PUBLIC, $virtualMethod(RSAKeyPairGenerator, initialize, void, int32_t, $SecureRandom*)},
	{"initialize", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC, $virtualMethod(RSAKeyPairGenerator, initialize, void, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidAlgorithmParameterException"},
	{"isRelativePrime", "(Ljava/math/BigInteger;Ljava/math/BigInteger;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAKeyPairGenerator, isRelativePrime, bool, $BigInteger*, $BigInteger*)},
	{}
};

$InnerClassInfo _RSAKeyPairGenerator_InnerClassesInfo_[] = {
	{"sun.security.rsa.RSAKeyPairGenerator$PSS", "sun.security.rsa.RSAKeyPairGenerator", "PSS", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSAKeyPairGenerator$Legacy", "sun.security.rsa.RSAKeyPairGenerator", "Legacy", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSAKeyPairGenerator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.rsa.RSAKeyPairGenerator",
	"java.security.KeyPairGeneratorSpi",
	nullptr,
	_RSAKeyPairGenerator_FieldInfo_,
	_RSAKeyPairGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_RSAKeyPairGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.rsa.RSAKeyPairGenerator$PSS,sun.security.rsa.RSAKeyPairGenerator$Legacy"
};

$Object* allocate$RSAKeyPairGenerator($Class* clazz) {
	return $of($alloc(RSAKeyPairGenerator));
}

$BigInteger* RSAKeyPairGenerator::SQRT_2048 = nullptr;
$BigInteger* RSAKeyPairGenerator::SQRT_3072 = nullptr;
$BigInteger* RSAKeyPairGenerator::SQRT_4096 = nullptr;

void RSAKeyPairGenerator::init$($RSAUtil$KeyType* type, int32_t defKeySize) {
	$KeyPairGeneratorSpi::init$();
	$set(this, type, type);
	initialize(defKeySize, ($SecureRandom*)nullptr);
}

void RSAKeyPairGenerator::initialize(int32_t keySize, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($RSAKeyGenParameterSpec);
		initialize(static_cast<$AlgorithmParameterSpec*>($$new($RSAKeyGenParameterSpec, keySize, $RSAKeyGenParameterSpec::F4)), random);
	} catch ($InvalidAlgorithmParameterException& iape) {
		$throwNew($InvalidParameterException, $(iape->getMessage()));
	}
}

void RSAKeyPairGenerator::initialize($AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($RSAKeyGenParameterSpec, params) == false) {
		$throwNew($InvalidAlgorithmParameterException, "Params must be instance of RSAKeyGenParameterSpec"_s);
	}
	$var($RSAKeyGenParameterSpec, rsaSpec, $cast($RSAKeyGenParameterSpec, params));
	int32_t tmpKeySize = $nc(rsaSpec)->getKeysize();
	$var($BigInteger, tmpPubExp, rsaSpec->getPublicExponent());
	$var($AlgorithmParameterSpec, tmpParams, rsaSpec->getKeyParams());
	bool useNew = (tmpKeySize >= 2048 && (((int32_t)(tmpKeySize & (uint32_t)1)) == 0));
	if (tmpPubExp == nullptr) {
		$assign(tmpPubExp, $RSAKeyGenParameterSpec::F4);
	} else {
		if (!$nc(tmpPubExp)->testBit(0)) {
			$throwNew($InvalidAlgorithmParameterException, "Public exponent must be an odd number"_s);
		}
		$var($BigInteger, minValue, $RSAKeyGenParameterSpec::F0);
		int32_t maxBitLength = tmpKeySize;
		if ($nc(tmpPubExp)->compareTo($RSAKeyGenParameterSpec::F0) < 0) {
			$throwNew($InvalidAlgorithmParameterException, $$str({"Public exponent must be "_s, minValue, " or larger"_s}));
		}
		if ($nc(tmpPubExp)->bitLength() > maxBitLength) {
			$throwNew($InvalidAlgorithmParameterException, $$str({"Public exponent must be no longer than "_s, $$str(maxBitLength), " bits"_s}));
		}
		bool var$0 = ($nc(tmpPubExp)->compareTo($RSAKeyGenParameterSpec::F4) >= 0);
		useNew &= (var$0 && (tmpPubExp->bitLength() < 256));
	}
	try {
		$RSAKeyFactory::checkKeyLengths(tmpKeySize, tmpPubExp, 512, 64 * 1024);
	} catch ($InvalidKeyException& e) {
		$throwNew($InvalidAlgorithmParameterException, "Invalid key sizes"_s, e);
	}
	try {
		$set(this, keyParams, $RSAUtil::checkParamsAgainstType(this->type, tmpParams));
	} catch ($ProviderException& e) {
		$throwNew($InvalidAlgorithmParameterException, "Invalid key parameters"_s, e);
	}
	this->keySize = tmpKeySize;
	$set(this, publicExponent, tmpPubExp);
	$set(this, random, random == nullptr ? $JCAUtil::getSecureRandom() : random);
	this->useNew = useNew;
}

$KeyPair* RSAKeyPairGenerator::generateKeyPair() {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, e, this->publicExponent);
	$init($BigInteger);
	$var($BigInteger, minValue, this->useNew ? getSqrt(this->keySize) : $BigInteger::ZERO);
	int32_t lp = (this->keySize + 1) >> 1;
	int32_t lq = this->keySize - lp;
	int32_t pqDiffSize = lp - 100;
	while (true) {
		$var($BigInteger, p, nullptr);
		$var($BigInteger, q, nullptr);
		int32_t i = 0;
		while (i++ < 10 * lp) {
			$var($BigInteger, tmpP, $BigInteger::probablePrime(lp, this->random));
			bool var$0 = (!this->useNew || $nc(tmpP)->compareTo(minValue) == 1);
			if (var$0 && isRelativePrime(e, $(tmpP->subtract($BigInteger::ONE)))) {
				$assign(p, tmpP);
				break;
			}
		}
		if (p == nullptr) {
			$throwNew($ProviderException, "Cannot find prime P"_s);
		}
		i = 0;
		while (i++ < 20 * lq) {
			$var($BigInteger, tmpQ, $BigInteger::probablePrime(lq, this->random));
			bool var$2 = (!this->useNew || $nc(tmpQ)->compareTo(minValue) == 1);
			bool var$1 = var$2 && ($nc($($nc($($nc(p)->subtract(tmpQ)))->abs()))->compareTo($($nc($BigInteger::TWO)->pow(pqDiffSize))) == 1);
			if (var$1 && isRelativePrime(e, $(tmpQ->subtract($BigInteger::ONE)))) {
				$assign(q, tmpQ);
				break;
			}
		}
		if (q == nullptr) {
			$throwNew($ProviderException, "Cannot find prime Q"_s);
		}
		$var($BigInteger, n, $nc(p)->multiply(q));
		if ($nc(n)->bitLength() != this->keySize) {
			continue;
		}
		$var($KeyPair, kp, createKeyPair(this->type, this->keyParams, n, e, p, q));
		if (kp != nullptr) {
			return kp;
		}
	}
}

$BigInteger* RSAKeyPairGenerator::getSqrt(int32_t keySize) {
	$init(RSAKeyPairGenerator);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, sqrt, nullptr);
	switch (keySize) {
	case 2048:
		{
			$assign(sqrt, RSAKeyPairGenerator::SQRT_2048);
			break;
		}
	case 3072:
		{
			$assign(sqrt, RSAKeyPairGenerator::SQRT_3072);
			break;
		}
	case 4096:
		{
			$assign(sqrt, RSAKeyPairGenerator::SQRT_4096);
			break;
		}
	default:
		{
			$init($BigInteger);
			$assign(sqrt, $nc($($nc($BigInteger::TWO)->pow(keySize - 1)))->sqrt());
		}
	}
	return sqrt;
}

bool RSAKeyPairGenerator::isRelativePrime($BigInteger* e, $BigInteger* bi) {
	$init(RSAKeyPairGenerator);
	$useLocalCurrentObjectStackCache();
	$init($RSAKeyGenParameterSpec);
	bool var$0 = $nc(e)->compareTo($RSAKeyGenParameterSpec::F4) == 0;
	if (var$0 || $nc(e)->compareTo($RSAKeyGenParameterSpec::F0) == 0) {
		return !$nc($($nc(bi)->mod(e)))->equals($BigInteger::ZERO);
	} else {
		return $nc($(e->gcd(bi)))->equals($BigInteger::ONE);
	}
}

$KeyPair* RSAKeyPairGenerator::createKeyPair($RSAUtil$KeyType* type, $AlgorithmParameterSpec* keyParams, $BigInteger* n, $BigInteger* e, $BigInteger* p, $BigInteger* q) {
	$init(RSAKeyPairGenerator);
	$useLocalCurrentObjectStackCache();
	$init($BigInteger);
	$var($BigInteger, p1, $nc(p)->subtract($BigInteger::ONE));
	$var($BigInteger, q1, $nc(q)->subtract($BigInteger::ONE));
	$var($BigInteger, phi, $nc(p1)->multiply(q1));
	$var($BigInteger, gcd, p1->gcd(q1));
	$var($BigInteger, lcm, $nc(gcd)->equals($BigInteger::ONE) ? phi : $nc(phi)->divide(gcd));
	$var($BigInteger, d, $nc(e)->modInverse(lcm));
	if ($nc(d)->compareTo($($nc($BigInteger::TWO)->pow(p->bitLength()))) != 1) {
		return nullptr;
	}
	$var($BigInteger, pe, $nc(d)->mod(p1));
	$var($BigInteger, qe, d->mod(q1));
	$var($BigInteger, coeff, q->modInverse(p));
	try {
		$var($PublicKey, publicKey, static_cast<$PublicKey*>(static_cast<$X509Key*>($new($RSAPublicKeyImpl, type, keyParams, n, e))));
		$var($PrivateKey, privateKey, static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>($new($RSAPrivateCrtKeyImpl, type, keyParams, n, e, d, p, q, pe, qe, coeff))));
		return $new($KeyPair, publicKey, privateKey);
	} catch ($InvalidKeyException& exc) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(exc));
	}
	$shouldNotReachHere();
}

void clinit$RSAKeyPairGenerator($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$init($BigInteger);
		$assignStatic(RSAKeyPairGenerator::SQRT_2048, $nc($($nc($BigInteger::TWO)->pow(2047)))->sqrt());
		$assignStatic(RSAKeyPairGenerator::SQRT_3072, $nc($($nc($BigInteger::TWO)->pow(3071)))->sqrt());
		$assignStatic(RSAKeyPairGenerator::SQRT_4096, $nc($($nc($BigInteger::TWO)->pow(4095)))->sqrt());
	}
}

RSAKeyPairGenerator::RSAKeyPairGenerator() {
}

$Class* RSAKeyPairGenerator::load$($String* name, bool initialize) {
	$loadClass(RSAKeyPairGenerator, name, initialize, &_RSAKeyPairGenerator_ClassInfo_, clinit$RSAKeyPairGenerator, allocate$RSAKeyPairGenerator);
	return class$;
}

$Class* RSAKeyPairGenerator::class$ = nullptr;

		} // rsa
	} // security
} // sun