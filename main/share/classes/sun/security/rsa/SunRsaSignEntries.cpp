#include <sun/security/rsa/SunRsaSignEntries.h>

#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/util/SecurityProviderConstants.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $MethodInfo = ::java::lang::MethodInfo;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $SecurityProviderConstants = ::sun::security::util::SecurityProviderConstants;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _SunRsaSignEntries_FieldInfo_[] = {
	{"services", "Ljava/util/LinkedHashSet;", "Ljava/util/LinkedHashSet<Ljava/security/Provider$Service;>;", $PRIVATE, $field(SunRsaSignEntries, services)},
	{}
};

$MethodInfo _SunRsaSignEntries_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Provider;)V", nullptr, $PUBLIC, $method(SunRsaSignEntries, init$, void, $Provider*)},
	{"add", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/List;Ljava/util/HashMap;)V", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(SunRsaSignEntries, add, void, $Provider*, $String*, $String*, $String*, $List*, $HashMap*)},
	{"addA", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap;)V", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(SunRsaSignEntries, addA, void, $Provider*, $String*, $String*, $String*, $HashMap*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/security/Provider$Service;>;", $PUBLIC, $method(SunRsaSignEntries, iterator, $Iterator*)},
	{}
};

$ClassInfo _SunRsaSignEntries_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.rsa.SunRsaSignEntries",
	"java.lang.Object",
	nullptr,
	_SunRsaSignEntries_FieldInfo_,
	_SunRsaSignEntries_MethodInfo_
};

$Object* allocate$SunRsaSignEntries($Class* clazz) {
	return $of($alloc(SunRsaSignEntries));
}

void SunRsaSignEntries::add($Provider* p, $String* type, $String* algo, $String* cn, $List* aliases, $HashMap* attrs) {
	$nc(this->services)->add($$new($Provider$Service, p, type, algo, cn, aliases, attrs));
}

void SunRsaSignEntries::addA($Provider* p, $String* type, $String* algo, $String* cn, $HashMap* attrs) {
	$useLocalCurrentObjectStackCache();
	$nc(this->services)->add($$new($Provider$Service, p, type, algo, cn, $($SecurityProviderConstants::getAliases(algo)), attrs));
}

void SunRsaSignEntries::init$($Provider* p) {
	$useLocalCurrentObjectStackCache();
	$set(this, services, $new($LinkedHashSet, 20, 0.9f));
	$var($HashMap, attrs, $new($HashMap, 3));
	attrs->put("SupportedKeyClasses"_s, "java.security.interfaces.RSAPublicKey|java.security.interfaces.RSAPrivateKey"_s);
	add(p, "KeyFactory"_s, "RSA"_s, "sun.security.rsa.RSAKeyFactory$Legacy"_s, $($SecurityProviderConstants::getAliases("PKCS1"_s)), nullptr);
	add(p, "KeyPairGenerator"_s, "RSA"_s, "sun.security.rsa.RSAKeyPairGenerator$Legacy"_s, $($SecurityProviderConstants::getAliases("PKCS1"_s)), nullptr);
	addA(p, "Signature"_s, "MD2withRSA"_s, "sun.security.rsa.RSASignature$MD2withRSA"_s, attrs);
	addA(p, "Signature"_s, "MD5withRSA"_s, "sun.security.rsa.RSASignature$MD5withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA1withRSA"_s, "sun.security.rsa.RSASignature$SHA1withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA224withRSA"_s, "sun.security.rsa.RSASignature$SHA224withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA256withRSA"_s, "sun.security.rsa.RSASignature$SHA256withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA384withRSA"_s, "sun.security.rsa.RSASignature$SHA384withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA512withRSA"_s, "sun.security.rsa.RSASignature$SHA512withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA512/224withRSA"_s, "sun.security.rsa.RSASignature$SHA512_224withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA512/256withRSA"_s, "sun.security.rsa.RSASignature$SHA512_256withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA3-224withRSA"_s, "sun.security.rsa.RSASignature$SHA3_224withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA3-256withRSA"_s, "sun.security.rsa.RSASignature$SHA3_256withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA3-384withRSA"_s, "sun.security.rsa.RSASignature$SHA3_384withRSA"_s, attrs);
	addA(p, "Signature"_s, "SHA3-512withRSA"_s, "sun.security.rsa.RSASignature$SHA3_512withRSA"_s, attrs);
	addA(p, "KeyFactory"_s, "RSASSA-PSS"_s, "sun.security.rsa.RSAKeyFactory$PSS"_s, attrs);
	addA(p, "KeyPairGenerator"_s, "RSASSA-PSS"_s, "sun.security.rsa.RSAKeyPairGenerator$PSS"_s, attrs);
	addA(p, "Signature"_s, "RSASSA-PSS"_s, "sun.security.rsa.RSAPSSSignature"_s, attrs);
	addA(p, "AlgorithmParameters"_s, "RSASSA-PSS"_s, "sun.security.rsa.PSSParameters"_s, nullptr);
}

$Iterator* SunRsaSignEntries::iterator() {
	return $nc(this->services)->iterator();
}

SunRsaSignEntries::SunRsaSignEntries() {
}

$Class* SunRsaSignEntries::load$($String* name, bool initialize) {
	$loadClass(SunRsaSignEntries, name, initialize, &_SunRsaSignEntries_ClassInfo_, allocate$SunRsaSignEntries);
	return class$;
}

$Class* SunRsaSignEntries::class$ = nullptr;

		} // rsa
	} // security
} // sun