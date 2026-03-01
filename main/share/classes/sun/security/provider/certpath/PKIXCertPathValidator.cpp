#include <sun/security/provider/certpath/PKIXCertPathValidator.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathChecker.h>
#include <java/security/cert/CertPathParameters.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/CertPathValidatorResult.h>
#include <java/security/cert/CertPathValidatorSpi.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/PKIXCertPathValidatorResult.h>
#include <java/security/cert/PKIXReason.h>
#include <java/security/cert/PKIXRevocationChecker.h>
#include <java/security/cert/PolicyNode.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/ToIntFunction.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/Stream.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <jdk/internal/event/EventHelper.h>
#include <jdk/internal/event/X509ValidationEvent.h>
#include <sun/security/provider/certpath/AdaptableX509CertSelector.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/provider/certpath/BasicChecker.h>
#include <sun/security/provider/certpath/ConstraintsChecker.h>
#include <sun/security/provider/certpath/KeyChecker.h>
#include <sun/security/provider/certpath/PKIX$ValidatorParams.h>
#include <sun/security/provider/certpath/PKIX.h>
#include <sun/security/provider/certpath/PKIXMasterCertPathValidator.h>
#include <sun/security/provider/certpath/PolicyChecker.h>
#include <sun/security/provider/certpath/PolicyNodeImpl.h>
#include <sun/security/provider/certpath/RevocationChecker.h>
#include <sun/security/provider/certpath/UntrustedChecker.h>
#include <sun/security/util/Debug.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef ANY_POLICY
#undef NO_TRUST_ANCHOR

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $PublicKey = ::java::security::PublicKey;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathChecker = ::java::security::cert::CertPathChecker;
using $CertPathParameters = ::java::security::cert::CertPathParameters;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $CertPathValidatorResult = ::java::security::cert::CertPathValidatorResult;
using $CertPathValidatorSpi = ::java::security::cert::CertPathValidatorSpi;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $PKIXCertPathValidatorResult = ::java::security::cert::PKIXCertPathValidatorResult;
using $PKIXReason = ::java::security::cert::PKIXReason;
using $PKIXRevocationChecker = ::java::security::cert::PKIXRevocationChecker;
using $PolicyNode = ::java::security::cert::PolicyNode;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $ToIntFunction = ::java::util::function::ToIntFunction;
using $IntStream = ::java::util::stream::IntStream;
using $Stream = ::java::util::stream::Stream;
using $EventHelper = ::jdk::internal::event::EventHelper;
using $X509ValidationEvent = ::jdk::internal::event::X509ValidationEvent;
using $AdaptableX509CertSelector = ::sun::security::provider::certpath::AdaptableX509CertSelector;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $BasicChecker = ::sun::security::provider::certpath::BasicChecker;
using $ConstraintsChecker = ::sun::security::provider::certpath::ConstraintsChecker;
using $KeyChecker = ::sun::security::provider::certpath::KeyChecker;
using $PKIX = ::sun::security::provider::certpath::PKIX;
using $PKIX$ValidatorParams = ::sun::security::provider::certpath::PKIX$ValidatorParams;
using $PKIXMasterCertPathValidator = ::sun::security::provider::certpath::PKIXMasterCertPathValidator;
using $PolicyChecker = ::sun::security::provider::certpath::PolicyChecker;
using $PolicyNodeImpl = ::sun::security::provider::certpath::PolicyNodeImpl;
using $RevocationChecker = ::sun::security::provider::certpath::RevocationChecker;
using $UntrustedChecker = ::sun::security::provider::certpath::UntrustedChecker;
using $Debug = ::sun::security::util::Debug;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

