#include <java/util/concurrent/Executors.h>

#include <java/lang/Runnable.h>
#include <java/lang/Runtime.h>
#include <java/lang/Thread$UncaughtExceptionHandler.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/concurrent/BlockingQueue.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Executors$1.h>
#include <java/util/concurrent/Executors$2.h>
#include <java/util/concurrent/Executors$DefaultThreadFactory.h>
#include <java/util/concurrent/Executors$DelegatedExecutorService.h>
#include <java/util/concurrent/Executors$DelegatedScheduledExecutorService.h>
#include <java/util/concurrent/Executors$FinalizableDelegatedExecutorService.h>
#include <java/util/concurrent/Executors$PrivilegedCallable.h>
#include <java/util/concurrent/Executors$PrivilegedCallableUsingCurrentClassLoader.h>
#include <java/util/concurrent/Executors$PrivilegedThreadFactory.h>
#include <java/util/concurrent/Executors$RunnableAdapter.h>
#include <java/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/LinkedBlockingQueue.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/SynchronousQueue.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/ThreadPoolExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef MILLISECONDS
#undef SECONDS

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $Runtime = ::java::lang::Runtime;
using $Thread$UncaughtExceptionHandler = ::java::lang::Thread$UncaughtExceptionHandler;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $BlockingQueue = ::java::util::concurrent::BlockingQueue;
using $Callable = ::java::util::concurrent::Callable;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Executors$1 = ::java::util::concurrent::Executors$1;
using $Executors$2 = ::java::util::concurrent::Executors$2;
using $Executors$DefaultThreadFactory = ::java::util::concurrent::Executors$DefaultThreadFactory;
using $Executors$DelegatedExecutorService = ::java::util::concurrent::Executors$DelegatedExecutorService;
using $Executors$DelegatedScheduledExecutorService = ::java::util::concurrent::Executors$DelegatedScheduledExecutorService;
using $Executors$FinalizableDelegatedExecutorService = ::java::util::concurrent::Executors$FinalizableDelegatedExecutorService;
using $Executors$PrivilegedCallable = ::java::util::concurrent::Executors$PrivilegedCallable;
using $Executors$PrivilegedCallableUsingCurrentClassLoader = ::java::util::concurrent::Executors$PrivilegedCallableUsingCurrentClassLoader;
using $Executors$PrivilegedThreadFactory = ::java::util::concurrent::Executors$PrivilegedThreadFactory;
using $Executors$RunnableAdapter = ::java::util::concurrent::Executors$RunnableAdapter;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $LinkedBlockingQueue = ::java::util::concurrent::LinkedBlockingQueue;
using $ScheduledExecutorService = ::java::util::concurrent::ScheduledExecutorService;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $SynchronousQueue = ::java::util::concurrent::SynchronousQueue;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $ThreadPoolExecutor = ::java::util::concurrent::ThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;

namespace java {
	namespace util {
		namespace concurrent {

$NamedAttribute Executors_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Executors_MethodAnnotations_privilegedCallable18[] = {
	{"Ljava/lang/Deprecated;", Executors_Attribute_var$0},
	{}
};

$NamedAttribute Executors_Attribute_var$1[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Executors_MethodAnnotations_privilegedCallableUsingCurrentClassLoader19[] = {
	{"Ljava/lang/Deprecated;", Executors_Attribute_var$1},
	{}
};

$NamedAttribute Executors_Attribute_var$2[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Executors_MethodAnnotations_privilegedThreadFactory20[] = {
	{"Ljava/lang/Deprecated;", Executors_Attribute_var$2},
	{}
};

$MethodInfo _Executors_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Executors, init$, void)},
	{"callable", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/Callable;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/Callable<TT;>;", $PUBLIC | $STATIC, $staticMethod(Executors, callable, $Callable*, $Runnable*, Object$*)},
	{"callable", "(Ljava/lang/Runnable;)Ljava/util/concurrent/Callable;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/Callable<Ljava/lang/Object;>;", $PUBLIC | $STATIC, $staticMethod(Executors, callable, $Callable*, $Runnable*)},
	{"callable", "(Ljava/security/PrivilegedAction;)Ljava/util/concurrent/Callable;", "(Ljava/security/PrivilegedAction<*>;)Ljava/util/concurrent/Callable<Ljava/lang/Object;>;", $PUBLIC | $STATIC, $staticMethod(Executors, callable, $Callable*, $PrivilegedAction*)},
	{"callable", "(Ljava/security/PrivilegedExceptionAction;)Ljava/util/concurrent/Callable;", "(Ljava/security/PrivilegedExceptionAction<*>;)Ljava/util/concurrent/Callable<Ljava/lang/Object;>;", $PUBLIC | $STATIC, $staticMethod(Executors, callable, $Callable*, $PrivilegedExceptionAction*)},
	{"defaultThreadFactory", "()Ljava/util/concurrent/ThreadFactory;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, defaultThreadFactory, $ThreadFactory*)},
	{"newCachedThreadPool", "()Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newCachedThreadPool, $ExecutorService*)},
	{"newCachedThreadPool", "(Ljava/util/concurrent/ThreadFactory;)Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newCachedThreadPool, $ExecutorService*, $ThreadFactory*)},
	{"newFixedThreadPool", "(I)Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newFixedThreadPool, $ExecutorService*, int32_t)},
	{"newFixedThreadPool", "(ILjava/util/concurrent/ThreadFactory;)Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newFixedThreadPool, $ExecutorService*, int32_t, $ThreadFactory*)},
	{"newScheduledThreadPool", "(I)Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newScheduledThreadPool, $ScheduledExecutorService*, int32_t)},
	{"newScheduledThreadPool", "(ILjava/util/concurrent/ThreadFactory;)Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newScheduledThreadPool, $ScheduledExecutorService*, int32_t, $ThreadFactory*)},
	{"newSingleThreadExecutor", "()Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newSingleThreadExecutor, $ExecutorService*)},
	{"newSingleThreadExecutor", "(Ljava/util/concurrent/ThreadFactory;)Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newSingleThreadExecutor, $ExecutorService*, $ThreadFactory*)},
	{"newSingleThreadScheduledExecutor", "()Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newSingleThreadScheduledExecutor, $ScheduledExecutorService*)},
	{"newSingleThreadScheduledExecutor", "(Ljava/util/concurrent/ThreadFactory;)Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newSingleThreadScheduledExecutor, $ScheduledExecutorService*, $ThreadFactory*)},
	{"newWorkStealingPool", "(I)Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newWorkStealingPool, $ExecutorService*, int32_t)},
	{"newWorkStealingPool", "()Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, newWorkStealingPool, $ExecutorService*)},
	{"privilegedCallable", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/Callable;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/Callable<TT;>;", $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(Executors, privilegedCallable, $Callable*, $Callable*), nullptr, nullptr, _Executors_MethodAnnotations_privilegedCallable18},
	{"privilegedCallableUsingCurrentClassLoader", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/Callable;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/Callable<TT;>;", $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(Executors, privilegedCallableUsingCurrentClassLoader, $Callable*, $Callable*), nullptr, nullptr, _Executors_MethodAnnotations_privilegedCallableUsingCurrentClassLoader19},
	{"privilegedThreadFactory", "()Ljava/util/concurrent/ThreadFactory;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(Executors, privilegedThreadFactory, $ThreadFactory*), nullptr, nullptr, _Executors_MethodAnnotations_privilegedThreadFactory20},
	{"unconfigurableExecutorService", "(Ljava/util/concurrent/ExecutorService;)Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, unconfigurableExecutorService, $ExecutorService*, $ExecutorService*)},
	{"unconfigurableScheduledExecutorService", "(Ljava/util/concurrent/ScheduledExecutorService;)Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PUBLIC | $STATIC, $staticMethod(Executors, unconfigurableScheduledExecutorService, $ScheduledExecutorService*, $ScheduledExecutorService*)},
	{}
};

$InnerClassInfo _Executors_InnerClassesInfo_[] = {
	{"java.util.concurrent.Executors$DelegatedScheduledExecutorService", "java.util.concurrent.Executors", "DelegatedScheduledExecutorService", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$FinalizableDelegatedExecutorService", "java.util.concurrent.Executors", "FinalizableDelegatedExecutorService", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$DelegatedExecutorService", "java.util.concurrent.Executors", "DelegatedExecutorService", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$PrivilegedThreadFactory", "java.util.concurrent.Executors", "PrivilegedThreadFactory", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$DefaultThreadFactory", "java.util.concurrent.Executors", "DefaultThreadFactory", $PRIVATE | $STATIC},
	{"java.util.concurrent.Executors$PrivilegedCallableUsingCurrentClassLoader", "java.util.concurrent.Executors", "PrivilegedCallableUsingCurrentClassLoader", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.Executors$PrivilegedCallable", "java.util.concurrent.Executors", "PrivilegedCallable", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.Executors$RunnableAdapter", "java.util.concurrent.Executors", "RunnableAdapter", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.Executors$2", nullptr, nullptr, 0},
	{"java.util.concurrent.Executors$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Executors_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.Executors",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Executors_MethodInfo_,
	nullptr,
	nullptr,
	_Executors_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.Executors$DelegatedScheduledExecutorService,java.util.concurrent.Executors$FinalizableDelegatedExecutorService,java.util.concurrent.Executors$DelegatedExecutorService,java.util.concurrent.Executors$PrivilegedThreadFactory,java.util.concurrent.Executors$PrivilegedThreadFactory$1,java.util.concurrent.Executors$PrivilegedThreadFactory$1$1,java.util.concurrent.Executors$DefaultThreadFactory,java.util.concurrent.Executors$PrivilegedCallableUsingCurrentClassLoader,java.util.concurrent.Executors$PrivilegedCallableUsingCurrentClassLoader$1,java.util.concurrent.Executors$PrivilegedCallable,java.util.concurrent.Executors$PrivilegedCallable$1,java.util.concurrent.Executors$RunnableAdapter,java.util.concurrent.Executors$2,java.util.concurrent.Executors$1"
};

$Object* allocate$Executors($Class* clazz) {
	return $of($alloc(Executors));
}

$ExecutorService* Executors::newFixedThreadPool(int32_t nThreads) {
	$init($TimeUnit);
	return $new($ThreadPoolExecutor, nThreads, nThreads, 0, $TimeUnit::MILLISECONDS, $$new($LinkedBlockingQueue));
}

$ExecutorService* Executors::newWorkStealingPool(int32_t parallelism) {
	$init($ForkJoinPool);
	return $new($ForkJoinPool, parallelism, $ForkJoinPool::defaultForkJoinWorkerThreadFactory, nullptr, true);
}

$ExecutorService* Executors::newWorkStealingPool() {
	$init($ForkJoinPool);
	return $new($ForkJoinPool, $nc($($Runtime::getRuntime()))->availableProcessors(), $ForkJoinPool::defaultForkJoinWorkerThreadFactory, nullptr, true);
}

$ExecutorService* Executors::newFixedThreadPool(int32_t nThreads, $ThreadFactory* threadFactory) {
	$init($TimeUnit);
	return $new($ThreadPoolExecutor, nThreads, nThreads, (int64_t)0, $TimeUnit::MILLISECONDS, static_cast<$BlockingQueue*>($$new($LinkedBlockingQueue)), threadFactory);
}

$ExecutorService* Executors::newSingleThreadExecutor() {
	$useLocalCurrentObjectStackCache();
	$init($TimeUnit);
	return $new($Executors$FinalizableDelegatedExecutorService, $$new($ThreadPoolExecutor, 1, 1, 0, $TimeUnit::MILLISECONDS, $$new($LinkedBlockingQueue)));
}

$ExecutorService* Executors::newSingleThreadExecutor($ThreadFactory* threadFactory) {
	$useLocalCurrentObjectStackCache();
	$init($TimeUnit);
	return $new($Executors$FinalizableDelegatedExecutorService, $$new($ThreadPoolExecutor, 1, 1, (int64_t)0, $TimeUnit::MILLISECONDS, static_cast<$BlockingQueue*>($$new($LinkedBlockingQueue)), threadFactory));
}

$ExecutorService* Executors::newCachedThreadPool() {
	$init($TimeUnit);
	return $new($ThreadPoolExecutor, 0, $Integer::MAX_VALUE, 60, $TimeUnit::SECONDS, $$new($SynchronousQueue));
}

$ExecutorService* Executors::newCachedThreadPool($ThreadFactory* threadFactory) {
	$init($TimeUnit);
	return $new($ThreadPoolExecutor, 0, $Integer::MAX_VALUE, (int64_t)60, $TimeUnit::SECONDS, static_cast<$BlockingQueue*>($$new($SynchronousQueue)), threadFactory);
}

$ScheduledExecutorService* Executors::newSingleThreadScheduledExecutor() {
	return $new($Executors$DelegatedScheduledExecutorService, $$new($ScheduledThreadPoolExecutor, 1));
}

$ScheduledExecutorService* Executors::newSingleThreadScheduledExecutor($ThreadFactory* threadFactory) {
	return $new($Executors$DelegatedScheduledExecutorService, $$new($ScheduledThreadPoolExecutor, 1, threadFactory));
}

$ScheduledExecutorService* Executors::newScheduledThreadPool(int32_t corePoolSize) {
	return $new($ScheduledThreadPoolExecutor, corePoolSize);
}

$ScheduledExecutorService* Executors::newScheduledThreadPool(int32_t corePoolSize, $ThreadFactory* threadFactory) {
	return $new($ScheduledThreadPoolExecutor, corePoolSize, threadFactory);
}

$ExecutorService* Executors::unconfigurableExecutorService($ExecutorService* executor) {
	if (executor == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$DelegatedExecutorService, executor);
}

$ScheduledExecutorService* Executors::unconfigurableScheduledExecutorService($ScheduledExecutorService* executor) {
	if (executor == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$DelegatedScheduledExecutorService, executor);
}

$ThreadFactory* Executors::defaultThreadFactory() {
	return $new($Executors$DefaultThreadFactory);
}

$ThreadFactory* Executors::privilegedThreadFactory() {
	return $new($Executors$PrivilegedThreadFactory);
}

$Callable* Executors::callable($Runnable* task, Object$* result) {
	if (task == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$RunnableAdapter, task, result);
}

$Callable* Executors::callable($Runnable* task) {
	if (task == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$RunnableAdapter, task, nullptr);
}

$Callable* Executors::callable($PrivilegedAction* action) {
	if (action == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$1, action);
}

$Callable* Executors::callable($PrivilegedExceptionAction* action) {
	if (action == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$2, action);
}

$Callable* Executors::privilegedCallable($Callable* callable) {
	if (callable == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$PrivilegedCallable, callable);
}

$Callable* Executors::privilegedCallableUsingCurrentClassLoader($Callable* callable) {
	if (callable == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($Executors$PrivilegedCallableUsingCurrentClassLoader, callable);
}

void Executors::init$() {
}

Executors::Executors() {
}

$Class* Executors::load$($String* name, bool initialize) {
	$loadClass(Executors, name, initialize, &_Executors_ClassInfo_, allocate$Executors);
	return class$;
}

$Class* Executors::class$ = nullptr;

		} // concurrent
	} // util
} // java