#include <Basic4Appendable.h>

#include <Basic4Appendable$1.h>
#include <Basic4Appendable$10.h>
#include <Basic4Appendable$2.h>
#include <Basic4Appendable$3.h>
#include <Basic4Appendable$4.h>
#include <Basic4Appendable$5.h>
#include <Basic4Appendable$6.h>
#include <Basic4Appendable$7.h>
#include <Basic4Appendable$8.h>
#include <Basic4Appendable$9.h>
#include <BasicRunnable.h>
#include <java/io/BufferedWriter.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/CharArrayWriter.h>
#include <java/io/File.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/PrintWriter.h>
#include <java/io/StringWriter.h>
#include <java/io/Writer.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/StringBuffer.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <jcpp.h>

using $Basic4Appendable$1 = ::Basic4Appendable$1;
using $Basic4Appendable$10 = ::Basic4Appendable$10;
using $Basic4Appendable$2 = ::Basic4Appendable$2;
using $Basic4Appendable$3 = ::Basic4Appendable$3;
using $Basic4Appendable$4 = ::Basic4Appendable$4;
using $Basic4Appendable$5 = ::Basic4Appendable$5;
using $Basic4Appendable$6 = ::Basic4Appendable$6;
using $Basic4Appendable$7 = ::Basic4Appendable$7;
using $Basic4Appendable$8 = ::Basic4Appendable$8;
using $Basic4Appendable$9 = ::Basic4Appendable$9;
using $BasicRunnable = ::BasicRunnable;
using $CharSequenceArray = $Array<::java::lang::CharSequence>;
using $intArray2 = $Array<int32_t, 2>;
using $ObjectArray2 = $Array<::java::lang::Object, 2>;
using $BufferedWriter = ::java::io::BufferedWriter;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $CharArrayWriter = ::java::io::CharArrayWriter;
using $File = ::java::io::File;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $StringWriter = ::java::io::StringWriter;
using $Writer = ::java::io::Writer;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;

$FieldInfo _Basic4Appendable_FieldInfo_[] = {
	{"s", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Basic4Appendable, s)},
	{"gw", "Ljava/io/CharArrayWriter;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, gw)},
	{"gos", "Ljava/io/ByteArrayOutputStream;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, gos)},
	{"gf", "Ljava/io/File;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, gf)},
	{"fail", "I", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, fail$)},
	{"pass", "I", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, pass$)},
	{"first", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, first)},
	{"testBufferedWriter", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testBufferedWriter)},
	{"testCharArrayWriter", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testCharArrayWriter)},
	{"testFileWriter", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testFileWriter)},
	{"testOutputStreamWriter", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testOutputStreamWriter)},
	{"testPrintWriter", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testPrintWriter)},
	{"testStringWriter", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testStringWriter)},
	{"testPrintStream", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testPrintStream)},
	{"testCharBuffer", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testCharBuffer)},
	{"testStringBuffer", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testStringBuffer)},
	{"testStringBuilder", "LBasicRunnable;", nullptr, $PRIVATE | $STATIC, $staticField(Basic4Appendable, testStringBuilder)},
	{}
};

$MethodInfo _Basic4Appendable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Basic4Appendable, init$, void)},
	{"ck", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Basic4Appendable, ck, void, $String*, $String*, $String*)},
	{"fail", "(Ljava/lang/Throwable;)V", nullptr, $STATIC, $staticMethod(Basic4Appendable, fail, void, $Throwable*)},
	{"fail", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $STATIC, $staticMethod(Basic4Appendable, fail, void, $String*, $Throwable*)},
	{"fail", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Basic4Appendable, fail, void, $String*, $String*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Basic4Appendable, main, void, $StringArray*), "java.lang.Exception"},
	{"newFile", "()Ljava/io/File;", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Appendable, newFile, $File*)},
	{"pass", "()V", nullptr, $STATIC, $staticMethod(Basic4Appendable, pass, void)},
	{"test", "(Ljava/lang/Appendable;Ljava/lang/CharSequence;LBasicRunnable;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Basic4Appendable, test, void, $Appendable*, $CharSequence*, $BasicRunnable*)},
	{}
};

$InnerClassInfo _Basic4Appendable_InnerClassesInfo_[] = {
	{"Basic4Appendable$10", nullptr, nullptr, 0},
	{"Basic4Appendable$9", nullptr, nullptr, 0},
	{"Basic4Appendable$8", nullptr, nullptr, 0},
	{"Basic4Appendable$7", nullptr, nullptr, 0},
	{"Basic4Appendable$6", nullptr, nullptr, 0},
	{"Basic4Appendable$5", nullptr, nullptr, 0},
	{"Basic4Appendable$4", nullptr, nullptr, 0},
	{"Basic4Appendable$3", nullptr, nullptr, 0},
	{"Basic4Appendable$2", nullptr, nullptr, 0},
	{"Basic4Appendable$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Basic4Appendable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Basic4Appendable",
	"java.lang.Object",
	nullptr,
	_Basic4Appendable_FieldInfo_,
	_Basic4Appendable_MethodInfo_,
	nullptr,
	nullptr,
	_Basic4Appendable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Basic4Appendable$10,Basic4Appendable$9,Basic4Appendable$8,Basic4Appendable$7,Basic4Appendable$6,Basic4Appendable$5,Basic4Appendable$4,Basic4Appendable$3,Basic4Appendable$2,Basic4Appendable$1"
};

$Object* allocate$Basic4Appendable($Class* clazz) {
	return $of($alloc(Basic4Appendable));
}

$String* Basic4Appendable::s = nullptr;
$CharArrayWriter* Basic4Appendable::gw = nullptr;
$ByteArrayOutputStream* Basic4Appendable::gos = nullptr;
$File* Basic4Appendable::gf = nullptr;
int32_t Basic4Appendable::fail$ = 0;
int32_t Basic4Appendable::pass$ = 0;
$Throwable* Basic4Appendable::first = nullptr;
$BasicRunnable* Basic4Appendable::testBufferedWriter = nullptr;
$BasicRunnable* Basic4Appendable::testCharArrayWriter = nullptr;
$BasicRunnable* Basic4Appendable::testFileWriter = nullptr;
$BasicRunnable* Basic4Appendable::testOutputStreamWriter = nullptr;
$BasicRunnable* Basic4Appendable::testPrintWriter = nullptr;
$BasicRunnable* Basic4Appendable::testStringWriter = nullptr;
$BasicRunnable* Basic4Appendable::testPrintStream = nullptr;
$BasicRunnable* Basic4Appendable::testCharBuffer = nullptr;
$BasicRunnable* Basic4Appendable::testStringBuffer = nullptr;
$BasicRunnable* Basic4Appendable::testStringBuilder = nullptr;

void Basic4Appendable::init$() {
}

$File* Basic4Appendable::newFile() {
	$init(Basic4Appendable);
	$var($File, f, nullptr);
	try {
		$assign(f, $File::createTempFile("append"_s, ".txt"_s));
		$nc(f)->deleteOnExit();
	} catch ($IOException& x) {
		fail(x);
	}
	return f;
}

void Basic4Appendable::pass() {
	$init(Basic4Appendable);
	++Basic4Appendable::pass$;
}

void Basic4Appendable::fail($Throwable* ex) {
	$init(Basic4Appendable);
	if (Basic4Appendable::first == nullptr) {
		$assignStatic(Basic4Appendable::first, ex);
	}
	$nc($System::err)->println("FAILED: unexpected exception"_s);
	++Basic4Appendable::fail$;
}

void Basic4Appendable::fail($String* fs, $Throwable* ex) {
	$init(Basic4Appendable);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $str({"\'"_s, fs, "\': "_s, $($nc($of(ex))->getClass()->getName()), " not thrown"_s}));
	if (Basic4Appendable::first == nullptr) {
		$assignStatic(Basic4Appendable::first, ex);
	}
	$nc($System::err)->println($$str({"FAILED: "_s, s}));
	++Basic4Appendable::fail$;
}

void Basic4Appendable::fail($String* fs, $String* exp, $String* got) {
	$init(Basic4Appendable);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $str({"\'"_s, fs, "\': Expected \'"_s, exp, "\', got \'"_s, got, "\'"_s}));
	if (Basic4Appendable::first == nullptr) {
		$assignStatic(Basic4Appendable::first, $new($RuntimeException, s));
	}
	$nc($System::err)->println($$str({"FAILED: "_s, s}));
	++Basic4Appendable::fail$;
}

