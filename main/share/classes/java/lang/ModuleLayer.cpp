#include <java/lang/ModuleLayer.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/LayerInstantiationException.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer$Controller.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/security/Permission.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Deque.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/CopyOnWriteArrayList.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/loader/ClassLoaderValue.h>
#include <jdk/internal/loader/Loader.h>
#include <jdk/internal/loader/LoaderPool.h>
#include <jdk/internal/misc/CDS.h>
#include <jdk/internal/module/ServicesCatalog.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef CLV
#undef CREATE_CLASSLOADER_PERMISSION
#undef EMPTY_LAYER
#undef GET_CLASSLOADER_PERMISSION

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $LayerInstantiationException = ::java::lang::LayerInstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer$Controller = ::java::lang::ModuleLayer$Controller;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $Permission = ::java::security::Permission;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Deque = ::java::util::Deque;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $CopyOnWriteArrayList = ::java::util::concurrent::CopyOnWriteArrayList;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $ClassLoaderValue = ::jdk::internal::loader::ClassLoaderValue;
using $Loader = ::jdk::internal::loader::Loader;
using $LoaderPool = ::jdk::internal::loader::LoaderPool;
using $CDS = ::jdk::internal::misc::CDS;
using $ServicesCatalog = ::jdk::internal::module::ServicesCatalog;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {

class ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0 : public $Function {
	$class(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0, $NO_CLASS_INIT, $Function)
public:
	void init$($Loader* loader) {
		$set(this, loader, loader);
	}
	virtual $Object* apply(Object$* mn) override {
		 return $of(ModuleLayer::lambda$defineModulesWithOneLoader$0(loader, $cast($String, mn)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0>());
	}
	$Loader* loader = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::fieldInfos[2] = {
	{"loader", "Ljdk/internal/loader/Loader;", nullptr, $PUBLIC, $field(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0, loader)},
	{}
};
$MethodInfo ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/Loader;)V", nullptr, $PUBLIC, $method(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0, init$, void, $Loader*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::load$($String* name, bool initialize) {
	$loadClass(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::class$ = nullptr;

class ModuleLayer$$Lambda$loaderFor$1 : public $Function {
	$class(ModuleLayer$$Lambda$loaderFor$1, $NO_CLASS_INIT, $Function)
public:
	void init$($LoaderPool* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* name) override {
		 return $of($nc(inst$)->loaderFor($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleLayer$$Lambda$loaderFor$1>());
	}
	$LoaderPool* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleLayer$$Lambda$loaderFor$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModuleLayer$$Lambda$loaderFor$1, inst$)},
	{}
};
$MethodInfo ModuleLayer$$Lambda$loaderFor$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/LoaderPool;)V", nullptr, $PUBLIC, $method(ModuleLayer$$Lambda$loaderFor$1, init$, void, $LoaderPool*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleLayer$$Lambda$loaderFor$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleLayer$$Lambda$loaderFor$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ModuleLayer$$Lambda$loaderFor$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModuleLayer$$Lambda$loaderFor$1::load$($String* name, bool initialize) {
	$loadClass(ModuleLayer$$Lambda$loaderFor$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleLayer$$Lambda$loaderFor$1::class$ = nullptr;

class ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2 : public $Function {
	$class(ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(ModuleLayer::lambda$checkForDuplicatePkgs$1($cast($ClassLoader, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2::load$($String* name, bool initialize) {
	$loadClass(ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2::class$ = nullptr;

class ModuleLayer$$Lambda$lambda$findModule$2$3 : public $Function {
	$class(ModuleLayer$$Lambda$lambda$findModule$2$3, $NO_CLASS_INIT, $Function)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* apply(Object$* l) override {
		 return $of(ModuleLayer::lambda$findModule$2(name, $cast(ModuleLayer, l)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleLayer$$Lambda$lambda$findModule$2$3>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleLayer$$Lambda$lambda$findModule$2$3::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ModuleLayer$$Lambda$lambda$findModule$2$3, name)},
	{}
};
$MethodInfo ModuleLayer$$Lambda$lambda$findModule$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(ModuleLayer$$Lambda$lambda$findModule$2$3, init$, void, $String*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleLayer$$Lambda$lambda$findModule$2$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleLayer$$Lambda$lambda$findModule$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ModuleLayer$$Lambda$lambda$findModule$2$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModuleLayer$$Lambda$lambda$findModule$2$3::load$($String* name, bool initialize) {
	$loadClass(ModuleLayer$$Lambda$lambda$findModule$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleLayer$$Lambda$lambda$findModule$2$3::class$ = nullptr;

class ModuleLayer$$Lambda$nonNull$4 : public $Predicate {
	$class(ModuleLayer$$Lambda$nonNull$4, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* obj) override {
		 return $Objects::nonNull(obj);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleLayer$$Lambda$nonNull$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleLayer$$Lambda$nonNull$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleLayer$$Lambda$nonNull$4, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleLayer$$Lambda$nonNull$4, test, bool, Object$*)},
	{}
};
$ClassInfo ModuleLayer$$Lambda$nonNull$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ModuleLayer$$Lambda$nonNull$4",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* ModuleLayer$$Lambda$nonNull$4::load$($String* name, bool initialize) {
	$loadClass(ModuleLayer$$Lambda$nonNull$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleLayer$$Lambda$nonNull$4::class$ = nullptr;

class ModuleLayer$$Lambda$getName$5 : public $Function {
	$class(ModuleLayer$$Lambda$getName$5, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Module, inst$)->getName());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleLayer$$Lambda$getName$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleLayer$$Lambda$getName$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleLayer$$Lambda$getName$5, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleLayer$$Lambda$getName$5, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleLayer$$Lambda$getName$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ModuleLayer$$Lambda$getName$5",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleLayer$$Lambda$getName$5::load$($String* name, bool initialize) {
	$loadClass(ModuleLayer$$Lambda$getName$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleLayer$$Lambda$getName$5::class$ = nullptr;

$CompoundAttribute _ModuleLayer_FieldAnnotations_EMPTY_LAYER[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _ModuleLayer_FieldInfo_[] = {
	{"EMPTY_LAYER", "Ljava/lang/ModuleLayer;", nullptr, $PRIVATE | $STATIC, $staticField(ModuleLayer, EMPTY_LAYER), _ModuleLayer_FieldAnnotations_EMPTY_LAYER},
	{"cf", "Ljava/lang/module/Configuration;", nullptr, $PRIVATE | $FINAL, $field(ModuleLayer, cf)},
	{"parents", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/ModuleLayer;>;", $PRIVATE | $FINAL, $field(ModuleLayer, parents$)},
	{"nameToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;", $PRIVATE | $FINAL, $field(ModuleLayer, nameToModule)},
	{"allLayers", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/ModuleLayer;>;", $PRIVATE | $VOLATILE, $field(ModuleLayer, allLayers)},
	{"modules", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Module;>;", $PRIVATE | $VOLATILE, $field(ModuleLayer, modules$)},
	{"servicesCatalog", "Ljdk/internal/module/ServicesCatalog;", nullptr, $PRIVATE | $VOLATILE, $field(ModuleLayer, servicesCatalog)},
	{"CLV", "Ljdk/internal/loader/ClassLoaderValue;", "Ljdk/internal/loader/ClassLoaderValue<Ljava/util/List<Ljava/lang/ModuleLayer;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ModuleLayer, CLV)},
	{}
};

$MethodInfo _ModuleLayer_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/module/Configuration;Ljava/util/List;Ljava/util/function/Function;)V", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;)V", $PRIVATE, $method(ModuleLayer, init$, void, $Configuration*, $List*, $Function*)},
	{"bindToLoader", "(Ljava/lang/ClassLoader;)V", nullptr, 0, $method(ModuleLayer, bindToLoader, void, $ClassLoader*)},
	{"boot", "()Ljava/lang/ModuleLayer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleLayer, boot, ModuleLayer*)},
	{"checkConfiguration", "(Ljava/lang/module/Configuration;Ljava/util/List;)V", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;)V", $PRIVATE | $STATIC, $staticMethod(ModuleLayer, checkConfiguration, void, $Configuration*, $List*)},
	{"checkCreateClassLoaderPermission", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleLayer, checkCreateClassLoaderPermission, void)},
	{"checkForDuplicatePkgs", "(Ljava/lang/module/Configuration;Ljava/util/function/Function;)V", "(Ljava/lang/module/Configuration;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;)V", $PRIVATE | $STATIC, $staticMethod(ModuleLayer, checkForDuplicatePkgs, void, $Configuration*, $Function*)},
	{"checkGetClassLoaderPermission", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleLayer, checkGetClassLoaderPermission, void)},
	{"configuration", "()Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $method(ModuleLayer, configuration, $Configuration*)},
	{"defineModules", "(Ljava/lang/module/Configuration;Ljava/util/function/Function;)Ljava/lang/ModuleLayer;", "(Ljava/lang/module/Configuration;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;)Ljava/lang/ModuleLayer;", $PUBLIC, $method(ModuleLayer, defineModules, ModuleLayer*, $Configuration*, $Function*)},
	{"defineModules", "(Ljava/lang/module/Configuration;Ljava/util/List;Ljava/util/function/Function;)Ljava/lang/ModuleLayer$Controller;", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;)Ljava/lang/ModuleLayer$Controller;", $PUBLIC | $STATIC, $staticMethod(ModuleLayer, defineModules, $ModuleLayer$Controller*, $Configuration*, $List*, $Function*)},
	{"defineModulesWithManyLoaders", "(Ljava/lang/module/Configuration;Ljava/lang/ClassLoader;)Ljava/lang/ModuleLayer;", nullptr, $PUBLIC, $method(ModuleLayer, defineModulesWithManyLoaders, ModuleLayer*, $Configuration*, $ClassLoader*)},
	{"defineModulesWithManyLoaders", "(Ljava/lang/module/Configuration;Ljava/util/List;Ljava/lang/ClassLoader;)Ljava/lang/ModuleLayer$Controller;", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;Ljava/lang/ClassLoader;)Ljava/lang/ModuleLayer$Controller;", $PUBLIC | $STATIC, $staticMethod(ModuleLayer, defineModulesWithManyLoaders, $ModuleLayer$Controller*, $Configuration*, $List*, $ClassLoader*)},
	{"defineModulesWithOneLoader", "(Ljava/lang/module/Configuration;Ljava/lang/ClassLoader;)Ljava/lang/ModuleLayer;", nullptr, $PUBLIC, $method(ModuleLayer, defineModulesWithOneLoader, ModuleLayer*, $Configuration*, $ClassLoader*)},
	{"defineModulesWithOneLoader", "(Ljava/lang/module/Configuration;Ljava/util/List;Ljava/lang/ClassLoader;)Ljava/lang/ModuleLayer$Controller;", "(Ljava/lang/module/Configuration;Ljava/util/List<Ljava/lang/ModuleLayer;>;Ljava/lang/ClassLoader;)Ljava/lang/ModuleLayer$Controller;", $PUBLIC | $STATIC, $staticMethod(ModuleLayer, defineModulesWithOneLoader, $ModuleLayer$Controller*, $Configuration*, $List*, $ClassLoader*)},
	{"empty", "()Ljava/lang/ModuleLayer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleLayer, empty, ModuleLayer*)},
	{"fail", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/LayerInstantiationException;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(ModuleLayer, fail, $LayerInstantiationException*, $String*, $ObjectArray*)},
	{"findLoader", "(Ljava/lang/String;)Ljava/lang/ClassLoader;", nullptr, $PUBLIC, $method(ModuleLayer, findLoader, $ClassLoader*, $String*)},
	{"findModule", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/Module;>;", $PUBLIC, $method(ModuleLayer, findModule, $Optional*, $String*)},
	{"getServicesCatalog", "()Ljdk/internal/module/ServicesCatalog;", nullptr, 0, $method(ModuleLayer, getServicesCatalog, $ServicesCatalog*)},
	{"lambda$checkForDuplicatePkgs$1", "(Ljava/lang/ClassLoader;)Ljava/util/Set;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleLayer, lambda$checkForDuplicatePkgs$1, $Set*, $ClassLoader*)},
	{"lambda$defineModulesWithOneLoader$0", "(Ljdk/internal/loader/Loader;Ljava/lang/String;)Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleLayer, lambda$defineModulesWithOneLoader$0, $ClassLoader*, $Loader*, $String*)},
	{"lambda$findModule$2", "(Ljava/lang/String;Ljava/lang/ModuleLayer;)Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleLayer, lambda$findModule$2, $Module*, $String*, ModuleLayer*)},
	{"layers", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/ModuleLayer;>;", 0, $method(ModuleLayer, layers, $Stream*)},
	{"layers", "(Ljava/lang/ClassLoader;)Ljava/util/stream/Stream;", "(Ljava/lang/ClassLoader;)Ljava/util/stream/Stream<Ljava/lang/ModuleLayer;>;", $STATIC, $staticMethod(ModuleLayer, layers, $Stream*, $ClassLoader*)},
	{"modules", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/Module;>;", $PUBLIC, $method(ModuleLayer, modules, $Set*)},
	{"parents", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/ModuleLayer;>;", $PUBLIC, $method(ModuleLayer, parents, $List*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ModuleLayer, toString, $String*)},
	{}
};

$InnerClassInfo _ModuleLayer_InnerClassesInfo_[] = {
	{"java.lang.ModuleLayer$Controller", "java.lang.ModuleLayer", "Controller", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ModuleLayer_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.ModuleLayer",
	"java.lang.Object",
	nullptr,
	_ModuleLayer_FieldInfo_,
	_ModuleLayer_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleLayer_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.ModuleLayer$Controller"
};

$Object* allocate$ModuleLayer($Class* clazz) {
	return $of($alloc(ModuleLayer));
}

ModuleLayer* ModuleLayer::EMPTY_LAYER = nullptr;
$ClassLoaderValue* ModuleLayer::CLV = nullptr;

void ModuleLayer::init$($Configuration* cf, $List* parents, $Function* clf) {
	$set(this, cf, cf);
	$set(this, parents$, parents);
	$var($Map, map, nullptr);
	if ($nc(parents)->isEmpty()) {
		$assign(map, $Map::of());
	} else {
		$assign(map, $Module::defineModules(cf, clf, this));
	}
	$set(this, nameToModule, map);
}

ModuleLayer* ModuleLayer::defineModulesWithOneLoader($Configuration* cf, $ClassLoader* parentLoader) {
	$useLocalCurrentObjectStackCache();
	return $nc($(defineModulesWithOneLoader(cf, $($List::of($of(this))), parentLoader)))->layer();
}

ModuleLayer* ModuleLayer::defineModulesWithManyLoaders($Configuration* cf, $ClassLoader* parentLoader) {
	$useLocalCurrentObjectStackCache();
	return $nc($(defineModulesWithManyLoaders(cf, $($List::of($of(this))), parentLoader)))->layer();
}

ModuleLayer* ModuleLayer::defineModules($Configuration* cf, $Function* clf) {
	$useLocalCurrentObjectStackCache();
	return $nc($(defineModules(cf, $($List::of($of(this))), clf)))->layer();
}

$ModuleLayer$Controller* ModuleLayer::defineModulesWithOneLoader($Configuration* cf, $List* parentLayers, $ClassLoader* parentLoader) {
	$init(ModuleLayer);
	$useLocalCurrentObjectStackCache();
	$var($List, parents, $List::copyOf(parentLayers));
	checkConfiguration(cf, parents);
	checkCreateClassLoaderPermission();
	checkGetClassLoaderPermission();
	try {
		$var($Loader, loader, $new($Loader, $($nc(cf)->modules()), parentLoader));
		loader->initRemotePackageMap(cf, parents);
		$var(ModuleLayer, layer, $new(ModuleLayer, cf, parents, static_cast<$Function*>($$new(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0, loader))));
		return $new($ModuleLayer$Controller, layer);
	} catch ($IllegalArgumentException& e) {
		$throwNew($LayerInstantiationException, $(e->getMessage()));
	} catch ($IllegalStateException& e) {
		$throwNew($LayerInstantiationException, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

$ModuleLayer$Controller* ModuleLayer::defineModulesWithManyLoaders($Configuration* cf, $List* parentLayers, $ClassLoader* parentLoader) {
	$init(ModuleLayer);
	$useLocalCurrentObjectStackCache();
	$var($List, parents, $List::copyOf(parentLayers));
	checkConfiguration(cf, parents);
	checkCreateClassLoaderPermission();
	checkGetClassLoaderPermission();
	$var($LoaderPool, pool, $new($LoaderPool, cf, parents, parentLoader));
	try {
		$var(ModuleLayer, layer, $new(ModuleLayer, cf, parents, static_cast<$Function*>($$new(ModuleLayer$$Lambda$loaderFor$1, static_cast<$LoaderPool*>(pool)))));
		return $new($ModuleLayer$Controller, layer);
	} catch ($IllegalArgumentException& e) {
		$throwNew($LayerInstantiationException, $(e->getMessage()));
	} catch ($IllegalStateException& e) {
		$throwNew($LayerInstantiationException, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

$ModuleLayer$Controller* ModuleLayer::defineModules($Configuration* cf, $List* parentLayers, $Function* clf) {
	$init(ModuleLayer);
	$useLocalCurrentObjectStackCache();
	$var($List, parents, $List::copyOf(parentLayers));
	checkConfiguration(cf, parents);
	$Objects::requireNonNull(clf);
	checkGetClassLoaderPermission();
	if (boot() != nullptr) {
		checkForDuplicatePkgs(cf, clf);
	}
	try {
		$var(ModuleLayer, layer, $new(ModuleLayer, cf, parents, clf));
		return $new($ModuleLayer$Controller, layer);
	} catch ($IllegalArgumentException& e) {
		$throwNew($LayerInstantiationException, $(e->getMessage()));
	} catch ($IllegalStateException& e) {
		$throwNew($LayerInstantiationException, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

void ModuleLayer::checkConfiguration($Configuration* cf, $List* parentLayers) {
	$init(ModuleLayer);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(cf);
	$var($List, parentConfigurations, cf->parents());
	int32_t var$0 = $nc(parentLayers)->size();
	if (var$0 != $nc(parentConfigurations)->size()) {
		$throwNew($IllegalArgumentException, "wrong number of parents"_s);
	}
	int32_t index = 0;
	{
		$var($Iterator, i$, $nc(parentLayers)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(ModuleLayer, parent, $cast(ModuleLayer, i$->next()));
			{
				if (!$equals($nc(parent)->configuration(), $nc(parentConfigurations)->get(index))) {
					$throwNew($IllegalArgumentException, "Parent of configuration != configuration of this Layer"_s);
				}
				++index;
			}
		}
	}
}

void ModuleLayer::checkCreateClassLoaderPermission() {
	$init(ModuleLayer);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::CREATE_CLASSLOADER_PERMISSION);
	}
}

void ModuleLayer::checkGetClassLoaderPermission() {
	$init(ModuleLayer);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
	}
}

void ModuleLayer::checkForDuplicatePkgs($Configuration* cf, $Function* clf) {
	$init(ModuleLayer);
	$useLocalCurrentObjectStackCache();
	$var($Map, loaderToPackages, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc(cf)->modules()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				$var($ModuleDescriptor, descriptor, $nc($($nc(resolvedModule)->reference()))->descriptor());
				$var($ClassLoader, loader, $cast($ClassLoader, $nc(clf)->apply($($nc(descriptor)->name()))));
				$var($Set, loaderPackages, $cast($Set, loaderToPackages->computeIfAbsent(loader, static_cast<$Function*>($$new(ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2)))));
				{
					$var($Iterator, i$, $nc($($nc(descriptor)->packages()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, pkg, $cast($String, i$->next()));
						{
							bool added = $nc(loaderPackages)->add(pkg);
							if (!added) {
								$throw($(fail("More than one module with package %s mapped to the same class loader"_s, $$new($ObjectArray, {$of(pkg)}))));
							}
						}
					}
				}
			}
		}
	}
}

$LayerInstantiationException* ModuleLayer::fail($String* fmt, $ObjectArray* args) {
	$init(ModuleLayer);
	$var($String, msg, $String::format(fmt, args));
	return $new($LayerInstantiationException, msg);
}

$Configuration* ModuleLayer::configuration() {
	return this->cf;
}

$List* ModuleLayer::parents() {
	return this->parents$;
}

$Stream* ModuleLayer::layers() {
	$useLocalCurrentObjectStackCache();
	$var($List, allLayers, this->allLayers);
	if (allLayers != nullptr) {
		return allLayers->stream();
	}
	$assign(allLayers, $new($ArrayList));
	$var($Set, visited, $new($HashSet));
	$var($Deque, stack, $new($ArrayDeque));
	visited->add(this);
	stack->push(this);
	while (!stack->isEmpty()) {
		$var(ModuleLayer, layer, $cast(ModuleLayer, stack->pop()));
		allLayers->add(layer);
		for (int32_t i = $nc($nc(layer)->parents$)->size() - 1; i >= 0; --i) {
			$var(ModuleLayer, parent, $cast(ModuleLayer, $nc(layer->parents$)->get(i)));
			if (visited->add(parent)) {
				stack->push(parent);
			}
		}
	}
	$set(this, allLayers, ($assign(allLayers, $Collections::unmodifiableList(allLayers))));
	return $nc(allLayers)->stream();
}

$Set* ModuleLayer::modules() {
	$useLocalCurrentObjectStackCache();
	$var($Set, modules, this->modules$);
	if (modules == nullptr) {
		$set(this, modules$, ($assign(modules, $Set::copyOf($($nc(this->nameToModule)->values())))));
	}
	return modules;
}

$Optional* ModuleLayer::findModule($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (this == ModuleLayer::EMPTY_LAYER) {
		return $Optional::empty();
	}
	$var($Module, m, $cast($Module, $nc(this->nameToModule)->get(name)));
	if (m != nullptr) {
		return $Optional::of(m);
	}
	return $nc($($nc($($nc($($nc($(layers()))->skip(1)))->map(static_cast<$Function*>($$new(ModuleLayer$$Lambda$lambda$findModule$2$3, name)))))->filter(static_cast<$Predicate*>($$new(ModuleLayer$$Lambda$nonNull$4)))))->findAny();
}

$ClassLoader* ModuleLayer::findLoader($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Optional, om, findModule(name));
	if ($nc(om)->isPresent()) {
		return $nc(($cast($Module, $(om->get()))))->getClassLoader();
	} else {
		$throwNew($IllegalArgumentException, $$str({"Module "_s, name, " not known to this layer"_s}));
	}
}

$String* ModuleLayer::toString() {
	$useLocalCurrentObjectStackCache();
	return $cast($String, $nc($($nc($($nc($(modules()))->stream()))->map(static_cast<$Function*>($$new(ModuleLayer$$Lambda$getName$5)))))->collect($($Collectors::joining(", "_s))));
}

ModuleLayer* ModuleLayer::empty() {
	$init(ModuleLayer);
	return ModuleLayer::EMPTY_LAYER;
}

ModuleLayer* ModuleLayer::boot() {
	$init(ModuleLayer);
	return $System::bootLayer;
}

$ServicesCatalog* ModuleLayer::getServicesCatalog() {
	$useLocalCurrentObjectStackCache();
	$var($ServicesCatalog, servicesCatalog, this->servicesCatalog);
	if (servicesCatalog != nullptr) {
		return servicesCatalog;
	}
	$synchronized(this) {
		$assign(servicesCatalog, this->servicesCatalog);
		if (servicesCatalog == nullptr) {
			$assign(servicesCatalog, $ServicesCatalog::create());
			{
				$var($Iterator, i$, $nc($($nc(this->nameToModule)->values()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Module, m, $cast($Module, i$->next()));
					{
						$nc(servicesCatalog)->register$(m);
					}
				}
			}
			$set(this, servicesCatalog, servicesCatalog);
		}
	}
	return servicesCatalog;
}

void ModuleLayer::bindToLoader($ClassLoader* loader) {
	$useLocalCurrentObjectStackCache();
	$var($List, list, $cast($List, $nc(ModuleLayer::CLV)->get(loader)));
	if (list == nullptr) {
		$assign(list, $new($CopyOnWriteArrayList));
		$var($List, previous, $cast($List, $nc(ModuleLayer::CLV)->putIfAbsent(loader, list)));
		if (previous != nullptr) {
			$assign(list, previous);
		}
	}
	$nc(list)->add(this);
}

$Stream* ModuleLayer::layers($ClassLoader* loader) {
	$init(ModuleLayer);
	$var($List, list, $cast($List, $nc(ModuleLayer::CLV)->get(loader)));
	if (list != nullptr) {
		return list->stream();
	} else {
		return $Stream::empty();
	}
}

$Module* ModuleLayer::lambda$findModule$2($String* name, ModuleLayer* l) {
	$init(ModuleLayer);
	return $cast($Module, $nc($nc(l)->nameToModule)->get(name));
}

$Set* ModuleLayer::lambda$checkForDuplicatePkgs$1($ClassLoader* k) {
	$init(ModuleLayer);
	return $new($HashSet);
}

$ClassLoader* ModuleLayer::lambda$defineModulesWithOneLoader$0($Loader* loader, $String* mn) {
	$init(ModuleLayer);
	return loader;
}

void clinit$ModuleLayer($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$CDS::initializeFromArchive(ModuleLayer::class$);
		if (ModuleLayer::EMPTY_LAYER == nullptr) {
			$var($Configuration, var$0, $Configuration::empty());
			$assignStatic(ModuleLayer::EMPTY_LAYER, $new(ModuleLayer, var$0, $($List::of()), nullptr));
		}
	}
	$assignStatic(ModuleLayer::CLV, $new($ClassLoaderValue));
}

ModuleLayer::ModuleLayer() {
}

$Class* ModuleLayer::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::classInfo$.name)) {
			return ModuleLayer$$Lambda$lambda$defineModulesWithOneLoader$0::load$(name, initialize);
		}
		if (name->equals(ModuleLayer$$Lambda$loaderFor$1::classInfo$.name)) {
			return ModuleLayer$$Lambda$loaderFor$1::load$(name, initialize);
		}
		if (name->equals(ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2::classInfo$.name)) {
			return ModuleLayer$$Lambda$lambda$checkForDuplicatePkgs$1$2::load$(name, initialize);
		}
		if (name->equals(ModuleLayer$$Lambda$lambda$findModule$2$3::classInfo$.name)) {
			return ModuleLayer$$Lambda$lambda$findModule$2$3::load$(name, initialize);
		}
		if (name->equals(ModuleLayer$$Lambda$nonNull$4::classInfo$.name)) {
			return ModuleLayer$$Lambda$nonNull$4::load$(name, initialize);
		}
		if (name->equals(ModuleLayer$$Lambda$getName$5::classInfo$.name)) {
			return ModuleLayer$$Lambda$getName$5::load$(name, initialize);
		}
	}
	$loadClass(ModuleLayer, name, initialize, &_ModuleLayer_ClassInfo_, clinit$ModuleLayer, allocate$ModuleLayer);
	return class$;
}

$Class* ModuleLayer::class$ = nullptr;

	} // lang
} // java