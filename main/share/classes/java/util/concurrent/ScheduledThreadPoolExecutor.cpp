#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>

#include <java/lang/Runnable.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/concurrent/BlockingQueue.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/Delayed.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/RejectedExecutionHandler.h>
#include <java/util/concurrent/RunnableScheduledFuture.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor$DelayedWorkQueue.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor$ScheduledFutureTask.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/ThreadPoolExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <jcpp.h>

#undef DEFAULT_KEEPALIVE_MILLIS
#undef MAX_VALUE
#undef MILLISECONDS
#undef NANOSECONDS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $BlockingQueue = ::java::util::concurrent::BlockingQueue;
using $Callable = ::java::util::concurrent::Callable;
using $Delayed = ::java::util::concurrent::Delayed;
using $Executors = ::java::util::concurrent::Executors;
using $Future = ::java::util::concurrent::Future;
using $RejectedExecutionHandler = ::java::util::concurrent::RejectedExecutionHandler;
using $RunnableScheduledFuture = ::java::util::concurrent::RunnableScheduledFuture;
using $ScheduledFuture = ::java::util::concurrent::ScheduledFuture;
using $ScheduledThreadPoolExecutor$DelayedWorkQueue = ::java::util::concurrent::ScheduledThreadPoolExecutor$DelayedWorkQueue;
using $ScheduledThreadPoolExecutor$ScheduledFutureTask = ::java::util::concurrent::ScheduledThreadPoolExecutor$ScheduledFutureTask;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $ThreadPoolExecutor = ::java::util::concurrent::ThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ScheduledThreadPoolExecutor_FieldInfo_[] = {
	{"continueExistingPeriodicTasksAfterShutdown", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ScheduledThreadPoolExecutor, continueExistingPeriodicTasksAfterShutdown)},
	{"executeExistingDelayedTasksAfterShutdown", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ScheduledThreadPoolExecutor, executeExistingDelayedTasksAfterShutdown)},
	{"removeOnCancel", "Z", nullptr, $VOLATILE, $field(ScheduledThreadPoolExecutor, removeOnCancel)},
	{"sequencer", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ScheduledThreadPoolExecutor, sequencer)},
	{"DEFAULT_KEEPALIVE_MILLIS", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ScheduledThreadPoolExecutor, DEFAULT_KEEPALIVE_MILLIS)},
	{}
};

$MethodInfo _ScheduledThreadPoolExecutor_MethodInfo_[] = {
	{"*awaitTermination", "(JLjava/util/concurrent/TimeUnit;)Z", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(ScheduledThreadPoolExecutor, init$, void, int32_t)},
	{"<init>", "(ILjava/util/concurrent/ThreadFactory;)V", nullptr, $PUBLIC, $method(ScheduledThreadPoolExecutor, init$, void, int32_t, $ThreadFactory*)},
	{"<init>", "(ILjava/util/concurrent/RejectedExecutionHandler;)V", nullptr, $PUBLIC, $method(ScheduledThreadPoolExecutor, init$, void, int32_t, $RejectedExecutionHandler*)},
	{"<init>", "(ILjava/util/concurrent/ThreadFactory;Ljava/util/concurrent/RejectedExecutionHandler;)V", nullptr, $PUBLIC, $method(ScheduledThreadPoolExecutor, init$, void, int32_t, $ThreadFactory*, $RejectedExecutionHandler*)},
	{"canRunInCurrentRunState", "(Ljava/util/concurrent/RunnableScheduledFuture;)Z", "(Ljava/util/concurrent/RunnableScheduledFuture<*>;)Z", 0, $virtualMethod(ScheduledThreadPoolExecutor, canRunInCurrentRunState, bool, $RunnableScheduledFuture*)},
	{"decorateTask", "(Ljava/lang/Runnable;Ljava/util/concurrent/RunnableScheduledFuture;)Ljava/util/concurrent/RunnableScheduledFuture;", "<V:Ljava/lang/Object;>(Ljava/lang/Runnable;Ljava/util/concurrent/RunnableScheduledFuture<TV;>;)Ljava/util/concurrent/RunnableScheduledFuture<TV;>;", $PROTECTED, $virtualMethod(ScheduledThreadPoolExecutor, decorateTask, $RunnableScheduledFuture*, $Runnable*, $RunnableScheduledFuture*)},
	{"decorateTask", "(Ljava/util/concurrent/Callable;Ljava/util/concurrent/RunnableScheduledFuture;)Ljava/util/concurrent/RunnableScheduledFuture;", "<V:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TV;>;Ljava/util/concurrent/RunnableScheduledFuture<TV;>;)Ljava/util/concurrent/RunnableScheduledFuture<TV;>;", $PROTECTED, $virtualMethod(ScheduledThreadPoolExecutor, decorateTask, $RunnableScheduledFuture*, $Callable*, $RunnableScheduledFuture*)},
	{"delayedExecute", "(Ljava/util/concurrent/RunnableScheduledFuture;)V", "(Ljava/util/concurrent/RunnableScheduledFuture<*>;)V", $PRIVATE, $method(ScheduledThreadPoolExecutor, delayedExecute, void, $RunnableScheduledFuture*)},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, execute, void, $Runnable*)},
	{"getContinueExistingPeriodicTasksAfterShutdownPolicy", "()Z", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, getContinueExistingPeriodicTasksAfterShutdownPolicy, bool)},
	{"getExecuteExistingDelayedTasksAfterShutdownPolicy", "()Z", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, getExecuteExistingDelayedTasksAfterShutdownPolicy, bool)},
	{"getQueue", "()Ljava/util/concurrent/BlockingQueue;", "()Ljava/util/concurrent/BlockingQueue<Ljava/lang/Runnable;>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, getQueue, $BlockingQueue*)},
	{"getRemoveOnCancelPolicy", "()Z", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, getRemoveOnCancelPolicy, bool)},
	{"*invokeAll", "(Ljava/util/Collection;)Ljava/util/List;", nullptr, $PUBLIC},
	{"*invokeAll", "(Ljava/util/Collection;JLjava/util/concurrent/TimeUnit;)Ljava/util/List;", nullptr, $PUBLIC},
	{"*invokeAny", "(Ljava/util/Collection;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*invokeAny", "(Ljava/util/Collection;JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*isShutdown", "()Z", nullptr, $PUBLIC},
	{"*isTerminated", "()Z", nullptr, $PUBLIC},
	{"onShutdown", "()V", nullptr, 0, $virtualMethod(ScheduledThreadPoolExecutor, onShutdown, void)},
	{"overflowFree", "(J)J", nullptr, $PRIVATE, $method(ScheduledThreadPoolExecutor, overflowFree, int64_t, int64_t)},
	{"reExecutePeriodic", "(Ljava/util/concurrent/RunnableScheduledFuture;)V", "(Ljava/util/concurrent/RunnableScheduledFuture<*>;)V", 0, $virtualMethod(ScheduledThreadPoolExecutor, reExecutePeriodic, void, $RunnableScheduledFuture*)},
	{"schedule", "(Ljava/lang/Runnable;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture;", "(Ljava/lang/Runnable;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture<*>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, schedule, $ScheduledFuture*, $Runnable*, int64_t, $TimeUnit*)},
	{"schedule", "(Ljava/util/concurrent/Callable;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture;", "<V:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TV;>;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture<TV;>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, schedule, $ScheduledFuture*, $Callable*, int64_t, $TimeUnit*)},
	{"scheduleAtFixedRate", "(Ljava/lang/Runnable;JJLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture;", "(Ljava/lang/Runnable;JJLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture<*>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, scheduleAtFixedRate, $ScheduledFuture*, $Runnable*, int64_t, int64_t, $TimeUnit*)},
	{"scheduleWithFixedDelay", "(Ljava/lang/Runnable;JJLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture;", "(Ljava/lang/Runnable;JJLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/ScheduledFuture<*>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, scheduleWithFixedDelay, $ScheduledFuture*, $Runnable*, int64_t, int64_t, $TimeUnit*)},
	{"setContinueExistingPeriodicTasksAfterShutdownPolicy", "(Z)V", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, setContinueExistingPeriodicTasksAfterShutdownPolicy, void, bool)},
	{"setExecuteExistingDelayedTasksAfterShutdownPolicy", "(Z)V", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, setExecuteExistingDelayedTasksAfterShutdownPolicy, void, bool)},
	{"setRemoveOnCancelPolicy", "(Z)V", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, setRemoveOnCancelPolicy, void, bool)},
	{"shutdown", "()V", nullptr, $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, shutdown, void)},
	{"shutdownNow", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Runnable;>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, shutdownNow, $List*)},
	{"submit", "(Ljava/lang/Runnable;)Ljava/util/concurrent/Future;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/Future<*>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, submit, $Future*, $Runnable*)},
	{"submit", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/Future;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/Future<TT;>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, submit, $Future*, $Runnable*, Object$*)},
	{"submit", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/Future;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/Future<TT;>;", $PUBLIC, $virtualMethod(ScheduledThreadPoolExecutor, submit, $Future*, $Callable*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"triggerTime", "(JLjava/util/concurrent/TimeUnit;)J", nullptr, $PRIVATE, $method(ScheduledThreadPoolExecutor, triggerTime, int64_t, int64_t, $TimeUnit*)},
	{"triggerTime", "(J)J", nullptr, 0, $virtualMethod(ScheduledThreadPoolExecutor, triggerTime, int64_t, int64_t)},
	{}
};

$InnerClassInfo _ScheduledThreadPoolExecutor_InnerClassesInfo_[] = {
	{"java.util.concurrent.ScheduledThreadPoolExecutor$DelayedWorkQueue", "java.util.concurrent.ScheduledThreadPoolExecutor", "DelayedWorkQueue", $STATIC},
	{"java.util.concurrent.ScheduledThreadPoolExecutor$ScheduledFutureTask", "java.util.concurrent.ScheduledThreadPoolExecutor", "ScheduledFutureTask", $PRIVATE},
	{}
};

$ClassInfo _ScheduledThreadPoolExecutor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.ScheduledThreadPoolExecutor",
	"java.util.concurrent.ThreadPoolExecutor",
	"java.util.concurrent.ScheduledExecutorService",
	_ScheduledThreadPoolExecutor_FieldInfo_,
	_ScheduledThreadPoolExecutor_MethodInfo_,
	nullptr,
	nullptr,
	_ScheduledThreadPoolExecutor_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.ScheduledThreadPoolExecutor$DelayedWorkQueue,java.util.concurrent.ScheduledThreadPoolExecutor$DelayedWorkQueue$Itr,java.util.concurrent.ScheduledThreadPoolExecutor$ScheduledFutureTask"
};

$Object* allocate$ScheduledThreadPoolExecutor($Class* clazz) {
	return $of($alloc(ScheduledThreadPoolExecutor));
}

bool ScheduledThreadPoolExecutor::isShutdown() {
	 return this->$ThreadPoolExecutor::isShutdown();
}

bool ScheduledThreadPoolExecutor::isTerminated() {
	 return this->$ThreadPoolExecutor::isTerminated();
}

bool ScheduledThreadPoolExecutor::awaitTermination(int64_t timeout, $TimeUnit* unit) {
	 return this->$ThreadPoolExecutor::awaitTermination(timeout, unit);
}

void ScheduledThreadPoolExecutor::finalize() {
	this->$ThreadPoolExecutor::finalize();
}

$String* ScheduledThreadPoolExecutor::toString() {
	 return this->$ThreadPoolExecutor::toString();
}

$Object* ScheduledThreadPoolExecutor::invokeAny($Collection* tasks) {
	 return this->$ThreadPoolExecutor::invokeAny(tasks);
}

$Object* ScheduledThreadPoolExecutor::invokeAny($Collection* tasks, int64_t timeout, $TimeUnit* unit) {
	 return this->$ThreadPoolExecutor::invokeAny(tasks, timeout, unit);
}

$List* ScheduledThreadPoolExecutor::invokeAll($Collection* tasks) {
	 return this->$ThreadPoolExecutor::invokeAll(tasks);
}

$List* ScheduledThreadPoolExecutor::invokeAll($Collection* tasks, int64_t timeout, $TimeUnit* unit) {
	 return this->$ThreadPoolExecutor::invokeAll(tasks, timeout, unit);
}

int32_t ScheduledThreadPoolExecutor::hashCode() {
	 return this->$ThreadPoolExecutor::hashCode();
}

bool ScheduledThreadPoolExecutor::equals(Object$* obj) {
	 return this->$ThreadPoolExecutor::equals(obj);
}

$Object* ScheduledThreadPoolExecutor::clone() {
	 return this->$ThreadPoolExecutor::clone();
}

$AtomicLong* ScheduledThreadPoolExecutor::sequencer = nullptr;

bool ScheduledThreadPoolExecutor::canRunInCurrentRunState($RunnableScheduledFuture* task) {
	if (!isShutdown()) {
		return true;
	}
	if (isStopped()) {
		return false;
	}
	$init($TimeUnit);
	return $nc(task)->isPeriodic() ? $cast(bool, this->continueExistingPeriodicTasksAfterShutdown) : (this->executeExistingDelayedTasksAfterShutdown || $nc(task)->getDelay($TimeUnit::NANOSECONDS) <= 0);
}

void ScheduledThreadPoolExecutor::delayedExecute($RunnableScheduledFuture* task) {
	if (isShutdown()) {
		reject(task);
	} else {
		$nc($($ThreadPoolExecutor::getQueue()))->add(task);
		bool var$0 = !canRunInCurrentRunState(task);
		if (var$0 && remove(task)) {
			$nc(task)->cancel(false);
		} else {
			ensurePrestart();
		}
	}
}

void ScheduledThreadPoolExecutor::reExecutePeriodic($RunnableScheduledFuture* task) {
	if (canRunInCurrentRunState(task)) {
		$nc($($ThreadPoolExecutor::getQueue()))->add(task);
		bool var$0 = canRunInCurrentRunState(task);
		if (var$0 || !remove(task)) {
			ensurePrestart();
			return;
		}
	}
	$nc(task)->cancel(false);
}

void ScheduledThreadPoolExecutor::onShutdown() {
	$useLocalCurrentObjectStackCache();
	$var($BlockingQueue, q, $ThreadPoolExecutor::getQueue());
	bool keepDelayed = getExecuteExistingDelayedTasksAfterShutdownPolicy();
	bool keepPeriodic = getContinueExistingPeriodicTasksAfterShutdownPolicy();
	{
		$var($ObjectArray, arr$, $nc(q)->toArray());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, e, arr$->get(i$));
			{
				if ($instanceOf($RunnableScheduledFuture, e)) {
					$var($RunnableScheduledFuture, t, $cast($RunnableScheduledFuture, e));
					$init($TimeUnit);
					bool var$0 = ($nc(t)->isPeriodic() ? !keepPeriodic : (!keepDelayed && $nc(t)->getDelay($TimeUnit::NANOSECONDS) > 0));
					if (var$0 || $nc(t)->isCancelled()) {
						if (q->remove(t)) {
							t->cancel(false);
						}
					}
				}
			}
		}
	}
	tryTerminate();
}

$RunnableScheduledFuture* ScheduledThreadPoolExecutor::decorateTask($Runnable* runnable, $RunnableScheduledFuture* task) {
	return task;
}

$RunnableScheduledFuture* ScheduledThreadPoolExecutor::decorateTask($Callable* callable, $RunnableScheduledFuture* task) {
	return task;
}

void ScheduledThreadPoolExecutor::init$(int32_t corePoolSize) {
	$init($TimeUnit);
	$ThreadPoolExecutor::init$(corePoolSize, $Integer::MAX_VALUE, ScheduledThreadPoolExecutor::DEFAULT_KEEPALIVE_MILLIS, $TimeUnit::MILLISECONDS, $$new($ScheduledThreadPoolExecutor$DelayedWorkQueue));
	this->executeExistingDelayedTasksAfterShutdown = true;
}

void ScheduledThreadPoolExecutor::init$(int32_t corePoolSize, $ThreadFactory* threadFactory) {
	$init($TimeUnit);
	$ThreadPoolExecutor::init$(corePoolSize, $Integer::MAX_VALUE, ScheduledThreadPoolExecutor::DEFAULT_KEEPALIVE_MILLIS, $TimeUnit::MILLISECONDS, static_cast<$BlockingQueue*>($$new($ScheduledThreadPoolExecutor$DelayedWorkQueue)), threadFactory);
	this->executeExistingDelayedTasksAfterShutdown = true;
}

void ScheduledThreadPoolExecutor::init$(int32_t corePoolSize, $RejectedExecutionHandler* handler) {
	$init($TimeUnit);
	$ThreadPoolExecutor::init$(corePoolSize, $Integer::MAX_VALUE, ScheduledThreadPoolExecutor::DEFAULT_KEEPALIVE_MILLIS, $TimeUnit::MILLISECONDS, static_cast<$BlockingQueue*>($$new($ScheduledThreadPoolExecutor$DelayedWorkQueue)), handler);
	this->executeExistingDelayedTasksAfterShutdown = true;
}

void ScheduledThreadPoolExecutor::init$(int32_t corePoolSize, $ThreadFactory* threadFactory, $RejectedExecutionHandler* handler) {
	$init($TimeUnit);
	$ThreadPoolExecutor::init$(corePoolSize, $Integer::MAX_VALUE, ScheduledThreadPoolExecutor::DEFAULT_KEEPALIVE_MILLIS, $TimeUnit::MILLISECONDS, $$new($ScheduledThreadPoolExecutor$DelayedWorkQueue), threadFactory, handler);
	this->executeExistingDelayedTasksAfterShutdown = true;
}

int64_t ScheduledThreadPoolExecutor::triggerTime(int64_t delay, $TimeUnit* unit) {
	return triggerTime($nc(unit)->toNanos((delay < 0) ? (int64_t)0 : delay));
}

int64_t ScheduledThreadPoolExecutor::triggerTime(int64_t delay) {
	int64_t var$0 = $System::nanoTime();
	return var$0 + ((delay < ($Long::MAX_VALUE >> 1)) ? delay : overflowFree(delay));
}

int64_t ScheduledThreadPoolExecutor::overflowFree(int64_t delay) {
	$useLocalCurrentObjectStackCache();
	$var($Delayed, head, $cast($Delayed, $nc($($ThreadPoolExecutor::getQueue()))->peek()));
	if (head != nullptr) {
		$init($TimeUnit);
		int64_t headDelay = head->getDelay($TimeUnit::NANOSECONDS);
		if (headDelay < 0 && (delay - headDelay < 0)) {
			delay = $Long::MAX_VALUE + headDelay;
		}
	}
	return delay;
}

$ScheduledFuture* ScheduledThreadPoolExecutor::schedule($Runnable* command, int64_t delay, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (command == nullptr || unit == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Runnable, var$0, command);
	int64_t var$1 = triggerTime(delay, unit);
	$var($RunnableScheduledFuture, t, decorateTask(command, static_cast<$RunnableScheduledFuture*>($$new($ScheduledThreadPoolExecutor$ScheduledFutureTask, this, var$0, nullptr, var$1, $nc(ScheduledThreadPoolExecutor::sequencer)->getAndIncrement()))));
	delayedExecute(t);
	return t;
}

$ScheduledFuture* ScheduledThreadPoolExecutor::schedule($Callable* callable, int64_t delay, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (callable == nullptr || unit == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Callable, var$0, callable);
	int64_t var$1 = triggerTime(delay, unit);
	$var($RunnableScheduledFuture, t, decorateTask(callable, static_cast<$RunnableScheduledFuture*>($$new($ScheduledThreadPoolExecutor$ScheduledFutureTask, this, var$0, var$1, $nc(ScheduledThreadPoolExecutor::sequencer)->getAndIncrement()))));
	delayedExecute(t);
	return t;
}

$ScheduledFuture* ScheduledThreadPoolExecutor::scheduleAtFixedRate($Runnable* command, int64_t initialDelay, int64_t period, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (command == nullptr || unit == nullptr) {
		$throwNew($NullPointerException);
	}
	if (period <= (int64_t)0) {
		$throwNew($IllegalArgumentException);
	}
	$var($Runnable, var$0, command);
	int64_t var$1 = triggerTime(initialDelay, unit);
	int64_t var$2 = $nc(unit)->toNanos(period);
	$var($ScheduledThreadPoolExecutor$ScheduledFutureTask, sft, $new($ScheduledThreadPoolExecutor$ScheduledFutureTask, this, var$0, nullptr, var$1, var$2, $nc(ScheduledThreadPoolExecutor::sequencer)->getAndIncrement()));
	$var($RunnableScheduledFuture, t, decorateTask(command, static_cast<$RunnableScheduledFuture*>(sft)));
	$set(sft, outerTask, t);
	delayedExecute(t);
	return t;
}

$ScheduledFuture* ScheduledThreadPoolExecutor::scheduleWithFixedDelay($Runnable* command, int64_t initialDelay, int64_t delay, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	if (command == nullptr || unit == nullptr) {
		$throwNew($NullPointerException);
	}
	if (delay <= (int64_t)0) {
		$throwNew($IllegalArgumentException);
	}
	$var($Runnable, var$0, command);
	int64_t var$1 = triggerTime(initialDelay, unit);
	int64_t var$2 = -$nc(unit)->toNanos(delay);
	$var($ScheduledThreadPoolExecutor$ScheduledFutureTask, sft, $new($ScheduledThreadPoolExecutor$ScheduledFutureTask, this, var$0, nullptr, var$1, var$2, $nc(ScheduledThreadPoolExecutor::sequencer)->getAndIncrement()));
	$var($RunnableScheduledFuture, t, decorateTask(command, static_cast<$RunnableScheduledFuture*>(sft)));
	$set(sft, outerTask, t);
	delayedExecute(t);
	return t;
}

void ScheduledThreadPoolExecutor::execute($Runnable* command) {
	$init($TimeUnit);
	schedule(command, (int64_t)0, $TimeUnit::NANOSECONDS);
}

$Future* ScheduledThreadPoolExecutor::submit($Runnable* task) {
	$init($TimeUnit);
	return schedule(task, (int64_t)0, $TimeUnit::NANOSECONDS);
}

$Future* ScheduledThreadPoolExecutor::submit($Runnable* task, Object$* result) {
	$init($TimeUnit);
	return schedule($($Executors::callable(task, result)), (int64_t)0, $TimeUnit::NANOSECONDS);
}

$Future* ScheduledThreadPoolExecutor::submit($Callable* task) {
	$init($TimeUnit);
	return schedule(task, (int64_t)0, $TimeUnit::NANOSECONDS);
}

void ScheduledThreadPoolExecutor::setContinueExistingPeriodicTasksAfterShutdownPolicy(bool value) {
	this->continueExistingPeriodicTasksAfterShutdown = value;
	if (!value && isShutdown()) {
		onShutdown();
	}
}

bool ScheduledThreadPoolExecutor::getContinueExistingPeriodicTasksAfterShutdownPolicy() {
	return this->continueExistingPeriodicTasksAfterShutdown;
}

void ScheduledThreadPoolExecutor::setExecuteExistingDelayedTasksAfterShutdownPolicy(bool value) {
	this->executeExistingDelayedTasksAfterShutdown = value;
	if (!value && isShutdown()) {
		onShutdown();
	}
}

bool ScheduledThreadPoolExecutor::getExecuteExistingDelayedTasksAfterShutdownPolicy() {
	return this->executeExistingDelayedTasksAfterShutdown;
}

void ScheduledThreadPoolExecutor::setRemoveOnCancelPolicy(bool value) {
	this->removeOnCancel = value;
}

bool ScheduledThreadPoolExecutor::getRemoveOnCancelPolicy() {
	return this->removeOnCancel;
}

void ScheduledThreadPoolExecutor::shutdown() {
	$ThreadPoolExecutor::shutdown();
}

$List* ScheduledThreadPoolExecutor::shutdownNow() {
	return $ThreadPoolExecutor::shutdownNow();
}

$BlockingQueue* ScheduledThreadPoolExecutor::getQueue() {
	return $ThreadPoolExecutor::getQueue();
}

void clinit$ScheduledThreadPoolExecutor($Class* class$) {
	$assignStatic(ScheduledThreadPoolExecutor::sequencer, $new($AtomicLong));
}

ScheduledThreadPoolExecutor::ScheduledThreadPoolExecutor() {
}

$Class* ScheduledThreadPoolExecutor::load$($String* name, bool initialize) {
	$loadClass(ScheduledThreadPoolExecutor, name, initialize, &_ScheduledThreadPoolExecutor_ClassInfo_, clinit$ScheduledThreadPoolExecutor, allocate$ScheduledThreadPoolExecutor);
	return class$;
}

$Class* ScheduledThreadPoolExecutor::class$ = nullptr;

		} // concurrent
	} // util
} // java