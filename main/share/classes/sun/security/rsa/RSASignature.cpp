#include <sun/security/rsa/RSASignature.h>

#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
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
#include <javax/crypto/BadPaddingException.h>
#include <sun/security/rsa/RSACore.h>
#include <sun/security/rsa/RSAKeyFactory.h>
#include <sun/security/rsa/RSAPadding.h>
#include <sun/security/rsa/RSAUtil$KeyType.h>
#include <sun/security/rsa/RSAUtil.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef PAD_BLOCKTYPE_1
#undef RSA

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
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
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $RSACore = ::sun::security::rsa::RSACore;
using $RSAKeyFactory = ::sun::security::rsa::RSAKeyFactory;
using $RSAPadding = ::sun::security::rsa::RSAPadding;
using $RSAUtil = ::sun::security::rsa::RSAUtil;
using $RSAUtil$KeyType = ::sun::security::rsa::RSAUtil$KeyType;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace rsa {

$CompoundAttribute _RSASignature_MethodAnnotations_engineGetParameter3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RSASignature_MethodAnnotations_engineSetParameter8[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RSASignature_FieldInfo_[] = {
	{"baseLength", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSASignature, baseLength)},
	{"digestOID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $FINAL, $field(RSASignature, digestOID)},
	{"encodedLength", "I", nullptr, $PRIVATE | $FINAL, $field(RSASignature, encodedLength)},
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(RSASignature, md)},
	{"digestReset", "Z", nullptr, $PRIVATE, $field(RSASignature, digestReset)},
	{"privateKey", "Ljava/security/interfaces/RSAPrivateKey;", nullptr, $PRIVATE, $field(RSASignature, privateKey)},
	{"publicKey", "Ljava/security/interfaces/RSAPublicKey;", nullptr, $PRIVATE, $field(RSASignature, publicKey)},
	{"padding", "Lsun/security/rsa/RSAPadding;", nullptr, $PRIVATE, $field(RSASignature, padding)},
	{}
};

$MethodInfo _RSASignature_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/security/util/ObjectIdentifier;I)V", nullptr, 0, $method(RSASignature, init$, void, $String*, $ObjectIdentifier*, int32_t)},
	{"decodeSignature", "(Lsun/security/util/ObjectIdentifier;[B)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(RSASignature, decodeSignature, $bytes*, $ObjectIdentifier*, $bytes*), "java.io.IOException"},
	{"encodeSignature", "(Lsun/security/util/ObjectIdentifier;[B)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(RSASignature, encodeSignature, $bytes*, $ObjectIdentifier*, $bytes*), "java.io.IOException"},
	{"engineGetParameter", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(RSASignature, engineGetParameter, $Object*, $String*), "java.security.InvalidParameterException", nullptr, _RSASignature_MethodAnnotations_engineGetParameter3},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineGetParameters, $AlgorithmParameters*)},
	{"engineInitSign", "(Ljava/security/PrivateKey;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineInitSign, void, $PrivateKey*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineInitSign, void, $PrivateKey*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineInitVerify, void, $PublicKey*), "java.security.InvalidKeyException"},
	{"engineSetParameter", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(RSASignature, engineSetParameter, void, $String*, Object$*), "java.security.InvalidParameterException", nullptr, _RSASignature_MethodAnnotations_engineSetParameter8},
	{"engineSetParameter", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineSetParameter, void, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{"engineSign", "()[B", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineSign, $bytes*), "java.security.SignatureException"},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineUpdate, void, int8_t), "java.security.SignatureException"},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineUpdate, void, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineUpdate, void, $ByteBuffer*)},
	{"engineVerify", "([B)Z", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineVerify, bool, $bytes*), "java.security.SignatureException"},
	{"getDigestValue", "()[B", nullptr, $PRIVATE, $method(RSASignature, getDigestValue, $bytes*)},
	{"initCommon", "(Ljava/security/interfaces/RSAKey;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(RSASignature, initCommon, void, $RSAKey*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"resetDigest", "()V", nullptr, $PRIVATE, $method(RSASignature, resetDigest, void)},
	{}
};

$InnerClassInfo _RSASignature_InnerClassesInfo_[] = {
	{"sun.security.rsa.RSASignature$SHA3_512withRSA", "sun.security.rsa.RSASignature", "SHA3_512withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA3_384withRSA", "sun.security.rsa.RSASignature", "SHA3_384withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA3_256withRSA", "sun.security.rsa.RSASignature", "SHA3_256withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA3_224withRSA", "sun.security.rsa.RSASignature", "SHA3_224withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA512_256withRSA", "sun.security.rsa.RSASignature", "SHA512_256withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA512_224withRSA", "sun.security.rsa.RSASignature", "SHA512_224withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA512withRSA", "sun.security.rsa.RSASignature", "SHA512withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA384withRSA", "sun.security.rsa.RSASignature", "SHA384withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA256withRSA", "sun.security.rsa.RSASignature", "SHA256withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA224withRSA", "sun.security.rsa.RSASignature", "SHA224withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$SHA1withRSA", "sun.security.rsa.RSASignature", "SHA1withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$MD5withRSA", "sun.security.rsa.RSASignature", "MD5withRSA", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.rsa.RSASignature$MD2withRSA", "sun.security.rsa.RSASignature", "MD2withRSA", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSASignature_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.rsa.RSASignature",
	"java.security.SignatureSpi",
	nullptr,
	_RSASignature_FieldInfo_,
	_RSASignature_MethodInfo_,
	nullptr,
	nullptr,
	_RSASignature_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.rsa.RSASignature$SHA3_512withRSA,sun.security.rsa.RSASignature$SHA3_384withRSA,sun.security.rsa.RSASignature$SHA3_256withRSA,sun.security.rsa.RSASignature$SHA3_224withRSA,sun.security.rsa.RSASignature$SHA512_256withRSA,sun.security.rsa.RSASignature$SHA512_224withRSA,sun.security.rsa.RSASignature$SHA512withRSA,sun.security.rsa.RSASignature$SHA384withRSA,sun.security.rsa.RSASignature$SHA256withRSA,sun.security.rsa.RSASignature$SHA224withRSA,sun.security.rsa.RSASignature$SHA1withRSA,sun.security.rsa.RSASignature$MD5withRSA,sun.security.rsa.RSASignature$MD2withRSA"
};

$Object* allocate$RSASignature($Class* clazz) {
	return $of($alloc(RSASignature));
}

void RSASignature::init$($String* algorithm, $ObjectIdentifier* digestOID, int32_t oidLength) {
	$SignatureSpi::init$();
	$set(this, digestOID, digestOID);
	try {
		$set(this, md, $MessageDigest::getInstance(algorithm));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	this->digestReset = true;
	this->encodedLength = RSASignature::baseLength + oidLength + $nc(this->md)->getDigestLength();
}

void RSASignature::engineInitVerify($PublicKey* publicKey) {
	$var($RSAPublicKey, rsaKey, $cast($RSAPublicKey, $RSAKeyFactory::toRSAKey(publicKey)));
	$set(this, privateKey, nullptr);
	$set(this, publicKey, rsaKey);
	initCommon(rsaKey, nullptr);
}

void RSASignature::engineInitSign($PrivateKey* privateKey) {
	engineInitSign(privateKey, nullptr);
}

void RSASignature::engineInitSign($PrivateKey* privateKey, $SecureRandom* random) {
	$var($RSAPrivateKey, rsaKey, $cast($RSAPrivateKey, $RSAKeyFactory::toRSAKey(privateKey)));
	$set(this, privateKey, rsaKey);
	$set(this, publicKey, nullptr);
	initCommon(rsaKey, random);
}

void RSASignature::initCommon($RSAKey* rsaKey, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($RSAUtil$KeyType);
		$RSAUtil::checkParamsAgainstType($RSAUtil$KeyType::RSA, $($nc(rsaKey)->getParams()));
	} catch ($ProviderException& e) {
		$throwNew($InvalidKeyException, "Invalid key for RSA signatures"_s, e);
	}
	resetDigest();
	int32_t keySize = $RSACore::getByteLength(rsaKey);
	try {
		$set(this, padding, $RSAPadding::getInstance($RSAPadding::PAD_BLOCKTYPE_1, keySize, random));
	} catch ($InvalidAlgorithmParameterException& iape) {
		$throwNew($InvalidKeyException, $(iape->getMessage()));
	}
	int32_t maxDataSize = $nc(this->padding)->getMaxDataSize();
	if (this->encodedLength > maxDataSize) {
		$throwNew($InvalidKeyException, "Key is too short for this signature algorithm"_s);
	}
}

void RSASignature::resetDigest() {
	if (this->digestReset == false) {
		$nc(this->md)->reset();
		this->digestReset = true;
	}
}

$bytes* RSASignature::getDigestValue() {
	this->digestReset = true;
	return $nc(this->md)->digest();
}

void RSASignature::engineUpdate(int8_t b) {
	$nc(this->md)->update(b);
	this->digestReset = false;
}

void RSASignature::engineUpdate($bytes* b, int32_t off, int32_t len) {
	$nc(this->md)->update(b, off, len);
	this->digestReset = false;
}

void RSASignature::engineUpdate($ByteBuffer* b) {
	$nc(this->md)->update(b);
	this->digestReset = false;
}

$bytes* RSASignature::engineSign() {
	$useLocalCurrentObjectStackCache();
	if (this->privateKey == nullptr) {
		$throwNew($SignatureException, "Missing private key"_s);
	}
	$var($bytes, digest, getDigestValue());
	try {
		$var($bytes, encoded, encodeSignature(this->digestOID, digest));
		$var($bytes, padded, $nc(this->padding)->pad(encoded));
		$var($bytes, encrypted, $RSACore::rsa(padded, this->privateKey, true));
		return encrypted;
	} catch ($GeneralSecurityException& e) {
		$throwNew($SignatureException, "Could not sign data"_s, e);
	} catch ($IOException& e) {
		$throwNew($SignatureException, "Could not encode data"_s, e);
	}
	$shouldNotReachHere();
}

bool RSASignature::engineVerify($bytes* sigBytes) {
	$useLocalCurrentObjectStackCache();
	if (this->publicKey == nullptr) {
		$throwNew($SignatureException, "Missing public key"_s);
	}
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			try {
				if ($nc(sigBytes)->length != $RSACore::getByteLength(static_cast<$RSAKey*>(this->publicKey))) {
					$throwNew($SignatureException, $$str({"Signature length not correct: got "_s, $$str(sigBytes->length), " but was expecting "_s, $$str($RSACore::getByteLength(static_cast<$RSAKey*>(this->publicKey)))}));
				}
				$var($bytes, digest, getDigestValue());
				$var($bytes, decrypted, $RSACore::rsa(sigBytes, this->publicKey));
				$var($bytes, unpadded, $nc(this->padding)->unpad(decrypted));
				$var($bytes, decodedDigest, decodeSignature(this->digestOID, unpadded));
				var$2 = $MessageDigest::isEqual(digest, decodedDigest);
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

$bytes* RSASignature::encodeSignature($ObjectIdentifier* oid, $bytes* digest) {
	$init(RSASignature);
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, out, $new($DerOutputStream));
	$$new($AlgorithmId, oid)->encode(out);
	out->putOctetString(digest);
	$var($DerValue, result, $new($DerValue, $DerValue::tag_Sequence, $(out->toByteArray())));
	return result->toByteArray();
}

$bytes* RSASignature::decodeSignature($ObjectIdentifier* oid, $bytes* sig) {
	$init(RSASignature);
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, in, $new($DerInputStream, sig, 0, $nc(sig)->length, false));
	$var($DerValueArray, values, in->getSequence(2));
	if (($nc(values)->length != 2) || (in->available() != 0)) {
		$throwNew($IOException, "SEQUENCE length error"_s);
	}
	$var($AlgorithmId, algId, $AlgorithmId::parse($nc(values)->get(0)));
	if ($nc($($nc(algId)->getOID()))->equals(oid) == false) {
		$throwNew($IOException, $$str({"ObjectIdentifier mismatch: "_s, $(algId->getOID())}));
	}
	if ($nc(algId)->getEncodedParams() != nullptr) {
		$throwNew($IOException, "Unexpected AlgorithmId parameters"_s);
	}
	$var($bytes, digest, $nc($nc(values)->get(1))->getOctetString());
	return digest;
}

void RSASignature::engineSetParameter($String* param, Object$* value) {
	$throwNew($UnsupportedOperationException, "setParameter() not supported"_s);
}

void RSASignature::engineSetParameter($AlgorithmParameterSpec* params) {
	if (params != nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "No parameters accepted"_s);
	}
}

$Object* RSASignature::engineGetParameter($String* param) {
	$throwNew($UnsupportedOperationException, "getParameter() not supported"_s);
	$shouldNotReachHere();
}

$AlgorithmParameters* RSASignature::engineGetParameters() {
	return nullptr;
}

RSASignature::RSASignature() {
}

$Class* RSASignature::load$($String* name, bool initialize) {
	$loadClass(RSASignature, name, initialize, &_RSASignature_ClassInfo_, allocate$RSASignature);
	return class$;
}

$Class* RSASignature::class$ = nullptr;

		} // rsa
	} // security
} // sun