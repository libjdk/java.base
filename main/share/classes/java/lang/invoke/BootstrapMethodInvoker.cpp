#include <java/lang/invoke/BootstrapMethodInvoker.h>

#include <java/lang/AssertionError.h>
#include <java/lang/BootstrapMethodError.h>
#include <java/lang/Error.h>
#include <java/lang/invoke/BootstrapCallInfo.h>
#include <java/lang/invoke/BootstrapMethodInvoker$PullAdapter.h>
#include <java/lang/invoke/BootstrapMethodInvoker$PushAdapter.h>
#include <java/lang/invoke/BootstrapMethodInvoker$VM_BSCI.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/Invokers.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleNatives.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#undef IMPL_LOOKUP
#undef LMF_ALT_MT
#undef LMF_CONDY_MT
#undef LMF_INDY_MT
#undef MAX_MH_ARITY
#undef MAX_SAFE_SIZE
#undef NON_SPREAD_ARG_COUNT
#undef SCF_MT
#undef TRACE_METHOD_LINKAGE

using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $BootstrapMethodError = ::java::lang::BootstrapMethodError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BootstrapCallInfo = ::java::lang::invoke::BootstrapCallInfo;
using $BootstrapMethodInvoker$PullAdapter = ::java::lang::invoke::BootstrapMethodInvoker$PullAdapter;
using $BootstrapMethodInvoker$PushAdapter = ::java::lang::invoke::BootstrapMethodInvoker$PushAdapter;
using $BootstrapMethodInvoker$VM_BSCI = ::java::lang::invoke::BootstrapMethodInvoker$VM_BSCI;
using $CallSite = ::java::lang::invoke::CallSite;
using $Invokers = ::java::lang::invoke::Invokers;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleNatives = ::java::lang::invoke::MethodHandleNatives;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Arrays = ::java::util::Arrays;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _BootstrapMethodInvoker_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BootstrapMethodInvoker, $assertionsDisabled)},
	{"LMF_INDY_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootstrapMethodInvoker, LMF_INDY_MT)},
	{"LMF_ALT_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootstrapMethodInvoker, LMF_ALT_MT)},
	{"LMF_CONDY_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootstrapMethodInvoker, LMF_CONDY_MT)},
	{"SCF_MT", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BootstrapMethodInvoker, SCF_MT)},
	{}
};

$MethodInfo _BootstrapMethodInvoker_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(BootstrapMethodInvoker, init$, void)},
	{"invoke", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Class<TT;>;Ljava/lang/invoke/MethodHandle;Ljava/lang/String;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Class<*>;)TT;", $STATIC, $staticMethod(BootstrapMethodInvoker, invoke, $Object*, $Class*, $MethodHandle*, $String*, Object$*, Object$*, $Class*)},
	{"invokeWithManyArguments", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/String;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, invokeWithManyArguments, $Object*, $MethodHandle*, $MethodHandles$Lookup*, $String*, Object$*, $ObjectArray*), "java.lang.Throwable"},
	{"isLambdaMetafactoryAltMetafactoryBSM", "(Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, isLambdaMetafactoryAltMetafactoryBSM, bool, $MethodType*)},
	{"isLambdaMetafactoryCondyBSM", "(Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, isLambdaMetafactoryCondyBSM, bool, $MethodType*)},
	{"isLambdaMetafactoryIndyBSM", "(Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, isLambdaMetafactoryIndyBSM, bool, $MethodType*)},
	{"isStringConcatFactoryBSM", "(Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, isStringConcatFactoryBSM, bool, $MethodType*)},
	{"maybeReBox", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, maybeReBox, $Object*, Object$*)},
	{"maybeReBoxElements", "([Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(BootstrapMethodInvoker, maybeReBoxElements, void, $ObjectArray*)},
	{"pushMePullYou", "(Ljava/lang/invoke/MethodHandle;Z)Ljava/lang/invoke/MethodHandle;", nullptr, $STATIC, $staticMethod(BootstrapMethodInvoker, pushMePullYou, $MethodHandle*, $MethodHandle*, bool)},
	{"widenAndCast", "(Ljava/lang/Object;Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Object;Ljava/lang/Class<TT;>;)TT;", $STATIC, $staticMethod(BootstrapMethodInvoker, widenAndCast, $Object*, Object$*, $Class*), "java.lang.Throwable"},
	{}
};

$InnerClassInfo _BootstrapMethodInvoker_InnerClassesInfo_[] = {
	{"java.lang.invoke.BootstrapMethodInvoker$PullAdapter", "java.lang.invoke.BootstrapMethodInvoker", "PullAdapter", $STATIC | $FINAL},
	{"java.lang.invoke.BootstrapMethodInvoker$PushAdapter", "java.lang.invoke.BootstrapMethodInvoker", "PushAdapter", $STATIC | $FINAL},
	{"java.lang.invoke.BootstrapMethodInvoker$VM_BSCI", "java.lang.invoke.BootstrapMethodInvoker", "VM_BSCI", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _BootstrapMethodInvoker_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.invoke.BootstrapMethodInvoker",
	"java.lang.Object",
	nullptr,
	_BootstrapMethodInvoker_FieldInfo_,
	_BootstrapMethodInvoker_MethodInfo_,
	nullptr,
	nullptr,
	_BootstrapMethodInvoker_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.BootstrapMethodInvoker$PullAdapter,java.lang.invoke.BootstrapMethodInvoker$PushAdapter,java.lang.invoke.BootstrapMethodInvoker$VM_BSCI"
};

$Object* allocate$BootstrapMethodInvoker($Class* clazz) {
	return $of($alloc(BootstrapMethodInvoker));
}

bool BootstrapMethodInvoker::$assertionsDisabled = false;
$MethodType* BootstrapMethodInvoker::LMF_INDY_MT = nullptr;
$MethodType* BootstrapMethodInvoker::LMF_ALT_MT = nullptr;
$MethodType* BootstrapMethodInvoker::LMF_CONDY_MT = nullptr;
$MethodType* BootstrapMethodInvoker::SCF_MT = nullptr;

void BootstrapMethodInvoker::init$() {
}

$Object* BootstrapMethodInvoker::invoke($Class* resultType, $MethodHandle* bootstrapMethod$renamed, $String* name, Object$* type, Object$* info$renamed, $Class* callerClass) {
	$init(BootstrapMethodInvoker);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, bootstrapMethod, bootstrapMethod$renamed);
	$var($Object, info, info$renamed);
	$init($MethodHandles$Lookup);
	$var($MethodHandles$Lookup, caller, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->in(callerClass));
	$var($Object, result, nullptr);
	bool pullMode = $MethodHandleNatives::isPullModeBSM(bootstrapMethod);
	bool vmIsPushing = !$MethodHandleNatives::staticArgumentsPulled(info);
	$var($MethodHandle, pullModeBSM, nullptr);
	if (vmIsPushing) {
		$assign(pullModeBSM, nullptr);
		if (pullMode) {
			$assign(bootstrapMethod, pushMePullYou(bootstrapMethod, true));
		}
	} else {
		$assign(pullModeBSM, pullMode ? bootstrapMethod : pushMePullYou(bootstrapMethod, false));
		$assign(bootstrapMethod, nullptr);
	}
	try {
		if (info == nullptr) {
			{
				$Class* c = nullptr;
				bool var$0 = $instanceOf($Class, type);
				if (var$0) {
					c = $cast($Class, type);
					var$0 = true;
				}
				if (var$0) {
					$assign(result, $nc(bootstrapMethod)->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c)})));
				} else {
					$assign(result, $nc(bootstrapMethod)->invoke($$new($ObjectArray, {$of(caller), $of(name), $cast($MethodType, type)})));
				}
			}
		} else if (!$nc($of(info))->getClass()->isArray()) {
			if (isStringConcatFactoryBSM($($nc(bootstrapMethod)->type()))) {
				$assign(result, $cast($CallSite, $nc(bootstrapMethod)->invokeExact($$new($ObjectArray, {$of(caller), $of(name), $cast($MethodType, type), $cast($String, info), $of($$new($ObjectArray, 0))}))));
			} else {
				$assign(info, maybeReBox(info));
				{
					$Class* c = nullptr;
					bool var$1 = $instanceOf($Class, type);
					if (var$1) {
						c = $cast($Class, type);
						var$1 = true;
					}
					if (var$1) {
						$assign(result, $nc(bootstrapMethod)->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), info})));
					} else {
						$assign(result, $nc(bootstrapMethod)->invoke($$new($ObjectArray, {$of(caller), $of(name), $cast($MethodType, type), info})));
					}
				}
			}
		} else {
			$load($ints);
			if ($of(info)->getClass() == $getClass($ints)) {
				$var($BootstrapCallInfo, bsci, $new($BootstrapMethodInvoker$VM_BSCI, bootstrapMethod, name, type, caller, $cast($ints, info)));
				$assign(result, $nc(pullModeBSM)->invoke($$new($ObjectArray, {$of(caller), $of(bsci)})));
			} else {
				$var($ObjectArray, argv, $cast($ObjectArray, info));
				$var($MethodType, bsmType, $nc(bootstrapMethod)->type());
				if (isLambdaMetafactoryIndyBSM(bsmType) && argv->length == 3) {
					$assign(result, $cast($CallSite, bootstrapMethod->invokeExact($$new($ObjectArray, {$of(caller), $of(name), $cast($MethodType, type), $cast($MethodType, argv->get(0)), $cast($MethodHandle, argv->get(1)), $cast($MethodType, argv->get(2))}))));
				} else if (isLambdaMetafactoryCondyBSM(bsmType) && argv->length == 3) {
					$assign(result, bootstrapMethod->invokeExact($$new($ObjectArray, {$of(caller), $of(name), $cast($Class, type), $cast($MethodType, argv->get(0)), $cast($MethodHandle, argv->get(1)), $cast($MethodType, argv->get(2))})));
				} else if (isStringConcatFactoryBSM(bsmType) && argv->length >= 1) {
					$var($String, recipe, $cast($String, argv->get(0)));
					$var($ObjectArray, shiftedArgs, $Arrays::copyOfRange(argv, 1, argv->length));
					maybeReBoxElements(shiftedArgs);
					$assign(result, $cast($CallSite, bootstrapMethod->invokeExact($$new($ObjectArray, {$of(caller), $of(name), $cast($MethodType, type), $of(recipe), $of(shiftedArgs)}))));
				} else if (isLambdaMetafactoryAltMetafactoryBSM(bsmType)) {
					maybeReBoxElements(argv);
					$assign(result, $cast($CallSite, bootstrapMethod->invokeExact($$new($ObjectArray, {$of(caller), $of(name), $cast($MethodType, type), $of(argv)}))));
				} else {
					maybeReBoxElements(argv);
					{
						$Class* c = nullptr;
						bool var$2 = $instanceOf($Class, type);
						if (var$2) {
							c = $cast($Class, type);
							var$2 = true;
						}
						if (var$2) {

							$var($Object, var$3, nullptr)
							switch (argv->length) {
							case 0:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c)})));
									break;
								}
							case 1:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), argv->get(0)})));
									break;
								}
							case 2:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), argv->get(0), argv->get(1)})));
									break;
								}
							case 3:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), argv->get(0), argv->get(1), argv->get(2)})));
									break;
								}
							case 4:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), argv->get(0), argv->get(1), argv->get(2), argv->get(3)})));
									break;
								}
							case 5:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), argv->get(0), argv->get(1), argv->get(2), argv->get(3), argv->get(4)})));
									break;
								}
							case 6:
								{
									$assign(var$3, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(c), argv->get(0), argv->get(1), argv->get(2), argv->get(3), argv->get(4), argv->get(5)})));
									break;
								}
							default:
								{
									$assign(var$3, invokeWithManyArguments(bootstrapMethod, caller, name, type, argv));
									break;
								}
							}
							$assign(result, var$3);
						} else {
							$var($MethodType, mt, $cast($MethodType, type));

							$var($Object, var$4, nullptr)
							switch (argv->length) {
							case 0:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt)})));
									break;
								}
							case 1:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt), argv->get(0)})));
									break;
								}
							case 2:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt), argv->get(0), argv->get(1)})));
									break;
								}
							case 3:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt), argv->get(0), argv->get(1), argv->get(2)})));
									break;
								}
							case 4:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt), argv->get(0), argv->get(1), argv->get(2), argv->get(3)})));
									break;
								}
							case 5:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt), argv->get(0), argv->get(1), argv->get(2), argv->get(3), argv->get(4)})));
									break;
								}
							case 6:
								{
									$assign(var$4, bootstrapMethod->invoke($$new($ObjectArray, {$of(caller), $of(name), $of(mt), argv->get(0), argv->get(1), argv->get(2), argv->get(3), argv->get(4), argv->get(5)})));
									break;
								}
							default:
								{
									$assign(var$4, invokeWithManyArguments(bootstrapMethod, caller, name, type, argv));
									break;
								}
							}
							$assign(result, var$4);
						}
					}
				}
			}
		}
		return $of(widenAndCast(result, resultType));
	} catch ($Error& e) {
		$throw(e);
	} catch ($Throwable& ex) {
		$throwNew($BootstrapMethodError, "bootstrap method initialization exception"_s, ex);
	}
	$shouldNotReachHere();
}

$Object* BootstrapMethodInvoker::widenAndCast(Object$* result$renamed, $Class* resultType) {
	$init(BootstrapMethodInvoker);
	$useLocalCurrentObjectStackCache();
	$var($Object, result, result$renamed);
	if (!$nc(resultType)->isPrimitive()) {
		return $of(resultType->cast(result));
	}
	$Class* wrapperType = $Wrapper::asWrapperType(resultType);
	if ($nc(wrapperType)->isInstance(result)) {
		$var($Object, wrapper, result);
		return $of(wrapper);
	}
	$var($MethodHandle, funnel, $MethodHandles::identity(resultType));
	$assign(result, $nc(funnel)->invoke($$new($ObjectArray, {result})));
	return $of($nc(wrapperType)->cast(result));
}

$Object* BootstrapMethodInvoker::invokeWithManyArguments($MethodHandle* bootstrapMethod, $MethodHandles$Lookup* caller, $String* name, Object$* type, $ObjectArray* argv) {
	$init(BootstrapMethodInvoker);
	$useLocalCurrentObjectStackCache();
	int32_t NON_SPREAD_ARG_COUNT = 3;
	int32_t MAX_SAFE_SIZE = $MethodType::MAX_MH_ARITY / 2 - NON_SPREAD_ARG_COUNT;
	if ($nc(argv)->length >= MAX_SAFE_SIZE) {
		$var($ObjectArray, newargv, $new($ObjectArray, NON_SPREAD_ARG_COUNT + argv->length));
		newargv->set(0, caller);
		newargv->set(1, name);
		newargv->set(2, type);
		$System::arraycopy(argv, 0, newargv, NON_SPREAD_ARG_COUNT, argv->length);
		return $of($nc(bootstrapMethod)->invokeWithArguments(newargv));
	} else {
		$var($MethodType, invocationType, $MethodType::genericMethodType(NON_SPREAD_ARG_COUNT + argv->length));
		$var($MethodHandle, typedBSM, $nc(bootstrapMethod)->asType(invocationType));
		$var($MethodHandle, spreader, $nc($($nc(invocationType)->invokers()))->spreadInvoker(NON_SPREAD_ARG_COUNT));
		return $of($nc(spreader)->invokeExact($$new($ObjectArray, {$of(typedBSM), $of(caller), $of(name), type, $of(argv)})));
	}
}

