#include <java/util/stream/LongPipeline.h>

#include <java/io/Serializable.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Iterator.h>
#include <java/util/LongSummaryStatistics.h>
#include <java/util/Objects.h>
#include <java/util/OptionalDouble.h>
#include <java/util/OptionalLong.h>
#include <java/util/PrimitiveIterator$OfLong.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/LongBinaryOperator.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/function/LongFunction.h>
#include <java/util/function/LongPredicate.h>
#include <java/util/function/LongToDoubleFunction.h>
#include <java/util/function/LongToIntFunction.h>
#include <java/util/function/LongUnaryOperator.h>
#include <java/util/function/ObjLongConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/function/ToLongFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/FindOps.h>
#include <java/util/stream/ForEachOps.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongPipeline$1.h>
#include <java/util/stream/LongPipeline$10.h>
#include <java/util/stream/LongPipeline$2.h>
#include <java/util/stream/LongPipeline$3.h>
#include <java/util/stream/LongPipeline$4.h>
#include <java/util/stream/LongPipeline$5.h>
#include <java/util/stream/LongPipeline$6.h>
#include <java/util/stream/LongPipeline$7.h>
#include <java/util/stream/LongPipeline$8.h>
#include <java/util/stream/LongPipeline$9.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/LongStream$LongMapMultiConsumer.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/MatchOps$MatchKind.h>
#include <java/util/stream/MatchOps.h>
#include <java/util/stream/Node$Builder$OfLong.h>
#include <java/util/stream/Node$Builder.h>
#include <java/util/stream/Node$OfLong.h>
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
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfLong.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator$OfPrimitive.h>
#include <java/util/stream/StreamSpliterators$DelegatingSpliterator.h>
#include <java/util/stream/StreamSpliterators$LongWrappingSpliterator.h>
#include <java/util/stream/TerminalOp.h>
#include <java/util/stream/Tripwire.h>
#include <java/util/stream/WhileOps.h>
#include <jcpp.h>

#undef ALL
#undef ANY
#undef ENABLED
#undef LONG_VALUE
#undef NONE
#undef NOT_DISTINCT
#undef NOT_ORDERED
#undef NOT_SIZED
#undef NOT_SORTED

using $LongArray = $Array<::java::lang::Long>;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Iterator = ::java::util::Iterator;
using $LongSummaryStatistics = ::java::util::LongSummaryStatistics;
using $Objects = ::java::util::Objects;
using $OptionalDouble = ::java::util::OptionalDouble;
using $OptionalLong = ::java::util::OptionalLong;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Spliterators = ::java::util::Spliterators;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $IntFunction = ::java::util::function::IntFunction;
using $LongBinaryOperator = ::java::util::function::LongBinaryOperator;
using $LongConsumer = ::java::util::function::LongConsumer;
using $LongFunction = ::java::util::function::LongFunction;
using $LongPredicate = ::java::util::function::LongPredicate;
using $LongToDoubleFunction = ::java::util::function::LongToDoubleFunction;
using $LongToIntFunction = ::java::util::function::LongToIntFunction;
using $LongUnaryOperator = ::java::util::function::LongUnaryOperator;
using $ObjLongConsumer = ::java::util::function::ObjLongConsumer;
using $Supplier = ::java::util::function::Supplier;
using $ToLongFunction = ::java::util::function::ToLongFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $BaseStream = ::java::util::stream::BaseStream;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $FindOps = ::java::util::stream::FindOps;
using $ForEachOps = ::java::util::stream::ForEachOps;
using $IntStream = ::java::util::stream::IntStream;
using $LongPipeline$1 = ::java::util::stream::LongPipeline$1;
using $LongPipeline$10 = ::java::util::stream::LongPipeline$10;
using $LongPipeline$2 = ::java::util::stream::LongPipeline$2;
using $LongPipeline$3 = ::java::util::stream::LongPipeline$3;
using $LongPipeline$4 = ::java::util::stream::LongPipeline$4;
using $LongPipeline$5 = ::java::util::stream::LongPipeline$5;
using $LongPipeline$6 = ::java::util::stream::LongPipeline$6;
using $LongPipeline$7 = ::java::util::stream::LongPipeline$7;
using $LongPipeline$8 = ::java::util::stream::LongPipeline$8;
using $LongPipeline$9 = ::java::util::stream::LongPipeline$9;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $LongStream = ::java::util::stream::LongStream;
using $LongStream$LongMapMultiConsumer = ::java::util::stream::LongStream$LongMapMultiConsumer;
using $MatchOps = ::java::util::stream::MatchOps;
using $MatchOps$MatchKind = ::java::util::stream::MatchOps$MatchKind;
using $Node = ::java::util::stream::Node;
using $Node$Builder = ::java::util::stream::Node$Builder;
using $Node$OfLong = ::java::util::stream::Node$OfLong;
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
using $StreamSpliterators$DelegatingSpliterator$OfLong = ::java::util::stream::StreamSpliterators$DelegatingSpliterator$OfLong;
using $StreamSpliterators$DelegatingSpliterator$OfPrimitive = ::java::util::stream::StreamSpliterators$DelegatingSpliterator$OfPrimitive;
using $StreamSpliterators$LongWrappingSpliterator = ::java::util::stream::StreamSpliterators$LongWrappingSpliterator;
using $Tripwire = ::java::util::stream::Tripwire;
using $WhileOps = ::java::util::stream::WhileOps;

namespace java {
	namespace util {
		namespace stream {

class LongPipeline$$Lambda$accept : public $LongConsumer {
	$class(LongPipeline$$Lambda$accept, $NO_CLASS_INIT, $LongConsumer)
public:
	void init$($Sink* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t value) override {
		$nc(inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$accept>());
	}
	$Sink* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LongPipeline$$Lambda$accept::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LongPipeline$$Lambda$accept, inst$)},
	{}
};
$MethodInfo LongPipeline$$Lambda$accept::methodInfos[3] = {
	{"<init>", "(Ljava/util/stream/Sink;)V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$accept, init$, void, $Sink*)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$accept, accept, void, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$accept::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$accept",
	"java.lang.Object",
	"java.util.function.LongConsumer",
	fieldInfos,
	methodInfos
};
$Class* LongPipeline$$Lambda$accept::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$accept, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$accept::class$ = nullptr;

class LongPipeline$$Lambda$valueOf$1 : public $LongFunction {
	$class(LongPipeline$$Lambda$valueOf$1, $NO_CLASS_INIT, $LongFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int64_t l) override {
		 return $of($Long::valueOf(l));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$valueOf$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$valueOf$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$valueOf$1, init$, void)},
	{"apply", "(J)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$valueOf$1, apply, $Object*, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$valueOf$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$valueOf$1",
	"java.lang.Object",
	"java.util.function.LongFunction",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$valueOf$1::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$valueOf$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$valueOf$1::class$ = nullptr;

class LongPipeline$$Lambda$lambda$distinct$0$2 : public $ToLongFunction {
	$class(LongPipeline$$Lambda$lambda$distinct$0$2, $NO_CLASS_INIT, $ToLongFunction)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(Object$* i) override {
		 return LongPipeline::lambda$distinct$0($cast($Long, i));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$lambda$distinct$0$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$lambda$distinct$0$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$lambda$distinct$0$2, init$, void)},
	{"applyAsLong", "(Ljava/lang/Object;)J", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$lambda$distinct$0$2, applyAsLong, int64_t, Object$*)},
	{}
};
$ClassInfo LongPipeline$$Lambda$lambda$distinct$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$lambda$distinct$0$2",
	"java.lang.Object",
	"java.util.function.ToLongFunction",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$lambda$distinct$0$2::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$lambda$distinct$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$lambda$distinct$0$2::class$ = nullptr;

class LongPipeline$$Lambda$sum$3 : public $LongBinaryOperator {
	$class(LongPipeline$$Lambda$sum$3, $NO_CLASS_INIT, $LongBinaryOperator)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(int64_t a, int64_t b) override {
		 return $Long::sum(a, b);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$sum$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$sum$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$sum$3, init$, void)},
	{"applyAsLong", "(JJ)J", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$sum$3, applyAsLong, int64_t, int64_t, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$sum$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$sum$3",
	"java.lang.Object",
	"java.util.function.LongBinaryOperator",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$sum$3::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$sum$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$sum$3::class$ = nullptr;

class LongPipeline$$Lambda$min$4 : public $LongBinaryOperator {
	$class(LongPipeline$$Lambda$min$4, $NO_CLASS_INIT, $LongBinaryOperator)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(int64_t a, int64_t b) override {
		 return $Math::min(a, b);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$min$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$min$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$min$4, init$, void)},
	{"applyAsLong", "(JJ)J", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$min$4, applyAsLong, int64_t, int64_t, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$min$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$min$4",
	"java.lang.Object",
	"java.util.function.LongBinaryOperator",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$min$4::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$min$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$min$4::class$ = nullptr;

class LongPipeline$$Lambda$max$5 : public $LongBinaryOperator {
	$class(LongPipeline$$Lambda$max$5, $NO_CLASS_INIT, $LongBinaryOperator)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(int64_t a, int64_t b) override {
		 return $Math::max(a, b);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$max$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$max$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$max$5, init$, void)},
	{"applyAsLong", "(JJ)J", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$max$5, applyAsLong, int64_t, int64_t, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$max$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$max$5",
	"java.lang.Object",
	"java.util.function.LongBinaryOperator",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$max$5::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$max$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$max$5::class$ = nullptr;

class LongPipeline$$Lambda$lambda$average$1$6 : public $Supplier {
	$class(LongPipeline$$Lambda$lambda$average$1$6, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(LongPipeline::lambda$average$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$lambda$average$1$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$lambda$average$1$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$lambda$average$1$6, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$lambda$average$1$6, get, $Object*)},
	{}
};
$ClassInfo LongPipeline$$Lambda$lambda$average$1$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$lambda$average$1$6",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$lambda$average$1$6::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$lambda$average$1$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$lambda$average$1$6::class$ = nullptr;

class LongPipeline$$Lambda$lambda$average$2$7 : public $ObjLongConsumer {
	$class(LongPipeline$$Lambda$lambda$average$2$7, $NO_CLASS_INIT, $ObjLongConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* ll, int64_t i) override {
		LongPipeline::lambda$average$2($cast($longs, ll), i);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$lambda$average$2$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$lambda$average$2$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$lambda$average$2$7, init$, void)},
	{"accept", "(Ljava/lang/Object;J)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$lambda$average$2$7, accept, void, Object$*, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$lambda$average$2$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$lambda$average$2$7",
	"java.lang.Object",
	"java.util.function.ObjLongConsumer",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$lambda$average$2$7::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$lambda$average$2$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$lambda$average$2$7::class$ = nullptr;

class LongPipeline$$Lambda$lambda$average$3$8 : public $BiConsumer {
	$class(LongPipeline$$Lambda$lambda$average$3$8, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* ll, Object$* rr) override {
		LongPipeline::lambda$average$3($cast($longs, ll), $cast($longs, rr));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$lambda$average$3$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$lambda$average$3$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$lambda$average$3$8, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$lambda$average$3$8, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo LongPipeline$$Lambda$lambda$average$3$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$lambda$average$3$8",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$lambda$average$3$8::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$lambda$average$3$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$lambda$average$3$8::class$ = nullptr;

class LongPipeline$$Lambda$LongSummaryStatistics$9 : public $Supplier {
	$class(LongPipeline$$Lambda$LongSummaryStatistics$9, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($LongSummaryStatistics));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$LongSummaryStatistics$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$LongSummaryStatistics$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$LongSummaryStatistics$9, init$, void)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$LongSummaryStatistics$9, get, $Object*)},
	{}
};
$ClassInfo LongPipeline$$Lambda$LongSummaryStatistics$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$LongSummaryStatistics$9",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$LongSummaryStatistics$9::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$LongSummaryStatistics$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$LongSummaryStatistics$9::class$ = nullptr;

class LongPipeline$$Lambda$accept$10 : public $ObjLongConsumer {
	$class(LongPipeline$$Lambda$accept$10, $NO_CLASS_INIT, $ObjLongConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, int64_t value) override {
		$sure($LongSummaryStatistics, inst$)->accept(value);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$accept$10>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$accept$10::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$accept$10, init$, void)},
	{"accept", "(Ljava/lang/Object;J)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$accept$10, accept, void, Object$*, int64_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$accept$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$accept$10",
	"java.lang.Object",
	"java.util.function.ObjLongConsumer",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$accept$10::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$accept$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$accept$10::class$ = nullptr;

class LongPipeline$$Lambda$combine$11 : public $BiConsumer {
	$class(LongPipeline$$Lambda$combine$11, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$, Object$* other) override {
		$sure($LongSummaryStatistics, inst$)->combine($cast($LongSummaryStatistics, other));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$combine$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$combine$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$combine$11, init$, void)},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$combine$11, accept, void, Object$*, Object$*)},
	{}
};
$ClassInfo LongPipeline$$Lambda$combine$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$combine$11",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$combine$11::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$combine$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$combine$11::class$ = nullptr;

class LongPipeline$$Lambda$lambda$collect$4$12 : public $BinaryOperator {
	$class(LongPipeline$$Lambda$lambda$collect$4$12, $NO_CLASS_INIT, $BinaryOperator)
public:
	void init$($BiConsumer* combiner) {
		$set(this, combiner, combiner);
	}
	virtual $Object* apply(Object$* left, Object$* right) override {
		 return LongPipeline::lambda$collect$4(combiner, left, right);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$lambda$collect$4$12>());
	}
	$BiConsumer* combiner = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LongPipeline$$Lambda$lambda$collect$4$12::fieldInfos[2] = {
	{"combiner", "Ljava/util/function/BiConsumer;", nullptr, $PUBLIC, $field(LongPipeline$$Lambda$lambda$collect$4$12, combiner)},
	{}
};
$MethodInfo LongPipeline$$Lambda$lambda$collect$4$12::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiConsumer;)V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$lambda$collect$4$12, init$, void, $BiConsumer*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$lambda$collect$4$12, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo LongPipeline$$Lambda$lambda$collect$4$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$lambda$collect$4$12",
	"java.lang.Object",
	"java.util.function.BinaryOperator",
	fieldInfos,
	methodInfos
};
$Class* LongPipeline$$Lambda$lambda$collect$4$12::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$lambda$collect$4$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$lambda$collect$4$12::class$ = nullptr;

class LongPipeline$$Lambda$lambda$toArray$5$13 : public $IntFunction {
	$class(LongPipeline$$Lambda$lambda$toArray$5$13, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(LongPipeline::lambda$toArray$5(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LongPipeline$$Lambda$lambda$toArray$5$13>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LongPipeline$$Lambda$lambda$toArray$5$13::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LongPipeline$$Lambda$lambda$toArray$5$13, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LongPipeline$$Lambda$lambda$toArray$5$13, apply, $Object*, int32_t)},
	{}
};
$ClassInfo LongPipeline$$Lambda$lambda$toArray$5$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.LongPipeline$$Lambda$lambda$toArray$5$13",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* LongPipeline$$Lambda$lambda$toArray$5$13::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$$Lambda$lambda$toArray$5$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LongPipeline$$Lambda$lambda$toArray$5$13::class$ = nullptr;

$MethodInfo _LongPipeline_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/function/Supplier;IZ)V", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator<Ljava/lang/Long;>;>;IZ)V", 0, $method(LongPipeline, init$, void, $Supplier*, int32_t, bool)},
	{"<init>", "(Ljava/util/Spliterator;IZ)V", "(Ljava/util/Spliterator<Ljava/lang/Long;>;IZ)V", 0, $method(LongPipeline, init$, void, $Spliterator*, int32_t, bool)},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;I)V", "(Ljava/util/stream/AbstractPipeline<*TE_IN;*>;I)V", 0, $method(LongPipeline, init$, void, $AbstractPipeline*, int32_t)},
	{"adapt", "(Ljava/util/stream/Sink;)Ljava/util/function/LongConsumer;", "(Ljava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/function/LongConsumer;", $PRIVATE | $STATIC, $staticMethod(LongPipeline, adapt, $LongConsumer*, $Sink*)},
	{"adapt", "(Ljava/util/Spliterator;)Ljava/util/Spliterator$OfLong;", "(Ljava/util/Spliterator<Ljava/lang/Long;>;)Ljava/util/Spliterator$OfLong;", $PRIVATE | $STATIC, $staticMethod(LongPipeline, adapt, $Spliterator$OfLong*, $Spliterator*)},
	{"allMatch", "(Ljava/util/function/LongPredicate;)Z", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, allMatch, bool, $LongPredicate*)},
	{"anyMatch", "(Ljava/util/function/LongPredicate;)Z", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, anyMatch, bool, $LongPredicate*)},
	{"asDoubleStream", "()Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, asDoubleStream, $DoubleStream*)},
	{"average", "()Ljava/util/OptionalDouble;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, average, $OptionalDouble*)},
	{"boxed", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/Long;>;", $PUBLIC | $FINAL, $method(LongPipeline, boxed, $Stream*)},
	{"collect", "(Ljava/util/function/Supplier;Ljava/util/function/ObjLongConsumer;Ljava/util/function/BiConsumer;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjLongConsumer<TR;>;Ljava/util/function/BiConsumer<TR;TR;>;)TR;", $PUBLIC | $FINAL, $method(LongPipeline, collect, $Object*, $Supplier*, $ObjLongConsumer*, $BiConsumer*)},
	{"count", "()J", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, count, int64_t)},
	{"distinct", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, distinct, $LongStream*)},
	{"dropWhile", "(Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, dropWhile, $LongStream*, $LongPredicate*)},
	{"evaluateToNode", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;ZLjava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;ZLjava/util/function/IntFunction<[Ljava/lang/Long;>;)Ljava/util/stream/Node<Ljava/lang/Long;>;", $FINAL, $virtualMethod(LongPipeline, evaluateToNode, $Node*, $PipelineHelper*, $Spliterator*, bool, $IntFunction*)},
	{"filter", "(Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, filter, $LongStream*, $LongPredicate*)},
	{"findAny", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, findAny, $OptionalLong*)},
	{"findFirst", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, findFirst, $OptionalLong*)},
	{"flatMap", "(Ljava/util/function/LongFunction;)Ljava/util/stream/LongStream;", "(Ljava/util/function/LongFunction<+Ljava/util/stream/LongStream;>;)Ljava/util/stream/LongStream;", $PUBLIC | $FINAL, $method(LongPipeline, flatMap, $LongStream*, $LongFunction*)},
	{"forEach", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline, forEach, void, $LongConsumer*)},
	{"forEachOrdered", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $virtualMethod(LongPipeline, forEachOrdered, void, $LongConsumer*)},
	{"forEachWithCancel", "(Ljava/util/Spliterator;Ljava/util/stream/Sink;)Z", "(Ljava/util/Spliterator<Ljava/lang/Long;>;Ljava/util/stream/Sink<Ljava/lang/Long;>;)Z", $FINAL, $virtualMethod(LongPipeline, forEachWithCancel, bool, $Spliterator*, $Sink*)},
	{"getOutputShape", "()Ljava/util/stream/StreamShape;", nullptr, $FINAL, $virtualMethod(LongPipeline, getOutputShape, $StreamShape*)},
	{"*isParallel", "()Z", nullptr, $PUBLIC | $FINAL},
	{"iterator", "()Ljava/util/PrimitiveIterator$OfLong;", nullptr, $PUBLIC | $FINAL, $virtualMethod(LongPipeline, iterator, $Iterator*)},
	{"lambda$average$1", "()[J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongPipeline, lambda$average$1, $longs*)},
	{"lambda$average$2", "([JJ)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongPipeline, lambda$average$2, void, $longs*, int64_t)},
	{"lambda$average$3", "([J[J)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongPipeline, lambda$average$3, void, $longs*, $longs*)},
	{"lambda$collect$4", "(Ljava/util/function/BiConsumer;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongPipeline, lambda$collect$4, $Object*, $BiConsumer*, Object$*, Object$*)},
	{"lambda$distinct$0", "(Ljava/lang/Long;)J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongPipeline, lambda$distinct$0, int64_t, $Long*)},
	{"lambda$toArray$5", "(I)[Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LongPipeline, lambda$toArray$5, $LongArray*, int32_t)},
	{"lazySpliterator", "(Ljava/util/function/Supplier;)Ljava/util/Spliterator$OfLong;", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator<Ljava/lang/Long;>;>;)Ljava/util/Spliterator$OfLong;", $FINAL, $virtualMethod(LongPipeline, lazySpliterator, $Spliterator*, $Supplier*)},
	{"limit", "(J)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, limit, $LongStream*, int64_t)},
	{"makeNodeBuilder", "(JLjava/util/function/IntFunction;)Ljava/util/stream/Node$Builder;", "(JLjava/util/function/IntFunction<[Ljava/lang/Long;>;)Ljava/util/stream/Node$Builder<Ljava/lang/Long;>;", $FINAL, $virtualMethod(LongPipeline, makeNodeBuilder, $Node$Builder*, int64_t, $IntFunction*)},
	{"map", "(Ljava/util/function/LongUnaryOperator;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, map, $LongStream*, $LongUnaryOperator*)},
	{"mapMulti", "(Ljava/util/stream/LongStream$LongMapMultiConsumer;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, mapMulti, $LongStream*, $LongStream$LongMapMultiConsumer*)},
	{"mapToDouble", "(Ljava/util/function/LongToDoubleFunction;)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, mapToDouble, $DoubleStream*, $LongToDoubleFunction*)},
	{"mapToInt", "(Ljava/util/function/LongToIntFunction;)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, mapToInt, $IntStream*, $LongToIntFunction*)},
	{"mapToObj", "(Ljava/util/function/LongFunction;I)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/LongFunction<+TU;>;I)Ljava/util/stream/Stream<TU;>;", $PRIVATE, $method(LongPipeline, mapToObj, $Stream*, $LongFunction*, int32_t)},
	{"mapToObj", "(Ljava/util/function/LongFunction;)Ljava/util/stream/Stream;", "<U:Ljava/lang/Object;>(Ljava/util/function/LongFunction<+TU;>;)Ljava/util/stream/Stream<TU;>;", $PUBLIC | $FINAL, $method(LongPipeline, mapToObj, $Stream*, $LongFunction*)},
	{"max", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, max, $OptionalLong*)},
	{"min", "()Ljava/util/OptionalLong;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, min, $OptionalLong*)},
	{"noneMatch", "(Ljava/util/function/LongPredicate;)Z", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, noneMatch, bool, $LongPredicate*)},
	{"*onClose", "(Ljava/lang/Runnable;)Ljava/util/stream/BaseStream;", nullptr, $PUBLIC},
	{"parallel", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(LongPipeline, parallel, $BaseStream*)},
	{"peek", "(Ljava/util/function/LongConsumer;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, peek, $LongStream*, $LongConsumer*)},
	{"reduce", "(JLjava/util/function/LongBinaryOperator;)J", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, reduce, int64_t, int64_t, $LongBinaryOperator*)},
	{"reduce", "(Ljava/util/function/LongBinaryOperator;)Ljava/util/OptionalLong;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, reduce, $OptionalLong*, $LongBinaryOperator*)},
	{"sequential", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(LongPipeline, sequential, $BaseStream*)},
	{"skip", "(J)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, skip, $LongStream*, int64_t)},
	{"sorted", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, sorted, $LongStream*)},
	{"spliterator", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC | $FINAL, $virtualMethod(LongPipeline, spliterator, $Spliterator*)},
	{"sum", "()J", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, sum, int64_t)},
	{"summaryStatistics", "()Ljava/util/LongSummaryStatistics;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, summaryStatistics, $LongSummaryStatistics*)},
	{"takeWhile", "(Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, takeWhile, $LongStream*, $LongPredicate*)},
	{"toArray", "()[J", nullptr, $PUBLIC | $FINAL, $method(LongPipeline, toArray, $longs*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unordered", "()Ljava/util/stream/LongStream;", nullptr, $PUBLIC, $virtualMethod(LongPipeline, unordered, $BaseStream*)},
	{"wrap", "(Ljava/util/stream/PipelineHelper;Ljava/util/function/Supplier;Z)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/function/Supplier<Ljava/util/Spliterator<TP_IN;>;>;Z)Ljava/util/Spliterator<Ljava/lang/Long;>;", $FINAL, $virtualMethod(LongPipeline, wrap, $Spliterator*, $PipelineHelper*, $Supplier*, bool)},
	{}
};

$InnerClassInfo _LongPipeline_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$StatefulOp", "java.util.stream.LongPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$Head", "java.util.stream.LongPipeline", "Head", $STATIC},
	{"java.util.stream.LongPipeline$10", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$9", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$8", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$7", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$6", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.stream.LongPipeline",
	"java.util.stream.AbstractPipeline",
	"java.util.stream.LongStream",
	nullptr,
	_LongPipeline_MethodInfo_,
	"<E_IN:Ljava/lang/Object;>Ljava/util/stream/AbstractPipeline<TE_IN;Ljava/lang/Long;Ljava/util/stream/LongStream;>;Ljava/util/stream/LongStream;",
	nullptr,
	_LongPipeline_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline$StatefulOp,java.util.stream.LongPipeline$StatelessOp,java.util.stream.LongPipeline$Head,java.util.stream.LongPipeline$10,java.util.stream.LongPipeline$10$1,java.util.stream.LongPipeline$9,java.util.stream.LongPipeline$9$1,java.util.stream.LongPipeline$8,java.util.stream.LongPipeline$7,java.util.stream.LongPipeline$7$1,java.util.stream.LongPipeline$6,java.util.stream.LongPipeline$6$1,java.util.stream.LongPipeline$5,java.util.stream.LongPipeline$5$1,java.util.stream.LongPipeline$4,java.util.stream.LongPipeline$4$1,java.util.stream.LongPipeline$3,java.util.stream.LongPipeline$3$1,java.util.stream.LongPipeline$2,java.util.stream.LongPipeline$2$1,java.util.stream.LongPipeline$1,java.util.stream.LongPipeline$1$1"
};

$Object* allocate$LongPipeline($Class* clazz) {
	return $of($alloc(LongPipeline));
}

void LongPipeline::close() {
	this->$AbstractPipeline::close();
}

$BaseStream* LongPipeline::onClose($Runnable* closeHandler) {
	 return this->$AbstractPipeline::onClose(closeHandler);
}

bool LongPipeline::isParallel() {
	 return this->$AbstractPipeline::isParallel();
}

int32_t LongPipeline::hashCode() {
	 return this->$AbstractPipeline::hashCode();
}

bool LongPipeline::equals(Object$* obj) {
	 return this->$AbstractPipeline::equals(obj);
}

$Object* LongPipeline::clone() {
	 return this->$AbstractPipeline::clone();
}

$String* LongPipeline::toString() {
	 return this->$AbstractPipeline::toString();
}

void LongPipeline::finalize() {
	this->$AbstractPipeline::finalize();
}

LongPipeline::MemberClass0$::MemberClass0$() {
	$patchMemberClass(LongPipeline, $LongStream, memberClass0$);
}

$LongStream* LongPipeline::MemberClass0$::filter($LongPredicate* predicate) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->filter(predicate);
}

$LongStream* LongPipeline::MemberClass0$::map($LongUnaryOperator* mapper) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->map(mapper);
}

$Stream* LongPipeline::MemberClass0$::mapToObj($LongFunction* mapper) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->mapToObj(mapper);
}

$IntStream* LongPipeline::MemberClass0$::mapToInt($LongToIntFunction* mapper) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->mapToInt(mapper);
}

$DoubleStream* LongPipeline::MemberClass0$::mapToDouble($LongToDoubleFunction* mapper) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->mapToDouble(mapper);
}

$LongStream* LongPipeline::MemberClass0$::flatMap($LongFunction* mapper) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->flatMap(mapper);
}

$LongStream* LongPipeline::MemberClass0$::mapMulti($LongStream$LongMapMultiConsumer* mapper) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->mapMulti(mapper);
}

$LongStream* LongPipeline::MemberClass0$::distinct() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->distinct();
}

$LongStream* LongPipeline::MemberClass0$::sorted() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->sorted();
}

$LongStream* LongPipeline::MemberClass0$::peek($LongConsumer* action) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->peek(action);
}

$LongStream* LongPipeline::MemberClass0$::limit(int64_t maxSize) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->limit(maxSize);
}

$LongStream* LongPipeline::MemberClass0$::skip(int64_t n) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->skip(n);
}

$LongStream* LongPipeline::MemberClass0$::takeWhile($LongPredicate* predicate) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->takeWhile(predicate);
}

$LongStream* LongPipeline::MemberClass0$::dropWhile($LongPredicate* predicate) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->dropWhile(predicate);
}

void LongPipeline::MemberClass0$::forEach($LongConsumer* action) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->forEach(action);
}

void LongPipeline::MemberClass0$::forEachOrdered($LongConsumer* action) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->forEachOrdered(action);
}

$longs* LongPipeline::MemberClass0$::toArray() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->toArray();
}

int64_t LongPipeline::MemberClass0$::reduce(int64_t identity, $LongBinaryOperator* op) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->reduce(identity, op);
}

$OptionalLong* LongPipeline::MemberClass0$::reduce($LongBinaryOperator* op) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->reduce(op);
}

$Object* LongPipeline::MemberClass0$::collect($Supplier* supplier, $ObjLongConsumer* accumulator, $BiConsumer* combiner) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->collect(supplier, accumulator, combiner);
}

int64_t LongPipeline::MemberClass0$::sum() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->sum();
}

$OptionalLong* LongPipeline::MemberClass0$::min() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->min();
}

$OptionalLong* LongPipeline::MemberClass0$::max() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->max();
}

int64_t LongPipeline::MemberClass0$::count() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->count();
}

$OptionalDouble* LongPipeline::MemberClass0$::average() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->average();
}

$LongSummaryStatistics* LongPipeline::MemberClass0$::summaryStatistics() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->summaryStatistics();
}

bool LongPipeline::MemberClass0$::anyMatch($LongPredicate* predicate) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->anyMatch(predicate);
}

