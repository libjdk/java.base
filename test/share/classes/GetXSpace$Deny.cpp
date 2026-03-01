#include <GetXSpace$Deny.h>

#include <GetXSpace.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/Permission.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;

$MethodInfo _GetXSpace$Deny_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(GetXSpace$Deny, init$, void)},
	{"checkPermission", "(Ljava/security/Permission;)V", nullptr, $PUBLIC, $virtualMethod(GetXSpace$Deny, checkPermission, void, $Permission*)},
	{"checkPermission", "(Ljava/security/Permission;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(GetXSpace$Deny, checkPermission, void, $Permission*, Object$*)},
	{}
};

$InnerClassInfo _GetXSpace$Deny_InnerClassesInfo_[] = {
	{"GetXSpace$Deny", "GetXSpace", "Deny", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _GetXSpace$Deny_ClassInfo_ = {
	$ACC_SUPER,
	"GetXSpace$Deny",
	"java.lang.SecurityManager",
	nullptr,
	nullptr,
	_GetXSpace$Deny_MethodInfo_,
	nullptr,
	nullptr,
	_GetXSpace$Deny_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"GetXSpace"
};

$Object* allocate$GetXSpace$Deny($Class* clazz) {
	return $of($alloc(GetXSpace$Deny));
}

void GetXSpace$Deny::init$() {
	$SecurityManager::init$();
}

void GetXSpace$Deny::checkPermission($Permission* p) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(p)->implies($$new($RuntimePermission, "setSecurityManager"_s));
	if (var$0 || $nc(p)->implies($$new($RuntimePermission, "getProtectionDomain"_s))) {
		return;
	}
	$SecurityManager::checkPermission(p);
}

void GetXSpace$Deny::checkPermission($Permission* p, Object$* context) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(p)->implies($$new($RuntimePermission, "setSecurityManager"_s));
	if (var$0 || $nc(p)->implies($$new($RuntimePermission, "getProtectionDomain"_s))) {
		return;
	}
	$SecurityManager::checkPermission(p, context);
}

GetXSpace$Deny::GetXSpace$Deny() {
}

$Class* GetXSpace$Deny::load$($String* name, bool initialize) {
	$loadClass(GetXSpace$Deny, name, initialize, &_GetXSpace$Deny_ClassInfo_, allocate$GetXSpace$Deny);
	return class$;
}

$Class* GetXSpace$Deny::class$ = nullptr;