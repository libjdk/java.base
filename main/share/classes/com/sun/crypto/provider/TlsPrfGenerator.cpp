#include <com/sun/crypto/provider/TlsPrfGenerator.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/DigestException.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/ProviderException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/KeyGeneratorSpi.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/internal/spec/TlsPrfParameterSpec.h>
#include <jcpp.h>

#undef LABEL_CLIENT_WRITE_KEY
#undef LABEL_EXTENDED_MASTER_SECRET
#undef LABEL_IV_BLOCK
#undef LABEL_KEY_EXPANSION
#undef LABEL_MASTER_SECRET
#undef LABEL_SERVER_WRITE_KEY
#undef MSG
#undef SSL3_CONST
#undef UTF_8

using $byteArray2 = $Array<int8_t, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $DigestException = ::java::security::DigestException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $ProviderException = ::java::security::ProviderException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $KeyGeneratorSpi = ::javax::crypto::KeyGeneratorSpi;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $TlsPrfParameterSpec = ::sun::security::internal::spec::TlsPrfParameterSpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _TlsPrfGenerator_FieldInfo_[] = {
	{"B0", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsPrfGenerator, B0)},
	{"LABEL_MASTER_SECRET", "[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, LABEL_MASTER_SECRET)},
	{"LABEL_EXTENDED_MASTER_SECRET", "[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, LABEL_EXTENDED_MASTER_SECRET)},
	{"LABEL_KEY_EXPANSION", "[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, LABEL_KEY_EXPANSION)},
	{"LABEL_CLIENT_WRITE_KEY", "[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, LABEL_CLIENT_WRITE_KEY)},
	{"LABEL_SERVER_WRITE_KEY", "[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, LABEL_SERVER_WRITE_KEY)},
	{"LABEL_IV_BLOCK", "[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, LABEL_IV_BLOCK)},
	{"HMAC_ipad64", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsPrfGenerator, HMAC_ipad64)},
	{"HMAC_ipad128", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsPrfGenerator, HMAC_ipad128)},
	{"HMAC_opad64", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsPrfGenerator, HMAC_opad64)},
	{"HMAC_opad128", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsPrfGenerator, HMAC_opad128)},
	{"SSL3_CONST", "[[B", nullptr, $STATIC | $FINAL, $staticField(TlsPrfGenerator, SSL3_CONST)},
	{"MSG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsPrfGenerator, MSG)},
	{"spec", "Lsun/security/internal/spec/TlsPrfParameterSpec;", nullptr, $PRIVATE, $field(TlsPrfGenerator, spec)},
	{}
};

$MethodInfo _TlsPrfGenerator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TlsPrfGenerator, init$, void)},
	{"concat", "([B[B)[B", nullptr, $STATIC, $staticMethod(TlsPrfGenerator, concat, $bytes*, $bytes*, $bytes*)},
	{"doTLS10PRF", "([B[B[BI)[B", nullptr, $STATIC, $staticMethod(TlsPrfGenerator, doTLS10PRF, $bytes*, $bytes*, $bytes*, $bytes*, int32_t), "java.security.NoSuchAlgorithmException,java.security.DigestException"},
	{"doTLS10PRF", "([B[B[BILjava/security/MessageDigest;Ljava/security/MessageDigest;)[B", nullptr, $STATIC, $staticMethod(TlsPrfGenerator, doTLS10PRF, $bytes*, $bytes*, $bytes*, $bytes*, int32_t, $MessageDigest*, $MessageDigest*), "java.security.DigestException"},
	{"doTLS12PRF", "([B[B[BILjava/lang/String;II)[B", nullptr, $STATIC, $staticMethod(TlsPrfGenerator, doTLS12PRF, $bytes*, $bytes*, $bytes*, $bytes*, int32_t, $String*, int32_t, int32_t), "java.security.NoSuchAlgorithmException,java.security.DigestException"},
	{"doTLS12PRF", "([B[B[BILjava/security/MessageDigest;II)[B", nullptr, $STATIC, $staticMethod(TlsPrfGenerator, doTLS12PRF, $bytes*, $bytes*, $bytes*, $bytes*, int32_t, $MessageDigest*, int32_t, int32_t), "java.security.DigestException"},
	{"engineGenerateKey0", "(Z)Ljavax/crypto/SecretKey;", nullptr, 0, $virtualMethod(TlsPrfGenerator, engineGenerateKey0, $SecretKey*, bool)},
	{"engineInit", "(Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsPrfGenerator, engineInit, void, $SecureRandom*)},
	{"engineInit", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsPrfGenerator, engineInit, void, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsPrfGenerator, engineInit, void, int32_t, $SecureRandom*)},
	{"expand", "(Ljava/security/MessageDigest;I[BII[B[B[B[B[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(TlsPrfGenerator, expand, void, $MessageDigest*, int32_t, $bytes*, int32_t, int32_t, $bytes*, $bytes*, $bytes*, $bytes*, $bytes*), "java.security.DigestException"},
	{"genConst", "()[[B", nullptr, $PRIVATE | $STATIC, $staticMethod(TlsPrfGenerator, genConst, $byteArray2*)},
	{"genPad", "(BI)[B", nullptr, $STATIC, $staticMethod(TlsPrfGenerator, genPad, $bytes*, int8_t, int32_t)},
	{}
};

