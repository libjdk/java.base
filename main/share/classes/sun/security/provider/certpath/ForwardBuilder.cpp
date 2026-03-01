#include <sun/security/provider/certpath/ForwardBuilder.h>

#include <java/math/BigInteger.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/PKIXReason.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/certpath/AdaptableX509CertSelector.h>
#include <sun/security/provider/certpath/Builder.h>
#include <sun/security/provider/certpath/CertPathHelper.h>
#include <sun/security/provider/certpath/ForwardBuilder$PKIXCertComparator.h>
#include <sun/security/provider/certpath/ForwardState.h>
#include <sun/security/provider/certpath/KeyChecker.h>
#include <sun/security/provider/certpath/PKIX$BuilderParams.h>
#include <sun/security/provider/certpath/PKIX.h>
#include <sun/security/provider/certpath/State.h>
#include <sun/security/provider/certpath/URICertStore.h>
#include <sun/security/provider/certpath/UntrustedChecker.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AccessDescription.h>
#include <sun/security/x509/AuthorityInfoAccessExtension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef UNRECOGNIZED_CRIT_EXT
#undef USE_AIA

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $PublicKey = ::java::security::PublicKey;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $PKIXReason = ::java::security::cert::PKIXReason;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $AdaptableX509CertSelector = ::sun::security::provider::certpath::AdaptableX509CertSelector;
using $Builder = ::sun::security::provider::certpath::Builder;
using $CertPathHelper = ::sun::security::provider::certpath::CertPathHelper;
using $ForwardBuilder$PKIXCertComparator = ::sun::security::provider::certpath::ForwardBuilder$PKIXCertComparator;
using $ForwardState = ::sun::security::provider::certpath::ForwardState;
using $KeyChecker = ::sun::security::provider::certpath::KeyChecker;
using $PKIX = ::sun::security::provider::certpath::PKIX;
using $PKIX$BuilderParams = ::sun::security::provider::certpath::PKIX$BuilderParams;
using $State = ::sun::security::provider::certpath::State;
using $URICertStore = ::sun::security::provider::certpath::URICertStore;
using $UntrustedChecker = ::sun::security::provider::certpath::UntrustedChecker;
using $Debug = ::sun::security::util::Debug;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AccessDescription = ::sun::security::x509::AccessDescription;
using $AuthorityInfoAccessExtension = ::sun::security::x509::AuthorityInfoAccessExtension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _ForwardBuilder_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForwardBuilder, debug)},
	{"trustedCerts", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $FINAL, $field(ForwardBuilder, trustedCerts)},
	{"trustedSubjectDNs", "Ljava/util/Set;", "Ljava/util/Set<Ljavax/security/auth/x500/X500Principal;>;", $PRIVATE | $FINAL, $field(ForwardBuilder, trustedSubjectDNs)},
	{"trustAnchors", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;", $PRIVATE | $FINAL, $field(ForwardBuilder, trustAnchors)},
	{"eeSelector", "Ljava/security/cert/X509CertSelector;", nullptr, $PRIVATE, $field(ForwardBuilder, eeSelector)},
	{"caSelector", "Lsun/security/provider/certpath/AdaptableX509CertSelector;", nullptr, $PRIVATE, $field(ForwardBuilder, caSelector)},
	{"caTargetSelector", "Ljava/security/cert/X509CertSelector;", nullptr, $PRIVATE, $field(ForwardBuilder, caTargetSelector)},
	{"trustAnchor", "Ljava/security/cert/TrustAnchor;", nullptr, 0, $field(ForwardBuilder, trustAnchor)},
	{"searchAllCertStores", "Z", nullptr, $PRIVATE, $field(ForwardBuilder, searchAllCertStores)},
	{}
};

