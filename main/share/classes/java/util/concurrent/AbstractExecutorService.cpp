#include <java/util/concurrent/AbstractExecutorService.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/CancellationException.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ExecutorCompletionService.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/FutureTask.h>
#include <java/util/concurrent/RunnableFuture.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/TimeoutException.h>
#include <jcpp.h>

#undef NANOSECONDS

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Callable = ::java::util::concurrent::Callable;
using $CancellationException = ::java::util::concurrent::CancellationException;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Executor = ::java::util::concurrent::Executor;
using $ExecutorCompletionService = ::java::util::concurrent::ExecutorCompletionService;
using $Future = ::java::util::concurrent::Future;
using $FutureTask = ::java::util::concurrent::FutureTask;
using $RunnableFuture = ::java::util::concurrent::RunnableFuture;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $TimeoutException = ::java::util::concurrent::TimeoutException;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _AbstractExecutorService_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AbstractExecutorService, $assertionsDisabled)},
	{}
};

$MethodInfo _AbstractExecutorService_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AbstractExecutorService, init$, void)},
	{"cancelAll", "(Ljava/util/ArrayList;)V", "<T:Ljava/lang/Object;>(Ljava/util/ArrayList<Ljava/util/concurrent/Future<TT;>;>;)V", $PRIVATE | $STATIC, $staticMethod(AbstractExecutorService, cancelAll, void, $ArrayList*)},
	{"cancelAll", "(Ljava/util/ArrayList;I)V", "<T:Ljava/lang/Object;>(Ljava/util/ArrayList<Ljava/util/concurrent/Future<TT;>;>;I)V", $PRIVATE | $STATIC, $staticMethod(AbstractExecutorService, cancelAll, void, $ArrayList*, int32_t)},
	{"doInvokeAny", "(Ljava/util/Collection;ZJ)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;ZJ)TT;", $PRIVATE, $method(AbstractExecutorService, doInvokeAny, $Object*, $Collection*, bool, int64_t), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"invokeAll", "(Ljava/util/Collection;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;)Ljava/util/List<Ljava/util/concurrent/Future<TT;>;>;", $PUBLIC, $virtualMethod(AbstractExecutorService, invokeAll, $List*, $Collection*), "java.lang.InterruptedException"},
	{"invokeAll", "(Ljava/util/Collection;JLjava/util/concurrent/TimeUnit;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;JLjava/util/concurrent/TimeUnit;)Ljava/util/List<Ljava/util/concurrent/Future<TT;>;>;", $PUBLIC, $virtualMethod(AbstractExecutorService, invokeAll, $List*, $Collection*, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"invokeAny", "(Ljava/util/Collection;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;)TT;", $PUBLIC, $virtualMethod(AbstractExecutorService, invokeAny, $Object*, $Collection*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"invokeAny", "(Ljava/util/Collection;JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;JLjava/util/concurrent/TimeUnit;)TT;", $PUBLIC, $virtualMethod(AbstractExecutorService, invokeAny, $Object*, $Collection*, int64_t, $TimeUnit*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"newTaskFor", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/RunnableFuture;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/RunnableFuture<TT;>;", $PROTECTED, $virtualMethod(AbstractExecutorService, newTaskFor, $RunnableFuture*, $Runnable*, Object$*)},
	{"newTaskFor", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/RunnableFuture;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/RunnableFuture<TT;>;", $PROTECTED, $virtualMethod(AbstractExecutorService, newTaskFor, $RunnableFuture*, $Callable*)},
	{"submit", "(Ljava/lang/Runnable;)Ljava/util/concurrent/Future;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/Future<*>;", $PUBLIC, $virtualMethod(AbstractExecutorService, submit, $Future*, $Runnable*)},
	{"submit", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/Future;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/Future<TT;>;", $PUBLIC, $virtualMethod(AbstractExecutorService, submit, $Future*, $Runnable*, Object$*)},
	{"submit", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/Future;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/Future<TT;>;", $PUBLIC, $virtualMethod(AbstractExecutorService, submit, $Future*, $Callable*)},
	{}
};

$ClassInfo _AbstractExecutorService_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.concurrent.AbstractExecutorService",
	"java.lang.Object",
	"java.util.concurrent.ExecutorService",
	_AbstractExecutorService_FieldInfo_,
	_AbstractExecutorService_MethodInfo_
};

$Object* allocate$AbstractExecutorService($Class* clazz) {
	return $of($alloc(AbstractExecutorService));
}

bool AbstractExecutorService::$assertionsDisabled = false;

void AbstractExecutorService::init$() {
}

$RunnableFuture* AbstractExecutorService::newTaskFor($Runnable* runnable, Object$* value) {
	return $new($FutureTask, runnable, value);
}

$RunnableFuture* AbstractExecutorService::newTaskFor($Callable* callable) {
	return $new($FutureTask, callable);
}

$Future* AbstractExecutorService::submit($Runnable* task) {
	if (task == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($RunnableFuture, ftask, newTaskFor(task, nullptr));
	execute(ftask);
	return ftask;
}

$Future* AbstractExecutorService::submit($Runnable* task, Object$* result) {
	if (task == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($RunnableFuture, ftask, newTaskFor(task, result));
	execute(ftask);
	return ftask;
}

$Future* AbstractExecutorService::submit($Callable* task) {
	if (task == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($RunnableFuture, ftask, newTaskFor(task));
	execute(ftask);
	return ftask;
}

$Object* AbstractExecutorService::doInvokeAny($Collection* tasks, bool timed, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	if (tasks == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t ntasks = $nc(tasks)->size();
	if (ntasks == 0) {
		$throwNew($IllegalArgumentException);
	}
	$var($ArrayList, futures, $new($ArrayList, ntasks));
	$var($ExecutorCompletionService, ecs, $new($ExecutorCompletionService, this));
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($ExecutionException, ee, nullptr);
			int64_t deadline = timed ? $System::nanoTime() + nanos : (int64_t)0;
			$var($Iterator, it, tasks->iterator());
			futures->add($(ecs->submit($cast($Callable, $($nc(it)->next())))));
			--ntasks;
			int32_t active = 1;
			for (;;) {
				$var($Future, f, ecs->poll());
				if (f == nullptr) {
					if (ntasks > 0) {
						--ntasks;
						futures->add($(ecs->submit($cast($Callable, $($nc(it)->next())))));
						++active;
					} else if (active == 0) {
						break;
					} else if (timed) {
						$init($TimeUnit);
						$assign(f, ecs->poll(nanos, $TimeUnit::NANOSECONDS));
						if (f == nullptr) {
							$throwNew($TimeoutException);
						}
						nanos = deadline - $System::nanoTime();
					} else {
						$assign(f, ecs->take());
					}
				}
				if (f != nullptr) {
					--active;
					try {
						$assign(var$2, f->get());
						return$1 = true;
						goto $finally;
					} catch ($ExecutionException& eex) {
						$assign(ee, eex);
					} catch ($RuntimeException& rex) {
						$assign(ee, $new($ExecutionException, static_cast<$Throwable*>(rex)));
					}
				}
			}
			if (ee == nullptr) {
				$assign(ee, $new($ExecutionException));
			}
			$throw(ee);
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			cancelAll(futures);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* AbstractExecutorService::invokeAny($Collection* tasks) {
	try {
		return $of(doInvokeAny(tasks, false, 0));
	} catch ($TimeoutException& cannotHappen) {
		if (!AbstractExecutorService::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
		return $of(nullptr);
	}
	$shouldNotReachHere();
}

$Object* AbstractExecutorService::invokeAny($Collection* tasks, int64_t timeout, $TimeUnit* unit) {
	return $of(doInvokeAny(tasks, true, $nc(unit)->toNanos(timeout)));
}

$List* AbstractExecutorService::invokeAll($Collection* tasks) {
	$useLocalCurrentObjectStackCache();
	if (tasks == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ArrayList, futures, $new($ArrayList, $nc(tasks)->size()));
	try {
		{
			$var($Iterator, i$, $nc(tasks)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Callable, t, $cast($Callable, i$->next()));
				{
					$var($RunnableFuture, f, newTaskFor(t));
					futures->add(f);
					execute(f);
				}
			}
		}
		{
			int32_t i = 0;
			int32_t size = futures->size();
			for (; i < size; ++i) {
				$var($Future, f, $cast($Future, futures->get(i)));
				if (!$nc(f)->isDone()) {
					try {
						f->get();
					} catch ($CancellationException& ignore) {
					} catch ($ExecutionException& ignore) {
					}
				}
			}
		}
		return futures;
	} catch ($Throwable& t) {
		cancelAll(futures);
		$throw(t);
	}
	$shouldNotReachHere();
}

$List* AbstractExecutorService::invokeAll($Collection* tasks, int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (tasks == nullptr) {
		$throwNew($NullPointerException);
	}
	int64_t nanos = $nc(unit)->toNanos(timeout);
	int64_t deadline = $System::nanoTime() + nanos;
	$var($ArrayList, futures, $new($ArrayList, $nc(tasks)->size()));
	int32_t j = 0;
	bool timedOut$break = false;
	for (;;) {
		try {
			{
				$var($Iterator, i$, $nc(tasks)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Callable, t, $cast($Callable, i$->next()));
					futures->add($(newTaskFor(t)));
				}
			}
			int32_t size = futures->size();
			for (int32_t i = 0; i < size; ++i) {
				if (((i == 0) ? nanos : deadline - $System::nanoTime()) <= (int64_t)0) {
					timedOut$break = true;
					break;
				}
				execute($cast($Runnable, $(futures->get(i))));
			}
			if (timedOut$break) {
				break;
			}
			for (; j < size; ++j) {
				$var($Future, f, $cast($Future, futures->get(j)));
				if (!$nc(f)->isDone()) {
					try {
						f->get(deadline - $System::nanoTime(), $TimeUnit::NANOSECONDS);
					} catch ($CancellationException& ignore) {
					} catch ($ExecutionException& ignore) {
					} catch ($TimeoutException& timedOut) {
						timedOut$break = true;
						break;
					}
				}
			}
			if (timedOut$break) {
				break;
			}
			return futures;
		} catch ($Throwable& t) {
			cancelAll(futures);
			$throw(t);
		}
		break;
	}
	cancelAll(futures, j);
	return futures;
}

void AbstractExecutorService::cancelAll($ArrayList* futures) {
	$init(AbstractExecutorService);
	cancelAll(futures, 0);
}

void AbstractExecutorService::cancelAll($ArrayList* futures, int32_t j) {
	$init(AbstractExecutorService);
	$useLocalCurrentObjectStackCache();
	for (int32_t size = $nc(futures)->size(); j < size; ++j) {
		$nc(($cast($Future, $(futures->get(j)))))->cancel(true);
	}
}

void clinit$AbstractExecutorService($Class* class$) {
	AbstractExecutorService::$assertionsDisabled = !AbstractExecutorService::class$->desiredAssertionStatus();
}

AbstractExecutorService::AbstractExecutorService() {
}

$Class* AbstractExecutorService::load$($String* name, bool initialize) {
	$loadClass(AbstractExecutorService, name, initialize, &_AbstractExecutorService_ClassInfo_, clinit$AbstractExecutorService, allocate$AbstractExecutorService);
	return class$;
}

$Class* AbstractExecutorService::class$ = nullptr;

		} // concurrent
	} // util
} // java