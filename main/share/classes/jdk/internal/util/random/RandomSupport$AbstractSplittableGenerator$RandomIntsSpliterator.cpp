#include <jdk/internal/util/random/RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator.h>

#include <java/util/Objects.h>
#include <java/util/Spliterator$OfInt.h>
#include <java/util/function/IntConsumer.h>
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
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $IntConsumer = ::java::util::function::IntConsumer;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGenerator$SplittableGenerator = ::java::util::random::RandomGenerator$SplittableGenerator;
using $RandomSupport = ::jdk::internal::util::random::RandomSupport;
using $RandomSupport$RandomSpliterator = ::jdk::internal::util::random::RandomSupport$RandomSpliterator;

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

$FieldInfo _RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_FieldInfo_[] = {
	{"generatingGenerator", "Ljava/util/random/RandomGenerator$SplittableGenerator;", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, generatingGenerator)},
	{"origin", "I", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, origin)},
	{"bound", "I", nullptr, $FINAL, $field(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, bound)},
	{}
};

$MethodInfo _RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_MethodInfo_[] = {
	{"*characteristics", "()I", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*estimateSize", "()J", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/random/RandomGenerator$SplittableGenerator;JJII)V", nullptr, 0, $method(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, init$, void, $RandomGenerator$SplittableGenerator*, int64_t, int64_t, int32_t, int32_t)},
	{"forEachRemaining", "(Ljava/util/function/IntConsumer;)V", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, forEachRemaining, void, $IntConsumer*)},
	{"forEachRemaining", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, forEachRemaining, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, tryAdvance, bool, $IntConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, trySplit, $Spliterator$OfInt*)},
	{}
};

$InnerClassInfo _RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_InnerClassesInfo_[] = {
	{"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator", "jdk.internal.util.random.RandomSupport", "AbstractSplittableGenerator", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator", "jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator", "RandomIntsSpliterator", $STATIC},
	{"jdk.internal.util.random.RandomSupport$RandomSpliterator", "jdk.internal.util.random.RandomSupport", "RandomSpliterator", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.util.Spliterator$OfInt", "java.util.Spliterator", "OfInt", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator",
	"jdk.internal.util.random.RandomSupport$RandomSpliterator",
	"java.util.Spliterator$OfInt",
	_RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_FieldInfo_,
	_RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.util.random.RandomSupport"
};

$Object* allocate$RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator($Class* clazz) {
	return $of($alloc(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator));
}

int64_t RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::estimateSize() {
	 return this->$RandomSupport$RandomSpliterator::estimateSize();
}

int32_t RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::characteristics() {
	 return this->$RandomSupport$RandomSpliterator::characteristics();
}

int32_t RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::hashCode() {
	 return this->$RandomSupport$RandomSpliterator::hashCode();
}

bool RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::equals(Object$* obj) {
	 return this->$RandomSupport$RandomSpliterator::equals(obj);
}

$Object* RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::clone() {
	 return this->$RandomSupport$RandomSpliterator::clone();
}

$String* RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::toString() {
	 return this->$RandomSupport$RandomSpliterator::toString();
}

void RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::finalize() {
	this->$RandomSupport$RandomSpliterator::finalize();
}

void RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::init$($RandomGenerator$SplittableGenerator* generatingGenerator, int64_t index, int64_t fence, int32_t origin, int32_t bound) {
	$RandomSupport$RandomSpliterator::init$(index, fence);
	$set(this, generatingGenerator, generatingGenerator);
	this->origin = origin;
	this->bound = bound;
}

$Spliterator$OfInt* RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::trySplit() {
	int64_t i = this->index;
	int64_t m = (int64_t)((uint64_t)(i + this->fence) >> 1);
	if (m <= i) {
		return nullptr;
	}
	this->index = m;
	return $new(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, $($nc(this->generatingGenerator)->split()), i, m, this->origin, this->bound);
}

bool RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::tryAdvance($IntConsumer* consumer) {
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

void RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::forEachRemaining($IntConsumer* consumer) {
	$Objects::requireNonNull(consumer);
	int64_t i = this->index;
	int64_t f = this->fence;
	if (i < f) {
		this->index = f;
		$var($RandomGenerator, r, this->generatingGenerator);
		int32_t o = this->origin;
		int32_t b = this->bound;
		do {
			consumer->accept($RandomSupport::boundedNextInt(r, o, b));
		} while (++i < f);
	}
}

void RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::forEachRemaining(Object$* consumer) {
	this->forEachRemaining($cast($IntConsumer, consumer));
}

bool RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::tryAdvance(Object$* consumer) {
	return this->tryAdvance($cast($IntConsumer, consumer));
}

RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator() {
}

$Class* RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::load$($String* name, bool initialize) {
	$loadClass(RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator, name, initialize, &_RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator_ClassInfo_, allocate$RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator);
	return class$;
}

$Class* RandomSupport$AbstractSplittableGenerator$RandomIntsSpliterator::class$ = nullptr;

			} // random
		} // util
	} // internal
} // jdk