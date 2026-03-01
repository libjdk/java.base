#include <sun/security/provider/DSA.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/MessageDigest.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/SignatureException.h>
#include <java/security/SignatureSpi.h>
#include <java/security/interfaces/DSAParams.h>
#include <java/security/interfaces/DSAPrivateKey.h>
#include <java/security/interfaces/DSAPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <java/util/Random.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef BLINDING_BITS
#undef BLINDING_CONSTANT
#undef DSA
#undef ONE

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $MessageDigest = ::java::security::MessageDigest;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $SignatureException = ::java::security::SignatureException;
using $SignatureSpi = ::java::security::SignatureSpi;
using $DSAParams = ::java::security::interfaces::DSAParams;
using $DSAPrivateKey = ::java::security::interfaces::DSAPrivateKey;
using $DSAPublicKey = ::java::security::interfaces::DSAPublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $Random = ::java::util::Random;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace provider {

$CompoundAttribute _DSA_MethodAnnotations_engineGetParameter3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _DSA_MethodAnnotations_engineSetParameter7[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _DSA_FieldInfo_[] = {
	{"debug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DSA, debug)},
	{"BLINDING_BITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DSA, BLINDING_BITS)},
	{"BLINDING_CONSTANT", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DSA, BLINDING_CONSTANT)},
	{"params", "Ljava/security/interfaces/DSAParams;", nullptr, $PRIVATE, $field(DSA, params)},
	{"presetP", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DSA, presetP)},
	{"presetQ", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DSA, presetQ)},
	{"presetG", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DSA, presetG)},
	{"presetY", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DSA, presetY)},
	{"presetX", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DSA, presetX)},
	{"signingRandom", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(DSA, signingRandom)},
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(DSA, md)},
	{"p1363Format", "Z", nullptr, $PRIVATE | $FINAL, $field(DSA, p1363Format)},
	{}
};

