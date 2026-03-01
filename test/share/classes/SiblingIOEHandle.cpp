#include <SiblingIOEHandle.h>

#include <SiblingIOEHandle$1.h>
#include <SiblingIOEHandle$APP.h>
#include <SiblingIOEHandle$ProcessC.h>
#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder.h>
#include <java/lang/Runnable.h>
#include <java/util/concurrent/BrokenBarrierException.h>
#include <java/util/concurrent/CyclicBarrier.h>
#include <jcpp.h>

#undef A
#undef B
#undef JAVA_EXE
#undef SIGNAL

using $SiblingIOEHandle$1 = ::SiblingIOEHandle$1;
using $SiblingIOEHandle$APP = ::SiblingIOEHandle$APP;
using $SiblingIOEHandle$ProcessC = ::SiblingIOEHandle$ProcessC;
using $BufferedReader = ::java::io::BufferedReader;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process = ::java::lang::Process;
using $ProcessBuilder = ::java::lang::ProcessBuilder;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $BrokenBarrierException = ::java::util::concurrent::BrokenBarrierException;
using $CyclicBarrier = ::java::util::concurrent::CyclicBarrier;

$FieldInfo _SiblingIOEHandle_FieldInfo_[] = {
	{"stopC", "Ljava/io/File;", nullptr, $PRIVATE | $STATIC, $staticField(SiblingIOEHandle, stopC)},
	{"SIGNAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SiblingIOEHandle, SIGNAL)},
	{"JAVA_EXE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SiblingIOEHandle, JAVA_EXE)},
	{"procClaunched", "Z", nullptr, $STATIC, $staticField(SiblingIOEHandle, procClaunched)},
	{}
};

$MethodInfo _SiblingIOEHandle_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SiblingIOEHandle, init$, void)},
	{"getCommandArray", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SiblingIOEHandle, getCommandArray, $StringArray*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SiblingIOEHandle, main, void, $StringArray*)},
	{"performA", "(Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SiblingIOEHandle, performA, void, bool)},
	{"performB", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(SiblingIOEHandle, performB, void)},
	{"performC", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(SiblingIOEHandle, performC, void)},
	{"waitAbit", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(SiblingIOEHandle, waitAbit, void)},
	{"waitBarrier", "(Ljava/util/concurrent/CyclicBarrier;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(SiblingIOEHandle, waitBarrier, bool, $CyclicBarrier*)},
	{}
};

$InnerClassInfo _SiblingIOEHandle_InnerClassesInfo_[] = {
	{"SiblingIOEHandle$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"SiblingIOEHandle$ProcessC", "SiblingIOEHandle", "ProcessC", $PRIVATE | $STATIC},
	{"SiblingIOEHandle$APP", "SiblingIOEHandle", "APP", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SiblingIOEHandle_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"SiblingIOEHandle",
	"java.lang.Object",
	nullptr,
	_SiblingIOEHandle_FieldInfo_,
	_SiblingIOEHandle_MethodInfo_,
	nullptr,
	nullptr,
	_SiblingIOEHandle_InnerClassesInfo_,
	nullptr,
	nullptr,
	"SiblingIOEHandle$1,SiblingIOEHandle$ProcessC,SiblingIOEHandle$APP"
};

$Object* allocate$SiblingIOEHandle($Class* clazz) {
	return $of($alloc(SiblingIOEHandle));
}

$File* SiblingIOEHandle::stopC = nullptr;
$String* SiblingIOEHandle::SIGNAL = nullptr;
$String* SiblingIOEHandle::JAVA_EXE = nullptr;
bool SiblingIOEHandle::procClaunched = false;

void SiblingIOEHandle::init$() {
}

$StringArray* SiblingIOEHandle::getCommandArray($String* processName) {
	$init(SiblingIOEHandle);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, cmdArray, $new($StringArray, {
		SiblingIOEHandle::JAVA_EXE,
		"-cp"_s,
		$($System::getProperty("java.class.path"_s)),
		$(SiblingIOEHandle::class$->getName()),
		processName
	}));
	return cmdArray;
}

void SiblingIOEHandle::main($StringArray* args) {
	$init(SiblingIOEHandle);
	if (!$nc($($System::getProperty("os.name"_s)))->startsWith("Windows"_s)) {
		return;
	}
	$init($SiblingIOEHandle$APP);
	$SiblingIOEHandle$APP* app = ($nc(args)->length > 0) ? $SiblingIOEHandle$APP::valueOf($nc(args)->get(0)) : $SiblingIOEHandle$APP::A;
	$init($SiblingIOEHandle$1);
	switch ($nc($SiblingIOEHandle$1::$SwitchMap$SiblingIOEHandle$APP)->get($nc((app))->ordinal())) {
	case 1:
		{
			performA(true);
			performA(false);
			break;
		}
	case 2:
		{
			performB();
			break;
		}
	case 3:
		{
			performC();
			break;
		}
	}
}

void SiblingIOEHandle::waitAbit() {
	$init(SiblingIOEHandle);
	try {
		$Thread::sleep(0);
	} catch ($InterruptedException& ex) {
	}
}

bool SiblingIOEHandle::waitBarrier($CyclicBarrier* barrier) {
	$init(SiblingIOEHandle);
	while (true) {
		try {
			$nc(barrier)->await();
			return true;
		} catch ($InterruptedException& ex) {
			continue;
		} catch ($BrokenBarrierException& ex) {
			ex->printStackTrace();
			return false;
		}
	}
	$shouldNotReachHere();
}

void SiblingIOEHandle::performA(bool fileOut) {
	$init(SiblingIOEHandle);
	$useLocalCurrentObjectStackCache();
	try {
		$nc(SiblingIOEHandle::stopC)->delete$();
		$init($SiblingIOEHandle$APP);
		$var($ProcessBuilder, builderB, $new($ProcessBuilder, $(getCommandArray($($SiblingIOEHandle$APP::B->name())))));
		$var($File, outB, nullptr);
		if (fileOut) {
			$assign(outB, $new($File, "outB.txt"_s));
			builderB->redirectOutput(outB);
		}
		builderB->redirectErrorStream(true);
		$var($CyclicBarrier, barrier, $new($CyclicBarrier, 2));
		$var($SiblingIOEHandle$ProcessC, processC, $new($SiblingIOEHandle$ProcessC, barrier));
		$var($Thread, procCRunner, $new($Thread, static_cast<$Runnable*>(processC)));
		procCRunner->start();
		if (!waitBarrier(barrier)) {
			$throwNew($RuntimeException, "Catastrophe in process A! Synchronization failed."_s);
		}
		$var($Process, processB, builderB->start());
		while (true) {
			try {
				procCRunner->join();
				break;
			} catch ($InterruptedException& ex) {
				continue;
			}
		}
		if (!SiblingIOEHandle::procClaunched) {
			$throwNew($RuntimeException, "Catastrophe in process A! C was not launched."_s);
		}
		$nc($($nc(processB)->getOutputStream()))->close();
		$nc($(processB->getErrorStream()))->close();
		if (fileOut) {
			try {
				processB->waitFor();
			} catch ($InterruptedException& ex) {
				$throwNew($RuntimeException, "Catastrophe in process B! B hung up."_s);
			}
			$nc($System::err)->println("Trying to delete [outB.txt]."_s);
			if (!$nc(outB)->delete$()) {
				$throwNew($RuntimeException, "Greedy brother C deadlock! File share."_s);
			}
			$nc($System::err)->println("Succeeded in delete [outB.txt]."_s);
		} else {
			$nc($System::err)->println("Read stream start."_s);
			bool isSignalReceived = false;
			{
				$var($BufferedReader, in, $new($BufferedReader, $$new($InputStreamReader, $(processB->getInputStream()), "utf-8"_s)));
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							$var($String, result, nullptr);
							while (($assign(result, in->readLine())) != nullptr) {
								if ($nc(SiblingIOEHandle::SIGNAL)->equals(result)) {
									isSignalReceived = true;
								} else {
									$throwNew($RuntimeException, "Catastrophe in process B! Bad output."_s);
								}
							}
						} catch ($Throwable& t$) {
							try {
								in->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						in->close();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
			if (!isSignalReceived) {
				$throwNew($RuntimeException, "Signal from B was not received"_s);
			}
			$nc($System::err)->println("Read stream finished."_s);
		}
		$nc(SiblingIOEHandle::stopC)->createNewFile();
		processC->waitFor();
	} catch ($IOException& ex) {
		$throwNew($RuntimeException, "Catastrophe in process A!"_s, ex);
	} catch ($InterruptedException& ex) {
		$throwNew($RuntimeException, "Process A was interrupted while waiting for C"_s, ex);
	}
}

void SiblingIOEHandle::performB() {
	$init(SiblingIOEHandle);
	$nc($System::out)->println(SiblingIOEHandle::SIGNAL);
}

void SiblingIOEHandle::performC() {
	$init(SiblingIOEHandle);
	for (int32_t i = 0; i < 5 * 60; ++i) {
		try {
			$Thread::sleep(1000);
			if ($nc(SiblingIOEHandle::stopC)->exists()) {
				break;
			}
		} catch ($InterruptedException& ex) {
		}
	}
}

void clinit$SiblingIOEHandle($Class* class$) {
	$assignStatic(SiblingIOEHandle::stopC, $new($File, ".\\StopCs.txt"_s));
	$assignStatic(SiblingIOEHandle::SIGNAL, "B child reported."_s);
	$init($File);
	$assignStatic(SiblingIOEHandle::JAVA_EXE, $str({$($System::getProperty("java.home"_s)), $File::separator, "bin"_s, $File::separator, "java"_s}));
	SiblingIOEHandle::procClaunched = false;
}

SiblingIOEHandle::SiblingIOEHandle() {
}

$Class* SiblingIOEHandle::load$($String* name, bool initialize) {
	$loadClass(SiblingIOEHandle, name, initialize, &_SiblingIOEHandle_ClassInfo_, clinit$SiblingIOEHandle, allocate$SiblingIOEHandle);
	return class$;
}

$Class* SiblingIOEHandle::class$ = nullptr;