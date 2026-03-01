#include <jdk/internal/loader/BuiltinClassLoader.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Package.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor$Opens.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/lang/ref/SoftReference.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSigner.h>
#include <java/security/CodeSource.h>
#include <java/security/PermissionCollection.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/SecureClassLoader.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <java/util/jar/Attributes$Name.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/Manifest.h>
#include <jdk/internal/access/JavaUtilJarAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/ArchivedClassLoaders.h>
#include <jdk/internal/loader/BuiltinClassLoader$1.h>
#include <jdk/internal/loader/BuiltinClassLoader$2.h>
#include <jdk/internal/loader/BuiltinClassLoader$3.h>
#include <jdk/internal/loader/BuiltinClassLoader$4.h>
#include <jdk/internal/loader/BuiltinClassLoader$5.h>
#include <jdk/internal/loader/BuiltinClassLoader$LoadedModule.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/loader/Resource.h>
#include <jdk/internal/loader/URLClassPath.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ModulePatcher$PatchedModuleReader.h>
#include <jdk/internal/module/Resources.h>
#include <sun/security/util/LazyCodeSourcePermissionCollection.h>
#include <jcpp.h>

#include <java/lang/Machine.h>
#include <java/lang/module/RuntimeModuleReader.h>
using Machine = ::java::lang::Machine;
using RuntimeModuleReader = ::java::lang::module::RuntimeModuleReader;

#undef IMPLEMENTATION_TITLE
#undef IMPLEMENTATION_VENDOR
#undef IMPLEMENTATION_VERSION
#undef SEALED
#undef SPECIFICATION_TITLE
#undef SPECIFICATION_VENDOR
#undef SPECIFICATION_VERSION

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Package = ::java::lang::Package;
using $SecurityException = ::java::lang::SecurityException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Opens = ::java::lang::module::ModuleDescriptor$Opens;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $SoftReference = ::java::lang::ref::SoftReference;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $PermissionCollection = ::java::security::PermissionCollection;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SecureClassLoader = ::java::security::SecureClassLoader;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;
using $Attributes = ::java::util::jar::Attributes;
using $Attributes$Name = ::java::util::jar::Attributes$Name;
using $Manifest = ::java::util::jar::Manifest;
using $JavaUtilJarAccess = ::jdk::internal::access::JavaUtilJarAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ArchivedClassLoaders = ::jdk::internal::loader::ArchivedClassLoaders;
using $BuiltinClassLoader$1 = ::jdk::internal::loader::BuiltinClassLoader$1;
using $BuiltinClassLoader$2 = ::jdk::internal::loader::BuiltinClassLoader$2;
using $BuiltinClassLoader$3 = ::jdk::internal::loader::BuiltinClassLoader$3;
using $BuiltinClassLoader$4 = ::jdk::internal::loader::BuiltinClassLoader$4;
using $BuiltinClassLoader$5 = ::jdk::internal::loader::BuiltinClassLoader$5;
using $BuiltinClassLoader$LoadedModule = ::jdk::internal::loader::BuiltinClassLoader$LoadedModule;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $Resource = ::jdk::internal::loader::Resource;
using $URLClassPath = ::jdk::internal::loader::URLClassPath;
using $VM = ::jdk::internal::misc::VM;
using $ModulePatcher$PatchedModuleReader = ::jdk::internal::module::ModulePatcher$PatchedModuleReader;
using $Resources = ::jdk::internal::module::Resources;
using $LazyCodeSourcePermissionCollection = ::sun::security::util::LazyCodeSourcePermissionCollection;

namespace jdk {
	namespace internal {
		namespace loader {

class BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0 : public $PrivilegedAction {
	$class(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(BuiltinClassLoader* inst, $String* name) {
		$set(this, inst$, inst);
		$set(this, name, name);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$findResourceOnClassPath$0(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0>());
	}
	BuiltinClassLoader* inst$ = nullptr;
	$String* name = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, inst$)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, name)},
	{}
};
$MethodInfo BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/BuiltinClassLoader;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, init$, void, BuiltinClassLoader*, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, run, $Object*)},
	{}
};
$ClassInfo BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::load$($String* name, bool initialize) {
	$loadClass(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::class$ = nullptr;

class BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1 : public $PrivilegedAction {
	$class(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(BuiltinClassLoader* inst, $String* name) {
		$set(this, inst$, inst);
		$set(this, name, name);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$findResourcesOnClassPath$1(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1>());
	}
	BuiltinClassLoader* inst$ = nullptr;
	$String* name = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, inst$)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, name)},
	{}
};
$MethodInfo BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/BuiltinClassLoader;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, init$, void, BuiltinClassLoader*, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, run, $Object*)},
	{}
};
$ClassInfo BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::load$($String* name, bool initialize) {
	$loadClass(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::class$ = nullptr;

class BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2 : public $PrivilegedAction {
	$class(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(BuiltinClassLoader* inst, $String* cn, $BuiltinClassLoader$LoadedModule* loadedModule) {
		$set(this, inst$, inst);
		$set(this, cn, cn);
		$set(this, loadedModule, loadedModule);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$findClassInModuleOrNull$2(cn, loadedModule));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2>());
	}
	BuiltinClassLoader* inst$ = nullptr;
	$String* cn = nullptr;
	$BuiltinClassLoader$LoadedModule* loadedModule = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, inst$)},
	{"cn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, cn)},
	{"loadedModule", "Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;", nullptr, $PUBLIC, $field(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, loadedModule)},
	{}
};
$MethodInfo BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/loader/BuiltinClassLoader;Ljava/lang/String;Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;)V", nullptr, $PUBLIC, $method(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, init$, void, BuiltinClassLoader*, $String*, $BuiltinClassLoader$LoadedModule*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, run, $Object*)},
	{}
};
$ClassInfo BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.loader.BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::load$($String* name, bool initialize) {
	$loadClass(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::class$ = nullptr;

$CompoundAttribute _BuiltinClassLoader_FieldAnnotations_ucp[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _BuiltinClassLoader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BuiltinClassLoader, $assertionsDisabled)},
	{"parent", "Ljdk/internal/loader/BuiltinClassLoader;", nullptr, $PRIVATE | $FINAL, $field(BuiltinClassLoader, parent)},
	{"ucp", "Ljdk/internal/loader/URLClassPath;", nullptr, $PRIVATE, $field(BuiltinClassLoader, ucp), _BuiltinClassLoader_FieldAnnotations_ucp},
	{"packageToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;>;", $PRIVATE | $STATIC | $FINAL, $staticField(BuiltinClassLoader, packageToModule$)},
	{"nameToModule", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/module/ModuleReference;>;", $PRIVATE | $FINAL, $field(BuiltinClassLoader, nameToModule)},
	{"moduleToReader", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/module/ModuleReference;Ljava/lang/module/ModuleReader;>;", $PRIVATE | $FINAL, $field(BuiltinClassLoader, moduleToReader)},
	{"resourceCache", "Ljava/lang/ref/SoftReference;", "Ljava/lang/ref/SoftReference<Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/net/URL;>;>;>;", $PRIVATE | $VOLATILE, $field(BuiltinClassLoader, resourceCache)},
	{}
};

$MethodInfo _BuiltinClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljdk/internal/loader/BuiltinClassLoader;Ljdk/internal/loader/URLClassPath;)V", nullptr, 0, $method(BuiltinClassLoader, init$, void, $String*, BuiltinClassLoader*, $URLClassPath*)},
	{"appendClassPath", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(BuiltinClassLoader, appendClassPath, void, $String*)},
	{"checkURL", "(Ljava/net/URL;)Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticMethod(BuiltinClassLoader, checkURL, $URL*, $URL*)},
	{"defineClass", "(Ljava/lang/String;Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;)Ljava/lang/Class;", "(Ljava/lang/String;Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;)Ljava/lang/Class<*>;", $PRIVATE, $method(BuiltinClassLoader, defineClass, $Class*, $String*, $BuiltinClassLoader$LoadedModule*)},
	{"defineClass", "(Ljava/lang/String;Ljdk/internal/loader/Resource;)Ljava/lang/Class;", "(Ljava/lang/String;Ljdk/internal/loader/Resource;)Ljava/lang/Class<*>;", $PRIVATE, $method(BuiltinClassLoader, defineClass, $Class*, $String*, $Resource*), "java.io.IOException"},
	{"defineOrCheckPackage", "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PROTECTED, $virtualMethod(BuiltinClassLoader, defineOrCheckPackage, $Package*, $String*, $Manifest*, $URL*)},
	{"definePackage", "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PRIVATE, $method(BuiltinClassLoader, definePackage, $Package*, $String*, $Manifest*, $URL*)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(BuiltinClassLoader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"findClass", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(BuiltinClassLoader, findClass, $Class*, $String*, $String*)},
	{"findClassInModuleOrNull", "(Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;Ljava/lang/String;)Ljava/lang/Class;", "(Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE, $method(BuiltinClassLoader, findClassInModuleOrNull, $Class*, $BuiltinClassLoader$LoadedModule*, $String*)},
	{"findClassOnClassPathOrNull", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE, $method(BuiltinClassLoader, findClassOnClassPathOrNull, $Class*, $String*)},
	{"findLoadedModule", "(Ljava/lang/String;)Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;", nullptr, $PRIVATE, $method(BuiltinClassLoader, findLoadedModule, $BuiltinClassLoader$LoadedModule*, $String*)},
	{"findLoadedModule", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;", nullptr, $PRIVATE, $method(BuiltinClassLoader, findLoadedModule, $BuiltinClassLoader$LoadedModule*, $String*, $String*)},
	{"findMiscResource", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/net/URL;>;", $PRIVATE, $method(BuiltinClassLoader, findMiscResource, $List*, $String*), "java.io.IOException"},
	{"findModule", "(Ljava/lang/String;)Ljava/lang/module/ModuleReference;", nullptr, $PROTECTED, $virtualMethod(BuiltinClassLoader, findModule, $ModuleReference*, $String*)},
	{"findResource", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader, findResource, $URL*, $String*, $String*), "java.io.IOException"},
	{"findResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader, findResource, $URL*, $String*)},
	{"findResource", "(Ljava/lang/module/ModuleReference;Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE, $method(BuiltinClassLoader, findResource, $URL*, $ModuleReference*, $String*), "java.io.IOException"},
	{"findResourceAsStream", "(Ljava/lang/String;Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader, findResourceAsStream, $InputStream*, $String*, $String*), "java.io.IOException"},
	{"findResourceOnClassPath", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE, $method(BuiltinClassLoader, findResourceOnClassPath, $URL*, $String*)},
	{"findResourceOrNull", "(Ljava/lang/module/ModuleReference;Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE, $method(BuiltinClassLoader, findResourceOrNull, $URL*, $ModuleReference*, $String*)},
	{"findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(BuiltinClassLoader, findResources, $Enumeration*, $String*), "java.io.IOException"},
	{"findResourcesOnClassPath", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PRIVATE, $method(BuiltinClassLoader, findResourcesOnClassPath, $Enumeration*, $String*)},
	{"getAndVerifyPackage", "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PRIVATE, $method(BuiltinClassLoader, getAndVerifyPackage, $Package*, $String*, $Manifest*, $URL*)},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED, $virtualMethod(BuiltinClassLoader, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"hasClassPath", "()Z", nullptr, 0, $virtualMethod(BuiltinClassLoader, hasClassPath, bool)},
	{"isOpen", "(Ljava/lang/module/ModuleReference;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(BuiltinClassLoader, isOpen, bool, $ModuleReference*, $String*)},
	{"isSealed", "(Ljava/lang/String;Ljava/util/jar/Manifest;)Z", nullptr, $PRIVATE, $method(BuiltinClassLoader, isSealed, bool, $String*, $Manifest*)},
	{"lambda$findClassInModuleOrNull$2", "(Ljava/lang/String;Ljdk/internal/loader/BuiltinClassLoader$LoadedModule;)Ljava/lang/Class;", nullptr, $PRIVATE | $SYNTHETIC, $method(BuiltinClassLoader, lambda$findClassInModuleOrNull$2, $Class*, $String*, $BuiltinClassLoader$LoadedModule*)},
	{"lambda$findResourceOnClassPath$0", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE | $SYNTHETIC, $method(BuiltinClassLoader, lambda$findResourceOnClassPath$0, $URL*, $String*)},
	{"lambda$findResourcesOnClassPath$1", "(Ljava/lang/String;)Ljava/util/Enumeration;", nullptr, $PRIVATE | $SYNTHETIC, $method(BuiltinClassLoader, lambda$findResourcesOnClassPath$1, $Enumeration*, $String*)},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(BuiltinClassLoader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{"loadClassOrNull", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(BuiltinClassLoader, loadClassOrNull, $Class*, $String*, bool)},
	{"loadClassOrNull", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED | $FINAL, $method(BuiltinClassLoader, loadClassOrNull, $Class*, $String*)},
	{"loadModule", "(Ljava/lang/module/ModuleReference;)V", nullptr, $PUBLIC, $virtualMethod(BuiltinClassLoader, loadModule, void, $ModuleReference*)},
	{"moduleReaderFor", "(Ljava/lang/module/ModuleReference;)Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE, $method(BuiltinClassLoader, moduleReaderFor, $ModuleReader*, $ModuleReference*)},
	{"packageToModule", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;*>;", $STATIC, $staticMethod(BuiltinClassLoader, packageToModule, $Map*)},
	{"resetArchivedStates", "()V", nullptr, $PRIVATE, $method(BuiltinClassLoader, resetArchivedStates, void)},
	{"setClassPath", "(Ljdk/internal/loader/URLClassPath;)V", nullptr, 0, $virtualMethod(BuiltinClassLoader, setClassPath, void, $URLClassPath*)},
	{}
};

$InnerClassInfo _BuiltinClassLoader_InnerClassesInfo_[] = {
	{"jdk.internal.loader.BuiltinClassLoader$NullModuleReader", "jdk.internal.loader.BuiltinClassLoader", "NullModuleReader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.BuiltinClassLoader$LoadedModule", "jdk.internal.loader.BuiltinClassLoader", "LoadedModule", $PRIVATE | $STATIC},
	{"jdk.internal.loader.BuiltinClassLoader$5", nullptr, nullptr, 0},
	{"jdk.internal.loader.BuiltinClassLoader$4", nullptr, nullptr, 0},
	{"jdk.internal.loader.BuiltinClassLoader$3", nullptr, nullptr, 0},
	{"jdk.internal.loader.BuiltinClassLoader$2", nullptr, nullptr, 0},
	{"jdk.internal.loader.BuiltinClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _BuiltinClassLoader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.loader.BuiltinClassLoader",
	"java.security.SecureClassLoader",
	nullptr,
	_BuiltinClassLoader_FieldInfo_,
	_BuiltinClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_BuiltinClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.loader.BuiltinClassLoader$NullModuleReader,jdk.internal.loader.BuiltinClassLoader$LoadedModule,jdk.internal.loader.BuiltinClassLoader$5,jdk.internal.loader.BuiltinClassLoader$4,jdk.internal.loader.BuiltinClassLoader$3,jdk.internal.loader.BuiltinClassLoader$2,jdk.internal.loader.BuiltinClassLoader$1"
};

$Object* allocate$BuiltinClassLoader($Class* clazz) {
	return $of($alloc(BuiltinClassLoader));
}

bool BuiltinClassLoader::$assertionsDisabled = false;
$Map* BuiltinClassLoader::packageToModule$ = nullptr;

$Map* BuiltinClassLoader::packageToModule() {
	$init(BuiltinClassLoader);
	return BuiltinClassLoader::packageToModule$;
}

void BuiltinClassLoader::init$($String* name, BuiltinClassLoader* parent, $URLClassPath* ucp) {
	$SecureClassLoader::init$(name, parent == nullptr || parent == $ClassLoaders::bootLoader() ? ($ClassLoader*)nullptr : static_cast<$ClassLoader*>(parent));
	$set(this, parent, parent);
	$set(this, ucp, ucp);
	$set(this, nameToModule, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap, 32))));
	$set(this, moduleToReader, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
}

void BuiltinClassLoader::appendClassPath($String* path) {
	$nc(this->ucp)->addFile(path);
}

void BuiltinClassLoader::setClassPath($URLClassPath* ucp) {
	$set(this, ucp, ucp);
}

bool BuiltinClassLoader::hasClassPath() {
	return this->ucp != nullptr;
}

void BuiltinClassLoader::loadModule($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
	$var($String, mn, $nc(descriptor)->name());
	if ($nc(this->nameToModule)->putIfAbsent(mn, mref) != nullptr) {
		$throwNew($InternalError, $$str({mn, " already defined to this loader"_s}));
	}
	$var($BuiltinClassLoader$LoadedModule, loadedModule, $new($BuiltinClassLoader$LoadedModule, this, mref));
	{
		$var($Iterator, i$, $nc($(descriptor->packages()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, pn, $cast($String, i$->next()));
			{
				$var($BuiltinClassLoader$LoadedModule, other, $cast($BuiltinClassLoader$LoadedModule, $nc(BuiltinClassLoader::packageToModule$)->putIfAbsent(pn, loadedModule)));
				if (other != nullptr) {
					$throwNew($InternalError, $$str({pn, " in modules "_s, mn, " and "_s, $(other->name())}));
				}
			}
		}
	}
	if (this->resourceCache != nullptr && $VM::isModuleSystemInited()) {
		$set(this, resourceCache, nullptr);
	}
}

$ModuleReference* BuiltinClassLoader::findModule($String* name) {
	return $cast($ModuleReference, $nc(this->nameToModule)->get(name));
}

$URL* BuiltinClassLoader::findResource($String* mn, $String* name) {
	$useLocalCurrentObjectStackCache();
	$var($URL, url, nullptr);
	if (mn != nullptr) {
		$var($ModuleReference, mref, $cast($ModuleReference, $nc(this->nameToModule)->get(mn)));
		if (mref != nullptr) {
			$assign(url, findResource(mref, name));
		}
	} else {
		$assign(url, findResourceOnClassPath(name));
	}
	return checkURL(url);
}

$InputStream* BuiltinClassLoader::findResourceAsStream($String* mn, $String* name) {
	$useLocalCurrentObjectStackCache();
	if ($System::getSecurityManager() != nullptr || mn == nullptr) {
		$var($URL, url, findResource(mn, name));
		return (url != nullptr) ? $nc(url)->openStream() : ($InputStream*)nullptr;
	}
	$var($ModuleReference, mref, $cast($ModuleReference, $nc(this->nameToModule)->get(mn)));
	if (mref != nullptr) {
		return $cast($InputStream, $nc($($nc($(moduleReaderFor(mref)))->open(name)))->orElse(nullptr));
	} else {
		return nullptr;
	}
}

$URL* BuiltinClassLoader::findResource($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($String, pn, $Resources::toPackageName(name));
	$var($BuiltinClassLoader$LoadedModule, module, $cast($BuiltinClassLoader$LoadedModule, $nc(BuiltinClassLoader::packageToModule$)->get(pn)));
	if (module != nullptr) {
		if (module->loader() == this) {
			$var($URL, url, nullptr);
			try {
				$assign(url, findResource($(module->name()), name));
			} catch ($IOException& ioe) {
				return nullptr;
			}
			bool var$0 = url != nullptr;
			if (var$0) {
				bool var$2 = $nc(name)->endsWith(".class"_s);
				bool var$1 = var$2 || $nc($($nc(url)->toString()))->endsWith("/"_s);
				var$0 = (var$1 || isOpen($(module->mref()), pn));
			}
			if (var$0) {
				return url;
			}
		}
	} else {
		try {
			$var($List, urls, findMiscResource(name));
			if (!$nc(urls)->isEmpty()) {
				$var($URL, url, $cast($URL, urls->get(0)));
				if (url != nullptr) {
					return checkURL(url);
				}
			}
		} catch ($IOException& ioe) {
			return nullptr;
		}
	}
	$var($URL, url, findResourceOnClassPath(name));
	return checkURL(url);
}

$Enumeration* BuiltinClassLoader::findResources($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($List, checked, $new($ArrayList));
	$var($String, pn, $Resources::toPackageName(name));
	$var($BuiltinClassLoader$LoadedModule, module, $cast($BuiltinClassLoader$LoadedModule, $nc(BuiltinClassLoader::packageToModule$)->get(pn)));
	if (module != nullptr) {
		if (module->loader() == this) {
			$var($URL, url, findResource($(module->name()), name));
			bool var$0 = url != nullptr;
			if (var$0) {
				bool var$2 = $nc(name)->endsWith(".class"_s);
				bool var$1 = var$2 || $nc($($nc(url)->toString()))->endsWith("/"_s);
				var$0 = (var$1 || isOpen($(module->mref()), pn));
			}
			if (var$0) {
				checked->add(url);
			}
		}
	} else {
		{
			$var($Iterator, i$, $nc($(findMiscResource(name)))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($URL, url, $cast($URL, i$->next()));
				{
					$assign(url, checkURL(url));
					if (url != nullptr) {
						checked->add(url);
					}
				}
			}
		}
	}
	$var($Enumeration, e, findResourcesOnClassPath(name));
	return $new($BuiltinClassLoader$1, this, checked, e);
}

$List* BuiltinClassLoader::findMiscResource($String* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SoftReference, ref, this->resourceCache);
	$var($Map, map, (ref != nullptr) ? $cast($Map, $nc(ref)->get()) : ($Map*)nullptr);
	if (map == nullptr) {
		if ($VM::isModuleSystemInited()) {
			$assign(map, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
			$set(this, resourceCache, $new($SoftReference, map));
		}
	} else {
		$var($List, urls, $cast($List, $nc(map)->get(name)));
		if (urls != nullptr) {
			return urls;
		}
	}
	$var($List, urls, nullptr);
	try {
		$assign(urls, $cast($List, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($BuiltinClassLoader$2, this, name)))));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getCause())));
	}
	if (map != nullptr) {
		map->putIfAbsent(name, urls);
	}
	return urls;
}

$URL* BuiltinClassLoader::findResource($ModuleReference* mref, $String* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($URI, u, nullptr);
	if ($System::getSecurityManager() == nullptr) {
		$assign(u, $cast($URI, $nc($($nc($(moduleReaderFor(mref)))->find(name)))->orElse(nullptr)));
	} else {
		try {
			$assign(u, $cast($URI, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($BuiltinClassLoader$3, this, mref, name)))));
		} catch ($PrivilegedActionException& pae) {
			$throw($cast($IOException, $(pae->getCause())));
		}
	}
	if (u != nullptr) {
		try {
			return u->toURL();
		} catch ($MalformedURLException& e) {
		} catch ($IllegalArgumentException& e) {
		}
	}
	return nullptr;
}

$URL* BuiltinClassLoader::findResourceOrNull($ModuleReference* mref, $String* name) {
	try {
		return findResource(mref, name);
	} catch ($IOException& ignore) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$URL* BuiltinClassLoader::findResourceOnClassPath($String* name) {
	$beforeCallerSensitive();
	$var($URL, url, Machine::findResource(name));
	if (url != nullptr) {
		return url;
	}
	if (hasClassPath()) {
		if ($System::getSecurityManager() == nullptr) {
			return $nc(this->ucp)->findResource(name, false);
		} else {
			$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0, this, name)));
			return $cast($URL, $AccessController::doPrivileged(pa));
		}
	} else {
		return nullptr;
	}
}

$Enumeration* BuiltinClassLoader::findResourcesOnClassPath($String* name) {
	$beforeCallerSensitive();
	$var($Enumeration, resources, Machine::findResources(name));
	if (resources != nullptr) {
		return resources;
	}
	if (hasClassPath()) {
		if ($System::getSecurityManager() == nullptr) {
			return $nc(this->ucp)->findResources(name, false);
		} else {
			$var($PrivilegedAction, pa, nullptr);
			$assign(pa, static_cast<$PrivilegedAction*>($new(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1, this, name)));
			return $cast($Enumeration, $AccessController::doPrivileged(pa));
		}
	} else {
		return $Collections::emptyEnumeration();
	}
}

$Class* BuiltinClassLoader::findClass($String* cn) {
	if (!$VM::isModuleSystemInited()) {
		$throwNew($ClassNotFoundException, cn);
	}
	$var($BuiltinClassLoader$LoadedModule, loadedModule, findLoadedModule(cn));
	$Class* c = nullptr;
	if (loadedModule != nullptr) {
		if (loadedModule->loader() == this) {
			c = findClassInModuleOrNull(loadedModule, cn);
		}
	} else if (hasClassPath()) {
		c = findClassOnClassPathOrNull(cn);
	}
	if (c == nullptr) {
		$throwNew($ClassNotFoundException, cn);
	}
	return c;
}

$Class* BuiltinClassLoader::findClass($String* mn, $String* cn) {
	if (mn != nullptr) {
		$var($BuiltinClassLoader$LoadedModule, loadedModule, findLoadedModule(mn, cn));
		if (loadedModule == nullptr) {
			return nullptr;
		}
		if (!BuiltinClassLoader::$assertionsDisabled && !($nc(loadedModule)->loader() == this)) {
			$throwNew($AssertionError);
		}
		return findClassInModuleOrNull(loadedModule, cn);
	}
	if (hasClassPath()) {
		return findClassOnClassPathOrNull(cn);
	}
	return nullptr;
}

$Class* BuiltinClassLoader::loadClass($String* cn, bool resolve) {
	$Class* c = loadClassOrNull(cn, resolve);
	if (c == nullptr) {
		$throwNew($ClassNotFoundException, cn);
	}
	return c;
}

$Class* BuiltinClassLoader::loadClassOrNull($String* cn, bool resolve) {
	$useLocalCurrentObjectStackCache();
	$synchronized(getClassLoadingLock(cn)) {
		$Class* c = findLoadedClass(cn);
		if (c == nullptr) {
			$var($BuiltinClassLoader$LoadedModule, loadedModule, findLoadedModule(cn));
			if (loadedModule != nullptr) {
				$var(BuiltinClassLoader, loader, loadedModule->loader());
				if (loader == this) {
					if ($VM::isModuleSystemInited()) {
						c = findClassInModuleOrNull(loadedModule, cn);
					}
				} else {
					c = loader->loadClassOrNull(cn);
				}
			} else {
				if (this->parent != nullptr) {
					c = $nc(this->parent)->loadClassOrNull(cn);
				}
				bool var$0 = c == nullptr && hasClassPath();
				if (var$0 && $VM::isModuleSystemInited()) {
					c = findClassOnClassPathOrNull(cn);
				}
			}
		}
		if (resolve && c != nullptr) {
			resolveClass(c);
		}
		return c;
	}
}

$Class* BuiltinClassLoader::loadClassOrNull($String* cn) {
	return loadClassOrNull(cn, false);
}

$BuiltinClassLoader$LoadedModule* BuiltinClassLoader::findLoadedModule($String* cn) {
	int32_t pos = $nc(cn)->lastIndexOf((int32_t)u'.');
	if (pos < 0) {
		return nullptr;
	}
	$var($String, pn, cn->substring(0, pos));
	return $cast($BuiltinClassLoader$LoadedModule, $nc(BuiltinClassLoader::packageToModule$)->get(pn));
}

$BuiltinClassLoader$LoadedModule* BuiltinClassLoader::findLoadedModule($String* mn, $String* cn) {
	$useLocalCurrentObjectStackCache();
	$var($BuiltinClassLoader$LoadedModule, loadedModule, findLoadedModule(cn));
	if (loadedModule != nullptr && $nc(mn)->equals($(loadedModule->name()))) {
		return loadedModule;
	} else {
		return nullptr;
	}
}

$Class* BuiltinClassLoader::findClassInModuleOrNull($BuiltinClassLoader$LoadedModule* loadedModule, $String* cn) {
	$var($ModuleReference, mref, $nc(loadedModule)->mref());
	$var($ModuleReader, reader, moduleReaderFor(mref));
	RuntimeModuleReader* runtimeModuleReader = $cast<RuntimeModuleReader>(reader);
	if (runtimeModuleReader != nullptr) {
		return Machine::findClass(this,  mref->descriptor()->name(), cn);
	}
	return defineClass(cn, loadedModule);
}

$Class* BuiltinClassLoader::findClassOnClassPathOrNull($String* cn) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* clazz = Machine::findClass(this, cn);
	if (clazz != nullptr) {
		return clazz;
	}
	$var($String, path, $($nc(cn)->replace(u'.', u'/'))->concat(".class"_s));
	if ($System::getSecurityManager() == nullptr) {
		$var($Resource, res, $nc(this->ucp)->getResource(path, false));
		if (res != nullptr) {
			try {
				return defineClass(cn, res);
			} catch ($IOException& ioe) {
			}
		}
		return nullptr;
	} else {
		$var($PrivilegedAction, pa, $new($BuiltinClassLoader$4, this, path, cn));
		return $cast($Class, $AccessController::doPrivileged(pa));
	}
}

$Class* BuiltinClassLoader::defineClass($String* cn, $BuiltinClassLoader$LoadedModule* loadedModule) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleReference, mref, $nc(loadedModule)->mref());
	$var($ModuleReader, reader, moduleReaderFor(mref));
	try {
		$var($ByteBuffer, bb, nullptr);
		$var($URL, csURL, nullptr);
		$var($String, rn, $($nc(cn)->replace(u'.', u'/'))->concat(".class"_s));
		if ($instanceOf($ModulePatcher$PatchedModuleReader, reader)) {
			$var($Resource, r, $nc(($cast($ModulePatcher$PatchedModuleReader, reader)))->findResource(rn));
			if (r != nullptr) {
				$assign(bb, r->getByteBuffer());
				$assign(csURL, r->getCodeSourceURL());
			}
		} else {
			$assign(bb, $cast($ByteBuffer, $nc($($nc(reader)->read(rn)))->orElse(nullptr)));
			$assign(csURL, loadedModule->codeSourceURL());
		}
		if (bb == nullptr) {
			return nullptr;
		}
		$var($CodeSource, cs, $new($CodeSource, csURL, ($CodeSignerArray*)nullptr));
		{
			$var($Throwable, var$0, nullptr);
			$var($Class, var$2, nullptr);
			bool return$1 = false;
			try {
				var$2 = defineClass(cn, bb, cs);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(reader)->release(bb);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& ioe) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Class* BuiltinClassLoader::defineClass($String* cn, $Resource* res) {
	$useLocalCurrentObjectStackCache();
	$var($URL, url, $nc(res)->getCodeSourceURL());
	int32_t pos = $nc(cn)->lastIndexOf((int32_t)u'.');
	if (pos != -1) {
		$var($String, pn, cn->substring(0, pos));
		$var($Manifest, man, res->getManifest());
		defineOrCheckPackage(pn, man, url);
	}
	$var($ByteBuffer, bb, res->getByteBuffer());
	if (bb != nullptr) {
		$var($CodeSignerArray, signers, res->getCodeSigners());
		$var($CodeSource, cs, $new($CodeSource, url, signers));
		return defineClass(cn, bb, cs);
	} else {
		$var($bytes, b, res->getBytes());
		$var($CodeSignerArray, signers, res->getCodeSigners());
		$var($CodeSource, cs, $new($CodeSource, url, signers));
		return defineClass(cn, b, 0, $nc(b)->length, cs);
	}
}

$Package* BuiltinClassLoader::defineOrCheckPackage($String* pn, $Manifest* man, $URL* url) {
	$useLocalCurrentObjectStackCache();
	$var($Package, pkg, getAndVerifyPackage(pn, man, url));
	if (pkg == nullptr) {
		try {
			if (man != nullptr) {
				$assign(pkg, definePackage(pn, man, url));
			} else {
				$assign(pkg, definePackage(pn, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr));
			}
		} catch ($IllegalArgumentException& iae) {
			$assign(pkg, getAndVerifyPackage(pn, man, url));
			if (pkg == nullptr) {
				$throwNew($InternalError, $$str({"Cannot find package: "_s, pn}));
			}
		}
	}
	return pkg;
}

$Package* BuiltinClassLoader::getAndVerifyPackage($String* pn, $Manifest* man, $URL* url) {
	$useLocalCurrentObjectStackCache();
	$var($Package, pkg, getDefinedPackage(pn));
	if (pkg != nullptr) {
		if (pkg->isSealed()) {
			if (!pkg->isSealed(url)) {
				$throwNew($SecurityException, $$str({"sealing violation: package "_s, pn, " is sealed"_s}));
			}
		} else if ((man != nullptr) && isSealed(pn, man)) {
			$throwNew($SecurityException, $$str({"sealing violation: can\'t seal package "_s, pn, ": already defined"_s}));
		}
	}
	return pkg;
}

$Package* BuiltinClassLoader::definePackage($String* pn, $Manifest* man, $URL* url) {
	$useLocalCurrentObjectStackCache();
	$var($String, specTitle, nullptr);
	$var($String, specVersion, nullptr);
	$var($String, specVendor, nullptr);
	$var($String, implTitle, nullptr);
	$var($String, implVersion, nullptr);
	$var($String, implVendor, nullptr);
	$var($String, sealed, nullptr);
	$var($URL, sealBase, nullptr);
	if (man != nullptr) {
		$var($Attributes, attr, $nc($($SharedSecrets::javaUtilJarAccess()))->getTrustedAttributes(man, $($($nc(pn)->replace(u'.', u'/'))->concat("/"_s))));
		if (attr != nullptr) {
			$init($Attributes$Name);
			$assign(specTitle, attr->getValue($Attributes$Name::SPECIFICATION_TITLE));
			$assign(specVersion, attr->getValue($Attributes$Name::SPECIFICATION_VERSION));
			$assign(specVendor, attr->getValue($Attributes$Name::SPECIFICATION_VENDOR));
			$assign(implTitle, attr->getValue($Attributes$Name::IMPLEMENTATION_TITLE));
			$assign(implVersion, attr->getValue($Attributes$Name::IMPLEMENTATION_VERSION));
			$assign(implVendor, attr->getValue($Attributes$Name::IMPLEMENTATION_VENDOR));
			$assign(sealed, attr->getValue($Attributes$Name::SEALED));
		}
		$assign(attr, man->getMainAttributes());
		if (attr != nullptr) {
			if (specTitle == nullptr) {
				$init($Attributes$Name);
				$assign(specTitle, attr->getValue($Attributes$Name::SPECIFICATION_TITLE));
			}
			if (specVersion == nullptr) {
				$init($Attributes$Name);
				$assign(specVersion, attr->getValue($Attributes$Name::SPECIFICATION_VERSION));
			}
			if (specVendor == nullptr) {
				$init($Attributes$Name);
				$assign(specVendor, attr->getValue($Attributes$Name::SPECIFICATION_VENDOR));
			}
			if (implTitle == nullptr) {
				$init($Attributes$Name);
				$assign(implTitle, attr->getValue($Attributes$Name::IMPLEMENTATION_TITLE));
			}
			if (implVersion == nullptr) {
				$init($Attributes$Name);
				$assign(implVersion, attr->getValue($Attributes$Name::IMPLEMENTATION_VERSION));
			}
			if (implVendor == nullptr) {
				$init($Attributes$Name);
				$assign(implVendor, attr->getValue($Attributes$Name::IMPLEMENTATION_VENDOR));
			}
			if (sealed == nullptr) {
				$init($Attributes$Name);
				$assign(sealed, attr->getValue($Attributes$Name::SEALED));
			}
		}
		if ("true"_s->equalsIgnoreCase(sealed)) {
			$assign(sealBase, url);
		}
	}
	return definePackage(pn, specTitle, specVersion, specVendor, implTitle, implVersion, implVendor, sealBase);
}

bool BuiltinClassLoader::isSealed($String* pn, $Manifest* man) {
	$useLocalCurrentObjectStackCache();
	$var($Attributes, attr, $nc($($SharedSecrets::javaUtilJarAccess()))->getTrustedAttributes(man, $($($nc(pn)->replace(u'.', u'/'))->concat("/"_s))));
	$var($String, sealed, nullptr);
	if (attr != nullptr) {
		$init($Attributes$Name);
		$assign(sealed, attr->getValue($Attributes$Name::SEALED));
	}
	if (sealed == nullptr && ($assign(attr, $nc(man)->getMainAttributes())) != nullptr) {
		$init($Attributes$Name);
		$assign(sealed, $nc(attr)->getValue($Attributes$Name::SEALED));
	}
	return "true"_s->equalsIgnoreCase(sealed);
}

$PermissionCollection* BuiltinClassLoader::getPermissions($CodeSource* cs) {
	return $new($LazyCodeSourcePermissionCollection, $($SecureClassLoader::getPermissions(cs)), cs);
}

$ModuleReader* BuiltinClassLoader::moduleReaderFor($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleReader, reader, $cast($ModuleReader, $nc(this->moduleToReader)->get(mref)));
	if (reader == nullptr) {
		$var($Function, create, $new($BuiltinClassLoader$5, this, mref));
		$assign(reader, $cast($ModuleReader, $nc(this->moduleToReader)->computeIfAbsent(mref, create)));
	}
	return reader;
}

bool BuiltinClassLoader::isOpen($ModuleReference* mref, $String* pn) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleDescriptor, descriptor, $nc(mref)->descriptor());
	bool var$0 = $nc(descriptor)->isOpen();
	if (var$0 || $nc(descriptor)->isAutomatic()) {
		return true;
	}
	{
		$var($Iterator, i$, $nc($($nc(descriptor)->opens()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleDescriptor$Opens, opens, $cast($ModuleDescriptor$Opens, i$->next()));
			{
				$var($String, source, $nc(opens)->source());
				bool var$1 = !opens->isQualified();
				if (var$1 && $nc(source)->equals(pn)) {
					return true;
				}
			}
		}
	}
	return false;
}

$URL* BuiltinClassLoader::checkURL($URL* url) {
	$init(BuiltinClassLoader);
	return $URLClassPath::checkURL(url);
}

void BuiltinClassLoader::resetArchivedStates() {
	$set(this, ucp, nullptr);
}

$Class* BuiltinClassLoader::lambda$findClassInModuleOrNull$2($String* cn, $BuiltinClassLoader$LoadedModule* loadedModule) {
	return defineClass(cn, loadedModule);
}

$Enumeration* BuiltinClassLoader::lambda$findResourcesOnClassPath$1($String* name) {
	return $nc(this->ucp)->findResources(name, false);
}

$URL* BuiltinClassLoader::lambda$findResourceOnClassPath$0($String* name) {
	return $nc(this->ucp)->findResource(name, false);
}

void clinit$BuiltinClassLoader($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	BuiltinClassLoader::$assertionsDisabled = !BuiltinClassLoader::class$->desiredAssertionStatus();
	{
		if (!$ClassLoader::registerAsParallelCapable()) {
			$throwNew($InternalError, "Unable to register as parallel capable"_s);
		}
	}
	{
		$var($ArchivedClassLoaders, archivedClassLoaders, $ArchivedClassLoaders::get());
		if (archivedClassLoaders != nullptr) {
			$var($Map, map, archivedClassLoaders->packageToModule());
			$assignStatic(BuiltinClassLoader::packageToModule$, map);
		} else {
			$assignStatic(BuiltinClassLoader::packageToModule$, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap, 1024))));
		}
	}
}

BuiltinClassLoader::BuiltinClassLoader() {
}

$Class* BuiltinClassLoader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::classInfo$.name)) {
			return BuiltinClassLoader$$Lambda$lambda$findResourceOnClassPath$0::load$(name, initialize);
		}
		if (name->equals(BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::classInfo$.name)) {
			return BuiltinClassLoader$$Lambda$lambda$findResourcesOnClassPath$1$1::load$(name, initialize);
		}
		if (name->equals(BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::classInfo$.name)) {
			return BuiltinClassLoader$$Lambda$lambda$findClassInModuleOrNull$2$2::load$(name, initialize);
		}
	}
	$loadClass(BuiltinClassLoader, name, initialize, &_BuiltinClassLoader_ClassInfo_, clinit$BuiltinClassLoader, allocate$BuiltinClassLoader);
	return class$;
}

$Class* BuiltinClassLoader::class$ = nullptr;

		} // loader
	} // internal
} // jdk