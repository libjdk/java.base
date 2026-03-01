#include <sun/security/ssl/SunX509KeyManagerImpl$X509Credentials.h>

#include <java/security/PrivateKey.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/ssl/SunX509KeyManagerImpl.h>
#include <jcpp.h>

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivateKey = ::java::security::PrivateKey;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SunX509KeyManagerImpl$X509Credentials_FieldInfo_[] = {
	{"privateKey", "Ljava/security/PrivateKey;", nullptr, $FINAL, $field(SunX509KeyManagerImpl$X509Credentials, privateKey)},
	{"certificates", "[Ljava/security/cert/X509Certificate;", nullptr, $FINAL, $field(SunX509KeyManagerImpl$X509Credentials, certificates)},
	{"issuerX500Principals", "Ljava/util/Set;", "Ljava/util/Set<Ljavax/security/auth/x500/X500Principal;>;", $PRIVATE | $FINAL, $field(SunX509KeyManagerImpl$X509Credentials, issuerX500Principals)},
	{}
};

$MethodInfo _SunX509KeyManagerImpl$X509Credentials_MethodInfo_[] = {
	{"<init>", "(Ljava/security/PrivateKey;[Ljava/security/cert/X509Certificate;)V", nullptr, 0, $method(SunX509KeyManagerImpl$X509Credentials, init$, void, $PrivateKey*, $X509CertificateArray*)},
	{"getIssuerX500Principals", "()Ljava/util/Set;", "()Ljava/util/Set<Ljavax/security/auth/x500/X500Principal;>;", 0, $virtualMethod(SunX509KeyManagerImpl$X509Credentials, getIssuerX500Principals, $Set*)},
	{}
};

$InnerClassInfo _SunX509KeyManagerImpl$X509Credentials_InnerClassesInfo_[] = {
	{"sun.security.ssl.SunX509KeyManagerImpl$X509Credentials", "sun.security.ssl.SunX509KeyManagerImpl", "X509Credentials", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SunX509KeyManagerImpl$X509Credentials_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.SunX509KeyManagerImpl$X509Credentials",
	"java.lang.Object",
	nullptr,
	_SunX509KeyManagerImpl$X509Credentials_FieldInfo_,
	_SunX509KeyManagerImpl$X509Credentials_MethodInfo_,
	nullptr,
	nullptr,
	_SunX509KeyManagerImpl$X509Credentials_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SunX509KeyManagerImpl"
};

$Object* allocate$SunX509KeyManagerImpl$X509Credentials($Class* clazz) {
	return $of($alloc(SunX509KeyManagerImpl$X509Credentials));
}

void SunX509KeyManagerImpl$X509Credentials::init$($PrivateKey* privateKey, $X509CertificateArray* certificates) {
	$useLocalCurrentObjectStackCache();
	$set(this, privateKey, privateKey);
	$set(this, certificates, certificates);
	$set(this, issuerX500Principals, $new($HashSet, $nc(certificates)->length));
	{
		$var($X509CertificateArray, arr$, certificates);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($X509Certificate, certificate, arr$->get(i$));
			{
				$nc(this->issuerX500Principals)->add($($nc(certificate)->getIssuerX500Principal()));
			}
		}
	}
}

$Set* SunX509KeyManagerImpl$X509Credentials::getIssuerX500Principals() {
	return this->issuerX500Principals;
}

SunX509KeyManagerImpl$X509Credentials::SunX509KeyManagerImpl$X509Credentials() {
}

$Class* SunX509KeyManagerImpl$X509Credentials::load$($String* name, bool initialize) {
	$loadClass(SunX509KeyManagerImpl$X509Credentials, name, initialize, &_SunX509KeyManagerImpl$X509Credentials_ClassInfo_, allocate$SunX509KeyManagerImpl$X509Credentials);
	return class$;
}

$Class* SunX509KeyManagerImpl$X509Credentials::class$ = nullptr;

		} // ssl
	} // security
} // sun