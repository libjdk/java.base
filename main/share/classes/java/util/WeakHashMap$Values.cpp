#include <java/util/WeakHashMap$Values.h>

#include <java/util/AbstractCollection.h>
#include <java/util/Iterator.h>
#include <java/util/Spliterator.h>
#include <java/util/WeakHashMap$ValueIterator.h>
#include <java/util/WeakHashMap$ValueSpliterator.h>
#include <java/util/WeakHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractCollection = ::java::util::AbstractCollection;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;
using $WeakHashMap = ::java::util::WeakHashMap;
using $WeakHashMap$ValueIterator = ::java::util::WeakHashMap$ValueIterator;
using $WeakHashMap$ValueSpliterator = ::java::util::WeakHashMap$ValueSpliterator;

namespace java {
	namespace util {

$FieldInfo _WeakHashMap$Values_FieldInfo_[] = {
	{"this$0", "Ljava/util/WeakHashMap;", nullptr, $FINAL | $SYNTHETIC, $field(WeakHashMap$Values, this$0)},
	{}
};

$MethodInfo _WeakHashMap$Values_MethodInfo_[] = {
	{"<init>", "(Ljava/util/WeakHashMap;)V", nullptr, $PRIVATE, $method(WeakHashMap$Values, init$, void, $WeakHashMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$Values, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$Values, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TV;>;", $PUBLIC, $virtualMethod(WeakHashMap$Values, iterator, $Iterator*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(WeakHashMap$Values, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TV;>;", $PUBLIC, $virtualMethod(WeakHashMap$Values, spliterator, $Spliterator*)},
	{}
};

$InnerClassInfo _WeakHashMap$Values_InnerClassesInfo_[] = {
	{"java.util.WeakHashMap$Values", "java.util.WeakHashMap", "Values", $PRIVATE},
	{}
};

$ClassInfo _WeakHashMap$Values_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.WeakHashMap$Values",
	"java.util.AbstractCollection",
	nullptr,
	_WeakHashMap$Values_FieldInfo_,
	_WeakHashMap$Values_MethodInfo_,
	"Ljava/util/AbstractCollection<TV;>;",
	nullptr,
	_WeakHashMap$Values_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.WeakHashMap"
};

$Object* allocate$WeakHashMap$Values($Class* clazz) {
	return $of($alloc(WeakHashMap$Values));
}

void WeakHashMap$Values::init$($WeakHashMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractCollection::init$();
}

$Iterator* WeakHashMap$Values::iterator() {
	return $new($WeakHashMap$ValueIterator, this->this$0);
}

int32_t WeakHashMap$Values::size() {
	return this->this$0->size();
}

bool WeakHashMap$Values::contains(Object$* o) {
	return this->this$0->containsValue(o);
}

void WeakHashMap$Values::clear() {
	this->this$0->clear();
}

$Spliterator* WeakHashMap$Values::spliterator() {
	return $new($WeakHashMap$ValueSpliterator, this->this$0, 0, -1, 0, 0);
}

WeakHashMap$Values::WeakHashMap$Values() {
}

$Class* WeakHashMap$Values::load$($String* name, bool initialize) {
	$loadClass(WeakHashMap$Values, name, initialize, &_WeakHashMap$Values_ClassInfo_, allocate$WeakHashMap$Values);
	return class$;
}

$Class* WeakHashMap$Values::class$ = nullptr;

	} // util
} // java