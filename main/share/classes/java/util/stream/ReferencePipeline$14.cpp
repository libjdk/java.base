#include <java/util/stream/ReferencePipeline$14.h>

#include <java/util/function/BiConsumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$14$1.h>
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
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$14$1 = ::java::util::stream::ReferencePipeline$14$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$14_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$14, this$0)},
	{"val$mapper", "Ljava/util/function/BiConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$14, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$14_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/BiConsumer;)V", nullptr, 0, $method(ReferencePipeline$14, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $BiConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$14, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$14_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapMultiToDouble",
	"(Ljava/util/function/BiConsumer;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _ReferencePipeline$14_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$14", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$14$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$14_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$14",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$14_FieldInfo_,
	_ReferencePipeline$14_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$14_EnclosingMethodInfo_,
	_ReferencePipeline$14_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$14($Class* clazz) {
	return $of($alloc(ReferencePipeline$14));
}

void ReferencePipeline$14::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $BiConsumer* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$14::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$14$1, this, sink);
}

ReferencePipeline$14::ReferencePipeline$14() {
}

$Class* ReferencePipeline$14::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$14, name, initialize, &_ReferencePipeline$14_ClassInfo_, allocate$ReferencePipeline$14);
	return class$;
}

$Class* ReferencePipeline$14::class$ = nullptr;

		} // stream
	} // util
} // java