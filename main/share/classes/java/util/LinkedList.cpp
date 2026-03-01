#include <java/util/LinkedList.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/reflect/Array.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList$DescendingIterator.h>
#include <java/util/LinkedList$LLSpliterator.h>
#include <java/util/LinkedList$ListItr.h>
#include <java/util/LinkedList$Node.h>
#include <java/util/ListIterator.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $1Array = ::java::lang::reflect::Array;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $LinkedList$DescendingIterator = ::java::util::LinkedList$DescendingIterator;
using $LinkedList$LLSpliterator = ::java::util::LinkedList$LLSpliterator;
using $LinkedList$ListItr = ::java::util::LinkedList$ListItr;
using $LinkedList$Node = ::java::util::LinkedList$Node;
using $ListIterator = ::java::util::ListIterator;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {

$FieldInfo _LinkedList_FieldInfo_[] = {
	{"size", "I", nullptr, $TRANSIENT, $field(LinkedList, size$)},
	{"first", "Ljava/util/LinkedList$Node;", "Ljava/util/LinkedList$Node<TE;>;", $TRANSIENT, $field(LinkedList, first)},
	{"last", "Ljava/util/LinkedList$Node;", "Ljava/util/LinkedList$Node<TE;>;", $TRANSIENT, $field(LinkedList, last)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinkedList, serialVersionUID)},
	{}
};

$MethodInfo _LinkedList_MethodInfo_[] = {
	{"*containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(LinkedList, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(LinkedList, init$, void, $Collection*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedList, add, bool, Object$*)},
	{"add", "(ILjava/lang/Object;)V", "(ITE;)V", $PUBLIC, $virtualMethod(LinkedList, add, void, int32_t, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(LinkedList, addAll, bool, $Collection*)},
	{"addAll", "(ILjava/util/Collection;)Z", "(ILjava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(LinkedList, addAll, bool, int32_t, $Collection*)},
	{"addFirst", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(LinkedList, addFirst, void, Object$*)},
	{"addLast", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(LinkedList, addLast, void, Object$*)},
	{"checkElementIndex", "(I)V", nullptr, $PRIVATE, $method(LinkedList, checkElementIndex, void, int32_t)},
	{"checkPositionIndex", "(I)V", nullptr, $PRIVATE, $method(LinkedList, checkPositionIndex, void, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(LinkedList, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LinkedList, clone, $Object*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedList, contains, bool, Object$*)},
	{"descendingIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(LinkedList, descendingIterator, $Iterator*)},
	{"element", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, element, $Object*)},
	{"get", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC, $virtualMethod(LinkedList, get, $Object*, int32_t)},
	{"getFirst", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, getFirst, $Object*)},
	{"getLast", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, getLast, $Object*)},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(LinkedList, indexOf, int32_t, Object$*)},
	{"isElementIndex", "(I)Z", nullptr, $PRIVATE, $method(LinkedList, isElementIndex, bool, int32_t)},
	{"*isEmpty", "()Z", nullptr, $PUBLIC},
	{"isPositionIndex", "(I)Z", nullptr, $PRIVATE, $method(LinkedList, isPositionIndex, bool, int32_t)},
	{"*iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC},
	{"lastIndexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(LinkedList, lastIndexOf, int32_t, Object$*)},
	{"linkBefore", "(Ljava/lang/Object;Ljava/util/LinkedList$Node;)V", "(TE;Ljava/util/LinkedList$Node<TE;>;)V", 0, $virtualMethod(LinkedList, linkBefore, void, Object$*, $LinkedList$Node*)},
	{"linkFirst", "(Ljava/lang/Object;)V", "(TE;)V", $PRIVATE, $method(LinkedList, linkFirst, void, Object$*)},
	{"linkLast", "(Ljava/lang/Object;)V", "(TE;)V", 0, $virtualMethod(LinkedList, linkLast, void, Object$*)},
	{"listIterator", "(I)Ljava/util/ListIterator;", "(I)Ljava/util/ListIterator<TE;>;", $PUBLIC, $virtualMethod(LinkedList, listIterator, $ListIterator*, int32_t)},
	{"node", "(I)Ljava/util/LinkedList$Node;", "(I)Ljava/util/LinkedList$Node<TE;>;", 0, $virtualMethod(LinkedList, node, $LinkedList$Node*, int32_t)},
	{"offer", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedList, offer, bool, Object$*)},
	{"offerFirst", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedList, offerFirst, bool, Object$*)},
	{"offerLast", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(LinkedList, offerLast, bool, Object$*)},
	{"outOfBoundsMsg", "(I)Ljava/lang/String;", nullptr, $PRIVATE, $method(LinkedList, outOfBoundsMsg, $String*, int32_t)},
	{"*parallelStream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"peek", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, peek, $Object*)},
	{"peekFirst", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, peekFirst, $Object*)},
	{"peekLast", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, peekLast, $Object*)},
	{"poll", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, poll, $Object*)},
	{"pollFirst", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, pollFirst, $Object*)},
	{"pollLast", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, pollLast, $Object*)},
	{"pop", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, pop, $Object*)},
	{"push", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(LinkedList, push, void, Object$*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(LinkedList, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedList, remove, bool, Object$*)},
	{"remove", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC, $virtualMethod(LinkedList, remove, $Object*, int32_t)},
	{"remove", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, remove, $Object*)},
	{"*removeAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"removeFirst", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, removeFirst, $Object*)},
	{"removeFirstOccurrence", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedList, removeFirstOccurrence, bool, Object$*)},
	{"*removeIf", "(Ljava/util/function/Predicate;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"removeLast", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(LinkedList, removeLast, $Object*)},
	{"removeLastOccurrence", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LinkedList, removeLastOccurrence, bool, Object$*)},
	{"*retainAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"set", "(ILjava/lang/Object;)Ljava/lang/Object;", "(ITE;)TE;", $PUBLIC, $virtualMethod(LinkedList, set, $Object*, int32_t, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(LinkedList, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(LinkedList, spliterator, $Spliterator*)},
	{"*stream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"superClone", "()Ljava/util/LinkedList;", "()Ljava/util/LinkedList<TE;>;", $PRIVATE, $method(LinkedList, superClone, LinkedList*)},
	{"*toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LinkedList, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(LinkedList, toArray, $ObjectArray*, $ObjectArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unlink", "(Ljava/util/LinkedList$Node;)Ljava/lang/Object;", "(Ljava/util/LinkedList$Node<TE;>;)TE;", 0, $virtualMethod(LinkedList, unlink, $Object*, $LinkedList$Node*)},
	{"unlinkFirst", "(Ljava/util/LinkedList$Node;)Ljava/lang/Object;", "(Ljava/util/LinkedList$Node<TE;>;)TE;", $PRIVATE, $method(LinkedList, unlinkFirst, $Object*, $LinkedList$Node*)},
	{"unlinkLast", "(Ljava/util/LinkedList$Node;)Ljava/lang/Object;", "(Ljava/util/LinkedList$Node<TE;>;)TE;", $PRIVATE, $method(LinkedList, unlinkLast, $Object*, $LinkedList$Node*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(LinkedList, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _LinkedList_InnerClassesInfo_[] = {
	{"java.util.LinkedList$LLSpliterator", "java.util.LinkedList", "LLSpliterator", $STATIC | $FINAL},
	{"java.util.LinkedList$DescendingIterator", "java.util.LinkedList", "DescendingIterator", $PRIVATE},
	{"java.util.LinkedList$Node", "java.util.LinkedList", "Node", $PRIVATE | $STATIC},
	{"java.util.LinkedList$ListItr", "java.util.LinkedList", "ListItr", $PRIVATE},
	{}
};

$ClassInfo _LinkedList_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.LinkedList",
	"java.util.AbstractSequentialList",
	"java.util.Deque,java.lang.Cloneable,java.io.Serializable",
	_LinkedList_FieldInfo_,
	_LinkedList_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractSequentialList<TE;>;Ljava/util/List<TE;>;Ljava/util/Deque<TE;>;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_LinkedList_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.LinkedList$LLSpliterator,java.util.LinkedList$DescendingIterator,java.util.LinkedList$Node,java.util.LinkedList$ListItr"
};

$Object* allocate$LinkedList($Class* clazz) {
	return $of($alloc(LinkedList));
}

$Iterator* LinkedList::iterator() {
	 return this->$AbstractSequentialList::iterator();
}

bool LinkedList::equals(Object$* o) {
	 return this->$AbstractSequentialList::equals(o);
}

int32_t LinkedList::hashCode() {
	 return this->$AbstractSequentialList::hashCode();
}

bool LinkedList::isEmpty() {
	 return this->$AbstractSequentialList::isEmpty();
}

bool LinkedList::containsAll($Collection* c) {
	 return this->$AbstractSequentialList::containsAll(c);
}

bool LinkedList::removeAll($Collection* c) {
	 return this->$AbstractSequentialList::removeAll(c);
}

bool LinkedList::retainAll($Collection* c) {
	 return this->$AbstractSequentialList::retainAll(c);
}

$String* LinkedList::toString() {
	 return this->$AbstractSequentialList::toString();
}

$ObjectArray* LinkedList::toArray($IntFunction* generator) {
	 return this->$AbstractSequentialList::toArray(generator);
}

bool LinkedList::removeIf($Predicate* filter) {
	 return this->$AbstractSequentialList::removeIf(filter);
}

$Stream* LinkedList::stream() {
	 return this->$AbstractSequentialList::stream();
}

$Stream* LinkedList::parallelStream() {
	 return this->$AbstractSequentialList::parallelStream();
}

void LinkedList::forEach($Consumer* action) {
	this->$AbstractSequentialList::forEach(action);
}

void LinkedList::finalize() {
	this->$AbstractSequentialList::finalize();
}

void LinkedList::init$() {
	$AbstractSequentialList::init$();
	this->size$ = 0;
}

void LinkedList::init$($Collection* c) {
	LinkedList::init$();
	addAll(c);
}

void LinkedList::linkFirst(Object$* e) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList$Node, f, this->first);
	$var($LinkedList$Node, newNode, $new($LinkedList$Node, nullptr, e, f));
	$set(this, first, newNode);
	if (f == nullptr) {
		$set(this, last, newNode);
	} else {
		$set($nc(f), prev, newNode);
	}
	++this->size$;
	++this->modCount;
}

void LinkedList::linkLast(Object$* e) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList$Node, l, this->last);
	$var($LinkedList$Node, newNode, $new($LinkedList$Node, l, e, nullptr));
	$set(this, last, newNode);
	if (l == nullptr) {
		$set(this, first, newNode);
	} else {
		$set($nc(l), next, newNode);
	}
	++this->size$;
	++this->modCount;
}

void LinkedList::linkBefore(Object$* e, $LinkedList$Node* succ) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList$Node, pred, $nc(succ)->prev);
	$var($LinkedList$Node, newNode, $new($LinkedList$Node, pred, e, succ));
	$set(succ, prev, newNode);
	if (pred == nullptr) {
		$set(this, first, newNode);
	} else {
		$set($nc(pred), next, newNode);
	}
	++this->size$;
	++this->modCount;
}

$Object* LinkedList::unlinkFirst($LinkedList$Node* f) {
	$useLocalCurrentObjectStackCache();
	$var($Object, element, $nc(f)->item);
	$var($LinkedList$Node, next, f->next);
	$set(f, item, nullptr);
	$set(f, next, nullptr);
	$set(this, first, next);
	if (next == nullptr) {
		$set(this, last, nullptr);
	} else {
		$set($nc(next), prev, nullptr);
	}
	--this->size$;
	++this->modCount;
	return $of(element);
}

$Object* LinkedList::unlinkLast($LinkedList$Node* l) {
	$useLocalCurrentObjectStackCache();
	$var($Object, element, $nc(l)->item);
	$var($LinkedList$Node, prev, l->prev);
	$set(l, item, nullptr);
	$set(l, prev, nullptr);
	$set(this, last, prev);
	if (prev == nullptr) {
		$set(this, first, nullptr);
	} else {
		$set($nc(prev), next, nullptr);
	}
	--this->size$;
	++this->modCount;
	return $of(element);
}

