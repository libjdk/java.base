#include <java/util/Vector.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/Vector$1.h>
#include <java/util/Vector$Itr.h>
#include <java/util/Vector$ListItr.h>
#include <java/util/Vector$VectorSpliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/UnaryOperator.h>
#include <jdk/internal/util/ArraysSupport.h>
#include <jcpp.h>

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $Serializable = ::java::io::Serializable;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Vector$1 = ::java::util::Vector$1;
using $Vector$Itr = ::java::util::Vector$Itr;
using $Vector$ListItr = ::java::util::Vector$ListItr;
using $Vector$VectorSpliterator = ::java::util::Vector$VectorSpliterator;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $UnaryOperator = ::java::util::function::UnaryOperator;
using $ArraysSupport = ::jdk::internal::util::ArraysSupport;

namespace java {
	namespace util {

class Vector$$Lambda$lambda$removeAll$0 : public $Predicate {
	$class(Vector$$Lambda$lambda$removeAll$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return Vector::lambda$removeAll$0(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Vector$$Lambda$lambda$removeAll$0>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Vector$$Lambda$lambda$removeAll$0::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(Vector$$Lambda$lambda$removeAll$0, c)},
	{}
};
$MethodInfo Vector$$Lambda$lambda$removeAll$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(Vector$$Lambda$lambda$removeAll$0, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Vector$$Lambda$lambda$removeAll$0, test, bool, Object$*)},
	{}
};
$ClassInfo Vector$$Lambda$lambda$removeAll$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Vector$$Lambda$lambda$removeAll$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Vector$$Lambda$lambda$removeAll$0::load$($String* name, bool initialize) {
	$loadClass(Vector$$Lambda$lambda$removeAll$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Vector$$Lambda$lambda$removeAll$0::class$ = nullptr;

class Vector$$Lambda$lambda$retainAll$1$1 : public $Predicate {
	$class(Vector$$Lambda$lambda$retainAll$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Collection* c) {
		$set(this, c, c);
	}
	virtual bool test(Object$* e) override {
		 return Vector::lambda$retainAll$1(c, e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Vector$$Lambda$lambda$retainAll$1$1>());
	}
	$Collection* c = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Vector$$Lambda$lambda$retainAll$1$1::fieldInfos[2] = {
	{"c", "Ljava/util/Collection;", nullptr, $PUBLIC, $field(Vector$$Lambda$lambda$retainAll$1$1, c)},
	{}
};
$MethodInfo Vector$$Lambda$lambda$retainAll$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(Vector$$Lambda$lambda$retainAll$1$1, init$, void, $Collection*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Vector$$Lambda$lambda$retainAll$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo Vector$$Lambda$lambda$retainAll$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.Vector$$Lambda$lambda$retainAll$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Vector$$Lambda$lambda$retainAll$1$1::load$($String* name, bool initialize) {
	$loadClass(Vector$$Lambda$lambda$retainAll$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Vector$$Lambda$lambda$retainAll$1$1::class$ = nullptr;

$FieldInfo _Vector_FieldInfo_[] = {
	{"elementData", "[Ljava/lang/Object;", nullptr, $PROTECTED, $field(Vector, elementData$)},
	{"elementCount", "I", nullptr, $PROTECTED, $field(Vector, elementCount)},
	{"capacityIncrement", "I", nullptr, $PROTECTED, $field(Vector, capacityIncrement)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Vector, serialVersionUID)},
	{}
};

$MethodInfo _Vector_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(Vector, init$, void, int32_t, int32_t)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(Vector, init$, void, int32_t)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(Vector, init$, void)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(Vector, init$, void, $Collection*)},
	{"add", "(Ljava/lang/Object;[Ljava/lang/Object;I)V", "(TE;[Ljava/lang/Object;I)V", $PRIVATE, $method(Vector, add, void, Object$*, $ObjectArray*, int32_t)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, add, bool, Object$*)},
	{"add", "(ILjava/lang/Object;)V", "(ITE;)V", $PUBLIC, $virtualMethod(Vector, add, void, int32_t, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(Vector, addAll, bool, $Collection*)},
	{"addAll", "(ILjava/util/Collection;)Z", "(ILjava/util/Collection<+TE;>;)Z", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, addAll, bool, int32_t, $Collection*)},
	{"addElement", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, addElement, void, Object$*)},
	{"bulkRemove", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PRIVATE | $SYNCHRONIZED, $method(Vector, bulkRemove, bool, $Predicate*)},
	{"capacity", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, capacity, int32_t)},
	{"checkInvariants", "()V", nullptr, 0, $virtualMethod(Vector, checkInvariants, void)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(Vector, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, clone, $Object*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Vector, contains, bool, Object$*)},
	{"containsAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, containsAll, bool, $Collection*)},
	{"copyInto", "([Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, copyInto, void, $ObjectArray*)},
	{"elementAt", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, elementAt, $Object*, int32_t)},
	{"elementAt", "([Ljava/lang/Object;I)Ljava/lang/Object;", "<E:Ljava/lang/Object;>([Ljava/lang/Object;I)TE;", $STATIC, $staticMethod(Vector, elementAt, $Object*, $ObjectArray*, int32_t)},
	{"elementData", "(I)Ljava/lang/Object;", "(I)TE;", 0, $virtualMethod(Vector, elementData, $Object*, int32_t)},
	{"elements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<TE;>;", $PUBLIC, $virtualMethod(Vector, elements, $Enumeration*)},
	{"ensureCapacity", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, ensureCapacity, void, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, equals, bool, Object$*)},
	{"firstElement", "()Ljava/lang/Object;", "()TE;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, firstElement, $Object*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, forEach, void, $Consumer*)},
	{"get", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, get, $Object*, int32_t)},
	{"grow", "(I)[Ljava/lang/Object;", nullptr, $PRIVATE, $method(Vector, grow, $ObjectArray*, int32_t)},
	{"grow", "()[Ljava/lang/Object;", nullptr, $PRIVATE, $method(Vector, grow, $ObjectArray*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, hashCode, int32_t)},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Vector, indexOf, int32_t, Object$*)},
	{"indexOf", "(Ljava/lang/Object;I)I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, indexOf, int32_t, Object$*, int32_t)},
	{"insertElementAt", "(Ljava/lang/Object;I)V", "(TE;I)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, insertElementAt, void, Object$*, int32_t)},
	{"isClear", "([JI)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Vector, isClear, bool, $longs*, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, iterator, $Iterator*)},
	{"lambda$removeAll$0", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Vector, lambda$removeAll$0, bool, $Collection*, Object$*)},
	{"lambda$retainAll$1", "(Ljava/util/Collection;Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Vector, lambda$retainAll$1, bool, $Collection*, Object$*)},
	{"lastElement", "()Ljava/lang/Object;", "()TE;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, lastElement, $Object*)},
	{"lastIndexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, lastIndexOf, int32_t, Object$*)},
	{"lastIndexOf", "(Ljava/lang/Object;I)I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, lastIndexOf, int32_t, Object$*, int32_t)},
	{"listIterator", "(I)Ljava/util/ListIterator;", "(I)Ljava/util/ListIterator<TE;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, listIterator, $ListIterator*, int32_t)},
	{"listIterator", "()Ljava/util/ListIterator;", "()Ljava/util/ListIterator<TE;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, listIterator, $ListIterator*)},
	{"nBits", "(I)[J", nullptr, $PRIVATE | $STATIC, $staticMethod(Vector, nBits, $longs*, int32_t)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Vector, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Vector, remove, bool, Object$*)},
	{"remove", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, remove, $Object*, int32_t)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(Vector, removeAll, bool, $Collection*)},
	{"removeAllElements", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, removeAllElements, void)},
	{"removeElement", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, removeElement, bool, Object$*)},
	{"removeElementAt", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, removeElementAt, void, int32_t)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TE;>;)Z", $PUBLIC, $virtualMethod(Vector, removeIf, bool, $Predicate*)},
	{"removeRange", "(II)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(Vector, removeRange, void, int32_t, int32_t)},
	{"replaceAll", "(Ljava/util/function/UnaryOperator;)V", "(Ljava/util/function/UnaryOperator<TE;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, replaceAll, void, $UnaryOperator*)},
	{"retainAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(Vector, retainAll, bool, $Collection*)},
	{"set", "(ILjava/lang/Object;)Ljava/lang/Object;", "(ITE;)TE;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, set, $Object*, int32_t, Object$*)},
	{"setBit", "([JI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Vector, setBit, void, $longs*, int32_t)},
	{"setElementAt", "(Ljava/lang/Object;I)V", "(TE;I)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, setElementAt, void, Object$*, int32_t)},
	{"setSize", "(I)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, setSize, void, int32_t)},
	{"shiftTailOverGap", "([Ljava/lang/Object;II)V", nullptr, $PRIVATE, $method(Vector, shiftTailOverGap, void, $ObjectArray*, int32_t, int32_t)},
	{"size", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, size, int32_t)},
	{"sort", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, sort, void, $Comparator*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(Vector, spliterator, $Spliterator*)},
	{"subList", "(II)Ljava/util/List;", "(II)Ljava/util/List<TE;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, subList, $List*, int32_t, int32_t)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, toArray, $ObjectArray*, $ObjectArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, toString, $String*)},
	{"trimToSize", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Vector, trimToSize, void)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(Vector, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Vector_InnerClassesInfo_[] = {
	{"java.util.Vector$VectorSpliterator", "java.util.Vector", "VectorSpliterator", $FINAL},
	{"java.util.Vector$ListItr", "java.util.Vector", "ListItr", $FINAL},
	{"java.util.Vector$Itr", "java.util.Vector", "Itr", $PRIVATE},
	{"java.util.Vector$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Vector_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.Vector",
	"java.util.AbstractList",
	"java.util.RandomAccess,java.lang.Cloneable,java.io.Serializable",
	_Vector_FieldInfo_,
	_Vector_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractList<TE;>;Ljava/util/List<TE;>;Ljava/util/RandomAccess;Ljava/lang/Cloneable;Ljava/io/Serializable;",
	nullptr,
	_Vector_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Vector$VectorSpliterator,java.util.Vector$ListItr,java.util.Vector$Itr,java.util.Vector$1"
};

$Object* allocate$Vector($Class* clazz) {
	return $of($alloc(Vector));
}

void Vector::finalize() {
	this->$AbstractList::finalize();
}

void Vector::init$(int32_t initialCapacity, int32_t capacityIncrement) {
	$useLocalCurrentObjectStackCache();
	$AbstractList::init$();
	if (initialCapacity < 0) {
		$throwNew($IllegalArgumentException, $$str({"Illegal Capacity: "_s, $$str(initialCapacity)}));
	}
	$set(this, elementData$, $new($ObjectArray, initialCapacity));
	this->capacityIncrement = capacityIncrement;
}

void Vector::init$(int32_t initialCapacity) {
	Vector::init$(initialCapacity, 0);
}

void Vector::init$() {
	Vector::init$(10);
}

void Vector::init$($Collection* c) {
	$AbstractList::init$();
	$var($ObjectArray, a, $nc(c)->toArray());
	this->elementCount = $nc(a)->length;
	$load($ArrayList);
	if ($of(c)->getClass() == $ArrayList::class$) {
		$set(this, elementData$, a);
	} else {
		$load($ObjectArray);
		$set(this, elementData$, $Arrays::copyOf(a, this->elementCount, $getClass($ObjectArray)));
	}
}

void Vector::copyInto($ObjectArray* anArray) {
	$synchronized(this) {
		$System::arraycopy(this->elementData$, 0, anArray, 0, this->elementCount);
	}
}

void Vector::trimToSize() {
	$synchronized(this) {
		++this->modCount;
		int32_t oldCapacity = $nc(this->elementData$)->length;
		if (this->elementCount < oldCapacity) {
			$set(this, elementData$, $Arrays::copyOf(this->elementData$, this->elementCount));
		}
	}
}

void Vector::ensureCapacity(int32_t minCapacity) {
	$synchronized(this) {
		if (minCapacity > 0) {
			++this->modCount;
			if (minCapacity > $nc(this->elementData$)->length) {
				grow(minCapacity);
			}
		}
	}
}

$ObjectArray* Vector::grow(int32_t minCapacity) {
	int32_t oldCapacity = $nc(this->elementData$)->length;
	int32_t newCapacity = $ArraysSupport::newLength(oldCapacity, minCapacity - oldCapacity, this->capacityIncrement > 0 ? this->capacityIncrement : oldCapacity);
	return $set(this, elementData$, $Arrays::copyOf(this->elementData$, newCapacity));
}

$ObjectArray* Vector::grow() {
	return grow(this->elementCount + 1);
}

void Vector::setSize(int32_t newSize) {
	$synchronized(this) {
		++this->modCount;
		if (newSize > $nc(this->elementData$)->length) {
			grow(newSize);
		}
		$var($ObjectArray, es, this->elementData$);
		{
			int32_t to = this->elementCount;
			int32_t i = newSize;
			for (; i < to; ++i) {
				$nc(es)->set(i, nullptr);
			}
		}
		this->elementCount = newSize;
	}
}

int32_t Vector::capacity() {
	$synchronized(this) {
		return $nc(this->elementData$)->length;
	}
}

int32_t Vector::size() {
	$synchronized(this) {
		return this->elementCount;
	}
}

bool Vector::isEmpty() {
	$synchronized(this) {
		return this->elementCount == 0;
	}
}

$Enumeration* Vector::elements() {
	return $new($Vector$1, this);
}

bool Vector::contains(Object$* o) {
	return indexOf(o, 0) >= 0;
}

int32_t Vector::indexOf(Object$* o) {
	return indexOf(o, 0);
}

int32_t Vector::indexOf(Object$* o, int32_t index) {
	$synchronized(this) {
		if (o == nullptr) {
			for (int32_t i = index; i < this->elementCount; ++i) {
				if ($nc(this->elementData$)->get(i) == nullptr) {
					return i;
				}
			}
		} else {
			for (int32_t i = index; i < this->elementCount; ++i) {
				if ($nc($of(o))->equals($nc(this->elementData$)->get(i))) {
					return i;
				}
			}
		}
		return -1;
	}
}

int32_t Vector::lastIndexOf(Object$* o) {
	$synchronized(this) {
		return lastIndexOf(o, this->elementCount - 1);
	}
}

int32_t Vector::lastIndexOf(Object$* o, int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index >= this->elementCount) {
			$throwNew($IndexOutOfBoundsException, $$str({$$str(index), " >= "_s, $$str(this->elementCount)}));
		}
		if (o == nullptr) {
			for (int32_t i = index; i >= 0; --i) {
				if ($nc(this->elementData$)->get(i) == nullptr) {
					return i;
				}
			}
		} else {
			for (int32_t i = index; i >= 0; --i) {
				if ($nc($of(o))->equals($nc(this->elementData$)->get(i))) {
					return i;
				}
			}
		}
		return -1;
	}
}

$Object* Vector::elementAt(int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index >= this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, $$str({$$str(index), " >= "_s, $$str(this->elementCount)}));
		}
		return $of(elementData(index));
	}
}

$Object* Vector::firstElement() {
	$synchronized(this) {
		if (this->elementCount == 0) {
			$throwNew($NoSuchElementException);
		}
		return $of(elementData(0));
	}
}

$Object* Vector::lastElement() {
	$synchronized(this) {
		if (this->elementCount == 0) {
			$throwNew($NoSuchElementException);
		}
		return $of(elementData(this->elementCount - 1));
	}
}

void Vector::setElementAt(Object$* obj, int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index >= this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, $$str({$$str(index), " >= "_s, $$str(this->elementCount)}));
		}
		$nc(this->elementData$)->set(index, obj);
	}
}

void Vector::removeElementAt(int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index >= this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, $$str({$$str(index), " >= "_s, $$str(this->elementCount)}));
		} else if (index < 0) {
			$throwNew($ArrayIndexOutOfBoundsException, index);
		}
		int32_t j = this->elementCount - index - 1;
		if (j > 0) {
			$System::arraycopy(this->elementData$, index + 1, this->elementData$, index, j);
		}
		++this->modCount;
		--this->elementCount;
		$nc(this->elementData$)->set(this->elementCount, nullptr);
	}
}

void Vector::insertElementAt(Object$* obj, int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index > this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, $$str({$$str(index), " > "_s, $$str(this->elementCount)}));
		}
		++this->modCount;
		int32_t s = this->elementCount;
		$var($ObjectArray, elementData, this->elementData$);
		if (s == $nc(elementData)->length) {
			$assign(elementData, grow());
		}
		$System::arraycopy(elementData, index, elementData, index + 1, s - index);
		$nc(elementData)->set(index, obj);
		this->elementCount = s + 1;
	}
}

