#include <sun/security/ssl/SSLCipher$StreamReadCipherGenerator$StreamReadCipher.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/Key.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/ShortBufferException.h>
#include <sun/security/ssl/Authenticator$MAC.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$StreamReadCipherGenerator.h>
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

$FieldInfo _SSLCipher$StreamReadCipherGenerator$StreamReadCipher_FieldInfo_[] = {
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$StreamReadCipherGenerator$StreamReadCipher, cipher)},
	{}
};

$MethodInfo _SSLCipher$StreamReadCipherGenerator$StreamReadCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Ljava/lang/String;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(SSLCipher$StreamReadCipherGenerator$StreamReadCipher, init$, void, $Authenticator*, $ProtocolVersion*, $String*, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"decrypt", "(BLjava/nio/ByteBuffer;[B)Lsun/security/ssl/Plaintext;", nullptr, $PUBLIC, $virtualMethod(SSLCipher$StreamReadCipherGenerator$StreamReadCipher, decrypt, $Plaintext*, int8_t, $ByteBuffer*, $bytes*), "java.security.GeneralSecurityException"},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$StreamReadCipherGenerator$StreamReadCipher, dispose, void)},
	{"estimateFragmentSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$StreamReadCipherGenerator$StreamReadCipher, estimateFragmentSize, int32_t, int32_t, int32_t)},
	{}
};

$InnerClassInfo _SSLCipher$StreamReadCipherGenerator$StreamReadCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$StreamReadCipherGenerator", "sun.security.ssl.SSLCipher", "StreamReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$StreamReadCipherGenerator$StreamReadCipher", "sun.security.ssl.SSLCipher$StreamReadCipherGenerator", "StreamReadCipher", $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLReadCipher", "sun.security.ssl.SSLCipher", "SSLReadCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$StreamReadCipherGenerator$StreamReadCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLCipher$StreamReadCipherGenerator$StreamReadCipher",
	"sun.security.ssl.SSLCipher$SSLReadCipher",
	nullptr,
	_SSLCipher$StreamReadCipherGenerator$StreamReadCipher_FieldInfo_,
	_SSLCipher$StreamReadCipherGenerator$StreamReadCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$StreamReadCipherGenerator$StreamReadCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$StreamReadCipherGenerator$StreamReadCipher($Class* clazz) {
	return $of($alloc(SSLCipher$StreamReadCipherGenerator$StreamReadCipher));
}

void SSLCipher$StreamReadCipherGenerator$StreamReadCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $String* algorithm, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$SSLCipher$SSLReadCipher::init$(authenticator, protocolVersion);
	$set(this, cipher, $Cipher::getInstance(algorithm));
	$nc(this->cipher)->init($Cipher::DECRYPT_MODE, key, params, random);
}

$Plaintext* SSLCipher$StreamReadCipherGenerator$StreamReadCipher::decrypt(int8_t contentType, $ByteBuffer* bb, $bytes* sequence) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(bb)->remaining();
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
	bb->position(pos);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("plaintext"_s)) {
		$SSLLogger::fine("Plaintext after DECRYPTION"_s, $$new($ObjectArray, {$($of(bb->duplicate()))}));
	}
	$var($Authenticator$MAC, signer, $cast($Authenticator$MAC, this->authenticator));
	if ($nc($($nc(signer)->macAlg()))->size != 0) {
		$SSLCipher::checkStreamMac(signer, bb, contentType, sequence);
	} else {
		$nc(this->authenticator)->increaseSequenceNumber();
	}
	$init($ProtocolVersion);
	return $new($Plaintext, contentType, $ProtocolVersion::NONE->major, $ProtocolVersion::NONE->minor, -1, -1, $(bb->slice()));
}

void SSLCipher$StreamReadCipherGenerator$StreamReadCipher::dispose() {
	if (this->cipher != nullptr) {
		try {
			$nc(this->cipher)->doFinal();
		} catch ($Exception& e) {
		}
	}
}

int32_t SSLCipher$StreamReadCipherGenerator$StreamReadCipher::estimateFragmentSize(int32_t packetSize, int32_t headerSize) {
	int32_t macLen = $nc($($nc(($cast($Authenticator$MAC, this->authenticator)))->macAlg()))->size;
	return packetSize - headerSize - macLen;
}

SSLCipher$StreamReadCipherGenerator$StreamReadCipher::SSLCipher$StreamReadCipherGenerator$StreamReadCipher() {
}

$Class* SSLCipher$StreamReadCipherGenerator$StreamReadCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$StreamReadCipherGenerator$StreamReadCipher, name, initialize, &_SSLCipher$StreamReadCipherGenerator$StreamReadCipher_ClassInfo_, allocate$SSLCipher$StreamReadCipherGenerator$StreamReadCipher);
	return class$;
}

$Class* SSLCipher$StreamReadCipherGenerator$StreamReadCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun