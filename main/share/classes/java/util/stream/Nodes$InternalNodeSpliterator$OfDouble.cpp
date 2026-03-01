#include <java/util/stream/Nodes$InternalNodeSpliterator$OfDouble.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/stream/Node$OfDouble.h>
#include <java/util/stream/Node$OfPrimitive.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator$OfPrimitive.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $Node$OfDouble = ::java::util::stream::Node$OfDouble;
using $Node$OfPrimitive = ::java::util::stream::Node$OfPrimitive;
using $Nodes$InternalNodeSpliterator$OfPrimitive = ::java::util::stream::Nodes$InternalNodeSpliterator$OfPrimitive;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$InternalNodeSpliterator$OfDouble_MethodInfo_[] = {
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
	{"<init>", "(Ljava/util/stream/Node$OfDouble;)V", nullptr, 0, $method(Nodes$InternalNodeSpliterator$OfDouble, init$, void, $Node$OfDouble*)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Nodes$InternalNodeSpliterator$OfDouble, forEachRemaining, void, $DoubleConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Nodes$InternalNodeSpliterator$OfDouble, tryAdvance, bool, $DoubleConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$InternalNodeSpliterator$OfDouble, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Nodes$InternalNodeSpliterator$OfDouble_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$InternalNodeSpliterator", "java.util.stream.Nodes", "InternalNodeSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$InternalNodeSpliterator$OfDouble", "java.util.stream.Nodes$InternalNodeSpliterator", "OfDouble", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive", "java.util.stream.Nodes$InternalNodeSpliterator", "OfPrimitive", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfDouble", "java.util.stream.Node", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$InternalNodeSpliterator$OfDouble_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$InternalNodeSpliterator$OfDouble",
	"java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive",
	"java.util.Spliterator$OfDouble",
	nullptr,
	_Nodes$InternalNodeSpliterator$OfDouble_MethodInfo_,
	"Ljava/util/stream/Nodes$InternalNodeSpliterator$OfPrimitive<Ljava/lang/Double;Ljava/util/function/DoubleConsumer;[DLjava/util/Spliterator$OfDouble;Ljava/util/stream/Node$OfDouble;>;Ljava/util/Spliterator$OfDouble;",
	nullptr,
	_Nodes$InternalNodeSpliterator$OfDouble_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$InternalNodeSpliterator$OfDouble($Class* clazz) {
	return $of($alloc(Nodes$InternalNodeSpliterator$OfDouble));
}

bool Nodes$InternalNodeSpliterator$OfDouble::tryAdvance(Object$* consumer) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::tryAdvance(consumer);
}

void Nodes$InternalNodeSpliterator$OfDouble::forEachRemaining(Object$* consumer) {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining(consumer);
}

int64_t Nodes$InternalNodeSpliterator$OfDouble::estimateSize() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::estimateSize();
}

int32_t Nodes$InternalNodeSpliterator$OfDouble::characteristics() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::characteristics();
}

bool Nodes$InternalNodeSpliterator$OfDouble::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfDouble::forEachRemaining($Consumer* action) {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining(action);
}

int64_t Nodes$InternalNodeSpliterator$OfDouble::getExactSizeIfKnown() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::getExactSizeIfKnown();
}

bool Nodes$InternalNodeSpliterator$OfDouble::hasCharacteristics(int32_t characteristics) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::hasCharacteristics(characteristics);
}

$Comparator* Nodes$InternalNodeSpliterator$OfDouble::getComparator() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::getComparator();
}

int32_t Nodes$InternalNodeSpliterator$OfDouble::hashCode() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::hashCode();
}

bool Nodes$InternalNodeSpliterator$OfDouble::equals(Object$* obj) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::equals(obj);
}

$Object* Nodes$InternalNodeSpliterator$OfDouble::clone() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::clone();
}

$String* Nodes$InternalNodeSpliterator$OfDouble::toString() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::toString();
}

void Nodes$InternalNodeSpliterator$OfDouble::finalize() {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::finalize();
}

Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Nodes$InternalNodeSpliterator$OfDouble, $Spliterator$OfDouble, memberClass0$);
}

$Spliterator$OfDouble* Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfDouble, ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->trySplit());
}

bool Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::tryAdvance($DoubleConsumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::forEachRemaining($DoubleConsumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

void Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::tryAdvance(Object$* action) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

int64_t Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::estimateSize() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->estimateSize();
}

int64_t Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::getExactSizeIfKnown() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::characteristics() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->characteristics();
}

bool Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::getComparator() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->getComparator();
}

int32_t Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::hashCode() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->hashCode();
}

bool Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::equals(Object$* obj) {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->equals(obj);
}

$Object* Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::clone() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->clone();
}

$String* Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::toString() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->toString();
}

void Nodes$InternalNodeSpliterator$OfDouble::MemberClass0$::finalize() {
	return ((Nodes$InternalNodeSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfDouble, memberClass0$)))->finalize();
}

void Nodes$InternalNodeSpliterator$OfDouble::init$($Node$OfDouble* cur) {
	$Nodes$InternalNodeSpliterator$OfPrimitive::init$(cur);
}

void Nodes$InternalNodeSpliterator$OfDouble::forEachRemaining($DoubleConsumer* consumer) {
	$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining($of(consumer));
}

bool Nodes$InternalNodeSpliterator$OfDouble::tryAdvance($DoubleConsumer* consumer) {
	return $Nodes$InternalNodeSpliterator$OfPrimitive::tryAdvance($of(consumer));
}

$Spliterator* Nodes$InternalNodeSpliterator$OfDouble::trySplit() {
	return $cast($Spliterator$OfDouble, $Nodes$InternalNodeSpliterator$OfPrimitive::trySplit());
}

Nodes$InternalNodeSpliterator$OfDouble::Nodes$InternalNodeSpliterator$OfDouble() {
}

$Class* Nodes$InternalNodeSpliterator$OfDouble::load$($String* name, bool initialize) {
	$loadClass(Nodes$InternalNodeSpliterator$OfDouble, name, initialize, &_Nodes$InternalNodeSpliterator$OfDouble_ClassInfo_, allocate$Nodes$InternalNodeSpliterator$OfDouble);
	return class$;
}

$Class* Nodes$InternalNodeSpliterator$OfDouble::class$ = nullptr;

		} // stream
	} // util
} // java