#include <java/lang/invoke/MethodHandleImpl$BindCaller.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassValue.h>
#include <java/lang/Error.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl$BindCaller$1.h>
#include <java/lang/invoke/MethodHandleImpl$WrappedMember.h>
#include <java/lang/invoke/MethodHandleImpl.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup$ClassDefiner.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/ProtectionDomain.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jcpp.h>

#undef IMPL_LOOKUP
#undef INJECTED_INVOKER_TEMPLATE
#undef INVOKER_MT
#undef THIS_CLASS
#undef TYPE

using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassValue = ::java::lang::ClassValue;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $SecurityException = ::java::lang::SecurityException;
using $LambdaForm = ::java::lang::invoke::LambdaForm;
using $MemberName = ::java::lang::invoke::MemberName;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl = ::java::lang::invoke::MethodHandleImpl;
using $MethodHandleImpl$BindCaller$1 = ::java::lang::invoke::MethodHandleImpl$BindCaller$1;
using $MethodHandleImpl$WrappedMember = ::java::lang::invoke::MethodHandleImpl$WrappedMember;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodHandles$Lookup$ClassDefiner = ::java::lang::invoke::MethodHandles$Lookup$ClassDefiner;
using $MethodType = ::java::lang::invoke::MethodType;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Reflection = ::jdk::internal::reflect::Reflection;

namespace java {
	namespace lang {
		namespace invoke {

$CompoundAttribute _MethodHandleImpl$BindCaller_MethodAnnotations_checkCallerClass2[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{"Ljdk/internal/vm/annotation/ForceInline;", nullptr},
	{}
};

$FieldInfo _MethodHandleImpl$BindCaller_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodHandleImpl$BindCaller, $assertionsDisabled)},
	{"INVOKER_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC, $staticField(MethodHandleImpl$BindCaller, INVOKER_MT)},
	{"CV_makeInjectedInvoker", "Ljava/lang/ClassValue;", "Ljava/lang/ClassValue<Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC, $staticField(MethodHandleImpl$BindCaller, CV_makeInjectedInvoker)},
	{"MH_checkCallerClass", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodHandleImpl$BindCaller, MH_checkCallerClass)},
	{"INJECTED_INVOKER_TEMPLATE", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MethodHandleImpl$BindCaller, INJECTED_INVOKER_TEMPLATE)},
	{}
};

$MethodInfo _MethodHandleImpl$BindCaller_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(MethodHandleImpl$BindCaller, init$, void)},
	{"bindCaller", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(MethodHandleImpl$BindCaller, bindCaller, $MethodHandle*, $MethodHandle*, $Class*)},
	{"checkCallerClass", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl$BindCaller, checkCallerClass, bool, $Class*), nullptr, nullptr, _MethodHandleImpl$BindCaller_MethodAnnotations_checkCallerClass2},
	{"checkInjectedInvoker", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl$BindCaller, checkInjectedInvoker, bool, $Class*, $Class*)},
	{"generateInvokerTemplate", "()[B", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl$BindCaller, generateInvokerTemplate, $bytes*)},
	{"makeInjectedInvoker", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl$BindCaller, makeInjectedInvoker, $MethodHandle*, $Class*)},
	{"prepareForInvoker", "(Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl$BindCaller, prepareForInvoker, $MethodHandle*, $MethodHandle*)},
	{"restoreToType", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(MethodHandleImpl$BindCaller, restoreToType, $MethodHandle*, $MethodHandle*, $MethodHandle*, $Class*)},
	{}
};

$InnerClassInfo _MethodHandleImpl$BindCaller_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandleImpl$BindCaller", "java.lang.invoke.MethodHandleImpl", "BindCaller", $PRIVATE | $STATIC},
	{"java.lang.invoke.MethodHandleImpl$BindCaller$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MethodHandleImpl$BindCaller_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.invoke.MethodHandleImpl$BindCaller",
	"java.lang.Object",
	nullptr,
	_MethodHandleImpl$BindCaller_FieldInfo_,
	_MethodHandleImpl$BindCaller_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandleImpl$BindCaller_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandleImpl"
};

$Object* allocate$MethodHandleImpl$BindCaller($Class* clazz) {
	return $of($alloc(MethodHandleImpl$BindCaller));
}

bool MethodHandleImpl$BindCaller::$assertionsDisabled = false;
$MethodType* MethodHandleImpl$BindCaller::INVOKER_MT = nullptr;
$ClassValue* MethodHandleImpl$BindCaller::CV_makeInjectedInvoker = nullptr;
$MethodHandle* MethodHandleImpl$BindCaller::MH_checkCallerClass = nullptr;
$bytes* MethodHandleImpl$BindCaller::INJECTED_INVOKER_TEMPLATE = nullptr;

void MethodHandleImpl$BindCaller::init$() {
}

$MethodHandle* MethodHandleImpl$BindCaller::bindCaller($MethodHandle* mh, $Class* hostClass) {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	bool var$0 = hostClass == nullptr;
	if (!var$0) {
		bool var$2 = $nc(hostClass)->isArray();
		bool var$1 = var$2 || $nc(hostClass)->isPrimitive();
		var$0 = (var$1 || $nc($($nc(hostClass)->getName()))->startsWith("java.lang.invoke."_s));
	}
	if (var$0) {
		$throwNew($InternalError);
	}
	$var($MethodHandle, vamh, prepareForInvoker(mh));
	$var($MethodHandle, bccInvoker, $cast($MethodHandle, $nc(MethodHandleImpl$BindCaller::CV_makeInjectedInvoker)->get(hostClass)));
	return restoreToType($($nc(bccInvoker)->bindTo(vamh)), mh, hostClass);
}

$MethodHandle* MethodHandleImpl$BindCaller::makeInjectedInvoker($Class* targetClass) {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, name, $str({$($nc(targetClass)->getName()), "$$InjectedInvoker"_s}));
		if (targetClass->isHidden()) {
			$assign(name, $nc(name)->replace(u'/', u'_'));
		}
		$Class* invokerClass = $nc($($$new($MethodHandles$Lookup, targetClass)->makeHiddenClassDefiner(name, MethodHandleImpl$BindCaller::INJECTED_INVOKER_TEMPLATE)))->defineClass(true);
		if (!MethodHandleImpl$BindCaller::$assertionsDisabled && !checkInjectedInvoker(targetClass, invokerClass)) {
			$throwNew($AssertionError);
		}
		return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(invokerClass, "invoke_V"_s, MethodHandleImpl$BindCaller::INVOKER_MT);
	} catch ($ReflectiveOperationException& ex) {
		$throw($($MethodHandleStatics::uncaughtException(ex)));
	}
	$shouldNotReachHere();
}

$MethodHandle* MethodHandleImpl$BindCaller::prepareForInvoker($MethodHandle* mh$renamed) {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, mh, mh$renamed);
	$assign(mh, $nc(mh)->asFixedArity());
	$var($MethodType, mt, mh->type());
	int32_t arity = $nc(mt)->parameterCount();
	$var($MethodHandle, vamh, mh->asType($(mt->generic())));
	$nc($($nc(vamh)->internalForm()))->compileToBytecode();
	$load($ObjectArray);
	$assign(vamh, vamh->asSpreader($getClass($ObjectArray), arity));
	$nc($(vamh->internalForm()))->compileToBytecode();
	return vamh;
}

$MethodHandle* MethodHandleImpl$BindCaller::restoreToType($MethodHandle* vamh, $MethodHandle* original, $Class* hostClass) {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $nc(original)->type());
	$load($ObjectArray);
	$var($MethodHandle, mh, $nc(vamh)->asCollector($getClass($ObjectArray), $nc(type)->parameterCount()));
	$var($MemberName, member, original->internalMemberName());
	$assign(mh, $nc(mh)->asType(type));
	$assign(mh, $new($MethodHandleImpl$WrappedMember, mh, type, member, original->isInvokeSpecial(), hostClass));
	return mh;
}

bool MethodHandleImpl$BindCaller::checkInjectedInvoker($Class* hostClass, $Class* invokerClass) {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	bool var$0 = !MethodHandleImpl$BindCaller::$assertionsDisabled;
	if (var$0) {
		var$0 = !($nc(hostClass)->getClassLoader() == $nc(invokerClass)->getClassLoader());
	}
	if (var$0) {
		$throwNew($AssertionError, $of($$str({$(hostClass->getName()), " (CL)"_s})));
	}
	try {
		bool var$1 = !MethodHandleImpl$BindCaller::$assertionsDisabled;
		if (var$1) {
			var$1 = !($nc(hostClass)->getProtectionDomain() == $nc(invokerClass)->getProtectionDomain());
		}
		if (var$1) {
			$throwNew($AssertionError, $of($$str({$(hostClass->getName()), " (PD)"_s})));
		}
	} catch ($SecurityException& ex) {
	}
	try {
		$init($MethodHandles$Lookup);
		$var($MethodHandle, invoker, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(invokerClass, "invoke_V"_s, MethodHandleImpl$BindCaller::INVOKER_MT));
		$var($MethodHandle, vamh, prepareForInvoker(MethodHandleImpl$BindCaller::MH_checkCallerClass));
		return $booleanValue($nc(invoker)->invoke($$new($ObjectArray, {$of(vamh), $of($$new($ObjectArray, {$of(invokerClass)}))})));
	} catch ($Throwable& ex) {
		$throwNew($InternalError, $cast($Throwable, ex));
	}
	$shouldNotReachHere();
}

