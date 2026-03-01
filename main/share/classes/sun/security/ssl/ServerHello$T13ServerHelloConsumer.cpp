#include <sun/security/ssl/ServerHello$T13ServerHelloConsumer.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/HashMap.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/Map.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ChangeCipherSpec.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLConsumer.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/ServerHello$ServerHelloMessage.h>
#include <sun/security/ssl/ServerHello.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CERTIFICATE
#undef CERTIFICATE_REQUEST
#undef CERTIFICATE_VERIFY
#undef CHANGE_CIPHER_SPEC
#undef ENCRYPTED_EXTENSIONS
#undef FINISHED
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR
#undef PROTOCOL_VERSION
#undef SERVER_HELLO
#undef TLS12

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $Map = ::java::util::Map;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $Alert = ::sun::security::ssl::Alert;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $ChangeCipherSpec = ::sun::security::ssl::ChangeCipherSpec;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLKeyExchange = ::sun::security::ssl::SSLKeyExchange;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $ServerHello = ::sun::security::ssl::ServerHello;
using $ServerHello$ServerHelloMessage = ::sun::security::ssl::ServerHello$ServerHelloMessage;
using $SessionId = ::sun::security::ssl::SessionId;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ServerHello$T13ServerHelloConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ServerHello$T13ServerHelloConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)V", nullptr, $PUBLIC, $virtualMethod(ServerHello$T13ServerHelloConsumer, consume, void, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ServerHello$T13ServerHelloConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerHello$T13ServerHelloConsumer", "sun.security.ssl.ServerHello", "T13ServerHelloConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ServerHello$T13ServerHelloConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerHello$T13ServerHelloConsumer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeConsumer",
	nullptr,
	_ServerHello$T13ServerHelloConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_ServerHello$T13ServerHelloConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerHello"
};

$Object* allocate$ServerHello$T13ServerHelloConsumer($Class* clazz) {
	return $of($alloc(ServerHello$T13ServerHelloConsumer));
}

void ServerHello$T13ServerHelloConsumer::init$() {
}

void ServerHello$T13ServerHelloConsumer::consume($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($ServerHello$ServerHelloMessage, serverHello, $cast($ServerHello$ServerHelloMessage, message));
	$init($ProtocolVersion);
	if ($nc(serverHello)->serverVersion != $ProtocolVersion::TLS12) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::PROTOCOL_VERSION, "The ServerHello.legacy_version field is not TLS 1.2"_s)));
	}
	$set($nc(chc), negotiatedCipherSuite, $nc(serverHello)->cipherSuite);
	$nc(chc->handshakeHash)->determine(chc->negotiatedProtocol, chc->negotiatedCipherSuite);
	$set(chc, serverHelloRandom, serverHello->serverRandom);
	$init($SSLHandshake);
	$var($SSLExtensionArray, extTypes, $nc(chc->sslConfig)->getEnabledExtensions($SSLHandshake::SERVER_HELLO));
	$nc(serverHello->extensions)->consumeOnLoad(chc, extTypes);
	if (!chc->isResumption) {
		if (chc->resumingSession != nullptr) {
			$nc(chc->resumingSession)->invalidate();
			$set(chc, resumingSession, nullptr);
		}
		if (!$nc(chc->sslConfig)->enableSessionCreation) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::PROTOCOL_VERSION, "New session creation is disabled"_s)));
		}
		$set(chc, handshakeSession, $new($SSLSessionImpl, chc, chc->negotiatedCipherSuite, serverHello->sessionId));
		$nc(chc->handshakeSession)->setMaximumPacketSize($nc(chc->sslConfig)->maximumPacketSize);
	} else {
		$var($SecretKey, psk, $nc(chc->resumingSession)->consumePreSharedKey());
		if (psk == nullptr) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "No PSK available. Unable to resume."_s)));
		}
		$set(chc, handshakeSession, chc->resumingSession);
		$ServerHello::setUpPskKD(chc, psk);
	}
	$nc(serverHello->extensions)->consumeOnTrade(chc, extTypes);
	$nc(chc->handshakeHash)->update();
	$var($SSLKeyExchange, ke, chc->handshakeKeyExchange);
	if (ke == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "Not negotiated key shares"_s)));
	}
	$var($SSLKeyDerivation, handshakeKD, $nc(ke)->createKeyDerivation(chc));
	$var($SecretKey, handshakeSecret, $nc(handshakeKD)->deriveKey("TlsHandshakeSecret"_s, nullptr));
	$SSLTrafficKeyDerivation* kdg = $SSLTrafficKeyDerivation::valueOf(chc->negotiatedProtocol);
	if (kdg == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, chc->negotiatedProtocol}))));
	}
	$var($SSLKeyDerivation, secretKD, $new($SSLSecretDerivation, chc, handshakeSecret));
	$var($SecretKey, readSecret, secretKD->deriveKey("TlsServerHandshakeTrafficSecret"_s, nullptr));
	$var($SSLKeyDerivation, readKD, $nc(kdg)->createKeyDerivation(chc, readSecret));
	$var($SecretKey, readKey, $nc(readKD)->deriveKey("TlsKey"_s, nullptr));
	$var($SecretKey, readIvSecret, readKD->deriveKey("TlsIv"_s, nullptr));
	$var($IvParameterSpec, readIv, $new($IvParameterSpec, $($nc(readIvSecret)->getEncoded())));
	$var($SSLCipher$SSLReadCipher, readCipher, nullptr);
	try {
		$var($Authenticator, var$0, $Authenticator::valueOf(chc->negotiatedProtocol));
		$var($ProtocolVersion, var$1, chc->negotiatedProtocol);
		$var($SecretKey, var$2, readKey);
		$var($IvParameterSpec, var$3, readIv);
		$assign(readCipher, $nc(chc->negotiatedCipherSuite)->bulkCipher->createReadCipher(var$0, var$1, var$2, var$3, $($nc(chc->sslContext)->getSecureRandom())));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Missing cipher algorithm"_s, gse)));
	}
	if (readCipher == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, chc->negotiatedCipherSuite, ") and protocol version ("_s, chc->negotiatedProtocol, ")"_s}))));
	}
	$set(chc, baseReadSecret, readSecret);
	$nc($nc(chc->conContext)->inputRecord)->changeReadCiphers(readCipher);
	$var($SecretKey, writeSecret, secretKD->deriveKey("TlsClientHandshakeTrafficSecret"_s, nullptr));
	$var($SSLKeyDerivation, writeKD, kdg->createKeyDerivation(chc, writeSecret));
	$var($SecretKey, writeKey, $nc(writeKD)->deriveKey("TlsKey"_s, nullptr));
	$var($SecretKey, writeIvSecret, writeKD->deriveKey("TlsIv"_s, nullptr));
	$var($IvParameterSpec, writeIv, $new($IvParameterSpec, $($nc(writeIvSecret)->getEncoded())));
	$var($SSLCipher$SSLWriteCipher, writeCipher, nullptr);
	try {
		$var($Authenticator, var$4, $Authenticator::valueOf(chc->negotiatedProtocol));
		$var($ProtocolVersion, var$5, chc->negotiatedProtocol);
		$var($SecretKey, var$6, writeKey);
		$var($IvParameterSpec, var$7, writeIv);
		$assign(writeCipher, $nc(chc->negotiatedCipherSuite)->bulkCipher->createWriteCipher(var$4, var$5, var$6, var$7, $($nc(chc->sslContext)->getSecureRandom())));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Missing cipher algorithm"_s, gse)));
	}
	if (writeCipher == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, chc->negotiatedCipherSuite, ") and protocol version ("_s, chc->negotiatedProtocol, ")"_s}))));
	}
	$set(chc, baseWriteSecret, writeSecret);
	$nc($nc(chc->conContext)->outputRecord)->changeWriteCiphers(writeCipher, ($nc(serverHello->sessionId)->length() != 0));
	$set(chc, handshakeKeyDerivation, secretKD);
	$init($ContentType);
	$init($ChangeCipherSpec);
	$nc($nc(chc->conContext)->consumers)->putIfAbsent($($Byte::valueOf($ContentType::CHANGE_CIPHER_SPEC->id)), $ChangeCipherSpec::t13Consumer);
	$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::ENCRYPTED_EXTENSIONS->id)), $SSLHandshake::ENCRYPTED_EXTENSIONS);
	$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::CERTIFICATE_REQUEST->id)), $SSLHandshake::CERTIFICATE_REQUEST);
	$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::CERTIFICATE->id)), $SSLHandshake::CERTIFICATE);
	$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::CERTIFICATE_VERIFY->id)), $SSLHandshake::CERTIFICATE_VERIFY);
	$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::FINISHED->id)), $SSLHandshake::FINISHED);
}

ServerHello$T13ServerHelloConsumer::ServerHello$T13ServerHelloConsumer() {
}

$Class* ServerHello$T13ServerHelloConsumer::load$($String* name, bool initialize) {
	$loadClass(ServerHello$T13ServerHelloConsumer, name, initialize, &_ServerHello$T13ServerHelloConsumer_ClassInfo_, allocate$ServerHello$T13ServerHelloConsumer);
	return class$;
}

$Class* ServerHello$T13ServerHelloConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun