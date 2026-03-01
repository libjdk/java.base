#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt$Taking.h>

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

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfInt$Taking_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator$OfInt;ZLjava/util/function/IntPredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, init$, void, $Spliterator$OfInt*, bool, $IntPredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfInt;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfInt;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, init$, void, $Spliterator$OfInt*, $WhileOps$UnorderedWhileSpliterator$OfInt*)},
	{"makeSpliterator", "(Ljava/util/Spliterator$OfInt;)Ljava/util/Spliterator$OfInt;", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, makeSpliterator, $Spliterator$OfInt*, $Spliterator$OfInt*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", nullptr, $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/IntConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, tryAdvance, bool, $IntConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfInt;", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfInt$Taking_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfInt", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfInt$Taking_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt$Taking",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfInt",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfInt$Taking_MethodInfo_,
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfInt$Taking_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfInt$Taking($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfInt$Taking));
}

void WhileOps$UnorderedWhileSpliterator$OfInt$Taking::init$($Spliterator$OfInt* s, bool noSplitting, $IntPredicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfInt::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfInt$Taking::init$($Spliterator$OfInt* s, $WhileOps$UnorderedWhileSpliterator$OfInt* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfInt::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfInt$Taking::tryAdvance($IntConsumer* action) {
	bool test = true;
	bool var$1 = this->takeOrDrop && checkCancelOnCount();
	bool var$0 = var$1 && $nc(($cast($Spliterator$OfInt, this->s)))->tryAdvance(static_cast<$IntConsumer*>(this));
	if (var$0 && (test = $nc(this->p)->test(this->t))) {
		$nc(action)->accept(this->t);
		return true;
	} else {
		this->takeOrDrop = false;
		if (!test) {
			$nc(this->cancel)->set(true);
		}
		return false;
	}
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfInt$Taking::trySplit() {
	return ($nc(this->cancel)->get() ? ($Spliterator$OfInt*)nullptr : $cast($Spliterator$OfInt, $WhileOps$UnorderedWhileSpliterator$OfInt::trySplit()));
}

$Spliterator$OfInt* WhileOps$UnorderedWhileSpliterator$OfInt$Taking::makeSpliterator($Spliterator$OfInt* s) {
	return $as($Spliterator$OfInt, $new(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, s, this));
}

bool WhileOps$UnorderedWhileSpliterator$OfInt$Taking::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($IntConsumer, action));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfInt$Taking::makeSpliterator($Spliterator* s) {
	return this->makeSpliterator($cast($Spliterator$OfInt, s));
}

WhileOps$UnorderedWhileSpliterator$OfInt$Taking::WhileOps$UnorderedWhileSpliterator$OfInt$Taking() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfInt$Taking::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfInt$Taking, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfInt$Taking_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfInt$Taking);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfInt$Taking::class$ = nullptr;

		} // stream
	} // util
} // java