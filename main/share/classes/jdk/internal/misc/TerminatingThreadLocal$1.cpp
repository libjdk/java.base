#include <jdk/internal/misc/TerminatingThreadLocal$1.h>

#include <java/lang/ThreadLocal.h>
#include <java/util/Collections.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $Collections = ::java::util::Collections;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $Map = ::java::util::Map;

namespace jdk {
	namespace internal {
		namespace misc {

$MethodInfo _TerminatingThreadLocal$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(TerminatingThreadLocal$1, init$, void)},
	{"initialValue", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljdk/internal/misc/TerminatingThreadLocal<*>;>;", $PROTECTED, $virtualMethod(TerminatingThreadLocal$1, initialValue, $Object*)},
	{}
};

$EnclosingMethodInfo _TerminatingThreadLocal$1_EnclosingMethodInfo_ = {
	"jdk.internal.misc.TerminatingThreadLocal",
	nullptr,
	nullptr
};

$InnerClassInfo _TerminatingThreadLocal$1_InnerClassesInfo_[] = {
	{"jdk.internal.misc.TerminatingThreadLocal$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TerminatingThreadLocal$1_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.misc.TerminatingThreadLocal$1",
	"java.lang.ThreadLocal",
	nullptr,
	nullptr,
	_TerminatingThreadLocal$1_MethodInfo_,
	"Ljava/lang/ThreadLocal<Ljava/util/Collection<Ljdk/internal/misc/TerminatingThreadLocal<*>;>;>;",
	&_TerminatingThreadLocal$1_EnclosingMethodInfo_,
	_TerminatingThreadLocal$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.misc.TerminatingThreadLocal"
};

$Object* allocate$TerminatingThreadLocal$1($Class* clazz) {
	return $of($alloc(TerminatingThreadLocal$1));
}

void TerminatingThreadLocal$1::init$() {
	$ThreadLocal::init$();
}

$Object* TerminatingThreadLocal$1::initialValue() {
	return $of($Collections::newSetFromMap($$new($IdentityHashMap, 4)));
}

TerminatingThreadLocal$1::TerminatingThreadLocal$1() {
}

$Class* TerminatingThreadLocal$1::load$($String* name, bool initialize) {
	$loadClass(TerminatingThreadLocal$1, name, initialize, &_TerminatingThreadLocal$1_ClassInfo_, allocate$TerminatingThreadLocal$1);
	return class$;
}

$Class* TerminatingThreadLocal$1::class$ = nullptr;

		} // misc
	} // internal
} // jdk