$MethodInfo _ForwardBuilder_MethodInfo_[] = {
	{"<init>", "(Lsun/security/provider/certpath/PKIX$BuilderParams;Z)V", nullptr, 0, $method(ForwardBuilder, init$, void, $PKIX$BuilderParams*, bool)},
	{"addCertToPath", "(Ljava/security/cert/X509Certificate;Ljava/util/LinkedList;)V", "(Ljava/security/cert/X509Certificate;Ljava/util/LinkedList<Ljava/security/cert/X509Certificate;>;)V", 0, $virtualMethod(ForwardBuilder, addCertToPath, void, $X509Certificate*, $LinkedList*)},
	{"getCerts", "(Lsun/security/x509/AuthorityInfoAccessExtension;Ljava/util/Collection;)Z", "(Lsun/security/x509/AuthorityInfoAccessExtension;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)Z", $PRIVATE, $method(ForwardBuilder, getCerts, bool, $AuthorityInfoAccessExtension*, $Collection*)},
	{"getMatchingCACerts", "(Lsun/security/provider/certpath/ForwardState;Ljava/util/List;Ljava/util/Collection;)V", "(Lsun/security/provider/certpath/ForwardState;Ljava/util/List<Ljava/security/cert/CertStore;>;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)V", $PRIVATE, $method(ForwardBuilder, getMatchingCACerts, void, $ForwardState*, $List*, $Collection*), "java.io.IOException"},
	{"getMatchingCerts", "(Lsun/security/provider/certpath/State;Ljava/util/List;)Ljava/util/Collection;", "(Lsun/security/provider/certpath/State;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", 0, $virtualMethod(ForwardBuilder, getMatchingCerts, $Collection*, $State*, $List*), "java.security.cert.CertStoreException,java.security.cert.CertificateException,java.io.IOException"},
	{"getMatchingEECerts", "(Lsun/security/provider/certpath/ForwardState;Ljava/util/List;Ljava/util/Collection;)V", "(Lsun/security/provider/certpath/ForwardState;Ljava/util/List<Ljava/security/cert/CertStore;>;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)V", $PRIVATE, $method(ForwardBuilder, getMatchingEECerts, void, $ForwardState*, $List*, $Collection*), "java.io.IOException"},
	{"isPathCompleted", "(Ljava/security/cert/X509Certificate;)Z", nullptr, 0, $virtualMethod(ForwardBuilder, isPathCompleted, bool, $X509Certificate*)},
	{"removeFinalCertFromPath", "(Ljava/util/LinkedList;)V", "(Ljava/util/LinkedList<Ljava/security/cert/X509Certificate;>;)V", 0, $virtualMethod(ForwardBuilder, removeFinalCertFromPath, void, $LinkedList*)},
	{"verifyCert", "(Ljava/security/cert/X509Certificate;Lsun/security/provider/certpath/State;Ljava/util/List;)V", "(Ljava/security/cert/X509Certificate;Lsun/security/provider/certpath/State;Ljava/util/List<Ljava/security/cert/X509Certificate;>;)V", 0, $virtualMethod(ForwardBuilder, verifyCert, void, $X509Certificate*, $State*, $List*), "java.security.GeneralSecurityException"},
	{}
};

$InnerClassInfo _ForwardBuilder_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.ForwardBuilder$PKIXCertComparator", "sun.security.provider.certpath.ForwardBuilder", "PKIXCertComparator", $STATIC},
	{}
};

$ClassInfo _ForwardBuilder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.ForwardBuilder",
	"sun.security.provider.certpath.Builder",
	nullptr,
	_ForwardBuilder_FieldInfo_,
	_ForwardBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_ForwardBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.ForwardBuilder$PKIXCertComparator"
};

$Object* allocate$ForwardBuilder($Class* clazz) {
	return $of($alloc(ForwardBuilder));
}

$Debug* ForwardBuilder::debug = nullptr;

void ForwardBuilder::init$($PKIX$BuilderParams* buildParams, bool searchAllCertStores) {
	$useLocalCurrentObjectStackCache();
	$Builder::init$(buildParams);
	this->searchAllCertStores = true;
	$set(this, trustAnchors, $nc(buildParams)->trustAnchors());
	$set(this, trustedCerts, $new($HashSet, $nc(this->trustAnchors)->size()));
	$set(this, trustedSubjectDNs, $new($HashSet, $nc(this->trustAnchors)->size()));
	{
		$var($Iterator, i$, $nc(this->trustAnchors)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				$var($X509Certificate, trustedCert, $nc(anchor)->getTrustedCert());
				if (trustedCert != nullptr) {
					$nc(this->trustedCerts)->add(trustedCert);
					$nc(this->trustedSubjectDNs)->add($(trustedCert->getSubjectX500Principal()));
				} else {
					$nc(this->trustedSubjectDNs)->add($(anchor->getCA()));
				}
			}
		}
	}
	this->searchAllCertStores = searchAllCertStores;
}

