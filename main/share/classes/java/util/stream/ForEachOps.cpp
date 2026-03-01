#include <java/util/stream/ForEachOps.h>

#include <java/util/Objects.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/stream/ForEachOps$ForEachOp$OfDouble.h>
#include <java/util/stream/ForEachOps$ForEachOp$OfInt.h>
#include <java/util/stream/ForEachOps$ForEachOp$OfLong.h>
#include <java/util/stream/ForEachOps$ForEachOp$OfRef.h>
#include <java/util/stream/TerminalOp.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $ForEachOps$ForEachOp$OfDouble = ::java::util::stream::ForEachOps$ForEachOp$OfDouble;
using $ForEachOps$ForEachOp$OfInt = ::java::util::stream::ForEachOps$ForEachOp$OfInt;
using $ForEachOps$ForEachOp$OfLong = ::java::util::stream::ForEachOps$ForEachOp$OfLong;
using $ForEachOps$ForEachOp$OfRef = ::java::util::stream::ForEachOps$ForEachOp$OfRef;
using $TerminalOp = ::java::util::stream::TerminalOp;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _ForEachOps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ForEachOps, init$, void)},
	{"makeDouble", "(Ljava/util/function/DoubleConsumer;Z)Ljava/util/stream/TerminalOp;", "(Ljava/util/function/DoubleConsumer;Z)Ljava/util/stream/TerminalOp<Ljava/lang/Double;Ljava/lang/Void;>;", $PUBLIC | $STATIC, $staticMethod(ForEachOps, makeDouble, $TerminalOp*, $DoubleConsumer*, bool)},
	{"makeInt", "(Ljava/util/function/IntConsumer;Z)Ljava/util/stream/TerminalOp;", "(Ljava/util/function/IntConsumer;Z)Ljava/util/stream/TerminalOp<Ljava/lang/Integer;Ljava/lang/Void;>;", $PUBLIC | $STATIC, $staticMethod(ForEachOps, makeInt, $TerminalOp*, $IntConsumer*, bool)},
	{"makeLong", "(Ljava/util/function/LongConsumer;Z)Ljava/util/stream/TerminalOp;", "(Ljava/util/function/LongConsumer;Z)Ljava/util/stream/TerminalOp<Ljava/lang/Long;Ljava/lang/Void;>;", $PUBLIC | $STATIC, $staticMethod(ForEachOps, makeLong, $TerminalOp*, $LongConsumer*, bool)},
	{"makeRef", "(Ljava/util/function/Consumer;Z)Ljava/util/stream/TerminalOp;", "<T:Ljava/lang/Object;>(Ljava/util/function/Consumer<-TT;>;Z)Ljava/util/stream/TerminalOp<TT;Ljava/lang/Void;>;", $PUBLIC | $STATIC, $staticMethod(ForEachOps, makeRef, $TerminalOp*, $Consumer*, bool)},
	{}
};

$InnerClassInfo _ForEachOps_InnerClassesInfo_[] = {
	{"java.util.stream.ForEachOps$ForEachOrderedTask", "java.util.stream.ForEachOps", "ForEachOrderedTask", $STATIC | $FINAL},
	{"java.util.stream.ForEachOps$ForEachTask", "java.util.stream.ForEachOps", "ForEachTask", $STATIC | $FINAL},
	{"java.util.stream.ForEachOps$ForEachOp", "java.util.stream.ForEachOps", "ForEachOp", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _ForEachOps_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.ForEachOps",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ForEachOps_MethodInfo_,
	nullptr,
	nullptr,
	_ForEachOps_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.ForEachOps$ForEachOrderedTask,java.util.stream.ForEachOps$ForEachTask,java.util.stream.ForEachOps$ForEachOp,java.util.stream.ForEachOps$ForEachOp$OfDouble,java.util.stream.ForEachOps$ForEachOp$OfLong,java.util.stream.ForEachOps$ForEachOp$OfInt,java.util.stream.ForEachOps$ForEachOp$OfRef"
};

$Object* allocate$ForEachOps($Class* clazz) {
	return $of($alloc(ForEachOps));
}

void ForEachOps::init$() {
}

$TerminalOp* ForEachOps::makeRef($Consumer* action, bool ordered) {
	$Objects::requireNonNull(action);
	return $new($ForEachOps$ForEachOp$OfRef, action, ordered);
}

$TerminalOp* ForEachOps::makeInt($IntConsumer* action, bool ordered) {
	$Objects::requireNonNull(action);
	return $new($ForEachOps$ForEachOp$OfInt, action, ordered);
}

$TerminalOp* ForEachOps::makeLong($LongConsumer* action, bool ordered) {
	$Objects::requireNonNull(action);
	return $new($ForEachOps$ForEachOp$OfLong, action, ordered);
}

$TerminalOp* ForEachOps::makeDouble($DoubleConsumer* action, bool ordered) {
	$Objects::requireNonNull(action);
	return $new($ForEachOps$ForEachOp$OfDouble, action, ordered);
}

ForEachOps::ForEachOps() {
}

$Class* ForEachOps::load$($String* name, bool initialize) {
	$loadClass(ForEachOps, name, initialize, &_ForEachOps_ClassInfo_, allocate$ForEachOps);
	return class$;
}

$Class* ForEachOps::class$ = nullptr;

		} // stream
	} // util
} // java