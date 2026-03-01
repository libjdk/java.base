#include <java/util/stream/ReduceOps$13.h>

#include <java/util/Spliterator.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReduceOps$AccumulatingSink.h>
#include <java/util/stream/ReduceOps$CountingSink$OfLong.h>
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
using $ReduceOps$CountingSink$OfLong = ::java::util::stream::ReduceOps$CountingSink$OfLong;
using $ReduceOps$ReduceOp = ::java::util::stream::ReduceOps$ReduceOp;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _ReduceOps$13_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/StreamShape;)V", nullptr, 0, $method(ReduceOps$13, init$, void, $StreamShape*)},
	{"evaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/lang/Long;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/lang/Long;", $PUBLIC, $virtualMethod(ReduceOps$13, evaluateParallel, $Object*, $PipelineHelper*, $Spliterator*)},
	{"evaluateSequential", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/lang/Long;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/lang/Long;", $PUBLIC, $virtualMethod(ReduceOps$13, evaluateSequential, $Object*, $PipelineHelper*, $Spliterator*)},
	{"getOpFlags", "()I", nullptr, $PUBLIC, $virtualMethod(ReduceOps$13, getOpFlags, int32_t)},
	{"makeSink", "()Ljava/util/stream/ReduceOps$CountingSink;", "()Ljava/util/stream/ReduceOps$CountingSink<Ljava/lang/Long;>;", $PUBLIC, $virtualMethod(ReduceOps$13, makeSink, $ReduceOps$AccumulatingSink*)},
	{}
};

$EnclosingMethodInfo _ReduceOps$13_EnclosingMethodInfo_ = {
	"java.util.stream.ReduceOps",
	"makeLongCounting",
	"()Ljava/util/stream/TerminalOp;"
};

$InnerClassInfo _ReduceOps$13_InnerClassesInfo_[] = {
	{"java.util.stream.ReduceOps$13", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$ReduceOp", "java.util.stream.ReduceOps", "ReduceOp", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.ReduceOps$CountingSink", "java.util.stream.ReduceOps", "CountingSink", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ReduceOps$13_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReduceOps$13",
	"java.util.stream.ReduceOps$ReduceOp",
	nullptr,
	nullptr,
	_ReduceOps$13_MethodInfo_,
	"Ljava/util/stream/ReduceOps$ReduceOp<Ljava/lang/Long;Ljava/lang/Long;Ljava/util/stream/ReduceOps$CountingSink<Ljava/lang/Long;>;>;",
	&_ReduceOps$13_EnclosingMethodInfo_,
	_ReduceOps$13_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReduceOps"
};

$Object* allocate$ReduceOps$13($Class* clazz) {
	return $of($alloc(ReduceOps$13));
}

void ReduceOps$13::init$($StreamShape* shape) {
	$ReduceOps$ReduceOp::init$(shape);
}

$ReduceOps$AccumulatingSink* ReduceOps$13::makeSink() {
	return $new($ReduceOps$CountingSink$OfLong);
}

$Object* ReduceOps$13::evaluateSequential($PipelineHelper* helper, $Spliterator* spliterator) {
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size != -1) {
		return $of($Long::valueOf(size));
	}
	return $of($cast($Long, $ReduceOps$ReduceOp::evaluateSequential(helper, spliterator)));
}

$Object* ReduceOps$13::evaluateParallel($PipelineHelper* helper, $Spliterator* spliterator) {
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size != -1) {
		return $of($Long::valueOf(size));
	}
	return $of($cast($Long, $ReduceOps$ReduceOp::evaluateParallel(helper, spliterator)));
}

int32_t ReduceOps$13::getOpFlags() {
	$init($StreamOpFlag);
	return $StreamOpFlag::NOT_ORDERED;
}

ReduceOps$13::ReduceOps$13() {
}

$Class* ReduceOps$13::load$($String* name, bool initialize) {
	$loadClass(ReduceOps$13, name, initialize, &_ReduceOps$13_ClassInfo_, allocate$ReduceOps$13);
	return class$;
}

$Class* ReduceOps$13::class$ = nullptr;

		} // stream
	} // util
} // java