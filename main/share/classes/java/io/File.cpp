#include <java/io/File.h>

#include <java/io/DefaultFileSystem.h>
#include <java/io/DeleteOnExitHook.h>
#include <java/io/File$PathStatus.h>
#include <java/io/File$TempDirectory.h>
#include <java/io/FileFilter.h>
#include <java/io/FileSystem.h>
#include <java/io/FilenameFilter.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URL.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/FileSystems.h>
#include <java/nio/file/Path.h>
#include <java/security/Permission.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jcpp.h>

#undef ACCESS_EXECUTE
#undef ACCESS_READ
#undef ACCESS_WRITE
#undef BA_DIRECTORY
#undef BA_EXISTS
#undef BA_HIDDEN
#undef BA_REGULAR
#undef CHECKED
#undef INVALID
#undef MAX_VALUE
#undef PATH_OFFSET
#undef PREFIX_LENGTH_OFFSET
#undef SPACE_FREE
#undef SPACE_TOTAL
#undef SPACE_USABLE
#undef UNSAFE

using $FileArray = $Array<::java::io::File>;
using $DefaultFileSystem = ::java::io::DefaultFileSystem;
using $DeleteOnExitHook = ::java::io::DeleteOnExitHook;
using $File$PathStatus = ::java::io::File$PathStatus;
using $File$TempDirectory = ::java::io::File$TempDirectory;
using $FileFilter = ::java::io::FileFilter;
using $FileSystem = ::java::io::FileSystem;
using $FilenameFilter = ::java::io::FilenameFilter;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URL = ::java::net::URL;
using $1FileSystem = ::java::nio::file::FileSystem;
using $FileSystems = ::java::nio::file::FileSystems;
using $Path = ::java::nio::file::Path;
using $Permission = ::java::security::Permission;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Unsafe = ::jdk::internal::misc::Unsafe;

namespace java {
	namespace io {

$CompoundAttribute _File_MethodAnnotations_toURL61[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _File_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(File, $assertionsDisabled)},
	{"fs", "Ljava/io/FileSystem;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(File, fs)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(File, path)},
	{"status", "Ljava/io/File$PathStatus;", nullptr, $PRIVATE | $TRANSIENT, $field(File, status)},
	{"prefixLength", "I", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(File, prefixLength)},
	{"separatorChar", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(File, separatorChar)},
	{"separator", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(File, separator)},
	{"pathSeparatorChar", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(File, pathSeparatorChar)},
	{"pathSeparator", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(File, pathSeparator)},
	{"UNSAFE", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(File, UNSAFE)},
	{"PATH_OFFSET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(File, PATH_OFFSET)},
	{"PREFIX_LENGTH_OFFSET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(File, PREFIX_LENGTH_OFFSET)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(File, serialVersionUID)},
	{"filePath", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(File, filePath)},
	{}
};

$MethodInfo _File_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(File, init$, void, $String*, int32_t)},
	{"<init>", "(Ljava/lang/String;Ljava/io/File;)V", nullptr, $PRIVATE, $method(File, init$, void, $String*, File*)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(File, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(File, init$, void, $String*, $String*)},
	{"<init>", "(Ljava/io/File;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(File, init$, void, File*, $String*)},
	{"<init>", "(Ljava/net/URI;)V", nullptr, $PUBLIC, $method(File, init$, void, $URI*)},
	{"canExecute", "()Z", nullptr, $PUBLIC, $virtualMethod(File, canExecute, bool)},
	{"canRead", "()Z", nullptr, $PUBLIC, $virtualMethod(File, canRead, bool)},
	{"canWrite", "()Z", nullptr, $PUBLIC, $virtualMethod(File, canWrite, bool)},
	{"compareTo", "(Ljava/io/File;)I", nullptr, $PUBLIC, $virtualMethod(File, compareTo, int32_t, File*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(File, compareTo, int32_t, Object$*)},
	{"createNewFile", "()Z", nullptr, $PUBLIC, $virtualMethod(File, createNewFile, bool), "java.io.IOException"},
	{"createTempFile", "(Ljava/lang/String;Ljava/lang/String;Ljava/io/File;)Ljava/io/File;", nullptr, $PUBLIC | $STATIC, $staticMethod(File, createTempFile, File*, $String*, $String*, File*), "java.io.IOException"},
	{"createTempFile", "(Ljava/lang/String;Ljava/lang/String;)Ljava/io/File;", nullptr, $PUBLIC | $STATIC, $staticMethod(File, createTempFile, File*, $String*, $String*), "java.io.IOException"},
	{"delete", "()Z", nullptr, $PUBLIC, $virtualMethod(File, delete$, bool)},
	{"deleteOnExit", "()V", nullptr, $PUBLIC, $virtualMethod(File, deleteOnExit, void)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(File, equals, bool, Object$*)},
	{"exists", "()Z", nullptr, $PUBLIC, $virtualMethod(File, exists, bool)},
	{"getAbsoluteFile", "()Ljava/io/File;", nullptr, $PUBLIC, $virtualMethod(File, getAbsoluteFile, File*)},
	{"getAbsolutePath", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, getAbsolutePath, $String*)},
	{"getCanonicalFile", "()Ljava/io/File;", nullptr, $PUBLIC, $virtualMethod(File, getCanonicalFile, File*), "java.io.IOException"},
	{"getCanonicalPath", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, getCanonicalPath, $String*), "java.io.IOException"},
	{"getFreeSpace", "()J", nullptr, $PUBLIC, $virtualMethod(File, getFreeSpace, int64_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, getName, $String*)},
	{"getParent", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, getParent, $String*)},
	{"getParentFile", "()Ljava/io/File;", nullptr, $PUBLIC, $virtualMethod(File, getParentFile, File*)},
	{"getPath", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, getPath, $String*)},
	{"getPrefixLength", "()I", nullptr, 0, $virtualMethod(File, getPrefixLength, int32_t)},
	{"getTotalSpace", "()J", nullptr, $PUBLIC, $virtualMethod(File, getTotalSpace, int64_t)},
	{"getUsableSpace", "()J", nullptr, $PUBLIC, $virtualMethod(File, getUsableSpace, int64_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(File, hashCode, int32_t)},
	{"isAbsolute", "()Z", nullptr, $PUBLIC, $virtualMethod(File, isAbsolute, bool)},
	{"isDirectory", "()Z", nullptr, $PUBLIC, $virtualMethod(File, isDirectory, bool)},
	{"isFile", "()Z", nullptr, $PUBLIC, $virtualMethod(File, isFile, bool)},
	{"isHidden", "()Z", nullptr, $PUBLIC, $virtualMethod(File, isHidden, bool)},
	{"isInvalid", "()Z", nullptr, $FINAL, $method(File, isInvalid, bool)},
	{"lastModified", "()J", nullptr, $PUBLIC, $virtualMethod(File, lastModified, int64_t)},
	{"length", "()J", nullptr, $PUBLIC, $virtualMethod(File, length, int64_t)},
	{"list", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, list, $StringArray*)},
	{"list", "(Ljava/io/FilenameFilter;)[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, list, $StringArray*, $FilenameFilter*)},
	{"listFiles", "()[Ljava/io/File;", nullptr, $PUBLIC, $virtualMethod(File, listFiles, $FileArray*)},
	{"listFiles", "(Ljava/io/FilenameFilter;)[Ljava/io/File;", nullptr, $PUBLIC, $virtualMethod(File, listFiles, $FileArray*, $FilenameFilter*)},
	{"listFiles", "(Ljava/io/FileFilter;)[Ljava/io/File;", nullptr, $PUBLIC, $virtualMethod(File, listFiles, $FileArray*, $FileFilter*)},
	{"listRoots", "()[Ljava/io/File;", nullptr, $PUBLIC | $STATIC, $staticMethod(File, listRoots, $FileArray*)},
	{"mkdir", "()Z", nullptr, $PUBLIC, $virtualMethod(File, mkdir, bool)},
	{"mkdirs", "()Z", nullptr, $PUBLIC, $virtualMethod(File, mkdirs, bool)},
	{"normalizedList", "()[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $method(File, normalizedList, $StringArray*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(File, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"renameTo", "(Ljava/io/File;)Z", nullptr, $PUBLIC, $virtualMethod(File, renameTo, bool, File*)},
	{"setExecutable", "(ZZ)Z", nullptr, $PUBLIC, $virtualMethod(File, setExecutable, bool, bool, bool)},
	{"setExecutable", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(File, setExecutable, bool, bool)},
	{"setLastModified", "(J)Z", nullptr, $PUBLIC, $virtualMethod(File, setLastModified, bool, int64_t)},
	{"setReadOnly", "()Z", nullptr, $PUBLIC, $virtualMethod(File, setReadOnly, bool)},
	{"setReadable", "(ZZ)Z", nullptr, $PUBLIC, $virtualMethod(File, setReadable, bool, bool, bool)},
	{"setReadable", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(File, setReadable, bool, bool)},
	{"setWritable", "(ZZ)Z", nullptr, $PUBLIC, $virtualMethod(File, setWritable, bool, bool, bool)},
	{"setWritable", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(File, setWritable, bool, bool)},
	{"slashify", "(Ljava/lang/String;Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(File, slashify, $String*, $String*, bool)},
	{"toPath", "()Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(File, toPath, $Path*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(File, toString, $String*)},
	{"toURI", "()Ljava/net/URI;", nullptr, $PUBLIC, $virtualMethod(File, toURI, $URI*)},
	{"toURL", "()Ljava/net/URL;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(File, toURL, $URL*), "java.net.MalformedURLException", nullptr, _File_MethodAnnotations_toURL61},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(File, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _File_InnerClassesInfo_[] = {
	{"java.io.File$TempDirectory", "java.io.File", "TempDirectory", $PRIVATE | $STATIC},
	{"java.io.File$PathStatus", "java.io.File", "PathStatus", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _File_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.File",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Comparable",
	_File_FieldInfo_,
	_File_MethodInfo_,
	"Ljava/lang/Object;Ljava/io/Serializable;Ljava/lang/Comparable<Ljava/io/File;>;",
	nullptr,
	_File_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.File$TempDirectory,java.io.File$PathStatus"
};

$Object* allocate$File($Class* clazz) {
	return $of($alloc(File));
}

$Object* File::clone() {
	 return this->$Serializable::clone();
}

void File::finalize() {
	this->$Serializable::finalize();
}

bool File::$assertionsDisabled = false;
$FileSystem* File::fs = nullptr;
char16_t File::separatorChar = 0;
$String* File::separator = nullptr;
char16_t File::pathSeparatorChar = 0;
$String* File::pathSeparator = nullptr;
$Unsafe* File::UNSAFE = nullptr;
int64_t File::PATH_OFFSET = 0;
int64_t File::PREFIX_LENGTH_OFFSET = 0;

bool File::isInvalid() {
	$File$PathStatus* s = this->status;
	if (s == nullptr) {
		$init($File$PathStatus);
		s = ($nc(this->path)->indexOf((int32_t)u'\0') < 0) ? $File$PathStatus::CHECKED : $File$PathStatus::INVALID;
		$set(this, status, s);
	}
	$init($File$PathStatus);
	return s == $File$PathStatus::INVALID;
}

int32_t File::getPrefixLength() {
	return this->prefixLength;
}

void File::init$($String* pathname, int32_t prefixLength) {
	$set(this, status, nullptr);
	$set(this, path, pathname);
	this->prefixLength = prefixLength;
}

void File::init$($String* child, File* parent) {
	$set(this, status, nullptr);
	if (!File::$assertionsDisabled && !($nc(parent)->path != nullptr)) {
		$throwNew($AssertionError);
	}
	if (!File::$assertionsDisabled && !(!$nc($nc(parent)->path)->isEmpty())) {
		$throwNew($AssertionError);
	}
	$set(this, path, $nc(File::fs)->resolve($nc(parent)->path, child));
	this->prefixLength = $nc(parent)->prefixLength;
}

void File::init$($String* pathname) {
	$set(this, status, nullptr);
	if (pathname == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, path, $nc(File::fs)->normalize(pathname));
	this->prefixLength = $nc(File::fs)->prefixLength(this->path);
}

void File::init$($String* parent, $String* child) {
	$useLocalCurrentObjectStackCache();
	$set(this, status, nullptr);
	if (child == nullptr) {
		$throwNew($NullPointerException);
	}
	if (parent != nullptr) {
		if (parent->isEmpty()) {
			$var($String, var$0, $nc(File::fs)->getDefaultParent());
			$set(this, path, $nc(File::fs)->resolve(var$0, $($nc(File::fs)->normalize(child))));
		} else {
			$var($String, var$1, $nc(File::fs)->normalize(parent));
			$set(this, path, $nc(File::fs)->resolve(var$1, $($nc(File::fs)->normalize(child))));
		}
	} else {
		$set(this, path, $nc(File::fs)->normalize(child));
	}
	this->prefixLength = $nc(File::fs)->prefixLength(this->path);
}

void File::init$(File* parent, $String* child) {
	$useLocalCurrentObjectStackCache();
	$set(this, status, nullptr);
	if (child == nullptr) {
		$throwNew($NullPointerException);
	}
	if (parent != nullptr) {
		if ($nc(parent->path)->isEmpty()) {
			$var($String, var$0, $nc(File::fs)->getDefaultParent());
			$set(this, path, $nc(File::fs)->resolve(var$0, $($nc(File::fs)->normalize(child))));
		} else {
			$set(this, path, $nc(File::fs)->resolve(parent->path, $($nc(File::fs)->normalize(child))));
		}
	} else {
		$set(this, path, $nc(File::fs)->normalize(child));
	}
	this->prefixLength = $nc(File::fs)->prefixLength(this->path);
}

void File::init$($URI* uri) {
	$useLocalCurrentObjectStackCache();
	$set(this, status, nullptr);
	if (!$nc(uri)->isAbsolute()) {
		$throwNew($IllegalArgumentException, "URI is not absolute"_s);
	}
	if ($nc(uri)->isOpaque()) {
		$throwNew($IllegalArgumentException, "URI is not hierarchical"_s);
	}
	$var($String, scheme, $nc(uri)->getScheme());
	if ((scheme == nullptr) || !$nc(scheme)->equalsIgnoreCase("file"_s)) {
		$throwNew($IllegalArgumentException, "URI scheme is not \"file\""_s);
	}
	if (uri->getRawAuthority() != nullptr) {
		$throwNew($IllegalArgumentException, "URI has an authority component"_s);
	}
	if (uri->getRawFragment() != nullptr) {
		$throwNew($IllegalArgumentException, "URI has a fragment component"_s);
	}
	if (uri->getRawQuery() != nullptr) {
		$throwNew($IllegalArgumentException, "URI has a query component"_s);
	}
	$var($String, p, uri->getPath());
	if ($nc(p)->isEmpty()) {
		$throwNew($IllegalArgumentException, "URI path component is empty"_s);
	}
	$assign(p, $nc(File::fs)->fromURIPath(p));
	if (File::separatorChar != u'/') {
		$assign(p, $nc(p)->replace(u'/', File::separatorChar));
	}
	$set(this, path, $nc(File::fs)->normalize(p));
	this->prefixLength = $nc(File::fs)->prefixLength(this->path);
}

$String* File::getName() {
	int32_t index = $nc(this->path)->lastIndexOf((int32_t)File::separatorChar);
	if (index < this->prefixLength) {
		return $nc(this->path)->substring(this->prefixLength);
	}
	return $nc(this->path)->substring(index + 1);
}

$String* File::getParent() {
	int32_t index = $nc(this->path)->lastIndexOf((int32_t)File::separatorChar);
	if (index < this->prefixLength) {
		if ((this->prefixLength > 0) && ($nc(this->path)->length() > this->prefixLength)) {
			return $nc(this->path)->substring(0, this->prefixLength);
		}
		return nullptr;
	}
	return $nc(this->path)->substring(0, index);
}

File* File::getParentFile() {
	$var($String, p, this->getParent());
	if (p == nullptr) {
		return nullptr;
	}
	if ($of(this)->getClass() != File::class$) {
		$assign(p, $nc(File::fs)->normalize(p));
	}
	return $new(File, p, this->prefixLength);
}

$String* File::getPath() {
	return this->path;
}

bool File::isAbsolute() {
	return $nc(File::fs)->isAbsolute(this);
}

$String* File::getAbsolutePath() {
	return $nc(File::fs)->resolve(this);
}

File* File::getAbsoluteFile() {
	$var($String, absPath, getAbsolutePath());
	if ($of(this)->getClass() != File::class$) {
		$assign(absPath, $nc(File::fs)->normalize(absPath));
	}
	return $new(File, absPath, $nc(File::fs)->prefixLength(absPath));
}

$String* File::getCanonicalPath() {
	if (isInvalid()) {
		$throwNew($IOException, "Invalid file path"_s);
	}
	return $nc(File::fs)->canonicalize($($nc(File::fs)->resolve(this)));
}

File* File::getCanonicalFile() {
	$var($String, canonPath, getCanonicalPath());
	if ($of(this)->getClass() != File::class$) {
		$assign(canonPath, $nc(File::fs)->normalize(canonPath));
	}
	return $new(File, canonPath, $nc(File::fs)->prefixLength(canonPath));
}

$String* File::slashify($String* path, bool isDirectory) {
	$init(File);
	$var($String, p, path);
	if (File::separatorChar != u'/') {
		$assign(p, $nc(p)->replace(File::separatorChar, u'/'));
	}
	if (!$nc(p)->startsWith("/"_s)) {
		$assign(p, $str({"/"_s, p}));
	}
	if (!$nc(p)->endsWith("/"_s) && isDirectory) {
		$assign(p, $str({p, "/"_s}));
	}
	return p;
}

$URL* File::toURL() {
	$useLocalCurrentObjectStackCache();
	if (isInvalid()) {
		$throwNew($MalformedURLException, "Invalid file path"_s);
	}
	$var($String, var$0, getAbsolutePath());
	return $new($URL, "file"_s, ""_s, $(slashify(var$0, isDirectory())));
}

$URI* File::toURI() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(File, f, getAbsoluteFile());
		$var($String, var$0, $nc(f)->getPath());
		$var($String, sp, slashify(var$0, f->isDirectory()));
		if ($nc(sp)->startsWith("//"_s)) {
			$assign(sp, $str({"//"_s, sp}));
		}
		return $new($URI, "file"_s, nullptr, sp, nullptr);
	} catch ($URISyntaxException& x) {
		$throwNew($Error, static_cast<$Throwable*>(x));
	}
	$shouldNotReachHere();
}

bool File::canRead() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->checkAccess(this, $FileSystem::ACCESS_READ);
}

bool File::canWrite() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->checkAccess(this, $FileSystem::ACCESS_WRITE);
}

bool File::exists() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->hasBooleanAttributes(this, $FileSystem::BA_EXISTS);
}

bool File::isDirectory() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->hasBooleanAttributes(this, $FileSystem::BA_DIRECTORY);
}

bool File::isFile() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->hasBooleanAttributes(this, $FileSystem::BA_REGULAR);
}

bool File::isHidden() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->hasBooleanAttributes(this, $FileSystem::BA_HIDDEN);
}

int64_t File::lastModified() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return 0;
	}
	return $nc(File::fs)->getLastModifiedTime(this);
}

int64_t File::length() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return 0;
	}
	return $nc(File::fs)->getLength(this);
}

bool File::createNewFile() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		$throwNew($IOException, "Invalid file path"_s);
	}
	return $nc(File::fs)->createFileExclusively(this->path);
}

bool File::delete$() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkDelete(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->delete$(this);
}

void File::deleteOnExit() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkDelete(this->path);
	}
	if (isInvalid()) {
		return;
	}
	$DeleteOnExitHook::add(this->path);
}

$StringArray* File::list() {
	return normalizedList();
}

$StringArray* File::normalizedList() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(this->path);
	}
	if (isInvalid()) {
		return nullptr;
	}
	$var($StringArray, s, $nc(File::fs)->list(this));
	if (s != nullptr && $of(this)->getClass() != File::class$) {
		$var($StringArray, normalized, $new($StringArray, s->length));
		for (int32_t i = 0; i < s->length; ++i) {
			normalized->set(i, $($nc(File::fs)->normalize(s->get(i))));
		}
		$assign(s, normalized);
	}
	return s;
}

$StringArray* File::list($FilenameFilter* filter) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, names, normalizedList());
	if ((names == nullptr) || (filter == nullptr)) {
		return names;
	}
	$var($List, v, $new($ArrayList));
	for (int32_t i = 0; i < $nc(names)->length; ++i) {
		if ($nc(filter)->accept(this, names->get(i))) {
			v->add(names->get(i));
		}
	}
	return $fcast($StringArray, v->toArray($$new($StringArray, v->size())));
}

$FileArray* File::listFiles() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, ss, normalizedList());
	if (ss == nullptr) {
		return nullptr;
	}
	int32_t n = $nc(ss)->length;
	$var($FileArray, fs, $new($FileArray, n));
	for (int32_t i = 0; i < n; ++i) {
		fs->set(i, $$new(File, ss->get(i), this));
	}
	return fs;
}

$FileArray* File::listFiles($FilenameFilter* filter) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, ss, normalizedList());
	if (ss == nullptr) {
		return nullptr;
	}
	$var($ArrayList, files, $new($ArrayList));
	{
		$var($StringArray, arr$, ss);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			if ((filter == nullptr) || $nc(filter)->accept(this, s)) {
				files->add($$new(File, s, this));
			}
		}
	}
	return $fcast($FileArray, files->toArray($$new($FileArray, files->size())));
}

