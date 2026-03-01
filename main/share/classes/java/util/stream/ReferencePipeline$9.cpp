#include <java/util/stream/ReferencePipeline$9.h>

#include <java/util/function/Function.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/ReferencePipeline$9$1.h>
#include <java/util/stream/ReferencePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Function = ::java::util::function::Function;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $ReferencePipeline = ::java::util::stream::ReferencePipeline;
using $ReferencePipeline$9$1 = ::java::util::stream::ReferencePipeline$9$1;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _ReferencePipeline$9_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/ReferencePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$9, this$0)},
	{"val$mapper", "Ljava/util/function/Function;", nullptr, $FINAL | $SYNTHETIC, $field(ReferencePipeline$9, val$mapper)},
	{}
};

$MethodInfo _ReferencePipeline$9_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/ReferencePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/Function;)V", nullptr, 0, $method(ReferencePipeline$9, init$, void, $ReferencePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $Function*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<TP_OUT;>;", 0, $virtualMethod(ReferencePipeline$9, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _ReferencePipeline$9_EnclosingMethodInfo_ = {
	"java.util.stream.ReferencePipeline",
	"flatMapToDouble",
	"(Ljava/util/function/Function;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _ReferencePipeline$9_InnerClassesInfo_[] = {
	{"java.util.stream.ReferencePipeline$9", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.ReferencePipeline$9$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReferencePipeline$9_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.ReferencePipeline$9",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_ReferencePipeline$9_FieldInfo_,
	_ReferencePipeline$9_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<TP_OUT;>;",
	&_ReferencePipeline$9_EnclosingMethodInfo_,
	_ReferencePipeline$9_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.ReferencePipeline"
};

$Object* allocate$ReferencePipeline$9($Class* clazz) {
	return $of($alloc(ReferencePipeline$9));
}

void ReferencePipeline$9::init$($ReferencePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $Function* val$mapper) {
	$set(this, this$0, this$0);
	$set(this, val$mapper, val$mapper);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* ReferencePipeline$9::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($ReferencePipeline$9$1, this, sink);
}

ReferencePipeline$9::ReferencePipeline$9() {
}

$Class* ReferencePipeline$9::load$($String* name, bool initialize) {
	$loadClass(ReferencePipeline$9, name, initialize, &_ReferencePipeline$9_ClassInfo_, allocate$ReferencePipeline$9);
	return class$;
}

$Class* ReferencePipeline$9::class$ = nullptr;

		} // stream
	} // util
} // java