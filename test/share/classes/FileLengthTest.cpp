#include <FileLengthTest.h>

#include <java/io/File.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/RandomAccessFile.h>
#include <java/io/Serializable.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <jcpp.h>

#undef BUF_SIZE

using $File = ::java::io::File;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $RandomAccessFile = ::java::io::RandomAccessFile;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;

class FileLengthTest$$Lambda$lambda$startLengthThread$0 : public $Runnable {
	$class(FileLengthTest$$Lambda$lambda$startLengthThread$0, $NO_CLASS_INIT, $Runnable)
public:
	void init$() {
	}
	virtual void run() override {
		FileLengthTest::lambda$startLengthThread$0();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FileLengthTest$$Lambda$lambda$startLengthThread$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo FileLengthTest$$Lambda$lambda$startLengthThread$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FileLengthTest$$Lambda$lambda$startLengthThread$0, init$, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(FileLengthTest$$Lambda$lambda$startLengthThread$0, run, void)},
	{}
};
$ClassInfo FileLengthTest$$Lambda$lambda$startLengthThread$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"FileLengthTest$$Lambda$lambda$startLengthThread$0",
	"java.lang.Object",
	"java.lang.Runnable",
	nullptr,
	methodInfos
};
$Class* FileLengthTest$$Lambda$lambda$startLengthThread$0::load$($String* name, bool initialize) {
	$loadClass(FileLengthTest$$Lambda$lambda$startLengthThread$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FileLengthTest$$Lambda$lambda$startLengthThread$0::class$ = nullptr;

class FileLengthTest$$Lambda$lambda$startReaderThread$1$1 : public $Runnable {
	$class(FileLengthTest$$Lambda$lambda$startReaderThread$1$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$() {
	}
	virtual void run() override {
		FileLengthTest::lambda$startReaderThread$1();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FileLengthTest$$Lambda$lambda$startReaderThread$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo FileLengthTest$$Lambda$lambda$startReaderThread$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FileLengthTest$$Lambda$lambda$startReaderThread$1$1, init$, void)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(FileLengthTest$$Lambda$lambda$startReaderThread$1$1, run, void)},
	{}
};
$ClassInfo FileLengthTest$$Lambda$lambda$startReaderThread$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"FileLengthTest$$Lambda$lambda$startReaderThread$1$1",
	"java.lang.Object",
	"java.lang.Runnable",
	nullptr,
	methodInfos
};
$Class* FileLengthTest$$Lambda$lambda$startReaderThread$1$1::load$($String* name, bool initialize) {
	$loadClass(FileLengthTest$$Lambda$lambda$startReaderThread$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FileLengthTest$$Lambda$lambda$startReaderThread$1$1::class$ = nullptr;

$FieldInfo _FileLengthTest_FieldInfo_[] = {
	{"BUF_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileLengthTest, BUF_SIZE)},
	{"randomAccessFile", "Ljava/io/RandomAccessFile;", nullptr, $PRIVATE | $STATIC, $staticField(FileLengthTest, randomAccessFile)},
	{"fileLengthCaller", "Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC, $staticField(FileLengthTest, fileLengthCaller)},
	{"fileContentReader", "Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC, $staticField(FileLengthTest, fileContentReader)},
	{"fileContents", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $STATIC, $staticField(FileLengthTest, fileContents)},
	{"isFailed", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(FileLengthTest, isFailed)},
	{}
};

$MethodInfo _FileLengthTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FileLengthTest, init$, void)},
	{"createDummyFile", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(FileLengthTest, createDummyFile, void, $String*), "java.io.FileNotFoundException,java.io.IOException"},
	{"lambda$startLengthThread$0", "()V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(FileLengthTest, lambda$startLengthThread$0, void)},
	{"lambda$startReaderThread$1", "()V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(FileLengthTest, lambda$startReaderThread$1, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(FileLengthTest, main, void, $StringArray*)},
	{"startLengthThread", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(FileLengthTest, startLengthThread, void)},
	{"startReaderThread", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(FileLengthTest, startReaderThread, void)},
	{}
};

$ClassInfo _FileLengthTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"FileLengthTest",
	"java.lang.Object",
	nullptr,
	_FileLengthTest_FieldInfo_,
	_FileLengthTest_MethodInfo_
};

$Object* allocate$FileLengthTest($Class* clazz) {
	return $of($alloc(FileLengthTest));
}

$RandomAccessFile* FileLengthTest::randomAccessFile = nullptr;
$Thread* FileLengthTest::fileLengthCaller = nullptr;
$Thread* FileLengthTest::fileContentReader = nullptr;
$StringBuilder* FileLengthTest::fileContents = nullptr;
$volatile(bool) FileLengthTest::isFailed = false;

void FileLengthTest::init$() {
}

void FileLengthTest::startLengthThread() {
	$init(FileLengthTest);
	if (FileLengthTest::randomAccessFile == nullptr) {
		return;
	}
	$assignStatic(FileLengthTest::fileLengthCaller, $new($Thread, static_cast<$Runnable*>($$new(FileLengthTest$$Lambda$lambda$startLengthThread$0))));
	$nc(FileLengthTest::fileLengthCaller)->setName("RandomAccessFile-length-caller"_s);
	$nc(FileLengthTest::fileLengthCaller)->setDaemon(true);
	$nc(FileLengthTest::fileLengthCaller)->start();
}

void FileLengthTest::startReaderThread() {
	$init(FileLengthTest);
	if (FileLengthTest::randomAccessFile == nullptr) {
		return;
	}
	$assignStatic(FileLengthTest::fileContentReader, $new($Thread, static_cast<$Runnable*>($$new(FileLengthTest$$Lambda$lambda$startReaderThread$1$1))));
	$nc(FileLengthTest::fileContentReader)->setName("RandomAccessFile-content-reader"_s);
	$nc(FileLengthTest::fileContentReader)->setDaemon(true);
	$nc(FileLengthTest::fileContentReader)->start();
}

void FileLengthTest::main($StringArray* args) {
	$init(FileLengthTest);
	$useLocalCurrentObjectStackCache();
	$var($bytes, arr, $new($bytes, FileLengthTest::BUF_SIZE));
	$var($String, testFile, "testfile.txt"_s);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				createDummyFile(testFile);
				$var($File, file, $new($File, testFile));
				file->deleteOnExit();
				$assignStatic(FileLengthTest::randomAccessFile, $new($RandomAccessFile, file, "r"_s));
				int32_t count = $nc(FileLengthTest::randomAccessFile)->read(arr);
				$nc(FileLengthTest::randomAccessFile)->seek(0);
				$assignStatic(FileLengthTest::fileContents, $new($StringBuilder, FileLengthTest::BUF_SIZE));
				$nc(FileLengthTest::fileContents)->append($$new($String, arr, 0, count));
				startLengthThread();
				startReaderThread();
				$nc(FileLengthTest::fileContentReader)->join();
			} catch ($FileNotFoundException& ex) {
			} catch ($InterruptedException& ex) {
			} catch ($IOException& ex) {
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			try {
				$nc(FileLengthTest::randomAccessFile)->close();
			} catch ($IOException& ex) {
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (FileLengthTest::isFailed) {
		$throwNew($RuntimeException, "RandomAccessFile.length() changed the underlying file pointer."_s);
	}
}

void FileLengthTest::createDummyFile($String* fileName) {
	$init(FileLengthTest);
	$useLocalCurrentObjectStackCache();
	{
		$var($FileOutputStream, outputStream, $new($FileOutputStream, $$new($File, fileName)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($String, str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"_s);
					int32_t count = 0;
					while ((count + str->length()) < FileLengthTest::BUF_SIZE) {
						outputStream->write($(str->getBytes()));
						count += str->length();
					}
					outputStream->flush();
				} catch ($Throwable& t$) {
					try {
						outputStream->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				outputStream->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void FileLengthTest::lambda$startReaderThread$1() {
	$init(FileLengthTest);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, FileLengthTest::BUF_SIZE));
	int32_t i = 0;
	$var($bytes, arr, $new($bytes, 8));
	try {
		while ((i = $nc(FileLengthTest::randomAccessFile)->read(arr)) != -1) {
			sb->append($$new($String, arr, 0, i));
		}
		if (!$nc($(sb->toString()))->equals($($nc(FileLengthTest::fileContents)->toString()))) {
			FileLengthTest::isFailed = true;
		}
	} catch ($IOException& ex) {
	}
}

void FileLengthTest::lambda$startLengthThread$0() {
	$init(FileLengthTest);
	while (true) {
		try {
			int64_t length = $nc(FileLengthTest::randomAccessFile)->length();
			if (length < 0) {
				return;
			}
		} catch ($IOException& ex) {
			return;
		}
	}
}

void clinit$FileLengthTest($Class* class$) {
	FileLengthTest::isFailed = false;
}

FileLengthTest::FileLengthTest() {
}

$Class* FileLengthTest::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(FileLengthTest$$Lambda$lambda$startLengthThread$0::classInfo$.name)) {
			return FileLengthTest$$Lambda$lambda$startLengthThread$0::load$(name, initialize);
		}
		if (name->equals(FileLengthTest$$Lambda$lambda$startReaderThread$1$1::classInfo$.name)) {
			return FileLengthTest$$Lambda$lambda$startReaderThread$1$1::load$(name, initialize);
		}
	}
	$loadClass(FileLengthTest, name, initialize, &_FileLengthTest_ClassInfo_, clinit$FileLengthTest, allocate$FileLengthTest);
	return class$;
}

$Class* FileLengthTest::class$ = nullptr;