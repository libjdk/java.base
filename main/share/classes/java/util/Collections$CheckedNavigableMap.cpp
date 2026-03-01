#include <java/util/Collections$CheckedNavigableMap.h>

#include <java/util/Collection.h>
#include <java/util/Collections$CheckedMap$CheckedEntrySet$CheckedEntry.h>
#include <java/util/Collections$CheckedMap.h>
#include <java/util/Collections$CheckedSortedMap.h>
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
using $Collections = ::java::util::Collections;
using $Collections$CheckedMap$CheckedEntrySet$CheckedEntry = ::java::util::Collections$CheckedMap$CheckedEntrySet$CheckedEntry;
using $Collections$CheckedSortedMap = ::java::util::Collections$CheckedSortedMap;
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

$FieldInfo _Collections$CheckedNavigableMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Collections$CheckedNavigableMap, serialVersionUID)},
	{"nm", "Ljava/util/NavigableMap;", "Ljava/util/NavigableMap<TK;TV;>;", $PRIVATE | $FINAL, $field(Collections$CheckedNavigableMap, nm)},
	{}
};

$MethodInfo _Collections$CheckedNavigableMap_MethodInfo_[] = {
	{"*clear", "()V", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*entrySet", "()Ljava/util/Set;", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC},
	{"*get", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/NavigableMap;Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/util/NavigableMap<TK;TV;>;Ljava/lang/Class<TK;>;Ljava/lang/Class<TV;>;)V", 0, $method(Collections$CheckedNavigableMap, init$, void, $NavigableMap*, $Class*, $Class*)},
	{"ceilingEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, ceilingEntry, $Map$Entry*, Object$*)},
	{"ceilingKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, ceilingKey, $Object*, Object$*)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TK;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, comparator, $Comparator*)},
	{"descendingKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, descendingKeySet, $NavigableSet*)},
	{"descendingMap", "()Ljava/util/NavigableMap;", "()Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, descendingMap, $NavigableMap*)},
	{"firstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, firstEntry, $Map$Entry*)},
	{"firstKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, firstKey, $Object*)},
	{"floorEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, floorEntry, $Map$Entry*, Object$*)},
	{"floorKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, floorKey, $Object*, Object$*)},
	{"headMap", "(Ljava/lang/Object;)Ljava/util/NavigableMap;", "(TK;)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, headMap, $SortedMap*, Object$*)},
	{"headMap", "(Ljava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, headMap, $NavigableMap*, Object$*, bool)},
	{"higherEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, higherEntry, $Map$Entry*, Object$*)},
	{"higherKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, higherKey, $Object*, Object$*)},
	{"*isEmpty", "()Z", nullptr, $PUBLIC},
	{"keySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, keySet, $Set*)},
	{"lastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, lastEntry, $Map$Entry*)},
	{"lastKey", "()Ljava/lang/Object;", "()TK;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, lastKey, $Object*)},
	{"lowerEntry", "(Ljava/lang/Object;)Ljava/util/Map$Entry;", "(TK;)Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, lowerEntry, $Map$Entry*, Object$*)},
	{"lowerKey", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TK;)TK;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, lowerKey, $Object*, Object$*)},
	{"*merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"navigableKeySet", "()Ljava/util/NavigableSet;", "()Ljava/util/NavigableSet<TK;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, navigableKeySet, $NavigableSet*)},
	{"pollFirstEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, pollFirstEntry, $Map$Entry*)},
	{"pollLastEntry", "()Ljava/util/Map$Entry;", "()Ljava/util/Map$Entry<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, pollLastEntry, $Map$Entry*)},
	{"*put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*putAll", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"*putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*remove", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*replaceAll", "(Ljava/util/function/BiFunction;)V", nullptr, $PUBLIC},
	{"*size", "()I", nullptr, $PUBLIC},
	{"subMap", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/NavigableMap;", "(TK;TK;)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, subMap, $SortedMap*, Object$*, Object$*)},
	{"subMap", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;ZTK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, subMap, $NavigableMap*, Object$*, bool, Object$*, bool)},
	{"tailMap", "(Ljava/lang/Object;)Ljava/util/NavigableMap;", "(TK;)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, tailMap, $SortedMap*, Object$*)},
	{"tailMap", "(Ljava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(Collections$CheckedNavigableMap, tailMap, $NavigableMap*, Object$*, bool)},
	{"*values", "()Ljava/util/Collection;", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Collections$CheckedNavigableMap_InnerClassesInfo_[] = {
	{"java.util.Collections$CheckedNavigableMap", "java.util.Collections", "CheckedNavigableMap", $STATIC},
	{"java.util.Collections$CheckedSortedMap", "java.util.Collections", "CheckedSortedMap", $STATIC},
	{}
};

$ClassInfo _Collections$CheckedNavigableMap_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.Collections$CheckedNavigableMap",
	"java.util.Collections$CheckedSortedMap",
	"java.util.NavigableMap",
	_Collections$CheckedNavigableMap_FieldInfo_,
	_Collections$CheckedNavigableMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/Collections$CheckedSortedMap<TK;TV;>;Ljava/util/NavigableMap<TK;TV;>;Ljava/io/Serializable;",
	nullptr,
	_Collections$CheckedNavigableMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Collections"
};

$Object* allocate$Collections$CheckedNavigableMap($Class* clazz) {
	return $of($alloc(Collections$CheckedNavigableMap));
}

int32_t Collections$CheckedNavigableMap::size() {
	 return this->$Collections$CheckedSortedMap::size();
}

bool Collections$CheckedNavigableMap::isEmpty() {
	 return this->$Collections$CheckedSortedMap::isEmpty();
}

bool Collections$CheckedNavigableMap::containsKey(Object$* key) {
	 return this->$Collections$CheckedSortedMap::containsKey(key);
}

bool Collections$CheckedNavigableMap::containsValue(Object$* v) {
	 return this->$Collections$CheckedSortedMap::containsValue(v);
}

$Object* Collections$CheckedNavigableMap::get(Object$* key) {
	 return this->$Collections$CheckedSortedMap::get(key);
}

$Object* Collections$CheckedNavigableMap::remove(Object$* key) {
	 return this->$Collections$CheckedSortedMap::remove(key);
}

void Collections$CheckedNavigableMap::clear() {
	this->$Collections$CheckedSortedMap::clear();
}

$Collection* Collections$CheckedNavigableMap::values() {
	 return this->$Collections$CheckedSortedMap::values();
}

bool Collections$CheckedNavigableMap::equals(Object$* o) {
	 return this->$Collections$CheckedSortedMap::equals(o);
}

int32_t Collections$CheckedNavigableMap::hashCode() {
	 return this->$Collections$CheckedSortedMap::hashCode();
}

$String* Collections$CheckedNavigableMap::toString() {
	 return this->$Collections$CheckedSortedMap::toString();
}

$Object* Collections$CheckedNavigableMap::put(Object$* key, Object$* value) {
	 return this->$Collections$CheckedSortedMap::put(key, value);
}

void Collections$CheckedNavigableMap::putAll($Map* t) {
	this->$Collections$CheckedSortedMap::putAll(t);
}

$Set* Collections$CheckedNavigableMap::entrySet() {
	 return this->$Collections$CheckedSortedMap::entrySet();
}

void Collections$CheckedNavigableMap::forEach($BiConsumer* action) {
	this->$Collections$CheckedSortedMap::forEach(action);
}

void Collections$CheckedNavigableMap::replaceAll($BiFunction* function) {
	this->$Collections$CheckedSortedMap::replaceAll(function);
}

$Object* Collections$CheckedNavigableMap::putIfAbsent(Object$* key, Object$* value) {
	 return this->$Collections$CheckedSortedMap::putIfAbsent(key, value);
}

bool Collections$CheckedNavigableMap::remove(Object$* key, Object$* value) {
	 return this->$Collections$CheckedSortedMap::remove(key, value);
}

bool Collections$CheckedNavigableMap::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	 return this->$Collections$CheckedSortedMap::replace(key, oldValue, newValue);
}

$Object* Collections$CheckedNavigableMap::replace(Object$* key, Object$* value) {
	 return this->$Collections$CheckedSortedMap::replace(key, value);
}

$Object* Collections$CheckedNavigableMap::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	 return this->$Collections$CheckedSortedMap::computeIfAbsent(key, mappingFunction);
}

$Object* Collections$CheckedNavigableMap::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	 return this->$Collections$CheckedSortedMap::computeIfPresent(key, remappingFunction);
}

$Object* Collections$CheckedNavigableMap::compute(Object$* key, $BiFunction* remappingFunction) {
	 return this->$Collections$CheckedSortedMap::compute(key, remappingFunction);
}

$Object* Collections$CheckedNavigableMap::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	 return this->$Collections$CheckedSortedMap::merge(key, value, remappingFunction);
}

$Object* Collections$CheckedNavigableMap::getOrDefault(Object$* key, Object$* defaultValue) {
	 return this->$Collections$CheckedSortedMap::getOrDefault(key, defaultValue);
}

$Object* Collections$CheckedNavigableMap::clone() {
	 return this->$Collections$CheckedSortedMap::clone();
}

void Collections$CheckedNavigableMap::finalize() {
	this->$Collections$CheckedSortedMap::finalize();
}

void Collections$CheckedNavigableMap::init$($NavigableMap* m, $Class* keyType, $Class* valueType) {
	$Collections$CheckedSortedMap::init$(m, keyType, valueType);
	$set(this, nm, m);
}

$Comparator* Collections$CheckedNavigableMap::comparator() {
	return $nc(this->nm)->comparator();
}

$Object* Collections$CheckedNavigableMap::firstKey() {
	return $of($nc(this->nm)->firstKey());
}

$Object* Collections$CheckedNavigableMap::lastKey() {
	return $of($nc(this->nm)->lastKey());
}

$Map$Entry* Collections$CheckedNavigableMap::lowerEntry(Object$* key) {
	$var($Map$Entry, lower, $nc(this->nm)->lowerEntry(key));
	return (nullptr != lower) ? static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, lower, this->valueType)) : ($Map$Entry*)nullptr;
}

$Object* Collections$CheckedNavigableMap::lowerKey(Object$* key) {
	return $of($nc(this->nm)->lowerKey(key));
}

$Map$Entry* Collections$CheckedNavigableMap::floorEntry(Object$* key) {
	$var($Map$Entry, floor, $nc(this->nm)->floorEntry(key));
	return (nullptr != floor) ? static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, floor, this->valueType)) : ($Map$Entry*)nullptr;
}

$Object* Collections$CheckedNavigableMap::floorKey(Object$* key) {
	return $of($nc(this->nm)->floorKey(key));
}

$Map$Entry* Collections$CheckedNavigableMap::ceilingEntry(Object$* key) {
	$var($Map$Entry, ceiling, $nc(this->nm)->ceilingEntry(key));
	return (nullptr != ceiling) ? static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, ceiling, this->valueType)) : ($Map$Entry*)nullptr;
}

$Object* Collections$CheckedNavigableMap::ceilingKey(Object$* key) {
	return $of($nc(this->nm)->ceilingKey(key));
}

$Map$Entry* Collections$CheckedNavigableMap::higherEntry(Object$* key) {
	$var($Map$Entry, higher, $nc(this->nm)->higherEntry(key));
	return (nullptr != higher) ? static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, higher, this->valueType)) : ($Map$Entry*)nullptr;
}

$Object* Collections$CheckedNavigableMap::higherKey(Object$* key) {
	return $of($nc(this->nm)->higherKey(key));
}

$Map$Entry* Collections$CheckedNavigableMap::firstEntry() {
	$var($Map$Entry, first, $nc(this->nm)->firstEntry());
	return (nullptr != first) ? static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, first, this->valueType)) : ($Map$Entry*)nullptr;
}

$Map$Entry* Collections$CheckedNavigableMap::lastEntry() {
	$var($Map$Entry, last, $nc(this->nm)->lastEntry());
	return (nullptr != last) ? static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, last, this->valueType)) : ($Map$Entry*)nullptr;
}

$Map$Entry* Collections$CheckedNavigableMap::pollFirstEntry() {
	$var($Map$Entry, entry, $nc(this->nm)->pollFirstEntry());
	return (nullptr == entry) ? ($Map$Entry*)nullptr : static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, entry, this->valueType));
}

