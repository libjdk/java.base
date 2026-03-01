#include <sun/security/provider/certpath/OCSPResponse.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/security/AccessController.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/CRLReason.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathValidatorException$BasicReason.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateParsingException.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/action/GetIntegerAction.h>
#include <sun/security/provider/certpath/AlgorithmChecker.h>
#include <sun/security/provider/certpath/CertId.h>
#include <sun/security/provider/certpath/OCSP$RevocationStatus$CertStatus.h>
#include <sun/security/provider/certpath/OCSPResponse$1.h>
#include <sun/security/provider/certpath/OCSPResponse$IssuerInfo.h>
#include <sun/security/provider/certpath/OCSPResponse$ResponseStatus.h>
#include <sun/security/provider/certpath/OCSPResponse$SingleResponse.h>
#include <sun/security/provider/certpath/ResponderId$Type.h>
#include <sun/security/provider/certpath/ResponderId.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/KeyIdentifier.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef BY_KEY
#undef BY_NAME
#undef CERT_STATUS_GOOD
#undef CERT_STATUS_REVOKED
#undef CERT_STATUS_UNKNOWN
#undef DEFAULT_MAX_CLOCK_SKEW
#undef KEY_TAG
#undef MAX_CLOCK_SKEW
#undef NAME_TAG
#undef OCSP_BASIC_RESPONSE_OID
#undef SUCCESSFUL
#undef UNDETERMINED_REVOCATION_STATUS

