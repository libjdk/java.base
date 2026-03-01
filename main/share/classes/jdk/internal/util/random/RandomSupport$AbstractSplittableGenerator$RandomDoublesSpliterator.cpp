#include <jdk/internal/util/random/RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/function/DoubleConsumer.h>
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
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGenerator$SplittableGenerator = ::java::util::random::RandomGenerator$SplittableGenerator;
using $RandomSupport = ::jdk::internal::util::random::RandomSupport;
using $RandomSupport$RandomSpliterator = ::jdk::internal::util::random::RandomSupport$RandomSpliterator;

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

$FieldInfo _RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_FieldInfo_[] = {
	{"generatingGenerator", "Ljava/util/random/RandomGenerator$SplittableGenerator;", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, generatingGenerator)},
	{"origin", "D", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, origin)},
	{"bound", "D", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, bound)},
	{}
};

$MethodInfo _RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/random/RandomGenerator$SplittableGenerator;JJDD)V", nullptr, 0, $method(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, init$, void, $RandomGenerator$SplittableGenerator*, int64_t, int64_t, double, double)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, forEachRemaining, void, $DoubleConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, tryAdvance, bool, $DoubleConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, trySplit, $Spliterator$OfDouble*)},
	{}
};

$InnerClassInfo _RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_InnerClassesInfo_[] = {
	{"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator", "jdk.internal.util.random.RandomSupport", "AbstractSplittableGenerator", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator", "jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator", "RandomDoublesSpliterator", $STATIC},
	{"jdk.internal.util.random.RandomSupport$RandomSpliterator", "jdk.internal.util.random.RandomSupport", "RandomSpliterator", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator",
	"jdk.internal.util.random.RandomSupport$RandomSpliterator",
	"java.util.Spliterator$OfDouble",
	_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_FieldInfo_,
	_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.util.random.RandomSupport"
};

$Object* allocate$RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator($Class* clazz) {
	return $of($alloc(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator));
}

int64_t RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::estimateSize() {
	 return this->$RandomSupport$RandomSpliterator::estimateSize();
}

int32_t RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::characteristics() {
	 return this->$RandomSupport$RandomSpliterator::characteristics();
}

int32_t RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::hashCode() {
	 return this->$RandomSupport$RandomSpliterator::hashCode();
}

bool RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::equals(Object$* obj) {
	 return this->$RandomSupport$RandomSpliterator::equals(obj);
}

$Object* RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::clone() {
	 return this->$RandomSupport$RandomSpliterator::clone();
}

$String* RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::toString() {
	 return this->$RandomSupport$RandomSpliterator::toString();
}

void RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::finalize() {
	this->$RandomSupport$RandomSpliterator::finalize();
}

void RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::init$($RandomGenerator$SplittableGenerator* generatingGenerator, int64_t index, int64_t fence, double origin, double bound) {
	$RandomSupport$RandomSpliterator::init$(index, fence);
	$set(this, generatingGenerator, generatingGenerator);
	this->origin = origin;
	this->bound = bound;
}

$Spliterator$OfDouble* RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::trySplit() {
	int64_t i = this->index;
	int64_t m = (int64_t)((uint64_t)(i + this->fence) >> 1);
	if (m <= i) {
		return nullptr;
	}
	this->index = m;
	return $new(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, $($nc(this->generatingGenerator)->split()), i, m, this->origin, this->bound);
}

bool RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::tryAdvance($DoubleConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		consumer->accept($RandomSupport::boundedNextDouble(this->generatingGenerator, this->origin, this->bound));
		this->index = i + 1;
		return true;
	} else {
		return false;
	}
}

void RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::forEachRemaining($DoubleConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		this->index = f;
		$var($RandomGenerator, r, this->generatingGenerator);
		double o = this->origin;
		double b = this->bound;
		do {
			consumer->accept($RandomSupport::boundedNextDouble(r, o, b));
		} while (++i < f);
	}
}

void RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($DoubleConsumer, consumer));
}

bool RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($DoubleConsumer, consumer));
}

RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator() {
}

$Class* RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::load$($String* name, bool initialize) {
	$loadClass(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, name, initialize, &_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_ClassInfo_, allocate$RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator);
	return class$;
}

$Class* RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator::class$ = nullptr;

			} // random
		} // util
	} // internal
} // jdk