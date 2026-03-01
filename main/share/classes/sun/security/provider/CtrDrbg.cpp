#include <sun/security/provider/CtrDrbg.h>

#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/SecureRandomParameters.h>
#include <java/util/Arrays.h>
#include <java/util/HexFormat.h>
#include <java/util/Locale.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/provider/AbstractDrbg.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef AES_LIMIT
#undef DEFAULT_STRENGTH
#undef ENCRYPT_MODE
#undef ROOT

using $byteArray2 = $Array<int8_t, 2>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $SecureRandomParameters = ::java::security::SecureRandomParameters;
using $Arrays = ::java::util::Arrays;
using $HexFormat = ::java::util::HexFormat;
using $Locale = ::java::util::Locale;
using $Cipher = ::javax::crypto::Cipher;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $AbstractDrbg = ::sun::security::provider::AbstractDrbg;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _CtrDrbg_FieldInfo_[] = {
	{"AES_LIMIT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CtrDrbg, AES_LIMIT)},
	{"cipher", "Ljavax/crypto/Cipher;", nullptr, $PRIVATE, $field(CtrDrbg, cipher)},
	{"cipherAlg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CtrDrbg, cipherAlg)},
	{"keyAlg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CtrDrbg, keyAlg)},
	{"ctrLen", "I", nullptr, $PRIVATE, $field(CtrDrbg, ctrLen)},
	{"blockLen", "I", nullptr, $PRIVATE, $field(CtrDrbg, blockLen)},
	{"keyLen", "I", nullptr, $PRIVATE, $field(CtrDrbg, keyLen)},
	{"seedLen", "I", nullptr, $PRIVATE, $field(CtrDrbg, seedLen)},
	{"v", "[B", nullptr, $PRIVATE, $field(CtrDrbg, v)},
	{"k", "[B", nullptr, $PRIVATE, $field(CtrDrbg, k)},
	{}
};

$MethodInfo _CtrDrbg_MethodInfo_[] = {
	{"<init>", "(Ljava/security/SecureRandomParameters;)V", nullptr, $PUBLIC, $method(CtrDrbg, init$, void, $SecureRandomParameters*)},
	{"addOne", "([BI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CtrDrbg, addOne, void, $bytes*, int32_t)},
	{"alg2strength", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CtrDrbg, alg2strength, int32_t, $String*)},
	{"bcc", "([B[[B)[B", nullptr, $PRIVATE | $TRANSIENT, $method(CtrDrbg, bcc, $bytes*, $bytes*, $byteArray2*)},
	{"chooseAlgorithmAndStrength", "()V", nullptr, $PROTECTED, $virtualMethod(CtrDrbg, chooseAlgorithmAndStrength, void)},
	{"df", "([B)[B", nullptr, $PRIVATE, $method(CtrDrbg, df, $bytes*, $bytes*)},
	{"generateAlgorithm", "([B[B)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(CtrDrbg, generateAlgorithm, void, $bytes*, $bytes*)},
	{"initEngine", "()V", nullptr, $PROTECTED, $virtualMethod(CtrDrbg, initEngine, void)},
	{"instantiateAlgorithm", "([B)V", nullptr, $PROTECTED, $virtualMethod(CtrDrbg, instantiateAlgorithm, void, $bytes*)},
	{"reseedAlgorithm", "([B[B)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(CtrDrbg, reseedAlgorithm, void, $bytes*, $bytes*)},
	{"status", "()V", nullptr, $PRIVATE, $method(CtrDrbg, status, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CtrDrbg, toString, $String*)},
	{"update", "([B)V", nullptr, $PRIVATE, $method(CtrDrbg, update, void, $bytes*)},
	{}
};

$ClassInfo _CtrDrbg_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.CtrDrbg",
	"sun.security.provider.AbstractDrbg",
	nullptr,
	_CtrDrbg_FieldInfo_,
	_CtrDrbg_MethodInfo_
};

$Object* allocate$CtrDrbg($Class* clazz) {
	return $of($alloc(CtrDrbg));
}

int32_t CtrDrbg::AES_LIMIT = 0;

void CtrDrbg::init$($SecureRandomParameters* params) {
	$AbstractDrbg::init$();
	$set(this, mechName, "CTR_DRBG"_s);
	configure(params);
}

int32_t CtrDrbg::alg2strength($String* algorithm) {
	$init(CtrDrbg);
	$useLocalCurrentObjectStackCache();
	{
		$init($Locale);
		$var($String, s2192$, $nc(algorithm)->toUpperCase($Locale::ROOT));
		int32_t tmp2192$ = -1;
		switch (s2192$->hashCode()) {
		case (int32_t)0xE8DA4019:
			{
				if (s2192$->equals("AES-128"_s)) {
					tmp2192$ = 0;
				}
				break;
			}
		case (int32_t)0xE8DA40EC:
			{
				if (s2192$->equals("AES-192"_s)) {
					tmp2192$ = 1;
				}
				break;
			}
		case (int32_t)0xE8DA4435:
			{
				if (s2192$->equals("AES-256"_s)) {
					tmp2192$ = 2;
				}
				break;
			}
		}
		switch (tmp2192$) {
		case 0:
			{
				return 128;
			}
		case 1:
			{
				return 192;
			}
		case 2:
			{
				return 256;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({algorithm, " not supported in CTR_DBRG"_s}));
			}
		}
	}
}

void CtrDrbg::chooseAlgorithmAndStrength() {
	$useLocalCurrentObjectStackCache();
	if (this->requestedAlgorithm != nullptr) {
		$init($Locale);
		$set(this, algorithm, $nc(this->requestedAlgorithm)->toUpperCase($Locale::ROOT));
		int32_t supportedStrength = alg2strength(this->algorithm);
		if (this->requestedInstantiationSecurityStrength >= 0) {
			int32_t tryStrength = getStandardStrength(this->requestedInstantiationSecurityStrength);
			if (tryStrength > supportedStrength) {
				$throwNew($IllegalArgumentException, $$str({this->algorithm, " does not support strength "_s, $$str(this->requestedInstantiationSecurityStrength)}));
			}
			this->securityStrength = tryStrength;
		} else {
			this->securityStrength = ($AbstractDrbg::DEFAULT_STRENGTH > supportedStrength) ? supportedStrength : $AbstractDrbg::DEFAULT_STRENGTH;
		}
	} else {
		int32_t tryStrength = (this->requestedInstantiationSecurityStrength < 0) ? $AbstractDrbg::DEFAULT_STRENGTH : this->requestedInstantiationSecurityStrength;
		tryStrength = getStandardStrength(tryStrength);
		if (tryStrength <= 128 && CtrDrbg::AES_LIMIT < 256) {
			$set(this, algorithm, "AES-128"_s);
		} else if (CtrDrbg::AES_LIMIT >= 256) {
			$set(this, algorithm, "AES-256"_s);
		} else {
			$throwNew($IllegalArgumentException, $$str({"unsupported strength "_s, $$str(this->requestedInstantiationSecurityStrength)}));
		}
		this->securityStrength = tryStrength;
	}
	{
		$init($Locale);
		$var($String, s4292$, $nc(this->algorithm)->toUpperCase($Locale::ROOT));
		int32_t tmp4292$ = -1;
		switch (s4292$->hashCode()) {
		case (int32_t)0xE8DA4019:
			{
				if (s4292$->equals("AES-128"_s)) {
					tmp4292$ = 0;
				}
				break;
			}
		case (int32_t)0xE8DA40EC:
			{
				if (s4292$->equals("AES-192"_s)) {
					tmp4292$ = 1;
				}
				break;
			}
		case (int32_t)0xE8DA4435:
			{
				if (s4292$->equals("AES-256"_s)) {
					tmp4292$ = 2;
				}
				break;
			}
		}
		switch (tmp4292$) {
		case 0:
			{}
		case 1:
			{}
		case 2:
			{
				$set(this, keyAlg, "AES"_s);
				$set(this, cipherAlg, "AES/ECB/NoPadding"_s);
				{
					$var($String, s4529$, this->algorithm);
					int32_t tmp4529$ = -1;
					switch ($nc(s4529$)->hashCode()) {
					case (int32_t)0xE8DA4019:
						{
							if (s4529$->equals("AES-128"_s)) {
								tmp4529$ = 0;
							}
							break;
						}
					case (int32_t)0xE8DA40EC:
						{
							if (s4529$->equals("AES-192"_s)) {
								tmp4529$ = 1;
							}
							break;
						}
					case (int32_t)0xE8DA4435:
						{
							if (s4529$->equals("AES-256"_s)) {
								tmp4529$ = 2;
							}
							break;
						}
					}
					switch (tmp4529$) {
					case 0:
						{
							this->keyLen = 128 / 8;
							break;
						}
					case 1:
						{
							this->keyLen = 192 / 8;
							if (CtrDrbg::AES_LIMIT < 192) {
								$throwNew($IllegalArgumentException, $$str({this->algorithm, " not available (because policy) in CTR_DBRG"_s}));
							}
							break;
						}
					case 2:
						{
							this->keyLen = 256 / 8;
							if (CtrDrbg::AES_LIMIT < 256) {
								$throwNew($IllegalArgumentException, $$str({this->algorithm, " not available (because policy) in CTR_DBRG"_s}));
							}
							break;
						}
					default:
						{
							$throwNew($IllegalArgumentException, $$str({this->algorithm, " not supported in CTR_DBRG"_s}));
						}
					}
				}
				this->blockLen = 128 / 8;
				break;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({this->algorithm, " not supported in CTR_DBRG"_s}));
			}
		}
	}
	this->seedLen = this->blockLen + this->keyLen;
	this->ctrLen = this->blockLen;
	if (this->usedf) {
		this->minLength = this->securityStrength / 8;
	} else {
		this->minLength = (this->maxLength = (this->maxPersonalizationStringLength = (this->maxAdditionalInputLength = this->seedLen)));
	}
}

void CtrDrbg::initEngine() {
	$useLocalCurrentObjectStackCache();
	try {
		$set(this, cipher, $Cipher::getInstance(this->cipherAlg, "SunJCE"_s));
	} catch ($NoSuchProviderException& e) {
		try {
			$set(this, cipher, $Cipher::getInstance(this->cipherAlg));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->cipherAlg, " not available."_s}), exc);
		} catch ($NoSuchPaddingException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->cipherAlg, " not available."_s}), exc);
		}
	} catch ($NoSuchAlgorithmException& e) {
		try {
			$set(this, cipher, $Cipher::getInstance(this->cipherAlg));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->cipherAlg, " not available."_s}), exc);
		} catch ($NoSuchPaddingException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->cipherAlg, " not available."_s}), exc);
		}
	} catch ($NoSuchPaddingException& e) {
		try {
			$set(this, cipher, $Cipher::getInstance(this->cipherAlg));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->cipherAlg, " not available."_s}), exc);
		} catch ($NoSuchPaddingException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->cipherAlg, " not available."_s}), exc);
		}
	}
}

