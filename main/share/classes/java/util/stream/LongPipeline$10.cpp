#include <java/util/stream/LongPipeline$10.h>

#include <java/util/function/LongConsumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/LongPipeline$10$1.h>
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
using $LongConsumer = ::java::util::function::LongConsumer;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$10$1 = ::java::util::stream::LongPipeline$10$1;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$10_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$10, this$0)},
	{"val$action", "Ljava/util/function/LongConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$10, val$action)},
	{}
};

$MethodInfo _LongPipeline$10_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongConsumer;)V", nullptr, 0, $method(LongPipeline$10, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $LongConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$10, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$10_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"peek",
	"(Ljava/util/function/LongConsumer;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _LongPipeline$10_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$10", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$10$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline$10_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$10",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_LongPipeline$10_FieldInfo_,
	_LongPipeline$10_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<Ljava/lang/Long;>;",
	&_LongPipeline$10_EnclosingMethodInfo_,
	_LongPipeline$10_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$10($Class* clazz) {
	return $of($alloc(LongPipeline$10));
}

void LongPipeline$10::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongConsumer* val$action) {
	$set(this, this$0, this$0);
	$set(this, val$action, val$action);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$10::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$10$1, this, sink);
}

LongPipeline$10::LongPipeline$10() {
}

$Class* LongPipeline$10::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$10, name, initialize, &_LongPipeline$10_ClassInfo_, allocate$LongPipeline$10);
	return class$;
}

$Class* LongPipeline$10::class$ = nullptr;

		} // stream
	} // util
} // java