#include <java/util/concurrent/SubmissionPublisher$BufferedSubscription.h>

#include <java/lang/Error.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/Arrays.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/ForkJoinPool$ManagedBlocker.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/SubmissionPublisher$ConsumerTask.h>
#include <java/util/concurrent/SubmissionPublisher.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <java/util/function/BiConsumer.h>
#include <jcpp.h>

#undef ACTIVE
#undef CLOSED
#undef COMPLETE
#undef CTL
#undef DEMAND
#undef ERROR
#undef INTERRUPTED
#undef MAX_VALUE
#undef OPEN
#undef QA
#undef REQS
#undef RUN
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Error = ::java::lang::Error;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Arrays = ::java::util::Arrays;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$ManagedBlocker = ::java::util::concurrent::ForkJoinPool$ManagedBlocker;
using $SubmissionPublisher$ConsumerTask = ::java::util::concurrent::SubmissionPublisher$ConsumerTask;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;
using $BiConsumer = ::java::util::function::BiConsumer;

namespace java {
	namespace util {
		namespace concurrent {

$CompoundAttribute _SubmissionPublisher$BufferedSubscription_Annotations_[] = {
	{"Ljdk/internal/vm/annotation/Contended;", nullptr},
	{}
};

$NamedAttribute SubmissionPublisher$BufferedSubscription_Attribute_var$0[] = {
	{"value", 's', "c"},
	{}
};

$CompoundAttribute _SubmissionPublisher$BufferedSubscription_FieldAnnotations_demand[] = {
	{"Ljdk/internal/vm/annotation/Contended;", SubmissionPublisher$BufferedSubscription_Attribute_var$0},
	{}
};

$NamedAttribute SubmissionPublisher$BufferedSubscription_Attribute_var$1[] = {
	{"value", 's', "c"},
	{}
};

$CompoundAttribute _SubmissionPublisher$BufferedSubscription_FieldAnnotations_waiting[] = {
	{"Ljdk/internal/vm/annotation/Contended;", SubmissionPublisher$BufferedSubscription_Attribute_var$1},
	{}
};

$FieldInfo _SubmissionPublisher$BufferedSubscription_FieldInfo_[] = {
	{"timeout", "J", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, timeout)},
	{"head", "I", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, head)},
	{"tail", "I", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, tail)},
	{"maxCapacity", "I", nullptr, $FINAL, $field(SubmissionPublisher$BufferedSubscription, maxCapacity)},
	{"ctl", "I", nullptr, $VOLATILE, $field(SubmissionPublisher$BufferedSubscription, ctl)},
	{"array", "[Ljava/lang/Object;", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, array)},
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-TT;>;", $FINAL, $field(SubmissionPublisher$BufferedSubscription, subscriber)},
	{"onNextHandler", "Ljava/util/function/BiConsumer;", "Ljava/util/function/BiConsumer<-Ljava/util/concurrent/Flow$Subscriber<-TT;>;-Ljava/lang/Throwable;>;", $FINAL, $field(SubmissionPublisher$BufferedSubscription, onNextHandler)},
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, executor)},
	{"waiter", "Ljava/lang/Thread;", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, waiter)},
	{"pendingError", "Ljava/lang/Throwable;", nullptr, 0, $field(SubmissionPublisher$BufferedSubscription, pendingError)},
	{"next", "Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription;", "Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription<TT;>;", 0, $field(SubmissionPublisher$BufferedSubscription, next)},
	{"nextRetry", "Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription;", "Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription<TT;>;", 0, $field(SubmissionPublisher$BufferedSubscription, nextRetry)},
	{"demand", "J", nullptr, $VOLATILE, $field(SubmissionPublisher$BufferedSubscription, demand), _SubmissionPublisher$BufferedSubscription_FieldAnnotations_demand},
	{"waiting", "I", nullptr, $VOLATILE, $field(SubmissionPublisher$BufferedSubscription, waiting), _SubmissionPublisher$BufferedSubscription_FieldAnnotations_waiting},
	{"CLOSED", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, CLOSED)},
	{"ACTIVE", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, ACTIVE)},
	{"REQS", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, REQS)},
	{"ERROR", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, ERROR)},
	{"COMPLETE", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, COMPLETE)},
	{"RUN", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, RUN)},
	{"OPEN", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, OPEN)},
	{"INTERRUPTED", "J", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher$BufferedSubscription, INTERRUPTED)},
	{"CTL", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(SubmissionPublisher$BufferedSubscription, CTL)},
	{"DEMAND", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(SubmissionPublisher$BufferedSubscription, DEMAND)},
	{"QA", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(SubmissionPublisher$BufferedSubscription, QA)},
	{}
};

