#include <java/util/TreeMap$AscendingSubMap.h>

#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/NavigableMap.h>
#include <java/util/Set.h>
#include <java/util/Spliterator.h>
#include <java/util/TreeMap$AscendingSubMap$AscendingEntrySetView.h>
#include <java/util/TreeMap$DescendingSubMap.h>
#include <java/util/TreeMap$Entry.h>
#include <java/util/TreeMap$NavigableSubMap$DescendingSubMapKeyIterator.h>
#include <java/util/TreeMap$NavigableSubMap$EntrySetView.h>
#include <java/util/TreeMap$NavigableSubMap$SubMapKeyIterator.h>
#include <java/util/TreeMap$NavigableSubMap.h>
#include <java/util/TreeMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $NavigableMap = ::java::util::NavigableMap;
using $Set = ::java::util::Set;
using $Spliterator = ::java::util::Spliterator;
using $TreeMap = ::java::util::TreeMap;
using $TreeMap$AscendingSubMap$AscendingEntrySetView = ::java::util::TreeMap$AscendingSubMap$AscendingEntrySetView;
using $TreeMap$DescendingSubMap = ::java::util::TreeMap$DescendingSubMap;
using $TreeMap$Entry = ::java::util::TreeMap$Entry;
using $TreeMap$NavigableSubMap = ::java::util::TreeMap$NavigableSubMap;
using $TreeMap$NavigableSubMap$DescendingSubMapKeyIterator = ::java::util::TreeMap$NavigableSubMap$DescendingSubMapKeyIterator;
using $TreeMap$NavigableSubMap$EntrySetView = ::java::util::TreeMap$NavigableSubMap$EntrySetView;
using $TreeMap$NavigableSubMap$SubMapKeyIterator = ::java::util::TreeMap$NavigableSubMap$SubMapKeyIterator;

namespace java {
	namespace util {

$FieldInfo _TreeMap$AscendingSubMap_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TreeMap$AscendingSubMap, serialVersionUID)},
	{}
};

$MethodInfo _TreeMap$AscendingSubMap_MethodInfo_[] = {
	{"<init>", "(Ljava/util/TreeMap;ZLjava/lang/Object;ZZLjava/lang/Object;Z)V", "(Ljava/util/TreeMap<TK;TV;>;ZTK;ZZTK;Z)V", 0, $method(TreeMap$AscendingSubMap, init$, void, $TreeMap*, bool, Object$*, bool, bool, Object$*, bool)},
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TK;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap, comparator, $Comparator*)},
	{"descendingKeyIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, descendingKeyIterator, $Iterator*)},
	{"descendingMap", "()Ljava/util/NavigableMap;", "()Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap, descendingMap, $NavigableMap*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap, entrySet, $Set*)},
	{"headMap", "(Ljava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap, headMap, $NavigableMap*, Object$*, bool)},
	{"keyIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, keyIterator, $Iterator*)},
	{"keySpliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TK;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, keySpliterator, $Spliterator*)},
	{"subCeiling", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, subCeiling, $TreeMap$Entry*, Object$*)},
	{"subFloor", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, subFloor, $TreeMap$Entry*, Object$*)},
	{"subHigher", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, subHigher, $TreeMap$Entry*, Object$*)},
	{"subHighest", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, subHighest, $TreeMap$Entry*)},
	{"subLower", "(Ljava/lang/Object;)Ljava/util/TreeMap$Entry;", "(TK;)Ljava/util/TreeMap$Entry<TK;TV;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, subLower, $TreeMap$Entry*, Object$*)},
	{"subLowest", "()Ljava/util/TreeMap$Entry;", "()Ljava/util/TreeMap$Entry<TK;TV;>;", 0, $virtualMethod(TreeMap$AscendingSubMap, subLowest, $TreeMap$Entry*)},
	{"subMap", "(Ljava/lang/Object;ZLjava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;ZTK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap, subMap, $NavigableMap*, Object$*, bool, Object$*, bool)},
	{"tailMap", "(Ljava/lang/Object;Z)Ljava/util/NavigableMap;", "(TK;Z)Ljava/util/NavigableMap<TK;TV;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap, tailMap, $NavigableMap*, Object$*, bool)},
	{}
};

$InnerClassInfo _TreeMap$AscendingSubMap_InnerClassesInfo_[] = {
	{"java.util.TreeMap$AscendingSubMap", "java.util.TreeMap", "AscendingSubMap", $STATIC | $FINAL},
	{"java.util.TreeMap$NavigableSubMap", "java.util.TreeMap", "NavigableSubMap", $STATIC | $ABSTRACT},
	{"java.util.TreeMap$AscendingSubMap$AscendingEntrySetView", "java.util.TreeMap$AscendingSubMap", "AscendingEntrySetView", $FINAL},
	{}
};

$ClassInfo _TreeMap$AscendingSubMap_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.TreeMap$AscendingSubMap",
	"java.util.TreeMap$NavigableSubMap",
	nullptr,
	_TreeMap$AscendingSubMap_FieldInfo_,
	_TreeMap$AscendingSubMap_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/TreeMap$NavigableSubMap<TK;TV;>;",
	nullptr,
	_TreeMap$AscendingSubMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.TreeMap"
};

$Object* allocate$TreeMap$AscendingSubMap($Class* clazz) {
	return $of($alloc(TreeMap$AscendingSubMap));
}

void TreeMap$AscendingSubMap::init$($TreeMap* m, bool fromStart, Object$* lo, bool loInclusive, bool toEnd, Object$* hi, bool hiInclusive) {
	$TreeMap$NavigableSubMap::init$(m, fromStart, lo, loInclusive, toEnd, hi, hiInclusive);
}

$Comparator* TreeMap$AscendingSubMap::comparator() {
	return $nc(this->m)->comparator();
}

$NavigableMap* TreeMap$AscendingSubMap::subMap(Object$* fromKey, bool fromInclusive, Object$* toKey, bool toInclusive) {
	if (!inRange(fromKey, fromInclusive)) {
		$throwNew($IllegalArgumentException, "fromKey out of range"_s);
	}
	if (!inRange(toKey, toInclusive)) {
		$throwNew($IllegalArgumentException, "toKey out of range"_s);
	}
	return $new(TreeMap$AscendingSubMap, this->m, false, fromKey, fromInclusive, false, toKey, toInclusive);
}

$NavigableMap* TreeMap$AscendingSubMap::headMap(Object$* toKey, bool inclusive) {
	if (!inRange(toKey, inclusive)) {
		$throwNew($IllegalArgumentException, "toKey out of range"_s);
	}
	return $new(TreeMap$AscendingSubMap, this->m, this->fromStart, this->lo, this->loInclusive, false, toKey, inclusive);
}

$NavigableMap* TreeMap$AscendingSubMap::tailMap(Object$* fromKey, bool inclusive) {
	if (!inRange(fromKey, inclusive)) {
		$throwNew($IllegalArgumentException, "fromKey out of range"_s);
	}
	return $new(TreeMap$AscendingSubMap, this->m, false, fromKey, inclusive, this->toEnd, this->hi, this->hiInclusive);
}

$NavigableMap* TreeMap$AscendingSubMap::descendingMap() {
	$var($NavigableMap, mv, this->descendingMapView);
	return (mv != nullptr) ? mv : ($set(this, descendingMapView, $new($TreeMap$DescendingSubMap, this->m, this->fromStart, this->lo, this->loInclusive, this->toEnd, this->hi, this->hiInclusive)));
}

$Iterator* TreeMap$AscendingSubMap::keyIterator() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$Entry, var$0, absLowest());
	return $new($TreeMap$NavigableSubMap$SubMapKeyIterator, this, var$0, $(absHighFence()));
}

