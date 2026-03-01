#include <java/util/SortedSet.h>

#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/SortedSet$1.h>
#include <java/util/Spliterator.h>
#include <jcpp.h>

#undef DISTINCT
#undef ORDERED
#undef SORTED

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $SortedSet$1 = ::java::util::SortedSet$1;
using $Spliterator = ::java::util::Spliterator;

namespace java {
	namespace util {

$MethodInfo _SortedSet_MethodInfo_[] = {
	{"comparator", "()Ljava/util/Comparator;", "()Ljava/util/Comparator<-TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(SortedSet, comparator, $Comparator*)},
	{"first", "()Ljava/lang/Object;", "()TE;", $PUBLIC | $ABSTRACT, $virtualMethod(SortedSet, first, $Object*)},
	{"headSet", "(Ljava/lang/Object;)Ljava/util/SortedSet;", "(TE;)Ljava/util/SortedSet<TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(SortedSet, headSet, SortedSet*, Object$*)},
	{"last", "()Ljava/lang/Object;", "()TE;", $PUBLIC | $ABSTRACT, $virtualMethod(SortedSet, last, $Object*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(SortedSet, spliterator, $Spliterator*)},
	{"subSet", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/SortedSet;", "(TE;TE;)Ljava/util/SortedSet<TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(SortedSet, subSet, SortedSet*, Object$*, Object$*)},
	{"tailSet", "(Ljava/lang/Object;)Ljava/util/SortedSet;", "(TE;)Ljava/util/SortedSet<TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(SortedSet, tailSet, SortedSet*, Object$*)},
	{}
};

$InnerClassInfo _SortedSet_InnerClassesInfo_[] = {
	{"java.util.SortedSet$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SortedSet_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.SortedSet",
	nullptr,
	"java.util.Set",
	nullptr,
	_SortedSet_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/Set<TE;>;",
	nullptr,
	_SortedSet_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.SortedSet$1"
};

$Object* allocate$SortedSet($Class* clazz) {
	return $of($alloc(SortedSet));
}

$Spliterator* SortedSet::spliterator() {
	return $new($SortedSet$1, this, this, ($Spliterator::DISTINCT | $Spliterator::SORTED) | $Spliterator::ORDERED);
}

$Class* SortedSet::load$($String* name, bool initialize) {
	$loadClass(SortedSet, name, initialize, &_SortedSet_ClassInfo_, allocate$SortedSet);
	return class$;
}

$Class* SortedSet::class$ = nullptr;

	} // util
} // java