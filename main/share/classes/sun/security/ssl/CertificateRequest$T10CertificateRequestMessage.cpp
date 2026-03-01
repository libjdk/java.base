#include <sun/security/ssl/CertificateRequest$T10CertificateRequestMessage.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/cert/X509Certificate.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertificateRequest$ClientCertificateType.h>
#include <sun/security/ssl/CertificateRequest.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef CERTIFICATE_REQUEST
#undef CERT_TYPES
#undef ENGLISH
#undef ILLEGAL_PARAMETER

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $X500PrincipalArray = $Array<::javax::security::auth::x500::X500Principal>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $Alert = ::sun::security::ssl::Alert;
using $CertificateRequest$ClientCertificateType = ::sun::security::ssl::CertificateRequest$ClientCertificateType;
using $CipherSuite$KeyExchange = ::sun::security::ssl::CipherSuite$KeyExchange;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $Record = ::sun::security::ssl::Record;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertificateRequest$T10CertificateRequestMessage_FieldInfo_[] = {
	{"types", "[B", nullptr, $FINAL, $field(CertificateRequest$T10CertificateRequestMessage, types)},
	{"authorities", "Ljava/util/List;", "Ljava/util/List<[B>;", $FINAL, $field(CertificateRequest$T10CertificateRequestMessage, authorities)},
	{}
};

$MethodInfo _CertificateRequest$T10CertificateRequestMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;[Ljava/security/cert/X509Certificate;Lsun/security/ssl/CipherSuite$KeyExchange;)V", nullptr, 0, $method(CertificateRequest$T10CertificateRequestMessage, init$, void, $HandshakeContext*, $X509CertificateArray*, $CipherSuite$KeyExchange*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(CertificateRequest$T10CertificateRequestMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"getAuthorities", "()[Ljavax/security/auth/x500/X500Principal;", nullptr, 0, $method(CertificateRequest$T10CertificateRequestMessage, getAuthorities, $X500PrincipalArray*)},
	{"getKeyTypes", "()[Ljava/lang/String;", nullptr, 0, $method(CertificateRequest$T10CertificateRequestMessage, getKeyTypes, $StringArray*)},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(CertificateRequest$T10CertificateRequestMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(CertificateRequest$T10CertificateRequestMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificateRequest$T10CertificateRequestMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateRequest$T10CertificateRequestMessage, toString, $String*)},
	{}
};

$InnerClassInfo _CertificateRequest$T10CertificateRequestMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateRequest$T10CertificateRequestMessage", "sun.security.ssl.CertificateRequest", "T10CertificateRequestMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _CertificateRequest$T10CertificateRequestMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateRequest$T10CertificateRequestMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_CertificateRequest$T10CertificateRequestMessage_FieldInfo_,
	_CertificateRequest$T10CertificateRequestMessage_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateRequest$T10CertificateRequestMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateRequest"
};

$Object* allocate$CertificateRequest$T10CertificateRequestMessage($Class* clazz) {
	return $of($alloc(CertificateRequest$T10CertificateRequestMessage));
}

void CertificateRequest$T10CertificateRequestMessage::init$($HandshakeContext* handshakeContext, $X509CertificateArray* trustedCerts, $CipherSuite$KeyExchange* keyExchange) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$set(this, authorities, $new($ArrayList, $nc(trustedCerts)->length));
	{
		$var($X509CertificateArray, arr$, trustedCerts);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($X509Certificate, cert, arr$->get(i$));
			{
				$var($X500Principal, x500Principal, $nc(cert)->getSubjectX500Principal());
				$nc(this->authorities)->add($($nc(x500Principal)->getEncoded()));
			}
		}
	}
	$init($CertificateRequest$ClientCertificateType);
	$set(this, types, $CertificateRequest$ClientCertificateType::CERT_TYPES);
}

