#include <java/util/stream/Node$OfLong.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator$OfPrimitive.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/stream/Node$Builder$OfLong.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/Tripwire.h>
#include <jcpp.h>

#undef ENABLED
#undef LONG_VALUE

using $LongArray = $Array<::java::lang::Long>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Spliterator$OfPrimitive = ::java::util::Spliterator$OfPrimitive;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $LongConsumer = ::java::util::function::LongConsumer;
using $Node$Builder$OfLong = ::java::util::stream::Node$Builder$OfLong;
using $Nodes = ::java::util::stream::Nodes;
using $StreamShape = ::java::util::stream::StreamShape;
using $Tripwire = ::java::util::stream::Tripwire;

namespace java {
	namespace util {
		namespace stream {

class Node$OfLong$$Lambda$lambda$truncate$0 : public $LongConsumer {
	$class(Node$OfLong$$Lambda$lambda$truncate$0, $NO_CLASS_INIT, $LongConsumer)
public:
	void init$() {
	}
	virtual void accept(int64_t e) override {
		Node$OfLong::lambda$truncate$0(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Node$OfLong$$Lambda$lambda$truncate$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Node$OfLong$$Lambda$lambda$truncate$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Node$OfLong$$Lambda$lambda$truncate$0, init$, void)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(Node$OfLong$$Lambda$lambda$truncate$0, accept, void, int64_t)},
	{}
};
$ClassInfo Node$OfLong$$Lambda$lambda$truncate$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Node$OfLong$$Lambda$lambda$truncate$0",
	"java.lang.Object",
	"java.util.function.LongConsumer",
	nullptr,
	methodInfos
};
$Class* Node$OfLong$$Lambda$lambda$truncate$0::load$($String* name, bool initialize) {
	$loadClass(Node$OfLong$$Lambda$lambda$truncate$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Node$OfLong$$Lambda$lambda$truncate$0::class$ = nullptr;

$MethodInfo _Node$OfLong_MethodInfo_[] = {
	{"copyInto", "([Ljava/lang/Long;I)V", nullptr, $PUBLIC, $virtualMethod(Node$OfLong, copyInto, void, $LongArray*, int32_t)},
	{"copyInto", "([Ljava/lang/Object;I)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Node$OfLong, copyInto, void, $ObjectArray*, int32_t)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-Ljava/lang/Long;>;)V", $PUBLIC, $virtualMethod(Node$OfLong, forEach, void, $Consumer*)},
	{"getShape", "()Ljava/util/stream/StreamShape;", nullptr, $PUBLIC, $virtualMethod(Node$OfLong, getShape, $StreamShape*)},
	{"lambda$truncate$0", "(J)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Node$OfLong, lambda$truncate$0, void, int64_t)},
	{"newArray", "(I)[J", nullptr, $PUBLIC, $virtualMethod(Node$OfLong, newArray, $Object*, int32_t)},
	{"truncate", "(JJLjava/util/function/IntFunction;)Ljava/util/stream/Node$OfLong;", "(JJLjava/util/function/IntFunction<[Ljava/lang/Long;>;)Ljava/util/stream/Node$OfLong;", $PUBLIC, $virtualMethod(Node$OfLong, truncate, Node$OfLong*, int64_t, int64_t, $IntFunction*)},
	{}
};

$InnerClassInfo _Node$OfLong_InnerClassesInfo_[] = {
	{"java.util.stream.Node$OfLong", "java.util.stream.Node", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfPrimitive", "java.util.stream.Node", "OfPrimitive", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Node$OfLong_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.stream.Node$OfLong",
	nullptr,
	"java.util.stream.Node$OfPrimitive",
	nullptr,
	_Node$OfLong_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/stream/Node$OfPrimitive<Ljava/lang/Long;Ljava/util/function/LongConsumer;[JLjava/util/Spliterator$OfLong;Ljava/util/stream/Node$OfLong;>;",
	nullptr,
	_Node$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Node"
};

$Object* allocate$Node$OfLong($Class* clazz) {
	return $of($alloc(Node$OfLong));
}

void Node$OfLong::forEach($Consumer* consumer) {
	if ($instanceOf($LongConsumer, consumer)) {
		forEach($cast($LongConsumer, consumer));
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$Tripwire::trip($of(this)->getClass(), "{0} calling Node.OfLong.forEachRemaining(Consumer)"_s);
		}
		$nc(($cast($Spliterator$OfLong, $($cast($Spliterator$OfPrimitive, spliterator())))))->forEachRemaining(consumer);
	}
}

void Node$OfLong::copyInto($LongArray* boxed, int32_t offset) {
	$useLocalCurrentObjectStackCache();
	$init($Tripwire);
	if ($Tripwire::ENABLED) {
		$Tripwire::trip($of(this)->getClass(), "{0} calling Node.OfInt.copyInto(Long[], int)"_s);
	}
	$var($longs, array, $cast($longs, asPrimitiveArray()));
	for (int32_t i = 0; i < $nc(array)->length; ++i) {
		$nc(boxed)->set(offset + i, $($Long::valueOf(array->get(i))));
	}
}

Node$OfLong* Node$OfLong::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	if (from == 0 && to == count()) {
		return this;
	}
	int64_t size = to - from;
	$var($Spliterator$OfLong, spliterator, $cast($Spliterator$OfLong, $cast($Spliterator$OfPrimitive, this->spliterator())));
	$var($Node$Builder$OfLong, nodeBuilder, $Nodes::longBuilder(size));
	$nc(nodeBuilder)->begin(size);
	for (int32_t i = 0; i < from && $nc(spliterator)->tryAdvance(static_cast<$LongConsumer*>($$new(Node$OfLong$$Lambda$lambda$truncate$0))); ++i) {
	}
	if (to == count()) {
		$nc(spliterator)->forEachRemaining(static_cast<$LongConsumer*>(nodeBuilder));
	} else {
		for (int32_t i = 0; i < size && $nc(spliterator)->tryAdvance(static_cast<$LongConsumer*>(nodeBuilder)); ++i) {
		}
	}
	nodeBuilder->end();
	return $cast(Node$OfLong, nodeBuilder->build());
}

$Object* Node$OfLong::newArray(int32_t count) {
	return $of($new($longs, count));
}

$StreamShape* Node$OfLong::getShape() {
	$init($StreamShape);
	return $StreamShape::LONG_VALUE;
}

void Node$OfLong::copyInto($ObjectArray* boxed, int32_t offset) {
	this->copyInto($fcast($LongArray, boxed), offset);
}

void Node$OfLong::lambda$truncate$0(int64_t e) {
	$init(Node$OfLong);
}

$Class* Node$OfLong::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Node$OfLong$$Lambda$lambda$truncate$0::classInfo$.name)) {
			return Node$OfLong$$Lambda$lambda$truncate$0::load$(name, initialize);
		}
	}
	$loadClass(Node$OfLong, name, initialize, &_Node$OfLong_ClassInfo_, allocate$Node$OfLong);
	return class$;
}

$Class* Node$OfLong::class$ = nullptr;

		} // stream
	} // util
} // java