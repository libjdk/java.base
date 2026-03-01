#include <java/util/stream/StreamSpliterators$DoubleWrappingSpliterator.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/function/BooleanSupplier.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/AbstractSpinedBuffer.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink$OfDouble.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SpinedBuffer$OfDouble.h>
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
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSpinedBuffer = ::java::util::stream::AbstractSpinedBuffer;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $Sink$OfDouble = ::java::util::stream::Sink$OfDouble;
using $SpinedBuffer$OfDouble = ::java::util::stream::SpinedBuffer$OfDouble;
using $StreamSpliterators$AbstractWrappingSpliterator = ::java::util::stream::StreamSpliterators$AbstractWrappingSpliterator;

namespace java {
	namespace util {
		namespace stream {

class StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept : public $Sink$OfDouble {
	$class(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept, $NO_CLASS_INIT, $Sink$OfDouble)
public:
	void init$($SpinedBuffer$OfDouble* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(double i) override {
		$nc(inst$)->accept(i);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept>());
	}
	$SpinedBuffer$OfDouble* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept, inst$)},
	{}
};
$MethodInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/SpinedBuffer$OfDouble;)V", nullptr, $PUBLIC, $method(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept, init$, void, $SpinedBuffer$OfDouble*)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept, accept, void, double)},
	{}
};
$ClassInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept",
	"java.lang.Object",
	"java.util.stream.Sink$OfDouble",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::class$ = nullptr;

class StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1 : public $BooleanSupplier {
	$class(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, $NO_CLASS_INIT, $BooleanSupplier)
public:
	void init$(StreamSpliterators$DoubleWrappingSpliterator* inst) {
		$set(this, inst$, inst);
	}
	virtual bool getAsBoolean() override {
		 return $nc(inst$)->lambda$initPartialTraversalState$0();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1>());
	}
	StreamSpliterators$DoubleWrappingSpliterator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, inst$)},
	{}
};
$MethodInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/StreamSpliterators$DoubleWrappingSpliterator;)V", nullptr, $PUBLIC, $method(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, init$, void, StreamSpliterators$DoubleWrappingSpliterator*)},
	{"getAsBoolean", "()Z", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, getAsBoolean, bool)},
	{}
};
$ClassInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1",
	"java.lang.Object",
	"java.util.function.BooleanSupplier",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::class$ = nullptr;

class StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2 : public $Sink$OfDouble {
	$class(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2, $NO_CLASS_INIT, $Sink$OfDouble)
public:
	void init$($DoubleConsumer* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(double value) override {
		$nc(inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2>());
	}
	$DoubleConsumer* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2, inst$)},
	{}
};
$MethodInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $method(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2, init$, void, $DoubleConsumer*)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2, accept, void, double)},
	{}
};
$ClassInfo StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2",
	"java.lang.Object",
	"java.util.stream.Sink$OfDouble",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::class$ = nullptr;

$MethodInfo _StreamSpliterators$DoubleWrappingSpliterator_MethodInfo_[] = {
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
	{"<init>", "(Ljava/util/stream/PipelineHelper;Ljava/util/function/Supplier;Z)V", "(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/function/Supplier<Ljava/util/Spliterator<TP_IN;>;>;Z)V", 0, $method(StreamSpliterators$DoubleWrappingSpliterator, init$, void, $PipelineHelper*, $Supplier*, bool)},
	{"<init>", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Z)V", "(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;Z)V", 0, $method(StreamSpliterators$DoubleWrappingSpliterator, init$, void, $PipelineHelper*, $Spliterator*, bool)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $method(StreamSpliterators$DoubleWrappingSpliterator, forEachRemaining, void, $DoubleConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$DoubleWrappingSpliterator, forEachRemaining, void, Object$*)},
	{"initPartialTraversalState", "()V", nullptr, 0, $virtualMethod(StreamSpliterators$DoubleWrappingSpliterator, initPartialTraversalState, void)},
	{"lambda$initPartialTraversalState$0", "()Z", nullptr, $PRIVATE | $SYNTHETIC, $method(StreamSpliterators$DoubleWrappingSpliterator, lambda$initPartialTraversalState$0, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC, $method(StreamSpliterators$DoubleWrappingSpliterator, tryAdvance, bool, $DoubleConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$DoubleWrappingSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$DoubleWrappingSpliterator, trySplit, $Spliterator*)},
	{"wrap", "(Ljava/util/Spliterator;)Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator;", "(Ljava/util/Spliterator<TP_IN;>;)Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator<TP_IN;Ljava/lang/Double;*>;", 0, $virtualMethod(StreamSpliterators$DoubleWrappingSpliterator, wrap, $StreamSpliterators$AbstractWrappingSpliterator*, $Spliterator*)},
	{}
};

$InnerClassInfo _StreamSpliterators$DoubleWrappingSpliterator_InnerClassesInfo_[] = {
	{"java.util.stream.StreamSpliterators$DoubleWrappingSpliterator", "java.util.stream.StreamSpliterators", "DoubleWrappingSpliterator", $STATIC | $FINAL},
	{"java.util.stream.StreamSpliterators$AbstractWrappingSpliterator", "java.util.stream.StreamSpliterators", "AbstractWrappingSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$OfDouble", "java.util.stream.SpinedBuffer", "OfDouble", $STATIC},
	{}
};

$ClassInfo _StreamSpliterators$DoubleWrappingSpliterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.StreamSpliterators$DoubleWrappingSpliterator",
	"java.util.stream.StreamSpliterators$AbstractWrappingSpliterator",
	"java.util.Spliterator$OfDouble",
	nullptr,
	_StreamSpliterators$DoubleWrappingSpliterator_MethodInfo_,
	"<P_IN:Ljava/lang/Object;>Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator<TP_IN;Ljava/lang/Double;Ljava/util/stream/SpinedBuffer$OfDouble;>;Ljava/util/Spliterator$OfDouble;",
	nullptr,
	_StreamSpliterators$DoubleWrappingSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.StreamSpliterators"
};

$Object* allocate$StreamSpliterators$DoubleWrappingSpliterator($Class* clazz) {
	return $of($alloc(StreamSpliterators$DoubleWrappingSpliterator));
}

int64_t StreamSpliterators$DoubleWrappingSpliterator::estimateSize() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::estimateSize();
}

int64_t StreamSpliterators$DoubleWrappingSpliterator::getExactSizeIfKnown() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::getExactSizeIfKnown();
}

int32_t StreamSpliterators$DoubleWrappingSpliterator::characteristics() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::characteristics();
}

$Comparator* StreamSpliterators$DoubleWrappingSpliterator::getComparator() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::getComparator();
}

$String* StreamSpliterators$DoubleWrappingSpliterator::toString() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::toString();
}

bool StreamSpliterators$DoubleWrappingSpliterator::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfDouble, this)->$Spliterator$OfDouble::tryAdvance(action);
}

void StreamSpliterators$DoubleWrappingSpliterator::forEachRemaining($Consumer* action) {
	this->$StreamSpliterators$AbstractWrappingSpliterator::forEachRemaining(action);
}

bool StreamSpliterators$DoubleWrappingSpliterator::hasCharacteristics(int32_t characteristics) {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::hasCharacteristics(characteristics);
}

int32_t StreamSpliterators$DoubleWrappingSpliterator::hashCode() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::hashCode();
}

bool StreamSpliterators$DoubleWrappingSpliterator::equals(Object$* obj) {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::equals(obj);
}

$Object* StreamSpliterators$DoubleWrappingSpliterator::clone() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::clone();
}

void StreamSpliterators$DoubleWrappingSpliterator::finalize() {
	this->$StreamSpliterators$AbstractWrappingSpliterator::finalize();
}

StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::MemberClass0$() {
	$patchMemberClass(StreamSpliterators$DoubleWrappingSpliterator, $Spliterator$OfDouble, memberClass0$);
}

$Spliterator$OfDouble* StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfDouble, ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->trySplit());
}

bool StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::tryAdvance($DoubleConsumer* action) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::forEachRemaining($DoubleConsumer* action) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::tryAdvance($Consumer* action) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

void StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::forEachRemaining(Object$* action) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::tryAdvance(Object$* action) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

int64_t StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::estimateSize() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->estimateSize();
}

int64_t StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::getExactSizeIfKnown() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->getExactSizeIfKnown();
}

int32_t StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::characteristics() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->characteristics();
}

bool StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::getComparator() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->getComparator();
}

int32_t StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::hashCode() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->hashCode();
}

bool StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::equals(Object$* obj) {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->equals(obj);
}

$Object* StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::clone() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->clone();
}

$String* StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::toString() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->toString();
}

void StreamSpliterators$DoubleWrappingSpliterator::MemberClass0$::finalize() {
	return ((StreamSpliterators$DoubleWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$DoubleWrappingSpliterator, memberClass0$)))->finalize();
}

void StreamSpliterators$DoubleWrappingSpliterator::init$($PipelineHelper* ph, $Supplier* supplier, bool parallel) {
	$StreamSpliterators$AbstractWrappingSpliterator::init$(ph, supplier, parallel);
}

void StreamSpliterators$DoubleWrappingSpliterator::init$($PipelineHelper* ph, $Spliterator* spliterator, bool parallel) {
	$StreamSpliterators$AbstractWrappingSpliterator::init$(ph, spliterator, parallel);
}

$StreamSpliterators$AbstractWrappingSpliterator* StreamSpliterators$DoubleWrappingSpliterator::wrap($Spliterator* s) {
	return $new(StreamSpliterators$DoubleWrappingSpliterator, this->ph, s, this->isParallel);
}

void StreamSpliterators$DoubleWrappingSpliterator::initPartialTraversalState() {
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfDouble, b, $new($SpinedBuffer$OfDouble));
	$set(this, buffer, b);
	$set(this, bufferSink, $nc(this->ph)->wrapSink(static_cast<$Sink$OfDouble*>($$new(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept, static_cast<$SpinedBuffer$OfDouble*>(b)))));
	$set(this, pusher, static_cast<$BooleanSupplier*>($new(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, this)));
}

$Spliterator* StreamSpliterators$DoubleWrappingSpliterator::trySplit() {
	return $cast($Spliterator$OfDouble, $StreamSpliterators$AbstractWrappingSpliterator::trySplit());
}

bool StreamSpliterators$DoubleWrappingSpliterator::tryAdvance($DoubleConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	bool hasNext = doAdvance();
	if (hasNext) {
		consumer->accept($nc(($cast($SpinedBuffer$OfDouble, this->buffer)))->get(this->nextToConsume));
	}
	return hasNext;
}

void StreamSpliterators$DoubleWrappingSpliterator::forEachRemaining($DoubleConsumer* consumer) {
	if (this->buffer == nullptr && !this->finished) {
		$Objects::requireNonNull(consumer);
		init();
		$nc(this->ph)->wrapAndCopyInto(static_cast<$Sink$OfDouble*>($$new(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2, static_cast<$DoubleConsumer*>(consumer))), this->spliterator);
		this->finished = true;
	} else {
		do {
		} while (tryAdvance(consumer));
	}
}

void StreamSpliterators$DoubleWrappingSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($DoubleConsumer, consumer));
}

bool StreamSpliterators$DoubleWrappingSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($DoubleConsumer, consumer));
}

bool StreamSpliterators$DoubleWrappingSpliterator::lambda$initPartialTraversalState$0() {
	return $nc(this->spliterator)->tryAdvance(this->bufferSink);
}

StreamSpliterators$DoubleWrappingSpliterator::StreamSpliterators$DoubleWrappingSpliterator() {
}

$Class* StreamSpliterators$DoubleWrappingSpliterator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::classInfo$.name)) {
			return StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept::load$(name, initialize);
		}
		if (name->equals(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::classInfo$.name)) {
			return StreamSpliterators$DoubleWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::load$(name, initialize);
		}
		if (name->equals(StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::classInfo$.name)) {
			return StreamSpliterators$DoubleWrappingSpliterator$$Lambda$accept$2::load$(name, initialize);
		}
	}
	$loadClass(StreamSpliterators$DoubleWrappingSpliterator, name, initialize, &_StreamSpliterators$DoubleWrappingSpliterator_ClassInfo_, allocate$StreamSpliterators$DoubleWrappingSpliterator);
	return class$;
}

$Class* StreamSpliterators$DoubleWrappingSpliterator::class$ = nullptr;

		} // stream
	} // util
} // java