#include <java/util/concurrent/ConcurrentSkipListMap$KeySet.h>

#include <java/lang/ClassCastException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/SortedSet.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ConcurrentNavigableMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap$KeyIterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$KeySpliterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap$SubMapKeyIterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableSet = ::java::util::NavigableSet;
using $Set = ::java::util::Set;
using $SortedSet = ::java::util::SortedSet;
using $Spliterator = ::java::util::Spliterator;
using $ConcurrentNavigableMap = ::java::util::concurrent::ConcurrentNavigableMap;
using $ConcurrentSkipListMap = ::java::util::concurrent::ConcurrentSkipListMap;
using $ConcurrentSkipListMap$KeyIterator = ::java::util::concurrent::ConcurrentSkipListMap$KeyIterator;
using $ConcurrentSkipListMap$SubMap = ::java::util::concurrent::ConcurrentSkipListMap$SubMap;
using $ConcurrentSkipListMap$SubMap$SubMapKeyIterator = ::java::util::concurrent::ConcurrentSkipListMap$SubMap$SubMapKeyIterator;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ConcurrentSkipListMap$KeySet_FieldInfo_[] = {
	{"m", "Ljava/util/concurrent/ConcurrentNavigableMap;", "Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $FINAL, $field(ConcurrentSkipListMap$KeySet, m)},
	{}
};

$MethodInfo _ConcurrentSkipListMap$KeySet_MethodInfo_[] = {
	{"*add", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*addAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/concurrent/ConcurrentNavigableMap;)V", "(Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;)V", 0, $method(ConcurrentSkipListMap$KeySet, init$, void, $ConcurrentNavigableMap*)},
	{"ceiling", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, ceiling, $Object*, Object$*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, clear, void)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, comparator, $Comparator*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, contains, bool, Object$*)},
	{"descendingIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, descendingIterator, $Iterator*)},
	{"descendingSet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, descendingSet, $NavigableSet*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, equals, bool, Object$*)},
	{"first", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, first, $Object*)},
	{"floor", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, floor, $Object*, Object$*)},
	{"headSet", "(Ljava/lang/Object;Z)Ljava/util/NavigableSet;", "(TK;Z)Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, headSet, $NavigableSet*, Object$*, bool)},
	{"headSet", "(Ljava/lang/Object;)Ljava/util/NavigableSet;", "(TK;)Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, headSet, $SortedSet*, Object$*)},
	{"higher", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, higher, $Object*, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, iterator, $Iterator*)},
	{"last", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, last, $Object*)},
	{"lower", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, lower, $Object*, Object$*)},
	{"*parallelStream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"pollFirst", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, pollFirst, $Object*)},
	{"pollLast", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, pollLast, $Object*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, remove, bool, Object$*)},
	{"*removeAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"*removeIf", "(Ljava/util/function/Predicate;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*retainAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, spliterator, $Spliterator*)},
	{"*stream", "()Ljava/util/stream/Stream;", nullptr, $PUBLIC | $ABSTRACT},
	{"subSet", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/NavigableSet;", "(TK;ZTK;Z)Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, subSet, $NavigableSet*, Object$*, bool, Object$*, bool)},
	{"subSet", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/NavigableSet;", "(TK;TK;)Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, subSet, $SortedSet*, Object$*, Object$*)},
	{"tailSet", "(Ljava/lang/Object;Z)Ljava/util/NavigableSet;", "(TK;Z)Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, tailSet, $NavigableSet*, Object$*, bool)},
	{"tailSet", "(Ljava/lang/Object;)Ljava/util/NavigableSet;", "(TK;)Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, tailSet, $SortedSet*, Object$*)},
	{"*toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$KeySet, toArray, $ObjectArray*, $ObjectArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ConcurrentSkipListMap$KeySet_InnerClassesInfo_[] = {
	{"java.util.concurrent.ConcurrentSkipListMap$KeySet", "java.util.concurrent.ConcurrentSkipListMap", "KeySet", $STATIC | $FINAL},
	{}
};

$ClassInfo _ConcurrentSkipListMap$KeySet_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.ConcurrentSkipListMap$KeySet",
	"java.util.AbstractSet",
	"java.util.NavigableSet",
	_ConcurrentSkipListMap$KeySet_FieldInfo_,
	_ConcurrentSkipListMap$KeySet_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractSet<TK;>;Ljava/util/NavigableSet<TK;>;",
	nullptr,
	_ConcurrentSkipListMap$KeySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.ConcurrentSkipListMap"
};

$Object* allocate$ConcurrentSkipListMap$KeySet($Class* clazz) {
	return $of($alloc(ConcurrentSkipListMap$KeySet));
}

int32_t ConcurrentSkipListMap$KeySet::hashCode() {
	 return this->$AbstractSet::hashCode();
}

bool ConcurrentSkipListMap$KeySet::removeAll($Collection* c) {
	 return this->$AbstractSet::removeAll(c);
}

bool ConcurrentSkipListMap$KeySet::add(Object$* e) {
	 return this->$AbstractSet::add(e);
}

bool ConcurrentSkipListMap$KeySet::containsAll($Collection* c) {
	 return this->$AbstractSet::containsAll(c);
}

bool ConcurrentSkipListMap$KeySet::addAll($Collection* c) {
	 return this->$AbstractSet::addAll(c);
}

bool ConcurrentSkipListMap$KeySet::retainAll($Collection* c) {
	 return this->$AbstractSet::retainAll(c);
}

$String* ConcurrentSkipListMap$KeySet::toString() {
	 return this->$AbstractSet::toString();
}

$ObjectArray* ConcurrentSkipListMap$KeySet::toArray($IntFunction* generator) {
	 return this->$AbstractSet::toArray(generator);
}

bool ConcurrentSkipListMap$KeySet::removeIf($Predicate* filter) {
	 return this->$AbstractSet::removeIf(filter);
}

$Stream* ConcurrentSkipListMap$KeySet::stream() {
	 return this->$AbstractSet::stream();
}

$Stream* ConcurrentSkipListMap$KeySet::parallelStream() {
	 return this->$AbstractSet::parallelStream();
}

void ConcurrentSkipListMap$KeySet::forEach($Consumer* action) {
	this->$AbstractSet::forEach(action);
}

$Object* ConcurrentSkipListMap$KeySet::clone() {
	 return this->$AbstractSet::clone();
}

void ConcurrentSkipListMap$KeySet::finalize() {
	this->$AbstractSet::finalize();
}

void ConcurrentSkipListMap$KeySet::init$($ConcurrentNavigableMap* map) {
	$AbstractSet::init$();
	$set(this, m, map);
}

int32_t ConcurrentSkipListMap$KeySet::size() {
	return $nc(this->m)->size();
}

bool ConcurrentSkipListMap$KeySet::isEmpty() {
	return $nc(this->m)->isEmpty();
}

bool ConcurrentSkipListMap$KeySet::contains(Object$* o) {
	return $nc(this->m)->containsKey(o);
}

bool ConcurrentSkipListMap$KeySet::remove(Object$* o) {
	return $nc(this->m)->remove(o) != nullptr;
}

void ConcurrentSkipListMap$KeySet::clear() {
	$nc(this->m)->clear();
}

$Object* ConcurrentSkipListMap$KeySet::lower(Object$* e) {
	return $of($nc(this->m)->lowerKey(e));
}

$Object* ConcurrentSkipListMap$KeySet::floor(Object$* e) {
	return $of($nc(this->m)->floorKey(e));
}

$Object* ConcurrentSkipListMap$KeySet::ceiling(Object$* e) {
	return $of($nc(this->m)->ceilingKey(e));
}

$Object* ConcurrentSkipListMap$KeySet::higher(Object$* e) {
	return $of($nc(this->m)->higherKey(e));
}

$Comparator* ConcurrentSkipListMap$KeySet::comparator() {
	return $nc(this->m)->comparator();
}

$Object* ConcurrentSkipListMap$KeySet::first() {
	return $of($nc(this->m)->firstKey());
}

$Object* ConcurrentSkipListMap$KeySet::last() {
	return $of($nc(this->m)->lastKey());
}

$Object* ConcurrentSkipListMap$KeySet::pollFirst() {
	$var($Map$Entry, e, $nc(this->m)->pollFirstEntry());
	return $of((e == nullptr) ? ($Object*)nullptr : $nc(e)->getKey());
}

$Object* ConcurrentSkipListMap$KeySet::pollLast() {
	$var($Map$Entry, e, $nc(this->m)->pollLastEntry());
	return $of((e == nullptr) ? ($Object*)nullptr : $nc(e)->getKey());
}

$Iterator* ConcurrentSkipListMap$KeySet::iterator() {
	return ($instanceOf($ConcurrentSkipListMap, this->m)) ? static_cast<$Iterator*>($new($ConcurrentSkipListMap$KeyIterator, static_cast<$ConcurrentSkipListMap*>($nc(($cast($ConcurrentSkipListMap, this->m)))))) : static_cast<$Iterator*>($new($ConcurrentSkipListMap$SubMap$SubMapKeyIterator, static_cast<$ConcurrentSkipListMap$SubMap*>($nc(($cast($ConcurrentSkipListMap$SubMap, this->m))))));
}

bool ConcurrentSkipListMap$KeySet::equals(Object$* o) {
	if ($equals(o, this)) {
		return true;
	}
	if (!($instanceOf($Set, o))) {
		return false;
	}
	$var($Collection, c, $cast($Collection, o));
	try {
		bool var$0 = containsAll(c);
		return var$0 && $nc(c)->containsAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this))));
	} catch ($ClassCastException& unused) {
		return false;
	} catch ($NullPointerException& unused) {
		return false;
	}
	$shouldNotReachHere();
}

