#include <sun/security/ssl/RSASignature.h>

#include <java/security/AlgorithmParameters.h>
#include <java/security/DigestException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/MessageDigest.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/SignatureSpi.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <sun/security/ssl/JsseJce.h>
#include <jcpp.h>

#undef SIGNATURE_RAWRSA
#undef SIGNATURE_SSLRSA

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $DigestException = ::java::security::DigestException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $MessageDigest = ::java::security::MessageDigest;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $SignatureSpi = ::java::security::SignatureSpi;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $JsseJce = ::sun::security::ssl::JsseJce;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _RSASignature_FieldInfo_[] = {
	{"rawRsa", "Ljava/security/Signature;", nullptr, $PRIVATE | $FINAL, $field(RSASignature, rawRsa)},
	{"mdMD5", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(RSASignature, mdMD5)},
	{"mdSHA", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(RSASignature, mdSHA)},
	{}
};

$MethodInfo _RSASignature_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RSASignature, init$, void), "java.security.NoSuchAlgorithmException"},
	{"engineGetParameter", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineGetParameter, $Object*, $String*), "java.security.InvalidParameterException"},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineGetParameters, $AlgorithmParameters*)},
	{"engineInitSign", "(Ljava/security/PrivateKey;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineInitSign, void, $PrivateKey*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineInitSign, void, $PrivateKey*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineInitVerify, void, $PublicKey*), "java.security.InvalidKeyException"},
	{"engineSetParameter", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineSetParameter, void, $String*, Object$*), "java.security.InvalidParameterException"},
	{"engineSetParameter", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineSetParameter, void, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{"engineSign", "()[B", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineSign, $bytes*), "java.security.SignatureException"},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineUpdate, void, int8_t)},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineUpdate, void, $bytes*, int32_t, int32_t)},
	{"engineVerify", "([B)Z", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineVerify, bool, $bytes*), "java.security.SignatureException"},
	{"engineVerify", "([BII)Z", nullptr, $PROTECTED, $virtualMethod(RSASignature, engineVerify, bool, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"getDigest", "()[B", nullptr, $PRIVATE, $method(RSASignature, getDigest, $bytes*), "java.security.SignatureException"},
	{"getInstance", "()Ljava/security/Signature;", nullptr, $STATIC, $staticMethod(RSASignature, getInstance, $Signature*), "java.security.NoSuchAlgorithmException"},
	{}
};

$ClassInfo _RSASignature_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.ssl.RSASignature",
	"java.security.SignatureSpi",
	nullptr,
	_RSASignature_FieldInfo_,
	_RSASignature_MethodInfo_
};

$Object* allocate$RSASignature($Class* clazz) {
	return $of($alloc(RSASignature));
}

void RSASignature::init$() {
	$SignatureSpi::init$();
	$init($JsseJce);
	$set(this, rawRsa, $Signature::getInstance($JsseJce::SIGNATURE_RAWRSA));
	$set(this, mdMD5, $MessageDigest::getInstance("MD5"_s));
	$set(this, mdSHA, $MessageDigest::getInstance("SHA"_s));
}

$Signature* RSASignature::getInstance() {
	$init(RSASignature);
	$init($JsseJce);
	return $Signature::getInstance($JsseJce::SIGNATURE_SSLRSA);
}

void RSASignature::engineInitVerify($PublicKey* publicKey) {
	if (publicKey == nullptr) {
		$throwNew($InvalidKeyException, "Public key must not be null"_s);
	}
	$nc(this->mdMD5)->reset();
	$nc(this->mdSHA)->reset();
	$nc(this->rawRsa)->initVerify(publicKey);
}

void RSASignature::engineInitSign($PrivateKey* privateKey) {
	engineInitSign(privateKey, nullptr);
}

void RSASignature::engineInitSign($PrivateKey* privateKey, $SecureRandom* random) {
	if (privateKey == nullptr) {
		$throwNew($InvalidKeyException, "Private key must not be null"_s);
	}
	$nc(this->mdMD5)->reset();
	$nc(this->mdSHA)->reset();
	$nc(this->rawRsa)->initSign(privateKey, random);
}

void RSASignature::engineUpdate(int8_t b) {
	$nc(this->mdMD5)->update(b);
	$nc(this->mdSHA)->update(b);
}

void RSASignature::engineUpdate($bytes* b, int32_t off, int32_t len) {
	$nc(this->mdMD5)->update(b, off, len);
	$nc(this->mdSHA)->update(b, off, len);
}

$bytes* RSASignature::getDigest() {
	try {
		$var($bytes, data, $new($bytes, 36));
		$nc(this->mdMD5)->digest(data, 0, 16);
		$nc(this->mdSHA)->digest(data, 16, 20);
		return data;
	} catch ($DigestException& e) {
		$throwNew($SignatureException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$bytes* RSASignature::engineSign() {
	$nc(this->rawRsa)->update($(getDigest()));
	return $nc(this->rawRsa)->sign();
}

bool RSASignature::engineVerify($bytes* sigBytes) {
	return engineVerify(sigBytes, 0, $nc(sigBytes)->length);
}

bool RSASignature::engineVerify($bytes* sigBytes, int32_t offset, int32_t length) {
	$nc(this->rawRsa)->update($(getDigest()));
	return $nc(this->rawRsa)->verify(sigBytes, offset, length);
}

void RSASignature::engineSetParameter($String* param, Object$* value) {
	$throwNew($InvalidParameterException, "Parameters not supported"_s);
}

void RSASignature::engineSetParameter($AlgorithmParameterSpec* params) {
	if (params != nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "No parameters accepted"_s);
	}
}

$Object* RSASignature::engineGetParameter($String* param) {
	$throwNew($InvalidParameterException, "Parameters not supported"_s);
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

		} // ssl
	} // security
} // sun