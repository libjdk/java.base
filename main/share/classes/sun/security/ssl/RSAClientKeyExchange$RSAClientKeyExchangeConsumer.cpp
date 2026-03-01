#include <sun/security/ssl/RSAClientKeyExchange$RSAClientKeyExchangeConsumer.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/PrivateKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RSAClientKeyExchange$RSAClientKeyExchangeMessage.h>
#include <sun/security/ssl/RSAClientKeyExchange.h>
#include <sun/security/ssl/RSAKeyExchange$EphemeralRSAPossession.h>
#include <sun/security/ssl/RSAKeyExchange$RSAPremasterSecret.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <jcpp.h>

#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $PrivateKey = ::java::security::PrivateKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $SecretKey = ::javax::crypto::SecretKey;
using $Alert = ::sun::security::ssl::Alert;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $RSAClientKeyExchange$RSAClientKeyExchangeMessage = ::sun::security::ssl::RSAClientKeyExchange$RSAClientKeyExchangeMessage;
using $RSAKeyExchange$EphemeralRSAPossession = ::sun::security::ssl::RSAKeyExchange$EphemeralRSAPossession;
using $RSAKeyExchange$RSAPremasterSecret = ::sun::security::ssl::RSAKeyExchange$RSAPremasterSecret;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLKeyExchange = ::sun::security::ssl::SSLKeyExchange;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _RSAClientKeyExchange$RSAClientKeyExchangeConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(RSAClientKeyExchange$RSAClientKeyExchangeConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(RSAClientKeyExchange$RSAClientKeyExchangeConsumer, consume, void, $ConnectionContext*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _RSAClientKeyExchange$RSAClientKeyExchangeConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.RSAClientKeyExchange$RSAClientKeyExchangeConsumer", "sun.security.ssl.RSAClientKeyExchange", "RSAClientKeyExchangeConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSAClientKeyExchange$RSAClientKeyExchangeConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.RSAClientKeyExchange$RSAClientKeyExchangeConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLConsumer",
	nullptr,
	_RSAClientKeyExchange$RSAClientKeyExchangeConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_RSAClientKeyExchange$RSAClientKeyExchangeConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.RSAClientKeyExchange"
};

$Object* allocate$RSAClientKeyExchange$RSAClientKeyExchangeConsumer($Class* clazz) {
	return $of($alloc(RSAClientKeyExchange$RSAClientKeyExchangeConsumer));
}

void RSAClientKeyExchange$RSAClientKeyExchangeConsumer::init$() {
}

void RSAClientKeyExchange$RSAClientKeyExchangeConsumer::consume($ConnectionContext* context, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$var($RSAKeyExchange$EphemeralRSAPossession, rsaPossession, nullptr);
	$var($X509Authentication$X509Possession, x509Possession, nullptr);
	{
		$var($Iterator, i$, $nc($nc(shc)->handshakePossessions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLPossession, possession, $cast($SSLPossession, i$->next()));
			{
				if ($instanceOf($RSAKeyExchange$EphemeralRSAPossession, possession)) {
					$assign(rsaPossession, $cast($RSAKeyExchange$EphemeralRSAPossession, possession));
					break;
				} else if ($instanceOf($X509Authentication$X509Possession, possession)) {
					$assign(x509Possession, $cast($X509Authentication$X509Possession, possession));
					if (rsaPossession != nullptr) {
						break;
					}
				}
			}
		}
	}
	if (rsaPossession == nullptr && x509Possession == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "No RSA possessions negotiated for client key exchange"_s)));
	}
	$var($PrivateKey, privateKey, (rsaPossession != nullptr) ? $nc(rsaPossession)->popPrivateKey : $nc(x509Possession)->popPrivateKey);
	if (!$nc($($nc(privateKey)->getAlgorithm()))->equals("RSA"_s)) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Not RSA private key for client key exchange"_s)));
	}
	$var($RSAClientKeyExchange$RSAClientKeyExchangeMessage, ckem, $new($RSAClientKeyExchange$RSAClientKeyExchangeMessage, shc, message));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Consuming RSA ClientKeyExchange handshake message"_s, $$new($ObjectArray, {$of(ckem)}));
	}
	$var($RSAKeyExchange$RSAPremasterSecret, premaster, nullptr);
	try {
		$assign(premaster, $RSAKeyExchange$RSAPremasterSecret::decode(shc, privateKey, ckem->encrypted));
		$nc(shc->handshakeCredentials)->add(premaster);
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Cannot decode RSA premaster secret"_s, gse)));
	}
	$var($SSLKeyExchange, ke, $SSLKeyExchange::valueOf($nc(shc->negotiatedCipherSuite)->keyExchange, shc->negotiatedProtocol));
	if (ke == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, "Not supported key exchange type"_s)));
	} else {
		$var($SSLKeyDerivation, masterKD, $nc(ke)->createKeyDerivation(shc));
		$var($SecretKey, masterSecret, $nc(masterKD)->deriveKey("MasterSecret"_s, nullptr));
		$nc(shc->handshakeSession)->setMasterSecret(masterSecret);
		$SSLTrafficKeyDerivation* kd = $SSLTrafficKeyDerivation::valueOf(shc->negotiatedProtocol);
		if (kd == nullptr) {
			$init($Alert);
			$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, shc->negotiatedProtocol}))));
		} else {
			$set(shc, handshakeKeyDerivation, $nc(kd)->createKeyDerivation(shc, masterSecret));
		}
	}
}

RSAClientKeyExchange$RSAClientKeyExchangeConsumer::RSAClientKeyExchange$RSAClientKeyExchangeConsumer() {
}

$Class* RSAClientKeyExchange$RSAClientKeyExchangeConsumer::load$($String* name, bool initialize) {
	$loadClass(RSAClientKeyExchange$RSAClientKeyExchangeConsumer, name, initialize, &_RSAClientKeyExchange$RSAClientKeyExchangeConsumer_ClassInfo_, allocate$RSAClientKeyExchange$RSAClientKeyExchangeConsumer);
	return class$;
}

$Class* RSAClientKeyExchange$RSAClientKeyExchangeConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun