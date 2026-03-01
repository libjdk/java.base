#include <sun/security/ssl/CertificateVerify$S30CertificateVerifyMessage.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CertificateVerify.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/JsseJce.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
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
#undef SIGNATURE_RAWDSA
#undef SIGNATURE_RAWECDSA
#undef SIGNATURE_RAWRSA

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $MessageFormat = ::java::text::MessageFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $JsseJce = ::sun::security::ssl::JsseJce;
using $Record = ::sun::security::ssl::Record;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CertificateVerify$S30CertificateVerifyMessage_FieldInfo_[] = {
	{"signature", "[B", nullptr, $PRIVATE | $FINAL, $field(CertificateVerify$S30CertificateVerifyMessage, signature)},
	{}
};

$MethodInfo _CertificateVerify$S30CertificateVerifyMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/X509Authentication$X509Possession;)V", nullptr, 0, $method(CertificateVerify$S30CertificateVerifyMessage, init$, void, $HandshakeContext*, $X509Authentication$X509Possession*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(CertificateVerify$S30CertificateVerifyMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"getSignature", "(Ljava/lang/String;Ljava/security/Key;)Ljava/security/Signature;", nullptr, $PRIVATE | $STATIC, $staticMethod(CertificateVerify$S30CertificateVerifyMessage, getSignature, $Signature*, $String*, $Key*), "java.security.GeneralSecurityException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$S30CertificateVerifyMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$S30CertificateVerifyMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$S30CertificateVerifyMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateVerify$S30CertificateVerifyMessage, toString, $String*)},
	{}
};

$InnerClassInfo _CertificateVerify$S30CertificateVerifyMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.CertificateVerify$S30CertificateVerifyMessage", "sun.security.ssl.CertificateVerify", "S30CertificateVerifyMessage", $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _CertificateVerify$S30CertificateVerifyMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.CertificateVerify$S30CertificateVerifyMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_CertificateVerify$S30CertificateVerifyMessage_FieldInfo_,
	_CertificateVerify$S30CertificateVerifyMessage_MethodInfo_,
	nullptr,
	nullptr,
	_CertificateVerify$S30CertificateVerifyMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CertificateVerify"
};

$Object* allocate$CertificateVerify$S30CertificateVerifyMessage($Class* clazz) {
	return $of($alloc(CertificateVerify$S30CertificateVerifyMessage));
}

void CertificateVerify$S30CertificateVerifyMessage::init$($HandshakeContext* context, $X509Authentication$X509Possession* x509Possession) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($bytes, temporary, nullptr);
	$var($String, algorithm, $nc($nc(x509Possession)->popPrivateKey)->getAlgorithm());
	try {
		$var($Signature, signer, getSignature(algorithm, x509Possession->popPrivateKey));
		$var($bytes, hashes, $nc($nc(chc)->handshakeHash)->digest(algorithm, $($nc(chc->handshakeSession)->getMasterSecret())));
		$nc(signer)->update(hashes);
		$assign(temporary, signer->sign());
	} catch ($NoSuchAlgorithmException& nsae) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm ("_s, algorithm, ") used in CertificateVerify handshake message"_s}), nsae)));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot produce CertificateVerify signature"_s, gse)));
	}
	$set(this, signature, temporary);
}

void CertificateVerify$S30CertificateVerifyMessage::init$($HandshakeContext* context, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	if ($nc(m)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Invalid CertificateVerify message: no sufficient data"_s)));
	}
	$set(this, signature, $Record::getBytes16(m));
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
	$var($String, algorithm, $nc($nc(x509Credentials)->popPublicKey)->getAlgorithm());
	try {
		$var($Signature, signer, getSignature(algorithm, x509Credentials->popPublicKey));
		$var($bytes, hashes, $nc(shc->handshakeHash)->digest(algorithm, $($nc(shc->handshakeSession)->getMasterSecret())));
		$nc(signer)->update(hashes);
		if (!signer->verify(this->signature)) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid CertificateVerify message: invalid signature"_s)));
		}
	} catch ($NoSuchAlgorithmException& nsae) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm ("_s, algorithm, ") used in CertificateVerify handshake message"_s}), nsae)));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot verify CertificateVerify signature"_s, gse)));
	}
}

$SSLHandshake* CertificateVerify$S30CertificateVerifyMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::CERTIFICATE_VERIFY;
}

int32_t CertificateVerify$S30CertificateVerifyMessage::messageLength() {
	return 2 + $nc(this->signature)->length;
}

void CertificateVerify$S30CertificateVerifyMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->putBytes16(this->signature);
}

$String* CertificateVerify$S30CertificateVerifyMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"CertificateVerify\": \'{\'\n  \"signature\": \'{\'\n{0}\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->signature)), "    "_s)))}));
	return messageFormat->format(messageFields);
}

$Signature* CertificateVerify$S30CertificateVerifyMessage::getSignature($String* algorithm, $Key* key) {
	$init(CertificateVerify$S30CertificateVerifyMessage);
	$useLocalCurrentObjectStackCache();
	$var($Signature, signer, nullptr);
	{
		$var($String, s7950$, algorithm);
		int32_t tmp7950$ = -1;
		switch ($nc(s7950$)->hashCode()) {
		case 0x00013E20:
			{
				if (s7950$->equals("RSA"_s)) {
					tmp7950$ = 0;
				}
				break;
			}
		case 0x00010992:
			{
				if (s7950$->equals("DSA"_s)) {
					tmp7950$ = 1;
				}
				break;
			}
		case 2206:
			{
				if (s7950$->equals("EC"_s)) {
					tmp7950$ = 2;
				}
				break;
			}
		}
		switch (tmp7950$) {
		case 0:
			{
				$init($JsseJce);
				$assign(signer, $Signature::getInstance($JsseJce::SIGNATURE_RAWRSA));
				break;
			}
		case 1:
			{
				$init($JsseJce);
				$assign(signer, $Signature::getInstance($JsseJce::SIGNATURE_RAWDSA));
				break;
			}
		case 2:
			{
				$init($JsseJce);
				$assign(signer, $Signature::getInstance($JsseJce::SIGNATURE_RAWECDSA));
				break;
			}
		default:
			{
				$throwNew($SignatureException, $$str({"Unrecognized algorithm: "_s, algorithm}));
			}
		}
	}
	if (signer != nullptr) {
		if ($instanceOf($PublicKey, key)) {
			signer->initVerify(($cast($PublicKey, key)));
		} else {
			signer->initSign($cast($PrivateKey, key));
		}
	}
	return signer;
}

CertificateVerify$S30CertificateVerifyMessage::CertificateVerify$S30CertificateVerifyMessage() {
}

$Class* CertificateVerify$S30CertificateVerifyMessage::load$($String* name, bool initialize) {
	$loadClass(CertificateVerify$S30CertificateVerifyMessage, name, initialize, &_CertificateVerify$S30CertificateVerifyMessage_ClassInfo_, allocate$CertificateVerify$S30CertificateVerifyMessage);
	return class$;
}

$Class* CertificateVerify$S30CertificateVerifyMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun