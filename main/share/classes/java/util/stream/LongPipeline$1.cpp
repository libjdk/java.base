#include <java/util/stream/LongPipeline$1.h>

#include <java/util/function/LongFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$1$1.h>
#include <java/util/stream/LongPipeline.h>
#include <java/util/stream/ReferencePipeline$StatelessOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LongFunction = ::java::util::function::LongFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$1$1 = ::java::util::stream::LongPipeline$1$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$1_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$1, this$0)},
	{"val$mapper", "Ljava/util/function/LongFunction;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$1, val$mapper)},
	{}
};

$MethodInfo _LongPipeline$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongFunction;)V", nullptr, 0, $method(LongPipeline$1, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $LongFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TU;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$1, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$1_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"mapToObj",
	"(Ljava/util/function/LongFunction;I)Ljava/util/stream/Stream;"
};

$InnerClassInfo _LongPipeline$1_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$1", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$1$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$1",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_LongPipeline$1_FieldInfo_,
	_LongPipeline$1_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<Ljava/lang/Long;TU;>;",
	&_LongPipeline$1_EnclosingMethodInfo_,
	_LongPipeline$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$1($Class* clazz) {
	return $of($alloc(LongPipeline$1));
}

void LongPipeline$1::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$1::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$1$1, this, sink);
}

LongPipeline$1::LongPipeline$1() {
}

$Class* LongPipeline$1::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$1, name, initialize, &_LongPipeline$1_ClassInfo_, allocate$LongPipeline$1);
	return class$;
}

$Class* LongPipeline$1::class$ = nullptr;

		} // stream
	} // util
} // java