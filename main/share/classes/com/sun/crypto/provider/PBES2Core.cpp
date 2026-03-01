#include <com/sun/crypto/provider/PBES2Core.h>

#include <com/sun/crypto/provider/AESConstants.h>
#include <com/sun/crypto/provider/AESCrypt.h>
#include <com/sun/crypto/provider/CipherCore.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA1.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA224.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA256.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA384.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA512.h>
#include <com/sun/crypto/provider/PBKDF2Core.h>
#include <com/sun/crypto/provider/PBKDF2KeyImpl.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/CipherSpi.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/interfaces/PBEKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <jcpp.h>

#undef AES_BLOCK_SIZE
#undef DEFAULT_COUNT
#undef DEFAULT_SALT_LENGTH
#undef ENCRYPT_MODE
#undef WRAP_MODE

using $AESConstants = ::com::sun::crypto::provider::AESConstants;
using $AESCrypt = ::com::sun::crypto::provider::AESCrypt;
using $CipherCore = ::com::sun::crypto::provider::CipherCore;
using $PBKDF2Core = ::com::sun::crypto::provider::PBKDF2Core;
using $PBKDF2Core$HmacSHA1 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA1;
using $PBKDF2Core$HmacSHA224 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA224;
using $PBKDF2Core$HmacSHA256 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA256;
using $PBKDF2Core$HmacSHA384 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA384;
using $PBKDF2Core$HmacSHA512 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA512;
using $PBKDF2KeyImpl = ::com::sun::crypto::provider::PBKDF2KeyImpl;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $CipherSpi = ::javax::crypto::CipherSpi;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $PBEKey = ::javax::crypto::interfaces::PBEKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _PBES2Core_FieldInfo_[] = {
	{"DEFAULT_SALT_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PBES2Core, DEFAULT_SALT_LENGTH)},
	{"DEFAULT_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PBES2Core, DEFAULT_COUNT)},
	{"cipher", "Lcom/sun/crypto/provider/CipherCore;", nullptr, $PRIVATE | $FINAL, $field(PBES2Core, cipher)},
	{"keyLength", "I", nullptr, $PRIVATE | $FINAL, $field(PBES2Core, keyLength)},
	{"blkSize", "I", nullptr, $PRIVATE | $FINAL, $field(PBES2Core, blkSize)},
	{"kdf", "Lcom/sun/crypto/provider/PBKDF2Core;", nullptr, $PRIVATE | $FINAL, $field(PBES2Core, kdf)},
	{"pbeAlgo", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(PBES2Core, pbeAlgo)},
	{"cipherAlgo", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(PBES2Core, cipherAlgo)},
	{"iCount", "I", nullptr, $PRIVATE, $field(PBES2Core, iCount)},
	{"salt", "[B", nullptr, $PRIVATE, $field(PBES2Core, salt)},
	{"ivSpec", "Ljavax/crypto/spec/IvParameterSpec;", nullptr, $PRIVATE, $field(PBES2Core, ivSpec)},
	{}
};

$MethodInfo _PBES2Core_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;I)V", nullptr, 0, $method(PBES2Core, init$, void, $String*, $String*, int32_t), "java.security.NoSuchAlgorithmException,javax.crypto.NoSuchPaddingException"},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(PBES2Core, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$InnerClassInfo _PBES2Core_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.PBES2Core$HmacSHA512AndAES_256", "com.sun.crypto.provider.PBES2Core", "HmacSHA512AndAES_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA384AndAES_256", "com.sun.crypto.provider.PBES2Core", "HmacSHA384AndAES_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA256AndAES_256", "com.sun.crypto.provider.PBES2Core", "HmacSHA256AndAES_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA224AndAES_256", "com.sun.crypto.provider.PBES2Core", "HmacSHA224AndAES_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA1AndAES_256", "com.sun.crypto.provider.PBES2Core", "HmacSHA1AndAES_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA512AndAES_128", "com.sun.crypto.provider.PBES2Core", "HmacSHA512AndAES_128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA384AndAES_128", "com.sun.crypto.provider.PBES2Core", "HmacSHA384AndAES_128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA256AndAES_128", "com.sun.crypto.provider.PBES2Core", "HmacSHA256AndAES_128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA224AndAES_128", "com.sun.crypto.provider.PBES2Core", "HmacSHA224AndAES_128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBES2Core$HmacSHA1AndAES_128", "com.sun.crypto.provider.PBES2Core", "HmacSHA1AndAES_128", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _PBES2Core_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"com.sun.crypto.provider.PBES2Core",
	"javax.crypto.CipherSpi",
	nullptr,
	_PBES2Core_FieldInfo_,
	_PBES2Core_MethodInfo_,
	nullptr,
	nullptr,
	_PBES2Core_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.PBES2Core$HmacSHA512AndAES_256,com.sun.crypto.provider.PBES2Core$HmacSHA384AndAES_256,com.sun.crypto.provider.PBES2Core$HmacSHA256AndAES_256,com.sun.crypto.provider.PBES2Core$HmacSHA224AndAES_256,com.sun.crypto.provider.PBES2Core$HmacSHA1AndAES_256,com.sun.crypto.provider.PBES2Core$HmacSHA512AndAES_128,com.sun.crypto.provider.PBES2Core$HmacSHA384AndAES_128,com.sun.crypto.provider.PBES2Core$HmacSHA256AndAES_128,com.sun.crypto.provider.PBES2Core$HmacSHA224AndAES_128,com.sun.crypto.provider.PBES2Core$HmacSHA1AndAES_128"
};

