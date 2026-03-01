#include <test/java/lang/invoke/CallStaticInitOrder.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/ConstantCallSite.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/MutableCallSite.h>
#include <java/lang/reflect/Method.h>
#include <test/java/lang/invoke/CallStaticInitOrder$Init1.h>
#include <test/java/lang/invoke/CallStaticInitOrder$Init2.h>
#include <test/java/lang/invoke/CallStaticInitOrder$Init3.h>
#include <test/java/lang/invoke/CallStaticInitOrder$Init4.h>
#include <test/java/lang/invoke/CallStaticInitOrder$Init5.h>
#include <test/java/lang/invoke/CallStaticInitOrder$Init6.h>
#include <jcpp.h>

#undef LAST_LOSER
#undef TICK
#undef TYPE

using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $ConstantCallSite = ::java::lang::invoke::ConstantCallSite;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MutableCallSite = ::java::lang::invoke::MutableCallSite;
using $CallStaticInitOrder$Init1 = ::test::java::lang::invoke::CallStaticInitOrder$Init1;
using $CallStaticInitOrder$Init2 = ::test::java::lang::invoke::CallStaticInitOrder$Init2;
using $CallStaticInitOrder$Init3 = ::test::java::lang::invoke::CallStaticInitOrder$Init3;
using $CallStaticInitOrder$Init4 = ::test::java::lang::invoke::CallStaticInitOrder$Init4;
using $CallStaticInitOrder$Init5 = ::test::java::lang::invoke::CallStaticInitOrder$Init5;
using $CallStaticInitOrder$Init6 = ::test::java::lang::invoke::CallStaticInitOrder$Init6;

namespace test {
	namespace java {
		namespace lang {
			namespace invoke {

$FieldInfo _CallStaticInitOrder_FieldInfo_[] = {
	{"TICK", "I", nullptr, $PRIVATE | $STATIC, $staticField(CallStaticInitOrder, TICK)},
	{"Init1Tick", "I", nullptr, $STATIC, $staticField(CallStaticInitOrder, Init1Tick)},
	{"Init2Tick", "I", nullptr, $STATIC, $staticField(CallStaticInitOrder, Init2Tick)},
	{"Init3Tick", "I", nullptr, $STATIC, $staticField(CallStaticInitOrder, Init3Tick)},
	{"Init4Tick", "I", nullptr, $STATIC, $staticField(CallStaticInitOrder, Init4Tick)},
	{"Init5Tick", "I", nullptr, $STATIC, $staticField(CallStaticInitOrder, Init5Tick)},
	{"Init6Tick", "I", nullptr, $STATIC, $staticField(CallStaticInitOrder, Init6Tick)},
	{"CONSTANT_CS_baz", "Ljava/lang/invoke/MutableCallSite;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CallStaticInitOrder, CONSTANT_CS_baz)},
	{"CONSTANT_MH_bar", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CallStaticInitOrder, CONSTANT_MH_bar)},
	{"CONSTANT_MH_bat", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CallStaticInitOrder, CONSTANT_MH_bat)},
	{"CONSTANT_MH_bangGetter", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CallStaticInitOrder, CONSTANT_MH_bangGetter)},
	{"CONSTANT_MH_pongSetter", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CallStaticInitOrder, CONSTANT_MH_pongSetter)},
	{"LAST_LOSER", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC, $staticField(CallStaticInitOrder, LAST_LOSER)},
	{}
};

$MethodInfo _CallStaticInitOrder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CallStaticInitOrder, init$, void)},
	{"INDY_bang", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, INDY_bang, $MethodHandle*), "java.lang.Throwable"},
	{"INDY_bar", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, INDY_bar, $MethodHandle*), "java.lang.Throwable"},
	{"INDY_bat", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, INDY_bat, $MethodHandle*), "java.lang.Throwable"},
	{"INDY_baz", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, INDY_baz, $MethodHandle*), "java.lang.Throwable"},
	{"INDY_foo", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, INDY_foo, $MethodHandle*), "java.lang.Throwable"},
	{"INDY_pong", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, INDY_pong, $MethodHandle*), "java.lang.Throwable"},
	{"MH_baz", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, MH_baz, $MethodHandle*), "java.lang.ReflectiveOperationException"},
	{"MH_bsm", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, MH_bsm, $MethodHandle*), "java.lang.ReflectiveOperationException"},
	{"MH_foo", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, MH_foo, $MethodHandle*), "java.lang.ReflectiveOperationException"},
	{"assertEquals", "(II)V", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, assertEquals, void, int32_t, int32_t)},
	{"bsm", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/CallSite;", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, bsm, $CallSite*, $MethodHandles$Lookup*, $String*, $MethodType*), "java.lang.ReflectiveOperationException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(CallStaticInitOrder, main, void, $StringArray*), "java.lang.Throwable"},
	{"runBang", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, runBang, int32_t), "java.lang.Throwable"},
	{"runBar", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, runBar, int32_t), "java.lang.Throwable"},
	{"runBat", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, runBat, int32_t), "java.lang.Throwable"},
	{"runBaz", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, runBaz, int32_t), "java.lang.Throwable"},
	{"runFoo", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, runFoo, int32_t), "java.lang.Throwable"},
	{"runPong", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, runPong, int32_t), "java.lang.Throwable"},
	{"shouldNotCallThis", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, shouldNotCallThis, void)},
	{"testInit", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(CallStaticInitOrder, testInit, void), "java.lang.Throwable"},
	{"tick", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(CallStaticInitOrder, tick, int32_t, $String*)},
	{}
};

$InnerClassInfo _CallStaticInitOrder_InnerClassesInfo_[] = {
	{"test.java.lang.invoke.CallStaticInitOrder$Init6", "test.java.lang.invoke.CallStaticInitOrder", "Init6", $PRIVATE | $STATIC},
	{"test.java.lang.invoke.CallStaticInitOrder$Init5", "test.java.lang.invoke.CallStaticInitOrder", "Init5", $PRIVATE | $STATIC},
	{"test.java.lang.invoke.CallStaticInitOrder$Init4", "test.java.lang.invoke.CallStaticInitOrder", "Init4", $PRIVATE | $STATIC},
	{"test.java.lang.invoke.CallStaticInitOrder$Init3", "test.java.lang.invoke.CallStaticInitOrder", "Init3", $PRIVATE | $STATIC},
	{"test.java.lang.invoke.CallStaticInitOrder$Init2", "test.java.lang.invoke.CallStaticInitOrder", "Init2", $PRIVATE | $STATIC},
	{"test.java.lang.invoke.CallStaticInitOrder$Init1", "test.java.lang.invoke.CallStaticInitOrder", "Init1", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _CallStaticInitOrder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"test.java.lang.invoke.CallStaticInitOrder",
	"java.lang.Object",
	nullptr,
	_CallStaticInitOrder_FieldInfo_,
	_CallStaticInitOrder_MethodInfo_,
	nullptr,
	nullptr,
	_CallStaticInitOrder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"test.java.lang.invoke.CallStaticInitOrder$Init6,test.java.lang.invoke.CallStaticInitOrder$Init5,test.java.lang.invoke.CallStaticInitOrder$Init4,test.java.lang.invoke.CallStaticInitOrder$Init3,test.java.lang.invoke.CallStaticInitOrder$Init2,test.java.lang.invoke.CallStaticInitOrder$Init1"
};

$Object* allocate$CallStaticInitOrder($Class* clazz) {
	return $of($alloc(CallStaticInitOrder));
}

int32_t CallStaticInitOrder::TICK = 0;
int32_t CallStaticInitOrder::Init1Tick = 0;
int32_t CallStaticInitOrder::Init2Tick = 0;
int32_t CallStaticInitOrder::Init3Tick = 0;
int32_t CallStaticInitOrder::Init4Tick = 0;
int32_t CallStaticInitOrder::Init5Tick = 0;
int32_t CallStaticInitOrder::Init6Tick = 0;
$MutableCallSite* CallStaticInitOrder::CONSTANT_CS_baz = nullptr;
$MethodHandle* CallStaticInitOrder::CONSTANT_MH_bar = nullptr;
$MethodHandle* CallStaticInitOrder::CONSTANT_MH_bat = nullptr;
$MethodHandle* CallStaticInitOrder::CONSTANT_MH_bangGetter = nullptr;
$MethodHandle* CallStaticInitOrder::CONSTANT_MH_pongSetter = nullptr;
$Throwable* CallStaticInitOrder::LAST_LOSER = nullptr;

void CallStaticInitOrder::init$() {
}

int32_t CallStaticInitOrder::tick($String* event) {
	$load(CallStaticInitOrder);
	$synchronized(class$) {
		$init(CallStaticInitOrder);
		$useLocalCurrentObjectStackCache();
		int32_t n = ++CallStaticInitOrder::TICK;
		$nc($System::out)->println($$str({"event #"_s, $$str(n), " = "_s, event}));
		return n;
	}
}

$MethodHandle* CallStaticInitOrder::MH_foo() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($CallStaticInitOrder$Init1);
	$init($Integer);
	return $nc($($MethodHandles::lookup()))->findStatic($CallStaticInitOrder$Init1::class$, "foo"_s, $($MethodType::methodType($Integer::TYPE)));
}

$MethodHandle* CallStaticInitOrder::MH_baz() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($CallStaticInitOrder$Init3);
	$init($Integer);
	return $nc($($MethodHandles::lookup()))->findStatic($CallStaticInitOrder$Init3::class$, "baz"_s, $($MethodType::methodType($Integer::TYPE)));
}

void CallStaticInitOrder::main($StringArray* av) {
	$init(CallStaticInitOrder);
	testInit();
	if (CallStaticInitOrder::LAST_LOSER != nullptr) {
		$throw(CallStaticInitOrder::LAST_LOSER);
	}
}

void CallStaticInitOrder::assertEquals(int32_t expected, int32_t actual) {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	if (expected != actual) {
		$var($Throwable, loser, $new($AssertionError, $of($$str({"expected: "_s, $$str(expected), ", actual: "_s, $$str(actual)}))));
		if (CallStaticInitOrder::LAST_LOSER != nullptr) {
			$nc(CallStaticInitOrder::LAST_LOSER)->printStackTrace($System::out);
		}
		$assignStatic(CallStaticInitOrder::LAST_LOSER, loser);
	}
}

void CallStaticInitOrder::testInit() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({"runFoo = "_s, $$str(runFoo())}));
	$nc($System::out)->println($$str({"runBar = "_s, $$str(runBar())}));
	try {
		runBaz();
	} catch ($IllegalStateException& ex) {
		tick("runBaz throw/catch"_s);
	}
	$nc(CallStaticInitOrder::CONSTANT_CS_baz)->setTarget($(MH_baz()));
	$nc($System::out)->println($$str({"runBaz = "_s, $$str(runBaz())}));
	$nc($System::out)->println($$str({"runBat = "_s, $$str(runBat())}));
	$nc($System::out)->println($$str({"runBang = "_s, $$str(runBang())}));
	$nc($System::out)->println($$str({"runPong = "_s, $$str(runPong())}));
}

int32_t CallStaticInitOrder::runFoo() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	assertEquals(CallStaticInitOrder::Init1Tick, 0);
	int32_t t1 = tick("runFoo"_s);
	int32_t t2 = $intValue($nc($(INDY_foo()))->invokeExact($$new($ObjectArray, 0)));
	int32_t t3 = tick("runFoo done"_s);
	assertEquals(CallStaticInitOrder::Init1Tick, t2);
	assertEquals(t1 + 2, t3);
	assertEquals(t1 + 1, t2);
	return t2;
}

$MethodHandle* CallStaticInitOrder::INDY_foo() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$var($Object, var$0, $of($MethodHandles::lookup()));
	$var($Object, var$1, $of("foo"_s));
	$init($Integer);
	return $nc(($($cast($CallSite, $nc($(MH_bsm()))->invoke($$new($ObjectArray, {var$0, var$1, $($of($MethodType::methodType($Integer::TYPE)))}))))))->dynamicInvoker();
}

int32_t CallStaticInitOrder::runBar() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	assertEquals(CallStaticInitOrder::Init2Tick, 0);
	int32_t t1 = tick("runBar"_s);
	int32_t t2 = $intValue($nc($(INDY_bar()))->invokeExact($$new($ObjectArray, 0)));
	int32_t t3 = tick("runBar done"_s);
	assertEquals(CallStaticInitOrder::Init2Tick, t2);
	assertEquals(t1 + 2, t3);
	assertEquals(t1 + 1, t2);
	return t2;
}

$MethodHandle* CallStaticInitOrder::INDY_bar() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$var($Object, var$0, $of($MethodHandles::lookup()));
	$var($Object, var$1, $of("bar"_s));
	$init($Integer);
	return $nc(($($cast($CallSite, $nc($(MH_bsm()))->invoke($$new($ObjectArray, {var$0, var$1, $($of($MethodType::methodType($Integer::TYPE)))}))))))->dynamicInvoker();
}

int32_t CallStaticInitOrder::runBaz() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	assertEquals(CallStaticInitOrder::Init3Tick, 0);
	int32_t t1 = tick("runBaz"_s);
	int32_t t2 = $intValue($nc($(INDY_baz()))->invokeExact($$new($ObjectArray, 0)));
	int32_t t3 = tick("runBaz done"_s);
	assertEquals(CallStaticInitOrder::Init3Tick, t2);
	assertEquals(t1 + 2, t3);
	assertEquals(t1 + 1, t2);
	return t2;
}

$MethodHandle* CallStaticInitOrder::INDY_baz() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$var($Object, var$0, $of($MethodHandles::lookup()));
	$var($Object, var$1, $of("baz"_s));
	$init($Integer);
	return $nc(($($cast($CallSite, $nc($(MH_bsm()))->invoke($$new($ObjectArray, {var$0, var$1, $($of($MethodType::methodType($Integer::TYPE)))}))))))->dynamicInvoker();
}

int32_t CallStaticInitOrder::runBat() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	assertEquals(CallStaticInitOrder::Init4Tick, 0);
	int32_t t1 = tick("runBat"_s);
	int32_t t2 = $intValue($nc($(INDY_bat()))->invokeExact($$new($ObjectArray, 0)));
	int32_t t3 = tick("runBat done"_s);
	assertEquals(CallStaticInitOrder::Init4Tick, t2);
	assertEquals(t1 + 2, t3);
	assertEquals(t1 + 1, t2);
	return t2;
}

$MethodHandle* CallStaticInitOrder::INDY_bat() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$var($Object, var$0, $of($MethodHandles::lookup()));
	$var($Object, var$1, $of("bat"_s));
	$init($Integer);
	return $nc(($($cast($CallSite, $nc($(MH_bsm()))->invoke($$new($ObjectArray, {var$0, var$1, $($of($MethodType::methodType($Integer::TYPE)))}))))))->dynamicInvoker();
}

int32_t CallStaticInitOrder::runBang() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	assertEquals(CallStaticInitOrder::Init5Tick, 0);
	int32_t t1 = tick("runBang"_s);
	int32_t t2 = $intValue($nc($(INDY_bang()))->invokeExact($$new($ObjectArray, 0)));
	int32_t t3 = tick("runBang done"_s);
	assertEquals(CallStaticInitOrder::Init5Tick, t2);
	assertEquals(t1 + 2, t3);
	assertEquals(t1 + 1, t2);
	return t2;
}

$MethodHandle* CallStaticInitOrder::INDY_bang() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$var($Object, var$0, $of($MethodHandles::lookup()));
	$var($Object, var$1, $of("bang"_s));
	$init($Integer);
	return $nc(($($cast($CallSite, $nc($(MH_bsm()))->invoke($$new($ObjectArray, {var$0, var$1, $($of($MethodType::methodType($Integer::TYPE)))}))))))->dynamicInvoker();
}

int32_t CallStaticInitOrder::runPong() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	assertEquals(CallStaticInitOrder::Init6Tick, 0);
	int32_t t1 = tick("runPong"_s);
	int32_t t2 = $intValue($nc($(INDY_pong()))->invokeExact($$new($ObjectArray, 0)));
	int32_t t3 = tick("runPong done"_s);
	assertEquals(CallStaticInitOrder::Init6Tick, t2);
	assertEquals(t1 + 2, t3);
	assertEquals(t1 + 1, t2);
	return t2;
}

$MethodHandle* CallStaticInitOrder::INDY_pong() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$var($Object, var$0, $of($MethodHandles::lookup()));
	$var($Object, var$1, $of("pong"_s));
	$init($Integer);
	return $nc(($($cast($CallSite, $nc($(MH_bsm()))->invoke($$new($ObjectArray, {var$0, var$1, $($of($MethodType::methodType($Integer::TYPE)))}))))))->dynamicInvoker();
}

$CallSite* CallStaticInitOrder::bsm($MethodHandles$Lookup* caller, $String* name, $MethodType* type) {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({"bsm "_s, name, type}));
	$var($CallSite, res, nullptr);
	{
		$var($String, s9788$, name);
		int32_t tmp9788$ = -1;
		switch ($nc(s9788$)->hashCode()) {
		case 0x00018CC6:
			{
				if (s9788$->equals("foo"_s)) {
					tmp9788$ = 0;
				}
				break;
			}
		case 0x00017C13:
			{
				if (s9788$->equals("bar"_s)) {
					tmp9788$ = 1;
				}
				break;
			}
		case 0x00017C1B:
			{
				if (s9788$->equals("baz"_s)) {
					tmp9788$ = 2;
				}
				break;
			}
		case 0x00017C15:
			{
				if (s9788$->equals("bat"_s)) {
					tmp9788$ = 3;
				}
				break;
			}
		case 0x002E0638:
			{
				if (s9788$->equals("bang"_s)) {
					tmp9788$ = 4;
				}
				break;
			}
		case 0x003497F8:
			{
				if (s9788$->equals("pong"_s)) {
					tmp9788$ = 5;
				}
				break;
			}
		}
		switch (tmp9788$) {
		case 0:
			{
				$assign(res, $new($ConstantCallSite, $(MH_foo())));
				break;
			}
		case 1:
			{
				$assign(res, $new($ConstantCallSite, CallStaticInitOrder::CONSTANT_MH_bar));
				break;
			}
		case 2:
			{
				$assign(res, CallStaticInitOrder::CONSTANT_CS_baz);
				break;
			}
		case 3:
			{
				$assign(res, $new($ConstantCallSite, CallStaticInitOrder::CONSTANT_MH_bat));
				break;
			}
		case 4:
			{
				$assign(res, $new($ConstantCallSite, CallStaticInitOrder::CONSTANT_MH_bangGetter));
				break;
			}
		case 5:
			{
				$assign(res, $new($ConstantCallSite, CallStaticInitOrder::CONSTANT_MH_pongSetter));
				break;
			}
		default:
			{
				$assign(res, nullptr);
			}
		}
	}
	if (res == nullptr || !$nc($($nc(res)->type()))->equals($of(type))) {
		$throwNew($AssertionError, $($of($String::valueOf($of(res)))));
	}
	return res;
}

$MethodHandle* CallStaticInitOrder::MH_bsm() {
	$init(CallStaticInitOrder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	shouldNotCallThis();
	$Class* var$0 = $nc($($MethodHandles::lookup()))->lookupClass();
	$var($String, var$1, "bsm"_s);
	$load($CallSite);
	$load($MethodType);
	return $nc($($MethodHandles::lookup()))->findStatic(var$0, var$1, $($MethodType::methodType($CallSite::class$, $MethodHandles$Lookup::class$, $$new($ClassArray, {
		$String::class$,
		$MethodType::class$
	}))));
}

void CallStaticInitOrder::shouldNotCallThis() {
	$init(CallStaticInitOrder);
	$throwNew($AssertionError, $of("this code should be statically transformed away by Indify"_s));
}

void clinit$CallStaticInitOrder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		try {
			int32_t t1 = CallStaticInitOrder::tick("CallStaticInitOrder.<clinit>"_s);
			{
				$init($Integer);
				$assignStatic(CallStaticInitOrder::CONSTANT_CS_baz, $new($MutableCallSite, $($MethodType::methodType($Integer::TYPE))));
				$load($CallStaticInitOrder$Init2);
				$assignStatic(CallStaticInitOrder::CONSTANT_MH_bar, $nc($($MethodHandles::lookup()))->findStatic($CallStaticInitOrder$Init2::class$, "bar"_s, $($MethodType::methodType($Integer::TYPE))));
				$load($CallStaticInitOrder$Init4);
				$assignStatic(CallStaticInitOrder::CONSTANT_MH_bat, $nc($($MethodHandles::lookup()))->unreflect($($CallStaticInitOrder$Init4::class$->getDeclaredMethod("bat"_s, $$new($ClassArray, 0)))));
				$load($CallStaticInitOrder$Init5);
				$assignStatic(CallStaticInitOrder::CONSTANT_MH_bangGetter, $nc($($MethodHandles::lookup()))->findStaticGetter($CallStaticInitOrder$Init5::class$, "bang"_s, $Integer::TYPE));
				$load($CallStaticInitOrder$Init6);
				$var($MethodHandle, pongSetter, $nc($($MethodHandles::lookup()))->findStaticSetter($CallStaticInitOrder$Init6::class$, "pong"_s, $Integer::TYPE));
				$var($MethodHandle, tickGetter, $nc($($MethodHandles::lookup()))->findStaticGetter(CallStaticInitOrder::class$, "Init6Tick"_s, $Integer::TYPE));
				$assignStatic(CallStaticInitOrder::CONSTANT_MH_pongSetter, $MethodHandles::filterReturnValue($($MethodHandles::insertArguments(pongSetter, 0, $$new($ObjectArray, {$($of($Integer::valueOf(-99)))}))), tickGetter));
			}
			int32_t t2 = CallStaticInitOrder::tick("CallStaticInitOrder.<clinit> done"_s);
			CallStaticInitOrder::assertEquals(t1 + 1, t2);
		} catch ($Exception& ex) {
			$throwNew($InternalError, $(ex->toString()));
		}
	}
}

CallStaticInitOrder::CallStaticInitOrder() {
}

$Class* CallStaticInitOrder::load$($String* name, bool initialize) {
	$loadClass(CallStaticInitOrder, name, initialize, &_CallStaticInitOrder_ClassInfo_, clinit$CallStaticInitOrder, allocate$CallStaticInitOrder);
	return class$;
}

$Class* CallStaticInitOrder::class$ = nullptr;

			} // invoke
		} // lang
	} // java
} // test