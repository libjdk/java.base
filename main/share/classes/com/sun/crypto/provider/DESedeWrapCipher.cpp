#include <com/sun/crypto/provider/DESedeWrapCipher.h>

#include <com/sun/crypto/provider/CipherBlockChaining.h>
#include <com/sun/crypto/provider/ConstructKeys.h>
#include <com/sun/crypto/provider/DESConstants.h>
#include <com/sun/crypto/provider/DESedeCrypt.h>
#include <com/sun/crypto/provider/DESedeParameters.h>
#include <com/sun/crypto/provider/FeedbackCipher.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/CipherSpi.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <jcpp.h>

#undef CHECKSUM_LEN
#undef DES_BLOCK_SIZE
#undef IV2
#undef IV_LEN
#undef UNWRAP_MODE
#undef WRAP_MODE

using $CipherBlockChaining = ::com::sun::crypto::provider::CipherBlockChaining;
using $ConstructKeys = ::com::sun::crypto::provider::ConstructKeys;
using $DESConstants = ::com::sun::crypto::provider::DESConstants;
using $DESedeCrypt = ::com::sun::crypto::provider::DESedeCrypt;
using $DESedeParameters = ::com::sun::crypto::provider::DESedeParameters;
using $FeedbackCipher = ::com::sun::crypto::provider::FeedbackCipher;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $CipherSpi = ::javax::crypto::CipherSpi;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _DESedeWrapCipher_FieldInfo_[] = {
	{"IV2", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DESedeWrapCipher, IV2)},
	{"CHECKSUM_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DESedeWrapCipher, CHECKSUM_LEN)},
	{"IV_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DESedeWrapCipher, IV_LEN)},
	{"cipher", "Lcom/sun/crypto/provider/FeedbackCipher;", nullptr, $PRIVATE, $field(DESedeWrapCipher, cipher)},
	{"iv", "[B", nullptr, $PRIVATE, $field(DESedeWrapCipher, iv)},
	{"cipherKey", "Ljava/security/Key;", nullptr, $PRIVATE, $field(DESedeWrapCipher, cipherKey)},
	{"decrypting", "Z", nullptr, $PRIVATE, $field(DESedeWrapCipher, decrypting)},
	{}
};

$MethodInfo _DESedeWrapCipher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DESedeWrapCipher, init$, void)},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(DESedeWrapCipher, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{"getChecksum", "([B)[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(DESedeWrapCipher, getChecksum, $bytes*, $bytes*)},
	{"getChecksum", "([BII)[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(DESedeWrapCipher, getChecksum, $bytes*, $bytes*, int32_t, int32_t)},
	{}
};

$ClassInfo _DESedeWrapCipher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.DESedeWrapCipher",
	"javax.crypto.CipherSpi",
	nullptr,
	_DESedeWrapCipher_FieldInfo_,
	_DESedeWrapCipher_MethodInfo_
};

$Object* allocate$DESedeWrapCipher($Class* clazz) {
	return $of($alloc(DESedeWrapCipher));
}

$bytes* DESedeWrapCipher::IV2 = nullptr;

void DESedeWrapCipher::init$() {
	$CipherSpi::init$();
	$set(this, iv, nullptr);
	$set(this, cipherKey, nullptr);
	this->decrypting = false;
	$set(this, cipher, $new($CipherBlockChaining, $$new($DESedeCrypt)));
}

void DESedeWrapCipher::engineSetMode($String* mode) {
	if (!$nc(mode)->equalsIgnoreCase("CBC"_s)) {
		$throwNew($NoSuchAlgorithmException, $$str({mode, " cannot be used"_s}));
	}
}

void DESedeWrapCipher::engineSetPadding($String* padding) {
	if (!$nc(padding)->equalsIgnoreCase("NoPadding"_s)) {
		$throwNew($NoSuchPaddingException, $$str({padding, " cannot be used"_s}));
	}
}

int32_t DESedeWrapCipher::engineGetBlockSize() {
	return $DESConstants::DES_BLOCK_SIZE;
}

int32_t DESedeWrapCipher::engineGetOutputSize(int32_t inputLen) {
	int32_t result = 0;
	if (this->decrypting) {
		result = inputLen - 16;
	} else {
		result = $Math::addExact(inputLen, 16);
	}
	return (result < 0 ? 0 : result);
}

$bytes* DESedeWrapCipher::engineGetIV() {
	return (this->iv == nullptr) ? ($bytes*)nullptr : $cast($bytes, $nc(this->iv)->clone());
}

void DESedeWrapCipher::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		engineInit(opmode, key, ($AlgorithmParameterSpec*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& iape) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, "Parameters required"_s));
		ike->initCause(iape);
		$throw(ike);
	}
}

void DESedeWrapCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($SecureRandom, random, random$renamed);
	$var($bytes, currIv, nullptr);
	if (opmode == $Cipher::WRAP_MODE) {
		this->decrypting = false;
		if (params == nullptr) {
			$set(this, iv, $new($bytes, DESedeWrapCipher::IV_LEN));
			if (random == nullptr) {
				$assign(random, $SunJCE::getRandom());
			}
			$nc(random)->nextBytes(this->iv);
		} else if ($instanceOf($IvParameterSpec, params)) {
			$set(this, iv, $nc(($cast($IvParameterSpec, params)))->getIV());
		} else {
			$throwNew($InvalidAlgorithmParameterException, "Wrong parameter type: IV expected"_s);
		}
		$assign(currIv, this->iv);
	} else if (opmode == $Cipher::UNWRAP_MODE) {
		if (params != nullptr) {
			$throwNew($InvalidAlgorithmParameterException, "No parameter accepted for unwrapping keys"_s);
		}
		$set(this, iv, nullptr);
		this->decrypting = true;
		$assign(currIv, DESedeWrapCipher::IV2);
	} else {
		$throwNew($UnsupportedOperationException, "This cipher can only be used for key wrapping and unwrapping"_s);
	}
	$var($bytes, encoded, $nc(key)->getEncoded());
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->cipher)->init(this->decrypting, $(key->getAlgorithm()), encoded, currIv);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (encoded != nullptr) {
				$Arrays::fill(encoded, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$set(this, cipherKey, key);
}

void DESedeWrapCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$var($IvParameterSpec, ivSpec, nullptr);
	if (params != nullptr) {
		try {
			$var($DESedeParameters, paramsEng, $new($DESedeParameters));
			paramsEng->engineInit($(params->getEncoded()));
			$load($IvParameterSpec);
			$assign(ivSpec, $cast($IvParameterSpec, paramsEng->engineGetParameterSpec($IvParameterSpec::class$)));
		} catch ($Exception& ex) {
			$var($InvalidAlgorithmParameterException, iape, $new($InvalidAlgorithmParameterException, "Wrong parameter type: IV expected"_s));
			iape->initCause(ex);
			$throw(iape);
		}
	}
	engineInit(opmode, key, static_cast<$AlgorithmParameterSpec*>(ivSpec), random);
}

$bytes* DESedeWrapCipher::engineUpdate($bytes* in, int32_t inOffset, int32_t inLen) {
	$throwNew($IllegalStateException, "Cipher has not been initialized"_s);
	$shouldNotReachHere();
}

int32_t DESedeWrapCipher::engineUpdate($bytes* in, int32_t inOffset, int32_t inLen, $bytes* out, int32_t outOffset) {
	$throwNew($IllegalStateException, "Cipher has not been initialized"_s);
	$shouldNotReachHere();
}

$bytes* DESedeWrapCipher::engineDoFinal($bytes* in, int32_t inOffset, int32_t inLen) {
	$throwNew($IllegalStateException, "Cipher has not been initialized"_s);
	$shouldNotReachHere();
}

int32_t DESedeWrapCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	$throwNew($IllegalStateException, "Cipher has not been initialized"_s);
	$shouldNotReachHere();
}

$AlgorithmParameters* DESedeWrapCipher::engineGetParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, params, nullptr);
	if (this->iv != nullptr) {
		$var($String, algo, $nc(this->cipherKey)->getAlgorithm());
		try {
			$assign(params, $AlgorithmParameters::getInstance(algo, $(static_cast<$Provider*>($SunJCE::getInstance()))));
			$nc(params)->init(static_cast<$AlgorithmParameterSpec*>($$new($IvParameterSpec, this->iv)));
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($RuntimeException, $$str({"Cannot find "_s, algo, " AlgorithmParameters implementation in SunJCE provider"_s}));
		} catch ($InvalidParameterSpecException& ipse) {
			$throwNew($RuntimeException, "IvParameterSpec not supported"_s);
		}
	}
	return params;
}

int32_t DESedeWrapCipher::engineGetKeySize($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $nc(key)->getEncoded());
	$Arrays::fill(encoded, (int8_t)0);
	if ($nc(encoded)->length != 24) {
		$throwNew($InvalidKeyException, $$str({"Invalid key length: "_s, $$str(encoded->length), " bytes"_s}));
	}
	return 112;
}

$bytes* DESedeWrapCipher::engineWrap($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, keyVal, $nc(key)->getEncoded());
	if ((keyVal == nullptr) || ($nc(keyVal)->length == 0)) {
		$throwNew($InvalidKeyException, "Cannot get an encoding of the key to be wrapped"_s);
	}
	$var($bytes, in, $new($bytes, $Math::addExact($nc(keyVal)->length, DESedeWrapCipher::CHECKSUM_LEN)));
	$var($bytes, cipherKeyEncoded, $nc(this->cipherKey)->getEncoded());
	$var($bytes, out, $new($bytes, $Math::addExact($nc(this->iv)->length, in->length)));
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($bytes, cks, getChecksum(keyVal));
			$System::arraycopy(keyVal, 0, in, 0, $nc(keyVal)->length);
			$System::arraycopy(cks, 0, in, $nc(keyVal)->length, DESedeWrapCipher::CHECKSUM_LEN);
			$System::arraycopy(this->iv, 0, out, 0, $nc(this->iv)->length);
			$nc(this->cipher)->encrypt(in, 0, in->length, out, $nc(this->iv)->length);
			for (int32_t i = 0; i < out->length / 2; ++i) {
				int8_t temp = out->get(i);
				out->set(i, out->get(out->length - 1 - i));
				out->set(out->length - 1 - i, temp);
			}
			try {
				$nc(this->cipher)->init(false, $($nc(this->cipherKey)->getAlgorithm()), cipherKeyEncoded, DESedeWrapCipher::IV2);
			} catch ($InvalidKeyException& ike) {
				$throwNew($RuntimeException, "Internal cipher key is corrupted"_s);
			} catch ($InvalidAlgorithmParameterException& iape) {
				$throwNew($RuntimeException, "Internal cipher IV is invalid"_s);
			}
			$var($bytes, out2, $new($bytes, out->length));
			$nc(this->cipher)->encrypt(out, 0, out->length, out2, 0);
			try {
				$nc(this->cipher)->init(this->decrypting, $($nc(this->cipherKey)->getAlgorithm()), cipherKeyEncoded, this->iv);
			} catch ($InvalidKeyException& ike) {
				$throwNew($RuntimeException, "Internal cipher key is corrupted"_s);
			} catch ($InvalidAlgorithmParameterException& iape) {
				$throwNew($RuntimeException, "Internal cipher IV is invalid"_s);
			}
			$assign(var$2, out2);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(keyVal, (int8_t)0);
			$Arrays::fill(in, (int8_t)0);
			$Arrays::fill(out, (int8_t)0);
			if (cipherKeyEncoded != nullptr) {
				$Arrays::fill(cipherKeyEncoded, (int8_t)0);
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

$Key* DESedeWrapCipher::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$useLocalCurrentObjectStackCache();
	if ($nc(wrappedKey)->length == 0) {
		$throwNew($InvalidKeyException, "The wrapped key is empty"_s);
	}
	$var($bytes, buffer, $new($bytes, $nc(wrappedKey)->length));
	$nc(this->cipher)->decrypt(wrappedKey, 0, wrappedKey->length, buffer, 0);
	for (int32_t i = 0; i < buffer->length / 2; ++i) {
		int8_t temp = buffer->get(i);
		buffer->set(i, buffer->get(buffer->length - 1 - i));
		buffer->set(buffer->length - 1 - i, temp);
	}
	$set(this, iv, $new($bytes, DESedeWrapCipher::IV_LEN));
	$System::arraycopy(buffer, 0, this->iv, 0, $nc(this->iv)->length);
	$var($bytes, cipherKeyEncoded, $nc(this->cipherKey)->getEncoded());
	$var($bytes, out, nullptr);
	$var($bytes, buffer2, $new($bytes, buffer->length - $nc(this->iv)->length));
	{
		$var($Throwable, var$0, nullptr);
		$var($Key, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$nc(this->cipher)->init(true, $($nc(this->cipherKey)->getAlgorithm()), cipherKeyEncoded, this->iv);
			} catch ($InvalidAlgorithmParameterException& iape) {
				$throwNew($InvalidKeyException, "IV in wrapped key is invalid"_s);
			}
			$nc(this->cipher)->decrypt(buffer, $nc(this->iv)->length, buffer2->length, buffer2, 0);
			int32_t keyValLen = buffer2->length - DESedeWrapCipher::CHECKSUM_LEN;
			$var($bytes, cks, getChecksum(buffer2, 0, keyValLen));
			int32_t offset = keyValLen;
			for (int32_t i = 0; i < DESedeWrapCipher::CHECKSUM_LEN; ++i) {
				if (buffer2->get(offset + i) != $nc(cks)->get(i)) {
					$throwNew($InvalidKeyException, "Checksum comparison failed"_s);
				}
			}
			try {
				$nc(this->cipher)->init(this->decrypting, $($nc(this->cipherKey)->getAlgorithm()), cipherKeyEncoded, DESedeWrapCipher::IV2);
			} catch ($InvalidAlgorithmParameterException& iape) {
				$throwNew($InvalidKeyException, "IV in wrapped key is invalid"_s);
			}
			$assign(out, $new($bytes, keyValLen));
			$System::arraycopy(buffer2, 0, out, 0, keyValLen);
			$assign(var$2, $ConstructKeys::constructKey(out, wrappedKeyAlgorithm, wrappedKeyType));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (out != nullptr) {
				$Arrays::fill(out, (int8_t)0);
			}
			if (cipherKeyEncoded != nullptr) {
				$Arrays::fill(cipherKeyEncoded, (int8_t)0);
			}
			$Arrays::fill(buffer2, (int8_t)0);
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

$bytes* DESedeWrapCipher::getChecksum($bytes* in) {
	$init(DESedeWrapCipher);
	return getChecksum(in, 0, $nc(in)->length);
}

$bytes* DESedeWrapCipher::getChecksum($bytes* in, int32_t offset, int32_t len) {
	$init(DESedeWrapCipher);
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md, nullptr);
	try {
		$assign(md, $MessageDigest::getInstance("SHA1"_s));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, "SHA1 message digest not available"_s);
	}
	$nc(md)->update(in, offset, len);
	$var($bytes, cks, $new($bytes, DESedeWrapCipher::CHECKSUM_LEN));
	$System::arraycopy($(md->digest()), 0, cks, 0, cks->length);
	md->reset();
	return cks;
}

void clinit$DESedeWrapCipher($Class* class$) {
	$assignStatic(DESedeWrapCipher::IV2, $new($bytes, {
		(int8_t)74,
		(int8_t)221,
		(int8_t)162,
		(int8_t)44,
		(int8_t)121,
		(int8_t)232,
		(int8_t)33,
		(int8_t)5
	}));
}

DESedeWrapCipher::DESedeWrapCipher() {
}

$Class* DESedeWrapCipher::load$($String* name, bool initialize) {
	$loadClass(DESedeWrapCipher, name, initialize, &_DESedeWrapCipher_ClassInfo_, clinit$DESedeWrapCipher, allocate$DESedeWrapCipher);
	return class$;
}

$Class* DESedeWrapCipher::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com