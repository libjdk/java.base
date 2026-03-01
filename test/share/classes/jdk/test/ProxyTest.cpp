#include <jdk/test/ProxyTest.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Proxy.h>
#include <jdk/test/ProxyTest$Data.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Proxy = ::java::lang::reflect::Proxy;
using $ProxyTest$Data = ::jdk::test::ProxyTest$Data;

namespace jdk {
	namespace test {

class ProxyTest$$Lambda$lambda$static$0 : public $InvocationHandler {
	$class(ProxyTest$$Lambda$lambda$static$0, $NO_CLASS_INIT, $InvocationHandler)
public:
	void init$() {
	}
	virtual $Object* invoke(Object$* proxy, $Method* m, $ObjectArray* params) override {
		 return ProxyTest::lambda$static$0(proxy, m, params);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProxyTest$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ProxyTest$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ProxyTest$$Lambda$lambda$static$0, init$, void)},
	{"invoke", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProxyTest$$Lambda$lambda$static$0, invoke, $Object*, Object$*, $Method*, $ObjectArray*)},
	{}
};
$ClassInfo ProxyTest$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.test.ProxyTest$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.lang.reflect.InvocationHandler",
	nullptr,
	methodInfos
};
$Class* ProxyTest$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(ProxyTest$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProxyTest$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _ProxyTest_FieldInfo_[] = {
	{"handler", "Ljava/lang/reflect/InvocationHandler;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyTest, handler)},
	{}
};

$MethodInfo _ProxyTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ProxyTest, init$, void)},
	{"assertDynamicModule", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/Class;)V", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/Class<*>;)V", $PUBLIC | $STATIC, $staticMethod(ProxyTest, assertDynamicModule, void, $Module*, $ClassLoader*, $Class*)},
	{"assertEquals", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ProxyTest, assertEquals, void, Object$*, Object$*)},
	{"lambda$static$0", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ProxyTest, lambda$static$0, $Object*, Object$*, $Method*, $ObjectArray*), "java.lang.Throwable"},
	{"test", "(Ljdk/test/ProxyTest$Data;)V", nullptr, $PUBLIC, $virtualMethod(ProxyTest, test, void, $ProxyTest$Data*)},
	{"testDynamicModule", "(Ljdk/test/ProxyTest$Data;)V", nullptr, $PRIVATE, $method(ProxyTest, testDynamicModule, void, $ProxyTest$Data*)},
	{"testProxyClass", "(Ljava/lang/Module;Ljava/lang/ClassLoader;[Ljava/lang/Class;)V", "(Ljava/lang/Module;Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(ProxyTest, testProxyClass, void, $Module*, $ClassLoader*, $ClassArray*)},
	{}
};

$InnerClassInfo _ProxyTest_InnerClassesInfo_[] = {
	{"jdk.test.ProxyTest$Data", "jdk.test.ProxyTest", "Data", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _ProxyTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.test.ProxyTest",
	"java.lang.Object",
	nullptr,
	_ProxyTest_FieldInfo_,
	_ProxyTest_MethodInfo_,
	nullptr,
	nullptr,
	_ProxyTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.test.ProxyTest$Data"
};

$Object* allocate$ProxyTest($Class* clazz) {
	return $of($alloc(ProxyTest));
}

$InvocationHandler* ProxyTest::handler = nullptr;

void ProxyTest::init$() {
}

void ProxyTest::test($ProxyTest$Data* d) {
	$nc($System::out)->println($of(d));
	if ($nc(d)->module != nullptr) {
		testProxyClass(d->module, d->loader, d->interfaces);
	} else {
		testDynamicModule(d);
	}
}

void ProxyTest::testDynamicModule($ProxyTest$Data* d) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* proxyClass = $Proxy::getProxyClass($nc(d)->loader, d->interfaces);
	assertDynamicModule($($nc(proxyClass)->getModule()), $nc(d)->loader, proxyClass);
	$var($Object, proxy, $Proxy::newProxyInstance($nc(d)->loader, d->interfaces, ProxyTest::handler));
	$var($Module, var$0, $nc($of(proxy))->getClass()->getModule());
	$var($ClassLoader, var$1, $nc(d)->loader);
	assertDynamicModule(var$0, var$1, $of(proxy)->getClass());
}

void ProxyTest::testProxyClass($Module* module, $ClassLoader* ld, $ClassArray* interfaces) {
	$init(ProxyTest);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* proxyClass = $Proxy::getProxyClass(ld, interfaces);
	assertEquals($($nc(proxyClass)->getModule()), module);
	$var($Object, proxy, $Proxy::newProxyInstance(ld, interfaces, ProxyTest::handler));
	assertEquals($($nc($of(proxy))->getClass()->getModule()), module);
}

void ProxyTest::assertDynamicModule($Module* m, $ClassLoader* ld, $Class* proxyClass) {
	$init(ProxyTest);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	bool var$0 = !$nc(m)->isNamed();
	if (var$0 || !$nc($($nc(m)->getName()))->startsWith("jdk.proxy"_s)) {
		$throwNew($RuntimeException, $$str({$(m->getName()), " not dynamic module"_s}));
	}
	bool var$1 = ld != $nc(m)->getClassLoader();
	if (var$1 || $nc(proxyClass)->getClassLoader() != ld) {
		$throwNew($RuntimeException, "unexpected class loader"_s);
	}
	try {
		$load($InvocationHandler);
		$var($Constructor, cons, $nc(proxyClass)->getConstructor($$new($ClassArray, {$InvocationHandler::class$})));
		$nc(cons)->newInstance($$new($ObjectArray, {$of(ProxyTest::handler)}));
		if (!$nc($(proxyClass->getPackageName()))->equals($($nc(m)->getName()))) {
			$throwNew($RuntimeException, $$str({"Expected IllegalAccessException: "_s, proxyClass}));
		}
	} catch ($IllegalAccessException& e) {
	} catch ($NoSuchMethodException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($InstantiationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($InvocationTargetException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
}

void ProxyTest::assertEquals(Object$* o1, Object$* o2) {
	$init(ProxyTest);
	if (!$equals(o1, o2)) {
		$throwNew($RuntimeException, $$str({o1, " != "_s, o2}));
	}
}

$Object* ProxyTest::lambda$static$0(Object$* proxy, $Method* m, $ObjectArray* params) {
	$init(ProxyTest);
	$throwNew($RuntimeException, $($nc(m)->toString()));
	$shouldNotReachHere();
}

void clinit$ProxyTest($Class* class$) {
	$assignStatic(ProxyTest::handler, static_cast<$InvocationHandler*>($new(ProxyTest$$Lambda$lambda$static$0)));
}

ProxyTest::ProxyTest() {
}

$Class* ProxyTest::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ProxyTest$$Lambda$lambda$static$0::classInfo$.name)) {
			return ProxyTest$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(ProxyTest, name, initialize, &_ProxyTest_ClassInfo_, clinit$ProxyTest, allocate$ProxyTest);
	return class$;
}

$Class* ProxyTest::class$ = nullptr;

	} // test
} // jdk