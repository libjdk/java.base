#include <sun/nio/fs/WindowsFileSystemProvider.h>

#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URI.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/nio/file/AccessDeniedException.h>
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
#include <java/nio/file/Path.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/attribute/AclFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/DosFileAttributeView.h>
#include <java/nio/file/attribute/DosFileAttributes.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/FileOwnerAttributeView.h>
#include <java/nio/file/attribute/UserDefinedFileAttributeView.h>
#include <java/security/Permission.h>
#include <java/util/Collections.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ExecutorService.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView.h>
#include <sun/nio/fs/AbstractFileSystemProvider.h>
#include <sun/nio/fs/DynamicFileAttributeView.h>
#include <sun/nio/fs/FileOwnerAttributeViewImpl.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/Util.h>
#include <sun/nio/fs/WindowsAclFileAttributeView.h>
#include <sun/nio/fs/WindowsChannelFactory.h>
#include <sun/nio/fs/WindowsDirectoryStream.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsFileAttributeViews$Basic.h>
#include <sun/nio/fs/WindowsFileAttributeViews$Dos.h>
#include <sun/nio/fs/WindowsFileAttributeViews.h>
#include <sun/nio/fs/WindowsFileAttributes.h>
#include <sun/nio/fs/WindowsFileCopy.h>
#include <sun/nio/fs/WindowsFileStore.h>
#include <sun/nio/fs/WindowsFileSystem.h>
#include <sun/nio/fs/WindowsFileSystemProvider$1.h>
#include <sun/nio/fs/WindowsLinkSupport.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsPath.h>
#include <sun/nio/fs/WindowsPathType.h>
#include <sun/nio/fs/WindowsSecurity.h>
#include <sun/nio/fs/WindowsSecurityDescriptor.h>
#include <sun/nio/fs/WindowsUriSupport.h>
#include <sun/nio/fs/WindowsUserDefinedFileAttributeView.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef DRIVE_RELATIVE
#undef EMPTY_PATH
#undef FILE_READLINK_ACTION
#undef RELATIVE
#undef UTF_8

using $AccessModeArray = $Array<::java::nio::file::AccessMode>;
using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
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
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessDeniedException = ::java::nio::file::AccessDeniedException;
using $AccessMode = ::java::nio::file::AccessMode;
using $DirectoryNotEmptyException = ::java::nio::file::DirectoryNotEmptyException;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $DirectoryStream$Filter = ::java::nio::file::DirectoryStream$Filter;
using $FileAlreadyExistsException = ::java::nio::file::FileAlreadyExistsException;
using $FileStore = ::java::nio::file::FileStore;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystemAlreadyExistsException = ::java::nio::file::FileSystemAlreadyExistsException;
using $LinkPermission = ::java::nio::file::LinkPermission;
using $Path = ::java::nio::file::Path;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $AclFileAttributeView = ::java::nio::file::attribute::AclFileAttributeView;
using $BasicFileAttributeView = ::java::nio::file::attribute::BasicFileAttributeView;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $DosFileAttributeView = ::java::nio::file::attribute::DosFileAttributeView;
using $DosFileAttributes = ::java::nio::file::attribute::DosFileAttributes;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $FileOwnerAttributeView = ::java::nio::file::attribute::FileOwnerAttributeView;
using $UserDefinedFileAttributeView = ::java::nio::file::attribute::UserDefinedFileAttributeView;
using $Permission = ::java::security::Permission;
using $Collections = ::java::util::Collections;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $AbstractBasicFileAttributeView = ::sun::nio::fs::AbstractBasicFileAttributeView;
using $AbstractFileSystemProvider = ::sun::nio::fs::AbstractFileSystemProvider;
using $DynamicFileAttributeView = ::sun::nio::fs::DynamicFileAttributeView;
using $FileOwnerAttributeViewImpl = ::sun::nio::fs::FileOwnerAttributeViewImpl;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $Util = ::sun::nio::fs::Util;
using $WindowsAclFileAttributeView = ::sun::nio::fs::WindowsAclFileAttributeView;
using $WindowsChannelFactory = ::sun::nio::fs::WindowsChannelFactory;
using $WindowsDirectoryStream = ::sun::nio::fs::WindowsDirectoryStream;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsFileAttributeViews = ::sun::nio::fs::WindowsFileAttributeViews;
using $WindowsFileAttributeViews$Basic = ::sun::nio::fs::WindowsFileAttributeViews$Basic;
using $WindowsFileAttributes = ::sun::nio::fs::WindowsFileAttributes;
using $WindowsFileCopy = ::sun::nio::fs::WindowsFileCopy;
using $WindowsFileStore = ::sun::nio::fs::WindowsFileStore;
using $WindowsFileSystem = ::sun::nio::fs::WindowsFileSystem;
using $WindowsFileSystemProvider$1 = ::sun::nio::fs::WindowsFileSystemProvider$1;
using $WindowsLinkSupport = ::sun::nio::fs::WindowsLinkSupport;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsPath = ::sun::nio::fs::WindowsPath;
using $WindowsPathType = ::sun::nio::fs::WindowsPathType;
using $WindowsSecurity = ::sun::nio::fs::WindowsSecurity;
using $WindowsSecurityDescriptor = ::sun::nio::fs::WindowsSecurityDescriptor;
using $WindowsUriSupport = ::sun::nio::fs::WindowsUriSupport;
using $WindowsUserDefinedFileAttributeView = ::sun::nio::fs::WindowsUserDefinedFileAttributeView;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _WindowsFileSystemProvider_FieldInfo_[] = {
	{"EMPTY_PATH", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsFileSystemProvider, EMPTY_PATH)},
	{"theFileSystem", "Lsun/nio/fs/WindowsFileSystem;", nullptr, $PRIVATE | $FINAL, $field(WindowsFileSystemProvider, theFileSystem$)},
	{}
};

$MethodInfo _WindowsFileSystemProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WindowsFileSystemProvider, init$, void)},
	{"checkAccess", "(Ljava/nio/file/Path;[Ljava/nio/file/AccessMode;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, checkAccess, void, $Path*, $AccessModeArray*), "java.io.IOException"},
	{"checkReadAccess", "(Lsun/nio/fs/WindowsPath;)V", nullptr, $PRIVATE, $method(WindowsFileSystemProvider, checkReadAccess, void, $WindowsPath*), "java.io.IOException"},
	{"checkUri", "(Ljava/net/URI;)V", nullptr, $PRIVATE, $method(WindowsFileSystemProvider, checkUri, void, $URI*)},
	{"copy", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, copy, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"createDirectory", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, createDirectory, void, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"createLink", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, createLink, void, $Path*, $Path*), "java.io.IOException"},
	{"createSymbolicLink", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, createSymbolicLink, void, $Path*, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljava/nio/file/Path;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, getFileAttributeView, $FileAttributeView*, $Path*, $Class*, $LinkOptionArray*)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Lsun/nio/fs/DynamicFileAttributeView;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, getFileAttributeView, $DynamicFileAttributeView*, $Path*, $String*, $LinkOptionArray*)},
	{"getFileStore", "(Ljava/nio/file/Path;)Ljava/nio/file/FileStore;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, getFileStore, $FileStore*, $Path*), "java.io.IOException"},
	{"getFileSystem", "(Ljava/net/URI;)Ljava/nio/file/FileSystem;", nullptr, $PUBLIC | $FINAL, $virtualMethod(WindowsFileSystemProvider, getFileSystem, $FileSystem*, $URI*)},
	{"getPath", "(Ljava/net/URI;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, getPath, $Path*, $URI*)},
	{"getScheme", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, getScheme, $String*)},
	{"getSunPathForSocketFile", "(Ljava/nio/file/Path;)[B", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, getSunPathForSocketFile, $bytes*, $Path*)},
	{"hasDesiredAccess", "(Lsun/nio/fs/WindowsPath;I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsFileSystemProvider, hasDesiredAccess, bool, $WindowsPath*, int32_t), "java.io.IOException"},
	{"implDelete", "(Ljava/nio/file/Path;Z)Z", nullptr, 0, $virtualMethod(WindowsFileSystemProvider, implDelete, bool, $Path*, bool), "java.io.IOException"},
	{"isHidden", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, isHidden, bool, $Path*), "java.io.IOException"},
	{"isSameFile", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, isSameFile, bool, $Path*, $Path*), "java.io.IOException"},
	{"isUnixDomainSocket", "(Lsun/nio/fs/WindowsPath;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsFileSystemProvider, isUnixDomainSocket, bool, $WindowsPath*), "sun.nio.fs.WindowsException"},
	{"move", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, move, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"newAsynchronousFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/AsynchronousFileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/AsynchronousFileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, newAsynchronousFileChannel, $AsynchronousFileChannel*, $Path*, $Set*, $ExecutorService*, $FileAttributeArray*), "java.io.IOException"},
	{"newByteChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/SeekableByteChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/SeekableByteChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, newByteChannel, $SeekableByteChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newDirectoryStream", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter;)Ljava/nio/file/DirectoryStream;", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter<-Ljava/nio/file/Path;>;)Ljava/nio/file/DirectoryStream<Ljava/nio/file/Path;>;", $PUBLIC, $virtualMethod(WindowsFileSystemProvider, newDirectoryStream, $DirectoryStream*, $Path*, $DirectoryStream$Filter*), "java.io.IOException"},
	{"newFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/FileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, newFileChannel, $FileChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/net/URI;Ljava/util/Map;)Ljava/nio/file/FileSystem;", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/nio/file/FileSystem;", $PUBLIC, $virtualMethod(WindowsFileSystemProvider, newFileSystem, $FileSystem*, $URI*, $Map*), "java.io.IOException"},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/BasicFileAttributes;", "<A::Ljava/nio/file/attribute/BasicFileAttributes;>(Ljava/nio/file/Path;Ljava/lang/Class<TA;>;[Ljava/nio/file/LinkOption;)TA;", $PUBLIC | $TRANSIENT, $virtualMethod(WindowsFileSystemProvider, readAttributes, $BasicFileAttributes*, $Path*, $Class*, $LinkOptionArray*), "java.io.IOException"},
	{"readSymbolicLink", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(WindowsFileSystemProvider, readSymbolicLink, $Path*, $Path*), "java.io.IOException"},
	{"theFileSystem", "()Lsun/nio/fs/WindowsFileSystem;", nullptr, 0, $virtualMethod(WindowsFileSystemProvider, theFileSystem, $WindowsFileSystem*)},
	{}
};

$InnerClassInfo _WindowsFileSystemProvider_InnerClassesInfo_[] = {
	{"sun.nio.fs.WindowsFileSystemProvider$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _WindowsFileSystemProvider_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsFileSystemProvider",
	"sun.nio.fs.AbstractFileSystemProvider",
	nullptr,
	_WindowsFileSystemProvider_FieldInfo_,
	_WindowsFileSystemProvider_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsFileSystemProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.WindowsFileSystemProvider$1"
};

$Object* allocate$WindowsFileSystemProvider($Class* clazz) {
	return $of($alloc(WindowsFileSystemProvider));
}

$bytes* WindowsFileSystemProvider::EMPTY_PATH = nullptr;

void WindowsFileSystemProvider::init$() {
	$AbstractFileSystemProvider::init$();
	$set(this, theFileSystem$, $new($WindowsFileSystem, this, $($StaticProperty::userDir())));
}

$WindowsFileSystem* WindowsFileSystemProvider::theFileSystem() {
	return this->theFileSystem$;
}

$String* WindowsFileSystemProvider::getScheme() {
	return "file"_s;
}

void WindowsFileSystemProvider::checkUri($URI* uri) {
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

$FileSystem* WindowsFileSystemProvider::newFileSystem($URI* uri, $Map* env) {
	checkUri(uri);
	$throwNew($FileSystemAlreadyExistsException);
	$shouldNotReachHere();
}

$FileSystem* WindowsFileSystemProvider::getFileSystem($URI* uri) {
	checkUri(uri);
	return this->theFileSystem$;
}

$Path* WindowsFileSystemProvider::getPath($URI* uri) {
	return $WindowsUriSupport::fromUri(this->theFileSystem$, uri);
}

$FileChannel* WindowsFileSystemProvider::newFileChannel($Path* path, $Set* options, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	if (path == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!($instanceOf($WindowsPath, path))) {
		$throwNew($ProviderMismatchException);
	}
	$var($WindowsPath, file, $cast($WindowsPath, path));
	$var($WindowsSecurityDescriptor, sd, $WindowsSecurityDescriptor::fromAttribute(attrs));
	{
		$var($Throwable, var$0, nullptr);
		$var($FileChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($String, var$3, $nc(file)->getPathForWin32Calls());
				$var($String, var$4, file->getPathForPermissionCheck());
				$var($Set, var$5, options);
				$assign(var$2, $WindowsChannelFactory::newFileChannel(var$3, var$4, var$5, $nc(sd)->address()));
				return$1 = true;
				goto $finally;
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(file);
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			if (sd != nullptr) {
				sd->release();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$AsynchronousFileChannel* WindowsFileSystemProvider::newAsynchronousFileChannel($Path* path, $Set* options, $ExecutorService* executor, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	if (path == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!($instanceOf($WindowsPath, path))) {
		$throwNew($ProviderMismatchException);
	}
	$var($WindowsPath, file, $cast($WindowsPath, path));
	$var($ThreadPool, pool, (executor == nullptr) ? ($ThreadPool*)nullptr : $ThreadPool::wrap(executor, 0));
	$var($WindowsSecurityDescriptor, sd, $WindowsSecurityDescriptor::fromAttribute(attrs));
	{
		$var($Throwable, var$0, nullptr);
		$var($AsynchronousFileChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($String, var$3, $nc(file)->getPathForWin32Calls());
				$var($String, var$4, file->getPathForPermissionCheck());
				$var($Set, var$5, options);
				$assign(var$2, $WindowsChannelFactory::newAsynchronousFileChannel(var$3, var$4, var$5, $nc(sd)->address(), pool));
				return$1 = true;
				goto $finally;
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(file);
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			if (sd != nullptr) {
				sd->release();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$FileAttributeView* WindowsFileSystemProvider::getFileAttributeView($Path* obj, $Class* view, $LinkOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	if (view == nullptr) {
		$throwNew($NullPointerException);
	}
	bool followLinks = $Util::followLinks(options);
	$load($BasicFileAttributeView);
	if (view == $BasicFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>($WindowsFileAttributeViews::createBasicView(file, followLinks));
	}
	$load($DosFileAttributeView);
	if (view == $DosFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>(static_cast<$BasicFileAttributeView*>(static_cast<$AbstractBasicFileAttributeView*>(static_cast<$WindowsFileAttributeViews$Basic*>($WindowsFileAttributeViews::createDosView(file, followLinks)))));
	}
	$load($AclFileAttributeView);
	if (view == $AclFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>($new($WindowsAclFileAttributeView, file, followLinks));
	}
	$load($FileOwnerAttributeView);
	if (view == $FileOwnerAttributeView::class$) {
		return static_cast<$FileAttributeView*>($new($FileOwnerAttributeViewImpl, static_cast<$AclFileAttributeView*>($$new($WindowsAclFileAttributeView, file, followLinks))));
	}
	$load($UserDefinedFileAttributeView);
	if (view == $UserDefinedFileAttributeView::class$) {
		return static_cast<$FileAttributeView*>($new($WindowsUserDefinedFileAttributeView, file, followLinks));
	}
	return ($FileAttributeView*)nullptr;
}

$BasicFileAttributes* WindowsFileSystemProvider::readAttributes($Path* file, $Class* type, $LinkOptionArray* options) {
	$Class* view = nullptr;
	$load($BasicFileAttributes);
	if (type == $BasicFileAttributes::class$) {
		$load($BasicFileAttributeView);
		view = $BasicFileAttributeView::class$;
	} else {
		$load($DosFileAttributes);
		if (type == $DosFileAttributes::class$) {
			$load($DosFileAttributeView);
			view = $DosFileAttributeView::class$;
		} else if (type == nullptr) {
			$throwNew($NullPointerException);
		} else {
			$throwNew($UnsupportedOperationException);
		}
	}
	return $nc(($cast($BasicFileAttributeView, $(getFileAttributeView(file, view, options)))))->readAttributes();
}

$DynamicFileAttributeView* WindowsFileSystemProvider::getFileAttributeView($Path* obj, $String* name, $LinkOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	bool followLinks = $Util::followLinks(options);
	if ($nc(name)->equals("basic"_s)) {
		return $WindowsFileAttributeViews::createBasicView(file, followLinks);
	}
	if ($nc(name)->equals("dos"_s)) {
		return $WindowsFileAttributeViews::createDosView(file, followLinks);
	}
	if ($nc(name)->equals("acl"_s)) {
		return $new($WindowsAclFileAttributeView, file, followLinks);
	}
	if ($nc(name)->equals("owner"_s)) {
		return $new($FileOwnerAttributeViewImpl, static_cast<$AclFileAttributeView*>($$new($WindowsAclFileAttributeView, file, followLinks)));
	}
	if ($nc(name)->equals("user"_s)) {
		return $new($WindowsUserDefinedFileAttributeView, file, followLinks);
	}
	return nullptr;
}

$SeekableByteChannel* WindowsFileSystemProvider::newByteChannel($Path* obj, $Set* options, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	$var($WindowsSecurityDescriptor, sd, $WindowsSecurityDescriptor::fromAttribute(attrs));
	{
		$var($Throwable, var$0, nullptr);
		$var($SeekableByteChannel, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($String, var$3, $nc(file)->getPathForWin32Calls());
				$var($String, var$4, file->getPathForPermissionCheck());
				$var($Set, var$5, options);
				$assign(var$2, $WindowsChannelFactory::newFileChannel(var$3, var$4, var$5, $nc(sd)->address()));
				return$1 = true;
				goto $finally;
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(file);
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$6) {
			$assign(var$0, var$6);
		} $finally: {
			$nc(sd)->release();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool WindowsFileSystemProvider::implDelete($Path* obj, bool failIfNotExists) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	$nc(file)->checkDelete();
	$var($WindowsFileAttributes, attrs, nullptr);
	try {
		$assign(attrs, $WindowsFileAttributes::get(file, false));
		bool var$0 = $nc(attrs)->isDirectory();
		if (var$0 || $nc(attrs)->isDirectoryLink()) {
			$WindowsNativeDispatcher::RemoveDirectory($(file->getPathForWin32Calls()));
		} else {
			$WindowsNativeDispatcher::DeleteFile($(file->getPathForWin32Calls()));
		}
		return true;
	} catch ($WindowsException& x) {
		bool var$1 = !failIfNotExists;
		if (var$1) {
			bool var$2 = x->lastError() == 2;
			var$1 = (var$2 || x->lastError() == 3);
		}
		if (var$1) {
			return false;
		}
		if (attrs != nullptr && attrs->isDirectory()) {
			bool var$3 = x->lastError() == 145;
			if (var$3 || x->lastError() == 183) {
				$throwNew($DirectoryNotEmptyException, $(file->getPathForExceptionMessage()));
			}
		}
		x->rethrowAsIOException(file);
		return false;
	}
	$shouldNotReachHere();
}

void WindowsFileSystemProvider::copy($Path* source, $Path* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, var$0, $WindowsPath::toWindowsPath(source));
	$WindowsFileCopy::copy(var$0, $($WindowsPath::toWindowsPath(target)), options);
}

void WindowsFileSystemProvider::move($Path* source, $Path* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, var$0, $WindowsPath::toWindowsPath(source));
	$WindowsFileCopy::move(var$0, $($WindowsPath::toWindowsPath(target)), options);
}

bool WindowsFileSystemProvider::hasDesiredAccess($WindowsPath* file, int32_t rights) {
	$init(WindowsFileSystemProvider);
	$useLocalCurrentObjectStackCache();
	bool hasRights = false;
	$var($String, target, $WindowsLinkSupport::getFinalPath(file, true));
	$var($NativeBuffer, aclBuffer, $WindowsAclFileAttributeView::getFileSecurity(target, (4 | 1) | 2));
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				hasRights = $WindowsSecurity::checkAccessMask($nc(aclBuffer)->address(), rights, 0x00120089, 0x00120116, 0x001200A0, 0x001F01FF);
			} catch ($WindowsException& exc) {
				exc->rethrowAsIOException(file);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(aclBuffer)->release();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return hasRights;
}

void WindowsFileSystemProvider::checkReadAccess($WindowsPath* file) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Set, opts, $Collections::emptySet());
		$var($String, var$0, $nc(file)->getPathForWin32Calls());
		$var($FileChannel, fc, $WindowsChannelFactory::newFileChannel(var$0, $(file->getPathForPermissionCheck()), opts, 0));
		$nc(fc)->close();
	} catch ($WindowsException& exc) {
		try {
			bool var$1 = exc->lastError() == 1920;
			if (var$1 && isUnixDomainSocket(file)) {
				return;
			}
		} catch ($WindowsException& ignore) {
		}
		try {
			$$new($WindowsDirectoryStream, file, nullptr)->close();
		} catch ($IOException& ioe) {
			exc->rethrowAsIOException(file);
		}
	}
}

bool WindowsFileSystemProvider::isUnixDomainSocket($WindowsPath* path) {
	$init(WindowsFileSystemProvider);
	$var($WindowsFileAttributes, attrs, $WindowsFileAttributes::get(path, false));
	return $nc(attrs)->isUnixDomainSocket();
}

void WindowsFileSystemProvider::checkAccess($Path* obj, $AccessModeArray* modes) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	bool r = false;
	bool w = false;
	bool x = false;
	{
		$var($AccessModeArray, arr$, modes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$AccessMode* mode = arr$->get(i$);
			{
				$init($WindowsFileSystemProvider$1);
				switch ($nc($WindowsFileSystemProvider$1::$SwitchMap$java$nio$file$AccessMode)->get($nc((mode))->ordinal())) {
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
	if (!w && !x) {
		checkReadAccess(file);
		return;
	}
	int32_t mask = 0;
	if (r) {
		$nc(file)->checkRead();
		mask |= 1;
	}
	if (w) {
		$nc(file)->checkWrite();
		mask |= 2;
	}
	if (x) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkExec($($nc(file)->getPathForPermissionCheck()));
		}
		mask |= 32;
	}
	if (!hasDesiredAccess(file, mask)) {
		$throwNew($AccessDeniedException, $($nc(file)->getPathForExceptionMessage()), nullptr, "Permissions does not allow requested access"_s);
	}
	if (w) {
		try {
			$var($WindowsFileAttributes, attrs, $WindowsFileAttributes::get(file, true));
			bool var$0 = !$nc(attrs)->isDirectory();
			if (var$0 && attrs->isReadOnly()) {
				$throwNew($AccessDeniedException, $($nc(file)->getPathForExceptionMessage()), nullptr, "DOS readonly attribute is set"_s);
			}
		} catch ($WindowsException& exc) {
			exc->rethrowAsIOException(file);
		}
		if ($nc($($WindowsFileStore::create(file)))->isReadOnly()) {
			$throwNew($AccessDeniedException, $($nc(file)->getPathForExceptionMessage()), nullptr, "Read-only file system"_s);
		}
	}
}

bool WindowsFileSystemProvider::isSameFile($Path* obj1, $Path* obj2) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file1, $WindowsPath::toWindowsPath(obj1));
	if ($nc(file1)->equals(obj2)) {
		return true;
	}
	if (obj2 == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!($instanceOf($WindowsPath, obj2))) {
		return false;
	}
	$var($WindowsPath, file2, $cast($WindowsPath, obj2));
	$nc(file1)->checkRead();
	$nc(file2)->checkRead();
	int64_t h1 = 0;
	try {
		h1 = file1->openForReadAttributeAccess(true);
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(file1);
	}
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			$var($WindowsFileAttributes, attrs1, nullptr);
			try {
				$assign(attrs1, $WindowsFileAttributes::readAttributes(h1));
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(file1);
			}
			int64_t h2 = 0;
			try {
				h2 = file2->openForReadAttributeAccess(true);
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(file2);
			}
			{
				$var($Throwable, var$3, nullptr);
				bool var$5 = false;
				bool return$4 = false;
				try {
					$var($WindowsFileAttributes, attrs2, nullptr);
					try {
						$assign(attrs2, $WindowsFileAttributes::readAttributes(h2));
					} catch ($WindowsException& x) {
						x->rethrowAsIOException(file2);
					}
					var$5 = $WindowsFileAttributes::isSameFile(attrs1, attrs2);
					return$4 = true;
					goto $finally1;
				} catch ($Throwable& var$6) {
					$assign(var$3, var$6);
				} $finally1: {
					$WindowsNativeDispatcher::CloseHandle(h2);
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
				if (return$4) {
					var$2 = var$5;
					return$1 = true;
					goto $finally;
				}
			}
		} catch ($Throwable& var$7) {
			$assign(var$0, var$7);
		} $finally: {
			$WindowsNativeDispatcher::CloseHandle(h1);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool WindowsFileSystemProvider::isHidden($Path* obj) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	$nc(file)->checkRead();
	$var($WindowsFileAttributes, attrs, nullptr);
	try {
		$assign(attrs, $WindowsFileAttributes::get(file, true));
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(file);
	}
	return $nc(attrs)->isHidden();
}

$FileStore* WindowsFileSystemProvider::getFileStore($Path* obj) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getFileStoreAttributes"_s));
		$nc(file)->checkRead();
	}
	return $WindowsFileStore::create(file);
}

void WindowsFileSystemProvider::createDirectory($Path* obj, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, dir, $WindowsPath::toWindowsPath(obj));
	$nc(dir)->checkWrite();
	$var($WindowsSecurityDescriptor, sd, $WindowsSecurityDescriptor::fromAttribute(attrs));
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$var($String, var$1, dir->getPathForWin32Calls());
				$WindowsNativeDispatcher::CreateDirectory(var$1, $nc(sd)->address());
			} catch ($WindowsException& x) {
				if (x->lastError() == 5) {
					try {
						if ($nc($($WindowsFileAttributes::get(dir, false)))->isDirectory()) {
							$throwNew($FileAlreadyExistsException, $(dir->toString()));
						}
					} catch ($WindowsException& ignore) {
					}
				}
				x->rethrowAsIOException(dir);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			$nc(sd)->release();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$DirectoryStream* WindowsFileSystemProvider::newDirectoryStream($Path* obj, $DirectoryStream$Filter* filter) {
	$var($WindowsPath, dir, $WindowsPath::toWindowsPath(obj));
	$nc(dir)->checkRead();
	if (filter == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($WindowsDirectoryStream, dir, filter);
}

void WindowsFileSystemProvider::createSymbolicLink($Path* obj1, $Path* obj2, $FileAttributeArray* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, link, $WindowsPath::toWindowsPath(obj1));
	$var($WindowsPath, target, $WindowsPath::toWindowsPath(obj2));
	if ($nc(attrs)->length > 0) {
		$WindowsSecurityDescriptor::fromAttribute(attrs);
		$throwNew($UnsupportedOperationException, "Initial file attributesnot supported when creating symbolic link"_s);
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($LinkPermission, "symbolic"_s));
		$nc(link)->checkWrite();
	}
	$init($WindowsPathType);
	if ($nc(target)->type() == $WindowsPathType::DRIVE_RELATIVE) {
		$throwNew($IOException, "Cannot create symbolic link to working directory relative target"_s);
	}
	$var($WindowsPath, resolvedTarget, nullptr);
	if ($nc(target)->type() == $WindowsPathType::RELATIVE) {
		$var($WindowsPath, parent, $nc(link)->getParent());
		$assign(resolvedTarget, (parent == nullptr) ? target : $nc(parent)->resolve(static_cast<$Path*>(target)));
	} else {
		$assign(resolvedTarget, $nc(link)->resolve(static_cast<$Path*>(target)));
	}
	int32_t flags = 0;
	try {
		$var($WindowsFileAttributes, wattrs, $WindowsFileAttributes::get(resolvedTarget, false));
		bool var$0 = $nc(wattrs)->isDirectory();
		if (var$0 || $nc(wattrs)->isDirectoryLink()) {
			flags |= 1;
		}
	} catch ($WindowsException& x) {
	}
	try {
		$var($String, var$1, $nc(link)->getPathForWin32Calls());
		$WindowsNativeDispatcher::CreateSymbolicLink(var$1, $($WindowsPath::addPrefixIfNeeded($($nc(target)->toString()))), flags);
	} catch ($WindowsException& x) {
		if (x->lastError() == 4392) {
			x->rethrowAsIOException(link, target);
		} else {
			x->rethrowAsIOException(link);
		}
	}
}

void WindowsFileSystemProvider::createLink($Path* obj1, $Path* obj2) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, link, $WindowsPath::toWindowsPath(obj1));
	$var($WindowsPath, existing, $WindowsPath::toWindowsPath(obj2));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($LinkPermission, "hard"_s));
		$nc(link)->checkWrite();
		$nc(existing)->checkWrite();
	}
	try {
		$var($String, var$0, $nc(link)->getPathForWin32Calls());
		$WindowsNativeDispatcher::CreateHardLink(var$0, $($nc(existing)->getPathForWin32Calls()));
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(link, existing);
	}
}

$Path* WindowsFileSystemProvider::readSymbolicLink($Path* obj1) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, link, $WindowsPath::toWindowsPath(obj1));
	$var($WindowsFileSystem, fs, $cast($WindowsFileSystem, $nc(link)->getFileSystem()));
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		$var($FilePermission, perm, $new($FilePermission, $(link->getPathForPermissionCheck()), $SecurityConstants::FILE_READLINK_ACTION));
		sm->checkPermission(perm);
	}
	$var($String, target, $WindowsLinkSupport::readLink(link));
	return $WindowsPath::createFromNormalizedPath(fs, target);
}

$bytes* WindowsFileSystemProvider::getSunPathForSocketFile($Path* obj) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, file, $WindowsPath::toWindowsPath(obj));
	$var($String, s, $nc(file)->toString());
	$init($StandardCharsets);
	return $nc(s)->isEmpty() ? WindowsFileSystemProvider::EMPTY_PATH : $nc(s)->getBytes($StandardCharsets::UTF_8);
}

void clinit$WindowsFileSystemProvider($Class* class$) {
	$assignStatic(WindowsFileSystemProvider::EMPTY_PATH, $new($bytes, 0));
}

WindowsFileSystemProvider::WindowsFileSystemProvider() {
}

$Class* WindowsFileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(WindowsFileSystemProvider, name, initialize, &_WindowsFileSystemProvider_ClassInfo_, clinit$WindowsFileSystemProvider, allocate$WindowsFileSystemProvider);
	return class$;
}

$Class* WindowsFileSystemProvider::class$ = nullptr;

		} // fs
	} // nio
} // sun