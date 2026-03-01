#include <java/util/Spliterators$EmptySpliterator$OfDouble.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators$EmptySpliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterators$EmptySpliterator = ::java::util::Spliterators$EmptySpliterator;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;

namespace java {
	namespace util {

$MethodInfo _Spliterators$EmptySpliterator$OfDouble_MethodInfo_[] = {
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
	{"<init>", "()V", nullptr, 0, $method(Spliterators$EmptySpliterator$OfDouble, init$, void)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Spliterators$EmptySpliterator$OfDouble, forEachRemaining, void, $DoubleConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Spliterators$EmptySpliterator$OfDouble, tryAdvance, bool, $DoubleConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Spliterators$EmptySpliterator$OfDouble, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Spliterators$EmptySpliterator$OfDouble_InnerClassesInfo_[] = {
	{"java.util.Spliterators$EmptySpliterator", "java.util.Spliterators", "EmptySpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterators$EmptySpliterator$OfDouble", "java.util.Spliterators$EmptySpliterator", "OfDouble", $PRIVATE | $STATIC | $FINAL},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Spliterators$EmptySpliterator$OfDouble_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.Spliterators$EmptySpliterator$OfDouble",
	"java.util.Spliterators$EmptySpliterator",
	"java.util.Spliterator$OfDouble",
	nullptr,
	_Spliterators$EmptySpliterator$OfDouble_MethodInfo_,
	"Ljava/util/Spliterators$EmptySpliterator<Ljava/lang/Double;Ljava/util/Spliterator$OfDouble;Ljava/util/function/DoubleConsumer;>;Ljava/util/Spliterator$OfDouble;",
	nullptr,
	_Spliterators$EmptySpliterator$OfDouble_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Spliterators"
};

$Object* allocate$Spliterators$EmptySpliterator$OfDouble($Class* clazz) {
	return $of($alloc(Spliterators$EmptySpliterator$OfDouble));
}

bool Spliterators$EmptySpliterator$OfDouble::tryAdvance(Object$* consumer) {
	 return this->$Spliterators$EmptySpliterator::tryAdvance(consumer);
}

void Spliterators$EmptySpliterator$OfDouble::forEachRemaining(Object$* consumer) {
	this->$Spliterators$EmptySpliterator::forEachRemaining(consumer);
}

int64_t Spliterators$EmptySpliterator$OfDouble::estimateSize() {
	 return this->$Spliterators$EmptySpliterator::estimateSize();
}

int32_t Spliterators$EmptySpliterator$OfDouble::characteristics() {
	 return this->$Spliterators$EmptySpliterator::characteristics();
}

int32_t Spliterators$EmptySpliterator$OfDouble::hashCode() {
	 return this->$Spliterators$EmptySpliterator::hashCode();
}

bool Spliterators$EmptySpliterator$OfDouble::equals(Object$* obj) {
	 return this->$Spliterators$EmptySpliterator::equals(obj);
}

$Object* Spliterators$EmptySpliterator$OfDouble::clone() {
	 return this->$Spliterators$EmptySpliterator::clone();
}

$String* Spliterators$EmptySpliterator$OfDouble::toString() {
	 return this->$Spliterators$EmptySpliterator::toString();
}

void Spliterators$EmptySpliterator$OfDouble::finalize() {
	this->$Spliterators$EmptySpliterator::finalize();
}

bool Spliterators$EmptySpliterator$OfDouble::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfDouble::forEachRemaining($Consumer* action) {
	$as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::forEachRemaining(action);
}

int64_t Spliterators$EmptySpliterator$OfDouble::getExactSizeIfKnown() {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::getExactSizeIfKnown();
}

bool Spliterators$EmptySpliterator$OfDouble::hasCharacteristics(int32_t characteristics) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::hasCharacteristics(characteristics);
}

$Comparator* Spliterators$EmptySpliterator$OfDouble::getComparator() {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::getComparator();
}

Spliterators$EmptySpliterator$OfDouble::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Spliterators$EmptySpliterator$OfDouble, $Spliterator$OfDouble, memberClass0$);
}

$Spliterator$OfDouble* Spliterators$EmptySpliterator$OfDouble::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfDouble, ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->trySplit());
}

bool Spliterators$EmptySpliterator$OfDouble::MemberClass0$::tryAdvance($DoubleConsumer* action) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfDouble::MemberClass0$::forEachRemaining($DoubleConsumer* action) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool Spliterators$EmptySpliterator$OfDouble::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfDouble::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

void Spliterators$EmptySpliterator$OfDouble::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool Spliterators$EmptySpliterator$OfDouble::MemberClass0$::tryAdvance(Object$* action) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

int64_t Spliterators$EmptySpliterator$OfDouble::MemberClass0$::estimateSize() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->estimateSize();
}

int64_t Spliterators$EmptySpliterator$OfDouble::MemberClass0$::getExactSizeIfKnown() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Spliterators$EmptySpliterator$OfDouble::MemberClass0$::characteristics() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->characteristics();
}

bool Spliterators$EmptySpliterator$OfDouble::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Spliterators$EmptySpliterator$OfDouble::MemberClass0$::getComparator() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->getComparator();
}

int32_t Spliterators$EmptySpliterator$OfDouble::MemberClass0$::hashCode() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->hashCode();
}

bool Spliterators$EmptySpliterator$OfDouble::MemberClass0$::equals(Object$* obj) {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->equals(obj);
}

$Object* Spliterators$EmptySpliterator$OfDouble::MemberClass0$::clone() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->clone();
}

$String* Spliterators$EmptySpliterator$OfDouble::MemberClass0$::toString() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->toString();
}

void Spliterators$EmptySpliterator$OfDouble::MemberClass0$::finalize() {
	return ((Spliterators$EmptySpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfDouble, memberClass0$)))->finalize();
}

void Spliterators$EmptySpliterator$OfDouble::init$() {
	$Spliterators$EmptySpliterator::init$();
}

void Spliterators$EmptySpliterator$OfDouble::forEachRemaining($DoubleConsumer* consumer) {
	$Spliterators$EmptySpliterator::forEachRemaining(consumer);
}

bool Spliterators$EmptySpliterator$OfDouble::tryAdvance($DoubleConsumer* consumer) {
	return $Spliterators$EmptySpliterator::tryAdvance(consumer);
}

$Spliterator* Spliterators$EmptySpliterator$OfDouble::trySplit() {
	return $cast($Spliterator$OfDouble, $Spliterators$EmptySpliterator::trySplit());
}

Spliterators$EmptySpliterator$OfDouble::Spliterators$EmptySpliterator$OfDouble() {
}

$Class* Spliterators$EmptySpliterator$OfDouble::load$($String* name, bool initialize) {
	$loadClass(Spliterators$EmptySpliterator$OfDouble, name, initialize, &_Spliterators$EmptySpliterator$OfDouble_ClassInfo_, allocate$Spliterators$EmptySpliterator$OfDouble);
	return class$;
}

$Class* Spliterators$EmptySpliterator$OfDouble::class$ = nullptr;

	} // util
} // java