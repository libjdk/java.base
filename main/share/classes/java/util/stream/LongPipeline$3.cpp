#include <java/util/stream/LongPipeline$3.h>

#include <java/util/function/LongUnaryOperator.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$3$1.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/LongPipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LongUnaryOperator = ::java::util::function::LongUnaryOperator;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$3$1 = ::java::util::stream::LongPipeline$3$1;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$3_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$3, this$0)},
	{"val$mapper", "Ljava/util/function/LongUnaryOperator;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$3, val$mapper)},
	{}
};

$MethodInfo _LongPipeline$3_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongUnaryOperator;)V", nullptr, 0, $method(LongPipeline$3, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $LongUnaryOperator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$3, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$3_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"map",
	"(Ljava/util/function/LongUnaryOperator;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _LongPipeline$3_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$3", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$3$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$3",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_LongPipeline$3_FieldInfo_,
	_LongPipeline$3_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<Ljava/lang/Long;>;",
	&_LongPipeline$3_EnclosingMethodInfo_,
	_LongPipeline$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$3($Class* clazz) {
	return $of($alloc(LongPipeline$3));
}

void LongPipeline$3::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongUnaryOperator* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$3::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$3$1, this, sink);
}

LongPipeline$3::LongPipeline$3() {
}

$Class* LongPipeline$3::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$3, name, initialize, &_LongPipeline$3_ClassInfo_, allocate$LongPipeline$3);
	return class$;
}

$Class* LongPipeline$3::class$ = nullptr;

		} // stream
	} // util
} // java