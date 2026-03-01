#include <java/util/stream/Nodes$EmptyNode$OfDouble.h>

#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Node$OfDouble.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes$EmptyNode.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef EMPTY_DOUBLE_ARRAY

using $DoubleArray = $Array<::java::lang::Double>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Node = ::java::util::stream::Node;
using $Node$OfDouble = ::java::util::stream::Node$OfDouble;
using $Nodes = ::java::util::stream::Nodes;
using $Nodes$EmptyNode = ::java::util::stream::Nodes$EmptyNode;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$EmptyNode$OfDouble_MethodInfo_[] = {
	{"*asArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*copyInto", "(Ljava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*copyInto", "([Ljava/lang/Object;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*copyInto", "([Ljava/lang/Double;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*count", "()J", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getChild", "(I)Ljava/util/stream/Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"*getChildCount", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"*getShape", "()Ljava/util/stream/StreamShape;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Nodes$EmptyNode$OfDouble, init$, void)},
	{"asPrimitiveArray", "()[D", nullptr, $PUBLIC, $method(Nodes$EmptyNode$OfDouble, asPrimitiveArray, $doubles*)},
	{"*newArray", "(I)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"spliterator", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(Nodes$EmptyNode$OfDouble, spliterator, $Spliterator*)},
	{"*truncate", "(JJLjava/util/function/IntFunction;)Ljava/util/stream/Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Nodes$EmptyNode$OfDouble_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$EmptyNode", "java.util.stream.Nodes", "EmptyNode", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$EmptyNode$OfDouble", "java.util.stream.Nodes$EmptyNode", "OfDouble", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Node$OfDouble", "java.util.stream.Node", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$EmptyNode$OfDouble_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$EmptyNode$OfDouble",
	"java.util.stream.Nodes$EmptyNode",
	"java.util.stream.Node$OfDouble",
	nullptr,
	_Nodes$EmptyNode$OfDouble_MethodInfo_,
	"Ljava/util/stream/Nodes$EmptyNode<Ljava/lang/Double;[DLjava/util/function/DoubleConsumer;>;Ljava/util/stream/Node$OfDouble;",
	nullptr,
	_Nodes$EmptyNode$OfDouble_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$EmptyNode$OfDouble($Class* clazz) {
	return $of($alloc(Nodes$EmptyNode$OfDouble));
}

$ObjectArray* Nodes$EmptyNode$OfDouble::asArray($IntFunction* generator) {
	 return this->$Nodes$EmptyNode::asArray(generator);
}

void Nodes$EmptyNode$OfDouble::copyInto(Object$* array, int32_t offset) {
	this->$Nodes$EmptyNode::copyInto(array, offset);
}

int64_t Nodes$EmptyNode$OfDouble::count() {
	 return this->$Nodes$EmptyNode::count();
}

void Nodes$EmptyNode$OfDouble::forEach(Object$* consumer) {
	this->$Nodes$EmptyNode::forEach(consumer);
}

void Nodes$EmptyNode$OfDouble::forEach($Consumer* consumer) {
	$as($Node$OfDouble, this)->$Node$OfDouble::forEach(consumer);
}

int32_t Nodes$EmptyNode$OfDouble::getChildCount() {
	 return this->$Nodes$EmptyNode::getChildCount();
}

$Node* Nodes$EmptyNode$OfDouble::getChild(int32_t i) {
	 return this->$Nodes$EmptyNode::getChild(i);
}

$Node* Nodes$EmptyNode$OfDouble::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	 return this->$Nodes$EmptyNode::truncate(from, to, generator);
}

void Nodes$EmptyNode$OfDouble::copyInto($ObjectArray* array, int32_t offset) {
	$as($Node$OfDouble, this)->$Node$OfDouble::copyInto(array, offset);
}

$StreamShape* Nodes$EmptyNode$OfDouble::getShape() {
	 return this->$Nodes$EmptyNode::getShape();
}

int32_t Nodes$EmptyNode$OfDouble::hashCode() {
	 return this->$Nodes$EmptyNode::hashCode();
}

bool Nodes$EmptyNode$OfDouble::equals(Object$* obj) {
	 return this->$Nodes$EmptyNode::equals(obj);
}

$Object* Nodes$EmptyNode$OfDouble::clone() {
	 return this->$Nodes$EmptyNode::clone();
}

$String* Nodes$EmptyNode$OfDouble::toString() {
	 return this->$Nodes$EmptyNode::toString();
}

void Nodes$EmptyNode$OfDouble::finalize() {
	this->$Nodes$EmptyNode::finalize();
}

void Nodes$EmptyNode$OfDouble::copyInto($DoubleArray* boxed, int32_t offset) {
	$as($Node$OfDouble, this)->$Node$OfDouble::copyInto(boxed, offset);
}

$Object* Nodes$EmptyNode$OfDouble::newArray(int32_t count) {
	 return $as($Node$OfDouble, this)->$Node$OfDouble::newArray(count);
}

Nodes$EmptyNode$OfDouble::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Nodes$EmptyNode$OfDouble, $Node$OfDouble, memberClass0$);
}

void Nodes$EmptyNode$OfDouble::MemberClass0$::forEach($Consumer* consumer) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->forEach(consumer);
}

void Nodes$EmptyNode$OfDouble::MemberClass0$::copyInto($DoubleArray* boxed, int32_t offset) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->copyInto(boxed, offset);
}

$Node$OfDouble* Nodes$EmptyNode$OfDouble::MemberClass0$::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	return $cast($Node$OfDouble, ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->truncate(from, to, generator));
}

$Object* Nodes$EmptyNode$OfDouble::MemberClass0$::newArray(int32_t count) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->newArray(count);
}

$StreamShape* Nodes$EmptyNode$OfDouble::MemberClass0$::getShape() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->getShape();
}

void Nodes$EmptyNode$OfDouble::MemberClass0$::copyInto($ObjectArray* boxed, int32_t offset) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->copyInto(boxed, offset);
}

$Spliterator* Nodes$EmptyNode$OfDouble::MemberClass0$::spliterator() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->spliterator();
}

void Nodes$EmptyNode$OfDouble::MemberClass0$::forEach(Object$* action) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->forEach(action);
}

$Node* Nodes$EmptyNode$OfDouble::MemberClass0$::getChild(int32_t i) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->getChild(i);
}

$ObjectArray* Nodes$EmptyNode$OfDouble::MemberClass0$::asArray($IntFunction* generator) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->asArray(generator);
}

$Object* Nodes$EmptyNode$OfDouble::MemberClass0$::asPrimitiveArray() {
	return $of(((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->asPrimitiveArray());
}

void Nodes$EmptyNode$OfDouble::MemberClass0$::copyInto(Object$* array, int32_t offset) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->copyInto(array, offset);
}

int32_t Nodes$EmptyNode$OfDouble::MemberClass0$::getChildCount() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->getChildCount();
}

int64_t Nodes$EmptyNode$OfDouble::MemberClass0$::count() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->count();
}

int32_t Nodes$EmptyNode$OfDouble::MemberClass0$::hashCode() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->hashCode();
}

bool Nodes$EmptyNode$OfDouble::MemberClass0$::equals(Object$* obj) {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->equals(obj);
}

$Object* Nodes$EmptyNode$OfDouble::MemberClass0$::clone() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->clone();
}

$String* Nodes$EmptyNode$OfDouble::MemberClass0$::toString() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->toString();
}

void Nodes$EmptyNode$OfDouble::MemberClass0$::finalize() {
	return ((Nodes$EmptyNode$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfDouble, memberClass0$)))->finalize();
}

void Nodes$EmptyNode$OfDouble::init$() {
	$Nodes$EmptyNode::init$();
}

$Spliterator* Nodes$EmptyNode$OfDouble::spliterator() {
	return $Spliterators::emptyDoubleSpliterator();
}

$doubles* Nodes$EmptyNode$OfDouble::asPrimitiveArray() {
	$init($Nodes);
	return $Nodes::EMPTY_DOUBLE_ARRAY;
}

Nodes$EmptyNode$OfDouble::Nodes$EmptyNode$OfDouble() {
}

$Class* Nodes$EmptyNode$OfDouble::load$($String* name, bool initialize) {
	$loadClass(Nodes$EmptyNode$OfDouble, name, initialize, &_Nodes$EmptyNode$OfDouble_ClassInfo_, allocate$Nodes$EmptyNode$OfDouble);
	return class$;
}

$Class* Nodes$EmptyNode$OfDouble::class$ = nullptr;

		} // stream
	} // util
} // java