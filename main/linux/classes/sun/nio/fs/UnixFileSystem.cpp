#include <sun/nio/fs/UnixFileSystem.h>

#include <java/lang/Iterable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/file/FileStore.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/PathMatcher.h>
#include <java/nio/file/attribute/UserPrincipalLookupService.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/security/Permission.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/regex/Pattern.h>
#include <sun/nio/fs/Globs.h>
#include <sun/nio/fs/UnixFileSystem$1.h>
#include <sun/nio/fs/UnixFileSystem$2.h>
#include <sun/nio/fs/UnixFileSystem$3.h>
#include <sun/nio/fs/UnixFileSystem$LookupService.h>
#include <sun/nio/fs/UnixFileSystemProvider.h>
#include <sun/nio/fs/UnixMountEntry.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/Util.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef GLOB_SYNTAX
#undef REGEX_SYNTAX

using $PathArray = $Array<::java::nio::file::Path>;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $FileStore = ::java::nio::file::FileStore;
using $FileSystem = ::java::nio::file::FileSystem;
using $Path = ::java::nio::file::Path;
using $PathMatcher = ::java::nio::file::PathMatcher;
using $UserPrincipalLookupService = ::java::nio::file::attribute::UserPrincipalLookupService;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $Permission = ::java::security::Permission;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Pattern = ::java::util::regex::Pattern;
using $Globs = ::sun::nio::fs::Globs;
using $UnixFileSystem$1 = ::sun::nio::fs::UnixFileSystem$1;
using $UnixFileSystem$2 = ::sun::nio::fs::UnixFileSystem$2;
using $UnixFileSystem$3 = ::sun::nio::fs::UnixFileSystem$3;
using $UnixFileSystem$LookupService = ::sun::nio::fs::UnixFileSystem$LookupService;
using $UnixFileSystemProvider = ::sun::nio::fs::UnixFileSystemProvider;
using $UnixMountEntry = ::sun::nio::fs::UnixMountEntry;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $Util = ::sun::nio::fs::Util;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixFileSystem_FieldInfo_[] = {
	{"provider", "Lsun/nio/fs/UnixFileSystemProvider;", nullptr, $PRIVATE | $FINAL, $field(UnixFileSystem, provider$)},
	{"defaultDirectory", "[B", nullptr, $PRIVATE | $FINAL, $field(UnixFileSystem, defaultDirectory$)},
	{"needToResolveAgainstDefaultDirectory", "Z", nullptr, $PRIVATE | $FINAL, $field(UnixFileSystem, needToResolveAgainstDefaultDirectory$)},
	{"rootDirectory", "Lsun/nio/fs/UnixPath;", nullptr, $PRIVATE | $FINAL, $field(UnixFileSystem, rootDirectory$)},
	{"GLOB_SYNTAX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileSystem, GLOB_SYNTAX)},
	{"REGEX_SYNTAX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileSystem, REGEX_SYNTAX)},
	{}
};

$MethodInfo _UnixFileSystem_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/UnixFileSystemProvider;Ljava/lang/String;)V", nullptr, 0, $method(UnixFileSystem, init$, void, $UnixFileSystemProvider*, $String*)},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, close, void), "java.io.IOException"},
	{"compilePathMatchPattern", "(Ljava/lang/String;)Ljava/util/regex/Pattern;", nullptr, 0, $virtualMethod(UnixFileSystem, compilePathMatchPattern, $Pattern*, $String*)},
	{"copyNonPosixAttributes", "(II)V", nullptr, 0, $virtualMethod(UnixFileSystem, copyNonPosixAttributes, void, int32_t, int32_t)},
	{"defaultDirectory", "()[B", nullptr, 0, $virtualMethod(UnixFileSystem, defaultDirectory, $bytes*)},
	{"getFileStore", "(Lsun/nio/fs/UnixMountEntry;)Ljava/nio/file/FileStore;", nullptr, $ABSTRACT, $virtualMethod(UnixFileSystem, getFileStore, $FileStore*, $UnixMountEntry*), "java.io.IOException"},
	{"getFileStores", "()Ljava/lang/Iterable;", "()Ljava/lang/Iterable<Ljava/nio/file/FileStore;>;", $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, getFileStores, $Iterable*)},
	{"getMountEntries", "()Ljava/lang/Iterable;", "()Ljava/lang/Iterable<Lsun/nio/fs/UnixMountEntry;>;", $ABSTRACT, $virtualMethod(UnixFileSystem, getMountEntries, $Iterable*)},
	{"getPath", "(Ljava/lang/String;[Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PUBLIC | $FINAL | $TRANSIENT, $virtualMethod(UnixFileSystem, getPath, $Path*, $String*, $StringArray*)},
	{"getPathMatcher", "(Ljava/lang/String;)Ljava/nio/file/PathMatcher;", nullptr, $PUBLIC, $virtualMethod(UnixFileSystem, getPathMatcher, $PathMatcher*, $String*)},
	{"getRootDirectories", "()Ljava/lang/Iterable;", "()Ljava/lang/Iterable<Ljava/nio/file/Path;>;", $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, getRootDirectories, $Iterable*)},
	{"getSeparator", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, getSeparator, $String*)},
	{"getUserPrincipalLookupService", "()Ljava/nio/file/attribute/UserPrincipalLookupService;", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, getUserPrincipalLookupService, $UserPrincipalLookupService*)},
	{"isOpen", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, isOpen, bool)},
	{"isReadOnly", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, isReadOnly, bool)},
	{"needToResolveAgainstDefaultDirectory", "()Z", nullptr, 0, $virtualMethod(UnixFileSystem, needToResolveAgainstDefaultDirectory, bool)},
	{"normalizeJavaPath", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $virtualMethod(UnixFileSystem, normalizeJavaPath, $String*, $String*)},
	{"normalizeNativePath", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $virtualMethod(UnixFileSystem, normalizeNativePath, $String*, $String*)},
	{"provider", "()Ljava/nio/file/spi/FileSystemProvider;", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystem, provider, $FileSystemProvider*)},
	{"rootDirectory", "()Lsun/nio/fs/UnixPath;", nullptr, 0, $virtualMethod(UnixFileSystem, rootDirectory, $UnixPath*)},
	{"standardFileAttributeViews", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $STATIC, $staticMethod(UnixFileSystem, standardFileAttributeViews, $List*)},
	{}
};

$InnerClassInfo _UnixFileSystem_InnerClassesInfo_[] = {
	{"sun.nio.fs.UnixFileSystem$LookupService", "sun.nio.fs.UnixFileSystem", "LookupService", $PRIVATE | $STATIC},
	{"sun.nio.fs.UnixFileSystem$FileStoreIterator", "sun.nio.fs.UnixFileSystem", "FileStoreIterator", $PRIVATE},
	{"sun.nio.fs.UnixFileSystem$3", nullptr, nullptr, 0},
	{"sun.nio.fs.UnixFileSystem$2", nullptr, nullptr, 0},
	{"sun.nio.fs.UnixFileSystem$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnixFileSystem_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.UnixFileSystem",
	"java.nio.file.FileSystem",
	nullptr,
	_UnixFileSystem_FieldInfo_,
	_UnixFileSystem_MethodInfo_,
	nullptr,
	nullptr,
	_UnixFileSystem_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.UnixFileSystem$LookupService,sun.nio.fs.UnixFileSystem$LookupService$1,sun.nio.fs.UnixFileSystem$FileStoreIterator,sun.nio.fs.UnixFileSystem$3,sun.nio.fs.UnixFileSystem$2,sun.nio.fs.UnixFileSystem$1"
};

$Object* allocate$UnixFileSystem($Class* clazz) {
	return $of($alloc(UnixFileSystem));
}

$String* UnixFileSystem::GLOB_SYNTAX = nullptr;
$String* UnixFileSystem::REGEX_SYNTAX = nullptr;

void UnixFileSystem::init$($UnixFileSystemProvider* provider, $String* dir) {
	$useLocalCurrentObjectStackCache();
	$FileSystem::init$();
	$set(this, provider$, provider);
	$set(this, defaultDirectory$, $Util::toBytes($($UnixPath::normalizeAndCheck(dir))));
	if ($nc(this->defaultDirectory$)->get(0) != u'/') {
		$throwNew($RuntimeException, "default directory must be absolute"_s);
	}
	$var($String, propValue, $GetPropertyAction::privilegedGetProperty("sun.nio.fs.chdirAllowed"_s, "false"_s));
	bool chdirAllowed = $nc(propValue)->isEmpty() ? true : $Boolean::parseBoolean(propValue);
	if (chdirAllowed) {
		this->needToResolveAgainstDefaultDirectory$ = true;
	} else {
		$var($bytes, cwd, $UnixNativeDispatcher::getcwd());
		bool defaultIsCwd = ($nc(cwd)->length == $nc(this->defaultDirectory$)->length);
		if (defaultIsCwd) {
			for (int32_t i = 0; i < cwd->length; ++i) {
				if (cwd->get(i) != $nc(this->defaultDirectory$)->get(i)) {
					defaultIsCwd = false;
					break;
				}
			}
		}
		this->needToResolveAgainstDefaultDirectory$ = !defaultIsCwd;
	}
	$set(this, rootDirectory$, $new($UnixPath, this, "/"_s));
}

$bytes* UnixFileSystem::defaultDirectory() {
	return this->defaultDirectory$;
}

bool UnixFileSystem::needToResolveAgainstDefaultDirectory() {
	return this->needToResolveAgainstDefaultDirectory$;
}

$UnixPath* UnixFileSystem::rootDirectory() {
	return this->rootDirectory$;
}

$List* UnixFileSystem::standardFileAttributeViews() {
	$init(UnixFileSystem);
	return $Arrays::asList($$new($StringArray, {
		"basic"_s,
		"posix"_s,
		"unix"_s,
		"owner"_s
	}));
}

$FileSystemProvider* UnixFileSystem::provider() {
	return this->provider$;
}

$String* UnixFileSystem::getSeparator() {
	return "/"_s;
}

bool UnixFileSystem::isOpen() {
	return true;
}

bool UnixFileSystem::isReadOnly() {
	return false;
}

void UnixFileSystem::close() {
	$throwNew($UnsupportedOperationException);
}

void UnixFileSystem::copyNonPosixAttributes(int32_t sfd, int32_t tfd) {
}

$Iterable* UnixFileSystem::getRootDirectories() {
	$useLocalCurrentObjectStackCache();
	$var($List, allowedList, $Collections::unmodifiableList($($Arrays::asList($$new($PathArray, {static_cast<$Path*>(this->rootDirectory$)})))));
	return $new($UnixFileSystem$1, this, allowedList);
}

$Iterable* UnixFileSystem::getFileStores() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		try {
			sm->checkPermission($$new($RuntimePermission, "getFileStoreAttributes"_s));
		} catch ($SecurityException& se) {
			return $Collections::emptyList();
		}
	}
	return $new($UnixFileSystem$2, this);
}

