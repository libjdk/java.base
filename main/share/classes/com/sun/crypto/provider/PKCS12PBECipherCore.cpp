#include <com/sun/crypto/provider/PKCS12PBECipherCore.h>

#include <com/sun/crypto/provider/ARCFOURCipher.h>
#include <com/sun/crypto/provider/CipherCore.h>
#include <com/sun/crypto/provider/DESedeCrypt.h>
#include <com/sun/crypto/provider/RC2Crypt.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/lang/Math.h>
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
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/interfaces/PBEKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <javax/security/auth/DestroyFailedException.h>
#include <jcpp.h>

#undef B
#undef CIPHER_IV
#undef CIPHER_KEY
#undef D
#undef DECRYPT_MODE
#undef DEFAULT_COUNT
#undef DEFAULT_SALT_LENGTH
#undef I
#undef MAC_KEY
#undef UNWRAP_MODE

using $ARCFOURCipher = ::com::sun::crypto::provider::ARCFOURCipher;
using $CipherCore = ::com::sun::crypto::provider::CipherCore;
using $DESedeCrypt = ::com::sun::crypto::provider::DESedeCrypt;
using $RC2Crypt = ::com::sun::crypto::provider::RC2Crypt;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
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
using $SecretKey = ::javax::crypto::SecretKey;
using $PBEKey = ::javax::crypto::interfaces::PBEKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $DestroyFailedException = ::javax::security::auth::DestroyFailedException;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _PKCS12PBECipherCore_FieldInfo_[] = {
	{"cipher", "Lcom/sun/crypto/provider/CipherCore;", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, cipher)},
	{"blockSize", "I", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, blockSize)},
	{"keySize", "I", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, keySize)},
	{"keyLength", "I", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, keyLength)},
	{"algo", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, algo)},
	{"pbeAlgo", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, pbeAlgo)},
	{"salt", "[B", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, salt)},
	{"iCount", "I", nullptr, $PRIVATE, $field(PKCS12PBECipherCore, iCount)},
	{"DEFAULT_SALT_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12PBECipherCore, DEFAULT_SALT_LENGTH)},
	{"DEFAULT_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12PBECipherCore, DEFAULT_COUNT)},
	{"CIPHER_KEY", "I", nullptr, $STATIC | $FINAL, $constField(PKCS12PBECipherCore, CIPHER_KEY)},
	{"CIPHER_IV", "I", nullptr, $STATIC | $FINAL, $constField(PKCS12PBECipherCore, CIPHER_IV)},
	{"MAC_KEY", "I", nullptr, $STATIC | $FINAL, $constField(PKCS12PBECipherCore, MAC_KEY)},
	{}
};

$MethodInfo _PKCS12PBECipherCore_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, 0, $method(PKCS12PBECipherCore, init$, void, $String*, int32_t), "java.security.NoSuchAlgorithmException"},
	{"addOne", "(I[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12PBECipherCore, addOne, void, int32_t, $bytes*)},
	{"addTwo", "(I[B[BI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12PBECipherCore, addTwo, void, int32_t, $bytes*, $bytes*, int32_t)},
	{"concat", "([B[BII)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12PBECipherCore, concat, void, $bytes*, $bytes*, int32_t, int32_t)},
	{"derive", "([C[BIII)[B", nullptr, $STATIC, $staticMethod(PKCS12PBECipherCore, derive, $bytes*, $chars*, $bytes*, int32_t, int32_t, int32_t)},
	{"derive", "([C[BIIILjava/lang/String;I)[B", nullptr, $STATIC, $staticMethod(PKCS12PBECipherCore, derive, $bytes*, $chars*, $bytes*, int32_t, int32_t, int32_t, $String*, int32_t)},
	{"implDoFinal", "([BII)[B", nullptr, 0, $method(PKCS12PBECipherCore, implDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"implDoFinal", "([BII[BI)I", nullptr, 0, $method(PKCS12PBECipherCore, implDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"implGetBlockSize", "()I", nullptr, 0, $method(PKCS12PBECipherCore, implGetBlockSize, int32_t)},
	{"implGetIV", "()[B", nullptr, 0, $method(PKCS12PBECipherCore, implGetIV, $bytes*)},
	{"implGetKeySize", "(Ljava/security/Key;)I", nullptr, 0, $method(PKCS12PBECipherCore, implGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"implGetOutputSize", "(I)I", nullptr, 0, $method(PKCS12PBECipherCore, implGetOutputSize, int32_t, int32_t)},
	{"implGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, 0, $method(PKCS12PBECipherCore, implGetParameters, $AlgorithmParameters*)},
	{"implInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(PKCS12PBECipherCore, implInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"implInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;Ljavax/crypto/CipherSpi;)V", nullptr, 0, $method(PKCS12PBECipherCore, implInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*, $CipherSpi*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"implInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, 0, $method(PKCS12PBECipherCore, implInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"implInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;Ljavax/crypto/CipherSpi;)V", nullptr, 0, $method(PKCS12PBECipherCore, implInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*, $CipherSpi*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"implInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, 0, $method(PKCS12PBECipherCore, implInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"implInit", "(ILjava/security/Key;Ljava/security/SecureRandom;Ljavax/crypto/CipherSpi;)V", nullptr, 0, $method(PKCS12PBECipherCore, implInit, void, int32_t, $Key*, $SecureRandom*, $CipherSpi*), "java.security.InvalidKeyException"},
	{"implSetMode", "(Ljava/lang/String;)V", nullptr, 0, $method(PKCS12PBECipherCore, implSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"implSetPadding", "(Ljava/lang/String;)V", nullptr, 0, $method(PKCS12PBECipherCore, implSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"implUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, 0, $method(PKCS12PBECipherCore, implUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"implUpdate", "([BII)[B", nullptr, 0, $method(PKCS12PBECipherCore, implUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"implUpdate", "([BII[BI)I", nullptr, 0, $method(PKCS12PBECipherCore, implUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"implWrap", "(Ljava/security/Key;)[B", nullptr, 0, $method(PKCS12PBECipherCore, implWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{"roundup", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12PBECipherCore, roundup, int32_t, int32_t, int32_t)},
	{}
};

$InnerClassInfo _PKCS12PBECipherCore_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC4_128", "com.sun.crypto.provider.PKCS12PBECipherCore", "PBEWithSHA1AndRC4_128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC4_40", "com.sun.crypto.provider.PKCS12PBECipherCore", "PBEWithSHA1AndRC4_40", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC2_128", "com.sun.crypto.provider.PKCS12PBECipherCore", "PBEWithSHA1AndRC2_128", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC2_40", "com.sun.crypto.provider.PKCS12PBECipherCore", "PBEWithSHA1AndRC2_40", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndDESede", "com.sun.crypto.provider.PKCS12PBECipherCore", "PBEWithSHA1AndDESede", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _PKCS12PBECipherCore_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.PKCS12PBECipherCore",
	"java.lang.Object",
	nullptr,
	_PKCS12PBECipherCore_FieldInfo_,
	_PKCS12PBECipherCore_MethodInfo_,
	nullptr,
	nullptr,
	_PKCS12PBECipherCore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC4_128,com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC4_40,com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC2_128,com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC2_40,com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndDESede"
};

$Object* allocate$PKCS12PBECipherCore($Class* clazz) {
	return $of($alloc(PKCS12PBECipherCore));
}

$bytes* PKCS12PBECipherCore::derive($chars* chars, $bytes* salt, int32_t ic, int32_t n, int32_t type) {
	return derive(chars, salt, ic, n, type, "SHA-1"_s, 64);
}

$bytes* PKCS12PBECipherCore::derive($chars* chars$renamed, $bytes* salt, int32_t ic, int32_t n, int32_t type, $String* hashAlgo, int32_t blockLength) {
	$useLocalCurrentObjectStackCache();
	$var($chars, chars, chars$renamed);
	int32_t length = $nc(chars)->length * 2;
	if (length == 2 && chars->get(0) == 0) {
		$assign(chars, $new($chars, 0));
		length = 0;
	} else {
		length += 2;
	}
	$var($bytes, passwd, $new($bytes, length));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < chars->length; ++i, j += 2) {
			passwd->set(j, (int8_t)((int32_t)(((int32_t)((uint32_t)chars->get(i) >> 8)) & (uint32_t)255)));
			passwd->set(j + 1, (int8_t)((int32_t)(chars->get(i) & (uint32_t)255)));
		}
	}
	$var($bytes, key, $new($bytes, n));
	try {
		$var($MessageDigest, sha, $MessageDigest::getInstance(hashAlgo));
		int32_t v = blockLength;
		int32_t u = $nc(sha)->getDigestLength();
		int32_t c = $div(roundup(n, u), u);
		$var($bytes, D, $new($bytes, v));
		int32_t s = roundup($nc(salt)->length, v);
		int32_t p = roundup(passwd->length, v);
		$var($bytes, I, $new($bytes, s + p));
		$Arrays::fill(D, (int8_t)type);
		concat(salt, I, 0, s);
		concat(passwd, I, s, p);
		$Arrays::fill(passwd, (int8_t)0);
		$var($bytes, Ai, nullptr);
		$var($bytes, B, $new($bytes, v));
		int32_t i = 0;
		for (;; ++i, n -= u) {
			sha->update(D);
			sha->update(I);
			$assign(Ai, sha->digest());
			for (int32_t r = 1; r < ic; ++r) {
				$assign(Ai, sha->digest(Ai));
			}
			$System::arraycopy(Ai, 0, key, u * i, $Math::min(n, u));
			if (i + 1 == c) {
				break;
			}
			concat(Ai, B, 0, v);
			addOne(v, B);
			for (int32_t j = 0; j < I->length; j += v) {
				addTwo(v, B, I, j);
			}
		}
		$Arrays::fill(I, (int8_t)0);
	} catch ($Exception& e) {
		$throwNew($RuntimeException, $$str({"internal error: "_s, e}));
	}
	return key;
}

void PKCS12PBECipherCore::addOne(int32_t len, $bytes* b) {
	for (int32_t i = len - 1; i >= 0; --i) {
		if (((int32_t)($nc(b)->get(i) & (uint32_t)255)) != 255) {
			++(*b)[i];
			break;
		} else {
			b->set(i, (int8_t)0);
		}
	}
}

void PKCS12PBECipherCore::addTwo(int32_t len, $bytes* src, $bytes* dst, int32_t offset) {
	int32_t carry = 0;
	for (int32_t i = len - 1; i >= 0; --i) {
		int32_t sum = ((int32_t)($nc(src)->get(i) & (uint32_t)255)) + ((int32_t)($nc(dst)->get(i + offset) & (uint32_t)255)) + carry;
		carry = sum >> 8;
		dst->set(i + offset, (int8_t)sum);
	}
}

int32_t PKCS12PBECipherCore::roundup(int32_t x, int32_t y) {
	return ($div((x + (y - 1)), y)) * y;
}

void PKCS12PBECipherCore::concat($bytes* src, $bytes* dst, int32_t start, int32_t len) {
	if ($nc(src)->length == 0) {
		return;
	}
	int32_t loop = $div(len, $nc(src)->length);
	int32_t off = 0;
	int32_t i = 0;
	for (i = 0, off = 0; i < loop; ++i, off += src->length) {
		$System::arraycopy(src, 0, dst, off + start, src->length);
	}
	$System::arraycopy(src, 0, dst, off + start, len - off);
}

void PKCS12PBECipherCore::init$($String* symmCipherAlg, int32_t defKeySize) {
	$useLocalCurrentObjectStackCache();
	$set(this, algo, nullptr);
	$set(this, pbeAlgo, nullptr);
	$set(this, salt, nullptr);
	this->iCount = 0;
	$set(this, algo, symmCipherAlg);
	this->keyLength = defKeySize * 8;
	if ($nc(this->algo)->equals("RC4"_s)) {
		$set(this, pbeAlgo, $str({"PBEWithSHA1AndRC4_"_s, $$str(this->keyLength)}));
	} else {
		$var($SymmetricCipher, symmCipher, nullptr);
		if ($nc(this->algo)->equals("DESede"_s)) {
			$assign(symmCipher, $new($DESedeCrypt));
			$set(this, pbeAlgo, "PBEWithSHA1AndDESede"_s);
			this->keyLength = 112;
		} else if ($nc(this->algo)->equals("RC2"_s)) {
			$assign(symmCipher, $new($RC2Crypt));
			$set(this, pbeAlgo, $str({"PBEWithSHA1AndRC2_"_s, $$str(this->keyLength)}));
		} else {
			$throwNew($NoSuchAlgorithmException, $$str({"No Cipher implementation for PBEWithSHA1And"_s, this->algo}));
		}
		this->blockSize = $nc(symmCipher)->getBlockSize();
		$set(this, cipher, $new($CipherCore, symmCipher, this->blockSize));
		$nc(this->cipher)->setMode("CBC"_s);
		try {
			$nc(this->cipher)->setPadding("PKCS5Padding"_s);
		} catch ($NoSuchPaddingException& nspe) {
		}
	}
	this->keySize = defKeySize;
}

void PKCS12PBECipherCore::implSetMode($String* mode) {
	if ((mode != nullptr) && (!mode->equalsIgnoreCase("CBC"_s))) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid cipher mode: "_s, mode}));
	}
}

void PKCS12PBECipherCore::implSetPadding($String* padding) {
	if ((padding != nullptr) && (!padding->equalsIgnoreCase("PKCS5Padding"_s))) {
		$throwNew($NoSuchPaddingException, $$str({"Invalid padding scheme: "_s, padding}));
	}
}

int32_t PKCS12PBECipherCore::implGetBlockSize() {
	return this->blockSize;
}

int32_t PKCS12PBECipherCore::implGetOutputSize(int32_t inLen) {
	return $nc(this->cipher)->getOutputSize(inLen);
}

$bytes* PKCS12PBECipherCore::implGetIV() {
	return $nc(this->cipher)->getIV();
}

$AlgorithmParameters* PKCS12PBECipherCore::implGetParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, params, nullptr);
	if (this->salt == nullptr) {
		$set(this, salt, $new($bytes, PKCS12PBECipherCore::DEFAULT_SALT_LENGTH));
		$nc($($SunJCE::getRandom()))->nextBytes(this->salt);
		this->iCount = PKCS12PBECipherCore::DEFAULT_COUNT;
	}
	$var($PBEParameterSpec, pbeSpec, $new($PBEParameterSpec, this->salt, this->iCount));
	try {
		$assign(params, $AlgorithmParameters::getInstance(this->pbeAlgo, $(static_cast<$Provider*>($SunJCE::getInstance()))));
		$nc(params)->init(static_cast<$AlgorithmParameterSpec*>(pbeSpec));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, "SunJCE provider is not configured properly"_s);
	} catch ($InvalidParameterSpecException& ipse) {
		$throwNew($RuntimeException, "PBEParameterSpec not supported"_s);
	}
	return params;
}

void PKCS12PBECipherCore::implInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	implInit(opmode, key, params, random, ($CipherSpi*)nullptr);
}

void PKCS12PBECipherCore::implInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random, $CipherSpi* cipherImpl) {
	$useLocalCurrentObjectStackCache();
	$var($chars, passwdChars, nullptr);
	$set(this, salt, nullptr);
	this->iCount = 0;
	if ($instanceOf($PBEKey, key)) {
		$var($PBEKey, pbeKey, $cast($PBEKey, key));
		$assign(passwdChars, $nc(pbeKey)->getPassword());
		$set(this, salt, pbeKey->getSalt());
		this->iCount = pbeKey->getIterationCount();
	} else if ($instanceOf($SecretKey, key)) {
		$var($bytes, passwdBytes, nullptr);
		bool var$0 = !($nc($($nc(key)->getAlgorithm()))->regionMatches(true, 0, "PBE"_s, 0, 3));
		if (var$0 || ($assign(passwdBytes, $nc(key)->getEncoded())) == nullptr) {
			$throwNew($InvalidKeyException, "Missing password"_s);
		}
		$assign(passwdChars, $new($chars, $nc(passwdBytes)->length));
		for (int32_t i = 0; i < passwdChars->length; ++i) {
			passwdChars->set(i, (char16_t)((int32_t)(passwdBytes->get(i) & (uint32_t)127)));
		}
		$Arrays::fill(passwdBytes, (int8_t)0);
	} else {
		$throwNew($InvalidKeyException, "SecretKey of PBE type required"_s);
	}
	{
		$var($Throwable, var$1, nullptr);
		try {
			if (((opmode == $Cipher::DECRYPT_MODE) || (opmode == $Cipher::UNWRAP_MODE)) && ((params == nullptr) && ((this->salt == nullptr) || (this->iCount == 0)))) {
				$throwNew($InvalidAlgorithmParameterException, "Parameters missing"_s);
			}
			if (params == nullptr) {
				if (this->salt == nullptr) {
					$set(this, salt, $new($bytes, PKCS12PBECipherCore::DEFAULT_SALT_LENGTH));
					if (random != nullptr) {
						random->nextBytes(this->salt);
					} else {
						$nc($($SunJCE::getRandom()))->nextBytes(this->salt);
					}
				}
				if (this->iCount == 0) {
					this->iCount = PKCS12PBECipherCore::DEFAULT_COUNT;
				}
			} else if (!($instanceOf($PBEParameterSpec, params))) {
				$throwNew($InvalidAlgorithmParameterException, "PBEParameterSpec type required"_s);
			} else {
				$var($PBEParameterSpec, pbeParams, $cast($PBEParameterSpec, params));
				if (this->salt != nullptr) {
					if (!$Arrays::equals(this->salt, $($nc(pbeParams)->getSalt()))) {
						$throwNew($InvalidAlgorithmParameterException, "Inconsistent value of salt between key and params"_s);
					}
				} else {
					$set(this, salt, $nc(pbeParams)->getSalt());
				}
				if (this->iCount != 0) {
					if (this->iCount != $nc(pbeParams)->getIterationCount()) {
						$throwNew($InvalidAlgorithmParameterException, "Different iteration count between key and params"_s);
					}
				} else {
					this->iCount = $nc(pbeParams)->getIterationCount();
				}
			}
			if ($nc(this->salt)->length < 8) {
				$throwNew($InvalidAlgorithmParameterException, "Salt must be at least 8 bytes long"_s);
			}
			if (this->iCount <= 0) {
				$throwNew($InvalidAlgorithmParameterException, "IterationCount must be a positive number"_s);
			}
			$var($bytes, derivedKey, derive(passwdChars, this->salt, this->iCount, this->keySize, PKCS12PBECipherCore::CIPHER_KEY));
			$var($SecretKey, cipherKey, $new($SecretKeySpec, derivedKey, this->algo));
			$Arrays::fill(derivedKey, (int8_t)0);
			{
				$var($Throwable, var$2, nullptr);
				try {
					if (cipherImpl != nullptr && $instanceOf($ARCFOURCipher, cipherImpl)) {
						$nc(($cast($ARCFOURCipher, cipherImpl)))->engineInit(opmode, cipherKey, random);
					} else {
						$var($bytes, derivedIv, derive(passwdChars, this->salt, this->iCount, 8, PKCS12PBECipherCore::CIPHER_IV));
						$var($IvParameterSpec, ivSpec, $new($IvParameterSpec, derivedIv, 0, 8));
						$nc(this->cipher)->init(opmode, static_cast<$Key*>(cipherKey), static_cast<$AlgorithmParameterSpec*>(ivSpec), random);
					}
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					try {
						cipherKey->destroy();
					} catch ($DestroyFailedException& e) {
					}
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} /*finally*/ {
			$Arrays::fill(passwdChars, u'\0');
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
}

void PKCS12PBECipherCore::implInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	implInit(opmode, key, params, random, ($CipherSpi*)nullptr);
}

void PKCS12PBECipherCore::implInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random, $CipherSpi* cipherImpl) {
	$var($AlgorithmParameterSpec, paramSpec, nullptr);
	if (params != nullptr) {
		try {
			$load($PBEParameterSpec);
			$assign(paramSpec, params->getParameterSpec($PBEParameterSpec::class$));
		} catch ($InvalidParameterSpecException& ipse) {
			$throwNew($InvalidAlgorithmParameterException, "requires PBE parameters"_s);
		}
	}
	implInit(opmode, key, paramSpec, random, cipherImpl);
}

void PKCS12PBECipherCore::implInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	implInit(opmode, key, random, ($CipherSpi*)nullptr);
}

void PKCS12PBECipherCore::implInit(int32_t opmode, $Key* key, $SecureRandom* random, $CipherSpi* cipherImpl) {
	try {
		implInit(opmode, key, ($AlgorithmParameterSpec*)nullptr, random, cipherImpl);
	} catch ($InvalidAlgorithmParameterException& iape) {
		$throwNew($InvalidKeyException, "requires PBE parameters"_s);
	}
}

$bytes* PKCS12PBECipherCore::implUpdate($bytes* in, int32_t inOff, int32_t inLen) {
	return $nc(this->cipher)->update(in, inOff, inLen);
}

int32_t PKCS12PBECipherCore::implUpdate($bytes* in, int32_t inOff, int32_t inLen, $bytes* out, int32_t outOff) {
	return $nc(this->cipher)->update(in, inOff, inLen, out, outOff);
}

$bytes* PKCS12PBECipherCore::implDoFinal($bytes* in, int32_t inOff, int32_t inLen) {
	return $nc(this->cipher)->doFinal(in, inOff, inLen);
}

int32_t PKCS12PBECipherCore::implDoFinal($bytes* in, int32_t inOff, int32_t inLen, $bytes* out, int32_t outOff) {
	return $nc(this->cipher)->doFinal(in, inOff, inLen, out, outOff);
}

int32_t PKCS12PBECipherCore::implGetKeySize($Key* key) {
	return this->keyLength;
}

$bytes* PKCS12PBECipherCore::implWrap($Key* key) {
	return $nc(this->cipher)->wrap(key);
}

$Key* PKCS12PBECipherCore::implUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	return $nc(this->cipher)->unwrap(wrappedKey, wrappedKeyAlgorithm, wrappedKeyType);
}

PKCS12PBECipherCore::PKCS12PBECipherCore() {
}

$Class* PKCS12PBECipherCore::load$($String* name, bool initialize) {
	$loadClass(PKCS12PBECipherCore, name, initialize, &_PKCS12PBECipherCore_ClassInfo_, allocate$PKCS12PBECipherCore);
	return class$;
}

$Class* PKCS12PBECipherCore::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com