$ObjectArray* ConcurrentSkipListMap$KeySet::toArray() {
	return $nc($($ConcurrentSkipListMap::toList(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this))))))->toArray();
}

$ObjectArray* ConcurrentSkipListMap$KeySet::toArray($ObjectArray* a) {
	return $nc($($ConcurrentSkipListMap::toList(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this))))))->toArray(a);
}

$Iterator* ConcurrentSkipListMap$KeySet::descendingIterator() {
	return $nc($(descendingSet()))->iterator();
}

$NavigableSet* ConcurrentSkipListMap$KeySet::subSet(Object$* fromElement, bool fromInclusive, Object$* toElement, bool toInclusive) {
	return $new(ConcurrentSkipListMap$KeySet, $($cast($ConcurrentNavigableMap, $nc(this->m)->subMap(fromElement, fromInclusive, toElement, toInclusive))));
}

$NavigableSet* ConcurrentSkipListMap$KeySet::headSet(Object$* toElement, bool inclusive) {
	return $new(ConcurrentSkipListMap$KeySet, $($cast($ConcurrentNavigableMap, $nc(this->m)->headMap(toElement, inclusive))));
}

$NavigableSet* ConcurrentSkipListMap$KeySet::tailSet(Object$* fromElement, bool inclusive) {
	return $new(ConcurrentSkipListMap$KeySet, $($cast($ConcurrentNavigableMap, $nc(this->m)->tailMap(fromElement, inclusive))));
}

$SortedSet* ConcurrentSkipListMap$KeySet::subSet(Object$* fromElement, Object$* toElement) {
	return subSet(fromElement, true, toElement, false);
}

$SortedSet* ConcurrentSkipListMap$KeySet::headSet(Object$* toElement) {
	return headSet(toElement, false);
}

$SortedSet* ConcurrentSkipListMap$KeySet::tailSet(Object$* fromElement) {
	return tailSet(fromElement, true);
}

$NavigableSet* ConcurrentSkipListMap$KeySet::descendingSet() {
	return $new(ConcurrentSkipListMap$KeySet, $($cast($ConcurrentNavigableMap, $nc(this->m)->descendingMap())));
}

$Spliterator* ConcurrentSkipListMap$KeySet::spliterator() {
	return ($instanceOf($ConcurrentSkipListMap, this->m)) ? static_cast<$Spliterator*>($nc(($cast($ConcurrentSkipListMap, this->m)))->keySpliterator()) : static_cast<$Spliterator*>($new($ConcurrentSkipListMap$SubMap$SubMapKeyIterator, static_cast<$ConcurrentSkipListMap$SubMap*>($nc(($cast($ConcurrentSkipListMap$SubMap, this->m))))));
}

ConcurrentSkipListMap$KeySet::ConcurrentSkipListMap$KeySet() {
}

$Class* ConcurrentSkipListMap$KeySet::load$($String* name, bool initialize) {
	$loadClass(ConcurrentSkipListMap$KeySet, name, initialize, &_ConcurrentSkipListMap$KeySet_ClassInfo_, allocate$ConcurrentSkipListMap$KeySet);
	return class$;
}

$Class* ConcurrentSkipListMap$KeySet::class$ = nullptr;

		} // concurrent
	} // util
} // java