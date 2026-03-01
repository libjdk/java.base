#include <sun/nio/fs/UnixFileAttributes.h>

#include <java/lang/Math.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/nio/file/attribute/GroupPrincipal.h>
#include <java/nio/file/attribute/PosixFilePermission.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <java/util/concurrent/TimeUnit.h>
#include <sun/nio/fs/UnixConstants.h>
#include <sun/nio/fs/UnixFileAttributes$UnixAsBasicFileAttributes.h>
#include <sun/nio/fs/UnixFileKey.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/UnixUserPrincipals$Group.h>
#include <sun/nio/fs/UnixUserPrincipals$User.h>
#include <sun/nio/fs/UnixUserPrincipals.h>
#include <jcpp.h>

#undef AT_SYMLINK_NOFOLLOW
#undef GROUP_EXECUTE
#undef GROUP_READ
#undef GROUP_WRITE
#undef MICROSECONDS
#undef NANOSECONDS
#undef OTHERS_EXECUTE
#undef OTHERS_READ
#undef OTHERS_WRITE
#undef OWNER_EXECUTE
#undef OWNER_READ
#undef OWNER_WRITE
#undef SECONDS
#undef S_IAMB
#undef S_IFBLK
#undef S_IFCHR
#undef S_IFDIR
#undef S_IFIFO
#undef S_IFLNK
#undef S_IFMT
#undef S_IFREG
#undef S_IRGRP
#undef S_IROTH
#undef S_IRUSR
#undef S_IWGRP
#undef S_IWOTH
#undef S_IWUSR
#undef S_IXGRP
#undef S_IXOTH
#undef S_IXUSR

using $ArithmeticException = ::java::lang::ArithmeticException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $GroupPrincipal = ::java::nio::file::attribute::GroupPrincipal;
using $PosixFilePermission = ::java::nio::file::attribute::PosixFilePermission;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $UnixConstants = ::sun::nio::fs::UnixConstants;
using $UnixFileAttributes$UnixAsBasicFileAttributes = ::sun::nio::fs::UnixFileAttributes$UnixAsBasicFileAttributes;
using $UnixFileKey = ::sun::nio::fs::UnixFileKey;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $UnixUserPrincipals = ::sun::nio::fs::UnixUserPrincipals;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixFileAttributes_FieldInfo_[] = {
	{"st_mode", "I", nullptr, $PRIVATE, $field(UnixFileAttributes, st_mode)},
	{"st_ino", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_ino)},
	{"st_dev", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_dev)},
	{"st_rdev", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_rdev)},
	{"st_nlink", "I", nullptr, $PRIVATE, $field(UnixFileAttributes, st_nlink)},
	{"st_uid", "I", nullptr, $PRIVATE, $field(UnixFileAttributes, st_uid)},
	{"st_gid", "I", nullptr, $PRIVATE, $field(UnixFileAttributes, st_gid)},
	{"st_size", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_size)},
	{"st_atime_sec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_atime_sec)},
	{"st_atime_nsec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_atime_nsec)},
	{"st_mtime_sec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_mtime_sec)},
	{"st_mtime_nsec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_mtime_nsec)},
	{"st_ctime_sec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_ctime_sec)},
	{"st_ctime_nsec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_ctime_nsec)},
	{"st_birthtime_sec", "J", nullptr, $PRIVATE, $field(UnixFileAttributes, st_birthtime_sec)},
	{"owner", "Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PRIVATE | $VOLATILE, $field(UnixFileAttributes, owner$)},
	{"group", "Ljava/nio/file/attribute/GroupPrincipal;", nullptr, $PRIVATE | $VOLATILE, $field(UnixFileAttributes, group$)},
	{"key", "Lsun/nio/fs/UnixFileKey;", nullptr, $PRIVATE | $VOLATILE, $field(UnixFileAttributes, key)},
	{}
};

$MethodInfo _UnixFileAttributes_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(UnixFileAttributes, init$, void)},
	{"asBasicFileAttributes", "()Ljava/nio/file/attribute/BasicFileAttributes;", nullptr, 0, $virtualMethod(UnixFileAttributes, asBasicFileAttributes, $BasicFileAttributes*)},
	{"creationTime", "()Ljava/nio/file/attribute/FileTime;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, creationTime, $FileTime*)},
	{"ctime", "()Ljava/nio/file/attribute/FileTime;", nullptr, 0, $virtualMethod(UnixFileAttributes, ctime, $FileTime*)},
	{"dev", "()J", nullptr, 0, $virtualMethod(UnixFileAttributes, dev, int64_t)},
	{"fileKey", "()Lsun/nio/fs/UnixFileKey;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, fileKey, $Object*)},
	{"get", "(Lsun/nio/fs/UnixPath;Z)Lsun/nio/fs/UnixFileAttributes;", nullptr, $STATIC, $staticMethod(UnixFileAttributes, get, UnixFileAttributes*, $UnixPath*, bool), "sun.nio.fs.UnixException"},
	{"get", "(I)Lsun/nio/fs/UnixFileAttributes;", nullptr, $STATIC, $staticMethod(UnixFileAttributes, get, UnixFileAttributes*, int32_t), "sun.nio.fs.UnixException"},
	{"get", "(ILsun/nio/fs/UnixPath;Z)Lsun/nio/fs/UnixFileAttributes;", nullptr, $STATIC, $staticMethod(UnixFileAttributes, get, UnixFileAttributes*, int32_t, $UnixPath*, bool), "sun.nio.fs.UnixException"},
	{"gid", "()I", nullptr, 0, $virtualMethod(UnixFileAttributes, gid, int32_t)},
	{"group", "()Ljava/nio/file/attribute/GroupPrincipal;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, group, $GroupPrincipal*)},
	{"ino", "()J", nullptr, 0, $virtualMethod(UnixFileAttributes, ino, int64_t)},
	{"isDevice", "()Z", nullptr, 0, $virtualMethod(UnixFileAttributes, isDevice, bool)},
	{"isDirectory", "()Z", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, isDirectory, bool)},
	{"isOther", "()Z", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, isOther, bool)},
	{"isRegularFile", "()Z", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, isRegularFile, bool)},
	{"isSameFile", "(Lsun/nio/fs/UnixFileAttributes;)Z", nullptr, 0, $virtualMethod(UnixFileAttributes, isSameFile, bool, UnixFileAttributes*)},
	{"isSymbolicLink", "()Z", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, isSymbolicLink, bool)},
	{"lastAccessTime", "()Ljava/nio/file/attribute/FileTime;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, lastAccessTime, $FileTime*)},
	{"lastModifiedTime", "()Ljava/nio/file/attribute/FileTime;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, lastModifiedTime, $FileTime*)},
	{"mode", "()I", nullptr, 0, $virtualMethod(UnixFileAttributes, mode, int32_t)},
	{"nlink", "()I", nullptr, 0, $virtualMethod(UnixFileAttributes, nlink, int32_t)},
	{"owner", "()Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, owner, $UserPrincipal*)},
	{"permissions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;", $PUBLIC, $virtualMethod(UnixFileAttributes, permissions, $Set*)},
	{"rdev", "()J", nullptr, 0, $virtualMethod(UnixFileAttributes, rdev, int64_t)},
	{"size", "()J", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributes, size, int64_t)},
	{"toFileTime", "(JJ)Ljava/nio/file/attribute/FileTime;", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixFileAttributes, toFileTime, $FileTime*, int64_t, int64_t)},
	{"toUnixFileAttributes", "(Ljava/nio/file/attribute/BasicFileAttributes;)Lsun/nio/fs/UnixFileAttributes;", nullptr, $STATIC, $staticMethod(UnixFileAttributes, toUnixFileAttributes, UnixFileAttributes*, $BasicFileAttributes*)},
	{"uid", "()I", nullptr, 0, $virtualMethod(UnixFileAttributes, uid, int32_t)},
	{}
};

$InnerClassInfo _UnixFileAttributes_InnerClassesInfo_[] = {
	{"sun.nio.fs.UnixFileAttributes$UnixAsBasicFileAttributes", "sun.nio.fs.UnixFileAttributes", "UnixAsBasicFileAttributes", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _UnixFileAttributes_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.UnixFileAttributes",
	"java.lang.Object",
	"java.nio.file.attribute.PosixFileAttributes",
	_UnixFileAttributes_FieldInfo_,
	_UnixFileAttributes_MethodInfo_,
	nullptr,
	nullptr,
	_UnixFileAttributes_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.UnixFileAttributes$UnixAsBasicFileAttributes"
};

$Object* allocate$UnixFileAttributes($Class* clazz) {
	return $of($alloc(UnixFileAttributes));
}

void UnixFileAttributes::init$() {
}

UnixFileAttributes* UnixFileAttributes::get($UnixPath* path, bool followLinks) {
	$init(UnixFileAttributes);
	$var(UnixFileAttributes, attrs, $new(UnixFileAttributes));
	if (followLinks) {
		$UnixNativeDispatcher::stat(path, attrs);
	} else {
		$UnixNativeDispatcher::lstat(path, attrs);
	}
	return attrs;
}

UnixFileAttributes* UnixFileAttributes::get(int32_t fd) {
	$init(UnixFileAttributes);
	$var(UnixFileAttributes, attrs, $new(UnixFileAttributes));
	$UnixNativeDispatcher::fstat(fd, attrs);
	return attrs;
}

UnixFileAttributes* UnixFileAttributes::get(int32_t dfd, $UnixPath* path, bool followLinks) {
	$init(UnixFileAttributes);
	$useLocalCurrentObjectStackCache();
	$var(UnixFileAttributes, attrs, $new(UnixFileAttributes));
	$init($UnixConstants);
	int32_t flag = (followLinks) ? 0 : $UnixConstants::AT_SYMLINK_NOFOLLOW;
	$UnixNativeDispatcher::fstatat(dfd, $($nc(path)->asByteArray()), flag, attrs);
	return attrs;
}

bool UnixFileAttributes::isSameFile(UnixFileAttributes* attrs) {
	return ((this->st_ino == $nc(attrs)->st_ino) && (this->st_dev == attrs->st_dev));
}

int32_t UnixFileAttributes::mode() {
	return this->st_mode;
}

int64_t UnixFileAttributes::ino() {
	return this->st_ino;
}

int64_t UnixFileAttributes::dev() {
	return this->st_dev;
}

int64_t UnixFileAttributes::rdev() {
	return this->st_rdev;
}

int32_t UnixFileAttributes::nlink() {
	return this->st_nlink;
}

int32_t UnixFileAttributes::uid() {
	return this->st_uid;
}

int32_t UnixFileAttributes::gid() {
	return this->st_gid;
}

$FileTime* UnixFileAttributes::toFileTime(int64_t sec, int64_t nsec) {
	$init(UnixFileAttributes);
	if (nsec == 0) {
		$init($TimeUnit);
		return $FileTime::from(sec, $TimeUnit::SECONDS);
	} else {
		try {
			int64_t nanos = $Math::addExact(nsec, $Math::multiplyExact(sec, (int64_t)1000000000));
			$init($TimeUnit);
			return $FileTime::from(nanos, $TimeUnit::NANOSECONDS);
		} catch ($ArithmeticException& ignore) {
			int64_t micro = sec * (int64_t)1000000 + $div(nsec, (int64_t)1000);
			$init($TimeUnit);
			return $FileTime::from(micro, $TimeUnit::MICROSECONDS);
		}
	}
	$shouldNotReachHere();
}

$FileTime* UnixFileAttributes::ctime() {
	return toFileTime(this->st_ctime_sec, this->st_ctime_nsec);
}

bool UnixFileAttributes::isDevice() {
	$init($UnixConstants);
	int32_t type = (int32_t)(this->st_mode & (uint32_t)$UnixConstants::S_IFMT);
	return (type == $UnixConstants::S_IFCHR || type == $UnixConstants::S_IFBLK || type == $UnixConstants::S_IFIFO);
}

$FileTime* UnixFileAttributes::lastModifiedTime() {
	return toFileTime(this->st_mtime_sec, this->st_mtime_nsec);
}

$FileTime* UnixFileAttributes::lastAccessTime() {
	return toFileTime(this->st_atime_sec, this->st_atime_nsec);
}

$FileTime* UnixFileAttributes::creationTime() {
	if ($UnixNativeDispatcher::birthtimeSupported()) {
		$init($TimeUnit);
		return $FileTime::from(this->st_birthtime_sec, $TimeUnit::SECONDS);
	} else {
		return lastModifiedTime();
	}
}

bool UnixFileAttributes::isRegularFile() {
	$init($UnixConstants);
	return (((int32_t)(this->st_mode & (uint32_t)$UnixConstants::S_IFMT)) == $UnixConstants::S_IFREG);
}

bool UnixFileAttributes::isDirectory() {
	$init($UnixConstants);
	return (((int32_t)(this->st_mode & (uint32_t)$UnixConstants::S_IFMT)) == $UnixConstants::S_IFDIR);
}

bool UnixFileAttributes::isSymbolicLink() {
	$init($UnixConstants);
	return (((int32_t)(this->st_mode & (uint32_t)$UnixConstants::S_IFMT)) == $UnixConstants::S_IFLNK);
}

bool UnixFileAttributes::isOther() {
	$init($UnixConstants);
	int32_t type = (int32_t)(this->st_mode & (uint32_t)$UnixConstants::S_IFMT);
	return (type != $UnixConstants::S_IFREG && type != $UnixConstants::S_IFDIR && type != $UnixConstants::S_IFLNK);
}

int64_t UnixFileAttributes::size() {
	return this->st_size;
}

$Object* UnixFileAttributes::fileKey() {
	if (this->key == nullptr) {
		$synchronized(this) {
			if (this->key == nullptr) {
				$set(this, key, $new($UnixFileKey, this->st_dev, this->st_ino));
			}
		}
	}
	return $of(this->key);
}

$UserPrincipal* UnixFileAttributes::owner() {
	if (this->owner$ == nullptr) {
		$synchronized(this) {
			if (this->owner$ == nullptr) {
				$set(this, owner$, $UnixUserPrincipals::fromUid(this->st_uid));
			}
		}
	}
	return this->owner$;
}

$GroupPrincipal* UnixFileAttributes::group() {
	if (this->group$ == nullptr) {
		$synchronized(this) {
			if (this->group$ == nullptr) {
				$set(this, group$, $UnixUserPrincipals::fromGid(this->st_gid));
			}
		}
	}
	return this->group$;
}

$Set* UnixFileAttributes::permissions() {
	$init($UnixConstants);
	int32_t bits = ((int32_t)(this->st_mode & (uint32_t)$UnixConstants::S_IAMB));
	$var($HashSet, perms, $new($HashSet));
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IRUSR)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::OWNER_READ);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IWUSR)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::OWNER_WRITE);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IXUSR)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::OWNER_EXECUTE);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IRGRP)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::GROUP_READ);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IWGRP)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::GROUP_WRITE);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IXGRP)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::GROUP_EXECUTE);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IROTH)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::OTHERS_READ);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IWOTH)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::OTHERS_WRITE);
	}
	if (((int32_t)(bits & (uint32_t)$UnixConstants::S_IXOTH)) > 0) {
		$init($PosixFilePermission);
		perms->add($PosixFilePermission::OTHERS_EXECUTE);
	}
	return perms;
}

$BasicFileAttributes* UnixFileAttributes::asBasicFileAttributes() {
	return $UnixFileAttributes$UnixAsBasicFileAttributes::wrap(this);
}

UnixFileAttributes* UnixFileAttributes::toUnixFileAttributes($BasicFileAttributes* attrs) {
	$init(UnixFileAttributes);
	if ($instanceOf(UnixFileAttributes, attrs)) {
		return $cast(UnixFileAttributes, attrs);
	}
	if ($instanceOf($UnixFileAttributes$UnixAsBasicFileAttributes, attrs)) {
		return $nc(($cast($UnixFileAttributes$UnixAsBasicFileAttributes, attrs)))->unwrap();
	}
	return nullptr;
}

UnixFileAttributes::UnixFileAttributes() {
}

$Class* UnixFileAttributes::load$($String* name, bool initialize) {
	$loadClass(UnixFileAttributes, name, initialize, &_UnixFileAttributes_ClassInfo_, allocate$UnixFileAttributes);
	return class$;
}

$Class* UnixFileAttributes::class$ = nullptr;

		} // fs
	} // nio
} // sun