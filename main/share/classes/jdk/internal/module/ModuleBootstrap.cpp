#include <jdk/internal/module/ModuleBootstrap.h>

#include <java/io/File.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/InternalError.h>
#include <java/lang/LayerInstantiationException.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleFinder.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/net/URI.h>
#include <java/nio/file/Path.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/JavaLangModuleAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/misc/CDS.h>
#include <jdk/internal/module/ArchivedBootLayer.h>
#include <jdk/internal/module/ArchivedModuleGraph.h>
#include <jdk/internal/module/DefaultRoots.h>
#include <jdk/internal/module/ExplodedSystemModules.h>
#include <jdk/internal/module/ModuleBootstrap$1.h>
#include <jdk/internal/module/ModuleBootstrap$Counters.h>
#include <jdk/internal/module/ModuleBootstrap$SafeModuleFinder.h>
#include <jdk/internal/module/ModuleLoaderMap.h>
#include <jdk/internal/module/ModulePatcher.h>
#include <jdk/internal/module/ModulePath.h>
#include <jdk/internal/module/ModulePathValidator.h>
#include <jdk/internal/module/ModuleResolution.h>
#include <jdk/internal/module/Modules.h>
#include <jdk/internal/module/SystemModuleFinders.h>
#include <jdk/internal/module/SystemModules.h>
#include <jcpp.h>

#undef ADD_EXPORTS
#undef ADD_MODULES
#undef ADD_OPENS
#undef ADD_READS
#undef ALL_DEFAULT
#undef ALL_MODULE_PATH
#undef ALL_SYSTEM
#undef ALL_UNNAMED
#undef ENABLE_NATIVE_ACCESS
#undef JAVA_BASE
#undef JLA
#undef JLMA
#undef PATCH_MODULE

using $ModuleFinderArray = $Array<::java::lang::module::ModuleFinder>;
using $PathArray = $Array<::java::nio::file::Path>;
using $File = ::java::io::File;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $LayerInstantiationException = ::java::lang::LayerInstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleFinder = ::java::lang::module::ModuleFinder;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $URI = ::java::net::URI;
using $Path = ::java::nio::file::Path;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Optional = ::java::util::Optional;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $JavaLangModuleAccess = ::jdk::internal::access::JavaLangModuleAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $CDS = ::jdk::internal::misc::CDS;
using $ArchivedBootLayer = ::jdk::internal::module::ArchivedBootLayer;
using $ArchivedModuleGraph = ::jdk::internal::module::ArchivedModuleGraph;
using $DefaultRoots = ::jdk::internal::module::DefaultRoots;
using $ExplodedSystemModules = ::jdk::internal::module::ExplodedSystemModules;
using $ModuleBootstrap$1 = ::jdk::internal::module::ModuleBootstrap$1;
using $ModuleBootstrap$Counters = ::jdk::internal::module::ModuleBootstrap$Counters;
using $ModuleBootstrap$SafeModuleFinder = ::jdk::internal::module::ModuleBootstrap$SafeModuleFinder;
using $ModuleLoaderMap = ::jdk::internal::module::ModuleLoaderMap;
using $ModulePatcher = ::jdk::internal::module::ModulePatcher;
using $ModulePath = ::jdk::internal::module::ModulePath;
using $ModulePathValidator = ::jdk::internal::module::ModulePathValidator;
using $ModuleResolution = ::jdk::internal::module::ModuleResolution;
using $Modules = ::jdk::internal::module::Modules;
using $SystemModuleFinders = ::jdk::internal::module::SystemModuleFinders;
using $SystemModules = ::jdk::internal::module::SystemModules;

namespace jdk {
	namespace internal {
		namespace module {

class ModuleBootstrap$$Lambda$descriptor : public $Function {
	$class(ModuleBootstrap$$Lambda$descriptor, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleReference, inst$)->descriptor());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$descriptor>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleBootstrap$$Lambda$descriptor::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$descriptor, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$descriptor, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$descriptor::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$descriptor",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$descriptor::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$descriptor, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$descriptor::class$ = nullptr;

class ModuleBootstrap$$Lambda$name$1 : public $Function {
	$class(ModuleBootstrap$$Lambda$name$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ModuleDescriptor, inst$)->name());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$name$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleBootstrap$$Lambda$name$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$name$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$name$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$name$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$name$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$name$1::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$name$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$name$1::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$boot2$0$2 : public $Predicate {
	$class(ModuleBootstrap$$Lambda$lambda$boot2$0$2, $NO_CLASS_INIT, $Predicate)
public:
	void init$($ModuleFinder* f) {
		$set(this, f, f);
	}
	virtual bool test(Object$* mn) override {
		 return ModuleBootstrap::lambda$boot2$0(f, $cast($String, mn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$boot2$0$2>());
	}
	$ModuleFinder* f = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleBootstrap$$Lambda$lambda$boot2$0$2::fieldInfos[2] = {
	{"f", "Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC, $field(ModuleBootstrap$$Lambda$lambda$boot2$0$2, f)},
	{}
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$boot2$0$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleFinder;)V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$boot2$0$2, init$, void, $ModuleFinder*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$boot2$0$2, test, bool, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$boot2$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$boot2$0$2",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$boot2$0$2::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$boot2$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$boot2$0$2::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$boot2$1$3 : public $Consumer {
	$class(ModuleBootstrap$$Lambda$lambda$boot2$1$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Set* roots) {
		$set(this, roots, roots);
	}
	virtual void accept(Object$* mn) override {
		ModuleBootstrap::lambda$boot2$1(roots, $cast($String, mn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$boot2$1$3>());
	}
	$Set* roots = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleBootstrap$$Lambda$lambda$boot2$1$3::fieldInfos[2] = {
	{"roots", "Ljava/util/Set;", nullptr, $PUBLIC, $field(ModuleBootstrap$$Lambda$lambda$boot2$1$3, roots)},
	{}
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$boot2$1$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$boot2$1$3, init$, void, $Set*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$boot2$1$3, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$boot2$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$boot2$1$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$boot2$1$3::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$boot2$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$boot2$1$3::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$boot2$4$4 : public $Predicate {
	$class(ModuleBootstrap$$Lambda$lambda$boot2$4$4, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Configuration* cf) {
		$set(this, cf, cf);
	}
	virtual bool test(Object$* mn) override {
		 return ModuleBootstrap::lambda$boot2$4(cf, $cast($String, mn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$boot2$4$4>());
	}
	$Configuration* cf = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleBootstrap$$Lambda$lambda$boot2$4$4::fieldInfos[2] = {
	{"cf", "Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $field(ModuleBootstrap$$Lambda$lambda$boot2$4$4, cf)},
	{}
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$boot2$4$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Configuration;)V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$boot2$4$4, init$, void, $Configuration*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$boot2$4$4, test, bool, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$boot2$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$boot2$4$4",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$boot2$4$4::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$boot2$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$boot2$4$4::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$boot2$5$5 : public $Consumer {
	$class(ModuleBootstrap$$Lambda$lambda$boot2$5$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* mn) override {
		ModuleBootstrap::lambda$boot2$5($cast($String, mn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$boot2$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$boot2$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$boot2$5$5, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$boot2$5$5, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$boot2$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$boot2$5$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$boot2$5$5::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$boot2$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$boot2$5$5::class$ = nullptr;

class ModuleBootstrap$$Lambda$reference$6 : public $Function {
	$class(ModuleBootstrap$$Lambda$reference$6, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($ResolvedModule, inst$)->reference());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$reference$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleBootstrap$$Lambda$reference$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$reference$6, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$reference$6, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$reference$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$reference$6",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$reference$6::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$reference$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$reference$6::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$limitFinder$6$7 : public $Consumer {
	$class(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Map* map) {
		$set(this, map, map);
	}
	virtual void accept(Object$* mref) override {
		ModuleBootstrap::lambda$limitFinder$6(map, $cast($ModuleReference, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$limitFinder$6$7>());
	}
	$Map* map = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::fieldInfos[2] = {
	{"map", "Ljava/util/Map;", nullptr, $PUBLIC, $field(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7, map)},
	{}
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::methodInfos[3] = {
	{"<init>", "(Ljava/util/Map;)V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7, init$, void, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$limitFinder$6$7",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::class$ = nullptr;

class ModuleBootstrap$$Lambda$find$8 : public $Function {
	$class(ModuleBootstrap$$Lambda$find$8, $NO_CLASS_INIT, $Function)
public:
	void init$($ModuleFinder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* name) override {
		 return $of($nc(inst$)->find($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$find$8>());
	}
	$ModuleFinder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleBootstrap$$Lambda$find$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ModuleBootstrap$$Lambda$find$8, inst$)},
	{}
};
$MethodInfo ModuleBootstrap$$Lambda$find$8::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/ModuleFinder;)V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$find$8, init$, void, $ModuleFinder*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$find$8, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$find$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$find$8",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$find$8::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$find$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$find$8::class$ = nullptr;

class ModuleBootstrap$$Lambda$stream$9 : public $Function {
	$class(ModuleBootstrap$$Lambda$stream$9, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Optional, inst$)->stream());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$stream$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleBootstrap$$Lambda$stream$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$stream$9, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$stream$9, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$stream$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$stream$9",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$stream$9::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$stream$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$stream$9::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$limitFinder$7$10 : public $Consumer {
	$class(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Map* map) {
		$set(this, map, map);
	}
	virtual void accept(Object$* mref) override {
		ModuleBootstrap::lambda$limitFinder$7(map, $cast($ModuleReference, mref));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$limitFinder$7$10>());
	}
	$Map* map = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::fieldInfos[2] = {
	{"map", "Ljava/util/Map;", nullptr, $PUBLIC, $field(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10, map)},
	{}
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::methodInfos[3] = {
	{"<init>", "(Ljava/util/Map;)V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10, init$, void, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$limitFinder$7$10",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::class$ = nullptr;

class ModuleBootstrap$$Lambda$lambda$decode$8$11 : public $Function {
	$class(ModuleBootstrap$$Lambda$lambda$decode$8$11, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(ModuleBootstrap::lambda$decode$8($cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleBootstrap$$Lambda$lambda$decode$8$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ModuleBootstrap$$Lambda$lambda$decode$8$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleBootstrap$$Lambda$lambda$decode$8$11, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ModuleBootstrap$$Lambda$lambda$decode$8$11, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ModuleBootstrap$$Lambda$lambda$decode$8$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleBootstrap$$Lambda$lambda$decode$8$11",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ModuleBootstrap$$Lambda$lambda$decode$8$11::load$($String* name, bool initialize) {
	$loadClass(ModuleBootstrap$$Lambda$lambda$decode$8$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleBootstrap$$Lambda$lambda$decode$8$11::class$ = nullptr;

$FieldInfo _ModuleBootstrap_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ModuleBootstrap, $assertionsDisabled)},
	{"JAVA_BASE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, JAVA_BASE)},
	{"ALL_DEFAULT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ALL_DEFAULT)},
	{"ALL_UNNAMED", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ALL_UNNAMED)},
	{"ALL_SYSTEM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ALL_SYSTEM)},
	{"ALL_MODULE_PATH", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ALL_MODULE_PATH)},
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, JLA)},
	{"JLMA", "Ljdk/internal/access/JavaLangModuleAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, JLMA)},
	{"patcher", "Ljdk/internal/module/ModulePatcher;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, patcher$)},
	{"unlimitedFinder", "Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(ModuleBootstrap, unlimitedFinder$)},
	{"limitedFinder", "Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(ModuleBootstrap, limitedFinder$)},
	{"ADD_MODULES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ADD_MODULES)},
	{"ADD_EXPORTS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ADD_EXPORTS)},
	{"ADD_OPENS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ADD_OPENS)},
	{"ADD_READS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ADD_READS)},
	{"PATCH_MODULE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, PATCH_MODULE)},
	{"ENABLE_NATIVE_ACCESS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleBootstrap, ENABLE_NATIVE_ACCESS)},
	{}
};

$MethodInfo _ModuleBootstrap_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ModuleBootstrap, init$, void)},
	{"addEnableNativeAccess", "(Ljava/lang/ModuleLayer;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, addEnableNativeAccess, void, $ModuleLayer*)},
	{"addExtraExportsAndOpens", "(Ljava/lang/ModuleLayer;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, addExtraExportsAndOpens, bool, $ModuleLayer*)},
	{"addExtraExportsOrOpens", "(Ljava/lang/ModuleLayer;Ljava/util/Map;Z)V", "(Ljava/lang/ModuleLayer;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;Z)V", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, addExtraExportsOrOpens, void, $ModuleLayer*, $Map*, bool)},
	{"addExtraReads", "(Ljava/lang/ModuleLayer;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, addExtraReads, void, $ModuleLayer*)},
	{"addModules", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, addModules, $Set*)},
	{"boot", "()Ljava/lang/ModuleLayer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleBootstrap, boot, $ModuleLayer*)},
	{"boot2", "()Ljava/lang/ModuleLayer;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, boot2, $ModuleLayer*)},
	{"canUseArchivedBootLayer", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, canUseArchivedBootLayer, bool)},
	{"checkIncubatingStatus", "(Ljava/lang/module/Configuration;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, checkIncubatingStatus, void, $Configuration*)},
	{"checkSplitPackages", "(Ljava/lang/module/Configuration;Ljava/util/function/Function;)V", "(Ljava/lang/module/Configuration;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;)V", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, checkSplitPackages, void, $Configuration*, $Function*)},
	{"decode", "(Ljava/lang/String;Ljava/lang/String;Z)Ljava/util/Map;", "(Ljava/lang/String;Ljava/lang/String;Z)Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, decode, $Map*, $String*, $String*, bool)},
	{"decode", "(Ljava/lang/String;)Ljava/util/Map;", "(Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, decode, $Map*, $String*)},
	{"decodeEnableNativeAccess", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, decodeEnableNativeAccess, $Set*)},
	{"fail", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(ModuleBootstrap, fail, void, $String*)},
	{"finderFor", "(Ljava/lang/String;)Ljava/lang/module/ModuleFinder;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, finderFor, $ModuleFinder*, $String*)},
	{"getAndRemoveProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, getAndRemoveProperty, $String*, $String*)},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, getProperty, $String*, $String*)},
	{"initModulePatcher", "()Ljdk/internal/module/ModulePatcher;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, initModulePatcher, $ModulePatcher*)},
	{"lambda$boot2$0", "(Ljava/lang/module/ModuleFinder;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$boot2$0, bool, $ModuleFinder*, $String*)},
	{"lambda$boot2$1", "(Ljava/util/Set;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$boot2$1, void, $Set*, $String*)},
	{"lambda$boot2$4", "(Ljava/lang/module/Configuration;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$boot2$4, bool, $Configuration*, $String*)},
	{"lambda$boot2$5", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$boot2$5, void, $String*)},
	{"lambda$decode$8", "(Ljava/lang/String;)Ljava/util/List;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$decode$8, $List*, $String*)},
	{"lambda$limitFinder$6", "(Ljava/util/Map;Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$limitFinder$6, void, $Map*, $ModuleReference*)},
	{"lambda$limitFinder$7", "(Ljava/util/Map;Ljava/lang/module/ModuleReference;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleBootstrap, lambda$limitFinder$7, void, $Map*, $ModuleReference*)},
	{"limitFinder", "(Ljava/lang/module/ModuleFinder;Ljava/util/Set;Ljava/util/Set;)Ljava/lang/module/ModuleFinder;", "(Ljava/lang/module/ModuleFinder;Ljava/util/Set<Ljava/lang/String;>;Ljava/util/Set<Ljava/lang/String;>;)Ljava/lang/module/ModuleFinder;", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, limitFinder, $ModuleFinder*, $ModuleFinder*, $Set*, $Set*)},
	{"limitModules", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, limitModules, $Set*)},
	{"limitedFinder", "()Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleBootstrap, limitedFinder, $ModuleFinder*)},
	{"loadModules", "(Ljava/lang/module/Configuration;Ljava/util/function/Function;)V", "(Ljava/lang/module/Configuration;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;)V", $PRIVATE | $STATIC, $staticMethod(ModuleBootstrap, loadModules, void, $Configuration*, $Function*)},
	{"option", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ModuleBootstrap, option, $String*, $String*)},
	{"patcher", "()Ljdk/internal/module/ModulePatcher;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleBootstrap, patcher, $ModulePatcher*)},
	{"unableToParse", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ModuleBootstrap, unableToParse, $String*, $String*, $String*, $String*)},
	{"unlimitedFinder", "()Ljava/lang/module/ModuleFinder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleBootstrap, unlimitedFinder, $ModuleFinder*)},
	{"warn", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(ModuleBootstrap, warn, void, $String*)},
	{"warnUnknownModule", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(ModuleBootstrap, warnUnknownModule, void, $String*, $String*)},
	{}
};

$InnerClassInfo _ModuleBootstrap_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModuleBootstrap$Counters", "jdk.internal.module.ModuleBootstrap", "Counters", $STATIC},
	{"jdk.internal.module.ModuleBootstrap$SafeModuleFinder", "jdk.internal.module.ModuleBootstrap", "SafeModuleFinder", $STATIC},
	{"jdk.internal.module.ModuleBootstrap$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ModuleBootstrap_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.module.ModuleBootstrap",
	"java.lang.Object",
	nullptr,
	_ModuleBootstrap_FieldInfo_,
	_ModuleBootstrap_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleBootstrap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.ModuleBootstrap$Counters,jdk.internal.module.ModuleBootstrap$SafeModuleFinder,jdk.internal.module.ModuleBootstrap$1"
};

$Object* allocate$ModuleBootstrap($Class* clazz) {
	return $of($alloc(ModuleBootstrap));
}

bool ModuleBootstrap::$assertionsDisabled = false;
$String* ModuleBootstrap::JAVA_BASE = nullptr;
$String* ModuleBootstrap::ALL_DEFAULT = nullptr;
$String* ModuleBootstrap::ALL_UNNAMED = nullptr;
$String* ModuleBootstrap::ALL_SYSTEM = nullptr;
$String* ModuleBootstrap::ALL_MODULE_PATH = nullptr;
$JavaLangAccess* ModuleBootstrap::JLA = nullptr;
$JavaLangModuleAccess* ModuleBootstrap::JLMA = nullptr;
$ModulePatcher* ModuleBootstrap::patcher$ = nullptr;
$volatile($ModuleFinder*) ModuleBootstrap::unlimitedFinder$ = nullptr;
$volatile($ModuleFinder*) ModuleBootstrap::limitedFinder$ = nullptr;
$String* ModuleBootstrap::ADD_MODULES = nullptr;
$String* ModuleBootstrap::ADD_EXPORTS = nullptr;
$String* ModuleBootstrap::ADD_OPENS = nullptr;
$String* ModuleBootstrap::ADD_READS = nullptr;
$String* ModuleBootstrap::PATCH_MODULE = nullptr;
$String* ModuleBootstrap::ENABLE_NATIVE_ACCESS = nullptr;

void ModuleBootstrap::init$() {
}

$ModulePatcher* ModuleBootstrap::patcher() {
	$init(ModuleBootstrap);
	return ModuleBootstrap::patcher$;
}

$ModuleFinder* ModuleBootstrap::unlimitedFinder() {
	$init(ModuleBootstrap);
	$var($ModuleFinder, finder, ModuleBootstrap::unlimitedFinder$);
	if (finder == nullptr) {
		return $ModuleFinder::ofSystem();
	} else {
		return finder;
	}
}

$ModuleFinder* ModuleBootstrap::limitedFinder() {
	$init(ModuleBootstrap);
	$var($ModuleFinder, finder, ModuleBootstrap::limitedFinder$);
	if (finder == nullptr) {
		return unlimitedFinder();
	} else {
		return finder;
	}
}

bool ModuleBootstrap::canUseArchivedBootLayer() {
	$init(ModuleBootstrap);
	bool var$7 = getProperty("jdk.module.upgrade.path"_s) == nullptr;
	bool var$6 = var$7 && getProperty("jdk.module.path"_s) == nullptr;
	bool var$5 = var$6 && getProperty("jdk.module.patch.0"_s) == nullptr;
	bool var$4 = var$5 && getProperty("jdk.module.main"_s) == nullptr;
	bool var$3 = var$4 && getProperty("jdk.module.addmods.0"_s) == nullptr;
	bool var$2 = var$3 && getProperty("jdk.module.limitmods"_s) == nullptr;
	bool var$1 = var$2 && getProperty("jdk.module.addreads.0"_s) == nullptr;
	bool var$0 = var$1 && getProperty("jdk.module.addexports.0"_s) == nullptr;
	return var$0 && getProperty("jdk.module.addopens.0"_s) == nullptr;
}

$ModuleLayer* ModuleBootstrap::boot() {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$ModuleBootstrap$Counters::start();
	$var($ModuleLayer, bootLayer, nullptr);
	$var($ArchivedBootLayer, archivedBootLayer, $ArchivedBootLayer::get());
	if (archivedBootLayer != nullptr) {
		if (!ModuleBootstrap::$assertionsDisabled && !canUseArchivedBootLayer()) {
			$throwNew($AssertionError);
		}
		$assign(bootLayer, archivedBootLayer->bootLayer());
		$BootLoader::getUnnamedModule();
		$var($ClassLoader, var$0, $ClassLoaders::platformClassLoader());
		$CDS::defineArchivedModules(var$0, $($ClassLoaders::appClassLoader()));
		$nc(ModuleBootstrap::JLA)->bindToLoader(bootLayer, $($ClassLoaders::appClassLoader()));
	} else {
		$assign(bootLayer, boot2());
	}
	$ModuleBootstrap$Counters::publish("jdk.module.boot.totalTime"_s);
	return bootLayer;
}

$ModuleLayer* ModuleBootstrap::boot2() {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($ModuleFinder, upgradeModulePath, finderFor("jdk.module.upgrade.path"_s));
	$var($ModuleFinder, appModulePath, finderFor("jdk.module.path"_s));
	bool isPatched = $nc(ModuleBootstrap::patcher$)->hasPatches();
	$var($String, mainModule, $System::getProperty("jdk.module.main"_s));
	$var($Set, addModules, ModuleBootstrap::addModules());
	$var($Set, limitModules, ModuleBootstrap::limitModules());
	$var($PrintStream, traceOutput, nullptr);
	$var($String, trace, getAndRemoveProperty("jdk.module.showModuleResolution"_s));
	if (trace != nullptr && $Boolean::parseBoolean(trace)) {
		$assign(traceOutput, $System::out);
	}
	$ModuleBootstrap$Counters::add("jdk.module.boot.0.commandLineTime"_s);
	$var($SystemModules, systemModules, nullptr);
	$var($ModuleFinder, systemModuleFinder, nullptr);
	bool haveModulePath = (appModulePath != nullptr || upgradeModulePath != nullptr);
	bool needResolution = true;
	bool canArchive = false;
	bool hasSplitPackages = false;
	bool hasIncubatorModules = false;
	$var($ArchivedModuleGraph, archivedModuleGraph, $ArchivedModuleGraph::get(mainModule));
	bool var$0 = archivedModuleGraph != nullptr && !haveModulePath && $nc(addModules)->isEmpty();
	if (var$0 && $nc(limitModules)->isEmpty() && !isPatched) {
		$assign(systemModuleFinder, archivedModuleGraph->finder());
		hasSplitPackages = archivedModuleGraph->hasSplitPackages();
		hasIncubatorModules = archivedModuleGraph->hasIncubatorModules();
		needResolution = (traceOutput != nullptr);
	} else {
		bool var$1 = !haveModulePath && addModules->isEmpty();
		if (var$1 && limitModules->isEmpty()) {
			$assign(systemModules, $SystemModuleFinders::systemModules(mainModule));
			if (systemModules != nullptr && !isPatched) {
				needResolution = (traceOutput != nullptr);
				canArchive = true;
			}
		}
		if (systemModules == nullptr) {
			$assign(systemModules, $SystemModuleFinders::allSystemModules());
		}
		if (systemModules != nullptr) {
			$assign(systemModuleFinder, $SystemModuleFinders::of(systemModules));
		} else {
			$assign(systemModules, $new($ExplodedSystemModules));
			$assign(systemModuleFinder, $SystemModuleFinders::ofSystem());
		}
		hasSplitPackages = $nc(systemModules)->hasSplitPackages();
		hasIncubatorModules = systemModules->hasIncubatorModules();
		$assign(archivedModuleGraph, nullptr);
	}
	$ModuleBootstrap$Counters::add("jdk.module.boot.1.systemModulesTime"_s);
	$var($ModuleReference, base, $cast($ModuleReference, $nc($($nc(systemModuleFinder)->find(ModuleBootstrap::JAVA_BASE)))->orElse(nullptr)));
	if (base == nullptr) {
		$throwNew($InternalError, $$str({ModuleBootstrap::JAVA_BASE, " not found"_s}));
	}
	$var($URI, baseUri, $cast($URI, $nc($($nc(base)->location()))->orElse(nullptr)));
	if (baseUri == nullptr) {
		$throwNew($InternalError, $$str({ModuleBootstrap::JAVA_BASE, " does not have a location"_s}));
	}
	$BootLoader::loadModule(base);
	$var($Module, baseModule, $Modules::defineModule(nullptr, $(base->descriptor()), baseUri));
	$nc(ModuleBootstrap::JLA)->addEnableNativeAccess(baseModule);
	if (getAndRemoveProperty("jdk.module.validation"_s) != nullptr) {
		int32_t errors = $ModulePathValidator::scanAllModules($System::out);
		if (errors > 0) {
			fail("Validation of module path failed"_s);
		}
	}
	$ModuleBootstrap$Counters::add("jdk.module.boot.2.defineBaseTime"_s);
	$var($ModuleFinder, savedModuleFinder, nullptr);
	$var($ModuleFinder, finder, nullptr);
	$var($Set, roots, nullptr);
	if (needResolution) {
		if (upgradeModulePath != nullptr) {
			$assign(systemModuleFinder, $ModuleFinder::compose($$new($ModuleFinderArray, {
				upgradeModulePath,
				systemModuleFinder
			})));
		}
		if (appModulePath != nullptr) {
			$assign(finder, $ModuleFinder::compose($$new($ModuleFinderArray, {
				systemModuleFinder,
				appModulePath
			})));
		} else {
			$assign(finder, systemModuleFinder);
		}
		$assign(roots, $new($HashSet));
		if (mainModule != nullptr) {
			roots->add(mainModule);
		}
		bool addAllDefaultModules = false;
		bool addAllSystemModules = false;
		bool addAllApplicationModules = false;
		{
			$var($Iterator, i$, $nc(addModules)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, mod, $cast($String, i$->next()));
				{
					{
						$var($String, s12811$, mod);
						int32_t tmp12811$ = -1;
						switch ($nc(s12811$)->hashCode()) {
						case 0x21A431D5:
							{
								if (s12811$->equals("ALL-DEFAULT"_s)) {
									tmp12811$ = 0;
								}
								break;
							}
						case (int32_t)0xC0F7CFFB:
							{
								if (s12811$->equals("ALL-SYSTEM"_s)) {
									tmp12811$ = 1;
								}
								break;
							}
						case 0x3FCA5C9A:
							{
								if (s12811$->equals("ALL-MODULE-PATH"_s)) {
									tmp12811$ = 2;
								}
								break;
							}
						}
						switch (tmp12811$) {
						case 0:
							{
								addAllDefaultModules = true;
								break;
							}
						case 1:
							{
								addAllSystemModules = true;
								break;
							}
						case 2:
							{
								addAllApplicationModules = true;
								break;
							}
						default:
							{
								roots->add(mod);
							}
						}
					}
				}
			}
		}
		$assign(savedModuleFinder, finder);
		if (!$nc(limitModules)->isEmpty()) {
			$assign(finder, limitFinder(finder, limitModules, roots));
		}
		if (mainModule == nullptr || addAllDefaultModules) {
			roots->addAll($($DefaultRoots::compute(systemModuleFinder, finder)));
		}
		if (addAllSystemModules) {
			$var($ModuleFinder, f, finder);
			$nc($($nc($($nc($($nc($($nc($(systemModuleFinder->findAll()))->stream()))->map(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$descriptor)))))->map(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$name$1)))))->filter(static_cast<$Predicate*>($$new(ModuleBootstrap$$Lambda$lambda$boot2$0$2, f)))))->forEach(static_cast<$Consumer*>($$new(ModuleBootstrap$$Lambda$lambda$boot2$1$3, roots)));
		}
		if (appModulePath != nullptr && addAllApplicationModules) {
			$var($ModuleFinder, f, finder);
			$nc($($nc($($nc($($nc($($nc($(appModulePath->findAll()))->stream()))->map(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$descriptor)))))->map(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$name$1)))))->filter(static_cast<$Predicate*>($$new(ModuleBootstrap$$Lambda$lambda$boot2$0$2, f)))))->forEach(static_cast<$Consumer*>($$new(ModuleBootstrap$$Lambda$lambda$boot2$1$3, roots)));
		}
	} else {
		$assign(finder, systemModuleFinder);
		$assign(roots, nullptr);
	}
	$ModuleBootstrap$Counters::add("jdk.module.boot.3.optionsAndRootsTime"_s);
	$var($Configuration, cf, nullptr);
	if (needResolution) {
		$assign(cf, $Modules::newBootLayerConfiguration(finder, roots, traceOutput));
	} else if (archivedModuleGraph != nullptr) {
		$assign(cf, archivedModuleGraph->configuration());
	} else {
		$var($Map, map, $nc(systemModules)->moduleReads());
		$assign(cf, $nc(ModuleBootstrap::JLMA)->newConfiguration(systemModuleFinder, map));
	}
	if (isPatched) {
		$nc($($nc($($nc($($nc(ModuleBootstrap::patcher$)->patchedModules()))->stream()))->filter(static_cast<$Predicate*>($$new(ModuleBootstrap$$Lambda$lambda$boot2$4$4, cf)))))->forEach(static_cast<$Consumer*>($$new(ModuleBootstrap$$Lambda$lambda$boot2$5$5)));
	}
	$ModuleBootstrap$Counters::add("jdk.module.boot.4.resolveTime"_s);
	$var($Function, clf, nullptr);
	if (archivedModuleGraph != nullptr) {
		$assign(clf, archivedModuleGraph->classLoaderFunction());
	} else {
		$assign(clf, $ModuleLoaderMap::mappingFunction(cf));
	}
	if (haveModulePath) {
		{
			$var($Iterator, i$, $nc($($nc(cf)->modules()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
				{
					$var($ModuleReference, mref, $nc(resolvedModule)->reference());
					$var($String, name, $nc($($nc(mref)->descriptor()))->name());
					$var($ClassLoader, cl, $cast($ClassLoader, $nc(clf)->apply(name)));
					if (cl == nullptr) {
						if (upgradeModulePath != nullptr && $nc($(upgradeModulePath->find(name)))->isPresent()) {
							fail($$str({name, ": cannot be loaded from upgrade module path"_s}));
						}
						if (!$nc($(systemModuleFinder->find(name)))->isPresent()) {
							fail($$str({name, ": cannot be loaded from application module path"_s}));
						}
					}
				}
			}
		}
	}
	if (hasSplitPackages || isPatched || haveModulePath) {
		checkSplitPackages(cf, clf);
	}
	loadModules(cf, clf);
	$ModuleBootstrap$Counters::add("jdk.module.boot.5.loadModulesTime"_s);
	$var($ModuleLayer, bootLayer, $nc($($ModuleLayer::empty()))->defineModules(cf, clf));
	$ModuleBootstrap$Counters::add("jdk.module.boot.6.layerCreateTime"_s);
	if (hasIncubatorModules || haveModulePath) {
		checkIncubatingStatus(cf);
	}
	addExtraReads(bootLayer);
	bool extraExportsOrOpens = addExtraExportsAndOpens(bootLayer);
	addEnableNativeAccess(bootLayer);
	$ModuleBootstrap$Counters::add("jdk.module.boot.7.adjustModulesTime"_s);
	if (savedModuleFinder != nullptr) {
		$assignStatic(ModuleBootstrap::unlimitedFinder$, $new($ModuleBootstrap$SafeModuleFinder, savedModuleFinder));
		if (savedModuleFinder != finder) {
			$assignStatic(ModuleBootstrap::limitedFinder$, $new($ModuleBootstrap$SafeModuleFinder, finder));
		}
	}
	if (canArchive && (mainModule == nullptr)) {
		$ArchivedModuleGraph::archive(hasSplitPackages, hasIncubatorModules, systemModuleFinder, cf, clf);
		if (!hasSplitPackages && !hasIncubatorModules) {
			$ArchivedBootLayer::archive(bootLayer);
		}
	}
	return bootLayer;
}

void ModuleBootstrap::loadModules($Configuration* cf, $Function* clf) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(cf)->modules()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				$var($ModuleReference, mref, $nc(resolvedModule)->reference());
				$var($String, name, resolvedModule->name());
				$var($ClassLoader, loader, $cast($ClassLoader, $nc(clf)->apply(name)));
				if (loader == nullptr) {
					if (!$nc(name)->equals(ModuleBootstrap::JAVA_BASE)) {
						$BootLoader::loadModule(mref);
					}
				} else if ($instanceOf($BuiltinClassLoader, loader)) {
					$nc(($cast($BuiltinClassLoader, loader)))->loadModule(mref);
				}
			}
		}
	}
}

void ModuleBootstrap::checkSplitPackages($Configuration* cf, $Function* clf) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($Map, packageToModule, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc(cf)->modules()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				$var($ModuleDescriptor, descriptor, $nc($($nc(resolvedModule)->reference()))->descriptor());
				$var($String, name, $nc(descriptor)->name());
				$var($ClassLoader, loader, $cast($ClassLoader, $nc(clf)->apply(name)));
				if (loader == nullptr || $instanceOf($BuiltinClassLoader, loader)) {
					{
						$var($Iterator, i$, $nc($(descriptor->packages()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, p, $cast($String, i$->next()));
							{
								$var($String, other, $cast($String, packageToModule->putIfAbsent(p, name)));
								if (other != nullptr) {
									$var($String, msg, $str({"Package "_s, p, " in both module "_s, name, " and module "_s, other}));
									$throwNew($LayerInstantiationException, msg);
								}
							}
						}
					}
				}
			}
		}
	}
}

$ModuleFinder* ModuleBootstrap::limitFinder($ModuleFinder* finder, $Set* roots, $Set* otherMods) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($Configuration, cf, $nc($($Configuration::empty()))->resolve(finder, $($ModuleFinder::of($$new($PathArray, 0))), roots));
	$var($Map, map, $new($HashMap));
	$nc($($nc($($nc($($nc(cf)->modules()))->stream()))->map(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$reference$6)))))->forEach(static_cast<$Consumer*>($$new(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7, map)));
	$nc($($nc($($nc($($nc(otherMods)->stream()))->map(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$find$8, static_cast<$ModuleFinder*>($nc(finder)))))))->flatMap(static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$stream$9)))))->forEach(static_cast<$Consumer*>($$new(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10, map)));
	$var($Set, mrefs, $new($HashSet, $(map->values())));
	return $new($ModuleBootstrap$1, map, mrefs);
}

$ModuleFinder* ModuleBootstrap::finderFor($String* prop) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $System::getProperty(prop));
	if (s == nullptr) {
		return nullptr;
	} else {
		$init($File);
		$var($StringArray, dirs, $nc(s)->split($File::pathSeparator));
		$var($PathArray, paths, $new($PathArray, dirs->length));
		int32_t i = 0;
		{
			$var($StringArray, arr$, dirs);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, dir, arr$->get(i$));
				{
					paths->set(i++, $($Path::of(dir, $$new($StringArray, 0))));
				}
			}
		}
		return $ModulePath::of(ModuleBootstrap::patcher$, paths);
	}
}

$ModulePatcher* ModuleBootstrap::initModulePatcher() {
	$init(ModuleBootstrap);
	$init($File);
	$var($Map, map, decode("jdk.module.patch."_s, $File::pathSeparator, false));
	return $new($ModulePatcher, map);
}

$Set* ModuleBootstrap::addModules() {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($String, prefix, "jdk.module.addmods."_s);
	int32_t index = 0;
	$var($String, value, getAndRemoveProperty($$str({prefix, $$str(index)})));
	if (value == nullptr) {
		return $Set::of();
	} else {
		$var($Set, modules, $new($HashSet));
		while (value != nullptr) {
			{
				$var($StringArray, arr$, value->split(","_s));
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, s, arr$->get(i$));
					{
						if (!$nc(s)->isEmpty()) {
							modules->add(s);
						}
					}
				}
			}
			++index;
			$assign(value, getAndRemoveProperty($$str({prefix, $$str(index)})));
		}
		return modules;
	}
}

$Set* ModuleBootstrap::limitModules() {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($String, value, getAndRemoveProperty("jdk.module.limitmods"_s));
	if (value == nullptr) {
		return $Set::of();
	} else {
		$var($Set, names, $new($HashSet));
		{
			$var($StringArray, arr$, $nc(value)->split(","_s));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, name, arr$->get(i$));
				{
					if ($nc(name)->length() > 0) {
						names->add(name);
					}
				}
			}
		}
		return names;
	}
}

void ModuleBootstrap::addExtraReads($ModuleLayer* bootLayer) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($Map, map, decode("jdk.module.addreads."_s));
	if ($nc(map)->isEmpty()) {
		return;
	}
	{
		$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, mn, $cast($String, $nc(e)->getKey()));
				$var($Optional, om, $nc(bootLayer)->findModule(mn));
				if (!$nc(om)->isPresent()) {
					warnUnknownModule(ModuleBootstrap::ADD_READS, mn);
					continue;
				}
				$var($Module, m, $cast($Module, $nc(om)->get()));
				{
					$var($Iterator, i$, $nc(($cast($List, $(e->getValue()))))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, name, $cast($String, i$->next()));
						{
							if ($nc(ModuleBootstrap::ALL_UNNAMED)->equals(name)) {
								$Modules::addReadsAllUnnamed(m);
							} else {
								$assign(om, bootLayer->findModule(name));
								if ($nc(om)->isPresent()) {
									$Modules::addReads(m, $cast($Module, $(om->get())));
								} else {
									warnUnknownModule(ModuleBootstrap::ADD_READS, name);
								}
							}
						}
					}
				}
			}
		}
	}
}

bool ModuleBootstrap::addExtraExportsAndOpens($ModuleLayer* bootLayer) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	bool extraExportsOrOpens = false;
	$var($String, prefix, "jdk.module.addexports."_s);
	$var($Map, extraExports, decode(prefix));
	if (!$nc(extraExports)->isEmpty()) {
		addExtraExportsOrOpens(bootLayer, extraExports, false);
		extraExportsOrOpens = true;
	}
	$assign(prefix, "jdk.module.addopens."_s);
	$var($Map, extraOpens, decode(prefix));
	if (!$nc(extraOpens)->isEmpty()) {
		addExtraExportsOrOpens(bootLayer, extraOpens, true);
		extraExportsOrOpens = true;
	}
	return extraExportsOrOpens;
}

void ModuleBootstrap::addExtraExportsOrOpens($ModuleLayer* bootLayer, $Map* map, bool opens) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($String, option, opens ? ModuleBootstrap::ADD_OPENS : ModuleBootstrap::ADD_EXPORTS);
	{
		$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(e)->getKey()));
				$var($StringArray, s, $nc(key)->split("/"_s));
				if (s->length != 2) {
					fail($(unableToParse(option, "<module>/<package>"_s, key)));
				}
				$var($String, mn, s->get(0));
				$var($String, pn, s->get(1));
				bool var$0 = $nc(mn)->isEmpty();
				if (var$0 || $nc(pn)->isEmpty()) {
					fail($(unableToParse(option, "<module>/<package>"_s, key)));
				}
				$var($Module, m, nullptr);
				$var($Optional, om, $nc(bootLayer)->findModule(mn));
				if (!$nc(om)->isPresent()) {
					warnUnknownModule(option, mn);
					continue;
				}
				$assign(m, $cast($Module, $nc(om)->get()));
				if (!$nc($($nc($($nc(m)->getDescriptor()))->packages()))->contains(pn)) {
					warn($$str({"package "_s, pn, " not in "_s, mn}));
					continue;
				}
				{
					$var($Iterator, i$, $nc(($cast($List, $(e->getValue()))))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, name, $cast($String, i$->next()));
						{
							bool allUnnamed = false;
							$var($Module, other, nullptr);
							if ($nc(ModuleBootstrap::ALL_UNNAMED)->equals(name)) {
								allUnnamed = true;
							} else {
								$assign(om, bootLayer->findModule(name));
								if ($nc(om)->isPresent()) {
									$assign(other, $cast($Module, om->get()));
								} else {
									warnUnknownModule(option, name);
									continue;
								}
							}
							if (allUnnamed) {
								if (opens) {
									$Modules::addOpensToAllUnnamed(m, pn);
								} else {
									$Modules::addExportsToAllUnnamed(m, pn);
								}
							} else if (opens) {
								$Modules::addOpens(m, pn, other);
							} else {
								$Modules::addExports(m, pn, other);
							}
						}
					}
				}
			}
		}
	}
}

void ModuleBootstrap::addEnableNativeAccess($ModuleLayer* layer) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($(decodeEnableNativeAccess()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, name, $cast($String, i$->next()));
			{
				if ($nc(name)->equals("ALL-UNNAMED"_s)) {
					$nc(ModuleBootstrap::JLA)->addEnableNativeAccessAllUnnamed();
				} else {
					$var($Optional, module, $nc(layer)->findModule(name));
					if ($nc(module)->isPresent()) {
						$nc(ModuleBootstrap::JLA)->addEnableNativeAccess($cast($Module, $(module->get())));
					} else {
						warnUnknownModule(ModuleBootstrap::ENABLE_NATIVE_ACCESS, name);
					}
				}
			}
		}
	}
}

$Set* ModuleBootstrap::decodeEnableNativeAccess() {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($String, prefix, "jdk.module.enable.native.access."_s);
	int32_t index = 0;
	$var($String, value, getAndRemoveProperty($$str({prefix, $$str(index)})));
	$var($Set, modules, $new($HashSet));
	if (value == nullptr) {
		return modules;
	}
	while (value != nullptr) {
		{
			$var($StringArray, arr$, value->split(","_s));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, s, arr$->get(i$));
				{
					if (!$nc(s)->isEmpty()) {
						modules->add(s);
					}
				}
			}
		}
		++index;
		$assign(value, getAndRemoveProperty($$str({prefix, $$str(index)})));
	}
	return modules;
}

$Map* ModuleBootstrap::decode($String* prefix, $String* regex, bool allowDuplicates) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	int32_t index = 0;
	$var($String, value, getAndRemoveProperty($$str({prefix, $$str(index)})));
	if (value == nullptr) {
		return $Map::of();
	}
	$var($Map, map, $new($HashMap));
	while (value != nullptr) {
		int32_t pos = value->indexOf((int32_t)u'=');
		if (pos == -1) {
			fail($(unableToParse($(option(prefix)), "<module>=<value>"_s, value)));
		}
		if (pos == 0) {
			fail($(unableToParse($(option(prefix)), "<module>=<value>"_s, value)));
		}
		$var($String, key, value->substring(0, pos));
		$var($String, rhs, value->substring(pos + 1));
		if (rhs->isEmpty()) {
			fail($(unableToParse($(option(prefix)), "<module>=<value>"_s, value)));
		}
		if (!allowDuplicates && map->containsKey(key)) {
			fail($$str({key, " specified more than once to "_s, $(option(prefix))}));
		}
		$var($List, values, $cast($List, map->computeIfAbsent(key, static_cast<$Function*>($$new(ModuleBootstrap$$Lambda$lambda$decode$8$11)))));
		int32_t ntargets = 0;
		{
			$var($StringArray, arr$, rhs->split(regex));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, s, arr$->get(i$));
				{
					if (!$nc(s)->isEmpty()) {
						$nc(values)->add(s);
						++ntargets;
					}
				}
			}
		}
		if (ntargets == 0) {
			fail($$str({"Target must be specified: "_s, $(option(prefix)), " "_s, value}));
		}
		++index;
		$assign(value, getAndRemoveProperty($$str({prefix, $$str(index)})));
	}
	return map;
}

$Map* ModuleBootstrap::decode($String* prefix) {
	$init(ModuleBootstrap);
	return decode(prefix, ","_s, true);
}

$String* ModuleBootstrap::getProperty($String* key) {
	$init(ModuleBootstrap);
	return $System::getProperty(key);
}

$String* ModuleBootstrap::getAndRemoveProperty($String* key) {
	$init(ModuleBootstrap);
	return $cast($String, $nc($($System::getProperties()))->remove(key));
}

void ModuleBootstrap::checkIncubatingStatus($Configuration* cf) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$var($String, incubating, nullptr);
	{
		$var($Iterator, i$, $nc($($nc(cf)->modules()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ResolvedModule, resolvedModule, $cast($ResolvedModule, i$->next()));
			{
				$var($ModuleReference, mref, $nc(resolvedModule)->reference());
				if ($ModuleResolution::hasIncubatingWarning(mref)) {
					$var($String, mn, $nc($($nc(mref)->descriptor()))->name());
					if (incubating == nullptr) {
						$assign(incubating, mn);
					} else {
						$plusAssign(incubating, $$str({", "_s, mn}));
					}
				}
			}
		}
	}
	if (incubating != nullptr) {
		warn($$str({"Using incubator modules: "_s, incubating}));
	}
}

void ModuleBootstrap::fail($String* m) {
	$init(ModuleBootstrap);
	$throwNew($RuntimeException, m);
}

void ModuleBootstrap::warn($String* m) {
	$init(ModuleBootstrap);
	$nc($System::err)->println($$str({"WARNING: "_s, m}));
}

void ModuleBootstrap::warnUnknownModule($String* option, $String* mn) {
	$init(ModuleBootstrap);
	warn($$str({"Unknown module: "_s, mn, " specified to "_s, option}));
}

$String* ModuleBootstrap::unableToParse($String* option, $String* text, $String* value) {
	$init(ModuleBootstrap);
	return $str({"Unable to parse "_s, option, " "_s, text, ": "_s, value});
}

$String* ModuleBootstrap::option($String* prefix) {
	$init(ModuleBootstrap);
	{
		$var($String, s36138$, prefix);
		int32_t tmp36138$ = -1;
		switch ($nc(s36138$)->hashCode()) {
		case 0x52DCBE8B:
			{
				if (s36138$->equals("jdk.module.addexports."_s)) {
					tmp36138$ = 0;
				}
				break;
			}
		case 0x36C8C2A1:
			{
				if (s36138$->equals("jdk.module.addopens."_s)) {
					tmp36138$ = 1;
				}
				break;
			}
		case 0x3B4A52ED:
			{
				if (s36138$->equals("jdk.module.addreads."_s)) {
					tmp36138$ = 2;
				}
				break;
			}
		case 0x295751EB:
			{
				if (s36138$->equals("jdk.module.patch."_s)) {
					tmp36138$ = 3;
				}
				break;
			}
		case (int32_t)0x9E8EFC61:
			{
				if (s36138$->equals("jdk.module.addmods."_s)) {
					tmp36138$ = 4;
				}
				break;
			}
		}
		switch (tmp36138$) {
		case 0:
			{
				return ModuleBootstrap::ADD_EXPORTS;
			}
		case 1:
			{
				return ModuleBootstrap::ADD_OPENS;
			}
		case 2:
			{
				return ModuleBootstrap::ADD_READS;
			}
		case 3:
			{
				return ModuleBootstrap::PATCH_MODULE;
			}
		case 4:
			{
				return ModuleBootstrap::ADD_MODULES;
			}
		default:
			{
				$throwNew($IllegalArgumentException, prefix);
			}
		}
	}
}

$List* ModuleBootstrap::lambda$decode$8($String* k) {
	$init(ModuleBootstrap);
	return $new($ArrayList);
}

void ModuleBootstrap::lambda$limitFinder$7($Map* map, $ModuleReference* mref) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$nc(map)->putIfAbsent($($nc($($nc(mref)->descriptor()))->name()), mref);
}

void ModuleBootstrap::lambda$limitFinder$6($Map* map, $ModuleReference* mref) {
	$init(ModuleBootstrap);
	$useLocalCurrentObjectStackCache();
	$nc(map)->put($($nc($($nc(mref)->descriptor()))->name()), mref);
}

void ModuleBootstrap::lambda$boot2$5($String* mn) {
	$init(ModuleBootstrap);
	warnUnknownModule(ModuleBootstrap::PATCH_MODULE, mn);
}

bool ModuleBootstrap::lambda$boot2$4($Configuration* cf, $String* mn) {
	$init(ModuleBootstrap);
	return !$nc($($nc(cf)->findModule(mn)))->isPresent();
}

void ModuleBootstrap::lambda$boot2$1($Set* roots, $String* mn) {
	$init(ModuleBootstrap);
	$nc(roots)->add(mn);
}

bool ModuleBootstrap::lambda$boot2$0($ModuleFinder* f, $String* mn) {
	$init(ModuleBootstrap);
	return $nc($($nc(f)->find(mn)))->isPresent();
}

void clinit$ModuleBootstrap($Class* class$) {
	$assignStatic(ModuleBootstrap::JAVA_BASE, "java.base"_s);
	$assignStatic(ModuleBootstrap::ALL_DEFAULT, "ALL-DEFAULT"_s);
	$assignStatic(ModuleBootstrap::ALL_UNNAMED, "ALL-UNNAMED"_s);
	$assignStatic(ModuleBootstrap::ALL_SYSTEM, "ALL-SYSTEM"_s);
	$assignStatic(ModuleBootstrap::ALL_MODULE_PATH, "ALL-MODULE-PATH"_s);
	$assignStatic(ModuleBootstrap::ADD_MODULES, "--add-modules"_s);
	$assignStatic(ModuleBootstrap::ADD_EXPORTS, "--add-exports"_s);
	$assignStatic(ModuleBootstrap::ADD_OPENS, "--add-opens"_s);
	$assignStatic(ModuleBootstrap::ADD_READS, "--add-reads"_s);
	$assignStatic(ModuleBootstrap::PATCH_MODULE, "--patch-module"_s);
	$assignStatic(ModuleBootstrap::ENABLE_NATIVE_ACCESS, "--enable-native-access"_s);
	ModuleBootstrap::$assertionsDisabled = !ModuleBootstrap::class$->desiredAssertionStatus();
	$assignStatic(ModuleBootstrap::JLA, $SharedSecrets::getJavaLangAccess());
	$assignStatic(ModuleBootstrap::JLMA, $SharedSecrets::getJavaLangModuleAccess());
	$assignStatic(ModuleBootstrap::patcher$, ModuleBootstrap::initModulePatcher());
}

ModuleBootstrap::ModuleBootstrap() {
}

$Class* ModuleBootstrap::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleBootstrap$$Lambda$descriptor::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$descriptor::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$name$1::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$name$1::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$boot2$0$2::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$boot2$0$2::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$boot2$1$3::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$boot2$1$3::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$boot2$4$4::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$boot2$4$4::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$boot2$5$5::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$boot2$5$5::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$reference$6::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$reference$6::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$limitFinder$6$7::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$find$8::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$find$8::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$stream$9::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$stream$9::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$limitFinder$7$10::load$(name, initialize);
		}
		if (name->equals(ModuleBootstrap$$Lambda$lambda$decode$8$11::classInfo$.name)) {
			return ModuleBootstrap$$Lambda$lambda$decode$8$11::load$(name, initialize);
		}
	}
	$loadClass(ModuleBootstrap, name, initialize, &_ModuleBootstrap_ClassInfo_, clinit$ModuleBootstrap, allocate$ModuleBootstrap);
	return class$;
}

$Class* ModuleBootstrap::class$ = nullptr;

		} // module
	} // internal
} // jdk