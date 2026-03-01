#include <java/util/stream/LongPipeline$2.h>

#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/LongPipeline$2$1.h>
#include <java/util/stream/LongPipeline.h>
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
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$2$1 = ::java::util::stream::LongPipeline$2$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$2_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$2, this$0)},
	{}
};

$MethodInfo _LongPipeline$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;I)V", nullptr, 0, $method(LongPipeline$2, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$2, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$2_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"asDoubleStream",
	"()Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _LongPipeline$2_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$2",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_LongPipeline$2_FieldInfo_,
	_LongPipeline$2_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Long;>;",
	&_LongPipeline$2_EnclosingMethodInfo_,
	_LongPipeline$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$2($Class* clazz) {
	return $of($alloc(LongPipeline$2));
}

void LongPipeline$2::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags) {
	$set(this, this$0, this$0);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$2::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$2$1, this, sink);
}

LongPipeline$2::LongPipeline$2() {
}

$Class* LongPipeline$2::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$2, name, initialize, &_LongPipeline$2_ClassInfo_, allocate$LongPipeline$2);
	return class$;
}

$Class* LongPipeline$2::class$ = nullptr;

		} // stream
	} // util
} // java