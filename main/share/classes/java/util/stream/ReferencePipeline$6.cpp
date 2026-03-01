#include <java/util/stream/ReferencePipeline$6.h>

#include <java/util/function/ToDoubleFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$6$1.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ToDoubleFunction = ::java::util::function::ToDoubleFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$6$1 = ::java::util::stream::ReferencePipeline$6$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$6_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$6, this$0)},
	{"val$mapper", "Ljava/util/function/ToDoubleFunction;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$6, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$6_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/ToDoubleFunction;)V", nullptr, 0, $method(ReferencePipeline$6, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $ToDoubleFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$6, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$6_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapToDouble",
	"(Ljava/util/function/ToDoubleFunction;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _ReferencePipeline$6_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$6", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$6$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$6_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$6",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$6_FieldInfo_,
	_ReferencePipeline$6_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$6_EnclosingMethodInfo_,
	_ReferencePipeline$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$6($Class* clazz) {
	return $of($alloc(ReferencePipeline$6));
}

void ReferencePipeline$6::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $ToDoubleFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$6::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$6$1, this, sink);
}

ReferencePipeline$6::ReferencePipeline$6() {
}

$Class* ReferencePipeline$6::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$6, name, initialize, &_ReferencePipeline$6_ClassInfo_, allocate$ReferencePipeline$6);
	return class$;
}

$Class* ReferencePipeline$6::class$ = nullptr;

		} // stream
	} // util
} // java