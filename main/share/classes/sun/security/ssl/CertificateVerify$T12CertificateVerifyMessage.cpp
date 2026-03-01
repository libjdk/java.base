#include <sun/security/ssl/CertificateVerify$T12CertificateVerifyMessage.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertificateVerify.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef CERTIFICATE_VERIFY
#undef ENGLISH
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $MessageFormat = ::java::text::MessageFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map$Entry = ::java::util::Map$Entry;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $Record = ::sun::security::ssl::Record;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertificateVerify$T12CertificateVerifyMessage_FieldInfo_[] = {
	{"signatureScheme", "Lsun/security/ssl/SignatureScheme;", nullptr, $PRIVATE | $FINAL, $field(CertificateVerify$T12CertificateVerifyMessage, signatureScheme)},
	{"signature", "[B", nullptr, $PRIVATE | $FINAL, $field(CertificateVerify$T12CertificateVerifyMessage, signature)},
	{}
};

$MethodInfo _CertificateVerify$T12CertificateVerifyMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/X509Authentication$X509Possession;)V", nullptr, 0, $method(CertificateVerify$T12CertificateVerifyMessage, init$, void, $HandshakeContext*, $X509Authentication$X509Possession*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(CertificateVerify$T12CertificateVerifyMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$T12CertificateVerifyMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$T12CertificateVerifyMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$T12CertificateVerifyMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$T12CertificateVerifyMessage, toString, $String*)},
	{}
};

$InnerClassInfo _CertificateVerify$T12CertificateVerifyMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateVerify$T12CertificateVerifyMessage", "sun.security.ssl.CertificateVerify", "T12CertificateVerifyMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _CertificateVerify$T12CertificateVerifyMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateVerify$T12CertificateVerifyMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_CertificateVerify$T12CertificateVerifyMessage_FieldInfo_,
	_CertificateVerify$T12CertificateVerifyMessage_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateVerify$T12CertificateVerifyMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateVerify"
};

$Object* allocate$CertificateVerify$T12CertificateVerifyMessage($Class* clazz) {
	return $of($alloc(CertificateVerify$T12CertificateVerifyMessage));
}

void CertificateVerify$T12CertificateVerifyMessage::init$($HandshakeContext* context, $X509Authentication$X509Possession* x509Possession) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($Map$Entry, schemeAndSigner, $SignatureScheme::getSignerOfPreferableAlgorithm($nc(chc)->algorithmConstraints, chc->peerRequestedSignatureSchemes, x509Possession, chc->negotiatedProtocol));
	if (schemeAndSigner == nullptr) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"No supported CertificateVerify signature algorithm for "_s, $($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm()), "  key"_s}))));
	}
	$set(this, signatureScheme, $cast($SignatureScheme, $nc(schemeAndSigner)->getKey()));
	$var($bytes, temporary, nullptr);
	try {
		$var($Signature, signer, $cast($Signature, schemeAndSigner->getValue()));
		$nc(signer)->update($($nc($nc(chc)->handshakeHash)->archived()));
		$assign(temporary, signer->sign());
	} catch ($SignatureException& ikse) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot produce CertificateVerify signature"_s, ikse)));
	}
	$set(this, signature, temporary);
}

void CertificateVerify$T12CertificateVerifyMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, handshakeContext));
	if ($nc(m)->remaining() < 4) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Invalid CertificateVerify message: no sufficient data"_s)));
	}
	int32_t ssid = $Record::getInt16(m);
	$set(this, signatureScheme, $SignatureScheme::valueOf(ssid));
	if (this->signatureScheme == nullptr) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Invalid signature algorithm ("_s, $$str(ssid), ") used in CertificateVerify handshake message"_s}))));
	}
	if (!$nc($nc(shc)->localSupportedSignAlgs)->contains(this->signatureScheme)) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Unsupported signature algorithm ("_s, this->signatureScheme->name$, ") used in CertificateVerify handshake message"_s}))));
	}
	$var($X509Authentication$X509Credentials, x509Credentials, nullptr);
	{
		$var($Iterator, i$, $nc($nc(shc)->handshakeCredentials)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLCredentials, cd, $cast($SSLCredentials, i$->next()));
			{
				if ($instanceOf($X509Authentication$X509Credentials, cd)) {
					$assign(x509Credentials, $cast($X509Authentication$X509Credentials, cd));
					break;
				}
			}
		}
	}
	if (x509Credentials == nullptr || $nc(x509Credentials)->popPublicKey == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "No X509 credentials negotiated for CertificateVerify"_s)));
	}
	$set(this, signature, $Record::getBytes16(m));
	try {
		$var($Signature, signer, this->signatureScheme->getVerifier($nc(x509Credentials)->popPublicKey));
		$nc(signer)->update($($nc(shc->handshakeHash)->archived()));
		if (!signer->verify(this->signature)) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid CertificateVerify signature"_s)));
		}
	} catch ($NoSuchAlgorithmException& nsae) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm ("_s, this->signatureScheme->name$, ") used in CertificateVerify handshake message"_s}), nsae)));
	} catch ($InvalidAlgorithmParameterException& nsae) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm ("_s, this->signatureScheme->name$, ") used in CertificateVerify handshake message"_s}), nsae)));
	} catch ($InvalidKeyException& ikse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot verify CertificateVerify signature"_s, ikse)));
	} catch ($SignatureException& ikse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot verify CertificateVerify signature"_s, ikse)));
	}
}

$SSLHandshake* CertificateVerify$T12CertificateVerifyMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::CERTIFICATE_VERIFY;
}

int32_t CertificateVerify$T12CertificateVerifyMessage::messageLength() {
	return 4 + $nc(this->signature)->length;
}

void CertificateVerify$T12CertificateVerifyMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->putInt16(this->signatureScheme->id);
	hos->putBytes16(this->signature);
}

$String* CertificateVerify$T12CertificateVerifyMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"CertificateVerify\": \'{\'\n  \"signature algorithm\": {0}\n  \"signature\": \'{\'\n{1}\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$of(this->signatureScheme->name$),
		$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->signature)), "    "_s)))
	}));
	return messageFormat->format(messageFields);
}

CertificateVerify$T12CertificateVerifyMessage::CertificateVerify$T12CertificateVerifyMessage() {
}

$Class* CertificateVerify$T12CertificateVerifyMessage::load$($String* name, bool initialize) {
	$loadClass(CertificateVerify$T12CertificateVerifyMessage, name, initialize, &_CertificateVerify$T12CertificateVerifyMessage_ClassInfo_, allocate$CertificateVerify$T12CertificateVerifyMessage);
	return class$;
}

$Class* CertificateVerify$T12CertificateVerifyMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun