#include <java/nio/file/spi/FileSystemProvider.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URI.h>
#include <java/nio/channels/AsynchronousFileChannel.h>
#include <java/nio/channels/Channels.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/ReadableByteChannel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/channels/WritableByteChannel.h>
#include <java/nio/file/AccessMode.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/DirectoryStream$Filter.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileStore.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/NoSuchFileException.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/spi/FileSystemProvider$1.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ExecutorService.h>
#include <sun/nio/ch/FileChannelImpl.h>
#include <jcpp.h>

#undef APPEND
#undef CREATE
#undef DEFAULT_OPEN_OPTIONS
#undef READ
#undef TRUNCATE_EXISTING
#undef WRITE

using $AccessModeArray = $Array<::java::nio::file::AccessMode>;
using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $URI = ::java::net::URI;
using $AsynchronousFileChannel = ::java::nio::channels::AsynchronousFileChannel;
using $Channels = ::java::nio::channels::Channels;
using $FileChannel = ::java::nio::channels::FileChannel;
using $ReadableByteChannel = ::java::nio::channels::ReadableByteChannel;
using $SeekableByteChannel = ::java::nio::channels::SeekableByteChannel;
using $WritableByteChannel = ::java::nio::channels::WritableByteChannel;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $DirectoryStream$Filter = ::java::nio::file::DirectoryStream$Filter;
using $FileStore = ::java::nio::file::FileStore;
using $FileSystem = ::java::nio::file::FileSystem;
using $FileSystems = ::java::nio::file::FileSystems;
using $Files = ::java::nio::file::Files;
using $NoSuchFileException = ::java::nio::file::NoSuchFileException;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileAttributeView = ::java::nio::file::attribute::FileAttributeView;
using $FileSystemProvider$1 = ::java::nio::file::spi::FileSystemProvider$1;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ServiceLoader = ::java::util::ServiceLoader;
using $Set = ::java::util::Set;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $FileChannelImpl = ::sun::nio::ch::FileChannelImpl;

