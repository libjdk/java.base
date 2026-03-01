#include <IsDefaultTest.h>

#include <ExpectedIsDefault.h>
#include <TestType1.h>
#include <TestType2$nestedTestType2.h>
#include <TestType2.h>
#include <TestType3.h>
#include <TestType4.h>
#include <TestType5$nestedTestType5.h>
#include <TestType5.h>
#include <TestType6$nestedTestType6.h>
#include <TestType6.h>
#include <TestType7.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/reflect/Method.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ExpectedIsDefault = ::ExpectedIsDefault;
using $TestType1 = ::TestType1;
using $TestType2 = ::TestType2;
using $TestType2$nestedTestType2 = ::TestType2$nestedTestType2;
using $TestType3 = ::TestType3;
using $TestType4 = ::TestType4;
using $TestType5 = ::TestType5;
using $TestType5$nestedTestType5 = ::TestType5$nestedTestType5;
using $TestType6 = ::TestType6;
using $TestType6$nestedTestType6 = ::TestType6$nestedTestType6;
using $TestType7 = ::TestType7;
using $MethodArray = $Array<::java::lang::reflect::Method>;
using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Method = ::java::lang::reflect::Method;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _IsDefaultTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(IsDefaultTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(IsDefaultTest, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _IsDefaultTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"IsDefaultTest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_IsDefaultTest_MethodInfo_
};

$Object* allocate$IsDefaultTest($Class* clazz) {
	return $of($alloc(IsDefaultTest));
}

void IsDefaultTest::init$() {
}

void IsDefaultTest::main($StringArray* argv) {
	$load(IsDefaultTest);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int32_t failures = 0;
	int32_t visitationCount = 0;
	$var($List, classList, $new($ArrayList));
	$load($TestType1);
	classList->add($TestType1::class$);
	$load($TestType2);
	classList->add($TestType2::class$);
	$load($TestType3);
	classList->add($TestType3::class$);
	$load($TestType4);
	classList->add($TestType4::class$);
	$load($TestType2$nestedTestType2);
	classList->add($TestType2$nestedTestType2::class$);
	$load($TestType5);
	classList->add($TestType5::class$);
	$load($TestType5$nestedTestType5);
	classList->add($TestType5$nestedTestType5::class$);
	$load($TestType6);
	classList->add($TestType6::class$);
	$load($TestType6$nestedTestType6);
	classList->add($TestType6$nestedTestType6::class$);
	$load($TestType7);
	classList->add($TestType7::class$);
	{
		$var($Iterator, i$, classList->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* clazz = $cast($Class, i$->next());
			{
				{
					$var($MethodArray, arr$, $nc(clazz)->getDeclaredMethods());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Method, method, arr$->get(i$));
						{
							$load($ExpectedIsDefault);
							$var($ExpectedIsDefault, expectedIsDefault, $cast($ExpectedIsDefault, $nc(method)->getAnnotation($ExpectedIsDefault::class$)));
							if (expectedIsDefault != nullptr) {
								++visitationCount;
								bool expected = expectedIsDefault->value();
								bool actual = method->isDefault();
								if (actual != expected) {
									++failures;
									$nc($System::err)->printf("ERROR: On %s expected isDefault of \'\'%s\'\'; got \'\'%s\'\'.\n"_s, $$new($ObjectArray, {
										$($of(method->toString())),
										$($of($Boolean::valueOf(expected))),
										$($of($Boolean::valueOf(actual)))
									}));
								}
							}
						}
					}
				}
			}
		}
	}
	if (visitationCount == 0) {
		$nc($System::err)->println("Test failed because no methods checked."_s);
		$throwNew($RuntimeException);
	}
	if (failures > 0) {
		$nc($System::err)->println("Test failed."_s);
		$throwNew($RuntimeException);
	}
}

IsDefaultTest::IsDefaultTest() {
}

$Class* IsDefaultTest::load$($String* name, bool initialize) {
	$loadClass(IsDefaultTest, name, initialize, &_IsDefaultTest_ClassInfo_, allocate$IsDefaultTest);
	return class$;
}

$Class* IsDefaultTest::class$ = nullptr;