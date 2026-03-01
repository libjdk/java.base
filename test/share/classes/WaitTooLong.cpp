#include <WaitTooLong.h>

#include <java/lang/IllegalMonitorStateException.h>
#include <java/lang/InterruptedException.h>
#include <jcpp.h>

#undef MAX_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalMonitorStateException = ::java::lang::IllegalMonitorStateException;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;

$MethodInfo _WaitTooLong_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WaitTooLong, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(WaitTooLong, main, void, $StringArray*)},
	{"test", "(I)V", nullptr, $STATIC, $staticMethod(WaitTooLong, test, void, int32_t)},
	{}
};

$ClassInfo _WaitTooLong_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"WaitTooLong",
	"java.lang.Object",
	nullptr,
	nullptr,
	_WaitTooLong_MethodInfo_
};

$Object* allocate$WaitTooLong($Class* clazz) {
	return $of($alloc(WaitTooLong));
}

void WaitTooLong::init$() {
}

void WaitTooLong::main($StringArray* args) {
	test(0);
	test(1);
	test(0x0007A120);
	test(0x000F423F);
}

void WaitTooLong::test(int32_t nanos) {
	try {
		$load(WaitTooLong);
		$of(WaitTooLong::class$)->wait($Long::MAX_VALUE, nanos);
	} catch ($IllegalMonitorStateException& expected) {
	} catch ($IllegalArgumentException& unexpected) {
		$throwNew($RuntimeException, "Unexpected"_s, unexpected);
	} catch ($InterruptedException& unexpected) {
		$throwNew($RuntimeException, "Unexpected"_s, unexpected);
	}
}

WaitTooLong::WaitTooLong() {
}

$Class* WaitTooLong::load$($String* name, bool initialize) {
	$loadClass(WaitTooLong, name, initialize, &_WaitTooLong_ClassInfo_, allocate$WaitTooLong);
	return class$;
}

$Class* WaitTooLong::class$ = nullptr;