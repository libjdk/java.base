#include <InheritIOEHandle.h>

#include <InheritIOEHandle$1.h>
#include <InheritIOEHandle$APP.h>
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
#include <jcpp.h>

#undef A
#undef B
#undef C
#undef JAVA_EXE
#undef SIGNAL

using $InheritIOEHandle$1 = ::InheritIOEHandle$1;
using $InheritIOEHandle$APP = ::InheritIOEHandle$APP;
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
using $RuntimeException = ::java::lang::RuntimeException;

$FieldInfo _InheritIOEHandle_FieldInfo_[] = {
	{"stopC", "Ljava/io/File;", nullptr, $PRIVATE | $STATIC, $staticField(InheritIOEHandle, stopC)},
	{"SIGNAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(InheritIOEHandle, SIGNAL)},
	{"JAVA_EXE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(InheritIOEHandle, JAVA_EXE)},
	{}
};

$MethodInfo _InheritIOEHandle_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InheritIOEHandle, init$, void)},
	{"getCommandArray", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritIOEHandle, getCommandArray, $StringArray*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(InheritIOEHandle, main, void, $StringArray*), "java.lang.Exception"},
	{"performA", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritIOEHandle, performA, void)},
	{"performB", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritIOEHandle, performB, void)},
	{"performC", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritIOEHandle, performC, void)},
	{}
};

$InnerClassInfo _InheritIOEHandle_InnerClassesInfo_[] = {
	{"InheritIOEHandle$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"InheritIOEHandle$APP", "InheritIOEHandle", "APP", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _InheritIOEHandle_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"InheritIOEHandle",
	"java.lang.Object",
	nullptr,
	_InheritIOEHandle_FieldInfo_,
	_InheritIOEHandle_MethodInfo_,
	nullptr,
	nullptr,
	_InheritIOEHandle_InnerClassesInfo_,
	nullptr,
	nullptr,
	"InheritIOEHandle$1,InheritIOEHandle$APP"
};

$Object* allocate$InheritIOEHandle($Class* clazz) {
	return $of($alloc(InheritIOEHandle));
}

$File* InheritIOEHandle::stopC = nullptr;
$String* InheritIOEHandle::SIGNAL = nullptr;
$String* InheritIOEHandle::JAVA_EXE = nullptr;

void InheritIOEHandle::init$() {
}

$StringArray* InheritIOEHandle::getCommandArray($String* processName) {
	$init(InheritIOEHandle);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, cmdArray, $new($StringArray, {
		InheritIOEHandle::JAVA_EXE,
		"-cp"_s,
		$($System::getProperty("java.class.path"_s)),
		$(InheritIOEHandle::class$->getName()),
		processName
	}));
	return cmdArray;
}

void InheritIOEHandle::main($StringArray* args) {
	$init(InheritIOEHandle);
	if (!$nc($($System::getProperty("os.name"_s)))->startsWith("Windows"_s)) {
		return;
	}
	$init($InheritIOEHandle$APP);
	$InheritIOEHandle$APP* app = ($nc(args)->length > 0) ? $InheritIOEHandle$APP::valueOf($nc(args)->get(0)) : $InheritIOEHandle$APP::A;
	$init($InheritIOEHandle$1);
	switch ($nc($InheritIOEHandle$1::$SwitchMap$InheritIOEHandle$APP)->get($nc((app))->ordinal())) {
	case 1:
		{
			performA();
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

void InheritIOEHandle::performA() {
	$init(InheritIOEHandle);
	$useLocalCurrentObjectStackCache();
	try {
		$nc(InheritIOEHandle::stopC)->delete$();
		$init($InheritIOEHandle$APP);
		$var($ProcessBuilder, builder, $new($ProcessBuilder, $(getCommandArray($($InheritIOEHandle$APP::B->name())))));
		builder->redirectErrorStream(true);
		$var($Process, process, builder->start());
		$nc($($nc(process)->getOutputStream()))->close();
		$nc($(process->getErrorStream()))->close();
		bool isSignalReceived = false;
		{
			$var($BufferedReader, in, $new($BufferedReader, $$new($InputStreamReader, $(process->getInputStream()), "utf-8"_s)));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$var($String, result, nullptr);
						while (($assign(result, in->readLine())) != nullptr) {
							if ($nc(InheritIOEHandle::SIGNAL)->equals(result)) {
								isSignalReceived = true;
								break;
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
		$nc($System::out)->println("Received signal from B, creating file StopC"_s);
		bool isFileStopC = $nc(InheritIOEHandle::stopC)->createNewFile();
		if (!isFileStopC) {
			$throwNew($RuntimeException, "Signal file StopC.txt was not created. TEST or INFRA bug"_s);
		}
		process->waitFor();
		$nc($System::err)->println("Read stream finished."_s);
	} catch ($IOException& ex) {
		$throwNew($RuntimeException, "Catastrophe in process A!"_s, ex);
	} catch ($InterruptedException& ex) {
		$throwNew($RuntimeException, "A was interrupted while waiting for B"_s, ex);
	}
}

void InheritIOEHandle::performB() {
	$init(InheritIOEHandle);
	$useLocalCurrentObjectStackCache();
	try {
		$init($InheritIOEHandle$APP);
		$var($ProcessBuilder, builder, $new($ProcessBuilder, $(getCommandArray($($InheritIOEHandle$APP::C->name())))));
		$var($Process, process, builder->start());
		$nc($($nc(process)->getInputStream()))->close();
		$nc($(process->getOutputStream()))->close();
		$nc($(process->getErrorStream()))->close();
		$nc($System::out)->println(InheritIOEHandle::SIGNAL);
		process->waitFor();
	} catch ($IOException& ex) {
		$throwNew($RuntimeException, "Catastrophe in process B!"_s, ex);
	} catch ($InterruptedException& ex) {
		$throwNew($RuntimeException, "B was interrupted while waiting for C"_s, ex);
	}
}

void InheritIOEHandle::performC() {
	$init(InheritIOEHandle);
	for (int32_t i = 0; i < 5 * 60; ++i) {
		try {
			$Thread::sleep(1000);
		} catch ($InterruptedException& ex) {
		}
		if ($nc(InheritIOEHandle::stopC)->exists()) {
			break;
		}
	}
}

void clinit$InheritIOEHandle($Class* class$) {
	$assignStatic(InheritIOEHandle::stopC, $new($File, "StopC.txt"_s));
	$assignStatic(InheritIOEHandle::SIGNAL, "After call child process"_s);
	$init($File);
	$assignStatic(InheritIOEHandle::JAVA_EXE, $str({$($System::getProperty("java.home"_s)), $File::separator, "bin"_s, $File::separator, "java"_s}));
}

InheritIOEHandle::InheritIOEHandle() {
}

$Class* InheritIOEHandle::load$($String* name, bool initialize) {
	$loadClass(InheritIOEHandle, name, initialize, &_InheritIOEHandle_ClassInfo_, clinit$InheritIOEHandle, allocate$InheritIOEHandle);
	return class$;
}

$Class* InheritIOEHandle::class$ = nullptr;