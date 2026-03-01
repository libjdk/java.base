#include <sun/security/ssl/RSAServerKeyExchange$RSAServerKeyExchangeMessage.h>

#include <java/math/BigInteger.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/RSAPublicKeySpec.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/JsseJce.h>
#include <sun/security/ssl/RSAKeyExchange$EphemeralRSAPossession.h>
#include <sun/security/ssl/RSAServerKeyExchange.h>
#include <sun/security/ssl/RSASignature.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef ENGLISH
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR
#undef SERVER_KEY_EXCHANGE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $RSAPublicKeySpec = ::java::security::spec::RSAPublicKeySpec;
using $MessageFormat = ::java::text::MessageFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $JsseJce = ::sun::security::ssl::JsseJce;
using $RSAKeyExchange$EphemeralRSAPossession = ::sun::security::ssl::RSAKeyExchange$EphemeralRSAPossession;
using $RSASignature = ::sun::security::ssl::RSASignature;
using $Record = ::sun::security::ssl::Record;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _RSAServerKeyExchange$RSAServerKeyExchangeMessage_FieldInfo_[] = {
	{"modulus", "[B", nullptr, $PRIVATE | $FINAL, $field(RSAServerKeyExchange$RSAServerKeyExchangeMessage, modulus)},
	{"exponent", "[B", nullptr, $PRIVATE | $FINAL, $field(RSAServerKeyExchange$RSAServerKeyExchangeMessage, exponent)},
	{"paramsSignature", "[B", nullptr, $PRIVATE | $FINAL, $field(RSAServerKeyExchange$RSAServerKeyExchangeMessage, paramsSignature)},
	{}
};

$MethodInfo _RSAServerKeyExchange$RSAServerKeyExchangeMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/X509Authentication$X509Possession;Lsun/security/ssl/RSAKeyExchange$EphemeralRSAPossession;)V", nullptr, $PRIVATE, $method(RSAServerKeyExchange$RSAServerKeyExchangeMessage, init$, void, $HandshakeContext*, $X509Authentication$X509Possession*, $RSAKeyExchange$EphemeralRSAPossession*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(RSAServerKeyExchange$RSAServerKeyExchangeMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, 0, $virtualMethod(RSAServerKeyExchange$RSAServerKeyExchangeMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, 0, $virtualMethod(RSAServerKeyExchange$RSAServerKeyExchangeMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, 0, $virtualMethod(RSAServerKeyExchange$RSAServerKeyExchangeMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(RSAServerKeyExchange$RSAServerKeyExchangeMessage, toString, $String*)},
	{"updateSignature", "(Ljava/security/Signature;[B[B)V", nullptr, $PRIVATE, $method(RSAServerKeyExchange$RSAServerKeyExchangeMessage, updateSignature, void, $Signature*, $bytes*, $bytes*), "java.security.SignatureException"},
	{}
};

$InnerClassInfo _RSAServerKeyExchange$RSAServerKeyExchangeMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.RSAServerKeyExchange$RSAServerKeyExchangeMessage", "sun.security.ssl.RSAServerKeyExchange", "RSAServerKeyExchangeMessage", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _RSAServerKeyExchange$RSAServerKeyExchangeMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.RSAServerKeyExchange$RSAServerKeyExchangeMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_RSAServerKeyExchange$RSAServerKeyExchangeMessage_FieldInfo_,
	_RSAServerKeyExchange$RSAServerKeyExchangeMessage_MethodInfo_,
	nullptr,
	nullptr,
	_RSAServerKeyExchange$RSAServerKeyExchangeMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.RSAServerKeyExchange"
};

$Object* allocate$RSAServerKeyExchange$RSAServerKeyExchangeMessage($Class* clazz) {
	return $of($alloc(RSAServerKeyExchange$RSAServerKeyExchangeMessage));
}

void RSAServerKeyExchange$RSAServerKeyExchangeMessage::init$($HandshakeContext* handshakeContext, $X509Authentication$X509Possession* x509Possession, $RSAKeyExchange$EphemeralRSAPossession* rsaPossession) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, handshakeContext));
	$var($RSAPublicKey, publicKey, $nc(rsaPossession)->popPublicKey);
	$var($RSAPublicKeySpec, spec, $JsseJce::getRSAPublicKeySpec(publicKey));
	$set(this, modulus, $Utilities::toByteArray($($nc(spec)->getModulus())));
	$set(this, exponent, $Utilities::toByteArray($($nc(spec)->getPublicExponent())));
	$var($bytes, signature, nullptr);
	try {
		$var($Signature, signer, $RSASignature::getInstance());
		$nc(signer)->initSign($nc(x509Possession)->popPrivateKey, $($nc($nc(shc)->sslContext)->getSecureRandom()));
		updateSignature(signer, $nc($nc(shc)->clientHelloRandom)->randomBytes, $nc(shc->serverHelloRandom)->randomBytes);
		$assign(signature, signer->sign());
	} catch ($NoSuchAlgorithmException& ex) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::INTERNAL_ERROR, "Failed to sign ephemeral RSA parameters"_s, ex)));
	} catch ($InvalidKeyException& ex) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::INTERNAL_ERROR, "Failed to sign ephemeral RSA parameters"_s, ex)));
	} catch ($SignatureException& ex) {
		$init($Alert);
		$throw($($nc($nc(shc)->conContext)->fatal($Alert::INTERNAL_ERROR, "Failed to sign ephemeral RSA parameters"_s, ex)));
	}
	$set(this, paramsSignature, signature);
}

