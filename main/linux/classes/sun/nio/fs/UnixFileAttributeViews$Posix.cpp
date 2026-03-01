#include <sun/nio/fs/UnixFileAttributeViews$Posix.h>

#include <java/io/IOException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/nio/file/attribute/GroupPrincipal.h>
#include <java/nio/file/attribute/PosixFileAttributes.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/security/Permission.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView$AttributesBuilder.h>
#include <sun/nio/fs/AbstractBasicFileAttributeView.h>
#include <sun/nio/fs/UnixException.h>
#include <sun/nio/fs/UnixFileAttributeViews$Basic.h>
#include <sun/nio/fs/UnixFileAttributeViews.h>
#include <sun/nio/fs/UnixFileAttributes.h>
#include <sun/nio/fs/UnixFileModeAttribute.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/UnixUserPrincipals$Group.h>
#include <sun/nio/fs/UnixUserPrincipals$User.h>
#include <sun/nio/fs/Util.h>
#include <jcpp.h>

#undef GROUP_NAME
#undef OWNER_NAME
#undef PERMISSIONS_NAME

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $GroupPrincipal = ::java::nio::file::attribute::GroupPrincipal;
using $PosixFileAttributes = ::java::nio::file::attribute::PosixFileAttributes;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $Permission = ::java::security::Permission;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $AbstractBasicFileAttributeView = ::sun::nio::fs::AbstractBasicFileAttributeView;
using $AbstractBasicFileAttributeView$AttributesBuilder = ::sun::nio::fs::AbstractBasicFileAttributeView$AttributesBuilder;
using $UnixException = ::sun::nio::fs::UnixException;
using $UnixFileAttributeViews$Basic = ::sun::nio::fs::UnixFileAttributeViews$Basic;
using $UnixFileAttributes = ::sun::nio::fs::UnixFileAttributes;
using $UnixFileModeAttribute = ::sun::nio::fs::UnixFileModeAttribute;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $UnixUserPrincipals$Group = ::sun::nio::fs::UnixUserPrincipals$Group;
using $UnixUserPrincipals$User = ::sun::nio::fs::UnixUserPrincipals$User;
using $Util = ::sun::nio::fs::Util;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixFileAttributeViews$Posix_FieldInfo_[] = {
	{"PERMISSIONS_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileAttributeViews$Posix, PERMISSIONS_NAME)},
	{"OWNER_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileAttributeViews$Posix, OWNER_NAME)},
	{"GROUP_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixFileAttributeViews$Posix, GROUP_NAME)},
	{"posixAttributeNames", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(UnixFileAttributeViews$Posix, posixAttributeNames)},
	{}
};

$MethodInfo _UnixFileAttributeViews$Posix_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/nio/fs/UnixPath;Z)V", nullptr, 0, $method(UnixFileAttributeViews$Posix, init$, void, $UnixPath*, bool)},
	{"addRequestedPosixAttributes", "(Ljava/nio/file/attribute/PosixFileAttributes;Lsun/nio/fs/AbstractBasicFileAttributeView$AttributesBuilder;)V", nullptr, $FINAL, $method(UnixFileAttributeViews$Posix, addRequestedPosixAttributes, void, $PosixFileAttributes*, $AbstractBasicFileAttributeView$AttributesBuilder*)},
	{"checkReadExtended", "()V", nullptr, $FINAL, $method(UnixFileAttributeViews$Posix, checkReadExtended, void)},
	{"checkWriteExtended", "()V", nullptr, $FINAL, $method(UnixFileAttributeViews$Posix, checkWriteExtended, void)},
	{"getOwner", "()Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, getOwner, $UserPrincipal*), "java.io.IOException"},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, name, $String*)},
	{"readAttributes", "([Ljava/lang/String;)Ljava/util/Map;", "([Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, readAttributes, $Map*, $StringArray*), "java.io.IOException"},
	{"readAttributes", "()Lsun/nio/fs/UnixFileAttributes;", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, readAttributes, $BasicFileAttributes*), "java.io.IOException"},
	{"setAttribute", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, setAttribute, void, $String*, Object$*), "java.io.IOException"},
	{"setGroup", "(Ljava/nio/file/attribute/GroupPrincipal;)V", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, setGroup, void, $GroupPrincipal*), "java.io.IOException"},
	{"setMode", "(I)V", nullptr, $FINAL, $method(UnixFileAttributeViews$Posix, setMode, void, int32_t), "java.io.IOException"},
	{"setOwner", "(Ljava/nio/file/attribute/UserPrincipal;)V", nullptr, $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, setOwner, void, $UserPrincipal*), "java.io.IOException"},
	{"setOwners", "(II)V", nullptr, $FINAL, $method(UnixFileAttributeViews$Posix, setOwners, void, int32_t, int32_t), "java.io.IOException"},
	{"setPermissions", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/nio/file/attribute/PosixFilePermission;>;)V", $PUBLIC, $virtualMethod(UnixFileAttributeViews$Posix, setPermissions, void, $Set*), "java.io.IOException"},
	{"*setTimes", "(Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;Ljava/nio/file/attribute/FileTime;)V", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _UnixFileAttributeViews$Posix_InnerClassesInfo_[] = {
	{"sun.nio.fs.UnixFileAttributeViews$Posix", "sun.nio.fs.UnixFileAttributeViews", "Posix", $PRIVATE | $STATIC},
	{"sun.nio.fs.UnixFileAttributeViews$Basic", "sun.nio.fs.UnixFileAttributeViews", "Basic", $STATIC},
	{}
};

$ClassInfo _UnixFileAttributeViews$Posix_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.UnixFileAttributeViews$Posix",
	"sun.nio.fs.UnixFileAttributeViews$Basic",
	"java.nio.file.attribute.PosixFileAttributeView",
	_UnixFileAttributeViews$Posix_FieldInfo_,
	_UnixFileAttributeViews$Posix_MethodInfo_,
	nullptr,
	nullptr,
	_UnixFileAttributeViews$Posix_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.UnixFileAttributeViews"
};

$Object* allocate$UnixFileAttributeViews$Posix($Class* clazz) {
	return $of($alloc(UnixFileAttributeViews$Posix));
}

void UnixFileAttributeViews$Posix::setTimes($FileTime* lastModifiedTime, $FileTime* lastAccessTime, $FileTime* createTime) {
	this->$UnixFileAttributeViews$Basic::setTimes(lastModifiedTime, lastAccessTime, createTime);
}

int32_t UnixFileAttributeViews$Posix::hashCode() {
	 return this->$UnixFileAttributeViews$Basic::hashCode();
}

bool UnixFileAttributeViews$Posix::equals(Object$* obj) {
	 return this->$UnixFileAttributeViews$Basic::equals(obj);
}

$Object* UnixFileAttributeViews$Posix::clone() {
	 return this->$UnixFileAttributeViews$Basic::clone();
}

$String* UnixFileAttributeViews$Posix::toString() {
	 return this->$UnixFileAttributeViews$Basic::toString();
}

void UnixFileAttributeViews$Posix::finalize() {
	this->$UnixFileAttributeViews$Basic::finalize();
}

$String* UnixFileAttributeViews$Posix::PERMISSIONS_NAME = nullptr;
$String* UnixFileAttributeViews$Posix::OWNER_NAME = nullptr;
$String* UnixFileAttributeViews$Posix::GROUP_NAME = nullptr;
$Set* UnixFileAttributeViews$Posix::posixAttributeNames = nullptr;

void UnixFileAttributeViews$Posix::init$($UnixPath* file, bool followLinks) {
	$UnixFileAttributeViews$Basic::init$(file, followLinks);
}

void UnixFileAttributeViews$Posix::checkReadExtended() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$nc(this->file)->checkRead();
		sm->checkPermission($$new($RuntimePermission, "accessUserInformation"_s));
	}
}

void UnixFileAttributeViews$Posix::checkWriteExtended() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$nc(this->file)->checkWrite();
		sm->checkPermission($$new($RuntimePermission, "accessUserInformation"_s));
	}
}

$String* UnixFileAttributeViews$Posix::name() {
	return "posix"_s;
}

void UnixFileAttributeViews$Posix::setAttribute($String* attribute, Object$* value) {
	if ($nc(attribute)->equals(UnixFileAttributeViews$Posix::PERMISSIONS_NAME)) {
		setPermissions($cast($Set, value));
		return;
	}
	if ($nc(attribute)->equals(UnixFileAttributeViews$Posix::OWNER_NAME)) {
		setOwner($cast($UserPrincipal, value));
		return;
	}
	if ($nc(attribute)->equals(UnixFileAttributeViews$Posix::GROUP_NAME)) {
		setGroup($cast($GroupPrincipal, value));
		return;
	}
	$UnixFileAttributeViews$Basic::setAttribute(attribute, value);
}

void UnixFileAttributeViews$Posix::addRequestedPosixAttributes($PosixFileAttributes* attrs, $AbstractBasicFileAttributeView$AttributesBuilder* builder) {
	$useLocalCurrentObjectStackCache();
	addRequestedBasicAttributes(attrs, builder);
	if ($nc(builder)->match(UnixFileAttributeViews$Posix::PERMISSIONS_NAME)) {
		builder->add(UnixFileAttributeViews$Posix::PERMISSIONS_NAME, $($nc(attrs)->permissions()));
	}
	if ($nc(builder)->match(UnixFileAttributeViews$Posix::OWNER_NAME)) {
		builder->add(UnixFileAttributeViews$Posix::OWNER_NAME, $($nc(attrs)->owner()));
	}
	if ($nc(builder)->match(UnixFileAttributeViews$Posix::GROUP_NAME)) {
		builder->add(UnixFileAttributeViews$Posix::GROUP_NAME, $($nc(attrs)->group()));
	}
}

$Map* UnixFileAttributeViews$Posix::readAttributes($StringArray* requested) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractBasicFileAttributeView$AttributesBuilder, builder, $AbstractBasicFileAttributeView$AttributesBuilder::create(UnixFileAttributeViews$Posix::posixAttributeNames, requested));
	$var($PosixFileAttributes, attrs, $cast($PosixFileAttributes, readAttributes()));
	addRequestedPosixAttributes(attrs, builder);
	return $nc(builder)->unmodifiableMap();
}

$BasicFileAttributes* UnixFileAttributeViews$Posix::readAttributes() {
	checkReadExtended();
	try {
		return $UnixFileAttributes::get(this->file, this->followLinks);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
		return nullptr;
	}
	$shouldNotReachHere();
}

void UnixFileAttributeViews$Posix::setMode(int32_t mode) {
	checkWriteExtended();
	try {
		if (this->followLinks) {
			$UnixNativeDispatcher::chmod(this->file, mode);
		} else {
			int32_t fd = $nc(this->file)->openForAttributeAccess(false);
			{
				$var($Throwable, var$0, nullptr);
				try {
					$UnixNativeDispatcher::fchmod(fd, mode);
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					$UnixNativeDispatcher::close(fd);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
}

void UnixFileAttributeViews$Posix::setOwners(int32_t uid, int32_t gid) {
	checkWriteExtended();
	try {
		if (this->followLinks) {
			$UnixNativeDispatcher::chown(this->file, uid, gid);
		} else {
			$UnixNativeDispatcher::lchown(this->file, uid, gid);
		}
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
}

void UnixFileAttributeViews$Posix::setPermissions($Set* perms) {
	setMode($UnixFileModeAttribute::toUnixMode(perms));
}

void UnixFileAttributeViews$Posix::setOwner($UserPrincipal* owner) {
	if (owner == nullptr) {
		$throwNew($NullPointerException, "\'owner\' is null"_s);
	}
	if (!($instanceOf($UnixUserPrincipals$User, owner))) {
		$throwNew($ProviderMismatchException);
	}
	if ($instanceOf($UnixUserPrincipals$Group, owner)) {
		$throwNew($IOException, "\'owner\' parameter can\'t be a group"_s);
	}
	int32_t uid = $nc(($cast($UnixUserPrincipals$User, owner)))->uid();
	setOwners(uid, -1);
}

$UserPrincipal* UnixFileAttributeViews$Posix::getOwner() {
	return $nc($($cast($UnixFileAttributes, readAttributes())))->owner();
}

void UnixFileAttributeViews$Posix::setGroup($GroupPrincipal* group) {
	if (group == nullptr) {
		$throwNew($NullPointerException, "\'owner\' is null"_s);
	}
	if (!($instanceOf($UnixUserPrincipals$Group, group))) {
		$throwNew($ProviderMismatchException);
	}
	int32_t gid = $nc(($cast($UnixUserPrincipals$Group, group)))->gid();
	setOwners(-1, gid);
}

void clinit$UnixFileAttributeViews$Posix($Class* class$) {
	$assignStatic(UnixFileAttributeViews$Posix::PERMISSIONS_NAME, "permissions"_s);
	$assignStatic(UnixFileAttributeViews$Posix::OWNER_NAME, "owner"_s);
	$assignStatic(UnixFileAttributeViews$Posix::GROUP_NAME, "group"_s);
	$init($AbstractBasicFileAttributeView);
	$assignStatic(UnixFileAttributeViews$Posix::posixAttributeNames, $Util::newSet($AbstractBasicFileAttributeView::basicAttributeNames, $$new($StringArray, {
		UnixFileAttributeViews$Posix::PERMISSIONS_NAME,
		UnixFileAttributeViews$Posix::OWNER_NAME,
		UnixFileAttributeViews$Posix::GROUP_NAME
	})));
}

UnixFileAttributeViews$Posix::UnixFileAttributeViews$Posix() {
}

$Class* UnixFileAttributeViews$Posix::load$($String* name, bool initialize) {
	$loadClass(UnixFileAttributeViews$Posix, name, initialize, &_UnixFileAttributeViews$Posix_ClassInfo_, clinit$UnixFileAttributeViews$Posix, allocate$UnixFileAttributeViews$Posix);
	return class$;
}

$Class* UnixFileAttributeViews$Posix::class$ = nullptr;

		} // fs
	} // nio
} // sun