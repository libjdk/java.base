#include <sun/security/provider/PolicyFile$SelfPermission.h>

#include <java/security/Permission.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/PolicyFile.h>
#include <sun/security/util/LocalizedMessage.h>
#include <jcpp.h>

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Permission = ::java::security::Permission;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $LocalizedMessage = ::sun::security::util::LocalizedMessage;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicyFile$SelfPermission_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PolicyFile$SelfPermission, serialVersionUID)},
	{"type", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyFile$SelfPermission, type)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyFile$SelfPermission, name)},
	{"actions", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyFile$SelfPermission, actions)},
	{"certs", "[Ljava/security/cert/Certificate;", nullptr, $PRIVATE, $field(PolicyFile$SelfPermission, certs)},
	{}
};

$MethodInfo _PolicyFile$SelfPermission_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $method(PolicyFile$SelfPermission, init$, void, $String*, $String*, $String*, $CertificateArray*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, equals, bool, Object$*)},
	{"getActions", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, getActions, $String*)},
	{"getCerts", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, getCerts, $CertificateArray*)},
	{"getSelfActions", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, getSelfActions, $String*)},
	{"getSelfName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, getSelfName, $String*)},
	{"getSelfType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, getSelfType, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, hashCode, int32_t)},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, implies, bool, $Permission*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyFile$SelfPermission, toString, $String*)},
	{}
};

$InnerClassInfo _PolicyFile$SelfPermission_InnerClassesInfo_[] = {
	{"sun.security.provider.PolicyFile$SelfPermission", "sun.security.provider.PolicyFile", "SelfPermission", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PolicyFile$SelfPermission_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.PolicyFile$SelfPermission",
	"java.security.Permission",
	nullptr,
	_PolicyFile$SelfPermission_FieldInfo_,
	_PolicyFile$SelfPermission_MethodInfo_,
	nullptr,
	nullptr,
	_PolicyFile$SelfPermission_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.PolicyFile"
};

$Object* allocate$PolicyFile$SelfPermission($Class* clazz) {
	return $of($alloc(PolicyFile$SelfPermission));
}

void PolicyFile$SelfPermission::init$($String* type, $String* name, $String* actions, $CertificateArray* certs) {
	$useLocalCurrentObjectStackCache();
	$Permission::init$(type);
	if (type == nullptr) {
		$throwNew($NullPointerException, $($LocalizedMessage::getNonlocalized("type.can.t.be.null"_s, $$new($ObjectArray, 0))));
	}
	$set(this, type, type);
	$set(this, name, name);
	$set(this, actions, actions);
	if (certs != nullptr) {
		for (int32_t i = 0; i < certs->length; ++i) {
			if (!($instanceOf($X509Certificate, certs->get(i)))) {
				$set(this, certs, $cast($CertificateArray, certs->clone()));
				break;
			}
		}
		if (this->certs == nullptr) {
			int32_t i = 0;
			int32_t count = 0;
			while (i < certs->length) {
				++count;
				while (((i + 1) < certs->length) && $nc($($nc(($cast($X509Certificate, certs->get(i))))->getIssuerX500Principal()))->equals($($nc(($cast($X509Certificate, certs->get(i + 1))))->getSubjectX500Principal()))) {
					++i;
				}
				++i;
			}
			if (count == certs->length) {
				$set(this, certs, $cast($CertificateArray, certs->clone()));
			}
			if (this->certs == nullptr) {
				$var($List, signerCerts, $new($ArrayList));
				i = 0;
				while (i < certs->length) {
					signerCerts->add(certs->get(i));
					while (((i + 1) < certs->length) && $nc($($nc(($cast($X509Certificate, certs->get(i))))->getIssuerX500Principal()))->equals($($nc(($cast($X509Certificate, certs->get(i + 1))))->getSubjectX500Principal()))) {
						++i;
					}
					++i;
				}
				$set(this, certs, $new($CertificateArray, signerCerts->size()));
				signerCerts->toArray(this->certs);
			}
		}
	}
}

bool PolicyFile$SelfPermission::implies($Permission* p) {
	return false;
}

bool PolicyFile$SelfPermission::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	if (!($instanceOf(PolicyFile$SelfPermission, obj))) {
		return false;
	}
	$var(PolicyFile$SelfPermission, that, $cast(PolicyFile$SelfPermission, obj));
	bool var$1 = $nc(this->type)->equals($nc(that)->type);
	bool var$0 = var$1 && $nc(this->name)->equals($nc(that)->name);
	if (!(var$0 && $nc(this->actions)->equals($nc(that)->actions))) {
		return false;
	}
	if ($nc(this->certs)->length != $nc($nc(that)->certs)->length) {
		return false;
	}
	int32_t i = 0;
	int32_t j = 0;
	bool match = false;
	for (i = 0; i < $nc(this->certs)->length; ++i) {
		match = false;
		for (j = 0; j < $nc($nc(that)->certs)->length; ++j) {
			if ($nc($nc(this->certs)->get(i))->equals($nc(that->certs)->get(j))) {
				match = true;
				break;
			}
		}
		if (!match) {
			return false;
		}
	}
	for (i = 0; i < $nc($nc(that)->certs)->length; ++i) {
		match = false;
		for (j = 0; j < $nc(this->certs)->length; ++j) {
			if ($nc($nc(that->certs)->get(i))->equals($nc(this->certs)->get(j))) {
				match = true;
				break;
			}
		}
		if (!match) {
			return false;
		}
	}
	return true;
}

int32_t PolicyFile$SelfPermission::hashCode() {
	int32_t hash = $nc(this->type)->hashCode();
	if (this->name != nullptr) {
		hash ^= $nc(this->name)->hashCode();
	}
	if (this->actions != nullptr) {
		hash ^= $nc(this->actions)->hashCode();
	}
	return hash;
}

$String* PolicyFile$SelfPermission::getActions() {
	return ""_s;
}

$String* PolicyFile$SelfPermission::getSelfType() {
	return this->type;
}

$String* PolicyFile$SelfPermission::getSelfName() {
	return this->name;
}

$String* PolicyFile$SelfPermission::getSelfActions() {
	return this->actions;
}

$CertificateArray* PolicyFile$SelfPermission::getCerts() {
	return this->certs;
}

$String* PolicyFile$SelfPermission::toString() {
	return $str({"(SelfPermission "_s, this->type, " "_s, this->name, " "_s, this->actions, ")"_s});
}

PolicyFile$SelfPermission::PolicyFile$SelfPermission() {
}

$Class* PolicyFile$SelfPermission::load$($String* name, bool initialize) {
	$loadClass(PolicyFile$SelfPermission, name, initialize, &_PolicyFile$SelfPermission_ClassInfo_, allocate$PolicyFile$SelfPermission);
	return class$;
}

$Class* PolicyFile$SelfPermission::class$ = nullptr;

		} // provider
	} // security
} // sun