#include <java/util/stream/IntPipeline$6.h>

#include <java/util/function/IntToDoubleFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/IntPipeline$6$1.h>
#include <java/util/stream/IntPipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $IntToDoubleFunction = ::java::util::function::IntToDoubleFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$6$1 = ::java::util::stream::IntPipeline$6$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$6_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$6, this$0)},
	{"val$mapper", "Ljava/util/function/IntToDoubleFunction;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$6, val$mapper)},
	{}
};

$MethodInfo _IntPipeline$6_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntToDoubleFunction;)V", nullptr, 0, $method(IntPipeline$6, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntToDoubleFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$6, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$6_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"mapToDouble",
	"(Ljava/util/function/IntToDoubleFunction;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _IntPipeline$6_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$6", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$6$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$6_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$6",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_IntPipeline$6_FieldInfo_,
	_IntPipeline$6_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$6_EnclosingMethodInfo_,
	_IntPipeline$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$6($Class* clazz) {
	return $of($alloc(IntPipeline$6));
}

void IntPipeline$6::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntToDoubleFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$6::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$6$1, this, sink);
}

IntPipeline$6::IntPipeline$6() {
}

$Class* IntPipeline$6::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$6, name, initialize, &_IntPipeline$6_ClassInfo_, allocate$IntPipeline$6);
	return class$;
}

$Class* IntPipeline$6::class$ = nullptr;

		} // stream
	} // util
} // java