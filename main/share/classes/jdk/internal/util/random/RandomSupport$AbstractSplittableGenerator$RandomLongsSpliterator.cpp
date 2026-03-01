#include <jdk/internal/util/random/RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/random/RandomGenerator$SplittableGenerator.h>
#include <java/util/random/RandomGenerator.h>
#include <jdk/internal/util/random/RandomSupport$AbstractSplittableGenerator.h>
#include <jdk/internal/util/random/RandomSupport$RandomSpliterator.h>
#include <jdk/internal/util/random/RandomSupport.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $LongConsumer = ::java::util::function::LongConsumer;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGenerator$SplittableGenerator = ::java::util::random::RandomGenerator$SplittableGenerator;
using $RandomSupport = ::jdk::internal::util::random::RandomSupport;
using $RandomSupport$RandomSpliterator = ::jdk::internal::util::random::RandomSupport$RandomSpliterator;

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

$FieldInfo _RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_FieldInfo_[] = {
	{"generatingGenerator", "Ljava/util/random/RandomGenerator$SplittableGenerator;", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, generatingGenerator)},
	{"origin", "J", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, origin)},
	{"bound", "J", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, bound)},
	{}
};

$MethodInfo _RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/random/RandomGenerator$SplittableGenerator;JJJJ)V", nullptr, 0, $method(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, init$, void, $RandomGenerator$SplittableGenerator*, int64_t, int64_t, int64_t, int64_t)},
	{"forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, forEachRemaining, void, $LongConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, tryAdvance, bool, $LongConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, trySplit, $Spliterator$OfLong*)},
	{}
};

$InnerClassInfo _RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_InnerClassesInfo_[] = {
	{"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator", "jdk.internal.util.random.RandomSupport", "AbstractSplittableGenerator", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator", "jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator", "RandomLongsSpliterator", $STATIC},
	{"jdk.internal.util.random.RandomSupport$RandomSpliterator", "jdk.internal.util.random.RandomSupport", "RandomSpliterator", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator",
	"jdk.internal.util.random.RandomSupport$RandomSpliterator",
	"java.util.Spliterator$OfLong",
	_RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_FieldInfo_,
	_RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.util.random.RandomSupport"
};

$Object* allocate$RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator($Class* clazz) {
	return $of($alloc(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator));
}

int64_t RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::estimateSize() {
	 return this->$RandomSupport$RandomSpliterator::estimateSize();
}

int32_t RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::characteristics() {
	 return this->$RandomSupport$RandomSpliterator::characteristics();
}

int32_t RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::hashCode() {
	 return this->$RandomSupport$RandomSpliterator::hashCode();
}

bool RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::equals(Object$* obj) {
	 return this->$RandomSupport$RandomSpliterator::equals(obj);
}

$Object* RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::clone() {
	 return this->$RandomSupport$RandomSpliterator::clone();
}

$String* RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::toString() {
	 return this->$RandomSupport$RandomSpliterator::toString();
}

void RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::finalize() {
	this->$RandomSupport$RandomSpliterator::finalize();
}

void RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::init$($RandomGenerator$SplittableGenerator* generatingGenerator, int64_t index, int64_t fence, int64_t origin, int64_t bound) {
	$RandomSupport$RandomSpliterator::init$(index, fence);
	$set(this, generatingGenerator, generatingGenerator);
	this->origin = origin;
	this->bound = bound;
}

$Spliterator$OfLong* RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::trySplit() {
	int64_t i = this->index;
	int64_t m = (int64_t)((uint64_t)(i + this->fence) >> 1);
	if (m <= i) {
		return nullptr;
	}
	this->index = m;
	return $new(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, $($nc(this->generatingGenerator)->split()), i, m, this->origin, this->bound);
}

bool RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::tryAdvance($LongConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		consumer->accept($RandomSupport::boundedNextLong(this->generatingGenerator, this->origin, this->bound));
		this->index = i + 1;
		return true;
	} else {
		return false;
	}
}

void RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::forEachRemaining($LongConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		this->index = f;
		$var($RandomGenerator, r, this->generatingGenerator);
		int64_t o = this->origin;
		int64_t b = this->bound;
		do {
			consumer->accept($RandomSupport::boundedNextLong(r, o, b));
		} while (++i < f);
	}
}

void RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($LongConsumer, consumer));
}

bool RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($LongConsumer, consumer));
}

RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator() {
}

$Class* RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::load$($String* name, bool initialize) {
	$loadClass(RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator, name, initialize, &_RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator_ClassInfo_, allocate$RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator);
	return class$;
}

$Class* RandomSupport$AbstractSplittableGenerator$RandomLongsSpliterator::class$ = nullptr;

			} // random
		} // util
	} // internal
} // jdk