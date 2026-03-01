#include <repeatingAnnotations/InheritedAssociatedAnnotations.h>

#include <java/lang/annotation/Annotation.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/util/Arrays.h>
#include <repeatingAnnotations/A3.h>
#include <repeatingAnnotations/Ann.h>
#include <repeatingAnnotations/B3.h>
#include <repeatingAnnotations/C3.h>
#include <repeatingAnnotations/D3.h>
#include <repeatingAnnotations/ExpectedAssociated.h>
#include <jcpp.h>

using $AnnArray = $Array<::repeatingAnnotations::Ann>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $Arrays = ::java::util::Arrays;
using $A3 = ::repeatingAnnotations::A3;
using $Ann = ::repeatingAnnotations::Ann;
using $B3 = ::repeatingAnnotations::B3;
using $C3 = ::repeatingAnnotations::C3;
using $D3 = ::repeatingAnnotations::D3;
using $ExpectedAssociated = ::repeatingAnnotations::ExpectedAssociated;

namespace repeatingAnnotations {

$MethodInfo _InheritedAssociatedAnnotations_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InheritedAssociatedAnnotations, init$, void)},
	{"checkAssociated", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritedAssociatedAnnotations, checkAssociated, void, $AnnotatedElement*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(InheritedAssociatedAnnotations, main, void, $StringArray*)},
	{}
};

$ClassInfo _InheritedAssociatedAnnotations_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"repeatingAnnotations.InheritedAssociatedAnnotations",
	"java.lang.Object",
	nullptr,
	nullptr,
	_InheritedAssociatedAnnotations_MethodInfo_
};

$Object* allocate$InheritedAssociatedAnnotations($Class* clazz) {
	return $of($alloc(InheritedAssociatedAnnotations));
}

void InheritedAssociatedAnnotations::init$() {
}

void InheritedAssociatedAnnotations::main($StringArray* args) {
	$load($A3);
	checkAssociated($A3::class$);
	$load($B3);
	checkAssociated($B3::class$);
	$load($C3);
	checkAssociated($C3::class$);
	$load($D3);
	checkAssociated($D3::class$);
}

void InheritedAssociatedAnnotations::checkAssociated($AnnotatedElement* ae) {
	$useLocalCurrentObjectStackCache();
	$load($Ann);
	$var($AnnArray, actual, $fcast($AnnArray, $nc(ae)->getAnnotationsByType($Ann::class$)));
	$load($ExpectedAssociated);
	$var($AnnArray, expected, $nc(($cast($ExpectedAssociated, $(ae->getAnnotation($ExpectedAssociated::class$)))))->value());
	if (!$Arrays::equals(actual, expected)) {
		$throwNew($RuntimeException, $($String::format("Test failed for %s: Expected %s but got %s."_s, $$new($ObjectArray, {
			$of(ae),
			$($of($Arrays::toString(expected))),
			$($of($Arrays::toString(actual)))
		}))));
	}
}

InheritedAssociatedAnnotations::InheritedAssociatedAnnotations() {
}

$Class* InheritedAssociatedAnnotations::load$($String* name, bool initialize) {
	$loadClass(InheritedAssociatedAnnotations, name, initialize, &_InheritedAssociatedAnnotations_ClassInfo_, allocate$InheritedAssociatedAnnotations);
	return class$;
}

$Class* InheritedAssociatedAnnotations::class$ = nullptr;

} // repeatingAnnotations