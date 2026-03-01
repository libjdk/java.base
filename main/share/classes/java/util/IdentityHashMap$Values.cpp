#include <java/util/IdentityHashMap$Values.h>

#include <java/lang/reflect/Array.h>
#include <java/util/AbstractCollection.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/IdentityHashMap$ValueIterator.h>
#include <java/util/IdentityHashMap$ValueSpliterator.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Spliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $1Array = ::java::lang::reflect::Array;
using $AbstractCollection = ::java::util::AbstractCollection;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $IdentityHashMap$ValueIterator = ::java::util::IdentityHashMap$ValueIterator;
using $IdentityHashMap$ValueSpliterator = ::java::util::IdentityHashMap$ValueSpliterator;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;

namespace java {
	namespace util {

$FieldInfo _IdentityHashMap$Values_FieldInfo_[] = {
	{"this$0", "Ljava/util/IdentityHashMap;", nullptr, $FINAL | $SYNTHETIC, $field(IdentityHashMap$Values, this$0)},
	{}
};

$MethodInfo _IdentityHashMap$Values_MethodInfo_[] = {
	{"<init>", "(Ljava/util/IdentityHashMap;)V", nullptr, $PRIVATE, $method(IdentityHashMap$Values, init$, void, $IdentityHashMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$Values, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$Values, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TV;>;", $PUBLIC, $virtualMethod(IdentityHashMap$Values, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$Values, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$Values, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TV;>;", $PUBLIC, $virtualMethod(IdentityHashMap$Values, spliterator, $Spliterator*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(IdentityHashMap$Values, toArray, $ObjectArray*)},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", "<T:Ljava/lang/Object;>([TT;)[TT;", $PUBLIC, $virtualMethod(IdentityHashMap$Values, toArray, $ObjectArray*, $ObjectArray*)},
	{}
};

$InnerClassInfo _IdentityHashMap$Values_InnerClassesInfo_[] = {
	{"java.util.IdentityHashMap$Values", "java.util.IdentityHashMap", "Values", $PRIVATE},
	{}
};

$ClassInfo _IdentityHashMap$Values_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.IdentityHashMap$Values",
	"java.util.AbstractCollection",
	nullptr,
	_IdentityHashMap$Values_FieldInfo_,
	_IdentityHashMap$Values_MethodInfo_,
	"Ljava/util/AbstractCollection<TV;>;",
	nullptr,
	_IdentityHashMap$Values_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.IdentityHashMap"
};

$Object* allocate$IdentityHashMap$Values($Class* clazz) {
	return $of($alloc(IdentityHashMap$Values));
}

void IdentityHashMap$Values::init$($IdentityHashMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractCollection::init$();
}

$Iterator* IdentityHashMap$Values::iterator() {
	return $new($IdentityHashMap$ValueIterator, this->this$0);
}

int32_t IdentityHashMap$Values::size() {
	return this->this$0->size$;
}

bool IdentityHashMap$Values::contains(Object$* o) {
	return this->this$0->containsValue(o);
}

bool IdentityHashMap$Values::remove(Object$* o) {
	{
		$var($Iterator, i, iterator());
		for (; $nc(i)->hasNext();) {
			if ($equals(i->next(), o)) {
				i->remove();
				return true;
			}
		}
	}
	return false;
}

void IdentityHashMap$Values::clear() {
	this->this$0->clear();
}

$ObjectArray* IdentityHashMap$Values::toArray() {
	return toArray($$new($ObjectArray, 0));
}

$ObjectArray* IdentityHashMap$Values::toArray($ObjectArray* a$renamed) {
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
		if (tab->get(si) != nullptr) {
			if (ti >= size) {
				$throwNew($ConcurrentModificationException);
			}
			$nc(a)->set(ti++, tab->get(si + 1));
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

$Spliterator* IdentityHashMap$Values::spliterator() {
	return $new($IdentityHashMap$ValueSpliterator, this->this$0, 0, -1, 0, 0);
}

IdentityHashMap$Values::IdentityHashMap$Values() {
}

$Class* IdentityHashMap$Values::load$($String* name, bool initialize) {
	$loadClass(IdentityHashMap$Values, name, initialize, &_IdentityHashMap$Values_ClassInfo_, allocate$IdentityHashMap$Values);
	return class$;
}

$Class* IdentityHashMap$Values::class$ = nullptr;

	} // util
} // java