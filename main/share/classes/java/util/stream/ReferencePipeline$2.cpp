#include <java/util/stream/ReferencePipeline$2.h>

#include <java/util/function/Predicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/ReferencePipeline$2$1.h>
#include <java/util/stream/ReferencePipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Predicate = ::java::util::function::Predicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$2$1 = ::java::util::stream::ReferencePipeline$2$1;
using $ReferencePipeline$StatelessOp = ::java::util::stream::ReferencePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$2_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$2, this$0)},
	{"val$predicate", "Ljava/util/function/Predicate;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$2, val$predicate)},
	{}
};

$MethodInfo _ReferencePipeline$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/Predicate;)V", nullptr, 0, $method(ReferencePipeline$2, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $Predicate*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<TP_OUT;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$2, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$2_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"filter",
	"(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;"
};

$InnerClassInfo _ReferencePipeline$2_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$2", nullptr, nullptr, 0},
	{"java.util.stream.ReferencePipeline$StatelessOp", "java.util.stream.ReferencePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$2",
	"java.util.stream.ReferencePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$2_FieldInfo_,
	_ReferencePipeline$2_MethodInfo_,
	"Ljava/util/stream/ReferencePipeline$StatelessOp<TP_OUT;TP_OUT;>;",
	&_ReferencePipeline$2_EnclosingMethodInfo_,
	_ReferencePipeline$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$2($Class* clazz) {
	return $of($alloc(ReferencePipeline$2));
}

void ReferencePipeline$2::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $Predicate* val$predicate) {
	$set(this, this$0, this$0);
	$set(this, val$predicate, val$predicate);
	$ReferencePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$2::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$2$1, this, sink);
}

ReferencePipeline$2::ReferencePipeline$2() {
}

$Class* ReferencePipeline$2::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$2, name, initialize, &_ReferencePipeline$2_ClassInfo_, allocate$ReferencePipeline$2);
	return class$;
}

$Class* ReferencePipeline$2::class$ = nullptr;

		} // stream
	} // util
} // java