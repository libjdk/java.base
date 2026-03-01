#include <RecordTest.h>

#include <Person.h>
#include <jcpp.h>

using $Person = ::Person;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _RecordTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RecordTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(RecordTest, main, void, $StringArray*)},
	{}
};

$ClassInfo _RecordTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"RecordTest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_RecordTest_MethodInfo_
};

$Object* allocate$RecordTest($Class* clazz) {
	return $of($alloc(RecordTest));
}

void RecordTest::init$() {
}

void RecordTest::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($Person, person1, $new($Person, "p1"_s, 15, 99999.0000000001));
	$var($Person, person2, $new($Person, "p2"_s, 29, 8.888888888888889E12));
	$nc($System::out)->println($(person1->name()));
	$nc($System::out)->println($of(person1));
	$nc($System::out)->println(person1->equals(person2));
}

RecordTest::RecordTest() {
}

$Class* RecordTest::load$($String* name, bool initialize) {
	$loadClass(RecordTest, name, initialize, &_RecordTest_ClassInfo_, allocate$RecordTest);
	return class$;
}

$Class* RecordTest::class$ = nullptr;