void CtrDrbg::status() {
	$useLocalCurrentObjectStackCache();
	$init($AbstractDrbg);
	if ($AbstractDrbg::debug != nullptr) {
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"Key = "_s, $($nc($($HexFormat::of()))->formatHex(this->k))}));
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"V   = "_s, $($nc($($HexFormat::of()))->formatHex(this->v))}));
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"reseed counter = "_s, $$str(this->reseedCounter)}));
	}
}

void CtrDrbg::update($bytes* input) {
	$useLocalCurrentObjectStackCache();
	if ($nc(input)->length != this->seedLen) {
		$throwNew($IllegalArgumentException, $$str({"input length not seedLen: "_s, $$str(input->length)}));
	}
	try {
		int32_t m = $div((this->seedLen + this->blockLen - 1), this->blockLen);
		$var($bytes, temp, $new($bytes, m * this->blockLen));
		for (int32_t i = 0; i < m; ++i) {
			addOne(this->v, this->ctrLen);
			$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>($$new($SecretKeySpec, this->k, this->keyAlg)));
			$nc(this->cipher)->doFinal(this->v, 0, this->blockLen, temp, i * this->blockLen);
		}
		$assign(temp, $Arrays::copyOf(temp, this->seedLen));
		for (int32_t i = 0; i < this->seedLen; ++i) {
			(*temp)[i] ^= $nc(input)->get(i);
		}
		$set(this, k, $Arrays::copyOf(temp, this->keyLen));
		$set(this, v, $Arrays::copyOfRange(temp, this->seedLen - this->blockLen, this->seedLen));
	} catch ($GeneralSecurityException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
}

void CtrDrbg::instantiateAlgorithm($bytes* ei) {
	$init($AbstractDrbg);
	if ($AbstractDrbg::debug != nullptr) {
		$nc($AbstractDrbg::debug)->println($of(this), "instantiate"_s);
	}
	$var($bytes, more, nullptr);
	if (this->usedf) {
		if (this->personalizationString == nullptr) {
			$assign(more, this->nonce);
		} else {
			if ($nc(this->nonce)->length + $nc(this->personalizationString)->length < 0) {
				$throwNew($IllegalArgumentException, "nonce plus personalization string is too long"_s);
			}
			$assign(more, $Arrays::copyOf(this->nonce, $nc(this->nonce)->length + $nc(this->personalizationString)->length));
			$System::arraycopy(this->personalizationString, 0, more, $nc(this->nonce)->length, $nc(this->personalizationString)->length);
		}
	} else {
		$assign(more, this->personalizationString);
	}
	reseedAlgorithm(ei, more);
}

$bytes* CtrDrbg::df($bytes* input) {
	$useLocalCurrentObjectStackCache();
	int32_t l = $nc(input)->length;
	int32_t n = this->seedLen;
	$var($bytes, ln, $new($bytes, 8));
	ln->set(0, (int8_t)(l >> 24));
	ln->set(1, (int8_t)(l >> 16));
	ln->set(2, (int8_t)(l >> 8));
	ln->set(3, (int8_t)(l));
	ln->set(4, (int8_t)(n >> 24));
	ln->set(5, (int8_t)(n >> 16));
	ln->set(6, (int8_t)(n >> 8));
	ln->set(7, (int8_t)(n));
	$var($bytes, k, $new($bytes, this->keyLen));
	for (int32_t i = 0; i < k->length; ++i) {
		k->set(i, (int8_t)i);
	}
	$var($bytes, temp, $new($bytes, this->seedLen));
	for (int32_t i = 0; i * this->blockLen < temp->length; ++i) {
		$var($bytes, iv, $new($bytes, this->blockLen));
		iv->set(0, (int8_t)(i >> 24));
		iv->set(1, (int8_t)(i >> 16));
		iv->set(2, (int8_t)(i >> 8));
		iv->set(3, (int8_t)(i));
		int32_t tailLen = temp->length - this->blockLen * i;
		if (tailLen > this->blockLen) {
			tailLen = this->blockLen;
		}
		$System::arraycopy($(bcc(k, $$new($byteArray2, {
			iv,
			ln,
			input,
			$$new($bytes, {(int8_t)128})
		}))), 0, temp, this->blockLen * i, tailLen);
	}
	$assign(k, $Arrays::copyOf(temp, this->keyLen));
	$var($bytes, x, $Arrays::copyOfRange(temp, this->keyLen, temp->length));
	for (int32_t i = 0; i * this->blockLen < this->seedLen; ++i) {
		try {
			$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>($$new($SecretKeySpec, k, this->keyAlg)));
			int32_t tailLen = temp->length - this->blockLen * i;
			if (tailLen > this->blockLen) {
				tailLen = this->blockLen;
			}
			$assign(x, $nc(this->cipher)->doFinal(x));
			$System::arraycopy(x, 0, temp, this->blockLen * i, tailLen);
		} catch ($GeneralSecurityException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	return temp;
}

$bytes* CtrDrbg::bcc($bytes* k, $byteArray2* data) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, chain, $new($bytes, this->blockLen));
	int32_t n1 = 0;
	int32_t n2 = 0;
	while (n1 < $nc(data)->length) {
		int32_t j = 0;
		bool out$break = false;
		for (j = 0; j < this->blockLen; ++j) {
			while (n2 >= $nc(data->get(n1))->length) {
				++n1;
				if (n1 >= data->length) {
					out$break = true;
					break;
				}
				n2 = 0;
			}
			if (out$break) {
				break;
			}
			(*$nc(chain))[j] ^= $nc(data->get(n1))->get(n2);
			++n2;
		}
		if (j == 0) {
			break;
		}
		try {
			$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>($$new($SecretKeySpec, k, this->keyAlg)));
			$assign(chain, $nc(this->cipher)->doFinal(chain));
		} catch ($GeneralSecurityException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	return chain;
}

