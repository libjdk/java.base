#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong$Taking.h>

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

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfLong$Taking_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator$OfLong;ZLjava/util/function/LongPredicate;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, init$, void, $Spliterator$OfLong*, bool, $LongPredicate*)},
	{"<init>", "(Ljava/util/Spliterator$OfLong;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfLong;)V", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, init$, void, $Spliterator$OfLong*, $WhileOps$UnorderedWhileSpliterator$OfLong*)},
	{"makeSpliterator", "(Ljava/util/Spliterator$OfLong;)Ljava/util/Spliterator$OfLong;", nullptr, 0, $method(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, makeSpliterator, $Spliterator$OfLong*, $Spliterator$OfLong*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", nullptr, $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/LongConsumer;)Z", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, tryAdvance, bool, $LongConsumer*)},
	{"tryAdvance", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, tryAdvance, bool, Object$*)},
	{"trySplit", "()Ljava/util/Spliterator$OfLong;", nullptr, $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfLong$Taking_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfLong", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfLong$Taking_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong$Taking",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfLong",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfLong$Taking_MethodInfo_,
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfLong$Taking_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfLong$Taking($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfLong$Taking));
}

void WhileOps$UnorderedWhileSpliterator$OfLong$Taking::init$($Spliterator$OfLong* s, bool noSplitting, $LongPredicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfLong::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfLong$Taking::init$($Spliterator$OfLong* s, $WhileOps$UnorderedWhileSpliterator$OfLong* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfLong::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfLong$Taking::tryAdvance($LongConsumer* action) {
	bool test = true;
	bool var$1 = this->takeOrDrop && checkCancelOnCount();
	bool var$0 = var$1 && $nc(($cast($Spliterator$OfLong, this->s)))->tryAdvance(static_cast<$LongConsumer*>(this));
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

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfLong$Taking::trySplit() {
	return ($nc(this->cancel)->get() ? ($Spliterator$OfLong*)nullptr : $cast($Spliterator$OfLong, $WhileOps$UnorderedWhileSpliterator$OfLong::trySplit()));
}

$Spliterator$OfLong* WhileOps$UnorderedWhileSpliterator$OfLong$Taking::makeSpliterator($Spliterator$OfLong* s) {
	return $as($Spliterator$OfLong, $new(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, s, this));
}

bool WhileOps$UnorderedWhileSpliterator$OfLong$Taking::tryAdvance(Object$* action) {
	return this->tryAdvance($cast($LongConsumer, action));
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfLong$Taking::makeSpliterator($Spliterator* s) {
	return this->makeSpliterator($cast($Spliterator$OfLong, s));
}

WhileOps$UnorderedWhileSpliterator$OfLong$Taking::WhileOps$UnorderedWhileSpliterator$OfLong$Taking() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfLong$Taking::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfLong$Taking, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfLong$Taking_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfLong$Taking);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfLong$Taking::class$ = nullptr;

		} // stream
	} // util
} // java