#include <java/util/TreeMap$AscendingSubMap$AscendingEntrySetView.h>

#include <java/util/Iterator.h>
#include <java/util/TreeMap$AscendingSubMap.h>
#include <java/util/TreeMap$Entry.h>
#include <java/util/TreeMap$NavigableSubMap$EntrySetView.h>
#include <java/util/TreeMap$NavigableSubMap$SubMapEntryIterator.h>
#include <java/util/TreeMap$NavigableSubMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Iterator = ::java::util::Iterator;
using $TreeMap$AscendingSubMap = ::java::util::TreeMap$AscendingSubMap;
using $TreeMap$Entry = ::java::util::TreeMap$Entry;
using $TreeMap$NavigableSubMap = ::java::util::TreeMap$NavigableSubMap;
using $TreeMap$NavigableSubMap$EntrySetView = ::java::util::TreeMap$NavigableSubMap$EntrySetView;
using $TreeMap$NavigableSubMap$SubMapEntryIterator = ::java::util::TreeMap$NavigableSubMap$SubMapEntryIterator;

namespace java {
	namespace util {

$FieldInfo _TreeMap$AscendingSubMap$AscendingEntrySetView_FieldInfo_[] = {
	{"this$0", "Ljava/util/TreeMap$AscendingSubMap;", nullptr, $FINAL | $SYNTHETIC, $field(TreeMap$AscendingSubMap$AscendingEntrySetView, this$0)},
	{}
};

$MethodInfo _TreeMap$AscendingSubMap$AscendingEntrySetView_MethodInfo_[] = {
	{"<init>", "(Ljava/util/TreeMap$AscendingSubMap;)V", nullptr, 0, $method(TreeMap$AscendingSubMap$AscendingEntrySetView, init$, void, $TreeMap$AscendingSubMap*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/Map$Entry<TK;TV;>;>;", $PUBLIC, $virtualMethod(TreeMap$AscendingSubMap$AscendingEntrySetView, iterator, $Iterator*)},
	{}
};

$InnerClassInfo _TreeMap$AscendingSubMap$AscendingEntrySetView_InnerClassesInfo_[] = {
	{"java.util.TreeMap$AscendingSubMap", "java.util.TreeMap", "AscendingSubMap", $STATIC | $FINAL},
	{"java.util.TreeMap$AscendingSubMap$AscendingEntrySetView", "java.util.TreeMap$AscendingSubMap", "AscendingEntrySetView", $FINAL},
	{"java.util.TreeMap$NavigableSubMap", "java.util.TreeMap", "NavigableSubMap", $STATIC | $ABSTRACT},
	{"java.util.TreeMap$NavigableSubMap$EntrySetView", "java.util.TreeMap$NavigableSubMap", "EntrySetView", $ABSTRACT},
	{}
};

$ClassInfo _TreeMap$AscendingSubMap$AscendingEntrySetView_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.TreeMap$AscendingSubMap$AscendingEntrySetView",
	"java.util.TreeMap$NavigableSubMap$EntrySetView",
	nullptr,
	_TreeMap$AscendingSubMap$AscendingEntrySetView_FieldInfo_,
	_TreeMap$AscendingSubMap$AscendingEntrySetView_MethodInfo_,
	"Ljava/util/TreeMap$NavigableSubMap<TK;TV;>.EntrySetView;",
	nullptr,
	_TreeMap$AscendingSubMap$AscendingEntrySetView_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.TreeMap"
};

$Object* allocate$TreeMap$AscendingSubMap$AscendingEntrySetView($Class* clazz) {
	return $of($alloc(TreeMap$AscendingSubMap$AscendingEntrySetView));
}

void TreeMap$AscendingSubMap$AscendingEntrySetView::init$($TreeMap$AscendingSubMap* this$0) {
	$set(this, this$0, this$0);
	$TreeMap$NavigableSubMap$EntrySetView::init$(this$0);
}

$Iterator* TreeMap$AscendingSubMap$AscendingEntrySetView::iterator() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap$NavigableSubMap, var$0, static_cast<$TreeMap$NavigableSubMap*>(this->this$0));
	$var($TreeMap$Entry, var$1, this->this$0->absLowest());
	return $new($TreeMap$NavigableSubMap$SubMapEntryIterator, var$0, var$1, $(this->this$0->absHighFence()));
}

TreeMap$AscendingSubMap$AscendingEntrySetView::TreeMap$AscendingSubMap$AscendingEntrySetView() {
}

$Class* TreeMap$AscendingSubMap$AscendingEntrySetView::load$($String* name, bool initialize) {
	$loadClass(TreeMap$AscendingSubMap$AscendingEntrySetView, name, initialize, &_TreeMap$AscendingSubMap$AscendingEntrySetView_ClassInfo_, allocate$TreeMap$AscendingSubMap$AscendingEntrySetView);
	return class$;
}

$Class* TreeMap$AscendingSubMap$AscendingEntrySetView::class$ = nullptr;

	} // util
} // java