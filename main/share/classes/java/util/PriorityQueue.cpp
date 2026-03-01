#include <java/util/PriorityQueue.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Comparable.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractQueue.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/PriorityQueue$Itr.h>
#include <java/util/PriorityQueue$PriorityQueueSpliterator.h>
#include <java/util/SortedSet.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/util/ArraysSupport.h>
#include <jcpp.h>

#undef DEFAULT_INITIAL_CAPACITY

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractQueue = ::java::util::AbstractQueue;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $PriorityQueue$Itr = ::java::util::PriorityQueue$Itr;
using $PriorityQueue$PriorityQueueSpliterator = ::java::util::PriorityQueue$PriorityQueueSpliterator;
using $SortedSet = ::java::util::SortedSet;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ArraysSupport = ::jdk::internal::util::ArraysSupport;

namespace java {
	namespace util {

class PriorityQueue$$Lambda$lambda$removeAll$0 : public $Predicate {
	$class(PriorityQueue$$Lambda$lambda$removeAll$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return PriorityQueue::lambda$removeAll$0(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PriorityQueue$$Lambda$lambda$removeAll$0>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PriorityQueue$$Lambda$lambda$removeAll$0::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(PriorityQueue$$Lambda$lambda$removeAll$0, c)},
	{}
};
$MethodInfo PriorityQueue$$Lambda$lambda$removeAll$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(PriorityQueue$$Lambda$lambda$removeAll$0, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityQueue$$Lambda$lambda$removeAll$0, test, bool, Object$*)},
	{}
};
$ClassInfo PriorityQueue$$Lambda$lambda$removeAll$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.PriorityQueue$$Lambda$lambda$removeAll$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* PriorityQueue$$Lambda$lambda$removeAll$0::load$($String* name, bool initialize) {
	$loadClass(PriorityQueue$$Lambda$lambda$removeAll$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PriorityQueue$$Lambda$lambda$removeAll$0::class$ = nullptr;

class PriorityQueue$$Lambda$lambda$retainAll$1$1 : public $Predicate {
	$class(PriorityQueue$$Lambda$lambda$retainAll$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return PriorityQueue::lambda$retainAll$1(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PriorityQueue$$Lambda$lambda$retainAll$1$1>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PriorityQueue$$Lambda$lambda$retainAll$1$1::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(PriorityQueue$$Lambda$lambda$retainAll$1$1, c)},
	{}
};
$MethodInfo PriorityQueue$$Lambda$lambda$retainAll$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(PriorityQueue$$Lambda$lambda$retainAll$1$1, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityQueue$$Lambda$lambda$retainAll$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo PriorityQueue$$Lambda$lambda$retainAll$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.PriorityQueue$$Lambda$lambda$retainAll$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* PriorityQueue$$Lambda$lambda$retainAll$1$1::load$($String* name, bool initialize) {
	$loadClass(PriorityQueue$$Lambda$lambda$retainAll$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PriorityQueue$$Lambda$lambda$retainAll$1$1::class$ = nullptr;

$FieldInfo _PriorityQueue_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PriorityQueue, serialVersionUID)},
	{"DEFAULT_INITIAL_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PriorityQueue, DEFAULT_INITIAL_CAPACITY)},
	{"queue", "[Ljava/lang/Object;", nullptr, $TRANSIENT, $field(PriorityQueue, queue)},
	{"size", "I", nullptr, 0, $field(PriorityQueue, size$)},
	{"comparator", "Ljava/util/Comparator;", "Ljava/util/Comparator<-TE;>;", $PRIVATE | $FINAL, $field(PriorityQueue, comparator$)},
	{"modCount", "I", nullptr, $TRANSIENT, $field(PriorityQueue, modCount)},
	{}
};

$MethodInfo _PriorityQueue_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PUBLIC, $method(PriorityQueue, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(PriorityQueue, init$, void, int32_t)},
	{"<init>", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC, $method(PriorityQueue, init$, void, $Comparator*)},
	{"<init>", "(ILjava/util/Comparator;)V", "(ILjava/util/Comparator<-TE;>;)V", $PUBLIC, $method(PriorityQueue, init$, void, int32_t, $Comparator*)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(PriorityQueue, init$, void, $Collection*)},
	{"<init>", "(Ljava/util/PriorityQueue;)V", "(Ljava/util/PriorityQueue<+TE;>;)V", $PUBLIC, $method(PriorityQueue, init$, void, PriorityQueue*)},
	{"<init>", "(Ljava/util/SortedSet;)V", "(Ljava/util/SortedSet<+TE;>;)V", $PUBLIC, $method(PriorityQueue, init$, void, $SortedSet*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(PriorityQueue, add, bool, Object$*)},
	{"bulkRemove", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PRIVATE, $method(PriorityQueue, bulkRemove, bool, $Predicate*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(PriorityQueue, clear, void)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TE;>;", $PUBLIC, $virtualMethod(PriorityQueue, comparator, $Comparator*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityQueue, contains, bool, Object$*)},
	{"ensureNonEmpty", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityQueue, ensureNonEmpty, $ObjectArray*, $ObjectArray*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(PriorityQueue, forEach, void, $Consumer*)},
	{"grow", "(I)V", nullptr, $PRIVATE, $method(PriorityQueue, grow, void, int32_t)},
	{"heapify", "()V", nullptr, $PRIVATE, $method(PriorityQueue, heapify, void)},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PRIVATE, $method(PriorityQueue, indexOf, int32_t, Object$*)},
	{"initElementsFromCollection", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PRIVATE, $method(PriorityQueue, initElementsFromCollection, void, $Collection*)},
	{"initFromCollection", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PRIVATE, $method(PriorityQueue, initFromCollection, void, $Collection*)},
	{"initFromPriorityQueue", "(Ljava/util/PriorityQueue;)V", "(Ljava/util/PriorityQueue<+TE;>;)V", $PRIVATE, $method(PriorityQueue, initFromPriorityQueue, void, PriorityQueue*)},
	{"isClear", "([JI)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityQueue, isClear, bool, $longs*, int32_t)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(PriorityQueue, iterator, $Iterator*)},
	{"lambda$removeAll$0", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PriorityQueue, lambda$removeAll$0, bool, $Collection*, Object$*)},
	{"lambda$retainAll$1", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PriorityQueue, lambda$retainAll$1, bool, $Collection*, Object$*)},
	{"nBits", "(I)[J", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityQueue, nBits, $longs*, int32_t)},
	{"offer", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(PriorityQueue, offer, bool, Object$*)},
	{"peek", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(PriorityQueue, peek, $Object*)},
	{"poll", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(PriorityQueue, poll, $Object*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(PriorityQueue, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PriorityQueue, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(PriorityQueue, removeAll, bool, $Collection*)},
	{"removeAt", "(I)Ljava/lang/Object;", "(I)TE;", 0, $virtualMethod(PriorityQueue, removeAt, $Object*, int32_t)},
	{"removeEq", "(Ljava/lang/Object;)V", nullptr, 0, $virtualMethod(PriorityQueue, removeEq, void, Object$*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(PriorityQueue, removeIf, bool, $Predicate*)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(PriorityQueue, retainAll, bool, $Collection*)},
	{"setBit", "([JI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PriorityQueue, setBit, void, $longs*, int32_t)},
	{"siftDown", "(ILjava/lang/Object;)V", "(ITE;)V", $PRIVATE, $method(PriorityQueue, siftDown, void, int32_t, Object$*)},
	{"siftDownComparable", "(ILjava/lang/Object;[Ljava/lang/Object;I)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;I)V", $PRIVATE | $STATIC, $staticMethod(PriorityQueue, siftDownComparable, void, int32_t, Object$*, $ObjectArray*, int32_t)},
	{"siftDownUsingComparator", "(ILjava/lang/Object;[Ljava/lang/Object;ILjava/util/Comparator;)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;ILjava/util/Comparator<-TT;>;)V", $PRIVATE | $STATIC, $staticMethod(PriorityQueue, siftDownUsingComparator, void, int32_t, Object$*, $ObjectArray*, int32_t, $Comparator*)},
	{"siftUp", "(ILjava/lang/Object;)V", "(ITE;)V", $PRIVATE, $method(PriorityQueue, siftUp, void, int32_t, Object$*)},
	{"siftUpComparable", "(ILjava/lang/Object;[Ljava/lang/Object;)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;)V", $PRIVATE | $STATIC, $staticMethod(PriorityQueue, siftUpComparable, void, int32_t, Object$*, $ObjectArray*)},
	{"siftUpUsingComparator", "(ILjava/lang/Object;[Ljava/lang/Object;Ljava/util/Comparator;)V", "<T:Ljava/lang/Object;>(ITT;[Ljava/lang/Object;Ljava/util/Comparator<-TT;>;)V", $PRIVATE | $STATIC, $staticMethod(PriorityQueue, siftUpUsingComparator, void, int32_t, Object$*, $ObjectArray*, $Comparator*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(PriorityQueue, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC | $FINAL, $virtualMethod(PriorityQueue, spliterator, $Spliterator*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PriorityQueue, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(PriorityQueue, toArray, $ObjectArray*, $ObjectArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(PriorityQueue, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _PriorityQueue_InnerClassesInfo_[] = {
	{"java.util.PriorityQueue$PriorityQueueSpliterator", "java.util.PriorityQueue", "PriorityQueueSpliterator", $FINAL},
	{"java.util.PriorityQueue$Itr", "java.util.PriorityQueue", "Itr", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _PriorityQueue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.PriorityQueue",
	"java.util.AbstractQueue",
	"java.io.Serializable",
	_PriorityQueue_FieldInfo_,
	_PriorityQueue_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractQueue<TE;>;Ljava/io/Serializable;",
	nullptr,
	_PriorityQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.PriorityQueue$PriorityQueueSpliterator,java.util.PriorityQueue$Itr"
};

$Object* allocate$PriorityQueue($Class* clazz) {
	return $of($alloc(PriorityQueue));
}

$String* PriorityQueue::toString() {
	 return this->$AbstractQueue::toString();
}

bool PriorityQueue::equals(Object$* o) {
	 return this->$AbstractQueue::equals(o);
}

int32_t PriorityQueue::hashCode() {
	 return this->$AbstractQueue::hashCode();
}

$Object* PriorityQueue::clone() {
	 return this->$AbstractQueue::clone();
}

void PriorityQueue::finalize() {
	this->$AbstractQueue::finalize();
}

void PriorityQueue::init$() {
	PriorityQueue::init$(PriorityQueue::DEFAULT_INITIAL_CAPACITY, nullptr);
}

void PriorityQueue::init$(int32_t initialCapacity) {
	PriorityQueue::init$(initialCapacity, nullptr);
}

void PriorityQueue::init$($Comparator* comparator) {
	PriorityQueue::init$(PriorityQueue::DEFAULT_INITIAL_CAPACITY, comparator);
}

void PriorityQueue::init$(int32_t initialCapacity, $Comparator* comparator) {
	$AbstractQueue::init$();
	if (initialCapacity < 1) {
		$throwNew($IllegalArgumentException);
	}
	$set(this, queue, $new($ObjectArray, initialCapacity));
	$set(this, comparator$, comparator);
}

void PriorityQueue::init$($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$AbstractQueue::init$();
	if ($instanceOf($SortedSet, c)) {
		$var($SortedSet, ss, $cast($SortedSet, c));
		$set(this, comparator$, $nc(ss)->comparator());
		initElementsFromCollection(ss);
	} else if ($instanceOf(PriorityQueue, c)) {
		$var(PriorityQueue, pq, $cast(PriorityQueue, c));
		$set(this, comparator$, $nc(pq)->comparator());
		initFromPriorityQueue(pq);
	} else {
		$set(this, comparator$, nullptr);
		initFromCollection(c);
	}
}

void PriorityQueue::init$(PriorityQueue* c) {
	$AbstractQueue::init$();
	$set(this, comparator$, $nc(c)->comparator());
	initFromPriorityQueue(c);
}

void PriorityQueue::init$($SortedSet* c) {
	$AbstractQueue::init$();
	$set(this, comparator$, $nc(c)->comparator());
	initElementsFromCollection(c);
}

$ObjectArray* PriorityQueue::ensureNonEmpty($ObjectArray* es) {
	$init(PriorityQueue);
	return ($nc(es)->length > 0) ? es : $new($ObjectArray, 1);
}

void PriorityQueue::initFromPriorityQueue(PriorityQueue* c) {
	if ($nc($of(c))->getClass() == PriorityQueue::class$) {
		$set(this, queue, ensureNonEmpty($(c->toArray())));
		this->size$ = c->size();
	} else {
		initFromCollection(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractQueue*>(c))));
	}
}

void PriorityQueue::initElementsFromCollection($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, $nc(c)->toArray());
	int32_t len = $nc(es)->length;
	$load($ArrayList);
	if ($of(c)->getClass() != $ArrayList::class$) {
		$load($ObjectArray);
		$assign(es, $Arrays::copyOf(es, len, $getClass($ObjectArray)));
	}
	if (len == 1 || this->comparator$ != nullptr) {
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
	this->size$ = len;
}

void PriorityQueue::initFromCollection($Collection* c) {
	initElementsFromCollection(c);
	heapify();
}

void PriorityQueue::grow(int32_t minCapacity) {
	int32_t oldCapacity = $nc(this->queue)->length;
	int32_t newCapacity = $ArraysSupport::newLength(oldCapacity, minCapacity - oldCapacity, oldCapacity < 64 ? oldCapacity + 2 : oldCapacity >> 1);
	$set(this, queue, $Arrays::copyOf(this->queue, newCapacity));
}

bool PriorityQueue::add(Object$* e) {
	return offer(e);
}

bool PriorityQueue::offer(Object$* e) {
	if (e == nullptr) {
		$throwNew($NullPointerException);
	}
	++this->modCount;
	int32_t i = this->size$;
	if (i >= $nc(this->queue)->length) {
		grow(i + 1);
	}
	siftUp(i, e);
	this->size$ = i + 1;
	return true;
}

$Object* PriorityQueue::peek() {
	return $of($nc(this->queue)->get(0));
}

int32_t PriorityQueue::indexOf(Object$* o) {
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

bool PriorityQueue::remove(Object$* o) {
	int32_t i = indexOf(o);
	if (i == -1) {
		return false;
	} else {
		removeAt(i);
		return true;
	}
}

void PriorityQueue::removeEq(Object$* o) {
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
}

bool PriorityQueue::contains(Object$* o) {
	return indexOf(o) >= 0;
}

$ObjectArray* PriorityQueue::toArray() {
	return $Arrays::copyOf(this->queue, this->size$);
}

$ObjectArray* PriorityQueue::toArray($ObjectArray* a) {
	int32_t size = this->size$;
	if ($nc(a)->length < size) {
		return $Arrays::copyOf(this->queue, size, $of(a)->getClass());
	}
	$System::arraycopy(this->queue, 0, a, 0, size);
	if ($nc(a)->length > size) {
		a->set(size, nullptr);
	}
	return a;
}

$Iterator* PriorityQueue::iterator() {
	return $new($PriorityQueue$Itr, this);
}

int32_t PriorityQueue::size() {
	return this->size$;
}

void PriorityQueue::clear() {
	++this->modCount;
	$var($ObjectArray, es, this->queue);
	{
		int32_t i = 0;
		int32_t n = this->size$;
		for (; i < n; ++i) {
			$nc(es)->set(i, nullptr);
		}
	}
	this->size$ = 0;
}

$Object* PriorityQueue::poll() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, nullptr);
	$var($Object, result, nullptr);
	if (($assign(result, ($nc(($assign(es, this->queue)))->get(0)))) != nullptr) {
		++this->modCount;
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

$Object* PriorityQueue::removeAt(int32_t i) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, this->queue);
	++this->modCount;
	int32_t s = --this->size$;
	if (s == i) {
		$nc(es)->set(i, nullptr);
	} else {
		$var($Object, moved, $nc(es)->get(s));
		es->set(s, nullptr);
		siftDown(i, moved);
		if ($equals(es->get(i), moved)) {
			siftUp(i, moved);
			if (!$equals(es->get(i), moved)) {
				return $of(moved);
			}
		}
	}
	return $of(nullptr);
}

void PriorityQueue::siftUp(int32_t k, Object$* x) {
	if (this->comparator$ != nullptr) {
		siftUpUsingComparator(k, x, this->queue, this->comparator$);
	} else {
		siftUpComparable(k, x, this->queue);
	}
}

void PriorityQueue::siftUpComparable(int32_t k, Object$* x, $ObjectArray* es) {
	$init(PriorityQueue);
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

void PriorityQueue::siftUpUsingComparator(int32_t k, Object$* x, $ObjectArray* es, $Comparator* cmp) {
	$init(PriorityQueue);
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

void PriorityQueue::siftDown(int32_t k, Object$* x) {
	if (this->comparator$ != nullptr) {
		siftDownUsingComparator(k, x, this->queue, this->size$, this->comparator$);
	} else {
		siftDownComparable(k, x, this->queue, this->size$);
	}
}

void PriorityQueue::siftDownComparable(int32_t k, Object$* x, $ObjectArray* es, int32_t n) {
	$init(PriorityQueue);
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

void PriorityQueue::siftDownUsingComparator(int32_t k, Object$* x, $ObjectArray* es, int32_t n, $Comparator* cmp) {
	$init(PriorityQueue);
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

void PriorityQueue::heapify() {
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

$Comparator* PriorityQueue::comparator() {
	return this->comparator$;
}

void PriorityQueue::writeObject($ObjectOutputStream* s) {
	$nc(s)->defaultWriteObject();
	s->writeInt($Math::max(2, this->size$ + 1));
	$var($ObjectArray, es, this->queue);
	{
		int32_t i = 0;
		int32_t n = this->size$;
		for (; i < n; ++i) {
			s->writeObject($nc(es)->get(i));
		}
	}
}

void PriorityQueue::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	s->readInt();
	$load($ObjectArray);
	$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($ObjectArray), this->size$);
	$var($ObjectArray, es, $set(this, queue, $new($ObjectArray, $Math::max(this->size$, 1))));
	{
		int32_t i = 0;
		int32_t n = this->size$;
		for (; i < n; ++i) {
			$nc(es)->set(i, $(s->readObject()));
		}
	}
	heapify();
}

$Spliterator* PriorityQueue::spliterator() {
	return $new($PriorityQueue$PriorityQueueSpliterator, this, 0, -1, 0);
}

bool PriorityQueue::removeIf($Predicate* filter) {
	$Objects::requireNonNull(filter);
	return bulkRemove(filter);
}

bool PriorityQueue::removeAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(PriorityQueue$$Lambda$lambda$removeAll$0, c)));
}

bool PriorityQueue::retainAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(PriorityQueue$$Lambda$lambda$retainAll$1$1, c)));
}

$longs* PriorityQueue::nBits(int32_t n) {
	$init(PriorityQueue);
	return $new($longs, ((n - 1) >> 6) + 1);
}

void PriorityQueue::setBit($longs* bits, int32_t i) {
	$init(PriorityQueue);
	(*$nc(bits))[i >> 6] |= $sl((int64_t)1, i);
}

bool PriorityQueue::isClear($longs* bits, int32_t i) {
	$init(PriorityQueue);
	return ((int64_t)($nc(bits)->get(i >> 6) & (uint64_t)($sl((int64_t)1, i)))) == 0;
}

bool PriorityQueue::bulkRemove($Predicate* filter) {
	$useLocalCurrentObjectStackCache();
	int32_t expectedModCount = ++this->modCount;
	$var($ObjectArray, es, this->queue);
	int32_t end = this->size$;
	int32_t i = 0;
	for (i = 0; i < end && !$nc(filter)->test($nc(es)->get(i)); ++i) {
	}
	if (i >= end) {
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
		return false;
	}
	int32_t beg = i;
	$var($longs, deathRow, nBits(end - beg));
	$nc(deathRow)->set(0, 1);
	for (i = beg + 1; i < end; ++i) {
		if ($nc(filter)->test($nc(es)->get(i))) {
			setBit(deathRow, i - beg);
		}
	}
	if (this->modCount != expectedModCount) {
		$throwNew($ConcurrentModificationException);
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
	return true;
}

void PriorityQueue::forEach($Consumer* action) {
	$Objects::requireNonNull(action);
	int32_t expectedModCount = this->modCount;
	$var($ObjectArray, es, this->queue);
	{
		int32_t i = 0;
		int32_t n = this->size$;
		for (; i < n; ++i) {
			action->accept($nc(es)->get(i));
		}
	}
	if (expectedModCount != this->modCount) {
		$throwNew($ConcurrentModificationException);
	}
}

bool PriorityQueue::lambda$retainAll$1($Collection* c, Object$* e) {
	$init(PriorityQueue);
	return !$nc(c)->contains(e);
}

bool PriorityQueue::lambda$removeAll$0($Collection* c, Object$* e) {
	$init(PriorityQueue);
	return $nc(c)->contains(e);
}

PriorityQueue::PriorityQueue() {
}

$Class* PriorityQueue::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PriorityQueue$$Lambda$lambda$removeAll$0::classInfo$.name)) {
			return PriorityQueue$$Lambda$lambda$removeAll$0::load$(name, initialize);
		}
		if (name->equals(PriorityQueue$$Lambda$lambda$retainAll$1$1::classInfo$.name)) {
			return PriorityQueue$$Lambda$lambda$retainAll$1$1::load$(name, initialize);
		}
	}
	$loadClass(PriorityQueue, name, initialize, &_PriorityQueue_ClassInfo_, allocate$PriorityQueue);
	return class$;
}

$Class* PriorityQueue::class$ = nullptr;

	} // util
} // java