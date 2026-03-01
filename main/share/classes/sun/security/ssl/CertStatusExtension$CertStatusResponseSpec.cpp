#include <sun/security/ssl/CertStatusExtension$CertStatusResponseSpec.h>

#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestType.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusResponse.h>
#include <sun/security/ssl/CertStatusExtension$OCSPStatusResponse.h>
#include <sun/security/ssl/CertStatusExtension.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef OCSP

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $CertStatusExtension$CertStatusResponse = ::sun::security::ssl::CertStatusExtension$CertStatusResponse;
using $CertStatusExtension$OCSPStatusResponse = ::sun::security::ssl::CertStatusExtension$OCSPStatusResponse;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $Record = ::sun::security::ssl::Record;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertStatusExtension$CertStatusResponseSpec_FieldInfo_[] = {
	{"statusResponse", "Lsun/security/ssl/CertStatusExtension$CertStatusResponse;", nullptr, $FINAL, $field(CertStatusExtension$CertStatusResponseSpec, statusResponse)},
	{}
};

$MethodInfo _CertStatusExtension$CertStatusResponseSpec_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/CertStatusExtension$CertStatusResponse;)V", nullptr, $PRIVATE, $method(CertStatusExtension$CertStatusResponseSpec, init$, void, $CertStatusExtension$CertStatusResponse*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(CertStatusExtension$CertStatusResponseSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertStatusExtension$CertStatusResponseSpec, toString, $String*)},
	{}
};

$InnerClassInfo _CertStatusExtension$CertStatusResponseSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertStatusExtension$CertStatusResponseSpec", "sun.security.ssl.CertStatusExtension", "CertStatusResponseSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _CertStatusExtension$CertStatusResponseSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertStatusExtension$CertStatusResponseSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_CertStatusExtension$CertStatusResponseSpec_FieldInfo_,
	_CertStatusExtension$CertStatusResponseSpec_MethodInfo_,
	nullptr,
	nullptr,
	_CertStatusExtension$CertStatusResponseSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertStatusExtension"
};

$Object* allocate$CertStatusExtension$CertStatusResponseSpec($Class* clazz) {
	return $of($alloc(CertStatusExtension$CertStatusResponseSpec));
}

void CertStatusExtension$CertStatusResponseSpec::init$($CertStatusExtension$CertStatusResponse* resp) {
	$set(this, statusResponse, resp);
}

void CertStatusExtension$CertStatusResponseSpec::init$($HandshakeContext* hc, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid status_request extension: insufficient data"_s)))));
	}
	int8_t type = (int8_t)$Record::getInt8(buffer);
	$var($bytes, respData, $Record::getBytes24(buffer));
	$init($CertStatusExtension$CertStatusRequestType);
	if (type == $CertStatusExtension$CertStatusRequestType::OCSP->id) {
		$set(this, statusResponse, $new($CertStatusExtension$OCSPStatusResponse, type, respData));
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::info($$str({"Unknown certificate status response (status type: "_s, $$str(type), ")"_s}), $$new($ObjectArray, 0));
		}
		$set(this, statusResponse, $new($CertStatusExtension$CertStatusResponse, type, respData));
	}
}

$String* CertStatusExtension$CertStatusResponseSpec::toString() {
	return this->statusResponse == nullptr ? "<empty>"_s : $nc(this->statusResponse)->toString();
}

CertStatusExtension$CertStatusResponseSpec::CertStatusExtension$CertStatusResponseSpec() {
}

$Class* CertStatusExtension$CertStatusResponseSpec::load$($String* name, bool initialize) {
	$loadClass(CertStatusExtension$CertStatusResponseSpec, name, initialize, &_CertStatusExtension$CertStatusResponseSpec_ClassInfo_, allocate$CertStatusExtension$CertStatusResponseSpec);
	return class$;
}

$Class* CertStatusExtension$CertStatusResponseSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun