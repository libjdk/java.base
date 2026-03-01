#include <java/util/stream/Nodes$InternalNodeSpliterator$OfLong.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/stream/Node$OfLong.h>
#include <java/util/stream/Node$OfPrimitive.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator$OfPrimitive.h>
#include <java/util/stream/Nodes$InternalNodeSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $Node$OfLong = ::java::util::stream::Node$OfLong;
using $Node$OfPrimitive = ::java::util::stream::Node$OfPrimitive;
using $Nodes$InternalNodeSpliterator$OfPrimitive = ::java::util::stream::Nodes$InternalNodeSpliterator$OfPrimitive;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Nodes$InternalNodeSpliterator$OfLong_MethodInfo_[] = {
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
	{"<init>", "(Ljava/util/stream/Node$OfLong;)V", nullptr, 0, $method(Nodes$InternalNodeSpliterator$OfLong, init$, void, $Node$OfLong*)},
	{"forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Nodes$InternalNodeSpliterator$OfLong, forEachRemaining, void, $LongConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Nodes$InternalNodeSpliterator$OfLong, tryAdvance, bool, $LongConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Nodes$InternalNodeSpliterator$OfLong, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Nodes$InternalNodeSpliterator$OfLong_InnerClassesInfo_[] = {
	{"java.util.stream.Nodes$InternalNodeSpliterator", "java.util.stream.Nodes", "InternalNodeSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.Nodes$InternalNodeSpliterator$OfLong", "java.util.stream.Nodes$InternalNodeSpliterator", "OfLong", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive", "java.util.stream.Nodes$InternalNodeSpliterator", "OfPrimitive", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Node$OfLong", "java.util.stream.Node", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Nodes$InternalNodeSpliterator$OfLong_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Nodes$InternalNodeSpliterator$OfLong",
	"java.util.stream.Nodes$InternalNodeSpliterator$OfPrimitive",
	"java.util.Spliterator$OfLong",
	nullptr,
	_Nodes$InternalNodeSpliterator$OfLong_MethodInfo_,
	"Ljava/util/stream/Nodes$InternalNodeSpliterator$OfPrimitive<Ljava/lang/Long;Ljava/util/function/LongConsumer;[JLjava/util/Spliterator$OfLong;Ljava/util/stream/Node$OfLong;>;Ljava/util/Spliterator$OfLong;",
	nullptr,
	_Nodes$InternalNodeSpliterator$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Nodes"
};

$Object* allocate$Nodes$InternalNodeSpliterator$OfLong($Class* clazz) {
	return $of($alloc(Nodes$InternalNodeSpliterator$OfLong));
}

bool Nodes$InternalNodeSpliterator$OfLong::tryAdvance(Object$* consumer) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::tryAdvance(consumer);
}

void Nodes$InternalNodeSpliterator$OfLong::forEachRemaining(Object$* consumer) {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining(consumer);
}

int64_t Nodes$InternalNodeSpliterator$OfLong::estimateSize() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::estimateSize();
}

int32_t Nodes$InternalNodeSpliterator$OfLong::characteristics() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::characteristics();
}

bool Nodes$InternalNodeSpliterator$OfLong::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfLong::forEachRemaining($Consumer* action) {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining(action);
}

int64_t Nodes$InternalNodeSpliterator$OfLong::getExactSizeIfKnown() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::getExactSizeIfKnown();
}

bool Nodes$InternalNodeSpliterator$OfLong::hasCharacteristics(int32_t characteristics) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::hasCharacteristics(characteristics);
}

$Comparator* Nodes$InternalNodeSpliterator$OfLong::getComparator() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::getComparator();
}

int32_t Nodes$InternalNodeSpliterator$OfLong::hashCode() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::hashCode();
}

bool Nodes$InternalNodeSpliterator$OfLong::equals(Object$* obj) {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::equals(obj);
}

$Object* Nodes$InternalNodeSpliterator$OfLong::clone() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::clone();
}

$String* Nodes$InternalNodeSpliterator$OfLong::toString() {
	 return this->$Nodes$InternalNodeSpliterator$OfPrimitive::toString();
}

void Nodes$InternalNodeSpliterator$OfLong::finalize() {
	this->$Nodes$InternalNodeSpliterator$OfPrimitive::finalize();
}

Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Nodes$InternalNodeSpliterator$OfLong, $Spliterator$OfLong, memberClass0$);
}

$Spliterator$OfLong* Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfLong, ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->trySplit());
}

bool Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::tryAdvance($LongConsumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::forEachRemaining($LongConsumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

bool Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

void Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

void Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

bool Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::tryAdvance(Object$* action) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

int64_t Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::estimateSize() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->estimateSize();
}

int64_t Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::getExactSizeIfKnown() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::characteristics() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->characteristics();
}

bool Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::getComparator() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->getComparator();
}

int32_t Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::hashCode() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->hashCode();
}

bool Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::equals(Object$* obj) {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->equals(obj);
}

$Object* Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::clone() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->clone();
}

$String* Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::toString() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->toString();
}

void Nodes$InternalNodeSpliterator$OfLong::MemberClass0$::finalize() {
	return ((Nodes$InternalNodeSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Nodes$InternalNodeSpliterator$OfLong, memberClass0$)))->finalize();
}

void Nodes$InternalNodeSpliterator$OfLong::init$($Node$OfLong* cur) {
	$Nodes$InternalNodeSpliterator$OfPrimitive::init$(cur);
}

void Nodes$InternalNodeSpliterator$OfLong::forEachRemaining($LongConsumer* consumer) {
	$Nodes$InternalNodeSpliterator$OfPrimitive::forEachRemaining($of(consumer));
}

bool Nodes$InternalNodeSpliterator$OfLong::tryAdvance($LongConsumer* consumer) {
	return $Nodes$InternalNodeSpliterator$OfPrimitive::tryAdvance($of(consumer));
}

$Spliterator* Nodes$InternalNodeSpliterator$OfLong::trySplit() {
	return $cast($Spliterator$OfLong, $Nodes$InternalNodeSpliterator$OfPrimitive::trySplit());
}

Nodes$InternalNodeSpliterator$OfLong::Nodes$InternalNodeSpliterator$OfLong() {
}

$Class* Nodes$InternalNodeSpliterator$OfLong::load$($String* name, bool initialize) {
	$loadClass(Nodes$InternalNodeSpliterator$OfLong, name, initialize, &_Nodes$InternalNodeSpliterator$OfLong_ClassInfo_, allocate$Nodes$InternalNodeSpliterator$OfLong);
	return class$;
}

$Class* Nodes$InternalNodeSpliterator$OfLong::class$ = nullptr;

		} // stream
	} // util
} // java