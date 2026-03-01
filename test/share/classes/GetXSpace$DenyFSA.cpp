#include <GetXSpace$DenyFSA.h>

#include <GetXSpace$Deny.h>
#include <GetXSpace.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/security/Permission.h>
#include <jcpp.h>

using $GetXSpace$Deny = ::GetXSpace$Deny;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $Permission = ::java::security::Permission;

$FieldInfo _GetXSpace$DenyFSA_FieldInfo_[] = {
	{"err", "Ljava/lang/String;", nullptr, $PRIVATE, $field(GetXSpace$DenyFSA, err)},
	{}
};

$MethodInfo _GetXSpace$DenyFSA_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(GetXSpace$DenyFSA, init$, void)},
	{"checkPermission", "(Ljava/security/Permission;)V", nullptr, $PUBLIC, $virtualMethod(GetXSpace$DenyFSA, checkPermission, void, $Permission*)},
	{"checkPermission", "(Ljava/security/Permission;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(GetXSpace$DenyFSA, checkPermission, void, $Permission*, Object$*)},
	{}
};

$InnerClassInfo _GetXSpace$DenyFSA_InnerClassesInfo_[] = {
	{"GetXSpace$DenyFSA", "GetXSpace", "DenyFSA", $PRIVATE | $STATIC},
	{"GetXSpace$Deny", "GetXSpace", "Deny", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _GetXSpace$DenyFSA_ClassInfo_ = {
	$ACC_SUPER,
	"GetXSpace$DenyFSA",
	"GetXSpace$Deny",
	nullptr,
	_GetXSpace$DenyFSA_FieldInfo_,
	_GetXSpace$DenyFSA_MethodInfo_,
	nullptr,
	nullptr,
	_GetXSpace$DenyFSA_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"GetXSpace"
};

$Object* allocate$GetXSpace$DenyFSA($Class* clazz) {
	return $of($alloc(GetXSpace$DenyFSA));
}

void GetXSpace$DenyFSA::init$() {
	$GetXSpace$Deny::init$();
	$set(this, err, "sorry - getFileSystemAttributes"_s);
}

void GetXSpace$DenyFSA::checkPermission($Permission* p) {
	if ($nc(p)->implies($$new($RuntimePermission, "getFileSystemAttributes"_s))) {
		$throwNew($SecurityException, this->err);
	}
	$GetXSpace$Deny::checkPermission(p);
}

void GetXSpace$DenyFSA::checkPermission($Permission* p, Object$* context) {
	if ($nc(p)->implies($$new($RuntimePermission, "getFileSystemAttributes"_s))) {
		$throwNew($SecurityException, this->err);
	}
	$GetXSpace$Deny::checkPermission(p, context);
}

GetXSpace$DenyFSA::GetXSpace$DenyFSA() {
}

$Class* GetXSpace$DenyFSA::load$($String* name, bool initialize) {
	$loadClass(GetXSpace$DenyFSA, name, initialize, &_GetXSpace$DenyFSA_ClassInfo_, allocate$GetXSpace$DenyFSA);
	return class$;
}

$Class* GetXSpace$DenyFSA::class$ = nullptr;