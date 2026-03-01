#include <sun/security/ssl/CertStatusExtension$CTCertStatusResponseProducer.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Map.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestType.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusResponse.h>
#include <sun/security/ssl/CertStatusExtension$OCSPStatusResponse.h>
#include <sun/security/ssl/CertStatusExtension.h>
#include <sun/security/ssl/CertificateMessage$CertificateEntry.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/StatusResponseManager$StaplingParameters.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef BAD_CERTIFICATE
#undef BAD_CERT_STATUS_RESPONSE
#undef OCSP

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Map = ::java::util::Map;
using $Alert = ::sun::security::ssl::Alert;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $CertStatusExtension$CertStatusResponse = ::sun::security::ssl::CertStatusExtension$CertStatusResponse;
using $CertStatusExtension$OCSPStatusResponse = ::sun::security::ssl::CertStatusExtension$OCSPStatusResponse;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _CertStatusExtension$CTCertStatusResponseProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(CertStatusExtension$CTCertStatusResponseProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(CertStatusExtension$CTCertStatusResponseProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _CertStatusExtension$CTCertStatusResponseProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertStatusExtension$CTCertStatusResponseProducer", "sun.security.ssl.CertStatusExtension", "CTCertStatusResponseProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _CertStatusExtension$CTCertStatusResponseProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertStatusExtension$CTCertStatusResponseProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_CertStatusExtension$CTCertStatusResponseProducer_MethodInfo_,
	nullptr,
	nullptr,
	_CertStatusExtension$CTCertStatusResponseProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertStatusExtension"
};

$Object* allocate$CertStatusExtension$CTCertStatusResponseProducer($Class* clazz) {
	return $of($alloc(CertStatusExtension$CTCertStatusResponseProducer));
}

void CertStatusExtension$CTCertStatusResponseProducer::init$() {
}

$bytes* CertStatusExtension$CTCertStatusResponseProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$var($bytes, producedData, nullptr);
	if ($nc(shc)->stapleParams == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::finest("Stapling is disabled for this connection"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	if ($nc(shc)->currentCertEntry == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::finest("Found null CertificateEntry in context"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		$var($X509Certificate, x509Cert, $cast($X509Certificate, $nc(cf)->generateCertificate($$new($ByteArrayInputStream, $nc($nc(shc)->currentCertEntry)->encoded))));
		$var($bytes, respBytes, $cast($bytes, $nc($nc($nc(shc)->stapleParams)->responseMap)->get(x509Cert)));
		if (respBytes == nullptr) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
				$SSLLogger::finest($$str({"No status response found for "_s, $($nc(x509Cert)->getSubjectX500Principal())}), $$new($ObjectArray, 0));
			}
			$set(shc, currentCertEntry, nullptr);
			return nullptr;
		}
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest($$str({"Found status response for "_s, $($nc(x509Cert)->getSubjectX500Principal()), ", response length: "_s, $$str($nc(respBytes)->length)}), $$new($ObjectArray, 0));
		}
		$init($CertStatusExtension$CertStatusRequestType);
		$var($CertStatusExtension$CertStatusResponse, certResp, ($nc(shc->stapleParams)->statReqType == $CertStatusExtension$CertStatusRequestType::OCSP) ? static_cast<$CertStatusExtension$CertStatusResponse*>($new($CertStatusExtension$OCSPStatusResponse, $nc(shc->stapleParams)->statReqType->id, respBytes)) : $new($CertStatusExtension$CertStatusResponse, $nc(shc->stapleParams)->statReqType->id, respBytes));
		$assign(producedData, $nc(certResp)->toByteArray());
	} catch ($CertificateException& ce) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::BAD_CERTIFICATE, "Failed to parse server certificates"_s, ce)));
	} catch ($IOException& ioe) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::BAD_CERT_STATUS_RESPONSE, "Failed to parse certificate status response"_s, ioe)));
	}
	$set($nc(shc), currentCertEntry, nullptr);
	return producedData;
}

CertStatusExtension$CTCertStatusResponseProducer::CertStatusExtension$CTCertStatusResponseProducer() {
}

$Class* CertStatusExtension$CTCertStatusResponseProducer::load$($String* name, bool initialize) {
	$loadClass(CertStatusExtension$CTCertStatusResponseProducer, name, initialize, &_CertStatusExtension$CTCertStatusResponseProducer_ClassInfo_, allocate$CertStatusExtension$CTCertStatusResponseProducer);
	return class$;
}

$Class* CertStatusExtension$CTCertStatusResponseProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun