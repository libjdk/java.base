#include <sun/security/ssl/ServerHello.h>

#include <java/security/GeneralSecurityException.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/HKDF.h>
#include <sun/security/ssl/HandshakeConsumer.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeProducer.h>
#include <sun/security/ssl/SSLConsumer.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSecretDerivation.h>
#include <sun/security/ssl/ServerHello$ServerHelloConsumer.h>
#include <sun/security/ssl/ServerHello$T12ServerHelloConsumer.h>
#include <sun/security/ssl/ServerHello$T12ServerHelloProducer.h>
#include <sun/security/ssl/ServerHello$T13HelloRetryRequestConsumer.h>
#include <sun/security/ssl/ServerHello$T13HelloRetryRequestProducer.h>
#include <sun/security/ssl/ServerHello$T13HelloRetryRequestReproducer.h>
#include <sun/security/ssl/ServerHello$T13ServerHelloConsumer.h>
#include <sun/security/ssl/ServerHello$T13ServerHelloProducer.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $SecretKey = ::javax::crypto::SecretKey;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $HKDF = ::sun::security::ssl::HKDF;
using $HandshakeConsumer = ::sun::security::ssl::HandshakeConsumer;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeProducer = ::sun::security::ssl::HandshakeProducer;
using $SSLConsumer = ::sun::security::ssl::SSLConsumer;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSecretDerivation = ::sun::security::ssl::SSLSecretDerivation;
using $ServerHello$ServerHelloConsumer = ::sun::security::ssl::ServerHello$ServerHelloConsumer;
using $ServerHello$T12ServerHelloConsumer = ::sun::security::ssl::ServerHello$T12ServerHelloConsumer;
using $ServerHello$T12ServerHelloProducer = ::sun::security::ssl::ServerHello$T12ServerHelloProducer;
using $ServerHello$T13HelloRetryRequestConsumer = ::sun::security::ssl::ServerHello$T13HelloRetryRequestConsumer;
using $ServerHello$T13HelloRetryRequestProducer = ::sun::security::ssl::ServerHello$T13HelloRetryRequestProducer;
using $ServerHello$T13HelloRetryRequestReproducer = ::sun::security::ssl::ServerHello$T13HelloRetryRequestReproducer;
using $ServerHello$T13ServerHelloConsumer = ::sun::security::ssl::ServerHello$T13ServerHelloConsumer;
using $ServerHello$T13ServerHelloProducer = ::sun::security::ssl::ServerHello$T13ServerHelloProducer;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _ServerHello_FieldInfo_[] = {
	{"handshakeConsumer", "Lsun/security/ssl/SSLConsumer;", nullptr, $STATIC | $FINAL, $staticField(ServerHello, handshakeConsumer)},
	{"t12HandshakeProducer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(ServerHello, t12HandshakeProducer)},
	{"t13HandshakeProducer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(ServerHello, t13HandshakeProducer)},
	{"hrrHandshakeProducer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(ServerHello, hrrHandshakeProducer)},
	{"hrrReproducer", "Lsun/security/ssl/HandshakeProducer;", nullptr, $STATIC | $FINAL, $staticField(ServerHello, hrrReproducer)},
	{"t12HandshakeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ServerHello, t12HandshakeConsumer)},
	{"t13HandshakeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ServerHello, t13HandshakeConsumer)},
	{"d12HandshakeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ServerHello, d12HandshakeConsumer)},
	{"d13HandshakeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ServerHello, d13HandshakeConsumer)},
	{"t13HrrHandshakeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ServerHello, t13HrrHandshakeConsumer)},
	{"d13HrrHandshakeConsumer", "Lsun/security/ssl/HandshakeConsumer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ServerHello, d13HrrHandshakeConsumer)},
	{}
};

$MethodInfo _ServerHello_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ServerHello, init$, void)},
	{"setUpPskKD", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ServerHello, setUpPskKD, void, $HandshakeContext*, $SecretKey*), "javax.net.ssl.SSLHandshakeException"},
	{}
};

$InnerClassInfo _ServerHello_InnerClassesInfo_[] = {
	{"sun.security.ssl.ServerHello$T13HelloRetryRequestConsumer", "sun.security.ssl.ServerHello", "T13HelloRetryRequestConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T13ServerHelloConsumer", "sun.security.ssl.ServerHello", "T13ServerHelloConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T12ServerHelloConsumer", "sun.security.ssl.ServerHello", "T12ServerHelloConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$ServerHelloConsumer", "sun.security.ssl.ServerHello", "ServerHelloConsumer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T13HelloRetryRequestReproducer", "sun.security.ssl.ServerHello", "T13HelloRetryRequestReproducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T13HelloRetryRequestProducer", "sun.security.ssl.ServerHello", "T13HelloRetryRequestProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T13ServerHelloProducer", "sun.security.ssl.ServerHello", "T13ServerHelloProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$T12ServerHelloProducer", "sun.security.ssl.ServerHello", "T12ServerHelloProducer", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.ServerHello$ServerHelloMessage", "sun.security.ssl.ServerHello", "ServerHelloMessage", $STATIC | $FINAL},
	{}
};

$ClassInfo _ServerHello_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ServerHello",
	"java.lang.Object",
	nullptr,
	_ServerHello_FieldInfo_,
	_ServerHello_MethodInfo_,
	nullptr,
	nullptr,
	_ServerHello_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.ServerHello$T13HelloRetryRequestConsumer,sun.security.ssl.ServerHello$T13ServerHelloConsumer,sun.security.ssl.ServerHello$T12ServerHelloConsumer,sun.security.ssl.ServerHello$ServerHelloConsumer,sun.security.ssl.ServerHello$T13HelloRetryRequestReproducer,sun.security.ssl.ServerHello$T13HelloRetryRequestProducer,sun.security.ssl.ServerHello$T13ServerHelloProducer,sun.security.ssl.ServerHello$T12ServerHelloProducer,sun.security.ssl.ServerHello$T12ServerHelloProducer$KeyExchangeProperties,sun.security.ssl.ServerHello$ServerHelloMessage"
};

$Object* allocate$ServerHello($Class* clazz) {
	return $of($alloc(ServerHello));
}

$SSLConsumer* ServerHello::handshakeConsumer = nullptr;
$HandshakeProducer* ServerHello::t12HandshakeProducer = nullptr;
$HandshakeProducer* ServerHello::t13HandshakeProducer = nullptr;
$HandshakeProducer* ServerHello::hrrHandshakeProducer = nullptr;
$HandshakeProducer* ServerHello::hrrReproducer = nullptr;
$HandshakeConsumer* ServerHello::t12HandshakeConsumer = nullptr;
$HandshakeConsumer* ServerHello::t13HandshakeConsumer = nullptr;
$HandshakeConsumer* ServerHello::d12HandshakeConsumer = nullptr;
$HandshakeConsumer* ServerHello::d13HandshakeConsumer = nullptr;
$HandshakeConsumer* ServerHello::t13HrrHandshakeConsumer = nullptr;
$HandshakeConsumer* ServerHello::d13HrrHandshakeConsumer = nullptr;

void ServerHello::init$() {
}

void ServerHello::setUpPskKD($HandshakeContext* hc, $SecretKey* psk) {
	$init(ServerHello);
	$useLocalCurrentObjectStackCache();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Using PSK to derive early secret"_s, $$new($ObjectArray, 0));
	}
	try {
		$CipherSuite$HashAlg* hashAlg = $nc($nc(hc)->negotiatedCipherSuite)->hashAlg;
		$var($HKDF, hkdf, $new($HKDF, $nc(hashAlg)->name$));
		$var($bytes, zeros, $new($bytes, $nc(hashAlg)->hashLength));
		$var($SecretKey, earlySecret, hkdf->extract(zeros, psk, "TlsEarlySecret"_s));
		$set(hc, handshakeKeyDerivation, $new($SSLSecretDerivation, hc, earlySecret));
	} catch ($GeneralSecurityException& gse) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(gse))));
	}
}