void RSAServerKeyExchange$RSAServerKeyExchangeMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, handshakeContext));
	$set(this, modulus, $Record::getBytes16(m));
	$set(this, exponent, $Record::getBytes16(m));
	$set(this, paramsSignature, $Record::getBytes16(m));
	$var($X509Authentication$X509Credentials, x509Credentials, nullptr);
	{
		$var($Iterator, i$, $nc($nc(chc)->handshakeCredentials)->iterator());
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
	if (x509Credentials == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "No RSA credentials negotiated for server key exchange"_s)));
	}
	try {
		$var($Signature, signer, $RSASignature::getInstance());
		$nc(signer)->initVerify($nc(x509Credentials)->popPublicKey);
		updateSignature(signer, $nc(chc->clientHelloRandom)->randomBytes, $nc(chc->serverHelloRandom)->randomBytes);
		if (!signer->verify(this->paramsSignature)) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid signature of RSA ServerKeyExchange message"_s)));
		}
	} catch ($NoSuchAlgorithmException& ex) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "Failed to sign ephemeral RSA parameters"_s, ex)));
	} catch ($InvalidKeyException& ex) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "Failed to sign ephemeral RSA parameters"_s, ex)));
	} catch ($SignatureException& ex) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "Failed to sign ephemeral RSA parameters"_s, ex)));
	}
}

$SSLHandshake* RSAServerKeyExchange$RSAServerKeyExchangeMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::SERVER_KEY_EXCHANGE;
}

int32_t RSAServerKeyExchange$RSAServerKeyExchangeMessage::messageLength() {
	return 6 + $nc(this->modulus)->length + $nc(this->exponent)->length + $nc(this->paramsSignature)->length;
}

void RSAServerKeyExchange$RSAServerKeyExchangeMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->putBytes16(this->modulus);
	hos->putBytes16(this->exponent);
	hos->putBytes16(this->paramsSignature);
}

$String* RSAServerKeyExchange$RSAServerKeyExchangeMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"RSA ServerKeyExchange\": \'{\'\n  \"parameters\": \'{\'\n    \"rsa_modulus\": \'{\'\n{0}\n    \'}\',\n    \"rsa_exponent\": \'{\'\n{1}\n    \'}\'\n  \'}\',\n  \"digital signature\":  \'{\'\n    \"signature\": \'{\'\n{2}\n    \'}\',\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->modulus)), "      "_s))),
		$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->exponent)), "      "_s))),
		$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->paramsSignature)), "      "_s)))
	}));
	return messageFormat->format(messageFields);
}

void RSAServerKeyExchange$RSAServerKeyExchangeMessage::updateSignature($Signature* signature, $bytes* clntNonce, $bytes* svrNonce) {
	$nc(signature)->update(clntNonce);
	signature->update(svrNonce);
	signature->update((int8_t)($nc(this->modulus)->length >> 8));
	signature->update((int8_t)((int32_t)($nc(this->modulus)->length & (uint32_t)255)));
	signature->update(this->modulus);
	signature->update((int8_t)($nc(this->exponent)->length >> 8));
	signature->update((int8_t)((int32_t)($nc(this->exponent)->length & (uint32_t)255)));
	signature->update(this->exponent);
}

RSAServerKeyExchange$RSAServerKeyExchangeMessage::RSAServerKeyExchange$RSAServerKeyExchangeMessage() {
}

$Class* RSAServerKeyExchange$RSAServerKeyExchangeMessage::load$($String* name, bool initialize) {
	$loadClass(RSAServerKeyExchange$RSAServerKeyExchangeMessage, name, initialize, &_RSAServerKeyExchange$RSAServerKeyExchangeMessage_ClassInfo_, allocate$RSAServerKeyExchange$RSAServerKeyExchangeMessage);
	return class$;
}

$Class* RSAServerKeyExchange$RSAServerKeyExchangeMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun