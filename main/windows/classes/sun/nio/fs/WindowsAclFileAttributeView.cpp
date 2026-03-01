#include <sun/nio/fs/WindowsAclFileAttributeView.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/ProviderMismatchException.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/security/Permission.h>
#include <java/util/List.h>
#include <sun/nio/fs/AbstractAclFileAttributeView.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/NativeBuffers.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsLinkSupport.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsPath.h>
#include <sun/nio/fs/WindowsSecurity$Privilege.h>
#include <sun/nio/fs/WindowsSecurity.h>
#include <sun/nio/fs/WindowsSecurityDescriptor.h>
#include <sun/nio/fs/WindowsUserPrincipals$User.h>
#include <sun/nio/fs/WindowsUserPrincipals.h>
#include <jcpp.h>

#undef SIZEOF_SECURITY_DESCRIPTOR

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $ProviderMismatchException = ::java::nio::file::ProviderMismatchException;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $Permission = ::java::security::Permission;
using $List = ::java::util::List;
using $AbstractAclFileAttributeView = ::sun::nio::fs::AbstractAclFileAttributeView;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $NativeBuffers = ::sun::nio::fs::NativeBuffers;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsLinkSupport = ::sun::nio::fs::WindowsLinkSupport;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsPath = ::sun::nio::fs::WindowsPath;
using $WindowsSecurity = ::sun::nio::fs::WindowsSecurity;
using $WindowsSecurity$Privilege = ::sun::nio::fs::WindowsSecurity$Privilege;
using $WindowsSecurityDescriptor = ::sun::nio::fs::WindowsSecurityDescriptor;
using $WindowsUserPrincipals = ::sun::nio::fs::WindowsUserPrincipals;
using $WindowsUserPrincipals$User = ::sun::nio::fs::WindowsUserPrincipals$User;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _WindowsAclFileAttributeView_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowsAclFileAttributeView, $assertionsDisabled)},
	{"SIZEOF_SECURITY_DESCRIPTOR", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsAclFileAttributeView, SIZEOF_SECURITY_DESCRIPTOR)},
	{"file", "Lsun/nio/fs/WindowsPath;", nullptr, $PRIVATE | $FINAL, $field(WindowsAclFileAttributeView, file)},
	{"followLinks", "Z", nullptr, $PRIVATE | $FINAL, $field(WindowsAclFileAttributeView, followLinks)},
	{}
};

$MethodInfo _WindowsAclFileAttributeView_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/WindowsPath;Z)V", nullptr, 0, $method(WindowsAclFileAttributeView, init$, void, $WindowsPath*, bool)},
	{"checkAccess", "(Lsun/nio/fs/WindowsPath;ZZ)V", nullptr, $PRIVATE, $method(WindowsAclFileAttributeView, checkAccess, void, $WindowsPath*, bool, bool)},
	{"getAcl", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/file/attribute/AclEntry;>;", $PUBLIC, $virtualMethod(WindowsAclFileAttributeView, getAcl, $List*), "java.io.IOException"},
	{"getFileSecurity", "(Ljava/lang/String;I)Lsun/nio/fs/NativeBuffer;", nullptr, $STATIC, $staticMethod(WindowsAclFileAttributeView, getFileSecurity, $NativeBuffer*, $String*, int32_t), "java.io.IOException"},
	{"getOwner", "()Ljava/nio/file/attribute/UserPrincipal;", nullptr, $PUBLIC, $virtualMethod(WindowsAclFileAttributeView, getOwner, $UserPrincipal*), "java.io.IOException"},
	{"setAcl", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/file/attribute/AclEntry;>;)V", $PUBLIC, $virtualMethod(WindowsAclFileAttributeView, setAcl, void, $List*), "java.io.IOException"},
	{"setOwner", "(Ljava/nio/file/attribute/UserPrincipal;)V", nullptr, $PUBLIC, $virtualMethod(WindowsAclFileAttributeView, setOwner, void, $UserPrincipal*), "java.io.IOException"},
	{}
};

$ClassInfo _WindowsAclFileAttributeView_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsAclFileAttributeView",
	"sun.nio.fs.AbstractAclFileAttributeView",
	nullptr,
	_WindowsAclFileAttributeView_FieldInfo_,
	_WindowsAclFileAttributeView_MethodInfo_
};

$Object* allocate$WindowsAclFileAttributeView($Class* clazz) {
	return $of($alloc(WindowsAclFileAttributeView));
}

bool WindowsAclFileAttributeView::$assertionsDisabled = false;

void WindowsAclFileAttributeView::init$($WindowsPath* file, bool followLinks) {
	$AbstractAclFileAttributeView::init$();
	$set(this, file, file);
	this->followLinks = followLinks;
}

void WindowsAclFileAttributeView::checkAccess($WindowsPath* file, bool checkRead, bool checkWrite) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		if (checkRead) {
			sm->checkRead($($nc(file)->getPathForPermissionCheck()));
		}
		if (checkWrite) {
			sm->checkWrite($($nc(file)->getPathForPermissionCheck()));
		}
		sm->checkPermission($$new($RuntimePermission, "accessUserInformation"_s));
	}
}

$NativeBuffer* WindowsAclFileAttributeView::getFileSecurity($String* path, int32_t request) {
	$init(WindowsAclFileAttributeView);
	int32_t size = 0;
	try {
		size = $WindowsNativeDispatcher::GetFileSecurity(path, request, 0, 0);
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(path);
	}
	if (!WindowsAclFileAttributeView::$assertionsDisabled && !(size > 0)) {
		$throwNew($AssertionError);
	}
	$var($NativeBuffer, buffer, $NativeBuffers::getNativeBuffer(size));
	try {
		for (;;) {
			int32_t newSize = $WindowsNativeDispatcher::GetFileSecurity(path, request, $nc(buffer)->address(), size);
			if (newSize <= size) {
				return buffer;
			}
			$nc(buffer)->release();
			$assign(buffer, $NativeBuffers::getNativeBuffer(newSize));
			size = newSize;
		}
	} catch ($WindowsException& x) {
		$nc(buffer)->release();
		x->rethrowAsIOException(path);
		return nullptr;
	}
	$shouldNotReachHere();
}

$UserPrincipal* WindowsAclFileAttributeView::getOwner() {
	$useLocalCurrentObjectStackCache();
	checkAccess(this->file, true, false);
	$var($String, path, $WindowsLinkSupport::getFinalPath(this->file, this->followLinks));
	$var($NativeBuffer, buffer, getFileSecurity(path, 1));
	{
		$var($Throwable, var$0, nullptr);
		$var($UserPrincipal, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				int64_t sidAddress = $WindowsNativeDispatcher::GetSecurityDescriptorOwner($nc(buffer)->address());
				if (sidAddress == (int64_t)0) {
					$throwNew($IOException, "no owner"_s);
				}
				$assign(var$2, $WindowsUserPrincipals::fromSid(sidAddress));
				return$1 = true;
				goto $finally;
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(this->file);
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(buffer)->release();
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

$List* WindowsAclFileAttributeView::getAcl() {
	$useLocalCurrentObjectStackCache();
	checkAccess(this->file, true, false);
	$var($String, path, $WindowsLinkSupport::getFinalPath(this->file, this->followLinks));
	$var($NativeBuffer, buffer, getFileSecurity(path, 4));
	{
		$var($Throwable, var$0, nullptr);
		$var($List, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $WindowsSecurityDescriptor::getAcl($nc(buffer)->address()));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(buffer)->release();
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

void WindowsAclFileAttributeView::setOwner($UserPrincipal* obj) {
	$useLocalCurrentObjectStackCache();
	if (obj == nullptr) {
		$throwNew($NullPointerException, "\'owner\' is null"_s);
	}
	if (!($instanceOf($WindowsUserPrincipals$User, obj))) {
		$throwNew($ProviderMismatchException);
	}
	$var($WindowsUserPrincipals$User, owner, $cast($WindowsUserPrincipals$User, obj));
	checkAccess(this->file, false, true);
	$var($String, path, $WindowsLinkSupport::getFinalPath(this->file, this->followLinks));
	int64_t pOwner = 0;
	try {
		pOwner = $WindowsNativeDispatcher::ConvertStringSidToSid($($nc(owner)->sidString()));
	} catch ($WindowsException& x) {
		$var($String, var$0, $$str({"Failed to get SID for "_s, $($nc(owner)->getName()), ": "_s}));
		$throwNew($IOException, $$concat(var$0, $(x->errorString())));
	}
	{
		$var($Throwable, var$1, nullptr);
		try {
			$var($NativeBuffer, buffer, $NativeBuffers::getNativeBuffer(WindowsAclFileAttributeView::SIZEOF_SECURITY_DESCRIPTOR));
			{
				$var($Throwable, var$2, nullptr);
				try {
					try {
						$WindowsNativeDispatcher::InitializeSecurityDescriptor($nc(buffer)->address());
						$WindowsNativeDispatcher::SetSecurityDescriptorOwner($nc(buffer)->address(), pOwner);
						$var($WindowsSecurity$Privilege, priv, $WindowsSecurity::enablePrivilege("SeRestorePrivilege"_s));
						{
							$var($Throwable, var$3, nullptr);
							try {
								$WindowsNativeDispatcher::SetFileSecurity(path, 1, $nc(buffer)->address());
							} catch ($Throwable& var$4) {
								$assign(var$3, var$4);
							} /*finally*/ {
								$nc(priv)->drop();
							}
							if (var$3 != nullptr) {
								$throw(var$3);
							}
						}
					} catch ($WindowsException& x) {
						x->rethrowAsIOException(this->file);
					}
				} catch ($Throwable& var$5) {
					$assign(var$2, var$5);
				} /*finally*/ {
					$nc(buffer)->release();
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		} catch ($Throwable& var$6) {
			$assign(var$1, var$6);
		} /*finally*/ {
			$WindowsNativeDispatcher::LocalFree(pOwner);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
}

void WindowsAclFileAttributeView::setAcl($List* acl) {
	$useLocalCurrentObjectStackCache();
	checkAccess(this->file, false, true);
	$var($String, path, $WindowsLinkSupport::getFinalPath(this->file, this->followLinks));
	$var($WindowsSecurityDescriptor, sd, $WindowsSecurityDescriptor::create(acl));
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$WindowsNativeDispatcher::SetFileSecurity(path, 4, $nc(sd)->address());
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(this->file);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(sd)->release();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void clinit$WindowsAclFileAttributeView($Class* class$) {
	WindowsAclFileAttributeView::$assertionsDisabled = !WindowsAclFileAttributeView::class$->desiredAssertionStatus();
}

WindowsAclFileAttributeView::WindowsAclFileAttributeView() {
}

$Class* WindowsAclFileAttributeView::load$($String* name, bool initialize) {
	$loadClass(WindowsAclFileAttributeView, name, initialize, &_WindowsAclFileAttributeView_ClassInfo_, clinit$WindowsAclFileAttributeView, allocate$WindowsAclFileAttributeView);
	return class$;
}

$Class* WindowsAclFileAttributeView::class$ = nullptr;

		} // fs
	} // nio
} // sun