#include <java/util/stream/Nodes$ConcNode.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes$AbstractConcNode.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator$OfRef.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $Nodes$AbstractConcNode = ::java::util::stream::Nodes$AbstractConcNode;
using $Nodes$InternalNodeSpliterator$OfRef = ::java::util::stream::Nodes$InternalNodeSpliterator$OfRef;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$ConcNode_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/Node;Ljava/util/stream/Node;)V", "(Ljava/util/stream/Node<TT;>;Ljava/util/stream/Node<TT;>;)V", 0, $method(Nodes$ConcNode, init$, void, $Node*, $Node*)},
	{"asArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", "(Ljava/util/function/IntFunction<[TT;>;)[TT;", $PUBLIC, $virtualMethod(Nodes$ConcNode, asArray, $ObjectArray*, $IntFunction*)},
	{"copyInto", "([Ljava/lang/Object;I)V", "([TT;I)V", $PUBLIC, $virtualMethod(Nodes$ConcNode, copyInto, void, $ObjectArray*, int32_t)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TT;>;)V", $PUBLIC, $virtualMethod(Nodes$ConcNode, forEach, void, $Consumer*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TT;>;", $PUBLIC, $virtualMethod(Nodes$ConcNode, spliterator, $Spliterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Nodes$ConcNode, toString, $String*)},
	{"truncate", "(JJLjava/util/function/IntFunction;)Ljava/util/stream/Node;", "(JJLjava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", $PUBLIC, $virtualMethod(Nodes$ConcNode, truncate, $Node*, int64_t, int64_t, $IntFunction*)},
	{}
};

$InnerClassInfo _Nodes$ConcNode_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$ConcNode", "java.util.stream.Nodes", "ConcNode", $STATIC | $FINAL},
	{"java.util.stream.Nodes$AbstractConcNode", "java.util.stream.Nodes", "AbstractConcNode", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$ConcNode$OfDouble", "java.util.stream.Nodes$ConcNode", "OfDouble", $STATIC | $FINAL},
	{"java.util.stream.Nodes$ConcNode$OfLong", "java.util.stream.Nodes$ConcNode", "OfLong", $STATIC | $FINAL},
	{"java.util.stream.Nodes$ConcNode$OfInt", "java.util.stream.Nodes$ConcNode", "OfInt", $STATIC | $FINAL},
	{"java.util.stream.Nodes$ConcNode$OfPrimitive", "java.util.stream.Nodes$ConcNode", "OfPrimitive", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$ConcNode_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$ConcNode",
	"java.util.stream.Nodes$AbstractConcNode",
	nullptr,
	nullptr,
	_Nodes$ConcNode_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/stream/Nodes$AbstractConcNode<TT;Ljava/util/stream/Node<TT;>;>;Ljava/util/stream/Node<TT;>;",
	nullptr,
	_Nodes$ConcNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$ConcNode($Class* clazz) {
	return $of($alloc(Nodes$ConcNode));
}

void Nodes$ConcNode::init$($Node* left, $Node* right) {
	$Nodes$AbstractConcNode::init$(left, right);
}

$Spliterator* Nodes$ConcNode::spliterator() {
	return $new($Nodes$InternalNodeSpliterator$OfRef, this);
}

void Nodes$ConcNode::copyInto($ObjectArray* array, int32_t offset) {
	$Objects::requireNonNull(array);
	$nc(this->left)->copyInto(array, offset);
	$nc(this->right)->copyInto(array, offset + (int32_t)$nc(this->left)->count());
}

$ObjectArray* Nodes$ConcNode::asArray($IntFunction* generator) {
	int64_t size = count();
	if (size >= (int64_t)2147483639) {
		$throwNew($IllegalArgumentException, "Stream size exceeds max array size"_s);
	}
	$var($ObjectArray, array, $cast($ObjectArray, $nc(generator)->apply((int32_t)size)));
	copyInto(array, 0);
	return array;
}

void Nodes$ConcNode::forEach($Consumer* consumer) {
	$nc(this->left)->forEach(consumer);
	$nc(this->right)->forEach(consumer);
}

$Node* Nodes$ConcNode::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	if (from == 0 && to == count()) {
		return this;
	}
	int64_t leftCount = $nc(this->left)->count();
	if (from >= leftCount) {
		return $nc(this->right)->truncate(from - leftCount, to - leftCount, generator);
	} else if (to <= leftCount) {
		return $nc(this->left)->truncate(from, to, generator);
	} else {
		$var($StreamShape, var$0, getShape());
		$var($Node, var$1, $nc(this->left)->truncate(from, leftCount, generator));
		return $Nodes::conc(var$0, var$1, $($nc(this->right)->truncate(0, to - leftCount, generator)));
	}
}

$String* Nodes$ConcNode::toString() {
	$useLocalCurrentObjectStackCache();
	if (count() < 32) {
		return $String::format("ConcNode[%s.%s]"_s, $$new($ObjectArray, {
			$of(this->left),
			$of(this->right)
		}));
	} else {
		return $String::format("ConcNode[size=%d]"_s, $$new($ObjectArray, {$($of($Long::valueOf(count())))}));
	}
}

Nodes$ConcNode::Nodes$ConcNode() {
}

$Class* Nodes$ConcNode::load$($String* name, bool initialize) {
	$loadClass(Nodes$ConcNode, name, initialize, &_Nodes$ConcNode_ClassInfo_, allocate$Nodes$ConcNode);
	return class$;
}

$Class* Nodes$ConcNode::class$ = nullptr;

		} // stream
	} // util
} // java