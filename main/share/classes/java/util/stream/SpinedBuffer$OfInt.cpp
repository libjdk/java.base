#include <java/util/stream/SpinedBuffer$OfInt.h>

#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/PrimitiveIterator$OfInt.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator$OfPrimitive.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/stream/SpinedBuffer$OfInt$1Splitr.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive$BaseSpliterator.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive.h>
#include <java/util/stream/SpinedBuffer.h>
#include <java/util/stream/Tripwire.h>
#include <jcpp.h>

#undef ENABLED

using $intArray2 = $Array<int32_t, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $Spliterator$OfPrimitive = ::java::util::Spliterator$OfPrimitive;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $IntConsumer = ::java::util::function::IntConsumer;
using $SpinedBuffer$OfInt$1Splitr = ::java::util::stream::SpinedBuffer$OfInt$1Splitr;
using $SpinedBuffer$OfPrimitive = ::java::util::stream::SpinedBuffer$OfPrimitive;
using $SpinedBuffer$OfPrimitive$BaseSpliterator = ::java::util::stream::SpinedBuffer$OfPrimitive$BaseSpliterator;
using $Tripwire = ::java::util::stream::Tripwire;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _SpinedBuffer$OfInt_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(SpinedBuffer$OfInt, init$, void)},
	{"<init>", "(I)V", nullptr, 0, $method(SpinedBuffer$OfInt, init$, void, int32_t)},
	{"accept", "(I)V", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, accept, void, int32_t)},
	{"arrayForEach", "([IIILjava/util/function/IntConsumer;)V", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfInt, arrayForEach, void, $ints*, int32_t, int32_t, $IntConsumer*)},
	{"arrayForEach", "(Ljava/lang/Object;IILjava/lang/Object;)V", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(SpinedBuffer$OfInt, arrayForEach, void, Object$*, int32_t, int32_t, Object$*)},
	{"arrayLength", "([I)I", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfInt, arrayLength, int32_t, $ints*)},
	{"arrayLength", "(Ljava/lang/Object;)I", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(SpinedBuffer$OfInt, arrayLength, int32_t, Object$*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-Ljava/lang/Integer;>;)V", $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, forEach, void, $Consumer*)},
	{"get", "(J)I", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, get, int32_t, int64_t)},
	{"iterator", "()Ljava/util/PrimitiveIterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, iterator, $Iterator*)},
	{"newArray", "(I)[I", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, newArray, $Object*, int32_t)},
	{"newArrayArray", "(I)[[I", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfInt, newArrayArray, $ObjectArray*, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, spliterator, $Spliterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfInt, toString, $String*)},
	{}
};

$InnerClassInfo _SpinedBuffer$OfInt_InnerClassesInfo_[] = {
	{"java.util.stream.SpinedBuffer$OfInt", "java.util.stream.SpinedBuffer", "OfInt", $STATIC},
	{"java.util.stream.SpinedBuffer$OfPrimitive", "java.util.stream.SpinedBuffer", "OfPrimitive", $STATIC | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$OfInt$1Splitr", nullptr, "Splitr", 0},
	{}
};

$ClassInfo _SpinedBuffer$OfInt_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.SpinedBuffer$OfInt",
	"java.util.stream.SpinedBuffer$OfPrimitive",
	"java.util.function.IntConsumer",
	nullptr,
	_SpinedBuffer$OfInt_MethodInfo_,
	"Ljava/util/stream/SpinedBuffer$OfPrimitive<Ljava/lang/Integer;[ILjava/util/function/IntConsumer;>;Ljava/util/function/IntConsumer;",
	nullptr,
	_SpinedBuffer$OfInt_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SpinedBuffer"
};

$Object* allocate$SpinedBuffer$OfInt($Class* clazz) {
	return $of($alloc(SpinedBuffer$OfInt));
}

int32_t SpinedBuffer$OfInt::hashCode() {
	 return this->$SpinedBuffer$OfPrimitive::hashCode();
}

bool SpinedBuffer$OfInt::equals(Object$* obj) {
	 return this->$SpinedBuffer$OfPrimitive::equals(obj);
}

$Object* SpinedBuffer$OfInt::clone() {
	 return this->$SpinedBuffer$OfPrimitive::clone();
}

void SpinedBuffer$OfInt::finalize() {
	this->$SpinedBuffer$OfPrimitive::finalize();
}

void SpinedBuffer$OfInt::init$() {
	$SpinedBuffer$OfPrimitive::init$();
}

void SpinedBuffer$OfInt::init$(int32_t initialCapacity) {
	$SpinedBuffer$OfPrimitive::init$(initialCapacity);
}

void SpinedBuffer$OfInt::forEach($Consumer* consumer) {
	if ($instanceOf($IntConsumer, consumer)) {
		forEach($cast($IntConsumer, consumer));
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$Tripwire::trip($of(this)->getClass(), "{0} calling SpinedBuffer.OfInt.forEach(Consumer)"_s);
		}
		$nc($($cast($Spliterator$OfInt, spliterator())))->forEachRemaining(consumer);
	}
}

$ObjectArray* SpinedBuffer$OfInt::newArrayArray(int32_t size) {
	return static_cast<$ObjectArray*>(static_cast<$Object*>(static_cast<$intArray2*>($new($intArray2, size))));
}

$Object* SpinedBuffer$OfInt::newArray(int32_t size) {
	return $of($new($ints, size));
}

int32_t SpinedBuffer$OfInt::arrayLength($ints* array) {
	return $nc(array)->length;
}

void SpinedBuffer$OfInt::arrayForEach($ints* array, int32_t from, int32_t to, $IntConsumer* consumer) {
	for (int32_t i = from; i < to; ++i) {
		$nc(consumer)->accept($nc(array)->get(i));
	}
}

void SpinedBuffer$OfInt::accept(int32_t i) {
	preAccept();
	$nc($cast($ints, this->curChunk))->set(this->elementIndex++, i);
}

int32_t SpinedBuffer$OfInt::get(int64_t index) {
	int32_t ch = chunkFor(index);
	if (this->spineIndex == 0 && ch == 0) {
		return $nc(($cast($ints, this->curChunk)))->get((int32_t)index);
	} else {
		return $nc($nc(($fcast($intArray2, this->spine)))->get(ch))->get((int32_t)(index - $nc(this->priorElementCount)->get(ch)));
	}
}

$Iterator* SpinedBuffer$OfInt::iterator() {
	return $Spliterators::iterator($($cast($Spliterator$OfInt, spliterator())));
}

$Spliterator* SpinedBuffer$OfInt::spliterator() {
	{
	}
	return static_cast<$Spliterator*>(static_cast<$Spliterator$OfPrimitive*>(static_cast<$SpinedBuffer$OfPrimitive$BaseSpliterator*>($new($SpinedBuffer$OfInt$1Splitr, this, 0, this->spineIndex, 0, this->elementIndex))));
}

$String* SpinedBuffer$OfInt::toString() {
	$useLocalCurrentObjectStackCache();
	$var($ints, array, $cast($ints, asPrimitiveArray()));
	if ($nc(array)->length < 200) {
		return $String::format("%s[length=%d, chunks=%d]%s"_s, $$new($ObjectArray, {
			$($of($of(this)->getClass()->getSimpleName())),
			$($of($Integer::valueOf(array->length))),
			$($of($Integer::valueOf(this->spineIndex))),
			$($of($Arrays::toString(array)))
		}));
	} else {
		$var($ints, array2, $Arrays::copyOf(array, 200));
		return $String::format("%s[length=%d, chunks=%d]%s..."_s, $$new($ObjectArray, {
			$($of($of(this)->getClass()->getSimpleName())),
			$($of($Integer::valueOf(array->length))),
			$($of($Integer::valueOf(this->spineIndex))),
			$($of($Arrays::toString(array2)))
		}));
	}
}

void SpinedBuffer$OfInt::arrayForEach(Object$* array, int32_t from, int32_t to, Object$* consumer) {
	this->arrayForEach($cast($ints, array), from, to, $cast($IntConsumer, consumer));
}

int32_t SpinedBuffer$OfInt::arrayLength(Object$* array) {
	return this->arrayLength($cast($ints, array));
}

SpinedBuffer$OfInt::SpinedBuffer$OfInt() {
}

$Class* SpinedBuffer$OfInt::load$($String* name, bool initialize) {
	$loadClass(SpinedBuffer$OfInt, name, initialize, &_SpinedBuffer$OfInt_ClassInfo_, allocate$SpinedBuffer$OfInt);
	return class$;
}

$Class* SpinedBuffer$OfInt::class$ = nullptr;

		} // stream
	} // util
} // java