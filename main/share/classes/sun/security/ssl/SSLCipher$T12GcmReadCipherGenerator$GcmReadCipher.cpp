#include <sun/security/ssl/SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher.h>

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
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$T12GcmReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef NONE

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
using $Plaintext = ::sun::security::ssl::Plaintext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_FieldInfo_[] = {
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, cipher)},
	{"tagSize", "I", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, tagSize)},
	{"key", "Ljava/security/Key;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, key)},
	{"fixedIv", "[B", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, fixedIv)},
	{"recordIvSize", "I", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, recordIvSize)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, random)},
	{}
};

$MethodInfo _SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Lsun/security/ssl/SSLCipher;Ljava/lang/String;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, init$, void, $Authenticator*, $ProtocolVersion*, $SSLCipher*, $String*, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"decrypt", "(BLjava/nio/ByteBuffer;[B)Lsun/security/ssl/Plaintext;", nullptr, $PUBLIC, $virtualMethod(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, decrypt, $Plaintext*, int8_t, $ByteBuffer*, $bytes*), "java.security.GeneralSecurityException"},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, dispose, void)},
	{"estimateFragmentSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, estimateFragmentSize, int32_t, int32_t, int32_t)},
	{}
};

$InnerClassInfo _SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator", "sun.security.ssl.SSLCipher", "T12GcmReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher", "sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator", "GcmReadCipher", $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLReadCipher", "sun.security.ssl.SSLCipher", "SSLReadCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher",
	"sun.security.ssl.SSLCipher$SSLReadCipher",
	nullptr,
	_SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_FieldInfo_,
	_SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher($Class* clazz) {
	return $of($alloc(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher));
}

void SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $SSLCipher* sslCipher, $String* algorithm, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$SSLCipher$SSLReadCipher::init$(authenticator, protocolVersion);
	$set(this, cipher, $Cipher::getInstance(algorithm));
	this->tagSize = $nc(sslCipher)->tagSize;
	$set(this, key, key);
	$set(this, fixedIv, $nc(($cast($IvParameterSpec, params)))->getIV());
	this->recordIvSize = sslCipher->ivSize - sslCipher->fixedIvSize;
	$set(this, random, random);
}

$Plaintext* SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::decrypt(int8_t contentType, $ByteBuffer* bb, $bytes* sequence) {
	$useLocalCurrentObjectStackCache();
	if ($nc(bb)->remaining() < (this->recordIvSize + this->tagSize)) {
		$throwNew($BadPaddingException, $$str({"Insufficient buffer remaining for AEAD cipher fragment ("_s, $$str(bb->remaining()), "). Needs to be more than or equal to IV size ("_s, $$str(this->recordIvSize), ") + tag size ("_s, $$str(this->tagSize), ")"_s}));
	}
	$var($bytes, iv, $Arrays::copyOf(this->fixedIv, $nc(this->fixedIv)->length + this->recordIvSize));
	$nc(bb)->get(iv, $nc(this->fixedIv)->length, this->recordIvSize);
	$var($GCMParameterSpec, spec, $new($GCMParameterSpec, this->tagSize * 8, iv));
	try {
		$nc(this->cipher)->init($Cipher::DECRYPT_MODE, this->key, static_cast<$AlgorithmParameterSpec*>(spec), this->random);
	} catch ($InvalidKeyException& ikae) {
		$throwNew($RuntimeException, "invalid key or spec in GCM mode"_s, ikae);
	} catch ($InvalidAlgorithmParameterException& ikae) {
		$throwNew($RuntimeException, "invalid key or spec in GCM mode"_s, ikae);
	}
	$var($bytes, aad, $nc(this->authenticator)->acquireAuthenticationBytes(contentType, bb->remaining() - this->tagSize, sequence));
	$nc(this->cipher)->updateAAD(aad);
	int32_t len = 0;
	int32_t pos = bb->position();
	$var($ByteBuffer, dup, bb->duplicate());
	try {
		len = $nc(this->cipher)->doFinal(dup, bb);
	} catch ($IllegalBlockSizeException& ibse) {
		$var($String, var$0, $$str({"Cipher error in AEAD mode \""_s, $(ibse->getMessage()), " \"in JCE provider "_s}));
		$throwNew($RuntimeException, $$concat(var$0, $($nc($($nc(this->cipher)->getProvider()))->getName())));
	} catch ($ShortBufferException& sbe) {
		$throwNew($RuntimeException, $$str({"Cipher buffering error in JCE provider "_s, $($nc($($nc(this->cipher)->getProvider()))->getName())}), sbe);
	}
	bb->position(pos);
	bb->limit(pos + len);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("plaintext"_s)) {
		$SSLLogger::fine("Plaintext after DECRYPTION"_s, $$new($ObjectArray, {$($of(bb->duplicate()))}));
	}
	$init($ProtocolVersion);
	return $new($Plaintext, contentType, $ProtocolVersion::NONE->major, $ProtocolVersion::NONE->minor, -1, -1, $(bb->slice()));
}

void SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::dispose() {
	if (this->cipher != nullptr) {
		try {
			$nc(this->cipher)->doFinal();
		} catch ($Exception& e) {
		}
	}
}

int32_t SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::estimateFragmentSize(int32_t packetSize, int32_t headerSize) {
	return packetSize - headerSize - this->recordIvSize - this->tagSize;
}

SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher() {
}

$Class* SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher, name, initialize, &_SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher_ClassInfo_, allocate$SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher);
	return class$;
}

$Class* SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun