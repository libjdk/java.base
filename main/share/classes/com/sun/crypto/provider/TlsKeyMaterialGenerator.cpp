#include <com/sun/crypto/provider/TlsKeyMaterialGenerator.h>

#include <com/sun/crypto/provider/TlsPrfGenerator.h>
#include <java/lang/IllegalStateException.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/MessageDigest.h>
#include <java/security/ProviderException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/KeyGeneratorSpi.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/internal/spec/TlsKeyMaterialParameterSpec.h>
#include <sun/security/internal/spec/TlsKeyMaterialSpec.h>
#include <jcpp.h>

#undef LABEL_CLIENT_WRITE_KEY
#undef LABEL_IV_BLOCK
#undef LABEL_KEY_EXPANSION
#undef LABEL_SERVER_WRITE_KEY
#undef MSG
#undef SSL3_CONST

using $TlsPrfGenerator = ::com::sun::crypto::provider::TlsPrfGenerator;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $MessageDigest = ::java::security::MessageDigest;
using $ProviderException = ::java::security::ProviderException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $KeyGeneratorSpi = ::javax::crypto::KeyGeneratorSpi;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $TlsKeyMaterialParameterSpec = ::sun::security::internal::spec::TlsKeyMaterialParameterSpec;
using $TlsKeyMaterialSpec = ::sun::security::internal::spec::TlsKeyMaterialSpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _TlsKeyMaterialGenerator_FieldInfo_[] = {
	{"MSG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsKeyMaterialGenerator, MSG)},
	{"spec", "Lsun/security/internal/spec/TlsKeyMaterialParameterSpec;", nullptr, $PRIVATE, $field(TlsKeyMaterialGenerator, spec)},
	{"protocolVersion", "I", nullptr, $PRIVATE, $field(TlsKeyMaterialGenerator, protocolVersion)},
	{}
};

$MethodInfo _TlsKeyMaterialGenerator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TlsKeyMaterialGenerator, init$, void)},
	{"engineGenerateKey", "()Ljavax/crypto/SecretKey;", nullptr, $PROTECTED, $virtualMethod(TlsKeyMaterialGenerator, engineGenerateKey, $SecretKey*)},
	{"engineGenerateKey0", "([B)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $method(TlsKeyMaterialGenerator, engineGenerateKey0, $SecretKey*, $bytes*), "java.security.GeneralSecurityException"},
	{"engineInit", "(Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsKeyMaterialGenerator, engineInit, void, $SecureRandom*)},
	{"engineInit", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsKeyMaterialGenerator, engineInit, void, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsKeyMaterialGenerator, engineInit, void, int32_t, $SecureRandom*)},
	{}
};

$ClassInfo _TlsKeyMaterialGenerator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.TlsKeyMaterialGenerator",
	"javax.crypto.KeyGeneratorSpi",
	nullptr,
	_TlsKeyMaterialGenerator_FieldInfo_,
	_TlsKeyMaterialGenerator_MethodInfo_
};

$Object* allocate$TlsKeyMaterialGenerator($Class* clazz) {
	return $of($alloc(TlsKeyMaterialGenerator));
}

$String* TlsKeyMaterialGenerator::MSG = nullptr;

void TlsKeyMaterialGenerator::init$() {
	$KeyGeneratorSpi::init$();
}

void TlsKeyMaterialGenerator::engineInit($SecureRandom* random) {
	$throwNew($InvalidParameterException, TlsKeyMaterialGenerator::MSG);
}

void TlsKeyMaterialGenerator::engineInit($AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($TlsKeyMaterialParameterSpec, params) == false) {
		$throwNew($InvalidAlgorithmParameterException, TlsKeyMaterialGenerator::MSG);
	}
	$set(this, spec, $cast($TlsKeyMaterialParameterSpec, params));
	if ("RAW"_s->equals($($nc($($nc(this->spec)->getMasterSecret()))->getFormat())) == false) {
		$throwNew($InvalidAlgorithmParameterException, "Key format must be RAW"_s);
	}
	int32_t var$0 = ($nc(this->spec)->getMajorVersion() << 8);
	this->protocolVersion = var$0 | $nc(this->spec)->getMinorVersion();
	if ((this->protocolVersion < 768) || (this->protocolVersion > 771)) {
		$throwNew($InvalidAlgorithmParameterException, "Only SSL 3.0, TLS 1.0/1.1/1.2 supported"_s);
	}
}

void TlsKeyMaterialGenerator::engineInit(int32_t keysize, $SecureRandom* random) {
	$throwNew($InvalidParameterException, TlsKeyMaterialGenerator::MSG);
}

$SecretKey* TlsKeyMaterialGenerator::engineGenerateKey() {
	$useLocalCurrentObjectStackCache();
	if (this->spec == nullptr) {
		$throwNew($IllegalStateException, "TlsKeyMaterialGenerator must be initialized"_s);
	}
	$var($bytes, masterSecret, $nc($($nc(this->spec)->getMasterSecret()))->getEncoded());
	{
		$var($Throwable, var$0, nullptr);
		$var($SecretKey, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, engineGenerateKey0(masterSecret));
				return$1 = true;
				goto $finally;
			} catch ($GeneralSecurityException& e) {
				$throwNew($ProviderException, static_cast<$Throwable*>(e));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(masterSecret, (int8_t)0);
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

$SecretKey* TlsKeyMaterialGenerator::engineGenerateKey0($bytes* masterSecret) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, clientRandom, $nc(this->spec)->getClientRandom());
	$var($bytes, serverRandom, $nc(this->spec)->getServerRandom());
	$var($SecretKey, clientMacKey, nullptr);
	$var($SecretKey, serverMacKey, nullptr);
	$var($SecretKey, clientCipherKey, nullptr);
	$var($SecretKey, serverCipherKey, nullptr);
	$var($IvParameterSpec, clientIv, nullptr);
	$var($IvParameterSpec, serverIv, nullptr);
	int32_t macLength = $nc(this->spec)->getMacKeyLength();
	int32_t expandedKeyLength = $nc(this->spec)->getExpandedCipherKeyLength();
	bool isExportable = (expandedKeyLength != 0);
	int32_t keyLength = $nc(this->spec)->getCipherKeyLength();
	int32_t ivLength = $nc(this->spec)->getIvLength();
	int32_t keyBlockLen = macLength + keyLength + (isExportable ? 0 : ivLength);
	keyBlockLen <<= 1;
	$var($bytes, keyBlock, nullptr);
	$var($MessageDigest, md5, nullptr);
	$var($MessageDigest, sha, nullptr);
	if (this->protocolVersion >= 771) {
		$var($bytes, seed, $TlsPrfGenerator::concat(serverRandom, clientRandom));
		$var($bytes, var$0, masterSecret);
		$var($bytes, var$1, $TlsPrfGenerator::LABEL_KEY_EXPANSION);
		$var($bytes, var$2, seed);
		int32_t var$3 = keyBlockLen;
		$var($String, var$4, $nc(this->spec)->getPRFHashAlg());
		int32_t var$5 = $nc(this->spec)->getPRFHashLength();
		$assign(keyBlock, $TlsPrfGenerator::doTLS12PRF(var$0, var$1, var$2, var$3, var$4, var$5, $nc(this->spec)->getPRFBlockSize()));
	} else if (this->protocolVersion >= 769) {
		$assign(md5, $MessageDigest::getInstance("MD5"_s));
		$assign(sha, $MessageDigest::getInstance("SHA1"_s));
		$var($bytes, seed, $TlsPrfGenerator::concat(serverRandom, clientRandom));
		$assign(keyBlock, $TlsPrfGenerator::doTLS10PRF(masterSecret, $TlsPrfGenerator::LABEL_KEY_EXPANSION, seed, keyBlockLen, md5, sha));
	} else {
		$assign(md5, $MessageDigest::getInstance("MD5"_s));
		$assign(sha, $MessageDigest::getInstance("SHA1"_s));
		$assign(keyBlock, $new($bytes, keyBlockLen));
		$var($bytes, tmp, $new($bytes, 20));
		{
			int32_t i = 0;
			int32_t remaining = keyBlockLen;
			for (; remaining > 0; ++i, remaining -= 16) {
				$init($TlsPrfGenerator);
				$nc(sha)->update($nc($TlsPrfGenerator::SSL3_CONST)->get(i));
				sha->update(masterSecret);
				sha->update(serverRandom);
				sha->update(clientRandom);
				sha->digest(tmp, 0, 20);
				$nc(md5)->update(masterSecret);
				md5->update(tmp);
				if (remaining >= 16) {
					md5->digest(keyBlock, i << 4, 16);
				} else {
					md5->digest(tmp, 0, 16);
					$System::arraycopy(tmp, 0, keyBlock, i << 4, remaining);
				}
			}
		}
	}
	int32_t ofs = 0;
	if (macLength != 0) {
		$assign(clientMacKey, $new($SecretKeySpec, keyBlock, ofs, macLength, "Mac"_s));
		ofs += macLength;
		$assign(serverMacKey, $new($SecretKeySpec, keyBlock, ofs, macLength, "Mac"_s));
		ofs += macLength;
	}
	if (keyLength == 0) {
		return $new($TlsKeyMaterialSpec, clientMacKey, serverMacKey);
	}
	$var($String, alg, $nc(this->spec)->getCipherAlgorithm());
	$var($bytes, clientKeyBytes, $new($bytes, keyLength));
	$System::arraycopy(keyBlock, ofs, clientKeyBytes, 0, keyLength);
	ofs += keyLength;
	$var($bytes, serverKeyBytes, $new($bytes, keyLength));
	$System::arraycopy(keyBlock, ofs, serverKeyBytes, 0, keyLength);
	ofs += keyLength;
	{
		$var($Throwable, var$6, nullptr);
		try {
			if (isExportable == false) {
				$assign(clientCipherKey, $new($SecretKeySpec, clientKeyBytes, alg));
				$assign(serverCipherKey, $new($SecretKeySpec, serverKeyBytes, alg));
				if (ivLength != 0) {
					$assign(clientIv, $new($IvParameterSpec, keyBlock, ofs, ivLength));
					ofs += ivLength;
					$assign(serverIv, $new($IvParameterSpec, keyBlock, ofs, ivLength));
					ofs += ivLength;
				}
			} else if (this->protocolVersion >= 770) {
				$throwNew($RuntimeException, "Internal Error:  TLS 1.1+ should not be negotiatingexportable ciphersuites"_s);
			} else if (this->protocolVersion == 769) {
				$var($bytes, seed, $TlsPrfGenerator::concat(clientRandom, serverRandom));
				$var($bytes, tmp, $TlsPrfGenerator::doTLS10PRF(clientKeyBytes, $TlsPrfGenerator::LABEL_CLIENT_WRITE_KEY, seed, expandedKeyLength, md5, sha));
				$assign(clientCipherKey, $new($SecretKeySpec, tmp, alg));
				$Arrays::fill(tmp, (int8_t)0);
				$assign(tmp, $TlsPrfGenerator::doTLS10PRF(serverKeyBytes, $TlsPrfGenerator::LABEL_SERVER_WRITE_KEY, seed, expandedKeyLength, md5, sha));
				$assign(serverCipherKey, $new($SecretKeySpec, tmp, alg));
				$Arrays::fill(tmp, (int8_t)0);
				if (ivLength != 0) {
					$var($bytes, block, $TlsPrfGenerator::doTLS10PRF(nullptr, $TlsPrfGenerator::LABEL_IV_BLOCK, seed, ivLength << 1, md5, sha));
					$assign(clientIv, $new($IvParameterSpec, block, 0, ivLength));
					$assign(serverIv, $new($IvParameterSpec, block, ivLength, ivLength));
				}
			} else {
				$var($bytes, tmp, $new($bytes, expandedKeyLength));
				$var($bytes, digest, nullptr);
				$nc(md5)->update(clientKeyBytes);
				md5->update(clientRandom);
				md5->update(serverRandom);
				$assign(digest, md5->digest());
				$System::arraycopy(digest, 0, tmp, 0, expandedKeyLength);
				$assign(clientCipherKey, $new($SecretKeySpec, tmp, alg));
				$Arrays::fill(digest, (int8_t)0);
				md5->update(serverKeyBytes);
				md5->update(serverRandom);
				md5->update(clientRandom);
				$assign(digest, md5->digest());
				$System::arraycopy(digest, 0, tmp, 0, expandedKeyLength);
				$assign(serverCipherKey, $new($SecretKeySpec, tmp, alg));
				$Arrays::fill(digest, (int8_t)0);
				$Arrays::fill(tmp, (int8_t)0);
				if (ivLength != 0) {
					$assign(tmp, $new($bytes, ivLength));
					md5->update(clientRandom);
					md5->update(serverRandom);
					$System::arraycopy($(md5->digest()), 0, tmp, 0, ivLength);
					$assign(clientIv, $new($IvParameterSpec, tmp));
					md5->update(serverRandom);
					md5->update(clientRandom);
					$System::arraycopy($(md5->digest()), 0, tmp, 0, ivLength);
					$assign(serverIv, $new($IvParameterSpec, tmp));
				}
			}
		} catch ($Throwable& var$7) {
			$assign(var$6, var$7);
		} /*finally*/ {
			$Arrays::fill(serverKeyBytes, (int8_t)0);
			$Arrays::fill(clientKeyBytes, (int8_t)0);
			$Arrays::fill(keyBlock, (int8_t)0);
		}
		if (var$6 != nullptr) {
			$throw(var$6);
		}
	}
	return $new($TlsKeyMaterialSpec, clientMacKey, serverMacKey, clientCipherKey, clientIv, serverCipherKey, serverIv);
}

TlsKeyMaterialGenerator::TlsKeyMaterialGenerator() {
}

void clinit$TlsKeyMaterialGenerator($Class* class$) {
	$assignStatic(TlsKeyMaterialGenerator::MSG, "TlsKeyMaterialGenerator must be initialized using a TlsKeyMaterialParameterSpec"_s);
}

$Class* TlsKeyMaterialGenerator::load$($String* name, bool initialize) {
	$loadClass(TlsKeyMaterialGenerator, name, initialize, &_TlsKeyMaterialGenerator_ClassInfo_, clinit$TlsKeyMaterialGenerator, allocate$TlsKeyMaterialGenerator);
	return class$;
}

$Class* TlsKeyMaterialGenerator::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com