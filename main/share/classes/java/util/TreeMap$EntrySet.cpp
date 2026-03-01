#include <java/util/TreeMap$EntrySet.h>

#include <java/util/AbstractSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Spliterator.h>
#include <java/util/TreeMap$Entry.h>
#include <java/util/TreeMap$EntryIterator.h>
#include <java/util/TreeMap$EntrySpliterator.h>
#include <java/util/TreeMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSet = ::java::util::AbstractSet;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;
using $Spliterator = ::java::util::Spliterator;
using $TreeMap = ::java::util::TreeMap;
using $TreeMap$Entry = ::java::util::TreeMap$Entry;
using $TreeMap$EntryIterator = ::java::util::TreeMap$EntryIterator;
using $TreeMap$EntrySpliterator = ::java::util::TreeMap$EntrySpliterator;

namespace java {
	namespace util {

$FieldInfo _TreeMap$EntrySet_FieldInfo_[] = {
	{"this$0", "Ljava/util/TreeMap;", nullptr, $FINAL | $SYNTHETIC, $field(TreeMap$EntrySet, this$0)},
	{}
};

$MethodInfo _TreeMap$EntrySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/TreeMap;)V", nullptr, 0, $method(TreeMap$EntrySet, init$, void, $TreeMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(TreeMap$EntrySet, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(TreeMap$EntrySet, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(TreeMap$EntrySet, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(TreeMap$EntrySet, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(TreeMap$EntrySet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(TreeMap$EntrySet, spliterator, $Spliterator*)},
	{}
};

$InnerClassInfo _TreeMap$EntrySet_InnerClassesInfo_[] = {
	{"java.util.TreeMap$EntrySet", "java.util.TreeMap", "EntrySet", 0},
	{"java.util.Map$Entry", "java.util.Map", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _TreeMap$EntrySet_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.TreeMap$EntrySet",
	"java.util.AbstractSet",
	nullptr,
	_TreeMap$EntrySet_FieldInfo_,
	_TreeMap$EntrySet_MethodInfo_,
	"Ljava/util/AbstractSet<Ljava/util/Map$Entry<TK;TV;>;>;",
	nullptr,
	_TreeMap$EntrySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.TreeMap"
};

$Object* allocate$TreeMap$EntrySet($Class* clazz) {
	return $of($alloc(TreeMap$EntrySet));
}

void TreeMap$EntrySet::init$($TreeMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractSet::init$();
}

$Iterator* TreeMap$EntrySet::iterator() {
	return $new($TreeMap$EntryIterator, this->this$0, $(this->this$0->getFirstEntry()));
}

bool TreeMap$EntrySet::contains(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, entry, nullptr);
	bool var$0 = $instanceOf($Map$Entry, o);
	if (var$0) {
		$assign(entry, $cast($Map$Entry, o));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	$var($Object, value, $nc(entry)->getValue());
	$var($TreeMap$Entry, p, this->this$0->getEntry($(entry->getKey())));
	return p != nullptr && $TreeMap::valEquals($(p->getValue()), value);
}

bool TreeMap$EntrySet::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, entry, nullptr);
	bool var$0 = $instanceOf($Map$Entry, o);
	if (var$0) {
		$assign(entry, $cast($Map$Entry, o));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	$var($Object, value, $nc(entry)->getValue());
	$var($TreeMap$Entry, p, this->this$0->getEntry($(entry->getKey())));
	if (p != nullptr && $TreeMap::valEquals($(p->getValue()), value)) {
		this->this$0->deleteEntry(p);
		return true;
	}
	return false;
}

int32_t TreeMap$EntrySet::size() {
	return this->this$0->size();
}

void TreeMap$EntrySet::clear() {
	this->this$0->clear();
}

$Spliterator* TreeMap$EntrySet::spliterator() {
	return $new($TreeMap$EntrySpliterator, this->this$0, nullptr, nullptr, 0, -1, 0);
}

TreeMap$EntrySet::TreeMap$EntrySet() {
}

$Class* TreeMap$EntrySet::load$($String* name, bool initialize) {
	$loadClass(TreeMap$EntrySet, name, initialize, &_TreeMap$EntrySet_ClassInfo_, allocate$TreeMap$EntrySet);
	return class$;
}

$Class* TreeMap$EntrySet::class$ = nullptr;

	} // util
} // java