$Spliterator* TreeMap$AscendingSubMap::keySpliterator() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$Entry, var$0, absLowest());
	return $new($TreeMap$NavigableSubMap$SubMapKeyIterator, this, var$0, $(absHighFence()));
}

$Iterator* TreeMap$AscendingSubMap::descendingKeyIterator() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$Entry, var$0, absHighest());
	return $new($TreeMap$NavigableSubMap$DescendingSubMapKeyIterator, this, var$0, $(absLowFence()));
}

$Set* TreeMap$AscendingSubMap::entrySet() {
	$var($TreeMap$NavigableSubMap$EntrySetView, es, this->entrySetView);
	return (es != nullptr) ? static_cast<$Set*>(es) : (static_cast<$Set*>(($set(this, entrySetView, $new($TreeMap$AscendingSubMap$AscendingEntrySetView, this)))));
}

$TreeMap$Entry* TreeMap$AscendingSubMap::subLowest() {
	return absLowest();
}

$TreeMap$Entry* TreeMap$AscendingSubMap::subHighest() {
	return absHighest();
}

$TreeMap$Entry* TreeMap$AscendingSubMap::subCeiling(Object$* key) {
	return absCeiling(key);
}

$TreeMap$Entry* TreeMap$AscendingSubMap::subHigher(Object$* key) {
	return absHigher(key);
}

$TreeMap$Entry* TreeMap$AscendingSubMap::subFloor(Object$* key) {
	return absFloor(key);
}

$TreeMap$Entry* TreeMap$AscendingSubMap::subLower(Object$* key) {
	return absLower(key);
}

TreeMap$AscendingSubMap::TreeMap$AscendingSubMap() {
}

$Class* TreeMap$AscendingSubMap::load$($String* name, bool initialize) {
	$loadClass(TreeMap$AscendingSubMap, name, initialize, &_TreeMap$AscendingSubMap_ClassInfo_, allocate$TreeMap$AscendingSubMap);
	return class$;
}

$Class* TreeMap$AscendingSubMap::class$ = nullptr;

	} // util
} // java