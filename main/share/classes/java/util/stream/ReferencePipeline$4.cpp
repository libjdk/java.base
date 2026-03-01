#include <java/util/stream/ReferencePipeline$4.h>

#include <java/util/function/ToIntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$4$1.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ToIntFunction = ::java::util::function::ToIntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$4$1 = ::java::util::stream::ReferencePipeline$4$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$4_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$4, this$0)},
	{"val$mapper", "Ljava/util/function/ToIntFunction;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$4, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$4_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/ToIntFunction;)V", nullptr, 0, $method(ReferencePipeline$4, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $ToIntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$4, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$4_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapToInt",
	"(Ljava/util/function/ToIntFunction;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _ReferencePipeline$4_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$4$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$4_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$4",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$4_FieldInfo_,
	_ReferencePipeline$4_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$4_EnclosingMethodInfo_,
	_ReferencePipeline$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$4($Class* clazz) {
	return $of($alloc(ReferencePipeline$4));
}

void ReferencePipeline$4::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $ToIntFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$4::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$4$1, this, sink);
}

ReferencePipeline$4::ReferencePipeline$4() {
}

$Class* ReferencePipeline$4::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$4, name, initialize, &_ReferencePipeline$4_ClassInfo_, allocate$ReferencePipeline$4);
	return class$;
}

$Class* ReferencePipeline$4::class$ = nullptr;

		} // stream
	} // util
} // java