$MethodInfo _SubmissionPublisher$BufferedSubscription_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/Executor;Ljava/util/function/BiConsumer;[Ljava/lang/Object;I)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;Ljava/util/concurrent/Executor;Ljava/util/function/BiConsumer<-Ljava/util/concurrent/Flow$Subscriber<-TT;>;-Ljava/lang/Throwable;>;[Ljava/lang/Object;I)V", 0, $method(SubmissionPublisher$BufferedSubscription, init$, void, $Flow$Subscriber*, $Executor*, $BiConsumer*, $ObjectArray*, int32_t)},
	{"awaitSpace", "(J)V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, awaitSpace, void, int64_t)},
	{"block", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(SubmissionPublisher$BufferedSubscription, block, bool)},
	{"cancel", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(SubmissionPublisher$BufferedSubscription, cancel, void)},
	{"casDemand", "(JJ)Z", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, casDemand, bool, int64_t, int64_t)},
	{"closeOnComplete", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, closeOnComplete, void, $Flow$Subscriber*)},
	{"closeOnError", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/lang/Throwable;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;Ljava/lang/Throwable;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, closeOnError, void, $Flow$Subscriber*, $Throwable*)},
	{"consume", "()V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, consume, void)},
	{"consumeComplete", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, consumeComplete, void, $Flow$Subscriber*)},
	{"consumeError", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/lang/Throwable;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;Ljava/lang/Throwable;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, consumeError, void, $Flow$Subscriber*, $Throwable*)},
	{"consumeNext", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/lang/Object;)Z", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;Ljava/lang/Object;)Z", $FINAL, $method(SubmissionPublisher$BufferedSubscription, consumeNext, bool, $Flow$Subscriber*, Object$*)},
	{"consumeSubscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, consumeSubscribe, void, $Flow$Subscriber*)},
	{"estimateLag", "()I", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, estimateLag, int32_t)},
	{"getAndBitwiseOrCtl", "(I)I", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, getAndBitwiseOrCtl, int32_t, int32_t)},
	{"growAndOffer", "(Ljava/lang/Object;[Ljava/lang/Object;I)Z", "(TT;[Ljava/lang/Object;I)Z", $FINAL, $method(SubmissionPublisher$BufferedSubscription, growAndOffer, bool, Object$*, $ObjectArray*, int32_t)},
	{"handleOnNext", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/lang/Throwable;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;Ljava/lang/Throwable;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, handleOnNext, void, $Flow$Subscriber*, $Throwable*)},
	{"isClosed", "()Z", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, isClosed, bool)},
	{"isReleasable", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(SubmissionPublisher$BufferedSubscription, isReleasable, bool)},
	{"offer", "(Ljava/lang/Object;Z)I", "(TT;Z)I", $FINAL, $method(SubmissionPublisher$BufferedSubscription, offer, int32_t, Object$*, bool)},
	{"onComplete", "()V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, onComplete, void)},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, onError, void, $Throwable*)},
	{"onSubscribe", "()V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, onSubscribe, void)},
	{"request", "(J)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(SubmissionPublisher$BufferedSubscription, request, void, int64_t)},
	{"retryOffer", "(Ljava/lang/Object;)I", "(TT;)I", $FINAL, $method(SubmissionPublisher$BufferedSubscription, retryOffer, int32_t, Object$*)},
	{"signalWaiter", "()V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, signalWaiter, void)},
	{"startOnOffer", "(I)I", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, startOnOffer, int32_t, int32_t)},
	{"startOnSignal", "(I)V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, startOnSignal, void, int32_t)},
	{"subscribeOnOpen", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;)V", $FINAL, $method(SubmissionPublisher$BufferedSubscription, subscribeOnOpen, void, $Flow$Subscriber*)},
	{"subtractDemand", "(I)J", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, subtractDemand, int64_t, int32_t)},
	{"takeItems", "(Ljava/util/concurrent/Flow$Subscriber;JI)I", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;JI)I", $FINAL, $method(SubmissionPublisher$BufferedSubscription, takeItems, int32_t, $Flow$Subscriber*, int64_t, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryStart", "()V", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, tryStart, void)},
	{"weakCasCtl", "(II)Z", nullptr, $FINAL, $method(SubmissionPublisher$BufferedSubscription, weakCasCtl, bool, int32_t, int32_t)},
	{}
};

