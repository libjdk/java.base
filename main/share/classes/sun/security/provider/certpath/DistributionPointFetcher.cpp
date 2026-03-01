#include <sun/security/provider/certpath/DistributionPointFetcher.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/net/URI.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Principal.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertPathBuilder.h>
#include <java/security/cert/CertPathBuilderResult.h>
#include <java/security/cert/CertPathParameters.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/PKIXBuilderParameters.h>
#include <java/security/cert/PKIXCertPathBuilderResult.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/URICertStoreParameters.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509CRLSelector.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/certpath/AdaptableX509CertSelector.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/provider/certpath/PKIX$CertStoreTypeException.h>
#include <sun/security/provider/certpath/URICertStore.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/Event$ReporterCategory.h>
#include <sun/security/util/Event.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/validator/Validator.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <sun/security/x509/CRLDistributionPointsExtension.h>
#include <sun/security/x509/DistributionPoint.h>
#include <sun/security/x509/DistributionPointName.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/IssuingDistributionPointExtension.h>
#include <sun/security/x509/KeyIdentifier.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/RDN.h>
#include <sun/security/x509/ReasonFlags.h>
#include <sun/security/x509/SerialNumber.h>
#include <sun/security/x509/URIName.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CRLImpl.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef ALL_REASONS
#undef CRLCHECK
#undef FALSE
#undef INDIRECT_CRL
#undef NAME_DIRECTORY
#undef NAME_URI
#undef ONLY_ATTRIBUTE_CERTS
#undef ONLY_CA_CERTS
#undef ONLY_USER_CERTS
#undef POINT
#undef POINTS
#undef REASONS
#undef SERIAL_NUMBER
#undef TRUE
#undef VAR_PLUGIN_CODE_SIGNING

using $RDNArray = $Array<::sun::security::x509::RDN>;
using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PublicKey = ::java::security::PublicKey;
using $CRL = ::java::security::cert::CRL;
using $CRLException = ::java::security::cert::CRLException;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertPathBuilder = ::java::security::cert::CertPathBuilder;
using $CertPathParameters = ::java::security::cert::CertPathParameters;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $PKIXBuilderParameters = ::java::security::cert::PKIXBuilderParameters;
using $PKIXCertPathBuilderResult = ::java::security::cert::PKIXCertPathBuilderResult;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $URICertStoreParameters = ::java::security::cert::URICertStoreParameters;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509CRLSelector = ::java::security::cert::X509CRLSelector;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $AdaptableX509CertSelector = ::sun::security::provider::certpath::AdaptableX509CertSelector;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $PKIX$CertStoreTypeException = ::sun::security::provider::certpath::PKIX$CertStoreTypeException;
using $URICertStore = ::sun::security::provider::certpath::URICertStore;
using $Debug = ::sun::security::util::Debug;
using $Event = ::sun::security::util::Event;
using $Event$ReporterCategory = ::sun::security::util::Event$ReporterCategory;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $Validator = ::sun::security::validator::Validator;
using $AuthorityKeyIdentifierExtension = ::sun::security::x509::AuthorityKeyIdentifierExtension;
using $CRLDistributionPointsExtension = ::sun::security::x509::CRLDistributionPointsExtension;
using $DistributionPoint = ::sun::security::x509::DistributionPoint;
using $DistributionPointName = ::sun::security::x509::DistributionPointName;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $IssuingDistributionPointExtension = ::sun::security::x509::IssuingDistributionPointExtension;
using $KeyIdentifier = ::sun::security::x509::KeyIdentifier;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $RDN = ::sun::security::x509::RDN;
using $ReasonFlags = ::sun::security::x509::ReasonFlags;
using $SerialNumber = ::sun::security::x509::SerialNumber;
using $URIName = ::sun::security::x509::URIName;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CRLImpl = ::sun::security::x509::X509CRLImpl;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _DistributionPointFetcher_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DistributionPointFetcher, debug)},
	{"ALL_REASONS", "[Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DistributionPointFetcher, ALL_REASONS)},
	{}
};

$MethodInfo _DistributionPointFetcher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(DistributionPointFetcher, init$, void)},
	{"getCRL", "(Lsun/security/x509/URIName;)Ljava/security/cert/X509CRL;", nullptr, $PRIVATE | $STATIC, $staticMethod(DistributionPointFetcher, getCRL, $X509CRL*, $URIName*), "java.security.cert.CertStoreException"},
	{"getCRLs", "(Ljava/security/cert/X509CRLSelector;ZLjava/security/PublicKey;Ljava/lang/String;Ljava/util/List;[ZLjava/util/Set;Ljava/util/Date;Ljava/lang/String;)Ljava/util/Collection;", "(Ljava/security/cert/X509CRLSelector;ZLjava/security/PublicKey;Ljava/lang/String;Ljava/util/List<Ljava/security/cert/CertStore;>;[ZLjava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/Date;Ljava/lang/String;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PUBLIC | $STATIC, $staticMethod(DistributionPointFetcher, getCRLs, $Collection*, $X509CRLSelector*, bool, $PublicKey*, $String*, $List*, $booleans*, $Set*, $Date*, $String*), "java.security.cert.CertStoreException"},
	{"getCRLs", "(Ljava/security/cert/X509CRLSelector;ZLjava/security/PublicKey;Ljava/lang/String;Ljava/util/List;[ZLjava/util/Set;Ljava/util/Date;)Ljava/util/Collection;", "(Ljava/security/cert/X509CRLSelector;ZLjava/security/PublicKey;Ljava/lang/String;Ljava/util/List<Ljava/security/cert/CertStore;>;[ZLjava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/Date;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PUBLIC | $STATIC, $staticMethod(DistributionPointFetcher, getCRLs, $Collection*, $X509CRLSelector*, bool, $PublicKey*, $String*, $List*, $booleans*, $Set*, $Date*), "java.security.cert.CertStoreException"},
	{"getCRLs", "(Ljava/security/cert/X509CRLSelector;ZLjava/security/PublicKey;Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/util/List;[ZLjava/util/Set;Ljava/util/Date;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)Ljava/util/Collection;", "(Ljava/security/cert/X509CRLSelector;ZLjava/security/PublicKey;Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/util/List<Ljava/security/cert/CertStore;>;[ZLjava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/Date;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PUBLIC | $STATIC, $staticMethod(DistributionPointFetcher, getCRLs, $Collection*, $X509CRLSelector*, bool, $PublicKey*, $X509Certificate*, $String*, $List*, $booleans*, $Set*, $Date*, $String*, $TrustAnchor*), "java.security.cert.CertStoreException"},
	{"getCRLs", "(Ljava/security/cert/X509CRLSelector;Lsun/security/x509/X509CertImpl;Lsun/security/x509/DistributionPoint;[ZZLjava/security/PublicKey;Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/util/List;Ljava/util/Set;Ljava/util/Date;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)Ljava/util/Collection;", "(Ljava/security/cert/X509CRLSelector;Lsun/security/x509/X509CertImpl;Lsun/security/x509/DistributionPoint;[ZZLjava/security/PublicKey;Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/util/List<Ljava/security/cert/CertStore;>;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/Date;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PRIVATE | $STATIC, $staticMethod(DistributionPointFetcher, getCRLs, $Collection*, $X509CRLSelector*, $X509CertImpl*, $DistributionPoint*, $booleans*, bool, $PublicKey*, $X509Certificate*, $String*, $List*, $Set*, $Date*, $String*, $TrustAnchor*), "java.security.cert.CertStoreException"},
	{"getCRLs", "(Lsun/security/x509/X500Name;Ljavax/security/auth/x500/X500Principal;Ljava/util/List;)Ljava/util/Collection;", "(Lsun/security/x509/X500Name;Ljavax/security/auth/x500/X500Principal;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PRIVATE | $STATIC, $staticMethod(DistributionPointFetcher, getCRLs, $Collection*, $X500Name*, $X500Principal*, $List*), "java.security.cert.CertStoreException"},
	{"getFullNames", "(Lsun/security/x509/X500Name;Lsun/security/x509/RDN;)Lsun/security/x509/GeneralNames;", nullptr, $PRIVATE | $STATIC, $staticMethod(DistributionPointFetcher, getFullNames, $GeneralNames*, $X500Name*, $RDN*), "java.io.IOException"},
	{"issues", "(Lsun/security/x509/X509CertImpl;Lsun/security/x509/X509CRLImpl;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(DistributionPointFetcher, issues, bool, $X509CertImpl*, $X509CRLImpl*, $String*), "java.io.IOException"},
	{"verifyCRL", "(Lsun/security/x509/X509CertImpl;Lsun/security/x509/DistributionPoint;Ljava/security/cert/X509CRL;[ZZLjava/security/PublicKey;Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/util/Set;Ljava/util/List;Ljava/util/Date;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)Z", "(Lsun/security/x509/X509CertImpl;Lsun/security/x509/DistributionPoint;Ljava/security/cert/X509CRL;[ZZLjava/security/PublicKey;Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/List<Ljava/security/cert/CertStore;>;Ljava/util/Date;Ljava/lang/String;Ljava/security/cert/TrustAnchor;)Z", $STATIC, $staticMethod(DistributionPointFetcher, verifyCRL, bool, $X509CertImpl*, $DistributionPoint*, $X509CRL*, $booleans*, bool, $PublicKey*, $X509Certificate*, $String*, $Set*, $List*, $Date*, $String*, $TrustAnchor*), "java.security.cert.CRLException,java.io.IOException"},
	{}
};

$ClassInfo _DistributionPointFetcher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.certpath.DistributionPointFetcher",
	"java.lang.Object",
	nullptr,
	_DistributionPointFetcher_FieldInfo_,
	_DistributionPointFetcher_MethodInfo_
};

$Object* allocate$DistributionPointFetcher($Class* clazz) {
	return $of($alloc(DistributionPointFetcher));
}

$Debug* DistributionPointFetcher::debug = nullptr;
$booleans* DistributionPointFetcher::ALL_REASONS = nullptr;

void DistributionPointFetcher::init$() {
}

$Collection* DistributionPointFetcher::getCRLs($X509CRLSelector* selector, bool signFlag, $PublicKey* prevKey, $String* provider, $List* certStores, $booleans* reasonsMask, $Set* trustAnchors, $Date* validity, $String* variant) {
	$init(DistributionPointFetcher);
	return getCRLs(selector, signFlag, prevKey, nullptr, provider, certStores, reasonsMask, trustAnchors, validity, variant, nullptr);
}

$Collection* DistributionPointFetcher::getCRLs($X509CRLSelector* selector, bool signFlag, $PublicKey* prevKey, $String* provider, $List* certStores, $booleans* reasonsMask, $Set* trustAnchors, $Date* validity) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	if ($nc(trustAnchors)->isEmpty()) {
		$throwNew($CertStoreException, "at least one TrustAnchor must be specified"_s);
	}
	$var($TrustAnchor, anchor, $cast($TrustAnchor, $nc($($nc(trustAnchors)->iterator()))->next()));
	$init($Validator);
	return getCRLs(selector, signFlag, prevKey, nullptr, provider, certStores, reasonsMask, trustAnchors, validity, $Validator::VAR_PLUGIN_CODE_SIGNING, anchor);
}

$Collection* DistributionPointFetcher::getCRLs($X509CRLSelector* selector, bool signFlag, $PublicKey* prevKey, $X509Certificate* prevCert, $String* provider, $List* certStores, $booleans* reasonsMask, $Set* trustAnchors, $Date* validity, $String* variant, $TrustAnchor* anchor) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	$var($X509Certificate, cert, $nc(selector)->getCertificateChecking());
	if (cert == nullptr) {
		return $Collections::emptySet();
	}
	try {
		$var($X509CertImpl, certImpl, $X509CertImpl::toImpl(cert));
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println($$str({"DistributionPointFetcher.getCRLs: Checking CRLDPs for "_s, $($nc(certImpl)->getSubjectX500Principal())}));
		}
		$var($CRLDistributionPointsExtension, ext, $nc(certImpl)->getCRLDistributionPointsExtension());
		if (ext == nullptr) {
			if (DistributionPointFetcher::debug != nullptr) {
				$nc(DistributionPointFetcher::debug)->println("No CRLDP ext"_s);
			}
			return $Collections::emptySet();
		}
		$init($CRLDistributionPointsExtension);
		$var($List, points, $cast($List, $nc(ext)->get($CRLDistributionPointsExtension::POINTS)));
		$var($Set, results, $new($HashSet));
		{
			$var($Iterator, t, $nc(points)->iterator());
			for (;;) {
				bool var$0 = $nc(t)->hasNext();
				if (!(var$0 && !$Arrays::equals(reasonsMask, DistributionPointFetcher::ALL_REASONS))) {
					break;
				}
				{
					$var($DistributionPoint, point, $cast($DistributionPoint, t->next()));
					$var($Collection, crls, getCRLs(selector, certImpl, point, reasonsMask, signFlag, prevKey, prevCert, provider, certStores, trustAnchors, validity, variant, anchor));
					results->addAll(crls);
				}
			}
		}
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println($$str({"Returning "_s, $$str(results->size()), " CRLs"_s}));
		}
		return results;
	} catch ($CertificateException& e) {
		return $Collections::emptySet();
	} catch ($IOException& e) {
		return $Collections::emptySet();
	}
	$shouldNotReachHere();
}

$Collection* DistributionPointFetcher::getCRLs($X509CRLSelector* selector, $X509CertImpl* certImpl, $DistributionPoint* point, $booleans* reasonsMask, bool signFlag, $PublicKey* prevKey, $X509Certificate* prevCert, $String* provider, $List* certStores, $Set* trustAnchors, $Date* validity, $String* variant, $TrustAnchor* anchor) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	$var($GeneralNames, fullName, $nc(point)->getFullName());
	if (fullName == nullptr) {
		$var($RDN, relativeName, point->getRelativeName());
		if (relativeName == nullptr) {
			return $Collections::emptySet();
		}
		try {
			$var($GeneralNames, crlIssuers, point->getCRLIssuer());
			if (crlIssuers == nullptr) {
				$assign(fullName, getFullNames($cast($X500Name, $($nc(certImpl)->getIssuerDN())), relativeName));
			} else if ($nc(crlIssuers)->size() != 1) {
				return $Collections::emptySet();
			} else {
				$assign(fullName, getFullNames($cast($X500Name, $($nc($(crlIssuers->get(0)))->getName())), relativeName));
			}
		} catch ($IOException& ioe) {
			return $Collections::emptySet();
		}
	}
	$var($Collection, possibleCRLs, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
	$var($CertStoreException, savedCSE, nullptr);
	{
		$var($Iterator, t, $nc(fullName)->iterator());
		for (; $nc(t)->hasNext();) {
			try {
				$var($GeneralName, name, $cast($GeneralName, t->next()));
				if ($nc(name)->getType() == $GeneralNameInterface::NAME_DIRECTORY) {
					$var($X500Name, x500Name, $cast($X500Name, name->getName()));
					possibleCRLs->addAll($(getCRLs(x500Name, $($nc(certImpl)->getIssuerX500Principal()), certStores)));
				} else if (name->getType() == $GeneralNameInterface::NAME_URI) {
					$var($URIName, uriName, $cast($URIName, name->getName()));
					$var($X509CRL, crl, getCRL(uriName));
					if (crl != nullptr) {
						possibleCRLs->add(crl);
					}
				}
			} catch ($CertStoreException& cse) {
				$assign(savedCSE, cse);
			}
		}
	}
	if (possibleCRLs->isEmpty() && savedCSE != nullptr) {
		$throw(savedCSE);
	}
	$var($Collection, crls, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList, 2)))));
	{
		$var($Iterator, i$, possibleCRLs->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509CRL, crl, $cast($X509CRL, i$->next()));
			{
				try {
					$nc(selector)->setIssuerNames(nullptr);
					bool var$0 = selector->match(crl);
					if (var$0 && verifyCRL(certImpl, point, crl, reasonsMask, signFlag, prevKey, prevCert, provider, trustAnchors, certStores, validity, variant, anchor)) {
						crls->add(crl);
					}
				} catch ($IOException& e) {
					if (DistributionPointFetcher::debug != nullptr) {
						$nc(DistributionPointFetcher::debug)->println($$str({"Exception verifying CRL: "_s, $(e->getMessage())}));
						e->printStackTrace();
					}
				} catch ($CRLException& e) {
					if (DistributionPointFetcher::debug != nullptr) {
						$nc(DistributionPointFetcher::debug)->println($$str({"Exception verifying CRL: "_s, $(e->getMessage())}));
						e->printStackTrace();
					}
				}
			}
		}
	}
	return crls;
}

