#include <java/util/TreeMap$DescendingSubMap$DescendingEntrySetView.h>

#include <java/util/Iterator.h>
#include <java/util/TreeMap$DescendingSubMap.h>
#include <java/util/TreeMap$Entry.h>
#include <java/util/TreeMap$NavigableSubMap$DescendingSubMapEntryIterator.h>
#include <java/util/TreeMap$NavigableSubMap$EntrySetView.h>
#include <java/util/TreeMap$NavigableSubMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Iterator = ::java::util::Iterator;
using $TreeMap$DescendingSubMap = ::java::util::TreeMap$DescendingSubMap;
using $TreeMap$Entry = ::java::util::TreeMap$Entry;
using $TreeMap$NavigableSubMap = ::java::util::TreeMap$NavigableSubMap;
using $TreeMap$NavigableSubMap$DescendingSubMapEntryIterator = ::java::util::TreeMap$NavigableSubMap$DescendingSubMapEntryIterator;
using $TreeMap$NavigableSubMap$EntrySetView = ::java::util::TreeMap$NavigableSubMap$EntrySetView;

namespace java {
	namespace util {

$FieldInfo _TreeMap$DescendingSubMap$DescendingEntrySetView_FieldInfo_[] = {
	{"this$0", "Ljava/util/TreeMap$DescendingSubMap;", nullptr, $FINAL | $SYNTHETIC, $field(TreeMap$DescendingSubMap$DescendingEntrySetView, this$0)},
	{}
};

$MethodInfo _TreeMap$DescendingSubMap$DescendingEntrySetView_MethodInfo_[] = {
	{"<init>", "(Ljava/util/TreeMap$DescendingSubMap;)V", nullptr, 0, $method(TreeMap$DescendingSubMap$DescendingEntrySetView, init$, void, $TreeMap$DescendingSubMap*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(TreeMap$DescendingSubMap$DescendingEntrySetView, iterator, $Iterator*)},
	{}
};

$InnerClassInfo _TreeMap$DescendingSubMap$DescendingEntrySetView_InnerClassesInfo_[] = {
	{"java.util.TreeMap$DescendingSubMap", "java.util.TreeMap", "DescendingSubMap", $STATIC | $FINAL},
	{"java.util.TreeMap$DescendingSubMap$DescendingEntrySetView", "java.util.TreeMap$DescendingSubMap", "DescendingEntrySetView", $FINAL},
	{"java.util.TreeMap$NavigableSubMap", "java.util.TreeMap", "NavigableSubMap", $STATIC | $ABSTRACT},
	{"java.util.TreeMap$NavigableSubMap$EntrySetView", "java.util.TreeMap$NavigableSubMap", "EntrySetView", $ABSTRACT},
	{}
};

$ClassInfo _TreeMap$DescendingSubMap$DescendingEntrySetView_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.TreeMap$DescendingSubMap$DescendingEntrySetView",
	"java.util.TreeMap$NavigableSubMap$EntrySetView",
	nullptr,
	_TreeMap$DescendingSubMap$DescendingEntrySetView_FieldInfo_,
	_TreeMap$DescendingSubMap$DescendingEntrySetView_MethodInfo_,
	"Ljava/util/TreeMap$NavigableSubMap<TK;TV;>.EntrySetView;",
	nullptr,
	_TreeMap$DescendingSubMap$DescendingEntrySetView_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.TreeMap"
};

$Object* allocate$TreeMap$DescendingSubMap$DescendingEntrySetView($Class* clazz) {
	return $of($alloc(TreeMap$DescendingSubMap$DescendingEntrySetView));
}

void TreeMap$DescendingSubMap$DescendingEntrySetView::init$($TreeMap$DescendingSubMap* this$0) {
	$set(this, this$0, this$0);
	$TreeMap$NavigableSubMap$EntrySetView::init$(this$0);
}

$Iterator* TreeMap$DescendingSubMap$DescendingEntrySetView::iterator() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$NavigableSubMap, var$0, static_cast<$TreeMap$NavigableSubMap*>(this->this$0));
	$var($TreeMap$Entry, var$1, this->this$0->absHighest());
	return $new($TreeMap$NavigableSubMap$DescendingSubMapEntryIterator, var$0, var$1, $(this->this$0->absLowFence()));
}

TreeMap$DescendingSubMap$DescendingEntrySetView::TreeMap$DescendingSubMap$DescendingEntrySetView() {
}

$Class* TreeMap$DescendingSubMap$DescendingEntrySetView::load$($String* name, bool initialize) {
	$loadClass(TreeMap$DescendingSubMap$DescendingEntrySetView, name, initialize, &_TreeMap$DescendingSubMap$DescendingEntrySetView_ClassInfo_, allocate$TreeMap$DescendingSubMap$DescendingEntrySetView);
	return class$;
}

$Class* TreeMap$DescendingSubMap$DescendingEntrySetView::class$ = nullptr;

	} // util
} // java