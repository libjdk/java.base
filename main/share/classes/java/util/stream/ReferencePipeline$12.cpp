#include <java/util/stream/ReferencePipeline$12.h>

#include <java/util/function/BiConsumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$12$1.h>
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
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$12$1 = ::java::util::stream::ReferencePipeline$12$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$12_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$12, this$0)},
	{"val$mapper", "Ljava/util/function/BiConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$12, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$12_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/BiConsumer;)V", nullptr, 0, $method(ReferencePipeline$12, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $BiConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$12, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$12_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapMultiToInt",
	"(Ljava/util/function/BiConsumer;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _ReferencePipeline$12_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$12", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$12$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$12_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$12",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$12_FieldInfo_,
	_ReferencePipeline$12_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$12_EnclosingMethodInfo_,
	_ReferencePipeline$12_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$12($Class* clazz) {
	return $of($alloc(ReferencePipeline$12));
}

void ReferencePipeline$12::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $BiConsumer* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$12::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$12$1, this, sink);
}

ReferencePipeline$12::ReferencePipeline$12() {
}

$Class* ReferencePipeline$12::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$12, name, initialize, &_ReferencePipeline$12_ClassInfo_, allocate$ReferencePipeline$12);
	return class$;
}

$Class* ReferencePipeline$12::class$ = nullptr;

		} // stream
	} // util
} // java