$MethodInfo _DSA_MethodInfo_[] = {
	{"<init>", "(Ljava/security/MessageDigest;)V", nullptr, 0, $method(DSA, init$, void, $MessageDigest*)},
	{"<init>", "(Ljava/security/MessageDigest;Z)V", nullptr, 0, $method(DSA, init$, void, $MessageDigest*, bool)},
	{"checkKey", "(Ljava/security/interfaces/DSAParams;ILjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(DSA, checkKey, void, $DSAParams*, int32_t, $String*), "java.security.InvalidKeyException"},
	{"engineGetParameter", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(DSA, engineGetParameter, $Object*, $String*), nullptr, nullptr, _DSA_MethodAnnotations_engineGetParameter3},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(DSA, engineGetParameters, $AlgorithmParameters*)},
	{"engineInitSign", "(Ljava/security/PrivateKey;)V", nullptr, $PROTECTED, $virtualMethod(DSA, engineInitSign, void, $PrivateKey*), "java.security.InvalidKeyException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;)V", nullptr, $PROTECTED, $virtualMethod(DSA, engineInitVerify, void, $PublicKey*), "java.security.InvalidKeyException"},
	{"engineSetParameter", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(DSA, engineSetParameter, void, $String*, Object$*), nullptr, nullptr, _DSA_MethodAnnotations_engineSetParameter7},
	{"engineSetParameter", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(DSA, engineSetParameter, void, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{"engineSign", "()[B", nullptr, $PROTECTED, $virtualMethod(DSA, engineSign, $bytes*), "java.security.SignatureException"},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED, $virtualMethod(DSA, engineUpdate, void, int8_t)},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED, $virtualMethod(DSA, engineUpdate, void, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(DSA, engineUpdate, void, $ByteBuffer*)},
	{"engineVerify", "([B)Z", nullptr, $PROTECTED, $virtualMethod(DSA, engineVerify, bool, $bytes*), "java.security.SignatureException"},
	{"engineVerify", "([BII)Z", nullptr, $PROTECTED, $virtualMethod(DSA, engineVerify, bool, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"generateK", "(Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PROTECTED, $virtualMethod(DSA, generateK, $BigInteger*, $BigInteger*)},
	{"generateR", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(DSA, generateR, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*)},
	{"generateS", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(DSA, generateS, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*), "java.security.SignatureException"},
	{"generateV", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(DSA, generateV, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*), "java.security.SignatureException"},
	{"generateW", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(DSA, generateW, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*)},
	{"getSigningRandom", "()Ljava/security/SecureRandom;", nullptr, $PROTECTED, $virtualMethod(DSA, getSigningRandom, $SecureRandom*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DSA, toString, $String*)},
	{}
};

$InnerClassInfo _DSA_InnerClassesInfo_[] = {
	{"sun.security.provider.DSA$RawDSAinP1363Format", "sun.security.provider.DSA", "RawDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$RawDSA", "sun.security.provider.DSA", "RawDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$Raw", "sun.security.provider.DSA", "Raw", $STATIC},
	{"sun.security.provider.DSA$SHA1withDSAinP1363Format", "sun.security.provider.DSA", "SHA1withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA1withDSA", "sun.security.provider.DSA", "SHA1withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA512withDSAinP1363Format", "sun.security.provider.DSA", "SHA512withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA512withDSA", "sun.security.provider.DSA", "SHA512withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA384withDSAinP1363Format", "sun.security.provider.DSA", "SHA384withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA384withDSA", "sun.security.provider.DSA", "SHA384withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA256withDSAinP1363Format", "sun.security.provider.DSA", "SHA256withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA256withDSA", "sun.security.provider.DSA", "SHA256withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA224withDSAinP1363Format", "sun.security.provider.DSA", "SHA224withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA224withDSA", "sun.security.provider.DSA", "SHA224withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_512withDSAinP1363Format", "sun.security.provider.DSA", "SHA3_512withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_512withDSA", "sun.security.provider.DSA", "SHA3_512withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_384withDSAinP1363Format", "sun.security.provider.DSA", "SHA3_384withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_384withDSA", "sun.security.provider.DSA", "SHA3_384withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_256withDSAinP1363Format", "sun.security.provider.DSA", "SHA3_256withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_256withDSA", "sun.security.provider.DSA", "SHA3_256withDSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_224withDSAinP1363Format", "sun.security.provider.DSA", "SHA3_224withDSAinP1363Format", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DSA$SHA3_224withDSA", "sun.security.provider.DSA", "SHA3_224withDSA", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _DSA_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.provider.DSA",
	"java.security.SignatureSpi",
	nullptr,
	_DSA_FieldInfo_,
	_DSA_MethodInfo_,
	nullptr,
	nullptr,
	_DSA_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.DSA$RawDSAinP1363Format,sun.security.provider.DSA$RawDSA,sun.security.provider.DSA$Raw,sun.security.provider.DSA$Raw$NullDigest20,sun.security.provider.DSA$SHA1withDSAinP1363Format,sun.security.provider.DSA$SHA1withDSA,sun.security.provider.DSA$SHA512withDSAinP1363Format,sun.security.provider.DSA$SHA512withDSA,sun.security.provider.DSA$SHA384withDSAinP1363Format,sun.security.provider.DSA$SHA384withDSA,sun.security.provider.DSA$SHA256withDSAinP1363Format,sun.security.provider.DSA$SHA256withDSA,sun.security.provider.DSA$SHA224withDSAinP1363Format,sun.security.provider.DSA$SHA224withDSA,sun.security.provider.DSA$SHA3_512withDSAinP1363Format,sun.security.provider.DSA$SHA3_512withDSA,sun.security.provider.DSA$SHA3_384withDSAinP1363Format,sun.security.provider.DSA$SHA3_384withDSA,sun.security.provider.DSA$SHA3_256withDSAinP1363Format,sun.security.provider.DSA$SHA3_256withDSA,sun.security.provider.DSA$SHA3_224withDSAinP1363Format,sun.security.provider.DSA$SHA3_224withDSA"
};

$Object* allocate$DSA($Class* clazz) {
	return $of($alloc(DSA));
}

$BigInteger* DSA::BLINDING_CONSTANT = nullptr;

void DSA::init$($MessageDigest* md) {
	DSA::init$(md, false);
}

void DSA::init$($MessageDigest* md, bool p1363Format) {
	$SignatureSpi::init$();
	$set(this, md, md);
	this->p1363Format = p1363Format;
}

void DSA::checkKey($DSAParams* params, int32_t digestLen, $String* mdAlgo) {
	$init(DSA);
	$useLocalCurrentObjectStackCache();
	int32_t valueN = $nc($($nc(params)->getQ()))->bitLength();
	if (valueN > digestLen) {
		$throwNew($InvalidKeyException, $$str({"The security strength of "_s, mdAlgo, " digest algorithm is not sufficient for this key size"_s}));
	}
}

void DSA::engineInitSign($PrivateKey* privateKey) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($DSAPrivateKey, privateKey))) {
		$throwNew($InvalidKeyException, $$str({"not a DSA private key: "_s, privateKey}));
	}
	$var($DSAPrivateKey, priv, $cast($DSAPrivateKey, privateKey));
	$var($DSAParams, params, $nc(priv)->getParams());
	if (params == nullptr) {
		$throwNew($InvalidKeyException, "DSA private key lacks parameters"_s);
	}
	if (!"NullDigest20"_s->equals($($nc(this->md)->getAlgorithm()))) {
		$var($DSAParams, var$0, params);
		int32_t var$1 = $nc(this->md)->getDigestLength() * 8;
		checkKey(var$0, var$1, $($nc(this->md)->getAlgorithm()));
	}
	$set(this, params, params);
	$set(this, presetX, priv->getX());
	$set(this, presetY, nullptr);
	$set(this, presetP, $nc(params)->getP());
	$set(this, presetQ, params->getQ());
	$set(this, presetG, params->getG());
	$nc(this->md)->reset();
}

void DSA::engineInitVerify($PublicKey* publicKey) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($DSAPublicKey, publicKey))) {
		$throwNew($InvalidKeyException, $$str({"not a DSA public key: "_s, publicKey}));
	}
	$var($DSAPublicKey, pub, $cast($DSAPublicKey, publicKey));
	$var($DSAParams, params, $nc(pub)->getParams());
	if (params == nullptr) {
		$throwNew($InvalidKeyException, "DSA public key lacks parameters"_s);
	}
	$set(this, params, params);
	$set(this, presetY, pub->getY());
	$set(this, presetX, nullptr);
	$set(this, presetP, $nc(params)->getP());
	$set(this, presetQ, params->getQ());
	$set(this, presetG, params->getG());
	$nc(this->md)->reset();
}

