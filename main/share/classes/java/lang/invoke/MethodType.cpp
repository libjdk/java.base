#include <java/lang/invoke/MethodType.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/constant/ClassDesc.h>
#include <java/lang/constant/Constable.h>
#include <java/lang/constant/MethodTypeDesc.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/Invokers.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType$ConcurrentWeakInternSet$WeakEntry.h>
#include <java/lang/invoke/MethodType$ConcurrentWeakInternSet.h>
#include <java/lang/invoke/MethodType$OffsetHolder.h>
#include <java/lang/invoke/MethodTypeForm.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/TypeDescriptor$OfMethod.h>
#include <java/lang/ref/Reference.h>
#include <java/security/Permission.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/StringJoiner.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/invoke/util/BytecodeDescriptor.h>
#include <sun/invoke/util/VerifyType.h>
#include <sun/invoke/util/Wrapper.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef GET_CLASSLOADER_PERMISSION
#undef MAX_JVM_ARITY
#undef MAX_MH_ARITY
#undef MAX_MH_INVOKER_ARITY
#undef METHOD_HANDLE_ARRAY
#undef NO_PTYPES
#undef TYPE
#undef UNSAFE
#undef UNWRAP
#undef WRAP

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $ClassDescArray = $Array<::java::lang::constant::ClassDesc>;
using $MethodTypeArray = $Array<::java::lang::invoke::MethodType>;
using $TypeDescriptor$OfFieldArray = $Array<::java::lang::invoke::TypeDescriptor$OfField>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $ClassDesc = ::java::lang::constant::ClassDesc;
using $Constable = ::java::lang::constant::Constable;
using $MethodTypeDesc = ::java::lang::constant::MethodTypeDesc;
using $Invokers = ::java::lang::invoke::Invokers;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodType$ConcurrentWeakInternSet = ::java::lang::invoke::MethodType$ConcurrentWeakInternSet;
using $MethodType$ConcurrentWeakInternSet$WeakEntry = ::java::lang::invoke::MethodType$ConcurrentWeakInternSet$WeakEntry;
using $MethodType$OffsetHolder = ::java::lang::invoke::MethodType$OffsetHolder;
using $MethodTypeForm = ::java::lang::invoke::MethodTypeForm;
using $TypeDescriptor$OfField = ::java::lang::invoke::TypeDescriptor$OfField;
using $TypeDescriptor$OfMethod = ::java::lang::invoke::TypeDescriptor$OfMethod;
using $Permission = ::java::security::Permission;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $StringJoiner = ::java::util::StringJoiner;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Stream = ::java::util::stream::Stream;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $BytecodeDescriptor = ::sun::invoke::util::BytecodeDescriptor;
using $VerifyType = ::sun::invoke::util::VerifyType;
using $Wrapper = ::sun::invoke::util::Wrapper;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {
		namespace invoke {

class MethodType$$Lambda$lambda$describeConstable$0 : public $Function {
	$class(MethodType$$Lambda$lambda$describeConstable$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* p) override {
		 return $of(MethodType::lambda$describeConstable$0($cast($Class, p)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodType$$Lambda$lambda$describeConstable$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MethodType$$Lambda$lambda$describeConstable$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MethodType$$Lambda$lambda$describeConstable$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MethodType$$Lambda$lambda$describeConstable$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo MethodType$$Lambda$lambda$describeConstable$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodType$$Lambda$lambda$describeConstable$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MethodType$$Lambda$lambda$describeConstable$0::load$($String* name, bool initialize) {
	$loadClass(MethodType$$Lambda$lambda$describeConstable$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodType$$Lambda$lambda$describeConstable$0::class$ = nullptr;

class MethodType$$Lambda$lambda$describeConstable$1$1 : public $IntFunction {
	$class(MethodType$$Lambda$lambda$describeConstable$1$1, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(MethodType::lambda$describeConstable$1(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodType$$Lambda$lambda$describeConstable$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MethodType$$Lambda$lambda$describeConstable$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MethodType$$Lambda$lambda$describeConstable$1$1, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MethodType$$Lambda$lambda$describeConstable$1$1, apply, $Object*, int32_t)},
	{}
};
$ClassInfo MethodType$$Lambda$lambda$describeConstable$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodType$$Lambda$lambda$describeConstable$1$1",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* MethodType$$Lambda$lambda$describeConstable$1$1::load$($String* name, bool initialize) {
	$loadClass(MethodType$$Lambda$lambda$describeConstable$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodType$$Lambda$lambda$describeConstable$1$1::class$ = nullptr;

$CompoundAttribute _MethodType_FieldAnnotations_rtype[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_ptypes[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_form[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_wrapAlt[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_invokers[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_methodDescriptor[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_objectOnlyTypes[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodType_FieldAnnotations_METHOD_HANDLE_ARRAY[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _MethodType_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodType, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MethodType, serialVersionUID)},
	{"rtype", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(MethodType, rtype$), _MethodType_FieldAnnotations_rtype},
	{"ptypes", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(MethodType, ptypes$), _MethodType_FieldAnnotations_ptypes},
	{"form", "Ljava/lang/invoke/MethodTypeForm;", nullptr, $PRIVATE, $field(MethodType, form$), _MethodType_FieldAnnotations_form},
	{"wrapAlt", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(MethodType, wrapAlt), _MethodType_FieldAnnotations_wrapAlt},
	{"invokers", "Ljava/lang/invoke/Invokers;", nullptr, $PRIVATE, $field(MethodType, invokers$), _MethodType_FieldAnnotations_invokers},
	{"methodDescriptor", "Ljava/lang/String;", nullptr, $PRIVATE, $field(MethodType, methodDescriptor), _MethodType_FieldAnnotations_methodDescriptor},
	{"MAX_JVM_ARITY", "I", nullptr, $STATIC | $FINAL, $constField(MethodType, MAX_JVM_ARITY)},
	{"MAX_MH_ARITY", "I", nullptr, $STATIC | $FINAL, $constField(MethodType, MAX_MH_ARITY)},
	{"MAX_MH_INVOKER_ARITY", "I", nullptr, $STATIC | $FINAL, $constField(MethodType, MAX_MH_INVOKER_ARITY)},
	{"internTable", "Ljava/lang/invoke/MethodType$ConcurrentWeakInternSet;", "Ljava/lang/invoke/MethodType$ConcurrentWeakInternSet<Ljava/lang/invoke/MethodType;>;", $STATIC | $FINAL, $staticField(MethodType, internTable)},
	{"NO_PTYPES", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $STATIC | $FINAL, $staticField(MethodType, NO_PTYPES)},
	{"objectOnlyTypes", "[Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodType, objectOnlyTypes), _MethodType_FieldAnnotations_objectOnlyTypes},
	{"METHOD_HANDLE_ARRAY", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(MethodType, METHOD_HANDLE_ARRAY), _MethodType_FieldAnnotations_METHOD_HANDLE_ARRAY},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodType, serialPersistentFields)},
	{}
};

$MethodInfo _MethodType_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/Class;[Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)V", $PRIVATE, $method(MethodType, init$, void, $Class*, $ClassArray*)},
	{"appendParameterTypes", "([Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "([Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $TRANSIENT, $method(MethodType, appendParameterTypes, MethodType*, $ClassArray*)},
	{"appendParameterTypes", "(Ljava/util/List;)Ljava/lang/invoke/MethodType;", "(Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/invoke/MethodType;", $PUBLIC, $method(MethodType, appendParameterTypes, MethodType*, $List*)},
	{"asCollectorType", "(Ljava/lang/Class;II)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;II)Ljava/lang/invoke/MethodType;", 0, $method(MethodType, asCollectorType, MethodType*, $Class*, int32_t, int32_t)},
	{"asSpreaderType", "(Ljava/lang/Class;II)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;II)Ljava/lang/invoke/MethodType;", 0, $method(MethodType, asSpreaderType, MethodType*, $Class*, int32_t, int32_t)},
	{"basicType", "()Ljava/lang/invoke/MethodType;", nullptr, 0, $method(MethodType, basicType, MethodType*)},
	{"canConvert", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $STATIC, $staticMethod(MethodType, canConvert, bool, $Class*, $Class*)},
	{"canConvertParameters", "([Ljava/lang/Class;[Ljava/lang/Class;)Z", "([Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Z", $PRIVATE, $method(MethodType, canConvertParameters, bool, $ClassArray*, $ClassArray*)},
	{"changeParameterType", "(ILjava/lang/Class;)Ljava/lang/invoke/MethodType;", "(ILjava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC, $method(MethodType, changeParameterType, MethodType*, int32_t, $Class*)},
	{"changeParameterType", "(ILjava/lang/invoke/TypeDescriptor$OfField;)Ljava/lang/invoke/TypeDescriptor$OfMethod;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MethodType, changeParameterType, $TypeDescriptor$OfMethod*, int32_t, $TypeDescriptor$OfField*)},
	{"changeReturnType", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC, $method(MethodType, changeReturnType, MethodType*, $Class*)},
	{"changeReturnType", "(Ljava/lang/invoke/TypeDescriptor$OfField;)Ljava/lang/invoke/TypeDescriptor$OfMethod;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MethodType, changeReturnType, $TypeDescriptor$OfMethod*, $TypeDescriptor$OfField*)},
	{"checkPtypes", "([Ljava/lang/Class;)I", "([Ljava/lang/Class<*>;)I", $PRIVATE | $STATIC, $staticMethod(MethodType, checkPtypes, int32_t, $ClassArray*)},
	{"checkSlotCount", "(I)V", nullptr, $STATIC, $staticMethod(MethodType, checkSlotCount, void, int32_t)},
	{"describeConstable", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/constant/MethodTypeDesc;>;", $PUBLIC, $virtualMethod(MethodType, describeConstable, $Optional*)},
	{"descriptorString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MethodType, descriptorString, $String*)},
	{"dropParameterTypes", "(II)Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC, $virtualMethod(MethodType, dropParameterTypes, $TypeDescriptor$OfMethod*, int32_t, int32_t)},
	{"effectivelyIdenticalParameters", "(ILjava/util/List;)Z", "(ILjava/util/List<Ljava/lang/Class<*>;>;)Z", 0, $method(MethodType, effectivelyIdenticalParameters, bool, int32_t, $List*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(MethodType, equals, bool, Object$*)},
	{"equals", "(Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE, $method(MethodType, equals, bool, MethodType*)},
	{"erase", "()Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC, $method(MethodType, erase, MethodType*)},
	{"explicitCastEquivalentToAsType", "(Ljava/lang/invoke/MethodType;)Z", nullptr, 0, $method(MethodType, explicitCastEquivalentToAsType, bool, MethodType*)},
	{"explicitCastEquivalentToAsType", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(MethodType, explicitCastEquivalentToAsType, bool, $Class*, $Class*)},
	{"form", "()Ljava/lang/invoke/MethodTypeForm;", nullptr, 0, $method(MethodType, form, $MethodTypeForm*)},
	{"fromDescriptor", "(Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/invoke/MethodType;", nullptr, $STATIC, $staticMethod(MethodType, fromDescriptor, MethodType*, $String*, $ClassLoader*), "java.lang.IllegalArgumentException,java.lang.TypeNotPresentException"},
	{"fromMethodDescriptorString", "(Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC | $STATIC, $staticMethod(MethodType, fromMethodDescriptorString, MethodType*, $String*, $ClassLoader*), "java.lang.IllegalArgumentException,java.lang.TypeNotPresentException"},
	{"generic", "()Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC, $method(MethodType, generic, MethodType*)},
	{"genericMethodType", "(IZ)Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC | $STATIC, $staticMethod(MethodType, genericMethodType, MethodType*, int32_t, bool)},
	{"genericMethodType", "(I)Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC | $STATIC, $staticMethod(MethodType, genericMethodType, MethodType*, int32_t)},
	{"hasPrimitives", "()Z", nullptr, $PUBLIC, $method(MethodType, hasPrimitives, bool)},
	{"hasWrappers", "()Z", nullptr, $PUBLIC, $method(MethodType, hasWrappers, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(MethodType, hashCode, int32_t)},
	{"insertParameterTypes", "(I[Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(I[Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $TRANSIENT, $method(MethodType, insertParameterTypes, MethodType*, int32_t, $ClassArray*)},
	{"insertParameterTypes", "(ILjava/util/List;)Ljava/lang/invoke/MethodType;", "(ILjava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/invoke/MethodType;", $PUBLIC, $method(MethodType, insertParameterTypes, MethodType*, int32_t, $List*)},
	{"insertParameterTypes", "(I[Ljava/lang/invoke/TypeDescriptor$OfField;)Ljava/lang/invoke/TypeDescriptor$OfMethod;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(MethodType, insertParameterTypes, $TypeDescriptor$OfMethod*, int32_t, $TypeDescriptor$OfFieldArray*)},
	{"invokerType", "()Ljava/lang/invoke/MethodType;", nullptr, 0, $method(MethodType, invokerType, MethodType*)},
	{"invokers", "()Ljava/lang/invoke/Invokers;", nullptr, 0, $method(MethodType, invokers, $Invokers*)},
	{"isConvertibleTo", "(Ljava/lang/invoke/MethodType;)Z", nullptr, 0, $method(MethodType, isConvertibleTo, bool, MethodType*)},
	{"isGeneric", "()Z", nullptr, 0, $method(MethodType, isGeneric, bool)},
	{"isViewableAs", "(Ljava/lang/invoke/MethodType;Z)Z", nullptr, 0, $method(MethodType, isViewableAs, bool, MethodType*, bool)},
	{"lambda$describeConstable$0", "(Ljava/lang/Class;)Ljava/lang/constant/ClassDesc;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MethodType, lambda$describeConstable$0, $ClassDesc*, $Class*)},
	{"lambda$describeConstable$1", "(I)[Ljava/lang/constant/ClassDesc;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MethodType, lambda$describeConstable$1, $ClassDescArray*, int32_t)},
	{"lastParameterType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(MethodType, lastParameterType, $Class*)},
	{"leadingReferenceParameter", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", 0, $method(MethodType, leadingReferenceParameter, $Class*)},
	{"listToArray", "(Ljava/util/List;)[Ljava/lang/Class;", "(Ljava/util/List<Ljava/lang/Class<*>;>;)[Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(MethodType, listToArray, $ClassArray*, $List*)},
	{"makeImpl", "(Ljava/lang/Class;[Ljava/lang/Class;Z)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;[Ljava/lang/Class<*>;Z)Ljava/lang/invoke/MethodType;", $STATIC, $staticMethod(MethodType, makeImpl, MethodType*, $Class*, $ClassArray*, bool)},
	{"methodType", "(Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $STATIC, $staticMethod(MethodType, methodType, MethodType*, $Class*, $ClassArray*)},
	{"methodType", "(Ljava/lang/Class;Ljava/util/List;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $STATIC, $staticMethod(MethodType, methodType, MethodType*, $Class*, $List*)},
	{"methodType", "(Ljava/lang/Class;Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(MethodType, methodType, MethodType*, $Class*, $Class*, $ClassArray*)},
	{"methodType", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $STATIC, $staticMethod(MethodType, methodType, MethodType*, $Class*)},
	{"methodType", "(Ljava/lang/Class;Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $PUBLIC | $STATIC, $staticMethod(MethodType, methodType, MethodType*, $Class*, $Class*)},
	{"methodType", "(Ljava/lang/Class;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodType;", $PUBLIC | $STATIC, $staticMethod(MethodType, methodType, MethodType*, $Class*, MethodType*)},
	{"newIndexOutOfBoundsException", "(Ljava/lang/Object;)Ljava/lang/IndexOutOfBoundsException;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodType, newIndexOutOfBoundsException, $IndexOutOfBoundsException*, Object$*)},
	{"parameterArray", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(MethodType, parameterArray, $TypeDescriptor$OfFieldArray*)},
	{"parameterCount", "()I", nullptr, $PUBLIC, $virtualMethod(MethodType, parameterCount, int32_t)},
	{"parameterList", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Class<*>;>;", $PUBLIC, $virtualMethod(MethodType, parameterList, $List*)},
	{"parameterSlotCount", "()I", nullptr, 0, $method(MethodType, parameterSlotCount, int32_t)},
	{"parameterType", "(I)Ljava/lang/Class;", "(I)Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(MethodType, parameterType, $TypeDescriptor$OfField*, int32_t)},
	{"ptypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", 0, $method(MethodType, ptypes, $ClassArray*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(MethodType, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(MethodType, readResolve, $Object*)},
	{"replaceParameterTypes", "(II[Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(II[Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $TRANSIENT, $method(MethodType, replaceParameterTypes, MethodType*, int32_t, int32_t, $ClassArray*)},
	{"returnType", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(MethodType, returnType, $TypeDescriptor$OfField*)},
	{"rtype", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", 0, $method(MethodType, rtype, $Class*)},
	{"setForm", "(Ljava/lang/invoke/MethodTypeForm;)V", nullptr, 0, $method(MethodType, setForm, void, $MethodTypeForm*)},
	{"toFieldDescriptorString", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $STATIC, $staticMethod(MethodType, toFieldDescriptorString, $String*, $Class*)},
	{"toMethodDescriptorString", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(MethodType, toMethodDescriptorString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MethodType, toString, $String*)},
	{"unwrap", "()Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC, $method(MethodType, unwrap, MethodType*)},
	{"unwrapWithNoPrims", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodType, unwrapWithNoPrims, MethodType*, MethodType*)},
	{"wrap", "()Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC, $method(MethodType, wrap, MethodType*)},
	{"wrapWithPrims", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodType, wrapWithPrims, MethodType*, MethodType*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(MethodType, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _MethodType_InnerClassesInfo_[] = {
	{"java.lang.invoke.TypeDescriptor$OfMethod", "java.lang.invoke.TypeDescriptor", "OfMethod", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.lang.invoke.MethodType$ConcurrentWeakInternSet", "java.lang.invoke.MethodType", "ConcurrentWeakInternSet", $PRIVATE | $STATIC},
	{"java.lang.invoke.MethodType$OffsetHolder", "java.lang.invoke.MethodType", "OffsetHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _MethodType_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.invoke.MethodType",
	"java.lang.Object",
	"java.lang.constant.Constable,java.lang.invoke.TypeDescriptor$OfMethod,java.io.Serializable",
	_MethodType_FieldInfo_,
	_MethodType_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/constant/Constable;Ljava/lang/invoke/TypeDescriptor$OfMethod<Ljava/lang/Class<*>;Ljava/lang/invoke/MethodType;>;Ljava/io/Serializable;",
	nullptr,
	_MethodType_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodType$ConcurrentWeakInternSet,java.lang.invoke.MethodType$ConcurrentWeakInternSet$WeakEntry,java.lang.invoke.MethodType$OffsetHolder"
};

$Object* allocate$MethodType($Class* clazz) {
	return $of($alloc(MethodType));
}

$Object* MethodType::clone() {
	 return this->$Constable::clone();
}

void MethodType::finalize() {
	this->$Constable::finalize();
}

bool MethodType::$assertionsDisabled = false;
$MethodType$ConcurrentWeakInternSet* MethodType::internTable = nullptr;
$ClassArray* MethodType::NO_PTYPES = nullptr;
$MethodTypeArray* MethodType::objectOnlyTypes = nullptr;
$ClassArray* MethodType::METHOD_HANDLE_ARRAY = nullptr;
$ObjectStreamFieldArray* MethodType::serialPersistentFields = nullptr;

void MethodType::init$($Class* rtype, $ClassArray* ptypes) {
	$set(this, rtype$, rtype);
	$set(this, ptypes$, ptypes);
}

$MethodTypeForm* MethodType::form() {
	return this->form$;
}

$Class* MethodType::rtype() {
	return this->rtype$;
}

$ClassArray* MethodType::ptypes() {
	return this->ptypes$;
}

void MethodType::setForm($MethodTypeForm* f) {
	$set(this, form$, f);
}

int32_t MethodType::checkPtypes($ClassArray* ptypes) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	int32_t slots = 0;
	{
		$var($ClassArray, arr$, ptypes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* ptype = arr$->get(i$);
			{
				$Objects::requireNonNull(ptype);
				$init($Void);
				if (ptype == $Void::TYPE) {
					$throw($($MethodHandleStatics::newIllegalArgumentException("parameter type cannot be void"_s)));
				}
				$init($Double);
				$init($Long);
				if (ptype == $Double::TYPE || ptype == $Long::TYPE) {
					++slots;
				}
			}
		}
	}
	checkSlotCount($nc(ptypes)->length + slots);
	return slots;
}

void MethodType::checkSlotCount(int32_t count) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	if (((int32_t)(count & (uint32_t)MethodType::MAX_JVM_ARITY)) != count) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"bad parameter count "_s, $$str(count)}))));
	}
}

$IndexOutOfBoundsException* MethodType::newIndexOutOfBoundsException(Object$* num$renamed) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	$var($Object, num, num$renamed);
	if ($instanceOf($Integer, num)) {
		$assign(num, $str({"bad index: "_s, num}));
	}
	return $new($IndexOutOfBoundsException, $($nc($of(num))->toString()));
}

MethodType* MethodType::methodType($Class* rtype, $ClassArray* ptypes) {
	$init(MethodType);
	return makeImpl(rtype, ptypes, false);
}

MethodType* MethodType::methodType($Class* rtype, $List* ptypes) {
	$init(MethodType);
	bool notrust = false;
	return makeImpl(rtype, $(listToArray(ptypes)), notrust);
}

$ClassArray* MethodType::listToArray($List* ptypes) {
	$init(MethodType);
	checkSlotCount($nc(ptypes)->size());
	return $fcast($ClassArray, $nc(ptypes)->toArray(MethodType::NO_PTYPES));
}

MethodType* MethodType::methodType($Class* rtype, $Class* ptype0, $ClassArray* ptypes) {
	$init(MethodType);
	$var($ClassArray, ptypes1, $new($ClassArray, 1 + $nc(ptypes)->length));
	ptypes1->set(0, ptype0);
	$System::arraycopy(ptypes, 0, ptypes1, 1, ptypes->length);
	return makeImpl(rtype, ptypes1, true);
}

MethodType* MethodType::methodType($Class* rtype) {
	$init(MethodType);
	return makeImpl(rtype, MethodType::NO_PTYPES, true);
}

MethodType* MethodType::methodType($Class* rtype, $Class* ptype0) {
	$init(MethodType);
	return makeImpl(rtype, $$new($ClassArray, {ptype0}), true);
}

MethodType* MethodType::methodType($Class* rtype, MethodType* ptypes) {
	$init(MethodType);
	return makeImpl(rtype, $nc(ptypes)->ptypes$, true);
}

MethodType* MethodType::makeImpl($Class* rtype, $ClassArray* ptypes$renamed, bool trusted) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	$var($ClassArray, ptypes, ptypes$renamed);
	if ($nc(ptypes)->length == 0) {
		$assign(ptypes, MethodType::NO_PTYPES);
		trusted = true;
	}
	$var(MethodType, primordialMT, $new(MethodType, rtype, ptypes));
	$var(MethodType, mt, $cast(MethodType, $nc(MethodType::internTable)->get(primordialMT)));
	if (mt != nullptr) {
		return mt;
	}
	$Objects::requireNonNull(rtype);
	if (trusted) {
		MethodType::checkPtypes(ptypes);
		$assign(mt, primordialMT);
	} else {
		$assign(ptypes, $fcast($ClassArray, $Arrays::copyOf(ptypes, $nc(ptypes)->length)));
		MethodType::checkPtypes(ptypes);
		$assign(mt, $new(MethodType, rtype, ptypes));
	}
	$set($nc(mt), form$, $MethodTypeForm::findForm(mt));
	return $cast(MethodType, $nc(MethodType::internTable)->add(mt));
}

MethodType* MethodType::genericMethodType(int32_t objectArgCount, bool finalArray) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	$var(MethodType, mt, nullptr);
	checkSlotCount(objectArgCount);
	int32_t ivarargs = (!finalArray ? 0 : 1);
	int32_t ootIndex = objectArgCount * 2 + ivarargs;
	if (ootIndex < $nc(MethodType::objectOnlyTypes)->length) {
		$assign(mt, $nc(MethodType::objectOnlyTypes)->get(ootIndex));
		if (mt != nullptr) {
			return mt;
		}
	}
	$var($ClassArray, ptypes, $new($ClassArray, objectArgCount + ivarargs));
	$Arrays::fill(ptypes, $of($Object::class$));
	if (ivarargs != 0) {
		$load($ObjectArray);
		ptypes->set(objectArgCount, $getClass($ObjectArray));
	}
	$assign(mt, makeImpl($Object::class$, ptypes, true));
	if (ootIndex < $nc(MethodType::objectOnlyTypes)->length) {
		$nc(MethodType::objectOnlyTypes)->set(ootIndex, mt);
	}
	return mt;
}

MethodType* MethodType::genericMethodType(int32_t objectArgCount) {
	$init(MethodType);
	return genericMethodType(objectArgCount, false);
}

MethodType* MethodType::changeParameterType(int32_t num, $Class* nptype) {
	if ($cast($Class, parameterType(num)) == nptype) {
		return this;
	}
	$var($ClassArray, nptypes, $cast($ClassArray, $nc(this->ptypes$)->clone()));
	nptypes->set(num, nptype);
	return makeImpl(this->rtype$, nptypes, true);
}

MethodType* MethodType::insertParameterTypes(int32_t num, $ClassArray* ptypesToInsert) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(this->ptypes$)->length;
	if (num < 0 || num > len) {
		$throw($(newIndexOutOfBoundsException($($Integer::valueOf(num)))));
	}
	int32_t ins = checkPtypes(ptypesToInsert);
	checkSlotCount(parameterSlotCount() + $nc(ptypesToInsert)->length + ins);
	int32_t ilen = $nc(ptypesToInsert)->length;
	if (ilen == 0) {
		return this;
	}
	$var($ClassArray, nptypes, $new($ClassArray, len + ilen));
	if (num > 0) {
		$System::arraycopy(this->ptypes$, 0, nptypes, 0, num);
	}
	$System::arraycopy(ptypesToInsert, 0, nptypes, num, ilen);
	if (num < len) {
		$System::arraycopy(this->ptypes$, num, nptypes, num + ilen, len - num);
	}
	return makeImpl(this->rtype$, nptypes, true);
}

MethodType* MethodType::appendParameterTypes($ClassArray* ptypesToInsert) {
	return insertParameterTypes(parameterCount(), ptypesToInsert);
}

MethodType* MethodType::insertParameterTypes(int32_t num, $List* ptypesToInsert) {
	return insertParameterTypes(num, $(listToArray(ptypesToInsert)));
}

MethodType* MethodType::appendParameterTypes($List* ptypesToInsert) {
	return insertParameterTypes(parameterCount(), ptypesToInsert);
}

MethodType* MethodType::replaceParameterTypes(int32_t start, int32_t end, $ClassArray* ptypesToInsert) {
	$useLocalCurrentObjectStackCache();
	if (start == end) {
		return insertParameterTypes(start, ptypesToInsert);
	}
	int32_t len = $nc(this->ptypes$)->length;
	if (!(0 <= start && start <= end && end <= len)) {
		$throw($(newIndexOutOfBoundsException($$str({"start="_s, $$str(start), " end="_s, $$str(end)}))));
	}
	int32_t ilen = $nc(ptypesToInsert)->length;
	if (ilen == 0) {
		return $cast(MethodType, dropParameterTypes(start, end));
	}
	return $nc($($cast(MethodType, dropParameterTypes(start, end))))->insertParameterTypes(start, ptypesToInsert);
}

MethodType* MethodType::asSpreaderType($Class* arrayType, int32_t pos, int32_t arrayLength) {
	$useLocalCurrentObjectStackCache();
	if (!MethodType::$assertionsDisabled && !(parameterCount() >= arrayLength)) {
		$throwNew($AssertionError);
	}
	int32_t spreadPos = pos;
	if (arrayLength == 0) {
		return this;
	}
	$load($ObjectArray);
	if (arrayType == $getClass($ObjectArray)) {
		if (isGeneric()) {
			return this;
		}
		if (spreadPos == 0) {
			$var(MethodType, res, genericMethodType(arrayLength));
			if (this->rtype$ != $Object::class$) {
				$assign(res, $nc(res)->changeReturnType(this->rtype$));
			}
			return res;
		}
	}
	$Class* elemType = $nc(arrayType)->getComponentType();
	if (!MethodType::$assertionsDisabled && !(elemType != nullptr)) {
		$throwNew($AssertionError);
	}
	for (int32_t i = spreadPos; i < spreadPos + arrayLength; ++i) {
		if ($nc(this->ptypes$)->get(i) != elemType) {
			$var($ClassArray, fixedPtypes, $cast($ClassArray, $nc(this->ptypes$)->clone()));
			$Arrays::fill(fixedPtypes, i, spreadPos + arrayLength, $of(elemType));
			return methodType(this->rtype$, fixedPtypes);
		}
	}
	return this;
}

$Class* MethodType::leadingReferenceParameter() {
	$Class* ptype = nullptr;
	if ($nc(this->ptypes$)->length == 0 || $nc((ptype = $nc(this->ptypes$)->get(0)))->isPrimitive()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("no leading reference parameter"_s)));
	}
	return ptype;
}

MethodType* MethodType::asCollectorType($Class* arrayType, int32_t pos, int32_t arrayLength) {
	$useLocalCurrentObjectStackCache();
	if (!MethodType::$assertionsDisabled && !(parameterCount() >= 1)) {
		$throwNew($AssertionError);
	}
	if (!MethodType::$assertionsDisabled && !(pos < $nc(this->ptypes$)->length)) {
		$throwNew($AssertionError);
	}
	if (!MethodType::$assertionsDisabled && !($nc($nc(this->ptypes$)->get(pos))->isAssignableFrom(arrayType))) {
		$throwNew($AssertionError);
	}
	$var(MethodType, res, nullptr);
	$load($ObjectArray);
	if (arrayType == $getClass($ObjectArray)) {
		$assign(res, genericMethodType(arrayLength));
		if (this->rtype$ != $Object::class$) {
			$assign(res, $nc(res)->changeReturnType(this->rtype$));
		}
	} else {
		$Class* elemType = arrayType->getComponentType();
		if (!MethodType::$assertionsDisabled && !(elemType != nullptr)) {
			$throwNew($AssertionError);
		}
		$assign(res, methodType(this->rtype$, $($Collections::nCopies(arrayLength, elemType))));
	}
	if ($nc(this->ptypes$)->length == 1) {
		return res;
	} else {
		if (pos < $nc(this->ptypes$)->length - 1) {
			$assign(res, $nc(res)->insertParameterTypes(arrayLength, $fcast($ClassArray, $($Arrays::copyOfRange(this->ptypes$, pos + 1, $nc(this->ptypes$)->length)))));
		}
		return $nc(res)->insertParameterTypes(0, $fcast($ClassArray, $($Arrays::copyOf(this->ptypes$, pos))));
	}
}

$TypeDescriptor$OfMethod* MethodType::dropParameterTypes(int32_t start, int32_t end) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(this->ptypes$)->length;
	if (!(0 <= start && start <= end && end <= len)) {
		$throw($(newIndexOutOfBoundsException($$str({"start="_s, $$str(start), " end="_s, $$str(end)}))));
	}
	if (start == end) {
		return this;
	}
	$var($ClassArray, nptypes, nullptr);
	if (start == 0) {
		if (end == len) {
			$assign(nptypes, MethodType::NO_PTYPES);
		} else {
			$assign(nptypes, $fcast($ClassArray, $Arrays::copyOfRange(this->ptypes$, end, len)));
		}
	} else if (end == len) {
		$assign(nptypes, $fcast($ClassArray, $Arrays::copyOfRange(this->ptypes$, 0, start)));
	} else {
		int32_t tail = len - end;
		$assign(nptypes, $fcast($ClassArray, $Arrays::copyOfRange(this->ptypes$, 0, start + tail)));
		$System::arraycopy(this->ptypes$, end, nptypes, start, tail);
	}
	return makeImpl(this->rtype$, nptypes, true);
}

MethodType* MethodType::changeReturnType($Class* nrtype) {
	if ($cast($Class, returnType()) == nrtype) {
		return this;
	}
	return makeImpl(nrtype, this->ptypes$, true);
}

bool MethodType::hasPrimitives() {
	return $nc(this->form$)->hasPrimitives();
}

bool MethodType::hasWrappers() {
	return unwrap() != this;
}

MethodType* MethodType::erase() {
	return $nc(this->form$)->erasedType();
}

MethodType* MethodType::basicType() {
	return $nc(this->form$)->basicType();
}

MethodType* MethodType::invokerType() {
	return insertParameterTypes(0, MethodType::METHOD_HANDLE_ARRAY);
}

MethodType* MethodType::generic() {
	return genericMethodType(parameterCount());
}

bool MethodType::isGeneric() {
	bool var$0 = this == erase();
	return var$0 && !hasPrimitives();
}

MethodType* MethodType::wrap() {
	return hasPrimitives() ? wrapWithPrims(this) : this;
}

MethodType* MethodType::unwrap() {
	$var(MethodType, noprims, !hasPrimitives() ? this : wrapWithPrims(this));
	return unwrapWithNoPrims(noprims);
}

MethodType* MethodType::wrapWithPrims(MethodType* pt) {
	$init(MethodType);
	if (!MethodType::$assertionsDisabled && !($nc(pt)->hasPrimitives())) {
		$throwNew($AssertionError);
	}
	$var(MethodType, wt, $cast(MethodType, $nc(pt)->wrapAlt));
	if (wt == nullptr) {
		$assign(wt, $MethodTypeForm::canonicalize(pt, $MethodTypeForm::WRAP));
		if (!MethodType::$assertionsDisabled && !(wt != nullptr)) {
			$throwNew($AssertionError);
		}
		$set(pt, wrapAlt, wt);
	}
	return wt;
}

MethodType* MethodType::unwrapWithNoPrims(MethodType* wt) {
	$init(MethodType);
	if (!MethodType::$assertionsDisabled && !(!$nc(wt)->hasPrimitives())) {
		$throwNew($AssertionError);
	}
	$var(MethodType, uwt, $cast(MethodType, $nc(wt)->wrapAlt));
	if (uwt == nullptr) {
		$assign(uwt, $MethodTypeForm::canonicalize(wt, $MethodTypeForm::UNWRAP));
		if (uwt == nullptr) {
			$assign(uwt, wt);
		}
		$set(wt, wrapAlt, uwt);
	}
	return uwt;
}

$TypeDescriptor$OfField* MethodType::parameterType(int32_t num) {
	return $nc(this->ptypes$)->get(num);
}

int32_t MethodType::parameterCount() {
	return $nc(this->ptypes$)->length;
}

$TypeDescriptor$OfField* MethodType::returnType() {
	return this->rtype$;
}

$List* MethodType::parameterList() {
	$useLocalCurrentObjectStackCache();
	return $Collections::unmodifiableList($($Arrays::asList($cast($ClassArray, $($nc(this->ptypes$)->clone())))));
}

$Class* MethodType::lastParameterType() {
	int32_t len = $nc(this->ptypes$)->length;
	$init($Void);
	return len == 0 ? $Void::TYPE : $nc(this->ptypes$)->get(len - 1);
}

$TypeDescriptor$OfFieldArray* MethodType::parameterArray() {
	return $fcast($TypeDescriptor$OfFieldArray, $cast($ClassArray, $nc(this->ptypes$)->clone()));
}

bool MethodType::equals(Object$* x) {
	if ($equals(this, x)) {
		return true;
	}
	if ($instanceOf(MethodType, x)) {
		return equals($cast(MethodType, x));
	}
	if ($instanceOf($MethodType$ConcurrentWeakInternSet$WeakEntry, x)) {
		$var($Object, o, $nc(($cast($MethodType$ConcurrentWeakInternSet$WeakEntry, x)))->get());
		if ($instanceOf(MethodType, o)) {
			return equals($cast(MethodType, o));
		}
	}
	return false;
}

bool MethodType::equals(MethodType* that) {
	return this->rtype$ == $nc(that)->rtype$ && $Arrays::equals(this->ptypes$, that->ptypes$);
}

int32_t MethodType::hashCode() {
	int32_t hashCode = 31 + $nc($of(this->rtype$))->hashCode();
	{
		$var($ClassArray, arr$, this->ptypes$);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* ptype = arr$->get(i$);
			hashCode = 31 * hashCode + $nc($of(ptype))->hashCode();
		}
	}
	return hashCode;
}

$String* MethodType::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringJoiner, sj, $new($StringJoiner, ","_s, "("_s, $$str({")"_s, $($nc(this->rtype$)->getSimpleName())})));
	for (int32_t i = 0; i < $nc(this->ptypes$)->length; ++i) {
		sj->add($($nc($nc(this->ptypes$)->get(i))->getSimpleName()));
	}
	return sj->toString();
}

bool MethodType::effectivelyIdenticalParameters(int32_t skipPos, $List* fullList) {
	$useLocalCurrentObjectStackCache();
	int32_t myLen = $nc(this->ptypes$)->length;
	int32_t fullLen = $nc(fullList)->size();
	if (skipPos > myLen || myLen - skipPos > fullLen) {
		return false;
	}
	$var($List, myList, $Arrays::asList(this->ptypes$));
	if (skipPos != 0) {
		$assign(myList, $nc(myList)->subList(skipPos, myLen));
		myLen -= skipPos;
	}
	if (fullLen == myLen) {
		return $nc(myList)->equals(fullList);
	} else {
		return $nc(myList)->equals($(fullList->subList(0, myLen)));
	}
}

bool MethodType::isViewableAs(MethodType* newType, bool keepInterfaces) {
	$useLocalCurrentObjectStackCache();
	$Class* var$0 = $cast($Class, returnType());
	if (!$VerifyType::isNullConversion(var$0, $($cast($Class, $nc(newType)->returnType())), keepInterfaces)) {
		return false;
	}
	if (this->form$ == $nc(newType)->form$ && $nc(this->form$)->erasedType$ == this) {
		return true;
	}
	if (this->ptypes$ == $nc(newType)->ptypes$) {
		return true;
	}
	int32_t argc = parameterCount();
	if (argc != $nc(newType)->parameterCount()) {
		return false;
	}
	for (int32_t i = 0; i < argc; ++i) {
		$Class* var$1 = $cast($Class, $nc(newType)->parameterType(i));
		if (!$VerifyType::isNullConversion(var$1, $($cast($Class, parameterType(i))), keepInterfaces)) {
			return false;
		}
	}
	return true;
}

bool MethodType::isConvertibleTo(MethodType* newType) {
	$useLocalCurrentObjectStackCache();
	$var($MethodTypeForm, oldForm, this->form());
	$var($MethodTypeForm, newForm, $nc(newType)->form());
	if (oldForm == newForm) {
		return true;
	}
	$Class* var$0 = $cast($Class, returnType());
	if (!canConvert(var$0, $($cast($Class, newType->returnType())))) {
		return false;
	}
	$var($ClassArray, srcTypes, newType->ptypes$);
	$var($ClassArray, dstTypes, this->ptypes$);
	if (srcTypes == dstTypes) {
		return true;
	}
	int32_t argc = 0;
	if ((argc = $nc(srcTypes)->length) != $nc(dstTypes)->length) {
		return false;
	}
	if (argc <= 1) {
		if (argc == 1 && !canConvert($nc(srcTypes)->get(0), $nc(dstTypes)->get(0))) {
			return false;
		}
		return true;
	}
	bool var$1 = (!$nc(oldForm)->hasPrimitives() && oldForm->erasedType$ == this);
	if (var$1 || (!$nc(newForm)->hasPrimitives() && newForm->erasedType$ == newType)) {
		if (!MethodType::$assertionsDisabled && !(canConvertParameters(srcTypes, dstTypes))) {
			$throwNew($AssertionError);
		}
		return true;
	}
	return canConvertParameters(srcTypes, dstTypes);
}

bool MethodType::explicitCastEquivalentToAsType(MethodType* newType) {
	$useLocalCurrentObjectStackCache();
	if (this == newType) {
		return true;
	}
	if (!explicitCastEquivalentToAsType(this->rtype$, $nc(newType)->rtype$)) {
		return false;
	}
	$var($ClassArray, srcTypes, $nc(newType)->ptypes$);
	$var($ClassArray, dstTypes, this->ptypes$);
	if (dstTypes == srcTypes) {
		return true;
	}
	if (!MethodType::$assertionsDisabled && !($nc(dstTypes)->length == $nc(srcTypes)->length)) {
		$throwNew($AssertionError);
	}
	for (int32_t i = 0; i < $nc(dstTypes)->length; ++i) {
		if (!explicitCastEquivalentToAsType($nc(srcTypes)->get(i), dstTypes->get(i))) {
			return false;
		}
	}
	return true;
}

bool MethodType::explicitCastEquivalentToAsType($Class* src, $Class* dst) {
	$init(MethodType);
	$init($Void);
	if (src == dst || dst == $Object::class$ || dst == $Void::TYPE) {
		return true;
	}
	if ($nc(src)->isPrimitive()) {
		return canConvert(src, dst);
	} else if ($nc(dst)->isPrimitive()) {
		return false;
	} else {
		bool var$0 = !dst->isInterface();
		return var$0 || dst->isAssignableFrom(src);
	}
}

bool MethodType::canConvertParameters($ClassArray* srcTypes, $ClassArray* dstTypes) {
	for (int32_t i = 0; i < $nc(srcTypes)->length; ++i) {
		if (!canConvert(srcTypes->get(i), $nc(dstTypes)->get(i))) {
			return false;
		}
	}
	return true;
}

bool MethodType::canConvert($Class* src, $Class* dst) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	if (src == dst || src == $Object::class$ || dst == $Object::class$) {
		return true;
	}
	if ($nc(src)->isPrimitive()) {
		$init($Void);
		if (src == $Void::TYPE) {
			return true;
		}
		$Wrapper* sw = $Wrapper::forPrimitiveType(src);
		if ($nc(dst)->isPrimitive()) {
			return $nc($($Wrapper::forPrimitiveType(dst)))->isConvertibleFrom(sw);
		} else {
			return dst->isAssignableFrom($nc(sw)->wrapperType());
		}
	} else if ($nc(dst)->isPrimitive()) {
		$init($Void);
		if (dst == $Void::TYPE) {
			return true;
		}
		$Wrapper* dw = $Wrapper::forPrimitiveType(dst);
		if (src->isAssignableFrom($nc(dw)->wrapperType())) {
			return true;
		}
		bool var$0 = $Wrapper::isWrapperType(src);
		if (var$0 && $nc(dw)->isConvertibleFrom($($Wrapper::forWrapperType(src)))) {
			return true;
		}
		return false;
	} else {
		return true;
	}
}

int32_t MethodType::parameterSlotCount() {
	return $nc(this->form$)->parameterSlotCount();
}

$Invokers* MethodType::invokers() {
	$var($Invokers, inv, this->invokers$);
	if (inv != nullptr) {
		return inv;
	}
	$set(this, invokers$, ($assign(inv, $new($Invokers, this))));
	return inv;
}

MethodType* MethodType::fromMethodDescriptorString($String* descriptor, $ClassLoader* loader) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (loader == nullptr) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$init($SecurityConstants);
			sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
		}
	}
	return fromDescriptor(descriptor, (loader == nullptr) ? $($ClassLoader::getSystemClassLoader()) : loader);
}

MethodType* MethodType::fromDescriptor($String* descriptor, $ClassLoader* loader) {
	$init(MethodType);
	$useLocalCurrentObjectStackCache();
	bool var$1 = !$nc(descriptor)->startsWith("("_s);
	bool var$0 = var$1 || $nc(descriptor)->indexOf((int32_t)u')') < 0;
	if (var$0 || $nc(descriptor)->indexOf((int32_t)u'.') >= 0) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"not a method descriptor: "_s, descriptor}))));
	}
	$var($List, types, $BytecodeDescriptor::parseMethod(descriptor, loader));
	$Class* rtype = $cast($Class, $nc(types)->remove(types->size() - 1));
	$var($ClassArray, ptypes, listToArray(types));
	return makeImpl(rtype, ptypes, true);
}

$String* MethodType::toMethodDescriptorString() {
	$var($String, desc, this->methodDescriptor);
	if (desc == nullptr) {
		$assign(desc, $BytecodeDescriptor::unparseMethod(this->rtype$, this->ptypes$));
		$set(this, methodDescriptor, desc);
	}
	return desc;
}

$String* MethodType::descriptorString() {
	return toMethodDescriptorString();
}

$String* MethodType::toFieldDescriptorString($Class* cls) {
	$init(MethodType);
	return $BytecodeDescriptor::unparse(cls);
}

$Optional* MethodType::describeConstable() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ClassDesc, var$0, $cast($ClassDesc, $nc($($nc($($cast($Class, returnType())))->describeConstable()))->orElseThrow()));
		return $Optional::of($($MethodTypeDesc::of(var$0, $fcast($ClassDescArray, $($nc($($nc($($Stream::of($(parameterArray()))))->map(static_cast<$Function*>($$new(MethodType$$Lambda$lambda$describeConstable$0)))))->toArray(static_cast<$IntFunction*>($$new(MethodType$$Lambda$lambda$describeConstable$1$1))))))));
	} catch ($NoSuchElementException& e) {
		return $Optional::empty();
	}
	$shouldNotReachHere();
}

void MethodType::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	s->writeObject($(returnType()));
	s->writeObject($(parameterArray()));
}

void MethodType::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$init($MethodHandleStatics);
	$init($MethodType$OffsetHolder);
	$init($Void);
	$nc($MethodHandleStatics::UNSAFE)->putReference(this, $MethodType$OffsetHolder::rtypeOffset, $Void::TYPE);
	$nc($MethodHandleStatics::UNSAFE)->putReference(this, $MethodType$OffsetHolder::ptypesOffset, MethodType::NO_PTYPES);
	$nc(s)->defaultReadObject();
	$Class* returnType = $cast($Class, s->readObject());
	$var($ClassArray, parameterArray, $cast($ClassArray, s->readObject()));
	$set(this, wrapAlt, $new($MethodTypeArray, {$(MethodType::methodType(returnType, parameterArray))}));
}

$Object* MethodType::readResolve() {
	$var(MethodType, mt, $nc(($cast($MethodTypeArray, this->wrapAlt)))->get(0));
	$set(this, wrapAlt, nullptr);
	return $of(mt);
}

$TypeDescriptor$OfMethod* MethodType::insertParameterTypes(int32_t num, $TypeDescriptor$OfFieldArray* ptypesToInsert) {
	return this->insertParameterTypes(num, $fcast($ClassArray, ptypesToInsert));
}

$TypeDescriptor$OfMethod* MethodType::changeParameterType(int32_t num, $TypeDescriptor$OfField* nptype) {
	return this->changeParameterType(num, $cast($Class, nptype));
}

$TypeDescriptor$OfMethod* MethodType::changeReturnType($TypeDescriptor$OfField* nrtype) {
	return this->changeReturnType($cast($Class, nrtype));
}

$ClassDescArray* MethodType::lambda$describeConstable$1(int32_t x$0) {
	$init(MethodType);
	return $new($ClassDescArray, x$0);
}

$ClassDesc* MethodType::lambda$describeConstable$0($Class* p) {
	$init(MethodType);
	return $cast($ClassDesc, $nc($($nc(p)->describeConstable()))->orElseThrow());
}

void clinit$MethodType($Class* class$) {
	MethodType::$assertionsDisabled = !MethodType::class$->desiredAssertionStatus();
	{
	}
	$assignStatic(MethodType::internTable, $new($MethodType$ConcurrentWeakInternSet));
	$assignStatic(MethodType::NO_PTYPES, $new($ClassArray, 0));
	$assignStatic(MethodType::objectOnlyTypes, $new($MethodTypeArray, 20));
	$load($MethodHandle);
	$assignStatic(MethodType::METHOD_HANDLE_ARRAY, $new($ClassArray, {$MethodHandle::class$}));
	$assignStatic(MethodType::serialPersistentFields, $new($ObjectStreamFieldArray, 0));
}

MethodType::MethodType() {
}

$Class* MethodType::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MethodType$$Lambda$lambda$describeConstable$0::classInfo$.name)) {
			return MethodType$$Lambda$lambda$describeConstable$0::load$(name, initialize);
		}
		if (name->equals(MethodType$$Lambda$lambda$describeConstable$1$1::classInfo$.name)) {
			return MethodType$$Lambda$lambda$describeConstable$1$1::load$(name, initialize);
		}
	}
	$loadClass(MethodType, name, initialize, &_MethodType_ClassInfo_, clinit$MethodType, allocate$MethodType);
	return class$;
}

$Class* MethodType::class$ = nullptr;

		} // invoke
	} // lang
} // java