$Object* allocate$PBES2Core($Class* clazz) {
	return $of($alloc(PBES2Core));
}

void PBES2Core::init$($String* kdfAlgo, $String* cipherAlgo, int32_t keySize) {
	$useLocalCurrentObjectStackCache();
	$CipherSpi::init$();
	this->iCount = PBES2Core::DEFAULT_COUNT;
	$set(this, salt, nullptr);
	$set(this, ivSpec, nullptr);
	$set(this, cipherAlgo, cipherAlgo);
	this->keyLength = keySize * 8;
	$set(this, pbeAlgo, $str({"PBEWith"_s, kdfAlgo, "And"_s, cipherAlgo, "_"_s, $$str(this->keyLength)}));
	if ($nc(cipherAlgo)->equals("AES"_s)) {
		this->blkSize = $AESConstants::AES_BLOCK_SIZE;
		$set(this, cipher, $new($CipherCore, $$new($AESCrypt), this->blkSize));
		{
			$var($String, s2782$, kdfAlgo);
			int32_t tmp2782$ = -1;
			switch ($nc(s2782$)->hashCode()) {
			case 0x687BD5AC:
				{
					if (s2782$->equals("HmacSHA1"_s)) {
						tmp2782$ = 0;
					}
					break;
				}
			case 0x38DD24AF:
				{
					if (s2782$->equals("HmacSHA224"_s)) {
						tmp2782$ = 1;
					}
					break;
				}
			case 0x38DD250E:
				{
					if (s2782$->equals("HmacSHA256"_s)) {
						tmp2782$ = 2;
					}
					break;
				}
			case 0x38DD292A:
				{
					if (s2782$->equals("HmacSHA384"_s)) {
						tmp2782$ = 3;
					}
					break;
				}
			case 0x38DD2FD1:
				{
					if (s2782$->equals("HmacSHA512"_s)) {
						tmp2782$ = 4;
					}
					break;
				}
			}
			switch (tmp2782$) {
			case 0:
				{
					$set(this, kdf, $new($PBKDF2Core$HmacSHA1));
					break;
				}
			case 1:
				{
					$set(this, kdf, $new($PBKDF2Core$HmacSHA224));
					break;
				}
			case 2:
				{
					$set(this, kdf, $new($PBKDF2Core$HmacSHA256));
					break;
				}
			case 3:
				{
					$set(this, kdf, $new($PBKDF2Core$HmacSHA384));
					break;
				}
			case 4:
				{
					$set(this, kdf, $new($PBKDF2Core$HmacSHA512));
					break;
				}
			default:
				{
					$throwNew($NoSuchAlgorithmException, $$str({"No Cipher implementation for "_s, kdfAlgo}));
				}
			}
		}
	} else {
		$throwNew($NoSuchAlgorithmException, $$str({"No Cipher implementation for "_s, this->pbeAlgo}));
	}
	$nc(this->cipher)->setMode("CBC"_s);
	$nc(this->cipher)->setPadding("PKCS5Padding"_s);
}

void PBES2Core::engineSetMode($String* mode) {
	if ((mode != nullptr) && (!mode->equalsIgnoreCase("CBC"_s))) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid cipher mode: "_s, mode}));
	}
}

void PBES2Core::engineSetPadding($String* paddingScheme) {
	if ((paddingScheme != nullptr) && (!paddingScheme->equalsIgnoreCase("PKCS5Padding"_s))) {
		$throwNew($NoSuchPaddingException, $$str({"Invalid padding scheme: "_s, paddingScheme}));
	}
}

int32_t PBES2Core::engineGetBlockSize() {
	return this->blkSize;
}

int32_t PBES2Core::engineGetOutputSize(int32_t inputLen) {
	return $nc(this->cipher)->getOutputSize(inputLen);
}

$bytes* PBES2Core::engineGetIV() {
	return $nc(this->cipher)->getIV();
}

$AlgorithmParameters* PBES2Core::engineGetParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, params, nullptr);
	if (this->salt == nullptr) {
		$set(this, salt, $new($bytes, PBES2Core::DEFAULT_SALT_LENGTH));
		$nc($($SunJCE::getRandom()))->nextBytes(this->salt);
		this->iCount = PBES2Core::DEFAULT_COUNT;
	}
	if (this->ivSpec == nullptr) {
		$var($bytes, ivBytes, $new($bytes, this->blkSize));
		$nc($($SunJCE::getRandom()))->nextBytes(ivBytes);
		$set(this, ivSpec, $new($IvParameterSpec, ivBytes));
	}
	$var($PBEParameterSpec, pbeSpec, $new($PBEParameterSpec, this->salt, this->iCount, this->ivSpec));
	try {
		$assign(params, $AlgorithmParameters::getInstance(this->pbeAlgo, $(static_cast<$Provider*>($SunJCE::getInstance()))));
		$nc(params)->init(static_cast<$AlgorithmParameterSpec*>(pbeSpec));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, "SunJCE called, but not configured"_s);
	} catch ($InvalidParameterSpecException& ipse) {
		$throwNew($RuntimeException, "PBEParameterSpec not supported"_s);
	}
	return params;
}

void PBES2Core::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		engineInit(opmode, key, ($AlgorithmParameterSpec*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& ie) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, "requires PBE parameters"_s));
		ike->initCause(ie);
		$throw(ike);
	}
}

void PBES2Core::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($InvalidKeyException, "Null key"_s);
	}
	$var($bytes, passwdBytes, $nc(key)->getEncoded());
	$var($chars, passwdChars, nullptr);
	$var($PBEKeySpec, pbeSpec, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			if ((passwdBytes == nullptr) || !($nc($(key->getAlgorithm()))->regionMatches(true, 0, "PBE"_s, 0, 3))) {
				$throwNew($InvalidKeyException, "Missing password"_s);
			}
			if ($instanceOf($PBEKey, key)) {
				$set(this, salt, $nc(($cast($PBEKey, key)))->getSalt());
				if (this->salt != nullptr && $nc(this->salt)->length < 8) {
					$throwNew($InvalidAlgorithmParameterException, "Salt must be at least 8 bytes long"_s);
				}
				this->iCount = ($cast($PBEKey, key))->getIterationCount();
				if (this->iCount == 0) {
					this->iCount = PBES2Core::DEFAULT_COUNT;
				} else if (this->iCount < 0) {
					$throwNew($InvalidAlgorithmParameterException, "Iteration count must be a positive number"_s);
				}
			}
			if (params == nullptr) {
				if (this->salt == nullptr) {
					$set(this, salt, $new($bytes, PBES2Core::DEFAULT_SALT_LENGTH));
					$nc(random)->nextBytes(this->salt);
					this->iCount = PBES2Core::DEFAULT_COUNT;
				}
				if ((opmode == $Cipher::ENCRYPT_MODE) || (opmode == $Cipher::WRAP_MODE)) {
					$var($bytes, ivBytes, $new($bytes, this->blkSize));
					$nc(random)->nextBytes(ivBytes);
					$set(this, ivSpec, $new($IvParameterSpec, ivBytes));
				}
			} else {
				if (!($instanceOf($PBEParameterSpec, params))) {
					$throwNew($InvalidAlgorithmParameterException, "Wrong parameter type: PBE expected"_s);
				}
				$var($bytes, specSalt, $nc(($cast($PBEParameterSpec, params)))->getSalt());
				if (specSalt != nullptr && specSalt->length < 8) {
					$throwNew($InvalidAlgorithmParameterException, "Salt must be at least 8 bytes long"_s);
				}
				$set(this, salt, specSalt);
				int32_t specICount = ($cast($PBEParameterSpec, params))->getIterationCount();
				if (specICount == 0) {
					specICount = PBES2Core::DEFAULT_COUNT;
				} else if (specICount < 0) {
					$throwNew($InvalidAlgorithmParameterException, "Iteration count must be a positive number"_s);
				}
				this->iCount = specICount;
				$var($AlgorithmParameterSpec, specParams, ($cast($PBEParameterSpec, params))->getParameterSpec());
				if (specParams != nullptr) {
					if ($instanceOf($IvParameterSpec, specParams)) {
						$set(this, ivSpec, $cast($IvParameterSpec, specParams));
					} else {
						$throwNew($InvalidAlgorithmParameterException, "Wrong parameter type: IV expected"_s);
					}
				} else if ((opmode == $Cipher::ENCRYPT_MODE) || (opmode == $Cipher::WRAP_MODE)) {
					$var($bytes, ivBytes, $new($bytes, this->blkSize));
					$nc(random)->nextBytes(ivBytes);
					$set(this, ivSpec, $new($IvParameterSpec, ivBytes));
				} else {
					$throwNew($InvalidAlgorithmParameterException, "Missing parameter type: IV expected"_s);
				}
			}
			$assign(passwdChars, $new($chars, $nc(passwdBytes)->length));
			for (int32_t i = 0; i < passwdChars->length; ++i) {
				passwdChars->set(i, (char16_t)((int32_t)(passwdBytes->get(i) & (uint32_t)127)));
			}
			$assign(pbeSpec, $new($PBEKeySpec, passwdChars, this->salt, this->iCount, this->keyLength));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (passwdChars != nullptr) {
				$Arrays::fill(passwdChars, u'\0');
			}
			if (passwdBytes != nullptr) {
				$Arrays::fill(passwdBytes, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($PBKDF2KeyImpl, s, nullptr);
	{
		$var($Throwable, var$2, nullptr);
		try {
			try {
				$assign(s, $cast($PBKDF2KeyImpl, $nc(this->kdf)->engineGenerateSecret(pbeSpec)));
			} catch ($InvalidKeySpecException& ikse) {
				$var($InvalidKeyException, ike, $new($InvalidKeyException, "Cannot construct PBE key"_s));
				ike->initCause(ikse);
				$throw(ike);
			}
		} catch ($Throwable& var$3) {
			$assign(var$2, var$3);
		} /*finally*/ {
			$nc(pbeSpec)->clearPassword();
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
	}
	$var($bytes, derivedKey, $nc(s)->getEncoded());
	s->clearPassword();
	$var($SecretKeySpec, cipherKey, $new($SecretKeySpec, derivedKey, this->cipherAlgo));
	$nc(this->cipher)->init(opmode, static_cast<$Key*>(cipherKey), static_cast<$AlgorithmParameterSpec*>(this->ivSpec), random);
}

void PBES2Core::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$var($AlgorithmParameterSpec, pbeSpec, nullptr);
	if (params != nullptr) {
		try {
			$load($PBEParameterSpec);
			$assign(pbeSpec, params->getParameterSpec($PBEParameterSpec::class$));
		} catch ($InvalidParameterSpecException& ipse) {
			$throwNew($InvalidAlgorithmParameterException, "Wrong parameter type: PBE expected"_s);
		}
	}
	engineInit(opmode, key, pbeSpec, random);
}

$bytes* PBES2Core::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->cipher)->update(input, inputOffset, inputLen);
}

int32_t PBES2Core::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->cipher)->update(input, inputOffset, inputLen, output, outputOffset);
}

$bytes* PBES2Core::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->cipher)->doFinal(input, inputOffset, inputLen);
}

int32_t PBES2Core::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->cipher)->doFinal(input, inputOffset, inputLen, output, outputOffset);
}

int32_t PBES2Core::engineGetKeySize($Key* key) {
	return this->keyLength;
}

$bytes* PBES2Core::engineWrap($Key* key) {
	return $nc(this->cipher)->wrap(key);
}

$Key* PBES2Core::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$var($bytes, encodedKey, nullptr);
	return $nc(this->cipher)->unwrap(wrappedKey, wrappedKeyAlgorithm, wrappedKeyType);
}

PBES2Core::PBES2Core() {
}

$Class* PBES2Core::load$($String* name, bool initialize) {
	$loadClass(PBES2Core, name, initialize, &_PBES2Core_ClassInfo_, allocate$PBES2Core);
	return class$;
}

$Class* PBES2Core::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com