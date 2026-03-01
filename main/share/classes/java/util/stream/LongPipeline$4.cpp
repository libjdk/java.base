#include <java/util/stream/LongPipeline$4.h>

#include <java/util/function/LongToIntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$StatelessOp.h>
#include <java/util/stream/LongPipeline$4$1.h>
#include <java/util/stream/LongPipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LongToIntFunction = ::java::util::function::LongToIntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $LongPipeline = ::java::util::stream::LongPipeline;
using $LongPipeline$4$1 = ::java::util::stream::LongPipeline$4$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _LongPipeline$4_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/LongPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$4, this$0)},
	{"val$mapper", "Ljava/util/function/LongToIntFunction;", nullptr, $FINAL | $SYNTHETIC, $field(LongPipeline$4, val$mapper)},
	{}
};

$MethodInfo _LongPipeline$4_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/LongPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/LongToIntFunction;)V", nullptr, 0, $method(LongPipeline$4, init$, void, $LongPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $LongToIntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Long;>;", 0, $virtualMethod(LongPipeline$4, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _LongPipeline$4_EnclosingMethodInfo_ = {
	"java.util.stream.LongPipeline",
	"mapToInt",
	"(Ljava/util/function/LongToIntFunction;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _LongPipeline$4_InnerClassesInfo_[] = {
	{"java.util.stream.LongPipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.LongPipeline$4$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LongPipeline$4_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.LongPipeline$4",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_LongPipeline$4_FieldInfo_,
	_LongPipeline$4_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<Ljava/lang/Long;>;",
	&_LongPipeline$4_EnclosingMethodInfo_,
	_LongPipeline$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.LongPipeline"
};

$Object* allocate$LongPipeline$4($Class* clazz) {
	return $of($alloc(LongPipeline$4));
}

void LongPipeline$4::init$($LongPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $LongToIntFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* LongPipeline$4::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($LongPipeline$4$1, this, sink);
}

LongPipeline$4::LongPipeline$4() {
}

$Class* LongPipeline$4::load$($String* name, bool initialize) {
	$loadClass(LongPipeline$4, name, initialize, &_LongPipeline$4_ClassInfo_, allocate$LongPipeline$4);
	return class$;
}

$Class* LongPipeline$4::class$ = nullptr;

		} // stream
	} // util
} // java