void clinit$ServerHello($Class* class$) {
	$assignStatic(ServerHello::handshakeConsumer, $new($ServerHello$ServerHelloConsumer));
	$assignStatic(ServerHello::t12HandshakeProducer, $new($ServerHello$T12ServerHelloProducer));
	$assignStatic(ServerHello::t13HandshakeProducer, $new($ServerHello$T13ServerHelloProducer));
	$assignStatic(ServerHello::hrrHandshakeProducer, $new($ServerHello$T13HelloRetryRequestProducer));
	$assignStatic(ServerHello::hrrReproducer, $new($ServerHello$T13HelloRetryRequestReproducer));
	$assignStatic(ServerHello::t12HandshakeConsumer, $new($ServerHello$T12ServerHelloConsumer));
	$assignStatic(ServerHello::t13HandshakeConsumer, $new($ServerHello$T13ServerHelloConsumer));
	$assignStatic(ServerHello::d12HandshakeConsumer, $new($ServerHello$T12ServerHelloConsumer));
	$assignStatic(ServerHello::d13HandshakeConsumer, $new($ServerHello$T13ServerHelloConsumer));
	$assignStatic(ServerHello::t13HrrHandshakeConsumer, $new($ServerHello$T13HelloRetryRequestConsumer));
	$assignStatic(ServerHello::d13HrrHandshakeConsumer, $new($ServerHello$T13HelloRetryRequestConsumer));
}

ServerHello::ServerHello() {
}

$Class* ServerHello::load$($String* name, bool initialize) {
	$loadClass(ServerHello, name, initialize, &_ServerHello_ClassInfo_, clinit$ServerHello, allocate$ServerHello);
	return class$;
}

$Class* ServerHello::class$ = nullptr;

		} // ssl
	} // security
} // sun