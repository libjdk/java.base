#include <java/util/stream/WhileOps$1Op.h>

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
#include <java/util/stream/WhileOps$1Op$1OpSink.h>
#include <java/util/stream/WhileOps$DropWhileSink.h>
#include <java/util/stream/WhileOps$DropWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Dropping.h>
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
using $WhileOps$1Op$1OpSink = ::java::util::stream::WhileOps$1Op$1OpSink;
using $WhileOps$DropWhileSink = ::java::util::stream::WhileOps$DropWhileSink;
using $WhileOps$DropWhileTask = ::java::util::stream::WhileOps$DropWhileTask;
using $WhileOps$UnorderedWhileSpliterator$OfRef$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfRef$Dropping;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _WhileOps$1Op_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/Predicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$1Op, val$predicate)},
	{}
};

$MethodInfo _WhileOps$1Op_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/Predicate;)V", "(Ljava/util/stream/AbstractPipeline<*TT;*>;Ljava/util/stream/StreamShape;I)V", $PUBLIC, $method(WhileOps$1Op, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $Predicate*)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", 0, $virtualMethod(WhileOps$1Op, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(WhileOps$1Op, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TT;>;)Ljava/util/stream/Sink<TT;>;", 0, $virtualMethod(WhileOps$1Op, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"opWrapSink", "(Ljava/util/stream/Sink;Z)Ljava/util/stream/WhileOps$DropWhileSink;", "(Ljava/util/stream/Sink<TT;>;Z)Ljava/util/stream/WhileOps$DropWhileSink<TT;>;", $PUBLIC, $virtualMethod(WhileOps$1Op, opWrapSink, $WhileOps$DropWhileSink*, $Sink*, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _WhileOps$1Op_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeDropWhileRef",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/Predicate;)Ljava/util/stream/Stream;"
};

$InnerClassInfo _WhileOps$1Op_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$1Op", nullptr, "Op", 0},
	{"java.util.stream.ReferencePipeline$StatefulOp", "java.util.stream.ReferencePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$DropWhileOp", "java.util.stream.WhileOps", "DropWhileOp", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$1Op$1OpSink", nullptr, "OpSink", 0},
	{}
};

$ClassInfo _WhileOps$1Op_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$1Op",
	"java.util.stream.ReferencePipeline$StatefulOp",
	"java.util.stream.WhileOps$DropWhileOp",
	_WhileOps$1Op_FieldInfo_,
	_WhileOps$1Op_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatefulOp<TT;TT;>;Ljava/util/stream/WhileOps$DropWhileOp<TT;>;",
	&_WhileOps$1Op_EnclosingMethodInfo_,
	_WhileOps$1Op_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$1Op($Class* clazz) {
	return $of($alloc(WhileOps$1Op));
}

int32_t WhileOps$1Op::hashCode() {
	 return this->$ReferencePipeline$StatefulOp::hashCode();
}

bool WhileOps$1Op::equals(Object$* obj) {
	 return this->$ReferencePipeline$StatefulOp::equals(obj);
}

$Object* WhileOps$1Op::clone() {
	 return this->$ReferencePipeline$StatefulOp::clone();
}

$String* WhileOps$1Op::toString() {
	 return this->$ReferencePipeline$StatefulOp::toString();
}

void WhileOps$1Op::finalize() {
	this->$ReferencePipeline$StatefulOp::finalize();
}

void WhileOps$1Op::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $Predicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$ReferencePipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$1Op::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, $($Nodes::castingArray()))))->spliterator();
	} else {
		return $new($WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, $($nc(helper)->wrapSpliterator(spliterator)), false, this->val$predicate);
	}
}

$Node* WhileOps$1Op::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$DropWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$1Op::opWrapSink(int32_t flags, $Sink* sink) {
	return opWrapSink(sink, false);
}

$WhileOps$DropWhileSink* WhileOps$1Op::opWrapSink($Sink* sink, bool retainAndCountDroppedElements) {
	{
	}
	return $new($WhileOps$1Op$1OpSink, this, sink, retainAndCountDroppedElements);
}

WhileOps$1Op::WhileOps$1Op() {
}

$Class* WhileOps$1Op::load$($String* name, bool initialize) {
	$loadClass(WhileOps$1Op, name, initialize, &_WhileOps$1Op_ClassInfo_, allocate$WhileOps$1Op);
	return class$;
}

$Class* WhileOps$1Op::class$ = nullptr;

		} // stream
	} // util
} // java