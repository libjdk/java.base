#include <java/util/concurrent/FutureTask.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/CancellationException.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/FutureTask$WaitNode.h>
#include <java/util/concurrent/RunnableFuture.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/TimeoutException.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <jcpp.h>

#undef CANCELLED
#undef COMPLETING
#undef EXCEPTIONAL
#undef INTERRUPTED
#undef INTERRUPTING
#undef NEW
#undef NORMAL
#undef RUNNER
#undef STATE
#undef TYPE
#undef WAITERS

using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Callable = ::java::util::concurrent::Callable;
using $CancellationException = ::java::util::concurrent::CancellationException;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Executors = ::java::util::concurrent::Executors;
using $FutureTask$WaitNode = ::java::util::concurrent::FutureTask$WaitNode;
using $RunnableFuture = ::java::util::concurrent::RunnableFuture;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $TimeoutException = ::java::util::concurrent::TimeoutException;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _FutureTask_FieldInfo_[] = {
	{"state", "I", nullptr, $PRIVATE | $VOLATILE, $field(FutureTask, state)},
	{"NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, NEW)},
	{"COMPLETING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, COMPLETING)},
	{"NORMAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, NORMAL)},
	{"EXCEPTIONAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, EXCEPTIONAL)},
	{"CANCELLED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, CANCELLED)},
	{"INTERRUPTING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, INTERRUPTING)},
	{"INTERRUPTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FutureTask, INTERRUPTED)},
	{"callable", "Ljava/util/concurrent/Callable;", "Ljava/util/concurrent/Callable<TV;>;", $PRIVATE, $field(FutureTask, callable)},
	{"outcome", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(FutureTask, outcome)},
	{"runner", "Ljava/lang/Thread;", nullptr, $PRIVATE | $VOLATILE, $field(FutureTask, runner)},
	{"waiters", "Ljava/util/concurrent/FutureTask$WaitNode;", nullptr, $PRIVATE | $VOLATILE, $field(FutureTask, waiters)},
	{"STATE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FutureTask, STATE)},
	{"RUNNER", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FutureTask, RUNNER)},
	{"WAITERS", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FutureTask, WAITERS)},
	{}
};

$MethodInfo _FutureTask_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Callable;)V", "(Ljava/util/concurrent/Callable<TV;>;)V", $PUBLIC, $method(FutureTask, init$, void, $Callable*)},
	{"<init>", "(Ljava/lang/Runnable;Ljava/lang/Object;)V", "(Ljava/lang/Runnable;TV;)V", $PUBLIC, $method(FutureTask, init$, void, $Runnable*, Object$*)},
	{"awaitDone", "(ZJ)I", nullptr, $PRIVATE, $method(FutureTask, awaitDone, int32_t, bool, int64_t), "java.lang.InterruptedException"},
	{"cancel", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(FutureTask, cancel, bool, bool)},
	{"done", "()V", nullptr, $PROTECTED, $virtualMethod(FutureTask, done, void)},
	{"finishCompletion", "()V", nullptr, $PRIVATE, $method(FutureTask, finishCompletion, void)},
	{"get", "()Ljava/lang/Object;", "()TV;", $PUBLIC, $virtualMethod(FutureTask, get, $Object*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"get", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TV;", $PUBLIC, $virtualMethod(FutureTask, get, $Object*, int64_t, $TimeUnit*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"handlePossibleCancellationInterrupt", "(I)V", nullptr, $PRIVATE, $method(FutureTask, handlePossibleCancellationInterrupt, void, int32_t)},
	{"isCancelled", "()Z", nullptr, $PUBLIC, $virtualMethod(FutureTask, isCancelled, bool)},
	{"isDone", "()Z", nullptr, $PUBLIC, $virtualMethod(FutureTask, isDone, bool)},
	{"removeWaiter", "(Ljava/util/concurrent/FutureTask$WaitNode;)V", nullptr, $PRIVATE, $method(FutureTask, removeWaiter, void, $FutureTask$WaitNode*)},
	{"report", "(I)Ljava/lang/Object;", "(I)TV;", $PRIVATE, $method(FutureTask, report, $Object*, int32_t), "java.util.concurrent.ExecutionException"},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(FutureTask, run, void)},
	{"runAndReset", "()Z", nullptr, $PROTECTED, $virtualMethod(FutureTask, runAndReset, bool)},
	{"set", "(Ljava/lang/Object;)V", "(TV;)V", $PROTECTED, $virtualMethod(FutureTask, set, void, Object$*)},
	{"setException", "(Ljava/lang/Throwable;)V", nullptr, $PROTECTED, $virtualMethod(FutureTask, setException, void, $Throwable*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FutureTask, toString, $String*)},
	{}
};

$InnerClassInfo _FutureTask_InnerClassesInfo_[] = {
	{"java.util.concurrent.FutureTask$WaitNode", "java.util.concurrent.FutureTask", "WaitNode", $STATIC | $FINAL},
	{}
};

$ClassInfo _FutureTask_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.FutureTask",
	"java.lang.Object",
	"java.util.concurrent.RunnableFuture",
	_FutureTask_FieldInfo_,
	_FutureTask_MethodInfo_,
	"<V:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/RunnableFuture<TV;>;",
	nullptr,
	_FutureTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.FutureTask$WaitNode"
};

$Object* allocate$FutureTask($Class* clazz) {
	return $of($alloc(FutureTask));
}

$VarHandle* FutureTask::STATE = nullptr;
$VarHandle* FutureTask::RUNNER = nullptr;
$VarHandle* FutureTask::WAITERS = nullptr;

$Object* FutureTask::report(int32_t s) {
	$var($Object, x, this->outcome);
	if (s == FutureTask::NORMAL) {
		return $of(x);
	}
	if (s >= FutureTask::CANCELLED) {
		$throwNew($CancellationException);
	}
	$throwNew($ExecutionException, $cast($Throwable, x));
}

void FutureTask::init$($Callable* callable) {
	if (callable == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, callable, callable);
	this->state = FutureTask::NEW;
}

void FutureTask::init$($Runnable* runnable, Object$* result) {
	$set(this, callable, $Executors::callable(runnable, result));
	this->state = FutureTask::NEW;
}

bool FutureTask::isCancelled() {
	return this->state >= FutureTask::CANCELLED;
}

bool FutureTask::isDone() {
	return this->state != FutureTask::NEW;
}

bool FutureTask::cancel(bool mayInterruptIfRunning) {
	$useLocalCurrentObjectStackCache();
	if (!(this->state == FutureTask::NEW && $nc(FutureTask::STATE)->compareAndSet($$new($ObjectArray, {$of(this), $$of(FutureTask::NEW), $$of((mayInterruptIfRunning ? FutureTask::INTERRUPTING : FutureTask::CANCELLED))})))) {
		return false;
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (mayInterruptIfRunning) {
				{
					$var($Throwable, var$1, nullptr);
					try {
						$var($Thread, t, this->runner);
						if (t != nullptr) {
							t->interrupt();
						}
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						$nc(FutureTask::STATE)->setRelease($$new($ObjectArray, {$of(this), $$of(FutureTask::INTERRUPTED)}));
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			finishCompletion();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return true;
}

$Object* FutureTask::get() {
	int32_t s = this->state;
	if (s <= FutureTask::COMPLETING) {
		s = awaitDone(false, 0);
	}
	return $of(report(s));
}

$Object* FutureTask::get(int64_t timeout, $TimeUnit* unit) {
	if (unit == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t s = this->state;
	bool var$0 = s <= FutureTask::COMPLETING;
	if (var$0 && (s = awaitDone(true, $nc(unit)->toNanos(timeout))) <= FutureTask::COMPLETING) {
		$throwNew($TimeoutException);
	}
	return $of(report(s));
}

void FutureTask::done() {
}

void FutureTask::set(Object$* v) {
	$useLocalCurrentObjectStackCache();
	if ($nc(FutureTask::STATE)->compareAndSet($$new($ObjectArray, {$of(this), $$of(FutureTask::NEW), $$of(FutureTask::COMPLETING)}))) {
		$set(this, outcome, v);
		$nc(FutureTask::STATE)->setRelease($$new($ObjectArray, {$of(this), $$of(FutureTask::NORMAL)}));
		finishCompletion();
	}
}

void FutureTask::setException($Throwable* t) {
	$useLocalCurrentObjectStackCache();
	if ($nc(FutureTask::STATE)->compareAndSet($$new($ObjectArray, {$of(this), $$of(FutureTask::NEW), $$of(FutureTask::COMPLETING)}))) {
		$set(this, outcome, t);
		$nc(FutureTask::STATE)->setRelease($$new($ObjectArray, {$of(this), $$of(FutureTask::EXCEPTIONAL)}));
		finishCompletion();
	}
}

void FutureTask::run() {
	$useLocalCurrentObjectStackCache();
	if (this->state != FutureTask::NEW || !$nc(FutureTask::RUNNER)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $($of($Thread::currentThread()))}))) {
		return;
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Callable, c, this->callable);
			if (c != nullptr && this->state == FutureTask::NEW) {
				$var($Object, result, nullptr);
				bool ran = false;
				try {
					$assign(result, c->call());
					ran = true;
				} catch ($Throwable& ex) {
					$assign(result, nullptr);
					ran = false;
					setException(ex);
				}
				if (ran) {
					set(result);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, runner, nullptr);
			int32_t s = this->state;
			if (s >= FutureTask::INTERRUPTING) {
				handlePossibleCancellationInterrupt(s);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool FutureTask::runAndReset() {
	$useLocalCurrentObjectStackCache();
	if (this->state != FutureTask::NEW || !$nc(FutureTask::RUNNER)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $($of($Thread::currentThread()))}))) {
		return false;
	}
	bool ran = false;
	int32_t s = this->state;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Callable, c, this->callable);
			if (c != nullptr && s == FutureTask::NEW) {
				try {
					c->call();
					ran = true;
				} catch ($Throwable& ex) {
					setException(ex);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, runner, nullptr);
			s = this->state;
			if (s >= FutureTask::INTERRUPTING) {
				handlePossibleCancellationInterrupt(s);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return ran && s == FutureTask::NEW;
}

void FutureTask::handlePossibleCancellationInterrupt(int32_t s) {
	if (s == FutureTask::INTERRUPTING) {
		while (this->state == FutureTask::INTERRUPTING) {
			$Thread::yield();
		}
	}
}

void FutureTask::finishCompletion() {
	$useLocalCurrentObjectStackCache();
	{
		$var($FutureTask$WaitNode, q, nullptr);
		for (; ($assign(q, this->waiters)) != nullptr;) {
			if ($nc(FutureTask::WAITERS)->weakCompareAndSet($$new($ObjectArray, {$of(this), $of(q), ($Object*)nullptr}))) {
				for (;;) {
					$var($Thread, t, $nc(q)->thread);
					if (t != nullptr) {
						$set(q, thread, nullptr);
						$LockSupport::unpark(t);
					}
					$var($FutureTask$WaitNode, next, q->next);
					if (next == nullptr) {
						break;
					}
					$set(q, next, nullptr);
					$assign(q, next);
				}
				break;
			}
		}
	}
	done();
	$set(this, callable, nullptr);
}

int32_t FutureTask::awaitDone(bool timed, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	int64_t startTime = 0;
	$var($FutureTask$WaitNode, q, nullptr);
	bool queued = false;
	for (;;) {
		int32_t s = this->state;
		if (s > FutureTask::COMPLETING) {
			if (q != nullptr) {
				$set(q, thread, nullptr);
			}
			return s;
		} else if (s == FutureTask::COMPLETING) {
			$Thread::yield();
		} else if ($Thread::interrupted()) {
			removeWaiter(q);
			$throwNew($InterruptedException);
		} else if (q == nullptr) {
			if (timed && nanos <= (int64_t)0) {
				return s;
			}
			$assign(q, $new($FutureTask$WaitNode));
		} else if (!queued) {
			$var($Object, var$0, $of(($set($nc(q), next, this->waiters))));
			queued = $nc(FutureTask::WAITERS)->weakCompareAndSet($$new($ObjectArray, {$of(this), var$0, $of(q)}));
		} else if (timed) {
			int64_t parkNanos = 0;
			if (startTime == (int64_t)0) {
				startTime = $System::nanoTime();
				if (startTime == (int64_t)0) {
					startTime = 1;
				}
				parkNanos = nanos;
			} else {
				int64_t elapsed = $System::nanoTime() - startTime;
				if (elapsed >= nanos) {
					removeWaiter(q);
					return this->state;
				}
				parkNanos = nanos - elapsed;
			}
			if (this->state < FutureTask::COMPLETING) {
				$LockSupport::parkNanos(this, parkNanos);
			}
		} else {
			$LockSupport::park(this);
		}
	}
}

void FutureTask::removeWaiter($FutureTask$WaitNode* node) {
	$useLocalCurrentObjectStackCache();
	if (node != nullptr) {
		$set(node, thread, nullptr);
		bool retry$continue = false;
		for (;;) {
			{
				$var($FutureTask$WaitNode, pred, nullptr);
				$var($FutureTask$WaitNode, q, this->waiters);
				$var($FutureTask$WaitNode, s, nullptr);
				for (; q != nullptr; $assign(q, s)) {
					$assign(s, $nc(q)->next);
					if (q->thread != nullptr) {
						$assign(pred, q);
					} else if (pred != nullptr) {
						$set(pred, next, s);
						if (pred->thread == nullptr) {
							retry$continue = true;
							break;
						}
					} else if (!$nc(FutureTask::WAITERS)->compareAndSet($$new($ObjectArray, {$of(this), $of(q), $of(s)}))) {
						retry$continue = true;
						break;
					}
				}
				if (retry$continue) {
					retry$continue = false;
					continue;
				}
			}
			break;
		}
	}
}

$String* FutureTask::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, status, nullptr);
	{
		$var($Callable, callable, nullptr)
		switch (this->state) {
		case FutureTask::NORMAL:
			{
				$assign(status, "[Completed normally]"_s);
				break;
			}
		case FutureTask::EXCEPTIONAL:
			{
				$assign(status, $str({"[Completed exceptionally: "_s, this->outcome, "]"_s}));
				break;
			}
		case FutureTask::CANCELLED:
			{}
		case FutureTask::INTERRUPTING:
			{}
		case FutureTask::INTERRUPTED:
			{
				$assign(status, "[Cancelled]"_s);
				break;
			}
		default:
			{
				$assign(callable, this->callable);
				$assign(status, (callable == nullptr) ? "[Not completed]"_s : $str({"[Not completed, task = "_s, callable, "]"_s}));
			}
		}
	}
	return $str({$($RunnableFuture::toString()), status});
}

void clinit$FutureTask($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(FutureTask::STATE, $nc(l)->findVarHandle(FutureTask::class$, "state"_s, $Integer::TYPE));
			$assignStatic(FutureTask::RUNNER, l->findVarHandle(FutureTask::class$, "runner"_s, $Thread::class$));
			$load($FutureTask$WaitNode);
			$assignStatic(FutureTask::WAITERS, l->findVarHandle(FutureTask::class$, "waiters"_s, $FutureTask$WaitNode::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
		$load($LockSupport);
		$Class* ensureLoaded = $LockSupport::class$;
	}
}

FutureTask::FutureTask() {
}

$Class* FutureTask::load$($String* name, bool initialize) {
	$loadClass(FutureTask, name, initialize, &_FutureTask_ClassInfo_, clinit$FutureTask, allocate$FutureTask);
	return class$;
}

$Class* FutureTask::class$ = nullptr;

		} // concurrent
	} // util
} // java