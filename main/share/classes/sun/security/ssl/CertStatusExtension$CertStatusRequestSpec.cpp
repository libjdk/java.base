#include <sun/security/ssl/CertStatusExtension$CertStatusRequestSpec.h>

#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequest.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestType.h>
#include <sun/security/ssl/CertStatusExtension$OCSPStatusRequest.h>
#include <sun/security/ssl/CertStatusExtension.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef DEFAULT
#undef EMPTY_OCSP
#undef OCSP

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $CertStatusExtension$CertStatusRequest = ::sun::security::ssl::CertStatusExtension$CertStatusRequest;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $CertStatusExtension$OCSPStatusRequest = ::sun::security::ssl::CertStatusExtension$OCSPStatusRequest;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $Record = ::sun::security::ssl::Record;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertStatusExtension$CertStatusRequestSpec_FieldInfo_[] = {
	{"DEFAULT", "Lsun/security/ssl/CertStatusExtension$CertStatusRequestSpec;", nullptr, $STATIC | $FINAL, $staticField(CertStatusExtension$CertStatusRequestSpec, DEFAULT)},
	{"statusRequest", "Lsun/security/ssl/CertStatusExtension$CertStatusRequest;", nullptr, $FINAL, $field(CertStatusExtension$CertStatusRequestSpec, statusRequest)},
	{}
};

$MethodInfo _CertStatusExtension$CertStatusRequestSpec_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/CertStatusExtension$CertStatusRequest;)V", nullptr, $PRIVATE, $method(CertStatusExtension$CertStatusRequestSpec, init$, void, $CertStatusExtension$CertStatusRequest*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(CertStatusExtension$CertStatusRequestSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertStatusExtension$CertStatusRequestSpec, toString, $String*)},
	{}
};

$InnerClassInfo _CertStatusExtension$CertStatusRequestSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertStatusExtension$CertStatusRequestSpec", "sun.security.ssl.CertStatusExtension", "CertStatusRequestSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _CertStatusExtension$CertStatusRequestSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertStatusExtension$CertStatusRequestSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_CertStatusExtension$CertStatusRequestSpec_FieldInfo_,
	_CertStatusExtension$CertStatusRequestSpec_MethodInfo_,
	nullptr,
	nullptr,
	_CertStatusExtension$CertStatusRequestSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertStatusExtension"
};

$Object* allocate$CertStatusExtension$CertStatusRequestSpec($Class* clazz) {
	return $of($alloc(CertStatusExtension$CertStatusRequestSpec));
}

CertStatusExtension$CertStatusRequestSpec* CertStatusExtension$CertStatusRequestSpec::DEFAULT = nullptr;

void CertStatusExtension$CertStatusRequestSpec::init$($CertStatusExtension$CertStatusRequest* statusRequest) {
	$set(this, statusRequest, statusRequest);
}

void CertStatusExtension$CertStatusRequestSpec::init$($HandshakeContext* hc, $ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if ($nc(buffer)->remaining() == 0) {
		$set(this, statusRequest, nullptr);
		return;
	}
	if ($nc(buffer)->remaining() < 1) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid status_request extension: insufficient data"_s)))));
	}
	int8_t statusType = (int8_t)$Record::getInt8(buffer);
	$var($bytes, encoded, $new($bytes, $nc(buffer)->remaining()));
	if (encoded->length != 0) {
		buffer->get(encoded);
	}
	$init($CertStatusExtension$CertStatusRequestType);
	if (statusType == $CertStatusExtension$CertStatusRequestType::OCSP->id) {
		$set(this, statusRequest, $new($CertStatusExtension$OCSPStatusRequest, statusType, encoded));
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::info($$str({"Unknown certificate status request (status type: "_s, $$str(statusType), ")"_s}), $$new($ObjectArray, 0));
		}
		$set(this, statusRequest, $new($CertStatusExtension$CertStatusRequest, statusType, encoded));
	}
}

$String* CertStatusExtension$CertStatusRequestSpec::toString() {
	return this->statusRequest == nullptr ? "<empty>"_s : $nc(this->statusRequest)->toString();
}

void clinit$CertStatusExtension$CertStatusRequestSpec($Class* class$) {
	$init($CertStatusExtension$OCSPStatusRequest);
	$assignStatic(CertStatusExtension$CertStatusRequestSpec::DEFAULT, $new(CertStatusExtension$CertStatusRequestSpec, $CertStatusExtension$OCSPStatusRequest::EMPTY_OCSP));
}

CertStatusExtension$CertStatusRequestSpec::CertStatusExtension$CertStatusRequestSpec() {
}

$Class* CertStatusExtension$CertStatusRequestSpec::load$($String* name, bool initialize) {
	$loadClass(CertStatusExtension$CertStatusRequestSpec, name, initialize, &_CertStatusExtension$CertStatusRequestSpec_ClassInfo_, clinit$CertStatusExtension$CertStatusRequestSpec, allocate$CertStatusExtension$CertStatusRequestSpec);
	return class$;
}

$Class* CertStatusExtension$CertStatusRequestSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun