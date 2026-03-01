#include <java/util/EnumMap$EntrySet.h>

#include <java/lang/Enum.h>
#include <java/lang/reflect/Array.h>
#include <java/util/AbstractMap$SimpleEntry.h>
#include <java/util/AbstractSet.h>
#include <java/util/EnumMap$EntryIterator.h>
#include <java/util/EnumMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $1Array = ::java::lang::reflect::Array;
using $AbstractMap$SimpleEntry = ::java::util::AbstractMap$SimpleEntry;
using $AbstractSet = ::java::util::AbstractSet;
using $EnumMap = ::java::util::EnumMap;
using $EnumMap$EntryIterator = ::java::util::EnumMap$EntryIterator;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;

namespace java {
	namespace util {

$FieldInfo _EnumMap$EntrySet_FieldInfo_[] = {
	{"this$0", "Ljava/util/EnumMap;", nullptr, $FINAL | $SYNTHETIC, $field(EnumMap$EntrySet, this$0)},
	{}
};

$MethodInfo _EnumMap$EntrySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/EnumMap;)V", nullptr, $PRIVATE, $method(EnumMap$EntrySet, init$, void, $EnumMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(EnumMap$EntrySet, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap$EntrySet, contains, bool, Object$*)},
	{"fillEntryArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE, $method(EnumMap$EntrySet, fillEntryArray, $ObjectArray*, $ObjectArray*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(EnumMap$EntrySet, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(EnumMap$EntrySet, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(EnumMap$EntrySet, size, int32_t)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(EnumMap$EntrySet, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(EnumMap$EntrySet, toArray, $ObjectArray*, $ObjectArray*)},
	{}
};

$InnerClassInfo _EnumMap$EntrySet_InnerClassesInfo_[] = {
	{"java.util.EnumMap$EntrySet", "java.util.EnumMap", "EntrySet", $PRIVATE},
	{"java.util.Map$Entry", "java.util.Map", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _EnumMap$EntrySet_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.EnumMap$EntrySet",
	"java.util.AbstractSet",
	nullptr,
	_EnumMap$EntrySet_FieldInfo_,
	_EnumMap$EntrySet_MethodInfo_,
	"Ljava/util/AbstractSet<Ljava/util/Map$Entry<TK;TV;>;>;",
	nullptr,
	_EnumMap$EntrySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.EnumMap"
};

$Object* allocate$EnumMap$EntrySet($Class* clazz) {
	return $of($alloc(EnumMap$EntrySet));
}

void EnumMap$EntrySet::init$($EnumMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractSet::init$();
}

$Iterator* EnumMap$EntrySet::iterator() {
	return $new($EnumMap$EntryIterator, this->this$0);
}

bool EnumMap$EntrySet::contains(Object$* o) {
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

bool EnumMap$EntrySet::remove(Object$* o) {
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

int32_t EnumMap$EntrySet::size() {
	return this->this$0->size$;
}

void EnumMap$EntrySet::clear() {
	this->this$0->clear();
}

$ObjectArray* EnumMap$EntrySet::toArray() {
	return fillEntryArray($$new($ObjectArray, this->this$0->size$));
}

$ObjectArray* EnumMap$EntrySet::toArray($ObjectArray* a$renamed) {
	$var($ObjectArray, a, a$renamed);
	int32_t size = this->size();
	if ($nc(a)->length < size) {
		$assign(a, $cast($ObjectArray, $1Array::newInstance($of(a)->getClass()->getComponentType(), size)));
	}
	if ($nc(a)->length > size) {
		a->set(size, nullptr);
	}
	return fillEntryArray(a);
}

$ObjectArray* EnumMap$EntrySet::fillEntryArray($ObjectArray* a) {
	$useLocalCurrentObjectStackCache();
	int32_t j = 0;
	for (int32_t i = 0; i < $nc(this->this$0->vals)->length; ++i) {
		if ($nc(this->this$0->vals)->get(i) != nullptr) {
			$nc(a)->set(j++, $$new($AbstractMap$SimpleEntry, $nc(this->this$0->keyUniverse)->get(i), $(this->this$0->unmaskNull($nc(this->this$0->vals)->get(i)))));
		}
	}
	return a;
}

EnumMap$EntrySet::EnumMap$EntrySet() {
}

$Class* EnumMap$EntrySet::load$($String* name, bool initialize) {
	$loadClass(EnumMap$EntrySet, name, initialize, &_EnumMap$EntrySet_ClassInfo_, allocate$EnumMap$EntrySet);
	return class$;
}

$Class* EnumMap$EntrySet::class$ = nullptr;

	} // util
} // java