#include <sun/security/ssl/SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher.h>

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
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher$T10BlockWriteCipherGenerator.h>
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
using $Key = ::java::security::Key;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Cipher = ::javax::crypto::Cipher;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $Authenticator$MAC = ::sun::security::ssl::Authenticator$MAC;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher = ::sun::security::ssl::SSLCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_FieldInfo_[] = {
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE | $FINAL, $field(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, cipher)},
	{}
};

$MethodInfo _SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Ljava/lang/String;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, init$, void, $Authenticator*, $ProtocolVersion*, $String*, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"calculateFragmentSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, calculateFragmentSize, int32_t, int32_t, int32_t)},
	{"calculatePacketSize", "(II)I", nullptr, 0, $virtualMethod(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, calculatePacketSize, int32_t, int32_t, int32_t)},
	{"dispose", "()V", nullptr, 0, $virtualMethod(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, dispose, void)},
	{"encrypt", "(BLjava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, encrypt, int32_t, int8_t, $ByteBuffer*)},
	{"getExplicitNonceSize", "()I", nullptr, 0, $virtualMethod(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, getExplicitNonceSize, int32_t)},
	{"isCBCMode", "()Z", nullptr, 0, $virtualMethod(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, isCBCMode, bool)},
	{}
};

$InnerClassInfo _SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator", "sun.security.ssl.SSLCipher", "T10BlockWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher", "sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator", "BlockWriteCipher", $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLWriteCipher", "sun.security.ssl.SSLCipher", "SSLWriteCipher", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher",
	"sun.security.ssl.SSLCipher$SSLWriteCipher",
	nullptr,
	_SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_FieldInfo_,
	_SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher"
};

$Object* allocate$SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher($Class* clazz) {
	return $of($alloc(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher));
}

void SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::init$($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $String* algorithm, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$SSLCipher$SSLWriteCipher::init$(authenticator, protocolVersion);
	$set(this, cipher, $Cipher::getInstance(algorithm));
	$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, key, params, random);
}

int32_t SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::encrypt(int8_t contentType, $ByteBuffer* bb) {
	$useLocalCurrentObjectStackCache();
	int32_t pos = $nc(bb)->position();
	$var($Authenticator$MAC, signer, $cast($Authenticator$MAC, this->authenticator));
	if ($nc($($nc(signer)->macAlg()))->size != 0) {
		$SSLCipher::addMac(signer, bb, contentType);
	} else {
		$nc(this->authenticator)->increaseSequenceNumber();
	}
	int32_t blockSize = $nc(this->cipher)->getBlockSize();
	int32_t len = $SSLCipher::addPadding(bb, blockSize);
	bb->position(pos);
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("plaintext"_s)) {
		$SSLLogger::fine("Padded plaintext before ENCRYPTION"_s, $$new($ObjectArray, {$($of(bb->duplicate()))}));
	}
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
	return len;
}

void SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::dispose() {
	if (this->cipher != nullptr) {
		try {
			$nc(this->cipher)->doFinal();
		} catch ($Exception& e) {
		}
	}
}

int32_t SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::getExplicitNonceSize() {
	return 0;
}

int32_t SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::calculateFragmentSize(int32_t packetLimit, int32_t headerSize) {
	int32_t macLen = $nc($($nc(($cast($Authenticator$MAC, this->authenticator)))->macAlg()))->size;
	int32_t blockSize = $nc(this->cipher)->getBlockSize();
	int32_t fragLen = packetLimit - headerSize;
	fragLen -= ($mod(fragLen, blockSize));
	fragLen -= 1;
	fragLen -= macLen;
	return fragLen;
}

int32_t SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::calculatePacketSize(int32_t fragmentSize, int32_t headerSize) {
	int32_t macLen = $nc($($nc(($cast($Authenticator$MAC, this->authenticator)))->macAlg()))->size;
	int32_t blockSize = $nc(this->cipher)->getBlockSize();
	int32_t paddedLen = fragmentSize + macLen + 1;
	if (($mod(paddedLen, blockSize)) != 0) {
		paddedLen += blockSize - 1;
		paddedLen -= $mod(paddedLen, blockSize);
	}
	return headerSize + paddedLen;
}

bool SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::isCBCMode() {
	return true;
}

SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher() {
}

$Class* SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher, name, initialize, &_SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher_ClassInfo_, allocate$SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher);
	return class$;
}

$Class* SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun