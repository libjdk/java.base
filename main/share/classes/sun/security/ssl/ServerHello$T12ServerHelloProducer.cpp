#include <sun/security/ssl/ServerHello$T12ServerHelloProducer.h>

#include <java/lang/Enum.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/SecureRandom.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/EnumSet.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Set.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/HandshakeProducer.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/ServerHello$ServerHelloMessage.h>
#include <sun/security/ssl/ServerHello$T12ServerHelloProducer$KeyExchangeProperties.h>
#include <sun/security/ssl/ServerHello.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/StatusResponseManager$StaplingParameters.h>
#include <sun/security/ssl/StatusResponseManager.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CERTIFICATE
#undef CERTIFICATE_REQUEST
#undef CLIENT_AUTH_NONE
#undef CLIENT_AUTH_REQUIRED
#undef CLIENT_HELLO
#undef C_NULL
#undef FINISHED
#undef HANDSHAKE_FAILURE
#undef INTERNAL_ERROR
#undef KEY_AGREEMENT
#undef K_DH_ANON
#undef K_ECDH_ANON
#undef SERVER_HELLO
#undef SERVER_HELLO_DONE

using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $SSLHandshakeArray = $Array<::sun::security::ssl::SSLHandshake>;
using $SSLPossessionArray = $Array<::sun::security::ssl::SSLPossession>;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $EnumSet = ::java::util::EnumSet;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $SSLException = ::javax::net::ssl::SSLException;
using $Alert = ::sun::security::ssl::Alert;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $CipherSuite$KeyExchange = ::sun::security::ssl::CipherSuite$KeyExchange;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $HandshakeProducer = ::sun::security::ssl::HandshakeProducer;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $RandomCookie = ::sun::security::ssl::RandomCookie;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyExchange = ::sun::security::ssl::SSLKeyExchange;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $ServerHello$ServerHelloMessage = ::sun::security::ssl::ServerHello$ServerHelloMessage;
using $ServerHello$T12ServerHelloProducer$KeyExchangeProperties = ::sun::security::ssl::ServerHello$T12ServerHelloProducer$KeyExchangeProperties;
using $SessionId = ::sun::security::ssl::SessionId;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $StatusResponseManager = ::sun::security::ssl::StatusResponseManager;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ServerHello$T12ServerHelloProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ServerHello$T12ServerHelloProducer, init$, void)},
	{"chooseCipherSuite", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/ClientHello$ClientHelloMessage;)Lsun/security/ssl/ServerHello$T12ServerHelloProducer$KeyExchangeProperties;", nullptr, $PRIVATE | $STATIC, $staticMethod(ServerHello$T12ServerHelloProducer, chooseCipherSuite, $ServerHello$T12ServerHelloProducer$KeyExchangeProperties*, $ServerHandshakeContext*, $ClientHello$ClientHelloMessage*), "java.io.IOException"},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(ServerHello$T12ServerHelloProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ServerHello$T12ServerHelloProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerHello$T12ServerHelloProducer", "sun.security.ssl.ServerHello", "T12ServerHelloProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T12ServerHelloProducer$KeyExchangeProperties", "sun.security.ssl.ServerHello$T12ServerHelloProducer", "KeyExchangeProperties", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ServerHello$T12ServerHelloProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerHello$T12ServerHelloProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_ServerHello$T12ServerHelloProducer_MethodInfo_,
	nullptr,
	nullptr,
	_ServerHello$T12ServerHelloProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerHello"
};

$Object* allocate$ServerHello$T12ServerHelloProducer($Class* clazz) {
	return $of($alloc(ServerHello$T12ServerHelloProducer));
}

void ServerHello$T12ServerHelloProducer::init$() {
}

$bytes* ServerHello$T12ServerHelloProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$var($ClientHello$ClientHelloMessage, clientHello, $cast($ClientHello$ClientHelloMessage, message));
	if (!$nc(shc)->isResumption || $nc(shc)->resumingSession == nullptr) {
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
		$var($ServerHello$T12ServerHelloProducer$KeyExchangeProperties, credentials, chooseCipherSuite(shc, clientHello));
		if (credentials == nullptr) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "no cipher suites in common"_s)));
		}
		$set(shc, negotiatedCipherSuite, $nc(credentials)->cipherSuite);
		$set(shc, handshakeKeyExchange, credentials->keyExchange);
		$nc(shc->handshakeSession)->setSuite(credentials->cipherSuite);
		$nc(shc->handshakePossessions)->addAll($($Arrays::asList(credentials->possessions)));
		$nc(shc->handshakeHash)->determine(shc->negotiatedProtocol, shc->negotiatedCipherSuite);
		$set(shc, stapleParams, $StatusResponseManager::processStapling(shc));
		shc->staplingActive = (shc->stapleParams != nullptr);
		$var($SSLKeyExchange, ke, credentials->keyExchange);
		if (ke != nullptr) {
			{
				$var($Map$EntryArray, arr$, ke->getHandshakeProducers(shc));
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Map$Entry, me, arr$->get(i$));
					{
						$var($Object, var$0, $cast($Byte, $nc(me)->getKey()));
						$nc(shc->handshakeProducers)->put(var$0, $cast($HandshakeProducer, $(me->getValue())));
					}
				}
			}
		}
		$init($ClientAuthType);
		if ((ke != nullptr) && ($nc(shc->sslConfig)->clientAuthType != $ClientAuthType::CLIENT_AUTH_NONE) && !$nc(shc->negotiatedCipherSuite)->isAnonymous()) {
			{
				$var($SSLHandshakeArray, arr$, ke->getRelatedHandshakers(shc));
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$SSLHandshake* hs = arr$->get(i$);
					{
						if (hs == $SSLHandshake::CERTIFICATE) {
							$nc(shc->handshakeProducers)->put($($Byte::valueOf($SSLHandshake::CERTIFICATE_REQUEST->id)), $SSLHandshake::CERTIFICATE_REQUEST);
							break;
						}
					}
				}
			}
		}
		$nc(shc->handshakeProducers)->put($($Byte::valueOf($SSLHandshake::SERVER_HELLO_DONE->id)), $SSLHandshake::SERVER_HELLO_DONE);
	} else {
		if (shc->statelessResumption) {
			$set(shc, resumingSession, $new($SSLSessionImpl, shc->resumingSession, ($nc($nc(clientHello)->sessionId)->length() == 0) ? $$new($SessionId, true, $($nc(shc->sslContext)->getSecureRandom())) : $$new($SessionId, $($nc($nc(clientHello)->sessionId)->getId()))));
		}
		$set(shc, handshakeSession, shc->resumingSession);
		$set(shc, negotiatedProtocol, $nc(shc->resumingSession)->getProtocolVersion());
		$set(shc, negotiatedCipherSuite, $nc(shc->resumingSession)->getSuite());
		$nc(shc->handshakeHash)->determine(shc->negotiatedProtocol, shc->negotiatedCipherSuite);
	}
	$var($HandshakeContext, var$1, static_cast<$HandshakeContext*>(shc));
	$var($ProtocolVersion, var$2, $nc(shc)->negotiatedProtocol);
	$var($SessionId, var$3, $nc(shc->handshakeSession)->getSessionId());
	$var($CipherSuite, var$4, shc->negotiatedCipherSuite);
	$var($ServerHello$ServerHelloMessage, shm, $new($ServerHello$ServerHelloMessage, var$1, var$2, var$3, var$4, $$new($RandomCookie, static_cast<$HandshakeContext*>(shc)), clientHello));
	$set($nc(shc), serverHelloRandom, shm->serverRandom);
	$init($SSLHandshake);
	$var($SSLExtensionArray, serverHelloExtensions, $nc(shc->sslConfig)->getEnabledExtensions($SSLHandshake::SERVER_HELLO, shc->negotiatedProtocol));
	$nc(shm->extensions)->produce(shc, serverHelloExtensions);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced ServerHello handshake message"_s, $$new($ObjectArray, {$of(shm)}));
	}
	shm->write(shc->handshakeOutput);
	$nc(shc->handshakeOutput)->flush();
	if (shc->isResumption && shc->resumingSession != nullptr) {
		$SSLTrafficKeyDerivation* kdg = $SSLTrafficKeyDerivation::valueOf(shc->negotiatedProtocol);
		if (kdg == nullptr) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, shc->negotiatedProtocol}))));
		} else {
			$set(shc, handshakeKeyDerivation, $nc(kdg)->createKeyDerivation(shc, $($nc(shc->resumingSession)->getMasterSecret())));
		}
		$nc(shc->handshakeProducers)->put($($Byte::valueOf($SSLHandshake::FINISHED->id)), $SSLHandshake::FINISHED);
	}
	return nullptr;
}

$ServerHello$T12ServerHelloProducer$KeyExchangeProperties* ServerHello$T12ServerHelloProducer::chooseCipherSuite($ServerHandshakeContext* shc, $ClientHello$ClientHelloMessage* clientHello) {
	$init(ServerHello$T12ServerHelloProducer);
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
	$var($List, legacySuites, $new($LinkedList));
	{
		$var($Iterator, i$, $nc(preferred)->iterator());
		for (; $nc(i$)->hasNext();) {
			$CipherSuite* cs = $cast($CipherSuite, i$->next());
			{
				if (!$HandshakeContext::isNegotiable(proposed, $nc(shc)->negotiatedProtocol, cs)) {
					continue;
				}
				$init($ClientAuthType);
				if ($nc($nc(shc)->sslConfig)->clientAuthType == $ClientAuthType::CLIENT_AUTH_REQUIRED) {
					$init($CipherSuite$KeyExchange);
					if (($nc(cs)->keyExchange == $CipherSuite$KeyExchange::K_DH_ANON) || ($nc(cs)->keyExchange == $CipherSuite$KeyExchange::K_ECDH_ANON)) {
						continue;
					}
				}
				$var($SSLKeyExchange, ke, $SSLKeyExchange::valueOf($nc(cs)->keyExchange, $nc(shc)->negotiatedProtocol));
				if (ke == nullptr) {
					continue;
				}
				$init($ServerHandshakeContext);
				$init($CryptoPrimitive);
				if (!$nc($ServerHandshakeContext::legacyAlgorithmConstraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), $nc(cs)->name$, nullptr)) {
					legacySuites->add(cs);
					continue;
				}
				$var($SSLPossessionArray, hcds, $nc(ke)->createPossessions(shc));
				if ((hcds == nullptr) || ($nc(hcds)->length == 0)) {
					continue;
				}
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine($$str({"use cipher suite "_s, $nc(cs)->name$}), $$new($ObjectArray, 0));
				}
				return $new($ServerHello$T12ServerHelloProducer$KeyExchangeProperties, cs, ke, hcds);
			}
		}
	}
	{
		$var($Iterator, i$, legacySuites->iterator());
		for (; $nc(i$)->hasNext();) {
			$CipherSuite* cs = $cast($CipherSuite, i$->next());
			{
				$var($SSLKeyExchange, ke, $SSLKeyExchange::valueOf($nc(cs)->keyExchange, $nc(shc)->negotiatedProtocol));
				if (ke != nullptr) {
					$var($SSLPossessionArray, hcds, ke->createPossessions(shc));
					if ((hcds != nullptr) && (hcds->length != 0)) {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
							$SSLLogger::warning($$str({"use legacy cipher suite "_s, $nc(cs)->name$}), $$new($ObjectArray, 0));
						}
						return $new($ServerHello$T12ServerHelloProducer$KeyExchangeProperties, cs, ke, hcds);
					}
				}
			}
		}
	}
	$init($Alert);
	$throw($($nc($nc(shc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "no cipher suites in common"_s)));
}

ServerHello$T12ServerHelloProducer::ServerHello$T12ServerHelloProducer() {
}

$Class* ServerHello$T12ServerHelloProducer::load$($String* name, bool initialize) {
	$loadClass(ServerHello$T12ServerHelloProducer, name, initialize, &_ServerHello$T12ServerHelloProducer_ClassInfo_, allocate$ServerHello$T12ServerHelloProducer);
	return class$;
}

$Class* ServerHello$T12ServerHelloProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun