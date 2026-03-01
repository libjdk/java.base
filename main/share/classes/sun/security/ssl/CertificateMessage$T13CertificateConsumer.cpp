#include <sun/security/ssl/CertificateMessage$T13CertificateConsumer.h>

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
#include <java/security/cert/X509Certificate.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/X509ExtendedTrustManager.h>
#include <javax/net/ssl/X509TrustManager.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertificateMessage$CertificateEntry.h>
#include <sun/security/ssl/CertificateMessage$T13CertificateMessage.h>
#include <sun/security/ssl/CertificateMessage.h>
#include <sun/security/ssl/ClientAuthType.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTransport.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <jcpp.h>

#undef BAD_CERTIFICATE
#undef BAD_CERT_STATUS_RESPONSE
#undef CERTIFICATE
#undef CERTIFICATE_REVOKED
#undef CERTIFICATE_UNKNOWN
#undef CERTIFICATE_VERIFY
#undef CLIENT_AUTH_REQUIRED
#undef REVOKED
#undef UNDETERMINED_REVOCATION_STATUS

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $InputStream = ::java::io::InputStream;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Socket = ::java::net::Socket;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $PublicKey = ::java::security::PublicKey;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$BasicReason = ::java::security::cert::CertPathValidatorException$BasicReason;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $X509ExtendedTrustManager = ::javax::net::ssl::X509ExtendedTrustManager;
using $X509TrustManager = ::javax::net::ssl::X509TrustManager;
using $Alert = ::sun::security::ssl::Alert;
using $CertificateMessage$CertificateEntry = ::sun::security::ssl::CertificateMessage$CertificateEntry;
using $CertificateMessage$T13CertificateMessage = ::sun::security::ssl::CertificateMessage$T13CertificateMessage;
using $ClientAuthType = ::sun::security::ssl::ClientAuthType;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _CertificateMessage$T13CertificateConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(CertificateMessage$T13CertificateConsumer, init$, void)},
	{"checkClientCerts", "(Lsun/security/ssl/ServerHandshakeContext;Ljava/util/List;)[Ljava/security/cert/X509Certificate;", "(Lsun/security/ssl/ServerHandshakeContext;Ljava/util/List<Lsun/security/ssl/CertificateMessage$CertificateEntry;>;)[Ljava/security/cert/X509Certificate;", $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T13CertificateConsumer, checkClientCerts, $X509CertificateArray*, $ServerHandshakeContext*, $List*), "java.io.IOException"},
	{"checkServerCerts", "(Lsun/security/ssl/ClientHandshakeContext;Ljava/util/List;)[Ljava/security/cert/X509Certificate;", "(Lsun/security/ssl/ClientHandshakeContext;Ljava/util/List<Lsun/security/ssl/CertificateMessage$CertificateEntry;>;)[Ljava/security/cert/X509Certificate;", $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T13CertificateConsumer, checkServerCerts, $X509CertificateArray*, $ClientHandshakeContext*, $List*), "java.io.IOException"},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T13CertificateConsumer, consume, void, $ConnectionContext*, $ByteBuffer*), "java.io.IOException"},
	{"getCertificateAlert", "(Lsun/security/ssl/ClientHandshakeContext;Ljava/security/cert/CertificateException;)Lsun/security/ssl/Alert;", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateMessage$T13CertificateConsumer, getCertificateAlert, $Alert*, $ClientHandshakeContext*, $CertificateException*)},
	{"onConsumeCertificate", "(Lsun/security/ssl/ServerHandshakeContext;Lsun/security/ssl/CertificateMessage$T13CertificateMessage;)V", nullptr, $PRIVATE, $method(CertificateMessage$T13CertificateConsumer, onConsumeCertificate, void, $ServerHandshakeContext*, $CertificateMessage$T13CertificateMessage*), "java.io.IOException"},
	{"onConsumeCertificate", "(Lsun/security/ssl/ClientHandshakeContext;Lsun/security/ssl/CertificateMessage$T13CertificateMessage;)V", nullptr, $PRIVATE, $method(CertificateMessage$T13CertificateConsumer, onConsumeCertificate, void, $ClientHandshakeContext*, $CertificateMessage$T13CertificateMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _CertificateMessage$T13CertificateConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateMessage$T13CertificateConsumer", "sun.security.ssl.CertificateMessage", "T13CertificateConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _CertificateMessage$T13CertificateConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateMessage$T13CertificateConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLConsumer",
	nullptr,
	_CertificateMessage$T13CertificateConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateMessage$T13CertificateConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateMessage"
};

$Object* allocate$CertificateMessage$T13CertificateConsumer($Class* clazz) {
	return $of($alloc(CertificateMessage$T13CertificateConsumer));
}

void CertificateMessage$T13CertificateConsumer::init$() {
}

void CertificateMessage$T13CertificateConsumer::consume($ConnectionContext* context, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	$var($HandshakeContext, hc, $cast($HandshakeContext, context));
	$init($SSLHandshake);
	$nc($nc(hc)->handshakeConsumers)->remove($($Byte::valueOf($SSLHandshake::CERTIFICATE->id)));
	$var($CertificateMessage$T13CertificateMessage, cm, $new($CertificateMessage$T13CertificateMessage, hc, message));
	if ($nc(hc->sslConfig)->isClientMode) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Consuming server Certificate handshake message"_s, $$new($ObjectArray, {$of(cm)}));
		}
		onConsumeCertificate($cast($ClientHandshakeContext, context), cm);
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Consuming client Certificate handshake message"_s, $$new($ObjectArray, {$of(cm)}));
		}
		onConsumeCertificate($cast($ServerHandshakeContext, context), cm);
	}
}

void CertificateMessage$T13CertificateConsumer::onConsumeCertificate($ServerHandshakeContext* shc, $CertificateMessage$T13CertificateMessage* certificateMessage) {
	$useLocalCurrentObjectStackCache();
	if ($nc(certificateMessage)->certEntries == nullptr || $nc($nc(certificateMessage)->certEntries)->isEmpty()) {
		$init($SSLHandshake);
		$nc($nc(shc)->handshakeConsumers)->remove($($Byte::valueOf($SSLHandshake::CERTIFICATE_VERIFY->id)));
		$init($ClientAuthType);
		if ($nc(shc->sslConfig)->clientAuthType == $ClientAuthType::CLIENT_AUTH_REQUIRED) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::BAD_CERTIFICATE, "Empty client certificate chain"_s)));
		} else {
			return;
		}
	}
	$var($X509CertificateArray, cliCerts, checkClientCerts(shc, $nc(certificateMessage)->certEntries));
	$nc($nc(shc)->handshakeCredentials)->add($$new($X509Authentication$X509Credentials, $($nc($nc(cliCerts)->get(0))->getPublicKey()), cliCerts));
	$nc(shc->handshakeSession)->setPeerCertificates(cliCerts);
}

void CertificateMessage$T13CertificateConsumer::onConsumeCertificate($ClientHandshakeContext* chc, $CertificateMessage$T13CertificateMessage* certificateMessage) {
	$useLocalCurrentObjectStackCache();
	if ($nc(certificateMessage)->certEntries == nullptr || $nc($nc(certificateMessage)->certEntries)->isEmpty()) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Empty server certificate chain"_s)));
	}
	$init($SSLHandshake);
	$var($SSLExtensionArray, enabledExtensions, $nc($nc(chc)->sslConfig)->getEnabledExtensions($SSLHandshake::CERTIFICATE));
	{
		$var($Iterator, i$, $nc($nc(certificateMessage)->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificateMessage$CertificateEntry, certEnt, $cast($CertificateMessage$CertificateEntry, i$->next()));
			{
				$nc($nc(certEnt)->extensions)->consumeOnLoad(chc, enabledExtensions);
			}
		}
	}
	$var($X509CertificateArray, srvCerts, checkServerCerts(chc, certificateMessage->certEntries));
	$nc(chc->handshakeCredentials)->add($$new($X509Authentication$X509Credentials, $($nc($nc(srvCerts)->get(0))->getPublicKey()), srvCerts));
	$nc(chc->handshakeSession)->setPeerCertificates(srvCerts);
}

$X509CertificateArray* CertificateMessage$T13CertificateConsumer::checkClientCerts($ServerHandshakeContext* shc, $List* certEntries) {
	$init(CertificateMessage$T13CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	$var($X509CertificateArray, certs, $new($X509CertificateArray, $nc(certEntries)->size()));
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		int32_t i = 0;
		{
			$var($Iterator, i$, certEntries->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($CertificateMessage$CertificateEntry, entry, $cast($CertificateMessage$CertificateEntry, i$->next()));
				{
					certs->set(i++, $cast($X509Certificate, $($nc(cf)->generateCertificate($$new($ByteArrayInputStream, $nc(entry)->encoded)))));
				}
			}
		}
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Failed to parse server certificates"_s, ce)));
	}
	$var($String, keyAlgorithm, $nc($($nc(certs->get(0))->getPublicKey()))->getAlgorithm());
	$var($String, authType, nullptr);
	{
		$var($String, s53002$, keyAlgorithm);
		int32_t tmp53002$ = -1;
		switch ($nc(s53002$)->hashCode()) {
		case 0x00013E20:
			{
				if (s53002$->equals("RSA"_s)) {
					tmp53002$ = 0;
				}
				break;
			}
		case 0x00010992:
			{
				if (s53002$->equals("DSA"_s)) {
					tmp53002$ = 1;
				}
				break;
			}
		case 2206:
			{
				if (s53002$->equals("EC"_s)) {
					tmp53002$ = 2;
				}
				break;
			}
		case 0x69D3B2A4:
			{
				if (s53002$->equals("RSASSA-PSS"_s)) {
					tmp53002$ = 3;
				}
				break;
			}
		}
		switch (tmp53002$) {
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
		$var($X509TrustManager, tm, $nc($nc(shc)->sslContext)->getX509TrustManager());
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
		$nc(shc->handshakeSession)->setPeerCertificates(certs);
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::CERTIFICATE_UNKNOWN, static_cast<$Throwable*>(ce))));
	}
	return certs;
}

$X509CertificateArray* CertificateMessage$T13CertificateConsumer::checkServerCerts($ClientHandshakeContext* chc, $List* certEntries) {
	$init(CertificateMessage$T13CertificateConsumer);
	$useLocalCurrentObjectStackCache();
	$var($X509CertificateArray, certs, $new($X509CertificateArray, $nc(certEntries)->size()));
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		int32_t i = 0;
		{
			$var($Iterator, i$, certEntries->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($CertificateMessage$CertificateEntry, entry, $cast($CertificateMessage$CertificateEntry, i$->next()));
				{
					certs->set(i++, $cast($X509Certificate, $($nc(cf)->generateCertificate($$new($ByteArrayInputStream, $nc(entry)->encoded)))));
				}
			}
		}
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Failed to parse server certificates"_s, ce)));
	}
	$var($String, authType, "UNKNOWN"_s);
	try {
		$var($X509TrustManager, tm, $nc($nc(chc)->sslContext)->getX509TrustManager());
		if ($instanceOf($X509ExtendedTrustManager, tm)) {
			if ($instanceOf($SSLEngine, $nc(chc->conContext)->transport)) {
				$var($SSLEngine, engine, $cast($SSLEngine, $nc(chc->conContext)->transport));
				$nc(($cast($X509ExtendedTrustManager, tm)))->checkServerTrusted($cast($X509CertificateArray, $(certs->clone())), authType, engine);
			} else {
				$var($SSLSocket, socket, $cast($SSLSocket, $nc(chc->conContext)->transport));
				$nc(($cast($X509ExtendedTrustManager, tm)))->checkServerTrusted($cast($X509CertificateArray, $(certs->clone())), authType, static_cast<$Socket*>(socket));
			}
		} else {
			$throwNew($CertificateException, "Improper X509TrustManager implementation"_s);
		}
		$nc(chc->handshakeSession)->setPeerCertificates(certs);
	} catch ($CertificateException& ce) {
		$throw($($nc($nc(chc)->conContext)->fatal($(getCertificateAlert(chc, ce)), static_cast<$Throwable*>(ce))));
	}
	return certs;
}

$Alert* CertificateMessage$T13CertificateConsumer::getCertificateAlert($ClientHandshakeContext* chc, $CertificateException* cexc) {
	$init(CertificateMessage$T13CertificateConsumer);
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
			}
		}
	}
	return alert;
}

CertificateMessage$T13CertificateConsumer::CertificateMessage$T13CertificateConsumer() {
}

$Class* CertificateMessage$T13CertificateConsumer::load$($String* name, bool initialize) {
	$loadClass(CertificateMessage$T13CertificateConsumer, name, initialize, &_CertificateMessage$T13CertificateConsumer_ClassInfo_, allocate$CertificateMessage$T13CertificateConsumer);
	return class$;
}

$Class* CertificateMessage$T13CertificateConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun