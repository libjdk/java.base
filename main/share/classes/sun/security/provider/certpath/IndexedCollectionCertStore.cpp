#include <sun/security/provider/certpath/IndexedCollectionCertStore.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/security/cert/CertStoreSpi.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CollectionCertStoreParameters.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509CRLSelector.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $CRL = ::java::security::cert::CRL;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $CertStoreSpi = ::java::security::cert::CertStoreSpi;
using $Certificate = ::java::security::cert::Certificate;
using $CollectionCertStoreParameters = ::java::security::cert::CollectionCertStoreParameters;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509CRLSelector = ::java::security::cert::X509CRLSelector;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _IndexedCollectionCertStore_FieldInfo_[] = {
	{"certSubjects", "Ljava/util/Map;", "Ljava/util/Map<Ljavax/security/auth/x500/X500Principal;Ljava/lang/Object;>;", $PRIVATE, $field(IndexedCollectionCertStore, certSubjects)},
	{"crlIssuers", "Ljava/util/Map;", "Ljava/util/Map<Ljavax/security/auth/x500/X500Principal;Ljava/lang/Object;>;", $PRIVATE, $field(IndexedCollectionCertStore, crlIssuers)},
	{"otherCertificates", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/Certificate;>;", $PRIVATE, $field(IndexedCollectionCertStore, otherCertificates)},
	{"otherCRLs", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/CRL;>;", $PRIVATE, $field(IndexedCollectionCertStore, otherCRLs)},
	{}
};

$MethodInfo _IndexedCollectionCertStore_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/CertStoreParameters;)V", nullptr, $PUBLIC, $method(IndexedCollectionCertStore, init$, void, $CertStoreParameters*), "java.security.InvalidAlgorithmParameterException"},
	{"buildIndex", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<*>;)V", $PRIVATE, $method(IndexedCollectionCertStore, buildIndex, void, $Collection*)},
	{"engineGetCRLs", "(Ljava/security/cert/CRLSelector;)Ljava/util/Collection;", "(Ljava/security/cert/CRLSelector;)Ljava/util/Collection<Ljava/security/cert/CRL;>;", $PUBLIC, $virtualMethod(IndexedCollectionCertStore, engineGetCRLs, $Collection*, $CRLSelector*), "java.security.cert.CertStoreException"},
	{"engineGetCertificates", "(Ljava/security/cert/CertSelector;)Ljava/util/Collection;", "(Ljava/security/cert/CertSelector;)Ljava/util/Collection<+Ljava/security/cert/Certificate;>;", $PUBLIC, $virtualMethod(IndexedCollectionCertStore, engineGetCertificates, $Collection*, $CertSelector*), "java.security.cert.CertStoreException"},
	{"indexCRL", "(Ljava/security/cert/X509CRL;)V", nullptr, $PRIVATE, $method(IndexedCollectionCertStore, indexCRL, void, $X509CRL*)},
	{"indexCertificate", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PRIVATE, $method(IndexedCollectionCertStore, indexCertificate, void, $X509Certificate*)},
	{"matchX509CRLs", "(Ljava/security/cert/CRLSelector;Ljava/util/Collection;)V", "(Ljava/security/cert/CRLSelector;Ljava/util/Collection<Ljava/security/cert/CRL;>;)V", $PRIVATE, $method(IndexedCollectionCertStore, matchX509CRLs, void, $CRLSelector*, $Collection*)},
	{"matchX509Certs", "(Ljava/security/cert/CertSelector;Ljava/util/Collection;)V", "(Ljava/security/cert/CertSelector;Ljava/util/Collection<Ljava/security/cert/Certificate;>;)V", $PRIVATE, $method(IndexedCollectionCertStore, matchX509Certs, void, $CertSelector*, $Collection*)},
	{}
};

$ClassInfo _IndexedCollectionCertStore_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.certpath.IndexedCollectionCertStore",
	"java.security.cert.CertStoreSpi",
	nullptr,
	_IndexedCollectionCertStore_FieldInfo_,
	_IndexedCollectionCertStore_MethodInfo_
};

$Object* allocate$IndexedCollectionCertStore($Class* clazz) {
	return $of($alloc(IndexedCollectionCertStore));
}

void IndexedCollectionCertStore::init$($CertStoreParameters* params) {
	$CertStoreSpi::init$(params);
	if (!($instanceOf($CollectionCertStoreParameters, params))) {
		$throwNew($InvalidAlgorithmParameterException, "parameters must be CollectionCertStoreParameters"_s);
	}
	$var($Collection, coll, $nc(($cast($CollectionCertStoreParameters, params)))->getCollection());
	if (coll == nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "Collection must not be null"_s);
	}
	buildIndex(coll);
}

void IndexedCollectionCertStore::buildIndex($Collection* coll) {
	$useLocalCurrentObjectStackCache();
	$set(this, certSubjects, $new($HashMap));
	$set(this, crlIssuers, $new($HashMap));
	$set(this, otherCertificates, nullptr);
	$set(this, otherCRLs, nullptr);
	{
		$var($Iterator, i$, $nc(coll)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, obj, i$->next());
			{
				if ($instanceOf($X509Certificate, obj)) {
					indexCertificate($cast($X509Certificate, obj));
				} else if ($instanceOf($X509CRL, obj)) {
					indexCRL($cast($X509CRL, obj));
				} else if ($instanceOf($Certificate, obj)) {
					if (this->otherCertificates == nullptr) {
						$set(this, otherCertificates, $new($HashSet));
					}
					$nc(this->otherCertificates)->add($cast($Certificate, obj));
				} else if ($instanceOf($CRL, obj)) {
					if (this->otherCRLs == nullptr) {
						$set(this, otherCRLs, $new($HashSet));
					}
					$nc(this->otherCRLs)->add($cast($CRL, obj));
				} else {
				}
			}
		}
	}
	if (this->otherCertificates == nullptr) {
		$set(this, otherCertificates, $Collections::emptySet());
	}
	if (this->otherCRLs == nullptr) {
		$set(this, otherCRLs, $Collections::emptySet());
	}
}

void IndexedCollectionCertStore::indexCertificate($X509Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($X500Principal, subject, $nc(cert)->getSubjectX500Principal());
	$var($Object, oldEntry, $nc(this->certSubjects)->put(subject, cert));
	if (oldEntry != nullptr) {
		if ($instanceOf($X509Certificate, oldEntry)) {
			if (cert->equals(oldEntry)) {
				return;
			}
			$var($List, list, $new($ArrayList, 2));
			list->add(cert);
			list->add($cast($X509Certificate, oldEntry));
			$nc(this->certSubjects)->put(subject, list);
		} else {
			$var($List, list, $cast($List, oldEntry));
			if (list->contains(cert) == false) {
				list->add(cert);
			}
			$nc(this->certSubjects)->put(subject, list);
		}
	}
}

void IndexedCollectionCertStore::indexCRL($X509CRL* crl) {
	$useLocalCurrentObjectStackCache();
	$var($X500Principal, issuer, $nc(crl)->getIssuerX500Principal());
	$var($Object, oldEntry, $nc(this->crlIssuers)->put(issuer, crl));
	if (oldEntry != nullptr) {
		if ($instanceOf($X509CRL, oldEntry)) {
			if (crl->equals(oldEntry)) {
				return;
			}
			$var($List, list, $new($ArrayList, 2));
			list->add(crl);
			list->add($cast($X509CRL, oldEntry));
			$nc(this->crlIssuers)->put(issuer, list);
		} else {
			$var($List, list, $cast($List, oldEntry));
			if (list->contains(crl) == false) {
				list->add(crl);
			}
			$nc(this->crlIssuers)->put(issuer, list);
		}
	}
}

$Collection* IndexedCollectionCertStore::engineGetCertificates($CertSelector* selector) {
	$useLocalCurrentObjectStackCache();
	if (selector == nullptr) {
		$var($Set, matches, $new($HashSet));
		matchX509Certs($$new($X509CertSelector), matches);
		matches->addAll(this->otherCertificates);
		return matches;
	}
	if ($instanceOf($X509CertSelector, selector) == false) {
		$var($Set, matches, $new($HashSet));
		matchX509Certs(selector, matches);
		{
			$var($Iterator, i$, $nc(this->otherCertificates)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Certificate, cert, $cast($Certificate, i$->next()));
				{
					if ($nc(selector)->match(cert)) {
						matches->add(cert);
					}
				}
			}
		}
		return matches;
	}
	if ($nc(this->certSubjects)->isEmpty()) {
		return $Collections::emptySet();
	}
	$var($X509CertSelector, x509Selector, $cast($X509CertSelector, selector));
	$var($X500Principal, subject, nullptr);
	$var($X509Certificate, matchCert, $nc(x509Selector)->getCertificate());
	if (matchCert != nullptr) {
		$assign(subject, matchCert->getSubjectX500Principal());
	} else {
		$assign(subject, x509Selector->getSubject());
	}
	if (subject != nullptr) {
		$var($Object, entry, $nc(this->certSubjects)->get(subject));
		if (entry == nullptr) {
			return $Collections::emptySet();
		}
		if ($instanceOf($X509Certificate, entry)) {
			$var($X509Certificate, x509Entry, $cast($X509Certificate, entry));
			if (x509Selector->match(x509Entry)) {
				return $Collections::singleton(x509Entry);
			} else {
				return $Collections::emptySet();
			}
		} else {
			$var($List, list, $cast($List, entry));
			$var($Set, matches, $new($HashSet, 16));
			{
				$var($Iterator, i$, $nc(list)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
					{
						if (x509Selector->match(cert)) {
							matches->add(cert);
						}
					}
				}
			}
			return matches;
		}
	}
	$var($Set, matches, $new($HashSet, 16));
	matchX509Certs(x509Selector, matches);
	return matches;
}

void IndexedCollectionCertStore::matchX509Certs($CertSelector* selector, $Collection* matches) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(this->certSubjects)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, obj, i$->next());
			{
				if ($instanceOf($X509Certificate, obj)) {
					$var($X509Certificate, cert, $cast($X509Certificate, obj));
					if ($nc(selector)->match(cert)) {
						$nc(matches)->add(cert);
					}
				} else {
					$var($List, list, $cast($List, obj));
					{
						$var($Iterator, i$, $nc(list)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
							{
								if ($nc(selector)->match(cert)) {
									$nc(matches)->add(cert);
								}
							}
						}
					}
				}
			}
		}
	}
}

$Collection* IndexedCollectionCertStore::engineGetCRLs($CRLSelector* selector) {
	$useLocalCurrentObjectStackCache();
	if (selector == nullptr) {
		$var($Set, matches, $new($HashSet));
		matchX509CRLs($$new($X509CRLSelector), matches);
		matches->addAll(this->otherCRLs);
		return matches;
	}
	if ($instanceOf($X509CRLSelector, selector) == false) {
		$var($Set, matches, $new($HashSet));
		matchX509CRLs(selector, matches);
		{
			$var($Iterator, i$, $nc(this->otherCRLs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($CRL, crl, $cast($CRL, i$->next()));
				{
					if ($nc(selector)->match(crl)) {
						matches->add(crl);
					}
				}
			}
		}
		return matches;
	}
	if ($nc(this->crlIssuers)->isEmpty()) {
		return $Collections::emptySet();
	}
	$var($X509CRLSelector, x509Selector, $cast($X509CRLSelector, selector));
	$var($Collection, issuers, $nc(x509Selector)->getIssuers());
	if (issuers != nullptr) {
		$var($HashSet, matches, $new($HashSet, 16));
		{
			$var($Iterator, i$, issuers->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($X500Principal, issuer, $cast($X500Principal, i$->next()));
				{
					$var($Object, entry, $nc(this->crlIssuers)->get(issuer));
					if (entry == nullptr) {
					} else if ($instanceOf($X509CRL, entry)) {
						$var($X509CRL, crl, $cast($X509CRL, entry));
						if (x509Selector->match(crl)) {
							matches->add(crl);
						}
					} else {
						$var($List, list, $cast($List, entry));
						{
							$var($Iterator, i$, $nc(list)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($X509CRL, crl, $cast($X509CRL, i$->next()));
								{
									if (x509Selector->match(crl)) {
										matches->add(crl);
									}
								}
							}
						}
					}
				}
			}
		}
		return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(matches)));
	}
	$var($Set, matches, $new($HashSet, 16));
	matchX509CRLs(x509Selector, matches);
	return matches;
}

void IndexedCollectionCertStore::matchX509CRLs($CRLSelector* selector, $Collection* matches) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(this->crlIssuers)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, obj, i$->next());
			{
				if ($instanceOf($X509CRL, obj)) {
					$var($X509CRL, crl, $cast($X509CRL, obj));
					if ($nc(selector)->match(crl)) {
						$nc(matches)->add(crl);
					}
				} else {
					$var($List, list, $cast($List, obj));
					{
						$var($Iterator, i$, $nc(list)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($X509CRL, crl, $cast($X509CRL, i$->next()));
							{
								if ($nc(selector)->match(crl)) {
									$nc(matches)->add(crl);
								}
							}
						}
					}
				}
			}
		}
	}
}

IndexedCollectionCertStore::IndexedCollectionCertStore() {
}

$Class* IndexedCollectionCertStore::load$($String* name, bool initialize) {
	$loadClass(IndexedCollectionCertStore, name, initialize, &_IndexedCollectionCertStore_ClassInfo_, allocate$IndexedCollectionCertStore);
	return class$;
}

$Class* IndexedCollectionCertStore::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun