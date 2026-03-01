#include <java/security/ProtectionDomain$JavaSecurityAccessImpl$1.h>

#include <java/security/PermissionCollection.h>
#include <java/security/ProtectionDomain$JavaSecurityAccessImpl.h>
#include <java/security/ProtectionDomain$Key.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Collections.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PermissionCollection = ::java::security::PermissionCollection;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $ProtectionDomain$JavaSecurityAccessImpl = ::java::security::ProtectionDomain$JavaSecurityAccessImpl;
using $ProtectionDomain$Key = ::java::security::ProtectionDomain$Key;
using $Collections = ::java::util::Collections;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;

namespace java {
	namespace security {

$FieldInfo _ProtectionDomain$JavaSecurityAccessImpl$1_FieldInfo_[] = {
	{"this$0", "Ljava/security/ProtectionDomain$JavaSecurityAccessImpl;", nullptr, $FINAL | $SYNTHETIC, $field(ProtectionDomain$JavaSecurityAccessImpl$1, this$0)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/ProtectionDomain$Key;Ljava/security/PermissionCollection;>;", $PRIVATE | $FINAL, $field(ProtectionDomain$JavaSecurityAccessImpl$1, map)},
	{}
};

$MethodInfo _ProtectionDomain$JavaSecurityAccessImpl$1_MethodInfo_[] = {
	{"<init>", "(Ljava/security/ProtectionDomain$JavaSecurityAccessImpl;)V", nullptr, 0, $method(ProtectionDomain$JavaSecurityAccessImpl$1, init$, void, $ProtectionDomain$JavaSecurityAccessImpl*)},
	{"get", "(Ljava/security/ProtectionDomain;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(ProtectionDomain$JavaSecurityAccessImpl$1, get, $PermissionCollection*, $ProtectionDomain*)},
	{"put", "(Ljava/security/ProtectionDomain;Ljava/security/PermissionCollection;)V", nullptr, $PUBLIC, $virtualMethod(ProtectionDomain$JavaSecurityAccessImpl$1, put, void, $ProtectionDomain*, $PermissionCollection*)},
	{}
};

$EnclosingMethodInfo _ProtectionDomain$JavaSecurityAccessImpl$1_EnclosingMethodInfo_ = {
	"java.security.ProtectionDomain$JavaSecurityAccessImpl",
	"getProtectionDomainCache",
	"()Ljdk/internal/access/JavaSecurityAccess$ProtectionDomainCache;"
};

$InnerClassInfo _ProtectionDomain$JavaSecurityAccessImpl$1_InnerClassesInfo_[] = {
	{"java.security.ProtectionDomain$JavaSecurityAccessImpl", "java.security.ProtectionDomain", "JavaSecurityAccessImpl", $PRIVATE | $STATIC},
	{"java.security.ProtectionDomain$JavaSecurityAccessImpl$1", nullptr, nullptr, 0},
	{"jdk.internal.access.JavaSecurityAccess$ProtectionDomainCache", "jdk.internal.access.JavaSecurityAccess", "ProtectionDomainCache", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ProtectionDomain$JavaSecurityAccessImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.security.ProtectionDomain$JavaSecurityAccessImpl$1",
	"java.lang.Object",
	"jdk.internal.access.JavaSecurityAccess$ProtectionDomainCache",
	_ProtectionDomain$JavaSecurityAccessImpl$1_FieldInfo_,
	_ProtectionDomain$JavaSecurityAccessImpl$1_MethodInfo_,
	nullptr,
	&_ProtectionDomain$JavaSecurityAccessImpl$1_EnclosingMethodInfo_,
	_ProtectionDomain$JavaSecurityAccessImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.ProtectionDomain"
};

$Object* allocate$ProtectionDomain$JavaSecurityAccessImpl$1($Class* clazz) {
	return $of($alloc(ProtectionDomain$JavaSecurityAccessImpl$1));
}

void ProtectionDomain$JavaSecurityAccessImpl$1::init$($ProtectionDomain$JavaSecurityAccessImpl* this$0) {
	$set(this, this$0, this$0);
	$set(this, map, $Collections::synchronizedMap($$new($WeakHashMap)));
}

void ProtectionDomain$JavaSecurityAccessImpl$1::put($ProtectionDomain* pd, $PermissionCollection* pc) {
	$nc(this->map)->put((pd == nullptr ? ($ProtectionDomain$Key*)nullptr : $nc(pd)->key), pc);
}

$PermissionCollection* ProtectionDomain$JavaSecurityAccessImpl$1::get($ProtectionDomain* pd) {
	return pd == nullptr ? $cast($PermissionCollection, $nc(this->map)->get(nullptr)) : $cast($PermissionCollection, $nc(this->map)->get($nc(pd)->key));
}

ProtectionDomain$JavaSecurityAccessImpl$1::ProtectionDomain$JavaSecurityAccessImpl$1() {
}

$Class* ProtectionDomain$JavaSecurityAccessImpl$1::load$($String* name, bool initialize) {
	$loadClass(ProtectionDomain$JavaSecurityAccessImpl$1, name, initialize, &_ProtectionDomain$JavaSecurityAccessImpl$1_ClassInfo_, allocate$ProtectionDomain$JavaSecurityAccessImpl$1);
	return class$;
}

$Class* ProtectionDomain$JavaSecurityAccessImpl$1::class$ = nullptr;

	} // security
} // java