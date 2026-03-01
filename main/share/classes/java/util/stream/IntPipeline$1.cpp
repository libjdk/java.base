#include <java/util/stream/IntPipeline$1.h>

#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$1$1.h>
#include <java/util/stream/IntPipeline.h>
#include <java/util/stream/ReferencePipeline$StatelessOp.h>
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
using $IntPipeline$1$1 = ::java::util::stream::IntPipeline$1$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$1_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$1, this$0)},
	{"val$mapper", "Ljava/util/function/IntFunction;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$1, val$mapper)},
	{}
};

$MethodInfo _IntPipeline$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntFunction;)V", nullptr, 0, $method(IntPipeline$1, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntFunction*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TU;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$1, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$1_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"mapToObj",
	"(Ljava/util/function/IntFunction;I)Ljava/util/stream/Stream;"
};

$InnerClassInfo _IntPipeline$1_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$1", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$1$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$1",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_IntPipeline$1_FieldInfo_,
	_IntPipeline$1_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<Ljava/lang/Integer;TU;>;",
	&_IntPipeline$1_EnclosingMethodInfo_,
	_IntPipeline$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$1($Class* clazz) {
	return $of($alloc(IntPipeline$1));
}

void IntPipeline$1::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntFunction* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$1::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$1$1, this, sink);
}

IntPipeline$1::IntPipeline$1() {
}

$Class* IntPipeline$1::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$1, name, initialize, &_IntPipeline$1_ClassInfo_, allocate$IntPipeline$1);
	return class$;
}

$Class* IntPipeline$1::class$ = nullptr;

		} // stream
	} // util
} // java