$FileArray* File::listFiles($FileFilter* filter) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, ss, normalizedList());
	if (ss == nullptr) {
		return nullptr;
	}
	$var($ArrayList, files, $new($ArrayList));
	{
		$var($StringArray, arr$, ss);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			{
				$var(File, f, $new(File, s, this));
				if ((filter == nullptr) || $nc(filter)->accept(f)) {
					files->add(f);
				}
			}
		}
	}
	return $fcast($FileArray, files->toArray($$new($FileArray, files->size())));
}

bool File::mkdir() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->createDirectory(this);
}

bool File::mkdirs() {
	$useLocalCurrentObjectStackCache();
	if (exists()) {
		return false;
	}
	if (mkdir()) {
		return true;
	}
	$var(File, canonFile, nullptr);
	try {
		$assign(canonFile, getCanonicalFile());
	} catch ($IOException& e) {
		return false;
	}
	$var(File, parent, $nc(canonFile)->getParentFile());
	bool var$1 = parent != nullptr;
	if (var$1) {
		bool var$2 = parent->mkdirs();
		var$1 = (var$2 || parent->exists());
	}
	bool var$0 = var$1;
	return (var$0 && canonFile->mkdir());
}

bool File::renameTo(File* dest) {
	if (dest == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
		security->checkWrite($nc(dest)->path);
	}
	bool var$0 = this->isInvalid();
	if (var$0 || $nc(dest)->isInvalid()) {
		return false;
	}
	return $nc(File::fs)->rename(this, dest);
}

bool File::setLastModified(int64_t time) {
	if (time < 0) {
		$throwNew($IllegalArgumentException, "Negative time"_s);
	}
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->setLastModifiedTime(this, time);
}

bool File::setReadOnly() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->setReadOnly(this);
}

bool File::setWritable(bool writable, bool ownerOnly) {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->setPermission(this, $FileSystem::ACCESS_WRITE, writable, ownerOnly);
}

bool File::setWritable(bool writable) {
	return setWritable(writable, true);
}

bool File::setReadable(bool readable, bool ownerOnly) {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->setPermission(this, $FileSystem::ACCESS_READ, readable, ownerOnly);
}

bool File::setReadable(bool readable) {
	return setReadable(readable, true);
}

bool File::setExecutable(bool executable, bool ownerOnly) {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->setPermission(this, $FileSystem::ACCESS_EXECUTE, executable, ownerOnly);
}

bool File::setExecutable(bool executable) {
	return setExecutable(executable, true);
}

bool File::canExecute() {
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkExec(this->path);
	}
	if (isInvalid()) {
		return false;
	}
	return $nc(File::fs)->checkAccess(this, $FileSystem::ACCESS_EXECUTE);
}

$FileArray* File::listRoots() {
	$init(File);
	return $nc(File::fs)->listRoots();
}

int64_t File::getTotalSpace() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getFileSystemAttributes"_s));
		sm->checkRead(this->path);
	}
	if (isInvalid()) {
		return 0;
	}
	int64_t space = $nc(File::fs)->getSpace(this, $FileSystem::SPACE_TOTAL);
	return space >= (int64_t)0 ? space : $Long::MAX_VALUE;
}

int64_t File::getFreeSpace() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getFileSystemAttributes"_s));
		sm->checkRead(this->path);
	}
	if (isInvalid()) {
		return 0;
	}
	int64_t space = $nc(File::fs)->getSpace(this, $FileSystem::SPACE_FREE);
	return space >= (int64_t)0 ? space : $Long::MAX_VALUE;
}

int64_t File::getUsableSpace() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getFileSystemAttributes"_s));
		sm->checkRead(this->path);
	}
	if (isInvalid()) {
		return 0;
	}
	int64_t space = $nc(File::fs)->getSpace(this, $FileSystem::SPACE_USABLE);
	return space >= (int64_t)0 ? space : $Long::MAX_VALUE;
}

File* File::createTempFile($String* prefix, $String* suffix$renamed, File* directory) {
	$init(File);
	$useLocalCurrentObjectStackCache();
	$var($String, suffix, suffix$renamed);
	if ($nc(prefix)->length() < 3) {
		$throwNew($IllegalArgumentException, $$str({"Prefix string \""_s, prefix, "\" too short: length must be at least 3"_s}));
	}
	if (suffix == nullptr) {
		$assign(suffix, ".tmp"_s);
	}
	$var(File, tmpdir, (directory != nullptr) ? directory : $File$TempDirectory::location());
	$var($SecurityManager, sm, $System::getSecurityManager());
	$var(File, f, nullptr);
	do {
		$assign(f, $File$TempDirectory::generateFile(prefix, suffix, tmpdir));
		if (sm != nullptr) {
			try {
				sm->checkWrite($($nc(f)->getPath()));
			} catch ($SecurityException& se) {
				if (directory == nullptr) {
					$throwNew($SecurityException, "Unable to create temporary file"_s);
				}
				$throw(se);
			}
		}
	} while ($nc(File::fs)->hasBooleanAttributes(f, $FileSystem::BA_EXISTS));
	if (!$nc(File::fs)->createFileExclusively($($nc(f)->getPath()))) {
		$throwNew($IOException, "Unable to create temporary file"_s);
	}
	return f;
}

File* File::createTempFile($String* prefix, $String* suffix) {
	$init(File);
	return createTempFile(prefix, suffix, nullptr);
}

int32_t File::compareTo(File* pathname) {
	return $nc(File::fs)->compare(this, pathname);
}

bool File::equals(Object$* obj) {
	{
		$var(File, file, nullptr);
		bool var$0 = $instanceOf(File, obj);
		if (var$0) {
			$assign(file, $cast(File, obj));
			var$0 = true;
		}
		if (var$0) {
			return compareTo(file) == 0;
		}
	}
	return false;
}

int32_t File::hashCode() {
	return $nc(File::fs)->hashCode(this);
}

$String* File::toString() {
	return getPath();
}

void File::writeObject($ObjectOutputStream* s) {
	$synchronized(this) {
		$nc(s)->defaultWriteObject();
		s->writeChar(File::separatorChar);
	}
}

void File::readObject($ObjectInputStream* s) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
		$var($String, pathField, $cast($String, $nc(fields)->get("path"_s, ($Object*)nullptr)));
		char16_t sep = s->readChar();
		if (sep != File::separatorChar) {
			$assign(pathField, $nc(pathField)->replace(sep, File::separatorChar));
		}
		$var($String, path, $nc(File::fs)->normalize(pathField));
		$nc(File::UNSAFE)->putReference(this, File::PATH_OFFSET, path);
		$nc(File::UNSAFE)->putIntVolatile(this, File::PREFIX_LENGTH_OFFSET, $nc(File::fs)->prefixLength(path));
	}
}

$Path* File::toPath() {
	$useLocalCurrentObjectStackCache();
	$var($Path, result, this->filePath);
	if (result == nullptr) {
		$synchronized(this) {
			$assign(result, this->filePath);
			if (result == nullptr) {
				$assign(result, $nc($($FileSystems::getDefault()))->getPath(this->path, $$new($StringArray, 0)));
				$set(this, filePath, result);
			}
		}
	}
	return result;
}

int32_t File::compareTo(Object$* pathname) {
	return this->compareTo($cast(File, pathname));
}

void clinit$File($Class* class$) {
	$useLocalCurrentObjectStackCache();
	File::$assertionsDisabled = !File::class$->desiredAssertionStatus();
	$assignStatic(File::fs, $DefaultFileSystem::getFileSystem());
	File::separatorChar = $nc(File::fs)->getSeparator();
	$assignStatic(File::separator, $str({""_s, $$str(File::separatorChar)}));
	File::pathSeparatorChar = $nc(File::fs)->getPathSeparator();
	$assignStatic(File::pathSeparator, $str({""_s, $$str(File::pathSeparatorChar)}));
	$assignStatic(File::UNSAFE, $Unsafe::getUnsafe());
	File::PATH_OFFSET = $nc(File::UNSAFE)->objectFieldOffset(File::class$, "path"_s);
	File::PREFIX_LENGTH_OFFSET = $nc(File::UNSAFE)->objectFieldOffset(File::class$, "prefixLength"_s);
}

File::File() {
}

$Class* File::load$($String* name, bool initialize) {
	$loadClass(File, name, initialize, &_File_ClassInfo_, clinit$File, allocate$File);
	return class$;
}

$Class* File::class$ = nullptr;

	} // io
} // java