#include <sun/security/ssl/KAKeyDerivation.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/KeyAgreement.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/HKDF.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLMasterKeyDerivation.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeyAgreement = ::javax::crypto::KeyAgreement;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $HKDF = ::sun::security::ssl::HKDF;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLMasterKeyDerivation = ::sun::security::ssl::SSLMasterKeyDerivation;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _KAKeyDerivation_FieldInfo_[] = {
	{"algorithmName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(KAKeyDerivation, algorithmName)},
	{"context", "Lsun/security/ssl/HandshakeContext;", nullptr, $PRIVATE | $FINAL, $field(KAKeyDerivation, context)},
	{"localPrivateKey", "Ljava/security/PrivateKey;", nullptr, $PRIVATE | $FINAL, $field(KAKeyDerivation, localPrivateKey)},
	{"peerPublicKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE | $FINAL, $field(KAKeyDerivation, peerPublicKey)},
	{}
};

$MethodInfo _KAKeyDerivation_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/security/ssl/HandshakeContext;Ljava/security/PrivateKey;Ljava/security/PublicKey;)V", nullptr, 0, $method(KAKeyDerivation, init$, void, $String*, $HandshakeContext*, $PrivateKey*, $PublicKey*)},
	{"deriveKey", "(Ljava/lang/String;Ljava/security/spec/AlgorithmParameterSpec;)Ljavax/crypto/SecretKey;", nullptr, $PUBLIC, $virtualMethod(KAKeyDerivation, deriveKey, $SecretKey*, $String*, $AlgorithmParameterSpec*), "java.io.IOException"},
	{"t12DeriveKey", "(Ljava/lang/String;Ljava/security/spec/AlgorithmParameterSpec;)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $method(KAKeyDerivation, t12DeriveKey, $SecretKey*, $String*, $AlgorithmParameterSpec*), "java.io.IOException"},
	{"t13DeriveKey", "(Ljava/lang/String;Ljava/security/spec/AlgorithmParameterSpec;)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $method(KAKeyDerivation, t13DeriveKey, $SecretKey*, $String*, $AlgorithmParameterSpec*), "java.io.IOException"},
	{}
};

$ClassInfo _KAKeyDerivation_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.ssl.KAKeyDerivation",
	"java.lang.Object",
	"sun.security.ssl.SSLKeyDerivation",
	_KAKeyDerivation_FieldInfo_,
	_KAKeyDerivation_MethodInfo_
};

$Object* allocate$KAKeyDerivation($Class* clazz) {
	return $of($alloc(KAKeyDerivation));
}

void KAKeyDerivation::init$($String* algorithmName, $HandshakeContext* context, $PrivateKey* localPrivateKey, $PublicKey* peerPublicKey) {
	$set(this, algorithmName, algorithmName);
	$set(this, context, context);
	$set(this, localPrivateKey, localPrivateKey);
	$set(this, peerPublicKey, peerPublicKey);
}

$SecretKey* KAKeyDerivation::deriveKey($String* algorithm, $AlgorithmParameterSpec* params) {
	if (!$nc($nc(this->context)->negotiatedProtocol)->useTLS13PlusSpec()) {
		return t12DeriveKey(algorithm, params);
	} else {
		return t13DeriveKey(algorithm, params);
	}
}

$SecretKey* KAKeyDerivation::t12DeriveKey($String* algorithm, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyAgreement, ka, $KeyAgreement::getInstance(this->algorithmName));
		$nc(ka)->init(this->localPrivateKey);
		ka->doPhase(this->peerPublicKey, true);
		$var($SecretKey, preMasterSecret, ka->generateSecret("TlsPremasterSecret"_s));
		$SSLMasterKeyDerivation* mskd = $SSLMasterKeyDerivation::valueOf($nc(this->context)->negotiatedProtocol);
		if (mskd == nullptr) {
			$throwNew($SSLHandshakeException, $$str({"No expected master key derivation for protocol: "_s, $nc($nc(this->context)->negotiatedProtocol)->name$}));
		}
		$var($SSLKeyDerivation, kd, $nc(mskd)->createKeyDerivation(this->context, preMasterSecret));
		return $nc(kd)->deriveKey("MasterSecret"_s, params);
	} catch ($GeneralSecurityException& gse) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(gse))));
	}
	$shouldNotReachHere();
}

$SecretKey* KAKeyDerivation::t13DeriveKey($String* algorithm, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyAgreement, ka, $KeyAgreement::getInstance(this->algorithmName));
		$nc(ka)->init(this->localPrivateKey);
		ka->doPhase(this->peerPublicKey, true);
		$var($SecretKey, sharedSecret, ka->generateSecret("TlsPremasterSecret"_s));
		$CipherSuite$HashAlg* hashAlg = $nc($nc(this->context)->negotiatedCipherSuite)->hashAlg;
		$var($SSLKeyDerivation, kd, $nc(this->context)->handshakeKeyDerivation);
		$var($HKDF, hkdf, $new($HKDF, $nc(hashAlg)->name$));
		if (kd == nullptr) {
			$var($bytes, zeros, $new($bytes, $nc(hashAlg)->hashLength));
			$var($SecretKeySpec, ikm, $new($SecretKeySpec, zeros, "TlsPreSharedSecret"_s));
			$var($SecretKey, earlySecret, hkdf->extract(zeros, static_cast<$SecretKey*>(ikm), "TlsEarlySecret"_s));
			$assign(kd, $new($SSLSecretDerivation, this->context, earlySecret));
		}
		$var($SecretKey, saltSecret, $nc(kd)->deriveKey("TlsSaltSecret"_s, nullptr));
		return hkdf->extract(saltSecret, sharedSecret, algorithm);
	} catch ($GeneralSecurityException& gse) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(gse))));
	}
	$shouldNotReachHere();
}

KAKeyDerivation::KAKeyDerivation() {
}

$Class* KAKeyDerivation::load$($String* name, bool initialize) {
	$loadClass(KAKeyDerivation, name, initialize, &_KAKeyDerivation_ClassInfo_, allocate$KAKeyDerivation);
	return class$;
}

$Class* KAKeyDerivation::class$ = nullptr;

		} // ssl
	} // security
} // sun