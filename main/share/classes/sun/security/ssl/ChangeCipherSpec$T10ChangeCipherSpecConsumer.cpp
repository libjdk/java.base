#include <sun/security/ssl/ChangeCipherSpec$T10ChangeCipherSpecConsumer.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SecureRandom.h>
#include <java/util/Map.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ChangeCipherSpec.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/CipherType.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef AEAD_CIPHER
#undef CHANGE_CIPHER_SPEC
#undef HANDSHAKE_FAILURE
#undef ILLEGAL_PARAMETER
#undef UNEXPECTED_MESSAGE

using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Map = ::java::util::Map;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SSLException = ::javax::net::ssl::SSLException;
using $Alert = ::sun::security::ssl::Alert;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $CipherType = ::sun::security::ssl::CipherType;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation = ::sun::security::ssl::SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _ChangeCipherSpec$T10ChangeCipherSpecConsumer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ChangeCipherSpec$T10ChangeCipherSpecConsumer, init$, void)},
	{"consume", "(Lsun/security/ssl/ConnectionContext;Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(ChangeCipherSpec$T10ChangeCipherSpecConsumer, consume, void, $ConnectionContext*, $ByteBuffer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ChangeCipherSpec$T10ChangeCipherSpecConsumer_InnerClassesInfo_[] = {
	{"sun.security.ssl.ChangeCipherSpec$T10ChangeCipherSpecConsumer", "sun.security.ssl.ChangeCipherSpec", "T10ChangeCipherSpecConsumer", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ChangeCipherSpec$T10ChangeCipherSpecConsumer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.ChangeCipherSpec$T10ChangeCipherSpecConsumer",
	"java.lang.Object",
	"sun.security.ssl.SSLConsumer",
	nullptr,
	_ChangeCipherSpec$T10ChangeCipherSpecConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_ChangeCipherSpec$T10ChangeCipherSpecConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.ChangeCipherSpec"
};

$Object* allocate$ChangeCipherSpec$T10ChangeCipherSpecConsumer($Class* clazz) {
	return $of($alloc(ChangeCipherSpec$T10ChangeCipherSpecConsumer));
}

void ChangeCipherSpec$T10ChangeCipherSpecConsumer::init$() {
}

void ChangeCipherSpec$T10ChangeCipherSpecConsumer::consume($ConnectionContext* context, $ByteBuffer* message) {
	$useLocalCurrentObjectStackCache();
	$var($TransportContext, tc, $cast($TransportContext, context));
	$init($ContentType);
	$nc($nc(tc)->consumers)->remove($($Byte::valueOf($ContentType::CHANGE_CIPHER_SPEC->id)));
	bool var$0 = $nc(message)->remaining() != 1;
	if (var$0 || $nc(message)->get() != 1) {
		$init($Alert);
		$throw($(tc->fatal($Alert::UNEXPECTED_MESSAGE, "Malformed or unexpected ChangeCipherSpec message"_s)));
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
		$SSLLogger::fine("Consuming ChangeCipherSpec message"_s, $$new($ObjectArray, 0));
	}
	if (tc->handshakeContext == nullptr) {
		$init($Alert);
		$throw($(tc->fatal($Alert::HANDSHAKE_FAILURE, "Unexpected ChangeCipherSpec message"_s)));
	}
	$var($HandshakeContext, hc, tc->handshakeContext);
	if ($nc(hc)->handshakeKeyDerivation == nullptr) {
		$init($Alert);
		$throw($(tc->fatal($Alert::UNEXPECTED_MESSAGE, "Unexpected ChangeCipherSpec message"_s)));
	}
	$var($SSLKeyDerivation, kd, $nc(hc)->handshakeKeyDerivation);
	if ($instanceOf($SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, kd)) {
		$var($SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, tkd, $cast($SSLTrafficKeyDerivation$LegacyTrafficKeyDerivation, kd));
		$CipherSuite* ncs = hc->negotiatedCipherSuite;
		$var($Authenticator, readAuthenticator, nullptr);
		$init($CipherType);
		if ($nc(ncs)->bulkCipher->cipherType == $CipherType::AEAD_CIPHER) {
			$assign(readAuthenticator, $Authenticator::valueOf(hc->negotiatedProtocol));
		} else {
			try {
				$assign(readAuthenticator, $Authenticator::valueOf(hc->negotiatedProtocol, ncs->macAlg, $($nc(tkd)->getTrafficKey($nc(hc->sslConfig)->isClientMode ? "serverMacKey"_s : "clientMacKey"_s))));
			} catch ($NoSuchAlgorithmException& e) {
				$throwNew($SSLException, "Algorithm missing:  "_s, e);
			} catch ($InvalidKeyException& e) {
				$throwNew($SSLException, "Algorithm missing:  "_s, e);
			}
		}
		$var($SecretKey, readKey, $nc(tkd)->getTrafficKey($nc(hc->sslConfig)->isClientMode ? "serverWriteKey"_s : "clientWriteKey"_s));
		$var($SecretKey, readIv, tkd->getTrafficKey($nc(hc->sslConfig)->isClientMode ? "serverWriteIv"_s : "clientWriteIv"_s));
		$var($IvParameterSpec, iv, (readIv == nullptr) ? ($IvParameterSpec*)nullptr : $new($IvParameterSpec, $($nc(readIv)->getEncoded())));
		$var($SSLCipher$SSLReadCipher, readCipher, nullptr);
		try {
			$assign(readCipher, $nc(ncs)->bulkCipher->createReadCipher(readAuthenticator, hc->negotiatedProtocol, readKey, iv, $($nc(hc->sslContext)->getSecureRandom())));
		} catch ($GeneralSecurityException& gse) {
			$throwNew($SSLException, "Algorithm missing:  "_s, gse);
		}
		if (readCipher == nullptr) {
			$init($Alert);
			$throw($($nc(hc->conContext)->fatal($Alert::ILLEGAL_PARAMETER, $$str({"Illegal cipher suite ("_s, hc->negotiatedCipherSuite, ") and protocol version ("_s, hc->negotiatedProtocol, ")"_s}))));
		}
		$nc(tc->inputRecord)->changeReadCiphers(readCipher);
	} else {
		$throwNew($UnsupportedOperationException, "Not supported."_s);
	}
}

ChangeCipherSpec$T10ChangeCipherSpecConsumer::ChangeCipherSpec$T10ChangeCipherSpecConsumer() {
}

$Class* ChangeCipherSpec$T10ChangeCipherSpecConsumer::load$($String* name, bool initialize) {
	$loadClass(ChangeCipherSpec$T10ChangeCipherSpecConsumer, name, initialize, &_ChangeCipherSpec$T10ChangeCipherSpecConsumer_ClassInfo_, allocate$ChangeCipherSpec$T10ChangeCipherSpecConsumer);
	return class$;
}

$Class* ChangeCipherSpec$T10ChangeCipherSpecConsumer::class$ = nullptr;

		} // ssl
	} // security
} // sun