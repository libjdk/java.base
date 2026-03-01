#include <java/util/concurrent/SubmissionPublisher.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/SubmissionPublisher$BufferedSubscription.h>
#include <java/util/concurrent/SubmissionPublisher$ConsumerSubscriber.h>
#include <java/util/concurrent/SubmissionPublisher$ThreadPerTaskExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

#undef ASYNC_POOL
#undef BUFFER_CAPACITY_LIMIT
#undef INITIAL_CAPACITY
#undef MAX_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Executor = ::java::util::concurrent::Executor;
using $Flow = ::java::util::concurrent::Flow;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $SubmissionPublisher$BufferedSubscription = ::java::util::concurrent::SubmissionPublisher$BufferedSubscription;
using $SubmissionPublisher$ConsumerSubscriber = ::java::util::concurrent::SubmissionPublisher$ConsumerSubscriber;
using $SubmissionPublisher$ThreadPerTaskExecutor = ::java::util::concurrent::SubmissionPublisher$ThreadPerTaskExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Consumer = ::java::util::function::Consumer;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _SubmissionPublisher_FieldInfo_[] = {
	{"BUFFER_CAPACITY_LIMIT", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher, BUFFER_CAPACITY_LIMIT)},
	{"INITIAL_CAPACITY", "I", nullptr, $STATIC | $FINAL, $constField(SubmissionPublisher, INITIAL_CAPACITY)},
	{"ASYNC_POOL", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SubmissionPublisher, ASYNC_POOL)},
	{"clients", "Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription;", "Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription<TT;>;", 0, $field(SubmissionPublisher, clients)},
	{"lock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $FINAL, $field(SubmissionPublisher, lock)},
	{"closed", "Z", nullptr, $VOLATILE, $field(SubmissionPublisher, closed)},
	{"subscribed", "Z", nullptr, 0, $field(SubmissionPublisher, subscribed)},
	{"owner", "Ljava/lang/Thread;", nullptr, 0, $field(SubmissionPublisher, owner)},
	{"closedException", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(SubmissionPublisher, closedException)},
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, $FINAL, $field(SubmissionPublisher, executor)},
	{"onNextHandler", "Ljava/util/function/BiConsumer;", "Ljava/util/function/BiConsumer<-Ljava/util/concurrent/Flow$Subscriber<-TT;>;-Ljava/lang/Throwable;>;", $FINAL, $field(SubmissionPublisher, onNextHandler)},
	{"maxBufferCapacity", "I", nullptr, $FINAL, $field(SubmissionPublisher, maxBufferCapacity)},
	{}
};

$MethodInfo _SubmissionPublisher_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/concurrent/Executor;ILjava/util/function/BiConsumer;)V", "(Ljava/util/concurrent/Executor;ILjava/util/function/BiConsumer<-Ljava/util/concurrent/Flow$Subscriber<-TT;>;-Ljava/lang/Throwable;>;)V", $PUBLIC, $method(SubmissionPublisher, init$, void, $Executor*, int32_t, $BiConsumer*)},
	{"<init>", "(Ljava/util/concurrent/Executor;I)V", nullptr, $PUBLIC, $method(SubmissionPublisher, init$, void, $Executor*, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(SubmissionPublisher, init$, void)},
	{"cleanAndCount", "()I", nullptr, $PRIVATE, $method(SubmissionPublisher, cleanAndCount, int32_t)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, close, void)},
	{"closeExceptionally", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, closeExceptionally, void, $Throwable*)},
	{"consume", "(Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/function/Consumer<-TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $virtualMethod(SubmissionPublisher, consume, $CompletableFuture*, $Consumer*)},
	{"doOffer", "(Ljava/lang/Object;JLjava/util/function/BiPredicate;)I", "(TT;JLjava/util/function/BiPredicate<Ljava/util/concurrent/Flow$Subscriber<-TT;>;-TT;>;)I", $PRIVATE, $method(SubmissionPublisher, doOffer, int32_t, Object$*, int64_t, $BiPredicate*)},
	{"estimateMaximumLag", "()I", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, estimateMaximumLag, int32_t)},
	{"estimateMinimumDemand", "()J", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, estimateMinimumDemand, int64_t)},
	{"getClosedException", "()Ljava/lang/Throwable;", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, getClosedException, $Throwable*)},
	{"getExecutor", "()Ljava/util/concurrent/Executor;", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, getExecutor, $Executor*)},
	{"getMaxBufferCapacity", "()I", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, getMaxBufferCapacity, int32_t)},
	{"getNumberOfSubscribers", "()I", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, getNumberOfSubscribers, int32_t)},
	{"getSubscribers", "()Ljava/util/List;", "()Ljava/util/List<Ljava/util/concurrent/Flow$Subscriber<-TT;>;>;", $PUBLIC, $virtualMethod(SubmissionPublisher, getSubscribers, $List*)},
	{"hasSubscribers", "()Z", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, hasSubscribers, bool)},
	{"isClosed", "()Z", nullptr, $PUBLIC, $virtualMethod(SubmissionPublisher, isClosed, bool)},
	{"isSubscribed", "(Ljava/util/concurrent/Flow$Subscriber;)Z", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;)Z", $PUBLIC, $virtualMethod(SubmissionPublisher, isSubscribed, bool, $Flow$Subscriber*)},
	{"offer", "(Ljava/lang/Object;Ljava/util/function/BiPredicate;)I", "(TT;Ljava/util/function/BiPredicate<Ljava/util/concurrent/Flow$Subscriber<-TT;>;-TT;>;)I", $PUBLIC, $virtualMethod(SubmissionPublisher, offer, int32_t, Object$*, $BiPredicate*)},
	{"offer", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;Ljava/util/function/BiPredicate;)I", "(TT;JLjava/util/concurrent/TimeUnit;Ljava/util/function/BiPredicate<Ljava/util/concurrent/Flow$Subscriber<-TT;>;-TT;>;)I", $PUBLIC, $virtualMethod(SubmissionPublisher, offer, int32_t, Object$*, int64_t, $TimeUnit*, $BiPredicate*)},
	{"retryOffer", "(Ljava/lang/Object;JLjava/util/function/BiPredicate;Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription;IZ)I", "(TT;JLjava/util/function/BiPredicate<Ljava/util/concurrent/Flow$Subscriber<-TT;>;-TT;>;Ljava/util/concurrent/SubmissionPublisher$BufferedSubscription<TT;>;IZ)I", $PRIVATE, $method(SubmissionPublisher, retryOffer, int32_t, Object$*, int64_t, $BiPredicate*, $SubmissionPublisher$BufferedSubscription*, int32_t, bool)},
	{"roundCapacity", "(I)I", nullptr, $STATIC | $FINAL, $staticMethod(SubmissionPublisher, roundCapacity, int32_t, int32_t)},
	{"submit", "(Ljava/lang/Object;)I", "(TT;)I", $PUBLIC, $virtualMethod(SubmissionPublisher, submit, int32_t, Object$*)},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;)V", $PUBLIC, $virtualMethod(SubmissionPublisher, subscribe, void, $Flow$Subscriber*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SubmissionPublisher_InnerClassesInfo_[] = {
	{"java.util.concurrent.Flow$Publisher", "java.util.concurrent.Flow", "Publisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.SubmissionPublisher$BufferedSubscription", "java.util.concurrent.SubmissionPublisher", "BufferedSubscription", $STATIC | $FINAL},
	{"java.util.concurrent.SubmissionPublisher$ConsumerTask", "java.util.concurrent.SubmissionPublisher", "ConsumerTask", $STATIC | $FINAL},
	{"java.util.concurrent.SubmissionPublisher$ConsumerSubscriber", "java.util.concurrent.SubmissionPublisher", "ConsumerSubscriber", $STATIC | $FINAL},
	{"java.util.concurrent.SubmissionPublisher$ThreadPerTaskExecutor", "java.util.concurrent.SubmissionPublisher", "ThreadPerTaskExecutor", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SubmissionPublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.SubmissionPublisher",
	"java.lang.Object",
	"java.util.concurrent.Flow$Publisher,java.lang.AutoCloseable",
	_SubmissionPublisher_FieldInfo_,
	_SubmissionPublisher_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Flow$Publisher<TT;>;Ljava/lang/AutoCloseable;",
	nullptr,
	_SubmissionPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.SubmissionPublisher$BufferedSubscription,java.util.concurrent.SubmissionPublisher$ConsumerTask,java.util.concurrent.SubmissionPublisher$ConsumerSubscriber,java.util.concurrent.SubmissionPublisher$ThreadPerTaskExecutor"
};

$Object* allocate$SubmissionPublisher($Class* clazz) {
	return $of($alloc(SubmissionPublisher));
}

int32_t SubmissionPublisher::hashCode() {
	 return this->$Flow$Publisher::hashCode();
}

bool SubmissionPublisher::equals(Object$* obj) {
	 return this->$Flow$Publisher::equals(obj);
}

$Object* SubmissionPublisher::clone() {
	 return this->$Flow$Publisher::clone();
}

$String* SubmissionPublisher::toString() {
	 return this->$Flow$Publisher::toString();
}

void SubmissionPublisher::finalize() {
	this->$Flow$Publisher::finalize();
}

$Executor* SubmissionPublisher::ASYNC_POOL = nullptr;

int32_t SubmissionPublisher::roundCapacity(int32_t cap) {
	$init(SubmissionPublisher);
	int32_t n = cap - 1;
	n |= (int32_t)((uint32_t)n >> 1);
	n |= (int32_t)((uint32_t)n >> 2);
	n |= (int32_t)((uint32_t)n >> 4);
	n |= (int32_t)((uint32_t)n >> 8);
	n |= (int32_t)((uint32_t)n >> 16);
	return (n <= 0) ? 1 : (n >= SubmissionPublisher::BUFFER_CAPACITY_LIMIT) ? SubmissionPublisher::BUFFER_CAPACITY_LIMIT : n + 1;
}

void SubmissionPublisher::init$($Executor* executor, int32_t maxBufferCapacity, $BiConsumer* handler) {
	if (executor == nullptr) {
		$throwNew($NullPointerException);
	}
	if (maxBufferCapacity <= 0) {
		$throwNew($IllegalArgumentException, "capacity must be positive"_s);
	}
	$set(this, lock, $new($ReentrantLock));
	$set(this, executor, executor);
	$set(this, onNextHandler, handler);
	this->maxBufferCapacity = roundCapacity(maxBufferCapacity);
}

void SubmissionPublisher::init$($Executor* executor, int32_t maxBufferCapacity) {
	SubmissionPublisher::init$(executor, maxBufferCapacity, nullptr);
}

void SubmissionPublisher::init$() {
	SubmissionPublisher::init$(SubmissionPublisher::ASYNC_POOL, $Flow::defaultBufferSize(), nullptr);
}

void SubmissionPublisher::subscribe($Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	if (subscriber == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ReentrantLock, lock, this->lock);
	int32_t max = this->maxBufferCapacity;
	$var($ObjectArray, array, $new($ObjectArray, max < SubmissionPublisher::INITIAL_CAPACITY ? max : SubmissionPublisher::INITIAL_CAPACITY));
	$var($SubmissionPublisher$BufferedSubscription, subscription, $new($SubmissionPublisher$BufferedSubscription, subscriber, this->executor, this->onNextHandler, array, max));
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (!this->subscribed) {
				this->subscribed = true;
				$set(this, owner, $Thread::currentThread());
			}
			{
				$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
				$var($SubmissionPublisher$BufferedSubscription, pred, nullptr);
				for (;;) {
					if (b == nullptr) {
						$var($Throwable, ex, nullptr);
						subscription->onSubscribe();
						if (($assign(ex, this->closedException)) != nullptr) {
							subscription->onError(ex);
						} else if (this->closed) {
							subscription->onComplete();
						} else if (pred == nullptr) {
							$set(this, clients, subscription);
						} else {
							$set($nc(pred), next, subscription);
						}
						break;
					}
					$var($SubmissionPublisher$BufferedSubscription, next, $nc(b)->next);
					if (b->isClosed()) {
						$set(b, next, nullptr);
						if (pred == nullptr) {
							$set(this, clients, next);
						} else {
							$set($nc(pred), next, next);
						}
					} else if ($nc($of(subscriber))->equals(b->subscriber)) {
						b->onError($$new($IllegalStateException, "Duplicate subscribe"_s));
						break;
					} else {
						$assign(pred, b);
					}
					$assign(b, next);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int32_t SubmissionPublisher::doOffer(Object$* item, int64_t nanos, $BiPredicate* onDrop) {
	$useLocalCurrentObjectStackCache();
	if (item == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t lag = 0;
	bool complete = false;
	bool unowned = false;
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Thread, t, $Thread::currentThread());
			$var($Thread, o, nullptr);
			$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
			bool var$1 = (unowned = (($assign(o, this->owner)) != t));
			if (var$1 && o != nullptr) {
				$set(this, owner, nullptr);
			}
			if (b == nullptr) {
				complete = this->closed;
			} else {
				complete = false;
				bool cleanMe = false;
				$var($SubmissionPublisher$BufferedSubscription, retries, nullptr);
				$var($SubmissionPublisher$BufferedSubscription, rtail, nullptr);
				$var($SubmissionPublisher$BufferedSubscription, next, nullptr);
				do {
					$assign(next, $nc(b)->next);
					int32_t stat = b->offer(item, unowned);
					if (stat == 0) {
						$set(b, nextRetry, nullptr);
						if (rtail == nullptr) {
							$assign(retries, b);
						} else {
							$set($nc(rtail), nextRetry, b);
						}
						$assign(rtail, b);
					} else if (stat < 0) {
						cleanMe = true;
					} else if (stat > lag) {
						lag = stat;
					}
				} while (($assign(b, next)) != nullptr);
				if (retries != nullptr || cleanMe) {
					lag = retryOffer(item, nanos, onDrop, retries, lag, cleanMe);
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (complete) {
		$throwNew($IllegalStateException, "Closed"_s);
	} else {
		return lag;
	}
}

int32_t SubmissionPublisher::retryOffer(Object$* item, int64_t nanos, $BiPredicate* onDrop, $SubmissionPublisher$BufferedSubscription* retries, int32_t lag, bool cleanMe) {
	$useLocalCurrentObjectStackCache();
	{
		$var($SubmissionPublisher$BufferedSubscription, r, retries);
		for (; r != nullptr;) {
			$var($SubmissionPublisher$BufferedSubscription, nextRetry, r->nextRetry);
			$set(r, nextRetry, nullptr);
			if (nanos > (int64_t)0) {
				r->awaitSpace(nanos);
			}
			int32_t stat = r->retryOffer(item);
			if (stat == 0 && onDrop != nullptr && onDrop->test(r->subscriber, item)) {
				stat = r->retryOffer(item);
			}
			if (stat == 0) {
				lag = (lag >= 0) ? -1 : lag - 1;
			} else if (stat < 0) {
				cleanMe = true;
			} else if (lag >= 0 && stat > lag) {
				lag = stat;
			}
			$assign(r, nextRetry);
		}
	}
	if (cleanMe) {
		cleanAndCount();
	}
	return lag;
}

int32_t SubmissionPublisher::cleanAndCount() {
	$useLocalCurrentObjectStackCache();
	int32_t count = 0;
	$var($SubmissionPublisher$BufferedSubscription, pred, nullptr);
	$var($SubmissionPublisher$BufferedSubscription, next, nullptr);
	{
		$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
		for (; b != nullptr; $assign(b, next)) {
			$assign(next, $nc(b)->next);
			if (b->isClosed()) {
				$set(b, next, nullptr);
				if (pred == nullptr) {
					$set(this, clients, next);
				} else {
					$set($nc(pred), next, next);
				}
			} else {
				$assign(pred, b);
				++count;
			}
		}
	}
	return count;
}

int32_t SubmissionPublisher::submit(Object$* item) {
	return doOffer(item, $Long::MAX_VALUE, nullptr);
}

int32_t SubmissionPublisher::offer(Object$* item, $BiPredicate* onDrop) {
	return doOffer(item, 0, onDrop);
}

int32_t SubmissionPublisher::offer(Object$* item, int64_t timeout, $TimeUnit* unit, $BiPredicate* onDrop) {
	int64_t nanos = $nc(unit)->toNanos(timeout);
	if (nanos == $Long::MAX_VALUE) {
		--nanos;
	}
	return doOffer(item, nanos, onDrop);
}

void SubmissionPublisher::close() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	if (!this->closed) {
		$var($SubmissionPublisher$BufferedSubscription, b, nullptr);
		$nc(lock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				$assign(b, this->clients);
				$set(this, clients, nullptr);
				$set(this, owner, nullptr);
				this->closed = true;
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				lock->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		while (b != nullptr) {
			$var($SubmissionPublisher$BufferedSubscription, next, b->next);
			$set(b, next, nullptr);
			b->onComplete();
			$assign(b, next);
		}
	}
}

void SubmissionPublisher::closeExceptionally($Throwable* error) {
	$useLocalCurrentObjectStackCache();
	if (error == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ReentrantLock, lock, this->lock);
	if (!this->closed) {
		$var($SubmissionPublisher$BufferedSubscription, b, nullptr);
		$nc(lock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				$assign(b, this->clients);
				if (!this->closed) {
					$set(this, closedException, error);
					$set(this, clients, nullptr);
					$set(this, owner, nullptr);
					this->closed = true;
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				lock->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		while (b != nullptr) {
			$var($SubmissionPublisher$BufferedSubscription, next, b->next);
			$set(b, next, nullptr);
			b->onError(error);
			$assign(b, next);
		}
	}
}

bool SubmissionPublisher::isClosed() {
	return this->closed;
}

$Throwable* SubmissionPublisher::getClosedException() {
	return this->closedException;
}

bool SubmissionPublisher::hasSubscribers() {
	$useLocalCurrentObjectStackCache();
	bool nonEmpty = false;
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			{
				$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
				for (; b != nullptr;) {
					$var($SubmissionPublisher$BufferedSubscription, next, b->next);
					if (b->isClosed()) {
						$set(b, next, nullptr);
						$assign(b, ($set(this, clients, next)));
					} else {
						nonEmpty = true;
						break;
					}
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return nonEmpty;
}

int32_t SubmissionPublisher::getNumberOfSubscribers() {
	$useLocalCurrentObjectStackCache();
	int32_t n = 0;
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			n = cleanAndCount();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return n;
}

$Executor* SubmissionPublisher::getExecutor() {
	return this->executor;
}

int32_t SubmissionPublisher::getMaxBufferCapacity() {
	return this->maxBufferCapacity;
}

$List* SubmissionPublisher::getSubscribers() {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, subs, $new($ArrayList));
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($SubmissionPublisher$BufferedSubscription, pred, nullptr);
			$var($SubmissionPublisher$BufferedSubscription, next, nullptr);
			{
				$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
				for (; b != nullptr; $assign(b, next)) {
					$assign(next, $nc(b)->next);
					if (b->isClosed()) {
						$set(b, next, nullptr);
						if (pred == nullptr) {
							$set(this, clients, next);
						} else {
							$set($nc(pred), next, next);
						}
					} else {
						subs->add(b->subscriber);
						$assign(pred, b);
					}
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return subs;
}

bool SubmissionPublisher::isSubscribed($Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	if (subscriber == nullptr) {
		$throwNew($NullPointerException);
	}
	bool subscribed = false;
	$var($ReentrantLock, lock, this->lock);
	if (!this->closed) {
		$nc(lock)->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				$var($SubmissionPublisher$BufferedSubscription, pred, nullptr);
				$var($SubmissionPublisher$BufferedSubscription, next, nullptr);
				{
					$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
					for (; b != nullptr; $assign(b, next)) {
						$assign(next, $nc(b)->next);
						if (b->isClosed()) {
							$set(b, next, nullptr);
							if (pred == nullptr) {
								$set(this, clients, next);
							} else {
								$set($nc(pred), next, next);
							}
						} else if (subscribed = $nc($of(subscriber))->equals(b->subscriber)) {
							break;
						} else {
							$assign(pred, b);
						}
					}
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				lock->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	return subscribed;
}

int64_t SubmissionPublisher::estimateMinimumDemand() {
	$useLocalCurrentObjectStackCache();
	int64_t min = $Long::MAX_VALUE;
	bool nonEmpty = false;
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($SubmissionPublisher$BufferedSubscription, pred, nullptr);
			$var($SubmissionPublisher$BufferedSubscription, next, nullptr);
			{
				$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
				for (; b != nullptr; $assign(b, next)) {
					int32_t n = 0;
					int64_t d = 0;
					$assign(next, $nc(b)->next);
					if ((n = b->estimateLag()) < 0) {
						$set(b, next, nullptr);
						if (pred == nullptr) {
							$set(this, clients, next);
						} else {
							$set($nc(pred), next, next);
						}
					} else {
						if ((d = b->demand - n) < min) {
							min = d;
						}
						nonEmpty = true;
						$assign(pred, b);
					}
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return nonEmpty ? min : (int64_t)0;
}

int32_t SubmissionPublisher::estimateMaximumLag() {
	$useLocalCurrentObjectStackCache();
	int32_t max = 0;
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($SubmissionPublisher$BufferedSubscription, pred, nullptr);
			$var($SubmissionPublisher$BufferedSubscription, next, nullptr);
			{
				$var($SubmissionPublisher$BufferedSubscription, b, this->clients);
				for (; b != nullptr; $assign(b, next)) {
					int32_t n = 0;
					$assign(next, $nc(b)->next);
					if ((n = b->estimateLag()) < 0) {
						$set(b, next, nullptr);
						if (pred == nullptr) {
							$set(this, clients, next);
						} else {
							$set($nc(pred), next, next);
						}
					} else {
						if (n > max) {
							max = n;
						}
						$assign(pred, b);
					}
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return max;
}

$CompletableFuture* SubmissionPublisher::consume($Consumer* consumer) {
	$useLocalCurrentObjectStackCache();
	if (consumer == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($CompletableFuture, status, $new($CompletableFuture));
	subscribe($$new($SubmissionPublisher$ConsumerSubscriber, status, consumer));
	return status;
}

void clinit$SubmissionPublisher($Class* class$) {
	$assignStatic(SubmissionPublisher::ASYNC_POOL, ($ForkJoinPool::getCommonPoolParallelism() > 1) ? static_cast<$Executor*>($ForkJoinPool::commonPool()) : static_cast<$Executor*>($new($SubmissionPublisher$ThreadPerTaskExecutor)));
}

SubmissionPublisher::SubmissionPublisher() {
}

$Class* SubmissionPublisher::load$($String* name, bool initialize) {
	$loadClass(SubmissionPublisher, name, initialize, &_SubmissionPublisher_ClassInfo_, clinit$SubmissionPublisher, allocate$SubmissionPublisher);
	return class$;
}

$Class* SubmissionPublisher::class$ = nullptr;

		} // concurrent
	} // util
} // java