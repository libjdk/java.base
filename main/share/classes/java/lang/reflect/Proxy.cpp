#include <java/lang/reflect/Proxy.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassValue.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/WrongMethodTypeException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Proxy$1.h>
#include <java/lang/reflect/Proxy$2.h>
#include <java/lang/reflect/Proxy$InvocationException.h>
#include <java/lang/reflect/Proxy$ProxyBuilder.h>
#include <java/lang/reflect/ReflectPermission.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Arrays.h>
#include <java/util/Deque.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/BooleanSupplier.h>
#include <jdk/internal/loader/AbstractClassLoaderValue$Sub.h>
#include <jdk/internal/loader/ClassLoaderValue.h>
#include <jdk/internal/reflect/Reflection.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef DEFAULT_METHODS_MAP
#undef EMPTY_ARGS
#undef GET_CLASSLOADER_PERMISSION
#undef PROXY_PACKAGE
#undef PROXY_PACKAGE_PREFIX

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassValue = ::java::lang::ClassValue;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $WrongMethodTypeException = ::java::lang::invoke::WrongMethodTypeException;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Proxy$1 = ::java::lang::reflect::Proxy$1;
using $Proxy$2 = ::java::lang::reflect::Proxy$2;
using $Proxy$InvocationException = ::java::lang::reflect::Proxy$InvocationException;
using $Proxy$ProxyBuilder = ::java::lang::reflect::Proxy$ProxyBuilder;
using $ReflectPermission = ::java::lang::reflect::ReflectPermission;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Arrays = ::java::util::Arrays;
using $Deque = ::java::util::Deque;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiFunction = ::java::util::function::BiFunction;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $AbstractClassLoaderValue$Sub = ::jdk::internal::loader::AbstractClassLoaderValue$Sub;
using $ClassLoaderValue = ::jdk::internal::loader::ClassLoaderValue;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {
		namespace reflect {

class Proxy$$Lambda$lambda$getProxyConstructor$0 : public $BiFunction {
	$class(Proxy$$Lambda$lambda$getProxyConstructor$0, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* ld, Object$* clv) override {
		 return $of(Proxy::lambda$getProxyConstructor$0($cast($ClassLoader, ld), $cast($AbstractClassLoaderValue$Sub, clv)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Proxy$$Lambda$lambda$getProxyConstructor$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Proxy$$Lambda$lambda$getProxyConstructor$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Proxy$$Lambda$lambda$getProxyConstructor$0, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Proxy$$Lambda$lambda$getProxyConstructor$0, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Proxy$$Lambda$lambda$getProxyConstructor$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Proxy$$Lambda$lambda$getProxyConstructor$0",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Proxy$$Lambda$lambda$getProxyConstructor$0::load$($String* name, bool initialize) {
	$loadClass(Proxy$$Lambda$lambda$getProxyConstructor$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Proxy$$Lambda$lambda$getProxyConstructor$0::class$ = nullptr;

class Proxy$$Lambda$lambda$getProxyConstructor$1$1 : public $BiFunction {
	$class(Proxy$$Lambda$lambda$getProxyConstructor$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* ld, Object$* clv) override {
		 return $of(Proxy::lambda$getProxyConstructor$1($cast($ClassLoader, ld), $cast($AbstractClassLoaderValue$Sub, clv)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Proxy$$Lambda$lambda$getProxyConstructor$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Proxy$$Lambda$lambda$getProxyConstructor$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Proxy$$Lambda$lambda$getProxyConstructor$1$1, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Proxy$$Lambda$lambda$getProxyConstructor$1$1, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Proxy$$Lambda$lambda$getProxyConstructor$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Proxy$$Lambda$lambda$getProxyConstructor$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Proxy$$Lambda$lambda$getProxyConstructor$1$1::load$($String* name, bool initialize) {
	$loadClass(Proxy$$Lambda$lambda$getProxyConstructor$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Proxy$$Lambda$lambda$getProxyConstructor$1$1::class$ = nullptr;

class Proxy$$Lambda$getClassLoader$2 : public $PrivilegedAction {
	$class(Proxy$$Lambda$getClassLoader$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Module* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->getClassLoader());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Proxy$$Lambda$getClassLoader$2>());
	}
	$Module* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Proxy$$Lambda$getClassLoader$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Proxy$$Lambda$getClassLoader$2, inst$)},
	{}
};
$MethodInfo Proxy$$Lambda$getClassLoader$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(Proxy$$Lambda$getClassLoader$2, init$, void, $Module*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Proxy$$Lambda$getClassLoader$2, run, $Object*)},
	{}
};
$ClassInfo Proxy$$Lambda$getClassLoader$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Proxy$$Lambda$getClassLoader$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Proxy$$Lambda$getClassLoader$2::load$($String* name, bool initialize) {
	$loadClass(Proxy$$Lambda$getClassLoader$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Proxy$$Lambda$getClassLoader$2::class$ = nullptr;

class Proxy$$Lambda$lambda$defaultMethodHandle$2$3 : public $BooleanSupplier {
	$class(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, $NO_CLASS_INIT, $BooleanSupplier)
public:
	void init$($MethodHandle* dmh, $MethodType* type, $Class* proxyClass) {
		$set(this, dmh, dmh);
		$set(this, type, type);
		this->proxyClass = proxyClass;
	}
	virtual bool getAsBoolean() override {
		 return Proxy::lambda$defaultMethodHandle$2(dmh, type, proxyClass);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Proxy$$Lambda$lambda$defaultMethodHandle$2$3>());
	}
	$MethodHandle* dmh = nullptr;
	$MethodType* type = nullptr;
	$Class* proxyClass = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Proxy$$Lambda$lambda$defaultMethodHandle$2$3::fieldInfos[4] = {
	{"dmh", "Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $field(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, dmh)},
	{"type", "Ljava/lang/invoke/MethodType;", nullptr, $PUBLIC, $field(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, type)},
	{"proxyClass", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, proxyClass)},
	{}
};
$MethodInfo Proxy$$Lambda$lambda$defaultMethodHandle$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, init$, void, $MethodHandle*, $MethodType*, $Class*)},
	{"getAsBoolean", "()Z", nullptr, $PUBLIC, $virtualMethod(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, getAsBoolean, bool)},
	{}
};
$ClassInfo Proxy$$Lambda$lambda$defaultMethodHandle$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Proxy$$Lambda$lambda$defaultMethodHandle$2$3",
	"java.lang.Object",
	"java.util.function.BooleanSupplier",
	fieldInfos,
	methodInfos
};
$Class* Proxy$$Lambda$lambda$defaultMethodHandle$2$3::load$($String* name, bool initialize) {
	$loadClass(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Proxy$$Lambda$lambda$defaultMethodHandle$2$3::class$ = nullptr;

$CompoundAttribute _Proxy_MethodAnnotations_getInvocationHandler7[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Proxy_MethodAnnotations_getProxyClass9[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Proxy_MethodAnnotations_newProxyInstance15[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _Proxy_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Proxy, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Proxy, serialVersionUID)},
	{"constructorParams", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(Proxy, constructorParams)},
	{"proxyCache", "Ljdk/internal/loader/ClassLoaderValue;", "Ljdk/internal/loader/ClassLoaderValue<Ljava/lang/reflect/Constructor<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Proxy, proxyCache)},
	{"h", "Ljava/lang/reflect/InvocationHandler;", nullptr, $PROTECTED, $field(Proxy, h)},
	{"PROXY_PACKAGE_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Proxy, PROXY_PACKAGE_PREFIX)},
	{"DEFAULT_METHODS_MAP", "Ljava/lang/ClassValue;", "Ljava/lang/ClassValue<Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/reflect/Method;Ljava/lang/invoke/MethodHandle;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Proxy, DEFAULT_METHODS_MAP)},
	{"EMPTY_ARGS", "[Ljava/lang/Object;", nullptr, $STATIC | $FINAL, $staticField(Proxy, EMPTY_ARGS)},
	{}
};

$MethodInfo _Proxy_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Proxy, init$, void)},
	{"<init>", "(Ljava/lang/reflect/InvocationHandler;)V", nullptr, $PROTECTED, $method(Proxy, init$, void, $InvocationHandler*)},
	{"checkNewProxyPermission", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(Proxy, checkNewProxyPermission, void, $Class*, $Class*)},
	{"checkProxyAccess", "(Ljava/lang/Class;Ljava/lang/ClassLoader;[Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Proxy, checkProxyAccess, void, $Class*, $ClassLoader*, $ClassArray*)},
	{"defaultMethodHandle", "(Ljava/lang/Class;Ljava/lang/reflect/Method;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<+Ljava/lang/reflect/Proxy;>;Ljava/lang/reflect/Method;)Ljava/lang/invoke/MethodHandle;", $STATIC, $staticMethod(Proxy, defaultMethodHandle, $MethodHandle*, $Class*, $Method*)},
	{"defaultMethodMap", "(Ljava/lang/Class;)Ljava/util/concurrent/ConcurrentHashMap;", "(Ljava/lang/Class<*>;)Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/reflect/Method;Ljava/lang/invoke/MethodHandle;>;", $PRIVATE | $STATIC, $staticMethod(Proxy, defaultMethodMap, $ConcurrentHashMap*, $Class*)},
	{"findProxyInterfaceOrElseThrow", "(Ljava/lang/Class;Ljava/lang/reflect/Method;)Ljava/lang/Class;", "(Ljava/lang/Class<*>;Ljava/lang/reflect/Method;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(Proxy, findProxyInterfaceOrElseThrow, $Class*, $Class*, $Method*)},
	{"getInvocationHandler", "(Ljava/lang/Object;)Ljava/lang/reflect/InvocationHandler;", nullptr, $PUBLIC | $STATIC, $staticMethod(Proxy, getInvocationHandler, $InvocationHandler*, Object$*), "java.lang.IllegalArgumentException", nullptr, _Proxy_MethodAnnotations_getInvocationHandler7},
	{"getLoader", "(Ljava/lang/Module;)Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC, $staticMethod(Proxy, getLoader, $ClassLoader*, $Module*)},
	{"getProxyClass", "(Ljava/lang/ClassLoader;[Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC | $TRANSIENT | $DEPRECATED, $staticMethod(Proxy, getProxyClass, $Class*, $ClassLoader*, $ClassArray*), "java.lang.IllegalArgumentException", nullptr, _Proxy_MethodAnnotations_getProxyClass9},
	{"getProxyConstructor", "(Ljava/lang/Class;Ljava/lang/ClassLoader;[Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<*>;", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Proxy, getProxyConstructor, $Constructor*, $Class*, $ClassLoader*, $ClassArray*)},
	{"isProxyClass", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC | $STATIC, $staticMethod(Proxy, isProxyClass, bool, $Class*)},
	{"lambda$defaultMethodHandle$2", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Ljava/lang/Class;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Proxy, lambda$defaultMethodHandle$2, bool, $MethodHandle*, $MethodType*, $Class*)},
	{"lambda$getProxyConstructor$0", "(Ljava/lang/ClassLoader;Ljdk/internal/loader/AbstractClassLoaderValue$Sub;)Ljava/lang/reflect/Constructor;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Proxy, lambda$getProxyConstructor$0, $Constructor*, $ClassLoader*, $AbstractClassLoaderValue$Sub*)},
	{"lambda$getProxyConstructor$1", "(Ljava/lang/ClassLoader;Ljdk/internal/loader/AbstractClassLoaderValue$Sub;)Ljava/lang/reflect/Constructor;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Proxy, lambda$getProxyConstructor$1, $Constructor*, $ClassLoader*, $AbstractClassLoaderValue$Sub*)},
	{"newProxyInstance", "(Ljava/lang/ClassLoader;[Ljava/lang/Class;Ljava/lang/reflect/InvocationHandler;)Ljava/lang/Object;", "(Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;Ljava/lang/reflect/InvocationHandler;)Ljava/lang/Object;", $PUBLIC | $STATIC, $staticMethod(Proxy, newProxyInstance, $Object*, $ClassLoader*, $ClassArray*, $InvocationHandler*), nullptr, nullptr, _Proxy_MethodAnnotations_newProxyInstance15},
	{"newProxyInstance", "(Ljava/lang/Class;Ljava/lang/reflect/Constructor;Ljava/lang/reflect/InvocationHandler;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Ljava/lang/reflect/Constructor<*>;Ljava/lang/reflect/InvocationHandler;)Ljava/lang/Object;", $PRIVATE | $STATIC, $staticMethod(Proxy, newProxyInstance, $Object*, $Class*, $Constructor*, $InvocationHandler*)},
	{"proxyClassLookup", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandles$Lookup;", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandles$Lookup;", $PRIVATE | $STATIC, $staticMethod(Proxy, proxyClassLookup, $MethodHandles$Lookup*, $MethodHandles$Lookup*, $Class*)},
	{}
};

$InnerClassInfo _Proxy_InnerClassesInfo_[] = {
	{"java.lang.reflect.Proxy$InvocationException", "java.lang.reflect.Proxy", "InvocationException", $STATIC},
	{"java.lang.reflect.Proxy$ProxyBuilder", "java.lang.reflect.Proxy", "ProxyBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.reflect.Proxy$2", nullptr, nullptr, 0},
	{"java.lang.reflect.Proxy$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Proxy_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.reflect.Proxy",
	"java.lang.Object",
	"java.io.Serializable",
	_Proxy_FieldInfo_,
	_Proxy_MethodInfo_,
	nullptr,
	nullptr,
	_Proxy_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.reflect.Proxy$InvocationException,java.lang.reflect.Proxy$ProxyBuilder,java.lang.reflect.Proxy$ProxyBuilder$1,java.lang.reflect.Proxy$2,java.lang.reflect.Proxy$1"
};

$Object* allocate$Proxy($Class* clazz) {
	return $of($alloc(Proxy));
}

bool Proxy::$assertionsDisabled = false;
$ClassArray* Proxy::constructorParams = nullptr;
$ClassLoaderValue* Proxy::proxyCache = nullptr;
$String* Proxy::PROXY_PACKAGE_PREFIX = nullptr;
$ClassValue* Proxy::DEFAULT_METHODS_MAP = nullptr;
$ObjectArray* Proxy::EMPTY_ARGS = nullptr;

void Proxy::init$() {
}

void Proxy::init$($InvocationHandler* h) {
	$Objects::requireNonNull(h);
	$set(this, h, h);
}

$Class* Proxy::getProxyClass($ClassLoader* loader, $ClassArray* interfaces) {
	$init(Proxy);
	$Class* caller = $System::getSecurityManager() == nullptr ? ($Class*)nullptr : $Reflection::getCallerClass();
	return $nc($(getProxyConstructor(caller, loader, interfaces)))->getDeclaringClass();
}

$Constructor* Proxy::getProxyConstructor($Class* caller, $ClassLoader* loader, $ClassArray* interfaces) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	if ($nc(interfaces)->length == 1) {
		$Class* intf = interfaces->get(0);
		if (caller != nullptr) {
			checkProxyAccess(caller, loader, $$new($ClassArray, {intf}));
		}
		return $cast($Constructor, $nc($($nc(Proxy::proxyCache)->sub(intf)))->computeIfAbsent(loader, static_cast<$BiFunction*>($$new(Proxy$$Lambda$lambda$getProxyConstructor$0))));
	} else {
		$var($ClassArray, intfsArray, $cast($ClassArray, interfaces->clone()));
		if (caller != nullptr) {
			checkProxyAccess(caller, loader, intfsArray);
		}
		$var($List, intfs, $Arrays::asList(intfsArray));
		return $cast($Constructor, $nc($($nc(Proxy::proxyCache)->sub(intfs)))->computeIfAbsent(loader, static_cast<$BiFunction*>($$new(Proxy$$Lambda$lambda$getProxyConstructor$1$1))));
	}
}

void Proxy::checkProxyAccess($Class* caller, $ClassLoader* loader, $ClassArray* interfaces) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($ClassLoader, ccl, $nc(caller)->getClassLoader());
		if (loader == nullptr && ccl != nullptr) {
			$init($SecurityConstants);
			sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
		}
		$ReflectUtil::checkProxyPackageAccess(ccl, interfaces);
	}
}

$Object* Proxy::newProxyInstance($ClassLoader* loader, $ClassArray* interfaces, $InvocationHandler* h) {
	$init(Proxy);
	$Objects::requireNonNull(h);
	$Class* caller = $System::getSecurityManager() == nullptr ? ($Class*)nullptr : $Reflection::getCallerClass();
	$var($Constructor, cons, getProxyConstructor(caller, loader, interfaces));
	return $of(newProxyInstance(caller, cons, h));
}

$Object* Proxy::newProxyInstance($Class* caller, $Constructor* cons, $InvocationHandler* h) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		if (caller != nullptr) {
			checkNewProxyPermission(caller, $nc(cons)->getDeclaringClass());
		}
		return $of($nc(cons)->newInstance($$new($ObjectArray, {$of(h)})));
	} catch ($IllegalAccessException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	} catch ($InstantiationException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	} catch ($InvocationTargetException& e) {
		$var($Throwable, t, e->getCause());
		if ($instanceOf($RuntimeException, t)) {
			$throw($cast($RuntimeException, t));
		} else {
			$throwNew($InternalError, $($nc(t)->toString()), t);
		}
	}
	$shouldNotReachHere();
}

void Proxy::checkNewProxyPermission($Class* caller, $Class* proxyClass) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		if ($ReflectUtil::isNonPublicProxyClass(proxyClass)) {
			$var($ClassLoader, ccl, $nc(caller)->getClassLoader());
			$var($ClassLoader, pcl, $nc(proxyClass)->getClassLoader());
			$var($String, pkg, proxyClass->getPackageName());
			$var($String, callerPkg, caller->getPackageName());
			if (pcl != ccl || !$nc(pkg)->equals(callerPkg)) {
				sm->checkPermission($$new($ReflectPermission, $$str({"newProxyInPackage."_s, pkg})));
			}
		}
	}
}

$ClassLoader* Proxy::getLoader($Module* m) {
	$init(Proxy);
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(Proxy$$Lambda$getClassLoader$2, static_cast<$Module*>($nc(m)))));
	return $cast($ClassLoader, $AccessController::doPrivileged(pa));
}

bool Proxy::isProxyClass($Class* cl) {
	$init(Proxy);
	bool var$0 = Proxy::class$->isAssignableFrom(cl);
	return var$0 && $Proxy$ProxyBuilder::isProxyClass(cl);
}

$InvocationHandler* Proxy::getInvocationHandler(Object$* proxy) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	if (!isProxyClass($nc($of(proxy))->getClass())) {
		$throwNew($IllegalArgumentException, "not a proxy instance"_s);
	}
	$var(Proxy, p, $cast(Proxy, proxy));
	$var($InvocationHandler, ih, $nc(p)->h);
	if ($System::getSecurityManager() != nullptr) {
		$Class* ihClass = $nc($of(ih))->getClass();
		$Class* caller = $Reflection::getCallerClass();
		$var($ClassLoader, var$0, $nc(caller)->getClassLoader());
		if ($ReflectUtil::needsPackageAccessCheck(var$0, $($nc(ihClass)->getClassLoader()))) {
			$ReflectUtil::checkPackageAccess(ihClass);
		}
	}
	return ih;
}

$ConcurrentHashMap* Proxy::defaultMethodMap($Class* proxyClass) {
	$init(Proxy);
	if (!Proxy::$assertionsDisabled && !isProxyClass(proxyClass)) {
		$throwNew($AssertionError);
	}
	return $cast($ConcurrentHashMap, $nc(Proxy::DEFAULT_METHODS_MAP)->get(proxyClass));
}

$MethodHandle* Proxy::defaultMethodHandle($Class* proxyClass, $Method* method) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ConcurrentHashMap, methods, defaultMethodMap(proxyClass));
	$var($MethodHandle, superMH, $cast($MethodHandle, $nc(methods)->get(method)));
	if (superMH == nullptr) {
		$Class* var$0 = $nc(method)->getReturnType();
		$var($MethodType, type, $MethodType::methodType(var$0, $(method->getParameterTypes())));
		$var($MethodHandles$Lookup, lookup, $MethodHandles::lookup());
		$Class* proxyInterface = findProxyInterfaceOrElseThrow(proxyClass, method);
		$var($MethodHandle, dmh, nullptr);
		try {
			$assign(dmh, $nc($($nc($(proxyClassLookup(lookup, proxyClass)))->findSpecial(proxyInterface, $($nc(method)->getName()), type, proxyClass)))->withVarargs(false));
		} catch ($IllegalAccessException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		} catch ($NoSuchMethodException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
		if (!Proxy::$assertionsDisabled && !$nc((static_cast<$BooleanSupplier*>($$new(Proxy$$Lambda$lambda$defaultMethodHandle$2$3, dmh, type, proxyClass))))->getAsBoolean()) {
			$throwNew($AssertionError, $of("Wrong method type"_s));
		}
		$var($MethodHandle, mh, $nc(dmh)->asType($($nc($(dmh->type()))->changeReturnType($Object::class$))));
		$assign(mh, $MethodHandles::catchException(mh, $Throwable::class$, $($Proxy$InvocationException::wrapMH())));
		$load($ObjectArray);
		$assign(mh, $nc(mh)->asSpreader(1, $getClass($ObjectArray), $nc(type)->parameterCount()));
		$assign(mh, mh->asType($($MethodType::methodType($Object::class$, $Object::class$, $$new($ClassArray, {$getClass($ObjectArray)})))));
		$var($MethodHandle, cached, $cast($MethodHandle, methods->putIfAbsent(method, mh)));
		if (cached != nullptr) {
			$assign(superMH, cached);
		} else {
			$assign(superMH, mh);
		}
	}
	return superMH;
}

$Class* Proxy::findProxyInterfaceOrElseThrow($Class* proxyClass, $Method* method) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* declaringClass = $nc(method)->getDeclaringClass();
	if (!$nc(declaringClass)->isInterface()) {
		$throwNew($IllegalArgumentException, $$str({"\""_s, method, "\" is not a method declared in the proxy class"_s}));
	}
	$var($List, proxyInterfaces, $Arrays::asList($($nc(proxyClass)->getInterfaces())));
	if ($nc(proxyInterfaces)->contains(declaringClass)) {
		return declaringClass;
	}
	$var($Deque, deque, $new($ArrayDeque));
	$var($Set, visited, $new($HashSet));
	bool indirectMethodRef = false;
	{
		$var($Iterator, i$, $nc(proxyInterfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* proxyIntf = $cast($Class, i$->next());
			{
				if (!Proxy::$assertionsDisabled && !(proxyIntf != declaringClass)) {
					$throwNew($AssertionError);
				}
				visited->add(proxyIntf);
				deque->add(proxyIntf);
				$Class* c = nullptr;
				while ((c = $cast($Class, deque->poll())) != nullptr) {
					if (c == declaringClass) {
						try {
							$var($String, var$0, method->getName());
							$var($Method, m, $nc(proxyIntf)->getMethod(var$0, $(method->getParameterTypes())));
							if ($nc(m)->getDeclaringClass() == declaringClass) {
								return proxyIntf;
							}
							indirectMethodRef = true;
						} catch ($NoSuchMethodException& e) {
						}
						continue;
					}
					visited->add(c);
					{
						$var($ClassArray, arr$, $nc(c)->getInterfaces());
						int32_t len$ = arr$->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							$Class* superIntf = arr$->get(i$);
							{
								bool var$1 = !visited->contains(superIntf);
								if (var$1 && !deque->contains(superIntf)) {
									if (superIntf == declaringClass) {
										deque->addFirst(superIntf);
									} else {
										deque->add(superIntf);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	$throwNew($IllegalArgumentException, $$str({"\""_s, method, (indirectMethodRef ? "\" is overridden directly or indirectly by the proxy interfaces"_s : "\" is not a method declared in the proxy class"_s)}));
	$shouldNotReachHere();
}

$MethodHandles$Lookup* Proxy::proxyClassLookup($MethodHandles$Lookup* caller, $Class* proxyClass) {
	$init(Proxy);
	$beforeCallerSensitive();
	return $cast($MethodHandles$Lookup, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Proxy$2, proxyClass, caller))));
}

bool Proxy::lambda$defaultMethodHandle$2($MethodHandle* dmh, $MethodType* type, $Class* proxyClass) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	try {
		$nc(dmh)->asType($($nc(type)->insertParameterTypes(0, $$new($ClassArray, {proxyClass}))));
		return true;
	} catch ($WrongMethodTypeException& e) {
		return false;
	}
	$shouldNotReachHere();
}

$Constructor* Proxy::lambda$getProxyConstructor$1($ClassLoader* ld, $AbstractClassLoaderValue$Sub* clv) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	return $$new($Proxy$ProxyBuilder, ld, $cast($List, $($nc(clv)->key())))->build();
}

$Constructor* Proxy::lambda$getProxyConstructor$0($ClassLoader* ld, $AbstractClassLoaderValue$Sub* clv) {
	$init(Proxy);
	$useLocalCurrentObjectStackCache();
	return $$new($Proxy$ProxyBuilder, ld, $cast($Class, $($nc(clv)->key())))->build();
}

void clinit$Proxy($Class* class$) {
	$init($ReflectUtil);
	$assignStatic(Proxy::PROXY_PACKAGE_PREFIX, $ReflectUtil::PROXY_PACKAGE);
	Proxy::$assertionsDisabled = !Proxy::class$->desiredAssertionStatus();
	$load($InvocationHandler);
	$assignStatic(Proxy::constructorParams, $new($ClassArray, {$InvocationHandler::class$}));
	$assignStatic(Proxy::proxyCache, $new($ClassLoaderValue));
	$assignStatic(Proxy::DEFAULT_METHODS_MAP, $new($Proxy$1));
	$assignStatic(Proxy::EMPTY_ARGS, $new($ObjectArray, 0));
}

Proxy::Proxy() {
}

$Class* Proxy::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Proxy$$Lambda$lambda$getProxyConstructor$0::classInfo$.name)) {
			return Proxy$$Lambda$lambda$getProxyConstructor$0::load$(name, initialize);
		}
		if (name->equals(Proxy$$Lambda$lambda$getProxyConstructor$1$1::classInfo$.name)) {
			return Proxy$$Lambda$lambda$getProxyConstructor$1$1::load$(name, initialize);
		}
		if (name->equals(Proxy$$Lambda$getClassLoader$2::classInfo$.name)) {
			return Proxy$$Lambda$getClassLoader$2::load$(name, initialize);
		}
		if (name->equals(Proxy$$Lambda$lambda$defaultMethodHandle$2$3::classInfo$.name)) {
			return Proxy$$Lambda$lambda$defaultMethodHandle$2$3::load$(name, initialize);
		}
	}
	$loadClass(Proxy, name, initialize, &_Proxy_ClassInfo_, clinit$Proxy, allocate$Proxy);
	return class$;
}

$Class* Proxy::class$ = nullptr;

		} // reflect
	} // lang
} // java