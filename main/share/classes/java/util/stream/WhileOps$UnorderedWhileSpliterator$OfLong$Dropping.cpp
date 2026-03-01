#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong$Dropping.h>

#include <java/util/Spliterator$OfLong.h>
#include <java/util/Spliterator.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/LongConsumer.h>
#include <java/util/function/LongPredicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $Spliterator$OfLong = ::java::util::Spliterator$OfLong;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $LongConsumer = ::java::util::function::LongConsumer;
using $LongPredicate = ::java::util::function::LongPredicate;
using $WhileOps$UnorderedWhileSpliterator$OfLong = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfLong;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfLong$Dropping_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator$OfLong;ZLjava/util/function/LongPredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, init$, void, $Spliterator$OfLong*, bool, $LongPredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfLong;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, init$, void, $Spliterator$OfLong*, $WhileOps$UnorderedWhileSpliterator$OfLong*)},
	{"makeSpliterator", "(Ljava/util/Spliterator$OfLong;)Ljava/util/Spliterator$OfLong;", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, makeSpliterator, $Spliterator$OfLong*, $Spliterator$OfLong*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", nullptr, $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, tryAdvance, bool, $LongConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfLong$Dropping_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfLong", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Dropping", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "Dropping", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfLong$Dropping_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Dropping",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfLong$Dropping_MethodInfo_,
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfLong$Dropping_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfLong$Dropping($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping));
}

void WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::init$($Spliterator$OfLong* s, bool noSplitting, $LongPredicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfLong::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::init$($Spliterator$OfLong* s, $WhileOps$UnorderedWhileSpliterator$OfLong* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfLong::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::tryAdvance($LongConsumer* action) {
	if (this->takeOrDrop) {
		this->takeOrDrop = false;
		bool adv = false;
		bool dropped = false;
		while (true) {
			bool var$1 = (adv = $nc(($cast($Spliterator$OfLong, this->s)))->tryAdvance(static_cast<$LongConsumer*>(this)));
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
		return $nc(($cast($Spliterator$OfLong, this->s)))->tryAdvance(action);
	}
}

$Spliterator$OfLong* WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::makeSpliterator($Spliterator$OfLong* s) {
	return $as($Spliterator$OfLong, $new(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, s, this));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::trySplit() {
	return $cast($Spliterator$OfLong, $WhileOps$UnorderedWhileSpliterator$OfLong::trySplit());
}

bool WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($LongConsumer, action));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::makeSpliterator($Spliterator* s) {
	return this->makeSpliterator($cast($Spliterator$OfLong, s));
}

WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::WhileOps$UnorderedWhileSpliterator$OfLong$Dropping() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfLong$Dropping, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfLong$Dropping_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfLong$Dropping);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfLong$Dropping::class$ = nullptr;

		} // stream
	} // util
} // java