#include <java/util/stream/IntStream.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <java/util/IntSummaryStatistics.h>
#include <java/util/Objects.h>
#include <java/util/OptionalDouble.h>
#include <java/util/OptionalInt.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/IntBinaryOperator.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/IntPredicate.h>
#include <java/util/function/IntSupplier.h>
#include <java/util/function/IntToDoubleFunction.h>
#include <java/util/function/IntToLongFunction.h>
#include <java/util/function/IntUnaryOperator.h>
#include <java/util/function/ObjIntConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntStream$1.h>
#include <java/util/stream/IntStream$2.h>
#include <java/util/stream/IntStream$Builder.h>
#include <java/util/stream/IntStream$IntMapMultiConsumer.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/SpinedBuffer$OfInt.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSpliterators$InfiniteSupplyingSpliterator$OfInt.h>
#include <java/util/stream/StreamSupport.h>
#include <java/util/stream/Streams$ConcatSpliterator$OfInt.h>
#include <java/util/stream/Streams$IntStreamBuilderImpl.h>
#include <java/util/stream/Streams$RangeIntSpliterator.h>
#include <java/util/stream/Streams.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt$Dropping.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt$Taking.h>
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
using $IntSummaryStatistics = ::java::util::IntSummaryStatistics;
using $Objects = ::java::util::Objects;
using $OptionalDouble = ::java::util::OptionalDouble;
using $OptionalInt = ::java::util::OptionalInt;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterators = ::java::util::Spliterators;
using $BiConsumer = ::java::util::function::BiConsumer;
using $IntBinaryOperator = ::java::util::function::IntBinaryOperator;
using $IntConsumer = ::java::util::function::IntConsumer;
using $IntFunction = ::java::util::function::IntFunction;
using $IntPredicate = ::java::util::function::IntPredicate;
using $IntSupplier = ::java::util::function::IntSupplier;
using $IntToDoubleFunction = ::java::util::function::IntToDoubleFunction;
using $IntToLongFunction = ::java::util::function::IntToLongFunction;
using $IntUnaryOperator = ::java::util::function::IntUnaryOperator;
using $ObjIntConsumer = ::java::util::function::ObjIntConsumer;
using $Supplier = ::java::util::function::Supplier;
using $BaseStream = ::java::util::stream::BaseStream;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntStream$1 = ::java::util::stream::IntStream$1;
using $IntStream$2 = ::java::util::stream::IntStream$2;
using $IntStream$Builder = ::java::util::stream::IntStream$Builder;
using $IntStream$IntMapMultiConsumer = ::java::util::stream::IntStream$IntMapMultiConsumer;
using $LongStream = ::java::util::stream::LongStream;
using $SpinedBuffer$OfInt = ::java::util::stream::SpinedBuffer$OfInt;
using $Stream = ::java::util::stream::Stream;
using $StreamSpliterators$InfiniteSupplyingSpliterator$OfInt = ::java::util::stream::StreamSpliterators$InfiniteSupplyingSpliterator$OfInt;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams = ::java::util::stream::Streams;
using $Streams$ConcatSpliterator$OfInt = ::java::util::stream::Streams$ConcatSpliterator$OfInt;
using $Streams$IntStreamBuilderImpl = ::java::util::stream::Streams$IntStreamBuilderImpl;
using $Streams$RangeIntSpliterator = ::java::util::stream::Streams$RangeIntSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfInt$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt$Dropping;
using $WhileOps$UnorderedWhileSpliterator$OfInt$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt$Taking;

