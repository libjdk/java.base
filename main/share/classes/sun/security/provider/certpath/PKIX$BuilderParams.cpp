#include <sun/security/provider/certpath/PKIX$BuilderParams.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/PKIXBuilderParameters.h>
#include <java/security/cert/PKIXParameters.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/certpath/PKIX$CertStoreComparator.h>
#include <sun/security/provider/certpath/PKIX$ValidatorParams.h>
#include <sun/security/provider/certpath/PKIX.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $PKIXBuilderParameters = ::java::security::cert::PKIXBuilderParameters;
using $PKIXParameters = ::java::security::cert::PKIXParameters;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $PKIX = ::sun::security::provider::certpath::PKIX;
using $PKIX$CertStoreComparator = ::sun::security::provider::certpath::PKIX$CertStoreComparator;
using $PKIX$ValidatorParams = ::sun::security::provider::certpath::PKIX$ValidatorParams;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _PKIX$BuilderParams_FieldInfo_[] = {
	{"params", "Ljava/security/cert/PKIXBuilderParameters;", nullptr, $PRIVATE, $field(PKIX$BuilderParams, params$)},
	{"stores", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/CertStore;>;", $PRIVATE, $field(PKIX$BuilderParams, stores)},
	{"targetSubject", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $field(PKIX$BuilderParams, targetSubject$)},
	{}
};

$MethodInfo _PKIX$BuilderParams_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/PKIXBuilderParameters;)V", nullptr, 0, $method(PKIX$BuilderParams, init$, void, $PKIXBuilderParameters*), "java.security.InvalidAlgorithmParameterException"},
	{"certStores", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/CertStore;>;", 0, $virtualMethod(PKIX$BuilderParams, certStores, $List*)},
	{"checkParams", "(Ljava/security/cert/PKIXBuilderParameters;)V", nullptr, $PRIVATE, $method(PKIX$BuilderParams, checkParams, void, $PKIXBuilderParameters*), "java.security.InvalidAlgorithmParameterException"},
	{"getTargetSubject", "(Ljava/util/List;Ljava/security/cert/X509CertSelector;)Ljavax/security/auth/x500/X500Principal;", "(Ljava/util/List<Ljava/security/cert/CertStore;>;Ljava/security/cert/X509CertSelector;)Ljavax/security/auth/x500/X500Principal;", $PRIVATE | $STATIC, $staticMethod(PKIX$BuilderParams, getTargetSubject, $X500Principal*, $List*, $X509CertSelector*), "java.security.InvalidAlgorithmParameterException"},
	{"maxPathLength", "()I", nullptr, 0, $virtualMethod(PKIX$BuilderParams, maxPathLength, int32_t)},
	{"params", "()Ljava/security/cert/PKIXBuilderParameters;", nullptr, 0, $virtualMethod(PKIX$BuilderParams, params, $PKIXBuilderParameters*)},
	{"targetSubject", "()Ljavax/security/auth/x500/X500Principal;", nullptr, 0, $virtualMethod(PKIX$BuilderParams, targetSubject, $X500Principal*)},
	{}
};

$InnerClassInfo _PKIX$BuilderParams_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.PKIX$BuilderParams", "sun.security.provider.certpath.PKIX", "BuilderParams", $STATIC},
	{"sun.security.provider.certpath.PKIX$ValidatorParams", "sun.security.provider.certpath.PKIX", "ValidatorParams", $STATIC},
	{}
};

$ClassInfo _PKIX$BuilderParams_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.PKIX$BuilderParams",
	"sun.security.provider.certpath.PKIX$ValidatorParams",
	nullptr,
	_PKIX$BuilderParams_FieldInfo_,
	_PKIX$BuilderParams_MethodInfo_,
	nullptr,
	nullptr,
	_PKIX$BuilderParams_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.PKIX"
};

$Object* allocate$PKIX$BuilderParams($Class* clazz) {
	return $of($alloc(PKIX$BuilderParams));
}

void PKIX$BuilderParams::init$($PKIXBuilderParameters* params) {
	$PKIX$ValidatorParams::init$(params);
	checkParams(params);
}

void PKIX$BuilderParams::checkParams($PKIXBuilderParameters* params) {
	$useLocalCurrentObjectStackCache();
	$var($CertSelector, sel, targetCertConstraints());
	if (!($instanceOf($X509CertSelector, sel))) {
		$throwNew($InvalidAlgorithmParameterException, "the targetCertConstraints parameter must be an X509CertSelector"_s);
	}
	$set(this, params$, params);
	$var($List, var$0, certStores());
	$set(this, targetSubject$, getTargetSubject(var$0, $cast($X509CertSelector, $(targetCertConstraints()))));
}

$List* PKIX$BuilderParams::certStores() {
	$useLocalCurrentObjectStackCache();
	if (this->stores == nullptr) {
		$set(this, stores, $new($ArrayList, $(static_cast<$Collection*>($nc(this->params$)->getCertStores()))));
		$Collections::sort(this->stores, $$new($PKIX$CertStoreComparator));
	}
	return this->stores;
}

int32_t PKIX$BuilderParams::maxPathLength() {
	return $nc(this->params$)->getMaxPathLength();
}

$PKIXBuilderParameters* PKIX$BuilderParams::params() {
	return this->params$;
}

$X500Principal* PKIX$BuilderParams::targetSubject() {
	return this->targetSubject$;
}

$X500Principal* PKIX$BuilderParams::getTargetSubject($List* stores, $X509CertSelector* sel) {
	$init(PKIX$BuilderParams);
	$useLocalCurrentObjectStackCache();
	$var($X500Principal, subject, $nc(sel)->getSubject());
	if (subject != nullptr) {
		return subject;
	}
	$var($X509Certificate, cert, sel->getCertificate());
	if (cert != nullptr) {
		$assign(subject, cert->getSubjectX500Principal());
	}
	if (subject != nullptr) {
		return subject;
	}
	{
		$var($Iterator, i$, $nc(stores)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertStore, store, $cast($CertStore, i$->next()));
			{
				try {
					$var($Collection, certs, $nc(store)->getCertificates(sel));
					if (!$nc(certs)->isEmpty()) {
						$var($X509Certificate, xc, $cast($X509Certificate, $nc($(certs->iterator()))->next()));
						return $nc(xc)->getSubjectX500Principal();
					}
				} catch ($CertStoreException& e) {
					$init($PKIX);
					if ($PKIX::debug != nullptr) {
						$nc($PKIX::debug)->println($$str({"BuilderParams.getTargetSubjectDN: non-fatal exception retrieving certs: "_s, e}));
						e->printStackTrace();
					}
				}
			}
		}
	}
	$throwNew($InvalidAlgorithmParameterException, "Could not determine unique target subject"_s);
	$shouldNotReachHere();
}

PKIX$BuilderParams::PKIX$BuilderParams() {
}

$Class* PKIX$BuilderParams::load$($String* name, bool initialize) {
	$loadClass(PKIX$BuilderParams, name, initialize, &_PKIX$BuilderParams_ClassInfo_, allocate$PKIX$BuilderParams);
	return class$;
}

$Class* PKIX$BuilderParams::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun