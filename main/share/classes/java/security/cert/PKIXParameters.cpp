#include <java/security/cert/PKIXParameters.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/KeyStore.h>
#include <java/security/cert/CertPathParameters.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $KeyStore = ::java::security::KeyStore;
using $CertPathParameters = ::java::security::cert::CertPathParameters;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $Certificate = ::java::security::cert::Certificate;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _PKIXParameters_FieldInfo_[] = {
	{"unmodTrustAnchors", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;", $PRIVATE, $field(PKIXParameters, unmodTrustAnchors)},
	{"date", "Ljava/util/Date;", nullptr, $PRIVATE, $field(PKIXParameters, date)},
	{"certPathCheckers", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/PKIXCertPathChecker;>;", $PRIVATE, $field(PKIXParameters, certPathCheckers)},
	{"sigProvider", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKIXParameters, sigProvider)},
	{"revocationEnabled", "Z", nullptr, $PRIVATE, $field(PKIXParameters, revocationEnabled)},
	{"unmodInitialPolicies", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(PKIXParameters, unmodInitialPolicies)},
	{"explicitPolicyRequired", "Z", nullptr, $PRIVATE, $field(PKIXParameters, explicitPolicyRequired)},
	{"policyMappingInhibited", "Z", nullptr, $PRIVATE, $field(PKIXParameters, policyMappingInhibited)},
	{"anyPolicyInhibited", "Z", nullptr, $PRIVATE, $field(PKIXParameters, anyPolicyInhibited)},
	{"policyQualifiersRejected", "Z", nullptr, $PRIVATE, $field(PKIXParameters, policyQualifiersRejected)},
	{"certStores", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/CertStore;>;", $PRIVATE, $field(PKIXParameters, certStores)},
	{"certSelector", "Ljava/security/cert/CertSelector;", nullptr, $PRIVATE, $field(PKIXParameters, certSelector)},
	{}
};

$MethodInfo _PKIXParameters_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;)V", $PUBLIC, $method(PKIXParameters, init$, void, $Set*), "java.security.InvalidAlgorithmParameterException"},
	{"<init>", "(Ljava/security/KeyStore;)V", nullptr, $PUBLIC, $method(PKIXParameters, init$, void, $KeyStore*), "java.security.KeyStoreException,java.security.InvalidAlgorithmParameterException"},
	{"addCertPathChecker", "(Ljava/security/cert/PKIXCertPathChecker;)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, addCertPathChecker, void, $PKIXCertPathChecker*)},
	{"addCertStore", "(Ljava/security/cert/CertStore;)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, addCertStore, void, $CertStore*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, clone, $Object*)},
	{"getCertPathCheckers", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/PKIXCertPathChecker;>;", $PUBLIC, $virtualMethod(PKIXParameters, getCertPathCheckers, $List*)},
	{"getCertStores", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/CertStore;>;", $PUBLIC, $virtualMethod(PKIXParameters, getCertStores, $List*)},
	{"getDate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, getDate, $Date*)},
	{"getInitialPolicies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PKIXParameters, getInitialPolicies, $Set*)},
	{"getPolicyQualifiersRejected", "()Z", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, getPolicyQualifiersRejected, bool)},
	{"getSigProvider", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, getSigProvider, $String*)},
	{"getTargetCertConstraints", "()Ljava/security/cert/CertSelector;", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, getTargetCertConstraints, $CertSelector*)},
	{"getTrustAnchors", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;", $PUBLIC, $virtualMethod(PKIXParameters, getTrustAnchors, $Set*)},
	{"isAnyPolicyInhibited", "()Z", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, isAnyPolicyInhibited, bool)},
	{"isExplicitPolicyRequired", "()Z", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, isExplicitPolicyRequired, bool)},
	{"isPolicyMappingInhibited", "()Z", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, isPolicyMappingInhibited, bool)},
	{"isRevocationEnabled", "()Z", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, isRevocationEnabled, bool)},
	{"setAnyPolicyInhibited", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setAnyPolicyInhibited, void, bool)},
	{"setCertPathCheckers", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/security/cert/PKIXCertPathChecker;>;)V", $PUBLIC, $virtualMethod(PKIXParameters, setCertPathCheckers, void, $List*)},
	{"setCertStores", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/security/cert/CertStore;>;)V", $PUBLIC, $virtualMethod(PKIXParameters, setCertStores, void, $List*)},
	{"setDate", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setDate, void, $Date*)},
	{"setExplicitPolicyRequired", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setExplicitPolicyRequired, void, bool)},
	{"setInitialPolicies", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(PKIXParameters, setInitialPolicies, void, $Set*)},
	{"setPolicyMappingInhibited", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setPolicyMappingInhibited, void, bool)},
	{"setPolicyQualifiersRejected", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setPolicyQualifiersRejected, void, bool)},
	{"setRevocationEnabled", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setRevocationEnabled, void, bool)},
	{"setSigProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setSigProvider, void, $String*)},
	{"setTargetCertConstraints", "(Ljava/security/cert/CertSelector;)V", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, setTargetCertConstraints, void, $CertSelector*)},
	{"setTrustAnchors", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;)V", $PUBLIC, $virtualMethod(PKIXParameters, setTrustAnchors, void, $Set*), "java.security.InvalidAlgorithmParameterException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKIXParameters, toString, $String*)},
	{}
};

$ClassInfo _PKIXParameters_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.PKIXParameters",
	"java.lang.Object",
	"java.security.cert.CertPathParameters",
	_PKIXParameters_FieldInfo_,
	_PKIXParameters_MethodInfo_
};

$Object* allocate$PKIXParameters($Class* clazz) {
	return $of($alloc(PKIXParameters));
}

void PKIXParameters::init$($Set* trustAnchors) {
	this->revocationEnabled = true;
	this->explicitPolicyRequired = false;
	this->policyMappingInhibited = false;
	this->anyPolicyInhibited = false;
	this->policyQualifiersRejected = true;
	setTrustAnchors(trustAnchors);
	$set(this, unmodInitialPolicies, $Collections::emptySet());
	$set(this, certPathCheckers, $new($ArrayList));
	$set(this, certStores, $new($ArrayList));
}

void PKIXParameters::init$($KeyStore* keystore) {
	$useLocalCurrentObjectStackCache();
	this->revocationEnabled = true;
	this->explicitPolicyRequired = false;
	this->policyMappingInhibited = false;
	this->anyPolicyInhibited = false;
	this->policyQualifiersRejected = true;
	if (keystore == nullptr) {
		$throwNew($NullPointerException, "the keystore parameter must be non-null"_s);
	}
	$var($Set, hashSet, $new($HashSet));
	$var($Enumeration, aliases, $nc(keystore)->aliases());
	while ($nc(aliases)->hasMoreElements()) {
		$var($String, alias, $cast($String, aliases->nextElement()));
		if (keystore->isCertificateEntry(alias)) {
			$var($Certificate, cert, keystore->getCertificate(alias));
			if ($instanceOf($X509Certificate, cert)) {
				hashSet->add($$new($TrustAnchor, $cast($X509Certificate, cert), nullptr));
			}
		}
	}
	setTrustAnchors(hashSet);
	$set(this, unmodInitialPolicies, $Collections::emptySet());
	$set(this, certPathCheckers, $new($ArrayList));
	$set(this, certStores, $new($ArrayList));
}

$Set* PKIXParameters::getTrustAnchors() {
	return this->unmodTrustAnchors;
}

void PKIXParameters::setTrustAnchors($Set* trustAnchors) {
	$useLocalCurrentObjectStackCache();
	if (trustAnchors == nullptr) {
		$throwNew($NullPointerException, "the trustAnchors parameters must be non-null"_s);
	}
	if ($nc(trustAnchors)->isEmpty()) {
		$throwNew($InvalidAlgorithmParameterException, "the trustAnchors parameter must be non-empty"_s);
	}
	{
		$var($Iterator, i, $nc(trustAnchors)->iterator());
		for (; $nc(i)->hasNext();) {
			if (!($instanceOf($TrustAnchor, $(i->next())))) {
				$throwNew($ClassCastException, "all elements of set must be of type java.security.cert.TrustAnchor"_s);
			}
		}
	}
	$set(this, unmodTrustAnchors, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(trustAnchors))));
}