bool MethodHandleImpl$BindCaller::checkCallerClass($Class* expected) {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	$Class* actual = $Reflection::getCallerClass();
	if (actual != expected) {
		$var($String, var$0, $$str({"found "_s, $($nc(actual)->getName()), ", expected "_s}));
		$throwNew($InternalError, $$concat(var$0, $($nc(expected)->getName())));
	}
	return true;
}

$bytes* MethodHandleImpl$BindCaller::generateInvokerTemplate() {
	$init(MethodHandleImpl$BindCaller);
	$useLocalCurrentObjectStackCache();
	$var($ClassWriter, cw, $new($ClassWriter, 0));
	cw->visit(52, 2 | 32, "InjectedInvoker"_s, nullptr, "java/lang/Object"_s, nullptr);
	$var($MethodVisitor, mv, cw->visitMethod(8, "invoke_V"_s, "(Ljava/lang/invoke/MethodHandle;[Ljava/lang/Object;)Ljava/lang/Object;"_s, nullptr, nullptr));
	$nc(mv)->visitCode();
	mv->visitVarInsn(25, 0);
	mv->visitVarInsn(25, 1);
	mv->visitMethodInsn(182, "java/lang/invoke/MethodHandle"_s, "invokeExact"_s, "([Ljava/lang/Object;)Ljava/lang/Object;"_s, false);
	mv->visitInsn(176);
	mv->visitMaxs(2, 2);
	mv->visitEnd();
	cw->visitEnd();
	return cw->toByteArray();
}

void clinit$MethodHandleImpl$BindCaller($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($MethodHandleImpl);
	MethodHandleImpl$BindCaller::$assertionsDisabled = !$MethodHandleImpl::class$->desiredAssertionStatus();
	$load($MethodHandle);
	$load($ObjectArray);
	$assignStatic(MethodHandleImpl$BindCaller::INVOKER_MT, $MethodType::methodType($Object::class$, $MethodHandle::class$, $$new($ClassArray, {$getClass($ObjectArray)})));
	$assignStatic(MethodHandleImpl$BindCaller::CV_makeInjectedInvoker, $new($MethodHandleImpl$BindCaller$1));
	{
		$Class* THIS_CLASS = MethodHandleImpl$BindCaller::class$;
		if (!MethodHandleImpl$BindCaller::$assertionsDisabled && !(MethodHandleImpl$BindCaller::checkCallerClass(THIS_CLASS))) {
			$throwNew($AssertionError);
		}
		try {
			$init($MethodHandles$Lookup);
			$init($Boolean);
			$assignStatic(MethodHandleImpl$BindCaller::MH_checkCallerClass, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(THIS_CLASS, "checkCallerClass"_s, $($MethodType::methodType($Boolean::TYPE, $Class::class$))));
			if (!MethodHandleImpl$BindCaller::$assertionsDisabled && !($booleanValue($nc(MethodHandleImpl$BindCaller::MH_checkCallerClass)->invokeExact($$new($ObjectArray, {$of(THIS_CLASS)}))))) {
				$throwNew($AssertionError);
			}
		} catch ($Throwable& ex) {
			$throwNew($InternalError, $cast($Throwable, ex));
		}
	}
	$assignStatic(MethodHandleImpl$BindCaller::INJECTED_INVOKER_TEMPLATE, MethodHandleImpl$BindCaller::generateInvokerTemplate());
}

MethodHandleImpl$BindCaller::MethodHandleImpl$BindCaller() {
}

$Class* MethodHandleImpl$BindCaller::load$($String* name, bool initialize) {
	$loadClass(MethodHandleImpl$BindCaller, name, initialize, &_MethodHandleImpl$BindCaller_ClassInfo_, clinit$MethodHandleImpl$BindCaller, allocate$MethodHandleImpl$BindCaller);
	return class$;
}

$Class* MethodHandleImpl$BindCaller::class$ = nullptr;

		} // invoke
	} // lang
} // java