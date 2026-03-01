#include <java/util/Spliterators$EmptySpliterator$OfInt.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators$EmptySpliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterators$EmptySpliterator = ::java::util::Spliterators$EmptySpliterator;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;

namespace java {
	namespace util {

$MethodInfo _Spliterators$EmptySpliterator$OfInt_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC | $ABSTRACT},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Spliterators$EmptySpliterator$OfInt, init$, void)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Spliterators$EmptySpliterator$OfInt, forEachRemaining, void, $IntConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Spliterators$EmptySpliterator$OfInt, tryAdvance, bool, $IntConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Spliterators$EmptySpliterator$OfInt, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Spliterators$EmptySpliterator$OfInt_InnerClassesInfo_[] = {
	{"java.util.Spliterators$EmptySpliterator", "java.util.Spliterators", "EmptySpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterators$EmptySpliterator$OfInt", "java.util.Spliterators$EmptySpliterator", "OfInt", $PRIVATE | $STATIC | $FINAL},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Spliterators$EmptySpliterator$OfInt_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.Spliterators$EmptySpliterator$OfInt",
	"java.util.Spliterators$EmptySpliterator",
	"java.util.Spliterator$OfInt",
	nullptr,
	_Spliterators$EmptySpliterator$OfInt_MethodInfo_,
	"Ljava/util/Spliterators$EmptySpliterator<Ljava/lang/Integer;Ljava/util/Spliterator$OfInt;Ljava/util/function/IntConsumer;>;Ljava/util/Spliterator$OfInt;",
	nullptr,
	_Spliterators$EmptySpliterator$OfInt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Spliterators"
};

$Object* allocate$Spliterators$EmptySpliterator$OfInt($Class* clazz) {
	return $of($alloc(Spliterators$EmptySpliterator$OfInt));
}

bool Spliterators$EmptySpliterator$OfInt::tryAdvance(Object$* consumer) {
	 return this->$Spliterators$EmptySpliterator::tryAdvance(consumer);
}

void Spliterators$EmptySpliterator$OfInt::forEachRemaining(Object$* consumer) {
	this->$Spliterators$EmptySpliterator::forEachRemaining(consumer);
}

int64_t Spliterators$EmptySpliterator$OfInt::estimateSize() {
	 return this->$Spliterators$EmptySpliterator::estimateSize();
}

int32_t Spliterators$EmptySpliterator$OfInt::characteristics() {
	 return this->$Spliterators$EmptySpliterator::characteristics();
}

int32_t Spliterators$EmptySpliterator$OfInt::hashCode() {
	 return this->$Spliterators$EmptySpliterator::hashCode();
}

bool Spliterators$EmptySpliterator$OfInt::equals(Object$* obj) {
	 return this->$Spliterators$EmptySpliterator::equals(obj);
}

$Object* Spliterators$EmptySpliterator$OfInt::clone() {
	 return this->$Spliterators$EmptySpliterator::clone();
}

$String* Spliterators$EmptySpliterator$OfInt::toString() {
	 return this->$Spliterators$EmptySpliterator::toString();
}

void Spliterators$EmptySpliterator$OfInt::finalize() {
	this->$Spliterators$EmptySpliterator::finalize();
}

bool Spliterators$EmptySpliterator$OfInt::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfInt::forEachRemaining($Consumer* action) {
	$as($Spliterator$OfInt, this)->$Spliterator$OfInt::forEachRemaining(action);
}

int64_t Spliterators$EmptySpliterator$OfInt::getExactSizeIfKnown() {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::getExactSizeIfKnown();
}

bool Spliterators$EmptySpliterator$OfInt::hasCharacteristics(int32_t characteristics) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::hasCharacteristics(characteristics);
}

$Comparator* Spliterators$EmptySpliterator$OfInt::getComparator() {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::getComparator();
}

Spliterators$EmptySpliterator$OfInt::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Spliterators$EmptySpliterator$OfInt, $Spliterator$OfInt, memberClass0$);
}

$Spliterator$OfInt* Spliterators$EmptySpliterator$OfInt::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfInt, ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->trySplit());
}

bool Spliterators$EmptySpliterator$OfInt::MemberClass0$::tryAdvance($IntConsumer* action) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfInt::MemberClass0$::forEachRemaining($IntConsumer* action) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool Spliterators$EmptySpliterator$OfInt::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfInt::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

void Spliterators$EmptySpliterator$OfInt::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool Spliterators$EmptySpliterator$OfInt::MemberClass0$::tryAdvance(Object$* action) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

int64_t Spliterators$EmptySpliterator$OfInt::MemberClass0$::estimateSize() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->estimateSize();
}

int64_t Spliterators$EmptySpliterator$OfInt::MemberClass0$::getExactSizeIfKnown() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Spliterators$EmptySpliterator$OfInt::MemberClass0$::characteristics() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->characteristics();
}

bool Spliterators$EmptySpliterator$OfInt::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Spliterators$EmptySpliterator$OfInt::MemberClass0$::getComparator() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->getComparator();
}

int32_t Spliterators$EmptySpliterator$OfInt::MemberClass0$::hashCode() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->hashCode();
}

bool Spliterators$EmptySpliterator$OfInt::MemberClass0$::equals(Object$* obj) {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->equals(obj);
}

$Object* Spliterators$EmptySpliterator$OfInt::MemberClass0$::clone() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->clone();
}

$String* Spliterators$EmptySpliterator$OfInt::MemberClass0$::toString() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->toString();
}

void Spliterators$EmptySpliterator$OfInt::MemberClass0$::finalize() {
	return ((Spliterators$EmptySpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfInt, memberClass0$)))->finalize();
}

void Spliterators$EmptySpliterator$OfInt::init$() {
	$Spliterators$EmptySpliterator::init$();
}

void Spliterators$EmptySpliterator$OfInt::forEachRemaining($IntConsumer* consumer) {
	$Spliterators$EmptySpliterator::forEachRemaining(consumer);
}

bool Spliterators$EmptySpliterator$OfInt::tryAdvance($IntConsumer* consumer) {
	return $Spliterators$EmptySpliterator::tryAdvance(consumer);
}

$Spliterator* Spliterators$EmptySpliterator$OfInt::trySplit() {
	return $cast($Spliterator$OfInt, $Spliterators$EmptySpliterator::trySplit());
}

Spliterators$EmptySpliterator$OfInt::Spliterators$EmptySpliterator$OfInt() {
}

$Class* Spliterators$EmptySpliterator$OfInt::load$($String* name, bool initialize) {
	$loadClass(Spliterators$EmptySpliterator$OfInt, name, initialize, &_Spliterators$EmptySpliterator$OfInt_ClassInfo_, allocate$Spliterators$EmptySpliterator$OfInt);
	return class$;
}

$Class* Spliterators$EmptySpliterator$OfInt::class$ = nullptr;

	} // util
} // java