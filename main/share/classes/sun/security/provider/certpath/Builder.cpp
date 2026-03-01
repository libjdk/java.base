#include <sun/security/provider/certpath/Builder.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/provider/certpath/PKIX$BuilderParams.h>
#include <sun/security/provider/certpath/PolicyChecker.h>
#include <sun/security/provider/certpath/State.h>
#include <sun/security/util/Debug.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/GeneralSubtree.h>
#include <sun/security/x509/GeneralSubtrees.h>
#include <sun/security/x509/NameConstraintsExtension.h>
#include <sun/security/x509/SubjectAlternativeNameExtension.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef ANY_POLICY
#undef EXCLUDED_SUBTREES
#undef NAME_DIFF_TYPE
#undef NAME_DIRECTORY
#undef NAME_MATCH
#undef NAME_NARROWS
#undef NAME_SAME_TYPE
#undef NAME_WIDENS
#undef PERMITTED_SUBTREES
#undef SUBJECT_NAME
#undef USE_AIA

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $PKIX$BuilderParams = ::sun::security::provider::certpath::PKIX$BuilderParams;
using $PolicyChecker = ::sun::security::provider::certpath::PolicyChecker;
using $State = ::sun::security::provider::certpath::State;
using $Debug = ::sun::security::util::Debug;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $GeneralSubtree = ::sun::security::x509::GeneralSubtree;
using $GeneralSubtrees = ::sun::security::x509::GeneralSubtrees;
using $NameConstraintsExtension = ::sun::security::x509::NameConstraintsExtension;
using $SubjectAlternativeNameExtension = ::sun::security::x509::SubjectAlternativeNameExtension;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _Builder_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Builder, debug)},
	{"matchingPolicies", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(Builder, matchingPolicies)},
	{"buildParams", "Lsun/security/provider/certpath/PKIX$BuilderParams;", nullptr, $FINAL, $field(Builder, buildParams)},
	{"targetCertConstraints", "Ljava/security/cert/X509CertSelector;", nullptr, $FINAL, $field(Builder, targetCertConstraints)},
	{"USE_AIA", "Z", nullptr, $STATIC | $FINAL, $staticField(Builder, USE_AIA)},
	{}
};

$MethodInfo _Builder_MethodInfo_[] = {
	{"<init>", "(Lsun/security/provider/certpath/PKIX$BuilderParams;)V", nullptr, 0, $method(Builder, init$, void, $PKIX$BuilderParams*)},
	{"addCertToPath", "(Ljava/security/cert/X509Certificate;Ljava/util/LinkedList;)V", "(Ljava/security/cert/X509Certificate;Ljava/util/LinkedList<Ljava/security/cert/X509Certificate;>;)V", $ABSTRACT, $virtualMethod(Builder, addCertToPath, void, $X509Certificate*, $LinkedList*)},
	{"addMatchingCerts", "(Ljava/security/cert/X509CertSelector;Ljava/util/Collection;Ljava/util/Collection;Z)Z", "(Ljava/security/cert/X509CertSelector;Ljava/util/Collection<Ljava/security/cert/CertStore;>;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;Z)Z", 0, $virtualMethod(Builder, addMatchingCerts, bool, $X509CertSelector*, $Collection*, $Collection*, bool)},
	{"distance", "(Lsun/security/x509/GeneralNameInterface;Lsun/security/x509/GeneralNameInterface;I)I", nullptr, $STATIC, $staticMethod(Builder, distance, int32_t, $GeneralNameInterface*, $GeneralNameInterface*, int32_t)},
	{"getMatchingCerts", "(Lsun/security/provider/certpath/State;Ljava/util/List;)Ljava/util/Collection;", "(Lsun/security/provider/certpath/State;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $ABSTRACT, $virtualMethod(Builder, getMatchingCerts, $Collection*, $State*, $List*), "java.security.cert.CertStoreException,java.security.cert.CertificateException,java.io.IOException"},
	{"getMatchingPolicies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", 0, $virtualMethod(Builder, getMatchingPolicies, $Set*)},
	{"hops", "(Lsun/security/x509/GeneralNameInterface;Lsun/security/x509/GeneralNameInterface;I)I", nullptr, $STATIC, $staticMethod(Builder, hops, int32_t, $GeneralNameInterface*, $GeneralNameInterface*, int32_t)},
	{"isPathCompleted", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $ABSTRACT, $virtualMethod(Builder, isPathCompleted, bool, $X509Certificate*)},
	{"removeFinalCertFromPath", "(Ljava/util/LinkedList;)V", "(Ljava/util/LinkedList<Ljava/security/cert/X509Certificate;>;)V", $ABSTRACT, $virtualMethod(Builder, removeFinalCertFromPath, void, $LinkedList*)},
	{"targetDistance", "(Lsun/security/x509/NameConstraintsExtension;Ljava/security/cert/X509Certificate;Lsun/security/x509/GeneralNameInterface;)I", nullptr, $STATIC, $staticMethod(Builder, targetDistance, int32_t, $NameConstraintsExtension*, $X509Certificate*, $GeneralNameInterface*), "java.io.IOException"},
	{"verifyCert", "(Ljava/security/cert/X509Certificate;Lsun/security/provider/certpath/State;Ljava/util/List;)V", "(Ljava/security/cert/X509Certificate;Lsun/security/provider/certpath/State;Ljava/util/List<Ljava/security/cert/X509Certificate;>;)V", $ABSTRACT, $virtualMethod(Builder, verifyCert, void, $X509Certificate*, $State*, $List*), "java.security.GeneralSecurityException"},
	{}
};

$ClassInfo _Builder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.provider.certpath.Builder",
	"java.lang.Object",
	nullptr,
	_Builder_FieldInfo_,
	_Builder_MethodInfo_
};

