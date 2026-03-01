#include <sun/security/provider/certpath/PKIX$ValidatorParams.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Timestamp.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/PKIXParameters.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <sun/security/provider/certpath/PKIX.h>
#include <sun/security/provider/certpath/PKIXExtendedParameters.h>
#include <sun/security/validator/Validator.h>
#include <jcpp.h>

#undef VAR_CODE_SIGNING
#undef VAR_GENERIC
#undef VAR_PLUGIN_CODE_SIGNING

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Timestamp = ::java::security::Timestamp;
using $CertPath = ::java::security::cert::CertPath;
using $CertSelector = ::java::security::cert::CertSelector;
using $PKIXParameters = ::java::security::cert::PKIXParameters;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $PKIXExtendedParameters = ::sun::security::provider::certpath::PKIXExtendedParameters;
using $Validator = ::sun::security::validator::Validator;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _PKIX$ValidatorParams_FieldInfo_[] = {
	{"params", "Ljava/security/cert/PKIXParameters;", nullptr, $PRIVATE | $FINAL, $field(PKIX$ValidatorParams, params)},
	{"certPath", "Ljava/security/cert/CertPath;", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, certPath$)},
	{"checkers", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/PKIXCertPathChecker;>;", $PRIVATE, $field(PKIX$ValidatorParams, checkers)},
	{"stores", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/CertStore;>;", $PRIVATE, $field(PKIX$ValidatorParams, stores)},
	{"gotDate", "Z", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, gotDate)},
	{"date", "Ljava/util/Date;", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, date$)},
	{"policies", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(PKIX$ValidatorParams, policies)},
	{"gotConstraints", "Z", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, gotConstraints)},
	{"constraints", "Ljava/security/cert/CertSelector;", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, constraints)},
	{"anchors", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;", $PRIVATE, $field(PKIX$ValidatorParams, anchors)},
	{"certs", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PRIVATE, $field(PKIX$ValidatorParams, certs)},
	{"timestamp", "Ljava/security/Timestamp;", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, timestamp)},
	{"variant", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKIX$ValidatorParams, variant$)},
	{}
};

$MethodInfo _PKIX$ValidatorParams_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/CertPath;Ljava/security/cert/PKIXParameters;)V", nullptr, 0, $method(PKIX$ValidatorParams, init$, void, $CertPath*, $PKIXParameters*), "java.security.InvalidAlgorithmParameterException"},
	{"<init>", "(Ljava/security/cert/PKIXParameters;)V", nullptr, 0, $method(PKIX$ValidatorParams, init$, void, $PKIXParameters*), "java.security.InvalidAlgorithmParameterException"},
	{"anyPolicyInhibited", "()Z", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, anyPolicyInhibited, bool)},
	{"certPath", "()Ljava/security/cert/CertPath;", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, certPath, $CertPath*)},
	{"certPathCheckers", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/PKIXCertPathChecker;>;", 0, $virtualMethod(PKIX$ValidatorParams, certPathCheckers, $List*)},
	{"certStores", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/CertStore;>;", 0, $virtualMethod(PKIX$ValidatorParams, certStores, $List*)},
	{"certificates", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/X509Certificate;>;", 0, $virtualMethod(PKIX$ValidatorParams, certificates, $List*)},
	{"date", "()Ljava/util/Date;", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, date, $Date*)},
	{"explicitPolicyRequired", "()Z", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, explicitPolicyRequired, bool)},
	{"getPKIXParameters", "()Ljava/security/cert/PKIXParameters;", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, getPKIXParameters, $PKIXParameters*)},
	{"initialPolicies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", 0, $virtualMethod(PKIX$ValidatorParams, initialPolicies, $Set*)},
	{"policyMappingInhibited", "()Z", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, policyMappingInhibited, bool)},
	{"policyQualifiersRejected", "()Z", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, policyQualifiersRejected, bool)},
	{"revocationEnabled", "()Z", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, revocationEnabled, bool)},
	{"setCertPath", "(Ljava/security/cert/CertPath;)V", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, setCertPath, void, $CertPath*)},
	{"sigProvider", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, sigProvider, $String*)},
	{"targetCertConstraints", "()Ljava/security/cert/CertSelector;", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, targetCertConstraints, $CertSelector*)},
	{"trustAnchors", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;", 0, $virtualMethod(PKIX$ValidatorParams, trustAnchors, $Set*)},
	{"variant", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(PKIX$ValidatorParams, variant, $String*)},
	{}
};

$InnerClassInfo _PKIX$ValidatorParams_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.PKIX$ValidatorParams", "sun.security.provider.certpath.PKIX", "ValidatorParams", $STATIC},
	{}
};

$ClassInfo _PKIX$ValidatorParams_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.PKIX$ValidatorParams",
	"java.lang.Object",
	nullptr,
	_PKIX$ValidatorParams_FieldInfo_,
	_PKIX$ValidatorParams_MethodInfo_,
	nullptr,
	nullptr,
	_PKIX$ValidatorParams_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.PKIX"
};

$Object* allocate$PKIX$ValidatorParams($Class* clazz) {
	return $of($alloc(PKIX$ValidatorParams));
}

void PKIX$ValidatorParams::init$($CertPath* cp, $PKIXParameters* params) {
	$useLocalCurrentObjectStackCache();
	PKIX$ValidatorParams::init$(params);
	bool var$0 = !$nc($($nc(cp)->getType()))->equals("X.509"_s);
	if (var$0 && !$nc($(cp->getType()))->equals("X509"_s)) {
		$throwNew($InvalidAlgorithmParameterException, "inappropriate CertPath type specified, must be X.509 or X509"_s);
	}
	$set(this, certPath$, cp);
}

void PKIX$ValidatorParams::init$($PKIXParameters* params) {
	$useLocalCurrentObjectStackCache();
	$init($Validator);
	$set(this, variant$, $Validator::VAR_GENERIC);
	if ($instanceOf($PKIXExtendedParameters, params)) {
		$set(this, timestamp, $nc(($cast($PKIXExtendedParameters, params)))->getTimestamp());
		$set(this, variant$, ($cast($PKIXExtendedParameters, params))->getVariant());
	}
	$set(this, anchors, $nc(params)->getTrustAnchors());
	{
		$var($Iterator, i$, $nc(this->anchors)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				if ($nc(anchor)->getNameConstraints() != nullptr) {
					$throwNew($InvalidAlgorithmParameterException, "name constraints in trust anchor not supported"_s);
				}
			}
		}
	}
	$set(this, params, params);
}

$CertPath* PKIX$ValidatorParams::certPath() {
	return this->certPath$;
}

void PKIX$ValidatorParams::setCertPath($CertPath* cp) {
	$set(this, certPath$, cp);
}

$List* PKIX$ValidatorParams::certificates() {
	$useLocalCurrentObjectStackCache();
	if (this->certs == nullptr) {
		if (this->certPath$ == nullptr) {
			$set(this, certs, $Collections::emptyList());
		} else {
			$var($List, xc, $new($ArrayList, $($nc(this->certPath$)->getCertificates())));
			$Collections::reverse(xc);
			$set(this, certs, xc);
		}
	}
	return this->certs;
}

$List* PKIX$ValidatorParams::certPathCheckers() {
	if (this->checkers == nullptr) {
		$set(this, checkers, $nc(this->params)->getCertPathCheckers());
	}
	return this->checkers;
}

$List* PKIX$ValidatorParams::certStores() {
	if (this->stores == nullptr) {
		$set(this, stores, $nc(this->params)->getCertStores());
	}
	return this->stores;
}

$Date* PKIX$ValidatorParams::date() {
	if (!this->gotDate) {
		bool var$0 = this->timestamp != nullptr;
		if (var$0) {
			$init($Validator);
			bool var$1 = $nc(this->variant$)->equals($Validator::VAR_CODE_SIGNING);
			var$0 = (var$1 || $nc(this->variant$)->equals($Validator::VAR_PLUGIN_CODE_SIGNING));
		}
		if (var$0) {
			$set(this, date$, $nc(this->timestamp)->getTimestamp());
		} else {
			$set(this, date$, $nc(this->params)->getDate());
			if (this->date$ == nullptr) {
				$set(this, date$, $new($Date));
			}
		}
		this->gotDate = true;
	}
	return this->date$;
}

$Set* PKIX$ValidatorParams::initialPolicies() {
	if (this->policies == nullptr) {
		$set(this, policies, $nc(this->params)->getInitialPolicies());
	}
	return this->policies;
}

$CertSelector* PKIX$ValidatorParams::targetCertConstraints() {
	if (!this->gotConstraints) {
		$set(this, constraints, $nc(this->params)->getTargetCertConstraints());
		this->gotConstraints = true;
	}
	return this->constraints;
}

$Set* PKIX$ValidatorParams::trustAnchors() {
	return this->anchors;
}

bool PKIX$ValidatorParams::revocationEnabled() {
	return $nc(this->params)->isRevocationEnabled();
}

bool PKIX$ValidatorParams::policyMappingInhibited() {
	return $nc(this->params)->isPolicyMappingInhibited();
}

bool PKIX$ValidatorParams::explicitPolicyRequired() {
	return $nc(this->params)->isExplicitPolicyRequired();
}

bool PKIX$ValidatorParams::policyQualifiersRejected() {
	return $nc(this->params)->getPolicyQualifiersRejected();
}

$String* PKIX$ValidatorParams::sigProvider() {
	return $nc(this->params)->getSigProvider();
}

bool PKIX$ValidatorParams::anyPolicyInhibited() {
	return $nc(this->params)->isAnyPolicyInhibited();
}

$PKIXParameters* PKIX$ValidatorParams::getPKIXParameters() {
	return this->params;
}

$String* PKIX$ValidatorParams::variant() {
	return this->variant$;
}

PKIX$ValidatorParams::PKIX$ValidatorParams() {
}

$Class* PKIX$ValidatorParams::load$($String* name, bool initialize) {
	$loadClass(PKIX$ValidatorParams, name, initialize, &_PKIX$ValidatorParams_ClassInfo_, allocate$PKIX$ValidatorParams);
	return class$;
}

$Class* PKIX$ValidatorParams::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun