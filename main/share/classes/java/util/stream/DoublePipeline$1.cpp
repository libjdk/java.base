#include <java/util/stream/DoublePipeline$1.h>

#include <java/util/function/DoubleFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$1$1.h>
#include <java/util/stream/DoublePipeline.h>
#include <java/util/stream/ReferencePipeline$StatelessOp.h>
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
using $DoublePipeline$1$1 = ::java::util::stream::DoublePipeline$1$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$1_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$1, this$0)},
	{"val$mapper", "Ljava/util/function/DoubleFunction;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$1, val$mapper)},
	{}
};

$MethodInfo _DoublePipeline$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoubleFunction;)V", nullptr, 0, $method(DoublePipeline$1, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoubleFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TU;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$1, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$1_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"mapToObj",
	"(Ljava/util/function/DoubleFunction;I)Ljava/util/stream/Stream;"
};

$InnerClassInfo _DoublePipeline$1_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$1", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$1$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$1",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_DoublePipeline$1_FieldInfo_,
	_DoublePipeline$1_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<Ljava/lang/Double;TU;>;",
	&_DoublePipeline$1_EnclosingMethodInfo_,
	_DoublePipeline$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$1($Class* clazz) {
	return $of($alloc(DoublePipeline$1));
}

void DoublePipeline$1::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoubleFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$1::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$1$1, this, sink);
}

DoublePipeline$1::DoublePipeline$1() {
}

$Class* DoublePipeline$1::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$1, name, initialize, &_DoublePipeline$1_ClassInfo_, allocate$DoublePipeline$1);
	return class$;
}

$Class* DoublePipeline$1::class$ = nullptr;

		} // stream
	} // util
} // java