#include <java/util/stream/DoublePipeline$4.h>

#include <java/util/function/DoubleToLongFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$4$1.h>
#include <java/util/stream/DoublePipeline.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DoubleToLongFunction = ::java::util::function::DoubleToLongFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline = ::java::util::stream::DoublePipeline;
using $DoublePipeline$4$1 = ::java::util::stream::DoublePipeline$4$1;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$4_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$4, this$0)},
	{"val$mapper", "Ljava/util/function/DoubleToLongFunction;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$4, val$mapper)},
	{}
};

$MethodInfo _DoublePipeline$4_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoubleToLongFunction;)V", nullptr, 0, $method(DoublePipeline$4, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoubleToLongFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$4, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$4_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"mapToLong",
	"(Ljava/util/function/DoubleToLongFunction;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _DoublePipeline$4_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$4$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline$4_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$4",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_DoublePipeline$4_FieldInfo_,
	_DoublePipeline$4_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<Ljava/lang/Double;>;",
	&_DoublePipeline$4_EnclosingMethodInfo_,
	_DoublePipeline$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$4($Class* clazz) {
	return $of($alloc(DoublePipeline$4));
}

void DoublePipeline$4::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoubleToLongFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$4::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$4$1, this, sink);
}

DoublePipeline$4::DoublePipeline$4() {
}

$Class* DoublePipeline$4::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$4, name, initialize, &_DoublePipeline$4_ClassInfo_, allocate$DoublePipeline$4);
	return class$;
}

$Class* DoublePipeline$4::class$ = nullptr;

		} // stream
	} // util
} // java