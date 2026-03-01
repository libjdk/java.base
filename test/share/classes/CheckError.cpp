#include <CheckError.h>

#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FileWriter.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintWriter.h>
#include <java/io/Writer.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FileWriter = ::java::io::FileWriter;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _CheckError_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CheckError, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckError, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _CheckError_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"CheckError",
	"java.lang.Object",
	nullptr,
	nullptr,
	_CheckError_MethodInfo_
};

$Object* allocate$CheckError($Class* clazz) {
	return $of($alloc(CheckError));
}

void CheckError::init$() {
}

void CheckError::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	bool passTest1 = false;
	$var($File, file, $new($File, $($System::getProperty("test.dir"_s, "."_s)), "junkie.out"_s));
	$var($FileWriter, fw, $new($FileWriter, file));
	$var($PrintWriter, ppw, $new($PrintWriter, static_cast<$Writer*>($$new($PrintWriter, static_cast<$Writer*>(fw)))));
	fw->close();
	ppw->println("Hello World!"_s);
	file->deleteOnExit();
	if (ppw->checkError()) {
		$nc($System::out)->println("Correct: An error occured in the underlying writer"_s);
		passTest1 = true;
	}
	ppw->close();
	$var($FileOutputStream, fos, $new($FileOutputStream, file));
	$var($PrintWriter, pps, $new($PrintWriter, static_cast<$OutputStream*>($$new($PrintStream, static_cast<$OutputStream*>(fos)))));
	fos->close();
	pps->println("Hello World!"_s);
	if (pps->checkError()) {
		$nc($System::out)->println("Correct: An error occured in the underlying Stream"_s);
	} else if (!passTest1) {
		$throwNew($Exception, "CheckError() returned an incorrect value when error occured in the underlying Stream and when error occured in the underlying writer"_s);
	} else {
		$throwNew($Exception, "CheckError() returned an incorrect value when the error has occured in the underlying Stream"_s);
	}
	if (!passTest1) {
		$throwNew($Exception, "CheckError() returned an incorrect value when the error has occured in the underlying Writer"_s);
	}
	pps->close();
}

CheckError::CheckError() {
}

$Class* CheckError::load$($String* name, bool initialize) {
	$loadClass(CheckError, name, initialize, &_CheckError_ClassInfo_, allocate$CheckError);
	return class$;
}

$Class* CheckError::class$ = nullptr;