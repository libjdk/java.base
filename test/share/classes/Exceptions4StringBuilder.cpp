#include <Exceptions4StringBuilder.h>

#include <Exceptions4StringBuilder$1.h>
#include <Exceptions4StringBuilder$2.h>
#include <Exceptions4StringBuilder$3.h>
#include <Exceptions4StringBuilder$4.h>
#include <Exceptions4StringBuilder$5.h>
#include <Exceptions4StringBuilder$6.h>
#include <Exceptions4StringBuilder$7.h>
#include <Exceptions4StringBuilder$8.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/Runnable.h>
#include <java/lang/StringIndexOutOfBoundsException.h>
#include <jcpp.h>

using $Exceptions4StringBuilder$1 = ::Exceptions4StringBuilder$1;
using $Exceptions4StringBuilder$2 = ::Exceptions4StringBuilder$2;
using $Exceptions4StringBuilder$3 = ::Exceptions4StringBuilder$3;
using $Exceptions4StringBuilder$4 = ::Exceptions4StringBuilder$4;
using $Exceptions4StringBuilder$5 = ::Exceptions4StringBuilder$5;
using $Exceptions4StringBuilder$6 = ::Exceptions4StringBuilder$6;
using $Exceptions4StringBuilder$7 = ::Exceptions4StringBuilder$7;
using $Exceptions4StringBuilder$8 = ::Exceptions4StringBuilder$8;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NegativeArraySizeException = ::java::lang::NegativeArraySizeException;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringIndexOutOfBoundsException = ::java::lang::StringIndexOutOfBoundsException;

$FieldInfo _Exceptions4StringBuilder_FieldInfo_[] = {
	{"ok", "Z", nullptr, $PRIVATE | $STATIC, $staticField(Exceptions4StringBuilder, ok)},
	{}
};

$MethodInfo _Exceptions4StringBuilder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Exceptions4StringBuilder, init$, void)},
	{"fail", "(Ljava/lang/Throwable;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Exceptions4StringBuilder, fail, void, $Throwable*, $String*, $Throwable*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Exceptions4StringBuilder, main, void, $StringArray*)},
	{"pass", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Exceptions4StringBuilder, pass, void, $String*)},
	{"tryCatch", "(Ljava/lang/String;Ljava/lang/Throwable;Ljava/lang/Runnable;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Exceptions4StringBuilder, tryCatch, void, $String*, $Throwable*, $Runnable*)},
	{}
};

$InnerClassInfo _Exceptions4StringBuilder_InnerClassesInfo_[] = {
	{"Exceptions4StringBuilder$8", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$7", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$6", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$5", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$4", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$3", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$2", nullptr, nullptr, 0},
	{"Exceptions4StringBuilder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Exceptions4StringBuilder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Exceptions4StringBuilder",
	"java.lang.Object",
	nullptr,
	_Exceptions4StringBuilder_FieldInfo_,
	_Exceptions4StringBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_Exceptions4StringBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Exceptions4StringBuilder$8,Exceptions4StringBuilder$7,Exceptions4StringBuilder$6,Exceptions4StringBuilder$5,Exceptions4StringBuilder$4,Exceptions4StringBuilder$3,Exceptions4StringBuilder$2,Exceptions4StringBuilder$1"
};

$Object* allocate$Exceptions4StringBuilder($Class* clazz) {
	return $of($alloc(Exceptions4StringBuilder));
}

bool Exceptions4StringBuilder::ok = false;

void Exceptions4StringBuilder::init$() {
}

void Exceptions4StringBuilder::fail($Throwable* ex, $String* s, $Throwable* got) {
	$init(Exceptions4StringBuilder);
	$useLocalCurrentObjectStackCache();
	Exceptions4StringBuilder::ok = false;
	$var($String, var$7, $$str({"expected "_s, $($nc($of(ex))->getClass()->getName()), ": "_s}));
	$var($String, var$6, $$concat(var$7, $(ex->getMessage())));
	$var($String, var$5, $$concat(var$6, " for "_s));
	$var($String, var$4, $$concat(var$5, s));
	$var($String, var$3, $$concat(var$4, " got "_s));
	$var($String, var$2, $$concat(var$3, $($nc($of(got))->getClass()->getName())));
	$var($String, var$1, $$concat(var$2, ": "_s));
	$var($String, var$0, $$concat(var$1, $(got->getMessage())));
	$nc($System::err)->println($$concat(var$0, " - FAILED"_s));
}

void Exceptions4StringBuilder::pass($String* s) {
	$init(Exceptions4StringBuilder);
	$nc($System::out)->println($$str({s, " -- OK"_s}));
}

void Exceptions4StringBuilder::tryCatch($String* s, $Throwable* ex, $Runnable* thunk) {
	$init(Exceptions4StringBuilder);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, nullptr);
	try {
		$nc(thunk)->run();
	} catch ($Throwable& x) {
		if ($nc($of(ex))->getClass()->isAssignableFrom($of(x)->getClass())) {
			$assign(t, x);
		} else {
			x->printStackTrace();
		}
	}
	if ((t == nullptr) && (ex != nullptr)) {
		fail(ex, s, t);
	}
	$var($String, msg, ex == nullptr ? ($String*)nullptr : $nc(ex)->getMessage());
	if ((msg != nullptr) && !msg->equals($($nc(t)->getMessage()))) {
		fail(ex, s, t);
	} else {
		pass(s);
	}
}

void Exceptions4StringBuilder::main($StringArray* args) {
	$init(Exceptions4StringBuilder);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println("StringBuilder()"_s);
	tryCatch("  no args"_s, nullptr, $$new($Exceptions4StringBuilder$1));
	$nc($System::out)->println("StringBuilder(int length)"_s);
	tryCatch("  1"_s, nullptr, $$new($Exceptions4StringBuilder$2));
	$var($String, var$0, "  -1"_s);
	$var($Throwable, var$1, static_cast<$Throwable*>($new($NegativeArraySizeException)));
	tryCatch(var$0, var$1, $$new($Exceptions4StringBuilder$3));
	$nc($System::out)->println("StringBuilder(String str)"_s);
	$var($String, var$2, "  null"_s);
	$var($Throwable, var$3, static_cast<$Throwable*>($new($NullPointerException)));
	tryCatch(var$2, var$3, $$new($Exceptions4StringBuilder$4));
	tryCatch("  foo"_s, nullptr, $$new($Exceptions4StringBuilder$5));
	$nc($System::out)->println("StringBuilder.replace(int start, int end, String str)"_s);
	$var($String, var$4, "  -1, 2, \" \""_s);
	$var($Throwable, var$5, static_cast<$Throwable*>($new($StringIndexOutOfBoundsException, "start -1, end 2, length 7"_s)));
	tryCatch(var$4, var$5, $$new($Exceptions4StringBuilder$6));
	$var($String, var$6, "  7, 8, \" \""_s);
	$var($Throwable, var$7, static_cast<$Throwable*>($new($StringIndexOutOfBoundsException, "start 7, end 6, length 6"_s)));
	tryCatch(var$6, var$7, $$new($Exceptions4StringBuilder$7));
	$var($String, var$8, "  2, 1, \" \""_s);
	$var($Throwable, var$9, static_cast<$Throwable*>($new($StringIndexOutOfBoundsException, "start 2, end 1, length 7"_s)));
	tryCatch(var$8, var$9, $$new($Exceptions4StringBuilder$8));
	if (!Exceptions4StringBuilder::ok) {
		$throwNew($RuntimeException, "Some tests FAILED"_s);
	} else {
		$nc($System::out)->println("All tests PASSED"_s);
	}
}

void clinit$Exceptions4StringBuilder($Class* class$) {
	Exceptions4StringBuilder::ok = true;
}

Exceptions4StringBuilder::Exceptions4StringBuilder() {
}

$Class* Exceptions4StringBuilder::load$($String* name, bool initialize) {
	$loadClass(Exceptions4StringBuilder, name, initialize, &_Exceptions4StringBuilder_ClassInfo_, clinit$Exceptions4StringBuilder, allocate$Exceptions4StringBuilder);
	return class$;
}

$Class* Exceptions4StringBuilder::class$ = nullptr;