#include <java/util/stream/SpinedBuffer$OfDouble.h>

#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/PrimitiveIterator$OfDouble.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator$OfPrimitive.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/stream/SpinedBuffer$OfDouble$1Splitr.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive$BaseSpliterator.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive.h>
#include <java/util/stream/SpinedBuffer.h>
#include <java/util/stream/Tripwire.h>
#include <jcpp.h>

#undef ENABLED

using $doubleArray2 = $Array<double, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $Spliterator$OfPrimitive = ::java::util::Spliterator$OfPrimitive;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $SpinedBuffer$OfDouble$1Splitr = ::java::util::stream::SpinedBuffer$OfDouble$1Splitr;
using $SpinedBuffer$OfPrimitive = ::java::util::stream::SpinedBuffer$OfPrimitive;
using $SpinedBuffer$OfPrimitive$BaseSpliterator = ::java::util::stream::SpinedBuffer$OfPrimitive$BaseSpliterator;
using $Tripwire = ::java::util::stream::Tripwire;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _SpinedBuffer$OfDouble_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(SpinedBuffer$OfDouble, init$, void)},
	{"<init>", "(I)V", nullptr, 0, $method(SpinedBuffer$OfDouble, init$, void, int32_t)},
	{"accept", "(D)V", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, accept, void, double)},
	{"arrayForEach", "([DIILjava/util/function/DoubleConsumer;)V", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfDouble, arrayForEach, void, $doubles*, int32_t, int32_t, $DoubleConsumer*)},
	{"arrayForEach", "(Ljava/lang/Object;IILjava/lang/Object;)V", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(SpinedBuffer$OfDouble, arrayForEach, void, Object$*, int32_t, int32_t, Object$*)},
	{"arrayLength", "([D)I", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfDouble, arrayLength, int32_t, $doubles*)},
	{"arrayLength", "(Ljava/lang/Object;)I", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(SpinedBuffer$OfDouble, arrayLength, int32_t, Object$*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-Ljava/lang/Double;>;)V", $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, forEach, void, $Consumer*)},
	{"get", "(J)D", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, get, double, int64_t)},
	{"iterator", "()Ljava/util/PrimitiveIterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, iterator, $Iterator*)},
	{"newArray", "(I)[D", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, newArray, $Object*, int32_t)},
	{"newArrayArray", "(I)[[D", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfDouble, newArrayArray, $ObjectArray*, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, spliterator, $Spliterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfDouble, toString, $String*)},
	{}
};

$InnerClassInfo _SpinedBuffer$OfDouble_InnerClassesInfo_[] = {
	{"java.util.stream.SpinedBuffer$OfDouble", "java.util.stream.SpinedBuffer", "OfDouble", $STATIC},
	{"java.util.stream.SpinedBuffer$OfPrimitive", "java.util.stream.SpinedBuffer", "OfPrimitive", $STATIC | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$OfDouble$1Splitr", nullptr, "Splitr", 0},
	{}
};

$ClassInfo _SpinedBuffer$OfDouble_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.SpinedBuffer$OfDouble",
	"java.util.stream.SpinedBuffer$OfPrimitive",
	"java.util.function.DoubleConsumer",
	nullptr,
	_SpinedBuffer$OfDouble_MethodInfo_,
	"Ljava/util/stream/SpinedBuffer$OfPrimitive<Ljava/lang/Double;[DLjava/util/function/DoubleConsumer;>;Ljava/util/function/DoubleConsumer;",
	nullptr,
	_SpinedBuffer$OfDouble_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SpinedBuffer"
};

$Object* allocate$SpinedBuffer$OfDouble($Class* clazz) {
	return $of($alloc(SpinedBuffer$OfDouble));
}

int32_t SpinedBuffer$OfDouble::hashCode() {
	 return this->$SpinedBuffer$OfPrimitive::hashCode();
}

bool SpinedBuffer$OfDouble::equals(Object$* obj) {
	 return this->$SpinedBuffer$OfPrimitive::equals(obj);
}

$Object* SpinedBuffer$OfDouble::clone() {
	 return this->$SpinedBuffer$OfPrimitive::clone();
}

void SpinedBuffer$OfDouble::finalize() {
	this->$SpinedBuffer$OfPrimitive::finalize();
}

void SpinedBuffer$OfDouble::init$() {
	$SpinedBuffer$OfPrimitive::init$();
}

void SpinedBuffer$OfDouble::init$(int32_t initialCapacity) {
	$SpinedBuffer$OfPrimitive::init$(initialCapacity);
}

void SpinedBuffer$OfDouble::forEach($Consumer* consumer) {
	if ($instanceOf($DoubleConsumer, consumer)) {
		forEach($cast($DoubleConsumer, consumer));
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$Tripwire::trip($of(this)->getClass(), "{0} calling SpinedBuffer.OfDouble.forEach(Consumer)"_s);
		}
		$nc($($cast($Spliterator$OfDouble, spliterator())))->forEachRemaining(consumer);
	}
}

$ObjectArray* SpinedBuffer$OfDouble::newArrayArray(int32_t size) {
	return static_cast<$ObjectArray*>(static_cast<$Object*>(static_cast<$doubleArray2*>($new($doubleArray2, size))));
}

$Object* SpinedBuffer$OfDouble::newArray(int32_t size) {
	return $of($new($doubles, size));
}

int32_t SpinedBuffer$OfDouble::arrayLength($doubles* array) {
	return $nc(array)->length;
}

void SpinedBuffer$OfDouble::arrayForEach($doubles* array, int32_t from, int32_t to, $DoubleConsumer* consumer) {
	for (int32_t i = from; i < to; ++i) {
		$nc(consumer)->accept($nc(array)->get(i));
	}
}

void SpinedBuffer$OfDouble::accept(double i) {
	preAccept();
	$nc($cast($doubles, this->curChunk))->set(this->elementIndex++, i);
}

double SpinedBuffer$OfDouble::get(int64_t index) {
	int32_t ch = chunkFor(index);
	if (this->spineIndex == 0 && ch == 0) {
		return $nc(($cast($doubles, this->curChunk)))->get((int32_t)index);
	} else {
		return $nc($nc(($fcast($doubleArray2, this->spine)))->get(ch))->get((int32_t)(index - $nc(this->priorElementCount)->get(ch)));
	}
}

$Iterator* SpinedBuffer$OfDouble::iterator() {
	return $Spliterators::iterator($($cast($Spliterator$OfDouble, spliterator())));
}

$Spliterator* SpinedBuffer$OfDouble::spliterator() {
	{
	}
	return static_cast<$Spliterator*>(static_cast<$Spliterator$OfPrimitive*>(static_cast<$SpinedBuffer$OfPrimitive$BaseSpliterator*>($new($SpinedBuffer$OfDouble$1Splitr, this, 0, this->spineIndex, 0, this->elementIndex))));
}

$String* SpinedBuffer$OfDouble::toString() {
	$useLocalCurrentObjectStackCache();
	$var($doubles, array, $cast($doubles, asPrimitiveArray()));
	if ($nc(array)->length < 200) {
		return $String::format("%s[length=%d, chunks=%d]%s"_s, $$new($ObjectArray, {
			$($of($of(this)->getClass()->getSimpleName())),
			$($of($Integer::valueOf(array->length))),
			$($of($Integer::valueOf(this->spineIndex))),
			$($of($Arrays::toString(array)))
		}));
	} else {
		$var($doubles, array2, $Arrays::copyOf(array, 200));
		return $String::format("%s[length=%d, chunks=%d]%s..."_s, $$new($ObjectArray, {
			$($of($of(this)->getClass()->getSimpleName())),
			$($of($Integer::valueOf(array->length))),
			$($of($Integer::valueOf(this->spineIndex))),
			$($of($Arrays::toString(array2)))
		}));
	}
}

void SpinedBuffer$OfDouble::arrayForEach(Object$* array, int32_t from, int32_t to, Object$* consumer) {
	this->arrayForEach($cast($doubles, array), from, to, $cast($DoubleConsumer, consumer));
}

int32_t SpinedBuffer$OfDouble::arrayLength(Object$* array) {
	return this->arrayLength($cast($doubles, array));
}

SpinedBuffer$OfDouble::SpinedBuffer$OfDouble() {
}

$Class* SpinedBuffer$OfDouble::load$($String* name, bool initialize) {
	$loadClass(SpinedBuffer$OfDouble, name, initialize, &_SpinedBuffer$OfDouble_ClassInfo_, allocate$SpinedBuffer$OfDouble);
	return class$;
}

$Class* SpinedBuffer$OfDouble::class$ = nullptr;

		} // stream
	} // util
} // java