$Object* LinkedList::unlink($LinkedList$Node* x) {
	$useLocalCurrentObjectStackCache();
	$var($Object, element, $nc(x)->item);
	$var($LinkedList$Node, next, x->next);
	$var($LinkedList$Node, prev, x->prev);
	if (prev == nullptr) {
		$set(this, first, next);
	} else {
		$set($nc(prev), next, next);
		$set(x, prev, nullptr);
	}
	if (next == nullptr) {
		$set(this, last, prev);
	} else {
		$set($nc(next), prev, prev);
		$set(x, next, nullptr);
	}
	$set(x, item, nullptr);
	--this->size$;
	++this->modCount;
	return $of(element);
}

$Object* LinkedList::getFirst() {
	$var($LinkedList$Node, f, this->first);
	if (f == nullptr) {
		$throwNew($NoSuchElementException);
	}
	return $of($nc(f)->item);
}

$Object* LinkedList::getLast() {
	$var($LinkedList$Node, l, this->last);
	if (l == nullptr) {
		$throwNew($NoSuchElementException);
	}
	return $of($nc(l)->item);
}

$Object* LinkedList::removeFirst() {
	$var($LinkedList$Node, f, this->first);
	if (f == nullptr) {
		$throwNew($NoSuchElementException);
	}
	return $of(unlinkFirst(f));
}

$Object* LinkedList::removeLast() {
	$var($LinkedList$Node, l, this->last);
	if (l == nullptr) {
		$throwNew($NoSuchElementException);
	}
	return $of(unlinkLast(l));
}

void LinkedList::addFirst(Object$* e) {
	linkFirst(e);
}

void LinkedList::addLast(Object$* e) {
	linkLast(e);
}

bool LinkedList::contains(Object$* o) {
	return indexOf(o) >= 0;
}

int32_t LinkedList::size() {
	return this->size$;
}

bool LinkedList::add(Object$* e) {
	linkLast(e);
	return true;
}

bool LinkedList::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (o == nullptr) {
		{
			$var($LinkedList$Node, x, this->first);
			for (; x != nullptr; $assign(x, $nc(x)->next)) {
				if (x->item == nullptr) {
					unlink(x);
					return true;
				}
			}
		}
	} else {
		{
			$var($LinkedList$Node, x, this->first);
			for (; x != nullptr; $assign(x, $nc(x)->next)) {
				if ($nc($of(o))->equals(x->item)) {
					unlink(x);
					return true;
				}
			}
		}
	}
	return false;
}

bool LinkedList::addAll($Collection* c) {
	return addAll(this->size$, c);
}

bool LinkedList::addAll(int32_t index, $Collection* c) {
	$useLocalCurrentObjectStackCache();
	checkPositionIndex(index);
	$var($ObjectArray, a, $nc(c)->toArray());
	int32_t numNew = $nc(a)->length;
	if (numNew == 0) {
		return false;
	}
	$var($LinkedList$Node, pred, nullptr);
	$var($LinkedList$Node, succ, nullptr);
	if (index == this->size$) {
		$assign(succ, nullptr);
		$assign(pred, this->last);
	} else {
		$assign(succ, node(index));
		$assign(pred, $nc(succ)->prev);
	}
	{
		$var($ObjectArray, arr$, a);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, o, arr$->get(i$));
			{
				$var($Object, e, o);
				$var($LinkedList$Node, newNode, $new($LinkedList$Node, pred, e, nullptr));
				if (pred == nullptr) {
					$set(this, first, newNode);
				} else {
					$set($nc(pred), next, newNode);
				}
				$assign(pred, newNode);
			}
		}
	}
	if (succ == nullptr) {
		$set(this, last, pred);
	} else {
		$set($nc(pred), next, succ);
		$set($nc(succ), prev, pred);
	}
	this->size$ += numNew;
	++this->modCount;
	return true;
}

void LinkedList::clear() {
	$useLocalCurrentObjectStackCache();
	{
		$var($LinkedList$Node, x, this->first);
		for (; x != nullptr;) {
			$var($LinkedList$Node, next, x->next);
			$set(x, item, nullptr);
			$set(x, next, nullptr);
			$set(x, prev, nullptr);
			$assign(x, next);
		}
	}
	$set(this, first, ($set(this, last, nullptr)));
	this->size$ = 0;
	++this->modCount;
}

$Object* LinkedList::get(int32_t index) {
	checkElementIndex(index);
	return $of($nc($(node(index)))->item);
}

$Object* LinkedList::set(int32_t index, Object$* element) {
	$useLocalCurrentObjectStackCache();
	checkElementIndex(index);
	$var($LinkedList$Node, x, node(index));
	$var($Object, oldVal, $nc(x)->item);
	$set(x, item, element);
	return $of(oldVal);
}

void LinkedList::add(int32_t index, Object$* element) {
	checkPositionIndex(index);
	if (index == this->size$) {
		linkLast(element);
	} else {
		linkBefore(element, $(node(index)));
	}
}

$Object* LinkedList::remove(int32_t index) {
	checkElementIndex(index);
	return $of(unlink($(node(index))));
}

bool LinkedList::isElementIndex(int32_t index) {
	return index >= 0 && index < this->size$;
}

bool LinkedList::isPositionIndex(int32_t index) {
	return index >= 0 && index <= this->size$;
}

$String* LinkedList::outOfBoundsMsg(int32_t index) {
	$useLocalCurrentObjectStackCache();
	return $str({"Index: "_s, $$str(index), ", Size: "_s, $$str(this->size$)});
}

void LinkedList::checkElementIndex(int32_t index) {
	if (!isElementIndex(index)) {
		$throwNew($IndexOutOfBoundsException, $(outOfBoundsMsg(index)));
	}
}

void LinkedList::checkPositionIndex(int32_t index) {
	if (!isPositionIndex(index)) {
		$throwNew($IndexOutOfBoundsException, $(outOfBoundsMsg(index)));
	}
}

$LinkedList$Node* LinkedList::node(int32_t index) {
	$useLocalCurrentObjectStackCache();
	if (index < (this->size$ >> 1)) {
		$var($LinkedList$Node, x, this->first);
		for (int32_t i = 0; i < index; ++i) {
			$assign(x, $nc(x)->next);
		}
		return x;
	} else {
		$var($LinkedList$Node, x, this->last);
		for (int32_t i = this->size$ - 1; i > index; --i) {
			$assign(x, $nc(x)->prev);
		}
		return x;
	}
}

int32_t LinkedList::indexOf(Object$* o) {
	$useLocalCurrentObjectStackCache();
	int32_t index = 0;
	if (o == nullptr) {
		{
			$var($LinkedList$Node, x, this->first);
			for (; x != nullptr; $assign(x, $nc(x)->next)) {
				if (x->item == nullptr) {
					return index;
				}
				++index;
			}
		}
	} else {
		{
			$var($LinkedList$Node, x, this->first);
			for (; x != nullptr; $assign(x, $nc(x)->next)) {
				if ($nc($of(o))->equals(x->item)) {
					return index;
				}
				++index;
			}
		}
	}
	return -1;
}

int32_t LinkedList::lastIndexOf(Object$* o) {
	$useLocalCurrentObjectStackCache();
	int32_t index = this->size$;
	if (o == nullptr) {
		{
			$var($LinkedList$Node, x, this->last);
			for (; x != nullptr; $assign(x, $nc(x)->prev)) {
				--index;
				if (x->item == nullptr) {
					return index;
				}
			}
		}
	} else {
		{
			$var($LinkedList$Node, x, this->last);
			for (; x != nullptr; $assign(x, $nc(x)->prev)) {
				--index;
				if ($nc($of(o))->equals(x->item)) {
					return index;
				}
			}
		}
	}
	return -1;
}

$Object* LinkedList::peek() {
	$var($LinkedList$Node, f, this->first);
	return $of((f == nullptr) ? ($Object*)nullptr : $nc(f)->item);
}

$Object* LinkedList::element() {
	return $of(getFirst());
}

$Object* LinkedList::poll() {
	$var($LinkedList$Node, f, this->first);
	return $of((f == nullptr) ? ($Object*)nullptr : unlinkFirst(f));
}

$Object* LinkedList::remove() {
	return $of(removeFirst());
}

bool LinkedList::offer(Object$* e) {
	return add(e);
}

bool LinkedList::offerFirst(Object$* e) {
	addFirst(e);
	return true;
}

bool LinkedList::offerLast(Object$* e) {
	addLast(e);
	return true;
}

$Object* LinkedList::peekFirst() {
	$var($LinkedList$Node, f, this->first);
	return $of((f == nullptr) ? ($Object*)nullptr : $nc(f)->item);
}

$Object* LinkedList::peekLast() {
	$var($LinkedList$Node, l, this->last);
	return $of((l == nullptr) ? ($Object*)nullptr : $nc(l)->item);
}

$Object* LinkedList::pollFirst() {
	$var($LinkedList$Node, f, this->first);
	return $of((f == nullptr) ? ($Object*)nullptr : unlinkFirst(f));
}

$Object* LinkedList::pollLast() {
	$var($LinkedList$Node, l, this->last);
	return $of((l == nullptr) ? ($Object*)nullptr : unlinkLast(l));
}

void LinkedList::push(Object$* e) {
	addFirst(e);
}

$Object* LinkedList::pop() {
	return $of(removeFirst());
}

bool LinkedList::removeFirstOccurrence(Object$* o) {
	return remove(o);
}

bool LinkedList::removeLastOccurrence(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (o == nullptr) {
		{
			$var($LinkedList$Node, x, this->last);
			for (; x != nullptr; $assign(x, $nc(x)->prev)) {
				if (x->item == nullptr) {
					unlink(x);
					return true;
				}
			}
		}
	} else {
		{
			$var($LinkedList$Node, x, this->last);
			for (; x != nullptr; $assign(x, $nc(x)->prev)) {
				if ($nc($of(o))->equals(x->item)) {
					unlink(x);
					return true;
				}
			}
		}
	}
	return false;
}

$ListIterator* LinkedList::listIterator(int32_t index) {
	checkPositionIndex(index);
	return $new($LinkedList$ListItr, this, index);
}

$Iterator* LinkedList::descendingIterator() {
	return $new($LinkedList$DescendingIterator, this);
}

LinkedList* LinkedList::superClone() {
	try {
		return $cast(LinkedList, $AbstractSequentialList::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$Object* LinkedList::clone() {
	$useLocalCurrentObjectStackCache();
	$var(LinkedList, clone, superClone());
	$set($nc(clone), first, ($set(clone, last, nullptr)));
	clone->size$ = 0;
	clone->modCount = 0;
	{
		$var($LinkedList$Node, x, this->first);
		for (; x != nullptr; $assign(x, $nc(x)->next)) {
			clone->add(x->item);
		}
	}
	return $of(clone);
}

$ObjectArray* LinkedList::toArray() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, result, $new($ObjectArray, this->size$));
	int32_t i = 0;
	{
		$var($LinkedList$Node, x, this->first);
		for (; x != nullptr; $assign(x, $nc(x)->next)) {
			result->set(i++, x->item);
		}
	}
	return result;
}

$ObjectArray* LinkedList::toArray($ObjectArray* a$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, a$renamed);
	if ($nc(a)->length < this->size$) {
		$assign(a, $cast($ObjectArray, $1Array::newInstance($of(a)->getClass()->getComponentType(), this->size$)));
	}
	int32_t i = 0;
	$var($ObjectArray, result, a);
	{
		$var($LinkedList$Node, x, this->first);
		for (; x != nullptr; $assign(x, $nc(x)->next)) {
			$nc(result)->set(i++, x->item);
		}
	}
	if ($nc(a)->length > this->size$) {
		a->set(this->size$, nullptr);
	}
	return a;
}

void LinkedList::writeObject($ObjectOutputStream* s) {
	$nc(s)->defaultWriteObject();
	s->writeInt(this->size$);
	{
		$var($LinkedList$Node, x, this->first);
		for (; x != nullptr; $assign(x, $nc(x)->next)) {
			s->writeObject(x->item);
		}
	}
}

void LinkedList::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	int32_t size = s->readInt();
	for (int32_t i = 0; i < size; ++i) {
		linkLast($(s->readObject()));
	}
}

$Spliterator* LinkedList::spliterator() {
	return $new($LinkedList$LLSpliterator, this, -1, 0);
}

LinkedList::LinkedList() {
}

$Class* LinkedList::load$($String* name, bool initialize) {
	$loadClass(LinkedList, name, initialize, &_LinkedList_ClassInfo_, allocate$LinkedList);
	return class$;
}

$Class* LinkedList::class$ = nullptr;

	} // util
} // java