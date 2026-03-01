#include <java/util/stream/ReduceOps$ReduceTask.h>

#include <java/util/Spliterator.h>
#include <java/util/concurrent/CountedCompleter.h>
#include <java/util/stream/AbstractTask.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReduceOps$AccumulatingSink.h>
#include <java/util/stream/ReduceOps$ReduceOp.h>
#include <java/util/stream/ReduceOps.h>
#include <java/util/stream/Sink.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $CountedCompleter = ::java::util::concurrent::CountedCompleter;
using $AbstractTask = ::java::util::stream::AbstractTask;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReduceOps$AccumulatingSink = ::java::util::stream::ReduceOps$AccumulatingSink;
using $ReduceOps$ReduceOp = ::java::util::stream::ReduceOps$ReduceOp;
using $Sink = ::java::util::stream::Sink;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReduceOps$ReduceTask_FieldInfo_[] = {
	{"op", "Ljava/util/stream/ReduceOps$ReduceOp;", "Ljava/util/stream/ReduceOps$ReduceOp<TP_OUT;TR;TS;>;", $PRIVATE | $FINAL, $field(ReduceOps$ReduceTask, op)},
	{}
};

$MethodInfo _ReduceOps$ReduceTask_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReduceOps$ReduceOp;Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;)V", "(Ljava/util/stream/ReduceOps$ReduceOp<TP_OUT;TR;TS;>;Ljava/util/stream/PipelineHelper<TP_OUT;>;Ljava/util/Spliterator<TP_IN;>;)V", 0, $method(ReduceOps$ReduceTask, init$, void, $ReduceOps$ReduceOp*, $PipelineHelper*, $Spliterator*)},
	{"<init>", "(Ljava/util/stream/ReduceOps$ReduceTask;Ljava/util/Spliterator;)V", "(Ljava/util/stream/ReduceOps$ReduceTask<TP_IN;TP_OUT;TR;TS;>;Ljava/util/Spliterator<TP_IN;>;)V", 0, $method(ReduceOps$ReduceTask, init$, void, ReduceOps$ReduceTask*, $Spliterator*)},
	{"doLeaf", "()Ljava/util/stream/ReduceOps$AccumulatingSink;", "()TS;", $PROTECTED, $virtualMethod(ReduceOps$ReduceTask, doLeaf, $Object*)},
	{"makeChild", "(Ljava/util/Spliterator;)Ljava/util/stream/ReduceOps$ReduceTask;", "(Ljava/util/Spliterator<TP_IN;>;)Ljava/util/stream/ReduceOps$ReduceTask<TP_IN;TP_OUT;TR;TS;>;", $PROTECTED, $virtualMethod(ReduceOps$ReduceTask, makeChild, ReduceOps$ReduceTask*, $Spliterator*)},
	{"onCompletion", "(Ljava/util/concurrent/CountedCompleter;)V", "(Ljava/util/concurrent/CountedCompleter<*>;)V", $PUBLIC, $virtualMethod(ReduceOps$ReduceTask, onCompletion, void, $CountedCompleter*)},
	{}
};

$InnerClassInfo _ReduceOps$ReduceTask_InnerClassesInfo_[] = {
	{"java.util.stream.ReduceOps$ReduceTask", "java.util.stream.ReduceOps", "ReduceTask", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.ReduceOps$AccumulatingSink", "java.util.stream.ReduceOps", "AccumulatingSink", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ReduceOps$ReduceTask_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.ReduceOps$ReduceTask",
	"java.util.stream.AbstractTask",
	nullptr,
	_ReduceOps$ReduceTask_FieldInfo_,
	_ReduceOps$ReduceTask_MethodInfo_,
	"<P_IN:Ljava/lang/Object;P_OUT:Ljava/lang/Object;R:Ljava/lang/Object;S::Ljava/util/stream/ReduceOps$AccumulatingSink<TP_OUT;TR;TS;>;>Ljava/util/stream/AbstractTask<TP_IN;TP_OUT;TS;Ljava/util/stream/ReduceOps$ReduceTask<TP_IN;TP_OUT;TR;TS;>;>;",
	nullptr,
	_ReduceOps$ReduceTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReduceOps"
};

$Object* allocate$ReduceOps$ReduceTask($Class* clazz) {
	return $of($alloc(ReduceOps$ReduceTask));
}

void ReduceOps$ReduceTask::init$($ReduceOps$ReduceOp* op, $PipelineHelper* helper, $Spliterator* spliterator) {
	$AbstractTask::init$(helper, spliterator);
	$set(this, op, op);
}

void ReduceOps$ReduceTask::init$(ReduceOps$ReduceTask* parent, $Spliterator* spliterator) {
	$AbstractTask::init$(static_cast<$AbstractTask*>(parent), spliterator);
	$set(this, op, $nc(parent)->op);
}

ReduceOps$ReduceTask* ReduceOps$ReduceTask::makeChild($Spliterator* spliterator) {
	return $new(ReduceOps$ReduceTask, this, spliterator);
}

$Object* ReduceOps$ReduceTask::doLeaf() {
	return $of($cast($ReduceOps$AccumulatingSink, $nc(this->helper)->wrapAndCopyInto($($nc(this->op)->makeSink()), this->spliterator)));
}

void ReduceOps$ReduceTask::onCompletion($CountedCompleter* caller) {
	$useLocalCurrentObjectStackCache();
	if (!isLeaf()) {
		$var($ReduceOps$AccumulatingSink, leftResult, $cast($ReduceOps$AccumulatingSink, $nc(($cast(ReduceOps$ReduceTask, this->leftChild)))->getLocalResult()));
		$nc(leftResult)->combine($cast($ReduceOps$AccumulatingSink, $($nc(($cast(ReduceOps$ReduceTask, this->rightChild)))->getLocalResult())));
		setLocalResult(leftResult);
	}
	$AbstractTask::onCompletion(caller);
}

ReduceOps$ReduceTask::ReduceOps$ReduceTask() {
}

$Class* ReduceOps$ReduceTask::load$($String* name, bool initialize) {
	$loadClass(ReduceOps$ReduceTask, name, initialize, &_ReduceOps$ReduceTask_ClassInfo_, allocate$ReduceOps$ReduceTask);
	return class$;
}

$Class* ReduceOps$ReduceTask::class$ = nullptr;

		} // stream
	} // util
} // java