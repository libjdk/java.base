#include <java/util/stream/IntPipeline$5.h>

#include <java/util/function/IntToLongFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$5$1.h>
#include <java/util/stream/IntPipeline.h>
#include <java/util/stream/LongPipeline$StatelessOp.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $IntToLongFunction = ::java::util::function::IntToLongFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$5$1 = ::java::util::stream::IntPipeline$5$1;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$5_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$5, this$0)},
	{"val$mapper", "Ljava/util/function/IntToLongFunction;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$5, val$mapper)},
	{}
};

$MethodInfo _IntPipeline$5_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntToLongFunction;)V", nullptr, 0, $method(IntPipeline$5, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntToLongFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$5, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$5_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"mapToLong",
	"(Ljava/util/function/IntToLongFunction;)Ljava/util/stream/LongStream;"
};

$InnerClassInfo _IntPipeline$5_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$5", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$5$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$5_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$5",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_IntPipeline$5_FieldInfo_,
	_IntPipeline$5_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$5_EnclosingMethodInfo_,
	_IntPipeline$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$5($Class* clazz) {
	return $of($alloc(IntPipeline$5));
}

void IntPipeline$5::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntToLongFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$5::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$5$1, this, sink);
}

IntPipeline$5::IntPipeline$5() {
}

$Class* IntPipeline$5::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$5, name, initialize, &_IntPipeline$5_ClassInfo_, allocate$IntPipeline$5);
	return class$;
}

$Class* IntPipeline$5::class$ = nullptr;

		} // stream
	} // util
} // java