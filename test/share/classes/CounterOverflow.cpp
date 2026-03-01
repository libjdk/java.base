#include <CounterOverflow.h>

#include <java/io/DataOutputStream.h>
#include <java/io/OutputStream.h>
#include <jcpp.h>

#undef MAX_VALUE

using $DataOutputStream = ::java::io::DataOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _CounterOverflow_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(CounterOverflow, init$, void, $OutputStream*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CounterOverflow, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _CounterOverflow_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"CounterOverflow",
	"java.io.DataOutputStream",
	nullptr,
	nullptr,
	_CounterOverflow_MethodInfo_
};

$Object* allocate$CounterOverflow($Class* clazz) {
	return $of($alloc(CounterOverflow));
}

void CounterOverflow::init$($OutputStream* out) {
	$DataOutputStream::init$(out);
	this->written = $Integer::MAX_VALUE;
}

void CounterOverflow::main($StringArray* args) {
	$init(CounterOverflow);
	$var(CounterOverflow, dataOut, $new(CounterOverflow, $System::out));
	dataOut->writeByte(1);
	if (dataOut->size() < 0) {
		$throwNew($Exception, "Internal counter less than 0."_s);
	}
}

CounterOverflow::CounterOverflow() {
}

$Class* CounterOverflow::load$($String* name, bool initialize) {
	$loadClass(CounterOverflow, name, initialize, &_CounterOverflow_ClassInfo_, allocate$CounterOverflow);
	return class$;
}

$Class* CounterOverflow::class$ = nullptr;