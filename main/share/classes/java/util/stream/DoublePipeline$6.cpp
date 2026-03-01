#include <java/util/stream/DoublePipeline$6.h>

#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$6$1.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/DoublePipeline.h>
#include <java/util/stream/DoubleStream$DoubleMapMultiConsumer.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline = ::java::util::stream::DoublePipeline;
using $DoublePipeline$6$1 = ::java::util::stream::DoublePipeline$6$1;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $DoubleStream$DoubleMapMultiConsumer = ::java::util::stream::DoubleStream$DoubleMapMultiConsumer;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$6_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$6, this$0)},
	{"val$mapper", "Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$6, val$mapper)},
	{}
};

$MethodInfo _DoublePipeline$6_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/stream/DoubleStream$DoubleMapMultiConsumer;)V", nullptr, 0, $method(DoublePipeline$6, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoubleStream$DoubleMapMultiConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$6, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$6_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"mapMulti",
	"(Ljava/util/stream/DoubleStream$DoubleMapMultiConsumer;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _DoublePipeline$6_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$6", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$6$1", nullptr, nullptr, 0},
	{"java.util.stream.DoubleStream$DoubleMapMultiConsumer", "java.util.stream.DoubleStream", "DoubleMapMultiConsumer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _DoublePipeline$6_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$6",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_DoublePipeline$6_FieldInfo_,
	_DoublePipeline$6_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Double;>;",
	&_DoublePipeline$6_EnclosingMethodInfo_,
	_DoublePipeline$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$6($Class* clazz) {
	return $of($alloc(DoublePipeline$6));
}

void DoublePipeline$6::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoubleStream$DoubleMapMultiConsumer* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$6::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$6$1, this, sink);
}

DoublePipeline$6::DoublePipeline$6() {
}

$Class* DoublePipeline$6::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$6, name, initialize, &_DoublePipeline$6_ClassInfo_, allocate$DoublePipeline$6);
	return class$;
}

$Class* DoublePipeline$6::class$ = nullptr;

		} // stream
	} // util
} // java