$InnerClassInfo _TlsPrfGenerator_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.TlsPrfGenerator$V10", "com.sun.crypto.provider.TlsPrfGenerator", "V10", $PUBLIC | $STATIC},
	{"com.sun.crypto.provider.TlsPrfGenerator$V12", "com.sun.crypto.provider.TlsPrfGenerator", "V12", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _TlsPrfGenerator_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"com.sun.crypto.provider.TlsPrfGenerator",
	"javax.crypto.KeyGeneratorSpi",
	nullptr,
	_TlsPrfGenerator_FieldInfo_,
	_TlsPrfGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_TlsPrfGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.TlsPrfGenerator$V10,com.sun.crypto.provider.TlsPrfGenerator$V12"
};

$Object* allocate$TlsPrfGenerator($Class* clazz) {
	return $of($alloc(TlsPrfGenerator));
}

$bytes* TlsPrfGenerator::B0 = nullptr;
$bytes* TlsPrfGenerator::LABEL_MASTER_SECRET = nullptr;
$bytes* TlsPrfGenerator::LABEL_EXTENDED_MASTER_SECRET = nullptr;
$bytes* TlsPrfGenerator::LABEL_KEY_EXPANSION = nullptr;
$bytes* TlsPrfGenerator::LABEL_CLIENT_WRITE_KEY = nullptr;
$bytes* TlsPrfGenerator::LABEL_SERVER_WRITE_KEY = nullptr;
$bytes* TlsPrfGenerator::LABEL_IV_BLOCK = nullptr;
$bytes* TlsPrfGenerator::HMAC_ipad64 = nullptr;
$bytes* TlsPrfGenerator::HMAC_ipad128 = nullptr;
$bytes* TlsPrfGenerator::HMAC_opad64 = nullptr;
$bytes* TlsPrfGenerator::HMAC_opad128 = nullptr;
$byteArray2* TlsPrfGenerator::SSL3_CONST = nullptr;
$String* TlsPrfGenerator::MSG = nullptr;

$bytes* TlsPrfGenerator::genPad(int8_t b, int32_t count) {
	$init(TlsPrfGenerator);
	$var($bytes, padding, $new($bytes, count));
	$Arrays::fill(padding, b);
	return padding;
}

$bytes* TlsPrfGenerator::concat($bytes* b1, $bytes* b2) {
	$init(TlsPrfGenerator);
	int32_t n1 = $nc(b1)->length;
	int32_t n2 = $nc(b2)->length;
	$var($bytes, b, $new($bytes, n1 + n2));
	$System::arraycopy(b1, 0, b, 0, n1);
	$System::arraycopy(b2, 0, b, n1, n2);
	return b;
}

$byteArray2* TlsPrfGenerator::genConst() {
	$init(TlsPrfGenerator);
	$useLocalCurrentObjectStackCache();
	int32_t n = 10;
	$var($byteArray2, arr, $new($byteArray2, n));
	for (int32_t i = 0; i < n; ++i) {
		$var($bytes, b, $new($bytes, i + 1));
		$Arrays::fill(b, (int8_t)(u'A' + i));
		arr->set(i, b);
	}
	return arr;
}

void TlsPrfGenerator::init$() {
	$KeyGeneratorSpi::init$();
}

void TlsPrfGenerator::engineInit($SecureRandom* random) {
	$throwNew($InvalidParameterException, TlsPrfGenerator::MSG);
}

void TlsPrfGenerator::engineInit($AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($TlsPrfParameterSpec, params) == false) {
		$throwNew($InvalidAlgorithmParameterException, TlsPrfGenerator::MSG);
	}
	$set(this, spec, $cast($TlsPrfParameterSpec, params));
	$var($SecretKey, key, $nc(this->spec)->getSecret());
	if ((key != nullptr) && ("RAW"_s->equals($(key->getFormat())) == false)) {
		$throwNew($InvalidAlgorithmParameterException, "Key encoding format must be RAW"_s);
	}
}

void TlsPrfGenerator::engineInit(int32_t keysize, $SecureRandom* random) {
	$throwNew($InvalidParameterException, TlsPrfGenerator::MSG);
}

$SecretKey* TlsPrfGenerator::engineGenerateKey0(bool tls12) {
	$useLocalCurrentObjectStackCache();
	if (this->spec == nullptr) {
		$throwNew($IllegalStateException, "TlsPrfGenerator must be initialized"_s);
	}
	$var($SecretKey, key, $nc(this->spec)->getSecret());
	$var($bytes, secret, (key == nullptr) ? ($bytes*)nullptr : $nc(key)->getEncoded());
	{
		$var($Throwable, var$0, nullptr);
		$var($SecretKey, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$init($StandardCharsets);
				$var($bytes, labelBytes, $nc($($nc(this->spec)->getLabel()))->getBytes($StandardCharsets::UTF_8));
				int32_t n = $nc(this->spec)->getOutputLength();
				$var($bytes, var$3, nullptr);
				if (tls12) {
					$var($bytes, var$4, secret);
					$var($bytes, var$5, labelBytes);
					$var($bytes, var$6, $nc(this->spec)->getSeed());
					int32_t var$7 = n;
					$var($String, var$8, $nc(this->spec)->getPRFHashAlg());
					int32_t var$9 = $nc(this->spec)->getPRFHashLength();
					$assign(var$3, doTLS12PRF(var$4, var$5, var$6, var$7, var$8, var$9, $nc(this->spec)->getPRFBlockSize()));
				} else {
					$assign(var$3, doTLS10PRF(secret, labelBytes, $($nc(this->spec)->getSeed()), n));
				}
				$var($bytes, prfBytes, var$3);
				{
					$var($Throwable, var$10, nullptr);
					$var($SecretKey, var$12, nullptr);
					bool return$11 = false;
					try {
						$assign(var$12, $new($SecretKeySpec, prfBytes, "TlsPrf"_s));
						return$11 = true;
						goto $finally1;
					} catch ($Throwable& var$13) {
						$assign(var$10, var$13);
					} $finally1: {
						$Arrays::fill(prfBytes, (int8_t)0);
					}
					if (var$10 != nullptr) {
						$throw(var$10);
					}
					if (return$11) {
						$assign(var$2, var$12);
						return$1 = true;
						goto $finally;
					}
				}
			} catch ($GeneralSecurityException& e) {
				$throwNew($ProviderException, "Could not generate PRF"_s, e);
			}
		} catch ($Throwable& var$14) {
			$assign(var$0, var$14);
		} $finally: {
			if (secret != nullptr) {
				$Arrays::fill(secret, (int8_t)0);
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

$bytes* TlsPrfGenerator::doTLS12PRF($bytes* secret, $bytes* labelBytes, $bytes* seed, int32_t outputLength, $String* prfHash, int32_t prfHashLength, int32_t prfBlockSize) {
	$init(TlsPrfGenerator);
	if (prfHash == nullptr) {
		$throwNew($NoSuchAlgorithmException, "Unspecified PRF algorithm"_s);
	}
	$var($MessageDigest, prfMD, $MessageDigest::getInstance(prfHash));
	return doTLS12PRF(secret, labelBytes, seed, outputLength, prfMD, prfHashLength, prfBlockSize);
}

$bytes* TlsPrfGenerator::doTLS12PRF($bytes* secret$renamed, $bytes* labelBytes, $bytes* seed, int32_t outputLength, $MessageDigest* mdPRF, int32_t mdPRFLen, int32_t mdPRFBlockSize) {
	$init(TlsPrfGenerator);
	$useLocalCurrentObjectStackCache();
	$var($bytes, secret, secret$renamed);
	if (secret == nullptr) {
		$assign(secret, TlsPrfGenerator::B0);
	}
	if ($nc(secret)->length > mdPRFBlockSize) {
		$assign(secret, $nc(mdPRF)->digest(secret));
	}
	$var($bytes, output, $new($bytes, outputLength));
	$var($bytes, ipad, nullptr);
	$var($bytes, opad, nullptr);
	switch (mdPRFBlockSize) {
	case 64:
		{
			$assign(ipad, $cast($bytes, $nc(TlsPrfGenerator::HMAC_ipad64)->clone()));
			$assign(opad, $cast($bytes, $nc(TlsPrfGenerator::HMAC_opad64)->clone()));
			break;
		}
	case 128:
		{
			$assign(ipad, $cast($bytes, $nc(TlsPrfGenerator::HMAC_ipad128)->clone()));
			$assign(opad, $cast($bytes, $nc(TlsPrfGenerator::HMAC_opad128)->clone()));
			break;
		}
	default:
		{
			$throwNew($DigestException, "Unexpected block size."_s);
		}
	}
	expand(mdPRF, mdPRFLen, secret, 0, $nc(secret)->length, labelBytes, seed, output, ipad, opad);
	return output;
}

$bytes* TlsPrfGenerator::doTLS10PRF($bytes* secret, $bytes* labelBytes, $bytes* seed, int32_t outputLength) {
	$init(TlsPrfGenerator);
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md5, $MessageDigest::getInstance("MD5"_s));
	$var($MessageDigest, sha, $MessageDigest::getInstance("SHA1"_s));
	return doTLS10PRF(secret, labelBytes, seed, outputLength, md5, sha);
}

$bytes* TlsPrfGenerator::doTLS10PRF($bytes* secret$renamed, $bytes* labelBytes, $bytes* seed, int32_t outputLength, $MessageDigest* md5, $MessageDigest* sha) {
	$init(TlsPrfGenerator);
	$useLocalCurrentObjectStackCache();
	$var($bytes, secret, secret$renamed);
	if (secret == nullptr) {
		$assign(secret, TlsPrfGenerator::B0);
	}
	int32_t off = $nc(secret)->length >> 1;
	int32_t seclen = off + ((int32_t)(secret->length & (uint32_t)1));
	$var($bytes, secKey, secret);
	int32_t keyLen = seclen;
	$var($bytes, output, $new($bytes, outputLength));
	if (seclen > 64) {
		$nc(md5)->update(secret, 0, seclen);
		$assign(secKey, md5->digest());
		md5->reset();
		keyLen = $nc(secKey)->length;
	}
	$var($MessageDigest, var$0, md5);
	$var($bytes, var$1, secKey);
	int32_t var$2 = keyLen;
	$var($bytes, var$3, labelBytes);
	$var($bytes, var$4, seed);
	$var($bytes, var$5, output);
	$var($bytes, var$6, $cast($bytes, $nc(TlsPrfGenerator::HMAC_ipad64)->clone()));
	expand(var$0, 16, var$1, 0, var$2, var$3, var$4, var$5, var$6, $cast($bytes, $($nc(TlsPrfGenerator::HMAC_opad64)->clone())));
	if (seclen > 64) {
		$nc(sha)->update(secret, off, seclen);
		$assign(secKey, sha->digest());
		sha->reset();
		keyLen = $nc(secKey)->length;
		off = 0;
	}
	$var($MessageDigest, var$7, sha);
	$var($bytes, var$8, secKey);
	int32_t var$9 = off;
	int32_t var$10 = keyLen;
	$var($bytes, var$11, labelBytes);
	$var($bytes, var$12, seed);
	$var($bytes, var$13, output);
	$var($bytes, var$14, $cast($bytes, $nc(TlsPrfGenerator::HMAC_ipad64)->clone()));
	expand(var$7, 20, var$8, var$9, var$10, var$11, var$12, var$13, var$14, $cast($bytes, $($nc(TlsPrfGenerator::HMAC_opad64)->clone())));
	return output;
}

void TlsPrfGenerator::expand($MessageDigest* digest, int32_t hmacSize, $bytes* secret, int32_t secOff, int32_t secLen, $bytes* label, $bytes* seed, $bytes* output, $bytes* pad1, $bytes* pad2) {
	$init(TlsPrfGenerator);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < secLen; ++i) {
		(*$nc(pad1))[i] ^= $nc(secret)->get(i + secOff);
		(*$nc(pad2))[i] ^= secret->get(i + secOff);
	}
	$var($bytes, tmp, $new($bytes, hmacSize));
	$var($bytes, aBytes, nullptr);
	int32_t remaining = $nc(output)->length;
	int32_t ofs = 0;
	while (remaining > 0) {
		$nc(digest)->update(pad1);
		if (aBytes == nullptr) {
			digest->update(label);
			digest->update(seed);
		} else {
			digest->update(aBytes);
		}
		digest->digest(tmp, 0, hmacSize);
		digest->update(pad2);
		digest->update(tmp);
		if (aBytes == nullptr) {
			$assign(aBytes, $new($bytes, hmacSize));
		}
		digest->digest(aBytes, 0, hmacSize);
		digest->update(pad1);
		digest->update(aBytes);
		digest->update(label);
		digest->update(seed);
		digest->digest(tmp, 0, hmacSize);
		digest->update(pad2);
		digest->update(tmp);
		digest->digest(tmp, 0, hmacSize);
		digest->reset();
		int32_t k = $Math::min(hmacSize, remaining);
		for (int32_t i = 0; i < k; ++i) {
			(*output)[ofs++] ^= tmp->get(i);
		}
		remaining -= k;
	}
	$Arrays::fill(tmp, (int8_t)0);
}

void clinit$TlsPrfGenerator($Class* class$) {
	$assignStatic(TlsPrfGenerator::MSG, "TlsPrfGenerator must be initialized using a TlsPrfParameterSpec"_s);
	$assignStatic(TlsPrfGenerator::B0, $new($bytes, 0));
	$assignStatic(TlsPrfGenerator::LABEL_MASTER_SECRET, $new($bytes, {
		(int8_t)109,
		(int8_t)97,
		(int8_t)115,
		(int8_t)116,
		(int8_t)101,
		(int8_t)114,
		(int8_t)32,
		(int8_t)115,
		(int8_t)101,
		(int8_t)99,
		(int8_t)114,
		(int8_t)101,
		(int8_t)116
	}));
	$assignStatic(TlsPrfGenerator::LABEL_EXTENDED_MASTER_SECRET, $new($bytes, {
		(int8_t)101,
		(int8_t)120,
		(int8_t)116,
		(int8_t)101,
		(int8_t)110,
		(int8_t)100,
		(int8_t)101,
		(int8_t)100,
		(int8_t)32,
		(int8_t)109,
		(int8_t)97,
		(int8_t)115,
		(int8_t)116,
		(int8_t)101,
		(int8_t)114,
		(int8_t)32,
		(int8_t)115,
		(int8_t)101,
		(int8_t)99,
		(int8_t)114,
		(int8_t)101,
		(int8_t)116
	}));
	$assignStatic(TlsPrfGenerator::LABEL_KEY_EXPANSION, $new($bytes, {
		(int8_t)107,
		(int8_t)101,
		(int8_t)121,
		(int8_t)32,
		(int8_t)101,
		(int8_t)120,
		(int8_t)112,
		(int8_t)97,
		(int8_t)110,
		(int8_t)115,
		(int8_t)105,
		(int8_t)111,
		(int8_t)110
	}));
	$assignStatic(TlsPrfGenerator::LABEL_CLIENT_WRITE_KEY, $new($bytes, {
		(int8_t)99,
		(int8_t)108,
		(int8_t)105,
		(int8_t)101,
		(int8_t)110,
		(int8_t)116,
		(int8_t)32,
		(int8_t)119,
		(int8_t)114,
		(int8_t)105,
		(int8_t)116,
		(int8_t)101,
		(int8_t)32,
		(int8_t)107,
		(int8_t)101,
		(int8_t)121
	}));
	$assignStatic(TlsPrfGenerator::LABEL_SERVER_WRITE_KEY, $new($bytes, {
		(int8_t)115,
		(int8_t)101,
		(int8_t)114,
		(int8_t)118,
		(int8_t)101,
		(int8_t)114,
		(int8_t)32,
		(int8_t)119,
		(int8_t)114,
		(int8_t)105,
		(int8_t)116,
		(int8_t)101,
		(int8_t)32,
		(int8_t)107,
		(int8_t)101,
		(int8_t)121
	}));
	$assignStatic(TlsPrfGenerator::LABEL_IV_BLOCK, $new($bytes, {
		(int8_t)73,
		(int8_t)86,
		(int8_t)32,
		(int8_t)98,
		(int8_t)108,
		(int8_t)111,
		(int8_t)99,
		(int8_t)107
	}));
	$assignStatic(TlsPrfGenerator::HMAC_ipad64, TlsPrfGenerator::genPad((int8_t)54, 64));
	$assignStatic(TlsPrfGenerator::HMAC_ipad128, TlsPrfGenerator::genPad((int8_t)54, 128));
	$assignStatic(TlsPrfGenerator::HMAC_opad64, TlsPrfGenerator::genPad((int8_t)92, 64));
	$assignStatic(TlsPrfGenerator::HMAC_opad128, TlsPrfGenerator::genPad((int8_t)92, 128));
	$assignStatic(TlsPrfGenerator::SSL3_CONST, TlsPrfGenerator::genConst());
}

TlsPrfGenerator::TlsPrfGenerator() {
}

$Class* TlsPrfGenerator::load$($String* name, bool initialize) {
	$loadClass(TlsPrfGenerator, name, initialize, &_TlsPrfGenerator_ClassInfo_, clinit$TlsPrfGenerator, allocate$TlsPrfGenerator);
	return class$;
}

$Class* TlsPrfGenerator::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com