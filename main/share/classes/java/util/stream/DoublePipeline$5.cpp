#include <java/util/stream/DoublePipeline$5.h>

#include <java/util/function/DoubleFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$5$1.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/DoublePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DoubleFunction = ::java::util::function::DoubleFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline = ::java::util::stream::DoublePipeline;
using $DoublePipeline$5$1 = ::java::util::stream::DoublePipeline$5$1;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$5_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$5, this$0)},
	{"val$mapper", "Ljava/util/function/DoubleFunction;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$5, val$mapper)},
	{}
};

$MethodInfo _DoublePipeline$5_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoubleFunction;)V", nullptr, 0, $method(DoublePipeline$5, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoubleFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$5, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$5_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"flatMap",
	"(Ljava/util/function/DoubleFunction;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _DoublePipeline$5_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$5$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline$5_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$5",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_DoublePipeline$5_FieldInfo_,
	_DoublePipeline$5_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Double;>;",
	&_DoublePipeline$5_EnclosingMethodInfo_,
	_DoublePipeline$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$5($Class* clazz) {
	return $of($alloc(DoublePipeline$5));
}

void DoublePipeline$5::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoubleFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$5::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$5$1, this, sink);
}

DoublePipeline$5::DoublePipeline$5() {
}

$Class* DoublePipeline$5::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$5, name, initialize, &_DoublePipeline$5_ClassInfo_, allocate$DoublePipeline$5);
	return class$;
}

$Class* DoublePipeline$5::class$ = nullptr;

		} // stream
	} // util
} // java