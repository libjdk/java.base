#include <java/util/stream/SortedOps$OfRef.h>

#include <java/util/Arrays.h>
#include <java/util/Comparator.h>
#include <java/util/Objects.h>
#include <java/util/Spliterator.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/Node.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/PipelineHelper.h>
#include <java/util/stream/ReferencePipeline$StatefulOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/SortedOps$RefSortingSink.h>
#include <java/util/stream/SortedOps$SizedRefSortingSink.h>
#include <java/util/stream/SortedOps.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

#undef IS_ORDERED
#undef IS_SORTED
#undef NOT_SORTED
#undef REFERENCE
#undef SIZED
#undef SORTED

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Comparator = ::java::util::Comparator;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $Node = ::java::util::stream::Node;
using $Nodes = ::java::util::stream::Nodes;
using $PipelineHelper = ::java::util::stream::PipelineHelper;
using $ReferencePipeline$StatefulOp = ::java::util::stream::ReferencePipeline$StatefulOp;
using $Sink = ::java::util::stream::Sink;
using $SortedOps$RefSortingSink = ::java::util::stream::SortedOps$RefSortingSink;
using $SortedOps$SizedRefSortingSink = ::java::util::stream::SortedOps$SizedRefSortingSink;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _SortedOps$OfRef_FieldInfo_[] = {
	{"isNaturalSort", "Z", nullptr, $PRIVATE | $FINAL, $field(SortedOps$OfRef, isNaturalSort)},
	{"comparator", "Ljava/util/Comparator;", "Ljava/util/Comparator<-TT;>;", $PRIVATE | $FINAL, $field(SortedOps$OfRef, comparator)},
	{}
};

$MethodInfo _SortedOps$OfRef_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/AbstractPipeline;)V", "(Ljava/util/stream/AbstractPipeline<*TT;*>;)V", 0, $method(SortedOps$OfRef, init$, void, $AbstractPipeline*)},
	{"<init>", "(Ljava/util/stream/AbstractPipeline;Ljava/util/Comparator;)V", "(Ljava/util/stream/AbstractPipeline<*TT;*>;Ljava/util/Comparator<-TT;>;)V", 0, $method(SortedOps$OfRef, init$, void, $AbstractPipeline*, $Comparator*)},
	{"opEvaluateParallel", "(Ljava/util/stream/PipelineHelper;Ljava/util/Spliterator;Ljava/util/function/IntFunction;)Ljava/util/stream/Node;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/PipelineHelper<TT;>;Ljava/util/Spliterator<TP_IN;>;Ljava/util/function/IntFunction<[TT;>;)Ljava/util/stream/Node<TT;>;", $PUBLIC, $virtualMethod(SortedOps$OfRef, opEvaluateParallel, $Node*, $PipelineHelper*, $Spliterator*, $IntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TT;>;)Ljava/util/stream/Sink<TT;>;", $PUBLIC, $virtualMethod(SortedOps$OfRef, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$InnerClassInfo _SortedOps$OfRef_InnerClassesInfo_[] = {
	{"java.util.stream.SortedOps$OfRef", "java.util.stream.SortedOps", "OfRef", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.ReferencePipeline$StatefulOp", "java.util.stream.ReferencePipeline", "StatefulOp", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SortedOps$OfRef_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.SortedOps$OfRef",
	"java.util.stream.ReferencePipeline$StatefulOp",
	nullptr,
	_SortedOps$OfRef_FieldInfo_,
	_SortedOps$OfRef_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/stream/ReferencePipeline$StatefulOp<TT;TT;>;",
	nullptr,
	_SortedOps$OfRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SortedOps"
};

$Object* allocate$SortedOps$OfRef($Class* clazz) {
	return $of($alloc(SortedOps$OfRef));
}

void SortedOps$OfRef::init$($AbstractPipeline* upstream) {
	$init($StreamShape);
	$init($StreamOpFlag);
	$ReferencePipeline$StatefulOp::init$(upstream, $StreamShape::REFERENCE, $StreamOpFlag::IS_ORDERED | $StreamOpFlag::IS_SORTED);
	this->isNaturalSort = true;
	$var($Comparator, comp, $Comparator::naturalOrder());
	$set(this, comparator, comp);
}

void SortedOps$OfRef::init$($AbstractPipeline* upstream, $Comparator* comparator) {
	$init($StreamShape);
	$init($StreamOpFlag);
	$ReferencePipeline$StatefulOp::init$(upstream, $StreamShape::REFERENCE, $StreamOpFlag::IS_ORDERED | $StreamOpFlag::NOT_SORTED);
	this->isNaturalSort = false;
	$set(this, comparator, $cast($Comparator, $Objects::requireNonNull(comparator)));
}

$Sink* SortedOps$OfRef::opWrapSink(int32_t flags, $Sink* sink) {
	$Objects::requireNonNull(sink);
	$init($StreamOpFlag);
	if ($StreamOpFlag::SORTED->isKnown(flags) && this->isNaturalSort) {
		return sink;
	} else {
		if ($StreamOpFlag::SIZED->isKnown(flags)) {
			return $new($SortedOps$SizedRefSortingSink, sink, this->comparator);
		} else {
			return $new($SortedOps$RefSortingSink, sink, this->comparator);
		}
	}
}

$Node* SortedOps$OfRef::opEvaluateParallel($PipelineHelper* helper, $Spliterator* spliterator, $IntFunction* generator) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag);
	if ($StreamOpFlag::SORTED->isKnown($nc(helper)->getStreamAndOpFlags()) && this->isNaturalSort) {
		return $nc(helper)->evaluate(spliterator, false, generator);
	} else {
		$var($ObjectArray, flattenedData, $nc($($nc(helper)->evaluate(spliterator, true, generator)))->asArray(generator));
		$Arrays::parallelSort(flattenedData, this->comparator);
		return $Nodes::node(flattenedData);
	}
}

SortedOps$OfRef::SortedOps$OfRef() {
}

$Class* SortedOps$OfRef::load$($String* name, bool initialize) {
	$loadClass(SortedOps$OfRef, name, initialize, &_SortedOps$OfRef_ClassInfo_, allocate$SortedOps$OfRef);
	return class$;
}

$Class* SortedOps$OfRef::class$ = nullptr;

		} // stream
	} // util
} // java