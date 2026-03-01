#include <java/util/ArrayList.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList$ArrayListSpliterator.h>
#include <java/util/ArrayList$Itr.h>
#include <java/util/ArrayList$ListItr.h>
#include <java/util/ArrayList$SubList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/UnaryOperator.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/util/ArraysSupport.h>
#include <jcpp.h>

#undef DEFAULTCAPACITY_EMPTY_ELEMENTDATA
#undef DEFAULT_CAPACITY
#undef EMPTY_ELEMENTDATA

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList$ArrayListSpliterator = ::java::util::ArrayList$ArrayListSpliterator;
using $ArrayList$Itr = ::java::util::ArrayList$Itr;
using $ArrayList$ListItr = ::java::util::ArrayList$ListItr;
using $ArrayList$SubList = ::java::util::ArrayList$SubList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $UnaryOperator = ::java::util::function::UnaryOperator;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ArraysSupport = ::jdk::internal::util::ArraysSupport;

namespace java {
	namespace util {

$FieldInfo _ArrayList_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ArrayList, serialVersionUID)},
	{"DEFAULT_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ArrayList, DEFAULT_CAPACITY)},
	{"EMPTY_ELEMENTDATA", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ArrayList, EMPTY_ELEMENTDATA)},
	{"DEFAULTCAPACITY_EMPTY_ELEMENTDATA", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ArrayList, DEFAULTCAPACITY_EMPTY_ELEMENTDATA)},
	{"elementData", "[Ljava/lang/Object;", nullptr, $TRANSIENT, $field(ArrayList, elementData$)},
	{"size", "I", nullptr, $PRIVATE, $field(ArrayList, size$)},
	{}
};

$MethodInfo _ArrayList_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(ArrayList, init$, void, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(ArrayList, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(ArrayList, init$, void, $Collection*)},
	{"add", "(Ljava/lang/Object;[Ljava/lang/Object;I)V", "(TE;[Ljava/lang/Object;I)V", $PRIVATE, $method(ArrayList, add, void, Object$*, $ObjectArray*, int32_t)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(ArrayList, add, bool, Object$*)},
	{"add", "(ILjava/lang/Object;)V", "(ITE;)V", $PUBLIC, $virtualMethod(ArrayList, add, void, int32_t, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(ArrayList, addAll, bool, $Collection*)},
	{"addAll", "(ILjava/util/Collection;)Z", "(ILjava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(ArrayList, addAll, bool, int32_t, $Collection*)},
	{"batchRemove", "(Ljava/util/Collection;ZII)Z", "(Ljava/util/Collection<*>;ZII)Z", 0, $virtualMethod(ArrayList, batchRemove, bool, $Collection*, bool, int32_t, int32_t)},
	{"checkForComodification", "(I)V", nullptr, $PRIVATE, $method(ArrayList, checkForComodification, void, int32_t)},
	{"checkInvariants", "()V", nullptr, 0, $virtualMethod(ArrayList, checkInvariants, void)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ArrayList, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ArrayList, clone, $Object*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ArrayList, contains, bool, Object$*)},
	{"elementAt", "([Ljava/lang/Object;I)Ljava/lang/Object;", "<E:Ljava/lang/Object;>([Ljava/lang/Object;I)TE;", $STATIC, $staticMethod(ArrayList, elementAt, $Object*, $ObjectArray*, int32_t)},
	{"elementData", "(I)Ljava/lang/Object;", "(I)TE;", 0, $virtualMethod(ArrayList, elementData, $Object*, int32_t)},
	{"ensureCapacity", "(I)V", nullptr, $PUBLIC, $virtualMethod(ArrayList, ensureCapacity, void, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ArrayList, equals, bool, Object$*)},
	{"equalsArrayList", "(Ljava/util/ArrayList;)Z", "(Ljava/util/ArrayList<*>;)Z", $PRIVATE, $method(ArrayList, equalsArrayList, bool, ArrayList*)},
	{"equalsRange", "(Ljava/util/List;II)Z", "(Ljava/util/List<*>;II)Z", 0, $virtualMethod(ArrayList, equalsRange, bool, $List*, int32_t, int32_t)},
	{"fastRemove", "([Ljava/lang/Object;I)V", nullptr, $PRIVATE, $method(ArrayList, fastRemove, void, $ObjectArray*, int32_t)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(ArrayList, forEach, void, $Consumer*)},
	{"get", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC, $virtualMethod(ArrayList, get, $Object*, int32_t)},
	{"grow", "(I)[Ljava/lang/Object;", nullptr, $PRIVATE, $method(ArrayList, grow, $ObjectArray*, int32_t)},
	{"grow", "()[Ljava/lang/Object;", nullptr, $PRIVATE, $method(ArrayList, grow, $ObjectArray*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ArrayList, hashCode, int32_t)},
	{"hashCodeRange", "(II)I", nullptr, 0, $virtualMethod(ArrayList, hashCodeRange, int32_t, int32_t, int32_t)},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(ArrayList, indexOf, int32_t, Object$*)},
	{"indexOfRange", "(Ljava/lang/Object;II)I", nullptr, 0, $virtualMethod(ArrayList, indexOfRange, int32_t, Object$*, int32_t, int32_t)},
	{"isClear", "([JI)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ArrayList, isClear, bool, $longs*, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ArrayList, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(ArrayList, iterator, $Iterator*)},
	{"lastIndexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(ArrayList, lastIndexOf, int32_t, Object$*)},
	{"lastIndexOfRange", "(Ljava/lang/Object;II)I", nullptr, 0, $virtualMethod(ArrayList, lastIndexOfRange, int32_t, Object$*, int32_t, int32_t)},
	{"listIterator", "(I)Ljava/util/ListIterator;", "(I)Ljava/util/ListIterator<TE;>;", $PUBLIC, $virtualMethod(ArrayList, listIterator, $ListIterator*, int32_t)},
	{"listIterator", "()Ljava/util/ListIterator;", "()Ljava/util/ListIterator<TE;>;", $PUBLIC, $virtualMethod(ArrayList, listIterator, $ListIterator*)},
	{"nBits", "(I)[J", nullptr, $PRIVATE | $STATIC, $staticMethod(ArrayList, nBits, $longs*, int32_t)},
	{"outOfBoundsMsg", "(I)Ljava/lang/String;", nullptr, $PRIVATE, $method(ArrayList, outOfBoundsMsg, $String*, int32_t)},
	{"outOfBoundsMsg", "(II)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ArrayList, outOfBoundsMsg, $String*, int32_t, int32_t)},
	{"rangeCheckForAdd", "(I)V", nullptr, $PRIVATE, $method(ArrayList, rangeCheckForAdd, void, int32_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ArrayList, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC, $virtualMethod(ArrayList, remove, $Object*, int32_t)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ArrayList, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(ArrayList, removeAll, bool, $Collection*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(ArrayList, removeIf, bool, $Predicate*)},
	{"removeIf", "(Ljava/util/function/Predicate;II)Z", "(Ljava/util/function/Predicate<-TE;>;II)Z", 0, $virtualMethod(ArrayList, removeIf, bool, $Predicate*, int32_t, int32_t)},
	{"removeRange", "(II)V", nullptr, $PROTECTED, $virtualMethod(ArrayList, removeRange, void, int32_t, int32_t)},
	{"replaceAll", "(Ljava/util/function/UnaryOperator;)V", "(Ljava/util/function/UnaryOperator<TE;>;)V", $PUBLIC, $virtualMethod(ArrayList, replaceAll, void, $UnaryOperator*)},
	{"replaceAllRange", "(Ljava/util/function/UnaryOperator;II)V", "(Ljava/util/function/UnaryOperator<TE;>;II)V", $PRIVATE, $method(ArrayList, replaceAllRange, void, $UnaryOperator*, int32_t, int32_t)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(ArrayList, retainAll, bool, $Collection*)},
	{"set", "(ILjava/lang/Object;)Ljava/lang/Object;", "(ITE;)TE;", $PUBLIC, $virtualMethod(ArrayList, set, $Object*, int32_t, Object$*)},
	{"setBit", "([JI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ArrayList, setBit, void, $longs*, int32_t)},
	{"shiftTailOverGap", "([Ljava/lang/Object;II)V", nullptr, $PRIVATE, $method(ArrayList, shiftTailOverGap, void, $ObjectArray*, int32_t, int32_t)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ArrayList, size, int32_t)},
	{"sort", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC, $virtualMethod(ArrayList, sort, void, $Comparator*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(ArrayList, spliterator, $Spliterator*)},
	{"subList", "(II)Ljava/util/List;", "(II)Ljava/util/List<TE;>;", $PUBLIC, $virtualMethod(ArrayList, subList, $List*, int32_t, int32_t)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ArrayList, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(ArrayList, toArray, $ObjectArray*, $ObjectArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"trimToSize", "()V", nullptr, $PUBLIC, $virtualMethod(ArrayList, trimToSize, void)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(ArrayList, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ArrayList_InnerClassesInfo_[] = {
	{"java.util.ArrayList$ArrayListSpliterator", "java.util.ArrayList", "ArrayListSpliterator", $FINAL},
	{"java.util.ArrayList$SubList", "java.util.ArrayList", "SubList", $PRIVATE | $STATIC},
	{"java.util.ArrayList$ListItr", "java.util.ArrayList", "ListItr", $PRIVATE},
	{"java.util.ArrayList$Itr", "java.util.ArrayList", "Itr", $PRIVATE},
	{}
};

$ClassInfo _ArrayList_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.ArrayList",
	"java.util.AbstractList",
	"java.util.RandomAccess,java.lang.Cloneable,java.io.Serializable",
	_ArrayList_FieldInfo_,
	_ArrayList_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractList<TE;>;Ljava/util/List<TE;>;Ljava/util/RandomAccess;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_ArrayList_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.ArrayList$ArrayListSpliterator,java.util.ArrayList$SubList,java.util.ArrayList$SubList$2,java.util.ArrayList$SubList$1,java.util.ArrayList$ListItr,java.util.ArrayList$Itr"
};

$Object* allocate$ArrayList($Class* clazz) {
	return $of($alloc(ArrayList));
}

$String* ArrayList::toString() {
	 return this->$AbstractList::toString();
}

void ArrayList::finalize() {
	this->$AbstractList::finalize();
}

$ObjectArray* ArrayList::EMPTY_ELEMENTDATA = nullptr;
$ObjectArray* ArrayList::DEFAULTCAPACITY_EMPTY_ELEMENTDATA = nullptr;

void ArrayList::init$(int32_t initialCapacity) {
	$useLocalCurrentObjectStackCache();
	$AbstractList::init$();
	if (initialCapacity > 0) {
		$set(this, elementData$, $new($ObjectArray, initialCapacity));
	} else if (initialCapacity == 0) {
		$set(this, elementData$, ArrayList::EMPTY_ELEMENTDATA);
	} else {
		$throwNew($IllegalArgumentException, $$str({"Illegal Capacity: "_s, $$str(initialCapacity)}));
	}
}

void ArrayList::init$() {
	$AbstractList::init$();
	$set(this, elementData$, ArrayList::DEFAULTCAPACITY_EMPTY_ELEMENTDATA);
}

void ArrayList::init$($Collection* c) {
	$AbstractList::init$();
	$var($ObjectArray, a, $nc(c)->toArray());
	if ((this->size$ = $nc(a)->length) != 0) {
		if ($of(c)->getClass() == ArrayList::class$) {
			$set(this, elementData$, a);
		} else {
			$load($ObjectArray);
			$set(this, elementData$, $Arrays::copyOf(a, this->size$, $getClass($ObjectArray)));
		}
	} else {
		$set(this, elementData$, ArrayList::EMPTY_ELEMENTDATA);
	}
}

void ArrayList::trimToSize() {
	++this->modCount;
	if (this->size$ < $nc(this->elementData$)->length) {
		$set(this, elementData$, (this->size$ == 0) ? ArrayList::EMPTY_ELEMENTDATA : $Arrays::copyOf(this->elementData$, this->size$));
	}
}

void ArrayList::ensureCapacity(int32_t minCapacity) {
	if (minCapacity > $nc(this->elementData$)->length && !(this->elementData$ == ArrayList::DEFAULTCAPACITY_EMPTY_ELEMENTDATA && minCapacity <= ArrayList::DEFAULT_CAPACITY)) {
		++this->modCount;
		grow(minCapacity);
	}
}

$ObjectArray* ArrayList::grow(int32_t minCapacity) {
	int32_t oldCapacity = $nc(this->elementData$)->length;
	if (oldCapacity > 0 || this->elementData$ != ArrayList::DEFAULTCAPACITY_EMPTY_ELEMENTDATA) {
		int32_t newCapacity = $ArraysSupport::newLength(oldCapacity, minCapacity - oldCapacity, oldCapacity >> 1);
		return $set(this, elementData$, $Arrays::copyOf(this->elementData$, newCapacity));
	} else {
		return $set(this, elementData$, $new($ObjectArray, $Math::max(ArrayList::DEFAULT_CAPACITY, minCapacity)));
	}
}

$ObjectArray* ArrayList::grow() {
	return grow(this->size$ + 1);
}

int32_t ArrayList::size() {
	return this->size$;
}

bool ArrayList::isEmpty() {
	return this->size$ == 0;
}

bool ArrayList::contains(Object$* o) {
	return indexOf(o) >= 0;
}

int32_t ArrayList::indexOf(Object$* o) {
	return indexOfRange(o, 0, this->size$);
}

int32_t ArrayList::indexOfRange(Object$* o, int32_t start, int32_t end) {
	$var($ObjectArray, es, this->elementData$);
	if (o == nullptr) {
		for (int32_t i = start; i < end; ++i) {
			if ($nc(es)->get(i) == nullptr) {
				return i;
			}
		}
	} else {
		for (int32_t i = start; i < end; ++i) {
			if ($nc($of(o))->equals($nc(es)->get(i))) {
				return i;
			}
		}
	}
	return -1;
}

int32_t ArrayList::lastIndexOf(Object$* o) {
	return lastIndexOfRange(o, 0, this->size$);
}

int32_t ArrayList::lastIndexOfRange(Object$* o, int32_t start, int32_t end) {
	$var($ObjectArray, es, this->elementData$);
	if (o == nullptr) {
		for (int32_t i = end - 1; i >= start; --i) {
			if ($nc(es)->get(i) == nullptr) {
				return i;
			}
		}
	} else {
		for (int32_t i = end - 1; i >= start; --i) {
			if ($nc($of(o))->equals($nc(es)->get(i))) {
				return i;
			}
		}
	}
	return -1;
}

$Object* ArrayList::clone() {
	try {
		$var(ArrayList, v, $cast(ArrayList, $AbstractList::clone()));
		$set($nc(v), elementData$, $Arrays::copyOf(this->elementData$, this->size$));
		v->modCount = 0;
		return $of(v);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$ObjectArray* ArrayList::toArray() {
	return $Arrays::copyOf(this->elementData$, this->size$);
}

$ObjectArray* ArrayList::toArray($ObjectArray* a) {
	if ($nc(a)->length < this->size$) {
		return $Arrays::copyOf(this->elementData$, this->size$, $of(a)->getClass());
	}
	$System::arraycopy(this->elementData$, 0, a, 0, this->size$);
	if ($nc(a)->length > this->size$) {
		a->set(this->size$, nullptr);
	}
	return a;
}

$Object* ArrayList::elementData(int32_t index) {
	return $of($nc(this->elementData$)->get(index));
}

$Object* ArrayList::elementAt($ObjectArray* es, int32_t index) {
	$init(ArrayList);
	return $of($nc(es)->get(index));
}

$Object* ArrayList::get(int32_t index) {
	$Objects::checkIndex(index, this->size$);
	return $of(elementData(index));
}

$Object* ArrayList::set(int32_t index, Object$* element) {
	$Objects::checkIndex(index, this->size$);
	$var($Object, oldValue, elementData(index));
	$nc(this->elementData$)->set(index, element);
	return $of(oldValue);
}

void ArrayList::add(Object$* e, $ObjectArray* elementData$renamed, int32_t s) {
	$var($ObjectArray, elementData, elementData$renamed);
	if (s == $nc(elementData)->length) {
		$assign(elementData, grow());
	}
	$nc(elementData)->set(s, e);
	this->size$ = s + 1;
}

bool ArrayList::add(Object$* e) {
	++this->modCount;
	add(e, this->elementData$, this->size$);
	return true;
}

void ArrayList::add(int32_t index, Object$* element) {
	rangeCheckForAdd(index);
	++this->modCount;
	int32_t s = 0;
	$var($ObjectArray, elementData, nullptr);
	if ((s = this->size$) == $nc(($assign(elementData, this->elementData$)))->length) {
		$assign(elementData, grow());
	}
	$System::arraycopy(elementData, index, elementData, index + 1, s - index);
	$nc(elementData)->set(index, element);
	this->size$ = s + 1;
}

$Object* ArrayList::remove(int32_t index) {
	$useLocalCurrentObjectStackCache();
	$Objects::checkIndex(index, this->size$);
	$var($ObjectArray, es, this->elementData$);
	$var($Object, oldValue, $nc(es)->get(index));
	fastRemove(es, index);
	return $of(oldValue);
}

bool ArrayList::equals(Object$* o) {
	if ($equals(o, this)) {
		return true;
	}
	if (!($instanceOf($List, o))) {
		return false;
	}
	int32_t expectedModCount = this->modCount;
	bool equal = ($nc($of(o))->getClass() == ArrayList::class$) ? equalsArrayList($cast(ArrayList, o)) : equalsRange($cast($List, o), 0, this->size$);
	checkForComodification(expectedModCount);
	return equal;
}

bool ArrayList::equalsRange($List* other, int32_t from, int32_t to) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, this->elementData$);
	if (to > $nc(es)->length) {
		$throwNew($ConcurrentModificationException);
	}
	$var($Iterator, oit, $nc(other)->iterator());
	for (; from < to; ++from) {
		bool var$0 = !$nc(oit)->hasNext();
		if (var$0 || !$Objects::equals($nc(es)->get(from), $($nc(oit)->next()))) {
			return false;
		}
	}
	return !$nc(oit)->hasNext();
}

bool ArrayList::equalsArrayList(ArrayList* other) {
	$useLocalCurrentObjectStackCache();
	int32_t otherModCount = $nc(other)->modCount;
	int32_t s = this->size$;
	bool equal = false;
	if (equal = (s == other->size$)) {
		$var($ObjectArray, otherEs, other->elementData$);
		$var($ObjectArray, es, this->elementData$);
		if (s > $nc(es)->length || s > $nc(otherEs)->length) {
			$throwNew($ConcurrentModificationException);
		}
		for (int32_t i = 0; i < s; ++i) {
			if (!$Objects::equals($nc(es)->get(i), $nc(otherEs)->get(i))) {
				equal = false;
				break;
			}
		}
	}
	other->checkForComodification(otherModCount);
	return equal;
}

void ArrayList::checkForComodification(int32_t expectedModCount) {
	if (this->modCount != expectedModCount) {
		$throwNew($ConcurrentModificationException);
	}
}

int32_t ArrayList::hashCode() {
	int32_t expectedModCount = this->modCount;
	int32_t hash = hashCodeRange(0, this->size$);
	checkForComodification(expectedModCount);
	return hash;
}

int32_t ArrayList::hashCodeRange(int32_t from, int32_t to) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, es, this->elementData$);
	if (to > $nc(es)->length) {
		$throwNew($ConcurrentModificationException);
	}
	int32_t hashCode = 1;
	for (int32_t i = from; i < to; ++i) {
		$var($Object0, e, $nc(es)->get(i));
		hashCode = 31 * hashCode + (e == nullptr ? 0 : $nc($of(e))->hashCode());
	}
	return hashCode;
}

bool ArrayList::remove(Object$* o) {
	$var($ObjectArray, es, this->elementData$);
	int32_t size = this->size$;
	int32_t i = 0;
	bool found$break = false;
	for (;;) {
		{
			if (o == nullptr) {
				for (; i < size; ++i) {
					if ($nc(es)->get(i) == nullptr) {
						found$break = true;
						break;
					}
				}
				if (found$break) {
					break;
				}
			} else {
				for (; i < size; ++i) {
					if ($nc($of(o))->equals($nc(es)->get(i))) {
						found$break = true;
						break;
					}
				}
				if (found$break) {
					break;
				}
			}
			return false;
		}
		break;
	}
	fastRemove(es, i);
	return true;
}

void ArrayList::fastRemove($ObjectArray* es, int32_t i) {
	++this->modCount;
	int32_t newSize = 0;
	if ((newSize = this->size$ - 1) > i) {
		$System::arraycopy(es, i + 1, es, i, newSize - i);
	}
	$nc(es)->set(this->size$ = newSize, nullptr);
}

void ArrayList::clear() {
	++this->modCount;
	$var($ObjectArray, es, this->elementData$);
	{
		int32_t to = this->size$;
		int32_t i = this->size$ = 0;
		for (; i < to; ++i) {
			$nc(es)->set(i, nullptr);
		}
	}
}

bool ArrayList::addAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, $nc(c)->toArray());
	++this->modCount;
	int32_t numNew = $nc(a)->length;
	if (numNew == 0) {
		return false;
	}
	$var($ObjectArray, elementData, nullptr);
	int32_t s = 0;
	if (numNew > $nc(($assign(elementData, this->elementData$)))->length - (s = this->size$)) {
		$assign(elementData, grow(s + numNew));
	}
	$System::arraycopy(a, 0, elementData, s, numNew);
	this->size$ = s + numNew;
	return true;
}

bool ArrayList::addAll(int32_t index, $Collection* c) {
	$useLocalCurrentObjectStackCache();
	rangeCheckForAdd(index);
	$var($ObjectArray, a, $nc(c)->toArray());
	++this->modCount;
	int32_t numNew = $nc(a)->length;
	if (numNew == 0) {
		return false;
	}
	$var($ObjectArray, elementData, nullptr);
	int32_t s = 0;
	if (numNew > $nc(($assign(elementData, this->elementData$)))->length - (s = this->size$)) {
		$assign(elementData, grow(s + numNew));
	}
	int32_t numMoved = s - index;
	if (numMoved > 0) {
		$System::arraycopy(elementData, index, elementData, index + numNew, numMoved);
	}
	$System::arraycopy(a, 0, elementData, index, numNew);
	this->size$ = s + numNew;
	return true;
}

void ArrayList::removeRange(int32_t fromIndex, int32_t toIndex) {
	if (fromIndex > toIndex) {
		$throwNew($IndexOutOfBoundsException, $(outOfBoundsMsg(fromIndex, toIndex)));
	}
	++this->modCount;
	shiftTailOverGap(this->elementData$, fromIndex, toIndex);
}

void ArrayList::shiftTailOverGap($ObjectArray* es, int32_t lo, int32_t hi) {
	$System::arraycopy(es, hi, es, lo, this->size$ - hi);
	{
		int32_t to = this->size$;
		int32_t i = (this->size$ -= hi - lo);
		for (; i < to; ++i) {
			$nc(es)->set(i, nullptr);
		}
	}
}

void ArrayList::rangeCheckForAdd(int32_t index) {
	if (index > this->size$ || index < 0) {
		$throwNew($IndexOutOfBoundsException, $(outOfBoundsMsg(index)));
	}
}

$String* ArrayList::outOfBoundsMsg(int32_t index) {
	$useLocalCurrentObjectStackCache();
	return $str({"Index: "_s, $$str(index), ", Size: "_s, $$str(this->size$)});
}

$String* ArrayList::outOfBoundsMsg(int32_t fromIndex, int32_t toIndex) {
	$init(ArrayList);
	$useLocalCurrentObjectStackCache();
	return $str({"From Index: "_s, $$str(fromIndex), " > To Index: "_s, $$str(toIndex)});
}

bool ArrayList::removeAll($Collection* c) {
	return batchRemove(c, false, 0, this->size$);
}

bool ArrayList::retainAll($Collection* c) {
	return batchRemove(c, true, 0, this->size$);
}

bool ArrayList::batchRemove($Collection* c, bool complement, int32_t from, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(c);
	$var($ObjectArray, es, this->elementData$);
	int32_t r = 0;
	for (r = from;; ++r) {
		if (r == end) {
			return false;
		}
		if (c->contains($nc(es)->get(r)) != complement) {
			break;
		}
	}
	int32_t w = r++;
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				{
					$var($Object, e, nullptr);
					for (; r < end; ++r) {
						if (c->contains($assign(e, $nc(es)->get(r))) == complement) {
							$nc(es)->set(w++, e);
						}
					}
				}
			} catch ($Throwable& ex) {
				$System::arraycopy(es, r, es, w, end - r);
				w += end - r;
				$throw(ex);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->modCount += end - w;
			shiftTailOverGap(es, w, end);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return true;
}

void ArrayList::writeObject($ObjectOutputStream* s) {
	int32_t expectedModCount = this->modCount;
	$nc(s)->defaultWriteObject();
	s->writeInt(this->size$);
	for (int32_t i = 0; i < this->size$; ++i) {
		s->writeObject($nc(this->elementData$)->get(i));
	}
	if (this->modCount != expectedModCount) {
		$throwNew($ConcurrentModificationException);
	}
}

void ArrayList::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	s->readInt();
	if (this->size$ > 0) {
		$load($ObjectArray);
		$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($ObjectArray), this->size$);
		$var($ObjectArray, elements, $new($ObjectArray, this->size$));
		for (int32_t i = 0; i < this->size$; ++i) {
			elements->set(i, $(s->readObject()));
		}
		$set(this, elementData$, elements);
	} else if (this->size$ == 0) {
		$set(this, elementData$, ArrayList::EMPTY_ELEMENTDATA);
	} else {
		$throwNew($InvalidObjectException, $$str({"Invalid size: "_s, $$str(this->size$)}));
	}
}

$ListIterator* ArrayList::listIterator(int32_t index) {
	rangeCheckForAdd(index);
	return $new($ArrayList$ListItr, this, index);
}

$ListIterator* ArrayList::listIterator() {
	return $new($ArrayList$ListItr, this, 0);
}

$Iterator* ArrayList::iterator() {
	return $new($ArrayList$Itr, this);
}

$List* ArrayList::subList(int32_t fromIndex, int32_t toIndex) {
	subListRangeCheck(fromIndex, toIndex, this->size$);
	return $new($ArrayList$SubList, this, fromIndex, toIndex);
}

void ArrayList::forEach($Consumer* action) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(action);
	int32_t expectedModCount = this->modCount;
	$var($ObjectArray, es, this->elementData$);
	int32_t size = this->size$;
	for (int32_t i = 0; this->modCount == expectedModCount && i < size; ++i) {
		action->accept($(elementAt(es, i)));
	}
	if (this->modCount != expectedModCount) {
		$throwNew($ConcurrentModificationException);
	}
}

$Spliterator* ArrayList::spliterator() {
	return $new($ArrayList$ArrayListSpliterator, this, 0, -1, 0);
}

$longs* ArrayList::nBits(int32_t n) {
	$init(ArrayList);
	return $new($longs, ((n - 1) >> 6) + 1);
}

void ArrayList::setBit($longs* bits, int32_t i) {
	$init(ArrayList);
	(*$nc(bits))[i >> 6] |= $sl((int64_t)1, i);
}

bool ArrayList::isClear($longs* bits, int32_t i) {
	$init(ArrayList);
	return ((int64_t)($nc(bits)->get(i >> 6) & (uint64_t)($sl((int64_t)1, i)))) == 0;
}

bool ArrayList::removeIf($Predicate* filter) {
	return removeIf(filter, 0, this->size$);
}

bool ArrayList::removeIf($Predicate* filter, int32_t i, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(filter);
	int32_t expectedModCount = this->modCount;
	$var($ObjectArray, es, this->elementData$);
	for (; i < end && !filter->test($(elementAt(es, i))); ++i) {
	}
	if (i < end) {
		int32_t beg = i;
		$var($longs, deathRow, nBits(end - beg));
		$nc(deathRow)->set(0, 1);
		for (i = beg + 1; i < end; ++i) {
			if (filter->test($(elementAt(es, i)))) {
				setBit(deathRow, i - beg);
			}
		}
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
		++this->modCount;
		int32_t w = beg;
		for (i = beg; i < end; ++i) {
			if (isClear(deathRow, i - beg)) {
				$nc(es)->set(w++, es->get(i));
			}
		}
		shiftTailOverGap(es, w, end);
		return true;
	} else {
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
		return false;
	}
}

void ArrayList::replaceAll($UnaryOperator* operator$) {
	replaceAllRange(operator$, 0, this->size$);
	++this->modCount;
}

void ArrayList::replaceAllRange($UnaryOperator* operator$, int32_t i, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(operator$);
	int32_t expectedModCount = this->modCount;
	$var($ObjectArray, es, this->elementData$);
	for (; this->modCount == expectedModCount && i < end; ++i) {
		$nc(es)->set(i, $(operator$->apply($(elementAt(es, i)))));
	}
	if (this->modCount != expectedModCount) {
		$throwNew($ConcurrentModificationException);
	}
}

void ArrayList::sort($Comparator* c) {
	int32_t expectedModCount = this->modCount;
	$Arrays::sort(this->elementData$, 0, this->size$, c);
	if (this->modCount != expectedModCount) {
		$throwNew($ConcurrentModificationException);
	}
	++this->modCount;
}

void ArrayList::checkInvariants() {
}

void clinit$ArrayList($Class* class$) {
	$assignStatic(ArrayList::EMPTY_ELEMENTDATA, $new($ObjectArray, 0));
	$assignStatic(ArrayList::DEFAULTCAPACITY_EMPTY_ELEMENTDATA, $new($ObjectArray, 0));
}

ArrayList::ArrayList() {
}

$Class* ArrayList::load$($String* name, bool initialize) {
	$loadClass(ArrayList, name, initialize, &_ArrayList_ClassInfo_, clinit$ArrayList, allocate$ArrayList);
	return class$;
}

$Class* ArrayList::class$ = nullptr;

	} // util
} // java