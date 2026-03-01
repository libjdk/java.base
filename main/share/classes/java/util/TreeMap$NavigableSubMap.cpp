#include <java/util/TreeMap$NavigableSubMap.h>

#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/Spliterator.h>
#include <java/util/TreeMap$Entry.h>
#include <java/util/TreeMap$KeySet.h>
#include <java/util/TreeMap$NavigableSubMap$EntrySetView.h>
#include <java/util/TreeMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableMap = ::java::util::NavigableMap;
using $NavigableSet = ::java::util::NavigableSet;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $Spliterator = ::java::util::Spliterator;
using $TreeMap = ::java::util::TreeMap;
using $TreeMap$Entry = ::java::util::TreeMap$Entry;
using $TreeMap$KeySet = ::java::util::TreeMap$KeySet;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;

namespace java {
	namespace util {

$FieldInfo _TreeMap$NavigableSubMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TreeMap$NavigableSubMap, serialVersionUID)},
	{"m", "Ljava/util/TreeMap;", "Ljava/util/TreeMap<TK;TV;>;", $FINAL, $field(TreeMap$NavigableSubMap, m)},
	{"lo", "Ljava/lang/Object;", "TK;", $FINAL, $field(TreeMap$NavigableSubMap, lo)},
	{"hi", "Ljava/lang/Object;", "TK;", $FINAL, $field(TreeMap$NavigableSubMap, hi)},
	{"fromStart", "Z", nullptr, $FINAL, $field(TreeMap$NavigableSubMap, fromStart)},
	{"toEnd", "Z", nullptr, $FINAL, $field(TreeMap$NavigableSubMap, toEnd)},
	{"loInclusive", "Z", nullptr, $FINAL, $field(TreeMap$NavigableSubMap, loInclusive)},
	{"hiInclusive", "Z", nullptr, $FINAL, $field(TreeMap$NavigableSubMap, hiInclusive)},
	{"descendingMapView", "Ljava/util/NavigableMap;", "Ljava/util/NavigableMap<TK;TV;>;", $TRANSIENT, $field(TreeMap$NavigableSubMap, descendingMapView)},
	{"entrySetView", "Ljava/util/TreeMap$NavigableSubMap$EntrySetView;", "Ljava/util/TreeMap$NavigableSubMap<TK;TV;>.EntrySetView;", $TRANSIENT, $field(TreeMap$NavigableSubMap, entrySetView)},
	{"navigableKeySetView", "Ljava/util/TreeMap$KeySet;", "Ljava/util/TreeMap$KeySet<TK;>;", $TRANSIENT, $field(TreeMap$NavigableSubMap, navigableKeySetView)},
	{}
};

$MethodInfo _TreeMap$NavigableSubMap_MethodInfo_[] = {
	{"*clear", "()V", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED},
	{"*containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*entrySet", "()Ljava/util/Set;", nullptr, $PUBLIC | $ABSTRACT},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/TreeMap;ZLjava/lang/Object;ZZLjava/lang/Object;Z)V", "(Ljava/util/TreeMap<TK;TV;>;ZTK;ZZTK;Z)V", 0, $method(TreeMap$NavigableSubMap, init$, void, $TreeMap*, bool, Object$*, bool, bool, Object$*, bool)},
	{"absCeiling", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absCeiling, $TreeMap$Entry*, Object$*)},
	{"absFloor", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absFloor, $TreeMap$Entry*, Object$*)},
	{"absHighFence", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absHighFence, $TreeMap$Entry*)},
	{"absHigher", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absHigher, $TreeMap$Entry*, Object$*)},
	{"absHighest", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absHighest, $TreeMap$Entry*)},
	{"absLowFence", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absLowFence, $TreeMap$Entry*)},
	{"absLower", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absLower, $TreeMap$Entry*, Object$*)},
	{"absLowest", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", $FINAL, $method(TreeMap$NavigableSubMap, absLowest, $TreeMap$Entry*)},
	{"ceilingEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, ceilingEntry, $Map$Entry*, Object$*)},
	{"ceilingKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, ceilingKey, $Object*, Object$*)},
	{"compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, compute, $Object*, Object$*, $BiFunction*)},
	{"computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(TK;Ljava/util/function/Function<-TK;+TV;>;)TV;", $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, computeIfAbsent, $Object*, Object$*, $Function*)},
	{"computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;Ljava/util/function/BiFunction<-TK;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, computeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, containsKey, bool, Object$*)},
	{"descendingKeyIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, descendingKeyIterator, $Iterator*)},
	{"descendingKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, descendingKeySet, $NavigableSet*)},
	{"firstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, firstEntry, $Map$Entry*)},
	{"firstKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, firstKey, $Object*)},
	{"floorEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, floorEntry, $Map$Entry*, Object$*)},
	{"floorKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, floorKey, $Object*, Object$*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, get, $Object*, Object$*)},
	{"headMap", "(Ljava/lang/Object;)Ljava/util/SortedMap;", "(TK;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, headMap, $SortedMap*, Object$*)},
	{"higherEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, higherEntry, $Map$Entry*, Object$*)},
	{"higherKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, higherKey, $Object*, Object$*)},
	{"inClosedRange", "(Ljava/lang/Object;)Z", nullptr, $FINAL, $method(TreeMap$NavigableSubMap, inClosedRange, bool, Object$*)},
	{"inRange", "(Ljava/lang/Object;)Z", nullptr, $FINAL, $method(TreeMap$NavigableSubMap, inRange, bool, Object$*)},
	{"inRange", "(Ljava/lang/Object;Z)Z", nullptr, $FINAL, $method(TreeMap$NavigableSubMap, inRange, bool, Object$*, bool)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, isEmpty, bool)},
	{"keyIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, keyIterator, $Iterator*)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<TK;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, keySet, $Set*)},
	{"keySpliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TK;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, keySpliterator, $Spliterator*)},
	{"lastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, lastEntry, $Map$Entry*)},
	{"lastKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, lastKey, $Object*)},
	{"lowerEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, lowerEntry, $Map$Entry*, Object$*)},
	{"lowerKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, lowerKey, $Object*, Object$*)},
	{"merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(TK;TV;Ljava/util/function/BiFunction<-TV;-TV;+TV;>;)TV;", $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, merge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"navigableKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, navigableKeySet, $NavigableSet*)},
	{"pollFirstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, pollFirstEntry, $Map$Entry*)},
	{"pollLastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, pollLastEntry, $Map$Entry*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, put, $Object*, Object$*, Object$*)},
	{"*putAll", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "(TK;TV;)TV;", $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, putIfAbsent, $Object*, Object$*, Object$*)},
	{"*remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Object;)TV;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, remove, $Object*, Object$*)},
	{"*replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*replaceAll", "(Ljava/util/function/BiFunction;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(TreeMap$NavigableSubMap, size, int32_t)},
	{"subCeiling", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, subCeiling, $TreeMap$Entry*, Object$*)},
	{"subFloor", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, subFloor, $TreeMap$Entry*, Object$*)},
	{"subHigher", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, subHigher, $TreeMap$Entry*, Object$*)},
	{"subHighest", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, subHighest, $TreeMap$Entry*)},
	{"subLower", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, subLower, $TreeMap$Entry*, Object$*)},
	{"subLowest", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", $ABSTRACT, $virtualMethod(TreeMap$NavigableSubMap, subLowest, $TreeMap$Entry*)},
	{"subMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/SortedMap;", "(TK;TK;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, subMap, $SortedMap*, Object$*, Object$*)},
	{"tailMap", "(Ljava/lang/Object;)Ljava/util/SortedMap;", "(TK;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC | $FINAL, $virtualMethod(TreeMap$NavigableSubMap, tailMap, $SortedMap*, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tooHigh", "(Ljava/lang/Object;)Z", nullptr, $FINAL, $method(TreeMap$NavigableSubMap, tooHigh, bool, Object$*)},
	{"tooLow", "(Ljava/lang/Object;)Z", nullptr, $FINAL, $method(TreeMap$NavigableSubMap, tooLow, bool, Object$*)},
	{"*values", "()Ljava/util/Collection;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TreeMap$NavigableSubMap_InnerClassesInfo_[] = {
	{"java.util.TreeMap$NavigableSubMap", "java.util.TreeMap", "NavigableSubMap", $STATIC | $ABSTRACT},
	{"java.util.TreeMap$NavigableSubMap$DescendingSubMapKeyIterator", "java.util.TreeMap$NavigableSubMap", "DescendingSubMapKeyIterator", $FINAL},
	{"java.util.TreeMap$NavigableSubMap$SubMapKeyIterator", "java.util.TreeMap$NavigableSubMap", "SubMapKeyIterator", $FINAL},
	{"java.util.TreeMap$NavigableSubMap$DescendingSubMapEntryIterator", "java.util.TreeMap$NavigableSubMap", "DescendingSubMapEntryIterator", $FINAL},
	{"java.util.TreeMap$NavigableSubMap$SubMapEntryIterator", "java.util.TreeMap$NavigableSubMap", "SubMapEntryIterator", $FINAL},
	{"java.util.TreeMap$NavigableSubMap$SubMapIterator", "java.util.TreeMap$NavigableSubMap", "SubMapIterator", $ABSTRACT},
	{"java.util.TreeMap$NavigableSubMap$EntrySetView", "java.util.TreeMap$NavigableSubMap", "EntrySetView", $ABSTRACT},
	{}
};

$ClassInfo _TreeMap$NavigableSubMap_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.TreeMap$NavigableSubMap",
	"java.util.AbstractMap",
	"java.util.NavigableMap,java.io.Serializable",
	_TreeMap$NavigableSubMap_FieldInfo_,
	_TreeMap$NavigableSubMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractMap<TK;TV;>;Ljava/util/NavigableMap<TK;TV;>;Ljava/io/Serializable;",
	nullptr,
	_TreeMap$NavigableSubMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.TreeMap"
};

$Object* allocate$TreeMap$NavigableSubMap($Class* clazz) {
	return $of($alloc(TreeMap$NavigableSubMap));
}

bool TreeMap$NavigableSubMap::containsValue(Object$* value) {
	 return this->$AbstractMap::containsValue(value);
}

void TreeMap$NavigableSubMap::putAll($Map* m) {
	this->$AbstractMap::putAll(m);
}

void TreeMap$NavigableSubMap::clear() {
	this->$AbstractMap::clear();
}

$Collection* TreeMap$NavigableSubMap::values() {
	 return this->$AbstractMap::values();
}

bool TreeMap$NavigableSubMap::equals(Object$* o) {
	 return this->$AbstractMap::equals(o);
}

int32_t TreeMap$NavigableSubMap::hashCode() {
	 return this->$AbstractMap::hashCode();
}

$String* TreeMap$NavigableSubMap::toString() {
	 return this->$AbstractMap::toString();
}

$Object* TreeMap$NavigableSubMap::clone() {
	 return this->$AbstractMap::clone();
}

$Object* TreeMap$NavigableSubMap::getOrDefault(Object$* key, Object$* defaultValue) {
	 return this->$AbstractMap::getOrDefault(key, defaultValue);
}

void TreeMap$NavigableSubMap::forEach($BiConsumer* action) {
	this->$AbstractMap::forEach(action);
}

void TreeMap$NavigableSubMap::replaceAll($BiFunction* function) {
	this->$AbstractMap::replaceAll(function);
}

bool TreeMap$NavigableSubMap::remove(Object$* key, Object$* value) {
	 return this->$AbstractMap::remove(key, value);
}

bool TreeMap$NavigableSubMap::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	 return this->$AbstractMap::replace(key, oldValue, newValue);
}

$Object* TreeMap$NavigableSubMap::replace(Object$* key, Object$* value) {
	 return this->$AbstractMap::replace(key, value);
}

void TreeMap$NavigableSubMap::finalize() {
	this->$AbstractMap::finalize();
}

void TreeMap$NavigableSubMap::init$($TreeMap* m, bool fromStart, Object$* lo, bool loInclusive, bool toEnd, Object$* hi, bool hiInclusive) {
	$AbstractMap::init$();
	if (!fromStart && !toEnd) {
		if ($nc(m)->compare(lo, hi) > 0) {
			$throwNew($IllegalArgumentException, "fromKey > toKey"_s);
		}
	} else {
		if (!fromStart) {
			$nc(m)->compare(lo, lo);
		}
		if (!toEnd) {
			$nc(m)->compare(hi, hi);
		}
	}
	$set(this, m, m);
	this->fromStart = fromStart;
	$set(this, lo, lo);
	this->loInclusive = loInclusive;
	this->toEnd = toEnd;
	$set(this, hi, hi);
	this->hiInclusive = hiInclusive;
}

bool TreeMap$NavigableSubMap::tooLow(Object$* key) {
	if (!this->fromStart) {
		int32_t c = $nc(this->m)->compare(key, this->lo);
		if (c < 0 || (c == 0 && !this->loInclusive)) {
			return true;
		}
	}
	return false;
}

bool TreeMap$NavigableSubMap::tooHigh(Object$* key) {
	if (!this->toEnd) {
		int32_t c = $nc(this->m)->compare(key, this->hi);
		if (c > 0 || (c == 0 && !this->hiInclusive)) {
			return true;
		}
	}
	return false;
}

bool TreeMap$NavigableSubMap::inRange(Object$* key) {
	bool var$0 = !tooLow(key);
	return var$0 && !tooHigh(key);
}

bool TreeMap$NavigableSubMap::inClosedRange(Object$* key) {
	bool var$0 = (this->fromStart || $nc(this->m)->compare(key, this->lo) >= 0);
	return var$0 && (this->toEnd || $nc(this->m)->compare(this->hi, key) >= 0);
}

bool TreeMap$NavigableSubMap::inRange(Object$* key, bool inclusive) {
	return inclusive ? inRange(key) : inClosedRange(key);
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absLowest() {
	$var($TreeMap$Entry, e, this->fromStart ? $nc(this->m)->getFirstEntry() : (this->loInclusive ? $nc(this->m)->getCeilingEntry(this->lo) : $nc(this->m)->getHigherEntry(this->lo)));
	return (e == nullptr || tooHigh($nc(e)->key)) ? ($TreeMap$Entry*)nullptr : e;
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absHighest() {
	$var($TreeMap$Entry, e, this->toEnd ? $nc(this->m)->getLastEntry() : (this->hiInclusive ? $nc(this->m)->getFloorEntry(this->hi) : $nc(this->m)->getLowerEntry(this->hi)));
	return (e == nullptr || tooLow($nc(e)->key)) ? ($TreeMap$Entry*)nullptr : e;
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absCeiling(Object$* key) {
	if (tooLow(key)) {
		return absLowest();
	}
	$var($TreeMap$Entry, e, $nc(this->m)->getCeilingEntry(key));
	return (e == nullptr || tooHigh($nc(e)->key)) ? ($TreeMap$Entry*)nullptr : e;
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absHigher(Object$* key) {
	if (tooLow(key)) {
		return absLowest();
	}
	$var($TreeMap$Entry, e, $nc(this->m)->getHigherEntry(key));
	return (e == nullptr || tooHigh($nc(e)->key)) ? ($TreeMap$Entry*)nullptr : e;
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absFloor(Object$* key) {
	if (tooHigh(key)) {
		return absHighest();
	}
	$var($TreeMap$Entry, e, $nc(this->m)->getFloorEntry(key));
	return (e == nullptr || tooLow($nc(e)->key)) ? ($TreeMap$Entry*)nullptr : e;
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absLower(Object$* key) {
	if (tooHigh(key)) {
		return absHighest();
	}
	$var($TreeMap$Entry, e, $nc(this->m)->getLowerEntry(key));
	return (e == nullptr || tooLow($nc(e)->key)) ? ($TreeMap$Entry*)nullptr : e;
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absHighFence() {
	return (this->toEnd ? ($TreeMap$Entry*)nullptr : (this->hiInclusive ? $nc(this->m)->getHigherEntry(this->hi) : $nc(this->m)->getCeilingEntry(this->hi)));
}

$TreeMap$Entry* TreeMap$NavigableSubMap::absLowFence() {
	return (this->fromStart ? ($TreeMap$Entry*)nullptr : (this->loInclusive ? $nc(this->m)->getLowerEntry(this->lo) : $nc(this->m)->getFloorEntry(this->lo)));
}

bool TreeMap$NavigableSubMap::isEmpty() {
	return (this->fromStart && this->toEnd) ? $nc(this->m)->isEmpty() : $nc($(entrySet()))->isEmpty();
}

int32_t TreeMap$NavigableSubMap::size() {
	return (this->fromStart && this->toEnd) ? $nc(this->m)->size() : $nc($(entrySet()))->size();
}

bool TreeMap$NavigableSubMap::containsKey(Object$* key) {
	bool var$0 = inRange(key);
	return var$0 && $nc(this->m)->containsKey(key);
}

$Object* TreeMap$NavigableSubMap::put(Object$* key, Object$* value) {
	if (!inRange(key)) {
		$throwNew($IllegalArgumentException, "key out of range"_s);
	}
	return $of($nc(this->m)->put(key, value));
}

$Object* TreeMap$NavigableSubMap::putIfAbsent(Object$* key, Object$* value) {
	if (!inRange(key)) {
		$throwNew($IllegalArgumentException, "key out of range"_s);
	}
	return $of($nc(this->m)->putIfAbsent(key, value));
}

$Object* TreeMap$NavigableSubMap::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	if (!inRange(key)) {
		$throwNew($IllegalArgumentException, "key out of range"_s);
	}
	return $of($nc(this->m)->merge(key, value, remappingFunction));
}

$Object* TreeMap$NavigableSubMap::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	if (!inRange(key)) {
		if ($nc(mappingFunction)->apply(key) == nullptr) {
			return $of(nullptr);
		}
		$throwNew($IllegalArgumentException, "key out of range"_s);
	}
	return $of($nc(this->m)->computeIfAbsent(key, mappingFunction));
}

$Object* TreeMap$NavigableSubMap::compute(Object$* key, $BiFunction* remappingFunction) {
	if (!inRange(key)) {
		if ($nc(remappingFunction)->apply(key, nullptr) == nullptr) {
			return $of(nullptr);
		}
		$throwNew($IllegalArgumentException, "key out of range"_s);
	}
	return $of($nc(this->m)->compute(key, remappingFunction));
}

$Object* TreeMap$NavigableSubMap::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	return $of(!inRange(key) ? ($Object*)nullptr : $nc(this->m)->computeIfPresent(key, remappingFunction));
}

$Object* TreeMap$NavigableSubMap::get(Object$* key) {
	return $of(!inRange(key) ? ($Object*)nullptr : $nc(this->m)->get(key));
}

$Object* TreeMap$NavigableSubMap::remove(Object$* key) {
	return $of(!inRange(key) ? ($Object*)nullptr : $nc(this->m)->remove(key));
}

$Map$Entry* TreeMap$NavigableSubMap::ceilingEntry(Object$* key) {
	return $TreeMap::exportEntry($(subCeiling(key)));
}

$Object* TreeMap$NavigableSubMap::ceilingKey(Object$* key) {
	return $of($TreeMap::keyOrNull($(subCeiling(key))));
}

$Map$Entry* TreeMap$NavigableSubMap::higherEntry(Object$* key) {
	return $TreeMap::exportEntry($(subHigher(key)));
}

$Object* TreeMap$NavigableSubMap::higherKey(Object$* key) {
	return $of($TreeMap::keyOrNull($(subHigher(key))));
}

$Map$Entry* TreeMap$NavigableSubMap::floorEntry(Object$* key) {
	return $TreeMap::exportEntry($(subFloor(key)));
}

$Object* TreeMap$NavigableSubMap::floorKey(Object$* key) {
	return $of($TreeMap::keyOrNull($(subFloor(key))));
}

$Map$Entry* TreeMap$NavigableSubMap::lowerEntry(Object$* key) {
	return $TreeMap::exportEntry($(subLower(key)));
}

$Object* TreeMap$NavigableSubMap::lowerKey(Object$* key) {
	return $of($TreeMap::keyOrNull($(subLower(key))));
}

$Object* TreeMap$NavigableSubMap::firstKey() {
	return $of($TreeMap::key($(subLowest())));
}

$Object* TreeMap$NavigableSubMap::lastKey() {
	return $of($TreeMap::key($(subHighest())));
}

$Map$Entry* TreeMap$NavigableSubMap::firstEntry() {
	return $TreeMap::exportEntry($(subLowest()));
}

$Map$Entry* TreeMap$NavigableSubMap::lastEntry() {
	return $TreeMap::exportEntry($(subHighest()));
}

$Map$Entry* TreeMap$NavigableSubMap::pollFirstEntry() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$Entry, e, subLowest());
	$var($Map$Entry, result, $TreeMap::exportEntry(e));
	if (e != nullptr) {
		$nc(this->m)->deleteEntry(e);
	}
	return result;
}

$Map$Entry* TreeMap$NavigableSubMap::pollLastEntry() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$Entry, e, subHighest());
	$var($Map$Entry, result, $TreeMap::exportEntry(e));
	if (e != nullptr) {
		$nc(this->m)->deleteEntry(e);
	}
	return result;
}

$NavigableSet* TreeMap$NavigableSubMap::navigableKeySet() {
	$var($TreeMap$KeySet, nksv, this->navigableKeySetView);
	return (nksv != nullptr) ? static_cast<$NavigableSet*>(nksv) : (static_cast<$NavigableSet*>(($set(this, navigableKeySetView, $new($TreeMap$KeySet, this)))));
}

$Set* TreeMap$NavigableSubMap::keySet() {
	return navigableKeySet();
}

$NavigableSet* TreeMap$NavigableSubMap::descendingKeySet() {
	return $nc($(descendingMap()))->navigableKeySet();
}

$SortedMap* TreeMap$NavigableSubMap::subMap(Object$* fromKey, Object$* toKey) {
	return subMap(fromKey, true, toKey, false);
}

$SortedMap* TreeMap$NavigableSubMap::headMap(Object$* toKey) {
	return headMap(toKey, false);
}

$SortedMap* TreeMap$NavigableSubMap::tailMap(Object$* fromKey) {
	return tailMap(fromKey, true);
}

TreeMap$NavigableSubMap::TreeMap$NavigableSubMap() {
}

$Class* TreeMap$NavigableSubMap::load$($String* name, bool initialize) {
	$loadClass(TreeMap$NavigableSubMap, name, initialize, &_TreeMap$NavigableSubMap_ClassInfo_, allocate$TreeMap$NavigableSubMap);
	return class$;
}

$Class* TreeMap$NavigableSubMap::class$ = nullptr;

	} // util
} // java