bool BootstrapMethodInvoker::isStringConcatFactoryBSM($MethodType* bsmType) {
	$init(BootstrapMethodInvoker);
	return bsmType == BootstrapMethodInvoker::SCF_MT;
}

bool BootstrapMethodInvoker::isLambdaMetafactoryCondyBSM($MethodType* bsmType) {
	$init(BootstrapMethodInvoker);
	return bsmType == BootstrapMethodInvoker::LMF_CONDY_MT;
}

bool BootstrapMethodInvoker::isLambdaMetafactoryIndyBSM($MethodType* bsmType) {
	$init(BootstrapMethodInvoker);
	return bsmType == BootstrapMethodInvoker::LMF_INDY_MT;
}

bool BootstrapMethodInvoker::isLambdaMetafactoryAltMetafactoryBSM($MethodType* bsmType) {
	$init(BootstrapMethodInvoker);
	return bsmType == BootstrapMethodInvoker::LMF_ALT_MT;
}

$Object* BootstrapMethodInvoker::maybeReBox(Object$* x$renamed) {
	$init(BootstrapMethodInvoker);
	$var($Object, x, x$renamed);
	if ($instanceOf($Integer, x)) {
		int32_t xi = $nc(($cast($Integer, x)))->intValue();
		if (xi == (int8_t)xi) {
			$assign(x, $Integer::valueOf(xi));
		}
	}
	return $of(x);
}

void BootstrapMethodInvoker::maybeReBoxElements($ObjectArray* xa) {
	$init(BootstrapMethodInvoker);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(xa)->length; ++i) {
		xa->set(i, $(maybeReBox(xa->get(i))));
	}
}

$MethodHandle* BootstrapMethodInvoker::pushMePullYou($MethodHandle* bsm, bool goToPushMode) {
	$init(BootstrapMethodInvoker);
	$useLocalCurrentObjectStackCache();
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::TRACE_METHOD_LINKAGE) {
		$nc($System::out)->println($$str({"converting BSM of type "_s, $($nc(bsm)->type()), " to "_s, (goToPushMode ? "push mode"_s : "pull mode"_s)}));
	}
	if (!BootstrapMethodInvoker::$assertionsDisabled && !($MethodHandleNatives::isPullModeBSM(bsm) == goToPushMode)) {
		$throwNew($AssertionError);
	}
	if (goToPushMode) {
		$init($BootstrapMethodInvoker$PushAdapter);
		return $nc($($nc($BootstrapMethodInvoker$PushAdapter::MH_pushToBootstrapMethod)->bindTo(bsm)))->withVarargs(true);
	} else {
		$init($BootstrapMethodInvoker$PullAdapter);
		return $nc($($nc($BootstrapMethodInvoker$PullAdapter::MH_pullFromBootstrapMethod)->bindTo(bsm)))->withVarargs(false);
	}
}

void clinit$BootstrapMethodInvoker($Class* class$) {
	$useLocalCurrentObjectStackCache();
	BootstrapMethodInvoker::$assertionsDisabled = !BootstrapMethodInvoker::class$->desiredAssertionStatus();
	$load($CallSite);
	$load($MethodHandles$Lookup);
	$load($MethodType);
	$load($MethodHandle);
	$assignStatic(BootstrapMethodInvoker::LMF_INDY_MT, $MethodType::methodType($CallSite::class$, $MethodHandles$Lookup::class$, $$new($ClassArray, {
		$String::class$,
		$MethodType::class$,
		$MethodType::class$,
		$MethodHandle::class$,
		$MethodType::class$
	})));
	$load($ObjectArray);
	$assignStatic(BootstrapMethodInvoker::LMF_ALT_MT, $MethodType::methodType($CallSite::class$, $MethodHandles$Lookup::class$, $$new($ClassArray, {
		$String::class$,
		$MethodType::class$,
		$getClass($ObjectArray)
	})));
	$assignStatic(BootstrapMethodInvoker::LMF_CONDY_MT, $MethodType::methodType($Object::class$, $MethodHandles$Lookup::class$, $$new($ClassArray, {
		$String::class$,
		$Class::class$,
		$MethodType::class$,
		$MethodHandle::class$,
		$MethodType::class$
	})));
	$assignStatic(BootstrapMethodInvoker::SCF_MT, $MethodType::methodType($CallSite::class$, $MethodHandles$Lookup::class$, $$new($ClassArray, {
		$String::class$,
		$MethodType::class$,
		$String::class$,
		$getClass($ObjectArray)
	})));
}

BootstrapMethodInvoker::BootstrapMethodInvoker() {
}

$Class* BootstrapMethodInvoker::load$($String* name, bool initialize) {
	$loadClass(BootstrapMethodInvoker, name, initialize, &_BootstrapMethodInvoker_ClassInfo_, clinit$BootstrapMethodInvoker, allocate$BootstrapMethodInvoker);
	return class$;
}

$Class* BootstrapMethodInvoker::class$ = nullptr;

		} // invoke
	} // lang
} // java