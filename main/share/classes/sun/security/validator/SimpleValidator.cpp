#include <sun/security/validator/SimpleValidator.h>

#include <java/io/IOException.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Principal.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/provider/certpath/UntrustedChecker.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/validator/Validator.h>
#include <sun/security/validator/ValidatorException.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/KeyIdentifier.h>
#include <sun/security/x509/NetscapeCertTypeExtension.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef CHAIN0
#undef NSCT_CODE_SIGNING_CA
#undef NSCT_SSL_CA
#undef OBJECT_SIGNING_CA
#undef OBJID_NETSCAPE_CERT_TYPE
#undef OID_BASIC_CONSTRAINTS
#undef OID_EKU_ANY_USAGE
#undef OID_EXTENDED_KEY_USAGE
#undef OID_KEY_USAGE
#undef OID_NETSCAPE_CERT_TYPE
#undef SSL_CA
#undef TYPE_SIMPLE
#undef T_ALGORITHM_DISABLED
#undef T_CA_EXTENSIONS
#undef T_NAME_CHAINING
#undef T_NO_TRUST_ANCHOR
#undef T_SIGNATURE_ERROR
#undef T_UNTRUSTED_CERT
#undef VAR_CODE_SIGNING
#undef VAR_GENERIC
#undef VAR_JCE_SIGNING
#undef VAR_TLS_CLIENT
#undef VAR_TLS_SERVER

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Principal = ::java::security::Principal;
using $PublicKey = ::java::security::PublicKey;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $UntrustedChecker = ::sun::security::provider::certpath::UntrustedChecker;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $Validator = ::sun::security::validator::Validator;
using $ValidatorException = ::sun::security::validator::ValidatorException;
using $KeyIdentifier = ::sun::security::x509::KeyIdentifier;
using $NetscapeCertTypeExtension = ::sun::security::x509::NetscapeCertTypeExtension;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace validator {

$FieldInfo _SimpleValidator_FieldInfo_[] = {
	{"OID_BASIC_CONSTRAINTS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SimpleValidator, OID_BASIC_CONSTRAINTS)},
	{"OID_NETSCAPE_CERT_TYPE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SimpleValidator, OID_NETSCAPE_CERT_TYPE)},
	{"OID_KEY_USAGE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SimpleValidator, OID_KEY_USAGE)},
	{"OID_EXTENDED_KEY_USAGE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SimpleValidator, OID_EXTENDED_KEY_USAGE)},
	{"OID_EKU_ANY_USAGE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SimpleValidator, OID_EKU_ANY_USAGE)},
	{"OBJID_NETSCAPE_CERT_TYPE", "Lsun/security/util/ObjectIdentifier;", nullptr, $STATIC | $FINAL, $staticField(SimpleValidator, OBJID_NETSCAPE_CERT_TYPE)},
	{"NSCT_SSL_CA", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleValidator, NSCT_SSL_CA)},
	{"NSCT_CODE_SIGNING_CA", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleValidator, NSCT_CODE_SIGNING_CA)},
	{"trustedX500Principals", "Ljava/util/Map;", "Ljava/util/Map<Ljavax/security/auth/x500/X500Principal;Ljava/util/List<Ljava/security/cert/X509Certificate;>;>;", $PRIVATE | $FINAL, $field(SimpleValidator, trustedX500Principals)},
	{"trustedCerts", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PRIVATE | $FINAL, $field(SimpleValidator, trustedCerts)},
	{}
};

$MethodInfo _SimpleValidator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/Collection;)V", "(Ljava/lang/String;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;)V", 0, $method(SimpleValidator, init$, void, $String*, $Collection*)},
	{"buildTrustedChain", "([Ljava/security/cert/X509Certificate;)[Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $method(SimpleValidator, buildTrustedChain, $X509CertificateArray*, $X509CertificateArray*), "java.security.cert.CertificateException"},
	{"checkBasicConstraints", "(Ljava/security/cert/X509Certificate;Ljava/util/Set;I)I", "(Ljava/security/cert/X509Certificate;Ljava/util/Set<Ljava/lang/String;>;I)I", $PRIVATE, $method(SimpleValidator, checkBasicConstraints, int32_t, $X509Certificate*, $Set*, int32_t), "java.security.cert.CertificateException"},
	{"checkExtensions", "(Ljava/security/cert/X509Certificate;I)I", nullptr, $PRIVATE, $method(SimpleValidator, checkExtensions, int32_t, $X509Certificate*, int32_t), "java.security.cert.CertificateException"},
	{"checkKeyUsage", "(Ljava/security/cert/X509Certificate;Ljava/util/Set;)V", "(Ljava/security/cert/X509Certificate;Ljava/util/Set<Ljava/lang/String;>;)V", $PRIVATE, $method(SimpleValidator, checkKeyUsage, void, $X509Certificate*, $Set*), "java.security.cert.CertificateException"},
	{"checkNetscapeCertType", "(Ljava/security/cert/X509Certificate;Ljava/util/Set;)V", "(Ljava/security/cert/X509Certificate;Ljava/util/Set<Ljava/lang/String;>;)V", $PRIVATE, $method(SimpleValidator, checkNetscapeCertType, void, $X509Certificate*, $Set*), "java.security.cert.CertificateException"},
	{"engineValidate", "([Ljava/security/cert/X509Certificate;Ljava/util/Collection;Ljava/util/List;Ljava/security/AlgorithmConstraints;Ljava/lang/Object;)[Ljava/security/cert/X509Certificate;", "([Ljava/security/cert/X509Certificate;Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;Ljava/util/List<[B>;Ljava/security/AlgorithmConstraints;Ljava/lang/Object;)[Ljava/security/cert/X509Certificate;", 0, $virtualMethod(SimpleValidator, engineValidate, $X509CertificateArray*, $X509CertificateArray*, $Collection*, $List*, $AlgorithmConstraints*, Object$*), "java.security.cert.CertificateException"},
	{"getNetscapeCertTypeBit", "(Ljava/security/cert/X509Certificate;Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(SimpleValidator, getNetscapeCertTypeBit, bool, $X509Certificate*, $String*)},
	{"getTrustedCertificate", "(Ljava/security/cert/X509Certificate;)Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $method(SimpleValidator, getTrustedCertificate, $X509Certificate*, $X509Certificate*)},
	{"getTrustedCertificates", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/security/cert/X509Certificate;>;", $PUBLIC, $virtualMethod(SimpleValidator, getTrustedCertificates, $Collection*)},
	{}
};

$ClassInfo _SimpleValidator_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.validator.SimpleValidator",
	"sun.security.validator.Validator",
	nullptr,
	_SimpleValidator_FieldInfo_,
	_SimpleValidator_MethodInfo_
};

$Object* allocate$SimpleValidator($Class* clazz) {
	return $of($alloc(SimpleValidator));
}

$String* SimpleValidator::OID_BASIC_CONSTRAINTS = nullptr;
$String* SimpleValidator::OID_NETSCAPE_CERT_TYPE = nullptr;
$String* SimpleValidator::OID_KEY_USAGE = nullptr;
$String* SimpleValidator::OID_EXTENDED_KEY_USAGE = nullptr;
$String* SimpleValidator::OID_EKU_ANY_USAGE = nullptr;
$ObjectIdentifier* SimpleValidator::OBJID_NETSCAPE_CERT_TYPE = nullptr;
$String* SimpleValidator::NSCT_SSL_CA = nullptr;
$String* SimpleValidator::NSCT_CODE_SIGNING_CA = nullptr;

void SimpleValidator::init$($String* variant, $Collection* trustedCerts) {
	$useLocalCurrentObjectStackCache();
	$init($Validator);
	$Validator::init$($Validator::TYPE_SIMPLE, variant);
	$set(this, trustedCerts, trustedCerts);
	$set(this, trustedX500Principals, $new($HashMap));
	{
		$var($Iterator, i$, $nc(trustedCerts)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				$var($X500Principal, principal, $nc(cert)->getSubjectX500Principal());
				$var($List, list, $cast($List, $nc(this->trustedX500Principals)->get(principal)));
				if (list == nullptr) {
					$assign(list, $new($ArrayList, 2));
					$nc(this->trustedX500Principals)->put(principal, list);
				}
				$nc(list)->add(cert);
			}
		}
	}
}

$Collection* SimpleValidator::getTrustedCertificates() {
	return this->trustedCerts;
}

$X509CertificateArray* SimpleValidator::engineValidate($X509CertificateArray* chain$renamed, $Collection* otherCerts, $List* responseList, $AlgorithmConstraints* constraints, Object$* parameter) {
	$useLocalCurrentObjectStackCache();
	$var($X509CertificateArray, chain, chain$renamed);
	if ((chain == nullptr) || ($nc(chain)->length == 0)) {
		$throwNew($CertificateException, "null or zero-length certificate chain"_s);
	}
	$assign(chain, buildTrustedChain(chain));
	$var($Date, date, this->validationDate);
	if (date == nullptr) {
		$assign(date, $new($Date));
	}
	$var($UntrustedChecker, untrustedChecker, $new($UntrustedChecker));
	$var($X509Certificate, anchorCert, $nc(chain)->get(chain->length - 1));
	try {
		untrustedChecker->check(anchorCert);
	} catch ($CertPathValidatorException& cpve) {
		$init($ValidatorException);
		$throwNew($ValidatorException, $$str({"Untrusted certificate: "_s, $($nc(anchorCert)->getSubjectX500Principal())}), $ValidatorException::T_UNTRUSTED_CERT, anchorCert, cpve);
	}
	$var($TrustAnchor, anchor, $new($TrustAnchor, anchorCert, nullptr));
	$var($AlgorithmChecker, defaultAlgChecker, $new($AlgorithmChecker, anchor, this->variant));
	$var($AlgorithmChecker, appAlgChecker, nullptr);
	if (constraints != nullptr) {
		$assign(appAlgChecker, $new($AlgorithmChecker, anchor, constraints, nullptr, this->variant));
	}
	int32_t maxPathLength = chain->length - 1;
	for (int32_t i = chain->length - 2; i >= 0; --i) {
		$var($X509Certificate, issuerCert, chain->get(i + 1));
		$var($X509Certificate, cert, chain->get(i));
		try {
			untrustedChecker->check(cert, $($Collections::emptySet()));
		} catch ($CertPathValidatorException& cpve) {
			$init($ValidatorException);
			$throwNew($ValidatorException, $$str({"Untrusted certificate: "_s, $($nc(cert)->getSubjectX500Principal())}), $ValidatorException::T_UNTRUSTED_CERT, cert, cpve);
		}
		try {
			defaultAlgChecker->check(cert, $($Collections::emptySet()));
			if (appAlgChecker != nullptr) {
				appAlgChecker->check(cert, $($Collections::emptySet()));
			}
		} catch ($CertPathValidatorException& cpve) {
			$init($ValidatorException);
			$throwNew($ValidatorException, $ValidatorException::T_ALGORITHM_DISABLED, cert, static_cast<$Throwable*>(cpve));
		}
		$init($Validator);
		bool var$0 = ($nc(this->variant)->equals($Validator::VAR_CODE_SIGNING) == false);
		if (var$0 && ($nc(this->variant)->equals($Validator::VAR_JCE_SIGNING) == false)) {
			$nc(cert)->checkValidity(date);
		}
		if ($nc($($nc(cert)->getIssuerX500Principal()))->equals($($nc(issuerCert)->getSubjectX500Principal())) == false) {
			$init($ValidatorException);
			$throwNew($ValidatorException, $ValidatorException::T_NAME_CHAINING, cert);
		}
		try {
			$nc(cert)->verify($($nc(issuerCert)->getPublicKey()));
		} catch ($GeneralSecurityException& e) {
			$init($ValidatorException);
			$throwNew($ValidatorException, $ValidatorException::T_SIGNATURE_ERROR, cert, static_cast<$Throwable*>(e));
		}
		if (i != 0) {
			maxPathLength = checkExtensions(cert, maxPathLength);
		}
	}
	return chain;
}

int32_t SimpleValidator::checkExtensions($X509Certificate* cert, int32_t maxPathLen) {
	$useLocalCurrentObjectStackCache();
	$var($Set, critSet, $nc(cert)->getCriticalExtensionOIDs());
	if (critSet == nullptr) {
		$assign(critSet, $Collections::emptySet());
	}
	int32_t pathLenConstraint = checkBasicConstraints(cert, critSet, maxPathLen);
	checkKeyUsage(cert, critSet);
	checkNetscapeCertType(cert, critSet);
	if (!$nc(critSet)->isEmpty()) {
		$init($ValidatorException);
		$throwNew($ValidatorException, $$str({"Certificate contains unknown critical extensions: "_s, critSet}), $ValidatorException::T_CA_EXTENSIONS, cert);
	}
	return pathLenConstraint;
}

void SimpleValidator::checkNetscapeCertType($X509Certificate* cert, $Set* critSet) {
	$init($Validator);
	if ($nc(this->variant)->equals($Validator::VAR_GENERIC)) {
	} else {
		bool var$1 = $nc(this->variant)->equals($Validator::VAR_TLS_CLIENT);
		if (var$1 || $nc(this->variant)->equals($Validator::VAR_TLS_SERVER)) {
			if (getNetscapeCertTypeBit(cert, SimpleValidator::NSCT_SSL_CA) == false) {
				$init($ValidatorException);
				$throwNew($ValidatorException, "Invalid Netscape CertType extension for SSL CA certificate"_s, $ValidatorException::T_CA_EXTENSIONS, cert);
			}
			$nc(critSet)->remove(SimpleValidator::OID_NETSCAPE_CERT_TYPE);
		} else {
			bool var$3 = $nc(this->variant)->equals($Validator::VAR_CODE_SIGNING);
			if (var$3 || $nc(this->variant)->equals($Validator::VAR_JCE_SIGNING)) {
				if (getNetscapeCertTypeBit(cert, SimpleValidator::NSCT_CODE_SIGNING_CA) == false) {
					$init($ValidatorException);
					$throwNew($ValidatorException, "Invalid Netscape CertType extension for code signing CA certificate"_s, $ValidatorException::T_CA_EXTENSIONS, cert);
				}
				$nc(critSet)->remove(SimpleValidator::OID_NETSCAPE_CERT_TYPE);
			} else {
				$throwNew($CertificateException, $$str({"Unknown variant "_s, this->variant}));
			}
		}
	}
}

bool SimpleValidator::getNetscapeCertTypeBit($X509Certificate* cert, $String* type) {
	$init(SimpleValidator);
	$useLocalCurrentObjectStackCache();
	try {
		$var($NetscapeCertTypeExtension, ext, nullptr);
		if ($instanceOf($X509CertImpl, cert)) {
			$var($X509CertImpl, certImpl, $cast($X509CertImpl, cert));
			$var($ObjectIdentifier, oid, SimpleValidator::OBJID_NETSCAPE_CERT_TYPE);
			$assign(ext, $cast($NetscapeCertTypeExtension, $nc(certImpl)->getExtension(oid)));
			if (ext == nullptr) {
				return true;
			}
		} else {
			$var($bytes, extVal, $nc(cert)->getExtensionValue(SimpleValidator::OID_NETSCAPE_CERT_TYPE));
			if (extVal == nullptr) {
				return true;
			}
			$var($DerInputStream, in, $new($DerInputStream, extVal));
			$var($bytes, encoded, in->getOctetString());
			$assign(encoded, $nc($($$new($DerValue, encoded)->getUnalignedBitString()))->toByteArray());
			$assign(ext, $new($NetscapeCertTypeExtension, encoded));
		}
		$var($Boolean, val, $cast($Boolean, $nc(ext)->get(type)));
		return $nc(val)->booleanValue();
	} catch ($IOException& e) {
		return false;
	}
	$shouldNotReachHere();
}

int32_t SimpleValidator::checkBasicConstraints($X509Certificate* cert, $Set* critSet, int32_t maxPathLen) {
	$nc(critSet)->remove(SimpleValidator::OID_BASIC_CONSTRAINTS);
	int32_t constraints = $nc(cert)->getBasicConstraints();
	if (constraints < 0) {
		$init($ValidatorException);
		$throwNew($ValidatorException, "End user tried to act as a CA"_s, $ValidatorException::T_CA_EXTENSIONS, cert);
	}
	if (!$X509CertImpl::isSelfIssued(cert)) {
		if (maxPathLen <= 0) {
			$init($ValidatorException);
			$throwNew($ValidatorException, "Violated path length constraints"_s, $ValidatorException::T_CA_EXTENSIONS, cert);
		}
		--maxPathLen;
	}
	if (maxPathLen > constraints) {
		maxPathLen = constraints;
	}
	return maxPathLen;
}

void SimpleValidator::checkKeyUsage($X509Certificate* cert, $Set* critSet) {
	$nc(critSet)->remove(SimpleValidator::OID_KEY_USAGE);
	critSet->remove(SimpleValidator::OID_EXTENDED_KEY_USAGE);
	$var($booleans, keyUsageInfo, $nc(cert)->getKeyUsage());
	if (keyUsageInfo != nullptr) {
		if ((keyUsageInfo->length < 6) || (keyUsageInfo->get(5) == false)) {
			$init($ValidatorException);
			$throwNew($ValidatorException, "Wrong key usage: expected keyCertSign"_s, $ValidatorException::T_CA_EXTENSIONS, cert);
		}
	}
}

$X509CertificateArray* SimpleValidator::buildTrustedChain($X509CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	$var($List, c, $new($ArrayList, $nc(chain)->length));
	for (int32_t i = 0; i < $nc(chain)->length; ++i) {
		$var($X509Certificate, cert, chain->get(i));
		$var($X509Certificate, trustedCert, getTrustedCertificate(cert));
		if (trustedCert != nullptr) {
			c->add(trustedCert);
			$init($Validator);
			return $fcast($X509CertificateArray, c->toArray($Validator::CHAIN0));
		}
		c->add(cert);
	}
	$var($X509Certificate, cert, $nc(chain)->get(chain->length - 1));
	$var($X500Principal, subject, $nc(cert)->getSubjectX500Principal());
	$var($X500Principal, issuer, cert->getIssuerX500Principal());
	$var($List, list, $cast($List, $nc(this->trustedX500Principals)->get(issuer)));
	if (list != nullptr) {
		$var($X509Certificate, matchedCert, $cast($X509Certificate, list->get(0)));
		$var($X509CertImpl, certImpl, $X509CertImpl::toImpl(cert));
		$var($KeyIdentifier, akid, $nc(certImpl)->getAuthKeyId());
		if (akid != nullptr) {
			{
				$var($Iterator, i$, list->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($X509Certificate, sup, $cast($X509Certificate, i$->next()));
					{
						$var($X509CertImpl, supCert, $X509CertImpl::toImpl(sup));
						if (akid->equals($($nc(supCert)->getSubjectKeyId()))) {
							$assign(matchedCert, sup);
							break;
						}
					}
				}
			}
		}
		c->add(matchedCert);
		$init($Validator);
		return $fcast($X509CertificateArray, c->toArray($Validator::CHAIN0));
	}
	$init($ValidatorException);
	$throwNew($ValidatorException, $ValidatorException::T_NO_TRUST_ANCHOR);
}

$X509Certificate* SimpleValidator::getTrustedCertificate($X509Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($Principal, certSubjectName, $nc(cert)->getSubjectX500Principal());
	$var($List, list, $cast($List, $nc(this->trustedX500Principals)->get(certSubjectName)));
	if (list == nullptr) {
		return nullptr;
	}
	$var($Principal, certIssuerName, cert->getIssuerX500Principal());
	$var($PublicKey, certPublicKey, cert->getPublicKey());
	{
		$var($Iterator, i$, $nc(list)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, mycert, $cast($X509Certificate, i$->next()));
			{
				if ($nc(mycert)->equals(cert)) {
					return cert;
				}
				if (!$nc($($nc(mycert)->getIssuerX500Principal()))->equals(certIssuerName)) {
					continue;
				}
				if (!$nc($of($($nc(mycert)->getPublicKey())))->equals(certPublicKey)) {
					continue;
				}
				return mycert;
			}
		}
	}
	return nullptr;
}

void clinit$SimpleValidator($Class* class$) {
	$init($NetscapeCertTypeExtension);
	$assignStatic(SimpleValidator::NSCT_SSL_CA, $NetscapeCertTypeExtension::SSL_CA);
	$assignStatic(SimpleValidator::NSCT_CODE_SIGNING_CA, $NetscapeCertTypeExtension::OBJECT_SIGNING_CA);
	$init($KnownOIDs);
	$assignStatic(SimpleValidator::OID_BASIC_CONSTRAINTS, $KnownOIDs::BasicConstraints->value());
	$assignStatic(SimpleValidator::OID_NETSCAPE_CERT_TYPE, $KnownOIDs::NETSCAPE_CertType->value());
	$assignStatic(SimpleValidator::OID_KEY_USAGE, $KnownOIDs::KeyUsage->value());
	$assignStatic(SimpleValidator::OID_EXTENDED_KEY_USAGE, $KnownOIDs::extendedKeyUsage->value());
	$assignStatic(SimpleValidator::OID_EKU_ANY_USAGE, $KnownOIDs::anyExtendedKeyUsage->value());
	$init($NetscapeCertTypeExtension);
	$assignStatic(SimpleValidator::OBJID_NETSCAPE_CERT_TYPE, $NetscapeCertTypeExtension::NetscapeCertType_Id);
}

SimpleValidator::SimpleValidator() {
}

$Class* SimpleValidator::load$($String* name, bool initialize) {
	$loadClass(SimpleValidator, name, initialize, &_SimpleValidator_ClassInfo_, clinit$SimpleValidator, allocate$SimpleValidator);
	return class$;
}

$Class* SimpleValidator::class$ = nullptr;

		} // validator
	} // security
} // sun