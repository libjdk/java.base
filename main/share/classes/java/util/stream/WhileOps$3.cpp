#include <java/util/stream/WhileOps$3.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/LongPredicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$StatefulOp.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/WhileOps$3$1.h>
#include <java/util/stream/WhileOps$TakeWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong$Taking.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <java/util/stream/WhileOps.h>
#include <jcpp.h>

#undef ORDERED

using $LongArray = $Array<::java::lang::Long>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $IntFunction = ::java::util::function::IntFunction;
using $LongPredicate = ::java::util::function::LongPredicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline$StatefulOp = ::java::util::stream::LongPipeline$StatefulOp;
using $Node = ::java::util::stream::Node;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $WhileOps$3$1 = ::java::util::stream::WhileOps$3$1;
using $WhileOps$TakeWhileTask = ::java::util::stream::WhileOps$TakeWhileTask;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfLong = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong;
using $WhileOps$UnorderedWhileSpliterator$OfLong$Taking = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong$Taking;

namespace java {
	namespace util {
		namespace stream {

class WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(WhileOps$3::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _WhileOps$3_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/LongPredicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$3, val$predicate)},
	{}
};

$MethodInfo _WhileOps$3_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongPredicate;)V", nullptr, 0, $method(WhileOps$3, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $LongPredicate*)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WhileOps$3, lambda$opEvaluateParallelLazy$0, $LongArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Long;>;)Ljava/util/stream/Node<Ljava/lang/Long;>;", 0, $virtualMethod(WhileOps$3, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Long;>;", 0, $virtualMethod(WhileOps$3, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(WhileOps$3, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _WhileOps$3_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeTakeWhileLong",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _WhileOps$3_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$3", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatefulOp", "java.util.stream.LongPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$3$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WhileOps$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$3",
	"java.util.stream.LongPipeline$StatefulOp",
	nullptr,
	_WhileOps$3_FieldInfo_,
	_WhileOps$3_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatefulOp<Ljava/lang/Long;>;",
	&_WhileOps$3_EnclosingMethodInfo_,
	_WhileOps$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$3($Class* clazz) {
	return $of($alloc(WhileOps$3));
}

void WhileOps$3::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongPredicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$LongPipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$3::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, static_cast<$IntFunction*>($$new(WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0)))))->spliterator();
	} else {
		return static_cast<$Spliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator$OfLong*>($new($WhileOps$UnorderedWhileSpliterator$OfLong$Taking, $cast($Spliterator$OfLong, $($nc(helper)->wrapSpliterator(spliterator))), false, this->val$predicate))));
	}
}

$Node* WhileOps$3::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$TakeWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$3::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($WhileOps$3$1, this, sink);
}

$LongArray* WhileOps$3::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(WhileOps$3);
	return $new($LongArray, x$0);
}

WhileOps$3::WhileOps$3() {
}

$Class* WhileOps$3::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return WhileOps$3$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(WhileOps$3, name, initialize, &_WhileOps$3_ClassInfo_, allocate$WhileOps$3);
	return class$;
}

$Class* WhileOps$3::class$ = nullptr;

		} // stream
	} // util
} // java