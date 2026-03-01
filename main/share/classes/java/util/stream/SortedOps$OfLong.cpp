#include <java/util/stream/SortedOps$OfLong.h>

#include <java/util/Arrays.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$StatefulOp.h>
#include <java/util/stream/Node$OfLong.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SortedOps$LongSortingSink.h>
#include <java/util/stream/SortedOps$SizedLongSortingSink.h>
#include <java/util/stream/SortedOps.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef IS_ORDERED
#undef IS_SORTED
#undef LONG_VALUE
#undef SIZED
#undef SORTED

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline$StatefulOp = ::java::util::stream::LongPipeline$StatefulOp;
using $Node = ::java::util::stream::Node;
using $Node$OfLong = ::java::util::stream::Node$OfLong;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $Sink = ::java::util::stream::Sink;
using $SortedOps$LongSortingSink = ::java::util::stream::SortedOps$LongSortingSink;
using $SortedOps$SizedLongSortingSink = ::java::util::stream::SortedOps$SizedLongSortingSink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _SortedOps$OfLong_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;)V", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Long;*>;)V", 0, $method(SortedOps$OfLong, init$, void, $AbstractPipeline*)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<Ljava/lang/Long;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[Ljava/lang/Long;>;)Ljava/util/stream/Node<Ljava/lang/Long;>;", $PUBLIC, $virtualMethod(SortedOps$OfLong, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", $PUBLIC, $virtualMethod(SortedOps$OfLong, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$InnerClassInfo _SortedOps$OfLong_InnerClassesInfo_[] = {
	{"java.util.stream.SortedOps$OfLong", "java.util.stream.SortedOps", "OfLong", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.LongPipeline$StatefulOp", "java.util.stream.LongPipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SortedOps$OfLong_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.SortedOps$OfLong",
	"java.util.stream.LongPipeline$StatefulOp",
	nullptr,
	nullptr,
	_SortedOps$OfLong_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatefulOp<Ljava/lang/Long;>;",
	nullptr,
	_SortedOps$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SortedOps"
};

$Object* allocate$SortedOps$OfLong($Class* clazz) {
	return $of($alloc(SortedOps$OfLong));
}

void SortedOps$OfLong::init$($AbstractPipeline* upstream) {
	$init($StreamShape);
	$init($StreamOpFlag);
	$LongPipeline$StatefulOp::init$(upstream, $StreamShape::LONG_VALUE, $StreamOpFlag::IS_ORDERED | $StreamOpFlag::IS_SORTED);
}

$Sink* SortedOps$OfLong::opWrapSink(int32_t flags, $Sink* sink) {
	$Objects::requireNonNull(sink);
	$init($StreamOpFlag);
	if ($StreamOpFlag::SORTED->isKnown(flags)) {
		return sink;
	} else {
		if ($StreamOpFlag::SIZED->isKnown(flags)) {
			return $new($SortedOps$SizedLongSortingSink, sink);
		} else {
			return $new($SortedOps$LongSortingSink, sink);
		}
	}
}

$Node* SortedOps$OfLong::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::SORTED->isKnown($nc(helper)->getStreamAndOpFlags())) {
		return $nc(helper)->evaluate(spliterator, false, generator);
	} else {
		$var($Node$OfLong, n, $cast($Node$OfLong, $nc(helper)->evaluate(spliterator, true, generator)));
		$var($longs, content, $cast($longs, $nc(n)->asPrimitiveArray()));
		$Arrays::parallelSort(content);
		return $Nodes::node(content);
	}
}

SortedOps$OfLong::SortedOps$OfLong() {
}

$Class* SortedOps$OfLong::load$($String* name, bool initialize) {
	$loadClass(SortedOps$OfLong, name, initialize, &_SortedOps$OfLong_ClassInfo_, allocate$SortedOps$OfLong);
	return class$;
}

$Class* SortedOps$OfLong::class$ = nullptr;

		} // stream
	} // util
} // java