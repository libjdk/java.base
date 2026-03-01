#include <java/util/WeakHashMap$EntrySet.h>

#include <java/util/AbstractMap$SimpleEntry.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Spliterator.h>
#include <java/util/WeakHashMap$Entry.h>
#include <java/util/WeakHashMap$EntryIterator.h>
#include <java/util/WeakHashMap$EntrySpliterator.h>
#include <java/util/WeakHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractMap$SimpleEntry = ::java::util::AbstractMap$SimpleEntry;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map$Entry = ::java::util::Map$Entry;
using $Spliterator = ::java::util::Spliterator;
using $WeakHashMap = ::java::util::WeakHashMap;
using $WeakHashMap$Entry = ::java::util::WeakHashMap$Entry;
using $WeakHashMap$EntryIterator = ::java::util::WeakHashMap$EntryIterator;
using $WeakHashMap$EntrySpliterator = ::java::util::WeakHashMap$EntrySpliterator;

namespace java {
	namespace util {

$FieldInfo _WeakHashMap$EntrySet_FieldInfo_[] = {
	{"this$0", "Ljava/util/WeakHashMap;", nullptr, $FINAL | $SYNTHETIC, $field(WeakHashMap$EntrySet, this$0)},
	{}
};

$MethodInfo _WeakHashMap$EntrySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/WeakHashMap;)V", nullptr, $PRIVATE, $method(WeakHashMap$EntrySet, init$, void, $WeakHashMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, contains, bool, Object$*)},
	{"deepCopy", "()Ljava/util/List;", "()Ljava/util/List<Ljava/util/Map$Entry<TK;TV;>;>;", $PRIVATE, $method(WeakHashMap$EntrySet, deepCopy, $List*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, spliterator, $Spliterator*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(WeakHashMap$EntrySet, toArray, $ObjectArray*, $ObjectArray*)},
	{}
};

$InnerClassInfo _WeakHashMap$EntrySet_InnerClassesInfo_[] = {
	{"java.util.WeakHashMap$EntrySet", "java.util.WeakHashMap", "EntrySet", $PRIVATE},
	{"java.util.Map$Entry", "java.util.Map", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WeakHashMap$EntrySet_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.WeakHashMap$EntrySet",
	"java.util.AbstractSet",
	nullptr,
	_WeakHashMap$EntrySet_FieldInfo_,
	_WeakHashMap$EntrySet_MethodInfo_,
	"Ljava/util/AbstractSet<Ljava/util/Map$Entry<TK;TV;>;>;",
	nullptr,
	_WeakHashMap$EntrySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.WeakHashMap"
};

$Object* allocate$WeakHashMap$EntrySet($Class* clazz) {
	return $of($alloc(WeakHashMap$EntrySet));
}

void WeakHashMap$EntrySet::init$($WeakHashMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractSet::init$();
}

$Iterator* WeakHashMap$EntrySet::iterator() {
	return $new($WeakHashMap$EntryIterator, this->this$0);
}

bool WeakHashMap$EntrySet::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, e, nullptr);
	bool var$2 = $instanceOf($Map$Entry, o);
	if (var$2) {
		$assign(e, $cast($Map$Entry, o));
		var$2 = true;
	}
	bool var$1 = var$2;
	bool var$0 = var$1 && this->this$0->getEntry($($nc(e)->getKey())) != nullptr;
	return var$0 && $nc($(this->this$0->getEntry($($nc(e)->getKey()))))->equals(e);
}

bool WeakHashMap$EntrySet::remove(Object$* o) {
	return this->this$0->removeMapping(o);
}

int32_t WeakHashMap$EntrySet::size() {
	return this->this$0->size();
}

void WeakHashMap$EntrySet::clear() {
	this->this$0->clear();
}

$List* WeakHashMap$EntrySet::deepCopy() {
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList, size()));
	{
		$var($Iterator, i$, this->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			list->add($$new($AbstractMap$SimpleEntry, e));
		}
	}
	return list;
}

$ObjectArray* WeakHashMap$EntrySet::toArray() {
	return $nc($(deepCopy()))->toArray();
}

$ObjectArray* WeakHashMap$EntrySet::toArray($ObjectArray* a) {
	return $nc($(deepCopy()))->toArray(a);
}

$Spliterator* WeakHashMap$EntrySet::spliterator() {
	return $new($WeakHashMap$EntrySpliterator, this->this$0, 0, -1, 0, 0);
}

WeakHashMap$EntrySet::WeakHashMap$EntrySet() {
}

$Class* WeakHashMap$EntrySet::load$($String* name, bool initialize) {
	$loadClass(WeakHashMap$EntrySet, name, initialize, &_WeakHashMap$EntrySet_ClassInfo_, allocate$WeakHashMap$EntrySet);
	return class$;
}

$Class* WeakHashMap$EntrySet::class$ = nullptr;

	} // util
} // java