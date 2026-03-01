#include <sun/nio/fs/MacOSXFileSystemProvider.h>

#include <java/nio/file/Path.h>
#include <java/nio/file/spi/FileTypeDetector.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/nio/fs/AbstractFileTypeDetector.h>
#include <sun/nio/fs/BsdFileSystemProvider.h>
#include <sun/nio/fs/MacOSXFileSystem.h>
#include <sun/nio/fs/MimeTypesFileTypeDetector.h>
#include <sun/nio/fs/UTIFileTypeDetector.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <sun/nio/fs/UnixFileSystemProvider.h>
#include <jcpp.h>

using $AbstractFileTypeDetectorArray = $Array<::sun::nio::fs::AbstractFileTypeDetector>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Path = ::java::nio::file::Path;
using $FileTypeDetector = ::java::nio::file::spi::FileTypeDetector;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $AbstractFileTypeDetector = ::sun::nio::fs::AbstractFileTypeDetector;
using $BsdFileSystemProvider = ::sun::nio::fs::BsdFileSystemProvider;
using $MacOSXFileSystem = ::sun::nio::fs::MacOSXFileSystem;
using $MimeTypesFileTypeDetector = ::sun::nio::fs::MimeTypesFileTypeDetector;
using $UTIFileTypeDetector = ::sun::nio::fs::UTIFileTypeDetector;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;
using $UnixFileSystemProvider = ::sun::nio::fs::UnixFileSystemProvider;

namespace sun {
	namespace nio {
		namespace fs {

$MethodInfo _MacOSXFileSystemProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MacOSXFileSystemProvider, init$, void)},
	{"getFileTypeDetector", "()Ljava/nio/file/spi/FileTypeDetector;", nullptr, 0, $virtualMethod(MacOSXFileSystemProvider, getFileTypeDetector, $FileTypeDetector*)},
	{"newFileSystem", "(Ljava/lang/String;)Lsun/nio/fs/MacOSXFileSystem;", nullptr, 0, $virtualMethod(MacOSXFileSystemProvider, newFileSystem, $UnixFileSystem*, $String*)},
	{}
};

$ClassInfo _MacOSXFileSystemProvider_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.MacOSXFileSystemProvider",
	"sun.nio.fs.BsdFileSystemProvider",
	nullptr,
	nullptr,
	_MacOSXFileSystemProvider_MethodInfo_
};

$Object* allocate$MacOSXFileSystemProvider($Class* clazz) {
	return $of($alloc(MacOSXFileSystemProvider));
}

void MacOSXFileSystemProvider::init$() {
	$BsdFileSystemProvider::init$();
}

$UnixFileSystem* MacOSXFileSystemProvider::newFileSystem($String* dir) {
	return $new($MacOSXFileSystem, this, dir);
}

$FileTypeDetector* MacOSXFileSystemProvider::getFileTypeDetector() {
	$useLocalCurrentObjectStackCache();
	$var($Path, userMimeTypes, $Path::of($($StaticProperty::userHome()), $$new($StringArray, {".mime.types"_s})));
	return chain($$new($AbstractFileTypeDetectorArray, {
		static_cast<$AbstractFileTypeDetector*>($$new($MimeTypesFileTypeDetector, userMimeTypes)),
		static_cast<$AbstractFileTypeDetector*>($$new($UTIFileTypeDetector))
	}));
}

MacOSXFileSystemProvider::MacOSXFileSystemProvider() {
}

$Class* MacOSXFileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(MacOSXFileSystemProvider, name, initialize, &_MacOSXFileSystemProvider_ClassInfo_, allocate$MacOSXFileSystemProvider);
	return class$;
}

$Class* MacOSXFileSystemProvider::class$ = nullptr;

		} // fs
	} // nio
} // sun