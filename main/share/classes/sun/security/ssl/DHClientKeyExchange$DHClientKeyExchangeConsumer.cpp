#include <sun/security/ssl/DHClientKeyExchange$DHClientKeyExchangeConsumer.h>

#include <java/io/IOException.h>
#include <java/lang/Enum.h>
#include <java/math/BigInteger.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/PublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/interfaces/DHPublicKey.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <javax/crypto/spec/DHPublicKeySpec.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/DHClientKeyExchange$DHClientKeyExchangeMessage.h>
#include <sun/security/ssl/DHClientKeyExchange.h>
#include <sun/security/ssl/DHKeyExchange$DHECredentials.h>
#include <sun/security/ssl/DHKeyExchange$DHEPossession.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef HANDSHAKE_FAILURE
#undef INTERNAL_ERROR
#undef KEY_AGREEMENT

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $SecretKey = ::javax::crypto::SecretKey;
using $DHPublicKey = ::javax::crypto::interfaces::DHPublicKey;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $DHPublicKeySpec = ::javax::crypto::spec::DHPublicKeySpec;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $Alert = ::sun::security::ssl::Alert;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $DHClientKeyExchange$DHClientKeyExchangeMessage = ::sun::security::ssl::DHClientKeyExchange$DHClientKeyExchangeMessage;
using $DHKeyExchange$DHECredentials = ::sun::security::ssl::DHKeyExchange$DHECredentials;
using $DHKeyExchange$DHEPossession = ::sun::security::ssl::DHKeyExchange$DHEPossession;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLKeyExchange = ::sun::security::ssl::SSLKeyExchange;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SSLTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _DHClientKeyExchange$DHClientKeyExchangeConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(DHClientKeyExchange$DHClientKeyExchangeConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(DHClientKeyExchange$DHClientKeyExchangeConsumer, consume, void, $ConnectionContext*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _DHClientKeyExchange$DHClientKeyExchangeConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.DHClientKeyExchange$DHClientKeyExchangeConsumer", "sun.security.ssl.DHClientKeyExchange", "DHClientKeyExchangeConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _DHClientKeyExchange$DHClientKeyExchangeConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.DHClientKeyExchange$DHClientKeyExchangeConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLConsumer",
	nullptr,
	_DHClientKeyExchange$DHClientKeyExchangeConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_DHClientKeyExchange$DHClientKeyExchangeConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.DHClientKeyExchange"
};

$Object* allocate$DHClientKeyExchange$DHClientKeyExchangeConsumer($Class* clazz) {
	return $of($alloc(DHClientKeyExchange$DHClientKeyExchangeConsumer));
}

void DHClientKeyExchange$DHClientKeyExchangeConsumer::init$() {
}

void DHClientKeyExchange$DHClientKeyExchangeConsumer::consume($ConnectionContext* context, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	$var($ServerHandshakeContext, shc, $cast($ServerHandshakeContext, context));
	$var($DHKeyExchange$DHEPossession, dhePossession, nullptr);
	{
		$var($Iterator, i$, $nc($nc(shc)->handshakePossessions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLPossession, possession, $cast($SSLPossession, i$->next()));
			{
				if ($instanceOf($DHKeyExchange$DHEPossession, possession)) {
					$assign(dhePossession, $cast($DHKeyExchange$DHEPossession, possession));
					break;
				}
			}
		}
	}
	if (dhePossession == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::HANDSHAKE_FAILURE, "No expected DHE possessions for client key exchange"_s)));
	}
	$var($SSLKeyExchange, ke, $SSLKeyExchange::valueOf($nc(shc->negotiatedCipherSuite)->keyExchange, shc->negotiatedProtocol));
	if (ke == nullptr) {
		$init($Alert);
		$throw($($nc(shc->conContext)->fatal($Alert::INTERNAL_ERROR, "Not supported key exchange type"_s)));
	}
	$var($DHClientKeyExchange$DHClientKeyExchangeMessage, ckem, $new($DHClientKeyExchange$DHClientKeyExchangeMessage, shc, message));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Consuming DH ClientKeyExchange handshake message"_s, $$new($ObjectArray, {$of(ckem)}));
	}
	try {
		$var($DHParameterSpec, params, $nc($nc(dhePossession)->publicKey)->getParams());
		$var($BigInteger, var$0, $new($BigInteger, 1, ckem->y));
		$var($BigInteger, var$1, $nc(params)->getP());
		$var($DHPublicKeySpec, spec, $new($DHPublicKeySpec, var$0, var$1, $(params->getG())));
		$var($KeyFactory, kf, $KeyFactory::getInstance("DiffieHellman"_s));
		$var($DHPublicKey, peerPublicKey, $cast($DHPublicKey, $nc(kf)->generatePublic(spec)));
		$init($CryptoPrimitive);
		if (!$nc(shc->algorithmConstraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), peerPublicKey)) {
			$throwNew($SSLHandshakeException, "DHPublicKey does not comply to algorithm constraints"_s);
		}
		$NamedGroup* namedGroup = $NamedGroup::valueOf(params);
		$nc(shc->handshakeCredentials)->add($$new($DHKeyExchange$DHECredentials, peerPublicKey, namedGroup));
	} catch ($GeneralSecurityException& e) {
		$throw(($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate DHPublicKey"_s)->initCause(e)))));
	} catch ($IOException& e) {
		$throw(($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate DHPublicKey"_s)->initCause(e)))));
	}
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

DHClientKeyExchange$DHClientKeyExchangeConsumer::DHClientKeyExchange$DHClientKeyExchangeConsumer() {
}

$Class* DHClientKeyExchange$DHClientKeyExchangeConsumer::load$($String* name, bool initialize) {
	$loadClass(DHClientKeyExchange$DHClientKeyExchangeConsumer, name, initialize, &_DHClientKeyExchange$DHClientKeyExchangeConsumer_ClassInfo_, allocate$DHClientKeyExchange$DHClientKeyExchangeConsumer);
	return class$;
}

$Class* DHClientKeyExchange$DHClientKeyExchangeConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun