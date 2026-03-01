#include <java/util/stream/Nodes$InternalNodeSpliterator$OfInt.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/stream/Node$OfInt.h>
#include <java/util/stream/Node$OfPrimitive.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator$OfPrimitive.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $Node$OfInt = ::java::util::stream::Node$OfInt;
using $Node$OfPrimitive = ::java::util::stream::Node$OfPrimitive;
using $Nodes$InternalNodeSpliterator$OfPrimitive = ::java::util::stream::Nodes$InternalNodeSpliterator$OfPrimitive;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$InternalNodeSpliterator$OfInt_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC | $FINAL},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC | $ABSTRACT},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/stream/Node$OfInt;)V", nullptr, 0, $method(Nodes$InternalNodeSpliterator$OfInt, init$, void, $Node$OfInt*)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Nodes$InternalNodeSpliterator$OfInt, forEachRemaining, void, $IntConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Nodes$InternalNodeSpliterator$OfInt, tryAdvance, bool, $IntConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$InternalNodeSpliterator$OfInt, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Nodes$InternalNodeSpliterator$OfInt_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$InternalNodeSpliterator", "java.util.stream.Nodes", "InternalNodeSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$InternalNodeSpliterator$OfInt", "java.util.stream.Nodes$InternalNodeSpliterator", "OfInt", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive", "java.util.stream.Nodes$InternalNodeSpliterator", "OfPrimitive", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfInt", "java.util.stream.Node", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$InternalNodeSpliterator$OfInt_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$InternalNodeSpliterator$OfInt",
	"java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive",
	"java.util.Spliterator$OfInt",
	nullptr,
	_Nodes$InternalNodeSpliterator$OfInt_MethodInfo_,
	"Ljava/util/stream/Nodes$InternalNodeSpliterator$OfPrimitive<Ljava/lang/Integer;Ljava/util/function/IntConsumer;[ILjava/util/Spliterator$OfInt;Ljava/util/stream/Node$OfInt;>;Ljava/util/Spliterator$OfInt;",
	nullptr,
	_Nodes$InternalNodeSpliterator$OfInt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$InternalNodeSpliterator$OfInt($Class* clazz) {
	return $of($alloc(Nodes$InternalNodeSpliterator$OfInt));
}

bool Nodes$InternalNodeSpliterator$OfInt::tryAdvance(Object$* consumer) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::tryAdvance(consumer);
}

void Nodes$InternalNodeSpliterator$OfInt::forEachRemaining(Object$* consumer) {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining(consumer);
}

int64_t Nodes$InternalNodeSpliterator$OfInt::estimateSize() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::estimateSize();
}

int32_t Nodes$InternalNodeSpliterator$OfInt::characteristics() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::characteristics();
}

bool Nodes$InternalNodeSpliterator$OfInt::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfInt::forEachRemaining($Consumer* action) {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining(action);
}

int64_t Nodes$InternalNodeSpliterator$OfInt::getExactSizeIfKnown() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::getExactSizeIfKnown();
}

bool Nodes$InternalNodeSpliterator$OfInt::hasCharacteristics(int32_t characteristics) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::hasCharacteristics(characteristics);
}

$Comparator* Nodes$InternalNodeSpliterator$OfInt::getComparator() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::getComparator();
}

int32_t Nodes$InternalNodeSpliterator$OfInt::hashCode() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::hashCode();
}

bool Nodes$InternalNodeSpliterator$OfInt::equals(Object$* obj) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::equals(obj);
}

$Object* Nodes$InternalNodeSpliterator$OfInt::clone() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::clone();
}

$String* Nodes$InternalNodeSpliterator$OfInt::toString() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::toString();
}

void Nodes$InternalNodeSpliterator$OfInt::finalize() {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::finalize();
}

Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Nodes$InternalNodeSpliterator$OfInt, $Spliterator$OfInt, memberClass0$);
}

$Spliterator$OfInt* Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfInt, ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->trySplit());
}

bool Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::tryAdvance($IntConsumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::forEachRemaining($IntConsumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

void Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::tryAdvance(Object$* action) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

int64_t Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::estimateSize() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->estimateSize();
}

int64_t Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::getExactSizeIfKnown() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::characteristics() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->characteristics();
}

bool Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::getComparator() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->getComparator();
}

int32_t Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::hashCode() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->hashCode();
}

bool Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::equals(Object$* obj) {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->equals(obj);
}

$Object* Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::clone() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->clone();
}

$String* Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::toString() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->toString();
}

void Nodes$InternalNodeSpliterator$OfInt::MemberClass0$::finalize() {
	return ((Nodes$InternalNodeSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfInt, memberClass0$)))->finalize();
}

void Nodes$InternalNodeSpliterator$OfInt::init$($Node$OfInt* cur) {
	$Nodes$InternalNodeSpliterator$OfPrimitive::init$(cur);
}

void Nodes$InternalNodeSpliterator$OfInt::forEachRemaining($IntConsumer* consumer) {
	$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining($of(consumer));
}

bool Nodes$InternalNodeSpliterator$OfInt::tryAdvance($IntConsumer* consumer) {
	return $Nodes$InternalNodeSpliterator$OfPrimitive::tryAdvance($of(consumer));
}

$Spliterator* Nodes$InternalNodeSpliterator$OfInt::trySplit() {
	return $cast($Spliterator$OfInt, $Nodes$InternalNodeSpliterator$OfPrimitive::trySplit());
}

Nodes$InternalNodeSpliterator$OfInt::Nodes$InternalNodeSpliterator$OfInt() {
}

$Class* Nodes$InternalNodeSpliterator$OfInt::load$($String* name, bool initialize) {
	$loadClass(Nodes$InternalNodeSpliterator$OfInt, name, initialize, &_Nodes$InternalNodeSpliterator$OfInt_ClassInfo_, allocate$Nodes$InternalNodeSpliterator$OfInt);
	return class$;
}

$Class* Nodes$InternalNodeSpliterator$OfInt::class$ = nullptr;

		} // stream
	} // util
} // java