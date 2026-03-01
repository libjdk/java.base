#include <java/lang/Class.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Class$1.h>
#include <java/lang/Class$2.h>
#include <java/lang/Class$3.h>
#include <java/lang/Class$AnnotationData.h>
#include <java/lang/Class$Atomic.h>
#include <java/lang/Class$EnclosingMethodInfo.h>
#include <java/lang/Class$ReflectionData.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassValue$ClassValueMap.h>
#include <java/lang/Enum.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/Package.h>
#include <java/lang/PublicMethods$MethodList.h>
#include <java/lang/PublicMethods.h>
#include <java/lang/Record.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/constant/ClassDesc.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/ref/SoftReference.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/GenericArrayType.h>
#include <java/lang/reflect/GenericDeclaration.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/lang/reflect/RecordComponent.h>
#include <java/lang/reflect/Type.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/AllPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/module/Resources.h>
#include <jdk/internal/reflect/ConstantPool.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/reflect/ReflectionFactory$GetReflectionFactoryAction.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <sun/invoke/util/Wrapper.h>
#include <sun/reflect/annotation/AnnotationParser.h>
#include <sun/reflect/annotation/AnnotationSupport.h>
#include <sun/reflect/annotation/AnnotationType.h>
#include <sun/reflect/annotation/TypeAnnotationParser.h>
#include <sun/reflect/generics/factory/CoreReflectionFactory.h>
#include <sun/reflect/generics/factory/GenericsFactory.h>
#include <sun/reflect/generics/repository/ClassRepository.h>
#include <sun/reflect/generics/repository/ConstructorRepository.h>
#include <sun/reflect/generics/repository/MethodRepository.h>
#include <sun/reflect/generics/scope/ClassScope.h>
#include <sun/reflect/generics/scope/Scope.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#include <java/lang/Machine.h>
#include <java/lang/ClassCastOffset.h>
#include <java/lang/Util.h>
#include "Platform.h"

#define $ALIGN_NUM $SIZEOF_VOID_P
#define $SIZEOF_VOID_P sizeof(void*)

int32_t calcAlignedSize$(int32_t size) {
	int32_t r = size % $ALIGN_NUM;
	if (r == 0) {
		return size;
	}
	return size + ($ALIGN_NUM - r);
}

int32_t calcClassSize$(int32_t size, int32_t delta) {
	int32_t minAlign = delta < $ALIGN_NUM ? delta : $ALIGN_NUM;
	int32_t r = size % minAlign;
	if (r == 0) {
		return size + delta;
	}
	return size + (minAlign - r) + delta;
}

int32_t calcFieldOffset$(int32_t size, int32_t delta) {
	int32_t minAlign = delta < $ALIGN_NUM ? delta : $ALIGN_NUM;
	int32_t r = size % minAlign;
	if (r == 0) {
		return size;
	}
	return size + (minAlign - r);
}

#undef ALL_PERMISSION
#undef ANNOTATION
#undef CHECK_MEMBER_ACCESS_PERMISSION
#undef DECLARED
#undef EMPTY_CLASS_ARRAY
#undef ENUM
#undef FINAL
#undef GET_CLASSLOADER_PERMISSION
#undef GET_PD_PERMISSION
#undef NONE
#undef NULL_SENTINEL
#undef PUBLIC
#undef SYNTHETIC
#undef TYPE

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $AnnotatedTypeArray = $Array<::java::lang::reflect::AnnotatedType>;
using $ConstructorArray = $Array<::java::lang::reflect::Constructor>;
using $FieldArray = $Array<::java::lang::reflect::Field>;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $RecordComponentArray = $Array<::java::lang::reflect::RecordComponent>;
using $TypeArray = $Array<::java::lang::reflect::Type>;
using $TypeVariableArray = $Array<::java::lang::reflect::TypeVariable>;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $Class$1 = ::java::lang::Class$1;
using $Class$2 = ::java::lang::Class$2;
using $Class$3 = ::java::lang::Class$3;
using $Class$AnnotationData = ::java::lang::Class$AnnotationData;
using $Class$Atomic = ::java::lang::Class$Atomic;
using $Class$EnclosingMethodInfo = ::java::lang::Class$EnclosingMethodInfo;
using $Class$ReflectionData = ::java::lang::Class$ReflectionData;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $Package = ::java::lang::Package;
using $PublicMethods = ::java::lang::PublicMethods;
using $PublicMethods$MethodList = ::java::lang::PublicMethods$MethodList;
using $Record = ::java::lang::Record;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $Annotation = ::java::lang::annotation::Annotation;
using $ClassDesc = ::java::lang::constant::ClassDesc;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $TypeDescriptor$OfField = ::java::lang::invoke::TypeDescriptor$OfField;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $SoftReference = ::java::lang::ref::SoftReference;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $1Array = ::java::lang::reflect::Array;
using $Constructor = ::java::lang::reflect::Constructor;
using $Executable = ::java::lang::reflect::Executable;
using $Field = ::java::lang::reflect::Field;
using $GenericArrayType = ::java::lang::reflect::GenericArrayType;
using $GenericDeclaration = ::java::lang::reflect::GenericDeclaration;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Member = ::java::lang::reflect::Member;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $Type = ::java::lang::reflect::Type;
using $TypeVariable = ::java::lang::reflect::TypeVariable;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $Resources = ::jdk::internal::module::Resources;
using $ConstantPool = ::jdk::internal::reflect::ConstantPool;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectionFactory = ::jdk::internal::reflect::ReflectionFactory;
using $ReflectionFactory$GetReflectionFactoryAction = ::jdk::internal::reflect::ReflectionFactory$GetReflectionFactoryAction;
using $Wrapper = ::sun::invoke::util::Wrapper;
using $AnnotationParser = ::sun::reflect::annotation::AnnotationParser;
using $AnnotationSupport = ::sun::reflect::annotation::AnnotationSupport;
using $AnnotationType = ::sun::reflect::annotation::AnnotationType;
using $TypeAnnotationParser = ::sun::reflect::annotation::TypeAnnotationParser;
using $CoreReflectionFactory = ::sun::reflect::generics::factory::CoreReflectionFactory;
using $GenericsFactory = ::sun::reflect::generics::factory::GenericsFactory;
using $ClassRepository = ::sun::reflect::generics::repository::ClassRepository;
using $ConstructorRepository = ::sun::reflect::generics::repository::ConstructorRepository;
using $MethodRepository = ::sun::reflect::generics::repository::MethodRepository;
using $ClassScope = ::sun::reflect::generics::scope::ClassScope;
using $Scope = ::sun::reflect::generics::scope::Scope;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {

class Class$$Lambda$typeVarBounds : public $Function {
	$class(Class$$Lambda$typeVarBounds, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* typeVar) override {
		 return $of(Class::typeVarBounds($cast($TypeVariable, typeVar)));
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$typeVarBounds>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Class$$Lambda$typeVarBounds::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Class$$Lambda$typeVarBounds, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$typeVarBounds, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Class$$Lambda$typeVarBounds::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$typeVarBounds",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
Class* Class$$Lambda$typeVarBounds::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$typeVarBounds, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$typeVarBounds::class$ = nullptr;

class Class$$Lambda$getTypeName$1 : public $Function {
	$class(Class$$Lambda$getTypeName$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Type, inst$)->getTypeName());
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$getTypeName$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Class$$Lambda$getTypeName$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Class$$Lambda$getTypeName$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$getTypeName$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Class$$Lambda$getTypeName$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$getTypeName$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
Class* Class$$Lambda$getTypeName$1::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$getTypeName$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$getTypeName$1::class$ = nullptr;

class Class$$Lambda$getClassLoader$2 : public $PrivilegedAction {
	$class(Class$$Lambda$getClassLoader$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Module* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->getClassLoader());
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$getClassLoader$2>());
	}
	$Module* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Class$$Lambda$getClassLoader$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Class$$Lambda$getClassLoader$2, inst$)},
	{}
};
$MethodInfo Class$$Lambda$getClassLoader$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(Class$$Lambda$getClassLoader$2, init$, void, $Module*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$getClassLoader$2, run, $Object*)},
	{}
};
$ClassInfo Class$$Lambda$getClassLoader$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$getClassLoader$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
Class* Class$$Lambda$getClassLoader$2::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$getClassLoader$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$getClassLoader$2::class$ = nullptr;

class Class$$Lambda$lambda$methodToString$0$3 : public $Function {
	$class(Class$$Lambda$lambda$methodToString$0$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* c) override {
		 return $of(Class::lambda$methodToString$0($cast(Class, c)));
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$lambda$methodToString$0$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Class$$Lambda$lambda$methodToString$0$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Class$$Lambda$lambda$methodToString$0$3, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$lambda$methodToString$0$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Class$$Lambda$lambda$methodToString$0$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$lambda$methodToString$0$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
Class* Class$$Lambda$lambda$methodToString$0$3::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$lambda$methodToString$0$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$lambda$methodToString$0$3::class$ = nullptr;

class Class$$Lambda$lambda$getPermittedSubclasses$1$4 : public $Predicate {
	$class(Class$$Lambda$lambda$getPermittedSubclasses$1$4, $NO_CLASS_INIT, $Predicate)
public:
	void init$(Class* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* c) override {
		 return $nc(inst$)->lambda$getPermittedSubclasses$1($cast(Class, c));
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$lambda$getPermittedSubclasses$1$4>());
	}
	Class* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Class$$Lambda$lambda$getPermittedSubclasses$1$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Class$$Lambda$lambda$getPermittedSubclasses$1$4, inst$)},
	{}
};
$MethodInfo Class$$Lambda$lambda$getPermittedSubclasses$1$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(Class$$Lambda$lambda$getPermittedSubclasses$1$4, init$, void, Class*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$lambda$getPermittedSubclasses$1$4, test, bool, Object$*)},
	{}
};
$ClassInfo Class$$Lambda$lambda$getPermittedSubclasses$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$lambda$getPermittedSubclasses$1$4",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
Class* Class$$Lambda$lambda$getPermittedSubclasses$1$4::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$lambda$getPermittedSubclasses$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$lambda$getPermittedSubclasses$1$4::class$ = nullptr;

class Class$$Lambda$isDirectSubType$5 : public $Predicate {
	$class(Class$$Lambda$isDirectSubType$5, $NO_CLASS_INIT, $Predicate)
public:
	void init$(Class* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* c) override {
		 return $nc(inst$)->isDirectSubType($cast(Class, c));
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$isDirectSubType$5>());
	}
	Class* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Class$$Lambda$isDirectSubType$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Class$$Lambda$isDirectSubType$5, inst$)},
	{}
};
$MethodInfo Class$$Lambda$isDirectSubType$5::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(Class$$Lambda$isDirectSubType$5, init$, void, Class*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$isDirectSubType$5, test, bool, Object$*)},
	{}
};
$ClassInfo Class$$Lambda$isDirectSubType$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$isDirectSubType$5",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
Class* Class$$Lambda$isDirectSubType$5::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$isDirectSubType$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$isDirectSubType$5::class$ = nullptr;

class Class$$Lambda$lambda$getPermittedSubclasses$2$6 : public $IntFunction {
	$class(Class$$Lambda$lambda$getPermittedSubclasses$2$6, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t s) override {
		 return $of(Class::lambda$getPermittedSubclasses$2(s));
	}
	static $Object* allocate$(Class* clazz) {
		return $of($alloc<Class$$Lambda$lambda$getPermittedSubclasses$2$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Class$$Lambda$lambda$getPermittedSubclasses$2$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Class$$Lambda$lambda$getPermittedSubclasses$2$6, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Class$$Lambda$lambda$getPermittedSubclasses$2$6, apply, $Object*, int32_t)},
	{}
};
$ClassInfo Class$$Lambda$lambda$getPermittedSubclasses$2$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.Class$$Lambda$lambda$getPermittedSubclasses$2$6",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
Class* Class$$Lambda$lambda$getPermittedSubclasses$2$6::load$($String* name, bool initialize) {
	$loadClass(Class$$Lambda$lambda$getPermittedSubclasses$2$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
Class* Class$$Lambda$lambda$getPermittedSubclasses$2$6::class$ = nullptr;

$CompoundAttribute _Class_MethodAnnotations_cast8[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_forName23[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_forName24[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_forName25[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getClassLoader36[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getClasses38[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getConstructor41[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getConstructors43[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredClasses48[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredConstructor50[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredConstructors51[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredField53[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredFields54[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredMethod56[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaredMethods57[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getDeclaringClass60[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getEnclosingClass62[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getEnclosingConstructor63[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getEnclosingMethod64[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getField71[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getFields73[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getMethod81[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getMethods83[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getModifiers85[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getNestHost88[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getNestMembers90[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getPermittedSubclasses94[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getRecordComponents101[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getResource104[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getResourceAsStream105[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_getSuperclass111[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_isArray119[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_isAssignableFrom120[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_isHidden123[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_isInstance124[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_isInterface125[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_isPrimitive131[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$NamedAttribute Class_Attribute_var$0[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _Class_MethodAnnotations_newInstance141[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{"Ljava/lang/Deprecated;", Class_Attribute_var$0},
	{}
};

$FieldInfo _Class_FieldInfo_[] = {
	{"ANNOTATION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Class, ANNOTATION)},
	{"ENUM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Class, ENUM)},
	{"SYNTHETIC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Class, SYNTHETIC)},
	{"cachedConstructor", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<TT;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, cachedConstructor)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(Class, name)},
	{"module", "Ljava/lang/Module;", nullptr, $PRIVATE | $TRANSIENT, $field(Class, module)},
	{"classLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(Class, classLoader)},
	{"classData", "Ljava/lang/Object;", nullptr, $PRIVATE | $TRANSIENT, $field(Class, classData)},
	{"packageName", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(Class, packageName)},
	{"componentType", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(Class, componentType$)},
	{"allPermDomain", "Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $STATIC, $staticField(Class, allPermDomain)},
	{"reflectionData", "Ljava/lang/ref/SoftReference;", "Ljava/lang/ref/SoftReference<Ljava/lang/Class$ReflectionData<TT;>;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, reflectionData$)},
	{"classRedefinedCount", "I", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, classRedefinedCount)},
	{"genericInfo", "Lsun/reflect/generics/repository/ClassRepository;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, genericInfo)},
	{"EMPTY_CLASS_ARRAY", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(Class, EMPTY_CLASS_ARRAY)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Class, serialVersionUID)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Class, serialPersistentFields)},
	{"reflectionFactory", "Ljdk/internal/reflect/ReflectionFactory;", nullptr, $PRIVATE | $STATIC, $staticField(Class, reflectionFactory)},
	{"enumConstants", "[Ljava/lang/Object;", "[TT;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, enumConstants)},
	{"enumConstantDirectory", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;TT;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, enumConstantDirectory$)},
	{"annotationData", "Ljava/lang/Class$AnnotationData;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, annotationData$)},
	{"annotationType", "Lsun/reflect/annotation/AnnotationType;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Class, annotationType)},
	{"classValueMap", "Ljava/lang/ClassValue$ClassValueMap;", nullptr, $TRANSIENT, $field(Class, classValueMap)},
	{"arrayType", "Ljava/lang/Class;", nullptr, 2, $field(Class, arrayType$)},
	{"simpleBinaryName", "Ljava/lang/String;", nullptr, 2, $field(Class, simpleBinaryName)},
	{"declaringClass", "Ljava/lang/Class;", nullptr, 2, $field(Class, declaringClass)},
	{"superClass", "Ljava/lang/Class;", nullptr, 2, $field(Class, superClass)},
	{"nestHost", "Ljava/lang/Class;", nullptr, 2, $field(Class, nestHost)},
	{}
};

$MethodInfo _Class_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/Class;)V", "(Ljava/lang/ClassLoader;Ljava/lang/Class<*>;)V", $PRIVATE, $method(Class, init$, void, $ClassLoader*, Class*)},
	{"addAll", "(Ljava/util/Collection;[Ljava/lang/reflect/Field;)V", "(Ljava/util/Collection<Ljava/lang/reflect/Field;>;[Ljava/lang/reflect/Field;)V", $PRIVATE | $STATIC, $staticMethod(Class, addAll, void, $Collection*, $FieldArray*)},
	{"annotationData", "()Ljava/lang/Class$AnnotationData;", nullptr, $PRIVATE, $method(Class, annotationData, $Class$AnnotationData*)},
	{"arrayContentsEq", "([Ljava/lang/Object;[Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Class, arrayContentsEq, bool, $ObjectArray*, $ObjectArray*)},
	{"arrayType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Class, arrayType, $TypeDescriptor$OfField*)},
	{"asSubclass", "(Ljava/lang/Class;)Ljava/lang/Class;", "<U:Ljava/lang/Object;>(Ljava/lang/Class<TU;>;)Ljava/lang/Class<+TU;>;", $PUBLIC, $method(Class, asSubclass, Class*, Class*)},
	{"cannotCastMsg", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Class, cannotCastMsg, $String*, Object$*)},
	{"casAnnotationType", "(Lsun/reflect/annotation/AnnotationType;Lsun/reflect/annotation/AnnotationType;)Z", nullptr, 0, $method(Class, casAnnotationType, bool, $AnnotationType*, $AnnotationType*)},
	{"cast", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TT;", $PUBLIC, $method(Class, cast, $Object*, Object$*), nullptr, nullptr, _Class_MethodAnnotations_cast8},
	{"checkMemberAccess", "(Ljava/lang/SecurityManager;ILjava/lang/Class;Z)V", "(Ljava/lang/SecurityManager;ILjava/lang/Class<*>;Z)V", $PRIVATE, $method(Class, checkMemberAccess, void, $SecurityManager*, int32_t, Class*, bool)},
	{"checkPackageAccess", "(Ljava/lang/SecurityManager;Ljava/lang/ClassLoader;Z)V", nullptr, $PRIVATE, $method(Class, checkPackageAccess, void, $SecurityManager*, $ClassLoader*, bool)},
	{"checkPackageAccessForPermittedSubclasses", "(Ljava/lang/SecurityManager;Ljava/lang/ClassLoader;[Ljava/lang/Class;)V", "(Ljava/lang/SecurityManager;Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(Class, checkPackageAccessForPermittedSubclasses, void, $SecurityManager*, $ClassLoader*, $ClassArray*)},
	{"componentType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Class, componentType, $TypeDescriptor$OfField*)},
	{"copyConstructors", "([Ljava/lang/reflect/Constructor;)[Ljava/lang/reflect/Constructor;", "<U:Ljava/lang/Object;>([Ljava/lang/reflect/Constructor<TU;>;)[Ljava/lang/reflect/Constructor<TU;>;", $PRIVATE | $STATIC, $staticMethod(Class, copyConstructors, $ConstructorArray*, $ConstructorArray*)},
	{"copyFields", "([Ljava/lang/reflect/Field;)[Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC, $staticMethod(Class, copyFields, $FieldArray*, $FieldArray*)},
	{"copyMethods", "([Ljava/lang/reflect/Method;)[Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticMethod(Class, copyMethods, $MethodArray*, $MethodArray*)},
	{"createAnnotationData", "(I)Ljava/lang/Class$AnnotationData;", nullptr, $PRIVATE, $method(Class, createAnnotationData, $Class$AnnotationData*, int32_t)},
	{"describeConstable", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/constant/ClassDesc;>;", $PUBLIC, $virtualMethod(Class, describeConstable, $Optional*)},
	{"descriptorString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Class, descriptorString, $String*)},
	{"desiredAssertionStatus", "()Z", nullptr, $PUBLIC, $method(Class, desiredAssertionStatus, bool)},
	{"desiredAssertionStatus0", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC | $NATIVE, $staticMethod(Class, desiredAssertionStatus0, bool, Class*)},
	{"elementType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(Class, elementType, Class*)},
	{"enumConstantDirectory", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;TT;>;", 0, $method(Class, enumConstantDirectory, $Map*)},
	{"forName", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(Class, forName, Class*, $String*), "java.lang.ClassNotFoundException", nullptr, _Class_MethodAnnotations_forName23},
	{"forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(Class, forName, Class*, $String*, bool, $ClassLoader*), "java.lang.ClassNotFoundException", nullptr, _Class_MethodAnnotations_forName24},
	{"forName", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(Class, forName, Class*, $Module*, $String*), nullptr, nullptr, _Class_MethodAnnotations_forName25},
	{"forName0", "(Ljava/lang/String;ZLjava/lang/ClassLoader;Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/String;ZLjava/lang/ClassLoader;Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $NATIVE, $staticMethod(Class, forName0, Class*, $String*, bool, $ClassLoader*, Class*), "java.lang.ClassNotFoundException"},
	{"getAnnotatedInterfaces", "()[Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $method(Class, getAnnotatedInterfaces, $AnnotatedTypeArray*)},
	{"getAnnotatedSuperclass", "()Ljava/lang/reflect/AnnotatedType;", nullptr, $PUBLIC, $method(Class, getAnnotatedSuperclass, $AnnotatedType*)},
	{"getAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TA;>;)TA;", $PUBLIC, $virtualMethod(Class, getAnnotation, $Annotation*, Class*)},
	{"getAnnotationType", "()Lsun/reflect/annotation/AnnotationType;", nullptr, 0, $method(Class, getAnnotationType, $AnnotationType*)},
	{"getAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Class, getAnnotations, $AnnotationArray*)},
	{"getAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TA;>;)[TA;", $PUBLIC, $virtualMethod(Class, getAnnotationsByType, $AnnotationArray*, Class*)},
	{"getCanonicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Class, getCanonicalName, $String*)},
	{"getCanonicalName0", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(Class, getCanonicalName0, $String*)},
	{"getClassData", "()Ljava/lang/Object;", nullptr, 0, $method(Class, getClassData, $Object*)},
	{"getClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC, $method(Class, getClassLoader, $ClassLoader*), nullptr, nullptr, _Class_MethodAnnotations_getClassLoader36},
	{"getClassLoader0", "()Ljava/lang/ClassLoader;", nullptr, 0, $method(Class, getClassLoader0, $ClassLoader*)},
	{"getClasses", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getClasses, $ClassArray*), nullptr, nullptr, _Class_MethodAnnotations_getClasses38},
	{"getComponentType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getComponentType, Class*)},
	{"getConstantPool", "()Ljdk/internal/reflect/ConstantPool;", nullptr, $NATIVE, $method(Class, getConstantPool, $ConstantPool*)},
	{"getConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "([Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<TT;>;", $PUBLIC | $TRANSIENT, $method(Class, getConstructor, $Constructor*, $ClassArray*), "java.lang.NoSuchMethodException,java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getConstructor41},
	{"getConstructor0", "([Ljava/lang/Class;I)Ljava/lang/reflect/Constructor;", "([Ljava/lang/Class<*>;I)Ljava/lang/reflect/Constructor<TT;>;", $PRIVATE, $method(Class, getConstructor0, $Constructor*, $ClassArray*, int32_t), "java.lang.NoSuchMethodException"},
	{"getConstructors", "()[Ljava/lang/reflect/Constructor;", "()[Ljava/lang/reflect/Constructor<*>;", $PUBLIC, $method(Class, getConstructors, $ConstructorArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getConstructors43},
	{"getDeclaredAnnotation", "(Ljava/lang/Class;)Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TA;>;)TA;", $PUBLIC, $virtualMethod(Class, getDeclaredAnnotation, $Annotation*, Class*)},
	{"getDeclaredAnnotationMap", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;Ljava/lang/annotation/Annotation;>;", 0, $method(Class, getDeclaredAnnotationMap, $Map*)},
	{"getDeclaredAnnotations", "()[Ljava/lang/annotation/Annotation;", nullptr, $PUBLIC, $virtualMethod(Class, getDeclaredAnnotations, $AnnotationArray*)},
	{"getDeclaredAnnotationsByType", "(Ljava/lang/Class;)[Ljava/lang/annotation/Annotation;", "<A::Ljava/lang/annotation/Annotation;>(Ljava/lang/Class<TA;>;)[TA;", $PUBLIC, $virtualMethod(Class, getDeclaredAnnotationsByType, $AnnotationArray*, Class*)},
	{"getDeclaredClasses", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getDeclaredClasses, $ClassArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredClasses48},
	{"getDeclaredClasses0", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PRIVATE | $NATIVE, $method(Class, getDeclaredClasses0, $ClassArray*)},
	{"getDeclaredConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "([Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<TT;>;", $PUBLIC | $TRANSIENT, $method(Class, getDeclaredConstructor, $Constructor*, $ClassArray*), "java.lang.NoSuchMethodException,java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredConstructor50},
	{"getDeclaredConstructors", "()[Ljava/lang/reflect/Constructor;", "()[Ljava/lang/reflect/Constructor<*>;", $PUBLIC, $method(Class, getDeclaredConstructors, $ConstructorArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredConstructors51},
	{"getDeclaredConstructors0", "(Z)[Ljava/lang/reflect/Constructor;", "(Z)[Ljava/lang/reflect/Constructor<TT;>;", $PRIVATE | $NATIVE, $method(Class, getDeclaredConstructors0, $ConstructorArray*, bool)},
	{"getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;", nullptr, $PUBLIC, $method(Class, getDeclaredField, $Field*, $String*), "java.lang.NoSuchFieldException,java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredField53},
	{"getDeclaredFields", "()[Ljava/lang/reflect/Field;", nullptr, $PUBLIC, $method(Class, getDeclaredFields, $FieldArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredFields54},
	{"getDeclaredFields0", "(Z)[Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $NATIVE, $method(Class, getDeclaredFields0, $FieldArray*, bool)},
	{"getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;", "(Ljava/lang/String;[Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PUBLIC | $TRANSIENT, $method(Class, getDeclaredMethod, $Method*, $String*, $ClassArray*), "java.lang.NoSuchMethodException,java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredMethod56},
	{"getDeclaredMethods", "()[Ljava/lang/reflect/Method;", nullptr, $PUBLIC, $method(Class, getDeclaredMethods, $MethodArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaredMethods57},
	{"getDeclaredMethods0", "(Z)[Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $NATIVE, $method(Class, getDeclaredMethods0, $MethodArray*, bool)},
	{"getDeclaredPublicMethods", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/util/List;", "(Ljava/lang/String;[Ljava/lang/Class<*>;)Ljava/util/List<Ljava/lang/reflect/Method;>;", $TRANSIENT, $method(Class, getDeclaredPublicMethods, $List*, $String*, $ClassArray*)},
	{"getDeclaringClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getDeclaringClass, Class*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getDeclaringClass60},
	{"getDeclaringClass0", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE | $NATIVE, $method(Class, getDeclaringClass0, Class*)},
	{"getEnclosingClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getEnclosingClass, Class*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getEnclosingClass62},
	{"getEnclosingConstructor", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<*>;", $PUBLIC, $method(Class, getEnclosingConstructor, $Constructor*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getEnclosingConstructor63},
	{"getEnclosingMethod", "()Ljava/lang/reflect/Method;", nullptr, $PUBLIC, $method(Class, getEnclosingMethod, $Method*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getEnclosingMethod64},
	{"getEnclosingMethod0", "()[Ljava/lang/Object;", nullptr, $PRIVATE | $NATIVE, $method(Class, getEnclosingMethod0, $ObjectArray*)},
	{"getEnclosingMethodInfo", "()Ljava/lang/Class$EnclosingMethodInfo;", nullptr, $PRIVATE, $method(Class, getEnclosingMethodInfo, $Class$EnclosingMethodInfo*)},
	{"getEnumConstants", "()[Ljava/lang/Object;", "()[TT;", $PUBLIC, $method(Class, getEnumConstants, $ObjectArray*)},
	{"getEnumConstantsShared", "()[Ljava/lang/Object;", "()[TT;", 0, $method(Class, getEnumConstantsShared, $ObjectArray*)},
	{"getExecutableTypeAnnotationBytes", "(Ljava/lang/reflect/Executable;)[B", nullptr, $STATIC, $staticMethod(Class, getExecutableTypeAnnotationBytes, $bytes*, $Executable*)},
	{"getFactory", "()Lsun/reflect/generics/factory/GenericsFactory;", nullptr, $PRIVATE, $method(Class, getFactory, $GenericsFactory*)},
	{"getField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;", nullptr, $PUBLIC, $method(Class, getField, $Field*, $String*), "java.lang.NoSuchFieldException,java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getField71},
	{"getField0", "(Ljava/lang/String;)Ljava/lang/reflect/Field;", nullptr, $PRIVATE, $method(Class, getField0, $Field*, $String*)},
	{"getFields", "()[Ljava/lang/reflect/Field;", nullptr, $PUBLIC, $method(Class, getFields, $FieldArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getFields73},
	{"getGenericInfo", "()Lsun/reflect/generics/repository/ClassRepository;", nullptr, $PRIVATE, $method(Class, getGenericInfo, $ClassRepository*)},
	{"getGenericInterfaces", "()[Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $method(Class, getGenericInterfaces, $TypeArray*)},
	{"getGenericSignature0", "()Ljava/lang/String;", nullptr, $PRIVATE | $NATIVE, $method(Class, getGenericSignature0, $String*)},
	{"getGenericSuperclass", "()Ljava/lang/reflect/Type;", nullptr, $PUBLIC, $method(Class, getGenericSuperclass, $Type*)},
	{"getInterfaces", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getInterfaces, $ClassArray*)},
	{"getInterfaces", "(Z)[Ljava/lang/Class;", "(Z)[Ljava/lang/Class<*>;", $PRIVATE, $method(Class, getInterfaces, $ClassArray*, bool)},
	{"getInterfaces0", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PRIVATE | $NATIVE, $method(Class, getInterfaces0, $ClassArray*)},
	{"getMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;", "(Ljava/lang/String;[Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PUBLIC | $TRANSIENT, $method(Class, getMethod, $Method*, $String*, $ClassArray*), "java.lang.NoSuchMethodException,java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getMethod81},
	{"getMethod0", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;", "(Ljava/lang/String;[Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PRIVATE, $method(Class, getMethod0, $Method*, $String*, $ClassArray*)},
	{"getMethods", "()[Ljava/lang/reflect/Method;", nullptr, $PUBLIC, $method(Class, getMethods, $MethodArray*), "java.lang.SecurityException", nullptr, _Class_MethodAnnotations_getMethods83},
	{"getMethodsRecursive", "(Ljava/lang/String;[Ljava/lang/Class;Z)Ljava/lang/PublicMethods$MethodList;", "(Ljava/lang/String;[Ljava/lang/Class<*>;Z)Ljava/lang/PublicMethods$MethodList;", $PRIVATE, $method(Class, getMethodsRecursive, $PublicMethods$MethodList*, $String*, $ClassArray*, bool)},
	{"getModifiers", "()I", nullptr, $PUBLIC | $NATIVE, $method(Class, getModifiers, int32_t), nullptr, nullptr, _Class_MethodAnnotations_getModifiers85},
	{"getModule", "()Ljava/lang/Module;", nullptr, $PUBLIC, $method(Class, getModule, $Module*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Class, getName, $String*)},
	{"getNestHost", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getNestHost, Class*), nullptr, nullptr, _Class_MethodAnnotations_getNestHost88},
	{"getNestHost0", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE | $NATIVE, $method(Class, getNestHost0, Class*)},
	{"getNestMembers", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getNestMembers, $ClassArray*), nullptr, nullptr, _Class_MethodAnnotations_getNestMembers90},
	{"getNestMembers0", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PRIVATE | $NATIVE, $method(Class, getNestMembers0, $ClassArray*)},
	{"getPackage", "()Ljava/lang/Package;", nullptr, $PUBLIC, $method(Class, getPackage, $Package*)},
	{"getPackageName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Class, getPackageName, $String*)},
	{"getPermittedSubclasses", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $method(Class, getPermittedSubclasses, $ClassArray*), nullptr, nullptr, _Class_MethodAnnotations_getPermittedSubclasses94},
	{"getPermittedSubclasses0", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PRIVATE | $NATIVE, $method(Class, getPermittedSubclasses0, $ClassArray*)},
	{"getPrimitiveClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $STATIC | $NATIVE, $staticMethod(Class, getPrimitiveClass, Class*, $String*)},
	{"getProtectionDomain", "()Ljava/security/ProtectionDomain;", nullptr, $PUBLIC, $method(Class, getProtectionDomain, $ProtectionDomain*)},
	{"getProtectionDomain0", "()Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $NATIVE, $method(Class, getProtectionDomain0, $ProtectionDomain*)},
	{"getRawAnnotations", "()[B", nullptr, $NATIVE, $method(Class, getRawAnnotations, $bytes*)},
	{"getRawTypeAnnotations", "()[B", nullptr, $NATIVE, $method(Class, getRawTypeAnnotations, $bytes*)},
	{"getRecordComponents", "()[Ljava/lang/reflect/RecordComponent;", nullptr, $PUBLIC, $method(Class, getRecordComponents, $RecordComponentArray*), nullptr, nullptr, _Class_MethodAnnotations_getRecordComponents101},
	{"getRecordComponents0", "()[Ljava/lang/reflect/RecordComponent;", nullptr, $PRIVATE | $NATIVE, $method(Class, getRecordComponents0, $RecordComponentArray*)},
	{"getReflectionFactory", "()Ljdk/internal/reflect/ReflectionFactory;", nullptr, $PRIVATE | $STATIC, $staticMethod(Class, getReflectionFactory, $ReflectionFactory*)},
	{"getResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $method(Class, getResource, $URL*, $String*), nullptr, nullptr, _Class_MethodAnnotations_getResource104},
	{"getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $method(Class, getResourceAsStream, $InputStream*, $String*), nullptr, nullptr, _Class_MethodAnnotations_getResourceAsStream105},
	{"getSigners", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $NATIVE, $method(Class, getSigners, $ObjectArray*)},
	{"getSimpleBinaryName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(Class, getSimpleBinaryName, $String*)},
	{"getSimpleBinaryName0", "()Ljava/lang/String;", nullptr, $PRIVATE | $NATIVE, $method(Class, getSimpleBinaryName0, $String*)},
	{"getSimpleName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Class, getSimpleName, $String*)},
	{"getSimpleName0", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(Class, getSimpleName0, $String*)},
	{"getSuperclass", "()Ljava/lang/Class;", "()Ljava/lang/Class<-TT;>;", $PUBLIC | $NATIVE, $method(Class, getSuperclass, Class*), nullptr, nullptr, _Class_MethodAnnotations_getSuperclass111},
	{"getTypeName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Class, getTypeName, $String*)},
	{"getTypeParameters", "()[Ljava/lang/reflect/TypeVariable;", "()[Ljava/lang/reflect/TypeVariable<Ljava/lang/Class<TT;>;>;", $PUBLIC, $virtualMethod(Class, getTypeParameters, $TypeVariableArray*)},
	{"hasEnclosingMethodInfo", "()Z", nullptr, $PRIVATE, $method(Class, hasEnclosingMethodInfo, bool)},
	{"initClassName", "()Ljava/lang/String;", nullptr, $PRIVATE | $NATIVE, $method(Class, initClassName, $String*)},
	{"isAnnotation", "()Z", nullptr, $PUBLIC, $method(Class, isAnnotation, bool)},
	{"isAnnotationPresent", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;)Z", $PUBLIC, $virtualMethod(Class, isAnnotationPresent, bool, Class*)},
	{"isAnonymousClass", "()Z", nullptr, $PUBLIC, $method(Class, isAnonymousClass, bool)},
	{"isArray", "()Z", nullptr, $PUBLIC | $NATIVE, $virtualMethod(Class, isArray, bool), nullptr, nullptr, _Class_MethodAnnotations_isArray119},
	{"isAssignableFrom", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC | $NATIVE, $method(Class, isAssignableFrom, bool, Class*), nullptr, nullptr, _Class_MethodAnnotations_isAssignableFrom120},
	{"isDirectSubType", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE, $method(Class, isDirectSubType, bool, Class*)},
	{"isEnum", "()Z", nullptr, $PUBLIC, $method(Class, isEnum, bool)},
	{"isHidden", "()Z", nullptr, $PUBLIC | $NATIVE, $method(Class, isHidden, bool), nullptr, nullptr, _Class_MethodAnnotations_isHidden123},
	{"isInstance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $NATIVE, $method(Class, isInstance, bool, Object$*), nullptr, nullptr, _Class_MethodAnnotations_isInstance124},
	{"isInterface", "()Z", nullptr, $PUBLIC | $NATIVE, $method(Class, isInterface, bool), nullptr, nullptr, _Class_MethodAnnotations_isInterface125},
	{"isLocalClass", "()Z", nullptr, $PUBLIC, $method(Class, isLocalClass, bool)},
	{"isLocalOrAnonymousClass", "()Z", nullptr, $PRIVATE, $method(Class, isLocalOrAnonymousClass, bool)},
	{"isMemberClass", "()Z", nullptr, $PUBLIC, $method(Class, isMemberClass, bool)},
	{"isNestmateOf", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC, $method(Class, isNestmateOf, bool, Class*)},
	{"isOpenToCaller", "(Ljava/lang/String;Ljava/lang/Class;)Z", "(Ljava/lang/String;Ljava/lang/Class<*>;)Z", $PRIVATE, $method(Class, isOpenToCaller, bool, $String*, Class*)},
	{"isPrimitive", "()Z", nullptr, $PUBLIC | $NATIVE, $virtualMethod(Class, isPrimitive, bool), nullptr, nullptr, _Class_MethodAnnotations_isPrimitive131},
	{"isRecord", "()Z", nullptr, $PUBLIC, $method(Class, isRecord, bool)},
	{"isRecord0", "()Z", nullptr, $PRIVATE | $NATIVE, $method(Class, isRecord0, bool)},
	{"isSealed", "()Z", nullptr, $PUBLIC, $method(Class, isSealed, bool)},
	{"isSynthetic", "()Z", nullptr, $PUBLIC, $method(Class, isSynthetic, bool)},
	{"isTopLevelClass", "()Z", nullptr, $PRIVATE, $method(Class, isTopLevelClass, bool)},
	{"lambda$getPermittedSubclasses$1", "(Ljava/lang/Class;)Z", nullptr, $PRIVATE | $SYNTHETIC, $method(Class, lambda$getPermittedSubclasses$1, bool, Class*)},
	{"lambda$getPermittedSubclasses$2", "(I)[Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Class, lambda$getPermittedSubclasses$2, $ClassArray*, int32_t)},
	{"lambda$methodToString$0", "(Ljava/lang/Class;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Class, lambda$methodToString$0, $String*, Class*)},
	{"methodToString", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/String;[Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE, $method(Class, methodToString, $String*, $String*, $ClassArray*)},
	{"newInstance", "()Ljava/lang/Object;", "()TT;", $PUBLIC | $DEPRECATED, $method(Class, newInstance, $Object*), "java.lang.InstantiationException,java.lang.IllegalAccessException", nullptr, _Class_MethodAnnotations_newInstance141},
	{"newReflectionData", "(Ljava/lang/ref/SoftReference;I)Ljava/lang/Class$ReflectionData;", "(Ljava/lang/ref/SoftReference<Ljava/lang/Class$ReflectionData<TT;>;>;I)Ljava/lang/Class$ReflectionData<TT;>;", $PRIVATE, $method(Class, newReflectionData, $Class$ReflectionData*, $SoftReference*, int32_t)},
	{"privateGetDeclaredConstructors", "(Z)[Ljava/lang/reflect/Constructor;", "(Z)[Ljava/lang/reflect/Constructor<TT;>;", $PRIVATE, $method(Class, privateGetDeclaredConstructors, $ConstructorArray*, bool)},
	{"privateGetDeclaredFields", "(Z)[Ljava/lang/reflect/Field;", nullptr, $PRIVATE, $method(Class, privateGetDeclaredFields, $FieldArray*, bool)},
	{"privateGetDeclaredMethods", "(Z)[Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $method(Class, privateGetDeclaredMethods, $MethodArray*, bool)},
	{"privateGetPublicFields", "()[Ljava/lang/reflect/Field;", nullptr, $PRIVATE, $method(Class, privateGetPublicFields, $FieldArray*)},
	{"privateGetPublicMethods", "()[Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $method(Class, privateGetPublicMethods, $MethodArray*)},
	{"protectionDomain", "()Ljava/security/ProtectionDomain;", nullptr, 0, $method(Class, protectionDomain, $ProtectionDomain*)},
	{"reflectionData", "()Ljava/lang/Class$ReflectionData;", "()Ljava/lang/Class$ReflectionData<TT;>;", $PRIVATE, $method(Class, reflectionData, $Class$ReflectionData*)},
	{"registerNatives", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(Class, registerNatives, void)},
	{"resolveName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Class, resolveName, $String*, $String*)},
	{"searchFields", "([Ljava/lang/reflect/Field;Ljava/lang/String;)Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC, $staticMethod(Class, searchFields, $Field*, $FieldArray*, $String*)},
	{"searchMethods", "([Ljava/lang/reflect/Method;Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;", "([Ljava/lang/reflect/Method;Ljava/lang/String;[Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PRIVATE | $STATIC, $staticMethod(Class, searchMethods, $Method*, $MethodArray*, $String*, $ClassArray*)},
	{"setSigners", "([Ljava/lang/Object;)V", nullptr, $NATIVE, $method(Class, setSigners, void, $ObjectArray*)},
	{"toClass", "(Ljava/lang/reflect/Type;)Ljava/lang/Class;", "(Ljava/lang/reflect/Type;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(Class, toClass, Class*, $Type*)},
	{"toGenericString", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(Class, toGenericString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Class, toString, $String*)},
	{"typeVarBounds", "(Ljava/lang/reflect/TypeVariable;)Ljava/lang/String;", "(Ljava/lang/reflect/TypeVariable<*>;)Ljava/lang/String;", $STATIC, $staticMethod(Class, typeVarBounds, $String*, $TypeVariable*)},
	{}
};

#define _METHOD_INDEX_desiredAssertionStatus0 24
#define _METHOD_INDEX_forName0 30
#define _METHOD_INDEX_getConstantPool 44
#define _METHOD_INDEX_getDeclaredClasses0 53
#define _METHOD_INDEX_getDeclaredConstructors0 56
#define _METHOD_INDEX_getDeclaredFields0 59
#define _METHOD_INDEX_getDeclaredMethods0 62
#define _METHOD_INDEX_getDeclaringClass0 65
#define _METHOD_INDEX_getEnclosingMethod0 69
#define _METHOD_INDEX_getGenericSignature0 80
#define _METHOD_INDEX_getInterfaces0 84
#define _METHOD_INDEX_getModifiers 89
#define _METHOD_INDEX_getNestHost0 93
#define _METHOD_INDEX_getNestMembers0 95
#define _METHOD_INDEX_getPermittedSubclasses0 99
#define _METHOD_INDEX_getPrimitiveClass 100
#define _METHOD_INDEX_getProtectionDomain0 102
#define _METHOD_INDEX_getRawAnnotations 103
#define _METHOD_INDEX_getRawTypeAnnotations 104
#define _METHOD_INDEX_getRecordComponents0 106
#define _METHOD_INDEX_getSigners 110
#define _METHOD_INDEX_getSimpleBinaryName0 112
#define _METHOD_INDEX_getSuperclass 115
#define _METHOD_INDEX_initClassName 119
#define _METHOD_INDEX_isArray 123
#define _METHOD_INDEX_isAssignableFrom 124
#define _METHOD_INDEX_isHidden 127
#define _METHOD_INDEX_isInstance 128
#define _METHOD_INDEX_isInterface 129
#define _METHOD_INDEX_isPrimitive 135
#define _METHOD_INDEX_isRecord0 137
#define _METHOD_INDEX_registerNatives 154
#define _METHOD_INDEX_setSigners 158

$InnerClassInfo _Class_InnerClassesInfo_[] = {
	{"java.lang.invoke.TypeDescriptor$OfField", "java.lang.invoke.TypeDescriptor", "OfField", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.lang.Class$AnnotationData", "java.lang.Class", "AnnotationData", $PRIVATE | $STATIC},
	{"java.lang.Class$ReflectionData", "java.lang.Class", "ReflectionData", $PRIVATE | $STATIC},
	{"java.lang.Class$Atomic", "java.lang.Class", "Atomic", $PRIVATE | $STATIC},
	{"java.lang.Class$EnclosingMethodInfo", "java.lang.Class", "EnclosingMethodInfo", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.Class$3", nullptr, nullptr, 0},
	{"java.lang.Class$2", nullptr, nullptr, 0},
	{"java.lang.Class$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Class_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.Class",
	"java.lang.Object",
	"java.io.Serializable,java.lang.reflect.GenericDeclaration,java.lang.reflect.Type,java.lang.invoke.TypeDescriptor$OfField,java.lang.constant.Constable",
	_Class_FieldInfo_,
	_Class_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/io/Serializable;Ljava/lang/reflect/GenericDeclaration;Ljava/lang/reflect/Type;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/invoke/TypeDescriptor$OfField<Ljava/lang/Class<*>;>;Ljava/lang/constant/Constable;",
	nullptr,
	_Class_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.Class$AnnotationData,java.lang.Class$ReflectionData,java.lang.Class$Atomic,java.lang.Class$EnclosingMethodInfo,java.lang.Class$3,java.lang.Class$2,java.lang.Class$1"
};

$Object* allocate$Class(Class* clazz) {
	return $of($alloc(Class));
}

int32_t Class::hashCode() {
	 return this->$Serializable::hashCode();
}

bool Class::equals(Object$* obj) {
	 return this->$Serializable::equals(obj);
}

$Object* Class::clone() {
	 return this->$Serializable::clone();
}

void Class::finalize() {
	this->$Serializable::finalize();
}

$ProtectionDomain* Class::allPermDomain = nullptr;
$ClassArray* Class::EMPTY_CLASS_ARRAY = nullptr;
$ObjectStreamFieldArray* Class::serialPersistentFields = nullptr;
$ReflectionFactory* Class::reflectionFactory = nullptr;

void Class::registerNatives() {
}

void Class::init$($ClassLoader* loader, Class* arrayComponentType) {
	$set(this, classLoader, loader);
	$set(this, componentType$, arrayComponentType);
}

$String* Class::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, (isInterface() ? "interface "_s : (isPrimitive() ? ""_s : "class "_s)));
	return $concat(var$0, $(getName()));
}

$String* Class::toGenericString() {
	$useLocalCurrentObjectStackCache();
	if (isPrimitive()) {
		return toString();
	} else {
		$var($StringBuilder, sb, $new($StringBuilder));
		Class* component = this;
		int32_t arrayDepth = 0;
		if (isArray()) {
			do {
				++arrayDepth;
				component = $nc(component)->getComponentType();
			} while ($nc(component)->isArray());
			sb->append($(component->getName()));
		} else {
			int32_t var$0 = getModifiers();
			int32_t modifiers = (int32_t)(var$0 & (uint32_t)$Modifier::classModifiers());
			if (modifiers != 0) {
				sb->append($($Modifier::toString(modifiers)));
				sb->append(u' ');
			}
			if (isAnnotation()) {
				sb->append(u'@');
			}
			if (isInterface()) {
				sb->append("interface"_s);
			} else if (isEnum()) {
				sb->append("enum"_s);
			} else if (isRecord()) {
				sb->append("record"_s);
			} else {
				sb->append("class"_s);
			}
			sb->append(u' ');
			sb->append($(getName()));
		}
		$var($TypeVariableArray, typeparms, $nc(component)->getTypeParameters());
		if ($nc(typeparms)->length > 0) {
			sb->append($cast($String, $($nc($($nc($($Arrays::stream(typeparms)))->map(static_cast<$Function*>($$new(Class$$Lambda$typeVarBounds)))))->collect($($Collectors::joining(","_s, "<"_s, ">"_s))))));
		}
		if (arrayDepth > 0) {
			sb->append($("[]"_s->repeat(arrayDepth)));
		}
		return sb->toString();
	}
}

$String* Class::typeVarBounds($TypeVariable* typeVar) {
	$useLocalCurrentObjectStackCache();
	$var($TypeArray, bounds, $nc(typeVar)->getBounds());
	if ($nc(bounds)->length == 1 && $nc($of(bounds->get(0)))->equals($Object::class$)) {
		return typeVar->getName();
	} else {
		$var($String, var$0, $$str({$(typeVar->getName()), " extends "_s}));
		return $concat(var$0, $cast($String, $($nc($($nc($($Arrays::stream(bounds)))->map(static_cast<$Function*>($$new(Class$$Lambda$getTypeName$1)))))->collect($($Collectors::joining(" & "_s))))));
	}
}

Class* Class::forName($String* className) {
	if ($nullcheck(className)->equals("java.lang.Object")) {
		return Object::class$;
	}
	Class* caller = $Reflection::getCallerClass();
	return forName0(className, true, $($ClassLoader::getClassLoader(caller)), caller);
}

Class* Class::forName($String* name, bool initialize, $ClassLoader* loader) {
	$useLocalCurrentObjectStackCache();
	Class* caller = nullptr;
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		caller = $Reflection::getCallerClass();
		if (loader == nullptr) {
			$var($ClassLoader, ccl, $ClassLoader::getClassLoader(caller));
			if (ccl != nullptr) {
				$init($SecurityConstants);
				sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
			}
		}
	}
	return forName0(name, initialize, loader, caller);
}

Class* Class::forName0($String* name, bool initialize, $ClassLoader* loader, Class* caller) {
	return Machine::forName0(name, initialize, loader, caller);
}

Class* Class::forName($Module* module, $String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(module);
	$Objects::requireNonNull(name);
	$var($ClassLoader, cl, nullptr);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		Class* caller = $Reflection::getCallerClass();
		if (caller != nullptr && caller->getModule() != module) {
			$init($SecurityConstants);
			sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
		}
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(Class$$Lambda$getClassLoader$2, static_cast<$Module*>(module))));
		$assign(cl, $cast($ClassLoader, $AccessController::doPrivileged(pa)));
	} else {
		$assign(cl, module->getClassLoader());
	}
	if (cl != nullptr) {
		return cl->loadClass(module, name);
	} else {
		return $BootLoader::loadClass(module, name);
	}
}

$Object* Class::newInstance() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), false);
	}
	$var($Constructor, tmpConstructor, this->cachedConstructor);
	if (tmpConstructor == nullptr) {
		if (this == Class::class$) {
			$throwNew($IllegalAccessException, "Can not call newInstance() on the Class for java.lang.Class"_s);
		}
		try {
			$var($ClassArray, empty, $new($ClassArray, 0));
			$var($Constructor, c, $nc($(getReflectionFactory()))->copyConstructor($(getConstructor0(empty, $Member::DECLARED))));
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Class$1, this, c)));
			$set(this, cachedConstructor, ($assign(tmpConstructor, c)));
		} catch ($NoSuchMethodException& e) {
			$throw($cast($InstantiationException, $($$new($InstantiationException, $(getName()))->initCause(e))));
		}
	}
	try {
		Class* caller = $Reflection::getCallerClass();
		return $of($nc($(getReflectionFactory()))->newInstance(tmpConstructor, nullptr, caller));
	} catch ($InvocationTargetException& e) {
		$nc($($Unsafe::getUnsafe()))->throwException($(e->getTargetException()));
		return $of(nullptr);
	}
	$shouldNotReachHere();
}

bool Class::isInstance(Object$* obj) {
	if (obj == nullptr) {
		return false;
	}
	Object0* obj0 = $toObject0(obj);
	Class* clazz = obj0->getClass();
	if (clazz == this) {
		return true;
	}
	return isAssignableFrom(clazz);
}

bool Class::isAssignableFrom(Class* from) {
	$nullcheck(from);
	if (this == from) {
		return true;
	}
	if (this == Object::class$) {
		return !from->isPrimitive();
	}
	// is array
	if (this->componentType$ != nullptr) {
		if (from->componentType$ != nullptr) {
			return this->componentType$->isAssignableFrom(from->componentType$);
		} else {
			return false;
		}
	}
	int32_t offset = from->calcCastOffset(this, nullptr);
	return offset >= 0;
}

bool Class::isInterface() {
	return $Modifier::isInterface(getModifiers());
}

bool Class::isArray() {
	return componentType$ != nullptr;
}

bool Class::isPrimitive() {
	return primitive;
}

bool Class::isAnnotation() {
	return ((int32_t)(getModifiers() & (uint32_t)Class::ANNOTATION)) != 0;
}

bool Class::isSynthetic() {
	return ((int32_t)(getModifiers() & (uint32_t)Class::SYNTHETIC)) != 0;
}

$String* Class::getName() {
	$var($String, name, this->name);
	return name != nullptr ? name : initClassName();
}

$String* Class::initClassName() {
	if (name == nullptr) {
		$synchronized(this) {
			if (name == nullptr) {
				if (isArray()) {
					if (componentType$->isPrimitive()) {
						if (componentType$ == Byte::TYPE) {
							$set(this, name, "[B"_s);
						} else if (componentType$ == Short::TYPE) {
							$set(this, name, "[S"_s);
						} else if (componentType$ == Integer::TYPE) {
							$set(this, name, "[I"_s);
						} else if (componentType$ == Long::TYPE) {
							$set(this, name, "[J"_s);
						} else if (componentType$ == Float::TYPE) {
							$set(this, name, "[F"_s);
						} else if (componentType$ == Double::TYPE) {
							$set(this, name, "[D"_s);
						} else if (componentType$ == Boolean::TYPE) {
							$set(this, name, "[Z"_s);
						} else if (componentType$ == Character::TYPE) {
							$set(this, name, "[C"_s);
						}
					} else if (componentType$->isArray()) {
						$set(this, name, String::valueOf({"["_s, componentType$->getName()}));
					} else {
						$set(this, name, String::valueOf({"[L"_s, componentType$->getName(), ";"_s}));
					}
				} else if (classInfo != nullptr && classInfo->name != nullptr) {
					$set(this, name, $cstr(classInfo->name));
				}
			}
		}
	}
	return name;
}

$ClassLoader* Class::getClassLoader() {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, cl, getClassLoader0());
	if (cl == nullptr) {
		return nullptr;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$ClassLoader::checkClassLoaderPermission(cl, $Reflection::getCallerClass());
	}
	return cl;
}

$ClassLoader* Class::getClassLoader0() {
	return this->classLoader;
}

$Module* Class::getModule() {
	return this->module;
}

$Object* Class::getClassData() {
	return $of(this->classData);
}

$TypeVariableArray* Class::getTypeParameters() {
	$var($ClassRepository, info, getGenericInfo());
	if (info != nullptr) {
		return info->getTypeParameters();
	} else {
		return $new($TypeVariableArray, 0);
	}
}

Class* Class::getSuperclass() {
	if (superClass == nullptr) {
		if (this != Object::class$) {
			$synchronized(this) {
				if (superClass == nullptr) {
					if (classInfo != nullptr && classInfo->superClass != nullptr) {
						$set(this, superClass, forName(classInfo->superClass));
 					} else if (isArray()) {
						$set(this, superClass, Object::class$);
					}
				}
			}
		}
	}
	return superClass;
}

$Type* Class::getGenericSuperclass() {
	$var($ClassRepository, info, getGenericInfo());
	if (info == nullptr) {
		return getSuperclass();
	}
	if (isInterface()) {
		return nullptr;
	}
	return $nc(info)->getSuperclass();
}

$Package* Class::getPackage() {
	bool var$0 = isPrimitive();
	if (var$0 || isArray()) {
		return nullptr;
	}
	$var($ClassLoader, cl, getClassLoader0());
	return cl != nullptr ? $nc(cl)->definePackage(this) : $BootLoader::definePackage(this);
}

$String* Class::getPackageName() {
	$useLocalCurrentObjectStackCache();
	$var($String, pn, this->packageName);
	if (pn == nullptr) {
		Class* c = isArray() ? elementType() : this;
		if ($nc(c)->isPrimitive()) {
			$assign(pn, "java.lang"_s);
		} else {
			$var($String, cn, c->getName());
			int32_t dot = $nc(cn)->lastIndexOf((int32_t)u'.');
			$assign(pn, (dot != -1) ? $(cn->substring(0, dot))->intern() : ""_s);
		}
		$set(this, packageName, pn);
	}
	return pn;
}

$ClassArray* Class::getInterfaces() {
	return getInterfaces(true);
}

$ClassArray* Class::getInterfaces(bool cloneArray) {
	$useLocalCurrentObjectStackCache();
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd == nullptr) {
		return getInterfaces0();
	} else {
		$var($ClassArray, interfaces, rd->interfaces);
		if (interfaces == nullptr) {
			$assign(interfaces, getInterfaces0());
			$set(rd, interfaces, interfaces);
		}
		return cloneArray ? $cast($ClassArray, $nc(interfaces)->clone()) : interfaces;
	}
}

$ClassArray* Class::getInterfaces0() {
	if (classInfo == nullptr || classInfo->interfaces == nullptr) {
		return $new($ClassArray, 0);
	}
	$var($StringArray, sa, Util::split(classInfo->interfaces, ','));
	$var($ClassArray, interfaces, $new($ClassArray, sa->length));
	for (int32_t i = 0; i < interfaces->length; i++) {
		interfaces->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
	}
	return interfaces;
}

$TypeArray* Class::getGenericInterfaces() {
	$var($ClassRepository, info, getGenericInfo());
	return (info == nullptr) ? $fcast($TypeArray, getInterfaces()) : $nc(info)->getSuperInterfaces();
}

Class* Class::getComponentType() {
	return componentType$;
}

Class* Class::elementType() {
	if (!isArray()) {
		return nullptr;
	}
	Class* c = this;
	while ($nc(c)->isArray()) {
		c = c->getComponentType();
	}
	return c;
}

int32_t Class::getModifiers() {
	if (isPrimitive()) {
		// JVM_ACC_ABSTRACT | JVM_ACC_FINAL | JVM_ACC_PUBLIC
		return $Modifier::ABSTRACT | $Modifier::FINAL | $Modifier::PUBLIC;
	}
	if (classInfo != nullptr) {
		int32_t flags = classInfo->flags;
		InnerClassInfo* innerClass = classInfo->innerClasses;
		$var(String, name, getName());
		for (; innerClass != nullptr && !innerClass->isEnd(); innerClass++) {
			if (name->equals(innerClass->innerClass)) {
	//			flags &= ~$Modifier::ACCESS_MODIFIERS;
	// 			flags |= (classInfo->innerClasses->innerClassAccessFlags & $Modifier::ACCESS_MODIFIERS);
				flags = innerClass->innerClassAccessFlags;
				break;
			}
		}
		#define JVM_ACC_SUPER 0x20
		#define JVM_ACC_WRITTEN_FLAGS 0x00007FFF
		return (flags & (~JVM_ACC_SUPER)) & JVM_ACC_WRITTEN_FLAGS;
	}
	return 0;
}

$ObjectArray* Class::getSigners() {
	$var($ObjectArray, $ret, nullptr);
	$prepareNative(Class, getSigners, $ObjectArray*);
	$assign($ret, $invokeNativeObject());
	$finishNative();
	return $ret;
}

void Class::setSigners($ObjectArray* signers) {
	$prepareNative(Class, setSigners, void, $ObjectArray* signers);
	$invokeNative(signers);
	$finishNative();
}

$Method* Class::getEnclosingMethod() {
	$useLocalCurrentObjectStackCache();
	$var($Class$EnclosingMethodInfo, enclosingInfo, getEnclosingMethodInfo());
	if (enclosingInfo == nullptr) {
		return nullptr;
	} else {
		if (!$nc(enclosingInfo)->isMethod()) {
			return nullptr;
		}
		$var($String, var$0, $nc(enclosingInfo)->getDescriptor());
		$var($MethodRepository, typeInfo, $MethodRepository::make(var$0, $(getFactory())));
		Class* returnType = toClass($($nc(typeInfo)->getReturnType()));
		$var($TypeArray, parameterTypes, $nc(typeInfo)->getParameterTypes());
		$var($ClassArray, parameterClasses, $new($ClassArray, $nc(parameterTypes)->length));
		for (int32_t i = 0; i < parameterClasses->length; ++i) {
			parameterClasses->set(i, toClass(parameterTypes->get(i)));
		}
		Class* enclosingCandidate = $nc(enclosingInfo)->getEnclosingClass();
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$nc(enclosingCandidate)->checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
		}
		$var($MethodArray, candidates, $nc(enclosingCandidate)->privateGetDeclaredMethods(false));
		$var($ReflectionFactory, fact, getReflectionFactory());
		{
			$var($MethodArray, arr$, candidates);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Method, m, arr$->get(i$));
				{
					bool var$1 = $nc($($nc(m)->getName()))->equals($(enclosingInfo->getName()));
					if (var$1 && arrayContentsEq(parameterClasses, $(fact->getExecutableSharedParameterTypes(m)))) {
						if ($nc($of(m->getReturnType()))->equals(returnType)) {
							return fact->copyMethod(m);
						}
					}
				}
			}
		}
		$throwNew($InternalError, "Enclosing method not found"_s);
	}
}

$ObjectArray* Class::getEnclosingMethod0() {
	$var($ObjectArray, enclosingMethod, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(enclosingMethod, rd->enclosingMethod);
		if (enclosingMethod != nullptr) {
			return enclosingMethod;
		}
	}
	if (classInfo != nullptr && classInfo->enclosingMethod != nullptr) {
		$synchronized(this) {
			$assign(enclosingMethod, $new($ObjectArray, 3));
			enclosingMethod->set(0, forName(classInfo->enclosingMethod->enclClass));
			if (classInfo->enclosingMethod->name != nullptr) {
				enclosingMethod->set(1, $cstr(classInfo->enclosingMethod->name));
			}
			if (classInfo->enclosingMethod->descriptor != nullptr) {
				enclosingMethod->set(2, $cstr(classInfo->enclosingMethod->descriptor));
			}
			if (rd != nullptr) {
				$set(rd, enclosingMethod, enclosingMethod);
			}
		}
	}
	return enclosingMethod;
}

$Class$EnclosingMethodInfo* Class::getEnclosingMethodInfo() {
	$var($ObjectArray, enclosingInfo, getEnclosingMethod0());
	if (enclosingInfo == nullptr) {
		return nullptr;
	} else {
		return $new($Class$EnclosingMethodInfo, enclosingInfo);
	}
}

Class* Class::toClass($Type* o) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($GenericArrayType, o)) {
		return $of($($1Array::newInstance(toClass($($nc(($cast($GenericArrayType, o)))->getGenericComponentType())), 0)))->getClass();
	}
	return $cast(Class, o);
}

$Constructor* Class::getEnclosingConstructor() {
	$useLocalCurrentObjectStackCache();
	$var($Class$EnclosingMethodInfo, enclosingInfo, getEnclosingMethodInfo());
	if (enclosingInfo == nullptr) {
		return nullptr;
	} else {
		if (!$nc(enclosingInfo)->isConstructor()) {
			return nullptr;
		}
		$var($String, var$0, $nc(enclosingInfo)->getDescriptor());
		$var($ConstructorRepository, typeInfo, $ConstructorRepository::make(var$0, $(getFactory())));
		$var($TypeArray, parameterTypes, $nc(typeInfo)->getParameterTypes());
		$var($ClassArray, parameterClasses, $new($ClassArray, $nc(parameterTypes)->length));
		for (int32_t i = 0; i < parameterClasses->length; ++i) {
			parameterClasses->set(i, toClass(parameterTypes->get(i)));
		}
		Class* enclosingCandidate = $nc(enclosingInfo)->getEnclosingClass();
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$nc(enclosingCandidate)->checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
		}
		$var($ConstructorArray, candidates, $nc(enclosingCandidate)->privateGetDeclaredConstructors(false));
		$var($ReflectionFactory, fact, getReflectionFactory());
		{
			$var($ConstructorArray, arr$, candidates);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Constructor, c, arr$->get(i$));
				{
					if (arrayContentsEq(parameterClasses, $(fact->getExecutableSharedParameterTypes(c)))) {
						return fact->copyConstructor(c);
					}
				}
			}
		}
		$throwNew($InternalError, "Enclosing constructor not found"_s);
	}
}

Class* Class::getDeclaringClass() {
	$useLocalCurrentObjectStackCache();
	Class* candidate = getDeclaringClass0();
	if (candidate != nullptr) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			candidate->checkPackageAccess(sm, $($ClassLoader::getClassLoader($Reflection::getCallerClass())), true);
		}
	}
	return candidate;
}

Class* Class::getDeclaringClass0() {
	if (declaringClass == nullptr && classInfo != nullptr && classInfo->innerClasses != nullptr) {
		$synchronized(this) {
			if (declaringClass == nullptr) {
				$var(String, thisClassName, this->getName());
				InnerClassInfo* innerClassInfo = classInfo->innerClasses;
				for (; true; innerClassInfo++) {
					if (innerClassInfo->innerClass == nullptr) {
						break;
					}
					$var(String, innerClass, $cstr(innerClassInfo->innerClass)->replace(u'/', u'.'));
					if ($Objects::equals(thisClassName, innerClass) && innerClassInfo->outerClass != nullptr) {
						$set(this, declaringClass, forName(innerClassInfo->outerClass));
						break;
					}
				}
			}
		}
	}
	return declaringClass;
}

Class* Class::getEnclosingClass() {
	$useLocalCurrentObjectStackCache();
	$var($Class$EnclosingMethodInfo, enclosingInfo, getEnclosingMethodInfo());
	Class* enclosingCandidate = nullptr;
	if (enclosingInfo == nullptr) {
		enclosingCandidate = getDeclaringClass0();
	} else {
		Class* enclosingClass = $nc(enclosingInfo)->getEnclosingClass();
		if (enclosingClass == this || enclosingClass == nullptr) {
			$throwNew($InternalError, "Malformed enclosing method information"_s);
		} else {
			enclosingCandidate = enclosingClass;
		}
	}
	if (enclosingCandidate != nullptr) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			enclosingCandidate->checkPackageAccess(sm, $($ClassLoader::getClassLoader($Reflection::getCallerClass())), true);
		}
	}
	return enclosingCandidate;
}

$String* Class::getSimpleName() {
	$useLocalCurrentObjectStackCache();
	$var($Class$ReflectionData, rd, reflectionData());
	$var($String, simpleName, rd->simpleName);
	if (simpleName == nullptr) {
		$set(rd, simpleName, ($assign(simpleName, getSimpleName0())));
	}
	return simpleName;
}

$String* Class::getSimpleName0() {
	$useLocalCurrentObjectStackCache();
	if (isArray()) {
		return $str({$($nc(getComponentType())->getSimpleName()), "[]"_s});
	}
	$var($String, simpleName, getSimpleBinaryName());
	if (simpleName == nullptr) {
		$assign(simpleName, getName());
		$assign(simpleName, $nc(simpleName)->substring(simpleName->lastIndexOf((int32_t)u'.') + 1));
	}
	return simpleName;
}

$String* Class::getTypeName() {
	$useLocalCurrentObjectStackCache();
	if (isArray()) {
		try {
			Class* cl = this;
			int32_t dimensions = 0;
			do {
				++dimensions;
				cl = $nc(cl)->getComponentType();
			} while ($nc(cl)->isArray());
			$var($String, var$0, $(cl->getName()));
			return $concat(var$0, $("[]"_s->repeat(dimensions)));
		} catch ($Throwable& e) {
		}
	}
	return getName();
}

$String* Class::getCanonicalName() {
	$useLocalCurrentObjectStackCache();
	$var($Class$ReflectionData, rd, reflectionData());
	$var($String, canonicalName, rd->canonicalName);
	if (canonicalName == nullptr) {
		$set(rd, canonicalName, ($assign(canonicalName, getCanonicalName0())));
	}
	$init($Class$ReflectionData);
	return canonicalName == $Class$ReflectionData::NULL_SENTINEL ? ($String*)nullptr : canonicalName;
}

$String* Class::getCanonicalName0() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (isArray()) {
		$var($String, canonicalName, $nc(getComponentType())->getCanonicalName());
		if (canonicalName != nullptr) {
			return $str({canonicalName, "[]"_s});
		} else {
			$init($Class$ReflectionData);
			return $Class$ReflectionData::NULL_SENTINEL;
		}
	}
	bool var$0 = isHidden();
	if (var$0 || isLocalOrAnonymousClass()) {
		$init($Class$ReflectionData);
		return $Class$ReflectionData::NULL_SENTINEL;
	}
	Class* enclosingClass = getEnclosingClass();
	if (enclosingClass == nullptr) {
		return getName();
	} else {
		$var($String, enclosingName, $nc(enclosingClass)->getCanonicalName());
		if (enclosingName == nullptr) {
			$init($Class$ReflectionData);
			return $Class$ReflectionData::NULL_SENTINEL;
		}
		$var($String, simpleName, getSimpleName());
		int32_t var$1 = $nc(enclosingName)->length();
		return $$new($StringBuilder, var$1 + $nc(simpleName)->length() + 1)->append(enclosingName)->append(u'.')->append(simpleName)->toString();
	}
}

bool Class::isAnonymousClass() {
	bool var$1 = !isArray();
	bool var$0 = var$1 && isLocalOrAnonymousClass();
	return var$0 && getSimpleBinaryName0() == nullptr;
}

bool Class::isLocalClass() {
	bool var$0 = isLocalOrAnonymousClass();
	if (var$0) {
		bool var$1 = isArray();
		var$0 = (var$1 || getSimpleBinaryName0() != nullptr);
	}
	return var$0;
}

bool Class::isMemberClass() {
	bool var$0 = !isLocalOrAnonymousClass();
	return var$0 && getDeclaringClass0() != nullptr;
}

$String* Class::getSimpleBinaryName() {
	if (isTopLevelClass()) {
		return nullptr;
	}
	$var($String, name, getSimpleBinaryName0());
	if (name == nullptr) {
		return ""_s;
	}
	return name;
}

$String* Class::getSimpleBinaryName0() {
	if (simpleBinaryName == nullptr && classInfo != nullptr && classInfo->innerClasses != nullptr) {
		$synchronized(this) {
			if (simpleBinaryName == nullptr) {
				$var(String, thisClassName, this->getName());
				InnerClassInfo* innerClassInfo = classInfo->innerClasses;
				for (; true; innerClassInfo++) {
					if (innerClassInfo->innerClass == nullptr) {
						break;
					}
					$var(String, innerClass, $cstr(innerClassInfo->innerClass)->replace(u'/', u'.'));
					if ($Objects::equals(thisClassName, innerClass) && innerClassInfo->innerName != nullptr) {
						$set(this, simpleBinaryName, $cstr(innerClassInfo->innerName));
						break;
					}
				}
			}
		}
	}
	return simpleBinaryName;
}

bool Class::isTopLevelClass() {
	bool var$0 = !isLocalOrAnonymousClass();
	return var$0 && getDeclaringClass0() == nullptr;
}

bool Class::isLocalOrAnonymousClass() {
	return hasEnclosingMethodInfo();
}

bool Class::hasEnclosingMethodInfo() {
	$var($ObjectArray, enclosingInfo, getEnclosingMethod0());
	if (enclosingInfo != nullptr) {
		$Class$EnclosingMethodInfo::validate(enclosingInfo);
		return true;
	}
	return false;
}

$ClassArray* Class::getClasses() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), false);
	}
	return $cast($ClassArray, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Class$2, this))));
}

$FieldArray* Class::getFields() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), true);
	}
	return copyFields($(privateGetPublicFields()));
}

$MethodArray* Class::getMethods() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), true);
	}
	return copyMethods($(privateGetPublicMethods()));
}

$ConstructorArray* Class::getConstructors() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), true);
	}
	return copyConstructors($(privateGetDeclaredConstructors(true)));
}

$Field* Class::getField($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), true);
	}
	$var($Field, field, getField0(name));
	if (field == nullptr) {
		$throwNew($NoSuchFieldException, name);
	}
	return $nc($(getReflectionFactory()))->copyField(field);
}

$Method* Class::getMethod($String* name, $ClassArray* parameterTypes) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), true);
	}
	$var($Method, method, getMethod0(name, parameterTypes));
	if (method == nullptr) {
		$throwNew($NoSuchMethodException, $(methodToString(name, parameterTypes)));
	}
	return $nc($(getReflectionFactory()))->copyMethod(method);
}

$Constructor* Class::getConstructor($ClassArray* parameterTypes) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::PUBLIC, $Reflection::getCallerClass(), true);
	}
	return $nc($(getReflectionFactory()))->copyConstructor($(getConstructor0(parameterTypes, $Member::PUBLIC)));
}

$ClassArray* Class::getDeclaredClasses() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), false);
	}
	return getDeclaredClasses0();
}

$FieldArray* Class::getDeclaredFields() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	return copyFields($(privateGetDeclaredFields(false)));
}

$RecordComponentArray* Class::getRecordComponents() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	if (!isRecord()) {
		return nullptr;
	}
	return getRecordComponents0();
}

$MethodArray* Class::getDeclaredMethods() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	return copyMethods($(privateGetDeclaredMethods(false)));
}

$ConstructorArray* Class::getDeclaredConstructors() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	return copyConstructors($(privateGetDeclaredConstructors(false)));
}

$Field* Class::getDeclaredField($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	$var($Field, field, searchFields($(privateGetDeclaredFields(false)), name));
	if (field == nullptr) {
		$throwNew($NoSuchFieldException, name);
	}
	return $nc($(getReflectionFactory()))->copyField(field);
}

$Method* Class::getDeclaredMethod($String* name, $ClassArray* parameterTypes) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	$var($Method, method, searchMethods($(privateGetDeclaredMethods(false)), name, parameterTypes));
	if (method == nullptr) {
		$throwNew($NoSuchMethodException, $(methodToString(name, parameterTypes)));
	}
	return $nc($(getReflectionFactory()))->copyMethod(method);
}

$List* Class::getDeclaredPublicMethods($String* name, $ClassArray* parameterTypes) {
	$useLocalCurrentObjectStackCache();
	$var($MethodArray, methods, privateGetDeclaredMethods(true));
	$var($ReflectionFactory, factory, getReflectionFactory());
	$var($List, result, $new($ArrayList));
	{
		$var($MethodArray, arr$, methods);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, method, arr$->get(i$));
			{
				bool var$0 = $nc($($nc(method)->getName()))->equals(name);
				if (var$0 && $Arrays::equals($(factory->getExecutableSharedParameterTypes(method)), parameterTypes)) {
					result->add($(factory->copyMethod(method)));
				}
			}
		}
	}
	return result;
}

$Constructor* Class::getDeclaredConstructor($ClassArray* parameterTypes) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkMemberAccess(sm, $Member::DECLARED, $Reflection::getCallerClass(), true);
	}
	return $nc($(getReflectionFactory()))->copyConstructor($(getConstructor0(parameterTypes, $Member::DECLARED)));
}

$InputStream* Class::getResourceAsStream($String* name$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	$assign(name, resolveName(name));
	$var($Module, thisModule, getModule());
	if ($nc(thisModule)->isNamed()) {
		bool var$0 = $Resources::canEncapsulate(name);
		if (var$0 && !isOpenToCaller(name, $Reflection::getCallerClass())) {
			return nullptr;
		}
		$var($String, mn, thisModule->getName());
		$var($ClassLoader, cl, getClassLoader0());
		try {
			if (cl == nullptr) {
				return $BootLoader::findResourceAsStream(mn, name);
			} else if ($instanceOf($BuiltinClassLoader, cl)) {
				return $nc(($cast($BuiltinClassLoader, cl)))->findResourceAsStream(mn, name);
			} else {
				$var($URL, url, $nc(cl)->findResource(mn, name));
				return (url != nullptr) ? $nc(url)->openStream() : ($InputStream*)nullptr;
			}
		} catch ($IOException& e) {
			return nullptr;
		} catch ($SecurityException& e) {
			return nullptr;
		}
	}
	$var($ClassLoader, cl, getClassLoader0());
	if (cl == nullptr) {
		return $ClassLoader::getSystemResourceAsStream(name);
	} else {
		return $nc(cl)->getResourceAsStream(name);
	}
}

$URL* Class::getResource($String* name$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	$assign(name, resolveName(name));
	$var($Module, thisModule, getModule());
	if ($nc(thisModule)->isNamed()) {
		bool var$0 = $Resources::canEncapsulate(name);
		if (var$0 && !isOpenToCaller(name, $Reflection::getCallerClass())) {
			return nullptr;
		}
		$var($String, mn, thisModule->getName());
		$var($ClassLoader, cl, getClassLoader0());
		try {
			if (cl == nullptr) {
				return $BootLoader::findResource(mn, name);
			} else {
				return $nc(cl)->findResource(mn, name);
			}
		} catch ($IOException& ioe) {
			return nullptr;
		}
	}
	$var($ClassLoader, cl, getClassLoader0());
	if (cl == nullptr) {
		return $ClassLoader::getSystemResource(name);
	} else {
		return $nc(cl)->getResource(name);
	}
}

bool Class::isOpenToCaller($String* name, Class* caller) {
	$useLocalCurrentObjectStackCache();
	$var($Module, thisModule, getModule());
	$var($Module, callerModule, (caller != nullptr) ? $nc(caller)->getModule() : ($Module*)nullptr);
	if (callerModule != thisModule) {
		$var($String, pn, $Resources::toPackageName(name));
		if ($nc($($nc($($nc(thisModule)->getDescriptor()))->packages()))->contains(pn)) {
			if (callerModule == nullptr && !thisModule->isOpen(pn)) {
				return false;
			}
			if (!thisModule->isOpen(pn, callerModule)) {
				return false;
			}
		}
	}
	return true;
}

$ProtectionDomain* Class::getProtectionDomain() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_PD_PERMISSION);
	}
	return protectionDomain();
}

$ProtectionDomain* Class::protectionDomain() {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomain, pd, getProtectionDomain0());
	if (pd == nullptr) {
		if (Class::allPermDomain == nullptr) {
			$var($Permissions, perms, $new($Permissions));
			$init($SecurityConstants);
			perms->add($SecurityConstants::ALL_PERMISSION);
			$assignStatic(Class::allPermDomain, $new($ProtectionDomain, nullptr, perms));
		}
		$assign(pd, Class::allPermDomain);
	}
	return pd;
}

$ProtectionDomain* Class::getProtectionDomain0() {
	// TODO native
	return nullptr;
}

Class* Class::getPrimitiveClass($String* name) {
	return Machine::getPrimitiveClass(name);
}

void Class::checkMemberAccess($SecurityManager* sm, int32_t which, Class* caller, bool checkProxyInterfaces) {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, ccl, $ClassLoader::getClassLoader(caller));
	if (which != $Member::PUBLIC) {
		$var($ClassLoader, cl, getClassLoader0());
		if (ccl != cl) {
			$init($SecurityConstants);
			$nc(sm)->checkPermission($SecurityConstants::CHECK_MEMBER_ACCESS_PERMISSION);
		}
	}
	this->checkPackageAccess(sm, ccl, checkProxyInterfaces);
}

void Class::checkPackageAccess($SecurityManager* sm, $ClassLoader* ccl, bool checkProxyInterfaces) {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, cl, getClassLoader0());
	if ($ReflectUtil::needsPackageAccessCheck(ccl, cl)) {
		$var($String, pkg, this->getPackageName());
		if (!$nc(pkg)->isEmpty()) {
			bool var$0 = !$Proxy::isProxyClass(this);
			if (var$0 || $ReflectUtil::isNonPublicProxyClass(this)) {
				$nc(sm)->checkPackageAccess(pkg);
			}
		}
	}
	if (checkProxyInterfaces && $Proxy::isProxyClass(this)) {
		$ReflectUtil::checkProxyPackageAccess(ccl, $(this->getInterfaces()));
	}
}

void Class::checkPackageAccessForPermittedSubclasses($SecurityManager* sm, $ClassLoader* ccl, $ClassArray* subClasses) {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, cl, $nc($nc(subClasses)->get(0))->getClassLoader0());
	if ($ReflectUtil::needsPackageAccessCheck(ccl, cl)) {
		$var($Set, packages, $new($HashSet));
		{
			$var($ClassArray, arr$, subClasses);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				Class* c = arr$->get(i$);
				{
					if ($Proxy::isProxyClass(c)) {
						$throwNew($InternalError, $$str({"a permitted subclass should not be a proxy class: "_s, c}));
					}
					$var($String, pkg, $nc(c)->getPackageName());
					if (!$nc(pkg)->isEmpty()) {
						packages->add(pkg);
					}
				}
			}
		}
		{
			$var($Iterator, i$, packages->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, pkg, $cast($String, i$->next()));
				{
					$nc(sm)->checkPackageAccess(pkg);
				}
			}
		}
	}
}

$String* Class::resolveName($String* name$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	if (!$nc(name)->startsWith("/"_s)) {
		$var($String, baseName, getPackageName());
		if (!$nc(baseName)->isEmpty()) {
			int32_t var$0 = baseName->length() + 1;
			int32_t len = var$0 + name->length();
			$var($StringBuilder, sb, $new($StringBuilder, len));
			$assign(name, sb->append($(baseName->replace(u'.', u'/')))->append(u'/')->append(name)->toString());
		}
	} else {
		$assign(name, name->substring(1));
	}
	return name;
}

$Class$ReflectionData* Class::reflectionData() {
	$useLocalCurrentObjectStackCache();
	$var($SoftReference, reflectionData, this->reflectionData$);
	int32_t classRedefinedCount = this->classRedefinedCount;
	$var($Class$ReflectionData, rd, nullptr);
	if (reflectionData != nullptr && ($assign(rd, $cast($Class$ReflectionData, reflectionData->get()))) != nullptr && $nc(rd)->redefinedCount == classRedefinedCount) {
		return rd;
	}
	return newReflectionData(reflectionData, classRedefinedCount);
}

$Class$ReflectionData* Class::newReflectionData($SoftReference* oldReflectionData$renamed, int32_t classRedefinedCount) {
	$useLocalCurrentObjectStackCache();
	$var($SoftReference, oldReflectionData, oldReflectionData$renamed);
	while (true) {
		$var($Class$ReflectionData, rd, $new($Class$ReflectionData, classRedefinedCount));
		if ($Class$Atomic::casReflectionData(this, oldReflectionData, $$new($SoftReference, rd))) {
			return rd;
		}
		$assign(oldReflectionData, this->reflectionData$);
		classRedefinedCount = this->classRedefinedCount;
		if (oldReflectionData != nullptr && ($assign(rd, $cast($Class$ReflectionData, oldReflectionData->get()))) != nullptr && rd->redefinedCount == classRedefinedCount) {
			return rd;
		}
	}
}

$String* Class::getGenericSignature0() {
	$var(String, genericSignature, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(genericSignature, rd->genericSignature);
		if (genericSignature != nullptr) {
			return genericSignature;
		}
	}
	if (classInfo != nullptr && classInfo->signature != nullptr) {
		$synchronized(this) {
			$assign(genericSignature, $str(classInfo->signature));
			if (rd != nullptr) {
				$set(rd, genericSignature, genericSignature);
			}
		}
	}
	return genericSignature;
}

$GenericsFactory* Class::getFactory() {
	return $CoreReflectionFactory::make(this, $($ClassScope::make(this)));
}

$ClassRepository* Class::getGenericInfo() {
	$useLocalCurrentObjectStackCache();
	$var($ClassRepository, genericInfo, this->genericInfo);
	if (genericInfo == nullptr) {
		$var($String, signature, getGenericSignature0());
		if (signature == nullptr) {
			$init($ClassRepository);
			$assign(genericInfo, $ClassRepository::NONE);
		} else {
			$assign(genericInfo, $ClassRepository::make(signature, $(getFactory())));
		}
		$set(this, genericInfo, genericInfo);
	}
	$init($ClassRepository);
	return (genericInfo != $ClassRepository::NONE) ? genericInfo : ($ClassRepository*)nullptr;
}

$bytes* Class::getRawAnnotations() {
	if (classInfo != nullptr) {
		if (classInfo->rawAnnotations != nullptr) {
			return classInfo->rawAnnotations;
		}
		ensureConstantPoolInitialized();
		return classInfo->rawAnnotations;
	}
	return nullptr;
}

$bytes* Class::getRawTypeAnnotations() {
	if (classInfo != nullptr) {
		if (classInfo->rawTypeAnnotations != nullptr) {
			return classInfo->rawTypeAnnotations;
		}
		ensureConstantPoolInitialized();
		return classInfo->rawTypeAnnotations;
	}
	return nullptr;
}

$bytes* Class::getExecutableTypeAnnotationBytes($Executable* ex) {
	return $nc($(getReflectionFactory()))->getExecutableTypeAnnotationBytes(ex);
}

$ConstantPool* Class::getConstantPool() {
	$var($ConstantPool, constantPool, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(constantPool, rd->constantPool);
		if (constantPool != nullptr) {
			return constantPool;
		}
	}
	$synchronized(this) {
		$assign(constantPool, getConstantPool0());
		$set(rd, constantPool, constantPool);
	}
	return constantPool;
}

$FieldArray* Class::privateGetDeclaredFields(bool publicOnly) {
	$useLocalCurrentObjectStackCache();
	$var($FieldArray, res, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(res, publicOnly ? $cast($FieldArray, rd->declaredPublicFields) : $cast($FieldArray, rd->declaredFields));
		if (res != nullptr) {
			return res;
		}
	}
	$assign(res, $Reflection::filterFields(this, $(getDeclaredFields0(publicOnly))));
	if (rd != nullptr) {
		if (publicOnly) {
			$set(rd, declaredPublicFields, res);
		} else {
			$set(rd, declaredFields, res);
		}
	}
	return res;
}

$FieldArray* Class::privateGetPublicFields() {
	$useLocalCurrentObjectStackCache();
	$var($FieldArray, res, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(res, rd->publicFields);
		if (res != nullptr) {
			return res;
		}
	}
	$var($LinkedHashSet, fields, $new($LinkedHashSet));
	addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(static_cast<$HashSet*>(fields)))), $(privateGetDeclaredFields(true)));
	{
		$var($ClassArray, arr$, getInterfaces());
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			Class* si = arr$->get(i$);
			{
				addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(static_cast<$HashSet*>(fields)))), $($nc(si)->privateGetPublicFields()));
			}
		}
	}
	Class* sc = getSuperclass();
	if (sc != nullptr) {
		addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(static_cast<$HashSet*>(fields)))), $(sc->privateGetPublicFields()));
	}
	$assign(res, $fcast($FieldArray, fields->toArray($$new($FieldArray, 0))));
	if (rd != nullptr) {
		$set(rd, publicFields, res);
	}
	return res;
}

void Class::addAll($Collection* c, $FieldArray* o) {
	$useLocalCurrentObjectStackCache();
	{
		$var($FieldArray, arr$, o);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Field, f, arr$->get(i$));
			{
				$nc(c)->add(f);
			}
		}
	}
}

$ConstructorArray* Class::privateGetDeclaredConstructors(bool publicOnly) {
	$useLocalCurrentObjectStackCache();
	$var($ConstructorArray, res, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(res, publicOnly ? $cast($ConstructorArray, rd->publicConstructors) : $cast($ConstructorArray, rd->declaredConstructors));
		if (res != nullptr) {
			return res;
		}
	}
	if (isInterface()) {
		$var($ConstructorArray, temporaryRes, $new($ConstructorArray, 0));
		$assign(res, temporaryRes);
	} else {
		$assign(res, getDeclaredConstructors0(publicOnly));
	}
	if (rd != nullptr) {
		if (publicOnly) {
			$set(rd, publicConstructors, res);
		} else {
			$set(rd, declaredConstructors, res);
		}
	}
	return res;
}

$MethodArray* Class::privateGetDeclaredMethods(bool publicOnly) {
	$useLocalCurrentObjectStackCache();
	$var($MethodArray, res, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(res, publicOnly ? $cast($MethodArray, rd->declaredPublicMethods) : $cast($MethodArray, rd->declaredMethods));
		if (res != nullptr) {
			return res;
		}
	}
	$assign(res, $Reflection::filterMethods(this, $(getDeclaredMethods0(publicOnly))));
	if (rd != nullptr) {
		if (publicOnly) {
			$set(rd, declaredPublicMethods, res);
		} else {
			$set(rd, declaredMethods, res);
		}
	}
	return res;
}

$MethodArray* Class::privateGetPublicMethods() {
	$useLocalCurrentObjectStackCache();
	$var($MethodArray, res, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(res, rd->publicMethods);
		if (res != nullptr) {
			return res;
		}
	}
	$var($PublicMethods, pms, $new($PublicMethods));
	{
		$var($MethodArray, arr$, privateGetDeclaredMethods(true));
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, m, arr$->get(i$));
			{
				pms->merge(m);
			}
		}
	}
	Class* sc = getSuperclass();
	if (sc != nullptr) {
		{
			$var($MethodArray, arr$, sc->privateGetPublicMethods());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Method, m, arr$->get(i$));
				{
					pms->merge(m);
				}
			}
		}
	}
	{
		$var($ClassArray, arr$, getInterfaces(false));
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			Class* intf = arr$->get(i$);
			{
				{
					$var($MethodArray, arr$, $nc(intf)->privateGetPublicMethods());
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Method, m, arr$->get(i$));
						{
							if (!$Modifier::isStatic($nc(m)->getModifiers())) {
								pms->merge(m);
							}
						}
					}
				}
			}
		}
	}
	$assign(res, pms->toArray());
	if (rd != nullptr) {
		$set(rd, publicMethods, res);
	}
	return res;
}

$Field* Class::searchFields($FieldArray* fields, $String* name) {
	$useLocalCurrentObjectStackCache();
	{
		$var($FieldArray, arr$, fields);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Field, field, arr$->get(i$));
			{
				if ($nc($($nc(field)->getName()))->equals(name)) {
					return field;
				}
			}
		}
	}
	return nullptr;
}

$Field* Class::getField0($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Field, res, nullptr);
	if (($assign(res, searchFields($(privateGetDeclaredFields(true)), name))) != nullptr) {
		return res;
	}
	$var($ClassArray, interfaces, getInterfaces(false));
	{
		$var($ClassArray, arr$, interfaces);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			Class* c = arr$->get(i$);
			{
				if (($assign(res, $nc(c)->getField0(name))) != nullptr) {
					return res;
				}
			}
		}
	}
	if (!isInterface()) {
		Class* c = getSuperclass();
		if (c != nullptr) {
			if (($assign(res, c->getField0(name))) != nullptr) {
				return res;
			}
		}
	}
	return nullptr;
}

$Method* Class::searchMethods($MethodArray* methods, $String* name, $ClassArray* parameterTypes) {
	$useLocalCurrentObjectStackCache();
	$var($ReflectionFactory, fact, getReflectionFactory());
	$var($Method, res, nullptr);
	{
		$var($MethodArray, arr$, methods);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, m, arr$->get(i$));
			{
				bool var$1 = $nc($($nc(m)->getName()))->equals(name);
				bool var$0 = var$1 && arrayContentsEq(parameterTypes, $(fact->getExecutableSharedParameterTypes(m)));
				if (var$0) {
					bool var$2 = res == nullptr;
					if (!var$2) {
						bool var$3 = $nc(res)->getReturnType() != $nc(m)->getReturnType();
						var$2 = (var$3 && $nc(res->getReturnType())->isAssignableFrom(m->getReturnType()));
					}
					var$0 = (var$2);
				}
				if (var$0) {
					$assign(res, m);
				}
			}
		}
	}
	return res;
}

$Method* Class::getMethod0($String* name, $ClassArray* parameterTypes) {
	$var($PublicMethods$MethodList, res, getMethodsRecursive(name, parameterTypes == nullptr ? Class::EMPTY_CLASS_ARRAY : parameterTypes, true));
	return res == nullptr ? ($Method*)nullptr : $nc(res)->getMostSpecific();
}

$PublicMethods$MethodList* Class::getMethodsRecursive($String* name, $ClassArray* parameterTypes, bool includeStatic) {
	$useLocalCurrentObjectStackCache();
	$var($MethodArray, methods, privateGetDeclaredMethods(true));
	$var($PublicMethods$MethodList, res, $PublicMethods$MethodList::filter(methods, name, parameterTypes, includeStatic));
	if (res != nullptr) {
		return res;
	}
	Class* sc = getSuperclass();
	if (sc != nullptr) {
		$assign(res, sc->getMethodsRecursive(name, parameterTypes, includeStatic));
	}
	{
		$var($ClassArray, arr$, getInterfaces(false));
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			Class* intf = arr$->get(i$);
			{
				$assign(res, $PublicMethods$MethodList::merge(res, $($nc(intf)->getMethodsRecursive(name, parameterTypes, false))));
			}
		}
	}
	return res;
}

$Constructor* Class::getConstructor0($ClassArray* parameterTypes, int32_t which) {
	$useLocalCurrentObjectStackCache();
	$var($ReflectionFactory, fact, getReflectionFactory());
	$var($ConstructorArray, constructors, privateGetDeclaredConstructors((which == $Member::PUBLIC)));
	{
		$var($ConstructorArray, arr$, constructors);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Constructor, constructor, arr$->get(i$));
			{
				if (arrayContentsEq(parameterTypes, $(fact->getExecutableSharedParameterTypes(constructor)))) {
					return constructor;
				}
			}
		}
	}
	$throwNew($NoSuchMethodException, $(methodToString("<init>"_s, parameterTypes)));
}

bool Class::arrayContentsEq($ObjectArray* a1, $ObjectArray* a2) {
	if (a1 == nullptr) {
		return a2 == nullptr || $nc(a2)->length == 0;
	}
	if (a2 == nullptr) {
		return $nc(a1)->length == 0;
	}
	if ($nc(a1)->length != $nc(a2)->length) {
		return false;
	}
	for (int32_t i = 0; i < $nc(a1)->length; ++i) {
		if (!$equals(a1->get(i), $nc(a2)->get(i))) {
			return false;
		}
	}
	return true;
}

$FieldArray* Class::copyFields($FieldArray* arg) {
	$useLocalCurrentObjectStackCache();
	$var($FieldArray, out, $new($FieldArray, $nc(arg)->length));
	$var($ReflectionFactory, fact, getReflectionFactory());
	for (int32_t i = 0; i < arg->length; ++i) {
		out->set(i, $(fact->copyField(arg->get(i))));
	}
	return out;
}

$MethodArray* Class::copyMethods($MethodArray* arg) {
	$useLocalCurrentObjectStackCache();
	$var($MethodArray, out, $new($MethodArray, $nc(arg)->length));
	$var($ReflectionFactory, fact, getReflectionFactory());
	for (int32_t i = 0; i < arg->length; ++i) {
		out->set(i, $(fact->copyMethod(arg->get(i))));
	}
	return out;
}

$ConstructorArray* Class::copyConstructors($ConstructorArray* arg) {
	$useLocalCurrentObjectStackCache();
	$var($ConstructorArray, out, $cast($ConstructorArray, $nc(arg)->clone()));
	$var($ReflectionFactory, fact, getReflectionFactory());
	for (int32_t i = 0; i < out->length; ++i) {
		out->set(i, $(fact->copyConstructor(out->get(i))));
	}
	return out;
}

$FieldArray* Class::getDeclaredFields0(bool publicOnly) {
	if (!metaInited) {
		initMeta();
	}
	$synchronized(this) {
		$var($FieldArray, declaredFields, nullptr);
		if (classInfo != nullptr && classInfo->fields != nullptr) {
			FieldInfo* fieldInfo = classInfo->fields;
			int32_t count = 0;
			for (; true; fieldInfo++) {
				if (fieldInfo->name == nullptr) {
					break;
				}
				count++;
			}
			fieldInfo = classInfo->fields;
			$assign(declaredFields, $new($FieldArray, count));
			int32_t index = 0;
			ensureConstantPoolInitialized();
			for (; true; fieldInfo++) {
				if (fieldInfo->name == nullptr) {
					break;
				}
				$var($Field, field, $new($Field,
					this,
					$cstr(fieldInfo->name),
					forDescriptor(fieldInfo->descriptor),
					fieldInfo->modifiers,
					false, // trustedFinal
					index, // slot,
					fieldInfo->signature != nullptr ? $cstr(fieldInfo->signature) : nullptr,
					fieldInfo->rawAnnotations));
				$set(field, typeAnnotation, fieldInfo->rawTypeAnnotations);
				field->setOffsetof(fieldInfo->offset);
				declaredFields->set(index, field);
				index++;
			}
		}

		if (declaredFields != nullptr) {
			if (publicOnly) {
				int32_t publicCount = 0;
				for (int32_t i = 0; i < declaredFields->length; i++) {
					$Field* field = $fcast($Field, declaredFields->get(i));
					if ($Modifier::isPublic(field->getModifiers())) {
						publicCount++;
					}
				}
				$var($FieldArray, publicFields, $new($FieldArray, publicCount));
				publicCount = 0;
				for (int32_t i = 0; i < declaredFields->length; i++) {
					$Field* field = $fcast($Field, declaredFields->get(i));
					if ($Modifier::isPublic(field->getModifiers())) {
						publicFields->set(publicCount, field);
						publicCount++;
					}
				}
				return publicFields;
			} else {
				return declaredFields;
			}
		}
	}
	return $new($FieldArray, 0);
}

$MethodArray* Class::getDeclaredMethods0(bool publicOnly) {
	return getDeclaredMethods(publicOnly, false);
}

$ConstructorArray* Class::getDeclaredConstructors0(bool publicOnly) {
	$var($ConstructorArray, constructors, nullptr);
	if (classInfo != nullptr && classInfo->methods != nullptr) {
		ensureConstantPoolInitialized();
		MethodInfo* methodInfo = classInfo->methods;
		int32_t count = 0;
		for (; true; methodInfo++) {
			if (methodInfo->name == nullptr) {
				break;
			}
			if (publicOnly) {
				if (!$Modifier::isPublic(methodInfo->modifiers)) {
					continue;
				}
			}
			if ("<init>"_s->equals(methodInfo->name)) {
				count++;
			}
		}
		$assign(constructors, $new($ConstructorArray, count));
		int32_t constructorIndex = 0;
		methodInfo = classInfo->methods;
		for (; true; methodInfo++) {
			if (methodInfo->name == nullptr) {
				break;
			}
			if (publicOnly) {
				if (!$Modifier::isPublic(methodInfo->modifiers)) {
					continue;
				}
			}
			if (!"<init>"_s->equals(methodInfo->name)) {
				continue;
			}
			$var($StringArray, sa, parseMethodDescriptor($cstr(methodInfo->descriptor)));
			$var($ClassArray, parameterTypes, $new($ClassArray, sa->length - 1));
			for (int32_t i = 0; i < sa->length - 1; i++) {
				parameterTypes->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
			}

			$var($ClassArray, checkedExceptions, nullptr);
			if (methodInfo->exceptions != nullptr) {
				$var($StringArray, sa, Util::split(methodInfo->exceptions, ','));
				$assign(checkedExceptions, $new($ClassArray, sa->length));
				for (int32_t i = 0; i < checkedExceptions->length; i++) {
					checkedExceptions->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
				}
			} else {
				$assign(checkedExceptions, $new($ClassArray, 0));
			}

			$var($Constructor, constructor, $new($Constructor,
				this,
				parameterTypes,
				checkedExceptions,
				methodInfo->modifiers,
				methodInfo->slot,
				methodInfo->signature != nullptr ? $cstr(methodInfo->signature) : nullptr,
				methodInfo->rawAnnotations,
				methodInfo->rawParameterAnnotations));
			$set(constructor, typeAnnotation, methodInfo->rawTypeAnnotations);
			constructor->invokeAddress = methodInfo->invokeAddress;
			constructors->set(constructorIndex, constructor);
			constructorIndex++;
		}
	}

	if (constructors != nullptr) {
		return constructors;
	}
	return $new($ConstructorArray, 0);
}

$ClassArray* Class::getDeclaredClasses0() {
	$var($ClassArray, declaredClasses, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(declaredClasses, rd->declaredClasses);
		if (declaredClasses != nullptr) {
			return declaredClasses;
		}
	}
	$synchronized(this) {
		if (classInfo != nullptr && classInfo->innerClasses !=nullptr) {
			$var(String, thisClassName, this->getName());
			int32_t declaredClassesCount = 0;
			InnerClassInfo* innerClassInfo = classInfo->innerClasses;
			for (; true; innerClassInfo++) {
				if (innerClassInfo->innerClass == nullptr) {
					break;
				}
				if (innerClassInfo->outerClass == nullptr) {
					continue;
				}
				$var(String, outerClass, $cstr(innerClassInfo->outerClass)->replace(u'/', u'.'));
				if ($Objects::equals(thisClassName, outerClass)) {
					declaredClassesCount++;
				}
			}
			$assign(declaredClasses, $new($ClassArray, declaredClassesCount));
			int32_t declaredClassesIndex = 0;
			innerClassInfo = classInfo->innerClasses;
			for (; true; innerClassInfo++) {
				if (innerClassInfo->innerClass == nullptr) {
					break;
				}
				if (innerClassInfo->outerClass == nullptr) {
					continue;
				}
				$var(String, outerClass, $cstr(innerClassInfo->outerClass)->replace(u'/', u'.'));
				if ($Objects::equals(thisClassName, outerClass)) {
					declaredClasses->set(declaredClassesIndex, forName(innerClassInfo->innerClass));
					declaredClassesIndex++;
				}
			}
		} else {
			$assign(declaredClasses, $new($ClassArray, 0));
		}
		if (rd != nullptr) {
			$set(rd, declaredClasses, declaredClasses);
		}
	}
	return declaredClasses;
}

$RecordComponentArray* Class::getRecordComponents0() {
	return $new($RecordComponentArray, 0);
}

bool Class::isRecord0() {
	return false;
}

$String* Class::methodToString($String* name, $ClassArray* argTypes) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$(getName()), $$str(u'.'), name}));
	return $concat(var$0, ((argTypes == nullptr || $nc(argTypes)->length == 0) ? "()"_s : $cast($String, $($nc($($nc($($Arrays::stream(argTypes)))->map(static_cast<$Function*>($$new(Class$$Lambda$lambda$methodToString$0$3)))))->collect($($Collectors::joining(","_s, "("_s, ")"_s)))))));
}

bool Class::desiredAssertionStatus() {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, loader, getClassLoader0());
	if (loader == nullptr) {
		return desiredAssertionStatus0(this);
	}
	$synchronized($nc(loader)->assertionLock) {
		if (loader->classAssertionStatus != nullptr) {
			return loader->desiredAssertionStatus($(getName()));
		}
	}
	return desiredAssertionStatus0(this);
}

bool Class::desiredAssertionStatus0(Class* clazz) {
	return false;
}

bool Class::isEnum() {
	bool var$0 = ((int32_t)(this->getModifiers() & (uint32_t)Class::ENUM)) != 0;
	$load($Enum);
	return var$0 && this->getSuperclass() == $Enum::class$;
}

bool Class::isRecord() {
	$load($Record);
	bool var$1 = getSuperclass() == $Record::class$;
	bool var$0 = var$1 && ((int32_t)(this->getModifiers() & (uint32_t)$Modifier::FINAL)) != 0;
	return var$0 && isRecord0();
}

$ReflectionFactory* Class::getReflectionFactory() {
	$beforeCallerSensitive();
	if (Class::reflectionFactory == nullptr) {
		$assignStatic(Class::reflectionFactory, $cast($ReflectionFactory, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ReflectionFactory$GetReflectionFactoryAction)))));
	}
	return Class::reflectionFactory;
}

$ObjectArray* Class::getEnumConstants() {
	$var($ObjectArray, values, getEnumConstantsShared());
	return (values != nullptr) ? $cast($ObjectArray, $nc(values)->clone()) : ($ObjectArray*)nullptr;
}

$ObjectArray* Class::getEnumConstantsShared() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ObjectArray, constants, this->enumConstants);
	if (constants == nullptr) {
		if (!isEnum()) {
			return nullptr;
		}
		try {
			$var($Method, values, getMethod("values"_s, $$new($ClassArray, 0)));
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Class$3, this, values)));
			$var($ObjectArray, temporaryConstants, $cast($ObjectArray, $nc(values)->invoke(nullptr, $$new($ObjectArray, 0))));
			$set(this, enumConstants, ($assign(constants, temporaryConstants)));
		} catch ($InvocationTargetException& ex) {
			return nullptr;
		} catch ($NoSuchMethodException& ex) {
			return nullptr;
		} catch ($IllegalAccessException& ex) {
			return nullptr;
		}
	}
	return constants;
}

$Map* Class::enumConstantDirectory() {
	$useLocalCurrentObjectStackCache();
	$var($Map, directory, this->enumConstantDirectory$);
	if (directory == nullptr) {
		$var($ObjectArray, universe, getEnumConstantsShared());
		if (universe == nullptr) {
			$throwNew($IllegalArgumentException, $$str({$(getName()), " is not an enum class"_s}));
		}
		$assign(directory, $new($HashMap, $cast(int32_t, ($nc(universe)->length / 0.75f)) + 1));
		{
			$var($ObjectArray, arr$, universe);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, constant, arr$->get(i$));
				{
					directory->put($($nc(($cast($Enum, constant)))->name()), constant);
				}
			}
		}
		$set(this, enumConstantDirectory$, directory);
	}
	return directory;
}

$Object* Class::cast(Object$* obj) {
	if (obj == nullptr) {
		return nullptr;
	}
	Object0* obj0 = $toObject0(obj);
	Class* clazz = obj0->getClass();
	if (clazz == this) {
		return obj0;
	}
	return cast0(this, clazz, obj0);
}

$String* Class::cannotCastMsg(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({"Cannot cast "_s, $($nc($of(obj))->getClass()->getName()), " to "_s}));
	return $concat(var$0, $(getName()));
}

Class* Class::asSubclass(Class* clazz) {
	if ($nc(clazz)->isAssignableFrom(this)) {
		return this;
	} else {
		$throwNew($ClassCastException, $(this->toString()));
	}
}

$Annotation* Class::getAnnotation(Class* annotationClass) {
	$Objects::requireNonNull(annotationClass);
	return $cast($Annotation, $nc($nc($(annotationData()))->annotations)->get(annotationClass));
}

bool Class::isAnnotationPresent(Class* annotationClass) {
	return $GenericDeclaration::isAnnotationPresent(annotationClass);
}

$AnnotationArray* Class::getAnnotationsByType(Class* annotationClass) {
	$Objects::requireNonNull(annotationClass);
	$var($Class$AnnotationData, annotationData, this->annotationData());
	return $AnnotationSupport::getAssociatedAnnotations($nc(annotationData)->declaredAnnotations, this, annotationClass);
}

$AnnotationArray* Class::getAnnotations() {
	return $AnnotationParser::toArray($nc($(annotationData()))->annotations);
}

$Annotation* Class::getDeclaredAnnotation(Class* annotationClass) {
	$Objects::requireNonNull(annotationClass);
	return $cast($Annotation, $nc($nc($(annotationData()))->declaredAnnotations)->get(annotationClass));
}

$AnnotationArray* Class::getDeclaredAnnotationsByType(Class* annotationClass) {
	$Objects::requireNonNull(annotationClass);
	return $AnnotationSupport::getDirectlyAndIndirectlyPresent($nc($(annotationData()))->declaredAnnotations, annotationClass);
}

$AnnotationArray* Class::getDeclaredAnnotations() {
	return $AnnotationParser::toArray($nc($(annotationData()))->declaredAnnotations);
}

$Class$AnnotationData* Class::annotationData() {
	$useLocalCurrentObjectStackCache();
	while (true) {
		$var($Class$AnnotationData, annotationData, this->annotationData$);
		int32_t classRedefinedCount = this->classRedefinedCount;
		if (annotationData != nullptr && annotationData->redefinedCount == classRedefinedCount) {
			return annotationData;
		}
		$var($Class$AnnotationData, newAnnotationData, createAnnotationData(classRedefinedCount));
		if ($Class$Atomic::casAnnotationData(this, annotationData, newAnnotationData)) {
			return newAnnotationData;
		}
	}
}

$Class$AnnotationData* Class::createAnnotationData(int32_t classRedefinedCount) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, getRawAnnotations());
	$var($Map, declaredAnnotations, $AnnotationParser::parseAnnotations(var$0, $(getConstantPool()), this));
	Class* superClass = getSuperclass();
	$var($Map, annotations, nullptr);
	if (superClass != nullptr) {
		$var($Map, superAnnotations, $nc($(superClass->annotationData()))->annotations);
		{
			$var($Iterator, i$, $nc($($nc(superAnnotations)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					Class* annotationClass = $cast(Class, $nc(e)->getKey());
					if ($nc($($AnnotationType::getInstance(annotationClass)))->isInherited()) {
						if (annotations == nullptr) {
							int32_t var$1 = $nc(declaredAnnotations)->size();
							int32_t var$2 = declaredAnnotations->size();
							$assign(annotations, $new($LinkedHashMap, ($Math::max(var$1, $Math::min(12, var$2 + superAnnotations->size())) * 4 + 2) / 3));
						}
						$nc(annotations)->put(annotationClass, $cast($Annotation, $(e->getValue())));
					}
				}
			}
		}
	}
	if (annotations == nullptr) {
		$assign(annotations, declaredAnnotations);
	} else {
		$nc(annotations)->putAll(declaredAnnotations);
	}
	return $new($Class$AnnotationData, annotations, declaredAnnotations, classRedefinedCount);
}

bool Class::casAnnotationType($AnnotationType* oldType, $AnnotationType* newType) {
	return $Class$Atomic::casAnnotationType(this, oldType, newType);
}

$AnnotationType* Class::getAnnotationType() {
	return this->annotationType;
}

$Map* Class::getDeclaredAnnotationMap() {
	return $nc($(annotationData()))->declaredAnnotations;
}

$AnnotatedType* Class::getAnnotatedSuperclass() {
	$useLocalCurrentObjectStackCache();
	bool var$1 = this == $Object::class$ || isInterface();
	bool var$0 = var$1 || isArray();
	$init($Void);
	if (var$0 || isPrimitive() || this == $Void::TYPE) {
		return nullptr;
	}
	$var($bytes, var$2, getRawTypeAnnotations());
	return $TypeAnnotationParser::buildAnnotatedSuperclass(var$2, $(getConstantPool()), this);
}

$AnnotatedTypeArray* Class::getAnnotatedInterfaces() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, getRawTypeAnnotations());
	return $TypeAnnotationParser::buildAnnotatedInterfaces(var$0, $(getConstantPool()), this);
}

Class* Class::getNestHost0() {
	if (nestHost != nullptr) {
		return nestHost;
	}
	if (this->classInfo != nullptr && classInfo->nestHost != nullptr) {
		$synchronized(this) {
			if (nestHost == nullptr) {
				$set(this, nestHost, forName0($cstr(classInfo->nestHost), false, this->classLoader, nullptr));
			}
		}
	} else {
		$synchronized(this) {
			if (nestHost == nullptr) {
				$set(this, nestHost, this);
			}
		}
	}
	return nestHost;
}

Class* Class::getNestHost() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = isPrimitive();
	if (var$0 || isArray()) {
		return this;
	}
	Class* host = getNestHost0();
	if (host == this) {
		return this;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		checkPackageAccess(sm, $($ClassLoader::getClassLoader($Reflection::getCallerClass())), true);
	}
	return host;
}

bool Class::isNestmateOf(Class* c) {
	$beforeCallerSensitive();
	if (this == c) {
		return true;
	}
	bool var$2 = isPrimitive();
	bool var$1 = var$2 || isArray();
	bool var$0 = var$1 || $nc(c)->isPrimitive();
	if (var$0 || $nc(c)->isArray()) {
		return false;
	}
	return getNestHost() == $nc(c)->getNestHost();
}

$ClassArray* Class::getNestMembers0() {
	$var($ClassArray, nestMembers, nullptr);
	$var($Class$ReflectionData, rd, reflectionData());
	if (rd != nullptr) {
		$assign(nestMembers, rd->nestMembers);
		if (nestMembers != nullptr) {
			return nestMembers;
		}
	}
	$synchronized(this) {
		if (classInfo != nullptr && classInfo->nestMembers != nullptr) {
			$var($StringArray, sa, Util::split(classInfo->nestMembers, ','));
			$assign(nestMembers, $new($ClassArray, sa->length));
			for (int32_t i = 0; i < nestMembers->length; i++) {
				nestMembers->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
			}
		} else {
			$assign(nestMembers, $new($ClassArray, 0));
		}
		if (rd != nullptr) {
			$set(rd, nestMembers, nestMembers);
		}
	}
	return nestMembers;
}

$ClassArray* Class::getNestMembers() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = isPrimitive();
	if (var$0 || isArray()) {
		return $new($ClassArray, {this});
	}
	$var($ClassArray, members, getNestMembers0());
	if (members->length > 1) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			checkPackageAccess(sm, $($ClassLoader::getClassLoader($Reflection::getCallerClass())), true);
		}
	}
	return members;
}

$String* Class::descriptorString() {
	$useLocalCurrentObjectStackCache();
	if (isPrimitive()) {
		return $nc($($Wrapper::forPrimitiveType(this)))->basicTypeString();
	}
	if (isArray()) {
		return $str({"["_s, $($nc(this->componentType$)->descriptorString())});
	} else if (isHidden()) {
		$var($String, name, getName());
		int32_t index = $nc(name)->indexOf((int32_t)u'/');
		return $$new($StringBuilder, name->length() + 2)->append(u'L')->append($($(name->substring(0, index))->replace(u'.', u'/')))->append(u'.')->append(static_cast<$CharSequence*>(name), index + 1, name->length())->append(u';')->toString();
	} else {
		$var($String, name, $nc($(getName()))->replace(u'.', u'/'));
		return $$new($StringBuilder, name->length() + 2)->append(u'L')->append(name)->append(u';')->toString();
	}
}

$TypeDescriptor$OfField* Class::componentType() {
	return (isArray() ? this->componentType$ : (Class*)nullptr);
}

$TypeDescriptor$OfField* Class::arrayType() {
	return arrayType0();
}

$Optional* Class::describeConstable() {
	$useLocalCurrentObjectStackCache();
	Class* c = isArray() ? elementType() : this;
	return $nc(c)->isHidden() ? $Optional::empty() : $Optional::of($($ClassDesc::ofDescriptor($(descriptorString()))));
}

bool Class::isHidden() {
	return hidden;
}

$ClassArray* Class::getPermittedSubclasses() {
	$useLocalCurrentObjectStackCache();
	$var($ClassArray, subClasses, nullptr);
	bool var$1 = isArray();
	bool var$0 = var$1 || isPrimitive();
	if (var$0 || ($assign(subClasses, getPermittedSubclasses0())) == nullptr) {
		return nullptr;
	}
	if ($nc(subClasses)->length > 0) {
		if ($nc($($Arrays::stream(subClasses)))->anyMatch(static_cast<$Predicate*>($$new(Class$$Lambda$lambda$getPermittedSubclasses$1$4, this)))) {
			$assign(subClasses, $fcast($ClassArray, $nc($($nc($($Arrays::stream(subClasses)))->filter(static_cast<$Predicate*>($$new(Class$$Lambda$isDirectSubType$5, this)))))->toArray(static_cast<$IntFunction*>($$new(Class$$Lambda$lambda$getPermittedSubclasses$2$6)))));
		}
	}
	if ($nc(subClasses)->length > 0) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			checkPackageAccessForPermittedSubclasses(sm, $($ClassLoader::getClassLoader($Reflection::getCallerClass())), subClasses);
		}
	}
	return subClasses;
}

bool Class::isDirectSubType(Class* c) {
	if (isInterface()) {
		{
			$var($ClassArray, arr$, $nc(c)->getInterfaces(false));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				Class* i = arr$->get(i$);
				{
					if (i == this) {
						return true;
					}
				}
			}
		}
	} else {
		return $nc(c)->getSuperclass() == this;
	}
	return false;
}

bool Class::isSealed() {
	$beforeCallerSensitive();
	bool var$0 = isArray();
	if (var$0 || isPrimitive()) {
		return false;
	}
	return getPermittedSubclasses() != nullptr;
}

$ClassArray* Class::getPermittedSubclasses0() {
	return nullptr;
}

$ClassArray* Class::lambda$getPermittedSubclasses$2(int32_t s) {
	return $new($ClassArray, s);
}

bool Class::lambda$getPermittedSubclasses$1(Class* c) {
	return !isDirectSubType(c);
}

$String* Class::lambda$methodToString$0(Class* c) {
	return c == nullptr ? "null"_s : $nc(c)->getName();
}

void clinit$Class(Class* class$) {
	{
		Class::registerNatives();
	}
	$assignStatic(Class::EMPTY_CLASS_ARRAY, $new($ClassArray, 0));
	$assignStatic(Class::serialPersistentFields, $new($ObjectStreamFieldArray, 0));
}

Class::Class() {
}

void Class::setPrimitive(bool primitive) {
	this->primitive = primitive;
}

void Class::setArrayIndexScale(int32_t arrayIndexScale) {
	this->arrayIndexScale = arrayIndexScale;
	int32_t shift = 0;
	while ((1 << shift) < arrayIndexScale) {
		shift++;
	}
	this->arrayIndexScaleShift = shift;
}

void Class::setSuperClass(Class* superClass) {
	$set(this, superClass, superClass);
}

void Class::setComponentType(Class* componentType) {
	$set(this, componentType$, componentType);
}

int32_t Class::getSize() {
	if (size == 0) {
		initMeta();
	}
	return size;
}

void Class::initialize() {
	if (state != CLASS_STATE_INITIALIZED) {
		$synchronized(this) {
			if (state != CLASS_STATE_INITIALIZING && state != CLASS_STATE_INITIALIZED) {
				state = CLASS_STATE_INITIALIZING;
				// array type need not to initialize base class(Object)
				if (!isArray()) {
					ensureBaseClassInitialized(this);
					initMeta();
				}
				if (initClassFunction != nullptr) {
					initClassFunction(this);
				}
				state = CLASS_STATE_INITIALIZED;
			}
		}
	}
}

bool isObjectField(const char* descriptor) {
	return descriptor[1] != '\0';
}

int32_t sizeofField(const char* descriptor) {
	if (isObjectField(descriptor)) {
		return $SIZEOF_VOID_P;
	}
	switch (descriptor[0]) {
		case 'Z':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'S':
			return 2;
		case 'I':
			return 4;
		case 'J':
			return 8;
		case 'F':
			return 4;
		case 'D':
			return 8;
	}
	return 0;
}

int32_t Class::calcBaseSize() {
	Machine::ensureInitialized(this);
	int32_t baseSize = 0;
	if (this->isPrimitive()) {
		$init(Boolean);
		if (this == Boolean::TYPE) {
			baseSize = 1;
		}
		$init(Byte);
		if (this == Byte::TYPE) {
			baseSize = 1;
		}
		$init(Short);
		if (this == Short::TYPE) {
			baseSize = 2;
		}
		$init(Integer);
		if (this == Integer::TYPE) {
			baseSize = 4;
		}
		$init(Long);
		if (this == Long::TYPE) {
			baseSize = 8;
		}
		$init(Character);
		if (this == Character::TYPE) {
			baseSize = 2;
		}
		$init(Float);
		if (this == Float::TYPE) {
			baseSize = 4;
		}
		$init(Double);
		if (this == Double::TYPE) {
			baseSize = 8;
		}
		return baseSize;
	}
	if (this == Object::class$) {
		baseSize = sizeof(Object); // TODO
		return baseSize;
	}

	$var($ClassArray, interfaces, this->getInterfaces(false));

	if (this->isInterface()) {
		if (interfaces->length == 0) {
			baseSize = Object::class$->getSize(); // virtual function table pointer
		} else {
			baseSize = 0;
			for (int32_t i = 0; i < interfaces->length; i++) {
				Class* ifc = $fcast(Class, interfaces->get(i));
				int32_t interfaceSize = ifc->getSize();
				baseSize = calcClassSize$(baseSize, interfaceSize);
			}
		}
	} else {
		Class* superClass = this->getSuperclass();
		if (superClass == Object::class$) {
			if (interfaces->length == 0) {
				baseSize = Object::class$->getSize();
			} else {
				baseSize = 0;
				for (int32_t i = 0; i < interfaces->length; i++) {
					Class* ifc = $fcast(Class, interfaces->get(i));
					int32_t interfaceSize = ifc->getSize();
					baseSize = calcClassSize$(baseSize, interfaceSize);
				}
			}
		} else {
#ifdef _WIN32
			baseSize = superClass->getSize();
#else
			if (superClass->classInfo != nullptr && superClass->classInfo->fields != nullptr) {
				FieldInfo* fieldInfo = superClass->classInfo->fields;
				int32_t objectFieldOffsetsCount = 0;
				int32_t staticObjectFieldOffsetsCount = 0;
				FieldInfo* lastFieldInfo = nullptr;
				for (; true; fieldInfo++) {
					if (fieldInfo->name == nullptr) {
						break;
					}
					if (!$Modifier::isStatic(fieldInfo->modifiers)) {
						lastFieldInfo = fieldInfo;
					}
				}
				if (lastFieldInfo != nullptr) {
					int32_t fieldSize = sizeofField(lastFieldInfo->descriptor);
					baseSize = calcClassSize$(lastFieldInfo->offset, fieldSize);
				} else {
					baseSize = superClass->calcBaseSize();
				}
			}
#endif
			for (int32_t i = 0; i < interfaces->length; i++) {
				Class* ifc = $fcast(Class, interfaces->get(i));
				int32_t interfaceSize = ifc->getSize();
				baseSize = calcClassSize$(baseSize, interfaceSize);
			}
		}
	}
	return baseSize;
}

$StringArray* Class::parseMethodDescriptor(String* descriptor) {
	$var($ArrayList, list, $new($ArrayList));
	int32_t i = 0;
	int32_t dim = 0;
	for (; i < descriptor->length(); i++) {
		char16_t c = descriptor->charAt(i);
		if (c == u'(') {
			continue;
		}
		if (c == u')') {
			continue;
		}
		$var(String, prefix, "["_s->repeat(dim));
		switch (c) {
		case u'B':
			if (dim == 0) {
				list->add("byte"_s);
			} else {
				list->add($$concat(prefix, "B"_s));
				dim = 0;
			}
			break;
		case u'S':
			if (dim == 0) {
				list->add("short"_s);
			} else {
				list->add($$concat(prefix, "S"_s));
				dim = 0;
			}
			break;
		case u'I':
			if (dim == 0) {
				list->add("int"_s);
			} else {
				list->add($$concat(prefix, "I"_s));
				dim = 0;
			}
			break;
		case u'J':
			if (dim == 0) {
				list->add("long"_s);
			} else {
				list->add($$concat(prefix, "J"_s));
				dim = 0;
			}
			break;
		case u'C':
			if (dim == 0) {
				list->add("char"_s);
			} else {
				list->add($$concat(prefix, "C"_s));
				dim = 0;
			}
			break;
		case u'F':
			if (dim == 0) {
				list->add("float"_s);
			} else {
				list->add($$concat(prefix, "F"_s));
				dim = 0;
			}
			break;
		case u'D':
			if (dim == 0) {
				list->add("double"_s);
			} else {
				list->add($$concat(prefix, "D"_s));
				dim = 0;
			}
			break;
		case u'Z':
			if (dim == 0) {
				list->add("boolean"_s);
			} else {
				list->add($$concat(prefix, "Z"_s));
				dim = 0;
			}
			break;
		case u'V':
			list->add("void"_s);
			break;
		case u'L': {
			int32_t index = descriptor->indexOf(u';', i);
			if (index > 0) {
				if (dim == 0) {
					$var(String, objectType, descriptor->substring(i + 1, index));
					$assign(objectType, objectType->replace(u'/', u'.'));
					list->add(objectType);
				} else {
					$var(String, objectType, descriptor->substring(i, index + 1));
					$assign(objectType, objectType->replace(u'/', u'.'));
					list->add($$concat(prefix, objectType));
					dim = 0;
				}
				i = index;
			} else {
				// error handle todo
			}
		}
			break;
		case u'[':
			dim++;
			break;
		}
	}
	return $fcast($StringArray, list->toArray($$new($StringArray, 0)));
}

Class* Class::forName(const char* name) {
	return Machine::forName0($$str(name), false, this->classLoader, nullptr);
}

Class* Class::forDescriptor(const char* descriptor) {
	$var($StringArray, sa, parseMethodDescriptor($$str(descriptor)));
	String* name = $fcast(String, sa->get(0));
	return forName0(name, false, this->classLoader, nullptr);
}

$Field* Class::refField($String* name) {
	$nullcheck(name);
	if (classInfo != nullptr && classInfo->fields != nullptr) {
		FieldInfo* fieldInfo = classInfo->fields;
		int32_t index = 0;
		for (; true; fieldInfo++) {
			if (fieldInfo->name == nullptr) {
				break;
			}
			if (name->equals(fieldInfo->name)) {
				if (fieldInfo->ref != nullptr) {
					return fieldInfo->ref;
				}
				ensureConstantPoolInitialized();
				$synchronized(this) {
					if (fieldInfo->ref != nullptr) {
						return ($Field*)fieldInfo->ref;
					}
					$Field* field = $allocStatic<$Field>();
					field->init$(
						this,
						$cstr(fieldInfo->name),
						forDescriptor(fieldInfo->descriptor),
						fieldInfo->modifiers,
						false, // trustedFinal
						index, // slot,
						fieldInfo->signature != nullptr ? $cstr(fieldInfo->signature) : nullptr,
						fieldInfo->rawAnnotations);
					$set(field, typeAnnotation, fieldInfo->rawTypeAnnotations);
					field->setOffsetof(fieldInfo->offset);
					fieldInfo->ref = field;
					return field;
				}
			}
			index++;
		}
	}
	Class* superClass = getSuperclass();
	if (superClass != nullptr) {
		return superClass->refField(name);
	}
	return nullptr;
}

$Constructor* Class::refConstructor($String* descriptor) {
	$nullcheck(descriptor);
	if (classInfo != nullptr && classInfo->methods != nullptr) {
		String* name = "<init>"_s;
		ensureConstantPoolInitialized();
		MethodInfo* methodInfo = classInfo->methods;
		methodInfo = classInfo->methods;
		for (; true; methodInfo++) {
			const char* methodName = methodInfo->name;
			if (methodName == nullptr) {
				break;
			}
			if (name->equals(methodName) && descriptor->equals(methodInfo->descriptor)) {
				if (methodInfo->ref != nullptr) {
					return ($Constructor*)methodInfo->ref;
				}
				$var($StringArray, sa, parseMethodDescriptor(descriptor));
				$var($ClassArray, parameterTypes, $new($ClassArray, sa->length - 1));
				for (int32_t i = 0; i < sa->length - 1; i++) {
					parameterTypes->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
				}
				Class* returnType = forName0($fcast(String, sa->get(sa->length - 1)), false, this->classLoader, nullptr);

				$var($ClassArray, checkedExceptions, nullptr);
				if (methodInfo->exceptions != nullptr) {
					$var($StringArray, sa, Util::split(methodInfo->exceptions, ','));
					$assign(checkedExceptions, $new($ClassArray, sa->length));
					for (int32_t i = 0; i < checkedExceptions->length; i++) {
						checkedExceptions->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
					}
				} else {
					$assign(checkedExceptions, $new($ClassArray, 0));
				}

				$synchronized(this) {
					if (methodInfo->ref != nullptr) {
						return ($Constructor*)methodInfo->ref;
					}
					$Constructor* constructor = $allocStatic<$Constructor>();
					constructor->init$(
						this,
						parameterTypes,
						checkedExceptions,
						methodInfo->modifiers,
						methodInfo->slot,
						methodInfo->signature != nullptr ? $cstr(methodInfo->signature) : nullptr,
						methodInfo->rawAnnotations,
						methodInfo->rawParameterAnnotations);
					$set(constructor, typeAnnotation, methodInfo->rawTypeAnnotations);
					constructor->invokeAddress = methodInfo->invokeAddress;
					methodInfo->ref = constructor;
					return constructor;
				}
			}
		}
	}
	return nullptr;
}

$Method* Class::refMethod($String* name, $String* descriptor) {
	$nullcheck(name);
	$nullcheck(descriptor);
	if (classInfo != nullptr && classInfo->methods != nullptr) {
		ensureConstantPoolInitialized();
		MethodInfo* methodInfo = classInfo->methods;
		methodInfo = classInfo->methods;
		for (; true; methodInfo++) {
			const char* methodName = methodInfo->name;
			if (methodName == nullptr) {
				break;
			}
			if (name->equals(methodName) && descriptor->equals(methodInfo->descriptor)) {
				if (methodInfo->ref != nullptr) {
					return ($Method*)methodInfo->ref;
				}
				$var($StringArray, sa, parseMethodDescriptor(descriptor));
				$var($ClassArray, parameterTypes, $new($ClassArray, sa->length - 1));
				for (int32_t i = 0; i < sa->length - 1; i++) {
					parameterTypes->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
				}
				Class* returnType = forName0($fcast(String, sa->get(sa->length - 1)), false, this->classLoader, nullptr);

				$var($ClassArray, checkedExceptions, nullptr);
				if (methodInfo->exceptions != nullptr) {
					$var($StringArray, sa, Util::split(methodInfo->exceptions, ','));
					$assign(checkedExceptions, $new($ClassArray, sa->length));
					for (int32_t i = 0; i < checkedExceptions->length; i++) {
						checkedExceptions->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
					}
				} else {
					$assign(checkedExceptions, $new($ClassArray, 0));
				}

				$synchronized(this) {
					if (methodInfo->ref != nullptr) {
						return ($Method*)methodInfo->ref;
					}
					$Method* method = $allocStatic<$Method>();
					method->init$(
						this,
						$cstr(methodName),
						parameterTypes,
						returnType,
						checkedExceptions,
						methodInfo->modifiers,
						methodInfo->slot,
						methodInfo->signature != nullptr ? $cstr(methodInfo->signature) : nullptr,
						methodInfo->rawAnnotations,
						methodInfo->rawParameterAnnotations,
						methodInfo->rawDefaultValue);
					$set(method, typeAnnotation, methodInfo->rawTypeAnnotations);
					method->invokeAddress = methodInfo->invokeAddress;
					methodInfo->ref = method;
					return method;
				}
			}
		}
	}
	$var($ClassArray, interfaces, getInterfaces(false));
	for (int32_t i = 0; i < interfaces->length; ++i) {
		Class* c = (Class*)interfaces->get(i);
		$Method* method = $nc(c)->refMethod(name, descriptor);
		if (method != nullptr) {
			return method;
		}
	}
	if (!isInterface()) {
		Class* c = getSuperclass();
		if (c != nullptr) {
			$Method* method = c->refMethod(name, descriptor);
			if (method != nullptr) {
				return method;
			}
		}
	}
	return nullptr;
}

$Method* Class::getMethodEx(String* name, $ClassArray* parameterTypes) {
	return getMethodsRecursiveEx(name, parameterTypes == nullptr ? Class::EMPTY_CLASS_ARRAY : parameterTypes, true);
}

$Method* Class::getMethodsRecursiveEx(String* name, $ClassArray* parameterTypes, bool includeStatic) {
	$var($MethodArray, methods, privateGetDeclaredMethods(false));
	$var($MethodArray, arr$, methods);
	int32_t parameterTypesLen = parameterTypes->length;
	int32_t len$ = arr$->length;
	int32_t i$ = 0;
	for (; i$ < len$; ++i$) {
		$Method* method = $fcast($Method, arr$->get(i$));
		{
			if ((includeStatic || !$Modifier::isStatic(method->getModifiers())) && method->name->equals(name)) {
				bool match = true;
				if (method->isVarArgs()) {
					if (parameterTypesLen < method->parameterTypes->length - 1) {
						continue;
					}
					int32_t j = 0;
					for (; j < method->parameterTypes->length - 1; j++) {
						Class* class1 = (Class*)parameterTypes->get(j);
						Class* class2 = (Class*)method->parameterTypes->get(j);
						if (class2 != Object::class$ && !class2->isAssignableFrom(class1)) {
							match = false;
							break;
						}
					}
					Class* class2 = (Class*)method->parameterTypes->get(j);
					class2 = class2->componentType$;
					if (class2 == nullptr) {
						match = false;
						break;
					}
					if (j + 1 == parameterTypes->length) {
						Class* class1 = (Class*)parameterTypes->get(j);
						if (class1->isArray()) {
							class1 = class1->componentType$;
							if (class2 == Object::class$ || class2->isAssignableFrom(class1)) {
								return method;
							}
						}
					}
					for (; j < parameterTypes->length; j++) {
						Class* class1 = (Class*)parameterTypes->get(j);
						$nullcheck(class2);
						if (class2 != Object::class$ && !class2->isAssignableFrom(class1)) {
							match = false;
							break;
						}
					}
				} else if (method->parameterTypes->length == parameterTypesLen) {
					for (int32_t j = 0; j < parameterTypesLen; j++) {
						Class* class1 = (Class*)parameterTypes->get(j);
						Class* class2 = (Class*)method->parameterTypes->get(j);
						$nullcheck(class2);
						if (class2 != Object::class$ && !class2->isAssignableFrom(class1)) {
							match = false;
							break;
						}
					}
				} else {
					match = false;
				}
				if (match) {
					return method;
				}
			}
		}
	}
	$var($Method, res, nullptr);
	Class* superClass = getSuperclass();
	if (superClass != nullptr) {
		$assign(res, superClass->getMethodsRecursiveEx(name, parameterTypes, includeStatic));
	}
	if (res == nullptr) {
		$var($ClassArray, arr$, getInterfaces(false));
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			Class* intf = (Class*)arr$->get(i$);
			$assign(res, intf->getMethodsRecursiveEx(name, parameterTypes, false));
			if (res != nullptr) {
				break;
			}
		}
	}
	if (res == nullptr && this->isInterface()) {
		$assign(res, Object::class$->getMethodsRecursiveEx(name, parameterTypes, false));
	}
	return res;
}

$Method* Class::getMethodEx(String* name, String* descriptor) {
	$var($StringArray, sa, parseMethodDescriptor(descriptor));
	$var($ClassArray, parameterTypes, $new($ClassArray, sa->length - 1));
	for (int32_t i = 0; i < sa->length - 1; i++) {
		parameterTypes->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
	}
	return this->getMethodEx(name, parameterTypes);
}

$Constructor* Class::getDeclaredConstructor(String* descriptor) {
	$var($ConstructorArray, constructors, getDeclaredConstructors());
	int32_t len$ = constructors->length;
	int32_t i$ = 0;
	for (; i$ < len$; ++i$) {
		$Constructor* constructor = ($Constructor*)constructors->get(i$);
		if (descriptor->equals(constructor->getDescriptor())) {
			return constructor;
		}
	}
	return nullptr;
}

$Array<$Method>* Class::getDeclaredMethods(bool publicOnly, bool withStar) {
	$var($MethodArray, methods, nullptr);
	if (classInfo != nullptr && classInfo->methods != nullptr) {
		ensureConstantPoolInitialized();
		MethodInfo* methodInfo = classInfo->methods;
		int32_t count = 0;
		for (; true; methodInfo++) {
			const char* methodName = methodInfo->name;
			if (methodName == nullptr) {
				break;
			}
			
			if ("<init>"_s->equals(methodName)) {
				continue;
			}
			if (methodName[0] == '*') {
				if (withStar) {
					methodName++;
				} else {
					continue;
				}
			}
			if (publicOnly) {
				if (!$Modifier::isPublic(methodInfo->modifiers)) {
					continue;
				}
			}
			count++;
		}
		$assign(methods, $new($MethodArray, count));
		int32_t methodIndex = 0;
		methodInfo = classInfo->methods;
		for (; true; methodInfo++) {
			const char* methodName = methodInfo->name;
			if (methodName == nullptr) {
				break;
			}
			if ("<init>"_s->equals(methodName)) {
				continue;
			}
			if (methodName[0] == '*') {
				if (withStar) {
					methodName++;
				} else {
					continue;
				}
			}
			if (publicOnly) {
				if (!$Modifier::isPublic(methodInfo->modifiers)) {
					continue;
				}
			}
			$var($StringArray, sa, parseMethodDescriptor($cstr(methodInfo->descriptor)));
			$var($ClassArray, parameterTypes, $new($ClassArray, sa->length - 1));
			for (int32_t i = 0; i < sa->length - 1; i++) {
				parameterTypes->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
			}
			Class* returnType = forName0($fcast(String, sa->get(sa->length - 1)), false, this->classLoader, nullptr);

			$var($ClassArray, checkedExceptions, nullptr);
			if (methodInfo->exceptions != nullptr) {
				$var($StringArray, sa, Util::split(methodInfo->exceptions, ','));
				$assign(checkedExceptions, $new($ClassArray, sa->length));
				for (int32_t i = 0; i < checkedExceptions->length; i++) {
					checkedExceptions->set(i, forName0($fcast(String, sa->get(i)), false, this->classLoader, nullptr));
				}
			} else {
				$assign(checkedExceptions, $new($ClassArray, 0));
			}

			$var($Method, method, $new($Method,
				this,
				$cstr(methodName),
				parameterTypes,
				returnType,
				checkedExceptions,
				methodInfo->modifiers,
				methodInfo->slot,
				methodInfo->signature != nullptr ? $cstr(methodInfo->signature) : nullptr,
				methodInfo->rawAnnotations,
				methodInfo->rawParameterAnnotations,
				methodInfo->rawDefaultValue));
			$set(method, typeAnnotation, methodInfo->rawTypeAnnotations);
			method->invokeAddress = methodInfo->invokeAddress;
			methods->set(methodIndex, method);
			methodIndex++;
		}
	}

	if (methods != nullptr) {
		return methods;
	}
	return $new($MethodArray, 0);
}

void Class::ensureClassInitialized() {
	Machine::ensureInitialized(this);
}

$ConstantPool* Class::getConstantPool0() {
	if (classInfo != nullptr) {
		$var($ConstantPool, constantPool, $new($ConstantPool));
		classInfo->visit(constantPool);
		return constantPool;
	}
	return nullptr;
}

void Class::initMeta() {
	if (!metaInited) {
		$synchronized(this) {
			if (!metaInited) {
				Class* superClass = getSuperclass();
				if (superClass != nullptr) {
					superClass->initMeta();
				}
				$var($ClassArray, interfaces, getInterfaces(false));
				for (int32_t i = 0; i < interfaces->length; i++) {
					Class* interface0 = $fcast(Class, interfaces->get(i));
					interface0->initMeta();
				}

				// cale size and field offset
				bool sizeChanged = false;
				int32_t size0 = calcBaseSize();
				if (this->size < size0) {
					this->size = size0;
					sizeChanged = true;
				}
				if (classInfo != nullptr) {
					if (classInfo->fields != nullptr) {
						FieldInfo* fieldInfo = classInfo->fields;
						for (; true; fieldInfo++) {
							if (fieldInfo->name == nullptr) {
								break;
							}
							if (!$Modifier::isStatic(fieldInfo->modifiers)) {
								int32_t fieldSize = sizeofField(fieldInfo->descriptor);
								int32_t offset = calcFieldOffset$(size0, fieldSize);
								if (fieldInfo->offset == 0) {
									fieldInfo->offset = offset;
								}
								size0 = calcClassSize$(size0, fieldSize);
								if (this->size < size0) {
									this->size = size0;
									sizeChanged = true;
								}
							}
						}
						size0 = calcAlignedSize$(size0);
						if (this->size < size0) {
							this->size = size0;
							sizeChanged = true;
						}
					}
				}
				if (sizeChanged) {
					initObjectFieldOffset();
				}
				calcClassCastOffset();
				metaInited = true;
			}
		}
	}
}

bool Class::isCloneable() {
	return $hasFlag(mark, $CLONEABLE);
}

Object* Class::allocateInstance() {
	if (allocateInstanceFunction != nullptr) {
		return allocateInstanceFunction(this);
	}
	$shouldNotReachHere();
}

#define MAX_VAR_UNION_LENGTH 16

void Class::initInstance($Constructor* constructor, Object$* inst, $ObjectArray* args) {
	ensureClassInitialized();
	Object0* obj = $toObject0($nullcheck(inst));
	if (constructor->parameterTypes->length <= MAX_VAR_UNION_LENGTH) {
		$Value argv[MAX_VAR_UNION_LENGTH];
		if (constructor->isVarArgs()) {
			$var($Object, save, Util::prepareArgsWithVarArgs(constructor->parameterTypes, args, argv));
			if (initInstanceFunction != nullptr) {
				initInstanceFunction(constructor, obj, argv);
			} else {
				Platform::initInstance(constructor, obj, argv);
			}
		} else {
			Util::prepareArgs(constructor->parameterTypes, args, argv);
			if (initInstanceFunction != nullptr) {
				initInstanceFunction(constructor, obj, argv);
			} else {
				Platform::initInstance(constructor, obj, argv);
			}
		}
	} else {
		$var($bytes, data, $new($bytes, constructor->parameterTypes->length * sizeof($Value)));
		$Value* argv = ($Value*)data->begin();
		if (constructor->isVarArgs()) {
			$var($Object, save, Util::prepareArgsWithVarArgs(constructor->parameterTypes, args, argv));
			if (initInstanceFunction != nullptr) {
				initInstanceFunction(constructor, obj, argv);
			} else {
				Platform::initInstance(constructor, obj, argv);
			}
		} else {
			Util::prepareArgs(constructor->parameterTypes, args, argv);
			if (initInstanceFunction != nullptr) {
				initInstanceFunction(constructor, obj, argv);
			} else {
				Platform::initInstance(constructor, obj, argv);
			}
		}
	}
}

$Object* Class::invokeSpecial($Method* method, Object$* obj, $ObjectArray* args) {
	obj = this->cast($toObject0($nc(obj)));
	if (method->parameterTypes->length <= MAX_VAR_UNION_LENGTH) {
		$Value argv[MAX_VAR_UNION_LENGTH];
		if (method->isVarArgs()) {
			$var($Object, save, Util::prepareArgsWithVarArgs(method->parameterTypes, args, argv));
			if (invokeSpecialFunction != nullptr) {
				$Value ret = invokeSpecialFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invokeSpecial(method, obj, argv);
			}
		} else {
			Util::prepareArgs(method->parameterTypes, args, argv);
			if (invokeSpecialFunction != nullptr) {
				$Value ret = invokeSpecialFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invokeSpecial(method, obj, argv);
			}
		}
	} else {
		$var($bytes, data, $new($bytes, method->parameterTypes->length * sizeof($Value)));
		$Value* argv = ($Value*)data->begin();
		if (method->isVarArgs()) {
			$var($Object, save, Util::prepareArgsWithVarArgs(method->parameterTypes, args, argv));
			if (invokeSpecialFunction != nullptr) {
				$Value ret = invokeSpecialFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invokeSpecial(method, obj, argv);
			}
		} else {
			Util::prepareArgs(method->parameterTypes, args, argv);
			if (invokeSpecialFunction != nullptr) {
				$Value ret = invokeSpecialFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invokeSpecial(method, obj, argv);
			}
		}
	}
}

$Object* Class::invoke($Method* method, Object$* obj, $ObjectArray* args) {
	if (!method->isStatic()) {
		obj = this->cast($toObject0($nc(obj)));
	}
	if (method->parameterTypes->length <= MAX_VAR_UNION_LENGTH) {
		$Value argv[MAX_VAR_UNION_LENGTH];
		if (method->isVarArgs()) {
			$var($Object, save, Util::prepareArgsWithVarArgs(method->parameterTypes, args, argv));
			if (invokeFunction != nullptr) {
				$Value ret = invokeFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invoke(method, obj, argv);
			}
		} else {
			Util::prepareArgs(method->parameterTypes, args, argv);
			if (invokeFunction != nullptr) {
				$Value ret = invokeFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invoke(method, obj, argv);
			}
		}
	} else {
		$var($bytes, data, $new($bytes, method->parameterTypes->length * sizeof($Value)));
		$Value* argv = ($Value*)data->begin();
		if (method->isVarArgs()) {
			$var($Object, save, Util::prepareArgsWithVarArgs(method->parameterTypes, args, argv));
			if (invokeFunction != nullptr) {
				$Value ret = invokeFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invoke(method, obj, argv);
			}
		} else {
			Util::prepareArgs(method->parameterTypes, args, argv);
			if (invokeFunction != nullptr) {
				$Value ret = invokeFunction(method, obj, argv);
				return Util::toObject(method->returnType, ret);
			} else {
				return Platform::invoke(method, obj, argv);
			}
		}
	}
}

$Value Class::invokev($Method* method, Object$* obj, $Value* argv) {
	obj = this->cast($toObject0($nc(obj)));
	if (invokeFunction != nullptr) {
		return invokeFunction(method, obj, argv);
	}
	return Platform::invokev(false, method, obj, argv);
}

int32_t Class::calcCastOffset(Class* classTo, Object$* obj) {
	if (classCastOffsetArray == nullptr) {
		if (obj != nullptr) {
			$var(Object, saved, obj);
			calcClassCastOffset();
		} else {
			calcClassCastOffset();
		}
	}
	for (int32_t i = 0; i < classCastOffsetArrayLength; i++) {
		if (classCastOffsetArray[i].clazz == classTo) {
			return classCastOffsetArray[i].offset;
		}
	}
	return -1;
}

$Field* Class::findField(String* fieldName) {
	$var($Field, field, Class::searchFields($ref(($FieldArray*)privateGetDeclaredFields(false)), fieldName));
	if (field == nullptr) {
		$assign(field, Class::searchFields($ref(($FieldArray*)getDeclaredFields0(false)), fieldName));
	}
	if (field == nullptr) {
		$var($ClassArray, interfaces, getInterfaces(false));
		 int32_t len$ = interfaces->length;
		 int32_t i$ = 0;
		 for (; i$ < len$; ++i$) {
			 Class* c = $fcast(Class, interfaces->get(i$));
			 if (($assign(field, $nullcheck(c)->findField(fieldName))) != nullptr) {
				 return field;
			 }
		 }
		if (!isInterface()) {
			Class* superClass = getSuperclass();
			if (superClass != nullptr) {
				if (($assign(field, superClass->findField(fieldName))) != nullptr) {
					return field;
				}
			}
		}
	}
	return field;
}

Class* Class::getFieldTypeByOffset(int32_t offset) {
	if (classInfo != nullptr && classInfo->fields != nullptr) {
		FieldInfo* fieldInfo = classInfo->fields;
		for (; true; fieldInfo++) {
			if (fieldInfo->name == nullptr) {
				break;
			}
			if (fieldInfo->offset == offset) {
				if (fieldInfo->type != nullptr) {
					return fieldInfo->type;
				}
				$var(String, s, $str(fieldInfo->descriptor));
				if (s->startsWith("L")) {
					$assign(s, s->substring(1, s->length() - 1));
				}
				$assign(s, s->replace('/', '.'));
				Class* type = forName(s);
				$synchronized(this) {
					if (fieldInfo->type == nullptr) {
						fieldInfo->type = type;
					}
				}
				return fieldInfo->type;
			}
		}
	}
	Class* superClass = getSuperclass();
	if (superClass != nullptr) {
		return superClass->getFieldTypeByOffset(offset);
	}
	return nullptr;
}

void Class::initObjectFieldOffset() {
#ifdef $USE_COMPRESS_OBJECT_FIELD_OFFSET_FLAGS
	objectFieldOffsetFlags = 0;
#else
	if (objectFieldOffsetFlags != nullptr) {
		$freeRaw(objectFieldOffsetFlags);
		objectFieldOffsetFlags = nullptr;
	}
	if (objectFieldOffsetFlags == nullptr) {
		objectFieldOffsetFlags = $allocRaw<int8_t>(this->size / sizeof(void*));
		$memsetRaw(objectFieldOffsetFlags, 0);
	}
#endif
}

void Class::recordObjectFieldOffset(int32_t offset) {
	$synchronized(this) {
		recordObjectFieldOffset0(offset);
	}
}

void Class::recordObjectFieldOffset0(int32_t offset) {
	if (offset <= 0 || offset >= size) {
		return;
	}
	if (objectFieldOffsetArray == nullptr) {
		objectFieldOffsetArrayLength = size / sizeof(Object*) + 1;
		objectFieldOffsetArray = $allocRawStatic<int32_t>(objectFieldOffsetArrayLength);
		$memsetRaw(objectFieldOffsetArray, 0);
	}
	for (int32_t i = 0; i < objectFieldOffsetArrayLength; i++) {
		if (objectFieldOffsetArray[i] == offset) {
			return;
		} else if (objectFieldOffsetArray[i] == 0) {
			objectFieldOffsetArray[i] = offset;
			break;
		}
	}
	
#ifdef $USE_COMPRESS_OBJECT_FIELD_OFFSET_FLAGS
	int32_t index = offset / sizeof(void*);
	if (index < (sizeof(objectFieldOffsetFlags) * 8)) {
		objectFieldOffsetFlags |= (uint64_t)1 << index;
	}
#else
	int32_t index = offset / sizeof(void*);
	objectFieldOffsetFlags[index] = 1;
#endif
}

void saveClassCastOffset(Class* clazz, int32_t offset, ClassCastOffset*& classCastOffsetArray, int32_t& classCastOffsetArrayLength) {
	for (int32_t i = 0; i < classCastOffsetArrayLength; i++) {
		if (classCastOffsetArray[i].clazz == clazz) {
			return;
		}
	}
	int32_t newLength = classCastOffsetArrayLength + 1;
	ClassCastOffset* newArray = $allocRaw<ClassCastOffset>(newLength);
	$memsetRaw(newArray, 0);
	for (int32_t i = 0; i < classCastOffsetArrayLength; i++) {
		Class* clazz2 = classCastOffsetArray[i].clazz;
		int32_t offset2 = classCastOffsetArray[i].offset;
		if (offset < offset2) {
			newArray[i].clazz = clazz;
			newArray[i].offset = offset;
			clazz = clazz2;
			offset = offset2;
		} else {
			newArray[i].clazz = clazz2;
			newArray[i].offset = offset2;
		}
	}
	newArray[classCastOffsetArrayLength].clazz = clazz;
	newArray[classCastOffsetArrayLength].offset = offset;
	$freeRaw(classCastOffsetArray);
	classCastOffsetArray = newArray;
	classCastOffsetArrayLength = newLength;
}

void Class::calcClassCastOffset() {
	if (classCastOffsetArray == nullptr) {
		if (this->isPrimitive()) {
			return;
		}
		$synchronized(this) {
			if (classCastOffsetArray == nullptr) {
				ClassCastOffset* classCastOffsetArray0 = nullptr;
				int32_t classCastOffsetArrayLength0 = 0;
				saveClassCastOffset(this, 0, classCastOffsetArray0, classCastOffsetArrayLength0);
				int32_t classSize = 0;
				Class* superClass = this->getSuperclass();
				if (superClass != nullptr) {
					superClass->calcClassCastOffset();
					for (int32_t i = 0; i < superClass->classCastOffsetArrayLength; i++) {
						saveClassCastOffset(superClass->classCastOffsetArray[i].clazz, superClass->classCastOffsetArray[i].offset, classCastOffsetArray0, classCastOffsetArrayLength0);
					}
					if (superClass != Object::class$) {
						classSize = superClass->getSize();
					}
				} else if (this != Object::class$) {
					saveClassCastOffset(Object::class$, 0, classCastOffsetArray0, classCastOffsetArrayLength0);
				}
				$var($ObjectArray, interfaces, this->getInterfaces(false));
				for (int32_t i = 0; i < interfaces->length; i++) {
					Class* ifc = $fcast(Class, interfaces->get(i));
					ifc->calcClassCastOffset();
					for (int32_t i = 0; i < ifc->classCastOffsetArrayLength; i++) {
						saveClassCastOffset(ifc->classCastOffsetArray[i].clazz, ifc->classCastOffsetArray[i].offset + classSize, classCastOffsetArray0, classCastOffsetArrayLength0);
					}
					classSize = calcClassSize$(classSize, ifc->getSize());
				}
				classCastOffsetArray = classCastOffsetArray0;
				classCastOffsetArrayLength = classCastOffsetArrayLength0;
			}
		}
	}
}

void Class::ensureConstantPoolInitialized() {
	if (!constantPoolInited) {
		getConstantPool0();
		constantPoolInited = true;
	}
}

template<typename T>
inline $Object* cast0Impl(Class* to, Class* from, T* inst) {
	Object0* obj = $toObject0(inst);
	if (to->componentType$ != nullptr) {
		Class* srcType = from;
		Class* dstType = to;
		if (srcType != dstType && dstType != Object::class$) {
			for (int32_t i = 0; i < 255; i++) {
				if (dstType->componentType$ != nullptr) {
					if (srcType->componentType$ == nullptr) {
						$throwNew($ClassCastException, $(to->cannotCastMsg(obj)));
					}
					dstType = dstType->componentType$;
					srcType = srcType->componentType$;
				} else {
					break;
				}
			}
			if (srcType != dstType && dstType != Object::class$ && srcType->calcCastOffset(dstType, obj) < 0) {
				$throwNew($ClassCastException, $(to->cannotCastMsg(obj)));
			}
		}
		return obj;
	}
	int8_t* address = (int8_t*)(void*)obj;
	int32_t offset = from->calcCastOffset(to, obj);
	if (offset >= 0) {
		return (Object*)(void*)(address + offset);
	}
	$throwNew($ClassCastException, $(to->cannotCastMsg(obj)));
}

$Object* Class::cast0(Class* to, Class* from, Object0* inst) {
	return cast0Impl(to, from, inst);
}

$Object* Class::castOrNull(Object$* inst) {
	if (inst == nullptr) {
		return nullptr;
	}
	Object0* obj = $toObject0(inst);
	Class* objClass = obj->getClass();
	if (objClass == this) {
		return obj;
	}
	if (this->componentType$ != nullptr) {
		Class* srcType = objClass;
		Class* dstType = this;
		if (srcType != dstType && dstType != Object::class$) {
			for (int32_t i = 0; i < 255; i++) {
				if (dstType->componentType$ != nullptr) {
					if (srcType->componentType$ == nullptr) {
						return nullptr;
					}
					dstType = dstType->componentType$;
					srcType = srcType->componentType$;
				} else {
					break;
				}
			}
			if (srcType != dstType && dstType != Object::class$ && srcType->calcCastOffset(dstType, obj) < 0) {
				return nullptr;
			}
		}
		return obj;
	}
	int8_t* address = (int8_t*)(void*)obj;
	int32_t offset = objClass->calcCastOffset(this, obj);
	if (offset >= 0) {
		return (Object*)(void*)(address + offset);
	}
	return nullptr;
}

$ClassArray* Class::getPrimaryBaseClasses() {
	$var($ArrayList, vfptrClasses, $new($ArrayList));
	Class* superClass = this->getSuperclass();
	if (superClass != nullptr && superClass != Object::class$) {
		vfptrClasses->add(superClass);
		$var($ClassArray, vfptrClassesSuper, superClass->getPrimaryBaseClasses());
		for (int32_t vfptrClassesSuperIndex = 1; vfptrClassesSuperIndex < vfptrClassesSuper->length; vfptrClassesSuperIndex++) {
			Class* vfptrClass = (Class*)vfptrClassesSuper->get(vfptrClassesSuperIndex);
			vfptrClasses->add(vfptrClass);
		}
	}
	$var($ClassArray, interfaces, this->getInterfaces(false));

	for (int32_t i = 0; i < interfaces->length; i++) {
		Class* ifc = $fcast(Class, interfaces->get(i));
		vfptrClasses->add(ifc);
		$var($ClassArray, vfptrClassesIfc, ifc->getPrimaryBaseClasses());
		for (int32_t vfptrClassesIfcIndex = 1; vfptrClassesIfcIndex < vfptrClassesIfc->length; vfptrClassesIfcIndex++) {
			Class* vfptrClassIfc = $fcast(Class, vfptrClassesIfc->get(vfptrClassesIfcIndex));
			vfptrClasses->add(vfptrClassIfc);
		}
	}
	if (vfptrClasses->isEmpty()) {
		vfptrClasses->add(Object::class$);
	}
	return $fcast($ClassArray, vfptrClasses->toArray($$new($ClassArray, 0)));
}

int32_t Class::getBaseClassOffset(Class* baseClass) {
	if (baseClass == Object::class$) {
		return 0;
	}
	if (this == baseClass) {
		return 0;
	}
	int32_t offset = 0;

	Class* superClass = this->getSuperclass();
	if (superClass != nullptr) {
		offset = superClass->getBaseClassOffset(baseClass);
		if (offset >= 0) {
			return offset;
		}
		if (superClass == Object::class$) {
			offset = 0;
		} else {
			offset = superClass->getSize();
		}
	}

	$var($ClassArray, interfaces, this->getInterfaces(false));
	for (int32_t i = 0; i < interfaces->length; i++) {
		Class* ifc = $fcast(Class, interfaces->get(i));
		int32_t offsetIfc = ifc->getBaseClassOffset(baseClass);
		if (offsetIfc >= 0) {
			return offset + offsetIfc;
		}
		offset += ifc->getSize();
	}

	return -1;
}

void Class::loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction, $AllocateInstanceFunction allocateInstanceFunction, $InitInstanceFunction initInstanceFunction, $InvokeSpecialFunction invokeSpecialFunction, $InvokeFunction invokeFunction) {
	Machine::loadClass(name, initialize, pClass, size, mark, classInfo, initClassFunction, allocateInstanceFunction, initInstanceFunction, invokeSpecialFunction, invokeFunction);
}

void Class::loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction, $AllocateInstanceFunction allocateInstanceFunction) {
	Machine::loadClass(name, initialize, pClass, size, mark, classInfo, initClassFunction, allocateInstanceFunction, nullptr, nullptr, nullptr);
}

void Class::loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction) {
	Machine::loadClass(name, initialize, pClass, size, mark, classInfo, initClassFunction, nullptr, nullptr, nullptr, nullptr);
}

void Class::loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo, $AllocateInstanceFunction allocateInstanceFunction) {
	Machine::loadClass(name, initialize, pClass, size, mark, classInfo, nullptr, allocateInstanceFunction, nullptr, nullptr, nullptr);
}

void Class::loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark, ClassInfo* classInfo) {
	Machine::loadClass(name, initialize, pClass, size, mark, classInfo, nullptr, nullptr, nullptr, nullptr, nullptr);
}

void Class::loadClass(String* name, bool initialize, Class** pClass, int64_t size, int32_t mark) {
	Machine::loadClass(name, initialize, pClass, size, mark, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
}

void Class::registerClass(Class* clazz, const char* name) {
	$set(clazz, name, $cstr(name));
	Machine::registerClass(clazz);
}

void Class::registerClass(Class* clazz, const char* name, const char* simpleBinaryName) {
	$set(clazz, name, $cstr(name));
	$set(clazz, simpleBinaryName, $cstr(simpleBinaryName));
	Machine::registerClass(clazz);
}

void Class::ensureBaseClassInitialized(Class* clazz) {
	Class* superClass = clazz->getSuperclass();
	if (superClass != nullptr) {
		superClass->ensureClassInitialized();
	}
	$var($ClassArray, interfaces, clazz->getInterfaces(false));
	for (int32_t i = 0; i < interfaces->length; i++) {
		Class* interface0 = $fcast(Class, interfaces->get(i));
		interface0->ensureClassInitialized();
	}
}

bool Class::isAssignable(Class* to, Class* from, Object$* inst) {
	$nullcheck(to);
	$nullcheck(from);
	if (to == from) {
		return true;
	}
	// is array
	if (to->componentType$ != nullptr) {
		if (from->componentType$ != nullptr) {
			return isAssignable(to->componentType$, from->componentType$, inst);
		} else {
			return false;
		}
	}
	int32_t offset = from->calcCastOffset(to, inst);
	return offset >= 0;
}

Class* Class::arrayType0() {
	if (arrayType$ == nullptr) {
		$synchronized(this) {
			if (arrayType$ == nullptr) {
				$set(this, arrayType$, Machine::findArrayClass(this));
			}
		}
	}
	return arrayType$;
}

Class* Class::arrayType(int32_t dim) {
	Class* type = this;
	for (int32_t i = 0; i < dim; i++) {
		type = type->arrayType0();
	}
	return type;
}

int32_t Class::arrayDimension() {
	int32_t dim = 0;
	Class* clazz = this;
	while (clazz->componentType$ != nullptr) {
		dim++;
		clazz = clazz->componentType$;
	}
	return dim;
}

String* Class::bootstrapToString(Object$* inst) {
	if (bootstrapToStringMethodHandle == nullptr) {
		$synchronized(this) {
			$set(this, bootstrapToStringMethodHandle, Machine::makeBootstrapMethodHandle(this, "toString"_s));
		}
	}
	return $cast($String, bootstrapToStringMethodHandle->invoke($$new($ObjectArray, { inst })));
}

int32_t Class::bootstrapHashCode(Object$* inst) {
	if (bootstrapHashCodeMethodHandle == nullptr) {
		$synchronized(this) {
			$set(this, bootstrapHashCodeMethodHandle, Machine::makeBootstrapMethodHandle(this, "hashCode"_s));
		}
	}
	return $intValue(bootstrapHashCodeMethodHandle->invoke($$new($ObjectArray, { inst })));
}

bool Class::bootstrapEquals(Object$* inst, Object$* o) {
	if (bootstrapEqualsMethodHandle == nullptr) {
		$synchronized(this) {
			$set(this, bootstrapEqualsMethodHandle, Machine::makeBootstrapMethodHandle(this, "equals"_s));
		}
	}
	return $booleanValue(bootstrapEqualsMethodHandle->invoke($$new($ObjectArray, { inst, o })));
}

Class* Class::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Class$$Lambda$typeVarBounds::classInfo$.name)) {
			return Class$$Lambda$typeVarBounds::load$(name, initialize);
		}
		if (name->equals(Class$$Lambda$getTypeName$1::classInfo$.name)) {
			return Class$$Lambda$getTypeName$1::load$(name, initialize);
		}
		if (name->equals(Class$$Lambda$getClassLoader$2::classInfo$.name)) {
			return Class$$Lambda$getClassLoader$2::load$(name, initialize);
		}
		if (name->equals(Class$$Lambda$lambda$methodToString$0$3::classInfo$.name)) {
			return Class$$Lambda$lambda$methodToString$0$3::load$(name, initialize);
		}
		if (name->equals(Class$$Lambda$lambda$getPermittedSubclasses$1$4::classInfo$.name)) {
			return Class$$Lambda$lambda$getPermittedSubclasses$1$4::load$(name, initialize);
		}
		if (name->equals(Class$$Lambda$isDirectSubType$5::classInfo$.name)) {
			return Class$$Lambda$isDirectSubType$5::load$(name, initialize);
		}
		if (name->equals(Class$$Lambda$lambda$getPermittedSubclasses$2$6::classInfo$.name)) {
			return Class$$Lambda$lambda$getPermittedSubclasses$2$6::load$(name, initialize);
		}
	}
	$loadClass(Class, name, initialize, &_Class_ClassInfo_, clinit$Class, allocate$Class);
	return class$;
}

Class* Class::class$ = nullptr;

	} // lang
} // java