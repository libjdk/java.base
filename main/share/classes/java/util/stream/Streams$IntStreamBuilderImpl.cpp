#include <java/util/stream/Streams$IntStreamBuilderImpl.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/SpinedBuffer$OfInt.h>
#include <java/util/stream/StreamSupport.h>
#include <java/util/stream/Streams$AbstractStreamBuilderImpl.h>
#include <java/util/stream/Streams.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Comparator = ::java::util::Comparator;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $IntStream = ::java::util::stream::IntStream;
using $SpinedBuffer$OfInt = ::java::util::stream::SpinedBuffer$OfInt;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams$AbstractStreamBuilderImpl = ::java::util::stream::Streams$AbstractStreamBuilderImpl;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _Streams$IntStreamBuilderImpl_FieldInfo_[] = {
	{"first", "I", nullptr, 0, $field(Streams$IntStreamBuilderImpl, first)},
	{"buffer", "Ljava/util/stream/SpinedBuffer$OfInt;", nullptr, 0, $field(Streams$IntStreamBuilderImpl, buffer)},
	{}
};

$MethodInfo _Streams$IntStreamBuilderImpl_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC | $ABSTRACT},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(Streams$IntStreamBuilderImpl, init$, void)},
	{"<init>", "(I)V", nullptr, 0, $method(Streams$IntStreamBuilderImpl, init$, void, int32_t)},
	{"accept", "(I)V", nullptr, $PUBLIC, $virtualMethod(Streams$IntStreamBuilderImpl, accept, void, int32_t)},
	{"build", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(Streams$IntStreamBuilderImpl, build, $IntStream*)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC, $method(Streams$IntStreamBuilderImpl, forEachRemaining, void, $IntConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Streams$IntStreamBuilderImpl, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC, $method(Streams$IntStreamBuilderImpl, tryAdvance, bool, $IntConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Streams$IntStreamBuilderImpl, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Streams$IntStreamBuilderImpl, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Streams$IntStreamBuilderImpl_InnerClassesInfo_[] = {
	{"java.util.stream.Streams$IntStreamBuilderImpl", "java.util.stream.Streams", "IntStreamBuilderImpl", $STATIC | $FINAL},
	{"java.util.stream.Streams$AbstractStreamBuilderImpl", "java.util.stream.Streams", "AbstractStreamBuilderImpl", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.IntStream$Builder", "java.util.stream.IntStream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Streams$IntStreamBuilderImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Streams$IntStreamBuilderImpl",
	"java.util.stream.Streams$AbstractStreamBuilderImpl",
	"java.util.stream.IntStream$Builder,java.util.Spliterator$OfInt",
	_Streams$IntStreamBuilderImpl_FieldInfo_,
	_Streams$IntStreamBuilderImpl_MethodInfo_,
	"Ljava/util/stream/Streams$AbstractStreamBuilderImpl<Ljava/lang/Integer;Ljava/util/Spliterator$OfInt;>;Ljava/util/stream/IntStream$Builder;Ljava/util/Spliterator$OfInt;",
	nullptr,
	_Streams$IntStreamBuilderImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Streams"
};

$Object* allocate$Streams$IntStreamBuilderImpl($Class* clazz) {
	return $of($alloc(Streams$IntStreamBuilderImpl));
}

int64_t Streams$IntStreamBuilderImpl::estimateSize() {
	 return this->$Streams$AbstractStreamBuilderImpl::estimateSize();
}

int32_t Streams$IntStreamBuilderImpl::characteristics() {
	 return this->$Streams$AbstractStreamBuilderImpl::characteristics();
}

bool Streams$IntStreamBuilderImpl::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::tryAdvance(action);
}

void Streams$IntStreamBuilderImpl::forEachRemaining($Consumer* action) {
	this->$Streams$AbstractStreamBuilderImpl::forEachRemaining(action);
}

int64_t Streams$IntStreamBuilderImpl::getExactSizeIfKnown() {
	 return this->$Streams$AbstractStreamBuilderImpl::getExactSizeIfKnown();
}

bool Streams$IntStreamBuilderImpl::hasCharacteristics(int32_t characteristics) {
	 return this->$Streams$AbstractStreamBuilderImpl::hasCharacteristics(characteristics);
}

$Comparator* Streams$IntStreamBuilderImpl::getComparator() {
	 return this->$Streams$AbstractStreamBuilderImpl::getComparator();
}

int32_t Streams$IntStreamBuilderImpl::hashCode() {
	 return this->$Streams$AbstractStreamBuilderImpl::hashCode();
}

bool Streams$IntStreamBuilderImpl::equals(Object$* obj) {
	 return this->$Streams$AbstractStreamBuilderImpl::equals(obj);
}

$Object* Streams$IntStreamBuilderImpl::clone() {
	 return this->$Streams$AbstractStreamBuilderImpl::clone();
}

$String* Streams$IntStreamBuilderImpl::toString() {
	 return this->$Streams$AbstractStreamBuilderImpl::toString();
}

void Streams$IntStreamBuilderImpl::finalize() {
	this->$Streams$AbstractStreamBuilderImpl::finalize();
}

Streams$IntStreamBuilderImpl::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Streams$IntStreamBuilderImpl, $Spliterator$OfInt, memberClass0$);
}

$Spliterator$OfInt* Streams$IntStreamBuilderImpl::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfInt, ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->trySplit());
}

