#include <java/security/KeyStore$PrivateKeyEntry.h>

#include <java/security/KeyStore$Entry$Attribute.h>
#include <java/security/KeyStore.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace java {
	namespace security {

$FieldInfo _KeyStore$PrivateKeyEntry_FieldInfo_[] = {
	{"privKey", "Ljava/security/PrivateKey;", nullptr, $PRIVATE | $FINAL, $field(KeyStore$PrivateKeyEntry, privKey)},
	{"chain", "[Ljava/security/cert/Certificate;", nullptr, $PRIVATE | $FINAL, $field(KeyStore$PrivateKeyEntry, chain)},
	{"attributes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PRIVATE | $FINAL, $field(KeyStore$PrivateKeyEntry, attributes)},
	{}
};

$MethodInfo _KeyStore$PrivateKeyEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/security/PrivateKey;[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $method(KeyStore$PrivateKeyEntry, init$, void, $PrivateKey*, $CertificateArray*)},
	{"<init>", "(Ljava/security/PrivateKey;[Ljava/security/cert/Certificate;Ljava/util/Set;)V", "(Ljava/security/PrivateKey;[Ljava/security/cert/Certificate;Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)V", $PUBLIC, $method(KeyStore$PrivateKeyEntry, init$, void, $PrivateKey*, $CertificateArray*, $Set*)},
	{"getAttributes", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PUBLIC, $virtualMethod(KeyStore$PrivateKeyEntry, getAttributes, $Set*)},
	{"getCertificate", "()Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $method(KeyStore$PrivateKeyEntry, getCertificate, $Certificate*)},
	{"getCertificateChain", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $method(KeyStore$PrivateKeyEntry, getCertificateChain, $CertificateArray*)},
	{"getPrivateKey", "()Ljava/security/PrivateKey;", nullptr, $PUBLIC, $method(KeyStore$PrivateKeyEntry, getPrivateKey, $PrivateKey*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeyStore$PrivateKeyEntry, toString, $String*)},
	{}
};

$InnerClassInfo _KeyStore$PrivateKeyEntry_InnerClassesInfo_[] = {
	{"java.security.KeyStore$PrivateKeyEntry", "java.security.KeyStore", "PrivateKeyEntry", $PUBLIC | $STATIC | $FINAL},
	{"java.security.KeyStore$Entry", "java.security.KeyStore", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyStore$PrivateKeyEntry_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.KeyStore$PrivateKeyEntry",
	"java.lang.Object",
	"java.security.KeyStore$Entry",
	_KeyStore$PrivateKeyEntry_FieldInfo_,
	_KeyStore$PrivateKeyEntry_MethodInfo_,
	nullptr,
	nullptr,
	_KeyStore$PrivateKeyEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.KeyStore"
};

$Object* allocate$KeyStore$PrivateKeyEntry($Class* clazz) {
	return $of($alloc(KeyStore$PrivateKeyEntry));
}

void KeyStore$PrivateKeyEntry::init$($PrivateKey* privateKey, $CertificateArray* chain) {
	KeyStore$PrivateKeyEntry::init$(privateKey, chain, $($Collections::emptySet()));
}

void KeyStore$PrivateKeyEntry::init$($PrivateKey* privateKey, $CertificateArray* chain, $Set* attributes) {
	$useLocalCurrentObjectStackCache();
	if (privateKey == nullptr || chain == nullptr || attributes == nullptr) {
		$throwNew($NullPointerException, "invalid null input"_s);
	}
	if ($nc(chain)->length == 0) {
		$throwNew($IllegalArgumentException, "invalid zero-length input chain"_s);
	}
	$var($CertificateArray, clonedChain, $cast($CertificateArray, $nc(chain)->clone()));
	$var($String, certType, $nc(clonedChain->get(0))->getType());
	for (int32_t i = 1; i < clonedChain->length; ++i) {
		if (!$nc(certType)->equals($($nc(clonedChain->get(i))->getType()))) {
			$throwNew($IllegalArgumentException, "chain does not contain certificates of the same type"_s);
		}
	}
	if (!$nc($($nc(privateKey)->getAlgorithm()))->equals($($nc($($nc(clonedChain->get(0))->getPublicKey()))->getAlgorithm()))) {
		$throwNew($IllegalArgumentException, "private key algorithm does not match algorithm of public key in end entity certificate (at index 0)"_s);
	}
	$set(this, privKey, privateKey);
	if ($instanceOf($X509Certificate, clonedChain->get(0)) && !($instanceOf($X509CertificateArray, clonedChain))) {
		$set(this, chain, $fcast($CertificateArray, $new($X509CertificateArray, clonedChain->length)));
		$System::arraycopy(clonedChain, 0, this->chain, 0, clonedChain->length);
	} else {
		$set(this, chain, clonedChain);
	}
	$set(this, attributes, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(attributes))));
}

$PrivateKey* KeyStore$PrivateKeyEntry::getPrivateKey() {
	return this->privKey;
}

$CertificateArray* KeyStore$PrivateKeyEntry::getCertificateChain() {
	return $cast($CertificateArray, $nc(this->chain)->clone());
}

$Certificate* KeyStore$PrivateKeyEntry::getCertificate() {
	return $nc(this->chain)->get(0);
}

$Set* KeyStore$PrivateKeyEntry::getAttributes() {
	return this->attributes;
}

$String* KeyStore$PrivateKeyEntry::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($$str({"Private key entry and certificate chain with "_s, $$str($nc(this->chain)->length), " elements:\r\n"_s}));
	{
		$var($CertificateArray, arr$, this->chain);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Certificate, cert, arr$->get(i$));
			{
				sb->append($of(cert));
				sb->append("\r\n"_s);
			}
		}
	}
	return sb->toString();
}

KeyStore$PrivateKeyEntry::KeyStore$PrivateKeyEntry() {
}

$Class* KeyStore$PrivateKeyEntry::load$($String* name, bool initialize) {
	$loadClass(KeyStore$PrivateKeyEntry, name, initialize, &_KeyStore$PrivateKeyEntry_ClassInfo_, allocate$KeyStore$PrivateKeyEntry);
	return class$;
}

$Class* KeyStore$PrivateKeyEntry::class$ = nullptr;

	} // security
} // java