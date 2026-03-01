#include <java/util/stream/IntPipeline$11.h>

#include <java/util/function/IntConsumer.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$11$1.h>
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
using $IntConsumer = ::java::util::function::IntConsumer;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$11$1 = ::java::util::stream::IntPipeline$11$1;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$11_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$11, this$0)},
	{"val$action", "Ljava/util/function/IntConsumer;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$11, val$action)},
	{}
};

$MethodInfo _IntPipeline$11_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntConsumer;)V", nullptr, 0, $method(IntPipeline$11, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntConsumer*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$11, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$11_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"peek",
	"(Ljava/util/function/IntConsumer;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _IntPipeline$11_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$11", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$11$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$11_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$11",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_IntPipeline$11_FieldInfo_,
	_IntPipeline$11_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$11_EnclosingMethodInfo_,
	_IntPipeline$11_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$11($Class* clazz) {
	return $of($alloc(IntPipeline$11));
}

void IntPipeline$11::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntConsumer* val$action) {
	$set(this, this$0, this$0);
	$set(this, val$action, val$action);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$11::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$11$1, this, sink);
}

IntPipeline$11::IntPipeline$11() {
}

$Class* IntPipeline$11::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$11, name, initialize, &_IntPipeline$11_ClassInfo_, allocate$IntPipeline$11);
	return class$;
}

$Class* IntPipeline$11::class$ = nullptr;

		} // stream
	} // util
} // java