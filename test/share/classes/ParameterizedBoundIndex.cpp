#include <ParameterizedBoundIndex.h>

#include <ParameterizedBoundIndex$ConstructorClassBound.h>
#include <ParameterizedBoundIndex$ConstructorInterfaceBound.h>
#include <ParameterizedBoundIndex$ConstructorParameterizedClassBound.h>
#include <ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound.h>
#include <ParameterizedBoundIndex$ConstructorVariableBound.h>
#include <ParameterizedBoundIndex$MethodClassBound.h>
#include <ParameterizedBoundIndex$MethodInterfaceBound.h>
#include <ParameterizedBoundIndex$MethodParameterizedClassBound.h>
#include <ParameterizedBoundIndex$MethodParameterizedInterfaceBound.h>
#include <ParameterizedBoundIndex$MethodVariableBound.h>
#include <ParameterizedBoundIndex$TypeAnnotation.h>
#include <ParameterizedBoundIndex$TypeClassBound.h>
#include <ParameterizedBoundIndex$TypeInterfaceBound.h>
#include <ParameterizedBoundIndex$TypeParameterizedClassBound.h>
#include <ParameterizedBoundIndex$TypeParameterizedInterfaceBound.h>
#include <ParameterizedBoundIndex$TypeVariableBound.h>
#include <java/lang/reflect/AnnotatedType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ParameterizedBoundIndex$ConstructorClassBound = ::ParameterizedBoundIndex$ConstructorClassBound;
using $ParameterizedBoundIndex$ConstructorInterfaceBound = ::ParameterizedBoundIndex$ConstructorInterfaceBound;
using $ParameterizedBoundIndex$ConstructorParameterizedClassBound = ::ParameterizedBoundIndex$ConstructorParameterizedClassBound;
using $ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound = ::ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound;
using $ParameterizedBoundIndex$ConstructorVariableBound = ::ParameterizedBoundIndex$ConstructorVariableBound;
using $ParameterizedBoundIndex$MethodClassBound = ::ParameterizedBoundIndex$MethodClassBound;
using $ParameterizedBoundIndex$MethodInterfaceBound = ::ParameterizedBoundIndex$MethodInterfaceBound;
using $ParameterizedBoundIndex$MethodParameterizedClassBound = ::ParameterizedBoundIndex$MethodParameterizedClassBound;
using $ParameterizedBoundIndex$MethodParameterizedInterfaceBound = ::ParameterizedBoundIndex$MethodParameterizedInterfaceBound;
using $ParameterizedBoundIndex$MethodVariableBound = ::ParameterizedBoundIndex$MethodVariableBound;
using $ParameterizedBoundIndex$TypeAnnotation = ::ParameterizedBoundIndex$TypeAnnotation;
using $ParameterizedBoundIndex$TypeClassBound = ::ParameterizedBoundIndex$TypeClassBound;
using $ParameterizedBoundIndex$TypeInterfaceBound = ::ParameterizedBoundIndex$TypeInterfaceBound;
using $ParameterizedBoundIndex$TypeParameterizedClassBound = ::ParameterizedBoundIndex$TypeParameterizedClassBound;
using $ParameterizedBoundIndex$TypeParameterizedInterfaceBound = ::ParameterizedBoundIndex$TypeParameterizedInterfaceBound;
using $ParameterizedBoundIndex$TypeVariableBound = ::ParameterizedBoundIndex$TypeVariableBound;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AnnotatedType = ::java::lang::reflect::AnnotatedType;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $TypeVariable = ::java::lang::reflect::TypeVariable;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

$MethodInfo _ParameterizedBoundIndex_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ParameterizedBoundIndex, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ParameterizedBoundIndex, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _ParameterizedBoundIndex_InnerClassesInfo_[] = {
	{"ParameterizedBoundIndex$ConstructorVariableBound", "ParameterizedBoundIndex", "ConstructorVariableBound", $STATIC},
	{"ParameterizedBoundIndex$ConstructorParameterizedClassBound", "ParameterizedBoundIndex", "ConstructorParameterizedClassBound", $STATIC},
	{"ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound", "ParameterizedBoundIndex", "ConstructorParameterizedInterfaceBound", $STATIC},
	{"ParameterizedBoundIndex$ConstructorInterfaceBound", "ParameterizedBoundIndex", "ConstructorInterfaceBound", $STATIC},
	{"ParameterizedBoundIndex$ConstructorClassBound", "ParameterizedBoundIndex", "ConstructorClassBound", $STATIC},
	{"ParameterizedBoundIndex$MethodVariableBound", "ParameterizedBoundIndex", "MethodVariableBound", $STATIC},
	{"ParameterizedBoundIndex$MethodParameterizedClassBound", "ParameterizedBoundIndex", "MethodParameterizedClassBound", $STATIC},
	{"ParameterizedBoundIndex$MethodParameterizedInterfaceBound", "ParameterizedBoundIndex", "MethodParameterizedInterfaceBound", $STATIC},
	{"ParameterizedBoundIndex$MethodInterfaceBound", "ParameterizedBoundIndex", "MethodInterfaceBound", $STATIC},
	{"ParameterizedBoundIndex$MethodClassBound", "ParameterizedBoundIndex", "MethodClassBound", $STATIC},
	{"ParameterizedBoundIndex$TypeVariableBound", "ParameterizedBoundIndex", "TypeVariableBound", $STATIC},
	{"ParameterizedBoundIndex$TypeParameterizedClassBound", "ParameterizedBoundIndex", "TypeParameterizedClassBound", $STATIC},
	{"ParameterizedBoundIndex$TypeParameterizedInterfaceBound", "ParameterizedBoundIndex", "TypeParameterizedInterfaceBound", $STATIC},
	{"ParameterizedBoundIndex$TypeInterfaceBound", "ParameterizedBoundIndex", "TypeInterfaceBound", $STATIC},
	{"ParameterizedBoundIndex$TypeClassBound", "ParameterizedBoundIndex", "TypeClassBound", $STATIC},
	{"ParameterizedBoundIndex$TypeAnnotation", "ParameterizedBoundIndex", "TypeAnnotation", $STATIC | $INTERFACE | $ABSTRACT | $ANNOTATION},
	{}
};

$ClassInfo _ParameterizedBoundIndex_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ParameterizedBoundIndex",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ParameterizedBoundIndex_MethodInfo_,
	nullptr,
	nullptr,
	_ParameterizedBoundIndex_InnerClassesInfo_,
	nullptr,
	nullptr,
	"ParameterizedBoundIndex$ConstructorVariableBound,ParameterizedBoundIndex$ConstructorParameterizedClassBound,ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound,ParameterizedBoundIndex$ConstructorInterfaceBound,ParameterizedBoundIndex$ConstructorClassBound,ParameterizedBoundIndex$MethodVariableBound,ParameterizedBoundIndex$MethodParameterizedClassBound,ParameterizedBoundIndex$MethodParameterizedInterfaceBound,ParameterizedBoundIndex$MethodInterfaceBound,ParameterizedBoundIndex$MethodClassBound,ParameterizedBoundIndex$TypeVariableBound,ParameterizedBoundIndex$TypeParameterizedClassBound,ParameterizedBoundIndex$TypeParameterizedInterfaceBound,ParameterizedBoundIndex$TypeInterfaceBound,ParameterizedBoundIndex$TypeClassBound,ParameterizedBoundIndex$TypeAnnotation"
};

$Object* allocate$ParameterizedBoundIndex($Class* clazz) {
	return $of($alloc(ParameterizedBoundIndex));
}

void ParameterizedBoundIndex::init$() {
}

void ParameterizedBoundIndex::main($StringArray* args) {
	$load(ParameterizedBoundIndex);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, failed, $new($ArrayList));
	$load($ParameterizedBoundIndex$TypeClassBound);
	$load($ParameterizedBoundIndex$TypeAnnotation);
	if (!$nc($nc($($nc($nc($($ParameterizedBoundIndex$TypeClassBound::class$->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$TypeClassBound::class$);
	}
	$load($ParameterizedBoundIndex$TypeInterfaceBound);
	if (!$nc($nc($($nc($nc($($ParameterizedBoundIndex$TypeInterfaceBound::class$->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$TypeInterfaceBound::class$);
	}
	$load($ParameterizedBoundIndex$TypeParameterizedInterfaceBound);
	if (!$nc($nc($($nc($nc($($ParameterizedBoundIndex$TypeParameterizedInterfaceBound::class$->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$TypeParameterizedInterfaceBound::class$);
	}
	$load($ParameterizedBoundIndex$TypeParameterizedClassBound);
	if (!$nc($nc($($nc($nc($($ParameterizedBoundIndex$TypeParameterizedClassBound::class$->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$TypeParameterizedClassBound::class$);
	}
	$load($ParameterizedBoundIndex$TypeVariableBound);
	if (!$nc($nc($($nc($nc($($ParameterizedBoundIndex$TypeVariableBound::class$->getTypeParameters()))->get(1))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$TypeVariableBound::class$);
	}
	$load($ParameterizedBoundIndex$MethodClassBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$MethodClassBound::class$->getDeclaredMethod("m"_s, $$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$MethodClassBound::class$);
	}
	$load($ParameterizedBoundIndex$MethodInterfaceBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$MethodInterfaceBound::class$->getDeclaredMethod("m"_s, $$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$MethodInterfaceBound::class$);
	}
	$load($ParameterizedBoundIndex$MethodParameterizedInterfaceBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$MethodParameterizedInterfaceBound::class$->getDeclaredMethod("m"_s, $$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$MethodParameterizedInterfaceBound::class$);
	}
	$load($ParameterizedBoundIndex$MethodParameterizedClassBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$MethodParameterizedClassBound::class$->getDeclaredMethod("m"_s, $$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$MethodParameterizedClassBound::class$);
	}
	$load($ParameterizedBoundIndex$MethodVariableBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$MethodVariableBound::class$->getDeclaredMethod("m"_s, $$new($ClassArray, 0))))->getTypeParameters()))->get(1))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$MethodVariableBound::class$);
	}
	$load($ParameterizedBoundIndex$ConstructorClassBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$ConstructorClassBound::class$->getDeclaredConstructor($$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$ConstructorClassBound::class$);
	}
	$load($ParameterizedBoundIndex$ConstructorInterfaceBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$ConstructorInterfaceBound::class$->getDeclaredConstructor($$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$ConstructorInterfaceBound::class$);
	}
	$load($ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound::class$->getDeclaredConstructor($$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$ConstructorParameterizedInterfaceBound::class$);
	}
	$load($ParameterizedBoundIndex$ConstructorParameterizedClassBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$ConstructorParameterizedClassBound::class$->getDeclaredConstructor($$new($ClassArray, 0))))->getTypeParameters()))->get(0))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$ConstructorParameterizedClassBound::class$);
	}
	$load($ParameterizedBoundIndex$ConstructorVariableBound);
	if (!$nc($nc($($nc($nc($($nc($($ParameterizedBoundIndex$ConstructorVariableBound::class$->getDeclaredConstructor($$new($ClassArray, 0))))->getTypeParameters()))->get(1))->getAnnotatedBounds()))->get(0))->isAnnotationPresent($ParameterizedBoundIndex$TypeAnnotation::class$)) {
		failed->add($ParameterizedBoundIndex$ConstructorVariableBound::class$);
	}
	if (!failed->isEmpty()) {
		$throwNew($RuntimeException, $$str({"Failed: "_s, failed}));
	}
}

ParameterizedBoundIndex::ParameterizedBoundIndex() {
}

$Class* ParameterizedBoundIndex::load$($String* name, bool initialize) {
	$loadClass(ParameterizedBoundIndex, name, initialize, &_ParameterizedBoundIndex_ClassInfo_, allocate$ParameterizedBoundIndex);
	return class$;
}

$Class* ParameterizedBoundIndex::class$ = nullptr;