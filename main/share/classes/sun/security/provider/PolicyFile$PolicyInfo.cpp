#include <sun/security/provider/PolicyFile$PolicyInfo.h>

#include <java/lang/Math.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Random.h>
#include <jdk/internal/access/JavaSecurityAccess$ProtectionDomainCache.h>
#include <jdk/internal/access/JavaSecurityAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/security/provider/PolicyFile.h>
#include <jcpp.h>

using $JavaSecurityAccess$ProtectionDomainCacheArray = $Array<::jdk::internal::access::JavaSecurityAccess$ProtectionDomainCache>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Random = ::java::util::Random;
using $JavaSecurityAccess = ::jdk::internal::access::JavaSecurityAccess;
using $JavaSecurityAccess$ProtectionDomainCache = ::jdk::internal::access::JavaSecurityAccess$ProtectionDomainCache;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicyFile$PolicyInfo_FieldInfo_[] = {
	{"verbose", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PolicyFile$PolicyInfo, verbose)},
	{"policyEntries", "Ljava/util/List;", "Ljava/util/List<Lsun/security/provider/PolicyFile$PolicyEntry;>;", $FINAL, $field(PolicyFile$PolicyInfo, policyEntries)},
	{"aliasMapping", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Object;Ljava/lang/Object;>;", $FINAL, $field(PolicyFile$PolicyInfo, aliasMapping)},
	{"pdMapping", "[Ljdk/internal/access/JavaSecurityAccess$ProtectionDomainCache;", nullptr, $PRIVATE | $FINAL, $field(PolicyFile$PolicyInfo, pdMapping)},
	{"random", "Ljava/util/Random;", nullptr, $PRIVATE, $field(PolicyFile$PolicyInfo, random)},
	{}
};

$MethodInfo _PolicyFile$PolicyInfo_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(PolicyFile$PolicyInfo, init$, void, int32_t)},
	{"getPdMapping", "()Ljdk/internal/access/JavaSecurityAccess$ProtectionDomainCache;", nullptr, 0, $virtualMethod(PolicyFile$PolicyInfo, getPdMapping, $JavaSecurityAccess$ProtectionDomainCache*)},
	{}
};

$InnerClassInfo _PolicyFile$PolicyInfo_InnerClassesInfo_[] = {
	{"sun.security.provider.PolicyFile$PolicyInfo", "sun.security.provider.PolicyFile", "PolicyInfo", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PolicyFile$PolicyInfo_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.PolicyFile$PolicyInfo",
	"java.lang.Object",
	nullptr,
	_PolicyFile$PolicyInfo_FieldInfo_,
	_PolicyFile$PolicyInfo_MethodInfo_,
	nullptr,
	nullptr,
	_PolicyFile$PolicyInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.PolicyFile"
};

$Object* allocate$PolicyFile$PolicyInfo($Class* clazz) {
	return $of($alloc(PolicyFile$PolicyInfo));
}

void PolicyFile$PolicyInfo::init$(int32_t numCaches) {
	$useLocalCurrentObjectStackCache();
	$set(this, policyEntries, $new($ArrayList));
	$set(this, aliasMapping, $Collections::synchronizedMap($$new($HashMap, 11)));
	$set(this, pdMapping, $new($JavaSecurityAccess$ProtectionDomainCacheArray, numCaches));
	$var($JavaSecurityAccess, jspda, $SharedSecrets::getJavaSecurityAccess());
	for (int32_t i = 0; i < numCaches; ++i) {
		$nc(this->pdMapping)->set(i, $($nc(jspda)->getProtectionDomainCache()));
	}
	if (numCaches > 1) {
		$set(this, random, $new($Random));
	}
}

$JavaSecurityAccess$ProtectionDomainCache* PolicyFile$PolicyInfo::getPdMapping() {
	if ($nc(this->pdMapping)->length == 1) {
		return $nc(this->pdMapping)->get(0);
	} else {
		int32_t i = $Math::abs($mod($nc(this->random)->nextInt(), $nc(this->pdMapping)->length));
		return $nc(this->pdMapping)->get(i);
	}
}

PolicyFile$PolicyInfo::PolicyFile$PolicyInfo() {
}

$Class* PolicyFile$PolicyInfo::load$($String* name, bool initialize) {
	$loadClass(PolicyFile$PolicyInfo, name, initialize, &_PolicyFile$PolicyInfo_ClassInfo_, allocate$PolicyFile$PolicyInfo);
	return class$;
}

$Class* PolicyFile$PolicyInfo::class$ = nullptr;

		} // provider
	} // security
} // sun