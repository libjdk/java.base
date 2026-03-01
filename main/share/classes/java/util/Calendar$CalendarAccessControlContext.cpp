#include <java/util/Calendar$CalendarAccessControlContext.h>

#include <java/lang/RuntimePermission.h>
#include <java/security/AccessControlContext.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Calendar.h>
#include <jcpp.h>

#undef INSTANCE

using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $AccessControlContext = ::java::security::AccessControlContext;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $ProtectionDomain = ::java::security::ProtectionDomain;

namespace java {
	namespace util {

$FieldInfo _Calendar$CalendarAccessControlContext_FieldInfo_[] = {
	{"INSTANCE", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Calendar$CalendarAccessControlContext, INSTANCE)},
	{}
};

$MethodInfo _Calendar$CalendarAccessControlContext_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Calendar$CalendarAccessControlContext, init$, void)},
	{}
};

$InnerClassInfo _Calendar$CalendarAccessControlContext_InnerClassesInfo_[] = {
	{"java.util.Calendar$CalendarAccessControlContext", "java.util.Calendar", "CalendarAccessControlContext", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Calendar$CalendarAccessControlContext_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.Calendar$CalendarAccessControlContext",
	"java.lang.Object",
	nullptr,
	_Calendar$CalendarAccessControlContext_FieldInfo_,
	_Calendar$CalendarAccessControlContext_MethodInfo_,
	nullptr,
	nullptr,
	_Calendar$CalendarAccessControlContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Calendar"
};

$Object* allocate$Calendar$CalendarAccessControlContext($Class* clazz) {
	return $of($alloc(Calendar$CalendarAccessControlContext));
}

$AccessControlContext* Calendar$CalendarAccessControlContext::INSTANCE = nullptr;

void Calendar$CalendarAccessControlContext::init$() {
}

void clinit$Calendar$CalendarAccessControlContext($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($RuntimePermission, perm, $new($RuntimePermission, "accessClassInPackage.sun.util.calendar"_s));
		$var($PermissionCollection, perms, perm->newPermissionCollection());
		$nc(perms)->add(perm);
		$assignStatic(Calendar$CalendarAccessControlContext::INSTANCE, $new($AccessControlContext, $$new($ProtectionDomainArray, {$$new($ProtectionDomain, nullptr, perms)})));
	}
}

Calendar$CalendarAccessControlContext::Calendar$CalendarAccessControlContext() {
}

$Class* Calendar$CalendarAccessControlContext::load$($String* name, bool initialize) {
	$loadClass(Calendar$CalendarAccessControlContext, name, initialize, &_Calendar$CalendarAccessControlContext_ClassInfo_, clinit$Calendar$CalendarAccessControlContext, allocate$Calendar$CalendarAccessControlContext);
	return class$;
}

$Class* Calendar$CalendarAccessControlContext::class$ = nullptr;

	} // util
} // java