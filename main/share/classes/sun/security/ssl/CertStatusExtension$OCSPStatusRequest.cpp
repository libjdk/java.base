#include <sun/security/ssl/CertStatusExtension$OCSPStatusRequest.h>

#include <java/io/IOException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/cert/Extension.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/provider/certpath/ResponderId.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequest.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestType.h>
#include <sun/security/ssl/CertStatusExtension.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/Extension.h>
#include <jcpp.h>

#undef EMPTY_OCSP
#undef EMPTY_OCSP_MULTI
#undef ENGLISH
#undef OCSP
#undef OCSP_MULTI

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $1Extension = ::java::security::cert::Extension;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $ResponderId = ::sun::security::provider::certpath::ResponderId;
using $CertStatusExtension$CertStatusRequest = ::sun::security::ssl::CertStatusExtension$CertStatusRequest;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $Record = ::sun::security::ssl::Record;
using $Utilities = ::sun::security::ssl::Utilities;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;
using $Extension = ::sun::security::x509::Extension;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertStatusExtension$OCSPStatusRequest_FieldInfo_[] = {
	{"EMPTY_OCSP", "Lsun/security/ssl/CertStatusExtension$OCSPStatusRequest;", nullptr, $STATIC | $FINAL, $staticField(CertStatusExtension$OCSPStatusRequest, EMPTY_OCSP)},
	{"EMPTY_OCSP_MULTI", "Lsun/security/ssl/CertStatusExtension$OCSPStatusRequest;", nullptr, $STATIC | $FINAL, $staticField(CertStatusExtension$OCSPStatusRequest, EMPTY_OCSP_MULTI)},
	{"responderIds", "Ljava/util/List;", "Ljava/util/List<Lsun/security/provider/certpath/ResponderId;>;", $FINAL, $field(CertStatusExtension$OCSPStatusRequest, responderIds)},
	{"extensions", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/Extension;>;", $FINAL, $field(CertStatusExtension$OCSPStatusRequest, extensions)},
	{}
};

$MethodInfo _CertStatusExtension$OCSPStatusRequest_MethodInfo_[] = {
	{"<init>", "(B[B)V", nullptr, $PRIVATE, $method(CertStatusExtension$OCSPStatusRequest, init$, void, int8_t, $bytes*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertStatusExtension$OCSPStatusRequest, toString, $String*)},
	{}
};

$InnerClassInfo _CertStatusExtension$OCSPStatusRequest_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertStatusExtension$OCSPStatusRequest", "sun.security.ssl.CertStatusExtension", "OCSPStatusRequest", $STATIC | $FINAL},
	{"sun.security.ssl.CertStatusExtension$CertStatusRequest", "sun.security.ssl.CertStatusExtension", "CertStatusRequest", $STATIC},
	{}
};

$ClassInfo _CertStatusExtension$OCSPStatusRequest_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertStatusExtension$OCSPStatusRequest",
	"sun.security.ssl.CertStatusExtension$CertStatusRequest",
	nullptr,
	_CertStatusExtension$OCSPStatusRequest_FieldInfo_,
	_CertStatusExtension$OCSPStatusRequest_MethodInfo_,
	nullptr,
	nullptr,
	_CertStatusExtension$OCSPStatusRequest_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertStatusExtension"
};

$Object* allocate$CertStatusExtension$OCSPStatusRequest($Class* clazz) {
	return $of($alloc(CertStatusExtension$OCSPStatusRequest));
}

CertStatusExtension$OCSPStatusRequest* CertStatusExtension$OCSPStatusRequest::EMPTY_OCSP = nullptr;
CertStatusExtension$OCSPStatusRequest* CertStatusExtension$OCSPStatusRequest::EMPTY_OCSP_MULTI = nullptr;

