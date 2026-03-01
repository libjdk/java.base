#include <WinDirRelative.h>

#include <java/io/File.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef BASENAME
#undef COLON
#undef EXTENSION
#undef NUM_FILES

using $FileArray = $Array<::java::io::File>;
using $File = ::java::io::File;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

$FieldInfo _WinDirRelative_FieldInfo_[] = {
	{"COLON", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WinDirRelative, COLON)},
	{"BASENAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WinDirRelative, BASENAME)},
	{"EXTENSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WinDirRelative, EXTENSION)},
	{"NUM_FILES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WinDirRelative, NUM_FILES)},
	{}
};

$MethodInfo _WinDirRelative_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WinDirRelative, init$, void)},
	{"isLetter", "(C)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(WinDirRelative, isLetter, bool, char16_t)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(WinDirRelative, main, void, $StringArray*), "java.lang.Throwable"},
	{}
};

$ClassInfo _WinDirRelative_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"WinDirRelative",
	"java.lang.Object",
	nullptr,
	_WinDirRelative_FieldInfo_,
	_WinDirRelative_MethodInfo_
};

$Object* allocate$WinDirRelative($Class* clazz) {
	return $of($alloc(WinDirRelative));
}

$String* WinDirRelative::BASENAME = nullptr;
$String* WinDirRelative::EXTENSION = nullptr;

void WinDirRelative::init$() {
}

bool WinDirRelative::isLetter(char16_t c) {
	$init(WinDirRelative);
	return ((c >= u'a') && (c <= u'z')) || ((c >= u'A') && (c <= u'Z'));
}

void WinDirRelative::main($StringArray* args) {
	$init(WinDirRelative);
	$useLocalCurrentObjectStackCache();
	$var($String, userDir, $System::getProperty("user.dir"_s));
	bool var$0 = isLetter($nc(userDir)->charAt(0));
	if (var$0 && $nc(userDir)->charAt(1) == WinDirRelative::COLON) {
		$var($List, filenames, $new($ArrayList, WinDirRelative::NUM_FILES));
		for (int32_t i = 0; i < WinDirRelative::NUM_FILES; ++i) {
			$var($String, filename, $str({WinDirRelative::BASENAME, $$str(i), WinDirRelative::EXTENSION}));
			filenames->add(filename);
			$var($File, f, $new($File, filename));
			f->createNewFile();
			f->deleteOnExit();
			$nc($System::out)->printf("Created %s (%s)%n"_s, $$new($ObjectArray, {
				$of(filename),
				$($of(f->getAbsolutePath()))
			}));
		}
		$var($String, prefix, userDir->substring(0, 2));
		$var($File, p, $new($File, prefix));
		int32_t failures = 0;
		int32_t successes = 0;
		{
			$var($FileArray, arr$, p->listFiles());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($File, f, arr$->get(i$));
				{
					if ($($nc($($nc(f)->getName()))->toString())->startsWith(WinDirRelative::BASENAME)) {
						if (!f->exists()) {
							$nc($System::err)->printf("%s (%s) does not exist%n"_s, $$new($ObjectArray, {
								$of(f),
								$($of(f->getAbsolutePath()))
							}));
							++failures;
						} else {
							++successes;
						}
					}
				}
			}
		}
		bool testFailed = false;
		if (failures > 0) {
			$nc($System::err)->println("Existence check failed"_s);
			testFailed = true;
		}
		if (successes != WinDirRelative::NUM_FILES) {
			$nc($System::err)->println("Count check failed"_s);
			testFailed = true;
		}
		if (testFailed) {
			$throwNew($RuntimeException, "Test failed"_s);
		}
	}
}

WinDirRelative::WinDirRelative() {
}

void clinit$WinDirRelative($Class* class$) {
	$assignStatic(WinDirRelative::BASENAME, "TestFile_"_s);
	$assignStatic(WinDirRelative::EXTENSION, ".txt"_s);
}

$Class* WinDirRelative::load$($String* name, bool initialize) {
	$loadClass(WinDirRelative, name, initialize, &_WinDirRelative_ClassInfo_, clinit$WinDirRelative, allocate$WinDirRelative);
	return class$;
}

$Class* WinDirRelative::class$ = nullptr;