#include <java/security/cert/PKIXRevocationChecker.h>

#include <java/net/URI.h>
#include <java/security/cert/Extension.h>
#include <java/security/cert/PKIXCertPathChecker.h>
#include <java/security/cert/PKIXRevocationChecker$Option.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $PKIXCertPathChecker = ::java::security::cert::PKIXCertPathChecker;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _PKIXRevocationChecker_FieldInfo_[] = {
	{"ocspResponder", "Ljava/net/URI;", nullptr, $PRIVATE, $field(PKIXRevocationChecker, ocspResponder)},
	{"ocspResponderCert", "Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(PKIXRevocationChecker, ocspResponderCert)},
	{"ocspExtensions", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/Extension;>;", $PRIVATE, $field(PKIXRevocationChecker, ocspExtensions)},
	{"ocspResponses", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/cert/X509Certificate;[B>;", $PRIVATE, $field(PKIXRevocationChecker, ocspResponses)},
	{"options", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/PKIXRevocationChecker$Option;>;", $PRIVATE, $field(PKIXRevocationChecker, options)},
	{}
};

$MethodInfo _PKIXRevocationChecker_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(PKIXRevocationChecker, init$, void)},
	{"clone", "()Ljava/security/cert/PKIXRevocationChecker;", nullptr, $PUBLIC, $virtualMethod(PKIXRevocationChecker, clone, $Object*)},
	{"getOcspExtensions", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/Extension;>;", $PUBLIC, $virtualMethod(PKIXRevocationChecker, getOcspExtensions, $List*)},
	{"getOcspResponder", "()Ljava/net/URI;", nullptr, $PUBLIC, $virtualMethod(PKIXRevocationChecker, getOcspResponder, $URI*)},
	{"getOcspResponderCert", "()Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(PKIXRevocationChecker, getOcspResponderCert, $X509Certificate*)},
	{"getOcspResponses", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/security/cert/X509Certificate;[B>;", $PUBLIC, $virtualMethod(PKIXRevocationChecker, getOcspResponses, $Map*)},
	{"getOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/cert/PKIXRevocationChecker$Option;>;", $PUBLIC, $virtualMethod(PKIXRevocationChecker, getOptions, $Set*)},
	{"getSoftFailExceptions", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/CertPathValidatorException;>;", $PUBLIC | $ABSTRACT, $virtualMethod(PKIXRevocationChecker, getSoftFailExceptions, $List*)},
	{"setOcspExtensions", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/security/cert/Extension;>;)V", $PUBLIC, $virtualMethod(PKIXRevocationChecker, setOcspExtensions, void, $List*)},
	{"setOcspResponder", "(Ljava/net/URI;)V", nullptr, $PUBLIC, $virtualMethod(PKIXRevocationChecker, setOcspResponder, void, $URI*)},
	{"setOcspResponderCert", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PUBLIC, $virtualMethod(PKIXRevocationChecker, setOcspResponderCert, void, $X509Certificate*)},
	{"setOcspResponses", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/security/cert/X509Certificate;[B>;)V", $PUBLIC, $virtualMethod(PKIXRevocationChecker, setOcspResponses, void, $Map*)},
	{"setOptions", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/security/cert/PKIXRevocationChecker$Option;>;)V", $PUBLIC, $virtualMethod(PKIXRevocationChecker, setOptions, void, $Set*)},
	{}
};

$InnerClassInfo _PKIXRevocationChecker_InnerClassesInfo_[] = {
	{"java.security.cert.PKIXRevocationChecker$Option", "java.security.cert.PKIXRevocationChecker", "Option", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _PKIXRevocationChecker_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.cert.PKIXRevocationChecker",
	"java.security.cert.PKIXCertPathChecker",
	nullptr,
	_PKIXRevocationChecker_FieldInfo_,
	_PKIXRevocationChecker_MethodInfo_,
	nullptr,
	nullptr,
	_PKIXRevocationChecker_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.cert.PKIXRevocationChecker$Option"
};

$Object* allocate$PKIXRevocationChecker($Class* clazz) {
	return $of($alloc(PKIXRevocationChecker));
}

void PKIXRevocationChecker::init$() {
	$PKIXCertPathChecker::init$();
	$set(this, ocspExtensions, $Collections::emptyList());
	$set(this, ocspResponses, $Collections::emptyMap());
	$set(this, options, $Collections::emptySet());
}

void PKIXRevocationChecker::setOcspResponder($URI* uri) {
	$set(this, ocspResponder, uri);
}

$URI* PKIXRevocationChecker::getOcspResponder() {
	return this->ocspResponder;
}

void PKIXRevocationChecker::setOcspResponderCert($X509Certificate* cert) {
	$set(this, ocspResponderCert, cert);
}

$X509Certificate* PKIXRevocationChecker::getOcspResponderCert() {
	return this->ocspResponderCert;
}

void PKIXRevocationChecker::setOcspExtensions($List* extensions) {
	$set(this, ocspExtensions, (extensions == nullptr) ? $Collections::emptyList() : static_cast<$List*>($new($ArrayList, static_cast<$Collection*>(extensions))));
}

$List* PKIXRevocationChecker::getOcspExtensions() {
	return $Collections::unmodifiableList(this->ocspExtensions);
}

void PKIXRevocationChecker::setOcspResponses($Map* responses) {
	$useLocalCurrentObjectStackCache();
	if (responses == nullptr) {
		$set(this, ocspResponses, $Collections::emptyMap());
	} else {
		$var($Map, copy, $new($HashMap, $nc(responses)->size()));
		{
			$var($Iterator, i$, $nc($($nc(responses)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					$var($Object, var$0, $cast($X509Certificate, $nc(e)->getKey()));
					copy->put(var$0, $cast($bytes, $($nc(($cast($bytes, $(e->getValue()))))->clone())));
				}
			}
		}
		$set(this, ocspResponses, copy);
	}
}

$Map* PKIXRevocationChecker::getOcspResponses() {
	$useLocalCurrentObjectStackCache();
	$var($Map, copy, $new($HashMap, $nc(this->ocspResponses)->size()));
	{
		$var($Iterator, i$, $nc($($nc(this->ocspResponses)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($Object, var$0, $cast($X509Certificate, $nc(e)->getKey()));
				copy->put(var$0, $cast($bytes, $($nc(($cast($bytes, $(e->getValue()))))->clone())));
			}
		}
	}
	return copy;
}

void PKIXRevocationChecker::setOptions($Set* options) {
	$set(this, options, (options == nullptr) ? $Collections::emptySet() : static_cast<$Set*>($new($HashSet, static_cast<$Collection*>(options))));
}

$Set* PKIXRevocationChecker::getOptions() {
	return $Collections::unmodifiableSet(this->options);
}

$Object* PKIXRevocationChecker::clone() {
	$useLocalCurrentObjectStackCache();
	$var(PKIXRevocationChecker, copy, $cast(PKIXRevocationChecker, $PKIXCertPathChecker::clone()));
	$set($nc(copy), ocspExtensions, $new($ArrayList, static_cast<$Collection*>(this->ocspExtensions)));
	$set(copy, ocspResponses, $new($HashMap, this->ocspResponses));
	{
		$var($Iterator, i$, $nc($($nc(copy->ocspResponses)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($bytes, encoded, $cast($bytes, $nc(entry)->getValue()));
				entry->setValue($cast($bytes, $($nc(encoded)->clone())));
			}
		}
	}
	$set(copy, options, $new($HashSet, static_cast<$Collection*>(this->options)));
	return $of(copy);
}

PKIXRevocationChecker::PKIXRevocationChecker() {
}

$Class* PKIXRevocationChecker::load$($String* name, bool initialize) {
	$loadClass(PKIXRevocationChecker, name, initialize, &_PKIXRevocationChecker_ClassInfo_, allocate$PKIXRevocationChecker);
	return class$;
}

$Class* PKIXRevocationChecker::class$ = nullptr;

		} // cert
	} // security
} // java