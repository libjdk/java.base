#include <ITLConstructor$AnotherRunnable.h>

#include <ITLConstructor.h>
#include <java/lang/InheritableThreadLocal.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadGroup.h>
#include <java/lang/ThreadLocal.h>
#include <jcpp.h>

using $ITLConstructor = ::ITLConstructor;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InheritableThreadLocal = ::java::lang::InheritableThreadLocal;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $ThreadGroup = ::java::lang::ThreadGroup;

$FieldInfo _ITLConstructor$AnotherRunnable_FieldInfo_[] = {
	{"threadId", "I", nullptr, $FINAL, $field(ITLConstructor$AnotherRunnable, threadId)},
	{"x", "[I", nullptr, $FINAL, $field(ITLConstructor$AnotherRunnable, x)},
	{"inherit", "Z", nullptr, $FINAL, $field(ITLConstructor$AnotherRunnable, inherit)},
	{}
};

$MethodInfo _ITLConstructor$AnotherRunnable_MethodInfo_[] = {
	{"<init>", "(I[IZ)V", nullptr, 0, $method(ITLConstructor$AnotherRunnable, init$, void, int32_t, $ints*, bool)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(ITLConstructor$AnotherRunnable, run, void)},
	{}
};

$InnerClassInfo _ITLConstructor$AnotherRunnable_InnerClassesInfo_[] = {
	{"ITLConstructor$AnotherRunnable", "ITLConstructor", "AnotherRunnable", $STATIC},
	{}
};

$ClassInfo _ITLConstructor$AnotherRunnable_ClassInfo_ = {
	$ACC_SUPER,
	"ITLConstructor$AnotherRunnable",
	"java.lang.Object",
	"java.lang.Runnable",
	_ITLConstructor$AnotherRunnable_FieldInfo_,
	_ITLConstructor$AnotherRunnable_MethodInfo_,
	nullptr,
	nullptr,
	_ITLConstructor$AnotherRunnable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"ITLConstructor"
};

$Object* allocate$ITLConstructor$AnotherRunnable($Class* clazz) {
	return $of($alloc(ITLConstructor$AnotherRunnable));
}

void ITLConstructor$AnotherRunnable::init$(int32_t threadId, $ints* x, bool inherit) {
	this->threadId = threadId;
	$set(this, x, x);
	this->inherit = inherit;
}

void ITLConstructor$AnotherRunnable::run() {
	$useLocalCurrentObjectStackCache();
	$init($ITLConstructor);
	int32_t itlValue = $nc(($cast($Integer, $($nc($ITLConstructor::n)->get()))))->intValue();
	if (this->threadId < 10 - 1) {
		$var($ThreadGroup, var$0, $($Thread::currentThread())->getThreadGroup());
		$var($Thread, child, $new($Thread, var$0, $$new(ITLConstructor$AnotherRunnable, this->threadId + 1, this->x, this->inherit), $$str({"ITLConstructor-thread-"_s, $$str((this->threadId + 1))}), 0, this->inherit));
		child->start();
		try {
			child->join();
		} catch ($InterruptedException& e) {
			$throw($$new($RuntimeException, "Interrupted"_s, e));
		}
	}
	$nc(this->x)->set(this->threadId, itlValue + 1);
}

ITLConstructor$AnotherRunnable::ITLConstructor$AnotherRunnable() {
}

$Class* ITLConstructor$AnotherRunnable::load$($String* name, bool initialize) {
	$loadClass(ITLConstructor$AnotherRunnable, name, initialize, &_ITLConstructor$AnotherRunnable_ClassInfo_, allocate$ITLConstructor$AnotherRunnable);
	return class$;
}

$Class* ITLConstructor$AnotherRunnable::class$ = nullptr;