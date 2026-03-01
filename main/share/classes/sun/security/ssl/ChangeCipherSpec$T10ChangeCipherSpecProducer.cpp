#include <sun/security/ssl/ChangeCipherSpec$T10ChangeCipherSpecProducer.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SecureRandom.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ChangeCipherSpec.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/CipherType.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef AEAD_CIPHER
#undef ILLEGAL_PARAMETER

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SSLException = ::javax::net::ssl::SSLException;
using $Alert = ::sun::security::ssl::Alert;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $CipherType = ::sun::security::ssl::CipherType;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ChangeCipherSpec$T10ChangeCipherSpecProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ChangeCipherSpec$T10ChangeCipherSpecProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(ChangeCipherSpec$T10ChangeCipherSpecProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ChangeCipherSpec$T10ChangeCipherSpecProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ChangeCipherSpec$T10ChangeCipherSpecProducer", "sun.security.ssl.ChangeCipherSpec", "T10ChangeCipherSpecProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ChangeCipherSpec$T10ChangeCipherSpecProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ChangeCipherSpec$T10ChangeCipherSpecProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_ChangeCipherSpec$T10ChangeCipherSpecProducer_MethodInfo_,
	nullptr,
	nullptr,
	_ChangeCipherSpec$T10ChangeCipherSpecProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ChangeCipherSpec"
};

$Object* allocate$ChangeCipherSpec$T10ChangeCipherSpecProducer($Class* clazz) {
	return $of($alloc(ChangeCipherSpec$T10ChangeCipherSpecProducer));
}

void ChangeCipherSpec$T10ChangeCipherSpecProducer::init$() {
}

$bytes* ChangeCipherSpec$T10ChangeCipherSpecProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($HandshakeContext, hc, $cast($HandshakeContext, context));
	$var($SSLKeyDerivation, kd, $nc(hc)->handshakeKeyDerivation);
	if (!($instanceOf($SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, kd))) {
		$throwNew($UnsupportedOperationException, "Not supported."_s);
	}
	$var($SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, tkd, $cast($SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, kd));
	$CipherSuite* ncs = hc->negotiatedCipherSuite;
	$var($Authenticator, writeAuthenticator, nullptr);
	$init($CipherType);
	if ($nc(ncs)->bulkCipher->cipherType == $CipherType::AEAD_CIPHER) {
		$assign(writeAuthenticator, $Authenticator::valueOf(hc->negotiatedProtocol));
	} else {
		try {
			$assign(writeAuthenticator, $Authenticator::valueOf(hc->negotiatedProtocol, ncs->macAlg, $($nc(tkd)->getTrafficKey($nc(hc->sslConfig)->isClientMode ? "clientMacKey"_s : "serverMacKey"_s))));
		} catch ($NoSuchAlgorithmException& e) {
			$throwNew($SSLException, "Algorithm missing:  "_s, e);
		} catch ($InvalidKeyException& e) {
			$throwNew($SSLException, "Algorithm missing:  "_s, e);
		}
	}
	$var($SecretKey, writeKey, $nc(tkd)->getTrafficKey($nc(hc->sslConfig)->isClientMode ? "clientWriteKey"_s : "serverWriteKey"_s));
	$var($SecretKey, writeIv, tkd->getTrafficKey($nc(hc->sslConfig)->isClientMode ? "clientWriteIv"_s : "serverWriteIv"_s));
	$var($IvParameterSpec, iv, (writeIv == nullptr) ? ($IvParameterSpec*)nullptr : $new($IvParameterSpec, $($nc(writeIv)->getEncoded())));
	$var($SSLCipher$SSLWriteCipher, writeCipher, nullptr);
	try {
		$assign(writeCipher, $nc(ncs)->bulkCipher->createWriteCipher(writeAuthenticator, hc->negotiatedProtocol, writeKey, iv, $($nc(hc->sslContext)->getSecureRandom())));
	} catch ($GeneralSecurityException& gse) {
		$throwNew($SSLException, "Algorithm missing:  "_s, gse);
	}
	if (writeCipher == nullptr) {
		$init($Alert);
		$throw($($nc(hc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, ncs, ") and protocol version ("_s, hc->negotiatedProtocol, ")"_s}))));
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced ChangeCipherSpec message"_s, $$new($ObjectArray, 0));
	}
	$nc($nc(hc->conContext)->outputRecord)->changeWriteCiphers(writeCipher, true);
	return nullptr;
}

ChangeCipherSpec$T10ChangeCipherSpecProducer::ChangeCipherSpec$T10ChangeCipherSpecProducer() {
}

$Class* ChangeCipherSpec$T10ChangeCipherSpecProducer::load$($String* name, bool initialize) {
	$loadClass(ChangeCipherSpec$T10ChangeCipherSpecProducer, name, initialize, &_ChangeCipherSpec$T10ChangeCipherSpecProducer_ClassInfo_, allocate$ChangeCipherSpec$T10ChangeCipherSpecProducer);
	return class$;
}

$Class* ChangeCipherSpec$T10ChangeCipherSpecProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun