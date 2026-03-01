#include <java/util/stream/StreamSpliterators$IntWrappingSpliterator.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/function/BooleanSupplier.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/AbstractSpinedBuffer.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink$OfInt.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SpinedBuffer$OfInt.h>
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
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSpinedBuffer = ::java::util::stream::AbstractSpinedBuffer;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $Sink$OfInt = ::java::util::stream::Sink$OfInt;
using $SpinedBuffer$OfInt = ::java::util::stream::SpinedBuffer$OfInt;
using $StreamSpliterators$AbstractWrappingSpliterator = ::java::util::stream::StreamSpliterators$AbstractWrappingSpliterator;

namespace java {
	namespace util {
		namespace stream {

class StreamSpliterators$IntWrappingSpliterator$$Lambda$accept : public $Sink$OfInt {
	$class(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept, $NO_CLASS_INIT, $Sink$OfInt)
public:
	void init$($SpinedBuffer$OfInt* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int32_t i) override {
		$nc(inst$)->accept(i);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$IntWrappingSpliterator$$Lambda$accept>());
	}
	$SpinedBuffer$OfInt* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept, inst$)},
	{}
};
$MethodInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/SpinedBuffer$OfInt;)V", nullptr, $PUBLIC, $method(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept, init$, void, $SpinedBuffer$OfInt*)},
	{"accept", "(I)V", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept, accept, void, int32_t)},
	{}
};
$ClassInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$IntWrappingSpliterator$$Lambda$accept",
	"java.lang.Object",
	"java.util.stream.Sink$OfInt",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::class$ = nullptr;

class StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1 : public $BooleanSupplier {
	$class(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, $NO_CLASS_INIT, $BooleanSupplier)
public:
	void init$(StreamSpliterators$IntWrappingSpliterator* inst) {
		$set(this, inst$, inst);
	}
	virtual bool getAsBoolean() override {
		 return $nc(inst$)->lambda$initPartialTraversalState$0();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1>());
	}
	StreamSpliterators$IntWrappingSpliterator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, inst$)},
	{}
};
$MethodInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/StreamSpliterators$IntWrappingSpliterator;)V", nullptr, $PUBLIC, $method(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, init$, void, StreamSpliterators$IntWrappingSpliterator*)},
	{"getAsBoolean", "()Z", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, getAsBoolean, bool)},
	{}
};
$ClassInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1",
	"java.lang.Object",
	"java.util.function.BooleanSupplier",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::class$ = nullptr;

class StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2 : public $Sink$OfInt {
	$class(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2, $NO_CLASS_INIT, $Sink$OfInt)
public:
	void init$($IntConsumer* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int32_t value) override {
		$nc(inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2>());
	}
	$IntConsumer* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2, inst$)},
	{}
};
$MethodInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC, $method(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2, init$, void, $IntConsumer*)},
	{"accept", "(I)V", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2, accept, void, int32_t)},
	{}
};
$ClassInfo StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2",
	"java.lang.Object",
	"java.util.stream.Sink$OfInt",
	fieldInfos,
	methodInfos
};
$Class* StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::load$($String* name, bool initialize) {
	$loadClass(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::class$ = nullptr;

$MethodInfo _StreamSpliterators$IntWrappingSpliterator_MethodInfo_[] = {
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
	{"<init>", "(Ljava/util/stream/PipelineHelper;Ljava/util/function/Supplier;Z)V", "(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/function/Supplier<Ljava/util/Spliterator<TP_IN;>;>;Z)V", 0, $method(StreamSpliterators$IntWrappingSpliterator, init$, void, $PipelineHelper*, $Supplier*, bool)},
	{"<init>", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Z)V", "(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;Z)V", 0, $method(StreamSpliterators$IntWrappingSpliterator, init$, void, $PipelineHelper*, $Spliterator*, bool)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC, $method(StreamSpliterators$IntWrappingSpliterator, forEachRemaining, void, $IntConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$IntWrappingSpliterator, forEachRemaining, void, Object$*)},
	{"initPartialTraversalState", "()V", nullptr, 0, $virtualMethod(StreamSpliterators$IntWrappingSpliterator, initPartialTraversalState, void)},
	{"lambda$initPartialTraversalState$0", "()Z", nullptr, $PRIVATE | $SYNTHETIC, $method(StreamSpliterators$IntWrappingSpliterator, lambda$initPartialTraversalState$0, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"*tryAdvance", "(Ljava/util/function/Consumer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC, $method(StreamSpliterators$IntWrappingSpliterator, tryAdvance, bool, $IntConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $method(StreamSpliterators$IntWrappingSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(StreamSpliterators$IntWrappingSpliterator, trySplit, $Spliterator*)},
	{"wrap", "(Ljava/util/Spliterator;)Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator;", "(Ljava/util/Spliterator<TP_IN;>;)Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator<TP_IN;Ljava/lang/Integer;*>;", 0, $virtualMethod(StreamSpliterators$IntWrappingSpliterator, wrap, $StreamSpliterators$AbstractWrappingSpliterator*, $Spliterator*)},
	{}
};

$InnerClassInfo _StreamSpliterators$IntWrappingSpliterator_InnerClassesInfo_[] = {
	{"java.util.stream.StreamSpliterators$IntWrappingSpliterator", "java.util.stream.StreamSpliterators", "IntWrappingSpliterator", $STATIC | $FINAL},
	{"java.util.stream.StreamSpliterators$AbstractWrappingSpliterator", "java.util.stream.StreamSpliterators", "AbstractWrappingSpliterator", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$OfInt", "java.util.stream.SpinedBuffer", "OfInt", $STATIC},
	{}
};

$ClassInfo _StreamSpliterators$IntWrappingSpliterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.StreamSpliterators$IntWrappingSpliterator",
	"java.util.stream.StreamSpliterators$AbstractWrappingSpliterator",
	"java.util.Spliterator$OfInt",
	nullptr,
	_StreamSpliterators$IntWrappingSpliterator_MethodInfo_,
	"<P_IN:Ljava/lang/Object;>Ljava/util/stream/StreamSpliterators$AbstractWrappingSpliterator<TP_IN;Ljava/lang/Integer;Ljava/util/stream/SpinedBuffer$OfInt;>;Ljava/util/Spliterator$OfInt;",
	nullptr,
	_StreamSpliterators$IntWrappingSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.StreamSpliterators"
};

$Object* allocate$StreamSpliterators$IntWrappingSpliterator($Class* clazz) {
	return $of($alloc(StreamSpliterators$IntWrappingSpliterator));
}

int64_t StreamSpliterators$IntWrappingSpliterator::estimateSize() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::estimateSize();
}

int64_t StreamSpliterators$IntWrappingSpliterator::getExactSizeIfKnown() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::getExactSizeIfKnown();
}

int32_t StreamSpliterators$IntWrappingSpliterator::characteristics() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::characteristics();
}

$Comparator* StreamSpliterators$IntWrappingSpliterator::getComparator() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::getComparator();
}

$String* StreamSpliterators$IntWrappingSpliterator::toString() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::toString();
}

bool StreamSpliterators$IntWrappingSpliterator::tryAdvance($Consumer* action) {
	 return $as($Spliterator$OfInt, this)->$Spliterator$OfInt::tryAdvance(action);
}

void StreamSpliterators$IntWrappingSpliterator::forEachRemaining($Consumer* action) {
	this->$StreamSpliterators$AbstractWrappingSpliterator::forEachRemaining(action);
}

bool StreamSpliterators$IntWrappingSpliterator::hasCharacteristics(int32_t characteristics) {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::hasCharacteristics(characteristics);
}

int32_t StreamSpliterators$IntWrappingSpliterator::hashCode() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::hashCode();
}

bool StreamSpliterators$IntWrappingSpliterator::equals(Object$* obj) {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::equals(obj);
}

$Object* StreamSpliterators$IntWrappingSpliterator::clone() {
	 return this->$StreamSpliterators$AbstractWrappingSpliterator::clone();
}

void StreamSpliterators$IntWrappingSpliterator::finalize() {
	this->$StreamSpliterators$AbstractWrappingSpliterator::finalize();
}

StreamSpliterators$IntWrappingSpliterator::MemberClass0$::MemberClass0$() {
	$patchMemberClass(StreamSpliterators$IntWrappingSpliterator, $Spliterator$OfInt, memberClass0$);
}

$Spliterator$OfInt* StreamSpliterators$IntWrappingSpliterator::MemberClass0$::trySplit() {
	return $cast($Spliterator$OfInt, ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->trySplit());
}

bool StreamSpliterators$IntWrappingSpliterator::MemberClass0$::tryAdvance($IntConsumer* action) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$IntWrappingSpliterator::MemberClass0$::forEachRemaining($IntConsumer* action) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$IntWrappingSpliterator::MemberClass0$::tryAdvance($Consumer* action) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

void StreamSpliterators$IntWrappingSpliterator::MemberClass0$::forEachRemaining($Consumer* action) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

void StreamSpliterators$IntWrappingSpliterator::MemberClass0$::forEachRemaining(Object$* action) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->forEachRemaining(action);
}

bool StreamSpliterators$IntWrappingSpliterator::MemberClass0$::tryAdvance(Object$* action) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->tryAdvance(action);
}

int64_t StreamSpliterators$IntWrappingSpliterator::MemberClass0$::estimateSize() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->estimateSize();
}

int64_t StreamSpliterators$IntWrappingSpliterator::MemberClass0$::getExactSizeIfKnown() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->getExactSizeIfKnown();
}

int32_t StreamSpliterators$IntWrappingSpliterator::MemberClass0$::characteristics() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->characteristics();
}

bool StreamSpliterators$IntWrappingSpliterator::MemberClass0$::hasCharacteristics(int32_t characteristics) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->hasCharacteristics(characteristics);
}

$Comparator* StreamSpliterators$IntWrappingSpliterator::MemberClass0$::getComparator() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->getComparator();
}

int32_t StreamSpliterators$IntWrappingSpliterator::MemberClass0$::hashCode() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->hashCode();
}

bool StreamSpliterators$IntWrappingSpliterator::MemberClass0$::equals(Object$* obj) {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->equals(obj);
}

$Object* StreamSpliterators$IntWrappingSpliterator::MemberClass0$::clone() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->clone();
}

$String* StreamSpliterators$IntWrappingSpliterator::MemberClass0$::toString() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->toString();
}

void StreamSpliterators$IntWrappingSpliterator::MemberClass0$::finalize() {
	return ((StreamSpliterators$IntWrappingSpliterator*)(void*)((int8_t*)(void*)this - $offsetof(StreamSpliterators$IntWrappingSpliterator, memberClass0$)))->finalize();
}

void StreamSpliterators$IntWrappingSpliterator::init$($PipelineHelper* ph, $Supplier* supplier, bool parallel) {
	$StreamSpliterators$AbstractWrappingSpliterator::init$(ph, supplier, parallel);
}

void StreamSpliterators$IntWrappingSpliterator::init$($PipelineHelper* ph, $Spliterator* spliterator, bool parallel) {
	$StreamSpliterators$AbstractWrappingSpliterator::init$(ph, spliterator, parallel);
}

$StreamSpliterators$AbstractWrappingSpliterator* StreamSpliterators$IntWrappingSpliterator::wrap($Spliterator* s) {
	return $new(StreamSpliterators$IntWrappingSpliterator, this->ph, s, this->isParallel);
}

void StreamSpliterators$IntWrappingSpliterator::initPartialTraversalState() {
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfInt, b, $new($SpinedBuffer$OfInt));
	$set(this, buffer, b);
	$set(this, bufferSink, $nc(this->ph)->wrapSink(static_cast<$Sink$OfInt*>($$new(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept, static_cast<$SpinedBuffer$OfInt*>(b)))));
	$set(this, pusher, static_cast<$BooleanSupplier*>($new(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1, this)));
}

$Spliterator* StreamSpliterators$IntWrappingSpliterator::trySplit() {
	return $cast($Spliterator$OfInt, $StreamSpliterators$AbstractWrappingSpliterator::trySplit());
}

bool StreamSpliterators$IntWrappingSpliterator::tryAdvance($IntConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	bool hasNext = doAdvance();
	if (hasNext) {
		consumer->accept($nc(($cast($SpinedBuffer$OfInt, this->buffer)))->get(this->nextToConsume));
	}
	return hasNext;
}

void StreamSpliterators$IntWrappingSpliterator::forEachRemaining($IntConsumer* consumer) {
	if (this->buffer == nullptr && !this->finished) {
		$Objects::requireNonNull(consumer);
		init();
		$nc(this->ph)->wrapAndCopyInto(static_cast<$Sink$OfInt*>($$new(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2, static_cast<$IntConsumer*>(consumer))), this->spliterator);
		this->finished = true;
	} else {
		do {
		} while (tryAdvance(consumer));
	}
}

void StreamSpliterators$IntWrappingSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($IntConsumer, consumer));
}

bool StreamSpliterators$IntWrappingSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($IntConsumer, consumer));
}

bool StreamSpliterators$IntWrappingSpliterator::lambda$initPartialTraversalState$0() {
	return $nc(this->spliterator)->tryAdvance(this->bufferSink);
}

StreamSpliterators$IntWrappingSpliterator::StreamSpliterators$IntWrappingSpliterator() {
}

$Class* StreamSpliterators$IntWrappingSpliterator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::classInfo$.name)) {
			return StreamSpliterators$IntWrappingSpliterator$$Lambda$accept::load$(name, initialize);
		}
		if (name->equals(StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::classInfo$.name)) {
			return StreamSpliterators$IntWrappingSpliterator$$Lambda$lambda$initPartialTraversalState$0$1::load$(name, initialize);
		}
		if (name->equals(StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::classInfo$.name)) {
			return StreamSpliterators$IntWrappingSpliterator$$Lambda$accept$2::load$(name, initialize);
		}
	}
	$loadClass(StreamSpliterators$IntWrappingSpliterator, name, initialize, &_StreamSpliterators$IntWrappingSpliterator_ClassInfo_, allocate$StreamSpliterators$IntWrappingSpliterator);
	return class$;
}

$Class* StreamSpliterators$IntWrappingSpliterator::class$ = nullptr;

		} // stream
	} // util
} // java