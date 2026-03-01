#include <sun/security/rsa/RSAPSSSignature.h>

#include <java/io/IOException.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/math/BigInteger.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/SignatureException.h>
#include <java/security/SignatureSpi.h>
#include <java/security/interfaces/RSAKey.h>
#include <java/security/interfaces/RSAPrivateKey.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/MGF1ParameterSpec.h>
#include <java/security/spec/PSSParameterSpec.h>
#include <java/util/Arrays.h>
#include <java/util/Hashtable.h>
#include <javax/crypto/BadPaddingException.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/rsa/MGF1.h>
#include <sun/security/rsa/PSSParameters.h>
#include <sun/security/rsa/RSACore.h>
#include <sun/security/util/KnownOIDs.h>
#include <jcpp.h>

#undef DEBUG
#undef DIGEST_LENGTHS
#undef EIGHT_BYTES_OF_ZEROS
#undef MASK
#undef SHA_1
#undef TRAILER_FIELD_BC

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $BigInteger = ::java::math::BigInteger;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $SignatureException = ::java::security::SignatureException;
using $SignatureSpi = ::java::security::SignatureSpi;
using $RSAKey = ::java::security::interfaces::RSAKey;
using $RSAPrivateKey = ::java::security::interfaces::RSAPrivateKey;
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $MGF1ParameterSpec = ::java::security::spec::MGF1ParameterSpec;
using $PSSParameterSpec = ::java::security::spec::PSSParameterSpec;
using $Arrays = ::java::util::Arrays;
using $Hashtable = ::java::util::Hashtable;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $MGF1 = ::sun::security::rsa::MGF1;
using $PSSParameters = ::sun::security::rsa::PSSParameters;
using $RSACore = ::sun::security::rsa::RSACore;
using $KnownOIDs = ::sun::security::util::KnownOIDs;

namespace sun {
	namespace security {
		namespace rsa {

$CompoundAttribute _RSAPSSSignature_MethodAnnotations_engineGetParameter4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RSAPSSSignature_MethodAnnotations_engineSetParameter9[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RSAPSSSignature_FieldInfo_[] = {
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSAPSSSignature, DEBUG)},
	{"EIGHT_BYTES_OF_ZEROS", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSAPSSSignature, EIGHT_BYTES_OF_ZEROS)},
	{"DIGEST_LENGTHS", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Lsun/security/util/KnownOIDs;Ljava/lang/Integer;>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAPSSSignature, DIGEST_LENGTHS)},
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE, $field(RSAPSSSignature, md)},
	{"digestReset", "Z", nullptr, $PRIVATE, $field(RSAPSSSignature, digestReset)},
	{"privKey", "Ljava/security/interfaces/RSAPrivateKey;", nullptr, $PRIVATE, $field(RSAPSSSignature, privKey)},
	{"pubKey", "Ljava/security/interfaces/RSAPublicKey;", nullptr, $PRIVATE, $field(RSAPSSSignature, pubKey)},
	{"sigParams", "Ljava/security/spec/PSSParameterSpec;", nullptr, $PRIVATE, $field(RSAPSSSignature, sigParams)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(RSAPSSSignature, random)},
	{}
};

$MethodInfo _RSAPSSSignature_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RSAPSSSignature, init$, void)},
	{"checkKeyLength", "(Ljava/security/interfaces/RSAKey;II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAPSSSignature, checkKeyLength, void, $RSAKey*, int32_t, int32_t), "java.security.InvalidKeyException"},
	{"decodeSignature", "([B[B)Z", nullptr, $PRIVATE, $method(RSAPSSSignature, decodeSignature, bool, $bytes*, $bytes*), "java.io.IOException"},
	{"encodeSignature", "([B)[B", nullptr, $PRIVATE, $method(RSAPSSSignature, encodeSignature, $bytes*, $bytes*), "java.io.IOException,java.security.DigestException"},
	{"engineGetParameter", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(RSAPSSSignature, engineGetParameter, $Object*, $String*), "java.security.InvalidParameterException", nullptr, _RSAPSSSignature_MethodAnnotations_engineGetParameter4},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineGetParameters, $AlgorithmParameters*)},
	{"engineInitSign", "(Ljava/security/PrivateKey;)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineInitSign, void, $PrivateKey*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineInitSign, void, $PrivateKey*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineInitVerify, void, $PublicKey*), "java.security.InvalidKeyException"},
	{"engineSetParameter", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(RSAPSSSignature, engineSetParameter, void, $String*, Object$*), "java.security.InvalidParameterException", nullptr, _RSAPSSSignature_MethodAnnotations_engineSetParameter9},
	{"engineSetParameter", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineSetParameter, void, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{"engineSign", "()[B", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineSign, $bytes*), "java.security.SignatureException"},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineUpdate, void, int8_t), "java.security.SignatureException"},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineUpdate, void, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineUpdate, void, $ByteBuffer*)},
	{"engineVerify", "([B)Z", nullptr, $PROTECTED, $virtualMethod(RSAPSSSignature, engineVerify, bool, $bytes*), "java.security.SignatureException"},
	{"ensureInit", "()V", nullptr, $PRIVATE, $method(RSAPSSSignature, ensureInit, void), "java.security.SignatureException"},
	{"getDigestValue", "()[B", nullptr, $PRIVATE, $method(RSAPSSSignature, getDigestValue, $bytes*)},
	{"getKeyLengthInBits", "(Ljava/security/interfaces/RSAKey;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAPSSSignature, getKeyLengthInBits, int32_t, $RSAKey*)},
	{"isCompatible", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/spec/PSSParameterSpec;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAPSSSignature, isCompatible, bool, $AlgorithmParameterSpec*, $PSSParameterSpec*)},
	{"isDigestEqual", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(RSAPSSSignature, isDigestEqual, bool, $String*, $String*)},
	{"isValid", "(Ljava/security/interfaces/RSAKey;)Ljava/security/interfaces/RSAKey;", nullptr, $PRIVATE, $method(RSAPSSSignature, isValid, $RSAKey*, $RSAKey*), "java.security.InvalidKeyException"},
	{"resetDigest", "()V", nullptr, $PRIVATE, $method(RSAPSSSignature, resetDigest, void)},
	{"validateSigParams", "(Ljava/security/spec/AlgorithmParameterSpec;)Ljava/security/spec/PSSParameterSpec;", nullptr, $PRIVATE, $method(RSAPSSSignature, validateSigParams, $PSSParameterSpec*, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{}
};

$ClassInfo _RSAPSSSignature_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.rsa.RSAPSSSignature",
	"java.security.SignatureSpi",
	nullptr,
	_RSAPSSSignature_FieldInfo_,
	_RSAPSSSignature_MethodInfo_
};

$Object* allocate$RSAPSSSignature($Class* clazz) {
	return $of($alloc(RSAPSSSignature));
}

$bytes* RSAPSSSignature::EIGHT_BYTES_OF_ZEROS = nullptr;
$Hashtable* RSAPSSSignature::DIGEST_LENGTHS = nullptr;

bool RSAPSSSignature::isDigestEqual($String* stdAlg, $String* givenAlg$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, givenAlg, givenAlg$renamed);
	if (stdAlg == nullptr || givenAlg == nullptr) {
		return false;
	}
	if ($nc(givenAlg)->indexOf("-"_s) != -1) {
		return $nc(stdAlg)->equalsIgnoreCase(givenAlg);
	} else if ($nc(stdAlg)->equals("SHA-1"_s)) {
		bool var$0 = givenAlg->equalsIgnoreCase("SHA"_s);
		return (var$0 || givenAlg->equalsIgnoreCase("SHA1"_s));
	} else {
		$var($StringBuilder, sb, $new($StringBuilder, givenAlg));
		if (givenAlg->regionMatches(true, 0, "SHA"_s, 0, 3)) {
			$assign(givenAlg, $nc(sb->insert(3, "-"_s))->toString());
			return stdAlg->equalsIgnoreCase(givenAlg);
		} else {
			$throwNew($ProviderException, $$str({"Unsupported digest algorithm "_s, givenAlg}));
		}
	}
}

void RSAPSSSignature::init$() {
	$SignatureSpi::init$();
	this->digestReset = true;
	$set(this, privKey, nullptr);
	$set(this, pubKey, nullptr);
	$set(this, sigParams, nullptr);
	$set(this, md, nullptr);
}

void RSAPSSSignature::engineInitVerify($PublicKey* publicKey) {
	if (!($instanceOf($RSAPublicKey, publicKey))) {
		$throwNew($InvalidKeyException, "key must be RSAPublicKey"_s);
	}
	$set(this, pubKey, $cast($RSAPublicKey, isValid($cast($RSAKey, publicKey))));
	$set(this, privKey, nullptr);
	resetDigest();
}

void RSAPSSSignature::engineInitSign($PrivateKey* privateKey) {
	engineInitSign(privateKey, nullptr);
}

void RSAPSSSignature::engineInitSign($PrivateKey* privateKey, $SecureRandom* random) {
	if (!($instanceOf($RSAPrivateKey, privateKey))) {
		$throwNew($InvalidKeyException, "key must be RSAPrivateKey"_s);
	}
	$set(this, privKey, $cast($RSAPrivateKey, isValid($cast($RSAKey, privateKey))));
	$set(this, pubKey, nullptr);
	$set(this, random, random == nullptr ? $JCAUtil::getSecureRandom() : random);
	resetDigest();
}

bool RSAPSSSignature::isCompatible($AlgorithmParameterSpec* keyParams, $PSSParameterSpec* sigParams) {
	$init(RSAPSSSignature);
	$useLocalCurrentObjectStackCache();
	if (keyParams == nullptr) {
		return true;
	}
	if (!($instanceOf($PSSParameterSpec, keyParams))) {
		return false;
	}
	if (sigParams == nullptr) {
		return true;
	}
	$var($PSSParameterSpec, pssKeyParams, $cast($PSSParameterSpec, keyParams));
	int32_t var$0 = $nc(pssKeyParams)->getSaltLength();
	if (var$0 > $nc(sigParams)->getSaltLength()) {
		return false;
	}
	$var($String, var$1, $nc(pssKeyParams)->getDigestAlgorithm());
	$var($String, var$2, pssKeyParams->getMGFAlgorithm());
	$var($AlgorithmParameterSpec, var$3, pssKeyParams->getMGFParameters());
	int32_t var$4 = $nc(sigParams)->getSaltLength();
	$var($PSSParameterSpec, keyParams2, $new($PSSParameterSpec, var$1, var$2, var$3, var$4, pssKeyParams->getTrailerField()));
	$var($PSSParameters, ap, $new($PSSParameters));
	try {
		ap->engineInit(static_cast<$AlgorithmParameterSpec*>(keyParams2));
		$var($bytes, encoded, ap->engineGetEncoded());
		ap->engineInit(static_cast<$AlgorithmParameterSpec*>(sigParams));
		$var($bytes, encoded2, ap->engineGetEncoded());
		return $Arrays::equals(encoded, encoded2);
	} catch ($Exception& e) {
		return false;
	}
	$shouldNotReachHere();
}

$RSAKey* RSAPSSSignature::isValid($RSAKey* rsaKey) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameterSpec, keyParams, $nc(rsaKey)->getParams());
	if (!isCompatible($(rsaKey->getParams()), this->sigParams)) {
		$throwNew($InvalidKeyException, "Key contains incompatible PSS parameter values"_s);
	}
	if (this->sigParams != nullptr) {
		$var($String, digestAlgo, $nc(this->sigParams)->getDigestAlgorithm());
		$KnownOIDs* ko = $KnownOIDs::findMatch(digestAlgo);
		if (ko != nullptr) {
			$var($Integer, hLen, $cast($Integer, $nc(RSAPSSSignature::DIGEST_LENGTHS)->get(ko)));
			if (hLen != nullptr) {
				$var($RSAKey, var$0, rsaKey);
				int32_t var$1 = hLen->intValue();
				checkKeyLength(var$0, var$1, $nc(this->sigParams)->getSaltLength());
			} else {
				$throwNew($ProviderException, $$str({"Unsupported digest algo: "_s, digestAlgo}));
			}
		} else {
			$throwNew($ProviderException, $$str({"Unrecognized digest algo: "_s, digestAlgo}));
		}
	}
	return rsaKey;
}

$PSSParameterSpec* RSAPSSSignature::validateSigParams($AlgorithmParameterSpec* p) {
	$useLocalCurrentObjectStackCache();
	if (p == nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "Parameters cannot be null"_s);
	}
	if (!($instanceOf($PSSParameterSpec, p))) {
		$throwNew($InvalidAlgorithmParameterException, "parameters must be type PSSParameterSpec"_s);
	}
	$var($PSSParameterSpec, params, $cast($PSSParameterSpec, p));
	if (params == this->sigParams) {
		return params;
	}
	$var($RSAKey, key, this->privKey == nullptr ? static_cast<$RSAKey*>(this->pubKey) : static_cast<$RSAKey*>(this->privKey));
	if (key != nullptr) {
		if (!isCompatible($(key->getParams()), params)) {
			$throwNew($InvalidAlgorithmParameterException, "Signature parameters does not match key parameters"_s);
		}
	}
	if (!($nc($($nc(params)->getMGFAlgorithm()))->equalsIgnoreCase("MGF1"_s))) {
		$throwNew($InvalidAlgorithmParameterException, "Only supports MGF1"_s);
	}
	if ($nc(params)->getTrailerField() != $PSSParameterSpec::TRAILER_FIELD_BC) {
		$throwNew($InvalidAlgorithmParameterException, "Only supports TrailerFieldBC(1)"_s);
	}
	if (key != nullptr) {
		$var($String, digestAlgo, $nc(params)->getDigestAlgorithm());
		$KnownOIDs* ko = $KnownOIDs::findMatch(digestAlgo);
		if (ko != nullptr) {
			$var($Integer, hLen, $cast($Integer, $nc(RSAPSSSignature::DIGEST_LENGTHS)->get(ko)));
			if (hLen != nullptr) {
				try {
					$var($RSAKey, var$0, key);
					int32_t var$1 = hLen->intValue();
					checkKeyLength(var$0, var$1, params->getSaltLength());
				} catch ($InvalidKeyException& e) {
					$throwNew($InvalidAlgorithmParameterException, static_cast<$Throwable*>(e));
				}
			} else {
				$throwNew($InvalidAlgorithmParameterException, $$str({"Unsupported digest algo: "_s, digestAlgo}));
			}
		} else {
			$throwNew($InvalidAlgorithmParameterException, $$str({"Unrecognized digest algo: "_s, digestAlgo}));
		}
	}
	return params;
}

void RSAPSSSignature::ensureInit() {
	$var($RSAKey, key, this->privKey == nullptr ? static_cast<$RSAKey*>(this->pubKey) : static_cast<$RSAKey*>(this->privKey));
	if (key == nullptr) {
		$throwNew($SignatureException, "Missing key"_s);
	}
	if (this->sigParams == nullptr) {
		$throwNew($SignatureException, "Parameters required for RSASSA-PSS signatures"_s);
	}
}

void RSAPSSSignature::checkKeyLength($RSAKey* key, int32_t digestLen, int32_t saltLen) {
	$init(RSAPSSSignature);
	$useLocalCurrentObjectStackCache();
	if (key != nullptr) {
		int32_t keyLength = (getKeyLengthInBits(key) + 7) >> 3;
		int32_t minLength = $Math::addExact($Math::addExact(digestLen, saltLen), 2);
		if (keyLength < minLength) {
			$throwNew($InvalidKeyException, $$str({"Key is too short, need min "_s, $$str(minLength), " bytes"_s}));
		}
	}
}

void RSAPSSSignature::resetDigest() {
	if (this->digestReset == false) {
		$nc(this->md)->reset();
		this->digestReset = true;
	}
}

$bytes* RSAPSSSignature::getDigestValue() {
	this->digestReset = true;
	return $nc(this->md)->digest();
}

void RSAPSSSignature::engineUpdate(int8_t b) {
	ensureInit();
	$nc(this->md)->update(b);
	this->digestReset = false;
}

void RSAPSSSignature::engineUpdate($bytes* b, int32_t off, int32_t len) {
	ensureInit();
	$nc(this->md)->update(b, off, len);
	this->digestReset = false;
}

void RSAPSSSignature::engineUpdate($ByteBuffer* b) {
	try {
		ensureInit();
	} catch ($SignatureException& se) {
		$throwNew($RuntimeException, $(se->getMessage()));
	}
	$nc(this->md)->update(b);
	this->digestReset = false;
}

$bytes* RSAPSSSignature::engineSign() {
	$useLocalCurrentObjectStackCache();
	ensureInit();
	$var($bytes, mHash, getDigestValue());
	try {
		$var($bytes, encoded, encodeSignature(mHash));
		$var($bytes, encrypted, $RSACore::rsa(encoded, this->privKey, true));
		return encrypted;
	} catch ($GeneralSecurityException& e) {
		$throwNew($SignatureException, "Could not sign data"_s, e);
	} catch ($IOException& e) {
		$throwNew($SignatureException, "Could not encode data"_s, e);
	}
	$shouldNotReachHere();
}

bool RSAPSSSignature::engineVerify($bytes* sigBytes) {
	$useLocalCurrentObjectStackCache();
	ensureInit();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			try {
				if ($nc(sigBytes)->length != $RSACore::getByteLength(static_cast<$RSAKey*>(this->pubKey))) {
					$throwNew($SignatureException, $$str({"Signature length not correct: got "_s, $$str(sigBytes->length), " but was expecting "_s, $$str($RSACore::getByteLength(static_cast<$RSAKey*>(this->pubKey)))}));
				}
				$var($bytes, mHash, getDigestValue());
				$var($bytes, decrypted, $RSACore::rsa(sigBytes, this->pubKey));
				var$2 = decodeSignature(mHash, decrypted);
				return$1 = true;
				goto $finally;
			} catch ($BadPaddingException& e) {
				var$2 = false;
				return$1 = true;
				goto $finally;
			} catch ($IOException& e) {
				$throwNew($SignatureException, "Signature encoding error"_s, e);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			resetDigest();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

int32_t RSAPSSSignature::getKeyLengthInBits($RSAKey* k) {
	$init(RSAPSSSignature);
	if (k != nullptr) {
		return $nc($(k->getModulus()))->bitLength();
	}
	return -1;
}

$bytes* RSAPSSSignature::encodeSignature($bytes* mHash) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameterSpec, mgfParams, $nc(this->sigParams)->getMGFParameters());
	$var($String, mgfDigestAlgo, nullptr);
	if (mgfParams != nullptr) {
		$assign(mgfDigestAlgo, $nc(($cast($MGF1ParameterSpec, mgfParams)))->getDigestAlgorithm());
	} else {
		$assign(mgfDigestAlgo, $nc(this->md)->getAlgorithm());
	}
	try {
		int32_t emBits = getKeyLengthInBits(this->privKey) - 1;
		int32_t emLen = (emBits + 7) >> 3;
		int32_t hLen = $nc(this->md)->getDigestLength();
		int32_t dbLen = emLen - hLen - 1;
		int32_t sLen = $nc(this->sigParams)->getSaltLength();
		$var($bytes, em, $new($bytes, emLen));
		em->set(dbLen - sLen - 1, (int8_t)1);
		em->set(em->length - 1, (int8_t)188);
		if (!this->digestReset) {
			$throwNew($ProviderException, "Digest should be reset"_s);
		}
		$nc(this->md)->update(RSAPSSSignature::EIGHT_BYTES_OF_ZEROS);
		this->digestReset = false;
		$nc(this->md)->update(mHash);
		if (sLen != 0) {
			$var($bytes, salt, $new($bytes, sLen));
			$nc(this->random)->nextBytes(salt);
			$nc(this->md)->update(salt);
			$System::arraycopy(salt, 0, em, dbLen - sLen, sLen);
		}
		$nc(this->md)->digest(em, dbLen, hLen);
		this->digestReset = true;
		$var($MGF1, mgf1, $new($MGF1, mgfDigestAlgo));
		mgf1->generateAndXor(em, dbLen, hLen, dbLen, em, 0);
		int32_t numZeroBits = (emLen << 3) - emBits;
		if (numZeroBits != 0) {
			int8_t MASK = (int8_t)($usr(255, numZeroBits));
			em->set(0, (int8_t)((int32_t)(em->get(0) & (uint32_t)(int32_t)MASK)));
		}
		return em;
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($IOException, $(e->toString()));
	}
	$shouldNotReachHere();
}

bool RSAPSSSignature::decodeSignature($bytes* mHash, $bytes* em) {
	$useLocalCurrentObjectStackCache();
	int32_t hLen = $nc(mHash)->length;
	int32_t sLen = $nc(this->sigParams)->getSaltLength();
	int32_t emBits = getKeyLengthInBits(this->pubKey) - 1;
	int32_t emLen = (emBits + 7) >> 3;
	int32_t emOfs = $nc(em)->length - emLen;
	if ((emOfs == 1) && (em->get(0) != 0)) {
		return false;
	}
	if (emLen < (hLen + sLen + 2)) {
		return false;
	}
	if (em->get(emOfs + emLen - 1) != (int8_t)188) {
		return false;
	}
	int32_t numZeroBits = (emLen << 3) - emBits;
	if (numZeroBits != 0) {
		int8_t MASK = (int8_t)($sl(255, 8 - numZeroBits));
		if (((int32_t)(em->get(emOfs) & (uint32_t)(int32_t)MASK)) != 0) {
			return false;
		}
	}
	$var($String, mgfDigestAlgo, nullptr);
	$var($AlgorithmParameterSpec, mgfParams, $nc(this->sigParams)->getMGFParameters());
	if (mgfParams != nullptr) {
		$assign(mgfDigestAlgo, $nc(($cast($MGF1ParameterSpec, mgfParams)))->getDigestAlgorithm());
	} else {
		$assign(mgfDigestAlgo, $nc(this->md)->getAlgorithm());
	}
	int32_t dbLen = emLen - hLen - 1;
	try {
		$var($MGF1, mgf1, $new($MGF1, mgfDigestAlgo));
		mgf1->generateAndXor(em, emOfs + dbLen, hLen, dbLen, em, emOfs);
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($IOException, $(nsae->toString()));
	}
	if (numZeroBits != 0) {
		int8_t MASK = (int8_t)($usr(255, numZeroBits));
		em->set(emOfs, (int8_t)((int32_t)(em->get(emOfs) & (uint32_t)(int32_t)MASK)));
	}
	int32_t i = emOfs;
	for (; i < emOfs + (dbLen - sLen - 1); ++i) {
		if (em->get(i) != 0) {
			return false;
		}
	}
	if (em->get(i) != 1) {
		return false;
	}
	$nc(this->md)->update(RSAPSSSignature::EIGHT_BYTES_OF_ZEROS);
	this->digestReset = false;
	$nc(this->md)->update(mHash);
	if (sLen > 0) {
		$nc(this->md)->update(em, emOfs + (dbLen - sLen), sLen);
	}
	$var($bytes, digest2, $nc(this->md)->digest());
	this->digestReset = true;
	$var($bytes, digestInEM, $Arrays::copyOfRange(em, emOfs + dbLen, emOfs + emLen - 1));
	return $MessageDigest::isEqual(digest2, digestInEM);
}

void RSAPSSSignature::engineSetParameter($String* param, Object$* value) {
	$throwNew($UnsupportedOperationException, "setParameter() not supported"_s);
}

void RSAPSSSignature::engineSetParameter($AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	$set(this, sigParams, validateSigParams(params));
	if (!this->digestReset) {
		$throwNew($ProviderException, "Cannot set parameters during operations"_s);
	}
	$var($String, newHashAlg, $nc(this->sigParams)->getDigestAlgorithm());
	if ((this->md == nullptr) || !($nc($($nc(this->md)->getAlgorithm()))->equalsIgnoreCase(newHashAlg))) {
		try {
			$set(this, md, $MessageDigest::getInstance(newHashAlg));
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($InvalidAlgorithmParameterException, $$str({"Unsupported digest algorithm "_s, newHashAlg}), nsae);
		}
	}
}

$Object* RSAPSSSignature::engineGetParameter($String* param) {
	$throwNew($UnsupportedOperationException, "getParameter() not supported"_s);
	$shouldNotReachHere();
}

$AlgorithmParameters* RSAPSSSignature::engineGetParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, ap, nullptr);
	if (this->sigParams != nullptr) {
		try {
			$assign(ap, $AlgorithmParameters::getInstance("RSASSA-PSS"_s));
			$nc(ap)->init(static_cast<$AlgorithmParameterSpec*>(this->sigParams));
		} catch ($GeneralSecurityException& gse) {
			$throwNew($ProviderException, $(gse->getMessage()));
		}
	}
	return ap;
}

void clinit$RSAPSSSignature($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(RSAPSSSignature::EIGHT_BYTES_OF_ZEROS, $new($bytes, 8));
	$assignStatic(RSAPSSSignature::DIGEST_LENGTHS, $new($Hashtable));
	{
		$init($KnownOIDs);
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_1, $($Integer::valueOf(20)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_224, $($Integer::valueOf(28)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_256, $($Integer::valueOf(32)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_384, $($Integer::valueOf(48)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_512, $($Integer::valueOf(64)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_512$224, $($Integer::valueOf(28)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA_512$256, $($Integer::valueOf(32)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA3_224, $($Integer::valueOf(28)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA3_256, $($Integer::valueOf(32)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA3_384, $($Integer::valueOf(48)));
		$nc(RSAPSSSignature::DIGEST_LENGTHS)->put($KnownOIDs::SHA3_512, $($Integer::valueOf(64)));
	}
}

RSAPSSSignature::RSAPSSSignature() {
}

$Class* RSAPSSSignature::load$($String* name, bool initialize) {
	$loadClass(RSAPSSSignature, name, initialize, &_RSAPSSSignature_ClassInfo_, clinit$RSAPSSSignature, allocate$RSAPSSSignature);
	return class$;
}

$Class* RSAPSSSignature::class$ = nullptr;

		} // rsa
	} // security
} // sun