void CtrDrbg::reseedAlgorithm($bytes* ei$renamed, $bytes* additionalInput) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($bytes, ei, ei$renamed);
		if (this->usedf) {
			if (additionalInput != nullptr) {
				if ($nc(ei)->length + additionalInput->length < 0) {
					$throwNew($IllegalArgumentException, "entropy plus additional input is too long"_s);
				}
				$var($bytes, temp, $Arrays::copyOf(ei, $nc(ei)->length + additionalInput->length));
				$System::arraycopy(additionalInput, 0, temp, $nc(ei)->length, additionalInput->length);
				$assign(ei, temp);
			}
			$assign(ei, df(ei));
		} else if (additionalInput != nullptr) {
			for (int32_t i = 0; i < additionalInput->length; ++i) {
				(*$nc(ei))[i] ^= additionalInput->get(i);
			}
		}
		if (this->v == nullptr) {
			$set(this, k, $new($bytes, this->keyLen));
			$set(this, v, $new($bytes, this->blockLen));
		}
		update(ei);
		this->reseedCounter = 1;
	}
}

void CtrDrbg::addOne($bytes* data, int32_t len) {
	$init(CtrDrbg);
	for (int32_t i = 0; i < len; ++i) {
		++(*$nc(data))[data->length - 1 - i];
		if (data->get(data->length - 1 - i) != 0) {
			break;
		}
	}
}

void CtrDrbg::generateAlgorithm($bytes* result, $bytes* additionalInput$renamed) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($bytes, additionalInput, additionalInput$renamed);
		$init($AbstractDrbg);
		if ($AbstractDrbg::debug != nullptr) {
			$nc($AbstractDrbg::debug)->println($of(this), "generateAlgorithm"_s);
		}
		if (additionalInput != nullptr) {
			if (this->usedf) {
				$assign(additionalInput, df(additionalInput));
			} else {
				$assign(additionalInput, $Arrays::copyOf(additionalInput, this->seedLen));
			}
			update(additionalInput);
		} else {
			$assign(additionalInput, $new($bytes, this->seedLen));
		}
		int32_t pos = 0;
		int32_t len = $nc(result)->length;
		while (len > 0) {
			addOne(this->v, this->ctrLen);
			try {
				$nc(this->cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>($$new($SecretKeySpec, this->k, this->keyAlg)));
				if (len > this->blockLen) {
					$nc(this->cipher)->doFinal(this->v, 0, this->blockLen, result, pos);
				} else {
					$var($bytes, out, $nc(this->cipher)->doFinal(this->v));
					$System::arraycopy(out, 0, result, pos, len);
					$Arrays::fill(out, (int8_t)0);
				}
			} catch ($GeneralSecurityException& e) {
				$throwNew($InternalError, static_cast<$Throwable*>(e));
			}
			len -= this->blockLen;
			if (len <= 0) {
				break;
			}
			pos += this->blockLen;
		}
		update(additionalInput);
		++this->reseedCounter;
	}
}

$String* CtrDrbg::toString() {
	return $str({$($AbstractDrbg::toString()), ","_s, (this->usedf ? "use_df"_s : "no_df"_s)});
}

void clinit$CtrDrbg($Class* class$) {
	{
		try {
			CtrDrbg::AES_LIMIT = $Cipher::getMaxAllowedKeyLength("AES"_s);
		} catch ($Exception& e) {
			$throwNew($AssertionError, "Cannot detect AES"_s, e);
		}
	}
}

CtrDrbg::CtrDrbg() {
}

$Class* CtrDrbg::load$($String* name, bool initialize) {
	$loadClass(CtrDrbg, name, initialize, &_CtrDrbg_ClassInfo_, clinit$CtrDrbg, allocate$CtrDrbg);
	return class$;
}

$Class* CtrDrbg::class$ = nullptr;

		} // provider
	} // security
} // sun