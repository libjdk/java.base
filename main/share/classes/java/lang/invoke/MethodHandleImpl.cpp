#include <java/lang/invoke/MethodHandleImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassValue.h>
#include <java/lang/Error.h>
#include <java/lang/InternalError.h>
#include <java/lang/Iterable.h>
#include <java/lang/Math.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/constant/Constable.h>
#include <java/lang/invoke/BoundMethodHandle$SpeciesData.h>
#include <java/lang/invoke/BoundMethodHandle.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaForm$BasicType.h>
#include <java/lang/invoke/LambdaForm$Kind.h>
#include <java/lang/invoke/LambdaForm$Name.h>
#include <java/lang/invoke/LambdaForm$NamedFunction.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/LambdaFormEditor.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl$1.h>
#include <java/lang/invoke/MethodHandleImpl$ArrayAccess.h>
#include <java/lang/invoke/MethodHandleImpl$ArrayAccessor.h>
#include <java/lang/invoke/MethodHandleImpl$AsVarargsCollector.h>
#include <java/lang/invoke/MethodHandleImpl$BindCaller.h>
#include <java/lang/invoke/MethodHandleImpl$CasesHolder.h>
#include <java/lang/invoke/MethodHandleImpl$CountingWrapper.h>
#include <java/lang/invoke/MethodHandleImpl$Intrinsic.h>
#include <java/lang/invoke/MethodHandleImpl$IntrinsicMethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl$LoopClauses.h>
#include <java/lang/invoke/MethodHandleImpl$Makers.h>
#include <java/lang/invoke/MethodHandleImpl$TableSwitchCacheKey.h>
#include <java/lang/invoke/MethodHandleImpl$WrappedMember.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/MethodTypeForm.h>
#include <java/lang/invoke/SimpleMethodHandle.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/TypeDescriptor$OfMethod.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaLangInvokeAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/invoke/empty/Empty.h>
#include <sun/invoke/util/ValueConversions.h>
#include <sun/invoke/util/VerifyType.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#undef ARG_BASE
#undef ARG_LIMIT
#undef ARG_SWITCH_ON
#undef ARRAYS
#undef ARRAY_STORE
#undef BOXED_ARGS
#undef CACHE
#undef CALL_NEW_ARRAY
#undef CALL_TARGET
#undef CALL_TEST
#undef COLLECTOR
#undef DONT_INLINE_THRESHOLD
#undef FAKE_METHOD_HANDLE_INVOKE
#undef FIELD_CASES
#undef FIELD_COLLECT_ARGS
#undef FIELD_DEFAULT_CASE
#undef FIELD_UNBOX_RESULT
#undef GET
#undef GET_CASES
#undef GET_CATCHER
#undef GET_CLASS
#undef GET_CLAUSE_DATA
#undef GET_CLEANUP
#undef GET_COLLECT_ARGS
#undef GET_COUNTERS
#undef GET_DEFAULT_CASE
#undef GET_FALLBACK
#undef GET_NEW_ARRAY
#undef GET_TARGET
#undef GET_TEST
#undef GET_UNBOX_RESULT
#undef GUARD
#undef GUARD_WITH_CATCH
#undef HANDLES
#undef IMPL_LOOKUP
#undef INARG_COUNT
#undef LF_COLLECTOR
#undef LF_GWC
#undef LF_GWT
#undef LF_LOOP
#undef LF_TF
#undef LOOP
#undef MAX_ARITY
#undef MAX_ARRAY_SLOTS
#undef MAX_JVM_ARITY
#undef MH_LIMIT
#undef MH_RECEIVER_OFFSET
#undef NFS
#undef NF_LIMIT
#undef OBJECT_ARRAY_SETTER
#undef PRODUCE_BLOCK_INLINING_FORM
#undef PRODUCE_REINVOKER_FORM
#undef PROFILE
#undef PROFILE_GWT
#undef SELECT_ALT
#undef SELECT_ALTERNATIVE
#undef SET
#undef STORE_ELEMENT_BASE
#undef STORE_ELEMENT_LIMIT
#undef TABLE_SWITCH
#undef TEST
#undef THIS_MH
#undef TRY_CATCH
#undef TRY_FINALLY
#undef TYPE
#undef TYPED_ACCESSORS
#undef TYPED_COLLECTORS
#undef UNBOXED_RESULT
#undef UNBOX_RESULT

using $ConstableArray = $Array<::java::lang::constant::Constable>;
using $LambdaForm$BasicTypeArray = $Array<::java::lang::invoke::LambdaForm$BasicType>;
using $LambdaForm$NameArray = $Array<::java::lang::invoke::LambdaForm$Name>;
using $LambdaForm$NamedFunctionArray = $Array<::java::lang::invoke::LambdaForm$NamedFunction>;
using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $MethodHandleArray2 = $Array<::java::lang::invoke::MethodHandle, 2>;
using $Serializable = ::java::io::Serializable;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassValue = ::java::lang::ClassValue;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Iterable = ::java::lang::Iterable;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $Constable = ::java::lang::constant::Constable;
using $BoundMethodHandle = ::java::lang::invoke::BoundMethodHandle;
using $BoundMethodHandle$SpeciesData = ::java::lang::invoke::BoundMethodHandle$SpeciesData;
using $LambdaForm = ::java::lang::invoke::LambdaForm;
using $LambdaForm$BasicType = ::java::lang::invoke::LambdaForm$BasicType;
using $LambdaForm$Kind = ::java::lang::invoke::LambdaForm$Kind;
using $LambdaForm$Name = ::java::lang::invoke::LambdaForm$Name;
using $LambdaForm$NamedFunction = ::java::lang::invoke::LambdaForm$NamedFunction;
using $LambdaFormEditor = ::java::lang::invoke::LambdaFormEditor;
using $MemberName = ::java::lang::invoke::MemberName;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl$1 = ::java::lang::invoke::MethodHandleImpl$1;
using $MethodHandleImpl$ArrayAccess = ::java::lang::invoke::MethodHandleImpl$ArrayAccess;
using $MethodHandleImpl$ArrayAccessor = ::java::lang::invoke::MethodHandleImpl$ArrayAccessor;
using $MethodHandleImpl$AsVarargsCollector = ::java::lang::invoke::MethodHandleImpl$AsVarargsCollector;
using $MethodHandleImpl$BindCaller = ::java::lang::invoke::MethodHandleImpl$BindCaller;
using $MethodHandleImpl$CasesHolder = ::java::lang::invoke::MethodHandleImpl$CasesHolder;
using $MethodHandleImpl$CountingWrapper = ::java::lang::invoke::MethodHandleImpl$CountingWrapper;
using $MethodHandleImpl$Intrinsic = ::java::lang::invoke::MethodHandleImpl$Intrinsic;
using $MethodHandleImpl$IntrinsicMethodHandle = ::java::lang::invoke::MethodHandleImpl$IntrinsicMethodHandle;
using $MethodHandleImpl$LoopClauses = ::java::lang::invoke::MethodHandleImpl$LoopClauses;
using $MethodHandleImpl$Makers = ::java::lang::invoke::MethodHandleImpl$Makers;
using $MethodHandleImpl$TableSwitchCacheKey = ::java::lang::invoke::MethodHandleImpl$TableSwitchCacheKey;
using $MethodHandleImpl$WrappedMember = ::java::lang::invoke::MethodHandleImpl$WrappedMember;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MethodTypeForm = ::java::lang::invoke::MethodTypeForm;
using $SimpleMethodHandle = ::java::lang::invoke::SimpleMethodHandle;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $1Array = ::java::lang::reflect::Array;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $JavaLangInvokeAccess = ::jdk::internal::access::JavaLangInvokeAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Empty = ::sun::invoke::empty::Empty;
using $ValueConversions = ::sun::invoke::util::ValueConversions;
using $VerifyType = ::sun::invoke::util::VerifyType;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace java {
	namespace lang {
		namespace invoke {

class MethodHandleImpl$$Lambda$lambda$makeLoop$0 : public $Function {
	$class(MethodHandleImpl$$Lambda$lambda$makeLoop$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* h) override {
		 return $of(MethodHandleImpl::lambda$makeLoop$0($cast($MethodHandle, h)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodHandleImpl$$Lambda$lambda$makeLoop$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MethodHandleImpl$$Lambda$lambda$makeLoop$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MethodHandleImpl$$Lambda$lambda$makeLoop$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MethodHandleImpl$$Lambda$lambda$makeLoop$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo MethodHandleImpl$$Lambda$lambda$makeLoop$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodHandleImpl$$Lambda$lambda$makeLoop$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MethodHandleImpl$$Lambda$lambda$makeLoop$0::load$($String* name, bool initialize) {
	$loadClass(MethodHandleImpl$$Lambda$lambda$makeLoop$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodHandleImpl$$Lambda$lambda$makeLoop$0::class$ = nullptr;

class MethodHandleImpl$$Lambda$basicType$1 : public $Function {
	$class(MethodHandleImpl$$Lambda$basicType$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* type) override {
		 return $of($LambdaForm$BasicType::basicType($cast($Class, type)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodHandleImpl$$Lambda$basicType$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MethodHandleImpl$$Lambda$basicType$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MethodHandleImpl$$Lambda$basicType$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MethodHandleImpl$$Lambda$basicType$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo MethodHandleImpl$$Lambda$basicType$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodHandleImpl$$Lambda$basicType$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MethodHandleImpl$$Lambda$basicType$1::load$($String* name, bool initialize) {
	$loadClass(MethodHandleImpl$$Lambda$basicType$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodHandleImpl$$Lambda$basicType$1::class$ = nullptr;

class MethodHandleImpl$$Lambda$lambda$makeLoop$1$2 : public $IntFunction {
	$class(MethodHandleImpl$$Lambda$lambda$makeLoop$1$2, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(MethodHandleImpl::lambda$makeLoop$1(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodHandleImpl$$Lambda$lambda$makeLoop$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MethodHandleImpl$$Lambda$lambda$makeLoop$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MethodHandleImpl$$Lambda$lambda$makeLoop$1$2, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MethodHandleImpl$$Lambda$lambda$makeLoop$1$2, apply, $Object*, int32_t)},
	{}
};
$ClassInfo MethodHandleImpl$$Lambda$lambda$makeLoop$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodHandleImpl$$Lambda$lambda$makeLoop$1$2",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* MethodHandleImpl$$Lambda$lambda$makeLoop$1$2::load$($String* name, bool initialize) {
	$loadClass(MethodHandleImpl$$Lambda$lambda$makeLoop$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodHandleImpl$$Lambda$lambda$makeLoop$1$2::class$ = nullptr;

class MethodHandleImpl$$Lambda$lambda$loop$2$3 : public $Predicate {
	$class(MethodHandleImpl$$Lambda$lambda$loop$2$3, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* h) override {
		 return MethodHandleImpl::lambda$loop$2($cast($MethodHandle, h));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodHandleImpl$$Lambda$lambda$loop$2$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MethodHandleImpl$$Lambda$lambda$loop$2$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MethodHandleImpl$$Lambda$lambda$loop$2$3, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(MethodHandleImpl$$Lambda$lambda$loop$2$3, test, bool, Object$*)},
	{}
};
$ClassInfo MethodHandleImpl$$Lambda$lambda$loop$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodHandleImpl$$Lambda$lambda$loop$2$3",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* MethodHandleImpl$$Lambda$lambda$loop$2$3::load$($String* name, bool initialize) {
	$loadClass(MethodHandleImpl$$Lambda$lambda$loop$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodHandleImpl$$Lambda$lambda$loop$2$3::class$ = nullptr;

$CompoundAttribute _MethodHandleImpl_FieldAnnotations_ARRAYS[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_FieldAnnotations_NFS[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_FieldAnnotations_HANDLES[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_guardWithCatch14[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_isCompileConstant16[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_loop22[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_prepend46[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_profileBoolean48[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_selectAlternative49[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_tableSwitch51[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$CompoundAttribute _MethodHandleImpl_MethodAnnotations_tryFinally55[] = {
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$FieldInfo _MethodHandleImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodHandleImpl, $assertionsDisabled)},
	{"FAKE_METHOD_HANDLE_INVOKE", "[Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticField(MethodHandleImpl, FAKE_METHOD_HANDLE_INVOKE)},
	{"ARRAYS", "[Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodHandleImpl, ARRAYS), _MethodHandleImpl_FieldAnnotations_ARRAYS},
	{"MAX_JVM_ARITY", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MAX_JVM_ARITY)},
	{"NF_checkSpreadArgument", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_checkSpreadArgument)},
	{"NF_guardWithCatch", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_guardWithCatch)},
	{"NF_throwException", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_throwException)},
	{"NF_tryFinally", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_tryFinally)},
	{"NF_loop", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_loop)},
	{"NF_profileBoolean", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_profileBoolean)},
	{"NF_tableSwitch", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_tableSwitch)},
	{"NF_LIMIT", "B", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, NF_LIMIT)},
	{"NFS", "[Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodHandleImpl, NFS), _MethodHandleImpl_FieldAnnotations_NFS},
	{"MH_cast", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_cast)},
	{"MH_selectAlternative", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_selectAlternative)},
	{"MH_countedLoopPred", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_countedLoopPred)},
	{"MH_countedLoopStep", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_countedLoopStep)},
	{"MH_initIterator", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_initIterator)},
	{"MH_iteratePred", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_iteratePred)},
	{"MH_iterateNext", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_iterateNext)},
	{"MH_Array_newInstance", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_Array_newInstance)},
	{"MH_LIMIT", "I", nullptr, $STATIC | $FINAL, $constField(MethodHandleImpl, MH_LIMIT)},
	{"HANDLES", "[Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodHandleImpl, HANDLES), _MethodHandleImpl_FieldAnnotations_HANDLES},
	{}
};

$MethodInfo _MethodHandleImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(MethodHandleImpl, init$, void)},
	{"assertCorrectArity", "(Ljava/lang/invoke/MethodHandle;I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, assertCorrectArity, bool, $MethodHandle*, int32_t)},
	{"assertSame", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl, assertSame, void, Object$*, Object$*)},
	{"bindCaller", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, bindCaller, $MethodHandle*, $MethodHandle*, $Class*)},
	{"checkSpreadArgument", "(Ljava/lang/Object;I)V", nullptr, $STATIC, $staticMethod(MethodHandleImpl, checkSpreadArgument, void, Object$*, int32_t)},
	{"computeValueConversions", "(Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;ZZ)[Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, computeValueConversions, $ObjectArray*, $MethodType*, $MethodType*, bool, bool)},
	{"countNonNull", "([Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, countNonNull, int32_t, $ObjectArray*)},
	{"countedLoopPredicate", "(II)Z", nullptr, $STATIC, $staticMethod(MethodHandleImpl, countedLoopPredicate, bool, int32_t, int32_t)},
	{"countedLoopStep", "(II)I", nullptr, $STATIC, $staticMethod(MethodHandleImpl, countedLoopStep, int32_t, int32_t, int32_t)},
	{"createFunction", "(B)Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, createFunction, $LambdaForm$NamedFunction*, int8_t)},
	{"fakeMethodHandleInvoke", "(Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, fakeMethodHandleInvoke, $MethodHandle*, $MemberName*)},
	{"fakeVarHandleInvoke", "(Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, fakeVarHandleInvoke, $MethodHandle*, $MemberName*)},
	{"getConstantHandle", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, getConstantHandle, $MethodHandle*, int32_t)},
	{"getFunction", "(B)Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, getFunction, $LambdaForm$NamedFunction*, int8_t)},
	{"guardWithCatch", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;[Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<+Ljava/lang/Throwable;>;Ljava/lang/invoke/MethodHandle;[Ljava/lang/Object;)Ljava/lang/Object;", $STATIC | $TRANSIENT, $staticMethod(MethodHandleImpl, guardWithCatch, $Object*, $MethodHandle*, $Class*, $MethodHandle*, $ObjectArray*), "java.lang.Throwable", nullptr, _MethodHandleImpl_MethodAnnotations_guardWithCatch14},
	{"initIterator", "(Ljava/lang/Iterable;)Ljava/util/Iterator;", "(Ljava/lang/Iterable<*>;)Ljava/util/Iterator<*>;", $STATIC, $staticMethod(MethodHandleImpl, initIterator, $Iterator*, $Iterable*)},
	{"isCompileConstant", "(Ljava/lang/Object;)Z", nullptr, $STATIC, $staticMethod(MethodHandleImpl, isCompileConstant, bool, Object$*), nullptr, nullptr, _MethodHandleImpl_MethodAnnotations_isCompileConstant16},
	{"iterateNext", "(Ljava/util/Iterator;)Ljava/lang/Object;", "(Ljava/util/Iterator<*>;)Ljava/lang/Object;", $STATIC, $staticMethod(MethodHandleImpl, iterateNext, $Object*, $Iterator*)},
	{"iteratePredicate", "(Ljava/util/Iterator;)Z", "(Ljava/util/Iterator<*>;)Z", $STATIC, $staticMethod(MethodHandleImpl, iteratePredicate, bool, $Iterator*)},
	{"lambda$loop$2", "(Ljava/lang/invoke/MethodHandle;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MethodHandleImpl, lambda$loop$2, bool, $MethodHandle*)},
	{"lambda$makeLoop$0", "(Ljava/lang/invoke/MethodHandle;)Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MethodHandleImpl, lambda$makeLoop$0, $Class*, $MethodHandle*)},
	{"lambda$makeLoop$1", "(I)[Ljava/lang/invoke/LambdaForm$BasicType;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MethodHandleImpl, lambda$makeLoop$1, $LambdaForm$BasicTypeArray*, int32_t)},
	{"loop", "([Ljava/lang/invoke/LambdaForm$BasicType;Ljava/lang/invoke/MethodHandleImpl$LoopClauses;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC | $TRANSIENT, $staticMethod(MethodHandleImpl, loop, $Object*, $LambdaForm$BasicTypeArray*, $MethodHandleImpl$LoopClauses*, $ObjectArray*), "java.lang.Throwable", nullptr, _MethodHandleImpl_MethodAnnotations_loop22},
	{"makeArrayElementAccessor", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, makeArrayElementAccessor, $MethodHandle*, $Class*, $MethodHandleImpl$ArrayAccess*)},
	{"makeBlockInliningWrapper", "(Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeBlockInliningWrapper, $MethodHandle*, $MethodHandle*)},
	{"makeCollector", "(Ljava/lang/Class;I)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;I)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeCollector, $MethodHandle*, $Class*, int32_t)},
	{"makeCollectorForm", "(Ljava/lang/invoke/MethodType;Ljava/lang/Class;)Ljava/lang/invoke/LambdaForm;", "(Ljava/lang/invoke/MethodType;Ljava/lang/Class<*>;)Ljava/lang/invoke/LambdaForm;", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeCollectorForm, $LambdaForm*, $MethodType*, $Class*)},
	{"makeConstantHandle", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeConstantHandle, $MethodHandle*, int32_t)},
	{"makeGuardWithCatch", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<+Ljava/lang/Throwable;>;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, makeGuardWithCatch, $MethodHandle*, $MethodHandle*, $Class*, $MethodHandle*)},
	{"makeGuardWithCatchForm", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeGuardWithCatchForm, $LambdaForm*, $MethodType*)},
	{"makeGuardWithTest", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeGuardWithTest, $MethodHandle*, $MethodHandle*, $MethodHandle*, $MethodHandle*)},
	{"makeGuardWithTestForm", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/LambdaForm;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeGuardWithTestForm, $LambdaForm*, $MethodType*)},
	{"makeIntrinsic", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandleImpl$Intrinsic;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeIntrinsic, $MethodHandle*, $MethodHandle*, $MethodHandleImpl$Intrinsic*)},
	{"makeIntrinsic", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandleImpl$Intrinsic;Ljava/lang/Object;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeIntrinsic, $MethodHandle*, $MethodHandle*, $MethodHandleImpl$Intrinsic*, Object$*)},
	{"makeIntrinsic", "(Ljava/lang/invoke/MethodType;Ljava/lang/invoke/LambdaForm;Ljava/lang/invoke/MethodHandleImpl$Intrinsic;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeIntrinsic, $MethodHandle*, $MethodType*, $LambdaForm*, $MethodHandleImpl$Intrinsic*)},
	{"makeLoop", "(Ljava/lang/Class;Ljava/util/List;Ljava/util/List;Ljava/util/List;Ljava/util/List;Ljava/util/List;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, makeLoop, $MethodHandle*, $Class*, $List*, $List*, $List*, $List*, $List*)},
	{"makeLoopForm", "(Ljava/lang/invoke/MethodType;[Ljava/lang/invoke/LambdaForm$BasicType;)Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeLoopForm, $LambdaForm*, $MethodType*, $LambdaForm$BasicTypeArray*)},
	{"makePairwiseConvert", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;ZZ)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makePairwiseConvert, $MethodHandle*, $MethodHandle*, $MethodType*, bool, bool)},
	{"makePairwiseConvert", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Z)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makePairwiseConvert, $MethodHandle*, $MethodHandle*, $MethodType*, bool)},
	{"makePairwiseConvertByEditor", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;ZZ)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makePairwiseConvertByEditor, $MethodHandle*, $MethodHandle*, $MethodType*, bool, bool)},
	{"makeTableSwitch", "(Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodHandle;[Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeTableSwitch, $MethodHandle*, $MethodType*, $MethodHandle*, $MethodHandleArray*)},
	{"makeTableSwitchForm", "(Ljava/lang/invoke/MethodType;Ljava/lang/invoke/BoundMethodHandle$SpeciesData;I)Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeTableSwitchForm, $LambdaForm*, $MethodType*, $BoundMethodHandle$SpeciesData*, int32_t)},
	{"makeTryFinally", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;Ljava/util/List;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, makeTryFinally, $MethodHandle*, $MethodHandle*, $MethodHandle*, $Class*, $List*)},
	{"makeTryFinallyForm", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, makeTryFinallyForm, $LambdaForm*, $MethodType*)},
	{"makeVarargsCollector", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, makeVarargsCollector, $MethodHandle*, $MethodHandle*, $Class*)},
	{"makeWrappedMember", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, makeWrappedMember, $MethodHandle*, $MethodHandle*, $MemberName*, bool)},
	{"prepend", "([Ljava/lang/Object;[Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(MethodHandleImpl, prepend, $ObjectArray*, $ObjectArray*, $ObjectArray*), nullptr, nullptr, _MethodHandleImpl_MethodAnnotations_prepend46},
	{"profile", "(Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, profile, $MethodHandle*, $MethodHandle*)},
	{"profileBoolean", "(Z[I)Z", nullptr, $STATIC, $staticMethod(MethodHandleImpl, profileBoolean, bool, bool, $ints*), nullptr, nullptr, _MethodHandleImpl_MethodAnnotations_profileBoolean48},
	{"selectAlternative", "(ZLjava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, selectAlternative, $MethodHandle*, bool, $MethodHandle*, $MethodHandle*), nullptr, nullptr, _MethodHandleImpl_MethodAnnotations_selectAlternative49},
	{"setCachedHandle", "(ILjava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(MethodHandleImpl, setCachedHandle, $MethodHandle*, int32_t, $MethodHandle*)},
	{"tableSwitch", "(ILjava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandleImpl$CasesHolder;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, tableSwitch, $Object*, int32_t, $MethodHandle*, $MethodHandleImpl$CasesHolder*, $ObjectArray*), "java.lang.Throwable", nullptr, _MethodHandleImpl_MethodAnnotations_tableSwitch51},
	{"throwException", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, throwException, $MethodHandle*, $MethodType*)},
	{"throwException", "(Ljava/lang/Throwable;)Lsun/invoke/empty/Empty;", "<T:Ljava/lang/Throwable;>(TT;)Lsun/invoke/empty/Empty;^TT;", $STATIC, $staticMethod(MethodHandleImpl, throwException, $Empty*, $Throwable*), "java.lang.Throwable"},
	{"toArray", "(Ljava/util/List;)[Ljava/lang/invoke/MethodHandle;", "(Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;)[Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, toArray, $MethodHandleArray*, $List*)},
	{"tryFinally", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC | $TRANSIENT, $staticMethod(MethodHandleImpl, tryFinally, $Object*, $MethodHandle*, $MethodHandle*, $ObjectArray*), "java.lang.Throwable", nullptr, _MethodHandleImpl_MethodAnnotations_tryFinally55},
	{"unboxResultHandle", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl, unboxResultHandle, $MethodHandle*, $Class*)},
	{"unmatchedArrayAccess", "(Ljava/lang/invoke/MethodHandleImpl$ArrayAccess;)Ljava/lang/InternalError;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, unmatchedArrayAccess, $InternalError*, $MethodHandleImpl$ArrayAccess*)},
	{"valueConversion", "(Ljava/lang/Class;Ljava/lang/Class;ZZ)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;ZZ)Ljava/lang/Object;", $STATIC, $staticMethod(MethodHandleImpl, valueConversion, $Object*, $Class*, $Class*, bool, bool)},
	{"varargsArray", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(MethodHandleImpl, varargsArray, $MethodHandle*, int32_t)},
	{"varargsArray", "(Ljava/lang/Class;I)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;I)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl, varargsArray, $MethodHandle*, $Class*, int32_t)},
	{}
};

$InnerClassInfo _MethodHandleImpl_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandleImpl$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.lang.invoke.MethodHandleImpl$TableSwitchCacheKey", "java.lang.invoke.MethodHandleImpl", "TableSwitchCacheKey", $PRIVATE | $STATIC},
	{"java.lang.invoke.MethodHandleImpl$CasesHolder", "java.lang.invoke.MethodHandleImpl", "CasesHolder", $STATIC},
	{"java.lang.invoke.MethodHandleImpl$LoopClauses", "java.lang.invoke.MethodHandleImpl", "LoopClauses", $STATIC},
	{"java.lang.invoke.MethodHandleImpl$IntrinsicMethodHandle", "java.lang.invoke.MethodHandleImpl", "IntrinsicMethodHandle", $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandleImpl$Intrinsic", "java.lang.invoke.MethodHandleImpl", "Intrinsic", $STATIC | $FINAL | $ENUM},
	{"java.lang.invoke.MethodHandleImpl$WrappedMember", "java.lang.invoke.MethodHandleImpl", "WrappedMember", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandleImpl$BindCaller", "java.lang.invoke.MethodHandleImpl", "BindCaller", $PRIVATE | $STATIC},
	{"java.lang.invoke.MethodHandleImpl$CountingWrapper", "java.lang.invoke.MethodHandleImpl", "CountingWrapper", $STATIC},
	{"java.lang.invoke.MethodHandleImpl$Makers", "java.lang.invoke.MethodHandleImpl", "Makers", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandleImpl$AsVarargsCollector", "java.lang.invoke.MethodHandleImpl", "AsVarargsCollector", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandleImpl$ArrayAccessor", "java.lang.invoke.MethodHandleImpl", "ArrayAccessor", $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandleImpl$ArrayAccess", "java.lang.invoke.MethodHandleImpl", "ArrayAccess", $STATIC | $FINAL | $ENUM},
	{"java.lang.invoke.MethodHandleImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MethodHandleImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.lang.invoke.MethodHandleImpl",
	"java.lang.Object",
	nullptr,
	_MethodHandleImpl_FieldInfo_,
	_MethodHandleImpl_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandleImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandleImpl$2,java.lang.invoke.MethodHandleImpl$TableSwitchCacheKey,java.lang.invoke.MethodHandleImpl$CasesHolder,java.lang.invoke.MethodHandleImpl$LoopClauses,java.lang.invoke.MethodHandleImpl$IntrinsicMethodHandle,java.lang.invoke.MethodHandleImpl$Intrinsic,java.lang.invoke.MethodHandleImpl$WrappedMember,java.lang.invoke.MethodHandleImpl$BindCaller,java.lang.invoke.MethodHandleImpl$BindCaller$1,java.lang.invoke.MethodHandleImpl$CountingWrapper,java.lang.invoke.MethodHandleImpl$CountingWrapper$1,java.lang.invoke.MethodHandleImpl$Makers,java.lang.invoke.MethodHandleImpl$Makers$3,java.lang.invoke.MethodHandleImpl$Makers$2,java.lang.invoke.MethodHandleImpl$Makers$1,java.lang.invoke.MethodHandleImpl$AsVarargsCollector,java.lang.invoke.MethodHandleImpl$ArrayAccessor,java.lang.invoke.MethodHandleImpl$ArrayAccessor$1,java.lang.invoke.MethodHandleImpl$ArrayAccess,java.lang.invoke.MethodHandleImpl$1"
};

$Object* allocate$MethodHandleImpl($Class* clazz) {
	return $of($alloc(MethodHandleImpl));
}

bool MethodHandleImpl::$assertionsDisabled = false;
$MethodHandleArray* MethodHandleImpl::FAKE_METHOD_HANDLE_INVOKE = nullptr;
$MethodHandleArray* MethodHandleImpl::ARRAYS = nullptr;
$LambdaForm$NamedFunctionArray* MethodHandleImpl::NFS = nullptr;
$MethodHandleArray* MethodHandleImpl::HANDLES = nullptr;

void MethodHandleImpl::init$() {
}

$MethodHandle* MethodHandleImpl::makeArrayElementAccessor($Class* arrayClass, $MethodHandleImpl$ArrayAccess* access) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$load($ObjectArray);
	if (arrayClass == $getClass($ObjectArray)) {
		return $MethodHandleImpl$ArrayAccess::objectAccessor(access);
	}
	if (!$nc(arrayClass)->isArray()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"not an array: "_s, arrayClass}))));
	}
	$init($MethodHandleImpl$ArrayAccessor);
	$var($MethodHandleArray, cache, $cast($MethodHandleArray, $nc($MethodHandleImpl$ArrayAccessor::TYPED_ACCESSORS)->get(arrayClass)));
	int32_t cacheIndex = $MethodHandleImpl$ArrayAccess::cacheIndex(access);
	$var($MethodHandle, mh, $nc(cache)->get(cacheIndex));
	if (mh != nullptr) {
		return mh;
	}
	$assign(mh, $MethodHandleImpl$ArrayAccessor::getAccessor(arrayClass, access));
	$var($MethodType, correctType, $MethodHandleImpl$ArrayAccessor::correctType(arrayClass, access));
	if ($nc(mh)->type() != correctType) {
		if (!MethodHandleImpl::$assertionsDisabled && !($cast($Class, $nc($(mh->type()))->parameterType(0)) == $getClass($ObjectArray))) {
			$throwNew($AssertionError);
		}
		if (!MethodHandleImpl::$assertionsDisabled && !(access != $MethodHandleImpl$ArrayAccess::SET || $cast($Class, $nc($(mh->type()))->parameterType(2)) == $Object::class$)) {
			$throwNew($AssertionError);
		}
		bool var$0 = !MethodHandleImpl::$assertionsDisabled;
		if (var$0) {
			bool var$1 = access != $MethodHandleImpl$ArrayAccess::GET;
			if (!var$1) {
				bool var$2 = $cast($Class, $nc($(mh->type()))->returnType()) == $Object::class$;
				if (var$2) {
					var$2 = $nc($($cast($Class, $nc(correctType)->parameterType(0))))->getComponentType() == $cast($Class, correctType->returnType());
				}
				var$1 = (var$2);
			}
			var$0 = !(var$1);
		}
		if (var$0) {
			$throwNew($AssertionError);
		}
		$assign(mh, mh->viewAsType(correctType, false));
	}
	$assign(mh, makeIntrinsic(mh, $($MethodHandleImpl$ArrayAccess::intrinsic(access))));
	$synchronized(cache) {
		if (cache->get(cacheIndex) == nullptr) {
			cache->set(cacheIndex, mh);
		} else {
			$assign(mh, cache->get(cacheIndex));
		}
	}
	return mh;
}

$InternalError* MethodHandleImpl::unmatchedArrayAccess($MethodHandleImpl$ArrayAccess* a) {
	$init(MethodHandleImpl);
	return $MethodHandleStatics::newInternalError($$str({"should not reach here (unmatched ArrayAccess: "_s, a, ")"_s}));
}

$MethodHandle* MethodHandleImpl::makePairwiseConvert($MethodHandle* target, $MethodType* srcType, bool strict, bool monobox) {
	$init(MethodHandleImpl);
	$var($MethodType, dstType, $nc(target)->type());
	if (srcType == dstType) {
		return target;
	}
	return makePairwiseConvertByEditor(target, srcType, strict, monobox);
}

int32_t MethodHandleImpl::countNonNull($ObjectArray* array) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	int32_t count = 0;
	if (array != nullptr) {
		{
			$var($ObjectArray, arr$, array);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, x, arr$->get(i$));
				{
					if (x != nullptr) {
						++count;
					}
				}
			}
		}
	}
	return count;
}

$MethodHandle* MethodHandleImpl::makePairwiseConvertByEditor($MethodHandle* target, $MethodType* srcType, bool strict, bool monobox) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	int32_t MH_RECEIVER_OFFSET = 1;
	$var($ObjectArray, convSpecs, computeValueConversions(srcType, $($nc(target)->type()), strict, monobox));
	int32_t convCount = countNonNull(convSpecs);
	if (convCount == 0) {
		return $nc(target)->viewAsType(srcType, strict);
	}
	$var($MethodType, basicSrcType, $nc(srcType)->basicType());
	$var($MethodType, midType, $nc($($nc(target)->type()))->basicType());
	$var($BoundMethodHandle, mh, target->rebind());
	$var($HashMap, convSpecMap, $new($HashMap, ((4 * convCount) / 3) + 1));
	for (int32_t i = 0; i < $nc(convSpecs)->length - MH_RECEIVER_OFFSET; ++i) {
		$var($Object0, convSpec, convSpecs->get(i));
		if (convSpec == nullptr) {
			continue;
		}
		$var($ints, positions, $cast($ints, convSpecMap->get(convSpec)));
		if (positions == nullptr) {
			$assign(positions, $new($ints, {i + MH_RECEIVER_OFFSET}));
		} else {
			$assign(positions, $Arrays::copyOf(positions, $nc(positions)->length + 1));
			positions->set(positions->length - 1, i + MH_RECEIVER_OFFSET);
		}
		convSpecMap->put(convSpec, positions);
	}
	{
		$var($Iterator, i$, $nc($(convSpecMap->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($Object, convSpec, $nc(entry)->getKey());
				$var($MethodHandle, fn, nullptr);
				if ($instanceOf($Class, convSpec)) {
					$assign(fn, $nc($(getConstantHandle(MethodHandleImpl::MH_cast)))->bindTo(convSpec));
				} else {
					$assign(fn, $cast($MethodHandle, convSpec));
				}
				$var($ints, positions, $cast($ints, entry->getValue()));
				$Class* newType = $cast($Class, $nc(basicSrcType)->parameterType($nc(positions)->get(0) - MH_RECEIVER_OFFSET));
				$LambdaForm$BasicType* newBasicType = $LambdaForm$BasicType::basicType(newType);
				convCount -= $nc(positions)->length;
				if (convCount == 0) {
					$assign(midType, srcType);
				} else {
					$var($ClassArray, ptypes, $cast($ClassArray, $nc($($nc(midType)->ptypes()))->clone()));
					{
						$var($ints, arr$, positions);
						int32_t len$ = arr$->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							int32_t pos = arr$->get(i$);
							{
								ptypes->set(pos - 1, newType);
							}
						}
					}
					$assign(midType, $MethodType::makeImpl(midType->rtype(), ptypes, true));
				}
				$var($LambdaForm, form2, nullptr);
				if (positions->length > 1) {
					$assign(form2, $nc($($nc(mh)->editor()))->filterRepeatedArgumentForm(newBasicType, positions));
				} else {
					$assign(form2, $nc($($nc(mh)->editor()))->filterArgumentForm(positions->get(0), newBasicType));
				}
				$assign(mh, $nc(mh)->copyWithExtendL(midType, form2, fn));
			}
		}
	}
	$var($Object0, convSpec, $nc(convSpecs)->get(convSpecs->length - 1));
	if (convSpec != nullptr) {
		$var($MethodHandle, fn, nullptr);
		if ($instanceOf($Class, convSpec)) {
			$init($Void);
			if ($equals(convSpec, $Void::TYPE)) {
				$assign(fn, nullptr);
			} else {
				$assign(fn, $nc($(getConstantHandle(MethodHandleImpl::MH_cast)))->bindTo(convSpec));
			}
		} else {
			$assign(fn, $cast($MethodHandle, convSpec));
		}
		$Class* newType = $cast($Class, $nc(basicSrcType)->returnType());
		if (!MethodHandleImpl::$assertionsDisabled && !(--convCount == 0)) {
			$throwNew($AssertionError);
		}
		$assign(midType, srcType);
		if (fn != nullptr) {
			$assign(mh, $nc(mh)->rebind());
			$var($LambdaForm, form2, $nc($(mh->editor()))->filterReturnForm($($LambdaForm$BasicType::basicType(newType)), false));
			$assign(mh, mh->copyWithExtendL(midType, form2, fn));
		} else {
			$var($LambdaForm, form2, $nc($($nc(mh)->editor()))->filterReturnForm($($LambdaForm$BasicType::basicType(newType)), true));
			$assign(mh, mh->copyWith(midType, form2));
		}
	}
	if (!MethodHandleImpl::$assertionsDisabled && !(convCount == 0)) {
		$throwNew($AssertionError);
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc($($nc(mh)->type()))->equals($of(srcType)))) {
		$throwNew($AssertionError);
	}
	return mh;
}

$ObjectArray* MethodHandleImpl::computeValueConversions($MethodType* srcType, $MethodType* dstType, bool strict, bool monobox) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	int32_t INARG_COUNT = $nc(srcType)->parameterCount();
	$var($ObjectArray, convSpecs, nullptr);
	for (int32_t i = 0; i <= INARG_COUNT; ++i) {
		bool isRet = (i == INARG_COUNT);
		$Class* src = isRet ? $cast($Class, $nc(dstType)->returnType()) : $cast($Class, srcType->parameterType(i));
		$Class* dst = isRet ? $cast($Class, srcType->returnType()) : $cast($Class, dstType->parameterType(i));
		if (!$VerifyType::isNullConversion(src, dst, strict)) {
			if (convSpecs == nullptr) {
				$assign(convSpecs, $new($ObjectArray, INARG_COUNT + 1));
			}
			$nc(convSpecs)->set(i, $(valueConversion(src, dst, strict, monobox)));
		}
	}
	return convSpecs;
}

$MethodHandle* MethodHandleImpl::makePairwiseConvert($MethodHandle* target, $MethodType* srcType, bool strict) {
	$init(MethodHandleImpl);
	return makePairwiseConvert(target, srcType, strict, false);
}

$Object* MethodHandleImpl::valueConversion($Class* src, $Class* dst, bool strict, bool monobox) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	if (!MethodHandleImpl::$assertionsDisabled && !(!$VerifyType::isNullConversion(src, dst, strict))) {
		$throwNew($AssertionError);
	}
	$init($Void);
	if (dst == $Void::TYPE) {
		return $of(dst);
	}
	$var($MethodHandle, fn, nullptr);
	if ($nc(src)->isPrimitive()) {
		if (src == $Void::TYPE) {
			return $of($Void::TYPE);
		} else if ($nc(dst)->isPrimitive()) {
			$assign(fn, $ValueConversions::convertPrimitive(src, dst));
		} else {
			$Wrapper* wsrc = $Wrapper::forPrimitiveType(src);
			$assign(fn, $ValueConversions::boxExact(wsrc));
			bool var$0 = !MethodHandleImpl::$assertionsDisabled;
			if (var$0) {
				var$0 = !($cast($Class, $nc($($nc(fn)->type()))->parameterType(0)) == $nc(wsrc)->primitiveType());
			}
			if (var$0) {
				$throwNew($AssertionError);
			}
			bool var$1 = !MethodHandleImpl::$assertionsDisabled;
			if (var$1) {
				var$1 = !($cast($Class, $nc($($nc(fn)->type()))->returnType()) == $nc(wsrc)->wrapperType());
			}
			if (var$1) {
				$throwNew($AssertionError);
			}
			if (!$VerifyType::isNullConversion($nc(wsrc)->wrapperType(), dst, strict)) {
				$var($MethodType, mt, $MethodType::methodType(dst, src));
				if (strict) {
					$assign(fn, $nc(fn)->asType(mt));
				} else {
					$assign(fn, MethodHandleImpl::makePairwiseConvert(fn, mt, false));
				}
			}
		}
	} else if ($nc(dst)->isPrimitive()) {
		$Wrapper* wdst = $Wrapper::forPrimitiveType(dst);
		if (monobox || src == $nc(wdst)->wrapperType()) {
			$assign(fn, $ValueConversions::unboxExact(wdst, strict));
		} else {
			$assign(fn, strict ? $ValueConversions::unboxWiden(wdst) : $ValueConversions::unboxCast(wdst));
		}
	} else {
		return $of(dst);
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc($($nc(fn)->type()))->parameterCount() <= 1)) {
		$throwNew($AssertionError, $of($$str({"pc"_s, $($Arrays::asList($$new($ConstableArray, {
			$(static_cast<$Constable*>($nc(src)->getSimpleName())),
			$(static_cast<$Constable*>($nc(dst)->getSimpleName())),
			static_cast<$Constable*>(fn)
		})))})));
	}
	return $of(fn);
}

$MethodHandle* MethodHandleImpl::makeVarargsCollector($MethodHandle* target$renamed, $Class* arrayType) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, target, target$renamed);
	$var($MethodType, type, $nc(target)->type());
	int32_t last = $nc(type)->parameterCount() - 1;
	if ($cast($Class, type->parameterType(last)) != arrayType) {
		$assign(target, target->asType($(type->changeParameterType(last, arrayType))));
	}
	$assign(target, target->asFixedArity());
	return $new($MethodHandleImpl$AsVarargsCollector, target, arrayType);
}

void MethodHandleImpl::checkSpreadArgument(Object$* av, int32_t n) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	if (av == nullptr && n == 0) {
		return;
	} else if (av == nullptr) {
		$throwNew($NullPointerException, "null array reference"_s);
	} else if ($instanceOf($ObjectArray, av)) {
		int32_t len = $nc(($cast($ObjectArray, av)))->length;
		if (len == n) {
			return;
		}
	} else {
		int32_t len = $1Array::getLength(av);
		if (len == n) {
			return;
		}
	}
	$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"array is not of length "_s, $$str(n)}))));
}

