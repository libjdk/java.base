#include <java/util/stream/IntPipeline$10.h>

#include <java/util/function/IntPredicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/IntPipeline$10$1.h>
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
using $IntPredicate = ::java::util::function::IntPredicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $IntPipeline = ::java::util::stream::IntPipeline;
using $IntPipeline$10$1 = ::java::util::stream::IntPipeline$10$1;
using $IntPipeline$StatelessOp = ::java::util::stream::IntPipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _IntPipeline$10_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/IntPipeline;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$10, this$0)},
	{"val$predicate", "Ljava/util/function/IntPredicate;", nullptr, $FINAL | $SYNTHETIC, $field(IntPipeline$10, val$predicate)},
	{}
};

$MethodInfo _IntPipeline$10_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/IntPipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/IntPredicate;)V", nullptr, 0, $method(IntPipeline$10, init$, void, $IntPipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $IntPredicate*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Integer;>;)Ljava/util/stream/Sink<Ljava/lang/Integer;>;", 0, $virtualMethod(IntPipeline$10, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _IntPipeline$10_EnclosingMethodInfo_ = {
	"java.util.stream.IntPipeline",
	"filter",
	"(Ljava/util/function/IntPredicate;)Ljava/util/stream/IntStream;"
};

$InnerClassInfo _IntPipeline$10_InnerClassesInfo_[] = {
	{"java.util.stream.IntPipeline$10", nullptr, nullptr, 0},
	{"java.util.stream.IntPipeline$StatelessOp", "java.util.stream.IntPipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.IntPipeline$10$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _IntPipeline$10_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.IntPipeline$10",
	"java.util.stream.IntPipeline$StatelessOp",
	nullptr,
	_IntPipeline$10_FieldInfo_,
	_IntPipeline$10_MethodInfo_,
	"Ljava/util/stream/IntPipeline$StatelessOp<Ljava/lang/Integer;>;",
	&_IntPipeline$10_EnclosingMethodInfo_,
	_IntPipeline$10_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.IntPipeline"
};

$Object* allocate$IntPipeline$10($Class* clazz) {
	return $of($alloc(IntPipeline$10));
}

void IntPipeline$10::init$($IntPipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $IntPredicate* val$predicate) {
	$set(this, this$0, this$0);
	$set(this, val$predicate, val$predicate);
	$IntPipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* IntPipeline$10::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($IntPipeline$10$1, this, sink);
}

IntPipeline$10::IntPipeline$10() {
}

$Class* IntPipeline$10::load$($String* name, bool initialize) {
	$loadClass(IntPipeline$10, name, initialize, &_IntPipeline$10_ClassInfo_, allocate$IntPipeline$10);
	return class$;
}

$Class* IntPipeline$10::class$ = nullptr;

		} // stream
	} // util
} // java