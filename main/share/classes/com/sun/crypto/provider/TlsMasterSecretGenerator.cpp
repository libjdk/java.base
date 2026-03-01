#include <com/sun/crypto/provider/TlsMasterSecretGenerator.h>

#include <com/sun/crypto/provider/TlsMasterSecretGenerator$TlsMasterSecretKey.h>
#include <com/sun/crypto/provider/TlsPrfGenerator.h>
#include <java/lang/IllegalStateException.h>
#include <java/security/DigestException.h>
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
#include <sun/security/internal/spec/TlsMasterSecretParameterSpec.h>
#include <jcpp.h>

#undef LABEL_EXTENDED_MASTER_SECRET
#undef LABEL_MASTER_SECRET
#undef MSG
#undef SSL3_CONST

using $TlsMasterSecretGenerator$TlsMasterSecretKey = ::com::sun::crypto::provider::TlsMasterSecretGenerator$TlsMasterSecretKey;
using $TlsPrfGenerator = ::com::sun::crypto::provider::TlsPrfGenerator;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DigestException = ::java::security::DigestException;
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
using $TlsMasterSecretParameterSpec = ::sun::security::internal::spec::TlsMasterSecretParameterSpec;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _TlsMasterSecretGenerator_FieldInfo_[] = {
	{"MSG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TlsMasterSecretGenerator, MSG)},
	{"spec", "Lsun/security/internal/spec/TlsMasterSecretParameterSpec;", nullptr, $PRIVATE, $field(TlsMasterSecretGenerator, spec)},
	{"protocolVersion", "I", nullptr, $PRIVATE, $field(TlsMasterSecretGenerator, protocolVersion)},
	{}
};

$MethodInfo _TlsMasterSecretGenerator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TlsMasterSecretGenerator, init$, void)},
	{"engineGenerateKey", "()Ljavax/crypto/SecretKey;", nullptr, $PROTECTED, $virtualMethod(TlsMasterSecretGenerator, engineGenerateKey, $SecretKey*)},
	{"engineInit", "(Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsMasterSecretGenerator, engineInit, void, $SecureRandom*)},
	{"engineInit", "(Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsMasterSecretGenerator, engineInit, void, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(TlsMasterSecretGenerator, engineInit, void, int32_t, $SecureRandom*)},
	{}
};

$InnerClassInfo _TlsMasterSecretGenerator_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.TlsMasterSecretGenerator$TlsMasterSecretKey", "com.sun.crypto.provider.TlsMasterSecretGenerator", "TlsMasterSecretKey", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _TlsMasterSecretGenerator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.TlsMasterSecretGenerator",
	"javax.crypto.KeyGeneratorSpi",
	nullptr,
	_TlsMasterSecretGenerator_FieldInfo_,
	_TlsMasterSecretGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_TlsMasterSecretGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.TlsMasterSecretGenerator$TlsMasterSecretKey"
};

$Object* allocate$TlsMasterSecretGenerator($Class* clazz) {
	return $of($alloc(TlsMasterSecretGenerator));
}

$String* TlsMasterSecretGenerator::MSG = nullptr;

void TlsMasterSecretGenerator::init$() {
	$KeyGeneratorSpi::init$();
}

void TlsMasterSecretGenerator::engineInit($SecureRandom* random) {
	$throwNew($InvalidParameterException, TlsMasterSecretGenerator::MSG);
}

void TlsMasterSecretGenerator::engineInit($AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($TlsMasterSecretParameterSpec, params) == false) {
		$throwNew($InvalidAlgorithmParameterException, TlsMasterSecretGenerator::MSG);
	}
	$set(this, spec, $cast($TlsMasterSecretParameterSpec, params));
	if ("RAW"_s->equals($($nc($($nc(this->spec)->getPremasterSecret()))->getFormat())) == false) {
		$throwNew($InvalidAlgorithmParameterException, "Key format must be RAW"_s);
	}
	int32_t var$0 = ($nc(this->spec)->getMajorVersion() << 8);
	this->protocolVersion = var$0 | $nc(this->spec)->getMinorVersion();
	if ((this->protocolVersion < 768) || (this->protocolVersion > 771)) {
		$throwNew($InvalidAlgorithmParameterException, "Only SSL 3.0, TLS 1.0/1.1/1.2 supported"_s);
	}
}

void TlsMasterSecretGenerator::engineInit(int32_t keysize, $SecureRandom* random) {
	$throwNew($InvalidParameterException, TlsMasterSecretGenerator::MSG);
}

$SecretKey* TlsMasterSecretGenerator::engineGenerateKey() {
	$useLocalCurrentObjectStackCache();
	if (this->spec == nullptr) {
		$throwNew($IllegalStateException, "TlsMasterSecretGenerator must be initialized"_s);
	}
	$var($SecretKey, premasterKey, $nc(this->spec)->getPremasterSecret());
	$var($bytes, premaster, $nc(premasterKey)->getEncoded());
	int32_t premasterMajor = 0;
	int32_t premasterMinor = 0;
	if ($nc($(premasterKey->getAlgorithm()))->equals("TlsRsaPremasterSecret"_s)) {
		premasterMajor = (int32_t)($nc(premaster)->get(0) & (uint32_t)255);
		premasterMinor = (int32_t)(premaster->get(1) & (uint32_t)255);
	} else {
		premasterMajor = -1;
		premasterMinor = -1;
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($SecretKey, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($bytes, master, nullptr);
				if (this->protocolVersion >= 769) {
					$var($bytes, label, nullptr);
					$var($bytes, seed, nullptr);
					$var($bytes, extendedMasterSecretSessionHash, $nc(this->spec)->getExtendedMasterSecretSessionHash());
					if ($nc(extendedMasterSecretSessionHash)->length != 0) {
						$init($TlsPrfGenerator);
						$assign(label, $TlsPrfGenerator::LABEL_EXTENDED_MASTER_SECRET);
						$assign(seed, extendedMasterSecretSessionHash);
					} else {
						$var($bytes, clientRandom, $nc(this->spec)->getClientRandom());
						$var($bytes, serverRandom, $nc(this->spec)->getServerRandom());
						$init($TlsPrfGenerator);
						$assign(label, $TlsPrfGenerator::LABEL_MASTER_SECRET);
						$assign(seed, $TlsPrfGenerator::concat(clientRandom, serverRandom));
					}
					$var($bytes, var$3, nullptr);
					if (this->protocolVersion >= 771) {
						$var($bytes, var$4, premaster);
						$var($bytes, var$5, label);
						$var($bytes, var$6, seed);
						$var($String, var$7, $nc(this->spec)->getPRFHashAlg());
						int32_t var$8 = $nc(this->spec)->getPRFHashLength();
						$assign(var$3, $TlsPrfGenerator::doTLS12PRF(var$4, var$5, var$6, 48, var$7, var$8, $nc(this->spec)->getPRFBlockSize()));
					} else {
						$assign(var$3, $TlsPrfGenerator::doTLS10PRF(premaster, label, seed, 48));
					}
					$assign(master, var$3);
				} else {
					$assign(master, $new($bytes, 48));
					$var($MessageDigest, md5, $MessageDigest::getInstance("MD5"_s));
					$var($MessageDigest, sha, $MessageDigest::getInstance("SHA"_s));
					$var($bytes, clientRandom, $nc(this->spec)->getClientRandom());
					$var($bytes, serverRandom, $nc(this->spec)->getServerRandom());
					$var($bytes, tmp, $new($bytes, 20));
					for (int32_t i = 0; i < 3; ++i) {
						$init($TlsPrfGenerator);
						$nc(sha)->update($nc($TlsPrfGenerator::SSL3_CONST)->get(i));
						sha->update(premaster);
						sha->update(clientRandom);
						sha->update(serverRandom);
						sha->digest(tmp, 0, 20);
						sha->reset();
						$nc(md5)->update(premaster);
						md5->update(tmp);
						md5->digest(master, i << 4, 16);
						md5->reset();
					}
				}
				$assign(var$2, $new($TlsMasterSecretGenerator$TlsMasterSecretKey, master, premasterMajor, premasterMinor));
				return$1 = true;
				goto $finally;
			} catch ($NoSuchAlgorithmException& e) {
				$throwNew($ProviderException, static_cast<$Throwable*>(e));
			} catch ($DigestException& e) {
				$throwNew($ProviderException, static_cast<$Throwable*>(e));
			}
		} catch ($Throwable& var$9) {
			$assign(var$0, var$9);
		} $finally: {
			if (premaster != nullptr) {
				$Arrays::fill(premaster, (int8_t)0);
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

TlsMasterSecretGenerator::TlsMasterSecretGenerator() {
}

void clinit$TlsMasterSecretGenerator($Class* class$) {
	$assignStatic(TlsMasterSecretGenerator::MSG, "TlsMasterSecretGenerator must be initialized using a TlsMasterSecretParameterSpec"_s);
}

$Class* TlsMasterSecretGenerator::load$($String* name, bool initialize) {
	$loadClass(TlsMasterSecretGenerator, name, initialize, &_TlsMasterSecretGenerator_ClassInfo_, clinit$TlsMasterSecretGenerator, allocate$TlsMasterSecretGenerator);
	return class$;
}

$Class* TlsMasterSecretGenerator::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com