void CertStatusExtension$OCSPStatusRequest::init$(int8_t statusType, $bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$CertStatusExtension$CertStatusRequest::init$(statusType, encoded);
	if (encoded == nullptr || $nc(encoded)->length < 4) {
		$throwNew($SSLProtocolException, "Invalid OCSP status request: insufficient data"_s);
	}
	$var($List, rids, $new($ArrayList));
	$var($List, exts, $new($ArrayList));
	$var($ByteBuffer, m, $ByteBuffer::wrap(encoded));
	int32_t ridListLen = $Record::getInt16(m);
	if ($nc(m)->remaining() < (ridListLen + 2)) {
		$throwNew($SSLProtocolException, "Invalid OCSP status request: insufficient data"_s);
	}
	int32_t ridListBytesRemaining = ridListLen;
	while (ridListBytesRemaining >= 2) {
		$var($bytes, ridBytes, $Record::getBytes16(m));
		try {
			rids->add($$new($ResponderId, ridBytes));
		} catch ($IOException& ioe) {
			$throwNew($SSLProtocolException, "Invalid OCSP status request: invalid responder ID"_s);
		}
		ridListBytesRemaining -= $nc(ridBytes)->length + 2;
	}
	if (ridListBytesRemaining != 0) {
		$throwNew($SSLProtocolException, "Invalid OCSP status request: incomplete data"_s);
	}
	$var($bytes, extListBytes, $Record::getBytes16(m));
	int32_t extListLen = $nc(extListBytes)->length;
	if (extListLen > 0) {
		try {
			$var($DerInputStream, dis, $new($DerInputStream, extListBytes));
			$var($DerValueArray, extSeqContents, dis->getSequence(extListBytes->length));
			{
				$var($DerValueArray, arr$, extSeqContents);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($DerValue, extDerVal, arr$->get(i$));
					{
						exts->add($$new($Extension, extDerVal));
					}
				}
			}
		} catch ($IOException& ioe) {
			$throwNew($SSLProtocolException, "Invalid OCSP status request: invalid extension"_s);
		}
	}
	$set(this, responderIds, rids);
	$set(this, extensions, exts);
}

$String* CertStatusExtension$OCSPStatusRequest::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"certificate status type\": {0}\n\"OCSP status request\": \'{\'\n{1}\n\'}\'"_s, $Locale::ENGLISH));
	$var($MessageFormat, requestFormat, $new($MessageFormat, "\"responder_id\": {0}\n\"request extensions\": \'{\'\n{1}\n\'}\'"_s, $Locale::ENGLISH));
	$var($String, ridStr, "<empty>"_s);
	if (!$nc(this->responderIds)->isEmpty()) {
		$assign(ridStr, $nc($of(this->responderIds))->toString());
	}
	$var($String, extsStr, "<empty>"_s);
	if (!$nc(this->extensions)->isEmpty()) {
		$var($StringBuilder, extBuilder, $new($StringBuilder, 512));
		bool isFirst = true;
		{
			$var($Iterator, i$, $nc(this->extensions)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($1Extension, ext, $cast($1Extension, i$->next()));
				{
					if (isFirst) {
						isFirst = false;
					} else {
						extBuilder->append(",\n"_s);
					}
					extBuilder->append("{\n"_s)->append($($Utilities::indent($($nc($of(ext))->toString()))))->append("}"_s);
				}
			}
		}
		$assign(extsStr, extBuilder->toString());
	}
	$var($ObjectArray, requestFields, $new($ObjectArray, {
		$of(ridStr),
		$($of($Utilities::indent(extsStr)))
	}));
	$var($String, ocspStatusRequest, requestFormat->format(requestFields));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$($of($CertStatusExtension$CertStatusRequestType::nameOf(this->statusType))),
		$($of($Utilities::indent(ocspStatusRequest)))
	}));
	return messageFormat->format(messageFields);
}

void clinit$CertStatusExtension$OCSPStatusRequest($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var(CertStatusExtension$OCSPStatusRequest, ocspReq, nullptr);
		$var(CertStatusExtension$OCSPStatusRequest, multiReq, nullptr);
		try {
			$init($CertStatusExtension$CertStatusRequestType);
			$assign(ocspReq, $new(CertStatusExtension$OCSPStatusRequest, $CertStatusExtension$CertStatusRequestType::OCSP->id, $$new($bytes, {
				(int8_t)0,
				(int8_t)0,
				(int8_t)0,
				(int8_t)0
			})));
			$assign(multiReq, $new(CertStatusExtension$OCSPStatusRequest, $CertStatusExtension$CertStatusRequestType::OCSP_MULTI->id, $$new($bytes, {
				(int8_t)0,
				(int8_t)0,
				(int8_t)0,
				(int8_t)0
			})));
		} catch ($IOException& ioe) {
		}
		$assignStatic(CertStatusExtension$OCSPStatusRequest::EMPTY_OCSP, ocspReq);
		$assignStatic(CertStatusExtension$OCSPStatusRequest::EMPTY_OCSP_MULTI, multiReq);
	}
}

CertStatusExtension$OCSPStatusRequest::CertStatusExtension$OCSPStatusRequest() {
}

$Class* CertStatusExtension$OCSPStatusRequest::load$($String* name, bool initialize) {
	$loadClass(CertStatusExtension$OCSPStatusRequest, name, initialize, &_CertStatusExtension$OCSPStatusRequest_ClassInfo_, clinit$CertStatusExtension$OCSPStatusRequest, allocate$CertStatusExtension$OCSPStatusRequest);
	return class$;
}

$Class* CertStatusExtension$OCSPStatusRequest::class$ = nullptr;

		} // ssl
	} // security
} // sun