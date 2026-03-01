#include <java/security/cert/X509CRL.h>

#include <java/math/BigInteger.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Principal.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/X509CRLEntry.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/X509CRLImpl.h>
#include <jcpp.h>

#undef X509CRL

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
using $CRL = ::java::security::cert::CRL;
using $CRLException = ::java::security::cert::CRLException;
using $X509CRLEntry = ::java::security::cert::X509CRLEntry;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $X509CRLImpl = ::sun::security::x509::X509CRLImpl;

namespace java {
	namespace security {
		namespace cert {

$NamedAttribute X509CRL_Attribute_var$0[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509CRL_MethodAnnotations_getIssuerDN3[] = {
	{"Ljava/lang/Deprecated;", X509CRL_Attribute_var$0},
	{}
};

$FieldInfo _X509CRL_FieldInfo_[] = {
	{"issuerPrincipal", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $TRANSIENT, $field(X509CRL, issuerPrincipal)},
	{}
};

$MethodInfo _X509CRL_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PROTECTED, $method(X509CRL, init$, void)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(X509CRL, equals, bool, Object$*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getEncoded, $bytes*), "java.security.cert.CRLException"},
	{"getIssuerDN", "()Ljava/security/Principal;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, $virtualMethod(X509CRL, getIssuerDN, $Principal*), nullptr, nullptr, _X509CRL_MethodAnnotations_getIssuerDN3},
	{"getIssuerX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CRL, getIssuerX500Principal, $X500Principal*)},
	{"getNextUpdate", "()Ljava/util/Date;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getNextUpdate, $Date*)},
	{"getRevokedCertificate", "(Ljava/math/BigInteger;)Ljava/security/cert/X509CRLEntry;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getRevokedCertificate, $X509CRLEntry*, $BigInteger*)},
	{"getRevokedCertificate", "(Ljava/security/cert/X509Certificate;)Ljava/security/cert/X509CRLEntry;", nullptr, $PUBLIC, $virtualMethod(X509CRL, getRevokedCertificate, $X509CRLEntry*, $X509Certificate*)},
	{"getRevokedCertificates", "()Ljava/util/Set;", "()Ljava/util/Set<+Ljava/security/cert/X509CRLEntry;>;", $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getRevokedCertificates, $Set*)},
	{"getSigAlgName", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getSigAlgName, $String*)},
	{"getSigAlgOID", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getSigAlgOID, $String*)},
	{"getSigAlgParams", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getSigAlgParams, $bytes*)},
	{"getSignature", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getSignature, $bytes*)},
	{"getTBSCertList", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getTBSCertList, $bytes*), "java.security.cert.CRLException"},
	{"getThisUpdate", "()Ljava/util/Date;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getThisUpdate, $Date*)},
	{"getVersion", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, getVersion, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(X509CRL, hashCode, int32_t)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"verify", "(Ljava/security/PublicKey;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, verify, void, $PublicKey*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"verify", "(Ljava/security/PublicKey;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(X509CRL, verify, void, $PublicKey*, $String*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"verify", "(Ljava/security/PublicKey;Ljava/security/Provider;)V", nullptr, $PUBLIC, $virtualMethod(X509CRL, verify, void, $PublicKey*, $Provider*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.SignatureException"},
	{}
};

$ClassInfo _X509CRL_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.cert.X509CRL",
	"java.security.cert.CRL",
	"java.security.cert.X509Extension",
	_X509CRL_FieldInfo_,
	_X509CRL_MethodInfo_
};

$Object* allocate$X509CRL($Class* clazz) {
	return $of($alloc(X509CRL));
}

$String* X509CRL::toString() {
	 return this->$CRL::toString();
}

$Object* X509CRL::clone() {
	 return this->$CRL::clone();
}

void X509CRL::finalize() {
	this->$CRL::finalize();
}

void X509CRL::init$() {
	$CRL::init$("X.509"_s);
}

bool X509CRL::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other)) {
		return true;
	}
	if (!($instanceOf(X509CRL, other))) {
		return false;
	}
	try {
		$var($bytes, thisCRL, $X509CRLImpl::getEncodedInternal(this));
		$var($bytes, otherCRL, $X509CRLImpl::getEncodedInternal($cast(X509CRL, other)));
		return $Arrays::equals(thisCRL, otherCRL);
	} catch ($CRLException& e) {
		return false;
	}
	$shouldNotReachHere();
}

int32_t X509CRL::hashCode() {
	int32_t retval = 0;
	try {
		$var($bytes, crlData, $X509CRLImpl::getEncodedInternal(this));
		for (int32_t i = 1; i < $nc(crlData)->length; ++i) {
			retval += crlData->get(i) * i;
		}
		return retval;
	} catch ($CRLException& e) {
		return retval;
	}
	$shouldNotReachHere();
}

void X509CRL::verify($PublicKey* key, $Provider* sigProvider) {
	$useLocalCurrentObjectStackCache();
	$var($String, sigAlgName, getSigAlgName());
	$var($Signature, sig, (sigProvider == nullptr) ? $Signature::getInstance(sigAlgName) : $Signature::getInstance(sigAlgName, sigProvider));
	try {
		$var($bytes, paramBytes, getSigAlgParams());
		$SignatureUtil::initVerifyWithParam(sig, key, $($SignatureUtil::getParamSpec(sigAlgName, paramBytes)));
	} catch ($ProviderException& e) {
		$var($String, var$0, e->getMessage());
		$throwNew($CRLException, var$0, $(e->getCause()));
	} catch ($InvalidAlgorithmParameterException& e) {
		$throwNew($CRLException, static_cast<$Throwable*>(e));
	}
	$var($bytes, tbsCRL, getTBSCertList());
	$nc(sig)->update(tbsCRL, 0, $nc(tbsCRL)->length);
	if (sig->verify($(getSignature())) == false) {
		$throwNew($SignatureException, "Signature does not match."_s);
	}
}

$X500Principal* X509CRL::getIssuerX500Principal() {
	if (this->issuerPrincipal == nullptr) {
		$set(this, issuerPrincipal, $X509CRLImpl::getIssuerX500Principal(this));
	}
	return this->issuerPrincipal;
}

$X509CRLEntry* X509CRL::getRevokedCertificate($X509Certificate* certificate) {
	$useLocalCurrentObjectStackCache();
	$var($X500Principal, certIssuer, $nc(certificate)->getIssuerX500Principal());
	$var($X500Principal, crlIssuer, getIssuerX500Principal());
	if ($nc(certIssuer)->equals(crlIssuer) == false) {
		return nullptr;
	}
	return getRevokedCertificate($(certificate->getSerialNumber()));
}

X509CRL::X509CRL() {
}

$Class* X509CRL::load$($String* name, bool initialize) {
	$loadClass(X509CRL, name, initialize, &_X509CRL_ClassInfo_, allocate$X509CRL);
	return class$;
}

$Class* X509CRL::class$ = nullptr;

		} // cert
	} // security
} // java