$Path* UnixFileSystem::getPath($String* first, $StringArray* more) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(first);
	$var($String, path, nullptr);
	if ($nc(more)->length == 0) {
		$assign(path, first);
	} else {
		$var($StringBuilder, sb, $new($StringBuilder));
		sb->append(first);
		{
			$var($StringArray, arr$, more);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, segment, arr$->get(i$));
				{
					if (!$nc(segment)->isEmpty()) {
						if (sb->length() > 0) {
							sb->append(u'/');
						}
						sb->append(segment);
					}
				}
			}
		}
		$assign(path, sb->toString());
	}
	return $new($UnixPath, this, path);
}

$PathMatcher* UnixFileSystem::getPathMatcher($String* syntaxAndInput) {
	$useLocalCurrentObjectStackCache();
	int32_t pos = $nc(syntaxAndInput)->indexOf((int32_t)u':');
	if (pos <= 0 || pos == syntaxAndInput->length()) {
		$throwNew($IllegalArgumentException);
	}
	$var($String, syntax, syntaxAndInput->substring(0, pos));
	$var($String, input, syntaxAndInput->substring(pos + 1));
	$var($String, expr, nullptr);
	if (syntax->equalsIgnoreCase(UnixFileSystem::GLOB_SYNTAX)) {
		$assign(expr, $Globs::toUnixRegexPattern(input));
	} else if (syntax->equalsIgnoreCase(UnixFileSystem::REGEX_SYNTAX)) {
		$assign(expr, input);
	} else {
		$throwNew($UnsupportedOperationException, $$str({"Syntax \'"_s, syntax, "\' not recognized"_s}));
	}
	$var($Pattern, pattern, compilePathMatchPattern(expr));
	return $new($UnixFileSystem$3, this, pattern);
}

$UserPrincipalLookupService* UnixFileSystem::getUserPrincipalLookupService() {
	$init($UnixFileSystem$LookupService);
	return $UnixFileSystem$LookupService::instance;
}

$Pattern* UnixFileSystem::compilePathMatchPattern($String* expr) {
	return $Pattern::compile(expr);
}

$String* UnixFileSystem::normalizeNativePath($String* path) {
	return path;
}

$String* UnixFileSystem::normalizeJavaPath($String* path) {
	return path;
}

UnixFileSystem::UnixFileSystem() {
}

void clinit$UnixFileSystem($Class* class$) {
	$assignStatic(UnixFileSystem::GLOB_SYNTAX, "glob"_s);
	$assignStatic(UnixFileSystem::REGEX_SYNTAX, "regex"_s);
}

$Class* UnixFileSystem::load$($String* name, bool initialize) {
	$loadClass(UnixFileSystem, name, initialize, &_UnixFileSystem_ClassInfo_, clinit$UnixFileSystem, allocate$UnixFileSystem);
	return class$;
}

$Class* UnixFileSystem::class$ = nullptr;

		} // fs
	} // nio
} // sun