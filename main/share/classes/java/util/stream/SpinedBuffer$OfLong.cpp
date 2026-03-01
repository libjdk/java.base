#include <java/util/stream/SpinedBuffer$OfLong.h>

#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/PrimitiveIterator$OfLong.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator$OfPrimitive.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/stream/SpinedBuffer$OfLong$1Splitr.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive$BaseSpliterator.h>
#include <java/util/stream/SpinedBuffer$OfPrimitive.h>
#include <java/util/stream/SpinedBuffer.h>
#include <java/util/stream/Tripwire.h>
#include <jcpp.h>

#undef ENABLED

using $longArray2 = $Array<int64_t, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $Spliterator$OfPrimitive = ::java::util::Spliterator$OfPrimitive;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $LongConsumer = ::java::util::function::LongConsumer;
using $SpinedBuffer$OfLong$1Splitr = ::java::util::stream::SpinedBuffer$OfLong$1Splitr;
using $SpinedBuffer$OfPrimitive = ::java::util::stream::SpinedBuffer$OfPrimitive;
using $SpinedBuffer$OfPrimitive$BaseSpliterator = ::java::util::stream::SpinedBuffer$OfPrimitive$BaseSpliterator;
using $Tripwire = ::java::util::stream::Tripwire;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _SpinedBuffer$OfLong_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(SpinedBuffer$OfLong, init$, void)},
	{"<init>", "(I)V", nullptr, 0, $method(SpinedBuffer$OfLong, init$, void, int32_t)},
	{"accept", "(J)V", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, accept, void, int64_t)},
	{"arrayForEach", "([JIILjava/util/function/LongConsumer;)V", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfLong, arrayForEach, void, $longs*, int32_t, int32_t, $LongConsumer*)},
	{"arrayForEach", "(Ljava/lang/Object;IILjava/lang/Object;)V", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(SpinedBuffer$OfLong, arrayForEach, void, Object$*, int32_t, int32_t, Object$*)},
	{"arrayLength", "([J)I", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfLong, arrayLength, int32_t, $longs*)},
	{"arrayLength", "(Ljava/lang/Object;)I", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(SpinedBuffer$OfLong, arrayLength, int32_t, Object$*)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-Ljava/lang/Long;>;)V", $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, forEach, void, $Consumer*)},
	{"get", "(J)J", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, get, int64_t, int64_t)},
	{"iterator", "()Ljava/util/PrimitiveIterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, iterator, $Iterator*)},
	{"newArray", "(I)[J", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, newArray, $Object*, int32_t)},
	{"newArrayArray", "(I)[[J", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer$OfLong, newArrayArray, $ObjectArray*, int32_t)},
	{"spliterator", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, spliterator, $Spliterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$OfLong, toString, $String*)},
	{}
};

$InnerClassInfo _SpinedBuffer$OfLong_InnerClassesInfo_[] = {
	{"java.util.stream.SpinedBuffer$OfLong", "java.util.stream.SpinedBuffer", "OfLong", $STATIC},
	{"java.util.stream.SpinedBuffer$OfPrimitive", "java.util.stream.SpinedBuffer", "OfPrimitive", $STATIC | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$OfLong$1Splitr", nullptr, "Splitr", 0},
	{}
};

$ClassInfo _SpinedBuffer$OfLong_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.SpinedBuffer$OfLong",
	"java.util.stream.SpinedBuffer$OfPrimitive",
	"java.util.function.LongConsumer",
	nullptr,
	_SpinedBuffer$OfLong_MethodInfo_,
	"Ljava/util/stream/SpinedBuffer$OfPrimitive<Ljava/lang/Long;[JLjava/util/function/LongConsumer;>;Ljava/util/function/LongConsumer;",
	nullptr,
	_SpinedBuffer$OfLong_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.SpinedBuffer"
};

$Object* allocate$SpinedBuffer$OfLong($Class* clazz) {
	return $of($alloc(SpinedBuffer$OfLong));
}

int32_t SpinedBuffer$OfLong::hashCode() {
	 return this->$SpinedBuffer$OfPrimitive::hashCode();
}

bool SpinedBuffer$OfLong::equals(Object$* obj) {
	 return this->$SpinedBuffer$OfPrimitive::equals(obj);
}

$Object* SpinedBuffer$OfLong::clone() {
	 return this->$SpinedBuffer$OfPrimitive::clone();
}

void SpinedBuffer$OfLong::finalize() {
	this->$SpinedBuffer$OfPrimitive::finalize();
}

void SpinedBuffer$OfLong::init$() {
	$SpinedBuffer$OfPrimitive::init$();
}

void SpinedBuffer$OfLong::init$(int32_t initialCapacity) {
	$SpinedBuffer$OfPrimitive::init$(initialCapacity);
}

void SpinedBuffer$OfLong::forEach($Consumer* consumer) {
	if ($instanceOf($LongConsumer, consumer)) {
		forEach($cast($LongConsumer, consumer));
	} else {
		$init($Tripwire);
		if ($Tripwire::ENABLED) {
			$Tripwire::trip($of(this)->getClass(), "{0} calling SpinedBuffer.OfLong.forEach(Consumer)"_s);
		}
		$nc($($cast($Spliterator$OfLong, spliterator())))->forEachRemaining(consumer);
	}
}

$ObjectArray* SpinedBuffer$OfLong::newArrayArray(int32_t size) {
	return static_cast<$ObjectArray*>(static_cast<$Object*>(static_cast<$longArray2*>($new($longArray2, size))));
}

$Object* SpinedBuffer$OfLong::newArray(int32_t size) {
	return $of($new($longs, size));
}

int32_t SpinedBuffer$OfLong::arrayLength($longs* array) {
	return $nc(array)->length;
}

void SpinedBuffer$OfLong::arrayForEach($longs* array, int32_t from, int32_t to, $LongConsumer* consumer) {
	for (int32_t i = from; i < to; ++i) {
		$nc(consumer)->accept($nc(array)->get(i));
	}
}

void SpinedBuffer$OfLong::accept(int64_t i) {
	preAccept();
	$nc($cast($longs, this->curChunk))->set(this->elementIndex++, i);
}

int64_t SpinedBuffer$OfLong::get(int64_t index) {
	int32_t ch = chunkFor(index);
	if (this->spineIndex == 0 && ch == 0) {
		return $nc(($cast($longs, this->curChunk)))->get((int32_t)index);
	} else {
		return $nc($nc(($fcast($longArray2, this->spine)))->get(ch))->get((int32_t)(index - $nc(this->priorElementCount)->get(ch)));
	}
}

$Iterator* SpinedBuffer$OfLong::iterator() {
	return $Spliterators::iterator($($cast($Spliterator$OfLong, spliterator())));
}

$Spliterator* SpinedBuffer$OfLong::spliterator() {
	{
	}
	return static_cast<$Spliterator*>(static_cast<$Spliterator$OfPrimitive*>(static_cast<$SpinedBuffer$OfPrimitive$BaseSpliterator*>($new($SpinedBuffer$OfLong$1Splitr, this, 0, this->spineIndex, 0, this->elementIndex))));
}

$String* SpinedBuffer$OfLong::toString() {
	$useLocalCurrentObjectStackCache();
	$var($longs, array, $cast($longs, asPrimitiveArray()));
	if ($nc(array)->length < 200) {
		return $String::format("%s[length=%d, chunks=%d]%s"_s, $$new($ObjectArray, {
			$($of($of(this)->getClass()->getSimpleName())),
			$($of($Integer::valueOf(array->length))),
			$($of($Integer::valueOf(this->spineIndex))),
			$($of($Arrays::toString(array)))
		}));
	} else {
		$var($longs, array2, $Arrays::copyOf(array, 200));
		return $String::format("%s[length=%d, chunks=%d]%s..."_s, $$new($ObjectArray, {
			$($of($of(this)->getClass()->getSimpleName())),
			$($of($Integer::valueOf(array->length))),
			$($of($Integer::valueOf(this->spineIndex))),
			$($of($Arrays::toString(array2)))
		}));
	}
}

void SpinedBuffer$OfLong::arrayForEach(Object$* array, int32_t from, int32_t to, Object$* consumer) {
	this->arrayForEach($cast($longs, array), from, to, $cast($LongConsumer, consumer));
}

int32_t SpinedBuffer$OfLong::arrayLength(Object$* array) {
	return this->arrayLength($cast($longs, array));
}

SpinedBuffer$OfLong::SpinedBuffer$OfLong() {
}

$Class* SpinedBuffer$OfLong::load$($String* name, bool initialize) {
	$loadClass(SpinedBuffer$OfLong, name, initialize, &_SpinedBuffer$OfLong_ClassInfo_, allocate$SpinedBuffer$OfLong);
	return class$;
}

$Class* SpinedBuffer$OfLong::class$ = nullptr;

		} // stream
	} // util
} // java