void DSA::engineUpdate(int8_t b) {
	$nc(this->md)->update(b);
}

void DSA::engineUpdate($bytes* data, int32_t off, int32_t len) {
	$nc(this->md)->update(data, off, len);
}

void DSA::engineUpdate($ByteBuffer* b) {
	$nc(this->md)->update(b);
}

$bytes* DSA::engineSign() {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, k, generateK(this->presetQ));
	$var($BigInteger, r, generateR(this->presetP, this->presetQ, this->presetG, k));
	$var($BigInteger, s, generateS(this->presetX, this->presetQ, r, k));
	if (this->p1363Format) {
		$var($bytes, rBytes, $nc(r)->toByteArray());
		$var($bytes, sBytes, $nc(s)->toByteArray());
		int32_t size = $nc(this->presetQ)->bitLength() / 8;
		$var($bytes, outseq, $new($bytes, size * 2));
		int32_t rLength = $nc(rBytes)->length;
		int32_t sLength = $nc(sBytes)->length;
		int32_t i = 0;
		for (i = rLength; i > 0 && rBytes->get(rLength - i) == 0; --i) {
		}
		int32_t j = 0;
		for (j = sLength; j > 0 && sBytes->get(sLength - j) == 0; --j) {
		}
		$System::arraycopy(rBytes, rLength - i, outseq, size - i, i);
		$System::arraycopy(sBytes, sLength - j, outseq, size * 2 - j, j);
		return outseq;
	} else {
		try {
			$var($DerOutputStream, outseq, $new($DerOutputStream, 100));
			outseq->putInteger(r);
			outseq->putInteger(s);
			$var($DerValue, result, $new($DerValue, $DerValue::tag_Sequence, $(outseq->toByteArray())));
			return result->toByteArray();
		} catch ($IOException& e) {
			$throwNew($SignatureException, "error encoding signature"_s);
		}
	}
	$shouldNotReachHere();
}

bool DSA::engineVerify($bytes* signature) {
	return engineVerify(signature, 0, $nc(signature)->length);
}

bool DSA::engineVerify($bytes* signature, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, r, nullptr);
	$var($BigInteger, s, nullptr);
	if (this->p1363Format) {
		if (((int32_t)(length & (uint32_t)1)) == 1) {
			$throwNew($SignatureException, "invalid signature format"_s);
		}
		int32_t mid = length / 2;
		$assign(r, $new($BigInteger, $($Arrays::copyOfRange(signature, 0, mid))));
		$assign(s, $new($BigInteger, $($Arrays::copyOfRange(signature, mid, length))));
	} else {
		try {
			$var($DerInputStream, in, $new($DerInputStream, signature, offset, length, false));
			$var($DerValueArray, values, in->getSequence(2));
			if (($nc(values)->length != 2) || (in->available() != 0)) {
				$throwNew($IOException, "Invalid encoding for signature"_s);
			}
			$assign(r, $nc($nc(values)->get(0))->getBigInteger());
			$assign(s, $nc(values->get(1))->getBigInteger());
		} catch ($IOException& e) {
			$throwNew($SignatureException, "Invalid encoding for signature"_s, e);
		}
	}
	if ($nc(r)->signum() < 0) {
		$assign(r, $new($BigInteger, 1, $(r->toByteArray())));
	}
	if ($nc(s)->signum() < 0) {
		$assign(s, $new($BigInteger, 1, $(s->toByteArray())));
	}
	bool var$0 = ($nc(r)->compareTo(this->presetQ) == -1);
	if (var$0 && ($nc(s)->compareTo(this->presetQ) == -1)) {
		$var($BigInteger, w, generateW(this->presetP, this->presetQ, this->presetG, s));
		$var($BigInteger, v, generateV(this->presetY, this->presetP, this->presetQ, this->presetG, w, r));
		return $nc(v)->equals(r);
	} else {
		$throwNew($SignatureException, "invalid signature: out of range values"_s);
	}
}

void DSA::engineSetParameter($String* key, Object$* param) {
	$throwNew($InvalidParameterException, "No parameter accepted"_s);
}

void DSA::engineSetParameter($AlgorithmParameterSpec* params) {
	if (params != nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "No parameter accepted"_s);
	}
}

$Object* DSA::engineGetParameter($String* key) {
	return $of(nullptr);
}

$AlgorithmParameters* DSA::engineGetParameters() {
	return nullptr;
}

$BigInteger* DSA::generateR($BigInteger* p, $BigInteger* q, $BigInteger* g, $BigInteger* k$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, k, k$renamed);
	$var($SecureRandom, random, getSigningRandom());
	$var($BigInteger, blindingValue, $new($BigInteger, DSA::BLINDING_BITS, static_cast<$Random*>(random)));
	$assign(blindingValue, blindingValue->add(DSA::BLINDING_CONSTANT));
	$assign(k, $nc(k)->add($($nc(q)->multiply(blindingValue))));
	$var($BigInteger, temp, $nc(g)->modPow(k, p));
	return $nc(temp)->mod(q);
}

