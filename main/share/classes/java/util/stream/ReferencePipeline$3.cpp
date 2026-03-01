#include <java/util/stream/ReferencePipeline$3.h>

#include <java/util/function/Function.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/ReferencePipeline$3$1.h>
#include <java/util/stream/ReferencePipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Function = ::java::util::function::Function;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$3$1 = ::java::util::stream::ReferencePipeline$3$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$3_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$3, this$0)},
	{"val$mapper", "Ljava/util/function/Function;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$3, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$3_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/Function;)V", nullptr, 0, $method(ReferencePipeline$3, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $Function*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TR;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$3, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$3_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"map",
	"(Ljava/util/function/Function;)Ljava/util/stream/Stream;"
};

$InnerClassInfo _ReferencePipeline$3_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$3$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$3",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$3_FieldInfo_,
	_ReferencePipeline$3_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<TP_OUT;TR;>;",
	&_ReferencePipeline$3_EnclosingMethodInfo_,
	_ReferencePipeline$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$3($Class* clazz) {
	return $of($alloc(ReferencePipeline$3));
}

void ReferencePipeline$3::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $Function* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$3::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$3$1, this, sink);
}

ReferencePipeline$3::ReferencePipeline$3() {
}

$Class* ReferencePipeline$3::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$3, name, initialize, &_ReferencePipeline$3_ClassInfo_, allocate$ReferencePipeline$3);
	return class$;
}

$Class* ReferencePipeline$3::class$ = nullptr;

		} // stream
	} // util
} // java