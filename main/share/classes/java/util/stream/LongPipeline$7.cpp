#include <java/util/stream/LongPipeline$7.h>

#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$7$1.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/LongPipeline.h>
#include <java/util/stream/LongStream$LongMapMultiConsumer.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$7$1 = ::java::util::stream::LongPipeline$7$1;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $LongStream$LongMapMultiConsumer = ::java::util::stream::LongStream$LongMapMultiConsumer;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$7_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$7, this$0)},
	{"val$mapper", "Ljava/util/stream/LongStream$LongMapMultiConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$7, val$mapper)},
	{}
};

$MethodInfo _LongPipeline$7_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/stream/LongStream$LongMapMultiConsumer;)V", nullptr, 0, $method(LongPipeline$7, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $LongStream$LongMapMultiConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$7, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$7_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"mapMulti",
	"(Ljava/util/stream/LongStream$LongMapMultiConsumer;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _LongPipeline$7_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$7", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$7$1", nullptr, nullptr, 0},
	{"java.util.stream.LongStream$LongMapMultiConsumer", "java.util.stream.LongStream", "LongMapMultiConsumer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LongPipeline$7_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$7",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_LongPipeline$7_FieldInfo_,
	_LongPipeline$7_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<Ljava/lang/Long;>;",
	&_LongPipeline$7_EnclosingMethodInfo_,
	_LongPipeline$7_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$7($Class* clazz) {
	return $of($alloc(LongPipeline$7));
}

void LongPipeline$7::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongStream$LongMapMultiConsumer* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$7::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$7$1, this, sink);
}

LongPipeline$7::LongPipeline$7() {
}

$Class* LongPipeline$7::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$7, name, initialize, &_LongPipeline$7_ClassInfo_, allocate$LongPipeline$7);
	return class$;
}

$Class* LongPipeline$7::class$ = nullptr;

		} // stream
	} // util
} // java