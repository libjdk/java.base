#include <ClearErrorWriter.h>

#include <java/io/BufferedWriter.h>
#include <java/io/File.h>
#include <java/io/FileWriter.h>
#include <java/io/PrintWriter.h>
#include <java/io/Writer.h>
#include <jcpp.h>

using $BufferedWriter = ::java::io::BufferedWriter;
using $File = ::java::io::File;
using $FileWriter = ::java::io::FileWriter;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _ClearErrorWriter_MethodInfo_[] = {
	{"<init>", "(Ljava/io/Writer;Z)V", nullptr, $PUBLIC, $method(ClearErrorWriter, init$, void, $Writer*, bool)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ClearErrorWriter, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ClearErrorWriter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ClearErrorWriter",
	"java.io.PrintWriter",
	nullptr,
	nullptr,
	_ClearErrorWriter_MethodInfo_
};

$Object* allocate$ClearErrorWriter($Class* clazz) {
	return $of($alloc(ClearErrorWriter));
}

void ClearErrorWriter::init$($Writer* w, bool autoFlush) {
	$PrintWriter::init$(w, autoFlush);
}

void ClearErrorWriter::main($StringArray* args) {
	$init(ClearErrorWriter);
	$useLocalCurrentObjectStackCache();
	$var($File, f, $new($File, $($System::getProperty("test.dir"_s, "."_s)), "print-writer.out"_s));
	f->deleteOnExit();
	$var(ClearErrorWriter, out, $new(ClearErrorWriter, $$new($BufferedWriter, $$new($FileWriter, f)), true));
	out->println("Hello World!"_s);
	out->close();
	out->println("Writing after close"_s);
	if (out->checkError()) {
		$nc($System::out)->println("An error occured"_s);
		out->clearError();
		if (!out->checkError()) {
			$nc($System::out)->println("Error status cleared"_s);
		} else {
			$throwNew($Exception, "Error Status unchanged"_s);
		}
	} else {
		$nc($System::out)->println(" No error occured"_s);
	}
}

ClearErrorWriter::ClearErrorWriter() {
}

$Class* ClearErrorWriter::load$($String* name, bool initialize) {
	$loadClass(ClearErrorWriter, name, initialize, &_ClearErrorWriter_ClassInfo_, allocate$ClearErrorWriter);
	return class$;
}

$Class* ClearErrorWriter::class$ = nullptr;