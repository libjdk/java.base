#include <java/lang/System$CallersHolder.h>

#include <java/util/Collections.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;

namespace java {
	namespace lang {

$FieldInfo _System$CallersHolder_FieldInfo_[] = {
	{"callers", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/lang/Boolean;>;", $STATIC | $FINAL, $staticField(System$CallersHolder, callers)},
	{}
};

$MethodInfo _System$CallersHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(System$CallersHolder, init$, void)},
	{}
};

$InnerClassInfo _System$CallersHolder_InnerClassesInfo_[] = {
	{"java.lang.System$CallersHolder", "java.lang.System", "CallersHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _System$CallersHolder_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.System$CallersHolder",
	"java.lang.Object",
	nullptr,
	_System$CallersHolder_FieldInfo_,
	_System$CallersHolder_MethodInfo_,
	nullptr,
	nullptr,
	_System$CallersHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.System"
};

$Object* allocate$System$CallersHolder($Class* clazz) {
	return $of($alloc(System$CallersHolder));
}

$Map* System$CallersHolder::callers = nullptr;

void System$CallersHolder::init$() {
}

void clinit$System$CallersHolder($Class* class$) {
	$assignStatic(System$CallersHolder::callers, $Collections::synchronizedMap($$new($WeakHashMap)));
}

System$CallersHolder::System$CallersHolder() {
}

$Class* System$CallersHolder::load$($String* name, bool initialize) {
	$loadClass(System$CallersHolder, name, initialize, &_System$CallersHolder_ClassInfo_, clinit$System$CallersHolder, allocate$System$CallersHolder);
	return class$;
}

$Class* System$CallersHolder::class$ = nullptr;

	} // lang
} // java