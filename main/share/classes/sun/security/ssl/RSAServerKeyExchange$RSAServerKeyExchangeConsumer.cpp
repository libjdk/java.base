#include <sun/security/ssl/RSAServerKeyExchange$RSAServerKeyExchangeConsumer.h>

#include <java/lang/Enum.h>
#include <java/math/BigInteger.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/PublicKey.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/RSAPublicKeySpec.h>
#include <java/util/EnumSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ClientHandshakeContext.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/RSAKeyExchange$EphemeralRSACredentials.h>
#include <sun/security/ssl/RSAServerKeyExchange$RSAServerKeyExchangeMessage.h>
#include <sun/security/ssl/RSAServerKeyExchange.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef INSUFFICIENT_SECURITY
#undef KEY_AGREEMENT

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
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $KeySpec = ::java::security::spec::KeySpec;
using $RSAPublicKeySpec = ::java::security::spec::RSAPublicKeySpec;
using $EnumSet = ::java::util::EnumSet;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Alert = ::sun::security::ssl::Alert;
using $ClientHandshakeContext = ::sun::security::ssl::ClientHandshakeContext;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $RSAKeyExchange$EphemeralRSACredentials = ::sun::security::ssl::RSAKeyExchange$EphemeralRSACredentials;
using $RSAServerKeyExchange$RSAServerKeyExchangeMessage = ::sun::security::ssl::RSAServerKeyExchange$RSAServerKeyExchangeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _RSAServerKeyExchange$RSAServerKeyExchangeConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(RSAServerKeyExchange$RSAServerKeyExchangeConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(RSAServerKeyExchange$RSAServerKeyExchangeConsumer, consume, void, $ConnectionContext*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _RSAServerKeyExchange$RSAServerKeyExchangeConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.RSAServerKeyExchange$RSAServerKeyExchangeConsumer", "sun.security.ssl.RSAServerKeyExchange", "RSAServerKeyExchangeConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSAServerKeyExchange$RSAServerKeyExchangeConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.RSAServerKeyExchange$RSAServerKeyExchangeConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLConsumer",
	nullptr,
	_RSAServerKeyExchange$RSAServerKeyExchangeConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_RSAServerKeyExchange$RSAServerKeyExchangeConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.RSAServerKeyExchange"
};

$Object* allocate$RSAServerKeyExchange$RSAServerKeyExchangeConsumer($Class* clazz) {
	return $of($alloc(RSAServerKeyExchange$RSAServerKeyExchangeConsumer));
}

void RSAServerKeyExchange$RSAServerKeyExchangeConsumer::init$() {
}

void RSAServerKeyExchange$RSAServerKeyExchangeConsumer::consume($ConnectionContext* context, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	$var($ClientHandshakeContext, chc, $cast($ClientHandshakeContext, context));
	$var($RSAServerKeyExchange$RSAServerKeyExchangeMessage, skem, $new($RSAServerKeyExchange$RSAServerKeyExchangeMessage, chc, message));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Consuming RSA ServerKeyExchange handshake message"_s, $$new($ObjectArray, {$of(skem)}));
	}
	$var($RSAPublicKey, publicKey, nullptr);
	try {
		$var($KeyFactory, kf, $KeyFactory::getInstance("RSA"_s));
		$var($BigInteger, var$0, $new($BigInteger, 1, skem->modulus));
		$var($RSAPublicKeySpec, spec, $new($RSAPublicKeySpec, var$0, $$new($BigInteger, 1, skem->exponent)));
		$assign(publicKey, $cast($RSAPublicKey, $nc(kf)->generatePublic(spec)));
	} catch ($GeneralSecurityException& gse) {
		$init($Alert);
		$throw($($nc($nc(chc)->conContext)->fatal($Alert::INSUFFICIENT_SECURITY, "Could not generate RSAPublicKey"_s, gse)));
	}
	$init($CryptoPrimitive);
	if (!$nc($nc(chc)->algorithmConstraints)->permits($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT)), publicKey)) {
		$init($Alert);
		$throw($($nc(chc->conContext)->fatal($Alert::INSUFFICIENT_SECURITY, "RSA ServerKeyExchange does not comply to algorithm constraints"_s)));
	}
	$nc($nc(chc)->handshakeCredentials)->add($$new($RSAKeyExchange$EphemeralRSACredentials, publicKey));
}

RSAServerKeyExchange$RSAServerKeyExchangeConsumer::RSAServerKeyExchange$RSAServerKeyExchangeConsumer() {
}

$Class* RSAServerKeyExchange$RSAServerKeyExchangeConsumer::load$($String* name, bool initialize) {
	$loadClass(RSAServerKeyExchange$RSAServerKeyExchangeConsumer, name, initialize, &_RSAServerKeyExchange$RSAServerKeyExchangeConsumer_ClassInfo_, allocate$RSAServerKeyExchange$RSAServerKeyExchangeConsumer);
	return class$;
}

$Class* RSAServerKeyExchange$RSAServerKeyExchangeConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun