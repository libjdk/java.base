#include <OversynchronizedTest.h>

#include <TestObj.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintWriter.h>
#include <jcpp.h>

using $TestObj = ::TestObj;
using $OversynchronizedTestArray = $Array<OversynchronizedTest>;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

$FieldInfo _OversynchronizedTest_FieldInfo_[] = {
	{"writer", "Ljava/io/PrintWriter;", nullptr, $PRIVATE | $STATIC, $staticField(OversynchronizedTest, writer)},
	{"testObj", "LTestObj;", nullptr, $PRIVATE | $STATIC, $staticField(OversynchronizedTest, testObj)},
	{"loopNum", "I", nullptr, $PRIVATE | $STATIC, $staticField(OversynchronizedTest, loopNum)},
	{}
};

$MethodInfo _OversynchronizedTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(OversynchronizedTest, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(OversynchronizedTest, main, void, $StringArray*), "java.lang.Exception"},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(OversynchronizedTest, run, void)},
	{}
};

$ClassInfo _OversynchronizedTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"OversynchronizedTest",
	"java.lang.Thread",
	nullptr,
	_OversynchronizedTest_FieldInfo_,
	_OversynchronizedTest_MethodInfo_
};

$Object* allocate$OversynchronizedTest($Class* clazz) {
	return $of($alloc(OversynchronizedTest));
}

$PrintWriter* OversynchronizedTest::writer = nullptr;
$TestObj* OversynchronizedTest::testObj = nullptr;
int32_t OversynchronizedTest::loopNum = 0;

void OversynchronizedTest::init$() {
	$Thread::init$();
}

void OversynchronizedTest::run() {
	for (int32_t i = 0; i < OversynchronizedTest::loopNum; ++i) {
		$nc(OversynchronizedTest::testObj)->test();
		$nc(OversynchronizedTest::writer)->println($of(OversynchronizedTest::testObj));
	}
}

void OversynchronizedTest::main($StringArray* args) {
	$init(OversynchronizedTest);
	$useLocalCurrentObjectStackCache();
	$nc(OversynchronizedTest::writer)->println(($Object*)nullptr);
	int32_t num = 5;
	$var($OversynchronizedTestArray, t, $new($OversynchronizedTestArray, num));
	for (int32_t i = 0; i < num; ++i) {
		t->set(i, $$new(OversynchronizedTest));
		$nc(t->get(i))->start();
	}
	for (int32_t i = 0; i < num; ++i) {
		$nc(t->get(i))->join();
	}
	$nc($System::out)->println("Test completed"_s);
}

void clinit$OversynchronizedTest($Class* class$) {
	$assignStatic(OversynchronizedTest::writer, $new($PrintWriter, static_cast<$OutputStream*>($System::out)));
	$assignStatic(OversynchronizedTest::testObj, $new($TestObj, "This is a test."_s, OversynchronizedTest::writer));
	OversynchronizedTest::loopNum = 100;
}

OversynchronizedTest::OversynchronizedTest() {
}

$Class* OversynchronizedTest::load$($String* name, bool initialize) {
	$loadClass(OversynchronizedTest, name, initialize, &_OversynchronizedTest_ClassInfo_, clinit$OversynchronizedTest, allocate$OversynchronizedTest);
	return class$;
}

$Class* OversynchronizedTest::class$ = nullptr;