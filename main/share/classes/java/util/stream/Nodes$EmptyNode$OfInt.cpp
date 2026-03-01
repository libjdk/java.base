#include <java/util/stream/Nodes$EmptyNode$OfInt.h>

#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Node$OfInt.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes$EmptyNode.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef EMPTY_INT_ARRAY

using $IntegerArray = $Array<::java::lang::Integer>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Node = ::java::util::stream::Node;
using $Node$OfInt = ::java::util::stream::Node$OfInt;
using $Nodes = ::java::util::stream::Nodes;
using $Nodes$EmptyNode = ::java::util::stream::Nodes$EmptyNode;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$EmptyNode$OfInt_MethodInfo_[] = {
	{"*asArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*copyInto", "(Ljava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*copyInto", "([Ljava/lang/Object;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*copyInto", "([Ljava/lang/Integer;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*count", "()J", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getChild", "(I)Ljava/util/stream/Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"*getChildCount", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"*getShape", "()Ljava/util/stream/StreamShape;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Nodes$EmptyNode$OfInt, init$, void)},
	{"asPrimitiveArray", "()[I", nullptr, $PUBLIC, $method(Nodes$EmptyNode$OfInt, asPrimitiveArray, $ints*)},
	{"*newArray", "(I)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"spliterator", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(Nodes$EmptyNode$OfInt, spliterator, $Spliterator*)},
	{"*truncate", "(JJLjava/util/function/IntFunction;)Ljava/util/stream/Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Nodes$EmptyNode$OfInt_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$EmptyNode", "java.util.stream.Nodes", "EmptyNode", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$EmptyNode$OfInt", "java.util.stream.Nodes$EmptyNode", "OfInt", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Node$OfInt", "java.util.stream.Node", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$EmptyNode$OfInt_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$EmptyNode$OfInt",
	"java.util.stream.Nodes$EmptyNode",
	"java.util.stream.Node$OfInt",
	nullptr,
	_Nodes$EmptyNode$OfInt_MethodInfo_,
	"Ljava/util/stream/Nodes$EmptyNode<Ljava/lang/Integer;[ILjava/util/function/IntConsumer;>;Ljava/util/stream/Node$OfInt;",
	nullptr,
	_Nodes$EmptyNode$OfInt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$EmptyNode$OfInt($Class* clazz) {
	return $of($alloc(Nodes$EmptyNode$OfInt));
}

$ObjectArray* Nodes$EmptyNode$OfInt::asArray($IntFunction* generator) {
	 return this->$Nodes$EmptyNode::asArray(generator);
}

void Nodes$EmptyNode$OfInt::copyInto(Object$* array, int32_t offset) {
	this->$Nodes$EmptyNode::copyInto(array, offset);
}

int64_t Nodes$EmptyNode$OfInt::count() {
	 return this->$Nodes$EmptyNode::count();
}

void Nodes$EmptyNode$OfInt::forEach(Object$* consumer) {
	this->$Nodes$EmptyNode::forEach(consumer);
}

void Nodes$EmptyNode$OfInt::forEach($Consumer* consumer) {
	$as($Node$OfInt, this)->$Node$OfInt::forEach(consumer);
}

int32_t Nodes$EmptyNode$OfInt::getChildCount() {
	 return this->$Nodes$EmptyNode::getChildCount();
}

$Node* Nodes$EmptyNode$OfInt::getChild(int32_t i) {
	 return this->$Nodes$EmptyNode::getChild(i);
}

$Node* Nodes$EmptyNode$OfInt::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	 return this->$Nodes$EmptyNode::truncate(from, to, generator);
}

void Nodes$EmptyNode$OfInt::copyInto($ObjectArray* array, int32_t offset) {
	$as($Node$OfInt, this)->$Node$OfInt::copyInto(array, offset);
}

$StreamShape* Nodes$EmptyNode$OfInt::getShape() {
	 return this->$Nodes$EmptyNode::getShape();
}

int32_t Nodes$EmptyNode$OfInt::hashCode() {
	 return this->$Nodes$EmptyNode::hashCode();
}

bool Nodes$EmptyNode$OfInt::equals(Object$* obj) {
	 return this->$Nodes$EmptyNode::equals(obj);
}

$Object* Nodes$EmptyNode$OfInt::clone() {
	 return this->$Nodes$EmptyNode::clone();
}

$String* Nodes$EmptyNode$OfInt::toString() {
	 return this->$Nodes$EmptyNode::toString();
}

void Nodes$EmptyNode$OfInt::finalize() {
	this->$Nodes$EmptyNode::finalize();
}

void Nodes$EmptyNode$OfInt::copyInto($IntegerArray* boxed, int32_t offset) {
	$as($Node$OfInt, this)->$Node$OfInt::copyInto(boxed, offset);
}

$Object* Nodes$EmptyNode$OfInt::newArray(int32_t count) {
	 return $as($Node$OfInt, this)->$Node$OfInt::newArray(count);
}

Nodes$EmptyNode$OfInt::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Nodes$EmptyNode$OfInt, $Node$OfInt, memberClass0$);
}

void Nodes$EmptyNode$OfInt::MemberClass0$::forEach($Consumer* consumer) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->forEach(consumer);
}

void Nodes$EmptyNode$OfInt::MemberClass0$::copyInto($IntegerArray* boxed, int32_t offset) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->copyInto(boxed, offset);
}

$Node$OfInt* Nodes$EmptyNode$OfInt::MemberClass0$::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	return $cast($Node$OfInt, ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->truncate(from, to, generator));
}

$Object* Nodes$EmptyNode$OfInt::MemberClass0$::newArray(int32_t count) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->newArray(count);
}

$StreamShape* Nodes$EmptyNode$OfInt::MemberClass0$::getShape() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->getShape();
}

void Nodes$EmptyNode$OfInt::MemberClass0$::copyInto($ObjectArray* boxed, int32_t offset) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->copyInto(boxed, offset);
}

$Spliterator* Nodes$EmptyNode$OfInt::MemberClass0$::spliterator() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->spliterator();
}

void Nodes$EmptyNode$OfInt::MemberClass0$::forEach(Object$* action) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->forEach(action);
}

$Node* Nodes$EmptyNode$OfInt::MemberClass0$::getChild(int32_t i) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->getChild(i);
}

$ObjectArray* Nodes$EmptyNode$OfInt::MemberClass0$::asArray($IntFunction* generator) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->asArray(generator);
}

$Object* Nodes$EmptyNode$OfInt::MemberClass0$::asPrimitiveArray() {
	return $of(((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->asPrimitiveArray());
}

void Nodes$EmptyNode$OfInt::MemberClass0$::copyInto(Object$* array, int32_t offset) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->copyInto(array, offset);
}

int32_t Nodes$EmptyNode$OfInt::MemberClass0$::getChildCount() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->getChildCount();
}

int64_t Nodes$EmptyNode$OfInt::MemberClass0$::count() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->count();
}

int32_t Nodes$EmptyNode$OfInt::MemberClass0$::hashCode() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->hashCode();
}

bool Nodes$EmptyNode$OfInt::MemberClass0$::equals(Object$* obj) {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->equals(obj);
}

$Object* Nodes$EmptyNode$OfInt::MemberClass0$::clone() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->clone();
}

$String* Nodes$EmptyNode$OfInt::MemberClass0$::toString() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->toString();
}

void Nodes$EmptyNode$OfInt::MemberClass0$::finalize() {
	return ((Nodes$EmptyNode$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfInt, memberClass0$)))->finalize();
}

void Nodes$EmptyNode$OfInt::init$() {
	$Nodes$EmptyNode::init$();
}

$Spliterator* Nodes$EmptyNode$OfInt::spliterator() {
	return $Spliterators::emptyIntSpliterator();
}

$ints* Nodes$EmptyNode$OfInt::asPrimitiveArray() {
	$init($Nodes);
	return $Nodes::EMPTY_INT_ARRAY;
}

Nodes$EmptyNode$OfInt::Nodes$EmptyNode$OfInt() {
}

$Class* Nodes$EmptyNode$OfInt::load$($String* name, bool initialize) {
	$loadClass(Nodes$EmptyNode$OfInt, name, initialize, &_Nodes$EmptyNode$OfInt_ClassInfo_, allocate$Nodes$EmptyNode$OfInt);
	return class$;
}

$Class* Nodes$EmptyNode$OfInt::class$ = nullptr;

		} // stream
	} // util
} // java