#include <sun/security/jca/ProviderConfig$4.h>

#include <java/security/GeneralSecurityException.h>
#include <java/security/ProviderException.h>
#include <sun/security/jca/ProviderConfig.h>
#include <sun/security/util/PropertyExpander.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $ProviderException = ::java::security::ProviderException;
using $PropertyExpander = ::sun::security::util::PropertyExpander;

namespace sun {
	namespace security {
		namespace jca {

$FieldInfo _ProviderConfig$4_FieldInfo_[] = {
	{"val$value", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(ProviderConfig$4, val$value)},
	{}
};

$MethodInfo _ProviderConfig$4_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", "()V", 0, $method(ProviderConfig$4, init$, void, $String*)},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProviderConfig$4, run, $Object*)},
	{}
};

$EnclosingMethodInfo _ProviderConfig$4_EnclosingMethodInfo_ = {
	"sun.security.jca.ProviderConfig",
	"expand",
	"(Ljava/lang/String;)Ljava/lang/String;"
};

$InnerClassInfo _ProviderConfig$4_InnerClassesInfo_[] = {
	{"sun.security.jca.ProviderConfig$4", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProviderConfig$4_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.jca.ProviderConfig$4",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_ProviderConfig$4_FieldInfo_,
	_ProviderConfig$4_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_ProviderConfig$4_EnclosingMethodInfo_,
	_ProviderConfig$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.jca.ProviderConfig"
};

$Object* allocate$ProviderConfig$4($Class* clazz) {
	return $of($alloc(ProviderConfig$4));
}

void ProviderConfig$4::init$($String* val$value) {
	$set(this, val$value, val$value);
}

$Object* ProviderConfig$4::run() {
	try {
		return $of($PropertyExpander::expand(this->val$value));
	} catch ($GeneralSecurityException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

ProviderConfig$4::ProviderConfig$4() {
}

$Class* ProviderConfig$4::load$($String* name, bool initialize) {
	$loadClass(ProviderConfig$4, name, initialize, &_ProviderConfig$4_ClassInfo_, allocate$ProviderConfig$4);
	return class$;
}

$Class* ProviderConfig$4::class$ = nullptr;

		} // jca
	} // security
} // sun