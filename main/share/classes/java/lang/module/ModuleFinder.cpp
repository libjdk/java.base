#include <java/lang/module/ModuleFinder.h>

#include <java/io/Serializable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleFinder$1.h>
#include <java/lang/module/ModuleFinder$2.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <jdk/internal/module/ModulePath.h>
#include <jdk/internal/module/SystemModuleFinders.h>
#include <jcpp.h>

using $ModuleFinderArray = $Array<::java::lang::module::ModuleFinder>;
using $PathArray = $Array<::java::nio::file::Path>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleFinder$1 = ::java::lang::module::ModuleFinder$1;
using $ModuleFinder$2 = ::java::lang::module::ModuleFinder$2;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $ModulePath = ::jdk::internal::module::ModulePath;
using $SystemModuleFinders = ::jdk::internal::module::SystemModuleFinders;

namespace java {
	namespace lang {
		namespace module {

class ModuleFinder$$Lambda$ofSystem : public $PrivilegedAction {
	$class(ModuleFinder$$Lambda$ofSystem, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of($SystemModuleFinders::ofSystem());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleFinder$$Lambda$ofSystem>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleFinder$$Lambda$ofSystem::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleFinder$$Lambda$ofSystem, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleFinder$$Lambda$ofSystem, run, $Object*)},
	{}
};
$ClassInfo ModuleFinder$$Lambda$ofSystem::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.module.ModuleFinder$$Lambda$ofSystem",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ModuleFinder$$Lambda$ofSystem::load$($String* name, bool initialize) {
	$loadClass(ModuleFinder$$Lambda$ofSystem, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleFinder$$Lambda$ofSystem::class$ = nullptr;

$MethodInfo _ModuleFinder_MethodInfo_[] = {
	{"compose", "([Ljava/lang/module/ModuleFinder;)Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ModuleFinder, compose, ModuleFinder*, $ModuleFinderArray*)},
	{"find", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/module/ModuleReference;>;", $PUBLIC | $ABSTRACT, $virtualMethod(ModuleFinder, find, $Optional*, $String*)},
	{"findAll", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/module/ModuleReference;>;", $PUBLIC | $ABSTRACT, $virtualMethod(ModuleFinder, findAll, $Set*)},
	{"of", "([Ljava/nio/file/Path;)Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ModuleFinder, of, ModuleFinder*, $PathArray*)},
	{"ofSystem", "()Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleFinder, ofSystem, ModuleFinder*)},
	{}
};

$InnerClassInfo _ModuleFinder_InnerClassesInfo_[] = {
	{"java.lang.module.ModuleFinder$2", nullptr, nullptr, 0},
	{"java.lang.module.ModuleFinder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ModuleFinder_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.lang.module.ModuleFinder",
	nullptr,
	nullptr,
	nullptr,
	_ModuleFinder_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleFinder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.module.ModuleFinder$2,java.lang.module.ModuleFinder$1"
};

$Object* allocate$ModuleFinder($Class* clazz) {
	return $of($alloc(ModuleFinder));
}

ModuleFinder* ModuleFinder::ofSystem() {
	$load(ModuleFinder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "accessSystemModules"_s));
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ModuleFinder$$Lambda$ofSystem)));
		return $cast(ModuleFinder, $AccessController::doPrivileged(pa));
	} else {
		return $SystemModuleFinders::ofSystem();
	}
}

ModuleFinder* ModuleFinder::of($PathArray* entries) {
	if ($nc(entries)->length == 0) {
		return $new($ModuleFinder$1);
	}
	return $ModulePath::of(entries);
}

ModuleFinder* ModuleFinder::compose($ModuleFinderArray* finders) {
	$var($List, finderList, $List::of(finders));
	return $new($ModuleFinder$2, finderList);
}

$Class* ModuleFinder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleFinder$$Lambda$ofSystem::classInfo$.name)) {
			return ModuleFinder$$Lambda$ofSystem::load$(name, initialize);
		}
	}
	$loadClass(ModuleFinder, name, initialize, &_ModuleFinder_ClassInfo_, allocate$ModuleFinder);
	return class$;
}

$Class* ModuleFinder::class$ = nullptr;

		} // module
	} // lang
} // java