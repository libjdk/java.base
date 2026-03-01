#include <sun/security/ssl/ClientHello$ClientHelloKickstartProducer.h>

#include <java/security/SecureRandom.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLPeerUnverifiedException.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ClientHello$ClientHelloMessage.h>
#include <sun/security/ssl/ClientHello.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionContextImpl.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/SessionId.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CH_EXTENDED_MASTER_SECRET
#undef CLIENT_HELLO
#undef DTLS12
#undef HELLO_VERIFY_REQUEST
#undef NONE
#undef SERVER_HELLO
#undef TLS12
#undef TLS_EMPTY_RENEGOTIATION_INFO_SCSV

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $CipherSuiteArray = $Array<::sun::security::ssl::CipherSuite>;
using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLPeerUnverifiedException = ::javax::net::ssl::SSLPeerUnverifiedException;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ClientHello$ClientHelloMessage = ::sun::security::ssl::ClientHello$ClientHelloMessage;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionContextImpl = ::sun::security::ssl::SSLSessionContextImpl;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTransport = ::sun::security::ssl::SSLTransport;
using $SessionId = ::sun::security::ssl::SessionId;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ClientHello$ClientHelloKickstartProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ClientHello$ClientHelloKickstartProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;)[B", nullptr, $PUBLIC, $virtualMethod(ClientHello$ClientHelloKickstartProducer, produce, $bytes*, $ConnectionContext*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ClientHello$ClientHelloKickstartProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ClientHello$ClientHelloKickstartProducer", "sun.security.ssl.ClientHello", "ClientHelloKickstartProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ClientHello$ClientHelloKickstartProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ClientHello$ClientHelloKickstartProducer",
	"java.lang.Object",
	"sun.security.ssl.SSLProducer",
	nullptr,
	_ClientHello$ClientHelloKickstartProducer_MethodInfo_,
	nullptr,
	nullptr,
	_ClientHello$ClientHelloKickstartProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ClientHello"
};

$Object* allocate$ClientHello$ClientHelloKickstartProducer($Class* clazz) {
	return $of($alloc(ClientHello$ClientHelloKickstartProducer));
}

void ClientHello$ClientHelloKickstartProducer::init$() {
}

$bytes* ClientHello$ClientHelloKickstartProducer::produce($ConnectionContext* context) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$init($SSLHandshake);
	$nc($nc(chc)->handshakeProducers)->remove($($Byte::valueOf($SSLHandshake::CLIENT_HELLO->id)));
	$ProtocolVersion* maxProtocolVersion = chc->maximumActiveProtocol;
	$var($SessionId, sessionId, $new($SessionId, $$new($bytes, 0)));
	$var($List, cipherSuites, chc->activeCipherSuites);
	$var($SSLSessionContextImpl, ssci, $cast($SSLSessionContextImpl, $nc(chc->sslContext)->engineGetClientSessionContext()));
	$var($String, var$0, $nc($nc(chc->conContext)->transport)->getPeerHost());
	$var($SSLSessionImpl, session, $nc(ssci)->get(var$0, $nc($nc(chc->conContext)->transport)->getPeerPort()));
	if (session != nullptr) {
		$init($ClientHandshakeContext);
		if (!$ClientHandshakeContext::allowUnsafeServerCertChange && session->isSessionResumption()) {
			try {
				$set(chc, reservedServerCerts, $fcast($X509CertificateArray, session->getPeerCertificates()));
			} catch ($SSLPeerUnverifiedException& puve) {
			}
		}
		if (!session->isRejoinable()) {
			$assign(session, nullptr);
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest("Can\'t resume, the session is not rejoinable"_s, $$new($ObjectArray, 0));
			}
		}
	}
	$CipherSuite* sessionSuite = nullptr;
	if (session != nullptr) {
		sessionSuite = session->getSuite();
		if (!chc->isNegotiable(sessionSuite)) {
			$assign(session, nullptr);
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest("Can\'t resume, unavailable session cipher suite"_s, $$new($ObjectArray, 0));
			}
		}
	}
	$ProtocolVersion* sessionVersion = nullptr;
	if (session != nullptr) {
		sessionVersion = session->getProtocolVersion();
		if (!chc->isNegotiable(sessionVersion)) {
			$assign(session, nullptr);
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest("Can\'t resume, unavailable protocol version"_s, $$new($ObjectArray, 0));
			}
		}
	}
	$init($SSLConfiguration);
	if (session != nullptr && !$nc(sessionVersion)->useTLS13PlusSpec() && $SSLConfiguration::useExtendedMasterSecret) {
		$init($SSLExtension);
		bool isEmsAvailable = $nc(chc->sslConfig)->isAvailable($SSLExtension::CH_EXTENDED_MASTER_SECRET, sessionVersion);
		if (isEmsAvailable && !session->useExtendedMasterSecret && !$SSLConfiguration::allowLegacyResumption) {
			$assign(session, nullptr);
		}
		$init($ClientHandshakeContext);
		if ((session != nullptr) && !$ClientHandshakeContext::allowUnsafeServerCertChange) {
			$var($String, identityAlg, $nc(chc->sslConfig)->identificationProtocol);
			if (identityAlg == nullptr || $nc(identityAlg)->isEmpty()) {
				if (isEmsAvailable) {
					if (!session->useExtendedMasterSecret) {
						$assign(session, nullptr);
					}
				} else {
					$assign(session, nullptr);
				}
			}
		}
	}
	$var($String, identityAlg, $nc(chc->sslConfig)->identificationProtocol);
	if (session != nullptr && identityAlg != nullptr) {
		$var($String, sessionIdentityAlg, session->getIdentificationProtocol());
		if (!identityAlg->equalsIgnoreCase(sessionIdentityAlg)) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest($$str({"Can\'t resume, endpoint id algorithm does not match, requested: "_s, identityAlg, ", cached: "_s, sessionIdentityAlg}), $$new($ObjectArray, 0));
			}
			$assign(session, nullptr);
		}
	}
	if (session != nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest("Try resuming session"_s, $$new($ObjectArray, {$of(session)}));
		}
		if (!$nc($(session->getProtocolVersion()))->useTLS13PlusSpec()) {
			$assign(sessionId, session->getSessionId());
		}
		if (!$nc(maxProtocolVersion)->equals(sessionVersion)) {
			maxProtocolVersion = sessionVersion;
			chc->setVersion(sessionVersion);
		}
		if (!$nc(chc->sslConfig)->enableSessionCreation) {
			bool var$1 = !$nc(chc->conContext)->isNegotiated && !$nc(sessionVersion)->useTLS13PlusSpec();
			$init($CipherSuite);
			if (var$1 && $nc(cipherSuites)->contains($CipherSuite::TLS_EMPTY_RENEGOTIATION_INFO_SCSV)) {
				$assign(cipherSuites, $Arrays::asList($$new($CipherSuiteArray, {
					sessionSuite,
					$CipherSuite::TLS_EMPTY_RENEGOTIATION_INFO_SCSV
				})));
			} else {
				$assign(cipherSuites, $List::of($of(sessionSuite)));
			}
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest("No new session is allowed, so try to resume the session cipher suite only"_s, $$new($ObjectArray, {$of(sessionSuite)}));
			}
		}
		chc->isResumption = true;
		$set(chc, resumingSession, session);
	}
	if (session == nullptr) {
		if (!$nc(chc->sslConfig)->enableSessionCreation) {
			$throwNew($SSLHandshakeException, "No new session is allowed and no existing session can be resumed"_s);
		}
		if ($nc(maxProtocolVersion)->useTLS13PlusSpec() && $SSLConfiguration::useCompatibilityMode) {
			$assign(sessionId, $new($SessionId, true, $($nc(chc->sslContext)->getSecureRandom())));
		}
	}
	$ProtocolVersion* minimumVersion = $ProtocolVersion::NONE;
	{
		$var($Iterator, i$, $nc(chc->activeProtocols)->iterator());
		for (; $nc(i$)->hasNext();) {
			$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
			{
				if (minimumVersion == $ProtocolVersion::NONE || $nc(pv)->compare(minimumVersion) < 0) {
					minimumVersion = pv;
				}
			}
		}
	}
	if (!$nc(minimumVersion)->useTLS13PlusSpec()) {
		$init($CipherSuite);
		if ($nc(chc->conContext)->secureRenegotiation && $nc(cipherSuites)->contains($CipherSuite::TLS_EMPTY_RENEGOTIATION_INFO_SCSV)) {
			$assign(cipherSuites, $new($LinkedList, cipherSuites));
			cipherSuites->remove($of($CipherSuite::TLS_EMPTY_RENEGOTIATION_INFO_SCSV));
		}
	}
	bool negotiable = false;
	{
		$var($Iterator, i$, $nc(cipherSuites)->iterator());
		for (; $nc(i$)->hasNext();) {
			$CipherSuite* suite = $cast($CipherSuite, i$->next());
			{
				if (chc->isNegotiable(suite)) {
					negotiable = true;
					break;
				}
			}
		}
	}
	if (!negotiable) {
		$throwNew($SSLHandshakeException, "No negotiable cipher suite"_s);
	}
	$ProtocolVersion* clientHelloVersion = maxProtocolVersion;
	if ($nc(clientHelloVersion)->useTLS13PlusSpec()) {
		if (clientHelloVersion->isDTLS) {
			clientHelloVersion = $ProtocolVersion::DTLS12;
		} else {
			clientHelloVersion = $ProtocolVersion::TLS12;
		}
	}
	$var($ClientHello$ClientHelloMessage, chm, $new($ClientHello$ClientHelloMessage, chc, $nc(clientHelloVersion)->id, sessionId, cipherSuites, $($nc(chc->sslContext)->getSecureRandom())));
	$set(chc, clientHelloRandom, chm->clientRandom);
	chc->clientHelloVersion = $nc(clientHelloVersion)->id;
	$var($SSLExtensionArray, extTypes, $nc(chc->sslConfig)->getEnabledExtensions($SSLHandshake::CLIENT_HELLO, chc->activeProtocols));
	$nc(chm->extensions)->produce(chc, extTypes);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced ClientHello handshake message"_s, $$new($ObjectArray, {$of(chm)}));
	}
	chm->write(chc->handshakeOutput);
	$nc(chc->handshakeOutput)->flush();
	$set(chc, initialClientHelloMsg, chm);
	$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::SERVER_HELLO->id)), $SSLHandshake::SERVER_HELLO);
	bool var$2 = $nc(chc->sslContext)->isDTLS();
	if (var$2 && !$nc(minimumVersion)->useTLS13PlusSpec()) {
		$nc(chc->handshakeConsumers)->put($($Byte::valueOf($SSLHandshake::HELLO_VERIFY_REQUEST->id)), $SSLHandshake::HELLO_VERIFY_REQUEST);
	}
	return nullptr;
}

ClientHello$ClientHelloKickstartProducer::ClientHello$ClientHelloKickstartProducer() {
}

$Class* ClientHello$ClientHelloKickstartProducer::load$($String* name, bool initialize) {
	$loadClass(ClientHello$ClientHelloKickstartProducer, name, initialize, &_ClientHello$ClientHelloKickstartProducer_ClassInfo_, allocate$ClientHello$ClientHelloKickstartProducer);
	return class$;
}

$Class* ClientHello$ClientHelloKickstartProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun