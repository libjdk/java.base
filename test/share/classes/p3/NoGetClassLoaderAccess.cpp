#include <p3/NoGetClassLoaderAccess.h>

#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessControlException.h>
#include <java/security/Permission.h>
#include <java/util/Optional.h>
#include <jcpp.h>

#undef GET_CLASSLOADER_PERMISSION

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessControlException = ::java::security::AccessControlException;
using $Permission = ::java::security::Permission;
using $Optional = ::java::util::Optional;

namespace p3 {

$FieldInfo _NoGetClassLoaderAccess_FieldInfo_[] = {
	{"m3", "Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NoGetClassLoaderAccess, m3)},
	{"GET_CLASSLOADER_PERMISSION", "Ljava/security/Permission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NoGetClassLoaderAccess, GET_CLASSLOADER_PERMISSION)},
	{}
};

$MethodInfo _NoGetClassLoaderAccess_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(NoGetClassLoaderAccess, init$, void)},
	{"findClass", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class<*>;", $STATIC, $staticMethod(NoGetClassLoaderAccess, findClass, $Class*, $Module*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(NoGetClassLoaderAccess, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _NoGetClassLoaderAccess_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"p3.NoGetClassLoaderAccess",
	"java.lang.Object",
	nullptr,
	_NoGetClassLoaderAccess_FieldInfo_,
	_NoGetClassLoaderAccess_MethodInfo_
};

$Object* allocate$NoGetClassLoaderAccess($Class* clazz) {
	return $of($alloc(NoGetClassLoaderAccess));
}

$Module* NoGetClassLoaderAccess::m3 = nullptr;
$Permission* NoGetClassLoaderAccess::GET_CLASSLOADER_PERMISSION = nullptr;

void NoGetClassLoaderAccess::init$() {
}

void NoGetClassLoaderAccess::main($StringArray* args) {
	$init(NoGetClassLoaderAccess);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ModuleLayer, boot, $ModuleLayer::boot());
	$System::setSecurityManager($$new($SecurityManager));
	$var($Module, m1, $cast($Module, $nc($($nc(boot)->findModule("m1"_s)))->get()));
	$var($Module, m2, $cast($Module, $nc($(boot->findModule("m2"_s)))->get()));
	findClass(m1, "p1.A"_s);
	findClass(m1, "p1.internal.B"_s);
	findClass(m2, "p2.C"_s);
	findClass(NoGetClassLoaderAccess::m3, "p3.internal.Foo"_s);
}

$Class* NoGetClassLoaderAccess::findClass($Module* module, $String* cn) {
	$init(NoGetClassLoaderAccess);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$Class* c = $Class::forName(module, cn);
		if (c == nullptr) {
			$throwNew($RuntimeException, $$str({cn, " not found in "_s, module}));
		}
		if ($nc(c)->getModule() != module) {
			$throwNew($RuntimeException, $$str({$(c->getModule()), " != "_s, module}));
		}
		return c;
	} catch ($AccessControlException& e) {
		if (module != NoGetClassLoaderAccess::m3) {
			if ($nc($(e->getPermission()))->equals(NoGetClassLoaderAccess::GET_CLASSLOADER_PERMISSION)) {
				return nullptr;
			}
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

void clinit$NoGetClassLoaderAccess($Class* class$) {
	$assignStatic(NoGetClassLoaderAccess::m3, NoGetClassLoaderAccess::class$->getModule());
	$assignStatic(NoGetClassLoaderAccess::GET_CLASSLOADER_PERMISSION, $new($RuntimePermission, "getClassLoader"_s));
}

NoGetClassLoaderAccess::NoGetClassLoaderAccess() {
}

$Class* NoGetClassLoaderAccess::load$($String* name, bool initialize) {
	$loadClass(NoGetClassLoaderAccess, name, initialize, &_NoGetClassLoaderAccess_ClassInfo_, clinit$NoGetClassLoaderAccess, allocate$NoGetClassLoaderAccess);
	return class$;
}

$Class* NoGetClassLoaderAccess::class$ = nullptr;

} // p3