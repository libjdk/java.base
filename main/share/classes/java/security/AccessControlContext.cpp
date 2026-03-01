#include <java/security/AccessControlContext.h>

#include <java/lang/SecurityManager.h>
#include <java/net/URL.h>
#include <java/security/AccessControlContext$1.h>
#include <java/security/AccessControlException.h>
#include <java/security/AccessController.h>
#include <java/security/AllPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/DomainCombiner.h>
#include <java/security/Permission.h>
#include <java/security/Policy.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/SecurityPermission.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/FilePermCompat.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef CREATE_ACC_PERMISSION
#undef GET_COMBINER_PERMISSION

using $PermissionArray = $Array<::java::security::Permission>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $URL = ::java::net::URL;
using $AccessControlContext$1 = ::java::security::AccessControlContext$1;
using $AccessControlException = ::java::security::AccessControlException;
using $AccessController = ::java::security::AccessController;
using $AllPermission = ::java::security::AllPermission;
using $CodeSource = ::java::security::CodeSource;
using $DomainCombiner = ::java::security::DomainCombiner;
using $Permission = ::java::security::Permission;
using $Policy = ::java::security::Policy;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Debug = ::sun::security::util::Debug;
using $FilePermCompat = ::sun::security::util::FilePermCompat;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace security {

$NamedAttribute AccessControlContext_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _AccessControlContext_Annotations_[] = {
	{"Ljava/lang/Deprecated;", AccessControlContext_Attribute_var$0},
	{}
};

$FieldInfo _AccessControlContext_FieldInfo_[] = {
	{"context", "[Ljava/security/ProtectionDomain;", nullptr, $PRIVATE, $field(AccessControlContext, context)},
	{"isPrivileged", "Z", nullptr, $PRIVATE, $field(AccessControlContext, isPrivileged$)},
	{"isAuthorized", "Z", nullptr, $PRIVATE, $field(AccessControlContext, isAuthorized$)},
	{"privilegedContext", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE, $field(AccessControlContext, privilegedContext)},
	{"combiner", "Ljava/security/DomainCombiner;", nullptr, $PRIVATE, $field(AccessControlContext, combiner)},
	{"permissions", "[Ljava/security/Permission;", nullptr, $PRIVATE, $field(AccessControlContext, permissions)},
	{"parent", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE, $field(AccessControlContext, parent)},
	{"isWrapped", "Z", nullptr, $PRIVATE, $field(AccessControlContext, isWrapped)},
	{"isLimited", "Z", nullptr, $PRIVATE, $field(AccessControlContext, isLimited)},
	{"limitedContext", "[Ljava/security/ProtectionDomain;", nullptr, $PRIVATE, $field(AccessControlContext, limitedContext)},
	{"debugInit", "Z", nullptr, $PRIVATE | $STATIC, $staticField(AccessControlContext, debugInit)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC, $staticField(AccessControlContext, debug)},
	{}
};

$MethodInfo _AccessControlContext_MethodInfo_[] = {
	{"<init>", "([Ljava/security/ProtectionDomain;)V", nullptr, $PUBLIC, $method(AccessControlContext, init$, void, $ProtectionDomainArray*)},
	{"<init>", "(Ljava/security/AccessControlContext;Ljava/security/DomainCombiner;)V", nullptr, $PUBLIC, $method(AccessControlContext, init$, void, AccessControlContext*, $DomainCombiner*)},
	{"<init>", "(Ljava/security/AccessControlContext;Ljava/security/DomainCombiner;Z)V", nullptr, 0, $method(AccessControlContext, init$, void, AccessControlContext*, $DomainCombiner*, bool)},
	{"<init>", "(Ljava/security/ProtectionDomain;Ljava/security/DomainCombiner;Ljava/security/AccessControlContext;Ljava/security/AccessControlContext;[Ljava/security/Permission;)V", nullptr, 0, $method(AccessControlContext, init$, void, $ProtectionDomain*, $DomainCombiner*, AccessControlContext*, AccessControlContext*, $PermissionArray*)},
	{"<init>", "([Ljava/security/ProtectionDomain;Z)V", nullptr, 0, $method(AccessControlContext, init$, void, $ProtectionDomainArray*, bool)},
	{"<init>", "([Ljava/security/ProtectionDomain;Ljava/security/AccessControlContext;)V", nullptr, 0, $method(AccessControlContext, init$, void, $ProtectionDomainArray*, AccessControlContext*)},
	{"calculateFields", "(Ljava/security/AccessControlContext;Ljava/security/AccessControlContext;[Ljava/security/Permission;)V", nullptr, $PRIVATE, $method(AccessControlContext, calculateFields, void, AccessControlContext*, AccessControlContext*, $PermissionArray*)},
	{"checkPermission", "(Ljava/security/Permission;)V", nullptr, $PUBLIC, $method(AccessControlContext, checkPermission, void, $Permission*), "java.security.AccessControlException"},
	{"checkPermission2", "(Ljava/security/Permission;)V", nullptr, $PRIVATE, $method(AccessControlContext, checkPermission2, void, $Permission*)},
	{"combine", "([Ljava/security/ProtectionDomain;[Ljava/security/ProtectionDomain;)[Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $STATIC, $staticMethod(AccessControlContext, combine, $ProtectionDomainArray*, $ProtectionDomainArray*, $ProtectionDomainArray*)},
	{"containsAllLimits", "(Ljava/security/AccessControlContext;)Z", nullptr, $PRIVATE, $method(AccessControlContext, containsAllLimits, bool, AccessControlContext*)},
	{"containsAllPDs", "([Ljava/security/ProtectionDomain;[Ljava/security/ProtectionDomain;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AccessControlContext, containsAllPDs, bool, $ProtectionDomainArray*, $ProtectionDomainArray*)},
	{"equalContext", "(Ljava/security/AccessControlContext;)Z", nullptr, $PRIVATE, $method(AccessControlContext, equalContext, bool, AccessControlContext*)},
	{"equalLimitedContext", "(Ljava/security/AccessControlContext;)Z", nullptr, $PRIVATE, $method(AccessControlContext, equalLimitedContext, bool, AccessControlContext*)},
	{"equalPDs", "([Ljava/security/ProtectionDomain;[Ljava/security/ProtectionDomain;)Z", nullptr, $PRIVATE, $method(AccessControlContext, equalPDs, bool, $ProtectionDomainArray*, $ProtectionDomainArray*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AccessControlContext, equals, bool, Object$*)},
	{"getAssignedCombiner", "()Ljava/security/DomainCombiner;", nullptr, 0, $method(AccessControlContext, getAssignedCombiner, $DomainCombiner*)},
	{"getCombiner", "()Ljava/security/DomainCombiner;", nullptr, 0, $method(AccessControlContext, getCombiner, $DomainCombiner*)},
	{"getContext", "()[Ljava/security/ProtectionDomain;", nullptr, 0, $method(AccessControlContext, getContext, $ProtectionDomainArray*)},
	{"getDebug", "()Lsun/security/util/Debug;", nullptr, $STATIC, $staticMethod(AccessControlContext, getDebug, $Debug*)},
	{"getDomainCombiner", "()Ljava/security/DomainCombiner;", nullptr, $PUBLIC, $method(AccessControlContext, getDomainCombiner, $DomainCombiner*)},
	{"getNextPC", "(Ljava/security/AccessControlContext;)Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC, $staticMethod(AccessControlContext, getNextPC, AccessControlContext*, AccessControlContext*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AccessControlContext, hashCode, int32_t)},
	{"isAuthorized", "()Z", nullptr, 0, $method(AccessControlContext, isAuthorized, bool)},
	{"isPrivileged", "()Z", nullptr, 0, $method(AccessControlContext, isPrivileged, bool)},
	{"optimize", "()Ljava/security/AccessControlContext;", nullptr, 0, $method(AccessControlContext, optimize, AccessControlContext*)},
	{}
};

$InnerClassInfo _AccessControlContext_InnerClassesInfo_[] = {
	{"java.security.AccessControlContext$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AccessControlContext_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.AccessControlContext",
	"java.lang.Object",
	nullptr,
	_AccessControlContext_FieldInfo_,
	_AccessControlContext_MethodInfo_,
	nullptr,
	nullptr,
	_AccessControlContext_InnerClassesInfo_,
	_AccessControlContext_Annotations_,
	nullptr,
	"java.security.AccessControlContext$1"
};

$Object* allocate$AccessControlContext($Class* clazz) {
	return $of($alloc(AccessControlContext));
}

bool AccessControlContext::debugInit = false;
$Debug* AccessControlContext::debug = nullptr;

$Debug* AccessControlContext::getDebug() {
	$init(AccessControlContext);
	if (AccessControlContext::debugInit) {
		return AccessControlContext::debug;
	} else {
		if ($Policy::isSet()) {
			$assignStatic(AccessControlContext::debug, $Debug::getInstance("access"_s));
			AccessControlContext::debugInit = true;
		}
		return AccessControlContext::debug;
	}
}

void AccessControlContext::init$($ProtectionDomainArray* context) {
	this->isAuthorized$ = false;
	$set(this, combiner, nullptr);
	if ($nc(context)->length == 0) {
		$set(this, context, nullptr);
	} else if (context->length == 1) {
		if (context->get(0) != nullptr) {
			$set(this, context, $cast($ProtectionDomainArray, context->clone()));
		} else {
			$set(this, context, nullptr);
		}
	} else {
		$var($List, v, $new($ArrayList, context->length));
		for (int32_t i = 0; i < context->length; ++i) {
			if ((context->get(i) != nullptr) && (!v->contains(context->get(i)))) {
				v->add(context->get(i));
			}
		}
		if (!v->isEmpty()) {
			$set(this, context, $new($ProtectionDomainArray, v->size()));
			$set(this, context, $fcast($ProtectionDomainArray, v->toArray(this->context)));
		}
	}
}

void AccessControlContext::init$(AccessControlContext* acc, $DomainCombiner* combiner) {
	AccessControlContext::init$(acc, combiner, false);
}

void AccessControlContext::init$(AccessControlContext* acc, $DomainCombiner* combiner, bool preauthorized) {
	this->isAuthorized$ = false;
	$set(this, combiner, nullptr);
	if (!preauthorized) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$init($SecurityConstants);
			sm->checkPermission($SecurityConstants::CREATE_ACC_PERMISSION);
			this->isAuthorized$ = true;
		}
	} else {
		this->isAuthorized$ = true;
	}
	$set(this, context, $nc(acc)->context);
	$set(this, combiner, combiner);
}

void AccessControlContext::init$($ProtectionDomain* caller, $DomainCombiner* combiner, AccessControlContext* parent$renamed, AccessControlContext* context, $PermissionArray* perms) {
	$useLocalCurrentObjectStackCache();
	$var(AccessControlContext, parent, parent$renamed);
	this->isAuthorized$ = false;
	$set(this, combiner, nullptr);
	$var($ProtectionDomainArray, callerPDs, nullptr);
	if (caller != nullptr) {
		$assign(callerPDs, $new($ProtectionDomainArray, {caller}));
	}
	if (context != nullptr) {
		if (combiner != nullptr) {
			$set(this, context, combiner->combine(callerPDs, context->context));
		} else {
			$set(this, context, combine(callerPDs, context->context));
		}
	} else if (combiner != nullptr) {
		$set(this, context, combiner->combine(callerPDs, nullptr));
	} else {
		$set(this, context, combine(callerPDs, nullptr));
	}
	$set(this, combiner, combiner);
	$var($PermissionArray, tmp, nullptr);
	if (perms != nullptr) {
		$assign(tmp, $new($PermissionArray, perms->length));
		for (int32_t i = 0; i < perms->length; ++i) {
			if (perms->get(i) == nullptr) {
				$throwNew($NullPointerException, "permission can\'t be null"_s);
			}
			$load($AllPermission);
			if ($nc($of(perms->get(i)))->getClass() == $AllPermission::class$) {
				$assign(parent, nullptr);
			}
			tmp->set(i, $($FilePermCompat::newPermPlusAltPath(perms->get(i))));
		}
	}
	if (parent != nullptr) {
		$set(this, limitedContext, combine(parent->context, parent->limitedContext));
		this->isLimited = true;
		this->isWrapped = true;
		$set(this, permissions, tmp);
		$set(this, parent, parent);
		$set(this, privilegedContext, context);
	}
	this->isAuthorized$ = true;
}

void AccessControlContext::init$($ProtectionDomainArray* context, bool isPrivileged) {
	this->isAuthorized$ = false;
	$set(this, combiner, nullptr);
	$set(this, context, context);
	this->isPrivileged$ = isPrivileged;
	this->isAuthorized$ = true;
}

void AccessControlContext::init$($ProtectionDomainArray* context, AccessControlContext* privilegedContext) {
	this->isAuthorized$ = false;
	$set(this, combiner, nullptr);
	$set(this, context, context);
	$set(this, privilegedContext, privilegedContext);
	this->isPrivileged$ = true;
}

$ProtectionDomainArray* AccessControlContext::getContext() {
	return this->context;
}

bool AccessControlContext::isPrivileged() {
	return this->isPrivileged$;
}

$DomainCombiner* AccessControlContext::getAssignedCombiner() {
	$var(AccessControlContext, acc, nullptr);
	if (this->isPrivileged$) {
		$assign(acc, this->privilegedContext);
	} else {
		$assign(acc, $AccessController::getInheritedAccessControlContext());
	}
	if (acc != nullptr) {
		return acc->combiner;
	}
	return nullptr;
}

$DomainCombiner* AccessControlContext::getDomainCombiner() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_COMBINER_PERMISSION);
	}
	return getCombiner();
}

$DomainCombiner* AccessControlContext::getCombiner() {
	return this->combiner;
}

bool AccessControlContext::isAuthorized() {
	return this->isAuthorized$;
}

void AccessControlContext::checkPermission($Permission* perm) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	bool dumpDebug = false;
	if (perm == nullptr) {
		$throwNew($NullPointerException, "permission can\'t be null"_s);
	}
	if (getDebug() != nullptr) {
		dumpDebug = !$Debug::isOn("codebase="_s);
		if (!dumpDebug) {
			for (int32_t i = 0; this->context != nullptr && i < $nc(this->context)->length; ++i) {
				bool var$1 = $nc($nc(this->context)->get(i))->getCodeSource() != nullptr;
				bool var$0 = var$1 && $nc($($nc($nc(this->context)->get(i))->getCodeSource()))->getLocation() != nullptr;
				if (var$0 && $Debug::isOn($$str({"codebase="_s, $($nc($($nc($($nc($nc(this->context)->get(i))->getCodeSource()))->getLocation()))->toString())}))) {
					dumpDebug = true;
					break;
				}
			}
		}
		bool var$2 = !$Debug::isOn("permission="_s);
		dumpDebug &= var$2 || $Debug::isOn($$str({"permission="_s, $($nc($of(perm))->getClass()->getCanonicalName())}));
		if (dumpDebug && $Debug::isOn("stack"_s)) {
			$Thread::dumpStack();
		}
		if (dumpDebug && $Debug::isOn("domain"_s)) {
			if (this->context == nullptr) {
				$nc(AccessControlContext::debug)->println("domain (context is null)"_s);
			} else {
				for (int32_t i = 0; i < $nc(this->context)->length; ++i) {
					$nc(AccessControlContext::debug)->println($$str({"domain "_s, $$str(i), " "_s, $nc(this->context)->get(i)}));
				}
			}
		}
	}
	if (this->context == nullptr) {
		checkPermission2(perm);
		return;
	}
	for (int32_t i = 0; i < $nc(this->context)->length; ++i) {
		if ($nc(this->context)->get(i) != nullptr && !$nc($nc(this->context)->get(i))->impliesWithAltFilePerm(perm)) {
			if (dumpDebug) {
				$nc(AccessControlContext::debug)->println($$str({"access denied "_s, perm}));
			}
			if ($Debug::isOn("failure"_s) && AccessControlContext::debug != nullptr) {
				if (!dumpDebug) {
					$nc(AccessControlContext::debug)->println($$str({"access denied "_s, perm}));
				}
				$Thread::dumpStack();
				$var($ProtectionDomain, pd, $nc(this->context)->get(i));
				$var($Debug, db, AccessControlContext::debug);
				$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($AccessControlContext$1, this, db, pd)));
			}
			$throwNew($AccessControlException, $$str({"access denied "_s, perm}), perm);
		}
	}
	if (dumpDebug) {
		$nc(AccessControlContext::debug)->println($$str({"access allowed "_s, perm}));
	}
	checkPermission2(perm);
}

void AccessControlContext::checkPermission2($Permission* perm) {
	$useLocalCurrentObjectStackCache();
	if (!this->isLimited) {
		return;
	}
	if (this->privilegedContext != nullptr) {
		$nc(this->privilegedContext)->checkPermission2(perm);
	}
	if (this->isWrapped) {
		return;
	}
	if (this->permissions != nullptr) {
		$Class* permClass = $nc($of(perm))->getClass();
		for (int32_t i = 0; i < $nc(this->permissions)->length; ++i) {
			$var($Permission, limit, $nc(this->permissions)->get(i));
			bool var$0 = $of($nc($of(limit))->getClass())->equals(permClass);
			if (var$0 && limit->implies(perm)) {
				return;
			}
		}
	}
	if (this->parent != nullptr) {
		if (this->permissions == nullptr) {
			$nc(this->parent)->checkPermission2(perm);
		} else {
			$nc(this->parent)->checkPermission(perm);
		}
	}
}

AccessControlContext* AccessControlContext::optimize() {
	$useLocalCurrentObjectStackCache();
	$var(AccessControlContext, acc, nullptr);
	$var($DomainCombiner, combiner, nullptr);
	$var(AccessControlContext, parent, nullptr);
	$var($PermissionArray, permissions, nullptr);
	if (this->isPrivileged$) {
		$assign(acc, this->privilegedContext);
		if (acc != nullptr) {
			if (acc->isWrapped) {
				$assign(permissions, acc->permissions);
				$assign(parent, acc->parent);
			}
		}
	} else {
		$assign(acc, $AccessController::getInheritedAccessControlContext());
		if (acc != nullptr) {
			if (acc->isLimited) {
				$assign(parent, acc);
			}
		}
	}
	bool skipStack = (this->context == nullptr);
	bool skipAssigned = (acc == nullptr || $nc(acc)->context == nullptr);
	$var($ProtectionDomainArray, assigned, (skipAssigned) ? ($ProtectionDomainArray*)nullptr : acc->context);
	$var($ProtectionDomainArray, pd, nullptr);
	bool skipLimited = ((acc == nullptr || !acc->isWrapped) && parent == nullptr);
	if (acc != nullptr && acc->combiner != nullptr) {
		if (getDebug() != nullptr) {
			$nc(AccessControlContext::debug)->println("AccessControlContext invoking the Combiner"_s);
		}
		$assign(combiner, acc->combiner);
		$assign(pd, $nc(combiner)->combine(this->context, assigned));
	} else {
		if (skipStack) {
			if (skipAssigned) {
				calculateFields(acc, parent, permissions);
				return this;
			} else if (skipLimited) {
				return acc;
			}
		} else if (assigned != nullptr) {
			if (skipLimited) {
				if ($nc(this->context)->length == 1 && $nc(this->context)->get(0) == assigned->get(0)) {
					return acc;
				}
			}
		}
		$assign(pd, combine(this->context, assigned));
		if (skipLimited && !skipAssigned && pd == assigned) {
			return acc;
		} else if (skipAssigned && pd == this->context) {
			calculateFields(acc, parent, permissions);
			return this;
		}
	}
	$set(this, context, pd);
	$set(this, combiner, combiner);
	this->isPrivileged$ = false;
	calculateFields(acc, parent, permissions);
	return this;
}

$ProtectionDomainArray* AccessControlContext::combine($ProtectionDomainArray* current, $ProtectionDomainArray* assigned) {
	$init(AccessControlContext);
	$useLocalCurrentObjectStackCache();
	bool skipStack = (current == nullptr);
	bool skipAssigned = (assigned == nullptr);
	int32_t slen = (skipStack) ? 0 : $nc(current)->length;
	if (skipAssigned && slen <= 2) {
		return current;
	}
	int32_t n = (skipAssigned) ? 0 : $nc(assigned)->length;
	$var($ProtectionDomainArray, pd, $new($ProtectionDomainArray, slen + n));
	if (!skipAssigned) {
		$System::arraycopy(assigned, 0, pd, 0, n);
	}
	bool outer$continue = false;
	for (int32_t i = 0; i < slen; ++i) {
		$var($ProtectionDomain, sd, current->get(i));
		if (sd != nullptr) {
			for (int32_t j = 0; j < n; ++j) {
				if (sd == pd->get(j)) {
					outer$continue = true;
					break;
				}
			}
			if (outer$continue) {
				outer$continue = false;
				continue;
			}
			pd->set(n++, sd);
		}
	}
	if (n != pd->length) {
		if (!skipAssigned && n == assigned->length) {
			return assigned;
		} else if (skipAssigned && n == slen) {
			return current;
		}
		$var($ProtectionDomainArray, tmp, $new($ProtectionDomainArray, n));
		$System::arraycopy(pd, 0, tmp, 0, n);
		$assign(pd, tmp);
	}
	return pd;
}

void AccessControlContext::calculateFields(AccessControlContext* assigned, AccessControlContext* parent, $PermissionArray* permissions) {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomainArray, parentLimit, nullptr);
	$var($ProtectionDomainArray, assignedLimit, nullptr);
	$var($ProtectionDomainArray, newLimit, nullptr);
	$assign(parentLimit, (parent != nullptr) ? $nc(parent)->limitedContext : ($ProtectionDomainArray*)nullptr);
	$assign(assignedLimit, (assigned != nullptr) ? $nc(assigned)->limitedContext : ($ProtectionDomainArray*)nullptr);
	$assign(newLimit, combine(parentLimit, assignedLimit));
	if (newLimit != nullptr) {
		if (this->context == nullptr || !containsAllPDs(newLimit, this->context)) {
			$set(this, limitedContext, newLimit);
			$set(this, permissions, permissions);
			$set(this, parent, parent);
			this->isLimited = true;
		}
	}
}

bool AccessControlContext::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	$var(AccessControlContext, that, nullptr);
	bool var$2 = $instanceOf(AccessControlContext, obj);
	if (var$2) {
		$assign(that, $cast(AccessControlContext, obj));
		var$2 = true;
	}
	bool var$1 = var$2;
	bool var$0 = var$1 && equalContext(that);
	return var$0 && equalLimitedContext(that);
}

bool AccessControlContext::equalContext(AccessControlContext* that) {
	if (!equalPDs(this->context, $nc(that)->context)) {
		return false;
	}
	if (this->combiner == nullptr && $nc(that)->combiner != nullptr) {
		return false;
	}
	if (this->combiner != nullptr && !$nc($of(this->combiner))->equals($nc(that)->combiner)) {
		return false;
	}
	return true;
}

bool AccessControlContext::equalPDs($ProtectionDomainArray* a, $ProtectionDomainArray* b) {
	if (a == nullptr) {
		return (b == nullptr);
	}
	if (b == nullptr) {
		return false;
	}
	bool var$0 = containsAllPDs(a, b);
	if (!(var$0 && containsAllPDs(b, a))) {
		return false;
	}
	return true;
}

bool AccessControlContext::equalLimitedContext(AccessControlContext* that) {
	$useLocalCurrentObjectStackCache();
	if (that == nullptr) {
		return false;
	}
	if (!this->isLimited && !$nc(that)->isLimited) {
		return true;
	}
	if (!(this->isLimited && $nc(that)->isLimited)) {
		return false;
	}
	if ((this->isWrapped && !$nc(that)->isWrapped) || (!this->isWrapped && $nc(that)->isWrapped)) {
		return false;
	}
	if (this->permissions == nullptr && $nc(that)->permissions != nullptr) {
		return false;
	}
	if (this->permissions != nullptr && $nc(that)->permissions == nullptr) {
		return false;
	}
	bool var$0 = this->containsAllLimits(that);
	if (!(var$0 && $nc(that)->containsAllLimits(this))) {
		return false;
	}
	$var(AccessControlContext, thisNextPC, getNextPC(this));
	$var(AccessControlContext, thatNextPC, getNextPC(that));
	if (thisNextPC == nullptr && thatNextPC != nullptr && thatNextPC->isLimited) {
		return false;
	}
	if (thisNextPC != nullptr && !thisNextPC->equalLimitedContext(thatNextPC)) {
		return false;
	}
	if (this->parent == nullptr && $nc(that)->parent != nullptr) {
		return false;
	}
	if (this->parent != nullptr && !$nc(this->parent)->equals($nc(that)->parent)) {
		return false;
	}
	return true;
}

AccessControlContext* AccessControlContext::getNextPC(AccessControlContext* acc$renamed) {
	$init(AccessControlContext);
	$var(AccessControlContext, acc, acc$renamed);
	while (acc != nullptr && acc->privilegedContext != nullptr) {
		$assign(acc, acc->privilegedContext);
		if (!$nc(acc)->isWrapped) {
			return acc;
		}
	}
	return nullptr;
}

bool AccessControlContext::containsAllPDs($ProtectionDomainArray* thisContext, $ProtectionDomainArray* thatContext) {
	$init(AccessControlContext);
	$useLocalCurrentObjectStackCache();
	bool match = false;
	$var($ProtectionDomain, thisPd, nullptr);
	for (int32_t i = 0; i < $nc(thisContext)->length; ++i) {
		match = false;
		if (($assign(thisPd, thisContext->get(i))) == nullptr) {
			for (int32_t j = 0; (j < $nc(thatContext)->length) && !match; ++j) {
				match = (thatContext->get(j) == nullptr);
			}
		} else {
			$Class* thisPdClass = $nc($of(thisPd))->getClass();
			$var($ProtectionDomain, thatPd, nullptr);
			for (int32_t j = 0; (j < $nc(thatContext)->length) && !match; ++j) {
				$assign(thatPd, thatContext->get(j));
				bool var$0 = thatPd != nullptr && thisPdClass == $of(thatPd)->getClass();
				match = (var$0 && $of(thisPd)->equals(thatPd));
			}
		}
		if (!match) {
			return false;
		}
	}
	return match;
}

bool AccessControlContext::containsAllLimits(AccessControlContext* that) {
	$useLocalCurrentObjectStackCache();
	bool match = false;
	$var($Permission, thisPerm, nullptr);
	if (this->permissions == nullptr && $nc(that)->permissions == nullptr) {
		return true;
	}
	for (int32_t i = 0; i < $nc(this->permissions)->length; ++i) {
		$var($Permission, limit, $nc(this->permissions)->get(i));
		$Class* limitClass = $nc($of(limit))->getClass();
		match = false;
		for (int32_t j = 0; (j < $nc($nc(that)->permissions)->length) && !match; ++j) {
			$var($Permission, perm, $nc(that->permissions)->get(j));
			bool var$0 = $nc($of(limitClass))->equals($nc($of(perm))->getClass());
			match = (var$0 && limit->equals(perm));
		}
		if (!match) {
			return false;
		}
	}
	return match;
}

int32_t AccessControlContext::hashCode() {
	int32_t hashCode = 0;
	if (this->context == nullptr) {
		return hashCode;
	}
	for (int32_t i = 0; i < $nc(this->context)->length; ++i) {
		if ($nc(this->context)->get(i) != nullptr) {
			hashCode ^= $nc($of($nc(this->context)->get(i)))->hashCode();
		}
	}
	return hashCode;
}

void clinit$AccessControlContext($Class* class$) {
	AccessControlContext::debugInit = false;
	$assignStatic(AccessControlContext::debug, nullptr);
}

AccessControlContext::AccessControlContext() {
}

$Class* AccessControlContext::load$($String* name, bool initialize) {
	$loadClass(AccessControlContext, name, initialize, &_AccessControlContext_ClassInfo_, clinit$AccessControlContext, allocate$AccessControlContext);
	return class$;
}

$Class* AccessControlContext::class$ = nullptr;

	} // security
} // java