#include <java/util/random/RandomGenerator$JumpableGenerator.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Objects.h>
#include <java/util/function/Supplier.h>
#include <java/util/random/RandomGenerator.h>
#include <java/util/random/RandomGeneratorFactory.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Objects = ::java::util::Objects;
using $Supplier = ::java::util::function::Supplier;
using $RandomGenerator = ::java::util::random::RandomGenerator;
using $RandomGeneratorFactory = ::java::util::random::RandomGeneratorFactory;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {
		namespace random {

class RandomGenerator$JumpableGenerator$$Lambda$copyAndJump : public $Supplier {
	$class(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump, $NO_CLASS_INIT, $Supplier)
public:
	void init$(RandomGenerator$JumpableGenerator* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->copyAndJump());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RandomGenerator$JumpableGenerator$$Lambda$copyAndJump>());
	}
	RandomGenerator$JumpableGenerator* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump, inst$)},
	{}
};
$MethodInfo RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::methodInfos[3] = {
	{"<init>", "(Ljava/util/random/RandomGenerator$JumpableGenerator;)V", nullptr, $PUBLIC, $method(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump, init$, void, RandomGenerator$JumpableGenerator*)},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump, get, $Object*)},
	{}
};
$ClassInfo RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.random.RandomGenerator$JumpableGenerator$$Lambda$copyAndJump",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::load$($String* name, bool initialize) {
	$loadClass(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::class$ = nullptr;

$MethodInfo _RandomGenerator$JumpableGenerator_MethodInfo_[] = {
	{"copy", "()Ljava/util/random/RandomGenerator$JumpableGenerator;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$JumpableGenerator, copy, RandomGenerator$JumpableGenerator*)},
	{"copyAndJump", "()Ljava/util/random/RandomGenerator;", nullptr, $PUBLIC, $virtualMethod(RandomGenerator$JumpableGenerator, copyAndJump, $RandomGenerator*)},
	{"jump", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$JumpableGenerator, jump, void)},
	{"jumpDistance", "()D", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(RandomGenerator$JumpableGenerator, jumpDistance, double)},
	{"jumps", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$JumpableGenerator, jumps, $Stream*)},
	{"jumps", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$JumpableGenerator, jumps, $Stream*, int64_t)},
	{"of", "(Ljava/lang/String;)Ljava/util/random/RandomGenerator$JumpableGenerator;", nullptr, $PUBLIC | $STATIC, $staticMethod(RandomGenerator$JumpableGenerator, of, RandomGenerator$JumpableGenerator*, $String*)},
	{"rngs", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$JumpableGenerator, rngs, $Stream*)},
	{"rngs", "(J)Ljava/util/stream/Stream;", "(J)Ljava/util/stream/Stream<Ljava/util/random/RandomGenerator;>;", $PUBLIC, $virtualMethod(RandomGenerator$JumpableGenerator, rngs, $Stream*, int64_t)},
	{}
};

$InnerClassInfo _RandomGenerator$JumpableGenerator_InnerClassesInfo_[] = {
	{"java.util.random.RandomGenerator$JumpableGenerator", "java.util.random.RandomGenerator", "JumpableGenerator", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.random.RandomGenerator$StreamableGenerator", "java.util.random.RandomGenerator", "StreamableGenerator", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RandomGenerator$JumpableGenerator_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.random.RandomGenerator$JumpableGenerator",
	nullptr,
	"java.util.random.RandomGenerator$StreamableGenerator",
	nullptr,
	_RandomGenerator$JumpableGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_RandomGenerator$JumpableGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.random.RandomGenerator"
};

$Object* allocate$RandomGenerator$JumpableGenerator($Class* clazz) {
	return $of($alloc(RandomGenerator$JumpableGenerator));
}

RandomGenerator$JumpableGenerator* RandomGenerator$JumpableGenerator::of($String* name) {
	$init(RandomGenerator$JumpableGenerator);
	$Objects::requireNonNull(name);
	return $cast(RandomGenerator$JumpableGenerator, $RandomGeneratorFactory::of(name, RandomGenerator$JumpableGenerator::class$));
}

$Stream* RandomGenerator$JumpableGenerator::jumps() {
	$useLocalCurrentObjectStackCache();
	return $cast($Stream, $nc($($Stream::generate(static_cast<$Supplier*>($$new(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump, this)))))->sequential());
}

$Stream* RandomGenerator$JumpableGenerator::jumps(int64_t streamSize) {
	return $nc($(jumps()))->limit(streamSize);
}

$Stream* RandomGenerator$JumpableGenerator::rngs() {
	return this->jumps();
}

$Stream* RandomGenerator$JumpableGenerator::rngs(int64_t streamSize) {
	return this->jumps(streamSize);
}

$RandomGenerator* RandomGenerator$JumpableGenerator::copyAndJump() {
	$var($RandomGenerator, result, copy());
	jump();
	return result;
}

$Class* RandomGenerator$JumpableGenerator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::classInfo$.name)) {
			return RandomGenerator$JumpableGenerator$$Lambda$copyAndJump::load$(name, initialize);
		}
	}
	$loadClass(RandomGenerator$JumpableGenerator, name, initialize, &_RandomGenerator$JumpableGenerator_ClassInfo_, allocate$RandomGenerator$JumpableGenerator);
	return class$;
}

$Class* RandomGenerator$JumpableGenerator::class$ = nullptr;

		} // random
	} // util
} // java