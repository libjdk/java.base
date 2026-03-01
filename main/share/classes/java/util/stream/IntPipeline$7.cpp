#include <java/util/stream/IntPipeline$7.h>

#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$7$1.h>
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
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$7$1 = ::java::util::stream::IntPipeline$7$1;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$7_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$7, this$0)},
	{"val$mapper", "Ljava/util/function/IntFunction;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$7, val$mapper)},
	{}
};

$MethodInfo _IntPipeline$7_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntFunction;)V", nullptr, 0, $method(IntPipeline$7, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$7, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$7_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"flatMap",
	"(Ljava/util/function/IntFunction;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _IntPipeline$7_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$7", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$7$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$7_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$7",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_IntPipeline$7_FieldInfo_,
	_IntPipeline$7_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$7_EnclosingMethodInfo_,
	_IntPipeline$7_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$7($Class* clazz) {
	return $of($alloc(IntPipeline$7));
}

void IntPipeline$7::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$7::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$7$1, this, sink);
}

IntPipeline$7::IntPipeline$7() {
}

$Class* IntPipeline$7::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$7, name, initialize, &_IntPipeline$7_ClassInfo_, allocate$IntPipeline$7);
	return class$;
}

$Class* IntPipeline$7::class$ = nullptr;

		} // stream
	} // util
} // java