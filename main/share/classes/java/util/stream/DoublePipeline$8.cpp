#include <java/util/stream/DoublePipeline$8.h>

#include <java/util/function/DoublePredicate.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoublePipeline$8$1.h>
#include <java/util/stream/DoublePipeline$StatelessOp.h>
#include <java/util/stream/DoublePipeline.h>
#include <java/util/stream/Sink.h>
#include <java/util/stream/StreamShape.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoublePipeline = ::java::util::stream::DoublePipeline;
using $DoublePipeline$8$1 = ::java::util::stream::DoublePipeline$8$1;
using $DoublePipeline$StatelessOp = ::java::util::stream::DoublePipeline$StatelessOp;
using $Sink = ::java::util::stream::Sink;
using $StreamShape = ::java::util::stream::StreamShape;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _DoublePipeline$8_FieldInfo_[] = {
	{"this$0", "Ljava/util/stream/DoublePipeline;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$8, this$0)},
	{"val$predicate", "Ljava/util/function/DoublePredicate;", nullptr, $FINAL | $SYNTHETIC, $field(DoublePipeline$8, val$predicate)},
	{}
};

$MethodInfo _DoublePipeline$8_MethodInfo_[] = {
	{"<init>", "(Ljava/util/stream/DoublePipeline;Ljava/util/stream/AbstractPipeline;Ljava/util/stream/StreamShape;ILjava/util/function/DoublePredicate;)V", nullptr, 0, $method(DoublePipeline$8, init$, void, $DoublePipeline*, $AbstractPipeline*, $StreamShape*, int32_t, $DoublePredicate*)},
	{"opWrapSink", "(ILjava/util/stream/Sink;)Ljava/util/stream/Sink;", "(ILjava/util/stream/Sink<Ljava/lang/Double;>;)Ljava/util/stream/Sink<Ljava/lang/Double;>;", 0, $virtualMethod(DoublePipeline$8, opWrapSink, $Sink*, int32_t, $Sink*)},
	{}
};

$EnclosingMethodInfo _DoublePipeline$8_EnclosingMethodInfo_ = {
	"java.util.stream.DoublePipeline",
	"filter",
	"(Ljava/util/function/DoublePredicate;)Ljava/util/stream/DoubleStream;"
};

$InnerClassInfo _DoublePipeline$8_InnerClassesInfo_[] = {
	{"java.util.stream.DoublePipeline$8", nullptr, nullptr, 0},
	{"java.util.stream.DoublePipeline$StatelessOp", "java.util.stream.DoublePipeline", "StatelessOp", $STATIC | $ABSTRACT},
	{"java.util.stream.DoublePipeline$8$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DoublePipeline$8_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.DoublePipeline$8",
	"java.util.stream.DoublePipeline$StatelessOp",
	nullptr,
	_DoublePipeline$8_FieldInfo_,
	_DoublePipeline$8_MethodInfo_,
	"Ljava/util/stream/DoublePipeline$StatelessOp<Ljava/lang/Double;>;",
	&_DoublePipeline$8_EnclosingMethodInfo_,
	_DoublePipeline$8_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.DoublePipeline"
};

$Object* allocate$DoublePipeline$8($Class* clazz) {
	return $of($alloc(DoublePipeline$8));
}

void DoublePipeline$8::init$($DoublePipeline* this$0, $AbstractPipeline* upstream, $StreamShape* inputShape, int32_t opFlags, $DoublePredicate* val$predicate) {
	$set(this, this$0, this$0);
	$set(this, val$predicate, val$predicate);
	$DoublePipeline$StatelessOp::init$(upstream, inputShape, opFlags);
}

$Sink* DoublePipeline$8::opWrapSink(int32_t flags, $Sink* sink) {
	return $new($DoublePipeline$8$1, this, sink);
}

DoublePipeline$8::DoublePipeline$8() {
}

$Class* DoublePipeline$8::load$($String* name, bool initialize) {
	$loadClass(DoublePipeline$8, name, initialize, &_DoublePipeline$8_ClassInfo_, allocate$DoublePipeline$8);
	return class$;
}

$Class* DoublePipeline$8::class$ = nullptr;

		} // stream
	} // util
} // java