bool LongPipeline::MemberClass0$::allMatch($LongPredicate* predicate) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->allMatch(predicate);
}

bool LongPipeline::MemberClass0$::noneMatch($LongPredicate* predicate) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->noneMatch(predicate);
}

$OptionalLong* LongPipeline::MemberClass0$::findFirst() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->findFirst();
}

$OptionalLong* LongPipeline::MemberClass0$::findAny() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->findAny();
}

$DoubleStream* LongPipeline::MemberClass0$::asDoubleStream() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->asDoubleStream();
}

$Stream* LongPipeline::MemberClass0$::boxed() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->boxed();
}

$LongStream* LongPipeline::MemberClass0$::sequential() {
	return $cast($LongStream, ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->sequential());
}

$LongStream* LongPipeline::MemberClass0$::parallel() {
	return $cast($LongStream, ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->parallel());
}

$Iterator* LongPipeline::MemberClass0$::iterator() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->iterator();
}

$Spliterator* LongPipeline::MemberClass0$::spliterator() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->spliterator();
}

bool LongPipeline::MemberClass0$::isParallel() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->isParallel();
}

$BaseStream* LongPipeline::MemberClass0$::unordered() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->unordered();
}

$BaseStream* LongPipeline::MemberClass0$::onClose($Runnable* closeHandler) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->onClose(closeHandler);
}

void LongPipeline::MemberClass0$::close() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->close();
}

int32_t LongPipeline::MemberClass0$::hashCode() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->hashCode();
}

bool LongPipeline::MemberClass0$::equals(Object$* obj) {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->equals(obj);
}

$Object* LongPipeline::MemberClass0$::clone() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->clone();
}

$String* LongPipeline::MemberClass0$::toString() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->toString();
}

void LongPipeline::MemberClass0$::finalize() {
	return ((LongPipeline*)(void*)((int8_t*)(void*)this - $offsetof(LongPipeline, memberClass0$)))->finalize();
}

void LongPipeline::init$($Supplier* source, int32_t sourceFlags, bool parallel) {
	$AbstractPipeline::init$(source, sourceFlags, parallel);
}

void LongPipeline::init$($Spliterator* source, int32_t sourceFlags, bool parallel) {
	$AbstractPipeline::init$(source, sourceFlags, parallel);
}

void LongPipeline::init$($AbstractPipeline* upstream, int32_t opFlags) {
	$AbstractPipeline::init$(upstream, opFlags);
}

$LongConsumer* LongPipeline::adapt($Sink* sink) {
	$init(LongPipeline);
	if ($instanceOf($LongConsumer, sink)) {
		return $cast($LongConsumer, sink);
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$load($AbstractPipeline);
			$Tripwire::trip($AbstractPipeline::class$, "using LongStream.adapt(Sink<Long> s)"_s);
		}
		return static_cast<$LongConsumer*>($new(LongPipeline$$Lambda$accept, static_cast<$Sink*>($nc(sink))));
	}
}

$Spliterator$OfLong* LongPipeline::adapt($Spliterator* s) {
	$init(LongPipeline);
	if ($instanceOf($Spliterator$OfLong, s)) {
		return $cast($Spliterator$OfLong, s);
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$load($AbstractPipeline);
			$Tripwire::trip($AbstractPipeline::class$, "using LongStream.adapt(Spliterator<Long> s)"_s);
		}
		$throwNew($UnsupportedOperationException, "LongStream.adapt(Spliterator<Long> s)"_s);
	}
}

$StreamShape* LongPipeline::getOutputShape() {
	$init($StreamShape);
	return $StreamShape::LONG_VALUE;
}

$Node* LongPipeline::evaluateToNode($PipelineHelper* helper, $Spliterator* spliterator, bool flattenTree, $IntFunction* generator) {
	return $Nodes::collectLong(helper, spliterator, flattenTree);
}

$Spliterator* LongPipeline::wrap($PipelineHelper* ph, $Supplier* supplier, bool isParallel) {
	return static_cast<$Spliterator*>(static_cast<$StreamSpliterators$AbstractWrappingSpliterator*>($new($StreamSpliterators$LongWrappingSpliterator, ph, supplier, isParallel)));
}

$Spliterator* LongPipeline::lazySpliterator($Supplier* supplier) {
	return static_cast<$Spliterator*>(static_cast<$StreamSpliterators$DelegatingSpliterator*>(static_cast<$StreamSpliterators$DelegatingSpliterator$OfPrimitive*>($new($StreamSpliterators$DelegatingSpliterator$OfLong, supplier))));
}

bool LongPipeline::forEachWithCancel($Spliterator* spliterator, $Sink* sink) {
	$useLocalCurrentObjectStackCache();
	$var($Spliterator$OfLong, spl, adapt(spliterator));
	$var($LongConsumer, adaptedSink, adapt(sink));
	bool cancelled = false;
	bool var$0 = false;
	do {
		var$0 = !(cancelled = $nc(sink)->cancellationRequested());
	} while (var$0 && $nc(spl)->tryAdvance(adaptedSink));
	return cancelled;
}

$Node$Builder* LongPipeline::makeNodeBuilder(int64_t exactSizeIfKnown, $IntFunction* generator) {
	return $Nodes::longBuilder(exactSizeIfKnown);
}

$Stream* LongPipeline::mapToObj($LongFunction* mapper, int32_t opFlags) {
	$init($StreamShape);
	return $new($LongPipeline$1, this, this, $StreamShape::LONG_VALUE, opFlags, mapper);
}

$Iterator* LongPipeline::iterator() {
	return $Spliterators::iterator($($cast($Spliterator$OfLong, spliterator())));
}

$Spliterator* LongPipeline::spliterator() {
	return adapt($($AbstractPipeline::spliterator()));
}

$DoubleStream* LongPipeline::asDoubleStream() {
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($LongPipeline$2, this, this, $StreamShape::LONG_VALUE, $StreamOpFlag::NOT_DISTINCT));
}

$Stream* LongPipeline::boxed() {
	return mapToObj(static_cast<$LongFunction*>($$new(LongPipeline$$Lambda$valueOf$1)), 0);
}

$LongStream* LongPipeline::map($LongUnaryOperator* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($LongPipeline$3, this, this, $StreamShape::LONG_VALUE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$Stream* LongPipeline::mapToObj($LongFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamOpFlag);
	return mapToObj(mapper, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT);
}

$IntStream* LongPipeline::mapToInt($LongToIntFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($IntStream, $new($LongPipeline$4, this, this, $StreamShape::LONG_VALUE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$DoubleStream* LongPipeline::mapToDouble($LongToDoubleFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($DoubleStream, $new($LongPipeline$5, this, this, $StreamShape::LONG_VALUE, $StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT, mapper));
}

$LongStream* LongPipeline::flatMap($LongFunction* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($LongPipeline$6, this, this, $StreamShape::LONG_VALUE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$LongStream* LongPipeline::mapMulti($LongStream$LongMapMultiConsumer* mapper) {
	$Objects::requireNonNull(mapper);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($LongPipeline$7, this, this, $StreamShape::LONG_VALUE, ($StreamOpFlag::NOT_SORTED | $StreamOpFlag::NOT_DISTINCT) | $StreamOpFlag::NOT_SIZED, mapper));
}

$BaseStream* LongPipeline::unordered() {
	if (!isOrdered()) {
		return static_cast<$BaseStream*>(static_cast<$AbstractPipeline*>(this));
	}
	$init($StreamShape);
	$init($StreamOpFlag);
	return static_cast<$BaseStream*>(static_cast<$AbstractPipeline*>(static_cast<LongPipeline*>(static_cast<$LongPipeline$StatelessOp*>($new($LongPipeline$8, this, this, $StreamShape::LONG_VALUE, $StreamOpFlag::NOT_ORDERED)))));
}

$LongStream* LongPipeline::filter($LongPredicate* predicate) {
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	$init($StreamOpFlag);
	return $as($LongStream, $new($LongPipeline$9, this, this, $StreamShape::LONG_VALUE, $StreamOpFlag::NOT_SIZED, predicate));
}

$LongStream* LongPipeline::peek($LongConsumer* action) {
	$Objects::requireNonNull(action);
	$init($StreamShape);
	return $as($LongStream, $new($LongPipeline$10, this, this, $StreamShape::LONG_VALUE, 0, action));
}

$LongStream* LongPipeline::limit(int64_t maxSize) {
	if (maxSize < 0) {
		$throwNew($IllegalArgumentException, $($Long::toString(maxSize)));
	}
	return $SliceOps::makeLong(this, 0, maxSize);
}

$LongStream* LongPipeline::skip(int64_t n) {
	if (n < 0) {
		$throwNew($IllegalArgumentException, $($Long::toString(n)));
	}
	if (n == 0) {
		return $as($LongStream, this);
	} else {
		return $SliceOps::makeLong(this, n, -1);
	}
}

$LongStream* LongPipeline::takeWhile($LongPredicate* predicate) {
	return $WhileOps::makeTakeWhileLong(this, predicate);
}

$LongStream* LongPipeline::dropWhile($LongPredicate* predicate) {
	return $WhileOps::makeDropWhileLong(this, predicate);
}

$LongStream* LongPipeline::sorted() {
	return $SortedOps::makeLong(this);
}

$LongStream* LongPipeline::distinct() {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($(boxed()))->distinct()))->mapToLong(static_cast<$ToLongFunction*>($$new(LongPipeline$$Lambda$lambda$distinct$0$2)));
}

void LongPipeline::forEach($LongConsumer* action) {
	evaluate($($ForEachOps::makeLong(action, false)));
}

void LongPipeline::forEachOrdered($LongConsumer* action) {
	evaluate($($ForEachOps::makeLong(action, true)));
}

int64_t LongPipeline::sum() {
	return reduce(0, static_cast<$LongBinaryOperator*>($$new(LongPipeline$$Lambda$sum$3)));
}

$OptionalLong* LongPipeline::min() {
	return reduce(static_cast<$LongBinaryOperator*>($$new(LongPipeline$$Lambda$min$4)));
}

$OptionalLong* LongPipeline::max() {
	return reduce(static_cast<$LongBinaryOperator*>($$new(LongPipeline$$Lambda$max$5)));
}

$OptionalDouble* LongPipeline::average() {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(LongPipeline$$Lambda$lambda$average$1$6)));
	$var($ObjLongConsumer, var$1, static_cast<$ObjLongConsumer*>($new(LongPipeline$$Lambda$lambda$average$2$7)));
	$var($longs, avg, $cast($longs, collect(var$0, var$1, static_cast<$BiConsumer*>($$new(LongPipeline$$Lambda$lambda$average$3$8)))));
	return $nc(avg)->get(0) > 0 ? $OptionalDouble::of((double)$nc(avg)->get(1) / avg->get(0)) : $OptionalDouble::empty();
}

int64_t LongPipeline::count() {
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Long, $(evaluate($($ReduceOps::makeLongCounting()))))))->longValue();
}

$LongSummaryStatistics* LongPipeline::summaryStatistics() {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, var$0, static_cast<$Supplier*>($new(LongPipeline$$Lambda$LongSummaryStatistics$9)));
	$var($ObjLongConsumer, var$1, static_cast<$ObjLongConsumer*>($new(LongPipeline$$Lambda$accept$10)));
	return $cast($LongSummaryStatistics, collect(var$0, var$1, static_cast<$BiConsumer*>($$new(LongPipeline$$Lambda$combine$11))));
}

int64_t LongPipeline::reduce(int64_t identity, $LongBinaryOperator* op) {
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Long, $(evaluate($($ReduceOps::makeLong(identity, op)))))))->longValue();
}

$OptionalLong* LongPipeline::reduce($LongBinaryOperator* op) {
	return $cast($OptionalLong, evaluate($($ReduceOps::makeLong(op))));
}

$Object* LongPipeline::collect($Supplier* supplier, $ObjLongConsumer* accumulator, $BiConsumer* combiner) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(combiner);
	$var($BinaryOperator, operator$, static_cast<$BinaryOperator*>($new(LongPipeline$$Lambda$lambda$collect$4$12, combiner)));
	return $of(evaluate($($ReduceOps::makeLong(supplier, accumulator, operator$))));
}

bool LongPipeline::anyMatch($LongPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeLong(predicate, $MatchOps$MatchKind::ANY)))))))->booleanValue();
}

bool LongPipeline::allMatch($LongPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeLong(predicate, $MatchOps$MatchKind::ALL)))))))->booleanValue();
}

bool LongPipeline::noneMatch($LongPredicate* predicate) {
	$useLocalCurrentObjectStackCache();
	$init($MatchOps$MatchKind);
	return $nc(($cast($Boolean, $(evaluate($($MatchOps::makeLong(predicate, $MatchOps$MatchKind::NONE)))))))->booleanValue();
}

$OptionalLong* LongPipeline::findFirst() {
	return $cast($OptionalLong, evaluate($($FindOps::makeLong(true))));
}

$OptionalLong* LongPipeline::findAny() {
	return $cast($OptionalLong, evaluate($($FindOps::makeLong(false))));
}

$longs* LongPipeline::toArray() {
	$useLocalCurrentObjectStackCache();
	return $cast($longs, $nc($($Nodes::flattenLong($cast($Node$OfLong, $(evaluateToArrayNode(static_cast<$IntFunction*>($$new(LongPipeline$$Lambda$lambda$toArray$5$13))))))))->asPrimitiveArray());
}

$BaseStream* LongPipeline::parallel() {
	return $cast($LongStream, $AbstractPipeline::parallel());
}

$BaseStream* LongPipeline::sequential() {
	return $cast($LongStream, $AbstractPipeline::sequential());
}

$LongArray* LongPipeline::lambda$toArray$5(int32_t x$0) {
	$init(LongPipeline);
	return $new($LongArray, x$0);
}

$Object* LongPipeline::lambda$collect$4($BiConsumer* combiner, Object$* left, Object$* right) {
	$init(LongPipeline);
	$nc(combiner)->accept(left, right);
	return $of(left);
}

void LongPipeline::lambda$average$3($longs* ll, $longs* rr) {
	$init(LongPipeline);
	(*$nc(ll))[0] += $nc(rr)->get(0);
	(*ll)[1] += rr->get(1);
}

void LongPipeline::lambda$average$2($longs* ll, int64_t i) {
	$init(LongPipeline);
	++(*$nc(ll))[0];
	(*ll)[1] += i;
}

$longs* LongPipeline::lambda$average$1() {
	$init(LongPipeline);
	return $new($longs, 2);
}

int64_t LongPipeline::lambda$distinct$0($Long* i) {
	$init(LongPipeline);
	return $nc(i)->longValue();
}

LongPipeline::LongPipeline() {
}

$Class* LongPipeline::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LongPipeline$$Lambda$accept::classInfo$.name)) {
			return LongPipeline$$Lambda$accept::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$valueOf$1::classInfo$.name)) {
			return LongPipeline$$Lambda$valueOf$1::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$lambda$distinct$0$2::classInfo$.name)) {
			return LongPipeline$$Lambda$lambda$distinct$0$2::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$sum$3::classInfo$.name)) {
			return LongPipeline$$Lambda$sum$3::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$min$4::classInfo$.name)) {
			return LongPipeline$$Lambda$min$4::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$max$5::classInfo$.name)) {
			return LongPipeline$$Lambda$max$5::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$lambda$average$1$6::classInfo$.name)) {
			return LongPipeline$$Lambda$lambda$average$1$6::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$lambda$average$2$7::classInfo$.name)) {
			return LongPipeline$$Lambda$lambda$average$2$7::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$lambda$average$3$8::classInfo$.name)) {
			return LongPipeline$$Lambda$lambda$average$3$8::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$LongSummaryStatistics$9::classInfo$.name)) {
			return LongPipeline$$Lambda$LongSummaryStatistics$9::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$accept$10::classInfo$.name)) {
			return LongPipeline$$Lambda$accept$10::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$combine$11::classInfo$.name)) {
			return LongPipeline$$Lambda$combine$11::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$lambda$collect$4$12::classInfo$.name)) {
			return LongPipeline$$Lambda$lambda$collect$4$12::load$(name, initialize);
		}
		if (name->equals(LongPipeline$$Lambda$lambda$toArray$5$13::classInfo$.name)) {
			return LongPipeline$$Lambda$lambda$toArray$5$13::load$(name, initialize);
		}
	}
	$loadClass(LongPipeline, name, initialize, &_LongPipeline_ClassInfo_, allocate$LongPipeline);
	return class$;
}

$Class* LongPipeline::class$ = nullptr;

		} // stream
	} // util
} // java