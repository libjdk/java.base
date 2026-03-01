#include <com/sun/crypto/provider/PBES1Core.h>

#include <com/sun/crypto/provider/CipherCore.h>
#include <com/sun/crypto/provider/ConstructKeys.h>
#include <com/sun/crypto/provider/DESConstants.h>
#include <com/sun/crypto/provider/DESCrypt.h>
#include <com/sun/crypto/provider/DESedeCrypt.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/DigestException.h>
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
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/spec/DESedeKeySpec.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef DES_BLOCK_SIZE
#undef DES_EDE_KEY_LEN
#undef UNWRAP_MODE

using $CipherCore = ::com::sun::crypto::provider::CipherCore;
using $ConstructKeys = ::com::sun::crypto::provider::ConstructKeys;
using $DESConstants = ::com::sun::crypto::provider::DESConstants;
using $DESCrypt = ::com::sun::crypto::provider::DESCrypt;
using $DESedeCrypt = ::com::sun::crypto::provider::DESedeCrypt;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $DigestException = ::java::security::DigestException;
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
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $DESedeKeySpec = ::javax::crypto::spec::DESedeKeySpec;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _PBES1Core_FieldInfo_[] = {
	{"cipher", "Lcom/sun/crypto/provider/CipherCore;", nullptr, $PRIVATE, $field(PBES1Core, cipher)},
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE, $field(PBES1Core, md)},
	{"blkSize", "I", nullptr, $PRIVATE, $field(PBES1Core, blkSize)},
	{"algo", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PBES1Core, algo)},
	{"salt", "[B", nullptr, $PRIVATE, $field(PBES1Core, salt)},
	{"iCount", "I", nullptr, $PRIVATE, $field(PBES1Core, iCount)},
	{}
};

$MethodInfo _PBES1Core_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, 0, $method(PBES1Core, init$, void, $String*), "java.security.NoSuchAlgorithmException,javax.crypto.NoSuchPaddingException"},
	{"deriveCipherKey", "([B)[B", nullptr, $PRIVATE, $method(PBES1Core, deriveCipherKey, $bytes*, $bytes*)},
	{"doFinal", "([BII)[B", nullptr, 0, $method(PBES1Core, doFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "([BII[BI)I", nullptr, 0, $method(PBES1Core, doFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"getBlockSize", "()I", nullptr, 0, $method(PBES1Core, getBlockSize, int32_t)},
	{"getIV", "()[B", nullptr, 0, $method(PBES1Core, getIV, $bytes*)},
	{"getOutputSize", "(I)I", nullptr, 0, $method(PBES1Core, getOutputSize, int32_t, int32_t)},
	{"getParameters", "()Ljava/security/AlgorithmParameters;", nullptr, 0, $method(PBES1Core, getParameters, $AlgorithmParameters*)},
	{"init", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(PBES1Core, init, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, 0, $method(PBES1Core, init, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"setMode", "(Ljava/lang/String;)V", nullptr, 0, $method(PBES1Core, setMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"setPadding", "(Ljava/lang/String;)V", nullptr, 0, $method(PBES1Core, setPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"unwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, 0, $method(PBES1Core, unwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"update", "([BII)[B", nullptr, 0, $method(PBES1Core, update, $bytes*, $bytes*, int32_t, int32_t)},
	{"update", "([BII[BI)I", nullptr, 0, $method(PBES1Core, update, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"wrap", "(Ljava/security/Key;)[B", nullptr, 0, $method(PBES1Core, wrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$ClassInfo _PBES1Core_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.PBES1Core",
	"java.lang.Object",
	nullptr,
	_PBES1Core_FieldInfo_,
	_PBES1Core_MethodInfo_
};

$Object* allocate$PBES1Core($Class* clazz) {
	return $of($alloc(PBES1Core));
}

void PBES1Core::init$($String* cipherAlg) {
	$useLocalCurrentObjectStackCache();
	$set(this, algo, nullptr);
	$set(this, salt, nullptr);
	this->iCount = 10;
	$set(this, algo, cipherAlg);
	if ($nc(this->algo)->equals("DES"_s)) {
		$set(this, cipher, $new($CipherCore, $$new($DESCrypt), $DESConstants::DES_BLOCK_SIZE));
	} else if ($nc(this->algo)->equals("DESede"_s)) {
		$set(this, cipher, $new($CipherCore, $$new($DESedeCrypt), $DESConstants::DES_BLOCK_SIZE));
	} else {
		$throwNew($NoSuchAlgorithmException, $$str({"No Cipher implementation for PBEWithMD5And"_s, this->algo}));
	}
	$nc(this->cipher)->setMode("CBC"_s);
	$nc(this->cipher)->setPadding("PKCS5Padding"_s);
	$set(this, md, $MessageDigest::getInstance("MD5"_s));
}

void PBES1Core::setMode($String* mode) {
	$nc(this->cipher)->setMode(mode);
}

void PBES1Core::setPadding($String* paddingScheme) {
	$nc(this->cipher)->setPadding(paddingScheme);
}

int32_t PBES1Core::getBlockSize() {
	return $DESConstants::DES_BLOCK_SIZE;
}

int32_t PBES1Core::getOutputSize(int32_t inputLen) {
	return $nc(this->cipher)->getOutputSize(inputLen);
}

$bytes* PBES1Core::getIV() {
	return $nc(this->cipher)->getIV();
}

$AlgorithmParameters* PBES1Core::getParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, params, nullptr);
	if (this->salt == nullptr) {
		$set(this, salt, $new($bytes, 8));
		$nc($($SunJCE::getRandom()))->nextBytes(this->salt);
	}
	$var($PBEParameterSpec, pbeSpec, $new($PBEParameterSpec, this->salt, this->iCount));
	try {
		$var($String, var$0, $str({"PBEWithMD5And"_s, ($nc(this->algo)->equalsIgnoreCase("DES"_s) ? "DES"_s : "TripleDES"_s)}));
		$assign(params, $AlgorithmParameters::getInstance(var$0, $(static_cast<$Provider*>($SunJCE::getInstance()))));
		$nc(params)->init(static_cast<$AlgorithmParameterSpec*>(pbeSpec));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, "SunJCE called, but not configured"_s);
	} catch ($InvalidParameterSpecException& ipse) {
		$throwNew($RuntimeException, "PBEParameterSpec not supported"_s);
	}
	return params;
}

void PBES1Core::init(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if (((opmode == $Cipher::DECRYPT_MODE) || (opmode == $Cipher::UNWRAP_MODE)) && (params == nullptr)) {
		$throwNew($InvalidAlgorithmParameterException, "Parameters missing"_s);
	}
	if (key == nullptr) {
		$throwNew($InvalidKeyException, "Null key"_s);
	}
	$var($bytes, derivedKey, nullptr);
	$var($bytes, passwdBytes, $nc(key)->getEncoded());
	{
		$var($Throwable, var$0, nullptr);
		try {
			if ((passwdBytes == nullptr) || !($nc($(key->getAlgorithm()))->regionMatches(true, 0, "PBE"_s, 0, 3))) {
				$throwNew($InvalidKeyException, "Missing password"_s);
			}
			if (params == nullptr) {
				$set(this, salt, $new($bytes, 8));
				$nc(random)->nextBytes(this->salt);
			} else {
				if (!($instanceOf($PBEParameterSpec, params))) {
					$throwNew($InvalidAlgorithmParameterException, "Wrong parameter type: PBE expected"_s);
				}
				$set(this, salt, $nc(($cast($PBEParameterSpec, params)))->getSalt());
				if ($nc(this->salt)->length != 8) {
					$throwNew($InvalidAlgorithmParameterException, "Salt must be 8 bytes long"_s);
				}
				this->iCount = ($cast($PBEParameterSpec, params))->getIterationCount();
				if (this->iCount <= 0) {
					$throwNew($InvalidAlgorithmParameterException, "IterationCount must be a positive number"_s);
				}
			}
			$assign(derivedKey, deriveCipherKey(passwdBytes));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (passwdBytes != nullptr) {
				$Arrays::fill(passwdBytes, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($SecretKeySpec, cipherKey, $new($SecretKeySpec, derivedKey, 0, $nc(derivedKey)->length - 8, this->algo));
	$var($IvParameterSpec, ivSpec, $new($IvParameterSpec, derivedKey, $nc(derivedKey)->length - 8, 8));
	$nc(this->cipher)->init(opmode, static_cast<$Key*>(cipherKey), static_cast<$AlgorithmParameterSpec*>(ivSpec), random);
}

$bytes* PBES1Core::deriveCipherKey($bytes* passwdBytes) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, result, nullptr);
	if ($nc(this->algo)->equals("DES"_s)) {
		$nc(this->md)->update(passwdBytes);
		$nc(this->md)->update(this->salt);
		$var($bytes, toBeHashed, $nc(this->md)->digest());
		for (int32_t i = 1; i < this->iCount; ++i) {
			$nc(this->md)->update(toBeHashed);
			try {
				$nc(this->md)->digest(toBeHashed, 0, $nc(toBeHashed)->length);
			} catch ($DigestException& e) {
				$throwNew($ProviderException, "Internal error"_s, e);
			}
		}
		$assign(result, toBeHashed);
	} else if ($nc(this->algo)->equals("DESede"_s)) {
		int32_t i = 0;
		for (i = 0; i < 4; ++i) {
			if ($nc(this->salt)->get(i) != $nc(this->salt)->get(i + 4)) {
				break;
			}
		}
		if (i == 4) {
			for (i = 0; i < 2; ++i) {
				int8_t tmp = $nc(this->salt)->get(i);
				$nc(this->salt)->set(i, $nc(this->salt)->get(3 - i));
				$nc(this->salt)->set(3 - i, tmp);
			}
		}
		$var($bytes, toBeHashed, nullptr);
		$assign(result, $new($bytes, $DESedeKeySpec::DES_EDE_KEY_LEN + $DESConstants::DES_BLOCK_SIZE));
		for (i = 0; i < 2; ++i) {
			$nc(this->md)->update(this->salt, i * ($nc(this->salt)->length / 2), $nc(this->salt)->length / 2);
			$nc(this->md)->update(passwdBytes);
			$assign(toBeHashed, $nc(this->md)->digest());
			for (int32_t j = 1; j < this->iCount; ++j) {
				$nc(this->md)->update(toBeHashed);
				$nc(this->md)->update(passwdBytes);
				try {
					$nc(this->md)->digest(toBeHashed, 0, $nc(toBeHashed)->length);
				} catch ($DigestException& e) {
					$throwNew($ProviderException, "Internal error"_s, e);
				}
			}
			$System::arraycopy(toBeHashed, 0, result, i * 16, $nc(toBeHashed)->length);
		}
	}
	$nc(this->md)->reset();
	return result;
}

void PBES1Core::init(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$var($PBEParameterSpec, pbeSpec, nullptr);
	if (params != nullptr) {
		try {
			$load($PBEParameterSpec);
			$assign(pbeSpec, $cast($PBEParameterSpec, params->getParameterSpec($PBEParameterSpec::class$)));
		} catch ($InvalidParameterSpecException& ipse) {
			$throwNew($InvalidAlgorithmParameterException, "Wrong parameter type: PBE expected"_s);
		}
	}
	init(opmode, key, static_cast<$AlgorithmParameterSpec*>(pbeSpec), random);
}

$bytes* PBES1Core::update($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->cipher)->update(input, inputOffset, inputLen);
}

int32_t PBES1Core::update($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->cipher)->update(input, inputOffset, inputLen, output, outputOffset);
}

$bytes* PBES1Core::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->cipher)->doFinal(input, inputOffset, inputLen);
}

int32_t PBES1Core::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->cipher)->doFinal(input, inputOffset, inputLen, output, outputOffset);
}

$bytes* PBES1Core::wrap($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, result, nullptr);
	$var($bytes, encodedKey, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$assign(encodedKey, $nc(key)->getEncoded());
				if ((encodedKey == nullptr) || ($nc(encodedKey)->length == 0)) {
					$throwNew($InvalidKeyException, "Cannot get an encoding of the key to be wrapped"_s);
				}
				$assign(result, doFinal(encodedKey, 0, $nc(encodedKey)->length));
			} catch ($BadPaddingException& e) {
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (encodedKey != nullptr) {
				$Arrays::fill(encodedKey, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return result;
}

$Key* PBES1Core::unwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($bytes, encodedKey, doFinal(wrappedKey, 0, $nc(wrappedKey)->length));
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
	} catch ($BadPaddingException& ePadding) {
		$throwNew($InvalidKeyException, "The wrapped key is not padded correctly"_s);
	} catch ($IllegalBlockSizeException& eBlockSize) {
		$throwNew($InvalidKeyException, "The wrapped key does not have the correct length"_s);
	}
	$shouldNotReachHere();
}

PBES1Core::PBES1Core() {
}

$Class* PBES1Core::load$($String* name, bool initialize) {
	$loadClass(PBES1Core, name, initialize, &_PBES1Core_ClassInfo_, allocate$PBES1Core);
	return class$;
}

$Class* PBES1Core::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com