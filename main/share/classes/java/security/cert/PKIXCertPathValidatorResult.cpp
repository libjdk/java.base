#include <java/security/cert/PKIXCertPathValidatorResult.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPathValidatorResult.h>
#include <java/security/cert/PolicyNode.h>
#include <java/security/cert/TrustAnchor.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $PublicKey = ::java::security::PublicKey;
using $CertPathValidatorResult = ::java::security::cert::CertPathValidatorResult;
using $PolicyNode = ::java::security::cert::PolicyNode;
using $TrustAnchor = ::java::security::cert::TrustAnchor;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _PKIXCertPathValidatorResult_FieldInfo_[] = {
	{"trustAnchor", "Ljava/security/cert/TrustAnchor;", nullptr, $PRIVATE, $field(PKIXCertPathValidatorResult, trustAnchor)},
	{"policyTree", "Ljava/security/cert/PolicyNode;", nullptr, $PRIVATE, $field(PKIXCertPathValidatorResult, policyTree)},
	{"subjectPublicKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(PKIXCertPathValidatorResult, subjectPublicKey)},
	{}
};

$MethodInfo _PKIXCertPathValidatorResult_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/TrustAnchor;Ljava/security/cert/PolicyNode;Ljava/security/PublicKey;)V", nullptr, $PUBLIC, $method(PKIXCertPathValidatorResult, init$, void, $TrustAnchor*, $PolicyNode*, $PublicKey*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidatorResult, clone, $Object*)},
	{"getPolicyTree", "()Ljava/security/cert/PolicyNode;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidatorResult, getPolicyTree, $PolicyNode*)},
	{"getPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidatorResult, getPublicKey, $PublicKey*)},
	{"getTrustAnchor", "()Ljava/security/cert/TrustAnchor;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidatorResult, getTrustAnchor, $TrustAnchor*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathValidatorResult, toString, $String*)},
	{}
};

$ClassInfo _PKIXCertPathValidatorResult_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.PKIXCertPathValidatorResult",
	"java.lang.Object",
	"java.security.cert.CertPathValidatorResult",
	_PKIXCertPathValidatorResult_FieldInfo_,
	_PKIXCertPathValidatorResult_MethodInfo_
};

$Object* allocate$PKIXCertPathValidatorResult($Class* clazz) {
	return $of($alloc(PKIXCertPathValidatorResult));
}

void PKIXCertPathValidatorResult::init$($TrustAnchor* trustAnchor, $PolicyNode* policyTree, $PublicKey* subjectPublicKey) {
	if (subjectPublicKey == nullptr) {
		$throwNew($NullPointerException, "subjectPublicKey must be non-null"_s);
	}
	if (trustAnchor == nullptr) {
		$throwNew($NullPointerException, "trustAnchor must be non-null"_s);
	}
	$set(this, trustAnchor, trustAnchor);
	$set(this, policyTree, policyTree);
	$set(this, subjectPublicKey, subjectPublicKey);
}

$TrustAnchor* PKIXCertPathValidatorResult::getTrustAnchor() {
	return this->trustAnchor;
}

$PolicyNode* PKIXCertPathValidatorResult::getPolicyTree() {
	return this->policyTree;
}

$PublicKey* PKIXCertPathValidatorResult::getPublicKey() {
	return this->subjectPublicKey;
}

$Object* PKIXCertPathValidatorResult::clone() {
	try {
		return $of($CertPathValidatorResult::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

$String* PKIXCertPathValidatorResult::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("PKIXCertPathValidatorResult: [\n"_s);
	sb->append($$str({"  Trust Anchor: "_s, $($nc(this->trustAnchor)->toString()), "\n"_s}));
	sb->append($$str({"  Policy Tree: "_s, $($String::valueOf($of(this->policyTree))), "\n"_s}));
	sb->append($$str({"  Subject Public Key: "_s, this->subjectPublicKey, "\n"_s}));
	sb->append("]"_s);
	return sb->toString();
}

PKIXCertPathValidatorResult::PKIXCertPathValidatorResult() {
}

$Class* PKIXCertPathValidatorResult::load$($String* name, bool initialize) {
	$loadClass(PKIXCertPathValidatorResult, name, initialize, &_PKIXCertPathValidatorResult_ClassInfo_, allocate$PKIXCertPathValidatorResult);
	return class$;
}

$Class* PKIXCertPathValidatorResult::class$ = nullptr;

		} // cert
	} // security
} // java