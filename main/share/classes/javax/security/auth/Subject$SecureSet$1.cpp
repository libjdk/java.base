#include <javax/security/auth/Subject$SecureSet$1.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/security/Permission.h>
#include <java/util/LinkedList.h>
#include <java/util/ListIterator.h>
#include <java/util/Set.h>
#include <javax/security/auth/AuthPermission.h>
#include <javax/security/auth/PrivateCredentialPermission.h>
#include <javax/security/auth/Subject$AuthPermissionHolder.h>
#include <javax/security/auth/Subject$SecureSet.h>
#include <javax/security/auth/Subject.h>
#include <sun/security/util/ResourcesMgr.h>
#include <jcpp.h>

#undef MODIFY_PRINCIPALS_PERMISSION
#undef MODIFY_PRIVATE_CREDENTIALS_PERMISSION
#undef MODIFY_PUBLIC_CREDENTIALS_PERMISSION
#undef PRINCIPAL_SET
#undef PRIV_CREDENTIAL_SET
#undef PUB_CREDENTIAL_SET

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $LinkedList = ::java::util::LinkedList;
using $ListIterator = ::java::util::ListIterator;
using $PrivateCredentialPermission = ::javax::security::auth::PrivateCredentialPermission;
using $Subject = ::javax::security::auth::Subject;
using $Subject$AuthPermissionHolder = ::javax::security::auth::Subject$AuthPermissionHolder;
using $Subject$SecureSet = ::javax::security::auth::Subject$SecureSet;
using $ResourcesMgr = ::sun::security::util::ResourcesMgr;

namespace javax {
	namespace security {
		namespace auth {

$FieldInfo _Subject$SecureSet$1_FieldInfo_[] = {
	{"this$0", "Ljavax/security/auth/Subject$SecureSet;", nullptr, $FINAL | $SYNTHETIC, $field(Subject$SecureSet$1, this$0)},
	{"val$list", "Ljava/util/LinkedList;", nullptr, $FINAL | $SYNTHETIC, $field(Subject$SecureSet$1, val$list)},
	{"i", "Ljava/util/ListIterator;", "Ljava/util/ListIterator<TE;>;", 0, $field(Subject$SecureSet$1, i)},
	{}
};

$MethodInfo _Subject$SecureSet$1_MethodInfo_[] = {
	{"<init>", "(Ljavax/security/auth/Subject$SecureSet;Ljava/util/LinkedList;)V", "()V", 0, $method(Subject$SecureSet$1, init$, void, $Subject$SecureSet*, $LinkedList*)},
	{"hasNext", "()Z", nullptr, $PUBLIC, $virtualMethod(Subject$SecureSet$1, hasNext, bool)},
	{"next", "()Ljava/lang/Object;", "()TE;", $PUBLIC, $virtualMethod(Subject$SecureSet$1, next, $Object*)},
	{"remove", "()V", nullptr, $PUBLIC, $virtualMethod(Subject$SecureSet$1, remove, void)},
	{}
};

$EnclosingMethodInfo _Subject$SecureSet$1_EnclosingMethodInfo_ = {
	"javax.security.auth.Subject$SecureSet",
	"iterator",
	"()Ljava/util/Iterator;"
};

$InnerClassInfo _Subject$SecureSet$1_InnerClassesInfo_[] = {
	{"javax.security.auth.Subject$SecureSet", "javax.security.auth.Subject", "SecureSet", $PRIVATE | $STATIC},
	{"javax.security.auth.Subject$SecureSet$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Subject$SecureSet$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.security.auth.Subject$SecureSet$1",
	"java.lang.Object",
	"java.util.Iterator",
	_Subject$SecureSet$1_FieldInfo_,
	_Subject$SecureSet$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/Iterator<TE;>;",
	&_Subject$SecureSet$1_EnclosingMethodInfo_,
	_Subject$SecureSet$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.security.auth.Subject"
};

$Object* allocate$Subject$SecureSet$1($Class* clazz) {
	return $of($alloc(Subject$SecureSet$1));
}

void Subject$SecureSet$1::init$($Subject$SecureSet* this$0, $LinkedList* val$list) {
	$set(this, this$0, this$0);
	$set(this, val$list, val$list);
	$set(this, i, $nc(this->val$list)->listIterator(0));
}

bool Subject$SecureSet$1::hasNext() {
	return $nc(this->i)->hasNext();
}

$Object* Subject$SecureSet$1::next() {
	$useLocalCurrentObjectStackCache();
	if (this->this$0->which != $Subject::PRIV_CREDENTIAL_SET) {
		return $of($nc(this->i)->next());
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		try {
			$var($String, var$0, $nc($of($($nc(this->val$list)->get($nc(this->i)->nextIndex()))))->getClass()->getName());
			sm->checkPermission($$new($PrivateCredentialPermission, var$0, $($nc(this->this$0->subject)->getPrincipals())));
		} catch ($SecurityException& se) {
			$nc(this->i)->next();
			$throw(se);
		}
	}
	return $of($nc(this->i)->next());
}

void Subject$SecureSet$1::remove() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->subject)->isReadOnly()) {
		$throwNew($IllegalStateException, $($ResourcesMgr::getString("Subject.is.read.only"_s)));
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		switch (this->this$0->which) {
		case $Subject::PRINCIPAL_SET:
			{
				$init($Subject$AuthPermissionHolder);
				sm->checkPermission($Subject$AuthPermissionHolder::MODIFY_PRINCIPALS_PERMISSION);
				break;
			}
		case $Subject::PUB_CREDENTIAL_SET:
			{
				$init($Subject$AuthPermissionHolder);
				sm->checkPermission($Subject$AuthPermissionHolder::MODIFY_PUBLIC_CREDENTIALS_PERMISSION);
				break;
			}
		default:
			{
				$init($Subject$AuthPermissionHolder);
				sm->checkPermission($Subject$AuthPermissionHolder::MODIFY_PRIVATE_CREDENTIALS_PERMISSION);
				break;
			}
		}
	}
	$nc(this->i)->remove();
}

Subject$SecureSet$1::Subject$SecureSet$1() {
}

$Class* Subject$SecureSet$1::load$($String* name, bool initialize) {
	$loadClass(Subject$SecureSet$1, name, initialize, &_Subject$SecureSet$1_ClassInfo_, allocate$Subject$SecureSet$1);
	return class$;
}

$Class* Subject$SecureSet$1::class$ = nullptr;

		} // auth
	} // security
} // javax