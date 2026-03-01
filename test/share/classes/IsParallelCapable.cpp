#include <IsParallelCapable.h>

#include <IsParallelCapable$NonParaCL.h>
#include <IsParallelCapable$NonParaSubCL1.h>
#include <IsParallelCapable$NonParaSubCL2.h>
#include <IsParallelCapable$ParaCL.h>
#include <IsParallelCapable$ParaSubCL.h>
#include <IsParallelCapable$TestCL.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/function/Consumer.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

using $IsParallelCapable$NonParaCL = ::IsParallelCapable$NonParaCL;
using $IsParallelCapable$NonParaSubCL1 = ::IsParallelCapable$NonParaSubCL1;
using $IsParallelCapable$NonParaSubCL2 = ::IsParallelCapable$NonParaSubCL2;
using $IsParallelCapable$ParaCL = ::IsParallelCapable$ParaCL;
using $IsParallelCapable$ParaSubCL = ::IsParallelCapable$ParaSubCL;
using $IsParallelCapable$TestCL = ::IsParallelCapable$TestCL;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Consumer = ::java::util::function::Consumer;
using $Stream = ::java::util::stream::Stream;

class IsParallelCapable$$Lambda$testClassLoaderClass : public $Consumer {
	$class(IsParallelCapable$$Lambda$testClassLoaderClass, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* klazz) override {
		IsParallelCapable::testClassLoaderClass($cast($Class, klazz));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<IsParallelCapable$$Lambda$testClassLoaderClass>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo IsParallelCapable$$Lambda$testClassLoaderClass::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(IsParallelCapable$$Lambda$testClassLoaderClass, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(IsParallelCapable$$Lambda$testClassLoaderClass, accept, void, Object$*)},
	{}
};
$ClassInfo IsParallelCapable$$Lambda$testClassLoaderClass::classInfo$ = {
	$PUBLIC | $FINAL,
	"IsParallelCapable$$Lambda$testClassLoaderClass",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* IsParallelCapable$$Lambda$testClassLoaderClass::load$($String* name, bool initialize) {
	$loadClass(IsParallelCapable$$Lambda$testClassLoaderClass, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* IsParallelCapable$$Lambda$testClassLoaderClass::class$ = nullptr;

$MethodInfo _IsParallelCapable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(IsParallelCapable, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(IsParallelCapable, main, void, $StringArray*), "java.lang.Exception"},
	{"testClassLoaderClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<+LIsParallelCapable$TestCL;>;)V", $PRIVATE | $STATIC, $staticMethod(IsParallelCapable, testClassLoaderClass, void, $Class*)},
	{}
};

$InnerClassInfo _IsParallelCapable_InnerClassesInfo_[] = {
	{"IsParallelCapable$ParaSubCL", "IsParallelCapable", "ParaSubCL", $PUBLIC | $STATIC},
	{"IsParallelCapable$NonParaSubCL2", "IsParallelCapable", "NonParaSubCL2", $PUBLIC | $STATIC},
	{"IsParallelCapable$NonParaSubCL1", "IsParallelCapable", "NonParaSubCL1", $PUBLIC | $STATIC},
	{"IsParallelCapable$NonParaCL", "IsParallelCapable", "NonParaCL", $PUBLIC | $STATIC},
	{"IsParallelCapable$ParaCL", "IsParallelCapable", "ParaCL", $PUBLIC | $STATIC},
	{"IsParallelCapable$TestCL", "IsParallelCapable", "TestCL", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _IsParallelCapable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"IsParallelCapable",
	"java.lang.Object",
	nullptr,
	nullptr,
	_IsParallelCapable_MethodInfo_,
	nullptr,
	nullptr,
	_IsParallelCapable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"IsParallelCapable$ParaSubCL,IsParallelCapable$NonParaSubCL2,IsParallelCapable$NonParaSubCL1,IsParallelCapable$NonParaCL,IsParallelCapable$ParaCL,IsParallelCapable$TestCL"
};

$Object* allocate$IsParallelCapable($Class* clazz) {
	return $of($alloc(IsParallelCapable));
}

void IsParallelCapable::init$() {
}

void IsParallelCapable::main($StringArray* args) {
	$load(IsParallelCapable);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!$nc($($ClassLoader::getSystemClassLoader()))->isRegisteredAsParallelCapable()) {
		$throwNew($RuntimeException, "System classloader not parallel capable!?"_s);
	}
	$load($IsParallelCapable$ParaCL);
	$load($IsParallelCapable$NonParaCL);
	$load($IsParallelCapable$NonParaSubCL1);
	$load($IsParallelCapable$NonParaSubCL2);
	$load($IsParallelCapable$ParaSubCL);
	$nc($($Stream::of($$new($ClassArray, {
		$IsParallelCapable$ParaCL::class$,
		$IsParallelCapable$NonParaCL::class$,
		$IsParallelCapable$NonParaSubCL1::class$,
		$IsParallelCapable$NonParaSubCL2::class$,
		$IsParallelCapable$ParaSubCL::class$
	}))))->forEach(static_cast<$Consumer*>($$new(IsParallelCapable$$Lambda$testClassLoaderClass)));
}

void IsParallelCapable::testClassLoaderClass($Class* klazz) {
	$load(IsParallelCapable);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($IsParallelCapable$TestCL, cl, $cast($IsParallelCapable$TestCL, $nc(klazz)->newInstance()));
		bool var$0 = $nc(cl)->expectCapable();
		if (var$0 != cl->isRegisteredAsParallelCapable()) {
			$var($String, var$3, $$str({klazz, " expectCapable: "_s}));
			$var($String, var$2, $$concat(var$3, $$str(cl->expectCapable())));
			$var($String, var$1, $$concat(var$2, ", isRegisteredAsParallelCapable: "_s));
			$throwNew($RuntimeException, $$concat(var$1, $$str(cl->isRegisteredAsParallelCapable())));
		} else {
			$nc($System::out)->println($$str({klazz, " passed"_s}));
		}
	} catch ($InstantiationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
}

IsParallelCapable::IsParallelCapable() {
}

$Class* IsParallelCapable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(IsParallelCapable$$Lambda$testClassLoaderClass::classInfo$.name)) {
			return IsParallelCapable$$Lambda$testClassLoaderClass::load$(name, initialize);
		}
	}
	$loadClass(IsParallelCapable, name, initialize, &_IsParallelCapable_ClassInfo_, allocate$IsParallelCapable);
	return class$;
}

$Class* IsParallelCapable::class$ = nullptr;