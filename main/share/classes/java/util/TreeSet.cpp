#include <java/util/TreeSet.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/SortedSet.h>
#include <java/util/Spliterator.h>
#include <java/util/TreeMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef PRESENT

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableMap = ::java::util::NavigableMap;
using $NavigableSet = ::java::util::NavigableSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $SortedSet = ::java::util::SortedSet;
using $Spliterator = ::java::util::Spliterator;
using $TreeMap = ::java::util::TreeMap;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {

$FieldInfo _TreeSet_FieldInfo_[] = {
	{"m", "Ljava/util/NavigableMap;", "Ljava/util/NavigableMap<TE;Ljava/lang/Object;>;", $PRIVATE | $TRANSIENT, $field(TreeSet, m)},
	{"PRESENT", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TreeSet, PRESENT)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TreeSet, serialVersionUID)},
	{}
};

$MethodInfo _TreeSet_MethodInfo_[] = {
	{"*containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/NavigableMap;)V", "(Ljava/util/NavigableMap<TE;Ljava/lang/Object;>;)V", 0, $method(TreeSet, init$, void, $NavigableMap*)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(TreeSet, init$, void)},
	{"<init>", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC, $method(TreeSet, init$, void, $Comparator*)},
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<+TE;>;)V", $PUBLIC, $method(TreeSet, init$, void, $Collection*)},
	{"<init>", "(Ljava/util/SortedSet;)V", "(Ljava/util/SortedSet<TE;>;)V", $PUBLIC, $method(TreeSet, init$, void, $SortedSet*)},
	{"add", "(Ljava/lang/Object;)Z", "(TE;)Z", $PUBLIC, $virtualMethod(TreeSet, add, bool, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<+TE;>;)Z", $PUBLIC, $virtualMethod(TreeSet, addAll, bool, $Collection*)},
	{"ceiling", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(TreeSet, ceiling, $Object*, Object$*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(TreeSet, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(TreeSet, clone, $Object*)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TE;>;", $PUBLIC, $virtualMethod(TreeSet, comparator, $Comparator*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(TreeSet, contains, bool, Object$*)},
	{"descendingIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(TreeSet, descendingIterator, $Iterator*)},
	{"descendingSet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, descendingSet, $NavigableSet*)},
	{"first", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(TreeSet, first, $Object*)},
	{"floor", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(TreeSet, floor, $Object*, Object$*)},
	{"headSet", "(Ljava/lang/Object;Z)Ljava/util/NavigableSet;", "(TE;Z)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, headSet, $NavigableSet*, Object$*, bool)},
	{"headSet", "(Ljava/lang/Object;)Ljava/util/SortedSet;", "(TE;)Ljava/util/SortedSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, headSet, $SortedSet*, Object$*)},
	{"higher", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(TreeSet, higher, $Object*, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(TreeSet, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(TreeSet, iterator, $Iterator*)},
	{"last", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(TreeSet, last, $Object*)},
	{"lower", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TE;)TE;", $PUBLIC, $virtualMethod(TreeSet, lower, $Object*, Object$*)},
	{"*parallelStream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"pollFirst", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(TreeSet, pollFirst, $Object*)},
	{"pollLast", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(TreeSet, pollLast, $Object*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(TreeSet, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(TreeSet, remove, bool, Object$*)},
	{"*removeAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*removeIf", "(Ljava/util/function/Predicate;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*retainAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(TreeSet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(TreeSet, spliterator, $Spliterator*)},
	{"*stream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"subSet", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/NavigableSet;", "(TE;ZTE;Z)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, subSet, $NavigableSet*, Object$*, bool, Object$*, bool)},
	{"subSet", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/SortedSet;", "(TE;TE;)Ljava/util/SortedSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, subSet, $SortedSet*, Object$*, Object$*)},
	{"tailSet", "(Ljava/lang/Object;Z)Ljava/util/NavigableSet;", "(TE;Z)Ljava/util/NavigableSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, tailSet, $NavigableSet*, Object$*, bool)},
	{"tailSet", "(Ljava/lang/Object;)Ljava/util/SortedSet;", "(TE;)Ljava/util/SortedSet<TE;>;", $PUBLIC, $virtualMethod(TreeSet, tailSet, $SortedSet*, Object$*)},
	{"*toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(TreeSet, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _TreeSet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.TreeSet",
	"java.util.AbstractSet",
	"java.util.NavigableSet,java.lang.Cloneable,java.io.Serializable",
	_TreeSet_FieldInfo_,
	_TreeSet_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/AbstractSet<TE;>;Ljava/util/NavigableSet<TE;>;Ljava/lang/Cloneable;Ljava/io/Serializable;"
};

$Object* allocate$TreeSet($Class* clazz) {
	return $of($alloc(TreeSet));
}

bool TreeSet::equals(Object$* o) {
	 return this->$AbstractSet::equals(o);
}

int32_t TreeSet::hashCode() {
	 return this->$AbstractSet::hashCode();
}

bool TreeSet::removeAll($Collection* c) {
	 return this->$AbstractSet::removeAll(c);
}

$ObjectArray* TreeSet::toArray() {
	 return this->$AbstractSet::toArray();
}

$ObjectArray* TreeSet::toArray($ObjectArray* a) {
	 return this->$AbstractSet::toArray(a);
}

bool TreeSet::containsAll($Collection* c) {
	 return this->$AbstractSet::containsAll(c);
}

bool TreeSet::retainAll($Collection* c) {
	 return this->$AbstractSet::retainAll(c);
}

$String* TreeSet::toString() {
	 return this->$AbstractSet::toString();
}

$ObjectArray* TreeSet::toArray($IntFunction* generator) {
	 return this->$AbstractSet::toArray(generator);
}

bool TreeSet::removeIf($Predicate* filter) {
	 return this->$AbstractSet::removeIf(filter);
}

$Stream* TreeSet::stream() {
	 return this->$AbstractSet::stream();
}

$Stream* TreeSet::parallelStream() {
	 return this->$AbstractSet::parallelStream();
}

void TreeSet::forEach($Consumer* action) {
	this->$AbstractSet::forEach(action);
}

void TreeSet::finalize() {
	this->$AbstractSet::finalize();
}

$Object* TreeSet::PRESENT = nullptr;

void TreeSet::init$($NavigableMap* m) {
	$AbstractSet::init$();
	$set(this, m, m);
}

void TreeSet::init$() {
	TreeSet::init$(static_cast<$NavigableMap*>($$new($TreeMap)));
}

void TreeSet::init$($Comparator* comparator) {
	TreeSet::init$(static_cast<$NavigableMap*>($$new($TreeMap, comparator)));
}

void TreeSet::init$($Collection* c) {
	TreeSet::init$();
	addAll(c);
}

void TreeSet::init$($SortedSet* s) {
	TreeSet::init$($($nc(s)->comparator()));
	addAll(s);
}

$Iterator* TreeSet::iterator() {
	return $nc($($nc(this->m)->navigableKeySet()))->iterator();
}

$Iterator* TreeSet::descendingIterator() {
	return $nc($($nc(this->m)->descendingKeySet()))->iterator();
}

$NavigableSet* TreeSet::descendingSet() {
	return $new(TreeSet, $($nc(this->m)->descendingMap()));
}

int32_t TreeSet::size() {
	return $nc(this->m)->size();
}

bool TreeSet::isEmpty() {
	return $nc(this->m)->isEmpty();
}

bool TreeSet::contains(Object$* o) {
	return $nc(this->m)->containsKey(o);
}

bool TreeSet::add(Object$* e) {
	return $nc(this->m)->put(e, TreeSet::PRESENT) == nullptr;
}

bool TreeSet::remove(Object$* o) {
	return $equals($nc(this->m)->remove(o), TreeSet::PRESENT);
}

void TreeSet::clear() {
	$nc(this->m)->clear();
}

bool TreeSet::addAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	{
		$var($TreeMap, map, nullptr);
		bool var$1 = $nc(this->m)->size() == 0;
		bool var$0 = var$1 && $nc(c)->size() > 0 && $instanceOf($SortedSet, c);
		if (var$0) {
			$var($NavigableMap, patt12583$temp, this->m);
			bool var$2 = $instanceOf($TreeMap, patt12583$temp);
			if (var$2) {
				$assign(map, $cast($TreeMap, patt12583$temp));
				var$2 = true;
			}
			var$0 = var$2;
		}
		if (var$0) {
			$var($SortedSet, set, $cast($SortedSet, c));
			$var($Object, var$3, $of(set->comparator()));
			if ($Objects::equals(var$3, $($nc(map)->comparator()))) {
				$nc(map)->addAllForTreeSet(set, TreeSet::PRESENT);
				return true;
			}
		}
	}
	return $AbstractSet::addAll(c);
}

$NavigableSet* TreeSet::subSet(Object$* fromElement, bool fromInclusive, Object$* toElement, bool toInclusive) {
	return $new(TreeSet, $($nc(this->m)->subMap(fromElement, fromInclusive, toElement, toInclusive)));
}

$NavigableSet* TreeSet::headSet(Object$* toElement, bool inclusive) {
	return $new(TreeSet, $($nc(this->m)->headMap(toElement, inclusive)));
}

$NavigableSet* TreeSet::tailSet(Object$* fromElement, bool inclusive) {
	return $new(TreeSet, $($nc(this->m)->tailMap(fromElement, inclusive)));
}

$SortedSet* TreeSet::subSet(Object$* fromElement, Object$* toElement) {
	return subSet(fromElement, true, toElement, false);
}

$SortedSet* TreeSet::headSet(Object$* toElement) {
	return headSet(toElement, false);
}

$SortedSet* TreeSet::tailSet(Object$* fromElement) {
	return tailSet(fromElement, true);
}

$Comparator* TreeSet::comparator() {
	return $nc(this->m)->comparator();
}

$Object* TreeSet::first() {
	return $of($nc(this->m)->firstKey());
}

$Object* TreeSet::last() {
	return $of($nc(this->m)->lastKey());
}

$Object* TreeSet::lower(Object$* e) {
	return $of($nc(this->m)->lowerKey(e));
}

$Object* TreeSet::floor(Object$* e) {
	return $of($nc(this->m)->floorKey(e));
}

$Object* TreeSet::ceiling(Object$* e) {
	return $of($nc(this->m)->ceilingKey(e));
}

$Object* TreeSet::higher(Object$* e) {
	return $of($nc(this->m)->higherKey(e));
}

$Object* TreeSet::pollFirst() {
	$var($Map$Entry, e, $nc(this->m)->pollFirstEntry());
	return $of((e == nullptr) ? ($Object*)nullptr : $nc(e)->getKey());
}

$Object* TreeSet::pollLast() {
	$var($Map$Entry, e, $nc(this->m)->pollLastEntry());
	return $of((e == nullptr) ? ($Object*)nullptr : $nc(e)->getKey());
}

$Object* TreeSet::clone() {
	$var(TreeSet, clone, nullptr);
	try {
		$assign(clone, $cast(TreeSet, $AbstractSet::clone()));
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$set($nc(clone), m, $new($TreeMap, static_cast<$SortedMap*>(this->m)));
	return $of(clone);
}

void TreeSet::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultWriteObject();
	s->writeObject($($nc(this->m)->comparator()));
	s->writeInt($nc(this->m)->size());
	{
		$var($Iterator, i$, $nc($($nc(this->m)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, e, i$->next());
			s->writeObject(e);
		}
	}
}

void TreeSet::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	$var($Comparator, c, $cast($Comparator, s->readObject()));
	$var($TreeMap, tm, $new($TreeMap, c));
	$set(this, m, tm);
	int32_t size = s->readInt();
	tm->readTreeSet(size, s, TreeSet::PRESENT);
}

$Spliterator* TreeSet::spliterator() {
	return $TreeMap::keySpliteratorFor(this->m);
}

void clinit$TreeSet($Class* class$) {
	$assignStatic(TreeSet::PRESENT, $new($Object));
}

TreeSet::TreeSet() {
}

$Class* TreeSet::load$($String* name, bool initialize) {
	$loadClass(TreeSet, name, initialize, &_TreeSet_ClassInfo_, clinit$TreeSet, allocate$TreeSet);
	return class$;
}

$Class* TreeSet::class$ = nullptr;

	} // util
} // java