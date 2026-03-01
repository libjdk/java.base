#include <java/util/stream/IntPipeline$3.h>

#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/IntPipeline$3$1.h>
#include <java/util/stream/IntPipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$3$1 = ::java::util::stream::IntPipeline$3$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$3_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$3, this$0)},
	{}
};

$MethodInfo _IntPipeline$3_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;I)V", nullptr, 0, $method(IntPipeline$3, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$3, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$3_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"asDoubleStream",
	"()Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _IntPipeline$3_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$3$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$3",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_IntPipeline$3_FieldInfo_,
	_IntPipeline$3_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$3_EnclosingMethodInfo_,
	_IntPipeline$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$3($Class* clazz) {
	return $of($alloc(IntPipeline$3));
}

void IntPipeline$3::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags) {
	$set(this, this$0, this$0);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$3::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$3$1, this, sink);
}

IntPipeline$3::IntPipeline$3() {
}

$Class* IntPipeline$3::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$3, name, initialize, &_IntPipeline$3_ClassInfo_, allocate$IntPipeline$3);
	return class$;
}

$Class* IntPipeline$3::class$ = nullptr;

		} // stream
	} // util
} // java