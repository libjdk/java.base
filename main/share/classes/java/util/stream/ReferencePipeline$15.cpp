#include <java/util/stream/ReferencePipeline$15.h>

#include <java/util/function/Consumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/ReferencePipeline$15$1.h>
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
using $Consumer = ::java::util::function::Consumer;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$15$1 = ::java::util::stream::ReferencePipeline$15$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$15_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$15, this$0)},
	{"val$action", "Ljava/util/function/Consumer;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$15, val$action)},
	{}
};

$MethodInfo _ReferencePipeline$15_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/Consumer;)V", nullptr, 0, $method(ReferencePipeline$15, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $Consumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TP_OUT;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$15, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$15_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"peek",
	"(Ljava/util/function/Consumer;)Ljava/util/stream/Stream;"
};

$InnerClassInfo _ReferencePipeline$15_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$15", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$15$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$15_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$15",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$15_FieldInfo_,
	_ReferencePipeline$15_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<TP_OUT;TP_OUT;>;",
	&_ReferencePipeline$15_EnclosingMethodInfo_,
	_ReferencePipeline$15_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$15($Class* clazz) {
	return $of($alloc(ReferencePipeline$15));
}

void ReferencePipeline$15::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $Consumer* val$action) {
	$set(this, this$0, this$0);
	$set(this, val$action, val$action);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$15::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$15$1, this, sink);
}

ReferencePipeline$15::ReferencePipeline$15() {
}

$Class* ReferencePipeline$15::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$15, name, initialize, &_ReferencePipeline$15_ClassInfo_, allocate$ReferencePipeline$15);
	return class$;
}

$Class* ReferencePipeline$15::class$ = nullptr;

		} // stream
	} // util
} // java