void Vector::addElement(Object$* obj) {
	$synchronized(this) {
		++this->modCount;
		add(obj, this->elementData$, this->elementCount);
	}
}

bool Vector::removeElement(Object$* obj) {
	$synchronized(this) {
		++this->modCount;
		int32_t i = indexOf(obj);
		if (i >= 0) {
			removeElementAt(i);
			return true;
		}
		return false;
	}
}

void Vector::removeAllElements() {
	$synchronized(this) {
		$var($ObjectArray, es, this->elementData$);
		{
			int32_t to = this->elementCount;
			int32_t i = this->elementCount = 0;
			for (; i < to; ++i) {
				$nc(es)->set(i, nullptr);
			}
		}
		++this->modCount;
	}
}

$Object* Vector::clone() {
	$synchronized(this) {
		try {
			$var(Vector, v, $cast(Vector, $AbstractList::clone()));
			$set($nc(v), elementData$, $Arrays::copyOf(this->elementData$, this->elementCount));
			v->modCount = 0;
			return $of(v);
		} catch ($CloneNotSupportedException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
	$shouldNotReachHere();
}

$ObjectArray* Vector::toArray() {
	$synchronized(this) {
		return $Arrays::copyOf(this->elementData$, this->elementCount);
	}
}

$ObjectArray* Vector::toArray($ObjectArray* a) {
	$synchronized(this) {
		if ($nc(a)->length < this->elementCount) {
			return $Arrays::copyOf(this->elementData$, this->elementCount, $of(a)->getClass());
		}
		$System::arraycopy(this->elementData$, 0, a, 0, this->elementCount);
		if ($nc(a)->length > this->elementCount) {
			a->set(this->elementCount, nullptr);
		}
		return a;
	}
}

$Object* Vector::elementData(int32_t index) {
	return $of($nc(this->elementData$)->get(index));
}

$Object* Vector::elementAt($ObjectArray* es, int32_t index) {
	$init(Vector);
	return $of($nc(es)->get(index));
}

$Object* Vector::get(int32_t index) {
	$synchronized(this) {
		if (index >= this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, index);
		}
		return $of(elementData(index));
	}
}

$Object* Vector::set(int32_t index, Object$* element) {
	$synchronized(this) {
		if (index >= this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, index);
		}
		$var($Object, oldValue, elementData(index));
		$nc(this->elementData$)->set(index, element);
		return $of(oldValue);
	}
}

void Vector::add(Object$* e, $ObjectArray* elementData$renamed, int32_t s) {
	$var($ObjectArray, elementData, elementData$renamed);
	if (s == $nc(elementData)->length) {
		$assign(elementData, grow());
	}
	$nc(elementData)->set(s, e);
	this->elementCount = s + 1;
}

bool Vector::add(Object$* e) {
	$synchronized(this) {
		++this->modCount;
		add(e, this->elementData$, this->elementCount);
		return true;
	}
}

bool Vector::remove(Object$* o) {
	return removeElement(o);
}

void Vector::add(int32_t index, Object$* element) {
	insertElementAt(element, index);
}

$Object* Vector::remove(int32_t index) {
	$synchronized(this) {
		++this->modCount;
		if (index >= this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, index);
		}
		$var($Object, oldValue, elementData(index));
		int32_t numMoved = this->elementCount - index - 1;
		if (numMoved > 0) {
			$System::arraycopy(this->elementData$, index + 1, this->elementData$, index, numMoved);
		}
		$nc(this->elementData$)->set(--this->elementCount, nullptr);
		return $of(oldValue);
	}
}

void Vector::clear() {
	removeAllElements();
}

bool Vector::containsAll($Collection* c) {
	$synchronized(this) {
		return $AbstractList::containsAll(c);
	}
}

bool Vector::addAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, $nc(c)->toArray());
	++this->modCount;
	int32_t numNew = $nc(a)->length;
	if (numNew == 0) {
		return false;
	}
	$synchronized(this) {
		$var($ObjectArray, elementData, this->elementData$);
		int32_t s = this->elementCount;
		if (numNew > $nc(elementData)->length - s) {
			$assign(elementData, grow(s + numNew));
		}
		$System::arraycopy(a, 0, elementData, s, numNew);
		this->elementCount = s + numNew;
		return true;
	}
}

bool Vector::removeAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(Vector$$Lambda$lambda$removeAll$0, c)));
}

bool Vector::retainAll($Collection* c) {
	$Objects::requireNonNull(c);
	return bulkRemove(static_cast<$Predicate*>($$new(Vector$$Lambda$lambda$retainAll$1$1, c)));
}

bool Vector::removeIf($Predicate* filter) {
	$Objects::requireNonNull(filter);
	return bulkRemove(filter);
}

$longs* Vector::nBits(int32_t n) {
	$init(Vector);
	return $new($longs, ((n - 1) >> 6) + 1);
}

void Vector::setBit($longs* bits, int32_t i) {
	$init(Vector);
	(*$nc(bits))[i >> 6] |= $sl((int64_t)1, i);
}

