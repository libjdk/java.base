#include <java/util/stream/DoublePipeline.h>

#include <java/io/Serializable.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/DoubleSummaryStatistics.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/OptionalDouble.h>
#include <java/util/PrimitiveIterator$OfDouble.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/DoubleBinaryOperator.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/DoubleFunction.h>
#include <java/util/function/DoublePredicate.h>
#include <java/util/function/DoubleToIntFunction.h>
#include <java/util/function/DoubleToLongFunction.h>
#include <java/util/function/DoubleUnaryOperator.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/ObjDoubleConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/function/ToDoubleFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/DoublePipeline$1.h>
#include <java/util/stream/DoublePipeline$2.h>
#include <java/util/stream/DoublePipeline$3.h>
#include <java/util/stream/DoublePipeline$4.h>
#include <java/util/stream/DoublePipeline$5.h>
#include <java/util/stream/DoublePipeline$6.h>
#include <java/util/stream/DoublePipeline$7.h>
#include <java/util/stream/DoublePipeline$8.h>
#include <java/util/stream/DoublePipeline$9.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/DoubleStream$DoubleMapMultiConsumer.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/FindOps.h>
#include <java/util/stream/ForEachOps.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/MatchOps$MatchKind.h>
#include <java/util/stream/MatchOps.h>
#include <java/util/stream/Node$Builder$OfDouble.h>
#include <java/util/stream/Node$Builder.h>
#include <java/util/stream/Node$OfDouble.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReduceOps.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SliceOps.h>
#include <java/util/stream/SortedOps.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/StreamSpliterators$AbstractWrappingSpliterator.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfDouble.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfPrimitive.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator.h>
#include <java/util/stream/StreamSpliterators$DoubleWrappingSpliterator.h>
#include <java/util/stream/TerminalOp.h>
#include <java/util/stream/Tripwire.h>
#include <java/util/stream/WhileOps.h>
#include <jcpp.h>

#undef ALL
#undef ANY
#undef DOUBLE_VALUE
#undef ENABLED
#undef NONE
#undef NOT_DISTINCT
#undef NOT_ORDERED
#undef NOT_SIZED
#undef NOT_SORTED

using $DoubleArray = $Array<::java::lang::Double>;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DoubleSummaryStatistics = ::java::util::DoubleSummaryStatistics;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $OptionalDouble = ::java::util::OptionalDouble;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterators = ::java::util::Spliterators;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $DoubleBinaryOperator = ::java::util::function::DoubleBinaryOperator;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $DoubleFunction = ::java::util::function::DoubleFunction;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $DoubleToIntFunction = ::java::util::function::DoubleToIntFunction;
using $DoubleToLongFunction = ::java::util::function::DoubleToLongFunction;
using $DoubleUnaryOperator = ::java::util::function::DoubleUnaryOperator;
using $IntFunction = ::java::util::function::IntFunction;
using $ObjDoubleConsumer = ::java::util::function::ObjDoubleConsumer;
using $Supplier = ::java::util::function::Supplier;
using $ToDoubleFunction = ::java::util::function::ToDoubleFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $BaseStream = ::java::util::stream::BaseStream;
using $Collectors = ::java::util::stream::Collectors;
using $DoublePipeline$1 = ::java::util::stream::DoublePipeline$1;
using $DoublePipeline$2 = ::java::util::stream::DoublePipeline$2;
using $DoublePipeline$3 = ::java::util::stream::DoublePipeline$3;
using $DoublePipeline$4 = ::java::util::stream::DoublePipeline$4;
using $DoublePipeline$5 = ::java::util::stream::DoublePipeline$5;
using $DoublePipeline$6 = ::java::util::stream::DoublePipeline$6;
using $DoublePipeline$7 = ::java::util::stream::DoublePipeline$7;
using $DoublePipeline$8 = ::java::util::stream::DoublePipeline$8;
using $DoublePipeline$9 = ::java::util::stream::DoublePipeline$9;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $DoubleStream$DoubleMapMultiConsumer = ::java::util::stream::DoubleStream$DoubleMapMultiConsumer;
using $FindOps = ::java::util::stream::FindOps;
using $ForEachOps = ::java::util::stream::ForEachOps;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $MatchOps = ::java::util::stream::MatchOps;
using $MatchOps$MatchKind = ::java::util::stream::MatchOps$MatchKind;
using $Node = ::java::util::stream::Node;
using $Node$Builder = ::java::util::stream::Node$Builder;
using $Node$OfDouble = ::java::util::stream::Node$OfDouble;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReduceOps = ::java::util::stream::ReduceOps;
using $Sink = ::java::util::stream::Sink;
using $SliceOps = ::java::util::stream::SliceOps;
using $SortedOps = ::java::util::stream::SortedOps;
using $Stream = ::java::util::stream::Stream;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $StreamSpliterators$AbstractWrappingSpliterator = ::java::util::stream::StreamSpliterators$AbstractWrappingSpliterator;
using $StreamSpliterators$DelegatingSpliterator = ::java::util::stream::StreamSpliterators$DelegatingSpliterator;
using $StreamSpliterators$DelegatingSpliterator$OfDouble = ::java::util::stream::StreamSpliterators$DelegatingSpliterator$OfDouble;
using $StreamSpliterators$DelegatingSpliterator$OfPrimitive = ::java::util::stream::StreamSpliterators$DelegatingSpliterator$OfPrimitive;
using $StreamSpliterators$DoubleWrappingSpliterator = ::java::util::stream::StreamSpliterators$DoubleWrappingSpliterator;
using $Tripwire = ::java::util::stream::Tripwire;
using $WhileOps = ::java::util::stream::WhileOps;

namespace java {
	namespace util {
		namespace stream {

class DoublePipeline$$Lambda$accept : public $DoubleConsumer {
	$class(DoublePipeline$$Lambda$accept, $NO_CLASS_INIT, $DoubleConsumer)
public:
	void init$($Sink* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(double value) override {
		$nc(inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$accept>());
	}
	$Sink* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DoublePipeline$$Lambda$accept::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DoublePipeline$$Lambda$accept, inst$)},
	{}
};
$MethodInfo DoublePipeline$$Lambda$accept::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/Sink;)V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$accept, init$, void, $Sink*)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$accept, accept, void, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$accept::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$accept",
	"java.lang.Object",
	"java.util.function.DoubleConsumer",
	fieldInfos,
	methodInfos
};
$Class* DoublePipeline$$Lambda$accept::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$accept, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$accept::class$ = nullptr;

class DoublePipeline$$Lambda$valueOf$1 : public $DoubleFunction {
	$class(DoublePipeline$$Lambda$valueOf$1, $NO_CLASS_INIT, $DoubleFunction)
public:
	void init$() {
	}
	virtual $Object* apply(double d) override {
		 return $of($Double::valueOf(d));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$valueOf$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$valueOf$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$valueOf$1, init$, void)},
	{"apply", "(D)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$valueOf$1, apply, $Object*, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$valueOf$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$valueOf$1",
	"java.lang.Object",
	"java.util.function.DoubleFunction",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$valueOf$1::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$valueOf$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$valueOf$1::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$distinct$0$2 : public $ToDoubleFunction {
	$class(DoublePipeline$$Lambda$lambda$distinct$0$2, $NO_CLASS_INIT, $ToDoubleFunction)
public:
	void init$() {
	}
	virtual double applyAsDouble(Object$* i) override {
		 return DoublePipeline::lambda$distinct$0($cast($Double, i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$distinct$0$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$distinct$0$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$distinct$0$2, init$, void)},
	{"applyAsDouble", "(Ljava/lang/Object;)D", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$distinct$0$2, applyAsDouble, double, Object$*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$distinct$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$distinct$0$2",
	"java.lang.Object",
	"java.util.function.ToDoubleFunction",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$distinct$0$2::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$distinct$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$distinct$0$2::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$sum$1$3 : public $Supplier {
	$class(DoublePipeline$$Lambda$lambda$sum$1$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(DoublePipeline::lambda$sum$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$sum$1$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$sum$1$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$sum$1$3, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$sum$1$3, get, $Object*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$sum$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$sum$1$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$sum$1$3::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$sum$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$sum$1$3::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$sum$2$4 : public $ObjDoubleConsumer {
	$class(DoublePipeline$$Lambda$lambda$sum$2$4, $NO_CLASS_INIT, $ObjDoubleConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* ll, double d) override {
		DoublePipeline::lambda$sum$2($cast($doubles, ll), d);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$sum$2$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$sum$2$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$sum$2$4, init$, void)},
	{"accept", "(Ljava/lang/Object;D)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$sum$2$4, accept, void, Object$*, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$sum$2$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$sum$2$4",
	"java.lang.Object",
	"java.util.function.ObjDoubleConsumer",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$sum$2$4::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$sum$2$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$sum$2$4::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$sum$3$5 : public $BiConsumer {
	$class(DoublePipeline$$Lambda$lambda$sum$3$5, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* ll, Object$* rr) override {
		DoublePipeline::lambda$sum$3($cast($doubles, ll), $cast($doubles, rr));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$sum$3$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$sum$3$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$sum$3$5, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$sum$3$5, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$sum$3$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$sum$3$5",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$sum$3$5::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$sum$3$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$sum$3$5::class$ = nullptr;

class DoublePipeline$$Lambda$min$6 : public $DoubleBinaryOperator {
	$class(DoublePipeline$$Lambda$min$6, $NO_CLASS_INIT, $DoubleBinaryOperator)
public:
	void init$() {
	}
	virtual double applyAsDouble(double a, double b) override {
		 return $Math::min(a, b);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$min$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$min$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$min$6, init$, void)},
	{"applyAsDouble", "(DD)D", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$min$6, applyAsDouble, double, double, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$min$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$min$6",
	"java.lang.Object",
	"java.util.function.DoubleBinaryOperator",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$min$6::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$min$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$min$6::class$ = nullptr;

class DoublePipeline$$Lambda$max$7 : public $DoubleBinaryOperator {
	$class(DoublePipeline$$Lambda$max$7, $NO_CLASS_INIT, $DoubleBinaryOperator)
public:
	void init$() {
	}
	virtual double applyAsDouble(double a, double b) override {
		 return $Math::max(a, b);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$max$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$max$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$max$7, init$, void)},
	{"applyAsDouble", "(DD)D", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$max$7, applyAsDouble, double, double, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$max$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$max$7",
	"java.lang.Object",
	"java.util.function.DoubleBinaryOperator",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$max$7::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$max$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$max$7::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$average$4$8 : public $Supplier {
	$class(DoublePipeline$$Lambda$lambda$average$4$8, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(DoublePipeline::lambda$average$4());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$average$4$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$average$4$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$average$4$8, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$average$4$8, get, $Object*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$average$4$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$average$4$8",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$average$4$8::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$average$4$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$average$4$8::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$average$5$9 : public $ObjDoubleConsumer {
	$class(DoublePipeline$$Lambda$lambda$average$5$9, $NO_CLASS_INIT, $ObjDoubleConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* ll, double d) override {
		DoublePipeline::lambda$average$5($cast($doubles, ll), d);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$average$5$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$average$5$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$average$5$9, init$, void)},
	{"accept", "(Ljava/lang/Object;D)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$average$5$9, accept, void, Object$*, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$average$5$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$average$5$9",
	"java.lang.Object",
	"java.util.function.ObjDoubleConsumer",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$average$5$9::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$average$5$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$average$5$9::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$average$6$10 : public $BiConsumer {
	$class(DoublePipeline$$Lambda$lambda$average$6$10, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* ll, Object$* rr) override {
		DoublePipeline::lambda$average$6($cast($doubles, ll), $cast($doubles, rr));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$average$6$10>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$average$6$10::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$average$6$10, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$average$6$10, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$average$6$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$average$6$10",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$average$6$10::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$average$6$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$average$6$10::class$ = nullptr;

class DoublePipeline$$Lambda$DoubleSummaryStatistics$11 : public $Supplier {
	$class(DoublePipeline$$Lambda$DoubleSummaryStatistics$11, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($DoubleSummaryStatistics));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$DoubleSummaryStatistics$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$DoubleSummaryStatistics$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$DoubleSummaryStatistics$11, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$DoubleSummaryStatistics$11, get, $Object*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$DoubleSummaryStatistics$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$DoubleSummaryStatistics$11",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$DoubleSummaryStatistics$11::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$DoubleSummaryStatistics$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$DoubleSummaryStatistics$11::class$ = nullptr;

class DoublePipeline$$Lambda$accept$12 : public $ObjDoubleConsumer {
	$class(DoublePipeline$$Lambda$accept$12, $NO_CLASS_INIT, $ObjDoubleConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, double value) override {
		$sure($DoubleSummaryStatistics, inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$accept$12>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$accept$12::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$accept$12, init$, void)},
	{"accept", "(Ljava/lang/Object;D)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$accept$12, accept, void, Object$*, double)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$accept$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$accept$12",
	"java.lang.Object",
	"java.util.function.ObjDoubleConsumer",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$accept$12::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$accept$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$accept$12::class$ = nullptr;

class DoublePipeline$$Lambda$combine$13 : public $BiConsumer {
	$class(DoublePipeline$$Lambda$combine$13, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* other) override {
		$sure($DoubleSummaryStatistics, inst$)->combine($cast($DoubleSummaryStatistics, other));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$combine$13>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$combine$13::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$combine$13, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$combine$13, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$combine$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$combine$13",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$combine$13::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$combine$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$combine$13::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$collect$7$14 : public $BinaryOperator {
	$class(DoublePipeline$$Lambda$lambda$collect$7$14, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$($BiConsumer* combiner) {
		$set(this, combiner, combiner);
	}
	virtual $Object* apply(Object$* left, Object$* right) override {
		 return DoublePipeline::lambda$collect$7(combiner, left, right);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$collect$7$14>());
	}
	$BiConsumer* combiner = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DoublePipeline$$Lambda$lambda$collect$7$14::fieldInfos[2] = {
	{"combiner", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(DoublePipeline$$Lambda$lambda$collect$7$14, combiner)},
	{}
};
$MethodInfo DoublePipeline$$Lambda$lambda$collect$7$14::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$collect$7$14, init$, void, $BiConsumer*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$collect$7$14, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$collect$7$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$collect$7$14",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	fieldInfos,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$collect$7$14::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$collect$7$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$collect$7$14::class$ = nullptr;

class DoublePipeline$$Lambda$lambda$toArray$8$15 : public $IntFunction {
	$class(DoublePipeline$$Lambda$lambda$toArray$8$15, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(DoublePipeline::lambda$toArray$8(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DoublePipeline$$Lambda$lambda$toArray$8$15>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DoublePipeline$$Lambda$lambda$toArray$8$15::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DoublePipeline$$Lambda$lambda$toArray$8$15, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline$$Lambda$lambda$toArray$8$15, apply, $Object*, int32_t)},
	{}
};
$ClassInfo DoublePipeline$$Lambda$lambda$toArray$8$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.DoublePipeline$$Lambda$lambda$toArray$8$15",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* DoublePipeline$$Lambda$lambda$toArray$8$15::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$$Lambda$lambda$toArray$8$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DoublePipeline$$Lambda$lambda$toArray$8$15::class$ = nullptr;

$MethodInfo _DoublePipeline_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/function/Supplier;IZ)V", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator<Ljava/lang/Double;>;>;IZ)V", 0, $method(DoublePipeline, init$, void, $Supplier*, int32_t, bool)},
	{"<init>", "(Ljava/util/Spliterator;IZ)V", "(Ljava/util/Spliterator<Ljava/lang/Double;>;IZ)V", 0, $method(DoublePipeline, init$, void, $Spliterator*, int32_t, bool)},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;I)V", "(Ljava/util/stream/AbstractPipeline<*TE_IN;*>;I)V", 0, $method(DoublePipeline, init$, void, $AbstractPipeline*, int32_t)},
	{"adapt", "(Ljava/util/stream/Sink;)Ljava/util/function/DoubleConsumer;", "(Ljava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/function/DoubleConsumer;", $PRIVATE | $STATIC, $staticMethod(DoublePipeline, adapt, $DoubleConsumer*, $Sink*)},
	{"adapt", "(Ljava/util/Spliterator;)Ljava/util/Spliterator$OfDouble;", "(Ljava/util/Spliterator<Ljava/lang/Double;>;)Ljava/util/Spliterator$OfDouble;", $PRIVATE | $STATIC, $staticMethod(DoublePipeline, adapt, $Spliterator$OfDouble*, $Spliterator*)},
	{"allMatch", "(Ljava/util/function/DoublePredicate;)Z", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, allMatch, bool, $DoublePredicate*)},
	{"anyMatch", "(Ljava/util/function/DoublePredicate;)Z", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, anyMatch, bool, $DoublePredicate*)},
	{"average", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, average, $OptionalDouble*)},
	{"boxed", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Double;>;", $PUBLIC | $FINAL, $method(DoublePipeline, boxed, $Stream*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/ObjDoubleConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjDoubleConsumer<TR;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $FINAL, $method(DoublePipeline, collect, $Object*, $Supplier*, $ObjDoubleConsumer*, $BiConsumer*)},
	{"count", "()J", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, count, int64_t)},
	{"distinct", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, distinct, $DoubleStream*)},
	{"dropWhile", "(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, dropWhile, $DoubleStream*, $DoublePredicate*)},
	{"evaluateToNode", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;ZLjava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;ZLjava/util/function/IntFunction<[Ljava/lang/Double;>;)Ljava/util/stream/Node<Ljava/lang/Double;>;", $FINAL, $virtualMethod(DoublePipeline, evaluateToNode, $Node*, $PipelineHelper*, $Spliterator*, bool, $IntFunction*)},
	{"filter", "(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, filter, $DoubleStream*, $DoublePredicate*)},
	{"findAny", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, findAny, $OptionalDouble*)},
	{"findFirst", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, findFirst, $OptionalDouble*)},
	{"flatMap", "(Ljava/util/function/DoubleFunction;)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/DoubleFunction<+Ljava/util/stream/DoubleStream;>;)Ljava/util/stream/DoubleStream;", $PUBLIC | $FINAL, $method(DoublePipeline, flatMap, $DoubleStream*, $DoubleFunction*)},
	{"forEach", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline, forEach, void, $DoubleConsumer*)},
	{"forEachOrdered", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $virtualMethod(DoublePipeline, forEachOrdered, void, $DoubleConsumer*)},
	{"forEachWithCancel", "(Ljava/util/Spliterator;Ljava/util/stream/Sink;)Z", "(Ljava/util/Spliterator<Ljava/lang/Double;>;Ljava/util/stream/Sink<Ljava/lang/Double;>;)Z", $FINAL, $virtualMethod(DoublePipeline, forEachWithCancel, bool, $Spliterator*, $Sink*)},
	{"getOutputShape", "()Ljava/util/stream/StreamShape;", nullptr, $FINAL, $virtualMethod(DoublePipeline, getOutputShape, $StreamShape*)},
	{"*isParallel", "()Z", nullptr, $PUBLIC | $FINAL},
	{"iterator", "()Ljava/util/PrimitiveIterator$OfDouble;", nullptr, $PUBLIC | $FINAL, $virtualMethod(DoublePipeline, iterator, $Iterator*)},
	{"lambda$average$4", "()[D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$average$4, $doubles*)},
	{"lambda$average$5", "([DD)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$average$5, void, $doubles*, double)},
	{"lambda$average$6", "([D[D)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$average$6, void, $doubles*, $doubles*)},
	{"lambda$collect$7", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$collect$7, $Object*, $BiConsumer*, Object$*, Object$*)},
	{"lambda$distinct$0", "(Ljava/lang/Double;)D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$distinct$0, double, $Double*)},
	{"lambda$sum$1", "()[D", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$sum$1, $doubles*)},
	{"lambda$sum$2", "([DD)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$sum$2, void, $doubles*, double)},
	{"lambda$sum$3", "([D[D)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$sum$3, void, $doubles*, $doubles*)},
	{"lambda$toArray$8", "(I)[Ljava/lang/Double;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DoublePipeline, lambda$toArray$8, $DoubleArray*, int32_t)},
	{"lazySpliterator", "(Ljava/util/function/Supplier;)Ljava/util/Spliterator$OfDouble;", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator<Ljava/lang/Double;>;>;)Ljava/util/Spliterator$OfDouble;", $FINAL, $virtualMethod(DoublePipeline, lazySpliterator, $Spliterator*, $Supplier*)},
	{"limit", "(J)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, limit, $DoubleStream*, int64_t)},
	{"makeNodeBuilder", "(JLjava/util/function/IntFunction;)Ljava/util/stream/Node$Builder;", "(JLjava/util/function/IntFunction<[Ljava/lang/Double;>;)Ljava/util/stream/Node$Builder<Ljava/lang/Double;>;", $FINAL, $virtualMethod(DoublePipeline, makeNodeBuilder, $Node$Builder*, int64_t, $IntFunction*)},
	{"map", "(Ljava/util/function/DoubleUnaryOperator;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, map, $DoubleStream*, $DoubleUnaryOperator*)},
	{"mapMulti", "(Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, mapMulti, $DoubleStream*, $DoubleStream$DoubleMapMultiConsumer*)},
	{"mapToInt", "(Ljava/util/function/DoubleToIntFunction;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, mapToInt, $IntStream*, $DoubleToIntFunction*)},
	{"mapToLong", "(Ljava/util/function/DoubleToLongFunction;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, mapToLong, $LongStream*, $DoubleToLongFunction*)},
	{"mapToObj", "(Ljava/util/function/DoubleFunction;I)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/DoubleFunction<+TU;>;I)Ljava/util/stream/Stream<TU;>;", $PRIVATE, $method(DoublePipeline, mapToObj, $Stream*, $DoubleFunction*, int32_t)},
	{"mapToObj", "(Ljava/util/function/DoubleFunction;)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/DoubleFunction<+TU;>;)Ljava/util/stream/Stream<TU;>;", $PUBLIC | $FINAL, $method(DoublePipeline, mapToObj, $Stream*, $DoubleFunction*)},
	{"max", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, max, $OptionalDouble*)},
	{"min", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, min, $OptionalDouble*)},
	{"noneMatch", "(Ljava/util/function/DoublePredicate;)Z", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, noneMatch, bool, $DoublePredicate*)},
	{"*onClose", "(Ljava/lang/Runnable;)Ljava/util/stream/BaseStream;", nullptr, $PUBLIC},
	{"parallel", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(DoublePipeline, parallel, $BaseStream*)},
	{"peek", "(Ljava/util/function/DoubleConsumer;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, peek, $DoubleStream*, $DoubleConsumer*)},
	{"reduce", "(DLjava/util/function/DoubleBinaryOperator;)D", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, reduce, double, double, $DoubleBinaryOperator*)},
	{"reduce", "(Ljava/util/function/DoubleBinaryOperator;)Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, reduce, $OptionalDouble*, $DoubleBinaryOperator*)},
	{"sequential", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(DoublePipeline, sequential, $BaseStream*)},
	{"skip", "(J)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, skip, $DoubleStream*, int64_t)},
	{"sorted", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, sorted, $DoubleStream*)},
	{"spliterator", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC | $FINAL, $virtualMethod(DoublePipeline, spliterator, $Spliterator*)},
	{"sum", "()D", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, sum, double)},
	{"summaryStatistics", "()Ljava/util/DoubleSummaryStatistics;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, summaryStatistics, $DoubleSummaryStatistics*)},
	{"takeWhile", "(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, takeWhile, $DoubleStream*, $DoublePredicate*)},
	{"toArray", "()[D", nullptr, $PUBLIC | $FINAL, $method(DoublePipeline, toArray, $doubles*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unordered", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC, $virtualMethod(DoublePipeline, unordered, $BaseStream*)},
	{"wrap", "(Ljava/util/stream/PipelineHelper;Ljava/util/function/Supplier;Z)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/function/Supplier<Ljava/util/Spliterator<TP_IN;>;>;Z)Ljava/util/Spliterator<Ljava/lang/Double;>;", $FINAL, $virtualMethod(DoublePipeline, wrap, $Spliterator*, $PipelineHelper*, $Supplier*, bool)},
	{}
};

$InnerClassInfo _DoublePipeline_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$StatefulOp", "java.util.stream.DoublePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$Head", "java.util.stream.DoublePipeline", "Head", $STATIC},
	{"java.util.stream.DoublePipeline$9", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$8", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$7", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$6", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.stream.DoublePipeline",
	"java.util.stream.AbstractPipeline",
	"java.util.stream.DoubleStream",
	nullptr,
	_DoublePipeline_MethodInfo_,
	"<E_IN:Ljava/lang/Object;>Ljava/util/stream/AbstractPipeline<TE_IN;Ljava/lang/Double;Ljava/util/stream/DoubleStream;>;Ljava/util/stream/DoubleStream;",
	nullptr,
	_DoublePipeline_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline$StatefulOp,java.util.stream.DoublePipeline$StatelessOp,java.util.stream.DoublePipeline$Head,java.util.stream.DoublePipeline$9,java.util.stream.DoublePipeline$9$1,java.util.stream.DoublePipeline$8,java.util.stream.DoublePipeline$8$1,java.util.stream.DoublePipeline$7,java.util.stream.DoublePipeline$6,java.util.stream.DoublePipeline$6$1,java.util.stream.DoublePipeline$5,java.util.stream.DoublePipeline$5$1,java.util.stream.DoublePipeline$4,java.util.stream.DoublePipeline$4$1,java.util.stream.DoublePipeline$3,java.util.stream.DoublePipeline$3$1,java.util.stream.DoublePipeline$2,java.util.stream.DoublePipeline$2$1,java.util.stream.DoublePipeline$1,java.util.stream.DoublePipeline$1$1"
};

$Object* allocate$DoublePipeline($Class* clazz) {
	return $of($alloc(DoublePipeline));
}

void DoublePipeline::close() {
	this->$AbstractPipeline::close();
}

$BaseStream* DoublePipeline::onClose($Runnable* closeHandler) {
	 return this->$AbstractPipeline::onClose(closeHandler);
}

bool DoublePipeline::isParallel() {
	 return this->$AbstractPipeline::isParallel();
}

int32_t DoublePipeline::hashCode() {
	 return this->$AbstractPipeline::hashCode();
}

bool DoublePipeline::equals(Object$* obj) {
	 return this->$AbstractPipeline::equals(obj);
}

$Object* DoublePipeline::clone() {
	 return this->$AbstractPipeline::clone();
}

$String* DoublePipeline::toString() {
	 return this->$AbstractPipeline::toString();
}

void DoublePipeline::finalize() {
	this->$AbstractPipeline::finalize();
}

DoublePipeline::MemberClass0$::MemberClass0$() {
	$patchMemberClass(DoublePipeline, $DoubleStream, memberClass0$);
}

$DoubleStream* DoublePipeline::MemberClass0$::filter($DoublePredicate* predicate) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->filter(predicate);
}

$DoubleStream* DoublePipeline::MemberClass0$::map($DoubleUnaryOperator* mapper) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->map(mapper);
}

$Stream* DoublePipeline::MemberClass0$::mapToObj($DoubleFunction* mapper) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->mapToObj(mapper);
}

$IntStream* DoublePipeline::MemberClass0$::mapToInt($DoubleToIntFunction* mapper) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->mapToInt(mapper);
}

$LongStream* DoublePipeline::MemberClass0$::mapToLong($DoubleToLongFunction* mapper) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->mapToLong(mapper);
}

$DoubleStream* DoublePipeline::MemberClass0$::flatMap($DoubleFunction* mapper) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->flatMap(mapper);
}

$DoubleStream* DoublePipeline::MemberClass0$::mapMulti($DoubleStream$DoubleMapMultiConsumer* mapper) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->mapMulti(mapper);
}

$DoubleStream* DoublePipeline::MemberClass0$::distinct() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->distinct();
}

$DoubleStream* DoublePipeline::MemberClass0$::sorted() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->sorted();
}

$DoubleStream* DoublePipeline::MemberClass0$::peek($DoubleConsumer* action) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->peek(action);
}

$DoubleStream* DoublePipeline::MemberClass0$::limit(int64_t maxSize) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->limit(maxSize);
}

$DoubleStream* DoublePipeline::MemberClass0$::skip(int64_t n) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->skip(n);
}

$DoubleStream* DoublePipeline::MemberClass0$::takeWhile($DoublePredicate* predicate) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->takeWhile(predicate);
}

$DoubleStream* DoublePipeline::MemberClass0$::dropWhile($DoublePredicate* predicate) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->dropWhile(predicate);
}

void DoublePipeline::MemberClass0$::forEach($DoubleConsumer* action) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->forEach(action);
}

void DoublePipeline::MemberClass0$::forEachOrdered($DoubleConsumer* action) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->forEachOrdered(action);
}

$doubles* DoublePipeline::MemberClass0$::toArray() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->toArray();
}

double DoublePipeline::MemberClass0$::reduce(double identity, $DoubleBinaryOperator* op) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->reduce(identity, op);
}

$OptionalDouble* DoublePipeline::MemberClass0$::reduce($DoubleBinaryOperator* op) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->reduce(op);
}

$Object* DoublePipeline::MemberClass0$::collect($Supplier* supplier, $ObjDoubleConsumer* accumulator, $BiConsumer* combiner) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->collect(supplier, accumulator, combiner);
}

double DoublePipeline::MemberClass0$::sum() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->sum();
}

$OptionalDouble* DoublePipeline::MemberClass0$::min() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->min();
}

$OptionalDouble* DoublePipeline::MemberClass0$::max() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->max();
}

int64_t DoublePipeline::MemberClass0$::count() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->count();
}

$OptionalDouble* DoublePipeline::MemberClass0$::average() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->average();
}

$DoubleSummaryStatistics* DoublePipeline::MemberClass0$::summaryStatistics() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->summaryStatistics();
}

bool DoublePipeline::MemberClass0$::anyMatch($DoublePredicate* predicate) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->anyMatch(predicate);
}

bool DoublePipeline::MemberClass0$::allMatch($DoublePredicate* predicate) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->allMatch(predicate);
}

bool DoublePipeline::MemberClass0$::noneMatch($DoublePredicate* predicate) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->noneMatch(predicate);
}

$OptionalDouble* DoublePipeline::MemberClass0$::findFirst() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->findFirst();
}

$OptionalDouble* DoublePipeline::MemberClass0$::findAny() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->findAny();
}

$Stream* DoublePipeline::MemberClass0$::boxed() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->boxed();
}

$DoubleStream* DoublePipeline::MemberClass0$::sequential() {
	return $cast($DoubleStream, ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->sequential());
}

$DoubleStream* DoublePipeline::MemberClass0$::parallel() {
	return $cast($DoubleStream, ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->parallel());
}

$Iterator* DoublePipeline::MemberClass0$::iterator() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->iterator();
}

$Spliterator* DoublePipeline::MemberClass0$::spliterator() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->spliterator();
}

bool DoublePipeline::MemberClass0$::isParallel() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->isParallel();
}

$BaseStream* DoublePipeline::MemberClass0$::unordered() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->unordered();
}

$BaseStream* DoublePipeline::MemberClass0$::onClose($Runnable* closeHandler) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->onClose(closeHandler);
}

void DoublePipeline::MemberClass0$::close() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->close();
}

int32_t DoublePipeline::MemberClass0$::hashCode() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->hashCode();
}

bool DoublePipeline::MemberClass0$::equals(Object$* obj) {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->equals(obj);
}

$Object* DoublePipeline::MemberClass0$::clone() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->clone();
}

$String* DoublePipeline::MemberClass0$::toString() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->toString();
}

void DoublePipeline::MemberClass0$::finalize() {
	return ((DoublePipeline*)(void*)((int8_t*)(void*)this - $offsetof(DoublePipeline, memberClass0$)))->finalize();
}

void DoublePipeline::init$($Supplier* source, int32_t sourceFlags, bool parallel) {
	$AbstractPipeline::init$(source, sourceFlags, parallel);
}

void DoublePipeline::init$($Spliterator* source, int32_t sourceFlags, bool parallel) {
	$AbstractPipeline::init$(source, sourceFlags, parallel);
}

void DoublePipeline::init$($AbstractPipeline* upstream, int32_t opFlags) {
	$AbstractPipeline::init$(upstream, opFlags);
}

$DoubleConsumer* DoublePipeline::adapt($Sink* sink) {
	$init(DoublePipeline);
	if ($instanceOf($DoubleConsumer, sink)) {
		return $cast($DoubleConsumer, sink);
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$load($AbstractPipeline);
			$Tripwire::trip($AbstractPipeline::class$, "using DoubleStream.adapt(Sink<Double> s)"_s);
		}
		return static_cast<$DoubleConsumer*>($new(DoublePipeline$$Lambda$accept, static_cast<$Sink*>($nc(sink))));
	}
}

$Spliterator$OfDouble* DoublePipeline::adapt($Spliterator* s) {
	$init(DoublePipeline);
	if ($instanceOf($Spliterator$OfDouble, s)) {
		return $cast($Spliterator$OfDouble, s);
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$load($AbstractPipeline);
			$Tripwire::trip($AbstractPipeline::class$, "using DoubleStream.adapt(Spliterator<Double> s)"_s);
		}
		$throwNew($UnsupportedOperationException, "DoubleStream.adapt(Spliterator<Double> s)"_s);
	}
}

$StreamShape* DoublePipeline::getOutputShape() {
	$init($StreamShape);
	return $StreamShape::DOUBLE_VALUE;
}

$Node* DoublePipeline::evaluateToNode($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree, $IntFunction* generator) {
	return $Nodes::collectDouble(helper, spliterator, flattenTree);
}

$Spliterator* DoublePipeline::wrap($PipelineHelper* ph, $Supplier* supplier, bool isParallel) {
	return static_cast<$Spliterator*>(static_cast<$StreamSpliterators$AbstractWrappingSpliterator*>($new($StreamSpliterators$DoubleWrappingSpliterator, ph, supplier, isParallel)));
}

$Spliterator* DoublePipeline::lazySpliterator($Supplier* supplier) {
	return static_cast<$Spliterator*>(static_cast<$StreamSpliterators$DelegatingSpliterator*>(static_cast<$StreamSpliterators$DelegatingSpliterator$OfPrimitive*>($new($StreamSpliterators$DelegatingSpliterator$OfDouble, supplier))));
}

bool DoublePipeline::forEachWithCancel($Spliterator* spliterator, $Sink* sink) {
	$useLocalCurrentObjectStackCache();
	$var($Spliterator$OfDouble, spl, adapt(spliterator));
	$var($DoubleConsumer, adaptedSink, adapt(sink));
	bool cancelled = false;
	bool var$0 = false;
	do {
		var$0 = !(cancelled = $nc(sink)->cancellationRequested());
	} while (var$0 && $nc(spl)->tryAdvance(adaptedSink));
	return cancelled;
}

$Node$Builder* DoublePipeline::makeNodeBuilder(int64_t exactSizeIfKnown, $IntFunction* generator) {
	return $Nodes::doubleBuilder(exactSizeIfKnown);
}

$Stream* DoublePipeline::mapToObj($DoubleFunction* mapper, int32_t opFlags) {
	$init($StreamShape);
	return $new($DoublePipeline$1, this, this, $StreamShape::DOUBLE_VALUE, opFlags, mapper);
}

