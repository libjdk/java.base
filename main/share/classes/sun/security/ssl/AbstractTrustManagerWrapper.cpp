#include <sun/security/ssl/AbstractTrustManagerWrapper.h>

#include <java/net/Socket.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <javax/net/ssl/ExtendedSSLSession.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/X509ExtendedTrustManager.h>
#include <javax/net/ssl/X509TrustManager.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLAlgorithmConstraints.h>
#include <sun/security/ssl/X509TrustManagerImpl.h>
#include <sun/security/validator/Validator.h>
#include <jcpp.h>

#undef VAR_TLS_CLIENT
#undef VAR_TLS_SERVER

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Socket = ::java::net::Socket;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $ExtendedSSLSession = ::javax::net::ssl::ExtendedSSLSession;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $X509ExtendedTrustManager = ::javax::net::ssl::X509ExtendedTrustManager;
using $X509TrustManager = ::javax::net::ssl::X509TrustManager;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLAlgorithmConstraints = ::sun::security::ssl::SSLAlgorithmConstraints;
using $X509TrustManagerImpl = ::sun::security::ssl::X509TrustManagerImpl;
using $Validator = ::sun::security::validator::Validator;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _AbstractTrustManagerWrapper_FieldInfo_[] = {
	{"tm", "Ljavax/net/ssl/X509TrustManager;", nullptr, $PRIVATE | $FINAL, $field(AbstractTrustManagerWrapper, tm)},
	{}
};

$MethodInfo _AbstractTrustManagerWrapper_MethodInfo_[] = {
	{"<init>", "(Ljavax/net/ssl/X509TrustManager;)V", nullptr, 0, $method(AbstractTrustManagerWrapper, init$, void, $X509TrustManager*)},
	{"checkAdditionalTrust", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/net/Socket;Z)V", nullptr, $PRIVATE, $method(AbstractTrustManagerWrapper, checkAdditionalTrust, void, $X509CertificateArray*, $String*, $Socket*, bool), "java.security.cert.CertificateException"},
	{"checkAdditionalTrust", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljavax/net/ssl/SSLEngine;Z)V", nullptr, $PRIVATE, $method(AbstractTrustManagerWrapper, checkAdditionalTrust, void, $X509CertificateArray*, $String*, $SSLEngine*, bool), "java.security.cert.CertificateException"},
	{"checkAlgorithmConstraints", "([Ljava/security/cert/X509Certificate;Ljava/security/AlgorithmConstraints;Z)V", nullptr, $PRIVATE, $method(AbstractTrustManagerWrapper, checkAlgorithmConstraints, void, $X509CertificateArray*, $AlgorithmConstraints*, bool), "java.security.cert.CertificateException"},
	{"checkClientTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, checkClientTrusted, void, $X509CertificateArray*, $String*), "java.security.cert.CertificateException"},
	{"checkClientTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/net/Socket;)V", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, checkClientTrusted, void, $X509CertificateArray*, $String*, $Socket*), "java.security.cert.CertificateException"},
	{"checkClientTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljavax/net/ssl/SSLEngine;)V", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, checkClientTrusted, void, $X509CertificateArray*, $String*, $SSLEngine*), "java.security.cert.CertificateException"},
	{"checkServerTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, checkServerTrusted, void, $X509CertificateArray*, $String*), "java.security.cert.CertificateException"},
	{"checkServerTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/net/Socket;)V", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, checkServerTrusted, void, $X509CertificateArray*, $String*, $Socket*), "java.security.cert.CertificateException"},
	{"checkServerTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljavax/net/ssl/SSLEngine;)V", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, checkServerTrusted, void, $X509CertificateArray*, $String*, $SSLEngine*), "java.security.cert.CertificateException"},
	{"getAcceptedIssuers", "()[Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(AbstractTrustManagerWrapper, getAcceptedIssuers, $X509CertificateArray*)},
	{}
};

$ClassInfo _AbstractTrustManagerWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.AbstractTrustManagerWrapper",
	"javax.net.ssl.X509ExtendedTrustManager",
	nullptr,
	_AbstractTrustManagerWrapper_FieldInfo_,
	_AbstractTrustManagerWrapper_MethodInfo_
};

$Object* allocate$AbstractTrustManagerWrapper($Class* clazz) {
	return $of($alloc(AbstractTrustManagerWrapper));
}

void AbstractTrustManagerWrapper::init$($X509TrustManager* tm) {
	$X509ExtendedTrustManager::init$();
	$set(this, tm, tm);
}

void AbstractTrustManagerWrapper::checkClientTrusted($X509CertificateArray* chain, $String* authType) {
	$nc(this->tm)->checkClientTrusted(chain, authType);
}

void AbstractTrustManagerWrapper::checkServerTrusted($X509CertificateArray* chain, $String* authType) {
	$nc(this->tm)->checkServerTrusted(chain, authType);
}

$X509CertificateArray* AbstractTrustManagerWrapper::getAcceptedIssuers() {
	return $nc(this->tm)->getAcceptedIssuers();
}

void AbstractTrustManagerWrapper::checkClientTrusted($X509CertificateArray* chain, $String* authType, $Socket* socket) {
	$nc(this->tm)->checkClientTrusted(chain, authType);
	checkAdditionalTrust(chain, authType, socket, true);
}

void AbstractTrustManagerWrapper::checkServerTrusted($X509CertificateArray* chain, $String* authType, $Socket* socket) {
	$nc(this->tm)->checkServerTrusted(chain, authType);
	checkAdditionalTrust(chain, authType, socket, false);
}

void AbstractTrustManagerWrapper::checkClientTrusted($X509CertificateArray* chain, $String* authType, $SSLEngine* engine) {
	$nc(this->tm)->checkClientTrusted(chain, authType);
	checkAdditionalTrust(chain, authType, engine, true);
}

void AbstractTrustManagerWrapper::checkServerTrusted($X509CertificateArray* chain, $String* authType, $SSLEngine* engine) {
	$nc(this->tm)->checkServerTrusted(chain, authType);
	checkAdditionalTrust(chain, authType, engine, false);
}

void AbstractTrustManagerWrapper::checkAdditionalTrust($X509CertificateArray* chain, $String* authType, $Socket* socket, bool checkClientTrusted) {
	$useLocalCurrentObjectStackCache();
	if (socket != nullptr && socket->isConnected() && $instanceOf($SSLSocket, socket)) {
		$var($SSLSocket, sslSocket, $cast($SSLSocket, socket));
		$var($SSLSession, session, sslSocket->getHandshakeSession());
		if (session == nullptr) {
			$throwNew($CertificateException, "No handshake session"_s);
		}
		$var($String, identityAlg, $nc($(sslSocket->getSSLParameters()))->getEndpointIdentificationAlgorithm());
		if (identityAlg != nullptr && !identityAlg->isEmpty()) {
			$X509TrustManagerImpl::checkIdentity(session, chain, identityAlg, checkClientTrusted);
		}
		$var($AlgorithmConstraints, constraints, nullptr);
		if ($ProtocolVersion::useTLS12PlusSpec($($nc(session)->getProtocol()))) {
			if ($instanceOf($ExtendedSSLSession, session)) {
				$var($ExtendedSSLSession, extSession, $cast($ExtendedSSLSession, session));
				$var($StringArray, peerSupportedSignAlgs, $nc(extSession)->getLocalSupportedSignatureAlgorithms());
				$assign(constraints, $new($SSLAlgorithmConstraints, sslSocket, peerSupportedSignAlgs, true));
			} else {
				$assign(constraints, $new($SSLAlgorithmConstraints, sslSocket, true));
			}
		} else {
			$assign(constraints, $new($SSLAlgorithmConstraints, sslSocket, true));
		}
		checkAlgorithmConstraints(chain, constraints, checkClientTrusted);
	}
}

void AbstractTrustManagerWrapper::checkAdditionalTrust($X509CertificateArray* chain, $String* authType, $SSLEngine* engine, bool checkClientTrusted) {
	$useLocalCurrentObjectStackCache();
	if (engine != nullptr) {
		$var($SSLSession, session, engine->getHandshakeSession());
		if (session == nullptr) {
			$throwNew($CertificateException, "No handshake session"_s);
		}
		$var($String, identityAlg, $nc($(engine->getSSLParameters()))->getEndpointIdentificationAlgorithm());
		if (identityAlg != nullptr && !identityAlg->isEmpty()) {
			$X509TrustManagerImpl::checkIdentity(session, chain, identityAlg, checkClientTrusted);
		}
		$var($AlgorithmConstraints, constraints, nullptr);
		if ($ProtocolVersion::useTLS12PlusSpec($($nc(session)->getProtocol()))) {
			if ($instanceOf($ExtendedSSLSession, session)) {
				$var($ExtendedSSLSession, extSession, $cast($ExtendedSSLSession, session));
				$var($StringArray, peerSupportedSignAlgs, $nc(extSession)->getLocalSupportedSignatureAlgorithms());
				$assign(constraints, $new($SSLAlgorithmConstraints, engine, peerSupportedSignAlgs, true));
			} else {
				$assign(constraints, $new($SSLAlgorithmConstraints, engine, true));
			}
		} else {
			$assign(constraints, $new($SSLAlgorithmConstraints, engine, true));
		}
		checkAlgorithmConstraints(chain, constraints, checkClientTrusted);
	}
}

void AbstractTrustManagerWrapper::checkAlgorithmConstraints($X509CertificateArray* chain, $AlgorithmConstraints* constraints, bool checkClientTrusted) {
	$useLocalCurrentObjectStackCache();
	try {
		int32_t checkedLength = $nc(chain)->length - 1;
		$var($Collection, trustedCerts, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>($new($HashSet)))));
		$var($X509CertificateArray, certs, $nc(this->tm)->getAcceptedIssuers());
		if ((certs != nullptr) && (certs->length > 0)) {
			$Collections::addAll(trustedCerts, certs);
		}
		if (trustedCerts->contains(chain->get(checkedLength))) {
			--checkedLength;
		}
		if (checkedLength >= 0) {
			$init($Validator);
			$var($AlgorithmChecker, checker, $new($AlgorithmChecker, constraints, (checkClientTrusted ? $Validator::VAR_TLS_CLIENT : $Validator::VAR_TLS_SERVER)));
			checker->init(false);
			for (int32_t i = checkedLength; i >= 0; --i) {
				$var($X509Certificate, cert, chain->get(i));
				checker->check(cert, $($Collections::emptySet()));
			}
		}
	} catch ($CertPathValidatorException& cpve) {
		$throwNew($CertificateException, "Certificates do not conform to algorithm constraints"_s, cpve);
	}
}

AbstractTrustManagerWrapper::AbstractTrustManagerWrapper() {
}

$Class* AbstractTrustManagerWrapper::load$($String* name, bool initialize) {
	$loadClass(AbstractTrustManagerWrapper, name, initialize, &_AbstractTrustManagerWrapper_ClassInfo_, allocate$AbstractTrustManagerWrapper);
	return class$;
}

$Class* AbstractTrustManagerWrapper::class$ = nullptr;

		} // ssl
	} // security
} // sun