$Collection* ForwardBuilder::getMatchingCerts($State* currentState, $List* certStores) {
	$useLocalCurrentObjectStackCache();
	if (ForwardBuilder::debug != nullptr) {
		$nc(ForwardBuilder::debug)->println("ForwardBuilder.getMatchingCerts()..."_s);
	}
	$var($ForwardState, currState, $cast($ForwardState, currentState));
	$var($Comparator, comparator, $new($ForwardBuilder$PKIXCertComparator, this->trustedSubjectDNs, $nc(currState)->cert));
	$var($Set, certs, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, comparator))));
	if ($nc(currState)->isInitial()) {
		getMatchingEECerts(currState, certStores, certs);
	}
	getMatchingCACerts(currState, certStores, certs);
	return certs;
}

void ForwardBuilder::getMatchingEECerts($ForwardState* currentState, $List* certStores, $Collection* eeCerts) {
	$useLocalCurrentObjectStackCache();
	if (ForwardBuilder::debug != nullptr) {
		$nc(ForwardBuilder::debug)->println("ForwardBuilder.getMatchingEECerts()..."_s);
	}
	if (this->eeSelector == nullptr) {
		$set(this, eeSelector, $cast($X509CertSelector, $nc(this->targetCertConstraints)->clone()));
		$nc(this->eeSelector)->setCertificateValid($($nc(this->buildParams)->date()));
		if ($nc(this->buildParams)->explicitPolicyRequired()) {
			$nc(this->eeSelector)->setPolicy($(getMatchingPolicies()));
		}
		$nc(this->eeSelector)->setBasicConstraints(-2);
	}
	addMatchingCerts(this->eeSelector, certStores, eeCerts, this->searchAllCertStores);
}

void ForwardBuilder::getMatchingCACerts($ForwardState* currentState, $List* certStores, $Collection* caCerts) {
	$useLocalCurrentObjectStackCache();
	if (ForwardBuilder::debug != nullptr) {
		$nc(ForwardBuilder::debug)->println("ForwardBuilder.getMatchingCACerts()..."_s);
	}
	int32_t initialSize = $nc(caCerts)->size();
	$var($X509CertSelector, sel, nullptr);
	if ($nc(currentState)->isInitial()) {
		if ($nc(this->targetCertConstraints)->getBasicConstraints() == -2) {
			return;
		}
		if (ForwardBuilder::debug != nullptr) {
			$nc(ForwardBuilder::debug)->println("ForwardBuilder.getMatchingCACerts(): the target is a CA"_s);
		}
		if (this->caTargetSelector == nullptr) {
			$set(this, caTargetSelector, $cast($X509CertSelector, $nc(this->targetCertConstraints)->clone()));
			if ($nc(this->buildParams)->explicitPolicyRequired()) {
				$nc(this->caTargetSelector)->setPolicy($(getMatchingPolicies()));
			}
		}
		$assign(sel, this->caTargetSelector);
	} else {
		if (this->caSelector == nullptr) {
			$set(this, caSelector, $new($AdaptableX509CertSelector));
			if ($nc(this->buildParams)->explicitPolicyRequired()) {
				$nc(this->caSelector)->setPolicy($(getMatchingPolicies()));
			}
		}
		$nc(this->caSelector)->setSubject(currentState->issuerDN);
		$CertPathHelper::setPathToNames(this->caSelector, currentState->subjectNamesTraversed);
		$var($Date, var$0, $nc(currentState->cert)->getNotBefore());
		$nc(this->caSelector)->setValidityPeriod(var$0, $($nc(currentState->cert)->getNotAfter()));
		$assign(sel, this->caSelector);
	}
	$nc(sel)->setBasicConstraints(-1);
	{
		$var($Iterator, i$, $nc(this->trustedCerts)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, trustedCert, $cast($X509Certificate, i$->next()));
			{
				if (sel->match(trustedCert)) {
					if (ForwardBuilder::debug != nullptr) {
						$var($String, var$3, $$str({"ForwardBuilder.getMatchingCACerts: found matching trust anchor.\n  SN: "_s, $($Debug::toHexString($($nc(trustedCert)->getSerialNumber()))), "\n  Subject: "_s}));
						$var($String, var$2, $$concat(var$3, $($nc(trustedCert)->getSubjectX500Principal())));
						$var($String, var$1, $$concat(var$2, "\n  Issuer: "_s));
						$nc(ForwardBuilder::debug)->println($$concat(var$1, $(trustedCert->getIssuerX500Principal())));
					}
					if (caCerts->add(trustedCert) && !this->searchAllCertStores) {
						return;
					}
				}
			}
		}
	}
	sel->setCertificateValid($($nc(this->buildParams)->date()));
	sel->setBasicConstraints($nc(currentState)->traversedCACerts);
	bool var$5 = $nc(currentState)->isInitial();
	bool var$4 = var$5 || ($nc(this->buildParams)->maxPathLength() == -1);
	if (var$4 || ($nc(this->buildParams)->maxPathLength() > $nc(currentState)->traversedCACerts)) {
		if (addMatchingCerts(sel, certStores, caCerts, this->searchAllCertStores) && !this->searchAllCertStores) {
			return;
		}
	}
	$init($Builder);
	if (!$nc(currentState)->isInitial() && $Builder::USE_AIA) {
		$var($AuthorityInfoAccessExtension, aiaExt, $nc(currentState->cert)->getAuthorityInfoAccessExtension());
		if (aiaExt != nullptr) {
			getCerts(aiaExt, caCerts);
		}
	}
	if (ForwardBuilder::debug != nullptr) {
		int32_t numCerts = caCerts->size() - initialSize;
		$nc(ForwardBuilder::debug)->println($$str({"ForwardBuilder.getMatchingCACerts: found "_s, $$str(numCerts), " CA certs"_s}));
	}
}

