#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong.h>

#include <java/util/Comparator.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/function/LongPredicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

#undef CANCEL_CHECK_COUNT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $LongPredicate = ::java::util::function::LongPredicate;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _WhileOps$UnorderedWhileSpliterator$OfLong_FieldInfo_[] = {
	{"p", "Ljava/util/function/LongPredicate;", nullptr, $FINAL, $field(WhileOps$UnorderedWhileSpliterator$OfLong, p)},
	{"t", "J", nullptr, 0, $field(WhileOps$UnorderedWhileSpliterator$OfLong, t)},
	{}
};

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfLong_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNTHETIC},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/Spliterator$OfLong;ZLjava/util/function/LongPredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong, init$, void, $Spliterator$OfLong*, bool, $LongPredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfLong;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong, init$, void, $Spliterator$OfLong*, WhileOps$UnorderedWhileSpliterator$OfLong*)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong, accept, void, int64_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNTHETIC},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfLong_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfLong", $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Dropping", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "Dropping", $STATIC | $FINAL},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfLong_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator",
	"java.util.function.LongConsumer,java.util.Spliterator$OfLong",
	_WhileOps$UnorderedWhileSpliterator$OfLong_FieldInfo_,
	_WhileOps$UnorderedWhileSpliterator$OfLong_MethodInfo_,
	"Ljava/util/stream/WhileOps$UnorderedWhileSpliterator<Ljava/lang/Long;Ljava/util/Spliterator$OfLong;>;Ljava/util/function/LongConsumer;Ljava/util/Spliterator$OfLong;",
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfLong($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfLong));
}

int64_t WhileOps$UnorderedWhileSpliterator$OfLong::estimateSize() {
	 return this->$WhileOps$UnorderedWhileSpliterator::estimateSize();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfLong::characteristics() {
	 return this->$WhileOps$UnorderedWhileSpliterator::characteristics();
}

int64_t WhileOps$UnorderedWhileSpliterator$OfLong::getExactSizeIfKnown() {
	 return this->$WhileOps$UnorderedWhileSpliterator::getExactSizeIfKnown();
}

$Comparator* WhileOps$UnorderedWhileSpliterator$OfLong::getComparator() {
	 return this->$WhileOps$UnorderedWhileSpliterator::getComparator();
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::forEachRemaining($Consumer* action) {
	this->$WhileOps$UnorderedWhileSpliterator::forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::hasCharacteristics(int32_t characteristics) {
	 return this->$WhileOps$UnorderedWhileSpliterator::hasCharacteristics(characteristics);
}

int32_t WhileOps$UnorderedWhileSpliterator$OfLong::hashCode() {
	 return this->$WhileOps$UnorderedWhileSpliterator::hashCode();
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::equals(Object$* obj) {
	 return this->$WhileOps$UnorderedWhileSpliterator::equals(obj);
}

$Object* WhileOps$UnorderedWhileSpliterator$OfLong::clone() {
	 return this->$WhileOps$UnorderedWhileSpliterator::clone();
}

$String* WhileOps$UnorderedWhileSpliterator$OfLong::toString() {
	 return this->$WhileOps$UnorderedWhileSpliterator::toString();
}

void WhileOps$UnorderedWhileSpliterator$OfLong::finalize() {
	this->$WhileOps$UnorderedWhileSpliterator::finalize();
}

void WhileOps$UnorderedWhileSpliterator$OfLong::forEachRemaining($LongConsumer* action) {
	$as($Spliterator$OfLong, this)->$Spliterator$OfLong::forEachRemaining(action);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::forEachRemaining(Object$* action) {
	$as($Spliterator$OfLong, this)->$Spliterator$OfLong::forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::tryAdvance(Object$* action) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::tryAdvance(action);
}

WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::MemberClass0$() {
	$patchMemberClass(WhileOps$UnorderedWhileSpliterator$OfLong, $Spliterator$OfLong, memberClass0$);
}

$Spliterator$OfLong* WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfLong, ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->trySplit());
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::tryAdvance($LongConsumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::forEachRemaining($LongConsumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::tryAdvance($Consumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::forEachRemaining(Object$* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->forEachRemaining(action);
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::tryAdvance(Object$* action) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->tryAdvance(action);
}

int64_t WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::estimateSize() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->estimateSize();
}

int64_t WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::getExactSizeIfKnown() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->getExactSizeIfKnown();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::characteristics() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->characteristics();
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::getComparator() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->getComparator();
}

int32_t WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::hashCode() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->hashCode();
}

bool WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::equals(Object$* obj) {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->equals(obj);
}

$Object* WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::clone() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->clone();
}

$String* WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::toString() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->toString();
}

void WhileOps$UnorderedWhileSpliterator$OfLong::MemberClass0$::finalize() {
	return ((WhileOps$UnorderedWhileSpliterator$OfLong*)(void*)((int8_t*)(void*)this - $offsetof(WhileOps$UnorderedWhileSpliterator$OfLong, memberClass0$)))->finalize();
}

void WhileOps$UnorderedWhileSpliterator$OfLong::init$($Spliterator$OfLong* s, bool noSplitting, $LongPredicate* p) {
	$WhileOps$UnorderedWhileSpliterator::init$(static_cast<$Spliterator*>(s), noSplitting);
	$set(this, p, p);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::init$($Spliterator$OfLong* s, WhileOps$UnorderedWhileSpliterator$OfLong* parent) {
	$WhileOps$UnorderedWhileSpliterator::init$(static_cast<$Spliterator*>(s), static_cast<$WhileOps$UnorderedWhileSpliterator*>(parent));
	$set(this, p, $nc(parent)->p);
}

void WhileOps$UnorderedWhileSpliterator$OfLong::accept(int64_t t) {
	this->count = (int32_t)((this->count + 1) & (uint32_t)$WhileOps$UnorderedWhileSpliterator::CANCEL_CHECK_COUNT);
	this->t = t;
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfLong::trySplit() {
	return $cast($Spliterator$OfLong, $WhileOps$UnorderedWhileSpliterator::trySplit());
}

WhileOps$UnorderedWhileSpliterator$OfLong::WhileOps$UnorderedWhileSpliterator$OfLong() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfLong::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfLong, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfLong_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfLong);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfLong::class$ = nullptr;

		} // stream
	} // util
} // java