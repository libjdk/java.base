#include <jdk/internal/loader/BootLoader.h>

#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Module.h>
#include <java/lang/Package.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <java/util/Enumeration.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/BootLoader$1.h>
#include <jdk/internal/loader/BootLoader$PackageHelper.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/loader/NativeLibraries.h>
#include <jdk/internal/loader/NativeLibrary.h>
#include <jdk/internal/module/ServicesCatalog.h>
#include <jdk/internal/util/StaticProperty.h>
#include <jcpp.h>

#undef CLASS_LOADER_VALUE_MAP
#undef JAVA_HOME
#undef JLA
#undef NATIVE_LIBS
#undef UNNAMED_MODULE

using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $Package = ::java::lang::Package;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $Enumeration = ::java::util::Enumeration;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;
using $Stream = ::java::util::stream::Stream;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootLoader$1 = ::jdk::internal::loader::BootLoader$1;
using $BootLoader$PackageHelper = ::jdk::internal::loader::BootLoader$PackageHelper;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $NativeLibraries = ::jdk::internal::loader::NativeLibraries;
using $ServicesCatalog = ::jdk::internal::module::ServicesCatalog;
using $StaticProperty = ::jdk::internal::util::StaticProperty;

namespace jdk {
	namespace internal {
		namespace loader {

class BootLoader$$Lambda$lambda$packages$0 : public $Function {
	$class(BootLoader$$Lambda$lambda$packages$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* name) override {
		 return $of(BootLoader::lambda$packages$0($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<BootLoader$$Lambda$lambda$packages$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo BootLoader$$Lambda$lambda$packages$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BootLoader$$Lambda$lambda$packages$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(BootLoader$$Lambda$lambda$packages$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo BootLoader$$Lambda$lambda$packages$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.BootLoader$$Lambda$lambda$packages$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* BootLoader$$Lambda$lambda$packages$0::load$($String* name, bool initialize) {
	$loadClass(BootLoader$$Lambda$lambda$packages$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* BootLoader$$Lambda$lambda$packages$0::class$ = nullptr;

$FieldInfo _BootLoader_FieldInfo_[] = {
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootLoader, JLA)},
	{"UNNAMED_MODULE", "Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootLoader, UNNAMED_MODULE)},
	{"JAVA_HOME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootLoader, JAVA_HOME)},
	{"CLASS_LOADER_VALUE_MAP", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<**>;", $PRIVATE | $STATIC | $FINAL, $staticField(BootLoader, CLASS_LOADER_VALUE_MAP)},
	{"NATIVE_LIBS", "Ljdk/internal/loader/NativeLibraries;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootLoader, NATIVE_LIBS)},
	{}
};

$MethodInfo _BootLoader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(BootLoader, init$, void)},
	{"definePackage", "(Ljava/lang/Class;)Ljava/lang/Package;", "(Ljava/lang/Class<*>;)Ljava/lang/Package;", $PUBLIC | $STATIC, $staticMethod(BootLoader, definePackage, $Package*, $Class*)},
	{"findResource", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, findResource, $URL*, $String*, $String*), "java.io.IOException"},
	{"findResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, findResource, $URL*, $String*)},
	{"findResourceAsStream", "(Ljava/lang/String;Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, findResourceAsStream, $InputStream*, $String*, $String*), "java.io.IOException"},
	{"findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC | $STATIC, $staticMethod(BootLoader, findResources, $Enumeration*, $String*), "java.io.IOException"},
	{"getClassLoaderValueMap", "()Ljava/util/concurrent/ConcurrentHashMap;", "()Ljava/util/concurrent/ConcurrentHashMap<**>;", $PUBLIC | $STATIC, $staticMethod(BootLoader, getClassLoaderValueMap, $ConcurrentHashMap*)},
	{"getDefinedPackage", "(Ljava/lang/String;)Ljava/lang/Package;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, getDefinedPackage, $Package*, $String*)},
	{"getNativeLibraries", "()Ljdk/internal/loader/NativeLibraries;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, getNativeLibraries, $NativeLibraries*)},
	{"getServicesCatalog", "()Ljdk/internal/module/ServicesCatalog;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, getServicesCatalog, $ServicesCatalog*)},
	{"getSystemPackageLocation", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(BootLoader, getSystemPackageLocation, $String*, $String*)},
	{"getSystemPackageNames", "()[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(BootLoader, getSystemPackageNames, $StringArray*)},
	{"getUnnamedModule", "()Ljava/lang/Module;", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, getUnnamedModule, $Module*)},
	{"hasClassPath", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, hasClassPath, bool)},
	{"lambda$packages$0", "(Ljava/lang/String;)Ljava/lang/Package;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(BootLoader, lambda$packages$0, $Package*, $String*)},
	{"loadClass", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(BootLoader, loadClass, $Class*, $Module*, $String*)},
	{"loadClassOrNull", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(BootLoader, loadClassOrNull, $Class*, $String*)},
	{"loadLibrary", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, loadLibrary, void, $String*)},
	{"loadModule", "(Ljava/lang/module/ModuleReference;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(BootLoader, loadModule, void, $ModuleReference*)},
	{"packages", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Package;>;", $PUBLIC | $STATIC, $staticMethod(BootLoader, packages, $Stream*)},
	{"setBootLoaderUnnamedModule0", "(Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(BootLoader, setBootLoaderUnnamedModule0, void, $Module*)},
	{}
};

#define _METHOD_INDEX_getSystemPackageLocation 10
#define _METHOD_INDEX_getSystemPackageNames 11
#define _METHOD_INDEX_setBootLoaderUnnamedModule0 20

$InnerClassInfo _BootLoader_InnerClassesInfo_[] = {
	{"jdk.internal.loader.BootLoader$PackageHelper", "jdk.internal.loader.BootLoader", "PackageHelper", $STATIC},
	{"jdk.internal.loader.BootLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _BootLoader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.loader.BootLoader",
	"java.lang.Object",
	nullptr,
	_BootLoader_FieldInfo_,
	_BootLoader_MethodInfo_,
	nullptr,
	nullptr,
	_BootLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.loader.BootLoader$PackageHelper,jdk.internal.loader.BootLoader$PackageHelper$2,jdk.internal.loader.BootLoader$PackageHelper$1,jdk.internal.loader.BootLoader$1"
};

$Object* allocate$BootLoader($Class* clazz) {
	return $of($alloc(BootLoader));
}

$JavaLangAccess* BootLoader::JLA = nullptr;
$Module* BootLoader::UNNAMED_MODULE = nullptr;
$String* BootLoader::JAVA_HOME = nullptr;
$ConcurrentHashMap* BootLoader::CLASS_LOADER_VALUE_MAP = nullptr;
$NativeLibraries* BootLoader::NATIVE_LIBS = nullptr;

void BootLoader::init$() {
}

$Module* BootLoader::getUnnamedModule() {
	$init(BootLoader);
	return BootLoader::UNNAMED_MODULE;
}

$ServicesCatalog* BootLoader::getServicesCatalog() {
	$init(BootLoader);
	return $ServicesCatalog::getServicesCatalog($($ClassLoaders::bootLoader()));
}

$ConcurrentHashMap* BootLoader::getClassLoaderValueMap() {
	$init(BootLoader);
	return BootLoader::CLASS_LOADER_VALUE_MAP;
}

$NativeLibraries* BootLoader::getNativeLibraries() {
	$init(BootLoader);
	return BootLoader::NATIVE_LIBS;
}

bool BootLoader::hasClassPath() {
	$init(BootLoader);
	return $nc($($ClassLoaders::bootLoader()))->hasClassPath();
}

void BootLoader::loadModule($ModuleReference* mref) {
	$init(BootLoader);
	$nc($($ClassLoaders::bootLoader()))->loadModule(mref);
}

$Class* BootLoader::loadClassOrNull($String* name) {
	$init(BootLoader);
	return $nc(BootLoader::JLA)->findBootstrapClassOrNull(name);
}

$Class* BootLoader::loadClass($Module* module, $String* name) {
	$init(BootLoader);
	$Class* c = loadClassOrNull(name);
	if (c != nullptr && c->getModule() == module) {
		return c;
	} else {
		return nullptr;
	}
}

void BootLoader::loadLibrary($String* name) {
	$init(BootLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($System::getSecurityManager() == nullptr) {
		$nc($(BootLoader::getNativeLibraries()))->loadLibrary(name);
	} else {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($BootLoader$1, name)));
	}
}

$URL* BootLoader::findResource($String* mn, $String* name) {
	$init(BootLoader);
	return $nc($($ClassLoaders::bootLoader()))->findResource(mn, name);
}

$InputStream* BootLoader::findResourceAsStream($String* mn, $String* name) {
	$init(BootLoader);
	return $nc($($ClassLoaders::bootLoader()))->findResourceAsStream(mn, name);
}

$URL* BootLoader::findResource($String* name) {
	$init(BootLoader);
	return $nc($($ClassLoaders::bootLoader()))->findResource(name);
}

$Enumeration* BootLoader::findResources($String* name) {
	$init(BootLoader);
	return $nc($($ClassLoaders::bootLoader()))->findResources(name);
}

$Package* BootLoader::definePackage($Class* c) {
	$init(BootLoader);
	return getDefinedPackage($($nc(c)->getPackageName()));
}

$Package* BootLoader::getDefinedPackage($String* pn) {
	$init(BootLoader);
	$useLocalCurrentObjectStackCache();
	$var($Package, pkg, $nc($($ClassLoaders::bootLoader()))->getDefinedPackage(pn));
	if (pkg == nullptr) {
		$var($String, location, getSystemPackageLocation($($nc(pn)->replace(u'.', u'/'))));
		if (location != nullptr) {
			$assign(pkg, $BootLoader$PackageHelper::definePackage($($nc(pn)->intern()), location));
		}
	}
	return pkg;
}

$Stream* BootLoader::packages() {
	$init(BootLoader);
	$useLocalCurrentObjectStackCache();
	return $nc($($Arrays::stream($(getSystemPackageNames()))))->map(static_cast<$Function*>($$new(BootLoader$$Lambda$lambda$packages$0)));
}

$StringArray* BootLoader::getSystemPackageNames() {
	$init(BootLoader);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(BootLoader, getSystemPackageNames, $StringArray*);
	$assign($ret, $invokeNativeStaticObject());
	$finishNativeStatic();
	return $ret;
}

$String* BootLoader::getSystemPackageLocation($String* name) {
	$init(BootLoader);
	$var($String, $ret, nullptr);
	$prepareNativeStatic(BootLoader, getSystemPackageLocation, $String*, $String* name);
	$assign($ret, $invokeNativeStaticObject(name));
	$finishNativeStatic();
	return $ret;
}

void BootLoader::setBootLoaderUnnamedModule0($Module* module) {
	$init(BootLoader);
	$prepareNativeStatic(BootLoader, setBootLoaderUnnamedModule0, void, $Module* module);
	$invokeNativeStatic(module);
	$finishNativeStatic();
}

$Package* BootLoader::lambda$packages$0($String* name) {
	$init(BootLoader);
	return getDefinedPackage($($nc(name)->replace(u'/', u'.')));
}

void clinit$BootLoader($Class* class$) {
	$assignStatic(BootLoader::JLA, $SharedSecrets::getJavaLangAccess());
	$assignStatic(BootLoader::JAVA_HOME, $StaticProperty::javaHome());
	{
		$var($JavaLangAccess, jla, $SharedSecrets::getJavaLangAccess());
		$assignStatic(BootLoader::UNNAMED_MODULE, $nc(jla)->defineUnnamedModule(nullptr));
		jla->addEnableNativeAccess(BootLoader::UNNAMED_MODULE);
		BootLoader::setBootLoaderUnnamedModule0(BootLoader::UNNAMED_MODULE);
	}
	$assignStatic(BootLoader::CLASS_LOADER_VALUE_MAP, $new($ConcurrentHashMap));
	$assignStatic(BootLoader::NATIVE_LIBS, $NativeLibraries::jniNativeLibraries(nullptr));
}

BootLoader::BootLoader() {
}

$Class* BootLoader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(BootLoader$$Lambda$lambda$packages$0::classInfo$.name)) {
			return BootLoader$$Lambda$lambda$packages$0::load$(name, initialize);
		}
	}
	$loadClass(BootLoader, name, initialize, &_BootLoader_ClassInfo_, clinit$BootLoader, allocate$BootLoader);
	return class$;
}

$Class* BootLoader::class$ = nullptr;

		} // loader
	} // internal
} // jdk