$MethodHandle* MethodHandleImpl::selectAlternative(bool testResult, $MethodHandle* target, $MethodHandle* fallback) {
	$init(MethodHandleImpl);
	if (testResult) {
		return target;
	} else {
		return fallback;
	}
}

bool MethodHandleImpl::profileBoolean(bool result, $ints* counters) {
	$init(MethodHandleImpl);
	int32_t idx = result ? 1 : 0;
	try {
		$nc(counters)->set(idx, $Math::addExact(counters->get(idx), 1));
	} catch ($ArithmeticException& e) {
		$nc(counters)->set(idx, counters->get(idx) / 2);
	}
	return result;
}

bool MethodHandleImpl::isCompileConstant(Object$* obj) {
	$init(MethodHandleImpl);
	return false;
}

$MethodHandle* MethodHandleImpl::makeGuardWithTest($MethodHandle* test, $MethodHandle* target, $MethodHandle* fallback) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $nc(target)->type());
	bool var$0 = !MethodHandleImpl::$assertionsDisabled;
	if (var$0) {
		$init($Boolean);
		bool var$1 = $nc($($nc(test)->type()))->equals($($of($nc(type)->changeReturnType($Boolean::TYPE))));
		var$0 = !(var$1 && $nc($($nc(fallback)->type()))->equals($of(type)));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($MethodType, basicType, $nc(type)->basicType());
	$var($LambdaForm, form, makeGuardWithTestForm(basicType));
	$var($BoundMethodHandle, mh, nullptr);
	try {
		$init($MethodHandleStatics);
		if ($MethodHandleStatics::PROFILE_GWT) {
			$var($ints, counts, $new($ints, 2));
			$var($Object, var$2, $of(type));
			$var($Object, var$3, $of(form));
			$var($Object, var$4, $of(test));
			$var($Object, var$5, $of(profile(target)));
			$assign(mh, $cast($BoundMethodHandle, $nc($($nc($($BoundMethodHandle::speciesData_LLLL()))->factory()))->invokeBasic($$new($ObjectArray, {var$2, var$3, var$4, var$5, $of($(profile(fallback))), $of(counts)}))));
		} else {
			$var($Object, var$6, $of(type));
			$var($Object, var$7, $of(form));
			$var($Object, var$8, $of(test));
			$var($Object, var$9, $of(profile(target)));
			$assign(mh, $cast($BoundMethodHandle, $nc($($nc($($BoundMethodHandle::speciesData_LLL()))->factory()))->invokeBasic($$new($ObjectArray, {var$6, var$7, var$8, var$9, $of($(profile(fallback)))}))));
		}
	} catch ($Throwable& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(mh)->type() == type)) {
		$throwNew($AssertionError);
	}
	return mh;
}