class PKIXCertPathValidator$$Lambda$hashCode : public $ToIntFunction {
	$class(PKIXCertPathValidator$$Lambda$hashCode, $NO_CLASS_INIT, $ToIntFunction)
public:
	void init$() {
	}
	virtual int32_t applyAsInt(Object$* inst$) override {
		 return $sure($Certificate, inst$)->hashCode();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PKIXCertPathValidator$$Lambda$hashCode>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PKIXCertPathValidator$$Lambda$hashCode::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PKIXCertPathValidator$$Lambda$hashCode, init$, void)},
	{"applyAsInt", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidator$$Lambda$hashCode, applyAsInt, int32_t, Object$*)},
	{}
};
$ClassInfo PKIXCertPathValidator$$Lambda$hashCode::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.provider.certpath.PKIXCertPathValidator$$Lambda$hashCode",
	"java.lang.Object",
	"java.util.function.ToIntFunction",
	nullptr,
	methodInfos
};
$Class* PKIXCertPathValidator$$Lambda$hashCode::load$($String* name, bool initialize) {
	$loadClass(PKIXCertPathValidator$$Lambda$hashCode, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PKIXCertPathValidator$$Lambda$hashCode::class$ = nullptr;

$FieldInfo _PKIXCertPathValidator_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKIXCertPathValidator, debug)},
	{"validationCounter", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKIXCertPathValidator, validationCounter)},
	{}
};

$MethodInfo _PKIXCertPathValidator_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PKIXCertPathValidator, init$, void)},
	{"engineGetRevocationChecker", "()Ljava/security/cert/CertPathChecker;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidator, engineGetRevocationChecker, $CertPathChecker*)},
	{"engineValidate", "(Ljava/security/cert/CertPath;Ljava/security/cert/CertPathParameters;)Ljava/security/cert/CertPathValidatorResult;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidator, engineValidate, $CertPathValidatorResult*, $CertPath*, $CertPathParameters*), "java.security.cert.CertPathValidatorException,java.security.InvalidAlgorithmParameterException"},
	{"validate", "(Lsun/security/provider/certpath/PKIX$ValidatorParams;)Ljava/security/cert/PKIXCertPathValidatorResult;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKIXCertPathValidator, validate, $PKIXCertPathValidatorResult*, $PKIX$ValidatorParams*), "java.security.cert.CertPathValidatorException"},
	{"validate", "(Ljava/security/cert/TrustAnchor;Lsun/security/provider/certpath/PKIX$ValidatorParams;)Ljava/security/cert/PKIXCertPathValidatorResult;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKIXCertPathValidator, validate, $PKIXCertPathValidatorResult*, $TrustAnchor*, $PKIX$ValidatorParams*), "java.security.cert.CertPathValidatorException"},
	{}
};

$ClassInfo _PKIXCertPathValidator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.certpath.PKIXCertPathValidator",
	"java.security.cert.CertPathValidatorSpi",
	nullptr,
	_PKIXCertPathValidator_FieldInfo_,
	_PKIXCertPathValidator_MethodInfo_
};

$Object* allocate$PKIXCertPathValidator($Class* clazz) {
	return $of($alloc(PKIXCertPathValidator));
}

$Debug* PKIXCertPathValidator::debug = nullptr;
$AtomicLong* PKIXCertPathValidator::validationCounter = nullptr;

void PKIXCertPathValidator::init$() {
	$CertPathValidatorSpi::init$();
}

$CertPathChecker* PKIXCertPathValidator::engineGetRevocationChecker() {
	return $new($RevocationChecker);
}

$CertPathValidatorResult* PKIXCertPathValidator::engineValidate($CertPath* cp, $CertPathParameters* params) {
	$var($PKIX$ValidatorParams, valParams, $PKIX::checkParams(cp, params));
	return validate(valParams);
}

$PKIXCertPathValidatorResult* PKIXCertPathValidator::validate($PKIX$ValidatorParams* params) {
	$init(PKIXCertPathValidator);
	$useLocalCurrentObjectStackCache();
	if (PKIXCertPathValidator::debug != nullptr) {
		$nc(PKIXCertPathValidator::debug)->println("PKIXCertPathValidator.engineValidate()..."_s);
	}
	$var($AdaptableX509CertSelector, selector, nullptr);
	$var($List, certList, $nc(params)->certificates());
	if (!$nc(certList)->isEmpty()) {
		$assign(selector, $new($AdaptableX509CertSelector));
		$var($X509Certificate, firstCert, $cast($X509Certificate, certList->get(0)));
		selector->setSubject($($nc(firstCert)->getIssuerX500Principal()));
		try {
			$var($X509CertImpl, firstCertImpl, $X509CertImpl::toImpl(firstCert));
			selector->setSkiAndSerialNumber($($nc(firstCertImpl)->getAuthorityKeyIdentifierExtension()));
		} catch ($CertificateException& e) {
		} catch ($IOException& e) {
		}
	}
	$var($CertPathValidatorException, lastException, nullptr);
	{
		$var($Iterator, i$, $nc($(params->trustAnchors()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				$var($X509Certificate, trustedCert, $nc(anchor)->getTrustedCert());
				if (trustedCert != nullptr) {
					if (selector != nullptr && !selector->match(trustedCert)) {
						if (PKIXCertPathValidator::debug != nullptr && $Debug::isVerbose()) {
							$nc(PKIXCertPathValidator::debug)->println("NO - don\'t try this trustedCert"_s);
						}
						continue;
					}
					if (PKIXCertPathValidator::debug != nullptr) {
						$nc(PKIXCertPathValidator::debug)->println("YES - try this trustedCert"_s);
						$nc(PKIXCertPathValidator::debug)->println($$str({"anchor.getTrustedCert().getSubjectX500Principal() = "_s, $(trustedCert->getSubjectX500Principal())}));
					}
				} else {
					if (PKIXCertPathValidator::debug != nullptr) {
						$nc(PKIXCertPathValidator::debug)->println("PKIXCertPathValidator.engineValidate(): anchor.getTrustedCert() == null"_s);
					}
				}
				try {
					return validate(anchor, params);
				} catch ($CertPathValidatorException& cpe) {
					$assign(lastException, cpe);
				}
			}
		}
	}
	if (lastException != nullptr) {
		$throw(lastException);
	}
	$init($PKIXReason);
	$throwNew($CertPathValidatorException, "Path does not chain with any of the trust anchors"_s, nullptr, nullptr, -1, $PKIXReason::NO_TRUST_ANCHOR);
	$shouldNotReachHere();
}

$PKIXCertPathValidatorResult* PKIXCertPathValidator::validate($TrustAnchor* anchor, $PKIX$ValidatorParams* params) {
	$init(PKIXCertPathValidator);
	$useLocalCurrentObjectStackCache();
	$var($UntrustedChecker, untrustedChecker, $new($UntrustedChecker));
	$var($X509Certificate, anchorCert, $nc(anchor)->getTrustedCert());
	if (anchorCert != nullptr) {
		untrustedChecker->check(anchorCert);
	}
	int32_t certPathLen = $nc($($nc(params)->certificates()))->size();
	$var($List, certPathCheckers, $new($ArrayList));
	certPathCheckers->add(untrustedChecker);
	$var($TrustAnchor, var$0, anchor);
	$var($Date, var$1, params->date());
	certPathCheckers->add($$new($AlgorithmChecker, var$0, nullptr, var$1, $(params->variant())));
	certPathCheckers->add($$new($KeyChecker, certPathLen, $(params->targetCertConstraints())));
	certPathCheckers->add($$new($ConstraintsChecker, certPathLen));
	$init($PolicyChecker);
	$var($PolicyNodeImpl, rootNode, $new($PolicyNodeImpl, nullptr, $PolicyChecker::ANY_POLICY, nullptr, false, $($Collections::singleton($PolicyChecker::ANY_POLICY)), false));
	$var($Set, var$2, params->initialPolicies());
	int32_t var$3 = certPathLen;
	bool var$4 = params->explicitPolicyRequired();
	bool var$5 = params->policyMappingInhibited();
	bool var$6 = params->anyPolicyInhibited();
	$var($PolicyChecker, pc, $new($PolicyChecker, var$2, var$3, var$4, var$5, var$6, params->policyQualifiersRejected(), rootNode));
	certPathCheckers->add(pc);
	$var($TrustAnchor, var$7, anchor);
	$var($Date, var$8, params->date());
	$var($BasicChecker, bc, $new($BasicChecker, var$7, var$8, $(params->sigProvider()), false));
	certPathCheckers->add(bc);
	bool revCheckerAdded = false;
	$var($List, checkers, params->certPathCheckers());
	{
		$var($Iterator, i$, $nc(checkers)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PKIXCertPathChecker, checker, $cast($PKIXCertPathChecker, i$->next()));
			{
				if ($instanceOf($PKIXRevocationChecker, checker)) {
					if (revCheckerAdded) {
						$throwNew($CertPathValidatorException, "Only one PKIXRevocationChecker can be specified"_s);
					}
					revCheckerAdded = true;
					if ($instanceOf($RevocationChecker, checker)) {
						$nc(($cast($RevocationChecker, checker)))->init(anchor, params);
					}
				}
			}
		}
	}
	if (params->revocationEnabled() && !revCheckerAdded) {
		certPathCheckers->add($$new($RevocationChecker, anchor, params));
	}
	certPathCheckers->addAll(checkers);
	$var($CertPath, var$9, params->certPath());
	$PKIXMasterCertPathValidator::validate(var$9, $(params->certificates()), certPathCheckers);
	$var($X509ValidationEvent, xve, $new($X509ValidationEvent));
	bool var$10 = xve->shouldCommit();
	if (var$10 || $EventHelper::isLoggingSecurity()) {
		$var($ints, certIds, $nc($($nc($($nc($(params->certificates()))->stream()))->mapToInt(static_cast<$ToIntFunction*>($$new(PKIXCertPathValidator$$Lambda$hashCode)))))->toArray());
		int32_t anchorCertId = (anchorCert != nullptr) ? $nc(anchorCert)->hashCode() : $nc($of($(anchor->getCAPublicKey())))->hashCode();
		if (xve->shouldCommit()) {
			xve->certificateId = anchorCertId;
			int32_t certificatePos = 1;
			xve->certificatePosition = certificatePos;
			xve->validationCounter = $nc(PKIXCertPathValidator::validationCounter)->incrementAndGet();
			xve->commit();
			{
				$var($ints, arr$, certIds);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					int32_t id = arr$->get(i$);
					{
						xve->certificateId = id;
						xve->certificatePosition = ++certificatePos;
						xve->commit();
					}
				}
			}
		}
		if ($EventHelper::isLoggingSecurity()) {
			$EventHelper::logX509ValidationEvent(anchorCertId, certIds);
		}
	}
	$var($TrustAnchor, var$11, anchor);
	$var($PolicyNode, var$12, pc->getPolicyTree());
	return $new($PKIXCertPathValidatorResult, var$11, var$12, $(bc->getPublicKey()));
}

void clinit$PKIXCertPathValidator($Class* class$) {
	$assignStatic(PKIXCertPathValidator::debug, $Debug::getInstance("certpath"_s));
	$assignStatic(PKIXCertPathValidator::validationCounter, $new($AtomicLong));
}

PKIXCertPathValidator::PKIXCertPathValidator() {
}

$Class* PKIXCertPathValidator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PKIXCertPathValidator$$Lambda$hashCode::classInfo$.name)) {
			return PKIXCertPathValidator$$Lambda$hashCode::load$(name, initialize);
		}
	}
	$loadClass(PKIXCertPathValidator, name, initialize, &_PKIXCertPathValidator_ClassInfo_, clinit$PKIXCertPathValidator, allocate$PKIXCertPathValidator);
	return class$;
}

$Class* PKIXCertPathValidator::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun