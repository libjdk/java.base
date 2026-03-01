#include <sun/security/provider/DSAKeyPairGenerator.h>

#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/KeyPair.h>
#include <java/security/KeyPairGenerator.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/DSAParameterSpec.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/pkcs/PKCS8Key.h>
#include <sun/security/provider/DSAPrivateKey.h>
#include <sun/security/provider/DSAPublicKey.h>
#include <sun/security/provider/DSAPublicKeyImpl.h>
#include <sun/security/provider/ParameterCache.h>
#include <sun/security/util/SecurityProviderConstants.h>
#include <sun/security/x509/X509Key.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $KeyPair = ::java::security::KeyPair;
using $KeyPairGenerator = ::java::security::KeyPairGenerator;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $DSAParameterSpec = ::java::security::spec::DSAParameterSpec;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $PKCS8Key = ::sun::security::pkcs::PKCS8Key;
using $DSAPrivateKey = ::sun::security::provider::DSAPrivateKey;
using $DSAPublicKey = ::sun::security::provider::DSAPublicKey;
using $DSAPublicKeyImpl = ::sun::security::provider::DSAPublicKeyImpl;
using $ParameterCache = ::sun::security::provider::ParameterCache;
using $SecurityProviderConstants = ::sun::security::util::SecurityProviderConstants;
using $X509Key = ::sun::security::x509::X509Key;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _DSAKeyPairGenerator_FieldInfo_[] = {
	{"plen", "I", nullptr, $PRIVATE, $field(DSAKeyPairGenerator, plen)},
	{"qlen", "I", nullptr, $PRIVATE, $field(DSAKeyPairGenerator, qlen)},
	{"forceNewParameters", "Z", nullptr, 0, $field(DSAKeyPairGenerator, forceNewParameters)},
	{"params", "Ljava/security/spec/DSAParameterSpec;", nullptr, $PRIVATE, $field(DSAKeyPairGenerator, params)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(DSAKeyPairGenerator, random)},
	{}
};

