#include <jdk/internal/jrtfs/JrtFileSystemProvider.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/file/AccessMode.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/DirectoryStream$Filter.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileStore.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ExecutorService.h>
#include <jdk/internal/jrtfs/JrtFileAttributeView.h>
#include <jdk/internal/jrtfs/JrtFileAttributes.h>
#include <jdk/internal/jrtfs/JrtFileSystem.h>
#include <jdk/internal/jrtfs/JrtFileSystemProvider$1.h>
#include <jdk/internal/jrtfs/JrtPath.h>
#include <jcpp.h>

#undef JRT_FS_JAR

using $URLArray = $Array<::java::net::URL>;
using $AccessModeArray = $Array<::java::nio::file::AccessMode>;
using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLClassLoader = ::java::net::URLClassLoader;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $FileChannel = ::java::nio::channels::FileChannel;
using $SeekableByteChannel = ::java::nio::channels::SeekableByteChannel;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $DirectoryStream$Filter = ::java::nio::file::DirectoryStream$Filter;
using $FileStore = ::java::nio::file::FileStore;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystems = ::java::nio::file::FileSystems;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $JrtFileAttributeView = ::jdk::internal::jrtfs::JrtFileAttributeView;
using $JrtFileAttributes = ::jdk::internal::jrtfs::JrtFileAttributes;
using $JrtFileSystem = ::jdk::internal::jrtfs::JrtFileSystem;
using $JrtFileSystemProvider$1 = ::jdk::internal::jrtfs::JrtFileSystemProvider$1;
using $JrtPath = ::jdk::internal::jrtfs::JrtPath;

namespace jdk {
	namespace internal {
		namespace jrtfs {

$FieldInfo _JrtFileSystemProvider_FieldInfo_[] = {
	{"theFileSystem", "Ljava/nio/file/FileSystem;", nullptr, $PRIVATE | $VOLATILE, $field(JrtFileSystemProvider, theFileSystem)},
	{"JRT_FS_JAR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtFileSystemProvider, JRT_FS_JAR)},
	{}
};

$MethodInfo _JrtFileSystemProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(JrtFileSystemProvider, init$, void)},
	{"checkAccess", "(Ljava/nio/file/Path;[Ljava/nio/file/AccessMode;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, checkAccess, void, $Path*, $AccessModeArray*), "java.io.IOException"},
	{"checkPermission", "()V", nullptr, $PRIVATE, $method(JrtFileSystemProvider, checkPermission, void)},
	{"checkUri", "(Ljava/net/URI;)V", nullptr, $PRIVATE, $method(JrtFileSystemProvider, checkUri, void, $URI*)},
	{"copy", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, copy, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"createDirectory", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, createDirectory, void, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"delete", "(Ljava/nio/file/Path;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtFileSystemProvider, delete$, void, $Path*), "java.io.IOException"},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljava/nio/file/Path;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, getFileAttributeView, $FileAttributeView*, $Path*, $Class*, $LinkOptionArray*)},
	{"getFileStore", "(Ljava/nio/file/Path;)Ljava/nio/file/FileStore;", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, getFileStore, $FileStore*, $Path*), "java.io.IOException"},
	{"getFileSystem", "(Ljava/net/URI;)Ljava/nio/file/FileSystem;", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, getFileSystem, $FileSystem*, $URI*)},
	{"getPath", "(Ljava/net/URI;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, getPath, $Path*, $URI*)},
	{"getScheme", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, getScheme, $String*)},
	{"getTheFileSystem", "()Ljava/nio/file/FileSystem;", nullptr, $PRIVATE, $method(JrtFileSystemProvider, getTheFileSystem, $FileSystem*)},
	{"isHidden", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, isHidden, bool, $Path*)},
	{"isSameFile", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, isSameFile, bool, $Path*, $Path*), "java.io.IOException"},
	{"move", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, move, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"newAsynchronousFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/AsynchronousFileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/AsynchronousFileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, newAsynchronousFileChannel, $AsynchronousFileChannel*, $Path*, $Set*, $ExecutorService*, $FileAttributeArray*), "java.io.IOException"},
	{"newByteChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/SeekableByteChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/SeekableByteChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, newByteChannel, $SeekableByteChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newDirectoryStream", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter;)Ljava/nio/file/DirectoryStream;", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter<-Ljava/nio/file/Path;>;)Ljava/nio/file/DirectoryStream<Ljava/nio/file/Path;>;", $PUBLIC, $virtualMethod(JrtFileSystemProvider, newDirectoryStream, $DirectoryStream*, $Path*, $DirectoryStream$Filter*), "java.io.IOException"},
	{"newFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/FileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, newFileChannel, $FileChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/net/URI;Ljava/util/Map;)Ljava/nio/file/FileSystem;", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/nio/file/FileSystem;", $PUBLIC, $virtualMethod(JrtFileSystemProvider, newFileSystem, $FileSystem*, $URI*, $Map*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/lang/String;Ljava/net/URI;Ljava/util/Map;)Ljava/nio/file/FileSystem;", "(Ljava/lang/String;Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/nio/file/FileSystem;", $PRIVATE, $method(JrtFileSystemProvider, newFileSystem, $FileSystem*, $String*, $URI*, $Map*), "java.io.IOException"},
	{"newInputStream", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/io/InputStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, newInputStream, $InputStream*, $Path*, $OpenOptionArray*), "java.io.IOException"},
	{"newJrtFsLoader", "(Ljava/nio/file/Path;)Ljava/net/URLClassLoader;", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtFileSystemProvider, newJrtFsLoader, $URLClassLoader*, $Path*)},
	{"newOutputStream", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/io/OutputStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, newOutputStream, $OutputStream*, $Path*, $OpenOptionArray*), "java.io.IOException"},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/BasicFileAttributes;", "<A::Ljava/nio/file/attribute/BasicFileAttributes;>(Ljava/nio/file/Path;Ljava/lang/Class<TA;>;[Ljava/nio/file/LinkOption;)TA;", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, readAttributes, $BasicFileAttributes*, $Path*, $Class*, $LinkOptionArray*), "java.io.IOException"},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map;", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, readAttributes, $Map*, $Path*, $String*, $LinkOptionArray*), "java.io.IOException"},
	{"readSymbolicLink", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(JrtFileSystemProvider, readSymbolicLink, $Path*, $Path*), "java.io.IOException"},
	{"setAttribute", "(Ljava/nio/file/Path;Ljava/lang/String;Ljava/lang/Object;[Ljava/nio/file/LinkOption;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(JrtFileSystemProvider, setAttribute, void, $Path*, $String*, Object$*, $LinkOptionArray*), "java.io.IOException"},
	{"toJrtPath", "(Ljava/nio/file/Path;)Ljdk/internal/jrtfs/JrtPath;", nullptr, $STATIC | $FINAL, $staticMethod(JrtFileSystemProvider, toJrtPath, $JrtPath*, $Path*)},
	{}
};

$InnerClassInfo _JrtFileSystemProvider_InnerClassesInfo_[] = {
	{"jdk.internal.jrtfs.JrtFileSystemProvider$JrtFsLoader", "jdk.internal.jrtfs.JrtFileSystemProvider", "JrtFsLoader", $PRIVATE | $STATIC},
	{"jdk.internal.jrtfs.JrtFileSystemProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _JrtFileSystemProvider_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.jrtfs.JrtFileSystemProvider",
	"java.nio.file.spi.FileSystemProvider",
	nullptr,
	_JrtFileSystemProvider_FieldInfo_,
	_JrtFileSystemProvider_MethodInfo_,
	nullptr,
	nullptr,
	_JrtFileSystemProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.jrtfs.JrtFileSystemProvider$JrtFsLoader,jdk.internal.jrtfs.JrtFileSystemProvider$1"
};

$Object* allocate$JrtFileSystemProvider($Class* clazz) {
	return $of($alloc(JrtFileSystemProvider));
}

$String* JrtFileSystemProvider::JRT_FS_JAR = nullptr;

void JrtFileSystemProvider::init$() {
	$FileSystemProvider::init$();
}

$String* JrtFileSystemProvider::getScheme() {
	return "jrt"_s;
}

void JrtFileSystemProvider::checkPermission() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($RuntimePermission, perm, $new($RuntimePermission, "accessSystemModules"_s));
		sm->checkPermission(perm);
	}
}

void JrtFileSystemProvider::checkUri($URI* uri) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($($nc(uri)->getScheme()))->equalsIgnoreCase($(getScheme()))) {
		$throwNew($IllegalArgumentException, "URI does not match this provider"_s);
	}
	if ($nc(uri)->getAuthority() != nullptr) {
		$throwNew($IllegalArgumentException, "Authority component present"_s);
	}
	if ($nc(uri)->getPath() == nullptr) {
		$throwNew($IllegalArgumentException, "Path component is undefined"_s);
	}
	if (!$nc($($nc(uri)->getPath()))->equals("/"_s)) {
		$throwNew($IllegalArgumentException, "Path component should be \'/\'"_s);
	}
	if ($nc(uri)->getQuery() != nullptr) {
		$throwNew($IllegalArgumentException, "Query component present"_s);
	}
	if ($nc(uri)->getFragment() != nullptr) {
		$throwNew($IllegalArgumentException, "Fragment component present"_s);
	}
}

$FileSystem* JrtFileSystemProvider::newFileSystem($URI* uri, $Map* env) {
	$Objects::requireNonNull(env);
	checkPermission();
	checkUri(uri);
	if (env->containsKey("java.home"_s)) {
		return newFileSystem($cast($String, $(env->get("java.home"_s))), uri, env);
	} else {
		return $new($JrtFileSystem, this, env);
	}
}

$FileSystem* JrtFileSystemProvider::newFileSystem($String* targetHome, $URI* uri, $Map* env) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Objects::requireNonNull(targetHome);
	$var($Path, jrtfs, $nc($($FileSystems::getDefault()))->getPath(targetHome, $$new($StringArray, {
		"lib"_s,
		JrtFileSystemProvider::JRT_FS_JAR
	})));
	if ($Files::notExists(jrtfs, $$new($LinkOptionArray, 0))) {
		$throwNew($IOException, $$str({$($nc(jrtfs)->toString()), " not exist"_s}));
	}
	$var($Map, newEnv, $new($HashMap, env));
	newEnv->remove("java.home"_s);
	$var($ClassLoader, cl, newJrtFsLoader(jrtfs));
	try {
		$Class* c = $Class::forName($(JrtFileSystemProvider::class$->getName()), false, cl);
		$var($Object, tmp, $nc(c)->newInstance());
		return $nc(($cast($FileSystemProvider, tmp)))->newFileSystem(uri, newEnv);
	} catch ($ClassNotFoundException& e) {
		$throwNew($IOException, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($IOException, static_cast<$Throwable*>(e));
	} catch ($InstantiationException& e) {
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$URLClassLoader* JrtFileSystemProvider::newJrtFsLoader($Path* jrtfs) {
	$init(JrtFileSystemProvider);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($URL, url, nullptr);
	try {
		$assign(url, $nc($($nc(jrtfs)->toUri()))->toURL());
	} catch ($MalformedURLException& mue) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(mue));
	}
	$var($URLArray, urls, $new($URLArray, {url}));
	return $cast($URLClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($JrtFileSystemProvider$1, urls))));
}

$Path* JrtFileSystemProvider::getPath($URI* uri) {
	$useLocalCurrentObjectStackCache();
	checkPermission();
	if (!$nc($($nc(uri)->getScheme()))->equalsIgnoreCase($(getScheme()))) {
		$throwNew($IllegalArgumentException, "URI does not match this provider"_s);
	}
	if ($nc(uri)->getAuthority() != nullptr) {
		$throwNew($IllegalArgumentException, "Authority component present"_s);
	}
	if ($nc(uri)->getQuery() != nullptr) {
		$throwNew($IllegalArgumentException, "Query component present"_s);
	}
	if ($nc(uri)->getFragment() != nullptr) {
		$throwNew($IllegalArgumentException, "Fragment component present"_s);
	}
	$var($String, path, $nc(uri)->getPath());
	bool var$0 = path == nullptr || $nc(path)->charAt(0) != u'/';
	if (var$0 || $nc(path)->contains(".."_s)) {
		$throwNew($IllegalArgumentException, "Invalid path component"_s);
	}
	return $nc($(getTheFileSystem()))->getPath($$str({"/modules"_s, path}), $$new($StringArray, 0));
}

$FileSystem* JrtFileSystemProvider::getTheFileSystem() {
	checkPermission();
	$var($FileSystem, fs, this->theFileSystem);
	if (fs == nullptr) {
		$synchronized(this) {
			$assign(fs, this->theFileSystem);
			if (fs == nullptr) {
				try {
					$set(this, theFileSystem, ($assign(fs, $new($JrtFileSystem, this, nullptr))));
				} catch ($IOException& ioe) {
					$throwNew($InternalError, static_cast<$Throwable*>(ioe));
				}
			}
		}
	}
	return fs;
}

$FileSystem* JrtFileSystemProvider::getFileSystem($URI* uri) {
	checkPermission();
	checkUri(uri);
	return getTheFileSystem();
}

$JrtPath* JrtFileSystemProvider::toJrtPath($Path* path) {
	$init(JrtFileSystemProvider);
	$Objects::requireNonNull($of(path), "path"_s);
	if (!($instanceOf($JrtPath, path))) {
		$throwNew($ProviderMismatchException);
	}
	return $cast($JrtPath, path);
}

void JrtFileSystemProvider::checkAccess($Path* path, $AccessModeArray* modes) {
	$nc($(toJrtPath(path)))->checkAccess(modes);
}

$Path* JrtFileSystemProvider::readSymbolicLink($Path* link) {
	return $nc($(toJrtPath(link)))->readSymbolicLink();
}

void JrtFileSystemProvider::copy($Path* src, $Path* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$nc($(toJrtPath(src)))->copy($(toJrtPath(target)), options);
}

void JrtFileSystemProvider::createDirectory($Path* path, $FileAttributeArray* attrs) {
	$nc($(toJrtPath(path)))->createDirectory(attrs);
}

void JrtFileSystemProvider::delete$($Path* path) {
	$nc($(toJrtPath(path)))->delete$();
}

$FileAttributeView* JrtFileSystemProvider::getFileAttributeView($Path* path, $Class* type, $LinkOptionArray* options) {
	return $JrtFileAttributeView::get($(toJrtPath(path)), type, options);
}

$FileStore* JrtFileSystemProvider::getFileStore($Path* path) {
	return $nc($(toJrtPath(path)))->getFileStore();
}

bool JrtFileSystemProvider::isHidden($Path* path) {
	return $nc($(toJrtPath(path)))->isHidden();
}

bool JrtFileSystemProvider::isSameFile($Path* path, $Path* other) {
	return $nc($(toJrtPath(path)))->isSameFile(other);
}

void JrtFileSystemProvider::move($Path* src, $Path* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$nc($(toJrtPath(src)))->move($(toJrtPath(target)), options);
}

$AsynchronousFileChannel* JrtFileSystemProvider::newAsynchronousFileChannel($Path* path, $Set* options, $ExecutorService* exec, $FileAttributeArray* attrs) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$SeekableByteChannel* JrtFileSystemProvider::newByteChannel($Path* path, $Set* options, $FileAttributeArray* attrs) {
	return $nc($(toJrtPath(path)))->newByteChannel(options, attrs);
}

$DirectoryStream* JrtFileSystemProvider::newDirectoryStream($Path* path, $DirectoryStream$Filter* filter) {
	return $nc($(toJrtPath(path)))->newDirectoryStream(filter);
}

$FileChannel* JrtFileSystemProvider::newFileChannel($Path* path, $Set* options, $FileAttributeArray* attrs) {
	return $nc($(toJrtPath(path)))->newFileChannel(options, attrs);
}

$InputStream* JrtFileSystemProvider::newInputStream($Path* path, $OpenOptionArray* options) {
	return $nc($(toJrtPath(path)))->newInputStream(options);
}

$OutputStream* JrtFileSystemProvider::newOutputStream($Path* path, $OpenOptionArray* options) {
	return $nc($(toJrtPath(path)))->newOutputStream(options);
}

$BasicFileAttributes* JrtFileSystemProvider::readAttributes($Path* path, $Class* type, $LinkOptionArray* options) {
	$load($BasicFileAttributes);
	$load($JrtFileAttributes);
	if (type == $BasicFileAttributes::class$ || type == $JrtFileAttributes::class$) {
		return static_cast<$BasicFileAttributes*>($nc($(toJrtPath(path)))->getAttributes(options));
	}
	return nullptr;
}

$Map* JrtFileSystemProvider::readAttributes($Path* path, $String* attribute, $LinkOptionArray* options) {
	return $nc($(toJrtPath(path)))->readAttributes(attribute, options);
}

void JrtFileSystemProvider::setAttribute($Path* path, $String* attribute, Object$* value, $LinkOptionArray* options) {
	$nc($(toJrtPath(path)))->setAttribute(attribute, value, options);
}

JrtFileSystemProvider::JrtFileSystemProvider() {
}

void clinit$JrtFileSystemProvider($Class* class$) {
	$assignStatic(JrtFileSystemProvider::JRT_FS_JAR, "jrt-fs.jar"_s);
}

$Class* JrtFileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(JrtFileSystemProvider, name, initialize, &_JrtFileSystemProvider_ClassInfo_, clinit$JrtFileSystemProvider, allocate$JrtFileSystemProvider);
	return class$;
}

$Class* JrtFileSystemProvider::class$ = nullptr;

		} // jrtfs
	} // internal
} // jdk