void Basic4Appendable::ck($String* s, $String* exp, $String* got) {
	$init(Basic4Appendable);
	if (!$nc(exp)->equals(got)) {
		fail(s, exp, got);
	} else {
		pass();
	}
}

void Basic4Appendable::test($Appendable* a$renamed, $CharSequence* csq, $BasicRunnable* thunk) {
	$init(Basic4Appendable);
	$useLocalCurrentObjectStackCache();
	$var($Appendable, a, a$renamed);
	$var($intArray2, sp, $new($intArray2, {
		$$new($ints, {
			0,
			0
		}),
		$$new($ints, {
			11,
			11
		}),
		$$new($ints, {
			11,
			21
		}),
		$$new($ints, {
			0,
			7
		}),
		$$new($ints, {
			0,
			$nc(Basic4Appendable::s)->length()
		}),
		$$new($ints, {
			$nc(Basic4Appendable::s)->length(),
			$nc(Basic4Appendable::s)->length()
		})
	}));
	for (int32_t j = 0; j < sp->length; ++j) {
		int32_t start = $nc(sp->get(j))->get(0);
		int32_t end = $nc(sp->get(j))->get(1);
		try {
			$var($Appendable, var$0, $nc(a)->append(csq, start, end));
			$var($String, var$1, $nc($of(csq))->getClass()->getName());
			$nc(thunk)->init(var$0, var$1, $($($nc(Basic4Appendable::s)->subSequence(start, end))->toString()));
			thunk->run();
			$assign(a, thunk->reset(a));
		} catch ($IOException& x) {
			fail(x);
		}
	}
	$var($intArray2, sf, $new($intArray2, {
		$$new($ints, {
			-1,
			0
		}),
		$$new($ints, {
			0,
			-1
		}),
		$$new($ints, {
			11,
			10
		}),
		$$new($ints, {
			0,
			$nc(Basic4Appendable::s)->length() + 1
		})
	}));
	for (int32_t j = 0; j < sf->length; ++j) {
		int32_t start = $nc(sf->get(j))->get(0);
		int32_t end = $nc(sf->get(j))->get(1);
		try {
			$nc(a)->append(csq, start, end);
			fail($$str({"start = "_s, $$str(start), ", end = "_s, $$str(end)}), $$new($IndexOutOfBoundsException));
			$assign(a, $nc(thunk)->reset(a));
		} catch ($IndexOutOfBoundsException& x) {
			pass();
		} catch ($IOException& x) {
			fail(x);
		}
	}
	int32_t start = 1;
	int32_t end = 2;
	try {
		$var($Appendable, var$2, $nc(a)->append(nullptr, start, end));
		$var($String, var$3, "null"_s);
		$nc(thunk)->init(var$2, var$3, $($("null"_s->subSequence(start, end))->toString()));
		thunk->run();
		$assign(a, thunk->reset(a));
	} catch ($IOException& x) {
		fail(x);
	}
}

void Basic4Appendable::main($StringArray* args) {
	$init(Basic4Appendable);
	$useLocalCurrentObjectStackCache();
	$var($CharBuffer, cb, $nc($($CharBuffer::allocate(128)))->put(Basic4Appendable::s));
	$nc($($nc(cb)->limit($nc(Basic4Appendable::s)->length())))->rewind();
	$var($CharBuffer, dcb, $nc($($nc($($ByteBuffer::allocateDirect(128)))->asCharBuffer()))->put(Basic4Appendable::s));
	$nc($($nc(dcb)->limit($nc(Basic4Appendable::s)->length())))->rewind();
	$var($CharSequenceArray, ca, $new($CharSequenceArray, {
		static_cast<$CharSequence*>(Basic4Appendable::s),
		static_cast<$CharSequence*>($$new($StringBuffer, Basic4Appendable::s)),
		static_cast<$CharSequence*>($$new($StringBuilder, Basic4Appendable::s)),
		static_cast<$CharSequence*>(cb),
		static_cast<$CharSequence*>(dcb)
	}));
	$var($ObjectArray2, wa, $new($ObjectArray2, {
		$$new($ObjectArray, {
			$of($$new($CharArrayWriter)),
			$of(Basic4Appendable::testCharArrayWriter)
		}),
		$$new($ObjectArray, {
			$of($$new($BufferedWriter, Basic4Appendable::gw)),
			$of(Basic4Appendable::testBufferedWriter)
		}),
		$$new($ObjectArray, {
			$of($$new($FileWriter, Basic4Appendable::gf)),
			$of(Basic4Appendable::testFileWriter)
		}),
		$$new($ObjectArray, {
			$of($$new($OutputStreamWriter, Basic4Appendable::gos)),
			$of(Basic4Appendable::testOutputStreamWriter)
		}),
		$$new($ObjectArray, {
			$of($$new($PrintWriter, static_cast<$Writer*>(Basic4Appendable::gw))),
			$of(Basic4Appendable::testPrintWriter)
		}),
		$$new($ObjectArray, {
			$of($$new($StringWriter)),
			$of(Basic4Appendable::testStringWriter)
		})
	}));
	for (int32_t i = 0; i < ca->length; ++i) {
		$var($CharSequence, a, ca->get(i));
		for (int32_t j = 0; j < wa->length; ++j) {
			test($cast($Writer, $nc(wa->get(j))->get(0)), a, $cast($BasicRunnable, $nc(wa->get(j))->get(1)));
		}
		test($$new($PrintStream, static_cast<$OutputStream*>(Basic4Appendable::gos)), a, Basic4Appendable::testPrintStream);
		test($($CharBuffer::allocate(128)), a, Basic4Appendable::testCharBuffer);
		test($($nc($($ByteBuffer::allocateDirect(128)))->asCharBuffer()), a, Basic4Appendable::testCharBuffer);
		test($$new($StringBuffer), a, Basic4Appendable::testStringBuffer);
		test($$new($StringBuilder), a, Basic4Appendable::testStringBuilder);
	}
	if (Basic4Appendable::fail$ != 0) {
		$throwNew($RuntimeException, $$str({$$str((Basic4Appendable::fail$ + Basic4Appendable::pass$)), " tests: "_s, $$str(Basic4Appendable::fail$), " failure(s), first"_s}), Basic4Appendable::first);
	} else {
		$nc($System::out)->println($$str({"all "_s, $$str((Basic4Appendable::fail$ + Basic4Appendable::pass$)), " tests passed"_s}));
	}
}

void clinit$Basic4Appendable($Class* class$) {
	$assignStatic(Basic4Appendable::s, "Beware the Jabberwock, my son!"_s);
	$assignStatic(Basic4Appendable::gw, $new($CharArrayWriter));
	$assignStatic(Basic4Appendable::gos, $new($ByteArrayOutputStream));
	$assignStatic(Basic4Appendable::gf, Basic4Appendable::newFile());
	Basic4Appendable::fail$ = 0;
	Basic4Appendable::pass$ = 0;
	$assignStatic(Basic4Appendable::testBufferedWriter, $new($Basic4Appendable$1));
	$assignStatic(Basic4Appendable::testCharArrayWriter, $new($Basic4Appendable$2));
	$assignStatic(Basic4Appendable::testFileWriter, $new($Basic4Appendable$3));
	$assignStatic(Basic4Appendable::testOutputStreamWriter, $new($Basic4Appendable$4));
	$assignStatic(Basic4Appendable::testPrintWriter, $new($Basic4Appendable$5));
	$assignStatic(Basic4Appendable::testStringWriter, $new($Basic4Appendable$6));
	$assignStatic(Basic4Appendable::testPrintStream, $new($Basic4Appendable$7));
	$assignStatic(Basic4Appendable::testCharBuffer, $new($Basic4Appendable$8));
	$assignStatic(Basic4Appendable::testStringBuffer, $new($Basic4Appendable$9));
	$assignStatic(Basic4Appendable::testStringBuilder, $new($Basic4Appendable$10));
}

Basic4Appendable::Basic4Appendable() {
}

$Class* Basic4Appendable::load$($String* name, bool initialize) {
	$loadClass(Basic4Appendable, name, initialize, &_Basic4Appendable_ClassInfo_, clinit$Basic4Appendable, allocate$Basic4Appendable);
	return class$;
}

$Class* Basic4Appendable::class$ = nullptr;