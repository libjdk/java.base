#include <java/util/stream/StreamSupport.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/DoublePipeline$Head.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntPipeline$Head.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongPipeline$Head.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/ReferencePipeline$Head.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamOpFlag.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Supplier = ::java::util::function::Supplier;
using $DoublePipeline$Head = ::java::util::stream::DoublePipeline$Head;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntPipeline$Head = ::java::util::stream::IntPipeline$Head;
using $IntStream = ::java::util::stream::IntStream;
using $LongPipeline$Head = ::java::util::stream::LongPipeline$Head;
using $LongStream = ::java::util::stream::LongStream;
using $ReferencePipeline$Head = ::java::util::stream::ReferencePipeline$Head;
using $Stream = ::java::util::stream::Stream;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _StreamSupport_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(StreamSupport, init$, void)},
	{"doubleStream", "(Ljava/util/Spliterator$OfDouble;Z)Ljava/util/stream/DoubleStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamSupport, doubleStream, $DoubleStream*, $Spliterator$OfDouble*, bool)},
	{"doubleStream", "(Ljava/util/function/Supplier;IZ)Ljava/util/stream/DoubleStream;", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator$OfDouble;>;IZ)Ljava/util/stream/DoubleStream;", $PUBLIC | $STATIC, $staticMethod(StreamSupport, doubleStream, $DoubleStream*, $Supplier*, int32_t, bool)},
	{"intStream", "(Ljava/util/Spliterator$OfInt;Z)Ljava/util/stream/IntStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamSupport, intStream, $IntStream*, $Spliterator$OfInt*, bool)},
	{"intStream", "(Ljava/util/function/Supplier;IZ)Ljava/util/stream/IntStream;", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator$OfInt;>;IZ)Ljava/util/stream/IntStream;", $PUBLIC | $STATIC, $staticMethod(StreamSupport, intStream, $IntStream*, $Supplier*, int32_t, bool)},
	{"longStream", "(Ljava/util/Spliterator$OfLong;Z)Ljava/util/stream/LongStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamSupport, longStream, $LongStream*, $Spliterator$OfLong*, bool)},
	{"longStream", "(Ljava/util/function/Supplier;IZ)Ljava/util/stream/LongStream;", "(Ljava/util/function/Supplier<+Ljava/util/Spliterator$OfLong;>;IZ)Ljava/util/stream/LongStream;", $PUBLIC | $STATIC, $staticMethod(StreamSupport, longStream, $LongStream*, $Supplier*, int32_t, bool)},
	{"stream", "(Ljava/util/Spliterator;Z)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/Spliterator<TT;>;Z)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(StreamSupport, stream, $Stream*, $Spliterator*, bool)},
	{"stream", "(Ljava/util/function/Supplier;IZ)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/function/Supplier<+Ljava/util/Spliterator<TT;>;>;IZ)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(StreamSupport, stream, $Stream*, $Supplier*, int32_t, bool)},
	{}
};

$ClassInfo _StreamSupport_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.stream.StreamSupport",
	"java.lang.Object",
	nullptr,
	nullptr,
	_StreamSupport_MethodInfo_
};

$Object* allocate$StreamSupport($Class* clazz) {
	return $of($alloc(StreamSupport));
}

void StreamSupport::init$() {
}

$Stream* StreamSupport::stream($Spliterator* spliterator, bool parallel) {
	$Objects::requireNonNull(spliterator);
	return $new($ReferencePipeline$Head, spliterator, $StreamOpFlag::fromCharacteristics(spliterator), parallel);
}

$Stream* StreamSupport::stream($Supplier* supplier, int32_t characteristics, bool parallel) {
	$Objects::requireNonNull(supplier);
	return $new($ReferencePipeline$Head, supplier, $StreamOpFlag::fromCharacteristics(characteristics), parallel);
}

$IntStream* StreamSupport::intStream($Spliterator$OfInt* spliterator, bool parallel) {
	return $as($IntStream, $new($IntPipeline$Head, static_cast<$Spliterator*>(spliterator), $StreamOpFlag::fromCharacteristics(static_cast<$Spliterator*>(spliterator)), parallel));
}

$IntStream* StreamSupport::intStream($Supplier* supplier, int32_t characteristics, bool parallel) {
	return $as($IntStream, $new($IntPipeline$Head, supplier, $StreamOpFlag::fromCharacteristics(characteristics), parallel));
}

$LongStream* StreamSupport::longStream($Spliterator$OfLong* spliterator, bool parallel) {
	return $as($LongStream, $new($LongPipeline$Head, static_cast<$Spliterator*>(spliterator), $StreamOpFlag::fromCharacteristics(static_cast<$Spliterator*>(spliterator)), parallel));
}

$LongStream* StreamSupport::longStream($Supplier* supplier, int32_t characteristics, bool parallel) {
	return $as($LongStream, $new($LongPipeline$Head, supplier, $StreamOpFlag::fromCharacteristics(characteristics), parallel));
}

$DoubleStream* StreamSupport::doubleStream($Spliterator$OfDouble* spliterator, bool parallel) {
	return $as($DoubleStream, $new($DoublePipeline$Head, static_cast<$Spliterator*>(spliterator), $StreamOpFlag::fromCharacteristics(static_cast<$Spliterator*>(spliterator)), parallel));
}

$DoubleStream* StreamSupport::doubleStream($Supplier* supplier, int32_t characteristics, bool parallel) {
	return $as($DoubleStream, $new($DoublePipeline$Head, supplier, $StreamOpFlag::fromCharacteristics(characteristics), parallel));
}

StreamSupport::StreamSupport() {
}

$Class* StreamSupport::load$($String* name, bool initialize) {
	$loadClass(StreamSupport, name, initialize, &_StreamSupport_ClassInfo_, allocate$StreamSupport);
	return class$;
}

$Class* StreamSupport::class$ = nullptr;

		} // stream
	} // util
} // java