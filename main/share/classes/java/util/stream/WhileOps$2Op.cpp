#include <java/util/stream/WhileOps$2Op.h>

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
#include <java/util/stream/WhileOps$2Op$1OpSink.h>
#include <java/util/stream/WhileOps$DropWhileSink.h>
#include <java/util/stream/WhileOps$DropWhileTask.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt$Dropping.h>
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
using $WhileOps$2Op$1OpSink = ::java::util::stream::WhileOps$2Op$1OpSink;
using $WhileOps$DropWhileSink = ::java::util::stream::WhileOps$DropWhileSink;
using $WhileOps$DropWhileTask = ::java::util::stream::WhileOps$DropWhileTask;
using $WhileOps$UnorderedWhileSpliterator = ::java::util::stream::WhileOps$UnorderedWhileSpliterator;
using $WhileOps$UnorderedWhileSpliterator$OfInt = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt;
using $WhileOps$UnorderedWhileSpliterator$OfInt$Dropping = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt$Dropping;

namespace java {
	namespace util {
		namespace stream {

class WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0 : public $IntFunction {
	$class(WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(WhileOps$2Op::lambda$opEvaluateParallelLazy$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0, apply, $Object*, int32_t)},
	{}
};
$ClassInfo WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0::load$($String* name, bool initialize) {
	$loadClass(WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0::class$ = nullptr;

$FieldInfo _WhileOps$2Op_FieldInfo_[] = {
	{"val$predicate", "Ljava/util/function/IntPredicate;", nullptr, $FINAL | $SYNTHETIC, $field(WhileOps$2Op, val$predicate)},
	{}
};

$MethodInfo _WhileOps$2Op_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntPredicate;)V", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Integer;*>;Ljava/util/stream/StreamShape;I)V", $PUBLIC, $method(WhileOps$2Op, init$, void, $AbstractPipeline*, $StreamShape*, int32_t, $IntPredicate*)},
	{"lambda$opEvaluateParallelLazy$0", "(I)[Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WhileOps$2Op, lambda$opEvaluateParallelLazy$0, $IntegerArray*, int32_t)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Integer;>;)Ljava/util/stream/Node<Ljava/lang/Integer;>;", 0, $virtualMethod(WhileOps$2Op, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opEvaluateParallelLazy", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Integer;>;Ljava/util/Spliterator<TP_IN;>;)Ljava/util/Spliterator<Ljava/lang/Integer;>;", 0, $virtualMethod(WhileOps$2Op, opEvaluateParallelLazy, $Spliterator*, $PipelineHelper*, $Spliterator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(WhileOps$2Op, opWrapSink, $Sink*, int32_t, $Sink*)},
	{"opWrapSink", "(Ljava/util/stream/Sink;Z)Ljava/util/stream/WhileOps$DropWhileSink;", "(Ljava/util/stream/Sink<Ljava/lang/Integer;>;Z)Ljava/util/stream/WhileOps$DropWhileSink<Ljava/lang/Integer;>;", $PUBLIC, $virtualMethod(WhileOps$2Op, opWrapSink, $WhileOps$DropWhileSink*, $Sink*, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _WhileOps$2Op_EnclosingMethodInfo_ = {
	"java.util.stream.WhileOps",
	"makeDropWhileInt",
	"(Ljava/util/stream/AbstractPipeline;Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _WhileOps$2Op_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$2Op", nullptr, "Op", 0},
	{"java.util.stream.IntPipeline$StatefulOp", "java.util.stream.IntPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$DropWhileOp", "java.util.stream.WhileOps", "DropWhileOp", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.WhileOps$2Op$1OpSink", nullptr, "OpSink", 0},
	{}
};

$ClassInfo _WhileOps$2Op_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.WhileOps$2Op",
	"java.util.stream.IntPipeline$StatefulOp",
	"java.util.stream.WhileOps$DropWhileOp",
	_WhileOps$2Op_FieldInfo_,
	_WhileOps$2Op_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatefulOp<Ljava/lang/Integer;>;Ljava/util/stream/WhileOps$DropWhileOp<Ljava/lang/Integer;>;",
	&_WhileOps$2Op_EnclosingMethodInfo_,
	_WhileOps$2Op_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$2Op($Class* clazz) {
	return $of($alloc(WhileOps$2Op));
}

int32_t WhileOps$2Op::hashCode() {
	 return this->$IntPipeline$StatefulOp::hashCode();
}

bool WhileOps$2Op::equals(Object$* obj) {
	 return this->$IntPipeline$StatefulOp::equals(obj);
}

$Object* WhileOps$2Op::clone() {
	 return this->$IntPipeline$StatefulOp::clone();
}

$String* WhileOps$2Op::toString() {
	 return this->$IntPipeline$StatefulOp::toString();
}

void WhileOps$2Op::finalize() {
	this->$IntPipeline$StatefulOp::finalize();
}

void WhileOps$2Op::init$($AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntPredicate* val$predicate) {
	$set(this, val$predicate, val$predicate);
	$IntPipeline$StatefulOp::init$(upstream, inputShape, opFlags);
}

$Spliterator* WhileOps$2Op::opEvaluateParallelLazy($PipelineHelper* helper, $Spliterator* spliterator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::ORDERED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc($(opEvaluateParallel(helper, spliterator, static_cast<$IntFunction*>($$new(WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0)))))->spliterator();
	} else {
		return static_cast<$Spliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator*>(static_cast<$WhileOps$UnorderedWhileSpliterator$OfInt*>($new($WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, $cast($Spliterator$OfInt, $($nc(helper)->wrapSpliterator(spliterator))), false, this->val$predicate))));
	}
}

$Node* WhileOps$2Op::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	return $cast($Node, $$new($WhileOps$DropWhileTask, this, helper, spliterator, generator)->invoke());
}

$Sink* WhileOps$2Op::opWrapSink(int32_t flags, $Sink* sink) {
	return opWrapSink(sink, false);
}

$WhileOps$DropWhileSink* WhileOps$2Op::opWrapSink($Sink* sink, bool retainAndCountDroppedElements) {
	{
	}
	return $new($WhileOps$2Op$1OpSink, this, sink, retainAndCountDroppedElements);
}

$IntegerArray* WhileOps$2Op::lambda$opEvaluateParallelLazy$0(int32_t x$0) {
	$init(WhileOps$2Op);
	return $new($IntegerArray, x$0);
}

WhileOps$2Op::WhileOps$2Op() {
}

$Class* WhileOps$2Op::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0::classInfo$.name)) {
			return WhileOps$2Op$$Lambda$lambda$opEvaluateParallelLazy$0::load$(name, initialize);
		}
	}
	$loadClass(WhileOps$2Op, name, initialize, &_WhileOps$2Op_ClassInfo_, allocate$WhileOps$2Op);
	return class$;
}

$Class* WhileOps$2Op::class$ = nullptr;

		} // stream
	} // util
} // java