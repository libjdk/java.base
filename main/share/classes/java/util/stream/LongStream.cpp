#include <java/util/stream/LongStream.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <java/util/LongSummaryStatistics.h>
#include <java/util/Objects.h>
#include <java/util/OptionalDouble.h>
#include <java/util/OptionalLong.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/LongBinaryOperator.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/function/LongFunction.h>
#include <java/util/function/LongPredicate.h>
#include <java/util/function/LongSupplier.h>
#include <java/util/function/LongToDoubleFunction.h>
#include <java/util/function/LongToIntFunction.h>
#include <java/util/function/LongUnaryOperator.h>
#include <java/util/function/ObjLongConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream$1.h>
#include <java/util/stream/LongStream$2.h>
#include <java/util/stream/LongStream$Builder.h>
#include <java/util/stream/LongStream$LongMapMultiConsumer.h>
#include <java/util/stream/SpinedBuffer$OfLong.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSpliterators$InfiniteSupplyingSpliterator$OfLong.h>
#include <java/util/stream/StreamSupport.h>
#include <java/util/stream/Streams$ConcatSpliterator$OfLong.h>
#include <java/util/stream/Streams$LongStreamBuilderImpl.h>
#include <java/util/stream/Streams$RangeLongSpliterator.h>
#include <java/util/stream/Streams.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong$Dropping.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong$Taking.h>
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
using $LongSummaryStatistics = ::java::util::LongSummaryStatistics;
using $Objects = ::java::util::Objects;
using $OptionalDouble = ::java::util::OptionalDouble;
using $OptionalLong = ::java::util::OptionalLong;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Spliterators = ::java::util::Spliterators;
using $BiConsumer = ::java::util::function::BiConsumer;
using $LongBinaryOperator = ::java::util::function::LongBinaryOperator;
using $LongConsumer = ::java::util::function::LongConsumer;
using $LongFunction = ::java::util::function::LongFunction;
using $LongPredicate = ::java::util::function::LongPredicate;
using $LongSupplier = ::java::util::function::LongSupplier;
using $LongToDoubleFunction = ::java::util::function::LongToDoubleFunction;
using $LongToIntFunction = ::java::util::function::LongToIntFunction;
using $LongUnaryOperator = ::java::util::function::LongUnaryOperator;
using $ObjLongConsumer = ::java::util::function::ObjLongConsumer;
using $Supplier = ::java::util::function::Supplier;
using $BaseStream = ::java::util::stream::BaseStream;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream$1 = ::java::util::stream::LongStream$1;
using $LongStream$2 = ::java::util::stream::LongStream$2;
using $LongStream$Builder = ::java::util::stream::LongStream$Builder;
using $LongStream$LongMapMultiConsumer = ::java::util::stream::LongStream$LongMapMultiConsumer;
using $SpinedBuffer$OfLong = ::java::util::stream::SpinedBuffer$OfLong;
using $Stream = ::java::util::stream::Stream;
using $StreamSpliterators$InfiniteSupplyingSpliterator$OfLong = ::java::util::stream::StreamSpliterators$InfiniteSupplyingSpliterator$OfLong;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams = ::java::util::stream::Streams;
using $Streams$ConcatSpliterator$OfLong = ::java::util::stream::Streams$ConcatSpliterator$OfLong;
using $Streams$LongStreamBuilderImpl = ::java::util::stream::Streams$LongStreamBuilderImpl;
using $Streams$RangeLongSpliterator = ::java::util::stream::Streams$RangeLongSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfLong$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong$Dropping;
using $WhileOps$UnorderedWhileSpliterator$OfLong$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong$Taking;

namespace java {
	namespace util {
		namespace stream {

class LongStream$$Lambda$lambda$mapMulti$0 : public $LongFunction {
	$class(LongStream$$Lambda$lambda$mapMulti$0, $NO_CLASS_INIT, $LongFunction)
public:
	void init$($LongStream$LongMapMultiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(int64_t e) override {
		 return $of(LongStream::lambda$mapMulti$0(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongStream$$Lambda$lambda$mapMulti$0>());
	}
	$LongStream$LongMapMultiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LongStream$$Lambda$lambda$mapMulti$0::fieldInfos[2] = {
	{"mapper", "Ljava/util/stream/LongStream$LongMapMultiConsumer;", nullptr, $PUBLIC, $field(LongStream$$Lambda$lambda$mapMulti$0, mapper)},
	{}
};
$MethodInfo LongStream$$Lambda$lambda$mapMulti$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/LongStream$LongMapMultiConsumer;)V", nullptr, $PUBLIC, $method(LongStream$$Lambda$lambda$mapMulti$0, init$, void, $LongStream$LongMapMultiConsumer*)},
	{"apply", "(J)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LongStream$$Lambda$lambda$mapMulti$0, apply, $Object*, int64_t)},
	{}
};
$ClassInfo LongStream$$Lambda$lambda$mapMulti$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongStream$$Lambda$lambda$mapMulti$0",
	"java.lang.Object",
	"java.util.function.LongFunction",
	fieldInfos,
	methodInfos
};
$Class* LongStream$$Lambda$lambda$mapMulti$0::load$($String* name, bool initialize) {
	$loadClass(LongStream$$Lambda$lambda$mapMulti$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongStream$$Lambda$lambda$mapMulti$0::class$ = nullptr;

class LongStream$$Lambda$close$1 : public $Runnable {
	$class(LongStream$$Lambda$close$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$($BaseStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->close();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongStream$$Lambda$close$1>());
	}
	$BaseStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LongStream$$Lambda$close$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LongStream$$Lambda$close$1, inst$)},
	{}
};
$MethodInfo LongStream$$Lambda$close$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/BaseStream;)V", nullptr, $PUBLIC, $method(LongStream$$Lambda$close$1, init$, void, $BaseStream*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(LongStream$$Lambda$close$1, run, void)},
	{}
};
$ClassInfo LongStream$$Lambda$close$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongStream$$Lambda$close$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* LongStream$$Lambda$close$1::load$($String* name, bool initialize) {
	$loadClass(LongStream$$Lambda$close$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongStream$$Lambda$close$1::class$ = nullptr;

$MethodInfo _LongStream_MethodInfo_[] = {
	{"allMatch", "(Ljava/util/function/LongPredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, allMatch, bool, $LongPredicate*)},
	{"anyMatch", "(Ljava/util/function/LongPredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, anyMatch, bool, $LongPredicate*)},
	{"asDoubleStream", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, asDoubleStream, $DoubleStream*)},
	{"average", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, average, $OptionalDouble*)},
	{"boxed", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Long;>;", $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, boxed, $Stream*)},
	{"builder", "()Ljava/util/stream/LongStream$Builder;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, builder, $LongStream$Builder*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/ObjLongConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjLongConsumer<TR;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, collect, $Object*, $Supplier*, $ObjLongConsumer*, $BiConsumer*)},
	{"concat", "(Ljava/util/stream/LongStream;Ljava/util/stream/LongStream;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, concat, LongStream*, LongStream*, LongStream*)},
	{"count", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, count, int64_t)},
	{"distinct", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, distinct, LongStream*)},
	{"dropWhile", "(Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC, $virtualMethod(LongStream, dropWhile, LongStream*, $LongPredicate*)},
	{"empty", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, empty, LongStream*)},
	{"filter", "(Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, filter, LongStream*, $LongPredicate*)},
	{"findAny", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, findAny, $OptionalLong*)},
	{"findFirst", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, findFirst, $OptionalLong*)},
	{"flatMap", "(Ljava/util/function/LongFunction;)Ljava/util/stream/LongStream;", "(Ljava/util/function/LongFunction<+Ljava/util/stream/LongStream;>;)Ljava/util/stream/LongStream;", $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, flatMap, LongStream*, $LongFunction*)},
	{"forEach", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, forEach, void, $LongConsumer*)},
	{"forEachOrdered", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, forEachOrdered, void, $LongConsumer*)},
	{"generate", "(Ljava/util/function/LongSupplier;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, generate, LongStream*, $LongSupplier*)},
	{"iterate", "(JLjava/util/function/LongUnaryOperator;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, iterate, LongStream*, int64_t, $LongUnaryOperator*)},
	{"iterate", "(JLjava/util/function/LongPredicate;Ljava/util/function/LongUnaryOperator;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, iterate, LongStream*, int64_t, $LongPredicate*, $LongUnaryOperator*)},
	{"iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"lambda$mapMulti$0", "(Ljava/util/stream/LongStream$LongMapMultiConsumer;J)Ljava/util/stream/LongStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongStream, lambda$mapMulti$0, LongStream*, $LongStream$LongMapMultiConsumer*, int64_t)},
	{"limit", "(J)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, limit, LongStream*, int64_t)},
	{"map", "(Ljava/util/function/LongUnaryOperator;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, map, LongStream*, $LongUnaryOperator*)},
	{"mapMulti", "(Ljava/util/stream/LongStream$LongMapMultiConsumer;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC, $virtualMethod(LongStream, mapMulti, LongStream*, $LongStream$LongMapMultiConsumer*)},
	{"mapToDouble", "(Ljava/util/function/LongToDoubleFunction;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, mapToDouble, $DoubleStream*, $LongToDoubleFunction*)},
	{"mapToInt", "(Ljava/util/function/LongToIntFunction;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, mapToInt, $IntStream*, $LongToIntFunction*)},
	{"mapToObj", "(Ljava/util/function/LongFunction;)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/LongFunction<+TU;>;)Ljava/util/stream/Stream<TU;>;", $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, mapToObj, $Stream*, $LongFunction*)},
	{"max", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, max, $OptionalLong*)},
	{"min", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, min, $OptionalLong*)},
	{"noneMatch", "(Ljava/util/function/LongPredicate;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, noneMatch, bool, $LongPredicate*)},
	{"of", "(J)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, of, LongStream*, int64_t)},
	{"of", "([J)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(LongStream, of, LongStream*, $longs*)},
	{"parallel", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT},
	{"peek", "(Ljava/util/function/LongConsumer;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, peek, LongStream*, $LongConsumer*)},
	{"range", "(JJ)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, range, LongStream*, int64_t, int64_t)},
	{"rangeClosed", "(JJ)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(LongStream, rangeClosed, LongStream*, int64_t, int64_t)},
	{"reduce", "(JLjava/util/function/LongBinaryOperator;)J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, reduce, int64_t, int64_t, $LongBinaryOperator*)},
	{"reduce", "(Ljava/util/function/LongBinaryOperator;)Ljava/util/OptionalLong;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, reduce, $OptionalLong*, $LongBinaryOperator*)},
	{"sequential", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT},
	{"skip", "(J)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, skip, LongStream*, int64_t)},
	{"sorted", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, sorted, LongStream*)},
	{"spliterator", "()Ljava/util/Spliterator;", nullptr, $PUBLIC | $ABSTRACT},
	{"sum", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, sum, int64_t)},
	{"summaryStatistics", "()Ljava/util/LongSummaryStatistics;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, summaryStatistics, $LongSummaryStatistics*)},
	{"takeWhile", "(Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC, $virtualMethod(LongStream, takeWhile, LongStream*, $LongPredicate*)},
	{"toArray", "()[J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(LongStream, toArray, $longs*)},
	{}
};

$InnerClassInfo _LongStream_InnerClassesInfo_[] = {
	{"java.util.stream.LongStream$LongMapMultiConsumer", "java.util.stream.LongStream", "LongMapMultiConsumer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.LongStream$Builder", "java.util.stream.LongStream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.LongStream$2", nullptr, nullptr, 0},
	{"java.util.stream.LongStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongStream_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.stream.LongStream",
	nullptr,
	"java.util.stream.BaseStream",
	nullptr,
	_LongStream_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/stream/BaseStream<Ljava/lang/Long;Ljava/util/stream/LongStream;>;",
	nullptr,
	_LongStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.LongStream$LongMapMultiConsumer,java.util.stream.LongStream$Builder,java.util.stream.LongStream$2,java.util.stream.LongStream$1"
};

$Object* allocate$LongStream($Class* clazz) {
	return $of($alloc(LongStream));
}

LongStream* LongStream::mapMulti($LongStream$LongMapMultiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMap(static_cast<$LongFunction*>($$new(LongStream$$Lambda$lambda$mapMulti$0, mapper)));
}

LongStream* LongStream::takeWhile($LongPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator$OfLong, var$0, $as($Spliterator$OfLong, $new($WhileOps$UnorderedWhileSpliterator$OfLong$Taking, $($cast($Spliterator$OfLong, spliterator())), true, predicate)));
	return $cast(LongStream, $nc($($StreamSupport::longStream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(LongStream$$Lambda$close$1, this))));
}

LongStream* LongStream::dropWhile($LongPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator$OfLong, var$0, $as($Spliterator$OfLong, $new($WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, $($cast($Spliterator$OfLong, spliterator())), true, predicate)));
	return $cast(LongStream, $nc($($StreamSupport::longStream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(LongStream$$Lambda$close$1, this))));
}

$LongStream$Builder* LongStream::builder() {
	$init(LongStream);
	return $new($Streams$LongStreamBuilderImpl);
}

LongStream* LongStream::empty() {
	$init(LongStream);
	return $StreamSupport::longStream($($Spliterators::emptyLongSpliterator()), false);
}

LongStream* LongStream::of(int64_t t) {
	$init(LongStream);
	return $StreamSupport::longStream($as($Spliterator$OfLong, $$new($Streams$LongStreamBuilderImpl, t)), false);
}

LongStream* LongStream::of($longs* values) {
	$init(LongStream);
	return $Arrays::stream(values);
}

LongStream* LongStream::iterate(int64_t seed, $LongUnaryOperator* f) {
	$init(LongStream);
	$Objects::requireNonNull(f);
	$var($Spliterator$OfLong, spliterator, $new($LongStream$1, $Long::MAX_VALUE, ($Spliterator::ORDERED | $Spliterator::IMMUTABLE) | $Spliterator::NONNULL, f, seed));
	return $StreamSupport::longStream(spliterator, false);
}

LongStream* LongStream::iterate(int64_t seed, $LongPredicate* hasNext, $LongUnaryOperator* next) {
	$init(LongStream);
	$Objects::requireNonNull(next);
	$Objects::requireNonNull(hasNext);
	$var($Spliterator$OfLong, spliterator, $new($LongStream$2, $Long::MAX_VALUE, ($Spliterator::ORDERED | $Spliterator::IMMUTABLE) | $Spliterator::NONNULL, next, seed, hasNext));
	return $StreamSupport::longStream(spliterator, false);
}

LongStream* LongStream::generate($LongSupplier* s) {
	$init(LongStream);
	$Objects::requireNonNull(s);
	return $StreamSupport::longStream($as($Spliterator$OfLong, $$new($StreamSpliterators$InfiniteSupplyingSpliterator$OfLong, $Long::MAX_VALUE, s)), false);
}

LongStream* LongStream::range(int64_t startInclusive, int64_t endExclusive) {
	$init(LongStream);
	$useLocalCurrentObjectStackCache();
	if (startInclusive >= endExclusive) {
		return empty();
	} else if (endExclusive - startInclusive < 0) {
		int64_t m = startInclusive + $Long::divideUnsigned(endExclusive - startInclusive, 2) + 1;
		$var(LongStream, var$0, range(startInclusive, m));
		return concat(var$0, $(range(m, endExclusive)));
	} else {
		return $StreamSupport::longStream($$new($Streams$RangeLongSpliterator, startInclusive, endExclusive, false), false);
	}
}

LongStream* LongStream::rangeClosed(int64_t startInclusive, int64_t endInclusive) {
	$init(LongStream);
	$useLocalCurrentObjectStackCache();
	if (startInclusive > endInclusive) {
		return empty();
	} else if (endInclusive - startInclusive + 1 <= 0) {
		int64_t m = startInclusive + $Long::divideUnsigned(endInclusive - startInclusive, 2) + 1;
		$var(LongStream, var$0, range(startInclusive, m));
		return concat(var$0, $(rangeClosed(m, endInclusive)));
	} else {
		return $StreamSupport::longStream($$new($Streams$RangeLongSpliterator, startInclusive, endInclusive, true), false);
	}
}

LongStream* LongStream::concat(LongStream* a, LongStream* b) {
	$init(LongStream);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(a);
	$Objects::requireNonNull(b);
	$var($Spliterator$OfLong, var$0, $cast($Spliterator$OfLong, a->spliterator()));
	$var($Spliterator$OfLong, split, $as($Spliterator$OfLong, $new($Streams$ConcatSpliterator$OfLong, var$0, $($cast($Spliterator$OfLong, b->spliterator())))));
	bool var$1 = a->isParallel();
	$var(LongStream, stream, $StreamSupport::longStream(split, var$1 || b->isParallel()));
	return $cast(LongStream, $nc(stream)->onClose($($Streams::composedClose(a, b))));
}

LongStream* LongStream::lambda$mapMulti$0($LongStream$LongMapMultiConsumer* mapper, int64_t e) {
	$init(LongStream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfLong, buffer, $new($SpinedBuffer$OfLong));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::longStream($($cast($Spliterator$OfLong, buffer->spliterator())), false);
}

$Class* LongStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LongStream$$Lambda$lambda$mapMulti$0::classInfo$.name)) {
			return LongStream$$Lambda$lambda$mapMulti$0::load$(name, initialize);
		}
		if (name->equals(LongStream$$Lambda$close$1::classInfo$.name)) {
			return LongStream$$Lambda$close$1::load$(name, initialize);
		}
	}
	$loadClass(LongStream, name, initialize, &_LongStream_ClassInfo_, allocate$LongStream);
	return class$;
}

$Class* LongStream::class$ = nullptr;

		} // stream
	} // util
} // java