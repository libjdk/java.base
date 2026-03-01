#include <com/sun/crypto/provider/CipherCore.h>

#include <com/sun/crypto/provider/CipherBlockChaining.h>
#include <com/sun/crypto/provider/CipherFeedback.h>
#include <com/sun/crypto/provider/CipherTextStealing.h>
#include <com/sun/crypto/provider/ConstructKeys.h>
#include <com/sun/crypto/provider/CounterMode.h>
#include <com/sun/crypto/provider/ElectronicCodeBook.h>
#include <com/sun/crypto/provider/FeedbackCipher.h>
#include <com/sun/crypto/provider/ISO10126Padding.h>
#include <com/sun/crypto/provider/OutputFeedback.h>
#include <com/sun/crypto/provider/PCBC.h>
#include <com/sun/crypto/provider/PKCS5Padding.h>
#include <com/sun/crypto/provider/Padding.h>
#include <com/sun/crypto/provider/RC2Crypt.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/util/Arrays.h>
#include <java/util/Locale.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/IllegalBlockSizeException.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/ShortBufferException.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/RC2ParameterSpec.h>
#include <jcpp.h>

#undef CBC_MODE
#undef CFB_MODE
#undef CTR_MODE
#undef CTS_MODE
#undef DECRYPT_MODE
#undef ECB_MODE
#undef ENGLISH
#undef OFB_MODE
#undef PCBC_MODE
#undef UNWRAP_MODE

using $CipherBlockChaining = ::com::sun::crypto::provider::CipherBlockChaining;
using $CipherFeedback = ::com::sun::crypto::provider::CipherFeedback;
using $CipherTextStealing = ::com::sun::crypto::provider::CipherTextStealing;
using $ConstructKeys = ::com::sun::crypto::provider::ConstructKeys;
using $CounterMode = ::com::sun::crypto::provider::CounterMode;
using $ElectronicCodeBook = ::com::sun::crypto::provider::ElectronicCodeBook;
using $FeedbackCipher = ::com::sun::crypto::provider::FeedbackCipher;
using $ISO10126Padding = ::com::sun::crypto::provider::ISO10126Padding;
using $OutputFeedback = ::com::sun::crypto::provider::OutputFeedback;
using $PCBC = ::com::sun::crypto::provider::PCBC;
using $PKCS5Padding = ::com::sun::crypto::provider::PKCS5Padding;
using $Padding = ::com::sun::crypto::provider::Padding;
using $RC2Crypt = ::com::sun::crypto::provider::RC2Crypt;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $IllegalBlockSizeException = ::javax::crypto::IllegalBlockSizeException;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $ShortBufferException = ::javax::crypto::ShortBufferException;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $RC2ParameterSpec = ::javax::crypto::spec::RC2ParameterSpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _CipherCore_FieldInfo_[] = {
	{"buffer", "[B", nullptr, $PRIVATE, $field(CipherCore, buffer)},
	{"blockSize", "I", nullptr, $PRIVATE, $field(CipherCore, blockSize)},
	{"unitBytes", "I", nullptr, $PRIVATE, $field(CipherCore, unitBytes)},
	{"buffered", "I", nullptr, $PRIVATE, $field(CipherCore, buffered)},
	{"minBytes", "I", nullptr, $PRIVATE, $field(CipherCore, minBytes)},
	{"diffBlocksize", "I", nullptr, $PRIVATE, $field(CipherCore, diffBlocksize)},
	{"padding", "Lcom/sun/crypto/provider/Padding;", nullptr, $PRIVATE, $field(CipherCore, padding)},
	{"cipher", "Lcom/sun/crypto/provider/FeedbackCipher;", nullptr, $PRIVATE, $field(CipherCore, cipher)},
	{"cipherMode", "I", nullptr, $PRIVATE, $field(CipherCore, cipherMode)},
	{"decrypting", "Z", nullptr, $PRIVATE, $field(CipherCore, decrypting)},
	{"ECB_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, ECB_MODE)},
	{"CBC_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, CBC_MODE)},
	{"CFB_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, CFB_MODE)},
	{"OFB_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, OFB_MODE)},
	{"PCBC_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, PCBC_MODE)},
	{"CTR_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, CTR_MODE)},
	{"CTS_MODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CipherCore, CTS_MODE)},
	{}
};

$MethodInfo _CipherCore_MethodInfo_[] = {
	{"<init>", "(Lcom/sun/crypto/provider/SymmetricCipher;I)V", nullptr, 0, $method(CipherCore, init$, void, $SymmetricCipher*, int32_t)},
	{"checkOutputCapacity", "([BII)I", nullptr, $PRIVATE, $method(CipherCore, checkOutputCapacity, int32_t, $bytes*, int32_t, int32_t), "javax.crypto.ShortBufferException"},
	{"doFinal", "([BII)[B", nullptr, 0, $method(CipherCore, doFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "([BII[BI)I", nullptr, 0, $method(CipherCore, doFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException,javax.crypto.BadPaddingException"},
	{"endDoFinal", "()V", nullptr, $PRIVATE, $method(CipherCore, endDoFinal, void)},
	{"fillOutputBuffer", "([BI[BII[B)I", nullptr, $PRIVATE, $method(CipherCore, fillOutputBuffer, int32_t, $bytes*, int32_t, $bytes*, int32_t, int32_t, $bytes*), "javax.crypto.ShortBufferException,javax.crypto.BadPaddingException,javax.crypto.IllegalBlockSizeException"},
	{"finalNoPadding", "([BI[BII)I", nullptr, $PRIVATE, $method(CipherCore, finalNoPadding, int32_t, $bytes*, int32_t, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException"},
	{"getIV", "()[B", nullptr, 0, $method(CipherCore, getIV, $bytes*)},
	{"getKeyBytes", "(Ljava/security/Key;)[B", nullptr, $STATIC, $staticMethod(CipherCore, getKeyBytes, $bytes*, $Key*), "java.security.InvalidKeyException"},
	{"getNumOfUnit", "(Ljava/lang/String;II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CipherCore, getNumOfUnit, int32_t, $String*, int32_t, int32_t), "java.security.NoSuchAlgorithmException"},
	{"getOutputSize", "(I)I", nullptr, 0, $method(CipherCore, getOutputSize, int32_t, int32_t)},
	{"getOutputSizeByOperation", "(IZ)I", nullptr, $PRIVATE, $method(CipherCore, getOutputSizeByOperation, int32_t, int32_t, bool)},
	{"getParameters", "(Ljava/lang/String;)Ljava/security/AlgorithmParameters;", nullptr, 0, $method(CipherCore, getParameters, $AlgorithmParameters*, $String*)},
	{"init", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, 0, $method(CipherCore, init, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"init", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $method(CipherCore, init, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, 0, $method(CipherCore, init, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"prepareInputBuffer", "([BII[BI)[B", nullptr, $PRIVATE, $method(CipherCore, prepareInputBuffer, $bytes*, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException"},
	{"setMode", "(Ljava/lang/String;)V", nullptr, 0, $method(CipherCore, setMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"setPadding", "(Ljava/lang/String;)V", nullptr, 0, $method(CipherCore, setPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"unpad", "(II[B)I", nullptr, $PRIVATE, $method(CipherCore, unpad, int32_t, int32_t, int32_t, $bytes*), "javax.crypto.BadPaddingException"},
	{"unwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, 0, $method(CipherCore, unwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"update", "([BII)[B", nullptr, 0, $method(CipherCore, update, $bytes*, $bytes*, int32_t, int32_t)},
	{"update", "([BII[BI)I", nullptr, 0, $method(CipherCore, update, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"wrap", "(Ljava/security/Key;)[B", nullptr, 0, $method(CipherCore, wrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$ClassInfo _CipherCore_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.CipherCore",
	"java.lang.Object",
	nullptr,
	_CipherCore_FieldInfo_,
	_CipherCore_MethodInfo_
};

$Object* allocate$CipherCore($Class* clazz) {
	return $of($alloc(CipherCore));
}

void CipherCore::init$($SymmetricCipher* impl, int32_t blkSize) {
	$set(this, buffer, nullptr);
	this->blockSize = 0;
	this->unitBytes = 0;
	this->buffered = 0;
	this->minBytes = 0;
	this->diffBlocksize = 0;
	$set(this, padding, nullptr);
	$set(this, cipher, nullptr);
	this->cipherMode = CipherCore::ECB_MODE;
	this->decrypting = false;
	this->blockSize = blkSize;
	this->unitBytes = blkSize;
	this->diffBlocksize = blkSize;
	$set(this, buffer, $new($bytes, this->blockSize * 2));
	$set(this, cipher, $new($ElectronicCodeBook, impl));
	$set(this, padding, $new($PKCS5Padding, this->blockSize));
}

void CipherCore::setMode($String* mode) {
	$useLocalCurrentObjectStackCache();
	if (mode == nullptr) {
		$throwNew($NoSuchAlgorithmException, "null mode"_s);
	}
	$init($Locale);
	$var($String, modeUpperCase, $nc(mode)->toUpperCase($Locale::ENGLISH));
	if (modeUpperCase->equals("ECB"_s)) {
		return;
	}
	$var($SymmetricCipher, rawImpl, $nc(this->cipher)->getEmbeddedCipher());
	if (modeUpperCase->equals("CBC"_s)) {
		this->cipherMode = CipherCore::CBC_MODE;
		$set(this, cipher, $new($CipherBlockChaining, rawImpl));
	} else if (modeUpperCase->equals("CTS"_s)) {
		this->cipherMode = CipherCore::CTS_MODE;
		$set(this, cipher, $new($CipherTextStealing, rawImpl));
		this->minBytes = this->blockSize + 1;
		$set(this, padding, nullptr);
	} else if (modeUpperCase->equals("CTR"_s)) {
		this->cipherMode = CipherCore::CTR_MODE;
		$set(this, cipher, $new($CounterMode, rawImpl));
		this->unitBytes = 1;
		$set(this, padding, nullptr);
	} else if (modeUpperCase->startsWith("CFB"_s)) {
		this->cipherMode = CipherCore::CFB_MODE;
		this->unitBytes = getNumOfUnit(mode, "CFB"_s->length(), this->blockSize);
		$set(this, cipher, $new($CipherFeedback, rawImpl, this->unitBytes));
	} else if (modeUpperCase->startsWith("OFB"_s)) {
		this->cipherMode = CipherCore::OFB_MODE;
		this->unitBytes = getNumOfUnit(mode, "OFB"_s->length(), this->blockSize);
		$set(this, cipher, $new($OutputFeedback, rawImpl, this->unitBytes));
	} else if (modeUpperCase->equals("PCBC"_s)) {
		this->cipherMode = CipherCore::PCBC_MODE;
		$set(this, cipher, $new($PCBC, rawImpl));
	} else {
		$throwNew($NoSuchAlgorithmException, $$str({"Cipher mode: "_s, mode, " not found"_s}));
	}
}

int32_t CipherCore::getNumOfUnit($String* mode, int32_t offset, int32_t blockSize) {
	$useLocalCurrentObjectStackCache();
	int32_t result = blockSize;
	if ($nc(mode)->length() > offset) {
		int32_t numInt = 0;
		try {
			$var($Integer, num, $Integer::valueOf($(mode->substring(offset))));
			numInt = $nc(num)->intValue();
			result = numInt >> 3;
		} catch ($NumberFormatException& e) {
			$throwNew($NoSuchAlgorithmException, $$str({"Algorithm mode: "_s, mode, " not implemented"_s}));
		}
		if ((numInt % 8 != 0) || (result > blockSize)) {
			$throwNew($NoSuchAlgorithmException, $$str({"Invalid algorithm mode: "_s, mode}));
		}
	}
	return result;
}

void CipherCore::setPadding($String* paddingScheme) {
	$useLocalCurrentObjectStackCache();
	if (paddingScheme == nullptr) {
		$throwNew($NoSuchPaddingException, "null padding"_s);
	}
	if ($nc(paddingScheme)->equalsIgnoreCase("NoPadding"_s)) {
		$set(this, padding, nullptr);
	} else if (paddingScheme->equalsIgnoreCase("ISO10126Padding"_s)) {
		$set(this, padding, $new($ISO10126Padding, this->blockSize));
	} else if (paddingScheme->equalsIgnoreCase("PKCS5Padding"_s)) {
		$set(this, padding, $new($PKCS5Padding, this->blockSize));
	} else {
		$throwNew($NoSuchPaddingException, $$str({"Padding: "_s, paddingScheme, " not implemented"_s}));
	}
	if ((this->padding != nullptr) && ((this->cipherMode == CipherCore::CTR_MODE) || (this->cipherMode == CipherCore::CTS_MODE))) {
		$set(this, padding, nullptr);
		$var($String, modeStr, nullptr);
		switch (this->cipherMode) {
		case CipherCore::CTR_MODE:
			{
				$assign(modeStr, "CTR"_s);
				break;
			}
		case CipherCore::CTS_MODE:
			{
				$assign(modeStr, "CTS"_s);
				break;
			}
		default:
			{}
		}
		if (modeStr != nullptr) {
			$throwNew($NoSuchPaddingException, $$str({modeStr, " mode must be used with NoPadding"_s}));
		}
	}
}

int32_t CipherCore::getOutputSize(int32_t inputLen) {
	return getOutputSizeByOperation(inputLen, true);
}

int32_t CipherCore::getOutputSizeByOperation(int32_t inputLen, bool isDoFinal) {
	int32_t totalLen = this->buffered;
	totalLen = $Math::addExact(totalLen, inputLen);
	if (this->padding != nullptr && !this->decrypting) {
		if (this->unitBytes != this->blockSize) {
			if (totalLen < this->diffBlocksize) {
				totalLen = this->diffBlocksize;
			} else {
				int32_t residue = $mod((totalLen - this->diffBlocksize), this->blockSize);
				totalLen = $Math::addExact(totalLen, (this->blockSize - residue));
			}
		} else {
			totalLen = $Math::addExact(totalLen, $nc(this->padding)->padLength(totalLen));
		}
	}
	return totalLen;
}

$bytes* CipherCore::getIV() {
	$var($bytes, iv, $nc(this->cipher)->getIV());
	return (iv == nullptr) ? ($bytes*)nullptr : $cast($bytes, $nc(iv)->clone());
}

$AlgorithmParameters* CipherCore::getParameters($String* algName) {
	$useLocalCurrentObjectStackCache();
	if (this->cipherMode == CipherCore::ECB_MODE) {
		return nullptr;
	}
	$var($AlgorithmParameters, params, nullptr);
	$var($AlgorithmParameterSpec, spec, nullptr);
	$var($bytes, iv, getIV());
	if (iv == nullptr) {
		$assign(iv, $new($bytes, this->blockSize));
		$nc($($SunJCE::getRandom()))->nextBytes(iv);
	}
	if ($nc(algName)->equals("RC2"_s)) {
		$var($RC2Crypt, rawImpl, $cast($RC2Crypt, $nc(this->cipher)->getEmbeddedCipher()));
		$assign(spec, $new($RC2ParameterSpec, $nc(rawImpl)->getEffectiveKeyBits(), iv));
	} else {
		$assign(spec, $new($IvParameterSpec, iv));
	}
	try {
		$assign(params, $AlgorithmParameters::getInstance(algName, $(static_cast<$Provider*>($SunJCE::getInstance()))));
		$nc(params)->init(spec);
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, $$str({"Cannot find "_s, algName, " AlgorithmParameters implementation in SunJCE provider"_s}));
	} catch ($InvalidParameterSpecException& ipse) {
		$throwNew($RuntimeException, $$str({$nc($of(spec))->getClass(), " not supported"_s}));
	}
	return params;
}

void CipherCore::init(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		init(opmode, key, ($AlgorithmParameterSpec*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& e) {
		$throwNew($InvalidKeyException, $(e->getMessage()));
	}
}

void CipherCore::init(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($SecureRandom, random, random$renamed);
	this->decrypting = (opmode == $Cipher::DECRYPT_MODE) || (opmode == $Cipher::UNWRAP_MODE);
	$var($bytes, keyBytes, getKeyBytes(key));
	$var($bytes, ivBytes, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (params != nullptr) {
				if ($instanceOf($IvParameterSpec, params)) {
					$assign(ivBytes, $nc(($cast($IvParameterSpec, params)))->getIV());
					if ((ivBytes == nullptr) || ($nc(ivBytes)->length != this->blockSize)) {
						$throwNew($InvalidAlgorithmParameterException, $$str({"Wrong IV length: must be "_s, $$str(this->blockSize), " bytes long"_s}));
					}
				} else if ($instanceOf($RC2ParameterSpec, params)) {
					$assign(ivBytes, $nc(($cast($RC2ParameterSpec, params)))->getIV());
					if ((ivBytes != nullptr) && (ivBytes->length != this->blockSize)) {
						$throwNew($InvalidAlgorithmParameterException, $$str({"Wrong IV length: must be "_s, $$str(this->blockSize), " bytes long"_s}));
					}
				} else {
					$throwNew($InvalidAlgorithmParameterException, $$str({"Unsupported parameter: "_s, params}));
				}
			}
			if (this->cipherMode == CipherCore::ECB_MODE) {
				if (ivBytes != nullptr) {
					$throwNew($InvalidAlgorithmParameterException, "ECB mode cannot use IV"_s);
				}
			} else if (ivBytes == nullptr) {
				if (this->decrypting) {
					$throwNew($InvalidAlgorithmParameterException, "Parameters missing"_s);
				}
				if (random == nullptr) {
					$assign(random, $SunJCE::getRandom());
				}
				$assign(ivBytes, $new($bytes, this->blockSize));
				$nc(random)->nextBytes(ivBytes);
			}
			this->buffered = 0;
			this->diffBlocksize = this->blockSize;
			$var($String, algorithm, $nc(key)->getAlgorithm());
			$nc(this->cipher)->init(this->decrypting, algorithm, keyBytes, ivBytes);
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

void CipherCore::init(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameterSpec, spec, nullptr);
	$var($String, paramType, nullptr);
	if (params != nullptr) {
		try {
			$assign(paramType, "IV"_s);
			$load($IvParameterSpec);
			$assign(spec, params->getParameterSpec($IvParameterSpec::class$));
		} catch ($InvalidParameterSpecException& ipse) {
			$throwNew($InvalidAlgorithmParameterException, $$str({"Wrong parameter type: "_s, paramType, " expected"_s}));
		}
	}
	init(opmode, key, spec, random);
}

$bytes* CipherCore::getKeyBytes($Key* key) {
	$useLocalCurrentObjectStackCache();
	if (key == nullptr) {
		$throwNew($InvalidKeyException, "No key given"_s);
	}
	if (!"RAW"_s->equalsIgnoreCase($($nc(key)->getFormat()))) {
		$throwNew($InvalidKeyException, "Wrong format: RAW bytes needed"_s);
	}
	$var($bytes, keyBytes, $nc(key)->getEncoded());
	if (keyBytes == nullptr) {
		$throwNew($InvalidKeyException, "RAW key bytes missing"_s);
	}
	return keyBytes;
}

$bytes* CipherCore::update($bytes* input, int32_t inputOffset, int32_t inputLen) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, output, nullptr);
	try {
		$assign(output, $new($bytes, getOutputSizeByOperation(inputLen, false)));
		int32_t len = update(input, inputOffset, inputLen, output, 0);
		if (len == output->length) {
			return output;
		} else {
			$var($bytes, copy, $Arrays::copyOf(output, len));
			if (this->decrypting) {
				$Arrays::fill(output, (int8_t)0);
			}
			return copy;
		}
	} catch ($ShortBufferException& e) {
		$throwNew($ProviderException, "Unexpected exception"_s, e);
	}
	$shouldNotReachHere();
}

int32_t CipherCore::update($bytes* input$renamed, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, input, input$renamed);
	int32_t len = $Math::addExact(this->buffered, inputLen);
	len -= this->minBytes;
	if (this->padding != nullptr && this->decrypting) {
		len -= this->blockSize;
	}
	len = (len > 0 ? (len - ($mod(len, this->unitBytes))) : 0);
	if (output == nullptr || ($nc(output)->length - outputOffset) < len) {
		$throwNew($ShortBufferException, $$str({"Output buffer must be (at least) "_s, $$str(len), " bytes long"_s}));
	}
	int32_t outLen = 0;
	if (len != 0) {
		if ((input == output) && (outputOffset - inputOffset < inputLen) && (inputOffset - outputOffset < $nc(this->buffer)->length)) {
			$assign(input, $Arrays::copyOfRange(input, inputOffset, $Math::addExact(inputOffset, inputLen)));
			inputOffset = 0;
		}
		if (len <= this->buffered) {
			if (this->decrypting) {
				outLen = $nc(this->cipher)->decrypt(this->buffer, 0, len, output, outputOffset);
			} else {
				outLen = $nc(this->cipher)->encrypt(this->buffer, 0, len, output, outputOffset);
			}
			this->buffered -= len;
			if (this->buffered != 0) {
				$System::arraycopy(this->buffer, len, this->buffer, 0, this->buffered);
			}
		} else {
			int32_t inputConsumed = len - this->buffered;
			int32_t temp = 0;
			if (this->buffered > 0) {
				int32_t bufferCapacity = $nc(this->buffer)->length - this->buffered;
				if (bufferCapacity != 0) {
					temp = $Math::min(bufferCapacity, inputConsumed);
					if (this->unitBytes != this->blockSize) {
						temp -= ($mod($Math::addExact(this->buffered, temp), this->unitBytes));
					}
					$System::arraycopy(input, inputOffset, this->buffer, this->buffered, temp);
					inputOffset = $Math::addExact(inputOffset, temp);
					inputConsumed -= temp;
					inputLen -= temp;
					this->buffered = $Math::addExact(this->buffered, temp);
				}
				if (this->decrypting) {
					outLen = $nc(this->cipher)->decrypt(this->buffer, 0, this->buffered, output, outputOffset);
				} else {
					outLen = $nc(this->cipher)->encrypt(this->buffer, 0, this->buffered, output, outputOffset);
					$Arrays::fill(this->buffer, (int8_t)0);
				}
				outputOffset = $Math::addExact(outputOffset, outLen);
				this->buffered = 0;
			}
			if (inputConsumed > 0) {
				if (this->decrypting) {
					outLen += $nc(this->cipher)->decrypt(input, inputOffset, inputConsumed, output, outputOffset);
				} else {
					outLen += $nc(this->cipher)->encrypt(input, inputOffset, inputConsumed, output, outputOffset);
				}
				inputOffset += inputConsumed;
				inputLen -= inputConsumed;
			}
		}
		if (this->unitBytes != this->blockSize) {
			if (len < this->diffBlocksize) {
				this->diffBlocksize -= len;
			} else {
				this->diffBlocksize = this->blockSize - ($mod((len - this->diffBlocksize), this->blockSize));
			}
		}
	}
	if (inputLen > 0) {
		$System::arraycopy(input, inputOffset, this->buffer, this->buffered, inputLen);
		this->buffered = $Math::addExact(this->buffered, inputLen);
	}
	return outLen;
}

$bytes* CipherCore::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($bytes, output, $new($bytes, getOutputSizeByOperation(inputLen, true)));
		$var($bytes, finalBuf, prepareInputBuffer(input, inputOffset, inputLen, output, 0));
		int32_t finalOffset = (finalBuf == input) ? inputOffset : 0;
		int32_t finalBufLen = (finalBuf == input) ? inputLen : $nc(finalBuf)->length;
		int32_t outLen = fillOutputBuffer(finalBuf, finalOffset, output, 0, finalBufLen, input);
		endDoFinal();
		if (outLen < output->length) {
			$var($bytes, copy, $Arrays::copyOf(output, outLen));
			if (this->decrypting) {
				$Arrays::fill(output, (int8_t)0);
			}
			return copy;
		} else {
			return output;
		}
	} catch ($ShortBufferException& e) {
		$throwNew($ProviderException, "Unexpected exception"_s, e);
	}
	$shouldNotReachHere();
}

int32_t CipherCore::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	$useLocalCurrentObjectStackCache();
	int32_t estOutSize = getOutputSizeByOperation(inputLen, true);
	int32_t outputCapacity = checkOutputCapacity(output, outputOffset, estOutSize);
	int32_t offset = outputOffset;
	$var($bytes, finalBuf, prepareInputBuffer(input, inputOffset, inputLen, output, outputOffset));
	$var($bytes, internalOutput, nullptr);
	int32_t finalOffset = (finalBuf == input) ? inputOffset : 0;
	int32_t finalBufLen = (finalBuf == input) ? inputLen : $nc(finalBuf)->length;
	if (this->decrypting) {
		if (outputCapacity < estOutSize) {
			$nc(this->cipher)->save();
		}
		$assign(internalOutput, $new($bytes, estOutSize));
		offset = 0;
	}
	$var($bytes, outBuffer, (internalOutput != nullptr) ? internalOutput : output);
	int32_t outLen = fillOutputBuffer(finalBuf, finalOffset, outBuffer, offset, finalBufLen, input);
	if (this->decrypting) {
		if (outputCapacity < outLen) {
			$nc(this->cipher)->restore();
			$throwNew($ShortBufferException, $$str({"Output buffer too short: "_s, $$str((outputCapacity)), " bytes given, "_s, $$str(outLen), " bytes needed"_s}));
		}
		if (internalOutput != nullptr) {
			$System::arraycopy(internalOutput, 0, output, outputOffset, outLen);
			$Arrays::fill(internalOutput, (int8_t)0);
		}
	}
	endDoFinal();
	return outLen;
}

void CipherCore::endDoFinal() {
	this->buffered = 0;
	this->diffBlocksize = this->blockSize;
	if (this->cipherMode != CipherCore::ECB_MODE) {
		$nc(this->cipher)->reset();
	}
}

int32_t CipherCore::unpad(int32_t outLen, int32_t off, $bytes* outWithPadding) {
	int32_t padStart = $nc(this->padding)->unpad(outWithPadding, off, outLen);
	if (padStart < 0) {
		$throwNew($BadPaddingException, "Given final block not properly padded. Such issues can arise if a bad key is used during decryption."_s);
	}
	return padStart - off;
}

$bytes* CipherCore::prepareInputBuffer($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $Math::addExact(this->buffered, inputLen);
	int32_t totalLen = len;
	int32_t paddingLen = 0;
	if (this->unitBytes != this->blockSize) {
		if (totalLen < this->diffBlocksize) {
			paddingLen = this->diffBlocksize - totalLen;
		} else {
			paddingLen = this->blockSize - ($mod((totalLen - this->diffBlocksize), this->blockSize));
		}
	} else if (this->padding != nullptr) {
		paddingLen = $nc(this->padding)->padLength(totalLen);
	}
	if (this->decrypting && (this->padding != nullptr) && (paddingLen > 0) && (paddingLen != this->blockSize)) {
		$throwNew($IllegalBlockSizeException, $$str({"Input length must be multiple of "_s, $$str(this->blockSize), " when decrypting with padded cipher"_s}));
	}
	if ((this->buffered != 0) || (!this->decrypting && this->padding != nullptr) || ((input == output) && (outputOffset - inputOffset < inputLen) && (inputOffset - outputOffset < $nc(this->buffer)->length))) {
		$var($bytes, finalBuf, nullptr);
		if (this->decrypting || this->padding == nullptr) {
			paddingLen = 0;
		}
		$assign(finalBuf, $new($bytes, $Math::addExact(len, paddingLen)));
		if (this->buffered != 0) {
			$System::arraycopy(this->buffer, 0, finalBuf, 0, this->buffered);
			if (!this->decrypting) {
				$Arrays::fill(this->buffer, (int8_t)0);
			}
		}
		if (inputLen != 0) {
			$System::arraycopy(input, inputOffset, finalBuf, this->buffered, inputLen);
		}
		if (paddingLen != 0) {
			$nc(this->padding)->padWithLen(finalBuf, $Math::addExact(this->buffered, inputLen), paddingLen);
		}
		return finalBuf;
	}
	return input;
}

int32_t CipherCore::fillOutputBuffer($bytes* finalBuf, int32_t finalOffset, $bytes* output, int32_t outOfs, int32_t finalBufLen, $bytes* input) {
	int32_t len = 0;
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			len = finalNoPadding(finalBuf, finalOffset, output, outOfs, finalBufLen);
			if (this->decrypting && this->padding != nullptr) {
				len = unpad(len, outOfs, output);
			}
			var$2 = len;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (!this->decrypting && finalBuf != input) {
				$Arrays::fill(finalBuf, (int8_t)0);
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

int32_t CipherCore::checkOutputCapacity($bytes* output, int32_t outputOffset, int32_t estOutSize) {
	$useLocalCurrentObjectStackCache();
	int32_t outputCapacity = $nc(output)->length - outputOffset;
	int32_t minOutSize = this->decrypting ? (estOutSize - this->blockSize) : estOutSize;
	if ((output == nullptr) || (outputCapacity < minOutSize)) {
		$throwNew($ShortBufferException, $$str({"Output buffer must be (at least) "_s, $$str(minOutSize), " bytes long"_s}));
	}
	return outputCapacity;
}

int32_t CipherCore::finalNoPadding($bytes* in, int32_t inOfs, $bytes* out, int32_t outOfs, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (in == nullptr || len == 0) {
		return 0;
	}
	if ((this->cipherMode != CipherCore::CFB_MODE) && (this->cipherMode != CipherCore::OFB_MODE) && (($mod(len, this->unitBytes)) != 0) && (this->cipherMode != CipherCore::CTS_MODE)) {
		if (this->padding != nullptr) {
			$throwNew($IllegalBlockSizeException, $$str({"Input length (with padding) not multiple of "_s, $$str(this->unitBytes), " bytes"_s}));
		} else {
			$throwNew($IllegalBlockSizeException, $$str({"Input length not multiple of "_s, $$str(this->unitBytes), " bytes"_s}));
		}
	}
	int32_t outLen = 0;
	if (this->decrypting) {
		outLen = $nc(this->cipher)->decryptFinal(in, inOfs, len, out, outOfs);
	} else {
		outLen = $nc(this->cipher)->encryptFinal(in, inOfs, len, out, outOfs);
	}
	return outLen;
}

$bytes* CipherCore::wrap($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, result, nullptr);
	try {
		$var($bytes, encodedKey, $nc(key)->getEncoded());
		if ((encodedKey == nullptr) || ($nc(encodedKey)->length == 0)) {
			$throwNew($InvalidKeyException, "Cannot get an encoding of the key to be wrapped"_s);
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				$assign(result, doFinal(encodedKey, 0, $nc(encodedKey)->length));
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$Arrays::fill(encodedKey, (int8_t)0);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($BadPaddingException& e) {
	}
	return result;
}

$Key* CipherCore::unwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encodedKey, nullptr);
	try {
		$assign(encodedKey, doFinal(wrappedKey, 0, $nc(wrappedKey)->length));
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

CipherCore::CipherCore() {
}

$Class* CipherCore::load$($String* name, bool initialize) {
	$loadClass(CipherCore, name, initialize, &_CipherCore_ClassInfo_, allocate$CipherCore);
	return class$;
}

$Class* CipherCore::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com