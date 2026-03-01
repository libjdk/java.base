#include <p1/A.h>

#include <java/lang/IllegalAccessException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <jcpp.h>

#undef A

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;

namespace p1 {

$FieldInfo _A_FieldInfo_[] = {
	{"lock", "Ljava/lang/Object;", nullptr, $STATIC | $FINAL, $staticField(A, lock)},
	{}
};

$MethodInfo _A_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(A, init$, void)},
	{}
};

$ClassInfo _A_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"p1.A",
	"java.lang.Object",
	nullptr,
	_A_FieldInfo_,
	_A_MethodInfo_
};

$Object* allocate$A($Class* clazz) {
	return $of($alloc(A));
}

$Object* A::lock = nullptr;

void A::init$() {
}

void clinit$A($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$nc($($MethodHandles::lookup()))->ensureInitialized(A::class$);
			$assignStatic(A::lock, $new($Object));
		} catch ($IllegalAccessException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
}

A::A() {
}

$Class* A::load$($String* name, bool initialize) {
	$loadClass(A, name, initialize, &_A_ClassInfo_, clinit$A, allocate$A);
	return class$;
}

$Class* A::class$ = nullptr;

} // p1