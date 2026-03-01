#include <TestParameterizedType.h>

#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Type.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Method = ::java::lang::reflect::Method;
using $Type = ::java::lang::reflect::Type;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;

$MethodInfo _TestParameterizedType_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TestParameterizedType, init$, void)},
	{"createTypes", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/reflect/Type;>;", $STATIC, $staticMethod(TestParameterizedType, createTypes, $List*), "java.lang.Exception"},
	{"genericMethod0", "()Ljava/lang/Object;", "<T:Ljava/lang/Object;>()TT;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod0, $Object*)},
	{"genericMethod1", "()Ljava/util/Set;", "<T:Ljava/lang/Object;>()Ljava/util/Set<TT;>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod1, $Set*)},
	{"genericMethod2", "()Ljava/util/Set;", "<T:Ljava/lang/Object;>()Ljava/util/Set<TT;>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod2, $Set*)},
	{"genericMethod3", "()Ljava/util/List;", "<S:Ljava/lang/Object;>()Ljava/util/List<TS;>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod3, $List*)},
	{"genericMethod4", "()Ljava/util/Map;", "<X:Ljava/lang/Object;Y:Ljava/lang/Object;>()Ljava/util/Map<TX;TY;>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod4, $Map*)},
	{"genericMethod5", "()[Ljava/lang/Object;", "<T:Ljava/lang/Object;>()[TT;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod5, $ObjectArray*)},
	{"genericMethod6", "()[Ljava/lang/Object;", "<T:Ljava/lang/Object;>()[TT;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod6, $ObjectArray*)},
	{"genericMethod7", "()Ljava/util/Set;", "()Ljava/util/Set<+Ljava/lang/Cloneable;>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod7, $Set*)},
	{"genericMethod8", "()Ljava/util/Set;", "()Ljava/util/Set<-Ljava/lang/Number;>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod8, $Set*)},
	{"genericMethod9", "()Ljava/util/Set;", "()Ljava/util/Set<*>;", $PUBLIC, $virtualMethod(TestParameterizedType, genericMethod9, $Set*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(TestParameterizedType, main, void, $StringArray*), "java.lang.Exception"},
	{"testReflexes", "(Ljava/util/List;)Z", "(Ljava/util/List<Ljava/lang/reflect/Type;>;)Z", $STATIC, $staticMethod(TestParameterizedType, testReflexes, bool, $List*)},
	{}
};

$ClassInfo _TestParameterizedType_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"TestParameterizedType",
	"java.lang.Object",
	nullptr,
	nullptr,
	_TestParameterizedType_MethodInfo_
};

$Object* allocate$TestParameterizedType($Class* clazz) {
	return $of($alloc(TestParameterizedType));
}

void TestParameterizedType::init$() {
}

$Object* TestParameterizedType::genericMethod0() {
	return $of(nullptr);
}

$Set* TestParameterizedType::genericMethod1() {
	return nullptr;
}

$Set* TestParameterizedType::genericMethod2() {
	return nullptr;
}

$List* TestParameterizedType::genericMethod3() {
	return nullptr;
}

$Map* TestParameterizedType::genericMethod4() {
	return nullptr;
}

$ObjectArray* TestParameterizedType::genericMethod5() {
	return nullptr;
}

$ObjectArray* TestParameterizedType::genericMethod6() {
	return nullptr;
}

$Set* TestParameterizedType::genericMethod7() {
	return nullptr;
}

$Set* TestParameterizedType::genericMethod8() {
	return nullptr;
}

$Set* TestParameterizedType::genericMethod9() {
	return nullptr;
}

$List* TestParameterizedType::createTypes() {
	$load(TestParameterizedType);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, typeList, $new($ArrayList, 3));
	$var($StringArray, methodNames, $new($StringArray, {
		"genericMethod0"_s,
		"genericMethod1"_s,
		"genericMethod2"_s,
		"genericMethod3"_s,
		"genericMethod4"_s,
		"genericMethod5"_s,
		"genericMethod6"_s,
		"genericMethod7"_s,
		"genericMethod8"_s,
		"genericMethod9"_s
	}));
	{
		$var($StringArray, arr$, methodNames);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			{
				$var($Type, t, $nc($(TestParameterizedType::class$->getDeclaredMethod(s, $$new($ClassArray, 0))))->getGenericReturnType());
				typeList->add(t);
			}
		}
	}
	return typeList;
}

bool TestParameterizedType::testReflexes($List* typeList) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(typeList)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Type, t, $cast($Type, i$->next()));
			{
				if (!$nc($of(t))->equals(t)) {
					$nc($System::err)->printf("Bad reflexes for%s %s%n"_s, $$new($ObjectArray, {
						$of(t),
						$of($of(t)->getClass())
					}));
					return true;
				}
			}
		}
	}
	return false;
}

void TestParameterizedType::main($StringArray* argv) {
	$useLocalCurrentObjectStackCache();
	bool failed = false;
	$var($List, take1, createTypes());
	$var($List, take2, createTypes());
	failed = failed | testReflexes(take1);
	failed = failed | testReflexes(take2);
	for (int32_t i = 0; i < $nc(take1)->size(); ++i) {
		$var($Type, type1, $cast($Type, take1->get(i)));
		for (int32_t j = 0; j < $nc(take2)->size(); ++j) {
			$var($Type, type2, $cast($Type, take2->get(j)));
			if (i == j) {
				if (!$nc($of(type1))->equals(type2)) {
					failed = true;
					$nc($System::err)->printf("Unexpected inequality: [%d, %d] %n\t%s%n\t%s%n"_s, $$new($ObjectArray, {
						$($of($Integer::valueOf(i))),
						$($of($Integer::valueOf(j))),
						$of(type1),
						$of(type2)
					}));
				}
			} else if ($nc($of(type1))->equals(type2)) {
				failed = true;
				$nc($System::err)->printf("Unexpected equality: [%d, %d] %n\t%s%n\t%s%n"_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(i))),
					$($of($Integer::valueOf(j))),
					$of(type1),
					$of(type2)
				}));
			}
		}
	}
	if (failed) {
		$throwNew($RuntimeException, "Bad equality on ParameterizedTypes"_s);
	}
}

TestParameterizedType::TestParameterizedType() {
}

$Class* TestParameterizedType::load$($String* name, bool initialize) {
	$loadClass(TestParameterizedType, name, initialize, &_TestParameterizedType_ClassInfo_, allocate$TestParameterizedType);
	return class$;
}

$Class* TestParameterizedType::class$ = nullptr;