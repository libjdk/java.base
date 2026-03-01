#include <java/util/random/RandomGenerator$SplittableGenerator.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Objects.h>
#include <java/util/function/Function.h>
#include <java/util/random/RandomGenerator.h>
#include <java/util/random/RandomGeneratorFactory.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Objects = ::java::util::Objects;
using $Function = ::java::util::function::Function;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGeneratorFactory = ::java::util::random::RandomGeneratorFactory;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {
		namespace random {

class RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0 : public $Function {
	$class(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* x) override {
		 return $of(RandomGenerator$SplittableGenerator::lambda$rngs$0($cast(RandomGenerator$SplittableGenerator, x)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.random.RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0::load$($String* name, bool initialize) {
	$loadClass(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0::class$ = nullptr;

$MethodInfo _RandomGenerator$SplittableGenerator_MethodInfo_[] = {
	{"lambda$rngs$0", "(Ljava/util/random/RandomGenerator$SplittableGenerator;)Ljava/util/random/RandomGenerator;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(RandomGenerator$SplittableGenerator, lambda$rngs$0, $RandomGenerator*, RandomGenerator$SplittableGenerator*)},
	{"of", "(Ljava/lang/String;)Ljava/util/random/RandomGenerator$SplittableGenerator;", nullptr, $PUBLIC | $STATIC, $staticMethod(RandomGenerator$SplittableGenerator, of, RandomGenerator$SplittableGenerator*, $String*)},
	{"rngs", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$SplittableGenerator, rngs, $Stream*)},
	{"rngs", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$SplittableGenerator, rngs, $Stream*, int64_t)},
	{"split", "()Ljava/util/random/RandomGenerator$SplittableGenerator;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$SplittableGenerator, split, RandomGenerator$SplittableGenerator*)},
	{"split", "(Ljava/util/random/RandomGenerator$SplittableGenerator;)Ljava/util/random/RandomGenerator$SplittableGenerator;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$SplittableGenerator, split, RandomGenerator$SplittableGenerator*, RandomGenerator$SplittableGenerator*)},
	{"splits", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator$SplittableGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$SplittableGenerator, splits, $Stream*)},
	{"splits", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator$SplittableGenerator;>;", $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$SplittableGenerator, splits, $Stream*, int64_t)},
	{"splits", "(Ljava/util/random/RandomGenerator$SplittableGenerator;)Ljava/util/stream/Stream;", "(Ljava/util/random/RandomGenerator$SplittableGenerator;)Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator$SplittableGenerator;>;", $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$SplittableGenerator, splits, $Stream*, RandomGenerator$SplittableGenerator*)},
	{"splits", "(JLjava/util/random/RandomGenerator$SplittableGenerator;)Ljava/util/stream/Stream;", "(JLjava/util/random/RandomGenerator$SplittableGenerator;)Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator$SplittableGenerator;>;", $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$SplittableGenerator, splits, $Stream*, int64_t, RandomGenerator$SplittableGenerator*)},
	{}
};

$InnerClassInfo _RandomGenerator$SplittableGenerator_InnerClassesInfo_[] = {
	{"java.util.random.RandomGenerator$SplittableGenerator", "java.util.random.RandomGenerator", "SplittableGenerator", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.random.RandomGenerator$StreamableGenerator", "java.util.random.RandomGenerator", "StreamableGenerator", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomGenerator$SplittableGenerator_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.random.RandomGenerator$SplittableGenerator",
	nullptr,
	"java.util.random.RandomGenerator$StreamableGenerator",
	nullptr,
	_RandomGenerator$SplittableGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomGenerator$SplittableGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.random.RandomGenerator"
};

$Object* allocate$RandomGenerator$SplittableGenerator($Class* clazz) {
	return $of($alloc(RandomGenerator$SplittableGenerator));
}

RandomGenerator$SplittableGenerator* RandomGenerator$SplittableGenerator::of($String* name) {
	$init(RandomGenerator$SplittableGenerator);
	$Objects::requireNonNull(name);
	return $cast(RandomGenerator$SplittableGenerator, $RandomGeneratorFactory::of(name, RandomGenerator$SplittableGenerator::class$));
}

$Stream* RandomGenerator$SplittableGenerator::splits() {
	return this->splits(this);
}

$Stream* RandomGenerator$SplittableGenerator::rngs() {
	$useLocalCurrentObjectStackCache();
	return $nc($(this->splits()))->map(static_cast<$Function*>($$new(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0)));
}

$Stream* RandomGenerator$SplittableGenerator::rngs(int64_t streamSize) {
	$useLocalCurrentObjectStackCache();
	return $nc($(this->splits(streamSize)))->map(static_cast<$Function*>($$new(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0)));
}

$RandomGenerator* RandomGenerator$SplittableGenerator::lambda$rngs$0(RandomGenerator$SplittableGenerator* x) {
	$init(RandomGenerator$SplittableGenerator);
	return x;
}

$Class* RandomGenerator$SplittableGenerator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0::classInfo$.name)) {
			return RandomGenerator$SplittableGenerator$$Lambda$lambda$rngs$0::load$(name, initialize);
		}
	}
	$loadClass(RandomGenerator$SplittableGenerator, name, initialize, &_RandomGenerator$SplittableGenerator_ClassInfo_, allocate$RandomGenerator$SplittableGenerator);
	return class$;
}

$Class* RandomGenerator$SplittableGenerator::class$ = nullptr;

		} // random
	} // util
} // java