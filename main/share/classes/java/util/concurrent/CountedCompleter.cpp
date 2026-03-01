#include <java/util/concurrent/CountedCompleter.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/ForkJoinPool$WorkQueue.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/concurrent/ForkJoinWorkerThread.h>
#include <jcpp.h>

#undef PENDING
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$WorkQueue = ::java::util::concurrent::ForkJoinPool$WorkQueue;
using $ForkJoinTask = ::java::util::concurrent::ForkJoinTask;
using $ForkJoinWorkerThread = ::java::util::concurrent::ForkJoinWorkerThread;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _CountedCompleter_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CountedCompleter, serialVersionUID)},
	{"completer", "Ljava/util/concurrent/CountedCompleter;", "Ljava/util/concurrent/CountedCompleter<*>;", $FINAL, $field(CountedCompleter, completer)},
	{"pending", "I", nullptr, $VOLATILE, $field(CountedCompleter, pending)},
	{"PENDING", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CountedCompleter, PENDING)},
	{}
};

$MethodInfo _CountedCompleter_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/CountedCompleter;I)V", "(Ljava/util/concurrent/CountedCompleter<*>;I)V", $PROTECTED, $method(CountedCompleter, init$, void, CountedCompleter*, int32_t)},
	{"<init>", "(Ljava/util/concurrent/CountedCompleter;)V", "(Ljava/util/concurrent/CountedCompleter<*>;)V", $PROTECTED, $method(CountedCompleter, init$, void, CountedCompleter*)},
	{"<init>", "()V", nullptr, $PROTECTED, $method(CountedCompleter, init$, void)},
	{"addToPendingCount", "(I)V", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, addToPendingCount, void, int32_t)},
	{"compareAndSetPendingCount", "(II)Z", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, compareAndSetPendingCount, bool, int32_t, int32_t)},
	{"complete", "(Ljava/lang/Object;)V", "(TT;)V", $PUBLIC, $virtualMethod(CountedCompleter, complete, void, Object$*)},
	{"compute", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CountedCompleter, compute, void)},
	{"decrementPendingCountUnlessZero", "()I", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, decrementPendingCountUnlessZero, int32_t)},
	{"exec", "()Z", nullptr, $PROTECTED | $FINAL, $virtualMethod(CountedCompleter, exec, bool)},
	{"firstComplete", "()Ljava/util/concurrent/CountedCompleter;", "()Ljava/util/concurrent/CountedCompleter<*>;", $PUBLIC | $FINAL, $method(CountedCompleter, firstComplete, CountedCompleter*)},
	{"getCompleter", "()Ljava/util/concurrent/CountedCompleter;", "()Ljava/util/concurrent/CountedCompleter<*>;", $PUBLIC | $FINAL, $method(CountedCompleter, getCompleter, CountedCompleter*)},
	{"getPendingCount", "()I", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, getPendingCount, int32_t)},
	{"getRawResult", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $virtualMethod(CountedCompleter, getRawResult, $Object*)},
	{"getRoot", "()Ljava/util/concurrent/CountedCompleter;", "()Ljava/util/concurrent/CountedCompleter<*>;", $PUBLIC | $FINAL, $method(CountedCompleter, getRoot, CountedCompleter*)},
	{"helpComplete", "(I)V", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, helpComplete, void, int32_t)},
	{"nextComplete", "()Ljava/util/concurrent/CountedCompleter;", "()Ljava/util/concurrent/CountedCompleter<*>;", $PUBLIC | $FINAL, $method(CountedCompleter, nextComplete, CountedCompleter*)},
	{"onCompletion", "(Ljava/util/concurrent/CountedCompleter;)V", "(Ljava/util/concurrent/CountedCompleter<*>;)V", $PUBLIC, $virtualMethod(CountedCompleter, onCompletion, void, CountedCompleter*)},
	{"onExceptionalCompletion", "(Ljava/lang/Throwable;Ljava/util/concurrent/CountedCompleter;)Z", "(Ljava/lang/Throwable;Ljava/util/concurrent/CountedCompleter<*>;)Z", $PUBLIC, $virtualMethod(CountedCompleter, onExceptionalCompletion, bool, $Throwable*, CountedCompleter*)},
	{"propagateCompletion", "()V", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, propagateCompletion, void)},
	{"quietlyCompleteRoot", "()V", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, quietlyCompleteRoot, void)},
	{"setPendingCount", "(I)V", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, setPendingCount, void, int32_t)},
	{"setRawResult", "(Ljava/lang/Object;)V", "(TT;)V", $PROTECTED, $virtualMethod(CountedCompleter, setRawResult, void, Object$*)},
	{"tryComplete", "()V", nullptr, $PUBLIC | $FINAL, $method(CountedCompleter, tryComplete, void)},
	{"trySetException", "(Ljava/lang/Throwable;)I", nullptr, $FINAL, $virtualMethod(CountedCompleter, trySetException, int32_t, $Throwable*)},
	{"weakCompareAndSetPendingCount", "(II)Z", nullptr, $FINAL, $method(CountedCompleter, weakCompareAndSetPendingCount, bool, int32_t, int32_t)},
	{}
};

$ClassInfo _CountedCompleter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.concurrent.CountedCompleter",
	"java.util.concurrent.ForkJoinTask",
	nullptr,
	_CountedCompleter_FieldInfo_,
	_CountedCompleter_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/concurrent/ForkJoinTask<TT;>;"
};

$Object* allocate$CountedCompleter($Class* clazz) {
	return $of($alloc(CountedCompleter));
}

$VarHandle* CountedCompleter::PENDING = nullptr;

void CountedCompleter::init$(CountedCompleter* completer, int32_t initialPendingCount) {
	$ForkJoinTask::init$();
	$set(this, completer, completer);
	this->pending = initialPendingCount;
}

void CountedCompleter::init$(CountedCompleter* completer) {
	$ForkJoinTask::init$();
	$set(this, completer, completer);
}

void CountedCompleter::init$() {
	$ForkJoinTask::init$();
	$set(this, completer, nullptr);
}

void CountedCompleter::onCompletion(CountedCompleter* caller) {
}

bool CountedCompleter::onExceptionalCompletion($Throwable* ex, CountedCompleter* caller) {
	return true;
}

CountedCompleter* CountedCompleter::getCompleter() {
	return this->completer;
}

int32_t CountedCompleter::getPendingCount() {
	return this->pending;
}

void CountedCompleter::setPendingCount(int32_t count) {
	this->pending = count;
}

void CountedCompleter::addToPendingCount(int32_t delta) {
	$nc(CountedCompleter::PENDING)->getAndAdd($$new($ObjectArray, {$of(this), $$of(delta)}));
}

bool CountedCompleter::compareAndSetPendingCount(int32_t expected, int32_t count) {
	return $nc(CountedCompleter::PENDING)->compareAndSet($$new($ObjectArray, {$of(this), $$of(expected), $$of(count)}));
}

bool CountedCompleter::weakCompareAndSetPendingCount(int32_t expected, int32_t count) {
	return $nc(CountedCompleter::PENDING)->weakCompareAndSet($$new($ObjectArray, {$of(this), $$of(expected), $$of(count)}));
}

int32_t CountedCompleter::decrementPendingCountUnlessZero() {
	int32_t c = 0;
	bool var$0 = false;
	do {
		var$0 = (c = this->pending) != 0;
	} while (var$0 && !weakCompareAndSetPendingCount(c, c - 1));
	return c;
}

CountedCompleter* CountedCompleter::getRoot() {
	$useLocalCurrentObjectStackCache();
	$var(CountedCompleter, a, this);
	$var(CountedCompleter, p, nullptr);
	while (($assign(p, $nc(a)->completer)) != nullptr) {
		$assign(a, p);
	}
	return a;
}

void CountedCompleter::tryComplete() {
	$useLocalCurrentObjectStackCache();
	$var(CountedCompleter, a, this);
	$var(CountedCompleter, s, a);
	for (int32_t c = 0;;) {
		if ((c = a->pending) == 0) {
			a->onCompletion(s);
			if (($assign(a, $nc(($assign(s, a)))->completer)) == nullptr) {
				s->quietlyComplete();
				return;
			}
		} else if (a->weakCompareAndSetPendingCount(c, c - 1)) {
			return;
		}
	}
}

void CountedCompleter::propagateCompletion() {
	$useLocalCurrentObjectStackCache();
	$var(CountedCompleter, a, this);
	$var(CountedCompleter, s, nullptr);
	for (int32_t c = 0;;) {
		if ((c = a->pending) == 0) {
			if (($assign(a, $nc(($assign(s, a)))->completer)) == nullptr) {
				s->quietlyComplete();
				return;
			}
		} else if (a->weakCompareAndSetPendingCount(c, c - 1)) {
			return;
		}
	}
}

void CountedCompleter::complete(Object$* rawResult) {
	$var(CountedCompleter, p, nullptr);
	setRawResult(rawResult);
	onCompletion(this);
	quietlyComplete();
	if (($assign(p, this->completer)) != nullptr) {
		$nc(p)->tryComplete();
	}
}

CountedCompleter* CountedCompleter::firstComplete() {
	for (int32_t c = 0;;) {
		if ((c = this->pending) == 0) {
			return this;
		} else if (weakCompareAndSetPendingCount(c, c - 1)) {
			return nullptr;
		}
	}
}

CountedCompleter* CountedCompleter::nextComplete() {
	$var(CountedCompleter, p, nullptr);
	if (($assign(p, this->completer)) != nullptr) {
		return $nc(p)->firstComplete();
	} else {
		quietlyComplete();
		return nullptr;
	}
}

void CountedCompleter::quietlyCompleteRoot() {
	$useLocalCurrentObjectStackCache();
	{
		$var(CountedCompleter, a, this);
		$var(CountedCompleter, p, nullptr);
		for (;;) {
			if (($assign(p, a->completer)) == nullptr) {
				a->quietlyComplete();
				return;
			}
			$assign(a, p);
		}
	}
}

void CountedCompleter::helpComplete(int32_t maxTasks) {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	$var($Thread, t, nullptr);
	bool owned = false;
	if (owned = $instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		$assign(q, $nc(($cast($ForkJoinWorkerThread, t)))->workQueue);
	} else {
		$assign(q, $ForkJoinPool::commonQueue());
	}
	if (q != nullptr && maxTasks > 0) {
		q->helpComplete(this, owned, maxTasks);
	}
}

int32_t CountedCompleter::trySetException($Throwable* ex) {
	$useLocalCurrentObjectStackCache();
	$var(CountedCompleter, a, this);
	$var(CountedCompleter, p, a);
	bool var$0 = false;
	do {
	bool var$1 = isExceptionalStatus(a->trySetThrown(ex));
		var$0 = var$1 && a->onExceptionalCompletion(ex, p);
	} while (var$0 && ($assign(a, $nc(($assign(p, a)))->completer)) != nullptr && a->status >= 0);
	return this->status;
}

bool CountedCompleter::exec() {
	compute();
	return false;
}

$Object* CountedCompleter::getRawResult() {
	return $of(nullptr);
}

void CountedCompleter::setRawResult(Object$* t) {
}

void clinit$CountedCompleter($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(CountedCompleter::PENDING, $nc(l)->findVarHandle(CountedCompleter::class$, "pending"_s, $Integer::TYPE));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

CountedCompleter::CountedCompleter() {
}

$Class* CountedCompleter::load$($String* name, bool initialize) {
	$loadClass(CountedCompleter, name, initialize, &_CountedCompleter_ClassInfo_, clinit$CountedCompleter, allocate$CountedCompleter);
	return class$;
}

$Class* CountedCompleter::class$ = nullptr;

		} // concurrent
	} // util
} // java