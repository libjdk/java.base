#include <com/sun/crypto/provider/GaloisCounterMode.h>

#include <com/sun/crypto/provider/AESCrypt.h>
#include <com/sun/crypto/provider/ConstructKeys.h>
#include <com/sun/crypto/provider/GHASH.h>
#include <com/sun/crypto/provider/GaloisCounterMode$GCMDecrypt.h>
#include <com/sun/crypto/provider/GaloisCounterMode$GCMEncrypt.h>
#include <com/sun/crypto/provider/GaloisCounterMode$GCMEngine.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ByteOrder.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/util/Arrays.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/CipherSpi.h>
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/ShortBufferException.h>
#include <javax/crypto/spec/GCMParameterSpec.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/util/ArrayUtil.h>
#include <jcpp.h>

#undef BIG_ENDIAN
#undef DECRYPT_MODE
#undef DEFAULT_IV_LEN
#undef DEFAULT_TAG_LEN
#undef EMPTY_BUF
#undef ENCRYPT_MODE
#undef MAX_BUF_SIZE
#undef TRIGGERLEN
#undef UNWRAP_MODE
#undef WRAP_MODE

using $AESCrypt = ::com::sun::crypto::provider::AESCrypt;
using $ConstructKeys = ::com::sun::crypto::provider::ConstructKeys;
using $GHASH = ::com::sun::crypto::provider::GHASH;
using $GaloisCounterMode$GCMDecrypt = ::com::sun::crypto::provider::GaloisCounterMode$GCMDecrypt;
using $GaloisCounterMode$GCMEncrypt = ::com::sun::crypto::provider::GaloisCounterMode$GCMEncrypt;
using $GaloisCounterMode$GCMEngine = ::com::sun::crypto::provider::GaloisCounterMode$GCMEngine;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ByteOrder = ::java::nio::ByteOrder;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $Arrays = ::java::util::Arrays;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $CipherSpi = ::javax::crypto::CipherSpi;
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $GCMParameterSpec = ::javax::crypto::spec::GCMParameterSpec;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $ArrayUtil = ::sun::security::util::ArrayUtil;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _GaloisCounterMode_FieldInfo_[] = {
	{"DEFAULT_IV_LEN", "I", nullptr, $STATIC, $staticField(GaloisCounterMode, DEFAULT_IV_LEN)},
	{"DEFAULT_TAG_LEN", "I", nullptr, $STATIC, $staticField(GaloisCounterMode, DEFAULT_TAG_LEN)},
	{"MAX_BUF_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GaloisCounterMode, MAX_BUF_SIZE)},
	{"TRIGGERLEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GaloisCounterMode, TRIGGERLEN)},
	{"EMPTY_BUF", "[B", nullptr, $STATIC | $FINAL, $staticField(GaloisCounterMode, EMPTY_BUF)},
	{"initialized", "Z", nullptr, $PRIVATE, $field(GaloisCounterMode, initialized)},
	{"blockCipher", "Lcom/sun/crypto/provider/SymmetricCipher;", nullptr, 0, $field(GaloisCounterMode, blockCipher)},
	{"engine", "Lcom/sun/crypto/provider/GaloisCounterMode$GCMEngine;", nullptr, $PRIVATE, $field(GaloisCounterMode, engine)},
	{"encryption", "Z", nullptr, $PRIVATE, $field(GaloisCounterMode, encryption)},
	{"tagLenBytes", "I", nullptr, 0, $field(GaloisCounterMode, tagLenBytes)},
	{"keySize", "I", nullptr, 0, $field(GaloisCounterMode, keySize)},
	{"reInit", "Z", nullptr, 0, $field(GaloisCounterMode, reInit)},
	{"lastKey", "[B", nullptr, 0, $field(GaloisCounterMode, lastKey)},
	{"lastIv", "[B", nullptr, 0, $field(GaloisCounterMode, lastIv)},
	{"iv", "[B", nullptr, 0, $field(GaloisCounterMode, iv)},
	{"random", "Ljava/security/SecureRandom;", nullptr, 0, $field(GaloisCounterMode, random)},
	{"wrapToByteArray", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GaloisCounterMode, wrapToByteArray)},
	{}
};

$MethodInfo _GaloisCounterMode_MethodInfo_[] = {
	{"<init>", "(ILcom/sun/crypto/provider/SymmetricCipher;)V", nullptr, 0, $method(GaloisCounterMode, init$, void, int32_t, $SymmetricCipher*)},
	{"checkDataLength", "([I)V", nullptr, $PRIVATE | $TRANSIENT, $method(GaloisCounterMode, checkDataLength, void, $ints*)},
	{"checkInit", "()V", nullptr, 0, $virtualMethod(GaloisCounterMode, checkInit, void)},
	{"checkReInit", "()V", nullptr, 0, $virtualMethod(GaloisCounterMode, checkReInit, void)},
	{"createIv", "(Ljava/security/SecureRandom;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(GaloisCounterMode, createIv, $bytes*, $SecureRandom*)},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineDoFinal, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineUpdate, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.ShortBufferException"},
	{"engineUpdateAAD", "([BII)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineUpdateAAD, void, $bytes*, int32_t, int32_t)},
	{"engineUpdateAAD", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineUpdateAAD, void, $ByteBuffer*)},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(GaloisCounterMode, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{"expandToOneBlock", "([BIII)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(GaloisCounterMode, expandToOneBlock, $bytes*, $bytes*, int32_t, int32_t, int32_t)},
	{"getJ0", "([B[BI)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(GaloisCounterMode, getJ0, $bytes*, $bytes*, $bytes*, int32_t)},
	{"getLengthBlock", "(I)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(GaloisCounterMode, getLengthBlock, $bytes*, int32_t)},
	{"getLengthBlock", "(II)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(GaloisCounterMode, getLengthBlock, $bytes*, int32_t, int32_t)},
	{"increment32", "([B)V", nullptr, $STATIC, $staticMethod(GaloisCounterMode, increment32, void, $bytes*)},
	{"init", "(ILjava/security/Key;Ljavax/crypto/spec/GCMParameterSpec;)V", nullptr, 0, $virtualMethod(GaloisCounterMode, init, void, int32_t, $Key*, $GCMParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _GaloisCounterMode_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.GaloisCounterMode$GCTRGHASH", "com.sun.crypto.provider.GaloisCounterMode", "GCTRGHASH", $STATIC | $FINAL},
	{"com.sun.crypto.provider.GaloisCounterMode$AES256", "com.sun.crypto.provider.GaloisCounterMode", "AES256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.GaloisCounterMode$AES192", "com.sun.crypto.provider.GaloisCounterMode", "AES192", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.GaloisCounterMode$AES128", "com.sun.crypto.provider.GaloisCounterMode", "AES128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.GaloisCounterMode$AESGCM", "com.sun.crypto.provider.GaloisCounterMode", "AESGCM", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.GaloisCounterMode$GCMDecrypt", "com.sun.crypto.provider.GaloisCounterMode", "GCMDecrypt", 0},
	{"com.sun.crypto.provider.GaloisCounterMode$GCMEncrypt", "com.sun.crypto.provider.GaloisCounterMode", "GCMEncrypt", 0},
	{"com.sun.crypto.provider.GaloisCounterMode$GCMEngine", "com.sun.crypto.provider.GaloisCounterMode", "GCMEngine", $ABSTRACT},
	{}
};

$ClassInfo _GaloisCounterMode_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"com.sun.crypto.provider.GaloisCounterMode",
	"javax.crypto.CipherSpi",
	nullptr,
	_GaloisCounterMode_FieldInfo_,
	_GaloisCounterMode_MethodInfo_,
	nullptr,
	nullptr,
	_GaloisCounterMode_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.GaloisCounterMode$GCTRGHASH,com.sun.crypto.provider.GaloisCounterMode$AES256,com.sun.crypto.provider.GaloisCounterMode$AES192,com.sun.crypto.provider.GaloisCounterMode$AES128,com.sun.crypto.provider.GaloisCounterMode$AESGCM,com.sun.crypto.provider.GaloisCounterMode$GCMDecrypt,com.sun.crypto.provider.GaloisCounterMode$GCMEncrypt,com.sun.crypto.provider.GaloisCounterMode$GCMEngine"
};

$Object* allocate$GaloisCounterMode($Class* clazz) {
	return $of($alloc(GaloisCounterMode));
}

int32_t GaloisCounterMode::DEFAULT_IV_LEN = 0;
int32_t GaloisCounterMode::DEFAULT_TAG_LEN = 0;
$bytes* GaloisCounterMode::EMPTY_BUF = nullptr;
$VarHandle* GaloisCounterMode::wrapToByteArray = nullptr;

void GaloisCounterMode::init$(int32_t keySize, $SymmetricCipher* embeddedCipher) {
	$CipherSpi::init$();
	this->initialized = false;
	this->encryption = true;
	this->tagLenBytes = GaloisCounterMode::DEFAULT_TAG_LEN;
	this->reInit = false;
	$set(this, lastKey, GaloisCounterMode::EMPTY_BUF);
	$set(this, lastIv, GaloisCounterMode::EMPTY_BUF);
	$set(this, iv, nullptr);
	$set(this, random, nullptr);
	$set(this, blockCipher, embeddedCipher);
	this->keySize = keySize;
}

void GaloisCounterMode::init(int32_t opmode, $Key* key, $GCMParameterSpec* spec) {
	$useLocalCurrentObjectStackCache();
	this->encryption = (opmode == $Cipher::ENCRYPT_MODE) || (opmode == $Cipher::WRAP_MODE);
	int32_t tagLen = $nc(spec)->getTLen();
	if (tagLen < 96 || tagLen > 128 || (((int32_t)(tagLen & (uint32_t)7)) != 0)) {
		$throwNew($InvalidAlgorithmParameterException, "Unsupported TLen value.  Must be one of {128, 120, 112, 104, 96}"_s);
	}
	this->tagLenBytes = tagLen >> 3;
	if (key == nullptr) {
		$throwNew($InvalidKeyException, "The key must not be null"_s);
	}
	$var($bytes, keyValue, $nc(key)->getEncoded());
	if (keyValue == nullptr) {
		$throwNew($InvalidKeyException, "Key encoding must not be null"_s);
	} else if (this->keySize != -1 && $nc(keyValue)->length != this->keySize) {
		$Arrays::fill(keyValue, (int8_t)0);
		$throwNew($InvalidKeyException, $$str({"The key must be "_s, $$str(this->keySize), " bytes"_s}));
	}
	if (this->encryption) {
		bool var$0 = $MessageDigest::isEqual(keyValue, this->lastKey);
		if (var$0 && $MessageDigest::isEqual(this->iv, this->lastIv)) {
			$Arrays::fill(keyValue, (int8_t)0);
			$throwNew($InvalidAlgorithmParameterException, "Cannot reuse iv for GCM encryption"_s);
		}
		if (this->lastKey != nullptr) {
			$Arrays::fill(this->lastKey, (int8_t)0);
		}
		$set(this, lastKey, keyValue);
		$set(this, lastIv, this->iv);
	}
	this->reInit = false;
	{
		$var($Throwable, var$1, nullptr);
		try {
			$nc(this->blockCipher)->init(false, $(key->getAlgorithm()), keyValue);
		} catch ($Throwable& var$2) {
			$assign(var$1, var$2);
		} /*finally*/ {
			if (!this->encryption) {
				$Arrays::fill(keyValue, (int8_t)0);
			}
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
}

void GaloisCounterMode::engineSetMode($String* mode) {
	if (!$nc(mode)->equalsIgnoreCase("GCM"_s)) {
		$throwNew($NoSuchAlgorithmException, "Mode must be GCM"_s);
	}
}

void GaloisCounterMode::engineSetPadding($String* padding) {
	if (!$nc(padding)->equalsIgnoreCase("NoPadding"_s)) {
		$throwNew($NoSuchPaddingException, "Padding must be NoPadding"_s);
	}
}

int32_t GaloisCounterMode::engineGetBlockSize() {
	return $nc(this->blockCipher)->getBlockSize();
}

int32_t GaloisCounterMode::engineGetOutputSize(int32_t inputLen) {
	checkInit();
	return $nc(this->engine)->getOutputSize(inputLen, true);
}

int32_t GaloisCounterMode::engineGetKeySize($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $nc(key)->getEncoded());
	$Arrays::fill(encoded, (int8_t)0);
	if (!$AESCrypt::isKeySizeValid($nc(encoded)->length)) {
		$throwNew($InvalidKeyException, $$str({"Invalid key length: "_s, $$str($nc(encoded)->length), " bytes"_s}));
	}
	return $Math::multiplyExact($nc(encoded)->length, 8);
}

$bytes* GaloisCounterMode::engineGetIV() {
	if (this->iv == nullptr) {
		return nullptr;
	}
	return $cast($bytes, $nc(this->iv)->clone());
}

$bytes* GaloisCounterMode::createIv($SecureRandom* rand$renamed) {
	$init(GaloisCounterMode);
	$useLocalCurrentObjectStackCache();
	$var($SecureRandom, rand, rand$renamed);
	$var($bytes, iv, $new($bytes, GaloisCounterMode::DEFAULT_IV_LEN));
	if (rand == nullptr) {
		$assign(rand, $JCAUtil::getDefSecureRandom());
	}
	$nc(rand)->nextBytes(iv);
	return iv;
}

$AlgorithmParameters* GaloisCounterMode::engineGetParameters() {
	$useLocalCurrentObjectStackCache();
	$var($GCMParameterSpec, spec, nullptr);
	$assign(spec, $new($GCMParameterSpec, this->tagLenBytes * 8, this->iv == nullptr ? $(createIv(this->random)) : $cast($bytes, $($nc(this->iv)->clone()))));
	try {
		$var($AlgorithmParameters, params, $AlgorithmParameters::getInstance("GCM"_s, $(static_cast<$Provider*>($SunJCE::getInstance()))));
		$nc(params)->init(static_cast<$AlgorithmParameterSpec*>(spec));
		return params;
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($InvalidParameterSpecException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void GaloisCounterMode::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	$set(this, engine, nullptr);
	if (opmode == $Cipher::DECRYPT_MODE || opmode == $Cipher::UNWRAP_MODE) {
		$throwNew($InvalidKeyException, "No GCMParameterSpec specified"_s);
	}
	try {
		engineInit(opmode, key, ($AlgorithmParameterSpec*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& e) {
	}
}

void GaloisCounterMode::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$var($GCMParameterSpec, spec, nullptr);
	$set(this, random, random);
	$set(this, engine, nullptr);
	if (params == nullptr) {
		$set(this, iv, createIv(random));
		$assign(spec, $new($GCMParameterSpec, GaloisCounterMode::DEFAULT_TAG_LEN * 8, this->iv));
	} else {
		if (!($instanceOf($GCMParameterSpec, params))) {
			$throwNew($InvalidAlgorithmParameterException, "AlgorithmParameterSpec not of GCMParameterSpec"_s);
		}
		$assign(spec, $cast($GCMParameterSpec, params));
		$set(this, iv, $nc(spec)->getIV());
		if (this->iv == nullptr) {
			$throwNew($InvalidAlgorithmParameterException, "IV is null"_s);
		}
		if ($nc(this->iv)->length == 0) {
			$throwNew($InvalidAlgorithmParameterException, "IV is empty"_s);
		}
	}
	init(opmode, key, spec);
	this->initialized = true;
}

void GaloisCounterMode::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$var($GCMParameterSpec, spec, nullptr);
	$set(this, engine, nullptr);
	if (params != nullptr) {
		try {
			$load($GCMParameterSpec);
			$assign(spec, $cast($GCMParameterSpec, params->getParameterSpec($GCMParameterSpec::class$)));
		} catch ($InvalidParameterSpecException& e) {
			$throwNew($InvalidAlgorithmParameterException, static_cast<$Throwable*>(e));
		}
	}
	engineInit(opmode, key, static_cast<$AlgorithmParameterSpec*>(spec), random);
}

void GaloisCounterMode::checkInit() {
	if (!this->initialized) {
		$throwNew($IllegalStateException, "Operation not initialized."_s);
	}
	if (this->engine == nullptr) {
		if (this->encryption) {
			$set(this, engine, $new($GaloisCounterMode$GCMEncrypt, this, this->blockCipher));
		} else {
			$set(this, engine, $new($GaloisCounterMode$GCMDecrypt, this, this->blockCipher));
		}
	}
}

void GaloisCounterMode::checkReInit() {
	if (this->reInit) {
		$throwNew($IllegalStateException, "Must use either different key or  iv for GCM encryption"_s);
	}
}

$bytes* GaloisCounterMode::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen) {
	checkInit();
	$ArrayUtil::nullAndBoundsCheck(input, inputOffset, inputLen);
	return $nc(this->engine)->doUpdate(input, inputOffset, inputLen);
}

int32_t GaloisCounterMode::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	$useLocalCurrentObjectStackCache();
	checkInit();
	$ArrayUtil::nullAndBoundsCheck(input, inputOffset, inputLen);
	$ArrayUtil::nullAndBoundsCheck(output, outputOffset, $nc(output)->length - outputOffset);
	int32_t len = $nc(this->engine)->getOutputSize(inputLen, false);
	if (len > $nc(output)->length - outputOffset) {
		$throwNew($ShortBufferException, $$str({"Output buffer too small, must be at least "_s, $$str(len), " bytes long"_s}));
	}
	return $nc(this->engine)->doUpdate(input, inputOffset, inputLen, output, outputOffset);
}

int32_t GaloisCounterMode::engineUpdate($ByteBuffer* src, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	checkInit();
	int32_t len = $nc(this->engine)->getOutputSize($nc(src)->remaining(), false);
	if (len > $nc(dst)->remaining()) {
		$throwNew($ShortBufferException, $$str({"Output buffer must be at least "_s, $$str(len), " bytes long"_s}));
	}
	return $nc(this->engine)->doUpdate(src, dst);
}

void GaloisCounterMode::engineUpdateAAD($bytes* src, int32_t offset, int32_t len) {
	checkInit();
	$nc(this->engine)->updateAAD(src, offset, len);
}

void GaloisCounterMode::engineUpdateAAD($ByteBuffer* src) {
	$useLocalCurrentObjectStackCache();
	checkInit();
	if ($nc(src)->hasArray()) {
		int32_t pos = src->position();
		int32_t len = src->remaining();
		$var($bytes, var$0, $cast($bytes, src->array()));
		$nc(this->engine)->updateAAD(var$0, src->arrayOffset() + pos, len);
		src->position(pos + len);
	} else {
		$var($bytes, aad, $new($bytes, src->remaining()));
		src->get(aad);
		$nc(this->engine)->updateAAD(aad, 0, aad->length);
	}
}

$bytes* GaloisCounterMode::engineDoFinal($bytes* input$renamed, int32_t inputOffset, int32_t inputLen) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, input, input$renamed);
	if (input == nullptr) {
		$assign(input, GaloisCounterMode::EMPTY_BUF);
	}
	try {
		$ArrayUtil::nullAndBoundsCheck(input, inputOffset, inputLen);
	} catch ($ArrayIndexOutOfBoundsException& e) {
		$throwNew($IllegalBlockSizeException, "input array invalid"_s);
	}
	checkInit();
	$var($bytes, output, $new($bytes, $nc(this->engine)->getOutputSize(inputLen, true)));
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->engine)->doFinal(input, inputOffset, inputLen, output, 0);
			} catch ($ShortBufferException& e) {
				$throwNew($ProviderException, static_cast<$Throwable*>(e));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, engine, nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return output;
}

int32_t GaloisCounterMode::engineDoFinal($bytes* input$renamed, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	$var($bytes, input, input$renamed);
	if (input == nullptr) {
		$assign(input, GaloisCounterMode::EMPTY_BUF);
	}
	try {
		$ArrayUtil::nullAndBoundsCheck(input, inputOffset, inputLen);
	} catch ($ArrayIndexOutOfBoundsException& e) {
		$set(this, engine, nullptr);
		$throwNew($IllegalBlockSizeException, "input array invalid"_s);
	}
	checkInit();
	int32_t len = $nc(this->engine)->doFinal(input, inputOffset, inputLen, output, outputOffset);
	$set(this, engine, nullptr);
	return len;
}

int32_t GaloisCounterMode::engineDoFinal($ByteBuffer* src, $ByteBuffer* dst) {
	checkInit();
	int32_t len = $nc(this->engine)->doFinal(src, dst);
	$set(this, engine, nullptr);
	return len;
}

$bytes* GaloisCounterMode::engineWrap($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encodedKey, nullptr);
	checkInit();
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(encodedKey, $nc(key)->getEncoded());
				if ((encodedKey == nullptr) || ($nc(encodedKey)->length == 0)) {
					$throwNew($InvalidKeyException, "Cannot get an encoding of the key to be wrapped"_s);
				}
				$assign(var$2, engineDoFinal(encodedKey, 0, $nc(encodedKey)->length));
				return$1 = true;
				goto $finally;
			} catch ($BadPaddingException& e) {
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$set(this, engine, nullptr);
			if (encodedKey != nullptr) {
				$Arrays::fill(encodedKey, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return nullptr;
}

$Key* GaloisCounterMode::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$useLocalCurrentObjectStackCache();
	checkInit();
	$var($bytes, encodedKey, nullptr);
	try {
		$assign(encodedKey, engineDoFinal(wrappedKey, 0, $nc(wrappedKey)->length));
	} catch ($BadPaddingException& ePadding) {
		$throwNew($InvalidKeyException, "The wrapped key is not padded correctly"_s);
	} catch ($IllegalBlockSizeException& eBlockSize) {
		$throwNew($InvalidKeyException, "The wrapped key does not have the correct length"_s);
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($Key, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $ConstructKeys::constructKey(encodedKey, wrappedKeyAlgorithm, wrappedKeyType));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(encodedKey, (int8_t)0);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void GaloisCounterMode::increment32($bytes* value) {
	$init(GaloisCounterMode);
	int32_t n = $nc(value)->length - 1;
	while (true) {
		bool var$0 = (n >= value->length - 4);
		if (!(var$0 && (++(*value)[n] == 0))) {
			break;
		}
		{
			--n;
		}
	}
}

$bytes* GaloisCounterMode::getLengthBlock(int32_t ivLenInBytes) {
	$init(GaloisCounterMode);
	$useLocalCurrentObjectStackCache();
	$var($bytes, out, $new($bytes, 16));
	$nc(GaloisCounterMode::wrapToByteArray)->set($$new($ObjectArray, {$of(out), $$of(8), $$of((((int64_t)((int64_t)ivLenInBytes & (uint64_t)(int64_t)0x00000000FFFFFFFF)) << 3))}));
	return out;
}

$bytes* GaloisCounterMode::getLengthBlock(int32_t aLenInBytes, int32_t cLenInBytes) {
	$init(GaloisCounterMode);
	$useLocalCurrentObjectStackCache();
	$var($bytes, out, $new($bytes, 16));
	$nc(GaloisCounterMode::wrapToByteArray)->set($$new($ObjectArray, {$of(out), $$of(0), $$of((((int64_t)((int64_t)aLenInBytes & (uint64_t)(int64_t)0x00000000FFFFFFFF)) << 3))}));
	$nc(GaloisCounterMode::wrapToByteArray)->set($$new($ObjectArray, {$of(out), $$of(8), $$of((((int64_t)((int64_t)cLenInBytes & (uint64_t)(int64_t)0x00000000FFFFFFFF)) << 3))}));
	return out;
}

$bytes* GaloisCounterMode::expandToOneBlock($bytes* in, int32_t inOfs, int32_t len, int32_t blockSize) {
	$init(GaloisCounterMode);
	$useLocalCurrentObjectStackCache();
	if (len > blockSize) {
		$throwNew($ProviderException, $$str({"input "_s, $$str(len), " too long"_s}));
	}
	if (len == blockSize && inOfs == 0) {
		return in;
	} else {
		$var($bytes, paddedIn, $new($bytes, blockSize));
		$System::arraycopy(in, inOfs, paddedIn, 0, len);
		return paddedIn;
	}
}

$bytes* GaloisCounterMode::getJ0($bytes* iv, $bytes* subkeyH, int32_t blockSize) {
	$init(GaloisCounterMode);
	$useLocalCurrentObjectStackCache();
	$var($bytes, j0, nullptr);
	if ($nc(iv)->length == 12) {
		$assign(j0, expandToOneBlock(iv, 0, iv->length, blockSize));
		$nc(j0)->set(blockSize - 1, (int8_t)1);
	} else {
		$var($GHASH, g, $new($GHASH, subkeyH));
		int32_t lastLen = $mod(iv->length, blockSize);
		if (lastLen != 0) {
			g->update(iv, 0, iv->length - lastLen);
			$var($bytes, padded, expandToOneBlock(iv, iv->length - lastLen, lastLen, blockSize));
			g->update(padded);
		} else {
			g->update(iv);
		}
		g->update($(getLengthBlock(iv->length)));
		$assign(j0, g->digest());
	}
	return j0;
}

void GaloisCounterMode::checkDataLength($ints* lengths) {
	$useLocalCurrentObjectStackCache();
	int32_t max = GaloisCounterMode::MAX_BUF_SIZE;
	{
		$var($ints, arr$, lengths);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t len = arr$->get(i$);
			{
				max = $Math::subtractExact(max, len);
			}
		}
	}
	if ($nc(this->engine)->processed > max) {
		$throwNew($ProviderException, $$str({"SunJCE provider only supports input size up to "_s, $$str(GaloisCounterMode::MAX_BUF_SIZE), " bytes"_s}));
	}
}

void clinit$GaloisCounterMode($Class* class$) {
	GaloisCounterMode::DEFAULT_IV_LEN = 12;
	GaloisCounterMode::DEFAULT_TAG_LEN = 16;
	$assignStatic(GaloisCounterMode::EMPTY_BUF, $new($bytes, 0));
	$load($longs);
	$init($ByteOrder);
	$assignStatic(GaloisCounterMode::wrapToByteArray, $MethodHandles::byteArrayViewVarHandle($getClass($longs), $ByteOrder::BIG_ENDIAN));
}

GaloisCounterMode::GaloisCounterMode() {
}

$Class* GaloisCounterMode::load$($String* name, bool initialize) {
	$loadClass(GaloisCounterMode, name, initialize, &_GaloisCounterMode_ClassInfo_, clinit$GaloisCounterMode, allocate$GaloisCounterMode);
	return class$;
}

$Class* GaloisCounterMode::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com