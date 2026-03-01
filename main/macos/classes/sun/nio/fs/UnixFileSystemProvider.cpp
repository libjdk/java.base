#include <sun/nio/fs/UnixFileSystemProvider.h>

#include <java/io/FilePermission.h>
#include <java/lang/AssertionError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URI.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/file/AccessMode.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/DirectoryNotEmptyException.h>
#include <java/nio/file/DirectoryStream$Filter.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileAlreadyExistsException.h>
#include <java/nio/file/FileStore.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystemAlreadyExistsException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/LinkPermission.h>
#include <java/nio/file/NotDirectoryException.h>
#include <java/nio/file/NotLinkException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/attribute/BasicFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/FileOwnerAttributeView.h>
#include <java/nio/file/attribute/PosixFileAttributeView.h>
#include <java/nio/file/attribute/PosixFileAttributes.h>
#include <java/nio/file/spi/FileTypeDetector.h>
#include <java/security/Permission.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ExecutorService.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView.h>
#include <sun/nio/fs/AbstractFileSystemProvider.h>
#include <sun/nio/fs/AbstractFileTypeDetector.h>
#include <sun/nio/fs/DynamicFileAttributeView.h>
#include <sun/nio/fs/FileOwnerAttributeViewImpl.h>
#include <sun/nio/fs/UnixChannelFactory.h>
#include <sun/nio/fs/UnixConstants.h>
#include <sun/nio/fs/UnixCopyFile.h>
#include <sun/nio/fs/UnixDirectoryStream.h>
#include <sun/nio/fs/UnixException.h>
#include <sun/nio/fs/UnixFileAttributeViews$Basic.h>
#include <sun/nio/fs/UnixFileAttributeViews$Posix.h>
#include <sun/nio/fs/UnixFileAttributeViews$Unix.h>
#include <sun/nio/fs/UnixFileAttributeViews.h>
#include <sun/nio/fs/UnixFileAttributes.h>
#include <sun/nio/fs/UnixFileModeAttribute.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <sun/nio/fs/UnixFileSystemProvider$1.h>
#include <sun/nio/fs/UnixFileSystemProvider$2.h>
#include <sun/nio/fs/UnixFileSystemProvider$3.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/UnixSecureDirectoryStream.h>
#include <sun/nio/fs/UnixUriUtils.h>
#include <sun/nio/fs/Util.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef ALL_PERMISSIONS
#undef ALL_READWRITE
#undef EEXIST
#undef EINVAL
#undef EISDIR
#undef EMPTY_PATH
#undef ENOENT
#undef ENOTDIR
#undef ENOTEMPTY
#undef FILE_READLINK_ACTION
#undef F_OK
#undef O_NOFOLLOW
#undef O_RDONLY
#undef R_OK
#undef S_IFDIR
#undef S_IFMT
#undef S_IFREG
#undef USER_DIR
#undef W_OK
#undef X_OK

using $AccessModeArray = $Array<::java::nio::file::AccessMode>;
using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $AbstractFileTypeDetectorArray = $Array<::sun::nio::fs::AbstractFileTypeDetector>;
using $FilePermission = ::java::io::FilePermission;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $URI = ::java::net::URI;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $FileChannel = ::java::nio::channels::FileChannel;
using $SeekableByteChannel = ::java::nio::channels::SeekableByteChannel;
using $AccessMode = ::java::nio::file::AccessMode;
using $DirectoryNotEmptyException = ::java::nio::file::DirectoryNotEmptyException;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $DirectoryStream$Filter = ::java::nio::file::DirectoryStream$Filter;
using $FileAlreadyExistsException = ::java::nio::file::FileAlreadyExistsException;
using $FileStore = ::java::nio::file::FileStore;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystemAlreadyExistsException = ::java::nio::file::FileSystemAlreadyExistsException;
using $LinkPermission = ::java::nio::file::LinkPermission;
using $NotDirectoryException = ::java::nio::file::NotDirectoryException;
using $NotLinkException = ::java::nio::file::NotLinkException;
using $Path = ::java::nio::file::Path;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $BasicFileAttributeView = ::java::nio::file::attribute::BasicFileAttributeView;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $FileOwnerAttributeView = ::java::nio::file::attribute::FileOwnerAttributeView;
using $PosixFileAttributeView = ::java::nio::file::attribute::PosixFileAttributeView;
using $PosixFileAttributes = ::java::nio::file::attribute::PosixFileAttributes;
using $FileTypeDetector = ::java::nio::file::spi::FileTypeDetector;
using $Permission = ::java::security::Permission;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $AbstractBasicFileAttributeView = ::sun::nio::fs::AbstractBasicFileAttributeView;
using $AbstractFileSystemProvider = ::sun::nio::fs::AbstractFileSystemProvider;
using $DynamicFileAttributeView = ::sun::nio::fs::DynamicFileAttributeView;
using $UnixChannelFactory = ::sun::nio::fs::UnixChannelFactory;
using $UnixConstants = ::sun::nio::fs::UnixConstants;
using $UnixCopyFile = ::sun::nio::fs::UnixCopyFile;
using $UnixDirectoryStream = ::sun::nio::fs::UnixDirectoryStream;
using $UnixException = ::sun::nio::fs::UnixException;
using $UnixFileAttributeViews = ::sun::nio::fs::UnixFileAttributeViews;
using $UnixFileAttributeViews$Basic = ::sun::nio::fs::UnixFileAttributeViews$Basic;
using $UnixFileAttributes = ::sun::nio::fs::UnixFileAttributes;
using $UnixFileModeAttribute = ::sun::nio::fs::UnixFileModeAttribute;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;
using $UnixFileSystemProvider$1 = ::sun::nio::fs::UnixFileSystemProvider$1;
using $UnixFileSystemProvider$2 = ::sun::nio::fs::UnixFileSystemProvider$2;
using $UnixFileSystemProvider$3 = ::sun::nio::fs::UnixFileSystemProvider$3;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $UnixSecureDirectoryStream = ::sun::nio::fs::UnixSecureDirectoryStream;
using $UnixUriUtils = ::sun::nio::fs::UnixUriUtils;
using $Util = ::sun::nio::fs::Util;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixFileSystemProvider_FieldInfo_[] = {
	{"USER_DIR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileSystemProvider, USER_DIR)},
	{"EMPTY_PATH", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileSystemProvider, EMPTY_PATH)},
	{"theFileSystem", "Lsun/nio/fs/UnixFileSystem;", nullptr, $PRIVATE | $FINAL, $field(UnixFileSystemProvider, theFileSystem$)},
	{}
};

$MethodInfo _UnixFileSystemProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnixFileSystemProvider, init$, void)},
	{"chain", "([Lsun/nio/fs/AbstractFileTypeDetector;)Ljava/nio/file/spi/FileTypeDetector;", nullptr, $FINAL | $TRANSIENT, $method(UnixFileSystemProvider, chain, $FileTypeDetector*, $AbstractFileTypeDetectorArray*)},
	{"checkAccess", "(Ljava/nio/file/Path;[Ljava/nio/file/AccessMode;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, checkAccess, void, $Path*, $AccessModeArray*), "java.io.IOException"},
	{"checkPath", "(Ljava/nio/file/Path;)Lsun/nio/fs/UnixPath;", nullptr, 0, $virtualMethod(UnixFileSystemProvider, checkPath, $UnixPath*, $Path*)},
	{"checkUri", "(Ljava/net/URI;)V", nullptr, $PRIVATE, $method(UnixFileSystemProvider, checkUri, void, $URI*)},
	{"copy", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, copy, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"createDirectory", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, createDirectory, void, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"createLink", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, createLink, void, $Path*, $Path*), "java.io.IOException"},
	{"createSymbolicLink", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, createSymbolicLink, void, $Path*, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"exists", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystemProvider, exists, bool, $Path*)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljava/nio/file/Path;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, getFileAttributeView, $FileAttributeView*, $Path*, $Class*, $LinkOptionArray*)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Lsun/nio/fs/DynamicFileAttributeView;", nullptr, $PROTECTED | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, getFileAttributeView, $DynamicFileAttributeView*, $Path*, $String*, $LinkOptionArray*)},
	{"getFileStore", "(Lsun/nio/fs/UnixPath;)Ljava/nio/file/FileStore;", nullptr, $ABSTRACT, $virtualMethod(UnixFileSystemProvider, getFileStore, $FileStore*, $UnixPath*), "java.io.IOException"},
	{"getFileStore", "(Ljava/nio/file/Path;)Ljava/nio/file/FileStore;", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, getFileStore, $FileStore*, $Path*), "java.io.IOException"},
	{"getFileSystem", "(Ljava/net/URI;)Ljava/nio/file/FileSystem;", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystemProvider, getFileSystem, $FileSystem*, $URI*)},
	{"getFileTypeDetector", "()Ljava/nio/file/spi/FileTypeDetector;", nullptr, 0, $virtualMethod(UnixFileSystemProvider, getFileTypeDetector, $FileTypeDetector*)},
	{"getPath", "(Ljava/net/URI;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, getPath, $Path*, $URI*)},
	{"getScheme", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystemProvider, getScheme, $String*)},
	{"getSunPathForSocketFile", "(Ljava/nio/file/Path;)[B", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, getSunPathForSocketFile, $bytes*, $Path*)},
	{"implDelete", "(Ljava/nio/file/Path;Z)Z", nullptr, 0, $virtualMethod(UnixFileSystemProvider, implDelete, bool, $Path*, bool), "java.io.IOException"},
	{"isDirectory", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystemProvider, isDirectory, bool, $Path*)},
	{"isHidden", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, isHidden, bool, $Path*)},
	{"isRegularFile", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(UnixFileSystemProvider, isRegularFile, bool, $Path*)},
	{"isSameFile", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, isSameFile, bool, $Path*, $Path*), "java.io.IOException"},
	{"move", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, move, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"newAsynchronousFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/AsynchronousFileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/AsynchronousFileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, newAsynchronousFileChannel, $AsynchronousFileChannel*, $Path*, $Set*, $ExecutorService*, $FileAttributeArray*), "java.io.IOException"},
	{"newByteChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/SeekableByteChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/SeekableByteChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, newByteChannel, $SeekableByteChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newDirectoryStream", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter;)Ljava/nio/file/DirectoryStream;", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter<-Ljava/nio/file/Path;>;)Ljava/nio/file/DirectoryStream<Ljava/nio/file/Path;>;", $PUBLIC, $virtualMethod(UnixFileSystemProvider, newDirectoryStream, $DirectoryStream*, $Path*, $DirectoryStream$Filter*), "java.io.IOException"},
	{"newFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/FileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, newFileChannel, $FileChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/lang/String;)Lsun/nio/fs/UnixFileSystem;", nullptr, $ABSTRACT, $virtualMethod(UnixFileSystemProvider, newFileSystem, $UnixFileSystem*, $String*)},
	{"newFileSystem", "(Ljava/net/URI;Ljava/util/Map;)Ljava/nio/file/FileSystem;", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/nio/file/FileSystem;", $PUBLIC | $FINAL, $virtualMethod(UnixFileSystemProvider, newFileSystem, $FileSystem*, $URI*, $Map*)},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/BasicFileAttributes;", "<A::Ljava/nio/file/attribute/BasicFileAttributes;>(Ljava/nio/file/Path;Ljava/lang/Class<TA;>;[Ljava/nio/file/LinkOption;)TA;", $PUBLIC | $TRANSIENT, $virtualMethod(UnixFileSystemProvider, readAttributes, $BasicFileAttributes*, $Path*, $Class*, $LinkOptionArray*), "java.io.IOException"},
	{"readSymbolicLink", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(UnixFileSystemProvider, readSymbolicLink, $Path*, $Path*), "java.io.IOException"},
	{"theFileSystem", "()Lsun/nio/fs/UnixFileSystem;", nullptr, 0, $virtualMethod(UnixFileSystemProvider, theFileSystem, $UnixFileSystem*)},
	{}
};

$InnerClassInfo _UnixFileSystemProvider_InnerClassesInfo_[] = {
	{"sun.nio.fs.UnixFileSystemProvider$3", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.nio.fs.UnixFileSystemProvider$2", nullptr, nullptr, 0},
	{"sun.nio.fs.UnixFileSystemProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnixFileSystemProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.UnixFileSystemProvider",
	"sun.nio.fs.AbstractFileSystemProvider",
	nullptr,
	_UnixFileSystemProvider_FieldInfo_,
	_UnixFileSystemProvider_MethodInfo_,
	nullptr,
	nullptr,
	_UnixFileSystemProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.UnixFileSystemProvider$3,sun.nio.fs.UnixFileSystemProvider$2,sun.nio.fs.UnixFileSystemProvider$1"
};

$Object* allocate$UnixFileSystemProvider($Class* clazz) {
	return $of($alloc(UnixFileSystemProvider));
}

$String* UnixFileSystemProvider::USER_DIR = nullptr;
$bytes* UnixFileSystemProvider::EMPTY_PATH = nullptr;

void UnixFileSystemProvider::init$() {
	$AbstractFileSystemProvider::init$();
	$var($String, userDir, $System::getProperty(UnixFileSystemProvider::USER_DIR));
	$set(this, theFileSystem$, newFileSystem(userDir));
}

$UnixFileSystem* UnixFileSystemProvider::theFileSystem() {
	return this->theFileSystem$;
}

$String* UnixFileSystemProvider::getScheme() {
	return "file"_s;
}

void UnixFileSystemProvider::checkUri($URI* uri) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($($nc(uri)->getScheme()))->equalsIgnoreCase($(getScheme()))) {
		$throwNew($IllegalArgumentException, "URI does not match this provider"_s);
	}
	if ($nc(uri)->getRawAuthority() != nullptr) {
		$throwNew($IllegalArgumentException, "Authority component present"_s);
	}
	$var($String, path, $nc(uri)->getPath());
	if (path == nullptr) {
		$throwNew($IllegalArgumentException, "Path component is undefined"_s);
	}
	if (!$nc(path)->equals("/"_s)) {
		$throwNew($IllegalArgumentException, "Path component should be \'/\'"_s);
	}
	if (uri->getRawQuery() != nullptr) {
		$throwNew($IllegalArgumentException, "Query component present"_s);
	}
	if (uri->getRawFragment() != nullptr) {
		$throwNew($IllegalArgumentException, "Fragment component present"_s);
	}
}

$FileSystem* UnixFileSystemProvider::newFileSystem($URI* uri, $Map* env) {
	checkUri(uri);
	$throwNew($FileSystemAlreadyExistsException);
	$shouldNotReachHere();
}

$FileSystem* UnixFileSystemProvider::getFileSystem($URI* uri) {
	checkUri(uri);
	return this->theFileSystem$;
}

$Path* UnixFileSystemProvider::getPath($URI* uri) {
	return $UnixUriUtils::fromUri(this->theFileSystem$, uri);
}

$UnixPath* UnixFileSystemProvider::checkPath($Path* obj) {
	if (obj == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!($instanceOf($UnixPath, obj))) {
		$throwNew($ProviderMismatchException);
	}
	return $cast($UnixPath, obj);
}

$FileAttributeView* UnixFileSystemProvider::getFileAttributeView($Path* obj, $Class* type, $LinkOptionArray* options) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	bool followLinks = $Util::followLinks(options);
	$load($BasicFileAttributeView);
	if (type == $BasicFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>($UnixFileAttributeViews::createBasicView(file, followLinks));
	}
	$load($PosixFileAttributeView);
	if (type == $PosixFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>(static_cast<$BasicFileAttributeView*>(static_cast<$AbstractBasicFileAttributeView*>(static_cast<$UnixFileAttributeViews$Basic*>($UnixFileAttributeViews::createPosixView(file, followLinks)))));
	}
	$load($FileOwnerAttributeView);
	if (type == $FileOwnerAttributeView::class$) {
		return static_cast<$FileAttributeView*>($UnixFileAttributeViews::createOwnerView(file, followLinks));
	}
	if (type == nullptr) {
		$throwNew($NullPointerException);
	}
	return ($FileAttributeView*)nullptr;
}

$BasicFileAttributes* UnixFileSystemProvider::readAttributes($Path* file, $Class* type, $LinkOptionArray* options) {
	$Class* view = nullptr;
	$load($BasicFileAttributes);
	if (type == $BasicFileAttributes::class$) {
		$load($BasicFileAttributeView);
		view = $BasicFileAttributeView::class$;
	} else {
		$load($PosixFileAttributes);
		if (type == $PosixFileAttributes::class$) {
			$load($PosixFileAttributeView);
			view = $PosixFileAttributeView::class$;
		} else if (type == nullptr) {
			$throwNew($NullPointerException);
		} else {
			$throwNew($UnsupportedOperationException);
		}
	}
	return $nc(($cast($BasicFileAttributeView, $(getFileAttributeView(file, view, options)))))->readAttributes();
}

$DynamicFileAttributeView* UnixFileSystemProvider::getFileAttributeView($Path* obj, $String* name, $LinkOptionArray* options) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	bool followLinks = $Util::followLinks(options);
	if ($nc(name)->equals("basic"_s)) {
		return $UnixFileAttributeViews::createBasicView(file, followLinks);
	}
	if ($nc(name)->equals("posix"_s)) {
		return $UnixFileAttributeViews::createPosixView(file, followLinks);
	}
	if ($nc(name)->equals("unix"_s)) {
		return $UnixFileAttributeViews::createUnixView(file, followLinks);
	}
	if ($nc(name)->equals("owner"_s)) {
		return $UnixFileAttributeViews::createOwnerView(file, followLinks);
	}
	return nullptr;
}

$FileChannel* UnixFileSystemProvider::newFileChannel($Path* obj, $Set* options, $FileAttributeArray* attrs) {
	$var($UnixPath, file, checkPath(obj));
	$init($UnixFileModeAttribute);
	int32_t mode = $UnixFileModeAttribute::toUnixMode($UnixFileModeAttribute::ALL_READWRITE, attrs);
	try {
		return $UnixChannelFactory::newFileChannel(file, options, mode);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(file);
		return nullptr;
	}
	$shouldNotReachHere();
}

$AsynchronousFileChannel* UnixFileSystemProvider::newAsynchronousFileChannel($Path* obj, $Set* options, $ExecutorService* executor, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, file, checkPath(obj));
	$init($UnixFileModeAttribute);
	int32_t mode = $UnixFileModeAttribute::toUnixMode($UnixFileModeAttribute::ALL_READWRITE, attrs);
	$var($ThreadPool, pool, (executor == nullptr) ? ($ThreadPool*)nullptr : $ThreadPool::wrap(executor, 0));
	try {
		return $UnixChannelFactory::newAsynchronousFileChannel(file, options, mode, pool);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(file);
		return nullptr;
	}
	$shouldNotReachHere();
}

$SeekableByteChannel* UnixFileSystemProvider::newByteChannel($Path* obj, $Set* options, $FileAttributeArray* attrs) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$init($UnixFileModeAttribute);
	int32_t mode = $UnixFileModeAttribute::toUnixMode($UnixFileModeAttribute::ALL_READWRITE, attrs);
	try {
		return $UnixChannelFactory::newFileChannel(file, options, mode);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(file);
		return nullptr;
	}
	$shouldNotReachHere();
}

bool UnixFileSystemProvider::implDelete($Path* obj, bool failIfNotExists) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$nc(file)->checkDelete();
	$var($UnixFileAttributes, attrs, nullptr);
	try {
		$assign(attrs, $UnixFileAttributes::get(file, false));
		if ($nc(attrs)->isDirectory()) {
			$UnixNativeDispatcher::rmdir(file);
		} else {
			$UnixNativeDispatcher::unlink(file);
		}
		return true;
	} catch ($UnixException& x) {
		$init($UnixConstants);
		if (!failIfNotExists && x->errno$() == $UnixConstants::ENOENT) {
			return false;
		}
		bool var$0 = attrs != nullptr && attrs->isDirectory();
		if (var$0) {
			bool var$1 = x->errno$() == $UnixConstants::EEXIST;
			var$0 = (var$1 || x->errno$() == $UnixConstants::ENOTEMPTY);
		}
		if (var$0) {
			$throwNew($DirectoryNotEmptyException, $(file->getPathForExceptionMessage()));
		}
		x->rethrowAsIOException(file);
		return false;
	}
	$shouldNotReachHere();
}

void UnixFileSystemProvider::copy($Path* source, $Path* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, var$0, $UnixPath::toUnixPath(source));
	$UnixCopyFile::copy(var$0, $($UnixPath::toUnixPath(target)), options);
}

void UnixFileSystemProvider::move($Path* source, $Path* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, var$0, $UnixPath::toUnixPath(source));
	$UnixCopyFile::move(var$0, $($UnixPath::toUnixPath(target)), options);
}

void UnixFileSystemProvider::checkAccess($Path* obj, $AccessModeArray* modes) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	bool e = false;
	bool r = false;
	bool w = false;
	bool x = false;
	if ($nc(modes)->length == 0) {
		e = true;
	} else {
		{
			$var($AccessModeArray, arr$, modes);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$AccessMode* mode = arr$->get(i$);
				{
					$init($UnixFileSystemProvider$3);
					switch ($nc($UnixFileSystemProvider$3::$SwitchMap$java$nio$file$AccessMode)->get($nc((mode))->ordinal())) {
					case 1:
						{
							r = true;
							break;
						}
					case 2:
						{
							w = true;
							break;
						}
					case 3:
						{
							x = true;
							break;
						}
					default:
						{
							$throwNew($AssertionError, $of("Should not get here"_s));
						}
					}
				}
			}
		}
	}
	int32_t mode = 0;
	if (e || r) {
		$nc(file)->checkRead();
		$init($UnixConstants);
		mode |= (r) ? $UnixConstants::R_OK : $UnixConstants::F_OK;
	}
	if (w) {
		$nc(file)->checkWrite();
		$init($UnixConstants);
		mode |= $UnixConstants::W_OK;
	}
	if (x) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkExec($($nc(file)->getPathForPermissionCheck()));
		}
		$init($UnixConstants);
		mode |= $UnixConstants::X_OK;
	}
	try {
		$UnixNativeDispatcher::access(file, mode);
	} catch ($UnixException& exc) {
		exc->rethrowAsIOException(file);
	}
}

bool UnixFileSystemProvider::isSameFile($Path* obj1, $Path* obj2) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, file1, $UnixPath::toUnixPath(obj1));
	if ($nc(file1)->equals(obj2)) {
		return true;
	}
	if (obj2 == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!($instanceOf($UnixPath, obj2))) {
		return false;
	}
	$var($UnixPath, file2, $cast($UnixPath, obj2));
	$nc(file1)->checkRead();
	$nc(file2)->checkRead();
	$var($UnixFileAttributes, attrs1, nullptr);
	$var($UnixFileAttributes, attrs2, nullptr);
	try {
		$assign(attrs1, $UnixFileAttributes::get(file1, true));
	} catch ($UnixException& x) {
		x->rethrowAsIOException(file1);
		return false;
	}
	try {
		$assign(attrs2, $UnixFileAttributes::get(file2, true));
	} catch ($UnixException& x) {
		x->rethrowAsIOException(file2);
		return false;
	}
	return $nc(attrs1)->isSameFile(attrs2);
}

