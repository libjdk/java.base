#include <java/util/concurrent/ConcurrentSkipListMap$EntrySet.h>

#include <java/lang/ClassCastException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ConcurrentNavigableMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap$EntryIterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$EntrySpliterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap$SubMapEntryIterator.h>
#include <java/util/concurrent/ConcurrentSkipListMap$SubMap.h>
#include <java/util/concurrent/ConcurrentSkipListMap.h>
#include <java/util/function/Predicate.h>
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
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Spliterator = ::java::util::Spliterator;
using $ConcurrentNavigableMap = ::java::util::concurrent::ConcurrentNavigableMap;
using $ConcurrentSkipListMap = ::java::util::concurrent::ConcurrentSkipListMap;
using $ConcurrentSkipListMap$EntryIterator = ::java::util::concurrent::ConcurrentSkipListMap$EntryIterator;
using $ConcurrentSkipListMap$SubMap = ::java::util::concurrent::ConcurrentSkipListMap$SubMap;
using $ConcurrentSkipListMap$SubMap$SubMapEntryIterator = ::java::util::concurrent::ConcurrentSkipListMap$SubMap$SubMapEntryIterator;
using $Predicate = ::java::util::function::Predicate;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ConcurrentSkipListMap$EntrySet_FieldInfo_[] = {
	{"m", "Ljava/util/concurrent/ConcurrentNavigableMap;", "Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;", $FINAL, $field(ConcurrentSkipListMap$EntrySet, m)},
	{}
};

$MethodInfo _ConcurrentSkipListMap$EntrySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/ConcurrentNavigableMap;)V", "(Ljava/util/concurrent/ConcurrentNavigableMap<TK;TV;>;)V", 0, $method(ConcurrentSkipListMap$EntrySet, init$, void, $ConcurrentNavigableMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, contains, bool, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, equals, bool, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, remove, bool, Object$*)},
	{"removeIf", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-Ljava/util/Map$Entry<TK;TV;>;>;)Z", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, removeIf, bool, $Predicate*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, spliterator, $Spliterator*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(ConcurrentSkipListMap$EntrySet, toArray, $ObjectArray*, $ObjectArray*)},
	{}
};

$InnerClassInfo _ConcurrentSkipListMap$EntrySet_InnerClassesInfo_[] = {
	{"java.util.concurrent.ConcurrentSkipListMap$EntrySet", "java.util.concurrent.ConcurrentSkipListMap", "EntrySet", $STATIC | $FINAL},
	{"java.util.Map$Entry", "java.util.Map", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ConcurrentSkipListMap$EntrySet_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.ConcurrentSkipListMap$EntrySet",
	"java.util.AbstractSet",
	nullptr,
	_ConcurrentSkipListMap$EntrySet_FieldInfo_,
	_ConcurrentSkipListMap$EntrySet_MethodInfo_,
	"<K:Ljava/lang/Object;V:Ljava/lang/Object;>Ljava/util/AbstractSet<Ljava/util/Map$Entry<TK;TV;>;>;",
	nullptr,
	_ConcurrentSkipListMap$EntrySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.ConcurrentSkipListMap"
};

$Object* allocate$ConcurrentSkipListMap$EntrySet($Class* clazz) {
	return $of($alloc(ConcurrentSkipListMap$EntrySet));
}

void ConcurrentSkipListMap$EntrySet::init$($ConcurrentNavigableMap* map) {
	$AbstractSet::init$();
	$set(this, m, map);
}

$Iterator* ConcurrentSkipListMap$EntrySet::iterator() {
	return ($instanceOf($ConcurrentSkipListMap, this->m)) ? static_cast<$Iterator*>($new($ConcurrentSkipListMap$EntryIterator, static_cast<$ConcurrentSkipListMap*>($nc(($cast($ConcurrentSkipListMap, this->m)))))) : static_cast<$Iterator*>($new($ConcurrentSkipListMap$SubMap$SubMapEntryIterator, static_cast<$ConcurrentSkipListMap$SubMap*>($nc(($cast($ConcurrentSkipListMap$SubMap, this->m))))));
}

bool ConcurrentSkipListMap$EntrySet::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($Map$Entry, o))) {
		return false;
	}
	$var($Map$Entry, e, $cast($Map$Entry, o));
	$var($Object, v, $nc(this->m)->get($($nc(e)->getKey())));
	return v != nullptr && $of(v)->equals($($nc(e)->getValue()));
}

bool ConcurrentSkipListMap$EntrySet::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($Map$Entry, o))) {
		return false;
	}
	$var($Map$Entry, e, $cast($Map$Entry, o));
	$var($Object, var$0, $nc(e)->getKey());
	return $nc(this->m)->remove(var$0, $(e->getValue()));
}

bool ConcurrentSkipListMap$EntrySet::isEmpty() {
	return $nc(this->m)->isEmpty();
}

int32_t ConcurrentSkipListMap$EntrySet::size() {
	return $nc(this->m)->size();
}

void ConcurrentSkipListMap$EntrySet::clear() {
	$nc(this->m)->clear();
}

bool ConcurrentSkipListMap$EntrySet::equals(Object$* o) {
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

$ObjectArray* ConcurrentSkipListMap$EntrySet::toArray() {
	return $nc($($ConcurrentSkipListMap::toList(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this))))))->toArray();
}

$ObjectArray* ConcurrentSkipListMap$EntrySet::toArray($ObjectArray* a) {
	return $nc($($ConcurrentSkipListMap::toList(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this))))))->toArray(a);
}

$Spliterator* ConcurrentSkipListMap$EntrySet::spliterator() {
	return ($instanceOf($ConcurrentSkipListMap, this->m)) ? static_cast<$Spliterator*>($nc(($cast($ConcurrentSkipListMap, this->m)))->entrySpliterator()) : static_cast<$Spliterator*>($new($ConcurrentSkipListMap$SubMap$SubMapEntryIterator, static_cast<$ConcurrentSkipListMap$SubMap*>($nc(($cast($ConcurrentSkipListMap$SubMap, this->m))))));
}

bool ConcurrentSkipListMap$EntrySet::removeIf($Predicate* filter) {
	$useLocalCurrentObjectStackCache();
	if (filter == nullptr) {
		$throwNew($NullPointerException);
	}
	if ($instanceOf($ConcurrentSkipListMap, this->m)) {
		return $nc(($cast($ConcurrentSkipListMap, this->m)))->removeEntryIf(filter);
	}
	$var($Iterator, it, $new($ConcurrentSkipListMap$SubMap$SubMapEntryIterator, static_cast<$ConcurrentSkipListMap$SubMap*>($nc(($cast($ConcurrentSkipListMap$SubMap, this->m))))));
	bool removed = false;
	while (it->hasNext()) {
		$var($Map$Entry, e, $cast($Map$Entry, it->next()));
		bool var$0 = $nc(filter)->test(e);
		if (var$0) {
			$var($Object, var$1, $nc(e)->getKey());
			var$0 = $nc(this->m)->remove(var$1, $(e->getValue()));
		}
		if (var$0) {
			removed = true;
		}
	}
	return removed;
}

ConcurrentSkipListMap$EntrySet::ConcurrentSkipListMap$EntrySet() {
}

$Class* ConcurrentSkipListMap$EntrySet::load$($String* name, bool initialize) {
	$loadClass(ConcurrentSkipListMap$EntrySet, name, initialize, &_ConcurrentSkipListMap$EntrySet_ClassInfo_, allocate$ConcurrentSkipListMap$EntrySet);
	return class$;
}

$Class* ConcurrentSkipListMap$EntrySet::class$ = nullptr;

		} // concurrent
	} // util
} // java