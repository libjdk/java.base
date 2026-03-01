#include <java/util/stream/ReferencePipeline.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
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
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/Collector$Characteristics.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/DistinctOps.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/FindOps.h>
#include <java/util/stream/ForEachOps.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/MatchOps$MatchKind.h>
#include <java/util/stream/MatchOps.h>
#include <java/util/stream/Node$Builder.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReduceOps.h>
#include <java/util/stream/ReferencePipeline$1.h>
#include <java/util/stream/ReferencePipeline$10.h>
#include <java/util/stream/ReferencePipeline$11.h>
#include <java/util/stream/ReferencePipeline$12.h>
#include <java/util/stream/ReferencePipeline$13.h>
#include <java/util/stream/ReferencePipeline$14.h>
#include <java/util/stream/ReferencePipeline$15.h>
#include <java/util/stream/ReferencePipeline$2.h>
#include <java/util/stream/ReferencePipeline$3.h>
#include <java/util/stream/ReferencePipeline$4.h>
#include <java/util/stream/ReferencePipeline$5.h>
#include <java/util/stream/ReferencePipeline$6.h>
#include <java/util/stream/ReferencePipeline$7.h>
#include <java/util/stream/ReferencePipeline$8.h>
#include <java/util/stream/ReferencePipeline$9.h>
#include <java/util/stream/ReferencePipeline$StatelessOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SliceOps.h>
#include <java/util/stream/SortedOps.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator.h>
#include <java/util/stream/StreamSpliterators$WrappingSpliterator.h>
#include <java/util/stream/TerminalOp.h>
#include <java/util/stream/WhileOps.h>
#include <jdk/internal/access/JavaUtilCollectionAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef ALL
#undef ANY
#undef CONCURRENT
#undef IDENTITY_FINISH
#undef NONE
#undef NOT_DISTINCT
#undef NOT_ORDERED
#undef NOT_SIZED
#undef NOT_SORTED
#undef REFERENCE
#undef UNORDERED

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Spliterator = ::java::util::Spliterator;
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
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $BaseStream = ::java::util::stream::BaseStream;
using $Collector = ::java::util::stream::Collector;
using $Collector$Characteristics = ::java::util::stream::Collector$Characteristics;
using $DistinctOps = ::java::util::stream::DistinctOps;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $FindOps = ::java::util::stream::FindOps;
using $ForEachOps = ::java::util::stream::ForEachOps;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $MatchOps = ::java::util::stream::MatchOps;
using $MatchOps$MatchKind = ::java::util::stream::MatchOps$MatchKind;
using $Node = ::java::util::stream::Node;
using $Node$Builder = ::java::util::stream::Node$Builder;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReduceOps = ::java::util::stream::ReduceOps;
using $ReferencePipeline$1 = ::java::util::stream::ReferencePipeline$1;
using $ReferencePipeline$10 = ::java::util::stream::ReferencePipeline$10;
using $ReferencePipeline$11 = ::java::util::stream::ReferencePipeline$11;
using $ReferencePipeline$12 = ::java::util::stream::ReferencePipeline$12;
using $ReferencePipeline$13 = ::java::util::stream::ReferencePipeline$13;
using $ReferencePipeline$14 = ::java::util::stream::ReferencePipeline$14;
using $ReferencePipeline$15 = ::java::util::stream::ReferencePipeline$15;
using $ReferencePipeline$2 = ::java::util::stream::ReferencePipeline$2;
using $ReferencePipeline$3 = ::java::util::stream::ReferencePipeline$3;
using $ReferencePipeline$4 = ::java::util::stream::ReferencePipeline$4;
using $ReferencePipeline$5 = ::java::util::stream::ReferencePipeline$5;
using $ReferencePipeline$6 = ::java::util::stream::ReferencePipeline$6;
using $ReferencePipeline$7 = ::java::util::stream::ReferencePipeline$7;
using $ReferencePipeline$8 = ::java::util::stream::ReferencePipeline$8;
using $ReferencePipeline$9 = ::java::util::stream::ReferencePipeline$9;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $SliceOps = ::java::util::stream::SliceOps;
using $SortedOps = ::java::util::stream::SortedOps;
using $Stream = ::java::util::stream::Stream;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $StreamSpliterators$DelegatingSpliterator = ::java::util::stream::StreamSpliterators$DelegatingSpliterator;
using $StreamSpliterators$WrappingSpliterator = ::java::util::stream::StreamSpliterators$WrappingSpliterator;
using $WhileOps = ::java::util::stream::WhileOps;
using $JavaUtilCollectionAccess = ::jdk::internal::access::JavaUtilCollectionAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {
		namespace stream {

class ReferencePipeline$$Lambda$lambda$toArray$0 : public $IntFunction {
	$class(ReferencePipeline$$Lambda$lambda$toArray$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(ReferencePipeline::lambda$toArray$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReferencePipeline$$Lambda$lambda$toArray$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReferencePipeline$$Lambda$lambda$toArray$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ReferencePipeline$$Lambda$lambda$toArray$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ReferencePipeline$$Lambda$lambda$toArray$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo ReferencePipeline$$Lambda$lambda$toArray$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.ReferencePipeline$$Lambda$lambda$toArray$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* ReferencePipeline$$Lambda$lambda$toArray$0::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$$Lambda$lambda$toArray$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReferencePipeline$$Lambda$lambda$toArray$0::class$ = nullptr;

class ReferencePipeline$$Lambda$lambda$collect$1$1 : public $Consumer {
	$class(ReferencePipeline$$Lambda$lambda$collect$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($BiConsumer* accumulator, Object$* container) {
		$set(this, accumulator, accumulator);
		$set(this, container, container);
	}
	virtual void accept(Object$* u) override {
		ReferencePipeline::lambda$collect$1(accumulator, container, u);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReferencePipeline$$Lambda$lambda$collect$1$1>());
	}
	$BiConsumer* accumulator = nullptr;
	$Object* container = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ReferencePipeline$$Lambda$lambda$collect$1$1::fieldInfos[3] = {
	{"accumulator", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(ReferencePipeline$$Lambda$lambda$collect$1$1, accumulator)},
	{"container", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ReferencePipeline$$Lambda$lambda$collect$1$1, container)},
	{}
};
$MethodInfo ReferencePipeline$$Lambda$lambda$collect$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(ReferencePipeline$$Lambda$lambda$collect$1$1, init$, void, $BiConsumer*, Object$*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ReferencePipeline$$Lambda$lambda$collect$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo ReferencePipeline$$Lambda$lambda$collect$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.ReferencePipeline$$Lambda$lambda$collect$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ReferencePipeline$$Lambda$lambda$collect$1$1::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$$Lambda$lambda$collect$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReferencePipeline$$Lambda$lambda$collect$1$1::class$ = nullptr;

$MethodInfo _ReferencePipeline_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/function/Supplier;IZ)V", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator<*>;>;IZ)V", 0, $method(ReferencePipeline, init$, void, $Supplier*, int32_t, bool)},
	{"<init>", "(Ljava/util/Spliterator;IZ)V", "(Ljava/util/Spliterator<*>;IZ)V", 0, $method(ReferencePipeline, init$, void, $Spliterator*, int32_t, bool)},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;I)V", "(Ljava/util/stream/AbstractPipeline<*TP_IN;*>;I)V", 0, $method(ReferencePipeline, init$, void, $AbstractPipeline*, int32_t)},
	{"allMatch", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TP_OUT;>;)Z", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, allMatch, bool, $Predicate*)},
	{"anyMatch", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TP_OUT;>;)Z", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, anyMatch, bool, $Predicate*)},
	{"collect", "(Ljava/util/stream/Collector;)Ljava/lang/Object;", "<R:Ljava/lang/Object;A:Ljava/lang/Object;>(Ljava/util/stream/Collector<-TP_OUT;TA;TR;>;)TR;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, collect, $Object*, $Collector*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/BiConsumer<TR;-TP_OUT;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, collect, $Object*, $Supplier*, $BiConsumer*, $BiConsumer*)},
	{"count", "()J", nullptr, $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, count, int64_t)},
	{"distinct", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, distinct, $Stream*)},
	{"dropWhile", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "(Ljava/util/function/Predicate<-TP_OUT;>;)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, dropWhile, $Stream*, $Predicate*)},
	{"evaluateToNode", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;ZLjava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TP_OUT;>;Ljava/util/Spliterator<TP_IN;>;ZLjava/util/function/IntFunction<[TP_OUT;>;)Ljava/util/stream/Node<TP_OUT;>;", $FINAL, $virtualMethod(ReferencePipeline, evaluateToNode, $Node*, $PipelineHelper*, $Spliterator*, bool, $IntFunction*)},
	{"filter", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "(Ljava/util/function/Predicate<-TP_OUT;>;)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, filter, $Stream*, $Predicate*)},
	{"findAny", "()Ljava/util/Optional;", "()Ljava/util/Optional<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, findAny, $Optional*)},
	{"findFirst", "()Ljava/util/Optional;", "()Ljava/util/Optional<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, findFirst, $Optional*)},
	{"flatMap", "(Ljava/util/function/Function;)Ljava/util/stream/Stream;", "<R:Ljava/lang/Object;>(Ljava/util/function/Function<-TP_OUT;+Ljava/util/stream/Stream<+TR;>;>;)Ljava/util/stream/Stream<TR;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, flatMap, $Stream*, $Function*)},
	{"flatMapToDouble", "(Ljava/util/function/Function;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/Function<-TP_OUT;+Ljava/util/stream/DoubleStream;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, flatMapToDouble, $DoubleStream*, $Function*)},
	{"flatMapToInt", "(Ljava/util/function/Function;)Ljava/util/stream/IntStream;", "(Ljava/util/function/Function<-TP_OUT;+Ljava/util/stream/IntStream;>;)Ljava/util/stream/IntStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, flatMapToInt, $IntStream*, $Function*)},
	{"flatMapToLong", "(Ljava/util/function/Function;)Ljava/util/stream/LongStream;", "(Ljava/util/function/Function<-TP_OUT;+Ljava/util/stream/LongStream;>;)Ljava/util/stream/LongStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, flatMapToLong, $LongStream*, $Function*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TP_OUT;>;)V", $PUBLIC, $virtualMethod(ReferencePipeline, forEach, void, $Consumer*)},
	{"forEachOrdered", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TP_OUT;>;)V", $PUBLIC, $virtualMethod(ReferencePipeline, forEachOrdered, void, $Consumer*)},
	{"forEachWithCancel", "(Ljava/util/Spliterator;Ljava/util/stream/Sink;)Z", "(Ljava/util/Spliterator<TP_OUT;>;Ljava/util/stream/Sink<TP_OUT;>;)Z", $FINAL, $virtualMethod(ReferencePipeline, forEachWithCancel, bool, $Spliterator*, $Sink*)},
	{"getOutputShape", "()Ljava/util/stream/StreamShape;", nullptr, $FINAL, $virtualMethod(ReferencePipeline, getOutputShape, $StreamShape*)},
	{"*isParallel", "()Z", nullptr, $PUBLIC | $FINAL},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, iterator, $Iterator*)},
	{"lambda$collect$1", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReferencePipeline, lambda$collect$1, void, $BiConsumer*, Object$*, Object$*)},
	{"lambda$toArray$0", "(I)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ReferencePipeline, lambda$toArray$0, $ObjectArray*, int32_t)},
	{"lazySpliterator", "(Ljava/util/function/Supplier;)Ljava/util/Spliterator;", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator<TP_OUT;>;>;)Ljava/util/Spliterator<TP_OUT;>;", $FINAL, $virtualMethod(ReferencePipeline, lazySpliterator, $Spliterator*, $Supplier*)},
	{"limit", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, limit, $Stream*, int64_t)},
	{"makeNodeBuilder", "(JLjava/util/function/IntFunction;)Ljava/util/stream/Node$Builder;", "(JLjava/util/function/IntFunction<[TP_OUT;>;)Ljava/util/stream/Node$Builder<TP_OUT;>;", $FINAL, $virtualMethod(ReferencePipeline, makeNodeBuilder, $Node$Builder*, int64_t, $IntFunction*)},
	{"map", "(Ljava/util/function/Function;)Ljava/util/stream/Stream;", "<R:Ljava/lang/Object;>(Ljava/util/function/Function<-TP_OUT;+TR;>;)Ljava/util/stream/Stream<TR;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, map, $Stream*, $Function*)},
	{"mapMulti", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/Stream;", "<R:Ljava/lang/Object;>(Ljava/util/function/BiConsumer<-TP_OUT;-Ljava/util/function/Consumer<TR;>;>;)Ljava/util/stream/Stream<TR;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapMulti, $Stream*, $BiConsumer*)},
	{"mapMultiToDouble", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/BiConsumer<-TP_OUT;-Ljava/util/function/DoubleConsumer;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapMultiToDouble, $DoubleStream*, $BiConsumer*)},
	{"mapMultiToInt", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/IntStream;", "(Ljava/util/function/BiConsumer<-TP_OUT;-Ljava/util/function/IntConsumer;>;)Ljava/util/stream/IntStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapMultiToInt, $IntStream*, $BiConsumer*)},
	{"mapMultiToLong", "(Ljava/util/function/BiConsumer;)Ljava/util/stream/LongStream;", "(Ljava/util/function/BiConsumer<-TP_OUT;-Ljava/util/function/LongConsumer;>;)Ljava/util/stream/LongStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapMultiToLong, $LongStream*, $BiConsumer*)},
	{"mapToDouble", "(Ljava/util/function/ToDoubleFunction;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/ToDoubleFunction<-TP_OUT;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapToDouble, $DoubleStream*, $ToDoubleFunction*)},
	{"mapToInt", "(Ljava/util/function/ToIntFunction;)Ljava/util/stream/IntStream;", "(Ljava/util/function/ToIntFunction<-TP_OUT;>;)Ljava/util/stream/IntStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapToInt, $IntStream*, $ToIntFunction*)},
	{"mapToLong", "(Ljava/util/function/ToLongFunction;)Ljava/util/stream/LongStream;", "(Ljava/util/function/ToLongFunction<-TP_OUT;>;)Ljava/util/stream/LongStream;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, mapToLong, $LongStream*, $ToLongFunction*)},
	{"max", "(Ljava/util/Comparator;)Ljava/util/Optional;", "(Ljava/util/Comparator<-TP_OUT;>;)Ljava/util/Optional<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, max, $Optional*, $Comparator*)},
	{"min", "(Ljava/util/Comparator;)Ljava/util/Optional;", "(Ljava/util/Comparator<-TP_OUT;>;)Ljava/util/Optional<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, min, $Optional*, $Comparator*)},
	{"noneMatch", "(Ljava/util/function/Predicate;)Z", "(Ljava/util/function/Predicate<-TP_OUT;>;)Z", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, noneMatch, bool, $Predicate*)},
	{"*onClose", "(Ljava/lang/Runnable;)Ljava/util/stream/BaseStream;", nullptr, $PUBLIC},
	{"*parallel", "()Ljava/util/stream/BaseStream;", nullptr, $PUBLIC | $FINAL},
	{"peek", "(Ljava/util/function/Consumer;)Ljava/util/stream/Stream;", "(Ljava/util/function/Consumer<-TP_OUT;>;)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, peek, $Stream*, $Consumer*)},
	{"reduce", "(Ljava/lang/Object;Ljava/util/function/BinaryOperator;)Ljava/lang/Object;", "(TP_OUT;Ljava/util/function/BinaryOperator<TP_OUT;>;)TP_OUT;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, reduce, $Object*, Object$*, $BinaryOperator*)},
	{"reduce", "(Ljava/util/function/BinaryOperator;)Ljava/util/Optional;", "(Ljava/util/function/BinaryOperator<TP_OUT;>;)Ljava/util/Optional<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, reduce, $Optional*, $BinaryOperator*)},
	{"reduce", "(Ljava/lang/Object;Ljava/util/function/BiFunction;Ljava/util/function/BinaryOperator;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(TR;Ljava/util/function/BiFunction<TR;-TP_OUT;TR;>;Ljava/util/function/BinaryOperator<TR;>;)TR;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, reduce, $Object*, Object$*, $BiFunction*, $BinaryOperator*)},
	{"*sequential", "()Ljava/util/stream/BaseStream;", nullptr, $PUBLIC | $FINAL},
	{"skip", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, skip, $Stream*, int64_t)},
	{"sorted", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, sorted, $Stream*)},
	{"sorted", "(Ljava/util/Comparator;)Ljava/util/stream/Stream;", "(Ljava/util/Comparator<-TP_OUT;>;)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, sorted, $Stream*, $Comparator*)},
	{"*spliterator", "()Ljava/util/Spliterator;", nullptr, $PUBLIC},
	{"takeWhile", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "(Ljava/util/function/Predicate<-TP_OUT;>;)Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, takeWhile, $Stream*, $Predicate*)},
	{"toArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", "<A:Ljava/lang/Object;>(Ljava/util/function/IntFunction<[TA;>;)[TA;", $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, toArray, $ObjectArray*, $IntFunction*)},
	{"toArray", "()[Ljava/lang/Object;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ReferencePipeline, toArray, $ObjectArray*)},
	{"toList", "()Ljava/util/List;", "()Ljava/util/List<TP_OUT;>;", $PUBLIC, $virtualMethod(ReferencePipeline, toList, $List*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unordered", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<TP_OUT;>;", $PUBLIC, $virtualMethod(ReferencePipeline, unordered, $BaseStream*)},
	{"wrap", "(Ljava/util/stream/PipelineHelper;Ljava/util/function/Supplier;Z)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TP_OUT;>;Ljava/util/function/Supplier<Ljava/util/Spliterator<TP_IN;>;>;Z)Ljava/util/Spliterator<TP_OUT;>;", $FINAL, $virtualMethod(ReferencePipeline, wrap, $Spliterator*, $PipelineHelper*, $Supplier*, bool)},
	{}
};

$InnerClassInfo _ReferencePipeline_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$StatefulOp", "java.util.stream.ReferencePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$Head", "java.util.stream.ReferencePipeline", "Head", $STATIC},
	{"java.util.stream.ReferencePipeline$15", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$14", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$13", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$12", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$11", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$10", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$9", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$8", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$7", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$6", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.stream.ReferencePipeline",
	"java.util.stream.AbstractPipeline",
	"java.util.stream.Stream",
	nullptr,
	_ReferencePipeline_MethodInfo_,
	"<P_IN:Ljava/lang/Object;P_OUT:Ljava/lang/Object;>Ljava/util/stream/AbstractPipeline<TP_IN;TP_OUT;Ljava/util/stream/Stream<TP_OUT;>;>;Ljava/util/stream/Stream<TP_OUT;>;",
	nullptr,
	_ReferencePipeline_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline$StatefulOp,java.util.stream.ReferencePipeline$StatelessOp,java.util.stream.ReferencePipeline$Head,java.util.stream.ReferencePipeline$15,java.util.stream.ReferencePipeline$15$1,java.util.stream.ReferencePipeline$14,java.util.stream.ReferencePipeline$14$1,java.util.stream.ReferencePipeline$13,java.util.stream.ReferencePipeline$13$1,java.util.stream.ReferencePipeline$12,java.util.stream.ReferencePipeline$12$1,java.util.stream.ReferencePipeline$11,java.util.stream.ReferencePipeline$11$1,java.util.stream.ReferencePipeline$10,java.util.stream.ReferencePipeline$10$1,java.util.stream.ReferencePipeline$9,java.util.stream.ReferencePipeline$9$1,java.util.stream.ReferencePipeline$8,java.util.stream.ReferencePipeline$8$1,java.util.stream.ReferencePipeline$7,java.util.stream.ReferencePipeline$7$1,java.util.stream.ReferencePipeline$6,java.util.stream.ReferencePipeline$6$1,java.util.stream.ReferencePipeline$5,java.util.stream.ReferencePipeline$5$1,java.util.stream.ReferencePipeline$4,java.util.stream.ReferencePipeline$4$1,java.util.stream.ReferencePipeline$3,java.util.stream.ReferencePipeline$3$1,java.util.stream.ReferencePipeline$2,java.util.stream.ReferencePipeline$2$1,java.util.stream.ReferencePipeline$1"
};

$Object* allocate$ReferencePipeline($Class* clazz) {
	return $of($alloc(ReferencePipeline));
}

$BaseStream* ReferencePipeline::sequential() {
	 return this->$AbstractPipeline::sequential();
}

$BaseStream* ReferencePipeline::parallel() {
	 return this->$AbstractPipeline::parallel();
}

void ReferencePipeline::close() {
	this->$AbstractPipeline::close();
}

$BaseStream* ReferencePipeline::onClose($Runnable* closeHandler) {
	 return this->$AbstractPipeline::onClose(closeHandler);
}

$Spliterator* ReferencePipeline::spliterator() {
	 return this->$AbstractPipeline::spliterator();
}

bool ReferencePipeline::isParallel() {
	 return this->$AbstractPipeline::isParallel();
}

int32_t ReferencePipeline::hashCode() {
	 return this->$AbstractPipeline::hashCode();
}

bool ReferencePipeline::equals(Object$* obj) {
	 return this->$AbstractPipeline::equals(obj);
}

$Object* ReferencePipeline::clone() {
	 return this->$AbstractPipeline::clone();
}

$String* ReferencePipeline::toString() {
	 return this->$AbstractPipeline::toString();
}

void ReferencePipeline::finalize() {
	this->$AbstractPipeline::finalize();
}

void ReferencePipeline::init$($Supplier* source, int32_t sourceFlags, bool parallel) {
	$AbstractPipeline::init$(source, sourceFlags, parallel);
}

void ReferencePipeline::init$($Spliterator* source, int32_t sourceFlags, bool parallel) {
	$AbstractPipeline::init$(source, sourceFlags, parallel);
}

void ReferencePipeline::init$($AbstractPipeline* upstream, int32_t opFlags) {
	$AbstractPipeline::init$(upstream, opFlags);
}

$StreamShape* ReferencePipeline::getOutputShape() {
	$init($StreamShape);
	return $StreamShape::REFERENCE;
}

$Node* ReferencePipeline::evaluateToNode($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree, $IntFunction* generator) {
	return $Nodes::collect(helper, spliterator, flattenTree, generator);
}

$Spliterator* ReferencePipeline::wrap($PipelineHelper* ph, $Supplier* supplier, bool isParallel) {
	return $new($StreamSpliterators$WrappingSpliterator, ph, supplier, isParallel);
}

$Spliterator* ReferencePipeline::lazySpliterator($Supplier* supplier) {
	return $new($StreamSpliterators$DelegatingSpliterator, supplier);
}

bool ReferencePipeline::forEachWithCancel($Spliterator* spliterator, $Sink* sink) {
	bool cancelled = false;
	bool var$0 = false;
	do {
		var$0 = !(cancelled = $nc(sink)->cancellationRequested());
	} while (var$0 && $nc(spliterator)->tryAdvance(sink));
	return cancelled;
}

$Node$Builder* ReferencePipeline::makeNodeBuilder(int64_t exactSizeIfKnown, $IntFunction* generator) {
	return $Nodes::builder(exactSizeIfKnown, generator);
}

$Iterator* ReferencePipeline::iterator() {
	return $Spliterators::iterator($(spliterator()));
}

$BaseStream* ReferencePipeline::unordered() {
	if (!isOrdered()) {
		return static_cast<$BaseStream*>(static_cast<$AbstractPipeline*>(this));
	}
	$init($StreamShape);
	$init($StreamOpFlag);
	return static_cast<$BaseStream*>(static_cast<$AbstractPipeline*>(static_cast<ReferencePipeline*>(static_cast<$ReferencePipeline$StatelessOp*>($new($ReferencePipeline$1, this, this, $StreamShape::REFERENCE, $StreamOpFlag::NOT_ORDERED)))));
}

$Stream* ReferencePipeline::filter($Predicate* predicate) {
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $new($ReferencePipeline$2, this, this, $StreamShape::REFERENCE, $StreamOpFlag::NOT_SIZED, predicate);
}

$Stream* ReferencePipeline::map($Function* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $new($ReferencePipeline$3, this, this, $StreamShape::REFERENCE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper);
}

$IntStream* ReferencePipeline::mapToInt($ToIntFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($IntStream, $new($ReferencePipeline$4, this, this, $StreamShape::REFERENCE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$LongStream* ReferencePipeline::mapToLong($ToLongFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($ReferencePipeline$5, this, this, $StreamShape::REFERENCE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$DoubleStream* ReferencePipeline::mapToDouble($ToDoubleFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($ReferencePipeline$6, this, this, $StreamShape::REFERENCE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$Stream* ReferencePipeline::flatMap($Function* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $new($ReferencePipeline$7, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper);
}

$IntStream* ReferencePipeline::flatMapToInt($Function* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($IntStream, $new($ReferencePipeline$8, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$DoubleStream* ReferencePipeline::flatMapToDouble($Function* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($ReferencePipeline$9, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$LongStream* ReferencePipeline::flatMapToLong($Function* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($ReferencePipeline$10, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$Stream* ReferencePipeline::mapMulti($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $new($ReferencePipeline$11, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper);
}

$IntStream* ReferencePipeline::mapMultiToInt($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($IntStream, $new($ReferencePipeline$12, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$LongStream* ReferencePipeline::mapMultiToLong($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($ReferencePipeline$13, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$DoubleStream* ReferencePipeline::mapMultiToDouble($BiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($ReferencePipeline$14, this, this, $StreamShape::REFERENCE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$Stream* ReferencePipeline::peek($Consumer* action) {
	$Objects::requireNonNull(action);
	$init($StreamShape);
	return $new($ReferencePipeline$15, this, this, $StreamShape::REFERENCE, 0, action);
}

$Stream* ReferencePipeline::distinct() {
	return $DistinctOps::makeRef(this);
}

$Stream* ReferencePipeline::sorted() {
	return $SortedOps::makeRef(this);
}

$Stream* ReferencePipeline::sorted($Comparator* comparator) {
	return $SortedOps::makeRef(this, comparator);
}

$Stream* ReferencePipeline::limit(int64_t maxSize) {
	if (maxSize < 0) {
		$throwNew($IllegalArgumentException, $($Long::toString(maxSize)));
	}
	return $SliceOps::makeRef(this, 0, maxSize);
}

$Stream* ReferencePipeline::skip(int64_t n) {
	if (n < 0) {
		$throwNew($IllegalArgumentException, $($Long::toString(n)));
	}
	if (n == 0) {
		return this;
	} else {
		return $SliceOps::makeRef(this, n, -1);
	}
}

$Stream* ReferencePipeline::takeWhile($Predicate* predicate) {
	return $WhileOps::makeTakeWhileRef(this, predicate);
}

$Stream* ReferencePipeline::dropWhile($Predicate* predicate) {
	return $WhileOps::makeDropWhileRef(this, predicate);
}

void ReferencePipeline::forEach($Consumer* action) {
	evaluate($($ForEachOps::makeRef(action, false)));
}

void ReferencePipeline::forEachOrdered($Consumer* action) {
	evaluate($($ForEachOps::makeRef(action, true)));
}

$ObjectArray* ReferencePipeline::toArray($IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	$var($IntFunction, rawGenerator, generator);
	return $nc($($Nodes::flatten($(evaluateToArrayNode(rawGenerator)), rawGenerator)))->asArray(rawGenerator);
}

$ObjectArray* ReferencePipeline::toArray() {
	return toArray(static_cast<$IntFunction*>($$new(ReferencePipeline$$Lambda$lambda$toArray$0)));
}

$List* ReferencePipeline::toList() {
	$useLocalCurrentObjectStackCache();
	return $nc($($SharedSecrets::getJavaUtilCollectionAccess()))->listFromTrustedArrayNullsAllowed($(this->toArray()));
}

bool ReferencePipeline::anyMatch($Predicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeRef(predicate, $MatchOps$MatchKind::ANY)))))))->booleanValue();
}

bool ReferencePipeline::allMatch($Predicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeRef(predicate, $MatchOps$MatchKind::ALL)))))))->booleanValue();
}

bool ReferencePipeline::noneMatch($Predicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeRef(predicate, $MatchOps$MatchKind::NONE)))))))->booleanValue();
}

$Optional* ReferencePipeline::findFirst() {
	return $cast($Optional, evaluate($($FindOps::makeRef(true))));
}

$Optional* ReferencePipeline::findAny() {
	return $cast($Optional, evaluate($($FindOps::makeRef(false))));
}

$Object* ReferencePipeline::reduce(Object$* identity, $BinaryOperator* accumulator) {
	return $of(evaluate($($ReduceOps::makeRef(identity, static_cast<$BiFunction*>(accumulator), accumulator))));
}

$Optional* ReferencePipeline::reduce($BinaryOperator* accumulator) {
	return $cast($Optional, evaluate($($ReduceOps::makeRef(accumulator))));
}

$Object* ReferencePipeline::reduce(Object$* identity, $BiFunction* accumulator, $BinaryOperator* combiner) {
	return $of(evaluate($($ReduceOps::makeRef(identity, accumulator, combiner))));
}

$Object* ReferencePipeline::collect($Collector* collector) {
	$useLocalCurrentObjectStackCache();
	$var($Object, container, nullptr);
	bool var$1 = isParallel();
	$init($Collector$Characteristics);
	bool var$0 = var$1 && ($nc($($nc(collector)->characteristics()))->contains($Collector$Characteristics::CONCURRENT));
	if (var$0) {
		bool var$2 = !isOrdered();
		var$0 = (var$2 || $nc($(collector->characteristics()))->contains($Collector$Characteristics::UNORDERED));
	}
	if (var$0) {
		$assign(container, $nc($($nc(collector)->supplier()))->get());
		$var($BiConsumer, accumulator, collector->accumulator());
		forEach(static_cast<$Consumer*>($$new(ReferencePipeline$$Lambda$lambda$collect$1$1, accumulator, container)));
	} else {
		$assign(container, evaluate($($ReduceOps::makeRef(collector))));
	}
	return $of($nc($($nc(collector)->characteristics()))->contains($Collector$Characteristics::IDENTITY_FINISH) ? container : $nc($($nc(collector)->finisher()))->apply(container));
}

$Object* ReferencePipeline::collect($Supplier* supplier, $BiConsumer* accumulator, $BiConsumer* combiner) {
	return $of(evaluate($($ReduceOps::makeRef(supplier, accumulator, combiner))));
}

$Optional* ReferencePipeline::max($Comparator* comparator) {
	return reduce($($BinaryOperator::maxBy(comparator)));
}

$Optional* ReferencePipeline::min($Comparator* comparator) {
	return reduce($($BinaryOperator::minBy(comparator)));
}

int64_t ReferencePipeline::count() {
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Long, $(evaluate($($ReduceOps::makeRefCounting()))))))->longValue();
}

void ReferencePipeline::lambda$collect$1($BiConsumer* accumulator, Object$* container, Object$* u) {
	$init(ReferencePipeline);
	$nc(accumulator)->accept(container, u);
}

$ObjectArray* ReferencePipeline::lambda$toArray$0(int32_t x$0) {
	$init(ReferencePipeline);
	return $new($ObjectArray, x$0);
}

ReferencePipeline::ReferencePipeline() {
}

$Class* ReferencePipeline::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ReferencePipeline$$Lambda$lambda$toArray$0::classInfo$.name)) {
			return ReferencePipeline$$Lambda$lambda$toArray$0::load$(name, initialize);
		}
		if (name->equals(ReferencePipeline$$Lambda$lambda$collect$1$1::classInfo$.name)) {
			return ReferencePipeline$$Lambda$lambda$collect$1$1::load$(name, initialize);
		}
	}
	$loadClass(ReferencePipeline, name, initialize, &_ReferencePipeline_ClassInfo_, allocate$ReferencePipeline);
	return class$;
}

$Class* ReferencePipeline::class$ = nullptr;

		} // stream
	} // util
} // java