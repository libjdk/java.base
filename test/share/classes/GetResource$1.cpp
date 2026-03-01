#include <GetResource$1.h>

#include <GetResource.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/InterruptedException.h>
#include <java/util/Properties.h>
#include <java/util/concurrent/BrokenBarrierException.h>
#include <java/util/concurrent/CyclicBarrier.h>
#include <jcpp.h>

using $GetResource = ::GetResource;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Properties = ::java::util::Properties;
using $BrokenBarrierException = ::java::util::concurrent::BrokenBarrierException;
using $CyclicBarrier = ::java::util::concurrent::CyclicBarrier;

$FieldInfo _GetResource$1_FieldInfo_[] = {
	{"this$0", "LGetResource;", nullptr, $FINAL | $SYNTHETIC, $field(GetResource$1, this$0)},
	{}
};

$MethodInfo _GetResource$1_MethodInfo_[] = {
	{"<init>", "(LGetResource;)V", nullptr, 0, $method(GetResource$1, init$, void, $GetResource*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(GetResource$1, run, void)},
	{}
};

$EnclosingMethodInfo _GetResource$1_EnclosingMethodInfo_ = {
	"GetResource",
	"<init>",
	"()V"
};

$InnerClassInfo _GetResource$1_InnerClassesInfo_[] = {
	{"GetResource$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GetResource$1_ClassInfo_ = {
	$ACC_SUPER,
	"GetResource$1",
	"java.lang.Thread",
	nullptr,
	_GetResource$1_FieldInfo_,
	_GetResource$1_MethodInfo_,
	nullptr,
	&_GetResource$1_EnclosingMethodInfo_,
	_GetResource$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"GetResource"
};

$Object* allocate$GetResource$1($Class* clazz) {
	return $of($alloc(GetResource$1));
}

void GetResource$1::init$($GetResource* this$0) {
	$set(this, this$0, this$0);
	$Thread::init$();
}

void GetResource$1::run() {
	$var($Properties, prop, $System::getProperties());
	$synchronized(prop) {
		$nc($System::out)->println("Thread 1 ready"_s);
		try {
			$nc(this->this$0->go)->await();
			$nc(prop)->put("property"_s, "value"_s);
			prop->store(static_cast<$OutputStream*>($System::out), ""_s);
			$nc(this->this$0->done)->await();
		} catch ($InterruptedException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		} catch ($BrokenBarrierException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		} catch ($IOException& e) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
	$nc($System::out)->println("Thread 1 exits"_s);
}

GetResource$1::GetResource$1() {
}

$Class* GetResource$1::load$($String* name, bool initialize) {
	$loadClass(GetResource$1, name, initialize, &_GetResource$1_ClassInfo_, allocate$GetResource$1);
	return class$;
}

$Class* GetResource$1::class$ = nullptr;