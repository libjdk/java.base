#include <sun/security/ssl/CertificateStatus$CertificateStatusMessage.h>

#include <java/io/IOException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/provider/certpath/OCSPResponse.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestType.h>
#include <sun/security/ssl/CertificateStatus.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/StatusResponseManager$StaplingParameters.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef CERTIFICATE_STATUS
#undef ENGLISH
#undef HANDSHAKE_FAILURE
#undef INTERNAL_ERROR
#undef OCSP
#undef OCSP_MULTI

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $OCSPResponse = ::sun::security::provider::certpath::OCSPResponse;
using $Alert = ::sun::security::ssl::Alert;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $Record = ::sun::security::ssl::Record;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $StatusResponseManager$StaplingParameters = ::sun::security::ssl::StatusResponseManager$StaplingParameters;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertificateStatus$CertificateStatusMessage_FieldInfo_[] = {
	{"statusType", "Lsun/security/ssl/CertStatusExtension$CertStatusRequestType;", nullptr, $FINAL, $field(CertificateStatus$CertificateStatusMessage, statusType)},
	{"encodedResponsesLen", "I", nullptr, $FINAL, $field(CertificateStatus$CertificateStatusMessage, encodedResponsesLen)},
	{"messageLength", "I", nullptr, $FINAL, $field(CertificateStatus$CertificateStatusMessage, messageLength$)},
	{"encodedResponses", "Ljava/util/List;", "Ljava/util/List<[B>;", $FINAL, $field(CertificateStatus$CertificateStatusMessage, encodedResponses)},
	{}
};

$MethodInfo _CertificateStatus$CertificateStatusMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;)V", nullptr, 0, $method(CertificateStatus$CertificateStatusMessage, init$, void, $HandshakeContext*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(CertificateStatus$CertificateStatusMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(CertificateStatus$CertificateStatusMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "(Lsun/security/ssl/CertStatusExtension$CertStatusRequestType;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateStatus$CertificateStatusMessage, messageLength, int32_t, $CertStatusExtension$CertStatusRequestType*, int32_t)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(CertificateStatus$CertificateStatusMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificateStatus$CertificateStatusMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateStatus$CertificateStatusMessage, toString, $String*)},
	{}
};

$InnerClassInfo _CertificateStatus$CertificateStatusMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateStatus$CertificateStatusMessage", "sun.security.ssl.CertificateStatus", "CertificateStatusMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _CertificateStatus$CertificateStatusMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateStatus$CertificateStatusMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_CertificateStatus$CertificateStatusMessage_FieldInfo_,
	_CertificateStatus$CertificateStatusMessage_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateStatus$CertificateStatusMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateStatus"
};

$Object* allocate$CertificateStatus$CertificateStatusMessage($Class* clazz) {
	return $of($alloc(CertificateStatus$CertificateStatusMessage));
}

void CertificateStatus$CertificateStatusMessage::init$($HandshakeContext* handshakeContext) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$set(this, encodedResponses, $new($ArrayList));
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, handshakeContext));
	$var($StatusResponseManager$StaplingParameters, stapleParams, $nc(shc)->stapleParams);
	if (stapleParams == nullptr) {
		$throwNew($IllegalArgumentException, "Unexpected null stapling parameters"_s);
	}
	$var($X509CertificateArray, certChain, $fcast($X509CertificateArray, $nc(shc->handshakeSession)->getLocalCertificates()));
	if (certChain == nullptr) {
		$throwNew($IllegalArgumentException, "Unexpected null certificate chain"_s);
	}
	$set(this, statusType, $nc(stapleParams)->statReqType);
	int32_t encodedLen = 0;
	$init($CertStatusExtension$CertStatusRequestType);
	if (this->statusType == $CertStatusExtension$CertStatusRequestType::OCSP) {
		$var($bytes, resp, $cast($bytes, $nc(stapleParams->responseMap)->get($nc(certChain)->get(0))));
		if (resp == nullptr) {
			$assign(resp, $new($bytes, 0));
		}
		$nc(this->encodedResponses)->add(resp);
		encodedLen += $nc(resp)->length + 3;
	} else {
		if (this->statusType == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI) {
			{
				$var($X509CertificateArray, arr$, certChain);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($X509Certificate, cert, arr$->get(i$));
					{
						$var($bytes, resp, $cast($bytes, $nc(stapleParams->responseMap)->get(cert)));
						if (resp == nullptr) {
							$assign(resp, $new($bytes, 0));
						}
						$nc(this->encodedResponses)->add(resp);
						encodedLen += $nc(resp)->length + 3;
					}
				}
			}
		} else {
			$throwNew($IllegalArgumentException, $$str({"Unsupported StatusResponseType: "_s, this->statusType}));
		}
	}
	this->encodedResponsesLen = encodedLen;
	this->messageLength$ = messageLength(this->statusType, this->encodedResponsesLen);
}

void CertificateStatus$CertificateStatusMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$set(this, encodedResponses, $new($ArrayList));
	$set(this, statusType, $CertStatusExtension$CertStatusRequestType::valueOf((int8_t)$Record::getInt8(m)));
	if (this->statusType == $CertStatusExtension$CertStatusRequestType::OCSP) {
		$var($bytes, respDER, $Record::getBytes24(m));
		if ($nc(respDER)->length > 0) {
			$nc(this->encodedResponses)->add(respDER);
			this->encodedResponsesLen = 3 + respDER->length;
		} else {
			$init($Alert);
			$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Zero-length OCSP Response"_s)));
		}
	} else {
		if (this->statusType == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI) {
			int32_t respListLen = $Record::getInt24(m);
			this->encodedResponsesLen = respListLen;
			while (respListLen > 0) {
				$var($bytes, respDER, $Record::getBytes24(m));
				$nc(this->encodedResponses)->add(respDER);
				respListLen -= ($nc(respDER)->length + 3);
			}
			if (respListLen != 0) {
				$init($Alert);
				$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::INTERNAL_ERROR, "Bad OCSP response list length"_s)));
			}
		} else {
			$init($Alert);
			$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Unsupported StatusResponseType: "_s, this->statusType}))));
		}
	}
	this->messageLength$ = messageLength(this->statusType, this->encodedResponsesLen);
}

int32_t CertificateStatus$CertificateStatusMessage::messageLength($CertStatusExtension$CertStatusRequestType* statusType, int32_t encodedResponsesLen) {
	$init(CertificateStatus$CertificateStatusMessage);
	$init($CertStatusExtension$CertStatusRequestType);
	if (statusType == $CertStatusExtension$CertStatusRequestType::OCSP) {
		return 1 + encodedResponsesLen;
	} else {
		if (statusType == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI) {
			return 4 + encodedResponsesLen;
		}
	}
	return -1;
}

$SSLHandshake* CertificateStatus$CertificateStatusMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::CERTIFICATE_STATUS;
}

int32_t CertificateStatus$CertificateStatusMessage::messageLength() {
	return this->messageLength$;
}

void CertificateStatus$CertificateStatusMessage::send($HandshakeOutStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->putInt8(this->statusType->id);
	$init($CertStatusExtension$CertStatusRequestType);
	if (this->statusType == $CertStatusExtension$CertStatusRequestType::OCSP) {
		s->putBytes24($cast($bytes, $($nc(this->encodedResponses)->get(0))));
	} else {
		if (this->statusType == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI) {
			s->putInt24(this->encodedResponsesLen);
			{
				$var($Iterator, i$, $nc(this->encodedResponses)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($bytes, respBytes, $cast($bytes, i$->next()));
					{
						s->putBytes24(respBytes);
					}
				}
			}
		} else {
			$throwNew($SSLHandshakeException, $$str({"Unsupported status_type: "_s, $$str(this->statusType->id)}));
		}
	}
}

$String* CertificateStatus$CertificateStatusMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	{
		$var($Iterator, i$, $nc(this->encodedResponses)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, respDER, $cast($bytes, i$->next()));
			{
				if ($nc(respDER)->length > 0) {
					try {
						$var($OCSPResponse, oResp, $new($OCSPResponse, respDER));
						sb->append($(oResp->toString()))->append("\n"_s);
					} catch ($IOException& ioe) {
						sb->append("OCSP Response Exception: "_s)->append($of(ioe))->append("\n"_s);
					}
				} else {
					sb->append("<Zero-length entry>\n"_s);
				}
			}
		}
	}
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"CertificateStatus\": \'{\'\n  \"type\"                : \"{0}\",\n  \"responses \"          : [\n{1}\n  ]\n\'}\'"_s, $Locale::ENGLISH));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$of(this->statusType->name$),
		$($of($Utilities::indent($($Utilities::indent($(sb->toString()))))))
	}));
	return messageFormat->format(messageFields);
}

CertificateStatus$CertificateStatusMessage::CertificateStatus$CertificateStatusMessage() {
}

$Class* CertificateStatus$CertificateStatusMessage::load$($String* name, bool initialize) {
	$loadClass(CertificateStatus$CertificateStatusMessage, name, initialize, &_CertificateStatus$CertificateStatusMessage_ClassInfo_, allocate$CertificateStatus$CertificateStatusMessage);
	return class$;
}

$Class* CertificateStatus$CertificateStatusMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun