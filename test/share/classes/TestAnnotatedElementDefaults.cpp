#include <TestAnnotatedElementDefaults.h>

#include <AnnotatedElementDelegate.h>
#include <AssociatedDirectOnSuperClass.h>
#include <AssociatedDirectOnSuperClassContainer.h>
#include <AssociatedDirectOnSuperClassIndirectOnSubclass.h>
#include <AssociatedDirectOnSuperClassIndirectOnSubclassContainer.h>
#include <AssociatedIndirectOnSuperClassDirectOnSubclass.h>
#include <AssociatedIndirectOnSuperClassDirectOnSubclassContainer.h>
#include <DirectlyAndIndirectlyPresent.h>
#include <DirectlyAndIndirectlyPresentContainer.h>
#include <DirectlyPresent.h>
#include <IndirectlyPresent.h>
#include <IndirectlyPresentContainer.h>
#include <Missing.h>
#include <MissingRepeatable.h>
#include <TestClass1B.h>
#include <TestClass1SuperB.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/Method.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $AnnotatedElementDelegate = ::AnnotatedElementDelegate;
using $AssociatedDirectOnSuperClass = ::AssociatedDirectOnSuperClass;
using $AssociatedDirectOnSuperClassContainer = ::AssociatedDirectOnSuperClassContainer;
using $AssociatedDirectOnSuperClassIndirectOnSubclass = ::AssociatedDirectOnSuperClassIndirectOnSubclass;
using $AssociatedDirectOnSuperClassIndirectOnSubclassContainer = ::AssociatedDirectOnSuperClassIndirectOnSubclassContainer;
using $AssociatedIndirectOnSuperClassDirectOnSubclass = ::AssociatedIndirectOnSuperClassDirectOnSubclass;
using $AssociatedIndirectOnSuperClassDirectOnSubclassContainer = ::AssociatedIndirectOnSuperClassDirectOnSubclassContainer;
using $DirectlyAndIndirectlyPresent = ::DirectlyAndIndirectlyPresent;
using $DirectlyAndIndirectlyPresentContainer = ::DirectlyAndIndirectlyPresentContainer;
using $DirectlyPresent = ::DirectlyPresent;
using $IndirectlyPresent = ::IndirectlyPresent;
using $IndirectlyPresentContainer = ::IndirectlyPresentContainer;
using $Missing = ::Missing;
using $MissingRepeatable = ::MissingRepeatable;
using $TestClass1B = ::TestClass1B;
using $TestClass1SuperB = ::TestClass1SuperB;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $Method = ::java::lang::reflect::Method;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _TestAnnotatedElementDefaults_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TestAnnotatedElementDefaults, init$, void)},
	{"annotationsToTest", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Class<+Ljava/lang/annotation/Annotation;>;>;", $PRIVATE | $STATIC, $staticMethod(TestAnnotatedElementDefaults, annotationsToTest, $List*)},
	{"elementsToTest", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/reflect/AnnotatedElement;>;", $PRIVATE | $STATIC, $staticMethod(TestAnnotatedElementDefaults, elementsToTest, $List*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(TestAnnotatedElementDefaults, main, void, $StringArray*), "java.lang.SecurityException"},
	{"testNullHandling", "(LAnnotatedElementDelegate;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(TestAnnotatedElementDefaults, testNullHandling, int32_t, $AnnotatedElementDelegate*)},
	{}
};

$ClassInfo _TestAnnotatedElementDefaults_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"TestAnnotatedElementDefaults",
	"java.lang.Object",
	nullptr,
	nullptr,
	_TestAnnotatedElementDefaults_MethodInfo_
};

$Object* allocate$TestAnnotatedElementDefaults($Class* clazz) {
	return $of($alloc(TestAnnotatedElementDefaults));
}

void TestAnnotatedElementDefaults::init$() {
}

void TestAnnotatedElementDefaults::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	{
		$var($Iterator, i$, $nc($(elementsToTest()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($AnnotatedElement, annotElement, $cast($AnnotatedElement, i$->next()));
			{
				$nc($System::out)->println($of(annotElement));
				$var($AnnotatedElementDelegate, delegate, $new($AnnotatedElementDelegate, annotElement));
				failures += testNullHandling(delegate);
				{
					$var($Iterator, i$, $nc($(annotationsToTest()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$Class* annotType = $cast($Class, i$->next());
						{
							failures += $AnnotatedElementDelegate::testDelegate(delegate, annotType);
						}
					}
				}
			}
		}
	}
	if (failures > 0) {
		$nc($System::err)->printf("%d failures%n"_s, $$new($ObjectArray, {$($of($Integer::valueOf(failures)))}));
		$throwNew($RuntimeException);
	}
}

$List* TestAnnotatedElementDefaults::elementsToTest() {
	$load(TestAnnotatedElementDefaults);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, annotatedElements, $new($ArrayList));
	$load($TestClass1SuperB);
	annotatedElements->add($TestClass1SuperB::class$);
	$load($TestClass1B);
	annotatedElements->add($TestClass1B::class$);
	{
		$var($MethodArray, arr$, $TestClass1B::class$->getDeclaredMethods());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Method, method, arr$->get(i$));
			{
				annotatedElements->add(method);
			}
		}
	}
	return annotatedElements;
}

$List* TestAnnotatedElementDefaults::annotationsToTest() {
	$var($List, annotations, $new($ArrayList));
	$load($Missing);
	annotations->add($Missing::class$);
	$load($MissingRepeatable);
	annotations->add($MissingRepeatable::class$);
	$load($DirectlyPresent);
	annotations->add($DirectlyPresent::class$);
	$load($IndirectlyPresent);
	annotations->add($IndirectlyPresent::class$);
	$load($IndirectlyPresentContainer);
	annotations->add($IndirectlyPresentContainer::class$);
	$load($DirectlyAndIndirectlyPresent);
	annotations->add($DirectlyAndIndirectlyPresent::class$);
	$load($DirectlyAndIndirectlyPresentContainer);
	annotations->add($DirectlyAndIndirectlyPresentContainer::class$);
	$load($AssociatedDirectOnSuperClass);
	annotations->add($AssociatedDirectOnSuperClass::class$);
	$load($AssociatedDirectOnSuperClassContainer);
	annotations->add($AssociatedDirectOnSuperClassContainer::class$);
	$load($AssociatedDirectOnSuperClassIndirectOnSubclass);
	annotations->add($AssociatedDirectOnSuperClassIndirectOnSubclass::class$);
	$load($AssociatedDirectOnSuperClassIndirectOnSubclassContainer);
	annotations->add($AssociatedDirectOnSuperClassIndirectOnSubclassContainer::class$);
	$load($AssociatedIndirectOnSuperClassDirectOnSubclass);
	annotations->add($AssociatedIndirectOnSuperClassDirectOnSubclass::class$);
	$load($AssociatedIndirectOnSuperClassDirectOnSubclassContainer);
	annotations->add($AssociatedIndirectOnSuperClassDirectOnSubclassContainer::class$);
	return annotations;
}

int32_t TestAnnotatedElementDefaults::testNullHandling($AnnotatedElementDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	try {
		$var($Object, result, $nc(delegate)->getDeclaredAnnotationsByType(nullptr));
		++failures;
	} catch ($NullPointerException& npe) {
	}
	try {
		$var($Object, result, $nc(delegate)->getAnnotationsByType(nullptr));
		++failures;
	} catch ($NullPointerException& npe) {
	}
	try {
		$var($Object, result, $nc(delegate)->getDeclaredAnnotation(nullptr));
		++failures;
	} catch ($NullPointerException& npe) {
	}
	return failures;
}

TestAnnotatedElementDefaults::TestAnnotatedElementDefaults() {
}

$Class* TestAnnotatedElementDefaults::load$($String* name, bool initialize) {
	$loadClass(TestAnnotatedElementDefaults, name, initialize, &_TestAnnotatedElementDefaults_ClassInfo_, allocate$TestAnnotatedElementDefaults);
	return class$;
}

$Class* TestAnnotatedElementDefaults::class$ = nullptr;