#include <javax/security/auth/SubjectDomainCombiner.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Principal.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <javax/security/auth/AuthPermission.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/SubjectDomainCombiner$1.h>
#include <javax/security/auth/SubjectDomainCombiner$2.h>
#include <javax/security/auth/SubjectDomainCombiner$WeakKeyValueMap.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

using $PrincipalArray = $Array<::java::security::Principal>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $AuthPermission = ::javax::security::auth::AuthPermission;
using $Subject = ::javax::security::auth::Subject;
using $SubjectDomainCombiner$1 = ::javax::security::auth::SubjectDomainCombiner$1;
using $SubjectDomainCombiner$2 = ::javax::security::auth::SubjectDomainCombiner$2;
using $SubjectDomainCombiner$WeakKeyValueMap = ::javax::security::auth::SubjectDomainCombiner$WeakKeyValueMap;
using $Debug = ::sun::security::util::Debug;

namespace javax {
	namespace security {
		namespace auth {

$NamedAttribute SubjectDomainCombiner_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _SubjectDomainCombiner_Annotations_[] = {
	{"Ljava/lang/Deprecated;", SubjectDomainCombiner_Attribute_var$0},
	{}
};

$FieldInfo _SubjectDomainCombiner_FieldInfo_[] = {
	{"subject", "Ljavax/security/auth/Subject;", nullptr, $PRIVATE, $field(SubjectDomainCombiner, subject)},
	{"cachedPDs", "Ljavax/security/auth/SubjectDomainCombiner$WeakKeyValueMap;", "Ljavax/security/auth/SubjectDomainCombiner$WeakKeyValueMap<Ljava/security/ProtectionDomain;Ljava/security/ProtectionDomain;>;", $PRIVATE, $field(SubjectDomainCombiner, cachedPDs)},
	{"principalSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/Principal;>;", $PRIVATE, $field(SubjectDomainCombiner, principalSet)},
	{"principals", "[Ljava/security/Principal;", nullptr, $PRIVATE, $field(SubjectDomainCombiner, principals)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SubjectDomainCombiner, debug)},
	{}
};

$MethodInfo _SubjectDomainCombiner_MethodInfo_[] = {
	{"<init>", "(Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, $method(SubjectDomainCombiner, init$, void, $Subject*)},
	{"combine", "([Ljava/security/ProtectionDomain;[Ljava/security/ProtectionDomain;)[Ljava/security/ProtectionDomain;", nullptr, $PUBLIC, $virtualMethod(SubjectDomainCombiner, combine, $ProtectionDomainArray*, $ProtectionDomainArray*, $ProtectionDomainArray*)},
	{"getSubject", "()Ljavax/security/auth/Subject;", nullptr, $PUBLIC, $virtualMethod(SubjectDomainCombiner, getSubject, $Subject*)},
	{"optimize", "([Ljava/security/ProtectionDomain;)[Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $STATIC, $staticMethod(SubjectDomainCombiner, optimize, $ProtectionDomainArray*, $ProtectionDomainArray*)},
	{"printDomain", "(Ljava/security/ProtectionDomain;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SubjectDomainCombiner, printDomain, $String*, $ProtectionDomain*)},
	{"printInputDomains", "([Ljava/security/ProtectionDomain;[Ljava/security/ProtectionDomain;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SubjectDomainCombiner, printInputDomains, void, $ProtectionDomainArray*, $ProtectionDomainArray*)},
	{}
};

$InnerClassInfo _SubjectDomainCombiner_InnerClassesInfo_[] = {
	{"javax.security.auth.SubjectDomainCombiner$WeakKeyValueMap", "javax.security.auth.SubjectDomainCombiner", "WeakKeyValueMap", $PRIVATE | $STATIC},
	{"javax.security.auth.SubjectDomainCombiner$2", nullptr, nullptr, 0},
	{"javax.security.auth.SubjectDomainCombiner$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SubjectDomainCombiner_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.security.auth.SubjectDomainCombiner",
	"java.lang.Object",
	"java.security.DomainCombiner",
	_SubjectDomainCombiner_FieldInfo_,
	_SubjectDomainCombiner_MethodInfo_,
	nullptr,
	nullptr,
	_SubjectDomainCombiner_InnerClassesInfo_,
	_SubjectDomainCombiner_Annotations_,
	nullptr,
	"javax.security.auth.SubjectDomainCombiner$WeakKeyValueMap,javax.security.auth.SubjectDomainCombiner$2,javax.security.auth.SubjectDomainCombiner$1"
};

$Object* allocate$SubjectDomainCombiner($Class* clazz) {
	return $of($alloc(SubjectDomainCombiner));
}

$Debug* SubjectDomainCombiner::debug = nullptr;

void SubjectDomainCombiner::init$($Subject* subject) {
	$set(this, cachedPDs, $new($SubjectDomainCombiner$WeakKeyValueMap));
	$set(this, subject, subject);
	if ($nc(subject)->isReadOnly()) {
		$set(this, principalSet, subject->getPrincipals());
		$set(this, principals, $fcast($PrincipalArray, $nc(this->principalSet)->toArray($$new($PrincipalArray, $nc(this->principalSet)->size()))));
	}
}

$Subject* SubjectDomainCombiner::getSubject() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($AuthPermission, "getSubjectFromDomainCombiner"_s));
	}
	return this->subject;
}

$ProtectionDomainArray* SubjectDomainCombiner::combine($ProtectionDomainArray* currentDomains$renamed, $ProtectionDomainArray* assignedDomains) {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomainArray, currentDomains, currentDomains$renamed);
	$beforeCallerSensitive();
	if (SubjectDomainCombiner::debug != nullptr) {
		if (this->subject == nullptr) {
			$nc(SubjectDomainCombiner::debug)->println("null subject"_s);
		} else {
			$var($Subject, s, this->subject);
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SubjectDomainCombiner$1, this, s)));
		}
		printInputDomains(currentDomains, assignedDomains);
	}
	if (currentDomains == nullptr || $nc(currentDomains)->length == 0) {
		return assignedDomains;
	}
	$assign(currentDomains, optimize(currentDomains));
	if (SubjectDomainCombiner::debug != nullptr) {
		$nc(SubjectDomainCombiner::debug)->println("after optimize"_s);
		printInputDomains(currentDomains, assignedDomains);
	}
	if (currentDomains == nullptr && assignedDomains == nullptr) {
		return nullptr;
	}
	int32_t cLen = (currentDomains == nullptr ? 0 : $nc(currentDomains)->length);
	int32_t aLen = (assignedDomains == nullptr ? 0 : $nc(assignedDomains)->length);
	$var($ProtectionDomainArray, newDomains, $new($ProtectionDomainArray, cLen + aLen));
	bool allNew = true;
	$synchronized(this->cachedPDs) {
		bool var$0 = !$nc(this->subject)->isReadOnly();
		if (var$0 && !$nc($($nc(this->subject)->getPrincipals()))->equals(this->principalSet)) {
			$var($Set, newSet, $nc(this->subject)->getPrincipals());
			$synchronized(newSet) {
				$set(this, principalSet, $new($HashSet, static_cast<$Collection*>(newSet)));
			}
			$set(this, principals, $fcast($PrincipalArray, $nc(this->principalSet)->toArray($$new($PrincipalArray, $nc(this->principalSet)->size()))));
			$nc(this->cachedPDs)->clear();
			if (SubjectDomainCombiner::debug != nullptr) {
				$nc(SubjectDomainCombiner::debug)->println("Subject mutated - clearing cache"_s);
			}
		}
		$var($ProtectionDomain, subjectPd, nullptr);
		for (int32_t i = 0; i < cLen; ++i) {
			$var($ProtectionDomain, pd, currentDomains->get(i));
			$assign(subjectPd, $cast($ProtectionDomain, $nc(this->cachedPDs)->getValue(pd)));
			if (subjectPd == nullptr) {
				if ($nc(pd)->staticPermissionsOnly()) {
					$assign(subjectPd, pd);
				} else {
					$var($CodeSource, var$1, pd->getCodeSource());
					$var($PermissionCollection, var$2, pd->getPermissions());
					$assign(subjectPd, $new($ProtectionDomain, var$1, var$2, $(pd->getClassLoader()), this->principals));
				}
				$nc(this->cachedPDs)->putValue(pd, subjectPd);
			} else {
				allNew = false;
			}
			newDomains->set(i, subjectPd);
		}
	}
	if (SubjectDomainCombiner::debug != nullptr) {
		$nc(SubjectDomainCombiner::debug)->println("updated current: "_s);
		for (int32_t i = 0; i < cLen; ++i) {
			$nc(SubjectDomainCombiner::debug)->println($$str({"\tupdated["_s, $$str(i), "] = "_s, $(printDomain(newDomains->get(i)))}));
		}
	}
	if (aLen > 0) {
		$System::arraycopy(assignedDomains, 0, newDomains, cLen, aLen);
		if (!allNew) {
			$assign(newDomains, optimize(newDomains));
		}
	}
	if (SubjectDomainCombiner::debug != nullptr) {
		if (newDomains == nullptr || newDomains->length == 0) {
			$nc(SubjectDomainCombiner::debug)->println("returning null"_s);
		} else {
			$nc(SubjectDomainCombiner::debug)->println("combinedDomains: "_s);
			for (int32_t i = 0; i < newDomains->length; ++i) {
				$nc(SubjectDomainCombiner::debug)->println($$str({"newDomain "_s, $$str(i), ": "_s, $(printDomain(newDomains->get(i)))}));
			}
		}
	}
	if (newDomains == nullptr || newDomains->length == 0) {
		return nullptr;
	} else {
		return newDomains;
	}
}

$ProtectionDomainArray* SubjectDomainCombiner::optimize($ProtectionDomainArray* domains) {
	$init(SubjectDomainCombiner);
	$useLocalCurrentObjectStackCache();
	if (domains == nullptr || $nc(domains)->length == 0) {
		return nullptr;
	}
	$var($ProtectionDomainArray, optimized, $new($ProtectionDomainArray, $nc(domains)->length));
	$var($ProtectionDomain, pd, nullptr);
	int32_t num = 0;
	for (int32_t i = 0; i < domains->length; ++i) {
		if (($assign(pd, domains->get(i))) != nullptr) {
			bool found = false;
			for (int32_t j = 0; j < num && !found; ++j) {
				found = (optimized->get(j) == pd);
			}
			if (!found) {
				optimized->set(num++, pd);
			}
		}
	}
	if (num > 0 && num < domains->length) {
		$var($ProtectionDomainArray, downSize, $new($ProtectionDomainArray, num));
		$System::arraycopy(optimized, 0, downSize, 0, downSize->length);
		$assign(optimized, downSize);
	}
	return ((num == 0 || optimized->length == 0) ? ($ProtectionDomainArray*)nullptr : optimized);
}

void SubjectDomainCombiner::printInputDomains($ProtectionDomainArray* currentDomains, $ProtectionDomainArray* assignedDomains) {
	$init(SubjectDomainCombiner);
	$useLocalCurrentObjectStackCache();
	if (currentDomains == nullptr || $nc(currentDomains)->length == 0) {
		$nc(SubjectDomainCombiner::debug)->println("currentDomains null or 0 length"_s);
	} else {
		for (int32_t i = 0; currentDomains != nullptr && i < currentDomains->length; ++i) {
			if (currentDomains->get(i) == nullptr) {
				$nc(SubjectDomainCombiner::debug)->println($$str({"currentDomain "_s, $$str(i), ": SystemDomain"_s}));
			} else {
				$nc(SubjectDomainCombiner::debug)->println($$str({"currentDomain "_s, $$str(i), ": "_s, $(printDomain(currentDomains->get(i)))}));
			}
		}
	}
	if (assignedDomains == nullptr || $nc(assignedDomains)->length == 0) {
		$nc(SubjectDomainCombiner::debug)->println("assignedDomains null or 0 length"_s);
	} else {
		$nc(SubjectDomainCombiner::debug)->println("assignedDomains = "_s);
		for (int32_t i = 0; assignedDomains != nullptr && i < assignedDomains->length; ++i) {
			if (assignedDomains->get(i) == nullptr) {
				$nc(SubjectDomainCombiner::debug)->println($$str({"assignedDomain "_s, $$str(i), ": SystemDomain"_s}));
			} else {
				$nc(SubjectDomainCombiner::debug)->println($$str({"assignedDomain "_s, $$str(i), ": "_s, $(printDomain(assignedDomains->get(i)))}));
			}
		}
	}
}

$String* SubjectDomainCombiner::printDomain($ProtectionDomain* pd) {
	$init(SubjectDomainCombiner);
	$beforeCallerSensitive();
	if (pd == nullptr) {
		return "null"_s;
	}
	return $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SubjectDomainCombiner$2, pd))));
}

void clinit$SubjectDomainCombiner($Class* class$) {
	$assignStatic(SubjectDomainCombiner::debug, $Debug::getInstance("combiner"_s, "\t[SubjectDomainCombiner]"_s));
}

SubjectDomainCombiner::SubjectDomainCombiner() {
}

$Class* SubjectDomainCombiner::load$($String* name, bool initialize) {
	$loadClass(SubjectDomainCombiner, name, initialize, &_SubjectDomainCombiner_ClassInfo_, clinit$SubjectDomainCombiner, allocate$SubjectDomainCombiner);
	return class$;
}

$Class* SubjectDomainCombiner::class$ = nullptr;

		} // auth
	} // security
} // javax