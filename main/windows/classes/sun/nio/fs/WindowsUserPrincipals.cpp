#include <sun/nio/fs/WindowsUserPrincipals.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/nio/file/attribute/UserPrincipalNotFoundException.h>
#include <java/security/Permission.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/NativeBuffers.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsNativeDispatcher$Account.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsUserPrincipals$Group.h>
#include <sun/nio/fs/WindowsUserPrincipals$User.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $UserPrincipalNotFoundException = ::java::nio::file::attribute::UserPrincipalNotFoundException;
using $Permission = ::java::security::Permission;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $NativeBuffers = ::sun::nio::fs::NativeBuffers;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsNativeDispatcher$Account = ::sun::nio::fs::WindowsNativeDispatcher$Account;
using $WindowsUserPrincipals$Group = ::sun::nio::fs::WindowsUserPrincipals$Group;
using $WindowsUserPrincipals$User = ::sun::nio::fs::WindowsUserPrincipals$User;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _WindowsUserPrincipals_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowsUserPrincipals, $assertionsDisabled)},
	{}
};

$MethodInfo _WindowsUserPrincipals_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(WindowsUserPrincipals, init$, void)},
	{"fromSid", "(J)Ljava/nio/file/attribute/UserPrincipal;", nullptr, $STATIC, $staticMethod(WindowsUserPrincipals, fromSid, $UserPrincipal*, int64_t), "java.io.IOException"},
	{"lookup", "(Ljava/lang/String;)Ljava/nio/file/attribute/UserPrincipal;", nullptr, $STATIC, $staticMethod(WindowsUserPrincipals, lookup, $UserPrincipal*, $String*), "java.io.IOException"},
	{}
};

$InnerClassInfo _WindowsUserPrincipals_InnerClassesInfo_[] = {
	{"sun.nio.fs.WindowsUserPrincipals$Group", "sun.nio.fs.WindowsUserPrincipals", "Group", $STATIC},
	{"sun.nio.fs.WindowsUserPrincipals$User", "sun.nio.fs.WindowsUserPrincipals", "User", $STATIC},
	{}
};

$ClassInfo _WindowsUserPrincipals_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsUserPrincipals",
	"java.lang.Object",
	nullptr,
	_WindowsUserPrincipals_FieldInfo_,
	_WindowsUserPrincipals_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsUserPrincipals_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.WindowsUserPrincipals$Group,sun.nio.fs.WindowsUserPrincipals$User"
};

$Object* allocate$WindowsUserPrincipals($Class* clazz) {
	return $of($alloc(WindowsUserPrincipals));
}

bool WindowsUserPrincipals::$assertionsDisabled = false;

void WindowsUserPrincipals::init$() {
}

$UserPrincipal* WindowsUserPrincipals::fromSid(int64_t sidAddress) {
	$init(WindowsUserPrincipals);
	$useLocalCurrentObjectStackCache();
	$var($String, sidString, nullptr);
	try {
		$assign(sidString, $WindowsNativeDispatcher::ConvertSidToStringSid(sidAddress));
		if (sidString == nullptr) {
			$throwNew($AssertionError);
		}
	} catch ($WindowsException& x) {
		$throwNew($IOException, $$str({"Unable to convert SID to String: "_s, $(x->errorString())}));
	}
	$var($WindowsNativeDispatcher$Account, account, nullptr);
	$var($String, name, nullptr);
	try {
		$assign(account, $WindowsNativeDispatcher::LookupAccountSid(sidAddress));
		$var($String, var$0, $$str({$($nc(account)->domain()), "\\"_s}));
		$assign(name, $concat(var$0, $(account->name())));
	} catch ($WindowsException& x) {
		$assign(name, sidString);
	}
	int32_t sidType = (account == nullptr) ? 8 : $nc(account)->use();
	if ((sidType == 2) || (sidType == 5) || (sidType == 4)) {
		return static_cast<$UserPrincipal*>(static_cast<$WindowsUserPrincipals$User*>($new($WindowsUserPrincipals$Group, sidString, sidType, name)));
	} else {
		return $new($WindowsUserPrincipals$User, sidString, sidType, name);
	}
}

$UserPrincipal* WindowsUserPrincipals::lookup($String* name) {
	$init(WindowsUserPrincipals);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "lookupUserInformation"_s));
	}
	int32_t size = 0;
	try {
		size = $WindowsNativeDispatcher::LookupAccountName(name, 0, 0);
	} catch ($WindowsException& x) {
		if (x->lastError() == 1332) {
			$throwNew($UserPrincipalNotFoundException, name);
		}
		$throwNew($IOException, $$str({name, ": "_s, $(x->errorString())}));
	}
	if (!WindowsUserPrincipals::$assertionsDisabled && !(size > 0)) {
		$throwNew($AssertionError);
	}
	$var($NativeBuffer, sidBuffer, $NativeBuffers::getNativeBuffer(size));
	{
		$var($Throwable, var$0, nullptr);
		$var($UserPrincipal, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				int32_t newSize = $WindowsNativeDispatcher::LookupAccountName(name, $nc(sidBuffer)->address(), size);
				if (newSize != size) {
					$throwNew($AssertionError, $of("SID change during lookup"_s));
				}
				$assign(var$2, fromSid($nc(sidBuffer)->address()));
				return$1 = true;
				goto $finally;
			} catch ($WindowsException& x) {
				$throwNew($IOException, $$str({name, ": "_s, $(x->errorString())}));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(sidBuffer)->release();
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

void clinit$WindowsUserPrincipals($Class* class$) {
	WindowsUserPrincipals::$assertionsDisabled = !WindowsUserPrincipals::class$->desiredAssertionStatus();
}

WindowsUserPrincipals::WindowsUserPrincipals() {
}

$Class* WindowsUserPrincipals::load$($String* name, bool initialize) {
	$loadClass(WindowsUserPrincipals, name, initialize, &_WindowsUserPrincipals_ClassInfo_, clinit$WindowsUserPrincipals, allocate$WindowsUserPrincipals);
	return class$;
}

$Class* WindowsUserPrincipals::class$ = nullptr;

		} // fs
	} // nio
} // sun