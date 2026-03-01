#include <java/util/stream/Node.h>

#include <java/io/Serializable.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Node$Builder.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef REFERENCE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Spliterator = ::java::util::Spliterator;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Node$Builder = ::java::util::stream::Node$Builder;
using $Nodes = ::java::util::stream::Nodes;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

class Node$$Lambda$lambda$truncate$0 : public $Consumer {
	$class(Node$$Lambda$lambda$truncate$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* e) override {
		Node::lambda$truncate$0(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Node$$Lambda$lambda$truncate$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Node$$Lambda$lambda$truncate$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Node$$Lambda$lambda$truncate$0, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Node$$Lambda$lambda$truncate$0, accept, void, Object$*)},
	{}
};
$ClassInfo Node$$Lambda$lambda$truncate$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Node$$Lambda$lambda$truncate$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* Node$$Lambda$lambda$truncate$0::load$($String* name, bool initialize) {
	$loadClass(Node$$Lambda$lambda$truncate$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Node$$Lambda$lambda$truncate$0::class$ = nullptr;

$MethodInfo _Node_MethodInfo_[] = {
	{"asArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", "(Ljava/util/function/IntFunction<[TT;>;)[TT;", $PUBLIC | $ABSTRACT, $virtualMethod(Node, asArray, $ObjectArray*, $IntFunction*)},
	{"copyInto", "([Ljava/lang/Object;I)V", "([TT;I)V", $PUBLIC | $ABSTRACT, $virtualMethod(Node, copyInto, void, $ObjectArray*, int32_t)},
	{"count", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Node, count, int64_t)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TT;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(Node, forEach, void, $Consumer*)},
	{"getChild", "(I)Ljava/util/stream/Node;", "(I)Ljava/util/stream/Node<TT;>;", $PUBLIC, $virtualMethod(Node, getChild, Node*, int32_t)},
	{"getChildCount", "()I", nullptr, $PUBLIC, $virtualMethod(Node, getChildCount, int32_t)},
	{"getShape", "()Ljava/util/stream/StreamShape;", nullptr, $PUBLIC, $virtualMethod(Node, getShape, $StreamShape*)},
	{"lambda$truncate$0", "(Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Node, lambda$truncate$0, void, Object$*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Node, spliterator, $Spliterator*)},
	{"truncate", "(JJLjava/util/function/IntFunction;)Ljava/util/stream/Node;", "(JJLjava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", $PUBLIC, $virtualMethod(Node, truncate, Node*, int64_t, int64_t, $IntFunction*)},
	{}
};

$InnerClassInfo _Node_InnerClassesInfo_[] = {
	{"java.util.stream.Node$OfDouble", "java.util.stream.Node", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfLong", "java.util.stream.Node", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfInt", "java.util.stream.Node", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfPrimitive", "java.util.stream.Node", "OfPrimitive", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$Builder", "java.util.stream.Node", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Node_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"java.util.stream.Node",
	nullptr,
	nullptr,
	nullptr,
	_Node_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_Node_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.Node$OfDouble,java.util.stream.Node$OfLong,java.util.stream.Node$OfInt,java.util.stream.Node$OfPrimitive,java.util.stream.Node$Builder,java.util.stream.Node$Builder$OfDouble,java.util.stream.Node$Builder$OfLong,java.util.stream.Node$Builder$OfInt"
};

$Object* allocate$Node($Class* clazz) {
	return $of($alloc(Node));
}

int32_t Node::getChildCount() {
	return 0;
}

Node* Node::getChild(int32_t i) {
	$throwNew($IndexOutOfBoundsException);
	$shouldNotReachHere();
}

Node* Node::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	if (from == 0 && to == count()) {
		return this;
	}
	$var($Spliterator, spliterator, this->spliterator());
	int64_t size = to - from;
	$var($Node$Builder, nodeBuilder, $Nodes::builder(size, generator));
	$nc(nodeBuilder)->begin(size);
	for (int32_t i = 0; i < from && $nc(spliterator)->tryAdvance(static_cast<$Consumer*>($$new(Node$$Lambda$lambda$truncate$0))); ++i) {
	}
	if (to == count()) {
		$nc(spliterator)->forEachRemaining(nodeBuilder);
	} else {
		for (int32_t i = 0; i < size && $nc(spliterator)->tryAdvance(nodeBuilder); ++i) {
		}
	}
	nodeBuilder->end();
	return nodeBuilder->build();
}

$StreamShape* Node::getShape() {
	$init($StreamShape);
	return $StreamShape::REFERENCE;
}

void Node::lambda$truncate$0(Object$* e) {
}

$Class* Node::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Node$$Lambda$lambda$truncate$0::classInfo$.name)) {
			return Node$$Lambda$lambda$truncate$0::load$(name, initialize);
		}
	}
	$loadClass(Node, name, initialize, &_Node_ClassInfo_, allocate$Node);
	return class$;
}

$Class* Node::class$ = nullptr;

		} // stream
	} // util
} // java