#include <sun/security/validator/TrustStoreUtil.h>

#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $KeyStore = ::java::security::KeyStore;
using $KeyStoreException = ::java::security::KeyStoreException;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace sun {
	namespace security {
		namespace validator {

$MethodInfo _TrustStoreUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(TrustStoreUtil, init$, void)},
	{"getTrustedCerts", "(Ljava/security/KeyStore;)Ljava/util/Set;", "(Ljava/security/KeyStore;)Ljava/util/Set<Ljava/security/cert/X509Certificate;>;", $PUBLIC | $STATIC, $staticMethod(TrustStoreUtil, getTrustedCerts, $Set*, $KeyStore*)},
	{}
};

$ClassInfo _TrustStoreUtil_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.validator.TrustStoreUtil",
	"java.lang.Object",
	nullptr,
	nullptr,
	_TrustStoreUtil_MethodInfo_
};

$Object* allocate$TrustStoreUtil($Class* clazz) {
	return $of($alloc(TrustStoreUtil));
}

void TrustStoreUtil::init$() {
}

$Set* TrustStoreUtil::getTrustedCerts($KeyStore* ks) {
	$useLocalCurrentObjectStackCache();
	$var($Set, set, $new($HashSet));
	try {
		{
			$var($Enumeration, e, $nc(ks)->aliases());
			for (; $nc(e)->hasMoreElements();) {
				$var($String, alias, $cast($String, e->nextElement()));
				if (ks->isCertificateEntry(alias)) {
					$var($Certificate, cert, ks->getCertificate(alias));
					if ($instanceOf($X509Certificate, cert)) {
						set->add($cast($X509Certificate, cert));
					}
				} else if (ks->isKeyEntry(alias)) {
					$var($CertificateArray, certs, ks->getCertificateChain(alias));
					if ((certs != nullptr) && (certs->length > 0) && ($instanceOf($X509Certificate, certs->get(0)))) {
						set->add($cast($X509Certificate, certs->get(0)));
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
	}
	return $Collections::unmodifiableSet(set);
}

TrustStoreUtil::TrustStoreUtil() {
}

$Class* TrustStoreUtil::load$($String* name, bool initialize) {
	$loadClass(TrustStoreUtil, name, initialize, &_TrustStoreUtil_ClassInfo_, allocate$TrustStoreUtil);
	return class$;
}

$Class* TrustStoreUtil::class$ = nullptr;

		} // validator
	} // security
} // sun