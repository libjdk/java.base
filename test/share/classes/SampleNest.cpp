#include <SampleNest.h>

#include <SampleNest$1.h>
#include <SampleNest$1LocalClass.h>
#include <java/lang/Runnable.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <jcpp.h>

using $SampleNest$1 = ::SampleNest$1;
using $SampleNest$1LocalClass = ::SampleNest$1LocalClass;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;

$FieldInfo _SampleNest_FieldInfo_[] = {
	{"_nestedTypes", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Class<*>;>;", $STATIC, $staticField(SampleNest, _nestedTypes)},
	{}
};

$MethodInfo _SampleNest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SampleNest, init$, void)},
	{"gather", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $STATIC, $staticMethod(SampleNest, gather, void, $Class*)},
	{"nestedTypes", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(SampleNest, nestedTypes, $ClassArray*)},
	{}
};

$InnerClassInfo _SampleNest_InnerClassesInfo_[] = {
	{"SampleNest$DeepNest1", "SampleNest", "DeepNest1", $STATIC},
	{"SampleNest$InnerIface", "SampleNest", "InnerIface", $STATIC | $INTERFACE | $ABSTRACT},
	{"SampleNest$InnerClass", "SampleNest", "InnerClass", 0},
	{"SampleNest$StaticIface", "SampleNest", "StaticIface", $STATIC | $INTERFACE | $ABSTRACT},
	{"SampleNest$StaticClass", "SampleNest", "StaticClass", $STATIC},
	{"SampleNest$1", nullptr, nullptr, 0},
	{"SampleNest$1LocalClass", nullptr, "LocalClass", 0},
	{}
};

$ClassInfo _SampleNest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"SampleNest",
	"java.lang.Object",
	nullptr,
	_SampleNest_FieldInfo_,
	_SampleNest_MethodInfo_,
	nullptr,
	nullptr,
	_SampleNest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"SampleNest$DeepNest1,SampleNest$DeepNest1$DeepNest2,SampleNest$DeepNest1$DeepNest2$DeepNest3,SampleNest$InnerIface,SampleNest$InnerClass,SampleNest$StaticIface,SampleNest$StaticClass,SampleNest$1,SampleNest$1LocalClass"
};

$Object* allocate$SampleNest($Class* clazz) {
	return $of($alloc(SampleNest));
}

$List* SampleNest::_nestedTypes = nullptr;

void SampleNest::gather($Class* c) {
	$init(SampleNest);
	$beforeCallerSensitive();
	$nc(SampleNest::_nestedTypes)->add(c);
	{
		$var($ClassArray, arr$, $nc(c)->getDeclaredClasses());
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* d = arr$->get(i$);
			{
				gather(d);
			}
		}
	}
}

$ClassArray* SampleNest::nestedTypes() {
	$init(SampleNest);
	return $fcast($ClassArray, $nc(SampleNest::_nestedTypes)->toArray($$new($ClassArray, 0)));
}

void SampleNest::init$() {
	{
	}
	$load($SampleNest$1LocalClass);
	$nc(SampleNest::_nestedTypes)->add($SampleNest$1LocalClass::class$);
	$var($Runnable, r, $new($SampleNest$1, this));
	r->run();
}

void clinit$SampleNest($Class* class$) {
	$assignStatic(SampleNest::_nestedTypes, $new($LinkedList));
	{
		SampleNest::gather(SampleNest::class$);
		$var(SampleNest, s, $new(SampleNest));
	}
}

SampleNest::SampleNest() {
}

$Class* SampleNest::load$($String* name, bool initialize) {
	$loadClass(SampleNest, name, initialize, &_SampleNest_ClassInfo_, clinit$SampleNest, allocate$SampleNest);
	return class$;
}

$Class* SampleNest::class$ = nullptr;