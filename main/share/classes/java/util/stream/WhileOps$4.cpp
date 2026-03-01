#include <java/util/stream/WhileOps$4.h>

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
#include <java/util/stream/WhileOps$4$1.h>
#include <java/util/stream/WhileOps$TakeWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble$Taking.h>
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
using $WhileOps$4$1 = ::java::util::stream::WhileOps$4$1;
using $WhileOps$TakeWhileTask = ::java::util::stream::WhileOps$TakeWhileTask;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfDouble = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble;
using $WhileOps$UnorderedWhileSpliterator$OfDouble$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble$Taking;

namespace java {
	namespace util {
		namespace stream {

class WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(WhileOps$4::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _WhileOps$4_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/DoublePredicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$4, val$predicate)},
	{}
};

$MethodInfo _WhileOps$4_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoublePredicate;)V", nullptr, 0, $method(WhileOps$4, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $DoublePredicate*)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Double;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WhileOps$4, lambda$opEvaluateParallelLazy$0, $DoubleArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Double;>;)Ljava/util/stream/Node<Ljava/lang/Double;>;", 0, $virtualMethod(WhileOps$4, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Double;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Double;>;", 0, $virtualMethod(WhileOps$4, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(WhileOps$4, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _WhileOps$4_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeTakeWhileDouble",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _WhileOps$4_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$4", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatefulOp", "java.util.stream.DoublePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$4$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WhileOps$4_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$4",
	"java.util.stream.DoublePipeline$StatefulOp",
	nullptr,
	_WhileOps$4_FieldInfo_,
	_WhileOps$4_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatefulOp<Ljava/lang/Double;>;",
	&_WhileOps$4_EnclosingMethodInfo_,
	_WhileOps$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$4($Class* clazz) {
	return $of($alloc(WhileOps$4));
}

void WhileOps$4::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoublePredicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$DoublePipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$4::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, static_cast<$IntFunction*>($$new(WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0)))))->spliterator();
	} else {
		return static_cast<$Spliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator$OfDouble*>($new($WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, $cast($Spliterator$OfDouble, $($nc(helper)->wrapSpliterator(spliterator))), false, this->val$predicate))));
	}
}

$Node* WhileOps$4::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$TakeWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$4::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($WhileOps$4$1, this, sink);
}

$DoubleArray* WhileOps$4::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(WhileOps$4);
	return $new($DoubleArray, x$0);
}

WhileOps$4::WhileOps$4() {
}

$Class* WhileOps$4::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return WhileOps$4$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(WhileOps$4, name, initialize, &_WhileOps$4_ClassInfo_, allocate$WhileOps$4);
	return class$;
}

$Class* WhileOps$4::class$ = nullptr;

		} // stream
	} // util
} // java