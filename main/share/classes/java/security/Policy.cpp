#include <java/security/Policy.h>

#include <java/lang/SecurityManager.h>
#include <java/security/AccessController.h>
#include <java/security/AllPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/Policy$1.h>
#include <java/security/Policy$2.h>
#include <java/security/Policy$3.h>
#include <java/security/Policy$Parameters.h>
#include <java/security/Policy$PolicyDelegate.h>
#include <java/security/Policy$PolicyInfo.h>
#include <java/security/Policy$UnsupportedEmptyCollection.h>
#include <java/security/PolicySpi.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain$Key.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/Provider.h>
#include <java/security/SecurityPermission.h>
#include <java/util/Enumeration.h>
#include <java/util/Objects.h>
#include <java/util/WeakHashMap.h>
#include <sun/security/jca/GetInstance$Instance.h>
#include <sun/security/jca/GetInstance.h>
#include <sun/security/provider/PolicyFile.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef ALL_PERMISSION
#undef DEFAULT_POLICY
#undef GET_POLICY_PERMISSION
#undef UNSUPPORTED_EMPTY_COLLECTION

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $Policy$1 = ::java::security::Policy$1;
using $Policy$2 = ::java::security::Policy$2;
using $Policy$3 = ::java::security::Policy$3;
using $Policy$Parameters = ::java::security::Policy$Parameters;
using $Policy$PolicyDelegate = ::java::security::Policy$PolicyDelegate;
using $Policy$PolicyInfo = ::java::security::Policy$PolicyInfo;
using $Policy$UnsupportedEmptyCollection = ::java::security::Policy$UnsupportedEmptyCollection;
using $PolicySpi = ::java::security::PolicySpi;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Provider = ::java::security::Provider;
using $SecurityPermission = ::java::security::SecurityPermission;
using $Enumeration = ::java::util::Enumeration;
using $Objects = ::java::util::Objects;
using $WeakHashMap = ::java::util::WeakHashMap;
using $GetInstance = ::sun::security::jca::GetInstance;
using $GetInstance$Instance = ::sun::security::jca::GetInstance$Instance;
using $PolicyFile = ::sun::security::provider::PolicyFile;
using $Debug = ::sun::security::util::Debug;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace security {

$NamedAttribute Policy_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Policy_Annotations_[] = {
	{"Ljava/lang/Deprecated;", Policy_Attribute_var$0},
	{}
};

$FieldInfo _Policy_FieldInfo_[] = {
	{"UNSUPPORTED_EMPTY_COLLECTION", "Ljava/security/PermissionCollection;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Policy, UNSUPPORTED_EMPTY_COLLECTION)},
	{"policyInfo", "Ljava/security/Policy$PolicyInfo;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Policy, policyInfo)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Policy, debug)},
	{"DEFAULT_POLICY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Policy, DEFAULT_POLICY)},
	{"pdMapping", "Ljava/util/WeakHashMap;", "Ljava/util/WeakHashMap<Ljava/security/ProtectionDomain$Key;Ljava/security/PermissionCollection;>;", $PRIVATE, $field(Policy, pdMapping)},
	{}
};

$MethodInfo _Policy_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Policy, init$, void)},
	{"addStaticPerms", "(Ljava/security/PermissionCollection;Ljava/security/PermissionCollection;)V", nullptr, $PRIVATE, $method(Policy, addStaticPerms, void, $PermissionCollection*, $PermissionCollection*)},
	{"checkPermission", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Policy, checkPermission, void, $String*)},
	{"getInstance", "(Ljava/lang/String;Ljava/security/Policy$Parameters;)Ljava/security/Policy;", nullptr, $PUBLIC | $STATIC, $staticMethod(Policy, getInstance, Policy*, $String*, $Policy$Parameters*), "java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/Policy$Parameters;Ljava/lang/String;)Ljava/security/Policy;", nullptr, $PUBLIC | $STATIC, $staticMethod(Policy, getInstance, Policy*, $String*, $Policy$Parameters*, $String*), "java.security.NoSuchProviderException,java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/Policy$Parameters;Ljava/security/Provider;)Ljava/security/Policy;", nullptr, $PUBLIC | $STATIC, $staticMethod(Policy, getInstance, Policy*, $String*, $Policy$Parameters*, $Provider*), "java.security.NoSuchAlgorithmException"},
	{"getParameters", "()Ljava/security/Policy$Parameters;", nullptr, $PUBLIC, $virtualMethod(Policy, getParameters, $Policy$Parameters*)},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(Policy, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"getPermissions", "(Ljava/security/ProtectionDomain;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(Policy, getPermissions, $PermissionCollection*, $ProtectionDomain*)},
	{"getPolicy", "()Ljava/security/Policy;", nullptr, $PUBLIC | $STATIC, $staticMethod(Policy, getPolicy, Policy*)},
	{"getPolicyNoCheck", "()Ljava/security/Policy;", nullptr, $STATIC, $staticMethod(Policy, getPolicyNoCheck, Policy*)},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC, $virtualMethod(Policy, getProvider, $Provider*)},
	{"getType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Policy, getType, $String*)},
	{"handleException", "(Ljava/security/NoSuchAlgorithmException;)Ljava/security/Policy;", nullptr, $PRIVATE | $STATIC, $staticMethod(Policy, handleException, Policy*, $NoSuchAlgorithmException*), "java.security.NoSuchAlgorithmException"},
	{"implies", "(Ljava/security/ProtectionDomain;Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(Policy, implies, bool, $ProtectionDomain*, $Permission*)},
	{"initPolicy", "(Ljava/security/Policy;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Policy, initPolicy, void, Policy*)},
	{"isSet", "()Z", nullptr, $STATIC, $staticMethod(Policy, isSet, bool)},
	{"loadPolicyProvider", "()Ljava/security/Policy;", nullptr, $PRIVATE | $STATIC, $staticMethod(Policy, loadPolicyProvider, Policy*)},
	{"refresh", "()V", nullptr, $PUBLIC, $virtualMethod(Policy, refresh, void)},
	{"setPolicy", "(Ljava/security/Policy;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Policy, setPolicy, void, Policy*)},
	{}
};

$InnerClassInfo _Policy_InnerClassesInfo_[] = {
	{"java.security.Policy$UnsupportedEmptyCollection", "java.security.Policy", "UnsupportedEmptyCollection", $PRIVATE | $STATIC},
	{"java.security.Policy$Parameters", "java.security.Policy", "Parameters", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.security.Policy$PolicyDelegate", "java.security.Policy", "PolicyDelegate", $PRIVATE | $STATIC},
	{"java.security.Policy$PolicyInfo", "java.security.Policy", "PolicyInfo", $PRIVATE | $STATIC},
	{"java.security.Policy$3", nullptr, nullptr, 0},
	{"java.security.Policy$2", nullptr, nullptr, 0},
	{"java.security.Policy$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Policy_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.Policy",
	"java.lang.Object",
	nullptr,
	_Policy_FieldInfo_,
	_Policy_MethodInfo_,
	nullptr,
	nullptr,
	_Policy_InnerClassesInfo_,
	_Policy_Annotations_,
	nullptr,
	"java.security.Policy$UnsupportedEmptyCollection,java.security.Policy$Parameters,java.security.Policy$PolicyDelegate,java.security.Policy$PolicyInfo,java.security.Policy$3,java.security.Policy$2,java.security.Policy$1"
};

$Object* allocate$Policy($Class* clazz) {
	return $of($alloc(Policy));
}

$PermissionCollection* Policy::UNSUPPORTED_EMPTY_COLLECTION = nullptr;
$volatile($Policy$PolicyInfo*) Policy::policyInfo = nullptr;
$Debug* Policy::debug = nullptr;
$String* Policy::DEFAULT_POLICY = nullptr;

void Policy::init$() {
}

bool Policy::isSet() {
	$init(Policy);
	$var($Policy$PolicyInfo, pi, Policy::policyInfo);
	return $nc(pi)->policy != nullptr && pi->initialized == true;
}

void Policy::checkPermission($String* type) {
	$init(Policy);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($SecurityPermission, $$str({"createPolicy."_s, type})));
	}
}

Policy* Policy::getPolicy() {
	$init(Policy);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_POLICY_PERMISSION);
	}
	return getPolicyNoCheck();
}

Policy* Policy::getPolicyNoCheck() {
	$init(Policy);
	$var($Policy$PolicyInfo, pi, Policy::policyInfo);
	if ($nc(pi)->initialized == false || $nc(pi)->policy == nullptr) {
		$synchronized(Policy::class$) {
			$assign(pi, Policy::policyInfo);
			if ($nc(pi)->policy == nullptr) {
				return loadPolicyProvider();
			}
		}
	}
	return $nc(pi)->policy;
}

Policy* Policy::loadPolicyProvider() {
	$init(Policy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, policyProvider, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Policy$1)))));
	bool var$0 = policyProvider == nullptr || $nc(policyProvider)->isEmpty();
	if (var$0 || $nc(policyProvider)->equals(Policy::DEFAULT_POLICY)) {
		$var(Policy, polFile, $new($PolicyFile));
		$assignStatic(Policy::policyInfo, $new($Policy$PolicyInfo, polFile, true));
		return polFile;
	}
	$var(Policy, polFile, $new($PolicyFile));
	$assignStatic(Policy::policyInfo, $new($Policy$PolicyInfo, polFile, false));
	$var(Policy, pol, $cast(Policy, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Policy$2, policyProvider)))));
	if (pol == nullptr) {
		if (Policy::debug != nullptr) {
			$nc(Policy::debug)->println($$str({"using "_s, Policy::DEFAULT_POLICY}));
		}
		$assign(pol, polFile);
	}
	$assignStatic(Policy::policyInfo, $new($Policy$PolicyInfo, pol, true));
	return pol;
}

void Policy::setPolicy(Policy* p) {
	$init(Policy);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($SecurityPermission, "setPolicy"_s));
	}
	if (p != nullptr) {
		initPolicy(p);
	}
	$synchronized(Policy::class$) {
		$assignStatic(Policy::policyInfo, $new($Policy$PolicyInfo, p, p != nullptr));
	}
}

void Policy::initPolicy(Policy* p) {
	$init(Policy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ProtectionDomain, policyDomain, $cast($ProtectionDomain, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Policy$3, p)))));
	$var($PermissionCollection, policyPerms, nullptr);
	$synchronized(p) {
		if ($nc(p)->pdMapping == nullptr) {
			$set(p, pdMapping, $new($WeakHashMap));
		}
	}
	if ($nc(policyDomain)->getCodeSource() != nullptr) {
		$var(Policy, pol, $nc(Policy::policyInfo)->policy);
		if (pol != nullptr) {
			$assign(policyPerms, pol->getPermissions(policyDomain));
		}
		if (policyPerms == nullptr) {
			$assign(policyPerms, $new($Permissions));
			$init($SecurityConstants);
			policyPerms->add($SecurityConstants::ALL_PERMISSION);
		}
		$synchronized($nc(p)->pdMapping) {
			$nc(p->pdMapping)->put(policyDomain->key, policyPerms);
		}
	}
	return;
}

Policy* Policy::getInstance($String* type, $Policy$Parameters* params) {
	$init(Policy);
	$Objects::requireNonNull($of(type), "null type name"_s);
	checkPermission(type);
	try {
		$load($PolicySpi);
		$var($GetInstance$Instance, instance, $GetInstance::getInstance("Policy"_s, $PolicySpi::class$, type, $of(params)));
		return $new($Policy$PolicyDelegate, $cast($PolicySpi, $nc(instance)->impl), instance->provider, type, params);
	} catch ($NoSuchAlgorithmException& nsae) {
		return handleException(nsae);
	}
	$shouldNotReachHere();
}

Policy* Policy::getInstance($String* type, $Policy$Parameters* params, $String* provider) {
	$init(Policy);
	$Objects::requireNonNull($of(type), "null type name"_s);
	if (provider == nullptr || $nc(provider)->isEmpty()) {
		$throwNew($IllegalArgumentException, "missing provider"_s);
	}
	checkPermission(type);
	try {
		$load($PolicySpi);
		$var($GetInstance$Instance, instance, $GetInstance::getInstance("Policy"_s, $PolicySpi::class$, type, $of(params), provider));
		return $new($Policy$PolicyDelegate, $cast($PolicySpi, $nc(instance)->impl), instance->provider, type, params);
	} catch ($NoSuchAlgorithmException& nsae) {
		return handleException(nsae);
	}
	$shouldNotReachHere();
}

Policy* Policy::getInstance($String* type, $Policy$Parameters* params, $Provider* provider) {
	$init(Policy);
	$Objects::requireNonNull($of(type), "null type name"_s);
	if (provider == nullptr) {
		$throwNew($IllegalArgumentException, "missing provider"_s);
	}
	checkPermission(type);
	try {
		$load($PolicySpi);
		$var($GetInstance$Instance, instance, $GetInstance::getInstance("Policy"_s, $PolicySpi::class$, type, $of(params), provider));
		return $new($Policy$PolicyDelegate, $cast($PolicySpi, $nc(instance)->impl), instance->provider, type, params);
	} catch ($NoSuchAlgorithmException& nsae) {
		return handleException(nsae);
	}
	$shouldNotReachHere();
}

Policy* Policy::handleException($NoSuchAlgorithmException* nsae) {
	$init(Policy);
	$var($Throwable, cause, $nc(nsae)->getCause());
	if ($instanceOf($IllegalArgumentException, cause)) {
		$throw($cast($IllegalArgumentException, cause));
	}
	$throw(nsae);
	$shouldNotReachHere();
}

$Provider* Policy::getProvider() {
	return nullptr;
}

$String* Policy::getType() {
	return nullptr;
}

$Policy$Parameters* Policy::getParameters() {
	return nullptr;
}

$PermissionCollection* Policy::getPermissions($CodeSource* codesource) {
	return Policy::UNSUPPORTED_EMPTY_COLLECTION;
}

$PermissionCollection* Policy::getPermissions($ProtectionDomain* domain) {
	$useLocalCurrentObjectStackCache();
	$var($PermissionCollection, pc, nullptr);
	if (domain == nullptr) {
		return $new($Permissions);
	}
	if (this->pdMapping == nullptr) {
		initPolicy(this);
	}
	$synchronized(this->pdMapping) {
		$assign(pc, $cast($PermissionCollection, $nc(this->pdMapping)->get($nc(domain)->key)));
	}
	if (pc != nullptr) {
		$var($Permissions, perms, $new($Permissions));
		$synchronized(pc) {
			{
				$var($Enumeration, e, pc->elements());
				for (; $nc(e)->hasMoreElements();) {
					perms->add($cast($Permission, $(e->nextElement())));
				}
			}
		}
		return perms;
	}
	$assign(pc, getPermissions($($nc(domain)->getCodeSource())));
	if (pc == nullptr || pc == Policy::UNSUPPORTED_EMPTY_COLLECTION) {
		$assign(pc, $new($Permissions));
	}
	addStaticPerms(pc, $($nc(domain)->getPermissions()));
	return pc;
}

void Policy::addStaticPerms($PermissionCollection* perms, $PermissionCollection* statics) {
	$useLocalCurrentObjectStackCache();
	if (statics != nullptr) {
		$synchronized(statics) {
			$var($Enumeration, e, statics->elements());
			while ($nc(e)->hasMoreElements()) {
				$nc(perms)->add($cast($Permission, $(e->nextElement())));
			}
		}
	}
}

bool Policy::implies($ProtectionDomain* domain, $Permission* permission) {
	$var($PermissionCollection, pc, nullptr);
	if (this->pdMapping == nullptr) {
		initPolicy(this);
	}
	$synchronized(this->pdMapping) {
		$assign(pc, $cast($PermissionCollection, $nc(this->pdMapping)->get($nc(domain)->key)));
	}
	if (pc != nullptr) {
		return pc->implies(permission);
	}
	$assign(pc, getPermissions(domain));
	if (pc == nullptr) {
		return false;
	}
	$synchronized(this->pdMapping) {
		$nc(this->pdMapping)->put($nc(domain)->key, pc);
	}
	return $nc(pc)->implies(permission);
}

void Policy::refresh() {
}

void clinit$Policy($Class* class$) {
	$assignStatic(Policy::DEFAULT_POLICY, "sun.security.provider.PolicyFile"_s);
	$assignStatic(Policy::UNSUPPORTED_EMPTY_COLLECTION, $new($Policy$UnsupportedEmptyCollection));
	$assignStatic(Policy::policyInfo, $new($Policy$PolicyInfo, nullptr, false));
	$assignStatic(Policy::debug, $Debug::getInstance("policy"_s));
}

Policy::Policy() {
}

$Class* Policy::load$($String* name, bool initialize) {
	$loadClass(Policy, name, initialize, &_Policy_ClassInfo_, clinit$Policy, allocate$Policy);
	return class$;
}

$Class* Policy::class$ = nullptr;

	} // security
} // java