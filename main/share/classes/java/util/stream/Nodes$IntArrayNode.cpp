#include <java/util/stream/Nodes$IntArrayNode.h>

#include <java/util/Arrays.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/stream/Nodes.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Spliterator = ::java::util::Spliterator;
using $IntConsumer = ::java::util::function::IntConsumer;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _Nodes$IntArrayNode_FieldInfo_[] = {
	{"array", "[I", nullptr, $FINAL, $field(Nodes$IntArrayNode, array)},
	{"curSize", "I", nullptr, 0, $field(Nodes$IntArrayNode, curSize)},
	{}
};

$MethodInfo _Nodes$IntArrayNode_MethodInfo_[] = {
	{"<init>", "(J)V", nullptr, 0, $method(Nodes$IntArrayNode, init$, void, int64_t)},
	{"<init>", "([I)V", nullptr, 0, $method(Nodes$IntArrayNode, init$, void, $ints*)},
	{"asPrimitiveArray", "()[I", nullptr, $PUBLIC, $virtualMethod(Nodes$IntArrayNode, asPrimitiveArray, $Object*)},
	{"copyInto", "([II)V", nullptr, $PUBLIC, $virtualMethod(Nodes$IntArrayNode, copyInto, void, $ints*, int32_t)},
	{"copyInto", "(Ljava/lang/Object;I)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$IntArrayNode, copyInto, void, Object$*, int32_t)},
	{"count", "()J", nullptr, $PUBLIC, $virtualMethod(Nodes$IntArrayNode, count, int64_t)},
	{"forEach", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC, $virtualMethod(Nodes$IntArrayNode, forEach, void, $IntConsumer*)},
	{"forEach", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$IntArrayNode, forEach, void, Object$*)},
	{"spliterator", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(Nodes$IntArrayNode, spliterator, $Spliterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Nodes$IntArrayNode, toString, $String*)},
	{}
};

$InnerClassInfo _Nodes$IntArrayNode_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$IntArrayNode", "java.util.stream.Nodes", "IntArrayNode", $PRIVATE | $STATIC},
	{"java.util.stream.Node$OfInt", "java.util.stream.Node", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$IntArrayNode_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.Nodes$IntArrayNode",
	"java.lang.Object",
	"java.util.stream.Node$OfInt",
	_Nodes$IntArrayNode_FieldInfo_,
	_Nodes$IntArrayNode_MethodInfo_,
	nullptr,
	nullptr,
	_Nodes$IntArrayNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$IntArrayNode($Class* clazz) {
	return $of($alloc(Nodes$IntArrayNode));
}

void Nodes$IntArrayNode::init$(int64_t size) {
	if (size >= (int64_t)2147483639) {
		$throwNew($IllegalArgumentException, "Stream size exceeds max array size"_s);
	}
	$set(this, array, $new($ints, (int32_t)size));
	this->curSize = 0;
}

void Nodes$IntArrayNode::init$($ints* array) {
	$set(this, array, array);
	this->curSize = $nc(array)->length;
}

$Spliterator* Nodes$IntArrayNode::spliterator() {
	return $Arrays::spliterator(this->array, 0, this->curSize);
}

$Object* Nodes$IntArrayNode::asPrimitiveArray() {
	if ($nc(this->array)->length == this->curSize) {
		return $of(this->array);
	} else {
		return $of($Arrays::copyOf(this->array, this->curSize));
	}
}

void Nodes$IntArrayNode::copyInto($ints* dest, int32_t destOffset) {
	$System::arraycopy(this->array, 0, dest, destOffset, this->curSize);
}

int64_t Nodes$IntArrayNode::count() {
	return this->curSize;
}

void Nodes$IntArrayNode::forEach($IntConsumer* consumer) {
	for (int32_t i = 0; i < this->curSize; ++i) {
		$nc(consumer)->accept($nc(this->array)->get(i));
	}
}

$String* Nodes$IntArrayNode::toString() {
	$useLocalCurrentObjectStackCache();
	return $String::format("IntArrayNode[%d][%s]"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf($nc(this->array)->length - this->curSize))),
		$($of($Arrays::toString(this->array)))
	}));
}

void Nodes$IntArrayNode::copyInto(Object$* dest, int32_t destOffset) {
	this->copyInto($cast($ints, dest), destOffset);
}

void Nodes$IntArrayNode::forEach(Object$* consumer) {
	this->forEach($cast($IntConsumer, consumer));
}

Nodes$IntArrayNode::Nodes$IntArrayNode() {
}

$Class* Nodes$IntArrayNode::load$($String* name, bool initialize) {
	$loadClass(Nodes$IntArrayNode, name, initialize, &_Nodes$IntArrayNode_ClassInfo_, allocate$Nodes$IntArrayNode);
	return class$;
}

$Class* Nodes$IntArrayNode::class$ = nullptr;

		} // stream
	} // util
} // java