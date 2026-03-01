#include <java/util/stream/StreamSpliterators$LongWrappingSpliterator.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/function/BooleanSupplier.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/AbstractSpinedBuffer.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink$OfLong.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SpinedBuffer$OfLong.h>
#include <java/util/stream/StreamSpliterators$AbstractWrappingSpliterator.h>
#include <java/util/stream/StreamSpliterators.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Comparator = ::java::util::Comparator;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSpinedBuffer = ::java::util::stream::AbstractSpinedBuffer;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $Sink$OfLong = ::java::util::stream::Sink$OfLong;
using $SpinedBuffer$OfLong = ::java::util::stream::SpinedBuffer$OfLong;
using $StreamSpliterators$AbstractWrappingSpliterator = ::java::util::stream::StreamSpliterators$AbstractWrappingSpliterator;

namespace java {
	namespace util {
		namespace stream {

class StreamSpliterators$LongWrappingSpliterator$$Lambda$accept : public $Sink$OfLong {
	$class(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept, $NO_CLASS_INIT, $Sink$OfLong)
public:
	void init$($SpinedBuffer$OfLong* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t i) override {
		$nc(inst$)->accept(i);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$LongWrappingSpliterator$$Lambda$accept>());
	}
	$SpinedBuffer$OfLong* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept, inst$)},
	{}
};
$MethodInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/SpinedBuffer$OfLong;)V", nullptr, $PUBLIC, $method(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept, init$, void, $SpinedBuffer$OfLong*)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept, accept, void, int64_t)},
	{}
};
$ClassInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$LongWrappingSpliterator$$Lambda$accept",
	"java.lang.Object",
	"java.util.stream.Sink$OfLong",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::class$ = nullptr;

class StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1 : public $BooleanSupplier {
	$class(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, $NO_CLASS_INIT, $BooleanSupplier)
public:
	void init$(StreamSpliterators$LongWrappingSpliterator* inst) {
		$set(this, inst$, inst);
	}
	virtual bool getAsBoolean() override {
		 return $nc(inst$)->lambda$initPartialTraversalState$0();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1>());
	}
	StreamSpliterators$LongWrappingSpliterator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, inst$)},
	{}
};
$MethodInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/StreamSpliterators$LongWrappingSpliterator;)V", nullptr, $PUBLIC, $method(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, init$, void, StreamSpliterators$LongWrappingSpliterator*)},
	{"getAsBoolean", "()Z", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, getAsBoolean, bool)},
	{}
};
$ClassInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1",
	"java.lang.Object",
	"java.util.function.BooleanSupplier",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::class$ = nullptr;

class StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2 : public $Sink$OfLong {
	$class(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2, $NO_CLASS_INIT, $Sink$OfLong)
public:
	void init$($LongConsumer* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t value) override {
		$nc(inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2>());
	}
	$LongConsumer* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2, inst$)},
	{}
};
$MethodInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $method(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2, init$, void, $LongConsumer*)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2, accept, void, int64_t)},
	{}
};
$ClassInfo StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2",
	"java.lang.Object",
	"java.util.stream.Sink$OfLong",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::class$ = nullptr;

$MethodInfo _StreamSpliterators$LongWrappingSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC | $FINAL},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*forEachRemaining", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*getComparator", "()Ljava/util/Comparator;", nullptr, $PUBLIC},
	{"*getExactSizeIfKnown", "()J", nullptr, $PUBLIC | $FINAL},
	{"*hasCharacteristics", "(I)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/stream/PipelineHelper;Ljava/util/function/Supplier;Z)V", "(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/function/Supplier<Ljava/util/Spliterator<TP_IN;>;>;Z)V", 0, $method(StreamSpliterators$LongWrappingSpliterator, init$, void, $PipelineHelper*, $Supplier*, bool)},
	{"<init>", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Z)V", "(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;Z)V", 0, $method(StreamSpliterators$LongWrappingSpliterator, init$, void, $PipelineHelper*, $Spliterator*, bool)},
	{"forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $method(StreamSpliterators$LongWrappingSpliterator, forEachRemaining, void, $LongConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$LongWrappingSpliterator, forEachRemaining, void, Object$*)},
	{"initPartialTraversalState", "()V", nullptr, 0, $virtualMethod(StreamSpliterators$LongWrappingSpliterator, initPartialTraversalState, void)},
	{"lambda$initPartialTraversalState$0", "()Z", nullptr, $PRIVATE | $SYNTHETIC, $method(StreamSpliterators$LongWrappingSpliterator, lambda$initPartialTraversalState$0, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC, $method(StreamSpliterators$LongWrappingSpliterator, tryAdvance, bool, $LongConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$LongWrappingSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$LongWrappingSpliterator, trySplit, $Spliterator*)},
	{"wrap", "(Ljava/util/Spliterator;)Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator;", "(Ljava/util/Spliterator<TP_IN;>;)Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator<TP_IN;Ljava/lang/Long;*>;", 0, $virtualMethod(StreamSpliterators$LongWrappingSpliterator, wrap, $StreamSpliterators$AbstractWrappingSpliterator*, $Spliterator*)},
	{}
};

$InnerClassInfo _StreamSpliterators$LongWrappingSpliterator_InnerClassesInfo_[] = {
	{"java.util.stream.StreamSpliterators$LongWrappingSpliterator", "java.util.stream.StreamSpliterators", "LongWrappingSpliterator", $STATIC | $FINAL},
	{"java.util.stream.StreamSpliterators$AbstractWrappingSpliterator", "java.util.stream.StreamSpliterators", "AbstractWrappingSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$OfLong", "java.util.stream.SpinedBuffer", "OfLong", $STATIC},
	{}
};

$ClassInfo _StreamSpliterators$LongWrappingSpliterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.StreamSpliterators$LongWrappingSpliterator",
	"java.util.stream.StreamSpliterators$AbstractWrappingSpliterator",
	"java.util.Spliterator$OfLong",
	nullptr,
	_StreamSpliterators$LongWrappingSpliterator_MethodInfo_,
	"<P_IN:Ljava/lang/Object;>Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator<TP_IN;Ljava/lang/Long;Ljava/util/stream/SpinedBuffer$OfLong;>;Ljava/util/Spliterator$OfLong;",
	nullptr,
	_StreamSpliterators$LongWrappingSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.StreamSpliterators"
};

$Object* allocate$StreamSpliterators$LongWrappingSpliterator($Class* clazz) {
	return $of($alloc(StreamSpliterators$LongWrappingSpliterator));
}

int64_t StreamSpliterators$LongWrappingSpliterator::estimateSize() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::estimateSize();
}

int64_t StreamSpliterators$LongWrappingSpliterator::getExactSizeIfKnown() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::getExactSizeIfKnown();
}

int32_t StreamSpliterators$LongWrappingSpliterator::characteristics() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::characteristics();
}

$Comparator* StreamSpliterators$LongWrappingSpliterator::getComparator() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::getComparator();
}

$String* StreamSpliterators$LongWrappingSpliterator::toString() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::toString();
}

bool StreamSpliterators$LongWrappingSpliterator::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfLong, this)->$Spliterator$OfLong::tryAdvance(action);
}

void StreamSpliterators$LongWrappingSpliterator::forEachRemaining($Consumer* action) {
	this->$StreamSpliterators$AbstractWrappingSpliterator::forEachRemaining(action);
}

bool StreamSpliterators$LongWrappingSpliterator::hasCharacteristics(int32_t characteristics) {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::hasCharacteristics(characteristics);
}

int32_t StreamSpliterators$LongWrappingSpliterator::hashCode() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::hashCode();
}

bool StreamSpliterators$LongWrappingSpliterator::equals(Object$* obj) {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::equals(obj);
}

$Object* StreamSpliterators$LongWrappingSpliterator::clone() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::clone();
}

void StreamSpliterators$LongWrappingSpliterator::finalize() {
	this->$StreamSpliterators$AbstractWrappingSpliterator::finalize();
}

StreamSpliterators$LongWrappingSpliterator::MemberClass0$::MemberClass0$() {
	$patchMemberClass(StreamSpliterators$LongWrappingSpliterator, $Spliterator$OfLong, memberClass0$);
}

$Spliterator$OfLong* StreamSpliterators$LongWrappingSpliterator::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfLong, ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->trySplit());
}

bool StreamSpliterators$LongWrappingSpliterator::MemberClass0$::tryAdvance($LongConsumer* action) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$LongWrappingSpliterator::MemberClass0$::forEachRemaining($LongConsumer* action) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$LongWrappingSpliterator::MemberClass0$::tryAdvance($Consumer* action) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$LongWrappingSpliterator::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

void StreamSpliterators$LongWrappingSpliterator::MemberClass0$::forEachRemaining(Object$* action) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$LongWrappingSpliterator::MemberClass0$::tryAdvance(Object$* action) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

int64_t StreamSpliterators$LongWrappingSpliterator::MemberClass0$::estimateSize() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->estimateSize();
}

int64_t StreamSpliterators$LongWrappingSpliterator::MemberClass0$::getExactSizeIfKnown() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->getExactSizeIfKnown();
}

int32_t StreamSpliterators$LongWrappingSpliterator::MemberClass0$::characteristics() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->characteristics();
}

bool StreamSpliterators$LongWrappingSpliterator::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* StreamSpliterators$LongWrappingSpliterator::MemberClass0$::getComparator() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->getComparator();
}

int32_t StreamSpliterators$LongWrappingSpliterator::MemberClass0$::hashCode() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->hashCode();
}

bool StreamSpliterators$LongWrappingSpliterator::MemberClass0$::equals(Object$* obj) {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->equals(obj);
}

$Object* StreamSpliterators$LongWrappingSpliterator::MemberClass0$::clone() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->clone();
}

$String* StreamSpliterators$LongWrappingSpliterator::MemberClass0$::toString() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->toString();
}

void StreamSpliterators$LongWrappingSpliterator::MemberClass0$::finalize() {
	return ((StreamSpliterators$LongWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$LongWrappingSpliterator, memberClass0$)))->finalize();
}

void StreamSpliterators$LongWrappingSpliterator::init$($PipelineHelper* ph, $Supplier* supplier, bool parallel) {
	$StreamSpliterators$AbstractWrappingSpliterator::init$(ph, supplier, parallel);
}

void StreamSpliterators$LongWrappingSpliterator::init$($PipelineHelper* ph, $Spliterator* spliterator, bool parallel) {
	$StreamSpliterators$AbstractWrappingSpliterator::init$(ph, spliterator, parallel);
}

$StreamSpliterators$AbstractWrappingSpliterator* StreamSpliterators$LongWrappingSpliterator::wrap($Spliterator* s) {
	return $new(StreamSpliterators$LongWrappingSpliterator, this->ph, s, this->isParallel);
}

void StreamSpliterators$LongWrappingSpliterator::initPartialTraversalState() {
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfLong, b, $new($SpinedBuffer$OfLong));
	$set(this, buffer, b);
	$set(this, bufferSink, $nc(this->ph)->wrapSink(static_cast<$Sink$OfLong*>($$new(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept, static_cast<$SpinedBuffer$OfLong*>(b)))));
	$set(this, pusher, static_cast<$BooleanSupplier*>($new(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, this)));
}

$Spliterator* StreamSpliterators$LongWrappingSpliterator::trySplit() {
	return $cast($Spliterator$OfLong, $StreamSpliterators$AbstractWrappingSpliterator::trySplit());
}

bool StreamSpliterators$LongWrappingSpliterator::tryAdvance($LongConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	bool hasNext = doAdvance();
	if (hasNext) {
		consumer->accept($nc(($cast($SpinedBuffer$OfLong, this->buffer)))->get(this->nextToConsume));
	}
	return hasNext;
}

void StreamSpliterators$LongWrappingSpliterator::forEachRemaining($LongConsumer* consumer) {
	if (this->buffer == nullptr && !this->finished) {
		$Objects::requireNonNull(consumer);
		init();
		$nc(this->ph)->wrapAndCopyInto(static_cast<$Sink$OfLong*>($$new(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2, static_cast<$LongConsumer*>(consumer))), this->spliterator);
		this->finished = true;
	} else {
		do {
		} while (tryAdvance(consumer));
	}
}

void StreamSpliterators$LongWrappingSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($LongConsumer, consumer));
}

bool StreamSpliterators$LongWrappingSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($LongConsumer, consumer));
}

bool StreamSpliterators$LongWrappingSpliterator::lambda$initPartialTraversalState$0() {
	return $nc(this->spliterator)->tryAdvance(this->bufferSink);
}

StreamSpliterators$LongWrappingSpliterator::StreamSpliterators$LongWrappingSpliterator() {
}

$Class* StreamSpliterators$LongWrappingSpliterator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::classInfo$.name)) {
			return StreamSpliterators$LongWrappingSpliterator$$Lambda$accept::load$(name, initialize);
		}
		if (name->equals(StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::classInfo$.name)) {
			return StreamSpliterators$LongWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::load$(name, initialize);
		}
		if (name->equals(StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::classInfo$.name)) {
			return StreamSpliterators$LongWrappingSpliterator$$Lambda$accept$2::load$(name, initialize);
		}
	}
	$loadClass(StreamSpliterators$LongWrappingSpliterator, name, initialize, &_StreamSpliterators$LongWrappingSpliterator_ClassInfo_, allocate$StreamSpliterators$LongWrappingSpliterator);
	return class$;
}

$Class* StreamSpliterators$LongWrappingSpliterator::class$ = nullptr;

		} // stream
	} // util
} // java