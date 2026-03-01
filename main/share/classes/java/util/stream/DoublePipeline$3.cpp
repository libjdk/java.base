#include <java/util/stream/DoublePipeline$3.h>

#include <java/util/function/DoubleToIntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$3$1.h>
#include <java/util/stream/DoublePipeline.h>
#include <java/util/stream/IntPipeline$StatelessOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DoubleToIntFunction = ::java::util::function::DoubleToIntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline = ::java::util::stream::DoublePipeline;
using $DoublePipeline$3$1 = ::java::util::stream::DoublePipeline$3$1;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$3_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$3, this$0)},
	{"val$mapper", "Ljava/util/function/DoubleToIntFunction;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$3, val$mapper)},
	{}
};

$MethodInfo _DoublePipeline$3_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoubleToIntFunction;)V", nullptr, 0, $method(DoublePipeline$3, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoubleToIntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$3, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$3_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"mapToInt",
	"(Ljava/util/function/DoubleToIntFunction;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _DoublePipeline$3_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$3$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$3",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_DoublePipeline$3_FieldInfo_,
	_DoublePipeline$3_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<Ljava/lang/Double;>;",
	&_DoublePipeline$3_EnclosingMethodInfo_,
	_DoublePipeline$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$3($Class* clazz) {
	return $of($alloc(DoublePipeline$3));
}

void DoublePipeline$3::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoubleToIntFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$3::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$3$1, this, sink);
}

DoublePipeline$3::DoublePipeline$3() {
}

$Class* DoublePipeline$3::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$3, name, initialize, &_DoublePipeline$3_ClassInfo_, allocate$DoublePipeline$3);
	return class$;
}

$Class* DoublePipeline$3::class$ = nullptr;

		} // stream
	} // util
} // java