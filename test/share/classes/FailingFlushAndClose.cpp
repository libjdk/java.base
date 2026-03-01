#include <FailingFlushAndClose.h>

#include <FailingFlushAndClose$FailingCloseInputStream.h>
#include <FailingFlushAndClose$FailingCloseOutputStream.h>
#include <FailingFlushAndClose$FailingCloseReader.h>
#include <FailingFlushAndClose$FailingCloseWriter.h>
#include <FailingFlushAndClose$FailingFlushOutputStream.h>
#include <FailingFlushAndClose$FailingFlushWriter.h>
#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/BufferedReader.h>
#include <java/io/BufferedWriter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Writer.h>
#include <jcpp.h>

using $FailingFlushAndClose$FailingCloseInputStream = ::FailingFlushAndClose$FailingCloseInputStream;
using $FailingFlushAndClose$FailingCloseOutputStream = ::FailingFlushAndClose$FailingCloseOutputStream;
using $FailingFlushAndClose$FailingCloseReader = ::FailingFlushAndClose$FailingCloseReader;
using $FailingFlushAndClose$FailingCloseWriter = ::FailingFlushAndClose$FailingCloseWriter;
using $FailingFlushAndClose$FailingFlushOutputStream = ::FailingFlushAndClose$FailingFlushOutputStream;
using $FailingFlushAndClose$FailingFlushWriter = ::FailingFlushAndClose$FailingFlushWriter;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $BufferedReader = ::java::io::BufferedReader;
using $BufferedWriter = ::java::io::BufferedWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;

$FieldInfo _FailingFlushAndClose_FieldInfo_[] = {
	{"failed", "I", nullptr, $STATIC, $staticField(FailingFlushAndClose, failed)},
	{}
};

$MethodInfo _FailingFlushAndClose_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FailingFlushAndClose, init$, void)},
	{"closeAgain", "(Ljava/io/InputStream;)V", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, closeAgain, void, $InputStream*), "java.io.IOException"},
	{"closeAgain", "(Ljava/io/OutputStream;)V", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, closeAgain, void, $OutputStream*), "java.io.IOException"},
	{"closeAgain", "(Ljava/io/Reader;)Ljava/io/Reader;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, closeAgain, $Reader*, $Reader*), "java.io.IOException"},
	{"closeAgain", "(Ljava/io/Writer;)Ljava/io/Writer;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, closeAgain, $Writer*, $Writer*), "java.io.IOException"},
	{"fail", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, fail, void, $String*)},
	{"failWithIOE", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, failWithIOE, void, $String*), "java.io.IOException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(FailingFlushAndClose, main, void, $StringArray*), "java.io.IOException"},
	{"testFailingClose", "(Ljava/io/InputStream;)Ljava/io/InputStream;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, testFailingClose, $InputStream*, $InputStream*), "java.io.IOException"},
	{"testFailingClose", "(Ljava/io/OutputStream;)Ljava/io/OutputStream;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, testFailingClose, $OutputStream*, $OutputStream*), "java.io.IOException"},
	{"testFailingClose", "(Ljava/io/Reader;)Ljava/io/Reader;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, testFailingClose, $Reader*, $Reader*), "java.io.IOException"},
	{"testFailingClose", "(Ljava/io/Writer;)Ljava/io/Writer;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, testFailingClose, $Writer*, $Writer*), "java.io.IOException"},
	{"testFailingFlush", "(Ljava/io/OutputStream;)Ljava/io/OutputStream;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, testFailingFlush, $OutputStream*, $OutputStream*), "java.io.IOException"},
	{"testFailingFlush", "(Ljava/io/Writer;)Ljava/io/Writer;", nullptr, $STATIC, $staticMethod(FailingFlushAndClose, testFailingFlush, $Writer*, $Writer*), "java.io.IOException"},
	{}
};

$InnerClassInfo _FailingFlushAndClose_InnerClassesInfo_[] = {
	{"FailingFlushAndClose$FailingFlushWriter", "FailingFlushAndClose", "FailingFlushWriter", $STATIC},
	{"FailingFlushAndClose$FailingCloseWriter", "FailingFlushAndClose", "FailingCloseWriter", $STATIC},
	{"FailingFlushAndClose$FailingCloseReader", "FailingFlushAndClose", "FailingCloseReader", $STATIC},
	{"FailingFlushAndClose$FailingFlushOutputStream", "FailingFlushAndClose", "FailingFlushOutputStream", $STATIC},
	{"FailingFlushAndClose$FailingCloseOutputStream", "FailingFlushAndClose", "FailingCloseOutputStream", $STATIC},
	{"FailingFlushAndClose$FailingCloseInputStream", "FailingFlushAndClose", "FailingCloseInputStream", $STATIC},
	{}
};

$ClassInfo _FailingFlushAndClose_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"FailingFlushAndClose",
	"java.lang.Object",
	nullptr,
	_FailingFlushAndClose_FieldInfo_,
	_FailingFlushAndClose_MethodInfo_,
	nullptr,
	nullptr,
	_FailingFlushAndClose_InnerClassesInfo_,
	nullptr,
	nullptr,
	"FailingFlushAndClose$FailingFlushWriter,FailingFlushAndClose$FailingCloseWriter,FailingFlushAndClose$FailingCloseReader,FailingFlushAndClose$FailingFlushOutputStream,FailingFlushAndClose$FailingCloseOutputStream,FailingFlushAndClose$FailingCloseInputStream"
};

$Object* allocate$FailingFlushAndClose($Class* clazz) {
	return $of($alloc(FailingFlushAndClose));
}

int32_t FailingFlushAndClose::failed = 0;

void FailingFlushAndClose::init$() {
}

void FailingFlushAndClose::fail($String* msg) {
	$nc($System::err)->println($$str({"FAIL: "_s, msg}));
	$init(FailingFlushAndClose);
	++FailingFlushAndClose::failed;
}

void FailingFlushAndClose::failWithIOE($String* msg) {
	fail(msg);
	$throwNew($IOException, msg);
}

$InputStream* FailingFlushAndClose::testFailingClose($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($of($nc($of(in))->getClass()));
	$nc(in)->read($$new($bytes, 100));
	try {
		in->close();
		fail("close did not fail"_s);
	} catch ($IOException& expected) {
	}
	try {
		in->read($$new($bytes, 100));
		fail("read did not fail"_s);
	} catch ($IOException& expected) {
	}
	return in;
}

$OutputStream* FailingFlushAndClose::testFailingClose($OutputStream* out) {
	$nc($System::out)->println($of($nc($of(out))->getClass()));
	$nc(out)->write(1);
	try {
		out->close();
		fail("close did not fail"_s);
	} catch ($IOException& expected) {
	}
	try {
		out->write(1);
		if (!($instanceOf($BufferedOutputStream, out))) {
			fail("write did not fail"_s);
		}
	} catch ($IOException& expected) {
	}
	return out;
}

$OutputStream* FailingFlushAndClose::testFailingFlush($OutputStream* out) {
	$nc($System::out)->println($of($nc($of(out))->getClass()));
	$nc(out)->write(1);
	try {
		out->flush();
		fail("flush did not fail"_s);
	} catch ($IOException& expected) {
	}
	if ($instanceOf($BufferedOutputStream, out)) {
		out->write(1);
		try {
			out->close();
			fail("close did not fail"_s);
		} catch ($IOException& expected) {
		}
	}
	return out;
}

void FailingFlushAndClose::closeAgain($InputStream* in) {
	try {
		$nc(in)->close();
	} catch ($IOException& expected) {
		fail("unexpected IOException from subsequent close"_s);
	}
}

void FailingFlushAndClose::closeAgain($OutputStream* out) {
	try {
		$nc(out)->close();
	} catch ($IOException& expected) {
		fail("unexpected IOException from subsequent close"_s);
	}
}

$Reader* FailingFlushAndClose::testFailingClose($Reader* r) {
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($of($nc($of(r))->getClass()));
	$nc(r)->read($$new($chars, 100));
	try {
		r->close();
		fail("close did not fail"_s);
	} catch ($IOException& expected) {
	}
	try {
		r->read($$new($chars, 100));
		fail("read did not fail"_s);
	} catch ($IOException& expected) {
	}
	return r;
}

$Writer* FailingFlushAndClose::testFailingClose($Writer* w) {
	$nc($System::out)->println($of($nc($of(w))->getClass()));
	$nc(w)->write("message"_s);
	try {
		w->close();
		fail("close did not fail"_s);
	} catch ($IOException& expected) {
	}
	try {
		w->write("another message"_s);
		fail("write did not fail"_s);
	} catch ($IOException& expected) {
	}
	return w;
}

$Writer* FailingFlushAndClose::testFailingFlush($Writer* w) {
	$nc($System::out)->println($of($nc($of(w))->getClass()));
	$nc(w)->write("message"_s);
	try {
		w->flush();
		fail("flush did not fail"_s);
	} catch ($IOException& expected) {
	}
	if ($instanceOf($BufferedWriter, w)) {
		w->write("another message"_s);
		try {
			w->close();
			fail("close did not fail"_s);
		} catch ($IOException& expected) {
		}
	}
	return w;
}

$Reader* FailingFlushAndClose::closeAgain($Reader* r) {
	try {
		$nc(r)->close();
	} catch ($IOException& expected) {
		fail("unexpected IOException from subsequent close"_s);
	}
	return r;
}

$Writer* FailingFlushAndClose::closeAgain($Writer* w) {
	try {
		$nc(w)->close();
	} catch ($IOException& expected) {
		fail("unexpected IOException from subsequent close"_s);
	}
	return w;
}

void FailingFlushAndClose::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	closeAgain($(testFailingClose(static_cast<$InputStream*>($$new($BufferedInputStream, $$new($FailingFlushAndClose$FailingCloseInputStream))))));
	closeAgain($(testFailingClose(static_cast<$OutputStream*>($$new($BufferedOutputStream, $$new($FailingFlushAndClose$FailingCloseOutputStream))))));
	closeAgain($(testFailingClose(static_cast<$Reader*>($$new($BufferedReader, $$new($FailingFlushAndClose$FailingCloseReader))))));
	closeAgain($(testFailingClose(static_cast<$Writer*>($$new($BufferedWriter, $$new($FailingFlushAndClose$FailingCloseWriter))))));
	closeAgain($(testFailingFlush(static_cast<$OutputStream*>($$new($BufferedOutputStream, $$new($FailingFlushAndClose$FailingFlushOutputStream))))));
	closeAgain($(testFailingFlush(static_cast<$Writer*>($$new($BufferedWriter, $$new($FailingFlushAndClose$FailingFlushWriter))))));
	$init(FailingFlushAndClose);
	if (FailingFlushAndClose::failed > 0) {
		$throwNew($RuntimeException, $$str({$$str(FailingFlushAndClose::failed), " test(s) failed - see log for details"_s}));
	}
}

FailingFlushAndClose::FailingFlushAndClose() {
}

$Class* FailingFlushAndClose::load$($String* name, bool initialize) {
	$loadClass(FailingFlushAndClose, name, initialize, &_FailingFlushAndClose_ClassInfo_, allocate$FailingFlushAndClose);
	return class$;
}

$Class* FailingFlushAndClose::class$ = nullptr;