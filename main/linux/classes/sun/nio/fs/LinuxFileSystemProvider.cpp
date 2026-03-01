#include <sun/nio/fs/LinuxFileSystemProvider.h>

#include <java/nio/file/FileStore.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/DosFileAttributeView.h>
#include <java/nio/file/attribute/DosFileAttributes.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/UserDefinedFileAttributeView.h>
#include <java/nio/file/spi/FileTypeDetector.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView.h>
#include <sun/nio/fs/AbstractFileTypeDetector.h>
#include <sun/nio/fs/DynamicFileAttributeView.h>
#include <sun/nio/fs/LinuxDosFileAttributeView.h>
#include <sun/nio/fs/LinuxFileStore.h>
#include <sun/nio/fs/LinuxFileSystem.h>
#include <sun/nio/fs/LinuxUserDefinedFileAttributeView.h>
#include <sun/nio/fs/MimeTypesFileTypeDetector.h>
#include <sun/nio/fs/UnixFileAttributeViews$Basic.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <sun/nio/fs/UnixFileSystemProvider.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/Util.h>
#include <jcpp.h>

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $AbstractFileTypeDetectorArray = $Array<::sun::nio::fs::AbstractFileTypeDetector>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileStore = ::java::nio::file::FileStore;
using $Path = ::java::nio::file::Path;
using $BasicFileAttributeView = ::java::nio::file::attribute::BasicFileAttributeView;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $DosFileAttributeView = ::java::nio::file::attribute::DosFileAttributeView;
using $DosFileAttributes = ::java::nio::file::attribute::DosFileAttributes;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $UserDefinedFileAttributeView = ::java::nio::file::attribute::UserDefinedFileAttributeView;
using $FileTypeDetector = ::java::nio::file::spi::FileTypeDetector;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $AbstractBasicFileAttributeView = ::sun::nio::fs::AbstractBasicFileAttributeView;
using $AbstractFileTypeDetector = ::sun::nio::fs::AbstractFileTypeDetector;
using $DynamicFileAttributeView = ::sun::nio::fs::DynamicFileAttributeView;
using $LinuxDosFileAttributeView = ::sun::nio::fs::LinuxDosFileAttributeView;
using $LinuxFileStore = ::sun::nio::fs::LinuxFileStore;
using $LinuxFileSystem = ::sun::nio::fs::LinuxFileSystem;
using $LinuxUserDefinedFileAttributeView = ::sun::nio::fs::LinuxUserDefinedFileAttributeView;
using $MimeTypesFileTypeDetector = ::sun::nio::fs::MimeTypesFileTypeDetector;
using $UnixFileAttributeViews$Basic = ::sun::nio::fs::UnixFileAttributeViews$Basic;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;
using $UnixFileSystemProvider = ::sun::nio::fs::UnixFileSystemProvider;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $Util = ::sun::nio::fs::Util;

namespace sun {
	namespace nio {
		namespace fs {

$MethodInfo _LinuxFileSystemProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LinuxFileSystemProvider, init$, void)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljava/nio/file/Path;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $PUBLIC | $TRANSIENT, $virtualMethod(LinuxFileSystemProvider, getFileAttributeView, $FileAttributeView*, $Path*, $Class*, $LinkOptionArray*)},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Lsun/nio/fs/DynamicFileAttributeView;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(LinuxFileSystemProvider, getFileAttributeView, $DynamicFileAttributeView*, $Path*, $String*, $LinkOptionArray*)},
	{"getFileStore", "(Lsun/nio/fs/UnixPath;)Lsun/nio/fs/LinuxFileStore;", nullptr, 0, $virtualMethod(LinuxFileSystemProvider, getFileStore, $FileStore*, $UnixPath*), "java.io.IOException"},
	{"getFileTypeDetector", "()Ljava/nio/file/spi/FileTypeDetector;", nullptr, 0, $virtualMethod(LinuxFileSystemProvider, getFileTypeDetector, $FileTypeDetector*)},
	{"newFileSystem", "(Ljava/lang/String;)Lsun/nio/fs/LinuxFileSystem;", nullptr, 0, $virtualMethod(LinuxFileSystemProvider, newFileSystem, $UnixFileSystem*, $String*)},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/BasicFileAttributes;", "<A::Ljava/nio/file/attribute/BasicFileAttributes;>(Ljava/nio/file/Path;Ljava/lang/Class<TA;>;[Ljava/nio/file/LinkOption;)TA;", $PUBLIC | $TRANSIENT, $virtualMethod(LinuxFileSystemProvider, readAttributes, $BasicFileAttributes*, $Path*, $Class*, $LinkOptionArray*), "java.io.IOException"},
	{}
};

$ClassInfo _LinuxFileSystemProvider_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.LinuxFileSystemProvider",
	"sun.nio.fs.UnixFileSystemProvider",
	nullptr,
	nullptr,
	_LinuxFileSystemProvider_MethodInfo_
};

$Object* allocate$LinuxFileSystemProvider($Class* clazz) {
	return $of($alloc(LinuxFileSystemProvider));
}

void LinuxFileSystemProvider::init$() {
	$UnixFileSystemProvider::init$();
}

$UnixFileSystem* LinuxFileSystemProvider::newFileSystem($String* dir) {
	return $new($LinuxFileSystem, this, dir);
}

$FileStore* LinuxFileSystemProvider::getFileStore($UnixPath* path) {
	return $new($LinuxFileStore, path);
}

$FileAttributeView* LinuxFileSystemProvider::getFileAttributeView($Path* obj, $Class* type, $LinkOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$load($DosFileAttributeView);
	if (type == $DosFileAttributeView::class$) {
		$var($UnixPath, var$0, $UnixPath::toUnixPath(obj));
		return static_cast<$FileAttributeView*>(static_cast<$BasicFileAttributeView*>(static_cast<$AbstractBasicFileAttributeView*>(static_cast<$UnixFileAttributeViews$Basic*>($new($LinuxDosFileAttributeView, var$0, $Util::followLinks(options))))));
	}
	$load($UserDefinedFileAttributeView);
	if (type == $UserDefinedFileAttributeView::class$) {
		$var($UnixPath, var$1, $UnixPath::toUnixPath(obj));
		return static_cast<$FileAttributeView*>($new($LinuxUserDefinedFileAttributeView, var$1, $Util::followLinks(options)));
	}
	return $UnixFileSystemProvider::getFileAttributeView(obj, type, options);
}

$DynamicFileAttributeView* LinuxFileSystemProvider::getFileAttributeView($Path* obj, $String* name, $LinkOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->equals("dos"_s)) {
		$var($UnixPath, var$0, $UnixPath::toUnixPath(obj));
		return $new($LinuxDosFileAttributeView, var$0, $Util::followLinks(options));
	}
	if ($nc(name)->equals("user"_s)) {
		$var($UnixPath, var$1, $UnixPath::toUnixPath(obj));
		return $new($LinuxUserDefinedFileAttributeView, var$1, $Util::followLinks(options));
	}
	return $UnixFileSystemProvider::getFileAttributeView(obj, name, options);
}

$BasicFileAttributes* LinuxFileSystemProvider::readAttributes($Path* file, $Class* type, $LinkOptionArray* options) {
	$load($DosFileAttributes);
	if (type == $DosFileAttributes::class$) {
		$load($DosFileAttributeView);
		$var($DosFileAttributeView, view, $cast($DosFileAttributeView, getFileAttributeView(file, $DosFileAttributeView::class$, options)));
		return static_cast<$BasicFileAttributes*>($cast($DosFileAttributes, $nc(view)->readAttributes()));
	} else {
		return $UnixFileSystemProvider::readAttributes(file, type, options);
	}
}

$FileTypeDetector* LinuxFileSystemProvider::getFileTypeDetector() {
	$useLocalCurrentObjectStackCache();
	$var($String, userHome, $StaticProperty::userHome());
	$var($Path, userMimeTypes, $Path::of(userHome, $$new($StringArray, {".mime.types"_s})));
	$var($Path, etcMimeTypes, $Path::of("/etc/mime.types"_s, $$new($StringArray, 0)));
	return chain($$new($AbstractFileTypeDetectorArray, {
		static_cast<$AbstractFileTypeDetector*>($$new($MimeTypesFileTypeDetector, userMimeTypes)),
		static_cast<$AbstractFileTypeDetector*>($$new($MimeTypesFileTypeDetector, etcMimeTypes))
	}));
}

LinuxFileSystemProvider::LinuxFileSystemProvider() {
}

$Class* LinuxFileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(LinuxFileSystemProvider, name, initialize, &_LinuxFileSystemProvider_ClassInfo_, allocate$LinuxFileSystemProvider);
	return class$;
}

$Class* LinuxFileSystemProvider::class$ = nullptr;

		} // fs
	} // nio
} // sun