$MethodInfo _DSAKeyPairGenerator_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(DSAKeyPairGenerator, init$, void, int32_t)},
	{"checkStrength", "(II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(DSAKeyPairGenerator, checkStrength, void, int32_t, int32_t)},
	{"generateKeyPair", "()Ljava/security/KeyPair;", nullptr, $PUBLIC, $virtualMethod(DSAKeyPairGenerator, generateKeyPair, $KeyPair*)},
	{"generateKeyPair", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/security/SecureRandom;)Ljava/security/KeyPair;", nullptr, $PRIVATE, $method(DSAKeyPairGenerator, generateKeyPair, $KeyPair*, $BigInteger*, $BigInteger*, $BigInteger*, $SecureRandom*)},
	{"generateX", "(Ljava/security/SecureRandom;Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(DSAKeyPairGenerator, generateX, $BigInteger*, $SecureRandom*, $BigInteger*)},
	{"generateY", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, 0, $virtualMethod(DSAKeyPairGenerator, generateY, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*)},
	{"init", "(ILjava/security/SecureRandom;Z)V", nullptr, 0, $virtualMethod(DSAKeyPairGenerator, init, void, int32_t, $SecureRandom*, bool)},
	{"init", "(Ljava/security/spec/DSAParameterSpec;Ljava/security/SecureRandom;Z)V", nullptr, 0, $virtualMethod(DSAKeyPairGenerator, init, void, $DSAParameterSpec*, $SecureRandom*, bool)},
	{"initialize", "(ILjava/security/SecureRandom;)V", nullptr, $PUBLIC, $virtualMethod(DSAKeyPairGenerator, initialize, void, int32_t, $SecureRandom*)},
	{"initialize", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC, $virtualMethod(DSAKeyPairGenerator, initialize, void, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _DSAKeyPairGenerator_InnerClassesInfo_[] = {
	{"sun.security.provider.DSAKeyPairGenerator$Legacy", "sun.security.provider.DSAKeyPairGenerator", "Legacy", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSAKeyPairGenerator$Current", "sun.security.provider.DSAKeyPairGenerator", "Current", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _DSAKeyPairGenerator_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.DSAKeyPairGenerator",
	"java.security.KeyPairGenerator",
	nullptr,
	_DSAKeyPairGenerator_FieldInfo_,
	_DSAKeyPairGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_DSAKeyPairGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.DSAKeyPairGenerator$Legacy,sun.security.provider.DSAKeyPairGenerator$Current"
};

$Object* allocate$DSAKeyPairGenerator($Class* clazz) {
	return $of($alloc(DSAKeyPairGenerator));
}

void DSAKeyPairGenerator::init$(int32_t defaultKeySize) {
	$KeyPairGenerator::init$("DSA"_s);
	initialize(defaultKeySize, ($SecureRandom*)nullptr);
}

void DSAKeyPairGenerator::checkStrength(int32_t sizeP, int32_t sizeQ) {
	$init(DSAKeyPairGenerator);
	$useLocalCurrentObjectStackCache();
	if ((sizeP >= 512) && (sizeP <= 1024) && (sizeP % 64 == 0) && sizeQ == 160) {
	} else if (sizeP == 2048 && (sizeQ == 224 || sizeQ == 256)) {
	} else if (sizeP == 3072 && sizeQ == 256) {
	} else {
		$throwNew($InvalidParameterException, $$str({"Unsupported prime and subprime size combination: "_s, $$str(sizeP), ", "_s, $$str(sizeQ)}));
	}
}

void DSAKeyPairGenerator::initialize(int32_t modlen, $SecureRandom* random) {
	init(modlen, random, false);
}

void DSAKeyPairGenerator::initialize($AlgorithmParameterSpec* params, $SecureRandom* random) {
	if (!($instanceOf($DSAParameterSpec, params))) {
		$throwNew($InvalidAlgorithmParameterException, "Inappropriate parameter"_s);
	}
	init($cast($DSAParameterSpec, params), random, false);
}

void DSAKeyPairGenerator::init(int32_t modlen, $SecureRandom* random, bool forceNew) {
	int32_t subPrimeLen = $SecurityProviderConstants::getDefDSASubprimeSize(modlen);
	checkStrength(modlen, subPrimeLen);
	this->plen = modlen;
	this->qlen = subPrimeLen;
	$set(this, params, nullptr);
	$set(this, random, random);
	this->forceNewParameters = forceNew;
}

void DSAKeyPairGenerator::init($DSAParameterSpec* params, $SecureRandom* random, bool forceNew) {
	$useLocalCurrentObjectStackCache();
	int32_t sizeP = $nc($($nc(params)->getP()))->bitLength();
	int32_t sizeQ = $nc($(params->getQ()))->bitLength();
	checkStrength(sizeP, sizeQ);
	this->plen = sizeP;
	this->qlen = sizeQ;
	$set(this, params, params);
	$set(this, random, random);
	this->forceNewParameters = forceNew;
}

$KeyPair* DSAKeyPairGenerator::generateKeyPair() {
	$useLocalCurrentObjectStackCache();
	if (this->random == nullptr) {
		$set(this, random, $JCAUtil::getSecureRandom());
	}
	$var($DSAParameterSpec, spec, nullptr);
	try {
		if (this->forceNewParameters) {
			$assign(spec, $ParameterCache::getNewDSAParameterSpec(this->plen, this->qlen, this->random));
		} else {
			if (this->params == nullptr) {
				$set(this, params, $ParameterCache::getDSAParameterSpec(this->plen, this->qlen, this->random));
			}
			$assign(spec, this->params);
		}
	} catch ($GeneralSecurityException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$var($BigInteger, var$0, $nc(spec)->getP());
	$var($BigInteger, var$1, spec->getQ());
	return generateKeyPair(var$0, var$1, $(spec->getG()), this->random);
}

$KeyPair* DSAKeyPairGenerator::generateKeyPair($BigInteger* p, $BigInteger* q, $BigInteger* g, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, x, generateX(random, q));
	$var($BigInteger, y, generateY(x, p, g));
	try {
		$var($DSAPublicKey, pub, nullptr);
		$assign(pub, $new($DSAPublicKeyImpl, y, p, q, g));
		$var($DSAPrivateKey, priv, $new($DSAPrivateKey, x, p, q, g));
		$var($KeyPair, pair, $new($KeyPair, static_cast<$PublicKey*>(static_cast<$X509Key*>(pub)), static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>(priv))));
		return pair;
	} catch ($InvalidKeyException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$BigInteger* DSAKeyPairGenerator::generateX($SecureRandom* random, $BigInteger* q) {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, x, nullptr);
	$var($bytes, temp, $new($bytes, this->qlen));
	while (true) {
		$nc(random)->nextBytes(temp);
		$assign(x, $$new($BigInteger, 1, temp)->mod(q));
		bool var$0 = $nc(x)->signum() > 0;
		if (var$0 && (x->compareTo(q) < 0)) {
			return x;
		}
	}
}

$BigInteger* DSAKeyPairGenerator::generateY($BigInteger* x, $BigInteger* p, $BigInteger* g) {
	$var($BigInteger, y, $nc(g)->modPow(x, p));
	return y;
}

DSAKeyPairGenerator::DSAKeyPairGenerator() {
}

$Class* DSAKeyPairGenerator::load$($String* name, bool initialize) {
	$loadClass(DSAKeyPairGenerator, name, initialize, &_DSAKeyPairGenerator_ClassInfo_, allocate$DSAKeyPairGenerator);
	return class$;
}

$Class* DSAKeyPairGenerator::class$ = nullptr;

		} // provider
	} // security
} // sun