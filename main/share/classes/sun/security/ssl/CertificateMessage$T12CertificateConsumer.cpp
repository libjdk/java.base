#include <sun/security/ssl/CertificateMessage$T12CertificateConsumer.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/InputStream.h>
#include <java/net/Socket.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPathValidatorException$BasicReason.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/CertificateParsingException.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/X509ExtendedTrustManager.h>
#include <javax/net/ssl/X509TrustManager.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertificateMessage$T12CertificateMessage.h>
#include <sun/security/ssl/CertificateMessage.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <jcpp.h>

#undef ALGORITHM_CONSTRAINED
#undef BAD_CERTIFICATE
#undef BAD_CERT_STATUS_RESPONSE
#undef CERTIFICATE
#undef CERTIFICATE_EXPIRED
#undef CERTIFICATE_REVOKED
#undef CERTIFICATE_UNKNOWN
#undef CERTIFICATE_VERIFY
#undef CLIENT_AUTH_REQUESTED
#undef EXPIRED
#undef INVALID_SIGNATURE
#undef K_DHE_RSA_EXPORT
#undef K_RSA
#undef K_RSA_EXPORT
#undef NOT_YET_VALID
#undef REVOKED
#undef UNDETERMINED_REVOCATION_STATUS
#undef UNSUPPORTED_CERTIFICATE

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $InputStream = ::java::io::InputStream;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Socket = ::java::net::Socket;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $PublicKey = ::java::security::PublicKey;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$BasicReason = ::java::security::cert::CertPathValidatorException$BasicReason;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $CertificateParsingException = ::java::security::cert::CertificateParsingException;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $X509ExtendedTrustManager = ::javax::net::ssl::X509ExtendedTrustManager;
using $X509TrustManager = ::javax::net::ssl::X509TrustManager;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $Alert = ::sun::security::ssl::Alert;
using $CertificateMessage$T12CertificateMessage = ::sun::security::ssl::CertificateMessage$T12CertificateMessage;
using $CipherSuite$KeyExchange = ::sun::security::ssl::CipherSuite$KeyExchange;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _CertificateMessage$T12CertificateConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(CertificateMessage$T12CertificateConsumer, init$, void)},
	{"checkClientCerts", "(Lsun/security/ssl/ServerHandshakeContext;[Ljava/security/cert/X509Certificate;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T12CertificateConsumer, checkClientCerts, void, $ServerHandshakeContext*, $X509CertificateArray*), "java.io.IOException"},
	{"checkServerCerts", "(Lsun/security/ssl/ClientHandshakeContext;[Ljava/security/cert/X509Certificate;)V", nullptr, $STATIC, $staticMethod(CertificateMessage$T12CertificateConsumer, checkServerCerts, void, $ClientHandshakeContext*, $X509CertificateArray*), "java.io.IOException"},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T12CertificateConsumer, consume, void, $ConnectionContext*, $ByteBuffer*), "java.io.IOException"},
	{"getCertificateAlert", "(Lsun/security/ssl/ClientHandshakeContext;Ljava/security/cert/CertificateException;)Lsun/security/ssl/Alert;", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T12CertificateConsumer, getCertificateAlert, $Alert*, $ClientHandshakeContext*, $CertificateException*)},
	{"getSubjectAltNames", "(Ljava/util/Collection;I)Ljava/util/Collection;", "(Ljava/util/Collection<Ljava/util/List<*>;>;I)Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T12CertificateConsumer, getSubjectAltNames, $Collection*, $Collection*, int32_t)},
	{"isEquivalent", "(Ljava/util/Collection;Ljava/util/Collection;)Z", "(Ljava/util/Collection<Ljava/lang/String;>;Ljava/util/Collection<Ljava/lang/String;>;)Z", $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T12CertificateConsumer, isEquivalent, bool, $Collection*, $Collection*)},
	{"isIdentityEquivalent", "(Ljava/security/cert/X509Certificate;Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T12CertificateConsumer, isIdentityEquivalent, bool, $X509Certificate*, $X509Certificate*)},
	{"onCertificate", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/CertificateMessage$T12CertificateMessage;)V", nullptr, $PRIVATE, $method(CertificateMessage$T12CertificateConsumer, onCertificate, void, $ServerHandshakeContext*, $CertificateMessage$T12CertificateMessage*), "java.io.IOException"},
	{"onCertificate", "(Lsun/security/ssl/ClientHandshakeContext;Lsun/security/ssl/CertificateMessage$T12CertificateMessage;)V", nullptr, $PRIVATE, $method(CertificateMessage$T12CertificateConsumer, onCertificate, void, $ClientHandshakeContext*, $CertificateMessage$T12CertificateMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _CertificateMessage$T12CertificateConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateMessage$T12CertificateConsumer", "sun.security.ssl.CertificateMessage", "T12CertificateConsumer", $STATIC | $FINAL},
	{}
};

$ClassInfo _CertificateMessage$T12CertificateConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateMessage$T12CertificateConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLConsumer",
	nullptr,
	_CertificateMessage$T12CertificateConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateMessage$T12CertificateConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateMessage"
};

$Object* allocate$CertificateMessage$T12CertificateConsumer($Class* clazz) {
	return $of($alloc(CertificateMessage$T12CertificateConsumer));
}

void CertificateMessage$T12CertificateConsumer::init$() {
}

void CertificateMessage$T12CertificateConsumer::consume($ConnectionContext* context, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	$var($HandshakeContext, hc, $cast($HandshakeContext, context));
	$init($SSLHandshake);
	$nc($nc(hc)->handshakeConsumers)->remove($($Byte::valueOf($SSLHandshake::CERTIFICATE->id)));
	$var($CertificateMessage$T12CertificateMessage, cm, $new($CertificateMessage$T12CertificateMessage, hc, message));
	if ($nc(hc->sslConfig)->isClientMode) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Consuming server Certificate handshake message"_s, $$new($ObjectArray, {$of(cm)}));
		}
		onCertificate($cast($ClientHandshakeContext, context), cm);
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Consuming client Certificate handshake message"_s, $$new($ObjectArray, {$of(cm)}));
		}
		onCertificate($cast($ServerHandshakeContext, context), cm);
	}
}

void CertificateMessage$T12CertificateConsumer::onCertificate($ServerHandshakeContext* shc, $CertificateMessage$T12CertificateMessage* certificateMessage) {
	$useLocalCurrentObjectStackCache();
	$var($List, encodedCerts, $nc(certificateMessage)->encodedCertChain);
	if (encodedCerts == nullptr || $nc(encodedCerts)->isEmpty()) {
		$init($SSLHandshake);
		$nc($nc(shc)->handshakeConsumers)->remove($($Byte::valueOf($SSLHandshake::CERTIFICATE_VERIFY->id)));
		$init($ClientAuthType);
		if ($nc(shc->sslConfig)->clientAuthType != $ClientAuthType::CLIENT_AUTH_REQUESTED) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::BAD_CERTIFICATE, "Empty server certificate chain"_s)));
		} else {
			return;
		}
	}
	$var($X509CertificateArray, x509Certs, $new($X509CertificateArray, $nc(encodedCerts)->size()));
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		int32_t i = 0;
		{
			$var($Iterator, i$, encodedCerts->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($bytes, encodedCert, $cast($bytes, i$->next()));
				{
					x509Certs->set(i++, $cast($X509Certificate, $($nc(cf)->generateCertificate($$new($ByteArrayInputStream, encodedCert)))));
				}
			}
		}
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Failed to parse server certificates"_s, ce)));
	}
	checkClientCerts(shc, x509Certs);
	$nc($nc(shc)->handshakeCredentials)->add($$new($X509Authentication$X509Credentials, $($nc(x509Certs->get(0))->getPublicKey()), x509Certs));
	$nc(shc->handshakeSession)->setPeerCertificates(x509Certs);
}

void CertificateMessage$T12CertificateConsumer::onCertificate($ClientHandshakeContext* chc, $CertificateMessage$T12CertificateMessage* certificateMessage) {
	$useLocalCurrentObjectStackCache();
	$var($List, encodedCerts, $nc(certificateMessage)->encodedCertChain);
	if (encodedCerts == nullptr || $nc(encodedCerts)->isEmpty()) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Empty server certificate chain"_s)));
	}
	$var($X509CertificateArray, x509Certs, $new($X509CertificateArray, $nc(encodedCerts)->size()));
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		int32_t i = 0;
		{
			$var($Iterator, i$, encodedCerts->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($bytes, encodedCert, $cast($bytes, i$->next()));
				{
					x509Certs->set(i++, $cast($X509Certificate, $($nc(cf)->generateCertificate($$new($ByteArrayInputStream, encodedCert)))));
				}
			}
		}
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Failed to parse server certificates"_s, ce)));
	}
	if ($nc(chc)->reservedServerCerts != nullptr && !$nc(chc->handshakeSession)->useExtendedMasterSecret) {
		$var($String, identityAlg, $nc(chc->sslConfig)->identificationProtocol);
		bool var$0 = (identityAlg == nullptr || $nc(identityAlg)->isEmpty());
		if (var$0 && !isIdentityEquivalent(x509Certs->get(0), $nc(chc->reservedServerCerts)->get(0))) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::BAD_CERTIFICATE, "server certificate change is restricted during renegotiation"_s)));
		}
	}
	if ($nc(chc)->staplingActive) {
		$set(chc, deferredCerts, x509Certs);
	} else {
		checkServerCerts(chc, x509Certs);
	}
	$nc($nc(chc)->handshakeCredentials)->add($$new($X509Authentication$X509Credentials, $($nc(x509Certs->get(0))->getPublicKey()), x509Certs));
	$nc(chc->handshakeSession)->setPeerCertificates(x509Certs);
}

bool CertificateMessage$T12CertificateConsumer::isIdentityEquivalent($X509Certificate* thisCert, $X509Certificate* prevCert) {
	$init(CertificateMessage$T12CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	if ($nc(thisCert)->equals(prevCert)) {
		return true;
	}
	$var($Collection, thisSubjectAltNames, nullptr);
	try {
		$assign(thisSubjectAltNames, $nc(thisCert)->getSubjectAlternativeNames());
	} catch ($CertificateParsingException& cpe) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("handshake"_s)) {
			$SSLLogger::fine("Attempt to obtain subjectAltNames extension failed!"_s, $$new($ObjectArray, 0));
		}
	}
	$var($Collection, prevSubjectAltNames, nullptr);
	try {
		$assign(prevSubjectAltNames, $nc(prevCert)->getSubjectAlternativeNames());
	} catch ($CertificateParsingException& cpe) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("handshake"_s)) {
			$SSLLogger::fine("Attempt to obtain subjectAltNames extension failed!"_s, $$new($ObjectArray, 0));
		}
	}
	if (thisSubjectAltNames != nullptr && prevSubjectAltNames != nullptr) {
		$var($Collection, thisSubAltIPAddrs, getSubjectAltNames(thisSubjectAltNames, 7));
		$var($Collection, prevSubAltIPAddrs, getSubjectAltNames(prevSubjectAltNames, 7));
		if (thisSubAltIPAddrs != nullptr && prevSubAltIPAddrs != nullptr && isEquivalent(thisSubAltIPAddrs, prevSubAltIPAddrs)) {
			return true;
		}
		$var($Collection, thisSubAltDnsNames, getSubjectAltNames(thisSubjectAltNames, 2));
		$var($Collection, prevSubAltDnsNames, getSubjectAltNames(prevSubjectAltNames, 2));
		if (thisSubAltDnsNames != nullptr && prevSubAltDnsNames != nullptr && isEquivalent(thisSubAltDnsNames, prevSubAltDnsNames)) {
			return true;
		}
	}
	$var($X500Principal, thisSubject, $nc(thisCert)->getSubjectX500Principal());
	$var($X500Principal, prevSubject, $nc(prevCert)->getSubjectX500Principal());
	$var($X500Principal, thisIssuer, thisCert->getIssuerX500Principal());
	$var($X500Principal, prevIssuer, prevCert->getIssuerX500Principal());
	bool var$2 = !$nc($($nc(thisSubject)->getName()))->isEmpty();
	bool var$1 = var$2 && !$nc($($nc(prevSubject)->getName()))->isEmpty();
	bool var$0 = var$1 && thisSubject->equals(prevSubject);
	return (var$0 && $nc(thisIssuer)->equals(prevIssuer));
}

$Collection* CertificateMessage$T12CertificateConsumer::getSubjectAltNames($Collection* subjectAltNames, int32_t type) {
	$init(CertificateMessage$T12CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, subAltDnsNames, nullptr);
	{
		$var($Iterator, i$, $nc(subjectAltNames)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, subjectAltName, $cast($List, i$->next()));
			{
				int32_t subjectAltNameType = $nc(($cast($Integer, $($nc(subjectAltName)->get(0)))))->intValue();
				if (subjectAltNameType == type) {
					$var($String, subAltDnsName, $cast($String, subjectAltName->get(1)));
					if ((subAltDnsName != nullptr) && !subAltDnsName->isEmpty()) {
						if (subAltDnsNames == nullptr) {
							$assign(subAltDnsNames, $new($HashSet, subjectAltNames->size()));
						}
						$nc(subAltDnsNames)->add(subAltDnsName);
					}
				}
			}
		}
	}
	return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(subAltDnsNames)));
}

bool CertificateMessage$T12CertificateConsumer::isEquivalent($Collection* thisSubAltNames, $Collection* prevSubAltNames) {
	$init(CertificateMessage$T12CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(thisSubAltNames)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, thisSubAltName, $cast($String, i$->next()));
			{
				{
					$var($Iterator, i$, $nc(prevSubAltNames)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, prevSubAltName, $cast($String, i$->next()));
						{
							if ($nc(thisSubAltName)->equalsIgnoreCase(prevSubAltName)) {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

void CertificateMessage$T12CertificateConsumer::checkServerCerts($ClientHandshakeContext* chc, $X509CertificateArray* certs) {
	$init(CertificateMessage$T12CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	$var($X509TrustManager, tm, $nc($nc(chc)->sslContext)->getX509TrustManager());
	$var($String, keyExchangeString, nullptr);
	$init($CipherSuite$KeyExchange);
	if ($nc(chc->negotiatedCipherSuite)->keyExchange == $CipherSuite$KeyExchange::K_RSA_EXPORT || $nc(chc->negotiatedCipherSuite)->keyExchange == $CipherSuite$KeyExchange::K_DHE_RSA_EXPORT) {
		$assign(keyExchangeString, $CipherSuite$KeyExchange::K_RSA->name$);
	} else {
		$assign(keyExchangeString, $nc(chc->negotiatedCipherSuite)->keyExchange->name$);
	}
	try {
		if ($instanceOf($X509ExtendedTrustManager, tm)) {
			if ($instanceOf($SSLEngine, $nc(chc->conContext)->transport)) {
				$var($SSLEngine, engine, $cast($SSLEngine, $nc(chc->conContext)->transport));
				$nc(($cast($X509ExtendedTrustManager, tm)))->checkServerTrusted($cast($X509CertificateArray, $($nc(certs)->clone())), keyExchangeString, engine);
			} else {
				$var($SSLSocket, socket, $cast($SSLSocket, $nc(chc->conContext)->transport));
				$nc(($cast($X509ExtendedTrustManager, tm)))->checkServerTrusted($cast($X509CertificateArray, $($nc(certs)->clone())), keyExchangeString, static_cast<$Socket*>(socket));
			}
		} else {
			$throwNew($CertificateException, "Improper X509TrustManager implementation"_s);
		}
		$nc(chc->handshakeSession)->setPeerCertificates(certs);
	} catch ($CertificateException& ce) {
		$throw($($nc(chc->conContext)->fatal($(getCertificateAlert(chc, ce)), static_cast<$Throwable*>(ce))));
	}
}

void CertificateMessage$T12CertificateConsumer::checkClientCerts($ServerHandshakeContext* shc, $X509CertificateArray* certs) {
	$init(CertificateMessage$T12CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	$var($X509TrustManager, tm, $nc($nc(shc)->sslContext)->getX509TrustManager());
	$var($PublicKey, key, $nc($nc(certs)->get(0))->getPublicKey());
	$var($String, keyAlgorithm, $nc(key)->getAlgorithm());
	$var($String, authType, nullptr);
	{
		$var($String, s28331$, keyAlgorithm);
		int32_t tmp28331$ = -1;
		switch ($nc(s28331$)->hashCode()) {
		case 0x00013E20:
			{
				if (s28331$->equals("RSA"_s)) {
					tmp28331$ = 0;
				}
				break;
			}
		case 0x00010992:
			{
				if (s28331$->equals("DSA"_s)) {
					tmp28331$ = 1;
				}
				break;
			}
		case 2206:
			{
				if (s28331$->equals("EC"_s)) {
					tmp28331$ = 2;
				}
				break;
			}
		case 0x69D3B2A4:
			{
				if (s28331$->equals("RSASSA-PSS"_s)) {
					tmp28331$ = 3;
				}
				break;
			}
		}
		switch (tmp28331$) {
		case 0:
			{}
		case 1:
			{}
		case 2:
			{}
		case 3:
			{
				$assign(authType, keyAlgorithm);
				break;
			}
		default:
			{
				$assign(authType, "UNKNOWN"_s);
			}
		}
	}
	try {
		if ($instanceOf($X509ExtendedTrustManager, tm)) {
			if ($instanceOf($SSLEngine, $nc(shc->conContext)->transport)) {
				$var($SSLEngine, engine, $cast($SSLEngine, $nc(shc->conContext)->transport));
				$nc(($cast($X509ExtendedTrustManager, tm)))->checkClientTrusted($cast($X509CertificateArray, $(certs->clone())), authType, engine);
			} else {
				$var($SSLSocket, socket, $cast($SSLSocket, $nc(shc->conContext)->transport));
				$nc(($cast($X509ExtendedTrustManager, tm)))->checkClientTrusted($cast($X509CertificateArray, $(certs->clone())), authType, static_cast<$Socket*>(socket));
			}
		} else {
			$throwNew($CertificateException, "Improper X509TrustManager implementation"_s);
		}
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::CERTIFICATE_UNKNOWN, static_cast<$Throwable*>(ce))));
	}
}

$Alert* CertificateMessage$T12CertificateConsumer::getCertificateAlert($ClientHandshakeContext* chc, $CertificateException* cexc) {
	$init(CertificateMessage$T12CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	$init($Alert);
	$Alert* alert = $Alert::CERTIFICATE_UNKNOWN;
	$var($Throwable, baseCause, $nc(cexc)->getCause());
	if ($instanceOf($CertPathValidatorException, baseCause)) {
		$var($CertPathValidatorException, cpve, $cast($CertPathValidatorException, baseCause));
		$var($CertPathValidatorException$Reason, reason, $nc(cpve)->getReason());
		$init($CertPathValidatorException$BasicReason);
		if ($equals(reason, $CertPathValidatorException$BasicReason::REVOKED)) {
			alert = $nc(chc)->staplingActive ? $Alert::BAD_CERT_STATUS_RESPONSE : $Alert::CERTIFICATE_REVOKED;
		} else {
			if ($equals(reason, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS)) {
				alert = $nc(chc)->staplingActive ? $Alert::BAD_CERT_STATUS_RESPONSE : $Alert::CERTIFICATE_UNKNOWN;
			} else {
				if ($equals(reason, $CertPathValidatorException$BasicReason::ALGORITHM_CONSTRAINED)) {
					alert = $Alert::UNSUPPORTED_CERTIFICATE;
				} else {
					if ($equals(reason, $CertPathValidatorException$BasicReason::EXPIRED)) {
						alert = $Alert::CERTIFICATE_EXPIRED;
					} else {
						if ($equals(reason, $CertPathValidatorException$BasicReason::INVALID_SIGNATURE) || $equals(reason, $CertPathValidatorException$BasicReason::NOT_YET_VALID)) {
							alert = $Alert::BAD_CERTIFICATE;
						}
					}
				}
			}
		}
	}
	return alert;
}

CertificateMessage$T12CertificateConsumer::CertificateMessage$T12CertificateConsumer() {
}

$Class* CertificateMessage$T12CertificateConsumer::load$($String* name, bool initialize) {
	$loadClass(CertificateMessage$T12CertificateConsumer, name, initialize, &_CertificateMessage$T12CertificateConsumer_ClassInfo_, allocate$CertificateMessage$T12CertificateConsumer);
	return class$;
}

$Class* CertificateMessage$T12CertificateConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun