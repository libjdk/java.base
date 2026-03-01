#include <java/util/stream/ReferencePipeline$11.h>

#include <java/util/function/BiConsumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/ReferencePipeline$11$1.h>
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
using $BiConsumer = ::java::util::function::BiConsumer;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$11$1 = ::java::util::stream::ReferencePipeline$11$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$11_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$11, this$0)},
	{"val$mapper", "Ljava/util/function/BiConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$11, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$11_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/BiConsumer;)V", nullptr, 0, $method(ReferencePipeline$11, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $BiConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TR;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$11, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$11_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapMulti",
	"(Ljava/util/function/BiConsumer;)Ljava/util/stream/Stream;"
};

$InnerClassInfo _ReferencePipeline$11_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$11", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$11$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$11_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$11",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$11_FieldInfo_,
	_ReferencePipeline$11_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<TP_OUT;TR;>;",
	&_ReferencePipeline$11_EnclosingMethodInfo_,
	_ReferencePipeline$11_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$11($Class* clazz) {
	return $of($alloc(ReferencePipeline$11));
}

void ReferencePipeline$11::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $BiConsumer* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$11::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$11$1, this, sink);
}

ReferencePipeline$11::ReferencePipeline$11() {
}

$Class* ReferencePipeline$11::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$11, name, initialize, &_ReferencePipeline$11_ClassInfo_, allocate$ReferencePipeline$11);
	return class$;
}

$Class* ReferencePipeline$11::class$ = nullptr;

		} // stream
	} // util
} // java