bool ForwardBuilder::getCerts($AuthorityInfoAccessExtension* aiaExt, $Collection* certs) {
	$useLocalCurrentObjectStackCache();
	$init($Builder);
	if ($Builder::USE_AIA == false) {
		return false;
	}
	$var($List, adList, $nc(aiaExt)->getAccessDescriptions());
	if (adList == nullptr || $nc(adList)->isEmpty()) {
		return false;
	}
	bool add = false;
	{
		$var($Iterator, i$, $nc(adList)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($AccessDescription, ad, $cast($AccessDescription, i$->next()));
			{
				$var($CertStore, cs, $URICertStore::getInstance(ad));
				if (cs != nullptr) {
					try {
						if ($nc(certs)->addAll($(cs->getCertificates(this->caSelector)))) {
							add = true;
							if (!this->searchAllCertStores) {
								return true;
							}
						}
					} catch ($CertStoreException& cse) {
						if (ForwardBuilder::debug != nullptr) {
							$nc(ForwardBuilder::debug)->println("exception getting certs from CertStore:"_s);
							cse->printStackTrace();
						}
					}
				}
			}
		}
	}
	return add;
}

void ForwardBuilder::verifyCert($X509Certificate* cert, $State* currentState, $List* certPathList) {
	$useLocalCurrentObjectStackCache();
	if (ForwardBuilder::debug != nullptr) {
		$var($String, var$3, $$str({"ForwardBuilder.verifyCert(SN: "_s, $($Debug::toHexString($($nc(cert)->getSerialNumber()))), "\n  Issuer: "_s}));
		$var($String, var$2, $$concat(var$3, $($nc(cert)->getIssuerX500Principal())));
		$var($String, var$1, $$concat(var$2, ")\n  Subject: "_s));
		$var($String, var$0, $$concat(var$1, $(cert->getSubjectX500Principal())));
		$nc(ForwardBuilder::debug)->println($$concat(var$0, ")"_s));
	}
	$var($ForwardState, currState, $cast($ForwardState, currentState));
	$nc($nc(currState)->untrustedChecker)->check(cert, $($Collections::emptySet()));
	if (certPathList != nullptr) {
		{
			$var($Iterator, i$, certPathList->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($X509Certificate, cpListCert, $cast($X509Certificate, i$->next()));
				{
					if ($nc(cert)->equals(cpListCert)) {
						if (ForwardBuilder::debug != nullptr) {
							$nc(ForwardBuilder::debug)->println("loop detected!!"_s);
						}
						$throwNew($CertPathValidatorException, "loop detected"_s);
					}
				}
			}
		}
	}
	bool isTrustedCert = $nc(this->trustedCerts)->contains(cert);
	if (!isTrustedCert) {
		$var($Set, unresCritExts, $nc(cert)->getCriticalExtensionOIDs());
		if (unresCritExts == nullptr) {
			$assign(unresCritExts, $Collections::emptySet());
		}
		{
			$var($Iterator, i$, $nc(currState->forwardCheckers)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PKIXCertPathChecker, checker, $cast($PKIXCertPathChecker, i$->next()));
				{
					$nc(checker)->check(cert, unresCritExts);
				}
			}
		}
		{
			$var($Iterator, i$, $nc($($nc(this->buildParams)->certPathCheckers()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PKIXCertPathChecker, checker, $cast($PKIXCertPathChecker, i$->next()));
				{
					if (!$nc(checker)->isForwardCheckingSupported()) {
						$var($Set, supportedExts, checker->getSupportedExtensions());
						if (supportedExts != nullptr) {
							$nc(unresCritExts)->removeAll(supportedExts);
						}
					}
				}
			}
		}
		if (!$nc(unresCritExts)->isEmpty()) {
			$init($PKIXExtensions);
			unresCritExts->remove($($nc($PKIXExtensions::BasicConstraints_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::NameConstraints_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::CertificatePolicies_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::PolicyMappings_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::PolicyConstraints_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::InhibitAnyPolicy_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::SubjectAlternativeName_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::KeyUsage_Id)->toString()));
			unresCritExts->remove($($nc($PKIXExtensions::ExtendedKeyUsage_Id)->toString()));
			if (!unresCritExts->isEmpty()) {
				$init($PKIXReason);
				$throwNew($CertPathValidatorException, "Unrecognized critical extension(s)"_s, nullptr, nullptr, -1, $PKIXReason::UNRECOGNIZED_CRIT_EXT);
			}
		}
	}
	if (currState->isInitial()) {
		return;
	}
	if (!isTrustedCert) {
		if ($nc(cert)->getBasicConstraints() == -1) {
			$throwNew($CertificateException, "cert is NOT a CA cert"_s);
		}
		$KeyChecker::verifyCAKeyUsage(cert);
	}
	if (!currState->keyParamsNeeded()) {
		$var($PublicKey, var$4, $nc(cert)->getPublicKey());
		$nc((currState->cert))->verify(var$4, $($nc(this->buildParams)->sigProvider()));
	}
}

bool ForwardBuilder::isPathCompleted($X509Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($List, otherAnchors, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(this->trustAnchors)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				if ($nc(anchor)->getTrustedCert() != nullptr) {
					if ($nc(cert)->equals($(anchor->getTrustedCert()))) {
						$set(this, trustAnchor, anchor);
						return true;
					} else {
						continue;
					}
				}
				$var($X500Principal, principal, $nc(anchor)->getCA());
				$var($PublicKey, publicKey, anchor->getCAPublicKey());
				if (principal != nullptr && publicKey != nullptr && principal->equals($($nc(cert)->getSubjectX500Principal()))) {
					if ($of(publicKey)->equals($($nc(cert)->getPublicKey()))) {
						$set(this, trustAnchor, anchor);
						return true;
					}
				}
				otherAnchors->add(anchor);
			}
		}
	}
	{
		$var($Iterator, i$, otherAnchors->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				$var($X500Principal, principal, $nc(anchor)->getCA());
				$var($PublicKey, publicKey, anchor->getCAPublicKey());
				if (principal == nullptr || !$nc(principal)->equals($($nc(cert)->getIssuerX500Principal()))) {
					continue;
				}
				if ($PKIX::isDSAPublicKeyWithoutParams(publicKey)) {
					continue;
				}
				try {
					$nc(cert)->verify(publicKey, $($nc(this->buildParams)->sigProvider()));
				} catch ($InvalidKeyException& ike) {
					if (ForwardBuilder::debug != nullptr) {
						$nc(ForwardBuilder::debug)->println("ForwardBuilder.isPathCompleted() invalid DSA key found"_s);
					}
					continue;
				} catch ($GeneralSecurityException& e) {
					if (ForwardBuilder::debug != nullptr) {
						$nc(ForwardBuilder::debug)->println("ForwardBuilder.isPathCompleted() unexpected exception"_s);
						e->printStackTrace();
					}
					continue;
				}
				$set(this, trustAnchor, anchor);
				return true;
			}
		}
	}
	return false;
}

void ForwardBuilder::addCertToPath($X509Certificate* cert, $LinkedList* certPathList) {
	$nc(certPathList)->addFirst(cert);
}

void ForwardBuilder::removeFinalCertFromPath($LinkedList* certPathList) {
	$nc(certPathList)->removeFirst();
}

void clinit$ForwardBuilder($Class* class$) {
	$assignStatic(ForwardBuilder::debug, $Debug::getInstance("certpath"_s));
}

ForwardBuilder::ForwardBuilder() {
}

$Class* ForwardBuilder::load$($String* name, bool initialize) {
	$loadClass(ForwardBuilder, name, initialize, &_ForwardBuilder_ClassInfo_, clinit$ForwardBuilder, allocate$ForwardBuilder);
	return class$;
}

$Class* ForwardBuilder::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun