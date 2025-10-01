#ifndef _jdk_internal_util_random_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_h_
#define _jdk_internal_util_random_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_h_
//$ class jdk.internal.util.random.RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator
//$ extends jdk.internal.util.random.RandomSupport$RandomSpliterator
//$ implements java.util.Spliterator$OfDouble

#include <java/util/Spliterator$OfDouble.h>
#include <jdk/internal/util/random/RandomSupport$RandomSpliterator.h>

namespace java {
	namespace util {
		namespace function {
			class DoubleConsumer;
		}
	}
}
namespace java {
	namespace util {
		namespace random {
			class RandomGenerator$SplittableGenerator;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

class $import RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator : public ::jdk::internal::util::random::RandomSupport$RandomSpliterator, public ::java::util::Spliterator$OfDouble {
	$class(RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator, $NO_CLASS_INIT, ::jdk::internal::util::random::RandomSupport$RandomSpliterator, ::java::util::Spliterator$OfDouble)
public:
	RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	using ::java::util::Spliterator$OfDouble::forEachRemaining;
	virtual int32_t characteristics() override;
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual int64_t estimateSize() override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::util::random::RandomGenerator$SplittableGenerator* generatingGenerator, int64_t index, int64_t fence, double origin, double bound);
	virtual void forEachRemaining(::java::util::function::DoubleConsumer* consumer) override;
	virtual void forEachRemaining(Object$* consumer) override;
	using ::java::util::Spliterator$OfDouble::tryAdvance;
	virtual $String* toString() override;
	virtual bool tryAdvance(::java::util::function::DoubleConsumer* consumer) override;
	virtual bool tryAdvance(Object$* consumer) override;
	virtual ::java::util::Spliterator$OfDouble* trySplit() override;
	::java::util::random::RandomGenerator$SplittableGenerator* generatingGenerator = nullptr;
	double origin = 0.0;
	double bound = 0.0;
};

			} // random
		} // util
	} // internal
} // jdk

#endif // _jdk_internal_util_random_RandomSupport$AbstractSplittableGenerator$RandomDoublesSpliterator_h_