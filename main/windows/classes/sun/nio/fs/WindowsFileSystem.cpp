#include <sun/nio/fs/WindowsFileSystem.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Iterable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/PathMatcher.h>
#include <java/nio/file/WatchService.h>
#include <java/nio/file/attribute/UserPrincipalLookupService.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/security/Permission.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/regex/Pattern.h>
#include <sun/nio/fs/Globs.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsFileSystem$1.h>
#include <sun/nio/fs/WindowsFileSystem$2.h>
#include <sun/nio/fs/WindowsFileSystem$LookupService.h>
#include <sun/nio/fs/WindowsFileSystemProvider.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsPath.h>
#include <sun/nio/fs/WindowsPathParser$Result.h>
#include <sun/nio/fs/WindowsPathParser.h>
#include <sun/nio/fs/WindowsPathType.h>
#include <sun/nio/fs/WindowsWatchService.h>
#include <jcpp.h>

#undef ABSOLUTE
#undef CASE_INSENSITIVE
#undef GLOB_SYNTAX
#undef REGEX_SYNTAX
#undef UNC
#undef UNICODE_CASE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $FileSystem = ::java::nio::file::FileSystem;
using $Path = ::java::nio::file::Path;
using $PathMatcher = ::java::nio::file::PathMatcher;
using $WatchService = ::java::nio::file::WatchService;
using $UserPrincipalLookupService = ::java::nio::file::attribute::UserPrincipalLookupService;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $Permission = ::java::security::Permission;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $Pattern = ::java::util::regex::Pattern;
using $Globs = ::sun::nio::fs::Globs;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsFileSystem$1 = ::sun::nio::fs::WindowsFileSystem$1;
using $WindowsFileSystem$2 = ::sun::nio::fs::WindowsFileSystem$2;
using $WindowsFileSystem$LookupService = ::sun::nio::fs::WindowsFileSystem$LookupService;
using $WindowsFileSystemProvider = ::sun::nio::fs::WindowsFileSystemProvider;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsPath = ::sun::nio::fs::WindowsPath;
using $WindowsPathParser = ::sun::nio::fs::WindowsPathParser;
using $WindowsPathParser$Result = ::sun::nio::fs::WindowsPathParser$Result;
using $WindowsPathType = ::sun::nio::fs::WindowsPathType;
using $WindowsWatchService = ::sun::nio::fs::WindowsWatchService;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _WindowsFileSystem_FieldInfo_[] = {
	{"provider", "Lsun/nio/fs/WindowsFileSystemProvider;", nullptr, $PRIVATE | $FINAL, $field(WindowsFileSystem, provider$)},
	{"defaultDirectory", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(WindowsFileSystem, defaultDirectory$)},
	{"defaultRoot", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(WindowsFileSystem, defaultRoot$)},
	{"supportedFileAttributeViews", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileSystem, supportedFileAttributeViews$)},
	{"GLOB_SYNTAX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileSystem, GLOB_SYNTAX)},
	{"REGEX_SYNTAX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileSystem, REGEX_SYNTAX)},
	{}
};

$MethodInfo _WindowsFileSystem_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/WindowsFileSystemProvider;Ljava/lang/String;)V", nullptr, 0, $method(WindowsFileSystem, init$, void, $WindowsFileSystemProvider*, $String*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, close, void), "java.io.IOException"},
	{"defaultDirectory", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(WindowsFileSystem, defaultDirectory, $String*)},
	{"defaultRoot", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(WindowsFileSystem, defaultRoot, $String*)},
	{"getFileStores", "()Ljava/lang/Iterable;", "()Ljava/lang/Iterable<Ljava/nio/file/FileStore;>;", $PUBLIC, $virtualMethod(WindowsFileSystem, getFileStores, $Iterable*)},
	{"getPath", "(Ljava/lang/String;[Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PUBLIC | $FINAL | $TRANSIENT, $virtualMethod(WindowsFileSystem, getPath, $Path*, $String*, $StringArray*)},
	{"getPathMatcher", "(Ljava/lang/String;)Ljava/nio/file/PathMatcher;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, getPathMatcher, $PathMatcher*, $String*)},
	{"getRootDirectories", "()Ljava/lang/Iterable;", "()Ljava/lang/Iterable<Ljava/nio/file/Path;>;", $PUBLIC, $virtualMethod(WindowsFileSystem, getRootDirectories, $Iterable*)},
	{"getSeparator", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, getSeparator, $String*)},
	{"getUserPrincipalLookupService", "()Ljava/nio/file/attribute/UserPrincipalLookupService;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, getUserPrincipalLookupService, $UserPrincipalLookupService*)},
	{"isOpen", "()Z", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, isOpen, bool)},
	{"isReadOnly", "()Z", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, isReadOnly, bool)},
	{"newWatchService", "()Ljava/nio/file/WatchService;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, newWatchService, $WatchService*), "java.io.IOException"},
	{"provider", "()Ljava/nio/file/spi/FileSystemProvider;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystem, provider, $FileSystemProvider*)},
	{"supportedFileAttributeViews", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(WindowsFileSystem, supportedFileAttributeViews, $Set*)},
	{}
};

$InnerClassInfo _WindowsFileSystem_InnerClassesInfo_[] = {
	{"sun.nio.fs.WindowsFileSystem$LookupService", "sun.nio.fs.WindowsFileSystem", "LookupService", $PRIVATE | $STATIC},
	{"sun.nio.fs.WindowsFileSystem$FileStoreIterator", "sun.nio.fs.WindowsFileSystem", "FileStoreIterator", $PRIVATE},
	{"sun.nio.fs.WindowsFileSystem$2", nullptr, nullptr, 0},
	{"sun.nio.fs.WindowsFileSystem$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WindowsFileSystem_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsFileSystem",
	"java.nio.file.FileSystem",
	nullptr,
	_WindowsFileSystem_FieldInfo_,
	_WindowsFileSystem_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsFileSystem_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.WindowsFileSystem$LookupService,sun.nio.fs.WindowsFileSystem$LookupService$1,sun.nio.fs.WindowsFileSystem$FileStoreIterator,sun.nio.fs.WindowsFileSystem$2,sun.nio.fs.WindowsFileSystem$1"
};

$Object* allocate$WindowsFileSystem($Class* clazz) {
	return $of($alloc(WindowsFileSystem));
}

$Set* WindowsFileSystem::supportedFileAttributeViews$ = nullptr;
$String* WindowsFileSystem::GLOB_SYNTAX = nullptr;
$String* WindowsFileSystem::REGEX_SYNTAX = nullptr;

void WindowsFileSystem::init$($WindowsFileSystemProvider* provider, $String* dir) {
	$FileSystem::init$();
	$set(this, provider$, provider);
	$var($WindowsPathParser$Result, result, $WindowsPathParser::parse(dir));
	$init($WindowsPathType);
	bool var$0 = ($nc(result)->type() != $WindowsPathType::ABSOLUTE);
	if (var$0 && (result->type() != $WindowsPathType::UNC)) {
		$throwNew($AssertionError, $of("Default directory is not an absolute path"_s));
	}
	$set(this, defaultDirectory$, $nc(result)->path());
	$set(this, defaultRoot$, result->root());
}

$String* WindowsFileSystem::defaultDirectory() {
	return this->defaultDirectory$;
}

$String* WindowsFileSystem::defaultRoot() {
	return this->defaultRoot$;
}

$FileSystemProvider* WindowsFileSystem::provider() {
	return this->provider$;
}

$String* WindowsFileSystem::getSeparator() {
	return "\\"_s;
}

bool WindowsFileSystem::isOpen() {
	return true;
}

bool WindowsFileSystem::isReadOnly() {
	return false;
}

void WindowsFileSystem::close() {
	$throwNew($UnsupportedOperationException);
}

$Iterable* WindowsFileSystem::getRootDirectories() {
	$useLocalCurrentObjectStackCache();
	int32_t drives = 0;
	try {
		drives = $WindowsNativeDispatcher::GetLogicalDrives();
	} catch ($WindowsException& x) {
		$throwNew($AssertionError, $($of(x->getMessage())));
	}
	$var($ArrayList, result, $new($ArrayList));
	$var($SecurityManager, sm, $System::getSecurityManager());
	for (int32_t i = 0; i <= 25; ++i) {
		if (((int32_t)(drives & (uint32_t)($sl(1, i)))) != 0) {
			$var($StringBuilder, sb, $new($StringBuilder, 3));
			sb->append((char16_t)(u'A' + i));
			sb->append(":\\"_s);
			$var($String, root, sb->toString());
			if (sm != nullptr) {
				try {
					sm->checkRead(root);
				} catch ($SecurityException& x) {
					continue;
				}
			}
			result->add($($WindowsPath::createFromNormalizedPath(this, root)));
		}
	}
	return $Collections::unmodifiableList(result);
}

$Iterable* WindowsFileSystem::getFileStores() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		try {
			sm->checkPermission($$new($RuntimePermission, "getFileStoreAttributes"_s));
		} catch ($SecurityException& se) {
			return $Collections::emptyList();
		}
	}
	return $new($WindowsFileSystem$1, this);
}

$Set* WindowsFileSystem::supportedFileAttributeViews() {
	return WindowsFileSystem::supportedFileAttributeViews$;
}

$Path* WindowsFileSystem::getPath($String* first, $StringArray* more) {
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
							sb->append(u'\\');
						}
						sb->append(segment);
					}
				}
			}
		}
		$assign(path, sb->toString());
	}
	return $WindowsPath::parse(this, path);
}

$UserPrincipalLookupService* WindowsFileSystem::getUserPrincipalLookupService() {
	$init($WindowsFileSystem$LookupService);
	return $WindowsFileSystem$LookupService::instance;
}

$PathMatcher* WindowsFileSystem::getPathMatcher($String* syntaxAndInput) {
	$useLocalCurrentObjectStackCache();
	int32_t pos = $nc(syntaxAndInput)->indexOf((int32_t)u':');
	if (pos <= 0 || pos == syntaxAndInput->length()) {
		$throwNew($IllegalArgumentException);
	}
	$var($String, syntax, syntaxAndInput->substring(0, pos));
	$var($String, input, syntaxAndInput->substring(pos + 1));
	$var($String, expr, nullptr);
	if (syntax->equalsIgnoreCase(WindowsFileSystem::GLOB_SYNTAX)) {
		$assign(expr, $Globs::toWindowsRegexPattern(input));
	} else if (syntax->equalsIgnoreCase(WindowsFileSystem::REGEX_SYNTAX)) {
		$assign(expr, input);
	} else {
		$throwNew($UnsupportedOperationException, $$str({"Syntax \'"_s, syntax, "\' not recognized"_s}));
	}
	$var($Pattern, pattern, $Pattern::compile(expr, $Pattern::CASE_INSENSITIVE | $Pattern::UNICODE_CASE));
	return $new($WindowsFileSystem$2, this, pattern);
}

$WatchService* WindowsFileSystem::newWatchService() {
	return $new($WindowsWatchService, this);
}

void clinit$WindowsFileSystem($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(WindowsFileSystem::GLOB_SYNTAX, "glob"_s);
	$assignStatic(WindowsFileSystem::REGEX_SYNTAX, "regex"_s);
	$assignStatic(WindowsFileSystem::supportedFileAttributeViews$, $Collections::unmodifiableSet($$new($HashSet, $(static_cast<$Collection*>($Arrays::asList($$new($StringArray, {
		"basic"_s,
		"dos"_s,
		"acl"_s,
		"owner"_s,
		"user"_s
	})))))));
}

WindowsFileSystem::WindowsFileSystem() {
}

$Class* WindowsFileSystem::load$($String* name, bool initialize) {
	$loadClass(WindowsFileSystem, name, initialize, &_WindowsFileSystem_ClassInfo_, clinit$WindowsFileSystem, allocate$WindowsFileSystem);
	return class$;
}

$Class* WindowsFileSystem::class$ = nullptr;

		} // fs
	} // nio
} // sun