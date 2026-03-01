#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt$Dropping.h>

#include <java/util/Spliterator$OfInt.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/IntConsumer.h>
#include <java/util/function/IntPredicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfInt = ::java::util::Spliterator$OfInt;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $IntConsumer = ::java::util::function::IntConsumer;
using $IntPredicate = ::java::util::function::IntPredicate;
using $WhileOps$UnorderedWhileSpliterator$OfInt = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfInt;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfInt$Dropping_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator$OfInt;ZLjava/util/function/IntPredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, init$, void, $Spliterator$OfInt*, bool, $IntPredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfInt;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, init$, void, $Spliterator$OfInt*, $WhileOps$UnorderedWhileSpliterator$OfInt*)},
	{"makeSpliterator", "(Ljava/util/Spliterator$OfInt;)Ljava/util/Spliterator$OfInt;", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, makeSpliterator, $Spliterator$OfInt*, $Spliterator$OfInt*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", nullptr, $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, tryAdvance, bool, $IntConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfInt$Dropping_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfInt", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Dropping", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "Dropping", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfInt$Dropping_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Dropping",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfInt$Dropping_MethodInfo_,
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfInt$Dropping_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfInt$Dropping($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping));
}

void WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::init$($Spliterator$OfInt* s, bool noSplitting, $IntPredicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfInt::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::init$($Spliterator$OfInt* s, $WhileOps$UnorderedWhileSpliterator$OfInt* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfInt::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::tryAdvance($IntConsumer* action) {
	if (this->takeOrDrop) {
		this->takeOrDrop = false;
		bool adv = false;
		bool dropped = false;
		while (true) {
			bool var$1 = (adv = $nc(($cast($Spliterator$OfInt, this->s)))->tryAdvance(static_cast<$IntConsumer*>(this)));
			bool var$0 = var$1 && checkCancelOnCount();
			if (!(var$0 && $nc(this->p)->test(this->t))) {
				break;
			}
			{
				dropped = true;
			}
		}
		if (adv) {
			if (dropped) {
				$nc(this->cancel)->set(true);
			}
			$nc(action)->accept(this->t);
		}
		return adv;
	} else {
		return $nc(($cast($Spliterator$OfInt, this->s)))->tryAdvance(action);
	}
}

$Spliterator$OfInt* WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::makeSpliterator($Spliterator$OfInt* s) {
	return $as($Spliterator$OfInt, $new(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, s, this));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::trySplit() {
	return $cast($Spliterator$OfInt, $WhileOps$UnorderedWhileSpliterator$OfInt::trySplit());
}

bool WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($IntConsumer, action));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::makeSpliterator($Spliterator* s) {
	return this->makeSpliterator($cast($Spliterator$OfInt, s));
}

WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::WhileOps$UnorderedWhileSpliterator$OfInt$Dropping() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfInt$Dropping, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfInt$Dropping_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfInt$Dropping);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfInt$Dropping::class$ = nullptr;

		} // stream
	} // util
} // java