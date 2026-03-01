#include <sun/security/ssl/SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/ShortBufferException.h>
#include <javax/crypto/spec/GCMParameterSpec.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher$T12GcmWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

#undef ENCRYPT_MODE

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $GCMParameterSpec = ::javax::crypto::spec::GCMParameterSpec;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_FieldInfo_[] = {
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, cipher)},
	{"tagSize", "I", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, tagSize)},
	{"key", "Ljava/security/Key;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, key)},
	{"fixedIv", "[B", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, fixedIv)},
	{"recordIvSize", "I", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, recordIvSize)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, random)},
	{}
};

$MethodInfo _SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/SSLCipher;Ljava/lang/String;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, init$, void, $Authenticator*, $ProtocolVersion*, $SSLCipher*, $String*, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"calculateFragmentSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, calculateFragmentSize, int32_t, int32_t, int32_t)},
	{"calculatePacketSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, calculatePacketSize, int32_t, int32_t, int32_t)},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, dispose, void)},
	{"encrypt", "(BLjava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, encrypt, int32_t, int8_t, $ByteBuffer*)},
	{"getExplicitNonceSize", "()I", nullptr, 0, $virtualMethod(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, getExplicitNonceSize, int32_t)},
	{}
};

$InnerClassInfo _SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator", "sun.security.ssl.SSLCipher", "T12GcmWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher", "sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator", "GcmWriteCipher", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLWriteCipher", "sun.security.ssl.SSLCipher", "SSLWriteCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher",
	"sun.security.ssl.SSLCipher$SSLWriteCipher",
	nullptr,
	_SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_FieldInfo_,
	_SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher($Class* clazz) {
	return $of($alloc(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher));
}

void SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $SSLCipher* sslCipher, $String* algorithm, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$SSLCipher$SSLWriteCipher::init$(authenticator, protocolVersion);
	$set(this, cipher, $Cipher::getInstance(algorithm));
	this->tagSize = $nc(sslCipher)->tagSize;
	$set(this, key, key);
	$set(this, fixedIv, $nc(($cast($IvParameterSpec, params)))->getIV());
	this->recordIvSize = sslCipher->ivSize - sslCipher->fixedIvSize;
	$set(this, random, random);
}

int32_t SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::encrypt(int8_t contentType, $ByteBuffer* bb) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, nonce, $nc(this->authenticator)->sequenceNumber());
	$var($bytes, iv, $Arrays::copyOf(this->fixedIv, $nc(this->fixedIv)->length + $nc(nonce)->length));
	$System::arraycopy(nonce, 0, iv, $nc(this->fixedIv)->length, $nc(nonce)->length);
	$var($GCMParameterSpec, spec, $new($GCMParameterSpec, this->tagSize * 8, iv));
	try {
		$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, this->key, static_cast<$AlgorithmParameterSpec*>(spec), this->random);
	} catch ($InvalidKeyException& ikae) {
		$throwNew($RuntimeException, "invalid key or spec in GCM mode"_s, ikae);
	} catch ($InvalidAlgorithmParameterException& ikae) {
		$throwNew($RuntimeException, "invalid key or spec in GCM mode"_s, ikae);
	}
	$var($bytes, aad, $nc(this->authenticator)->acquireAuthenticationBytes(contentType, $nc(bb)->remaining(), nullptr));
	$nc(this->cipher)->updateAAD(aad);
	$nc(bb)->position(bb->position() - $nc(nonce)->length);
	bb->put(nonce);
	int32_t len = 0;
	int32_t pos = bb->position();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("plaintext"_s)) {
		$SSLLogger::fine("Plaintext before ENCRYPTION"_s, $$new($ObjectArray, {$($of(bb->duplicate()))}));
	}
	$var($ByteBuffer, dup, bb->duplicate());
	int32_t outputSize = $nc(this->cipher)->getOutputSize($nc(dup)->remaining());
	if (outputSize > bb->remaining()) {
		bb->limit(pos + outputSize);
	}
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
	return len + $nc(nonce)->length;
}

void SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::dispose() {
	if (this->cipher != nullptr) {
		try {
			$nc(this->cipher)->doFinal();
		} catch ($Exception& e) {
		}
	}
}

int32_t SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::getExplicitNonceSize() {
	return this->recordIvSize;
}

int32_t SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::calculateFragmentSize(int32_t packetLimit, int32_t headerSize) {
	return packetLimit - headerSize - this->recordIvSize - this->tagSize;
}

int32_t SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::calculatePacketSize(int32_t fragmentSize, int32_t headerSize) {
	return fragmentSize + headerSize + this->recordIvSize + this->tagSize;
}

SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher() {
}

$Class* SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher, name, initialize, &_SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher_ClassInfo_, allocate$SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher);
	return class$;
}

$Class* SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun