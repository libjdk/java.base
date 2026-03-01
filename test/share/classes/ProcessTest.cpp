#include <ProcessTest.h>

#include <java/io/BufferedReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder.h>
#include <jcpp.h>

using $BufferedReader = ::java::io::BufferedReader;
using $IOException = ::java::io::IOException;
using $InputStreamReader = ::java::io::InputStreamReader;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process = ::java::lang::Process;
using $RuntimeException = ::java::lang::RuntimeException;

$FieldInfo _ProcessTest_FieldInfo_[] = {
	{"bldr", "Ljava/lang/ProcessBuilder;", nullptr, 0, $field(ProcessTest, bldr)},
	{"p", "Ljava/lang/Process;", nullptr, 0, $field(ProcessTest, p)},
	{}
};

$MethodInfo _ProcessTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ProcessTest, init$, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessTest, run, void)},
	{"runTest", "()V", nullptr, $PUBLIC, $virtualMethod(ProcessTest, runTest, void), "java.lang.Exception"},
	{}
};

$ClassInfo _ProcessTest_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"ProcessTest",
	"java.lang.Object",
	"java.lang.Runnable",
	_ProcessTest_FieldInfo_,
	_ProcessTest_MethodInfo_
};

$Object* allocate$ProcessTest($Class* clazz) {
	return $of($alloc(ProcessTest));
}

void ProcessTest::init$() {
}

void ProcessTest::run() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, line, nullptr);
		$var($BufferedReader, is, $new($BufferedReader, $$new($InputStreamReader, $($nc(this->p)->getInputStream()))));
		while (($assign(line, is->readLine())) != nullptr) {
			$nc($System::err)->println($$str({"ProcessTrap: "_s, line}));
		}
	} catch ($IOException& e) {
		if (!$nc($(e->getMessage()))->matches("[Ss]tream [Cc]losed"_s)) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(e));
		}
	}
}

void ProcessTest::runTest() {
	$nc(this->p)->destroyForcibly();
	$nc(this->p)->waitFor();
	if ($nc(this->p)->isAlive()) {
		$throwNew($RuntimeException, "Problem terminating the process."_s);
	}
}

ProcessTest::ProcessTest() {
}

$Class* ProcessTest::load$($String* name, bool initialize) {
	$loadClass(ProcessTest, name, initialize, &_ProcessTest_ClassInfo_, allocate$ProcessTest);
	return class$;
}

$Class* ProcessTest::class$ = nullptr;