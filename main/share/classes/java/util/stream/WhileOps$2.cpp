#include <java/util/stream/WhileOps$2.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/IntPredicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$StatefulOp.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/WhileOps$2$1.h>
#include <java/util/stream/WhileOps$TakeWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt$Taking.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <java/util/stream/WhileOps.h>
#include <jcpp.h>

#undef ORDERED

using $IntegerArray = $Array<::java::lang::Integer>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $IntFunction = ::java::util::function::IntFunction;
using $IntPredicate = ::java::util::function::IntPredicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline$StatefulOp = ::java::util::stream::IntPipeline$StatefulOp;
using $Node = ::java::util::stream::Node;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $WhileOps$2$1 = ::java::util::stream::WhileOps$2$1;
using $WhileOps$TakeWhileTask = ::java::util::stream::WhileOps$TakeWhileTask;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfInt = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt;
using $WhileOps$UnorderedWhileSpliterator$OfInt$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt$Taking;

namespace java {
	namespace util {
		namespace stream {

class WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(WhileOps$2::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _WhileOps$2_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/IntPredicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$2, val$predicate)},
	{}
};

$MethodInfo _WhileOps$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntPredicate;)V", nullptr, 0, $method(WhileOps$2, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $IntPredicate*)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WhileOps$2, lambda$opEvaluateParallelLazy$0, $IntegerArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Integer;>;)Ljava/util/stream/Node<Ljava/lang/Integer;>;", 0, $virtualMethod(WhileOps$2, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Integer;>;", 0, $virtualMethod(WhileOps$2, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(WhileOps$2, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _WhileOps$2_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeTakeWhileInt",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _WhileOps$2_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$2", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatefulOp", "java.util.stream.IntPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WhileOps$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$2",
	"java.util.stream.IntPipeline$StatefulOp",
	nullptr,
	_WhileOps$2_FieldInfo_,
	_WhileOps$2_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatefulOp<Ljava/lang/Integer;>;",
	&_WhileOps$2_EnclosingMethodInfo_,
	_WhileOps$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$2($Class* clazz) {
	return $of($alloc(WhileOps$2));
}

void WhileOps$2::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntPredicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$IntPipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$2::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, static_cast<$IntFunction*>($$new(WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0)))))->spliterator();
	} else {
		return static_cast<$Spliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator$OfInt*>($new($WhileOps$UnorderedWhileSpliterator$OfInt$Taking, $cast($Spliterator$OfInt, $($nc(helper)->wrapSpliterator(spliterator))), false, this->val$predicate))));
	}
}

$Node* WhileOps$2::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$TakeWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$2::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($WhileOps$2$1, this, sink);
}

$IntegerArray* WhileOps$2::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(WhileOps$2);
	return $new($IntegerArray, x$0);
}

WhileOps$2::WhileOps$2() {
}

$Class* WhileOps$2::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return WhileOps$2$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(WhileOps$2, name, initialize, &_WhileOps$2_ClassInfo_, allocate$WhileOps$2);
	return class$;
}

$Class* WhileOps$2::class$ = nullptr;

		} // stream
	} // util
} // java