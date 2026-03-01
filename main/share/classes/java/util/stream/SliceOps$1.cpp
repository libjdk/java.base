#include <java/util/stream/SliceOps$1.h>

#include <java/lang/Math.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReferencePipeline$StatefulOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SliceOps$1$1.h>
#include <java/util/stream/SliceOps$SliceTask.h>
#include <java/util/stream/SliceOps.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfRef.h>
#include <java/util/stream/StreamSpliterators$UnorderedSliceSpliterator$OfRef.h>
#include <jcpp.h>

#undef ORDERED
#undef SUBSIZED

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReferencePipeline$StatefulOp = ::java::util::stream::ReferencePipeline$StatefulOp;
using $Sink = ::java::util::stream::Sink;
using $SliceOps = ::java::util::stream::SliceOps;
using $SliceOps$1$1 = ::java::util::stream::SliceOps$1$1;
using $SliceOps$SliceTask = ::java::util::stream::SliceOps$SliceTask;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $StreamSpliterators$SliceSpliterator$OfRef = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfRef;
using $StreamSpliterators$UnorderedSliceSpliterator$OfRef = ::java::util::stream::StreamSpliterators$UnorderedSliceSpliterator$OfRef;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _SliceOps$1_FieldInfo_[] = {
	{"val$limit", "J", nullptr, $FINAL | $SYNTHETIC, $field(SliceOps$1, val$limit)},
	{"val$normalizedLimit", "J", nullptr, $FINAL | $SYNTHETIC, $field(SliceOps$1, val$normalizedLimit)},
	{"val$skip", "J", nullptr, $FINAL | $SYNTHETIC, $field(SliceOps$1, val$skip)},
	{}
};

$MethodInfo _SliceOps$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;IJJJ)V", nullptr, 0, $method(SliceOps$1, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, int64_t, int64_t, int64_t)},
	{"exactOutputSize", "(J)J", nullptr, 0, $virtualMethod(SliceOps$1, exactOutputSize, int64_t, int64_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", 0, $virtualMethod(SliceOps$1, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(SliceOps$1, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TT;>;)Ljava/util/stream/Sink<TT;>;", 0, $virtualMethod(SliceOps$1, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"unorderedSkipLimitSpliterator", "(Ljava/util/Spliterator;JJJ)Ljava/util/Spliterator;", "(Ljava/util/Spliterator<TT;>;JJJ)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(SliceOps$1, unorderedSkipLimitSpliterator, $Spliterator*, $Spliterator*, int64_t, int64_t, int64_t)},
	{}
};

$EnclosingMethodInfo _SliceOps$1_EnclosingMethodInfo_ = {
	"java.util.stream.SliceOps",
	"makeRef",
	"(Ljava/util/stream/AbstractPipeline;JJ)Ljava/util/stream/Stream;"
};

$InnerClassInfo _SliceOps$1_InnerClassesInfo_[] = {
	{"java.util.stream.SliceOps$1", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatefulOp", "java.util.stream.ReferencePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.SliceOps$1$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SliceOps$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.SliceOps$1",
	"java.util.stream.ReferencePipeline$StatefulOp",
	nullptr,
	_SliceOps$1_FieldInfo_,
	_SliceOps$1_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatefulOp<TT;TT;>;",
	&_SliceOps$1_EnclosingMethodInfo_,
	_SliceOps$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SliceOps"
};

$Object* allocate$SliceOps$1($Class* clazz) {
	return $of($alloc(SliceOps$1));
}

void SliceOps$1::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, int64_t val$skip, int64_t val$normalizedLimit, int64_t val$limit) {
	this->val$skip = val$skip;
	this->val$normalizedLimit = val$normalizedLimit;
	this->val$limit = val$limit;
	$ReferencePipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

int64_t SliceOps$1::exactOutputSize(int64_t previousSize) {
	return $SliceOps::calcSize(previousSize, this->val$skip, this->val$normalizedLimit);
}

$Spliterator* SliceOps$1::unorderedSkipLimitSpliterator($Spliterator* s, int64_t skip, int64_t limit, int64_t sizeIfKnown) {
	if (skip <= sizeIfKnown) {
		limit = limit >= 0 ? $Math::min(limit, sizeIfKnown - skip) : sizeIfKnown - skip;
		skip = 0;
	}
	return $new($StreamSpliterators$UnorderedSliceSpliterator$OfRef, s, skip, limit);
}

$Spliterator* SliceOps$1::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size > 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		$var($Spliterator, var$0, helper->wrapSpliterator(spliterator));
		int64_t var$1 = this->val$skip;
		return $new($StreamSpliterators$SliceSpliterator$OfRef, var$0, var$1, $SliceOps::calcSliceFence(this->val$skip, this->val$limit));
	} else {
		$init($StreamOpFlag);
		if (!$StreamOpFlag::ORDERED->isKnown(helper->getStreamAndOpFlags())) {
			return unorderedSkipLimitSpliterator($(helper->wrapSpliterator(spliterator)), this->val$skip, this->val$limit, size);
		} else {
			return $nc(($cast($Node, $($$new($SliceOps$SliceTask, this, helper, spliterator, $($Nodes::castingArray()), this->val$skip, this->val$limit)->invoke()))))->spliterator();
		}
	}
}

$Node* SliceOps$1::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	int64_t size = $nc(helper)->exactOutputSizeIfKnown(spliterator);
	if (size > 0 && $nc(spliterator)->hasCharacteristics($Spliterator::SUBSIZED)) {
		$var($Spliterator, s, $SliceOps::sliceSpliterator($(helper->getSourceShape()), spliterator, this->val$skip, this->val$limit));
		return $Nodes::collect(helper, s, true, generator);
	} else {
		$init($StreamOpFlag);
		if (!$StreamOpFlag::ORDERED->isKnown(helper->getStreamAndOpFlags())) {
			$var($Spliterator, s, unorderedSkipLimitSpliterator($(helper->wrapSpliterator(spliterator)), this->val$skip, this->val$limit, size));
			return $Nodes::collect(this, s, true, generator);
		} else {
			return $cast($Node, $$new($SliceOps$SliceTask, this, helper, spliterator, generator, this->val$skip, this->val$limit)->invoke());
		}
	}
}

$Sink* SliceOps$1::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($SliceOps$1$1, this, sink);
}

SliceOps$1::SliceOps$1() {
}

$Class* SliceOps$1::load$($String* name, bool initialize) {
	$loadClass(SliceOps$1, name, initialize, &_SliceOps$1_ClassInfo_, allocate$SliceOps$1);
	return class$;
}

$Class* SliceOps$1::class$ = nullptr;

		} // stream
	} // util
} // java