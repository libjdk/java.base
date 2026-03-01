#include <java/util/stream/IntPipeline$4.h>

#include <java/util/function/IntUnaryOperator.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$4$1.h>
#include <java/util/stream/IntPipeline$StatelessOp.h>
#include <java/util/stream/IntPipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $IntUnaryOperator = ::java::util::function::IntUnaryOperator;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$4$1 = ::java::util::stream::IntPipeline$4$1;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$4_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$4, this$0)},
	{"val$mapper", "Ljava/util/function/IntUnaryOperator;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$4, val$mapper)},
	{}
};

$MethodInfo _IntPipeline$4_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntUnaryOperator;)V", nullptr, 0, $method(IntPipeline$4, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntUnaryOperator*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$4, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$4_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"map",
	"(Ljava/util/function/IntUnaryOperator;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _IntPipeline$4_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$4", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$4$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$4_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$4",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_IntPipeline$4_FieldInfo_,
	_IntPipeline$4_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$4_EnclosingMethodInfo_,
	_IntPipeline$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$4($Class* clazz) {
	return $of($alloc(IntPipeline$4));
}

void IntPipeline$4::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntUnaryOperator* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$4::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$4$1, this, sink);
}

IntPipeline$4::IntPipeline$4() {
}

$Class* IntPipeline$4::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$4, name, initialize, &_IntPipeline$4_ClassInfo_, allocate$IntPipeline$4);
	return class$;
}

$Class* IntPipeline$4::class$ = nullptr;

		} // stream
	} // util
} // java