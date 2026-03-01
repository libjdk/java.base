#include <MyThreadFactory.h>

#include <java/lang/Runnable.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

$FieldInfo _MyThreadFactory_FieldInfo_[] = {
	{"threads", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Thread;>;", $PRIVATE | $STATIC | $FINAL, $staticField(MyThreadFactory, threads)},
	{}
};

$MethodInfo _MyThreadFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MyThreadFactory, init$, void)},
	{"created", "(Ljava/lang/Thread;)Z", nullptr, $STATIC, $staticMethod(MyThreadFactory, created, bool, $Thread*)},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC, $virtualMethod(MyThreadFactory, newThread, $Thread*, $Runnable*)},
	{}
};

$ClassInfo _MyThreadFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"MyThreadFactory",
	"java.lang.Object",
	"java.util.concurrent.ThreadFactory",
	_MyThreadFactory_FieldInfo_,
	_MyThreadFactory_MethodInfo_
};

$Object* allocate$MyThreadFactory($Class* clazz) {
	return $of($alloc(MyThreadFactory));
}

$Set* MyThreadFactory::threads = nullptr;

bool MyThreadFactory::created($Thread* t) {
	$init(MyThreadFactory);
	$synchronized(MyThreadFactory::threads) {
		return $nc(MyThreadFactory::threads)->contains(t);
	}
}

void MyThreadFactory::init$() {
}

$Thread* MyThreadFactory::newThread($Runnable* r) {
	$var($Thread, t, $new($Thread, r));
	t->setDaemon(true);
	$synchronized(MyThreadFactory::threads) {
		$nc(MyThreadFactory::threads)->add(t);
	}
	return t;
}

void clinit$MyThreadFactory($Class* class$) {
	$assignStatic(MyThreadFactory::threads, $new($HashSet));
}

MyThreadFactory::MyThreadFactory() {
}

$Class* MyThreadFactory::load$($String* name, bool initialize) {
	$loadClass(MyThreadFactory, name, initialize, &_MyThreadFactory_ClassInfo_, clinit$MyThreadFactory, allocate$MyThreadFactory);
	return class$;
}

$Class* MyThreadFactory::class$ = nullptr;