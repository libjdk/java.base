#include <java/security/DomainLoadStoreParameter.h>

#include <java/net/URI.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $URI = ::java::net::URI;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace java {
	namespace security {

$FieldInfo _DomainLoadStoreParameter_FieldInfo_[] = {
	{"configuration", "Ljava/net/URI;", nullptr, $PRIVATE | $FINAL, $field(DomainLoadStoreParameter, configuration)},
	{"protectionParams", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;>;", $PRIVATE | $FINAL, $field(DomainLoadStoreParameter, protectionParams)},
	{}
};

$MethodInfo _DomainLoadStoreParameter_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URI;Ljava/util/Map;)V", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;>;)V", $PUBLIC, $method(DomainLoadStoreParameter, init$, void, $URI*, $Map*)},
	{"getConfiguration", "()Ljava/net/URI;", nullptr, $PUBLIC, $method(DomainLoadStoreParameter, getConfiguration, $URI*)},
	{"getProtectionParameter", "()Ljava/security/KeyStore$ProtectionParameter;", nullptr, $PUBLIC, $virtualMethod(DomainLoadStoreParameter, getProtectionParameter, $KeyStore$ProtectionParameter*)},
	{"getProtectionParams", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;>;", $PUBLIC, $method(DomainLoadStoreParameter, getProtectionParams, $Map*)},
	{}
};

$InnerClassInfo _DomainLoadStoreParameter_InnerClassesInfo_[] = {
	{"java.security.KeyStore$LoadStoreParameter", "java.security.KeyStore", "LoadStoreParameter", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _DomainLoadStoreParameter_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.DomainLoadStoreParameter",
	"java.lang.Object",
	"java.security.KeyStore$LoadStoreParameter",
	_DomainLoadStoreParameter_FieldInfo_,
	_DomainLoadStoreParameter_MethodInfo_,
	nullptr,
	nullptr,
	_DomainLoadStoreParameter_InnerClassesInfo_
};

$Object* allocate$DomainLoadStoreParameter($Class* clazz) {
	return $of($alloc(DomainLoadStoreParameter));
}

void DomainLoadStoreParameter::init$($URI* configuration, $Map* protectionParams) {
	if (configuration == nullptr || protectionParams == nullptr) {
		$throwNew($NullPointerException, "invalid null input"_s);
	}
	$set(this, configuration, configuration);
	$set(this, protectionParams, $Collections::unmodifiableMap($$new($HashMap, protectionParams)));
}

$URI* DomainLoadStoreParameter::getConfiguration() {
	return this->configuration;
}

$Map* DomainLoadStoreParameter::getProtectionParams() {
	return this->protectionParams;
}

$KeyStore$ProtectionParameter* DomainLoadStoreParameter::getProtectionParameter() {
	return nullptr;
}

DomainLoadStoreParameter::DomainLoadStoreParameter() {
}

$Class* DomainLoadStoreParameter::load$($String* name, bool initialize) {
	$loadClass(DomainLoadStoreParameter, name, initialize, &_DomainLoadStoreParameter_ClassInfo_, allocate$DomainLoadStoreParameter);
	return class$;
}

$Class* DomainLoadStoreParameter::class$ = nullptr;

	} // security
} // java