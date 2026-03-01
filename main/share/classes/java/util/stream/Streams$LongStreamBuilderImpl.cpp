#include <java/util/stream/Streams$LongStreamBuilderImpl.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/SpinedBuffer$OfLong.h>
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
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $LongStream = ::java::util::stream::LongStream;
using $SpinedBuffer$OfLong = ::java::util::stream::SpinedBuffer$OfLong;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams$AbstractStreamBuilderImpl = ::java::util::stream::Streams$AbstractStreamBuilderImpl;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _Streams$LongStreamBuilderImpl_FieldInfo_[] = {
	{"first", "J", nullptr, 0, $field(Streams$LongStreamBuilderImpl, first)},
	{"buffer", "Ljava/util/stream/SpinedBuffer$OfLong;", nullptr, 0, $field(Streams$LongStreamBuilderImpl, buffer)},
	{}
};

$MethodInfo _Streams$LongStreamBuilderImpl_MethodInfo_[] = {
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
	{"<init>", "()V", nullptr, 0, $method(Streams$LongStreamBuilderImpl, init$, void)},
	{"<init>", "(J)V", nullptr, 0, $method(Streams$LongStreamBuilderImpl, init$, void, int64_t)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(Streams$LongStreamBuilderImpl, accept, void, int64_t)},
	{"build", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC, $virtualMethod(Streams$LongStreamBuilderImpl, build, $LongStream*)},
	{"forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $method(Streams$LongStreamBuilderImpl, forEachRemaining, void, $LongConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Streams$LongStreamBuilderImpl, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC, $method(Streams$LongStreamBuilderImpl, tryAdvance, bool, $LongConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Streams$LongStreamBuilderImpl, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Streams$LongStreamBuilderImpl, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Streams$LongStreamBuilderImpl_InnerClassesInfo_[] = {
	{"java.util.stream.Streams$LongStreamBuilderImpl", "java.util.stream.Streams", "LongStreamBuilderImpl", $STATIC | $FINAL},
	{"java.util.stream.Streams$AbstractStreamBuilderImpl", "java.util.stream.Streams", "AbstractStreamBuilderImpl", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.LongStream$Builder", "java.util.stream.LongStream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Streams$LongStreamBuilderImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Streams$LongStreamBuilderImpl",
	"java.util.stream.Streams$AbstractStreamBuilderImpl",
	"java.util.stream.LongStream$Builder,java.util.Spliterator$OfLong",
	_Streams$LongStreamBuilderImpl_FieldInfo_,
	_Streams$LongStreamBuilderImpl_MethodInfo_,
	"Ljava/util/stream/Streams$AbstractStreamBuilderImpl<Ljava/lang/Long;Ljava/util/Spliterator$OfLong;>;Ljava/util/stream/LongStream$Builder;Ljava/util/Spliterator$OfLong;",
	nullptr,
	_Streams$LongStreamBuilderImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Streams"
};

$Object* allocate$Streams$LongStreamBuilderImpl($Class* clazz) {
	return $of($alloc(Streams$LongStreamBuilderImpl));
}

int64_t Streams$LongStreamBuilderImpl::estimateSize() {
	 return this->$Streams$AbstractStreamBuilderImpl::estimateSize();
}

int32_t Streams$LongStreamBuilderImpl::characteristics() {
	 return this->$Streams$AbstractStreamBuilderImpl::characteristics();
}

bool Streams$LongStreamBuilderImpl::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::tryAdvance(action);
}

void Streams$LongStreamBuilderImpl::forEachRemaining($Consumer* action) {
	this->$Streams$AbstractStreamBuilderImpl::forEachRemaining(action);
}

int64_t Streams$LongStreamBuilderImpl::getExactSizeIfKnown() {
	 return this->$Streams$AbstractStreamBuilderImpl::getExactSizeIfKnown();
}

bool Streams$LongStreamBuilderImpl::hasCharacteristics(int32_t characteristics) {
	 return this->$Streams$AbstractStreamBuilderImpl::hasCharacteristics(characteristics);
}

$Comparator* Streams$LongStreamBuilderImpl::getComparator() {
	 return this->$Streams$AbstractStreamBuilderImpl::getComparator();
}

int32_t Streams$LongStreamBuilderImpl::hashCode() {
	 return this->$Streams$AbstractStreamBuilderImpl::hashCode();
}

bool Streams$LongStreamBuilderImpl::equals(Object$* obj) {
	 return this->$Streams$AbstractStreamBuilderImpl::equals(obj);
}

$Object* Streams$LongStreamBuilderImpl::clone() {
	 return this->$Streams$AbstractStreamBuilderImpl::clone();
}

$String* Streams$LongStreamBuilderImpl::toString() {
	 return this->$Streams$AbstractStreamBuilderImpl::toString();
}

void Streams$LongStreamBuilderImpl::finalize() {
	this->$Streams$AbstractStreamBuilderImpl::finalize();
}

Streams$LongStreamBuilderImpl::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Streams$LongStreamBuilderImpl, $Spliterator$OfLong, memberClass0$);
}

$Spliterator$OfLong* Streams$LongStreamBuilderImpl::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfLong, ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->trySplit());
}

bool Streams$LongStreamBuilderImpl::MemberClass0$::tryAdvance($LongConsumer* action) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

void Streams$LongStreamBuilderImpl::MemberClass0$::forEachRemaining($LongConsumer* action) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

bool Streams$LongStreamBuilderImpl::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

void Streams$LongStreamBuilderImpl::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

void Streams$LongStreamBuilderImpl::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

bool Streams$LongStreamBuilderImpl::MemberClass0$::tryAdvance(Object$* action) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

int64_t Streams$LongStreamBuilderImpl::MemberClass0$::estimateSize() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->estimateSize();
}

int64_t Streams$LongStreamBuilderImpl::MemberClass0$::getExactSizeIfKnown() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Streams$LongStreamBuilderImpl::MemberClass0$::characteristics() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->characteristics();
}

bool Streams$LongStreamBuilderImpl::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Streams$LongStreamBuilderImpl::MemberClass0$::getComparator() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->getComparator();
}

int32_t Streams$LongStreamBuilderImpl::MemberClass0$::hashCode() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->hashCode();
}

bool Streams$LongStreamBuilderImpl::MemberClass0$::equals(Object$* obj) {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->equals(obj);
}

$Object* Streams$LongStreamBuilderImpl::MemberClass0$::clone() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->clone();
}

$String* Streams$LongStreamBuilderImpl::MemberClass0$::toString() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->toString();
}

void Streams$LongStreamBuilderImpl::MemberClass0$::finalize() {
	return ((Streams$LongStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$LongStreamBuilderImpl, memberClass0$)))->finalize();
}

void Streams$LongStreamBuilderImpl::init$() {
	$Streams$AbstractStreamBuilderImpl::init$();
}

void Streams$LongStreamBuilderImpl::init$(int64_t t) {
	$Streams$AbstractStreamBuilderImpl::init$();
	this->first = t;
	this->count = -2;
}

void Streams$LongStreamBuilderImpl::accept(int64_t t) {
	if (this->count == 0) {
		this->first = t;
		++this->count;
	} else if (this->count > 0) {
		if (this->buffer == nullptr) {
			$set(this, buffer, $new($SpinedBuffer$OfLong));
			$nc(this->buffer)->accept(this->first);
			++this->count;
		}
		$nc(this->buffer)->accept(t);
	} else {
		$throwNew($IllegalStateException);
	}
}

$LongStream* Streams$LongStreamBuilderImpl::build() {
	int32_t c = this->count;
	if (c >= 0) {
		this->count = -this->count - 1;
		return (c < 2) ? $StreamSupport::longStream($as($Spliterator$OfLong, this), false) : $StreamSupport::longStream($($cast($Spliterator$OfLong, $nc(this->buffer)->spliterator())), false);
	}
	$throwNew($IllegalStateException);
}

bool Streams$LongStreamBuilderImpl::tryAdvance($LongConsumer* action) {
	$Objects::requireNonNull(action);
	if (this->count == -2) {
		action->accept(this->first);
		this->count = -1;
		return true;
	} else {
		return false;
	}
}

void Streams$LongStreamBuilderImpl::forEachRemaining($LongConsumer* action) {
	$Objects::requireNonNull(action);
	if (this->count == -2) {
		action->accept(this->first);
		this->count = -1;
	}
}

$Spliterator* Streams$LongStreamBuilderImpl::trySplit() {
	return $cast($Spliterator$OfLong, $Streams$AbstractStreamBuilderImpl::trySplit());
}

void Streams$LongStreamBuilderImpl::forEachRemaining(Object$* action) {
	this->forEachRemaining($cast($LongConsumer, action));
}

bool Streams$LongStreamBuilderImpl::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($LongConsumer, action));
}

Streams$LongStreamBuilderImpl::Streams$LongStreamBuilderImpl() {
}

$Class* Streams$LongStreamBuilderImpl::load$($String* name, bool initialize) {
	$loadClass(Streams$LongStreamBuilderImpl, name, initialize, &_Streams$LongStreamBuilderImpl_ClassInfo_, allocate$Streams$LongStreamBuilderImpl);
	return class$;
}

$Class* Streams$LongStreamBuilderImpl::class$ = nullptr;

		} // stream
	} // util
} // java