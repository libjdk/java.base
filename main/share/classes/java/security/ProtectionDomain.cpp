#include <java/security/ProtectionDomain.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/Policy.h>
#include <java/security/Principal.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain$1.h>
#include <java/security/ProtectionDomain$DebugHolder.h>
#include <java/security/ProtectionDomain$JavaSecurityAccessImpl.h>
#include <java/security/ProtectionDomain$Key.h>
#include <java/security/SecurityPermission.h>
#include <java/util/ArrayList.h>
#include <java/util/Enumeration.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jdk/internal/access/JavaSecurityAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/provider/PolicyFile.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/FilePermCompat.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef GET_POLICY_PERMISSION

using $PrincipalArray = $Array<::java::security::Principal>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $Policy = ::java::security::Policy;
using $Principal = ::java::security::Principal;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain$1 = ::java::security::ProtectionDomain$1;
using $ProtectionDomain$DebugHolder = ::java::security::ProtectionDomain$DebugHolder;
using $ProtectionDomain$JavaSecurityAccessImpl = ::java::security::ProtectionDomain$JavaSecurityAccessImpl;
using $ProtectionDomain$Key = ::java::security::ProtectionDomain$Key;
using $ArrayList = ::java::util::ArrayList;
using $Enumeration = ::java::util::Enumeration;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $JavaSecurityAccess = ::jdk::internal::access::JavaSecurityAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $PolicyFile = ::sun::security::provider::PolicyFile;
using $FilePermCompat = ::sun::security::util::FilePermCompat;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace security {

$FieldInfo _ProtectionDomain_FieldInfo_[] = {
	{"filePermCompatInPD", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProtectionDomain, filePermCompatInPD)},
	{"codesource", "Ljava/security/CodeSource;", nullptr, $PRIVATE, $field(ProtectionDomain, codesource)},
	{"classloader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(ProtectionDomain, classloader)},
	{"principals", "[Ljava/security/Principal;", nullptr, $PRIVATE, $field(ProtectionDomain, principals)},
	{"permissions", "Ljava/security/PermissionCollection;", nullptr, $PRIVATE, $field(ProtectionDomain, permissions)},
	{"hasAllPerm", "Z", nullptr, $PRIVATE, $field(ProtectionDomain, hasAllPerm)},
	{"staticPermissions", "Z", nullptr, $PRIVATE | $FINAL, $field(ProtectionDomain, staticPermissions)},
	{"key", "Ljava/security/ProtectionDomain$Key;", nullptr, $FINAL, $field(ProtectionDomain, key)},
	{}
};

$MethodInfo _ProtectionDomain_MethodInfo_[] = {
	{"<init>", "(Ljava/security/CodeSource;Ljava/security/PermissionCollection;)V", nullptr, $PUBLIC, $method(ProtectionDomain, init$, void, $CodeSource*, $PermissionCollection*)},
	{"<init>", "(Ljava/security/CodeSource;Ljava/security/PermissionCollection;Ljava/lang/ClassLoader;[Ljava/security/Principal;)V", nullptr, $PUBLIC, $method(ProtectionDomain, init$, void, $CodeSource*, $PermissionCollection*, $ClassLoader*, $PrincipalArray*)},
	{"getClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $FINAL, $method(ProtectionDomain, getClassLoader, $ClassLoader*)},
	{"getCodeSource", "()Ljava/security/CodeSource;", nullptr, $PUBLIC | $FINAL, $method(ProtectionDomain, getCodeSource, $CodeSource*)},
	{"getPermissions", "()Ljava/security/PermissionCollection;", nullptr, $PUBLIC | $FINAL, $method(ProtectionDomain, getPermissions, $PermissionCollection*)},
	{"getPrincipals", "()[Ljava/security/Principal;", nullptr, $PUBLIC | $FINAL, $method(ProtectionDomain, getPrincipals, $PrincipalArray*)},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(ProtectionDomain, implies, bool, $Permission*)},
	{"impliesWithAltFilePerm", "(Ljava/security/Permission;)Z", nullptr, 0, $virtualMethod(ProtectionDomain, impliesWithAltFilePerm, bool, $Permission*)},
	{"mergePermissions", "()Ljava/security/PermissionCollection;", nullptr, $PRIVATE, $method(ProtectionDomain, mergePermissions, $PermissionCollection*)},
	{"seeAllp", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ProtectionDomain, seeAllp, bool)},
	{"staticPermissionsOnly", "()Z", nullptr, $PUBLIC | $FINAL, $method(ProtectionDomain, staticPermissionsOnly, bool)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProtectionDomain, toString, $String*)},
	{}
};

$InnerClassInfo _ProtectionDomain_InnerClassesInfo_[] = {
	{"java.security.ProtectionDomain$Key", "java.security.ProtectionDomain", "Key", $STATIC | $FINAL},
	{"java.security.ProtectionDomain$DebugHolder", "java.security.ProtectionDomain", "DebugHolder", $PRIVATE | $STATIC},
	{"java.security.ProtectionDomain$JavaSecurityAccessImpl", "java.security.ProtectionDomain", "JavaSecurityAccessImpl", $PRIVATE | $STATIC},
	{"java.security.ProtectionDomain$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProtectionDomain_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.ProtectionDomain",
	"java.lang.Object",
	nullptr,
	_ProtectionDomain_FieldInfo_,
	_ProtectionDomain_MethodInfo_,
	nullptr,
	nullptr,
	_ProtectionDomain_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.ProtectionDomain$Key,java.security.ProtectionDomain$DebugHolder,java.security.ProtectionDomain$JavaSecurityAccessImpl,java.security.ProtectionDomain$JavaSecurityAccessImpl$1,java.security.ProtectionDomain$1"
};

$Object* allocate$ProtectionDomain($Class* clazz) {
	return $of($alloc(ProtectionDomain));
}

bool ProtectionDomain::filePermCompatInPD = false;

void ProtectionDomain::init$($CodeSource* codesource, $PermissionCollection* permissions) {
	this->hasAllPerm = false;
	$set(this, key, $new($ProtectionDomain$Key));
	$set(this, codesource, codesource);
	if (permissions != nullptr) {
		$set(this, permissions, permissions);
		$nc(this->permissions)->setReadOnly();
		if ($instanceOf($Permissions, permissions) && $nc(($cast($Permissions, permissions)))->allPermission != nullptr) {
			this->hasAllPerm = true;
		}
	}
	$set(this, classloader, nullptr);
	$set(this, principals, $new($PrincipalArray, 0));
	this->staticPermissions = true;
}

void ProtectionDomain::init$($CodeSource* codesource, $PermissionCollection* permissions, $ClassLoader* classloader, $PrincipalArray* principals) {
	this->hasAllPerm = false;
	$set(this, key, $new($ProtectionDomain$Key));
	$set(this, codesource, codesource);
	if (permissions != nullptr) {
		$set(this, permissions, permissions);
		$nc(this->permissions)->setReadOnly();
		if ($instanceOf($Permissions, permissions) && $nc(($cast($Permissions, permissions)))->allPermission != nullptr) {
			this->hasAllPerm = true;
		}
	}
	$set(this, classloader, classloader);
	$set(this, principals, principals != nullptr ? $cast($PrincipalArray, $nc(principals)->clone()) : $new($PrincipalArray, 0));
	this->staticPermissions = false;
}

$CodeSource* ProtectionDomain::getCodeSource() {
	return this->codesource;
}

$ClassLoader* ProtectionDomain::getClassLoader() {
	return this->classloader;
}

$PrincipalArray* ProtectionDomain::getPrincipals() {
	return $cast($PrincipalArray, $nc(this->principals)->clone());
}

$PermissionCollection* ProtectionDomain::getPermissions() {
	return this->permissions;
}

bool ProtectionDomain::staticPermissionsOnly() {
	return this->staticPermissions;
}

bool ProtectionDomain::implies($Permission* perm) {
	if (this->hasAllPerm) {
		return true;
	}
	if (!this->staticPermissions && $nc($($Policy::getPolicyNoCheck()))->implies(this, perm)) {
		return true;
	}
	if (this->permissions != nullptr) {
		return $nc(this->permissions)->implies(perm);
	}
	return false;
}

bool ProtectionDomain::impliesWithAltFilePerm($Permission* perm) {
	$useLocalCurrentObjectStackCache();
	$init($FilePermCompat);
	if (!ProtectionDomain::filePermCompatInPD || !$FilePermCompat::compat || $of(this)->getClass() != ProtectionDomain::class$) {
		return implies(perm);
	}
	if (this->hasAllPerm) {
		return true;
	}
	$var($Permission, p2, nullptr);
	bool p2Calculated = false;
	if (!this->staticPermissions) {
		$var($Policy, policy, $Policy::getPolicyNoCheck());
		if ($instanceOf($PolicyFile, policy)) {
			return $nc(policy)->implies(this, perm);
		} else {
			if ($nc(policy)->implies(this, perm)) {
				return true;
			}
			$assign(p2, $FilePermCompat::newPermUsingAltPath(perm));
			p2Calculated = true;
			if (p2 != nullptr && $nc(policy)->implies(this, p2)) {
				return true;
			}
		}
	}
	if (this->permissions != nullptr) {
		if ($nc(this->permissions)->implies(perm)) {
			return true;
		} else {
			if (!p2Calculated) {
				$assign(p2, $FilePermCompat::newPermUsingAltPath(perm));
			}
			if (p2 != nullptr) {
				return $nc(this->permissions)->implies(p2);
			}
		}
	}
	return false;
}

$String* ProtectionDomain::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, pals, "<no principals>"_s);
	if (this->principals != nullptr && $nc(this->principals)->length > 0) {
		$var($StringBuilder, palBuf, $new($StringBuilder, "(principals "_s));
		for (int32_t i = 0; i < $nc(this->principals)->length; ++i) {
			$var($String, var$1, $$str({$($nc($of($nc(this->principals)->get(i)))->getClass()->getName()), " \""_s}));
			$var($String, var$0, $$concat(var$1, $($nc($nc(this->principals)->get(i))->getName())));
			palBuf->append($$concat(var$0, "\""_s));
			if (i < $nc(this->principals)->length - 1) {
				palBuf->append(",\n"_s);
			} else {
				palBuf->append(")\n"_s);
			}
		}
		$assign(pals, palBuf->toString());
	}
	bool var$2 = $Policy::isSet();
	$var($PermissionCollection, pc, var$2 && seeAllp() ? mergePermissions() : getPermissions());
	return $str({"ProtectionDomain  "_s, this->codesource, "\n "_s, this->classloader, "\n "_s, pals, "\n "_s, pc, "\n"_s});
}

bool ProtectionDomain::seeAllp() {
	$init(ProtectionDomain);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return true;
	} else {
		$init($ProtectionDomain$DebugHolder);
		if ($ProtectionDomain$DebugHolder::debug != nullptr) {
			bool var$0 = $nc($of(sm))->getClass()->getClassLoader() == nullptr;
			if (var$0 && $nc($of($($Policy::getPolicyNoCheck())))->getClass()->getClassLoader() == nullptr) {
				return true;
			}
		} else {
			try {
				$init($SecurityConstants);
				$nc(sm)->checkPermission($SecurityConstants::GET_POLICY_PERMISSION);
				return true;
			} catch ($SecurityException& se) {
			}
		}
	}
	return false;
}

$PermissionCollection* ProtectionDomain::mergePermissions() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->staticPermissions) {
		return this->permissions;
	}
	$var($PermissionCollection, perms, $cast($PermissionCollection, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ProtectionDomain$1, this)))));
	$var($Permissions, mergedPerms, $new($Permissions));
	int32_t swag = 32;
	int32_t vcap = 8;
	$var($Enumeration, e, nullptr);
	$var($List, pdVector, $new($ArrayList, vcap));
	$var($List, plVector, $new($ArrayList, swag));
	if (this->permissions != nullptr) {
		$synchronized(this->permissions) {
			$assign(e, $nc(this->permissions)->elements());
			while ($nc(e)->hasMoreElements()) {
				pdVector->add($cast($Permission, $(e->nextElement())));
			}
		}
	}
	if (perms != nullptr) {
		$synchronized(perms) {
			$assign(e, perms->elements());
			while ($nc(e)->hasMoreElements()) {
				plVector->add($cast($Permission, $(e->nextElement())));
				++vcap;
			}
		}
	}
	if (perms != nullptr && this->permissions != nullptr) {
		$synchronized(this->permissions) {
			$assign(e, $nc(this->permissions)->elements());
			while ($nc(e)->hasMoreElements()) {
				$var($Permission, pdp, $cast($Permission, e->nextElement()));
				$Class* pdpClass = $nc($of(pdp))->getClass();
				$var($String, pdpActions, pdp->getActions());
				$var($String, pdpName, pdp->getName());
				for (int32_t i = 0; i < plVector->size(); ++i) {
					$var($Permission, pp, $cast($Permission, plVector->get(i)));
					if ($nc(pdpClass)->isInstance(pp)) {
						bool var$0 = $nc(pdpName)->equals($($nc(pp)->getName()));
						if (var$0 && $Objects::equals(pdpActions, $($nc(pp)->getActions()))) {
							plVector->remove(i);
							break;
						}
					}
				}
			}
		}
	}
	if (perms != nullptr) {
		for (int32_t i = plVector->size() - 1; i >= 0; --i) {
			mergedPerms->add($cast($Permission, $(plVector->get(i))));
		}
	}
	if (this->permissions != nullptr) {
		for (int32_t i = pdVector->size() - 1; i >= 0; --i) {
			mergedPerms->add($cast($Permission, $(pdVector->get(i))));
		}
	}
	return mergedPerms;
}

void clinit$ProtectionDomain($Class* class$) {
	$useLocalCurrentObjectStackCache();
	ProtectionDomain::filePermCompatInPD = "true"_s->equals($($GetPropertyAction::privilegedGetProperty("jdk.security.filePermCompat"_s)));
	{
		$SharedSecrets::setJavaSecurityAccess($$new($ProtectionDomain$JavaSecurityAccessImpl));
	}
}

ProtectionDomain::ProtectionDomain() {
}

$Class* ProtectionDomain::load$($String* name, bool initialize) {
	$loadClass(ProtectionDomain, name, initialize, &_ProtectionDomain_ClassInfo_, clinit$ProtectionDomain, allocate$ProtectionDomain);
	return class$;
}

$Class* ProtectionDomain::class$ = nullptr;

	} // security
} // java