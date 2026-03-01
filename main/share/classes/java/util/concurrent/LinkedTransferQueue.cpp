#include <java/util/concurrent/LinkedTransferQueue.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/AbstractQueue.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinPool$ManagedBlocker.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/Helpers.h>
#include <java/util/concurrent/LinkedTransferQueue$Itr.h>
#include <java/util/concurrent/LinkedTransferQueue$LTQSpliterator.h>
#include <java/util/concurrent/LinkedTransferQueue$Node.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef ASYNC
#undef HEAD
#undef ITEM
#undef MAX_HOPS
#undef MAX_VALUE
#undef NEXT
#undef NOW
#undef SPIN_FOR_TIMEOUT_THRESHOLD
#undef SWEEP_THRESHOLD
#undef SYNC
#undef TAIL
#undef TIMED
#undef WAITER

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $AbstractQueue = ::java::util::AbstractQueue;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$ManagedBlocker = ::java::util::concurrent::ForkJoinPool$ManagedBlocker;
using $Helpers = ::java::util::concurrent::Helpers;
using $LinkedTransferQueue$Itr = ::java::util::concurrent::LinkedTransferQueue$Itr;
using $LinkedTransferQueue$LTQSpliterator = ::java::util::concurrent::LinkedTransferQueue$LTQSpliterator;
using $LinkedTransferQueue$Node = ::java::util::concurrent::LinkedTransferQueue$Node;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {
		namespace concurrent {

class LinkedTransferQueue$$Lambda$lambda$removeAll$0 : public $Predicate {
	$class(LinkedTransferQueue$$Lambda$lambda$removeAll$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return LinkedTransferQueue::lambda$removeAll$0(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LinkedTransferQueue$$Lambda$lambda$removeAll$0>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LinkedTransferQueue$$Lambda$lambda$removeAll$0::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(LinkedTransferQueue$$Lambda$lambda$removeAll$0, c)},
	{}
};
$MethodInfo LinkedTransferQueue$$Lambda$lambda$removeAll$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(LinkedTransferQueue$$Lambda$lambda$removeAll$0, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue$$Lambda$lambda$removeAll$0, test, bool, Object$*)},
	{}
};
$ClassInfo LinkedTransferQueue$$Lambda$lambda$removeAll$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.LinkedTransferQueue$$Lambda$lambda$removeAll$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LinkedTransferQueue$$Lambda$lambda$removeAll$0::load$($String* name, bool initialize) {
	$loadClass(LinkedTransferQueue$$Lambda$lambda$removeAll$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LinkedTransferQueue$$Lambda$lambda$removeAll$0::class$ = nullptr;

class LinkedTransferQueue$$Lambda$lambda$retainAll$1$1 : public $Predicate {
	$class(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return LinkedTransferQueue::lambda$retainAll$1(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LinkedTransferQueue$$Lambda$lambda$retainAll$1$1>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1, c)},
	{}
};
$MethodInfo LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.LinkedTransferQueue$$Lambda$lambda$retainAll$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::load$($String* name, bool initialize) {
	$loadClass(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::class$ = nullptr;

class LinkedTransferQueue$$Lambda$lambda$clear$2$2 : public $Predicate {
	$class(LinkedTransferQueue$$Lambda$lambda$clear$2$2, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* e) override {
		 return LinkedTransferQueue::lambda$clear$2(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LinkedTransferQueue$$Lambda$lambda$clear$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LinkedTransferQueue$$Lambda$lambda$clear$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LinkedTransferQueue$$Lambda$lambda$clear$2$2, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue$$Lambda$lambda$clear$2$2, test, bool, Object$*)},
	{}
};
$ClassInfo LinkedTransferQueue$$Lambda$lambda$clear$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.LinkedTransferQueue$$Lambda$lambda$clear$2$2",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* LinkedTransferQueue$$Lambda$lambda$clear$2$2::load$($String* name, bool initialize) {
	$loadClass(LinkedTransferQueue$$Lambda$lambda$clear$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LinkedTransferQueue$$Lambda$lambda$clear$2$2::class$ = nullptr;

$FieldInfo _LinkedTransferQueue_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedTransferQueue, serialVersionUID)},
	{"SPIN_FOR_TIMEOUT_THRESHOLD", "J", nullptr, $STATIC | $FINAL, $constField(LinkedTransferQueue, SPIN_FOR_TIMEOUT_THRESHOLD)},
	{"SWEEP_THRESHOLD", "I", nullptr, $STATIC | $FINAL, $constField(LinkedTransferQueue, SWEEP_THRESHOLD)},
	{"head", "Ljava/util/concurrent/LinkedTransferQueue$Node;", nullptr, $VOLATILE | $TRANSIENT, $field(LinkedTransferQueue, head)},
	{"tail", "Ljava/util/concurrent/LinkedTransferQueue$Node;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(LinkedTransferQueue, tail)},
	{"needSweep", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(LinkedTransferQueue, needSweep)},
	{"NOW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedTransferQueue, NOW)},
	{"ASYNC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedTransferQueue, ASYNC)},
	{"SYNC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedTransferQueue, SYNC)},
	{"TIMED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedTransferQueue, TIMED)},
	{"MAX_HOPS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedTransferQueue, MAX_HOPS)},
	{"HEAD", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinkedTransferQueue, HEAD)},
	{"TAIL", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinkedTransferQueue, TAIL)},
	{"ITEM", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(LinkedTransferQueue, ITEM)},
	{"NEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(LinkedTransferQueue, NEXT)},
	{"WAITER", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(LinkedTransferQueue, WAITER)},
	{}
};

$MethodInfo _LinkedTransferQueue_MethodInfo_[] = {
	{"*addAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*element", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PUBLIC, $method(LinkedTransferQueue, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(LinkedTransferQueue, init$, void, $Collection*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, add, bool, Object$*)},
	{"awaitMatch", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/lang/Object;ZJ)Ljava/lang/Object;", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;TE;ZJ)TE;", $PRIVATE, $method(LinkedTransferQueue, awaitMatch, $Object*, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*, Object$*, bool, int64_t)},
	{"bulkRemove", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PRIVATE, $method(LinkedTransferQueue, bulkRemove, bool, $Predicate*)},
	{"casHead", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;)Z", nullptr, $PRIVATE, $method(LinkedTransferQueue, casHead, bool, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*)},
	{"casTail", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;)Z", nullptr, $PRIVATE, $method(LinkedTransferQueue, casTail, bool, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, contains, bool, Object$*)},
	{"countOfMode", "(Z)I", nullptr, $PRIVATE, $method(LinkedTransferQueue, countOfMode, int32_t, bool)},
	{"drainTo", "(Ljava/util/Collection;)I", "(Ljava/util/Collection<-TE;>;)I", $PUBLIC, $virtualMethod(LinkedTransferQueue, drainTo, int32_t, $Collection*)},
	{"drainTo", "(Ljava/util/Collection;I)I", "(Ljava/util/Collection<-TE;>;I)I", $PUBLIC, $virtualMethod(LinkedTransferQueue, drainTo, int32_t, $Collection*, int32_t)},
	{"firstDataNode", "()Ljava/util/concurrent/LinkedTransferQueue$Node;", nullptr, $FINAL, $method(LinkedTransferQueue, firstDataNode, $LinkedTransferQueue$Node*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(LinkedTransferQueue, forEach, void, $Consumer*)},
	{"forEachFrom", "(Ljava/util/function/Consumer;Ljava/util/concurrent/LinkedTransferQueue$Node;)V", "(Ljava/util/function/Consumer<-TE;>;Ljava/util/concurrent/LinkedTransferQueue$Node;)V", 0, $virtualMethod(LinkedTransferQueue, forEachFrom, void, $Consumer*, $LinkedTransferQueue$Node*)},
	{"getWaitingConsumerCount", "()I", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, getWaitingConsumerCount, int32_t)},
	{"hasWaitingConsumer", "()Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, hasWaitingConsumer, bool)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(LinkedTransferQueue, iterator, $Iterator*)},
	{"lambda$clear$2", "(Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LinkedTransferQueue, lambda$clear$2, bool, Object$*)},
	{"lambda$removeAll$0", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LinkedTransferQueue, lambda$removeAll$0, bool, $Collection*, Object$*)},
	{"lambda$retainAll$1", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LinkedTransferQueue, lambda$retainAll$1, bool, $Collection*, Object$*)},
	{"offer", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;)Z", "(TE;JLjava/util/concurrent/TimeUnit;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, offer, bool, Object$*, int64_t, $TimeUnit*)},
	{"offer", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, offer, bool, Object$*)},
	{"*parallelStream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"peek", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedTransferQueue, peek, $Object*)},
	{"poll", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TE;", $PUBLIC, $virtualMethod(LinkedTransferQueue, poll, $Object*, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"poll", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedTransferQueue, poll, $Object*)},
	{"put", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(LinkedTransferQueue, put, void, Object$*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(LinkedTransferQueue, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remainingCapacity", "()I", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, remainingCapacity, int32_t)},
	{"*remove", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, removeAll, bool, $Collection*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, removeIf, bool, $Predicate*)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, retainAll, bool, $Collection*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, size, int32_t)},
	{"skipDeadNodes", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;)Ljava/util/concurrent/LinkedTransferQueue$Node;", nullptr, $PRIVATE, $method(LinkedTransferQueue, skipDeadNodes, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*)},
	{"skipDeadNodesNearHead", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;)V", nullptr, $PRIVATE, $method(LinkedTransferQueue, skipDeadNodesNearHead, void, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(LinkedTransferQueue, spliterator, $Spliterator*)},
	{"*stream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"sweep", "()V", nullptr, $PRIVATE, $method(LinkedTransferQueue, sweep, void)},
	{"take", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedTransferQueue, take, $Object*), "java.lang.InterruptedException"},
	{"*toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(LinkedTransferQueue, toArray, $ObjectArray*, $ObjectArray*)},
	{"toArrayInternal", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE, $method(LinkedTransferQueue, toArrayInternal, $ObjectArray*, $ObjectArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LinkedTransferQueue, toString, $String*)},
	{"transfer", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(LinkedTransferQueue, transfer, void, Object$*), "java.lang.InterruptedException"},
	{"tryCasSuccessor", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;)Z", nullptr, $PRIVATE, $method(LinkedTransferQueue, tryCasSuccessor, bool, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*)},
	{"tryTransfer", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, tryTransfer, bool, Object$*)},
	{"tryTransfer", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;)Z", "(TE;JLjava/util/concurrent/TimeUnit;)Z", $PUBLIC, $virtualMethod(LinkedTransferQueue, tryTransfer, bool, Object$*, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"unsplice", "(Ljava/util/concurrent/LinkedTransferQueue$Node;Ljava/util/concurrent/LinkedTransferQueue$Node;)V", nullptr, $FINAL, $method(LinkedTransferQueue, unsplice, void, $LinkedTransferQueue$Node*, $LinkedTransferQueue$Node*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(LinkedTransferQueue, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{"xfer", "(Ljava/lang/Object;ZIJ)Ljava/lang/Object;", "(TE;ZIJ)TE;", $PRIVATE, $method(LinkedTransferQueue, xfer, $Object*, Object$*, bool, int32_t, int64_t)},
	{}
};

$InnerClassInfo _LinkedTransferQueue_InnerClassesInfo_[] = {
	{"java.util.concurrent.LinkedTransferQueue$LTQSpliterator", "java.util.concurrent.LinkedTransferQueue", "LTQSpliterator", $FINAL},
	{"java.util.concurrent.LinkedTransferQueue$Itr", "java.util.concurrent.LinkedTransferQueue", "Itr", $FINAL},
	{"java.util.concurrent.LinkedTransferQueue$Node", "java.util.concurrent.LinkedTransferQueue", "Node", $STATIC | $FINAL},
	{}
};

$ClassInfo _LinkedTransferQueue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.LinkedTransferQueue",
	"java.util.AbstractQueue",
	"java.util.concurrent.TransferQueue,java.io.Serializable",
	_LinkedTransferQueue_FieldInfo_,
	_LinkedTransferQueue_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractQueue<TE;>;Ljava/util/concurrent/TransferQueue<TE;>;Ljava/io/Serializable;",
	nullptr,
	_LinkedTransferQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.LinkedTransferQueue$LTQSpliterator,java.util.concurrent.LinkedTransferQueue$Itr,java.util.concurrent.LinkedTransferQueue$Node"
};

$Object* allocate$LinkedTransferQueue($Class* clazz) {
	return $of($alloc(LinkedTransferQueue));
}

$Object* LinkedTransferQueue::remove() {
	 return this->$AbstractQueue::remove();
}

$Object* LinkedTransferQueue::element() {
	 return this->$AbstractQueue::element();
}

bool LinkedTransferQueue::addAll($Collection* c) {
	 return this->$AbstractQueue::addAll(c);
}

bool LinkedTransferQueue::containsAll($Collection* c) {
	 return this->$AbstractQueue::containsAll(c);
}

$ObjectArray* LinkedTransferQueue::toArray($IntFunction* generator) {
	 return this->$AbstractQueue::toArray(generator);
}

bool LinkedTransferQueue::equals(Object$* o) {
	 return this->$AbstractQueue::equals(o);
}

int32_t LinkedTransferQueue::hashCode() {
	 return this->$AbstractQueue::hashCode();
}

$Stream* LinkedTransferQueue::stream() {
	 return this->$AbstractQueue::stream();
}

$Stream* LinkedTransferQueue::parallelStream() {
	 return this->$AbstractQueue::parallelStream();
}

$Object* LinkedTransferQueue::clone() {
	 return this->$AbstractQueue::clone();
}

void LinkedTransferQueue::finalize() {
	this->$AbstractQueue::finalize();
}

$VarHandle* LinkedTransferQueue::HEAD = nullptr;
$VarHandle* LinkedTransferQueue::TAIL = nullptr;
$VarHandle* LinkedTransferQueue::ITEM = nullptr;
$VarHandle* LinkedTransferQueue::NEXT = nullptr;
$VarHandle* LinkedTransferQueue::WAITER = nullptr;

bool LinkedTransferQueue::casTail($LinkedTransferQueue$Node* cmp, $LinkedTransferQueue$Node* val) {
	return $nc(LinkedTransferQueue::TAIL)->compareAndSet($$new($ObjectArray, {$of(this), $of(cmp), $of(val)}));
}

bool LinkedTransferQueue::casHead($LinkedTransferQueue$Node* cmp, $LinkedTransferQueue$Node* val) {
	return $nc(LinkedTransferQueue::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(cmp), $of(val)}));
}

bool LinkedTransferQueue::tryCasSuccessor($LinkedTransferQueue$Node* pred, $LinkedTransferQueue$Node* c, $LinkedTransferQueue$Node* p) {
	if (pred != nullptr) {
		return pred->casNext(c, p);
	}
	if (casHead(c, p)) {
		$nc(c)->selfLink();
		return true;
	}
	return false;
}

$LinkedTransferQueue$Node* LinkedTransferQueue::skipDeadNodes($LinkedTransferQueue$Node* pred, $LinkedTransferQueue$Node* c, $LinkedTransferQueue$Node* p, $LinkedTransferQueue$Node* q$renamed) {
	$var($LinkedTransferQueue$Node, q, q$renamed);
	if (q == nullptr) {
		if (c == p) {
			return pred;
		}
		$assign(q, p);
	}
	bool var$0 = tryCasSuccessor(pred, c, q);
	return (var$0 && (pred == nullptr || !$nc(pred)->isMatched())) ? pred : p;
}

void LinkedTransferQueue::skipDeadNodesNearHead($LinkedTransferQueue$Node* h, $LinkedTransferQueue$Node* p$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedTransferQueue$Node, p, p$renamed);
	for (;;) {
		$var($LinkedTransferQueue$Node, q, nullptr);
		if (($assign(q, $nc(p)->next)) == nullptr) {
			break;
		} else if (!$nc(q)->isMatched()) {
			$assign(p, q);
			break;
		} else {
			$var($LinkedTransferQueue$Node, var$1, p);
			if (var$1 == ($assign(p, q))) {
				return;
			}
		}
	}
	if (casHead(h, p)) {
		$nc(h)->selfLink();
	}
}

$Object* LinkedTransferQueue::xfer(Object$* e, bool haveData, int32_t how, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	if (haveData && (e == nullptr)) {
		$throwNew($NullPointerException);
	}
	bool restart$continue = false;
	{
		$var($LinkedTransferQueue$Node, s, nullptr);
		$var($LinkedTransferQueue$Node, t, nullptr);
		$var($LinkedTransferQueue$Node, h, nullptr);
		for (;;) {
			{
				$var($LinkedTransferQueue$Node, var$1, t);
				bool var$0 = var$1 != ($assign(t, this->tail));
				$var($LinkedTransferQueue$Node, p, (var$0 && $nc(t)->isData == haveData) ? t : ($assign(h, this->head)));
				for (;;) {
					$var($LinkedTransferQueue$Node, q, nullptr);
					$var($Object, item, nullptr);
					if ($nc(p)->isData != haveData && haveData == (($assign(item, p->item)) == nullptr)) {
						if (h == nullptr) {
							$assign(h, this->head);
						}
						if (p->tryMatch(item, e)) {
							if (h != p) {
								skipDeadNodesNearHead(h, p);
							}
							return $of(item);
						}
					}
					if (($assign(q, $nc(p)->next)) == nullptr) {
						if (how == LinkedTransferQueue::NOW) {
							return $of(e);
						}
						if (s == nullptr) {
							$assign(s, $new($LinkedTransferQueue$Node, e));
						}
						if (!p->casNext(nullptr, s)) {
							continue;
						}
						if (p != t) {
							casTail(t, s);
						}
						if (how == LinkedTransferQueue::ASYNC) {
							return $of(e);
						}
						return $of(awaitMatch(s, p, e, (how == LinkedTransferQueue::TIMED), nanos));
					}
					$var($LinkedTransferQueue$Node, var$2, p);
					if (var$2 == ($assign(p, q))) {
						restart$continue = true;
						break;
					}
				}
				if (restart$continue) {
					restart$continue = false;
					continue;
				}
			}
		}
	}
}

$Object* LinkedTransferQueue::awaitMatch($LinkedTransferQueue$Node* s, $LinkedTransferQueue$Node* pred, Object$* e, bool timed, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	bool isData = $nc(s)->isData;
	int64_t deadline = timed ? $System::nanoTime() + nanos : (int64_t)0;
	$var($Thread, w, $Thread::currentThread());
	int32_t stat = -1;
	$var($Object, item, nullptr);
	while ($equals($assign(item, s->item), e)) {
		if (this->needSweep) {
			sweep();
		} else if ((timed && nanos <= (int64_t)0) || w->isInterrupted()) {
			if (s->casItem(e, (e == nullptr) ? $of(s) : ($Object*)nullptr)) {
				unsplice(pred, s);
				return $of(e);
			}
		} else if (stat <= 0) {
			if (pred != nullptr && pred->next == s) {
				if (stat < 0 && (pred->isData != isData || pred->isMatched())) {
					stat = 0;
					$Thread::yield();
				} else {
					stat = 1;
					$set(s, waiter, w);
				}
			}
		} else if (!$equals($assign(item, s->item), e)) {
			break;
		} else if (!timed) {
			$LockSupport::setCurrentBlocker(this);
			try {
				$ForkJoinPool::managedBlock(s);
			} catch ($InterruptedException& cannotHappen) {
			}
			$LockSupport::setCurrentBlocker(nullptr);
		} else {
			nanos = deadline - $System::nanoTime();
			if (nanos > LinkedTransferQueue::SPIN_FOR_TIMEOUT_THRESHOLD) {
				$LockSupport::parkNanos(this, nanos);
			}
		}
	}
	if (stat == 1) {
		$nc(LinkedTransferQueue::WAITER)->set($$new($ObjectArray, {$of(s), ($Object*)nullptr}));
	}
	if (!isData) {
		$nc(LinkedTransferQueue::ITEM)->set($$new($ObjectArray, {$of(s), $of(s)}));
	}
	return $of(item);
}

$LinkedTransferQueue$Node* LinkedTransferQueue::firstDataNode() {
	$useLocalCurrentObjectStackCache();
	$var($LinkedTransferQueue$Node, first, nullptr);
	bool restartFromHead$continue = false;
	for (;;) {
		$var($LinkedTransferQueue$Node, h, this->head);
		$var($LinkedTransferQueue$Node, p, h);
		while (p != nullptr) {
			if (p->item != nullptr) {
				if (p->isData) {
					$assign(first, p);
					break;
				}
			} else if (!p->isData) {
				break;
			}
			$var($LinkedTransferQueue$Node, q, nullptr);
			if (($assign(q, p->next)) == nullptr) {
				break;
			}
			$var($LinkedTransferQueue$Node, var$0, p);
			if (var$0 == ($assign(p, q))) {
				restartFromHead$continue = true;
				break;
			}
		}
		if (restartFromHead$continue) {
			restartFromHead$continue = false;
			continue;
		}
		if (p != h && casHead(h, p)) {
			$nc(h)->selfLink();
		}
		return first;
	}
}

int32_t LinkedTransferQueue::countOfMode(bool data) {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t count = 0;
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			for (; p != nullptr;) {
				if (!p->isMatched()) {
					if (p->isData != data) {
						return 0;
					}
					if (++count == $Integer::MAX_VALUE) {
						break;
					}
				}
				$var($LinkedTransferQueue$Node, var$0, p);
				if (var$0 == ($assign(p, p->next))) {
					restartFromHead$continue = true;
					break;
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		return count;
	}
}

$String* LinkedTransferQueue::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, a, nullptr);
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t charLength = 0;
		int32_t size = 0;
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			for (; p != nullptr;) {
				$var($Object, item, p->item);
				if (p->isData) {
					if (item != nullptr) {
						if (a == nullptr) {
							$assign(a, $new($StringArray, 4));
						} else if (size == $nc(a)->length) {
							$assign(a, $fcast($StringArray, $Arrays::copyOf(a, 2 * size)));
						}
						$var($String, s, $of(item)->toString());
						$nc(a)->set(size++, s);
						charLength += $nc(s)->length();
					}
				} else if (item == nullptr) {
					break;
				}
				$var($LinkedTransferQueue$Node, var$0, p);
				if (var$0 == ($assign(p, p->next))) {
					restartFromHead$continue = true;
					break;
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		if (size == 0) {
			return "[]"_s;
		}
		return $Helpers::toString(a, size, charLength);
	}
}

$ObjectArray* LinkedTransferQueue::toArrayInternal($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, x, a);
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t size = 0;
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			for (; p != nullptr;) {
				$var($Object, item, p->item);
				if (p->isData) {
					if (item != nullptr) {
						if (x == nullptr) {
							$assign(x, $new($ObjectArray, 4));
						} else if (size == $nc(x)->length) {
							$assign(x, $Arrays::copyOf(x, 2 * (size + 4)));
						}
						$nc(x)->set(size++, item);
					}
				} else if (item == nullptr) {
					break;
				}
				$var($LinkedTransferQueue$Node, var$0, p);
				if (var$0 == ($assign(p, p->next))) {
					restartFromHead$continue = true;
					break;
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		if (x == nullptr) {
			return $new($ObjectArray, 0);
		} else if (a != nullptr && size <= a->length) {
			if (a != x) {
				$System::arraycopy(x, 0, a, 0, size);
			}
			if (size < a->length) {
				a->set(size, nullptr);
			}
			return a;
		}
		return (size == $nc(x)->length) ? x : $Arrays::copyOf(x, size);
	}
}

$ObjectArray* LinkedTransferQueue::toArray() {
	return toArrayInternal(nullptr);
}

$ObjectArray* LinkedTransferQueue::toArray($ObjectArray* a) {
	$Objects::requireNonNull(a);
	return toArrayInternal(a);
}

$Spliterator* LinkedTransferQueue::spliterator() {
	return $new($LinkedTransferQueue$LTQSpliterator, this);
}

void LinkedTransferQueue::unsplice($LinkedTransferQueue$Node* pred, $LinkedTransferQueue$Node* s) {
	$useLocalCurrentObjectStackCache();
	$set($nc(s), waiter, nullptr);
	if (pred != nullptr && pred->next == s) {
		$var($LinkedTransferQueue$Node, n, s->next);
		bool var$0 = n == nullptr;
		if (!var$0) {
			bool var$1 = n != s && pred->casNext(s, n);
			var$0 = (var$1 && pred->isMatched());
		}
		if (var$0) {
			for (;;) {
				$var($LinkedTransferQueue$Node, h, this->head);
				if (h == pred || h == s) {
					return;
				}
				if (!$nc(h)->isMatched()) {
					break;
				}
				$var($LinkedTransferQueue$Node, hn, $nc(h)->next);
				if (hn == nullptr) {
					return;
				}
				if (hn != h && casHead(h, hn)) {
					h->selfLink();
				}
			}
			if (pred->next != pred && s->next != s) {
				this->needSweep = true;
			}
		}
	}
}

void LinkedTransferQueue::sweep() {
	$useLocalCurrentObjectStackCache();
	this->needSweep = false;
	{
		$var($LinkedTransferQueue$Node, p, this->head);
		$var($LinkedTransferQueue$Node, s, nullptr);
		$var($LinkedTransferQueue$Node, n, nullptr);
		for (; p != nullptr && ($assign(s, p->next)) != nullptr;) {
			if (!$nc(s)->isMatched()) {
				$assign(p, s);
			} else if (($assign(n, s->next)) == nullptr) {
				break;
			} else if (s == n) {
				$assign(p, this->head);
			} else {
				p->casNext(s, n);
			}
		}
	}
}

void LinkedTransferQueue::init$() {
	$AbstractQueue::init$();
	$set(this, head, ($set(this, tail, $new($LinkedTransferQueue$Node))));
}

void LinkedTransferQueue::init$($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$AbstractQueue::init$();
	$var($LinkedTransferQueue$Node, h, nullptr);
	$var($LinkedTransferQueue$Node, t, nullptr);
	{
		$var($Iterator, i$, $nc(c)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			{
				$var($LinkedTransferQueue$Node, newNode, $new($LinkedTransferQueue$Node, $Objects::requireNonNull(e)));
				if (h == nullptr) {
					$assign(h, ($assign(t, newNode)));
				} else {
					$nc(t)->appendRelaxed($assign(t, newNode));
				}
			}
		}
	}
	if (h == nullptr) {
		$assign(h, ($assign(t, $new($LinkedTransferQueue$Node))));
	}
	$set(this, head, h);
	$set(this, tail, t);
}

void LinkedTransferQueue::put(Object$* e) {
	xfer(e, true, LinkedTransferQueue::ASYNC, 0);
}

bool LinkedTransferQueue::offer(Object$* e, int64_t timeout, $TimeUnit* unit) {
	xfer(e, true, LinkedTransferQueue::ASYNC, 0);
	return true;
}

bool LinkedTransferQueue::offer(Object$* e) {
	xfer(e, true, LinkedTransferQueue::ASYNC, 0);
	return true;
}

bool LinkedTransferQueue::add(Object$* e) {
	xfer(e, true, LinkedTransferQueue::ASYNC, 0);
	return true;
}

bool LinkedTransferQueue::tryTransfer(Object$* e) {
	return xfer(e, true, LinkedTransferQueue::NOW, 0) == nullptr;
}

void LinkedTransferQueue::transfer(Object$* e) {
	if (xfer(e, true, LinkedTransferQueue::SYNC, 0) != nullptr) {
		$Thread::interrupted();
		$throwNew($InterruptedException);
	}
}

bool LinkedTransferQueue::tryTransfer(Object$* e, int64_t timeout, $TimeUnit* unit) {
	if (xfer(e, true, LinkedTransferQueue::TIMED, $nc(unit)->toNanos(timeout)) == nullptr) {
		return true;
	}
	if (!$Thread::interrupted()) {
		return false;
	}
	$throwNew($InterruptedException);
}

$Object* LinkedTransferQueue::take() {
	$var($Object, e, xfer(nullptr, false, LinkedTransferQueue::SYNC, 0));
	if (e != nullptr) {
		return $of(e);
	}
	$Thread::interrupted();
	$throwNew($InterruptedException);
}

$Object* LinkedTransferQueue::poll(int64_t timeout, $TimeUnit* unit) {
	$var($Object, e, xfer(nullptr, false, LinkedTransferQueue::TIMED, $nc(unit)->toNanos(timeout)));
	if (e != nullptr || !$Thread::interrupted()) {
		return $of(e);
	}
	$throwNew($InterruptedException);
}

$Object* LinkedTransferQueue::poll() {
	return $of(xfer(nullptr, false, LinkedTransferQueue::NOW, 0));
}

int32_t LinkedTransferQueue::drainTo($Collection* c) {
	$Objects::requireNonNull(c);
	if ($equals(c, this)) {
		$throwNew($IllegalArgumentException);
	}
	int32_t n = 0;
	{
		$var($Object, e, nullptr);
		for (; ($assign(e, poll())) != nullptr; ++n) {
			c->add(e);
		}
	}
	return n;
}

int32_t LinkedTransferQueue::drainTo($Collection* c, int32_t maxElements) {
	$Objects::requireNonNull(c);
	if ($equals(c, this)) {
		$throwNew($IllegalArgumentException);
	}
	int32_t n = 0;
	{
		$var($Object, e, nullptr);
		for (; n < maxElements && ($assign(e, poll())) != nullptr; ++n) {
			c->add(e);
		}
	}
	return n;
}

$Iterator* LinkedTransferQueue::iterator() {
	return $new($LinkedTransferQueue$Itr, this);
}

$Object* LinkedTransferQueue::peek() {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			for (; p != nullptr;) {
				$var($Object, item, p->item);
				if (p->isData) {
					if (item != nullptr) {
						$var($Object, e, item);
						return $of(e);
					}
				} else if (item == nullptr) {
					break;
				}
				$var($LinkedTransferQueue$Node, var$0, p);
				if (var$0 == ($assign(p, p->next))) {
					restartFromHead$continue = true;
					break;
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		return $of(nullptr);
	}
}

bool LinkedTransferQueue::isEmpty() {
	return firstDataNode() == nullptr;
}

bool LinkedTransferQueue::hasWaitingConsumer() {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			for (; p != nullptr;) {
				$var($Object, item, p->item);
				if (p->isData) {
					if (item != nullptr) {
						break;
					}
				} else if (item == nullptr) {
					return true;
				}
				$var($LinkedTransferQueue$Node, var$0, p);
				if (var$0 == ($assign(p, p->next))) {
					restartFromHead$continue = true;
					break;
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		return false;
	}
}

int32_t LinkedTransferQueue::size() {
	return countOfMode(true);
}

int32_t LinkedTransferQueue::getWaitingConsumerCount() {
	return countOfMode(false);
}

bool LinkedTransferQueue::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (o == nullptr) {
		return false;
	}
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			$var($LinkedTransferQueue$Node, pred, nullptr);
			for (; p != nullptr;) {
				$var($LinkedTransferQueue$Node, q, p->next);
				$var($Object, item, nullptr);
				if (($assign(item, p->item)) != nullptr) {
					if (p->isData) {
						bool var$0 = $nc($of(o))->equals(item);
						if (var$0 && p->tryMatch(item, nullptr)) {
							skipDeadNodes(pred, p, p, q);
							return true;
						}
						$assign(pred, p);
						$assign(p, q);
						continue;
					}
				} else if (!p->isData) {
					break;
				}
				{
					$var($LinkedTransferQueue$Node, c, p);
					for (;; $assign(q, p->next)) {
						if (q == nullptr || !$nc(q)->isMatched()) {
							$assign(pred, skipDeadNodes(pred, c, p, q));
							$assign(p, q);
							break;
						}
						$var($LinkedTransferQueue$Node, var$1, p);
						if (var$1 == ($assign(p, q))) {
							restartFromHead$continue = true;
							break;
						}
					}
					if (restartFromHead$continue) {
						break;
					}
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		return false;
	}
}

bool LinkedTransferQueue::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (o == nullptr) {
		return false;
	}
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			$var($LinkedTransferQueue$Node, pred, nullptr);
			for (; p != nullptr;) {
				$var($LinkedTransferQueue$Node, q, p->next);
				$var($Object, item, nullptr);
				if (($assign(item, p->item)) != nullptr) {
					if (p->isData) {
						if ($nc($of(o))->equals(item)) {
							return true;
						}
						$assign(pred, p);
						$assign(p, q);
						continue;
					}
				} else if (!p->isData) {
					break;
				}
				{
					$var($LinkedTransferQueue$Node, c, p);
					for (;; $assign(q, p->next)) {
						if (q == nullptr || !$nc(q)->isMatched()) {
							$assign(pred, skipDeadNodes(pred, c, p, q));
							$assign(p, q);
							break;
						}
						$var($LinkedTransferQueue$Node, var$0, p);
						if (var$0 == ($assign(p, q))) {
							restartFromHead$continue = true;
							break;
						}
					}
					if (restartFromHead$continue) {
						break;
					}
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		return false;
	}
}

int32_t LinkedTransferQueue::remainingCapacity() {
	return $Integer::MAX_VALUE;
}

void LinkedTransferQueue::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	{
		$var($Iterator, i$, this->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			s->writeObject(e);
		}
	}
	s->writeObject(nullptr);
}

void LinkedTransferQueue::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedTransferQueue$Node, h, nullptr);
	$var($LinkedTransferQueue$Node, t, nullptr);
	{
		$var($Object, item, nullptr);
		for (; ($assign(item, $nc(s)->readObject())) != nullptr;) {
			$var($LinkedTransferQueue$Node, newNode, $new($LinkedTransferQueue$Node, item));
			if (h == nullptr) {
				$assign(h, ($assign(t, newNode)));
			} else {
				$nc(t)->appendRelaxed($assign(t, newNode));
			}
		}
	}
	if (h == nullptr) {
		$assign(h, ($assign(t, $new($LinkedTransferQueue$Node))));
	}
	$set(this, head, h);
	$set(this, tail, t);
}

bool LinkedTransferQueue::removeIf($Predicate* filter) {
	$Objects::requireNonNull(filter);
	return bulkRemove(filter);
}

bool LinkedTransferQueue::removeAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(LinkedTransferQueue$$Lambda$lambda$removeAll$0, c)));
}

bool LinkedTransferQueue::retainAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1, c)));
}

void LinkedTransferQueue::clear() {
	bulkRemove(static_cast<$Predicate*>($$new(LinkedTransferQueue$$Lambda$lambda$clear$2$2)));
}

bool LinkedTransferQueue::bulkRemove($Predicate* filter) {
	$useLocalCurrentObjectStackCache();
	bool removed = false;
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t hops = LinkedTransferQueue::MAX_HOPS;
		{
			$var($LinkedTransferQueue$Node, p, this->head);
			$var($LinkedTransferQueue$Node, c, p);
			$var($LinkedTransferQueue$Node, pred, nullptr);
			$var($LinkedTransferQueue$Node, q, nullptr);
			for (; p != nullptr; $assign(p, q)) {
				$assign(q, $nc(p)->next);
				$var($Object, item, nullptr);
				bool pAlive = false;
				if (pAlive = (($assign(item, p->item)) != nullptr && p->isData)) {
					if ($nc(filter)->test(item)) {
						if (p->tryMatch(item, nullptr)) {
							removed = true;
						}
						pAlive = false;
					}
				} else if (!p->isData && item == nullptr) {
					break;
				}
				if (pAlive || q == nullptr || --hops == 0) {
					bool var$0 = c != p;
					if (var$0) {
						$var($LinkedTransferQueue$Node, var$1, pred);
						$var($LinkedTransferQueue$Node, var$2, c);
						var$0 = !tryCasSuccessor(var$1, var$2, $assign(c, p));
					}
					if ((var$0) || pAlive) {
						hops = LinkedTransferQueue::MAX_HOPS;
						$assign(pred, p);
						$assign(c, q);
					}
				} else if (p == q) {
					restartFromHead$continue = true;
					break;
				}
			}
			if (restartFromHead$continue) {
				restartFromHead$continue = false;
				continue;
			}
		}
		return removed;
	}
}

void LinkedTransferQueue::forEachFrom($Consumer* action, $LinkedTransferQueue$Node* p$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedTransferQueue$Node, p, p$renamed);
	{
		$var($LinkedTransferQueue$Node, pred, nullptr);
		for (; p != nullptr;) {
			$var($LinkedTransferQueue$Node, q, p->next);
			$var($Object, item, nullptr);
			if (($assign(item, p->item)) != nullptr) {
				if (p->isData) {
					$nc(action)->accept(item);
					$assign(pred, p);
					$assign(p, q);
					continue;
				}
			} else if (!p->isData) {
				break;
			}
			{
				$var($LinkedTransferQueue$Node, c, p);
				for (;; $assign(q, p->next)) {
					if (q == nullptr || !$nc(q)->isMatched()) {
						$assign(pred, skipDeadNodes(pred, c, p, q));
						$assign(p, q);
						break;
					}
					$var($LinkedTransferQueue$Node, var$0, p);
					if (var$0 == ($assign(p, q))) {
						$assign(pred, nullptr);
						$assign(p, this->head);
						break;
					}
				}
			}
		}
	}
}

void LinkedTransferQueue::forEach($Consumer* action) {
	$Objects::requireNonNull(action);
	forEachFrom(action, this->head);
}

bool LinkedTransferQueue::lambda$clear$2(Object$* e) {
	$init(LinkedTransferQueue);
	return true;
}

bool LinkedTransferQueue::lambda$retainAll$1($Collection* c, Object$* e) {
	$init(LinkedTransferQueue);
	return !$nc(c)->contains(e);
}

bool LinkedTransferQueue::lambda$removeAll$0($Collection* c, Object$* e) {
	$init(LinkedTransferQueue);
	return $nc(c)->contains(e);
}

void clinit$LinkedTransferQueue($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$load($LinkedTransferQueue$Node);
			$assignStatic(LinkedTransferQueue::HEAD, $nc(l)->findVarHandle(LinkedTransferQueue::class$, "head"_s, $LinkedTransferQueue$Node::class$));
			$assignStatic(LinkedTransferQueue::TAIL, l->findVarHandle(LinkedTransferQueue::class$, "tail"_s, $LinkedTransferQueue$Node::class$));
			$assignStatic(LinkedTransferQueue::ITEM, l->findVarHandle($LinkedTransferQueue$Node::class$, "item"_s, $Object::class$));
			$assignStatic(LinkedTransferQueue::NEXT, l->findVarHandle($LinkedTransferQueue$Node::class$, "next"_s, $LinkedTransferQueue$Node::class$));
			$assignStatic(LinkedTransferQueue::WAITER, l->findVarHandle($LinkedTransferQueue$Node::class$, "waiter"_s, $Thread::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
		$load($LockSupport);
		$Class* ensureLoaded = $LockSupport::class$;
	}
}

LinkedTransferQueue::LinkedTransferQueue() {
}

$Class* LinkedTransferQueue::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LinkedTransferQueue$$Lambda$lambda$removeAll$0::classInfo$.name)) {
			return LinkedTransferQueue$$Lambda$lambda$removeAll$0::load$(name, initialize);
		}
		if (name->equals(LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::classInfo$.name)) {
			return LinkedTransferQueue$$Lambda$lambda$retainAll$1$1::load$(name, initialize);
		}
		if (name->equals(LinkedTransferQueue$$Lambda$lambda$clear$2$2::classInfo$.name)) {
			return LinkedTransferQueue$$Lambda$lambda$clear$2$2::load$(name, initialize);
		}
	}
	$loadClass(LinkedTransferQueue, name, initialize, &_LinkedTransferQueue_ClassInfo_, clinit$LinkedTransferQueue, allocate$LinkedTransferQueue);
	return class$;
}

$Class* LinkedTransferQueue::class$ = nullptr;

		} // concurrent
	} // util
} // java