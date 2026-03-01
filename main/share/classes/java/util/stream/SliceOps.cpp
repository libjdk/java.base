#include <java/util/stream/SliceOps.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IncompatibleClassChangeError.h>
#include <java/lang/Math.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/stream/AbstractPipeline.h>
#include <java/util/stream/DoubleStream.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/SliceOps$1.h>
#include <java/util/stream/SliceOps$2.h>
#include <java/util/stream/SliceOps$3.h>
#include <java/util/stream/SliceOps$4.h>
#include <java/util/stream/SliceOps$5.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamOpFlag.h>
#include <java/util/stream/StreamShape.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfDouble.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfInt.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfLong.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator$OfRef.h>
#include <java/util/stream/StreamSpliterators$SliceSpliterator.h>
#include <jcpp.h>

#undef DOUBLE_VALUE
#undef INT_VALUE
#undef IS_SHORT_CIRCUIT
#undef IS_SIZE_ADJUSTING
#undef LONG_VALUE
#undef MAX_VALUE
#undef REFERENCE
#undef SUBSIZED

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IncompatibleClassChangeError = ::java::lang::IncompatibleClassChangeError;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $AbstractPipeline = ::java::util::stream::AbstractPipeline;
using $DoubleStream = ::java::util::stream::DoubleStream;
using $IntStream = ::java::util::stream::IntStream;
using $LongStream = ::java::util::stream::LongStream;
using $SliceOps$1 = ::java::util::stream::SliceOps$1;
using $SliceOps$2 = ::java::util::stream::SliceOps$2;
using $SliceOps$3 = ::java::util::stream::SliceOps$3;
using $SliceOps$4 = ::java::util::stream::SliceOps$4;
using $SliceOps$5 = ::java::util::stream::SliceOps$5;
using $Stream = ::java::util::stream::Stream;
using $StreamOpFlag = ::java::util::stream::StreamOpFlag;
using $StreamShape = ::java::util::stream::StreamShape;
using $StreamSpliterators$SliceSpliterator = ::java::util::stream::StreamSpliterators$SliceSpliterator;
using $StreamSpliterators$SliceSpliterator$OfDouble = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfDouble;
using $StreamSpliterators$SliceSpliterator$OfInt = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfInt;
using $StreamSpliterators$SliceSpliterator$OfLong = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfLong;
using $StreamSpliterators$SliceSpliterator$OfRef = ::java::util::stream::StreamSpliterators$SliceSpliterator$OfRef;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _SliceOps_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SliceOps, $assertionsDisabled)},
	{}
};

$MethodInfo _SliceOps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SliceOps, init$, void)},
	{"calcSize", "(JJJ)J", nullptr, $PRIVATE | $STATIC, $staticMethod(SliceOps, calcSize, int64_t, int64_t, int64_t, int64_t)},
	{"calcSliceFence", "(JJ)J", nullptr, $PRIVATE | $STATIC, $staticMethod(SliceOps, calcSliceFence, int64_t, int64_t, int64_t)},
	{"flags", "(J)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SliceOps, flags, int32_t, int64_t)},
	{"makeDouble", "(Ljava/util/stream/AbstractPipeline;JJ)Ljava/util/stream/DoubleStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Double;*>;JJ)Ljava/util/stream/DoubleStream;", $PUBLIC | $STATIC, $staticMethod(SliceOps, makeDouble, $DoubleStream*, $AbstractPipeline*, int64_t, int64_t)},
	{"makeInt", "(Ljava/util/stream/AbstractPipeline;JJ)Ljava/util/stream/IntStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Integer;*>;JJ)Ljava/util/stream/IntStream;", $PUBLIC | $STATIC, $staticMethod(SliceOps, makeInt, $IntStream*, $AbstractPipeline*, int64_t, int64_t)},
	{"makeLong", "(Ljava/util/stream/AbstractPipeline;JJ)Ljava/util/stream/LongStream;", "(Ljava/util/stream/AbstractPipeline<*Ljava/lang/Long;*>;JJ)Ljava/util/stream/LongStream;", $PUBLIC | $STATIC, $staticMethod(SliceOps, makeLong, $LongStream*, $AbstractPipeline*, int64_t, int64_t)},
	{"makeRef", "(Ljava/util/stream/AbstractPipeline;JJ)Ljava/util/stream/Stream;", "<T:Ljava/lang/Object;>(Ljava/util/stream/AbstractPipeline<*TT;*>;JJ)Ljava/util/stream/Stream<TT;>;", $PUBLIC | $STATIC, $staticMethod(SliceOps, makeRef, $Stream*, $AbstractPipeline*, int64_t, int64_t)},
	{"sliceSpliterator", "(Ljava/util/stream/StreamShape;Ljava/util/Spliterator;JJ)Ljava/util/Spliterator;", "<P_IN:Ljava/lang/Object;>(Ljava/util/stream/StreamShape;Ljava/util/Spliterator<TP_IN;>;JJ)Ljava/util/Spliterator<TP_IN;>;", $PRIVATE | $STATIC, $staticMethod(SliceOps, sliceSpliterator, $Spliterator*, $StreamShape*, $Spliterator*, int64_t, int64_t)},
	{}
};

$InnerClassInfo _SliceOps_InnerClassesInfo_[] = {
	{"java.util.stream.SliceOps$5", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.util.stream.SliceOps$SliceTask", "java.util.stream.SliceOps", "SliceTask", $PRIVATE | $STATIC | $FINAL},
	{"java.util.stream.SliceOps$4", nullptr, nullptr, 0},
	{"java.util.stream.SliceOps$3", nullptr, nullptr, 0},
	{"java.util.stream.SliceOps$2", nullptr, nullptr, 0},
	{"java.util.stream.SliceOps$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SliceOps_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.SliceOps",
	"java.lang.Object",
	nullptr,
	_SliceOps_FieldInfo_,
	_SliceOps_MethodInfo_,
	nullptr,
	nullptr,
	_SliceOps_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.SliceOps$5,java.util.stream.SliceOps$SliceTask,java.util.stream.SliceOps$4,java.util.stream.SliceOps$4$1,java.util.stream.SliceOps$3,java.util.stream.SliceOps$3$1,java.util.stream.SliceOps$2,java.util.stream.SliceOps$2$1,java.util.stream.SliceOps$1,java.util.stream.SliceOps$1$1"
};

$Object* allocate$SliceOps($Class* clazz) {
	return $of($alloc(SliceOps));
}

bool SliceOps::$assertionsDisabled = false;

void SliceOps::init$() {
}

int64_t SliceOps::calcSize(int64_t size, int64_t skip, int64_t limit) {
	$init(SliceOps);
	return size >= 0 ? $Math::max((int64_t)0, $Math::min(size - skip, limit)) : (int64_t)-1;
}

int64_t SliceOps::calcSliceFence(int64_t skip, int64_t limit) {
	$init(SliceOps);
	int64_t sliceFence = limit >= 0 ? skip + limit : $Long::MAX_VALUE;
	return (sliceFence >= 0) ? sliceFence : $Long::MAX_VALUE;
}

$Spliterator* SliceOps::sliceSpliterator($StreamShape* shape, $Spliterator* s, int64_t skip, int64_t limit) {
	$init(SliceOps);
	$useLocalCurrentObjectStackCache();
	if (!SliceOps::$assertionsDisabled && !$nc(s)->hasCharacteristics($Spliterator::SUBSIZED)) {
		$throwNew($AssertionError);
	}
	int64_t sliceFence = calcSliceFence(skip, limit);
	$init($SliceOps$5);

	$var($StreamSpliterators$SliceSpliterator, var$0, nullptr)
	switch ($nc($SliceOps$5::$SwitchMap$java$util$stream$StreamShape)->get($nc((shape))->ordinal())) {
	default:
		{
			$throwNew($IncompatibleClassChangeError);
		}
	case 1:
		{
			$assign(var$0, $new($StreamSpliterators$SliceSpliterator$OfRef, s, skip, sliceFence));
			break;
		}
	case 2:
		{
			$assign(var$0, $new($StreamSpliterators$SliceSpliterator$OfInt, $cast($Spliterator$OfInt, s), skip, sliceFence));
			break;
		}
	case 3:
		{
			$assign(var$0, $new($StreamSpliterators$SliceSpliterator$OfLong, $cast($Spliterator$OfLong, s), skip, sliceFence));
			break;
		}
	case 4:
		{
			$assign(var$0, $new($StreamSpliterators$SliceSpliterator$OfDouble, $cast($Spliterator$OfDouble, s), skip, sliceFence));
			break;
		}
	}
	$var($Spliterator, sliceSpliterator, $cast($Spliterator, var$0));
	return sliceSpliterator;
}

$Stream* SliceOps::makeRef($AbstractPipeline* upstream, int64_t skip, int64_t limit) {
	$init(SliceOps);
	$useLocalCurrentObjectStackCache();
	if (skip < 0) {
		$throwNew($IllegalArgumentException, $$str({"Skip must be non-negative: "_s, $$str(skip)}));
	}
	int64_t normalizedLimit = limit >= 0 ? limit : $Long::MAX_VALUE;
	$init($StreamShape);
	return $new($SliceOps$1, upstream, $StreamShape::REFERENCE, flags(limit), skip, normalizedLimit, limit);
}

$IntStream* SliceOps::makeInt($AbstractPipeline* upstream, int64_t skip, int64_t limit) {
	$init(SliceOps);
	$useLocalCurrentObjectStackCache();
	if (skip < 0) {
		$throwNew($IllegalArgumentException, $$str({"Skip must be non-negative: "_s, $$str(skip)}));
	}
	int64_t normalizedLimit = limit >= 0 ? limit : $Long::MAX_VALUE;
	$init($StreamShape);
	return $as($IntStream, $new($SliceOps$2, upstream, $StreamShape::INT_VALUE, flags(limit), skip, normalizedLimit, limit));
}

$LongStream* SliceOps::makeLong($AbstractPipeline* upstream, int64_t skip, int64_t limit) {
	$init(SliceOps);
	$useLocalCurrentObjectStackCache();
	if (skip < 0) {
		$throwNew($IllegalArgumentException, $$str({"Skip must be non-negative: "_s, $$str(skip)}));
	}
	int64_t normalizedLimit = limit >= 0 ? limit : $Long::MAX_VALUE;
	$init($StreamShape);
	return $as($LongStream, $new($SliceOps$3, upstream, $StreamShape::LONG_VALUE, flags(limit), skip, normalizedLimit, limit));
}

$DoubleStream* SliceOps::makeDouble($AbstractPipeline* upstream, int64_t skip, int64_t limit) {
	$init(SliceOps);
	$useLocalCurrentObjectStackCache();
	if (skip < 0) {
		$throwNew($IllegalArgumentException, $$str({"Skip must be non-negative: "_s, $$str(skip)}));
	}
	int64_t normalizedLimit = limit >= 0 ? limit : $Long::MAX_VALUE;
	$init($StreamShape);
	return $as($DoubleStream, $new($SliceOps$4, upstream, $StreamShape::DOUBLE_VALUE, flags(limit), skip, normalizedLimit, limit));
}

int32_t SliceOps::flags(int64_t limit) {
	$init(SliceOps);
	$init($StreamOpFlag);
	return $StreamOpFlag::IS_SIZE_ADJUSTING | ((limit != -1) ? $StreamOpFlag::IS_SHORT_CIRCUIT : 0);
}

void clinit$SliceOps($Class* class$) {
	SliceOps::$assertionsDisabled = !SliceOps::class$->desiredAssertionStatus();
}

SliceOps::SliceOps() {
}

$Class* SliceOps::load$($String* name, bool initialize) {
	$loadClass(SliceOps, name, initialize, &_SliceOps_ClassInfo_, clinit$SliceOps, allocate$SliceOps);
	return class$;
}

$Class* SliceOps::class$ = nullptr;

		} // stream
	} // util
} // java