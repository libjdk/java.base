#include <java/util/stream/ReferencePipeline$13.h>

#include <java/util/function/BiConsumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$13$1.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BiConsumer = ::java::util::function::BiConsumer;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$13$1 = ::java::util::stream::ReferencePipeline$13$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$13_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$13, this$0)},
	{"val$mapper", "Ljava/util/function/BiConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$13, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$13_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/BiConsumer;)V", nullptr, 0, $method(ReferencePipeline$13, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $BiConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$13, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$13_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"mapMultiToLong",
	"(Ljava/util/function/BiConsumer;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _ReferencePipeline$13_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$13", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$13$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$13_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$13",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$13_FieldInfo_,
	_ReferencePipeline$13_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$13_EnclosingMethodInfo_,
	_ReferencePipeline$13_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$13($Class* clazz) {
	return $of($alloc(ReferencePipeline$13));
}

void ReferencePipeline$13::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $BiConsumer* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$13::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$13$1, this, sink);
}

ReferencePipeline$13::ReferencePipeline$13() {
}

$Class* ReferencePipeline$13::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$13, name, initialize, &_ReferencePipeline$13_ClassInfo_, allocate$ReferencePipeline$13);
	return class$;
}

$Class* ReferencePipeline$13::class$ = nullptr;

		} // stream
	} // util
} // java