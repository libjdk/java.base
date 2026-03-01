#include <java/security/cert/X509Certificate.h>

#include <java/math/BigInteger.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Principal.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/List.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $BigInteger = ::java::math::BigInteger;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Principal = ::java::security::Principal;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $List = ::java::util::List;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace java {
	namespace security {
		namespace cert {

$NamedAttribute X509Certificate_Attribute_var$0[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509Certificate_MethodAnnotations_getIssuerDN6[] = {
	{"Ljava/lang/Deprecated;", X509Certificate_Attribute_var$0},
	{}
};

$NamedAttribute X509Certificate_Attribute_var$1[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509Certificate_MethodAnnotations_getSubjectDN18[] = {
	{"Ljava/lang/Deprecated;", X509Certificate_Attribute_var$1},
	{}
};

$FieldInfo _X509Certificate_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509Certificate, serialVersionUID)},
	{"subjectX500Principal", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $TRANSIENT, $field(X509Certificate, subjectX500Principal)},
	{"issuerX500Principal", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $TRANSIENT, $field(X509Certificate, issuerX500Principal)},
	{}
};

$MethodInfo _X509Certificate_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PROTECTED, $method(X509Certificate, init$, void)},
	{"checkValidity", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, checkValidity, void), "java.security.cert.CertificateExpiredException,java.security.cert.CertificateNotYetValidException"},
	{"checkValidity", "(Ljava/util/Date;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, checkValidity, void, $Date*), "java.security.cert.CertificateExpiredException,java.security.cert.CertificateNotYetValidException"},
	{"getBasicConstraints", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getBasicConstraints, int32_t)},
	{"getExtendedKeyUsage", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509Certificate, getExtendedKeyUsage, $List*), "java.security.cert.CertificateParsingException"},
	{"getIssuerAlternativeNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC, $virtualMethod(X509Certificate, getIssuerAlternativeNames, $Collection*), "java.security.cert.CertificateParsingException"},
	{"getIssuerDN", "()Ljava/security/Principal;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, $virtualMethod(X509Certificate, getIssuerDN, $Principal*), nullptr, nullptr, _X509Certificate_MethodAnnotations_getIssuerDN6},
	{"getIssuerUniqueID", "()[Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getIssuerUniqueID, $booleans*)},
	{"getIssuerX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509Certificate, getIssuerX500Principal, $X500Principal*)},
	{"getKeyUsage", "()[Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getKeyUsage, $booleans*)},
	{"getNotAfter", "()Ljava/util/Date;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getNotAfter, $Date*)},
	{"getNotBefore", "()Ljava/util/Date;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getNotBefore, $Date*)},
	{"getSerialNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getSerialNumber, $BigInteger*)},
	{"getSigAlgName", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getSigAlgName, $String*)},
	{"getSigAlgOID", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getSigAlgOID, $String*)},
	{"getSigAlgParams", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getSigAlgParams, $bytes*)},
	{"getSignature", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getSignature, $bytes*)},
	{"getSubjectAlternativeNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC, $virtualMethod(X509Certificate, getSubjectAlternativeNames, $Collection*), "java.security.cert.CertificateParsingException"},
	{"getSubjectDN", "()Ljava/security/Principal;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, $virtualMethod(X509Certificate, getSubjectDN, $Principal*), nullptr, nullptr, _X509Certificate_MethodAnnotations_getSubjectDN18},
	{"getSubjectUniqueID", "()[Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getSubjectUniqueID, $booleans*)},
	{"getSubjectX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509Certificate, getSubjectX500Principal, $X500Principal*)},
	{"getTBSCertificate", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getTBSCertificate, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getVersion", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509Certificate, getVersion, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"verify", "(Ljava/security/PublicKey;Ljava/security/Provider;)V", nullptr, $PUBLIC, $virtualMethod(X509Certificate, verify, void, $PublicKey*, $Provider*), "java.security.cert.CertificateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.SignatureException"},
	{}
};

$ClassInfo _X509Certificate_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.cert.X509Certificate",
	"java.security.cert.Certificate",
	"java.security.cert.X509Extension",
	_X509Certificate_FieldInfo_,
	_X509Certificate_MethodInfo_
};

$Object* allocate$X509Certificate($Class* clazz) {
	return $of($alloc(X509Certificate));
}

bool X509Certificate::equals(Object$* other) {
	 return this->$Certificate::equals(other);
}

int32_t X509Certificate::hashCode() {
	 return this->$Certificate::hashCode();
}

$String* X509Certificate::toString() {
	 return this->$Certificate::toString();
}

$Object* X509Certificate::clone() {
	 return this->$Certificate::clone();
}

void X509Certificate::finalize() {
	this->$Certificate::finalize();
}

void X509Certificate::init$() {
	$Certificate::init$("X.509"_s);
}

$X500Principal* X509Certificate::getIssuerX500Principal() {
	if (this->issuerX500Principal == nullptr) {
		$set(this, issuerX500Principal, $X509CertImpl::getIssuerX500Principal(this));
	}
	return this->issuerX500Principal;
}

$X500Principal* X509Certificate::getSubjectX500Principal() {
	if (this->subjectX500Principal == nullptr) {
		$set(this, subjectX500Principal, $X509CertImpl::getSubjectX500Principal(this));
	}
	return this->subjectX500Principal;
}

$List* X509Certificate::getExtendedKeyUsage() {
	return $X509CertImpl::getExtendedKeyUsage(this);
}

$Collection* X509Certificate::getSubjectAlternativeNames() {
	return $X509CertImpl::getSubjectAlternativeNames(this);
}

$Collection* X509Certificate::getIssuerAlternativeNames() {
	return $X509CertImpl::getIssuerAlternativeNames(this);
}

void X509Certificate::verify($PublicKey* key, $Provider* sigProvider) {
	$useLocalCurrentObjectStackCache();
	$var($String, sigName, getSigAlgName());
	$var($Signature, sig, (sigProvider == nullptr) ? $Signature::getInstance(sigName) : $Signature::getInstance(sigName, sigProvider));
	try {
		$SignatureUtil::initVerifyWithParam(sig, key, $($SignatureUtil::getParamSpec(sigName, $(getSigAlgParams()))));
	} catch ($ProviderException& e) {
		$var($String, var$0, e->getMessage());
		$throwNew($CertificateException, var$0, $(e->getCause()));
	} catch ($InvalidAlgorithmParameterException& e) {
		$throwNew($CertificateException, static_cast<$Throwable*>(e));
	}
	$var($bytes, tbsCert, getTBSCertificate());
	$nc(sig)->update(tbsCert, 0, $nc(tbsCert)->length);
	if (sig->verify($(getSignature())) == false) {
		$throwNew($SignatureException, "Signature does not match."_s);
	}
}

X509Certificate::X509Certificate() {
}

$Class* X509Certificate::load$($String* name, bool initialize) {
	$loadClass(X509Certificate, name, initialize, &_X509Certificate_ClassInfo_, allocate$X509Certificate);
	return class$;
}

$Class* X509Certificate::class$ = nullptr;

		} // cert
	} // security
} // java