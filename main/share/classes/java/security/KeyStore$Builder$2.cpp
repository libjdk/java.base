#include <java/security/KeyStore$Builder$2.h>

#include <java/io/IOException.h>
#include <java/lang/IllegalStateException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/KeyStore$Builder$2$1.h>
#include <java/security/KeyStore$Builder.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/Provider.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $KeyStore = ::java::security::KeyStore;
using $KeyStore$Builder = ::java::security::KeyStore$Builder;
using $KeyStore$Builder$2$1 = ::java::security::KeyStore$Builder$2$1;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStoreException = ::java::security::KeyStoreException;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Provider = ::java::security::Provider;

namespace java {
	namespace security {

$FieldInfo _KeyStore$Builder$2_FieldInfo_[] = {
	{"val$context", "Ljava/security/AccessControlContext;", nullptr, $FINAL | $SYNTHETIC, $field(KeyStore$Builder$2, val$context)},
	{"val$protection", "Ljava/security/KeyStore$ProtectionParameter;", nullptr, $FINAL | $SYNTHETIC, $field(KeyStore$Builder$2, val$protection)},
	{"val$type", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(KeyStore$Builder$2, val$type)},
	{"val$provider", "Ljava/security/Provider;", nullptr, $FINAL | $SYNTHETIC, $field(KeyStore$Builder$2, val$provider)},
	{"getCalled", "Z", nullptr, $PRIVATE | $VOLATILE, $field(KeyStore$Builder$2, getCalled)},
	{"oldException", "Ljava/io/IOException;", nullptr, $PRIVATE, $field(KeyStore$Builder$2, oldException)},
	{"action", "Ljava/security/PrivilegedExceptionAction;", "Ljava/security/PrivilegedExceptionAction<Ljava/security/KeyStore;>;", $PRIVATE | $FINAL, $field(KeyStore$Builder$2, action)},
	{}
};

$MethodInfo _KeyStore$Builder$2_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Provider;Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;Ljava/security/AccessControlContext;)V", nullptr, 0, $method(KeyStore$Builder$2, init$, void, $Provider*, $String*, $KeyStore$ProtectionParameter*, $AccessControlContext*)},
	{"getKeyStore", "()Ljava/security/KeyStore;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(KeyStore$Builder$2, getKeyStore, $KeyStore*), "java.security.KeyStoreException"},
	{"getProtectionParameter", "(Ljava/lang/String;)Ljava/security/KeyStore$ProtectionParameter;", nullptr, $PUBLIC, $virtualMethod(KeyStore$Builder$2, getProtectionParameter, $KeyStore$ProtectionParameter*, $String*)},
	{}
};

$EnclosingMethodInfo _KeyStore$Builder$2_EnclosingMethodInfo_ = {
	"java.security.KeyStore$Builder",
	"newInstance",
	"(Ljava/lang/String;Ljava/security/Provider;Ljava/security/KeyStore$ProtectionParameter;)Ljava/security/KeyStore$Builder;"
};

$InnerClassInfo _KeyStore$Builder$2_InnerClassesInfo_[] = {
	{"java.security.KeyStore$Builder", "java.security.KeyStore", "Builder", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.security.KeyStore$Builder$2", nullptr, nullptr, 0},
	{"java.security.KeyStore$Builder$2$1", nullptr, nullptr, 0},
	{"java.security.KeyStore$ProtectionParameter", "java.security.KeyStore", "ProtectionParameter", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _KeyStore$Builder$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.security.KeyStore$Builder$2",
	"java.security.KeyStore$Builder",
	nullptr,
	_KeyStore$Builder$2_FieldInfo_,
	_KeyStore$Builder$2_MethodInfo_,
	nullptr,
	&_KeyStore$Builder$2_EnclosingMethodInfo_,
	_KeyStore$Builder$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.KeyStore"
};

$Object* allocate$KeyStore$Builder$2($Class* clazz) {
	return $of($alloc(KeyStore$Builder$2));
}

void KeyStore$Builder$2::init$($Provider* val$provider, $String* val$type, $KeyStore$ProtectionParameter* val$protection, $AccessControlContext* val$context) {
	$set(this, val$provider, val$provider);
	$set(this, val$type, val$type);
	$set(this, val$protection, val$protection);
	$set(this, val$context, val$context);
	$KeyStore$Builder::init$();
	$set(this, action, $new($KeyStore$Builder$2$1, this));
}

$KeyStore* KeyStore$Builder$2::getKeyStore() {
	$synchronized(this) {
		$beforeCallerSensitive();
		if (this->oldException != nullptr) {
			$throwNew($KeyStoreException, "Previous KeyStore instantiation failed"_s, this->oldException);
		}
		try {
			return $cast($KeyStore, $AccessController::doPrivileged(this->action, this->val$context));
		} catch ($PrivilegedActionException& e) {
			$var($Throwable, cause, e->getCause());
			$throwNew($KeyStoreException, "KeyStore instantiation failed"_s, cause);
		}
	}
	$shouldNotReachHere();
}

$KeyStore$ProtectionParameter* KeyStore$Builder$2::getProtectionParameter($String* alias) {
	if (alias == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->getCalled == false) {
		$throwNew($IllegalStateException, "getKeyStore() must be called first"_s);
	}
	return this->val$protection;
}

KeyStore$Builder$2::KeyStore$Builder$2() {
}

$Class* KeyStore$Builder$2::load$($String* name, bool initialize) {
	$loadClass(KeyStore$Builder$2, name, initialize, &_KeyStore$Builder$2_ClassInfo_, allocate$KeyStore$Builder$2);
	return class$;
}

$Class* KeyStore$Builder$2::class$ = nullptr;

	} // security
} // java