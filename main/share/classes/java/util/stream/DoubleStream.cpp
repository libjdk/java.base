#include <java/util/stream/DoubleStream.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <java/util/DoubleSummaryStatistics.h>
#include <java/util/Objects.h>
#include <java/util/OptionalDouble.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/DoubleBinaryOperator.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/DoubleFunction.h>
#include <java/util/function/DoublePredicate.h>
#include <java/util/function/DoubleSupplier.h>
#include <java/util/function/DoubleToIntFunction.h>
#include <java/util/function/DoubleToLongFunction.h>
#include <java/util/function/DoubleUnaryOperator.h>
#include <java/util/function/ObjDoubleConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/DoubleStream$1.h>
#include <java/util/stream/DoubleStream$2.h>
#include <java/util/stream/DoubleStream$Builder.h>
#include <java/util/stream/DoubleStream$DoubleMapMultiConsumer.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/SpinedBuffer$OfDouble.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSpliterators$InfiniteSupplyingSpliterator$OfDouble.h>
#include <java/util/stream/StreamSupport.h>
#include <java/util/stream/Streams$ConcatSpliterator$OfDouble.h>
#include <java/util/stream/Streams$DoubleStreamBuilderImpl.h>
#include <java/util/stream/Streams.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble$Taking.h>
#include <jcpp.h>

#undef IMMUTABLE
#undef MAX_VALUE
#undef NONNULL
#undef ORDERED

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Arrays = ::java::util::Arrays;
using $DoubleSummaryStatistics = ::java::util::DoubleSummaryStatistics;
using $Objects = ::java::util::Objects;
using $OptionalDouble = ::java::util::OptionalDouble;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterators = ::java::util::Spliterators;
using $BiConsumer = ::java::util::function::BiConsumer;
using $DoubleBinaryOperator = ::java::util::function::DoubleBinaryOperator;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $DoubleFunction = ::java::util::function::DoubleFunction;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $DoubleSupplier = ::java::util::function::DoubleSupplier;
using $DoubleToIntFunction = ::java::util::function::DoubleToIntFunction;
using $DoubleToLongFunction = ::java::util::function::DoubleToLongFunction;
using $DoubleUnaryOperator = ::java::util::function::DoubleUnaryOperator;
using $ObjDoubleConsumer = ::java::util::function::ObjDoubleConsumer;
using $Supplier = ::java::util::function::Supplier;
using $BaseStream = ::java::util::stream::BaseStream;
using $DoubleStream$1 = ::java::util::stream::DoubleStream$1;
using $DoubleStream$2 = ::java::util::stream::DoubleStream$2;
using $DoubleStream$Builder = ::java::util::stream::DoubleStream$Builder;
using $DoubleStream$DoubleMapMultiConsumer = ::java::util::stream::DoubleStream$DoubleMapMultiConsumer;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $SpinedBuffer$OfDouble = ::java::util::stream::SpinedBuffer$OfDouble;
using $Stream = ::java::util::stream::Stream;
using $StreamSpliterators$InfiniteSupplyingSpliterator$OfDouble = ::java::util::stream::StreamSpliterators$InfiniteSupplyingSpliterator$OfDouble;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams = ::java::util::stream::Streams;
using $Streams$ConcatSpliterator$OfDouble = ::java::util::stream::Streams$ConcatSpliterator$OfDouble;
using $Streams$DoubleStreamBuilderImpl = ::java::util::stream::Streams$DoubleStreamBuilderImpl;
using $WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping;
using $WhileOps$UnorderedWhileSpliterator$OfDouble$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble$Taking;

namespace java {
	namespace util {
		namespace stream {

class DoubleStream$$Lambda$lambda$mapMulti$0 : public $DoubleFunction {
	$class(DoubleStream$$Lambda$lambda$mapMulti$0, $NO_CLASS_INIT, $DoubleFunction)
public:
	void init$($DoubleStream$DoubleMapMultiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(double e) override {
		 return $of(DoubleStream::lambda$mapMulti$0(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoubleStream$$Lambda$lambda$mapMulti$0>());
	}
	$DoubleStream$DoubleMapMultiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DoubleStream$$Lambda$lambda$mapMulti$0::fieldInfos[2] = {
	{"mapper", "Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;", nullptr, $PUBLIC, $field(DoubleStream$$Lambda$lambda$mapMulti$0, mapper)},
	{}
};
$MethodInfo DoubleStream$$Lambda$lambda$mapMulti$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;)V", nullptr, $PUBLIC, $method(DoubleStream$$Lambda$lambda$mapMulti$0, init$, void, $DoubleStream$DoubleMapMultiConsumer*)},
	{"apply", "(D)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoubleStream$$Lambda$lambda$mapMulti$0, apply, $Object*, double)},
	{}
};
$ClassInfo DoubleStream$$Lambda$lambda$mapMulti$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoubleStream$$Lambda$lambda$mapMulti$0",
	"java.lang.Object",
	"java.util.function.DoubleFunction",
	fieldInfos,
	methodInfos
};
$Class* DoubleStream$$Lambda$lambda$mapMulti$0::load$($String* name, bool initialize) {
	$loadClass(DoubleStream$$Lambda$lambda$mapMulti$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoubleStream$$Lambda$lambda$mapMulti$0::class$ = nullptr;

class DoubleStream$$Lambda$close$1 : public $Runnable {
	$class(DoubleStream$$Lambda$close$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$($BaseStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->close();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoubleStream$$Lambda$close$1>());
	}
	$BaseStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DoubleStream$$Lambda$close$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DoubleStream$$Lambda$close$1, inst$)},
	{}
};
$MethodInfo DoubleStream$$Lambda$close$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/BaseStream;)V", nullptr, $PUBLIC, $method(DoubleStream$$Lambda$close$1, init$, void, $BaseStream*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(DoubleStream$$Lambda$close$1, run, void)},
	{}
};
$ClassInfo DoubleStream$$Lambda$close$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoubleStream$$Lambda$close$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* DoubleStream$$Lambda$close$1::load$($String* name, bool initialize) {
	$loadClass(DoubleStream$$Lambda$close$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoubleStream$$Lambda$close$1::class$ = nullptr;

$MethodInfo _DoubleStream_MethodInfo_[] = {
	{"allMatch", "(Ljava/util/function/DoublePredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, allMatch, bool, $DoublePredicate*)},
	{"anyMatch", "(Ljava/util/function/DoublePredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, anyMatch, bool, $DoublePredicate*)},
	{"average", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, average, $OptionalDouble*)},
	{"boxed", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Double;>;", $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, boxed, $Stream*)},
	{"builder", "()Ljava/util/stream/DoubleStream$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, builder, $DoubleStream$Builder*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/ObjDoubleConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjDoubleConsumer<TR;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, collect, $Object*, $Supplier*, $ObjDoubleConsumer*, $BiConsumer*)},
	{"concat", "(Ljava/util/stream/DoubleStream;Ljava/util/stream/DoubleStream;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, concat, DoubleStream*, DoubleStream*, DoubleStream*)},
	{"count", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, count, int64_t)},
	{"distinct", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, distinct, DoubleStream*)},
	{"dropWhile", "(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC, $virtualMethod(DoubleStream, dropWhile, DoubleStream*, $DoublePredicate*)},
	{"empty", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, empty, DoubleStream*)},
	{"filter", "(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, filter, DoubleStream*, $DoublePredicate*)},
	{"findAny", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, findAny, $OptionalDouble*)},
	{"findFirst", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, findFirst, $OptionalDouble*)},
	{"flatMap", "(Ljava/util/function/DoubleFunction;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/DoubleFunction<+Ljava/util/stream/DoubleStream;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, flatMap, DoubleStream*, $DoubleFunction*)},
	{"forEach", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, forEach, void, $DoubleConsumer*)},
	{"forEachOrdered", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, forEachOrdered, void, $DoubleConsumer*)},
	{"generate", "(Ljava/util/function/DoubleSupplier;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, generate, DoubleStream*, $DoubleSupplier*)},
	{"iterate", "(DLjava/util/function/DoubleUnaryOperator;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, iterate, DoubleStream*, double, $DoubleUnaryOperator*)},
	{"iterate", "(DLjava/util/function/DoublePredicate;Ljava/util/function/DoubleUnaryOperator;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, iterate, DoubleStream*, double, $DoublePredicate*, $DoubleUnaryOperator*)},
	{"iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"lambda$mapMulti$0", "(Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;D)Ljava/util/stream/DoubleStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoubleStream, lambda$mapMulti$0, DoubleStream*, $DoubleStream$DoubleMapMultiConsumer*, double)},
	{"limit", "(J)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, limit, DoubleStream*, int64_t)},
	{"map", "(Ljava/util/function/DoubleUnaryOperator;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, map, DoubleStream*, $DoubleUnaryOperator*)},
	{"mapMulti", "(Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC, $virtualMethod(DoubleStream, mapMulti, DoubleStream*, $DoubleStream$DoubleMapMultiConsumer*)},
	{"mapToInt", "(Ljava/util/function/DoubleToIntFunction;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, mapToInt, $IntStream*, $DoubleToIntFunction*)},
	{"mapToLong", "(Ljava/util/function/DoubleToLongFunction;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, mapToLong, $LongStream*, $DoubleToLongFunction*)},
	{"mapToObj", "(Ljava/util/function/DoubleFunction;)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/DoubleFunction<+TU;>;)Ljava/util/stream/Stream<TU;>;", $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, mapToObj, $Stream*, $DoubleFunction*)},
	{"max", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, max, $OptionalDouble*)},
	{"min", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, min, $OptionalDouble*)},
	{"noneMatch", "(Ljava/util/function/DoublePredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, noneMatch, bool, $DoublePredicate*)},
	{"of", "(D)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(DoubleStream, of, DoubleStream*, double)},
	{"of", "([D)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(DoubleStream, of, DoubleStream*, $doubles*)},
	{"parallel", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT},
	{"peek", "(Ljava/util/function/DoubleConsumer;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, peek, DoubleStream*, $DoubleConsumer*)},
	{"reduce", "(DLjava/util/function/DoubleBinaryOperator;)D", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, reduce, double, double, $DoubleBinaryOperator*)},
	{"reduce", "(Ljava/util/function/DoubleBinaryOperator;)Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, reduce, $OptionalDouble*, $DoubleBinaryOperator*)},
	{"sequential", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT},
	{"skip", "(J)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, skip, DoubleStream*, int64_t)},
	{"sorted", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, sorted, DoubleStream*)},
	{"spliterator", "()Ljava/util/Spliterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"sum", "()D", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, sum, double)},
	{"summaryStatistics", "()Ljava/util/DoubleSummaryStatistics;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, summaryStatistics, $DoubleSummaryStatistics*)},
	{"takeWhile", "(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC, $virtualMethod(DoubleStream, takeWhile, DoubleStream*, $DoublePredicate*)},
	{"toArray", "()[D", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(DoubleStream, toArray, $doubles*)},
	{}
};

$InnerClassInfo _DoubleStream_InnerClassesInfo_[] = {
	{"java.util.stream.DoubleStream$DoubleMapMultiConsumer", "java.util.stream.DoubleStream", "DoubleMapMultiConsumer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.DoubleStream$Builder", "java.util.stream.DoubleStream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.DoubleStream$2", nullptr, nullptr, 0},
	{"java.util.stream.DoubleStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoubleStream_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.stream.DoubleStream",
	nullptr,
	"java.util.stream.BaseStream",
	nullptr,
	_DoubleStream_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/stream/BaseStream<Ljava/lang/Double;Ljava/util/stream/DoubleStream;>;",
	nullptr,
	_DoubleStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.DoubleStream$DoubleMapMultiConsumer,java.util.stream.DoubleStream$Builder,java.util.stream.DoubleStream$2,java.util.stream.DoubleStream$1"
};

$Object* allocate$DoubleStream($Class* clazz) {
	return $of($alloc(DoubleStream));
}

DoubleStream* DoubleStream::mapMulti($DoubleStream$DoubleMapMultiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMap(static_cast<$DoubleFunction*>($$new(DoubleStream$$Lambda$lambda$mapMulti$0, mapper)));
}

DoubleStream* DoubleStream::takeWhile($DoublePredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator$OfDouble, var$0, $as($Spliterator$OfDouble, $new($WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, $($cast($Spliterator$OfDouble, spliterator())), true, predicate)));
	return $cast(DoubleStream, $nc($($StreamSupport::doubleStream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(DoubleStream$$Lambda$close$1, this))));
}

DoubleStream* DoubleStream::dropWhile($DoublePredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator$OfDouble, var$0, $as($Spliterator$OfDouble, $new($WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping, $($cast($Spliterator$OfDouble, spliterator())), true, predicate)));
	return $cast(DoubleStream, $nc($($StreamSupport::doubleStream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(DoubleStream$$Lambda$close$1, this))));
}

$DoubleStream$Builder* DoubleStream::builder() {
	$init(DoubleStream);
	return $new($Streams$DoubleStreamBuilderImpl);
}

DoubleStream* DoubleStream::empty() {
	$init(DoubleStream);
	return $StreamSupport::doubleStream($($Spliterators::emptyDoubleSpliterator()), false);
}

DoubleStream* DoubleStream::of(double t) {
	$init(DoubleStream);
	return $StreamSupport::doubleStream($as($Spliterator$OfDouble, $$new($Streams$DoubleStreamBuilderImpl, t)), false);
}

DoubleStream* DoubleStream::of($doubles* values) {
	$init(DoubleStream);
	return $Arrays::stream(values);
}

DoubleStream* DoubleStream::iterate(double seed, $DoubleUnaryOperator* f) {
	$init(DoubleStream);
	$Objects::requireNonNull(f);
	$var($Spliterator$OfDouble, spliterator, $new($DoubleStream$1, $Long::MAX_VALUE, ($Spliterator::ORDERED | $Spliterator::IMMUTABLE) | $Spliterator::NONNULL, f, seed));
	return $StreamSupport::doubleStream(spliterator, false);
}

DoubleStream* DoubleStream::iterate(double seed, $DoublePredicate* hasNext, $DoubleUnaryOperator* next) {
	$init(DoubleStream);
	$Objects::requireNonNull(next);
	$Objects::requireNonNull(hasNext);
	$var($Spliterator$OfDouble, spliterator, $new($DoubleStream$2, $Long::MAX_VALUE, ($Spliterator::ORDERED | $Spliterator::IMMUTABLE) | $Spliterator::NONNULL, next, seed, hasNext));
	return $StreamSupport::doubleStream(spliterator, false);
}

DoubleStream* DoubleStream::generate($DoubleSupplier* s) {
	$init(DoubleStream);
	$Objects::requireNonNull(s);
	return $StreamSupport::doubleStream($as($Spliterator$OfDouble, $$new($StreamSpliterators$InfiniteSupplyingSpliterator$OfDouble, $Long::MAX_VALUE, s)), false);
}

DoubleStream* DoubleStream::concat(DoubleStream* a, DoubleStream* b) {
	$init(DoubleStream);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(a);
	$Objects::requireNonNull(b);
	$var($Spliterator$OfDouble, var$0, $cast($Spliterator$OfDouble, a->spliterator()));
	$var($Spliterator$OfDouble, split, $as($Spliterator$OfDouble, $new($Streams$ConcatSpliterator$OfDouble, var$0, $($cast($Spliterator$OfDouble, b->spliterator())))));
	bool var$1 = a->isParallel();
	$var(DoubleStream, stream, $StreamSupport::doubleStream(split, var$1 || b->isParallel()));
	return $cast(DoubleStream, $nc(stream)->onClose($($Streams::composedClose(a, b))));
}

DoubleStream* DoubleStream::lambda$mapMulti$0($DoubleStream$DoubleMapMultiConsumer* mapper, double e) {
	$init(DoubleStream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfDouble, buffer, $new($SpinedBuffer$OfDouble));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::doubleStream($($cast($Spliterator$OfDouble, buffer->spliterator())), false);
}

$Class* DoubleStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DoubleStream$$Lambda$lambda$mapMulti$0::classInfo$.name)) {
			return DoubleStream$$Lambda$lambda$mapMulti$0::load$(name, initialize);
		}
		if (name->equals(DoubleStream$$Lambda$close$1::classInfo$.name)) {
			return DoubleStream$$Lambda$close$1::load$(name, initialize);
		}
	}
	$loadClass(DoubleStream, name, initialize, &_DoubleStream_ClassInfo_, allocate$DoubleStream);
	return class$;
}

$Class* DoubleStream::class$ = nullptr;

		} // stream
	} // util
} // java