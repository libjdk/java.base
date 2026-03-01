#include <WalkWithSecurity.h>

#include <WalkWithSecurity$1.h>
#include <WalkWithSecurity$CountingVisitor.h>
#include <WalkWithSecurity$ExpectedResult.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileVisitor.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/util/Iterator.h>
#include <jcpp.h>

using $WalkWithSecurity$1 = ::WalkWithSecurity$1;
using $WalkWithSecurity$CountingVisitor = ::WalkWithSecurity$CountingVisitor;
using $WalkWithSecurity$ExpectedResult = ::WalkWithSecurity$ExpectedResult;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $FileVisitor = ::java::nio::file::FileVisitor;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $Iterator = ::java::util::Iterator;

$MethodInfo _WalkWithSecurity_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WalkWithSecurity, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(WalkWithSecurity, main, void, $StringArray*), "java.io.IOException"},
	{}
};

$InnerClassInfo _WalkWithSecurity_InnerClassesInfo_[] = {
	{"WalkWithSecurity$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"WalkWithSecurity$CountingVisitor", "WalkWithSecurity", "CountingVisitor", $STATIC},
	{"WalkWithSecurity$ExpectedResult", "WalkWithSecurity", "ExpectedResult", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _WalkWithSecurity_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"WalkWithSecurity",
	"java.lang.Object",
	nullptr,
	nullptr,
	_WalkWithSecurity_MethodInfo_,
	nullptr,
	nullptr,
	_WalkWithSecurity_InnerClassesInfo_,
	nullptr,
	nullptr,
	"WalkWithSecurity$1,WalkWithSecurity$CountingVisitor,WalkWithSecurity$ExpectedResult"
};

$Object* allocate$WalkWithSecurity($Class* clazz) {
	return $of($alloc(WalkWithSecurity));
}

void WalkWithSecurity::init$() {
}

void WalkWithSecurity::main($StringArray* args) {
	$load(WalkWithSecurity);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, policyFile, $nc(args)->get(0));
	$WalkWithSecurity$ExpectedResult* expectedResult = $WalkWithSecurity$ExpectedResult::valueOf($($nc(args->get(1))->toUpperCase()));
	$var($String, here, $System::getProperty("user.dir"_s));
	$var($String, testSrc, $System::getProperty("test.src"_s));
	if (testSrc == nullptr) {
		$throwNew($RuntimeException, "This test must be run by jtreg"_s);
	}
	$var($Path, dir, $Paths::get(testSrc, $$new($StringArray, 0)));
	if ($Files::isSameFile($($Paths::get(here, $$new($StringArray, 0))), dir)) {
		$throwNew($RuntimeException, $$str({"Working directory cannot be "_s, dir}));
	}
	{
		$var($DirectoryStream, stream, $Files::newDirectoryStream(dir));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if (!$nc($($nc(stream)->iterator()))->hasNext()) {
						$throwNew($RuntimeException, $$str({testSrc, " is empty"_s}));
					}
				} catch ($Throwable& t$) {
					if (stream != nullptr) {
						try {
							stream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (stream != nullptr) {
					stream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	$System::setProperty("java.security.policy"_s, $($nc($($nc(dir)->resolve(policyFile)))->toString()));
	$System::setSecurityManager($$new($SecurityManager));
	$var($WalkWithSecurity$CountingVisitor, visitor, $new($WalkWithSecurity$CountingVisitor));
	$var($SecurityException, exception, nullptr);
	try {
		$Files::walkFileTree(dir, visitor);
	} catch ($SecurityException& se) {
		$assign(exception, se);
	}
	$init($WalkWithSecurity$1);
	switch ($nc($WalkWithSecurity$1::$SwitchMap$WalkWithSecurity$ExpectedResult)->get($nc((expectedResult))->ordinal())) {
	case 1:
		{
			if (exception != nullptr) {
				exception->printStackTrace();
				$throwNew($RuntimeException, "SecurityException not expected"_s);
			}
			if (visitor->count() == 0) {
				$throwNew($RuntimeException, "No files visited"_s);
			}
			break;
		}
	case 2:
		{
			if (exception == nullptr) {
				$throwNew($RuntimeException, "SecurityException expected"_s);
			}
			if (visitor->count() > 0) {
				$throwNew($RuntimeException, "Files were visited"_s);
			}
			break;
		}
	case 3:
		{
			if (exception != nullptr) {
				exception->printStackTrace();
				$throwNew($RuntimeException, "SecurityException not expected"_s);
			}
			if (visitor->count() == 0) {
				$throwNew($RuntimeException, "Starting file not visited"_s);
			}
			if (visitor->count() > 1) {
				$throwNew($RuntimeException, "More than starting file visited"_s);
			}
			break;
		}
	default:
		{
			$throwNew($RuntimeException, "Should not get here"_s);
		}
	}
}

WalkWithSecurity::WalkWithSecurity() {
}

$Class* WalkWithSecurity::load$($String* name, bool initialize) {
	$loadClass(WalkWithSecurity, name, initialize, &_WalkWithSecurity_ClassInfo_, allocate$WalkWithSecurity);
	return class$;
}

$Class* WalkWithSecurity::class$ = nullptr;