#include <sun/security/ssl/RSAClientKeyExchange$RSAClientKeyExchangeProducer.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/PublicKey.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/RSAClientKeyExchange$RSAClientKeyExchangeMessage.h>
#include <sun/security/ssl/RSAClientKeyExchange.h>
#include <sun/security/ssl/RSAKeyExchange$EphemeralRSACredentials.h>
#include <sun/security/ssl/RSAKeyExchange$RSAPremasterSecret.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/X509Authentication$X509Credentials.h>
#include <jcpp.h>

#undef ILLEGAL_PARAMETER
#undef INTERNAL_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $PublicKey = ::java::security::PublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $SecretKey = ::javax::crypto::SecretKey;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $RSAClientKeyExchange$RSAClientKeyExchangeMessage = ::sun::security::ssl::RSAClientKeyExchange$RSAClientKeyExchangeMessage;
using $RSAKeyExchange$EphemeralRSACredentials = ::sun::security::ssl::RSAKeyExchange$EphemeralRSACredentials;
using $RSAKeyExchange$RSAPremasterSecret = ::sun::security::ssl::RSAKeyExchange$RSAPremasterSecret;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLKeyExchange = ::sun::security::ssl::SSLKeyExchange;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $X509Authentication$X509Credentials = ::sun::security::ssl::X509Authentication$X509Credentials;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _RSAClientKeyExchange$RSAClientKeyExchangeProducer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(RSAClientKeyExchange$RSAClientKeyExchangeProducer, init$, void)},
	{"produce", "(Lsun/security/ssl/ConnectionContext;Lsun/security/ssl/SSLHandshake$HandshakeMessage;)[B", nullptr, $PUBLIC, $virtualMethod(RSAClientKeyExchange$RSAClientKeyExchangeProducer, produce, $bytes*, $ConnectionContext*, $SSLHandshake$HandshakeMessage*), "java.io.IOException"},
	{}
};

$InnerClassInfo _RSAClientKeyExchange$RSAClientKeyExchangeProducer_InnerClassesInfo_[] = {
	{"sun.security.ssl.RSAClientKeyExchange$RSAClientKeyExchangeProducer", "sun.security.ssl.RSAClientKeyExchange", "RSAClientKeyExchangeProducer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSAClientKeyExchange$RSAClientKeyExchangeProducer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.RSAClientKeyExchange$RSAClientKeyExchangeProducer",
	"java.lang.Object",
	"sun.security.ssl.HandshakeProducer",
	nullptr,
	_RSAClientKeyExchange$RSAClientKeyExchangeProducer_MethodInfo_,
	nullptr,
	nullptr,
	_RSAClientKeyExchange$RSAClientKeyExchangeProducer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.RSAClientKeyExchange"
};

$Object* allocate$RSAClientKeyExchange$RSAClientKeyExchangeProducer($Class* clazz) {
	return $of($alloc(RSAClientKeyExchange$RSAClientKeyExchangeProducer));
}

void RSAClientKeyExchange$RSAClientKeyExchangeProducer::init$() {
}

$bytes* RSAClientKeyExchange$RSAClientKeyExchangeProducer::produce($ConnectionContext* context, $SSLHandshake$HandshakeMessage* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($RSAKeyExchange$EphemeralRSACredentials, rsaCredentials, nullptr);
	$var($X509Authentication$X509Credentials, x509Credentials, nullptr);
	{
		$var($Iterator, i$, $nc($nc(chc)->handshakeCredentials)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLCredentials, credential, $cast($SSLCredentials, i$->next()));
			{
				if ($instanceOf($RSAKeyExchange$EphemeralRSACredentials, credential)) {
					$assign(rsaCredentials, $cast($RSAKeyExchange$EphemeralRSACredentials, credential));
					if (x509Credentials != nullptr) {
						break;
					}
				} else if ($instanceOf($X509Authentication$X509Credentials, credential)) {
					$assign(x509Credentials, $cast($X509Authentication$X509Credentials, credential));
					if (rsaCredentials != nullptr) {
						break;
					}
				}
			}
		}
	}
	if (rsaCredentials == nullptr && x509Credentials == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "No RSA credentials negotiated for client key exchange"_s)));
	}
	$var($PublicKey, publicKey, (rsaCredentials != nullptr) ? static_cast<$PublicKey*>($nc(rsaCredentials)->popPublicKey) : $nc(x509Credentials)->popPublicKey);
	if (!$nc($($nc(publicKey)->getAlgorithm()))->equals("RSA"_s)) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Not RSA public key for client key exchange"_s)));
	}
	$var($RSAKeyExchange$RSAPremasterSecret, premaster, nullptr);
	$var($RSAClientKeyExchange$RSAClientKeyExchangeMessage, ckem, nullptr);
	try {
		$assign(premaster, $RSAKeyExchange$RSAPremasterSecret::createPremasterSecret(chc));
		$nc(chc->handshakePossessions)->add(premaster);
		$assign(ckem, $new($RSAClientKeyExchange$RSAClientKeyExchangeMessage, chc, premaster, publicKey));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Cannot generate RSA premaster secret"_s, gse)));
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Produced RSA ClientKeyExchange handshake message"_s, $$new($ObjectArray, {$of(ckem)}));
	}
	$nc(ckem)->write(chc->handshakeOutput);
	$nc(chc->handshakeOutput)->flush();
	$var($SSLKeyExchange, ke, $SSLKeyExchange::valueOf($nc(chc->negotiatedCipherSuite)->keyExchange, chc->negotiatedProtocol));
	if (ke == nullptr) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, "Not supported key exchange type"_s)));
	} else {
		$var($SSLKeyDerivation, masterKD, $nc(ke)->createKeyDerivation(chc));
		$var($SecretKey, masterSecret, $nc(masterKD)->deriveKey("MasterSecret"_s, nullptr));
		$nc(chc->handshakeSession)->setMasterSecret(masterSecret);
		$SSLTrafficKeyDerivation* kd = $SSLTrafficKeyDerivation::valueOf(chc->negotiatedProtocol);
		if (kd == nullptr) {
			$init($Alert);
			$throw($($nc(chc->conContext)->fatal($Alert::INTERNAL_ERROR, $$str({"Not supported key derivation: "_s, chc->negotiatedProtocol}))));
		} else {
			$set(chc, handshakeKeyDerivation, $nc(kd)->createKeyDerivation(chc, masterSecret));
		}
	}
	return nullptr;
}

RSAClientKeyExchange$RSAClientKeyExchangeProducer::RSAClientKeyExchange$RSAClientKeyExchangeProducer() {
}

$Class* RSAClientKeyExchange$RSAClientKeyExchangeProducer::load$($String* name, bool initialize) {
	$loadClass(RSAClientKeyExchange$RSAClientKeyExchangeProducer, name, initialize, &_RSAClientKeyExchange$RSAClientKeyExchangeProducer_ClassInfo_, allocate$RSAClientKeyExchange$RSAClientKeyExchangeProducer);
	return class$;
}

$Class* RSAClientKeyExchange$RSAClientKeyExchangeProducer::class$ = nullptr;

		} // ssl
	} // security
} // sun