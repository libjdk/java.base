#include <java/util/IdentityHashMap$EntrySet.h>

#include <java/lang/reflect/Array.h>
#include <java/util/AbstractMap$SimpleEntry.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/IdentityHashMap$EntryIterator.h>
#include <java/util/IdentityHashMap$EntrySpliterator.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $1Array = ::java::lang::reflect::Array;
using $AbstractMap$SimpleEntry = ::java::util::AbstractMap$SimpleEntry;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $IdentityHashMap$EntryIterator = ::java::util::IdentityHashMap$EntryIterator;
using $IdentityHashMap$EntrySpliterator = ::java::util::IdentityHashMap$EntrySpliterator;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;

namespace java {
	namespace util {

$FieldInfo _IdentityHashMap$EntrySet_FieldInfo_[] = {
	{"this$0", "Ljava/util/IdentityHashMap;", nullptr, $FINAL | $SYNTHETIC, $field(IdentityHashMap$EntrySet, this$0)},
	{}
};

$MethodInfo _IdentityHashMap$EntrySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/IdentityHashMap;)V", nullptr, $PRIVATE, $method(IdentityHashMap$EntrySet, init$, void, $IdentityHashMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, remove, bool, Object$*)},
	{"removeAll", "(Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;)Z", $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, removeAll, bool, $Collection*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, spliterator, $Spliterator*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(IdentityHashMap$EntrySet, toArray, $ObjectArray*, $ObjectArray*)},
	{}
};

$InnerClassInfo _IdentityHashMap$EntrySet_InnerClassesInfo_[] = {
	{"java.util.IdentityHashMap$EntrySet", "java.util.IdentityHashMap", "EntrySet", $PRIVATE},
	{"java.util.Map$Entry", "java.util.Map", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _IdentityHashMap$EntrySet_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.IdentityHashMap$EntrySet",
	"java.util.AbstractSet",
	nullptr,
	_IdentityHashMap$EntrySet_FieldInfo_,
	_IdentityHashMap$EntrySet_MethodInfo_,
	"Ljava/util/AbstractSet<Ljava/util/Map$Entry<TK;TV;>;>;",
	nullptr,
	_IdentityHashMap$EntrySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.IdentityHashMap"
};

$Object* allocate$IdentityHashMap$EntrySet($Class* clazz) {
	return $of($alloc(IdentityHashMap$EntrySet));
}

void IdentityHashMap$EntrySet::init$($IdentityHashMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractSet::init$();
}

$Iterator* IdentityHashMap$EntrySet::iterator() {
	return $new($IdentityHashMap$EntryIterator, this->this$0);
}

bool IdentityHashMap$EntrySet::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, entry, nullptr);
	bool var$1 = $instanceOf($Map$Entry, o);
	if (var$1) {
		$assign(entry, $cast($Map$Entry, o));
		var$1 = true;
	}
	bool var$0 = var$1;
	if (var$0) {
		$var($Object, var$2, $nc(entry)->getKey());
		var$0 = this->this$0->containsMapping(var$2, $(entry->getValue()));
	}
	return var$0;
}

bool IdentityHashMap$EntrySet::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, entry, nullptr);
	bool var$1 = $instanceOf($Map$Entry, o);
	if (var$1) {
		$assign(entry, $cast($Map$Entry, o));
		var$1 = true;
	}
	bool var$0 = var$1;
	if (var$0) {
		$var($Object, var$2, $nc(entry)->getKey());
		var$0 = this->this$0->removeMapping(var$2, $(entry->getValue()));
	}
	return var$0;
}

int32_t IdentityHashMap$EntrySet::size() {
	return this->this$0->size$;
}

void IdentityHashMap$EntrySet::clear() {
	this->this$0->clear();
}

bool IdentityHashMap$EntrySet::removeAll($Collection* c) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(c);
	bool modified = false;
	{
		$var($Iterator, i, iterator());
		for (; $nc(i)->hasNext();) {
			if (c->contains($(i->next()))) {
				i->remove();
				modified = true;
			}
		}
	}
	return modified;
}

$ObjectArray* IdentityHashMap$EntrySet::toArray() {
	return toArray($$new($ObjectArray, 0));
}

$ObjectArray* IdentityHashMap$EntrySet::toArray($ObjectArray* a$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, a$renamed);
	int32_t expectedModCount = this->this$0->modCount;
	int32_t size = this->size();
	if ($nc(a)->length < size) {
		$assign(a, $cast($ObjectArray, $1Array::newInstance($of(a)->getClass()->getComponentType(), size)));
	}
	$var($ObjectArray, tab, this->this$0->table);
	int32_t ti = 0;
	for (int32_t si = 0; si < $nc(tab)->length; si += 2) {
		$var($Object, key, nullptr);
		if (($assign(key, tab->get(si))) != nullptr) {
			if (ti >= size) {
				$throwNew($ConcurrentModificationException);
			}
			$nc(a)->set(ti++, $of($$new($AbstractMap$SimpleEntry, $($IdentityHashMap::unmaskNull(key)), tab->get(si + 1))));
		}
	}
	if (ti < size || expectedModCount != this->this$0->modCount) {
		$throwNew($ConcurrentModificationException);
	}
	if (ti < $nc(a)->length) {
		a->set(ti, nullptr);
	}
	return a;
}

$Spliterator* IdentityHashMap$EntrySet::spliterator() {
	return $new($IdentityHashMap$EntrySpliterator, this->this$0, 0, -1, 0, 0);
}

IdentityHashMap$EntrySet::IdentityHashMap$EntrySet() {
}

$Class* IdentityHashMap$EntrySet::load$($String* name, bool initialize) {
	$loadClass(IdentityHashMap$EntrySet, name, initialize, &_IdentityHashMap$EntrySet_ClassInfo_, allocate$IdentityHashMap$EntrySet);
	return class$;
}

$Class* IdentityHashMap$EntrySet::class$ = nullptr;

	} // util
} // java