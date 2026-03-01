#include <java/util/stream/DoublePipeline$2.h>

#include <java/util/function/DoubleUnaryOperator.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$2$1.h>
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
using $DoubleUnaryOperator = ::java::util::function::DoubleUnaryOperator;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline = ::java::util::stream::DoublePipeline;
using $DoublePipeline$2$1 = ::java::util::stream::DoublePipeline$2$1;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$2_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$2, this$0)},
	{"val$mapper", "Ljava/util/function/DoubleUnaryOperator;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$2, val$mapper)},
	{}
};

$MethodInfo _DoublePipeline$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoubleUnaryOperator;)V", nullptr, 0, $method(DoublePipeline$2, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoubleUnaryOperator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$2, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$2_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"map",
	"(Ljava/util/function/DoubleUnaryOperator;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _DoublePipeline$2_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$2",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_DoublePipeline$2_FieldInfo_,
	_DoublePipeline$2_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Double;>;",
	&_DoublePipeline$2_EnclosingMethodInfo_,
	_DoublePipeline$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$2($Class* clazz) {
	return $of($alloc(DoublePipeline$2));
}

void DoublePipeline$2::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoubleUnaryOperator* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$2::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$2$1, this, sink);
}

DoublePipeline$2::DoublePipeline$2() {
}

$Class* DoublePipeline$2::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$2, name, initialize, &_DoublePipeline$2_ClassInfo_, allocate$DoublePipeline$2);
	return class$;
}

$Class* DoublePipeline$2::class$ = nullptr;

		} // stream
	} // util
} // java