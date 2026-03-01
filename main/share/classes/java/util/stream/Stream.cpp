#include <java/util/stream/Stream.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/function/ToDoubleFunction.h>
#include <java/util/function/ToIntFunction.h>
#include <java/util/function/ToLongFunction.h>
#include <java/util/function/UnaryOperator.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/SpinedBuffer$OfDouble.h>
#include <java/util/stream/SpinedBuffer$OfInt.h>
#include <java/util/stream/SpinedBuffer$OfLong.h>
#include <java/util/stream/SpinedBuffer.h>
#include <java/util/stream/Stream$1.h>
#include <java/util/stream/Stream$2.h>
#include <java/util/stream/Stream$Builder.h>
#include <java/util/stream/StreamSpliterators$InfiniteSupplyingSpliterator$OfRef.h>
#include <java/util/stream/StreamSupport.h>
#include <java/util/stream/Streams$ConcatSpliterator$OfRef.h>
#include <java/util/stream/Streams$StreamBuilderImpl.h>
#include <java/util/stream/Streams.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Dropping.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Taking.h>
#include <jcpp.h>

#undef IMMUTABLE
#undef MAX_VALUE
#undef ORDERED

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Spliterators = ::java::util::Spliterators;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $ToDoubleFunction = ::java::util::function::ToDoubleFunction;
using $ToIntFunction = ::java::util::function::ToIntFunction;
using $ToLongFunction = ::java::util::function::ToLongFunction;
using $UnaryOperator = ::java::util::function::UnaryOperator;
using $BaseStream = ::java::util::stream::BaseStream;
using $Collector = ::java::util::stream::Collector;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $SpinedBuffer = ::java::util::stream::SpinedBuffer;
using $SpinedBuffer$OfDouble = ::java::util::stream::SpinedBuffer$OfDouble;
using $SpinedBuffer$OfInt = ::java::util::stream::SpinedBuffer$OfInt;
using $SpinedBuffer$OfLong = ::java::util::stream::SpinedBuffer$OfLong;
using $Stream$1 = ::java::util::stream::Stream$1;
using $Stream$2 = ::java::util::stream::Stream$2;
using $Stream$Builder = ::java::util::stream::Stream$Builder;
using $StreamSpliterators$InfiniteSupplyingSpliterator$OfRef = ::java::util::stream::StreamSpliterators$InfiniteSupplyingSpliterator$OfRef;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $Streams = ::java::util::stream::Streams;
using $Streams$ConcatSpliterator$OfRef = ::java::util::stream::Streams$ConcatSpliterator$OfRef;
using $Streams$StreamBuilderImpl = ::java::util::stream::Streams$StreamBuilderImpl;
using $WhileOps$UnorderedWhileSpliterator$OfRef$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfRef$Dropping;
using $WhileOps$UnorderedWhileSpliterator$OfRef$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfRef$Taking;

namespace java {
	namespace util {
		namespace stream {

class Stream$$Lambda$lambda$mapMulti$0 : public $Function {
	$class(Stream$$Lambda$lambda$mapMulti$0, $NO_CLASS_INIT, $Function)
public:
	void init$($BiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(Stream::lambda$mapMulti$0(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$mapMulti$0>());
	}
	$BiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$mapMulti$0::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$mapMulti$0, mapper)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$mapMulti$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Stream$$Lambda$lambda$mapMulti$0, init$, void, $BiConsumer*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Stream$$Lambda$lambda$mapMulti$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Stream$$Lambda$lambda$mapMulti$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Stream$$Lambda$lambda$mapMulti$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$mapMulti$0::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$mapMulti$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$mapMulti$0::class$ = nullptr;

class Stream$$Lambda$lambda$mapMultiToInt$1$1 : public $Function {
	$class(Stream$$Lambda$lambda$mapMultiToInt$1$1, $NO_CLASS_INIT, $Function)
public:
	void init$($BiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(Stream::lambda$mapMultiToInt$1(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$mapMultiToInt$1$1>());
	}
	$BiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$mapMultiToInt$1$1::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$mapMultiToInt$1$1, mapper)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$mapMultiToInt$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Stream$$Lambda$lambda$mapMultiToInt$1$1, init$, void, $BiConsumer*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Stream$$Lambda$lambda$mapMultiToInt$1$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Stream$$Lambda$lambda$mapMultiToInt$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Stream$$Lambda$lambda$mapMultiToInt$1$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$mapMultiToInt$1$1::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$mapMultiToInt$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$mapMultiToInt$1$1::class$ = nullptr;

class Stream$$Lambda$lambda$mapMultiToLong$2$2 : public $Function {
	$class(Stream$$Lambda$lambda$mapMultiToLong$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$($BiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(Stream::lambda$mapMultiToLong$2(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$mapMultiToLong$2$2>());
	}
	$BiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$mapMultiToLong$2$2::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$mapMultiToLong$2$2, mapper)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$mapMultiToLong$2$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Stream$$Lambda$lambda$mapMultiToLong$2$2, init$, void, $BiConsumer*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Stream$$Lambda$lambda$mapMultiToLong$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Stream$$Lambda$lambda$mapMultiToLong$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Stream$$Lambda$lambda$mapMultiToLong$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$mapMultiToLong$2$2::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$mapMultiToLong$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$mapMultiToLong$2$2::class$ = nullptr;

class Stream$$Lambda$lambda$mapMultiToDouble$3$3 : public $Function {
	$class(Stream$$Lambda$lambda$mapMultiToDouble$3$3, $NO_CLASS_INIT, $Function)
public:
	void init$($BiConsumer* mapper) {
		$set(this, mapper, mapper);
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(Stream::lambda$mapMultiToDouble$3(mapper, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$mapMultiToDouble$3$3>());
	}
	$BiConsumer* mapper = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$mapMultiToDouble$3$3::fieldInfos[2] = {
	{"mapper", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$mapMultiToDouble$3$3, mapper)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$mapMultiToDouble$3$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(Stream$$Lambda$lambda$mapMultiToDouble$3$3, init$, void, $BiConsumer*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Stream$$Lambda$lambda$mapMultiToDouble$3$3, apply, $Object*, Object$*)},
	{}
};
$ClassInfo Stream$$Lambda$lambda$mapMultiToDouble$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Stream$$Lambda$lambda$mapMultiToDouble$3$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$mapMultiToDouble$3$3::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$mapMultiToDouble$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$mapMultiToDouble$3$3::class$ = nullptr;

class Stream$$Lambda$close$4 : public $Runnable {
	$class(Stream$$Lambda$close$4, $NO_CLASS_INIT, $Runnable)
public:
	void init$($BaseStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->close();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$close$4>());
	}
	$BaseStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$close$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$close$4, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$close$4::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/BaseStream;)V", nullptr, $PUBLIC, $method(Stream$$Lambda$close$4, init$, void, $BaseStream*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Stream$$Lambda$close$4, run, void)},
	{}
};
$ClassInfo Stream$$Lambda$close$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.Stream$$Lambda$close$4",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$close$4::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$close$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$close$4::class$ = nullptr;

$CompoundAttribute _Stream_MethodAnnotations_of39[] = {
	{"Ljava/lang/SafeVarargs;", nullptr},
	{}
};

$MethodInfo _Stream_MethodInfo_[] = {
	{"allMatch", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TT;>;)Z", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, allMatch, bool, $Predicate*)},
	{"anyMatch", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TT;>;)Z", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, anyMatch, bool, $Predicate*)},
	{"builder", "()Ljava/util/stream/Stream$Builder;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Stream$Builder<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, builder, $Stream$Builder*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/BiConsumer<TR;-TT;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, collect, $Object*, $Supplier*, $BiConsumer*, $BiConsumer*)},
	{"collect", "(Ljava/util/stream/Collector;)Ljava/lang/Object;", "<R:Ljava/lang/Object;A:Ljava/lang/Object;>(Ljava/util/stream/Collector<-TT;TA;TR;>;)TR;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, collect, $Object*, $Collector*)},
	{"concat", "(Ljava/util/stream/Stream;Ljava/util/stream/Stream;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/stream/Stream<+TT;>;Ljava/util/stream/Stream<+TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, concat, Stream*, Stream*, Stream*)},
	{"count", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Stream, count, int64_t)},
	{"distinct", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, distinct, Stream*)},
	{"dropWhile", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "(Ljava/util/function/Predicate<-TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC, $virtualMethod(Stream, dropWhile, Stream*, $Predicate*)},
	{"empty", "()Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>()Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, empty, Stream*)},
	{"filter", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "(Ljava/util/function/Predicate<-TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, filter, Stream*, $Predicate*)},
	{"findAny", "()Ljava/util/Optional;", "()Ljava/util/Optional<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, findAny, $Optional*)},
	{"findFirst", "()Ljava/util/Optional;", "()Ljava/util/Optional<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, findFirst, $Optional*)},
	{"flatMap", "(Ljava/util/function/Function;)Ljava/util/stream/Stream;", "<R:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+Ljava/util/stream/Stream<+TR;>;>;)Ljava/util/stream/Stream<TR;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, flatMap, Stream*, $Function*)},
	{"flatMapToDouble", "(Ljava/util/function/Function;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/Function<-TT;+Ljava/util/stream/DoubleStream;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, flatMapToDouble, $DoubleStream*, $Function*)},
	{"flatMapToInt", "(Ljava/util/function/Function;)Ljava/util/stream/IntStream;", "(Ljava/util/function/Function<-TT;+Ljava/util/stream/IntStream;>;)Ljava/util/stream/IntStream;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, flatMapToInt, $IntStream*, $Function*)},
	{"flatMapToLong", "(Ljava/util/function/Function;)Ljava/util/stream/LongStream;", "(Ljava/util/function/Function<-TT;+Ljava/util/stream/LongStream;>;)Ljava/util/stream/LongStream;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, flatMapToLong, $LongStream*, $Function*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TT;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, forEach, void, $Consumer*)},
	{"forEachOrdered", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TT;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, forEachOrdered, void, $Consumer*)},
	{"generate", "(Ljava/util/function/Supplier;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/function/Supplier<+TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, generate, Stream*, $Supplier*)},
	{"iterate", "(Ljava/lang/Object;Ljava/util/function/UnaryOperator;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(TT;Ljava/util/function/UnaryOperator<TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, iterate, Stream*, Object$*, $UnaryOperator*)},
	{"iterate", "(Ljava/lang/Object;Ljava/util/function/Predicate;Ljava/util/function/UnaryOperator;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(TT;Ljava/util/function/Predicate<-TT;>;Ljava/util/function/UnaryOperator<TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, iterate, Stream*, Object$*, $Predicate*, $UnaryOperator*)},
	{"lambda$mapMulti$0", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Stream, lambda$mapMulti$0, Stream*, $BiConsumer*, Object$*)},
	{"lambda$mapMultiToDouble$3", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;)Ljava/util/stream/DoubleStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Stream, lambda$mapMultiToDouble$3, $DoubleStream*, $BiConsumer*, Object$*)},
	{"lambda$mapMultiToInt$1", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;)Ljava/util/stream/IntStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Stream, lambda$mapMultiToInt$1, $IntStream*, $BiConsumer*, Object$*)},
	{"lambda$mapMultiToLong$2", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;)Ljava/util/stream/LongStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Stream, lambda$mapMultiToLong$2, $LongStream*, $BiConsumer*, Object$*)},
	{"limit", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, limit, Stream*, int64_t)},
	{"map", "(Ljava/util/function/Function;)Ljava/util/stream/Stream;", "<R:Ljava/lang/Object;>(Ljava/util/function/Function<-TT;+TR;>;)Ljava/util/stream/Stream<TR;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, map, Stream*, $Function*)},
	{"mapMulti", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/Stream;", "<R:Ljava/lang/Object;>(Ljava/util/function/BiConsumer<-TT;-Ljava/util/function/Consumer<TR;>;>;)Ljava/util/stream/Stream<TR;>;", $PUBLIC, $virtualMethod(Stream, mapMulti, Stream*, $BiConsumer*)},
	{"mapMultiToDouble", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/BiConsumer<-TT;-Ljava/util/function/DoubleConsumer;>;)Ljava/util/stream/DoubleStream;", $PUBLIC, $virtualMethod(Stream, mapMultiToDouble, $DoubleStream*, $BiConsumer*)},
	{"mapMultiToInt", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/IntStream;", "(Ljava/util/function/BiConsumer<-TT;-Ljava/util/function/IntConsumer;>;)Ljava/util/stream/IntStream;", $PUBLIC, $virtualMethod(Stream, mapMultiToInt, $IntStream*, $BiConsumer*)},
	{"mapMultiToLong", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/LongStream;", "(Ljava/util/function/BiConsumer<-TT;-Ljava/util/function/LongConsumer;>;)Ljava/util/stream/LongStream;", $PUBLIC, $virtualMethod(Stream, mapMultiToLong, $LongStream*, $BiConsumer*)},
	{"mapToDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/ToDoubleFunction<-TT;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, mapToDouble, $DoubleStream*, $ToDoubleFunction*)},
	{"mapToInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/stream/IntStream;", "(Ljava/util/function/ToIntFunction<-TT;>;)Ljava/util/stream/IntStream;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, mapToInt, $IntStream*, $ToIntFunction*)},
	{"mapToLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/stream/LongStream;", "(Ljava/util/function/ToLongFunction<-TT;>;)Ljava/util/stream/LongStream;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, mapToLong, $LongStream*, $ToLongFunction*)},
	{"max", "(Ljava/util/Comparator;)Ljava/util/Optional;", "(Ljava/util/Comparator<-TT;>;)Ljava/util/Optional<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, max, $Optional*, $Comparator*)},
	{"min", "(Ljava/util/Comparator;)Ljava/util/Optional;", "(Ljava/util/Comparator<-TT;>;)Ljava/util/Optional<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, min, $Optional*, $Comparator*)},
	{"noneMatch", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TT;>;)Z", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, noneMatch, bool, $Predicate*)},
	{"of", "(Ljava/lang/Object;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(TT;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, of, Stream*, Object$*)},
	{"of", "([Ljava/lang/Object;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>([TT;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Stream, of, Stream*, $ObjectArray*), nullptr, nullptr, _Stream_MethodAnnotations_of39},
	{"ofNullable", "(Ljava/lang/Object;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(TT;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(Stream, ofNullable, Stream*, Object$*)},
	{"peek", "(Ljava/util/function/Consumer;)Ljava/util/stream/Stream;", "(Ljava/util/function/Consumer<-TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, peek, Stream*, $Consumer*)},
	{"reduce", "(Ljava/lang/Object;Ljava/util/function/BinaryOperator;)Ljava/lang/Object;", "(TT;Ljava/util/function/BinaryOperator<TT;>;)TT;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, reduce, $Object*, Object$*, $BinaryOperator*)},
	{"reduce", "(Ljava/util/function/BinaryOperator;)Ljava/util/Optional;", "(Ljava/util/function/BinaryOperator<TT;>;)Ljava/util/Optional<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, reduce, $Optional*, $BinaryOperator*)},
	{"reduce", "(Ljava/lang/Object;Ljava/util/function/BiFunction;Ljava/util/function/BinaryOperator;)Ljava/lang/Object;", "<U:Ljava/lang/Object;>(TU;Ljava/util/function/BiFunction<TU;-TT;TU;>;Ljava/util/function/BinaryOperator<TU;>;)TU;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, reduce, $Object*, Object$*, $BiFunction*, $BinaryOperator*)},
	{"skip", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, skip, Stream*, int64_t)},
	{"sorted", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, sorted, Stream*)},
	{"sorted", "(Ljava/util/Comparator;)Ljava/util/stream/Stream;", "(Ljava/util/Comparator<-TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, sorted, Stream*, $Comparator*)},
	{"takeWhile", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "(Ljava/util/function/Predicate<-TT;>;)Ljava/util/stream/Stream<TT;>;", $PUBLIC, $virtualMethod(Stream, takeWhile, Stream*, $Predicate*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Stream, toArray, $ObjectArray*)},
	{"toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", "<A:Ljava/lang/Object;>(Ljava/util/function/IntFunction<[TA;>;)[TA;", $PUBLIC | $ABSTRACT, $virtualMethod(Stream, toArray, $ObjectArray*, $IntFunction*)},
	{"toList", "()Ljava/util/List;", "()Ljava/util/List<TT;>;", $PUBLIC, $virtualMethod(Stream, toList, $List*)},
	{}
};

$InnerClassInfo _Stream_InnerClassesInfo_[] = {
	{"java.util.stream.Stream$Builder", "java.util.stream.Stream", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.Stream$2", nullptr, nullptr, 0},
	{"java.util.stream.Stream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Stream_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.stream.Stream",
	nullptr,
	"java.util.stream.BaseStream",
	nullptr,
	_Stream_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/stream/BaseStream<TT;Ljava/util/stream/Stream<TT;>;>;",
	nullptr,
	_Stream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.Stream$Builder,java.util.stream.Stream$2,java.util.stream.Stream$1"
};

$Object* allocate$Stream($Class* clazz) {
	return $of($alloc(Stream));
}

Stream* Stream::mapMulti($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMap(static_cast<$Function*>($$new(Stream$$Lambda$lambda$mapMulti$0, mapper)));
}

$IntStream* Stream::mapMultiToInt($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMapToInt(static_cast<$Function*>($$new(Stream$$Lambda$lambda$mapMultiToInt$1$1, mapper)));
}

$LongStream* Stream::mapMultiToLong($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMapToLong(static_cast<$Function*>($$new(Stream$$Lambda$lambda$mapMultiToLong$2$2, mapper)));
}

$DoubleStream* Stream::mapMultiToDouble($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	return flatMapToDouble(static_cast<$Function*>($$new(Stream$$Lambda$lambda$mapMultiToDouble$3$3, mapper)));
}

Stream* Stream::takeWhile($Predicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator, var$0, static_cast<$Spliterator*>($new($WhileOps$UnorderedWhileSpliterator$OfRef$Taking, $(spliterator()), true, predicate)));
	return $cast(Stream, $nc($($StreamSupport::stream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(Stream$$Lambda$close$4, this))));
}

Stream* Stream::dropWhile($Predicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(predicate);
	$var($Spliterator, var$0, static_cast<$Spliterator*>($new($WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, $(spliterator()), true, predicate)));
	return $cast(Stream, $nc($($StreamSupport::stream(var$0, isParallel())))->onClose(static_cast<$Runnable*>($$new(Stream$$Lambda$close$4, this))));
}

$List* Stream::toList() {
	$useLocalCurrentObjectStackCache();
	return $Collections::unmodifiableList($$new($ArrayList, $(static_cast<$Collection*>($Arrays::asList($(this->toArray()))))));
}

$Stream$Builder* Stream::builder() {
	$init(Stream);
	return $new($Streams$StreamBuilderImpl);
}

Stream* Stream::empty() {
	$init(Stream);
	return $StreamSupport::stream($($Spliterators::emptySpliterator()), false);
}

Stream* Stream::of(Object$* t) {
	$init(Stream);
	return $StreamSupport::stream($$new($Streams$StreamBuilderImpl, t), false);
}

Stream* Stream::ofNullable(Object$* t) {
	$init(Stream);
	return t == nullptr ? Stream::empty() : $StreamSupport::stream($$new($Streams$StreamBuilderImpl, t), false);
}

Stream* Stream::of($ObjectArray* values) {
	$init(Stream);
	return $Arrays::stream(values);
}

Stream* Stream::iterate(Object$* seed, $UnaryOperator* f) {
	$init(Stream);
	$Objects::requireNonNull(f);
	$var($Spliterator, spliterator, $new($Stream$1, $Long::MAX_VALUE, $Spliterator::ORDERED | $Spliterator::IMMUTABLE, f, seed));
	return $StreamSupport::stream(spliterator, false);
}

Stream* Stream::iterate(Object$* seed, $Predicate* hasNext, $UnaryOperator* next) {
	$init(Stream);
	$Objects::requireNonNull(next);
	$Objects::requireNonNull(hasNext);
	$var($Spliterator, spliterator, $new($Stream$2, $Long::MAX_VALUE, $Spliterator::ORDERED | $Spliterator::IMMUTABLE, next, seed, hasNext));
	return $StreamSupport::stream(spliterator, false);
}

Stream* Stream::generate($Supplier* s) {
	$init(Stream);
	$Objects::requireNonNull(s);
	return $StreamSupport::stream($$new($StreamSpliterators$InfiniteSupplyingSpliterator$OfRef, $Long::MAX_VALUE, s), false);
}

Stream* Stream::concat(Stream* a, Stream* b) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(a);
	$Objects::requireNonNull(b);
	$var($Spliterator, var$0, a->spliterator());
	$var($Spliterator, split, $new($Streams$ConcatSpliterator$OfRef, var$0, $(b->spliterator())));
	bool var$1 = a->isParallel();
	$var(Stream, stream, $StreamSupport::stream(split, var$1 || b->isParallel()));
	return $cast(Stream, $nc(stream)->onClose($($Streams::composedClose(a, b))));
}

$DoubleStream* Stream::lambda$mapMultiToDouble$3($BiConsumer* mapper, Object$* e) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfDouble, buffer, $new($SpinedBuffer$OfDouble));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::doubleStream($($cast($Spliterator$OfDouble, buffer->spliterator())), false);
}

$LongStream* Stream::lambda$mapMultiToLong$2($BiConsumer* mapper, Object$* e) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfLong, buffer, $new($SpinedBuffer$OfLong));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::longStream($($cast($Spliterator$OfLong, buffer->spliterator())), false);
}

$IntStream* Stream::lambda$mapMultiToInt$1($BiConsumer* mapper, Object$* e) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer$OfInt, buffer, $new($SpinedBuffer$OfInt));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::intStream($($cast($Spliterator$OfInt, buffer->spliterator())), false);
}

Stream* Stream::lambda$mapMulti$0($BiConsumer* mapper, Object$* e) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$var($SpinedBuffer, buffer, $new($SpinedBuffer));
	$nc(mapper)->accept(e, buffer);
	return $StreamSupport::stream($(buffer->spliterator()), false);
}

$Class* Stream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Stream$$Lambda$lambda$mapMulti$0::classInfo$.name)) {
			return Stream$$Lambda$lambda$mapMulti$0::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$mapMultiToInt$1$1::classInfo$.name)) {
			return Stream$$Lambda$lambda$mapMultiToInt$1$1::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$mapMultiToLong$2$2::classInfo$.name)) {
			return Stream$$Lambda$lambda$mapMultiToLong$2$2::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$mapMultiToDouble$3$3::classInfo$.name)) {
			return Stream$$Lambda$lambda$mapMultiToDouble$3$3::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$close$4::classInfo$.name)) {
			return Stream$$Lambda$close$4::load$(name, initialize);
		}
	}
	$loadClass(Stream, name, initialize, &_Stream_ClassInfo_, allocate$Stream);
	return class$;
}

$Class* Stream::class$ = nullptr;

		} // stream
	} // util
} // java