bool Streams$IntStreamBuilderImpl::MemberClass0$::tryAdvance($IntConsumer* action) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

void Streams$IntStreamBuilderImpl::MemberClass0$::forEachRemaining($IntConsumer* action) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

bool Streams$IntStreamBuilderImpl::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

void Streams$IntStreamBuilderImpl::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

void Streams$IntStreamBuilderImpl::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

bool Streams$IntStreamBuilderImpl::MemberClass0$::tryAdvance(Object$* action) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

int64_t Streams$IntStreamBuilderImpl::MemberClass0$::estimateSize() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->estimateSize();
}

int64_t Streams$IntStreamBuilderImpl::MemberClass0$::getExactSizeIfKnown() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Streams$IntStreamBuilderImpl::MemberClass0$::characteristics() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->characteristics();
}

bool Streams$IntStreamBuilderImpl::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Streams$IntStreamBuilderImpl::MemberClass0$::getComparator() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->getComparator();
}

int32_t Streams$IntStreamBuilderImpl::MemberClass0$::hashCode() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->hashCode();
}

bool Streams$IntStreamBuilderImpl::MemberClass0$::equals(Object$* obj) {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->equals(obj);
}

$Object* Streams$IntStreamBuilderImpl::MemberClass0$::clone() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->clone();
}

$String* Streams$IntStreamBuilderImpl::MemberClass0$::toString() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->toString();
}

void Streams$IntStreamBuilderImpl::MemberClass0$::finalize() {
	return ((Streams$IntStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$IntStreamBuilderImpl, memberClass0$)))->finalize();
}

void Streams$IntStreamBuilderImpl::init$() {
	$Streams$AbstractStreamBuilderImpl::init$();
}

void Streams$IntStreamBuilderImpl::init$(int32_t t) {
	$Streams$AbstractStreamBuilderImpl::init$();
	this->first = t;
	this->count = -2;
}

void Streams$IntStreamBuilderImpl::accept(int32_t t) {
	if (this->count == 0) {
		this->first = t;
		++this->count;
	} else if (this->count > 0) {
		if (this->buffer == nullptr) {
			$set(this, buffer, $new($SpinedBuffer$OfInt));
			$nc(this->buffer)->accept(this->first);
			++this->count;
		}
		$nc(this->buffer)->accept(t);
	} else {
		$throwNew($IllegalStateException);
	}
}

$IntStream* Streams$IntStreamBuilderImpl::build() {
	int32_t c = this->count;
	if (c >= 0) {
		this->count = -this->count - 1;
		return (c < 2) ? $StreamSupport::intStream($as($Spliterator$OfInt, this), false) : $StreamSupport::intStream($($cast($Spliterator$OfInt, $nc(this->buffer)->spliterator())), false);
	}
	$throwNew($IllegalStateException);
}

bool Streams$IntStreamBuilderImpl::tryAdvance($IntConsumer* action) {
	$Objects::requireNonNull(action);
	if (this->count == -2) {
		action->accept(this->first);
		this->count = -1;
		return true;
	} else {
		return false;
	}
}

void Streams$IntStreamBuilderImpl::forEachRemaining($IntConsumer* action) {
	$Objects::requireNonNull(action);
	if (this->count == -2) {
		action->accept(this->first);
		this->count = -1;
	}
}

$Spliterator* Streams$IntStreamBuilderImpl::trySplit() {
	return $cast($Spliterator$OfInt, $Streams$AbstractStreamBuilderImpl::trySplit());
}

void Streams$IntStreamBuilderImpl::forEachRemaining(Object$* action) {
	this->forEachRemaining($cast($IntConsumer, action));
}

bool Streams$IntStreamBuilderImpl::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($IntConsumer, action));
}

Streams$IntStreamBuilderImpl::Streams$IntStreamBuilderImpl() {
}

$Class* Streams$IntStreamBuilderImpl::load$($String* name, bool initialize) {
	$loadClass(Streams$IntStreamBuilderImpl, name, initialize, &_Streams$IntStreamBuilderImpl_ClassInfo_, allocate$Streams$IntStreamBuilderImpl);
	return class$;
}

$Class* Streams$IntStreamBuilderImpl::class$ = nullptr;

		} // stream
	} // util
} // java