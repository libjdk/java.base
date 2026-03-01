#include <java/util/concurrent/ConcurrentSkipListMap$SubMap.h>

#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/concurrent/ConcurrentNavigableMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap$EntrySet.h>
#include <java/util/concurrent/ConcurrentSkipListMap$KeySet.h>
#include <java/util/concurrent/ConcurrentSkipListMap$Node.h>
#include <java/util/concurrent/ConcurrentSkipListMap$Values.h>
#include <java/util/concurrent/ConcurrentSkipListMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jcpp.h>

#undef MAX_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableMap = ::java::util::NavigableMap;
using $NavigableSet = ::java::util::NavigableSet;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $ConcurrentNavigableMap = ::java::util::concurrent::ConcurrentNavigableMap;
using $ConcurrentSkipListMap = ::java::util::concurrent::ConcurrentSkipListMap;
using $ConcurrentSkipListMap$EntrySet = ::java::util::concurrent::ConcurrentSkipListMap$EntrySet;
using $ConcurrentSkipListMap$KeySet = ::java::util::concurrent::ConcurrentSkipListMap$KeySet;
using $ConcurrentSkipListMap$Node = ::java::util::concurrent::ConcurrentSkipListMap$Node;
using $ConcurrentSkipListMap$Values = ::java::util::concurrent::ConcurrentSkipListMap$Values;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ConcurrentSkipListMap$SubMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConcurrentSkipListMap$SubMap, serialVersionUID)},
	{"m", "Ljava/util/concurrent/ConcurrentSkipListMap;", "Ljava/util/concurrent/ConcurrentSkipListMap<TK;TV;>;", $FINAL, $field(ConcurrentSkipListMap$SubMap, m)},
	{"lo", "Ljava/lang/Object;", "TK;", $PRIVATE | $FINAL, $field(ConcurrentSkipListMap$SubMap, lo)},
	{"hi", "Ljava/lang/Object;", "TK;", $PRIVATE | $FINAL, $field(ConcurrentSkipListMap$SubMap, hi)},
	{"loInclusive", "Z", nullptr, $PRIVATE | $FINAL, $field(ConcurrentSkipListMap$SubMap, loInclusive)},
	{"hiInclusive", "Z", nullptr, $PRIVATE | $FINAL, $field(ConcurrentSkipListMap$SubMap, hiInclusive)},
	{"isDescending", "Z", nullptr, $FINAL, $field(ConcurrentSkipListMap$SubMap, isDescending)},
	{"keySetView", "Ljava/util/concurrent/ConcurrentSkipListMap$KeySet;", "Ljava/util/concurrent/ConcurrentSkipListMap$KeySet<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap$SubMap, keySetView)},
	{"valuesView", "Ljava/util/concurrent/ConcurrentSkipListMap$Values;", "Ljava/util/concurrent/ConcurrentSkipListMap$Values<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap$SubMap, valuesView)},
	{"entrySetView", "Ljava/util/concurrent/ConcurrentSkipListMap$EntrySet;", "Ljava/util/concurrent/ConcurrentSkipListMap$EntrySet<TK;TV;>;", $PRIVATE | $TRANSIENT, $field(ConcurrentSkipListMap$SubMap, entrySetView)},
	{}
};

$MethodInfo _ConcurrentSkipListMap$SubMap_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED},
	{"*compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/concurrent/ConcurrentSkipListMap;Ljava/lang/Object;ZLjava/lang/Object;ZZ)V", "(Ljava/util/concurrent/ConcurrentSkipListMap<TK;TV;>;TK;ZTK;ZZ)V", 0, $method(ConcurrentSkipListMap$SubMap, init$, void, $ConcurrentSkipListMap*, Object$*, bool, Object$*, bool, bool)},
	{"ceilingEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, ceilingEntry, $Map$Entry*, Object$*)},
	{"ceilingKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, ceilingKey, $Object*, Object$*)},
	{"checkKeyBounds", "(Ljava/lang/Object;Ljava/util/Comparator;)V", "(TK;Ljava/util/Comparator<-TK;>;)V", 0, $method(ConcurrentSkipListMap$SubMap, checkKeyBounds, void, Object$*, $Comparator*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, clear, void)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, comparator, $Comparator*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, containsValue, bool, Object$*)},
	{"descendingKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, descendingKeySet, $NavigableSet*)},
	{"descendingMap", "()Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "()Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, descendingMap, $NavigableMap*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, entrySet, $Set*)},
	{"firstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, firstEntry, $Map$Entry*)},
	{"firstKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, firstKey, $Object*)},
	{"floorEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, floorEntry, $Map$Entry*, Object$*)},
	{"floorKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, floorKey, $Object*, Object$*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, get, $Object*, Object$*)},
	{"getNearEntry", "(Ljava/lang/Object;I)Ljava/util/Map$Entry;", "(TK;I)Ljava/util/Map$Entry<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, getNearEntry, $Map$Entry*, Object$*, int32_t)},
	{"getNearKey", "(Ljava/lang/Object;I)Ljava/lang/Object;", "(TK;I)TK;", 0, $method(ConcurrentSkipListMap$SubMap, getNearKey, $Object*, Object$*, int32_t)},
	{"headMap", "(Ljava/lang/Object;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, headMap, $NavigableMap*, Object$*, bool)},
	{"headMap", "(Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, headMap, $SortedMap*, Object$*)},
	{"hiNode", "(Ljava/util/Comparator;)Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "(Ljava/util/Comparator<-TK;>;)Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, hiNode, $ConcurrentSkipListMap$Node*, $Comparator*)},
	{"higherEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, higherEntry, $Map$Entry*, Object$*)},
	{"higherKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, higherKey, $Object*, Object$*)},
	{"highestEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, highestEntry, $Map$Entry*)},
	{"highestKey", "()Ljava/lang/Object;", "()TK;", 0, $method(ConcurrentSkipListMap$SubMap, highestKey, $Object*)},
	{"inBounds", "(Ljava/lang/Object;Ljava/util/Comparator;)Z", "(Ljava/lang/Object;Ljava/util/Comparator<-TK;>;)Z", 0, $method(ConcurrentSkipListMap$SubMap, inBounds, bool, Object$*, $Comparator*)},
	{"isBeforeEnd", "(Ljava/util/concurrent/ConcurrentSkipListMap$Node;Ljava/util/Comparator;)Z", "(Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;Ljava/util/Comparator<-TK;>;)Z", 0, $method(ConcurrentSkipListMap$SubMap, isBeforeEnd, bool, $ConcurrentSkipListMap$Node*, $Comparator*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, isEmpty, bool)},
	{"keySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, keySet, $Set*)},
	{"lastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, lastEntry, $Map$Entry*)},
	{"lastKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, lastKey, $Object*)},
	{"loNode", "(Ljava/util/Comparator;)Ljava/util/concurrent/ConcurrentSkipListMap$Node;", "(Ljava/util/Comparator<-TK;>;)Ljava/util/concurrent/ConcurrentSkipListMap$Node<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, loNode, $ConcurrentSkipListMap$Node*, $Comparator*)},
	{"lowerEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, lowerEntry, $Map$Entry*, Object$*)},
	{"lowerKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, lowerKey, $Object*, Object$*)},
	{"lowestEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, lowestEntry, $Map$Entry*)},
	{"lowestKey", "()Ljava/lang/Object;", "()TK;", 0, $method(ConcurrentSkipListMap$SubMap, lowestKey, $Object*)},
	{"*merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"navigableKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, navigableKeySet, $NavigableSet*)},
	{"newSubMap", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;ZTK;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, newSubMap, ConcurrentSkipListMap$SubMap*, Object$*, bool, Object$*, bool)},
	{"pollFirstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, pollFirstEntry, $Map$Entry*)},
	{"pollLastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, pollLastEntry, $Map$Entry*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, put, $Object*, Object$*, Object$*)},
	{"*putAll", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, putIfAbsent, $Object*, Object$*, Object$*)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, remove, $Object*, Object$*)},
	{"remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, remove, bool, Object$*, Object$*)},
	{"removeHighest", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, removeHighest, $Map$Entry*)},
	{"removeLowest", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", 0, $method(ConcurrentSkipListMap$SubMap, removeLowest, $Map$Entry*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", "(TK;TV;TV;)Z", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, replace, bool, Object$*, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, replace, $Object*, Object$*, Object$*)},
	{"*replaceAll", "(Ljava/util/function/BiFunction;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, size, int32_t)},
	{"subMap", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;ZTK;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, subMap, $NavigableMap*, Object$*, bool, Object$*, bool)},
	{"subMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;TK;)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, subMap, $SortedMap*, Object$*, Object$*)},
	{"tailMap", "(Ljava/lang/Object;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;Z)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, tailMap, $NavigableMap*, Object$*, bool)},
	{"tailMap", "(Ljava/lang/Object;)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap;", "(TK;)Ljava/util/concurrent/ConcurrentSkipListMap$SubMap<TK;TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, tailMap, $SortedMap*, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tooHigh", "(Ljava/lang/Object;Ljava/util/Comparator;)Z", "(Ljava/lang/Object;Ljava/util/Comparator<-TK;>;)Z", 0, $method(ConcurrentSkipListMap$SubMap, tooHigh, bool, Object$*, $Comparator*)},
	{"tooLow", "(Ljava/lang/Object;Ljava/util/Comparator;)Z", "(Ljava/lang/Object;Ljava/util/Comparator<-TK;>;)Z", 0, $method(ConcurrentSkipListMap$SubMap, tooLow, bool, Object$*, $Comparator*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<TV;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$SubMap, values, $Collection*)},
	{}
};

$InnerClassInfo _ConcurrentSkipListMap$SubMap_InnerClassesInfo_[] = {
	{"java.util.concurrent.ConcurrentSkipListMap$SubMap", "java.util.concurrent.ConcurrentSkipListMap", "SubMap", $STATIC | $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapEntryIterator", "java.util.concurrent.ConcurrentSkipListMap$SubMap", "SubMapEntryIterator", $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapKeyIterator", "java.util.concurrent.ConcurrentSkipListMap$SubMap", "SubMapKeyIterator", $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapValueIterator", "java.util.concurrent.ConcurrentSkipListMap$SubMap", "SubMapValueIterator", $FINAL},
	{"java.util.concurrent.ConcurrentSkipListMap$SubMap$SubMapIter", "java.util.concurrent.ConcurrentSkipListMap$SubMap", "SubMapIter", $ABSTRACT},
	{}
};

$ClassInfo _ConcurrentSkipListMap$SubMap_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.ConcurrentSkipListMap$SubMap",
	"java.util.AbstractMap",
	"java.util.concurrent.ConcurrentNavigableMap,java.io.Serializable",
	_ConcurrentSkipListMap$SubMap_FieldInfo_,
	_ConcurrentSkipListMap$SubMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;Ljava/io/Serializable;",
	nullptr,
	_ConcurrentSkipListMap$SubMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.ConcurrentSkipListMap"
};

$Object* allocate$ConcurrentSkipListMap$SubMap($Class* clazz) {
	return $of($alloc(ConcurrentSkipListMap$SubMap));
}

void ConcurrentSkipListMap$SubMap::putAll($Map* m) {
	this->$AbstractMap::putAll(m);
}

bool ConcurrentSkipListMap$SubMap::equals(Object$* o) {
	 return this->$AbstractMap::equals(o);
}

int32_t ConcurrentSkipListMap$SubMap::hashCode() {
	 return this->$AbstractMap::hashCode();
}

$String* ConcurrentSkipListMap$SubMap::toString() {
	 return this->$AbstractMap::toString();
}

$Object* ConcurrentSkipListMap$SubMap::clone() {
	 return this->$AbstractMap::clone();
}

$Object* ConcurrentSkipListMap$SubMap::getOrDefault(Object$* key, Object$* defaultValue) {
	 return this->$AbstractMap::getOrDefault(key, defaultValue);
}

void ConcurrentSkipListMap$SubMap::forEach($BiConsumer* action) {
	this->$AbstractMap::forEach(action);
}

void ConcurrentSkipListMap$SubMap::replaceAll($BiFunction* function) {
	this->$AbstractMap::replaceAll(function);
}

$Object* ConcurrentSkipListMap$SubMap::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	 return this->$AbstractMap::computeIfAbsent(key, mappingFunction);
}

$Object* ConcurrentSkipListMap$SubMap::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	 return this->$AbstractMap::computeIfPresent(key, remappingFunction);
}

$Object* ConcurrentSkipListMap$SubMap::compute(Object$* key, $BiFunction* remappingFunction) {
	 return this->$AbstractMap::compute(key, remappingFunction);
}

$Object* ConcurrentSkipListMap$SubMap::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	 return this->$AbstractMap::merge(key, value, remappingFunction);
}

void ConcurrentSkipListMap$SubMap::finalize() {
	this->$AbstractMap::finalize();
}

void ConcurrentSkipListMap$SubMap::init$($ConcurrentSkipListMap* map, Object$* fromKey, bool fromInclusive, Object$* toKey, bool toInclusive, bool isDescending) {
	$AbstractMap::init$();
	$var($Comparator, cmp, $nc(map)->comparator$);
	if (fromKey != nullptr && toKey != nullptr && $ConcurrentSkipListMap::cpr(cmp, fromKey, toKey) > 0) {
		$throwNew($IllegalArgumentException, "inconsistent range"_s);
	}
	$set(this, m, map);
	$set(this, lo, fromKey);
	$set(this, hi, toKey);
	this->loInclusive = fromInclusive;
	this->hiInclusive = toInclusive;
	this->isDescending = isDescending;
}

bool ConcurrentSkipListMap$SubMap::tooLow(Object$* key, $Comparator* cmp) {
	int32_t c = 0;
	bool var$0 = this->lo != nullptr;
	if (var$0) {
		bool var$1 = (c = $ConcurrentSkipListMap::cpr(cmp, key, this->lo)) < 0;
		var$0 = (var$1 || (c == 0 && !this->loInclusive));
	}
	return (var$0);
}

bool ConcurrentSkipListMap$SubMap::tooHigh(Object$* key, $Comparator* cmp) {
	int32_t c = 0;
	bool var$0 = this->hi != nullptr;
	if (var$0) {
		bool var$1 = (c = $ConcurrentSkipListMap::cpr(cmp, key, this->hi)) > 0;
		var$0 = (var$1 || (c == 0 && !this->hiInclusive));
	}
	return (var$0);
}

bool ConcurrentSkipListMap$SubMap::inBounds(Object$* key, $Comparator* cmp) {
	bool var$0 = !tooLow(key, cmp);
	return var$0 && !tooHigh(key, cmp);
}

void ConcurrentSkipListMap$SubMap::checkKeyBounds(Object$* key, $Comparator* cmp) {
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!inBounds(key, cmp)) {
		$throwNew($IllegalArgumentException, "key out of range"_s);
	}
}

bool ConcurrentSkipListMap$SubMap::isBeforeEnd($ConcurrentSkipListMap$Node* n, $Comparator* cmp) {
	if (n == nullptr) {
		return false;
	}
	if (this->hi == nullptr) {
		return true;
	}
	$var($Object, k, $nc(n)->key);
	if (k == nullptr) {
		return true;
	}
	int32_t c = $ConcurrentSkipListMap::cpr(cmp, k, this->hi);
	return c < 0 || (c == 0 && this->hiInclusive);
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap$SubMap::loNode($Comparator* cmp) {
	if (this->lo == nullptr) {
		return $nc(this->m)->findFirst();
	} else if (this->loInclusive) {
		return $nc(this->m)->findNear(this->lo, 0 | 1, cmp);
	} else {
		return $nc(this->m)->findNear(this->lo, 0, cmp);
	}
}

$ConcurrentSkipListMap$Node* ConcurrentSkipListMap$SubMap::hiNode($Comparator* cmp) {
	if (this->hi == nullptr) {
		return $nc(this->m)->findLast();
	} else if (this->hiInclusive) {
		return $nc(this->m)->findNear(this->hi, 2 | 1, cmp);
	} else {
		return $nc(this->m)->findNear(this->hi, 2, cmp);
	}
}

$Object* ConcurrentSkipListMap$SubMap::lowestKey() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	$var($ConcurrentSkipListMap$Node, n, loNode(cmp));
	if (isBeforeEnd(n, cmp)) {
		return $of($nc(n)->key);
	} else {
		$throwNew($NoSuchElementException);
	}
}

$Object* ConcurrentSkipListMap$SubMap::highestKey() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	$var($ConcurrentSkipListMap$Node, n, hiNode(cmp));
	if (n != nullptr) {
		$var($Object, last, n->key);
		if (inBounds(last, cmp)) {
			return $of(last);
		}
	}
	$throwNew($NoSuchElementException);
}

$Map$Entry* ConcurrentSkipListMap$SubMap::lowestEntry() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		bool var$0 = ($assign(n, loNode(cmp))) == nullptr;
		if (var$0 || !isBeforeEnd(n, cmp)) {
			return nullptr;
		} else if (($assign(v, $nc(n)->val)) != nullptr) {
			return $new($AbstractMap$SimpleImmutableEntry, n->key, v);
		}
	}
}

$Map$Entry* ConcurrentSkipListMap$SubMap::highestEntry() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, v, nullptr);
		bool var$0 = ($assign(n, hiNode(cmp))) == nullptr;
		if (var$0 || !inBounds($nc(n)->key, cmp)) {
			return nullptr;
		} else if (($assign(v, $nc(n)->val)) != nullptr) {
			return $new($AbstractMap$SimpleImmutableEntry, n->key, v);
		}
	}
}

$Map$Entry* ConcurrentSkipListMap$SubMap::removeLowest() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, k, nullptr);
		$var($Object, v, nullptr);
		if (($assign(n, loNode(cmp))) == nullptr) {
			return nullptr;
		} else if (!inBounds(($assign(k, $nc(n)->key)), cmp)) {
			return nullptr;
		} else if (($assign(v, $nc(this->m)->doRemove(k, nullptr))) != nullptr) {
			return $new($AbstractMap$SimpleImmutableEntry, k, v);
		}
	}
}

$Map$Entry* ConcurrentSkipListMap$SubMap::removeHighest() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, nullptr);
		$var($Object, k, nullptr);
		$var($Object, v, nullptr);
		if (($assign(n, hiNode(cmp))) == nullptr) {
			return nullptr;
		} else if (!inBounds(($assign(k, $nc(n)->key)), cmp)) {
			return nullptr;
		} else if (($assign(v, $nc(this->m)->doRemove(k, nullptr))) != nullptr) {
			return $new($AbstractMap$SimpleImmutableEntry, k, v);
		}
	}
}

