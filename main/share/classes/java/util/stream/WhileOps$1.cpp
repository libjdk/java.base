#include <java/util/stream/WhileOps$1.h>

#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReferencePipeline$StatefulOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/WhileOps$1$1.h>
#include <java/util/stream/WhileOps$TakeWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Taking.h>
#include <java/util/stream/WhileOps.h>
#include <jcpp.h>

#undef ORDERED

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReferencePipeline$StatefulOp = ::java::util::stream::ReferencePipeline$StatefulOp;
using $Sink = ::java::util::stream::Sink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $WhileOps$1$1 = ::java::util::stream::WhileOps$1$1;
using $WhileOps$TakeWhileTask = ::java::util::stream::WhileOps$TakeWhileTask;
using $WhileOps$UnorderedWhileSpliterator$OfRef$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfRef$Taking;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _WhileOps$1_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/Predicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$1, val$predicate)},
	{}
};

$MethodInfo _WhileOps$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/Predicate;)V", nullptr, 0, $method(WhileOps$1, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $Predicate*)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", 0, $virtualMethod(WhileOps$1, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(WhileOps$1, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TT;>;)Ljava/util/stream/Sink<TT;>;", 0, $virtualMethod(WhileOps$1, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _WhileOps$1_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeTakeWhileRef",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/Predicate;)Ljava/util/stream/Stream;"
};

$InnerClassInfo _WhileOps$1_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$1", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatefulOp", "java.util.stream.ReferencePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$1$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WhileOps$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$1",
	"java.util.stream.ReferencePipeline$StatefulOp",
	nullptr,
	_WhileOps$1_FieldInfo_,
	_WhileOps$1_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatefulOp<TT;TT;>;",
	&_WhileOps$1_EnclosingMethodInfo_,
	_WhileOps$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$1($Class* clazz) {
	return $of($alloc(WhileOps$1));
}

void WhileOps$1::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $Predicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$ReferencePipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$1::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, $($Nodes::castingArray()))))->spliterator();
	} else {
		return $new($WhileOps$UnorderedWhileSpliterator$OfRef$Taking, $($nc(helper)->wrapSpliterator(spliterator)), false, this->val$predicate);
	}
}

$Node* WhileOps$1::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$TakeWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$1::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($WhileOps$1$1, this, sink);
}

WhileOps$1::WhileOps$1() {
}

$Class* WhileOps$1::load$($String* name, bool initialize) {
	$loadClass(WhileOps$1, name, initialize, &_WhileOps$1_ClassInfo_, allocate$WhileOps$1);
	return class$;
}

$Class* WhileOps$1::class$ = nullptr;

		} // stream
	} // util
} // java