#include <java/util/stream/WhileOps.h>

#include <java/util/Objects.h>
#include <java/util/function/DoublePredicate.h>
#include <java/util/function/IntPredicate.h>
#include <java/util/function/LongPredicate.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/WhileOps$1.h>
#include <java/util/stream/WhileOps$1Op.h>
#include <java/util/stream/WhileOps$2.h>
#include <java/util/stream/WhileOps$2Op.h>
#include <java/util/stream/WhileOps$3.h>
#include <java/util/stream/WhileOps$3Op.h>
#include <java/util/stream/WhileOps$4.h>
#include <java/util/stream/WhileOps$4Op.h>
#include <jcpp.h>

#undef DOUBLE_VALUE
#undef DROP_FLAGS
#undef INT_VALUE
#undef IS_SHORT_CIRCUIT
#undef LONG_VALUE
#undef NOT_SIZED
#undef REFERENCE
#undef TAKE_FLAGS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $IntPredicate = ::java::util::function::IntPredicate;
using $LongPredicate = ::java::util::function::LongPredicate;
using $Predicate = ::java::util::function::Predicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $Stream = ::java::util::stream::Stream;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $WhileOps$1 = ::java::util::stream::WhileOps$1;
using $WhileOps$1Op = ::java::util::stream::WhileOps$1Op;
using $WhileOps$2 = ::java::util::stream::WhileOps$2;
using $WhileOps$2Op = ::java::util::stream::WhileOps$2Op;
using $WhileOps$3 = ::java::util::stream::WhileOps$3;
using $WhileOps$3Op = ::java::util::stream::WhileOps$3Op;
using $WhileOps$4 = ::java::util::stream::WhileOps$4;
using $WhileOps$4Op = ::java::util::stream::WhileOps$4Op;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _WhileOps_FieldInfo_[] = {
	{"TAKE_FLAGS", "I", nullptr, $STATIC | $FINAL, $staticField(WhileOps, TAKE_FLAGS)},
	{"DROP_FLAGS", "I", nullptr, $STATIC | $FINAL, $staticField(WhileOps, DROP_FLAGS)},
	{}
};

$MethodInfo _WhileOps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(WhileOps, init$, void)},
	{"makeDropWhileDouble", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Double;*>;Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", $STATIC, $staticMethod(WhileOps, makeDropWhileDouble, $DoubleStream*, $AbstractPipeline*, $DoublePredicate*)},
	{"makeDropWhileInt", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Integer;*>;Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", $STATIC, $staticMethod(WhileOps, makeDropWhileInt, $IntStream*, $AbstractPipeline*, $IntPredicate*)},
	{"makeDropWhileLong", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Long;*>;Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", $STATIC, $staticMethod(WhileOps, makeDropWhileLong, $LongStream*, $AbstractPipeline*, $LongPredicate*)},
	{"makeDropWhileRef", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/stream/AbstractPipeline<*TT;*>;Ljava/util/function/Predicate<-TT;>;)Ljava/util/stream/Stream<TT;>;", $STATIC, $staticMethod(WhileOps, makeDropWhileRef, $Stream*, $AbstractPipeline*, $Predicate*)},
	{"makeTakeWhileDouble", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Double;*>;Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;", $STATIC, $staticMethod(WhileOps, makeTakeWhileDouble, $DoubleStream*, $AbstractPipeline*, $DoublePredicate*)},
	{"makeTakeWhileInt", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Integer;*>;Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;", $STATIC, $staticMethod(WhileOps, makeTakeWhileInt, $IntStream*, $AbstractPipeline*, $IntPredicate*)},
	{"makeTakeWhileLong", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Long;*>;Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;", $STATIC, $staticMethod(WhileOps, makeTakeWhileLong, $LongStream*, $AbstractPipeline*, $LongPredicate*)},
	{"makeTakeWhileRef", "(Ljava/util/stream/AbstractPipeline;Ljava/util/function/Predicate;)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/stream/AbstractPipeline<*TT;*>;Ljava/util/function/Predicate<-TT;>;)Ljava/util/stream/Stream<TT;>;", $STATIC, $staticMethod(WhileOps, makeTakeWhileRef, $Stream*, $AbstractPipeline*, $Predicate*)},
	{}
};

$InnerClassInfo _WhileOps_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$DropWhileTask", "java.util.stream.WhileOps", "DropWhileTask", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.WhileOps$TakeWhileTask", "java.util.stream.WhileOps", "TakeWhileTask", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$DropWhileSink", "java.util.stream.WhileOps", "DropWhileSink", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$DropWhileOp", "java.util.stream.WhileOps", "DropWhileOp", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$4Op", nullptr, "Op", 0},
	{"java.util.stream.WhileOps$3Op", nullptr, "Op", 0},
	{"java.util.stream.WhileOps$2Op", nullptr, "Op", 0},
	{"java.util.stream.WhileOps$1Op", nullptr, "Op", 0},
	{"java.util.stream.WhileOps$4", nullptr, nullptr, 0},
	{"java.util.stream.WhileOps$3", nullptr, nullptr, 0},
	{"java.util.stream.WhileOps$2", nullptr, nullptr, 0},
	{"java.util.stream.WhileOps$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WhileOps_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps",
	"java.lang.Object",
	nullptr,
	_WhileOps_FieldInfo_,
	_WhileOps_MethodInfo_,
	nullptr,
	nullptr,
	_WhileOps_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps$DropWhileTask,java.util.stream.WhileOps$TakeWhileTask,java.util.stream.WhileOps$UnorderedWhileSpliterator,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble$Taking,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Dropping,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Taking,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Dropping,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Taking,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef$Dropping,java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef$Taking,java.util.stream.WhileOps$DropWhileSink,java.util.stream.WhileOps$DropWhileOp,java.util.stream.WhileOps$4Op,java.util.stream.WhileOps$4Op$1OpSink,java.util.stream.WhileOps$3Op,java.util.stream.WhileOps$3Op$1OpSink,java.util.stream.WhileOps$2Op,java.util.stream.WhileOps$2Op$1OpSink,java.util.stream.WhileOps$1Op,java.util.stream.WhileOps$1Op$1OpSink,java.util.stream.WhileOps$4,java.util.stream.WhileOps$4$1,java.util.stream.WhileOps$3,java.util.stream.WhileOps$3$1,java.util.stream.WhileOps$2,java.util.stream.WhileOps$2$1,java.util.stream.WhileOps$1,java.util.stream.WhileOps$1$1"
};

$Object* allocate$WhileOps($Class* clazz) {
	return $of($alloc(WhileOps));
}

int32_t WhileOps::TAKE_FLAGS = 0;
int32_t WhileOps::DROP_FLAGS = 0;

void WhileOps::init$() {
}

$Stream* WhileOps::makeTakeWhileRef($AbstractPipeline* upstream, $Predicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	return $new($WhileOps$1, upstream, $StreamShape::REFERENCE, WhileOps::TAKE_FLAGS, predicate);
}

$IntStream* WhileOps::makeTakeWhileInt($AbstractPipeline* upstream, $IntPredicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	return $as($IntStream, $new($WhileOps$2, upstream, $StreamShape::INT_VALUE, WhileOps::TAKE_FLAGS, predicate));
}

$LongStream* WhileOps::makeTakeWhileLong($AbstractPipeline* upstream, $LongPredicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	return $as($LongStream, $new($WhileOps$3, upstream, $StreamShape::LONG_VALUE, WhileOps::TAKE_FLAGS, predicate));
}

$DoubleStream* WhileOps::makeTakeWhileDouble($AbstractPipeline* upstream, $DoublePredicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	$init($StreamShape);
	return $as($DoubleStream, $new($WhileOps$4, upstream, $StreamShape::DOUBLE_VALUE, WhileOps::TAKE_FLAGS, predicate));
}

$Stream* WhileOps::makeDropWhileRef($AbstractPipeline* upstream, $Predicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	{
	}
	$init($StreamShape);
	return $new($WhileOps$1Op, upstream, $StreamShape::REFERENCE, WhileOps::DROP_FLAGS, predicate);
}

$IntStream* WhileOps::makeDropWhileInt($AbstractPipeline* upstream, $IntPredicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	{
	}
	$init($StreamShape);
	return $as($IntStream, $new($WhileOps$2Op, upstream, $StreamShape::INT_VALUE, WhileOps::DROP_FLAGS, predicate));
}

$LongStream* WhileOps::makeDropWhileLong($AbstractPipeline* upstream, $LongPredicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	{
	}
	$init($StreamShape);
	return $as($LongStream, $new($WhileOps$3Op, upstream, $StreamShape::LONG_VALUE, WhileOps::DROP_FLAGS, predicate));
}

$DoubleStream* WhileOps::makeDropWhileDouble($AbstractPipeline* upstream, $DoublePredicate* predicate) {
	$init(WhileOps);
	$Objects::requireNonNull(predicate);
	{
	}
	$init($StreamShape);
	return $as($DoubleStream, $new($WhileOps$4Op, upstream, $StreamShape::DOUBLE_VALUE, WhileOps::DROP_FLAGS, predicate));
}

void clinit$WhileOps($Class* class$) {
	$init($StreamOpFlag);
	WhileOps::TAKE_FLAGS = $StreamOpFlag::NOT_SIZED | $StreamOpFlag::IS_SHORT_CIRCUIT;
	WhileOps::DROP_FLAGS = $StreamOpFlag::NOT_SIZED;
}

WhileOps::WhileOps() {
}

$Class* WhileOps::load$($String* name, bool initialize) {
	$loadClass(WhileOps, name, initialize, &_WhileOps_ClassInfo_, clinit$WhileOps, allocate$WhileOps);
	return class$;
}

$Class* WhileOps::class$ = nullptr;

		} // stream
	} // util
} // java