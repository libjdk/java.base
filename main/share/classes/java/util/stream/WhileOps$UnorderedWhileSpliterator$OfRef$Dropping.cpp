#include <java/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Dropping.h>

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

$MethodInfo _WhileOps$UnorderedWhileSpliterator$OfRef$Dropping_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Spliterator;ZLjava/util/function/Predicate;)V", "(Ljava/util/Spliterator<TT;>;ZLjava/util/function/Predicate<-TT;>;)V", 0, $method(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, init$, void, $Spliterator*, bool, $Predicate*)},
	{"<init>", "(Ljava/util/Spliterator;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Dropping;)V", "(Ljava/util/Spliterator<TT;>;Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef$Dropping<TT;>;)V", 0, $method(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, init$, void, $Spliterator*, WhileOps$UnorderedWhileSpliterator$OfRef$Dropping*)},
	{"makeSpliterator", "(Ljava/util/Spliterator;)Ljava/util/Spliterator;", "(Ljava/util/Spliterator<TT;>;)Ljava/util/Spliterator<TT;>;", 0, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, makeSpliterator, $Spliterator*, $Spliterator*)},
	{"tryAdvance", "(Ljava/util/function/Consumer;)Z", "(Ljava/util/function/Consumer<-TT;>;)Z", $PUBLIC, $virtualMethod(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, tryAdvance, bool, $Consumer*)},
	{}
};

$InnerClassInfo _WhileOps$UnorderedWhileSpliterator$OfRef$Dropping_InnerClassesInfo_[] = {
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator", "java.util.stream.WhileOps", "UnorderedWhileSpliterator", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef", "java.util.stream.WhileOps$UnorderedWhileSpliterator", "OfRef", $STATIC | $ABSTRACT},
	{"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef$Dropping", "java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef", "Dropping", $STATIC | $FINAL},
	{}
};

$ClassInfo _WhileOps$UnorderedWhileSpliterator$OfRef$Dropping_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef$Dropping",
	"java.util.stream.WhileOps$UnorderedWhileSpliterator$OfRef",
	nullptr,
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfRef$Dropping_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/stream/WhileOps$UnorderedWhileSpliterator$OfRef<TT;>;",
	nullptr,
	_WhileOps$UnorderedWhileSpliterator$OfRef$Dropping_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.stream.WhileOps"
};

$Object* allocate$WhileOps$UnorderedWhileSpliterator$OfRef$Dropping($Class* clazz) {
	return $of($alloc(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping));
}

void WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::init$($Spliterator* s, bool noSplitting, $Predicate* p) {
	$WhileOps$UnorderedWhileSpliterator$OfRef::init$(s, noSplitting, p);
}

void WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::init$($Spliterator* s, WhileOps$UnorderedWhileSpliterator$OfRef$Dropping* parent) {
	$WhileOps$UnorderedWhileSpliterator$OfRef::init$(s, parent);
}

bool WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::tryAdvance($Consumer* action) {
	if (this->takeOrDrop) {
		this->takeOrDrop = false;
		bool adv = false;
		bool dropped = false;
		while (true) {
			bool var$1 = (adv = $nc(this->s)->tryAdvance(this));
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
		return $nc(this->s)->tryAdvance(action);
	}
}

$Spliterator* WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::makeSpliterator($Spliterator* s) {
	return $new(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, s, this);
}

WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::WhileOps$UnorderedWhileSpliterator$OfRef$Dropping() {
}

$Class* WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::load$($String* name, bool initialize) {
	$loadClass(WhileOps$UnorderedWhileSpliterator$OfRef$Dropping, name, initialize, &_WhileOps$UnorderedWhileSpliterator$OfRef$Dropping_ClassInfo_, allocate$WhileOps$UnorderedWhileSpliterator$OfRef$Dropping);
	return class$;
}

$Class* WhileOps$UnorderedWhileSpliterator$OfRef$Dropping::class$ = nullptr;

		} // stream
	} // util
} // java