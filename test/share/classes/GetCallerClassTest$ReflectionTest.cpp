#include <GetCallerClassTest$ReflectionTest.h>

#include <GetCallerClassTest.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/StackWalker.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

#undef TYPE

using $GetCallerClassTest = ::GetCallerClassTest;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StackWalker = ::java::lang::StackWalker;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;

$FieldInfo _GetCallerClassTest$ReflectionTest_FieldInfo_[] = {
	{"this$0", "LGetCallerClassTest;", nullptr, $FINAL | $SYNTHETIC, $field(GetCallerClassTest$ReflectionTest, this$0)},
	{"methodType", "Ljava/lang/invoke/MethodType;", nullptr, $FINAL, $field(GetCallerClassTest$ReflectionTest, methodType)},
	{}
};

$MethodInfo _GetCallerClassTest$ReflectionTest_MethodInfo_[] = {
	{"<init>", "(LGetCallerClassTest;)V", nullptr, 0, $method(GetCallerClassTest$ReflectionTest, init$, void, $GetCallerClassTest*)},
	{"callMethodHandle", "()V", nullptr, 0, $virtualMethod(GetCallerClassTest$ReflectionTest, callMethodHandle, void)},
	{"callMethodHandleRefl", "()V", nullptr, 0, $virtualMethod(GetCallerClassTest$ReflectionTest, callMethodHandleRefl, void)},
	{"callMethodInvoke", "()V", nullptr, 0, $virtualMethod(GetCallerClassTest$ReflectionTest, callMethodInvoke, void)},
	{"callMethodInvokeRefl", "()V", nullptr, 0, $virtualMethod(GetCallerClassTest$ReflectionTest, callMethodInvokeRefl, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(GetCallerClassTest$ReflectionTest, run, void)},
	{}
};

$InnerClassInfo _GetCallerClassTest$ReflectionTest_InnerClassesInfo_[] = {
	{"GetCallerClassTest$ReflectionTest", "GetCallerClassTest", "ReflectionTest", 0},
	{}
};

$ClassInfo _GetCallerClassTest$ReflectionTest_ClassInfo_ = {
	$ACC_SUPER,
	"GetCallerClassTest$ReflectionTest",
	"java.lang.Object",
	"java.lang.Runnable",
	_GetCallerClassTest$ReflectionTest_FieldInfo_,
	_GetCallerClassTest$ReflectionTest_MethodInfo_,
	nullptr,
	nullptr,
	_GetCallerClassTest$ReflectionTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"GetCallerClassTest"
};

$Object* allocate$GetCallerClassTest$ReflectionTest($Class* clazz) {
	return $of($alloc(GetCallerClassTest$ReflectionTest));
}

void GetCallerClassTest$ReflectionTest::init$($GetCallerClassTest* this$0) {
	$set(this, this$0, this$0);
	$init($Void);
	$load($StackWalker);
	$init($Boolean);
	$set(this, methodType, $MethodType::methodType($Void::TYPE, $StackWalker::class$, $$new($ClassArray, {
		$Class::class$,
		$Boolean::TYPE
	})));
}

void GetCallerClassTest$ReflectionTest::run() {
	callMethodHandle();
	callMethodHandleRefl();
	callMethodInvoke();
	callMethodInvokeRefl();
}

void GetCallerClassTest$ReflectionTest::callMethodHandle() {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandles$Lookup, lookup, $MethodHandles::publicLookup());
	try {
		$load($GetCallerClassTest);
		$var($MethodHandle, mh, $nc(lookup)->findStatic($GetCallerClassTest::class$, "staticGetCallerClass"_s, this->methodType));
		$nc(mh)->invokeExact($$new($ObjectArray, {$of(this->this$0->walker), $of(GetCallerClassTest$ReflectionTest::class$), $$of(this->this$0->expectUOE)}));
	} catch ($Throwable& e) {
		$throwNew($RuntimeException, $cast($Throwable, e));
	}
}

void GetCallerClassTest$ReflectionTest::callMethodHandleRefl() {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandles$Lookup, lookup, $MethodHandles::publicLookup());
	try {
		$load($GetCallerClassTest);
		$var($MethodHandle, mh, $nc(lookup)->findStatic($GetCallerClassTest::class$, "reflectiveGetCallerClass"_s, this->methodType));
		$nc(mh)->invokeExact($$new($ObjectArray, {$of(this->this$0->walker), $of(GetCallerClassTest$ReflectionTest::class$), $$of(this->this$0->expectUOE)}));
	} catch ($Throwable& e) {
		$throwNew($RuntimeException, $cast($Throwable, e));
	}
}

void GetCallerClassTest$ReflectionTest::callMethodInvoke() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$load($GetCallerClassTest);
		$load($StackWalker);
		$init($Boolean);
		$var($Method, m, $GetCallerClassTest::class$->getMethod("staticGetCallerClass"_s, $$new($ClassArray, {
			$StackWalker::class$,
			$Class::class$,
			$Boolean::TYPE
		})));
		$nc(m)->invoke(nullptr, $$new($ObjectArray, {
			$of(this->this$0->walker),
			$of(GetCallerClassTest$ReflectionTest::class$),
			$($of($Boolean::valueOf(this->this$0->expectUOE)))
		}));
	} catch ($NoSuchMethodException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($InvocationTargetException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
}

void GetCallerClassTest$ReflectionTest::callMethodInvokeRefl() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$load($GetCallerClassTest);
		$load($StackWalker);
		$init($Boolean);
		$var($Method, m, $GetCallerClassTest::class$->getMethod("reflectiveGetCallerClass"_s, $$new($ClassArray, {
			$StackWalker::class$,
			$Class::class$,
			$Boolean::TYPE
		})));
		$nc(m)->invoke(nullptr, $$new($ObjectArray, {
			$of(this->this$0->walker),
			$of(GetCallerClassTest$ReflectionTest::class$),
			$($of($Boolean::valueOf(this->this$0->expectUOE)))
		}));
	} catch ($UnsupportedOperationException& e) {
		$throw(e);
	} catch ($NoSuchMethodException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($InvocationTargetException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
}

GetCallerClassTest$ReflectionTest::GetCallerClassTest$ReflectionTest() {
}

$Class* GetCallerClassTest$ReflectionTest::load$($String* name, bool initialize) {
	$loadClass(GetCallerClassTest$ReflectionTest, name, initialize, &_GetCallerClassTest$ReflectionTest_ClassInfo_, allocate$GetCallerClassTest$ReflectionTest);
	return class$;
}

$Class* GetCallerClassTest$ReflectionTest::class$ = nullptr;