$Map$Entry* Collections$CheckedNavigableMap::pollLastEntry() {
	$var($Map$Entry, entry, $nc(this->nm)->pollLastEntry());
	return (nullptr == entry) ? ($Map$Entry*)nullptr : static_cast<$Map$Entry*>($new($Collections$CheckedMap$CheckedEntrySet$CheckedEntry, entry, this->valueType));
}

$NavigableMap* Collections$CheckedNavigableMap::descendingMap() {
	return $Collections::checkedNavigableMap($($nc(this->nm)->descendingMap()), this->keyType, this->valueType);
}

$Set* Collections$CheckedNavigableMap::keySet() {
	return navigableKeySet();
}

$NavigableSet* Collections$CheckedNavigableMap::navigableKeySet() {
	return $Collections::checkedNavigableSet($($nc(this->nm)->navigableKeySet()), this->keyType);
}

$NavigableSet* Collections$CheckedNavigableMap::descendingKeySet() {
	return $Collections::checkedNavigableSet($($nc(this->nm)->descendingKeySet()), this->keyType);
}

$SortedMap* Collections$CheckedNavigableMap::subMap(Object$* fromKey, Object$* toKey) {
	return $Collections::checkedNavigableMap($($nc(this->nm)->subMap(fromKey, true, toKey, false)), this->keyType, this->valueType);
}

$SortedMap* Collections$CheckedNavigableMap::headMap(Object$* toKey) {
	return $Collections::checkedNavigableMap($($nc(this->nm)->headMap(toKey, false)), this->keyType, this->valueType);
}

$SortedMap* Collections$CheckedNavigableMap::tailMap(Object$* fromKey) {
	return $Collections::checkedNavigableMap($($nc(this->nm)->tailMap(fromKey, true)), this->keyType, this->valueType);
}

$NavigableMap* Collections$CheckedNavigableMap::subMap(Object$* fromKey, bool fromInclusive, Object$* toKey, bool toInclusive) {
	return $Collections::checkedNavigableMap($($nc(this->nm)->subMap(fromKey, fromInclusive, toKey, toInclusive)), this->keyType, this->valueType);
}

$NavigableMap* Collections$CheckedNavigableMap::headMap(Object$* toKey, bool inclusive) {
	return $Collections::checkedNavigableMap($($nc(this->nm)->headMap(toKey, inclusive)), this->keyType, this->valueType);
}

$NavigableMap* Collections$CheckedNavigableMap::tailMap(Object$* fromKey, bool inclusive) {
	return $Collections::checkedNavigableMap($($nc(this->nm)->tailMap(fromKey, inclusive)), this->keyType, this->valueType);
}

Collections$CheckedNavigableMap::Collections$CheckedNavigableMap() {
}

$Class* Collections$CheckedNavigableMap::load$($String* name, bool initialize) {
	$loadClass(Collections$CheckedNavigableMap, name, initialize, &_Collections$CheckedNavigableMap_ClassInfo_, allocate$Collections$CheckedNavigableMap);
	return class$;
}

$Class* Collections$CheckedNavigableMap::class$ = nullptr;

	} // util
} // java