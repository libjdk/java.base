#include <java/util/stream/Streams$DoubleStreamBuilderImpl.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/SpinedBuffer$OfDouble.h>
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
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $SpinedBuffer$OfDouble = ::java::util::stream::SpinedBuffer$OfDouble;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams$AbstractStreamBuilderImpl = ::java::util::stream::Streams$AbstractStreamBuilderImpl;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _Streams$DoubleStreamBuilderImpl_FieldInfo_[] = {
	{"first", "D", nullptr, 0, $field(Streams$DoubleStreamBuilderImpl, first)},
	{"buffer", "Ljava/util/stream/SpinedBuffer$OfDouble;", nullptr, 0, $field(Streams$DoubleStreamBuilderImpl, buffer)},
	{}
};

$MethodInfo _Streams$DoubleStreamBuilderImpl_MethodInfo_[] = {
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
	{"<init>", "()V", nullptr, 0, $method(Streams$DoubleStreamBuilderImpl, init$, void)},
	{"<init>", "(D)V", nullptr, 0, $method(Streams$DoubleStreamBuilderImpl, init$, void, double)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(Streams$DoubleStreamBuilderImpl, accept, void, double)},
	{"build", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC, $virtualMethod(Streams$DoubleStreamBuilderImpl, build, $DoubleStream*)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $method(Streams$DoubleStreamBuilderImpl, forEachRemaining, void, $DoubleConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Streams$DoubleStreamBuilderImpl, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC, $method(Streams$DoubleStreamBuilderImpl, tryAdvance, bool, $DoubleConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(Streams$DoubleStreamBuilderImpl, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Streams$DoubleStreamBuilderImpl, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _Streams$DoubleStreamBuilderImpl_InnerClassesInfo_[] = {
	{"java.util.stream.Streams$DoubleStreamBuilderImpl", "java.util.stream.Streams", "DoubleStreamBuilderImpl", $STATIC | $FINAL},
	{"java.util.stream.Streams$AbstractStreamBuilderImpl", "java.util.stream.Streams", "AbstractStreamBuilderImpl", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.DoubleStream$Builder", "java.util.stream.DoubleStream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Streams$DoubleStreamBuilderImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.Streams$DoubleStreamBuilderImpl",
	"java.util.stream.Streams$AbstractStreamBuilderImpl",
	"java.util.stream.DoubleStream$Builder,java.util.Spliterator$OfDouble",
	_Streams$DoubleStreamBuilderImpl_FieldInfo_,
	_Streams$DoubleStreamBuilderImpl_MethodInfo_,
	"Ljava/util/stream/Streams$AbstractStreamBuilderImpl<Ljava/lang/Double;Ljava/util/Spliterator$OfDouble;>;Ljava/util/stream/DoubleStream$Builder;Ljava/util/Spliterator$OfDouble;",
	nullptr,
	_Streams$DoubleStreamBuilderImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.Streams"
};

$Object* allocate$Streams$DoubleStreamBuilderImpl($Class* clazz) {
	return $of($alloc(Streams$DoubleStreamBuilderImpl));
}

int64_t Streams$DoubleStreamBuilderImpl::estimateSize() {
	 return this->$Streams$AbstractStreamBuilderImpl::estimateSize();
}

int32_t Streams$DoubleStreamBuilderImpl::characteristics() {
	 return this->$Streams$AbstractStreamBuilderImpl::characteristics();
}

bool Streams$DoubleStreamBuilderImpl::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::tryAdvance(action);
}

void Streams$DoubleStreamBuilderImpl::forEachRemaining($Consumer* action) {
	this->$Streams$AbstractStreamBuilderImpl::forEachRemaining(action);
}

int64_t Streams$DoubleStreamBuilderImpl::getExactSizeIfKnown() {
	 return this->$Streams$AbstractStreamBuilderImpl::getExactSizeIfKnown();
}

bool Streams$DoubleStreamBuilderImpl::hasCharacteristics(int32_t characteristics) {
	 return this->$Streams$AbstractStreamBuilderImpl::hasCharacteristics(characteristics);
}

$Comparator* Streams$DoubleStreamBuilderImpl::getComparator() {
	 return this->$Streams$AbstractStreamBuilderImpl::getComparator();
}

int32_t Streams$DoubleStreamBuilderImpl::hashCode() {
	 return this->$Streams$AbstractStreamBuilderImpl::hashCode();
}

bool Streams$DoubleStreamBuilderImpl::equals(Object$* obj) {
	 return this->$Streams$AbstractStreamBuilderImpl::equals(obj);
}

$Object* Streams$DoubleStreamBuilderImpl::clone() {
	 return this->$Streams$AbstractStreamBuilderImpl::clone();
}

$String* Streams$DoubleStreamBuilderImpl::toString() {
	 return this->$Streams$AbstractStreamBuilderImpl::toString();
}

void Streams$DoubleStreamBuilderImpl::finalize() {
	this->$Streams$AbstractStreamBuilderImpl::finalize();
}

Streams$DoubleStreamBuilderImpl::MemberClass0$::MemberClass0$() {
	$patchMemberClass(Streams$DoubleStreamBuilderImpl, $Spliterator$OfDouble, memberClass0$);
}

$Spliterator$OfDouble* Streams$DoubleStreamBuilderImpl::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfDouble, ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->trySplit());
}

bool Streams$DoubleStreamBuilderImpl::MemberClass0$::tryAdvance($DoubleConsumer* action) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

void Streams$DoubleStreamBuilderImpl::MemberClass0$::forEachRemaining($DoubleConsumer* action) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

bool Streams$DoubleStreamBuilderImpl::MemberClass0$::tryAdvance($Consumer* action) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

void Streams$DoubleStreamBuilderImpl::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

void Streams$DoubleStreamBuilderImpl::MemberClass0$::forEachRemaining(Object$* action) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->forEachRemaining(action);
}

bool Streams$DoubleStreamBuilderImpl::MemberClass0$::tryAdvance(Object$* action) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->tryAdvance(action);
}

int64_t Streams$DoubleStreamBuilderImpl::MemberClass0$::estimateSize() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->estimateSize();
}

int64_t Streams$DoubleStreamBuilderImpl::MemberClass0$::getExactSizeIfKnown() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->getExactSizeIfKnown();
}

int32_t Streams$DoubleStreamBuilderImpl::MemberClass0$::characteristics() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->characteristics();
}

bool Streams$DoubleStreamBuilderImpl::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* Streams$DoubleStreamBuilderImpl::MemberClass0$::getComparator() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->getComparator();
}

int32_t Streams$DoubleStreamBuilderImpl::MemberClass0$::hashCode() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->hashCode();
}

bool Streams$DoubleStreamBuilderImpl::MemberClass0$::equals(Object$* obj) {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->equals(obj);
}

$Object* Streams$DoubleStreamBuilderImpl::MemberClass0$::clone() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->clone();
}

$String* Streams$DoubleStreamBuilderImpl::MemberClass0$::toString() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->toString();
}

void Streams$DoubleStreamBuilderImpl::MemberClass0$::finalize() {
	return ((Streams$DoubleStreamBuilderImpl*)(void*)((int8_t*)(void*)this - $offsetof(Streams$DoubleStreamBuilderImpl, memberClass0$)))->finalize();
}

void Streams$DoubleStreamBuilderImpl::init$() {
	$Streams$AbstractStreamBuilderImpl::init$();
}

void Streams$DoubleStreamBuilderImpl::init$(double t) {
	$Streams$AbstractStreamBuilderImpl::init$();
	this->first = t;
	this->count = -2;
}

void Streams$DoubleStreamBuilderImpl::accept(double t) {
	if (this->count == 0) {
		this->first = t;
		++this->count;
	} else if (this->count > 0) {
		if (this->buffer == nullptr) {
			$set(this, buffer, $new($SpinedBuffer$OfDouble));
			$nc(this->buffer)->accept(this->first);
			++this->count;
		}
		$nc(this->buffer)->accept(t);
	} else {
		$throwNew($IllegalStateException);
	}
}

$DoubleStream* Streams$DoubleStreamBuilderImpl::build() {
	int32_t c = this->count;
	if (c >= 0) {
		this->count = -this->count - 1;
		return (c < 2) ? $StreamSupport::doubleStream($as($Spliterator$OfDouble, this), false) : $StreamSupport::doubleStream($($cast($Spliterator$OfDouble, $nc(this->buffer)->spliterator())), false);
	}
	$throwNew($IllegalStateException);
}

bool Streams$DoubleStreamBuilderImpl::tryAdvance($DoubleConsumer* action) {
	$Objects::requireNonNull(action);
	if (this->count == -2) {
		action->accept(this->first);
		this->count = -1;
		return true;
	} else {
		return false;
	}
}

void Streams$DoubleStreamBuilderImpl::forEachRemaining($DoubleConsumer* action) {
	$Objects::requireNonNull(action);
	if (this->count == -2) {
		action->accept(this->first);
		this->count = -1;
	}
}

$Spliterator* Streams$DoubleStreamBuilderImpl::trySplit() {
	return $cast($Spliterator$OfDouble, $Streams$AbstractStreamBuilderImpl::trySplit());
}

void Streams$DoubleStreamBuilderImpl::forEachRemaining(Object$* action) {
	this->forEachRemaining($cast($DoubleConsumer, action));
}

bool Streams$DoubleStreamBuilderImpl::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($DoubleConsumer, action));
}

Streams$DoubleStreamBuilderImpl::Streams$DoubleStreamBuilderImpl() {
}

$Class* Streams$DoubleStreamBuilderImpl::load$($String* name, bool initialize) {
	$loadClass(Streams$DoubleStreamBuilderImpl, name, initialize, &_Streams$DoubleStreamBuilderImpl_ClassInfo_, allocate$Streams$DoubleStreamBuilderImpl);
	return class$;
}

$Class* Streams$DoubleStreamBuilderImpl::class$ = nullptr;

		} // stream
	} // util
} // java