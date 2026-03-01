#include <java/lang/invoke/Invokers.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/constant/Constable.h>
#include <java/lang/invoke/BoundMethodHandle$SpeciesData.h>
#include <java/lang/invoke/BoundMethodHandle.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/DirectMethodHandle.h>
#include <java/lang/invoke/InvokerBytecodeGenerator.h>
#include <java/lang/invoke/Invokers$Holder.h>
#include <java/lang/invoke/Invokers$Lazy.h>
#include <java/lang/invoke/LambdaForm$BasicType.h>
#include <java/lang/invoke/LambdaForm$Kind.h>
#include <java/lang/invoke/LambdaForm$Name.h>
#include <java/lang/invoke/LambdaForm$NamedFunction.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/MemberName$Factory.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/MethodTypeForm.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/VarHandle$AccessDescriptor.h>
#include <java/lang/invoke/VarHandle$AccessMode.h>
#include <java/lang/invoke/VarHandle$AccessType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/invoke/WrongMethodTypeException.h>
#include <java/lang/reflect/Array.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jcpp.h>

#undef APPENDIX_ARG
#undef ARG_BASE
#undef ARG_LIMIT
#undef CALL_MH
#undef CALL_VH
#undef CHECK_CUSTOM
#undef CHECK_TYPE
#undef COUNT
#undef CSITE_ARG
#undef CUSTOMIZE_THRESHOLD
#undef EAGER_COMPILE_ARITY_LIMIT
#undef EXACT_INVOKER
#undef EXACT_LINKER
#undef GENERIC_INVOKER
#undef GENERIC_LINKER
#undef IMPL_LOOKUP
#undef INARG_LIMIT
#undef INV_BASIC
#undef INV_EXACT
#undef INV_GENERIC
#undef INV_LIMIT
#undef LF_CS_LINKER
#undef LF_EX_INVOKER
#undef LF_EX_LINKER
#undef LF_GEN_INVOKER
#undef LF_GEN_LINKER
#undef LF_MH_LINKER
#undef LF_VH_EX_INVOKER
#undef LF_VH_GEN_INVOKER
#undef LF_VH_GEN_LINKER
#undef LINKER_CALL
#undef LINK_TO_CALL_SITE
#undef LINK_TO_TARGET_METHOD
#undef MAX_MH_ARITY
#undef MAX_MH_INVOKER_ARITY
#undef MH_BASIC_INV
#undef MH_LINKER_ARG_APPENDED
#undef MTYPE_ARG
#undef NFS
#undef NF_LIMIT
#undef OUTARG_LIMIT
#undef PREPEND_COUNT
#undef PREPEND_MH
#undef THIS_MH
#undef THIS_VH
#undef TYPE
#undef UNBOUND_VH
#undef UNSAFE
#undef VAD_ARG
#undef VARHANDLE_EXACT_INVOKER
#undef VARHANDLE_INVOKER
#undef VARHANDLE_LINKER
#undef VH_INV_EXACT
#undef VH_INV_GENERIC

using $SerializableArray = $Array<::java::io::Serializable>;
using $ConstableArray = $Array<::java::lang::constant::Constable>;
using $LambdaForm$NameArray = $Array<::java::lang::invoke::LambdaForm$Name>;
using $LambdaForm$NamedFunctionArray = $Array<::java::lang::invoke::LambdaForm$NamedFunction>;
using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Void = ::java::lang::Void;
using $Constable = ::java::lang::constant::Constable;
using $BoundMethodHandle = ::java::lang::invoke::BoundMethodHandle;
using $BoundMethodHandle$SpeciesData = ::java::lang::invoke::BoundMethodHandle$SpeciesData;
using $CallSite = ::java::lang::invoke::CallSite;
using $DirectMethodHandle = ::java::lang::invoke::DirectMethodHandle;
using $InvokerBytecodeGenerator = ::java::lang::invoke::InvokerBytecodeGenerator;
using $Invokers$Holder = ::java::lang::invoke::Invokers$Holder;
using $Invokers$Lazy = ::java::lang::invoke::Invokers$Lazy;
using $LambdaForm = ::java::lang::invoke::LambdaForm;
using $LambdaForm$BasicType = ::java::lang::invoke::LambdaForm$BasicType;
using $LambdaForm$Kind = ::java::lang::invoke::LambdaForm$Kind;
using $LambdaForm$Name = ::java::lang::invoke::LambdaForm$Name;
using $LambdaForm$NamedFunction = ::java::lang::invoke::LambdaForm$NamedFunction;
using $MemberName = ::java::lang::invoke::MemberName;
using $MemberName$Factory = ::java::lang::invoke::MemberName$Factory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl = ::java::lang::invoke::MethodHandleImpl;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MethodTypeForm = ::java::lang::invoke::MethodTypeForm;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $VarHandle$AccessDescriptor = ::java::lang::invoke::VarHandle$AccessDescriptor;
using $VarHandle$AccessMode = ::java::lang::invoke::VarHandle$AccessMode;
using $VarHandle$AccessType = ::java::lang::invoke::VarHandle$AccessType;
using $WrongMethodTypeException = ::java::lang::invoke::WrongMethodTypeException;
using $1Array = ::java::lang::reflect::Array;
using $Arrays = ::java::util::Arrays;
using $Unsafe = ::jdk::internal::misc::Unsafe;

namespace java {
	namespace lang {
		namespace invoke {

$CompoundAttribute _Invokers_FieldAnnotations_invokers[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _Invokers_FieldAnnotations_NFS[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_checkCustomized5[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_checkExactType6[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_checkGenericType7[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_checkVarHandleExactType9[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_checkVarHandleGenericType10[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{"Ljdk/internal/vm/annotation/Hidden;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_directVarHandleTarget13[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_getCallSiteTarget16[] = {
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$CompoundAttribute _Invokers_MethodAnnotations_maybeCustomize27[] = {
	{"Ljdk/internal/vm/annotation/DontInline;", nullptr},
	{}
};

$FieldInfo _Invokers_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Invokers, $assertionsDisabled)},
	{"targetType", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $FINAL, $field(Invokers, targetType)},
	{"invokers", "[Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $FINAL, $field(Invokers, invokers), _Invokers_FieldAnnotations_invokers},
	{"INV_EXACT", "I", nullptr, $STATIC | $FINAL, $constField(Invokers, INV_EXACT)},
	{"INV_GENERIC", "I", nullptr, $STATIC | $FINAL, $constField(Invokers, INV_GENERIC)},
	{"INV_BASIC", "I", nullptr, $STATIC | $FINAL, $constField(Invokers, INV_BASIC)},
	{"VH_INV_EXACT", "I", nullptr, $STATIC | $FINAL, $constField(Invokers, VH_INV_EXACT)},
	{"VH_INV_GENERIC", "I", nullptr, $STATIC | $FINAL, $staticField(Invokers, VH_INV_GENERIC)},
	{"INV_LIMIT", "I", nullptr, $STATIC | $FINAL, $staticField(Invokers, INV_LIMIT)},
	{"MH_LINKER_ARG_APPENDED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, MH_LINKER_ARG_APPENDED)},
	{"NF_checkExactType", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_checkExactType)},
	{"NF_checkGenericType", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_checkGenericType)},
	{"NF_getCallSiteTarget", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_getCallSiteTarget)},
	{"NF_checkCustomized", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_checkCustomized)},
	{"NF_checkVarHandleGenericType", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_checkVarHandleGenericType)},
	{"NF_checkVarHandleExactType", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_checkVarHandleExactType)},
	{"NF_directVarHandleTarget", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_directVarHandleTarget)},
	{"NF_LIMIT", "B", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Invokers, NF_LIMIT)},
	{"NFS", "[Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Invokers, NFS), _Invokers_FieldAnnotations_NFS},
	{}
};

$MethodInfo _Invokers_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/MethodType;)V", nullptr, 0, $method(Invokers, init$, void, $MethodType*)},
	{"basicInvoker", "()Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(Invokers, basicInvoker, $MethodHandle*)},
	{"cachedInvoker", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(Invokers, cachedInvoker, $MethodHandle*, int32_t)},
	{"cachedVHInvoker", "(ZLjava/lang/invoke/VarHandle$AccessMode;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(Invokers, cachedVHInvoker, $MethodHandle*, bool, $VarHandle$AccessMode*)},
	{"callSiteForm", "(Ljava/lang/invoke/MethodType;Z)Ljava/lang/invoke/LambdaForm;", nullptr, $STATIC, $staticMethod(Invokers, callSiteForm, $LambdaForm*, $MethodType*, bool)},
	{"checkCustomized", "(Ljava/lang/invoke/MethodHandle;)V", nullptr, $STATIC, $staticMethod(Invokers, checkCustomized, void, $MethodHandle*), nullptr, nullptr, _Invokers_MethodAnnotations_checkCustomized5},
	{"checkExactType", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;)V", nullptr, $STATIC, $staticMethod(Invokers, checkExactType, void, $MethodHandle*, $MethodType*), nullptr, nullptr, _Invokers_MethodAnnotations_checkExactType6},
	{"checkGenericType", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(Invokers, checkGenericType, $MethodHandle*, $MethodHandle*, $MethodType*), nullptr, nullptr, _Invokers_MethodAnnotations_checkGenericType7},
	{"checkInvoker", "(Ljava/lang/invoke/MethodHandle;)Z", nullptr, $PRIVATE, $method(Invokers, checkInvoker, bool, $MethodHandle*)},
	{"checkVarHandleExactType", "(Ljava/lang/invoke/VarHandle;Ljava/lang/invoke/VarHandle$AccessDescriptor;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(Invokers, checkVarHandleExactType, $MethodHandle*, $VarHandle*, $VarHandle$AccessDescriptor*), nullptr, nullptr, _Invokers_MethodAnnotations_checkVarHandleExactType9},
	{"checkVarHandleGenericType", "(Ljava/lang/invoke/VarHandle;Ljava/lang/invoke/VarHandle$AccessDescriptor;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(Invokers, checkVarHandleGenericType, $MethodHandle*, $VarHandle*, $VarHandle$AccessDescriptor*), nullptr, nullptr, _Invokers_MethodAnnotations_checkVarHandleGenericType10},
	{"checkVarHandleInvoker", "(Ljava/lang/invoke/MethodHandle;)Z", nullptr, $PRIVATE, $method(Invokers, checkVarHandleInvoker, bool, $MethodHandle*)},
	{"createFunction", "(B)Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PRIVATE | $STATIC, $staticMethod(Invokers, createFunction, $LambdaForm$NamedFunction*, int8_t)},
	{"directVarHandleTarget", "(Ljava/lang/invoke/VarHandle;)Ljava/lang/invoke/VarHandle;", nullptr, $STATIC, $staticMethod(Invokers, directVarHandleTarget, $VarHandle*, $VarHandle*), nullptr, nullptr, _Invokers_MethodAnnotations_directVarHandleTarget13},
	{"exactInvoker", "()Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(Invokers, exactInvoker, $MethodHandle*)},
	{"genericInvoker", "()Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(Invokers, genericInvoker, $MethodHandle*)},
	{"getCallSiteTarget", "(Ljava/lang/invoke/CallSite;)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(Invokers, getCallSiteTarget, $MethodHandle*, $CallSite*), nullptr, nullptr, _Invokers_MethodAnnotations_getCallSiteTarget16},
	{"getFunction", "(B)Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PRIVATE | $STATIC, $staticMethod(Invokers, getFunction, $LambdaForm$NamedFunction*, int8_t)},
	{"getNamedFunction", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/LambdaForm$NamedFunction;", nullptr, $PRIVATE | $STATIC, $staticMethod(Invokers, getNamedFunction, $LambdaForm$NamedFunction*, $String*, $MethodType*), "java.lang.ReflectiveOperationException"},
	{"impliedRestargType", "(Ljava/lang/invoke/MethodType;I)Ljava/lang/Class;", "(Ljava/lang/invoke/MethodType;I)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(Invokers, impliedRestargType, $Class*, $MethodType*, int32_t)},
	{"invokeBasicMethod", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(Invokers, invokeBasicMethod, $MemberName*, $MethodType*)},
	{"invokeHandleForm", "(Ljava/lang/invoke/MethodType;ZI)Ljava/lang/invoke/LambdaForm;", nullptr, $STATIC, $staticMethod(Invokers, invokeHandleForm, $LambdaForm*, $MethodType*, bool, int32_t)},
	{"linkToCallSiteMethod", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(Invokers, linkToCallSiteMethod, $MemberName*, $MethodType*)},
	{"linkToTargetMethod", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(Invokers, linkToTargetMethod, $MemberName*, $MethodType*)},
	{"makeExactOrGeneralInvoker", "(Z)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(Invokers, makeExactOrGeneralInvoker, $MethodHandle*, bool)},
	{"makeVarHandleMethodInvoker", "(Ljava/lang/invoke/VarHandle$AccessMode;Z)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(Invokers, makeVarHandleMethodInvoker, $MethodHandle*, $VarHandle$AccessMode*, bool)},
	{"maybeCompileToBytecode", "(Ljava/lang/invoke/MethodHandle;)V", nullptr, $PRIVATE, $method(Invokers, maybeCompileToBytecode, void, $MethodHandle*)},
	{"maybeCustomize", "(Ljava/lang/invoke/MethodHandle;)V", nullptr, $STATIC, $staticMethod(Invokers, maybeCustomize, void, $MethodHandle*), nullptr, nullptr, _Invokers_MethodAnnotations_maybeCustomize27},
	{"methodHandleInvokeLinkerMethod", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(Invokers, methodHandleInvokeLinkerMethod, $MemberName*, $String*, $MethodType*, $ObjectArray*)},
	{"newWrongMethodTypeException", "(Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/WrongMethodTypeException;", nullptr, $STATIC, $staticMethod(Invokers, newWrongMethodTypeException, $WrongMethodTypeException*, $MethodType*, $MethodType*)},
	{"setCachedInvoker", "(ILjava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(Invokers, setCachedInvoker, $MethodHandle*, int32_t, $MethodHandle*)},
	{"setCachedVHInvoker", "(ZLjava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(Invokers, setCachedVHInvoker, $MethodHandle*, bool, $VarHandle$AccessMode*, $MethodHandle*)},
	{"spreadInvoker", "(I)Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(Invokers, spreadInvoker, $MethodHandle*, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Invokers, toString, $String*)},
	{"varHandleInvokeLinkerMethod", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(Invokers, varHandleInvokeLinkerMethod, $MemberName*, $MethodType*)},
	{"varHandleMethodExactInvoker", "(Ljava/lang/invoke/VarHandle$AccessMode;)Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(Invokers, varHandleMethodExactInvoker, $MethodHandle*, $VarHandle$AccessMode*)},
	{"varHandleMethodGenericLinkerHandleForm", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $STATIC, $staticMethod(Invokers, varHandleMethodGenericLinkerHandleForm, $LambdaForm*, $MethodType*)},
	{"varHandleMethodInvoker", "(Ljava/lang/invoke/VarHandle$AccessMode;)Ljava/lang/invoke/MethodHandle;", nullptr, 0, $virtualMethod(Invokers, varHandleMethodInvoker, $MethodHandle*, $VarHandle$AccessMode*)},
	{"varHandleMethodInvokerHandleForm", "(Ljava/lang/invoke/MethodType;Z)Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $STATIC, $staticMethod(Invokers, varHandleMethodInvokerHandleForm, $LambdaForm*, $MethodType*, bool)},
	{}
};

$InnerClassInfo _Invokers_InnerClassesInfo_[] = {
	{"java.lang.invoke.Invokers$Holder", "java.lang.invoke.Invokers", "Holder", $FINAL},
	{"java.lang.invoke.Invokers$Lazy", "java.lang.invoke.Invokers", "Lazy", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Invokers_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.invoke.Invokers",
	"java.lang.Object",
	nullptr,
	_Invokers_FieldInfo_,
	_Invokers_MethodInfo_,
	nullptr,
	nullptr,
	_Invokers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.Invokers$Holder,java.lang.invoke.Invokers$Lazy"
};

$Object* allocate$Invokers($Class* clazz) {
	return $of($alloc(Invokers));
}

bool Invokers::$assertionsDisabled = false;
int32_t Invokers::VH_INV_GENERIC = 0;
int32_t Invokers::INV_LIMIT = 0;
$LambdaForm$NamedFunctionArray* Invokers::NFS = nullptr;

void Invokers::init$($MethodType* targetType) {
	$set(this, invokers, $new($MethodHandleArray, Invokers::INV_LIMIT));
	$set(this, targetType, targetType);
}

$MethodHandle* Invokers::exactInvoker() {
	$var($MethodHandle, invoker, cachedInvoker(Invokers::INV_EXACT));
	if (invoker != nullptr) {
		return invoker;
	}
	$assign(invoker, makeExactOrGeneralInvoker(true));
	return setCachedInvoker(Invokers::INV_EXACT, invoker);
}

$MethodHandle* Invokers::genericInvoker() {
	$var($MethodHandle, invoker, cachedInvoker(Invokers::INV_GENERIC));
	if (invoker != nullptr) {
		return invoker;
	}
	$assign(invoker, makeExactOrGeneralInvoker(false));
	return setCachedInvoker(Invokers::INV_GENERIC, invoker);
}

$MethodHandle* Invokers::basicInvoker() {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, invoker, cachedInvoker(Invokers::INV_BASIC));
	if (invoker != nullptr) {
		return invoker;
	}
	$var($MethodType, basicType, $nc(this->targetType)->basicType());
	if (basicType != this->targetType) {
		return setCachedInvoker(Invokers::INV_BASIC, $($nc($($nc(basicType)->invokers()))->basicInvoker()));
	}
	$assign(invoker, $nc($($nc(basicType)->form()))->cachedMethodHandle($MethodTypeForm::MH_BASIC_INV));
	if (invoker == nullptr) {
		$var($MemberName, method, invokeBasicMethod(basicType));
		$assign(invoker, $DirectMethodHandle::make(method));
		if (!Invokers::$assertionsDisabled && !(checkInvoker(invoker))) {
			$throwNew($AssertionError);
		}
		$assign(invoker, $nc($(basicType->form()))->setCachedMethodHandle($MethodTypeForm::MH_BASIC_INV, invoker));
	}
	return setCachedInvoker(Invokers::INV_BASIC, invoker);
}

$MethodHandle* Invokers::varHandleMethodInvoker($VarHandle$AccessMode* ak) {
	bool isExact = false;
	$var($MethodHandle, invoker, cachedVHInvoker(isExact, ak));
	if (invoker != nullptr) {
		return invoker;
	}
	$assign(invoker, makeVarHandleMethodInvoker(ak, isExact));
	return setCachedVHInvoker(isExact, ak, invoker);
}

$MethodHandle* Invokers::varHandleMethodExactInvoker($VarHandle$AccessMode* ak) {
	bool isExact = true;
	$var($MethodHandle, invoker, cachedVHInvoker(isExact, ak));
	if (invoker != nullptr) {
		return invoker;
	}
	$assign(invoker, makeVarHandleMethodInvoker(ak, isExact));
	return setCachedVHInvoker(isExact, ak, invoker);
}

$MethodHandle* Invokers::cachedInvoker(int32_t idx) {
	return $nc(this->invokers)->get(idx);
}

$MethodHandle* Invokers::setCachedInvoker(int32_t idx, $MethodHandle* invoker) {
	$synchronized(this) {
		$var($MethodHandle, prev, $nc(this->invokers)->get(idx));
		if (prev != nullptr) {
			return prev;
		}
		return $nc(this->invokers)->set(idx, invoker);
	}
}

$MethodHandle* Invokers::cachedVHInvoker(bool isExact, $VarHandle$AccessMode* ak) {
	int32_t baseIndex = (isExact ? Invokers::VH_INV_EXACT : Invokers::VH_INV_GENERIC);
	return cachedInvoker(baseIndex + $nc(ak)->ordinal());
}

$MethodHandle* Invokers::setCachedVHInvoker(bool isExact, $VarHandle$AccessMode* ak, $MethodHandle* invoker) {
	int32_t baseIndex = (isExact ? Invokers::VH_INV_EXACT : Invokers::VH_INV_GENERIC);
	return setCachedInvoker(baseIndex + $nc(ak)->ordinal(), invoker);
}

$MethodHandle* Invokers::makeExactOrGeneralInvoker(bool isExact) {
	$useLocalCurrentObjectStackCache();
	$var($MethodType, mtype, this->targetType);
	$var($MethodType, invokerType, $nc(mtype)->invokerType());
	int32_t which = (isExact ? $MethodTypeForm::LF_EX_INVOKER : $MethodTypeForm::LF_GEN_INVOKER);
	$var($LambdaForm, lform, invokeHandleForm(mtype, false, which));
	$var($MethodHandle, invoker, $BoundMethodHandle::bindSingle(invokerType, lform, mtype));
	$var($String, whichName, isExact ? "invokeExact"_s : "invoke"_s);
	$assign(invoker, $nc(invoker)->withInternalMemberName($($MemberName::makeMethodHandleInvoke(whichName, mtype)), false));
	if (!Invokers::$assertionsDisabled && !(checkInvoker(invoker))) {
		$throwNew($AssertionError);
	}
	maybeCompileToBytecode(invoker);
	return invoker;
}

$MethodHandle* Invokers::makeVarHandleMethodInvoker($VarHandle$AccessMode* ak, bool isExact) {
	$useLocalCurrentObjectStackCache();
	$var($MethodType, mtype, this->targetType);
	$load($VarHandle);
	$var($MethodType, invokerType, $nc(mtype)->insertParameterTypes(0, $$new($ClassArray, {$VarHandle::class$})));
	$var($LambdaForm, lform, varHandleMethodInvokerHandleForm(mtype, isExact));
	$var($MethodType, var$0, mtype);
	int32_t var$1 = $nc(ak)->at->ordinal();
	$var($VarHandle$AccessDescriptor, ad, $new($VarHandle$AccessDescriptor, var$0, var$1, ak->ordinal()));
	$var($MethodHandle, invoker, $BoundMethodHandle::bindSingle(invokerType, lform, ad));
	$assign(invoker, $nc(invoker)->withInternalMemberName($($MemberName::makeVarHandleMethodInvoke($($nc(ak)->methodName()), mtype)), false));
	if (!Invokers::$assertionsDisabled && !(checkVarHandleInvoker(invoker))) {
		$throwNew($AssertionError);
	}
	maybeCompileToBytecode(invoker);
	return invoker;
}

void Invokers::maybeCompileToBytecode($MethodHandle* invoker) {
	int32_t EAGER_COMPILE_ARITY_LIMIT = 10;
	bool var$0 = this->targetType == $nc(this->targetType)->erase();
	if (var$0 && $nc(this->targetType)->parameterCount() < EAGER_COMPILE_ARITY_LIMIT) {
		$nc($nc(invoker)->form)->compileToBytecode();
	}
}

$MemberName* Invokers::invokeBasicMethod($MethodType* basicType) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	if (!Invokers::$assertionsDisabled && !(basicType == $nc(basicType)->basicType())) {
		$throwNew($AssertionError);
	}
	try {
		$init($MethodHandles$Lookup);
		$load($MethodHandle);
		return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->resolveOrFail((int8_t)5, $MethodHandle::class$, "invokeBasic"_s, basicType);
	} catch ($ReflectiveOperationException& ex) {
		$throw($($MethodHandleStatics::newInternalError($$str({"JVM cannot find invoker for "_s, basicType}), ex)));
	}
	$shouldNotReachHere();
}

bool Invokers::checkInvoker($MethodHandle* invoker) {
	$useLocalCurrentObjectStackCache();
	if (!Invokers::$assertionsDisabled && !($nc($($nc(this->targetType)->invokerType()))->equals($($of($nc(invoker)->type()))))) {
		$throwNew($AssertionError, $($of($Arrays::asList($$new($ConstableArray, {
			static_cast<$Constable*>(this->targetType),
			$(static_cast<$Constable*>($nc(this->targetType)->invokerType())),
			static_cast<$Constable*>(invoker)
		})))));
	}
	bool var$0 = !Invokers::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(invoker)->internalMemberName() == nullptr;
		var$0 = !(var$1 || $nc($($nc($($nc(invoker)->internalMemberName()))->getMethodType()))->equals($of(this->targetType)));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	if (!Invokers::$assertionsDisabled && !(!$nc(invoker)->isVarargsCollector())) {
		$throwNew($AssertionError);
	}
	return true;
}

bool Invokers::checkVarHandleInvoker($MethodHandle* invoker) {
	$useLocalCurrentObjectStackCache();
	$load($VarHandle);
	$var($MethodType, invokerType, $nc(this->targetType)->insertParameterTypes(0, $$new($ClassArray, {$VarHandle::class$})));
	if (!Invokers::$assertionsDisabled && !($nc(invokerType)->equals($($of($nc(invoker)->type()))))) {
		$throwNew($AssertionError, $($of($Arrays::asList($$new($ConstableArray, {
			static_cast<$Constable*>(this->targetType),
			static_cast<$Constable*>(invokerType),
			static_cast<$Constable*>(invoker)
		})))));
	}
	bool var$0 = !Invokers::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(invoker)->internalMemberName() == nullptr;
		var$0 = !(var$1 || $nc($($nc($($nc(invoker)->internalMemberName()))->getMethodType()))->equals($of(this->targetType)));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	if (!Invokers::$assertionsDisabled && !(!$nc(invoker)->isVarargsCollector())) {
		$throwNew($AssertionError);
	}
	return true;
}

$MethodHandle* Invokers::spreadInvoker(int32_t leadingArgCount) {
	$useLocalCurrentObjectStackCache();
	int32_t spreadArgCount = $nc(this->targetType)->parameterCount() - leadingArgCount;
	$var($MethodType, postSpreadType, this->targetType);
	$Class* argArrayType = impliedRestargType(postSpreadType, leadingArgCount);
	if ($nc(postSpreadType)->parameterSlotCount() <= $MethodType::MAX_MH_INVOKER_ARITY) {
		return $nc($(genericInvoker()))->asSpreader(argArrayType, spreadArgCount);
	}
	$var($MethodType, preSpreadType, $nc(postSpreadType)->replaceParameterTypes(leadingArgCount, postSpreadType->parameterCount(), $$new($ClassArray, {argArrayType})));
	$var($MethodHandle, arrayInvoker, $MethodHandles::invoker(preSpreadType));
	$init($Invokers$Lazy);
	$var($MethodHandle, makeSpreader, $MethodHandles::insertArguments($Invokers$Lazy::MH_asSpreader, 1, $$new($ObjectArray, {
		$of(argArrayType),
		$($of($Integer::valueOf(spreadArgCount)))
	})));
	return $MethodHandles::filterArgument(arrayInvoker, 0, makeSpreader);
}

$Class* Invokers::impliedRestargType($MethodType* restargType, int32_t fromPos) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	if ($nc(restargType)->isGeneric()) {
		$load($ObjectArray);
		return $getClass($ObjectArray);
	}
	int32_t maxPos = $nc(restargType)->parameterCount();
	if (fromPos >= maxPos) {
		$load($ObjectArray);
		return $getClass($ObjectArray);
	}
	$Class* argType = $cast($Class, restargType->parameterType(fromPos));
	for (int32_t i = fromPos + 1; i < maxPos; ++i) {
		if (argType != $cast($Class, restargType->parameterType(i))) {
			$throw($($MethodHandleStatics::newIllegalArgumentException("need homogeneous rest arguments"_s, restargType)));
		}
	}
	if (argType == $Object::class$) {
		$load($ObjectArray);
		return $getClass($ObjectArray);
	}
	return $of($($1Array::newInstance(argType, 0)))->getClass();
}

$String* Invokers::toString() {
	return $str({"Invokers"_s, this->targetType});
}

$MemberName* Invokers::methodHandleInvokeLinkerMethod($String* name, $MethodType* mtype, $ObjectArray* appendixResult) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($String, s11780$, name);
	int32_t tmp11780$ = -1;
	switch ($nc(s11780$)->hashCode()) {
	case 0x38222167:
		{
			if (s11780$->equals("invokeExact"_s)) {
				tmp11780$ = 0;
			}
			break;
		}
	case (int32_t)0xB9724478:
		{
			if (s11780$->equals("invoke"_s)) {
				tmp11780$ = 1;
			}
			break;
		}
	}

	int32_t var$0 = 0;
	switch (tmp11780$) {
	case 0:
		{
			var$0 = $MethodTypeForm::LF_EX_LINKER;
			break;
		}
	case 1:
		{
			var$0 = $MethodTypeForm::LF_GEN_LINKER;
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"not invoker: "_s, name}));
		}
	}
	int32_t which = var$0;
	$var($LambdaForm, lform, nullptr);
	if ($nc(mtype)->parameterSlotCount() <= $MethodType::MAX_MH_ARITY - Invokers::MH_LINKER_ARG_APPENDED) {
		$assign(lform, invokeHandleForm(mtype, false, which));
		$nc(appendixResult)->set(0, mtype);
	} else {
		$assign(lform, invokeHandleForm(mtype, true, which));
	}
	return $nc(lform)->vmentry;
}

$LambdaForm* Invokers::invokeHandleForm($MethodType* mtype$renamed, bool customized, int32_t which) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, mtype, mtype$renamed);
	bool isCached = false;
	if (!customized) {
		$assign(mtype, $nc(mtype)->basicType());
		isCached = true;
	} else {
		isCached = false;
	}
	bool isLinker = false;
	bool isGeneric = false;
	$LambdaForm$Kind* kind = nullptr;
	switch (which) {
	case $MethodTypeForm::LF_EX_LINKER:
		{
			isLinker = true;
			isGeneric = false;
			$init($LambdaForm$Kind);
			kind = $LambdaForm$Kind::EXACT_LINKER;
			break;
		}
	case $MethodTypeForm::LF_EX_INVOKER:
		{
			isLinker = false;
			isGeneric = false;
			$init($LambdaForm$Kind);
			kind = $LambdaForm$Kind::EXACT_INVOKER;
			break;
		}
	case $MethodTypeForm::LF_GEN_LINKER:
		{
			isLinker = true;
			isGeneric = true;
			$init($LambdaForm$Kind);
			kind = $LambdaForm$Kind::GENERIC_LINKER;
			break;
		}
	case $MethodTypeForm::LF_GEN_INVOKER:
		{
			isLinker = false;
			isGeneric = true;
			$init($LambdaForm$Kind);
			kind = $LambdaForm$Kind::GENERIC_INVOKER;
			break;
		}
	default:
		{
			$throwNew($InternalError);
		}
	}
	$var($LambdaForm, lform, nullptr);
	if (isCached) {
		$assign(lform, $nc($($nc(mtype)->form()))->cachedLambdaForm(which));
		if (lform != nullptr) {
			return lform;
		}
	}
	int32_t THIS_MH = 0;
	int32_t CALL_MH = THIS_MH + (isLinker ? 0 : 1);
	int32_t ARG_BASE = CALL_MH + 1;
	int32_t OUTARG_LIMIT = ARG_BASE + $nc(mtype)->parameterCount();
	int32_t INARG_LIMIT = OUTARG_LIMIT + (isLinker && !customized ? 1 : 0);
	int32_t nameCursor = OUTARG_LIMIT;
	int32_t MTYPE_ARG = customized ? -1 : nameCursor++;
	int32_t CHECK_TYPE = nameCursor++;
	$init($MethodHandleStatics);
	int32_t CHECK_CUSTOM = ($MethodHandleStatics::CUSTOMIZE_THRESHOLD >= 0) ? nameCursor++ : -1;
	int32_t LINKER_CALL = nameCursor++;
	$var($MethodType, invokerFormType, mtype->invokerType());
	if (isLinker) {
		if (!customized) {
			$load($MemberName);
			$assign(invokerFormType, $nc(invokerFormType)->appendParameterTypes($$new($ClassArray, {$MemberName::class$})));
		}
	} else {
		$assign(invokerFormType, $nc(invokerFormType)->invokerType());
	}
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - INARG_LIMIT, invokerFormType));
	if (!Invokers::$assertionsDisabled && !($nc(names)->length == nameCursor)) {
		$throwNew($AssertionError, $($of($Arrays::asList($$new($SerializableArray, {
			static_cast<$Serializable*>(mtype),
			$(static_cast<$Serializable*>($Boolean::valueOf(customized))),
			$(static_cast<$Serializable*>($Integer::valueOf(which))),
			$(static_cast<$Serializable*>($Integer::valueOf(nameCursor))),
			$(static_cast<$Serializable*>($Integer::valueOf(names->length)))
		})))));
	}
	if (MTYPE_ARG >= INARG_LIMIT) {
		if (!Invokers::$assertionsDisabled && !($nc(names)->get(MTYPE_ARG) == nullptr)) {
			$throwNew($AssertionError);
		}
		$var($BoundMethodHandle$SpeciesData, speciesData, $BoundMethodHandle::speciesData_L());
		$nc(names)->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(speciesData)));
		$var($LambdaForm$NamedFunction, getter, $nc(speciesData)->getterFunction(0));
		names->set(MTYPE_ARG, $$new($LambdaForm$Name, getter, $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	}
	$var($MethodType, outCallType, mtype->basicType());
	$load($ObjectArray);
	$var($ObjectArray, outArgs, $Arrays::copyOfRange(names, CALL_MH, OUTARG_LIMIT, $getClass($ObjectArray)));
	$var($Object, mtypeArg, customized ? $of(mtype) : $of($nc(names)->get(MTYPE_ARG)));
	if (!isGeneric) {
		names->set(CHECK_TYPE, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkExactType)), $$new($ObjectArray, {
			$of(names->get(CALL_MH)),
			mtypeArg
		})));
	} else {
		names->set(CHECK_TYPE, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkGenericType)), $$new($ObjectArray, {
			$of(names->get(CALL_MH)),
			mtypeArg
		})));
		outArgs->set(0, names->get(CHECK_TYPE));
	}
	if (CHECK_CUSTOM != -1) {
		names->set(CHECK_CUSTOM, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkCustomized)), $$new($ObjectArray, {outArgs->get(0)})));
	}
	names->set(LINKER_CALL, $$new($LambdaForm$Name, outCallType, outArgs));
	if (customized) {
		$assign(lform, $new($LambdaForm, INARG_LIMIT, names));
	} else {
		$assign(lform, $new($LambdaForm, INARG_LIMIT, names, kind));
	}
	if (isLinker) {
		$nc(lform)->compileToBytecode();
	}
	if (isCached) {
		$assign(lform, $nc($(mtype->form()))->setCachedLambdaForm(which, lform));
	}
	return lform;
}

$MemberName* Invokers::varHandleInvokeLinkerMethod($MethodType* mtype) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	if ($nc(mtype)->parameterSlotCount() > $MethodType::MAX_MH_ARITY - Invokers::MH_LINKER_ARG_APPENDED) {
		$throw($($MethodHandleStatics::newInternalError($$str({"Unsupported parameter slot count "_s, $$str(mtype->parameterSlotCount())}))));
	}
	$var($LambdaForm, lform, varHandleMethodGenericLinkerHandleForm(mtype));
	return $nc(lform)->vmentry;
}

$LambdaForm* Invokers::varHandleMethodGenericLinkerHandleForm($MethodType* mtype$renamed) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, mtype, mtype$renamed);
	$assign(mtype, $nc(mtype)->basicType());
	int32_t which = $MethodTypeForm::LF_VH_GEN_LINKER;
	$var($LambdaForm, lform, $nc($(mtype->form()))->cachedLambdaForm(which));
	if (lform != nullptr) {
		return lform;
	}
	int32_t THIS_VH = 0;
	int32_t ARG_BASE = THIS_VH + 1;
	int32_t ARG_LIMIT = ARG_BASE + mtype->parameterCount();
	int32_t nameCursor = ARG_LIMIT;
	int32_t VAD_ARG = nameCursor++;
	int32_t UNBOUND_VH = nameCursor++;
	int32_t CHECK_TYPE = nameCursor++;
	$init($MethodHandleStatics);
	int32_t CHECK_CUSTOM = ($MethodHandleStatics::CUSTOMIZE_THRESHOLD >= 0) ? nameCursor++ : -1;
	int32_t LINKER_CALL = nameCursor++;
	$var($LambdaForm$NameArray, names, $new($LambdaForm$NameArray, LINKER_CALL + 1));
	names->set(THIS_VH, $($LambdaForm::argument(THIS_VH, $($LambdaForm$BasicType::basicType($Object::class$)))));
	for (int32_t i = 0; i < mtype->parameterCount(); ++i) {
		names->set(ARG_BASE + i, $($LambdaForm::argument(ARG_BASE + i, $($LambdaForm$BasicType::basicType($($cast($Class, mtype->parameterType(i))))))));
	}
	names->set(VAD_ARG, $$new($LambdaForm$Name, ARG_LIMIT, $($LambdaForm$BasicType::basicType($Object::class$))));
	names->set(UNBOUND_VH, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_directVarHandleTarget)), $$new($ObjectArray, {$of(names->get(THIS_VH))})));
	names->set(CHECK_TYPE, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkVarHandleGenericType)), $$new($ObjectArray, {
		$of(names->get(THIS_VH)),
		$of(names->get(VAD_ARG))
	})));
	$var($ObjectArray, outArgs, $new($ObjectArray, ARG_LIMIT + 1));
	outArgs->set(0, names->get(CHECK_TYPE));
	outArgs->set(1, names->get(UNBOUND_VH));
	for (int32_t i = 1; i < ARG_LIMIT; ++i) {
		outArgs->set(i + 1, names->get(i));
	}
	if (CHECK_CUSTOM != -1) {
		names->set(CHECK_CUSTOM, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkCustomized)), $$new($ObjectArray, {outArgs->get(0)})));
	}
	$load($VarHandle);
	$var($MethodType, outCallType, $nc($(mtype->insertParameterTypes(0, $$new($ClassArray, {$VarHandle::class$}))))->basicType());
	names->set(LINKER_CALL, $$new($LambdaForm$Name, outCallType, outArgs));
	$init($LambdaForm$Kind);
	$assign(lform, $new($LambdaForm, ARG_LIMIT + 1, names, $LambdaForm$Kind::VARHANDLE_LINKER));
	if ($LambdaForm::debugNames()) {
		$var($String, name, $str({"VarHandle_invoke_MT_"_s, $($LambdaForm::shortenSignature($($LambdaForm::basicTypeSignature(mtype))))}));
		$LambdaForm::associateWithDebugName(lform, name);
	}
	lform->compileToBytecode();
	$assign(lform, $nc($(mtype->form()))->setCachedLambdaForm(which, lform));
	return lform;
}

$LambdaForm* Invokers::varHandleMethodInvokerHandleForm($MethodType* mtype$renamed, bool isExact) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, mtype, mtype$renamed);
	$assign(mtype, $nc(mtype)->basicType());
	int32_t which = (isExact ? $MethodTypeForm::LF_VH_EX_INVOKER : $MethodTypeForm::LF_VH_GEN_INVOKER);
	$var($LambdaForm, lform, $nc($(mtype->form()))->cachedLambdaForm(which));
	if (lform != nullptr) {
		return lform;
	}
	int32_t THIS_MH = 0;
	int32_t CALL_VH = THIS_MH + 1;
	int32_t ARG_BASE = CALL_VH + 1;
	int32_t ARG_LIMIT = ARG_BASE + mtype->parameterCount();
	int32_t nameCursor = ARG_LIMIT;
	int32_t VAD_ARG = nameCursor++;
	int32_t UNBOUND_VH = nameCursor++;
	int32_t CHECK_TYPE = nameCursor++;
	int32_t LINKER_CALL = nameCursor++;
	$var($LambdaForm$NameArray, names, $new($LambdaForm$NameArray, LINKER_CALL + 1));
	names->set(THIS_MH, $($LambdaForm::argument(THIS_MH, $($LambdaForm$BasicType::basicType($Object::class$)))));
	names->set(CALL_VH, $($LambdaForm::argument(CALL_VH, $($LambdaForm$BasicType::basicType($Object::class$)))));
	for (int32_t i = 0; i < mtype->parameterCount(); ++i) {
		names->set(ARG_BASE + i, $($LambdaForm::argument(ARG_BASE + i, $($LambdaForm$BasicType::basicType($($cast($Class, mtype->parameterType(i))))))));
	}
	$var($BoundMethodHandle$SpeciesData, speciesData, $BoundMethodHandle::speciesData_L());
	names->set(THIS_MH, $($nc(names->get(THIS_MH))->withConstraint(speciesData)));
	$var($LambdaForm$NamedFunction, getter, $nc(speciesData)->getterFunction(0));
	names->set(VAD_ARG, $$new($LambdaForm$Name, getter, $$new($ObjectArray, {$of(names->get(THIS_MH))})));
	names->set(UNBOUND_VH, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_directVarHandleTarget)), $$new($ObjectArray, {$of(names->get(CALL_VH))})));
	if (isExact) {
		names->set(CHECK_TYPE, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkVarHandleExactType)), $$new($ObjectArray, {
			$of(names->get(CALL_VH)),
			$of(names->get(VAD_ARG))
		})));
	} else {
		names->set(CHECK_TYPE, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_checkVarHandleGenericType)), $$new($ObjectArray, {
			$of(names->get(CALL_VH)),
			$of(names->get(VAD_ARG))
		})));
	}
	$var($ObjectArray, outArgs, $new($ObjectArray, ARG_LIMIT));
	outArgs->set(0, names->get(CHECK_TYPE));
	outArgs->set(1, names->get(UNBOUND_VH));
	for (int32_t i = 2; i < ARG_LIMIT; ++i) {
		outArgs->set(i, names->get(i));
	}
	$load($VarHandle);
	$var($MethodType, outCallType, $nc($(mtype->insertParameterTypes(0, $$new($ClassArray, {$VarHandle::class$}))))->basicType());
	names->set(LINKER_CALL, $$new($LambdaForm$Name, outCallType, outArgs));
	$init($LambdaForm$Kind);
	$LambdaForm$Kind* kind = isExact ? $LambdaForm$Kind::VARHANDLE_EXACT_INVOKER : $LambdaForm$Kind::VARHANDLE_INVOKER;
	$assign(lform, $new($LambdaForm, ARG_LIMIT, names, kind));
	if ($LambdaForm::debugNames()) {
		$var($String, name, $str({(isExact ? "VarHandle_exactInvoker_"_s : "VarHandle_invoker_"_s), $($LambdaForm::shortenSignature($($LambdaForm::basicTypeSignature(mtype))))}));
		$LambdaForm::associateWithDebugName(lform, name);
	}
	lform->prepare();
	$assign(lform, $nc($(mtype->form()))->setCachedLambdaForm(which, lform));
	return lform;
}

$MethodHandle* Invokers::checkVarHandleGenericType($VarHandle* handle, $VarHandle$AccessDescriptor* ad) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(handle)->hasInvokeExactBehavior();
	if (var$0 && handle->accessModeType($nc(ad)->type) != $nc(ad)->symbolicMethodTypeExact) {
		$throwNew($WrongMethodTypeException, $$str({"expected "_s, $(handle->accessModeType(ad->type)), " but found "_s, ad->symbolicMethodTypeExact}));
	}
	$var($MethodHandle, mh, $nc(handle)->getMethodHandle($nc(ad)->mode));
	if ($nc(mh)->type() != $nc(ad)->symbolicMethodTypeInvoker) {
		return mh->asType(ad->symbolicMethodTypeInvoker);
	}
	return mh;
}

$MethodHandle* Invokers::checkVarHandleExactType($VarHandle* handle, $VarHandle$AccessDescriptor* ad) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, mh, $nc(handle)->getMethodHandle($nc(ad)->mode));
	$var($MethodType, mt, $nc(mh)->type());
	if (mt != $nc(ad)->symbolicMethodTypeInvoker) {
		$throw($(newWrongMethodTypeException(mt, ad->symbolicMethodTypeInvoker)));
	}
	return mh;
}

$WrongMethodTypeException* Invokers::newWrongMethodTypeException($MethodType* actual, $MethodType* expected) {
	$init(Invokers);
	return $new($WrongMethodTypeException, $$str({"expected "_s, expected, " but found "_s, actual}));
}

void Invokers::checkExactType($MethodHandle* mh, $MethodType* expected) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, actual, $nc(mh)->type());
	if (actual != expected) {
		$throw($(newWrongMethodTypeException(expected, actual)));
	}
}

$MethodHandle* Invokers::checkGenericType($MethodHandle* mh, $MethodType* expected) {
	$init(Invokers);
	return $nc(mh)->asType(expected);
}

$VarHandle* Invokers::directVarHandleTarget($VarHandle* handle) {
	$init(Invokers);
	return $nc(handle)->asDirect();
}

$MemberName* Invokers::linkToCallSiteMethod($MethodType* mtype) {
	$init(Invokers);
	$var($LambdaForm, lform, callSiteForm(mtype, false));
	return $nc(lform)->vmentry;
}

$MemberName* Invokers::linkToTargetMethod($MethodType* mtype) {
	$init(Invokers);
	$var($LambdaForm, lform, callSiteForm(mtype, true));
	return $nc(lform)->vmentry;
}

$LambdaForm* Invokers::callSiteForm($MethodType* mtype$renamed, bool skipCallSite) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, mtype, mtype$renamed);
	$assign(mtype, $nc(mtype)->basicType());
	int32_t which = (skipCallSite ? $MethodTypeForm::LF_MH_LINKER : $MethodTypeForm::LF_CS_LINKER);
	$var($LambdaForm, lform, $nc($(mtype->form()))->cachedLambdaForm(which));
	if (lform != nullptr) {
		return lform;
	}
	int32_t ARG_BASE = 0;
	int32_t OUTARG_LIMIT = ARG_BASE + mtype->parameterCount();
	int32_t INARG_LIMIT = OUTARG_LIMIT + 1;
	int32_t nameCursor = OUTARG_LIMIT;
	int32_t APPENDIX_ARG = nameCursor++;
	int32_t CSITE_ARG = skipCallSite ? -1 : APPENDIX_ARG;
	int32_t CALL_MH = skipCallSite ? APPENDIX_ARG : nameCursor++;
	int32_t LINKER_CALL = nameCursor++;
	$load($MethodHandle);
	$load($CallSite);
	$var($MethodType, invokerFormType, mtype->appendParameterTypes($$new($ClassArray, {skipCallSite ? $MethodHandle::class$ : $CallSite::class$})));
	$var($LambdaForm$NameArray, names, $LambdaForm::arguments(nameCursor - INARG_LIMIT, invokerFormType));
	if (!Invokers::$assertionsDisabled && !($nc(names)->length == nameCursor)) {
		$throwNew($AssertionError);
	}
	if (!Invokers::$assertionsDisabled && !($nc(names)->get(APPENDIX_ARG) != nullptr)) {
		$throwNew($AssertionError);
	}
	if (!skipCallSite) {
		$nc(names)->set(CALL_MH, $$new($LambdaForm$Name, $(getFunction(Invokers::NF_getCallSiteTarget)), $$new($ObjectArray, {$of(names->get(CSITE_ARG))})));
	}
	int32_t PREPEND_MH = 0;
	int32_t PREPEND_COUNT = 1;
	$load($ObjectArray);
	$var($ObjectArray, outArgs, $Arrays::copyOfRange(names, ARG_BASE, OUTARG_LIMIT + PREPEND_COUNT, $getClass($ObjectArray)));
	$System::arraycopy(outArgs, 0, outArgs, PREPEND_COUNT, outArgs->length - PREPEND_COUNT);
	outArgs->set(PREPEND_MH, $nc(names)->get(CALL_MH));
	names->set(LINKER_CALL, $$new($LambdaForm$Name, mtype, outArgs));
	$init($LambdaForm$Kind);
	$assign(lform, $new($LambdaForm, INARG_LIMIT, names, (skipCallSite ? $LambdaForm$Kind::LINK_TO_TARGET_METHOD : $LambdaForm$Kind::LINK_TO_CALL_SITE)));
	lform->compileToBytecode();
	$assign(lform, $nc($(mtype->form()))->setCachedLambdaForm(which, lform));
	return lform;
}

$MethodHandle* Invokers::getCallSiteTarget($CallSite* site) {
	$init(Invokers);
	return $nc(site)->getTarget();
}

void Invokers::checkCustomized($MethodHandle* mh) {
	$init(Invokers);
	if ($MethodHandleImpl::isCompileConstant(mh)) {
		return;
	}
	if ($nc($nc(mh)->form)->customized == nullptr) {
		maybeCustomize(mh);
	}
}

void Invokers::maybeCustomize($MethodHandle* mh) {
	$init(Invokers);
	$nc(mh)->maybeCustomize();
}

$LambdaForm$NamedFunction* Invokers::getFunction(int8_t func) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$NamedFunction, nf, $nc(Invokers::NFS)->get(func));
	if (nf != nullptr) {
		return nf;
	}
	$nc(Invokers::NFS)->set(func, $assign(nf, createFunction(func)));
	if (!Invokers::$assertionsDisabled && !($InvokerBytecodeGenerator::isStaticallyInvocable($$new($LambdaForm$NamedFunctionArray, {nf})))) {
		$throwNew($AssertionError);
	}
	return nf;
}

$LambdaForm$NamedFunction* Invokers::createFunction(int8_t func) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	try {

		$var($LambdaForm$NamedFunction, var$0, nullptr)
		switch (func) {
		case Invokers::NF_checkExactType:
			{
				$init($Void);
				$load($MethodHandle);
				$load($MethodType);
				$assign(var$0, getNamedFunction("checkExactType"_s, $($MethodType::methodType($Void::TYPE, $MethodHandle::class$, $$new($ClassArray, {$MethodType::class$})))));
				break;
			}
		case Invokers::NF_checkGenericType:
			{
				$load($MethodHandle);
				$load($MethodType);
				$assign(var$0, getNamedFunction("checkGenericType"_s, $($MethodType::methodType($MethodHandle::class$, $MethodHandle::class$, $$new($ClassArray, {$MethodType::class$})))));
				break;
			}
		case Invokers::NF_getCallSiteTarget:
			{
				$load($MethodHandle);
				$load($CallSite);
				$assign(var$0, getNamedFunction("getCallSiteTarget"_s, $($MethodType::methodType($MethodHandle::class$, $CallSite::class$))));
				break;
			}
		case Invokers::NF_checkCustomized:
			{
				$init($Void);
				$load($MethodHandle);
				$assign(var$0, getNamedFunction("checkCustomized"_s, $($MethodType::methodType($Void::TYPE, $MethodHandle::class$))));
				break;
			}
		case Invokers::NF_checkVarHandleGenericType:
			{
				$load($MethodHandle);
				$load($VarHandle);
				$load($VarHandle$AccessDescriptor);
				$assign(var$0, getNamedFunction("checkVarHandleGenericType"_s, $($MethodType::methodType($MethodHandle::class$, $VarHandle::class$, $$new($ClassArray, {$VarHandle$AccessDescriptor::class$})))));
				break;
			}
		case Invokers::NF_checkVarHandleExactType:
			{
				$load($MethodHandle);
				$load($VarHandle);
				$load($VarHandle$AccessDescriptor);
				$assign(var$0, getNamedFunction("checkVarHandleExactType"_s, $($MethodType::methodType($MethodHandle::class$, $VarHandle::class$, $$new($ClassArray, {$VarHandle$AccessDescriptor::class$})))));
				break;
			}
		case Invokers::NF_directVarHandleTarget:
			{
				$load($VarHandle);
				$assign(var$0, getNamedFunction("directVarHandleTarget"_s, $($MethodType::methodType($VarHandle::class$, $VarHandle::class$))));
				break;
			}
		default:
			{
				$throw($($MethodHandleStatics::newInternalError($$str({"Unknown function: "_s, $$str(func)}))));
			}
		}
		return var$0;
	} catch ($ReflectiveOperationException& ex) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(ex))));
	}
	$shouldNotReachHere();
}

$LambdaForm$NamedFunction* Invokers::getNamedFunction($String* name, $MethodType* type) {
	$init(Invokers);
	$useLocalCurrentObjectStackCache();
	$var($MemberName, member, $new($MemberName, Invokers::class$, name, type, (int8_t)6));
	$load($NoSuchMethodException);
	return $new($LambdaForm$NamedFunction, $($nc($($MemberName::getFactory()))->resolveOrFail((int8_t)6, member, Invokers::class$, -1, $NoSuchMethodException::class$)));
}

void clinit$Invokers($Class* class$) {
	Invokers::$assertionsDisabled = !Invokers::class$->desiredAssertionStatus();
	$init($VarHandle$AccessMode);
	Invokers::VH_INV_GENERIC = Invokers::VH_INV_EXACT + $VarHandle$AccessMode::COUNT;
	Invokers::INV_LIMIT = Invokers::VH_INV_GENERIC + $VarHandle$AccessMode::COUNT;
	$assignStatic(Invokers::NFS, $new($LambdaForm$NamedFunctionArray, Invokers::NF_LIMIT));
	{
		$init($MethodHandleStatics);
		$load($Invokers$Holder);
		$nc($MethodHandleStatics::UNSAFE)->ensureClassInitialized($Invokers$Holder::class$);
	}
}

Invokers::Invokers() {
}

$Class* Invokers::load$($String* name, bool initialize) {
	$loadClass(Invokers, name, initialize, &_Invokers_ClassInfo_, clinit$Invokers, allocate$Invokers);
	return class$;
}

$Class* Invokers::class$ = nullptr;

		} // invoke
	} // lang
} // java