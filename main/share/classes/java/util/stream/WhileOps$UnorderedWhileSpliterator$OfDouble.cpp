#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/DoublePredicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

#undef CANCEL_CHECK_COUNT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _WhileOps$UnorderedWhileSpliterator$OfDouble_FieldInfo_[] = {
	{"p", "Ljava/util/function/DoublePredicate;", nullptr, $FINAL, $field(WhileOps$UnorderedWhileSpliterator$OfDouble, p)},
	{"t", "D", nullptr, 0, $field(WhileOps$UnorderedWhileSpliterator$OfDouble, t)},
	{}
};

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfDouble_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNTHETIC},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/Spliterator$OfDouble;ZLjava/util/function/DoublePredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfDouble, init$, void, $Spliterator$OfDouble*, bool, $DoublePredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfDouble;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfDouble, init$, void, $Spliterator$OfDouble*, WhileOps$UnorderedWhileSpliterator$OfDouble*)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfDouble, accept, void, double)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNTHETIC},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfDouble, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfDouble_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfDouble", $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble", "Dropping", $STATIC | $FINAL},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfDouble_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator",
	"java.util.function.DoubleConsumer,java.util.Spliterator$OfDouble",
	_WhileOps$UnorderedWhileSpliterator$OfDouble_FieldInfo_,
	_WhileOps$UnorderedWhileSpliterator$OfDouble_MethodInfo_,
	"Ljava/util/stream/WhileOps$UnorderedWhileSpliterator<Ljava/lang/Double;Ljava/util/Spliterator$OfDouble;>;Ljava/util/function/DoubleConsumer;Ljava/util/Spliterator$OfDouble;",
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfDouble_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfDouble($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfDouble));
}

int64_t WhileOps$UnorderedWhileSpliterator$OfDouble::estimateSize() {
	 return this->$WhileOps$UnorderedWhileSpliterator::estimateSize();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfDouble::characteristics() {
	 return this->$WhileOps$UnorderedWhileSpliterator::characteristics();
}

int64_t WhileOps$UnorderedWhileSpliterator$OfDouble::getExactSizeIfKnown() {
	 return this->$WhileOps$UnorderedWhileSpliterator::getExactSizeIfKnown();
}

$Comparator* WhileOps$UnorderedWhileSpliterator$OfDouble::getComparator() {
	 return this->$WhileOps$UnorderedWhileSpliterator::getComparator();
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::forEachRemaining($Consumer* action) {
	this->$WhileOps$UnorderedWhileSpliterator::forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::hasCharacteristics(int32_t characteristics) {
	 return this->$WhileOps$UnorderedWhileSpliterator::hasCharacteristics(characteristics);
}

int32_t WhileOps$UnorderedWhileSpliterator$OfDouble::hashCode() {
	 return this->$WhileOps$UnorderedWhileSpliterator::hashCode();
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::equals(Object$* obj) {
	 return this->$WhileOps$UnorderedWhileSpliterator::equals(obj);
}

$Object* WhileOps$UnorderedWhileSpliterator$OfDouble::clone() {
	 return this->$WhileOps$UnorderedWhileSpliterator::clone();
}

$String* WhileOps$UnorderedWhileSpliterator$OfDouble::toString() {
	 return this->$WhileOps$UnorderedWhileSpliterator::toString();
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::finalize() {
	this->$WhileOps$UnorderedWhileSpliterator::finalize();
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::forEachRemaining($DoubleConsumer* action) {
	$as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::forEachRemaining(action);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::forEachRemaining(Object$* action) {
	$as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::tryAdvance(Object$* action) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::tryAdvance(action);
}

WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::MemberClass0$() {
	$patchMemberClass(WhileOps$UnorderedWhileSpliterator$OfDouble, $Spliterator$OfDouble, memberClass0$);
}

$Spliterator$OfDouble* WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfDouble, ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->trySplit());
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::tryAdvance($DoubleConsumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::forEachRemaining($DoubleConsumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::tryAdvance($Consumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::forEachRemaining(Object$* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::tryAdvance(Object$* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->tryAdvance(action);
}

int64_t WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::estimateSize() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->estimateSize();
}

int64_t WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::getExactSizeIfKnown() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->getExactSizeIfKnown();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::characteristics() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->characteristics();
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::getComparator() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->getComparator();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::hashCode() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->hashCode();
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::equals(Object$* obj) {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->equals(obj);
}

$Object* WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::clone() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->clone();
}

$String* WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::toString() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->toString();
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::MemberClass0$::finalize() {
	return ((WhileOps$UnorderedWhileSpliterator$OfDouble*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfDouble, memberClass0$)))->finalize();
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::init$($Spliterator$OfDouble* s, bool noSplitting, $DoublePredicate* p) {
	$WhileOps$UnorderedWhileSpliterator::init$(static_cast<$Spliterator*>(s), noSplitting);
	$set(this, p, p);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::init$($Spliterator$OfDouble* s, WhileOps$UnorderedWhileSpliterator$OfDouble* parent) {
	$WhileOps$UnorderedWhileSpliterator::init$(static_cast<$Spliterator*>(s), static_cast<$WhileOps$UnorderedWhileSpliterator*>(parent));
	$set(this, p, $nc(parent)->p);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble::accept(double t) {
	this->count = (int32_t)((this->count + 1) & (uint32_t)$WhileOps$UnorderedWhileSpliterator::CANCEL_CHECK_COUNT);
	this->t = t;
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfDouble::trySplit() {
	return $cast($Spliterator$OfDouble, $WhileOps$UnorderedWhileSpliterator::trySplit());
}

WhileOps$UnorderedWhileSpliterator$OfDouble::WhileOps$UnorderedWhileSpliterator$OfDouble() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfDouble::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfDouble, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfDouble_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfDouble);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfDouble::class$ = nullptr;

		} // stream
	} // util
} // java