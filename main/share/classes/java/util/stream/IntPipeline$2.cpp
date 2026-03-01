#include <java/util/stream/IntPipeline$2.h>

#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$2$1.h>
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
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$2$1 = ::java::util::stream::IntPipeline$2$1;
using $LongPipeline$StatelessOp = ::java::util::stream::LongPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$2_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$2, this$0)},
	{}
};

$MethodInfo _IntPipeline$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;I)V", nullptr, 0, $method(IntPipeline$2, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Long;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$2, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$2_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"asLongStream",
	"()Ljava/util/stream/LongStream;"
};

$InnerClassInfo _IntPipeline$2_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.LongPipeline$StatelessOp", "java.util.stream.LongPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$2",
	"java.util.stream.LongPipeline$StatelessOp",
	nullptr,
	_IntPipeline$2_FieldInfo_,
	_IntPipeline$2_MethodInfo_,
	"Ljava/util/stream/LongPipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$2_EnclosingMethodInfo_,
	_IntPipeline$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$2($Class* clazz) {
	return $of($alloc(IntPipeline$2));
}

void IntPipeline$2::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags) {
	$set(this, this$0, this$0);
	$LongPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$2::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$2$1, this, sink);
}

IntPipeline$2::IntPipeline$2() {
}

$Class* IntPipeline$2::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$2, name, initialize, &_IntPipeline$2_ClassInfo_, allocate$IntPipeline$2);
	return class$;
}

$Class* IntPipeline$2::class$ = nullptr;

		} // stream
	} // util
} // java