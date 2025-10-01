#ifndef _jdk_internal_util_random_RandomSupport$RandomLongsSpliterator_h_
#define _jdk_internal_util_random_RandomSupport$RandomLongsSpliterator_h_
//$ class jdk.internal.util.random.RandomSupport$RandomLongsSpliterator
//$ extends jdk.internal.util.random.RandomSupport$RandomSpliterator
//$ implements java.util.Spliterator$OfLong

#include <java/util/Spliterator$OfLong.h>
#include <jdk/internal/util/random/RandomSupport$RandomSpliterator.h>

namespace java {
	namespace util {
		namespace function {
			class LongConsumer;
		}
	}
}
namespace java {
	namespace util {
		namespace random {
			class RandomGenerator;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace util {
			namespace random {

class $export RandomSupport$RandomLongsSpliterator : public ::jdk::internal::util::random::RandomSupport$RandomSpliterator, public ::java::util::Spliterator$OfLong {
	$class(RandomSupport$RandomLongsSpliterator, $NO_CLASS_INIT, ::jdk::internal::util::random::RandomSupport$RandomSpliterator, ::java::util::Spliterator$OfLong)
public:
	RandomSupport$RandomLongsSpliterator();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	using ::java::util::Spliterator$OfLong::forEachRemaining;
	virtual int32_t characteristics() override;
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual int64_t estimateSize() override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::util::random::RandomGenerator* generatingGenerator, int64_t index, int64_t fence, int64_t origin, int64_t bound);
	virtual void forEachRemaining(::java::util::function::LongConsumer* consumer) override;
	virtual void forEachRemaining(Object$* consumer) override;
	using ::java::util::Spliterator$OfLong::tryAdvance;
	virtual $String* toString() override;
	virtual bool tryAdvance(::java::util::function::LongConsumer* consumer) override;
	virtual bool tryAdvance(Object$* consumer) override;
	virtual ::java::util::Spliterator$OfLong* trySplit() override;
	::java::util::random::RandomGenerator* generatingGenerator = nullptr;
	int64_t origin = 0;
	int64_t bound = 0;
};

			} // random
		} // util
	} // internal
} // jdk

#endif // _jdk_internal_util_random_RandomSupport$RandomLongsSpliterator_h_