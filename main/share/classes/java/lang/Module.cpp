#include <java/lang/Module.h>

#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalCallerException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module$1.h>
#include <java/lang/Module$1DummyModuleInfo.h>
#include <java/lang/Module$2.h>
#include <java/lang/Module$ArchivedData.h>
#include <java/lang/Module$ReflectionData.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/Package.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/WeakPairMap.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/Configuration.h>
#include <java/lang/module/ModuleDescriptor$Exports.h>
#include <java/lang/module/ModuleDescriptor$Opens.h>
#include <java/lang/module/ModuleDescriptor$Version.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/module/ResolvedModule.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ModuleLoaderMap.h>
#include <jdk/internal/module/Resources.h>
#include <jdk/internal/module/ServicesCatalog.h>
#include <jdk/internal/org/objectweb/asm/ClassReader.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/reflect/Reflection.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef ALL_UNNAMED_MODULE
#undef ALL_UNNAMED_MODULE_SET
#undef ASM7
#undef COMPUTE_FRAMES
#undef COMPUTE_MAXS
#undef EVERYONE_MODULE
#undef EVERYONE_SET
#undef FALSE
#undef GET_CLASSLOADER_PERMISSION
#undef MODULE_INFO
#undef TRUE

using $ClassLoaderArray = $Array<::java::lang::ClassLoader>;
using $ModuleArray = $Array<::java::lang::Module>;
using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $ResolvedModuleArray = $Array<::java::lang::module::ResolvedModule>;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalCallerException = ::java::lang::IllegalCallerException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module$1 = ::java::lang::Module$1;
using $Module$1DummyModuleInfo = ::java::lang::Module$1DummyModuleInfo;
using $Module$2 = ::java::lang::Module$2;
using $Module$ArchivedData = ::java::lang::Module$ArchivedData;
using $Module$ReflectionData = ::java::lang::Module$ReflectionData;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $Package = ::java::lang::Package;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $WeakPairMap = ::java::lang::WeakPairMap;
using $Annotation = ::java::lang::annotation::Annotation;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Configuration = ::java::lang::module::Configuration;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Exports = ::java::lang::module::ModuleDescriptor$Exports;
using $ModuleDescriptor$Opens = ::java::lang::module::ModuleDescriptor$Opens;
using $ModuleDescriptor$Version = ::java::lang::module::ModuleDescriptor$Version;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $ResolvedModule = ::java::lang::module::ResolvedModule;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $VM = ::jdk::internal::misc::VM;
using $ModuleLoaderMap = ::jdk::internal::module::ModuleLoaderMap;
using $Resources = ::jdk::internal::module::Resources;
using $ServicesCatalog = ::jdk::internal::module::ServicesCatalog;
using $ClassReader = ::jdk::internal::org::objectweb::asm$::ClassReader;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {

class Module$$Lambda$lambda$implAddExportsOrOpens$0 : public $BiFunction {
	$class(Module$$Lambda$lambda$implAddExportsOrOpens$0, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* m1, Object$* m2) override {
		 return $of(Module::lambda$implAddExportsOrOpens$0($cast(Module, m1), $cast(Module, m2)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Module$$Lambda$lambda$implAddExportsOrOpens$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Module$$Lambda$lambda$implAddExportsOrOpens$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Module$$Lambda$lambda$implAddExportsOrOpens$0, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Module$$Lambda$lambda$implAddExportsOrOpens$0, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Module$$Lambda$lambda$implAddExportsOrOpens$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Module$$Lambda$lambda$implAddExportsOrOpens$0",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Module$$Lambda$lambda$implAddExportsOrOpens$0::load$($String* name, bool initialize) {
	$loadClass(Module$$Lambda$lambda$implAddExportsOrOpens$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Module$$Lambda$lambda$implAddExportsOrOpens$0::class$ = nullptr;

class Module$$Lambda$lambda$getPackages$1$1 : public $Predicate {
	$class(Module$$Lambda$lambda$getPackages$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$(Module* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* p) override {
		 return $nc(inst$)->lambda$getPackages$1($cast($Package, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Module$$Lambda$lambda$getPackages$1$1>());
	}
	Module* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Module$$Lambda$lambda$getPackages$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Module$$Lambda$lambda$getPackages$1$1, inst$)},
	{}
};
$MethodInfo Module$$Lambda$lambda$getPackages$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(Module$$Lambda$lambda$getPackages$1$1, init$, void, Module*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Module$$Lambda$lambda$getPackages$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo Module$$Lambda$lambda$getPackages$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Module$$Lambda$lambda$getPackages$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Module$$Lambda$lambda$getPackages$1$1::load$($String* name, bool initialize) {
	$loadClass(Module$$Lambda$lambda$getPackages$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Module$$Lambda$lambda$getPackages$1$1::class$ = nullptr;

class Module$$Lambda$getName$2 : public $Function {
	$class(Module$$Lambda$getName$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Package, inst$)->getName());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Module$$Lambda$getName$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Module$$Lambda$getName$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Module$$Lambda$getName$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Module$$Lambda$getName$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Module$$Lambda$getName$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Module$$Lambda$getName$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Module$$Lambda$getName$2::load$($String* name, bool initialize) {
	$loadClass(Module$$Lambda$getName$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Module$$Lambda$getName$2::class$ = nullptr;

class Module$$Lambda$lambda$findModule$2$3 : public $Predicate {
	$class(Module$$Lambda$lambda$findModule$2$3, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Configuration* cf) {
		$set(this, cf, cf);
	}
	virtual bool test(Object$* l) override {
		 return Module::lambda$findModule$2(cf, $cast($ModuleLayer, l));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Module$$Lambda$lambda$findModule$2$3>());
	}
	$Configuration* cf = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Module$$Lambda$lambda$findModule$2$3::fieldInfos[2] = {
	{"cf", "Ljava/lang/module/Configuration;", nullptr, $PUBLIC, $field(Module$$Lambda$lambda$findModule$2$3, cf)},
	{}
};
$MethodInfo Module$$Lambda$lambda$findModule$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/module/Configuration;)V", nullptr, $PUBLIC, $method(Module$$Lambda$lambda$findModule$2$3, init$, void, $Configuration*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Module$$Lambda$lambda$findModule$2$3, test, bool, Object$*)},
	{}
};
$ClassInfo Module$$Lambda$lambda$findModule$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Module$$Lambda$lambda$findModule$2$3",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Module$$Lambda$lambda$findModule$2$3::load$($String* name, bool initialize) {
	$loadClass(Module$$Lambda$lambda$findModule$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Module$$Lambda$lambda$findModule$2$3::class$ = nullptr;

class Module$$Lambda$lambda$findModule$3$4 : public $Function {
	$class(Module$$Lambda$lambda$findModule$3$4, $NO_CLASS_INIT, $Function)
public:
	void init$($String* dn) {
		$set(this, dn, dn);
	}
	virtual $Object* apply(Object$* layer) override {
		 return $of(Module::lambda$findModule$3(dn, $cast($ModuleLayer, layer)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Module$$Lambda$lambda$findModule$3$4>());
	}
	$String* dn = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Module$$Lambda$lambda$findModule$3$4::fieldInfos[2] = {
	{"dn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Module$$Lambda$lambda$findModule$3$4, dn)},
	{}
};
$MethodInfo Module$$Lambda$lambda$findModule$3$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Module$$Lambda$lambda$findModule$3$4, init$, void, $String*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Module$$Lambda$lambda$findModule$3$4, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Module$$Lambda$lambda$findModule$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Module$$Lambda$lambda$findModule$3$4",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Module$$Lambda$lambda$findModule$3$4::load$($String* name, bool initialize) {
	$loadClass(Module$$Lambda$lambda$findModule$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Module$$Lambda$lambda$findModule$3$4::class$ = nullptr;

class Module$$Lambda$loadModuleInfoClass$5 : public $PrivilegedAction {
	$class(Module$$Lambda$loadModuleInfoClass$5, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(Module* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->loadModuleInfoClass());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Module$$Lambda$loadModuleInfoClass$5>());
	}
	Module* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Module$$Lambda$loadModuleInfoClass$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Module$$Lambda$loadModuleInfoClass$5, inst$)},
	{}
};
$MethodInfo Module$$Lambda$loadModuleInfoClass$5::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(Module$$Lambda$loadModuleInfoClass$5, init$, void, Module*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Module$$Lambda$loadModuleInfoClass$5, run, $Object*)},
	{}
};
$ClassInfo Module$$Lambda$loadModuleInfoClass$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Module$$Lambda$loadModuleInfoClass$5",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Module$$Lambda$loadModuleInfoClass$5::load$($String* name, bool initialize) {
	$loadClass(Module$$Lambda$loadModuleInfoClass$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Module$$Lambda$loadModuleInfoClass$5::class$ = nullptr;

$CompoundAttribute _Module_MethodAnnotations_addExports3[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Module_MethodAnnotations_addOpens7[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Module_MethodAnnotations_addReads8[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Module_MethodAnnotations_addUses10[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Module_MethodAnnotations_getResourceAsStream27[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _Module_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Module, $assertionsDisabled)},
	{"layer", "Ljava/lang/ModuleLayer;", nullptr, $PRIVATE | $FINAL, $field(Module, layer)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Module, name)},
	{"loader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(Module, loader)},
	{"descriptor", "Ljava/lang/module/ModuleDescriptor;", nullptr, $PRIVATE | $FINAL, $field(Module, descriptor)},
	{"enableNativeAccess", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Module, enableNativeAccess)},
	{"ALL_UNNAMED_MODULE", "Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Module, ALL_UNNAMED_MODULE)},
	{"ALL_UNNAMED_MODULE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Module;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Module, ALL_UNNAMED_MODULE_SET)},
	{"EVERYONE_MODULE", "Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Module, EVERYONE_MODULE)},
	{"EVERYONE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Module;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Module, EVERYONE_SET)},
	{"reads", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Module;>;", $PRIVATE | $VOLATILE, $field(Module, reads)},
	{"openPackages", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;", $PRIVATE | $VOLATILE, $field(Module, openPackages)},
	{"exportedPackages", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;", $PRIVATE | $VOLATILE, $field(Module, exportedPackages)},
	{"moduleInfoClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $VOLATILE, $field(Module, moduleInfoClass$)},
	{}
};

$MethodInfo _Module_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ModuleLayer;Ljava/lang/ClassLoader;Ljava/lang/module/ModuleDescriptor;Ljava/net/URI;)V", nullptr, 0, $method(Module, init$, void, $ModuleLayer*, $ClassLoader*, $ModuleDescriptor*, $URI*)},
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, 0, $method(Module, init$, void, $ClassLoader*)},
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/module/ModuleDescriptor;)V", nullptr, 0, $method(Module, init$, void, $ClassLoader*, $ModuleDescriptor*)},
	{"addExports", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/Module;", nullptr, $PUBLIC, $method(Module, addExports, Module*, $String*, Module*), nullptr, nullptr, _Module_MethodAnnotations_addExports3},
	{"addExports0", "(Ljava/lang/Module;Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Module, addExports0, void, Module*, $String*, Module*)},
	{"addExportsToAll0", "(Ljava/lang/Module;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Module, addExportsToAll0, void, Module*, $String*)},
	{"addExportsToAllUnnamed0", "(Ljava/lang/Module;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Module, addExportsToAllUnnamed0, void, Module*, $String*)},
	{"addOpens", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/Module;", nullptr, $PUBLIC, $method(Module, addOpens, Module*, $String*, Module*), nullptr, nullptr, _Module_MethodAnnotations_addOpens7},
	{"addReads", "(Ljava/lang/Module;)Ljava/lang/Module;", nullptr, $PUBLIC, $method(Module, addReads, Module*, Module*), nullptr, nullptr, _Module_MethodAnnotations_addReads8},
	{"addReads0", "(Ljava/lang/Module;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Module, addReads0, void, Module*, Module*)},
	{"addUses", "(Ljava/lang/Class;)Ljava/lang/Module;", "(Ljava/lang/Class<*>;)Ljava/lang/Module;", $PUBLIC, $method(Module, addUses, Module*, $Class*), nullptr, nullptr, _Module_MethodAnnotations_addUses10},
	{"allows", "(Ljava/util/Set;Ljava/lang/Module;)Z", "(Ljava/util/Set<Ljava/lang/Module;>;Ljava/lang/Module;)Z", $PRIVATE, $method(Module, allows, bool, $Set*, Module*)},
	{"canRead", "(Ljava/lang/Module;)Z", nullptr, $PUBLIC, $method(Module, canRead, bool, Module*)},
	{"canUse", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC, $method(Module, canUse, bool, $Class*)},
	{"defineModule0", "(Ljava/lang/Module;ZLjava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Module, defineModule0, void, Module*, bool, $String*, $String*, $ObjectArray*)},
	{"defineModules", "(Ljava/lang/module/Configuration;Ljava/util/function/Function;Ljava/lang/ModuleLayer;)Ljava/util/Map;", "(Ljava/lang/module/Configuration;Ljava/util/function/Function<Ljava/lang/String;Ljava/lang/ClassLoader;>;Ljava/lang/ModuleLayer;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;", $STATIC, $staticMethod(Module, defineModules, $Map*, $Configuration*, $Function*, $ModuleLayer*)},
	{"findModule", "(Ljava/lang/ModuleLayer;Ljava/lang/module/ResolvedModule;)Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC, $staticMethod(Module, findModule, Module*, $ModuleLayer*, $ResolvedModule*)},
	{"findModule", "(Ljava/lang/String;Ljava/util/Map;Ljava/util/Map;Ljava/util/List;)Ljava/lang/Module;", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;Ljava/util/List<Ljava/lang/ModuleLayer;>;)Ljava/lang/Module;", $PRIVATE | $STATIC, $staticMethod(Module, findModule, Module*, $String*, $Map*, $Map*, $List*)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, $virtualMethod(Module, getAnnotation, $Annotation*, $Class*)},
	{"getAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Module, getAnnotations, $AnnotationArray*)},
	{"getCallerModule", "(Ljava/lang/Class;)Ljava/lang/Module;", "(Ljava/lang/Class<*>;)Ljava/lang/Module;", $PRIVATE, $method(Module, getCallerModule, Module*, $Class*)},
	{"getClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC, $method(Module, getClassLoader, $ClassLoader*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Module, getDeclaredAnnotations, $AnnotationArray*)},
	{"getDescriptor", "()Ljava/lang/module/ModuleDescriptor;", nullptr, $PUBLIC, $method(Module, getDescriptor, $ModuleDescriptor*)},
	{"getLayer", "()Ljava/lang/ModuleLayer;", nullptr, $PUBLIC, $method(Module, getLayer, $ModuleLayer*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Module, getName, $String*)},
	{"getPackages", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $method(Module, getPackages, $Set*)},
	{"getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $method(Module, getResourceAsStream, $InputStream*, $String*), "java.io.IOException", nullptr, _Module_MethodAnnotations_getResourceAsStream27},
	{"implAddEnableNativeAccess", "()Ljava/lang/Module;", nullptr, 0, $method(Module, implAddEnableNativeAccess, Module*)},
	{"implAddEnableNativeAccessAllUnnamed", "()V", nullptr, $STATIC, $staticMethod(Module, implAddEnableNativeAccessAllUnnamed, void)},
	{"implAddExports", "(Ljava/lang/String;)V", nullptr, 0, $method(Module, implAddExports, void, $String*)},
	{"implAddExports", "(Ljava/lang/String;Ljava/lang/Module;)V", nullptr, 0, $method(Module, implAddExports, void, $String*, Module*)},
	{"implAddExportsNoSync", "(Ljava/lang/String;)V", nullptr, 0, $method(Module, implAddExportsNoSync, void, $String*)},
	{"implAddExportsNoSync", "(Ljava/lang/String;Ljava/lang/Module;)V", nullptr, 0, $method(Module, implAddExportsNoSync, void, $String*, Module*)},
	{"implAddExportsOrOpens", "(Ljava/lang/String;Ljava/lang/Module;ZZ)V", nullptr, $PRIVATE, $method(Module, implAddExportsOrOpens, void, $String*, Module*, bool, bool)},
	{"implAddExportsToAllUnnamed", "(Ljava/lang/String;)V", nullptr, 0, $method(Module, implAddExportsToAllUnnamed, void, $String*)},
	{"implAddOpens", "(Ljava/lang/String;)V", nullptr, 0, $method(Module, implAddOpens, void, $String*)},
	{"implAddOpens", "(Ljava/lang/String;Ljava/lang/Module;)V", nullptr, 0, $method(Module, implAddOpens, void, $String*, Module*)},
	{"implAddOpensToAllUnnamed", "(Ljava/lang/String;)V", nullptr, 0, $method(Module, implAddOpensToAllUnnamed, void, $String*)},
	{"implAddOpensToAllUnnamed", "(Ljava/util/Set;Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/lang/String;>;Ljava/util/Set<Ljava/lang/String;>;)V", 0, $method(Module, implAddOpensToAllUnnamed, void, $Set*, $Set*)},
	{"implAddOpensToAllUnnamed", "(Ljava/util/Set;Ljava/util/Map;)V", "(Ljava/util/Set<Ljava/lang/String;>;Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;)V", $PRIVATE, $method(Module, implAddOpensToAllUnnamed, void, $Set*, $Map*)},
	{"implAddReads", "(Ljava/lang/Module;)V", nullptr, 0, $method(Module, implAddReads, void, Module*)},
	{"implAddReads", "(Ljava/lang/Module;Z)V", nullptr, $PRIVATE, $method(Module, implAddReads, void, Module*, bool)},
	{"implAddReadsAllUnnamed", "()V", nullptr, 0, $method(Module, implAddReadsAllUnnamed, void)},
	{"implAddReadsNoSync", "(Ljava/lang/Module;)V", nullptr, 0, $method(Module, implAddReadsNoSync, void, Module*)},
	{"implAddUses", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $method(Module, implAddUses, void, $Class*)},
	{"implIsEnableNativeAccess", "()Z", nullptr, 0, $method(Module, implIsEnableNativeAccess, bool)},
	{"implIsExportedOrOpen", "(Ljava/lang/String;Ljava/lang/Module;Z)Z", nullptr, $PRIVATE, $method(Module, implIsExportedOrOpen, bool, $String*, Module*, bool)},
	{"initExports", "(Ljava/lang/Module;Ljava/util/Map;)V", "(Ljava/lang/Module;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;)V", $PRIVATE | $STATIC, $staticMethod(Module, initExports, void, Module*, $Map*)},
	{"initExportsAndOpens", "(Ljava/lang/Module;Ljava/util/Map;Ljava/util/Map;Ljava/util/List;)V", "(Ljava/lang/Module;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Module;>;Ljava/util/List<Ljava/lang/ModuleLayer;>;)V", $PRIVATE | $STATIC, $staticMethod(Module, initExportsAndOpens, void, Module*, $Map*, $Map*, $List*)},
	{"isExported", "(Ljava/lang/String;Ljava/lang/Module;)Z", nullptr, $PUBLIC, $method(Module, isExported, bool, $String*, Module*)},
	{"isExported", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(Module, isExported, bool, $String*)},
	{"isNamed", "()Z", nullptr, $PUBLIC, $method(Module, isNamed, bool)},
	{"isOpen", "(Ljava/lang/String;Ljava/lang/Module;)Z", nullptr, $PUBLIC, $method(Module, isOpen, bool, $String*, Module*)},
	{"isOpen", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(Module, isOpen, bool, $String*)},
	{"isReflectivelyExported", "(Ljava/lang/String;Ljava/lang/Module;)Z", nullptr, 0, $method(Module, isReflectivelyExported, bool, $String*, Module*)},
	{"isReflectivelyExportedOrOpen", "(Ljava/lang/String;Ljava/lang/Module;Z)Z", nullptr, $PRIVATE, $method(Module, isReflectivelyExportedOrOpen, bool, $String*, Module*, bool)},
	{"isReflectivelyOpened", "(Ljava/lang/String;Ljava/lang/Module;)Z", nullptr, 0, $method(Module, isReflectivelyOpened, bool, $String*, Module*)},
	{"isStaticallyExportedOrOpen", "(Ljava/lang/String;Ljava/lang/Module;Z)Z", nullptr, $PRIVATE, $method(Module, isStaticallyExportedOrOpen, bool, $String*, Module*, bool)},
	{"lambda$findModule$2", "(Ljava/lang/module/Configuration;Ljava/lang/ModuleLayer;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Module, lambda$findModule$2, bool, $Configuration*, $ModuleLayer*)},
	{"lambda$findModule$3", "(Ljava/lang/String;Ljava/lang/ModuleLayer;)Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Module, lambda$findModule$3, Module*, $String*, $ModuleLayer*)},
	{"lambda$getPackages$1", "(Ljava/lang/Package;)Z", nullptr, $PRIVATE | $SYNTHETIC, $method(Module, lambda$getPackages$1, bool, $Package*)},
	{"lambda$implAddExportsOrOpens$0", "(Ljava/lang/Module;Ljava/lang/Module;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Module, lambda$implAddExportsOrOpens$0, $Map*, Module*, Module*)},
	{"loadModuleInfoClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(Module, loadModuleInfoClass, $Class*)},
	{"loadModuleInfoClass", "(Ljava/io/InputStream;)Ljava/lang/Class;", "(Ljava/io/InputStream;)Ljava/lang/Class<*>;", $PRIVATE, $method(Module, loadModuleInfoClass, $Class*, $InputStream*), "java.io.IOException"},
	{"moduleInfoClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(Module, moduleInfoClass, $Class*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Module, toString, $String*)},
	{}
};

#define _METHOD_INDEX_addExports0 4
#define _METHOD_INDEX_addExportsToAll0 5
#define _METHOD_INDEX_addExportsToAllUnnamed0 6
#define _METHOD_INDEX_addReads0 9
#define _METHOD_INDEX_defineModule0 14

$InnerClassInfo _Module_InnerClassesInfo_[] = {
	{"java.lang.Module$ReflectionData", "java.lang.Module", "ReflectionData", $PRIVATE | $STATIC},
	{"java.lang.Module$ArchivedData", "java.lang.Module", "ArchivedData", $PRIVATE | $STATIC},
	{"java.lang.Module$2", nullptr, nullptr, 0},
	{"java.lang.Module$1", nullptr, nullptr, 0},
	{"java.lang.Module$1DummyModuleInfo", nullptr, "DummyModuleInfo", 0},
	{}
};

$ClassInfo _Module_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.Module",
	"java.lang.Object",
	"java.lang.reflect.AnnotatedElement",
	_Module_FieldInfo_,
	_Module_MethodInfo_,
	nullptr,
	nullptr,
	_Module_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.Module$ReflectionData,java.lang.Module$ArchivedData,java.lang.Module$2,java.lang.Module$1,java.lang.Module$1DummyModuleInfo"
};

$Object* allocate$Module($Class* clazz) {
	return $of($alloc(Module));
}

bool Module::$assertionsDisabled = false;
Module* Module::ALL_UNNAMED_MODULE = nullptr;
$Set* Module::ALL_UNNAMED_MODULE_SET = nullptr;
Module* Module::EVERYONE_MODULE = nullptr;
$Set* Module::EVERYONE_SET = nullptr;

void Module::init$($ModuleLayer* layer, $ClassLoader* loader, $ModuleDescriptor* descriptor, $URI* uri) {
	$useLocalCurrentObjectStackCache();
	$set(this, layer, layer);
	$set(this, name, $nc(descriptor)->name());
	$set(this, loader, loader);
	$set(this, descriptor, descriptor);
	bool var$0 = descriptor->isOpen();
	bool isOpen = var$0 || descriptor->isAutomatic();
	$var($ModuleDescriptor$Version, version, $cast($ModuleDescriptor$Version, $nc($(descriptor->version()))->orElse(nullptr)));
	$var($String, vs, $Objects::toString(version, nullptr));
	$var($String, loc, $Objects::toString(uri, nullptr));
	$var($ObjectArray, packages, $nc($(descriptor->packages()))->toArray());
	defineModule0(this, isOpen, vs, loc, packages);
	if (loader == nullptr || loader == $ClassLoaders::platformClassLoader()) {
		implAddEnableNativeAccess();
	}
}

void Module::init$($ClassLoader* loader) {
	$set(this, layer, nullptr);
	$set(this, name, nullptr);
	$set(this, loader, loader);
	$set(this, descriptor, nullptr);
}

void Module::init$($ClassLoader* loader, $ModuleDescriptor* descriptor) {
	$set(this, layer, nullptr);
	$set(this, name, $nc(descriptor)->name());
	$set(this, loader, loader);
	$set(this, descriptor, descriptor);
}

bool Module::isNamed() {
	return this->name != nullptr;
}

$String* Module::getName() {
	return this->name;
}

$ClassLoader* Module::getClassLoader() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
	}
	return this->loader;
}

$ModuleDescriptor* Module::getDescriptor() {
	return this->descriptor;
}

$ModuleLayer* Module::getLayer() {
	if (isNamed()) {
		$var($ModuleLayer, layer, this->layer);
		if (layer != nullptr) {
			return layer;
		}
		if (this->loader == nullptr && $nc(this->name)->equals("java.base"_s)) {
			return $ModuleLayer::boot();
		}
	}
	return nullptr;
}

Module* Module::implAddEnableNativeAccess() {
	this->enableNativeAccess = true;
	return this;
}

void Module::implAddEnableNativeAccessAllUnnamed() {
	$init(Module);
	$nc(Module::ALL_UNNAMED_MODULE)->enableNativeAccess = true;
}

bool Module::implIsEnableNativeAccess() {
	return isNamed() ? $cast(bool, this->enableNativeAccess) : $cast(bool, $nc(Module::ALL_UNNAMED_MODULE)->enableNativeAccess);
}

bool Module::canRead(Module* other) {
	$Objects::requireNonNull(other);
	if (!this->isNamed()) {
		return true;
	}
	if (other == this) {
		return true;
	}
	if (other->isNamed()) {
		$var($Set, reads, this->reads);
		if (reads != nullptr && reads->contains(other)) {
			return true;
		}
	}
	$init($Module$ReflectionData);
	if ($nc($Module$ReflectionData::reads)->containsKeyPair(this, other)) {
		return true;
	}
	bool var$0 = !other->isNamed();
	if (var$0 && $nc($Module$ReflectionData::reads)->containsKeyPair(this, Module::ALL_UNNAMED_MODULE)) {
		return true;
	}
	return false;
}

Module* Module::addReads(Module* other) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(other);
	if (this->isNamed()) {
		$var(Module, caller, getCallerModule($Reflection::getCallerClass()));
		if (caller != this) {
			$throwNew($IllegalCallerException, $$str({caller, " != "_s, this}));
		}
		implAddReads(other, true);
	}
	return this;
}

void Module::implAddReads(Module* other) {
	implAddReads(other, true);
}

void Module::implAddReadsAllUnnamed() {
	implAddReads(Module::ALL_UNNAMED_MODULE, true);
}

void Module::implAddReadsNoSync(Module* other) {
	implAddReads(other, false);
}

void Module::implAddReads(Module* other, bool syncVM) {
	$Objects::requireNonNull(other);
	if (!canRead(other)) {
		if (syncVM) {
			if (other == Module::ALL_UNNAMED_MODULE) {
				addReads0(this, nullptr);
			} else {
				addReads0(this, other);
			}
		}
		$init($Module$ReflectionData);
		$init($Boolean);
		$nc($Module$ReflectionData::reads)->putIfAbsent(this, other, $Boolean::TRUE);
	}
}

bool Module::isExported($String* pn, Module* other) {
	$Objects::requireNonNull(pn);
	$Objects::requireNonNull(other);
	return implIsExportedOrOpen(pn, other, false);
}

bool Module::isOpen($String* pn, Module* other) {
	$Objects::requireNonNull(pn);
	$Objects::requireNonNull(other);
	return implIsExportedOrOpen(pn, other, true);
}

bool Module::isExported($String* pn) {
	$Objects::requireNonNull(pn);
	return implIsExportedOrOpen(pn, Module::EVERYONE_MODULE, false);
}

bool Module::isOpen($String* pn) {
	$Objects::requireNonNull(pn);
	return implIsExportedOrOpen(pn, Module::EVERYONE_MODULE, true);
}

bool Module::implIsExportedOrOpen($String* pn, Module* other, bool open) {
	$useLocalCurrentObjectStackCache();
	if (!isNamed()) {
		return true;
	}
	if (other == this && $nc($($nc(this->descriptor)->packages()))->contains(pn)) {
		return true;
	}
	bool var$0 = $nc(this->descriptor)->isOpen();
	if (var$0 || $nc(this->descriptor)->isAutomatic()) {
		return $nc($($nc(this->descriptor)->packages()))->contains(pn);
	}
	if (isStaticallyExportedOrOpen(pn, other, open)) {
		return true;
	}
	if (isReflectivelyExportedOrOpen(pn, other, open)) {
		return true;
	}
	return false;
}

bool Module::isStaticallyExportedOrOpen($String* pn, Module* other, bool open) {
	$useLocalCurrentObjectStackCache();
	$var($Map, openPackages, this->openPackages);
	if (openPackages != nullptr && allows($cast($Set, $(openPackages->get(pn))), other)) {
		return true;
	}
	if (!open) {
		$var($Map, exportedPackages, this->exportedPackages);
		if (exportedPackages != nullptr && allows($cast($Set, $(exportedPackages->get(pn))), other)) {
			return true;
		}
	}
	return false;
}

bool Module::allows($Set* targets, Module* module) {
	if (targets != nullptr) {
		if (targets->contains(Module::EVERYONE_MODULE)) {
			return true;
		}
		if (module != Module::EVERYONE_MODULE) {
			if (targets->contains(module)) {
				return true;
			}
			bool var$0 = !$nc(module)->isNamed();
			if (var$0 && targets->contains(Module::ALL_UNNAMED_MODULE)) {
				return true;
			}
		}
	}
	return false;
}

bool Module::isReflectivelyExportedOrOpen($String* pn, Module* other, bool open) {
	$useLocalCurrentObjectStackCache();
	$init($Module$ReflectionData);
	$var($Map, exports, $cast($Map, $nc($Module$ReflectionData::exports)->get(this, Module::EVERYONE_MODULE)));
	if (exports != nullptr) {
		$var($Boolean, b, $cast($Boolean, exports->get(pn)));
		if (b != nullptr) {
			bool isOpen = b->booleanValue();
			if (!open || isOpen) {
				return true;
			}
		}
	}
	if (other != Module::EVERYONE_MODULE) {
		$assign(exports, $cast($Map, $nc($Module$ReflectionData::exports)->get(this, other)));
		if (exports != nullptr) {
			$var($Boolean, b, $cast($Boolean, exports->get(pn)));
			if (b != nullptr) {
				bool isOpen = b->booleanValue();
				if (!open || isOpen) {
					return true;
				}
			}
		}
		if (!$nc(other)->isNamed()) {
			$assign(exports, $cast($Map, $nc($Module$ReflectionData::exports)->get(this, Module::ALL_UNNAMED_MODULE)));
			if (exports != nullptr) {
				$var($Boolean, b, $cast($Boolean, exports->get(pn)));
				if (b != nullptr) {
					bool isOpen = b->booleanValue();
					if (!open || isOpen) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Module::isReflectivelyExported($String* pn, Module* other) {
	return isReflectivelyExportedOrOpen(pn, other, false);
}

bool Module::isReflectivelyOpened($String* pn, Module* other) {
	return isReflectivelyExportedOrOpen(pn, other, true);
}

Module* Module::addExports($String* pn, Module* other) {
	$useLocalCurrentObjectStackCache();
	if (pn == nullptr) {
		$throwNew($IllegalArgumentException, "package is null"_s);
	}
	$Objects::requireNonNull(other);
	if (isNamed()) {
		$var(Module, caller, getCallerModule($Reflection::getCallerClass()));
		if (caller != this) {
			$throwNew($IllegalCallerException, $$str({caller, " != "_s, this}));
		}
		implAddExportsOrOpens(pn, other, false, true);
	}
	return this;
}

Module* Module::addOpens($String* pn, Module* other) {
	$useLocalCurrentObjectStackCache();
	if (pn == nullptr) {
		$throwNew($IllegalArgumentException, "package is null"_s);
	}
	$Objects::requireNonNull(other);
	if (isNamed()) {
		$var(Module, caller, getCallerModule($Reflection::getCallerClass()));
		if (caller != this && (caller == nullptr || !isOpen(pn, caller))) {
			$throwNew($IllegalCallerException, $$str({pn, " is not open to "_s, caller}));
		}
		implAddExportsOrOpens(pn, other, true, true);
	}
	return this;
}

void Module::implAddExports($String* pn) {
	implAddExportsOrOpens(pn, Module::EVERYONE_MODULE, false, true);
}

void Module::implAddExports($String* pn, Module* other) {
	implAddExportsOrOpens(pn, other, false, true);
}

void Module::implAddExportsToAllUnnamed($String* pn) {
	implAddExportsOrOpens(pn, Module::ALL_UNNAMED_MODULE, false, true);
}

void Module::implAddExportsNoSync($String* pn) {
	implAddExportsOrOpens($($nc(pn)->replace(u'/', u'.')), Module::EVERYONE_MODULE, false, false);
}

void Module::implAddExportsNoSync($String* pn, Module* other) {
	implAddExportsOrOpens($($nc(pn)->replace(u'/', u'.')), other, false, false);
}

void Module::implAddOpens($String* pn) {
	implAddExportsOrOpens(pn, Module::EVERYONE_MODULE, true, true);
}

void Module::implAddOpens($String* pn, Module* other) {
	implAddExportsOrOpens(pn, other, true, true);
}

void Module::implAddOpensToAllUnnamed($String* pn) {
	implAddExportsOrOpens(pn, Module::ALL_UNNAMED_MODULE, true, true);
}

void Module::implAddExportsOrOpens($String* pn, Module* other, bool open, bool syncVM) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(other);
	$Objects::requireNonNull(pn);
	bool var$1 = !isNamed();
	bool var$0 = var$1 || $nc(this->descriptor)->isOpen();
	if (var$0 || $nc(this->descriptor)->isAutomatic()) {
		return;
	}
	if (implIsExportedOrOpen(pn, other, open)) {
		return;
	}
	if (!$nc($($nc(this->descriptor)->packages()))->contains(pn)) {
		$throwNew($IllegalArgumentException, $$str({"package "_s, pn, " not in contents"_s}));
	}
	if (syncVM) {
		if (other == Module::EVERYONE_MODULE) {
			addExportsToAll0(this, pn);
		} else if (other == Module::ALL_UNNAMED_MODULE) {
			addExportsToAllUnnamed0(this, pn);
		} else {
			addExports0(this, pn, other);
		}
	}
	$init($Module$ReflectionData);
	$var($Map, map, $cast($Map, $nc($Module$ReflectionData::exports)->computeIfAbsent(this, other, static_cast<$BiFunction*>($$new(Module$$Lambda$lambda$implAddExportsOrOpens$0)))));
	if (open) {
		$init($Boolean);
		$nc(map)->put(pn, $Boolean::TRUE);
	} else {
		$init($Boolean);
		$nc(map)->putIfAbsent(pn, $Boolean::FALSE);
	}
}

void Module::implAddOpensToAllUnnamed($Set* concealedPkgs, $Set* exportedPkgs) {
	if ($VM::isModuleSystemInited()) {
		$throwNew($IllegalStateException, "Module system already initialized"_s);
	}
	$var($Map, openPackages, this->openPackages);
	if (openPackages == nullptr) {
		int32_t var$0 = 4;
		int32_t var$2 = $nc(concealedPkgs)->size();
		int32_t var$1 = (var$2 + $nc(exportedPkgs)->size());
		$assign(openPackages, $new($HashMap, (var$0 * var$1 / 3) + 1));
	} else {
		$assign(openPackages, $new($HashMap, openPackages));
	}
	implAddOpensToAllUnnamed(concealedPkgs, openPackages);
	implAddOpensToAllUnnamed(exportedPkgs, openPackages);
	$set(this, openPackages, openPackages);
}

void Module::implAddOpensToAllUnnamed($Set* pkgs, $Map* openPackages) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(pkgs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, pn, $cast($String, i$->next()));
			{
				$var($Set, prev, $cast($Set, $nc(openPackages)->putIfAbsent(pn, Module::ALL_UNNAMED_MODULE_SET)));
				if (prev != nullptr) {
					prev->add(Module::ALL_UNNAMED_MODULE);
				}
				addExportsToAllUnnamed0(this, pn);
			}
		}
	}
}

Module* Module::addUses($Class* service) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(service);
	bool var$0 = isNamed();
	if (var$0 && !$nc(this->descriptor)->isAutomatic()) {
		$var(Module, caller, getCallerModule($Reflection::getCallerClass()));
		if (caller != this) {
			$throwNew($IllegalCallerException, $$str({caller, " != "_s, this}));
		}
		implAddUses(service);
	}
	return this;
}

void Module::implAddUses($Class* service) {
	if (!canUse(service)) {
		$init($Module$ReflectionData);
		$init($Boolean);
		$nc($Module$ReflectionData::uses)->putIfAbsent(this, service, $Boolean::TRUE);
	}
}

bool Module::canUse($Class* service) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(service);
	if (!isNamed()) {
		return true;
	}
	if ($nc(this->descriptor)->isAutomatic()) {
		return true;
	}
	if ($nc($($nc(this->descriptor)->uses()))->contains($(service->getName()))) {
		return true;
	}
	$init($Module$ReflectionData);
	return $nc($Module$ReflectionData::uses)->containsKeyPair(this, service);
}

$Set* Module::getPackages() {
	$useLocalCurrentObjectStackCache();
	if (isNamed()) {
		return $nc(this->descriptor)->packages();
	} else {
		$var($Stream, packages, nullptr);
		if (this->loader == nullptr) {
			$assign(packages, $BootLoader::packages());
		} else {
			$assign(packages, $nc(this->loader)->packages());
		}
		return $cast($Set, $nc($($nc($($nc(packages)->filter(static_cast<$Predicate*>($$new(Module$$Lambda$lambda$getPackages$1$1, this)))))->map(static_cast<$Function*>($$new(Module$$Lambda$getName$2)))))->collect($($Collectors::toSet())));
	}
}

$Map* Module::defineModules($Configuration* cf, $Function* clf, $ModuleLayer* layer) {
	$init(Module);
	$useLocalCurrentObjectStackCache();
	bool isBootLayer = ($ModuleLayer::boot() == nullptr);
	int32_t numModules = $nc($($nc(cf)->modules()))->size();
	int32_t cap = $cast(int32_t, (numModules / 0.75f + 1.0f));
	$var($Map, nameToModule, $new($HashMap, cap));
	$var($ResolvedModuleArray, resolvedModules, $new($ResolvedModuleArray, numModules));
	$var($ModuleArray, modules, $new($ModuleArray, numModules));
	$var($ClassLoaderArray, classLoaders, $new($ClassLoaderArray, numModules));
	$assign(resolvedModules, $fcast($ResolvedModuleArray, $nc($(cf->modules()))->toArray(resolvedModules)));
	$var($HashSet, toBindLoaders, $new($HashSet, 4));
	bool hasPlatformModules = false;
	$var($ClassLoader, pcl, $ClassLoaders::platformClassLoader());
	bool isModuleLoaderMapper = $ModuleLoaderMap::isBuiltinMapper(clf);
	for (int32_t index = 0; index < numModules; ++index) {
		$var($String, name, $nc($nc(resolvedModules)->get(index))->name());
		$var($ClassLoader, loader, $cast($ClassLoader, $nc(clf)->apply(name)));
		if (loader == nullptr || loader == pcl) {
			if (!isModuleLoaderMapper) {
				$throwNew($IllegalArgumentException, "loader can\'t be \'null\' or the platform class loader"_s);
			}
			hasPlatformModules = true;
		} else {
			toBindLoaders->add(loader);
		}
		classLoaders->set(index, loader);
	}
	for (int32_t index = 0; index < numModules; ++index) {
		$var($ModuleReference, mref, $nc($nc(resolvedModules)->get(index))->reference());
		$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
		$var($String, name, $nc(descriptor)->name());
		$var($ClassLoader, loader, classLoaders->get(index));
		$var(Module, m, nullptr);
		if (loader == nullptr && $nc(name)->equals("java.base"_s)) {
			$assign(m, $Object::class$->getModule());
		} else {
			$var($URI, uri, $cast($URI, $nc($(mref->location()))->orElse(nullptr)));
			$assign(m, $new(Module, layer, loader, descriptor, uri));
		}
		nameToModule->put(name, m);
		modules->set(index, m);
	}
	for (int32_t index = 0; index < numModules; ++index) {
		$var($ResolvedModule, resolvedModule, $nc(resolvedModules)->get(index));
		$var($ModuleReference, mref, $nc(resolvedModule)->reference());
		$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
		$var(Module, m, modules->get(index));
		$var($Set, reads, $new($HashSet));
		$var($Map, nameToSource, $Map::of());
		{
			$var($Iterator, i$, $nc($(resolvedModule->reads()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ResolvedModule, other, $cast($ResolvedModule, i$->next()));
				{
					$var(Module, m2, nullptr);
					if ($nc(other)->configuration() == cf) {
						$assign(m2, $cast(Module, nameToModule->get($(other->name()))));
						if (!Module::$assertionsDisabled && !(m2 != nullptr)) {
							$throwNew($AssertionError);
						}
					} else {
						{
							$var($Iterator, i$, $nc($($nc(layer)->parents()))->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($ModuleLayer, parent, $cast($ModuleLayer, i$->next()));
								{
									$assign(m2, findModule(parent, other));
									if (m2 != nullptr) {
										break;
									}
								}
							}
						}
						if (!Module::$assertionsDisabled && !(m2 != nullptr)) {
							$throwNew($AssertionError);
						}
						if ($nc(nameToSource)->isEmpty()) {
							$assign(nameToSource, $new($HashMap));
						}
						$nc(nameToSource)->put($(other->name()), m2);
					}
					reads->add(m2);
					addReads0(m, m2);
				}
			}
		}
		$set($nc(m), reads, reads);
		if ($nc(descriptor)->isAutomatic()) {
			m->implAddReads(Module::ALL_UNNAMED_MODULE, true);
		}
		bool var$0 = !$nc(descriptor)->isOpen();
		if (var$0 && !descriptor->isAutomatic()) {
			if (isBootLayer && $nc($(descriptor->opens()))->isEmpty()) {
				initExports(m, nameToModule);
			} else {
				initExportsAndOpens(m, nameToSource, nameToModule, $($nc(layer)->parents()));
			}
		}
	}
	if (hasPlatformModules) {
		$var($ServicesCatalog, bootCatalog, $BootLoader::getServicesCatalog());
		$var($ServicesCatalog, pclCatalog, $ServicesCatalog::getServicesCatalog(pcl));
		for (int32_t index = 0; index < numModules; ++index) {
			$var($ResolvedModule, resolvedModule, $nc(resolvedModules)->get(index));
			$var($ModuleReference, mref, $nc(resolvedModule)->reference());
			$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
			if (!$nc($($nc(descriptor)->provides()))->isEmpty()) {
				$var(Module, m, modules->get(index));
				$var($ClassLoader, loader, classLoaders->get(index));
				if (loader == nullptr) {
					$nc(bootCatalog)->register$(m);
				} else if (loader == pcl) {
					$nc(pclCatalog)->register$(m);
				}
			}
		}
	}
	{
		$var($Iterator, i$, toBindLoaders->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ClassLoader, loader, $cast($ClassLoader, i$->next()));
			{
				$nc(layer)->bindToLoader(loader);
			}
		}
	}
	return nameToModule;
}

Module* Module::findModule($ModuleLayer* parent, $ResolvedModule* resolvedModule) {
	$init(Module);
	$useLocalCurrentObjectStackCache();
	$var($Configuration, cf, $nc(resolvedModule)->configuration());
	$var($String, dn, resolvedModule->name());
	return $cast(Module, $nc($($nc($($nc($($nc($($nc(parent)->layers()))->filter(static_cast<$Predicate*>($$new(Module$$Lambda$lambda$findModule$2$3, cf)))))->findAny()))->map(static_cast<$Function*>($$new(Module$$Lambda$lambda$findModule$3$4, dn)))))->orElse(nullptr));
}

void Module::initExports(Module* m, $Map* nameToModule) {
	$init(Module);
	$useLocalCurrentObjectStackCache();
	$var($Map, exportedPackages, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc($($nc(m)->getDescriptor()))->exports()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Exports, exports, $cast($ModuleDescriptor$Exports, i$->next()));
			{
				$var($String, source, $nc(exports)->source());
				if (exports->isQualified()) {
					$var($Set, targets, $new($HashSet));
					{
						$var($Iterator, i$, $nc($(exports->targets()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, target, $cast($String, i$->next()));
							{
								$var(Module, m2, $cast(Module, $nc(nameToModule)->get(target)));
								if (m2 != nullptr) {
									addExports0(m, source, m2);
									targets->add(m2);
								}
							}
						}
					}
					if (!targets->isEmpty()) {
						exportedPackages->put(source, targets);
					}
				} else {
					addExportsToAll0(m, source);
					exportedPackages->put(source, Module::EVERYONE_SET);
				}
			}
		}
	}
	if (!exportedPackages->isEmpty()) {
		$set(m, exportedPackages, exportedPackages);
	}
}

void Module::initExportsAndOpens(Module* m, $Map* nameToSource, $Map* nameToModule, $List* parents) {
	$init(Module);
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, descriptor, $nc(m)->getDescriptor());
	$var($Map, openPackages, $new($HashMap));
	$var($Map, exportedPackages, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc(descriptor)->opens()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Opens, opens, $cast($ModuleDescriptor$Opens, i$->next()));
			{
				$var($String, source, $nc(opens)->source());
				if (opens->isQualified()) {
					$var($Set, targets, $new($HashSet));
					{
						$var($Iterator, i$, $nc($(opens->targets()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, target, $cast($String, i$->next()));
							{
								$var(Module, m2, findModule(target, nameToSource, nameToModule, parents));
								if (m2 != nullptr) {
									addExports0(m, source, m2);
									targets->add(m2);
								}
							}
						}
					}
					if (!targets->isEmpty()) {
						openPackages->put(source, targets);
					}
				} else {
					addExportsToAll0(m, source);
					openPackages->put(source, Module::EVERYONE_SET);
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc($(descriptor->exports()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Exports, exports, $cast($ModuleDescriptor$Exports, i$->next()));
			{
				$var($String, source, $nc(exports)->source());
				$var($Set, openToTargets, $cast($Set, openPackages->get(source)));
				if (openToTargets != nullptr && openToTargets->contains(Module::EVERYONE_MODULE)) {
					continue;
				}
				if (exports->isQualified()) {
					$var($Set, targets, $new($HashSet));
					{
						$var($Iterator, i$, $nc($(exports->targets()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, target, $cast($String, i$->next()));
							{
								$var(Module, m2, findModule(target, nameToSource, nameToModule, parents));
								if (m2 != nullptr) {
									if (openToTargets == nullptr || !$nc(openToTargets)->contains(m2)) {
										addExports0(m, source, m2);
										targets->add(m2);
									}
								}
							}
						}
					}
					if (!targets->isEmpty()) {
						exportedPackages->put(source, targets);
					}
				} else {
					addExportsToAll0(m, source);
					exportedPackages->put(source, Module::EVERYONE_SET);
				}
			}
		}
	}
	if (!openPackages->isEmpty()) {
		$set(m, openPackages, openPackages);
	}
	if (!exportedPackages->isEmpty()) {
		$set(m, exportedPackages, exportedPackages);
	}
}

Module* Module::findModule($String* target, $Map* nameToSource, $Map* nameToModule, $List* parents) {
	$init(Module);
	$useLocalCurrentObjectStackCache();
	$var(Module, m, $cast(Module, $nc(nameToSource)->get(target)));
	if (m == nullptr) {
		$assign(m, $cast(Module, $nc(nameToModule)->get(target)));
		if (m == nullptr) {
			{
				$var($Iterator, i$, $nc(parents)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($ModuleLayer, parent, $cast($ModuleLayer, i$->next()));
					{
						$assign(m, $cast(Module, $nc($($nc(parent)->findModule(target)))->orElse(nullptr)));
						if (m != nullptr) {
							break;
						}
					}
				}
			}
		}
	}
	return m;
}

$Annotation* Module::getAnnotation($Class* annotationClass) {
	return $nc(moduleInfoClass())->getDeclaredAnnotation(annotationClass);
}

$AnnotationArray* Module::getAnnotations() {
	return $nc(moduleInfoClass())->getAnnotations();
}

$AnnotationArray* Module::getDeclaredAnnotations() {
	return $nc(moduleInfoClass())->getDeclaredAnnotations();
}

$Class* Module::moduleInfoClass() {
	$beforeCallerSensitive();
	$Class* clazz = this->moduleInfoClass$;
	if (clazz != nullptr) {
		return clazz;
	}
	$synchronized(this) {
		clazz = this->moduleInfoClass$;
		if (clazz == nullptr) {
			if (isNamed()) {
				$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(Module$$Lambda$loadModuleInfoClass$5, this)));
				clazz = $cast($Class, $AccessController::doPrivileged(pa));
			}
			if (clazz == nullptr) {
				{
				}
				$load($Module$1DummyModuleInfo);
				clazz = $Module$1DummyModuleInfo::class$;
			}
			$set(this, moduleInfoClass$, clazz);
		}
		return clazz;
	}
}

$Class* Module::loadModuleInfoClass() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* clazz = nullptr;
	try {
		$var($InputStream, in, getResourceAsStream("module-info.class"_s));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if (in != nullptr) {
						clazz = loadModuleInfoClass(in);
					}
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (in != nullptr) {
					in->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& ignore) {
	}
	return clazz;
}

$Class* Module::loadModuleInfoClass($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($String, MODULE_INFO, "module-info"_s);
	$var($ClassWriter, cw, $new($ClassWriter, $ClassWriter::COMPUTE_MAXS + $ClassWriter::COMPUTE_FRAMES));
	$var($ClassVisitor, cv, $new($Module$1, this, $Opcodes::ASM7, cw, cw));
	$var($ClassReader, cr, $new($ClassReader, in));
	cr->accept(cv, 0);
	$var($bytes, bytes, cw->toByteArray());
	$var($ClassLoader, cl, $new($Module$2, this, this->loader, bytes));
	try {
		return cl->loadClass(MODULE_INFO);
	} catch ($ClassNotFoundException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$InputStream* Module::getResourceAsStream($String* name$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	if ($nc(name)->startsWith("/"_s)) {
		$assign(name, name->substring(1));
	}
	bool var$0 = isNamed();
	if (var$0 && $Resources::canEncapsulate(name)) {
		$var(Module, caller, getCallerModule($Reflection::getCallerClass()));
		if (caller != this && caller != $Object::class$->getModule()) {
			$var($String, pn, $Resources::toPackageName(name));
			if ($nc($(getPackages()))->contains(pn)) {
				if (caller == nullptr && !isOpen(pn)) {
					return nullptr;
				}
				if (!isOpen(pn, caller)) {
					return nullptr;
				}
			}
		}
	}
	$var($String, mn, this->name);
	if (this->loader == nullptr) {
		return $BootLoader::findResourceAsStream(mn, name);
	} else if ($instanceOf($BuiltinClassLoader, this->loader)) {
		return $nc(($cast($BuiltinClassLoader, this->loader)))->findResourceAsStream(mn, name);
	}
	$var($URL, url, $nc(this->loader)->findResource(mn, name));
	if (url != nullptr) {
		try {
			return url->openStream();
		} catch ($SecurityException& e) {
		}
	}
	return nullptr;
}

$String* Module::toString() {
	if (isNamed()) {
		return $str({"module "_s, this->name});
	} else {
		$var($String, id, $Integer::toHexString($System::identityHashCode(this)));
		return $str({"unnamed module @"_s, id});
	}
}

Module* Module::getCallerModule($Class* caller) {
	return (caller != nullptr) ? $nc(caller)->getModule() : (Module*)nullptr;
}

void Module::defineModule0(Module* module, bool isOpen$, $String* version, $String* location, $ObjectArray* pns) {
}

void Module::addReads0(Module* from, Module* to) {
}

void Module::addExports0(Module* from, $String* pn, Module* to) {
}

void Module::addExportsToAll0(Module* from, $String* pn) {
}

void Module::addExportsToAllUnnamed0(Module* from, $String* pn) {
}

Module* Module::lambda$findModule$3($String* dn, $ModuleLayer* layer) {
	$init(Module);
	$useLocalCurrentObjectStackCache();
	$var($Optional, om, $nc(layer)->findModule(dn));
	if (!Module::$assertionsDisabled && !$nc(om)->isPresent()) {
		$throwNew($AssertionError, $of($$str({dn, " not found in layer"_s})));
	}
	$var(Module, m, $cast(Module, $nc(om)->get()));
	if (!Module::$assertionsDisabled && !($nc(m)->getLayer() == layer)) {
		$throwNew($AssertionError, $of($$str({m, " not in expected layer"_s})));
	}
	return m;
}

bool Module::lambda$findModule$2($Configuration* cf, $ModuleLayer* l) {
	$init(Module);
	return $nc(l)->configuration() == cf;
}

bool Module::lambda$getPackages$1($Package* p) {
	return $nc(p)->module() == this;
}

$Map* Module::lambda$implAddExportsOrOpens$0(Module* m1, Module* m2) {
	$init(Module);
	return static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap)));
}

void clinit$Module($Class* class$) {
	Module::$assertionsDisabled = !Module::class$->desiredAssertionStatus();
	{
		$var($Module$ArchivedData, archivedData, $Module$ArchivedData::get());
		if (archivedData != nullptr) {
			$assignStatic(Module::ALL_UNNAMED_MODULE, archivedData->allUnnamedModule);
			$assignStatic(Module::ALL_UNNAMED_MODULE_SET, archivedData->allUnnamedModules);
			$assignStatic(Module::EVERYONE_MODULE, archivedData->everyoneModule);
			$assignStatic(Module::EVERYONE_SET, archivedData->everyoneSet);
		} else {
			$assignStatic(Module::ALL_UNNAMED_MODULE, $new(Module, nullptr));
			$assignStatic(Module::ALL_UNNAMED_MODULE_SET, $Set::of($of(Module::ALL_UNNAMED_MODULE)));
			$assignStatic(Module::EVERYONE_MODULE, $new(Module, nullptr));
			$assignStatic(Module::EVERYONE_SET, $Set::of($of(Module::EVERYONE_MODULE)));
			$Module$ArchivedData::archive();
		}
	}
}

Module::Module() {
}

$Class* Module::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Module$$Lambda$lambda$implAddExportsOrOpens$0::classInfo$.name)) {
			return Module$$Lambda$lambda$implAddExportsOrOpens$0::load$(name, initialize);
		}
		if (name->equals(Module$$Lambda$lambda$getPackages$1$1::classInfo$.name)) {
			return Module$$Lambda$lambda$getPackages$1$1::load$(name, initialize);
		}
		if (name->equals(Module$$Lambda$getName$2::classInfo$.name)) {
			return Module$$Lambda$getName$2::load$(name, initialize);
		}
		if (name->equals(Module$$Lambda$lambda$findModule$2$3::classInfo$.name)) {
			return Module$$Lambda$lambda$findModule$2$3::load$(name, initialize);
		}
		if (name->equals(Module$$Lambda$lambda$findModule$3$4::classInfo$.name)) {
			return Module$$Lambda$lambda$findModule$3$4::load$(name, initialize);
		}
		if (name->equals(Module$$Lambda$loadModuleInfoClass$5::classInfo$.name)) {
			return Module$$Lambda$loadModuleInfoClass$5::load$(name, initialize);
		}
	}
	$loadClass(Module, name, initialize, &_Module_ClassInfo_, clinit$Module, allocate$Module);
	return class$;
}

$Class* Module::class$ = nullptr;

	} // lang
} // java