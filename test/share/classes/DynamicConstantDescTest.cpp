#include <DynamicConstantDescTest.h>

#include <DynamicConstantDescTest$InvokeOfCanonical.h>
#include <DynamicConstantDescTest$Task.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/CountDownLatch.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/Future.h>
#include <jcpp.h>

using $DynamicConstantDescTest$InvokeOfCanonical = ::DynamicConstantDescTest$InvokeOfCanonical;
using $DynamicConstantDescTest$Task = ::DynamicConstantDescTest$Task;
using $FutureArray = $Array<::java::util::concurrent::Future>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Callable = ::java::util::concurrent::Callable;
using $CountDownLatch = ::java::util::concurrent::CountDownLatch;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Executors = ::java::util::concurrent::Executors;
using $Future = ::java::util::concurrent::Future;

$MethodInfo _DynamicConstantDescTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DynamicConstantDescTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(DynamicConstantDescTest, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _DynamicConstantDescTest_InnerClassesInfo_[] = {
	{"DynamicConstantDescTest$InvokeOfCanonical", "DynamicConstantDescTest", "InvokeOfCanonical", $PRIVATE | $STATIC},
	{"DynamicConstantDescTest$MyEnum", "DynamicConstantDescTest", "MyEnum", $STATIC | $FINAL | $ENUM},
	{"DynamicConstantDescTest$Task", "DynamicConstantDescTest", "Task", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DynamicConstantDescTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"DynamicConstantDescTest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_DynamicConstantDescTest_MethodInfo_,
	nullptr,
	nullptr,
	_DynamicConstantDescTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"DynamicConstantDescTest$InvokeOfCanonical,DynamicConstantDescTest$MyEnum,DynamicConstantDescTest$Task"
};

$Object* allocate$DynamicConstantDescTest($Class* clazz) {
	return $of($alloc(DynamicConstantDescTest));
}

void DynamicConstantDescTest::init$() {
}

void DynamicConstantDescTest::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($CountDownLatch, taskTriggerLatch, $new($CountDownLatch, 4));
	$var($List, tasks, $new($ArrayList));
	tasks->add($$new($DynamicConstantDescTest$Task, "java.lang.constant.DynamicConstantDesc"_s, taskTriggerLatch));
	tasks->add($$new($DynamicConstantDescTest$InvokeOfCanonical, taskTriggerLatch));
	tasks->add($$new($DynamicConstantDescTest$Task, "java.lang.constant.ConstantDescs"_s, taskTriggerLatch));
	tasks->add($$new($DynamicConstantDescTest$InvokeOfCanonical, taskTriggerLatch));
	$var($ExecutorService, executor, $Executors::newFixedThreadPool(tasks->size()));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($FutureArray, results, $new($FutureArray, tasks->size()));
			int32_t i = 0;
			{
				$var($Iterator, i$, tasks->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Callable, task, $cast($Callable, i$->next()));
					{
						results->set(i++, $($nc(executor)->submit(task)));
					}
				}
			}
			for (i = 0; i < tasks->size(); ++i) {
				$nc(results->get(i))->get();
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(executor)->shutdownNow();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

DynamicConstantDescTest::DynamicConstantDescTest() {
}

$Class* DynamicConstantDescTest::load$($String* name, bool initialize) {
	$loadClass(DynamicConstantDescTest, name, initialize, &_DynamicConstantDescTest_ClassInfo_, allocate$DynamicConstantDescTest);
	return class$;
}

$Class* DynamicConstantDescTest::class$ = nullptr;