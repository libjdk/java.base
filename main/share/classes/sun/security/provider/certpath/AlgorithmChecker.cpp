#include <sun/security/provider/certpath/AlgorithmChecker.h>

#include <java/lang/Enum.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathValidatorException$BasicReason.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/PKIXReason.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/interfaces/DSAParams.h>
#include <java/security/interfaces/DSAPublicKey.h>
#include <java/security/spec/DSAPublicKeySpec.h>
#include <java/security/spec/KeySpec.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/EnumSet.h>
#include <java/util/Set.h>
#include <sun/security/provider/certpath/CertPathConstraintsParameters.h>
#include <sun/security/provider/certpath/PKIX.h>
#include <sun/security/util/ConstraintsParameters.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DisabledAlgorithmConstraints.h>
#include <sun/security/util/KeyUtil.h>
#include <sun/security/validator/Validator.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/X509CRLImpl.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef ALGORITHM_CONSTRAINED
#undef INVALID_KEY_USAGE
#undef KEY_AGREEMENT
#undef KEY_ENCAPSULATION
#undef KU_PRIMITIVE_SET
#undef PUBLIC_KEY_ENCRYPTION
#undef SIGNATURE
#undef SIGNATURE_PRIMITIVE_SET
#undef SIG_ALG
#undef VAR_GENERIC

using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $PublicKey = ::java::security::PublicKey;
using $CRLException = ::java::security::cert::CRLException;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$BasicReason = ::java::security::cert::CertPathValidatorException$BasicReason;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $PKIXReason = ::java::security::cert::PKIXReason;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $DSAParams = ::java::security::interfaces::DSAParams;
using $DSAPublicKey = ::java::security::interfaces::DSAPublicKey;
using $DSAPublicKeySpec = ::java::security::spec::DSAPublicKeySpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $EnumSet = ::java::util::EnumSet;
using $Set = ::java::util::Set;
using $CertPathConstraintsParameters = ::sun::security::provider::certpath::CertPathConstraintsParameters;
using $PKIX = ::sun::security::provider::certpath::PKIX;
using $ConstraintsParameters = ::sun::security::util::ConstraintsParameters;
using $Debug = ::sun::security::util::Debug;
using $DisabledAlgorithmConstraints = ::sun::security::util::DisabledAlgorithmConstraints;
using $KeyUtil = ::sun::security::util::KeyUtil;
using $Validator = ::sun::security::validator::Validator;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $X509CRLImpl = ::sun::security::x509::X509CRLImpl;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _AlgorithmChecker_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AlgorithmChecker, debug)},
	{"constraints", "Ljava/security/AlgorithmConstraints;", nullptr, $PRIVATE | $FINAL, $field(AlgorithmChecker, constraints)},
	{"trustedPubKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE | $FINAL, $field(AlgorithmChecker, trustedPubKey)},
	{"date", "Ljava/util/Date;", nullptr, $PRIVATE | $FINAL, $field(AlgorithmChecker, date)},
	{"prevPubKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(AlgorithmChecker, prevPubKey)},
	{"variant", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(AlgorithmChecker, variant)},
	{"anchor", "Ljava/security/cert/TrustAnchor;", nullptr, $PRIVATE, $field(AlgorithmChecker, anchor)},
	{"SIGNATURE_PRIMITIVE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/CryptoPrimitive;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AlgorithmChecker, SIGNATURE_PRIMITIVE_SET)},
	{"KU_PRIMITIVE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/CryptoPrimitive;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AlgorithmChecker, KU_PRIMITIVE_SET)},
	{"certPathDefaultConstraints", "Lsun/security/util/DisabledAlgorithmConstraints;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AlgorithmChecker, certPathDefaultConstraints)},
	{}
};

$MethodInfo _AlgorithmChecker_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/TrustAnchor;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(AlgorithmChecker, init$, void, $TrustAnchor*, $String*)},
	{"<init>", "(Ljava/security/AlgorithmConstraints;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(AlgorithmChecker, init$, void, $AlgorithmConstraints*, $String*)},
	{"<init>", "(Ljava/security/cert/TrustAnchor;Ljava/security/AlgorithmConstraints;Ljava/util/Date;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(AlgorithmChecker, init$, void, $TrustAnchor*, $AlgorithmConstraints*, $Date*, $String*)},
	{"<init>", "(Ljava/security/cert/TrustAnchor;Ljava/util/Date;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(AlgorithmChecker, init$, void, $TrustAnchor*, $Date*, $String*)},
	{"check", "(Ljava/security/cert/Certificate;Ljava/util/Collection;)V", "(Ljava/security/cert/Certificate;Ljava/util/Collection<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(AlgorithmChecker, check, void, $Certificate*, $Collection*), "java.security.cert.CertPathValidatorException"},
	{"check", "(Ljava/security/PublicKey;Ljava/security/cert/X509CRL;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)V", nullptr, $STATIC, $staticMethod(AlgorithmChecker, check, void, $PublicKey*, $X509CRL*, $String*, $TrustAnchor*), "java.security.cert.CertPathValidatorException"},
	{"check", "(Ljava/security/PublicKey;Lsun/security/x509/AlgorithmId;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)V", nullptr, $STATIC, $staticMethod(AlgorithmChecker, check, void, $PublicKey*, $AlgorithmId*, $String*, $TrustAnchor*), "java.security.cert.CertPathValidatorException"},
	{"getSupportedExtensions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(AlgorithmChecker, getSupportedExtensions, $Set*)},
	{"init", "(Z)V", nullptr, $PUBLIC, $virtualMethod(AlgorithmChecker, init, void, bool), "java.security.cert.CertPathValidatorException"},
	{"isForwardCheckingSupported", "()Z", nullptr, $PUBLIC, $virtualMethod(AlgorithmChecker, isForwardCheckingSupported, bool)},
	{"trySetTrustAnchor", "(Ljava/security/cert/TrustAnchor;)V", nullptr, 0, $method(AlgorithmChecker, trySetTrustAnchor, void, $TrustAnchor*)},
	{}
};

$ClassInfo _AlgorithmChecker_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.certpath.AlgorithmChecker",
	"java.security.cert.PKIXCertPathChecker",
	nullptr,
	_AlgorithmChecker_FieldInfo_,
	_AlgorithmChecker_MethodInfo_
};

$Object* allocate$AlgorithmChecker($Class* clazz) {
	return $of($alloc(AlgorithmChecker));
}

$Debug* AlgorithmChecker::debug = nullptr;
$Set* AlgorithmChecker::SIGNATURE_PRIMITIVE_SET = nullptr;
$Set* AlgorithmChecker::KU_PRIMITIVE_SET = nullptr;
$DisabledAlgorithmConstraints* AlgorithmChecker::certPathDefaultConstraints = nullptr;

void AlgorithmChecker::init$($TrustAnchor* anchor, $String* variant) {
	AlgorithmChecker::init$(anchor, AlgorithmChecker::certPathDefaultConstraints, nullptr, variant);
}

void AlgorithmChecker::init$($AlgorithmConstraints* constraints, $String* variant) {
	AlgorithmChecker::init$(nullptr, constraints, nullptr, variant);
}

void AlgorithmChecker::init$($TrustAnchor* anchor, $AlgorithmConstraints* constraints, $Date* date, $String* variant) {
	$PKIXCertPathChecker::init$();
	if (anchor != nullptr) {
		if (anchor->getTrustedCert() != nullptr) {
			$set(this, trustedPubKey, $nc($(anchor->getTrustedCert()))->getPublicKey());
		} else {
			$set(this, trustedPubKey, anchor->getCAPublicKey());
		}
		$set(this, anchor, anchor);
	} else {
		$set(this, trustedPubKey, nullptr);
	}
	$set(this, prevPubKey, this->trustedPubKey);
	$set(this, constraints, constraints == nullptr ? static_cast<$AlgorithmConstraints*>(AlgorithmChecker::certPathDefaultConstraints) : constraints);
	$set(this, date, date);
	$init($Validator);
	$set(this, variant, variant == nullptr ? $Validator::VAR_GENERIC : variant);
}

void AlgorithmChecker::init$($TrustAnchor* anchor, $Date* pkixdate, $String* variant) {
	AlgorithmChecker::init$(anchor, AlgorithmChecker::certPathDefaultConstraints, pkixdate, variant);
}

void AlgorithmChecker::init(bool forward) {
	if (!forward) {
		if (this->trustedPubKey != nullptr) {
			$set(this, prevPubKey, this->trustedPubKey);
		} else {
			$set(this, prevPubKey, nullptr);
		}
	} else {
		$throwNew($CertPathValidatorException, "forward checking not supported"_s);
	}
}

bool AlgorithmChecker::isForwardCheckingSupported() {
	return false;
}

$Set* AlgorithmChecker::getSupportedExtensions() {
	return nullptr;
}

void AlgorithmChecker::check($Certificate* cert, $Collection* unresolvedCritExts) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($X509Certificate, cert)) || this->constraints == nullptr) {
		return;
	}
	$var($booleans, keyUsage, $nc(($cast($X509Certificate, cert)))->getKeyUsage());
	if (keyUsage != nullptr && keyUsage->length < 9) {
		$init($PKIXReason);
		$throwNew($CertPathValidatorException, "incorrect KeyUsage extension"_s, nullptr, nullptr, -1, $PKIXReason::INVALID_KEY_USAGE);
	}
	$var($X509CertImpl, x509Cert, nullptr);
	$var($AlgorithmId, algorithmId, nullptr);
	try {
		$assign(x509Cert, $X509CertImpl::toImpl($cast($X509Certificate, cert)));
		$assign(algorithmId, $cast($AlgorithmId, $nc(x509Cert)->get($X509CertImpl::SIG_ALG)));
	} catch ($CertificateException& ce) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(ce));
	}
	$var($AlgorithmParameters, currSigAlgParams, $nc(algorithmId)->getParameters());
	$var($PublicKey, currPubKey, $nc(cert)->getPublicKey());
	$var($String, currSigAlg, $nc(x509Cert)->getSigAlgName());
	if (!$nc(this->constraints)->permits(AlgorithmChecker::SIGNATURE_PRIMITIVE_SET, currSigAlg, currSigAlgParams)) {
		$init($CertPathValidatorException$BasicReason);
		$throwNew($CertPathValidatorException, $$str({"Algorithm constraints check failed on signature algorithm: "_s, currSigAlg}), nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::ALGORITHM_CONSTRAINED);
	}
	$var($Set, primitives, AlgorithmChecker::KU_PRIMITIVE_SET);
	if (keyUsage != nullptr) {
		$load($CryptoPrimitive);
		$assign(primitives, $EnumSet::noneOf($CryptoPrimitive::class$));
		if (keyUsage->get(0) || keyUsage->get(1) || keyUsage->get(5) || keyUsage->get(6)) {
			$init($CryptoPrimitive);
			$nc(primitives)->add($CryptoPrimitive::SIGNATURE);
		}
		if (keyUsage->get(2)) {
			$init($CryptoPrimitive);
			$nc(primitives)->add($CryptoPrimitive::KEY_ENCAPSULATION);
		}
		if (keyUsage->get(3)) {
			$init($CryptoPrimitive);
			$nc(primitives)->add($CryptoPrimitive::PUBLIC_KEY_ENCRYPTION);
		}
		if (keyUsage->get(4)) {
			$init($CryptoPrimitive);
			$nc(primitives)->add($CryptoPrimitive::KEY_AGREEMENT);
		}
		if ($nc(primitives)->isEmpty()) {
			$init($PKIXReason);
			$throwNew($CertPathValidatorException, "incorrect KeyUsage extension bits"_s, nullptr, nullptr, -1, $PKIXReason::INVALID_KEY_USAGE);
		}
	}
	$var($ConstraintsParameters, cp, $new($CertPathConstraintsParameters, x509Cert, this->variant, this->anchor, this->date));
	if ($instanceOf($DisabledAlgorithmConstraints, this->constraints)) {
		$nc(($cast($DisabledAlgorithmConstraints, this->constraints)))->permits(currSigAlg, currSigAlgParams, cp);
	} else {
		$nc(AlgorithmChecker::certPathDefaultConstraints)->permits(currSigAlg, currSigAlgParams, cp);
		if (!$nc(this->constraints)->permits(primitives, currPubKey)) {
			$var($String, var$1, $$str({"Algorithm constraints check failed on key "_s, $($nc(currPubKey)->getAlgorithm()), " with size of "_s}));
			$var($String, var$0, $$concat(var$1, $$str($KeyUtil::getKeySize(static_cast<$Key*>(currPubKey)))));
			$init($CertPathValidatorException$BasicReason);
			$throwNew($CertPathValidatorException, $$concat(var$0, "bits"_s), nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::ALGORITHM_CONSTRAINED);
		}
	}
	if (this->prevPubKey == nullptr) {
		$set(this, prevPubKey, currPubKey);
		return;
	}
	if (!$nc(this->constraints)->permits(AlgorithmChecker::SIGNATURE_PRIMITIVE_SET, currSigAlg, this->prevPubKey, currSigAlgParams)) {
		$init($CertPathValidatorException$BasicReason);
		$throwNew($CertPathValidatorException, $$str({"Algorithm constraints check failed on signature algorithm: "_s, currSigAlg}), nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::ALGORITHM_CONSTRAINED);
	}
	if ($PKIX::isDSAPublicKeyWithoutParams(currPubKey)) {
		if (!($instanceOf($DSAPublicKey, this->prevPubKey))) {
			$throwNew($CertPathValidatorException, "Input key is not of a appropriate type for inheriting parameters"_s);
		}
		$var($DSAParams, params, $nc(($cast($DSAPublicKey, this->prevPubKey)))->getParams());
		if (params == nullptr) {
			$throwNew($CertPathValidatorException, "Key parameters missing from public key."_s);
		}
		try {
			$var($BigInteger, y, $nc(($cast($DSAPublicKey, currPubKey)))->getY());
			$var($KeyFactory, kf, $KeyFactory::getInstance("DSA"_s));
			$var($BigInteger, var$2, y);
			$var($BigInteger, var$3, $nc(params)->getP());
			$var($BigInteger, var$4, params->getQ());
			$var($DSAPublicKeySpec, ks, $new($DSAPublicKeySpec, var$2, var$3, var$4, $(params->getG())));
			$assign(currPubKey, $nc(kf)->generatePublic(ks));
		} catch ($GeneralSecurityException& e) {
			$throwNew($CertPathValidatorException, $$str({"Unable to generate key with inherited parameters: "_s, $(e->getMessage())}), e);
		}
	}
	$set(this, prevPubKey, currPubKey);
}

void AlgorithmChecker::trySetTrustAnchor($TrustAnchor* anchor) {
	if (this->prevPubKey == nullptr) {
		if (anchor == nullptr) {
			$throwNew($IllegalArgumentException, "The trust anchor cannot be null"_s);
		}
		if ($nc(anchor)->getTrustedCert() != nullptr) {
			$set(this, prevPubKey, $nc($(anchor->getTrustedCert()))->getPublicKey());
		} else {
			$set(this, prevPubKey, anchor->getCAPublicKey());
		}
		$set(this, anchor, anchor);
	}
}

void AlgorithmChecker::check($PublicKey* key, $X509CRL* crl, $String* variant, $TrustAnchor* anchor) {
	$init(AlgorithmChecker);
	$useLocalCurrentObjectStackCache();
	$var($X509CRLImpl, x509CRLImpl, nullptr);
	try {
		$assign(x509CRLImpl, $X509CRLImpl::toImpl(crl));
	} catch ($CRLException& ce) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(ce));
	}
	$var($AlgorithmId, algorithmId, $nc(x509CRLImpl)->getSigAlgId());
	check(key, algorithmId, variant, anchor);
}

void AlgorithmChecker::check($PublicKey* key, $AlgorithmId* algorithmId, $String* variant, $TrustAnchor* anchor) {
	$init(AlgorithmChecker);
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(algorithmId)->getName());
	$var($AlgorithmParameters, var$1, algorithmId->getParameters());
	$nc(AlgorithmChecker::certPathDefaultConstraints)->permits(var$0, var$1, static_cast<$ConstraintsParameters*>($$new($CertPathConstraintsParameters, key, variant, anchor)));
}

void clinit$AlgorithmChecker($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(AlgorithmChecker::debug, $Debug::getInstance("certpath"_s));
	$init($CryptoPrimitive);
	$assignStatic(AlgorithmChecker::SIGNATURE_PRIMITIVE_SET, $Collections::unmodifiableSet($($EnumSet::of($CryptoPrimitive::SIGNATURE))));
	$assignStatic(AlgorithmChecker::KU_PRIMITIVE_SET, $Collections::unmodifiableSet($($EnumSet::of($CryptoPrimitive::SIGNATURE, $CryptoPrimitive::KEY_ENCAPSULATION, $CryptoPrimitive::PUBLIC_KEY_ENCRYPTION, $CryptoPrimitive::KEY_AGREEMENT))));
	$assignStatic(AlgorithmChecker::certPathDefaultConstraints, $DisabledAlgorithmConstraints::certPathConstraints());
}

AlgorithmChecker::AlgorithmChecker() {
}

$Class* AlgorithmChecker::load$($String* name, bool initialize) {
	$loadClass(AlgorithmChecker, name, initialize, &_AlgorithmChecker_ClassInfo_, clinit$AlgorithmChecker, allocate$AlgorithmChecker);
	return class$;
}

$Class* AlgorithmChecker::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun