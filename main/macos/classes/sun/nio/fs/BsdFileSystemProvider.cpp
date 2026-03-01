#include <sun/nio/fs/BsdFileSystemProvider.h>

#include <java/nio/file/FileStore.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/UserDefinedFileAttributeView.h>
#include <sun/nio/fs/BsdFileStore.h>
#include <sun/nio/fs/BsdFileSystem.h>
#include <sun/nio/fs/BsdUserDefinedFileAttributeView.h>
#include <sun/nio/fs/DynamicFileAttributeView.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <sun/nio/fs/UnixFileSystemProvider.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/Util.h>
#include <jcpp.h>

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileStore = ::java::nio::file::FileStore;
using $Path = ::java::nio::file::Path;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $UserDefinedFileAttributeView = ::java::nio::file::attribute::UserDefinedFileAttributeView;
using $BsdFileStore = ::sun::nio::fs::BsdFileStore;
using $BsdFileSystem = ::sun::nio::fs::BsdFileSystem;
using $BsdUserDefinedFileAttributeView = ::sun::nio::fs::BsdUserDefinedFileAttributeView;
using $DynamicFileAttributeView = ::sun::nio::fs::DynamicFileAttributeView;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;
using $UnixFileSystemProvider = ::sun::nio::fs::UnixFileSystemProvider;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $Util = ::sun::nio::fs::Util;

namespace sun {
	namespace nio {
		namespace fs {

$MethodInfo _BsdFileSystemProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BsdFileSystemProvider, init$, void)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljava/nio/file/Path;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $PUBLIC | $TRANSIENT, $virtualMethod(BsdFileSystemProvider, getFileAttributeView, $FileAttributeView*, $Path*, $Class*, $LinkOptionArray*)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Lsun/nio/fs/DynamicFileAttributeView;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(BsdFileSystemProvider, getFileAttributeView, $DynamicFileAttributeView*, $Path*, $String*, $LinkOptionArray*)},
	{"getFileStore", "(Lsun/nio/fs/UnixPath;)Lsun/nio/fs/BsdFileStore;", nullptr, 0, $virtualMethod(BsdFileSystemProvider, getFileStore, $FileStore*, $UnixPath*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/lang/String;)Lsun/nio/fs/BsdFileSystem;", nullptr, 0, $virtualMethod(BsdFileSystemProvider, newFileSystem, $UnixFileSystem*, $String*)},
	{}
};

$ClassInfo _BsdFileSystemProvider_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.BsdFileSystemProvider",
	"sun.nio.fs.UnixFileSystemProvider",
	nullptr,
	nullptr,
	_BsdFileSystemProvider_MethodInfo_
};

$Object* allocate$BsdFileSystemProvider($Class* clazz) {
	return $of($alloc(BsdFileSystemProvider));
}

void BsdFileSystemProvider::init$() {
	$UnixFileSystemProvider::init$();
}

$UnixFileSystem* BsdFileSystemProvider::newFileSystem($String* dir) {
	return $new($BsdFileSystem, this, dir);
}

$FileStore* BsdFileSystemProvider::getFileStore($UnixPath* path) {
	return $new($BsdFileStore, path);
}

$FileAttributeView* BsdFileSystemProvider::getFileAttributeView($Path* obj, $Class* type, $LinkOptionArray* options) {
	$load($UserDefinedFileAttributeView);
	if (type == $UserDefinedFileAttributeView::class$) {
		$var($UnixPath, var$0, $UnixPath::toUnixPath(obj));
		return static_cast<$FileAttributeView*>($new($BsdUserDefinedFileAttributeView, var$0, $Util::followLinks(options)));
	}
	return $UnixFileSystemProvider::getFileAttributeView(obj, type, options);
}

$DynamicFileAttributeView* BsdFileSystemProvider::getFileAttributeView($Path* obj, $String* name, $LinkOptionArray* options) {
	if ($nc(name)->equals("user"_s)) {
		$var($UnixPath, var$0, $UnixPath::toUnixPath(obj));
		return $new($BsdUserDefinedFileAttributeView, var$0, $Util::followLinks(options));
	}
	return $UnixFileSystemProvider::getFileAttributeView(obj, name, options);
}

BsdFileSystemProvider::BsdFileSystemProvider() {
}

$Class* BsdFileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(BsdFileSystemProvider, name, initialize, &_BsdFileSystemProvider_ClassInfo_, allocate$BsdFileSystemProvider);
	return class$;
}

$Class* BsdFileSystemProvider::class$ = nullptr;

		} // fs
	} // nio
} // sun