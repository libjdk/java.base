#include <sun/security/ssl/CertificateMessage$T13CertificateMessage.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/cert/X509Certificate.h>
#include <java/text/MessageFormat.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/CertificateMessage$CertificateEntry.h>
#include <sun/security/ssl/CertificateMessage.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLExtensions.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/Utilities.h>
#include <jcpp.h>

#undef CERTIFICATE
#undef ENGLISH

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $MessageFormat = ::java::text::MessageFormat;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $CertificateMessage$CertificateEntry = ::sun::security::ssl::CertificateMessage$CertificateEntry;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $Record = ::sun::security::ssl::Record;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLExtensions = ::sun::security::ssl::SSLExtensions;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $Utilities = ::sun::security::ssl::Utilities;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertificateMessage$T13CertificateMessage_FieldInfo_[] = {
	{"requestContext", "[B", nullptr, $PRIVATE | $FINAL, $field(CertificateMessage$T13CertificateMessage, requestContext)},
	{"certEntries", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/CertificateMessage$CertificateEntry;>;", $PRIVATE | $FINAL, $field(CertificateMessage$T13CertificateMessage, certEntries)},
	{}
};

$MethodInfo _CertificateMessage$T13CertificateMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;[B[Ljava/security/cert/X509Certificate;)V", nullptr, 0, $method(CertificateMessage$T13CertificateMessage, init$, void, $HandshakeContext*, $bytes*, $X509CertificateArray*), "javax.net.ssl.SSLException,java.security.cert.CertificateException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;[BLjava/util/List;)V", "(Lsun/security/ssl/HandshakeContext;[BLjava/util/List<Lsun/security/ssl/CertificateMessage$CertificateEntry;>;)V", 0, $method(CertificateMessage$T13CertificateMessage, init$, void, $HandshakeContext*, $bytes*, $List*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(CertificateMessage$T13CertificateMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T13CertificateMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T13CertificateMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T13CertificateMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateMessage$T13CertificateMessage, toString, $String*)},
	{}
};

$InnerClassInfo _CertificateMessage$T13CertificateMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateMessage$T13CertificateMessage", "sun.security.ssl.CertificateMessage", "T13CertificateMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _CertificateMessage$T13CertificateMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateMessage$T13CertificateMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_CertificateMessage$T13CertificateMessage_FieldInfo_,
	_CertificateMessage$T13CertificateMessage_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateMessage$T13CertificateMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateMessage"
};

$Object* allocate$CertificateMessage$T13CertificateMessage($Class* clazz) {
	return $of($alloc(CertificateMessage$T13CertificateMessage));
}

void CertificateMessage$T13CertificateMessage::init$($HandshakeContext* context, $bytes* requestContext, $X509CertificateArray* certificates) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	$set(this, requestContext, $cast($bytes, $nc(requestContext)->clone()));
	$set(this, certEntries, $new($LinkedList));
	{
		$var($X509CertificateArray, arr$, certificates);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($X509Certificate, cert, arr$->get(i$));
			{
				$var($bytes, encoded, $nc(cert)->getEncoded());
				$var($SSLExtensions, extensions, $new($SSLExtensions, this));
				$nc(this->certEntries)->add($$new($CertificateMessage$CertificateEntry, encoded, extensions));
			}
		}
	}
}

void CertificateMessage$T13CertificateMessage::init$($HandshakeContext* handshakeContext, $bytes* requestContext, $List* certificates) {
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$set(this, requestContext, $cast($bytes, $nc(requestContext)->clone()));
	$set(this, certEntries, certificates);
}

void CertificateMessage$T13CertificateMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	if ($nc(m)->remaining() < 4) {
		$throwNew($SSLProtocolException, $$str({"Invalid Certificate message: insufficient data (length="_s, $$str(m->remaining()), ")"_s}));
	}
	$set(this, requestContext, $Record::getBytes8(m));
	if ($nc(m)->remaining() < 3) {
		$throwNew($SSLProtocolException, $$str({"Invalid Certificate message: insufficient certificate entries data (length="_s, $$str(m->remaining()), ")"_s}));
	}
	int32_t listLen = $Record::getInt24(m);
	if (listLen != $nc(m)->remaining()) {
		$throwNew($SSLProtocolException, $$str({"Invalid Certificate message: incorrect list length (length="_s, $$str(listLen), ")"_s}));
	}
	$init($SSLHandshake);
	$var($SSLExtensionArray, enabledExtensions, $nc($nc(handshakeContext)->sslConfig)->getEnabledExtensions($SSLHandshake::CERTIFICATE));
	$var($List, certList, $new($LinkedList));
	while ($nc(m)->hasRemaining()) {
		$var($bytes, encodedCert, $Record::getBytes24(m));
		if ($nc(encodedCert)->length == 0) {
			$throwNew($SSLProtocolException, "Invalid Certificate message: empty cert_data"_s);
		}
		$var($SSLExtensions, extensions, $new($SSLExtensions, this, m, enabledExtensions));
		certList->add($$new($CertificateMessage$CertificateEntry, encodedCert, extensions));
		if (certList->size() > $SSLConfiguration::maxCertificateChainLength) {
			$throwNew($SSLProtocolException, $$str({"The certificate chain length ("_s, $$str(certList->size()), ") exceeds the maximum allowed length ("_s, $$str($SSLConfiguration::maxCertificateChainLength), ")"_s}));
		}
	}
	$set(this, certEntries, $Collections::unmodifiableList(certList));
}

$SSLHandshake* CertificateMessage$T13CertificateMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::CERTIFICATE;
}

int32_t CertificateMessage$T13CertificateMessage::messageLength() {
	$useLocalCurrentObjectStackCache();
	int32_t msgLen = 4 + $nc(this->requestContext)->length;
	{
		$var($Iterator, i$, $nc(this->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificateMessage$CertificateEntry, entry, $cast($CertificateMessage$CertificateEntry, i$->next()));
			{
				msgLen += $nc(entry)->getEncodedSize();
			}
		}
	}
	return msgLen;
}

void CertificateMessage$T13CertificateMessage::send($HandshakeOutStream* hos) {
	$useLocalCurrentObjectStackCache();
	int32_t entryListLen = 0;
	{
		$var($Iterator, i$, $nc(this->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificateMessage$CertificateEntry, entry, $cast($CertificateMessage$CertificateEntry, i$->next()));
			{
				entryListLen += $nc(entry)->getEncodedSize();
			}
		}
	}
	$nc(hos)->putBytes8(this->requestContext);
	hos->putInt24(entryListLen);
	{
		$var($Iterator, i$, $nc(this->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificateMessage$CertificateEntry, entry, $cast($CertificateMessage$CertificateEntry, i$->next()));
			{
				hos->putBytes24($nc(entry)->encoded);
				if ($nc($nc(entry)->extensions)->length() == 0) {
					hos->putInt16(0);
				} else {
					$nc(entry->extensions)->send(hos);
				}
			}
		}
	}
}

$String* CertificateMessage$T13CertificateMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"Certificate\": \'{\'\n  \"certificate_request_context\": \"{0}\",\n  \"certificate_list\": [{1}\n]\n\'}\'"_s, $Locale::ENGLISH));
	$var($StringBuilder, builder, $new($StringBuilder, 512));
	{
		$var($Iterator, i$, $nc(this->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificateMessage$CertificateEntry, entry, $cast($CertificateMessage$CertificateEntry, i$->next()));
			{
				builder->append($($nc(entry)->toString()));
			}
		}
	}
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$($of($Utilities::toHexString(this->requestContext))),
		$($of($Utilities::indent($(builder->toString()))))
	}));
	return messageFormat->format(messageFields);
}

CertificateMessage$T13CertificateMessage::CertificateMessage$T13CertificateMessage() {
}

$Class* CertificateMessage$T13CertificateMessage::load$($String* name, bool initialize) {
	$loadClass(CertificateMessage$T13CertificateMessage, name, initialize, &_CertificateMessage$T13CertificateMessage_ClassInfo_, allocate$CertificateMessage$T13CertificateMessage);
	return class$;
}

$Class* CertificateMessage$T13CertificateMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun