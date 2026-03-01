#include <jdk/internal/util/random/RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfDouble.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/random/RandomGenerator$ArbitrarilyJumpableGenerator.h>
#include <java/util/random/RandomGenerator.h>
#include <jdk/internal/util/random/RandomSupport$AbstractArbitrarilyJumpableGenerator.h>
#include <jdk/internal/util/random/RandomSupport$RandomSpliterator.h>
#include <jdk/internal/util/random/RandomSupport.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGenerator$ArbitrarilyJumpableGenerator = ::java::util::random::RandomGenerator$ArbitrarilyJumpableGenerator;
using $RandomSupport = ::jdk::internal::util::random::RandomSupport;
using $RandomSupport$RandomSpliterator = ::jdk::internal::util::random::RandomSupport$RandomSpliterator;

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

$FieldInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_FieldInfo_[] = {
	{"generatingGenerator", "Ljava/util/random/RandomGenerator$ArbitrarilyJumpableGenerator;", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, generatingGenerator)},
	{"origin", "D", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, origin)},
	{"bound", "D", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, bound)},
	{}
};

$MethodInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/random/RandomGenerator$ArbitrarilyJumpableGenerator;JJDD)V", nullptr, 0, $method(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, init$, void, $RandomGenerator$ArbitrarilyJumpableGenerator*, int64_t, int64_t, double, double)},
	{"forEachRemaining", "(Ljava/util/function/DoubleConsumer;)V", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, forEachRemaining, void, $DoubleConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, tryAdvance, bool, $DoubleConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, trySplit, $Spliterator$OfDouble*)},
	{}
};

$InnerClassInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_InnerClassesInfo_[] = {
	{"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator", "jdk.internal.util.random.RandomSupport", "AbstractArbitrarilyJumpableGenerator", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator", "jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator", "RandomDoublesSpliterator", $STATIC},
	{"jdk.internal.util.random.RandomSupport$RandomSpliterator", "jdk.internal.util.random.RandomSupport", "RandomSpliterator", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfDouble", "java.util.Spliterator", "OfDouble", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator",
	"jdk.internal.util.random.RandomSupport$RandomSpliterator",
	"java.util.Spliterator$OfDouble",
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_FieldInfo_,
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.util.random.RandomSupport"
};

$Object* allocate$RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator($Class* clazz) {
	return $of($alloc(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator));
}

int64_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::estimateSize() {
	 return this->$RandomSupport$RandomSpliterator::estimateSize();
}

int32_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::characteristics() {
	 return this->$RandomSupport$RandomSpliterator::characteristics();
}

int32_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::hashCode() {
	 return this->$RandomSupport$RandomSpliterator::hashCode();
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::equals(Object$* obj) {
	 return this->$RandomSupport$RandomSpliterator::equals(obj);
}

$Object* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::clone() {
	 return this->$RandomSupport$RandomSpliterator::clone();
}

$String* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::toString() {
	 return this->$RandomSupport$RandomSpliterator::toString();
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::finalize() {
	this->$RandomSupport$RandomSpliterator::finalize();
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::init$($RandomGenerator$ArbitrarilyJumpableGenerator* generatingGenerator, int64_t index, int64_t fence, double origin, double bound) {
	$RandomSupport$RandomSpliterator::init$(index, fence);
	$set(this, generatingGenerator, generatingGenerator);
	this->origin = origin;
	this->bound = bound;
}

$Spliterator$OfDouble* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::trySplit() {
	$useLocalCurrentObjectStackCache();
	int64_t i = this->index;
	int64_t delta = $Long::highestOneBit((this->fence - i) - 1);
	int64_t m = i + delta;
	if (m <= i) {
		return nullptr;
	}
	this->index = m;
	$var($RandomGenerator$ArbitrarilyJumpableGenerator, r, this->generatingGenerator);
	return $new(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, $($nc(r)->copyAndJump((double)delta)), i, m, this->origin, this->bound);
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::tryAdvance($DoubleConsumer* consumer) {
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

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::forEachRemaining($DoubleConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		this->index = f;
		$var($RandomGenerator$ArbitrarilyJumpableGenerator, r, this->generatingGenerator);
		double o = this->origin;
		double b = this->bound;
		do {
			consumer->accept($RandomSupport::boundedNextDouble(r, o, b));
		} while (++i < f);
	}
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($DoubleConsumer, consumer));
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($DoubleConsumer, consumer));
}

RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator() {
}

$Class* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::load$($String* name, bool initialize) {
	$loadClass(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator, name, initialize, &_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator_ClassInfo_, allocate$RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator);
	return class$;
}

$Class* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomDoublesSpliterator::class$ = nullptr;

			} // random
		} // util
	} // internal
} // jdk