void CertificateRequest$T10CertificateRequestMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	if ($nc(m)->remaining() < 4) {
		$init($Alert);
		$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Incorrect CertificateRequest message: no sufficient data"_s)));
	}
	$set(this, types, $Record::getBytes8(m));
	int32_t listLen = $Record::getInt16(m);
	if (listLen > $nc(m)->remaining()) {
		$init($Alert);
		$throw($($nc($nc(handshakeContext)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Incorrect CertificateRequest message:no sufficient data"_s)));
	}
	if (listLen > 0) {
		$set(this, authorities, $new($LinkedList));
		while (listLen > 0) {
			$var($bytes, encoded, $Record::getBytes16(m));
			listLen -= (2 + $nc(encoded)->length);
			$nc(this->authorities)->add(encoded);
		}
	} else {
		$set(this, authorities, $Collections::emptyList());
	}
}

$StringArray* CertificateRequest$T10CertificateRequestMessage::getKeyTypes() {
	return $CertificateRequest$ClientCertificateType::getKeyTypes(this->types);
}

$X500PrincipalArray* CertificateRequest$T10CertificateRequestMessage::getAuthorities() {
	$useLocalCurrentObjectStackCache();
	$var($X500PrincipalArray, principals, $new($X500PrincipalArray, $nc(this->authorities)->size()));
	int32_t i = 0;
	{
		$var($Iterator, i$, $nc(this->authorities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, encoded, $cast($bytes, i$->next()));
			{
				principals->set(i++, $$new($X500Principal, encoded));
			}
		}
	}
	return principals;
}

$SSLHandshake* CertificateRequest$T10CertificateRequestMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::CERTIFICATE_REQUEST;
}

int32_t CertificateRequest$T10CertificateRequestMessage::messageLength() {
	$useLocalCurrentObjectStackCache();
	int32_t len = 1 + $nc(this->types)->length + 2;
	{
		$var($Iterator, i$, $nc(this->authorities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, encoded, $cast($bytes, i$->next()));
			{
				len += $nc(encoded)->length + 2;
			}
		}
	}
	return len;
}

void CertificateRequest$T10CertificateRequestMessage::send($HandshakeOutStream* hos) {
	$useLocalCurrentObjectStackCache();
	$nc(hos)->putBytes8(this->types);
	int32_t listLen = 0;
	{
		$var($Iterator, i$, $nc(this->authorities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, encoded, $cast($bytes, i$->next()));
			{
				listLen += $nc(encoded)->length + 2;
			}
		}
	}
	hos->putInt16(listLen);
	{
		$var($Iterator, i$, $nc(this->authorities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, encoded, $cast($bytes, i$->next()));
			{
				hos->putBytes16(encoded);
			}
		}
	}
}

$String* CertificateRequest$T10CertificateRequestMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"CertificateRequest\": \'{\'\n  \"certificate types\": {0}\n  \"certificate authorities\": {1}\n\'}\'"_s, $Locale::ENGLISH));
	$var($List, typeNames, $new($ArrayList, $nc(this->types)->length));
	{
		$var($bytes, arr$, this->types);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int8_t type = arr$->get(i$);
			{
				typeNames->add($($CertificateRequest$ClientCertificateType::nameOf(type)));
			}
		}
	}
	$var($List, authorityNames, $new($ArrayList, $nc(this->authorities)->size()));
	{
		$var($Iterator, i$, $nc(this->authorities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, encoded, $cast($bytes, i$->next()));
			{
				$var($X500Principal, principal, $new($X500Principal, encoded));
				authorityNames->add($(principal->toString()));
			}
		}
	}
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$of(typeNames),
		$of(authorityNames)
	}));
	return messageFormat->format(messageFields);
}

CertificateRequest$T10CertificateRequestMessage::CertificateRequest$T10CertificateRequestMessage() {
}

$Class* CertificateRequest$T10CertificateRequestMessage::load$($String* name, bool initialize) {
	$loadClass(CertificateRequest$T10CertificateRequestMessage, name, initialize, &_CertificateRequest$T10CertificateRequestMessage_ClassInfo_, allocate$CertificateRequest$T10CertificateRequestMessage);
	return class$;
}

$Class* CertificateRequest$T10CertificateRequestMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun