#include <java/util/stream/SliceOps$2.h>

#include <java/io/Serializable.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator$OfPrimitive.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$StatefulOp.h>
#include <java/util/stream/Node$OfInt.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SliceOps$2$1.h>
#include <java/util/stream/SliceOps$SliceTask.h>
#include <java/util/stream/SliceOps.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfInt.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfPrimitive.h>
#include <java/util/stream/StreamSpliterators$UnorderedSliceSpliterator$OfInt.h>
#include <jcpp.h>

#undef ORDERED
#undef SUBSIZED

using $IntegerArray = $Array<::java::lang::Integer>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterator$OfPrimitive = ::java::util::Spliterator$OfPrimitive;
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline$StatefulOp = ::java::util::stream::IntPipeline$StatefulOp;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $SliceOps = ::java::util::stream::SliceOps;
using $SliceOps$2$1 = ::java::util::stream::SliceOps$2$1;
using $SliceOps$SliceTask = ::java::util::stream::SliceOps$SliceTask;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $StreamSpliterators$SliceSpliterator$OfInt = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfInt;
using $StreamSpliterators$SliceSpliterator$OfPrimitive = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfPrimitive;
using $StreamSpliterators$UnorderedSliceSpliterator$OfInt = ::java::util::stream::StreamSpliterators$UnorderedSliceSpliterator$OfInt;

namespace java {
	namespace util {
		namespace stream {

class SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(SliceOps$2::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _SliceOps$2_FieldInfo_[] = {
	{"val$limit", "J", nullptr, $FINAL | $SYNTHETIC, $field(SliceOps$2, val$limit)},
	{"val$normalizedLimit", "J", nullptr, $FINAL | $SYNTHETIC, $field(SliceOps$2, val$normalizedLimit)},
	{"val$skip", "J", nullptr, $FINAL | $SYNTHETIC, $field(SliceOps$2, val$skip)},
	{}
};

$MethodInfo _SliceOps$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;IJJJ)V", nullptr, 0, $method(SliceOps$2, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, int64_t, int64_t, int64_t)},
	{"exactOutputSize", "(J)J", nullptr, 0, $virtualMethod(SliceOps$2, exactOutputSize, int64_t, int64_t)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SliceOps$2, lambda$opEvaluateParallelLazy$0, $IntegerArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Integer;>;)Ljava/util/stream/Node<Ljava/lang/Integer;>;", 0, $virtualMethod(SliceOps$2, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Integer;>;", 0, $virtualMethod(SliceOps$2, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(SliceOps$2, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"unorderedSkipLimitSpliterator", "(Ljava/util/Spliterator$OfInt;JJJ)Ljava/util/Spliterator$OfInt;", nullptr, 0, $virtualMethod(SliceOps$2, unorderedSkipLimitSpliterator, $Spliterator$OfInt*, $Spliterator$OfInt*, int64_t, int64_t, int64_t)},
	{}
};

$EnclosingMethodInfo _SliceOps$2_EnclosingMethodInfo_ = {
	"java.util.stream.SliceOps",
	"makeInt",
	"(Ljava/util/stream/AbstractPipeline;JJ)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _SliceOps$2_InnerClassesInfo_[] = {
	{"java.util.stream.SliceOps$2", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatefulOp", "java.util.stream.IntPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.SliceOps$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SliceOps$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.SliceOps$2",
	"java.util.stream.IntPipeline$StatefulOp",
	nullptr,
	_SliceOps$2_FieldInfo_,
	_SliceOps$2_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatefulOp<Ljava/lang/Integer;>;",
	&_SliceOps$2_EnclosingMethodInfo_,
	_SliceOps$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SliceOps"
};

$Object* allocate$SliceOps$2($Class* clazz) {
	return $of($alloc(SliceOps$2));
}

void SliceOps$2::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, int64_t val$skip, int64_t val$normalizedLimit, int64_t val$limit) {
	this->val$skip = val$skip;
	this->val$normalizedLimit = val$normalizedLimit;
	this->val$limit = val$limit;
	$IntPipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

int64_t SliceOps$2::exactOutputSize(int64_t previousSize) {
	return $SliceOps::calcSize(previousSize, this->val$skip, this->val$normalizedLimit);
}

$Spliterator$OfInt* SliceOps$2::unorderedSkipLimitSpliterator($Spliterator$OfInt* s, int64_t skip, int64_t limit, int64_t sizeIfKnown) {
	if (skip <= sizeIfKnown) {
		limit = limit >= 0 ? $Math::min(limit, sizeIfKnown - skip) : sizeIfKnown - skip;
		skip = 0;
	}
	return $as($Spliterator$OfInt, $new($StreamSpliterators$UnorderedSliceSpliterator$OfInt, s, skip, limit));
}

$Spliterator* SliceOps$2::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size > 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		$var($Spliterator$OfInt, var$0, $cast($Spliterator$OfInt, helper->wrapSpliterator(spliterator)));
		int64_t var$1 = this->val$skip;
		return static_cast<$Spliterator*>(static_cast<$Spliterator$OfPrimitive*>(static_cast<$StreamSpliterators$SliceSpliterator$OfPrimitive*>($new($StreamSpliterators$SliceSpliterator$OfInt, var$0, var$1, $SliceOps::calcSliceFence(this->val$skip, this->val$limit)))));
	} else {
		$init($StreamOpFlag);
		if (!$StreamOpFlag::ORDERED->isKnown(helper->getStreamAndOpFlags())) {
			return unorderedSkipLimitSpliterator($cast($Spliterator$OfInt, $(helper->wrapSpliterator(spliterator))), this->val$skip, this->val$limit, size);
		} else {
			return $nc(($cast($Node, $($$new($SliceOps$SliceTask, this, helper, spliterator, static_cast<$IntFunction*>($$new(SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0)), this->val$skip, this->val$limit)->invoke()))))->spliterator();
		}
	}
}

$Node* SliceOps$2::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size > 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		$var($Spliterator, s, $SliceOps::sliceSpliterator($(helper->getSourceShape()), spliterator, this->val$skip, this->val$limit));
		return $Nodes::collectInt(helper, s, true);
	} else {
		$init($StreamOpFlag);
		if (!$StreamOpFlag::ORDERED->isKnown(helper->getStreamAndOpFlags())) {
			$var($Spliterator$OfInt, s, unorderedSkipLimitSpliterator($cast($Spliterator$OfInt, $(helper->wrapSpliterator(spliterator))), this->val$skip, this->val$limit, size));
			return $Nodes::collectInt(this, s, true);
		} else {
			return $cast($Node, $$new($SliceOps$SliceTask, this, helper, spliterator, generator, this->val$skip, this->val$limit)->invoke());
		}
	}
}

$Sink* SliceOps$2::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($SliceOps$2$1, this, sink);
}

$IntegerArray* SliceOps$2::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(SliceOps$2);
	return $new($IntegerArray, x$0);
}

SliceOps$2::SliceOps$2() {
}

$Class* SliceOps$2::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return SliceOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(SliceOps$2, name, initialize, &_SliceOps$2_ClassInfo_, allocate$SliceOps$2);
	return class$;
}

$Class* SliceOps$2::class$ = nullptr;

		} // stream
	} // util
} // java