#include <java/util/stream/ReduceOps.h>

#include <java/util/Objects.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/DoubleBinaryOperator.h>
#include <java/util/function/IntBinaryOperator.h>
#include <java/util/function/LongBinaryOperator.h>
#include <java/util/function/ObjDoubleConsumer.h>
#include <java/util/function/ObjIntConsumer.h>
#include <java/util/function/ObjLongConsumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/ReduceOps$1.h>
#include <java/util/stream/ReduceOps$10.h>
#include <java/util/stream/ReduceOps$11.h>
#include <java/util/stream/ReduceOps$12.h>
#include <java/util/stream/ReduceOps$13.h>
#include <java/util/stream/ReduceOps$14.h>
#include <java/util/stream/ReduceOps$15.h>
#include <java/util/stream/ReduceOps$16.h>
#include <java/util/stream/ReduceOps$17.h>
#include <java/util/stream/ReduceOps$2.h>
#include <java/util/stream/ReduceOps$3.h>
#include <java/util/stream/ReduceOps$4.h>
#include <java/util/stream/ReduceOps$5.h>
#include <java/util/stream/ReduceOps$6.h>
#include <java/util/stream/ReduceOps$7.h>
#include <java/util/stream/ReduceOps$8.h>
#include <java/util/stream/ReduceOps$9.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/TerminalOp.h>
#include <jcpp.h>

#undef DOUBLE_VALUE
#undef INT_VALUE
#undef LONG_VALUE
#undef REFERENCE

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $DoubleBinaryOperator = ::java::util::function::DoubleBinaryOperator;
using $IntBinaryOperator = ::java::util::function::IntBinaryOperator;
using $LongBinaryOperator = ::java::util::function::LongBinaryOperator;
using $ObjDoubleConsumer = ::java::util::function::ObjDoubleConsumer;
using $ObjIntConsumer = ::java::util::function::ObjIntConsumer;
using $ObjLongConsumer = ::java::util::function::ObjLongConsumer;
using $Supplier = ::java::util::function::Supplier;
using $Collector = ::java::util::stream::Collector;
using $ReduceOps$1 = ::java::util::stream::ReduceOps$1;
using $ReduceOps$10 = ::java::util::stream::ReduceOps$10;
using $ReduceOps$11 = ::java::util::stream::ReduceOps$11;
using $ReduceOps$12 = ::java::util::stream::ReduceOps$12;
using $ReduceOps$13 = ::java::util::stream::ReduceOps$13;
using $ReduceOps$14 = ::java::util::stream::ReduceOps$14;
using $ReduceOps$15 = ::java::util::stream::ReduceOps$15;
using $ReduceOps$16 = ::java::util::stream::ReduceOps$16;
using $ReduceOps$17 = ::java::util::stream::ReduceOps$17;
using $ReduceOps$2 = ::java::util::stream::ReduceOps$2;
using $ReduceOps$3 = ::java::util::stream::ReduceOps$3;
using $ReduceOps$4 = ::java::util::stream::ReduceOps$4;
using $ReduceOps$5 = ::java::util::stream::ReduceOps$5;
using $ReduceOps$6 = ::java::util::stream::ReduceOps$6;
using $ReduceOps$7 = ::java::util::stream::ReduceOps$7;
using $ReduceOps$8 = ::java::util::stream::ReduceOps$8;
using $ReduceOps$9 = ::java::util::stream::ReduceOps$9;
using $StreamShape = ::java::util::stream::StreamShape;
using $TerminalOp = ::java::util::stream::TerminalOp;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _ReduceOps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ReduceOps, init$, void)},
	{"makeDouble", "(DLjava/util/function/DoubleBinaryOperator;)Ljava/util/stream/TerminalOp;", "(DLjava/util/function/DoubleBinaryOperator;)Ljava/util/stream/TerminalOp<Ljava/lang/Double;Ljava/lang/Double;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeDouble, $TerminalOp*, double, $DoubleBinaryOperator*)},
	{"makeDouble", "(Ljava/util/function/DoubleBinaryOperator;)Ljava/util/stream/TerminalOp;", "(Ljava/util/function/DoubleBinaryOperator;)Ljava/util/stream/TerminalOp<Ljava/lang/Double;Ljava/util/OptionalDouble;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeDouble, $TerminalOp*, $DoubleBinaryOperator*)},
	{"makeDouble", "(Ljava/util/function/Supplier;Ljava/util/function/ObjDoubleConsumer;Ljava/util/function/BinaryOperator;)Ljava/util/stream/TerminalOp;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjDoubleConsumer<TR;>;Ljava/util/function/BinaryOperator<TR;>;)Ljava/util/stream/TerminalOp<Ljava/lang/Double;TR;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeDouble, $TerminalOp*, $Supplier*, $ObjDoubleConsumer*, $BinaryOperator*)},
	{"makeDoubleCounting", "()Ljava/util/stream/TerminalOp;", "()Ljava/util/stream/TerminalOp<Ljava/lang/Double;Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeDoubleCounting, $TerminalOp*)},
	{"makeInt", "(ILjava/util/function/IntBinaryOperator;)Ljava/util/stream/TerminalOp;", "(ILjava/util/function/IntBinaryOperator;)Ljava/util/stream/TerminalOp<Ljava/lang/Integer;Ljava/lang/Integer;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeInt, $TerminalOp*, int32_t, $IntBinaryOperator*)},
	{"makeInt", "(Ljava/util/function/IntBinaryOperator;)Ljava/util/stream/TerminalOp;", "(Ljava/util/function/IntBinaryOperator;)Ljava/util/stream/TerminalOp<Ljava/lang/Integer;Ljava/util/OptionalInt;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeInt, $TerminalOp*, $IntBinaryOperator*)},
	{"makeInt", "(Ljava/util/function/Supplier;Ljava/util/function/ObjIntConsumer;Ljava/util/function/BinaryOperator;)Ljava/util/stream/TerminalOp;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjIntConsumer<TR;>;Ljava/util/function/BinaryOperator<TR;>;)Ljava/util/stream/TerminalOp<Ljava/lang/Integer;TR;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeInt, $TerminalOp*, $Supplier*, $ObjIntConsumer*, $BinaryOperator*)},
	{"makeIntCounting", "()Ljava/util/stream/TerminalOp;", "()Ljava/util/stream/TerminalOp<Ljava/lang/Integer;Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeIntCounting, $TerminalOp*)},
	{"makeLong", "(JLjava/util/function/LongBinaryOperator;)Ljava/util/stream/TerminalOp;", "(JLjava/util/function/LongBinaryOperator;)Ljava/util/stream/TerminalOp<Ljava/lang/Long;Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeLong, $TerminalOp*, int64_t, $LongBinaryOperator*)},
	{"makeLong", "(Ljava/util/function/LongBinaryOperator;)Ljava/util/stream/TerminalOp;", "(Ljava/util/function/LongBinaryOperator;)Ljava/util/stream/TerminalOp<Ljava/lang/Long;Ljava/util/OptionalLong;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeLong, $TerminalOp*, $LongBinaryOperator*)},
	{"makeLong", "(Ljava/util/function/Supplier;Ljava/util/function/ObjLongConsumer;Ljava/util/function/BinaryOperator;)Ljava/util/stream/TerminalOp;", "<R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/ObjLongConsumer<TR;>;Ljava/util/function/BinaryOperator<TR;>;)Ljava/util/stream/TerminalOp<Ljava/lang/Long;TR;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeLong, $TerminalOp*, $Supplier*, $ObjLongConsumer*, $BinaryOperator*)},
	{"makeLongCounting", "()Ljava/util/stream/TerminalOp;", "()Ljava/util/stream/TerminalOp<Ljava/lang/Long;Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeLongCounting, $TerminalOp*)},
	{"makeRef", "(Ljava/lang/Object;Ljava/util/function/BiFunction;Ljava/util/function/BinaryOperator;)Ljava/util/stream/TerminalOp;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;>(TU;Ljava/util/function/BiFunction<TU;-TT;TU;>;Ljava/util/function/BinaryOperator<TU;>;)Ljava/util/stream/TerminalOp<TT;TU;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeRef, $TerminalOp*, Object$*, $BiFunction*, $BinaryOperator*)},
	{"makeRef", "(Ljava/util/function/BinaryOperator;)Ljava/util/stream/TerminalOp;", "<T:Ljava/lang/Object;>(Ljava/util/function/BinaryOperator<TT;>;)Ljava/util/stream/TerminalOp<TT;Ljava/util/Optional<TT;>;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeRef, $TerminalOp*, $BinaryOperator*)},
	{"makeRef", "(Ljava/util/stream/Collector;)Ljava/util/stream/TerminalOp;", "<T:Ljava/lang/Object;I:Ljava/lang/Object;>(Ljava/util/stream/Collector<-TT;TI;*>;)Ljava/util/stream/TerminalOp<TT;TI;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeRef, $TerminalOp*, $Collector*)},
	{"makeRef", "(Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BiConsumer;)Ljava/util/stream/TerminalOp;", "<T:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/BiConsumer<TR;-TT;>;Ljava/util/function/BiConsumer<TR;TR;>;)Ljava/util/stream/TerminalOp<TT;TR;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeRef, $TerminalOp*, $Supplier*, $BiConsumer*, $BiConsumer*)},
	{"makeRefCounting", "()Ljava/util/stream/TerminalOp;", "<T:Ljava/lang/Object;>()Ljava/util/stream/TerminalOp<TT;Ljava/lang/Long;>;", $PUBLIC | $STATIC, $staticMethod(ReduceOps, makeRefCounting, $TerminalOp*)},
	{}
};

$InnerClassInfo _ReduceOps_InnerClassesInfo_[] = {
	{"java.util.stream.ReduceOps$ReduceTask", "java.util.stream.ReduceOps", "ReduceTask", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.ReduceOps$ReduceOp", "java.util.stream.ReduceOps", "ReduceOp", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.ReduceOps$Box", "java.util.stream.ReduceOps", "Box", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.util.stream.ReduceOps$AccumulatingSink", "java.util.stream.ReduceOps", "AccumulatingSink", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.stream.ReduceOps$CountingSink", "java.util.stream.ReduceOps", "CountingSink", $STATIC | $ABSTRACT},
	{"java.util.stream.ReduceOps$17", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$16", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$13ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$15", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$12ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$14", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$11ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$13", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$12", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$10ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$11", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$9ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$10", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$8ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$9", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$8", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$7ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$7", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$6ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$6", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$5ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$5", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$4", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$4ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$3", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$3ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$2", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$2ReducingSink", nullptr, "ReducingSink", 0},
	{"java.util.stream.ReduceOps$1", nullptr, nullptr, 0},
	{"java.util.stream.ReduceOps$1ReducingSink", nullptr, "ReducingSink", 0},
	{}
};

$ClassInfo _ReduceOps_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.ReduceOps",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ReduceOps_MethodInfo_,
	nullptr,
	nullptr,
	_ReduceOps_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.ReduceOps$ReduceTask,java.util.stream.ReduceOps$ReduceOp,java.util.stream.ReduceOps$Box,java.util.stream.ReduceOps$AccumulatingSink,java.util.stream.ReduceOps$CountingSink,java.util.stream.ReduceOps$CountingSink$OfDouble,java.util.stream.ReduceOps$CountingSink$OfLong,java.util.stream.ReduceOps$CountingSink$OfInt,java.util.stream.ReduceOps$CountingSink$OfRef,java.util.stream.ReduceOps$17,java.util.stream.ReduceOps$16,java.util.stream.ReduceOps$13ReducingSink,java.util.stream.ReduceOps$15,java.util.stream.ReduceOps$12ReducingSink,java.util.stream.ReduceOps$14,java.util.stream.ReduceOps$11ReducingSink,java.util.stream.ReduceOps$13,java.util.stream.ReduceOps$12,java.util.stream.ReduceOps$10ReducingSink,java.util.stream.ReduceOps$11,java.util.stream.ReduceOps$9ReducingSink,java.util.stream.ReduceOps$10,java.util.stream.ReduceOps$8ReducingSink,java.util.stream.ReduceOps$9,java.util.stream.ReduceOps$8,java.util.stream.ReduceOps$7ReducingSink,java.util.stream.ReduceOps$7,java.util.stream.ReduceOps$6ReducingSink,java.util.stream.ReduceOps$6,java.util.stream.ReduceOps$5ReducingSink,java.util.stream.ReduceOps$5,java.util.stream.ReduceOps$4,java.util.stream.ReduceOps$4ReducingSink,java.util.stream.ReduceOps$3,java.util.stream.ReduceOps$3ReducingSink,java.util.stream.ReduceOps$2,java.util.stream.ReduceOps$2ReducingSink,java.util.stream.ReduceOps$1,java.util.stream.ReduceOps$1ReducingSink"
};

$Object* allocate$ReduceOps($Class* clazz) {
	return $of($alloc(ReduceOps));
}

void ReduceOps::init$() {
}

$TerminalOp* ReduceOps::makeRef(Object$* seed, $BiFunction* reducer, $BinaryOperator* combiner) {
	$Objects::requireNonNull(reducer);
	$Objects::requireNonNull(combiner);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$1, $StreamShape::REFERENCE, combiner, reducer, seed);
}

$TerminalOp* ReduceOps::makeRef($BinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$2, $StreamShape::REFERENCE, operator$);
}

$TerminalOp* ReduceOps::makeRef($Collector* collector) {
	$useLocalCurrentObjectStackCache();
	$var($Supplier, supplier, $nc(($cast($Collector, $Objects::requireNonNull(collector))))->supplier());
	$var($BiConsumer, accumulator, collector->accumulator());
	$var($BinaryOperator, combiner, collector->combiner());
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$3, $StreamShape::REFERENCE, combiner, accumulator, supplier, collector);
}

$TerminalOp* ReduceOps::makeRef($Supplier* seedFactory, $BiConsumer* accumulator, $BiConsumer* reducer) {
	$Objects::requireNonNull(seedFactory);
	$Objects::requireNonNull(accumulator);
	$Objects::requireNonNull(reducer);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$4, $StreamShape::REFERENCE, reducer, accumulator, seedFactory);
}

$TerminalOp* ReduceOps::makeRefCounting() {
	$init($StreamShape);
	return $new($ReduceOps$5, $StreamShape::REFERENCE);
}

$TerminalOp* ReduceOps::makeInt(int32_t identity, $IntBinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$6, $StreamShape::INT_VALUE, operator$, identity);
}

$TerminalOp* ReduceOps::makeInt($IntBinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$7, $StreamShape::INT_VALUE, operator$);
}

$TerminalOp* ReduceOps::makeInt($Supplier* supplier, $ObjIntConsumer* accumulator, $BinaryOperator* combiner) {
	$Objects::requireNonNull(supplier);
	$Objects::requireNonNull(accumulator);
	$Objects::requireNonNull(combiner);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$8, $StreamShape::INT_VALUE, combiner, accumulator, supplier);
}

$TerminalOp* ReduceOps::makeIntCounting() {
	$init($StreamShape);
	return $new($ReduceOps$9, $StreamShape::INT_VALUE);
}

$TerminalOp* ReduceOps::makeLong(int64_t identity, $LongBinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$10, $StreamShape::LONG_VALUE, operator$, identity);
}

$TerminalOp* ReduceOps::makeLong($LongBinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$11, $StreamShape::LONG_VALUE, operator$);
}

$TerminalOp* ReduceOps::makeLong($Supplier* supplier, $ObjLongConsumer* accumulator, $BinaryOperator* combiner) {
	$Objects::requireNonNull(supplier);
	$Objects::requireNonNull(accumulator);
	$Objects::requireNonNull(combiner);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$12, $StreamShape::LONG_VALUE, combiner, accumulator, supplier);
}

$TerminalOp* ReduceOps::makeLongCounting() {
	$init($StreamShape);
	return $new($ReduceOps$13, $StreamShape::LONG_VALUE);
}

$TerminalOp* ReduceOps::makeDouble(double identity, $DoubleBinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$14, $StreamShape::DOUBLE_VALUE, operator$, identity);
}

$TerminalOp* ReduceOps::makeDouble($DoubleBinaryOperator* operator$) {
	$Objects::requireNonNull(operator$);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$15, $StreamShape::DOUBLE_VALUE, operator$);
}

$TerminalOp* ReduceOps::makeDouble($Supplier* supplier, $ObjDoubleConsumer* accumulator, $BinaryOperator* combiner) {
	$Objects::requireNonNull(supplier);
	$Objects::requireNonNull(accumulator);
	$Objects::requireNonNull(combiner);
	{
	}
	$init($StreamShape);
	return $new($ReduceOps$16, $StreamShape::DOUBLE_VALUE, combiner, accumulator, supplier);
}

$TerminalOp* ReduceOps::makeDoubleCounting() {
	$init($StreamShape);
	return $new($ReduceOps$17, $StreamShape::DOUBLE_VALUE);
}

ReduceOps::ReduceOps() {
}

$Class* ReduceOps::load$($String* name, bool initialize) {
	$loadClass(ReduceOps, name, initialize, &_ReduceOps_ClassInfo_, allocate$ReduceOps);
	return class$;
}

$Class* ReduceOps::class$ = nullptr;

		} // stream
	} // util
} // java