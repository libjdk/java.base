#include <sun/security/ssl/CertStatusExtension$CertStatusRequestV2Spec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
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
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef DEFAULT
#undef EMPTY_OCSP_MULTI
#undef ENGLISH
#undef OCSP
#undef OCSP_MULTI

using $CertStatusExtension$CertStatusRequestArray = $Array<::sun::security::ssl::CertStatusExtension$CertStatusRequest>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $CertStatusExtension$CertStatusRequest = ::sun::security::ssl::CertStatusExtension$CertStatusRequest;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $CertStatusExtension$OCSPStatusRequest = ::sun::security::ssl::CertStatusExtension$OCSPStatusRequest;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $Record = ::sun::security::ssl::Record;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertStatusExtension$CertStatusRequestV2Spec_FieldInfo_[] = {
	{"DEFAULT", "Lsun/security/ssl/CertStatusExtension$CertStatusRequestV2Spec;", nullptr, $STATIC | $FINAL, $staticField(CertStatusExtension$CertStatusRequestV2Spec, DEFAULT)},
	{"certStatusRequests", "[Lsun/security/ssl/CertStatusExtension$CertStatusRequest;", nullptr, $FINAL, $field(CertStatusExtension$CertStatusRequestV2Spec, certStatusRequests)},
	{}
};

$MethodInfo _CertStatusExtension$CertStatusRequestV2Spec_MethodInfo_[] = {
	{"<init>", "([Lsun/security/ssl/CertStatusExtension$CertStatusRequest;)V", nullptr, $PRIVATE, $method(CertStatusExtension$CertStatusRequestV2Spec, init$, void, $CertStatusExtension$CertStatusRequestArray*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(CertStatusExtension$CertStatusRequestV2Spec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertStatusExtension$CertStatusRequestV2Spec, toString, $String*)},
	{}
};

$InnerClassInfo _CertStatusExtension$CertStatusRequestV2Spec_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertStatusExtension$CertStatusRequestV2Spec", "sun.security.ssl.CertStatusExtension", "CertStatusRequestV2Spec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _CertStatusExtension$CertStatusRequestV2Spec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertStatusExtension$CertStatusRequestV2Spec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_CertStatusExtension$CertStatusRequestV2Spec_FieldInfo_,
	_CertStatusExtension$CertStatusRequestV2Spec_MethodInfo_,
	nullptr,
	nullptr,
	_CertStatusExtension$CertStatusRequestV2Spec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertStatusExtension"
};

$Object* allocate$CertStatusExtension$CertStatusRequestV2Spec($Class* clazz) {
	return $of($alloc(CertStatusExtension$CertStatusRequestV2Spec));
}

CertStatusExtension$CertStatusRequestV2Spec* CertStatusExtension$CertStatusRequestV2Spec::DEFAULT = nullptr;

void CertStatusExtension$CertStatusRequestV2Spec::init$($CertStatusExtension$CertStatusRequestArray* certStatusRequests) {
	$set(this, certStatusRequests, certStatusRequests);
}

void CertStatusExtension$CertStatusRequestV2Spec::init$($HandshakeContext* hc, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	if ($nc(message)->remaining() == 0) {
		$set(this, certStatusRequests, $new($CertStatusExtension$CertStatusRequestArray, 0));
		return;
	}
	if ($nc(message)->remaining() < 5) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid status_request_v2 extension: insufficient data"_s)))));
	}
	int32_t listLen = $Record::getInt16(message);
	if (listLen <= 0) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"certificate_status_req_list length must be positive (received length: "_s, $$str(listLen), ")"_s}))))));
	}
	int32_t remaining = listLen;
	$var($List, statusRequests, $new($ArrayList));
	while (remaining > 0) {
		int8_t statusType = (int8_t)$Record::getInt8(message);
		int32_t requestLen = $Record::getInt16(message);
		if ($nc(message)->remaining() < requestLen) {
			$init($Alert);
			$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid status_request_v2 extension: insufficient data (request_length="_s, $$str(requestLen), ", remining="_s, $$str(message->remaining()), ")"_s}))))));
		}
		$var($bytes, encoded, $new($bytes, requestLen));
		if (encoded->length != 0) {
			$nc(message)->get(encoded);
		}
		remaining -= 3;
		remaining -= requestLen;
		$init($CertStatusExtension$CertStatusRequestType);
		if (statusType == $CertStatusExtension$CertStatusRequestType::OCSP->id || statusType == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI->id) {
			if (encoded->length < 4) {
				$init($Alert);
				$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid status_request_v2 extension: insufficient data"_s)))));
			}
			statusRequests->add($$new($CertStatusExtension$OCSPStatusRequest, statusType, encoded));
		} else {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::info($$str({"Unknown certificate status request (status type: "_s, $$str(statusType), ")"_s}), $$new($ObjectArray, 0));
			}
			statusRequests->add($$new($CertStatusExtension$CertStatusRequest, statusType, encoded));
		}
	}
	$set(this, certStatusRequests, $fcast($CertStatusExtension$CertStatusRequestArray, statusRequests->toArray($$new($CertStatusExtension$CertStatusRequestArray, 0))));
}

$String* CertStatusExtension$CertStatusRequestV2Spec::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->certStatusRequests == nullptr || $nc(this->certStatusRequests)->length == 0) {
		return "<empty>"_s;
	} else {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"cert status request\": \'{\'\n{0}\n\'}\'"_s, $Locale::ENGLISH));
		$var($StringBuilder, builder, $new($StringBuilder, 512));
		bool isFirst = true;
		{
			$var($CertStatusExtension$CertStatusRequestArray, arr$, this->certStatusRequests);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($CertStatusExtension$CertStatusRequest, csr, arr$->get(i$));
				{
					if (isFirst) {
						isFirst = false;
					} else {
						builder->append(", "_s);
					}
					$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::indent($($nc(csr)->toString()))))}));
					builder->append($(messageFormat->format(messageFields)));
				}
			}
		}
		return builder->toString();
	}
}

void clinit$CertStatusExtension$CertStatusRequestV2Spec($Class* class$) {
	$init($CertStatusExtension$OCSPStatusRequest);
	$assignStatic(CertStatusExtension$CertStatusRequestV2Spec::DEFAULT, $new(CertStatusExtension$CertStatusRequestV2Spec, $$new($CertStatusExtension$CertStatusRequestArray, {static_cast<$CertStatusExtension$CertStatusRequest*>($CertStatusExtension$OCSPStatusRequest::EMPTY_OCSP_MULTI)})));
}

CertStatusExtension$CertStatusRequestV2Spec::CertStatusExtension$CertStatusRequestV2Spec() {
}

$Class* CertStatusExtension$CertStatusRequestV2Spec::load$($String* name, bool initialize) {
	$loadClass(CertStatusExtension$CertStatusRequestV2Spec, name, initialize, &_CertStatusExtension$CertStatusRequestV2Spec_ClassInfo_, clinit$CertStatusExtension$CertStatusRequestV2Spec, allocate$CertStatusExtension$CertStatusRequestV2Spec);
	return class$;
}

$Class* CertStatusExtension$CertStatusRequestV2Spec::class$ = nullptr;

		} // ssl
	} // security
} // sun