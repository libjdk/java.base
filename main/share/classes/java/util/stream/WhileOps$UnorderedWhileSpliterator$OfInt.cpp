#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/function/IntPredicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

#undef CANCEL_CHECK_COUNT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $IntPredicate = ::java::util::function::IntPredicate;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _WhileOps$UnorderedWhileSpliterator$OfInt_FieldInfo_[] = {
	{"p", "Ljava/util/function/IntPredicate;", nullptr, $FINAL, $field(WhileOps$UnorderedWhileSpliterator$OfInt, p)},
	{"t", "I", nullptr, 0, $field(WhileOps$UnorderedWhileSpliterator$OfInt, t)},
	{}
};

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfInt_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNTHETIC},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/Spliterator$OfInt;ZLjava/util/function/IntPredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt, init$, void, $Spliterator$OfInt*, bool, $IntPredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfInt;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt, init$, void, $Spliterator$OfInt*, WhileOps$UnorderedWhileSpliterator$OfInt*)},
	{"accept", "(I)V", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt, accept, void, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNTHETIC},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfInt_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfInt", $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Dropping", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "Dropping", $STATIC | $FINAL},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfInt_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator",
	"java.util.function.IntConsumer,java.util.Spliterator$OfInt",
	_WhileOps$UnorderedWhileSpliterator$OfInt_FieldInfo_,
	_WhileOps$UnorderedWhileSpliterator$OfInt_MethodInfo_,
	"Ljava/util/stream/WhileOps$UnorderedWhileSpliterator<Ljava/lang/Integer;Ljava/util/Spliterator$OfInt;>;Ljava/util/function/IntConsumer;Ljava/util/Spliterator$OfInt;",
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfInt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfInt($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfInt));
}

int64_t WhileOps$UnorderedWhileSpliterator$OfInt::estimateSize() {
	 return this->$WhileOps$UnorderedWhileSpliterator::estimateSize();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfInt::characteristics() {
	 return this->$WhileOps$UnorderedWhileSpliterator::characteristics();
}

int64_t WhileOps$UnorderedWhileSpliterator$OfInt::getExactSizeIfKnown() {
	 return this->$WhileOps$UnorderedWhileSpliterator::getExactSizeIfKnown();
}

$Comparator* WhileOps$UnorderedWhileSpliterator$OfInt::getComparator() {
	 return this->$WhileOps$UnorderedWhileSpliterator::getComparator();
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::forEachRemaining($Consumer* action) {
	this->$WhileOps$UnorderedWhileSpliterator::forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::hasCharacteristics(int32_t characteristics) {
	 return this->$WhileOps$UnorderedWhileSpliterator::hasCharacteristics(characteristics);
}

int32_t WhileOps$UnorderedWhileSpliterator$OfInt::hashCode() {
	 return this->$WhileOps$UnorderedWhileSpliterator::hashCode();
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::equals(Object$* obj) {
	 return this->$WhileOps$UnorderedWhileSpliterator::equals(obj);
}

$Object* WhileOps$UnorderedWhileSpliterator$OfInt::clone() {
	 return this->$WhileOps$UnorderedWhileSpliterator::clone();
}

$String* WhileOps$UnorderedWhileSpliterator$OfInt::toString() {
	 return this->$WhileOps$UnorderedWhileSpliterator::toString();
}

void WhileOps$UnorderedWhileSpliterator$OfInt::finalize() {
	this->$WhileOps$UnorderedWhileSpliterator::finalize();
}

void WhileOps$UnorderedWhileSpliterator$OfInt::forEachRemaining($IntConsumer* action) {
	$as($Spliterator$OfInt, this)->$Spliterator$OfInt::forEachRemaining(action);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::forEachRemaining(Object$* action) {
	$as($Spliterator$OfInt, this)->$Spliterator$OfInt::forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::tryAdvance(Object$* action) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::tryAdvance(action);
}

WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::MemberClass0$() {
	$patchMemberClass(WhileOps$UnorderedWhileSpliterator$OfInt, $Spliterator$OfInt, memberClass0$);
}

$Spliterator$OfInt* WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfInt, ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->trySplit());
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::tryAdvance($IntConsumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::forEachRemaining($IntConsumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::tryAdvance($Consumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::forEachRemaining(Object$* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::tryAdvance(Object$* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->tryAdvance(action);
}

int64_t WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::estimateSize() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->estimateSize();
}

int64_t WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::getExactSizeIfKnown() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->getExactSizeIfKnown();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::characteristics() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->characteristics();
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::getComparator() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->getComparator();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::hashCode() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->hashCode();
}

bool WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::equals(Object$* obj) {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->equals(obj);
}

$Object* WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::clone() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->clone();
}

$String* WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::toString() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->toString();
}

void WhileOps$UnorderedWhileSpliterator$OfInt::MemberClass0$::finalize() {
	return ((WhileOps$UnorderedWhileSpliterator$OfInt*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfInt, memberClass0$)))->finalize();
}

void WhileOps$UnorderedWhileSpliterator$OfInt::init$($Spliterator$OfInt* s, bool noSplitting, $IntPredicate* p) {
	$WhileOps$UnorderedWhileSpliterator::init$(static_cast<$Spliterator*>(s), noSplitting);
	$set(this, p, p);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::init$($Spliterator$OfInt* s, WhileOps$UnorderedWhileSpliterator$OfInt* parent) {
	$WhileOps$UnorderedWhileSpliterator::init$(static_cast<$Spliterator*>(s), static_cast<$WhileOps$UnorderedWhileSpliterator*>(parent));
	$set(this, p, $nc(parent)->p);
}

void WhileOps$UnorderedWhileSpliterator$OfInt::accept(int32_t t) {
	this->count = (int32_t)((this->count + 1) & (uint32_t)$WhileOps$UnorderedWhileSpliterator::CANCEL_CHECK_COUNT);
	this->t = t;
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfInt::trySplit() {
	return $cast($Spliterator$OfInt, $WhileOps$UnorderedWhileSpliterator::trySplit());
}

WhileOps$UnorderedWhileSpliterator$OfInt::WhileOps$UnorderedWhileSpliterator$OfInt() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfInt::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfInt, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfInt_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfInt);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfInt::class$ = nullptr;

		} // stream
	} // util
} // java