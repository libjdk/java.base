#include <ReferenceEnqueue$ExplicitEnqueue.h>

#include <ReferenceEnqueue.h>
#include <java/lang/ref/PhantomReference.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/SoftReference.h>
#include <java/lang/ref/WeakReference.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $PhantomReference = ::java::lang::ref::PhantomReference;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $SoftReference = ::java::lang::ref::SoftReference;
using $WeakReference = ::java::lang::ref::WeakReference;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _ReferenceEnqueue$ExplicitEnqueue_FieldInfo_[] = {
	{"queue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;", $FINAL, $field(ReferenceEnqueue$ExplicitEnqueue, queue)},
	{"refs", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/ref/Reference<Ljava/lang/Object;>;>;", $FINAL, $field(ReferenceEnqueue$ExplicitEnqueue, refs)},
	{"iterations", "I", nullptr, $STATIC | $FINAL, $constField(ReferenceEnqueue$ExplicitEnqueue, iterations)},
	{}
};

$MethodInfo _ReferenceEnqueue$ExplicitEnqueue_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ReferenceEnqueue$ExplicitEnqueue, init$, void)},
	{"run", "()V", nullptr, 0, $virtualMethod(ReferenceEnqueue$ExplicitEnqueue, run, void), "java.lang.InterruptedException"},
	{}
};

$InnerClassInfo _ReferenceEnqueue$ExplicitEnqueue_InnerClassesInfo_[] = {
	{"ReferenceEnqueue$ExplicitEnqueue", "ReferenceEnqueue", "ExplicitEnqueue", $STATIC},
	{}
};

$ClassInfo _ReferenceEnqueue$ExplicitEnqueue_ClassInfo_ = {
	$ACC_SUPER,
	"ReferenceEnqueue$ExplicitEnqueue",
	"java.lang.Object",
	nullptr,
	_ReferenceEnqueue$ExplicitEnqueue_FieldInfo_,
	_ReferenceEnqueue$ExplicitEnqueue_MethodInfo_,
	nullptr,
	nullptr,
	_ReferenceEnqueue$ExplicitEnqueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"ReferenceEnqueue"
};

$Object* allocate$ReferenceEnqueue$ExplicitEnqueue($Class* clazz) {
	return $of($alloc(ReferenceEnqueue$ExplicitEnqueue));
}

void ReferenceEnqueue$ExplicitEnqueue::init$() {
	$useLocalCurrentObjectStackCache();
	$set(this, queue, $new($ReferenceQueue));
	$set(this, refs, $new($ArrayList));
	$nc(this->refs)->add($$new($SoftReference, $$new($Object), this->queue));
	$nc(this->refs)->add($$new($WeakReference, $$new($Object), this->queue));
	$nc(this->refs)->add($$new($PhantomReference, $$new($Object), this->queue));
}

void ReferenceEnqueue$ExplicitEnqueue::run() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(this->refs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Reference, ref, $cast($Reference, i$->next()));
			{
				if ($nc(ref)->enqueue() == false) {
					$throwNew($RuntimeException, "Error: enqueue failed"_s);
				}
				if (!$nc(ref)->refersTo(nullptr)) {
					$throwNew($RuntimeException, "Error: referent must be cleared"_s);
				}
			}
		}
	}
	$System::gc();
	for (int32_t i = 0; $nc(this->refs)->size() > 0 && i < ReferenceEnqueue$ExplicitEnqueue::iterations; ++i) {
		$var($Reference, ref, $nc(this->queue)->poll());
		if (ref == nullptr) {
			$System::gc();
			$Thread::sleep(100);
			continue;
		}
		if ($nc(this->refs)->remove($of(ref)) == false) {
			$throwNew($RuntimeException, $$str({"Error: unknown reference "_s, ref}));
		}
	}
	if (!$nc(this->refs)->isEmpty()) {
		$throwNew($RuntimeException, "Error: not all references are removed"_s);
	}
}

ReferenceEnqueue$ExplicitEnqueue::ReferenceEnqueue$ExplicitEnqueue() {
}

$Class* ReferenceEnqueue$ExplicitEnqueue::load$($String* name, bool initialize) {
	$loadClass(ReferenceEnqueue$ExplicitEnqueue, name, initialize, &_ReferenceEnqueue$ExplicitEnqueue_ClassInfo_, allocate$ReferenceEnqueue$ExplicitEnqueue);
	return class$;
}

$Class* ReferenceEnqueue$ExplicitEnqueue::class$ = nullptr;