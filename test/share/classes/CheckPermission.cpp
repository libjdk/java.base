#include <CheckPermission.h>

#include <CheckPermission$1.h>
#include <CheckPermission$2.h>
#include <CheckPermission$3.h>
#include <CheckPermission$Checks.h>
#include <CheckPermission$FileOperation.h>
#include <CheckPermission$LoggingSecurityManager.h>
#include <java/io/File.h>
#include <java/io/FileFilter.h>
#include <java/io/FilenameFilter.h>
#include <java/lang/Enum.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/ThreadLocal.h>
#include <java/security/Permission.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef CHECK_PERMISSION_TEST
#undef DELETE
#undef EXEC
#undef READ
#undef WRITE

using $CheckPermission$1 = ::CheckPermission$1;
using $CheckPermission$2 = ::CheckPermission$2;
using $CheckPermission$3 = ::CheckPermission$3;
using $CheckPermission$Checks = ::CheckPermission$Checks;
using $CheckPermission$FileOperation = ::CheckPermission$FileOperation;
using $CheckPermission$LoggingSecurityManager = ::CheckPermission$LoggingSecurityManager;
using $File = ::java::io::File;
using $FileFilter = ::java::io::FileFilter;
using $FilenameFilter = ::java::io::FilenameFilter;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $Permission = ::java::security::Permission;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;

$FieldInfo _CheckPermission_FieldInfo_[] = {
	{"CHECK_PERMISSION_TEST", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CheckPermission, CHECK_PERMISSION_TEST)},
	{"myChecks", "Ljava/lang/ThreadLocal;", "Ljava/lang/ThreadLocal<LCheckPermission$Checks;>;", $STATIC, $staticField(CheckPermission, myChecks)},
	{"testFile", "Ljava/io/File;", nullptr, $STATIC, $staticField(CheckPermission, testFile)},
	{"another", "Ljava/io/File;", nullptr, $STATIC, $staticField(CheckPermission, another)},
	{}
};

$MethodInfo _CheckPermission_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CheckPermission, init$, void)},
	{"assertCheckOperation", "(Ljava/io/File;Ljava/util/Set;)V", "(Ljava/io/File;Ljava/util/Set<LCheckPermission$FileOperation;>;)V", $STATIC, $staticMethod(CheckPermission, assertCheckOperation, void, $File*, $Set*)},
	{"assertCheckPermission", "(Ljava/lang/Class;Ljava/lang/String;)V", "(Ljava/lang/Class<+Ljava/security/Permission;>;Ljava/lang/String;)V", $STATIC, $staticMethod(CheckPermission, assertCheckPermission, void, $Class*, $String*)},
	{"assertCheckPropertyAccess", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(CheckPermission, assertCheckPropertyAccess, void, $String*)},
	{"assertChecked", "(Ljava/io/File;Ljava/util/List;)V", "(Ljava/io/File;Ljava/util/List<Ljava/lang/String;>;)V", $STATIC, $staticMethod(CheckPermission, assertChecked, void, $File*, $List*)},
	{"assertNotCheckOperation", "(Ljava/io/File;Ljava/util/Set;)V", "(Ljava/io/File;Ljava/util/Set<LCheckPermission$FileOperation;>;)V", $STATIC, $staticMethod(CheckPermission, assertNotCheckOperation, void, $File*, $Set*)},
	{"assertNotChecked", "(Ljava/io/File;Ljava/util/List;)V", "(Ljava/io/File;Ljava/util/List<Ljava/lang/String;>;)V", $STATIC, $staticMethod(CheckPermission, assertNotChecked, void, $File*, $List*)},
	{"assertOnlyCheckOperation", "(Ljava/io/File;Ljava/util/EnumSet;)V", "(Ljava/io/File;Ljava/util/EnumSet<LCheckPermission$FileOperation;>;)V", $STATIC, $staticMethod(CheckPermission, assertOnlyCheckOperation, void, $File*, $EnumSet*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CheckPermission, main, void, $StringArray*), "java.io.IOException"},
	{"prepare", "()V", nullptr, $STATIC, $staticMethod(CheckPermission, prepare, void)},
	{"setup", "()V", nullptr, $STATIC, $staticMethod(CheckPermission, setup, void)},
	{}
};

$InnerClassInfo _CheckPermission_InnerClassesInfo_[] = {
	{"CheckPermission$LoggingSecurityManager", "CheckPermission", "LoggingSecurityManager", $STATIC},
	{"CheckPermission$Checks", "CheckPermission", "Checks", $STATIC},
	{"CheckPermission$FileOperation", "CheckPermission", "FileOperation", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"CheckPermission$3", nullptr, nullptr, 0},
	{"CheckPermission$2", nullptr, nullptr, 0},
	{"CheckPermission$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _CheckPermission_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"CheckPermission",
	"java.lang.Object",
	nullptr,
	_CheckPermission_FieldInfo_,
	_CheckPermission_MethodInfo_,
	nullptr,
	nullptr,
	_CheckPermission_InnerClassesInfo_,
	nullptr,
	nullptr,
	"CheckPermission$LoggingSecurityManager,CheckPermission$Checks,CheckPermission$FileOperation,CheckPermission$3,CheckPermission$2,CheckPermission$1"
};

$Object* allocate$CheckPermission($Class* clazz) {
	return $of($alloc(CheckPermission));
}

$String* CheckPermission::CHECK_PERMISSION_TEST = nullptr;
$ThreadLocal* CheckPermission::myChecks = nullptr;
$File* CheckPermission::testFile = nullptr;
$File* CheckPermission::another = nullptr;

void CheckPermission::init$() {
}

void CheckPermission::prepare() {
	$init(CheckPermission);
	$nc(CheckPermission::myChecks)->set($$new($CheckPermission$Checks));
}

void CheckPermission::assertCheckPermission($Class* type, $String* name) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(($cast($CheckPermission$Checks, $($nc(CheckPermission::myChecks)->get()))))->permissionsChecked()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Permission, perm, $cast($Permission, i$->next()));
			{
				bool var$0 = $nc(type)->isInstance(perm);
				if (var$0 && $nc($($nc(perm)->getName()))->equals(name)) {
					return;
				}
			}
		}
	}
	$throwNew($RuntimeException, $$str({$($nc(type)->getName()), "(\""_s, name, "\") not checked"_s}));
}

void CheckPermission::assertCheckPropertyAccess($String* key) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	if (!$nc($($nc(($cast($CheckPermission$Checks, $($nc(CheckPermission::myChecks)->get()))))->propertiesChecked()))->contains(key)) {
		$throwNew($RuntimeException, $$str({"Property "_s, key, " not checked"_s}));
	}
}

void CheckPermission::assertChecked($File* file, $List* list) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	if (list != nullptr && !list->isEmpty()) {
		{
			$var($Iterator, i$, list->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, path, $cast($String, i$->next()));
				{
					if ($nc(path)->equals($($nc(file)->getPath()))) {
						return;
					}
				}
			}
		}
	}
	$throwNew($RuntimeException, "Access not checked"_s);
}

void CheckPermission::assertNotChecked($File* file, $List* list) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	if (list != nullptr && !list->isEmpty()) {
		{
			$var($Iterator, i$, list->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, path, $cast($String, i$->next()));
				{
					if ($nc(path)->equals($($nc(file)->getPath()))) {
						$throwNew($RuntimeException, "Access checked"_s);
					}
				}
			}
		}
	}
}

void CheckPermission::assertCheckOperation($File* file, $Set* ops) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(ops)->iterator());
		for (; $nc(i$)->hasNext();) {
			$CheckPermission$FileOperation* op = $cast($CheckPermission$FileOperation, i$->next());
			assertChecked(file, $($nc(($cast($CheckPermission$Checks, $($nc(CheckPermission::myChecks)->get()))))->fileOperationChecked(op)));
		}
	}
}

void CheckPermission::assertNotCheckOperation($File* file, $Set* ops) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(ops)->iterator());
		for (; $nc(i$)->hasNext();) {
			$CheckPermission$FileOperation* op = $cast($CheckPermission$FileOperation, i$->next());
			assertNotChecked(file, $($nc(($cast($CheckPermission$Checks, $($nc(CheckPermission::myChecks)->get()))))->fileOperationChecked(op)));
		}
	}
}

void CheckPermission::assertOnlyCheckOperation($File* file, $EnumSet* ops) {
	$init(CheckPermission);
	assertCheckOperation(file, ops);
	assertNotCheckOperation(file, $($EnumSet::complementOf(ops)));
}

void CheckPermission::setup() {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	$assignStatic(CheckPermission::testFile, $new($File, $$str({CheckPermission::CHECK_PERMISSION_TEST, $$str($System::currentTimeMillis())})));
	if ($nc(CheckPermission::testFile)->exists()) {
		$nc(CheckPermission::testFile)->delete$();
	}
	$assignStatic(CheckPermission::another, $new($File, $$str({CheckPermission::CHECK_PERMISSION_TEST, "Another"_s, $$str($System::currentTimeMillis())})));
	if ($nc(CheckPermission::another)->exists()) {
		$nc(CheckPermission::another)->delete$();
	}
	$CheckPermission$LoggingSecurityManager::install();
}

void CheckPermission::main($StringArray* args) {
	$init(CheckPermission);
	$useLocalCurrentObjectStackCache();
	setup();
	prepare();
	$nc(CheckPermission::testFile)->canRead();
	$init($CheckPermission$FileOperation);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->canWrite();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->exists();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->isDirectory();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->isFile();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->isHidden();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->lastModified();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->length();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->createNewFile();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->list();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->list($$new($CheckPermission$1));
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->listFiles();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->listFiles(static_cast<$FilenameFilter*>($$new($CheckPermission$2)));
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->listFiles(static_cast<$FileFilter*>($$new($CheckPermission$3)));
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	prepare();
	$nc(CheckPermission::testFile)->mkdir();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	if ($nc(CheckPermission::testFile)->exists()) {
		prepare();
		$nc(CheckPermission::testFile)->mkdirs();
		assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	}
	if (!$nc(CheckPermission::another)->exists()) {
		prepare();
		$nc(CheckPermission::another)->mkdirs();
		assertOnlyCheckOperation(CheckPermission::another, $($EnumSet::of(static_cast<$Enum*>($CheckPermission$FileOperation::READ), static_cast<$Enum*>($CheckPermission$FileOperation::WRITE))));
	}
	prepare();
	$nc(CheckPermission::another)->delete$();
	assertOnlyCheckOperation(CheckPermission::another, $($EnumSet::of($CheckPermission$FileOperation::DELETE)));
	prepare();
	bool renRst = $nc(CheckPermission::testFile)->renameTo(CheckPermission::another);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	assertOnlyCheckOperation(CheckPermission::another, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	if (renRst) {
		if ($nc(CheckPermission::testFile)->exists()) {
			$throwNew($RuntimeException, $$str({CheckPermission::testFile, " is already renamed to "_s, CheckPermission::another}));
		}
		$assignStatic(CheckPermission::testFile, CheckPermission::another);
	}
	prepare();
	$nc(CheckPermission::testFile)->setLastModified(0);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setReadOnly();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setWritable(true, true);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setWritable(true);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setReadable(true, true);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setReadable(true);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setExecutable(true, true);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->setExecutable(true);
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	prepare();
	$nc(CheckPermission::testFile)->canExecute();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::EXEC)));
	prepare();
	$nc(CheckPermission::testFile)->getTotalSpace();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	$load($RuntimePermission);
	assertCheckPermission($RuntimePermission::class$, "getFileSystemAttributes"_s);
	prepare();
	$nc(CheckPermission::testFile)->getFreeSpace();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	assertCheckPermission($RuntimePermission::class$, "getFileSystemAttributes"_s);
	prepare();
	$nc(CheckPermission::testFile)->getUsableSpace();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::READ)));
	assertCheckPermission($RuntimePermission::class$, "getFileSystemAttributes"_s);
	prepare();
	$var($File, tmpFile, $File::createTempFile(CheckPermission::CHECK_PERMISSION_TEST, nullptr));
	assertOnlyCheckOperation(tmpFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	$nc(tmpFile)->delete$();
	assertCheckOperation(tmpFile, $($EnumSet::of($CheckPermission$FileOperation::DELETE)));
	prepare();
	$assign(tmpFile, $File::createTempFile(CheckPermission::CHECK_PERMISSION_TEST, nullptr, nullptr));
	assertOnlyCheckOperation(tmpFile, $($EnumSet::of($CheckPermission$FileOperation::WRITE)));
	tmpFile->delete$();
	assertCheckOperation(tmpFile, $($EnumSet::of($CheckPermission$FileOperation::DELETE)));
	prepare();
	$nc(CheckPermission::testFile)->deleteOnExit();
	assertOnlyCheckOperation(CheckPermission::testFile, $($EnumSet::of($CheckPermission$FileOperation::DELETE)));
}

void clinit$CheckPermission($Class* class$) {
	$assignStatic(CheckPermission::CHECK_PERMISSION_TEST, "CheckPermissionTest"_s);
	$assignStatic(CheckPermission::myChecks, $new($ThreadLocal));
}

CheckPermission::CheckPermission() {
}

$Class* CheckPermission::load$($String* name, bool initialize) {
	$loadClass(CheckPermission, name, initialize, &_CheckPermission_ClassInfo_, clinit$CheckPermission, allocate$CheckPermission);
	return class$;
}

$Class* CheckPermission::class$ = nullptr;