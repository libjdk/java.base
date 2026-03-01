#include <java/util/stream/ReferencePipeline$5.h>

#include <java/util/function/ToLongFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$5$1.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ToLongFunction = ::java::util::function::ToLongFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$5$1 = ::java::util::stream::ReferencePipeline$5$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$5_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$5, this$0)},
	{"val$mapper", "Ljava/util/function/ToLongFunction;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$5, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$5_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/ToLongFunction;)V", nullptr, 0, $method(ReferencePipeline$5, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $ToLongFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$5, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$5_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapToLong",
	"(Ljava/util/function/ToLongFunction;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _ReferencePipeline$5_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$5$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$5_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$5",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$5_FieldInfo_,
	_ReferencePipeline$5_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$5_EnclosingMethodInfo_,
	_ReferencePipeline$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$5($Class* clazz) {
	return $of($alloc(ReferencePipeline$5));
}

void ReferencePipeline$5::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $ToLongFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$5::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$5$1, this, sink);
}

ReferencePipeline$5::ReferencePipeline$5() {
}

$Class* ReferencePipeline$5::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$5, name, initialize, &_ReferencePipeline$5_ClassInfo_, allocate$ReferencePipeline$5);
	return class$;
}

$Class* ReferencePipeline$5::class$ = nullptr;

		} // stream
	} // util
} // java