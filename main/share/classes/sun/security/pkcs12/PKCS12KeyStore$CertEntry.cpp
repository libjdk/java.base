#include <sun/security/pkcs12/PKCS12KeyStore$CertEntry.h>

#include <java/security/cert/X509Certificate.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/security/pkcs12/PKCS12KeyStore$Entry.h>
#include <sun/security/pkcs12/PKCS12KeyStore.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

using $ObjectIdentifierArray = $Array<::sun::security::util::ObjectIdentifier>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $PKCS12KeyStore$Entry = ::sun::security::pkcs12::PKCS12KeyStore$Entry;

namespace sun {
	namespace security {
		namespace pkcs12 {

$FieldInfo _PKCS12KeyStore$CertEntry_FieldInfo_[] = {
	{"cert", "Ljava/security/cert/X509Certificate;", nullptr, $FINAL, $field(PKCS12KeyStore$CertEntry, cert)},
	{"trustedKeyUsage", "[Lsun/security/util/ObjectIdentifier;", nullptr, 0, $field(PKCS12KeyStore$CertEntry, trustedKeyUsage)},
	{}
};

$MethodInfo _PKCS12KeyStore$CertEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/X509Certificate;[BLjava/lang/String;)V", nullptr, 0, $method(PKCS12KeyStore$CertEntry, init$, void, $X509Certificate*, $bytes*, $String*)},
	{"<init>", "(Ljava/security/cert/X509Certificate;[BLjava/lang/String;[Lsun/security/util/ObjectIdentifier;Ljava/util/Set;)V", "(Ljava/security/cert/X509Certificate;[BLjava/lang/String;[Lsun/security/util/ObjectIdentifier;Ljava/util/Set<+Ljava/security/KeyStore$Entry$Attribute;>;)V", 0, $method(PKCS12KeyStore$CertEntry, init$, void, $X509Certificate*, $bytes*, $String*, $ObjectIdentifierArray*, $Set*)},
	{}
};

$InnerClassInfo _PKCS12KeyStore$CertEntry_InnerClassesInfo_[] = {
	{"sun.security.pkcs12.PKCS12KeyStore$CertEntry", "sun.security.pkcs12.PKCS12KeyStore", "CertEntry", $PRIVATE | $STATIC},
	{"sun.security.pkcs12.PKCS12KeyStore$Entry", "sun.security.pkcs12.PKCS12KeyStore", "Entry", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PKCS12KeyStore$CertEntry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.pkcs12.PKCS12KeyStore$CertEntry",
	"sun.security.pkcs12.PKCS12KeyStore$Entry",
	nullptr,
	_PKCS12KeyStore$CertEntry_FieldInfo_,
	_PKCS12KeyStore$CertEntry_MethodInfo_,
	nullptr,
	nullptr,
	_PKCS12KeyStore$CertEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.pkcs12.PKCS12KeyStore"
};

$Object* allocate$PKCS12KeyStore$CertEntry($Class* clazz) {
	return $of($alloc(PKCS12KeyStore$CertEntry));
}

void PKCS12KeyStore$CertEntry::init$($X509Certificate* cert, $bytes* keyId, $String* alias) {
	PKCS12KeyStore$CertEntry::init$(cert, keyId, alias, nullptr, nullptr);
}

void PKCS12KeyStore$CertEntry::init$($X509Certificate* cert, $bytes* keyId, $String* alias, $ObjectIdentifierArray* trustedKeyUsage, $Set* attributes) {
	$PKCS12KeyStore$Entry::init$();
	$set(this, date, $new($Date));
	$set(this, cert, cert);
	$set(this, keyId, keyId);
	$set(this, alias, alias);
	$set(this, trustedKeyUsage, trustedKeyUsage);
	$set(this, attributes, $new($HashSet));
	if (attributes != nullptr) {
		$nc(this->attributes)->addAll(attributes);
	}
}

PKCS12KeyStore$CertEntry::PKCS12KeyStore$CertEntry() {
}

$Class* PKCS12KeyStore$CertEntry::load$($String* name, bool initialize) {
	$loadClass(PKCS12KeyStore$CertEntry, name, initialize, &_PKCS12KeyStore$CertEntry_ClassInfo_, allocate$PKCS12KeyStore$CertEntry);
	return class$;
}

$Class* PKCS12KeyStore$CertEntry::class$ = nullptr;

		} // pkcs12
	} // security
} // sun