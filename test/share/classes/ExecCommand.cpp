#include <ExecCommand.h>

#include <ExecCommand$SecurityMan.h>
#include <java/io/BufferedWriter.h>
#include <java/io/File.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/Writer.h>
#include <java/lang/Error.h>
#include <java/lang/Process.h>
#include <java/lang/Runtime.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessControlException.h>
#include <jcpp.h>

#undef TEST_RTE_ARG
#undef TEST_RTE_GI

using $ExecCommand$SecurityMan = ::ExecCommand$SecurityMan;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $BufferedWriter = ::java::io::BufferedWriter;
using $File = ::java::io::File;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process = ::java::lang::Process;
using $Runtime = ::java::lang::Runtime;
using $SecurityManager = ::java::lang::SecurityManager;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystems = ::java::nio::file::FileSystems;
using $Files = ::java::nio::file::Files;
using $AccessControlException = ::java::security::AccessControlException;

$FieldInfo _ExecCommand_FieldInfo_[] = {
	{"TEST_RTE_ARG", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExecCommand, TEST_RTE_ARG)},
	{"doCmdCopy", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExecCommand, doCmdCopy)},
	{"TEST_RTE_GI", "[[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExecCommand, TEST_RTE_GI)},
	{}
};

$MethodInfo _ExecCommand_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ExecCommand, init$, void)},
	{"checkOut", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ExecCommand, checkOut, void, $String*), "java.io.FileNotFoundException"},
	{"deleteOut", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ExecCommand, deleteOut, void, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ExecCommand, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _ExecCommand_InnerClassesInfo_[] = {
	{"ExecCommand$SecurityMan", "ExecCommand", "SecurityMan", $STATIC},
	{}
};

$ClassInfo _ExecCommand_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ExecCommand",
	"java.lang.Object",
	nullptr,
	_ExecCommand_FieldInfo_,
	_ExecCommand_MethodInfo_,
	nullptr,
	nullptr,
	_ExecCommand_InnerClassesInfo_,
	nullptr,
	nullptr,
	"ExecCommand$SecurityMan"
};

$Object* allocate$ExecCommand($Class* clazz) {
	return $of($alloc(ExecCommand));
}

$StringArray* ExecCommand::TEST_RTE_ARG = nullptr;
$StringArray* ExecCommand::doCmdCopy = nullptr;
$StringArray2* ExecCommand::TEST_RTE_GI = nullptr;

void ExecCommand::init$() {
}

void ExecCommand::deleteOut($String* path) {
	$init(ExecCommand);
	$useLocalCurrentObjectStackCache();
	try {
		$Files::delete$($($nc($($FileSystems::getDefault()))->getPath(path, $$new($StringArray, 0))));
	} catch ($IOException& ex) {
	}
}

void ExecCommand::checkOut($String* path) {
	$init(ExecCommand);
	$useLocalCurrentObjectStackCache();
	if ($Files::notExists($($nc($($FileSystems::getDefault()))->getPath(path, $$new($StringArray, 0))), $$new($LinkOptionArray, 0))) {
		$throwNew($FileNotFoundException, path);
	}
}

void ExecCommand::main($StringArray* _args) {
	$init(ExecCommand);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!$nc($($System::getProperty("os.name"_s)))->startsWith("Windows"_s)) {
		return;
	}
	try {
		$$new($File, ".\\Program Files"_s)->mkdirs();
		for (int32_t i = 0; i < $nc(ExecCommand::doCmdCopy)->length; ++i) {
			{
				$var($BufferedWriter, outCmd, $new($BufferedWriter, $$new($FileWriter, $nc(ExecCommand::doCmdCopy)->get(i))));
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							outCmd->write("@echo %1"_s);
						} catch ($Throwable& t$) {
							try {
								outCmd->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						outCmd->close();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
		}
	} catch ($IOException& e) {
		$throwNew($Error, $(e->getMessage()));
	}
	for (int32_t k = 0; k < 4; ++k) {
		switch (k) {
		case 0:
			{
				break;
			}
		case 1:
			{
				$System::setProperty("jdk.lang.Process.allowAmbiguousCommands"_s, "false"_s);
				break;
			}
		case 2:
			{
				$System::setProperty("jdk.lang.Process.allowAmbiguousCommands"_s, ""_s);
				break;
			}
		case 3:
			{
				$System::setSecurityManager($$new($ExecCommand$SecurityMan));
				break;
			}
		}
		for (int32_t i = 0; i < $nc(ExecCommand::TEST_RTE_ARG)->length; ++i) {
			$var($String, outRes, nullptr);
			try {
				switch (i) {
				case 0:
					{
						deleteOut(".\\dirOut.txt"_s);
						break;
					}
				case 1:
					{
						deleteOut(".\\Program Files\\dirOut.txt"_s);
						break;
					}
				}
				$var($Process, exec, $nc($($Runtime::getRuntime()))->exec($nc(ExecCommand::TEST_RTE_ARG)->get(i)));
				$nc(exec)->waitFor();
				switch (i) {
				case 0:
					{
						checkOut(".\\dirOut.txt"_s);
						break;
					}
				case 1:
					{
						checkOut(".\\Program Files\\dirOut.txt"_s);
						break;
					}
				}
				$assign(outRes, "Success"_s);
			} catch ($IOException& ioe) {
				$assign(outRes, $str({"IOException: "_s, $(ioe->getMessage())}));
			} catch ($IllegalArgumentException& iae) {
				$assign(outRes, $str({"IllegalArgumentException: "_s, $(iae->getMessage())}));
			} catch ($AccessControlException& se) {
				$assign(outRes, $str({"AccessControlException: "_s, $(se->getMessage())}));
			}
			if (!$nc(outRes)->startsWith($nc($nc(ExecCommand::TEST_RTE_GI)->get(i))->get(k))) {
				$throwNew($Error, $$str({"Unexpected output! Step"_s, $$str(k), ":"_s, $$str(i), "\nArgument: "_s, $nc(ExecCommand::TEST_RTE_ARG)->get(i), "\nExpected: "_s, $nc($nc(ExecCommand::TEST_RTE_GI)->get(i))->get(k), "\n  Output: "_s, outRes}));
			} else {
				$nc($System::out)->println($$str({"RTE OK:"_s, $nc(ExecCommand::TEST_RTE_ARG)->get(i)}));
			}
		}
	}
}

void clinit$ExecCommand($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ExecCommand::TEST_RTE_ARG, $new($StringArray, {
		"cmd /C dir > dirOut.txt"_s,
		"cmd /C dir > \".\\Program Files\\dirOut.txt\""_s,
		".\\Program Files\\do.cmd"_s,
		"\".\\Program Files\\doNot.cmd\" arg"_s,
		"\".\\Program Files\\do.cmd\" arg"_s,
		"\".\\Program.cmd\" arg"_s,
		".\\Program.cmd arg"_s
	}));
	$assignStatic(ExecCommand::doCmdCopy, $new($StringArray, {
		".\\Program.cmd"_s,
		".\\Program Files\\doNot.cmd"_s,
		".\\Program Files\\do.cmd"_s
	}));
	$assignStatic(ExecCommand::TEST_RTE_GI, $new($StringArray2, {
		$$new($StringArray, {
			"Success"_s,
			"IOException"_s,
			"Success"_s,
			"IOException"_s
		}),
		$$new($StringArray, {
			"Success"_s,
			"IOException"_s,
			"Success"_s,
			"IOException"_s
		}),
		$$new($StringArray, {
			"Success"_s,
			"IOException"_s,
			"Success"_s,
			"IOException"_s
		}),
		$$new($StringArray, {
			"Success"_s,
			"Success"_s,
			"Success"_s,
			"AccessControlException"_s
		}),
		$$new($StringArray, {
			"Success"_s,
			"Success"_s,
			"Success"_s,
			"Success"_s
		}),
		$$new($StringArray, {
			"Success"_s,
			"Success"_s,
			"Success"_s,
			"Success"_s
		}),
		$$new($StringArray, {
			"Success"_s,
			"Success"_s,
			"Success"_s,
			"Success"_s
		})
	}));
}

ExecCommand::ExecCommand() {
}

$Class* ExecCommand::load$($String* name, bool initialize) {
	$loadClass(ExecCommand, name, initialize, &_ExecCommand_ClassInfo_, clinit$ExecCommand, allocate$ExecCommand);
	return class$;
}

$Class* ExecCommand::class$ = nullptr;