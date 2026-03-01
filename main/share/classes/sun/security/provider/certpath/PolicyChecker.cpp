#include <sun/security/provider/certpath/PolicyChecker.h>

#include <java/io/IOException.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/PKIXReason.h>
#include <java/security/cert/PolicyNode.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <sun/security/provider/certpath/PolicyNodeImpl.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/CertificatePoliciesExtension.h>
#include <sun/security/x509/CertificatePolicyId.h>
#include <sun/security/x509/CertificatePolicyMap.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/InhibitAnyPolicyExtension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/PolicyConstraintsExtension.h>
#include <sun/security/x509/PolicyInformation.h>
#include <sun/security/x509/PolicyMappingsExtension.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef ANY_POLICY
#undef CE_CERT_POLICIES_ANY
#undef INHIBIT
#undef INVALID_POLICY
#undef MAP
#undef POLICIES
#undef REQUIRE
#undef SKIP_CERTS

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $PKIXReason = ::java::security::cert::PKIXReason;
using $PolicyNode = ::java::security::cert::PolicyNode;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $PolicyNodeImpl = ::sun::security::provider::certpath::PolicyNodeImpl;
using $Debug = ::sun::security::util::Debug;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $CertificatePoliciesExtension = ::sun::security::x509::CertificatePoliciesExtension;
using $CertificatePolicyId = ::sun::security::x509::CertificatePolicyId;
using $CertificatePolicyMap = ::sun::security::x509::CertificatePolicyMap;
using $InhibitAnyPolicyExtension = ::sun::security::x509::InhibitAnyPolicyExtension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $PolicyConstraintsExtension = ::sun::security::x509::PolicyConstraintsExtension;
using $PolicyInformation = ::sun::security::x509::PolicyInformation;
using $PolicyMappingsExtension = ::sun::security::x509::PolicyMappingsExtension;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _PolicyChecker_FieldInfo_[] = {
	{"initPolicies", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(PolicyChecker, initPolicies)},
	{"certPathLen", "I", nullptr, $PRIVATE | $FINAL, $field(PolicyChecker, certPathLen)},
	{"expPolicyRequired", "Z", nullptr, $PRIVATE | $FINAL, $field(PolicyChecker, expPolicyRequired)},
	{"polMappingInhibited", "Z", nullptr, $PRIVATE | $FINAL, $field(PolicyChecker, polMappingInhibited)},
	{"anyPolicyInhibited", "Z", nullptr, $PRIVATE | $FINAL, $field(PolicyChecker, anyPolicyInhibited)},
	{"rejectPolicyQualifiers", "Z", nullptr, $PRIVATE | $FINAL, $field(PolicyChecker, rejectPolicyQualifiers)},
	{"rootNode", "Lsun/security/provider/certpath/PolicyNodeImpl;", nullptr, $PRIVATE, $field(PolicyChecker, rootNode)},
	{"explicitPolicy", "I", nullptr, $PRIVATE, $field(PolicyChecker, explicitPolicy)},
	{"policyMapping", "I", nullptr, $PRIVATE, $field(PolicyChecker, policyMapping)},
	{"inhibitAnyPolicy", "I", nullptr, $PRIVATE, $field(PolicyChecker, inhibitAnyPolicy)},
	{"certIndex", "I", nullptr, $PRIVATE, $field(PolicyChecker, certIndex)},
	{"supportedExts", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(PolicyChecker, supportedExts)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyChecker, debug)},
	{"ANY_POLICY", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(PolicyChecker, ANY_POLICY)},
	{}
};

$MethodInfo _PolicyChecker_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Set;IZZZZLsun/security/provider/certpath/PolicyNodeImpl;)V", "(Ljava/util/Set<Ljava/lang/String;>;IZZZZLsun/security/provider/certpath/PolicyNodeImpl;)V", 0, $method(PolicyChecker, init$, void, $Set*, int32_t, bool, bool, bool, bool, $PolicyNodeImpl*)},
	{"check", "(Ljava/security/cert/Certificate;Ljava/util/Collection;)V", "(Ljava/security/cert/Certificate;Ljava/util/Collection<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(PolicyChecker, check, void, $Certificate*, $Collection*), "java.security.cert.CertPathValidatorException"},
	{"checkPolicy", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PRIVATE, $method(PolicyChecker, checkPolicy, void, $X509Certificate*), "java.security.cert.CertPathValidatorException"},
	{"getPolicyTree", "()Ljava/security/cert/PolicyNode;", nullptr, 0, $virtualMethod(PolicyChecker, getPolicyTree, $PolicyNode*)},
	{"getSupportedExtensions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PolicyChecker, getSupportedExtensions, $Set*)},
	{"init", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PolicyChecker, init, void, bool), "java.security.cert.CertPathValidatorException"},
	{"isForwardCheckingSupported", "()Z", nullptr, $PUBLIC, $virtualMethod(PolicyChecker, isForwardCheckingSupported, bool)},
	{"mergeExplicitPolicy", "(ILsun/security/x509/X509CertImpl;Z)I", nullptr, $STATIC, $staticMethod(PolicyChecker, mergeExplicitPolicy, int32_t, int32_t, $X509CertImpl*, bool), "java.security.cert.CertPathValidatorException"},
	{"mergeInhibitAnyPolicy", "(ILsun/security/x509/X509CertImpl;)I", nullptr, $STATIC, $staticMethod(PolicyChecker, mergeInhibitAnyPolicy, int32_t, int32_t, $X509CertImpl*), "java.security.cert.CertPathValidatorException"},
	{"mergePolicyMapping", "(ILsun/security/x509/X509CertImpl;)I", nullptr, $STATIC, $staticMethod(PolicyChecker, mergePolicyMapping, int32_t, int32_t, $X509CertImpl*), "java.security.cert.CertPathValidatorException"},
	{"processParents", "(IZZLsun/security/provider/certpath/PolicyNodeImpl;Ljava/lang/String;Ljava/util/Set;Z)Z", "(IZZLsun/security/provider/certpath/PolicyNodeImpl;Ljava/lang/String;Ljava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;Z)Z", $PRIVATE | $STATIC, $staticMethod(PolicyChecker, processParents, bool, int32_t, bool, bool, $PolicyNodeImpl*, $String*, $Set*, bool), "java.security.cert.CertPathValidatorException"},
	{"processPolicies", "(ILjava/util/Set;IIIZLsun/security/provider/certpath/PolicyNodeImpl;Lsun/security/x509/X509CertImpl;Z)Lsun/security/provider/certpath/PolicyNodeImpl;", "(ILjava/util/Set<Ljava/lang/String;>;IIIZLsun/security/provider/certpath/PolicyNodeImpl;Lsun/security/x509/X509CertImpl;Z)Lsun/security/provider/certpath/PolicyNodeImpl;", $STATIC, $staticMethod(PolicyChecker, processPolicies, $PolicyNodeImpl*, int32_t, $Set*, int32_t, int32_t, int32_t, bool, $PolicyNodeImpl*, $X509CertImpl*, bool), "java.security.cert.CertPathValidatorException"},
	{"processPolicyMappings", "(Lsun/security/x509/X509CertImpl;IILsun/security/provider/certpath/PolicyNodeImpl;ZLjava/util/Set;)Lsun/security/provider/certpath/PolicyNodeImpl;", "(Lsun/security/x509/X509CertImpl;IILsun/security/provider/certpath/PolicyNodeImpl;ZLjava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;)Lsun/security/provider/certpath/PolicyNodeImpl;", $PRIVATE | $STATIC, $staticMethod(PolicyChecker, processPolicyMappings, $PolicyNodeImpl*, $X509CertImpl*, int32_t, int32_t, $PolicyNodeImpl*, bool, $Set*), "java.security.cert.CertPathValidatorException"},
	{"removeInvalidNodes", "(Lsun/security/provider/certpath/PolicyNodeImpl;ILjava/util/Set;Lsun/security/x509/CertificatePoliciesExtension;)Lsun/security/provider/certpath/PolicyNodeImpl;", "(Lsun/security/provider/certpath/PolicyNodeImpl;ILjava/util/Set<Ljava/lang/String;>;Lsun/security/x509/CertificatePoliciesExtension;)Lsun/security/provider/certpath/PolicyNodeImpl;", $PRIVATE | $STATIC, $staticMethod(PolicyChecker, removeInvalidNodes, $PolicyNodeImpl*, $PolicyNodeImpl*, int32_t, $Set*, $CertificatePoliciesExtension*), "java.security.cert.CertPathValidatorException"},
	{"rewriteLeafNodes", "(ILjava/util/Set;Lsun/security/provider/certpath/PolicyNodeImpl;)Lsun/security/provider/certpath/PolicyNodeImpl;", "(ILjava/util/Set<Ljava/lang/String;>;Lsun/security/provider/certpath/PolicyNodeImpl;)Lsun/security/provider/certpath/PolicyNodeImpl;", $PRIVATE | $STATIC, $staticMethod(PolicyChecker, rewriteLeafNodes, $PolicyNodeImpl*, int32_t, $Set*, $PolicyNodeImpl*)},
	{}
};

$ClassInfo _PolicyChecker_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.PolicyChecker",
	"java.security.cert.PKIXCertPathChecker",
	nullptr,
	_PolicyChecker_FieldInfo_,
	_PolicyChecker_MethodInfo_
};

$Object* allocate$PolicyChecker($Class* clazz) {
	return $of($alloc(PolicyChecker));
}

$Debug* PolicyChecker::debug = nullptr;
$String* PolicyChecker::ANY_POLICY = nullptr;

void PolicyChecker::init$($Set* initialPolicies, int32_t certPathLen, bool expPolicyRequired, bool polMappingInhibited, bool anyPolicyInhibited, bool rejectPolicyQualifiers, $PolicyNodeImpl* rootNode) {
	$PKIXCertPathChecker::init$();
	if ($nc(initialPolicies)->isEmpty()) {
		$set(this, initPolicies, $new($HashSet, 1));
		$nc(this->initPolicies)->add(PolicyChecker::ANY_POLICY);
	} else {
		$set(this, initPolicies, $new($HashSet, static_cast<$Collection*>(initialPolicies)));
	}
	this->certPathLen = certPathLen;
	this->expPolicyRequired = expPolicyRequired;
	this->polMappingInhibited = polMappingInhibited;
	this->anyPolicyInhibited = anyPolicyInhibited;
	this->rejectPolicyQualifiers = rejectPolicyQualifiers;
	$set(this, rootNode, rootNode);
}

void PolicyChecker::init(bool forward) {
	if (forward) {
		$throwNew($CertPathValidatorException, "forward checking not supported"_s);
	}
	this->certIndex = 1;
	this->explicitPolicy = (this->expPolicyRequired ? 0 : this->certPathLen + 1);
	this->policyMapping = (this->polMappingInhibited ? 0 : this->certPathLen + 1);
	this->inhibitAnyPolicy = (this->anyPolicyInhibited ? 0 : this->certPathLen + 1);
}

bool PolicyChecker::isForwardCheckingSupported() {
	return false;
}

$Set* PolicyChecker::getSupportedExtensions() {
	$useLocalCurrentObjectStackCache();
	if (this->supportedExts == nullptr) {
		$set(this, supportedExts, $new($HashSet, 4));
		$init($PKIXExtensions);
		$nc(this->supportedExts)->add($($nc($PKIXExtensions::CertificatePolicies_Id)->toString()));
		$nc(this->supportedExts)->add($($nc($PKIXExtensions::PolicyMappings_Id)->toString()));
		$nc(this->supportedExts)->add($($nc($PKIXExtensions::PolicyConstraints_Id)->toString()));
		$nc(this->supportedExts)->add($($nc($PKIXExtensions::InhibitAnyPolicy_Id)->toString()));
		$set(this, supportedExts, $Collections::unmodifiableSet(this->supportedExts));
	}
	return this->supportedExts;
}

void PolicyChecker::check($Certificate* cert, $Collection* unresCritExts) {
	$useLocalCurrentObjectStackCache();
	checkPolicy($cast($X509Certificate, cert));
	if (unresCritExts != nullptr && !unresCritExts->isEmpty()) {
		$init($PKIXExtensions);
		unresCritExts->remove($($nc($PKIXExtensions::CertificatePolicies_Id)->toString()));
		unresCritExts->remove($($nc($PKIXExtensions::PolicyMappings_Id)->toString()));
		unresCritExts->remove($($nc($PKIXExtensions::PolicyConstraints_Id)->toString()));
		unresCritExts->remove($($nc($PKIXExtensions::InhibitAnyPolicy_Id)->toString()));
	}
}

void PolicyChecker::checkPolicy($X509Certificate* currCert) {
	$useLocalCurrentObjectStackCache();
	$var($String, msg, "certificate policies"_s);
	if (PolicyChecker::debug != nullptr) {
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() ---checking "_s, msg, "..."_s}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() certIndex = "_s, $$str(this->certIndex)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() BEFORE PROCESSING: explicitPolicy = "_s, $$str(this->explicitPolicy)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() BEFORE PROCESSING: policyMapping = "_s, $$str(this->policyMapping)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() BEFORE PROCESSING: inhibitAnyPolicy = "_s, $$str(this->inhibitAnyPolicy)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() BEFORE PROCESSING: policyTree = "_s, this->rootNode}));
	}
	$var($X509CertImpl, currCertImpl, nullptr);
	try {
		$assign(currCertImpl, $X509CertImpl::toImpl(currCert));
	} catch ($CertificateException& ce) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(ce));
	}
	bool finalCert = (this->certIndex == this->certPathLen);
	$set(this, rootNode, processPolicies(this->certIndex, this->initPolicies, this->explicitPolicy, this->policyMapping, this->inhibitAnyPolicy, this->rejectPolicyQualifiers, this->rootNode, currCertImpl, finalCert));
	if (!finalCert) {
		this->explicitPolicy = mergeExplicitPolicy(this->explicitPolicy, currCertImpl, finalCert);
		this->policyMapping = mergePolicyMapping(this->policyMapping, currCertImpl);
		this->inhibitAnyPolicy = mergeInhibitAnyPolicy(this->inhibitAnyPolicy, currCertImpl);
	}
	++this->certIndex;
	if (PolicyChecker::debug != nullptr) {
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() AFTER PROCESSING: explicitPolicy = "_s, $$str(this->explicitPolicy)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() AFTER PROCESSING: policyMapping = "_s, $$str(this->policyMapping)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() AFTER PROCESSING: inhibitAnyPolicy = "_s, $$str(this->inhibitAnyPolicy)}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() AFTER PROCESSING: policyTree = "_s, this->rootNode}));
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.checkPolicy() "_s, msg, " verified"_s}));
	}
}

int32_t PolicyChecker::mergeExplicitPolicy(int32_t explicitPolicy, $X509CertImpl* currCert, bool finalCert) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	if ((explicitPolicy > 0) && !$X509CertImpl::isSelfIssued(currCert)) {
		--explicitPolicy;
	}
	try {
		$var($PolicyConstraintsExtension, polConstExt, $nc(currCert)->getPolicyConstraintsExtension());
		if (polConstExt == nullptr) {
			return explicitPolicy;
		}
		$init($PolicyConstraintsExtension);
		int32_t require = $nc($($cast($Integer, $nc(polConstExt)->get($PolicyConstraintsExtension::REQUIRE))))->intValue();
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.mergeExplicitPolicy() require Index from cert = "_s, $$str(require)}));
		}
		if (!finalCert) {
			if (require != -1) {
				if ((explicitPolicy == -1) || (require < explicitPolicy)) {
					explicitPolicy = require;
				}
			}
		} else if (require == 0) {
			explicitPolicy = require;
		}
	} catch ($IOException& e) {
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println("PolicyChecker.mergeExplicitPolicy unexpected exception"_s);
			e->printStackTrace();
		}
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
	}
	return explicitPolicy;
}

int32_t PolicyChecker::mergePolicyMapping(int32_t policyMapping, $X509CertImpl* currCert) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	if ((policyMapping > 0) && !$X509CertImpl::isSelfIssued(currCert)) {
		--policyMapping;
	}
	try {
		$var($PolicyConstraintsExtension, polConstExt, $nc(currCert)->getPolicyConstraintsExtension());
		if (polConstExt == nullptr) {
			return policyMapping;
		}
		$init($PolicyConstraintsExtension);
		int32_t inhibit = $nc($($cast($Integer, $nc(polConstExt)->get($PolicyConstraintsExtension::INHIBIT))))->intValue();
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.mergePolicyMapping() inhibit Index from cert = "_s, $$str(inhibit)}));
		}
		if (inhibit != -1) {
			if ((policyMapping == -1) || (inhibit < policyMapping)) {
				policyMapping = inhibit;
			}
		}
	} catch ($IOException& e) {
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println("PolicyChecker.mergePolicyMapping unexpected exception"_s);
			e->printStackTrace();
		}
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
	}
	return policyMapping;
}

int32_t PolicyChecker::mergeInhibitAnyPolicy(int32_t inhibitAnyPolicy, $X509CertImpl* currCert) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	if ((inhibitAnyPolicy > 0) && !$X509CertImpl::isSelfIssued(currCert)) {
		--inhibitAnyPolicy;
	}
	try {
		$init($PKIXExtensions);
		$var($InhibitAnyPolicyExtension, inhAnyPolExt, $cast($InhibitAnyPolicyExtension, $nc(currCert)->getExtension($PKIXExtensions::InhibitAnyPolicy_Id)));
		if (inhAnyPolExt == nullptr) {
			return inhibitAnyPolicy;
		}
		$init($InhibitAnyPolicyExtension);
		int32_t skipCerts = $nc($($cast($Integer, $nc(inhAnyPolExt)->get($InhibitAnyPolicyExtension::SKIP_CERTS))))->intValue();
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.mergeInhibitAnyPolicy() skipCerts Index from cert = "_s, $$str(skipCerts)}));
		}
		if (skipCerts != -1) {
			if (skipCerts < inhibitAnyPolicy) {
				inhibitAnyPolicy = skipCerts;
			}
		}
	} catch ($IOException& e) {
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println("PolicyChecker.mergeInhibitAnyPolicy unexpected exception"_s);
			e->printStackTrace();
		}
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
	}
	return inhibitAnyPolicy;
}

$PolicyNodeImpl* PolicyChecker::processPolicies(int32_t certIndex, $Set* initPolicies, int32_t explicitPolicy, int32_t policyMapping, int32_t inhibitAnyPolicy, bool rejectPolicyQualifiers, $PolicyNodeImpl* origRootNode, $X509CertImpl* currCert, bool finalCert) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	bool policiesCritical = false;
	$var($List, policyInfo, nullptr);
	$var($PolicyNodeImpl, rootNode, nullptr);
	$var($Set, anyQuals, $new($HashSet));
	if (origRootNode == nullptr) {
		$assign(rootNode, nullptr);
	} else {
		$assign(rootNode, $nc(origRootNode)->copyTree());
	}
	$var($CertificatePoliciesExtension, currCertPolicies, $nc(currCert)->getCertificatePoliciesExtension());
	if ((currCertPolicies != nullptr) && (rootNode != nullptr)) {
		policiesCritical = currCertPolicies->isCritical();
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() policiesCritical = "_s, $$str(policiesCritical)}));
		}
		try {
			$assign(policyInfo, $cast($List, currCertPolicies->get($CertificatePoliciesExtension::POLICIES)));
		} catch ($IOException& ioe) {
			$throwNew($CertPathValidatorException, "Exception while retrieving policyOIDs"_s, ioe);
		}
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() rejectPolicyQualifiers = "_s, $$str(rejectPolicyQualifiers)}));
		}
		bool foundAnyPolicy = false;
		{
			$var($Iterator, i$, $nc(policyInfo)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PolicyInformation, curPolInfo, $cast($PolicyInformation, i$->next()));
				{
					$var($String, curPolicy, $nc($($nc($($nc(curPolInfo)->getPolicyIdentifier()))->getIdentifier()))->toString());
					if ($nc(curPolicy)->equals(PolicyChecker::ANY_POLICY)) {
						foundAnyPolicy = true;
						$assign(anyQuals, curPolInfo->getPolicyQualifiers());
					} else {
						if (PolicyChecker::debug != nullptr) {
							$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() processing policy: "_s, curPolicy}));
						}
						$var($Set, pQuals, curPolInfo->getPolicyQualifiers());
						if (!$nc(pQuals)->isEmpty() && rejectPolicyQualifiers && policiesCritical) {
							$init($PKIXReason);
							$throwNew($CertPathValidatorException, "critical policy qualifiers present in certificate"_s, nullptr, nullptr, -1, $PKIXReason::INVALID_POLICY);
						}
						bool foundMatch = processParents(certIndex, policiesCritical, rejectPolicyQualifiers, rootNode, curPolicy, pQuals, false);
						if (!foundMatch) {
							processParents(certIndex, policiesCritical, rejectPolicyQualifiers, rootNode, curPolicy, pQuals, true);
						}
					}
				}
			}
		}
		if (foundAnyPolicy) {
			if ((inhibitAnyPolicy > 0) || (!finalCert && $X509CertImpl::isSelfIssued(currCert))) {
				if (PolicyChecker::debug != nullptr) {
					$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() processing policy: "_s, PolicyChecker::ANY_POLICY}));
				}
				processParents(certIndex, policiesCritical, rejectPolicyQualifiers, rootNode, PolicyChecker::ANY_POLICY, anyQuals, true);
			}
		}
		rootNode->prune(certIndex);
		if (!$nc($(rootNode->getChildren()))->hasNext()) {
			$assign(rootNode, nullptr);
		}
	} else if (currCertPolicies == nullptr) {
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println("PolicyChecker.processPolicies() no policies present in cert"_s);
		}
		$assign(rootNode, nullptr);
	}
	if (rootNode != nullptr) {
		if (!finalCert) {
			$assign(rootNode, processPolicyMappings(currCert, certIndex, policyMapping, rootNode, policiesCritical, anyQuals));
		}
	}
	if ((rootNode != nullptr) && (!$nc(initPolicies)->contains(PolicyChecker::ANY_POLICY)) && (currCertPolicies != nullptr)) {
		$assign(rootNode, removeInvalidNodes(rootNode, certIndex, initPolicies, currCertPolicies));
		if ((rootNode != nullptr) && finalCert) {
			$assign(rootNode, rewriteLeafNodes(certIndex, initPolicies, rootNode));
		}
	}
	if (finalCert) {
		explicitPolicy = mergeExplicitPolicy(explicitPolicy, currCert, finalCert);
	}
	if ((explicitPolicy == 0) && (rootNode == nullptr)) {
		$init($PKIXReason);
		$throwNew($CertPathValidatorException, "non-null policy tree required and policy tree is null"_s, nullptr, nullptr, -1, $PKIXReason::INVALID_POLICY);
	}
	return rootNode;
}

$PolicyNodeImpl* PolicyChecker::rewriteLeafNodes(int32_t certIndex, $Set* initPolicies, $PolicyNodeImpl* rootNode$renamed) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	$var($PolicyNodeImpl, rootNode, rootNode$renamed);
	$var($Set, anyNodes, $nc(rootNode)->getPolicyNodesValid(certIndex, PolicyChecker::ANY_POLICY));
	if ($nc(anyNodes)->isEmpty()) {
		return rootNode;
	}
	$var($PolicyNodeImpl, anyNode, $cast($PolicyNodeImpl, $nc($($nc(anyNodes)->iterator()))->next()));
	$var($PolicyNodeImpl, parentNode, $cast($PolicyNodeImpl, $nc(anyNode)->getParent()));
	$nc(parentNode)->deleteChild(anyNode);
	$var($Set, initial, $new($HashSet, static_cast<$Collection*>(initPolicies)));
	{
		$var($Iterator, i$, $nc($(rootNode->getPolicyNodes(certIndex)))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyNodeImpl, node, $cast($PolicyNodeImpl, i$->next()));
			{
				initial->remove($($nc(node)->getValidPolicy()));
			}
		}
	}
	if (initial->isEmpty()) {
		rootNode->prune(certIndex);
		if ($nc($(rootNode->getChildren()))->hasNext() == false) {
			$assign(rootNode, nullptr);
		}
	} else {
		bool anyCritical = anyNode->isCritical();
		$var($Set, anyQualifiers, anyNode->getPolicyQualifiers());
		{
			$var($Iterator, i$, initial->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, policy, $cast($String, i$->next()));
				{
					$var($Set, expectedPolicies, $Collections::singleton(policy));
					$var($PolicyNodeImpl, node, $new($PolicyNodeImpl, parentNode, policy, anyQualifiers, anyCritical, expectedPolicies, false));
				}
			}
		}
	}
	return rootNode;
}

bool PolicyChecker::processParents(int32_t certIndex, bool policiesCritical, bool rejectPolicyQualifiers, $PolicyNodeImpl* rootNode, $String* curPolicy, $Set* pQuals, bool matchAny) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	bool foundMatch = false;
	if (PolicyChecker::debug != nullptr) {
		$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processParents(): matchAny = "_s, $$str(matchAny)}));
	}
	$var($Set, parentNodes, $nc(rootNode)->getPolicyNodesExpected(certIndex - 1, curPolicy, matchAny));
	{
		$var($Iterator, i$, $nc(parentNodes)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyNodeImpl, curParent, $cast($PolicyNodeImpl, i$->next()));
			{
				if (PolicyChecker::debug != nullptr) {
					$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processParents() found parent:\n"_s, $($nc(curParent)->asString())}));
				}
				foundMatch = true;
				$var($String, curParPolicy, $nc(curParent)->getValidPolicy());
				$var($PolicyNodeImpl, curNode, nullptr);
				$var($Set, curExpPols, nullptr);
				if ($nc(curPolicy)->equals(PolicyChecker::ANY_POLICY)) {
					$var($Set, parExpPols, curParent->getExpectedPolicies());
					bool parentExplicitPolicies$continue = false;
					{
						$var($Iterator, i$, $nc(parExpPols)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, curParExpPol, $cast($String, i$->next()));
							{
								$var($Iterator, childIter, curParent->getChildren());
								while ($nc(childIter)->hasNext()) {
									$var($PolicyNodeImpl, childNode, $cast($PolicyNodeImpl, childIter->next()));
									$var($String, childPolicy, $nc(childNode)->getValidPolicy());
									if ($nc(curParExpPol)->equals(childPolicy)) {
										if (PolicyChecker::debug != nullptr) {
											$nc(PolicyChecker::debug)->println($$str({childPolicy, " in parent\'s expected policy set already appears in child node"_s}));
										}
										parentExplicitPolicies$continue = true;
										break;
									}
								}
								if (parentExplicitPolicies$continue) {
									parentExplicitPolicies$continue = false;
									continue;
								}
								$var($Set, expPols, $new($HashSet));
								expPols->add(curParExpPol);
								$assign(curNode, $new($PolicyNodeImpl, curParent, curParExpPol, pQuals, policiesCritical, expPols, false));
							}
						}
					}
				} else {
					$assign(curExpPols, $new($HashSet));
					curExpPols->add(curPolicy);
					$assign(curNode, $new($PolicyNodeImpl, curParent, curPolicy, pQuals, policiesCritical, curExpPols, false));
				}
			}
		}
	}
	return foundMatch;
}

$PolicyNodeImpl* PolicyChecker::processPolicyMappings($X509CertImpl* currCert, int32_t certIndex, int32_t policyMapping, $PolicyNodeImpl* rootNode$renamed, bool policiesCritical, $Set* anyQuals) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	$var($PolicyNodeImpl, rootNode, rootNode$renamed);
	$var($PolicyMappingsExtension, polMappingsExt, $nc(currCert)->getPolicyMappingsExtension());
	if (polMappingsExt == nullptr) {
		return rootNode;
	}
	if (PolicyChecker::debug != nullptr) {
		$nc(PolicyChecker::debug)->println("PolicyChecker.processPolicyMappings() inside policyMapping check"_s);
	}
	$var($List, maps, nullptr);
	try {
		$init($PolicyMappingsExtension);
		$assign(maps, $cast($List, $nc(polMappingsExt)->get($PolicyMappingsExtension::MAP)));
	} catch ($IOException& e) {
		if (PolicyChecker::debug != nullptr) {
			$nc(PolicyChecker::debug)->println("PolicyChecker.processPolicyMappings() mapping exception"_s);
			e->printStackTrace();
		}
		$throwNew($CertPathValidatorException, "Exception while checking mapping"_s, e);
	}
	bool childDeleted = false;
	{
		$var($Iterator, i$, $nc(maps)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificatePolicyMap, polMap, $cast($CertificatePolicyMap, i$->next()));
			{
				$var($String, issuerDomain, $nc($($nc($($nc(polMap)->getIssuerIdentifier()))->getIdentifier()))->toString());
				$var($String, subjectDomain, $nc($($nc($(polMap->getSubjectIdentifier()))->getIdentifier()))->toString());
				if (PolicyChecker::debug != nullptr) {
					$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicyMappings() issuerDomain = "_s, issuerDomain}));
					$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicyMappings() subjectDomain = "_s, subjectDomain}));
				}
				if ($nc(issuerDomain)->equals(PolicyChecker::ANY_POLICY)) {
					$init($PKIXReason);
					$throwNew($CertPathValidatorException, "encountered an issuerDomainPolicy of ANY_POLICY"_s, nullptr, nullptr, -1, $PKIXReason::INVALID_POLICY);
				}
				if ($nc(subjectDomain)->equals(PolicyChecker::ANY_POLICY)) {
					$init($PKIXReason);
					$throwNew($CertPathValidatorException, "encountered a subjectDomainPolicy of ANY_POLICY"_s, nullptr, nullptr, -1, $PKIXReason::INVALID_POLICY);
				}
				$var($Set, validNodes, $nc(rootNode)->getPolicyNodesValid(certIndex, issuerDomain));
				if (!$nc(validNodes)->isEmpty()) {
					{
						$var($Iterator, i$, validNodes->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($PolicyNodeImpl, curNode, $cast($PolicyNodeImpl, i$->next()));
							{
								if ((policyMapping > 0) || (policyMapping == -1)) {
									$nc(curNode)->addExpectedPolicy(subjectDomain);
								} else if (policyMapping == 0) {
									$var($PolicyNodeImpl, parentNode, $cast($PolicyNodeImpl, $nc(curNode)->getParent()));
									if (PolicyChecker::debug != nullptr) {
										$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicyMappings() before deleting: policy tree = "_s, rootNode}));
									}
									$nc(parentNode)->deleteChild(curNode);
									childDeleted = true;
									if (PolicyChecker::debug != nullptr) {
										$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicyMappings() after deleting: policy tree = "_s, rootNode}));
									}
								}
							}
						}
					}
				} else if ((policyMapping > 0) || (policyMapping == -1)) {
					$var($Set, validAnyNodes, rootNode->getPolicyNodesValid(certIndex, PolicyChecker::ANY_POLICY));
					{
						$var($Iterator, i$, $nc(validAnyNodes)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($PolicyNodeImpl, curAnyNode, $cast($PolicyNodeImpl, i$->next()));
							{
								$var($PolicyNodeImpl, curAnyNodeParent, $cast($PolicyNodeImpl, $nc(curAnyNode)->getParent()));
								$var($Set, expPols, $new($HashSet));
								expPols->add(subjectDomain);
								$var($PolicyNodeImpl, curNode, $new($PolicyNodeImpl, curAnyNodeParent, issuerDomain, anyQuals, policiesCritical, expPols, true));
							}
						}
					}
				}
			}
		}
	}
	if (childDeleted) {
		$nc(rootNode)->prune(certIndex);
		if (!$nc($(rootNode->getChildren()))->hasNext()) {
			if (PolicyChecker::debug != nullptr) {
				$nc(PolicyChecker::debug)->println("setting rootNode to null"_s);
			}
			$assign(rootNode, nullptr);
		}
	}
	return rootNode;
}

$PolicyNodeImpl* PolicyChecker::removeInvalidNodes($PolicyNodeImpl* rootNode$renamed, int32_t certIndex, $Set* initPolicies, $CertificatePoliciesExtension* currCertPolicies) {
	$init(PolicyChecker);
	$useLocalCurrentObjectStackCache();
	$var($PolicyNodeImpl, rootNode, rootNode$renamed);
	$var($List, policyInfo, nullptr);
	try {
		$init($CertificatePoliciesExtension);
		$assign(policyInfo, $cast($List, $nc(currCertPolicies)->get($CertificatePoliciesExtension::POLICIES)));
	} catch ($IOException& ioe) {
		$throwNew($CertPathValidatorException, "Exception while retrieving policyOIDs"_s, ioe);
	}
	bool childDeleted = false;
	{
		$var($Iterator, i$, $nc(policyInfo)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyInformation, curPolInfo, $cast($PolicyInformation, i$->next()));
			{
				$var($String, curPolicy, $nc($($nc($($nc(curPolInfo)->getPolicyIdentifier()))->getIdentifier()))->toString());
				if (PolicyChecker::debug != nullptr) {
					$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() processing policy second time: "_s, curPolicy}));
				}
				$var($Set, validNodes, $nc(rootNode)->getPolicyNodesValid(certIndex, curPolicy));
				{
					$var($Iterator, i$, $nc(validNodes)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($PolicyNodeImpl, curNode, $cast($PolicyNodeImpl, i$->next()));
						{
							$var($PolicyNodeImpl, parentNode, $cast($PolicyNodeImpl, $nc(curNode)->getParent()));
							if ($nc($($nc(parentNode)->getValidPolicy()))->equals(PolicyChecker::ANY_POLICY)) {
								bool var$0 = (!$nc(initPolicies)->contains(curPolicy));
								if (var$0 && (!$nc(curPolicy)->equals(PolicyChecker::ANY_POLICY))) {
									if (PolicyChecker::debug != nullptr) {
										$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() before deleting: policy tree = "_s, rootNode}));
									}
									parentNode->deleteChild(curNode);
									childDeleted = true;
									if (PolicyChecker::debug != nullptr) {
										$nc(PolicyChecker::debug)->println($$str({"PolicyChecker.processPolicies() after deleting: policy tree = "_s, rootNode}));
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (childDeleted) {
		$nc(rootNode)->prune(certIndex);
		if (!$nc($(rootNode->getChildren()))->hasNext()) {
			$assign(rootNode, nullptr);
		}
	}
	return rootNode;
}

$PolicyNode* PolicyChecker::getPolicyTree() {
	if (this->rootNode == nullptr) {
		return nullptr;
	} else {
		$var($PolicyNodeImpl, policyTree, $nc(this->rootNode)->copyTree());
		$nc(policyTree)->setImmutable();
		return policyTree;
	}
}

void clinit$PolicyChecker($Class* class$) {
	$assignStatic(PolicyChecker::debug, $Debug::getInstance("certpath"_s));
	$init($KnownOIDs);
	$assignStatic(PolicyChecker::ANY_POLICY, $KnownOIDs::CE_CERT_POLICIES_ANY->value());
}

PolicyChecker::PolicyChecker() {
}

$Class* PolicyChecker::load$($String* name, bool initialize) {
	$loadClass(PolicyChecker, name, initialize, &_PolicyChecker_ClassInfo_, clinit$PolicyChecker, allocate$PolicyChecker);
	return class$;
}

$Class* PolicyChecker::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun