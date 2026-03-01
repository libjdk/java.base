#include <MetafactoryArgValidationTest$C.h>

#include <MetafactoryArgValidationTest.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <jcpp.h>

#undef TYPE

using $MetafactoryArgValidationTest = ::MetafactoryArgValidationTest;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;

$FieldInfo _MetafactoryArgValidationTest$C_FieldInfo_[] = {
	{"lookup", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PUBLIC | $STATIC, $staticField(MetafactoryArgValidationTest$C, lookup)},
	{"sv", "LMetafactoryArgValidationTest$C;", nullptr, $PUBLIC | $STATIC, $staticField(MetafactoryArgValidationTest$C, sv)},
	{"iv", "LMetafactoryArgValidationTest$C;", nullptr, $PUBLIC, $field(MetafactoryArgValidationTest$C, iv)},
	{}
};

$MethodInfo _MetafactoryArgValidationTest$C_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MetafactoryArgValidationTest$C, init$, void)},
	{"getFieldMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, getFieldMH, $MethodHandle*)},
	{"getStaticMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, getStaticMH, $MethodHandle*)},
	{"im", "()V", nullptr, $PUBLIC, $virtualMethod(MetafactoryArgValidationTest$C, im, void)},
	{"invokeInterfaceMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, invokeInterfaceMH, $MethodHandle*)},
	{"invokeSpecialMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, invokeSpecialMH, $MethodHandle*)},
	{"invokeStaticMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, invokeStaticMH, $MethodHandle*)},
	{"invokeVirtualMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, invokeVirtualMH, $MethodHandle*)},
	{"newInvokeSpecialMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, newInvokeSpecialMH, $MethodHandle*)},
	{"putFieldMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, putFieldMH, $MethodHandle*)},
	{"putStaticMH", "()Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, putStaticMH, $MethodHandle*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(MetafactoryArgValidationTest$C, run, void)},
	{"sm", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryArgValidationTest$C, sm, void)},
	{}
};

$InnerClassInfo _MetafactoryArgValidationTest$C_InnerClassesInfo_[] = {
	{"MetafactoryArgValidationTest$C", "MetafactoryArgValidationTest", "C", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _MetafactoryArgValidationTest$C_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MetafactoryArgValidationTest$C",
	"java.lang.Object",
	"java.lang.Runnable",
	_MetafactoryArgValidationTest$C_FieldInfo_,
	_MetafactoryArgValidationTest$C_MethodInfo_,
	nullptr,
	nullptr,
	_MetafactoryArgValidationTest$C_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"MetafactoryArgValidationTest"
};

$Object* allocate$MetafactoryArgValidationTest$C($Class* clazz) {
	return $of($alloc(MetafactoryArgValidationTest$C));
}

$MethodHandles$Lookup* MetafactoryArgValidationTest$C::lookup = nullptr;
MetafactoryArgValidationTest$C* MetafactoryArgValidationTest$C::sv = nullptr;

$MethodHandle* MetafactoryArgValidationTest$C::getFieldMH() {
	$init(MetafactoryArgValidationTest$C);
	try {
		return $nc(MetafactoryArgValidationTest$C::lookup)->findGetter(MetafactoryArgValidationTest$C::class$, "iv"_s, MetafactoryArgValidationTest$C::class$);
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::getStaticMH() {
	$init(MetafactoryArgValidationTest$C);
	try {
		return $nc(MetafactoryArgValidationTest$C::lookup)->findStaticGetter(MetafactoryArgValidationTest$C::class$, "sv"_s, MetafactoryArgValidationTest$C::class$);
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::putFieldMH() {
	$init(MetafactoryArgValidationTest$C);
	try {
		return $nc(MetafactoryArgValidationTest$C::lookup)->findSetter(MetafactoryArgValidationTest$C::class$, "iv"_s, MetafactoryArgValidationTest$C::class$);
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::putStaticMH() {
	$init(MetafactoryArgValidationTest$C);
	try {
		return $nc(MetafactoryArgValidationTest$C::lookup)->findStaticSetter(MetafactoryArgValidationTest$C::class$, "sv"_s, MetafactoryArgValidationTest$C::class$);
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::invokeVirtualMH() {
	$init(MetafactoryArgValidationTest$C);
	$useLocalCurrentObjectStackCache();
	try {
		$init($Void);
		return $nc(MetafactoryArgValidationTest$C::lookup)->findVirtual(MetafactoryArgValidationTest$C::class$, "im"_s, $($MetafactoryArgValidationTest::mt($Void::TYPE, $$new($ClassArray, 0))));
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::invokeStaticMH() {
	$init(MetafactoryArgValidationTest$C);
	$useLocalCurrentObjectStackCache();
	try {
		$init($Void);
		return $nc(MetafactoryArgValidationTest$C::lookup)->findStatic(MetafactoryArgValidationTest$C::class$, "sm"_s, $($MetafactoryArgValidationTest::mt($Void::TYPE, $$new($ClassArray, 0))));
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::invokeSpecialMH() {
	$init(MetafactoryArgValidationTest$C);
	$useLocalCurrentObjectStackCache();
	try {
		return $nc(MetafactoryArgValidationTest$C::lookup)->findSpecial($Object::class$, "toString"_s, $($MetafactoryArgValidationTest::mt($String::class$, $$new($ClassArray, 0))), MetafactoryArgValidationTest$C::class$);
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::newInvokeSpecialMH() {
	$init(MetafactoryArgValidationTest$C);
	$useLocalCurrentObjectStackCache();
	try {
		$init($Void);
		return $nc(MetafactoryArgValidationTest$C::lookup)->findConstructor(MetafactoryArgValidationTest$C::class$, $($MetafactoryArgValidationTest::mt($Void::TYPE, $$new($ClassArray, 0))));
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryArgValidationTest$C::invokeInterfaceMH() {
	$init(MetafactoryArgValidationTest$C);
	$useLocalCurrentObjectStackCache();
	try {
		$init($Void);
		return $nc(MetafactoryArgValidationTest$C::lookup)->findVirtual($Runnable::class$, "run"_s, $($MetafactoryArgValidationTest::mt($Void::TYPE, $$new($ClassArray, 0))));
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void MetafactoryArgValidationTest$C::sm() {
	$init(MetafactoryArgValidationTest$C);
}

void MetafactoryArgValidationTest$C::im() {
}

void MetafactoryArgValidationTest$C::init$() {
}

void MetafactoryArgValidationTest$C::run() {
}

void clinit$MetafactoryArgValidationTest$C($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(MetafactoryArgValidationTest$C::lookup, $MethodHandles::lookup());
}

MetafactoryArgValidationTest$C::MetafactoryArgValidationTest$C() {
}

$Class* MetafactoryArgValidationTest$C::load$($String* name, bool initialize) {
	$loadClass(MetafactoryArgValidationTest$C, name, initialize, &_MetafactoryArgValidationTest$C_ClassInfo_, clinit$MetafactoryArgValidationTest$C, allocate$MetafactoryArgValidationTest$C);
	return class$;
}

$Class* MetafactoryArgValidationTest$C::class$ = nullptr;