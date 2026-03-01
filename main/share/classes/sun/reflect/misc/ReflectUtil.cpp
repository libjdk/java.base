#include <sun/reflect/misc/ReflectUtil.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/security/Permission.h>
#include <jdk/internal/reflect/Reflection.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef CHECK_MEMBER_ACCESS_PERMISSION
#undef PROXY_PACKAGE

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Member = ::java::lang::reflect::Member;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $Permission = ::java::security::Permission;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace reflect {
		namespace misc {

$FieldInfo _ReflectUtil_FieldInfo_[] = {
	{"PROXY_PACKAGE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ReflectUtil, PROXY_PACKAGE)},
	{}
};

$MethodInfo _ReflectUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ReflectUtil, init$, void)},
	{"checkPackageAccess", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PUBLIC | $STATIC, $staticMethod(ReflectUtil, checkPackageAccess, void, $Class*)},
	{"checkPackageAccess", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReflectUtil, checkPackageAccess, void, $String*)},
	{"checkProxyMethod", "(Ljava/lang/Object;Ljava/lang/reflect/Method;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReflectUtil, checkProxyMethod, void, Object$*, $Method*)},
	{"checkProxyPackageAccess", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PUBLIC | $STATIC, $staticMethod(ReflectUtil, checkProxyPackageAccess, void, $Class*)},
	{"checkProxyPackageAccess", "(Ljava/lang/ClassLoader;[Ljava/lang/Class;)V", "(Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)V", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ReflectUtil, checkProxyPackageAccess, void, $ClassLoader*, $ClassArray*)},
	{"conservativeCheckMemberAccess", "(Ljava/lang/reflect/Member;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ReflectUtil, conservativeCheckMemberAccess, void, $Member*), "java.lang.SecurityException"},
	{"ensureMemberAccess", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/Object;I)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;Ljava/lang/Object;I)V", $PUBLIC | $STATIC, $staticMethod(ReflectUtil, ensureMemberAccess, void, $Class*, $Class*, Object$*, int32_t), "java.lang.IllegalAccessException"},
	{"forName", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(ReflectUtil, forName, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"isAncestor", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ReflectUtil, isAncestor, bool, $ClassLoader*, $ClassLoader*)},
	{"isNonPublicProxyClass", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC | $STATIC, $staticMethod(ReflectUtil, isNonPublicProxyClass, bool, $Class*)},
	{"isPackageAccessible", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC | $STATIC, $staticMethod(ReflectUtil, isPackageAccessible, bool, $Class*)},
	{"isSuperInterface", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(ReflectUtil, isSuperInterface, bool, $Class*, $Class*)},
	{"needsPackageAccessCheck", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(ReflectUtil, needsPackageAccessCheck, bool, $ClassLoader*, $ClassLoader*)},
	{"privateCheckPackageAccess", "(Ljava/lang/SecurityManager;Ljava/lang/Class;)V", "(Ljava/lang/SecurityManager;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(ReflectUtil, privateCheckPackageAccess, void, $SecurityManager*, $Class*)},
	{"privateCheckProxyPackageAccess", "(Ljava/lang/SecurityManager;Ljava/lang/Class;)V", "(Ljava/lang/SecurityManager;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(ReflectUtil, privateCheckProxyPackageAccess, void, $SecurityManager*, $Class*)},
	{}
};

$ClassInfo _ReflectUtil_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.reflect.misc.ReflectUtil",
	"java.lang.Object",
	nullptr,
	_ReflectUtil_FieldInfo_,
	_ReflectUtil_MethodInfo_
};

$Object* allocate$ReflectUtil($Class* clazz) {
	return $of($alloc(ReflectUtil));
}

$String* ReflectUtil::PROXY_PACKAGE = nullptr;

void ReflectUtil::init$() {
}

$Class* ReflectUtil::forName($String* name) {
	$init(ReflectUtil);
	$beforeCallerSensitive();
	checkPackageAccess(name);
	return $Class::forName(name);
}

void ReflectUtil::ensureMemberAccess($Class* currentClass, $Class* memberClass, Object$* target, int32_t modifiers) {
	$init(ReflectUtil);
	$Reflection::ensureMemberAccess(currentClass, memberClass, target == nullptr ? ($Class*)nullptr : $nc($of(target))->getClass(), modifiers);
}

void ReflectUtil::conservativeCheckMemberAccess($Member* m) {
	$init(ReflectUtil);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return;
	}
	$Class* declaringClass = $nc(m)->getDeclaringClass();
	privateCheckPackageAccess(sm, declaringClass);
	bool var$0 = $Modifier::isPublic(m->getModifiers());
	if (var$0 && $Modifier::isPublic($nc(declaringClass)->getModifiers())) {
		return;
	}
	$init($SecurityConstants);
	$nc(sm)->checkPermission($SecurityConstants::CHECK_MEMBER_ACCESS_PERMISSION);
}

void ReflectUtil::checkPackageAccess($Class* clazz) {
	$init(ReflectUtil);
	$var($SecurityManager, s, $System::getSecurityManager());
	if (s != nullptr) {
		privateCheckPackageAccess(s, clazz);
	}
}

void ReflectUtil::privateCheckPackageAccess($SecurityManager* s, $Class* clazz) {
	$init(ReflectUtil);
	$var($String, pkg, $nc(clazz)->getPackageName());
	if (!$nc(pkg)->isEmpty()) {
		$nc(s)->checkPackageAccess(pkg);
	}
	if (isNonPublicProxyClass(clazz)) {
		privateCheckProxyPackageAccess(s, clazz);
	}
}

void ReflectUtil::checkPackageAccess($String* name) {
	$init(ReflectUtil);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, s, $System::getSecurityManager());
	if (s != nullptr) {
		$var($String, cname, $nc(name)->replace(u'/', u'.'));
		if (cname->startsWith("["_s)) {
			int32_t b = cname->lastIndexOf((int32_t)u'[') + 2;
			if (b > 1 && b < cname->length()) {
				$assign(cname, cname->substring(b));
			}
		}
		int32_t i = cname->lastIndexOf((int32_t)u'.');
		if (i != -1) {
			s->checkPackageAccess($(cname->substring(0, i)));
		}
	}
}

bool ReflectUtil::isPackageAccessible($Class* clazz) {
	$init(ReflectUtil);
	try {
		checkPackageAccess(clazz);
	} catch ($SecurityException& e) {
		return false;
	}
	return true;
}

bool ReflectUtil::isAncestor($ClassLoader* p, $ClassLoader* cl) {
	$init(ReflectUtil);
	$beforeCallerSensitive();
	$var($ClassLoader, acl, cl);
	do {
		$assign(acl, $nc(acl)->getParent());
		if (p == acl) {
			return true;
		}
	} while (acl != nullptr);
	return false;
}

bool ReflectUtil::needsPackageAccessCheck($ClassLoader* from, $ClassLoader* to) {
	$init(ReflectUtil);
	if (from == nullptr || from == to) {
		return false;
	}
	if (to == nullptr) {
		return true;
	}
	return !isAncestor(from, to);
}

void ReflectUtil::checkProxyPackageAccess($Class* clazz) {
	$init(ReflectUtil);
	$var($SecurityManager, s, $System::getSecurityManager());
	if (s != nullptr) {
		privateCheckProxyPackageAccess(s, clazz);
	}
}

void ReflectUtil::privateCheckProxyPackageAccess($SecurityManager* s, $Class* clazz) {
	$init(ReflectUtil);
	if ($Proxy::isProxyClass(clazz)) {
		{
			$var($ClassArray, arr$, $nc(clazz)->getInterfaces());
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$Class* intf = arr$->get(i$);
				{
					privateCheckPackageAccess(s, intf);
				}
			}
		}
	}
}

void ReflectUtil::checkProxyPackageAccess($ClassLoader* ccl, $ClassArray* interfaces) {
	$init(ReflectUtil);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		{
			$var($ClassArray, arr$, interfaces);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$Class* intf = arr$->get(i$);
				{
					$var($ClassLoader, cl, $nc(intf)->getClassLoader());
					if (needsPackageAccessCheck(ccl, cl)) {
						privateCheckPackageAccess(sm, intf);
					}
				}
			}
		}
	}
}

bool ReflectUtil::isNonPublicProxyClass($Class* cls) {
	$init(ReflectUtil);
	if (!$Proxy::isProxyClass(cls)) {
		return false;
	}
	return !$Modifier::isPublic($nc(cls)->getModifiers());
}

void ReflectUtil::checkProxyMethod(Object$* proxy, $Method* method) {
	$init(ReflectUtil);
	$useLocalCurrentObjectStackCache();
	if (proxy == nullptr || !$Proxy::isProxyClass($nc($of(proxy))->getClass())) {
		$throwNew($IllegalArgumentException, "Not a Proxy instance"_s);
	}
	if ($Modifier::isStatic($nc(method)->getModifiers())) {
		$throwNew($IllegalArgumentException, "Can\'t handle static method"_s);
	}
	$Class* c = $nc(method)->getDeclaringClass();
	if (c == $Object::class$) {
		$var($String, name, method->getName());
		bool var$1 = $nc(name)->equals("hashCode"_s);
		bool var$0 = var$1 || $nc(name)->equals("equals"_s);
		if (var$0 || $nc(name)->equals("toString"_s)) {
			return;
		}
	}
	if (isSuperInterface($nc($of(proxy))->getClass(), c)) {
		return;
	}
	$throwNew($IllegalArgumentException, $$str({"Can\'t handle: "_s, method}));
}

bool ReflectUtil::isSuperInterface($Class* c, $Class* intf) {
	$init(ReflectUtil);
	{
		$var($ClassArray, arr$, $nc(c)->getInterfaces());
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* i = arr$->get(i$);
			{
				if (i == intf) {
					return true;
				}
				if (isSuperInterface(i, intf)) {
					return true;
				}
			}
		}
	}
	return false;
}

ReflectUtil::ReflectUtil() {
}

void clinit$ReflectUtil($Class* class$) {
	$assignStatic(ReflectUtil::PROXY_PACKAGE, "com.sun.proxy"_s);
}

$Class* ReflectUtil::load$($String* name, bool initialize) {
	$loadClass(ReflectUtil, name, initialize, &_ReflectUtil_ClassInfo_, clinit$ReflectUtil, allocate$ReflectUtil);
	return class$;
}

$Class* ReflectUtil::class$ = nullptr;

		} // misc
	} // reflect
} // sun