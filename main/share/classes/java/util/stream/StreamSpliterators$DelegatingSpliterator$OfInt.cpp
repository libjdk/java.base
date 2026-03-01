#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfInt.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfPrimitive.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $Supplier = ::java::util::function::Supplier;
using $StreamSpliterators$DelegatingSpliterator$OfPrimitive = ::java::util::stream::StreamSpliterators$DelegatingSpliterator$OfPrimitive;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _StreamSpliterators$DelegatingSpliterator$OfInt_MethodInfo_[] = {
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
	{"<init>", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/util/Spliterator$OfInt;>;)V", 0, $method(StreamSpliterators$DelegatingSpliterator$OfInt, init$, void, $Supplier*)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$DelegatingSpliterator$OfInt, forEachRemaining, void, $IntConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$DelegatingSpliterator$OfInt, tryAdvance, bool, $IntConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(StreamSpliterators$DelegatingSpliterator$OfInt, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _StreamSpliterators$DelegatingSpliterator$OfInt_InnerClassesInfo_[] = {
	{"java.util.stream.StreamSpliterators$DelegatingSpliterator", "java.util.stream.StreamSpliterators", "DelegatingSpliterator", $STATIC},
	{"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfInt", "java.util.stream.StreamSpliterators$DelegatingSpliterator", "OfInt", $STATIC | $FINAL},
	{"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfPrimitive", "java.util.stream.StreamSpliterators$DelegatingSpliterator", "OfPrimitive", $STATIC},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _StreamSpliterators$DelegatingSpliterator$OfInt_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfInt",
	"java.util.stream.StreamSpliterators$DelegatingSpliterator$OfPrimitive",
	"java.util.Spliterator$OfInt",
	nullptr,
	_StreamSpliterators$DelegatingSpliterator$OfInt_MethodInfo_,
	"Ljava/util/stream/StreamSpliterators$DelegatingSpliterator$OfPrimitive<Ljava/lang/Integer;Ljava/util/function/IntConsumer;Ljava/util/Spliterator$OfInt;>;Ljava/util/Spliterator$OfInt;",
	nullptr,
	_StreamSpliterators$DelegatingSpliterator$OfInt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.StreamSpliterators"
};

$Object* allocate$StreamSpliterators$DelegatingSpliterator$OfInt($Class* clazz) {
	return $of($alloc(StreamSpliterators$DelegatingSpliterator$OfInt));
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::tryAdvance(Object$* consumer) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::tryAdvance(consumer);
}

void StreamSpliterators$DelegatingSpliterator$OfInt::forEachRemaining(Object$* consumer) {
	this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::forEachRemaining(consumer);
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::tryAdvance($Consumer* consumer) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::tryAdvance(consumer);
}

void StreamSpliterators$DelegatingSpliterator$OfInt::forEachRemaining($Consumer* consumer) {
	this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::forEachRemaining(consumer);
}

int64_t StreamSpliterators$DelegatingSpliterator$OfInt::estimateSize() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::estimateSize();
}

int32_t StreamSpliterators$DelegatingSpliterator$OfInt::characteristics() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::characteristics();
}

$Comparator* StreamSpliterators$DelegatingSpliterator$OfInt::getComparator() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::getComparator();
}

int64_t StreamSpliterators$DelegatingSpliterator$OfInt::getExactSizeIfKnown() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::getExactSizeIfKnown();
}

$String* StreamSpliterators$DelegatingSpliterator$OfInt::toString() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::toString();
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::hasCharacteristics(int32_t characteristics) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::hasCharacteristics(characteristics);
}

int32_t StreamSpliterators$DelegatingSpliterator$OfInt::hashCode() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::hashCode();
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::equals(Object$* obj) {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::equals(obj);
}

$Object* StreamSpliterators$DelegatingSpliterator$OfInt::clone() {
	 return this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::clone();
}

void StreamSpliterators$DelegatingSpliterator$OfInt::finalize() {
	this->$StreamSpliterators$DelegatingSpliterator$OfPrimitive::finalize();
}

StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::MemberClass0$() {
	$patchMemberClass(StreamSpliterators$DelegatingSpliterator$OfInt, $Spliterator$OfInt, memberClass0$);
}

$Spliterator$OfInt* StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfInt, ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->trySplit());
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::tryAdvance($IntConsumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::forEachRemaining($IntConsumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::tryAdvance($Consumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

void StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::forEachRemaining(Object$* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::tryAdvance(Object$* action) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

int64_t StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::estimateSize() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->estimateSize();
}

int64_t StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::getExactSizeIfKnown() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->getExactSizeIfKnown();
}

int32_t StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::characteristics() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->characteristics();
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::getComparator() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->getComparator();
}

int32_t StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::hashCode() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->hashCode();
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::equals(Object$* obj) {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->equals(obj);
}

$Object* StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::clone() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->clone();
}

$String* StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::toString() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->toString();
}

void StreamSpliterators$DelegatingSpliterator$OfInt::MemberClass0$::finalize() {
	return ((StreamSpliterators$DelegatingSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DelegatingSpliterator$OfInt, memberClass0$)))->finalize();
}

void StreamSpliterators$DelegatingSpliterator$OfInt::init$($Supplier* supplier) {
	$StreamSpliterators$DelegatingSpliterator$OfPrimitive::init$(supplier);
}

void StreamSpliterators$DelegatingSpliterator$OfInt::forEachRemaining($IntConsumer* consumer) {
	$StreamSpliterators$DelegatingSpliterator$OfPrimitive::forEachRemaining($of(consumer));
}

bool StreamSpliterators$DelegatingSpliterator$OfInt::tryAdvance($IntConsumer* consumer) {
	return $StreamSpliterators$DelegatingSpliterator$OfPrimitive::tryAdvance($of(consumer));
}

$Spliterator* StreamSpliterators$DelegatingSpliterator$OfInt::trySplit() {
	return $cast($Spliterator$OfInt, $StreamSpliterators$DelegatingSpliterator$OfPrimitive::trySplit());
}

StreamSpliterators$DelegatingSpliterator$OfInt::StreamSpliterators$DelegatingSpliterator$OfInt() {
}

$Class* StreamSpliterators$DelegatingSpliterator$OfInt::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$DelegatingSpliterator$OfInt, name, initialize, &_StreamSpliterators$DelegatingSpliterator$OfInt_ClassInfo_, allocate$StreamSpliterators$DelegatingSpliterator$OfInt);
	return class$;
}

$Class* StreamSpliterators$DelegatingSpliterator$OfInt::class$ = nullptr;

		} // stream
	} // util
} // java