$X509CRL* DistributionPointFetcher::getCRL($URIName* name) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(name)->getURI());
	if (DistributionPointFetcher::debug != nullptr) {
		$nc(DistributionPointFetcher::debug)->println($$str({"Trying to fetch CRL from DP "_s, uri}));
	}
	$init($Event$ReporterCategory);
	$Event::report($Event$ReporterCategory::CRLCHECK, "event.crl.check"_s, $$new($ObjectArray, {$($of($nc(uri)->toString()))}));
	$var($CertStore, ucs, nullptr);
	try {
		$assign(ucs, $URICertStore::getInstance($$new($URICertStoreParameters, uri)));
	} catch ($InvalidAlgorithmParameterException& e) {
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println($$str({"Can\'t create URICertStore: "_s, $(e->getMessage())}));
		}
		return nullptr;
	} catch ($NoSuchAlgorithmException& e) {
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println($$str({"Can\'t create URICertStore: "_s, $(e->getMessage())}));
		}
		return nullptr;
	}
	$var($Collection, crls, $nc(ucs)->getCRLs(nullptr));
	if ($nc(crls)->isEmpty()) {
		return nullptr;
	} else {
		return $cast($X509CRL, $nc($(crls->iterator()))->next());
	}
}

$Collection* DistributionPointFetcher::getCRLs($X500Name* name, $X500Principal* certIssuer, $List* certStores) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	if (DistributionPointFetcher::debug != nullptr) {
		$nc(DistributionPointFetcher::debug)->println($$str({"Trying to fetch CRL from DP "_s, name}));
	}
	$var($X509CRLSelector, xcs, $new($X509CRLSelector));
	xcs->addIssuer($($nc(name)->asX500Principal()));
	xcs->addIssuer(certIssuer);
	$var($Collection, crls, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
	$var($CertStoreException, savedCSE, nullptr);
	{
		$var($Iterator, i$, $nc(certStores)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertStore, store, $cast($CertStore, i$->next()));
			{
				try {
					{
						$var($Iterator, i$, $nc($($nc(store)->getCRLs(xcs)))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($CRL, crl, $cast($CRL, i$->next()));
							{
								crls->add($cast($X509CRL, crl));
							}
						}
					}
				} catch ($CertStoreException& cse) {
					if (DistributionPointFetcher::debug != nullptr) {
						$nc(DistributionPointFetcher::debug)->println($$str({"Exception while retrieving CRLs: "_s, cse}));
						cse->printStackTrace();
					}
					$assign(savedCSE, $new($PKIX$CertStoreTypeException, $($nc(store)->getType()), cse));
				}
			}
		}
	}
	if (crls->isEmpty() && savedCSE != nullptr) {
		$throw(savedCSE);
	} else {
		return crls;
	}
}

bool DistributionPointFetcher::verifyCRL($X509CertImpl* certImpl, $DistributionPoint* point, $X509CRL* crl, $booleans* reasonsMask, bool signFlag, $PublicKey* prevKey$renamed, $X509Certificate* prevCert, $String* provider, $Set* trustAnchors, $List* certStores, $Date* validity, $String* variant, $TrustAnchor* anchor) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	$var($PublicKey, prevKey, prevKey$renamed);
	if (DistributionPointFetcher::debug != nullptr) {
		$var($String, var$2, $$str({"DistributionPointFetcher.verifyCRL: checking revocation status for\n  SN: "_s, $($Debug::toHexString($($nc(certImpl)->getSerialNumber()))), "\n  Subject: "_s}));
		$var($String, var$1, $$concat(var$2, $($nc(certImpl)->getSubjectX500Principal())));
		$var($String, var$0, $$concat(var$1, "\n  Issuer: "_s));
		$nc(DistributionPointFetcher::debug)->println($$concat(var$0, $(certImpl->getIssuerX500Principal())));
	}
	bool indirectCRL = false;
	$var($X509CRLImpl, crlImpl, $X509CRLImpl::toImpl(crl));
	$var($IssuingDistributionPointExtension, idpExt, $nc(crlImpl)->getIssuingDistributionPointExtension());
	$var($X500Name, certIssuer, $cast($X500Name, $nc(certImpl)->getIssuerDN()));
	$var($X500Name, crlIssuer, $cast($X500Name, crlImpl->getIssuerDN()));
	$var($GeneralNames, pointCrlIssuers, $nc(point)->getCRLIssuer());
	$var($X500Name, pointCrlIssuer, nullptr);
	if (pointCrlIssuers != nullptr) {
		$init($IssuingDistributionPointExtension);
		$init($Boolean);
		if (idpExt == nullptr || $nc(($cast($Boolean, $($nc(idpExt)->get($IssuingDistributionPointExtension::INDIRECT_CRL)))))->equals($Boolean::FALSE)) {
			return false;
		}
		bool match = false;
		{
			$var($Iterator, t, pointCrlIssuers->iterator());
			for (; !match && $nc(t)->hasNext();) {
				$var($GeneralNameInterface, name, $nc(($cast($GeneralName, $(t->next()))))->getName());
				if ($nc(crlIssuer)->equals(name) == true) {
					$assign(pointCrlIssuer, $cast($X500Name, name));
					match = true;
				}
			}
		}
		if (match == false) {
			return false;
		}
		if (issues(certImpl, crlImpl, provider)) {
			$assign(prevKey, certImpl->getPublicKey());
		} else {
			indirectCRL = true;
		}
	} else if ($nc(crlIssuer)->equals(certIssuer) == false) {
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println($$str({"crl issuer does not equal cert issuer.\ncrl issuer: "_s, crlIssuer, "\ncert issuer: "_s, certIssuer}));
		}
		return false;
	} else {
		$var($KeyIdentifier, certAKID, certImpl->getAuthKeyId());
		$var($KeyIdentifier, crlAKID, crlImpl->getAuthKeyId());
		if (certAKID == nullptr || crlAKID == nullptr) {
			if (issues(certImpl, crlImpl, provider)) {
				$assign(prevKey, certImpl->getPublicKey());
			}
		} else if (!$nc(certAKID)->equals(crlAKID)) {
			if (issues(certImpl, crlImpl, provider)) {
				$assign(prevKey, certImpl->getPublicKey());
			} else {
				indirectCRL = true;
			}
		}
	}
	if (!indirectCRL && !signFlag) {
		return false;
	}
	if (idpExt != nullptr) {
		$init($IssuingDistributionPointExtension);
		$var($DistributionPointName, idpPoint, $cast($DistributionPointName, idpExt->get($IssuingDistributionPointExtension::POINT)));
		if (idpPoint != nullptr) {
			$var($GeneralNames, idpNames, idpPoint->getFullName());
			if (idpNames == nullptr) {
				$var($RDN, relativeName, idpPoint->getRelativeName());
				if (relativeName == nullptr) {
					if (DistributionPointFetcher::debug != nullptr) {
						$nc(DistributionPointFetcher::debug)->println("IDP must be relative or full DN"_s);
					}
					return false;
				}
				if (DistributionPointFetcher::debug != nullptr) {
					$nc(DistributionPointFetcher::debug)->println($$str({"IDP relativeName:"_s, relativeName}));
				}
				$assign(idpNames, getFullNames(crlIssuer, relativeName));
			}
			bool var$3 = point->getFullName() != nullptr;
			if (var$3 || point->getRelativeName() != nullptr) {
				$var($GeneralNames, pointNames, point->getFullName());
				if (pointNames == nullptr) {
					$var($RDN, relativeName, point->getRelativeName());
					if (relativeName == nullptr) {
						if (DistributionPointFetcher::debug != nullptr) {
							$nc(DistributionPointFetcher::debug)->println("DP must be relative or full DN"_s);
						}
						return false;
					}
					if (DistributionPointFetcher::debug != nullptr) {
						$nc(DistributionPointFetcher::debug)->println($$str({"DP relativeName:"_s, relativeName}));
					}
					if (indirectCRL) {
						if ($nc(pointCrlIssuers)->size() != 1) {
							if (DistributionPointFetcher::debug != nullptr) {
								$nc(DistributionPointFetcher::debug)->println("must only be one CRL issuer when relative name present"_s);
							}
							return false;
						}
						$assign(pointNames, getFullNames(pointCrlIssuer, relativeName));
					} else {
						$assign(pointNames, getFullNames(certIssuer, relativeName));
					}
				}
				bool match = false;
				{
					$var($Iterator, i, $nc(idpNames)->iterator());
					for (; !match && $nc(i)->hasNext();) {
						$var($GeneralNameInterface, idpName, $nc(($cast($GeneralName, $(i->next()))))->getName());
						if (DistributionPointFetcher::debug != nullptr) {
							$nc(DistributionPointFetcher::debug)->println($$str({"idpName: "_s, idpName}));
						}
						{
							$var($Iterator, p, $nc(pointNames)->iterator());
							for (; !match && $nc(p)->hasNext();) {
								$var($GeneralNameInterface, pointName, $nc(($cast($GeneralName, $(p->next()))))->getName());
								if (DistributionPointFetcher::debug != nullptr) {
									$nc(DistributionPointFetcher::debug)->println($$str({"pointName: "_s, pointName}));
								}
								match = $nc($of(idpName))->equals(pointName);
							}
						}
					}
				}
				if (!match) {
					if (DistributionPointFetcher::debug != nullptr) {
						$nc(DistributionPointFetcher::debug)->println("IDP name does not match DP name"_s);
					}
					return false;
				}
			} else {
				bool match = false;
				{
					$var($Iterator, t, $nc(pointCrlIssuers)->iterator());
					for (; !match && $nc(t)->hasNext();) {
						$var($GeneralNameInterface, crlIssuerName, $nc(($cast($GeneralName, $(t->next()))))->getName());
						{
							$var($Iterator, i, $nc(idpNames)->iterator());
							for (; !match && $nc(i)->hasNext();) {
								$var($GeneralNameInterface, idpName, $nc(($cast($GeneralName, $(i->next()))))->getName());
								match = $nc($of(crlIssuerName))->equals(idpName);
							}
						}
					}
				}
				if (!match) {
					return false;
				}
			}
		}
		$var($Boolean, b, $cast($Boolean, idpExt->get($IssuingDistributionPointExtension::ONLY_USER_CERTS)));
		$init($Boolean);
		bool var$4 = $nc(b)->equals($Boolean::TRUE);
		if (var$4 && certImpl->getBasicConstraints() != -1) {
			if (DistributionPointFetcher::debug != nullptr) {
				$nc(DistributionPointFetcher::debug)->println("cert must be a EE cert"_s);
			}
			return false;
		}
		$assign(b, $cast($Boolean, idpExt->get($IssuingDistributionPointExtension::ONLY_CA_CERTS)));
		bool var$5 = $nc(b)->equals($Boolean::TRUE);
		if (var$5 && certImpl->getBasicConstraints() == -1) {
			if (DistributionPointFetcher::debug != nullptr) {
				$nc(DistributionPointFetcher::debug)->println("cert must be a CA cert"_s);
			}
			return false;
		}
		$assign(b, $cast($Boolean, idpExt->get($IssuingDistributionPointExtension::ONLY_ATTRIBUTE_CERTS)));
		if ($nc(b)->equals($Boolean::TRUE)) {
			if (DistributionPointFetcher::debug != nullptr) {
				$nc(DistributionPointFetcher::debug)->println("cert must not be an AA cert"_s);
			}
			return false;
		}
	}
	$var($booleans, interimReasonsMask, $new($booleans, 9));
	$var($ReasonFlags, reasons, nullptr);
	if (idpExt != nullptr) {
		$init($IssuingDistributionPointExtension);
		$assign(reasons, $cast($ReasonFlags, idpExt->get($IssuingDistributionPointExtension::REASONS)));
	}
	$var($booleans, pointReasonFlags, point->getReasonFlags());
	if (reasons != nullptr) {
		if (pointReasonFlags != nullptr) {
			$var($booleans, idpReasonFlags, reasons->getFlags());
			for (int32_t i = 0; i < interimReasonsMask->length; ++i) {
				interimReasonsMask->set(i, (i < $nc(idpReasonFlags)->length && idpReasonFlags->get(i)) && (i < pointReasonFlags->length && pointReasonFlags->get(i)));
			}
		} else {
			$assign(interimReasonsMask, $cast($booleans, $nc($(reasons->getFlags()))->clone()));
		}
	} else if (idpExt == nullptr || reasons == nullptr) {
		if (pointReasonFlags != nullptr) {
			$assign(interimReasonsMask, $cast($booleans, pointReasonFlags->clone()));
		} else {
			$Arrays::fill(interimReasonsMask, true);
		}
	}
	bool oneOrMore = false;
	for (int32_t i = 0; i < interimReasonsMask->length && !oneOrMore; ++i) {
		if (interimReasonsMask->get(i) && !(i < $nc(reasonsMask)->length && reasonsMask->get(i))) {
			oneOrMore = true;
		}
	}
	if (!oneOrMore) {
		return false;
	}
	if (indirectCRL) {
		$var($X509CertSelector, certSel, $new($X509CertSelector));
		certSel->setSubject($($nc(crlIssuer)->asX500Principal()));
		$var($booleans, crlSign, $new($booleans, {
			false,
			false,
			false,
			false,
			false,
			false,
			true
		}));
		certSel->setKeyUsage(crlSign);
		$var($AuthorityKeyIdentifierExtension, akidext, crlImpl->getAuthKeyIdExtension());
		if (akidext != nullptr) {
			$var($bytes, kid, akidext->getEncodedKeyIdentifier());
			if (kid != nullptr) {
				certSel->setSubjectKeyIdentifier(kid);
			}
			$var($SerialNumber, asn, $cast($SerialNumber, akidext->get($AuthorityKeyIdentifierExtension::SERIAL_NUMBER)));
			if (asn != nullptr) {
				certSel->setSerialNumber($(asn->getNumber()));
			}
		}
		$var($Set, newTrustAnchors, $new($HashSet, static_cast<$Collection*>(trustAnchors)));
		if (prevKey != nullptr) {
			$var($TrustAnchor, temporary, nullptr);
			if (prevCert != nullptr) {
				$assign(temporary, $new($TrustAnchor, prevCert, nullptr));
			} else {
				$var($X500Principal, principal, certImpl->getIssuerX500Principal());
				$assign(temporary, $new($TrustAnchor, principal, prevKey, ($bytes*)nullptr));
			}
			newTrustAnchors->add(temporary);
		}
		$var($PKIXBuilderParameters, params, nullptr);
		try {
			$assign(params, $new($PKIXBuilderParameters, newTrustAnchors, static_cast<$CertSelector*>(certSel)));
		} catch ($InvalidAlgorithmParameterException& iape) {
			$throwNew($CRLException, static_cast<$Throwable*>(iape));
		}
		$nc(params)->setCertStores(certStores);
		params->setSigProvider(provider);
		params->setDate(validity);
		try {
			$var($CertPathBuilder, builder, $CertPathBuilder::getInstance("PKIX"_s));
			$var($PKIXCertPathBuilderResult, result, $cast($PKIXCertPathBuilderResult, $nc(builder)->build(params)));
			$assign(prevKey, $nc(result)->getPublicKey());
		} catch ($GeneralSecurityException& e) {
			$throwNew($CRLException, static_cast<$Throwable*>(e));
		}
	}
	try {
		$AlgorithmChecker::check(prevKey, crl, variant, anchor);
	} catch ($CertPathValidatorException& cpve) {
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println($$str({"CRL signature algorithm check failed: "_s, cpve}));
		}
		return false;
	}
	try {
		$nc(crl)->verify(prevKey, provider);
	} catch ($GeneralSecurityException& e) {
		if (DistributionPointFetcher::debug != nullptr) {
			$nc(DistributionPointFetcher::debug)->println("CRL signature failed to verify"_s);
		}
		return false;
	}
	$var($Set, unresCritExts, $nc(crl)->getCriticalExtensionOIDs());
	if (unresCritExts != nullptr) {
		$init($PKIXExtensions);
		unresCritExts->remove($($nc($PKIXExtensions::IssuingDistributionPoint_Id)->toString()));
		if (!unresCritExts->isEmpty()) {
			if (DistributionPointFetcher::debug != nullptr) {
				$nc(DistributionPointFetcher::debug)->println($$str({"Unrecognized critical extension(s) in CRL: "_s, unresCritExts}));
				{
					$var($Iterator, i$, unresCritExts->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, ext, $cast($String, i$->next()));
						{
							$nc(DistributionPointFetcher::debug)->println(ext);
						}
					}
				}
			}
			return false;
		}
	}
	for (int32_t i = 0; i < $nc(reasonsMask)->length; ++i) {
		reasonsMask->set(i, reasonsMask->get(i) || (i < interimReasonsMask->length && interimReasonsMask->get(i)));
	}
	return true;
}

$GeneralNames* DistributionPointFetcher::getFullNames($X500Name* issuer, $RDN* rdn) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	$var($List, rdns, $new($ArrayList, $(static_cast<$Collection*>($nc(issuer)->rdns()))));
	rdns->add(rdn);
	$var($X500Name, fullName, $new($X500Name, $fcast($RDNArray, $(rdns->toArray($$new($RDNArray, 0))))));
	$var($GeneralNames, fullNames, $new($GeneralNames));
	fullNames->add($$new($GeneralName, static_cast<$GeneralNameInterface*>(fullName)));
	return fullNames;
}

bool DistributionPointFetcher::issues($X509CertImpl* cert, $X509CRLImpl* crl, $String* provider) {
	$init(DistributionPointFetcher);
	$useLocalCurrentObjectStackCache();
	bool matched = false;
	$var($AdaptableX509CertSelector, issuerSelector, $new($AdaptableX509CertSelector));
	$var($booleans, usages, $nc(cert)->getKeyUsage());
	if (usages != nullptr) {
		usages->set(6, true);
		issuerSelector->setKeyUsage(usages);
	}
	$var($X500Principal, crlIssuer, $nc(crl)->getIssuerX500Principal());
	issuerSelector->setSubject(crlIssuer);
	$var($AuthorityKeyIdentifierExtension, crlAKID, crl->getAuthKeyIdExtension());
	issuerSelector->setSkiAndSerialNumber(crlAKID);
	matched = issuerSelector->match(cert);
	if (matched && (crlAKID == nullptr || cert->getAuthorityKeyIdentifierExtension() == nullptr)) {
		try {
			crl->verify($(cert->getPublicKey()), provider);
			matched = true;
		} catch ($GeneralSecurityException& e) {
			matched = false;
		}
	}
	return matched;
}

void clinit$DistributionPointFetcher($Class* class$) {
	$assignStatic(DistributionPointFetcher::debug, $Debug::getInstance("certpath"_s));
	$assignStatic(DistributionPointFetcher::ALL_REASONS, $new($booleans, {
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true
	}));
}

DistributionPointFetcher::DistributionPointFetcher() {
}

$Class* DistributionPointFetcher::load$($String* name, bool initialize) {
	$loadClass(DistributionPointFetcher, name, initialize, &_DistributionPointFetcher_ClassInfo_, clinit$DistributionPointFetcher, allocate$DistributionPointFetcher);
	return class$;
}

$Class* DistributionPointFetcher::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun