#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfDouble.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfPrimitive.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $Supplier = ::java::util::function::Supplier;
using $StreamSpliterators$DelegatingSpliterator$OfPrimitive = ::java::util::stream::StreamSpliterators$DelegatingSpliterator$OfPrimitive;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _StreamSpliterators$DelegatingSpliterator$OfDouble_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/util/Spliterator$OfDouble;>;)V", 0, $method(StreamSpliterators$DelegatingSpliterator$OfDouble, init$, void, $Supplier*)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$DelegatingSpliterator$OfDouble, forEachRemaining, void, $DoubleConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$DelegatingSpliterator$OfDouble, tryAdvance, bool, $DoubleConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(StreamSpliterators$DelegatingSpliterator$OfDouble, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _StreamSpliterators$DelegatingSpliterator$OfDouble_InnerClassesInfo_[] = {
	{"java.util.stream.StreamSpliterators$DelegatingSpliterator", "java.util.stream.StreamSpliterators", "DelegatingSpliterator", $STATIC},
	{"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfDouble", "java.util.stream.StreamSpliterators$DelegatingSpliterator", "OfDouble", $STATIC | $FINAL},
	{"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfPrimitive", "java.util.stream.StreamSpliterators$DelegatingSpliterator", "OfPrimitive", $STATIC},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _StreamSpliterators$DelegatingSpliterator$OfDouble_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfDouble",
	"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfPrimitive",
	"java.util.Spliterator$OfDouble",
	nullptr,
	_StreamSpliterators$DelegatingSpliterator$OfDouble_MethodInfo_,
	"Ljava/util/stream/StreamSpliterators$DelegatingSpliterator$OfPrimitive<Ljava/lang/Double;Ljava/util/function/DoubleConsumer;Ljava/util/Spliterator$OfDouble;>;Ljava/util/Spliterator$OfDouble;",
	nullptr,
	_StreamSpliterators$DelegatingSpliterator$OfDouble_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.StreamSpliterators"
};

$Object* allocate$StreamSpliterators$DelegatingSpliterator$OfDouble($Class* clazz) {
	return $of($alloc(StreamSpliterators$DelegatingSpliterator$OfDouble));
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::tryAdvance(Object$* consumer) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::tryAdvance(consumer);
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::forEachRemaining(Object$* consumer) {
	this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::forEachRemaining(consumer);
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::tryAdvance($Consumer* consumer) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::tryAdvance(consumer);
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::forEachRemaining($Consumer* consumer) {
	this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::forEachRemaining(consumer);
}

int64_t StreamSpliterators$DelegatingSpliterator$OfDouble::estimateSize() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::estimateSize();
}

int32_t StreamSpliterators$DelegatingSpliterator$OfDouble::characteristics() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::characteristics();
}

$Comparator* StreamSpliterators$DelegatingSpliterator$OfDouble::getComparator() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::getComparator();
}

int64_t StreamSpliterators$DelegatingSpliterator$OfDouble::getExactSizeIfKnown() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::getExactSizeIfKnown();
}

$String* StreamSpliterators$DelegatingSpliterator$OfDouble::toString() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::toString();
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::hasCharacteristics(int32_t characteristics) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::hasCharacteristics(characteristics);
}

int32_t StreamSpliterators$DelegatingSpliterator$OfDouble::hashCode() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::hashCode();
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::equals(Object$* obj) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::equals(obj);
}

$Object* StreamSpliterators$DelegatingSpliterator$OfDouble::clone() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::clone();
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::finalize() {
	this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::finalize();
}

StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::MemberClass0$() {
	$patchMemberClass(StreamSpliterators$DelegatingSpliterator$OfDouble, $Spliterator$OfDouble, memberClass0$);
}

$Spliterator$OfDouble* StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfDouble, ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->trySplit());
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::tryAdvance($DoubleConsumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::forEachRemaining($DoubleConsumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::tryAdvance($Consumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::forEachRemaining(Object$* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::tryAdvance(Object$* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

int64_t StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::estimateSize() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->estimateSize();
}

int64_t StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::getExactSizeIfKnown() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->getExactSizeIfKnown();
}

int32_t StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::characteristics() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->characteristics();
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::getComparator() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->getComparator();
}

int32_t StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::hashCode() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->hashCode();
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::equals(Object$* obj) {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->equals(obj);
}

$Object* StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::clone() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->clone();
}

$String* StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::toString() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->toString();
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::MemberClass0$::finalize() {
	return ((StreamSpliterators$DelegatingSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfDouble, memberClass0$)))->finalize();
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::init$($Supplier* supplier) {
	$StreamSpliterators$DelegatingSpliterator$OfPrimitive::init$(supplier);
}

void StreamSpliterators$DelegatingSpliterator$OfDouble::forEachRemaining($DoubleConsumer* consumer) {
	$StreamSpliterators$DelegatingSpliterator$OfPrimitive::forEachRemaining($of(consumer));
}

bool StreamSpliterators$DelegatingSpliterator$OfDouble::tryAdvance($DoubleConsumer* consumer) {
	return $StreamSpliterators$DelegatingSpliterator$OfPrimitive::tryAdvance($of(consumer));
}

$Spliterator* StreamSpliterators$DelegatingSpliterator$OfDouble::trySplit() {
	return $cast($Spliterator$OfDouble, $StreamSpliterators$DelegatingSpliterator$OfPrimitive::trySplit());
}

StreamSpliterators$DelegatingSpliterator$OfDouble::StreamSpliterators$DelegatingSpliterator$OfDouble() {
}

$Class* StreamSpliterators$DelegatingSpliterator$OfDouble::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$DelegatingSpliterator$OfDouble, name, initialize, &_StreamSpliterators$DelegatingSpliterator$OfDouble_ClassInfo_, allocate$StreamSpliterators$DelegatingSpliterator$OfDouble);
	return class$;
}

$Class* StreamSpliterators$DelegatingSpliterator$OfDouble::class$ = nullptr;

		} // stream
	} // util
} // java