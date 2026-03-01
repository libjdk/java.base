#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Taking.h>

#include <java/util/Spliterator.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef.h>
#include <java/util/stream/WhileOps$UnorderedWhileSpliterator.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Spliterator = ::java::util::Spliterator;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $WhileOps$UnorderedWhileSpliterator$OfRef = ::java::util::stream::WhileOps$UnorderedWhileSpliterator$OfRef;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfRef$Taking_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator;ZLjava/util/function/Predicate;)V", "(Ljava/util/Spliterator<TT;>;ZLjava/util/function/Predicate<-TT;>;)V", 0, $method(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, init$, void, $Spliterator*, bool, $Predicate*)},
	{"<init>", "(Ljava/util/Spliterator;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Taking;)V", "(Ljava/util/Spliterator<TT;>;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Taking<TT;>;)V", 0, $method(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, init$, void, $Spliterator*, WhileOps$UnorderedWhileSpliterator$OfRef$Taking*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", "(Ljava/util/Spliterator<TT;>;)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/Consumer;)Z", "(Ljava/util/function/Consumer<-TT;>;)Z", $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, tryAdvance, bool, $Consumer*)},
	{"trySplit", "()Ljava/util/Spliterator;", "()Ljava/util/Spliterator<TT;>;", $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, trySplit, $Spliterator*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfRef$Taking_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfRef", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef$Taking", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef", "Taking", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfRef$Taking_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef$Taking",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfRef$Taking_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef<TT;>;",
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfRef$Taking_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfRef$Taking($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfRef$Taking));
}

void WhileOps$UnorderedWhileSpliterator$OfRef$Taking::init$($Spliterator* s, bool noSplitting, $Predicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfRef::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfRef$Taking::init$($Spliterator* s, WhileOps$UnorderedWhileSpliterator$OfRef$Taking* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfRef::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfRef$Taking::tryAdvance($Consumer* action) {
	bool test = true;
	bool var$1 = this->takeOrDrop && checkCancelOnCount();
	bool var$0 = var$1 && $nc(this->s)->tryAdvance(this);
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

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfRef$Taking::trySplit() {
	return $nc(this->cancel)->get() ? ($Spliterator*)nullptr : $WhileOps$UnorderedWhileSpliterator$OfRef::trySplit();
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfRef$Taking::makeSpliterator($Spliterator* s) {
	return $new(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, s, this);
}

WhileOps$UnorderedWhileSpliterator$OfRef$Taking::WhileOps$UnorderedWhileSpliterator$OfRef$Taking() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfRef$Taking::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfRef$Taking, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfRef$Taking_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfRef$Taking);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfRef$Taking::class$ = nullptr;

		} // stream
	} // util
} // java