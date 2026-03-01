#include <PhantomReferentClearing.h>

#include <java/lang/ref/PhantomReference.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef ENQUEUE_TIMEOUT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $PhantomReference = ::java::lang::ref::PhantomReference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

$FieldInfo _PhantomReferentClearing_FieldInfo_[] = {
	{"ENQUEUE_TIMEOUT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PhantomReferentClearing, ENQUEUE_TIMEOUT)},
	{"Q1", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(PhantomReferentClearing, Q1)},
	{"Q2", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(PhantomReferentClearing, Q2)},
	{"O2", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(PhantomReferentClearing, O2)},
	{"O1", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(PhantomReferentClearing, O1)},
	{"P1", "Ljava/lang/ref/PhantomReference;", "Ljava/lang/ref/PhantomReference<Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(PhantomReferentClearing, P1)},
	{"P2", "Ljava/lang/ref/PhantomReference;", "Ljava/lang/ref/PhantomReference<Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(PhantomReferentClearing, P2)},
	{}
};

$MethodInfo _PhantomReferentClearing_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PhantomReferentClearing, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(PhantomReferentClearing, main, void, $StringArray*), "java.lang.InterruptedException"},
	{}
};

$ClassInfo _PhantomReferentClearing_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"PhantomReferentClearing",
	"java.lang.Object",
	nullptr,
	_PhantomReferentClearing_FieldInfo_,
	_PhantomReferentClearing_MethodInfo_
};

$Object* allocate$PhantomReferentClearing($Class* clazz) {
	return $of($alloc(PhantomReferentClearing));
}

$ReferenceQueue* PhantomReferentClearing::Q1 = nullptr;
$ReferenceQueue* PhantomReferentClearing::Q2 = nullptr;
$volatile($Object*) PhantomReferentClearing::O2 = nullptr;
$volatile($List*) PhantomReferentClearing::O1 = nullptr;
$PhantomReference* PhantomReferentClearing::P1 = nullptr;
$PhantomReference* PhantomReferentClearing::P2 = nullptr;

void PhantomReferentClearing::init$() {
}

void PhantomReferentClearing::main($StringArray* args) {
	$init(PhantomReferentClearing);
	$System::gc();
	if ($nc(PhantomReferentClearing::Q1)->remove(PhantomReferentClearing::ENQUEUE_TIMEOUT) != nullptr) {
		$throwNew($RuntimeException, "P1 already notified"_s);
	} else {
		if ($nc(PhantomReferentClearing::Q2)->poll() != nullptr) {
			$throwNew($RuntimeException, "P2 already notified"_s);
		}
	}
	$assignStatic(PhantomReferentClearing::O1, nullptr);
	$System::gc();
	if ($nc(PhantomReferentClearing::Q1)->remove(PhantomReferentClearing::ENQUEUE_TIMEOUT) == nullptr) {
		$throwNew($RuntimeException, "P1 not notified by O1 deletion"_s);
	} else {
		if ($nc(PhantomReferentClearing::Q2)->remove(PhantomReferentClearing::ENQUEUE_TIMEOUT) != nullptr) {
			$throwNew($RuntimeException, "P2 notified by O1 deletion."_s);
		}
	}
	$assignStatic(PhantomReferentClearing::O2, nullptr);
	$System::gc();
	if ($nc(PhantomReferentClearing::Q2)->remove(PhantomReferentClearing::ENQUEUE_TIMEOUT) == nullptr) {
		$throwNew($RuntimeException, "P2 not notified by O2 deletion"_s);
	}
}

void clinit$PhantomReferentClearing($Class* class$) {
	$assignStatic(PhantomReferentClearing::Q1, $new($ReferenceQueue));
	$assignStatic(PhantomReferentClearing::Q2, $new($ReferenceQueue));
	$assignStatic(PhantomReferentClearing::O2, $new($Object));
	$assignStatic(PhantomReferentClearing::O1, $new($ArrayList));
	{
		$nc(PhantomReferentClearing::O1)->add(PhantomReferentClearing::O2);
	}
	$assignStatic(PhantomReferentClearing::P1, $new($PhantomReference, PhantomReferentClearing::O1, PhantomReferentClearing::Q1));
	$assignStatic(PhantomReferentClearing::P2, $new($PhantomReference, PhantomReferentClearing::O2, PhantomReferentClearing::Q2));
}

PhantomReferentClearing::PhantomReferentClearing() {
}

$Class* PhantomReferentClearing::load$($String* name, bool initialize) {
	$loadClass(PhantomReferentClearing, name, initialize, &_PhantomReferentClearing_ClassInfo_, clinit$PhantomReferentClearing, allocate$PhantomReferentClearing);
	return class$;
}

$Class* PhantomReferentClearing::class$ = nullptr;