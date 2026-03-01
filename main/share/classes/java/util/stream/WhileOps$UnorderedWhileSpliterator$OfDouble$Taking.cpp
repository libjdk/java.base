#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble$Taking.h>

#include <java/util/Spliterator$OfDouble.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/DoubleConsumer.h>
#include <java/util/function/DoublePredicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfDouble = ::java::util::Spliterator$OfDouble;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $DoubleConsumer = ::java::util::function::DoubleConsumer;
using $DoublePredicate = ::java::util::function::DoublePredicate;
using $WhileOps$UnorderedWhileSpliterator$OfDouble = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfDouble;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfDouble$Taking_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator$OfDouble;ZLjava/util/function/DoublePredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, init$, void, $Spliterator$OfDouble*, bool, $DoublePredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfDouble;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfDouble;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, init$, void, $Spliterator$OfDouble*, $WhileOps$UnorderedWhileSpliterator$OfDouble*)},
	{"makeSpliterator", "(Ljava/util/Spliterator$OfDouble;)Ljava/util/Spliterator$OfDouble;", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, makeSpliterator, $Spliterator$OfDouble*, $Spliterator$OfDouble*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", nullptr, $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/DoubleConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, tryAdvance, bool, $DoubleConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfDouble;", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfDouble$Taking_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfDouble", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfDouble$Taking_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble$Taking",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfDouble",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfDouble$Taking_MethodInfo_,
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfDouble$Taking_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfDouble$Taking($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking));
}

void WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::init$($Spliterator$OfDouble* s, bool noSplitting, $DoublePredicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfDouble::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::init$($Spliterator$OfDouble* s, $WhileOps$UnorderedWhileSpliterator$OfDouble* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfDouble::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::tryAdvance($DoubleConsumer* action) {
	bool test = true;
	bool var$1 = this->takeOrDrop && checkCancelOnCount();
	bool var$0 = var$1 && $nc(($cast($Spliterator$OfDouble, this->s)))->tryAdvance(static_cast<$DoubleConsumer*>(this));
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

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::trySplit() {
	return ($nc(this->cancel)->get() ? ($Spliterator$OfDouble*)nullptr : $cast($Spliterator$OfDouble, $WhileOps$UnorderedWhileSpliterator$OfDouble::trySplit()));
}

$Spliterator$OfDouble* WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::makeSpliterator($Spliterator$OfDouble* s) {
	return $as($Spliterator$OfDouble, $new(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, s, this));
}

bool WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($DoubleConsumer, action));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::makeSpliterator($Spliterator* s) {
	return this->makeSpliterator($cast($Spliterator$OfDouble, s));
}

WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::WhileOps$UnorderedWhileSpliterator$OfDouble$Taking() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfDouble$Taking, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfDouble$Taking_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfDouble$Taking);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfDouble$Taking::class$ = nullptr;

		} // stream
	} // util
} // java