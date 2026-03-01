#include <java/lang/ClassLoader$ParallelLoaders.h>

#include <java/lang/ClassLoader.h>
#include <java/util/Collections.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/WeakHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $WeakHashMap = ::java::util::WeakHashMap;

namespace java {
	namespace lang {

$FieldInfo _ClassLoader$ParallelLoaders_FieldInfo_[] = {
	{"loaderTypes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/Class<+Ljava/lang/ClassLoader;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ClassLoader$ParallelLoaders, loaderTypes)},
	{}
};

$MethodInfo _ClassLoader$ParallelLoaders_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ClassLoader$ParallelLoaders, init$, void)},
	{"isRegistered", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<+Ljava/lang/ClassLoader;>;)Z", $STATIC, $staticMethod(ClassLoader$ParallelLoaders, isRegistered, bool, $Class*)},
	{"register", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<+Ljava/lang/ClassLoader;>;)Z", $STATIC, $staticMethod(ClassLoader$ParallelLoaders, register$, bool, $Class*)},
	{}
};

$InnerClassInfo _ClassLoader$ParallelLoaders_InnerClassesInfo_[] = {
	{"java.lang.ClassLoader$ParallelLoaders", "java.lang.ClassLoader", "ParallelLoaders", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ClassLoader$ParallelLoaders_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.ClassLoader$ParallelLoaders",
	"java.lang.Object",
	nullptr,
	_ClassLoader$ParallelLoaders_FieldInfo_,
	_ClassLoader$ParallelLoaders_MethodInfo_,
	nullptr,
	nullptr,
	_ClassLoader$ParallelLoaders_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.ClassLoader"
};

$Object* allocate$ClassLoader$ParallelLoaders($Class* clazz) {
	return $of($alloc(ClassLoader$ParallelLoaders));
}

$Set* ClassLoader$ParallelLoaders::loaderTypes = nullptr;

void ClassLoader$ParallelLoaders::init$() {
}

bool ClassLoader$ParallelLoaders::register$($Class* c) {
	$init(ClassLoader$ParallelLoaders);
	$synchronized(ClassLoader$ParallelLoaders::loaderTypes) {
		if ($nc(ClassLoader$ParallelLoaders::loaderTypes)->contains($nc(c)->getSuperclass())) {
			$nc(ClassLoader$ParallelLoaders::loaderTypes)->add(c);
			return true;
		} else {
			return false;
		}
	}
}

bool ClassLoader$ParallelLoaders::isRegistered($Class* c) {
	$init(ClassLoader$ParallelLoaders);
	$synchronized(ClassLoader$ParallelLoaders::loaderTypes) {
		return $nc(ClassLoader$ParallelLoaders::loaderTypes)->contains(c);
	}
}

void clinit$ClassLoader$ParallelLoaders($Class* class$) {
	$assignStatic(ClassLoader$ParallelLoaders::loaderTypes, $Collections::newSetFromMap($$new($WeakHashMap)));
	{
		$synchronized(ClassLoader$ParallelLoaders::loaderTypes) {
			$load($ClassLoader);
			$nc(ClassLoader$ParallelLoaders::loaderTypes)->add($ClassLoader::class$);
		}
	}
}

ClassLoader$ParallelLoaders::ClassLoader$ParallelLoaders() {
}

$Class* ClassLoader$ParallelLoaders::load$($String* name, bool initialize) {
	$loadClass(ClassLoader$ParallelLoaders, name, initialize, &_ClassLoader$ParallelLoaders_ClassInfo_, clinit$ClassLoader$ParallelLoaders, allocate$ClassLoader$ParallelLoaders);
	return class$;
}

$Class* ClassLoader$ParallelLoaders::class$ = nullptr;

	} // lang
} // java