$MethodHandle* MethodHandleImpl::profile($MethodHandle* target) {
	$init(MethodHandleImpl);
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DONT_INLINE_THRESHOLD >= 0) {
		return makeBlockInliningWrapper(target);
	} else {
		return target;
	}
}

$MethodHandle* MethodHandleImpl::makeBlockInliningWrapper($MethodHandle* target) {
	$init(MethodHandleImpl);
	$var($LambdaForm, lform, nullptr);
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DONT_INLINE_THRESHOLD > 0) {
		$init($MethodHandleImpl$Makers);
		$assign(lform, $cast($LambdaForm, $nc($MethodHandleImpl$Makers::PRODUCE_BLOCK_INLINING_FORM)->apply(target)));
	} else {
		$init($MethodHandleImpl$Makers);
		$assign(lform, $cast($LambdaForm, $nc($MethodHandleImpl$Makers::PRODUCE_REINVOKER_FORM)->apply(target)));
	}
	$init($MethodHandleImpl$Makers);
	return $new($MethodHandleImpl$CountingWrapper, target, lform, $MethodHandleImpl$Makers::PRODUCE_BLOCK_INLINING_FORM, $MethodHandleImpl$Makers::PRODUCE_REINVOKER_FORM, $MethodHandleStatics::DONT_INLINE_THRESHOLD);
}

$LambdaForm* MethodHandleImpl::makeGuardWithTestForm($MethodType* basicType) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm, lform, $nc($($nc(basicType)->form()))->cachedLambdaForm($MethodTypeForm::LF_GWT));
	if (lform != nullptr) {
		return lform;
	}
	int32_t THIS_MH = 0;
	int32_t ARG_BASE = 1;
	int32_t ARG_LIMIT = ARG_BASE + basicType->parameterCount();
	int32_t nameCursor = ARG_LIMIT;
	int32_t GET_TEST = nameCursor++;
	int32_t GET_TARGET = nameCursor++;
	int32_t GET_FALLBACK = nameCursor++;
	$init($MethodHandleStatics);
	int32_t GET_COUNTERS = $MethodHandleStatics::PROFILE_GWT ? nameCursor++ : -1;
	int32_t CALL_TEST = nameCursor++;
	int32_t PROFILE = (GET_COUNTERS != -1) ? nameCursor++ : -1;
	int32_t TEST = nameCursor - 1;
	int32_t SELECT_ALT = nameCursor++;
	int32_t CALL_TARGET = nameCursor++;
	if (!MethodHandleImpl::$assertionsDisabled && !(CALL_TARGET == SELECT_ALT + 1)) {
		$throwNew($AssertionError);
	}
	$var($MethodType, lambdaType, basicType->invokerType());
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - ARG_LIMIT, lambdaType));
	$var($BoundMethodHandle$SpeciesData, data, (GET_COUNTERS != -1) ? $BoundMethodHandle::speciesData_LLLL() : $BoundMethodHandle::speciesData_LLL());
	$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(data)));
	names->set(GET_TEST, $$new($LambdaForm$Name, $($nc(data)->getterFunction(0)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_TARGET, $$new($LambdaForm$Name, $($nc(data)->getterFunction(1)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_FALLBACK, $$new($LambdaForm$Name, $($nc(data)->getterFunction(2)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	if (GET_COUNTERS != -1) {
		names->set(GET_COUNTERS, $$new($LambdaForm$Name, $($nc(data)->getterFunction(3)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	}
	$load($ObjectArray);
	$var($ObjectArray, invokeArgs, $Arrays::copyOfRange(names, 0, ARG_LIMIT, $getClass($ObjectArray)));
	$init($Boolean);
	$var($MethodType, testType, $nc($(basicType->changeReturnType($Boolean::TYPE)))->basicType());
	invokeArgs->set(0, names->get(GET_TEST));
	names->set(CALL_TEST, $$new($LambdaForm$Name, testType, invokeArgs));
	if (PROFILE != -1) {
		names->set(PROFILE, $$new($LambdaForm$Name, $(getFunction(MethodHandleImpl::NF_profileBoolean)), $$new($ObjectArray, {
			$of(names->get(CALL_TEST)),
			$of(names->get(GET_COUNTERS))
		})));
	}
	$init($MethodHandleImpl$Intrinsic);
	names->set(SELECT_ALT, $$new($LambdaForm$Name, $$new($LambdaForm$NamedFunction, $(makeIntrinsic($(getConstantHandle(MethodHandleImpl::MH_selectAlternative)), $MethodHandleImpl$Intrinsic::SELECT_ALTERNATIVE))), $$new($ObjectArray, {
		$of(names->get(TEST)),
		$of(names->get(GET_TARGET)),
		$of(names->get(GET_FALLBACK))
	})));
	invokeArgs->set(0, names->get(SELECT_ALT));
	names->set(CALL_TARGET, $$new($LambdaForm$Name, basicType, invokeArgs));
	$init($LambdaForm$Kind);
	$assign(lform, $new($LambdaForm, $nc(lambdaType)->parameterCount(), names, true, $LambdaForm$Kind::GUARD));
	return $nc($(basicType->form()))->setCachedLambdaForm($MethodTypeForm::LF_GWT, lform);
}

$LambdaForm* MethodHandleImpl::makeGuardWithCatchForm($MethodType* basicType) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, lambdaType, $nc(basicType)->invokerType());
	$var($LambdaForm, lform, $nc($(basicType->form()))->cachedLambdaForm($MethodTypeForm::LF_GWC));
	if (lform != nullptr) {
		return lform;
	}
	int32_t THIS_MH = 0;
	int32_t ARG_BASE = 1;
	int32_t ARG_LIMIT = ARG_BASE + basicType->parameterCount();
	int32_t nameCursor = ARG_LIMIT;
	int32_t GET_TARGET = nameCursor++;
	int32_t GET_CLASS = nameCursor++;
	int32_t GET_CATCHER = nameCursor++;
	int32_t GET_COLLECT_ARGS = nameCursor++;
	int32_t GET_UNBOX_RESULT = nameCursor++;
	int32_t BOXED_ARGS = nameCursor++;
	int32_t TRY_CATCH = nameCursor++;
	int32_t UNBOX_RESULT = nameCursor++;
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - ARG_LIMIT, lambdaType));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLLLL());
	$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(data)));
	names->set(GET_TARGET, $$new($LambdaForm$Name, $($nc(data)->getterFunction(0)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_CLASS, $$new($LambdaForm$Name, $($nc(data)->getterFunction(1)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_CATCHER, $$new($LambdaForm$Name, $($nc(data)->getterFunction(2)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_COLLECT_ARGS, $$new($LambdaForm$Name, $($nc(data)->getterFunction(3)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_UNBOX_RESULT, $$new($LambdaForm$Name, $($nc(data)->getterFunction(4)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	$var($MethodType, collectArgsType, basicType->changeReturnType($Object::class$));
	$var($MethodHandle, invokeBasic, $MethodHandles::basicInvoker(collectArgsType));
	$var($ObjectArray, args, $new($ObjectArray, $nc($($nc(invokeBasic)->type()))->parameterCount()));
	args->set(0, names->get(GET_COLLECT_ARGS));
	$System::arraycopy(names, ARG_BASE, args, 1, ARG_LIMIT - ARG_BASE);
	$init($MethodHandleImpl$Intrinsic);
	names->set(BOXED_ARGS, $$new($LambdaForm$Name, $$new($LambdaForm$NamedFunction, $(makeIntrinsic(invokeBasic, $MethodHandleImpl$Intrinsic::GUARD_WITH_CATCH))), args));
	$var($ObjectArray, gwcArgs, $new($ObjectArray, {
		$of(names->get(GET_TARGET)),
		$of(names->get(GET_CLASS)),
		$of(names->get(GET_CATCHER)),
		$of(names->get(BOXED_ARGS))
	}));
	names->set(TRY_CATCH, $$new($LambdaForm$Name, $(getFunction(MethodHandleImpl::NF_guardWithCatch)), gwcArgs));
	$var($MethodHandle, invokeBasicUnbox, $MethodHandles::basicInvoker($($MethodType::methodType(basicType->rtype(), $Object::class$))));
	$var($ObjectArray, unboxArgs, $new($ObjectArray, {
		$of(names->get(GET_UNBOX_RESULT)),
		$of(names->get(TRY_CATCH))
	}));
	names->set(UNBOX_RESULT, $$new($LambdaForm$Name, invokeBasicUnbox, unboxArgs));
	$init($LambdaForm$Kind);
	$assign(lform, $new($LambdaForm, $nc(lambdaType)->parameterCount(), names, $LambdaForm$Kind::GUARD_WITH_CATCH));
	return $nc($(basicType->form()))->setCachedLambdaForm($MethodTypeForm::LF_GWC, lform);
}

$MethodHandle* MethodHandleImpl::makeGuardWithCatch($MethodHandle* target, $Class* exType, $MethodHandle* catcher) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $nc(target)->type());
	$var($LambdaForm, form, makeGuardWithCatchForm($($nc(type)->basicType())));
	$load($ObjectArray);
	$var($MethodType, varargsType, $nc(type)->changeReturnType($getClass($ObjectArray)));
	$var($MethodHandle, collectArgs, $nc($(varargsArray(type->parameterCount())))->asType(varargsType));
	$var($MethodHandle, unboxResult, unboxResultHandle($($cast($Class, type->returnType()))));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLLLL());
	$var($BoundMethodHandle, mh, nullptr);
	try {
		$assign(mh, $cast($BoundMethodHandle, $nc($($nc(data)->factory()))->invokeBasic($$new($ObjectArray, {$of(type), $of(form), $of(target), $of(exType), $of(catcher), $of(collectArgs), $of(unboxResult)}))));
	} catch ($Throwable& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(mh)->type() == type)) {
		$throwNew($AssertionError);
	}
	return mh;
}

$Object* MethodHandleImpl::guardWithCatch($MethodHandle* target, $Class* exType, $MethodHandle* catcher, $ObjectArray* av) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	try {
		return $of($nc($($nc(target)->asFixedArity()))->invokeWithArguments(av));
	} catch ($Throwable& t) {
		if (!$nc(exType)->isInstance(t)) {
			$throw(t);
		}
		return $of($nc($($nc(catcher)->asFixedArity()))->invokeWithArguments($(prepend(av, $$new($ObjectArray, {$of(t)})))));
	}
	$shouldNotReachHere();
}

$ObjectArray* MethodHandleImpl::prepend($ObjectArray* array, $ObjectArray* elems) {
	$init(MethodHandleImpl);
	int32_t nArray = $nc(array)->length;
	int32_t nElems = $nc(elems)->length;
	$var($ObjectArray, newArray, $new($ObjectArray, nArray + nElems));
	$System::arraycopy(elems, 0, newArray, 0, nElems);
	$System::arraycopy(array, 0, newArray, nElems, nArray);
	return newArray;
}

$MethodHandle* MethodHandleImpl::throwException($MethodType* type) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	if (!MethodHandleImpl::$assertionsDisabled && !($Throwable::class$->isAssignableFrom($($cast($Class, $nc(type)->parameterType(0)))))) {
		$throwNew($AssertionError);
	}
	int32_t arity = $nc(type)->parameterCount();
	if (arity > 1) {
		$var($MethodHandle, mh, throwException($($cast($MethodType, type->dropParameterTypes(1, arity)))));
		$assign(mh, $MethodHandles::dropArguments(mh, 1, $fcast($ClassArray, $($Arrays::copyOfRange($(type->parameterArray()), 1, arity)))));
		return mh;
	}
	return makePairwiseConvert($($nc($(getFunction(MethodHandleImpl::NF_throwException)))->resolvedHandle()), type, false, true);
}

$Empty* MethodHandleImpl::throwException($Throwable* t) {
	$init(MethodHandleImpl);
	$throw(t);
	$shouldNotReachHere();
}

$MethodHandle* MethodHandleImpl::fakeMethodHandleInvoke($MemberName* method) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(method)->isMethodHandleInvoke())) {
		$throwNew($AssertionError);
	}
	$var($String, s46107$, $nc(method)->getName());
	int32_t tmp46107$ = -1;
	switch ($nc(s46107$)->hashCode()) {
	case (int32_t)0xB9724478:
		{
			if (s46107$->equals("invoke"_s)) {
				tmp46107$ = 0;
			}
			break;
		}
	case 0x38222167:
		{
			if (s46107$->equals("invokeExact"_s)) {
				tmp46107$ = 1;
			}
			break;
		}
	}

	int32_t var$0 = 0;
	switch (tmp46107$) {
	case 0:
		{
			var$0 = 0;
			break;
		}
	case 1:
		{
			var$0 = 1;
			break;
		}
	default:
		{
			$throwNew($InternalError, $($nc(method)->getName()));
		}
	}
	int32_t idx = var$0;
	$var($MethodHandle, mh, $nc(MethodHandleImpl::FAKE_METHOD_HANDLE_INVOKE)->get(idx));
	if (mh != nullptr) {
		return mh;
	}
	$load($UnsupportedOperationException);
	$load($MethodHandle);
	$load($ObjectArray);
	$var($MethodType, type, $MethodType::methodType($Object::class$, $UnsupportedOperationException::class$, $$new($ClassArray, {
		$MethodHandle::class$,
		$getClass($ObjectArray)
	})));
	$assign(mh, throwException(type));
	$assign(mh, $nc(mh)->bindTo($$new($UnsupportedOperationException, "cannot reflectively invoke MethodHandle"_s)));
	if (!$nc($($nc(method)->getInvocationType()))->equals($($of(mh->type())))) {
		$throwNew($InternalError, $(method->toString()));
	}
	$assign(mh, mh->withInternalMemberName(method, false));
	$assign(mh, mh->withVarargs(true));
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(method)->isVarargs())) {
		$throwNew($AssertionError);
	}
	$nc(MethodHandleImpl::FAKE_METHOD_HANDLE_INVOKE)->set(idx, mh);
	return mh;
}

$MethodHandle* MethodHandleImpl::fakeVarHandleInvoke($MemberName* method) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$load($UnsupportedOperationException);
	$load($VarHandle);
	$load($ObjectArray);
	$var($MethodType, type, $MethodType::methodType($nc(method)->getReturnType(), $UnsupportedOperationException::class$, $$new($ClassArray, {
		$VarHandle::class$,
		$getClass($ObjectArray)
	})));
	$var($MethodHandle, mh, throwException(type));
	$assign(mh, $nc(mh)->bindTo($$new($UnsupportedOperationException, "cannot reflectively invoke VarHandle"_s)));
	if (!$nc($($nc(method)->getInvocationType()))->equals($($of(mh->type())))) {
		$throwNew($InternalError, $(method->toString()));
	}
	$assign(mh, mh->withInternalMemberName(method, false));
	$assign(mh, mh->asVarargsCollector($getClass($ObjectArray)));
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(method)->isVarargs())) {
		$throwNew($AssertionError);
	}
	return mh;
}

$MethodHandle* MethodHandleImpl::bindCaller($MethodHandle* mh, $Class* hostClass) {
	$init(MethodHandleImpl);
	return $MethodHandleImpl$BindCaller::bindCaller(mh, hostClass);
}

$MethodHandle* MethodHandleImpl::makeWrappedMember($MethodHandle* target, $MemberName* member, bool isInvokeSpecial) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(member)->equals($($nc(target)->internalMemberName()));
	if (var$0 && isInvokeSpecial == $nc(target)->isInvokeSpecial()) {
		return target;
	}
	return $new($MethodHandleImpl$WrappedMember, target, $($nc(target)->type()), member, isInvokeSpecial, nullptr);
}

$MethodHandle* MethodHandleImpl::makeIntrinsic($MethodHandle* target, $MethodHandleImpl$Intrinsic* intrinsicName) {
	$init(MethodHandleImpl);
	return makeIntrinsic(target, intrinsicName, ($Object*)nullptr);
}

$MethodHandle* MethodHandleImpl::makeIntrinsic($MethodHandle* target, $MethodHandleImpl$Intrinsic* intrinsicName, Object$* intrinsicData) {
	$init(MethodHandleImpl);
	if (intrinsicName == $nc(target)->intrinsicName()) {
		return target;
	}
	return $new($MethodHandleImpl$IntrinsicMethodHandle, target, intrinsicName, intrinsicData);
}

$MethodHandle* MethodHandleImpl::makeIntrinsic($MethodType* type, $LambdaForm* form, $MethodHandleImpl$Intrinsic* intrinsicName) {
	$init(MethodHandleImpl);
	return $new($MethodHandleImpl$IntrinsicMethodHandle, $($SimpleMethodHandle::make(type, form)), intrinsicName);
}

$MethodHandle* MethodHandleImpl::varargsArray(int32_t nargs) {
	$init(MethodHandleImpl);
	$var($MethodHandle, mh, $nc(MethodHandleImpl::ARRAYS)->get(nargs));
	if (mh != nullptr) {
		return mh;
	}
	$load($ObjectArray);
	$assign(mh, makeCollector($getClass($ObjectArray), nargs));
	if (!MethodHandleImpl::$assertionsDisabled && !(assertCorrectArity(mh, nargs))) {
		$throwNew($AssertionError);
	}
	return $nc(MethodHandleImpl::ARRAYS)->set(nargs, mh);
}

$MethodHandle* MethodHandleImpl::varargsArray($Class* arrayType, int32_t nargs) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$Class* elemType = $nc(arrayType)->getComponentType();
	if (elemType == nullptr) {
		$throwNew($IllegalArgumentException, $$str({"not an array: "_s, arrayType}));
	}
	if (nargs >= MethodHandleImpl::MAX_JVM_ARITY / 2 - 1) {
		int32_t slots = nargs;
		int32_t MAX_ARRAY_SLOTS = MethodHandleImpl::MAX_JVM_ARITY - 1;
		if (slots <= MAX_ARRAY_SLOTS && $nc(elemType)->isPrimitive()) {
			slots *= $nc($($Wrapper::forPrimitiveType(elemType)))->stackSlots();
		}
		if (slots > MAX_ARRAY_SLOTS) {
			$throwNew($IllegalArgumentException, $$str({"too many arguments: "_s, $(arrayType->getSimpleName()), ", length "_s, $$str(nargs)}));
		}
	}
	if (elemType == $Object::class$) {
		return varargsArray(nargs);
	}
	$init($MethodHandleImpl$Makers);
	$var($MethodHandleArray, cache, $cast($MethodHandleArray, $nc($MethodHandleImpl$Makers::TYPED_COLLECTORS)->get(elemType)));
	$var($MethodHandle, mh, nargs < $nc(cache)->length ? $nc(cache)->get(nargs) : ($MethodHandle*)nullptr);
	if (mh != nullptr) {
		return mh;
	}
	$assign(mh, makeCollector(arrayType, nargs));
	if (!MethodHandleImpl::$assertionsDisabled && !(assertCorrectArity(mh, nargs))) {
		$throwNew($AssertionError);
	}
	if (nargs < cache->length) {
		cache->set(nargs, mh);
	}
	return mh;
}

bool MethodHandleImpl::assertCorrectArity($MethodHandle* mh, int32_t arity) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	if (!MethodHandleImpl::$assertionsDisabled && !($nc($($nc(mh)->type()))->parameterCount() == arity)) {
		$throwNew($AssertionError, $of($$str({"arity != "_s, $$str(arity), ": "_s, mh})));
	}
	return true;
}

void MethodHandleImpl::assertSame(Object$* mh1, Object$* mh2) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	if (!$equals(mh1, mh2)) {
		$var($String, msg, $String::format("mh1 != mh2: mh1 = %s (form: %s); mh2 = %s (form: %s)"_s, $$new($ObjectArray, {
			mh1,
			$of($nc(($cast($MethodHandle, mh1)))->form),
			mh2,
			$of($nc(($cast($MethodHandle, mh2)))->form)
		})));
		$throw($($MethodHandleStatics::newInternalError(msg)));
	}
}

$LambdaForm$NamedFunction* MethodHandleImpl::getFunction(int8_t func) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$NamedFunction, nf, $nc(MethodHandleImpl::NFS)->get(func));
	if (nf != nullptr) {
		return nf;
	}
	return $nc(MethodHandleImpl::NFS)->set(func, $(createFunction(func)));
}

$LambdaForm$NamedFunction* MethodHandleImpl::createFunction(int8_t func) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {

		$var($LambdaForm$NamedFunction, var$0, nullptr)
		switch (func) {
		case MethodHandleImpl::NF_checkSpreadArgument:
			{
				$init($Integer);
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("checkSpreadArgument"_s, $$new($ClassArray, {
					$Object::class$,
					$Integer::TYPE
				})))));
				break;
			}
		case MethodHandleImpl::NF_guardWithCatch:
			{
				$load($MethodHandle);
				$load($ObjectArray);
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("guardWithCatch"_s, $$new($ClassArray, {
					$MethodHandle::class$,
					$Class::class$,
					$MethodHandle::class$,
					$getClass($ObjectArray)
				})))));
				break;
			}
		case MethodHandleImpl::NF_tryFinally:
			{
				$load($MethodHandle);
				$load($ObjectArray);
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("tryFinally"_s, $$new($ClassArray, {
					$MethodHandle::class$,
					$MethodHandle::class$,
					$getClass($ObjectArray)
				})))));
				break;
			}
		case MethodHandleImpl::NF_loop:
			{
				$load($LambdaForm$BasicTypeArray);
				$load($MethodHandleImpl$LoopClauses);
				$load($ObjectArray);
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("loop"_s, $$new($ClassArray, {
					$getClass($LambdaForm$BasicTypeArray),
					$MethodHandleImpl$LoopClauses::class$,
					$getClass($ObjectArray)
				})))));
				break;
			}
		case MethodHandleImpl::NF_throwException:
			{
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("throwException"_s, $$new($ClassArray, {$Throwable::class$})))));
				break;
			}
		case MethodHandleImpl::NF_profileBoolean:
			{
				$init($Boolean);
				$load($ints);
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("profileBoolean"_s, $$new($ClassArray, {
					$Boolean::TYPE,
					$getClass($ints)
				})))));
				break;
			}
		case MethodHandleImpl::NF_tableSwitch:
			{
				$init($Integer);
				$load($MethodHandle);
				$load($MethodHandleImpl$CasesHolder);
				$load($ObjectArray);
				$assign(var$0, $new($LambdaForm$NamedFunction, $(MethodHandleImpl::class$->getDeclaredMethod("tableSwitch"_s, $$new($ClassArray, {
					$Integer::TYPE,
					$MethodHandle::class$,
					$MethodHandleImpl$CasesHolder::class$,
					$getClass($ObjectArray)
				})))));
				break;
			}
		default:
			{
				$throwNew($InternalError, $$str({"Undefined function: "_s, $$str(func)}));
			}
		}
		return var$0;
	} catch ($ReflectiveOperationException& ex) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(ex))));
	}
	$shouldNotReachHere();
}

$MethodHandle* MethodHandleImpl::unboxResultHandle($Class* returnType) {
	$init(MethodHandleImpl);
	if ($nc(returnType)->isPrimitive()) {
		$init($Void);
		if (returnType == $Void::TYPE) {
			return $ValueConversions::ignore();
		} else {
			$Wrapper* w = $Wrapper::forPrimitiveType(returnType);
			return $ValueConversions::unboxExact(w);
		}
	} else {
		return $MethodHandles::identity($Object::class$);
	}
}

$MethodHandle* MethodHandleImpl::makeLoop($Class* tloop, $List* targs, $List* init, $List* step, $List* pred, $List* fini) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $MethodType::methodType(tloop, targs));
	$var($LambdaForm$BasicTypeArray, initClauseTypes, $fcast($LambdaForm$BasicTypeArray, $nc($($nc($($nc($($nc(init)->stream()))->map(static_cast<$Function*>($$new(MethodHandleImpl$$Lambda$lambda$makeLoop$0)))))->map(static_cast<$Function*>($$new(MethodHandleImpl$$Lambda$basicType$1)))))->toArray(static_cast<$IntFunction*>($$new(MethodHandleImpl$$Lambda$lambda$makeLoop$1$2)))));
	$var($LambdaForm, form, makeLoopForm($($nc(type)->basicType()), initClauseTypes));
	$load($ObjectArray);
	$var($MethodType, varargsType, $nc(type)->changeReturnType($getClass($ObjectArray)));
	$var($MethodHandle, collectArgs, $nc($(varargsArray(type->parameterCount())))->asType(varargsType));
	$var($MethodHandle, unboxResult, unboxResultHandle(tloop));
	$var($MethodHandleImpl$LoopClauses, clauseData, $new($MethodHandleImpl$LoopClauses, $$new($MethodHandleArray2, {
		$(toArray(init)),
		$(toArray(step)),
		$(toArray(pred)),
		$(toArray(fini))
	})));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLL());
	$var($BoundMethodHandle, mh, nullptr);
	try {
		$assign(mh, $cast($BoundMethodHandle, $nc($($nc(data)->factory()))->invokeBasic($$new($ObjectArray, {$of(type), $of(form), $of(clauseData), $of(collectArgs), $of(unboxResult)}))));
	} catch ($Throwable& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(mh)->type() == type)) {
		$throwNew($AssertionError);
	}
	return mh;
}

$MethodHandleArray* MethodHandleImpl::toArray($List* l) {
	$init(MethodHandleImpl);
	return $fcast($MethodHandleArray, $nc(l)->toArray($$new($MethodHandleArray, 0)));
}

$LambdaForm* MethodHandleImpl::makeLoopForm($MethodType* basicType, $LambdaForm$BasicTypeArray* localVarTypes) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, lambdaType, $nc(basicType)->invokerType());
	int32_t THIS_MH = 0;
	int32_t ARG_BASE = 1;
	int32_t ARG_LIMIT = ARG_BASE + basicType->parameterCount();
	int32_t nameCursor = ARG_LIMIT;
	int32_t GET_CLAUSE_DATA = nameCursor++;
	int32_t GET_COLLECT_ARGS = nameCursor++;
	int32_t GET_UNBOX_RESULT = nameCursor++;
	int32_t BOXED_ARGS = nameCursor++;
	int32_t LOOP = nameCursor++;
	int32_t UNBOX_RESULT = nameCursor++;
	$var($LambdaForm, lform, $nc($(basicType->form()))->cachedLambdaForm($MethodTypeForm::LF_LOOP));
	if (lform == nullptr) {
		$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - ARG_LIMIT, lambdaType));
		$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLL());
		$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(data)));
		names->set(GET_CLAUSE_DATA, $$new($LambdaForm$Name, $($nc(data)->getterFunction(0)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
		names->set(GET_COLLECT_ARGS, $$new($LambdaForm$Name, $($nc(data)->getterFunction(1)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
		names->set(GET_UNBOX_RESULT, $$new($LambdaForm$Name, $($nc(data)->getterFunction(2)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
		$var($MethodType, collectArgsType, basicType->changeReturnType($Object::class$));
		$var($MethodHandle, invokeBasic, $MethodHandles::basicInvoker(collectArgsType));
		$var($ObjectArray, args, $new($ObjectArray, $nc($($nc(invokeBasic)->type()))->parameterCount()));
		args->set(0, names->get(GET_COLLECT_ARGS));
		$System::arraycopy(names, ARG_BASE, args, 1, ARG_LIMIT - ARG_BASE);
		$init($MethodHandleImpl$Intrinsic);
		names->set(BOXED_ARGS, $$new($LambdaForm$Name, $$new($LambdaForm$NamedFunction, $(makeIntrinsic(invokeBasic, $MethodHandleImpl$Intrinsic::LOOP))), args));
		$var($ObjectArray, lArgs, $new($ObjectArray, {
			($Object*)nullptr,
			$of(names->get(GET_CLAUSE_DATA)),
			$of(names->get(BOXED_ARGS))
		}));
		names->set(LOOP, $$new($LambdaForm$Name, $(getFunction(MethodHandleImpl::NF_loop)), lArgs));
		$var($MethodHandle, invokeBasicUnbox, $MethodHandles::basicInvoker($($MethodType::methodType(basicType->rtype(), $Object::class$))));
		$var($ObjectArray, unboxArgs, $new($ObjectArray, {
			$of(names->get(GET_UNBOX_RESULT)),
			$of(names->get(LOOP))
		}));
		names->set(UNBOX_RESULT, $$new($LambdaForm$Name, invokeBasicUnbox, unboxArgs));
		$init($LambdaForm$Kind);
		$assign(lform, $nc($(basicType->form()))->setCachedLambdaForm($MethodTypeForm::LF_LOOP, $$new($LambdaForm, $nc(lambdaType)->parameterCount(), names, $LambdaForm$Kind::LOOP)));
	}
	return $nc($($nc(lform)->editor()))->noteLoopLocalTypesForm(BOXED_ARGS, localVarTypes);
}

$Object* MethodHandleImpl::loop($LambdaForm$BasicTypeArray* localTypes, $MethodHandleImpl$LoopClauses* clauseData, $ObjectArray* av) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandleArray, init, $nc($nc(clauseData)->clauses)->get(0));
	$var($MethodHandleArray, step, $nc(clauseData->clauses)->get(1));
	$var($MethodHandleArray, pred, $nc(clauseData->clauses)->get(2));
	$var($MethodHandleArray, fini, $nc(clauseData->clauses)->get(3));
	int32_t varSize = (int32_t)$nc($($nc($($Stream::of(init)))->filter(static_cast<$Predicate*>($$new(MethodHandleImpl$$Lambda$lambda$loop$2$3)))))->count();
	int32_t nArgs = $nc($($nc($nc(init)->get(0))->type()))->parameterCount();
	$var($ObjectArray, varsAndArgs, $new($ObjectArray, varSize + nArgs));
	{
		int32_t i = 0;
		int32_t v = 0;
		for (; i < init->length; ++i) {
			$var($MethodHandle, ih, init->get(i));
			$init($Void);
			if ($cast($Class, $nc($($nc(ih)->type()))->returnType()) == $Void::TYPE) {
				ih->invokeWithArguments(av);
			} else {
				varsAndArgs->set(v++, $(ih->invokeWithArguments(av)));
			}
		}
	}
	$System::arraycopy(av, 0, varsAndArgs, varSize, nArgs);
	int32_t nSteps = $nc(step)->length;
	for (;;) {
		{
			int32_t i = 0;
			int32_t v = 0;
			for (; i < nSteps; ++i) {
				$var($MethodHandle, p, $nc(pred)->get(i));
				$var($MethodHandle, s, step->get(i));
				$var($MethodHandle, f, $nc(fini)->get(i));
				$init($Void);
				if ($cast($Class, $nc($($nc(s)->type()))->returnType()) == $Void::TYPE) {
					s->invokeWithArguments(varsAndArgs);
				} else {
					varsAndArgs->set(v++, $(s->invokeWithArguments(varsAndArgs)));
				}
				if (!$nc(($cast($Boolean, $($nc(p)->invokeWithArguments(varsAndArgs)))))->booleanValue()) {
					return $of($nc(f)->invokeWithArguments(varsAndArgs));
				}
			}
		}
	}
}

bool MethodHandleImpl::countedLoopPredicate(int32_t limit, int32_t counter) {
	$init(MethodHandleImpl);
	return counter < limit;
}

int32_t MethodHandleImpl::countedLoopStep(int32_t limit, int32_t counter) {
	$init(MethodHandleImpl);
	return counter + 1;
}

$Iterator* MethodHandleImpl::initIterator($Iterable* it) {
	$init(MethodHandleImpl);
	return $nc(it)->iterator();
}

bool MethodHandleImpl::iteratePredicate($Iterator* it) {
	$init(MethodHandleImpl);
	return $nc(it)->hasNext();
}

$Object* MethodHandleImpl::iterateNext($Iterator* it) {
	$init(MethodHandleImpl);
	return $of($nc(it)->next());
}

$MethodHandle* MethodHandleImpl::makeTryFinally($MethodHandle* target, $MethodHandle* cleanup, $Class* rtype, $List* argTypes) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $MethodType::methodType(rtype, argTypes));
	$var($LambdaForm, form, makeTryFinallyForm($($nc(type)->basicType())));
	$load($ObjectArray);
	$var($MethodType, varargsType, $nc(type)->changeReturnType($getClass($ObjectArray)));
	$var($MethodHandle, collectArgs, $nc($(varargsArray(type->parameterCount())))->asType(varargsType));
	$var($MethodHandle, unboxResult, unboxResultHandle(rtype));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLLL());
	$var($BoundMethodHandle, mh, nullptr);
	try {
		$assign(mh, $cast($BoundMethodHandle, $nc($($nc(data)->factory()))->invokeBasic($$new($ObjectArray, {$of(type), $of(form), $of(target), $of(cleanup), $of(collectArgs), $of(unboxResult)}))));
	} catch ($Throwable& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(mh)->type() == type)) {
		$throwNew($AssertionError);
	}
	return mh;
}

$LambdaForm* MethodHandleImpl::makeTryFinallyForm($MethodType* basicType) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, lambdaType, $nc(basicType)->invokerType());
	$var($LambdaForm, lform, $nc($(basicType->form()))->cachedLambdaForm($MethodTypeForm::LF_TF));
	if (lform != nullptr) {
		return lform;
	}
	int32_t THIS_MH = 0;
	int32_t ARG_BASE = 1;
	int32_t ARG_LIMIT = ARG_BASE + basicType->parameterCount();
	int32_t nameCursor = ARG_LIMIT;
	int32_t GET_TARGET = nameCursor++;
	int32_t GET_CLEANUP = nameCursor++;
	int32_t GET_COLLECT_ARGS = nameCursor++;
	int32_t GET_UNBOX_RESULT = nameCursor++;
	int32_t BOXED_ARGS = nameCursor++;
	int32_t TRY_FINALLY = nameCursor++;
	int32_t UNBOX_RESULT = nameCursor++;
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - ARG_LIMIT, lambdaType));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLLL());
	$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(data)));
	names->set(GET_TARGET, $$new($LambdaForm$Name, $($nc(data)->getterFunction(0)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_CLEANUP, $$new($LambdaForm$Name, $($nc(data)->getterFunction(1)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_COLLECT_ARGS, $$new($LambdaForm$Name, $($nc(data)->getterFunction(2)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_UNBOX_RESULT, $$new($LambdaForm$Name, $($nc(data)->getterFunction(3)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	$var($MethodType, collectArgsType, basicType->changeReturnType($Object::class$));
	$var($MethodHandle, invokeBasic, $MethodHandles::basicInvoker(collectArgsType));
	$var($ObjectArray, args, $new($ObjectArray, $nc($($nc(invokeBasic)->type()))->parameterCount()));
	args->set(0, names->get(GET_COLLECT_ARGS));
	$System::arraycopy(names, ARG_BASE, args, 1, ARG_LIMIT - ARG_BASE);
	$init($MethodHandleImpl$Intrinsic);
	names->set(BOXED_ARGS, $$new($LambdaForm$Name, $$new($LambdaForm$NamedFunction, $(makeIntrinsic(invokeBasic, $MethodHandleImpl$Intrinsic::TRY_FINALLY))), args));
	$var($ObjectArray, tfArgs, $new($ObjectArray, {
		$of(names->get(GET_TARGET)),
		$of(names->get(GET_CLEANUP)),
		$of(names->get(BOXED_ARGS))
	}));
	names->set(TRY_FINALLY, $$new($LambdaForm$Name, $(getFunction(MethodHandleImpl::NF_tryFinally)), tfArgs));
	$var($MethodHandle, invokeBasicUnbox, $MethodHandles::basicInvoker($($MethodType::methodType(basicType->rtype(), $Object::class$))));
	$var($ObjectArray, unboxArgs, $new($ObjectArray, {
		$of(names->get(GET_UNBOX_RESULT)),
		$of(names->get(TRY_FINALLY))
	}));
	names->set(UNBOX_RESULT, $$new($LambdaForm$Name, invokeBasicUnbox, unboxArgs));
	$init($LambdaForm$Kind);
	$assign(lform, $new($LambdaForm, $nc(lambdaType)->parameterCount(), names, $LambdaForm$Kind::TRY_FINALLY));
	return $nc($(basicType->form()))->setCachedLambdaForm($MethodTypeForm::LF_TF, lform);
}

$Object* MethodHandleImpl::tryFinally($MethodHandle* target, $MethodHandle* cleanup, $ObjectArray* av) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, nullptr);
	$var($Object, r, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$assign(r, $nc(target)->invokeWithArguments(av));
			} catch ($Throwable& thrown) {
				$assign(t, thrown);
				$throw(t);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$init($Void);
			$var($ObjectArray, args, $cast($Class, $nc($($nc(target)->type()))->returnType()) == $Void::TYPE ? prepend(av, $$new($ObjectArray, {$of(t)})) : prepend(av, $$new($ObjectArray, {
				$of(t),
				r
			})));
			$assign(r, $nc(cleanup)->invokeWithArguments(args));
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return $of(r);
}

$MethodHandle* MethodHandleImpl::makeCollector($Class* arrayType, int32_t parameterCount) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $MethodType::methodType(arrayType, $($Collections::nCopies(parameterCount, $($nc(arrayType)->componentType())))));
	$var($MethodHandle, newArray, $MethodHandles::arrayConstructor(arrayType));
	$var($LambdaForm, form, makeCollectorForm($($nc(type)->basicType()), arrayType));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_L());
	$var($BoundMethodHandle, mh, nullptr);
	try {
		$assign(mh, $cast($BoundMethodHandle, $nc($($nc(data)->factory()))->invokeBasic($$new($ObjectArray, {$of(type), $of(form), $of(newArray)}))));
	} catch ($Throwable& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(mh)->type() == type)) {
		$throwNew($AssertionError);
	}
	return mh;
}

$LambdaForm* MethodHandleImpl::makeCollectorForm($MethodType* basicType, $Class* arrayType) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, lambdaType, $nc(basicType)->invokerType());
	int32_t parameterCount = basicType->parameterCount();
	bool isReferenceType = !$nc($($cast($Class, $nc(arrayType)->componentType())))->isPrimitive();
	bool isSharedLambdaForm = parameterCount == 0 || isReferenceType;
	if (isSharedLambdaForm) {
		$var($LambdaForm, lform, $nc($(basicType->form()))->cachedLambdaForm($MethodTypeForm::LF_COLLECTOR));
		if (lform != nullptr) {
			return lform;
		}
	}
	$init($MethodHandleImpl$ArrayAccessor);
	$init($MethodHandleImpl$ArrayAccess);
	$var($MethodHandle, storeFunc, isReferenceType ? $MethodHandleImpl$ArrayAccessor::OBJECT_ARRAY_SETTER : makeArrayElementAccessor(arrayType, $MethodHandleImpl$ArrayAccess::SET));
	int32_t THIS_MH = 0;
	int32_t ARG_BASE = 1;
	int32_t ARG_LIMIT = ARG_BASE + parameterCount;
	int32_t nameCursor = ARG_LIMIT;
	int32_t GET_NEW_ARRAY = nameCursor++;
	int32_t CALL_NEW_ARRAY = nameCursor++;
	int32_t STORE_ELEMENT_BASE = nameCursor;
	int32_t STORE_ELEMENT_LIMIT = STORE_ELEMENT_BASE + parameterCount;
	nameCursor = STORE_ELEMENT_LIMIT;
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - ARG_LIMIT, lambdaType));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_L());
	$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(data)));
	names->set(GET_NEW_ARRAY, $$new($LambdaForm$Name, $($nc(data)->getterFunction(0)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	$init($Integer);
	$var($MethodHandle, invokeBasic, $MethodHandles::basicInvoker($($MethodType::methodType($Object::class$, $Integer::TYPE))));
	$var($LambdaForm$NamedFunction, var$0, $new($LambdaForm$NamedFunction, invokeBasic));
	names->set(CALL_NEW_ARRAY, $$new($LambdaForm$Name, var$0, $$new($ObjectArray, {
		$of(names->get(GET_NEW_ARRAY)),
		$($of($Integer::valueOf(parameterCount)))
	})));
	{
		int32_t storeIndex = 0;
		int32_t storeNameCursor = STORE_ELEMENT_BASE;
		int32_t argCursor = ARG_BASE;
		for (; storeNameCursor < STORE_ELEMENT_LIMIT; ++storeIndex, ++storeNameCursor, ++argCursor) {
			$init($MethodHandleImpl$Intrinsic);
			$var($LambdaForm$NamedFunction, var$1, $new($LambdaForm$NamedFunction, $(makeIntrinsic(storeFunc, $MethodHandleImpl$Intrinsic::ARRAY_STORE))));
			names->set(storeNameCursor, $$new($LambdaForm$Name, var$1, $$new($ObjectArray, {
				$of(names->get(CALL_NEW_ARRAY)),
				$($of($Integer::valueOf(storeIndex))),
				$of(names->get(argCursor))
			})));
		}
	}
	$init($LambdaForm$Kind);
	$var($LambdaForm, lform, $new($LambdaForm, $nc(lambdaType)->parameterCount(), names, CALL_NEW_ARRAY, $LambdaForm$Kind::COLLECTOR));
	if (isSharedLambdaForm) {
		$assign(lform, $nc($(basicType->form()))->setCachedLambdaForm($MethodTypeForm::LF_COLLECTOR, lform));
	}
	return lform;
}

$MethodHandle* MethodHandleImpl::makeTableSwitch($MethodType* type, $MethodHandle* defaultCase, $MethodHandleArray* caseActions) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$load($ObjectArray);
	$var($MethodType, varargsType, $nc(type)->changeReturnType($getClass($ObjectArray)));
	$var($MethodHandle, collectArgs, $nc($(varargsArray(type->parameterCount())))->asType(varargsType));
	$var($MethodHandle, unboxResult, unboxResultHandle($($cast($Class, type->returnType()))));
	$var($BoundMethodHandle$SpeciesData, data, $BoundMethodHandle::speciesData_LLLL());
	$var($LambdaForm, form, makeTableSwitchForm($(type->basicType()), data, $nc(caseActions)->length));
	$var($BoundMethodHandle, mh, nullptr);
	$var($MethodHandleImpl$CasesHolder, caseHolder, $new($MethodHandleImpl$CasesHolder, caseActions));
	try {
		$assign(mh, $cast($BoundMethodHandle, $nc($($nc(data)->factory()))->invokeBasic($$new($ObjectArray, {$of(type), $of(form), $of(defaultCase), $of(collectArgs), $of(unboxResult), $of(caseHolder)}))));
	} catch ($Throwable& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	if (!MethodHandleImpl::$assertionsDisabled && !($nc(mh)->type() == type)) {
		$throwNew($AssertionError);
	}
	return mh;
}

$LambdaForm* MethodHandleImpl::makeTableSwitchForm($MethodType* basicType, $BoundMethodHandle$SpeciesData* data, int32_t numCases) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, lambdaType, $nc(basicType)->invokerType());
	$var($MethodHandleImpl$TableSwitchCacheKey, key, $new($MethodHandleImpl$TableSwitchCacheKey, basicType, numCases));
	$init($MethodHandleImpl$TableSwitchCacheKey);
	$var($LambdaForm, lform, $cast($LambdaForm, $nc($MethodHandleImpl$TableSwitchCacheKey::CACHE)->get(key)));
	if (lform != nullptr) {
		return lform;
	}
	int32_t THIS_MH = 0;
	int32_t ARG_BASE = 1;
	int32_t ARG_LIMIT = ARG_BASE + basicType->parameterCount();
	int32_t ARG_SWITCH_ON = ARG_BASE;
	if (!MethodHandleImpl::$assertionsDisabled && !(ARG_SWITCH_ON < ARG_LIMIT)) {
		$throwNew($AssertionError);
	}
	int32_t nameCursor = ARG_LIMIT;
	int32_t GET_COLLECT_ARGS = nameCursor++;
	int32_t GET_DEFAULT_CASE = nameCursor++;
	int32_t GET_UNBOX_RESULT = nameCursor++;
	int32_t GET_CASES = nameCursor++;
	int32_t BOXED_ARGS = nameCursor++;
	int32_t TABLE_SWITCH = nameCursor++;
	int32_t UNBOXED_RESULT = nameCursor++;
	int32_t fieldCursor = 0;
	int32_t FIELD_DEFAULT_CASE = fieldCursor++;
	int32_t FIELD_COLLECT_ARGS = fieldCursor++;
	int32_t FIELD_UNBOX_RESULT = fieldCursor++;
	int32_t FIELD_CASES = fieldCursor++;
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - ARG_LIMIT, lambdaType));
	$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(data)));
	names->set(GET_DEFAULT_CASE, $$new($LambdaForm$Name, $($nc(data)->getterFunction(FIELD_DEFAULT_CASE)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_COLLECT_ARGS, $$new($LambdaForm$Name, $($nc(data)->getterFunction(FIELD_COLLECT_ARGS)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_UNBOX_RESULT, $$new($LambdaForm$Name, $($nc(data)->getterFunction(FIELD_UNBOX_RESULT)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(GET_CASES, $$new($LambdaForm$Name, $($nc(data)->getterFunction(FIELD_CASES)), $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	{
		$var($MethodType, collectArgsType, basicType->changeReturnType($Object::class$));
		$var($MethodHandle, invokeBasic, $MethodHandles::basicInvoker(collectArgsType));
		$var($ObjectArray, args, $new($ObjectArray, $nc($($nc(invokeBasic)->type()))->parameterCount()));
		args->set(0, names->get(GET_COLLECT_ARGS));
		$System::arraycopy(names, ARG_BASE, args, 1, ARG_LIMIT - ARG_BASE);
		$init($MethodHandleImpl$Intrinsic);
		names->set(BOXED_ARGS, $$new($LambdaForm$Name, $$new($LambdaForm$NamedFunction, $(makeIntrinsic(invokeBasic, $MethodHandleImpl$Intrinsic::TABLE_SWITCH, $($of($Integer::valueOf(numCases)))))), args));
	}
	{
		$var($ObjectArray, tfArgs, $new($ObjectArray, {
			$of(names->get(ARG_SWITCH_ON)),
			$of(names->get(GET_DEFAULT_CASE)),
			$of(names->get(GET_CASES)),
			$of(names->get(BOXED_ARGS))
		}));
		names->set(TABLE_SWITCH, $$new($LambdaForm$Name, $(getFunction(MethodHandleImpl::NF_tableSwitch)), tfArgs));
	}
	{
		$var($MethodHandle, invokeBasic, $MethodHandles::basicInvoker($($MethodType::methodType(basicType->rtype(), $Object::class$))));
		$var($ObjectArray, unboxArgs, $new($ObjectArray, {
			$of(names->get(GET_UNBOX_RESULT)),
			$of(names->get(TABLE_SWITCH))
		}));
		names->set(UNBOXED_RESULT, $$new($LambdaForm$Name, invokeBasic, unboxArgs));
	}
	$init($LambdaForm$Kind);
	$assign(lform, $new($LambdaForm, $nc(lambdaType)->parameterCount(), names, $LambdaForm$Kind::TABLE_SWITCH));
	$var($LambdaForm, prev, $cast($LambdaForm, $nc($MethodHandleImpl$TableSwitchCacheKey::CACHE)->putIfAbsent(key, lform)));
	return prev != nullptr ? prev : lform;
}

$Object* MethodHandleImpl::tableSwitch(int32_t input, $MethodHandle* defaultCase, $MethodHandleImpl$CasesHolder* holder, $ObjectArray* args) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandleArray, caseActions, $nc(holder)->cases);
	$var($MethodHandle, selectedCase, nullptr);
	if (input < 0 || input >= $nc(caseActions)->length) {
		$assign(selectedCase, defaultCase);
	} else {
		$assign(selectedCase, caseActions->get(input));
	}
	return $of($nc(selectedCase)->invokeWithArguments(args));
}

$MethodHandle* MethodHandleImpl::getConstantHandle(int32_t idx) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, handle, $nc(MethodHandleImpl::HANDLES)->get(idx));
	if (handle != nullptr) {
		return handle;
	}
	return setCachedHandle(idx, $(makeConstantHandle(idx)));
}

$MethodHandle* MethodHandleImpl::setCachedHandle(int32_t idx, $MethodHandle* method) {
	$load(MethodHandleImpl);
	$synchronized(class$) {
		$init(MethodHandleImpl);
		$var($MethodHandle, prev, $nc(MethodHandleImpl::HANDLES)->get(idx));
		if (prev != nullptr) {
			return prev;
		}
		$nc(MethodHandleImpl::HANDLES)->set(idx, method);
		return method;
	}
}

$MethodHandle* MethodHandleImpl::makeConstantHandle(int32_t idx) {
	$init(MethodHandleImpl);
	$useLocalCurrentObjectStackCache();
	try {
		switch (idx) {
		case MethodHandleImpl::MH_cast:
			{
				$init($MethodHandles$Lookup);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findVirtual($Class::class$, "cast"_s, $($MethodType::methodType($Object::class$, $Object::class$)));
			}
		case MethodHandleImpl::MH_selectAlternative:
			{
				$init($MethodHandles$Lookup);
				$load($MethodHandle);
				$init($Boolean);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl::class$, "selectAlternative"_s, $($MethodType::methodType($MethodHandle::class$, $Boolean::TYPE, $$new($ClassArray, {
					$MethodHandle::class$,
					$MethodHandle::class$
				}))));
			}
		case MethodHandleImpl::MH_countedLoopPred:
			{
				$init($MethodHandles$Lookup);
				$init($Boolean);
				$init($Integer);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl::class$, "countedLoopPredicate"_s, $($MethodType::methodType($Boolean::TYPE, $Integer::TYPE, $$new($ClassArray, {$Integer::TYPE}))));
			}
		case MethodHandleImpl::MH_countedLoopStep:
			{
				$init($MethodHandles$Lookup);
				$init($Integer);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl::class$, "countedLoopStep"_s, $($MethodType::methodType($Integer::TYPE, $Integer::TYPE, $$new($ClassArray, {$Integer::TYPE}))));
			}
		case MethodHandleImpl::MH_initIterator:
			{
				$init($MethodHandles$Lookup);
				$load($Iterator);
				$load($Iterable);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl::class$, "initIterator"_s, $($MethodType::methodType($Iterator::class$, $Iterable::class$)));
			}
		case MethodHandleImpl::MH_iteratePred:
			{
				$init($MethodHandles$Lookup);
				$init($Boolean);
				$load($Iterator);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl::class$, "iteratePredicate"_s, $($MethodType::methodType($Boolean::TYPE, $Iterator::class$)));
			}
		case MethodHandleImpl::MH_iterateNext:
			{
				$init($MethodHandles$Lookup);
				$load($Iterator);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(MethodHandleImpl::class$, "iterateNext"_s, $($MethodType::methodType($Object::class$, $Iterator::class$)));
			}
		case MethodHandleImpl::MH_Array_newInstance:
			{
				$init($MethodHandles$Lookup);
				$load($1Array);
				$init($Integer);
				return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic($1Array::class$, "newInstance"_s, $($MethodType::methodType($Object::class$, $Class::class$, $$new($ClassArray, {$Integer::TYPE}))));
			}
		}
	} catch ($ReflectiveOperationException& ex) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(ex))));
	}
	$throw($($MethodHandleStatics::newInternalError($$str({"Unknown function index: "_s, $$str(idx)}))));
	$shouldNotReachHere();
}

bool MethodHandleImpl::lambda$loop$2($MethodHandle* h) {
	$init(MethodHandleImpl);
	$init($Void);
	return $cast($Class, $nc($($nc(h)->type()))->returnType()) != $Void::TYPE;
}

$LambdaForm$BasicTypeArray* MethodHandleImpl::lambda$makeLoop$1(int32_t x$0) {
	$init(MethodHandleImpl);
	return $new($LambdaForm$BasicTypeArray, x$0);
}

$Class* MethodHandleImpl::lambda$makeLoop$0($MethodHandle* h) {
	$init(MethodHandleImpl);
	return $cast($Class, $nc($($nc(h)->type()))->returnType());
}

void clinit$MethodHandleImpl($Class* class$) {
	MethodHandleImpl::$assertionsDisabled = !MethodHandleImpl::class$->desiredAssertionStatus();
	$assignStatic(MethodHandleImpl::FAKE_METHOD_HANDLE_INVOKE, $new($MethodHandleArray, 2));
	$init($MethodHandleStatics);
	$assignStatic(MethodHandleImpl::ARRAYS, $new($MethodHandleArray, $MethodHandleStatics::MAX_ARITY + 1));
	$assignStatic(MethodHandleImpl::NFS, $new($LambdaForm$NamedFunctionArray, MethodHandleImpl::NF_LIMIT));
	{
		$SharedSecrets::setJavaLangInvokeAccess($$new($MethodHandleImpl$1));
	}
	$assignStatic(MethodHandleImpl::HANDLES, $new($MethodHandleArray, MethodHandleImpl::MH_LIMIT));
}

MethodHandleImpl::MethodHandleImpl() {
}

$Class* MethodHandleImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MethodHandleImpl$$Lambda$lambda$makeLoop$0::classInfo$.name)) {
			return MethodHandleImpl$$Lambda$lambda$makeLoop$0::load$(name, initialize);
		}
		if (name->equals(MethodHandleImpl$$Lambda$basicType$1::classInfo$.name)) {
			return MethodHandleImpl$$Lambda$basicType$1::load$(name, initialize);
		}
		if (name->equals(MethodHandleImpl$$Lambda$lambda$makeLoop$1$2::classInfo$.name)) {
			return MethodHandleImpl$$Lambda$lambda$makeLoop$1$2::load$(name, initialize);
		}
		if (name->equals(MethodHandleImpl$$Lambda$lambda$loop$2$3::classInfo$.name)) {
			return MethodHandleImpl$$Lambda$lambda$loop$2$3::load$(name, initialize);
		}
	}
	$loadClass(MethodHandleImpl, name, initialize, &_MethodHandleImpl_ClassInfo_, clinit$MethodHandleImpl, allocate$MethodHandleImpl);
	return class$;
}

$Class* MethodHandleImpl::class$ = nullptr;

		} // invoke
	} // lang
} // java