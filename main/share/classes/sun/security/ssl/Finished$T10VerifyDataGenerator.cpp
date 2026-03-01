#include <sun/security/ssl/Finished$T10VerifyDataGenerator.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/ProviderException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/KeyGenerator.h>
#include <javax/crypto/SecretKey.h>
#include <sun/security/internal/spec/TlsPrfParameterSpec.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/Finished.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <jcpp.h>

#undef H_NONE

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $ProviderException = ::java::security::ProviderException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeyGenerator = ::javax::crypto::KeyGenerator;
using $SecretKey = ::javax::crypto::SecretKey;
using $TlsPrfParameterSpec = ::sun::security::internal::spec::TlsPrfParameterSpec;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _Finished$T10VerifyDataGenerator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Finished$T10VerifyDataGenerator, init$, void)},
	{"createVerifyData", "(Lsun/security/ssl/HandshakeContext;Z)[B", nullptr, $PUBLIC, $virtualMethod(Finished$T10VerifyDataGenerator, createVerifyData, $bytes*, $HandshakeContext*, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _Finished$T10VerifyDataGenerator_InnerClassesInfo_[] = {
	{"sun.security.ssl.Finished$T10VerifyDataGenerator", "sun.security.ssl.Finished", "T10VerifyDataGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.Finished$VerifyDataGenerator", "sun.security.ssl.Finished", "VerifyDataGenerator", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Finished$T10VerifyDataGenerator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.Finished$T10VerifyDataGenerator",
	"java.lang.Object",
	"sun.security.ssl.Finished$VerifyDataGenerator",
	nullptr,
	_Finished$T10VerifyDataGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_Finished$T10VerifyDataGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.Finished"
};

$Object* allocate$Finished$T10VerifyDataGenerator($Class* clazz) {
	return $of($alloc(Finished$T10VerifyDataGenerator));
}

void Finished$T10VerifyDataGenerator::init$() {
}

$bytes* Finished$T10VerifyDataGenerator::createVerifyData($HandshakeContext* context, bool isValidation) {
	$useLocalCurrentObjectStackCache();
	$var($HandshakeHash, handshakeHash, $nc(context)->handshakeHash);
	$var($SecretKey, masterSecretKey, $nc(context->handshakeSession)->getMasterSecret());
	bool useClientLabel = ($nc(context->sslConfig)->isClientMode && !isValidation) || (!$nc(context->sslConfig)->isClientMode && isValidation);
	$var($String, tlsLabel, nullptr);
	if (useClientLabel) {
		$assign(tlsLabel, "client finished"_s);
	} else {
		$assign(tlsLabel, "server finished"_s);
	}
	try {
		$var($bytes, seed, $nc(handshakeHash)->digest());
		$var($String, prfAlg, "SunTlsPrf"_s);
		$init($CipherSuite$HashAlg);
		$CipherSuite$HashAlg* hashAlg = $CipherSuite$HashAlg::H_NONE;
		$var($TlsPrfParameterSpec, spec, $new($TlsPrfParameterSpec, masterSecretKey, tlsLabel, seed, 12, $nc(hashAlg)->name$, hashAlg->hashLength, hashAlg->blockSize));
		$var($KeyGenerator, kg, $KeyGenerator::getInstance(prfAlg));
		$nc(kg)->init(static_cast<$AlgorithmParameterSpec*>(spec));
		$var($SecretKey, prfKey, kg->generateKey());
		if (!"RAW"_s->equals($($nc(prfKey)->getFormat()))) {
			$throwNew($ProviderException, $$str({"Invalid PRF output, format must be RAW. Format received: "_s, $($nc(prfKey)->getFormat())}));
		}
		return $nc(prfKey)->getEncoded();
	} catch ($GeneralSecurityException& e) {
		$throwNew($RuntimeException, "PRF failed"_s, e);
	}
	$shouldNotReachHere();
}

Finished$T10VerifyDataGenerator::Finished$T10VerifyDataGenerator() {
}

$Class* Finished$T10VerifyDataGenerator::load$($String* name, bool initialize) {
	$loadClass(Finished$T10VerifyDataGenerator, name, initialize, &_Finished$T10VerifyDataGenerator_ClassInfo_, allocate$Finished$T10VerifyDataGenerator);
	return class$;
}

$Class* Finished$T10VerifyDataGenerator::class$ = nullptr;

		} // ssl
	} // security
} // sun