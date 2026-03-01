#include <com/sun/crypto/provider/RSACipher.h>

#include <com/sun/crypto/provider/ConstructKeys.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/interfaces/RSAKey.h>
#include <java/security/interfaces/RSAPrivateKey.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/MGF1ParameterSpec.h>
#include <java/util/Arrays.h>
#include <java/util/Locale.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/CipherSpi.h>
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/ShortBufferException.h>
#include <javax/crypto/spec/OAEPParameterSpec.h>
#include <javax/crypto/spec/PSource$PSpecified.h>
#include <javax/crypto/spec/PSource.h>
#include <sun/security/internal/spec/TlsRsaPremasterSecretParameterSpec.h>
#include <sun/security/jca/ProviderList.h>
#include <sun/security/jca/Providers.h>
#include <sun/security/rsa/RSACore.h>
#include <sun/security/rsa/RSAKeyFactory.h>
#include <sun/security/rsa/RSAPadding.h>
#include <sun/security/util/KeyUtil.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef DEFAULT
#undef ENCRYPT_MODE
#undef ENGLISH
#undef MODE_DECRYPT
#undef MODE_ENCRYPT
#undef MODE_SIGN
#undef MODE_VERIFY
#undef PAD_BLOCKTYPE_1
#undef PAD_BLOCKTYPE_2
#undef PAD_NONE
#undef PAD_OAEP_MGF1
#undef PAD_PKCS1
#undef SHA1
#undef UNWRAP_MODE
#undef WRAP_MODE

using $ConstructKeys = ::com::sun::crypto::provider::ConstructKeys;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $SecureRandom = ::java::security::SecureRandom;
using $RSAKey = ::java::security::interfaces::RSAKey;
using $RSAPrivateKey = ::java::security::interfaces::RSAPrivateKey;
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $MGF1ParameterSpec = ::java::security::spec::MGF1ParameterSpec;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $CipherSpi = ::javax::crypto::CipherSpi;
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $OAEPParameterSpec = ::javax::crypto::spec::OAEPParameterSpec;
using $PSource = ::javax::crypto::spec::PSource;
using $PSource$PSpecified = ::javax::crypto::spec::PSource$PSpecified;
using $TlsRsaPremasterSecretParameterSpec = ::sun::security::internal::spec::TlsRsaPremasterSecretParameterSpec;
using $ProviderList = ::sun::security::jca::ProviderList;
using $Providers = ::sun::security::jca::Providers;
using $RSACore = ::sun::security::rsa::RSACore;
using $RSAKeyFactory = ::sun::security::rsa::RSAKeyFactory;
using $RSAPadding = ::sun::security::rsa::RSAPadding;
using $KeyUtil = ::sun::security::util::KeyUtil;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _RSACipher_FieldInfo_[] = {
	{"B0", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSACipher, B0)},
	{"MODE_ENCRYPT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSACipher, MODE_ENCRYPT)},
	{"MODE_DECRYPT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSACipher, MODE_DECRYPT)},
	{"MODE_SIGN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSACipher, MODE_SIGN)},
	{"MODE_VERIFY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSACipher, MODE_VERIFY)},
	{"PAD_NONE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSACipher, PAD_NONE)},
	{"PAD_PKCS1", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSACipher, PAD_PKCS1)},
	{"PAD_OAEP_MGF1", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSACipher, PAD_OAEP_MGF1)},
	{"mode", "I", nullptr, $PRIVATE, $field(RSACipher, mode)},
	{"paddingType", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RSACipher, paddingType)},
	{"padding", "Lsun/security/rsa/RSAPadding;", nullptr, $PRIVATE, $field(RSACipher, padding)},
	{"spec", "Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PRIVATE, $field(RSACipher, spec)},
	{"buffer", "[B", nullptr, $PRIVATE, $field(RSACipher, buffer)},
	{"bufOfs", "I", nullptr, $PRIVATE, $field(RSACipher, bufOfs)},
	{"outputSize", "I", nullptr, $PRIVATE, $field(RSACipher, outputSize)},
	{"publicKey", "Ljava/security/interfaces/RSAPublicKey;", nullptr, $PRIVATE, $field(RSACipher, publicKey)},
	{"privateKey", "Ljava/security/interfaces/RSAPrivateKey;", nullptr, $PRIVATE, $field(RSACipher, privateKey)},
	{"oaepHashAlgorithm", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RSACipher, oaepHashAlgorithm)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(RSACipher, random)},
	{}
};

$MethodInfo _RSACipher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RSACipher, init$, void)},
	{"doFinal", "()[B", nullptr, $PRIVATE, $method(RSACipher, doFinal, $bytes*), "javax.crypto.BadPaddingException,javax.crypto.IllegalBlockSizeException"},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.BadPaddingException,javax.crypto.IllegalBlockSizeException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.BadPaddingException,javax.crypto.IllegalBlockSizeException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t)},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(RSACipher, engineWrap, $bytes*, $Key*), "java.security.InvalidKeyException,javax.crypto.IllegalBlockSizeException"},
	{"init", "(ILjava/security/Key;Ljava/security/SecureRandom;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PRIVATE, $method(RSACipher, init, void, int32_t, $Key*, $SecureRandom*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"update", "([BII)V", nullptr, $PRIVATE, $method(RSACipher, update, void, $bytes*, int32_t, int32_t)},
	{}
};

$ClassInfo _RSACipher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.RSACipher",
	"javax.crypto.CipherSpi",
	nullptr,
	_RSACipher_FieldInfo_,
	_RSACipher_MethodInfo_
};

$Object* allocate$RSACipher($Class* clazz) {
	return $of($alloc(RSACipher));
}

$bytes* RSACipher::B0 = nullptr;
$String* RSACipher::PAD_NONE = nullptr;
$String* RSACipher::PAD_PKCS1 = nullptr;
$String* RSACipher::PAD_OAEP_MGF1 = nullptr;

void RSACipher::init$() {
	$CipherSpi::init$();
	$set(this, spec, nullptr);
	$set(this, oaepHashAlgorithm, "SHA-1"_s);
	$set(this, paddingType, RSACipher::PAD_PKCS1);
}

void RSACipher::engineSetMode($String* mode) {
	if ($nc(mode)->equalsIgnoreCase("ECB"_s) == false) {
		$throwNew($NoSuchAlgorithmException, $$str({"Unsupported mode "_s, mode}));
	}
}

void RSACipher::engineSetPadding($String* paddingName) {
	$useLocalCurrentObjectStackCache();
	if ($nc(paddingName)->equalsIgnoreCase(RSACipher::PAD_NONE)) {
		$set(this, paddingType, RSACipher::PAD_NONE);
	} else if (paddingName->equalsIgnoreCase(RSACipher::PAD_PKCS1)) {
		$set(this, paddingType, RSACipher::PAD_PKCS1);
	} else {
		$init($Locale);
		$var($String, lowerPadding, paddingName->toLowerCase($Locale::ENGLISH));
		if (lowerPadding->equals("oaeppadding"_s)) {
			$set(this, paddingType, RSACipher::PAD_OAEP_MGF1);
		} else {
			bool var$1 = lowerPadding->startsWith("oaepwith"_s);
			if (var$1 && lowerPadding->endsWith("andmgf1padding"_s)) {
				$set(this, paddingType, RSACipher::PAD_OAEP_MGF1);
				$set(this, oaepHashAlgorithm, paddingName->substring(8, paddingName->length() - 14));
				if ($nc($($Providers::getProviderList()))->getService("MessageDigest"_s, this->oaepHashAlgorithm) == nullptr) {
					$throwNew($NoSuchPaddingException, $$str({"MessageDigest not available for "_s, paddingName}));
				}
			} else {
				$throwNew($NoSuchPaddingException, $$str({"Padding "_s, paddingName, " not supported"_s}));
			}
		}
	}
}

int32_t RSACipher::engineGetBlockSize() {
	return 0;
}

int32_t RSACipher::engineGetOutputSize(int32_t inputLen) {
	return this->outputSize;
}

$bytes* RSACipher::engineGetIV() {
	return nullptr;
}

