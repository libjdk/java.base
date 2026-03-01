#include <java/util/stream/Nodes$EmptyNode$OfLong.h>

#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Node$OfLong.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes$EmptyNode.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef EMPTY_LONG_ARRAY

using $LongArray = $Array<::java::lang::Long>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $Node = ::java::util::stream::Node;
using $Node$OfLong = ::java::util::stream::Node$OfLong;
using $Nodes = ::java::util::stream::Nodes;
using $Nodes$EmptyNode = ::java::util::stream::Nodes$EmptyNode;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$EmptyNode$OfLong_MethodInfo_[] = {
	{"*asArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*copyInto", "(Ljava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*copyInto", "([Ljava/lang/Object;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*copyInto", "([Ljava/lang/Long;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*count", "()J", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEach", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*forEach", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getChild", "(I)Ljava/util/stream/Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"*getChildCount", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"*getShape", "()Ljava/util/stream/StreamShape;", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Nodes$EmptyNode$OfLong, init$, void)},
	{"asPrimitiveArray", "()[J", nullptr, $PUBLIC, $method(Nodes$EmptyNode$OfLong, asPrimitiveArray, $longs*)},
	{"*newArray", "(I)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"spliterator", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(Nodes$EmptyNode$OfLong, spliterator, $Spliterator*)},
	{"*truncate", "(JJLjava/util/function/IntFunction;)Ljava/util/stream/Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Nodes$EmptyNode$OfLong_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$EmptyNode", "java.util.stream.Nodes", "EmptyNode", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$EmptyNode$OfLong", "java.util.stream.Nodes$EmptyNode", "OfLong", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Node$OfLong", "java.util.stream.Node", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$EmptyNode$OfLong_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$EmptyNode$OfLong",
	"java.util.stream.Nodes$EmptyNode",
	"java.util.stream.Node$OfLong",
	nullptr,
	_Nodes$EmptyNode$OfLong_MethodInfo_,
	"Ljava/util/stream/Nodes$EmptyNode<Ljava/lang/Long;[JLjava/util/function/LongConsumer;>;Ljava/util/stream/Node$OfLong;",
	nullptr,
	_Nodes$EmptyNode$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$EmptyNode$OfLong($Class* clazz) {
	return $of($alloc(Nodes$EmptyNode$OfLong));
}

$ObjectArray* Nodes$EmptyNode$OfLong::asArray($IntFunction* generator) {
	 return this->$Nodes$EmptyNode::asArray(generator);
}

void Nodes$EmptyNode$OfLong::copyInto(Object$* array, int32_t offset) {
	this->$Nodes$EmptyNode::copyInto(array, offset);
}

int64_t Nodes$EmptyNode$OfLong::count() {
	 return this->$Nodes$EmptyNode::count();
}

void Nodes$EmptyNode$OfLong::forEach(Object$* consumer) {
	this->$Nodes$EmptyNode::forEach(consumer);
}

void Nodes$EmptyNode$OfLong::forEach($Consumer* consumer) {
	$as($Node$OfLong, this)->$Node$OfLong::forEach(consumer);
}

int32_t Nodes$EmptyNode$OfLong::getChildCount() {
	 return this->$Nodes$EmptyNode::getChildCount();
}

$Node* Nodes$EmptyNode$OfLong::getChild(int32_t i) {
	 return this->$Nodes$EmptyNode::getChild(i);
}

$Node* Nodes$EmptyNode$OfLong::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	 return this->$Nodes$EmptyNode::truncate(from, to, generator);
}

void Nodes$EmptyNode$OfLong::copyInto($ObjectArray* array, int32_t offset) {
	$as($Node$OfLong, this)->$Node$OfLong::copyInto(array, offset);
}

$StreamShape* Nodes$EmptyNode$OfLong::getShape() {
	 return this->$Nodes$EmptyNode::getShape();
}

int32_t Nodes$EmptyNode$OfLong::hashCode() {
	 return this->$Nodes$EmptyNode::hashCode();
}

bool Nodes$EmptyNode$OfLong::equals(Object$* obj) {
	 return this->$Nodes$EmptyNode::equals(obj);
}

$Object* Nodes$EmptyNode$OfLong::clone() {
	 return this->$Nodes$EmptyNode::clone();
}

$String* Nodes$EmptyNode$OfLong::toString() {
	 return this->$Nodes$EmptyNode::toString();
}

void Nodes$EmptyNode$OfLong::finalize() {
	this->$Nodes$EmptyNode::finalize();
}

void Nodes$EmptyNode$OfLong::copyInto($LongArray* boxed, int32_t offset) {
	$as($Node$OfLong, this)->$Node$OfLong::copyInto(boxed, offset);
}

$Object* Nodes$EmptyNode$OfLong::newArray(int32_t count) {
	 return $as($Node$OfLong, this)->$Node$OfLong::newArray(count);
}

Nodes$EmptyNode$OfLong::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Nodes$EmptyNode$OfLong, $Node$OfLong, memberClass0$);
}