$InnerClassInfo _SubmissionPublisher$BufferedSubscription_InnerClassesInfo_[] = {
	{"java.util.concurrent.SubmissionPublisher$BufferedSubscription", "java.util.concurrent.SubmissionPublisher", "BufferedSubscription", $STATIC | $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.ForkJoinPool$ManagedBlocker", "java.util.concurrent.ForkJoinPool", "ManagedBlocker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SubmissionPublisher$BufferedSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.SubmissionPublisher$BufferedSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription,java.util.concurrent.ForkJoinPool$ManagedBlocker",
	_SubmissionPublisher$BufferedSubscription_FieldInfo_,
	_SubmissionPublisher$BufferedSubscription_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscription;Ljava/util/concurrent/ForkJoinPool$ManagedBlocker;",
	nullptr,
	_SubmissionPublisher$BufferedSubscription_InnerClassesInfo_,
	_SubmissionPublisher$BufferedSubscription_Annotations_,
	nullptr,
	nullptr,
	"java.util.concurrent.SubmissionPublisher"
};

$Object* allocate$SubmissionPublisher$BufferedSubscription($Class* clazz) {
	return $of($alloc(SubmissionPublisher$BufferedSubscription));
}

int32_t SubmissionPublisher$BufferedSubscription::hashCode() {
	 return this->$Flow$Subscription::hashCode();
}

bool SubmissionPublisher$BufferedSubscription::equals(Object$* obj) {
	 return this->$Flow$Subscription::equals(obj);
}

$Object* SubmissionPublisher$BufferedSubscription::clone() {
	 return this->$Flow$Subscription::clone();
}

$String* SubmissionPublisher$BufferedSubscription::toString() {
	 return this->$Flow$Subscription::toString();
}

void SubmissionPublisher$BufferedSubscription::finalize() {
	this->$Flow$Subscription::finalize();
}

$VarHandle* SubmissionPublisher$BufferedSubscription::CTL = nullptr;
$VarHandle* SubmissionPublisher$BufferedSubscription::DEMAND = nullptr;
$VarHandle* SubmissionPublisher$BufferedSubscription::QA = nullptr;

void SubmissionPublisher$BufferedSubscription::init$($Flow$Subscriber* subscriber, $Executor* executor, $BiConsumer* onNextHandler, $ObjectArray* array, int32_t maxBufferCapacity) {
	$set(this, subscriber, subscriber);
	$set(this, executor, executor);
	$set(this, onNextHandler, onNextHandler);
	$set(this, array, array);
	this->maxCapacity = maxBufferCapacity;
}

bool SubmissionPublisher$BufferedSubscription::weakCasCtl(int32_t cmp, int32_t val) {
	return $nc(SubmissionPublisher$BufferedSubscription::CTL)->weakCompareAndSet($$new($ObjectArray, {$of(this), $$of(cmp), $$of(val)}));
}

int32_t SubmissionPublisher$BufferedSubscription::getAndBitwiseOrCtl(int32_t bits) {
	return $intValue($nc(SubmissionPublisher$BufferedSubscription::CTL)->getAndBitwiseOr($$new($ObjectArray, {$of(this), $$of(bits)})));
}

int64_t SubmissionPublisher$BufferedSubscription::subtractDemand(int32_t k) {
	int64_t n = (int64_t)(-k);
	return n + $longValue($nc(SubmissionPublisher$BufferedSubscription::DEMAND)->getAndAdd($$new($ObjectArray, {$of(this), $$of(n)})));
}

bool SubmissionPublisher$BufferedSubscription::casDemand(int64_t cmp, int64_t val) {
	return $nc(SubmissionPublisher$BufferedSubscription::DEMAND)->compareAndSet($$new($ObjectArray, {$of(this), $$of(cmp), $$of(val)}));
}

bool SubmissionPublisher$BufferedSubscription::isClosed() {
	return ((int32_t)(this->ctl & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) != 0;
}

int32_t SubmissionPublisher$BufferedSubscription::estimateLag() {
	int32_t c = this->ctl;
	int32_t n = this->tail - this->head;
	return (((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) != 0) ? -1 : (n < 0) ? 0 : n;
}

int32_t SubmissionPublisher$BufferedSubscription::offer(Object$* item, bool unowned) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, nullptr);
	int32_t stat = 0;
	int32_t cap = (($assign(a, this->array)) == nullptr) ? 0 : $nc(a)->length;
	int32_t t = this->tail;
	int32_t i = (int32_t)(t & (uint32_t)(cap - 1));
	int32_t n = t + 1 - this->head;
	if (cap > 0) {
		bool added = false;
		if (n >= cap && cap < this->maxCapacity) {
			added = growAndOffer(item, a, t);
		} else if (n >= cap || unowned) {
			added = $nc(SubmissionPublisher$BufferedSubscription::QA)->compareAndSet($$new($ObjectArray, {$of(a), $$of(i), ($Object*)nullptr, item}));
		} else {
			$nc(SubmissionPublisher$BufferedSubscription::QA)->setRelease($$new($ObjectArray, {$of(a), $$of(i), item}));
			added = true;
		}
		if (added) {
			this->tail = t + 1;
			stat = n;
		}
	}
	return startOnOffer(stat);
}

bool SubmissionPublisher$BufferedSubscription::growAndOffer(Object$* item, $ObjectArray* a, int32_t t) {
	$useLocalCurrentObjectStackCache();
	int32_t cap = 0;
	int32_t newCap = 0;
	$var($ObjectArray, newArray, nullptr);
	bool var$0 = a != nullptr && (cap = a->length) > 0;
	if (var$0 && (newCap = cap << 1) > 0) {
		try {
			$assign(newArray, $new($ObjectArray, newCap));
		} catch ($OutOfMemoryError& ex) {
		}
	}
	if (newArray == nullptr) {
		return false;
	} else {
		int32_t newMask = newCap - 1;
		$nc(newArray)->set((int32_t)(t-- & (uint32_t)newMask), item);
		{
			int32_t mask = cap - 1;
			int32_t k = mask;
			for (; k >= 0; --k) {
				$var($Object, x, $nc(SubmissionPublisher$BufferedSubscription::QA)->getAndSet($$new($ObjectArray, {$of(a), $$of(((int32_t)(t & (uint32_t)mask))), ($Object*)nullptr})));
				if (x == nullptr) {
					break;
				} else {
					newArray->set((int32_t)(t-- & (uint32_t)newMask), x);
				}
			}
		}
		$set(this, array, newArray);
		$VarHandle::releaseFence();
		return true;
	}
}

int32_t SubmissionPublisher$BufferedSubscription::retryOffer(Object$* item) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, nullptr);
	int32_t stat = 0;
	int32_t t = this->tail;
	int32_t h = this->head;
	int32_t cap = 0;
	bool var$1 = ($assign(a, this->array)) != nullptr;
	bool var$0 = var$1 && (cap = $nc(a)->length) > 0;
	if (var$0 && $nc(SubmissionPublisher$BufferedSubscription::QA)->compareAndSet($$new($ObjectArray, {$of(a), $$of(((int32_t)((cap - 1) & (uint32_t)t))), ($Object*)nullptr, item}))) {
		stat = (this->tail = t + 1) - h;
	}
	return startOnOffer(stat);
}

int32_t SubmissionPublisher$BufferedSubscription::startOnOffer(int32_t stat) {
	int32_t c = 0;
	bool var$0 = ((int32_t)((c = this->ctl) & (uint32_t)(SubmissionPublisher$BufferedSubscription::REQS | SubmissionPublisher$BufferedSubscription::ACTIVE))) == SubmissionPublisher$BufferedSubscription::REQS;
	if (var$0 && ((int32_t)((c = getAndBitwiseOrCtl(SubmissionPublisher$BufferedSubscription::RUN | SubmissionPublisher$BufferedSubscription::ACTIVE)) & (uint32_t)(SubmissionPublisher$BufferedSubscription::RUN | SubmissionPublisher$BufferedSubscription::CLOSED))) == 0) {
		tryStart();
	} else if (((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) != 0) {
		stat = -1;
	}
	return stat;
}

void SubmissionPublisher$BufferedSubscription::tryStart() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Executor, e, nullptr);
		$var($SubmissionPublisher$ConsumerTask, task, $new($SubmissionPublisher$ConsumerTask, this));
		if (($assign(e, this->executor)) != nullptr) {
			$nc(e)->execute(task);
		}
	} catch ($RuntimeException& ex) {
		getAndBitwiseOrCtl(SubmissionPublisher$BufferedSubscription::ERROR | SubmissionPublisher$BufferedSubscription::CLOSED);
		$throw(ex);
	} catch ($Error& ex) {
		getAndBitwiseOrCtl(SubmissionPublisher$BufferedSubscription::ERROR | SubmissionPublisher$BufferedSubscription::CLOSED);
		$throw(ex);
	}
}

void SubmissionPublisher$BufferedSubscription::startOnSignal(int32_t bits) {
	if (((int32_t)(this->ctl & (uint32_t)bits)) != bits && ((int32_t)(getAndBitwiseOrCtl(bits) & (uint32_t)(SubmissionPublisher$BufferedSubscription::RUN | SubmissionPublisher$BufferedSubscription::CLOSED))) == 0) {
		tryStart();
	}
}

void SubmissionPublisher$BufferedSubscription::onSubscribe() {
	startOnSignal(SubmissionPublisher$BufferedSubscription::RUN | SubmissionPublisher$BufferedSubscription::ACTIVE);
}

void SubmissionPublisher$BufferedSubscription::onComplete() {
	startOnSignal((SubmissionPublisher$BufferedSubscription::RUN | SubmissionPublisher$BufferedSubscription::ACTIVE) | SubmissionPublisher$BufferedSubscription::COMPLETE);
}

void SubmissionPublisher$BufferedSubscription::onError($Throwable* ex) {
	int32_t c = 0;
	$var($ObjectArray, a, nullptr);
	if (ex != nullptr) {
		$set(this, pendingError, ex);
	}
	if (((int32_t)((c = getAndBitwiseOrCtl((SubmissionPublisher$BufferedSubscription::ERROR | SubmissionPublisher$BufferedSubscription::RUN) | SubmissionPublisher$BufferedSubscription::ACTIVE)) & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) == 0) {
		if (((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::RUN)) == 0) {
			tryStart();
		} else if (($assign(a, this->array)) != nullptr) {
			$Arrays::fill(a, ($Object*)nullptr);
		}
	}
}

void SubmissionPublisher$BufferedSubscription::cancel() {
	onError(nullptr);
}

void SubmissionPublisher$BufferedSubscription::request(int64_t n) {
	if (n > (int64_t)0) {
		for (;;) {
			int64_t p = this->demand;
			int64_t d = p + n;
			if (casDemand(p, d < p ? $Long::MAX_VALUE : d)) {
				break;
			}
		}
		startOnSignal((SubmissionPublisher$BufferedSubscription::RUN | SubmissionPublisher$BufferedSubscription::ACTIVE) | SubmissionPublisher$BufferedSubscription::REQS);
	} else {
		onError($$new($IllegalArgumentException, "non-positive subscription request"_s));
	}
}

void SubmissionPublisher$BufferedSubscription::consume() {
	$var($Flow$Subscriber, s, nullptr);
	if (($assign(s, this->subscriber)) != nullptr) {
		subscribeOnOpen(s);
		int64_t d = this->demand;
		{
			int32_t h = this->head;
			int32_t t = this->tail;
			for (;;) {
				int32_t c = 0;
				int32_t taken = 0;
				bool empty = false;
				if (((int32_t)((c = this->ctl) & (uint32_t)SubmissionPublisher$BufferedSubscription::ERROR)) != 0) {
					closeOnError(s, nullptr);
					break;
				} else if ((taken = takeItems(s, d, h)) > 0) {
					this->head = h += taken;
					d = subtractDemand(taken);
				} else if ((d = this->demand) == (int64_t)0 && ((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::REQS)) != 0) {
					weakCasCtl(c, (int32_t)(c & (uint32_t)~SubmissionPublisher$BufferedSubscription::REQS));
				} else if (d != (int64_t)0 && ((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::REQS)) == 0) {
					weakCasCtl(c, c | SubmissionPublisher$BufferedSubscription::REQS);
				} else {
					int32_t var$1 = t;
					if (var$1 == (t = this->tail)) {
						if ((empty = (t == h)) && ((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::COMPLETE)) != 0) {
							closeOnComplete(s);
							break;
						} else if (empty || d == (int64_t)0) {
							int32_t bit = (((int32_t)(c & (uint32_t)SubmissionPublisher$BufferedSubscription::ACTIVE)) != 0) ? SubmissionPublisher$BufferedSubscription::ACTIVE : SubmissionPublisher$BufferedSubscription::RUN;
							if (weakCasCtl(c, (int32_t)(c & (uint32_t)~bit)) && bit == SubmissionPublisher$BufferedSubscription::RUN) {
								break;
							}
						}
					}
				}
			}
		}
	}
}

int32_t SubmissionPublisher$BufferedSubscription::takeItems($Flow$Subscriber* s, int64_t d, int32_t h) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, nullptr);
	int32_t k = 0;
	int32_t cap = 0;
	bool var$0 = ($assign(a, this->array)) != nullptr;
	if (var$0 && (cap = $nc(a)->length) > 0) {
		int32_t m = cap - 1;
		int32_t b = ((int32_t)((uint32_t)m >> 3)) + 1;
		int32_t n = (d < (int64_t)b) ? (int32_t)d : b;
		for (; k < n; ++h, ++k) {
			$var($Object, x, $nc(SubmissionPublisher$BufferedSubscription::QA)->getAndSet($$new($ObjectArray, {$of(a), $$of(((int32_t)(h & (uint32_t)m))), ($Object*)nullptr})));
			if (this->waiting != 0) {
				signalWaiter();
			}
			if (x == nullptr) {
				break;
			} else if (!consumeNext(s, x)) {
				break;
			}
		}
	}
	return k;
}

bool SubmissionPublisher$BufferedSubscription::consumeNext($Flow$Subscriber* s, Object$* x) {
	try {
		$var($Object, y, x);
		if (s != nullptr) {
			s->onNext(y);
		}
		return true;
	} catch ($Throwable& ex) {
		handleOnNext(s, ex);
		return false;
	}
	$shouldNotReachHere();
}

void SubmissionPublisher$BufferedSubscription::handleOnNext($Flow$Subscriber* s, $Throwable* ex) {
	$var($BiConsumer, h, nullptr);
	try {
		if (($assign(h, this->onNextHandler)) != nullptr) {
			$nc(h)->accept(s, ex);
		}
	} catch ($Throwable& ignore) {
	}
	closeOnError(s, ex);
}

void SubmissionPublisher$BufferedSubscription::subscribeOnOpen($Flow$Subscriber* s) {
	if (((int32_t)(this->ctl & (uint32_t)SubmissionPublisher$BufferedSubscription::OPEN)) == 0 && ((int32_t)(getAndBitwiseOrCtl(SubmissionPublisher$BufferedSubscription::OPEN) & (uint32_t)SubmissionPublisher$BufferedSubscription::OPEN)) == 0) {
		consumeSubscribe(s);
	}
}

void SubmissionPublisher$BufferedSubscription::consumeSubscribe($Flow$Subscriber* s) {
	try {
		if (s != nullptr) {
			s->onSubscribe(this);
		}
	} catch ($Throwable& ex) {
		closeOnError(s, ex);
	}
}

void SubmissionPublisher$BufferedSubscription::closeOnComplete($Flow$Subscriber* s) {
	if (((int32_t)(getAndBitwiseOrCtl(SubmissionPublisher$BufferedSubscription::CLOSED) & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) == 0) {
		consumeComplete(s);
	}
}

void SubmissionPublisher$BufferedSubscription::consumeComplete($Flow$Subscriber* s) {
	try {
		if (s != nullptr) {
			s->onComplete();
		}
	} catch ($Throwable& ignore) {
	}
}

void SubmissionPublisher$BufferedSubscription::closeOnError($Flow$Subscriber* s, $Throwable* ex$renamed) {
	$var($Throwable, ex, ex$renamed);
	if (((int32_t)(getAndBitwiseOrCtl(SubmissionPublisher$BufferedSubscription::ERROR | SubmissionPublisher$BufferedSubscription::CLOSED) & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) == 0) {
		if (ex == nullptr) {
			$assign(ex, this->pendingError);
		}
		$set(this, pendingError, nullptr);
		$set(this, executor, nullptr);
		signalWaiter();
		consumeError(s, ex);
	}
}

void SubmissionPublisher$BufferedSubscription::consumeError($Flow$Subscriber* s, $Throwable* ex) {
	try {
		if (ex != nullptr && s != nullptr) {
			s->onError(ex);
		}
	} catch ($Throwable& ignore) {
	}
}

void SubmissionPublisher$BufferedSubscription::signalWaiter() {
	$var($Thread, w, nullptr);
	this->waiting = 0;
	if (($assign(w, this->waiter)) != nullptr) {
		$LockSupport::unpark(w);
	}
}

bool SubmissionPublisher$BufferedSubscription::isReleasable() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, nullptr);
	int32_t cap = 0;
	bool var$0 = ((int32_t)(this->ctl & (uint32_t)SubmissionPublisher$BufferedSubscription::CLOSED)) != 0;
	if (!var$0) {
		bool var$2 = ($assign(a, this->array)) != nullptr;
		bool var$1 = var$2 && (cap = $nc(a)->length) > 0;
		var$0 = (var$1 && $nc(SubmissionPublisher$BufferedSubscription::QA)->getAcquire($$new($ObjectArray, {$of(a), $$of(((int32_t)((cap - 1) & (uint32_t)this->tail)))})) == nullptr);
	}
	return (var$0);
}

void SubmissionPublisher$BufferedSubscription::awaitSpace(int64_t nanos) {
	if (!isReleasable()) {
		$ForkJoinPool::helpAsyncBlocker(this->executor, this);
		if (!isReleasable()) {
			this->timeout = nanos;
			try {
				$ForkJoinPool::managedBlock(this);
			} catch ($InterruptedException& ie) {
				this->timeout = SubmissionPublisher$BufferedSubscription::INTERRUPTED;
			}
			if (this->timeout == SubmissionPublisher$BufferedSubscription::INTERRUPTED) {
				$($Thread::currentThread())->interrupt();
			}
		}
	}
}

bool SubmissionPublisher$BufferedSubscription::block() {
	int64_t nanos = this->timeout;
	bool timed = (nanos < $Long::MAX_VALUE);
	int64_t deadline = timed ? $System::nanoTime() + nanos : (int64_t)0;
	while (!isReleasable()) {
		if ($Thread::interrupted()) {
			this->timeout = SubmissionPublisher$BufferedSubscription::INTERRUPTED;
			if (timed) {
				break;
			}
		} else if (timed && (nanos = deadline - $System::nanoTime()) <= (int64_t)0) {
			break;
		} else if (this->waiter == nullptr) {
			$set(this, waiter, $Thread::currentThread());
		} else if (this->waiting == 0) {
			this->waiting = 1;
		} else if (timed) {
			$LockSupport::parkNanos(this, nanos);
		} else {
			$LockSupport::park(this);
		}
	}
	$set(this, waiter, nullptr);
	this->waiting = 0;
	return true;
}

void clinit$SubmissionPublisher$BufferedSubscription($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(SubmissionPublisher$BufferedSubscription::CTL, $nc(l)->findVarHandle(SubmissionPublisher$BufferedSubscription::class$, "ctl"_s, $Integer::TYPE));
			$init($Long);
			$assignStatic(SubmissionPublisher$BufferedSubscription::DEMAND, l->findVarHandle(SubmissionPublisher$BufferedSubscription::class$, "demand"_s, $Long::TYPE));
			$load($ObjectArray);
			$assignStatic(SubmissionPublisher$BufferedSubscription::QA, $MethodHandles::arrayElementVarHandle($getClass($ObjectArray)));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
		$load($LockSupport);
		$Class* ensureLoaded = $LockSupport::class$;
	}
}

SubmissionPublisher$BufferedSubscription::SubmissionPublisher$BufferedSubscription() {
}

$Class* SubmissionPublisher$BufferedSubscription::load$($String* name, bool initialize) {
	$loadClass(SubmissionPublisher$BufferedSubscription, name, initialize, &_SubmissionPublisher$BufferedSubscription_ClassInfo_, clinit$SubmissionPublisher$BufferedSubscription, allocate$SubmissionPublisher$BufferedSubscription);
	return class$;
}

$Class* SubmissionPublisher$BufferedSubscription::class$ = nullptr;

		} // concurrent
	} // util
} // java