namespace java {
	namespace nio {
		namespace file {
			namespace spi {

$FieldInfo _FileSystemProvider_FieldInfo_[] = {
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileSystemProvider, lock)},
	{"installedProviders", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/file/spi/FileSystemProvider;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(FileSystemProvider, installedProviders$)},
	{"loadingProviders", "Z", nullptr, $PRIVATE | $STATIC, $staticField(FileSystemProvider, loadingProviders)},
	{"DEFAULT_OPEN_OPTIONS", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/file/OpenOption;>;", $PRIVATE | $STATIC | $FINAL, $staticField(FileSystemProvider, DEFAULT_OPEN_OPTIONS)},
	{}
};

$MethodInfo _FileSystemProvider_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Void;)V", nullptr, $PRIVATE, $method(FileSystemProvider, init$, void, $Void*)},
	{"<init>", "()V", nullptr, $PROTECTED, $method(FileSystemProvider, init$, void)},
	{"checkAccess", "(Ljava/nio/file/Path;[Ljava/nio/file/AccessMode;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, checkAccess, void, $Path*, $AccessModeArray*), "java.io.IOException"},
	{"checkPermission", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $staticMethod(FileSystemProvider, checkPermission, $Void*)},
	{"copy", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, copy, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"createDirectory", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, createDirectory, void, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"createLink", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $virtualMethod(FileSystemProvider, createLink, void, $Path*, $Path*), "java.io.IOException"},
	{"createSymbolicLink", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute;)V", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/attribute/FileAttribute<*>;)V", $PUBLIC | $TRANSIENT, $virtualMethod(FileSystemProvider, createSymbolicLink, void, $Path*, $Path*, $FileAttributeArray*), "java.io.IOException"},
	{"delete", "(Ljava/nio/file/Path;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, delete$, void, $Path*), "java.io.IOException"},
	{"deleteIfExists", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC, $virtualMethod(FileSystemProvider, deleteIfExists, bool, $Path*), "java.io.IOException"},
	{"getFileAttributeView", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/FileAttributeView;", "<V::Ljava/nio/file/attribute/FileAttributeView;>(Ljava/nio/file/Path;Ljava/lang/Class<TV;>;[Ljava/nio/file/LinkOption;)TV;", $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, getFileAttributeView, $FileAttributeView*, $Path*, $Class*, $LinkOptionArray*)},
	{"getFileStore", "(Ljava/nio/file/Path;)Ljava/nio/file/FileStore;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, getFileStore, $FileStore*, $Path*), "java.io.IOException"},
	{"getFileSystem", "(Ljava/net/URI;)Ljava/nio/file/FileSystem;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, getFileSystem, $FileSystem*, $URI*)},
	{"getPath", "(Ljava/net/URI;)Ljava/nio/file/Path;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, getPath, $Path*, $URI*)},
	{"getScheme", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, getScheme, $String*)},
	{"installedProviders", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/file/spi/FileSystemProvider;>;", $PUBLIC | $STATIC, $staticMethod(FileSystemProvider, installedProviders, $List*)},
	{"isHidden", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, isHidden, bool, $Path*), "java.io.IOException"},
	{"isSameFile", "(Ljava/nio/file/Path;Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, isSameFile, bool, $Path*, $Path*), "java.io.IOException"},
	{"loadInstalledProviders", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/file/spi/FileSystemProvider;>;", $PRIVATE | $STATIC, $staticMethod(FileSystemProvider, loadInstalledProviders, $List*)},
	{"move", "(Ljava/nio/file/Path;Ljava/nio/file/Path;[Ljava/nio/file/CopyOption;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, move, void, $Path*, $Path*, $CopyOptionArray*), "java.io.IOException"},
	{"newAsynchronousFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/AsynchronousFileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/AsynchronousFileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(FileSystemProvider, newAsynchronousFileChannel, $AsynchronousFileChannel*, $Path*, $Set*, $ExecutorService*, $FileAttributeArray*), "java.io.IOException"},
	{"newByteChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/SeekableByteChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/SeekableByteChannel;", $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, newByteChannel, $SeekableByteChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newDirectoryStream", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter;)Ljava/nio/file/DirectoryStream;", "(Ljava/nio/file/Path;Ljava/nio/file/DirectoryStream$Filter<-Ljava/nio/file/Path;>;)Ljava/nio/file/DirectoryStream<Ljava/nio/file/Path;>;", $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, newDirectoryStream, $DirectoryStream*, $Path*, $DirectoryStream$Filter*), "java.io.IOException"},
	{"newFileChannel", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/FileChannel;", $PUBLIC | $TRANSIENT, $virtualMethod(FileSystemProvider, newFileChannel, $FileChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/net/URI;Ljava/util/Map;)Ljava/nio/file/FileSystem;", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/nio/file/FileSystem;", $PUBLIC | $ABSTRACT, $virtualMethod(FileSystemProvider, newFileSystem, $FileSystem*, $URI*, $Map*), "java.io.IOException"},
	{"newFileSystem", "(Ljava/nio/file/Path;Ljava/util/Map;)Ljava/nio/file/FileSystem;", "(Ljava/nio/file/Path;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/nio/file/FileSystem;", $PUBLIC, $virtualMethod(FileSystemProvider, newFileSystem, $FileSystem*, $Path*, $Map*), "java.io.IOException"},
	{"newInputStream", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/io/InputStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(FileSystemProvider, newInputStream, $InputStream*, $Path*, $OpenOptionArray*), "java.io.IOException"},
	{"newOutputStream", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/io/OutputStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(FileSystemProvider, newOutputStream, $OutputStream*, $Path*, $OpenOptionArray*), "java.io.IOException"},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/Class;[Ljava/nio/file/LinkOption;)Ljava/nio/file/attribute/BasicFileAttributes;", "<A::Ljava/nio/file/attribute/BasicFileAttributes;>(Ljava/nio/file/Path;Ljava/lang/Class<TA;>;[Ljava/nio/file/LinkOption;)TA;", $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, readAttributes, $BasicFileAttributes*, $Path*, $Class*, $LinkOptionArray*), "java.io.IOException"},
	{"readAttributes", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map;", "(Ljava/nio/file/Path;Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, readAttributes, $Map*, $Path*, $String*, $LinkOptionArray*), "java.io.IOException"},
	{"readSymbolicLink", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(FileSystemProvider, readSymbolicLink, $Path*, $Path*), "java.io.IOException"},
	{"setAttribute", "(Ljava/nio/file/Path;Ljava/lang/String;Ljava/lang/Object;[Ljava/nio/file/LinkOption;)V", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT, $virtualMethod(FileSystemProvider, setAttribute, void, $Path*, $String*, Object$*, $LinkOptionArray*), "java.io.IOException"},
	{}
};

$InnerClassInfo _FileSystemProvider_InnerClassesInfo_[] = {
	{"java.nio.file.spi.FileSystemProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileSystemProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.file.spi.FileSystemProvider",
	"java.lang.Object",
	nullptr,
	_FileSystemProvider_FieldInfo_,
	_FileSystemProvider_MethodInfo_,
	nullptr,
	nullptr,
	_FileSystemProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.file.spi.FileSystemProvider$1"
};

$Object* allocate$FileSystemProvider($Class* clazz) {
	return $of($alloc(FileSystemProvider));
}

$Object* FileSystemProvider::lock = nullptr;
$volatile($List*) FileSystemProvider::installedProviders$ = nullptr;
bool FileSystemProvider::loadingProviders = false;
$Set* FileSystemProvider::DEFAULT_OPEN_OPTIONS = nullptr;

$Void* FileSystemProvider::checkPermission() {
	$init(FileSystemProvider);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "fileSystemProvider"_s));
	}
	return nullptr;
}

void FileSystemProvider::init$($Void* ignore) {
}

void FileSystemProvider::init$() {
	FileSystemProvider::init$($(checkPermission()));
}

$List* FileSystemProvider::loadInstalledProviders() {
	$init(FileSystemProvider);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, list, $new($ArrayList));
	$var($ServiceLoader, sl, $ServiceLoader::load(FileSystemProvider::class$, $($ClassLoader::getSystemClassLoader())));
	{
		$var($Iterator, i$, $nc(sl)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(FileSystemProvider, provider, $cast(FileSystemProvider, i$->next()));
			{
				$var($String, scheme, $nc(provider)->getScheme());
				if (!$nc(scheme)->equalsIgnoreCase("file"_s)) {
					bool found = false;
					{
						$var($Iterator, i$, list->iterator());
						for (; $nc(i$)->hasNext();) {
							$var(FileSystemProvider, p, $cast(FileSystemProvider, i$->next()));
							{
								if ($nc($($nc(p)->getScheme()))->equalsIgnoreCase(scheme)) {
									found = true;
									break;
								}
							}
						}
					}
					if (!found) {
						list->add(provider);
					}
				}
			}
		}
	}
	return list;
}

$List* FileSystemProvider::installedProviders() {
	$init(FileSystemProvider);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (FileSystemProvider::installedProviders$ == nullptr) {
		$var(FileSystemProvider, defaultProvider, $nc($($FileSystems::getDefault()))->provider());
		$synchronized(FileSystemProvider::lock) {
			if (FileSystemProvider::installedProviders$ == nullptr) {
				if (FileSystemProvider::loadingProviders) {
					$throwNew($Error, "Circular loading of installed providers detected"_s);
				}
				FileSystemProvider::loadingProviders = true;
				$var($List, list, $cast($List, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FileSystemProvider$1)))));
				$nc(list)->add(0, defaultProvider);
				$assignStatic(FileSystemProvider::installedProviders$, $Collections::unmodifiableList(list));
			}
		}
	}
	return FileSystemProvider::installedProviders$;
}

$FileSystem* FileSystemProvider::newFileSystem($Path* path, $Map* env) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* FileSystemProvider::newInputStream($Path* path, $OpenOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	if ($nc(options)->length > 0) {
		{
			$var($OpenOptionArray, arr$, options);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($OpenOption, opt, arr$->get(i$));
				{
					$init($StandardOpenOption);
					if ($equals(opt, $StandardOpenOption::APPEND) || $equals(opt, $StandardOpenOption::WRITE)) {
						$throwNew($UnsupportedOperationException, $$str({"\'"_s, opt, "\' not allowed"_s}));
					}
				}
			}
		}
	}
	$var($ReadableByteChannel, rbc, $Files::newByteChannel(path, options));
	if ($instanceOf($FileChannelImpl, rbc)) {
		$nc(($cast($FileChannelImpl, rbc)))->setUninterruptible();
	}
	return $Channels::newInputStream(rbc);
}

$OutputStream* FileSystemProvider::newOutputStream($Path* path, $OpenOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(options)->length;
	$var($Set, opts, nullptr);
	if (len == 0) {
		$assign(opts, FileSystemProvider::DEFAULT_OPEN_OPTIONS);
	} else {
		$assign(opts, $new($HashSet));
		{
			$var($OpenOptionArray, arr$, options);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($OpenOption, opt, arr$->get(i$));
				{
					$init($StandardOpenOption);
					if ($equals(opt, $StandardOpenOption::READ)) {
						$throwNew($IllegalArgumentException, "READ not allowed"_s);
					}
					opts->add(opt);
				}
			}
		}
		$init($StandardOpenOption);
		opts->add($StandardOpenOption::WRITE);
	}
	$var($WritableByteChannel, wbc, newByteChannel(path, opts, $$new($FileAttributeArray, 0)));
	if ($instanceOf($FileChannelImpl, wbc)) {
		$nc(($cast($FileChannelImpl, wbc)))->setUninterruptible();
	}
	return $Channels::newOutputStream(wbc);
}

$FileChannel* FileSystemProvider::newFileChannel($Path* path, $Set* options, $FileAttributeArray* attrs) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$AsynchronousFileChannel* FileSystemProvider::newAsynchronousFileChannel($Path* path, $Set* options, $ExecutorService* executor, $FileAttributeArray* attrs) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void FileSystemProvider::createSymbolicLink($Path* link, $Path* target, $FileAttributeArray* attrs) {
	$throwNew($UnsupportedOperationException);
}

void FileSystemProvider::createLink($Path* link, $Path* existing) {
	$throwNew($UnsupportedOperationException);
}

bool FileSystemProvider::deleteIfExists($Path* path) {
	try {
		delete$(path);
		return true;
	} catch ($NoSuchFileException& ignore) {
		return false;
	}
	$shouldNotReachHere();
}

$Path* FileSystemProvider::readSymbolicLink($Path* link) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void clinit$FileSystemProvider($Class* class$) {
	$assignStatic(FileSystemProvider::lock, $new($Object));
	FileSystemProvider::loadingProviders = false;
	$init($StandardOpenOption);
	$assignStatic(FileSystemProvider::DEFAULT_OPEN_OPTIONS, $Set::of($StandardOpenOption::CREATE, $StandardOpenOption::TRUNCATE_EXISTING, $StandardOpenOption::WRITE));
}

FileSystemProvider::FileSystemProvider() {
}

$Class* FileSystemProvider::load$($String* name, bool initialize) {
	$loadClass(FileSystemProvider, name, initialize, &_FileSystemProvider_ClassInfo_, clinit$FileSystemProvider, allocate$FileSystemProvider);
	return class$;
}

$Class* FileSystemProvider::class$ = nullptr;

			} // spi
		} // file
	} // nio
} // java