using $CRLReasonArray = $Array<::java::security::cert::CRLReason>;
using $OCSPResponse$ResponseStatusArray = $Array<::sun::security::provider::certpath::OCSPResponse$ResponseStatus>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $CRLReason = ::java::security::cert::CRLReason;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$BasicReason = ::java::security::cert::CertPathValidatorException$BasicReason;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateParsingException = ::java::security::cert::CertificateParsingException;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;
using $AlgorithmChecker = ::sun::security::provider::certpath::AlgorithmChecker;
using $CertId = ::sun::security::provider::certpath::CertId;
using $OCSPResponse$1 = ::sun::security::provider::certpath::OCSPResponse$1;
using $OCSPResponse$IssuerInfo = ::sun::security::provider::certpath::OCSPResponse$IssuerInfo;
using $OCSPResponse$ResponseStatus = ::sun::security::provider::certpath::OCSPResponse$ResponseStatus;
using $OCSPResponse$SingleResponse = ::sun::security::provider::certpath::OCSPResponse$SingleResponse;
using $ResponderId = ::sun::security::provider::certpath::ResponderId;
using $ResponderId$Type = ::sun::security::provider::certpath::ResponderId$Type;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $Extension = ::sun::security::x509::Extension;
using $KeyIdentifier = ::sun::security::x509::KeyIdentifier;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _OCSPResponse_FieldInfo_[] = {
	{"rsvalues", "[Lsun/security/provider/certpath/OCSPResponse$ResponseStatus;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPResponse, rsvalues)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPResponse, debug)},
	{"dump", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPResponse, dump)},
	{"OCSP_BASIC_RESPONSE_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPResponse, OCSP_BASIC_RESPONSE_OID)},
	{"CERT_STATUS_GOOD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OCSPResponse, CERT_STATUS_GOOD)},
	{"CERT_STATUS_REVOKED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OCSPResponse, CERT_STATUS_REVOKED)},
	{"CERT_STATUS_UNKNOWN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OCSPResponse, CERT_STATUS_UNKNOWN)},
	{"NAME_TAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OCSPResponse, NAME_TAG)},
	{"KEY_TAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OCSPResponse, KEY_TAG)},
	{"DEFAULT_MAX_CLOCK_SKEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(OCSPResponse, DEFAULT_MAX_CLOCK_SKEW)},
	{"MAX_CLOCK_SKEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPResponse, MAX_CLOCK_SKEW)},
	{"values", "[Ljava/security/cert/CRLReason;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OCSPResponse, values)},
	{"responseStatus", "Lsun/security/provider/certpath/OCSPResponse$ResponseStatus;", nullptr, $PRIVATE | $FINAL, $field(OCSPResponse, responseStatus)},
	{"singleResponseMap", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/provider/certpath/CertId;Lsun/security/provider/certpath/OCSPResponse$SingleResponse;>;", $PRIVATE | $FINAL, $field(OCSPResponse, singleResponseMap)},
	{"sigAlgId", "Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE | $FINAL, $field(OCSPResponse, sigAlgId)},
	{"signature", "[B", nullptr, $PRIVATE | $FINAL, $field(OCSPResponse, signature)},
	{"tbsResponseData", "[B", nullptr, $PRIVATE | $FINAL, $field(OCSPResponse, tbsResponseData)},
	{"responseNonce", "[B", nullptr, $PRIVATE | $FINAL, $field(OCSPResponse, responseNonce)},
	{"certs", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/X509CertImpl;>;", $PRIVATE, $field(OCSPResponse, certs)},
	{"signerCert", "Lsun/security/x509/X509CertImpl;", nullptr, $PRIVATE, $field(OCSPResponse, signerCert)},
	{"respId", "Lsun/security/provider/certpath/ResponderId;", nullptr, $PRIVATE | $FINAL, $field(OCSPResponse, respId)},
	{"producedAtDate", "Ljava/util/Date;", nullptr, $PRIVATE, $field(OCSPResponse, producedAtDate)},
	{"responseExtensions", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/security/cert/Extension;>;", $PRIVATE | $FINAL, $field(OCSPResponse, responseExtensions)},
	{}
};

$MethodInfo _OCSPResponse_MethodInfo_[] = {
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(OCSPResponse, init$, void, $bytes*), "java.io.IOException"},
	{"getCertIds", "()Ljava/util/Set;", "()Ljava/util/Set<Lsun/security/provider/certpath/CertId;>;", $PUBLIC, $method(OCSPResponse, getCertIds, $Set*)},
	{"getResponderId", "()Lsun/security/provider/certpath/ResponderId;", nullptr, $PUBLIC, $method(OCSPResponse, getResponderId, $ResponderId*)},
	{"getResponseStatus", "()Lsun/security/provider/certpath/OCSPResponse$ResponseStatus;", nullptr, $PUBLIC, $method(OCSPResponse, getResponseStatus, $OCSPResponse$ResponseStatus*)},
	{"getSignerCertificate", "()Ljava/security/cert/X509Certificate;", nullptr, 0, $method(OCSPResponse, getSignerCertificate, $X509Certificate*)},
	{"getSingleResponse", "(Lsun/security/provider/certpath/CertId;)Lsun/security/provider/certpath/OCSPResponse$SingleResponse;", nullptr, $PUBLIC, $method(OCSPResponse, getSingleResponse, $OCSPResponse$SingleResponse*, $CertId*)},
	{"initializeClockSkew", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(OCSPResponse, initializeClockSkew, int32_t)},
	{"parseExtensions", "(Lsun/security/util/DerValue;)Ljava/util/Map;", "(Lsun/security/util/DerValue;)Ljava/util/Map<Ljava/lang/String;Ljava/security/cert/Extension;>;", $PRIVATE | $STATIC, $staticMethod(OCSPResponse, parseExtensions, $Map*, $DerValue*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(OCSPResponse, toString, $String*)},
	{"verify", "(Ljava/util/List;Lsun/security/provider/certpath/OCSPResponse$IssuerInfo;Ljava/security/cert/X509Certificate;Ljava/util/Date;[BLjava/lang/String;)V", "(Ljava/util/List<Lsun/security/provider/certpath/CertId;>;Lsun/security/provider/certpath/OCSPResponse$IssuerInfo;Ljava/security/cert/X509Certificate;Ljava/util/Date;[BLjava/lang/String;)V", 0, $method(OCSPResponse, verify, void, $List*, $OCSPResponse$IssuerInfo*, $X509Certificate*, $Date*, $bytes*, $String*), "java.security.cert.CertPathValidatorException"},
	{"verifySignature", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(OCSPResponse, verifySignature, bool, $X509Certificate*), "java.security.cert.CertPathValidatorException"},
	{}
};

$InnerClassInfo _OCSPResponse_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.OCSPResponse$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.security.provider.certpath.OCSPResponse$IssuerInfo", "sun.security.provider.certpath.OCSPResponse", "IssuerInfo", $STATIC | $FINAL},
	{"sun.security.provider.certpath.OCSPResponse$SingleResponse", "sun.security.provider.certpath.OCSPResponse", "SingleResponse", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.certpath.OCSPResponse$ResponseStatus", "sun.security.provider.certpath.OCSPResponse", "ResponseStatus", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _OCSPResponse_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.certpath.OCSPResponse",
	"java.lang.Object",
	nullptr,
	_OCSPResponse_FieldInfo_,
	_OCSPResponse_MethodInfo_,
	nullptr,
	nullptr,
	_OCSPResponse_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.OCSPResponse$1,sun.security.provider.certpath.OCSPResponse$IssuerInfo,sun.security.provider.certpath.OCSPResponse$SingleResponse,sun.security.provider.certpath.OCSPResponse$ResponseStatus"
};

$Object* allocate$OCSPResponse($Class* clazz) {
	return $of($alloc(OCSPResponse));
}

$OCSPResponse$ResponseStatusArray* OCSPResponse::rsvalues = nullptr;
$Debug* OCSPResponse::debug = nullptr;
bool OCSPResponse::dump = false;
$ObjectIdentifier* OCSPResponse::OCSP_BASIC_RESPONSE_OID = nullptr;
int32_t OCSPResponse::MAX_CLOCK_SKEW = 0;
$CRLReasonArray* OCSPResponse::values = nullptr;

int32_t OCSPResponse::initializeClockSkew() {
	$init(OCSPResponse);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Integer, tmp, $cast($Integer, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetIntegerAction, "com.sun.security.ocsp.clockSkew"_s)))));
	if (tmp == nullptr || $nc(tmp)->intValue() < 0) {
		return OCSPResponse::DEFAULT_MAX_CLOCK_SKEW;
	}
	return $nc(tmp)->intValue() * 1000;
}

void OCSPResponse::init$($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	$set(this, signerCert, nullptr);
	$set(this, producedAtDate, nullptr);
	if (OCSPResponse::dump) {
		$var($HexDumpEncoder, hexEnc, $new($HexDumpEncoder));
		$nc(OCSPResponse::debug)->println($$str({"OCSPResponse bytes...\n\n"_s, $(hexEnc->encode(bytes)), "\n"_s}));
	}
	$var($DerValue, der, $new($DerValue, bytes));
	if (der->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Bad encoding in OCSP response: expected ASN.1 SEQUENCE tag."_s);
	}
	$var($DerInputStream, derIn, der->getData());
	int32_t status = $nc(derIn)->getEnumerated();
	if (status >= 0 && status < $nc(OCSPResponse::rsvalues)->length) {
		$set(this, responseStatus, $nc(OCSPResponse::rsvalues)->get(status));
	} else {
		$throwNew($IOException, $$str({"Unknown OCSPResponse status: "_s, $$str(status)}));
	}
	if (OCSPResponse::debug != nullptr) {
		$nc(OCSPResponse::debug)->println($$str({"OCSP response status: "_s, this->responseStatus}));
	}
	$init($OCSPResponse$ResponseStatus);
	if (this->responseStatus != $OCSPResponse$ResponseStatus::SUCCESSFUL) {
		$set(this, singleResponseMap, $Collections::emptyMap());
		$set(this, certs, $new($ArrayList));
		$set(this, sigAlgId, nullptr);
		$set(this, signature, nullptr);
		$set(this, tbsResponseData, nullptr);
		$set(this, responseNonce, nullptr);
		$set(this, responseExtensions, $Collections::emptyMap());
		$set(this, respId, nullptr);
		return;
	}
	$assign(der, derIn->getDerValue());
	if (!$nc(der)->isContextSpecific((int8_t)0)) {
		$throwNew($IOException, "Bad encoding in responseBytes element of OCSP response: expected ASN.1 context specific tag 0."_s);
	}
	$var($DerValue, tmp, $nc($nc(der)->data$)->getDerValue());
	if ($nc(tmp)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Bad encoding in responseBytes element of OCSP response: expected ASN.1 SEQUENCE tag."_s);
	}
	$assign(derIn, $nc(tmp)->data$);
	$var($ObjectIdentifier, responseType, derIn->getOID());
	if ($nc(responseType)->equals($of(OCSPResponse::OCSP_BASIC_RESPONSE_OID))) {
		if (OCSPResponse::debug != nullptr) {
			$nc(OCSPResponse::debug)->println("OCSP response type: basic"_s);
		}
	} else {
		if (OCSPResponse::debug != nullptr) {
			$nc(OCSPResponse::debug)->println($$str({"OCSP response type: "_s, responseType}));
		}
		$throwNew($IOException, $$str({"Unsupported OCSP response type: "_s, responseType}));
	}
	$var($DerInputStream, basicOCSPResponse, $new($DerInputStream, $(derIn->getOctetString())));
	$var($DerValueArray, seqTmp, basicOCSPResponse->getSequence(3));
	if ($nc(seqTmp)->length < 3) {
		$throwNew($IOException, "Unexpected BasicOCSPResponse value"_s);
	}
	$var($DerValue, responseData, $nc(seqTmp)->get(0));
	$set(this, tbsResponseData, $nc(seqTmp->get(0))->toByteArray());
	if ($nc(responseData)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Bad encoding in tbsResponseData element of OCSP response: expected ASN.1 SEQUENCE tag."_s);
	}
	$var($DerInputStream, seqDerIn, $nc(responseData)->data$);
	$var($DerValue, seq, $nc(seqDerIn)->getDerValue());
	if ($nc(seq)->isContextSpecific((int8_t)0)) {
		bool var$0 = seq->isConstructed();
		if (var$0 && seq->isContextSpecific()) {
			$assign(seq, $nc(seq->data$)->getDerValue());
			int32_t version = $nc(seq)->getInteger();
			if ($nc(seq->data$)->available() != 0) {
				$throwNew($IOException, "Bad encoding in version  element of OCSP response: bad format"_s);
			}
			$assign(seq, seqDerIn->getDerValue());
		}
	}
	$set(this, respId, $new($ResponderId, $($nc(seq)->toByteArray())));
	if (OCSPResponse::debug != nullptr) {
		$nc(OCSPResponse::debug)->println($$str({"Responder ID: "_s, this->respId}));
	}
	$assign(seq, seqDerIn->getDerValue());
	$set(this, producedAtDate, $nc(seq)->getGeneralizedTime());
	if (OCSPResponse::debug != nullptr) {
		$nc(OCSPResponse::debug)->println($$str({"OCSP response produced at: "_s, this->producedAtDate}));
	}
	$var($DerValueArray, singleResponseDer, seqDerIn->getSequence(1));
	$set(this, singleResponseMap, $new($HashMap, $nc(singleResponseDer)->length));
	if (OCSPResponse::debug != nullptr) {
		$nc(OCSPResponse::debug)->println($$str({"OCSP number of SingleResponses: "_s, $$str($nc(singleResponseDer)->length)}));
	}
	{
		$var($DerValueArray, arr$, singleResponseDer);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($DerValue, srDer, arr$->get(i$));
			{
				$var($OCSPResponse$SingleResponse, singleResponse, $new($OCSPResponse$SingleResponse, srDer));
				$nc(this->singleResponseMap)->put($(singleResponse->getCertId()), singleResponse);
			}
		}
	}
	$var($Map, tmpExtMap, $new($HashMap));
	if (seqDerIn->available() > 0) {
		$assign(seq, seqDerIn->getDerValue());
		if ($nc(seq)->isContextSpecific((int8_t)1)) {
			$assign(tmpExtMap, parseExtensions(seq));
		}
	}
	$set(this, responseExtensions, tmpExtMap);
	$init($PKIXExtensions);
	$var($Extension, nonceExt, $cast($Extension, tmpExtMap->get($($nc($PKIXExtensions::OCSPNonce_Id)->toString()))));
	$set(this, responseNonce, (nonceExt != nullptr) ? $nc(nonceExt)->getExtensionValue() : ($bytes*)nullptr);
	if (OCSPResponse::debug != nullptr && this->responseNonce != nullptr) {
		$nc(OCSPResponse::debug)->println($$str({"Response nonce: "_s, $($Arrays::toString(this->responseNonce))}));
	}
	$set(this, sigAlgId, $AlgorithmId::parse(seqTmp->get(1)));
	$set(this, signature, $nc(seqTmp->get(2))->getBitString());
	if (seqTmp->length > 3) {
		$var($DerValue, seqCert, seqTmp->get(3));
		if (!$nc(seqCert)->isContextSpecific((int8_t)0)) {
			$throwNew($IOException, "Bad encoding in certs element of OCSP response: expected ASN.1 context specific tag 0."_s);
		}
		$var($DerValueArray, derCerts, $nc($($nc(seqCert)->getData()))->getSequence(3));
		$set(this, certs, $new($ArrayList, $nc(derCerts)->length));
		try {
			for (int32_t i = 0; i < $nc(derCerts)->length; ++i) {
				$var($X509CertImpl, cert, $new($X509CertImpl, $($nc(derCerts->get(i))->toByteArray())));
				$nc(this->certs)->add(cert);
				if (OCSPResponse::debug != nullptr) {
					$nc(OCSPResponse::debug)->println($$str({"OCSP response cert #"_s, $$str((i + 1)), ": "_s, $(cert->getSubjectX500Principal())}));
				}
			}
		} catch ($CertificateException& ce) {
			$throwNew($IOException, "Bad encoding in X509 Certificate"_s, ce);
		}
	} else {
		$set(this, certs, $new($ArrayList));
	}
}

void OCSPResponse::verify($List* certIds, $OCSPResponse$IssuerInfo* issuerInfo, $X509Certificate* responderCert, $Date* date, $bytes* nonce, $String* variant) {
	$useLocalCurrentObjectStackCache();
	$init($OCSPResponse$1);
	switch ($nc($OCSPResponse$1::$SwitchMap$sun$security$provider$certpath$OCSPResponse$ResponseStatus)->get((this->responseStatus)->ordinal())) {
	case 1:
		{
			break;
		}
	case 2:
		{}
	case 3:
		{
			$init($CertPathValidatorException$BasicReason);
			$throwNew($CertPathValidatorException, $$str({"OCSP response error: "_s, this->responseStatus}), nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
		}
	case 4:
		{}
	default:
		{
			$throwNew($CertPathValidatorException, $$str({"OCSP response error: "_s, this->responseStatus}));
		}
	}
	{
		$var($Iterator, i$, $nc(certIds)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertId, certId, $cast($CertId, i$->next()));
			{
				$var($OCSPResponse$SingleResponse, sr, getSingleResponse(certId));
				if (sr == nullptr) {
					if (OCSPResponse::debug != nullptr) {
						$nc(OCSPResponse::debug)->println($$str({"No response found for CertId: "_s, certId}));
					}
					$throwNew($CertPathValidatorException, "OCSP response does not include a response for a certificate supplied in the OCSP request"_s);
				}
				if (OCSPResponse::debug != nullptr) {
					$var($String, var$0, $$str({"Status of certificate (with serial number "_s, $($nc(certId)->getSerialNumber()), ") is: "_s}));
					$nc(OCSPResponse::debug)->println($$concat(var$0, $($nc(sr)->getCertStatus())));
				}
			}
		}
	}
	if (this->signerCert == nullptr) {
		try {
			if ($nc(issuerInfo)->getCertificate() != nullptr) {
				$nc(this->certs)->add($($X509CertImpl::toImpl($(issuerInfo->getCertificate()))));
			}
			if (responderCert != nullptr) {
				$nc(this->certs)->add($($X509CertImpl::toImpl(responderCert)));
			}
		} catch ($CertificateException& ce) {
			$throwNew($CertPathValidatorException, "Invalid issuer or trusted responder certificate"_s, ce);
		}
		$init($ResponderId$Type);
		if ($nc(this->respId)->getType() == $ResponderId$Type::BY_NAME) {
			$var($X500Principal, rName, $nc(this->respId)->getResponderName());
			{
				$var($Iterator, i$, $nc(this->certs)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($X509CertImpl, cert, $cast($X509CertImpl, i$->next()));
					{
						if ($nc($($nc(cert)->getSubjectX500Principal()))->equals(rName)) {
							$set(this, signerCert, cert);
							break;
						}
					}
				}
			}
		} else {
			if ($nc(this->respId)->getType() == $ResponderId$Type::BY_KEY) {
				$var($KeyIdentifier, ridKeyId, $nc(this->respId)->getKeyIdentifier());
				{
					$var($Iterator, i$, $nc(this->certs)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($X509CertImpl, cert, $cast($X509CertImpl, i$->next()));
						{
							$var($KeyIdentifier, certKeyId, $nc(cert)->getSubjectKeyId());
							if (certKeyId != nullptr && $nc(ridKeyId)->equals(certKeyId)) {
								$set(this, signerCert, cert);
								break;
							} else {
								try {
									$assign(certKeyId, $new($KeyIdentifier, $(cert->getPublicKey())));
								} catch ($IOException& e) {
								}
								if (ridKeyId->equals(certKeyId)) {
									$set(this, signerCert, cert);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	bool signedByTrustedResponder = false;
	if (this->signerCert != nullptr) {
		bool var$1 = $nc($($nc(this->signerCert)->getSubjectX500Principal()))->equals($($nc(issuerInfo)->getName()));
		if (var$1 && $nc($of($($nc(this->signerCert)->getPublicKey())))->equals($($nc(issuerInfo)->getPublicKey()))) {
			if (OCSPResponse::debug != nullptr) {
				$nc(OCSPResponse::debug)->println("OCSP response is signed by the target\'s Issuing CA"_s);
			}
		} else if ($nc(this->signerCert)->equals(responderCert)) {
			signedByTrustedResponder = true;
			if (OCSPResponse::debug != nullptr) {
				$nc(OCSPResponse::debug)->println("OCSP response is signed by a Trusted Responder"_s);
			}
		} else if ($nc($($nc(this->signerCert)->getIssuerX500Principal()))->equals($($nc(issuerInfo)->getName()))) {
			try {
				$var($List, keyPurposes, $nc(this->signerCert)->getExtendedKeyUsage());
				$init($KnownOIDs);
				if (keyPurposes == nullptr || !$nc(keyPurposes)->contains($($KnownOIDs::OCSPSigning->value()))) {
					$throwNew($CertPathValidatorException, "Responder\'s certificate not valid for signing OCSP responses"_s);
				}
			} catch ($CertificateParsingException& cpe) {
				$throwNew($CertPathValidatorException, "Responder\'s certificate not valid for signing OCSP responses"_s, cpe);
			}
			$var($AlgorithmChecker, algChecker, $new($AlgorithmChecker, $($nc(issuerInfo)->getAnchor()), date, variant));
			algChecker->init(false);
			algChecker->check(this->signerCert, $($Collections::emptySet()));
			try {
				if (date == nullptr) {
					$nc(this->signerCert)->checkValidity();
				} else {
					$nc(this->signerCert)->checkValidity(date);
				}
			} catch ($CertificateException& e) {
				$throwNew($CertPathValidatorException, "Responder\'s certificate not within the validity period"_s, e);
			}
			$init($PKIXExtensions);
			$var($Extension, noCheck, $nc(this->signerCert)->getExtension($PKIXExtensions::OCSPNoCheck_Id));
			if (noCheck != nullptr) {
				if (OCSPResponse::debug != nullptr) {
					$nc(OCSPResponse::debug)->println("Responder\'s certificate includes the extension id-pkix-ocsp-nocheck."_s);
				}
			} else {
			}
			try {
				$nc(this->signerCert)->verify($($nc(issuerInfo)->getPublicKey()));
				if (OCSPResponse::debug != nullptr) {
					$nc(OCSPResponse::debug)->println("OCSP response is signed by an Authorized Responder"_s);
				}
			} catch ($GeneralSecurityException& e) {
				$set(this, signerCert, nullptr);
			}
		} else {
			$throwNew($CertPathValidatorException, "Responder\'s certificate is not authorized to sign OCSP responses"_s);
		}
	}
	if (this->signerCert != nullptr) {
		$var($PublicKey, var$2, $nc(this->signerCert)->getPublicKey());
		$var($AlgorithmId, var$3, this->sigAlgId);
		$var($String, var$4, variant);
		$AlgorithmChecker::check(var$2, var$3, var$4, signedByTrustedResponder ? $$new($TrustAnchor, responderCert, nullptr) : $($nc(issuerInfo)->getAnchor()));
		if (!verifySignature(this->signerCert)) {
			$throwNew($CertPathValidatorException, "Error verifying OCSP Response\'s signature"_s);
		}
	} else {
		$throwNew($CertPathValidatorException, "Unable to verify OCSP Response\'s signature"_s);
	}
	if (nonce != nullptr) {
		if (this->responseNonce != nullptr && !$Arrays::equals(nonce, this->responseNonce)) {
			$throwNew($CertPathValidatorException, "Nonces don\'t match"_s);
		}
	}
	int64_t now = (date == nullptr) ? $System::currentTimeMillis() : $nc(date)->getTime();
	$var($Date, nowPlusSkew, $new($Date, now + OCSPResponse::MAX_CLOCK_SKEW));
	$var($Date, nowMinusSkew, $new($Date, now - OCSPResponse::MAX_CLOCK_SKEW));
	{
		$var($Iterator, i$, $nc($($nc(this->singleResponseMap)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($OCSPResponse$SingleResponse, sr, $cast($OCSPResponse$SingleResponse, i$->next()));
			{
				if (OCSPResponse::debug != nullptr) {
					$var($String, until, ""_s);
					if ($nc(sr)->nextUpdate != nullptr) {
						$assign(until, $str({" until "_s, sr->nextUpdate}));
					}
					$nc(OCSPResponse::debug)->println($$str({"OCSP response validity interval is from "_s, $nc(sr)->thisUpdate, until}));
					$nc(OCSPResponse::debug)->println($$str({"Checking validity of OCSP response on "_s, $$new($Date, now), " with allowed interval between "_s, nowMinusSkew, " and "_s, nowPlusSkew}));
				}
				bool var$5 = nowPlusSkew->before($nc(sr)->thisUpdate);
				if (var$5 || nowMinusSkew->after($nc(sr)->nextUpdate != nullptr ? $nc(sr)->nextUpdate : sr->thisUpdate)) {
					$throwNew($CertPathValidatorException, "Response is unreliable: its validity interval is out-of-date"_s);
				}
			}
		}
	}
}

$OCSPResponse$ResponseStatus* OCSPResponse::getResponseStatus() {
	return this->responseStatus;
}

bool OCSPResponse::verifySignature($X509Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Signature, respSignature, $Signature::getInstance($($nc(this->sigAlgId)->getName())));
		$nc(respSignature)->initVerify($($nc(cert)->getPublicKey()));
		respSignature->update(this->tbsResponseData);
		if (respSignature->verify(this->signature)) {
			if (OCSPResponse::debug != nullptr) {
				$nc(OCSPResponse::debug)->println("Verified signature of OCSP Response"_s);
			}
			return true;
		} else {
			if (OCSPResponse::debug != nullptr) {
				$nc(OCSPResponse::debug)->println("Error verifying signature of OCSP Response"_s);
			}
			return false;
		}
	} catch ($InvalidKeyException& e) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
	} catch ($SignatureException& e) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$OCSPResponse$SingleResponse* OCSPResponse::getSingleResponse($CertId* certId) {
	return $cast($OCSPResponse$SingleResponse, $nc(this->singleResponseMap)->get(certId));
}

$Set* OCSPResponse::getCertIds() {
	return $Collections::unmodifiableSet($($nc(this->singleResponseMap)->keySet()));
}

$X509Certificate* OCSPResponse::getSignerCertificate() {
	return this->signerCert;
}

$ResponderId* OCSPResponse::getResponderId() {
	return this->respId;
}

$String* OCSPResponse::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("OCSP Response:\n"_s);
	sb->append("Response Status: "_s)->append($of(this->responseStatus))->append("\n"_s);
	sb->append("Responder ID: "_s)->append($of(this->respId))->append("\n"_s);
	sb->append("Produced at: "_s)->append($of(this->producedAtDate))->append("\n"_s);
	int32_t count = $nc(this->singleResponseMap)->size();
	sb->append(count)->append(count == 1 ? " response:\n"_s : " responses:\n"_s);
	{
		$var($Iterator, i$, $nc($($nc(this->singleResponseMap)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($OCSPResponse$SingleResponse, sr, $cast($OCSPResponse$SingleResponse, i$->next()));
			{
				sb->append($of(sr))->append("\n"_s);
			}
		}
	}
	if (this->responseExtensions != nullptr && $nc(this->responseExtensions)->size() > 0) {
		count = $nc(this->responseExtensions)->size();
		sb->append(count)->append(count == 1 ? " extension:\n"_s : " extensions:\n"_s);
		{
			$var($Iterator, i$, $nc($($nc(this->responseExtensions)->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, extId, $cast($String, i$->next()));
				{
					sb->append($($nc(this->responseExtensions)->get(extId)))->append("\n"_s);
				}
			}
		}
	}
	return sb->toString();
}

$Map* OCSPResponse::parseExtensions($DerValue* derVal) {
	$init(OCSPResponse);
	$useLocalCurrentObjectStackCache();
	$var($DerValueArray, extDer, $nc($nc(derVal)->data$)->getSequence(3));
	$var($Map, extMap, $new($HashMap, $nc(extDer)->length));
	{
		$var($DerValueArray, arr$, extDer);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($DerValue, extDerVal, arr$->get(i$));
			{
				$var($Extension, ext, $new($Extension, extDerVal));
				if (OCSPResponse::debug != nullptr) {
					$nc(OCSPResponse::debug)->println($$str({"Extension: "_s, ext}));
				}
				if (ext->isCritical()) {
					$throwNew($IOException, $$str({"Unsupported OCSP critical extension: "_s, $(ext->getExtensionId())}));
				}
				extMap->put($(ext->getId()), ext);
			}
		}
	}
	return extMap;
}

void clinit$OCSPResponse($Class* class$) {
	$assignStatic(OCSPResponse::rsvalues, $OCSPResponse$ResponseStatus::values());
	$assignStatic(OCSPResponse::debug, $Debug::getInstance("certpath"_s));
	OCSPResponse::dump = OCSPResponse::debug != nullptr && $Debug::isOn("ocsp"_s);
	$init($KnownOIDs);
	$assignStatic(OCSPResponse::OCSP_BASIC_RESPONSE_OID, $ObjectIdentifier::of($KnownOIDs::OCSPBasicResponse));
	OCSPResponse::MAX_CLOCK_SKEW = OCSPResponse::initializeClockSkew();
	$assignStatic(OCSPResponse::values, $CRLReason::values());
}

OCSPResponse::OCSPResponse() {
}

$Class* OCSPResponse::load$($String* name, bool initialize) {
	$loadClass(OCSPResponse, name, initialize, &_OCSPResponse_ClassInfo_, clinit$OCSPResponse, allocate$OCSPResponse);
	return class$;
}

$Class* OCSPResponse::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun