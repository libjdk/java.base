#include <java/io/ObjectStreamClass.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/Externalizable.h>
#include <java/io/IOException.h>
#include <java/io/InvalidClassException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamClass$1.h>
#include <java/io/ObjectStreamClass$2.h>
#include <java/io/ObjectStreamClass$3.h>
#include <java/io/ObjectStreamClass$4.h>
#include <java/io/ObjectStreamClass$5.h>
#include <java/io/ObjectStreamClass$Caches.h>
#include <java/io/ObjectStreamClass$ClassDataSlot.h>
#include <java/io/ObjectStreamClass$DeserializationConstructorsCache.h>
#include <java/io/ObjectStreamClass$EntryFuture.h>
#include <java/io/ObjectStreamClass$ExceptionInfo.h>
#include <java/io/ObjectStreamClass$FieldReflector.h>
#include <java/io/ObjectStreamClass$FieldReflectorKey.h>
#include <java/io/ObjectStreamClass$MemberSignature.h>
#include <java/io/ObjectStreamClass$WeakClassKey.h>
#include <java/io/ObjectStreamConstants.h>
#include <java/io/ObjectStreamException.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Enum.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationError.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/SoftReference.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/lang/reflect/RecordComponent.h>
#include <java/lang/reflect/UndeclaredThrowableException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaSecurityAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/reflect/ReflectionFactory$GetReflectionFactoryAction.h>
#include <jdk/internal/reflect/ReflectionFactory.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef ABSTRACT
#undef FINAL
#undef INTERFACE
#undef NATIVE
#undef NO_FIELDS
#undef PRIVATE
#undef PROTECTED
#undef PROTOCOL_VERSION_1
#undef PUBLIC
#undef SC_BLOCK_DATA
#undef SC_ENUM
#undef SC_EXTERNALIZABLE
#undef SC_SERIALIZABLE
#undef SC_WRITE_METHOD
#undef STATIC
#undef STRICT
#undef SYNCHRONIZED
#undef TRANSIENT
#undef VOLATILE

using $ObjectStreamClass$ClassDataSlotArray = $Array<::java::io::ObjectStreamClass$ClassDataSlot>;
using $ObjectStreamClass$MemberSignatureArray = $Array<::java::io::ObjectStreamClass$MemberSignature>;
using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $ConstructorArray = $Array<::java::lang::reflect::Constructor>;
using $FieldArray = $Array<::java::lang::reflect::Field>;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $Externalizable = ::java::io::Externalizable;
using $IOException = ::java::io::IOException;
using $InvalidClassException = ::java::io::InvalidClassException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectStreamClass$1 = ::java::io::ObjectStreamClass$1;
using $ObjectStreamClass$2 = ::java::io::ObjectStreamClass$2;
using $ObjectStreamClass$3 = ::java::io::ObjectStreamClass$3;
using $ObjectStreamClass$4 = ::java::io::ObjectStreamClass$4;
using $ObjectStreamClass$5 = ::java::io::ObjectStreamClass$5;
using $ObjectStreamClass$Caches = ::java::io::ObjectStreamClass$Caches;
using $ObjectStreamClass$ClassDataSlot = ::java::io::ObjectStreamClass$ClassDataSlot;
using $ObjectStreamClass$EntryFuture = ::java::io::ObjectStreamClass$EntryFuture;
using $ObjectStreamClass$ExceptionInfo = ::java::io::ObjectStreamClass$ExceptionInfo;
using $ObjectStreamClass$FieldReflector = ::java::io::ObjectStreamClass$FieldReflector;
using $ObjectStreamClass$FieldReflectorKey = ::java::io::ObjectStreamClass$FieldReflectorKey;
using $ObjectStreamClass$MemberSignature = ::java::io::ObjectStreamClass$MemberSignature;
using $ObjectStreamClass$WeakClassKey = ::java::io::ObjectStreamClass$WeakClassKey;
using $ObjectStreamConstants = ::java::io::ObjectStreamConstants;
using $ObjectStreamException = ::java::io::ObjectStreamException;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Enum = ::java::lang::Enum;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationError = ::java::lang::InstantiationError;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $SoftReference = ::java::lang::ref::SoftReference;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Member = ::java::lang::reflect::Member;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $RecordComponent = ::java::lang::reflect::RecordComponent;
using $UndeclaredThrowableException = ::java::lang::reflect::UndeclaredThrowableException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $HashSet = ::java::util::HashSet;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Stream = ::java::util::stream::Stream;
using $JavaSecurityAccess = ::jdk::internal::access::JavaSecurityAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectionFactory = ::jdk::internal::reflect::ReflectionFactory;
using $ReflectionFactory$GetReflectionFactoryAction = ::jdk::internal::reflect::ReflectionFactory$GetReflectionFactoryAction;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace java {
	namespace io {

class ObjectStreamClass$$Lambda$lambda$newInstance$0 : public $PrivilegedAction {
	$class(ObjectStreamClass$$Lambda$lambda$newInstance$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(ObjectStreamClass* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $nc(inst$)->lambda$newInstance$0();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectStreamClass$$Lambda$lambda$newInstance$0>());
	}
	ObjectStreamClass* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ObjectStreamClass$$Lambda$lambda$newInstance$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ObjectStreamClass$$Lambda$lambda$newInstance$0, inst$)},
	{}
};
$MethodInfo ObjectStreamClass$$Lambda$lambda$newInstance$0::methodInfos[3] = {
	{"<init>", "(Ljava/io/ObjectStreamClass;)V", nullptr, $PUBLIC, $method(ObjectStreamClass$$Lambda$lambda$newInstance$0, init$, void, ObjectStreamClass*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass$$Lambda$lambda$newInstance$0, run, $Object*)},
	{}
};
$ClassInfo ObjectStreamClass$$Lambda$lambda$newInstance$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectStreamClass$$Lambda$lambda$newInstance$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ObjectStreamClass$$Lambda$lambda$newInstance$0::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$$Lambda$lambda$newInstance$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectStreamClass$$Lambda$lambda$newInstance$0::class$ = nullptr;

class ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1 : public $PrivilegedAction {
	$class(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Class* cls) {
		this->cls = cls;
	}
	virtual $Object* run() override {
		 return $of(ObjectStreamClass::lambda$canonicalRecordCtr$2(cls));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1>());
	}
	$Class* cls = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::fieldInfos[2] = {
	{"cls", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1, cls)},
	{}
};
$MethodInfo ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1, init$, void, $Class*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1, run, $Object*)},
	{}
};
$ClassInfo ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::class$ = nullptr;

class ObjectStreamClass$$Lambda$getType$2 : public $Function {
	$class(ObjectStreamClass$$Lambda$getType$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($RecordComponent, inst$)->getType());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectStreamClass$$Lambda$getType$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectStreamClass$$Lambda$getType$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectStreamClass$$Lambda$getType$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass$$Lambda$getType$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ObjectStreamClass$$Lambda$getType$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectStreamClass$$Lambda$getType$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ObjectStreamClass$$Lambda$getType$2::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$$Lambda$getType$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectStreamClass$$Lambda$getType$2::class$ = nullptr;

class ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3 : public $IntFunction {
	$class(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(ObjectStreamClass::lambda$canonicalRecordCtr$1(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3, apply, $Object*, int32_t)},
	{}
};
$ClassInfo ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3::load$($String* name, bool initialize) {
	$loadClass(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3::class$ = nullptr;

$CompoundAttribute _ObjectStreamClass_MethodAnnotations_forClass11[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _ObjectStreamClass_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ObjectStreamClass, $assertionsDisabled)},
	{"NO_FIELDS", "[Ljava/io/ObjectStreamField;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ObjectStreamClass, NO_FIELDS)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ObjectStreamClass, serialVersionUID)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectStreamClass, serialPersistentFields)},
	{"reflFactory", "Ljdk/internal/reflect/ReflectionFactory;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectStreamClass, reflFactory)},
	{"cl", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE, $field(ObjectStreamClass, cl)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ObjectStreamClass, name)},
	{"suid", "Ljava/lang/Long;", nullptr, $PRIVATE | $VOLATILE, $field(ObjectStreamClass, suid)},
	{"isProxy", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, isProxy$)},
	{"isEnum", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, isEnum$)},
	{"isRecord", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, isRecord$)},
	{"serializable", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, serializable)},
	{"externalizable", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, externalizable)},
	{"hasWriteObjectData", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, hasWriteObjectData$)},
	{"hasBlockExternalData", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, hasBlockExternalData$)},
	{"resolveEx", "Ljava/lang/ClassNotFoundException;", nullptr, $PRIVATE, $field(ObjectStreamClass, resolveEx)},
	{"deserializeEx", "Ljava/io/ObjectStreamClass$ExceptionInfo;", nullptr, $PRIVATE, $field(ObjectStreamClass, deserializeEx)},
	{"serializeEx", "Ljava/io/ObjectStreamClass$ExceptionInfo;", nullptr, $PRIVATE, $field(ObjectStreamClass, serializeEx)},
	{"defaultSerializeEx", "Ljava/io/ObjectStreamClass$ExceptionInfo;", nullptr, $PRIVATE, $field(ObjectStreamClass, defaultSerializeEx)},
	{"fields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE, $field(ObjectStreamClass, fields)},
	{"primDataSize", "I", nullptr, $PRIVATE, $field(ObjectStreamClass, primDataSize)},
	{"numObjFields", "I", nullptr, $PRIVATE, $field(ObjectStreamClass, numObjFields)},
	{"fieldRefl", "Ljava/io/ObjectStreamClass$FieldReflector;", nullptr, $PRIVATE, $field(ObjectStreamClass, fieldRefl)},
	{"dataLayout", "[Ljava/io/ObjectStreamClass$ClassDataSlot;", nullptr, $PRIVATE | $VOLATILE, $field(ObjectStreamClass, dataLayout)},
	{"cons", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<*>;", $PRIVATE, $field(ObjectStreamClass, cons)},
	{"canonicalCtr", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $field(ObjectStreamClass, canonicalCtr)},
	{"deserializationCtrs", "Ljava/io/ObjectStreamClass$DeserializationConstructorsCache;", nullptr, $PRIVATE, $field(ObjectStreamClass, deserializationCtrs)},
	{"deserializationCtr", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $field(ObjectStreamClass, deserializationCtr)},
	{"domains", "[Ljava/security/ProtectionDomain;", nullptr, $PRIVATE, $field(ObjectStreamClass, domains)},
	{"writeObjectMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $field(ObjectStreamClass, writeObjectMethod)},
	{"readObjectMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $field(ObjectStreamClass, readObjectMethod)},
	{"readObjectNoDataMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $field(ObjectStreamClass, readObjectNoDataMethod)},
	{"writeReplaceMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $field(ObjectStreamClass, writeReplaceMethod)},
	{"readResolveMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE, $field(ObjectStreamClass, readResolveMethod)},
	{"localDesc", "Ljava/io/ObjectStreamClass;", nullptr, $PRIVATE, $field(ObjectStreamClass, localDesc)},
	{"superDesc", "Ljava/io/ObjectStreamClass;", nullptr, $PRIVATE, $field(ObjectStreamClass, superDesc)},
	{"initialized", "Z", nullptr, $PRIVATE, $field(ObjectStreamClass, initialized)},
	{}
};

$MethodInfo _ObjectStreamClass_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PRIVATE, $method(ObjectStreamClass, init$, void, $Class*)},
	{"<init>", "()V", nullptr, 0, $method(ObjectStreamClass, init$, void)},
	{"canonicalRecordCtr", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, canonicalRecordCtr, $MethodHandle*, $Class*)},
	{"checkDefaultSerialize", "()V", nullptr, 0, $virtualMethod(ObjectStreamClass, checkDefaultSerialize, void), "java.io.InvalidClassException"},
	{"checkDeserialize", "()V", nullptr, 0, $virtualMethod(ObjectStreamClass, checkDeserialize, void), "java.io.InvalidClassException"},
	{"checkInitialized", "()V", nullptr, $FINAL, $method(ObjectStreamClass, checkInitialized, void), "java.io.InvalidClassException"},
	{"checkObjFieldValueTypes", "(Ljava/lang/Object;[Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, checkObjFieldValueTypes, void, Object$*, $ObjectArray*)},
	{"checkSerialize", "()V", nullptr, 0, $virtualMethod(ObjectStreamClass, checkSerialize, void), "java.io.InvalidClassException"},
	{"classNamesEqual", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, classNamesEqual, bool, $String*, $String*)},
	{"computeDefaultSUID", "(Ljava/lang/Class;)J", "(Ljava/lang/Class<*>;)J", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, computeDefaultSUID, int64_t, $Class*)},
	{"computeFieldOffsets", "()V", nullptr, $PRIVATE, $method(ObjectStreamClass, computeFieldOffsets, void), "java.io.InvalidClassException"},
	{"forClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(ObjectStreamClass, forClass, $Class*), nullptr, nullptr, _ObjectStreamClass_MethodAnnotations_forClass11},
	{"getClassDataLayout", "()[Ljava/io/ObjectStreamClass$ClassDataSlot;", nullptr, 0, $virtualMethod(ObjectStreamClass, getClassDataLayout, $ObjectStreamClass$ClassDataSlotArray*), "java.io.InvalidClassException"},
	{"getClassDataLayout0", "()[Ljava/io/ObjectStreamClass$ClassDataSlot;", nullptr, $PRIVATE, $method(ObjectStreamClass, getClassDataLayout0, $ObjectStreamClass$ClassDataSlotArray*), "java.io.InvalidClassException"},
	{"getDeclaredSUID", "(Ljava/lang/Class;)Ljava/lang/Long;", "(Ljava/lang/Class<*>;)Ljava/lang/Long;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getDeclaredSUID, $Long*, $Class*)},
	{"getDeclaredSerialFields", "(Ljava/lang/Class;)[Ljava/io/ObjectStreamField;", "(Ljava/lang/Class<*>;)[Ljava/io/ObjectStreamField;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getDeclaredSerialFields, $ObjectStreamFieldArray*, $Class*), "java.io.InvalidClassException"},
	{"getDefaultSerialFields", "(Ljava/lang/Class;)[Ljava/io/ObjectStreamField;", "(Ljava/lang/Class<*>;)[Ljava/io/ObjectStreamField;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getDefaultSerialFields, $ObjectStreamFieldArray*, $Class*)},
	{"getExternalizableConstructor", "(Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<*>;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getExternalizableConstructor, $Constructor*, $Class*)},
	{"getField", "(Ljava/lang/String;)Ljava/io/ObjectStreamField;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass, getField, $ObjectStreamField*, $String*)},
	{"getField", "(Ljava/lang/String;Ljava/lang/Class;)Ljava/io/ObjectStreamField;", "(Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/io/ObjectStreamField;", 0, $virtualMethod(ObjectStreamClass, getField, $ObjectStreamField*, $String*, $Class*)},
	{"getFields", "()[Ljava/io/ObjectStreamField;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass, getFields, $ObjectStreamFieldArray*)},
	{"getFields", "(Z)[Ljava/io/ObjectStreamField;", nullptr, 0, $virtualMethod(ObjectStreamClass, getFields, $ObjectStreamFieldArray*, bool)},
	{"getInheritableMethod", "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/Class;)Ljava/lang/reflect/Method;", "(Ljava/lang/Class<*>;Ljava/lang/String;[Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getInheritableMethod, $Method*, $Class*, $String*, $ClassArray*, $Class*)},
	{"getLocalDesc", "()Ljava/io/ObjectStreamClass;", nullptr, 0, $virtualMethod(ObjectStreamClass, getLocalDesc, ObjectStreamClass*)},
	{"getMethodSignature", "([Ljava/lang/Class;Ljava/lang/Class;)Ljava/lang/String;", "([Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getMethodSignature, $String*, $ClassArray*, $Class*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass, getName, $String*)},
	{"getNumObjFields", "()I", nullptr, 0, $virtualMethod(ObjectStreamClass, getNumObjFields, int32_t)},
	{"getObjFieldValues", "(Ljava/lang/Object;[Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, getObjFieldValues, void, Object$*, $ObjectArray*)},
	{"getPrimDataSize", "()I", nullptr, 0, $virtualMethod(ObjectStreamClass, getPrimDataSize, int32_t)},
	{"getPrimFieldValues", "(Ljava/lang/Object;[B)V", nullptr, 0, $virtualMethod(ObjectStreamClass, getPrimFieldValues, void, Object$*, $bytes*)},
	{"getPrivateMethod", "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/Class;)Ljava/lang/reflect/Method;", "(Ljava/lang/Class<*>;Ljava/lang/String;[Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getPrivateMethod, $Method*, $Class*, $String*, $ClassArray*, $Class*)},
	{"getProtectionDomains", "(Ljava/lang/reflect/Constructor;Ljava/lang/Class;)[Ljava/security/ProtectionDomain;", "(Ljava/lang/reflect/Constructor<*>;Ljava/lang/Class<*>;)[Ljava/security/ProtectionDomain;", $PRIVATE, $method(ObjectStreamClass, getProtectionDomains, $ProtectionDomainArray*, $Constructor*, $Class*)},
	{"getRecordConstructor", "()Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(ObjectStreamClass, getRecordConstructor, $MethodHandle*)},
	{"getReflector", "([Ljava/io/ObjectStreamField;Ljava/io/ObjectStreamClass;)Ljava/io/ObjectStreamClass$FieldReflector;", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getReflector, $ObjectStreamClass$FieldReflector*, $ObjectStreamFieldArray*, ObjectStreamClass*), "java.io.InvalidClassException"},
	{"getResolveException", "()Ljava/lang/ClassNotFoundException;", nullptr, 0, $virtualMethod(ObjectStreamClass, getResolveException, $ClassNotFoundException*)},
	{"getSerialFields", "(Ljava/lang/Class;)[Ljava/io/ObjectStreamField;", "(Ljava/lang/Class<*>;)[Ljava/io/ObjectStreamField;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getSerialFields, $ObjectStreamFieldArray*, $Class*), "java.io.InvalidClassException"},
	{"getSerialVersionUID", "()J", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass, getSerialVersionUID, int64_t)},
	{"getSerializableConstructor", "(Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<*>;", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, getSerializableConstructor, $Constructor*, $Class*)},
	{"getSuperDesc", "()Ljava/io/ObjectStreamClass;", nullptr, 0, $virtualMethod(ObjectStreamClass, getSuperDesc, ObjectStreamClass*)},
	{"getVariantFor", "(Ljava/lang/Class;)Ljava/io/ObjectStreamClass;", "(Ljava/lang/Class<*>;)Ljava/io/ObjectStreamClass;", $PRIVATE, $method(ObjectStreamClass, getVariantFor, ObjectStreamClass*, $Class*), "java.io.InvalidClassException"},
	{"hasBlockExternalData", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasBlockExternalData, bool)},
	{"hasReadObjectMethod", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasReadObjectMethod, bool)},
	{"hasReadObjectNoDataMethod", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasReadObjectNoDataMethod, bool)},
	{"hasReadResolveMethod", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasReadResolveMethod, bool)},
	{"hasStaticInitializer", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC | $NATIVE, $staticMethod(ObjectStreamClass, hasStaticInitializer, bool, $Class*)},
	{"hasWriteObjectData", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasWriteObjectData, bool)},
	{"hasWriteObjectMethod", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasWriteObjectMethod, bool)},
	{"hasWriteReplaceMethod", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, hasWriteReplaceMethod, bool)},
	{"initNative", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(ObjectStreamClass, initNative, void)},
	{"initNonProxy", "(Ljava/io/ObjectStreamClass;Ljava/lang/Class;Ljava/lang/ClassNotFoundException;Ljava/io/ObjectStreamClass;)V", "(Ljava/io/ObjectStreamClass;Ljava/lang/Class<*>;Ljava/lang/ClassNotFoundException;Ljava/io/ObjectStreamClass;)V", 0, $virtualMethod(ObjectStreamClass, initNonProxy, void, ObjectStreamClass*, $Class*, $ClassNotFoundException*, ObjectStreamClass*), "java.io.InvalidClassException"},
	{"initProxy", "(Ljava/lang/Class;Ljava/lang/ClassNotFoundException;Ljava/io/ObjectStreamClass;)V", "(Ljava/lang/Class<*>;Ljava/lang/ClassNotFoundException;Ljava/io/ObjectStreamClass;)V", 0, $virtualMethod(ObjectStreamClass, initProxy, void, $Class*, $ClassNotFoundException*, ObjectStreamClass*), "java.io.InvalidClassException"},
	{"invokeReadObject", "(Ljava/lang/Object;Ljava/io/ObjectInputStream;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, invokeReadObject, void, Object$*, $ObjectInputStream*), "java.lang.ClassNotFoundException,java.io.IOException,java.lang.UnsupportedOperationException"},
	{"invokeReadObjectNoData", "(Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, invokeReadObjectNoData, void, Object$*), "java.io.IOException,java.lang.UnsupportedOperationException"},
	{"invokeReadResolve", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, 0, $virtualMethod(ObjectStreamClass, invokeReadResolve, $Object*, Object$*), "java.io.IOException,java.lang.UnsupportedOperationException"},
	{"invokeWriteObject", "(Ljava/lang/Object;Ljava/io/ObjectOutputStream;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, invokeWriteObject, void, Object$*, $ObjectOutputStream*), "java.io.IOException,java.lang.UnsupportedOperationException"},
	{"invokeWriteReplace", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, 0, $virtualMethod(ObjectStreamClass, invokeWriteReplace, $Object*, Object$*), "java.io.IOException,java.lang.UnsupportedOperationException"},
	{"isEnum", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, isEnum, bool)},
	{"isExternalizable", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, isExternalizable, bool)},
	{"isInstantiable", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, isInstantiable, bool)},
	{"isProxy", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, isProxy, bool)},
	{"isRecord", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, isRecord, bool)},
	{"isSerializable", "()Z", nullptr, 0, $virtualMethod(ObjectStreamClass, isSerializable, bool)},
	{"lambda$canonicalRecordCtr$1", "(I)[Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ObjectStreamClass, lambda$canonicalRecordCtr$1, $ClassArray*, int32_t)},
	{"lambda$canonicalRecordCtr$2", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ObjectStreamClass, lambda$canonicalRecordCtr$2, $MethodHandle*, $Class*)},
	{"lambda$newInstance$0", "()Ljava/lang/Object;", nullptr, $PRIVATE | $SYNTHETIC, $method(ObjectStreamClass, lambda$newInstance$0, $Object*)},
	{"lookup", "(Ljava/lang/Class;)Ljava/io/ObjectStreamClass;", "(Ljava/lang/Class<*>;)Ljava/io/ObjectStreamClass;", $PUBLIC | $STATIC, $staticMethod(ObjectStreamClass, lookup, ObjectStreamClass*, $Class*)},
	{"lookup", "(Ljava/lang/Class;Z)Ljava/io/ObjectStreamClass;", "(Ljava/lang/Class<*>;Z)Ljava/io/ObjectStreamClass;", $STATIC, $staticMethod(ObjectStreamClass, lookup, ObjectStreamClass*, $Class*, bool)},
	{"lookupAny", "(Ljava/lang/Class;)Ljava/io/ObjectStreamClass;", "(Ljava/lang/Class<*>;)Ljava/io/ObjectStreamClass;", $PUBLIC | $STATIC, $staticMethod(ObjectStreamClass, lookupAny, ObjectStreamClass*, $Class*)},
	{"matchFields", "([Ljava/io/ObjectStreamField;Ljava/io/ObjectStreamClass;)[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, matchFields, $ObjectStreamFieldArray*, $ObjectStreamFieldArray*, ObjectStreamClass*), "java.io.InvalidClassException"},
	{"newInstance", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(ObjectStreamClass, newInstance, $Object*), "java.lang.InstantiationException,java.lang.reflect.InvocationTargetException,java.lang.UnsupportedOperationException"},
	{"noPermissionsDomain", "()Ljava/security/ProtectionDomain;", nullptr, $PRIVATE, $method(ObjectStreamClass, noPermissionsDomain, $ProtectionDomain*)},
	{"packageEquals", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, packageEquals, bool, $Class*, $Class*)},
	{"processQueue", "(Ljava/lang/ref/ReferenceQueue;Ljava/util/concurrent/ConcurrentMap;)V", "(Ljava/lang/ref/ReferenceQueue<Ljava/lang/Class<*>;>;Ljava/util/concurrent/ConcurrentMap<+Ljava/lang/ref/WeakReference<Ljava/lang/Class<*>;>;*>;)V", $STATIC, $staticMethod(ObjectStreamClass, processQueue, void, $ReferenceQueue*, $ConcurrentMap*)},
	{"readNonProxy", "(Ljava/io/ObjectInputStream;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, readNonProxy, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"requireInitialized", "()V", nullptr, $PRIVATE | $FINAL, $method(ObjectStreamClass, requireInitialized, void)},
	{"setObjFieldValues", "(Ljava/lang/Object;[Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, setObjFieldValues, void, Object$*, $ObjectArray*)},
	{"setPrimFieldValues", "(Ljava/lang/Object;[B)V", nullptr, 0, $virtualMethod(ObjectStreamClass, setPrimFieldValues, void, Object$*, $bytes*)},
	{"throwMiscException", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectStreamClass, throwMiscException, void, $Throwable*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ObjectStreamClass, toString, $String*)},
	{"writeNonProxy", "(Ljava/io/ObjectOutputStream;)V", nullptr, 0, $virtualMethod(ObjectStreamClass, writeNonProxy, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_hasStaticInitializer 44
#define _METHOD_INDEX_initNative 48

$InnerClassInfo _ObjectStreamClass_InnerClassesInfo_[] = {
	{"java.io.ObjectStreamClass$RecordSupport", "java.io.ObjectStreamClass", "RecordSupport", $STATIC | $FINAL},
	{"java.io.ObjectStreamClass$DeserializationConstructorsCache", "java.io.ObjectStreamClass", "DeserializationConstructorsCache", $PRIVATE | $STATIC | $FINAL},
	{"java.io.ObjectStreamClass$WeakClassKey", "java.io.ObjectStreamClass", "WeakClassKey", $STATIC},
	{"java.io.ObjectStreamClass$FieldReflectorKey", "java.io.ObjectStreamClass", "FieldReflectorKey", $PRIVATE | $STATIC},
	{"java.io.ObjectStreamClass$FieldReflector", "java.io.ObjectStreamClass", "FieldReflector", $PRIVATE | $STATIC},
	{"java.io.ObjectStreamClass$MemberSignature", "java.io.ObjectStreamClass", "MemberSignature", $PRIVATE | $STATIC},
	{"java.io.ObjectStreamClass$ClassDataSlot", "java.io.ObjectStreamClass", "ClassDataSlot", $STATIC},
	{"java.io.ObjectStreamClass$EntryFuture", "java.io.ObjectStreamClass", "EntryFuture", $PRIVATE | $STATIC},
	{"java.io.ObjectStreamClass$ExceptionInfo", "java.io.ObjectStreamClass", "ExceptionInfo", $PRIVATE | $STATIC},
	{"java.io.ObjectStreamClass$Caches", "java.io.ObjectStreamClass", "Caches", $PRIVATE | $STATIC},
	{"java.io.ObjectStreamClass$5", nullptr, nullptr, 0},
	{"java.io.ObjectStreamClass$4", nullptr, nullptr, 0},
	{"java.io.ObjectStreamClass$3", nullptr, nullptr, 0},
	{"java.io.ObjectStreamClass$2", nullptr, nullptr, 0},
	{"java.io.ObjectStreamClass$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ObjectStreamClass_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.ObjectStreamClass",
	"java.lang.Object",
	"java.io.Serializable",
	_ObjectStreamClass_FieldInfo_,
	_ObjectStreamClass_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectStreamClass_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.ObjectStreamClass$RecordSupport,java.io.ObjectStreamClass$DeserializationConstructorsCache,java.io.ObjectStreamClass$DeserializationConstructorsCache$Key,java.io.ObjectStreamClass$DeserializationConstructorsCache$Key$Impl,java.io.ObjectStreamClass$DeserializationConstructorsCache$Key$Lookup,java.io.ObjectStreamClass$WeakClassKey,java.io.ObjectStreamClass$FieldReflectorKey,java.io.ObjectStreamClass$FieldReflector,java.io.ObjectStreamClass$MemberSignature,java.io.ObjectStreamClass$ClassDataSlot,java.io.ObjectStreamClass$EntryFuture,java.io.ObjectStreamClass$EntryFuture$1,java.io.ObjectStreamClass$ExceptionInfo,java.io.ObjectStreamClass$Caches,java.io.ObjectStreamClass$5,java.io.ObjectStreamClass$4,java.io.ObjectStreamClass$3,java.io.ObjectStreamClass$2,java.io.ObjectStreamClass$1"
};

$Object* allocate$ObjectStreamClass($Class* clazz) {
	return $of($alloc(ObjectStreamClass));
}

bool ObjectStreamClass::$assertionsDisabled = false;
$ObjectStreamFieldArray* ObjectStreamClass::NO_FIELDS = nullptr;
$ObjectStreamFieldArray* ObjectStreamClass::serialPersistentFields = nullptr;
$ReflectionFactory* ObjectStreamClass::reflFactory = nullptr;

void ObjectStreamClass::initNative() {
	$init(ObjectStreamClass);
	$prepareNativeStatic(ObjectStreamClass, initNative, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

ObjectStreamClass* ObjectStreamClass::lookup($Class* cl) {
	$init(ObjectStreamClass);
	return lookup(cl, false);
}

ObjectStreamClass* ObjectStreamClass::lookupAny($Class* cl) {
	$init(ObjectStreamClass);
	return lookup(cl, true);
}

$String* ObjectStreamClass::getName() {
	return this->name;
}

int64_t ObjectStreamClass::getSerialVersionUID() {
	$beforeCallerSensitive();
	if (this->suid == nullptr) {
		if (this->isRecord$) {
			return 0;
		}
		$set(this, suid, $cast($Long, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ObjectStreamClass$1, this)))));
	}
	return $nc(this->suid)->longValue();
}

$Class* ObjectStreamClass::forClass() {
	$useLocalCurrentObjectStackCache();
	if (this->cl == nullptr) {
		return nullptr;
	}
	requireInitialized();
	if ($System::getSecurityManager() != nullptr) {
		$Class* caller = $Reflection::getCallerClass();
		$var($ClassLoader, var$0, $nc(caller)->getClassLoader());
		if ($ReflectUtil::needsPackageAccessCheck(var$0, $($nc(this->cl)->getClassLoader()))) {
			$ReflectUtil::checkPackageAccess(this->cl);
		}
	}
	return this->cl;
}

$ObjectStreamFieldArray* ObjectStreamClass::getFields() {
	return getFields(true);
}

$ObjectStreamField* ObjectStreamClass::getField($String* name) {
	return getField(name, nullptr);
}

$String* ObjectStreamClass::toString() {
	return $str({this->name, ": static final long serialVersionUID = "_s, $$str(getSerialVersionUID()), "L;"_s});
}

ObjectStreamClass* ObjectStreamClass::lookup($Class* cl, bool all) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$load($Serializable);
	if (!(all || $Serializable::class$->isAssignableFrom(cl))) {
		return nullptr;
	}
	$init($ObjectStreamClass$Caches);
	processQueue($ObjectStreamClass$Caches::localDescsQueue, $ObjectStreamClass$Caches::localDescs);
	$var($ObjectStreamClass$WeakClassKey, key, $new($ObjectStreamClass$WeakClassKey, cl, $ObjectStreamClass$Caches::localDescsQueue));
	$var($Reference, ref, $cast($Reference, $nc($ObjectStreamClass$Caches::localDescs)->get(key)));
	$var($Object, entry, nullptr);
	if (ref != nullptr) {
		$assign(entry, ref->get());
	}
	$var($ObjectStreamClass$EntryFuture, future, nullptr);
	if (entry == nullptr) {
		$var($ObjectStreamClass$EntryFuture, newEntry, $new($ObjectStreamClass$EntryFuture));
		$var($Reference, newRef, $new($SoftReference, newEntry));
		do {
			if (ref != nullptr) {
				$nc($ObjectStreamClass$Caches::localDescs)->remove(key, ref);
			}
			$assign(ref, $cast($Reference, $nc($ObjectStreamClass$Caches::localDescs)->putIfAbsent(key, newRef)));
			if (ref != nullptr) {
				$assign(entry, ref->get());
			}
		} while (ref != nullptr && entry == nullptr);
		if (entry == nullptr) {
			$assign(future, newEntry);
		}
	}
	if ($instanceOf(ObjectStreamClass, entry)) {
		return $cast(ObjectStreamClass, entry);
	}
	if ($instanceOf($ObjectStreamClass$EntryFuture, entry)) {
		$assign(future, $cast($ObjectStreamClass$EntryFuture, entry));
		if ($nc(future)->getOwner() == $Thread::currentThread()) {
			$assign(entry, nullptr);
		} else {
			$assign(entry, future->get());
		}
	}
	if (entry == nullptr) {
		try {
			$assign(entry, $new(ObjectStreamClass, cl));
		} catch ($Throwable& th) {
			$assign(entry, th);
		}
		if ($nc(future)->set(entry)) {
			$nc($ObjectStreamClass$Caches::localDescs)->put(key, $$new($SoftReference, entry));
		} else {
			$assign(entry, future->get());
		}
	}
	if ($instanceOf(ObjectStreamClass, entry)) {
		return $cast(ObjectStreamClass, entry);
	} else if ($instanceOf($RuntimeException, entry)) {
		$throw($cast($RuntimeException, entry));
	} else if ($instanceOf($Error, entry)) {
		$throw($cast($Error, entry));
	} else {
		$throwNew($InternalError, $$str({"unexpected entry: "_s, entry}));
	}
}

void ObjectStreamClass::init$($Class* cl) {
	$beforeCallerSensitive();
	this->hasBlockExternalData$ = true;
	$set(this, cl, cl);
	$set(this, name, $nc(cl)->getName());
	this->isProxy$ = $Proxy::isProxyClass(cl);
	$load($Enum);
	this->isEnum$ = $Enum::class$->isAssignableFrom(cl);
	this->isRecord$ = cl->isRecord();
	$load($Serializable);
	this->serializable = $Serializable::class$->isAssignableFrom(cl);
	$load($Externalizable);
	this->externalizable = $Externalizable::class$->isAssignableFrom(cl);
	$Class* superCl = cl->getSuperclass();
	$set(this, superDesc, (superCl != nullptr) ? lookup(superCl, false) : (ObjectStreamClass*)nullptr);
	$set(this, localDesc, this);
	if (this->serializable) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ObjectStreamClass$2, this, cl)));
	} else {
		$set(this, suid, $Long::valueOf((int64_t)0));
		$set(this, fields, ObjectStreamClass::NO_FIELDS);
	}
	try {
		$set(this, fieldRefl, getReflector(this->fields, this));
	} catch ($InvalidClassException& ex) {
		$throwNew($InternalError, static_cast<$Throwable*>(ex));
	}
	if (this->deserializeEx == nullptr) {
		if (this->isEnum$) {
			$set(this, deserializeEx, $new($ObjectStreamClass$ExceptionInfo, this->name, "enum type"_s));
		} else if (this->cons == nullptr && !this->isRecord$) {
			$set(this, deserializeEx, $new($ObjectStreamClass$ExceptionInfo, this->name, "no valid constructor"_s));
		}
	}
	if (this->isRecord$ && this->canonicalCtr == nullptr) {
		$set(this, deserializeEx, $new($ObjectStreamClass$ExceptionInfo, this->name, "record canonical constructor not found"_s));
	} else {
		for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
			if ($nc($nc(this->fields)->get(i))->getField() == nullptr) {
				$set(this, defaultSerializeEx, $new($ObjectStreamClass$ExceptionInfo, this->name, "unmatched serializable field(s) declared"_s));
			}
		}
	}
	this->initialized = true;
}

void ObjectStreamClass::init$() {
	this->hasBlockExternalData$ = true;
}

$ProtectionDomain* ObjectStreamClass::noPermissionsDomain() {
	$var($PermissionCollection, perms, $new($Permissions));
	perms->setReadOnly();
	return $new($ProtectionDomain, nullptr, perms);
}

$ProtectionDomainArray* ObjectStreamClass::getProtectionDomains($Constructor* cons, $Class* cl) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ProtectionDomainArray, domains, nullptr);
	bool var$0 = cons != nullptr && $nc(cl)->getClassLoader() != nullptr;
	if (var$0 && $System::getSecurityManager() != nullptr) {
		$Class* cls = cl;
		$Class* fnscl = cons->getDeclaringClass();
		$var($Set, pds, nullptr);
		while (cls != fnscl) {
			$var($ProtectionDomain, pd, $nc(cls)->getProtectionDomain());
			if (pd != nullptr) {
				if (pds == nullptr) {
					$assign(pds, $new($HashSet));
				}
				$nc(pds)->add(pd);
			}
			cls = cls->getSuperclass();
			if (cls == nullptr) {
				if (pds == nullptr) {
					$assign(pds, $new($HashSet));
				} else {
					$nc(pds)->clear();
				}
				$nc(pds)->add($(noPermissionsDomain()));
				break;
			}
		}
		if (pds != nullptr) {
			$assign(domains, $fcast($ProtectionDomainArray, pds->toArray($$new($ProtectionDomainArray, 0))));
		}
	}
	return domains;
}

void ObjectStreamClass::initProxy($Class* cl, $ClassNotFoundException* resolveEx, ObjectStreamClass* superDesc) {
	$var(ObjectStreamClass, osc, nullptr);
	if (cl != nullptr) {
		$assign(osc, lookup(cl, true));
		if (!$nc(osc)->isProxy$) {
			$throwNew($InvalidClassException, "cannot bind proxy descriptor to a non-proxy class"_s);
		}
	}
	$set(this, cl, cl);
	$set(this, resolveEx, resolveEx);
	$set(this, superDesc, superDesc);
	this->isProxy$ = true;
	this->serializable = true;
	$set(this, suid, $Long::valueOf((int64_t)0));
	$set(this, fields, ObjectStreamClass::NO_FIELDS);
	if (osc != nullptr) {
		$set(this, localDesc, osc);
		$set(this, name, $nc(this->localDesc)->name);
		this->externalizable = $nc(this->localDesc)->externalizable;
		$set(this, writeReplaceMethod, $nc(this->localDesc)->writeReplaceMethod);
		$set(this, readResolveMethod, $nc(this->localDesc)->readResolveMethod);
		$set(this, deserializeEx, $nc(this->localDesc)->deserializeEx);
		$set(this, domains, $nc(this->localDesc)->domains);
		$set(this, cons, $nc(this->localDesc)->cons);
	}
	$set(this, fieldRefl, getReflector(this->fields, this->localDesc));
	this->initialized = true;
}

void ObjectStreamClass::initNonProxy(ObjectStreamClass* model, $Class* cl, $ClassNotFoundException* resolveEx, ObjectStreamClass* superDesc) {
	$useLocalCurrentObjectStackCache();
	int64_t suid = $nc(model)->getSerialVersionUID();
	$var(ObjectStreamClass, osc, nullptr);
	if (cl != nullptr) {
		$assign(osc, lookup(cl, true));
		if ($nc(osc)->isProxy$) {
			$throwNew($InvalidClassException, "cannot bind non-proxy descriptor to a proxy class"_s);
		}
		if (model->isEnum$ != $nc(osc)->isEnum$) {
			$throwNew($InvalidClassException, model->isEnum$ ? "cannot bind enum descriptor to a non-enum class"_s : "cannot bind non-enum descriptor to an enum class"_s);
		}
		bool var$1 = model->serializable == $nc(osc)->serializable && !cl->isArray();
		bool var$0 = var$1 && !cl->isRecord();
		if (var$0 && suid != osc->getSerialVersionUID()) {
			$throwNew($InvalidClassException, osc->name, $$str({"local class incompatible: stream classdesc serialVersionUID = "_s, $$str(suid), ", local class serialVersionUID = "_s, $$str(osc->getSerialVersionUID())}));
		}
		if (!classNamesEqual(model->name, $nc(osc)->name)) {
			$throwNew($InvalidClassException, $nc(osc)->name, $$str({"local class name incompatible with stream class name \""_s, model->name, "\""_s}));
		}
		if (!model->isEnum$) {
			if ((model->serializable == $nc(osc)->serializable) && (model->externalizable != osc->externalizable)) {
				$throwNew($InvalidClassException, osc->name, "Serializable incompatible with Externalizable"_s);
			}
			if ((model->serializable != $nc(osc)->serializable) || (model->externalizable != $nc(osc)->externalizable) || !(model->serializable || model->externalizable)) {
				$set(this, deserializeEx, $new($ObjectStreamClass$ExceptionInfo, $nc(osc)->name, "class invalid for deserialization"_s));
			}
		}
	}
	$set(this, cl, cl);
	$set(this, resolveEx, resolveEx);
	$set(this, superDesc, superDesc);
	$set(this, name, model->name);
	$set(this, suid, $Long::valueOf(suid));
	this->isProxy$ = false;
	this->isEnum$ = model->isEnum$;
	this->serializable = model->serializable;
	this->externalizable = model->externalizable;
	this->hasBlockExternalData$ = model->hasBlockExternalData$;
	this->hasWriteObjectData$ = model->hasWriteObjectData$;
	$set(this, fields, model->fields);
	this->primDataSize = model->primDataSize;
	this->numObjFields = model->numObjFields;
	if (osc != nullptr) {
		$set(this, localDesc, osc);
		this->isRecord$ = $nc(this->localDesc)->isRecord$;
		$set(this, canonicalCtr, $nc(this->localDesc)->canonicalCtr);
		$set(this, deserializationCtrs, $nc(this->localDesc)->deserializationCtrs);
		$set(this, writeObjectMethod, $nc(this->localDesc)->writeObjectMethod);
		$set(this, readObjectMethod, $nc(this->localDesc)->readObjectMethod);
		$set(this, readObjectNoDataMethod, $nc(this->localDesc)->readObjectNoDataMethod);
		$set(this, writeReplaceMethod, $nc(this->localDesc)->writeReplaceMethod);
		$set(this, readResolveMethod, $nc(this->localDesc)->readResolveMethod);
		if (this->deserializeEx == nullptr) {
			$set(this, deserializeEx, $nc(this->localDesc)->deserializeEx);
		}
		$set(this, domains, $nc(this->localDesc)->domains);
		if (!ObjectStreamClass::$assertionsDisabled && !($nc(cl)->isRecord() ? $nc(this->localDesc)->cons == nullptr : true)) {
			$throwNew($AssertionError);
		}
		$set(this, cons, $nc(this->localDesc)->cons);
	}
	$set(this, fieldRefl, getReflector(this->fields, this->localDesc));
	$set(this, fields, $nc(this->fieldRefl)->getFields());
	this->initialized = true;
}

void ObjectStreamClass::readNonProxy($ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$set(this, name, $nc(in)->readUTF());
	$set(this, suid, $Long::valueOf(in->readLong()));
	this->isProxy$ = false;
	int8_t flags = in->readByte();
	this->hasWriteObjectData$ = (((int32_t)(flags & (uint32_t)(int32_t)$ObjectStreamConstants::SC_WRITE_METHOD)) != 0);
	this->hasBlockExternalData$ = (((int32_t)(flags & (uint32_t)(int32_t)$ObjectStreamConstants::SC_BLOCK_DATA)) != 0);
	this->externalizable = (((int32_t)(flags & (uint32_t)(int32_t)$ObjectStreamConstants::SC_EXTERNALIZABLE)) != 0);
	bool sflag = (((int32_t)(flags & (uint32_t)(int32_t)$ObjectStreamConstants::SC_SERIALIZABLE)) != 0);
	if (this->externalizable && sflag) {
		$throwNew($InvalidClassException, this->name, "serializable and externalizable flags conflict"_s);
	}
	this->serializable = this->externalizable || sflag;
	this->isEnum$ = (((int32_t)(flags & (uint32_t)(int32_t)$ObjectStreamConstants::SC_ENUM)) != 0);
	if (this->isEnum$ && $nc(this->suid)->longValue() != (int64_t)0) {
		$throwNew($InvalidClassException, this->name, $$str({"enum descriptor has non-zero serialVersionUID: "_s, this->suid}));
	}
	int32_t numFields = in->readShort();
	if (this->isEnum$ && numFields != 0) {
		$throwNew($InvalidClassException, this->name, $$str({"enum descriptor has non-zero field count: "_s, $$str(numFields)}));
	}
	$set(this, fields, (numFields > 0) ? $new($ObjectStreamFieldArray, numFields) : ObjectStreamClass::NO_FIELDS);
	for (int32_t i = 0; i < numFields; ++i) {
		char16_t tcode = (char16_t)in->readByte();
		$var($String, fname, in->readUTF());
		$var($String, signature, ((tcode == u'L') || (tcode == u'[')) ? in->readTypeString() : $String::valueOf(tcode));
		try {
			$nc(this->fields)->set(i, $$new($ObjectStreamField, fname, signature, false));
		} catch ($RuntimeException& e) {
			$throw($cast($IOException, $($$new($InvalidClassException, this->name, $$str({"invalid descriptor for field "_s, fname}))->initCause(e))));
		}
	}
	computeFieldOffsets();
}

void ObjectStreamClass::writeNonProxy($ObjectOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$nc(out)->writeUTF(this->name);
	out->writeLong(getSerialVersionUID());
	int8_t flags = (int8_t)0;
	if (this->externalizable) {
		flags |= $ObjectStreamConstants::SC_EXTERNALIZABLE;
		int32_t protocol = out->getProtocolVersion();
		if (protocol != $ObjectStreamConstants::PROTOCOL_VERSION_1) {
			flags |= $ObjectStreamConstants::SC_BLOCK_DATA;
		}
	} else if (this->serializable) {
		flags |= $ObjectStreamConstants::SC_SERIALIZABLE;
	}
	if (this->hasWriteObjectData$) {
		flags |= $ObjectStreamConstants::SC_WRITE_METHOD;
	}
	if (this->isEnum$) {
		flags |= $ObjectStreamConstants::SC_ENUM;
	}
	out->writeByte(flags);
	out->writeShort($nc(this->fields)->length);
	for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
		$var($ObjectStreamField, f, $nc(this->fields)->get(i));
		out->writeByte($nc(f)->getTypeCode());
		out->writeUTF($($nc(f)->getName()));
		if (!$nc(f)->isPrimitive()) {
			out->writeTypeString($(f->getTypeString()));
		}
	}
}

$ClassNotFoundException* ObjectStreamClass::getResolveException() {
	return this->resolveEx;
}

void ObjectStreamClass::requireInitialized() {
	if (!this->initialized) {
		$throwNew($InternalError, "Unexpected call when not initialized"_s);
	}
}

void ObjectStreamClass::checkInitialized() {
	if (!this->initialized) {
		$throwNew($InvalidClassException, "Class descriptor should be initialized"_s);
	}
}

void ObjectStreamClass::checkDeserialize() {
	requireInitialized();
	if (this->deserializeEx != nullptr) {
		$throw($($nc(this->deserializeEx)->newInvalidClassException()));
	}
}

void ObjectStreamClass::checkSerialize() {
	requireInitialized();
	if (this->serializeEx != nullptr) {
		$throw($($nc(this->serializeEx)->newInvalidClassException()));
	}
}

void ObjectStreamClass::checkDefaultSerialize() {
	requireInitialized();
	if (this->defaultSerializeEx != nullptr) {
		$throw($($nc(this->defaultSerializeEx)->newInvalidClassException()));
	}
}

ObjectStreamClass* ObjectStreamClass::getSuperDesc() {
	requireInitialized();
	return this->superDesc;
}

ObjectStreamClass* ObjectStreamClass::getLocalDesc() {
	requireInitialized();
	return this->localDesc;
}

$ObjectStreamFieldArray* ObjectStreamClass::getFields(bool copy) {
	return copy ? $cast($ObjectStreamFieldArray, $nc(this->fields)->clone()) : this->fields;
}

$ObjectStreamField* ObjectStreamClass::getField($String* name, $Class* type) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
		$var($ObjectStreamField, f, $nc(this->fields)->get(i));
		if ($nc($($nc(f)->getName()))->equals(name)) {
			if (type == nullptr || (type == $Object::class$ && !f->isPrimitive())) {
				return f;
			}
			$Class* ftype = f->getType();
			if (ftype != nullptr && $nc(type)->isAssignableFrom(ftype)) {
				return f;
			}
		}
	}
	return nullptr;
}

bool ObjectStreamClass::isProxy() {
	requireInitialized();
	return this->isProxy$;
}

bool ObjectStreamClass::isEnum() {
	requireInitialized();
	return this->isEnum$;
}

bool ObjectStreamClass::isRecord() {
	requireInitialized();
	return this->isRecord$;
}

bool ObjectStreamClass::isExternalizable() {
	requireInitialized();
	return this->externalizable;
}

bool ObjectStreamClass::isSerializable() {
	requireInitialized();
	return this->serializable;
}

bool ObjectStreamClass::hasBlockExternalData() {
	requireInitialized();
	return this->hasBlockExternalData$;
}

bool ObjectStreamClass::hasWriteObjectData() {
	requireInitialized();
	return this->hasWriteObjectData$;
}

bool ObjectStreamClass::isInstantiable() {
	requireInitialized();
	return (this->cons != nullptr);
}

bool ObjectStreamClass::hasWriteObjectMethod() {
	requireInitialized();
	return (this->writeObjectMethod != nullptr);
}

bool ObjectStreamClass::hasReadObjectMethod() {
	requireInitialized();
	return (this->readObjectMethod != nullptr);
}

bool ObjectStreamClass::hasReadObjectNoDataMethod() {
	requireInitialized();
	return (this->readObjectNoDataMethod != nullptr);
}

bool ObjectStreamClass::hasWriteReplaceMethod() {
	requireInitialized();
	return (this->writeReplaceMethod != nullptr);
}

bool ObjectStreamClass::hasReadResolveMethod() {
	requireInitialized();
	return (this->readResolveMethod != nullptr);
}

$Object* ObjectStreamClass::newInstance() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	requireInitialized();
	if (this->cons != nullptr) {
		try {
			if (this->domains == nullptr || $nc(this->domains)->length == 0) {
				return $of($nc(this->cons)->newInstance($$new($ObjectArray, 0)));
			} else {
				$var($JavaSecurityAccess, jsa, $SharedSecrets::getJavaSecurityAccess());
				$var($PrivilegedAction, pea, static_cast<$PrivilegedAction*>($new(ObjectStreamClass$$Lambda$lambda$newInstance$0, this)));
				try {
					$var($PrivilegedAction, var$0, pea);
					$var($AccessControlContext, var$1, $AccessController::getContext());
					return $of($nc(jsa)->doIntersectionPrivilege(var$0, var$1, $$new($AccessControlContext, this->domains)));
				} catch ($UndeclaredThrowableException& x) {
					$var($Throwable, cause, x->getCause());
					if ($instanceOf($InstantiationException, cause)) {
						$throw($cast($InstantiationException, cause));
					}
					if ($instanceOf($InvocationTargetException, cause)) {
						$throw($cast($InvocationTargetException, cause));
					}
					if ($instanceOf($IllegalAccessException, cause)) {
						$throw($cast($IllegalAccessException, cause));
					}
					$throw(x);
				}
			}
		} catch ($IllegalAccessException& ex) {
			$throwNew($InternalError, static_cast<$Throwable*>(ex));
		} catch ($InstantiationError& err) {
			$var($InstantiationException, ex, $new($InstantiationException));
			ex->initCause(err);
			$throw(ex);
		}
	} else {
		$throwNew($UnsupportedOperationException);
	}
	$shouldNotReachHere();
}

void ObjectStreamClass::invokeWriteObject(Object$* obj, $ObjectOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	requireInitialized();
	if (this->writeObjectMethod != nullptr) {
		try {
			$nc(this->writeObjectMethod)->invoke(obj, $$new($ObjectArray, {$of(out)}));
		} catch ($InvocationTargetException& ex) {
			$var($Throwable, th, ex->getCause());
			if ($instanceOf($IOException, th)) {
				$throw($cast($IOException, th));
			} else {
				throwMiscException(th);
			}
		} catch ($IllegalAccessException& ex) {
			$throwNew($InternalError, static_cast<$Throwable*>(ex));
		}
	} else {
		$throwNew($UnsupportedOperationException);
	}
}

void ObjectStreamClass::invokeReadObject(Object$* obj, $ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	requireInitialized();
	if (this->readObjectMethod != nullptr) {
		try {
			$nc(this->readObjectMethod)->invoke(obj, $$new($ObjectArray, {$of(in)}));
		} catch ($InvocationTargetException& ex) {
			$var($Throwable, th, ex->getCause());
			if ($instanceOf($ClassNotFoundException, th)) {
				$throw($cast($ClassNotFoundException, th));
			} else if ($instanceOf($IOException, th)) {
				$throw($cast($IOException, th));
			} else {
				throwMiscException(th);
			}
		} catch ($IllegalAccessException& ex) {
			$throwNew($InternalError, static_cast<$Throwable*>(ex));
		}
	} else {
		$throwNew($UnsupportedOperationException);
	}
}

void ObjectStreamClass::invokeReadObjectNoData(Object$* obj) {
	$beforeCallerSensitive();
	requireInitialized();
	if (this->readObjectNoDataMethod != nullptr) {
		try {
			$nc(this->readObjectNoDataMethod)->invoke(obj, ($ObjectArray*)nullptr);
		} catch ($InvocationTargetException& ex) {
			$var($Throwable, th, ex->getCause());
			if ($instanceOf($ObjectStreamException, th)) {
				$throw($cast($ObjectStreamException, th));
			} else {
				throwMiscException(th);
			}
		} catch ($IllegalAccessException& ex) {
			$throwNew($InternalError, static_cast<$Throwable*>(ex));
		}
	} else {
		$throwNew($UnsupportedOperationException);
	}
}

$Object* ObjectStreamClass::invokeWriteReplace(Object$* obj) {
	$beforeCallerSensitive();
	requireInitialized();
	if (this->writeReplaceMethod != nullptr) {
		try {
			return $of($nc(this->writeReplaceMethod)->invoke(obj, ($ObjectArray*)nullptr));
		} catch ($InvocationTargetException& ex) {
			$var($Throwable, th, ex->getCause());
			if ($instanceOf($ObjectStreamException, th)) {
				$throw($cast($ObjectStreamException, th));
			} else {
				throwMiscException(th);
				$throwNew($InternalError, th);
			}
		} catch ($IllegalAccessException& ex) {
			$throwNew($InternalError, static_cast<$Throwable*>(ex));
		}
	} else {
		$throwNew($UnsupportedOperationException);
	}
	$shouldNotReachHere();
}

$Object* ObjectStreamClass::invokeReadResolve(Object$* obj) {
	$beforeCallerSensitive();
	requireInitialized();
	if (this->readResolveMethod != nullptr) {
		try {
			return $of($nc(this->readResolveMethod)->invoke(obj, ($ObjectArray*)nullptr));
		} catch ($InvocationTargetException& ex) {
			$var($Throwable, th, ex->getCause());
			if ($instanceOf($ObjectStreamException, th)) {
				$throw($cast($ObjectStreamException, th));
			} else {
				throwMiscException(th);
				$throwNew($InternalError, th);
			}
		} catch ($IllegalAccessException& ex) {
			$throwNew($InternalError, static_cast<$Throwable*>(ex));
		}
	} else {
		$throwNew($UnsupportedOperationException);
	}
	$shouldNotReachHere();
}

$ObjectStreamClass$ClassDataSlotArray* ObjectStreamClass::getClassDataLayout() {
	if (this->dataLayout == nullptr) {
		$set(this, dataLayout, getClassDataLayout0());
	}
	return this->dataLayout;
}

$ObjectStreamClass$ClassDataSlotArray* ObjectStreamClass::getClassDataLayout0() {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, slots, $new($ArrayList));
	$Class* start = this->cl;
	$Class* end = this->cl;
	$load($Serializable);
	while (end != nullptr && $Serializable::class$->isAssignableFrom(end)) {
		end = end->getSuperclass();
	}
	$var($HashSet, oscNames, $new($HashSet, 3));
	{
		$var(ObjectStreamClass, d, this);
		for (; d != nullptr; $assign(d, d->superDesc)) {
			if (oscNames->contains($nc(d)->name)) {
				$throwNew($InvalidClassException, "Circular reference."_s);
			} else {
				oscNames->add($nc(d)->name);
			}
			$var($String, searchName, ($nc(d)->cl != nullptr) ? $nc($nc(d)->cl)->getName() : d->name);
			$Class* match = nullptr;
			{
				$Class* c = start;
				for (; c != end; c = $nc(c)->getSuperclass()) {
					if ($nc(searchName)->equals($(c->getName()))) {
						match = c;
						break;
					}
				}
			}
			if (match != nullptr) {
				{
					$Class* c = start;
					for (; c != match; c = $nc(c)->getSuperclass()) {
						slots->add($$new($ObjectStreamClass$ClassDataSlot, $(ObjectStreamClass::lookup(c, true)), false));
					}
				}
				start = match->getSuperclass();
			}
			slots->add($$new($ObjectStreamClass$ClassDataSlot, $(d->getVariantFor(match)), true));
		}
	}
	{
		$Class* c = start;
		for (; c != end; c = $nc(c)->getSuperclass()) {
			slots->add($$new($ObjectStreamClass$ClassDataSlot, $(ObjectStreamClass::lookup(c, true)), false));
		}
	}
	$Collections::reverse(slots);
	return $fcast($ObjectStreamClass$ClassDataSlotArray, slots->toArray($$new($ObjectStreamClass$ClassDataSlotArray, slots->size())));
}

int32_t ObjectStreamClass::getPrimDataSize() {
	return this->primDataSize;
}

int32_t ObjectStreamClass::getNumObjFields() {
	return this->numObjFields;
}

void ObjectStreamClass::getPrimFieldValues(Object$* obj, $bytes* buf) {
	$nc(this->fieldRefl)->getPrimFieldValues(obj, buf);
}

void ObjectStreamClass::setPrimFieldValues(Object$* obj, $bytes* buf) {
	$nc(this->fieldRefl)->setPrimFieldValues(obj, buf);
}

void ObjectStreamClass::getObjFieldValues(Object$* obj, $ObjectArray* vals) {
	$nc(this->fieldRefl)->getObjFieldValues(obj, vals);
}

void ObjectStreamClass::checkObjFieldValueTypes(Object$* obj, $ObjectArray* vals) {
	$nc(this->fieldRefl)->checkObjectFieldValueTypes(obj, vals);
}

void ObjectStreamClass::setObjFieldValues(Object$* obj, $ObjectArray* vals) {
	$nc(this->fieldRefl)->setObjFieldValues(obj, vals);
}

void ObjectStreamClass::computeFieldOffsets() {
	$useLocalCurrentObjectStackCache();
	this->primDataSize = 0;
	this->numObjFields = 0;
	int32_t firstObjIndex = -1;
	for (int32_t i = 0; i < $nc(this->fields)->length; ++i) {
		$var($ObjectStreamField, f, $nc(this->fields)->get(i));
		switch ($nc(f)->getTypeCode()) {
		case u'Z':
			{}
		case u'B':
			{
				f->setOffset(this->primDataSize++);
				break;
			}
		case u'C':
			{}
		case u'S':
			{
				{
					f->setOffset(this->primDataSize);
					this->primDataSize += 2;
				}
				break;
			}
		case u'I':
			{}
		case u'F':
			{
				{
					f->setOffset(this->primDataSize);
					this->primDataSize += 4;
				}
				break;
			}
		case u'J':
			{}
		case u'D':
			{
				{
					f->setOffset(this->primDataSize);
					this->primDataSize += 8;
				}
				break;
			}
		case u'[':
			{}
		case u'L':
			{
				{
					f->setOffset(this->numObjFields++);
					if (firstObjIndex == -1) {
						firstObjIndex = i;
					}
				}
				break;
			}
		default:
			{
				$throwNew($InternalError);
			}
		}
	}
	if (firstObjIndex != -1 && firstObjIndex + this->numObjFields != $nc(this->fields)->length) {
		$throwNew($InvalidClassException, this->name, "illegal field order"_s);
	}
}

ObjectStreamClass* ObjectStreamClass::getVariantFor($Class* cl) {
	if (this->cl == cl) {
		return this;
	}
	$var(ObjectStreamClass, desc, $new(ObjectStreamClass));
	if (this->isProxy$) {
		desc->initProxy(cl, nullptr, this->superDesc);
	} else {
		desc->initNonProxy(this, cl, nullptr, this->superDesc);
	}
	return desc;
}

$Constructor* ObjectStreamClass::getExternalizableConstructor($Class* cl) {
	$init(ObjectStreamClass);
	$beforeCallerSensitive();
	try {
		$var($Constructor, cons, $nc(cl)->getDeclaredConstructor(($ClassArray*)nullptr));
		$nc(cons)->setAccessible(true);
		return (((int32_t)(cons->getModifiers() & (uint32_t)$Modifier::PUBLIC)) != 0) ? cons : ($Constructor*)nullptr;
	} catch ($NoSuchMethodException& ex) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Constructor* ObjectStreamClass::getSerializableConstructor($Class* cl) {
	$init(ObjectStreamClass);
	return $nc(ObjectStreamClass::reflFactory)->newConstructorForSerialization(cl);
}

$MethodHandle* ObjectStreamClass::canonicalRecordCtr($Class* cls) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!ObjectStreamClass::$assertionsDisabled && !$nc(cls)->isRecord()) {
		$throwNew($AssertionError, $of($$str({"Expected record, got: "_s, cls})));
	}
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1, cls)));
	return $cast($MethodHandle, $AccessController::doPrivileged(pa));
}

$MethodHandle* ObjectStreamClass::getRecordConstructor() {
	return this->canonicalCtr;
}

$Method* ObjectStreamClass::getInheritableMethod($Class* cl, $String* name, $ClassArray* argTypes, $Class* returnType) {
	$init(ObjectStreamClass);
	$beforeCallerSensitive();
	$var($Method, meth, nullptr);
	$Class* defCl = cl;
	while (defCl != nullptr) {
		try {
			$assign(meth, defCl->getDeclaredMethod(name, argTypes));
			break;
		} catch ($NoSuchMethodException& ex) {
			defCl = defCl->getSuperclass();
		}
	}
	if ((meth == nullptr) || ($nc(meth)->getReturnType() != returnType)) {
		return nullptr;
	}
	$nc(meth)->setAccessible(true);
	int32_t mods = meth->getModifiers();
	if (((int32_t)(mods & (uint32_t)($Modifier::STATIC | $Modifier::ABSTRACT))) != 0) {
		return nullptr;
	} else if (((int32_t)(mods & (uint32_t)($Modifier::PUBLIC | $Modifier::PROTECTED))) != 0) {
		return meth;
	} else if (((int32_t)(mods & (uint32_t)$Modifier::PRIVATE)) != 0) {
		return (cl == defCl) ? meth : ($Method*)nullptr;
	} else {
		return packageEquals(cl, defCl) ? meth : ($Method*)nullptr;
	}
}

$Method* ObjectStreamClass::getPrivateMethod($Class* cl, $String* name, $ClassArray* argTypes, $Class* returnType) {
	$init(ObjectStreamClass);
	$beforeCallerSensitive();
	try {
		$var($Method, meth, $nc(cl)->getDeclaredMethod(name, argTypes));
		$nc(meth)->setAccessible(true);
		int32_t mods = meth->getModifiers();
		return ((meth->getReturnType() == returnType) && (((int32_t)(mods & (uint32_t)$Modifier::STATIC)) == 0) && (((int32_t)(mods & (uint32_t)$Modifier::PRIVATE)) != 0)) ? meth : ($Method*)nullptr;
	} catch ($NoSuchMethodException& ex) {
		return nullptr;
	}
	$shouldNotReachHere();
}

bool ObjectStreamClass::packageEquals($Class* cl1, $Class* cl2) {
	$init(ObjectStreamClass);
	$beforeCallerSensitive();
	bool var$0 = $nc(cl1)->getClassLoader() == $nc(cl2)->getClassLoader();
	if (var$0) {
		var$0 = cl1->getPackageName() == cl2->getPackageName();
	}
	return var$0;
}

bool ObjectStreamClass::classNamesEqual($String* name1, $String* name2) {
	$init(ObjectStreamClass);
	int32_t idx1 = $nc(name1)->lastIndexOf((int32_t)u'.') + 1;
	int32_t idx2 = $nc(name2)->lastIndexOf((int32_t)u'.') + 1;
	int32_t len1 = name1->length() - idx1;
	int32_t len2 = name2->length() - idx2;
	return len1 == len2 && name1->regionMatches(idx1, name2, idx2, len1);
}

$String* ObjectStreamClass::getMethodSignature($ClassArray* paramTypes, $Class* retType) {
	$init(ObjectStreamClass);
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(u'(');
	for (int32_t i = 0; i < $nc(paramTypes)->length; ++i) {
		$ObjectStreamField::appendClassSignature(sb, paramTypes->get(i));
	}
	sb->append(u')');
	$ObjectStreamField::appendClassSignature(sb, retType);
	return sb->toString();
}

void ObjectStreamClass::throwMiscException($Throwable* th) {
	$init(ObjectStreamClass);
	if ($instanceOf($RuntimeException, th)) {
		$throw($cast($RuntimeException, th));
	} else if ($instanceOf($Error, th)) {
		$throw($cast($Error, th));
	} else {
		$var($IOException, ex, $new($IOException, "unexpected exception type"_s));
		ex->initCause(th);
		$throw(ex);
	}
}

$ObjectStreamFieldArray* ObjectStreamClass::getSerialFields($Class* cl) {
	$init(ObjectStreamClass);
	$load($Serializable);
	if (!$Serializable::class$->isAssignableFrom(cl)) {
		return ObjectStreamClass::NO_FIELDS;
	}
	$var($ObjectStreamFieldArray, fields, nullptr);
	if ($nc(cl)->isRecord()) {
		$assign(fields, getDefaultSerialFields(cl));
		$Arrays::sort(fields);
	} else {
		$load($Externalizable);
		bool var$3 = !$Externalizable::class$->isAssignableFrom(cl);
		bool var$2 = var$3 && !$Proxy::isProxyClass(cl);
		if (var$2 && !cl->isInterface()) {
			if (($assign(fields, getDeclaredSerialFields(cl))) == nullptr) {
				$assign(fields, getDefaultSerialFields(cl));
			}
			$Arrays::sort(fields);
		} else {
			$assign(fields, ObjectStreamClass::NO_FIELDS);
		}
	}
	return fields;
}

$ObjectStreamFieldArray* ObjectStreamClass::getDeclaredSerialFields($Class* cl) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ObjectStreamFieldArray, serialPersistentFields, nullptr);
	try {
		$var($Field, f, $nc(cl)->getDeclaredField("serialPersistentFields"_s));
		int32_t mask = ($Modifier::PRIVATE | $Modifier::STATIC) | $Modifier::FINAL;
		if (((int32_t)($nc(f)->getModifiers() & (uint32_t)mask)) == mask) {
			f->setAccessible(true);
			$assign(serialPersistentFields, $cast($ObjectStreamFieldArray, f->get(nullptr)));
		}
	} catch ($Exception& ex) {
	}
	if (serialPersistentFields == nullptr) {
		return nullptr;
	} else if ($nc(serialPersistentFields)->length == 0) {
		return ObjectStreamClass::NO_FIELDS;
	}
	$var($ObjectStreamFieldArray, boundFields, $new($ObjectStreamFieldArray, $nc(serialPersistentFields)->length));
	$var($Set, fieldNames, $new($HashSet, serialPersistentFields->length));
	for (int32_t i = 0; i < serialPersistentFields->length; ++i) {
		$var($ObjectStreamField, spf, serialPersistentFields->get(i));
		$var($String, fname, $nc(spf)->getName());
		if (fieldNames->contains(fname)) {
			$throwNew($InvalidClassException, $$str({"multiple serializable fields named "_s, fname}));
		}
		fieldNames->add(fname);
		try {
			$var($Field, f, $nc(cl)->getDeclaredField(fname));
			bool var$0 = ($nc(f)->getType() == spf->getType());
			if (var$0 && (((int32_t)(f->getModifiers() & (uint32_t)$Modifier::STATIC)) == 0)) {
				boundFields->set(i, $$new($ObjectStreamField, f, spf->isUnshared(), true));
			}
		} catch ($NoSuchFieldException& ex) {
		}
		if (boundFields->get(i) == nullptr) {
			$var($String, var$1, fname);
			$Class* var$2 = spf->getType();
			boundFields->set(i, $$new($ObjectStreamField, var$1, var$2, spf->isUnshared()));
		}
	}
	return boundFields;
}

$ObjectStreamFieldArray* ObjectStreamClass::getDefaultSerialFields($Class* cl) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($FieldArray, clFields, $nc(cl)->getDeclaredFields());
	$var($ArrayList, list, $new($ArrayList));
	int32_t mask = $Modifier::STATIC | $Modifier::TRANSIENT;
	for (int32_t i = 0; i < $nc(clFields)->length; ++i) {
		if (((int32_t)($nc(clFields->get(i))->getModifiers() & (uint32_t)mask)) == 0) {
			list->add($$new($ObjectStreamField, clFields->get(i), false, true));
		}
	}
	int32_t size = list->size();
	return (size == 0) ? ObjectStreamClass::NO_FIELDS : $fcast($ObjectStreamFieldArray, list->toArray($$new($ObjectStreamFieldArray, size)));
}

$Long* ObjectStreamClass::getDeclaredSUID($Class* cl) {
	$init(ObjectStreamClass);
	$beforeCallerSensitive();
	try {
		$var($Field, f, $nc(cl)->getDeclaredField("serialVersionUID"_s));
		int32_t mask = $Modifier::STATIC | $Modifier::FINAL;
		if (((int32_t)($nc(f)->getModifiers() & (uint32_t)mask)) == mask) {
			f->setAccessible(true);
			return $Long::valueOf(f->getLong(nullptr));
		}
	} catch ($Exception& ex) {
	}
	return nullptr;
}

int64_t ObjectStreamClass::computeDefaultSUID($Class* cl) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($Serializable);
	bool var$0 = !$Serializable::class$->isAssignableFrom(cl);
	if (var$0 || $Proxy::isProxyClass(cl)) {
		return 0;
	}
	try {
		$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream));
		$var($DataOutputStream, dout, $new($DataOutputStream, bout));
		dout->writeUTF($($nc(cl)->getName()));
		int32_t classMods = (int32_t)($nc(cl)->getModifiers() & (uint32_t)((($Modifier::PUBLIC | $Modifier::FINAL) | $Modifier::INTERFACE) | $Modifier::ABSTRACT));
		$var($MethodArray, methods, cl->getDeclaredMethods());
		if (((int32_t)(classMods & (uint32_t)$Modifier::INTERFACE)) != 0) {
			classMods = ($nc(methods)->length > 0) ? (classMods | $Modifier::ABSTRACT) : ((int32_t)(classMods & (uint32_t)~$Modifier::ABSTRACT));
		}
		dout->writeInt(classMods);
		if (!cl->isArray()) {
			$var($ClassArray, interfaces, cl->getInterfaces());
			$var($StringArray, ifaceNames, $new($StringArray, interfaces->length));
			for (int32_t i = 0; i < interfaces->length; ++i) {
				ifaceNames->set(i, $($nc(interfaces->get(i))->getName()));
			}
			$Arrays::sort(ifaceNames);
			for (int32_t i = 0; i < ifaceNames->length; ++i) {
				dout->writeUTF(ifaceNames->get(i));
			}
		}
		$var($FieldArray, fields, cl->getDeclaredFields());
		$var($ObjectStreamClass$MemberSignatureArray, fieldSigs, $new($ObjectStreamClass$MemberSignatureArray, $nc(fields)->length));
		for (int32_t i = 0; i < fields->length; ++i) {
			fieldSigs->set(i, $$new($ObjectStreamClass$MemberSignature, fields->get(i)));
		}
		$Arrays::sort(fieldSigs, $$new($ObjectStreamClass$3));
		for (int32_t i = 0; i < fieldSigs->length; ++i) {
			$var($ObjectStreamClass$MemberSignature, sig, fieldSigs->get(i));
			int32_t mods = (int32_t)($nc($nc(sig)->member)->getModifiers() & (uint32_t)(((((($Modifier::PUBLIC | $Modifier::PRIVATE) | $Modifier::PROTECTED) | $Modifier::STATIC) | $Modifier::FINAL) | $Modifier::VOLATILE) | $Modifier::TRANSIENT));
			if ((((int32_t)(mods & (uint32_t)$Modifier::PRIVATE)) == 0) || (((int32_t)(mods & (uint32_t)($Modifier::STATIC | $Modifier::TRANSIENT))) == 0)) {
				dout->writeUTF(sig->name);
				dout->writeInt(mods);
				dout->writeUTF(sig->signature);
			}
		}
		if (hasStaticInitializer(cl)) {
			dout->writeUTF("<clinit>"_s);
			dout->writeInt($Modifier::STATIC);
			dout->writeUTF("()V"_s);
		}
		$var($ConstructorArray, cons, cl->getDeclaredConstructors());
		$var($ObjectStreamClass$MemberSignatureArray, consSigs, $new($ObjectStreamClass$MemberSignatureArray, $nc(cons)->length));
		for (int32_t i = 0; i < cons->length; ++i) {
			consSigs->set(i, $$new($ObjectStreamClass$MemberSignature, cons->get(i)));
		}
		$Arrays::sort(consSigs, $$new($ObjectStreamClass$4));
		for (int32_t i = 0; i < consSigs->length; ++i) {
			$var($ObjectStreamClass$MemberSignature, sig, consSigs->get(i));
			int32_t mods = (int32_t)($nc($nc(sig)->member)->getModifiers() & (uint32_t)(((((((($Modifier::PUBLIC | $Modifier::PRIVATE) | $Modifier::PROTECTED) | $Modifier::STATIC) | $Modifier::FINAL) | $Modifier::SYNCHRONIZED) | $Modifier::NATIVE) | $Modifier::ABSTRACT) | $Modifier::STRICT));
			if (((int32_t)(mods & (uint32_t)$Modifier::PRIVATE)) == 0) {
				dout->writeUTF("<init>"_s);
				dout->writeInt(mods);
				dout->writeUTF($($nc(sig->signature)->replace(u'/', u'.')));
			}
		}
		$var($ObjectStreamClass$MemberSignatureArray, methSigs, $new($ObjectStreamClass$MemberSignatureArray, $nc(methods)->length));
		for (int32_t i = 0; i < methods->length; ++i) {
			methSigs->set(i, $$new($ObjectStreamClass$MemberSignature, methods->get(i)));
		}
		$Arrays::sort(methSigs, $$new($ObjectStreamClass$5));
		for (int32_t i = 0; i < methSigs->length; ++i) {
			$var($ObjectStreamClass$MemberSignature, sig, methSigs->get(i));
			int32_t mods = (int32_t)($nc($nc(sig)->member)->getModifiers() & (uint32_t)(((((((($Modifier::PUBLIC | $Modifier::PRIVATE) | $Modifier::PROTECTED) | $Modifier::STATIC) | $Modifier::FINAL) | $Modifier::SYNCHRONIZED) | $Modifier::NATIVE) | $Modifier::ABSTRACT) | $Modifier::STRICT));
			if (((int32_t)(mods & (uint32_t)$Modifier::PRIVATE)) == 0) {
				dout->writeUTF(sig->name);
				dout->writeInt(mods);
				dout->writeUTF($($nc(sig->signature)->replace(u'/', u'.')));
			}
		}
		dout->flush();
		$var($MessageDigest, md, $MessageDigest::getInstance("SHA"_s));
		$var($bytes, hashBytes, $nc(md)->digest($(bout->toByteArray())));
		int64_t hash = 0;
		for (int32_t i = $Math::min($nc(hashBytes)->length, 8) - 1; i >= 0; --i) {
			hash = (hash << 8) | ((int32_t)($nc(hashBytes)->get(i) & (uint32_t)255));
		}
		return hash;
	} catch ($IOException& ex) {
		$throwNew($InternalError, static_cast<$Throwable*>(ex));
	} catch ($NoSuchAlgorithmException& ex) {
		$throwNew($SecurityException, $(ex->getMessage()));
	}
	$shouldNotReachHere();
}

bool ObjectStreamClass::hasStaticInitializer($Class* cl) {
	$init(ObjectStreamClass);
	bool $ret = false;
	$prepareNativeStatic(ObjectStreamClass, hasStaticInitializer, bool, $Class* cl);
	$ret = $invokeNativeStatic(cl);
	$finishNativeStatic();
	return $ret;
}

$ObjectStreamClass$FieldReflector* ObjectStreamClass::getReflector($ObjectStreamFieldArray* fields, ObjectStreamClass* localDesc) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$Class* cl = (localDesc != nullptr && $nc(fields)->length > 0) ? $nc(localDesc)->cl : ($Class*)nullptr;
	$init($ObjectStreamClass$Caches);
	processQueue($ObjectStreamClass$Caches::reflectorsQueue, $ObjectStreamClass$Caches::reflectors);
	$var($ObjectStreamClass$FieldReflectorKey, key, $new($ObjectStreamClass$FieldReflectorKey, cl, fields, $ObjectStreamClass$Caches::reflectorsQueue));
	$var($Reference, ref, $cast($Reference, $nc($ObjectStreamClass$Caches::reflectors)->get(key)));
	$var($Object, entry, nullptr);
	if (ref != nullptr) {
		$assign(entry, ref->get());
	}
	$var($ObjectStreamClass$EntryFuture, future, nullptr);
	if (entry == nullptr) {
		$var($ObjectStreamClass$EntryFuture, newEntry, $new($ObjectStreamClass$EntryFuture));
		$var($Reference, newRef, $new($SoftReference, newEntry));
		do {
			if (ref != nullptr) {
				$nc($ObjectStreamClass$Caches::reflectors)->remove(key, ref);
			}
			$assign(ref, $cast($Reference, $nc($ObjectStreamClass$Caches::reflectors)->putIfAbsent(key, newRef)));
			if (ref != nullptr) {
				$assign(entry, ref->get());
			}
		} while (ref != nullptr && entry == nullptr);
		if (entry == nullptr) {
			$assign(future, newEntry);
		}
	}
	if ($instanceOf($ObjectStreamClass$FieldReflector, entry)) {
		return $cast($ObjectStreamClass$FieldReflector, entry);
	} else if ($instanceOf($ObjectStreamClass$EntryFuture, entry)) {
		$assign(entry, $nc(($cast($ObjectStreamClass$EntryFuture, entry)))->get());
	} else if (entry == nullptr) {
		try {
			$assign(entry, $new($ObjectStreamClass$FieldReflector, $(matchFields(fields, localDesc))));
		} catch ($Throwable& th) {
			$assign(entry, th);
		}
		$nc(future)->set(entry);
		$nc($ObjectStreamClass$Caches::reflectors)->put(key, $$new($SoftReference, entry));
	}
	if ($instanceOf($ObjectStreamClass$FieldReflector, entry)) {
		return $cast($ObjectStreamClass$FieldReflector, entry);
	} else if ($instanceOf($InvalidClassException, entry)) {
		$throw($cast($InvalidClassException, entry));
	} else if ($instanceOf($RuntimeException, entry)) {
		$throw($cast($RuntimeException, entry));
	} else if ($instanceOf($Error, entry)) {
		$throw($cast($Error, entry));
	} else {
		$throwNew($InternalError, $$str({"unexpected entry: "_s, entry}));
	}
}

$ObjectStreamFieldArray* ObjectStreamClass::matchFields($ObjectStreamFieldArray* fields, ObjectStreamClass* localDesc) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$var($ObjectStreamFieldArray, localFields, (localDesc != nullptr) ? $nc(localDesc)->fields : ObjectStreamClass::NO_FIELDS);
	$var($ObjectStreamFieldArray, matches, $new($ObjectStreamFieldArray, $nc(fields)->length));
	for (int32_t i = 0; i < fields->length; ++i) {
		$var($ObjectStreamField, f, fields->get(i));
		$var($ObjectStreamField, m, nullptr);
		for (int32_t j = 0; j < $nc(localFields)->length; ++j) {
			$var($ObjectStreamField, lf, localFields->get(j));
			if ($nc($($nc(f)->getName()))->equals($($nc(lf)->getName()))) {
				bool var$1 = f->isPrimitive();
				bool var$0 = (var$1 || $nc(lf)->isPrimitive());
				if (var$0) {
					char16_t var$2 = f->getTypeCode();
					var$0 = var$2 != lf->getTypeCode();
				}
				if (var$0) {
					$throwNew($InvalidClassException, localDesc->name, $$str({"incompatible types for field "_s, $(f->getName())}));
				}
				if ($nc(lf)->getField() != nullptr) {
					$var($Field, var$3, lf->getField());
					$assign(m, $new($ObjectStreamField, var$3, lf->isUnshared(), false));
				} else {
					$var($String, var$4, lf->getName());
					$var($String, var$5, lf->getSignature());
					$assign(m, $new($ObjectStreamField, var$4, var$5, lf->isUnshared()));
				}
			}
		}
		if (m == nullptr) {
			$var($String, var$6, $nc(f)->getName());
			$assign(m, $new($ObjectStreamField, var$6, $(f->getSignature()), false));
		}
		$nc(m)->setOffset($nc(f)->getOffset());
		matches->set(i, m);
	}
	return matches;
}

void ObjectStreamClass::processQueue($ReferenceQueue* queue, $ConcurrentMap* map) {
	$init(ObjectStreamClass);
	$var($Reference, ref, nullptr);
	while (($assign(ref, $nc(queue)->poll())) != nullptr) {
		$nc(map)->remove(ref);
	}
}

$MethodHandle* ObjectStreamClass::lambda$canonicalRecordCtr$2($Class* cls) {
	$init(ObjectStreamClass);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassArray, paramTypes, $fcast($ClassArray, $nc($($nc($($Arrays::stream($($nc(cls)->getRecordComponents()))))->map(static_cast<$Function*>($$new(ObjectStreamClass$$Lambda$getType$2)))))->toArray(static_cast<$IntFunction*>($$new(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3)))));
	try {
		$var($Constructor, ctr, $nc(cls)->getDeclaredConstructor(paramTypes));
		$nc(ctr)->setAccessible(true);
		return $nc($($MethodHandles::lookup()))->unreflectConstructor(ctr);
	} catch ($IllegalAccessException& e) {
		return nullptr;
	} catch ($NoSuchMethodException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$ClassArray* ObjectStreamClass::lambda$canonicalRecordCtr$1(int32_t x$0) {
	$init(ObjectStreamClass);
	return $new($ClassArray, x$0);
}

$Object* ObjectStreamClass::lambda$newInstance$0() {
	$beforeCallerSensitive();
	try {
		return $of($nc(this->cons)->newInstance($$new($ObjectArray, 0)));
	} catch ($InstantiationException& x) {
		$throwNew($UndeclaredThrowableException, x);
	} catch ($InvocationTargetException& x) {
		$throwNew($UndeclaredThrowableException, x);
	} catch ($IllegalAccessException& x) {
		$throwNew($UndeclaredThrowableException, x);
	}
	$shouldNotReachHere();
}

void clinit$ObjectStreamClass($Class* class$) {
	$beforeCallerSensitive();
	ObjectStreamClass::$assertionsDisabled = !ObjectStreamClass::class$->desiredAssertionStatus();
	$assignStatic(ObjectStreamClass::NO_FIELDS, $new($ObjectStreamFieldArray, 0));
	$assignStatic(ObjectStreamClass::serialPersistentFields, ObjectStreamClass::NO_FIELDS);
	$assignStatic(ObjectStreamClass::reflFactory, $cast($ReflectionFactory, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ReflectionFactory$GetReflectionFactoryAction)))));
	{
		ObjectStreamClass::initNative();
	}
}

ObjectStreamClass::ObjectStreamClass() {
}

$Class* ObjectStreamClass::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ObjectStreamClass$$Lambda$lambda$newInstance$0::classInfo$.name)) {
			return ObjectStreamClass$$Lambda$lambda$newInstance$0::load$(name, initialize);
		}
		if (name->equals(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::classInfo$.name)) {
			return ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$2$1::load$(name, initialize);
		}
		if (name->equals(ObjectStreamClass$$Lambda$getType$2::classInfo$.name)) {
			return ObjectStreamClass$$Lambda$getType$2::load$(name, initialize);
		}
		if (name->equals(ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3::classInfo$.name)) {
			return ObjectStreamClass$$Lambda$lambda$canonicalRecordCtr$1$3::load$(name, initialize);
		}
	}
	$loadClass(ObjectStreamClass, name, initialize, &_ObjectStreamClass_ClassInfo_, clinit$ObjectStreamClass, allocate$ObjectStreamClass);
	return class$;
}

$Class* ObjectStreamClass::class$ = nullptr;

	} // io
} // java