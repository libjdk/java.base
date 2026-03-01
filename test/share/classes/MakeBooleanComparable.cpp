#include <MakeBooleanComparable.h>

#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Random = ::java::util::Random;

$MethodInfo _MakeBooleanComparable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MakeBooleanComparable, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(MakeBooleanComparable, main, void, $StringArray*)},
	{}
};

$ClassInfo _MakeBooleanComparable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MakeBooleanComparable",
	"java.lang.Object",
	nullptr,
	nullptr,
	_MakeBooleanComparable_MethodInfo_
};

$Object* allocate$MakeBooleanComparable($Class* clazz) {
	return $of($alloc(MakeBooleanComparable));
}

void MakeBooleanComparable::init$() {
}

void MakeBooleanComparable::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($Random, rnd, $new($Random));
	$var($List, list, $new($ArrayList));
	int32_t numFalse = 0;
	for (int32_t i = 0; i < 1000; ++i) {
		bool element = rnd->nextBoolean();
		if (!element) {
			++numFalse;
		}
		list->add($($Boolean::valueOf(element)));
	}
	$Collections::sort(list);
	for (int32_t i = 0; i < numFalse; ++i) {
		if ($nc(($cast($Boolean, $(list->get(i)))))->booleanValue()) {
			$throwNew($RuntimeException, $$str({"False positive: "_s, $$str(i)}));
		}
	}
	for (int32_t i = numFalse; i < 1000; ++i) {
		if (!$nc(($cast($Boolean, $(list->get(i)))))->booleanValue()) {
			$throwNew($RuntimeException, $$str({"False negative: "_s, $$str(i)}));
		}
	}
}

MakeBooleanComparable::MakeBooleanComparable() {
}

$Class* MakeBooleanComparable::load$($String* name, bool initialize) {
	$loadClass(MakeBooleanComparable, name, initialize, &_MakeBooleanComparable_ClassInfo_, allocate$MakeBooleanComparable);
	return class$;
}

$Class* MakeBooleanComparable::class$ = nullptr;