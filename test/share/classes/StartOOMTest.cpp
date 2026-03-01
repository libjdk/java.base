#include <StartOOMTest.h>

#include <StartOOMTest$SleepRunnable.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadGroup.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $StartOOMTest$SleepRunnable = ::StartOOMTest$SleepRunnable;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _StartOOMTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(StartOOMTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(StartOOMTest, main, void, $StringArray*), "java.lang.Throwable"},
	{}
};

$InnerClassInfo _StartOOMTest_InnerClassesInfo_[] = {
	{"StartOOMTest$SleepRunnable", "StartOOMTest", "SleepRunnable", $STATIC},
	{}
};

$ClassInfo _StartOOMTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"StartOOMTest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_StartOOMTest_MethodInfo_,
	nullptr,
	nullptr,
	_StartOOMTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"StartOOMTest$SleepRunnable"
};

$Object* allocate$StartOOMTest($Class* clazz) {
	return $of($alloc(StartOOMTest));
}

void StartOOMTest::init$() {
}

void StartOOMTest::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($Runnable, r, $new($StartOOMTest$SleepRunnable));
	$var($ThreadGroup, tg, $new($ThreadGroup, "buggy"_s));
	$var($List, threads, $new($ArrayList));
	$var($Thread, failedThread, nullptr);
	int32_t i = 0;
	for (i = 0;; ++i) {
		$var($Thread, t, $new($Thread, tg, r));
		try {
			t->start();
			threads->add(t);
		} catch ($Throwable& x) {
			$assign(failedThread, t);
			$nc($System::out)->println($of(x));
			$nc($System::out)->println(i);
			break;
		}
	}
	int32_t j = 0;
	{
		$var($Iterator, i$, threads->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Thread, t, $cast($Thread, i$->next()));
			$nc(t)->interrupt();
		}
	}
	while (tg->activeCount() > i / 2) {
		$Thread::yield();
	}
	$nc(failedThread)->start();
	failedThread->interrupt();
	{
		$var($Iterator, i$, threads->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Thread, t, $cast($Thread, i$->next()));
			$nc(t)->join();
		}
	}
	failedThread->join();
	try {
		$Thread::sleep(1000);
	} catch ($Throwable& ignore) {
	}
	int32_t activeCount = tg->activeCount();
	$nc($System::out)->println($$str({"activeCount = "_s, $$str(activeCount)}));
	if (activeCount > 0) {
		$throwNew($RuntimeException, "Failed: there  should be no active Threads in the group"_s);
	}
}

StartOOMTest::StartOOMTest() {
}

$Class* StartOOMTest::load$($String* name, bool initialize) {
	$loadClass(StartOOMTest, name, initialize, &_StartOOMTest_ClassInfo_, allocate$StartOOMTest);
	return class$;
}

$Class* StartOOMTest::class$ = nullptr;