$BigInteger* DSA::generateS($BigInteger* x, $BigInteger* q, $BigInteger* r, $BigInteger* k) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, s2, nullptr);
	try {
		$assign(s2, $nc(this->md)->digest());
	} catch ($RuntimeException& re) {
		$throwNew($SignatureException, $(re->getMessage()));
	}
	int32_t nBytes = $nc(q)->bitLength() / 8;
	if (nBytes < $nc(s2)->length) {
		$assign(s2, $Arrays::copyOfRange(s2, 0, nBytes));
	}
	$var($BigInteger, z, $new($BigInteger, 1, s2));
	$var($BigInteger, k1, $nc(k)->modInverse(q));
	return $nc($($nc($($nc($($nc(x)->multiply(r)))->add(z)))->multiply(k1)))->mod(q);
}

$BigInteger* DSA::generateW($BigInteger* p, $BigInteger* q, $BigInteger* g, $BigInteger* s) {
	return $nc(s)->modInverse(q);
}

$BigInteger* DSA::generateV($BigInteger* y, $BigInteger* p, $BigInteger* q, $BigInteger* g, $BigInteger* w, $BigInteger* r) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, s2, nullptr);
	try {
		$assign(s2, $nc(this->md)->digest());
	} catch ($RuntimeException& re) {
		$throwNew($SignatureException, $(re->getMessage()));
	}
	int32_t nBytes = $nc(q)->bitLength() / 8;
	if (nBytes < $nc(s2)->length) {
		$assign(s2, $Arrays::copyOfRange(s2, 0, nBytes));
	}
	$var($BigInteger, z, $new($BigInteger, 1, s2));
	$var($BigInteger, u1, $nc($(z->multiply(w)))->mod(q));
	$var($BigInteger, u2, $nc(($($nc(r)->multiply(w))))->mod(q));
	$var($BigInteger, t1, $nc(g)->modPow(u1, p));
	$var($BigInteger, t2, $nc(y)->modPow(u2, p));
	$var($BigInteger, t3, $nc(t1)->multiply(t2));
	$var($BigInteger, t5, $nc(t3)->mod(p));
	return $nc(t5)->mod(q);
}

$BigInteger* DSA::generateK($BigInteger* q) {
	$useLocalCurrentObjectStackCache();
	$var($SecureRandom, random, getSigningRandom());
	$var($bytes, kValue, $new($bytes, ($nc(q)->bitLength() + 7) / 8 + 8));
	$nc(random)->nextBytes(kValue);
	return $nc($($$new($BigInteger, 1, kValue)->mod($(q->subtract($BigInteger::ONE)))))->add($BigInteger::ONE);
}

$SecureRandom* DSA::getSigningRandom() {
	if (this->signingRandom == nullptr) {
		if (this->appRandom != nullptr) {
			$set(this, signingRandom, this->appRandom);
		} else {
			$set(this, signingRandom, $JCAUtil::getSecureRandom());
		}
	}
	return this->signingRandom;
}

$String* DSA::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, printable, "DSA Signature"_s);
	if (this->presetP != nullptr && this->presetQ != nullptr && this->presetG != nullptr) {
		$plusAssign(printable, $$str({"\n\tp: "_s, $($Debug::toHexString(this->presetP))}));
		$plusAssign(printable, $$str({"\n\tq: "_s, $($Debug::toHexString(this->presetQ))}));
		$plusAssign(printable, $$str({"\n\tg: "_s, $($Debug::toHexString(this->presetG))}));
	} else {
		$plusAssign(printable, "\n\t P, Q or G not initialized."_s);
	}
	if (this->presetY != nullptr) {
		$plusAssign(printable, $$str({"\n\ty: "_s, $($Debug::toHexString(this->presetY))}));
	}
	if (this->presetY == nullptr && this->presetX == nullptr) {
		$plusAssign(printable, "\n\tUNINIIALIZED"_s);
	}
	return printable;
}

void clinit$DSA($Class* class$) {
	$assignStatic(DSA::BLINDING_CONSTANT, $BigInteger::valueOf((int64_t)$sl(1, DSA::BLINDING_BITS)));
}

DSA::DSA() {
}

$Class* DSA::load$($String* name, bool initialize) {
	$loadClass(DSA, name, initialize, &_DSA_ClassInfo_, clinit$DSA, allocate$DSA);
	return class$;
}

$Class* DSA::class$ = nullptr;

		} // provider
	} // security
} // sun