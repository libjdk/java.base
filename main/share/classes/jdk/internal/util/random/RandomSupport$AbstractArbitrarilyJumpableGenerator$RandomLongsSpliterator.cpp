#include <jdk/internal/util/random/RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfLong.h>
#include <java/util/function/LongConsumer.h>
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
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $LongConsumer = ::java::util::function::LongConsumer;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGenerator$ArbitrarilyJumpableGenerator = ::java::util::random::RandomGenerator$ArbitrarilyJumpableGenerator;
using $RandomSupport = ::jdk::internal::util::random::RandomSupport;
using $RandomSupport$RandomSpliterator = ::jdk::internal::util::random::RandomSupport$RandomSpliterator;

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

$FieldInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_FieldInfo_[] = {
	{"generatingGenerator", "Ljava/util/random/RandomGenerator$ArbitrarilyJumpableGenerator;", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, generatingGenerator)},
	{"origin", "J", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, origin)},
	{"bound", "J", nullptr, $FINAL, $field(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, bound)},
	{}
};

$MethodInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/random/RandomGenerator$ArbitrarilyJumpableGenerator;JJJJ)V", nullptr, 0, $method(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, init$, void, $RandomGenerator$ArbitrarilyJumpableGenerator*, int64_t, int64_t, int64_t, int64_t)},
	{"forEachRemaining", "(Ljava/util/function/LongConsumer;)V", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, forEachRemaining, void, $LongConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, tryAdvance, bool, $LongConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, trySplit, $Spliterator$OfLong*)},
	{}
};

$InnerClassInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_InnerClassesInfo_[] = {
	{"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator", "jdk.internal.util.random.RandomSupport", "AbstractArbitrarilyJumpableGenerator", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator", "jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator", "RandomLongsSpliterator", $STATIC},
	{"jdk.internal.util.random.RandomSupport$RandomSpliterator", "jdk.internal.util.random.RandomSupport", "RandomSpliterator", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfLong", "java.util.Spliterator", "OfLong", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.util.random.RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator",
	"jdk.internal.util.random.RandomSupport$RandomSpliterator",
	"java.util.Spliterator$OfLong",
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_FieldInfo_,
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.util.random.RandomSupport"
};

$Object* allocate$RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator($Class* clazz) {
	return $of($alloc(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator));
}

int64_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::estimateSize() {
	 return this->$RandomSupport$RandomSpliterator::estimateSize();
}

int32_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::characteristics() {
	 return this->$RandomSupport$RandomSpliterator::characteristics();
}

int32_t RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::hashCode() {
	 return this->$RandomSupport$RandomSpliterator::hashCode();
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::equals(Object$* obj) {
	 return this->$RandomSupport$RandomSpliterator::equals(obj);
}

$Object* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::clone() {
	 return this->$RandomSupport$RandomSpliterator::clone();
}

$String* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::toString() {
	 return this->$RandomSupport$RandomSpliterator::toString();
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::finalize() {
	this->$RandomSupport$RandomSpliterator::finalize();
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::init$($RandomGenerator$ArbitrarilyJumpableGenerator* generatingGenerator, int64_t index, int64_t fence, int64_t origin, int64_t bound) {
	$RandomSupport$RandomSpliterator::init$(index, fence);
	$set(this, generatingGenerator, generatingGenerator);
	this->origin = origin;
	this->bound = bound;
}

$Spliterator$OfLong* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::trySplit() {
	$useLocalCurrentObjectStackCache();
	int64_t i = this->index;
	int64_t delta = $Long::highestOneBit((this->fence - i) - 1);
	int64_t m = i + delta;
	if (m <= i) {
		return nullptr;
	}
	this->index = m;
	$var($RandomGenerator$ArbitrarilyJumpableGenerator, r, this->generatingGenerator);
	return $new(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, $($nc(r)->copyAndJump((double)delta)), i, m, this->origin, this->bound);
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::tryAdvance($LongConsumer* consumer) {
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

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::forEachRemaining($LongConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		this->index = f;
		$var($RandomGenerator$ArbitrarilyJumpableGenerator, r, this->generatingGenerator);
		int64_t o = this->origin;
		int64_t b = this->bound;
		do {
			consumer->accept($RandomSupport::boundedNextLong(r, o, b));
		} while (++i < f);
	}
}

void RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($LongConsumer, consumer));
}

bool RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($LongConsumer, consumer));
}

RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator() {
}

$Class* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::load$($String* name, bool initialize) {
	$loadClass(RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator, name, initialize, &_RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator_ClassInfo_, allocate$RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator);
	return class$;
}

$Class* RandomSupport$AbstractArbitrarilyJumpableGenerator$RandomLongsSpliterator::class$ = nullptr;

			} // random
		} // util
	} // internal
} // jdk