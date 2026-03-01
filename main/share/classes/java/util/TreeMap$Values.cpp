#include <java/util/TreeMap$Values.h>

#include <java/util/AbstractCollection.h>
#include <java/util/Iterator.h>
#include <java/util/Spliterator.h>
#include <java/util/TreeMap$Entry.h>
#include <java/util/TreeMap$ValueIterator.h>
#include <java/util/TreeMap$ValueSpliterator.h>
#include <java/util/TreeMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractCollection = ::java::util::AbstractCollection;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;
using $TreeMap = ::java::util::TreeMap;
using $TreeMap$Entry = ::java::util::TreeMap$Entry;
using $TreeMap$ValueIterator = ::java::util::TreeMap$ValueIterator;
using $TreeMap$ValueSpliterator = ::java::util::TreeMap$ValueSpliterator;

namespace java {
	namespace util {

$FieldInfo _TreeMap$Values_FieldInfo_[] = {
	{"this$0", "Ljava/util/TreeMap;", nullptr, $FINAL | $SYNTHETIC, $field(TreeMap$Values, this$0)},
	{}
};

$MethodInfo _TreeMap$Values_MethodInfo_[] = {
	{"<init>", "(Ljava/util/TreeMap;)V", nullptr, 0, $method(TreeMap$Values, init$, void, $TreeMap*)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(TreeMap$Values, clear, void)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(TreeMap$Values, contains, bool, Object$*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TV;>;", $PUBLIC, $virtualMethod(TreeMap$Values, iterator, $Iterator*)},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(TreeMap$Values, remove, bool, Object$*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(TreeMap$Values, size, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TV;>;", $PUBLIC, $virtualMethod(TreeMap$Values, spliterator, $Spliterator*)},
	{}
};

$InnerClassInfo _TreeMap$Values_InnerClassesInfo_[] = {
	{"java.util.TreeMap$Values", "java.util.TreeMap", "Values", 0},
	{}
};

$ClassInfo _TreeMap$Values_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.TreeMap$Values",
	"java.util.AbstractCollection",
	nullptr,
	_TreeMap$Values_FieldInfo_,
	_TreeMap$Values_MethodInfo_,
	"Ljava/util/AbstractCollection<TV;>;",
	nullptr,
	_TreeMap$Values_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.TreeMap"
};

$Object* allocate$TreeMap$Values($Class* clazz) {
	return $of($alloc(TreeMap$Values));
}

void TreeMap$Values::init$($TreeMap* this$0) {
	$set(this, this$0, this$0);
	$AbstractCollection::init$();
}

$Iterator* TreeMap$Values::iterator() {
	return $new($TreeMap$ValueIterator, this->this$0, $(this->this$0->getFirstEntry()));
}

int32_t TreeMap$Values::size() {
	return this->this$0->size();
}

bool TreeMap$Values::contains(Object$* o) {
	return this->this$0->containsValue(o);
}

bool TreeMap$Values::remove(Object$* o) {
	$useLocalCurrentObjectStackCache();
	{
		$var($TreeMap$Entry, e, this->this$0->getFirstEntry());
		for (; e != nullptr; $assign(e, $TreeMap::successor(e))) {
			if ($TreeMap::valEquals($($nc(e)->getValue()), o)) {
				this->this$0->deleteEntry(e);
				return true;
			}
		}
	}
	return false;
}

void TreeMap$Values::clear() {
	this->this$0->clear();
}

$Spliterator* TreeMap$Values::spliterator() {
	return $new($TreeMap$ValueSpliterator, this->this$0, nullptr, nullptr, 0, -1, 0);
}

TreeMap$Values::TreeMap$Values() {
}

$Class* TreeMap$Values::load$($String* name, bool initialize) {
	$loadClass(TreeMap$Values, name, initialize, &_TreeMap$Values_ClassInfo_, allocate$TreeMap$Values);
	return class$;
}

$Class* TreeMap$Values::class$ = nullptr;

	} // util
} // java