#include <java/lang/invoke/MethodHandleProxies.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl.h>
#include <java/lang/invoke/MethodHandleProxies$1.h>
#include <java/lang/invoke/MethodHandleProxies$2.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <jdk/internal/reflect/Reflection.h>
#include <sun/invoke/WrapperInstance.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef IMPL_LOOKUP
#undef TYPE

using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl = ::java::lang::invoke::MethodHandleImpl;
using $MethodHandleProxies$1 = ::java::lang::invoke::MethodHandleProxies$1;
using $MethodHandleProxies$2 = ::java::lang::invoke::MethodHandleProxies$2;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $WrapperInstance = ::sun::invoke::WrapperInstance;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace java {
	namespace lang {
		namespace invoke {

class MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0 : public $Function {
	$class(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, $NO_CLASS_INIT, $Function)
public:
	void init$($Class* intfc, Object$* self) {
		this->intfc = intfc;
		$set(this, self, self);
	}
	virtual $Object* apply(Object$* mk) override {
		 return $of(MethodHandleProxies::lambda$callDefaultMethod$0(intfc, self, $cast($Method, mk)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0>());
	}
	$Class* intfc = nullptr;
	$Object* self = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::fieldInfos[3] = {
	{"intfc", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, intfc)},
	{"self", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, self)},
	{}
};
$MethodInfo MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, init$, void, $Class*, Object$*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::load$($String* name, bool initialize) {
	$loadClass(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::class$ = nullptr;

$CompoundAttribute _MethodHandleProxies_MethodAnnotations_asInterfaceInstance1[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _MethodHandleProxies_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodHandleProxies, $assertionsDisabled)},
	{}
};

$MethodInfo _MethodHandleProxies_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(MethodHandleProxies, init$, void)},
	{"asInterfaceInstance", "(Ljava/lang/Class;Ljava/lang/invoke/MethodHandle;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Class<TT;>;Ljava/lang/invoke/MethodHandle;)TT;", $PUBLIC | $STATIC, $staticMethod(MethodHandleProxies, asInterfaceInstance, $Object*, $Class*, $MethodHandle*), nullptr, nullptr, _MethodHandleProxies_MethodAnnotations_asInterfaceInstance1},
	{"asWrapperInstance", "(Ljava/lang/Object;)Lsun/invoke/WrapperInstance;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, asWrapperInstance, $WrapperInstance*, Object$*)},
	{"bindCaller", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, bindCaller, $MethodHandle*, $MethodHandle*, $Class*)},
	{"callDefaultMethod", "(Ljava/util/concurrent/ConcurrentHashMap;Ljava/lang/Object;Ljava/lang/Class;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/reflect/Method;Ljava/lang/invoke/MethodHandle;>;Ljava/lang/Object;Ljava/lang/Class<*>;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, callDefaultMethod, $Object*, $ConcurrentHashMap*, Object$*, $Class*, $Method*, $ObjectArray*), "java.lang.Throwable"},
	{"callObjectMethod", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, callObjectMethod, $Object*, Object$*, $Method*, $ObjectArray*)},
	{"getSingleNameMethods", "(Ljava/lang/Class;)[Ljava/lang/reflect/Method;", "(Ljava/lang/Class<*>;)[Ljava/lang/reflect/Method;", $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, getSingleNameMethods, $MethodArray*, $Class*)},
	{"hasDefaultMethods", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, hasDefaultMethods, bool, $Class*)},
	{"isDefaultMethod", "(Ljava/lang/reflect/Method;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, isDefaultMethod, bool, $Method*)},
	{"isObjectMethod", "(Ljava/lang/reflect/Method;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandleProxies, isObjectMethod, bool, $Method*)},
	{"isWrapperInstance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(MethodHandleProxies, isWrapperInstance, bool, Object$*)},
	{"lambda$callDefaultMethod$0", "(Ljava/lang/Class;Ljava/lang/Object;Ljava/lang/reflect/Method;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(MethodHandleProxies, lambda$callDefaultMethod$0, $MethodHandle*, $Class*, Object$*, $Method*)},
	{"wrapperInstanceTarget", "(Ljava/lang/Object;)Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MethodHandleProxies, wrapperInstanceTarget, $MethodHandle*, Object$*)},
	{"wrapperInstanceType", "(Ljava/lang/Object;)Ljava/lang/Class;", "(Ljava/lang/Object;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(MethodHandleProxies, wrapperInstanceType, $Class*, Object$*)},
	{}
};

$InnerClassInfo _MethodHandleProxies_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandleProxies$2", nullptr, nullptr, 0},
	{"java.lang.invoke.MethodHandleProxies$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MethodHandleProxies_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.invoke.MethodHandleProxies",
	"java.lang.Object",
	nullptr,
	_MethodHandleProxies_FieldInfo_,
	_MethodHandleProxies_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandleProxies_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandleProxies$2,java.lang.invoke.MethodHandleProxies$1"
};

$Object* allocate$MethodHandleProxies($Class* clazz) {
	return $of($alloc(MethodHandleProxies));
}

bool MethodHandleProxies::$assertionsDisabled = false;

void MethodHandleProxies::init$() {
}

$Object* MethodHandleProxies::asInterfaceInstance($Class* intfc, $MethodHandle* target) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	bool var$0 = !$nc(intfc)->isInterface();
	if (var$0 || !$Modifier::isPublic($nc(intfc)->getModifiers())) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("not a public interface"_s, $($nc(intfc)->getName()))));
	}
	if ($nc(intfc)->isSealed()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("a sealed interface"_s, $(intfc->getName()))));
	}
	$var($MethodHandle, mh, nullptr);
	if ($System::getSecurityManager() != nullptr) {
		$Class* caller = $Reflection::getCallerClass();
		$var($ClassLoader, ccl, caller != nullptr ? $nc(caller)->getClassLoader() : ($ClassLoader*)nullptr);
		$ReflectUtil::checkProxyPackageAccess(ccl, $$new($ClassArray, {intfc}));
		$assign(mh, ccl != nullptr ? bindCaller(target, caller) : target);
	} else {
		$assign(mh, target);
	}
	$var($ClassLoader, proxyLoader, $nc(intfc)->getClassLoader());
	if (proxyLoader == nullptr) {
		$var($ClassLoader, cl, $($Thread::currentThread())->getContextClassLoader());
		$assign(proxyLoader, cl != nullptr ? cl : $ClassLoader::getSystemClassLoader());
	}
	$var($MethodArray, methods, getSingleNameMethods(intfc));
	if (methods == nullptr) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("not a single-method interface"_s, $(intfc->getName()))));
	}
	$var($MethodHandleArray, vaTargets, $new($MethodHandleArray, $nc(methods)->length));
	for (int32_t i = 0; i < methods->length; ++i) {
		$var($Method, sm, methods->get(i));
		$Class* var$1 = $nc(sm)->getReturnType();
		$var($MethodType, smMT, $MethodType::methodType(var$1, $(sm->getParameterTypes())));
		$var($MethodHandle, checkTarget, $nc(mh)->asType(smMT));
		$assign(checkTarget, $nc(checkTarget)->asType($($nc($(checkTarget->type()))->changeReturnType($Object::class$))));
		$load($ObjectArray);
		vaTargets->set(i, $(checkTarget->asSpreader($getClass($ObjectArray), $nc(smMT)->parameterCount())));
	}
	$var($ConcurrentHashMap, defaultMethodMap, hasDefaultMethods(intfc) ? $new($ConcurrentHashMap) : ($ConcurrentHashMap*)nullptr);
	$var($InvocationHandler, ih, $new($MethodHandleProxies$1, target, intfc, methods, vaTargets, defaultMethodMap));
	$var($Object, proxy, nullptr);
	if ($System::getSecurityManager() != nullptr) {
		$var($ClassLoader, loader, proxyLoader);
		$assign(proxy, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($MethodHandleProxies$2, loader, intfc, ih))));
	} else {
		$load($WrapperInstance);
		$assign(proxy, $Proxy::newProxyInstance(proxyLoader, $$new($ClassArray, {
			intfc,
			$WrapperInstance::class$
		}), ih));
	}
	return $of(intfc->cast(proxy));
}

