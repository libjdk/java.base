#include <java/lang/ClassLoader.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/AssertionStatusDirectives.h>
#include <java/lang/ClassLoader$1.h>
#include <java/lang/ClassLoader$ParallelLoaders.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/CompoundEnumeration.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/NamedPackage.h>
#include <java/lang/NoClassDefFoundError.h>
#include <java/lang/Package.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsatisfiedLinkError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/net/URL.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Principal.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/cert/Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSupport.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/loader/NativeLibraries.h>
#include <jdk/internal/loader/NativeLibrary.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/perf/PerfCounter.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#include <java/lang/Machine.h>

#undef GET_CLASSLOADER_PERMISSION
#undef IMMUTABLE
#undef NONNULL

using $PackageArray = $Array<::java::lang::Package>;
using $PrincipalArray = $Array<::java::security::Principal>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $EnumerationArray = $Array<::java::util::Enumeration>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $AssertionStatusDirectives = ::java::lang::AssertionStatusDirectives;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader$1 = ::java::lang::ClassLoader$1;
using $ClassLoader$ParallelLoaders = ::java::lang::ClassLoader$ParallelLoaders;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $CompoundEnumeration = ::java::lang::CompoundEnumeration;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NamedPackage = ::java::lang::NamedPackage;
using $NoClassDefFoundError = ::java::lang::NoClassDefFoundError;
using $NullPointerException = ::java::lang::NullPointerException;
using $Package = ::java::lang::Package;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsatisfiedLinkError = ::java::lang::UnsatisfiedLinkError;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $URL = ::java::net::URL;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Certificate = ::java::security::cert::Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::java::util::stream::Stream;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $NativeLibraries = ::jdk::internal::loader::NativeLibraries;
using $NativeLibrary = ::jdk::internal::loader::NativeLibrary;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $VM = ::jdk::internal::misc::VM;
using $PerfCounter = ::jdk::internal::perf::PerfCounter;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {

class ClassLoader$$Lambda$lambda$resources$0 : public $Supplier {
	$class(ClassLoader$$Lambda$lambda$resources$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$(ClassLoader* inst, $String* name, int32_t characteristics) {
		$set(this, inst$, inst);
		$set(this, name, name);
		this->characteristics = characteristics;
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resources$0(name, characteristics));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ClassLoader$$Lambda$lambda$resources$0>());
	}
	ClassLoader* inst$ = nullptr;
	$String* name = nullptr;
	int32_t characteristics = 0;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ClassLoader$$Lambda$lambda$resources$0::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ClassLoader$$Lambda$lambda$resources$0, inst$)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ClassLoader$$Lambda$lambda$resources$0, name)},
	{"characteristics", "I", nullptr, $PUBLIC, $field(ClassLoader$$Lambda$lambda$resources$0, characteristics)},
	{}
};
$MethodInfo ClassLoader$$Lambda$lambda$resources$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(ClassLoader$$Lambda$lambda$resources$0, init$, void, ClassLoader*, $String*, int32_t)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ClassLoader$$Lambda$lambda$resources$0, get, $Object*)},
	{}
};
$ClassInfo ClassLoader$$Lambda$lambda$resources$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ClassLoader$$Lambda$lambda$resources$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ClassLoader$$Lambda$lambda$resources$0::load$($String* name, bool initialize) {
	$loadClass(ClassLoader$$Lambda$lambda$resources$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ClassLoader$$Lambda$lambda$resources$0::class$ = nullptr;

class ClassLoader$$Lambda$lambda$definePackage$1$1 : public $BiFunction {
	$class(ClassLoader$$Lambda$lambda$definePackage$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(ClassLoader* inst, $Module* m) {
		$set(this, inst$, inst);
		$set(this, m, m);
	}
	virtual $Object* apply(Object$* n, Object$* p) override {
		 return $of($nc(inst$)->lambda$definePackage$1(m, $cast($String, n), $cast($NamedPackage, p)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ClassLoader$$Lambda$lambda$definePackage$1$1>());
	}
	ClassLoader* inst$ = nullptr;
	$Module* m = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ClassLoader$$Lambda$lambda$definePackage$1$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ClassLoader$$Lambda$lambda$definePackage$1$1, inst$)},
	{"m", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(ClassLoader$$Lambda$lambda$definePackage$1$1, m)},
	{}
};
$MethodInfo ClassLoader$$Lambda$lambda$definePackage$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(ClassLoader$$Lambda$lambda$definePackage$1$1, init$, void, ClassLoader*, $Module*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ClassLoader$$Lambda$lambda$definePackage$1$1, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo ClassLoader$$Lambda$lambda$definePackage$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ClassLoader$$Lambda$lambda$definePackage$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* ClassLoader$$Lambda$lambda$definePackage$1$1::load$($String* name, bool initialize) {
	$loadClass(ClassLoader$$Lambda$lambda$definePackage$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ClassLoader$$Lambda$lambda$definePackage$1$1::class$ = nullptr;

class ClassLoader$$Lambda$lambda$getDefinedPackages$2$2 : public $IntFunction {
	$class(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(ClassLoader::lambda$getDefinedPackages$2(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ClassLoader$$Lambda$lambda$getDefinedPackages$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ClassLoader$$Lambda$lambda$getDefinedPackages$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2, apply, $Object*, int32_t)},
	{}
};
$ClassInfo ClassLoader$$Lambda$lambda$getDefinedPackages$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ClassLoader$$Lambda$lambda$getDefinedPackages$2$2",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* ClassLoader$$Lambda$lambda$getDefinedPackages$2$2::load$($String* name, bool initialize) {
	$loadClass(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ClassLoader$$Lambda$lambda$getDefinedPackages$2$2::class$ = nullptr;

class ClassLoader$$Lambda$lambda$packages$4$3 : public $Function {
	$class(ClassLoader$$Lambda$lambda$packages$4$3, $NO_CLASS_INIT, $Function)
public:
	void init$(ClassLoader* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* p) override {
		 return $of($nc(inst$)->lambda$packages$4($cast($NamedPackage, p)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ClassLoader$$Lambda$lambda$packages$4$3>());
	}
	ClassLoader* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ClassLoader$$Lambda$lambda$packages$4$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ClassLoader$$Lambda$lambda$packages$4$3, inst$)},
	{}
};
$MethodInfo ClassLoader$$Lambda$lambda$packages$4$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $method(ClassLoader$$Lambda$lambda$packages$4$3, init$, void, ClassLoader*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ClassLoader$$Lambda$lambda$packages$4$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ClassLoader$$Lambda$lambda$packages$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ClassLoader$$Lambda$lambda$packages$4$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ClassLoader$$Lambda$lambda$packages$4$3::load$($String* name, bool initialize) {
	$loadClass(ClassLoader$$Lambda$lambda$packages$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ClassLoader$$Lambda$lambda$packages$4$3::class$ = nullptr;

$NamedAttribute ClassLoader_Attribute_var$0[] = {
	{"since", 's', "1.1"},
	{}
};

$CompoundAttribute _ClassLoader_MethodAnnotations_defineClass14[] = {
	{"Ljava/lang/Deprecated;", ClassLoader_Attribute_var$0},
	{}
};

$NamedAttribute ClassLoader_Attribute_var$1[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _ClassLoader_MethodAnnotations_getPackage46[] = {
	{"Ljava/lang/Deprecated;", ClassLoader_Attribute_var$1},
	{}
};

$CompoundAttribute _ClassLoader_MethodAnnotations_getParent48[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _ClassLoader_MethodAnnotations_getPlatformClassLoader49[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _ClassLoader_MethodAnnotations_getSystemClassLoader53[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _ClassLoader_MethodAnnotations_registerAsParallelCapable77[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _ClassLoader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ClassLoader, $assertionsDisabled)},
	{"parent", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(ClassLoader, parent)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassLoader, name$)},
	{"unnamedModule", "Ljava/lang/Module;", nullptr, $PRIVATE | $FINAL, $field(ClassLoader, unnamedModule)},
	{"nameAndId", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassLoader, nameAndId$)},
	{"parallelLockMap", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ClassLoader, parallelLockMap)},
	{"package2certs", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;[Ljava/security/cert/Certificate;>;", $PRIVATE | $FINAL, $field(ClassLoader, package2certs)},
	{"nocerts", "[Ljava/security/cert/Certificate;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassLoader, nocerts)},
	{"classes", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljava/lang/Class<*>;>;", $PRIVATE | $FINAL, $field(ClassLoader, classes)},
	{"defaultDomain", "Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $FINAL, $field(ClassLoader, defaultDomain)},
	{"packages", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/lang/NamedPackage;>;", $PRIVATE | $FINAL, $field(ClassLoader, packages$)},
	{"scl", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(ClassLoader, scl)},
	{"libraries", "Ljdk/internal/loader/NativeLibraries;", nullptr, $PRIVATE | $FINAL, $field(ClassLoader, libraries)},
	{"assertionLock", "Ljava/lang/Object;", nullptr, $FINAL, $field(ClassLoader, assertionLock)},
	{"defaultAssertionStatus", "Z", nullptr, $PRIVATE, $field(ClassLoader, defaultAssertionStatus)},
	{"packageAssertionStatus", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Boolean;>;", $PRIVATE, $field(ClassLoader, packageAssertionStatus)},
	{"classAssertionStatus", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Boolean;>;", 0, $field(ClassLoader, classAssertionStatus)},
	{"classLoaderValueMap", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<**>;", $PRIVATE | $VOLATILE, $field(ClassLoader, classLoaderValueMap)},
	{}
};

$MethodInfo _ClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Void;Ljava/lang/String;Ljava/lang/ClassLoader;)V", nullptr, $PRIVATE, $method(ClassLoader, init$, void, $Void*, $String*, ClassLoader*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/ClassLoader;)V", nullptr, $PROTECTED, $method(ClassLoader, init$, void, $String*, ClassLoader*)},
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, $PROTECTED, $method(ClassLoader, init$, void, ClassLoader*)},
	{"<init>", "()V", nullptr, $PROTECTED, $method(ClassLoader, init$, void)},
	{"addClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $virtualMethod(ClassLoader, addClass, void, $Class*)},
	{"checkCerts", "(Ljava/lang/String;Ljava/security/CodeSource;)V", nullptr, $PRIVATE, $method(ClassLoader, checkCerts, void, $String*, $CodeSource*)},
	{"checkClassLoaderPermission", "(Ljava/lang/ClassLoader;Ljava/lang/Class;)V", "(Ljava/lang/ClassLoader;Ljava/lang/Class<*>;)V", $STATIC, $staticMethod(ClassLoader, checkClassLoaderPermission, void, ClassLoader*, $Class*)},
	{"checkCreateClassLoader", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassLoader, checkCreateClassLoader, $Void*)},
	{"checkCreateClassLoader", "(Ljava/lang/String;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassLoader, checkCreateClassLoader, $Void*, $String*)},
	{"checkName", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassLoader, checkName, bool, $String*)},
	{"checkPackageAccess", "(Ljava/lang/Class;Ljava/security/ProtectionDomain;)V", "(Ljava/lang/Class<*>;Ljava/security/ProtectionDomain;)V", $PRIVATE, $method(ClassLoader, checkPackageAccess, void, $Class*, $ProtectionDomain*)},
	{"clearAssertionStatus", "()V", nullptr, $PUBLIC, $virtualMethod(ClassLoader, clearAssertionStatus, void)},
	{"compareCerts", "([Ljava/security/cert/Certificate;[Ljava/security/cert/Certificate;)Z", nullptr, $PRIVATE, $method(ClassLoader, compareCerts, bool, $CertificateArray*, $CertificateArray*)},
	{"createOrGetClassLoaderValueMap", "()Ljava/util/concurrent/ConcurrentHashMap;", "()Ljava/util/concurrent/ConcurrentHashMap<**>;", 0, $virtualMethod(ClassLoader, createOrGetClassLoaderValueMap, $ConcurrentHashMap*)},
	{"defineClass", "([BII)Ljava/lang/Class;", "([BII)Ljava/lang/Class<*>;", $PROTECTED | $FINAL | $DEPRECATED, $method(ClassLoader, defineClass, $Class*, $bytes*, int32_t, int32_t), "java.lang.ClassFormatError", nullptr, _ClassLoader_MethodAnnotations_defineClass14},
	{"defineClass", "(Ljava/lang/String;[BII)Ljava/lang/Class;", "(Ljava/lang/String;[BII)Ljava/lang/Class<*>;", $PROTECTED | $FINAL, $method(ClassLoader, defineClass, $Class*, $String*, $bytes*, int32_t, int32_t), "java.lang.ClassFormatError"},
	{"defineClass", "(Ljava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class;", "(Ljava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class<*>;", $PROTECTED | $FINAL, $method(ClassLoader, defineClass, $Class*, $String*, $bytes*, int32_t, int32_t, $ProtectionDomain*), "java.lang.ClassFormatError"},
	{"defineClass", "(Ljava/lang/String;Ljava/nio/ByteBuffer;Ljava/security/ProtectionDomain;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/nio/ByteBuffer;Ljava/security/ProtectionDomain;)Ljava/lang/Class<*>;", $PROTECTED | $FINAL, $method(ClassLoader, defineClass, $Class*, $String*, $ByteBuffer*, $ProtectionDomain*), "java.lang.ClassFormatError"},
	{"defineClass0", "(Ljava/lang/ClassLoader;Ljava/lang/Class;Ljava/lang/String;[BIILjava/security/ProtectionDomain;ZILjava/lang/Object;)Ljava/lang/Class;", "(Ljava/lang/ClassLoader;Ljava/lang/Class<*>;Ljava/lang/String;[BIILjava/security/ProtectionDomain;ZILjava/lang/Object;)Ljava/lang/Class<*>;", $STATIC | $NATIVE, $staticMethod(ClassLoader, defineClass0, $Class*, ClassLoader*, $Class*, $String*, $bytes*, int32_t, int32_t, $ProtectionDomain*, bool, int32_t, Object$*)},
	{"defineClass1", "(Ljava/lang/ClassLoader;Ljava/lang/String;[BIILjava/security/ProtectionDomain;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/ClassLoader;Ljava/lang/String;[BIILjava/security/ProtectionDomain;Ljava/lang/String;)Ljava/lang/Class<*>;", $STATIC | $NATIVE, $staticMethod(ClassLoader, defineClass1, $Class*, ClassLoader*, $String*, $bytes*, int32_t, int32_t, $ProtectionDomain*, $String*)},
	{"defineClass2", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/nio/ByteBuffer;IILjava/security/ProtectionDomain;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/nio/ByteBuffer;IILjava/security/ProtectionDomain;Ljava/lang/String;)Ljava/lang/Class<*>;", $STATIC | $NATIVE, $staticMethod(ClassLoader, defineClass2, $Class*, ClassLoader*, $String*, $ByteBuffer*, int32_t, int32_t, $ProtectionDomain*, $String*)},
	{"defineClassSourceLocation", "(Ljava/security/ProtectionDomain;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ClassLoader, defineClassSourceLocation, $String*, $ProtectionDomain*)},
	{"definePackage", "(Ljava/lang/Class;)Ljava/lang/Package;", "(Ljava/lang/Class<*>;)Ljava/lang/Package;", 0, $virtualMethod(ClassLoader, definePackage, $Package*, $Class*)},
	{"definePackage", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/Package;", nullptr, 0, $virtualMethod(ClassLoader, definePackage, $Package*, $String*, $Module*)},
	{"definePackage", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PROTECTED, $virtualMethod(ClassLoader, definePackage, $Package*, $String*, $String*, $String*, $String*, $String*, $String*, $String*, $URL*)},
	{"desiredAssertionStatus", "(Ljava/lang/String;)Z", nullptr, 0, $virtualMethod(ClassLoader, desiredAssertionStatus, bool, $String*)},
	{"findBootstrapClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $NATIVE, $staticMethod(ClassLoader, findBootstrapClass, $Class*, $String*)},
	{"findBootstrapClassOrNull", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $STATIC, $staticMethod(ClassLoader, findBootstrapClassOrNull, $Class*, $String*)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(ClassLoader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"findClass", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(ClassLoader, findClass, $Class*, $String*, $String*)},
	{"findLibrary", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(ClassLoader, findLibrary, $String*, $String*)},
	{"findLoadedClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED | $FINAL, $method(ClassLoader, findLoadedClass, $Class*, $String*)},
	{"findLoadedClass0", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE | $FINAL | $NATIVE, $method(ClassLoader, findLoadedClass0, $Class*, $String*)},
	{"findNative", "(Ljava/lang/ClassLoader;Ljava/lang/String;)J", nullptr, $STATIC, $staticMethod(ClassLoader, findNative, int64_t, ClassLoader*, $String*)},
	{"findResource", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/URL;", nullptr, $PROTECTED, $virtualMethod(ClassLoader, findResource, $URL*, $String*, $String*), "java.io.IOException"},
	{"findResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PROTECTED, $virtualMethod(ClassLoader, findResource, $URL*, $String*)},
	{"findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PROTECTED, $virtualMethod(ClassLoader, findResources, $Enumeration*, $String*), "java.io.IOException"},
	{"findSystemClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED | $FINAL, $method(ClassLoader, findSystemClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"getBuiltinAppClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $STATIC, $staticMethod(ClassLoader, getBuiltinAppClassLoader, ClassLoader*)},
	{"getBuiltinPlatformClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $STATIC, $staticMethod(ClassLoader, getBuiltinPlatformClassLoader, ClassLoader*)},
	{"getClassLoader", "(Ljava/lang/Class;)Ljava/lang/ClassLoader;", "(Ljava/lang/Class<*>;)Ljava/lang/ClassLoader;", $STATIC, $staticMethod(ClassLoader, getClassLoader, ClassLoader*, $Class*)},
	{"getClassLoadingLock", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(ClassLoader, getClassLoadingLock, $Object*, $String*)},
	{"getDefinedPackage", "(Ljava/lang/String;)Ljava/lang/Package;", nullptr, $PUBLIC | $FINAL, $method(ClassLoader, getDefinedPackage, $Package*, $String*)},
	{"getDefinedPackages", "()[Ljava/lang/Package;", nullptr, $PUBLIC | $FINAL, $method(ClassLoader, getDefinedPackages, $PackageArray*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ClassLoader, getName, $String*)},
	{"getNamedPackage", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/NamedPackage;", nullptr, $PRIVATE, $method(ClassLoader, getNamedPackage, $NamedPackage*, $String*, $Module*)},
	{"getPackage", "(Ljava/lang/String;)Ljava/lang/Package;", nullptr, $PROTECTED | $DEPRECATED, $virtualMethod(ClassLoader, getPackage, $Package*, $String*), nullptr, nullptr, _ClassLoader_MethodAnnotations_getPackage46},
	{"getPackages", "()[Ljava/lang/Package;", nullptr, $PROTECTED, $virtualMethod(ClassLoader, getPackages, $PackageArray*)},
	{"getParent", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $FINAL, $method(ClassLoader, getParent, ClassLoader*), nullptr, nullptr, _ClassLoader_MethodAnnotations_getParent48},
	{"getPlatformClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassLoader, getPlatformClassLoader, ClassLoader*), nullptr, nullptr, _ClassLoader_MethodAnnotations_getPlatformClassLoader49},
	{"getResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(ClassLoader, getResource, $URL*, $String*)},
	{"getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(ClassLoader, getResourceAsStream, $InputStream*, $String*)},
	{"getResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(ClassLoader, getResources, $Enumeration*, $String*), "java.io.IOException"},
	{"getSystemClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassLoader, getSystemClassLoader, ClassLoader*), nullptr, nullptr, _ClassLoader_MethodAnnotations_getSystemClassLoader53},
	{"getSystemResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassLoader, getSystemResource, $URL*, $String*)},
	{"getSystemResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassLoader, getSystemResourceAsStream, $InputStream*, $String*)},
	{"getSystemResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC | $STATIC, $staticMethod(ClassLoader, getSystemResources, $Enumeration*, $String*), "java.io.IOException"},
	{"getUnnamedModule", "()Ljava/lang/Module;", nullptr, $PUBLIC | $FINAL, $method(ClassLoader, getUnnamedModule, $Module*)},
	{"initSystemClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $STATIC | $SYNCHRONIZED, $staticMethod(ClassLoader, initSystemClassLoader, ClassLoader*)},
	{"initializeJavaAssertionMaps", "()V", nullptr, $PRIVATE, $method(ClassLoader, initializeJavaAssertionMaps, void)},
	{"isAncestor", "(Ljava/lang/ClassLoader;)Z", nullptr, 0, $virtualMethod(ClassLoader, isAncestor, bool, ClassLoader*)},
	{"isRegisteredAsParallelCapable", "()Z", nullptr, $PUBLIC | $FINAL, $method(ClassLoader, isRegisteredAsParallelCapable, bool)},
	{"lambda$definePackage$1", "(Ljava/lang/Module;Ljava/lang/String;Ljava/lang/NamedPackage;)Ljava/lang/NamedPackage;", nullptr, $PRIVATE | $SYNTHETIC, $method(ClassLoader, lambda$definePackage$1, $NamedPackage*, $Module*, $String*, $NamedPackage*)},
	{"lambda$getDefinedPackages$2", "(I)[Ljava/lang/Package;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ClassLoader, lambda$getDefinedPackages$2, $PackageArray*, int32_t)},
	{"lambda$packages$4", "(Ljava/lang/NamedPackage;)Ljava/lang/Package;", nullptr, $PRIVATE | $SYNTHETIC, $method(ClassLoader, lambda$packages$4, $Package*, $NamedPackage*)},
	{"lambda$resources$0", "(Ljava/lang/String;I)Ljava/util/Spliterator;", nullptr, $PRIVATE | $SYNTHETIC, $method(ClassLoader, lambda$resources$0, $Spliterator*, $String*, int32_t)},
	{"loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(ClassLoader, loadClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(ClassLoader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class<*>;", $FINAL, $method(ClassLoader, loadClass, $Class*, $Module*, $String*)},
	{"loadLibrary", "(Ljava/lang/Class;Ljava/io/File;)Ljdk/internal/loader/NativeLibrary;", "(Ljava/lang/Class<*>;Ljava/io/File;)Ljdk/internal/loader/NativeLibrary;", $STATIC, $staticMethod(ClassLoader, loadLibrary, $NativeLibrary*, $Class*, $File*)},
	{"loadLibrary", "(Ljava/lang/Class;Ljava/lang/String;)Ljdk/internal/loader/NativeLibrary;", "(Ljava/lang/Class<*>;Ljava/lang/String;)Ljdk/internal/loader/NativeLibrary;", $STATIC, $staticMethod(ClassLoader, loadLibrary, $NativeLibrary*, $Class*, $String*)},
	{"name", "()Ljava/lang/String;", nullptr, $FINAL, $method(ClassLoader, name, $String*)},
	{"nameAndId", "(Ljava/lang/ClassLoader;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassLoader, nameAndId, $String*, ClassLoader*)},
	{"needsClassLoaderPermissionCheck", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassLoader, needsClassLoaderPermissionCheck, bool, ClassLoader*, ClassLoader*)},
	{"packages", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Package;>;", 0, $virtualMethod(ClassLoader, packages, $Stream*)},
	{"postDefineClass", "(Ljava/lang/Class;Ljava/security/ProtectionDomain;)V", "(Ljava/lang/Class<*>;Ljava/security/ProtectionDomain;)V", $PRIVATE, $method(ClassLoader, postDefineClass, void, $Class*, $ProtectionDomain*)},
	{"preDefineClass", "(Ljava/lang/String;Ljava/security/ProtectionDomain;)Ljava/security/ProtectionDomain;", nullptr, $PRIVATE, $method(ClassLoader, preDefineClass, $ProtectionDomain*, $String*, $ProtectionDomain*)},
	{"registerAsParallelCapable", "()Z", nullptr, $PROTECTED | $STATIC, $staticMethod(ClassLoader, registerAsParallelCapable, bool), nullptr, nullptr, _ClassLoader_MethodAnnotations_registerAsParallelCapable77},
	{"registerNatives", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ClassLoader, registerNatives, void)},
	{"resetArchivedStates", "()V", nullptr, $PRIVATE, $method(ClassLoader, resetArchivedStates, void)},
	{"resolveClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PROTECTED | $FINAL, $method(ClassLoader, resolveClass, void, $Class*)},
	{"resources", "(Ljava/lang/String;)Ljava/util/stream/Stream;", "(Ljava/lang/String;)Ljava/util/stream/Stream<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(ClassLoader, resources, $Stream*, $String*)},
	{"retrieveDirectives", "()Ljava/lang/AssertionStatusDirectives;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ClassLoader, retrieveDirectives, $AssertionStatusDirectives*)},
	{"setClassAssertionStatus", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(ClassLoader, setClassAssertionStatus, void, $String*, bool)},
	{"setDefaultAssertionStatus", "(Z)V", nullptr, $PUBLIC, $virtualMethod(ClassLoader, setDefaultAssertionStatus, void, bool)},
	{"setPackageAssertionStatus", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(ClassLoader, setPackageAssertionStatus, void, $String*, bool)},
	{"setSigners", "(Ljava/lang/Class;[Ljava/lang/Object;)V", "(Ljava/lang/Class<*>;[Ljava/lang/Object;)V", $PROTECTED | $FINAL, $method(ClassLoader, setSigners, void, $Class*, $ObjectArray*)},
	{"toPackage", "(Ljava/lang/String;Ljava/lang/NamedPackage;Ljava/lang/Module;)Ljava/lang/Package;", nullptr, $PRIVATE, $method(ClassLoader, toPackage, $Package*, $String*, $NamedPackage*, $Module*)},
	{"trySetObjectField", "(Ljava/lang/String;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(ClassLoader, trySetObjectField, bool, $String*, Object$*)},
	{}
};

#define _METHOD_INDEX_defineClass0 18
#define _METHOD_INDEX_defineClass1 19
#define _METHOD_INDEX_defineClass2 20
#define _METHOD_INDEX_findBootstrapClass 26
#define _METHOD_INDEX_findLoadedClass0 32
#define _METHOD_INDEX_registerNatives 78
#define _METHOD_INDEX_retrieveDirectives 82

$InnerClassInfo _ClassLoader_InnerClassesInfo_[] = {
	{"java.lang.ClassLoader$ParallelLoaders", "java.lang.ClassLoader", "ParallelLoaders", $PRIVATE | $STATIC},
	{"java.lang.ClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ClassLoader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.lang.ClassLoader",
	"java.lang.Object",
	nullptr,
	_ClassLoader_FieldInfo_,
	_ClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_ClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.ClassLoader$ParallelLoaders,java.lang.ClassLoader$1"
};

$Object* allocate$ClassLoader($Class* clazz) {
	return $of($alloc(ClassLoader));
}

bool ClassLoader::$assertionsDisabled = false;
$CertificateArray* ClassLoader::nocerts = nullptr;
$volatile(ClassLoader*) ClassLoader::scl = nullptr;

void ClassLoader::registerNatives() {
}

void ClassLoader::addClass($Class* c) {
	$synchronized(this->classes) {
		$nc(this->classes)->add(c);
	}
}

$NamedPackage* ClassLoader::getNamedPackage($String* pn, $Module* m) {
	$useLocalCurrentObjectStackCache();
	$var($NamedPackage, p, $cast($NamedPackage, $nc(this->packages$)->get(pn)));
	if (p == nullptr) {
		$assign(p, $new($NamedPackage, pn, m));
		$var($NamedPackage, value, $cast($NamedPackage, $nc(this->packages$)->putIfAbsent(pn, p)));
		if (value != nullptr) {
			$assign(p, value);
			if (!ClassLoader::$assertionsDisabled && !(value->module() == m)) {
				$throwNew($AssertionError);
			}
		}
	}
	return p;
}

$Void* ClassLoader::checkCreateClassLoader() {
	$init(ClassLoader);
	return checkCreateClassLoader(nullptr);
}

$Void* ClassLoader::checkCreateClassLoader($String* name) {
	$init(ClassLoader);
	if (name != nullptr && name->isEmpty()) {
		$throwNew($IllegalArgumentException, "name must be non-empty or null"_s);
	}
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkCreateClassLoader();
	}
	return nullptr;
}

void ClassLoader::init$($Void* unused, $String* name, ClassLoader* parent) {
	$set(this, classes, $new($ArrayList));
	$set(this, defaultDomain, $new($ProtectionDomain, $$new($CodeSource, ($URL*)nullptr, ($CertificateArray*)nullptr), nullptr, this, nullptr));
	$set(this, packages$, $new($ConcurrentHashMap));
	$set(this, libraries, $NativeLibraries::jniNativeLibraries(this));
	this->defaultAssertionStatus = false;
	$set(this, packageAssertionStatus, nullptr);
	$set(this, classAssertionStatus, nullptr);
	$set(this, name$, name);
	$set(this, parent, parent);
	$set(this, unnamedModule, $new($Module, this));
	if ($ClassLoader$ParallelLoaders::isRegistered($of(this)->getClass())) {
		$set(this, parallelLockMap, $new($ConcurrentHashMap));
		$set(this, assertionLock, $new($Object));
	} else {
		$set(this, parallelLockMap, nullptr);
		$set(this, assertionLock, this);
	}
	$set(this, package2certs, $new($ConcurrentHashMap));
	$set(this, nameAndId$, nameAndId(this));
}

$String* ClassLoader::nameAndId(ClassLoader* ld) {
	$init(ClassLoader);
	$useLocalCurrentObjectStackCache();
	$var($String, nid, $nc(ld)->getName() != nullptr ? $str({"\'"_s, $($nc(ld)->getName()), "\'"_s}) : $of(ld)->getClass()->getName());
	if (!($instanceOf($BuiltinClassLoader, ld))) {
		$var($String, id, $Integer::toHexString($System::identityHashCode(ld)));
		$assign(nid, $str({nid, " @"_s, id}));
	}
	return nid;
}

void ClassLoader::init$($String* name, ClassLoader* parent) {
	ClassLoader::init$($(checkCreateClassLoader(name)), name, parent);
}

void ClassLoader::init$(ClassLoader* parent) {
	ClassLoader::init$($(checkCreateClassLoader()), nullptr, parent);
}

void ClassLoader::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Void, var$0, checkCreateClassLoader());
	ClassLoader::init$(var$0, nullptr, $(getSystemClassLoader()));
}

$String* ClassLoader::getName() {
	return this->name$;
}

$String* ClassLoader::name() {
	return this->name$;
}

$Class* ClassLoader::loadClass($String* name) {
	return loadClass(name, false);
}

$Class* ClassLoader::loadClass($String* name, bool resolve) {
	$useLocalCurrentObjectStackCache();
	$synchronized(getClassLoadingLock(name)) {
		$Class* c = findLoadedClass(name);
		if (c == nullptr) {
			int64_t t0 = $System::nanoTime();
			try {
				if (this->parent != nullptr) {
					c = $nc(this->parent)->loadClass(name, false);
				} else {
					c = findBootstrapClassOrNull(name);
				}
			} catch ($ClassNotFoundException& e) {
			}
			if (c == nullptr) {
				int64_t t1 = $System::nanoTime();
				c = findClass(name);
				$nc($($PerfCounter::getParentDelegationTime()))->addTime(t1 - t0);
				$nc($($PerfCounter::getFindClassTime()))->addElapsedTimeFrom(t1);
				$nc($($PerfCounter::getFindClasses()))->increment();
			}
		}
		if (resolve) {
			resolveClass(c);
		}
		return c;
	}
}

$Class* ClassLoader::loadClass($Module* module, $String* name) {
	$synchronized(getClassLoadingLock(name)) {
		$Class* c = findLoadedClass(name);
		if (c == nullptr) {
			c = findClass($($nc(module)->getName()), name);
		}
		if (c != nullptr && c->getModule() == module) {
			return c;
		} else {
			return nullptr;
		}
	}
}

$Object* ClassLoader::getClassLoadingLock($String* className) {
	$useLocalCurrentObjectStackCache();
	$var($Object, lock, this);
	if (this->parallelLockMap != nullptr) {
		$var($Object, newLock, $new($Object));
		$assign(lock, $nc(this->parallelLockMap)->putIfAbsent(className, newLock));
		if (lock == nullptr) {
			$assign(lock, newLock);
		}
	}
	return $of(lock);
}

void ClassLoader::checkPackageAccess($Class* cls, $ProtectionDomain* pd) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		if ($ReflectUtil::isNonPublicProxyClass(cls)) {
			{
				$var($ClassArray, arr$, $nc(cls)->getInterfaces());
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$Class* intf = arr$->get(i$);
					{
						checkPackageAccess(intf, pd);
					}
				}
			}
			return;
		}
		$var($String, packageName, $nc(cls)->getPackageName());
		if (!$nc(packageName)->isEmpty()) {
			$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new($ClassLoader$1, this, sm, packageName)));
			$AccessController::doPrivileged(var$0, $$new($AccessControlContext, $$new($ProtectionDomainArray, {pd})));
		}
	}
}

$Class* ClassLoader::findClass($String* name) {
	$throwNew($ClassNotFoundException, name);
	$shouldNotReachHere();
}

$Class* ClassLoader::findClass($String* moduleName, $String* name) {
	if (moduleName == nullptr) {
		try {
			return findClass(name);
		} catch ($ClassNotFoundException& ignore) {
		}
	}
	return nullptr;
}

$Class* ClassLoader::defineClass($bytes* b, int32_t off, int32_t len) {
	return defineClass(nullptr, b, off, len, nullptr);
}

$Class* ClassLoader::defineClass($String* name, $bytes* b, int32_t off, int32_t len) {
	return defineClass(name, b, off, len, nullptr);
}

$ProtectionDomain* ClassLoader::preDefineClass($String* name, $ProtectionDomain* pd$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomain, pd, pd$renamed);
	if (!checkName(name)) {
		$throwNew($NoClassDefFoundError, $$str({"IllegalName: "_s, name}));
	}
	bool var$0 = (name != nullptr) && name->startsWith("java."_s);
	if (var$0 && this != getBuiltinPlatformClassLoader()) {
		$throwNew($SecurityException, $$str({"Prohibited package name: "_s, $(name->substring(0, name->lastIndexOf((int32_t)u'.')))}));
	}
	if (pd == nullptr) {
		$assign(pd, this->defaultDomain);
	}
	if (name != nullptr) {
		checkCerts(name, $($nc(pd)->getCodeSource()));
	}
	return pd;
}

$String* ClassLoader::defineClassSourceLocation($ProtectionDomain* pd) {
	$useLocalCurrentObjectStackCache();
	$var($CodeSource, cs, $nc(pd)->getCodeSource());
	$var($String, source, nullptr);
	if (cs != nullptr && cs->getLocation() != nullptr) {
		$assign(source, $nc($(cs->getLocation()))->toString());
	}
	return source;
}

void ClassLoader::postDefineClass($Class* c, $ProtectionDomain* pd) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(c)->getPackageName());
	getNamedPackage(var$0, $(c->getModule()));
	if ($nc(pd)->getCodeSource() != nullptr) {
		$var($CertificateArray, certs, $nc($(pd->getCodeSource()))->getCertificates());
		if (certs != nullptr) {
			setSigners(c, certs);
		}
	}
}

$Class* ClassLoader::defineClass($String* name, $bytes* b, int32_t off, int32_t len, $ProtectionDomain* protectionDomain$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomain, protectionDomain, protectionDomain$renamed);
	$assign(protectionDomain, preDefineClass(name, protectionDomain));
	$var($String, source, defineClassSourceLocation(protectionDomain));
	$Class* c = defineClass1(this, name, b, off, len, protectionDomain, source);
	postDefineClass(c, protectionDomain);
	return c;
}

$Class* ClassLoader::defineClass($String* name, $ByteBuffer* b, $ProtectionDomain* protectionDomain$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomain, protectionDomain, protectionDomain$renamed);
	int32_t len = $nc(b)->remaining();
	if (!b->isDirect()) {
		if (b->hasArray()) {
			$var($String, var$0, name);
			$var($bytes, var$1, $cast($bytes, b->array()));
			int32_t var$2 = b->position();
			return defineClass(var$0, var$1, var$2 + b->arrayOffset(), len, protectionDomain);
		} else {
			$var($bytes, tb, $new($bytes, len));
			b->get(tb);
			return defineClass(name, tb, 0, len, protectionDomain);
		}
	}
	$assign(protectionDomain, preDefineClass(name, protectionDomain));
	$var($String, source, defineClassSourceLocation(protectionDomain));
	$Class* c = defineClass2(this, name, b, b->position(), len, protectionDomain, source);
	postDefineClass(c, protectionDomain);
	return c;
}

$Class* ClassLoader::defineClass1(ClassLoader* loader, $String* name, $bytes* b, int32_t off, int32_t len, $ProtectionDomain* pd, $String* source) {
	return Machine::defineClass1(loader, name, b, off, len, pd, source);
}

$Class* ClassLoader::defineClass2(ClassLoader* loader, $String* name, $ByteBuffer* b, int32_t off, int32_t len, $ProtectionDomain* pd, $String* source) {
	return Machine::defineClass2(loader, name, b, off, len, pd, source);
}

$Class* ClassLoader::defineClass0(ClassLoader* loader, $Class* lookup, $String* name, $bytes* b, int32_t off, int32_t len, $ProtectionDomain* pd, bool initialize, int32_t flags, Object$* classData) {
	return Machine::defineClass0(loader, lookup, name, b, off, len, pd, initialize, flags, classData);
}

bool ClassLoader::checkName($String* name) {
	$init(ClassLoader);
	if ((name == nullptr) || ($nc(name)->isEmpty())) {
		return true;
	}
	bool var$0 = ($nc(name)->indexOf((int32_t)u'/') != -1);
	if (var$0 || ($nc(name)->charAt(0) == u'[')) {
		return false;
	}
	return true;
}

void ClassLoader::checkCerts($String* name, $CodeSource* cs) {
	$useLocalCurrentObjectStackCache();
	int32_t i = $nc(name)->lastIndexOf((int32_t)u'.');
	$var($String, pname, (i == -1) ? ""_s : name->substring(0, i));
	$var($CertificateArray, certs, nullptr);
	if (cs != nullptr) {
		$assign(certs, cs->getCertificates());
	}
	$assign(certs, certs == nullptr ? ClassLoader::nocerts : certs);
	$var($CertificateArray, pcerts, $cast($CertificateArray, $nc(this->package2certs)->putIfAbsent(pname, certs)));
	if (pcerts != nullptr && !compareCerts(pcerts, certs)) {
		$throwNew($SecurityException, $$str({"class \""_s, name, "\"\'s signer information does not match signer information of other classes in the same package"_s}));
	}
}

bool ClassLoader::compareCerts($CertificateArray* pcerts, $CertificateArray* certs) {
	$useLocalCurrentObjectStackCache();
	if ($nc(certs)->length == 0) {
		return $nc(pcerts)->length == 0;
	}
	if ($nc(certs)->length != $nc(pcerts)->length) {
		return false;
	}
	bool match = false;
	{
		$var($CertificateArray, arr$, certs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Certificate, cert, arr$->get(i$));
			{
				match = false;
				{
					$var($CertificateArray, arr$, pcerts);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Certificate, pcert, arr$->get(i$));
						{
							if ($nc(cert)->equals(pcert)) {
								match = true;
								break;
							}
						}
					}
				}
				if (!match) {
					return false;
				}
			}
		}
	}
	{
		$var($CertificateArray, arr$, pcerts);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Certificate, pcert, arr$->get(i$));
			{
				match = false;
				{
					$var($CertificateArray, arr$, certs);
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Certificate, cert, arr$->get(i$));
						{
							if ($nc(pcert)->equals(cert)) {
								match = true;
								break;
							}
						}
					}
				}
				if (!match) {
					return false;
				}
			}
		}
	}
	return true;
}

void ClassLoader::resolveClass($Class* c) {
	if (c == nullptr) {
		$throwNew($NullPointerException);
	}
}

$Class* ClassLoader::findSystemClass($String* name) {
	$beforeCallerSensitive();
	return $nc($(getSystemClassLoader()))->loadClass(name);
}

$Class* ClassLoader::findBootstrapClassOrNull($String* name) {
	$init(ClassLoader);
	if (!checkName(name)) {
		return nullptr;
	}
	return findBootstrapClass(name);
}

$Class* ClassLoader::findBootstrapClass($String* name) {
	return Machine::findBootstrapClass(nullptr, name);
}

$Class* ClassLoader::findLoadedClass($String* name) {
	if (!checkName(name)) {
		return nullptr;
	}
	return findLoadedClass0(name);
}

$Class* ClassLoader::findLoadedClass0($String* name) {
	return Machine::findLoadedClass0(this, name);
}

void ClassLoader::setSigners($Class* c, $ObjectArray* signers) {
	$nc(c)->setSigners(signers);
}

$URL* ClassLoader::findResource($String* moduleName, $String* name) {
	if (moduleName == nullptr) {
		return findResource(name);
	} else {
		return nullptr;
	}
}

$URL* ClassLoader::getResource($String* name) {
	$Objects::requireNonNull(name);
	$var($URL, url, nullptr);
	if (this->parent != nullptr) {
		$assign(url, $nc(this->parent)->getResource(name));
	} else {
		$assign(url, $BootLoader::findResource(name));
	}
	if (url == nullptr) {
		$assign(url, findResource(name));
	}
	return url;
}

$Enumeration* ClassLoader::getResources($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($EnumerationArray, tmp, $new($EnumerationArray, 2));
	if (this->parent != nullptr) {
		tmp->set(0, $($nc(this->parent)->getResources(name)));
	} else {
		tmp->set(0, $($BootLoader::findResources(name)));
	}
	tmp->set(1, $(findResources(name)));
	return $new($CompoundEnumeration, tmp);
}

$Stream* ClassLoader::resources($String* name) {
	$Objects::requireNonNull(name);
	int32_t characteristics = $Spliterator::NONNULL | $Spliterator::IMMUTABLE;
	$var($Supplier, si, static_cast<$Supplier*>($new(ClassLoader$$Lambda$lambda$resources$0, this, name, characteristics)));
	return $StreamSupport::stream(si, characteristics, false);
}

$URL* ClassLoader::findResource($String* name) {
	return nullptr;
}

$Enumeration* ClassLoader::findResources($String* name) {
	return $Collections::emptyEnumeration();
}

bool ClassLoader::registerAsParallelCapable() {
	$init(ClassLoader);
	$Class* callerClass = $nc($Reflection::getCallerClass())->asSubclass(ClassLoader::class$);
	return $ClassLoader$ParallelLoaders::register$(callerClass);
}

bool ClassLoader::isRegisteredAsParallelCapable() {
	return $ClassLoader$ParallelLoaders::isRegistered($of(this)->getClass());
}

$URL* ClassLoader::getSystemResource($String* name) {
	$init(ClassLoader);
	$beforeCallerSensitive();
	return $nc($(getSystemClassLoader()))->getResource(name);
}

$Enumeration* ClassLoader::getSystemResources($String* name) {
	$init(ClassLoader);
	$beforeCallerSensitive();
	return $nc($(getSystemClassLoader()))->getResources(name);
}

$InputStream* ClassLoader::getResourceAsStream($String* name) {
	$Objects::requireNonNull(name);
	$var($URL, url, getResource(name));
	try {
		return url != nullptr ? $nc(url)->openStream() : ($InputStream*)nullptr;
	} catch ($IOException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$InputStream* ClassLoader::getSystemResourceAsStream($String* name) {
	$init(ClassLoader);
	$var($URL, url, getSystemResource(name));
	try {
		return url != nullptr ? $nc(url)->openStream() : ($InputStream*)nullptr;
	} catch ($IOException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

ClassLoader* ClassLoader::getParent() {
	if (this->parent == nullptr) {
		return nullptr;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkClassLoaderPermission(this->parent, $Reflection::getCallerClass());
	}
	return this->parent;
}

$Module* ClassLoader::getUnnamedModule() {
	return this->unnamedModule;
}

ClassLoader* ClassLoader::getPlatformClassLoader() {
	$init(ClassLoader);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	$var(ClassLoader, loader, getBuiltinPlatformClassLoader());
	if (sm != nullptr) {
		checkClassLoaderPermission(loader, $Reflection::getCallerClass());
	}
	return loader;
}

ClassLoader* ClassLoader::getSystemClassLoader() {
	$init(ClassLoader);
	$useLocalCurrentObjectStackCache();
	{
		$var($String, msg, nullptr)
		$var($SecurityManager, sm, nullptr)
		switch ($VM::initLevel()) {
		case 0:
			{}
		case 1:
			{}
		case 2:
			{
				return getBuiltinAppClassLoader();
			}
		case 3:
			{
				$assign(msg, "getSystemClassLoader cannot be called during the system class loader instantiation"_s);
				$throwNew($IllegalStateException, msg);
			}
		default:
			{
				if (!ClassLoader::$assertionsDisabled && !($VM::isBooted() && ClassLoader::scl != nullptr)) {
					$throwNew($AssertionError);
				}
				$assign(sm, $System::getSecurityManager());
				if (sm != nullptr) {
					checkClassLoaderPermission(ClassLoader::scl, $Reflection::getCallerClass());
				}
				return ClassLoader::scl;
			}
		}
	}
}

ClassLoader* ClassLoader::getBuiltinPlatformClassLoader() {
	$init(ClassLoader);
	return $ClassLoaders::platformClassLoader();
}

ClassLoader* ClassLoader::getBuiltinAppClassLoader() {
	$init(ClassLoader);
	return $ClassLoaders::appClassLoader();
}

ClassLoader* ClassLoader::initSystemClassLoader() {
	$load(ClassLoader);
	$synchronized(class$) {
		$init(ClassLoader);
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		if ($VM::initLevel() != 3) {
			$throwNew($InternalError, $$str({"system class loader cannot be set at initLevel "_s, $$str($VM::initLevel())}));
		}
		if (ClassLoader::scl != nullptr) {
			$throwNew($IllegalStateException, "recursive invocation"_s);
		}
		$var(ClassLoader, builtinLoader, getBuiltinAppClassLoader());
		$var($String, cn, $System::getProperty("java.system.class.loader"_s));
		if (cn != nullptr) {
			try {
				$var($Constructor, ctor, $Class::forName(cn, false, builtinLoader)->getDeclaredConstructor($$new($ClassArray, {ClassLoader::class$})));
				$assignStatic(ClassLoader::scl, $cast(ClassLoader, $nc(ctor)->newInstance($$new($ObjectArray, {$of(builtinLoader)}))));
			} catch ($Exception& e) {
				$var($Throwable, cause, e);
				if ($instanceOf($InvocationTargetException, e)) {
					$assign(cause, e->getCause());
					if ($instanceOf($Error, cause)) {
						$throw($cast($Error, cause));
					}
				}
				if ($instanceOf($RuntimeException, cause)) {
					$throw($cast($RuntimeException, cause));
				}
				$throwNew($Error, $(cause->getMessage()), cause);
			}
		} else {
			$assignStatic(ClassLoader::scl, builtinLoader);
		}
		return ClassLoader::scl;
	}
}

bool ClassLoader::isAncestor(ClassLoader* cl) {
	$var(ClassLoader, acl, this);
	do {
		$assign(acl, acl->parent);
		if (cl == acl) {
			return true;
		}
	} while (acl != nullptr);
	return false;
}

bool ClassLoader::needsClassLoaderPermissionCheck(ClassLoader* from, ClassLoader* to) {
	$init(ClassLoader);
	if (from == to) {
		return false;
	}
	if (from == nullptr) {
		return false;
	}
	return !$nc(to)->isAncestor(from);
}

ClassLoader* ClassLoader::getClassLoader($Class* caller) {
	$init(ClassLoader);
	if (caller == nullptr) {
		return nullptr;
	}
	return $nc(caller)->getClassLoader0();
}

void ClassLoader::checkClassLoaderPermission(ClassLoader* cl, $Class* caller) {
	$init(ClassLoader);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var(ClassLoader, ccl, getClassLoader(caller));
		if (needsClassLoaderPermissionCheck(ccl, cl)) {
			$init($SecurityConstants);
			sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
		}
	}
}

$Package* ClassLoader::definePackage($Class* c) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(c)->isPrimitive();
	if (var$0 || $nc(c)->isArray()) {
		return nullptr;
	}
	$var($String, var$1, $nc(c)->getPackageName());
	return definePackage(var$1, $(c->getModule()));
}

$Package* ClassLoader::definePackage($String* name, $Module* m) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(name)->isEmpty();
	if (var$0 && $nc(m)->isNamed()) {
		$throwNew($InternalError, $$str({"unnamed package in  "_s, m}));
	}
	$var($NamedPackage, pkg, $cast($NamedPackage, $nc(this->packages$)->get(name)));
	if ($instanceOf($Package, pkg)) {
		return $cast($Package, pkg);
	}
	return $cast($Package, $nc(this->packages$)->compute(name, static_cast<$BiFunction*>($$new(ClassLoader$$Lambda$lambda$definePackage$1$1, this, m))));
}

$Package* ClassLoader::toPackage($String* name, $NamedPackage* p, $Module* m) {
	$useLocalCurrentObjectStackCache();
	if (p == nullptr) {
		return $NamedPackage::toPackage(name, m);
	}
	if ($instanceOf($Package, p)) {
		return $cast($Package, p);
	}
	$var($String, var$0, $nc(p)->packageName());
	return $NamedPackage::toPackage(var$0, $(p->module()));
}

$Package* ClassLoader::definePackage($String* name, $String* specTitle, $String* specVersion, $String* specVendor, $String* implTitle, $String* implVersion, $String* implVendor, $URL* sealBase) {
	$Objects::requireNonNull(name);
	$var($Package, p, $new($Package, name, specTitle, specVersion, specVendor, implTitle, implVersion, implVendor, sealBase, this));
	if ($nc(this->packages$)->putIfAbsent(name, p) != nullptr) {
		$throwNew($IllegalArgumentException, name);
	}
	return p;
}

$Package* ClassLoader::getDefinedPackage($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(name), "name cannot be null"_s);
	$var($NamedPackage, p, $cast($NamedPackage, $nc(this->packages$)->get(name)));
	if (p == nullptr) {
		return nullptr;
	}
	return definePackage(name, $($nc(p)->module()));
}

$PackageArray* ClassLoader::getDefinedPackages() {
	$useLocalCurrentObjectStackCache();
	return $fcast($PackageArray, $nc($(packages()))->toArray(static_cast<$IntFunction*>($$new(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2))));
}

$Package* ClassLoader::getPackage($String* name) {
	$var($Package, pkg, getDefinedPackage(name));
	if (pkg == nullptr) {
		if (this->parent != nullptr) {
			$assign(pkg, $nc(this->parent)->getPackage(name));
		} else {
			$assign(pkg, $BootLoader::getDefinedPackage(name));
		}
	}
	return pkg;
}

$PackageArray* ClassLoader::getPackages() {
	$useLocalCurrentObjectStackCache();
	$var($Stream, pkgs, packages());
	$var(ClassLoader, ld, this->parent);
	while (ld != nullptr) {
		$assign(pkgs, $Stream::concat($(ld->packages()), pkgs));
		$assign(ld, ld->parent);
	}
	return $fcast($PackageArray, $nc($($Stream::concat($($BootLoader::packages()), pkgs)))->toArray(static_cast<$IntFunction*>($$new(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2))));
}

$Stream* ClassLoader::packages() {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc(this->packages$)->values()))->stream()))->map(static_cast<$Function*>($$new(ClassLoader$$Lambda$lambda$packages$4$3, this)));
}

$String* ClassLoader::findLibrary($String* libname) {
	return nullptr;
}

$NativeLibrary* ClassLoader::loadLibrary($Class* fromClass, $File* file) {
	$init(ClassLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var(ClassLoader, loader, (fromClass == nullptr) ? (ClassLoader*)nullptr : $nc(fromClass)->getClassLoader());
	$var($NativeLibraries, libs, loader != nullptr ? $nc(loader)->libraries : $BootLoader::getNativeLibraries());
	$var($NativeLibrary, nl, $nc(libs)->loadLibrary(fromClass, file));
	if (nl != nullptr) {
		return nl;
	}
	$throwNew($UnsatisfiedLinkError, $$str({"Can\'t load library: "_s, file}));
}

$NativeLibrary* ClassLoader::loadLibrary($Class* fromClass, $String* name) {
	$init(ClassLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var(ClassLoader, loader, (fromClass == nullptr) ? (ClassLoader*)nullptr : $nc(fromClass)->getClassLoader());
	if (loader == nullptr) {
		$var($NativeLibrary, nl, $nc($($BootLoader::getNativeLibraries()))->loadLibrary(fromClass, name));
		if (nl != nullptr) {
			return nl;
		}
		$throwNew($UnsatisfiedLinkError, $$str({"no "_s, name, " in system library path: "_s, $($StaticProperty::sunBootLibraryPath())}));
	}
	$var($NativeLibraries, libs, $nc(loader)->libraries);
	$var($String, libfilename, loader->findLibrary(name));
	if (libfilename != nullptr) {
		$var($File, libfile, $new($File, libfilename));
		if (!libfile->isAbsolute()) {
			$throwNew($UnsatisfiedLinkError, $$str({"ClassLoader.findLibrary failed to return an absolute path: "_s, libfilename}));
		}
		$var($NativeLibrary, nl, $nc(libs)->loadLibrary(fromClass, libfile));
		if (nl != nullptr) {
			return nl;
		}
		$throwNew($UnsatisfiedLinkError, $$str({"Can\'t load "_s, libfilename}));
	}
	$var($NativeLibrary, nl, $nc(libs)->loadLibrary(fromClass, name));
	if (nl != nullptr) {
		return nl;
	}
	$throwNew($UnsatisfiedLinkError, $$str({"no "_s, name, " in java.library.path: "_s, $($StaticProperty::javaLibraryPath())}));
}

int64_t ClassLoader::findNative(ClassLoader* loader, $String* entryName) {
	$init(ClassLoader);
	if (loader == nullptr) {
		return $nc($($BootLoader::getNativeLibraries()))->find(entryName);
	} else {
		return $nc($nc(loader)->libraries)->find(entryName);
	}
}

void ClassLoader::setDefaultAssertionStatus(bool enabled) {
	$synchronized(this->assertionLock) {
		if (this->classAssertionStatus == nullptr) {
			initializeJavaAssertionMaps();
		}
		this->defaultAssertionStatus = enabled;
	}
}

void ClassLoader::setPackageAssertionStatus($String* packageName, bool enabled) {
	$synchronized(this->assertionLock) {
		if (this->packageAssertionStatus == nullptr) {
			initializeJavaAssertionMaps();
		}
		$nc(this->packageAssertionStatus)->put(packageName, $($Boolean::valueOf(enabled)));
	}
}

void ClassLoader::setClassAssertionStatus($String* className, bool enabled) {
	$synchronized(this->assertionLock) {
		if (this->classAssertionStatus == nullptr) {
			initializeJavaAssertionMaps();
		}
		$nc(this->classAssertionStatus)->put(className, $($Boolean::valueOf(enabled)));
	}
}

void ClassLoader::clearAssertionStatus() {
	$synchronized(this->assertionLock) {
		$set(this, classAssertionStatus, $new($HashMap));
		$set(this, packageAssertionStatus, $new($HashMap));
		this->defaultAssertionStatus = false;
	}
}

bool ClassLoader::desiredAssertionStatus($String* className$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, className, className$renamed);
	$synchronized(this->assertionLock) {
		$var($Boolean, result, $cast($Boolean, $nc(this->classAssertionStatus)->get(className)));
		if (result != nullptr) {
			return result->booleanValue();
		}
		int32_t dotIndex = $nc(className)->lastIndexOf((int32_t)u'.');
		if (dotIndex < 0) {
			$assign(result, $cast($Boolean, $nc(this->packageAssertionStatus)->get(nullptr)));
			if (result != nullptr) {
				return result->booleanValue();
			}
		}
		while (dotIndex > 0) {
			$assign(className, className->substring(0, dotIndex));
			$assign(result, $cast($Boolean, $nc(this->packageAssertionStatus)->get(className)));
			if (result != nullptr) {
				return result->booleanValue();
			}
			dotIndex = className->lastIndexOf((int32_t)u'.', dotIndex - 1);
		}
		return this->defaultAssertionStatus;
	}
}

void ClassLoader::initializeJavaAssertionMaps() {
	$useLocalCurrentObjectStackCache();
	$set(this, classAssertionStatus, $new($HashMap));
	$set(this, packageAssertionStatus, $new($HashMap));
	$var($AssertionStatusDirectives, directives, retrieveDirectives());
	for (int32_t i = 0; i < $nc($nc(directives)->classes)->length; ++i) {
		$nc(this->classAssertionStatus)->put($nc(directives->classes)->get(i), $($Boolean::valueOf($nc(directives->classEnabled)->get(i))));
	}
	for (int32_t i = 0; i < $nc($nc(directives)->packages)->length; ++i) {
		$nc(this->packageAssertionStatus)->put($nc(directives->packages)->get(i), $($Boolean::valueOf($nc(directives->packageEnabled)->get(i))));
	}
	this->defaultAssertionStatus = $nc(directives)->deflt;
}

$AssertionStatusDirectives* ClassLoader::retrieveDirectives() {
	return Machine::retrieveDirectives();
}

$ConcurrentHashMap* ClassLoader::createOrGetClassLoaderValueMap() {
	$var($ConcurrentHashMap, map, this->classLoaderValueMap);
	if (map == nullptr) {
		$assign(map, $new($ConcurrentHashMap));
		bool set = trySetObjectField("classLoaderValueMap"_s, map);
		if (!set) {
			$assign(map, this->classLoaderValueMap);
		}
	}
	return map;
}

bool ClassLoader::trySetObjectField($String* name, Object$* obj) {
	$var($Unsafe, unsafe, $Unsafe::getUnsafe());
	$Class* k = ClassLoader::class$;
	int64_t offset = 0;
	offset = $nc(unsafe)->objectFieldOffset(k, name);
	return unsafe->compareAndSetReference(this, offset, nullptr, obj);
}

void ClassLoader::resetArchivedStates() {
	$nc(this->parallelLockMap)->clear();
	$nc(this->packages$)->clear();
	$nc(this->package2certs)->clear();
	$nc(this->classes)->clear();
	$set(this, classLoaderValueMap, nullptr);
}

$Package* ClassLoader::lambda$packages$4($NamedPackage* p) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(p)->packageName());
	return definePackage(var$0, $(p->module()));
}

$PackageArray* ClassLoader::lambda$getDefinedPackages$2(int32_t x$0) {
	$init(ClassLoader);
	return $new($PackageArray, x$0);
}

$NamedPackage* ClassLoader::lambda$definePackage$1($Module* m, $String* n, $NamedPackage* p) {
	return toPackage(n, p, m);
}

$Spliterator* ClassLoader::lambda$resources$0($String* name, int32_t characteristics) {
	$useLocalCurrentObjectStackCache();
	try {
		return $Spliterators::spliteratorUnknownSize($($nc($(getResources(name)))->asIterator()), characteristics);
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

void clinit$ClassLoader($Class* class$) {
	ClassLoader::$assertionsDisabled = !ClassLoader::class$->desiredAssertionStatus();
	{
		ClassLoader::registerNatives();
	}
	$assignStatic(ClassLoader::nocerts, $new($CertificateArray, 0));
}

ClassLoader::ClassLoader() {
}

$Class* ClassLoader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ClassLoader$$Lambda$lambda$resources$0::classInfo$.name)) {
			return ClassLoader$$Lambda$lambda$resources$0::load$(name, initialize);
		}
		if (name->equals(ClassLoader$$Lambda$lambda$definePackage$1$1::classInfo$.name)) {
			return ClassLoader$$Lambda$lambda$definePackage$1$1::load$(name, initialize);
		}
		if (name->equals(ClassLoader$$Lambda$lambda$getDefinedPackages$2$2::classInfo$.name)) {
			return ClassLoader$$Lambda$lambda$getDefinedPackages$2$2::load$(name, initialize);
		}
		if (name->equals(ClassLoader$$Lambda$lambda$packages$4$3::classInfo$.name)) {
			return ClassLoader$$Lambda$lambda$packages$4$3::load$(name, initialize);
		}
	}
	$loadClass(ClassLoader, name, initialize, &_ClassLoader_ClassInfo_, clinit$ClassLoader, allocate$ClassLoader);
	return class$;
}

$Class* ClassLoader::class$ = nullptr;

	} // lang
} // java