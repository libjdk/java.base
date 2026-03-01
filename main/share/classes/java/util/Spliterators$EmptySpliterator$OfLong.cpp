#include <java/util/Spliterators$EmptySpliterator$OfLong.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators$EmptySpliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Spliterators$EmptySpliterator = ::java::util::Spliterators$EmptySpliterator;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;

namespace java {
	namespace util {

$MethodInfo _Spliterators$EmptySpliterator$OfLong_MethodInfo_[] = {
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
	{"<init>", "()V", nullptr, 0, $method(Spliterators$EmptySpliterator$OfLong, init$, void)},
	{"forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Spliterators$EmptySpliterator$OfLong, forEachRemaining, void, $LongConsumer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Spliterators$EmptySpliterator$OfLong, tryAdvance, bool, $LongConsumer*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Spliterators$EmptySpliterator$OfLong, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Spliterators$EmptySpliterator$OfLong_InnerClassesInfo_[] = {
	{"java.util.Spliterators$EmptySpliterator", "java.util.Spliterators", "EmptySpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterators$EmptySpliterator$OfLong", "java.util.Spliterators$EmptySpliterator", "OfLong", $PRIVATE | $STATIC | $FINAL},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Spliterators$EmptySpliterator$OfLong_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.Spliterators$EmptySpliterator$OfLong",
	"java.util.Spliterators$EmptySpliterator",
	"java.util.Spliterator$OfLong",
	nullptr,
	_Spliterators$EmptySpliterator$OfLong_MethodInfo_,
	"Ljava/util/Spliterators$EmptySpliterator<Ljava/lang/Long;Ljava/util/Spliterator$OfLong;Ljava/util/function/LongConsumer;>;Ljava/util/Spliterator$OfLong;",
	nullptr,
	_Spliterators$EmptySpliterator$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Spliterators"
};

$Object* allocate$Spliterators$EmptySpliterator$OfLong($Class* clazz) {
	return $of($alloc(Spliterators$EmptySpliterator$OfLong));
}

bool Spliterators$EmptySpliterator$OfLong::tryAdvance(Object$* consumer) {
	 return this->$Spliterators$EmptySpliterator::tryAdvance(consumer);
}

void Spliterators$EmptySpliterator$OfLong::forEachRemaining(Object$* consumer) {
	this->$Spliterators$EmptySpliterator::forEachRemaining(consumer);
}

int64_t Spliterators$EmptySpliterator$OfLong::estimateSize() {
	 return this->$Spliterators$EmptySpliterator::estimateSize();
}

int32_t Spliterators$EmptySpliterator$OfLong::characteristics() {
	 return this->$Spliterators$EmptySpliterator::characteristics();
}

int32_t Spliterators$EmptySpliterator$OfLong::hashCode() {
	 return this->$Spliterators$EmptySpliterator::hashCode();
}

bool Spliterators$EmptySpliterator$OfLong::equals(Object$* obj) {
	 return this->$Spliterators$EmptySpliterator::equals(obj);
}

$Object* Spliterators$EmptySpliterator$OfLong::clone() {
	 return this->$Spliterators$EmptySpliterator::clone();
}

$String* Spliterators$EmptySpliterator$OfLong::toString() {
	 return this->$Spliterators$EmptySpliterator::toString();
}

void Spliterators$EmptySpliterator$OfLong::finalize() {
	this->$Spliterators$EmptySpliterator::finalize();
}

bool Spliterators$EmptySpliterator$OfLong::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfLong::forEachRemaining($Consumer* action) {
	$as($Spliterator$OfLong, this)->$Spliterator$OfLong::forEachRemaining(action);
}

int64_t Spliterators$EmptySpliterator$OfLong::getExactSizeIfKnown() {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::getExactSizeIfKnown();
}

bool Spliterators$EmptySpliterator$OfLong::hasCharacteristics(int32_t characteristics) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::hasCharacteristics(characteristics);
}

$Comparator* Spliterators$EmptySpliterator$OfLong::getComparator() {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::getComparator();
}

Spliterators$EmptySpliterator$OfLong::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Spliterators$EmptySpliterator$OfLong, $Spliterator$OfLong, memberClass0$);
}

$Spliterator$OfLong* Spliterators$EmptySpliterator$OfLong::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfLong, ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->trySplit());
}

bool Spliterators$EmptySpliterator$OfLong::MemberClass0$::tryAdvance($LongConsumer* action) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfLong::MemberClass0$::forEachRemaining($LongConsumer* action) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

bool Spliterators$EmptySpliterator$OfLong::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

void Spliterators$EmptySpliterator$OfLong::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

void Spliterators$EmptySpliterator$OfLong::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

bool Spliterators$EmptySpliterator$OfLong::MemberClass0$::tryAdvance(Object$* action) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

int64_t Spliterators$EmptySpliterator$OfLong::MemberClass0$::estimateSize() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->estimateSize();
}

int64_t Spliterators$EmptySpliterator$OfLong::MemberClass0$::getExactSizeIfKnown() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Spliterators$EmptySpliterator$OfLong::MemberClass0$::characteristics() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->characteristics();
}

bool Spliterators$EmptySpliterator$OfLong::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Spliterators$EmptySpliterator$OfLong::MemberClass0$::getComparator() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->getComparator();
}

int32_t Spliterators$EmptySpliterator$OfLong::MemberClass0$::hashCode() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->hashCode();
}

bool Spliterators$EmptySpliterator$OfLong::MemberClass0$::equals(Object$* obj) {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->equals(obj);
}

$Object* Spliterators$EmptySpliterator$OfLong::MemberClass0$::clone() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->clone();
}

$String* Spliterators$EmptySpliterator$OfLong::MemberClass0$::toString() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->toString();
}

void Spliterators$EmptySpliterator$OfLong::MemberClass0$::finalize() {
	return ((Spliterators$EmptySpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(Spliterators$EmptySpliterator$OfLong, memberClass0$)))->finalize();
}

void Spliterators$EmptySpliterator$OfLong::init$() {
	$Spliterators$EmptySpliterator::init$();
}

void Spliterators$EmptySpliterator$OfLong::forEachRemaining($LongConsumer* consumer) {
	$Spliterators$EmptySpliterator::forEachRemaining(consumer);
}

bool Spliterators$EmptySpliterator$OfLong::tryAdvance($LongConsumer* consumer) {
	return $Spliterators$EmptySpliterator::tryAdvance(consumer);
}

$Spliterator* Spliterators$EmptySpliterator$OfLong::trySplit() {
	return $cast($Spliterator$OfLong, $Spliterators$EmptySpliterator::trySplit());
}

Spliterators$EmptySpliterator$OfLong::Spliterators$EmptySpliterator$OfLong() {
}

$Class* Spliterators$EmptySpliterator$OfLong::load$($String* name, bool initialize) {
	$loadClass(Spliterators$EmptySpliterator$OfLong, name, initialize, &_Spliterators$EmptySpliterator$OfLong_ClassInfo_, allocate$Spliterators$EmptySpliterator$OfLong);
	return class$;
}

$Class* Spliterators$EmptySpliterator$OfLong::class$ = nullptr;

	} // util
} // java