$AlgorithmParameters* RSACipher::engineGetParameters() {
	$useLocalCurrentObjectStackCache();
	if (this->spec != nullptr && $instanceOf($OAEPParameterSpec, this->spec)) {
		try {
			$var($AlgorithmParameters, params, $AlgorithmParameters::getInstance("OAEP"_s, $(static_cast<$Provider*>($SunJCE::getInstance()))));
			$nc(params)->init(this->spec);
			return params;
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($RuntimeException, "Cannot find OAEP  AlgorithmParameters implementation in SunJCE provider"_s);
		} catch ($InvalidParameterSpecException& ipse) {
			$throwNew($RuntimeException, "OAEPParameterSpec not supported"_s);
		}
	} else {
		return nullptr;
	}
}

void RSACipher::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		init(opmode, key, random, nullptr);
	} catch ($InvalidAlgorithmParameterException& iape) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, "Wrong parameters"_s));
		ike->initCause(iape);
		$throw(ike);
	}
}

void RSACipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	init(opmode, key, random, params);
}

void RSACipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if (params == nullptr) {
		init(opmode, key, random, nullptr);
	} else {
		try {
			$load($OAEPParameterSpec);
			$var($OAEPParameterSpec, spec, $cast($OAEPParameterSpec, $nc(params)->getParameterSpec($OAEPParameterSpec::class$)));
			init(opmode, key, random, spec);
		} catch ($InvalidParameterSpecException& ipse) {
			$var($InvalidAlgorithmParameterException, iape, $new($InvalidAlgorithmParameterException, "Wrong parameter"_s));
			iape->initCause(ipse);
			$throw(iape);
		}
	}
}

void RSACipher::init(int32_t opmode, $Key* key, $SecureRandom* random, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	bool encrypt = false;
	switch (opmode) {
	case $Cipher::ENCRYPT_MODE:
		{}
	case $Cipher::WRAP_MODE:
		{
			encrypt = true;
			break;
		}
	case $Cipher::DECRYPT_MODE:
		{}
	case $Cipher::UNWRAP_MODE:
		{
			encrypt = false;
			break;
		}
	default:
		{
			$throwNew($AssertionError, $of($$str({"Unknown mode: "_s, $$str(opmode)})));
		}
	}
	$var($RSAKey, rsaKey, $RSAKeyFactory::toRSAKey(key));
	if ($instanceOf($RSAPublicKey, rsaKey)) {
		this->mode = encrypt ? RSACipher::MODE_ENCRYPT : RSACipher::MODE_VERIFY;
		$set(this, publicKey, $cast($RSAPublicKey, rsaKey));
		$set(this, privateKey, nullptr);
	} else {
		this->mode = encrypt ? RSACipher::MODE_SIGN : RSACipher::MODE_DECRYPT;
		$set(this, privateKey, $cast($RSAPrivateKey, rsaKey));
		$set(this, publicKey, nullptr);
	}
	int32_t n = $RSACore::getByteLength($($nc(rsaKey)->getModulus()));
	this->outputSize = n;
	this->bufOfs = 0;
	if (this->paddingType == RSACipher::PAD_NONE) {
		if (params != nullptr) {
			$throwNew($InvalidAlgorithmParameterException, "Parameters not supported"_s);
		}
		$set(this, padding, $RSAPadding::getInstance($RSAPadding::PAD_NONE, n, random));
		$set(this, buffer, $new($bytes, n));
	} else if (this->paddingType == RSACipher::PAD_PKCS1) {
		if (params != nullptr) {
			if (!($instanceOf($TlsRsaPremasterSecretParameterSpec, params))) {
				$throwNew($InvalidAlgorithmParameterException, "Parameters not supported"_s);
			}
			$set(this, spec, params);
			$set(this, random, random);
		}
		int32_t blockType = (this->mode <= RSACipher::MODE_DECRYPT) ? $RSAPadding::PAD_BLOCKTYPE_2 : $RSAPadding::PAD_BLOCKTYPE_1;
		$set(this, padding, $RSAPadding::getInstance(blockType, n, random));
		if (encrypt) {
			int32_t k = $nc(this->padding)->getMaxDataSize();
			$set(this, buffer, $new($bytes, k));
		} else {
			$set(this, buffer, $new($bytes, n));
		}
	} else {
		if ((this->mode == RSACipher::MODE_SIGN) || (this->mode == RSACipher::MODE_VERIFY)) {
			$throwNew($InvalidKeyException, "OAEP cannot be used to sign or verify signatures"_s);
		}
		if (params != nullptr) {
			if (!($instanceOf($OAEPParameterSpec, params))) {
				$throwNew($InvalidAlgorithmParameterException, "Wrong Parameters for OAEP Padding"_s);
			}
			$set(this, spec, params);
		} else {
			$init($MGF1ParameterSpec);
			$init($PSource$PSpecified);
			$set(this, spec, $new($OAEPParameterSpec, this->oaepHashAlgorithm, "MGF1"_s, $MGF1ParameterSpec::SHA1, $PSource$PSpecified::DEFAULT));
		}
		$set(this, padding, $RSAPadding::getInstance($RSAPadding::PAD_OAEP_MGF1, n, random, $cast($OAEPParameterSpec, this->spec)));
		if (encrypt) {
			int32_t k = $nc(this->padding)->getMaxDataSize();
			$set(this, buffer, $new($bytes, k));
		} else {
			$set(this, buffer, $new($bytes, n));
		}
	}
}

void RSACipher::update($bytes* in, int32_t inOfs, int32_t inLen) {
	if ((inLen == 0) || (in == nullptr)) {
		return;
	}
	if (inLen > ($nc(this->buffer)->length - this->bufOfs)) {
		this->bufOfs = $nc(this->buffer)->length + 1;
		return;
	}
	$System::arraycopy(in, inOfs, this->buffer, this->bufOfs, inLen);
	this->bufOfs += inLen;
}

$bytes* RSACipher::doFinal() {
	$useLocalCurrentObjectStackCache();
	if (this->bufOfs > $nc(this->buffer)->length) {
		$throwNew($IllegalBlockSizeException, $$str({"Data must not be longer than "_s, $$str($nc(this->buffer)->length), " bytes"_s}));
	}
	$var($bytes, paddingCopy, nullptr);
	$var($bytes, result, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			{
				$var($bytes, verifyBuffer, nullptr)
				$var($bytes, decryptBuffer, nullptr)
				switch (this->mode) {
				case RSACipher::MODE_SIGN:
					{
						$assign(paddingCopy, $nc(this->padding)->pad(this->buffer, 0, this->bufOfs));
						$assign(result, $RSACore::rsa(paddingCopy, this->privateKey, true));
						break;
					}
				case RSACipher::MODE_VERIFY:
					{
						$assign(verifyBuffer, $RSACore::convert(this->buffer, 0, this->bufOfs));
						$assign(paddingCopy, $RSACore::rsa(verifyBuffer, this->publicKey));
						$assign(result, $nc(this->padding)->unpad(paddingCopy));
						break;
					}
				case RSACipher::MODE_ENCRYPT:
					{
						$assign(paddingCopy, $nc(this->padding)->pad(this->buffer, 0, this->bufOfs));
						$assign(result, $RSACore::rsa(paddingCopy, this->publicKey));
						break;
					}
				case RSACipher::MODE_DECRYPT:
					{
						$assign(decryptBuffer, $RSACore::convert(this->buffer, 0, this->bufOfs));
						$assign(paddingCopy, $RSACore::rsa(decryptBuffer, this->privateKey, false));
						$assign(result, $nc(this->padding)->unpad(paddingCopy));
						break;
					}
				default:
					{
						$throwNew($AssertionError, $of("Internal error"_s));
					}
				}
			}
			$assign(var$2, result);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(this->buffer, 0, this->bufOfs, (int8_t)0);
			this->bufOfs = 0;
			if (paddingCopy != nullptr && paddingCopy != this->buffer && paddingCopy != result) {
				$Arrays::fill(paddingCopy, (int8_t)0);
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

$bytes* RSACipher::engineUpdate($bytes* in, int32_t inOfs, int32_t inLen) {
	update(in, inOfs, inLen);
	return RSACipher::B0;
}

int32_t RSACipher::engineUpdate($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out, int32_t outOfs) {
	update(in, inOfs, inLen);
	return 0;
}

$bytes* RSACipher::engineDoFinal($bytes* in, int32_t inOfs, int32_t inLen) {
	update(in, inOfs, inLen);
	return doFinal();
}

int32_t RSACipher::engineDoFinal($bytes* in, int32_t inOfs, int32_t inLen, $bytes* out, int32_t outOfs) {
	$useLocalCurrentObjectStackCache();
	if (this->outputSize > $nc(out)->length - outOfs) {
		$throwNew($ShortBufferException, $$str({"Need "_s, $$str(this->outputSize), " bytes for output"_s}));
	}
	update(in, inOfs, inLen);
	$var($bytes, result, doFinal());
	int32_t n = $nc(result)->length;
	$System::arraycopy(result, 0, out, outOfs, n);
	$Arrays::fill(result, (int8_t)0);
	return n;
}

$bytes* RSACipher::engineWrap($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $nc(key)->getEncoded());
	if ((encoded == nullptr) || ($nc(encoded)->length == 0)) {
		$throwNew($InvalidKeyException, "Could not obtain encoded key"_s);
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($bytes, var$2, nullptr);
		bool return$1 = false;
		try {
			if ($nc(encoded)->length > $nc(this->buffer)->length) {
				$throwNew($InvalidKeyException, "Key is too long for wrapping"_s);
			}
			update(encoded, 0, $nc(encoded)->length);
			try {
				$assign(var$2, doFinal());
				return$1 = true;
				goto $finally;
			} catch ($BadPaddingException& e) {
				$throwNew($InvalidKeyException, "Wrapping failed"_s, e);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(encoded, (int8_t)0);
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

$Key* RSACipher::engineUnwrap($bytes* wrappedKey, $String* algorithm, int32_t type) {
	$useLocalCurrentObjectStackCache();
	if ($nc(wrappedKey)->length > $nc(this->buffer)->length) {
		$throwNew($InvalidKeyException, "Key is too long for unwrapping"_s);
	}
	bool isTlsRsaPremasterSecret = $nc(algorithm)->equals("TlsRsaPremasterSecret"_s);
	$var($Exception, failover, nullptr);
	$var($bytes, encoded, nullptr);
	update(wrappedKey, 0, $nc(wrappedKey)->length);
	try {
		$assign(encoded, doFinal());
	} catch ($BadPaddingException& e) {
		if (isTlsRsaPremasterSecret) {
			$assign(failover, e);
		} else {
			$throwNew($InvalidKeyException, "Unwrapping failed"_s, e);
		}
	} catch ($IllegalBlockSizeException& e) {
		$throwNew($InvalidKeyException, "Unwrapping failed"_s, e);
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($Key, var$2, nullptr);
		bool return$1 = false;
		try {
			if (isTlsRsaPremasterSecret) {
				if (!($instanceOf($TlsRsaPremasterSecretParameterSpec, this->spec))) {
					$throwNew($IllegalStateException, "No TlsRsaPremasterSecretParameterSpec specified"_s);
				}
				int32_t var$3 = $nc(($cast($TlsRsaPremasterSecretParameterSpec, this->spec)))->getClientVersion();
				$assign(encoded, $KeyUtil::checkTlsPreMasterSecretKey(var$3, $nc(($cast($TlsRsaPremasterSecretParameterSpec, this->spec)))->getServerVersion(), this->random, encoded, (failover != nullptr)));
			}
			$assign(var$2, $ConstructKeys::constructKey(encoded, algorithm, type));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			if (encoded != nullptr) {
				$Arrays::fill(encoded, (int8_t)0);
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

int32_t RSACipher::engineGetKeySize($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($RSAKey, rsaKey, $RSAKeyFactory::toRSAKey(key));
	return $nc($($nc(rsaKey)->getModulus()))->bitLength();
}

void clinit$RSACipher($Class* class$) {
	$assignStatic(RSACipher::PAD_NONE, "NoPadding"_s);
	$assignStatic(RSACipher::PAD_PKCS1, "PKCS1Padding"_s);
	$assignStatic(RSACipher::PAD_OAEP_MGF1, "OAEP"_s);
	$assignStatic(RSACipher::B0, $new($bytes, 0));
}

RSACipher::RSACipher() {
}

$Class* RSACipher::load$($String* name, bool initialize) {
	$loadClass(RSACipher, name, initialize, &_RSACipher_ClassInfo_, clinit$RSACipher, allocate$RSACipher);
	return class$;
}

$Class* RSACipher::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com