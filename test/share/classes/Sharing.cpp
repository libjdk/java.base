#include <Sharing.h>

#include <Sharing$BadFileInputStream.h>
#include <Sharing$BadFileOutputStream.h>
#include <Sharing$OpenClose.h>
#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/RandomAccessFile.h>
#include <java/io/Writer.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/FileLock.h>
#include <java/util/concurrent/CountDownLatch.h>
#include <jcpp.h>

using $Sharing$BadFileInputStream = ::Sharing$BadFileInputStream;
using $Sharing$BadFileOutputStream = ::Sharing$BadFileOutputStream;
using $Sharing$OpenClose = ::Sharing$OpenClose;
using $Sharing$OpenCloseArray = $Array<Sharing$OpenClose>;
using $File = ::java::io::File;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $RandomAccessFile = ::java::io::RandomAccessFile;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $FileChannel = ::java::nio::channels::FileChannel;
using $FileLock = ::java::nio::channels::FileLock;
using $CountDownLatch = ::java::util::concurrent::CountDownLatch;

$FieldInfo _Sharing_FieldInfo_[] = {
	{"numFiles", "I", nullptr, $STATIC | $FINAL, $constField(Sharing, numFiles)},
	{"fail", "Z", nullptr, $STATIC | $VOLATILE, $staticField(Sharing, fail)},
	{}
};

$MethodInfo _Sharing_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Sharing, init$, void)},
	{"MultiThreadedFD", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Sharing, MultiThreadedFD, void), "java.lang.Exception"},
	{"TestCloseAll", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Sharing, TestCloseAll, void), "java.lang.Exception"},
	{"TestFinalizer", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Sharing, TestFinalizer, void), "java.lang.Exception"},
	{"TestIsValid", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Sharing, TestIsValid, void), "java.lang.Exception"},
	{"TestMultipleFD", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Sharing, TestMultipleFD, void), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Sharing, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _Sharing_InnerClassesInfo_[] = {
	{"Sharing$BadFileOutputStream", "Sharing", "BadFileOutputStream", $PRIVATE | $STATIC},
	{"Sharing$BadFileInputStream", "Sharing", "BadFileInputStream", $PRIVATE | $STATIC},
	{"Sharing$OpenClose", "Sharing", "OpenClose", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Sharing_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Sharing",
	"java.lang.Object",
	nullptr,
	_Sharing_FieldInfo_,
	_Sharing_MethodInfo_,
	nullptr,
	nullptr,
	_Sharing_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Sharing$BadFileOutputStream,Sharing$BadFileInputStream,Sharing$OpenClose"
};

$Object* allocate$Sharing($Class* clazz) {
	return $of($alloc(Sharing));
}

$volatile(bool) Sharing::fail = false;

void Sharing::init$() {
}

void Sharing::main($StringArray* args) {
	TestFinalizer();
	TestMultipleFD();
	TestIsValid();
	MultiThreadedFD();
	TestCloseAll();
}

void Sharing::TestFinalizer() {
	$useLocalCurrentObjectStackCache();
	$var($FileDescriptor, fd, nullptr);
	$var($File, tempFile, $new($File, "TestFinalizer1.txt"_s));
	tempFile->deleteOnExit();
	{
		$var($Writer, writer, $new($FileWriter, tempFile));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					for (int32_t i = 0; i < 5; ++i) {
						writer->write("test file content test file content"_s);
					}
				} catch ($Throwable& t$) {
					try {
						writer->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				writer->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	$var($FileInputStream, fis1, $new($FileInputStream, tempFile));
	$assign(fd, fis1->getFD());
	{
		$var($FileInputStream, fis2, $new($FileInputStream, fd));
		{
			$var($Throwable, var$2, nullptr);
			try {
				try {
					$assign(fis1, nullptr);
					int32_t ret = 0;
					while (ret >= 0) {
						$System::gc();
						$nc($System::out)->print("."_s);
						ret = fis2->read();
					}
				} catch ($Throwable& t$) {
					try {
						fis2->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$2, var$3);
			} /*finally*/ {
				fis2->close();
			}
			if (var$2 != nullptr) {
				$throw(var$2);
			}
		}
	}
	$var($File, testFinalizerFile, $new($File, "TestFinalizer"_s));
	$var($RandomAccessFile, raf, $new($RandomAccessFile, testFinalizerFile, "rw"_s));
	raf->writeBytes("test file content test file content"_s);
	raf->seek(0);
	$assign(fd, raf->getFD());
	{
		$var($Throwable, var$4, nullptr);
		try {
			$var($FileInputStream, fis3, $new($FileInputStream, fd));
			{
				$var($Throwable, var$5, nullptr);
				try {
					try {
						$assign(raf, nullptr);
						int32_t ret = 0;
						while (ret >= 0) {
							$System::gc();
							$nc($System::out)->print("."_s);
							ret = fis3->read();
						}
					} catch ($Throwable& t$) {
						try {
							fis3->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable& var$6) {
					$assign(var$5, var$6);
				} /*finally*/ {
					fis3->close();
				}
				if (var$5 != nullptr) {
					$throw(var$5);
				}
			}
		} catch ($Throwable& var$7) {
			$assign(var$4, var$7);
		} /*finally*/ {
			testFinalizerFile->delete$();
		}
		if (var$4 != nullptr) {
			$throw(var$4);
		}
	}
}

void Sharing::TestMultipleFD() {
	$useLocalCurrentObjectStackCache();
	$var($RandomAccessFile, raf, nullptr);
	$var($FileOutputStream, fos, nullptr);
	$var($FileInputStream, fis, nullptr);
	$var($FileChannel, fc, nullptr);
	$var($FileLock, fileLock, nullptr);
	$var($File, test1, $new($File, "test1"_s));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, test1, "rw"_s));
			$assign(fos, $new($FileOutputStream, $(raf->getFD())));
			$assign(fis, $new($FileInputStream, $(raf->getFD())));
			$assign(fc, raf->getChannel());
			$assign(fileLock, $nc(fc)->lock());
			raf->setLength(0);
			fos->flush();
			fos->write($("TEST"_s->getBytes()));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (fileLock != nullptr) {
				fileLock->release();
			}
			if (fis != nullptr) {
				fis->close();
			}
			if (fos != nullptr) {
				fos->close();
			}
			if (raf != nullptr) {
				raf->close();
			}
			test1->delete$();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($File, test2, $new($File, "test2"_s));
	{
		$var($Throwable, var$2, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, test2, "rw"_s));
			$assign(fos, $new($FileOutputStream, $(raf->getFD())));
			$assign(fis, $new($FileInputStream, $(raf->getFD())));
			$assign(fc, raf->getChannel());
			$assign(fileLock, $nc(fc)->lock());
			raf->setLength(0);
			fos->flush();
			fos->write($("TEST"_s->getBytes()));
		} catch ($Throwable& var$3) {
			$assign(var$2, var$3);
		} /*finally*/ {
			if (fileLock != nullptr) {
				fileLock->release();
			}
			if (raf != nullptr) {
				raf->close();
			}
			if (fos != nullptr) {
				fos->close();
			}
			if (fis != nullptr) {
				fis->close();
			}
			test2->delete$();
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
	}
	$var($File, test3, $new($File, "test3"_s));
	{
		$var($Throwable, var$4, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, test3, "rw"_s));
			$assign(fos, $new($FileOutputStream, $(raf->getFD())));
			$assign(fis, $new($FileInputStream, $(raf->getFD())));
			$assign(fc, raf->getChannel());
			$assign(fileLock, $nc(fc)->lock());
			raf->setLength(0);
			fos->flush();
			fos->write($("TEST"_s->getBytes()));
		} catch ($Throwable& var$5) {
			$assign(var$4, var$5);
		} /*finally*/ {
			if (fileLock != nullptr) {
				fileLock->release();
			}
			if (fos != nullptr) {
				fos->close();
			}
			if (raf != nullptr) {
				raf->close();
			}
			if (fis != nullptr) {
				fis->close();
			}
			test3->delete$();
		}
		if (var$4 != nullptr) {
			$throw(var$4);
		}
	}
}

void Sharing::TestIsValid() {
	$useLocalCurrentObjectStackCache();
	$var($FileDescriptor, fd, nullptr);
	$var($RandomAccessFile, raf, nullptr);
	$var($FileOutputStream, fos, nullptr);
	$var($FileInputStream, fis, nullptr);
	$var($FileChannel, fc, nullptr);
	$var($File, test1, $new($File, "test1"_s));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, test1, "rw"_s));
			$assign(fd, raf->getFD());
			$assign(fos, $new($FileOutputStream, fd));
			$assign(fis, $new($FileInputStream, fd));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			{
				$var($Throwable, var$2, nullptr);
				try {
					if (fis != nullptr) {
						fis->close();
					}
					if ($nc(fd)->valid()) {
						$throwNew($RuntimeException, "[FIS close()] FileDescriptor shouldn\'t be valid"_s);
					}
					if (fos != nullptr) {
						fos->close();
					}
					if (raf != nullptr) {
						raf->close();
					}
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					test1->delete$();
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($File, test2, $new($File, "test2"_s));
	{
		$var($Throwable, var$4, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, test2, "rw"_s));
			$assign(fd, raf->getFD());
			$assign(fos, $new($FileOutputStream, fd));
			$assign(fis, $new($FileInputStream, fd));
		} catch ($Throwable& var$5) {
			$assign(var$4, var$5);
		} /*finally*/ {
			{
				$var($Throwable, var$6, nullptr);
				try {
					if (raf != nullptr) {
						raf->close();
					}
					if ($nc(fd)->valid()) {
						$throwNew($RuntimeException, "[RAF close()] FileDescriptor shouldn\'t be valid"_s);
					}
					if (fos != nullptr) {
						fos->close();
					}
					if (fis != nullptr) {
						fis->close();
					}
				} catch ($Throwable& var$7) {
					$assign(var$6, var$7);
				} /*finally*/ {
					test2->delete$();
				}
				if (var$6 != nullptr) {
					$throw(var$6);
				}
			}
		}
		if (var$4 != nullptr) {
			$throw(var$4);
		}
	}
	$var($File, test3, $new($File, "test3"_s));
	{
		$var($Throwable, var$8, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, test3, "rw"_s));
			$assign(fd, raf->getFD());
			$assign(fos, $new($FileOutputStream, fd));
			$assign(fis, $new($FileInputStream, fd));
		} catch ($Throwable& var$9) {
			$assign(var$8, var$9);
		} /*finally*/ {
			{
				$var($Throwable, var$10, nullptr);
				try {
					if (fos != nullptr) {
						fos->close();
					}
					if ($nc(fd)->valid()) {
						$throwNew($RuntimeException, "[FOS close()] FileDescriptor shouldn\'t be valid"_s);
					}
					if (raf != nullptr) {
						raf->close();
					}
					if (fis != nullptr) {
						fis->close();
					}
				} catch ($Throwable& var$11) {
					$assign(var$10, var$11);
				} /*finally*/ {
					test3->delete$();
				}
				if (var$10 != nullptr) {
					$throw(var$10);
				}
			}
		}
		if (var$8 != nullptr) {
			$throw(var$8);
		}
	}
}

void Sharing::MultiThreadedFD() {
	$useLocalCurrentObjectStackCache();
	$var($RandomAccessFile, raf, nullptr);
	$var($FileDescriptor, fd, nullptr);
	int32_t numThreads = 2;
	$var($CountDownLatch, done, $new($CountDownLatch, numThreads));
	$var($Sharing$OpenCloseArray, fileOpenClose, $new($Sharing$OpenCloseArray, numThreads));
	$var($File, MultipleThreadedFD, $new($File, "MultipleThreadedFD"_s));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(raf, $new($RandomAccessFile, MultipleThreadedFD, "rw"_s));
			$assign(fd, raf->getFD());
			for (int32_t count = 0; count < numThreads; ++count) {
				fileOpenClose->set(count, $$new($Sharing$OpenClose, fd, done));
				$nc(fileOpenClose->get(count))->start();
			}
			done->await();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			{
				$var($Throwable, var$2, nullptr);
				try {
					if (raf != nullptr) {
						raf->close();
					}
					if ($nc(fd)->valid()) {
						$throwNew($RuntimeException, "FileDescriptor should not be valid"_s);
					}
					$init(Sharing);
					if (Sharing::fail) {
						$throwNew($RuntimeException, "OpenClose thread tests failed."_s);
					}
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					MultipleThreadedFD->delete$();
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Sharing::TestCloseAll() {
	$useLocalCurrentObjectStackCache();
	$var($File, testFile, $new($File, "test0"_s));
	testFile->deleteOnExit();
	$var($RandomAccessFile, raf, $new($RandomAccessFile, testFile, "rw"_s));
	$var($FileInputStream, fis, $new($FileInputStream, $(raf->getFD())));
	fis->close();
	if ($nc($(raf->getFD()))->valid()) {
		$throwNew($RuntimeException, "FD should not be valid."_s);
	}
	$assign(raf, $new($RandomAccessFile, testFile, "rw"_s));
	$assign(fis, $new($FileInputStream, $(raf->getFD())));
	$var($Sharing$BadFileInputStream, bfis1, $new($Sharing$BadFileInputStream, $(raf->getFD())));
	$var($Sharing$BadFileInputStream, bfis2, $new($Sharing$BadFileInputStream, $(raf->getFD())));
	$var($Sharing$BadFileInputStream, bfis3, $new($Sharing$BadFileInputStream, $(raf->getFD())));
	$assign(bfis3, nullptr);
	try {
		fis->close();
	} catch ($IOException& ioe) {
		ioe->printStackTrace();
		if ($nc($(ioe->getSuppressed()))->length != 2) {
			$throwNew($RuntimeException, $$str({"[FIS]Incorrect number of suppressed exceptions received : "_s, $$str($nc($(ioe->getSuppressed()))->length)}));
		}
	}
	if ($nc($(raf->getFD()))->valid()) {
		$throwNew($RuntimeException, "[FIS]TestCloseAll : FD still valid."_s);
	}
	$assign(raf, $new($RandomAccessFile, testFile, "rw"_s));
	$var($FileOutputStream, fos, $new($FileOutputStream, $(raf->getFD())));
	$var($Sharing$BadFileOutputStream, bfos1, $new($Sharing$BadFileOutputStream, $(raf->getFD())));
	$var($Sharing$BadFileOutputStream, bfos2, $new($Sharing$BadFileOutputStream, $(raf->getFD())));
	$var($Sharing$BadFileOutputStream, bfos3, $new($Sharing$BadFileOutputStream, $(raf->getFD())));
	$assign(bfos3, nullptr);
	try {
		fos->close();
	} catch ($IOException& ioe) {
		ioe->printStackTrace();
		if ($nc($(ioe->getSuppressed()))->length != 2) {
			$throwNew($RuntimeException, $$str({"[FOS]Incorrect number of suppressed exceptions received : "_s, $$str($nc($(ioe->getSuppressed()))->length)}));
		}
	}
	if ($nc($(raf->getFD()))->valid()) {
		$throwNew($RuntimeException, "[FOS]TestCloseAll : FD still valid."_s);
	}
}

Sharing::Sharing() {
}

$Class* Sharing::load$($String* name, bool initialize) {
	$loadClass(Sharing, name, initialize, &_Sharing_ClassInfo_, allocate$Sharing);
	return class$;
}

$Class* Sharing::class$ = nullptr;