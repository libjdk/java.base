#include <java/lang/invoke/MethodHandleNatives.h>

#include <java/lang/AbstractMethodError.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessError.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/IncompatibleClassChangeError.h>
#include <java/lang/InternalError.h>
#include <java/lang/LinkageError.h>
#include <java/lang/NoSuchFieldError.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NoSuchMethodError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/ConstantBootstraps.h>
#include <java/lang/invoke/ConstantCallSite.h>
#include <java/lang/invoke/Invokers.h>
#include <java/lang/invoke/MemberName$Factory.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleNatives$CallSiteContext.h>
#include <java/lang/invoke/MethodHandleNatives$Constants.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/VarHandle$AccessDescriptor.h>
#include <java/lang/invoke/VarHandle$AccessMode.h>
#include <java/lang/invoke/VarHandle$AccessType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/invoke/VarHandleGuards.h>
#include <java/lang/reflect/Field.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#include "_java_lang_invoke_MethodHandleNatives.h"

#undef HR_MASK
#undef IMPL_LOOKUP
#undef JLA
#undef TRACE_METHOD_LINKAGE
#undef UNSAFE
#undef VAR_HANDLE_GUARDS

using $MemberNameArray = $Array<::java::lang::invoke::MemberName>;
using $PrintStream = ::java::io::PrintStream;
using $AbstractMethodError = ::java::lang::AbstractMethodError;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessError = ::java::lang::IllegalAccessError;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IncompatibleClassChangeError = ::java::lang::IncompatibleClassChangeError;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $LinkageError = ::java::lang::LinkageError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NoSuchMethodError = ::java::lang::NoSuchMethodError;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $CallSite = ::java::lang::invoke::CallSite;
using $ConstantBootstraps = ::java::lang::invoke::ConstantBootstraps;
using $ConstantCallSite = ::java::lang::invoke::ConstantCallSite;
using $Invokers = ::java::lang::invoke::Invokers;
using $MemberName = ::java::lang::invoke::MemberName;
using $MemberName$Factory = ::java::lang::invoke::MemberName$Factory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleNatives$CallSiteContext = ::java::lang::invoke::MethodHandleNatives$CallSiteContext;
using $MethodHandleNatives$Constants = ::java::lang::invoke::MethodHandleNatives$Constants;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $VarHandle$AccessDescriptor = ::java::lang::invoke::VarHandle$AccessDescriptor;
using $VarHandle$AccessMode = ::java::lang::invoke::VarHandle$AccessMode;
using $VarHandle$AccessType = ::java::lang::invoke::VarHandle$AccessType;
using $VarHandleGuards = ::java::lang::invoke::VarHandleGuards;
using $Field = ::java::lang::reflect::Field;
using $Arrays = ::java::util::Arrays;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _MethodHandleNatives_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodHandleNatives, $assertionsDisabled)},
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodHandleNatives, JLA)},
	{}
};

$MethodInfo _MethodHandleNatives_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(MethodHandleNatives, init$, void)},
	{"canBeCalledVirtual", "(Ljava/lang/invoke/MemberName;)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, canBeCalledVirtual, bool, $MemberName*)},
	{"canBeCalledVirtual", "(Ljava/lang/invoke/MemberName;Ljava/lang/Class;)Z", "(Ljava/lang/invoke/MemberName;Ljava/lang/Class<*>;)Z", $STATIC, $staticMethod(MethodHandleNatives, canBeCalledVirtual, bool, $MemberName*, $Class*)},
	{"classData", "(Ljava/lang/Class;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;)Ljava/lang/Object;", $STATIC, $staticMethod(MethodHandleNatives, classData, $Object*, $Class*)},
	{"clearCallSiteContext", "(Ljava/lang/invoke/MethodHandleNatives$CallSiteContext;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, clearCallSiteContext, void, $MethodHandleNatives$CallSiteContext*)},
	{"copyOutBootstrapArguments", "(Ljava/lang/Class;[III[Ljava/lang/Object;IZLjava/lang/Object;)V", "(Ljava/lang/Class<*>;[III[Ljava/lang/Object;IZLjava/lang/Object;)V", $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, copyOutBootstrapArguments, void, $Class*, $ints*, int32_t, int32_t, $ObjectArray*, int32_t, bool, Object$*)},
	{"expand", "(Ljava/lang/invoke/MemberName;)V", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, expand, void, $MemberName*)},
	{"findMethodHandleType", "(Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodType;", $STATIC, $staticMethod(MethodHandleNatives, findMethodHandleType, $MethodType*, $Class*, $ClassArray*)},
	{"fixMethodType", "(Ljava/lang/Class;Ljava/lang/Object;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/Class<*>;Ljava/lang/Object;)Ljava/lang/invoke/MethodType;", $PRIVATE | $STATIC, $staticMethod(MethodHandleNatives, fixMethodType, $MethodType*, $Class*, Object$*)},
	{"getCharType", "(Ljava/lang/Class;)C", "(Ljava/lang/Class<*>;)C", $STATIC, $staticMethod(MethodHandleNatives, getCharType, char16_t, $Class*)},
	{"getMemberVMInfo", "(Ljava/lang/invoke/MemberName;)Ljava/lang/Object;", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, getMemberVMInfo, $Object*, $MemberName*)},
	{"getMembers", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;ILjava/lang/Class;I[Ljava/lang/invoke/MemberName;)I", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/String;ILjava/lang/Class<*>;I[Ljava/lang/invoke/MemberName;)I", $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, getMembers, int32_t, $Class*, $String*, $String*, int32_t, $Class*, int32_t, $MemberNameArray*)},
	{"getNamedCon", "(I[Ljava/lang/Object;)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, getNamedCon, int32_t, int32_t, $ObjectArray*)},
	{"getVarHandleGuardMethodName", "(Ljava/lang/invoke/MethodType;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(MethodHandleNatives, getVarHandleGuardMethodName, $String*, $MethodType*)},
	{"init", "(Ljava/lang/invoke/MemberName;Ljava/lang/Object;)V", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, init, void, $MemberName*, Object$*)},
	{"initCauseFrom", "(Ljava/lang/Error;Ljava/lang/Exception;)Ljava/lang/Error;", "<E:Ljava/lang/Error;>(TE;Ljava/lang/Exception;)TE;", $STATIC, $staticMethod(MethodHandleNatives, initCauseFrom, $Error*, $Error*, $Exception*)},
	{"isCallerSensitive", "(Ljava/lang/invoke/MemberName;)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, isCallerSensitive, bool, $MemberName*)},
	{"isPullModeBSM", "(Ljava/lang/invoke/MethodHandle;)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, isPullModeBSM, bool, $MethodHandle*)},
	{"linkCallSite", "(Ljava/lang/Object;ILjava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(MethodHandleNatives, linkCallSite, $MemberName*, Object$*, int32_t, Object$*, Object$*, Object$*, Object$*, $ObjectArray*)},
	{"linkCallSiteImpl", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", $STATIC, $staticMethod(MethodHandleNatives, linkCallSiteImpl, $MemberName*, $Class*, $MethodHandle*, $String*, $MethodType*, Object$*, $ObjectArray*)},
	{"linkCallSiteTracing", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", $STATIC, $staticMethod(MethodHandleNatives, linkCallSiteTracing, $MemberName*, $Class*, $MethodHandle*, $String*, $MethodType*, Object$*, $ObjectArray*)},
	{"linkDynamicConstant", "(Ljava/lang/Object;ILjava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(MethodHandleNatives, linkDynamicConstant, $Object*, Object$*, int32_t, Object$*, Object$*, Object$*, Object$*)},
	{"linkDynamicConstantImpl", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Class;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Class<*>;Ljava/lang/Object;)Ljava/lang/Object;", $STATIC, $staticMethod(MethodHandleNatives, linkDynamicConstantImpl, $Object*, $Class*, $MethodHandle*, $String*, $Class*, Object$*)},
	{"linkDynamicConstantTracing", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Class;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Class<*>;Ljava/lang/Object;)Ljava/lang/Object;", $STATIC, $staticMethod(MethodHandleNatives, linkDynamicConstantTracing, $Object*, $Class*, $MethodHandle*, $String*, $Class*, Object$*)},
	{"linkMethod", "(Ljava/lang/Class;ILjava/lang/Class;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/Class<*>;ILjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", $STATIC, $staticMethod(MethodHandleNatives, linkMethod, $MemberName*, $Class*, int32_t, $Class*, $String*, Object$*, $ObjectArray*)},
	{"linkMethodHandleConstant", "(Ljava/lang/Class;ILjava/lang/Class;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;ILjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleNatives, linkMethodHandleConstant, $MethodHandle*, $Class*, int32_t, $Class*, $String*, Object$*)},
	{"linkMethodImpl", "(Ljava/lang/Class;ILjava/lang/Class;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/Class<*>;ILjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", $STATIC, $staticMethod(MethodHandleNatives, linkMethodImpl, $MemberName*, $Class*, int32_t, $Class*, $String*, Object$*, $ObjectArray*)},
	{"linkMethodTracing", "(Ljava/lang/Class;ILjava/lang/Class;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/Class<*>;ILjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", $STATIC, $staticMethod(MethodHandleNatives, linkMethodTracing, $MemberName*, $Class*, int32_t, $Class*, $String*, Object$*, $ObjectArray*)},
	{"mapLookupExceptionToError", "(Ljava/lang/ReflectiveOperationException;)Ljava/lang/LinkageError;", nullptr, $STATIC, $staticMethod(MethodHandleNatives, mapLookupExceptionToError, $LinkageError*, $ReflectiveOperationException*)},
	{"newNoSuchMethodErrorOnVarHandle", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/NoSuchMethodError;", nullptr, $STATIC, $staticMethod(MethodHandleNatives, newNoSuchMethodErrorOnVarHandle, $NoSuchMethodError*, $String*, $MethodType*)},
	{"objectFieldOffset", "(Ljava/lang/invoke/MemberName;)J", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, objectFieldOffset, int64_t, $MemberName*)},
	{"refKindDoesDispatch", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindDoesDispatch, bool, int8_t)},
	{"refKindHasReceiver", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindHasReceiver, bool, int8_t)},
	{"refKindIsConstructor", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsConstructor, bool, int8_t)},
	{"refKindIsField", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsField, bool, int8_t)},
	{"refKindIsGetter", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsGetter, bool, int8_t)},
	{"refKindIsMethod", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsMethod, bool, int8_t)},
	{"refKindIsSetter", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsSetter, bool, int8_t)},
	{"refKindIsStatic", "(B)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsStatic, bool, int8_t)},
	{"refKindIsValid", "(I)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindIsValid, bool, int32_t)},
	{"refKindName", "(B)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(MethodHandleNatives, refKindName, $String*, int8_t)},
	{"registerNatives", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, registerNatives, void)},
	{"resolve", "(Ljava/lang/invoke/MemberName;Ljava/lang/Class;IZ)Ljava/lang/invoke/MemberName;", "(Ljava/lang/invoke/MemberName;Ljava/lang/Class<*>;IZ)Ljava/lang/invoke/MemberName;", $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, resolve, $MemberName*, $MemberName*, $Class*, int32_t, bool), "java.lang.LinkageError,java.lang.ClassNotFoundException"},
	{"setCallSiteTargetNormal", "(Ljava/lang/invoke/CallSite;Ljava/lang/invoke/MethodHandle;)V", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, setCallSiteTargetNormal, void, $CallSite*, $MethodHandle*)},
	{"setCallSiteTargetVolatile", "(Ljava/lang/invoke/CallSite;Ljava/lang/invoke/MethodHandle;)V", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, setCallSiteTargetVolatile, void, $CallSite*, $MethodHandle*)},
	{"staticArglistForTrace", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleNatives, staticArglistForTrace, $String*, Object$*)},
	{"staticArgumentsPulled", "(Ljava/lang/Object;)Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, staticArgumentsPulled, bool, Object$*)},
	{"staticFieldBase", "(Ljava/lang/invoke/MemberName;)Ljava/lang/Object;", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, staticFieldBase, $Object*, $MemberName*)},
	{"staticFieldOffset", "(Ljava/lang/invoke/MemberName;)J", nullptr, $STATIC | $NATIVE, $staticMethod(MethodHandleNatives, staticFieldOffset, int64_t, $MemberName*)},
	{"varHandleOperationLinkerMethod", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;[Ljava/lang/Object;)Ljava/lang/invoke/MemberName;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleNatives, varHandleOperationLinkerMethod, $MemberName*, $String*, $MethodType*, $ObjectArray*)},
	{"verifyConstants", "()Z", nullptr, $STATIC, $staticMethod(MethodHandleNatives, verifyConstants, bool)},
	{}
};

#define _METHOD_INDEX_clearCallSiteContext 4
#define _METHOD_INDEX_copyOutBootstrapArguments 5
#define _METHOD_INDEX_expand 6
#define _METHOD_INDEX_getMemberVMInfo 10
#define _METHOD_INDEX_getMembers 11
#define _METHOD_INDEX_getNamedCon 12
#define _METHOD_INDEX_init 14
#define _METHOD_INDEX_objectFieldOffset 30
#define _METHOD_INDEX_registerNatives 41
#define _METHOD_INDEX_resolve 42
#define _METHOD_INDEX_setCallSiteTargetNormal 43
#define _METHOD_INDEX_setCallSiteTargetVolatile 44
#define _METHOD_INDEX_staticFieldBase 47
#define _METHOD_INDEX_staticFieldOffset 48

$InnerClassInfo _MethodHandleNatives_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandleNatives$Constants", "java.lang.invoke.MethodHandleNatives", "Constants", $STATIC},
	{"java.lang.invoke.MethodHandleNatives$CallSiteContext", "java.lang.invoke.MethodHandleNatives", "CallSiteContext", $STATIC},
	{}
};

$ClassInfo _MethodHandleNatives_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.invoke.MethodHandleNatives",
	"java.lang.Object",
	nullptr,
	_MethodHandleNatives_FieldInfo_,
	_MethodHandleNatives_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandleNatives_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandleNatives$Constants,java.lang.invoke.MethodHandleNatives$CallSiteContext"
};

$Object* allocate$MethodHandleNatives($Class* clazz) {
	return $of($alloc(MethodHandleNatives));
}

bool MethodHandleNatives::$assertionsDisabled = false;
$JavaLangAccess* MethodHandleNatives::JLA = nullptr;

void MethodHandleNatives::init$() {
}

void MethodHandleNatives::init($MemberName* self, Object$* ref) {
	_Java_java_lang_invoke_MethodHandleNatives_init(self, ($Object*)ref);
}

void MethodHandleNatives::expand($MemberName* self) {
	_Java_java_lang_invoke_MethodHandleNatives_expand(self);
}

$MemberName* MethodHandleNatives::resolve($MemberName* self, $Class* caller, int32_t lookupMode, bool speculativeResolve) {
	return _Java_java_lang_invoke_MethodHandleNatives_resolve(self, caller, lookupMode, speculativeResolve);
}

int32_t MethodHandleNatives::getMembers($Class* defc, $String* matchName, $String* matchSig, int32_t matchFlags, $Class* caller, int32_t skip, $MemberNameArray* results) {
	return _Java_java_lang_invoke_MethodHandleNatives_getMembers(defc, matchName, matchSig, matchFlags, caller, skip, results);
}

int64_t MethodHandleNatives::objectFieldOffset($MemberName* self) {
	return _Java_java_lang_invoke_MethodHandleNatives_objectFieldOffset(self);
}

int64_t MethodHandleNatives::staticFieldOffset($MemberName* self) {
	return _Java_java_lang_invoke_MethodHandleNatives_staticFieldOffset(self);
}

$Object* MethodHandleNatives::staticFieldBase($MemberName* self) {
	return _Java_java_lang_invoke_MethodHandleNatives_staticFieldBase(self);
}

$Object* MethodHandleNatives::getMemberVMInfo($MemberName* self) {
	return _Java_java_lang_invoke_MethodHandleNatives_getMemberVMInfo(self);
}

void MethodHandleNatives::setCallSiteTargetNormal($CallSite* site, $MethodHandle* target) {
	_Java_java_lang_invoke_MethodHandleNatives_setCallSiteTargetNormal(site, target);
}

void MethodHandleNatives::setCallSiteTargetVolatile($CallSite* site, $MethodHandle* target) {
	_Java_java_lang_invoke_MethodHandleNatives_setCallSiteTargetVolatile(site, target);
}

void MethodHandleNatives::copyOutBootstrapArguments($Class* caller, $ints* indexInfo, int32_t start, int32_t end, $ObjectArray* buf, int32_t pos, bool resolve, Object$* ifNotAvailable) {
	_Java_java_lang_invoke_MethodHandleNatives_copyOutBootstrapArguments(caller, indexInfo, start, end, buf, pos, resolve, ($Object*)ifNotAvailable);
}

void MethodHandleNatives::clearCallSiteContext($MethodHandleNatives$CallSiteContext* context) {
	_Java_java_lang_invoke_MethodHandleNatives_clearCallSiteContext(context);
}

void MethodHandleNatives::registerNatives() {
	_Java_java_lang_invoke_MethodHandleNatives_registerNatives();
}

bool MethodHandleNatives::refKindIsValid(int32_t refKind) {
	$init(MethodHandleNatives);
	return (refKind > (int8_t)0 && refKind < (int8_t)10);
}

bool MethodHandleNatives::refKindIsField(int8_t refKind) {
	$init(MethodHandleNatives);
	if (!MethodHandleNatives::$assertionsDisabled && !(refKindIsValid(refKind))) {
		$throwNew($AssertionError);
	}
	return (refKind <= (int8_t)4);
}

bool MethodHandleNatives::refKindIsGetter(int8_t refKind) {
	$init(MethodHandleNatives);
	if (!MethodHandleNatives::$assertionsDisabled && !(refKindIsValid(refKind))) {
		$throwNew($AssertionError);
	}
	return (refKind <= (int8_t)2);
}

bool MethodHandleNatives::refKindIsSetter(int8_t refKind) {
	$init(MethodHandleNatives);
	bool var$0 = refKindIsField(refKind);
	return var$0 && !refKindIsGetter(refKind);
}

bool MethodHandleNatives::refKindIsMethod(int8_t refKind) {
	$init(MethodHandleNatives);
	return !refKindIsField(refKind) && (refKind != (int8_t)8);
}

bool MethodHandleNatives::refKindIsConstructor(int8_t refKind) {
	$init(MethodHandleNatives);
	return (refKind == (int8_t)8);
}

bool MethodHandleNatives::refKindHasReceiver(int8_t refKind) {
	$init(MethodHandleNatives);
	if (!MethodHandleNatives::$assertionsDisabled && !(refKindIsValid(refKind))) {
		$throwNew($AssertionError);
	}
	return ((int32_t)(refKind & (uint32_t)1)) != 0;
}

bool MethodHandleNatives::refKindIsStatic(int8_t refKind) {
	$init(MethodHandleNatives);
	return !refKindHasReceiver(refKind) && (refKind != (int8_t)8);
}

bool MethodHandleNatives::refKindDoesDispatch(int8_t refKind) {
	$init(MethodHandleNatives);
	if (!MethodHandleNatives::$assertionsDisabled && !(refKindIsValid(refKind))) {
		$throwNew($AssertionError);
	}
	return (refKind == (int8_t)5 || refKind == (int8_t)9);
}

$String* MethodHandleNatives::refKindName(int8_t refKind) {
	$init(MethodHandleNatives);
	if (!MethodHandleNatives::$assertionsDisabled && !(refKindIsValid(refKind))) {
		$throwNew($AssertionError);
	}

	$var($String, var$0, nullptr)
	switch (refKind) {
	case 1:
		{
			$assign(var$0, "getField"_s);
			break;
		}
	case 2:
		{
			$assign(var$0, "getStatic"_s);
			break;
		}
	case 3:
		{
			$assign(var$0, "putField"_s);
			break;
		}
	case 4:
		{
			$assign(var$0, "putStatic"_s);
			break;
		}
	case 5:
		{
			$assign(var$0, "invokeVirtual"_s);
			break;
		}
	case 6:
		{
			$assign(var$0, "invokeStatic"_s);
			break;
		}
	case 7:
		{
			$assign(var$0, "invokeSpecial"_s);
			break;
		}
	case 8:
		{
			$assign(var$0, "newInvokeSpecial"_s);
			break;
		}
	case 9:
		{
			$assign(var$0, "invokeInterface"_s);
			break;
		}
	default:
		{
			$assign(var$0, "REF_???"_s);
			break;
		}
	}
	return var$0;
}

int32_t MethodHandleNatives::getNamedCon(int32_t which, $ObjectArray* name) {
	return _Java_java_lang_invoke_MethodHandleNatives_getNamedCon(which, name);
}

bool MethodHandleNatives::verifyConstants() {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ObjectArray, box, $new($ObjectArray, {($Object*)nullptr}));
	for (int32_t i = 0;; ++i) {
		box->set(0, nullptr);
		int32_t vmval = getNamedCon(i, box);
		if (box->get(0) == nullptr) {
			break;
		}
		$var($String, name, $cast($String, box->get(0)));
		try {
			$load($MethodHandleNatives$Constants);
			$var($Field, con, $MethodHandleNatives$Constants::class$->getDeclaredField(name));
			int32_t jval = $nc(con)->getInt(nullptr);
			if (jval == vmval) {
				continue;
			}
			$var($String, err, $str({name, ": JVM has "_s, $$str(vmval), " while Java has "_s, $$str(jval)}));
			if ($nc(name)->equals("CONV_OP_LIMIT"_s)) {
				$nc($System::err)->println($$str({"warning: "_s, err}));
				continue;
			}
			$throwNew($InternalError, err);
		} catch ($NoSuchFieldException& ex) {
			$var($String, err, $str({name, ": JVM has "_s, $$str(vmval), " which Java does not define"_s}));
			continue;
		} catch ($IllegalAccessException& ex) {
			$var($String, err, $str({name, ": JVM has "_s, $$str(vmval), " which Java does not define"_s}));
			continue;
		}
	}
	return true;
}

$MemberName* MethodHandleNatives::linkCallSite(Object$* callerObj, int32_t indexInCP, Object$* bootstrapMethodObj, Object$* nameObj, Object$* typeObj, Object$* staticArguments, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, bootstrapMethod, $cast($MethodHandle, bootstrapMethodObj));
	$Class* caller = $cast($Class, callerObj);
	$var($String, name, $nc($($nc($of(nameObj))->toString()))->intern());
	$var($MethodType, type, $cast($MethodType, typeObj));
	$init($MethodHandleStatics);
	if (!$MethodHandleStatics::TRACE_METHOD_LINKAGE) {
		return linkCallSiteImpl(caller, bootstrapMethod, name, type, staticArguments, appendixResult);
	}
	return linkCallSiteTracing(caller, bootstrapMethod, name, type, staticArguments, appendixResult);
}

$MemberName* MethodHandleNatives::linkCallSiteImpl($Class* caller, $MethodHandle* bootstrapMethod, $String* name, $MethodType* type, Object$* staticArguments, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($CallSite, callSite, $CallSite::makeSite(bootstrapMethod, name, type, staticArguments, caller));
	if ($instanceOf($ConstantCallSite, callSite)) {
		$nc(appendixResult)->set(0, $($nc(callSite)->dynamicInvoker()));
		return $Invokers::linkToTargetMethod(type);
	} else {
		$nc(appendixResult)->set(0, callSite);
		return $Invokers::linkToCallSiteMethod(type);
	}
}

$MemberName* MethodHandleNatives::linkCallSiteTracing($Class* caller, $MethodHandle* bootstrapMethod, $String* name, $MethodType* type, Object$* staticArguments, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($Object, bsmReference, $nc(bootstrapMethod)->internalMemberName());
	if (bsmReference == nullptr) {
		$assign(bsmReference, bootstrapMethod);
	}
	$var($String, staticArglist, staticArglistForTrace(staticArguments));
	$nc($System::out)->println($$str({"linkCallSite "_s, $($nc(caller)->getName()), " "_s, bsmReference, " "_s, name, type, "/"_s, staticArglist}));
	try {
		$var($MemberName, res, linkCallSiteImpl(caller, bootstrapMethod, name, type, staticArguments, appendixResult));
		$nc($System::out)->println($$str({"linkCallSite => "_s, res, " + "_s, $nc(appendixResult)->get(0)}));
		return res;
	} catch ($Throwable& ex) {
		ex->printStackTrace();
		$nc($System::out)->println($$str({"linkCallSite => throw "_s, ex}));
		$throw(ex);
	}
	$shouldNotReachHere();
}

$Object* MethodHandleNatives::linkDynamicConstant(Object$* callerObj, int32_t indexInCP, Object$* bootstrapMethodObj, Object$* nameObj, Object$* typeObj, Object$* staticArguments) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, bootstrapMethod, $cast($MethodHandle, bootstrapMethodObj));
	$Class* caller = $cast($Class, callerObj);
	$var($String, name, $nc($($nc($of(nameObj))->toString()))->intern());
	$Class* type = $cast($Class, typeObj);
	$init($MethodHandleStatics);
	if (!$MethodHandleStatics::TRACE_METHOD_LINKAGE) {
		return $of(linkDynamicConstantImpl(caller, bootstrapMethod, name, type, staticArguments));
	}
	return $of(linkDynamicConstantTracing(caller, bootstrapMethod, name, type, staticArguments));
}

$Object* MethodHandleNatives::linkDynamicConstantImpl($Class* caller, $MethodHandle* bootstrapMethod, $String* name, $Class* type, Object$* staticArguments) {
	$init(MethodHandleNatives);
	return $of($ConstantBootstraps::makeConstant(bootstrapMethod, name, type, staticArguments, caller));
}

$String* MethodHandleNatives::staticArglistForTrace(Object$* staticArguments) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($ObjectArray, staticArguments)) {
		return $str({"BSA="_s, $($Arrays::asList($cast($ObjectArray, staticArguments)))});
	}
	if ($instanceOf($ints, staticArguments)) {
		return $str({"BSA@"_s, $($Arrays::toString($cast($ints, staticArguments)))});
	}
	if (staticArguments == nullptr) {
		return "BSA0=null"_s;
	}
	return $str({"BSA1="_s, staticArguments});
}

$Object* MethodHandleNatives::linkDynamicConstantTracing($Class* caller, $MethodHandle* bootstrapMethod, $String* name, $Class* type, Object$* staticArguments) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($Object, bsmReference, $nc(bootstrapMethod)->internalMemberName());
	if (bsmReference == nullptr) {
		$assign(bsmReference, bootstrapMethod);
	}
	$var($String, staticArglist, staticArglistForTrace(staticArguments));
	$nc($System::out)->println($$str({"linkDynamicConstant "_s, $($nc(caller)->getName()), " "_s, bsmReference, " "_s, name, type, "/"_s, staticArglist}));
	try {
		$var($Object, res, linkDynamicConstantImpl(caller, bootstrapMethod, name, type, staticArguments));
		$nc($System::out)->println($$str({"linkDynamicConstantImpl => "_s, res}));
		return $of(res);
	} catch ($Throwable& ex) {
		ex->printStackTrace();
		$nc($System::out)->println($$str({"linkDynamicConstant => throw "_s, ex}));
		$throw(ex);
	}
	$shouldNotReachHere();
}

bool MethodHandleNatives::staticArgumentsPulled(Object$* staticArguments) {
	$init(MethodHandleNatives);
	return $instanceOf($ints, staticArguments);
}

bool MethodHandleNatives::isPullModeBSM($MethodHandle* bsm) {
	$init(MethodHandleNatives);
	return false;
}

$MethodType* MethodHandleNatives::findMethodHandleType($Class* rtype, $ClassArray* ptypes) {
	$init(MethodHandleNatives);
	return $MethodType::makeImpl(rtype, ptypes, true);
}

$MemberName* MethodHandleNatives::linkMethod($Class* callerClass, int32_t refKind, $Class* defc, $String* name, Object$* type, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$init($MethodHandleStatics);
	if (!$MethodHandleStatics::TRACE_METHOD_LINKAGE) {
		return linkMethodImpl(callerClass, refKind, defc, name, type, appendixResult);
	}
	return linkMethodTracing(callerClass, refKind, defc, name, type, appendixResult);
}

$MemberName* MethodHandleNatives::linkMethodImpl($Class* callerClass, int32_t refKind, $Class* defc, $String* name, Object$* type, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	try {
		if (refKind == (int8_t)5) {
			$load($MethodHandle);
			if (defc == $MethodHandle::class$) {
				return $Invokers::methodHandleInvokeLinkerMethod(name, $(fixMethodType(callerClass, type)), appendixResult);
			} else {
				$load($VarHandle);
				if (defc == $VarHandle::class$) {
					return varHandleOperationLinkerMethod(name, $(fixMethodType(callerClass, type)), appendixResult);
				}
			}
		}
	} catch ($Error& e) {
		$throw(e);
	} catch ($Throwable& ex) {
		$throwNew($LinkageError, $(ex->getMessage()), ex);
	}
	$throwNew($LinkageError, $$str({"no such method "_s, $($nc(defc)->getName()), "."_s, name, type}));
	$shouldNotReachHere();
}

$MethodType* MethodHandleNatives::fixMethodType($Class* callerClass, Object$* type) {
	$init(MethodHandleNatives);
	$beforeCallerSensitive();
	if ($instanceOf($MethodType, type)) {
		return $cast($MethodType, type);
	} else {
		return $MethodType::fromDescriptor($cast($String, type), $($nc(callerClass)->getClassLoader()));
	}
}

$MemberName* MethodHandleNatives::linkMethodTracing($Class* callerClass, int32_t refKind, $Class* defc, $String* name, Object$* type, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({"linkMethod "_s, $($nc(defc)->getName()), "."_s, name, type, "/"_s}));
	$nc($System::out)->println($$concat(var$0, $($Integer::toHexString(refKind))));
	try {
		$var($MemberName, res, linkMethodImpl(callerClass, refKind, defc, name, type, appendixResult));
		$nc($System::out)->println($$str({"linkMethod => "_s, res, " + "_s, $nc(appendixResult)->get(0)}));
		return res;
	} catch ($Throwable& ex) {
		$nc($System::out)->println($$str({"linkMethod => throw "_s, ex}));
		$throw(ex);
	}
	$shouldNotReachHere();
}

$MemberName* MethodHandleNatives::varHandleOperationLinkerMethod($String* name, $MethodType* mtype, $ObjectArray* appendixResult) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, sigType, $nc(mtype)->basicType());
	$VarHandle$AccessMode* ak = nullptr;
	try {
		ak = $VarHandle$AccessMode::valueFromMethodName(name);
	} catch ($IllegalArgumentException& e) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(e))));
	}
	$var($MethodType, var$0, mtype);
	int32_t var$1 = $nc(ak)->at->ordinal();
	$var($VarHandle$AccessDescriptor, ad, $new($VarHandle$AccessDescriptor, var$0, var$1, ak->ordinal()));
	$nc(appendixResult)->set(0, ad);
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::VAR_HANDLE_GUARDS) {
		$Class* guardReturnType = $cast($Class, $nc(sigType)->returnType());
		if ($nc(ak)->at->isMonomorphicInReturnType) {
			if (ak->at->returnType != $cast($Class, mtype->returnType())) {
				$throw($(newNoSuchMethodErrorOnVarHandle(name, mtype)));
			}
			guardReturnType = ak->at->returnType;
		}
		$var($ClassArray, guardParams, $new($ClassArray, sigType->parameterCount() + 2));
		$load($VarHandle);
		guardParams->set(0, $VarHandle::class$);
		for (int32_t i = 0; i < sigType->parameterCount(); ++i) {
			guardParams->set(i + 1, $($cast($Class, sigType->parameterType(i))));
		}
		$load($VarHandle$AccessDescriptor);
		guardParams->set(guardParams->length - 1, $VarHandle$AccessDescriptor::class$);
		$var($MethodType, guardType, $MethodType::makeImpl(guardReturnType, guardParams, true));
		$load($VarHandleGuards);
		$var($MemberName, linker, $new($MemberName, $VarHandleGuards::class$, $(getVarHandleGuardMethodName(guardType)), guardType, (int8_t)6));
		$assign(linker, $nc($($MemberName::getFactory()))->resolveOrNull((int8_t)6, linker, $VarHandleGuards::class$, -1));
		if (linker != nullptr) {
			return linker;
		}
	}
	return $Invokers::varHandleInvokeLinkerMethod(mtype);
}

$String* MethodHandleNatives::getVarHandleGuardMethodName($MethodType* guardType) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($String, prefix, "guard_"_s);
	int32_t var$0 = prefix->length();
	$var($StringBuilder, sb, $new($StringBuilder, var$0 + $nc(guardType)->parameterCount()));
	sb->append(prefix);
	for (int32_t i = 1; i < $nc(guardType)->parameterCount() - 1; ++i) {
		$Class* pt = $cast($Class, guardType->parameterType(i));
		sb->append(getCharType(pt));
	}
	sb->append(u'_')->append(getCharType($($cast($Class, $nc(guardType)->returnType()))));
	return sb->toString();
}

char16_t MethodHandleNatives::getCharType($Class* pt) {
	$init(MethodHandleNatives);
	return $nc($($Wrapper::forBasicType(pt)))->basicTypeChar();
}

$NoSuchMethodError* MethodHandleNatives::newNoSuchMethodErrorOnVarHandle($String* name, $MethodType* mtype) {
	$init(MethodHandleNatives);
	return $new($NoSuchMethodError, $$str({"VarHandle."_s, name, mtype}));
}

$MethodHandle* MethodHandleNatives::linkMethodHandleConstant($Class* callerClass, int32_t refKind, $Class* defc, $String* name, Object$* type) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	try {
		$init($MethodHandles$Lookup);
		$var($MethodHandles$Lookup, lookup, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->in(callerClass));
		if (!MethodHandleNatives::$assertionsDisabled && !(refKindIsValid(refKind))) {
			$throwNew($AssertionError);
		}
		return $nc(lookup)->linkMethodHandleConstant((int8_t)refKind, defc, name, type);
	} catch ($ReflectiveOperationException& ex) {
		$throw($(mapLookupExceptionToError(ex)));
	}
	$shouldNotReachHere();
}

$LinkageError* MethodHandleNatives::mapLookupExceptionToError($ReflectiveOperationException* ex) {
	$init(MethodHandleNatives);
	$useLocalCurrentObjectStackCache();
	$var($LinkageError, err, nullptr);
	if ($instanceOf($IllegalAccessException, ex)) {
		$var($Throwable, cause, $nc(ex)->getCause());
		if ($instanceOf($AbstractMethodError, cause)) {
			return $cast($AbstractMethodError, cause);
		} else {
			$assign(err, $new($IllegalAccessError, $(ex->getMessage())));
		}
	} else if ($instanceOf($NoSuchMethodException, ex)) {
		$assign(err, $new($NoSuchMethodError, $($nc(ex)->getMessage())));
	} else if ($instanceOf($NoSuchFieldException, ex)) {
		$assign(err, $new($NoSuchFieldError, $($nc(ex)->getMessage())));
	} else {
		$assign(err, $new($IncompatibleClassChangeError));
	}
	return $cast($LinkageError, initCauseFrom(err, ex));
}

$Error* MethodHandleNatives::initCauseFrom($Error* err, $Exception* ex) {
	$init(MethodHandleNatives);
	$var($Throwable, th, $nc(ex)->getCause());
	$Class* Eclass = $nc($of(err))->getClass();
	if ($nc(Eclass)->isInstance(th)) {
		return $cast($Error, Eclass->cast(th));
	}
	err->initCause(th == nullptr ? static_cast<$Throwable*>(ex) : th);
	return err;
}

bool MethodHandleNatives::isCallerSensitive($MemberName* mem) {
	$init(MethodHandleNatives);
	if (!$nc(mem)->isInvocable()) {
		return false;
	}
	bool var$0 = $nc(mem)->isCallerSensitive();
	return var$0 || canBeCalledVirtual(mem);
}

bool MethodHandleNatives::canBeCalledVirtual($MemberName* mem) {
	$init(MethodHandleNatives);
	if (!MethodHandleNatives::$assertionsDisabled && !($nc(mem)->isInvocable())) {
		$throwNew($AssertionError);
	}
	bool var$0 = $nc($($nc(mem)->getName()))->equals("getContextClassLoader"_s);
	return var$0 && canBeCalledVirtual(mem, $Thread::class$);
}

bool MethodHandleNatives::canBeCalledVirtual($MemberName* symbolicRef, $Class* definingClass) {
	$init(MethodHandleNatives);
	$Class* symbolicRefClass = $nc(symbolicRef)->getDeclaringClass();
	if (symbolicRefClass == definingClass) {
		return true;
	}
	bool var$0 = symbolicRef->isStatic();
	if (var$0 || symbolicRef->isPrivate()) {
		return false;
	}
	bool var$1 = $nc(definingClass)->isAssignableFrom(symbolicRefClass);
	return (var$1 || $nc(symbolicRefClass)->isInterface());
}

$Object* MethodHandleNatives::classData($Class* c) {
	$init(MethodHandleNatives);
	$init($MethodHandleStatics);
	$nc($MethodHandleStatics::UNSAFE)->ensureClassInitialized(c);
	return $of($nc(MethodHandleNatives::JLA)->classData(c));
}

void clinit$MethodHandleNatives($Class* class$) {
	int32_t HR_MASK = (((((1 << (int8_t)1) | (1 << (int8_t)3)) | (1 << (int8_t)5)) | (1 << (int8_t)7)) | (1 << (int8_t)9));
	MethodHandleNatives::$assertionsDisabled = !MethodHandleNatives::class$->desiredAssertionStatus();
	{
		MethodHandleNatives::registerNatives();
	}
	{
		int32_t HR_MASK = (((((1 << (int8_t)1) | (1 << (int8_t)3)) | (1 << (int8_t)5)) | (1 << (int8_t)7)) | (1 << (int8_t)9));
		for (int8_t refKind = (int8_t)((int8_t)0 + 1); refKind < (int8_t)10; ++refKind) {
			if (!MethodHandleNatives::$assertionsDisabled && !(MethodHandleNatives::refKindHasReceiver(refKind) == (((int32_t)(($sl(1, refKind)) & (uint32_t)HR_MASK)) != 0))) {
				$throwNew($AssertionError, (int32_t)refKind);
			}
		}
	}
	{
		if (!MethodHandleNatives::$assertionsDisabled && !(MethodHandleNatives::verifyConstants())) {
			$throwNew($AssertionError);
		}
	}
	$assignStatic(MethodHandleNatives::JLA, $SharedSecrets::getJavaLangAccess());
}

MethodHandleNatives::MethodHandleNatives() {
}

$Class* MethodHandleNatives::load$($String* name, bool initialize) {
	$loadClass(MethodHandleNatives, name, initialize, &_MethodHandleNatives_ClassInfo_, clinit$MethodHandleNatives, allocate$MethodHandleNatives);
	return class$;
}

$Class* MethodHandleNatives::class$ = nullptr;

		} // invoke
	} // lang
} // java