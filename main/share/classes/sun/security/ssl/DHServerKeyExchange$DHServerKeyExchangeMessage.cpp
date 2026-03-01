#include <sun/security/ssl/DHServerKeyExchange$DHServerKeyExchangeMessage.h>

#include <java/math/BigInteger.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/spec/KeySpec.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <javax/crypto/interfaces/DHPublicKey.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <javax/crypto/spec/DHPublicKeySpec.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/DHKeyExchange$DHEPossession.h>
#include <sun/security/ssl/DHServerKeyExchange.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/JsseJce.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RSASignature.h>
#include <sun/security/ssl/RandomCookie.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/SignatureScheme.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KeyUtil.h>
#include <jcpp.h>

#undef ENGLISH
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR
#undef SERVER_KEY_EXCHANGE
#undef SIGNATURE_DSA

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $KeySpec = ::java::security::spec::KeySpec;
using $MessageFormat = ::java::text::MessageFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map$Entry = ::java::util::Map$Entry;
using $DHPublicKey = ::javax::crypto::interfaces::DHPublicKey;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $DHPublicKeySpec = ::javax::crypto::spec::DHPublicKeySpec;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $DHKeyExchange$DHEPossession = ::sun::security::ssl::DHKeyExchange$DHEPossession;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $JsseJce = ::sun::security::ssl::JsseJce;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $RSASignature = ::sun::security::ssl::RSASignature;
using $Record = ::sun::security::ssl::Record;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KeyUtil = ::sun::security::util::KeyUtil;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _DHServerKeyExchange$DHServerKeyExchangeMessage_FieldInfo_[] = {
	{"p", "[B", nullptr, $PRIVATE | $FINAL, $field(DHServerKeyExchange$DHServerKeyExchangeMessage, p)},
	{"g", "[B", nullptr, $PRIVATE | $FINAL, $field(DHServerKeyExchange$DHServerKeyExchangeMessage, g)},
	{"y", "[B", nullptr, $PRIVATE | $FINAL, $field(DHServerKeyExchange$DHServerKeyExchangeMessage, y)},
	{"useExplicitSigAlgorithm", "Z", nullptr, $PRIVATE | $FINAL, $field(DHServerKeyExchange$DHServerKeyExchangeMessage, useExplicitSigAlgorithm)},
	{"signatureScheme", "Lsun/security/ssl/SignatureScheme;", nullptr, $PRIVATE | $FINAL, $field(DHServerKeyExchange$DHServerKeyExchangeMessage, signatureScheme)},
	{"paramsSignature", "[B", nullptr, $PRIVATE | $FINAL, $field(DHServerKeyExchange$DHServerKeyExchangeMessage, paramsSignature)},
	{}
};

$MethodInfo _DHServerKeyExchange$DHServerKeyExchangeMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;)V", nullptr, 0, $method(DHServerKeyExchange$DHServerKeyExchangeMessage, init$, void, $HandshakeContext*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(DHServerKeyExchange$DHServerKeyExchangeMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"getSignature", "(Ljava/lang/String;Ljava/security/Key;)Ljava/security/Signature;", nullptr, $PRIVATE | $STATIC, $staticMethod(DHServerKeyExchange$DHServerKeyExchangeMessage, getSignature, $Signature*, $String*, $Key*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(DHServerKeyExchange$DHServerKeyExchangeMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(DHServerKeyExchange$DHServerKeyExchangeMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(DHServerKeyExchange$DHServerKeyExchangeMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DHServerKeyExchange$DHServerKeyExchangeMessage, toString, $String*)},
	{"updateSignature", "(Ljava/security/Signature;[B[B)V", nullptr, $PRIVATE, $method(DHServerKeyExchange$DHServerKeyExchangeMessage, updateSignature, void, $Signature*, $bytes*, $bytes*), "java.security.SignatureException"},
	{}
};

$InnerClassInfo _DHServerKeyExchange$DHServerKeyExchangeMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.DHServerKeyExchange$DHServerKeyExchangeMessage", "sun.security.ssl.DHServerKeyExchange", "DHServerKeyExchangeMessage", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _DHServerKeyExchange$DHServerKeyExchangeMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.DHServerKeyExchange$DHServerKeyExchangeMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_DHServerKeyExchange$DHServerKeyExchangeMessage_FieldInfo_,
	_DHServerKeyExchange$DHServerKeyExchangeMessage_MethodInfo_,
	nullptr,
	nullptr,
	_DHServerKeyExchange$DHServerKeyExchangeMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.DHServerKeyExchange"
};

$Object* allocate$DHServerKeyExchange$DHServerKeyExchangeMessage($Class* clazz) {
	return $of($alloc(DHServerKeyExchange$DHServerKeyExchangeMessage));
}

void DHServerKeyExchange$DHServerKeyExchangeMessage::init$($HandshakeContext* handshakeContext) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, handshakeContext));
	$var($DHKeyExchange$DHEPossession, dhePossession, nullptr);
	$var($X509Authentication$X509Possession, x509Possession, nullptr);
	{
		$var($Iterator, i$, $nc($nc(shc)->handshakePossessions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLPossession, possession, $cast($SSLPossession, i$->next()));
			{
				if ($instanceOf($DHKeyExchange$DHEPossession, possession)) {
					$assign(dhePossession, $cast($DHKeyExchange$DHEPossession, possession));
					if (x509Possession != nullptr) {
						break;
					}
				} else if ($instanceOf($X509Authentication$X509Possession, possession)) {
					$assign(x509Possession, $cast($X509Authentication$X509Possession, possession));
					if (dhePossession != nullptr) {
						break;
					}
				}
			}
		}
	}
	if (dhePossession == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "No DHE credentials negotiated for server key exchange"_s)));
	}
	$var($DHPublicKey, publicKey, $nc(dhePossession)->publicKey);
	$var($DHParameterSpec, params, $nc(publicKey)->getParams());
	$set(this, p, $Utilities::toByteArray($($nc(params)->getP())));
	$set(this, g, $Utilities::toByteArray($($nc(params)->getG())));
	$set(this, y, $Utilities::toByteArray($(publicKey->getY())));
	if (x509Possession == nullptr) {
		$set(this, paramsSignature, nullptr);
		$set(this, signatureScheme, nullptr);
		this->useExplicitSigAlgorithm = false;
	} else {
		this->useExplicitSigAlgorithm = $nc(shc->negotiatedProtocol)->useTLS12PlusSpec();
		$var($Signature, signer, nullptr);
		if (this->useExplicitSigAlgorithm) {
			$var($Map$Entry, schemeAndSigner, $SignatureScheme::getSignerOfPreferableAlgorithm(shc->algorithmConstraints, shc->peerRequestedSignatureSchemes, x509Possession, shc->negotiatedProtocol));
			if (schemeAndSigner == nullptr) {
				$init($Alert);
				$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"No supported signature algorithm for "_s, $($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm()), "  key"_s}))));
			} else {
				$set(this, signatureScheme, $cast($SignatureScheme, $nc(schemeAndSigner)->getKey()));
				$assign(signer, $cast($Signature, schemeAndSigner->getValue()));
			}
		} else {
			$set(this, signatureScheme, nullptr);
			try {
				$assign(signer, getSignature($($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm()), x509Possession->popPrivateKey));
			} catch ($NoSuchAlgorithmException& e) {
				$init($Alert);
				$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, $($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm())}), e)));
			} catch ($InvalidKeyException& e) {
				$init($Alert);
				$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, $($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm())}), e)));
			}
		}
		$var($bytes, signature, nullptr);
		try {
			updateSignature(signer, $nc(shc->clientHelloRandom)->randomBytes, $nc(shc->serverHelloRandom)->randomBytes);
			$assign(signature, $nc(signer)->sign());
		} catch ($SignatureException& ex) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Failed to sign dhe parameters: "_s, $($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm())}), ex)));
		}
		$set(this, paramsSignature, signature);
	}
}

void DHServerKeyExchange$DHServerKeyExchangeMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, handshakeContext));
	$set(this, p, $Record::getBytes16(m));
	$set(this, g, $Record::getBytes16(m));
	$set(this, y, $Record::getBytes16(m));
	try {
		$var($BigInteger, var$0, $new($BigInteger, 1, this->y));
		$var($BigInteger, var$1, $new($BigInteger, 1, this->p));
		$KeyUtil::validate(static_cast<$KeySpec*>($$new($DHPublicKeySpec, var$0, var$1, $$new($BigInteger, 1, this->p))));
	} catch ($InvalidKeyException& ike) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid DH ServerKeyExchange: invalid parameters"_s, ike)));
	}
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
		if ($nc(m)->hasRemaining()) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid DH ServerKeyExchange: unknown extra data"_s)));
		}
		$set(this, signatureScheme, nullptr);
		$set(this, paramsSignature, nullptr);
		this->useExplicitSigAlgorithm = false;
		return;
	}
	this->useExplicitSigAlgorithm = $nc(chc->negotiatedProtocol)->useTLS12PlusSpec();
	if (this->useExplicitSigAlgorithm) {
		int32_t ssid = $Record::getInt16(m);
		$set(this, signatureScheme, $SignatureScheme::valueOf(ssid));
		if (this->signatureScheme == nullptr) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Invalid signature algorithm ("_s, $$str(ssid), ") used in DH ServerKeyExchange handshake message"_s}))));
		}
		if (!$nc(chc->localSupportedSignAlgs)->contains(this->signatureScheme)) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Unsupported signature algorithm ("_s, this->signatureScheme->name$, ") used in DH ServerKeyExchange handshake message"_s}))));
		}
	} else {
		$set(this, signatureScheme, nullptr);
	}
	$set(this, paramsSignature, $Record::getBytes16(m));
	$var($Signature, signer, nullptr);
	if (this->useExplicitSigAlgorithm) {
		try {
			$assign(signer, this->signatureScheme->getVerifier($nc(x509Credentials)->popPublicKey));
		} catch ($NoSuchAlgorithmException& nsae) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, this->signatureScheme->name$}), nsae)));
		} catch ($InvalidKeyException& nsae) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, this->signatureScheme->name$}), nsae)));
		} catch ($InvalidAlgorithmParameterException& nsae) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, this->signatureScheme->name$}), nsae)));
		}
	} else {
		try {
			$assign(signer, getSignature($($nc($nc(x509Credentials)->popPublicKey)->getAlgorithm()), x509Credentials->popPublicKey));
		} catch ($NoSuchAlgorithmException& e) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, $($nc($nc(x509Credentials)->popPublicKey)->getAlgorithm())}), e)));
		} catch ($InvalidKeyException& e) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Unsupported signature algorithm: "_s, $($nc($nc(x509Credentials)->popPublicKey)->getAlgorithm())}), e)));
		}
	}
	try {
		updateSignature(signer, $nc(chc->clientHelloRandom)->randomBytes, $nc(chc->serverHelloRandom)->randomBytes);
		if (!$nc(signer)->verify(this->paramsSignature)) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid signature on DH ServerKeyExchange message"_s)));
		}
	} catch ($SignatureException& ex) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot verify DH ServerKeyExchange signature"_s, ex)));
	}
}

$SSLHandshake* DHServerKeyExchange$DHServerKeyExchangeMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::SERVER_KEY_EXCHANGE;
}

int32_t DHServerKeyExchange$DHServerKeyExchangeMessage::messageLength() {
	int32_t sigLen = 0;
	if (this->paramsSignature != nullptr) {
		sigLen = 2 + $nc(this->paramsSignature)->length;
		if (this->useExplicitSigAlgorithm) {
			sigLen += $SignatureScheme::sizeInRecord();
		}
	}
	return 6 + $nc(this->p)->length + $nc(this->g)->length + $nc(this->y)->length + sigLen;
}

void DHServerKeyExchange$DHServerKeyExchangeMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->putBytes16(this->p);
	hos->putBytes16(this->g);
	hos->putBytes16(this->y);
	if (this->paramsSignature != nullptr) {
		if (this->useExplicitSigAlgorithm) {
			hos->putInt16(this->signatureScheme->id);
		}
		hos->putBytes16(this->paramsSignature);
	}
}

$String* DHServerKeyExchange$DHServerKeyExchangeMessage::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->paramsSignature == nullptr) {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"DH ServerKeyExchange\": \'{\'\n  \"parameters\": \'{\'\n    \"dh_p\": \'{\'\n{0}\n    \'}\',\n    \"dh_g\": \'{\'\n{1}\n    \'}\',\n    \"dh_Ys\": \'{\'\n{2}\n    \'}\',\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
		$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->p)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->g)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->y)), "      "_s)))
		}));
		return messageFormat->format(messageFields);
	}
	if (this->useExplicitSigAlgorithm) {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"DH ServerKeyExchange\": \'{\'\n  \"parameters\": \'{\'\n    \"dh_p\": \'{\'\n{0}\n    \'}\',\n    \"dh_g\": \'{\'\n{1}\n    \'}\',\n    \"dh_Ys\": \'{\'\n{2}\n    \'}\',\n  \'}\',\n  \"digital signature\":  \'{\'\n    \"signature algorithm\": \"{3}\"\n    \"signature\": \'{\'\n{4}\n    \'}\',\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
		$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->p)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->g)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->y)), "      "_s))),
			$of(this->signatureScheme->name$),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->paramsSignature)), "      "_s)))
		}));
		return messageFormat->format(messageFields);
	} else {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"DH ServerKeyExchange\": \'{\'\n  \"parameters\": \'{\'\n    \"dh_p\": \'{\'\n{0}\n    \'}\',\n    \"dh_g\": \'{\'\n{1}\n    \'}\',\n    \"dh_Ys\": \'{\'\n{2}\n    \'}\',\n  \'}\',\n  \"signature\": \'{\'\n{3}\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
		$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->p)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->g)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->y)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->paramsSignature)), "    "_s)))
		}));
		return messageFormat->format(messageFields);
	}
}

$Signature* DHServerKeyExchange$DHServerKeyExchangeMessage::getSignature($String* keyAlgorithm, $Key* key) {
	$init(DHServerKeyExchange$DHServerKeyExchangeMessage);
	$useLocalCurrentObjectStackCache();
	$var($Signature, signer, nullptr);
	{
		$var($String, s17344$, keyAlgorithm);
		int32_t tmp17344$ = -1;
		switch ($nc(s17344$)->hashCode()) {
		case 0x00010992:
			{
				if (s17344$->equals("DSA"_s)) {
					tmp17344$ = 0;
				}
				break;
			}
		case 0x00013E20:
			{
				if (s17344$->equals("RSA"_s)) {
					tmp17344$ = 1;
				}
				break;
			}
		}
		switch (tmp17344$) {
		case 0:
			{
				$init($JsseJce);
				$assign(signer, $Signature::getInstance($JsseJce::SIGNATURE_DSA));
				break;
			}
		case 1:
			{
				$assign(signer, $RSASignature::getInstance());
				break;
			}
		default:
			{
				$throwNew($NoSuchAlgorithmException, $$str({"neither an RSA or a DSA key : "_s, keyAlgorithm}));
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

void DHServerKeyExchange$DHServerKeyExchangeMessage::updateSignature($Signature* sig, $bytes* clntNonce, $bytes* svrNonce) {
	int32_t tmp = 0;
	$nc(sig)->update(clntNonce);
	sig->update(svrNonce);
	sig->update((int8_t)($nc(this->p)->length >> 8));
	sig->update((int8_t)((int32_t)($nc(this->p)->length & (uint32_t)255)));
	sig->update(this->p);
	sig->update((int8_t)($nc(this->g)->length >> 8));
	sig->update((int8_t)((int32_t)($nc(this->g)->length & (uint32_t)255)));
	sig->update(this->g);
	sig->update((int8_t)($nc(this->y)->length >> 8));
	sig->update((int8_t)((int32_t)($nc(this->y)->length & (uint32_t)255)));
	sig->update(this->y);
}

DHServerKeyExchange$DHServerKeyExchangeMessage::DHServerKeyExchange$DHServerKeyExchangeMessage() {
}

$Class* DHServerKeyExchange$DHServerKeyExchangeMessage::load$($String* name, bool initialize) {
	$loadClass(DHServerKeyExchange$DHServerKeyExchangeMessage, name, initialize, &_DHServerKeyExchange$DHServerKeyExchangeMessage_ClassInfo_, allocate$DHServerKeyExchange$DHServerKeyExchangeMessage);
	return class$;
}

$Class* DHServerKeyExchange$DHServerKeyExchangeMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun