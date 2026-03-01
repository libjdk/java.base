#include <java/util/stream/LongPipeline$5.h>

#include <java/util/function/LongToDoubleFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/LongPipeline$5$1.h>
#include <java/util/stream/LongPipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LongToDoubleFunction = ::java::util::function::LongToDoubleFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$5$1 = ::java::util::stream::LongPipeline$5$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$5_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$5, this$0)},
	{"val$mapper", "Ljava/util/function/LongToDoubleFunction;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$5, val$mapper)},
	{}
};

$MethodInfo _LongPipeline$5_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongToDoubleFunction;)V", nullptr, 0, $method(LongPipeline$5, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $LongToDoubleFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$5, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$5_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"mapToDouble",
	"(Ljava/util/function/LongToDoubleFunction;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _LongPipeline$5_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$5$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline$5_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$5",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_LongPipeline$5_FieldInfo_,
	_LongPipeline$5_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Long;>;",
	&_LongPipeline$5_EnclosingMethodInfo_,
	_LongPipeline$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$5($Class* clazz) {
	return $of($alloc(LongPipeline$5));
}

void LongPipeline$5::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongToDoubleFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$5::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$5$1, this, sink);
}

LongPipeline$5::LongPipeline$5() {
}

$Class* LongPipeline$5::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$5, name, initialize, &_LongPipeline$5_ClassInfo_, allocate$LongPipeline$5);
	return class$;
}

$Class* LongPipeline$5::class$ = nullptr;

		} // stream
	} // util
} // java