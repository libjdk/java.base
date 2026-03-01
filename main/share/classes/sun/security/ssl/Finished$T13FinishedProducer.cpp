#include <sun/security/ssl/Finished$T13FinishedProducer.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/HashMap.h>
#include <java/util/LinkedHashMap.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/Finished$FinishedMessage.h>
#include <sun/security/ssl/Finished.h>
#include <sun/security/ssl/HKDF.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <sun/security/ssl/SSLSessionContextImpl.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef FINISHED
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR

using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $Alert = ::sun::security::ssl::Alert;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $Finished = ::sun::security::ssl::Finished;
using $Finished$FinishedMessage = ::sun::security::ssl::Finished$FinishedMessage;
using $HKDF = ::sun::security::ssl::HKDF;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;
using $SSLSessionContextImpl = ::sun::security::ssl::SSLSessionContextImpl;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _Finished$T13FinishedProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Finished$T13FinishedProducer, init$, void)},
	{"onProduceFinished", "(Lsun/security/ssl/ClientHandshakeContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PRIVATE, $method(Finished$T13FinishedProducer, onProduceFinished, $bytes*, $ClientHandshakeContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{"onProduceFinished", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PRIVATE, $method(Finished$T13FinishedProducer, onProduceFinished, $bytes*, $ServerHandshakeContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(Finished$T13FinishedProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Finished$T13FinishedProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.Finished$T13FinishedProducer", "sun.security.ssl.Finished", "T13FinishedProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Finished$T13FinishedProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.Finished$T13FinishedProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_Finished$T13FinishedProducer_MethodInfo_,
	nullptr,
	nullptr,
	_Finished$T13FinishedProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.Finished"
};

$Object* allocate$Finished$T13FinishedProducer($Class* clazz) {
	return $of($alloc(Finished$T13FinishedProducer));
}

void Finished$T13FinishedProducer::init$() {
}

$bytes* Finished$T13FinishedProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$var($HandshakeContext, hc, $cast($HandshakeContext, context));
	if ($nc($nc(hc)->sslConfig)->isClientMode) {
		return onProduceFinished($cast($ClientHandshakeContext, context), message);
	} else {
		return onProduceFinished($cast($ServerHandshakeContext, context), message);
	}
}

$bytes* Finished$T13FinishedProducer::onProduceFinished($ClientHandshakeContext* chc, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$nc($nc(chc)->handshakeHash)->update();
	$var($Finished$FinishedMessage, fm, $new($Finished$FinishedMessage, chc));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced client Finished handshake message"_s, $$new($ObjectArray, {$of(fm)}));
	}
	fm->write(chc->handshakeOutput);
	$nc(chc->handshakeOutput)->flush();
	if ($nc(chc->conContext)->secureRenegotiation) {
		$set($nc(chc->conContext), clientVerifyData, fm->verifyData);
	}
	$var($SSLKeyDerivation, kd, chc->handshakeKeyDerivation);
	if (kd == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "no key derivation"_s)));
	}
	$SSLTrafficKeyDerivation* kdg = $SSLTrafficKeyDerivation::valueOf(chc->negotiatedProtocol);
	if (kdg == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, chc->negotiatedProtocol}))));
	}
	try {
		$var($SecretKey, writeSecret, $nc(kd)->deriveKey("TlsClientAppTrafficSecret"_s, nullptr));
		$var($SSLKeyDerivation, writeKD, $nc(kdg)->createKeyDerivation(chc, writeSecret));
		$var($SecretKey, writeKey, $nc(writeKD)->deriveKey("TlsKey"_s, nullptr));
		$var($SecretKey, writeIvSecret, writeKD->deriveKey("TlsIv"_s, nullptr));
		$var($IvParameterSpec, writeIv, $new($IvParameterSpec, $($nc(writeIvSecret)->getEncoded())));
		$var($Authenticator, var$0, $Authenticator::valueOf(chc->negotiatedProtocol));
		$var($ProtocolVersion, var$1, chc->negotiatedProtocol);
		$var($SecretKey, var$2, writeKey);
		$var($IvParameterSpec, var$3, writeIv);
		$var($SSLCipher$SSLWriteCipher, writeCipher, $nc(chc->negotiatedCipherSuite)->bulkCipher->createWriteCipher(var$0, var$1, var$2, var$3, $($nc(chc->sslContext)->getSecureRandom())));
		if (writeCipher == nullptr) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, chc->negotiatedCipherSuite, ") and protocol version ("_s, chc->negotiatedProtocol, ")"_s}))));
		}
		$set(chc, baseWriteSecret, writeSecret);
		$nc($nc(chc->conContext)->outputRecord)->changeWriteCiphers(writeCipher, false);
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "Failure to derive application secrets"_s, gse)));
	}
	$var($SSLSecretDerivation, sd, $nc(($cast($SSLSecretDerivation, kd)))->forContext(chc));
	$var($SecretKey, resumptionMasterSecret, $nc(sd)->deriveKey("TlsResumptionMasterSecret"_s, nullptr));
	$nc(chc->handshakeSession)->setResumptionMasterSecret(resumptionMasterSecret);
	$set($nc(chc->conContext), conSession, $nc(chc->handshakeSession)->finish());
	$set($nc(chc->conContext), protocolVersion, chc->negotiatedProtocol);
	chc->handshakeFinished = true;
	$nc(chc->conContext)->finishHandshake();
	$Finished::recordEvent($nc(chc->conContext)->conSession);
	return nullptr;
}

