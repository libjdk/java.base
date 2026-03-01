#include <Test7157574.h>

#include <Test7157574$1C.h>
#include <Test7157574$Intf.h>
#include <Test7157574$Sub.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef TYPE

using $Test7157574$1C = ::Test7157574$1C;
using $Test7157574$Intf = ::Test7157574$Intf;
using $Test7157574$Sub = ::Test7157574$Sub;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Objects = ::java::util::Objects;

$MethodInfo _Test7157574_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Test7157574, init$, void)},
	{"assertEquals", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7157574, assertEquals, void, Object$*, Object$*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Test7157574, main, void, $StringArray*), "java.lang.Throwable"},
	{"testConcrete", "(LTest7157574$Sub;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test7157574, testConcrete, void, $Test7157574$Sub*, $MethodHandle*, $MethodHandle*, $MethodHandle*, $MethodHandle*, $MethodHandle*, $MethodHandle*), "java.lang.Throwable"},
	{}
};

$InnerClassInfo _Test7157574_InnerClassesInfo_[] = {
	{"Test7157574$Sub", "Test7157574", "Sub", $STATIC | $ABSTRACT},
	{"Test7157574$Super", "Test7157574", "Super", $STATIC | $ABSTRACT},
	{"Test7157574$Intf", "Test7157574", "Intf", $STATIC | $INTERFACE | $ABSTRACT},
	{"Test7157574$1C", nullptr, "C", 0},
	{}
};

$ClassInfo _Test7157574_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Test7157574",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Test7157574_MethodInfo_,
	nullptr,
	nullptr,
	_Test7157574_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Test7157574$Sub,Test7157574$Super,Test7157574$Intf,Test7157574$1C"
};

$Object* allocate$Test7157574($Class* clazz) {
	return $of($alloc(Test7157574));
}

void Test7157574::init$() {
}

void Test7157574::main($StringArray* av) {
	$load(Test7157574);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($Test7157574$Sub);
	$init($Void);
	$var($MethodHandle, m1, $nc($($MethodHandles::lookup()))->findVirtual($Test7157574$Sub::class$, "m1"_s, $($MethodType::methodType($Void::TYPE))));
	$nc($System::out)->println($of(m1));
	$var($MethodHandle, m2, $nc($($MethodHandles::lookup()))->findVirtual($Test7157574$Sub::class$, "m2"_s, $($MethodType::methodType($Void::TYPE))));
	$nc($System::out)->println($of(m2));
	$init($Integer);
	$var($MethodHandle, f2, $nc($($MethodHandles::lookup()))->findGetter($Test7157574$Sub::class$, "f2"_s, $Integer::TYPE));
	$nc($System::out)->println($of(f2));
	$var($MethodHandle, f2s, $nc($($MethodHandles::lookup()))->findSetter($Test7157574$Sub::class$, "f2"_s, $Integer::TYPE));
	$nc($System::out)->println($of(f2s));
	$var($MethodHandle, chc, $nc($($MethodHandles::lookup()))->findVirtual($Test7157574$Sub::class$, "hashCode"_s, $($MethodType::methodType($Integer::TYPE))));
	$nc($System::out)->println($of(chc));
	$load($Test7157574$Intf);
	$var($MethodHandle, ihc, $nc($($MethodHandles::lookup()))->findVirtual($Test7157574$Intf::class$, "hashCode"_s, $($MethodType::methodType($Integer::TYPE))));
	$nc($System::out)->println($of(ihc));
	assertEquals($Test7157574$Sub::class$, $($nc($($nc(m1)->type()))->parameterType(0)));
	assertEquals($Test7157574$Sub::class$, $($nc($($nc(m2)->type()))->parameterType(0)));
	assertEquals($Test7157574$Sub::class$, $($nc($($nc(f2)->type()))->parameterType(0)));
	assertEquals($Test7157574$Sub::class$, $($nc($($nc(f2s)->type()))->parameterType(0)));
	assertEquals($Test7157574$Sub::class$, $($nc($($nc(chc)->type()))->parameterType(0)));
	assertEquals($Test7157574$Intf::class$, $($nc($($nc(ihc)->type()))->parameterType(0)));
	{
	}
	testConcrete($$new($Test7157574$1C), m1, m2, f2, f2s, chc, ihc);
}

void Test7157574::testConcrete($Test7157574$Sub* s, $MethodHandle* m1, $MethodHandle* m2, $MethodHandle* f2, $MethodHandle* f2s, $MethodHandle* chc, $MethodHandle* ihc) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->f2 = 0;
	$nc(m1)->invokeExact($$new($ObjectArray, {$of(s)}));
	$var($Object, var$0, $of($Integer::valueOf(-1)));
	assertEquals(var$0, $($Integer::valueOf(s->f2)));
	$nc(m2)->invokeExact($$new($ObjectArray, {$of(s)}));
	$var($Object, var$1, $of($Integer::valueOf(-2)));
	assertEquals(var$1, $($Integer::valueOf(s->f2)));
	s->f2 = 2;
	$var($Object, var$2, $of($Integer::valueOf(2)));
	assertEquals(var$2, $($Integer::valueOf($intValue($nc(f2)->invokeExact($$new($ObjectArray, {$of(s)}))))));
	$nc(f2s)->invokeExact($$new($ObjectArray, {$of(s), $$of(0)}));
	$var($Object, var$3, $of($Integer::valueOf(0)));
	assertEquals(var$3, $($Integer::valueOf(s->f2)));
	$var($Object, var$4, $of($Integer::valueOf($of(s)->hashCode())));
	assertEquals(var$4, $($Integer::valueOf($intValue($nc(chc)->invokeExact($$new($ObjectArray, {$of(s)}))))));
	$var($Object, var$5, $of($Integer::valueOf($of(s)->hashCode())));
	assertEquals(var$5, $($Integer::valueOf($intValue($nc(ihc)->invokeExact($$new($ObjectArray, {static_cast<$Test7157574$Intf*>(s)}))))));
}

void Test7157574::assertEquals(Object$* expect, Object$* observe) {
	$useLocalCurrentObjectStackCache();
	if ($Objects::equals(expect, observe)) {
		return;
	}
	$var($String, msg, $str({"expected "_s, expect, " but observed "_s, observe}));
	$nc($System::out)->println($$str({"FAILED: "_s, msg}));
	$throwNew($AssertionError, $of(msg));
}

Test7157574::Test7157574() {
}

$Class* Test7157574::load$($String* name, bool initialize) {
	$loadClass(Test7157574, name, initialize, &_Test7157574_ClassInfo_, allocate$Test7157574);
	return class$;
}

$Class* Test7157574::class$ = nullptr;