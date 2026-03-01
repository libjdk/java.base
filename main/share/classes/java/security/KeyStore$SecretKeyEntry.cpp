#include <java/security/KeyStore$SecretKeyEntry.h>

#include <java/security/KeyStore$Entry$Attribute.h>
#include <java/security/KeyStore.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <javax/crypto/SecretKey.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $SecretKey = ::javax::crypto::SecretKey;

namespace java {
	namespace security {

$FieldInfo _KeyStore$SecretKeyEntry_FieldInfo_[] = {
	{"sKey", "Ljavax/crypto/SecretKey;", nullptr, $PRIVATE | $FINAL, $field(KeyStore$SecretKeyEntry, sKey)},
	{"attributes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PRIVATE | $FINAL, $field(KeyStore$SecretKeyEntry, attributes)},
	{}
};

$MethodInfo _KeyStore$SecretKeyEntry_MethodInfo_[] = {
	{"<init>", "(Ljavax/crypto/SecretKey;)V", nullptr, $PUBLIC, $method(KeyStore$SecretKeyEntry, init$, void, $SecretKey*)},
	{"<init>", "(Ljavax/crypto/SecretKey;Ljava/util/Set;)V", "(Ljavax/crypto/SecretKey;Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)V", $PUBLIC, $method(KeyStore$SecretKeyEntry, init$, void, $SecretKey*, $Set*)},
	{"getAttributes", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PUBLIC, $virtualMethod(KeyStore$SecretKeyEntry, getAttributes, $Set*)},
	{"getSecretKey", "()Ljavax/crypto/SecretKey;", nullptr, $PUBLIC, $method(KeyStore$SecretKeyEntry, getSecretKey, $SecretKey*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeyStore$SecretKeyEntry, toString, $String*)},
	{}
};

$InnerClassInfo _KeyStore$SecretKeyEntry_InnerClassesInfo_[] = {
	{"java.security.KeyStore$SecretKeyEntry", "java.security.KeyStore", "SecretKeyEntry", $PUBLIC | $STATIC | $FINAL},
	{"java.security.KeyStore$Entry", "java.security.KeyStore", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyStore$SecretKeyEntry_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.KeyStore$SecretKeyEntry",
	"java.lang.Object",
	"java.security.KeyStore$Entry",
	_KeyStore$SecretKeyEntry_FieldInfo_,
	_KeyStore$SecretKeyEntry_MethodInfo_,
	nullptr,
	nullptr,
	_KeyStore$SecretKeyEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.KeyStore"
};

$Object* allocate$KeyStore$SecretKeyEntry($Class* clazz) {
	return $of($alloc(KeyStore$SecretKeyEntry));
}

void KeyStore$SecretKeyEntry::init$($SecretKey* secretKey) {
	if (secretKey == nullptr) {
		$throwNew($NullPointerException, "invalid null input"_s);
	}
	$set(this, sKey, secretKey);
	$set(this, attributes, $Collections::emptySet());
}

void KeyStore$SecretKeyEntry::init$($SecretKey* secretKey, $Set* attributes) {
	if (secretKey == nullptr || attributes == nullptr) {
		$throwNew($NullPointerException, "invalid null input"_s);
	}
	$set(this, sKey, secretKey);
	$set(this, attributes, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(attributes))));
}

$SecretKey* KeyStore$SecretKeyEntry::getSecretKey() {
	return this->sKey;
}

$Set* KeyStore$SecretKeyEntry::getAttributes() {
	return this->attributes;
}

$String* KeyStore$SecretKeyEntry::toString() {
	return $str({"Secret key entry with algorithm "_s, $($nc(this->sKey)->getAlgorithm())});
}

KeyStore$SecretKeyEntry::KeyStore$SecretKeyEntry() {
}

$Class* KeyStore$SecretKeyEntry::load$($String* name, bool initialize) {
	$loadClass(KeyStore$SecretKeyEntry, name, initialize, &_KeyStore$SecretKeyEntry_ClassInfo_, allocate$KeyStore$SecretKeyEntry);
	return class$;
}

$Class* KeyStore$SecretKeyEntry::class$ = nullptr;

	} // security
} // java