void Nodes$EmptyNode$OfLong::MemberClass0$::forEach($Consumer* consumer) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->forEach(consumer);
}

void Nodes$EmptyNode$OfLong::MemberClass0$::copyInto($LongArray* boxed, int32_t offset) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->copyInto(boxed, offset);
}

$Node$OfLong* Nodes$EmptyNode$OfLong::MemberClass0$::truncate(int64_t from, int64_t to, $IntFunction* generator) {
	return $cast($Node$OfLong, ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->truncate(from, to, generator));
}

$Object* Nodes$EmptyNode$OfLong::MemberClass0$::newArray(int32_t count) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->newArray(count);
}

$StreamShape* Nodes$EmptyNode$OfLong::MemberClass0$::getShape() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->getShape();
}

void Nodes$EmptyNode$OfLong::MemberClass0$::copyInto($ObjectArray* boxed, int32_t offset) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->copyInto(boxed, offset);
}

$Spliterator* Nodes$EmptyNode$OfLong::MemberClass0$::spliterator() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->spliterator();
}

void Nodes$EmptyNode$OfLong::MemberClass0$::forEach(Object$* action) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->forEach(action);
}

$Node* Nodes$EmptyNode$OfLong::MemberClass0$::getChild(int32_t i) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->getChild(i);
}

$ObjectArray* Nodes$EmptyNode$OfLong::MemberClass0$::asArray($IntFunction* generator) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->asArray(generator);
}

$Object* Nodes$EmptyNode$OfLong::MemberClass0$::asPrimitiveArray() {
	return $of(((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->asPrimitiveArray());
}

void Nodes$EmptyNode$OfLong::MemberClass0$::copyInto(Object$* array, int32_t offset) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->copyInto(array, offset);
}

int32_t Nodes$EmptyNode$OfLong::MemberClass0$::getChildCount() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->getChildCount();
}

int64_t Nodes$EmptyNode$OfLong::MemberClass0$::count() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->count();
}

int32_t Nodes$EmptyNode$OfLong::MemberClass0$::hashCode() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->hashCode();
}

bool Nodes$EmptyNode$OfLong::MemberClass0$::equals(Object$* obj) {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->equals(obj);
}

$Object* Nodes$EmptyNode$OfLong::MemberClass0$::clone() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->clone();
}

$String* Nodes$EmptyNode$OfLong::MemberClass0$::toString() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->toString();
}

void Nodes$EmptyNode$OfLong::MemberClass0$::finalize() {
	return ((Nodes$EmptyNode$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$EmptyNode$OfLong, memberClass0$)))->finalize();
}

void Nodes$EmptyNode$OfLong::init$() {
	$Nodes$EmptyNode::init$();
}

$Spliterator* Nodes$EmptyNode$OfLong::spliterator() {
	return $Spliterators::emptyLongSpliterator();
}

$longs* Nodes$EmptyNode$OfLong::asPrimitiveArray() {
	$init($Nodes);
	return $Nodes::EMPTY_LONG_ARRAY;
}

Nodes$EmptyNode$OfLong::Nodes$EmptyNode$OfLong() {
}

$Class* Nodes$EmptyNode$OfLong::load$($String* name, bool initialize) {
	$loadClass(Nodes$EmptyNode$OfLong, name, initialize, &_Nodes$EmptyNode$OfLong_ClassInfo_, allocate$Nodes$EmptyNode$OfLong);
	return class$;
}

$Class* Nodes$EmptyNode$OfLong::class$ = nullptr;

		} // stream
	} // util
} // java