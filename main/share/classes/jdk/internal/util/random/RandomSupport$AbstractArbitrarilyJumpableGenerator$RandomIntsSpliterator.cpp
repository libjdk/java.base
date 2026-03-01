#include <jdk/internal/util/random/RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/function/IntConsumer.h>
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
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $IntConsumer = ::java::util::function::IntConsumer;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGenerator$ArbitrarilyJumpableGenerator = ::java::util::random::RandomGenerator$ArbitrarilyJumpableGenerator;
using $RandomSupport = ::jdk::internal::util::random::RandomSupport;
using $RandomSupport$RandomSpliterator = ::jdk::internal::util::random::RandomSupport$RandomSpliterator;

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

$FieldInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_FieldInfo_[] = {
	{"generatingGenerator", "Ljava/util/random/RandomGenerator$ArbitrarilyJumpableGenerator;", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, generatingGenerator)},
	{"origin", "I", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, origin)},
	{"bound", "I", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, bound)},
	{}
};

$MethodInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/random/RandomGenerator$ArbitrarilyJumpableGenerator;JJII)V", nullptr, 0, $method(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, init$, void, $RandomGenerator$ArbitrarilyJumpableGenerator*, int64_t, int64_t, int32_t, int32_t)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, forEachRemaining, void, $IntConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, tryAdvance, bool, $IntConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, trySplit, $Spliterator$OfInt*)},
	{}
};

$InnerClassInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_InnerClassesInfo_[] = {
	{"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator", "jdk.internal.util.random.RandomSupport", "AbstractArbitrarilyJumpableGenerator", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator", "jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator", "RandomIntsSpliterator", $STATIC},
	{"jdk.internal.util.random.RandomSupport$RandomSpliterator", "jdk.internal.util.random.RandomSupport", "RandomSpliterator", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator",
	"jdk.internal.util.random.RandomSupport$RandomSpliterator",
	"java.util.Spliterator$OfInt",
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_FieldInfo_,
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.util.random.RandomSupport"
};

$Object* allocate$RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator($Class* clazz) {
	return $of($alloc(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator));
}

int64_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::estimateSize() {
	 return this->$RandomSupport$RandomSpliterator::estimateSize();
}

int32_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::characteristics() {
	 return this->$RandomSupport$RandomSpliterator::characteristics();
}

int32_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::hashCode() {
	 return this->$RandomSupport$RandomSpliterator::hashCode();
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::equals(Object$* obj) {
	 return this->$RandomSupport$RandomSpliterator::equals(obj);
}

$Object* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::clone() {
	 return this->$RandomSupport$RandomSpliterator::clone();
}

$String* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::toString() {
	 return this->$RandomSupport$RandomSpliterator::toString();
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::finalize() {
	this->$RandomSupport$RandomSpliterator::finalize();
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::init$($RandomGenerator$ArbitrarilyJumpableGenerator* generatingGenerator, int64_t index, int64_t fence, int32_t origin, int32_t bound) {
	$RandomSupport$RandomSpliterator::init$(index, fence);
	this->origin = origin;
	this->bound = bound;
	$set(this, generatingGenerator, generatingGenerator);
}

$Spliterator$OfInt* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::trySplit() {
	$useLocalCurrentObjectStackCache();
	int64_t i = this->index;
	int64_t delta = $Long::highestOneBit((this->fence - i) - 1);
	int64_t m = i + delta;
	if (m <= i) {
		return nullptr;
	}
	this->index = m;
	$var($RandomGenerator$ArbitrarilyJumpableGenerator, r, this->generatingGenerator);
	return $new(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, $($nc(r)->copyAndJump((double)delta)), i, m, this->origin, this->bound);
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::tryAdvance($IntConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		consumer->accept($RandomSupport::boundedNextInt(this->generatingGenerator, this->origin, this->bound));
		this->index = i + 1;
		return true;
	} else {
		return false;
	}
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::forEachRemaining($IntConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		this->index = f;
		$var($RandomGenerator$ArbitrarilyJumpableGenerator, r, this->generatingGenerator);
		int32_t o = this->origin;
		int32_t b = this->bound;
		do {
			consumer->accept($RandomSupport::boundedNextInt(r, o, b));
		} while (++i < f);
	}
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($IntConsumer, consumer));
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($IntConsumer, consumer));
}

RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator() {
}

$Class* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::load$($String* name, bool initialize) {
	$loadClass(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator, name, initialize, &_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator_ClassInfo_, allocate$RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator);
	return class$;
}

$Class* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomIntsSpliterator::class$ = nullptr;

			} // random
		} // util
	} // internal
} // jdk