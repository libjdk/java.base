#include <java/util/concurrent/PriorityBlockingQueue.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Comparable.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/Math.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractQueue.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/PriorityQueue.h>
#include <java/util/SortedSet.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/Helpers.h>
#include <java/util/concurrent/PriorityBlockingQueue$Itr.h>
#include <java/util/concurrent/PriorityBlockingQueue$PBQSpliterator.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/Condition.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/util/ArraysSupport.h>
#include <jcpp.h>

#undef ALLOCATIONSPINLOCK
#undef DEFAULT_INITIAL_CAPACITY
#undef MAX_VALUE
#undef TYPE

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractQueue = ::java::util::AbstractQueue;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $PriorityQueue = ::java::util::PriorityQueue;
using $SortedSet = ::java::util::SortedSet;
using $Spliterator = ::java::util::Spliterator;
using $Helpers = ::java::util::concurrent::Helpers;
using $PriorityBlockingQueue$Itr = ::java::util::concurrent::PriorityBlockingQueue$Itr;
using $PriorityBlockingQueue$PBQSpliterator = ::java::util::concurrent::PriorityBlockingQueue$PBQSpliterator;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Condition = ::java::util::concurrent::locks::Condition;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ArraysSupport = ::jdk::internal::util::ArraysSupport;

namespace java {
	namespace util {
		namespace concurrent {

class PriorityBlockingQueue$$Lambda$lambda$removeAll$0 : public $Predicate {
	$class(PriorityBlockingQueue$$Lambda$lambda$removeAll$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return PriorityBlockingQueue::lambda$removeAll$0(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PriorityBlockingQueue$$Lambda$lambda$removeAll$0>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PriorityBlockingQueue$$Lambda$lambda$removeAll$0::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(PriorityBlockingQueue$$Lambda$lambda$removeAll$0, c)},
	{}
};
$MethodInfo PriorityBlockingQueue$$Lambda$lambda$removeAll$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(PriorityBlockingQueue$$Lambda$lambda$removeAll$0, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue$$Lambda$lambda$removeAll$0, test, bool, Object$*)},
	{}
};
$ClassInfo PriorityBlockingQueue$$Lambda$lambda$removeAll$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.PriorityBlockingQueue$$Lambda$lambda$removeAll$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* PriorityBlockingQueue$$Lambda$lambda$removeAll$0::load$($String* name, bool initialize) {
	$loadClass(PriorityBlockingQueue$$Lambda$lambda$removeAll$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PriorityBlockingQueue$$Lambda$lambda$removeAll$0::class$ = nullptr;

class PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1 : public $Predicate {
	$class(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return PriorityBlockingQueue::lambda$retainAll$1(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1, c)},
	{}
};
$MethodInfo PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::load$($String* name, bool initialize) {
	$loadClass(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::class$ = nullptr;

$FieldInfo _PriorityBlockingQueue_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PriorityBlockingQueue, serialVersionUID)},
	{"DEFAULT_INITIAL_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PriorityBlockingQueue, DEFAULT_INITIAL_CAPACITY)},
	{"queue", "[Ljava/lang/Object;", nullptr, $PRIVATE | $TRANSIENT, $field(PriorityBlockingQueue, queue)},
	{"size", "I", nullptr, $PRIVATE | $TRANSIENT, $field(PriorityBlockingQueue, size$)},
	{"comparator", "Ljava/util/Comparator;", "Ljava/util/Comparator<-TE;>;", $PRIVATE | $TRANSIENT, $field(PriorityBlockingQueue, comparator$)},
	{"lock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(PriorityBlockingQueue, lock)},
	{"notEmpty", "Ljava/util/concurrent/locks/Condition;", nullptr, $PRIVATE | $FINAL, $field(PriorityBlockingQueue, notEmpty)},
	{"allocationSpinLock", "I", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(PriorityBlockingQueue, allocationSpinLock)},
	{"q", "Ljava/util/PriorityQueue;", "Ljava/util/PriorityQueue<TE;>;", $PRIVATE, $field(PriorityBlockingQueue, q)},
	{"ALLOCATIONSPINLOCK", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PriorityBlockingQueue, ALLOCATIONSPINLOCK)},
	{}
};

$MethodInfo _PriorityBlockingQueue_MethodInfo_[] = {
	{"*addAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*element", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PUBLIC, $method(PriorityBlockingQueue, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(PriorityBlockingQueue, init$, void, int32_t)},
	{"<init>", "(ILjava/util/Comparator;)V", "(ILjava/util/Comparator<-TE;>;)V", $PUBLIC, $method(PriorityBlockingQueue, init$, void, int32_t, $Comparator*)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(PriorityBlockingQueue, init$, void, $Collection*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(PriorityBlockingQueue, add, bool, Object$*)},
	{"bulkRemove", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PRIVATE, $method(PriorityBlockingQueue, bulkRemove, bool, $Predicate*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, clear, void)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TE;>;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, comparator, $Comparator*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, contains, bool, Object$*)},
	{"dequeue", "()Ljava/lang/Object;", "()TE;", $PRIVATE, $method(PriorityBlockingQueue, dequeue, $Object*)},
	{"drainTo", "(Ljava/util/Collection;)I", "(Ljava/util/Collection<-TE;>;)I", $PUBLIC, $virtualMethod(PriorityBlockingQueue, drainTo, int32_t, $Collection*)},
	{"drainTo", "(Ljava/util/Collection;I)I", "(Ljava/util/Collection<-TE;>;I)I", $PUBLIC, $virtualMethod(PriorityBlockingQueue, drainTo, int32_t, $Collection*, int32_t)},
	{"ensureNonEmpty", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, ensureNonEmpty, $ObjectArray*, $ObjectArray*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(PriorityBlockingQueue, forEach, void, $Consumer*)},
	{"heapify", "()V", nullptr, $PRIVATE, $method(PriorityBlockingQueue, heapify, void)},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PRIVATE, $method(PriorityBlockingQueue, indexOf, int32_t, Object$*)},
	{"isClear", "([JI)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, isClear, bool, $longs*, int32_t)},
	{"*isEmpty", "()Z", nullptr, $PUBLIC},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, iterator, $Iterator*)},
	{"lambda$removeAll$0", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PriorityBlockingQueue, lambda$removeAll$0, bool, $Collection*, Object$*)},
	{"lambda$retainAll$1", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PriorityBlockingQueue, lambda$retainAll$1, bool, $Collection*, Object$*)},
	{"nBits", "(I)[J", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, nBits, $longs*, int32_t)},
	{"offer", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(PriorityBlockingQueue, offer, bool, Object$*)},
	{"offer", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;)Z", "(TE;JLjava/util/concurrent/TimeUnit;)Z", $PUBLIC, $virtualMethod(PriorityBlockingQueue, offer, bool, Object$*, int64_t, $TimeUnit*)},
	{"*parallelStream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"peek", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, peek, $Object*)},
	{"poll", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, poll, $Object*)},
	{"poll", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TE;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, poll, $Object*, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"put", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(PriorityBlockingQueue, put, void, Object$*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(PriorityBlockingQueue, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remainingCapacity", "()I", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, remainingCapacity, int32_t)},
	{"*remove", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(PriorityBlockingQueue, removeAll, bool, $Collection*)},
	{"removeAt", "(I)V", nullptr, $PRIVATE, $method(PriorityBlockingQueue, removeAt, void, int32_t)},
	{"removeEq", "(Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(PriorityBlockingQueue, removeEq, void, Object$*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(PriorityBlockingQueue, removeIf, bool, $Predicate*)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(PriorityBlockingQueue, retainAll, bool, $Collection*)},
	{"setBit", "([JI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, setBit, void, $longs*, int32_t)},
	{"siftDownComparable", "(ILjava/lang/Object;[Ljava/lang/Object;I)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;I)V", $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, siftDownComparable, void, int32_t, Object$*, $ObjectArray*, int32_t)},
	{"siftDownUsingComparator", "(ILjava/lang/Object;[Ljava/lang/Object;ILjava/util/Comparator;)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;ILjava/util/Comparator<-TT;>;)V", $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, siftDownUsingComparator, void, int32_t, Object$*, $ObjectArray*, int32_t, $Comparator*)},
	{"siftUpComparable", "(ILjava/lang/Object;[Ljava/lang/Object;)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;)V", $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, siftUpComparable, void, int32_t, Object$*, $ObjectArray*)},
	{"siftUpUsingComparator", "(ILjava/lang/Object;[Ljava/lang/Object;Ljava/util/Comparator;)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;Ljava/util/Comparator<-TT;>;)V", $PRIVATE | $STATIC, $staticMethod(PriorityBlockingQueue, siftUpUsingComparator, void, int32_t, Object$*, $ObjectArray*, $Comparator*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, spliterator, $Spliterator*)},
	{"*stream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"take", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, take, $Object*), "java.lang.InterruptedException"},
	{"*toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(PriorityBlockingQueue, toArray, $ObjectArray*, $ObjectArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PriorityBlockingQueue, toString, $String*)},
	{"tryGrow", "([Ljava/lang/Object;I)V", nullptr, $PRIVATE, $method(PriorityBlockingQueue, tryGrow, void, $ObjectArray*, int32_t)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(PriorityBlockingQueue, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _PriorityBlockingQueue_InnerClassesInfo_[] = {
	{"java.util.concurrent.PriorityBlockingQueue$PBQSpliterator", "java.util.concurrent.PriorityBlockingQueue", "PBQSpliterator", $FINAL},
	{"java.util.concurrent.PriorityBlockingQueue$Itr", "java.util.concurrent.PriorityBlockingQueue", "Itr", $FINAL},
	{}
};

$ClassInfo _PriorityBlockingQueue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.PriorityBlockingQueue",
	"java.util.AbstractQueue",
	"java.util.concurrent.BlockingQueue,java.io.Serializable",
	_PriorityBlockingQueue_FieldInfo_,
	_PriorityBlockingQueue_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractQueue<TE;>;Ljava/util/concurrent/BlockingQueue<TE;>;Ljava/io/Serializable;",
	nullptr,
	_PriorityBlockingQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.PriorityBlockingQueue$PBQSpliterator,java.util.concurrent.PriorityBlockingQueue$Itr"
};

$Object* allocate$PriorityBlockingQueue($Class* clazz) {
	return $of($alloc(PriorityBlockingQueue));
}

$Object* PriorityBlockingQueue::remove() {
	 return this->$AbstractQueue::remove();
}

$Object* PriorityBlockingQueue::element() {
	 return this->$AbstractQueue::element();
}

bool PriorityBlockingQueue::addAll($Collection* c) {
	 return this->$AbstractQueue::addAll(c);
}

bool PriorityBlockingQueue::isEmpty() {
	 return this->$AbstractQueue::isEmpty();
}

bool PriorityBlockingQueue::containsAll($Collection* c) {
	 return this->$AbstractQueue::containsAll(c);
}

$ObjectArray* PriorityBlockingQueue::toArray($IntFunction* generator) {
	 return this->$AbstractQueue::toArray(generator);
}

bool PriorityBlockingQueue::equals(Object$* o) {
	 return this->$AbstractQueue::equals(o);
}

int32_t PriorityBlockingQueue::hashCode() {
	 return this->$AbstractQueue::hashCode();
}

$Stream* PriorityBlockingQueue::stream() {
	 return this->$AbstractQueue::stream();
}

$Stream* PriorityBlockingQueue::parallelStream() {
	 return this->$AbstractQueue::parallelStream();
}

$Object* PriorityBlockingQueue::clone() {
	 return this->$AbstractQueue::clone();
}

void PriorityBlockingQueue::finalize() {
	this->$AbstractQueue::finalize();
}

$VarHandle* PriorityBlockingQueue::ALLOCATIONSPINLOCK = nullptr;

void PriorityBlockingQueue::init$() {
	PriorityBlockingQueue::init$(PriorityBlockingQueue::DEFAULT_INITIAL_CAPACITY, nullptr);
}

void PriorityBlockingQueue::init$(int32_t initialCapacity) {
	PriorityBlockingQueue::init$(initialCapacity, nullptr);
}

void PriorityBlockingQueue::init$(int32_t initialCapacity, $Comparator* comparator) {
	$AbstractQueue::init$();
	$set(this, lock, $new($ReentrantLock));
	$set(this, notEmpty, $nc(this->lock)->newCondition());
	if (initialCapacity < 1) {
		$throwNew($IllegalArgumentException);
	}
	$set(this, comparator$, comparator);
	$set(this, queue, $new($ObjectArray, $Math::max(1, initialCapacity)));
}

void PriorityBlockingQueue::init$($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$AbstractQueue::init$();
	$set(this, lock, $new($ReentrantLock));
	$set(this, notEmpty, $nc(this->lock)->newCondition());
	bool heapify = true;
	bool screen = true;
	if ($instanceOf($SortedSet, c)) {
		$var($SortedSet, ss, $cast($SortedSet, c));
		$set(this, comparator$, $nc(ss)->comparator());
		heapify = false;
	} else if ($instanceOf(PriorityBlockingQueue, c)) {
		$var(PriorityBlockingQueue, pq, $cast(PriorityBlockingQueue, c));
		$set(this, comparator$, $nc(pq)->comparator());
		screen = false;
		if ($of(pq)->getClass() == PriorityBlockingQueue::class$) {
			heapify = false;
		}
	}
	$var($ObjectArray, es, $nc(c)->toArray());
	int32_t n = $nc(es)->length;
	$load($ArrayList);
	if ($of(c)->getClass() != $ArrayList::class$) {
		$load($ObjectArray);
		$assign(es, $Arrays::copyOf(es, n, $getClass($ObjectArray)));
	}
	if (screen && (n == 1 || this->comparator$ != nullptr)) {
		{
			$var($ObjectArray, arr$, es);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, e, arr$->get(i$));
				if (e == nullptr) {
					$throwNew($NullPointerException);
				}
			}
		}
	}
	$set(this, queue, ensureNonEmpty(es));
	this->size$ = n;
	if (heapify) {
		this->heapify();
	}
}

$ObjectArray* PriorityBlockingQueue::ensureNonEmpty($ObjectArray* es) {
	$init(PriorityBlockingQueue);
	return ($nc(es)->length > 0) ? es : $new($ObjectArray, 1);
}

void PriorityBlockingQueue::tryGrow($ObjectArray* array, int32_t oldCap) {
	$useLocalCurrentObjectStackCache();
	$nc(this->lock)->unlock();
	$var($ObjectArray, newArray, nullptr);
	if (this->allocationSpinLock == 0 && $nc(PriorityBlockingQueue::ALLOCATIONSPINLOCK)->compareAndSet($$new($ObjectArray, {$of(this), $$of(0), $$of(1)}))) {
		{
			$var($Throwable, var$0, nullptr);
			try {
				int32_t growth = (oldCap < 64) ? (oldCap + 2) : (oldCap >> 1);
				int32_t newCap = $ArraysSupport::newLength(oldCap, 1, growth);
				if (this->queue == array) {
					$assign(newArray, $new($ObjectArray, newCap));
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				this->allocationSpinLock = 0;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	if (newArray == nullptr) {
		$Thread::yield();
	}
	$nc(this->lock)->lock();
	if (newArray != nullptr && this->queue == array) {
		$set(this, queue, newArray);
		$System::arraycopy(array, 0, newArray, 0, oldCap);
	}
}

$Object* PriorityBlockingQueue::dequeue() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, nullptr);
	$var($Object, result, nullptr);
	if (($assign(result, ($nc(($assign(es, this->queue)))->get(0)))) != nullptr) {
		int32_t n = 0;
		$var($Object, x, $nc(es)->get(n = --this->size$));
		es->set(n, nullptr);
		if (n > 0) {
			$var($Comparator, cmp, nullptr);
			if (($assign(cmp, this->comparator$)) == nullptr) {
				siftDownComparable(0, x, es, n);
			} else {
				siftDownUsingComparator(0, x, es, n, cmp);
			}
		}
	}
	return $of(result);
}

void PriorityBlockingQueue::siftUpComparable(int32_t k, Object$* x, $ObjectArray* es) {
	$init(PriorityBlockingQueue);
	$useLocalCurrentObjectStackCache();
	$var($Comparable, key, $cast($Comparable, x));
	while (k > 0) {
		int32_t parent = (int32_t)((uint32_t)(k - 1) >> 1);
		$var($Object0, e, $nc(es)->get(parent));
		if ($nc(key)->compareTo(e) >= 0) {
			break;
		}
		es->set(k, e);
		k = parent;
	}
	$nc(es)->set(k, key);
}

void PriorityBlockingQueue::siftUpUsingComparator(int32_t k, Object$* x, $ObjectArray* es, $Comparator* cmp) {
	$init(PriorityBlockingQueue);
	$useLocalCurrentObjectStackCache();
	while (k > 0) {
		int32_t parent = (int32_t)((uint32_t)(k - 1) >> 1);
		$var($Object0, e, $nc(es)->get(parent));
		if ($nc(cmp)->compare(x, e) >= 0) {
			break;
		}
		es->set(k, e);
		k = parent;
	}
	$nc(es)->set(k, x);
}

void PriorityBlockingQueue::siftDownComparable(int32_t k, Object$* x, $ObjectArray* es, int32_t n) {
	$init(PriorityBlockingQueue);
	$useLocalCurrentObjectStackCache();
	$var($Comparable, key, $cast($Comparable, x));
	int32_t half = (int32_t)((uint32_t)n >> 1);
	while (k < half) {
		int32_t child = (k << 1) + 1;
		$var($Object, c, $nc(es)->get(child));
		int32_t right = child + 1;
		if (right < n && $nc(($cast($Comparable, c)))->compareTo(es->get(right)) > 0) {
			$assign(c, es->get(child = right));
		}
		if ($nc(key)->compareTo(c) <= 0) {
			break;
		}
		es->set(k, c);
		k = child;
	}
	$nc(es)->set(k, key);
}

void PriorityBlockingQueue::siftDownUsingComparator(int32_t k, Object$* x, $ObjectArray* es, int32_t n, $Comparator* cmp) {
	$init(PriorityBlockingQueue);
	$useLocalCurrentObjectStackCache();
	int32_t half = (int32_t)((uint32_t)n >> 1);
	while (k < half) {
		int32_t child = (k << 1) + 1;
		$var($Object, c, $nc(es)->get(child));
		int32_t right = child + 1;
		if (right < n && $nc(cmp)->compare(c, es->get(right)) > 0) {
			$assign(c, es->get(child = right));
		}
		if ($nc(cmp)->compare(x, c) <= 0) {
			break;
		}
		es->set(k, c);
		k = child;
	}
	$nc(es)->set(k, x);
}

void PriorityBlockingQueue::heapify() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, this->queue);
	int32_t n = this->size$;
	int32_t i = ((int32_t)((uint32_t)n >> 1)) - 1;
	$var($Comparator, cmp, nullptr);
	if (($assign(cmp, this->comparator$)) == nullptr) {
		for (; i >= 0; --i) {
			siftDownComparable(i, $nc(es)->get(i), es, n);
		}
	} else {
		for (; i >= 0; --i) {
			siftDownUsingComparator(i, $nc(es)->get(i), es, n, cmp);
		}
	}
}

bool PriorityBlockingQueue::add(Object$* e) {
	return offer(e);
}

bool PriorityBlockingQueue::offer(Object$* e) {
	$useLocalCurrentObjectStackCache();
	if (e == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	int32_t n = 0;
	int32_t cap = 0;
	$var($ObjectArray, es, nullptr);
	while ((n = this->size$) >= (cap = $nc(($assign(es, this->queue)))->length)) {
		tryGrow(es, cap);
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Comparator, cmp, nullptr);
			if (($assign(cmp, this->comparator$)) == nullptr) {
				siftUpComparable(n, e, es);
			} else {
				siftUpUsingComparator(n, e, es, cmp);
			}
			this->size$ = n + 1;
			$nc(this->notEmpty)->signal();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			lock->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return true;
}

void PriorityBlockingQueue::put(Object$* e) {
	offer(e);
}

bool PriorityBlockingQueue::offer(Object$* e, int64_t timeout, $TimeUnit* unit) {
	return offer(e);
}

$Object* PriorityBlockingQueue::poll() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, dequeue());
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

$Object* PriorityBlockingQueue::take() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lockInterruptibly();
	$var($Object, result, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			while (($assign(result, dequeue())) == nullptr) {
				$nc(this->notEmpty)->await();
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
	return $of(result);
}

$Object* PriorityBlockingQueue::poll(int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	int64_t nanos = $nc(unit)->toNanos(timeout);
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lockInterruptibly();
	$var($Object, result, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			while (($assign(result, dequeue())) == nullptr && nanos > 0) {
				nanos = $nc(this->notEmpty)->awaitNanos(nanos);
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
	return $of(result);
}

$Object* PriorityBlockingQueue::peek() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->queue)->get(0));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

$Comparator* PriorityBlockingQueue::comparator() {
	return this->comparator$;
}

int32_t PriorityBlockingQueue::size() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			var$2 = this->size$;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

int32_t PriorityBlockingQueue::remainingCapacity() {
	return $Integer::MAX_VALUE;
}

int32_t PriorityBlockingQueue::indexOf(Object$* o) {
	if (o != nullptr) {
		$var($ObjectArray, es, this->queue);
		{
			int32_t i = 0;
			int32_t n = this->size$;
			for (; i < n; ++i) {
				if ($of(o)->equals($nc(es)->get(i))) {
					return i;
				}
			}
		}
	}
	return -1;
}

void PriorityBlockingQueue::removeAt(int32_t i) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, this->queue);
	int32_t n = this->size$ - 1;
	if (n == i) {
		$nc(es)->set(i, nullptr);
	} else {
		$var($Object, moved, $nc(es)->get(n));
		es->set(n, nullptr);
		$var($Comparator, cmp, nullptr);
		if (($assign(cmp, this->comparator$)) == nullptr) {
			siftDownComparable(i, moved, es, n);
		} else {
			siftDownUsingComparator(i, moved, es, n, cmp);
		}
		if ($equals(es->get(i), moved)) {
			if (cmp == nullptr) {
				siftUpComparable(i, moved, es);
			} else {
				siftUpUsingComparator(i, moved, es, cmp);
			}
		}
	}
	this->size$ = n;
}

bool PriorityBlockingQueue::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			int32_t i = indexOf(o);
			if (i == -1) {
				var$2 = false;
				return$1 = true;
				goto $finally;
			}
			removeAt(i);
			var$2 = true;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

void PriorityBlockingQueue::removeEq(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($ObjectArray, es, this->queue);
			{
				int32_t i = 0;
				int32_t n = this->size$;
				for (; i < n; ++i) {
					if ($equals(o, $nc(es)->get(i))) {
						removeAt(i);
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
}

bool PriorityBlockingQueue::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			var$2 = indexOf(o) != -1;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

$String* PriorityBlockingQueue::toString() {
	return $Helpers::collectionToString(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractQueue*>(this))));
}

int32_t PriorityBlockingQueue::drainTo($Collection* c) {
	return drainTo(c, $Integer::MAX_VALUE);
}

int32_t PriorityBlockingQueue::drainTo($Collection* c, int32_t maxElements) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(c);
	if ($equals(c, this)) {
		$throwNew($IllegalArgumentException);
	}
	if (maxElements <= 0) {
		return 0;
	}
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			int32_t n = $Math::min(this->size$, maxElements);
			for (int32_t i = 0; i < n; ++i) {
				c->add($nc(this->queue)->get(0));
				dequeue();
			}
			var$2 = n;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

void PriorityBlockingQueue::clear() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($ObjectArray, es, this->queue);
			{
				int32_t i = 0;
				int32_t n = this->size$;
				for (; i < n; ++i) {
					$nc(es)->set(i, nullptr);
				}
			}
			this->size$ = 0;
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

$ObjectArray* PriorityBlockingQueue::toArray() {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($ObjectArray, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $Arrays::copyOf(this->queue, this->size$));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

$ObjectArray* PriorityBlockingQueue::toArray($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($ObjectArray, var$2, nullptr);
		bool return$1 = false;
		try {
			int32_t n = this->size$;
			if ($nc(a)->length < n) {
				$assign(var$2, $Arrays::copyOf(this->queue, this->size$, $of(a)->getClass()));
				return$1 = true;
				goto $finally;
			}
			$System::arraycopy(this->queue, 0, a, 0, n);
			if ($nc(a)->length > n) {
				a->set(n, nullptr);
			}
			$assign(var$2, a);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

$Iterator* PriorityBlockingQueue::iterator() {
	return $new($PriorityBlockingQueue$Itr, this, $(toArray()));
}

void PriorityBlockingQueue::writeObject($ObjectOutputStream* s) {
	$nc(this->lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set(this, q, $new($PriorityQueue, $Math::max(this->size$, 1), this->comparator$));
			$nc(this->q)->addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractQueue*>(this))));
			$nc(s)->defaultWriteObject();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, q, nullptr);
			$nc(this->lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void PriorityBlockingQueue::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(s)->defaultReadObject();
			int32_t sz = $nc(this->q)->size();
			$load($ObjectArray);
			$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($ObjectArray), sz);
			$set(this, queue, $new($ObjectArray, $Math::max(1, sz)));
			$set(this, comparator$, $nc(this->q)->comparator());
			addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractQueue*>(this->q))));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, q, nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Spliterator* PriorityBlockingQueue::spliterator() {
	return $new($PriorityBlockingQueue$PBQSpliterator, this);
}

bool PriorityBlockingQueue::removeIf($Predicate* filter) {
	$Objects::requireNonNull(filter);
	return bulkRemove(filter);
}

bool PriorityBlockingQueue::removeAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(PriorityBlockingQueue$$Lambda$lambda$removeAll$0, c)));
}

bool PriorityBlockingQueue::retainAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1, c)));
}

$longs* PriorityBlockingQueue::nBits(int32_t n) {
	$init(PriorityBlockingQueue);
	return $new($longs, ((n - 1) >> 6) + 1);
}

void PriorityBlockingQueue::setBit($longs* bits, int32_t i) {
	$init(PriorityBlockingQueue);
	(*$nc(bits))[i >> 6] |= $sl((int64_t)1, i);
}

bool PriorityBlockingQueue::isClear($longs* bits, int32_t i) {
	$init(PriorityBlockingQueue);
	return ((int64_t)($nc(bits)->get(i >> 6) & (uint64_t)($sl((int64_t)1, i)))) == 0;
}

bool PriorityBlockingQueue::bulkRemove($Predicate* filter) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			$var($ObjectArray, es, this->queue);
			int32_t end = this->size$;
			int32_t i = 0;
			for (i = 0; i < end && !$nc(filter)->test($nc(es)->get(i)); ++i) {
			}
			if (i >= end) {
				var$2 = false;
				return$1 = true;
				goto $finally;
			}
			int32_t beg = i;
			$var($longs, deathRow, nBits(end - beg));
			$nc(deathRow)->set(0, 1);
			for (i = beg + 1; i < end; ++i) {
				if ($nc(filter)->test($nc(es)->get(i))) {
					setBit(deathRow, i - beg);
				}
			}
			int32_t w = beg;
			for (i = beg; i < end; ++i) {
				if (isClear(deathRow, i - beg)) {
					$nc(es)->set(w++, es->get(i));
				}
			}
			for (i = (this->size$ = w); i < end; ++i) {
				$nc(es)->set(i, nullptr);
			}
			heapify();
			var$2 = true;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			lock->unlock();
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

void PriorityBlockingQueue::forEach($Consumer* action) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(action);
	$var($ReentrantLock, lock, this->lock);
	$nc(lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($ObjectArray, es, this->queue);
			{
				int32_t i = 0;
				int32_t n = this->size$;
				for (; i < n; ++i) {
					action->accept($nc(es)->get(i));
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

bool PriorityBlockingQueue::lambda$retainAll$1($Collection* c, Object$* e) {
	$init(PriorityBlockingQueue);
	return !$nc(c)->contains(e);
}

bool PriorityBlockingQueue::lambda$removeAll$0($Collection* c, Object$* e) {
	$init(PriorityBlockingQueue);
	return $nc(c)->contains(e);
}

void clinit$PriorityBlockingQueue($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(PriorityBlockingQueue::ALLOCATIONSPINLOCK, $nc(l)->findVarHandle(PriorityBlockingQueue::class$, "allocationSpinLock"_s, $Integer::TYPE));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

PriorityBlockingQueue::PriorityBlockingQueue() {
}

$Class* PriorityBlockingQueue::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PriorityBlockingQueue$$Lambda$lambda$removeAll$0::classInfo$.name)) {
			return PriorityBlockingQueue$$Lambda$lambda$removeAll$0::load$(name, initialize);
		}
		if (name->equals(PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::classInfo$.name)) {
			return PriorityBlockingQueue$$Lambda$lambda$retainAll$1$1::load$(name, initialize);
		}
	}
	$loadClass(PriorityBlockingQueue, name, initialize, &_PriorityBlockingQueue_ClassInfo_, clinit$PriorityBlockingQueue, allocate$PriorityBlockingQueue);
	return class$;
}

$Class* PriorityBlockingQueue::class$ = nullptr;

		} // concurrent
	} // util
} // java