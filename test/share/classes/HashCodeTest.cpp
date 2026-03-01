#include <HashCodeTest.h>

#include <HashCodeTest$Edge.h>
#include <HashCodeTest$Node.h>
#include <java/lang/Enum.h>
#include <java/lang/reflect/TypeVariable.h>
#include <java/util/ArrayList.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $HashCodeTest$Edge = ::HashCodeTest$Edge;
using $HashCodeTest$Node = ::HashCodeTest$Node;
using $TypeVariableArray = $Array<::java::lang::reflect::TypeVariable>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $TypeVariable = ::java::lang::reflect::TypeVariable;
using $ArrayList = ::java::util::ArrayList;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;

$MethodInfo _HashCodeTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HashCodeTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(HashCodeTest, main, void, $StringArray*)},
	{}
};

$InnerClassInfo _HashCodeTest_InnerClassesInfo_[] = {
	{"HashCodeTest$Node", "HashCodeTest", "Node", $STATIC | $INTERFACE | $ABSTRACT},
	{"HashCodeTest$Edge", "HashCodeTest", "Edge", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HashCodeTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"HashCodeTest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_HashCodeTest_MethodInfo_,
	nullptr,
	nullptr,
	_HashCodeTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"HashCodeTest$Node,HashCodeTest$Edge"
};

$Object* allocate$HashCodeTest($Class* clazz) {
	return $of($alloc(HashCodeTest));
}

void HashCodeTest::init$() {
}

void HashCodeTest::main($StringArray* argv) {
	$useLocalCurrentObjectStackCache();
	$var($List, classes, $new($ArrayList));
	$var($Set, typeVariables, $new($HashSet));
	classes->add($Class::class$);
	$load($Map);
	classes->add($Map::class$);
	$load($Enum);
	classes->add($Enum::class$);
	$load($HashCodeTest$Edge);
	classes->add($HashCodeTest$Edge::class$);
	$load($HashCodeTest$Node);
	classes->add($HashCodeTest$Node::class$);
	{
		$var($Iterator, i$, classes->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* clazz = $cast($Class, i$->next());
			{
				$nc($System::out)->println($of(clazz));
				{
					$var($TypeVariableArray, arr$, $nc(clazz)->getTypeParameters());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($TypeVariable, tv, arr$->get(i$));
						{
							int32_t hc = $nc($of(tv))->hashCode();
							typeVariables->add(tv);
							$nc($System::out)->printf("\t%s 0x%x (%d)%n"_s, $$new($ObjectArray, {
								$($of(tv->getName())),
								$($of($Integer::valueOf(hc))),
								$($of($Integer::valueOf(hc)))
							}));
						}
					}
				}
			}
		}
	}
	int32_t count = 0;
	{
		$var($Iterator, i$, classes->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* clazz = $cast($Class, i$->next());
			{
				{
					$var($TypeVariableArray, arr$, $nc(clazz)->getTypeParameters());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($TypeVariable, tv, arr$->get(i$));
						{
							if (!typeVariables->remove(tv)) {
								$throwNew($RuntimeException, $$str({"Type variable "_s, tv, " not found."_s}));
							}
						}
					}
				}
			}
		}
	}
	if (typeVariables->size() != 0) {
		$throwNew($RuntimeException, "Unexpected number of type variables."_s);
	}
}

HashCodeTest::HashCodeTest() {
}

$Class* HashCodeTest::load$($String* name, bool initialize) {
	$loadClass(HashCodeTest, name, initialize, &_HashCodeTest_ClassInfo_, allocate$HashCodeTest);
	return class$;
}

$Class* HashCodeTest::class$ = nullptr;