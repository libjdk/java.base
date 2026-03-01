#include <jdk/internal/jrtfs/JrtPath.h>

#include <java/io/File.h>
#include <java/io/IOError.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/file/AccessDeniedException.h>
#include <java/nio/file/AccessMode.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/DirectoryNotEmptyException.h>
#include <java/nio/file/DirectoryStream$Filter.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileAlreadyExistsException.h>
#include <java/nio/file/FileStore.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/InvalidPathException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/NoSuchFileException.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/StandardCopyOption.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/WatchEvent$Modifier.h>
#include <java/nio/file/WatchKey.h>
#include <java/nio/file/WatchService.h>
#include <java/nio/file/attribute/BasicFileAttributeView.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/FileAttributeView.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jdk/internal/jimage/ImageReader$Node.h>
#include <jdk/internal/jrtfs/JrtDirectoryStream.h>
#include <jdk/internal/jrtfs/JrtFileAttributeView.h>
#include <jdk/internal/jrtfs/JrtFileAttributes.h>
#include <jdk/internal/jrtfs/JrtFileStore.h>
#include <jdk/internal/jrtfs/JrtFileSystem.h>
#include <jdk/internal/jrtfs/JrtPath$1.h>
#include <jdk/internal/jrtfs/JrtPath$2.h>
#include <jcpp.h>

#undef COPY_ATTRIBUTES
#undef CREATE_NEW
#undef H_ALPHA
#undef H_ALPHANUM
#undef H_DIGIT
#undef H_LOWALPHA
#undef H_MARK
#undef H_PATH
#undef H_PCHAR
#undef H_UNRESERVED
#undef H_UPALPHA
#undef L_ALPHA
#undef L_ALPHANUM
#undef L_DIGIT
#undef L_LOWALPHA
#undef L_MARK
#undef L_PATH
#undef L_PCHAR
#undef L_UNRESERVED
#undef L_UPALPHA
#undef READ
#undef REPLACE_EXISTING
#undef WRITE

using $AccessModeArray = $Array<::java::nio::file::AccessMode>;
using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $WatchEvent$KindArray = $Array<::java::nio::file::WatchEvent$Kind>;
using $WatchEvent$ModifierArray = $Array<::java::nio::file::WatchEvent$Modifier>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $File = ::java::io::File;
using $IOError = ::java::io::IOError;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $FileChannel = ::java::nio::channels::FileChannel;
using $SeekableByteChannel = ::java::nio::channels::SeekableByteChannel;
using $AccessDeniedException = ::java::nio::file::AccessDeniedException;
using $AccessMode = ::java::nio::file::AccessMode;
using $CopyOption = ::java::nio::file::CopyOption;
using $DirectoryNotEmptyException = ::java::nio::file::DirectoryNotEmptyException;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $DirectoryStream$Filter = ::java::nio::file::DirectoryStream$Filter;
using $FileAlreadyExistsException = ::java::nio::file::FileAlreadyExistsException;
using $FileStore = ::java::nio::file::FileStore;
using $FileSystem = ::java::nio::file::FileSystem;
using $Files = ::java::nio::file::Files;
using $InvalidPathException = ::java::nio::file::InvalidPathException;
using $NoSuchFileException = ::java::nio::file::NoSuchFileException;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $StandardCopyOption = ::java::nio::file::StandardCopyOption;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $WatchKey = ::java::nio::file::WatchKey;
using $WatchService = ::java::nio::file::WatchService;
using $BasicFileAttributeView = ::java::nio::file::attribute::BasicFileAttributeView;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $JrtDirectoryStream = ::jdk::internal::jrtfs::JrtDirectoryStream;
using $JrtFileAttributeView = ::jdk::internal::jrtfs::JrtFileAttributeView;
using $JrtFileAttributes = ::jdk::internal::jrtfs::JrtFileAttributes;
using $JrtFileSystem = ::jdk::internal::jrtfs::JrtFileSystem;
using $JrtPath$1 = ::jdk::internal::jrtfs::JrtPath$1;
using $JrtPath$2 = ::jdk::internal::jrtfs::JrtPath$2;

namespace jdk {
	namespace internal {
		namespace jrtfs {

$FieldInfo _JrtPath_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(JrtPath, $assertionsDisabled)},
	{"jrtfs", "Ljdk/internal/jrtfs/JrtFileSystem;", nullptr, $FINAL, $field(JrtPath, jrtfs)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(JrtPath, path)},
	{"offsets", "[I", nullptr, $PRIVATE | $VOLATILE, $field(JrtPath, offsets)},
	{"resolved", "Ljava/lang/String;", nullptr, $PRIVATE | $VOLATILE, $field(JrtPath, resolved)},
	{"L_DIGIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, L_DIGIT)},
	{"H_DIGIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JrtPath, H_DIGIT)},
	{"L_UPALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JrtPath, L_UPALPHA)},
	{"H_UPALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_UPALPHA)},
	{"L_LOWALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JrtPath, L_LOWALPHA)},
	{"H_LOWALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_LOWALPHA)},
	{"L_ALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JrtPath, L_ALPHA)},
	{"H_ALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_ALPHA)},
	{"L_ALPHANUM", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, L_ALPHANUM)},
	{"H_ALPHANUM", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_ALPHANUM)},
	{"L_MARK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, L_MARK)},
	{"H_MARK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_MARK)},
	{"L_UNRESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, L_UNRESERVED)},
	{"H_UNRESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_UNRESERVED)},
	{"L_PCHAR", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, L_PCHAR)},
	{"H_PCHAR", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_PCHAR)},
	{"L_PATH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, L_PATH)},
	{"H_PATH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, H_PATH)},
	{"hexDigits", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JrtPath, hexDigits)},
	{}
};

$MethodInfo _JrtPath_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/jrtfs/JrtFileSystem;Ljava/lang/String;)V", nullptr, 0, $method(JrtPath, init$, void, $JrtFileSystem*, $String*)},
	{"<init>", "(Ljdk/internal/jrtfs/JrtFileSystem;Ljava/lang/String;Z)V", nullptr, 0, $method(JrtPath, init$, void, $JrtFileSystem*, $String*, bool)},
	{"checkAccess", "([Ljava/nio/file/AccessMode;)V", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, checkAccess, void, $AccessModeArray*), "java.io.IOException"},
	{"checkPath", "(Ljava/nio/file/Path;)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PRIVATE, $method(JrtPath, checkPath, JrtPath*, $Path*)},
	{"compareTo", "(Ljava/nio/file/Path;)I", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, compareTo, int32_t, $Path*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(JrtPath, compareTo, int32_t, Object$*)},
	{"copy", "(Ljdk/internal/jrtfs/JrtPath;[Ljava/nio/file/CopyOption;)V", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, copy, void, JrtPath*, $CopyOptionArray*), "java.io.IOException"},
	{"copyToTarget", "(Ljdk/internal/jrtfs/JrtPath;[Ljava/nio/file/CopyOption;)V", nullptr, $PRIVATE | $TRANSIENT, $method(JrtPath, copyToTarget, void, JrtPath*, $CopyOptionArray*), "java.io.IOException"},
	{"createDirectory", "([Ljava/nio/file/attribute/FileAttribute;)V", "([Ljava/nio/file/attribute/FileAttribute<*>;)V", $FINAL | $TRANSIENT, $method(JrtPath, createDirectory, void, $FileAttributeArray*), "java.io.IOException"},
	{"delete", "()V", nullptr, $FINAL, $method(JrtPath, delete$, void), "java.io.IOException"},
	{"deleteIfExists", "()V", nullptr, $FINAL, $method(JrtPath, deleteIfExists, void), "java.io.IOException"},
	{"endsWith", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, endsWith, bool, $Path*)},
	{"endsWith", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, endsWith, bool, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, equals, bool, Object$*)},
	{"equalsNameAt", "(Ljdk/internal/jrtfs/JrtPath;I)Z", nullptr, $PRIVATE, $method(JrtPath, equalsNameAt, bool, JrtPath*, int32_t)},
	{"exists", "()Z", nullptr, $FINAL, $method(JrtPath, exists, bool)},
	{"getAttributes", "([Ljava/nio/file/LinkOption;)Ljdk/internal/jrtfs/JrtFileAttributes;", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, getAttributes, $JrtFileAttributes*, $LinkOptionArray*), "java.io.IOException"},
	{"getFileName", "()Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, getFileName, JrtPath*)},
	{"getFileStore", "()Ljava/nio/file/FileStore;", nullptr, $FINAL, $method(JrtPath, getFileStore, $FileStore*), "java.io.IOException"},
	{"getFileSystem", "()Ljdk/internal/jrtfs/JrtFileSystem;", nullptr, $PUBLIC, $virtualMethod(JrtPath, getFileSystem, $FileSystem*)},
	{"getName", "()Ljava/lang/String;", nullptr, $FINAL, $method(JrtPath, getName, $String*)},
	{"getName", "(I)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, getName, JrtPath*, int32_t)},
	{"getNameCount", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, getNameCount, int32_t)},
	{"getParent", "()Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, getParent, JrtPath*)},
	{"getResolved", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(JrtPath, getResolved, $String*)},
	{"getResolvedPath", "()Ljava/lang/String;", nullptr, $FINAL, $method(JrtPath, getResolvedPath, $String*)},
	{"getRoot", "()Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, getRoot, JrtPath*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, hashCode, int32_t)},
	{"highMask", "(Ljava/lang/String;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, highMask, int64_t, $String*)},
	{"highMask", "(CC)J", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, highMask, int64_t, char16_t, char16_t)},
	{"initOffsets", "()V", nullptr, $PRIVATE, $method(JrtPath, initOffsets, void)},
	{"isAbsolute", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, isAbsolute, bool)},
	{"isHidden", "()Z", nullptr, $FINAL, $method(JrtPath, isHidden, bool)},
	{"isSameFile", "(Ljava/nio/file/Path;)Z", nullptr, $FINAL, $method(JrtPath, isSameFile, bool, $Path*), "java.io.IOException"},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/nio/file/Path;>;", $PUBLIC | $FINAL, $virtualMethod(JrtPath, iterator, $Iterator*)},
	{"lowMask", "(Ljava/lang/String;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, lowMask, int64_t, $String*)},
	{"lowMask", "(CC)J", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, lowMask, int64_t, char16_t, char16_t)},
	{"match", "(CJJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, match, bool, char16_t, int64_t, int64_t)},
	{"move", "(Ljdk/internal/jrtfs/JrtPath;[Ljava/nio/file/CopyOption;)V", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, move, void, JrtPath*, $CopyOptionArray*), "java.io.IOException"},
	{"newByteChannel", "(Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/SeekableByteChannel;", "(Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/SeekableByteChannel;", $FINAL | $TRANSIENT, $method(JrtPath, newByteChannel, $SeekableByteChannel*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newDirectoryStream", "(Ljava/nio/file/DirectoryStream$Filter;)Ljava/nio/file/DirectoryStream;", "(Ljava/nio/file/DirectoryStream$Filter<-Ljava/nio/file/Path;>;)Ljava/nio/file/DirectoryStream<Ljava/nio/file/Path;>;", $FINAL, $method(JrtPath, newDirectoryStream, $DirectoryStream*, $DirectoryStream$Filter*), "java.io.IOException"},
	{"newFileChannel", "(Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;", "(Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/FileChannel;", $FINAL | $TRANSIENT, $method(JrtPath, newFileChannel, $FileChannel*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"newInputStream", "([Ljava/nio/file/OpenOption;)Ljava/io/InputStream;", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, newInputStream, $InputStream*, $OpenOptionArray*), "java.io.IOException"},
	{"newOutputStream", "([Ljava/nio/file/OpenOption;)Ljava/io/OutputStream;", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, newOutputStream, $OutputStream*, $OpenOptionArray*), "java.io.IOException"},
	{"normalize", "()Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, normalize, JrtPath*)},
	{"normalize", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, normalize, $String*, $String*)},
	{"normalize", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, normalize, $String*, $String*, int32_t)},
	{"readAttributes", "(Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map;", "(Ljava/lang/String;[Ljava/nio/file/LinkOption;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $FINAL | $TRANSIENT, $method(JrtPath, readAttributes, $Map*, $String*, $LinkOptionArray*), "java.io.IOException"},
	{"readSymbolicLink", "()Ljdk/internal/jrtfs/JrtPath;", nullptr, $FINAL, $method(JrtPath, readSymbolicLink, JrtPath*), "java.io.IOException"},
	{"register", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind<*>;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;", $PUBLIC | $FINAL | $TRANSIENT, $virtualMethod(JrtPath, register$, $WatchKey*, $WatchService*, $WatchEvent$KindArray*, $WatchEvent$ModifierArray*)},
	{"register", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind;)Ljava/nio/file/WatchKey;", "(Ljava/nio/file/WatchService;[Ljava/nio/file/WatchEvent$Kind<*>;)Ljava/nio/file/WatchKey;", $PUBLIC | $FINAL | $TRANSIENT, $virtualMethod(JrtPath, register$, $WatchKey*, $WatchService*, $WatchEvent$KindArray*)},
	{"relativize", "(Ljava/nio/file/Path;)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, relativize, JrtPath*, $Path*)},
	{"resolve", "(Ljava/nio/file/Path;)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, resolve, JrtPath*, $Path*)},
	{"resolve", "(Ljava/lang/String;)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, resolve, JrtPath*, $String*)},
	{"resolvePath", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(JrtPath, resolvePath, $String*)},
	{"resolveSibling", "(Ljava/nio/file/Path;)Ljava/nio/file/Path;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, resolveSibling, $Path*, $Path*)},
	{"resolveSibling", "(Ljava/lang/String;)Ljava/nio/file/Path;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, resolveSibling, $Path*, $String*)},
	{"setAttribute", "(Ljava/lang/String;Ljava/lang/Object;[Ljava/nio/file/LinkOption;)V", nullptr, $FINAL | $TRANSIENT, $method(JrtPath, setAttribute, void, $String*, Object$*, $LinkOptionArray*), "java.io.IOException"},
	{"setTimes", "(Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;)V", nullptr, $FINAL, $method(JrtPath, setTimes, void, $FileTime*, $FileTime*, $FileTime*), "java.io.IOException"},
	{"startsWith", "(Ljava/nio/file/Path;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, startsWith, bool, $Path*)},
	{"startsWith", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, startsWith, bool, $String*)},
	{"subpath", "(II)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, subpath, JrtPath*, int32_t, int32_t)},
	{"toAbsolutePath", "()Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, toAbsolutePath, JrtPath*)},
	{"toFile", "()Ljava/io/File;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, toFile, $File*)},
	{"toRealPath", "([Ljava/nio/file/LinkOption;)Ljdk/internal/jrtfs/JrtPath;", nullptr, $PUBLIC | $FINAL | $TRANSIENT, $virtualMethod(JrtPath, toRealPath, JrtPath*, $LinkOptionArray*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, toString, $String*)},
	{"toUri", "()Ljava/net/URI;", nullptr, $PUBLIC | $FINAL, $virtualMethod(JrtPath, toUri, $URI*)},
	{"toUri", "(Ljava/lang/String;)Ljava/net/URI;", nullptr, $PRIVATE | $STATIC, $staticMethod(JrtPath, toUri, $URI*, $String*)},
	{}
};

$InnerClassInfo _JrtPath_InnerClassesInfo_[] = {
	{"jdk.internal.jrtfs.JrtPath$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.jrtfs.JrtPath$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _JrtPath_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.jrtfs.JrtPath",
	"java.lang.Object",
	"java.nio.file.Path",
	_JrtPath_FieldInfo_,
	_JrtPath_MethodInfo_,
	nullptr,
	nullptr,
	_JrtPath_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.jrtfs.JrtPath$2,jdk.internal.jrtfs.JrtPath$1"
};

$Object* allocate$JrtPath($Class* clazz) {
	return $of($alloc(JrtPath));
}

bool JrtPath::$assertionsDisabled = false;
int64_t JrtPath::L_DIGIT = 0;
int64_t JrtPath::H_UPALPHA = 0;
int64_t JrtPath::H_LOWALPHA = 0;
int64_t JrtPath::H_ALPHA = 0;
int64_t JrtPath::L_ALPHANUM = 0;
int64_t JrtPath::H_ALPHANUM = 0;
int64_t JrtPath::L_MARK = 0;
int64_t JrtPath::H_MARK = 0;
int64_t JrtPath::L_UNRESERVED = 0;
int64_t JrtPath::H_UNRESERVED = 0;
int64_t JrtPath::L_PCHAR = 0;
int64_t JrtPath::H_PCHAR = 0;
int64_t JrtPath::L_PATH = 0;
int64_t JrtPath::H_PATH = 0;
$chars* JrtPath::hexDigits = nullptr;

void JrtPath::init$($JrtFileSystem* jrtfs, $String* path) {
	$set(this, jrtfs, jrtfs);
	$set(this, path, normalize(path));
	$set(this, resolved, nullptr);
}

void JrtPath::init$($JrtFileSystem* jrtfs, $String* path, bool normalized) {
	$set(this, jrtfs, jrtfs);
	$set(this, path, normalized ? path : normalize(path));
	$set(this, resolved, nullptr);
}

$String* JrtPath::getName() {
	return this->path;
}

JrtPath* JrtPath::getRoot() {
	if (this->isAbsolute()) {
		return $nc(this->jrtfs)->getRootPath();
	} else {
		return nullptr;
	}
}

JrtPath* JrtPath::getFileName() {
	if ($nc(this->path)->isEmpty()) {
		return this;
	}
	bool var$0 = $nc(this->path)->length() == 1;
	if (var$0 && $nc(this->path)->charAt(0) == u'/') {
		return nullptr;
	}
	int32_t off = $nc(this->path)->lastIndexOf((int32_t)u'/');
	if (off == -1) {
		return this;
	}
	return $new(JrtPath, this->jrtfs, $($nc(this->path)->substring(off + 1)), true);
}

JrtPath* JrtPath::getParent() {
	initOffsets();
	int32_t count = $nc(this->offsets)->length;
	if (count == 0) {
		return nullptr;
	}
	int32_t off = $nc(this->offsets)->get(count - 1) - 1;
	if (off <= 0) {
		return getRoot();
	}
	return $new(JrtPath, this->jrtfs, $($nc(this->path)->substring(0, off)));
}

int32_t JrtPath::getNameCount() {
	initOffsets();
	return $nc(this->offsets)->length;
}

JrtPath* JrtPath::getName(int32_t index) {
	$useLocalCurrentObjectStackCache();
	initOffsets();
	if (index < 0 || index >= $nc(this->offsets)->length) {
		$throwNew($IllegalArgumentException, $$str({"index: "_s, $$str(index), ", offsets length: "_s, $$str($nc(this->offsets)->length)}));
	}
	int32_t begin = $nc(this->offsets)->get(index);
	int32_t end = 0;
	if (index == ($nc(this->offsets)->length - 1)) {
		end = $nc(this->path)->length();
	} else {
		end = $nc(this->offsets)->get(index + 1);
	}
	return $new(JrtPath, this->jrtfs, $($nc(this->path)->substring(begin, end)));
}

JrtPath* JrtPath::subpath(int32_t beginIndex, int32_t endIndex) {
	$useLocalCurrentObjectStackCache();
	initOffsets();
	if (beginIndex < 0 || endIndex > $nc(this->offsets)->length || beginIndex >= endIndex) {
		$throwNew($IllegalArgumentException, $$str({"beginIndex: "_s, $$str(beginIndex), ", endIndex: "_s, $$str(endIndex), ", offsets length: "_s, $$str($nc(this->offsets)->length)}));
	}
	int32_t begin = $nc(this->offsets)->get(beginIndex);
	int32_t end = 0;
	if (endIndex == $nc(this->offsets)->length) {
		end = $nc(this->path)->length();
	} else {
		end = $nc(this->offsets)->get(endIndex);
	}
	return $new(JrtPath, this->jrtfs, $($nc(this->path)->substring(begin, end)));
}

JrtPath* JrtPath::toRealPath($LinkOptionArray* options) {
	return $nc(this->jrtfs)->toRealPath(this, options);
}

JrtPath* JrtPath::toAbsolutePath() {
	if (isAbsolute()) {
		return this;
	}
	return $new(JrtPath, this->jrtfs, $$str({"/"_s, this->path}), true);
}

$URI* JrtPath::toUri() {
	$useLocalCurrentObjectStackCache();
	$var($String, p, $nc($(toAbsolutePath()))->path);
	bool var$0 = !$nc(p)->startsWith("/modules"_s);
	if (var$0 || $nc(p)->contains(".."_s)) {
		$throwNew($IOError, $$new($RuntimeException, $$str({p, " cannot be represented as URI"_s})));
	}
	$assign(p, $nc(p)->substring("/modules"_s->length()));
	if (p->isEmpty()) {
		$assign(p, "/"_s);
	}
	return toUri(p);
}

bool JrtPath::equalsNameAt(JrtPath* other, int32_t index) {
	int32_t mbegin = $nc(this->offsets)->get(index);
	int32_t mlen = 0;
	if (index == ($nc(this->offsets)->length - 1)) {
		mlen = $nc(this->path)->length() - mbegin;
	} else {
		mlen = $nc(this->offsets)->get(index + 1) - mbegin - 1;
	}
	int32_t obegin = $nc($nc(other)->offsets)->get(index);
	int32_t olen = 0;
	if (index == ($nc(other->offsets)->length - 1)) {
		olen = $nc(other->path)->length() - obegin;
	} else {
		olen = $nc(other->offsets)->get(index + 1) - obegin - 1;
	}
	if (mlen != olen) {
		return false;
	}
	int32_t n = 0;
	while (n < mlen) {
		char16_t var$0 = $nc(this->path)->charAt(mbegin + n);
		if (var$0 != $nc(other->path)->charAt(obegin + n)) {
			return false;
		}
		++n;
	}
	return true;
}

JrtPath* JrtPath::relativize($Path* other) {
	$useLocalCurrentObjectStackCache();
	$var(JrtPath, o, checkPath(other));
	if ($nc(o)->equals(this)) {
		return $new(JrtPath, this->jrtfs, ""_s, true);
	}
	if ($nc(this->path)->isEmpty()) {
		return o;
	}
	bool var$0 = this->jrtfs != $nc(o)->jrtfs;
	if (!var$0) {
		bool var$1 = isAbsolute();
		var$0 = var$1 != $nc(o)->isAbsolute();
	}
	if (var$0) {
		$throwNew($IllegalArgumentException, $$str({"Incorrect filesystem or path: "_s, other}));
	}
	$var($String, tp, this->path);
	$var($String, op, $nc(o)->path);
	if ($nc(op)->startsWith(tp)) {
		int32_t off = $nc(tp)->length();
		if (op->charAt(off - 1) == u'/') {
			return $new(JrtPath, this->jrtfs, $(op->substring(off)), true);
		}
		if (op->charAt(off) == u'/') {
			return $new(JrtPath, this->jrtfs, $(op->substring(off + 1)), true);
		}
	}
	int32_t mc = this->getNameCount();
	int32_t oc = o->getNameCount();
	int32_t n = $Math::min(mc, oc);
	int32_t i = 0;
	while (i < n) {
		if (!equalsNameAt(o, i)) {
			break;
		}
		++i;
	}
	int32_t dotdots = mc - i;
	int32_t len = dotdots * 3 - 1;
	if (i < oc) {
		len += ($nc(o->path)->length() - $nc(o->offsets)->get(i) + 1);
	}
	$var($StringBuilder, sb, $new($StringBuilder, len));
	while (dotdots > 0) {
		sb->append(".."_s);
		if (sb->length() < len) {
			sb->append(u'/');
		}
		--dotdots;
	}
	if (i < oc) {
		sb->append(static_cast<$CharSequence*>(o->path), $nc(o->offsets)->get(i), $nc(o->path)->length());
	}
	return $new(JrtPath, this->jrtfs, $(sb->toString()), true);
}

$FileSystem* JrtPath::getFileSystem() {
	return this->jrtfs;
}

bool JrtPath::isAbsolute() {
	bool var$0 = !$nc(this->path)->isEmpty();
	return var$0 && $nc(this->path)->charAt(0) == u'/';
}

JrtPath* JrtPath::resolve($Path* other) {
	$useLocalCurrentObjectStackCache();
	$var(JrtPath, o, checkPath(other));
	bool var$0 = $nc(this->path)->isEmpty();
	if (var$0 || $nc(o)->isAbsolute()) {
		return o;
	}
	if ($nc($nc(o)->path)->isEmpty()) {
		return this;
	}
	int32_t var$1 = $nc(this->path)->length();
	$var($StringBuilder, sb, $new($StringBuilder, var$1 + $nc($nc(o)->path)->length() + 1));
	sb->append(this->path);
	if ($nc(this->path)->charAt($nc(this->path)->length() - 1) != u'/') {
		sb->append(u'/');
	}
	sb->append($nc(o)->path);
	return $new(JrtPath, this->jrtfs, $(sb->toString()), true);
}

$Path* JrtPath::resolveSibling($Path* other) {
	$Objects::requireNonNull($of(other), "other"_s);
	$var($Path, parent, getParent());
	return (parent == nullptr) ? other : $nc(parent)->resolve(other);
}

bool JrtPath::startsWith($Path* other) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf(JrtPath, $Objects::requireNonNull(other)))) {
		return false;
	}
	$var(JrtPath, o, $cast(JrtPath, other));
	$var($String, tp, this->path);
	$var($String, op, $nc(o)->path);
	bool var$1 = isAbsolute();
	bool var$0 = var$1 != o->isAbsolute();
	if (var$0 || !$nc(tp)->startsWith(op)) {
		return false;
	}
	int32_t off = $nc(op)->length();
	if (off == 0) {
		return $nc(tp)->isEmpty();
	}
	bool var$3 = $nc(tp)->length() == off;
	bool var$2 = var$3 || $nc(tp)->charAt(off) == u'/' || off == 0;
	return var$2 || op->charAt(off - 1) == u'/';
}

bool JrtPath::endsWith($Path* other) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf(JrtPath, $Objects::requireNonNull(other)))) {
		return false;
	}
	$var(JrtPath, o, $cast(JrtPath, other));
	$var(JrtPath, t, this);
	int32_t olast = $nc($nc(o)->path)->length() - 1;
	if (olast > 0 && $nc(o->path)->charAt(olast) == u'/') {
		--olast;
	}
	int32_t last = $nc(t->path)->length() - 1;
	if (last > 0 && $nc(t->path)->charAt(last) == u'/') {
		--last;
	}
	if (olast == -1) {
		return last == -1;
	}
	bool var$0 = o->isAbsolute();
	if ((var$0 && (!t->isAbsolute() || olast != last)) || last < olast) {
		return false;
	}
	for (; olast >= 0; --olast, --last) {
		char16_t var$1 = $nc(o->path)->charAt(olast);
		if (var$1 != $nc(t->path)->charAt(last)) {
			return false;
		}
	}
	bool var$2 = $nc(o->path)->charAt(olast + 1) == u'/' || last == -1;
	return var$2 || $nc(t->path)->charAt(last) == u'/';
}

JrtPath* JrtPath::resolve($String* other) {
	$useLocalCurrentObjectStackCache();
	return resolve($($nc($($cast($JrtFileSystem, getFileSystem())))->getPath(other, $$new($StringArray, 0))));
}

$Path* JrtPath::resolveSibling($String* other) {
	$useLocalCurrentObjectStackCache();
	return resolveSibling($($nc($($cast($JrtFileSystem, getFileSystem())))->getPath(other, $$new($StringArray, 0))));
}

bool JrtPath::startsWith($String* other) {
	$useLocalCurrentObjectStackCache();
	return startsWith($($nc($($cast($JrtFileSystem, getFileSystem())))->getPath(other, $$new($StringArray, 0))));
}

bool JrtPath::endsWith($String* other) {
	$useLocalCurrentObjectStackCache();
	return endsWith($($nc($($cast($JrtFileSystem, getFileSystem())))->getPath(other, $$new($StringArray, 0))));
}

JrtPath* JrtPath::normalize() {
	$var($String, res, getResolved());
	if (res == this->path) {
		return this;
	}
	return $new(JrtPath, this->jrtfs, res, true);
}

JrtPath* JrtPath::checkPath($Path* path) {
	$Objects::requireNonNull(path);
	if (!($instanceOf(JrtPath, path))) {
		$throwNew($ProviderMismatchException, $$str({"path class: "_s, $of(path)->getClass()}));
	}
	return $cast(JrtPath, path);
}

void JrtPath::initOffsets() {
	if (this->offsets == nullptr) {
		int32_t len = $nc(this->path)->length();
		int32_t count = 0;
		int32_t off = 0;
		while (off < len) {
			char16_t c = $nc(this->path)->charAt(off++);
			if (c != u'/') {
				++count;
				off = $nc(this->path)->indexOf((int32_t)u'/', off);
				if (off == -1) {
					break;
				}
			}
		}
		$var($ints, offsets, $new($ints, count));
		count = 0;
		off = 0;
		while (off < len) {
			char16_t c = $nc(this->path)->charAt(off);
			if (c == u'/') {
				++off;
			} else {
				offsets->set(count++, off++);
				off = $nc(this->path)->indexOf((int32_t)u'/', off);
				if (off == -1) {
					break;
				}
			}
		}
		$set(this, offsets, offsets);
	}
}

$String* JrtPath::getResolvedPath() {
	$useLocalCurrentObjectStackCache();
	$var($String, r, this->resolved);
	if (r == nullptr) {
		if (isAbsolute()) {
			$assign(r, getResolved());
		} else {
			$assign(r, $nc($(toAbsolutePath()))->getResolvedPath());
		}
		$set(this, resolved, r);
	}
	return r;
}

$String* JrtPath::normalize($String* path) {
	$init(JrtPath);
	int32_t len = $nc(path)->length();
	if (len == 0) {
		return path;
	}
	char16_t prevC = (char16_t)0;
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = path->charAt(i);
		if (c == u'\\' || c == u'\0') {
			return normalize(path, i);
		}
		if (c == u'/' && prevC == u'/') {
			return normalize(path, i - 1);
		}
		prevC = c;
	}
	if (prevC == u'/' && len > 1) {
		return path->substring(0, len - 1);
	}
	return path;
}

$String* JrtPath::normalize($String* path, int32_t off) {
	$init(JrtPath);
	int32_t len = $nc(path)->length();
	$var($StringBuilder, to, $new($StringBuilder, len));
	to->append(static_cast<$CharSequence*>(path), 0, off);
	char16_t prevC = (char16_t)0;
	while (off < len) {
		char16_t c = path->charAt(off++);
		if (c == u'\\') {
			c = u'/';
		}
		if (c == u'/' && prevC == u'/') {
			continue;
		}
		if (c == u'\0') {
			$throwNew($InvalidPathException, path, "Path: NUL character not allowed"_s);
		}
		to->append(c);
		prevC = c;
	}
	len = to->length();
	if (len > 1 && to->charAt(len - 1) == u'/') {
		to->deleteCharAt(len - 1);
	}
	return to->toString();
}

$String* JrtPath::getResolved() {
	int32_t length = $nc(this->path)->length();
	bool var$0 = length == 0;
	if (!var$0) {
		bool var$1 = $nc(this->path)->indexOf("./"_s) == -1;
		var$0 = (var$1 && $nc(this->path)->charAt(length - 1) != u'.');
	}
	if (var$0) {
		return this->path;
	} else {
		return resolvePath();
	}
}

$String* JrtPath::resolvePath() {
	$useLocalCurrentObjectStackCache();
	int32_t length = $nc(this->path)->length();
	$var($chars, to, $new($chars, length));
	int32_t nc = getNameCount();
	$var($ints, lastM, $new($ints, nc));
	int32_t lastMOff = -1;
	int32_t m = 0;
	for (int32_t i = 0; i < nc; ++i) {
		int32_t n = $nc(this->offsets)->get(i);
		int32_t len = (i == $nc(this->offsets)->length - 1) ? length - n : $nc(this->offsets)->get(i + 1) - n - 1;
		if (len == 1 && $nc(this->path)->charAt(n) == u'.') {
			if (m == 0 && $nc(this->path)->charAt(0) == u'/') {
				to->set(m++, u'/');
			}
			continue;
		}
		bool var$0 = len == 2 && $nc(this->path)->charAt(n) == u'.';
		if (var$0 && $nc(this->path)->charAt(n + 1) == u'.') {
			if (lastMOff >= 0) {
				m = lastM->get(lastMOff--);
				continue;
			}
			if ($nc(this->path)->charAt(0) == u'/') {
				if (m == 0) {
					to->set(m++, u'/');
				}
			} else {
				if (m != 0 && to->get(m - 1) != u'/') {
					to->set(m++, u'/');
				}
				while (len-- > 0) {
					to->set(m++, $nc(this->path)->charAt(n++));
				}
			}
			continue;
		}
		if (m == 0 && $nc(this->path)->charAt(0) == u'/' || m != 0 && to->get(m - 1) != u'/') {
			to->set(m++, u'/');
		}
		lastM->set(++lastMOff, m);
		while (len-- > 0) {
			to->set(m++, $nc(this->path)->charAt(n++));
		}
	}
	if (m > 1 && to->get(m - 1) == u'/') {
		--m;
	}
	return (m == to->length) ? $new($String, to) : $new($String, to, 0, m);
}

$String* JrtPath::toString() {
	return this->path;
}

int32_t JrtPath::hashCode() {
	return $nc(this->path)->hashCode();
}

bool JrtPath::equals(Object$* obj) {
	return $instanceOf(JrtPath, obj) && $nc(this->path)->equals($nc(($cast(JrtPath, obj)))->path);
}

int32_t JrtPath::compareTo($Path* other) {
	$var(JrtPath, o, checkPath(other));
	return $nc(this->path)->compareTo($nc(o)->path);
}

$WatchKey* JrtPath::register$($WatchService* watcher, $WatchEvent$KindArray* events, $WatchEvent$ModifierArray* modifiers) {
	$Objects::requireNonNull($of(watcher), "watcher"_s);
	$Objects::requireNonNull($of(events), "events"_s);
	$Objects::requireNonNull($of(modifiers), "modifiers"_s);
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$WatchKey* JrtPath::register$($WatchService* watcher, $WatchEvent$KindArray* events) {
	return register$(watcher, events, $$new($WatchEvent$ModifierArray, 0));
}

$File* JrtPath::toFile() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Iterator* JrtPath::iterator() {
	return $new($JrtPath$1, this);
}

JrtPath* JrtPath::readSymbolicLink() {
	if (!$nc(this->jrtfs)->isLink(this)) {
		$throwNew($IOException, "not a symbolic link"_s);
	}
	return $nc(this->jrtfs)->resolveLink(this);
}

bool JrtPath::isHidden() {
	return false;
}

void JrtPath::createDirectory($FileAttributeArray* attrs) {
	$nc(this->jrtfs)->createDirectory(this, attrs);
}

$InputStream* JrtPath::newInputStream($OpenOptionArray* options) {
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
					if (!$equals(opt, $StandardOpenOption::READ)) {
						$throwNew($UnsupportedOperationException, $$str({"\'"_s, opt, "\' not allowed"_s}));
					}
				}
			}
		}
	}
	return $nc(this->jrtfs)->newInputStream(this);
}

$DirectoryStream* JrtPath::newDirectoryStream($DirectoryStream$Filter* filter) {
	return $new($JrtDirectoryStream, this, filter);
}

void JrtPath::delete$() {
	$nc(this->jrtfs)->deleteFile(this, true);
}

void JrtPath::deleteIfExists() {
	$nc(this->jrtfs)->deleteFile(this, false);
}

$JrtFileAttributes* JrtPath::getAttributes($LinkOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$var($JrtFileAttributes, zfas, $nc(this->jrtfs)->getFileAttributes(this, options));
	if (zfas == nullptr) {
		$throwNew($NoSuchFileException, $(toString()));
	}
	return zfas;
}

void JrtPath::setAttribute($String* attribute, Object$* value, $LinkOptionArray* options) {
	$JrtFileAttributeView::setAttribute(this, attribute, value);
}

$Map* JrtPath::readAttributes($String* attributes, $LinkOptionArray* options) {
	return $JrtFileAttributeView::readAttributes(this, attributes, options);
}

void JrtPath::setTimes($FileTime* mtime, $FileTime* atime, $FileTime* ctime) {
	$nc(this->jrtfs)->setTimes(this, mtime, atime, ctime);
}

$FileStore* JrtPath::getFileStore() {
	if (exists()) {
		return $nc(this->jrtfs)->getFileStore(this);
	}
	$throwNew($NoSuchFileException, this->path);
}

bool JrtPath::isSameFile($Path* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other) || this->equals(other)) {
		return true;
	}
	bool var$0 = other == nullptr;
	if (!var$0) {
		var$0 = !$equals($cast($JrtFileSystem, this->getFileSystem()), $nc(other)->getFileSystem());
	}
	if (var$0) {
		return false;
	}
	this->checkAccess($$new($AccessModeArray, 0));
	$var(JrtPath, o, $cast(JrtPath, other));
	$nc(o)->checkAccess($$new($AccessModeArray, 0));
	bool var$1 = $nc($(this->getResolvedPath()))->equals($(o->getResolvedPath()));
	return var$1 || $nc(this->jrtfs)->isSameFile(this, o);
}

$SeekableByteChannel* JrtPath::newByteChannel($Set* options, $FileAttributeArray* attrs) {
	return $nc(this->jrtfs)->newByteChannel(this, options, attrs);
}

$FileChannel* JrtPath::newFileChannel($Set* options, $FileAttributeArray* attrs) {
	return $nc(this->jrtfs)->newFileChannel(this, options, attrs);
}

void JrtPath::checkAccess($AccessModeArray* modes) {
	$useLocalCurrentObjectStackCache();
	if ($nc(modes)->length == 0) {
		$nc(this->jrtfs)->checkNode(this);
	} else {
		bool w = false;
		{
			$var($AccessModeArray, arr$, modes);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$AccessMode* mode = arr$->get(i$);
				{
					$init($JrtPath$2);
					switch ($nc($JrtPath$2::$SwitchMap$java$nio$file$AccessMode)->get($nc((mode))->ordinal())) {
					case 1:
						{
							break;
						}
					case 2:
						{
							w = true;
							break;
						}
					case 3:
						{
							$throwNew($AccessDeniedException, $(toString()));
						}
					default:
						{
							$throwNew($UnsupportedOperationException);
						}
					}
				}
			}
		}
		$nc(this->jrtfs)->checkNode(this);
		if (w && $nc(this->jrtfs)->isReadOnly()) {
			$throwNew($AccessDeniedException, $(toString()));
		}
	}
}

bool JrtPath::exists() {
	try {
		return $nc(this->jrtfs)->exists(this);
	} catch ($IOException& x) {
	}
	return false;
}

$OutputStream* JrtPath::newOutputStream($OpenOptionArray* options) {
	if ($nc(options)->length == 0) {
		$init($StandardOpenOption);
		return $nc(this->jrtfs)->newOutputStream(this, $$new($OpenOptionArray, {
			static_cast<$OpenOption*>($StandardOpenOption::CREATE_NEW),
			static_cast<$OpenOption*>($StandardOpenOption::WRITE)
		}));
	}
	return $nc(this->jrtfs)->newOutputStream(this, options);
}

void JrtPath::move(JrtPath* target, $CopyOptionArray* options) {
	if (this->jrtfs == $nc(target)->jrtfs) {
		$nc(this->jrtfs)->copyFile(true, this, target, options);
	} else {
		copyToTarget(target, options);
		delete$();
	}
}

void JrtPath::copy(JrtPath* target, $CopyOptionArray* options) {
	if (this->jrtfs == $nc(target)->jrtfs) {
		$nc(this->jrtfs)->copyFile(false, this, target, options);
	} else {
		copyToTarget(target, options);
	}
}

void JrtPath::copyToTarget(JrtPath* target, $CopyOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	bool replaceExisting = false;
	bool copyAttrs = false;
	{
		$var($CopyOptionArray, arr$, options);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CopyOption, opt, arr$->get(i$));
			{
				$init($StandardCopyOption);
				if ($equals(opt, $StandardCopyOption::REPLACE_EXISTING)) {
					replaceExisting = true;
				} else {
					if ($equals(opt, $StandardCopyOption::COPY_ATTRIBUTES)) {
						copyAttrs = true;
					}
				}
			}
		}
	}
	$var($BasicFileAttributes, jrtfas, getAttributes($$new($LinkOptionArray, 0)));
	bool exists = false;
	if (replaceExisting) {
		try {
			$nc(target)->deleteIfExists();
			exists = false;
		} catch ($DirectoryNotEmptyException& x) {
			exists = true;
		}
	} else {
		exists = $nc(target)->exists();
	}
	if (exists) {
		$throwNew($FileAlreadyExistsException, $($nc(target)->toString()));
	}
	if ($nc(jrtfas)->isDirectory()) {
		$nc(target)->createDirectory($$new($FileAttributeArray, 0));
	} else {
		{
			$var($InputStream, is, $nc(this->jrtfs)->newInputStream(this));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$var($OutputStream, os, $nc(target)->newOutputStream($$new($OpenOptionArray, 0)));
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									$var($bytes, buf, $new($bytes, 8192));
									int32_t n = 0;
									while ((n = $nc(is)->read(buf)) != -1) {
										$nc(os)->write(buf, 0, n);
									}
								} catch ($Throwable& t$) {
									if (os != nullptr) {
										try {
											os->close();
										} catch ($Throwable& x2) {
											t$->addSuppressed(x2);
										}
									}
									$throw(t$);
								}
							} catch ($Throwable& var$2) {
								$assign(var$1, var$2);
							} /*finally*/ {
								if (os != nullptr) {
									os->close();
								}
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					} catch ($Throwable& t$) {
						if (is != nullptr) {
							try {
								is->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$3) {
					$assign(var$0, var$3);
				} /*finally*/ {
					if (is != nullptr) {
						is->close();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
	if (copyAttrs) {
		$load($BasicFileAttributeView);
		$var($BasicFileAttributeView, view, $cast($BasicFileAttributeView, $Files::getFileAttributeView(target, $BasicFileAttributeView::class$, $$new($LinkOptionArray, 0))));
		try {
			$var($FileTime, var$4, $nc(jrtfas)->lastModifiedTime());
			$var($FileTime, var$5, jrtfas->lastAccessTime());
			$nc(view)->setTimes(var$4, var$5, $(jrtfas->creationTime()));
		} catch ($IOException& x) {
			try {
				$nc(target)->delete$();
			} catch ($IOException& ignore) {
			}
			$throw(x);
		}
	}
}

$URI* JrtPath::toUri($String* str) {
	$init(JrtPath);
	$useLocalCurrentObjectStackCache();
	$var($chars, path, $nc(str)->toCharArray());
	if (!JrtPath::$assertionsDisabled && !(path->get(0) == u'/')) {
		$throwNew($AssertionError);
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(path->get(0));
	for (int32_t i = 1; i < path->length; ++i) {
		char16_t c = (char16_t)((int32_t)(path->get(i) & (uint32_t)255));
		if (match(c, JrtPath::L_PATH, JrtPath::H_PATH)) {
			sb->append(c);
		} else {
			sb->append(u'%');
			sb->append($nc(JrtPath::hexDigits)->get((int32_t)((c >> 4) & (uint32_t)15)));
			sb->append($nc(JrtPath::hexDigits)->get((int32_t)((c) & (uint32_t)15)));
		}
	}
	try {
		return $new($URI, $$str({"jrt:"_s, $(sb->toString())}));
	} catch ($URISyntaxException& x) {
		$throwNew($AssertionError, $of(x));
	}
	$shouldNotReachHere();
}

int64_t JrtPath::lowMask($String* chars) {
	$init(JrtPath);
	int32_t n = $nc(chars)->length();
	int64_t m = 0;
	for (int32_t i = 0; i < n; ++i) {
		char16_t c = chars->charAt(i);
		if (c < 64) {
			m |= ($sl((int64_t)1, c));
		}
	}
	return m;
}

int64_t JrtPath::highMask($String* chars) {
	$init(JrtPath);
	int32_t n = $nc(chars)->length();
	int64_t m = 0;
	for (int32_t i = 0; i < n; ++i) {
		char16_t c = chars->charAt(i);
		if ((c >= 64) && (c < 128)) {
			m |= ($sl((int64_t)1, c - 64));
		}
	}
	return m;
}

int64_t JrtPath::lowMask(char16_t first, char16_t last) {
	$init(JrtPath);
	int64_t m = 0;
	int32_t f = $Math::max($Math::min((int32_t)first, 63), 0);
	int32_t l = $Math::max($Math::min((int32_t)last, 63), 0);
	for (int32_t i = f; i <= l; ++i) {
		m |= $sl((int64_t)1, i);
	}
	return m;
}

int64_t JrtPath::highMask(char16_t first, char16_t last) {
	$init(JrtPath);
	int64_t m = 0;
	int32_t f = $Math::max($Math::min((int32_t)first, 127), 64) - 64;
	int32_t l = $Math::max($Math::min((int32_t)last, 127), 64) - 64;
	for (int32_t i = f; i <= l; ++i) {
		m |= $sl((int64_t)1, i);
	}
	return m;
}

bool JrtPath::match(char16_t c, int64_t lowMask, int64_t highMask) {
	$init(JrtPath);
	if (c < 64) {
		return ((int64_t)(($sl((int64_t)1, c)) & (uint64_t)lowMask)) != 0;
	}
	if (c < 128) {
		return ((int64_t)(($sl((int64_t)1, c - 64)) & (uint64_t)highMask)) != 0;
	}
	return false;
}

int32_t JrtPath::compareTo(Object$* other) {
	return this->compareTo($cast($Path, other));
}

void clinit$JrtPath($Class* class$) {
	JrtPath::$assertionsDisabled = !JrtPath::class$->desiredAssertionStatus();
	JrtPath::L_DIGIT = JrtPath::lowMask(u'0', u'9');
	JrtPath::H_UPALPHA = JrtPath::highMask(u'A', u'Z');
	JrtPath::H_LOWALPHA = JrtPath::highMask(u'a', u'z');
	JrtPath::H_ALPHA = JrtPath::H_LOWALPHA | JrtPath::H_UPALPHA;
	JrtPath::L_ALPHANUM = JrtPath::L_DIGIT | JrtPath::L_ALPHA;
	JrtPath::H_ALPHANUM = JrtPath::H_DIGIT | JrtPath::H_ALPHA;
	JrtPath::L_MARK = JrtPath::lowMask("-_.!~*\'()"_s);
	JrtPath::H_MARK = JrtPath::highMask("-_.!~*\'()"_s);
	JrtPath::L_UNRESERVED = JrtPath::L_ALPHANUM | JrtPath::L_MARK;
	JrtPath::H_UNRESERVED = JrtPath::H_ALPHANUM | JrtPath::H_MARK;
	JrtPath::L_PCHAR = JrtPath::L_UNRESERVED | JrtPath::lowMask(":@&=+$,"_s);
	JrtPath::H_PCHAR = JrtPath::H_UNRESERVED | JrtPath::highMask(":@&=+$,"_s);
	JrtPath::L_PATH = JrtPath::L_PCHAR | JrtPath::lowMask(";/"_s);
	JrtPath::H_PATH = JrtPath::H_PCHAR | JrtPath::highMask(";/"_s);
	$assignStatic(JrtPath::hexDigits, $new($chars, {
		u'0',
		u'1',
		u'2',
		u'3',
		u'4',
		u'5',
		u'6',
		u'7',
		u'8',
		u'9',
		u'A',
		u'B',
		u'C',
		u'D',
		u'E',
		u'F'
	}));
}

JrtPath::JrtPath() {
}

$Class* JrtPath::load$($String* name, bool initialize) {
	$loadClass(JrtPath, name, initialize, &_JrtPath_ClassInfo_, clinit$JrtPath, allocate$JrtPath);
	return class$;
}

$Class* JrtPath::class$ = nullptr;

		} // jrtfs
	} // internal
} // jdk