$Iterator* DoublePipeline::iterator() {
	return $Spliterators::iterator($($cast($Spliterator$OfDouble, spliterator())));
}

$Spliterator* DoublePipeline::spliterator() {
	return adapt($($AbstractPipeline::spliterator()));
}

$Stream* DoublePipeline::boxed() {
	return mapToObj(static_cast<$DoubleFunction*>($$new(DoublePipeline$$Lambda$valueOf$1)), 0);
}

$DoubleStream* DoublePipeline::map($DoubleUnaryOperator* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($DoublePipeline$2, this, this, $StreamShape::DOUBLE_VALUE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$Stream* DoublePipeline::mapToObj($DoubleFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamOpFlag);
	return mapToObj(mapper, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT);
}

$IntStream* DoublePipeline::mapToInt($DoubleToIntFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($IntStream, $new($DoublePipeline$3, this, this, $StreamShape::DOUBLE_VALUE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$LongStream* DoublePipeline::mapToLong($DoubleToLongFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($DoublePipeline$4, this, this, $StreamShape::DOUBLE_VALUE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$DoubleStream* DoublePipeline::flatMap($DoubleFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($DoublePipeline$5, this, this, $StreamShape::DOUBLE_VALUE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$DoubleStream* DoublePipeline::mapMulti($DoubleStream$DoubleMapMultiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($DoublePipeline$6, this, this, $StreamShape::DOUBLE_VALUE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$BaseStream* DoublePipeline::unordered() {
	if (!isOrdered()) {
		return static_cast<$BaseStream*>(static_cast<$AbstractPipeline*>(this));
	}
	$init($StreamShape);
	$init($StreamOpFlag);
	return static_cast<$BaseStream*>(static_cast<$AbstractPipeline*>(static_cast<DoublePipeline*>(static_cast<$DoublePipeline$StatelessOp*>($new($DoublePipeline$7, this, this, $StreamShape::DOUBLE_VALUE, $StreamOpFlag::NOT_ORDERED)))));
}

$DoubleStream* DoublePipeline::filter($DoublePredicate* predicate) {
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($DoublePipeline$8, this, this, $StreamShape::DOUBLE_VALUE, $StreamOpFlag::NOT_SIZED, predicate));
}

$DoubleStream* DoublePipeline::peek($DoubleConsumer* action) {
	$Objects::requireNonNull(action);
	$init($StreamShape);
	return $as($DoubleStream, $new($DoublePipeline$9, this, this, $StreamShape::DOUBLE_VALUE, 0, action));
}

$DoubleStream* DoublePipeline::limit(int64_t maxSize) {
	if (maxSize < 0) {
		$throwNew($IllegalArgumentException, $($Long::toString(maxSize)));
	}
	return $SliceOps::makeDouble(this, (int64_t)0, maxSize);
}

$DoubleStream* DoublePipeline::skip(int64_t n) {
	if (n < 0) {
		$throwNew($IllegalArgumentException, $($Long::toString(n)));
	}
	if (n == 0) {
		return $as($DoubleStream, this);
	} else {
		int64_t limit = -1;
		return $SliceOps::makeDouble(this, n, limit);
	}
}

$DoubleStream* DoublePipeline::takeWhile($DoublePredicate* predicate) {
	return $WhileOps::makeTakeWhileDouble(this, predicate);
}

$DoubleStream* DoublePipeline::dropWhile($DoublePredicate* predicate) {
	return $WhileOps::makeDropWhileDouble(this, predicate);
}

$DoubleStream* DoublePipeline::sorted() {
	return $SortedOps::makeDouble(this);
}

$DoubleStream* DoublePipeline::distinct() {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($(boxed()))->distinct()))->mapToDouble(static_cast<$ToDoubleFunction*>($$new(DoublePipeline$$Lambda$lambda$distinct$0$2)));
}

void DoublePipeline::forEach($DoubleConsumer* consumer) {
	evaluate($($ForEachOps::makeDouble(consumer, false)));
}

void DoublePipeline::forEachOrdered($DoubleConsumer* consumer) {
	evaluate($($ForEachOps::makeDouble(consumer, true)));
}

double DoublePipeline::sum() {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(DoublePipeline$$Lambda$lambda$sum$1$3)));
	$var($ObjDoubleConsumer, var$1, static_cast<$ObjDoubleConsumer*>($new(DoublePipeline$$Lambda$lambda$sum$2$4)));
	$var($doubles, summation, $cast($doubles, collect(var$0, var$1, static_cast<$BiConsumer*>($$new(DoublePipeline$$Lambda$lambda$sum$3$5)))));
	return $Collectors::computeFinalSum(summation);
}

$OptionalDouble* DoublePipeline::min() {
	return reduce(static_cast<$DoubleBinaryOperator*>($$new(DoublePipeline$$Lambda$min$6)));
}

$OptionalDouble* DoublePipeline::max() {
	return reduce(static_cast<$DoubleBinaryOperator*>($$new(DoublePipeline$$Lambda$max$7)));
}

$OptionalDouble* DoublePipeline::average() {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(DoublePipeline$$Lambda$lambda$average$4$8)));
	$var($ObjDoubleConsumer, var$1, static_cast<$ObjDoubleConsumer*>($new(DoublePipeline$$Lambda$lambda$average$5$9)));
	$var($doubles, avg, $cast($doubles, collect(var$0, var$1, static_cast<$BiConsumer*>($$new(DoublePipeline$$Lambda$lambda$average$6$10)))));
	return $nc(avg)->get(2) > 0 ? $OptionalDouble::of($Collectors::computeFinalSum(avg) / $nc(avg)->get(2)) : $OptionalDouble::empty();
}

int64_t DoublePipeline::count() {
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Long, $(evaluate($($ReduceOps::makeDoubleCounting()))))))->longValue();
}

$DoubleSummaryStatistics* DoublePipeline::summaryStatistics() {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(DoublePipeline$$Lambda$DoubleSummaryStatistics$11)));
	$var($ObjDoubleConsumer, var$1, static_cast<$ObjDoubleConsumer*>($new(DoublePipeline$$Lambda$accept$12)));
	return $cast($DoubleSummaryStatistics, collect(var$0, var$1, static_cast<$BiConsumer*>($$new(DoublePipeline$$Lambda$combine$13))));
}

double DoublePipeline::reduce(double identity, $DoubleBinaryOperator* op) {
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Double, $(evaluate($($ReduceOps::makeDouble(identity, op)))))))->doubleValue();
}

$OptionalDouble* DoublePipeline::reduce($DoubleBinaryOperator* op) {
	return $cast($OptionalDouble, evaluate($($ReduceOps::makeDouble(op))));
}

$Object* DoublePipeline::collect($Supplier* supplier, $ObjDoubleConsumer* accumulator, $BiConsumer* combiner) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(combiner);
	$var($BinaryOperator, operator$, static_cast<$BinaryOperator*>($new(DoublePipeline$$Lambda$lambda$collect$7$14, combiner)));
	return $of(evaluate($($ReduceOps::makeDouble(supplier, accumulator, operator$))));
}

bool DoublePipeline::anyMatch($DoublePredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeDouble(predicate, $MatchOps$MatchKind::ANY)))))))->booleanValue();
}

bool DoublePipeline::allMatch($DoublePredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeDouble(predicate, $MatchOps$MatchKind::ALL)))))))->booleanValue();
}

bool DoublePipeline::noneMatch($DoublePredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeDouble(predicate, $MatchOps$MatchKind::NONE)))))))->booleanValue();
}

$OptionalDouble* DoublePipeline::findFirst() {
	return $cast($OptionalDouble, evaluate($($FindOps::makeDouble(true))));
}

$OptionalDouble* DoublePipeline::findAny() {
	return $cast($OptionalDouble, evaluate($($FindOps::makeDouble(false))));
}

$doubles* DoublePipeline::toArray() {
	$useLocalCurrentObjectStackCache();
	return $cast($doubles, $nc($($Nodes::flattenDouble($cast($Node$OfDouble, $(evaluateToArrayNode(static_cast<$IntFunction*>($$new(DoublePipeline$$Lambda$lambda$toArray$8$15))))))))->asPrimitiveArray());
}

$BaseStream* DoublePipeline::parallel() {
	return $cast($DoubleStream, $AbstractPipeline::parallel());
}

$BaseStream* DoublePipeline::sequential() {
	return $cast($DoubleStream, $AbstractPipeline::sequential());
}

$DoubleArray* DoublePipeline::lambda$toArray$8(int32_t x$0) {
	$init(DoublePipeline);
	return $new($DoubleArray, x$0);
}

$Object* DoublePipeline::lambda$collect$7($BiConsumer* combiner, Object$* left, Object$* right) {
	$init(DoublePipeline);
	$nc(combiner)->accept(left, right);
	return $of(left);
}

void DoublePipeline::lambda$average$6($doubles* ll, $doubles* rr) {
	$init(DoublePipeline);
	$Collectors::sumWithCompensation(ll, $nc(rr)->get(0));
	$Collectors::sumWithCompensation(ll, $nc(rr)->get(1));
	(*$nc(ll))[2] += $nc(rr)->get(2);
	(*ll)[3] += rr->get(3);
}

void DoublePipeline::lambda$average$5($doubles* ll, double d) {
	$init(DoublePipeline);
	++(*$nc(ll))[2];
	$Collectors::sumWithCompensation(ll, d);
	(*ll)[3] += d;
}

$doubles* DoublePipeline::lambda$average$4() {
	$init(DoublePipeline);
	return $new($doubles, 4);
}

void DoublePipeline::lambda$sum$3($doubles* ll, $doubles* rr) {
	$init(DoublePipeline);
	$Collectors::sumWithCompensation(ll, $nc(rr)->get(0));
	$Collectors::sumWithCompensation(ll, $nc(rr)->get(1));
	(*$nc(ll))[2] += $nc(rr)->get(2);
}

void DoublePipeline::lambda$sum$2($doubles* ll, double d) {
	$init(DoublePipeline);
	$Collectors::sumWithCompensation(ll, d);
	(*$nc(ll))[2] += d;
}

$doubles* DoublePipeline::lambda$sum$1() {
	$init(DoublePipeline);
	return $new($doubles, 3);
}

double DoublePipeline::lambda$distinct$0($Double* i) {
	$init(DoublePipeline);
	return $nc(i)->doubleValue();
}

DoublePipeline::DoublePipeline() {
}

$Class* DoublePipeline::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DoublePipeline$$Lambda$accept::classInfo$.name)) {
			return DoublePipeline$$Lambda$accept::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$valueOf$1::classInfo$.name)) {
			return DoublePipeline$$Lambda$valueOf$1::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$distinct$0$2::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$distinct$0$2::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$sum$1$3::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$sum$1$3::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$sum$2$4::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$sum$2$4::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$sum$3$5::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$sum$3$5::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$min$6::classInfo$.name)) {
			return DoublePipeline$$Lambda$min$6::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$max$7::classInfo$.name)) {
			return DoublePipeline$$Lambda$max$7::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$average$4$8::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$average$4$8::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$average$5$9::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$average$5$9::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$average$6$10::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$average$6$10::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$DoubleSummaryStatistics$11::classInfo$.name)) {
			return DoublePipeline$$Lambda$DoubleSummaryStatistics$11::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$accept$12::classInfo$.name)) {
			return DoublePipeline$$Lambda$accept$12::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$combine$13::classInfo$.name)) {
			return DoublePipeline$$Lambda$combine$13::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$collect$7$14::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$collect$7$14::load$(name, initialize);
		}
		if (name->equals(DoublePipeline$$Lambda$lambda$toArray$8$15::classInfo$.name)) {
			return DoublePipeline$$Lambda$lambda$toArray$8$15::load$(name, initialize);
		}
	}
	$loadClass(DoublePipeline, name, initialize, &_DoublePipeline_ClassInfo_, allocate$DoublePipeline);
	return class$;
}

$Class* DoublePipeline::class$ = nullptr;

		} // stream
	} // util
} // java