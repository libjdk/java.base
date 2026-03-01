#include <java/util/stream/WhileOps$4Op.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/DoublePredicate.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatefulOp.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/WhileOps$4Op$1OpSink.h>
#include <java/util/stream/WhileOps$DropWhileSink.h>
#include <java/util/stream/WhileOps$DropWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <java/util/stream/WhileOps.h>
#include <jcpp.h>

#undef ORDERED

using $DoubleArray = $Array<::java::lang::Double>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline$StatefulOp = ::java::util::stream::DoublePipeline$StatefulOp;
using $Node = ::java::util::stream::Node;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $WhileOps$4Op$1OpSink = ::java::util::stream::WhileOps$4Op$1OpSink;
using $WhileOps$DropWhileSink = ::java::util::stream::WhileOps$DropWhileSink;
using $WhileOps$DropWhileTask = ::java::util::stream::WhileOps$DropWhileTask;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfDouble = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble;
using $WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping;

namespace java {
	namespace util {
		namespace stream {

class WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(WhileOps$4Op::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _WhileOps$4Op_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/DoublePredicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$4Op, val$predicate)},
	{}
};

$MethodInfo _WhileOps$4Op_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoublePredicate;)V", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Double;*>;Ljava/util/stream/StreamShape;I)V", $PUBLIC, $method(WhileOps$4Op, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $DoublePredicate*)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Double;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WhileOps$4Op, lambda$opEvaluateParallelLazy$0, $DoubleArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Double;>;)Ljava/util/stream/Node<Ljava/lang/Double;>;", 0, $virtualMethod(WhileOps$4Op, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Double;>;", 0, $virtualMethod(WhileOps$4Op, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(WhileOps$4Op, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"opWrapSink", "(Ljava/util/stream/Sink;Z)Ljava/util/stream/WhileOps$DropWhileSink;", "(Ljava/util/stream/Sink<Ljava/lang/Double;>;Z)Ljava/util/stream/WhileOps$DropWhileSink<Ljava/lang/Double;>;", $PUBLIC, $virtualMethod(WhileOps$4Op, opWrapSink, $WhileOps$DropWhileSink*, $Sink*, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _WhileOps$4Op_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeDropWhileDouble",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _WhileOps$4Op_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$4Op", nullptr, "Op", 0},
	{"java.util.stream.DoublePipeline$StatefulOp", "java.util.stream.DoublePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$DropWhileOp", "java.util.stream.WhileOps", "DropWhileOp", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$4Op$1OpSink", nullptr, "OpSink", 0},
	{}
};

$ClassInfo _WhileOps$4Op_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$4Op",
	"java.util.stream.DoublePipeline$StatefulOp",
	"java.util.stream.WhileOps$DropWhileOp",
	_WhileOps$4Op_FieldInfo_,
	_WhileOps$4Op_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatefulOp<Ljava/lang/Double;>;Ljava/util/stream/WhileOps$DropWhileOp<Ljava/lang/Double;>;",
	&_WhileOps$4Op_EnclosingMethodInfo_,
	_WhileOps$4Op_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$4Op($Class* clazz) {
	return $of($alloc(WhileOps$4Op));
}

int32_t WhileOps$4Op::hashCode() {
	 return this->$DoublePipeline$StatefulOp::hashCode();
}

bool WhileOps$4Op::equals(Object$* obj) {
	 return this->$DoublePipeline$StatefulOp::equals(obj);
}

$Object* WhileOps$4Op::clone() {
	 return this->$DoublePipeline$StatefulOp::clone();
}

$String* WhileOps$4Op::toString() {
	 return this->$DoublePipeline$StatefulOp::toString();
}

void WhileOps$4Op::finalize() {
	this->$DoublePipeline$StatefulOp::finalize();
}

void WhileOps$4Op::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoublePredicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$DoublePipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$4Op::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, static_cast<$IntFunction*>($$new(WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0)))))->spliterator();
	} else {
		return static_cast<$Spliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator$OfDouble*>($new($WhileOps$UnorderedWhileSpliterator$OfDouble$Dropping, $cast($Spliterator$OfDouble, $($nc(helper)->wrapSpliterator(spliterator))), false, this->val$predicate))));
	}
}

$Node* WhileOps$4Op::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$DropWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$4Op::opWrapSink(int32_t flags, $Sink* sink) {
	return opWrapSink(sink, false);
}

$WhileOps$DropWhileSink* WhileOps$4Op::opWrapSink($Sink* sink, bool retainAndCountDroppedElements) {
	{
	}
	return $new($WhileOps$4Op$1OpSink, this, sink, retainAndCountDroppedElements);
}

$DoubleArray* WhileOps$4Op::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(WhileOps$4Op);
	return $new($DoubleArray, x$0);
}

WhileOps$4Op::WhileOps$4Op() {
}

$Class* WhileOps$4Op::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return WhileOps$4Op$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(WhileOps$4Op, name, initialize, &_WhileOps$4Op_ClassInfo_, allocate$WhileOps$4Op);
	return class$;
}

$Class* WhileOps$4Op::class$ = nullptr;

		} // stream
	} // util
} // java