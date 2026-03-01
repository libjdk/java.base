#include <MultiThreadStackWalk.h>

#include <MultiThreadStackWalk$Call$WalkType.h>
#include <MultiThreadStackWalk$Call.h>
#include <MultiThreadStackWalk$Env.h>
#include <MultiThreadStackWalk$Test.h>
#include <MultiThreadStackWalk$WalkThread.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/util/AbstractSet.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <jcpp.h>

using $MultiThreadStackWalk$Call = ::MultiThreadStackWalk$Call;
using $MultiThreadStackWalk$Call$WalkType = ::MultiThreadStackWalk$Call$WalkType;
using $MultiThreadStackWalk$Env = ::MultiThreadStackWalk$Env;
using $MultiThreadStackWalk$Test = ::MultiThreadStackWalk$Test;
using $MultiThreadStackWalk$WalkThread = ::MultiThreadStackWalk$WalkThread;
using $MultiThreadStackWalk$WalkThreadArray = $Array<MultiThreadStackWalk$WalkThread>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AbstractSet = ::java::util::AbstractSet;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;

$FieldInfo _MultiThreadStackWalk_FieldInfo_[] = {
	{"infrastructureClasses", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC, $staticField(MultiThreadStackWalk, infrastructureClasses)},
	{"streamPipelines", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Class<*>;>;", $STATIC | $FINAL, $staticField(MultiThreadStackWalk, streamPipelines)},
	{}
};

$MethodInfo _MultiThreadStackWalk_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MultiThreadStackWalk, init$, void)},
	{"checkTest", "(LMultiThreadStackWalk$Env;LMultiThreadStackWalk$Test;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(MultiThreadStackWalk, checkTest, void, $MultiThreadStackWalk$Env*, $MultiThreadStackWalk$Test*)},
	{"classForName", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $STATIC, $staticMethod(MultiThreadStackWalk, classForName, $Class*, $String*)},
	{"isStreamPipeline", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(MultiThreadStackWalk, isStreamPipeline, bool, $Class*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(MultiThreadStackWalk, main, void, $StringArray*), "java.lang.Throwable"},
	{"runTest", "(LMultiThreadStackWalk$Test;II)LMultiThreadStackWalk$Env;", nullptr, $PUBLIC | $STATIC, $staticMethod(MultiThreadStackWalk, runTest, $MultiThreadStackWalk$Env*, $MultiThreadStackWalk$Test*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _MultiThreadStackWalk_InnerClassesInfo_[] = {
	{"MultiThreadStackWalk$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"MultiThreadStackWalk$WalkThread", "MultiThreadStackWalk", "WalkThread", $STATIC},
	{"MultiThreadStackWalk$Test", "MultiThreadStackWalk", "Test", $PUBLIC | $STATIC},
	{"MultiThreadStackWalk$Marker", "MultiThreadStackWalk", "Marker", $PUBLIC | $STATIC},
	{"MultiThreadStackWalk$Call", "MultiThreadStackWalk", "Call", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"MultiThreadStackWalk$Env", "MultiThreadStackWalk", "Env", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _MultiThreadStackWalk_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MultiThreadStackWalk",
	"java.lang.Object",
	nullptr,
	_MultiThreadStackWalk_FieldInfo_,
	_MultiThreadStackWalk_MethodInfo_,
	nullptr,
	nullptr,
	_MultiThreadStackWalk_InnerClassesInfo_,
	nullptr,
	nullptr,
	"MultiThreadStackWalk$1,MultiThreadStackWalk$WalkThread,MultiThreadStackWalk$Test,MultiThreadStackWalk$Marker,MultiThreadStackWalk$Call,MultiThreadStackWalk$Call$WalkType,MultiThreadStackWalk$Env"
};

$Object* allocate$MultiThreadStackWalk($Class* clazz) {
	return $of($alloc(MultiThreadStackWalk));
}

$Set* MultiThreadStackWalk::infrastructureClasses = nullptr;
$List* MultiThreadStackWalk::streamPipelines = nullptr;

void MultiThreadStackWalk::init$() {
}

$Class* MultiThreadStackWalk::classForName($String* name) {
	$init(MultiThreadStackWalk);
	$beforeCallerSensitive();
	try {
		return $Class::forName(name);
	} catch ($ClassNotFoundException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool MultiThreadStackWalk::isStreamPipeline($Class* clazz) {
	$init(MultiThreadStackWalk);
	{
		$var($Iterator, i$, $nc(MultiThreadStackWalk::streamPipelines)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* c = $cast($Class, i$->next());
			{
				if ($nc(c)->isAssignableFrom(clazz)) {
					return true;
				}
			}
		}
	}
	return false;
}

$MultiThreadStackWalk$Env* MultiThreadStackWalk::runTest($MultiThreadStackWalk$Test* test, int32_t total, int32_t markAt) {
	$init(MultiThreadStackWalk);
	$var($MultiThreadStackWalk$Env, env, $new($MultiThreadStackWalk$Env, total, markAt, $nc(test)->debug));
	$nc(test)->call(env, test, total, 0, markAt);
	return env;
}

void MultiThreadStackWalk::checkTest($MultiThreadStackWalk$Env* env, $MultiThreadStackWalk$Test* test) {
	$init(MultiThreadStackWalk);
	$useLocalCurrentObjectStackCache();
	$var($String, threadName, $($Thread::currentThread())->getName());
	$nc($System::out)->println($$str({threadName, ": Marker called: "_s, $$str($nc($nc(env)->markerCalled)->get())}));
	$nc($System::out)->println($$str({threadName, ": Max reached: "_s, $$str($nc($nc(env)->maxReached)->get())}));
	$nc($System::out)->println($$str({threadName, ": Frames consumed: "_s, $$str($nc($nc(env)->frameCounter)->get())}));
	if ($nc($nc(env)->markerCalled)->get() == 0) {
		$throwNew($RuntimeException, $$str({$($($Thread::currentThread())->getName()), ": Marker was not called."_s}));
	}
	if ($nc($nc(env)->markerCalled)->get() > 1) {
		$var($String, var$0, $$str({$($($Thread::currentThread())->getName()), ": Marker was called more than once: "_s}));
		$throwNew($RuntimeException, $$concat(var$0, $$str($nc(env->maxReached)->get())));
	}
	if (!$nc($nc(env)->unexpected)->isEmpty()) {
		$nc($System::out)->flush();
		$nc($System::err)->println($$str({"Encountered some unexpected infrastructure classes below \'main\': "_s, env->unexpected}));
	}
	if ($nc($nc(env)->maxReached)->get() == 0) {
		$throwNew($RuntimeException, $$str({$($($Thread::currentThread())->getName()), ": max not reached"_s}));
	}
	if ($nc($nc(env)->maxReached)->get() > 1) {
		$var($String, var$1, $$str({$($($Thread::currentThread())->getName()), ": max was reached more than once: "_s}));
		$throwNew($RuntimeException, $$concat(var$1, $$str($nc(env->maxReached)->get())));
	}
}

void MultiThreadStackWalk::main($StringArray* args) {
	$init(MultiThreadStackWalk);
	$useLocalCurrentObjectStackCache();
	$var($MultiThreadStackWalk$WalkThreadArray, threads, $new($MultiThreadStackWalk$WalkThreadArray, $($MultiThreadStackWalk$Call$WalkType::values())->length * 3));
	$var($Throwable, failed, nullptr);
	for (int32_t i = 0; i < threads->length; ++i) {
		$var($MultiThreadStackWalk$Test, test, $new($MultiThreadStackWalk$Test, $($MultiThreadStackWalk$Call$WalkType::values())->get($mod(i, $($MultiThreadStackWalk$Call$WalkType::values())->length))));
		threads->set(i, $$new($MultiThreadStackWalk$WalkThread, test));
	}
	for (int32_t i = 0; i < threads->length; ++i) {
		$nc(threads->get(i))->start();
	}
	for (int32_t i = 0; i < threads->length; ++i) {
		$nc(threads->get(i))->join();
		if (failed == nullptr) {
			$assign(failed, $nc(threads->get(i))->failed);
		} else if ($nc(threads->get(i))->failed == nullptr) {
			$nc(failed)->addSuppressed($nc(threads->get(i))->failed);
		}
	}
	if (failed != nullptr) {
		$throw(failed);
	}
}

void clinit$MultiThreadStackWalk($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(MultiThreadStackWalk::infrastructureClasses, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, $(static_cast<$Collection*>($Arrays::asList($$new($StringArray, {
		"jdk.internal.reflect.NativeMethodAccessorImpl"_s,
		"jdk.internal.reflect.DelegatingMethodAccessorImpl"_s,
		"java.lang.reflect.Method"_s,
		"com.sun.javatest.regtest.MainWrapper$MainThread"_s,
		"java.lang.Thread"_s
	}))))))));
	$assignStatic(MultiThreadStackWalk::streamPipelines, $Arrays::asList($$new($ClassArray, {
		MultiThreadStackWalk::classForName("java.util.stream.AbstractPipeline"_s),
		MultiThreadStackWalk::classForName("java.util.stream.TerminalOp"_s)
	})));
}

MultiThreadStackWalk::MultiThreadStackWalk() {
}

$Class* MultiThreadStackWalk::load$($String* name, bool initialize) {
	$loadClass(MultiThreadStackWalk, name, initialize, &_MultiThreadStackWalk_ClassInfo_, clinit$MultiThreadStackWalk, allocate$MultiThreadStackWalk);
	return class$;
}

$Class* MultiThreadStackWalk::class$ = nullptr;