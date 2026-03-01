#include <jdk/internal/loader/BootLoader$PackageHelper.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/Package.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Optional.h>
#include <java/util/function/Supplier.h>
#include <java/util/jar/Manifest.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/BootLoader$PackageHelper$1.h>
#include <jdk/internal/loader/BootLoader$PackageHelper$2.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/module/Modules.h>
#include <jcpp.h>

#undef JAVA_HOME
#undef JLA

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $Package = ::java::lang::Package;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $Path = ::java::nio::file::Path;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Optional = ::java::util::Optional;
using $Supplier = ::java::util::function::Supplier;
using $Manifest = ::java::util::jar::Manifest;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $BootLoader$PackageHelper$1 = ::jdk::internal::loader::BootLoader$PackageHelper$1;
using $BootLoader$PackageHelper$2 = ::jdk::internal::loader::BootLoader$PackageHelper$2;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $Modules = ::jdk::internal::module::Modules;

namespace jdk {
	namespace internal {
		namespace loader {

class BootLoader$PackageHelper$$Lambda$lambda$findModule$0 : public $Supplier {
	$class(BootLoader$PackageHelper$$Lambda$lambda$findModule$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* get() override {
		 return $of(BootLoader$PackageHelper::lambda$findModule$0(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<BootLoader$PackageHelper$$Lambda$lambda$findModule$0>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo BootLoader$PackageHelper$$Lambda$lambda$findModule$0::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(BootLoader$PackageHelper$$Lambda$lambda$findModule$0, name)},
	{}
};
$MethodInfo BootLoader$PackageHelper$$Lambda$lambda$findModule$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(BootLoader$PackageHelper$$Lambda$lambda$findModule$0, init$, void, $String*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(BootLoader$PackageHelper$$Lambda$lambda$findModule$0, get, $Object*)},
	{}
};
$ClassInfo BootLoader$PackageHelper$$Lambda$lambda$findModule$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.BootLoader$PackageHelper$$Lambda$lambda$findModule$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* BootLoader$PackageHelper$$Lambda$lambda$findModule$0::load$($String* name, bool initialize) {
	$loadClass(BootLoader$PackageHelper$$Lambda$lambda$findModule$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* BootLoader$PackageHelper$$Lambda$lambda$findModule$0::class$ = nullptr;

$FieldInfo _BootLoader$PackageHelper_FieldInfo_[] = {
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootLoader$PackageHelper, JLA)},
	{}
};

$MethodInfo _BootLoader$PackageHelper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(BootLoader$PackageHelper, init$, void)},
	{"definePackage", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Package;", nullptr, $STATIC, $staticMethod(BootLoader$PackageHelper, definePackage, $Package*, $String*, $String*)},
	{"findModule", "(Ljava/lang/String;)Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC, $staticMethod(BootLoader$PackageHelper, findModule, $Module*, $String*)},
	{"getManifest", "(Ljava/lang/String;)Ljava/util/jar/Manifest;", nullptr, $PRIVATE | $STATIC, $staticMethod(BootLoader$PackageHelper, getManifest, $Manifest*, $String*)},
	{"lambda$findModule$0", "(Ljava/lang/String;)Ljava/lang/InternalError;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(BootLoader$PackageHelper, lambda$findModule$0, $InternalError*, $String*)},
	{"toFileURL", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticMethod(BootLoader$PackageHelper, toFileURL, $URL*, $String*)},
	{}
};

$InnerClassInfo _BootLoader$PackageHelper_InnerClassesInfo_[] = {
	{"jdk.internal.loader.BootLoader$PackageHelper", "jdk.internal.loader.BootLoader", "PackageHelper", $STATIC},
	{"jdk.internal.loader.BootLoader$PackageHelper$2", nullptr, nullptr, 0},
	{"jdk.internal.loader.BootLoader$PackageHelper$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _BootLoader$PackageHelper_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.loader.BootLoader$PackageHelper",
	"java.lang.Object",
	nullptr,
	_BootLoader$PackageHelper_FieldInfo_,
	_BootLoader$PackageHelper_MethodInfo_,
	nullptr,
	nullptr,
	_BootLoader$PackageHelper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.loader.BootLoader"
};

$Object* allocate$BootLoader$PackageHelper($Class* clazz) {
	return $of($alloc(BootLoader$PackageHelper));
}

$JavaLangAccess* BootLoader$PackageHelper::JLA = nullptr;

void BootLoader$PackageHelper::init$() {
}

$Package* BootLoader$PackageHelper::definePackage($String* name, $String* location) {
	$init(BootLoader$PackageHelper);
	$useLocalCurrentObjectStackCache();
	$var($Module, module, findModule(location));
	if (module != nullptr) {
		if ($nc(name)->isEmpty()) {
			$throwNew($InternalError, $$str({"empty package in "_s, location}));
		}
		return $nc(BootLoader$PackageHelper::JLA)->definePackage($($ClassLoaders::bootLoader()), name, module);
	}
	$var($URL, url, toFileURL(location));
	$var($Manifest, man, url != nullptr ? getManifest(location) : ($Manifest*)nullptr);
	return $nc($($ClassLoaders::bootLoader()))->defineOrCheckPackage(name, man, url);
}

$Module* BootLoader$PackageHelper::findModule($String* location) {
	$init(BootLoader$PackageHelper);
	$useLocalCurrentObjectStackCache();
	$var($String, mn, nullptr);
	if ($nc(location)->startsWith("jrt:/"_s)) {
		$assign(mn, location->substring(5, location->length()));
	} else if (location->startsWith("file:/"_s)) {
		$var($Path, path, $Path::of($($URI::create(location))));
		$init($BootLoader);
		$var($Path, modulesDir, $Path::of($BootLoader::JAVA_HOME, $$new($StringArray, {"modules"_s})));
		if ($nc(path)->startsWith(modulesDir)) {
			$assign(mn, $nc($(path->getFileName()))->toString());
		}
	}
	if (mn != nullptr) {
		$var($String, name, mn);
		return $cast($Module, $nc($($Modules::findLoadedModule(mn)))->orElseThrow(static_cast<$Supplier*>($$new(BootLoader$PackageHelper$$Lambda$lambda$findModule$0, name))));
	} else {
		return nullptr;
	}
}

$URL* BootLoader$PackageHelper::toFileURL($String* location) {
	$init(BootLoader$PackageHelper);
	$beforeCallerSensitive();
	return $cast($URL, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($BootLoader$PackageHelper$1, location))));
}

$Manifest* BootLoader$PackageHelper::getManifest($String* location) {
	$init(BootLoader$PackageHelper);
	$beforeCallerSensitive();
	return $cast($Manifest, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($BootLoader$PackageHelper$2, location))));
}

$InternalError* BootLoader$PackageHelper::lambda$findModule$0($String* name) {
	$init(BootLoader$PackageHelper);
	return $new($InternalError, $$str({name, " not loaded"_s}));
}

void clinit$BootLoader$PackageHelper($Class* class$) {
	$assignStatic(BootLoader$PackageHelper::JLA, $SharedSecrets::getJavaLangAccess());
}

BootLoader$PackageHelper::BootLoader$PackageHelper() {
}

$Class* BootLoader$PackageHelper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(BootLoader$PackageHelper$$Lambda$lambda$findModule$0::classInfo$.name)) {
			return BootLoader$PackageHelper$$Lambda$lambda$findModule$0::load$(name, initialize);
		}
	}
	$loadClass(BootLoader$PackageHelper, name, initialize, &_BootLoader$PackageHelper_ClassInfo_, clinit$BootLoader$PackageHelper, allocate$BootLoader$PackageHelper);
	return class$;
}

$Class* BootLoader$PackageHelper::class$ = nullptr;

		} // loader
	} // internal
} // jdk