namespace java {
	namespace util {
		namespace stream {

class IntStream$$Lambda$lambda$mapMulti$0 : public $IntFunction {
	$class(IntStream$$Lambda$lambda$mapMulti$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$($IntStream$IntMapMultiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(int32_t e) override {
		 return $of(IntStream::lambda$mapMulti$0(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<IntStream$$Lambda$lambda$mapMulti$0>());
	}
	$IntStream$IntMapMultiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo IntStream$$Lambda$lambda$mapMulti$0::fieldInfos[2] = {
	{"mapper", "Ljava/util/stream/IntStream$IntMapMultiConsumer;", nullptr, $PUBLIC, $field(IntStream$$Lambda$lambda$mapMulti$0, mapper)},
	{}
};
$MethodInfo IntStream$$Lambda$lambda$mapMulti$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/IntStream$IntMapMultiConsumer;)V", nullptr, $PUBLIC, $method(IntStream$$Lambda$lambda$mapMulti$0, init$, void, $IntStream$IntMapMultiConsumer*)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(IntStream$$Lambda$lambda$mapMulti$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo IntStream$$Lambda$lambda$mapMulti$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.IntStream$$Lambda$lambda$mapMulti$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	fieldInfos,
	methodInfos
};
$Class* IntStream$$Lambda$lambda$mapMulti$0::load$($String* name, bool initialize) {
	$loadClass(IntStream$$Lambda$lambda$mapMulti$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* IntStream$$Lambda$lambda$mapMulti$0::class$ = nullptr;

class IntStream$$Lambda$close$1 : public $Runnable {
	$class(IntStream$$Lambda$close$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$($BaseStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->close();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<IntStream$$Lambda$close$1>());
	}
	$BaseStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo IntStream$$Lambda$close$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(IntStream$$Lambda$close$1, inst$)},
	{}
};
$MethodInfo IntStream$$Lambda$close$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/BaseStream;)V", nullptr, $PUBLIC, $method(IntStream$$Lambda$close$1, init$, void, $BaseStream*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(IntStream$$Lambda$close$1, run, void)},
	{}
};
$ClassInfo IntStream$$Lambda$close$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.IntStream$$Lambda$close$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* IntStream$$Lambda$close$1::load$($String* name, bool initialize) {
	$loadClass(IntStream$$Lambda$close$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* IntStream$$Lambda$close$1::class$ = nullptr;

$MethodInfo _IntStream_MethodInfo_[] = {
	{"allMatch", "(Ljava/util/function/IntPredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, allMatch, bool, $IntPredicate*)},
	{"anyMatch", "(Ljava/util/function/IntPredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, anyMatch, bool, $IntPredicate*)},
	{"asDoubleStream", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, asDoubleStream, $DoubleStream*)},
	{"asLongStream", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, asLongStream, $LongStream*)},
	{"average", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, average, $OptionalDouble*)},
	{"boxed", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Integer;>;", $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, boxed, $Stream*)},
	{"builder", "()Ljava/util/stream/IntStream$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, builder, $IntStream$Builder*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/ObjIntConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjIntConsumer<TR;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, collect, $Object*, $Supplier*, $ObjIntConsumer*, $BiConsumer*)},
	{"concat", "(Ljava/util/stream/IntStream;Ljava/util/stream/IntStream;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, concat, IntStream*, IntStream*, IntStream*)},
	{"count", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, count, int64_t)},
	{"distinct", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, distinct, IntStream*)},
	{"dropWhile", "(Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(IntStream, dropWhile, IntStream*, $IntPredicate*)},
	{"empty", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, empty, IntStream*)},
	{"filter", "(Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, filter, IntStream*, $IntPredicate*)},
	{"findAny", "()Ljava/util/OptionalInt;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, findAny, $OptionalInt*)},
	{"findFirst", "()Ljava/util/OptionalInt;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, findFirst, $OptionalInt*)},
	{"flatMap", "(Ljava/util/function/IntFunction;)Ljava/util/stream/IntStream;", "(Ljava/util/function/IntFunction<+Ljava/util/stream/IntStream;>;)Ljava/util/stream/IntStream;", $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, flatMap, IntStream*, $IntFunction*)},
	{"forEach", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, forEach, void, $IntConsumer*)},
	{"forEachOrdered", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, forEachOrdered, void, $IntConsumer*)},
	{"generate", "(Ljava/util/function/IntSupplier;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, generate, IntStream*, $IntSupplier*)},
	{"iterate", "(ILjava/util/function/IntUnaryOperator;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, iterate, IntStream*, int32_t, $IntUnaryOperator*)},
	{"iterate", "(ILjava/util/function/IntPredicate;Ljava/util/function/IntUnaryOperator;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, iterate, IntStream*, int32_t, $IntPredicate*, $IntUnaryOperator*)},
	{"iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"lambda$mapMulti$0", "(Ljava/util/stream/IntStream$IntMapMultiConsumer;I)Ljava/util/stream/IntStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(IntStream, lambda$mapMulti$0, IntStream*, $IntStream$IntMapMultiConsumer*, int32_t)},
	{"limit", "(J)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, limit, IntStream*, int64_t)},
	{"map", "(Ljava/util/function/IntUnaryOperator;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, map, IntStream*, $IntUnaryOperator*)},
	{"mapMulti", "(Ljava/util/stream/IntStream$IntMapMultiConsumer;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(IntStream, mapMulti, IntStream*, $IntStream$IntMapMultiConsumer*)},
	{"mapToDouble", "(Ljava/util/function/IntToDoubleFunction;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, mapToDouble, $DoubleStream*, $IntToDoubleFunction*)},
	{"mapToLong", "(Ljava/util/function/IntToLongFunction;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, mapToLong, $LongStream*, $IntToLongFunction*)},
	{"mapToObj", "(Ljava/util/function/IntFunction;)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/IntFunction<+TU;>;)Ljava/util/stream/Stream<TU;>;", $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, mapToObj, $Stream*, $IntFunction*)},
	{"max", "()Ljava/util/OptionalInt;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, max, $OptionalInt*)},
	{"min", "()Ljava/util/OptionalInt;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, min, $OptionalInt*)},
	{"noneMatch", "(Ljava/util/function/IntPredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, noneMatch, bool, $IntPredicate*)},
	{"of", "(I)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, of, IntStream*, int32_t)},
	{"of", "([I)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(IntStream, of, IntStream*, $ints*)},
	{"parallel", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT},
	{"peek", "(Ljava/util/function/IntConsumer;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, peek, IntStream*, $IntConsumer*)},
	{"range", "(II)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, range, IntStream*, int32_t, int32_t)},
	{"rangeClosed", "(II)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(IntStream, rangeClosed, IntStream*, int32_t, int32_t)},
	{"reduce", "(ILjava/util/function/IntBinaryOperator;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, reduce, int32_t, int32_t, $IntBinaryOperator*)},
	{"reduce", "(Ljava/util/function/IntBinaryOperator;)Ljava/util/OptionalInt;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, reduce, $OptionalInt*, $IntBinaryOperator*)},
	{"sequential", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT},
	{"skip", "(J)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, skip, IntStream*, int64_t)},
	{"sorted", "()Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, sorted, IntStream*)},
	{"spliterator", "()Ljava/util/Spliterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"sum", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, sum, int32_t)},
	{"summaryStatistics", "()Ljava/util/IntSummaryStatistics;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, summaryStatistics, $IntSummaryStatistics*)},
	{"takeWhile", "(Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC, $virtualMethod(IntStream, takeWhile, IntStream*, $IntPredicate*)},
	{"toArray", "()[I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(IntStream, toArray, $ints*)},
	{}
};

$InnerClassInfo _IntStream_InnerClassesInfo_[] = {
	{"java.util.stream.IntStream$IntMapMultiConsumer", "java.util.stream.IntStream", "IntMapMultiConsumer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.IntStream$Builder", "java.util.stream.IntStream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.IntStream$2", nullptr, nullptr, 0},
	{"java.util.stream.IntStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntStream_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.stream.IntStream",
	nullptr,
	"java.util.stream.BaseStream",
	nullptr,
	_IntStream_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/stream/BaseStream<Ljava/lang/Integer;Ljava/util/stream/IntStream;>;",
	nullptr,
	_IntStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.IntStream$IntMapMultiConsumer,java.util.stream.IntStream$Builder,java.util.stream.IntStream$2,java.util.stream.IntStream$1"
};

$Object* allocate$IntStream($Class* clazz) {
	return $of($alloc(IntStream));
}

IntStream* IntStream::mapMulti($IntStream$IntMapMultiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMap(static_cast<$IntFunction*>($$new(IntStream$$Lambda$lambda$mapMulti$0, mapper)));
}

IntStream* IntStream::takeWhile($IntPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator$OfInt, var$0, $as($Spliterator$OfInt, $new($WhileOps$UnorderedWhileSpliterator$OfInt$Taking, $($cast($Spliterator$OfInt, spliterator())), true, predicate)));
	return $cast(IntStream, $nc($($StreamSupport::intStream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(IntStream$$Lambda$close$1, this))));
}

IntStream* IntStream::dropWhile($IntPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator$OfInt, var$0, $as($Spliterator$OfInt, $new($WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, $($cast($Spliterator$OfInt, spliterator())), true, predicate)));
	return $cast(IntStream, $nc($($StreamSupport::intStream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(IntStream$$Lambda$close$1, this))));
}

$IntStream$Builder* IntStream::builder() {
	$init(IntStream);
	return $new($Streams$IntStreamBuilderImpl);
}

IntStream* IntStream::empty() {
	$init(IntStream);
	return $StreamSupport::intStream($($Spliterators::emptyIntSpliterator()), false);
}

IntStream* IntStream::of(int32_t t) {
	$init(IntStream);
	return $StreamSupport::intStream($as($Spliterator$OfInt, $$new($Streams$IntStreamBuilderImpl, t)), false);
}

IntStream* IntStream::of($ints* values) {
	$init(IntStream);
	return $Arrays::stream(values);
}

IntStream* IntStream::iterate(int32_t seed, $IntUnaryOperator* f) {
	$init(IntStream);
	$Objects::requireNonNull(f);
	$var($Spliterator$OfInt, spliterator, $new($IntStream$1, $Long::MAX_VALUE, ($Spliterator::ORDERED | $Spliterator::IMMUTABLE) | $Spliterator::NONNULL, f, seed));
	return $StreamSupport::intStream(spliterator, false);
}

IntStream* IntStream::iterate(int32_t seed, $IntPredicate* hasNext, $IntUnaryOperator* next) {
	$init(IntStream);
	$Objects::requireNonNull(next);
	$Objects::requireNonNull(hasNext);
	$var($Spliterator$OfInt, spliterator, $new($IntStream$2, $Long::MAX_VALUE, ($Spliterator::ORDERED | $Spliterator::IMMUTABLE) | $Spliterator::NONNULL, next, seed, hasNext));
	return $StreamSupport::intStream(spliterator, false);
}

IntStream* IntStream::generate($IntSupplier* s) {
	$init(IntStream);
	$Objects::requireNonNull(s);
	return $StreamSupport::intStream($as($Spliterator$OfInt, $$new($StreamSpliterators$InfiniteSupplyingSpliterator$OfInt, $Long::MAX_VALUE, s)), false);
}

IntStream* IntStream::range(int32_t startInclusive, int32_t endExclusive) {
	$init(IntStream);
	if (startInclusive >= endExclusive) {
		return empty();
	} else {
		return $StreamSupport::intStream($$new($Streams$RangeIntSpliterator, startInclusive, endExclusive, false), false);
	}
}

IntStream* IntStream::rangeClosed(int32_t startInclusive, int32_t endInclusive) {
	$init(IntStream);
	if (startInclusive > endInclusive) {
		return empty();
	} else {
		return $StreamSupport::intStream($$new($Streams$RangeIntSpliterator, startInclusive, endInclusive, true), false);
	}
}

IntStream* IntStream::concat(IntStream* a, IntStream* b) {
	$init(IntStream);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(a);
	$Objects::requireNonNull(b);
	$var($Spliterator$OfInt, var$0, $cast($Spliterator$OfInt, a->spliterator()));
	$var($Spliterator$OfInt, split, $as($Spliterator$OfInt, $new($Streams$ConcatSpliterator$OfInt, var$0, $($cast($Spliterator$OfInt, b->spliterator())))));
	bool var$1 = a->isParallel();
	$var(IntStream, stream, $StreamSupport::intStream(split, var$1 || b->isParallel()));
	return $cast(IntStream, $nc(stream)->onClose($($Streams::composedClose(a, b))));
}

IntStream* IntStream::lambda$mapMulti$0($IntStream$IntMapMultiConsumer* mapper, int32_t e) {
	$init(IntStream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfInt, buffer, $new($SpinedBuffer$OfInt));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::intStream($($cast($Spliterator$OfInt, buffer->spliterator())), false);
}

$Class* IntStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(IntStream$$Lambda$lambda$mapMulti$0::classInfo$.name)) {
			return IntStream$$Lambda$lambda$mapMulti$0::load$(name, initialize);
		}
		if (name->equals(IntStream$$Lambda$close$1::classInfo$.name)) {
			return IntStream$$Lambda$close$1::load$(name, initialize);
		}
	}
	$loadClass(IntStream, name, initialize, &_IntStream_ClassInfo_, allocate$IntStream);
	return class$;
}

$Class* IntStream::class$ = nullptr;

		} // stream
	} // util
} // java