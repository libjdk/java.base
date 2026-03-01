#include <java/util/stream/SpinedBuffer.h>

#include <java/io/Serializable.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Spliterator.h>
#include <java/util/Spliterators.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/AbstractSpinedBuffer.h>
#include <java/util/stream/Nodes.h>
#include <java/util/stream/SpinedBuffer$1Splitr.h>
#include <jcpp.h>

#undef BAD_SIZE
#undef MAX_ARRAY_SIZE
#undef MIN_SPINE_SIZE
#undef SPLITERATOR_CHARACTERISTICS

using $ObjectArray2 = $Array<::java::lang::Object, 2>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Spliterator = ::java::util::Spliterator;
using $Spliterators = ::java::util::Spliterators;
using $Consumer = ::java::util::function::Consumer;
using $IntFunction = ::java::util::function::IntFunction;
using $AbstractSpinedBuffer = ::java::util::stream::AbstractSpinedBuffer;
using $Nodes = ::java::util::stream::Nodes;
using $SpinedBuffer$1Splitr = ::java::util::stream::SpinedBuffer$1Splitr;

namespace java {
	namespace util {
		namespace stream {

class SpinedBuffer$$Lambda$add : public $Consumer {
	$class(SpinedBuffer$$Lambda$add, $NO_CLASS_INIT, $Consumer)
public:
	void init$($List* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->add(e);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SpinedBuffer$$Lambda$add>());
	}
	$List* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SpinedBuffer$$Lambda$add::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SpinedBuffer$$Lambda$add, inst$)},
	{}
};
$MethodInfo SpinedBuffer$$Lambda$add::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(SpinedBuffer$$Lambda$add, init$, void, $List*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer$$Lambda$add, accept, void, Object$*)},
	{}
};
$ClassInfo SpinedBuffer$$Lambda$add::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.stream.SpinedBuffer$$Lambda$add",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* SpinedBuffer$$Lambda$add::load$($String* name, bool initialize) {
	$loadClass(SpinedBuffer$$Lambda$add, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SpinedBuffer$$Lambda$add::class$ = nullptr;

$FieldInfo _SpinedBuffer_FieldInfo_[] = {
	{"curChunk", "[Ljava/lang/Object;", "[TE;", $PROTECTED, $field(SpinedBuffer, curChunk)},
	{"spine", "[[Ljava/lang/Object;", "[[TE;", $PROTECTED, $field(SpinedBuffer, spine)},
	{"SPLITERATOR_CHARACTERISTICS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SpinedBuffer, SPLITERATOR_CHARACTERISTICS)},
	{}
};

$MethodInfo _SpinedBuffer_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(I)V", nullptr, 0, $method(SpinedBuffer, init$, void, int32_t)},
	{"<init>", "()V", nullptr, 0, $method(SpinedBuffer, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", "(TE;)V", $PUBLIC, $virtualMethod(SpinedBuffer, accept, void, Object$*)},
	{"asArray", "(Ljava/util/function/IntFunction;)[Ljava/lang/Object;", "(Ljava/util/function/IntFunction<[TE;>;)[TE;", $PUBLIC, $virtualMethod(SpinedBuffer, asArray, $ObjectArray*, $IntFunction*)},
	{"capacity", "()J", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer, capacity, int64_t)},
	{"clear", "()V", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer, clear, void)},
	{"copyInto", "([Ljava/lang/Object;I)V", "([TE;I)V", $PUBLIC, $virtualMethod(SpinedBuffer, copyInto, void, $ObjectArray*, int32_t)},
	{"ensureCapacity", "(J)V", nullptr, $PROTECTED | $FINAL, $method(SpinedBuffer, ensureCapacity, void, int64_t)},
	{"forEach", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<-TE;>;)V", $PUBLIC, $virtualMethod(SpinedBuffer, forEach, void, $Consumer*)},
	{"get", "(J)Ljava/lang/Object;", "(J)TE;", $PUBLIC, $virtualMethod(SpinedBuffer, get, $Object*, int64_t)},
	{"increaseCapacity", "()V", nullptr, $PROTECTED, $virtualMethod(SpinedBuffer, increaseCapacity, void)},
	{"inflateSpine", "()V", nullptr, $PRIVATE, $method(SpinedBuffer, inflateSpine, void)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TE;>;", $PUBLIC, $virtualMethod(SpinedBuffer, iterator, $Iterator*)},
	{"spliterator", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TE;>;", $PUBLIC, $virtualMethod(SpinedBuffer, spliterator, $Spliterator*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SpinedBuffer, toString, $String*)},
	{}
};

$InnerClassInfo _SpinedBuffer_InnerClassesInfo_[] = {
	{"java.util.stream.SpinedBuffer$OfDouble", "java.util.stream.SpinedBuffer", "OfDouble", $STATIC},
	{"java.util.stream.SpinedBuffer$OfLong", "java.util.stream.SpinedBuffer", "OfLong", $STATIC},
	{"java.util.stream.SpinedBuffer$OfInt", "java.util.stream.SpinedBuffer", "OfInt", $STATIC},
	{"java.util.stream.SpinedBuffer$OfPrimitive", "java.util.stream.SpinedBuffer", "OfPrimitive", $STATIC | $ABSTRACT},
	{"java.util.stream.SpinedBuffer$1Splitr", nullptr, "Splitr", 0},
	{}
};

$ClassInfo _SpinedBuffer_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.stream.SpinedBuffer",
	"java.util.stream.AbstractSpinedBuffer",
	"java.util.function.Consumer,java.lang.Iterable",
	_SpinedBuffer_FieldInfo_,
	_SpinedBuffer_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/stream/AbstractSpinedBuffer;Ljava/util/function/Consumer<TE;>;Ljava/lang/Iterable<TE;>;",
	nullptr,
	_SpinedBuffer_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.SpinedBuffer$OfDouble,java.util.stream.SpinedBuffer$OfDouble$1Splitr,java.util.stream.SpinedBuffer$OfLong,java.util.stream.SpinedBuffer$OfLong$1Splitr,java.util.stream.SpinedBuffer$OfInt,java.util.stream.SpinedBuffer$OfInt$1Splitr,java.util.stream.SpinedBuffer$OfPrimitive,java.util.stream.SpinedBuffer$OfPrimitive$BaseSpliterator,java.util.stream.SpinedBuffer$1Splitr"
};

$Object* allocate$SpinedBuffer($Class* clazz) {
	return $of($alloc(SpinedBuffer));
}

int32_t SpinedBuffer::hashCode() {
	 return this->$AbstractSpinedBuffer::hashCode();
}

bool SpinedBuffer::equals(Object$* obj) {
	 return this->$AbstractSpinedBuffer::equals(obj);
}

$Object* SpinedBuffer::clone() {
	 return this->$AbstractSpinedBuffer::clone();
}

void SpinedBuffer::finalize() {
	this->$AbstractSpinedBuffer::finalize();
}

void SpinedBuffer::init$(int32_t initialCapacity) {
	$AbstractSpinedBuffer::init$(initialCapacity);
	$set(this, curChunk, $new($ObjectArray, $sl(1, this->initialChunkPower)));
}

void SpinedBuffer::init$() {
	$AbstractSpinedBuffer::init$();
	$set(this, curChunk, $new($ObjectArray, $sl(1, this->initialChunkPower)));
}

int64_t SpinedBuffer::capacity() {
	return (this->spineIndex == 0) ? (int64_t)$nc(this->curChunk)->length : $nc(this->priorElementCount)->get(this->spineIndex) + $nc($nc(this->spine)->get(this->spineIndex))->length;
}

void SpinedBuffer::inflateSpine() {
	if (this->spine == nullptr) {
		$set(this, spine, $new($ObjectArray2, $AbstractSpinedBuffer::MIN_SPINE_SIZE));
		$set(this, priorElementCount, $new($longs, $AbstractSpinedBuffer::MIN_SPINE_SIZE));
		$nc(this->spine)->set(0, this->curChunk);
	}
}

void SpinedBuffer::ensureCapacity(int64_t targetSize) {
	$useLocalCurrentObjectStackCache();
	int64_t capacity = this->capacity();
	if (targetSize > capacity) {
		inflateSpine();
		for (int32_t i = this->spineIndex + 1; targetSize > capacity; ++i) {
			if (i >= $nc(this->spine)->length) {
				int32_t newSpineSize = $nc(this->spine)->length * 2;
				$set(this, spine, $fcast($ObjectArray2, $Arrays::copyOf(this->spine, newSpineSize)));
				$set(this, priorElementCount, $Arrays::copyOf(this->priorElementCount, newSpineSize));
			}
			int32_t nextChunkSize = chunkSize(i);
			$nc(this->spine)->set(i, $$new($ObjectArray, nextChunkSize));
			$nc(this->priorElementCount)->set(i, $nc(this->priorElementCount)->get(i - 1) + $nc($nc(this->spine)->get(i - 1))->length);
			capacity += nextChunkSize;
		}
	}
}

void SpinedBuffer::increaseCapacity() {
	ensureCapacity(capacity() + 1);
}

$Object* SpinedBuffer::get(int64_t index) {
	$useLocalCurrentObjectStackCache();
	if (this->spineIndex == 0) {
		if (index < this->elementIndex) {
			return $of($nc(this->curChunk)->get((int32_t)index));
		} else {
			$throwNew($IndexOutOfBoundsException, $($Long::toString(index)));
		}
	}
	if (index >= count()) {
		$throwNew($IndexOutOfBoundsException, $($Long::toString(index)));
	}
	for (int32_t j = 0; j <= this->spineIndex; ++j) {
		if (index < $nc(this->priorElementCount)->get(j) + $nc($nc(this->spine)->get(j))->length) {
			return $of($nc($nc(this->spine)->get(j))->get((int32_t)(index - $nc(this->priorElementCount)->get(j))));
		}
	}
	$throwNew($IndexOutOfBoundsException, $($Long::toString(index)));
}

void SpinedBuffer::copyInto($ObjectArray* array, int32_t offset) {
	int64_t finalOffset = offset + count();
	if (finalOffset > $nc(array)->length || finalOffset < offset) {
		$throwNew($IndexOutOfBoundsException, "does not fit"_s);
	}
	if (this->spineIndex == 0) {
		$System::arraycopy(this->curChunk, 0, array, offset, this->elementIndex);
	} else {
		for (int32_t i = 0; i < this->spineIndex; ++i) {
			$System::arraycopy($nc(this->spine)->get(i), 0, array, offset, $nc($nc(this->spine)->get(i))->length);
			offset += $nc($nc(this->spine)->get(i))->length;
		}
		if (this->elementIndex > 0) {
			$System::arraycopy(this->curChunk, 0, array, offset, this->elementIndex);
		}
	}
}

$ObjectArray* SpinedBuffer::asArray($IntFunction* arrayFactory) {
	int64_t size = count();
	if (size >= $Nodes::MAX_ARRAY_SIZE) {
		$init($Nodes);
		$throwNew($IllegalArgumentException, $Nodes::BAD_SIZE);
	}
	$var($ObjectArray, result, $cast($ObjectArray, $nc(arrayFactory)->apply((int32_t)size)));
	copyInto(result, 0);
	return result;
}

void SpinedBuffer::clear() {
	if (this->spine != nullptr) {
		$set(this, curChunk, $nc(this->spine)->get(0));
		for (int32_t i = 0; i < $nc(this->curChunk)->length; ++i) {
			$nc(this->curChunk)->set(i, nullptr);
		}
		$set(this, spine, nullptr);
		$set(this, priorElementCount, nullptr);
	} else {
		for (int32_t i = 0; i < this->elementIndex; ++i) {
			$nc(this->curChunk)->set(i, nullptr);
		}
	}
	this->elementIndex = 0;
	this->spineIndex = 0;
}

$Iterator* SpinedBuffer::iterator() {
	return $Spliterators::iterator($(spliterator()));
}

void SpinedBuffer::forEach($Consumer* consumer) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < this->spineIndex; ++j) {
		{
			$var($ObjectArray, arr$, $nc(this->spine)->get(j));
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, t, arr$->get(i$));
				$nc(consumer)->accept(t);
			}
		}
	}
	for (int32_t i = 0; i < this->elementIndex; ++i) {
		$nc(consumer)->accept($nc(this->curChunk)->get(i));
	}
}

void SpinedBuffer::accept(Object$* e) {
	if (this->elementIndex == $nc(this->curChunk)->length) {
		inflateSpine();
		if (this->spineIndex + 1 >= $nc(this->spine)->length || $nc(this->spine)->get(this->spineIndex + 1) == nullptr) {
			increaseCapacity();
		}
		this->elementIndex = 0;
		++this->spineIndex;
		$set(this, curChunk, $nc(this->spine)->get(this->spineIndex));
	}
	$nc(this->curChunk)->set(this->elementIndex++, e);
}

$String* SpinedBuffer::toString() {
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList));
	forEach(static_cast<$Consumer*>($$new(SpinedBuffer$$Lambda$add, static_cast<$List*>(list))));
	return $str({"SpinedBuffer:"_s, $($of(list)->toString())});
}

$Spliterator* SpinedBuffer::spliterator() {
	{
	}
	return $new($SpinedBuffer$1Splitr, this, 0, this->spineIndex, 0, this->elementIndex);
}

SpinedBuffer::SpinedBuffer() {
}

$Class* SpinedBuffer::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SpinedBuffer$$Lambda$add::classInfo$.name)) {
			return SpinedBuffer$$Lambda$add::load$(name, initialize);
		}
	}
	$loadClass(SpinedBuffer, name, initialize, &_SpinedBuffer_ClassInfo_, allocate$SpinedBuffer);
	return class$;
}

$Class* SpinedBuffer::class$ = nullptr;

		} // stream
	} // util
} // java