#include <LookupTest$LookupTestPolicy.h>

#include <LookupTest.h>
#include <java/io/FilePermission.h>
#include <java/net/NetPermission.h>
#include <java/net/SocketPermission.h>
#include <java/net/URLPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/Policy.h>
#include <java/security/ProtectionDomain.h>
#include <jcpp.h>

#undef DEFAULT_POLICY

using $LookupTest = ::LookupTest;
using $FilePermission = ::java::io::FilePermission;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NetPermission = ::java::net::NetPermission;
using $SocketPermission = ::java::net::SocketPermission;
using $URLPermission = ::java::net::URLPermission;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $Policy = ::java::security::Policy;
using $ProtectionDomain = ::java::security::ProtectionDomain;

$FieldInfo _LookupTest$LookupTestPolicy_FieldInfo_[] = {
	{"perms", "Ljava/security/PermissionCollection;", nullptr, $FINAL, $field(LookupTest$LookupTestPolicy, perms)},
	{}
};

$MethodInfo _LookupTest$LookupTestPolicy_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(LookupTest$LookupTestPolicy, init$, void), "java.lang.Exception"},
	{"getPermissions", "(Ljava/security/ProtectionDomain;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(LookupTest$LookupTestPolicy, getPermissions, $PermissionCollection*, $ProtectionDomain*)},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(LookupTest$LookupTestPolicy, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"implies", "(Ljava/security/ProtectionDomain;Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(LookupTest$LookupTestPolicy, implies, bool, $ProtectionDomain*, $Permission*)},
	{}
};

$InnerClassInfo _LookupTest$LookupTestPolicy_InnerClassesInfo_[] = {
	{"LookupTest$LookupTestPolicy", "LookupTest", "LookupTestPolicy", $STATIC},
	{}
};

$ClassInfo _LookupTest$LookupTestPolicy_ClassInfo_ = {
	$ACC_SUPER,
	"LookupTest$LookupTestPolicy",
	"java.security.Policy",
	nullptr,
	_LookupTest$LookupTestPolicy_FieldInfo_,
	_LookupTest$LookupTestPolicy_MethodInfo_,
	nullptr,
	nullptr,
	_LookupTest$LookupTestPolicy_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"LookupTest"
};

$Object* allocate$LookupTest$LookupTestPolicy($Class* clazz) {
	return $of($alloc(LookupTest$LookupTestPolicy));
}

void LookupTest$LookupTestPolicy::init$() {
	$useLocalCurrentObjectStackCache();
	$Policy::init$();
	$set(this, perms, $new($Permissions));
	$nc(this->perms)->add($$new($NetPermission, "setProxySelector"_s));
	$nc(this->perms)->add($$new($SocketPermission, "localhost:1024-"_s, "resolve,accept"_s));
	$init($LookupTest);
	$nc(this->perms)->add($$new($URLPermission, $$str({"http://allowedAndFound.com:"_s, $$str($LookupTest::port), "/-"_s}), "*:*"_s));
	$nc(this->perms)->add($$new($URLPermission, $$str({"http://allowedButNotfound.com:"_s, $$str($LookupTest::port), "/-"_s}), "*:*"_s));
	$nc(this->perms)->add($$new($FilePermission, "<<ALL FILES>>"_s, "read,write,delete"_s));
}

$PermissionCollection* LookupTest$LookupTestPolicy::getPermissions($ProtectionDomain* domain) {
	return this->perms;
}

$PermissionCollection* LookupTest$LookupTestPolicy::getPermissions($CodeSource* codesource) {
	return this->perms;
}

bool LookupTest$LookupTestPolicy::implies($ProtectionDomain* domain, $Permission* perm) {
	bool var$0 = $nc(this->perms)->implies(perm);
	$init($LookupTest);
	return var$0 || $nc($LookupTest::DEFAULT_POLICY)->implies(domain, perm);
}

LookupTest$LookupTestPolicy::LookupTest$LookupTestPolicy() {
}

$Class* LookupTest$LookupTestPolicy::load$($String* name, bool initialize) {
	$loadClass(LookupTest$LookupTestPolicy, name, initialize, &_LookupTest$LookupTestPolicy_ClassInfo_, allocate$LookupTest$LookupTestPolicy);
	return class$;
}

$Class* LookupTest$LookupTestPolicy::class$ = nullptr;