#include <sun/security/ssl/SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/HashMap.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/ShortBufferException.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher$T13CC20P1305WriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

#undef ENCRYPT_MODE

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $HashMap = ::java::util::HashMap;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_FieldInfo_[] = {
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, cipher)},
	{"tagSize", "I", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, tagSize)},
	{"key", "Ljava/security/Key;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, key)},
	{"iv", "[B", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, iv)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, random)},
	{}
};

$MethodInfo _SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/SSLCipher;Ljava/lang/String;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, init$, void, $Authenticator*, $ProtocolVersion*, $SSLCipher*, $String*, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"calculateFragmentSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, calculateFragmentSize, int32_t, int32_t, int32_t)},
	{"calculatePacketSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, calculatePacketSize, int32_t, int32_t, int32_t)},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, dispose, void)},
	{"encrypt", "(BLjava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, encrypt, int32_t, int8_t, $ByteBuffer*)},
	{"getExplicitNonceSize", "()I", nullptr, 0, $virtualMethod(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, getExplicitNonceSize, int32_t)},
	{}
};

$InnerClassInfo _SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator", "sun.security.ssl.SSLCipher", "T13CC20P1305WriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher", "sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator", "CC20P1305WriteCipher", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLWriteCipher", "sun.security.ssl.SSLCipher", "SSLWriteCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher",
	"sun.security.ssl.SSLCipher$SSLWriteCipher",
	nullptr,
	_SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_FieldInfo_,
	_SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher($Class* clazz) {
	return $of($alloc(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher));
}

void SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $SSLCipher* sslCipher, $String* algorithm, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$SSLCipher$SSLWriteCipher::init$(authenticator, protocolVersion);
	$set(this, cipher, $Cipher::getInstance(algorithm));
	this->tagSize = $nc(sslCipher)->tagSize;
	$set(this, key, key);
	$set(this, iv, $nc(($cast($IvParameterSpec, params)))->getIV());
	$set(this, random, random);
	$init($SSLCipher);
	$var($Object, var$0, $of($str({$($nc(algorithm)->toUpperCase()), ":"_s, $nc($SSLCipher::tag)->get(0)})));
	this->keyLimitCountdown = $nc(($cast($Long, $($nc($SSLCipher::cipherLimits)->getOrDefault(var$0, $($Long::valueOf((int64_t)0)))))))->longValue();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::fine($$str({"algorithm = "_s, $($nc(algorithm)->toUpperCase()), ":"_s, $nc($SSLCipher::tag)->get(0), "\ncountdown value = "_s, $$str(this->keyLimitCountdown)}), $$new($ObjectArray, 0));
	}
	if (this->keyLimitCountdown > 0) {
		this->keyLimitEnabled = true;
	}
}

int32_t SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::encrypt(int8_t contentType, $ByteBuffer* bb) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, sn, $nc(this->authenticator)->sequenceNumber());
	$var($bytes, nonce, $new($bytes, $nc(this->iv)->length));
	$System::arraycopy(sn, 0, nonce, nonce->length - $nc(sn)->length, sn->length);
	for (int32_t i = 0; i < nonce->length; ++i) {
		(*nonce)[i] ^= $nc(this->iv)->get(i);
	}
	$var($AlgorithmParameterSpec, spec, $new($IvParameterSpec, nonce));
	try {
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, this->key, spec, this->random);
	} catch ($InvalidKeyException& ikae) {
		$throwNew($RuntimeException, "invalid key or spec in AEAD mode"_s, ikae);
	} catch ($InvalidAlgorithmParameterException& ikae) {
		$throwNew($RuntimeException, "invalid key or spec in AEAD mode"_s, ikae);
	}
	int32_t outputSize = $nc(this->cipher)->getOutputSize($nc(bb)->remaining());
	$var($bytes, aad, $nc(this->authenticator)->acquireAuthenticationBytes(contentType, outputSize, sn));
	$nc(this->cipher)->updateAAD(aad);
	int32_t pos = $nc(bb)->position();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("plaintext"_s)) {
		$SSLLogger::fine("Plaintext before ENCRYPTION"_s, $$new($ObjectArray, {$($of(bb->duplicate()))}));
	}
	$var($ByteBuffer, dup, bb->duplicate());
	if (outputSize > bb->remaining()) {
		bb->limit(pos + outputSize);
	}
	int32_t len = 0;
	try {
		len = $nc(this->cipher)->doFinal(dup, bb);
	} catch ($IllegalBlockSizeException& ibse) {
		$throwNew($RuntimeException, $$str({"Cipher error in AEAD mode in JCE provider "_s, $($nc($($nc(this->cipher)->getProvider()))->getName())}), ibse);
	} catch ($BadPaddingException& ibse) {
		$throwNew($RuntimeException, $$str({"Cipher error in AEAD mode in JCE provider "_s, $($nc($($nc(this->cipher)->getProvider()))->getName())}), ibse);
	} catch ($ShortBufferException& ibse) {
		$throwNew($RuntimeException, $$str({"Cipher error in AEAD mode in JCE provider "_s, $($nc($($nc(this->cipher)->getProvider()))->getName())}), ibse);
	}
	if (len != outputSize) {
		$throwNew($RuntimeException, $$str({"Cipher buffering error in JCE provider "_s, $($nc($($nc(this->cipher)->getProvider()))->getName())}));
	}
	if (this->keyLimitEnabled) {
		this->keyLimitCountdown -= len;
	}
	return len;
}

void SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::dispose() {
	if (this->cipher != nullptr) {
		try {
			$nc(this->cipher)->doFinal();
		} catch ($Exception& e) {
		}
	}
}

int32_t SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::getExplicitNonceSize() {
	return 0;
}

int32_t SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::calculateFragmentSize(int32_t packetLimit, int32_t headerSize) {
	return packetLimit - headerSize - this->tagSize;
}

int32_t SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::calculatePacketSize(int32_t fragmentSize, int32_t headerSize) {
	return fragmentSize + headerSize + this->tagSize;
}

SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher() {
}

$Class* SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher, name, initialize, &_SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher_ClassInfo_, allocate$SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher);
	return class$;
}

$Class* SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun