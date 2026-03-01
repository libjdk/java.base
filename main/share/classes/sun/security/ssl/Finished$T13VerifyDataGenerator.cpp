#include <sun/security/ssl/Finished$T13VerifyDataGenerator.h>

#include <java/lang/CharSequence.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/ProviderException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/Finished.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/SSLBasicKeyDerivation$SecretSizeSpec.h>
#include <sun/security/ssl/SSLBasicKeyDerivation.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ProviderException = ::java::security::ProviderException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $SSLBasicKeyDerivation = ::sun::security::ssl::SSLBasicKeyDerivation;
using $SSLBasicKeyDerivation$SecretSizeSpec = ::sun::security::ssl::SSLBasicKeyDerivation$SecretSizeSpec;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _Finished$T13VerifyDataGenerator_FieldInfo_[] = {
	{"hkdfLabel", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Finished$T13VerifyDataGenerator, hkdfLabel)},
	{"hkdfContext", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Finished$T13VerifyDataGenerator, hkdfContext)},
	{}
};

$MethodInfo _Finished$T13VerifyDataGenerator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Finished$T13VerifyDataGenerator, init$, void)},
	{"createVerifyData", "(Lsun/security/ssl/HandshakeContext;Z)[B", nullptr, $PUBLIC, $virtualMethod(Finished$T13VerifyDataGenerator, createVerifyData, $bytes*, $HandshakeContext*, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _Finished$T13VerifyDataGenerator_InnerClassesInfo_[] = {
	{"sun.security.ssl.Finished$T13VerifyDataGenerator", "sun.security.ssl.Finished", "T13VerifyDataGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Finished$VerifyDataGenerator", "sun.security.ssl.Finished", "VerifyDataGenerator", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Finished$T13VerifyDataGenerator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.Finished$T13VerifyDataGenerator",
	"java.lang.Object",
	"sun.security.ssl.Finished$VerifyDataGenerator",
	_Finished$T13VerifyDataGenerator_FieldInfo_,
	_Finished$T13VerifyDataGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_Finished$T13VerifyDataGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.Finished"
};

$Object* allocate$Finished$T13VerifyDataGenerator($Class* clazz) {
	return $of($alloc(Finished$T13VerifyDataGenerator));
}

$bytes* Finished$T13VerifyDataGenerator::hkdfLabel = nullptr;
$bytes* Finished$T13VerifyDataGenerator::hkdfContext = nullptr;

void Finished$T13VerifyDataGenerator::init$() {
}

$bytes* Finished$T13VerifyDataGenerator::createVerifyData($HandshakeContext* context, bool isValidation) {
	$useLocalCurrentObjectStackCache();
	$CipherSuite$HashAlg* hashAlg = $nc($nc(context)->negotiatedCipherSuite)->hashAlg;
	$var($SecretKey, secret, isValidation ? context->baseReadSecret : context->baseWriteSecret);
	$var($SSLBasicKeyDerivation, kdf, $new($SSLBasicKeyDerivation, secret, $nc(hashAlg)->name$, Finished$T13VerifyDataGenerator::hkdfLabel, Finished$T13VerifyDataGenerator::hkdfContext, hashAlg->hashLength));
	$var($AlgorithmParameterSpec, keySpec, $new($SSLBasicKeyDerivation$SecretSizeSpec, $nc(hashAlg)->hashLength));
	$var($SecretKey, finishedSecret, kdf->deriveKey("TlsFinishedSecret"_s, keySpec));
	$var($String, hmacAlg, $str({"Hmac"_s, $($nc($nc(hashAlg)->name$)->replace(static_cast<$CharSequence*>("-"_s), static_cast<$CharSequence*>(""_s)))}));
	try {
		$var($Mac, hmac, $Mac::getInstance(hmacAlg));
		$nc(hmac)->init(finishedSecret);
		return hmac->doFinal($($nc(context->handshakeHash)->digest()));
	} catch ($NoSuchAlgorithmException& ex) {
		$throwNew($ProviderException, "Failed to generate verify_data"_s, ex);
	} catch ($InvalidKeyException& ex) {
		$throwNew($ProviderException, "Failed to generate verify_data"_s, ex);
	}
	$shouldNotReachHere();
}

void clinit$Finished$T13VerifyDataGenerator($Class* class$) {
	$assignStatic(Finished$T13VerifyDataGenerator::hkdfLabel, "tls13 finished"_s->getBytes());
	$assignStatic(Finished$T13VerifyDataGenerator::hkdfContext, $new($bytes, 0));
}

Finished$T13VerifyDataGenerator::Finished$T13VerifyDataGenerator() {
}

$Class* Finished$T13VerifyDataGenerator::load$($String* name, bool initialize) {
	$loadClass(Finished$T13VerifyDataGenerator, name, initialize, &_Finished$T13VerifyDataGenerator_ClassInfo_, clinit$Finished$T13VerifyDataGenerator, allocate$Finished$T13VerifyDataGenerator);
	return class$;
}

$Class* Finished$T13VerifyDataGenerator::class$ = nullptr;

		} // ssl
	} // security
} // sun