$Set* PKIXParameters::getInitialPolicies() {
	return this->unmodInitialPolicies;
}

void PKIXParameters::setInitialPolicies($Set* initialPolicies) {
	$useLocalCurrentObjectStackCache();
	if (initialPolicies != nullptr) {
		{
			$var($Iterator, i, initialPolicies->iterator());
			for (; $nc(i)->hasNext();) {
				if (!($instanceOf($String, $(i->next())))) {
					$throwNew($ClassCastException, "all elements of set must be of type java.lang.String"_s);
				}
			}
		}
		$set(this, unmodInitialPolicies, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(initialPolicies))));
	} else {
		$set(this, unmodInitialPolicies, $Collections::emptySet());
	}
}

void PKIXParameters::setCertStores($List* stores) {
	$useLocalCurrentObjectStackCache();
	if (stores == nullptr) {
		$set(this, certStores, $new($ArrayList));
	} else {
		{
			$var($Iterator, i, $nc(stores)->iterator());
			for (; $nc(i)->hasNext();) {
				if (!($instanceOf($CertStore, $(i->next())))) {
					$throwNew($ClassCastException, "all elements of list must be of type java.security.cert.CertStore"_s);
				}
			}
		}
		$set(this, certStores, $new($ArrayList, static_cast<$Collection*>(stores)));
	}
}

void PKIXParameters::addCertStore($CertStore* store) {
	if (store != nullptr) {
		$nc(this->certStores)->add(store);
	}
}

$List* PKIXParameters::getCertStores() {
	return $Collections::unmodifiableList($$new($ArrayList, static_cast<$Collection*>(this->certStores)));
}

void PKIXParameters::setRevocationEnabled(bool val) {
	this->revocationEnabled = val;
}

bool PKIXParameters::isRevocationEnabled() {
	return this->revocationEnabled;
}

void PKIXParameters::setExplicitPolicyRequired(bool val) {
	this->explicitPolicyRequired = val;
}

bool PKIXParameters::isExplicitPolicyRequired() {
	return this->explicitPolicyRequired;
}

void PKIXParameters::setPolicyMappingInhibited(bool val) {
	this->policyMappingInhibited = val;
}

bool PKIXParameters::isPolicyMappingInhibited() {
	return this->policyMappingInhibited;
}

void PKIXParameters::setAnyPolicyInhibited(bool val) {
	this->anyPolicyInhibited = val;
}

bool PKIXParameters::isAnyPolicyInhibited() {
	return this->anyPolicyInhibited;
}

void PKIXParameters::setPolicyQualifiersRejected(bool qualifiersRejected) {
	this->policyQualifiersRejected = qualifiersRejected;
}

bool PKIXParameters::getPolicyQualifiersRejected() {
	return this->policyQualifiersRejected;
}

$Date* PKIXParameters::getDate() {
	if (this->date == nullptr) {
		return nullptr;
	} else {
		return $cast($Date, $nc(this->date)->clone());
	}
}

void PKIXParameters::setDate($Date* date$renamed) {
	$var($Date, date, date$renamed);
	if (date != nullptr) {
		$set(this, date, $cast($Date, date->clone()));
	} else {
		$assign(date, nullptr);
	}
}

void PKIXParameters::setCertPathCheckers($List* checkers) {
	$useLocalCurrentObjectStackCache();
	if (checkers != nullptr) {
		$var($List, tmpList, $new($ArrayList));
		{
			$var($Iterator, i$, checkers->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PKIXCertPathChecker, checker, $cast($PKIXCertPathChecker, i$->next()));
				{
					tmpList->add($cast($PKIXCertPathChecker, $($nc(checker)->clone())));
				}
			}
		}
		$set(this, certPathCheckers, tmpList);
	} else {
		$set(this, certPathCheckers, $new($ArrayList));
	}
}

$List* PKIXParameters::getCertPathCheckers() {
	$useLocalCurrentObjectStackCache();
	$var($List, tmpList, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(this->certPathCheckers)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PKIXCertPathChecker, ck, $cast($PKIXCertPathChecker, i$->next()));
			{
				tmpList->add($cast($PKIXCertPathChecker, $($nc(ck)->clone())));
			}
		}
	}
	return $Collections::unmodifiableList(tmpList);
}

void PKIXParameters::addCertPathChecker($PKIXCertPathChecker* checker) {
	if (checker != nullptr) {
		$nc(this->certPathCheckers)->add($cast($PKIXCertPathChecker, $(checker->clone())));
	}
}

$String* PKIXParameters::getSigProvider() {
	return this->sigProvider;
}

void PKIXParameters::setSigProvider($String* sigProvider) {
	$set(this, sigProvider, sigProvider);
}

$CertSelector* PKIXParameters::getTargetCertConstraints() {
	if (this->certSelector != nullptr) {
		return $cast($CertSelector, $nc(this->certSelector)->clone());
	} else {
		return nullptr;
	}
}

void PKIXParameters::setTargetCertConstraints($CertSelector* selector) {
	if (selector != nullptr) {
		$set(this, certSelector, $cast($CertSelector, selector->clone()));
	} else {
		$set(this, certSelector, nullptr);
	}
}

$Object* PKIXParameters::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(PKIXParameters, copy, $cast(PKIXParameters, $CertPathParameters::clone()));
		if (this->certStores != nullptr) {
			$set($nc(copy), certStores, $new($ArrayList, static_cast<$Collection*>(this->certStores)));
		}
		if (this->certPathCheckers != nullptr) {
			$set($nc(copy), certPathCheckers, $new($ArrayList, $nc(this->certPathCheckers)->size()));
			{
				$var($Iterator, i$, $nc(this->certPathCheckers)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($PKIXCertPathChecker, checker, $cast($PKIXCertPathChecker, i$->next()));
					{
						$nc(copy->certPathCheckers)->add($cast($PKIXCertPathChecker, $($nc(checker)->clone())));
					}
				}
			}
		}
		return $of(copy);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

$String* PKIXParameters::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("[\n"_s);
	if (this->unmodTrustAnchors != nullptr) {
		sb->append($$str({"  Trust Anchors: "_s, $($nc($of(this->unmodTrustAnchors))->toString()), "\n"_s}));
	}
	if (this->unmodInitialPolicies != nullptr) {
		if ($nc(this->unmodInitialPolicies)->isEmpty()) {
			sb->append("  Initial Policy OIDs: any\n"_s);
		} else {
			sb->append($$str({"  Initial Policy OIDs: ["_s, $($nc($of(this->unmodInitialPolicies))->toString()), "]\n"_s}));
		}
	}
	sb->append($$str({"  Validity Date: "_s, $($String::valueOf($of(this->date))), "\n"_s}));
	sb->append($$str({"  Signature Provider: "_s, $($String::valueOf($of(this->sigProvider))), "\n"_s}));
	sb->append($$str({"  Default Revocation Enabled: "_s, $$str(this->revocationEnabled), "\n"_s}));
	sb->append($$str({"  Explicit Policy Required: "_s, $$str(this->explicitPolicyRequired), "\n"_s}));
	sb->append($$str({"  Policy Mapping Inhibited: "_s, $$str(this->policyMappingInhibited), "\n"_s}));
	sb->append($$str({"  Any Policy Inhibited: "_s, $$str(this->anyPolicyInhibited), "\n"_s}));
	sb->append($$str({"  Policy Qualifiers Rejected: "_s, $$str(this->policyQualifiersRejected), "\n"_s}));
	sb->append($$str({"  Target Cert Constraints: "_s, $($String::valueOf($of(this->certSelector))), "\n"_s}));
	if (this->certPathCheckers != nullptr) {
		sb->append($$str({"  Certification Path Checkers: ["_s, $($nc($of(this->certPathCheckers))->toString()), "]\n"_s}));
	}
	if (this->certStores != nullptr) {
		sb->append($$str({"  CertStores: ["_s, $($nc($of(this->certStores))->toString()), "]\n"_s}));
	}
	sb->append("]"_s);
	return sb->toString();
}

PKIXParameters::PKIXParameters() {
}

$Class* PKIXParameters::load$($String* name, bool initialize) {
	$loadClass(PKIXParameters, name, initialize, &_PKIXParameters_ClassInfo_, allocate$PKIXParameters);
	return class$;
}

$Class* PKIXParameters::class$ = nullptr;

		} // cert
	} // security
} // java