$Map$Entry* ConcurrentSkipListMap$SubMap::getNearEntry(Object$* key, int32_t rel) {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	if (this->isDescending) {
		if (((int32_t)(rel & (uint32_t)2)) == 0) {
			rel |= 2;
		} else {
			rel &= (uint32_t)~2;
		}
	}
	if (tooLow(key, cmp)) {
		return (((int32_t)(rel & (uint32_t)2)) != 0) ? ($Map$Entry*)nullptr : lowestEntry();
	}
	if (tooHigh(key, cmp)) {
		return (((int32_t)(rel & (uint32_t)2)) != 0) ? highestEntry() : ($Map$Entry*)nullptr;
	}
	$var($AbstractMap$SimpleImmutableEntry, e, $nc(this->m)->findNearEntry(key, rel, cmp));
	if (e == nullptr || !inBounds($($nc(e)->getKey()), cmp)) {
		return nullptr;
	} else {
		return e;
	}
}

$Object* ConcurrentSkipListMap$SubMap::getNearKey(Object$* key, int32_t rel) {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	if (this->isDescending) {
		if (((int32_t)(rel & (uint32_t)2)) == 0) {
			rel |= 2;
		} else {
			rel &= (uint32_t)~2;
		}
	}
	if (tooLow(key, cmp)) {
		if (((int32_t)(rel & (uint32_t)2)) == 0) {
			$var($ConcurrentSkipListMap$Node, n, loNode(cmp));
			if (isBeforeEnd(n, cmp)) {
				return $of($nc(n)->key);
			}
		}
		return $of(nullptr);
	}
	if (tooHigh(key, cmp)) {
		if (((int32_t)(rel & (uint32_t)2)) != 0) {
			$var($ConcurrentSkipListMap$Node, n, hiNode(cmp));
			if (n != nullptr) {
				$var($Object, last, n->key);
				if (inBounds(last, cmp)) {
					return $of(last);
				}
			}
		}
		return $of(nullptr);
	}
	for (;;) {
		$var($ConcurrentSkipListMap$Node, n, $nc(this->m)->findNear(key, rel, cmp));
		if (n == nullptr || !inBounds($nc(n)->key, cmp)) {
			return $of(nullptr);
		}
		if ($nc(n)->val != nullptr) {
			return $of(n->key);
		}
	}
}

bool ConcurrentSkipListMap$SubMap::containsKey(Object$* key) {
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	bool var$0 = inBounds(key, $nc(this->m)->comparator$);
	return var$0 && $nc(this->m)->containsKey(key);
}

$Object* ConcurrentSkipListMap$SubMap::get(Object$* key) {
	if (key == nullptr) {
		$throwNew($NullPointerException);
	}
	return $of((!inBounds(key, $nc(this->m)->comparator$)) ? ($Object*)nullptr : $nc(this->m)->get(key));
}

$Object* ConcurrentSkipListMap$SubMap::put(Object$* key, Object$* value) {
	checkKeyBounds(key, $nc(this->m)->comparator$);
	return $of($nc(this->m)->put(key, value));
}

$Object* ConcurrentSkipListMap$SubMap::remove(Object$* key) {
	return $of((!inBounds(key, $nc(this->m)->comparator$)) ? ($Object*)nullptr : $nc(this->m)->remove(key));
}

int32_t ConcurrentSkipListMap$SubMap::size() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	int64_t count = 0;
	{
		$var($ConcurrentSkipListMap$Node, n, loNode(cmp));
		for (; isBeforeEnd(n, cmp); $assign(n, $nc(n)->next)) {
			if (n->val != nullptr) {
				++count;
			}
		}
	}
	return count >= $Integer::MAX_VALUE ? $Integer::MAX_VALUE : (int32_t)count;
}

bool ConcurrentSkipListMap$SubMap::isEmpty() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	return !isBeforeEnd($(loNode(cmp)), cmp);
}

bool ConcurrentSkipListMap$SubMap::containsValue(Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	{
		$var($ConcurrentSkipListMap$Node, n, loNode(cmp));
		for (; isBeforeEnd(n, cmp); $assign(n, $nc(n)->next)) {
			$var($Object, v, n->val);
			if (v != nullptr && $nc($of(value))->equals(v)) {
				return true;
			}
		}
	}
	return false;
}

void ConcurrentSkipListMap$SubMap::clear() {
	$useLocalCurrentObjectStackCache();
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	{
		$var($ConcurrentSkipListMap$Node, n, loNode(cmp));
		for (; isBeforeEnd(n, cmp); $assign(n, $nc(n)->next)) {
			if (n->val != nullptr) {
				$nc(this->m)->remove(n->key);
			}
		}
	}
}

$Object* ConcurrentSkipListMap$SubMap::putIfAbsent(Object$* key, Object$* value) {
	checkKeyBounds(key, $nc(this->m)->comparator$);
	return $of($nc(this->m)->putIfAbsent(key, value));
}

bool ConcurrentSkipListMap$SubMap::remove(Object$* key, Object$* value) {
	bool var$0 = inBounds(key, $nc(this->m)->comparator$);
	return var$0 && $nc(this->m)->remove(key, value);
}

bool ConcurrentSkipListMap$SubMap::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	checkKeyBounds(key, $nc(this->m)->comparator$);
	return $nc(this->m)->replace(key, oldValue, newValue);
}

$Object* ConcurrentSkipListMap$SubMap::replace(Object$* key, Object$* value) {
	checkKeyBounds(key, $nc(this->m)->comparator$);
	return $of($nc(this->m)->replace(key, value));
}

$Comparator* ConcurrentSkipListMap$SubMap::comparator() {
	$var($Comparator, cmp, $nc(this->m)->comparator());
	if (this->isDescending) {
		return $Collections::reverseOrder(cmp);
	} else {
		return cmp;
	}
}

ConcurrentSkipListMap$SubMap* ConcurrentSkipListMap$SubMap::newSubMap(Object$* fromKey$renamed, bool fromInclusive, Object$* toKey$renamed, bool toInclusive) {
	$useLocalCurrentObjectStackCache();
	$var($Object, toKey, toKey$renamed);
	$var($Object, fromKey, fromKey$renamed);
	$var($Comparator, cmp, $nc(this->m)->comparator$);
	if (this->isDescending) {
		$var($Object, tk, fromKey);
		$assign(fromKey, toKey);
		$assign(toKey, tk);
		bool ti = fromInclusive;
		fromInclusive = toInclusive;
		toInclusive = ti;
	}
	if (this->lo != nullptr) {
		if (fromKey == nullptr) {
			$assign(fromKey, this->lo);
			fromInclusive = this->loInclusive;
		} else {
			int32_t c = $ConcurrentSkipListMap::cpr(cmp, fromKey, this->lo);
			if (c < 0 || (c == 0 && !this->loInclusive && fromInclusive)) {
				$throwNew($IllegalArgumentException, "key out of range"_s);
			}
		}
	}
	if (this->hi != nullptr) {
		if (toKey == nullptr) {
			$assign(toKey, this->hi);
			toInclusive = this->hiInclusive;
		} else {
			int32_t c = $ConcurrentSkipListMap::cpr(cmp, toKey, this->hi);
			if (c > 0 || (c == 0 && !this->hiInclusive && toInclusive)) {
				$throwNew($IllegalArgumentException, "key out of range"_s);
			}
		}
	}
	return $new(ConcurrentSkipListMap$SubMap, this->m, fromKey, fromInclusive, toKey, toInclusive, this->isDescending);
}

$NavigableMap* ConcurrentSkipListMap$SubMap::subMap(Object$* fromKey, bool fromInclusive, Object$* toKey, bool toInclusive) {
	if (fromKey == nullptr || toKey == nullptr) {
		$throwNew($NullPointerException);
	}
	return newSubMap(fromKey, fromInclusive, toKey, toInclusive);
}

$NavigableMap* ConcurrentSkipListMap$SubMap::headMap(Object$* toKey, bool inclusive) {
	if (toKey == nullptr) {
		$throwNew($NullPointerException);
	}
	return newSubMap(nullptr, false, toKey, inclusive);
}

$NavigableMap* ConcurrentSkipListMap$SubMap::tailMap(Object$* fromKey, bool inclusive) {
	if (fromKey == nullptr) {
		$throwNew($NullPointerException);
	}
	return newSubMap(fromKey, inclusive, nullptr, false);
}

$SortedMap* ConcurrentSkipListMap$SubMap::subMap(Object$* fromKey, Object$* toKey) {
	return subMap(fromKey, true, toKey, false);
}

$SortedMap* ConcurrentSkipListMap$SubMap::headMap(Object$* toKey) {
	return headMap(toKey, false);
}

$SortedMap* ConcurrentSkipListMap$SubMap::tailMap(Object$* fromKey) {
	return tailMap(fromKey, true);
}

$NavigableMap* ConcurrentSkipListMap$SubMap::descendingMap() {
	return $new(ConcurrentSkipListMap$SubMap, this->m, this->lo, this->loInclusive, this->hi, this->hiInclusive, !this->isDescending);
}

$Map$Entry* ConcurrentSkipListMap$SubMap::ceilingEntry(Object$* key) {
	return getNearEntry(key, 0 | 1);
}

$Object* ConcurrentSkipListMap$SubMap::ceilingKey(Object$* key) {
	return $of(getNearKey(key, 0 | 1));
}

$Map$Entry* ConcurrentSkipListMap$SubMap::lowerEntry(Object$* key) {
	return getNearEntry(key, 2);
}

$Object* ConcurrentSkipListMap$SubMap::lowerKey(Object$* key) {
	return $of(getNearKey(key, 2));
}

$Map$Entry* ConcurrentSkipListMap$SubMap::floorEntry(Object$* key) {
	return getNearEntry(key, 2 | 1);
}

$Object* ConcurrentSkipListMap$SubMap::floorKey(Object$* key) {
	return $of(getNearKey(key, 2 | 1));
}

$Map$Entry* ConcurrentSkipListMap$SubMap::higherEntry(Object$* key) {
	return getNearEntry(key, 0);
}

$Object* ConcurrentSkipListMap$SubMap::higherKey(Object$* key) {
	return $of(getNearKey(key, 0));
}

$Object* ConcurrentSkipListMap$SubMap::firstKey() {
	return $of(this->isDescending ? highestKey() : lowestKey());
}

$Object* ConcurrentSkipListMap$SubMap::lastKey() {
	return $of(this->isDescending ? lowestKey() : highestKey());
}

$Map$Entry* ConcurrentSkipListMap$SubMap::firstEntry() {
	return this->isDescending ? highestEntry() : lowestEntry();
}

$Map$Entry* ConcurrentSkipListMap$SubMap::lastEntry() {
	return this->isDescending ? lowestEntry() : highestEntry();
}

$Map$Entry* ConcurrentSkipListMap$SubMap::pollFirstEntry() {
	return this->isDescending ? removeHighest() : removeLowest();
}

$Map$Entry* ConcurrentSkipListMap$SubMap::pollLastEntry() {
	return this->isDescending ? removeLowest() : removeHighest();
}

$Set* ConcurrentSkipListMap$SubMap::keySet() {
	$var($ConcurrentSkipListMap$KeySet, ks, nullptr);
	if (($assign(ks, this->keySetView)) != nullptr) {
		return static_cast<$Set*>(static_cast<$AbstractSet*>(ks));
	}
	return static_cast<$Set*>(static_cast<$AbstractSet*>(($set(this, keySetView, $new($ConcurrentSkipListMap$KeySet, this)))));
}

$NavigableSet* ConcurrentSkipListMap$SubMap::navigableKeySet() {
	$var($ConcurrentSkipListMap$KeySet, ks, nullptr);
	if (($assign(ks, this->keySetView)) != nullptr) {
		return ks;
	}
	return ($set(this, keySetView, $new($ConcurrentSkipListMap$KeySet, this)));
}

$Collection* ConcurrentSkipListMap$SubMap::values() {
	$var($ConcurrentSkipListMap$Values, vs, nullptr);
	if (($assign(vs, this->valuesView)) != nullptr) {
		return vs;
	}
	return ($set(this, valuesView, $new($ConcurrentSkipListMap$Values, this)));
}

$Set* ConcurrentSkipListMap$SubMap::entrySet() {
	$var($ConcurrentSkipListMap$EntrySet, es, nullptr);
	if (($assign(es, this->entrySetView)) != nullptr) {
		return es;
	}
	return ($set(this, entrySetView, $new($ConcurrentSkipListMap$EntrySet, this)));
}

$NavigableSet* ConcurrentSkipListMap$SubMap::descendingKeySet() {
	return $nc($($cast(ConcurrentSkipListMap$SubMap, descendingMap())))->navigableKeySet();
}

ConcurrentSkipListMap$SubMap::ConcurrentSkipListMap$SubMap() {
}

$Class* ConcurrentSkipListMap$SubMap::load$($String* name, bool initialize) {
	$loadClass(ConcurrentSkipListMap$SubMap, name, initialize, &_ConcurrentSkipListMap$SubMap_ClassInfo_, allocate$ConcurrentSkipListMap$SubMap);
	return class$;
}

$Class* ConcurrentSkipListMap$SubMap::class$ = nullptr;

		} // concurrent
	} // util
} // java