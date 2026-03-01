#include <java/util/List.h>

#include <java/util/AbstractList$RandomAccessSpliterator.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/ImmutableCollections$List12.h>
#include <java/util/ImmutableCollections$ListN.h>
#include <java/util/ImmutableCollections.h>
#include <java/util/ListIterator.h>
#include <java/util/Objects.h>
#include <java/util/RandomAccess.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/UnaryOperator.h>
#include <jcpp.h>

#undef EMPTY_LIST
#undef ORDERED

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractList$RandomAccessSpliterator = ::java::util::AbstractList$RandomAccessSpliterator;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $ImmutableCollections = ::java::util::ImmutableCollections;
using $ImmutableCollections$List12 = ::java::util::ImmutableCollections$List12;
using $ListIterator = ::java::util::ListIterator;
using $Objects = ::java::util::Objects;
using $RandomAccess = ::java::util::RandomAccess;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $UnaryOperator = ::java::util::function::UnaryOperator;

namespace java {
	namespace util {

$CompoundAttribute _List_MethodAnnotations_of19[] = {
	{"Ljava/lang/SafeVarargs;", nullptr},
	{}
};

$MethodInfo _List_MethodInfo_[] = {
	{"add", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"add", "(ILjava/lang/Object;)V", "(ITE;)V", $PUBLIC | $ABSTRACT, $virtualMethod(List, add, void, int32_t, Object$*)},
	{"addAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"addAll", "(ILjava/util/Collection;)Z", "(ILjava/util/Collection<+TE;>;)Z", $PUBLIC | $ABSTRACT, $virtualMethod(List, addAll, bool, int32_t, $Collection*)},
	{"clear", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"containsAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"copyOf", "(Ljava/util/Collection;)Ljava/util/List;", "<E:Ljava/lang/Object;>(Ljava/util/Collection<+TE;>;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, copyOf, List*, $Collection*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"get", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC | $ABSTRACT, $virtualMethod(List, get, $Object*, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"indexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(List, indexOf, int32_t, Object$*)},
	{"isEmpty", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"lastIndexOf", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(List, lastIndexOf, int32_t, Object$*)},
	{"listIterator", "()Ljava/util/ListIterator;", "()Ljava/util/ListIterator<TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(List, listIterator, $ListIterator*)},
	{"listIterator", "(I)Ljava/util/ListIterator;", "(I)Ljava/util/ListIterator<TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(List, listIterator, $ListIterator*, int32_t)},
	{"of", "()Ljava/util/List;", "<E:Ljava/lang/Object;>()Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*)},
	{"of", "(Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;TE;TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>(TE;TE;TE;TE;TE;TE;TE;TE;TE;TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC, $staticMethod(List, of, List*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*, Object$*)},
	{"of", "([Ljava/lang/Object;)Ljava/util/List;", "<E:Ljava/lang/Object;>([TE;)Ljava/util/List<TE;>;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(List, of, List*, $ObjectArray*), nullptr, nullptr, _List_MethodAnnotations_of19},
	{"remove", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"remove", "(I)Ljava/lang/Object;", "(I)TE;", $PUBLIC | $ABSTRACT, $virtualMethod(List, remove, $Object*, int32_t)},
	{"removeAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"replaceAll", "(Ljava/util/function/UnaryOperator;)V", "(Ljava/util/function/UnaryOperator<TE;>;)V", $PUBLIC, $virtualMethod(List, replaceAll, void, $UnaryOperator*)},
	{"retainAll", "(Ljava/util/Collection;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"set", "(ILjava/lang/Object;)Ljava/lang/Object;", "(ITE;)TE;", $PUBLIC | $ABSTRACT, $virtualMethod(List, set, $Object*, int32_t, Object$*)},
	{"size", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"sort", "(Ljava/util/Comparator;)V", "(Ljava/util/Comparator<-TE;>;)V", $PUBLIC, $virtualMethod(List, sort, void, $Comparator*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(List, spliterator, $Spliterator*)},
	{"subList", "(II)Ljava/util/List;", "(II)Ljava/util/List<TE;>;", $PUBLIC | $ABSTRACT, $virtualMethod(List, subList, List*, int32_t, int32_t)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"toArray", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _List_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.List",
	nullptr,
	"java.util.Collection",
	nullptr,
	_List_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/Collection<TE;>;"
};

$Object* allocate$List($Class* clazz) {
	return $of($alloc(List));
}

bool List::equals(Object$* o) {
	 return this->$Collection::equals(o);
}

int32_t List::hashCode() {
	 return this->$Collection::hashCode();
}

void List::replaceAll($UnaryOperator* operator$) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(operator$);
	$var($ListIterator, li, this->listIterator());
	while ($nc(li)->hasNext()) {
		li->set($(operator$->apply($(li->next()))));
	}
}

void List::sort($Comparator* c) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, a, this->toArray());
	$Arrays::sort(a, c);
	$var($ListIterator, i, this->listIterator());
	{
		$var($ObjectArray, arr$, a);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, e, arr$->get(i$));
			{
				$nc(i)->next();
				i->set(e);
			}
		}
	}
}

$Spliterator* List::spliterator() {
	if ($instanceOf($RandomAccess, this)) {
		return $new($AbstractList$RandomAccessSpliterator, this);
	} else {
		return $Spliterators::spliterator(static_cast<$Collection*>(this), $Spliterator::ORDERED);
	}
}

List* List::of() {
	$init(List);
	$init($ImmutableCollections);
	return static_cast<List*>($ImmutableCollections::EMPTY_LIST);
}

List* List::of(Object$* e1) {
	$init(List);
	return $new($ImmutableCollections$List12, e1);
}

List* List::of(Object$* e1, Object$* e2) {
	$init(List);
	return $new($ImmutableCollections$List12, e1, e2);
}

List* List::of(Object$* e1, Object$* e2, Object$* e3) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4, Object$* e5) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4,
		e5
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4, Object$* e5, Object$* e6) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4,
		e5,
		e6
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4, Object$* e5, Object$* e6, Object$* e7) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4,
		e5,
		e6,
		e7
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4, Object$* e5, Object$* e6, Object$* e7, Object$* e8) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4,
		e5,
		e6,
		e7,
		e8
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4, Object$* e5, Object$* e6, Object$* e7, Object$* e8, Object$* e9) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4,
		e5,
		e6,
		e7,
		e8,
		e9
	}));
}

List* List::of(Object$* e1, Object$* e2, Object$* e3, Object$* e4, Object$* e5, Object$* e6, Object$* e7, Object$* e8, Object$* e9, Object$* e10) {
	$init(List);
	return $ImmutableCollections::listFromTrustedArray($$new($ObjectArray, {
		e1,
		e2,
		e3,
		e4,
		e5,
		e6,
		e7,
		e8,
		e9,
		e10
	}));
}

List* List::of($ObjectArray* elements) {
	$init(List);
	{
		$var(List, list, nullptr)
		switch ($nc(elements)->length) {
		case 0:
			{
				$init($ImmutableCollections);
				$assign(list, static_cast<List*>($ImmutableCollections::EMPTY_LIST));
				return list;
			}
		case 1:
			{
				return $new($ImmutableCollections$List12, elements->get(0));
			}
		case 2:
			{
				return $new($ImmutableCollections$List12, elements->get(0), elements->get(1));
			}
		default:
			{
				return $ImmutableCollections::listFromArray(elements);
			}
		}
	}
}

List* List::copyOf($Collection* coll) {
	$init(List);
	return $ImmutableCollections::listCopy(coll);
}

$Class* List::load$($String* name, bool initialize) {
	$loadClass(List, name, initialize, &_List_ClassInfo_, allocate$List);
	return class$;
}

$Class* List::class$ = nullptr;

	} // util
} // java