$MethodHandle* MethodHandleProxies::bindCaller($MethodHandle* target, $Class* hostClass) {
	$init(MethodHandleProxies);
	return $nc($($MethodHandleImpl::bindCaller(target, hostClass)))->withVarargs($nc(target)->isVarargsCollector());
}

bool MethodHandleProxies::isWrapperInstance(Object$* x) {
	$init(MethodHandleProxies);
	return $instanceOf($WrapperInstance, x);
}

$WrapperInstance* MethodHandleProxies::asWrapperInstance(Object$* x) {
	$init(MethodHandleProxies);
	try {
		if (x != nullptr) {
			return $cast($WrapperInstance, x);
		}
	} catch ($ClassCastException& ex) {
	}
	$throw($($MethodHandleStatics::newIllegalArgumentException("not a wrapper instance"_s)));
	$shouldNotReachHere();
}

$MethodHandle* MethodHandleProxies::wrapperInstanceTarget(Object$* x) {
	$init(MethodHandleProxies);
	return $nc($(asWrapperInstance(x)))->getWrapperInstanceTarget();
}

$Class* MethodHandleProxies::wrapperInstanceType(Object$* x) {
	$init(MethodHandleProxies);
	return $nc($(asWrapperInstance(x)))->getWrapperInstanceType();
}

bool MethodHandleProxies::isObjectMethod($Method* m) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	$var($String, s14004$, $nc(m)->getName());
	int32_t tmp14004$ = -1;
	switch ($nc(s14004$)->hashCode()) {
	case (int32_t)0x9616526C:
		{
			if (s14004$->equals("toString"_s)) {
				tmp14004$ = 0;
			}
			break;
		}
	case 0x08CDAC1B:
		{
			if (s14004$->equals("hashCode"_s)) {
				tmp14004$ = 1;
			}
			break;
		}
	case (int32_t)0xB2C87FBF:
		{
			if (s14004$->equals("equals"_s)) {
				tmp14004$ = 2;
			}
			break;
		}
	}

	bool var$0 = false;
	switch (tmp14004$) {
	case 0:
		{
			bool var$1 = $nc(m)->getReturnType() == $String::class$;
			var$0 = var$1 && m->getParameterCount() == 0;
			break;
		}
	case 1:
		{
			$init($Integer);
			bool var$2 = $nc(m)->getReturnType() == $Integer::TYPE;
			var$0 = var$2 && m->getParameterCount() == 0;
			break;
		}
	case 2:
		{
			$init($Boolean);
			bool var$4 = $nc(m)->getReturnType() == $Boolean::TYPE;
			bool var$3 = var$4 && m->getParameterCount() == 1;
			var$0 = var$3 && $nc($(m->getParameterTypes()))->get(0) == $Object::class$;
			break;
		}
	default:
		{
			var$0 = false;
			break;
		}
	}
	return var$0;
}

$Object* MethodHandleProxies::callObjectMethod(Object$* self, $Method* m, $ObjectArray* args) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	if (!MethodHandleProxies::$assertionsDisabled && !(isObjectMethod(m))) {
		$throwNew($AssertionError, $of(m));
	}
	$var($String, s14666$, $nc(m)->getName());
	int32_t tmp14666$ = -1;
	switch ($nc(s14666$)->hashCode()) {
	case (int32_t)0x9616526C:
		{
			if (s14666$->equals("toString"_s)) {
				tmp14666$ = 0;
			}
			break;
		}
	case 0x08CDAC1B:
		{
			if (s14666$->equals("hashCode"_s)) {
				tmp14666$ = 1;
			}
			break;
		}
	case (int32_t)0xB2C87FBF:
		{
			if (s14666$->equals("equals"_s)) {
				tmp14666$ = 2;
			}
			break;
		}
	}

	$var($Object, var$0, nullptr)
	switch (tmp14666$) {
	case 0:
		{
			$var($String, var$1, $$str({$($nc($of(self))->getClass()->getName()), "@"_s}));
			$assign(var$0, $concat(var$1, $($Integer::toHexString($of(self)->hashCode()))));
			break;
		}
	case 1:
		{
			$assign(var$0, $Integer::valueOf($System::identityHashCode(self)));
			break;
		}
	case 2:
		{
			$assign(var$0, $Boolean::valueOf(($equals(self, $nc(args)->get(0)))));
			break;
		}
	default:
		{
			$assign(var$0, nullptr);
			break;
		}
	}
	return $of(var$0);
}

$MethodArray* MethodHandleProxies::getSingleNameMethods($Class* intfc) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ArrayList, methods, $new($ArrayList));
	$var($String, uniqueName, nullptr);
	{
		$var($MethodArray, arr$, $nc(intfc)->getMethods());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, m, arr$->get(i$));
			{
				if (isObjectMethod(m)) {
					continue;
				}
				if (!$Modifier::isAbstract($nc(m)->getModifiers())) {
					continue;
				}
				$var($String, mname, $nc(m)->getName());
				if (uniqueName == nullptr) {
					$assign(uniqueName, mname);
				} else if (!$nc(uniqueName)->equals(mname)) {
					return nullptr;
				}
				methods->add(m);
			}
		}
	}
	if (uniqueName == nullptr) {
		return nullptr;
	}
	return $fcast($MethodArray, methods->toArray($$new($MethodArray, methods->size())));
}

bool MethodHandleProxies::isDefaultMethod($Method* m) {
	$init(MethodHandleProxies);
	return !$Modifier::isAbstract($nc(m)->getModifiers());
}

bool MethodHandleProxies::hasDefaultMethods($Class* intfc) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($MethodArray, arr$, $nc(intfc)->getMethods());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, m, arr$->get(i$));
			{
				bool var$0 = !isObjectMethod(m);
				if (var$0 && !$Modifier::isAbstract($nc(m)->getModifiers())) {
					return true;
				}
			}
		}
	}
	return false;
}

$Object* MethodHandleProxies::callDefaultMethod($ConcurrentHashMap* defaultMethodMap, Object$* self, $Class* intfc, $Method* m, $ObjectArray* args) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	bool var$0 = !MethodHandleProxies::$assertionsDisabled;
	if (var$0) {
		bool var$1 = isDefaultMethod(m);
		var$0 = !(var$1 && !isObjectMethod(m));
	}
	if (var$0) {
		$throwNew($AssertionError, $of(m));
	}
	$var($MethodHandle, dmh, $cast($MethodHandle, $nc(defaultMethodMap)->computeIfAbsent(m, static_cast<$Function*>($$new(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0, intfc, self)))));
	return $of($nc(dmh)->invoke($$new($ObjectArray, {self, $of(args)})));
}

$MethodHandle* MethodHandleProxies::lambda$callDefaultMethod$0($Class* intfc, Object$* self, $Method* mk) {
	$init(MethodHandleProxies);
	$useLocalCurrentObjectStackCache();
	try {
		$init($MethodHandles$Lookup);
		$Class* var$0 = intfc;
		$var($String, var$1, $nc(mk)->getName());
		$Class* var$3 = mk->getReturnType();
		$var($MethodType, var$2, $MethodType::methodType(var$3, $(mk->getParameterTypes())));
		$var($MethodHandle, mh, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findSpecial(var$0, var$1, var$2, $nc($of(self))->getClass()));
		$load($ObjectArray);
		return $nc(mh)->asSpreader($getClass($ObjectArray), $nc(mk)->getParameterCount());
	} catch ($NoSuchMethodException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void clinit$MethodHandleProxies($Class* class$) {
	MethodHandleProxies::$assertionsDisabled = !MethodHandleProxies::class$->desiredAssertionStatus();
}

MethodHandleProxies::MethodHandleProxies() {
}

$Class* MethodHandleProxies::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::classInfo$.name)) {
			return MethodHandleProxies$$Lambda$lambda$callDefaultMethod$0::load$(name, initialize);
		}
	}
	$loadClass(MethodHandleProxies, name, initialize, &_MethodHandleProxies_ClassInfo_, clinit$MethodHandleProxies, allocate$MethodHandleProxies);
	return class$;
}

$Class* MethodHandleProxies::class$ = nullptr;

		} // invoke
	} // lang
} // java