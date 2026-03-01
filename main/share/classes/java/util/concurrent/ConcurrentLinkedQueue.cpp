#include <java/util/concurrent/ConcurrentLinkedQueue.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ExceptionInInitializerError.h>
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
#include <java/util/concurrent/ConcurrentLinkedQueue$CLQSpliterator.h>
#include <java/util/concurrent/ConcurrentLinkedQueue$Itr.h>
#include <java/util/concurrent/ConcurrentLinkedQueue$Node.h>
#include <java/util/concurrent/Helpers.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <jcpp.h>

#undef HEAD
#undef ITEM
#undef MAX_HOPS
#undef MAX_VALUE
#undef NEXT
#undef TAIL

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
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
using $ConcurrentLinkedQueue$CLQSpliterator = ::java::util::concurrent::ConcurrentLinkedQueue$CLQSpliterator;
using $ConcurrentLinkedQueue$Itr = ::java::util::concurrent::ConcurrentLinkedQueue$Itr;
using $ConcurrentLinkedQueue$Node = ::java::util::concurrent::ConcurrentLinkedQueue$Node;
using $Helpers = ::java::util::concurrent::Helpers;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;

namespace java {
	namespace util {
		namespace concurrent {

class ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0 : public $Predicate {
	$class(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return ConcurrentLinkedQueue::lambda$removeAll$0(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0, c)},
	{}
};
$MethodInfo ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0, test, bool, Object$*)},
	{}
};
$ClassInfo ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::load$($String* name, bool initialize) {
	$loadClass(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::class$ = nullptr;

class ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1 : public $Predicate {
	$class(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return ConcurrentLinkedQueue::lambda$retainAll$1(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1, c)},
	{}
};
$MethodInfo ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::load$($String* name, bool initialize) {
	$loadClass(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::class$ = nullptr;

class ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2 : public $Predicate {
	$class(ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* e) override {
		 return ConcurrentLinkedQueue::lambda$clear$2(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2, test, bool, Object$*)},
	{}
};
$ClassInfo ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.concurrent.ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2::load$($String* name, bool initialize) {
	$loadClass(ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2::class$ = nullptr;

$FieldInfo _ConcurrentLinkedQueue_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentLinkedQueue, serialVersionUID)},
	{"head", "Ljava/util/concurrent/ConcurrentLinkedQueue$Node;", "Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;", $VOLATILE | $TRANSIENT, $field(ConcurrentLinkedQueue, head)},
	{"tail", "Ljava/util/concurrent/ConcurrentLinkedQueue$Node;", "Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(ConcurrentLinkedQueue, tail)},
	{"MAX_HOPS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentLinkedQueue, MAX_HOPS)},
	{"HEAD", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentLinkedQueue, HEAD)},
	{"TAIL", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ConcurrentLinkedQueue, TAIL)},
	{"ITEM", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(ConcurrentLinkedQueue, ITEM)},
	{"NEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $STATIC | $FINAL, $staticField(ConcurrentLinkedQueue, NEXT)},
	{}
};

$MethodInfo _ConcurrentLinkedQueue_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConcurrentLinkedQueue, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(ConcurrentLinkedQueue, init$, void, $Collection*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, add, bool, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, addAll, bool, $Collection*)},
	{"bulkRemove", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PRIVATE, $method(ConcurrentLinkedQueue, bulkRemove, bool, $Predicate*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, contains, bool, Object$*)},
	{"first", "()Ljava/util/concurrent/ConcurrentLinkedQueue$Node;", "()Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;", 0, $virtualMethod(ConcurrentLinkedQueue, first, $ConcurrentLinkedQueue$Node*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, forEach, void, $Consumer*)},
	{"forEachFrom", "(Ljava/util/function/Consumer;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;)V", "(Ljava/util/function/Consumer<-TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;)V", 0, $virtualMethod(ConcurrentLinkedQueue, forEachFrom, void, $Consumer*, $ConcurrentLinkedQueue$Node*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, iterator, $Iterator*)},
	{"lambda$clear$2", "(Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ConcurrentLinkedQueue, lambda$clear$2, bool, Object$*)},
	{"lambda$removeAll$0", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ConcurrentLinkedQueue, lambda$removeAll$0, bool, $Collection*, Object$*)},
	{"lambda$retainAll$1", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ConcurrentLinkedQueue, lambda$retainAll$1, bool, $Collection*, Object$*)},
	{"offer", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, offer, bool, Object$*)},
	{"peek", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, peek, $Object*)},
	{"poll", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, poll, $Object*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ConcurrentLinkedQueue, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, removeAll, bool, $Collection*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, removeIf, bool, $Predicate*)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, retainAll, bool, $Collection*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, size, int32_t)},
	{"skipDeadNodes", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;)Ljava/util/concurrent/ConcurrentLinkedQueue$Node;", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;)Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;", $PRIVATE, $method(ConcurrentLinkedQueue, skipDeadNodes, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, spliterator, $Spliterator*)},
	{"succ", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node;)Ljava/util/concurrent/ConcurrentLinkedQueue$Node;", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;)Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;", $FINAL, $method(ConcurrentLinkedQueue, succ, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, toArray, $ObjectArray*, $ObjectArray*)},
	{"toArrayInternal", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE, $method(ConcurrentLinkedQueue, toArrayInternal, $ObjectArray*, $ObjectArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ConcurrentLinkedQueue, toString, $String*)},
	{"tryCasSuccessor", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;)Z", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;)Z", $PRIVATE, $method(ConcurrentLinkedQueue, tryCasSuccessor, bool, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*)},
	{"updateHead", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node;Ljava/util/concurrent/ConcurrentLinkedQueue$Node;)V", "(Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;Ljava/util/concurrent/ConcurrentLinkedQueue$Node<TE;>;)V", $FINAL, $method(ConcurrentLinkedQueue, updateHead, void, $ConcurrentLinkedQueue$Node*, $ConcurrentLinkedQueue$Node*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(ConcurrentLinkedQueue, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ConcurrentLinkedQueue_InnerClassesInfo_[] = {
	{"java.util.concurrent.ConcurrentLinkedQueue$CLQSpliterator", "java.util.concurrent.ConcurrentLinkedQueue", "CLQSpliterator", $FINAL},
	{"java.util.concurrent.ConcurrentLinkedQueue$Itr", "java.util.concurrent.ConcurrentLinkedQueue", "Itr", $PRIVATE},
	{"java.util.concurrent.ConcurrentLinkedQueue$Node", "java.util.concurrent.ConcurrentLinkedQueue", "Node", $STATIC | $FINAL},
	{}
};

$ClassInfo _ConcurrentLinkedQueue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.ConcurrentLinkedQueue",
	"java.util.AbstractQueue",
	"java.io.Serializable",
	_ConcurrentLinkedQueue_FieldInfo_,
	_ConcurrentLinkedQueue_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractQueue<TE;>;Ljava/util/Queue<TE;>;Ljava/io/Serializable;",
	nullptr,
	_ConcurrentLinkedQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.ConcurrentLinkedQueue$CLQSpliterator,java.util.concurrent.ConcurrentLinkedQueue$Itr,java.util.concurrent.ConcurrentLinkedQueue$Node"
};

$Object* allocate$ConcurrentLinkedQueue($Class* clazz) {
	return $of($alloc(ConcurrentLinkedQueue));
}

bool ConcurrentLinkedQueue::equals(Object$* o) {
	 return this->$AbstractQueue::equals(o);
}

int32_t ConcurrentLinkedQueue::hashCode() {
	 return this->$AbstractQueue::hashCode();
}

$Object* ConcurrentLinkedQueue::clone() {
	 return this->$AbstractQueue::clone();
}

void ConcurrentLinkedQueue::finalize() {
	this->$AbstractQueue::finalize();
}

$VarHandle* ConcurrentLinkedQueue::HEAD = nullptr;
$VarHandle* ConcurrentLinkedQueue::TAIL = nullptr;
$VarHandle* ConcurrentLinkedQueue::ITEM = nullptr;
$VarHandle* ConcurrentLinkedQueue::NEXT = nullptr;

void ConcurrentLinkedQueue::init$() {
	$AbstractQueue::init$();
	$set(this, head, ($set(this, tail, $new($ConcurrentLinkedQueue$Node))));
}

void ConcurrentLinkedQueue::init$($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$AbstractQueue::init$();
	$var($ConcurrentLinkedQueue$Node, h, nullptr);
	$var($ConcurrentLinkedQueue$Node, t, nullptr);
	{
		$var($Iterator, i$, $nc(c)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			{
				$var($ConcurrentLinkedQueue$Node, newNode, $new($ConcurrentLinkedQueue$Node, $Objects::requireNonNull(e)));
				if (h == nullptr) {
					$assign(h, ($assign(t, newNode)));
				} else {
					$nc(t)->appendRelaxed($assign(t, newNode));
				}
			}
		}
	}
	if (h == nullptr) {
		$assign(h, ($assign(t, $new($ConcurrentLinkedQueue$Node))));
	}
	$set(this, head, h);
	$set(this, tail, t);
}

bool ConcurrentLinkedQueue::add(Object$* e) {
	return offer(e);
}

void ConcurrentLinkedQueue::updateHead($ConcurrentLinkedQueue$Node* h, $ConcurrentLinkedQueue$Node* p) {
	$useLocalCurrentObjectStackCache();
	if (h != p && $nc(ConcurrentLinkedQueue::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(h), $of(p)}))) {
		$nc(ConcurrentLinkedQueue::NEXT)->setRelease($$new($ObjectArray, {$of(h), $of(h)}));
	}
}

$ConcurrentLinkedQueue$Node* ConcurrentLinkedQueue::succ($ConcurrentLinkedQueue$Node* p$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentLinkedQueue$Node, p, p$renamed);
	$var($ConcurrentLinkedQueue$Node, var$0, p);
	if (var$0 == ($assign(p, $nc(p)->next))) {
		$assign(p, this->head);
	}
	return p;
}

bool ConcurrentLinkedQueue::tryCasSuccessor($ConcurrentLinkedQueue$Node* pred, $ConcurrentLinkedQueue$Node* c, $ConcurrentLinkedQueue$Node* p) {
	$useLocalCurrentObjectStackCache();
	if (pred != nullptr) {
		return $nc(ConcurrentLinkedQueue::NEXT)->compareAndSet($$new($ObjectArray, {$of(pred), $of(c), $of(p)}));
	}
	if ($nc(ConcurrentLinkedQueue::HEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(c), $of(p)}))) {
		$nc(ConcurrentLinkedQueue::NEXT)->setRelease($$new($ObjectArray, {$of(c), $of(c)}));
		return true;
	}
	return false;
}

$ConcurrentLinkedQueue$Node* ConcurrentLinkedQueue::skipDeadNodes($ConcurrentLinkedQueue$Node* pred, $ConcurrentLinkedQueue$Node* c, $ConcurrentLinkedQueue$Node* p, $ConcurrentLinkedQueue$Node* q$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentLinkedQueue$Node, q, q$renamed);
	if (q == nullptr) {
		if (c == p) {
			return pred;
		}
		$assign(q, p);
	}
	bool var$0 = tryCasSuccessor(pred, c, q);
	return (var$0 && (pred == nullptr || $nc(ConcurrentLinkedQueue::ITEM)->get($$new($ObjectArray, {$of(pred)})) != nullptr)) ? pred : p;
}

bool ConcurrentLinkedQueue::offer(Object$* e) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentLinkedQueue$Node, newNode, $new($ConcurrentLinkedQueue$Node, $Objects::requireNonNull(e)));
	{
		$var($ConcurrentLinkedQueue$Node, t, this->tail);
		$var($ConcurrentLinkedQueue$Node, p, t);
		for (;;) {
			$var($ConcurrentLinkedQueue$Node, q, $nc(p)->next);
			if (q == nullptr) {
				if ($nc(ConcurrentLinkedQueue::NEXT)->compareAndSet($$new($ObjectArray, {$of(p), ($Object*)nullptr, $of(newNode)}))) {
					if (p != t) {
						$nc(ConcurrentLinkedQueue::TAIL)->weakCompareAndSet($$new($ObjectArray, {$of(this), $of(t), $of(newNode)}));
					}
					return true;
				}
			} else if (p == q) {
				$var($ConcurrentLinkedQueue$Node, var$0, t);
				$assign(p, (var$0 != ($assign(t, this->tail))) ? t : $cast($ConcurrentLinkedQueue$Node, this->head));
			} else {
				bool var$1 = p != t;
				if (var$1) {
					$var($ConcurrentLinkedQueue$Node, var$2, t);
					var$1 = var$2 != ($assign(t, this->tail));
				}
				$assign(p, (var$1) ? t : q);
			}
		}
	}
}

$Object* ConcurrentLinkedQueue::poll() {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($ConcurrentLinkedQueue$Node, h, this->head);
			$var($ConcurrentLinkedQueue$Node, p, h);
			$var($ConcurrentLinkedQueue$Node, q, nullptr);
			for (;; $assign(p, q)) {
				$var($Object, item, nullptr);
				bool var$0 = ($assign(item, $nc(p)->item)) != nullptr;
				if (var$0 && p->casItem(item, nullptr)) {
					if (p != h) {
						updateHead(h, (($assign(q, p->next)) != nullptr) ? q : p);
					}
					return $of(item);
				} else if (($assign(q, p->next)) == nullptr) {
					updateHead(h, p);
					return $of(nullptr);
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
	}
}

$Object* ConcurrentLinkedQueue::peek() {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($ConcurrentLinkedQueue$Node, h, this->head);
			$var($ConcurrentLinkedQueue$Node, p, h);
			$var($ConcurrentLinkedQueue$Node, q, nullptr);
			for (;; $assign(p, q)) {
				$var($Object, item, nullptr);
				if (($assign(item, $nc(p)->item)) != nullptr || ($assign(q, $nc(p)->next)) == nullptr) {
					updateHead(h, p);
					return $of(item);
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
	}
}

$ConcurrentLinkedQueue$Node* ConcurrentLinkedQueue::first() {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($ConcurrentLinkedQueue$Node, h, this->head);
			$var($ConcurrentLinkedQueue$Node, p, h);
			$var($ConcurrentLinkedQueue$Node, q, nullptr);
			for (;; $assign(p, q)) {
				bool hasItem = ($nc(p)->item != nullptr);
				if (hasItem || ($assign(q, p->next)) == nullptr) {
					updateHead(h, p);
					return hasItem ? p : ($ConcurrentLinkedQueue$Node*)nullptr;
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
	}
}

bool ConcurrentLinkedQueue::isEmpty() {
	return first() == nullptr;
}

int32_t ConcurrentLinkedQueue::size() {
	$useLocalCurrentObjectStackCache();
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t count = 0;
		{
			$var($ConcurrentLinkedQueue$Node, p, first());
			for (; p != nullptr;) {
				if (p->item != nullptr) {
					if (++count == $Integer::MAX_VALUE) {
						break;
					}
				}
				$var($ConcurrentLinkedQueue$Node, var$0, p);
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

bool ConcurrentLinkedQueue::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (o == nullptr) {
		return false;
	}
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($ConcurrentLinkedQueue$Node, p, this->head);
			$var($ConcurrentLinkedQueue$Node, pred, nullptr);
			for (; p != nullptr;) {
				$var($ConcurrentLinkedQueue$Node, q, p->next);
				$var($Object, item, nullptr);
				if (($assign(item, p->item)) != nullptr) {
					if ($nc($of(o))->equals(item)) {
						return true;
					}
					$assign(pred, p);
					$assign(p, q);
					continue;
				}
				{
					$var($ConcurrentLinkedQueue$Node, c, p);
					for (;; $assign(q, p->next)) {
						if (q == nullptr || $nc(q)->item != nullptr) {
							$assign(pred, skipDeadNodes(pred, c, p, q));
							$assign(p, q);
							break;
						}
						$var($ConcurrentLinkedQueue$Node, var$0, p);
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

bool ConcurrentLinkedQueue::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (o == nullptr) {
		return false;
	}
	bool restartFromHead$continue = false;
	for (;;) {
		{
			$var($ConcurrentLinkedQueue$Node, p, this->head);
			$var($ConcurrentLinkedQueue$Node, pred, nullptr);
			for (; p != nullptr;) {
				$var($ConcurrentLinkedQueue$Node, q, p->next);
				$var($Object, item, nullptr);
				if (($assign(item, p->item)) != nullptr) {
					bool var$0 = $nc($of(o))->equals(item);
					if (var$0 && p->casItem(item, nullptr)) {
						skipDeadNodes(pred, p, p, q);
						return true;
					}
					$assign(pred, p);
					$assign(p, q);
					continue;
				}
				{
					$var($ConcurrentLinkedQueue$Node, c, p);
					for (;; $assign(q, p->next)) {
						if (q == nullptr || $nc(q)->item != nullptr) {
							$assign(pred, skipDeadNodes(pred, c, p, q));
							$assign(p, q);
							break;
						}
						$var($ConcurrentLinkedQueue$Node, var$1, p);
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

bool ConcurrentLinkedQueue::addAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	if ($equals(c, this)) {
		$throwNew($IllegalArgumentException);
	}
	$var($ConcurrentLinkedQueue$Node, beginningOfTheEnd, nullptr);
	$var($ConcurrentLinkedQueue$Node, last, nullptr);
	{
		$var($Iterator, i$, $nc(c)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			{
				$var($ConcurrentLinkedQueue$Node, newNode, $new($ConcurrentLinkedQueue$Node, $Objects::requireNonNull(e)));
				if (beginningOfTheEnd == nullptr) {
					$assign(beginningOfTheEnd, ($assign(last, newNode)));
				} else {
					$nc(last)->appendRelaxed($assign(last, newNode));
				}
			}
		}
	}
	if (beginningOfTheEnd == nullptr) {
		return false;
	}
	{
		$var($ConcurrentLinkedQueue$Node, t, this->tail);
		$var($ConcurrentLinkedQueue$Node, p, t);
		for (;;) {
			$var($ConcurrentLinkedQueue$Node, q, $nc(p)->next);
			if (q == nullptr) {
				if ($nc(ConcurrentLinkedQueue::NEXT)->compareAndSet($$new($ObjectArray, {$of(p), ($Object*)nullptr, $of(beginningOfTheEnd)}))) {
					if (!$nc(ConcurrentLinkedQueue::TAIL)->weakCompareAndSet($$new($ObjectArray, {$of(this), $of(t), $of(last)}))) {
						$assign(t, this->tail);
						if ($nc(last)->next == nullptr) {
							$nc(ConcurrentLinkedQueue::TAIL)->weakCompareAndSet($$new($ObjectArray, {$of(this), $of(t), $of(last)}));
						}
					}
					return true;
				}
			} else if (p == q) {
				$var($ConcurrentLinkedQueue$Node, var$0, t);
				$assign(p, (var$0 != ($assign(t, this->tail))) ? t : $cast($ConcurrentLinkedQueue$Node, this->head));
			} else {
				bool var$1 = p != t;
				if (var$1) {
					$var($ConcurrentLinkedQueue$Node, var$2, t);
					var$1 = var$2 != ($assign(t, this->tail));
				}
				$assign(p, (var$1) ? t : q);
			}
		}
	}
}

$String* ConcurrentLinkedQueue::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, a, nullptr);
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t charLength = 0;
		int32_t size = 0;
		{
			$var($ConcurrentLinkedQueue$Node, p, first());
			for (; p != nullptr;) {
				$var($Object, item, nullptr);
				if (($assign(item, p->item)) != nullptr) {
					if (a == nullptr) {
						$assign(a, $new($StringArray, 4));
					} else if (size == $nc(a)->length) {
						$assign(a, $fcast($StringArray, $Arrays::copyOf(a, 2 * size)));
					}
					$var($String, s, $nc($of(item))->toString());
					$nc(a)->set(size++, s);
					charLength += $nc(s)->length();
				}
				$var($ConcurrentLinkedQueue$Node, var$0, p);
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

$ObjectArray* ConcurrentLinkedQueue::toArrayInternal($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, x, a);
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t size = 0;
		{
			$var($ConcurrentLinkedQueue$Node, p, first());
			for (; p != nullptr;) {
				$var($Object, item, nullptr);
				if (($assign(item, p->item)) != nullptr) {
					if (x == nullptr) {
						$assign(x, $new($ObjectArray, 4));
					} else if (size == $nc(x)->length) {
						$assign(x, $Arrays::copyOf(x, 2 * (size + 4)));
					}
					$nc(x)->set(size++, item);
				}
				$var($ConcurrentLinkedQueue$Node, var$0, p);
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

$ObjectArray* ConcurrentLinkedQueue::toArray() {
	return toArrayInternal(nullptr);
}

$ObjectArray* ConcurrentLinkedQueue::toArray($ObjectArray* a) {
	$Objects::requireNonNull(a);
	return toArrayInternal(a);
}

$Iterator* ConcurrentLinkedQueue::iterator() {
	return $new($ConcurrentLinkedQueue$Itr, this);
}

void ConcurrentLinkedQueue::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	{
		$var($ConcurrentLinkedQueue$Node, p, first());
		for (; p != nullptr; $assign(p, succ(p))) {
			$var($Object, item, nullptr);
			if (($assign(item, $nc(p)->item)) != nullptr) {
				s->writeObject(item);
			}
		}
	}
	s->writeObject(nullptr);
}

void ConcurrentLinkedQueue::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	$var($ConcurrentLinkedQueue$Node, h, nullptr);
	$var($ConcurrentLinkedQueue$Node, t, nullptr);
	{
		$var($Object, item, nullptr);
		for (; ($assign(item, s->readObject())) != nullptr;) {
			$var($ConcurrentLinkedQueue$Node, newNode, $new($ConcurrentLinkedQueue$Node, item));
			if (h == nullptr) {
				$assign(h, ($assign(t, newNode)));
			} else {
				$nc(t)->appendRelaxed($assign(t, newNode));
			}
		}
	}
	if (h == nullptr) {
		$assign(h, ($assign(t, $new($ConcurrentLinkedQueue$Node))));
	}
	$set(this, head, h);
	$set(this, tail, t);
}

$Spliterator* ConcurrentLinkedQueue::spliterator() {
	return $new($ConcurrentLinkedQueue$CLQSpliterator, this);
}

bool ConcurrentLinkedQueue::removeIf($Predicate* filter) {
	$Objects::requireNonNull(filter);
	return bulkRemove(filter);
}

bool ConcurrentLinkedQueue::removeAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0, c)));
}

bool ConcurrentLinkedQueue::retainAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1, c)));
}

void ConcurrentLinkedQueue::clear() {
	bulkRemove(static_cast<$Predicate*>($$new(ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2)));
}

bool ConcurrentLinkedQueue::bulkRemove($Predicate* filter) {
	$useLocalCurrentObjectStackCache();
	bool removed = false;
	bool restartFromHead$continue = false;
	for (;;) {
		int32_t hops = ConcurrentLinkedQueue::MAX_HOPS;
		{
			$var($ConcurrentLinkedQueue$Node, p, this->head);
			$var($ConcurrentLinkedQueue$Node, c, p);
			$var($ConcurrentLinkedQueue$Node, pred, nullptr);
			$var($ConcurrentLinkedQueue$Node, q, nullptr);
			for (; p != nullptr; $assign(p, q)) {
				$assign(q, $nc(p)->next);
				$var($Object, item, nullptr);
				bool pAlive = false;
				if (pAlive = (($assign(item, p->item)) != nullptr)) {
					if ($nc(filter)->test(item)) {
						if (p->casItem(item, nullptr)) {
							removed = true;
						}
						pAlive = false;
					}
				}
				if (pAlive || q == nullptr || --hops == 0) {
					bool var$0 = c != p;
					if (var$0) {
						$var($ConcurrentLinkedQueue$Node, var$1, pred);
						$var($ConcurrentLinkedQueue$Node, var$2, c);
						var$0 = !tryCasSuccessor(var$1, var$2, $assign(c, p));
					}
					if ((var$0) || pAlive) {
						hops = ConcurrentLinkedQueue::MAX_HOPS;
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

void ConcurrentLinkedQueue::forEachFrom($Consumer* action, $ConcurrentLinkedQueue$Node* p$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentLinkedQueue$Node, p, p$renamed);
	{
		$var($ConcurrentLinkedQueue$Node, pred, nullptr);
		for (; p != nullptr;) {
			$var($ConcurrentLinkedQueue$Node, q, p->next);
			$var($Object, item, nullptr);
			if (($assign(item, p->item)) != nullptr) {
				$nc(action)->accept(item);
				$assign(pred, p);
				$assign(p, q);
				continue;
			}
			{
				$var($ConcurrentLinkedQueue$Node, c, p);
				for (;; $assign(q, p->next)) {
					if (q == nullptr || $nc(q)->item != nullptr) {
						$assign(pred, skipDeadNodes(pred, c, p, q));
						$assign(p, q);
						break;
					}
					$var($ConcurrentLinkedQueue$Node, var$0, p);
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

void ConcurrentLinkedQueue::forEach($Consumer* action) {
	$Objects::requireNonNull(action);
	forEachFrom(action, this->head);
}

bool ConcurrentLinkedQueue::lambda$clear$2(Object$* e) {
	$init(ConcurrentLinkedQueue);
	return true;
}

bool ConcurrentLinkedQueue::lambda$retainAll$1($Collection* c, Object$* e) {
	$init(ConcurrentLinkedQueue);
	return !$nc(c)->contains(e);
}

bool ConcurrentLinkedQueue::lambda$removeAll$0($Collection* c, Object$* e) {
	$init(ConcurrentLinkedQueue);
	return $nc(c)->contains(e);
}

void clinit$ConcurrentLinkedQueue($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$load($ConcurrentLinkedQueue$Node);
			$assignStatic(ConcurrentLinkedQueue::HEAD, $nc(l)->findVarHandle(ConcurrentLinkedQueue::class$, "head"_s, $ConcurrentLinkedQueue$Node::class$));
			$assignStatic(ConcurrentLinkedQueue::TAIL, l->findVarHandle(ConcurrentLinkedQueue::class$, "tail"_s, $ConcurrentLinkedQueue$Node::class$));
			$assignStatic(ConcurrentLinkedQueue::ITEM, l->findVarHandle($ConcurrentLinkedQueue$Node::class$, "item"_s, $Object::class$));
			$assignStatic(ConcurrentLinkedQueue::NEXT, l->findVarHandle($ConcurrentLinkedQueue$Node::class$, "next"_s, $ConcurrentLinkedQueue$Node::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

ConcurrentLinkedQueue::ConcurrentLinkedQueue() {
}

$Class* ConcurrentLinkedQueue::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::classInfo$.name)) {
			return ConcurrentLinkedQueue$$Lambda$lambda$removeAll$0::load$(name, initialize);
		}
		if (name->equals(ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::classInfo$.name)) {
			return ConcurrentLinkedQueue$$Lambda$lambda$retainAll$1$1::load$(name, initialize);
		}
		if (name->equals(ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2::classInfo$.name)) {
			return ConcurrentLinkedQueue$$Lambda$lambda$clear$2$2::load$(name, initialize);
		}
	}
	$loadClass(ConcurrentLinkedQueue, name, initialize, &_ConcurrentLinkedQueue_ClassInfo_, clinit$ConcurrentLinkedQueue, allocate$ConcurrentLinkedQueue);
	return class$;
}

$Class* ConcurrentLinkedQueue::class$ = nullptr;

		} // concurrent
	} // util
} // java