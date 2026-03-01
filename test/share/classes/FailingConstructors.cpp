#include <FailingConstructors.h>

#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/PrintWriter.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/AssertionError.h>
#include <jcpp.h>

#undef FILE_CONTENTS
#undef UNSUPPORTED_CHARSET

using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;

$FieldInfo _FailingConstructors_FieldInfo_[] = {
	{"fileName", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(FailingConstructors, fileName)},
	{"UNSUPPORTED_CHARSET", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(FailingConstructors, UNSUPPORTED_CHARSET)},
	{"FILE_CONTENTS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(FailingConstructors, FILE_CONTENTS)},
	{"passed", "I", nullptr, $STATIC | $VOLATILE, $staticField(FailingConstructors, passed)},
	{"failed", "I", nullptr, $STATIC | $VOLATILE, $staticField(FailingConstructors, failed)},
	{}
};

$MethodInfo _FailingConstructors_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FailingConstructors, init$, void)},
	{"check", "(ZLjava/io/File;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(FailingConstructors, check, void, bool, $File*)},
	{"fail", "()V", nullptr, $STATIC, $staticMethod(FailingConstructors, fail, void)},
	{"fail", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(FailingConstructors, fail, void, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(FailingConstructors, main, void, $StringArray*), "java.lang.Throwable"},
	{"pass", "()V", nullptr, $STATIC, $staticMethod(FailingConstructors, pass, void)},
	{"realMain", "([Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(FailingConstructors, realMain, void, $StringArray*), "java.lang.Throwable"},
	{"test", "(ZLjava/io/File;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(FailingConstructors, test, void, bool, $File*), "java.lang.Throwable"},
	{"unexpected", "(Ljava/lang/Throwable;)V", nullptr, $STATIC, $staticMethod(FailingConstructors, unexpected, void, $Throwable*)},
	{"verifyContents", "(Ljava/io/File;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(FailingConstructors, verifyContents, void, $File*)},
	{}
};

$ClassInfo _FailingConstructors_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"FailingConstructors",
	"java.lang.Object",
	nullptr,
	_FailingConstructors_FieldInfo_,
	_FailingConstructors_MethodInfo_
};

$Object* allocate$FailingConstructors($Class* clazz) {
	return $of($alloc(FailingConstructors));
}

$String* FailingConstructors::fileName = nullptr;
$String* FailingConstructors::UNSUPPORTED_CHARSET = nullptr;
$String* FailingConstructors::FILE_CONTENTS = nullptr;
$volatile(int32_t) FailingConstructors::passed = 0;
$volatile(int32_t) FailingConstructors::failed = 0;

void FailingConstructors::init$() {
}

void FailingConstructors::realMain($StringArray* args) {
	$init(FailingConstructors);
	$useLocalCurrentObjectStackCache();
	test(false, $$new($File, FailingConstructors::fileName));
	$var($File, file, $File::createTempFile(FailingConstructors::fileName, nullptr));
	$nc(file)->deleteOnExit();
	$var($FileOutputStream, fos, $new($FileOutputStream, file));
	fos->write($($nc(FailingConstructors::FILE_CONTENTS)->getBytes()));
	fos->close();
	test(true, file);
	file->delete$();
}

void FailingConstructors::test(bool exists, $File* file) {
	$init(FailingConstructors);
	$useLocalCurrentObjectStackCache();
	try {
		$new($PrintWriter, file, FailingConstructors::UNSUPPORTED_CHARSET);
		fail();
	} catch ($FileNotFoundException& e) {
		pass();
	} catch ($UnsupportedEncodingException& e) {
		pass();
	}
	check(exists, file);
	try {
		$new($PrintWriter, file, ($String*)nullptr);
		fail();
	} catch ($FileNotFoundException& e) {
		pass();
	} catch ($NullPointerException& e) {
		pass();
	}
	check(exists, file);
	try {
		$new($PrintWriter, $($nc(file)->getName()), FailingConstructors::UNSUPPORTED_CHARSET);
		fail();
	} catch ($FileNotFoundException& e) {
		pass();
	} catch ($UnsupportedEncodingException& e) {
		pass();
	}
	check(exists, file);
	try {
		$new($PrintWriter, $($nc(file)->getName()), ($String*)nullptr);
		fail();
	} catch ($FileNotFoundException& e) {
		pass();
	} catch ($NullPointerException& e) {
		pass();
	}
	check(exists, file);
}

void FailingConstructors::check(bool exists, $File* file) {
	$init(FailingConstructors);
	if (exists) {
		verifyContents(file);
	} else if ($nc(file)->exists()) {
		fail($$str({file, " should not have been created"_s}));
	}
}

void FailingConstructors::verifyContents($File* file) {
	$init(FailingConstructors);
	$useLocalCurrentObjectStackCache();
	try {
		$var($FileInputStream, fis, $new($FileInputStream, file));
		{
			$var($Throwable, var$0, nullptr);
			bool return$1 = false;
			try {
				try {
					$var($bytes, contents, $nc(FailingConstructors::FILE_CONTENTS)->getBytes());
					int32_t read = 0;
					int32_t count = 0;
					while ((read = fis->read()) != -1) {
						if (read != contents->get(count++)) {
							fail("file contents have been altered"_s);
							return$1 = true;
							goto $finally;
						}
					}
				} catch ($Throwable& t$) {
					try {
						fis->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} $finally: {
				fis->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return;
			}
		}
	} catch ($IOException& ioe) {
		unexpected(ioe);
	}
}

void FailingConstructors::pass() {
	$init(FailingConstructors);
	++FailingConstructors::passed;
}

void FailingConstructors::fail() {
	$init(FailingConstructors);
	++FailingConstructors::failed;
	$Thread::dumpStack();
}

void FailingConstructors::fail($String* message) {
	$init(FailingConstructors);
	$nc($System::out)->println(message);
	fail();
}

void FailingConstructors::unexpected($Throwable* t) {
	$init(FailingConstructors);
	++FailingConstructors::failed;
	$nc(t)->printStackTrace();
}

void FailingConstructors::main($StringArray* args) {
	$init(FailingConstructors);
	$useLocalCurrentObjectStackCache();
	try {
		realMain(args);
	} catch ($Throwable& t) {
		unexpected(t);
	}
	$nc($System::out)->printf("%nPassed = %d, failed = %d%n%n"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(FailingConstructors::passed))),
		$($of($Integer::valueOf(FailingConstructors::failed)))
	}));
	if (FailingConstructors::failed > 0) {
		$throwNew($AssertionError, $of("Some tests failed"_s));
	}
}

void clinit$FailingConstructors($Class* class$) {
	$assignStatic(FailingConstructors::fileName, "FailingConstructorsTest"_s);
	$assignStatic(FailingConstructors::UNSUPPORTED_CHARSET, "unknownCharset"_s);
	$assignStatic(FailingConstructors::FILE_CONTENTS, "This is a small file!"_s);
	FailingConstructors::passed = 0;
	FailingConstructors::failed = 0;
}

FailingConstructors::FailingConstructors() {
}

$Class* FailingConstructors::load$($String* name, bool initialize) {
	$loadClass(FailingConstructors, name, initialize, &_FailingConstructors_ClassInfo_, clinit$FailingConstructors, allocate$FailingConstructors);
	return class$;
}

$Class* FailingConstructors::class$ = nullptr;