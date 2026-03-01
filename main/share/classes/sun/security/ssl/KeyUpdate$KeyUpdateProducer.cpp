#include <sun/security/ssl/KeyUpdate$KeyUpdateProducer.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/KeyUpdate$KeyUpdateMessage.h>
#include <sun/security/ssl/KeyUpdate$KeyUpdateRequest.h>
#include <sun/security/ssl/KeyUpdate.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/PostHandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $Alert = ::sun::security::ssl::Alert;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $KeyUpdate$KeyUpdateMessage = ::sun::security::ssl::KeyUpdate$KeyUpdateMessage;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $PostHandshakeContext = ::sun::security::ssl::PostHandshakeContext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _KeyUpdate$KeyUpdateProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(KeyUpdate$KeyUpdateProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(KeyUpdate$KeyUpdateProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _KeyUpdate$KeyUpdateProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.KeyUpdate$KeyUpdateProducer", "sun.security.ssl.KeyUpdate", "KeyUpdateProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _KeyUpdate$KeyUpdateProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.KeyUpdate$KeyUpdateProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_KeyUpdate$KeyUpdateProducer_MethodInfo_,
	nullptr,
	nullptr,
	_KeyUpdate$KeyUpdateProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.KeyUpdate"
};

$Object* allocate$KeyUpdate$KeyUpdateProducer($Class* clazz) {
	return $of($alloc(KeyUpdate$KeyUpdateProducer));
}

void KeyUpdate$KeyUpdateProducer::init$() {
}

$bytes* KeyUpdate$KeyUpdateProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($PostHandshakeContext, hc, $cast($PostHandshakeContext, context));
	$var($KeyUpdate$KeyUpdateMessage, km, $cast($KeyUpdate$KeyUpdateMessage, message));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced KeyUpdate post-handshake message"_s, $$new($ObjectArray, {$of(km)}));
	}
	$SSLTrafficKeyDerivation* kdg = $SSLTrafficKeyDerivation::valueOf($nc($nc(hc)->conContext)->protocolVersion);
	if (kdg == nullptr) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, $nc(hc->conContext)->protocolVersion}))));
	}
	$var($SSLKeyDerivation, skd, $nc(kdg)->createKeyDerivation(hc, $nc($nc($nc($nc(hc)->conContext)->outputRecord)->writeCipher)->baseSecret));
	if (skd == nullptr) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::INTERNAL_ERROR, "no key derivation"_s)));
	}
	$var($SecretKey, nplus1, $nc(skd)->deriveKey("TlsUpdateNplus1"_s, nullptr));
	$var($SSLKeyDerivation, kd, kdg->createKeyDerivation(hc, nplus1));
	$var($SecretKey, key, $nc(kd)->deriveKey("TlsKey"_s, nullptr));
	$var($IvParameterSpec, ivSpec, $new($IvParameterSpec, $($nc($(kd->deriveKey("TlsIv"_s, nullptr)))->getEncoded())));
	$var($SSLCipher$SSLWriteCipher, wc, nullptr);
	try {
		$var($Authenticator, var$0, $Authenticator::valueOf($nc(hc->conContext)->protocolVersion));
		$var($ProtocolVersion, var$1, $nc(hc->conContext)->protocolVersion);
		$var($SecretKey, var$2, key);
		$var($IvParameterSpec, var$3, ivSpec);
		$assign(wc, $nc($nc(hc)->negotiatedCipherSuite)->bulkCipher->createWriteCipher(var$0, var$1, var$2, var$3, $($nc(hc->sslContext)->getSecureRandom())));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::INTERNAL_ERROR, "Failure to derive write secrets"_s, gse)));
	}
	if (wc == nullptr) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, hc->negotiatedCipherSuite, ") and protocol version ("_s, hc->negotiatedProtocol, ")"_s}))));
	}
	$set($nc(wc), baseSecret, nplus1);
	$nc($nc($nc(hc)->conContext)->outputRecord)->changeWriteCiphers(wc, $nc(km)->status->id);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine("KeyUpdate: write key updated"_s, $$new($ObjectArray, 0));
	}
	$nc(hc->conContext)->finishPostHandshake();
	return nullptr;
}

KeyUpdate$KeyUpdateProducer::KeyUpdate$KeyUpdateProducer() {
}

$Class* KeyUpdate$KeyUpdateProducer::load$($String* name, bool initialize) {
	$loadClass(KeyUpdate$KeyUpdateProducer, name, initialize, &_KeyUpdate$KeyUpdateProducer_ClassInfo_, allocate$KeyUpdate$KeyUpdateProducer);
	return class$;
}

$Class* KeyUpdate$KeyUpdateProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun