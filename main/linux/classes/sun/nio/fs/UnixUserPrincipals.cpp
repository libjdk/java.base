#include <sun/nio/fs/UnixUserPrincipals.h>

#include <java/io/IOException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/attribute/GroupPrincipal.h>
#include <java/nio/file/attribute/UserPrincipal.h>
#include <java/nio/file/attribute/UserPrincipalNotFoundException.h>
#include <java/security/Permission.h>
#include <sun/nio/fs/UnixException.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixUserPrincipals$Group.h>
#include <sun/nio/fs/UnixUserPrincipals$User.h>
#include <sun/nio/fs/Util.h>
#include <jcpp.h>

#undef SPECIAL_EVERYONE
#undef SPECIAL_GROUP
#undef SPECIAL_OWNER

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $GroupPrincipal = ::java::nio::file::attribute::GroupPrincipal;
using $UserPrincipal = ::java::nio::file::attribute::UserPrincipal;
using $UserPrincipalNotFoundException = ::java::nio::file::attribute::UserPrincipalNotFoundException;
using $Permission = ::java::security::Permission;
using $UnixException = ::sun::nio::fs::UnixException;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixUserPrincipals$Group = ::sun::nio::fs::UnixUserPrincipals$Group;
using $UnixUserPrincipals$User = ::sun::nio::fs::UnixUserPrincipals$User;
using $Util = ::sun::nio::fs::Util;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixUserPrincipals_FieldInfo_[] = {
	{"SPECIAL_OWNER", "Lsun/nio/fs/UnixUserPrincipals$User;", nullptr, $STATIC | $FINAL, $staticField(UnixUserPrincipals, SPECIAL_OWNER)},
	{"SPECIAL_GROUP", "Lsun/nio/fs/UnixUserPrincipals$User;", nullptr, $STATIC | $FINAL, $staticField(UnixUserPrincipals, SPECIAL_GROUP)},
	{"SPECIAL_EVERYONE", "Lsun/nio/fs/UnixUserPrincipals$User;", nullptr, $STATIC | $FINAL, $staticField(UnixUserPrincipals, SPECIAL_EVERYONE)},
	{}
};

$MethodInfo _UnixUserPrincipals_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnixUserPrincipals, init$, void)},
	{"createSpecial", "(Ljava/lang/String;)Lsun/nio/fs/UnixUserPrincipals$User;", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUserPrincipals, createSpecial, $UnixUserPrincipals$User*, $String*)},
	{"fromGid", "(I)Lsun/nio/fs/UnixUserPrincipals$Group;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixUserPrincipals, fromGid, $UnixUserPrincipals$Group*, int32_t)},
	{"fromUid", "(I)Lsun/nio/fs/UnixUserPrincipals$User;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixUserPrincipals, fromUid, $UnixUserPrincipals$User*, int32_t)},
	{"lookupGroup", "(Ljava/lang/String;)Ljava/nio/file/attribute/GroupPrincipal;", nullptr, $STATIC, $staticMethod(UnixUserPrincipals, lookupGroup, $GroupPrincipal*, $String*), "java.io.IOException"},
	{"lookupName", "(Ljava/lang/String;Z)I", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUserPrincipals, lookupName, int32_t, $String*, bool), "java.io.IOException"},
	{"lookupUser", "(Ljava/lang/String;)Ljava/nio/file/attribute/UserPrincipal;", nullptr, $STATIC, $staticMethod(UnixUserPrincipals, lookupUser, $UserPrincipal*, $String*), "java.io.IOException"},
	{}
};

$InnerClassInfo _UnixUserPrincipals_InnerClassesInfo_[] = {
	{"sun.nio.fs.UnixUserPrincipals$Group", "sun.nio.fs.UnixUserPrincipals", "Group", $STATIC},
	{"sun.nio.fs.UnixUserPrincipals$User", "sun.nio.fs.UnixUserPrincipals", "User", $STATIC},
	{}
};

$ClassInfo _UnixUserPrincipals_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.fs.UnixUserPrincipals",
	"java.lang.Object",
	nullptr,
	_UnixUserPrincipals_FieldInfo_,
	_UnixUserPrincipals_MethodInfo_,
	nullptr,
	nullptr,
	_UnixUserPrincipals_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.UnixUserPrincipals$Group,sun.nio.fs.UnixUserPrincipals$User"
};

$Object* allocate$UnixUserPrincipals($Class* clazz) {
	return $of($alloc(UnixUserPrincipals));
}

$UnixUserPrincipals$User* UnixUserPrincipals::SPECIAL_OWNER = nullptr;
$UnixUserPrincipals$User* UnixUserPrincipals::SPECIAL_GROUP = nullptr;
$UnixUserPrincipals$User* UnixUserPrincipals::SPECIAL_EVERYONE = nullptr;

void UnixUserPrincipals::init$() {
}

$UnixUserPrincipals$User* UnixUserPrincipals::createSpecial($String* name) {
	$init(UnixUserPrincipals);
	return $new($UnixUserPrincipals$User, -1, name);
}

$UnixUserPrincipals$User* UnixUserPrincipals::fromUid(int32_t uid) {
	$init(UnixUserPrincipals);
	$useLocalCurrentObjectStackCache();
	$var($String, name, nullptr);
	try {
		$assign(name, $Util::toString($($UnixNativeDispatcher::getpwuid(uid))));
	} catch ($UnixException& x) {
		$assign(name, $Integer::toString(uid));
	}
	return $new($UnixUserPrincipals$User, uid, name);
}

$UnixUserPrincipals$Group* UnixUserPrincipals::fromGid(int32_t gid) {
	$init(UnixUserPrincipals);
	$useLocalCurrentObjectStackCache();
	$var($String, name, nullptr);
	try {
		$assign(name, $Util::toString($($UnixNativeDispatcher::getgrgid(gid))));
	} catch ($UnixException& x) {
		$assign(name, $Integer::toString(gid));
	}
	return $new($UnixUserPrincipals$Group, gid, name);
}

int32_t UnixUserPrincipals::lookupName($String* name, bool isGroup) {
	$init(UnixUserPrincipals);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "lookupUserInformation"_s));
	}
	int32_t id = 0;
	try {
		id = (isGroup) ? $UnixNativeDispatcher::getgrnam(name) : $UnixNativeDispatcher::getpwnam(name);
	} catch ($UnixException& x) {
		$throwNew($IOException, $$str({name, ": "_s, $(x->errorString())}));
	}
	if (id == -1) {
		try {
			id = $Integer::parseInt(name);
		} catch ($NumberFormatException& ignore) {
			$throwNew($UserPrincipalNotFoundException, name);
		}
	}
	return id;
}

$UserPrincipal* UnixUserPrincipals::lookupUser($String* name) {
	$init(UnixUserPrincipals);
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->equals($($nc(UnixUserPrincipals::SPECIAL_OWNER)->getName()))) {
		return UnixUserPrincipals::SPECIAL_OWNER;
	}
	if ($nc(name)->equals($($nc(UnixUserPrincipals::SPECIAL_GROUP)->getName()))) {
		return UnixUserPrincipals::SPECIAL_GROUP;
	}
	if ($nc(name)->equals($($nc(UnixUserPrincipals::SPECIAL_EVERYONE)->getName()))) {
		return UnixUserPrincipals::SPECIAL_EVERYONE;
	}
	int32_t uid = lookupName(name, false);
	return $new($UnixUserPrincipals$User, uid, name);
}

$GroupPrincipal* UnixUserPrincipals::lookupGroup($String* group) {
	$init(UnixUserPrincipals);
	int32_t gid = lookupName(group, true);
	return $new($UnixUserPrincipals$Group, gid, group);
}

void clinit$UnixUserPrincipals($Class* class$) {
	$assignStatic(UnixUserPrincipals::SPECIAL_OWNER, UnixUserPrincipals::createSpecial("OWNER@"_s));
	$assignStatic(UnixUserPrincipals::SPECIAL_GROUP, UnixUserPrincipals::createSpecial("GROUP@"_s));
	$assignStatic(UnixUserPrincipals::SPECIAL_EVERYONE, UnixUserPrincipals::createSpecial("EVERYONE@"_s));
}

UnixUserPrincipals::UnixUserPrincipals() {
}

$Class* UnixUserPrincipals::load$($String* name, bool initialize) {
	$loadClass(UnixUserPrincipals, name, initialize, &_UnixUserPrincipals_ClassInfo_, clinit$UnixUserPrincipals, allocate$UnixUserPrincipals);
	return class$;
}

$Class* UnixUserPrincipals::class$ = nullptr;

		} // fs
	} // nio
} // sun