#include <java/util/stream/WhileOps$3Op.h>

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
#include <java/util/stream/WhileOps$3Op$1OpSink.h>
#include <java/util/stream/WhileOps$DropWhileSink.h>
#include <java/util/stream/WhileOps$DropWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong$Dropping.h>
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
using $WhileOps$3Op$1OpSink = ::java::util::stream::WhileOps$3Op$1OpSink;
using $WhileOps$DropWhileSink = ::java::util::stream::WhileOps$DropWhileSink;
using $WhileOps$DropWhileTask = ::java::util::stream::WhileOps$DropWhileTask;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfLong = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong;
using $WhileOps$UnorderedWhileSpliterator$OfLong$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong$Dropping;

namespace java {
	namespace util {
		namespace stream {

class WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(WhileOps$3Op::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _WhileOps$3Op_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/LongPredicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$3Op, val$predicate)},
	{}
};

$MethodInfo _WhileOps$3Op_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongPredicate;)V", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Long;*>;Ljava/util/stream/StreamShape;I)V", $PUBLIC, $method(WhileOps$3Op, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $LongPredicate*)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WhileOps$3Op, lambda$opEvaluateParallelLazy$0, $LongArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Long;>;)Ljava/util/stream/Node<Ljava/lang/Long;>;", 0, $virtualMethod(WhileOps$3Op, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Long;>;", 0, $virtualMethod(WhileOps$3Op, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(WhileOps$3Op, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"opWrapSink", "(Ljava/util/stream/Sink;Z)Ljava/util/stream/WhileOps$DropWhileSink;", "(Ljava/util/stream/Sink<Ljava/lang/Long;>;Z)Ljava/util/stream/WhileOps$DropWhileSink<Ljava/lang/Long;>;", $PUBLIC, $virtualMethod(WhileOps$3Op, opWrapSink, $WhileOps$DropWhileSink*, $Sink*, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _WhileOps$3Op_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeDropWhileLong",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/LongPredicate;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _WhileOps$3Op_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$3Op", nullptr, "Op", 0},
	{"java.util.stream.LongPipeline$StatefulOp", "java.util.stream.LongPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$DropWhileOp", "java.util.stream.WhileOps", "DropWhileOp", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$3Op$1OpSink", nullptr, "OpSink", 0},
	{}
};

$ClassInfo _WhileOps$3Op_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$3Op",
	"java.util.stream.LongPipeline$StatefulOp",
	"java.util.stream.WhileOps$DropWhileOp",
	_WhileOps$3Op_FieldInfo_,
	_WhileOps$3Op_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatefulOp<Ljava/lang/Long;>;Ljava/util/stream/WhileOps$DropWhileOp<Ljava/lang/Long;>;",
	&_WhileOps$3Op_EnclosingMethodInfo_,
	_WhileOps$3Op_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$3Op($Class* clazz) {
	return $of($alloc(WhileOps$3Op));
}

int32_t WhileOps$3Op::hashCode() {
	 return this->$LongPipeline$StatefulOp::hashCode();
}

bool WhileOps$3Op::equals(Object$* obj) {
	 return this->$LongPipeline$StatefulOp::equals(obj);
}

$Object* WhileOps$3Op::clone() {
	 return this->$LongPipeline$StatefulOp::clone();
}

$String* WhileOps$3Op::toString() {
	 return this->$LongPipeline$StatefulOp::toString();
}

void WhileOps$3Op::finalize() {
	this->$LongPipeline$StatefulOp::finalize();
}

void WhileOps$3Op::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongPredicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$LongPipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$3Op::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, static_cast<$IntFunction*>($$new(WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0)))))->spliterator();
	} else {
		return static_cast<$Spliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator$OfLong*>($new($WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, $cast($Spliterator$OfLong, $($nc(helper)->wrapSpliterator(spliterator))), false, this->val$predicate))));
	}
}

$Node* WhileOps$3Op::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$DropWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$3Op::opWrapSink(int32_t flags, $Sink* sink) {
	return opWrapSink(sink, false);
}

$WhileOps$DropWhileSink* WhileOps$3Op::opWrapSink($Sink* sink, bool retainAndCountDroppedElements) {
	{
	}
	return $new($WhileOps$3Op$1OpSink, this, sink, retainAndCountDroppedElements);
}

$LongArray* WhileOps$3Op::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(WhileOps$3Op);
	return $new($LongArray, x$0);
}

WhileOps$3Op::WhileOps$3Op() {
}

$Class* WhileOps$3Op::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return WhileOps$3Op$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(WhileOps$3Op, name, initialize, &_WhileOps$3Op_ClassInfo_, allocate$WhileOps$3Op);
	return class$;
}

$Class* WhileOps$3Op::class$ = nullptr;

		} // stream
	} // util
} // java