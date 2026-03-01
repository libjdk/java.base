#include <sun/security/ssl/SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/Key.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/ShortBufferException.h>
#include <sun/security/ssl/Authenticator$MAC.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$T10BlockReadCipherGenerator.h>
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
using $Key = ::java::security::Key;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $Authenticator$MAC = ::sun::security::ssl::Authenticator$MAC;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_FieldInfo_[] = {
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, cipher)},
	{}
};

$MethodInfo _SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Ljava/lang/String;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, init$, void, $Authenticator*, $ProtocolVersion*, $String*, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"decrypt", "(BLjava/nio/ByteBuffer;[B)Lsun/security/ssl/Plaintext;", nullptr, $PUBLIC, $virtualMethod(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, decrypt, $Plaintext*, int8_t, $ByteBuffer*, $bytes*), "java.security.GeneralSecurityException"},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, dispose, void)},
	{"estimateFragmentSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, estimateFragmentSize, int32_t, int32_t, int32_t)},
	{"sanityCheck", "(II)Z", nullptr, $PRIVATE, $method(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, sanityCheck, bool, int32_t, int32_t)},
	{}
};

$InnerClassInfo _SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator", "sun.security.ssl.SSLCipher", "T10BlockReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher", "sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator", "BlockReadCipher", $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLReadCipher", "sun.security.ssl.SSLCipher", "SSLReadCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher",
	"sun.security.ssl.SSLCipher$SSLReadCipher",
	nullptr,
	_SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_FieldInfo_,
	_SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher($Class* clazz) {
	return $of($alloc(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher));
}

void SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $String* algorithm, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$SSLCipher$SSLReadCipher::init$(authenticator, protocolVersion);
	$set(this, cipher, $Cipher::getInstance(algorithm));
	$nc(this->cipher)->init($Cipher::DECRYPT_MODE, key, params, random);
}

$Plaintext* SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::decrypt(int8_t contentType, $ByteBuffer* bb, $bytes* sequence) {
	$useLocalCurrentObjectStackCache();
	$var($BadPaddingException, reservedBPE, nullptr);
	$var($Authenticator$MAC, signer, $cast($Authenticator$MAC, this->authenticator));
	int32_t cipheredLength = $nc(bb)->remaining();
	int32_t tagLen = $nc($($nc(signer)->macAlg()))->size;
	if (tagLen != 0) {
		if (!sanityCheck(tagLen, bb->remaining())) {
			$assign(reservedBPE, $new($BadPaddingException, "ciphertext sanity check failed"_s));
		}
	}
	int32_t len = bb->remaining();
	int32_t pos = bb->position();
	$var($ByteBuffer, dup, bb->duplicate());
	try {
		if (len != $nc(this->cipher)->update(dup, bb)) {
			$throwNew($RuntimeException, "Unexpected number of plaintext bytes"_s);
		}
		int32_t var$0 = bb->position();
		if (var$0 != $nc(dup)->position()) {
			$throwNew($RuntimeException, "Unexpected ByteBuffer position"_s);
		}
	} catch ($ShortBufferException& sbe) {
		$throwNew($RuntimeException, $$str({"Cipher buffering error in JCE provider "_s, $($nc($($nc(this->cipher)->getProvider()))->getName())}), sbe);
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("plaintext"_s)) {
		$SSLLogger::fine("Padded plaintext after DECRYPTION"_s, $$new($ObjectArray, {$($of($nc($(bb->duplicate()))->position(pos)))}));
	}
	int32_t blockSize = $nc(this->cipher)->getBlockSize();
	bb->position(pos);
	try {
		$SSLCipher::removePadding(bb, tagLen, blockSize, this->protocolVersion);
	} catch ($BadPaddingException& bpe) {
		if (reservedBPE == nullptr) {
			$assign(reservedBPE, bpe);
		}
	}
	try {
		if (tagLen != 0) {
			$SSLCipher::checkCBCMac(signer, bb, contentType, cipheredLength, sequence);
		} else {
			$nc(this->authenticator)->increaseSequenceNumber();
		}
	} catch ($BadPaddingException& bpe) {
		if (reservedBPE == nullptr) {
			$assign(reservedBPE, bpe);
		}
	}
	if (reservedBPE != nullptr) {
		$throw(reservedBPE);
	}
	$init($ProtocolVersion);
	return $new($Plaintext, contentType, $ProtocolVersion::NONE->major, $ProtocolVersion::NONE->minor, -1, -1, $(bb->slice()));
}

void SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::dispose() {
	if (this->cipher != nullptr) {
		try {
			$nc(this->cipher)->doFinal();
		} catch ($Exception& e) {
		}
	}
}

int32_t SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::estimateFragmentSize(int32_t packetSize, int32_t headerSize) {
	int32_t macLen = $nc($($nc(($cast($Authenticator$MAC, this->authenticator)))->macAlg()))->size;
	return packetSize - headerSize - macLen - 1;
}

bool SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::sanityCheck(int32_t tagLen, int32_t fragmentLen) {
	int32_t blockSize = $nc(this->cipher)->getBlockSize();
	if (($mod(fragmentLen, blockSize)) == 0) {
		int32_t minimal = tagLen + 1;
		minimal = (minimal >= blockSize) ? minimal : blockSize;
		return (fragmentLen >= minimal);
	}
	return false;
}

SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher() {
}

$Class* SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher, name, initialize, &_SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher_ClassInfo_, allocate$SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher);
	return class$;
}

$Class* SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun