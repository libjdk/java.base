#include <FilePermissionTest.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/Permission.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Permission = ::java::security::Permission;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Consumer = ::java::util::function::Consumer;

class FilePermissionTest$$Lambda$lambda$check$0 : public $Consumer {
	$class(FilePermissionTest$$Lambda$lambda$check$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($StringBuilder* actual) {
		$set(this, actual, actual);
	}
	virtual void accept(Object$* f) override {
		FilePermissionTest::lambda$check$0(actual, $cast($String, f));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FilePermissionTest$$Lambda$lambda$check$0>());
	}
	$StringBuilder* actual = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo FilePermissionTest$$Lambda$lambda$check$0::fieldInfos[2] = {
	{"actual", "Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $field(FilePermissionTest$$Lambda$lambda$check$0, actual)},
	{}
};
$MethodInfo FilePermissionTest$$Lambda$lambda$check$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/StringBuilder;)V", nullptr, $PUBLIC, $method(FilePermissionTest$$Lambda$lambda$check$0, init$, void, $StringBuilder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(FilePermissionTest$$Lambda$lambda$check$0, accept, void, Object$*)},
	{}
};
$ClassInfo FilePermissionTest$$Lambda$lambda$check$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"FilePermissionTest$$Lambda$lambda$check$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* FilePermissionTest$$Lambda$lambda$check$0::load$($String* name, bool initialize) {
	$loadClass(FilePermissionTest$$Lambda$lambda$check$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FilePermissionTest$$Lambda$lambda$check$0::class$ = nullptr;

$MethodInfo _FilePermissionTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FilePermissionTest, init$, void)},
	{"check", "(Ljava/util/List;Ljava/lang/String;)V", "(Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(FilePermissionTest, check, void, $List*, $String*)},
	{"lambda$check$0", "(Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(FilePermissionTest, lambda$check$0, void, $StringBuilder*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(FilePermissionTest, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _FilePermissionTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"FilePermissionTest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_FilePermissionTest_MethodInfo_
};

$Object* allocate$FilePermissionTest($Class* clazz) {
	return $of($alloc(FilePermissionTest));
}

void FilePermissionTest::init$() {
}

void FilePermissionTest::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($File, realFile, $new($File, "exist.file"_s));
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (!realFile->createNewFile()) {
				$throwNew($RuntimeException, "Unable to create a file."_s);
			}
			check($($Arrays::asList($$new($StringArray, {
				$(realFile->getName()),
				"notexist.file"_s
			}))), $nc(args)->get(0));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (realFile->exists()) {
				realFile->delete$();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void FilePermissionTest::check($List* files, $String* expected) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, actual, $new($StringBuilder));
	$nc(files)->forEach(static_cast<$Consumer*>($$new(FilePermissionTest$$Lambda$lambda$check$0, actual)));
	if (!$nc(expected)->equals($(actual->toString()))) {
		$throwNew($RuntimeException, $$str({"Failed: "_s, expected, "/"_s, actual}));
	}
}

void FilePermissionTest::lambda$check$0($StringBuilder* actual, $String* f) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, result, $new($StringBuilder));
	$var($FilePermission, fp1, $new($FilePermission, f, "read"_s));
	$var($FilePermission, fp2, $new($FilePermission, $($$new($File, f)->getAbsolutePath()), "read"_s));
	result->append(fp1->equals(fp2));
	result->append(fp1->implies(fp2));
	int32_t var$0 = fp1->hashCode();
	result->append(var$0 == fp2->hashCode());
	$nc($System::out)->println($$str({fp1, " Vs. "_s, fp2, " : Result: "_s, result}));
	$nc(actual)->append(static_cast<$CharSequence*>(result));
}

FilePermissionTest::FilePermissionTest() {
}

$Class* FilePermissionTest::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(FilePermissionTest$$Lambda$lambda$check$0::classInfo$.name)) {
			return FilePermissionTest$$Lambda$lambda$check$0::load$(name, initialize);
		}
	}
	$loadClass(FilePermissionTest, name, initialize, &_FilePermissionTest_ClassInfo_, allocate$FilePermissionTest);
	return class$;
}

$Class* FilePermissionTest::class$ = nullptr;