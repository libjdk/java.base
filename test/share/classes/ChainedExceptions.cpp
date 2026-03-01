#include <ChainedExceptions.h>

#include <HighLevelException.h>
#include <LowLevelException.h>
#include <MidLevelException.h>
#include <java/lang/StackTraceElement.h>
#include <jcpp.h>

#undef OUR_CLASS
#undef OUR_FILE_NAME

using $HighLevelException = ::HighLevelException;
using $LowLevelException = ::LowLevelException;
using $MidLevelException = ::MidLevelException;
using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StackTraceElement = ::java::lang::StackTraceElement;

$FieldInfo _ChainedExceptions_FieldInfo_[] = {
	{"OUR_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ChainedExceptions, OUR_CLASS)},
	{"OUR_FILE_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ChainedExceptions, OUR_FILE_NAME)},
	{}
};

$MethodInfo _ChainedExceptions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ChainedExceptions, init$, void)},
	{"a", "()V", nullptr, $STATIC, $staticMethod(ChainedExceptions, a, void), "HighLevelException"},
	{"b", "()V", nullptr, $STATIC, $staticMethod(ChainedExceptions, b, void), "MidLevelException"},
	{"c", "()V", nullptr, $STATIC, $staticMethod(ChainedExceptions, c, void), "MidLevelException"},
	{"check", "(Ljava/lang/Throwable;Ljava/lang/StackTraceElement;Ljava/lang/String;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ChainedExceptions, check, void, $Throwable*, $StackTraceElement*, $String*, int32_t)},
	{"d", "()V", nullptr, $STATIC, $staticMethod(ChainedExceptions, d, void), "LowLevelException"},
	{"e", "()V", nullptr, $STATIC, $staticMethod(ChainedExceptions, e, void), "LowLevelException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ChainedExceptions, main, void, $StringArray*)},
	{}
};

$ClassInfo _ChainedExceptions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ChainedExceptions",
	"java.lang.Object",
	nullptr,
	_ChainedExceptions_FieldInfo_,
	_ChainedExceptions_MethodInfo_
};

$Object* allocate$ChainedExceptions($Class* clazz) {
	return $of($alloc(ChainedExceptions));
}

$String* ChainedExceptions::OUR_CLASS = nullptr;
$String* ChainedExceptions::OUR_FILE_NAME = nullptr;

void ChainedExceptions::init$() {
}

void ChainedExceptions::main($StringArray* args) {
	$init(ChainedExceptions);
	$useLocalCurrentObjectStackCache();
	try {
		a();
	} catch ($HighLevelException& e) {
		$var($StackTraceElementArray, highTrace, e->getStackTrace());
		int32_t depthTrim = $nc(highTrace)->length - 2;
		check(e, highTrace->get(0), "a"_s, 48);
		check(e, highTrace->get(1), "main"_s, 11);
		$var($Throwable, mid, e->getCause());
		$var($StackTraceElementArray, midTrace, $nc(mid)->getStackTrace());
		if ($nc(midTrace)->length - depthTrim != 4) {
			$throwNew($RuntimeException, "Mid depth"_s);
		}
		check(mid, $nc(midTrace)->get(0), "c"_s, 58);
		check(mid, $nc(midTrace)->get(1), "b"_s, 52);
		check(mid, $nc(midTrace)->get(2), "a"_s, 46);
		check(mid, $nc(midTrace)->get(3), "main"_s, 11);
		$var($Throwable, low, mid->getCause());
		$var($StackTraceElementArray, lowTrace, $nc(low)->getStackTrace());
		if ($nc(lowTrace)->length - depthTrim != 6) {
			$throwNew($RuntimeException, "Low depth"_s);
		}
		check(low, $nc(lowTrace)->get(0), "e"_s, 65);
		check(low, $nc(lowTrace)->get(1), "d"_s, 62);
		check(low, $nc(lowTrace)->get(2), "c"_s, 56);
		check(low, $nc(lowTrace)->get(3), "b"_s, 52);
		check(low, $nc(lowTrace)->get(4), "a"_s, 46);
		check(low, $nc(lowTrace)->get(5), "main"_s, 11);
		if (low->getCause() != nullptr) {
			$throwNew($RuntimeException, "Low cause != null"_s);
		}
	}
}

void ChainedExceptions::a() {
	$init(ChainedExceptions);
	try {
		b();
	} catch ($MidLevelException& e) {
		$throwNew($HighLevelException, e);
	}
}

void ChainedExceptions::b() {
	$init(ChainedExceptions);
	c();
}

void ChainedExceptions::c() {
	$init(ChainedExceptions);
	try {
		d();
	} catch ($LowLevelException& e) {
		$throwNew($MidLevelException, e);
	}
}

void ChainedExceptions::d() {
	$init(ChainedExceptions);
	e();
}

void ChainedExceptions::e() {
	$init(ChainedExceptions);
	$throwNew($LowLevelException);
}

void ChainedExceptions::check($Throwable* t, $StackTraceElement* e, $String* methodName, int32_t n) {
	$init(ChainedExceptions);
	$useLocalCurrentObjectStackCache();
	if (!$nc($($nc(e)->getClassName()))->equals(ChainedExceptions::OUR_CLASS)) {
		$throwNew($RuntimeException, $$str({"Class: "_s, e}), t);
	}
	if (!$nc($($nc(e)->getMethodName()))->equals(methodName)) {
		$throwNew($RuntimeException, $$str({"Method name: "_s, e}), t);
	}
	if (!$nc($($nc(e)->getFileName()))->equals(ChainedExceptions::OUR_FILE_NAME)) {
		$throwNew($RuntimeException, $$str({"File name: "_s, e}), t);
	}
	if ($nc(e)->getLineNumber() != n) {
		$throwNew($RuntimeException, $$str({"Line number: "_s, e}), t);
	}
}

void clinit$ChainedExceptions($Class* class$) {
	$assignStatic(ChainedExceptions::OUR_FILE_NAME, "ChainedExceptions.java"_s);
	$assignStatic(ChainedExceptions::OUR_CLASS, ChainedExceptions::class$->getName());
}

ChainedExceptions::ChainedExceptions() {
}

$Class* ChainedExceptions::load$($String* name, bool initialize) {
	$loadClass(ChainedExceptions, name, initialize, &_ChainedExceptions_ClassInfo_, clinit$ChainedExceptions, allocate$ChainedExceptions);
	return class$;
}

$Class* ChainedExceptions::class$ = nullptr;