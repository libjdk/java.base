#include <sun/security/provider/certpath/AdjacencyList.h>

#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/provider/certpath/BuildStep.h>
#include <sun/security/provider/certpath/Vertex.h>
#include <jcpp.h>

#undef BACK
#undef FAIL
#undef FOLLOW
#undef POSSIBLE
#undef SUCCEED

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $BuildStep = ::sun::security::provider::certpath::BuildStep;
using $Vertex = ::sun::security::provider::certpath::Vertex;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _AdjacencyList_FieldInfo_[] = {
	{"mStepList", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Lsun/security/provider/certpath/BuildStep;>;", $PRIVATE, $field(AdjacencyList, mStepList)},
	{"mOrigList", "Ljava/util/List;", "Ljava/util/List<Ljava/util/List<Lsun/security/provider/certpath/Vertex;>;>;", $PRIVATE, $field(AdjacencyList, mOrigList)},
	{}
};

$MethodInfo _AdjacencyList_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/util/List<Lsun/security/provider/certpath/Vertex;>;>;)V", $PUBLIC, $method(AdjacencyList, init$, void, $List*)},
	{"buildList", "(Ljava/util/List;ILsun/security/provider/certpath/BuildStep;)Z", "(Ljava/util/List<Ljava/util/List<Lsun/security/provider/certpath/Vertex;>;>;ILsun/security/provider/certpath/BuildStep;)Z", $PRIVATE, $method(AdjacencyList, buildList, bool, $List*, int32_t, $BuildStep*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Lsun/security/provider/certpath/BuildStep;>;", $PUBLIC, $virtualMethod(AdjacencyList, iterator, $Iterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AdjacencyList, toString, $String*)},
	{}
};

$ClassInfo _AdjacencyList_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.certpath.AdjacencyList",
	"java.lang.Object",
	nullptr,
	_AdjacencyList_FieldInfo_,
	_AdjacencyList_MethodInfo_
};

$Object* allocate$AdjacencyList($Class* clazz) {
	return $of($alloc(AdjacencyList));
}

void AdjacencyList::init$($List* list) {
	$set(this, mStepList, $new($ArrayList));
	$set(this, mOrigList, list);
	buildList(list, 0, nullptr);
}

$Iterator* AdjacencyList::iterator() {
	return $nc($($Collections::unmodifiableList(this->mStepList)))->iterator();
}

bool AdjacencyList::buildList($List* theList, int32_t index, $BuildStep* follow) {
	$useLocalCurrentObjectStackCache();
	$var($List, l, $cast($List, $nc(theList)->get(index)));
	bool allNegOne = true;
	bool allXcps = true;
	{
		$var($Iterator, i$, $nc(l)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Vertex, v, $cast($Vertex, i$->next()));
			{
				if ($nc(v)->getIndex() != -1) {
					if ($nc(($cast($List, $(theList->get(v->getIndex())))))->size() != 0) {
						allNegOne = false;
					}
				} else if (v->getThrowable() == nullptr) {
					allXcps = false;
				}
				$nc(this->mStepList)->add($$new($BuildStep, v, $BuildStep::POSSIBLE));
			}
		}
	}
	if (allNegOne) {
		if (allXcps) {
			if (follow == nullptr) {
				$nc(this->mStepList)->add($$new($BuildStep, nullptr, $BuildStep::FAIL));
			} else {
				$nc(this->mStepList)->add($$new($BuildStep, $($nc(follow)->getVertex()), $BuildStep::BACK));
			}
			return false;
		} else {
			$var($List, possibles, $new($ArrayList));
			{
				$var($Iterator, i$, l->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Vertex, v, $cast($Vertex, i$->next()));
					{
						if ($nc(v)->getThrowable() == nullptr) {
							possibles->add(v);
						}
					}
				}
			}
			if (possibles->size() == 1) {
				$nc(this->mStepList)->add($$new($BuildStep, $cast($Vertex, $(possibles->get(0))), $BuildStep::SUCCEED));
			} else {
				$nc(this->mStepList)->add($$new($BuildStep, $cast($Vertex, $(possibles->get(0))), $BuildStep::SUCCEED));
			}
			return true;
		}
	} else {
		bool success = false;
		{
			$var($Iterator, i$, l->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Vertex, v, $cast($Vertex, i$->next()));
				{
					if ($nc(v)->getIndex() != -1) {
						if ($nc(($cast($List, $(theList->get(v->getIndex())))))->size() != 0) {
							$var($BuildStep, bs, $new($BuildStep, v, $BuildStep::FOLLOW));
							$nc(this->mStepList)->add(bs);
							success = buildList(theList, v->getIndex(), bs);
						}
					}
				}
			}
		}
		if (success) {
			return true;
		} else {
			if (follow == nullptr) {
				$nc(this->mStepList)->add($$new($BuildStep, nullptr, $BuildStep::FAIL));
			} else {
				$nc(this->mStepList)->add($$new($BuildStep, $($nc(follow)->getVertex()), $BuildStep::BACK));
			}
			return false;
		}
	}
}

$String* AdjacencyList::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, "[\n"_s));
	int32_t i = 0;
	{
		$var($Iterator, i$, $nc(this->mOrigList)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, l, $cast($List, i$->next()));
			{
				sb->append("LinkedList["_s)->append(i++)->append("]:\n"_s);
				{
					$var($Iterator, i$, $nc(l)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Vertex, step, $cast($Vertex, i$->next()));
						{
							sb->append($($nc(step)->toString()))->append("\n"_s);
						}
					}
				}
			}
		}
	}
	sb->append("]\n"_s);
	return sb->toString();
}

AdjacencyList::AdjacencyList() {
}

$Class* AdjacencyList::load$($String* name, bool initialize) {
	$loadClass(AdjacencyList, name, initialize, &_AdjacencyList_ClassInfo_, allocate$AdjacencyList);
	return class$;
}

$Class* AdjacencyList::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun