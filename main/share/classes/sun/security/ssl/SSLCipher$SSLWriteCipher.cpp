#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/SecureRandom.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher.h>
#include <jcpp.h>

#undef B_NULL
#undef NONE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $SecureRandom = ::java::security::SecureRandom;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher$SSLWriteCipher_FieldInfo_[] = {
	{"authenticator", "Lsun/security/ssl/Authenticator;", nullptr, $FINAL, $field(SSLCipher$SSLWriteCipher, authenticator)},
	{"protocolVersion", "Lsun/security/ssl/ProtocolVersion;", nullptr, $FINAL, $field(SSLCipher$SSLWriteCipher, protocolVersion)},
	{"keyLimitEnabled", "Z", nullptr, 0, $field(SSLCipher$SSLWriteCipher, keyLimitEnabled)},
	{"keyLimitCountdown", "J", nullptr, 0, $field(SSLCipher$SSLWriteCipher, keyLimitCountdown)},
	{"baseSecret", "Ljavax/crypto/SecretKey;", nullptr, 0, $field(SSLCipher$SSLWriteCipher, baseSecret)},
	{}
};

$MethodInfo _SSLCipher$SSLWriteCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;)V", nullptr, 0, $method(SSLCipher$SSLWriteCipher, init$, void, $Authenticator*, $ProtocolVersion*)},
	{"atKeyLimit", "()Z", nullptr, $PUBLIC, $virtualMethod(SSLCipher$SSLWriteCipher, atKeyLimit, bool)},
	{"calculateFragmentSize", "(II)I", nullptr, $ABSTRACT, $virtualMethod(SSLCipher$SSLWriteCipher, calculateFragmentSize, int32_t, int32_t, int32_t)},
	{"calculatePacketSize", "(II)I", nullptr, $ABSTRACT, $virtualMethod(SSLCipher$SSLWriteCipher, calculatePacketSize, int32_t, int32_t, int32_t)},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$SSLWriteCipher, dispose, void)},
	{"encrypt", "(BLjava/nio/ByteBuffer;)I", nullptr, $ABSTRACT, $virtualMethod(SSLCipher$SSLWriteCipher, encrypt, int32_t, int8_t, $ByteBuffer*)},
	{"getExplicitNonceSize", "()I", nullptr, $ABSTRACT, $virtualMethod(SSLCipher$SSLWriteCipher, getExplicitNonceSize, int32_t)},
	{"isCBCMode", "()Z", nullptr, 0, $virtualMethod(SSLCipher$SSLWriteCipher, isCBCMode, bool)},
	{"isNullCipher", "()Z", nullptr, 0, $virtualMethod(SSLCipher$SSLWriteCipher, isNullCipher, bool)},
	{"nullDTlsWriteCipher", "()Lsun/security/ssl/SSLCipher$SSLWriteCipher;", nullptr, $STATIC | $FINAL, $staticMethod(SSLCipher$SSLWriteCipher, nullDTlsWriteCipher, SSLCipher$SSLWriteCipher*)},
	{"nullTlsWriteCipher", "()Lsun/security/ssl/SSLCipher$SSLWriteCipher;", nullptr, $STATIC | $FINAL, $staticMethod(SSLCipher$SSLWriteCipher, nullTlsWriteCipher, SSLCipher$SSLWriteCipher*)},
	{}
};

$InnerClassInfo _SSLCipher$SSLWriteCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$SSLWriteCipher", "sun.security.ssl.SSLCipher", "SSLWriteCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$SSLWriteCipher_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.ssl.SSLCipher$SSLWriteCipher",
	"java.lang.Object",
	nullptr,
	_SSLCipher$SSLWriteCipher_FieldInfo_,
	_SSLCipher$SSLWriteCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$SSLWriteCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$SSLWriteCipher($Class* clazz) {
	return $of($alloc(SSLCipher$SSLWriteCipher));
}

void SSLCipher$SSLWriteCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion) {
	this->keyLimitEnabled = false;
	this->keyLimitCountdown = 0;
	$set(this, authenticator, authenticator);
	$set(this, protocolVersion, protocolVersion);
}

SSLCipher$SSLWriteCipher* SSLCipher$SSLWriteCipher::nullTlsWriteCipher() {
	try {
		$init($SSLCipher);
		$init($ProtocolVersion);
		return $SSLCipher::B_NULL->createWriteCipher($($Authenticator::nullTlsMac()), $ProtocolVersion::NONE, nullptr, nullptr, nullptr);
	} catch ($GeneralSecurityException& gse) {
		$throwNew($RuntimeException, "Cannot create NULL SSL write Cipher"_s, gse);
	}
	$shouldNotReachHere();
}

SSLCipher$SSLWriteCipher* SSLCipher$SSLWriteCipher::nullDTlsWriteCipher() {
	try {
		$init($SSLCipher);
		$init($ProtocolVersion);
		return $SSLCipher::B_NULL->createWriteCipher($($Authenticator::nullDtlsMac()), $ProtocolVersion::NONE, nullptr, nullptr, nullptr);
	} catch ($GeneralSecurityException& gse) {
		$throwNew($RuntimeException, "Cannot create NULL SSL write Cipher"_s, gse);
	}
	$shouldNotReachHere();
}

void SSLCipher$SSLWriteCipher::dispose() {
}

bool SSLCipher$SSLWriteCipher::isCBCMode() {
	return false;
}

bool SSLCipher$SSLWriteCipher::isNullCipher() {
	return false;
}

bool SSLCipher$SSLWriteCipher::atKeyLimit() {
	if (this->keyLimitCountdown >= 0) {
		return false;
	}
	this->keyLimitEnabled = false;
	return true;
}

SSLCipher$SSLWriteCipher::SSLCipher$SSLWriteCipher() {
}

$Class* SSLCipher$SSLWriteCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$SSLWriteCipher, name, initialize, &_SSLCipher$SSLWriteCipher_ClassInfo_, allocate$SSLCipher$SSLWriteCipher);
	return class$;
}

$Class* SSLCipher$SSLWriteCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun