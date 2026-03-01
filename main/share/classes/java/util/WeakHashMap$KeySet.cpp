#include <java/util/WeakHashMap$KeySet.h>

#include <java/util/AbstractSet.h>
#include <java/util/Iterator.h>
#include <java/util/Spliterator.h>
#include <java/util/WeakHashMap$KeyIterator.h>
#include <java/util/WeakHashMap$KeySpliterator.h>
#include <java/util/WeakHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSet = ::java::util::AbstractSet;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;
using $WeakHashMap = ::java::util::WeakHashMap;
using $WeakHashMap$KeyIterator = ::java::util::WeakHashMap$KeyIterator;
using $WeakHashMap$KeySpliterator = ::java::util::WeakHashMap$KeySpliterator;

namespace java {
	namespace util {

$FieldInfo _WeakHashMap$KeySet_FieldInfo_[] = {
	{"this$0", "Ljava/util/WeakHashMap;", nullptr, $FINAL | $SYNTHETIC, $field(WeakHashMap$KeySet, this$0)},
	{}
};

$MethodInfo _WeakHashMap$KeySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/WeakHashMap;)V", nullptr, $PRIVATE, $method(WeakHashMap$KeySet, init$, void, $WeakHashMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$KeySet, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$KeySet, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TK;>;", $PUBLIC, $virtualMethod(WeakHashMap$KeySet, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$KeySet, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$KeySet, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TK;>;", $PUBLIC, $virtualMethod(WeakHashMap$KeySet, spliterator, $Spliterator*)},
	{}
};

$InnerClassInfo _WeakHashMap$KeySet_InnerClassesInfo_[] = {
	{"java.util.WeakHashMap$KeySet", "java.util.WeakHashMap", "KeySet", $PRIVATE},
	{}
};

$ClassInfo _WeakHashMap$KeySet_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.WeakHashMap$KeySet",
	"java.util.AbstractSet",
	nullptr,
	_WeakHashMap$KeySet_FieldInfo_,
	_WeakHashMap$KeySet_MethodInfo_,
	"Ljava/util/AbstractSet<TK;>;",
	nullptr,
	_WeakHashMap$KeySet_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.WeakHashMap"
};

$Object* allocate$WeakHashMap$KeySet($Class* clazz) {
	return $of($alloc(WeakHashMap$KeySet));
}

void WeakHashMap$KeySet::init$($WeakHashMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractSet::init$();
}

$Iterator* WeakHashMap$KeySet::iterator() {
	return $new($WeakHashMap$KeyIterator, this->this$0);
}

int32_t WeakHashMap$KeySet::size() {
	return this->this$0->size();
}

bool WeakHashMap$KeySet::contains(Object$* o) {
	return this->this$0->containsKey(o);
}

bool WeakHashMap$KeySet::remove(Object$* o) {
	if (this->this$0->containsKey(o)) {
		this->this$0->remove(o);
		return true;
	} else {
		return false;
	}
}

void WeakHashMap$KeySet::clear() {
	this->this$0->clear();
}

$Spliterator* WeakHashMap$KeySet::spliterator() {
	return $new($WeakHashMap$KeySpliterator, this->this$0, 0, -1, 0, 0);
}

WeakHashMap$KeySet::WeakHashMap$KeySet() {
}

$Class* WeakHashMap$KeySet::load$($String* name, bool initialize) {
	$loadClass(WeakHashMap$KeySet, name, initialize, &_WeakHashMap$KeySet_ClassInfo_, allocate$WeakHashMap$KeySet);
	return class$;
}

$Class* WeakHashMap$KeySet::class$ = nullptr;

	} // util
} // java