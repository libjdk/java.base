#include <java/security/KeyStore$TrustedCertificateEntry.h>

#include <java/security/KeyStore$Entry$Attribute.h>
#include <java/security/KeyStore.h>
#include <java/security/cert/Certificate.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Certificate = ::java::security::cert::Certificate;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace java {
	namespace security {

$FieldInfo _KeyStore$TrustedCertificateEntry_FieldInfo_[] = {
	{"cert", "Ljava/security/cert/Certificate;", nullptr, $PRIVATE | $FINAL, $field(KeyStore$TrustedCertificateEntry, cert)},
	{"attributes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PRIVATE | $FINAL, $field(KeyStore$TrustedCertificateEntry, attributes)},
	{}
};

$MethodInfo _KeyStore$TrustedCertificateEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $method(KeyStore$TrustedCertificateEntry, init$, void, $Certificate*)},
	{"<init>", "(Ljava/security/cert/Certificate;Ljava/util/Set;)V", "(Ljava/security/cert/Certificate;Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)V", $PUBLIC, $method(KeyStore$TrustedCertificateEntry, init$, void, $Certificate*, $Set*)},
	{"getAttributes", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PUBLIC, $virtualMethod(KeyStore$TrustedCertificateEntry, getAttributes, $Set*)},
	{"getTrustedCertificate", "()Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $method(KeyStore$TrustedCertificateEntry, getTrustedCertificate, $Certificate*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeyStore$TrustedCertificateEntry, toString, $String*)},
	{}
};

$InnerClassInfo _KeyStore$TrustedCertificateEntry_InnerClassesInfo_[] = {
	{"java.security.KeyStore$TrustedCertificateEntry", "java.security.KeyStore", "TrustedCertificateEntry", $PUBLIC | $STATIC | $FINAL},
	{"java.security.KeyStore$Entry", "java.security.KeyStore", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyStore$TrustedCertificateEntry_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.KeyStore$TrustedCertificateEntry",
	"java.lang.Object",
	"java.security.KeyStore$Entry",
	_KeyStore$TrustedCertificateEntry_FieldInfo_,
	_KeyStore$TrustedCertificateEntry_MethodInfo_,
	nullptr,
	nullptr,
	_KeyStore$TrustedCertificateEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.KeyStore"
};

$Object* allocate$KeyStore$TrustedCertificateEntry($Class* clazz) {
	return $of($alloc(KeyStore$TrustedCertificateEntry));
}

void KeyStore$TrustedCertificateEntry::init$($Certificate* trustedCert) {
	if (trustedCert == nullptr) {
		$throwNew($NullPointerException, "invalid null input"_s);
	}
	$set(this, cert, trustedCert);
	$set(this, attributes, $Collections::emptySet());
}

void KeyStore$TrustedCertificateEntry::init$($Certificate* trustedCert, $Set* attributes) {
	if (trustedCert == nullptr || attributes == nullptr) {
		$throwNew($NullPointerException, "invalid null input"_s);
	}
	$set(this, cert, trustedCert);
	$set(this, attributes, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(attributes))));
}

$Certificate* KeyStore$TrustedCertificateEntry::getTrustedCertificate() {
	return this->cert;
}

$Set* KeyStore$TrustedCertificateEntry::getAttributes() {
	return this->attributes;
}

$String* KeyStore$TrustedCertificateEntry::toString() {
	return $str({"Trusted certificate entry:\r\n"_s, $($nc(this->cert)->toString())});
}

KeyStore$TrustedCertificateEntry::KeyStore$TrustedCertificateEntry() {
}

$Class* KeyStore$TrustedCertificateEntry::load$($String* name, bool initialize) {
	$loadClass(KeyStore$TrustedCertificateEntry, name, initialize, &_KeyStore$TrustedCertificateEntry_ClassInfo_, allocate$KeyStore$TrustedCertificateEntry);
	return class$;
}

$Class* KeyStore$TrustedCertificateEntry::class$ = nullptr;

	} // security
} // java