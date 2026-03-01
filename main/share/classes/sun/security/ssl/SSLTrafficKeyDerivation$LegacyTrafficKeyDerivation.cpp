#include <sun/security/ssl/SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/ProviderException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/KeyGenerator.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/internal/spec/TlsKeyMaterialParameterSpec.h>
#include <sun/security/internal/spec/TlsKeyMaterialSpec.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/CipherType.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <jcpp.h>

#undef AEAD_CIPHER
#undef BLOCK_CIPHER
#undef DTLS10
#undef H_NONE
#undef TLS11
#undef TLS12

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $ProviderException = ::java::security::ProviderException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeyGenerator = ::javax::crypto::KeyGenerator;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $TlsKeyMaterialParameterSpec = ::sun::security::internal::spec::TlsKeyMaterialParameterSpec;
using $TlsKeyMaterialSpec = ::sun::security::internal::spec::TlsKeyMaterialSpec;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $CipherType = ::sun::security::ssl::CipherType;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_FieldInfo_[] = {
	{"keyMaterialSpec", "Lsun/security/internal/spec/TlsKeyMaterialSpec;", nullptr, $PRIVATE | $FINAL, $field(SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, keyMaterialSpec)},
	{}
};

$MethodInfo _SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;)V", nullptr, 0, $method(SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, init$, void, $HandshakeContext*, $SecretKey*)},
	{"deriveKey", "(Ljava/lang/String;Ljava/security/spec/AlgorithmParameterSpec;)Ljavax/crypto/SecretKey;", nullptr, $PUBLIC, $virtualMethod(SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, deriveKey, $SecretKey*, $String*, $AlgorithmParameterSpec*), "java.io.IOException"},
	{"getTrafficKey", "(Ljava/lang/String;)Ljavax/crypto/SecretKey;", nullptr, 0, $method(SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, getTrafficKey, $SecretKey*, $String*)},
	{}
};

$InnerClassInfo _SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation", "sun.security.ssl.SSLTrafficKeyDerivation", "LegacyTrafficKeyDerivation", $STATIC | $FINAL},
	{}
};

$ClassInfo _SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation",
	"java.lang.Object",
	"sun.security.ssl.SSLKeyDerivation",
	_SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_FieldInfo_,
	_SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_MethodInfo_,
	nullptr,
	nullptr,
	_SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLTrafficKeyDerivation"
};

$Object* allocate$SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation($Class* clazz) {
	return $of($alloc(SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation));
}

void SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation::init$($HandshakeContext* context, $SecretKey* masterSecret) {
	$useLocalCurrentObjectStackCache();
	$CipherSuite* cipherSuite = $nc(context)->negotiatedCipherSuite;
	$ProtocolVersion* protocolVersion = context->negotiatedProtocol;
	int32_t hashSize = $nc(cipherSuite)->macAlg->size;
	bool is_exportable = cipherSuite->exportable;
	$SSLCipher* cipher = cipherSuite->bulkCipher;
	int32_t expandedKeySize = is_exportable ? $nc(cipher)->expandedKeySize : 0;
	$var($String, keyMaterialAlg, nullptr);
	$CipherSuite$HashAlg* hashAlg = nullptr;
	int8_t majorVersion = $nc(protocolVersion)->major;
	int8_t minorVersion = protocolVersion->minor;
	if (protocolVersion->isDTLS) {
		$init($ProtocolVersion);
		if (protocolVersion->id == $ProtocolVersion::DTLS10->id) {
			majorVersion = $ProtocolVersion::TLS11->major;
			minorVersion = $ProtocolVersion::TLS11->minor;
			$assign(keyMaterialAlg, "SunTlsKeyMaterial"_s);
			$init($CipherSuite$HashAlg);
			hashAlg = $CipherSuite$HashAlg::H_NONE;
		} else {
			majorVersion = $ProtocolVersion::TLS12->major;
			minorVersion = $ProtocolVersion::TLS12->minor;
			$assign(keyMaterialAlg, "SunTls12KeyMaterial"_s);
			hashAlg = cipherSuite->hashAlg;
		}
	} else {
		$init($ProtocolVersion);
		if (protocolVersion->id >= $ProtocolVersion::TLS12->id) {
			$assign(keyMaterialAlg, "SunTls12KeyMaterial"_s);
			hashAlg = cipherSuite->hashAlg;
		} else {
			$assign(keyMaterialAlg, "SunTlsKeyMaterial"_s);
			$init($CipherSuite$HashAlg);
			hashAlg = $CipherSuite$HashAlg::H_NONE;
		}
	}
	int32_t ivSize = cipher->ivSize;
	$init($CipherType);
	if (cipher->cipherType == $CipherType::AEAD_CIPHER) {
		ivSize = cipher->fixedIvSize;
	} else {
		if (cipher->cipherType == $CipherType::BLOCK_CIPHER && protocolVersion->useTLS11PlusSpec()) {
			ivSize = 0;
		}
	}
	$var($TlsKeyMaterialParameterSpec, spec, $new($TlsKeyMaterialParameterSpec, masterSecret, ((int32_t)(majorVersion & (uint32_t)255)), ((int32_t)(minorVersion & (uint32_t)255)), $nc(context->clientHelloRandom)->randomBytes, $nc(context->serverHelloRandom)->randomBytes, cipher->algorithm, cipher->keySize, expandedKeySize, ivSize, hashSize, $nc(hashAlg)->name$, hashAlg->hashLength, hashAlg->blockSize));
	try {
		$var($KeyGenerator, kg, $KeyGenerator::getInstance(keyMaterialAlg));
		$nc(kg)->init(static_cast<$AlgorithmParameterSpec*>(spec));
		$set(this, keyMaterialSpec, $cast($TlsKeyMaterialSpec, kg->generateKey()));
	} catch ($GeneralSecurityException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
}

$SecretKey* SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation::getTrafficKey($String* algorithm) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, s11334$, algorithm);
		int32_t tmp11334$ = -1;
		switch ($nc(s11334$)->hashCode()) {
		case (int32_t)0x9F4BE63B:
			{
				if (s11334$->equals("clientMacKey"_s)) {
					tmp11334$ = 0;
				}
				break;
			}
		case 0x668EA7B3:
			{
				if (s11334$->equals("serverMacKey"_s)) {
					tmp11334$ = 1;
				}
				break;
			}
		case (int32_t)0x9A7F2AEB:
			{
				if (s11334$->equals("clientWriteKey"_s)) {
					tmp11334$ = 2;
				}
				break;
			}
		case (int32_t)0x9C176E63:
			{
				if (s11334$->equals("serverWriteKey"_s)) {
					tmp11334$ = 3;
				}
				break;
			}
		case 0x7898BF21:
			{
				if (s11334$->equals("clientWriteIv"_s)) {
					tmp11334$ = 4;
				}
				break;
			}
		case (int32_t)0x99AE2CA9:
			{
				if (s11334$->equals("serverWriteIv"_s)) {
					tmp11334$ = 5;
				}
				break;
			}
		}
		{
			$var($IvParameterSpec, cliIvSpec, nullptr)
			$var($IvParameterSpec, srvIvSpec, nullptr)
			switch (tmp11334$) {
			case 0:
				{
					return $nc(this->keyMaterialSpec)->getClientMacKey();
				}
			case 1:
				{
					return $nc(this->keyMaterialSpec)->getServerMacKey();
				}
			case 2:
				{
					return $nc(this->keyMaterialSpec)->getClientCipherKey();
				}
			case 3:
				{
					return $nc(this->keyMaterialSpec)->getServerCipherKey();
				}
			case 4:
				{
					$assign(cliIvSpec, $nc(this->keyMaterialSpec)->getClientIv());
					return (cliIvSpec == nullptr) ? ($SecretKey*)nullptr : static_cast<$SecretKey*>($new($SecretKeySpec, $($nc(cliIvSpec)->getIV()), "TlsIv"_s));
				}
			case 5:
				{
					$assign(srvIvSpec, $nc(this->keyMaterialSpec)->getServerIv());
					return (srvIvSpec == nullptr) ? ($SecretKey*)nullptr : static_cast<$SecretKey*>($new($SecretKeySpec, $($nc(srvIvSpec)->getIV()), "TlsIv"_s));
				}
			}
		}
	}
	return nullptr;
}

$SecretKey* SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation::deriveKey($String* algorithm, $AlgorithmParameterSpec* params) {
	return getTrafficKey(algorithm);
}

SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation::SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation() {
}

$Class* SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation::load$($String* name, bool initialize) {
	$loadClass(SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, name, initialize, &_SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation_ClassInfo_, allocate$SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation);
	return class$;
}

$Class* SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation::class$ = nullptr;

		} // ssl
	} // security
} // sun