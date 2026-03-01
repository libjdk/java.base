#include <com/sun/crypto/provider/PBMAC1Core.h>

#include <com/sun/crypto/provider/HmacCore.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA1.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA224.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA256.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA384.h>
#include <com/sun/crypto/provider/PBKDF2Core$HmacSHA512.h>
#include <com/sun/crypto/provider/PBKDF2Core.h>
#include <com/sun/crypto/provider/PBKDF2KeyImpl.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/ProviderException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/interfaces/PBEKey.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <jcpp.h>

using $HmacCore = ::com::sun::crypto::provider::HmacCore;
using $PBKDF2Core = ::com::sun::crypto::provider::PBKDF2Core;
using $PBKDF2Core$HmacSHA1 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA1;
using $PBKDF2Core$HmacSHA224 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA224;
using $PBKDF2Core$HmacSHA256 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA256;
using $PBKDF2Core$HmacSHA384 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA384;
using $PBKDF2Core$HmacSHA512 = ::com::sun::crypto::provider::PBKDF2Core$HmacSHA512;
using $PBKDF2KeyImpl = ::com::sun::crypto::provider::PBKDF2KeyImpl;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $ProviderException = ::java::security::ProviderException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $Arrays = ::java::util::Arrays;
using $SecretKey = ::javax::crypto::SecretKey;
using $PBEKey = ::javax::crypto::interfaces::PBEKey;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _PBMAC1Core_FieldInfo_[] = {
	{"kdfAlgo", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(PBMAC1Core, kdfAlgo)},
	{"hashAlgo", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(PBMAC1Core, hashAlgo)},
	{"blockLength", "I", nullptr, $PRIVATE | $FINAL, $field(PBMAC1Core, blockLength)},
	{}
};

$MethodInfo _PBMAC1Core_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;I)V", nullptr, 0, $method(PBMAC1Core, init$, void, $String*, $String*, int32_t), "java.security.NoSuchAlgorithmException"},
	{"engineInit", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(PBMAC1Core, engineInit, void, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"getKDFImpl", "(Ljava/lang/String;)Lcom/sun/crypto/provider/PBKDF2Core;", nullptr, $PRIVATE | $STATIC, $staticMethod(PBMAC1Core, getKDFImpl, $PBKDF2Core*, $String*)},
	{}
};

$InnerClassInfo _PBMAC1Core_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.PBMAC1Core$HmacSHA512", "com.sun.crypto.provider.PBMAC1Core", "HmacSHA512", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBMAC1Core$HmacSHA384", "com.sun.crypto.provider.PBMAC1Core", "HmacSHA384", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBMAC1Core$HmacSHA256", "com.sun.crypto.provider.PBMAC1Core", "HmacSHA256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBMAC1Core$HmacSHA224", "com.sun.crypto.provider.PBMAC1Core", "HmacSHA224", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.PBMAC1Core$HmacSHA1", "com.sun.crypto.provider.PBMAC1Core", "HmacSHA1", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _PBMAC1Core_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"com.sun.crypto.provider.PBMAC1Core",
	"com.sun.crypto.provider.HmacCore",
	nullptr,
	_PBMAC1Core_FieldInfo_,
	_PBMAC1Core_MethodInfo_,
	nullptr,
	nullptr,
	_PBMAC1Core_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.PBMAC1Core$HmacSHA512,com.sun.crypto.provider.PBMAC1Core$HmacSHA384,com.sun.crypto.provider.PBMAC1Core$HmacSHA256,com.sun.crypto.provider.PBMAC1Core$HmacSHA224,com.sun.crypto.provider.PBMAC1Core$HmacSHA1"
};

$Object* allocate$PBMAC1Core($Class* clazz) {
	return $of($alloc(PBMAC1Core));
}

void PBMAC1Core::init$($String* kdfAlgo, $String* hashAlgo, int32_t blockLength) {
	$HmacCore::init$(hashAlgo, blockLength);
	$set(this, kdfAlgo, kdfAlgo);
	$set(this, hashAlgo, hashAlgo);
	this->blockLength = blockLength;
}

$PBKDF2Core* PBMAC1Core::getKDFImpl($String* algo) {
	$init(PBMAC1Core);
	$useLocalCurrentObjectStackCache();
	$var($PBKDF2Core, kdf, nullptr);
	{
		$var($String, s2411$, algo);
		int32_t tmp2411$ = -1;
		switch ($nc(s2411$)->hashCode()) {
		case 0x687BD5AC:
			{
				if (s2411$->equals("HmacSHA1"_s)) {
					tmp2411$ = 0;
				}
				break;
			}
		case 0x38DD24AF:
			{
				if (s2411$->equals("HmacSHA224"_s)) {
					tmp2411$ = 1;
				}
				break;
			}
		case 0x38DD250E:
			{
				if (s2411$->equals("HmacSHA256"_s)) {
					tmp2411$ = 2;
				}
				break;
			}
		case 0x38DD292A:
			{
				if (s2411$->equals("HmacSHA384"_s)) {
					tmp2411$ = 3;
				}
				break;
			}
		case 0x38DD2FD1:
			{
				if (s2411$->equals("HmacSHA512"_s)) {
					tmp2411$ = 4;
				}
				break;
			}
		}
		switch (tmp2411$) {
		case 0:
			{
				$assign(kdf, $new($PBKDF2Core$HmacSHA1));
				break;
			}
		case 1:
			{
				$assign(kdf, $new($PBKDF2Core$HmacSHA224));
				break;
			}
		case 2:
			{
				$assign(kdf, $new($PBKDF2Core$HmacSHA256));
				break;
			}
		case 3:
			{
				$assign(kdf, $new($PBKDF2Core$HmacSHA384));
				break;
			}
		case 4:
			{
				$assign(kdf, $new($PBKDF2Core$HmacSHA512));
				break;
			}
		default:
			{
				$throwNew($ProviderException, $$str({"No MAC implementation for "_s, algo}));
			}
		}
	}
	return kdf;
}

void PBMAC1Core::engineInit($Key* key, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	$var($chars, passwdChars, nullptr);
	$var($bytes, salt, nullptr);
	int32_t iCount = 0;
	if ($instanceOf($PBEKey, key)) {
		$var($PBEKey, pbeKey, $cast($PBEKey, key));
		$assign(passwdChars, $nc(pbeKey)->getPassword());
		$assign(salt, pbeKey->getSalt());
		iCount = pbeKey->getIterationCount();
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
	$var($PBEKeySpec, pbeSpec, nullptr);
	{
		$var($Throwable, var$1, nullptr);
		try {
			if (params == nullptr) {
				if ((salt == nullptr) || (iCount == 0)) {
					$throwNew($InvalidAlgorithmParameterException, "PBEParameterSpec required for salt and iteration count"_s);
				}
			} else if (!($instanceOf($PBEParameterSpec, params))) {
				$throwNew($InvalidAlgorithmParameterException, "PBEParameterSpec type required"_s);
			} else {
				$var($PBEParameterSpec, pbeParams, $cast($PBEParameterSpec, params));
				if (salt != nullptr) {
					if (!$Arrays::equals(salt, $($nc(pbeParams)->getSalt()))) {
						$throwNew($InvalidAlgorithmParameterException, "Inconsistent value of salt between key and params"_s);
					}
				} else {
					$assign(salt, $nc(pbeParams)->getSalt());
				}
				if (iCount != 0) {
					if (iCount != $nc(pbeParams)->getIterationCount()) {
						$throwNew($InvalidAlgorithmParameterException, "Different iteration count between key and params"_s);
					}
				} else {
					iCount = $nc(pbeParams)->getIterationCount();
				}
			}
			if ($nc(salt)->length < 8) {
				$throwNew($InvalidAlgorithmParameterException, "Salt must be at least 8 bytes long"_s);
			}
			if (iCount <= 0) {
				$throwNew($InvalidAlgorithmParameterException, "IterationCount must be a positive number"_s);
			}
			$assign(pbeSpec, $new($PBEKeySpec, passwdChars, salt, iCount, this->blockLength));
		} catch ($Throwable& var$2) {
			$assign(var$1, var$2);
		} /*finally*/ {
			$Arrays::fill(passwdChars, u'\0');
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
	$var($PBKDF2KeyImpl, s, nullptr);
	$var($PBKDF2Core, kdf, getKDFImpl(this->kdfAlgo));
	$var($bytes, derivedKey, nullptr);
	{
		$var($Throwable, var$3, nullptr);
		try {
			try {
				$assign(s, $cast($PBKDF2KeyImpl, $nc(kdf)->engineGenerateSecret(pbeSpec)));
				$assign(derivedKey, $nc(s)->getEncoded());
			} catch ($InvalidKeySpecException& ikse) {
				$var($InvalidKeyException, ike, $new($InvalidKeyException, "Cannot construct PBE key"_s));
				ike->initCause(ikse);
				$throw(ike);
			}
		} catch ($Throwable& var$4) {
			$assign(var$3, var$4);
		} /*finally*/ {
			$nc(pbeSpec)->clearPassword();
			if (s != nullptr) {
				s->clearPassword();
			}
		}
		if (var$3 != nullptr) {
			$throw(var$3);
		}
	}
	$var($SecretKey, cipherKey, $new($SecretKeySpec, derivedKey, this->kdfAlgo));
	$Arrays::fill(derivedKey, (int8_t)0);
	$HmacCore::engineInit(cipherKey, nullptr);
}

PBMAC1Core::PBMAC1Core() {
}

$Class* PBMAC1Core::load$($String* name, bool initialize) {
	$loadClass(PBMAC1Core, name, initialize, &_PBMAC1Core_ClassInfo_, allocate$PBMAC1Core);
	return class$;
}

$Class* PBMAC1Core::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com