bool Vector::isClear($longs* bits, int32_t i) {
	$init(Vector);
	return ((int64_t)($nc(bits)->get(i >> 6) & (uint64_t)($sl((int64_t)1, i)))) == 0;
}

bool Vector::bulkRemove($Predicate* filter) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		int32_t expectedModCount = this->modCount;
		$var($ObjectArray, es, this->elementData$);
		int32_t end = this->elementCount;
		int32_t i = 0;
		for (i = 0; i < end && !$nc(filter)->test($(elementAt(es, i))); ++i) {
		}
		if (i < end) {
			int32_t beg = i;
			$var($longs, deathRow, nBits(end - beg));
			$nc(deathRow)->set(0, 1);
			for (i = beg + 1; i < end; ++i) {
				if ($nc(filter)->test($(elementAt(es, i)))) {
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
			for (i = (this->elementCount = w); i < end; ++i) {
				$nc(es)->set(i, nullptr);
			}
			return true;
		} else {
			if (this->modCount != expectedModCount) {
				$throwNew($ConcurrentModificationException);
			}
			return false;
		}
	}
}

bool Vector::addAll(int32_t index, $Collection* c) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index < 0 || index > this->elementCount) {
			$throwNew($ArrayIndexOutOfBoundsException, index);
		}
		$var($ObjectArray, a, $nc(c)->toArray());
		++this->modCount;
		int32_t numNew = $nc(a)->length;
		if (numNew == 0) {
			return false;
		}
		$var($ObjectArray, elementData, this->elementData$);
		int32_t s = this->elementCount;
		if (numNew > $nc(elementData)->length - s) {
			$assign(elementData, grow(s + numNew));
		}
		int32_t numMoved = s - index;
		if (numMoved > 0) {
			$System::arraycopy(elementData, index, elementData, index + numNew, numMoved);
		}
		$System::arraycopy(a, 0, elementData, index, numNew);
		this->elementCount = s + numNew;
		return true;
	}
}

bool Vector::equals(Object$* o) {
	$synchronized(this) {
		return $AbstractList::equals(o);
	}
}

int32_t Vector::hashCode() {
	$synchronized(this) {
		return $AbstractList::hashCode();
	}
}

$String* Vector::toString() {
	$synchronized(this) {
		return $AbstractList::toString();
	}
}

$List* Vector::subList(int32_t fromIndex, int32_t toIndex) {
	$synchronized(this) {
		return $Collections::synchronizedList($($AbstractList::subList(fromIndex, toIndex)), this);
	}
}

void Vector::removeRange(int32_t fromIndex, int32_t toIndex) {
	$synchronized(this) {
		++this->modCount;
		shiftTailOverGap(this->elementData$, fromIndex, toIndex);
	}
}

void Vector::shiftTailOverGap($ObjectArray* es, int32_t lo, int32_t hi) {
	$System::arraycopy(es, hi, es, lo, this->elementCount - hi);
	{
		int32_t to = this->elementCount;
		int32_t i = (this->elementCount -= hi - lo);
		for (; i < to; ++i) {
			$nc(es)->set(i, nullptr);
		}
	}
}

void Vector::readObject($ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, gfields, $nc(in)->readFields());
	int32_t count = $nc(gfields)->get("elementCount"_s, 0);
	$var($ObjectArray, data, $cast($ObjectArray, gfields->get("elementData"_s, ($Object*)nullptr)));
	if (count < 0 || data == nullptr || count > $nc(data)->length) {
		$throwNew($StreamCorruptedException, "Inconsistent vector internals"_s);
	}
	this->elementCount = count;
	$set(this, elementData$, $cast($ObjectArray, $nc(data)->clone()));
}

void Vector::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$var($ObjectArray, data, nullptr);
	$synchronized(this) {
		$nc(fields)->put("capacityIncrement"_s, this->capacityIncrement);
		fields->put("elementCount"_s, this->elementCount);
		$assign(data, $cast($ObjectArray, $nc(this->elementData$)->clone()));
	}
	$nc(fields)->put("elementData"_s, $of(data));
	s->writeFields();
}

$ListIterator* Vector::listIterator(int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (index < 0 || index > this->elementCount) {
			$throwNew($IndexOutOfBoundsException, $$str({"Index: "_s, $$str(index)}));
		}
		return $new($Vector$ListItr, this, index);
	}
}

$ListIterator* Vector::listIterator() {
	$synchronized(this) {
		return $new($Vector$ListItr, this, 0);
	}
}

$Iterator* Vector::iterator() {
	$synchronized(this) {
		return $new($Vector$Itr, this);
	}
}

void Vector::forEach($Consumer* action) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(action);
		int32_t expectedModCount = this->modCount;
		$var($ObjectArray, es, this->elementData$);
		int32_t size = this->elementCount;
		for (int32_t i = 0; this->modCount == expectedModCount && i < size; ++i) {
			action->accept($(elementAt(es, i)));
		}
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
	}
}

void Vector::replaceAll($UnaryOperator* operator$) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Objects::requireNonNull(operator$);
		int32_t expectedModCount = this->modCount;
		$var($ObjectArray, es, this->elementData$);
		int32_t size = this->elementCount;
		for (int32_t i = 0; this->modCount == expectedModCount && i < size; ++i) {
			$nc(es)->set(i, $(operator$->apply($(elementAt(es, i)))));
		}
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
		++this->modCount;
	}
}

void Vector::sort($Comparator* c) {
	$synchronized(this) {
		int32_t expectedModCount = this->modCount;
		$Arrays::sort(this->elementData$, 0, this->elementCount, c);
		if (this->modCount != expectedModCount) {
			$throwNew($ConcurrentModificationException);
		}
		++this->modCount;
	}
}

$Spliterator* Vector::spliterator() {
	return $new($Vector$VectorSpliterator, this, nullptr, 0, -1, 0);
}

void Vector::checkInvariants() {
}

bool Vector::lambda$retainAll$1($Collection* c, Object$* e) {
	$init(Vector);
	return !$nc(c)->contains(e);
}

bool Vector::lambda$removeAll$0($Collection* c, Object$* e) {
	$init(Vector);
	return $nc(c)->contains(e);
}

Vector::Vector() {
}

$Class* Vector::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Vector$$Lambda$lambda$removeAll$0::classInfo$.name)) {
			return Vector$$Lambda$lambda$removeAll$0::load$(name, initialize);
		}
		if (name->equals(Vector$$Lambda$lambda$retainAll$1$1::classInfo$.name)) {
			return Vector$$Lambda$lambda$retainAll$1$1::load$(name, initialize);
		}
	}
	$loadClass(Vector, name, initialize, &_Vector_ClassInfo_, allocate$Vector);
	return class$;
}

$Class* Vector::class$ = nullptr;

	} // util
} // java