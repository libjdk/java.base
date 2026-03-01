#include <java/util/Collections$SynchronizedNavigableMap.h>

#include <java/util/Collection.h>
#include <java/util/Collections$SynchronizedMap.h>
#include <java/util/Collections$SynchronizedNavigableSet.h>
#include <java/util/Collections$SynchronizedSortedMap.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/NavigableMap.h>
#include <java/util/NavigableSet.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $Collections$SynchronizedNavigableSet = ::java::util::Collections$SynchronizedNavigableSet;
using $Collections$SynchronizedSortedMap = ::java::util::Collections$SynchronizedSortedMap;
using $Comparator = ::java::util::Comparator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $NavigableMap = ::java::util::NavigableMap;
using $NavigableSet = ::java::util::NavigableSet;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;

namespace java {
	namespace util {

$FieldInfo _Collections$SynchronizedNavigableMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections$SynchronizedNavigableMap, serialVersionUID)},
	{"nm", "Ljava/util/NavigableMap;", "Ljava/util/NavigableMap<TK;TV;>;", $PRIVATE | $FINAL, $field(Collections$SynchronizedNavigableMap, nm)},
	{}
};

$MethodInfo _Collections$SynchronizedNavigableMap_MethodInfo_[] = {
	{"*clear", "()V", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*comparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC},
	{"*compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*entrySet", "()Ljava/util/Set;", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*firstKey", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*forEach", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC},
	{"*get", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/NavigableMap;)V", "(Ljava/util/NavigableMap<TK;TV;>;)V", 0, $method(Collections$SynchronizedNavigableMap, init$, void, $NavigableMap*)},
	{"<init>", "(Ljava/util/NavigableMap;Ljava/lang/Object;)V", "(Ljava/util/NavigableMap<TK;TV;>;Ljava/lang/Object;)V", 0, $method(Collections$SynchronizedNavigableMap, init$, void, $NavigableMap*, Object$*)},
	{"ceilingEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, ceilingEntry, $Map$Entry*, Object$*)},
	{"ceilingKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, ceilingKey, $Object*, Object$*)},
	{"descendingKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, descendingKeySet, $NavigableSet*)},
	{"descendingMap", "()Ljava/util/NavigableMap;", "()Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, descendingMap, $NavigableMap*)},
	{"firstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, firstEntry, $Map$Entry*)},
	{"floorEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, floorEntry, $Map$Entry*, Object$*)},
	{"floorKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, floorKey, $Object*, Object$*)},
	{"headMap", "(Ljava/lang/Object;)Ljava/util/SortedMap;", "(TK;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, headMap, $SortedMap*, Object$*)},
	{"headMap", "(Ljava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, headMap, $NavigableMap*, Object$*, bool)},
	{"higherEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, higherEntry, $Map$Entry*, Object$*)},
	{"higherKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, higherKey, $Object*, Object$*)},
	{"*isEmpty", "()Z", nullptr, $PUBLIC},
	{"keySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, keySet, $Set*)},
	{"lastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, lastEntry, $Map$Entry*)},
	{"*lastKey", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"lowerEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, lowerEntry, $Map$Entry*, Object$*)},
	{"lowerKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, lowerKey, $Object*, Object$*)},
	{"*merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"navigableKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, navigableKeySet, $NavigableSet*)},
	{"pollFirstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, pollFirstEntry, $Map$Entry*)},
	{"pollLastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, pollLastEntry, $Map$Entry*)},
	{"*put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*putAll", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"*putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*remove", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*replaceAll", "(Ljava/util/function/BiFunction;)V", nullptr, $PUBLIC},
	{"*size", "()I", nullptr, $PUBLIC},
	{"subMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/SortedMap;", "(TK;TK;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, subMap, $SortedMap*, Object$*, Object$*)},
	{"subMap", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;ZTK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, subMap, $NavigableMap*, Object$*, bool, Object$*, bool)},
	{"tailMap", "(Ljava/lang/Object;)Ljava/util/SortedMap;", "(TK;)Ljava/util/SortedMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, tailMap, $SortedMap*, Object$*)},
	{"tailMap", "(Ljava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$SynchronizedNavigableMap, tailMap, $NavigableMap*, Object$*, bool)},
	{"*values", "()Ljava/util/Collection;", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Collections$SynchronizedNavigableMap_InnerClassesInfo_[] = {
	{"java.util.Collections$SynchronizedNavigableMap", "java.util.Collections", "SynchronizedNavigableMap", $STATIC},
	{"java.util.Collections$SynchronizedSortedMap", "java.util.Collections", "SynchronizedSortedMap", $STATIC},
	{}
};

$ClassInfo _Collections$SynchronizedNavigableMap_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.Collections$SynchronizedNavigableMap",
	"java.util.Collections$SynchronizedSortedMap",
	"java.util.NavigableMap",
	_Collections$SynchronizedNavigableMap_FieldInfo_,
	_Collections$SynchronizedNavigableMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/Collections$SynchronizedSortedMap<TK;TV;>;Ljava/util/NavigableMap<TK;TV;>;",
	nullptr,
	_Collections$SynchronizedNavigableMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Collections"
};

$Object* allocate$Collections$SynchronizedNavigableMap($Class* clazz) {
	return $of($alloc(Collections$SynchronizedNavigableMap));
}

$Comparator* Collections$SynchronizedNavigableMap::comparator() {
	 return this->$Collections$SynchronizedSortedMap::comparator();
}

$Object* Collections$SynchronizedNavigableMap::firstKey() {
	 return this->$Collections$SynchronizedSortedMap::firstKey();
}

$Object* Collections$SynchronizedNavigableMap::lastKey() {
	 return this->$Collections$SynchronizedSortedMap::lastKey();
}

int32_t Collections$SynchronizedNavigableMap::size() {
	 return this->$Collections$SynchronizedSortedMap::size();
}

bool Collections$SynchronizedNavigableMap::isEmpty() {
	 return this->$Collections$SynchronizedSortedMap::isEmpty();
}

bool Collections$SynchronizedNavigableMap::containsKey(Object$* key) {
	 return this->$Collections$SynchronizedSortedMap::containsKey(key);
}

bool Collections$SynchronizedNavigableMap::containsValue(Object$* value) {
	 return this->$Collections$SynchronizedSortedMap::containsValue(value);
}

$Object* Collections$SynchronizedNavigableMap::get(Object$* key) {
	 return this->$Collections$SynchronizedSortedMap::get(key);
}

$Object* Collections$SynchronizedNavigableMap::put(Object$* key, Object$* value) {
	 return this->$Collections$SynchronizedSortedMap::put(key, value);
}

$Object* Collections$SynchronizedNavigableMap::remove(Object$* key) {
	 return this->$Collections$SynchronizedSortedMap::remove(key);
}

void Collections$SynchronizedNavigableMap::putAll($Map* map) {
	this->$Collections$SynchronizedSortedMap::putAll(map);
}

void Collections$SynchronizedNavigableMap::clear() {
	this->$Collections$SynchronizedSortedMap::clear();
}

$Set* Collections$SynchronizedNavigableMap::entrySet() {
	 return this->$Collections$SynchronizedSortedMap::entrySet();
}

$Collection* Collections$SynchronizedNavigableMap::values() {
	 return this->$Collections$SynchronizedSortedMap::values();
}

bool Collections$SynchronizedNavigableMap::equals(Object$* o) {
	 return this->$Collections$SynchronizedSortedMap::equals(o);
}

int32_t Collections$SynchronizedNavigableMap::hashCode() {
	 return this->$Collections$SynchronizedSortedMap::hashCode();
}

$String* Collections$SynchronizedNavigableMap::toString() {
	 return this->$Collections$SynchronizedSortedMap::toString();
}

$Object* Collections$SynchronizedNavigableMap::getOrDefault(Object$* k, Object$* defaultValue) {
	 return this->$Collections$SynchronizedSortedMap::getOrDefault(k, defaultValue);
}

void Collections$SynchronizedNavigableMap::forEach($BiConsumer* action) {
	this->$Collections$SynchronizedSortedMap::forEach(action);
}

void Collections$SynchronizedNavigableMap::replaceAll($BiFunction* function) {
	this->$Collections$SynchronizedSortedMap::replaceAll(function);
}

$Object* Collections$SynchronizedNavigableMap::putIfAbsent(Object$* key, Object$* value) {
	 return this->$Collections$SynchronizedSortedMap::putIfAbsent(key, value);
}

bool Collections$SynchronizedNavigableMap::remove(Object$* key, Object$* value) {
	 return this->$Collections$SynchronizedSortedMap::remove(key, value);
}

bool Collections$SynchronizedNavigableMap::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	 return this->$Collections$SynchronizedSortedMap::replace(key, oldValue, newValue);
}

$Object* Collections$SynchronizedNavigableMap::replace(Object$* key, Object$* value) {
	 return this->$Collections$SynchronizedSortedMap::replace(key, value);
}

$Object* Collections$SynchronizedNavigableMap::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	 return this->$Collections$SynchronizedSortedMap::computeIfAbsent(key, mappingFunction);
}

$Object* Collections$SynchronizedNavigableMap::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	 return this->$Collections$SynchronizedSortedMap::computeIfPresent(key, remappingFunction);
}

$Object* Collections$SynchronizedNavigableMap::compute(Object$* key, $BiFunction* remappingFunction) {
	 return this->$Collections$SynchronizedSortedMap::compute(key, remappingFunction);
}

$Object* Collections$SynchronizedNavigableMap::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	 return this->$Collections$SynchronizedSortedMap::merge(key, value, remappingFunction);
}

$Object* Collections$SynchronizedNavigableMap::clone() {
	 return this->$Collections$SynchronizedSortedMap::clone();
}

void Collections$SynchronizedNavigableMap::finalize() {
	this->$Collections$SynchronizedSortedMap::finalize();
}

void Collections$SynchronizedNavigableMap::init$($NavigableMap* m) {
	$Collections$SynchronizedSortedMap::init$(m);
	$set(this, nm, m);
}

void Collections$SynchronizedNavigableMap::init$($NavigableMap* m, Object$* mutex) {
	$Collections$SynchronizedSortedMap::init$(m, mutex);
	$set(this, nm, m);
}

$Map$Entry* Collections$SynchronizedNavigableMap::lowerEntry(Object$* key) {
	$synchronized(this->mutex) {
		return $nc(this->nm)->lowerEntry(key);
	}
}

$Object* Collections$SynchronizedNavigableMap::lowerKey(Object$* key) {
	$synchronized(this->mutex) {
		return $of($nc(this->nm)->lowerKey(key));
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::floorEntry(Object$* key) {
	$synchronized(this->mutex) {
		return $nc(this->nm)->floorEntry(key);
	}
}

$Object* Collections$SynchronizedNavigableMap::floorKey(Object$* key) {
	$synchronized(this->mutex) {
		return $of($nc(this->nm)->floorKey(key));
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::ceilingEntry(Object$* key) {
	$synchronized(this->mutex) {
		return $nc(this->nm)->ceilingEntry(key);
	}
}

$Object* Collections$SynchronizedNavigableMap::ceilingKey(Object$* key) {
	$synchronized(this->mutex) {
		return $of($nc(this->nm)->ceilingKey(key));
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::higherEntry(Object$* key) {
	$synchronized(this->mutex) {
		return $nc(this->nm)->higherEntry(key);
	}
}

$Object* Collections$SynchronizedNavigableMap::higherKey(Object$* key) {
	$synchronized(this->mutex) {
		return $of($nc(this->nm)->higherKey(key));
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::firstEntry() {
	$synchronized(this->mutex) {
		return $nc(this->nm)->firstEntry();
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::lastEntry() {
	$synchronized(this->mutex) {
		return $nc(this->nm)->lastEntry();
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::pollFirstEntry() {
	$synchronized(this->mutex) {
		return $nc(this->nm)->pollFirstEntry();
	}
}

$Map$Entry* Collections$SynchronizedNavigableMap::pollLastEntry() {
	$synchronized(this->mutex) {
		return $nc(this->nm)->pollLastEntry();
	}
}

$NavigableMap* Collections$SynchronizedNavigableMap::descendingMap() {
	$synchronized(this->mutex) {
		return $new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->descendingMap()), this->mutex);
	}
}

$Set* Collections$SynchronizedNavigableMap::keySet() {
	return navigableKeySet();
}

$NavigableSet* Collections$SynchronizedNavigableMap::navigableKeySet() {
	$synchronized(this->mutex) {
		return $new($Collections$SynchronizedNavigableSet, $($nc(this->nm)->navigableKeySet()), this->mutex);
	}
}

$NavigableSet* Collections$SynchronizedNavigableMap::descendingKeySet() {
	$synchronized(this->mutex) {
		return $new($Collections$SynchronizedNavigableSet, $($nc(this->nm)->descendingKeySet()), this->mutex);
	}
}

$SortedMap* Collections$SynchronizedNavigableMap::subMap(Object$* fromKey, Object$* toKey) {
	$synchronized(this->mutex) {
		return static_cast<$SortedMap*>(static_cast<$Collections$SynchronizedSortedMap*>($new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->subMap(fromKey, true, toKey, false)), this->mutex)));
	}
}

$SortedMap* Collections$SynchronizedNavigableMap::headMap(Object$* toKey) {
	$synchronized(this->mutex) {
		return static_cast<$SortedMap*>(static_cast<$Collections$SynchronizedSortedMap*>($new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->headMap(toKey, false)), this->mutex)));
	}
}

$SortedMap* Collections$SynchronizedNavigableMap::tailMap(Object$* fromKey) {
	$synchronized(this->mutex) {
		return static_cast<$SortedMap*>(static_cast<$Collections$SynchronizedSortedMap*>($new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->tailMap(fromKey, true)), this->mutex)));
	}
}

$NavigableMap* Collections$SynchronizedNavigableMap::subMap(Object$* fromKey, bool fromInclusive, Object$* toKey, bool toInclusive) {
	$synchronized(this->mutex) {
		return $new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->subMap(fromKey, fromInclusive, toKey, toInclusive)), this->mutex);
	}
}

$NavigableMap* Collections$SynchronizedNavigableMap::headMap(Object$* toKey, bool inclusive) {
	$synchronized(this->mutex) {
		return $new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->headMap(toKey, inclusive)), this->mutex);
	}
}

$NavigableMap* Collections$SynchronizedNavigableMap::tailMap(Object$* fromKey, bool inclusive) {
	$synchronized(this->mutex) {
		return $new(Collections$SynchronizedNavigableMap, $($nc(this->nm)->tailMap(fromKey, inclusive)), this->mutex);
	}
}

Collections$SynchronizedNavigableMap::Collections$SynchronizedNavigableMap() {
}

$Class* Collections$SynchronizedNavigableMap::load$($String* name, bool initialize) {
	$loadClass(Collections$SynchronizedNavigableMap, name, initialize, &_Collections$SynchronizedNavigableMap_ClassInfo_, allocate$Collections$SynchronizedNavigableMap);
	return class$;
}

$Class* Collections$SynchronizedNavigableMap::class$ = nullptr;

	} // util
} // java