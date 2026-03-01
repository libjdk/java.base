#include <sun/security/ssl/ECDHServerKeyExchange$ECDHServerKeyExchangeMessage.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
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
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ECDHServerKeyExchange.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/JsseJce.h>
#include <sun/security/ssl/NamedGroup$ExceptionSupplier.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/NamedGroupPossession.h>
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
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef CURVE_NAMED_CURVE
#undef ENGLISH
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef INSUFFICIENT_SECURITY
#undef INTERNAL_ERROR
#undef SERVER_KEY_EXCHANGE
#undef SIGNATURE_ECDSA
#undef SIGNATURE_EDDSA
#undef UNEXPECTED_MESSAGE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
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
using $Map$Entry = ::java::util::Map$Entry;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $JsseJce = ::sun::security::ssl::JsseJce;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$ExceptionSupplier = ::sun::security::ssl::NamedGroup$ExceptionSupplier;
using $NamedGroupPossession = ::sun::security::ssl::NamedGroupPossession;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $RSASignature = ::sun::security::ssl::RSASignature;
using $Record = ::sun::security::ssl::Record;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $SignatureScheme = ::sun::security::ssl::SignatureScheme;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

class ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0 : public $NamedGroup$ExceptionSupplier {
	$class(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, $NO_CLASS_INIT, $NamedGroup$ExceptionSupplier)
public:
	void init$(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage* inst, $ClientHandshakeContext* chc) {
		$set(this, inst$, inst);
		$set(this, chc, chc);
	}
	virtual void apply($String* s) override {
		$nc(inst$)->lambda$new$0(chc, s);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0>());
	}
	ECDHServerKeyExchange$ECDHServerKeyExchangeMessage* inst$ = nullptr;
	$ClientHandshakeContext* chc = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, inst$)},
	{"chc", "Lsun/security/ssl/ClientHandshakeContext;", nullptr, $PUBLIC, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, chc)},
	{}
};
$MethodInfo ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Lsun/security/ssl/ECDHServerKeyExchange$ECDHServerKeyExchangeMessage;Lsun/security/ssl/ClientHandshakeContext;)V", nullptr, $PUBLIC, $method(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, init$, void, ECDHServerKeyExchange$ECDHServerKeyExchangeMessage*, $ClientHandshakeContext*)},
	{"apply", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, apply, void, $String*)},
	{}
};
$ClassInfo ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.ssl.ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0",
	"java.lang.Object",
	"sun.security.ssl.NamedGroup$ExceptionSupplier",
	fieldInfos,
	methodInfos
};
$Class* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_FieldInfo_[] = {
	{"CURVE_NAMED_CURVE", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, CURVE_NAMED_CURVE)},
	{"namedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, $PRIVATE | $FINAL, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, namedGroup)},
	{"publicPoint", "[B", nullptr, $PRIVATE | $FINAL, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, publicPoint)},
	{"paramsSignature", "[B", nullptr, $PRIVATE | $FINAL, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, paramsSignature)},
	{"useExplicitSigAlgorithm", "Z", nullptr, $PRIVATE | $FINAL, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, useExplicitSigAlgorithm)},
	{"signatureScheme", "Lsun/security/ssl/SignatureScheme;", nullptr, $PRIVATE | $FINAL, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, signatureScheme)},
	{"sslCredentials", "Lsun/security/ssl/SSLCredentials;", nullptr, $PRIVATE, $field(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, sslCredentials)},
	{}
};

$MethodInfo _ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;)V", nullptr, 0, $method(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, init$, void, $HandshakeContext*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"getSignature", "(Ljava/lang/String;Ljava/security/Key;)Ljava/security/Signature;", nullptr, $PRIVATE | $STATIC, $staticMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, getSignature, $Signature*, $String*, $Key*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, handshakeType, $SSLHandshake*)},
	{"lambda$new$0", "(Lsun/security/ssl/ClientHandshakeContext;Ljava/lang/String;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, lambda$new$0, void, $ClientHandshakeContext*, $String*), "javax.net.ssl.SSLException"},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, toString, $String*)},
	{"updateSignature", "(Ljava/security/Signature;[B[BI[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, updateSignature, void, $Signature*, $bytes*, $bytes*, int32_t, $bytes*), "java.security.SignatureException"},
	{}
};

$InnerClassInfo _ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.ECDHServerKeyExchange$ECDHServerKeyExchangeMessage", "sun.security.ssl.ECDHServerKeyExchange", "ECDHServerKeyExchangeMessage", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ECDHServerKeyExchange$ECDHServerKeyExchangeMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_FieldInfo_,
	_ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_MethodInfo_,
	nullptr,
	nullptr,
	_ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ECDHServerKeyExchange"
};

$Object* allocate$ECDHServerKeyExchange$ECDHServerKeyExchangeMessage($Class* clazz) {
	return $of($alloc(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage));
}

void ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::init$($HandshakeContext* handshakeContext) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, handshakeContext));
	$var($NamedGroupPossession, namedGroupPossession, nullptr);
	$var($X509Authentication$X509Possession, x509Possession, nullptr);
	{
		$var($Iterator, i$, $nc($nc(shc)->handshakePossessions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLPossession, possession, $cast($SSLPossession, i$->next()));
			{
				if ($instanceOf($NamedGroupPossession, possession)) {
					$assign(namedGroupPossession, $cast($NamedGroupPossession, possession));
					if (x509Possession != nullptr) {
						break;
					}
				} else if ($instanceOf($X509Authentication$X509Possession, possession)) {
					$assign(x509Possession, $cast($X509Authentication$X509Possession, possession));
					if (namedGroupPossession != nullptr) {
						break;
					}
				}
			}
		}
	}
	if (namedGroupPossession == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "No ECDHE credentials negotiated for server key exchange"_s)));
	}
	$set(this, namedGroup, $nc(namedGroupPossession)->getNamedGroup());
	if ((this->namedGroup == nullptr) || (!this->namedGroup->isAvailable$)) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Missing or improper named group: "_s, this->namedGroup}))));
	}
	$set(this, publicPoint, this->namedGroup->encodePossessionPublicKey(namedGroupPossession));
	if (this->publicPoint == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Missing public point for named group: "_s, this->namedGroup}))));
	}
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
			updateSignature(signer, $nc(shc->clientHelloRandom)->randomBytes, $nc(shc->serverHelloRandom)->randomBytes, this->namedGroup->id, this->publicPoint);
			$assign(signature, $nc(signer)->sign());
		} catch ($SignatureException& ex) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Failed to sign ecdhe parameters: "_s, $($nc($nc(x509Possession)->popPrivateKey)->getAlgorithm())}), ex)));
		}
		$set(this, paramsSignature, signature);
	}
}

void ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::init$($HandshakeContext* handshakeContext, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(handshakeContext);
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, handshakeContext));
	int8_t curveType = (int8_t)$Record::getInt8(m);
	if (curveType != ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::CURVE_NAMED_CURVE) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Unsupported ECCurveType: "_s, $$str(curveType)}))));
	}
	int32_t namedGroupId = $Record::getInt16(m);
	$set(this, namedGroup, $NamedGroup::valueOf(namedGroupId));
	if (this->namedGroup == nullptr) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Unknown named group ID: "_s, $$str(namedGroupId)}))));
	}
	if (!$SupportedGroupsExtension$SupportedGroups::isSupported(this->namedGroup)) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Unsupported named group: "_s, this->namedGroup}))));
	}
	$set(this, publicPoint, $Record::getBytes8(m));
	if ($nc(this->publicPoint)->length == 0) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Insufficient Point data: "_s, this->namedGroup}))));
	}
	try {
		$set(this, sslCredentials, this->namedGroup->decodeCredentials(this->publicPoint, $nc(handshakeContext)->algorithmConstraints, static_cast<$NamedGroup$ExceptionSupplier*>($$new(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0, this, chc))));
	} catch ($GeneralSecurityException& ex) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, $$str({"Cannot decode named group: "_s, $($NamedGroup::nameOf(namedGroupId))}))));
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
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Invalid signature algorithm ("_s, $$str(ssid), ") used in ECDH ServerKeyExchange handshake message"_s}))));
		}
		if (!$nc(chc->localSupportedSignAlgs)->contains(this->signatureScheme)) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, $$str({"Unsupported signature algorithm ("_s, this->signatureScheme->name$, ") used in ECDH ServerKeyExchange handshake message"_s}))));
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
		updateSignature(signer, $nc(chc->clientHelloRandom)->randomBytes, $nc(chc->serverHelloRandom)->randomBytes, this->namedGroup->id, this->publicPoint);
		if (!$nc(signer)->verify(this->paramsSignature)) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Invalid ECDH ServerKeyExchange signature"_s)));
		}
	} catch ($SignatureException& ex) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "Cannot verify ECDH ServerKeyExchange signature"_s, ex)));
	}
}

$SSLHandshake* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::SERVER_KEY_EXCHANGE;
}

int32_t ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::messageLength() {
	int32_t sigLen = 0;
	if (this->paramsSignature != nullptr) {
		sigLen = 2 + $nc(this->paramsSignature)->length;
		if (this->useExplicitSigAlgorithm) {
			sigLen += $SignatureScheme::sizeInRecord();
		}
	}
	return 4 + $nc(this->publicPoint)->length + sigLen;
}

void ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->putInt8(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::CURVE_NAMED_CURVE);
	hos->putInt16(this->namedGroup->id);
	hos->putBytes8(this->publicPoint);
	if (this->paramsSignature != nullptr) {
		if (this->useExplicitSigAlgorithm) {
			hos->putInt16(this->signatureScheme->id);
		}
		hos->putBytes16(this->paramsSignature);
	}
}

$String* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->useExplicitSigAlgorithm) {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"ECDH ServerKeyExchange\": \'{\'\n  \"parameters\": \'{\'\n    \"named group\": \"{0}\"\n    \"ecdh public\": \'{\'\n{1}\n    \'}\',\n  \'}\',\n  \"digital signature\":  \'{\'\n    \"signature algorithm\": \"{2}\"\n    \"signature\": \'{\'\n{3}\n    \'}\',\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
		$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$of(this->namedGroup->name$),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->publicPoint)), "      "_s))),
			$of(this->signatureScheme->name$),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->paramsSignature)), "      "_s)))
		}));
		return messageFormat->format(messageFields);
	} else if (this->paramsSignature != nullptr) {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"ECDH ServerKeyExchange\": \'{\'\n  \"parameters\":  \'{\'\n    \"named group\": \"{0}\"\n    \"ecdh public\": \'{\'\n{1}\n    \'}\',\n  \'}\',\n  \"signature\": \'{\'\n{2}\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
		$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$of(this->namedGroup->name$),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->publicPoint)), "      "_s))),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->paramsSignature)), "    "_s)))
		}));
		return messageFormat->format(messageFields);
	} else {
		$init($Locale);
		$var($MessageFormat, messageFormat, $new($MessageFormat, "\"ECDH ServerKeyExchange\": \'{\'\n  \"parameters\":  \'{\'\n    \"named group\": \"{0}\"\n    \"ecdh public\": \'{\'\n{1}\n    \'}\',\n  \'}\'\n\'}\'"_s, $Locale::ENGLISH));
		$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
		$var($ObjectArray, messageFields, $new($ObjectArray, {
			$of(this->namedGroup->name$),
			$($of($Utilities::indent($(hexEncoder->encodeBuffer(this->publicPoint)), "      "_s)))
		}));
		return messageFormat->format(messageFields);
	}
}

$Signature* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::getSignature($String* keyAlgorithm, $Key* key) {
	$init(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage);
	$useLocalCurrentObjectStackCache();
	$var($Signature, signer, nullptr);
	{
		$var($String, s17713$, keyAlgorithm);
		int32_t tmp17713$ = -1;
		switch ($nc(s17713$)->hashCode()) {
		case 2206:
			{
				if (s17713$->equals("EC"_s)) {
					tmp17713$ = 0;
				}
				break;
			}
		case 0x03FAD473:
			{
				if (s17713$->equals("EdDSA"_s)) {
					tmp17713$ = 1;
				}
				break;
			}
		case 0x00013E20:
			{
				if (s17713$->equals("RSA"_s)) {
					tmp17713$ = 2;
				}
				break;
			}
		}
		switch (tmp17713$) {
		case 0:
			{
				$init($JsseJce);
				$assign(signer, $Signature::getInstance($JsseJce::SIGNATURE_ECDSA));
				break;
			}
		case 1:
			{
				$init($JsseJce);
				$assign(signer, $Signature::getInstance($JsseJce::SIGNATURE_EDDSA));
				break;
			}
		case 2:
			{
				$assign(signer, $RSASignature::getInstance());
				break;
			}
		default:
			{
				$throwNew($NoSuchAlgorithmException, $$str({"neither an RSA or a EC key : "_s, keyAlgorithm}));
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

void ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::updateSignature($Signature* sig, $bytes* clntNonce, $bytes* svrNonce, int32_t namedGroupId, $bytes* publicPoint) {
	$init(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage);
	$nc(sig)->update(clntNonce);
	sig->update(svrNonce);
	sig->update(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::CURVE_NAMED_CURVE);
	sig->update((int8_t)((int32_t)((namedGroupId >> 8) & (uint32_t)255)));
	sig->update((int8_t)((int32_t)(namedGroupId & (uint32_t)255)));
	sig->update((int8_t)$nc(publicPoint)->length);
	sig->update(publicPoint);
}

void ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::lambda$new$0($ClientHandshakeContext* chc, $String* s) {
	$init($Alert);
	$nc($nc(chc)->conContext)->fatal($Alert::INSUFFICIENT_SECURITY, $$str({"ServerKeyExchange "_s, this->namedGroup, ": "_s, (s)}));
}

ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::ECDHServerKeyExchange$ECDHServerKeyExchangeMessage() {
}

$Class* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::classInfo$.name)) {
			return ECDHServerKeyExchange$ECDHServerKeyExchangeMessage$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(ECDHServerKeyExchange$ECDHServerKeyExchangeMessage, name, initialize, &_ECDHServerKeyExchange$ECDHServerKeyExchangeMessage_ClassInfo_, allocate$ECDHServerKeyExchange$ECDHServerKeyExchangeMessage);
	return class$;
}

$Class* ECDHServerKeyExchange$ECDHServerKeyExchangeMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun