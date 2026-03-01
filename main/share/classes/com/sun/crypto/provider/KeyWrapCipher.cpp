#include <com/sun/crypto/provider/KeyWrapCipher.h>

#include <com/sun/crypto/provider/AESCrypt.h>
#include <com/sun/crypto/provider/AESKeyWrap.h>
#include <com/sun/crypto/provider/AESKeyWrapPadded.h>
#include <com/sun/crypto/provider/ConstructKeys.h>
#include <com/sun/crypto/provider/FeedbackCipher.h>
#include <com/sun/crypto/provider/PKCS5Padding.h>
#include <com/sun/crypto/provider/Padding.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
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
#include <javax/crypto/spec/IvParameterSpec.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef ENCRYPT_MODE
#undef ICV1
#undef ICV2
#undef MAX_VALUE
#undef UNWRAP_MODE
#undef WRAP_MODE

using $AESCrypt = ::com::sun::crypto::provider::AESCrypt;
using $AESKeyWrap = ::com::sun::crypto::provider::AESKeyWrap;
using $AESKeyWrapPadded = ::com::sun::crypto::provider::AESKeyWrapPadded;
using $ConstructKeys = ::com::sun::crypto::provider::ConstructKeys;
using $FeedbackCipher = ::com::sun::crypto::provider::FeedbackCipher;
using $PKCS5Padding = ::com::sun::crypto::provider::PKCS5Padding;
using $Padding = ::com::sun::crypto::provider::Padding;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
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
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _KeyWrapCipher_FieldInfo_[] = {
	{"cipher", "Lcom/sun/crypto/provider/FeedbackCipher;", nullptr, $PRIVATE | $FINAL, $field(KeyWrapCipher, cipher)},
	{"padding", "Lcom/sun/crypto/provider/Padding;", nullptr, $PRIVATE | $FINAL, $field(KeyWrapCipher, padding)},
	{"opmode", "I", nullptr, $PRIVATE, $field(KeyWrapCipher, opmode)},
	{"fixedKeySize", "I", nullptr, $PRIVATE | $FINAL, $field(KeyWrapCipher, fixedKeySize)},
	{"dataBuf", "[B", nullptr, $PRIVATE, $field(KeyWrapCipher, dataBuf)},
	{"dataIdx", "I", nullptr, $PRIVATE, $field(KeyWrapCipher, dataIdx)},
	{}
};

$MethodInfo _KeyWrapCipher_MethodInfo_[] = {
	{"<init>", "(Lcom/sun/crypto/provider/FeedbackCipher;Lcom/sun/crypto/provider/Padding;I)V", nullptr, $PUBLIC, $method(KeyWrapCipher, init$, void, $FeedbackCipher*, $Padding*, int32_t)},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(KeyWrapCipher, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{"helperDecrypt", "([BI)I", nullptr, $PRIVATE, $method(KeyWrapCipher, helperDecrypt, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException,javax.crypto.ShortBufferException"},
	{"helperEncrypt", "([BI)I", nullptr, $PRIVATE, $method(KeyWrapCipher, helperEncrypt, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException"},
	{"implDoFinal", "([BII[B)I", nullptr, $PRIVATE, $method(KeyWrapCipher, implDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException,javax.crypto.ShortBufferException"},
	{"implInit", "(ILjava/security/Key;[BLjava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(KeyWrapCipher, implInit, void, int32_t, $Key*, $bytes*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"implUpdate", "([BII)V", nullptr, $PRIVATE, $method(KeyWrapCipher, implUpdate, void, $bytes*, int32_t, int32_t)},
	{"store", "([BII)V", nullptr, $PRIVATE, $method(KeyWrapCipher, store, void, $bytes*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _KeyWrapCipher_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.KeyWrapCipher$AES256_KWP_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES256_KWP_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES192_KWP_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES192_KWP_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES128_KWP_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES128_KWP_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES_KWP_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES_KWP_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES256_KW_PKCS5Padding", "com.sun.crypto.provider.KeyWrapCipher", "AES256_KW_PKCS5Padding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES192_KW_PKCS5Padding", "com.sun.crypto.provider.KeyWrapCipher", "AES192_KW_PKCS5Padding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES128_KW_PKCS5Padding", "com.sun.crypto.provider.KeyWrapCipher", "AES128_KW_PKCS5Padding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES_KW_PKCS5Padding", "com.sun.crypto.provider.KeyWrapCipher", "AES_KW_PKCS5Padding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES256_KW_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES256_KW_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES192_KW_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES192_KW_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES128_KW_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES128_KW_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.KeyWrapCipher$AES_KW_NoPadding", "com.sun.crypto.provider.KeyWrapCipher", "AES_KW_NoPadding", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _KeyWrapCipher_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"com.sun.crypto.provider.KeyWrapCipher",
	"javax.crypto.CipherSpi",
	nullptr,
	_KeyWrapCipher_FieldInfo_,
	_KeyWrapCipher_MethodInfo_,
	nullptr,
	nullptr,
	_KeyWrapCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.KeyWrapCipher$AES256_KWP_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES192_KWP_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES128_KWP_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES_KWP_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES256_KW_PKCS5Padding,com.sun.crypto.provider.KeyWrapCipher$AES192_KW_PKCS5Padding,com.sun.crypto.provider.KeyWrapCipher$AES128_KW_PKCS5Padding,com.sun.crypto.provider.KeyWrapCipher$AES_KW_PKCS5Padding,com.sun.crypto.provider.KeyWrapCipher$AES256_KW_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES192_KW_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES128_KW_NoPadding,com.sun.crypto.provider.KeyWrapCipher$AES_KW_NoPadding"
};

$Object* allocate$KeyWrapCipher($Class* clazz) {
	return $of($alloc(KeyWrapCipher));
}

void KeyWrapCipher::store($bytes* in, int32_t inOfs, int32_t inLen) {
	$useLocalCurrentObjectStackCache();
	int32_t remain = $Integer::MAX_VALUE - this->dataIdx;
	if (inLen > remain) {
		$throwNew($ProviderException, $$str({"SunJCE provider can only take "_s, $$str(remain), " more bytes"_s}));
	}
	if (this->dataBuf == nullptr || $nc(this->dataBuf)->length - this->dataIdx < inLen) {
		int32_t newSize = $Math::addExact(this->dataIdx, inLen);
		int32_t lastBlk = (this->dataIdx + inLen - 8) % 16;
		if (lastBlk != 0 || this->padding != nullptr) {
			newSize = $Math::addExact(newSize, 16 - lastBlk);
		}
		$var($bytes, temp, $new($bytes, newSize));
		if (this->dataBuf != nullptr && this->dataIdx > 0) {
			$System::arraycopy(this->dataBuf, 0, temp, 0, this->dataIdx);
		}
		$set(this, dataBuf, temp);
	}
	if (in != nullptr) {
		$System::arraycopy(in, inOfs, this->dataBuf, this->dataIdx, inLen);
		this->dataIdx += inLen;
	}
}

void KeyWrapCipher::init$($FeedbackCipher* cipher, $Padding* padding, int32_t keySize) {
	$CipherSpi::init$();
	this->opmode = -1;
	$set(this, cipher, cipher);
	$set(this, padding, padding);
	this->fixedKeySize = keySize;
	$set(this, dataBuf, nullptr);
	this->dataIdx = 0;
}

void KeyWrapCipher::engineSetMode($String* mode) {
	$useLocalCurrentObjectStackCache();
	if (mode != nullptr && !$nc($($nc(this->cipher)->getFeedback()))->equalsIgnoreCase(mode)) {
		$throwNew($NoSuchAlgorithmException, $$str({mode, " cannot be used"_s}));
	}
}

void KeyWrapCipher::engineSetPadding($String* padding) {
	bool var$0 = (this->padding == nullptr && !"NoPadding"_s->equalsIgnoreCase(padding));
	if (var$0 || $instanceOf($PKCS5Padding, this->padding) && !"PKCS5Padding"_s->equalsIgnoreCase(padding)) {
		$throwNew($NoSuchPaddingException, $$str({"Unsupported padding "_s, padding}));
	}
}

int32_t KeyWrapCipher::engineGetBlockSize() {
	return $nc(this->cipher)->getBlockSize();
}

int32_t KeyWrapCipher::engineGetOutputSize(int32_t inLen) {
	int32_t result = 0;
	if (this->opmode == $Cipher::ENCRYPT_MODE || this->opmode == $Cipher::WRAP_MODE) {
		result = (this->dataIdx > 0 ? $Math::addExact(inLen, this->dataIdx - 8) : inLen);
		int32_t padLen = 0;
		if (this->padding != nullptr) {
			padLen = $nc(this->padding)->padLength(result);
		} else if ($instanceOf($AESKeyWrapPadded, this->cipher)) {
			int32_t n = result % 8;
			if (n != 0) {
				padLen = 8 - n;
			}
		}
		result = $Math::addExact(result, 8 + padLen);
	} else {
		result = inLen - 8;
		if (this->dataIdx > 0) {
			result = $Math::addExact(result, this->dataIdx);
		}
	}
	return result;
}

$bytes* KeyWrapCipher::engineGetIV() {
	$var($bytes, iv, $nc(this->cipher)->getIV());
	return (iv == nullptr ? ($bytes*)nullptr : $cast($bytes, $nc(iv)->clone()));
}

void KeyWrapCipher::implInit(int32_t opmode, $Key* key, $bytes* iv, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, keyBytes, $nc(key)->getEncoded());
	if (keyBytes == nullptr) {
		$throwNew($InvalidKeyException, "Null key"_s);
	}
	this->opmode = opmode;
	bool decrypting = (opmode == $Cipher::DECRYPT_MODE || opmode == $Cipher::UNWRAP_MODE);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->cipher)->init(decrypting, $(key->getAlgorithm()), keyBytes, iv);
			$set(this, dataBuf, nullptr);
			this->dataIdx = 0;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$Arrays::fill(keyBytes, (int8_t)0);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void KeyWrapCipher::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		implInit(opmode, key, ($bytes*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& iae) {
		$throwNew($AssertionError, $of(iae));
	}
}

void KeyWrapCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	if (params != nullptr && !($instanceOf($IvParameterSpec, params))) {
		$throwNew($InvalidAlgorithmParameterException, "Only IvParameterSpec is accepted"_s);
	}
	$var($bytes, iv, params == nullptr ? ($bytes*)nullptr : $nc(($cast($IvParameterSpec, params)))->getIV());
	implInit(opmode, key, iv, random);
}

void KeyWrapCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, iv, nullptr);
	if (params != nullptr) {
		try {
			$load($IvParameterSpec);
			$var($AlgorithmParameterSpec, spec, params->getParameterSpec($IvParameterSpec::class$));
			$assign(iv, $nc(($cast($IvParameterSpec, spec)))->getIV());
		} catch ($InvalidParameterSpecException& ispe) {
			$throwNew($InvalidAlgorithmParameterException, "Only IvParameterSpec is accepted"_s);
		}
	}
	try {
		implInit(opmode, key, iv, random);
	} catch ($IllegalArgumentException& iae) {
		$throwNew($InvalidAlgorithmParameterException, $(iae->getMessage()));
	}
}

$bytes* KeyWrapCipher::engineUpdate($bytes* in, int32_t inOffset, int32_t inLen) {
	if (this->opmode != $Cipher::ENCRYPT_MODE && this->opmode != $Cipher::DECRYPT_MODE) {
		$throwNew($IllegalStateException, "Cipher not initialized for update"_s);
	}
	implUpdate(in, inOffset, inLen);
	return nullptr;
}

int32_t KeyWrapCipher::engineUpdate($bytes* in, int32_t inOffset, int32_t inLen, $bytes* out, int32_t outOffset) {
	if (this->opmode != $Cipher::ENCRYPT_MODE && this->opmode != $Cipher::DECRYPT_MODE) {
		$throwNew($IllegalStateException, "Cipher not initialized for update"_s);
	}
	implUpdate(in, inOffset, inLen);
	return 0;
}

void KeyWrapCipher::implUpdate($bytes* in, int32_t inOfs, int32_t inLen) {
	if (inLen <= 0) {
		return;
	}
	if (this->opmode == $Cipher::ENCRYPT_MODE && this->dataIdx == 0) {
		this->dataIdx = 8;
	}
	store(in, inOfs, inLen);
}

$bytes* KeyWrapCipher::engineDoFinal($bytes* in, int32_t inOfs, int32_t inLen) {
	$useLocalCurrentObjectStackCache();
	int32_t estOutLen = engineGetOutputSize(inLen);
	$var($bytes, out, $new($bytes, estOutLen));
	try {
		int32_t outLen = engineDoFinal(in, inOfs, inLen, out, 0);
		if (outLen < estOutLen) {
			{
				$var($Throwable, var$0, nullptr);
				$var($bytes, var$2, nullptr);
				bool return$1 = false;
				try {
					$assign(var$2, $Arrays::copyOf(out, outLen));
					return$1 = true;
					goto $finally;
				} catch ($Throwable& var$3) {
					$assign(var$0, var$3);
				} $finally: {
					$Arrays::fill(out, (int8_t)0);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
				if (return$1) {
					return var$2;
				}
			}
		} else {
			return out;
		}
	} catch ($ShortBufferException& sbe) {
		$throwNew($AssertionError, $of(sbe));
	}
	$shouldNotReachHere();
}

int32_t KeyWrapCipher::engineDoFinal($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out, int32_t outOfs) {
	$useLocalCurrentObjectStackCache();
	if (this->opmode != $Cipher::ENCRYPT_MODE && this->opmode != $Cipher::DECRYPT_MODE) {
		$throwNew($IllegalStateException, "Cipher not initialized for doFinal"_s);
	}
	int32_t estOutLen = engineGetOutputSize(inLen);
	if ($nc(out)->length - outOfs < estOutLen) {
		$throwNew($ShortBufferException, $$str({"Need at least "_s, $$str(estOutLen)}));
	}
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			if (outOfs == 0 && this->opmode == $Cipher::ENCRYPT_MODE) {
				var$2 = implDoFinal(in, inOfs, inLen, out);
				return$1 = true;
				goto $finally;
			} else {
				store(nullptr, 0, inLen);
				int32_t outLen = implDoFinal(in, inOfs, inLen, this->dataBuf);
				if (outLen > estOutLen) {
					$throwNew($AssertionError, $of("Actual output length exceeds estimated length"_s));
				}
				$System::arraycopy(this->dataBuf, 0, out, outOfs, outLen);
				var$2 = outLen;
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (this->dataBuf != nullptr) {
				$Arrays::fill(this->dataBuf, (int8_t)0);
			}
			$set(this, dataBuf, nullptr);
			this->dataIdx = 0;
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

int32_t KeyWrapCipher::implDoFinal($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out) {
	int32_t len = (out == this->dataBuf ? this->dataIdx : 0);
	if (out != this->dataBuf && this->dataIdx > 0) {
		$System::arraycopy(this->dataBuf, 0, out, 0, this->dataIdx);
		len = this->dataIdx;
	}
	if (this->opmode == $Cipher::ENCRYPT_MODE && len == 0) {
		len = 8;
	}
	if (inLen > 0) {
		$System::arraycopy(in, inOfs, out, len, inLen);
		len += inLen;
	}
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			var$2 = (this->opmode == $Cipher::ENCRYPT_MODE ? helperEncrypt(out, len) : helperDecrypt(out, len));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (this->dataBuf != nullptr && this->dataBuf != out) {
				$Arrays::fill(this->dataBuf, (int8_t)0);
			}
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

int32_t KeyWrapCipher::helperEncrypt($bytes* inBuf, int32_t inLen) {
	if (this->padding != nullptr) {
		int32_t paddingLen = $nc(this->padding)->padLength(inLen - 8);
		if (inLen + paddingLen > $nc(inBuf)->length) {
			$throwNew($AssertionError, $of("encrypt buffer too small"_s));
		}
		try {
			$nc(this->padding)->padWithLen(inBuf, inLen, paddingLen);
			inLen += paddingLen;
		} catch ($ShortBufferException& sbe) {
			$throwNew($AssertionError, $of(sbe));
		}
	}
	return $nc(this->cipher)->encryptFinal(inBuf, 0, inLen, nullptr, 0);
}

int32_t KeyWrapCipher::helperDecrypt($bytes* inBuf, int32_t inLen) {
	$useLocalCurrentObjectStackCache();
	int32_t outLen = $nc(this->cipher)->decryptFinal(inBuf, 0, inLen, nullptr, 0);
	if (this->padding != nullptr) {
		int32_t padIdx = $nc(this->padding)->unpad(inBuf, 0, outLen);
		if (padIdx <= 0) {
			$throwNew($BadPaddingException, $$str({"Bad Padding: "_s, $$str(padIdx)}));
		}
		outLen = padIdx;
	}
	return outLen;
}

$AlgorithmParameters* KeyWrapCipher::engineGetParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, params, nullptr);
	$var($bytes, iv, $nc(this->cipher)->getIV());
	if (iv == nullptr) {
		$init($AESKeyWrap);
		$init($AESKeyWrapPadded);
		$assign(iv, $instanceOf($AESKeyWrap, this->cipher) ? $AESKeyWrap::ICV1 : $AESKeyWrapPadded::ICV2);
	}
	try {
		$assign(params, $AlgorithmParameters::getInstance("AES"_s));
		$nc(params)->init(static_cast<$AlgorithmParameterSpec*>($$new($IvParameterSpec, iv)));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($AssertionError);
	} catch ($InvalidParameterSpecException& e) {
		$throwNew($AssertionError);
	}
	return params;
}

int32_t KeyWrapCipher::engineGetKeySize($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $nc(key)->getEncoded());
	if (encoded == nullptr) {
		$throwNew($InvalidKeyException, "Cannot decide key length"_s);
	}
	$Arrays::fill(encoded, (int8_t)0);
	int32_t keyLen = $nc(encoded)->length;
	bool var$0 = !$nc($(key->getAlgorithm()))->equalsIgnoreCase("AES"_s);
	if (var$0 || !$AESCrypt::isKeySizeValid(keyLen) || (this->fixedKeySize != -1 && this->fixedKeySize != keyLen)) {
		$throwNew($InvalidKeyException, $$str({"Invalid key length: "_s, $$str(keyLen), " bytes"_s}));
	}
	return $Math::multiplyExact(keyLen, 8);
}

$bytes* KeyWrapCipher::engineWrap($Key* key) {
	$useLocalCurrentObjectStackCache();
	if (this->opmode != $Cipher::WRAP_MODE) {
		$throwNew($IllegalStateException, "Cipher not initialized for wrap"_s);
	}
	$var($bytes, encoded, $nc(key)->getEncoded());
	if ((encoded == nullptr) || ($nc(encoded)->length == 0)) {
		$throwNew($InvalidKeyException, "Cannot get an encoding of the key to be wrapped"_s);
	}
	$var($bytes, out, $new($bytes, engineGetOutputSize($nc(encoded)->length)));
	int32_t len = 8;
	$System::arraycopy(encoded, 0, out, len, $nc(encoded)->length);
	len += $nc(encoded)->length;
	$Arrays::fill(encoded, (int8_t)0);
	try {
		int32_t outLen = helperEncrypt(out, len);
		if (outLen != out->length) {
			$throwNew($AssertionError, $of("Wrong output buffer size"_s));
		}
		return out;
	} catch ($ShortBufferException& sbe) {
		$throwNew($AssertionError);
	}
	$shouldNotReachHere();
}

$Key* KeyWrapCipher::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$useLocalCurrentObjectStackCache();
	if (this->opmode != $Cipher::UNWRAP_MODE) {
		$throwNew($IllegalStateException, "Cipher not initialized for unwrap"_s);
	}
	$var($bytes, buf, $cast($bytes, $nc(wrappedKey)->clone()));
	{
		$var($Throwable, var$0, nullptr);
		$var($Key, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				int32_t outLen = helperDecrypt(buf, buf->length);
				$assign(var$2, $ConstructKeys::constructKey(buf, 0, outLen, wrappedKeyAlgorithm, wrappedKeyType));
				return$1 = true;
				goto $finally;
			} catch ($ShortBufferException& sbe) {
				$throwNew($AssertionError);
			} catch ($IllegalBlockSizeException& e) {
				$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
			} catch ($BadPaddingException& e) {
				$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(buf, (int8_t)0);
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

KeyWrapCipher::KeyWrapCipher() {
}

$Class* KeyWrapCipher::load$($String* name, bool initialize) {
	$loadClass(KeyWrapCipher, name, initialize, &_KeyWrapCipher_ClassInfo_, allocate$KeyWrapCipher);
	return class$;
}

$Class* KeyWrapCipher::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com