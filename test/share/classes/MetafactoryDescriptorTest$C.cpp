#include <MetafactoryDescriptorTest$C.h>

#include <MetafactoryDescriptorTest.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <jcpp.h>

#undef TYPE

using $MetafactoryDescriptorTest = ::MetafactoryDescriptorTest;
using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;

$MethodInfo _MetafactoryDescriptorTest$C_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MetafactoryDescriptorTest$C, init$, void)},
	{"getM", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, getM, $MethodHandle*, $Class*)},
	{"getN", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, getN, $MethodHandle*, $Class*)},
	{"m_Integer", "(Ljava/lang/String;)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_Integer, $Integer*, $String*)},
	{"m_Object", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_Object, $Object*, $String*)},
	{"m_String", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_String, $String*, $String*)},
	{"m_boolean", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_boolean, bool, $String*)},
	{"m_byte", "(Ljava/lang/String;)B", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_byte, int8_t, $String*)},
	{"m_char", "(Ljava/lang/String;)C", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_char, char16_t, $String*)},
	{"m_double", "(Ljava/lang/String;)D", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_double, double, $String*)},
	{"m_float", "(Ljava/lang/String;)F", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_float, float, $String*)},
	{"m_int", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_int, int32_t, $String*)},
	{"m_long", "(Ljava/lang/String;)J", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_long, int64_t, $String*)},
	{"m_short", "(Ljava/lang/String;)S", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_short, int16_t, $String*)},
	{"m_void", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, m_void, void, $String*)},
	{"n_Integer", "(Ljava/lang/Integer;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_Integer, $String*, $Integer*)},
	{"n_Object", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_Object, $String*, Object$*)},
	{"n_String", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_String, $String*, $String*)},
	{"n_boolean", "(Z)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_boolean, $String*, bool)},
	{"n_byte", "(B)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_byte, $String*, int8_t)},
	{"n_char", "(C)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_char, $String*, char16_t)},
	{"n_double", "(D)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_double, $String*, double)},
	{"n_float", "(F)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_float, $String*, float)},
	{"n_int", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_int, $String*, int32_t)},
	{"n_long", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_long, $String*, int64_t)},
	{"n_short", "(S)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(MetafactoryDescriptorTest$C, n_short, $String*, int16_t)},
	{}
};

$InnerClassInfo _MetafactoryDescriptorTest$C_InnerClassesInfo_[] = {
	{"MetafactoryDescriptorTest$C", "MetafactoryDescriptorTest", "C", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _MetafactoryDescriptorTest$C_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MetafactoryDescriptorTest$C",
	"java.lang.Object",
	nullptr,
	nullptr,
	_MetafactoryDescriptorTest$C_MethodInfo_,
	nullptr,
	nullptr,
	_MetafactoryDescriptorTest$C_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"MetafactoryDescriptorTest"
};

$Object* allocate$MetafactoryDescriptorTest$C($Class* clazz) {
	return $of($alloc(MetafactoryDescriptorTest$C));
}

void MetafactoryDescriptorTest$C::init$() {
}

void MetafactoryDescriptorTest$C::m_void($String* arg) {
}

bool MetafactoryDescriptorTest$C::m_boolean($String* arg) {
	return true;
}

char16_t MetafactoryDescriptorTest$C::m_char($String* arg) {
	return u'x';
}

int8_t MetafactoryDescriptorTest$C::m_byte($String* arg) {
	return (int8_t)12;
}

int16_t MetafactoryDescriptorTest$C::m_short($String* arg) {
	return (int16_t)12;
}

int32_t MetafactoryDescriptorTest$C::m_int($String* arg) {
	return 12;
}

int64_t MetafactoryDescriptorTest$C::m_long($String* arg) {
	return 12;
}

float MetafactoryDescriptorTest$C::m_float($String* arg) {
	return (float)12;
}

double MetafactoryDescriptorTest$C::m_double($String* arg) {
	return (double)12;
}

$String* MetafactoryDescriptorTest$C::m_String($String* arg) {
	return ""_s;
}

$Integer* MetafactoryDescriptorTest$C::m_Integer($String* arg) {
	return $Integer::valueOf(23);
}

$Object* MetafactoryDescriptorTest$C::m_Object($String* arg) {
	return $of($new($Object));
}

$String* MetafactoryDescriptorTest$C::n_boolean(bool arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_char(char16_t arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_byte(int8_t arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_short(int16_t arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_int(int32_t arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_long(int64_t arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_float(float arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_double(double arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_String($String* arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_Integer($Integer* arg) {
	return ""_s;
}

$String* MetafactoryDescriptorTest$C::n_Object(Object$* arg) {
	return ""_s;
}

$MethodHandle* MetafactoryDescriptorTest$C::getM($Class* c) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($MetafactoryDescriptorTest);
		$load(MetafactoryDescriptorTest$C);
		$Class* var$0 = MetafactoryDescriptorTest$C::class$;
		$var($String, var$1, $str({"m_"_s, $($nc(c)->getSimpleName())}));
		return $nc($MetafactoryDescriptorTest::lookup)->findStatic(var$0, var$1, $($MetafactoryDescriptorTest::mt(c, $$new($ClassArray, {$String::class$}))));
	} catch ($NoSuchMethodException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$MethodHandle* MetafactoryDescriptorTest$C::getN($Class* c) {
	$useLocalCurrentObjectStackCache();
	$init($Void);
	if (c == $Void::TYPE) {
		return nullptr;
	}
	try {
		$init($MetafactoryDescriptorTest);
		$load(MetafactoryDescriptorTest$C);
		$Class* var$0 = MetafactoryDescriptorTest$C::class$;
		$var($String, var$1, $str({"n_"_s, $($nc(c)->getSimpleName())}));
		return $nc($MetafactoryDescriptorTest::lookup)->findStatic(var$0, var$1, $($MetafactoryDescriptorTest::mt($String::class$, $$new($ClassArray, {c}))));
	} catch ($NoSuchMethodException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

MetafactoryDescriptorTest$C::MetafactoryDescriptorTest$C() {
}

$Class* MetafactoryDescriptorTest$C::load$($String* name, bool initialize) {
	$loadClass(MetafactoryDescriptorTest$C, name, initialize, &_MetafactoryDescriptorTest$C_ClassInfo_, allocate$MetafactoryDescriptorTest$C);
	return class$;
}

$Class* MetafactoryDescriptorTest$C::class$ = nullptr;