$Object* allocate$Builder($Class* clazz) {
	return $of($alloc(Builder));
}

$Debug* Builder::debug = nullptr;
bool Builder::USE_AIA = false;

void Builder::init$($PKIX$BuilderParams* buildParams) {
	$set(this, buildParams, buildParams);
	$set(this, targetCertConstraints, $cast($X509CertSelector, $nc(buildParams)->targetCertConstraints()));
}

int32_t Builder::distance($GeneralNameInterface* base, $GeneralNameInterface* test, int32_t incomparable) {
	$init(Builder);
	switch ($nc(base)->constrains(test)) {
	case $GeneralNameInterface::NAME_DIFF_TYPE:
		{
			if (Builder::debug != nullptr) {
				$nc(Builder::debug)->println("Builder.distance(): Names are different types"_s);
			}
			return incomparable;
		}
	case $GeneralNameInterface::NAME_SAME_TYPE:
		{
			if (Builder::debug != nullptr) {
				$nc(Builder::debug)->println("Builder.distance(): Names are same type but in different subtrees"_s);
			}
			return incomparable;
		}
	case $GeneralNameInterface::NAME_MATCH:
		{
			return 0;
		}
	case $GeneralNameInterface::NAME_WIDENS:
		{
			break;
		}
	case $GeneralNameInterface::NAME_NARROWS:
		{
			break;
		}
	default:
		{
			return incomparable;
		}
	}
	int32_t var$0 = $nc(test)->subtreeDepth();
	return var$0 - base->subtreeDepth();
}

int32_t Builder::hops($GeneralNameInterface* base, $GeneralNameInterface* test, int32_t incomparable) {
	$init(Builder);
	$useLocalCurrentObjectStackCache();
	int32_t baseRtest = $nc(base)->constrains(test);
	switch (baseRtest) {
	case $GeneralNameInterface::NAME_DIFF_TYPE:
		{
			if (Builder::debug != nullptr) {
				$nc(Builder::debug)->println("Builder.hops(): Names are different types"_s);
			}
			return incomparable;
		}
	case $GeneralNameInterface::NAME_SAME_TYPE:
		{
			break;
		}
	case $GeneralNameInterface::NAME_MATCH:
		{
			return 0;
		}
	case $GeneralNameInterface::NAME_WIDENS:
		{
			int32_t var$0 = $nc(test)->subtreeDepth();
			return (var$0 - base->subtreeDepth());
		}
	case $GeneralNameInterface::NAME_NARROWS:
		{
			int32_t var$1 = $nc(test)->subtreeDepth();
			return (var$1 - base->subtreeDepth());
		}
	default:
		{
			return incomparable;
		}
	}
	if (base->getType() != $GeneralNameInterface::NAME_DIRECTORY) {
		if (Builder::debug != nullptr) {
			$nc(Builder::debug)->println("Builder.hops(): hopDistance not implemented for this name type"_s);
		}
		return incomparable;
	}
	$var($X500Name, baseName, $cast($X500Name, base));
	$var($X500Name, testName, $cast($X500Name, test));
	$var($X500Name, commonName, baseName->commonAncestor(testName));
	if (commonName == nullptr) {
		if (Builder::debug != nullptr) {
			$nc(Builder::debug)->println("Builder.hops(): Names are in different namespaces"_s);
		}
		return incomparable;
	} else {
		int32_t commonDistance = $nc(commonName)->subtreeDepth();
		int32_t baseDistance = baseName->subtreeDepth();
		int32_t testDistance = $nc(testName)->subtreeDepth();
		return (baseDistance + testDistance - (2 * commonDistance));
	}
}

int32_t Builder::targetDistance($NameConstraintsExtension* constraints$renamed, $X509Certificate* cert, $GeneralNameInterface* target) {
	$init(Builder);
	$useLocalCurrentObjectStackCache();
	$var($NameConstraintsExtension, constraints, constraints$renamed);
	if (constraints != nullptr && !constraints->verify(cert)) {
		$throwNew($IOException, "certificate does not satisfy existing name constraints"_s);
	}
	$var($X509CertImpl, certImpl, nullptr);
	try {
		$assign(certImpl, $X509CertImpl::toImpl(cert));
	} catch ($CertificateException& e) {
		$throwNew($IOException, "Invalid certificate"_s, e);
	}
	$var($X500Name, subject, $X500Name::asX500Name($($nc(certImpl)->getSubjectX500Principal())));
	if ($nc(subject)->equals(target)) {
		return 0;
	}
	$var($SubjectAlternativeNameExtension, altNameExt, $nc(certImpl)->getSubjectAlternativeNameExtension());
	if (altNameExt != nullptr) {
		$init($SubjectAlternativeNameExtension);
		$var($GeneralNames, altNames, $cast($GeneralNames, altNameExt->get($SubjectAlternativeNameExtension::SUBJECT_NAME)));
		if (altNames != nullptr) {
			{
				int32_t j = 0;
				int32_t n = altNames->size();
				for (; j < n; ++j) {
					$var($GeneralNameInterface, altName, $nc($(altNames->get(j)))->getName());
					if ($nc($of(altName))->equals(target)) {
						return 0;
					}
				}
			}
		}
	}
	$var($NameConstraintsExtension, ncExt, certImpl->getNameConstraintsExtension());
	if (ncExt == nullptr) {
		return -1;
	}
	if (constraints != nullptr) {
		constraints->merge(ncExt);
	} else {
		$assign(constraints, $cast($NameConstraintsExtension, $nc(ncExt)->clone()));
	}
	if (Builder::debug != nullptr) {
		$nc(Builder::debug)->println($$str({"Builder.targetDistance() merged constraints: "_s, $($String::valueOf($of(constraints)))}));
	}
	$var($GeneralSubtrees, permitted, $cast($GeneralSubtrees, $nc(constraints)->get($NameConstraintsExtension::PERMITTED_SUBTREES)));
	$var($GeneralSubtrees, excluded, $cast($GeneralSubtrees, constraints->get($NameConstraintsExtension::EXCLUDED_SUBTREES)));
	if (permitted != nullptr) {
		permitted->reduce(excluded);
	}
	if (Builder::debug != nullptr) {
		$nc(Builder::debug)->println($$str({"Builder.targetDistance() reduced constraints: "_s, permitted}));
	}
	if (!constraints->verify(target)) {
		$throwNew($IOException, "New certificate not allowed to sign certificate for target"_s);
	}
	if (permitted == nullptr) {
		return -1;
	}
	{
		int32_t i = 0;
		int32_t n = $nc(permitted)->size();
		for (; i < n; ++i) {
			$var($GeneralNameInterface, perName, $nc($($nc($(permitted->get(i)))->getName()))->getName());
			int32_t distance = Builder::distance(perName, target, -1);
			if (distance >= 0) {
				return (distance + 1);
			}
		}
	}
	return -1;
}

$Set* Builder::getMatchingPolicies() {
	if (this->matchingPolicies != nullptr) {
		$var($Set, initialPolicies, $nc(this->buildParams)->initialPolicies());
		bool var$1 = (!$nc(initialPolicies)->isEmpty());
		$init($PolicyChecker);
		bool var$0 = var$1 && (!initialPolicies->contains($PolicyChecker::ANY_POLICY));
		if (var$0 && ($nc(this->buildParams)->policyMappingInhibited())) {
			$set(this, matchingPolicies, $new($HashSet, static_cast<$Collection*>(initialPolicies)));
			$nc(this->matchingPolicies)->add($PolicyChecker::ANY_POLICY);
		} else {
			$set(this, matchingPolicies, $Collections::emptySet());
		}
	}
	return this->matchingPolicies;
}

bool Builder::addMatchingCerts($X509CertSelector* selector, $Collection* certStores, $Collection* resultCerts, bool checkAll) {
	$useLocalCurrentObjectStackCache();
	$var($X509Certificate, targetCert, $nc(selector)->getCertificate());
	if (targetCert != nullptr) {
		bool var$0 = selector->match(targetCert);
		if (var$0 && !$X509CertImpl::isSelfSigned(targetCert, $($nc(this->buildParams)->sigProvider()))) {
			if (Builder::debug != nullptr) {
				$var($String, var$3, $$str({"Builder.addMatchingCerts: adding target cert\n  SN: "_s, $($Debug::toHexString($(targetCert->getSerialNumber()))), "\n  Subject: "_s}));
				$var($String, var$2, $$concat(var$3, $(targetCert->getSubjectX500Principal())));
				$var($String, var$1, $$concat(var$2, "\n  Issuer: "_s));
				$nc(Builder::debug)->println($$concat(var$1, $(targetCert->getIssuerX500Principal())));
			}
			return $nc(resultCerts)->add(targetCert);
		}
		return false;
	}
	bool add = false;
	{
		$var($Iterator, i$, $nc(certStores)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertStore, store, $cast($CertStore, i$->next()));
			{
				try {
					$var($Collection, certs, $nc(store)->getCertificates(selector));
					{
						$var($Iterator, i$, $nc(certs)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Certificate, cert, $cast($Certificate, i$->next()));
							{
								if (!$X509CertImpl::isSelfSigned($cast($X509Certificate, cert), $($nc(this->buildParams)->sigProvider()))) {
									if ($nc(resultCerts)->add($cast($X509Certificate, cert))) {
										add = true;
									}
								}
							}
						}
					}
					if (!checkAll && add) {
						return true;
					}
				} catch ($CertStoreException& cse) {
					if (Builder::debug != nullptr) {
						$nc(Builder::debug)->println($$str({"Builder.addMatchingCerts, non-fatal exception retrieving certs: "_s, cse}));
						cse->printStackTrace();
					}
				}
			}
		}
	}
	return add;
}

void clinit$Builder($Class* class$) {
	$assignStatic(Builder::debug, $Debug::getInstance("certpath"_s));
	Builder::USE_AIA = $GetBooleanAction::privilegedGetProperty("com.sun.security.enableAIAcaIssuers"_s);
}

Builder::Builder() {
}

$Class* Builder::load$($String* name, bool initialize) {
	$loadClass(Builder, name, initialize, &_Builder_ClassInfo_, clinit$Builder, allocate$Builder);
	return class$;
}

$Class* Builder::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun