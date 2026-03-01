#include <sun/nio/fs/UnixSecureDirectoryStream$PosixFileAttributeViewImpl.h>

#include <java/io/IOException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/ClosedDirectoryStreamException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/nio/file/attribute/GroupPrincipal.h>
#include <java/nio/file/attribute/PosixFileAttributes.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/security/Permission.h>
#include <java/util/Set.h>
#include <java/util/concurrent/locks/Lock.h>
#include <sun/nio/fs/UnixDirectoryStream.h>
#include <sun/nio/fs/UnixException.h>
#include <sun/nio/fs/UnixFileAttributes.h>
#include <sun/nio/fs/UnixFileModeAttribute.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/UnixSecureDirectoryStream$BasicFileAttributeViewImpl.h>
#include <sun/nio/fs/UnixSecureDirectoryStream.h>
#include <sun/nio/fs/UnixUserPrincipals$Group.h>
#include <sun/nio/fs/UnixUserPrincipals$User.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $ClosedDirectoryStreamException = ::java::nio::file::ClosedDirectoryStreamException;
using $Path = ::java::nio::file::Path;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $GroupPrincipal = ::java::nio::file::attribute::GroupPrincipal;
using $PosixFileAttributes = ::java::nio::file::attribute::PosixFileAttributes;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $Permission = ::java::security::Permission;
using $Set = ::java::util::Set;
using $Lock = ::java::util::concurrent::locks::Lock;
using $UnixDirectoryStream = ::sun::nio::fs::UnixDirectoryStream;
using $UnixException = ::sun::nio::fs::UnixException;
using $UnixFileAttributes = ::sun::nio::fs::UnixFileAttributes;
using $UnixFileModeAttribute = ::sun::nio::fs::UnixFileModeAttribute;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $UnixSecureDirectoryStream = ::sun::nio::fs::UnixSecureDirectoryStream;
using $UnixSecureDirectoryStream$BasicFileAttributeViewImpl = ::sun::nio::fs::UnixSecureDirectoryStream$BasicFileAttributeViewImpl;
using $UnixUserPrincipals$Group = ::sun::nio::fs::UnixUserPrincipals$Group;
using $UnixUserPrincipals$User = ::sun::nio::fs::UnixUserPrincipals$User;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixSecureDirectoryStream$PosixFileAttributeViewImpl_FieldInfo_[] = {
	{"this$0", "Lsun/nio/fs/UnixSecureDirectoryStream;", nullptr, $FINAL | $SYNTHETIC, $field(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, this$0)},
	{}
};

$MethodInfo _UnixSecureDirectoryStream$PosixFileAttributeViewImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/fs/UnixSecureDirectoryStream;Lsun/nio/fs/UnixPath;Z)V", nullptr, 0, $method(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, init$, void, $UnixSecureDirectoryStream*, $UnixPath*, bool)},
	{"checkWriteAndUserAccess", "()V", nullptr, $PRIVATE, $method(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, checkWriteAndUserAccess, void)},
	{"getOwner", "()Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PUBLIC, $virtualMethod(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, getOwner, $UserPrincipal*), "java.io.IOException"},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, name, $String*)},
	{"readAttributes", "()Ljava/nio/file/attribute/PosixFileAttributes;", nullptr, $PUBLIC, $virtualMethod(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, readAttributes, $BasicFileAttributes*), "java.io.IOException"},
	{"setGroup", "(Ljava/nio/file/attribute/GroupPrincipal;)V", nullptr, $PUBLIC, $virtualMethod(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, setGroup, void, $GroupPrincipal*), "java.io.IOException"},
	{"setOwner", "(Ljava/nio/file/attribute/UserPrincipal;)V", nullptr, $PUBLIC, $virtualMethod(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, setOwner, void, $UserPrincipal*), "java.io.IOException"},
	{"setOwners", "(II)V", nullptr, $PRIVATE, $method(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, setOwners, void, int32_t, int32_t), "java.io.IOException"},
	{"setPermissions", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;)V", $PUBLIC, $virtualMethod(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, setPermissions, void, $Set*), "java.io.IOException"},
	{"*setTimes", "(Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;)V", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _UnixSecureDirectoryStream$PosixFileAttributeViewImpl_InnerClassesInfo_[] = {
	{"sun.nio.fs.UnixSecureDirectoryStream$PosixFileAttributeViewImpl", "sun.nio.fs.UnixSecureDirectoryStream", "PosixFileAttributeViewImpl", $PRIVATE},
	{"sun.nio.fs.UnixSecureDirectoryStream$BasicFileAttributeViewImpl", "sun.nio.fs.UnixSecureDirectoryStream", "BasicFileAttributeViewImpl", $PRIVATE},
	{}
};

$ClassInfo _UnixSecureDirectoryStream$PosixFileAttributeViewImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.UnixSecureDirectoryStream$PosixFileAttributeViewImpl",
	"sun.nio.fs.UnixSecureDirectoryStream$BasicFileAttributeViewImpl",
	"java.nio.file.attribute.PosixFileAttributeView",
	_UnixSecureDirectoryStream$PosixFileAttributeViewImpl_FieldInfo_,
	_UnixSecureDirectoryStream$PosixFileAttributeViewImpl_MethodInfo_,
	nullptr,
	nullptr,
	_UnixSecureDirectoryStream$PosixFileAttributeViewImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.UnixSecureDirectoryStream"
};

$Object* allocate$UnixSecureDirectoryStream$PosixFileAttributeViewImpl($Class* clazz) {
	return $of($alloc(UnixSecureDirectoryStream$PosixFileAttributeViewImpl));
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::setTimes($FileTime* lastModifiedTime, $FileTime* lastAccessTime, $FileTime* createTime) {
	this->$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::setTimes(lastModifiedTime, lastAccessTime, createTime);
}

int32_t UnixSecureDirectoryStream$PosixFileAttributeViewImpl::hashCode() {
	 return this->$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::hashCode();
}

bool UnixSecureDirectoryStream$PosixFileAttributeViewImpl::equals(Object$* obj) {
	 return this->$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::equals(obj);
}

$Object* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::clone() {
	 return this->$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::clone();
}

$String* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::toString() {
	 return this->$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::toString();
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::finalize() {
	this->$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::finalize();
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::init$($UnixSecureDirectoryStream* this$0, $UnixPath* file, bool followLinks) {
	$set(this, this$0, this$0);
	$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::init$(this$0, file, followLinks);
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::checkWriteAndUserAccess() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$UnixSecureDirectoryStream$BasicFileAttributeViewImpl::checkWriteAccess();
		sm->checkPermission($$new($RuntimePermission, "accessUserInformation"_s));
	}
}

$String* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::name() {
	return "posix"_s;
}

$BasicFileAttributes* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::readAttributes() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		if (this->file == nullptr) {
			$nc($($nc(this->this$0->ds)->directory()))->checkRead();
		} else {
			$nc($($nc($($nc(this->this$0->ds)->directory()))->resolve(static_cast<$Path*>(this->file))))->checkRead();
		}
		sm->checkPermission($$new($RuntimePermission, "accessUserInformation"_s));
	}
	$nc($($nc(this->this$0->ds)->readLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($BasicFileAttributes, var$2, nullptr);
		bool return$1 = false;
		try {
			if (!$nc(this->this$0->ds)->isOpen()) {
				$throwNew($ClosedDirectoryStreamException);
			}
			try {
				$var($UnixFileAttributes, attrs, (this->file == nullptr) ? $UnixFileAttributes::get(this->this$0->dfd) : $UnixFileAttributes::get(this->this$0->dfd, this->file, this->followLinks));
				$assign(var$2, attrs);
				return$1 = true;
				goto $finally;
			} catch ($UnixException& x) {
				x->rethrowAsIOException(this->file);
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc($($nc(this->this$0->ds)->readLock()))->unlock();
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

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::setPermissions($Set* perms) {
	$useLocalCurrentObjectStackCache();
	checkWriteAndUserAccess();
	$nc($($nc(this->this$0->ds)->readLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (!$nc(this->this$0->ds)->isOpen()) {
				$throwNew($ClosedDirectoryStreamException);
			}
			int32_t fd = (this->file == nullptr) ? this->this$0->dfd : open();
			{
				$var($Throwable, var$1, nullptr);
				try {
					try {
						$UnixNativeDispatcher::fchmod(fd, $UnixFileModeAttribute::toUnixMode(perms));
					} catch ($UnixException& x) {
						x->rethrowAsIOException(this->file);
					}
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					if (this->file != nullptr && fd >= 0) {
						$UnixNativeDispatcher::close(fd);
					}
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc($($nc(this->this$0->ds)->readLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::setOwners(int32_t uid, int32_t gid) {
	$useLocalCurrentObjectStackCache();
	checkWriteAndUserAccess();
	$nc($($nc(this->this$0->ds)->readLock()))->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (!$nc(this->this$0->ds)->isOpen()) {
				$throwNew($ClosedDirectoryStreamException);
			}
			int32_t fd = (this->file == nullptr) ? this->this$0->dfd : open();
			{
				$var($Throwable, var$1, nullptr);
				try {
					try {
						$UnixNativeDispatcher::fchown(fd, uid, gid);
					} catch ($UnixException& x) {
						x->rethrowAsIOException(this->file);
					}
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					if (this->file != nullptr && fd >= 0) {
						$UnixNativeDispatcher::close(fd);
					}
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc($($nc(this->this$0->ds)->readLock()))->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$UserPrincipal* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::getOwner() {
	return $nc($($cast($PosixFileAttributes, readAttributes())))->owner();
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::setOwner($UserPrincipal* owner) {
	if (!($instanceOf($UnixUserPrincipals$User, owner))) {
		$throwNew($ProviderMismatchException);
	}
	if ($instanceOf($UnixUserPrincipals$Group, owner)) {
		$throwNew($IOException, "\'owner\' parameter can\'t be a group"_s);
	}
	int32_t uid = $nc(($cast($UnixUserPrincipals$User, owner)))->uid();
	setOwners(uid, -1);
}

void UnixSecureDirectoryStream$PosixFileAttributeViewImpl::setGroup($GroupPrincipal* group) {
	if (!($instanceOf($UnixUserPrincipals$Group, group))) {
		$throwNew($ProviderMismatchException);
	}
	int32_t gid = $nc(($cast($UnixUserPrincipals$Group, group)))->gid();
	setOwners(-1, gid);
}

UnixSecureDirectoryStream$PosixFileAttributeViewImpl::UnixSecureDirectoryStream$PosixFileAttributeViewImpl() {
}

$Class* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::load$($String* name, bool initialize) {
	$loadClass(UnixSecureDirectoryStream$PosixFileAttributeViewImpl, name, initialize, &_UnixSecureDirectoryStream$PosixFileAttributeViewImpl_ClassInfo_, allocate$UnixSecureDirectoryStream$PosixFileAttributeViewImpl);
	return class$;
}

$Class* UnixSecureDirectoryStream$PosixFileAttributeViewImpl::class$ = nullptr;

		} // fs
	} // nio
} // sun