bool UnixFileSystemProvider::isHidden($Path* obj) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$nc(file)->checkRead();
	$var($UnixPath, name, file->getFileName());
	if (name == nullptr) {
		return false;
	}
	$var($bytes, path, nullptr);
	if ($nc(name)->isEmpty()) {
		$assign(path, $nc($($cast($UnixFileSystem, name->getFileSystem())))->defaultDirectory());
	} else {
		$assign(path, name->asByteArray());
	}
	return $nc(path)->get(0) == u'.';
}

$FileStore* UnixFileSystemProvider::getFileStore($Path* obj) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getFileStoreAttributes"_s));
		$nc(file)->checkRead();
	}
	return getFileStore(file);
}

void UnixFileSystemProvider::createDirectory($Path* obj, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, dir, $UnixPath::toUnixPath(obj));
	$nc(dir)->checkWrite();
	$init($UnixFileModeAttribute);
	int32_t mode = $UnixFileModeAttribute::toUnixMode($UnixFileModeAttribute::ALL_PERMISSIONS, attrs);
	try {
		$UnixNativeDispatcher::mkdir(dir, mode);
	} catch ($UnixException& x) {
		$init($UnixConstants);
		if (x->errno$() == $UnixConstants::EISDIR) {
			$throwNew($FileAlreadyExistsException, $(dir->toString()));
		}
		x->rethrowAsIOException(dir);
	}
}

$DirectoryStream* UnixFileSystemProvider::newDirectoryStream($Path* obj, $DirectoryStream$Filter* filter) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, dir, $UnixPath::toUnixPath(obj));
	$nc(dir)->checkRead();
	if (filter == nullptr) {
		$throwNew($NullPointerException);
	}
	$init($UnixConstants);
	if (!$UnixNativeDispatcher::openatSupported() || $UnixConstants::O_NOFOLLOW == 0) {
		try {
			int64_t ptr = $UnixNativeDispatcher::opendir(dir);
			return $new($UnixDirectoryStream, dir, ptr, filter);
		} catch ($UnixException& x) {
			if (x->errno$() == $UnixConstants::ENOTDIR) {
				$throwNew($NotDirectoryException, $(dir->getPathForExceptionMessage()));
			}
			x->rethrowAsIOException(dir);
		}
	}
	int32_t dfd1 = -1;
	int32_t dfd2 = -1;
	int64_t dp = 0;
	try {
		dfd1 = $UnixNativeDispatcher::open(dir, $UnixConstants::O_RDONLY, 0);
		dfd2 = $UnixNativeDispatcher::dup(dfd1);
		dp = $UnixNativeDispatcher::fdopendir(dfd1);
	} catch ($UnixException& x) {
		if (dfd1 != -1) {
			$UnixNativeDispatcher::close(dfd1);
		}
		if (dfd2 != -1) {
			$UnixNativeDispatcher::close(dfd2);
		}
		if (x->errno$() == $UnixConstants::ENOTDIR) {
			$throwNew($NotDirectoryException, $(dir->getPathForExceptionMessage()));
		}
		x->rethrowAsIOException(dir);
	}
	return $new($UnixSecureDirectoryStream, dir, dp, dfd2, filter);
}

void UnixFileSystemProvider::createSymbolicLink($Path* obj1, $Path* obj2, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, link, $UnixPath::toUnixPath(obj1));
	$var($UnixPath, target, $UnixPath::toUnixPath(obj2));
	if ($nc(attrs)->length > 0) {
		$UnixFileModeAttribute::toUnixMode(0, attrs);
		$throwNew($UnsupportedOperationException, "Initial file attributesnot supported when creating symbolic link"_s);
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($LinkPermission, "symbolic"_s));
		$nc(link)->checkWrite();
	}
	try {
		$UnixNativeDispatcher::symlink($($nc(target)->asByteArray()), link);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(link);
	}
}

void UnixFileSystemProvider::createLink($Path* obj1, $Path* obj2) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, link, $UnixPath::toUnixPath(obj1));
	$var($UnixPath, existing, $UnixPath::toUnixPath(obj2));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($LinkPermission, "hard"_s));
		$nc(link)->checkWrite();
		$nc(existing)->checkWrite();
	}
	try {
		$UnixNativeDispatcher::link(existing, link);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(link, existing);
	}
}

$Path* UnixFileSystemProvider::readSymbolicLink($Path* obj1) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, link, $UnixPath::toUnixPath(obj1));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		$var($FilePermission, perm, $new($FilePermission, $($nc(link)->getPathForPermissionCheck()), $SecurityConstants::FILE_READLINK_ACTION));
		sm->checkPermission(perm);
	}
	try {
		$var($bytes, target, $UnixNativeDispatcher::readlink(link));
		return $new($UnixPath, $($cast($UnixFileSystem, $nc(link)->getFileSystem())), target);
	} catch ($UnixException& x) {
		$init($UnixConstants);
		if (x->errno$() == $UnixConstants::EINVAL) {
			$throwNew($NotLinkException, $($nc(link)->getPathForExceptionMessage()));
		}
		x->rethrowAsIOException(link);
		return nullptr;
	}
	$shouldNotReachHere();
}

bool UnixFileSystemProvider::isDirectory($Path* obj) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$nc(file)->checkRead();
	int32_t mode = $UnixNativeDispatcher::stat(file);
	$init($UnixConstants);
	return (((int32_t)(mode & (uint32_t)$UnixConstants::S_IFMT)) == $UnixConstants::S_IFDIR);
}

bool UnixFileSystemProvider::isRegularFile($Path* obj) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$nc(file)->checkRead();
	int32_t mode = $UnixNativeDispatcher::stat(file);
	$init($UnixConstants);
	return (((int32_t)(mode & (uint32_t)$UnixConstants::S_IFMT)) == $UnixConstants::S_IFREG);
}

bool UnixFileSystemProvider::exists($Path* obj) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	$nc(file)->checkRead();
	return $UnixNativeDispatcher::exists(file);
}

$FileTypeDetector* UnixFileSystemProvider::getFileTypeDetector() {
	return $new($UnixFileSystemProvider$1, this);
}

$FileTypeDetector* UnixFileSystemProvider::chain($AbstractFileTypeDetectorArray* detectors) {
	return $new($UnixFileSystemProvider$2, this, detectors);
}

$bytes* UnixFileSystemProvider::getSunPathForSocketFile($Path* obj) {
	$var($UnixPath, file, $UnixPath::toUnixPath(obj));
	if ($nc(file)->isEmpty()) {
		return UnixFileSystemProvider::EMPTY_PATH;
	}
	return $nc(file)->getByteArrayForSysCalls();
}

void clinit$UnixFileSystemProvider($Class* class$) {
	$assignStatic(UnixFileSystemProvider::USER_DIR, "user.dir"_s);
	$assignStatic(UnixFileSystemProvider::EMPTY_PATH, $new($bytes, 0));
}

UnixFileSystemProvider::UnixFileSystemProvider() {
}

$Class* UnixFileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(UnixFileSystemProvider, name, initialize, &_UnixFileSystemProvider_ClassInfo_, clinit$UnixFileSystemProvider, allocate$UnixFileSystemProvider);
	return class$;
}

$Class* UnixFileSystemProvider::class$ = nullptr;

		} // fs
	} // nio
} // sun