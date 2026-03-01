#include <sun/security/ssl/Authenticator.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/util/Arrays.h>
#include <javax/crypto/SecretKey.h>
#include <sun/security/ssl/Authenticator$DTLS10Authenticator.h>
#include <sun/security/ssl/Authenticator$DTLS10Mac.h>
#include <sun/security/ssl/Authenticator$DTLS13Authenticator.h>
#include <sun/security/ssl/Authenticator$DTLSNullMac.h>
#include <sun/security/ssl/Authenticator$SSL30Authenticator.h>
#include <sun/security/ssl/Authenticator$SSL30Mac.h>
#include <sun/security/ssl/Authenticator$SSLNullMac.h>
#include <sun/security/ssl/Authenticator$TLS10Authenticator.h>
#include <sun/security/ssl/Authenticator$TLS10Mac.h>
#include <sun/security/ssl/Authenticator$TLS13Authenticator.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Arrays = ::java::util::Arrays;
using $SecretKey = ::javax::crypto::SecretKey;
using $Authenticator$DTLS10Authenticator = ::sun::security::ssl::Authenticator$DTLS10Authenticator;
using $Authenticator$DTLS10Mac = ::sun::security::ssl::Authenticator$DTLS10Mac;
using $Authenticator$DTLS13Authenticator = ::sun::security::ssl::Authenticator$DTLS13Authenticator;
using $Authenticator$DTLSNullMac = ::sun::security::ssl::Authenticator$DTLSNullMac;
using $Authenticator$SSL30Authenticator = ::sun::security::ssl::Authenticator$SSL30Authenticator;
using $Authenticator$SSL30Mac = ::sun::security::ssl::Authenticator$SSL30Mac;
using $Authenticator$SSLNullMac = ::sun::security::ssl::Authenticator$SSLNullMac;
using $Authenticator$TLS10Authenticator = ::sun::security::ssl::Authenticator$TLS10Authenticator;
using $Authenticator$TLS10Mac = ::sun::security::ssl::Authenticator$TLS10Mac;
using $Authenticator$TLS13Authenticator = ::sun::security::ssl::Authenticator$TLS13Authenticator;
using $CipherSuite$MacAlg = ::sun::security::ssl::CipherSuite$MacAlg;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _Authenticator_FieldInfo_[] = {
	{"block", "[B", nullptr, $PROTECTED | $FINAL, $field(Authenticator, block)},
	{}
};

$MethodInfo _Authenticator_MethodInfo_[] = {
	{"<init>", "([B)V", nullptr, $PRIVATE, $method(Authenticator, init$, void, $bytes*)},
	{"acquireAuthenticationBytes", "(BI[B)[B", nullptr, 0, $virtualMethod(Authenticator, acquireAuthenticationBytes, $bytes*, int8_t, int32_t, $bytes*)},
	{"increaseSequenceNumber", "()V", nullptr, $FINAL, $method(Authenticator, increaseSequenceNumber, void)},
	{"nullDtlsMac", "()Lsun/security/ssl/Authenticator;", nullptr, $STATIC, $staticMethod(Authenticator, nullDtlsMac, Authenticator*)},
	{"nullTlsMac", "()Lsun/security/ssl/Authenticator;", nullptr, $STATIC, $staticMethod(Authenticator, nullTlsMac, Authenticator*)},
	{"seqNumIsHuge", "()Z", nullptr, $ABSTRACT, $virtualMethod(Authenticator, seqNumIsHuge, bool)},
	{"seqNumOverflow", "()Z", nullptr, $ABSTRACT, $virtualMethod(Authenticator, seqNumOverflow, bool)},
	{"sequenceNumber", "()[B", nullptr, $FINAL, $method(Authenticator, sequenceNumber, $bytes*)},
	{"setEpochNumber", "(I)V", nullptr, 0, $virtualMethod(Authenticator, setEpochNumber, void, int32_t)},
	{"toLong", "([B)J", nullptr, $STATIC | $FINAL, $staticMethod(Authenticator, toLong, int64_t, $bytes*)},
	{"valueOf", "(Lsun/security/ssl/ProtocolVersion;)Lsun/security/ssl/Authenticator;", nullptr, $STATIC, $staticMethod(Authenticator, valueOf, Authenticator*, $ProtocolVersion*)},
	{"valueOf", "(Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/CipherSuite$MacAlg;Ljavax/crypto/SecretKey;)Lsun/security/ssl/Authenticator;", "<T:Lsun/security/ssl/Authenticator;:Lsun/security/ssl/Authenticator$MAC;>(Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/CipherSuite$MacAlg;Ljavax/crypto/SecretKey;)TT;", $STATIC, $staticMethod(Authenticator, valueOf, Authenticator*, $ProtocolVersion*, $CipherSuite$MacAlg*, $SecretKey*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{}
};

$InnerClassInfo _Authenticator_InnerClassesInfo_[] = {
	{"sun.security.ssl.Authenticator$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.security.ssl.Authenticator$DTLS10Mac", "sun.security.ssl.Authenticator", "DTLS10Mac", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$DTLSNullMac", "sun.security.ssl.Authenticator", "DTLSNullMac", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$TLS10Mac", "sun.security.ssl.Authenticator", "TLS10Mac", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$SSL30Mac", "sun.security.ssl.Authenticator", "SSL30Mac", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$SSLNullMac", "sun.security.ssl.Authenticator", "SSLNullMac", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$MacImpl", "sun.security.ssl.Authenticator", "MacImpl", $PRIVATE},
	{"sun.security.ssl.Authenticator$MAC", "sun.security.ssl.Authenticator", "MAC", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.security.ssl.Authenticator$DTLS13Authenticator", "sun.security.ssl.Authenticator", "DTLS13Authenticator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$DTLS10Authenticator", "sun.security.ssl.Authenticator", "DTLS10Authenticator", $PRIVATE | $STATIC},
	{"sun.security.ssl.Authenticator$DTLSNullAuthenticator", "sun.security.ssl.Authenticator", "DTLSNullAuthenticator", $PRIVATE | $STATIC},
	{"sun.security.ssl.Authenticator$DTLSAuthenticator", "sun.security.ssl.Authenticator", "DTLSAuthenticator", $PRIVATE | $STATIC},
	{"sun.security.ssl.Authenticator$TLS13Authenticator", "sun.security.ssl.Authenticator", "TLS13Authenticator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Authenticator$TLS10Authenticator", "sun.security.ssl.Authenticator", "TLS10Authenticator", $PRIVATE | $STATIC},
	{"sun.security.ssl.Authenticator$SSL30Authenticator", "sun.security.ssl.Authenticator", "SSL30Authenticator", $PRIVATE | $STATIC},
	{"sun.security.ssl.Authenticator$SSLNullAuthenticator", "sun.security.ssl.Authenticator", "SSLNullAuthenticator", $PRIVATE | $STATIC},
	{"sun.security.ssl.Authenticator$SSLAuthenticator", "sun.security.ssl.Authenticator", "SSLAuthenticator", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Authenticator_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.ssl.Authenticator",
	"java.lang.Object",
	nullptr,
	_Authenticator_FieldInfo_,
	_Authenticator_MethodInfo_,
	nullptr,
	nullptr,
	_Authenticator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.Authenticator$1,sun.security.ssl.Authenticator$DTLS10Mac,sun.security.ssl.Authenticator$DTLSNullMac,sun.security.ssl.Authenticator$TLS10Mac,sun.security.ssl.Authenticator$SSL30Mac,sun.security.ssl.Authenticator$SSLNullMac,sun.security.ssl.Authenticator$MacImpl,sun.security.ssl.Authenticator$MAC,sun.security.ssl.Authenticator$DTLS13Authenticator,sun.security.ssl.Authenticator$DTLS10Authenticator,sun.security.ssl.Authenticator$DTLSNullAuthenticator,sun.security.ssl.Authenticator$DTLSAuthenticator,sun.security.ssl.Authenticator$TLS13Authenticator,sun.security.ssl.Authenticator$TLS10Authenticator,sun.security.ssl.Authenticator$SSL30Authenticator,sun.security.ssl.Authenticator$SSLNullAuthenticator,sun.security.ssl.Authenticator$SSLAuthenticator"
};

$Object* allocate$Authenticator($Class* clazz) {
	return $of($alloc(Authenticator));
}

void Authenticator::init$($bytes* block) {
	$set(this, block, block);
}

Authenticator* Authenticator::valueOf($ProtocolVersion* protocolVersion) {
	if ($nc(protocolVersion)->isDTLS) {
		if (protocolVersion->useTLS13PlusSpec()) {
			return $new($Authenticator$DTLS13Authenticator, protocolVersion);
		} else {
			return $new($Authenticator$DTLS10Authenticator, protocolVersion);
		}
	} else if (protocolVersion->useTLS13PlusSpec()) {
		return $new($Authenticator$TLS13Authenticator, protocolVersion);
	} else if (protocolVersion->useTLS10PlusSpec()) {
		return $new($Authenticator$TLS10Authenticator, protocolVersion);
	} else {
		return $new($Authenticator$SSL30Authenticator);
	}
}

Authenticator* Authenticator::valueOf($ProtocolVersion* protocolVersion, $CipherSuite$MacAlg* macAlg, $SecretKey* key) {
	if ($nc(protocolVersion)->isDTLS) {
		if (protocolVersion->useTLS13PlusSpec()) {
			$throwNew($RuntimeException, "No MacAlg used in DTLS 1.3"_s);
		} else {
			return static_cast<Authenticator*>(($new($Authenticator$DTLS10Mac, protocolVersion, macAlg, key)));
		}
	} else if (protocolVersion->useTLS13PlusSpec()) {
		$throwNew($RuntimeException, "No MacAlg used in TLS 1.3"_s);
	} else if (protocolVersion->useTLS10PlusSpec()) {
		return static_cast<Authenticator*>(($new($Authenticator$TLS10Mac, protocolVersion, macAlg, key)));
	} else {
		return static_cast<Authenticator*>(($new($Authenticator$SSL30Mac, protocolVersion, macAlg, key)));
	}
}

Authenticator* Authenticator::nullTlsMac() {
	return $new($Authenticator$SSLNullMac);
}

Authenticator* Authenticator::nullDtlsMac() {
	return $new($Authenticator$DTLSNullMac);
}

$bytes* Authenticator::sequenceNumber() {
	return $Arrays::copyOf(this->block, 8);
}

void Authenticator::setEpochNumber(int32_t epoch) {
	$throwNew($UnsupportedOperationException, "Epoch numbers apply to DTLS protocols only"_s);
}

void Authenticator::increaseSequenceNumber() {
	int32_t k = 7;
	while (true) {
		bool var$0 = (k >= 0);
		if (!(var$0 && (++(*$nc(this->block))[k] == 0))) {
			break;
		}
		{
			--k;
		}
	}
}

$bytes* Authenticator::acquireAuthenticationBytes(int8_t type, int32_t length, $bytes* sequence) {
	$throwNew($UnsupportedOperationException, "Used by AEAD algorithms only"_s);
	$shouldNotReachHere();
}

int64_t Authenticator::toLong($bytes* recordEnS) {
	if (recordEnS != nullptr && recordEnS->length == 8) {
		return (((((((((int64_t)(recordEnS->get(0) & (uint64_t)(int64_t)255)) << 56) | (((int64_t)(recordEnS->get(1) & (uint64_t)(int64_t)255)) << 48)) | (((int64_t)(recordEnS->get(2) & (uint64_t)(int64_t)255)) << 40)) | (((int64_t)(recordEnS->get(3) & (uint64_t)(int64_t)255)) << 32)) | (((int64_t)(recordEnS->get(4) & (uint64_t)(int64_t)255)) << 24)) | (((int64_t)(recordEnS->get(5) & (uint64_t)(int64_t)255)) << 16)) | (((int64_t)(recordEnS->get(6) & (uint64_t)(int64_t)255)) << 8)) | ((int64_t)(recordEnS->get(7) & (uint64_t)(int64_t)255));
	}
	return -1;
}

Authenticator::Authenticator() {
}

$Class* Authenticator::load$($String* name, bool initialize) {
	$loadClass(Authenticator, name, initialize, &_Authenticator_ClassInfo_, allocate$Authenticator);
	return class$;
}

$Class* Authenticator::class$ = nullptr;

		} // ssl
	} // security
} // sun