$bytes* Finished$T13FinishedProducer::onProduceFinished($ServerHandshakeContext* shc, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$nc($nc(shc)->handshakeHash)->update();
	$var($Finished$FinishedMessage, fm, $new($Finished$FinishedMessage, shc));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced server Finished handshake message"_s, $$new($ObjectArray, {$of(fm)}));
	}
	fm->write(shc->handshakeOutput);
	$nc(shc->handshakeOutput)->flush();
	$var($SSLKeyDerivation, kd, shc->handshakeKeyDerivation);
	if (kd == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, "no key derivation"_s)));
	}
	$SSLTrafficKeyDerivation* kdg = $SSLTrafficKeyDerivation::valueOf(shc->negotiatedProtocol);
	if (kdg == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, shc->negotiatedProtocol}))));
	}
	try {
		$var($SecretKey, saltSecret, $nc(kd)->deriveKey("TlsSaltSecret"_s, nullptr));
		$CipherSuite$HashAlg* hashAlg = $nc(shc->negotiatedCipherSuite)->hashAlg;
		$var($HKDF, hkdf, $new($HKDF, $nc(hashAlg)->name$));
		$var($bytes, zeros, $new($bytes, $nc(hashAlg)->hashLength));
		$var($SecretKeySpec, sharedSecret, $new($SecretKeySpec, zeros, "TlsZeroSecret"_s));
		$var($SecretKey, masterSecret, hkdf->extract(saltSecret, static_cast<$SecretKey*>(sharedSecret), "TlsMasterSecret"_s));
		$var($SSLKeyDerivation, secretKD, $new($SSLSecretDerivation, shc, masterSecret));
		$var($SecretKey, writeSecret, secretKD->deriveKey("TlsServerAppTrafficSecret"_s, nullptr));
		$var($SSLKeyDerivation, writeKD, $nc(kdg)->createKeyDerivation(shc, writeSecret));
		$var($SecretKey, writeKey, $nc(writeKD)->deriveKey("TlsKey"_s, nullptr));
		$var($SecretKey, writeIvSecret, writeKD->deriveKey("TlsIv"_s, nullptr));
		$var($IvParameterSpec, writeIv, $new($IvParameterSpec, $($nc(writeIvSecret)->getEncoded())));
		$var($Authenticator, var$0, $Authenticator::valueOf(shc->negotiatedProtocol));
		$var($ProtocolVersion, var$1, shc->negotiatedProtocol);
		$var($SecretKey, var$2, writeKey);
		$var($IvParameterSpec, var$3, writeIv);
		$var($SSLCipher$SSLWriteCipher, writeCipher, $nc(shc->negotiatedCipherSuite)->bulkCipher->createWriteCipher(var$0, var$1, var$2, var$3, $($nc(shc->sslContext)->getSecureRandom())));
		if (writeCipher == nullptr) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, shc->negotiatedCipherSuite, ") and protocol version ("_s, shc->negotiatedProtocol, ")"_s}))));
		}
		$set(shc, baseWriteSecret, writeSecret);
		$nc($nc(shc->conContext)->outputRecord)->changeWriteCiphers(writeCipher, false);
		$set(shc, handshakeKeyDerivation, secretKD);
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, "Failure to derive application secrets"_s, gse)));
	}
	if ($nc(shc->conContext)->secureRenegotiation) {
		$set($nc(shc->conContext), serverVerifyData, fm->verifyData);
	}
	$nc(shc->handshakeSession)->setContext($cast($SSLSessionContextImpl, $($nc(shc->sslContext)->engineGetServerSessionContext())));
	$set($nc(shc->conContext), conSession, $nc(shc->handshakeSession)->finish());
	$init($SSLHandshake);
	$nc(shc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::FINISHED->id)), $SSLHandshake::FINISHED);
	return nullptr;
}

Finished$T13FinishedProducer::Finished$T13FinishedProducer() {
}

$Class* Finished$T13FinishedProducer::load$($String* name, bool initialize) {
	$loadClass(Finished$T13FinishedProducer, name, initialize, &_Finished$T13FinishedProducer_ClassInfo_, allocate$Finished$T13FinishedProducer);
	return class$;
}

$Class* Finished$T13FinishedProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun