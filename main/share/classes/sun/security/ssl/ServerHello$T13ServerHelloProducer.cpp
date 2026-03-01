#include <sun/security/ssl/ServerHello$T13ServerHelloProducer.h>

#include <java/lang/Enum.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/EnumSet.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <sun/security/ssl/SSLSessionContextImpl.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/ServerHello$ServerHelloMessage.h>
#include <sun/security/ssl/ServerHello.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CLIENT_HELLO
#undef C_NULL
#undef ENCRYPTED_EXTENSIONS
#undef FINISHED
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR
#undef KEY_AGREEMENT
#undef SERVER_HELLO
#undef TLS12

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $EnumSet = ::java::util::EnumSet;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SSLException = ::javax::net::ssl::SSLException;
using $Alert = ::sun::security::ssl::Alert;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $RandomCookie = ::sun::security::ssl::RandomCookie;
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
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;
using $SSLSessionContextImpl = ::sun::security::ssl::SSLSessionContextImpl;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $ServerHello = ::sun::security::ssl::ServerHello;
using $ServerHello$ServerHelloMessage = ::sun::security::ssl::ServerHello$ServerHelloMessage;
using $SessionId = ::sun::security::ssl::SessionId;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ServerHello$T13ServerHelloProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ServerHello$T13ServerHelloProducer, init$, void)},
	{"chooseCipherSuite", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/ClientHello$ClientHelloMessage;)Lsun/security/ssl/CipherSuite;", nullptr, $PRIVATE | $STATIC, $staticMethod(ServerHello$T13ServerHelloProducer, chooseCipherSuite, $CipherSuite*, $ServerHandshakeContext*, $ClientHello$ClientHelloMessage*), "java.io.IOException"},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(ServerHello$T13ServerHelloProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ServerHello$T13ServerHelloProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerHello$T13ServerHelloProducer", "sun.security.ssl.ServerHello", "T13ServerHelloProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ServerHello$T13ServerHelloProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerHello$T13ServerHelloProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_ServerHello$T13ServerHelloProducer_MethodInfo_,
	nullptr,
	nullptr,
	_ServerHello$T13ServerHelloProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerHello"
};

$Object* allocate$ServerHello$T13ServerHelloProducer($Class* clazz) {
	return $of($alloc(ServerHello$T13ServerHelloProducer));
}

void ServerHello$T13ServerHelloProducer::init$() {
}

$bytes* ServerHello$T13ServerHelloProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$var($ClientHello$ClientHelloMessage, clientHello, $cast($ClientHello$ClientHelloMessage, message));
	$var($SSLSessionContextImpl, sessionCache, $cast($SSLSessionContextImpl, $nc($nc(shc)->sslContext)->engineGetServerSessionContext()));
	if (!shc->isResumption || shc->resumingSession == nullptr) {
		if (!$nc(shc->sslConfig)->enableSessionCreation) {
			$throwNew($SSLException, "Not resumption, and no new session is allowed"_s);
		}
		if (shc->localSupportedSignAlgs == nullptr) {
			$set(shc, localSupportedSignAlgs, $SignatureScheme::getSupportedAlgorithms(shc->sslConfig, shc->algorithmConstraints, shc->activeProtocols));
		}
		$init($CipherSuite);
		$var($SSLSessionImpl, session, $new($SSLSessionImpl, static_cast<$HandshakeContext*>(shc), $CipherSuite::C_NULL));
		session->setMaximumPacketSize($nc(shc->sslConfig)->maximumPacketSize);
		$set(shc, handshakeSession, session);
		$init($SSLHandshake);
		$var($SSLExtensionArray, enabledExtensions, $nc(shc->sslConfig)->getEnabledExtensions($SSLHandshake::CLIENT_HELLO, shc->negotiatedProtocol));
		$nc($nc(clientHello)->extensions)->consumeOnTrade(shc, enabledExtensions);
		$CipherSuite* cipherSuite = chooseCipherSuite(shc, clientHello);
		if (cipherSuite == nullptr) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "no cipher suites in common"_s)));
		}
		$set(shc, negotiatedCipherSuite, cipherSuite);
		$nc(shc->handshakeSession)->setSuite(cipherSuite);
		$nc(shc->handshakeHash)->determine(shc->negotiatedProtocol, shc->negotiatedCipherSuite);
	} else {
		$set(shc, handshakeSession, shc->resumingSession);
		$init($SSLHandshake);
		$var($SSLExtensionArray, enabledExtensions, $nc(shc->sslConfig)->getEnabledExtensions($SSLHandshake::CLIENT_HELLO, shc->negotiatedProtocol));
		$nc($nc(clientHello)->extensions)->consumeOnTrade(shc, enabledExtensions);
		$set(shc, negotiatedProtocol, $nc(shc->resumingSession)->getProtocolVersion());
		$set(shc, negotiatedCipherSuite, $nc(shc->resumingSession)->getSuite());
		$nc(shc->handshakeHash)->determine(shc->negotiatedProtocol, shc->negotiatedCipherSuite);
		$ServerHello::setUpPskKD(shc, $($nc(shc->resumingSession)->consumePreSharedKey()));
	}
	$init($SSLHandshake);
	$nc(shc->handshakeProducers)->put($($Byte::valueOf($SSLHandshake::ENCRYPTED_EXTENSIONS->id)), $SSLHandshake::ENCRYPTED_EXTENSIONS);
	$nc(shc->handshakeProducers)->put($($Byte::valueOf($SSLHandshake::FINISHED->id)), $SSLHandshake::FINISHED);
	$init($ProtocolVersion);
	$var($ServerHello$ServerHelloMessage, shm, $new($ServerHello$ServerHelloMessage, shc, $ProtocolVersion::TLS12, $nc(clientHello)->sessionId, shc->negotiatedCipherSuite, $$new($RandomCookie, static_cast<$HandshakeContext*>(shc)), clientHello));
	$set(shc, serverHelloRandom, shm->serverRandom);
	$var($SSLExtensionArray, serverHelloExtensions, $nc(shc->sslConfig)->getEnabledExtensions($SSLHandshake::SERVER_HELLO, shc->negotiatedProtocol));
	$nc(shm->extensions)->produce(shc, serverHelloExtensions);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced ServerHello handshake message"_s, $$new($ObjectArray, {$of(shm)}));
	}
	shm->write(shc->handshakeOutput);
	$nc(shc->handshakeOutput)->flush();
	$nc(shc->handshakeHash)->update();
	$var($SSLKeyExchange, ke, shc->handshakeKeyExchange);
	if (ke == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, "Not negotiated key shares"_s)));
	}
	$var($SSLKeyDerivation, handshakeKD, $nc(ke)->createKeyDerivation(shc));
	$var($SecretKey, handshakeSecret, $nc(handshakeKD)->deriveKey("TlsHandshakeSecret"_s, nullptr));
	$SSLTrafficKeyDerivation* kdg = $SSLTrafficKeyDerivation::valueOf(shc->negotiatedProtocol);
	if (kdg == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, shc->negotiatedProtocol}))));
	}
	$var($SSLKeyDerivation, kd, $new($SSLSecretDerivation, shc, handshakeSecret));
	$var($SecretKey, readSecret, kd->deriveKey("TlsClientHandshakeTrafficSecret"_s, nullptr));
	$var($SSLKeyDerivation, readKD, $nc(kdg)->createKeyDerivation(shc, readSecret));
	$var($SecretKey, readKey, $nc(readKD)->deriveKey("TlsKey"_s, nullptr));
	$var($SecretKey, readIvSecret, readKD->deriveKey("TlsIv"_s, nullptr));
	$var($IvParameterSpec, readIv, $new($IvParameterSpec, $($nc(readIvSecret)->getEncoded())));
	$var($SSLCipher$SSLReadCipher, readCipher, nullptr);
	try {
		$var($Authenticator, var$0, $Authenticator::valueOf(shc->negotiatedProtocol));
		$var($ProtocolVersion, var$1, shc->negotiatedProtocol);
		$var($SecretKey, var$2, readKey);
		$var($IvParameterSpec, var$3, readIv);
		$assign(readCipher, $nc(shc->negotiatedCipherSuite)->bulkCipher->createReadCipher(var$0, var$1, var$2, var$3, $($nc(shc->sslContext)->getSecureRandom())));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Missing cipher algorithm"_s, gse)));
	}
	if (readCipher == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, shc->negotiatedCipherSuite, ") and protocol version ("_s, shc->negotiatedProtocol, ")"_s}))));
	}
	$set(shc, baseReadSecret, readSecret);
	$nc($nc(shc->conContext)->inputRecord)->changeReadCiphers(readCipher);
	$var($SecretKey, writeSecret, kd->deriveKey("TlsServerHandshakeTrafficSecret"_s, nullptr));
	$var($SSLKeyDerivation, writeKD, kdg->createKeyDerivation(shc, writeSecret));
	$var($SecretKey, writeKey, $nc(writeKD)->deriveKey("TlsKey"_s, nullptr));
	$var($SecretKey, writeIvSecret, writeKD->deriveKey("TlsIv"_s, nullptr));
	$var($IvParameterSpec, writeIv, $new($IvParameterSpec, $($nc(writeIvSecret)->getEncoded())));
	$var($SSLCipher$SSLWriteCipher, writeCipher, nullptr);
	try {
		$var($Authenticator, var$4, $Authenticator::valueOf(shc->negotiatedProtocol));
		$var($ProtocolVersion, var$5, shc->negotiatedProtocol);
		$var($SecretKey, var$6, writeKey);
		$var($IvParameterSpec, var$7, writeIv);
		$assign(writeCipher, $nc(shc->negotiatedCipherSuite)->bulkCipher->createWriteCipher(var$4, var$5, var$6, var$7, $($nc(shc->sslContext)->getSecureRandom())));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Missing cipher algorithm"_s, gse)));
	}
	if (writeCipher == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, shc->negotiatedCipherSuite, ") and protocol version ("_s, shc->negotiatedProtocol, ")"_s}))));
	}
	$set(shc, baseWriteSecret, writeSecret);
	$nc($nc(shc->conContext)->outputRecord)->changeWriteCiphers(writeCipher, ($nc($nc(clientHello)->sessionId)->length() != 0));
	$set(shc, handshakeKeyDerivation, kd);
	if ($nc(sessionCache)->statelessEnabled()) {
		shc->statelessResumption = true;
	}
	return nullptr;
}

$CipherSuite* ServerHello$T13ServerHelloProducer::chooseCipherSuite($ServerHandshakeContext* shc, $ClientHello$ClientHelloMessage* clientHello) {
	$init(ServerHello$T13ServerHelloProducer);
	$useLocalCurrentObjectStackCache();
	$var($List, preferred, nullptr);
	$var($List, proposed, nullptr);
	if ($nc($nc(shc)->sslConfig)->preferLocalCipherSuites) {
		$assign(preferred, shc->activeCipherSuites);
		$assign(proposed, $nc(clientHello)->cipherSuites);
	} else {
		$assign(preferred, $nc(clientHello)->cipherSuites);
		$assign(proposed, shc->activeCipherSuites);
	}
	$CipherSuite* legacySuite = nullptr;
	$init($ServerHandshakeContext);
	$var($AlgorithmConstraints, legacyConstraints, $ServerHandshakeContext::legacyAlgorithmConstraints);
	{
		$var($Iterator, i$, $nc(preferred)->iterator());
		for (; $nc(i$)->hasNext();) {
			$CipherSuite* cs = $cast($CipherSuite, i$->next());
			{
				if (!$HandshakeContext::isNegotiable(proposed, $nc(shc)->negotiatedProtocol, cs)) {
					continue;
				}
				$init($CryptoPrimitive);
				if ((legacySuite == nullptr) && !$nc(legacyConstraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), $nc(cs)->name$, nullptr)) {
					legacySuite = cs;
					continue;
				}
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine($$str({"use cipher suite "_s, $nc(cs)->name$}), $$new($ObjectArray, 0));
				}
				return cs;
			}
		}
	}
	if (legacySuite != nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::warning($$str({"use legacy cipher suite "_s, legacySuite->name$}), $$new($ObjectArray, 0));
		}
		return legacySuite;
	}
	return nullptr;
}

ServerHello$T13ServerHelloProducer::ServerHello$T13ServerHelloProducer() {
}

$Class* ServerHello$T13ServerHelloProducer::load$($String* name, bool initialize) {
	$loadClass(ServerHello$T13ServerHelloProducer, name, initialize, &_ServerHello$T13ServerHelloProducer_ClassInfo_, allocate$ServerHello$T13ServerHelloProducer);
	return class$;
}

$Class* ServerHello$T13ServerHelloProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun