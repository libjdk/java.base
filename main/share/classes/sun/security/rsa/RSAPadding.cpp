#include <sun/security/rsa/RSAPadding.h>

#include <java/lang/AssertionError.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/MGF1ParameterSpec.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/spec/OAEPParameterSpec.h>
#include <javax/crypto/spec/PSource$PSpecified.h>
#include <javax/crypto/spec/PSource.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/rsa/MGF1.h>
#include <sun/security/rsa/RSACore.h>
#include <jcpp.h>

#undef EM
#undef M
#undef PAD_BLOCKTYPE_1
#undef PAD_BLOCKTYPE_2
#undef PAD_NONE
#undef PAD_OAEP_MGF1

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $SecureRandom = ::java::security::SecureRandom;
using $MGF1ParameterSpec = ::java::security::spec::MGF1ParameterSpec;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $OAEPParameterSpec = ::javax::crypto::spec::OAEPParameterSpec;
using $PSource = ::javax::crypto::spec::PSource;
using $PSource$PSpecified = ::javax::crypto::spec::PSource$PSpecified;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $MGF1 = ::sun::security::rsa::MGF1;
using $RSACore = ::sun::security::rsa::RSACore;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _RSAPadding_FieldInfo_[] = {
	{"PAD_BLOCKTYPE_1", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAPadding, PAD_BLOCKTYPE_1)},
	{"PAD_BLOCKTYPE_2", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAPadding, PAD_BLOCKTYPE_2)},
	{"PAD_NONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAPadding, PAD_NONE)},
	{"PAD_OAEP_MGF1", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(RSAPadding, PAD_OAEP_MGF1)},
	{"type", "I", nullptr, $PRIVATE | $FINAL, $field(RSAPadding, type)},
	{"paddedSize", "I", nullptr, $PRIVATE | $FINAL, $field(RSAPadding, paddedSize)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(RSAPadding, random)},
	{"maxDataSize", "I", nullptr, $PRIVATE | $FINAL, $field(RSAPadding, maxDataSize)},
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE, $field(RSAPadding, md)},
	{"mgf", "Lsun/security/rsa/MGF1;", nullptr, $PRIVATE, $field(RSAPadding, mgf)},
	{"lHash", "[B", nullptr, $PRIVATE, $field(RSAPadding, lHash)},
	{"emptyHashes", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[B>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSAPadding, emptyHashes)},
	{}
};

$MethodInfo _RSAPadding_MethodInfo_[] = {
	{"<init>", "(IILjava/security/SecureRandom;Ljavax/crypto/spec/OAEPParameterSpec;)V", nullptr, $PRIVATE, $method(RSAPadding, init$, void, int32_t, int32_t, $SecureRandom*, $OAEPParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"getInitialHash", "(Ljava/security/MessageDigest;[B)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAPadding, getInitialHash, $bytes*, $MessageDigest*, $bytes*)},
	{"getInstance", "(II)Lsun/security/rsa/RSAPadding;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPadding, getInstance, RSAPadding*, int32_t, int32_t), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"getInstance", "(IILjava/security/SecureRandom;)Lsun/security/rsa/RSAPadding;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPadding, getInstance, RSAPadding*, int32_t, int32_t, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"getInstance", "(IILjava/security/SecureRandom;Ljavax/crypto/spec/OAEPParameterSpec;)Lsun/security/rsa/RSAPadding;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPadding, getInstance, RSAPadding*, int32_t, int32_t, $SecureRandom*, $OAEPParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"getMaxDataSize", "()I", nullptr, $PUBLIC, $method(RSAPadding, getMaxDataSize, int32_t)},
	{"pad", "([B)[B", nullptr, $PUBLIC, $method(RSAPadding, pad, $bytes*, $bytes*), "javax.crypto.BadPaddingException"},
	{"pad", "([BII)[B", nullptr, $PUBLIC, $method(RSAPadding, pad, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.BadPaddingException"},
	{"padOAEP", "([BII)[B", nullptr, $PRIVATE, $method(RSAPadding, padOAEP, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.BadPaddingException"},
	{"padV15", "([BII)[B", nullptr, $PRIVATE, $method(RSAPadding, padV15, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.BadPaddingException"},
	{"unpad", "([B)[B", nullptr, $PUBLIC, $method(RSAPadding, unpad, $bytes*, $bytes*), "javax.crypto.BadPaddingException"},
	{"unpadOAEP", "([B)[B", nullptr, $PRIVATE, $method(RSAPadding, unpadOAEP, $bytes*, $bytes*), "javax.crypto.BadPaddingException"},
	{"unpadV15", "([B)[B", nullptr, $PRIVATE, $method(RSAPadding, unpadV15, $bytes*, $bytes*), "javax.crypto.BadPaddingException"},
	{}
};

$ClassInfo _RSAPadding_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.rsa.RSAPadding",
	"java.lang.Object",
	nullptr,
	_RSAPadding_FieldInfo_,
	_RSAPadding_MethodInfo_
};

$Object* allocate$RSAPadding($Class* clazz) {
	return $of($alloc(RSAPadding));
}

$Map* RSAPadding::emptyHashes = nullptr;

RSAPadding* RSAPadding::getInstance(int32_t type, int32_t paddedSize) {
	$init(RSAPadding);
	return $new(RSAPadding, type, paddedSize, nullptr, nullptr);
}

RSAPadding* RSAPadding::getInstance(int32_t type, int32_t paddedSize, $SecureRandom* random) {
	$init(RSAPadding);
	return $new(RSAPadding, type, paddedSize, random, nullptr);
}

RSAPadding* RSAPadding::getInstance(int32_t type, int32_t paddedSize, $SecureRandom* random, $OAEPParameterSpec* spec) {
	$init(RSAPadding);
	return $new(RSAPadding, type, paddedSize, random, spec);
}

void RSAPadding::init$(int32_t type, int32_t paddedSize, $SecureRandom* random, $OAEPParameterSpec* spec) {
	$useLocalCurrentObjectStackCache();
	this->type = type;
	this->paddedSize = paddedSize;
	$set(this, random, random);
	if (paddedSize < 64) {
		$throwNew($InvalidKeyException, "Padded size must be at least 64"_s);
	}
	{
		$var($String, mdName, nullptr)
		$var($String, mgfMdName, nullptr)
		$var($bytes, digestInput, nullptr)
		int32_t digestLen = 0;
		switch (type) {
		case RSAPadding::PAD_BLOCKTYPE_1:
			{}
		case RSAPadding::PAD_BLOCKTYPE_2:
			{
				this->maxDataSize = paddedSize - 11;
				break;
			}
		case RSAPadding::PAD_NONE:
			{
				this->maxDataSize = paddedSize;
				break;
			}
		case RSAPadding::PAD_OAEP_MGF1:
			{
				$assign(mdName, "SHA-1"_s);
				$assign(mgfMdName, mdName);
				$assign(digestInput, nullptr);
				try {
					if (spec != nullptr) {
						$assign(mdName, spec->getDigestAlgorithm());
						$var($String, mgfName, spec->getMGFAlgorithm());
						if (!$nc(mgfName)->equalsIgnoreCase("MGF1"_s)) {
							$throwNew($InvalidAlgorithmParameterException, $$str({"Unsupported MGF algo: "_s, mgfName}));
						}
						$assign(mgfMdName, $nc(($cast($MGF1ParameterSpec, $(spec->getMGFParameters()))))->getDigestAlgorithm());
						$var($PSource, pSrc, spec->getPSource());
						$var($String, pSrcAlgo, $nc(pSrc)->getAlgorithm());
						if (!$nc(pSrcAlgo)->equalsIgnoreCase("PSpecified"_s)) {
							$throwNew($InvalidAlgorithmParameterException, $$str({"Unsupported pSource algo: "_s, pSrcAlgo}));
						}
						$assign(digestInput, $nc(($cast($PSource$PSpecified, pSrc)))->getValue());
					}
					$set(this, md, $MessageDigest::getInstance(mdName));
					$set(this, mgf, $new($MGF1, mgfMdName));
				} catch ($NoSuchAlgorithmException& e) {
					$throwNew($InvalidKeyException, "Digest not available"_s, e);
				}
				$set(this, lHash, getInitialHash(this->md, digestInput));
				digestLen = $nc(this->lHash)->length;
				this->maxDataSize = paddedSize - 2 - 2 * digestLen;
				if (this->maxDataSize <= 0) {
					$throwNew($InvalidKeyException, $$str({"Key is too short for encryption using OAEPPadding with "_s, mdName, " and "_s, $($nc(this->mgf)->getName())}));
				}
				break;
			}
		default:
			{
				$throwNew($InvalidKeyException, $$str({"Invalid padding: "_s, $$str(type)}));
			}
		}
	}
}

$bytes* RSAPadding::getInitialHash($MessageDigest* md, $bytes* digestInput) {
	$init(RSAPadding);
	$useLocalCurrentObjectStackCache();
	$var($bytes, result, nullptr);
	if ((digestInput == nullptr) || ($nc(digestInput)->length == 0)) {
		$var($String, digestName, $nc(md)->getAlgorithm());
		$assign(result, $cast($bytes, $nc(RSAPadding::emptyHashes)->get(digestName)));
		if (result == nullptr) {
			$assign(result, md->digest());
			$nc(RSAPadding::emptyHashes)->put(digestName, result);
		}
	} else {
		$assign(result, $nc(md)->digest(digestInput));
	}
	return result;
}

int32_t RSAPadding::getMaxDataSize() {
	return this->maxDataSize;
}

$bytes* RSAPadding::pad($bytes* data) {
	return pad(data, 0, $nc(data)->length);
}

$bytes* RSAPadding::pad($bytes* data, int32_t ofs, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (len > this->maxDataSize) {
		$throwNew($BadPaddingException, $$str({"Data must be shorter than "_s, $$str((this->maxDataSize + 1)), " bytes but received "_s, $$str(len), " bytes."_s}));
	}
	switch (this->type) {
	case RSAPadding::PAD_NONE:
		{
			return $RSACore::convert(data, ofs, len);
		}
	case RSAPadding::PAD_BLOCKTYPE_1:
		{}
	case RSAPadding::PAD_BLOCKTYPE_2:
		{
			return padV15(data, ofs, len);
		}
	case RSAPadding::PAD_OAEP_MGF1:
		{
			return padOAEP(data, ofs, len);
		}
	default:
		{
			$throwNew($AssertionError);
		}
	}
}

$bytes* RSAPadding::unpad($bytes* padded) {
	$useLocalCurrentObjectStackCache();
	if ($nc(padded)->length != this->paddedSize) {
		$throwNew($BadPaddingException, $$str({"Decryption error.The padded array length ("_s, $$str(padded->length), ") is not the specified padded size ("_s, $$str(this->paddedSize), ")"_s}));
	}
	switch (this->type) {
	case RSAPadding::PAD_NONE:
		{
			return padded;
		}
	case RSAPadding::PAD_BLOCKTYPE_1:
		{}
	case RSAPadding::PAD_BLOCKTYPE_2:
		{
			return unpadV15(padded);
		}
	case RSAPadding::PAD_OAEP_MGF1:
		{
			return unpadOAEP(padded);
		}
	default:
		{
			$throwNew($AssertionError);
		}
	}
}

$bytes* RSAPadding::padV15($bytes* data, int32_t ofs, int32_t len) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, padded, $new($bytes, this->paddedSize));
	$System::arraycopy(data, ofs, padded, this->paddedSize - len, len);
	int32_t psSize = this->paddedSize - 3 - len;
	int32_t k = 0;
	padded->set(k++, (int8_t)0);
	padded->set(k++, (int8_t)this->type);
	if (this->type == RSAPadding::PAD_BLOCKTYPE_1) {
		while (psSize-- > 0) {
			padded->set(k++, (int8_t)255);
		}
	} else {
		if (this->random == nullptr) {
			$set(this, random, $JCAUtil::getSecureRandom());
		}
		while (psSize > 0) {
			$var($bytes, r, $new($bytes, psSize + 4));
			$nc(this->random)->nextBytes(r);
			for (int32_t i = 0; i < r->length && psSize > 0; ++i) {
				if (r->get(i) != 0) {
					padded->set(k++, r->get(i));
					--psSize;
				}
			}
		}
	}
	return padded;
}

$bytes* RSAPadding::unpadV15($bytes* padded) {
	$useLocalCurrentObjectStackCache();
	int32_t k = 0;
	bool bp = false;
	if ($nc(padded)->get(k++) != 0) {
		bp = true;
	}
	if ($nc(padded)->get(k++) != this->type) {
		bp = true;
	}
	int32_t p = 0;
	while (k < $nc(padded)->length) {
		int32_t b = (int32_t)(padded->get(k++) & (uint32_t)255);
		if ((b == 0) && (p == 0)) {
			p = k;
		}
		if ((k == padded->length) && (p == 0)) {
			bp = true;
		}
		if ((this->type == RSAPadding::PAD_BLOCKTYPE_1) && (b != 255) && (p == 0)) {
			bp = true;
		}
	}
	int32_t n = $nc(padded)->length - p;
	if (n > this->maxDataSize) {
		bp = true;
	}
	$var($bytes, padding, $new($bytes, p));
	$System::arraycopy(padded, 0, padding, 0, p);
	$var($bytes, data, $new($bytes, n));
	$System::arraycopy(padded, p, data, 0, n);
	$var($BadPaddingException, bpe, $new($BadPaddingException, "Decryption error"_s));
	if (bp) {
		$throw(bpe);
	} else {
		return data;
	}
}

$bytes* RSAPadding::padOAEP($bytes* M, int32_t ofs, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (this->random == nullptr) {
		$set(this, random, $JCAUtil::getSecureRandom());
	}
	int32_t hLen = $nc(this->lHash)->length;
	$var($bytes, seed, $new($bytes, hLen));
	$nc(this->random)->nextBytes(seed);
	$var($bytes, EM, $new($bytes, this->paddedSize));
	int32_t seedStart = 1;
	int32_t seedLen = hLen;
	$System::arraycopy(seed, 0, EM, seedStart, seedLen);
	int32_t dbStart = hLen + 1;
	int32_t dbLen = EM->length - dbStart;
	int32_t mStart = this->paddedSize - len;
	$System::arraycopy(this->lHash, 0, EM, dbStart, hLen);
	EM->set(mStart - 1, (int8_t)1);
	$System::arraycopy(M, ofs, EM, mStart, len);
	$nc(this->mgf)->generateAndXor(EM, seedStart, seedLen, dbLen, EM, dbStart);
	$nc(this->mgf)->generateAndXor(EM, dbStart, dbLen, seedLen, EM, seedStart);
	return EM;
}

$bytes* RSAPadding::unpadOAEP($bytes* padded) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, EM, padded);
	bool bp = false;
	int32_t hLen = $nc(this->lHash)->length;
	if ($nc(EM)->get(0) != 0) {
		bp = true;
	}
	int32_t seedStart = 1;
	int32_t seedLen = hLen;
	int32_t dbStart = hLen + 1;
	int32_t dbLen = $nc(EM)->length - dbStart;
	$nc(this->mgf)->generateAndXor(EM, dbStart, dbLen, seedLen, EM, seedStart);
	$nc(this->mgf)->generateAndXor(EM, seedStart, seedLen, dbLen, EM, dbStart);
	for (int32_t i = 0; i < hLen; ++i) {
		if ($nc(this->lHash)->get(i) != EM->get(dbStart + i)) {
			bp = true;
		}
	}
	int32_t padStart = dbStart + hLen;
	int32_t onePos = -1;
	for (int32_t i = padStart; i < EM->length; ++i) {
		int32_t value = EM->get(i);
		if (onePos == -1) {
			if (value == 0) {
			} else if (value == 1) {
				onePos = i;
			} else {
				bp = true;
			}
		}
	}
	if (onePos == -1) {
		bp = true;
		onePos = EM->length - 1;
	}
	int32_t mStart = onePos + 1;
	$var($bytes, tmp, $new($bytes, mStart - padStart));
	$System::arraycopy(EM, padStart, tmp, 0, tmp->length);
	$var($bytes, m, $new($bytes, EM->length - mStart));
	$System::arraycopy(EM, mStart, m, 0, m->length);
	$var($BadPaddingException, bpe, $new($BadPaddingException, "Decryption error"_s));
	if (bp) {
		$throw(bpe);
	} else {
		return m;
	}
}

void clinit$RSAPadding($Class* class$) {
	$assignStatic(RSAPadding::emptyHashes, $Collections::synchronizedMap($$new($HashMap)));
}

RSAPadding::RSAPadding() {
}

$Class* RSAPadding::load$($String* name, bool initialize) {
	$loadClass(RSAPadding, name, initialize, &_RSAPadding_ClassInfo_, clinit$RSAPadding, allocate$RSAPadding);
	return class$;
}

$Class* RSAPadding::class$ = nullptr;

		} // rsa
	} // security
} // sun