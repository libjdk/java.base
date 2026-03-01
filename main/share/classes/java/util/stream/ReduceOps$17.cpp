#include <java/util/stream/ReduceOps$17.h>

#include <java/util/Spliterator.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReduceOps$AccumulatingSink.h>
#include <java/util/stream/ReduceOps$CountingSink$OfDouble.h>
#include <java/util/stream/ReduceOps$ReduceOp.h>
#include <java/util/stream/ReduceOps.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef NOT_ORDERED

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReduceOps$AccumulatingSink = ::java::util::stream::ReduceOps$AccumulatingSink;
using $ReduceOps$CountingSink$OfDouble = ::java::util::stream::ReduceOps$CountingSink$OfDouble;
using $ReduceOps$ReduceOp = ::java::util::stream::ReduceOps$ReduceOp;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _ReduceOps$17_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/StreamShape;)V", nullptr, 0, $method(ReduceOps$17, init$, void, $StreamShape*)},
	{"evaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/lang/Long;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/lang/Long;", $PUBLIC, $virtualMethod(ReduceOps$17, evaluateParallel, $Object*, $PipelineHelper*, $Spliterator*)},
	{"evaluateSequential", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/lang/Long;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/lang/Long;", $PUBLIC, $virtualMethod(ReduceOps$17, evaluateSequential, $Object*, $PipelineHelper*, $Spliterator*)},
	{"getOpFlags", "()I", nullptr, $PUBLIC, $virtualMethod(ReduceOps$17, getOpFlags, int32_t)},
	{"makeSink", "()Ljava/util/stream/ReduceOps$CountingSink;", "()Ljava/util/stream/ReduceOps$CountingSink<Ljava/lang/Double;>;", $PUBLIC, $virtualMethod(ReduceOps$17, makeSink, $ReduceOps$AccumulatingSink*)},
	{}
};

$EnclosingMethodInfo _ReduceOps$17_EnclosingMethodInfo_ = {
	"java.util.stream.ReduceOps",
	"makeDoubleCounting",
	"()Ljava/util/stream/TerminalOp;"
};

$InnerClassInfo _ReduceOps$17_InnerClassesInfo_[] = {
	{"java.util.stream.ReduceOps$17", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$ReduceOp", "java.util.stream.ReduceOps", "ReduceOp", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.ReduceOps$CountingSink", "java.util.stream.ReduceOps", "CountingSink", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ReduceOps$17_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReduceOps$17",
	"java.util.stream.ReduceOps$ReduceOp",
	nullptr,
	nullptr,
	_ReduceOps$17_MethodInfo_,
	"Ljava/util/stream/ReduceOps$ReduceOp<Ljava/lang/Double;Ljava/lang/Long;Ljava/util/stream/ReduceOps$CountingSink<Ljava/lang/Double;>;>;",
	&_ReduceOps$17_EnclosingMethodInfo_,
	_ReduceOps$17_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReduceOps"
};

$Object* allocate$ReduceOps$17($Class* clazz) {
	return $of($alloc(ReduceOps$17));
}

void ReduceOps$17::init$($StreamShape* shape) {
	$ReduceOps$ReduceOp::init$(shape);
}

$ReduceOps$AccumulatingSink* ReduceOps$17::makeSink() {
	return $new($ReduceOps$CountingSink$OfDouble);
}

$Object* ReduceOps$17::evaluateSequential($PipelineHelper* helper, $Spliterator* spliterator) {
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size != -1) {
		return $of($Long::valueOf(size));
	}
	return $of($cast($Long, $ReduceOps$ReduceOp::evaluateSequential(helper, spliterator)));
}

$Object* ReduceOps$17::evaluateParallel($PipelineHelper* helper, $Spliterator* spliterator) {
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size != -1) {
		return $of($Long::valueOf(size));
	}
	return $of($cast($Long, $ReduceOps$ReduceOp::evaluateParallel(helper, spliterator)));
}

int32_t ReduceOps$17::getOpFlags() {
	$init($StreamOpFlag);
	return $StreamOpFlag::NOT_ORDERED;
}

ReduceOps$17::ReduceOps$17() {
}

$Class* ReduceOps$17::load$($String* name, bool initialize) {
	$loadClass(ReduceOps$17, name, initialize, &_ReduceOps$17_ClassInfo_, allocate$ReduceOps$17);
	return class$;
}

$Class* ReduceOps$17::class$ = nullptr;

		} // stream
	} // util
} // java