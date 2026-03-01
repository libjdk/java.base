#include <sun/security/provider/certpath/RevocationChecker.h>

#include <java/io/IOException.h>
#include <java/lang/NumberFormatException.h>
#include <java/math/BigInteger.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/security/AccessController.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Principal.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CRLReason.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathBuilder.h>
#include <java/security/cert/CertPathBuilderException.h>
#include <java/security/cert/CertPathBuilderResult.h>
#include <java/security/cert/CertPathParameters.h>
#include <java/security/cert/CertPathValidatorException$BasicReason.h>
#include <java/security/cert/CertPathValidatorException$Reason.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateRevokedException.h>
#include <java/security/cert/CollectionCertStoreParameters.h>
#include <java/security/cert/Extension.h>
#include <java/security/cert/PKIXBuilderParameters.h>
#include <java/security/cert/PKIXCertPathBuilderResult.h>
#include <java/security/cert/PKIXRevocationChecker$Option.h>
#include <java/security/cert/PKIXRevocationChecker.h>
#include <java/security/cert/TrustAnchor.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509CRLEntry.h>
#include <java/security/cert/X509CRLSelector.h>
#include <java/security/cert/X509CertSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/certpath/BasicChecker.h>
#include <sun/security/provider/certpath/Builder.h>
#include <sun/security/provider/certpath/CertId.h>
#include <sun/security/provider/certpath/CertPathHelper.h>
#include <sun/security/provider/certpath/DistributionPointFetcher.h>
#include <sun/security/provider/certpath/OCSP$RevocationStatus$CertStatus.h>
#include <sun/security/provider/certpath/OCSP$RevocationStatus.h>
#include <sun/security/provider/certpath/OCSP.h>
#include <sun/security/provider/certpath/OCSPNonceExtension.h>
#include <sun/security/provider/certpath/OCSPResponse$IssuerInfo.h>
#include <sun/security/provider/certpath/OCSPResponse$SingleResponse.h>
#include <sun/security/provider/certpath/OCSPResponse.h>
#include <sun/security/provider/certpath/PKIX$CertStoreTypeException.h>
#include <sun/security/provider/certpath/PKIX$ValidatorParams.h>
#include <sun/security/provider/certpath/PKIX.h>
#include <sun/security/provider/certpath/RevocationChecker$1.h>
#include <sun/security/provider/certpath/RevocationChecker$2.h>
#include <sun/security/provider/certpath/RevocationChecker$Mode.h>
#include <sun/security/provider/certpath/RevocationChecker$RejectKeySelector.h>
#include <sun/security/provider/certpath/RevocationChecker$RevocationProperties.h>
#include <sun/security/provider/certpath/URICertStore.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AccessDescription.h>
#include <sun/security/x509/AuthorityInfoAccessExtension.h>
#include <sun/security/x509/CRLDistributionPointsExtension.h>
#include <sun/security/x509/DistributionPoint.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/SerialNumber.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CRLEntryImpl.h>
#include <sun/security/x509/X509CertImpl.h>
#include <jcpp.h>

#undef ALL_REASONS
#undef CRL_SIGN_USAGE
#undef DEFAULT_NONCE_BYTES
#undef MAX_CLOCK_SKEW
#undef NO_FALLBACK
#undef ONLY_CRLS
#undef ONLY_END_ENTITY
#undef ONLY_OCSP
#undef POINTS
#undef PREFER_CRLS
#undef PREFER_OCSP
#undef REVOKED
#undef SOFT_FAIL
#undef UNDETERMINED_REVOCATION_STATUS
#undef UNKNOWN
#undef UNSPECIFIED
#undef USE_AIA

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $AccessController = ::java::security::AccessController;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PublicKey = ::java::security::PublicKey;
using $CRL = ::java::security::cert::CRL;
using $CRLException = ::java::security::cert::CRLException;
using $CRLReason = ::java::security::cert::CRLReason;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathBuilder = ::java::security::cert::CertPathBuilder;
using $CertPathBuilderException = ::java::security::cert::CertPathBuilderException;
using $CertPathParameters = ::java::security::cert::CertPathParameters;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertPathValidatorException$BasicReason = ::java::security::cert::CertPathValidatorException$BasicReason;
using $CertPathValidatorException$Reason = ::java::security::cert::CertPathValidatorException$Reason;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateRevokedException = ::java::security::cert::CertificateRevokedException;
using $CollectionCertStoreParameters = ::java::security::cert::CollectionCertStoreParameters;
using $Extension = ::java::security::cert::Extension;
using $PKIXBuilderParameters = ::java::security::cert::PKIXBuilderParameters;
using $PKIXCertPathBuilderResult = ::java::security::cert::PKIXCertPathBuilderResult;
using $PKIXRevocationChecker = ::java::security::cert::PKIXRevocationChecker;
using $PKIXRevocationChecker$Option = ::java::security::cert::PKIXRevocationChecker$Option;
using $TrustAnchor = ::java::security::cert::TrustAnchor;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509CRLEntry = ::java::security::cert::X509CRLEntry;
using $X509CRLSelector = ::java::security::cert::X509CRLSelector;
using $X509CertSelector = ::java::security::cert::X509CertSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $BasicChecker = ::sun::security::provider::certpath::BasicChecker;
using $Builder = ::sun::security::provider::certpath::Builder;
using $CertId = ::sun::security::provider::certpath::CertId;
using $CertPathHelper = ::sun::security::provider::certpath::CertPathHelper;
using $DistributionPointFetcher = ::sun::security::provider::certpath::DistributionPointFetcher;
using $OCSP = ::sun::security::provider::certpath::OCSP;
using $OCSP$RevocationStatus = ::sun::security::provider::certpath::OCSP$RevocationStatus;
using $OCSP$RevocationStatus$CertStatus = ::sun::security::provider::certpath::OCSP$RevocationStatus$CertStatus;
using $OCSPNonceExtension = ::sun::security::provider::certpath::OCSPNonceExtension;
using $OCSPResponse = ::sun::security::provider::certpath::OCSPResponse;
using $OCSPResponse$IssuerInfo = ::sun::security::provider::certpath::OCSPResponse$IssuerInfo;
using $PKIX = ::sun::security::provider::certpath::PKIX;
using $PKIX$CertStoreTypeException = ::sun::security::provider::certpath::PKIX$CertStoreTypeException;
using $PKIX$ValidatorParams = ::sun::security::provider::certpath::PKIX$ValidatorParams;
using $RevocationChecker$1 = ::sun::security::provider::certpath::RevocationChecker$1;
using $RevocationChecker$2 = ::sun::security::provider::certpath::RevocationChecker$2;
using $RevocationChecker$Mode = ::sun::security::provider::certpath::RevocationChecker$Mode;
using $RevocationChecker$RejectKeySelector = ::sun::security::provider::certpath::RevocationChecker$RejectKeySelector;
using $RevocationChecker$RevocationProperties = ::sun::security::provider::certpath::RevocationChecker$RevocationProperties;
using $URICertStore = ::sun::security::provider::certpath::URICertStore;
using $Debug = ::sun::security::util::Debug;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AccessDescription = ::sun::security::x509::AccessDescription;
using $AuthorityInfoAccessExtension = ::sun::security::x509::AuthorityInfoAccessExtension;
using $CRLDistributionPointsExtension = ::sun::security::x509::CRLDistributionPointsExtension;
using $DistributionPoint = ::sun::security::x509::DistributionPoint;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CRLEntryImpl = ::sun::security::x509::X509CRLEntryImpl;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _RevocationChecker_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RevocationChecker, debug)},
	{"anchor", "Ljava/security/cert/TrustAnchor;", nullptr, $PRIVATE, $field(RevocationChecker, anchor)},
	{"params", "Lsun/security/provider/certpath/PKIX$ValidatorParams;", nullptr, $PRIVATE, $field(RevocationChecker, params)},
	{"onlyEE", "Z", nullptr, $PRIVATE, $field(RevocationChecker, onlyEE)},
	{"softFail", "Z", nullptr, $PRIVATE, $field(RevocationChecker, softFail)},
	{"crlDP", "Z", nullptr, $PRIVATE, $field(RevocationChecker, crlDP)},
	{"responderURI", "Ljava/net/URI;", nullptr, $PRIVATE, $field(RevocationChecker, responderURI)},
	{"responderCert", "Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(RevocationChecker, responderCert)},
	{"certStores", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/CertStore;>;", $PRIVATE, $field(RevocationChecker, certStores)},
	{"ocspResponses", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/cert/X509Certificate;[B>;", $PRIVATE, $field(RevocationChecker, ocspResponses)},
	{"ocspExtensions", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/Extension;>;", $PRIVATE, $field(RevocationChecker, ocspExtensions)},
	{"legacy", "Z", nullptr, $PRIVATE | $FINAL, $field(RevocationChecker, legacy)},
	{"softFailExceptions", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Ljava/security/cert/CertPathValidatorException;>;", $PRIVATE, $field(RevocationChecker, softFailExceptions)},
	{"issuerInfo", "Lsun/security/provider/certpath/OCSPResponse$IssuerInfo;", nullptr, $PRIVATE, $field(RevocationChecker, issuerInfo)},
	{"prevPubKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(RevocationChecker, prevPubKey)},
	{"crlSignFlag", "Z", nullptr, $PRIVATE, $field(RevocationChecker, crlSignFlag)},
	{"certIndex", "I", nullptr, $PRIVATE, $field(RevocationChecker, certIndex)},
	{"mode", "Lsun/security/provider/certpath/RevocationChecker$Mode;", nullptr, $PRIVATE, $field(RevocationChecker, mode)},
	{"rp", "Lsun/security/provider/certpath/RevocationChecker$RevocationProperties;", nullptr, $PRIVATE, $field(RevocationChecker, rp)},
	{"DEFAULT_NONCE_BYTES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RevocationChecker, DEFAULT_NONCE_BYTES)},
	{"MAX_CLOCK_SKEW", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RevocationChecker, MAX_CLOCK_SKEW)},
	{"ALL_REASONS", "[Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RevocationChecker, ALL_REASONS)},
	{"CRL_SIGN_USAGE", "[Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RevocationChecker, CRL_SIGN_USAGE)},
	{}
};

$MethodInfo _RevocationChecker_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(RevocationChecker, init$, void)},
	{"<init>", "(Ljava/security/cert/TrustAnchor;Lsun/security/provider/certpath/PKIX$ValidatorParams;)V", nullptr, 0, $method(RevocationChecker, init$, void, $TrustAnchor*, $PKIX$ValidatorParams*), "java.security.cert.CertPathValidatorException"},
	{"buildToNewKey", "(Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;Ljava/util/Set;)V", "(Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;Ljava/util/Set<Ljava/security/cert/X509Certificate;>;)V", $PRIVATE, $method(RevocationChecker, buildToNewKey, void, $X509Certificate*, $PublicKey*, $Set*), "java.security.cert.CertPathValidatorException"},
	{"certCanSignCrl", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $STATIC, $staticMethod(RevocationChecker, certCanSignCrl, bool, $X509Certificate*)},
	{"check", "(Ljava/security/cert/Certificate;Ljava/util/Collection;)V", "(Ljava/security/cert/Certificate;Ljava/util/Collection<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(RevocationChecker, check, void, $Certificate*, $Collection*), "java.security.cert.CertPathValidatorException"},
	{"check", "(Ljava/security/cert/X509Certificate;Ljava/util/Collection;Ljava/security/PublicKey;Z)V", "(Ljava/security/cert/X509Certificate;Ljava/util/Collection<Ljava/lang/String;>;Ljava/security/PublicKey;Z)V", $PRIVATE, $method(RevocationChecker, check, void, $X509Certificate*, $Collection*, $PublicKey*, bool), "java.security.cert.CertPathValidatorException"},
	{"checkApprovedCRLs", "(Ljava/security/cert/X509Certificate;Ljava/util/Set;)V", "(Ljava/security/cert/X509Certificate;Ljava/util/Set<Ljava/security/cert/X509CRL;>;)V", $PRIVATE, $method(RevocationChecker, checkApprovedCRLs, void, $X509Certificate*, $Set*), "java.security.cert.CertPathValidatorException"},
	{"checkCRLs", "(Ljava/security/cert/X509Certificate;Ljava/util/Collection;Ljava/util/Set;Ljava/security/PublicKey;Z)V", "(Ljava/security/cert/X509Certificate;Ljava/util/Collection<Ljava/lang/String;>;Ljava/util/Set<Ljava/security/cert/X509Certificate;>;Ljava/security/PublicKey;Z)V", $PRIVATE, $method(RevocationChecker, checkCRLs, void, $X509Certificate*, $Collection*, $Set*, $PublicKey*, bool), "java.security.cert.CertPathValidatorException"},
	{"checkCRLs", "(Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;Ljava/security/cert/X509Certificate;ZZLjava/util/Set;Ljava/util/Set;)V", "(Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;Ljava/security/cert/X509Certificate;ZZLjava/util/Set<Ljava/security/cert/X509Certificate;>;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;)V", $PRIVATE, $method(RevocationChecker, checkCRLs, void, $X509Certificate*, $PublicKey*, $X509Certificate*, bool, bool, $Set*, $Set*), "java.security.cert.CertPathValidatorException"},
	{"checkOCSP", "(Ljava/security/cert/X509Certificate;Ljava/util/Collection;)V", "(Ljava/security/cert/X509Certificate;Ljava/util/Collection<Ljava/lang/String;>;)V", $PRIVATE, $method(RevocationChecker, checkOCSP, void, $X509Certificate*, $Collection*), "java.security.cert.CertPathValidatorException"},
	{"getResponderCert", "(Lsun/security/provider/certpath/RevocationChecker$RevocationProperties;Ljava/util/Set;Ljava/util/List;)Ljava/security/cert/X509Certificate;", "(Lsun/security/provider/certpath/RevocationChecker$RevocationProperties;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/security/cert/X509Certificate;", $PRIVATE | $STATIC, $staticMethod(RevocationChecker, getResponderCert, $X509Certificate*, $RevocationChecker$RevocationProperties*, $Set*, $List*), "java.security.cert.CertPathValidatorException"},
	{"getResponderCert", "(Ljava/lang/String;Ljava/util/Set;Ljava/util/List;)Ljava/security/cert/X509Certificate;", "(Ljava/lang/String;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/security/cert/X509Certificate;", $PRIVATE | $STATIC, $staticMethod(RevocationChecker, getResponderCert, $X509Certificate*, $String*, $Set*, $List*), "java.security.cert.CertPathValidatorException"},
	{"getResponderCert", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Set;Ljava/util/List;)Ljava/security/cert/X509Certificate;", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/security/cert/X509Certificate;", $PRIVATE | $STATIC, $staticMethod(RevocationChecker, getResponderCert, $X509Certificate*, $String*, $String*, $Set*, $List*), "java.security.cert.CertPathValidatorException"},
	{"getResponderCert", "(Ljava/security/cert/X509CertSelector;Ljava/util/Set;Ljava/util/List;)Ljava/security/cert/X509Certificate;", "(Ljava/security/cert/X509CertSelector;Ljava/util/Set<Ljava/security/cert/TrustAnchor;>;Ljava/util/List<Ljava/security/cert/CertStore;>;)Ljava/security/cert/X509Certificate;", $PRIVATE | $STATIC, $staticMethod(RevocationChecker, getResponderCert, $X509Certificate*, $X509CertSelector*, $Set*, $List*), "java.security.cert.CertPathValidatorException"},
	{"getRevocationProperties", "()Lsun/security/provider/certpath/RevocationChecker$RevocationProperties;", nullptr, $PRIVATE | $STATIC, $staticMethod(RevocationChecker, getRevocationProperties, $RevocationChecker$RevocationProperties*)},
	{"getSoftFailExceptions", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/cert/CertPathValidatorException;>;", $PUBLIC, $virtualMethod(RevocationChecker, getSoftFailExceptions, $List*)},
	{"getSupportedExtensions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(RevocationChecker, getSupportedExtensions, $Set*)},
	{"init", "(Ljava/security/cert/TrustAnchor;Lsun/security/provider/certpath/PKIX$ValidatorParams;)V", nullptr, 0, $virtualMethod(RevocationChecker, init, void, $TrustAnchor*, $PKIX$ValidatorParams*), "java.security.cert.CertPathValidatorException"},
	{"init", "(Z)V", nullptr, $PUBLIC, $virtualMethod(RevocationChecker, init, void, bool), "java.security.cert.CertPathValidatorException"},
	{"isCausedByNetworkIssue", "(Ljava/lang/String;Ljava/security/cert/CertStoreException;)Z", nullptr, $STATIC, $staticMethod(RevocationChecker, isCausedByNetworkIssue, bool, $String*, $CertStoreException*)},
	{"isForwardCheckingSupported", "()Z", nullptr, $PUBLIC, $virtualMethod(RevocationChecker, isForwardCheckingSupported, bool)},
	{"isSoftFailException", "(Ljava/security/cert/CertPathValidatorException;)Z", nullptr, $PRIVATE, $method(RevocationChecker, isSoftFailException, bool, $CertPathValidatorException*)},
	{"stripOutSeparators", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(RevocationChecker, stripOutSeparators, $String*, $String*)},
	{"toURI", "(Ljava/lang/String;)Ljava/net/URI;", nullptr, $PRIVATE | $STATIC, $staticMethod(RevocationChecker, toURI, $URI*, $String*), "java.security.cert.CertPathValidatorException"},
	{"updateState", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PRIVATE, $method(RevocationChecker, updateState, void, $X509Certificate*), "java.security.cert.CertPathValidatorException"},
	{"verifyPossibleCRLs", "(Ljava/util/Set;Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;Z[ZLjava/util/Set;)Ljava/util/Collection;", "(Ljava/util/Set<Ljava/security/cert/X509CRL;>;Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;Z[ZLjava/util/Set<Ljava/security/cert/TrustAnchor;>;)Ljava/util/Collection<Ljava/security/cert/X509CRL;>;", $PRIVATE, $method(RevocationChecker, verifyPossibleCRLs, $Collection*, $Set*, $X509Certificate*, $PublicKey*, bool, $booleans*, $Set*), "java.security.cert.CertPathValidatorException"},
	{"verifyWithSeparateSigningKey", "(Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;ZLjava/util/Set;)V", "(Ljava/security/cert/X509Certificate;Ljava/security/PublicKey;ZLjava/util/Set<Ljava/security/cert/X509Certificate;>;)V", $PRIVATE, $method(RevocationChecker, verifyWithSeparateSigningKey, void, $X509Certificate*, $PublicKey*, bool, $Set*), "java.security.cert.CertPathValidatorException"},
	{}
};

$InnerClassInfo _RevocationChecker_InnerClassesInfo_[] = {
	{"sun.security.provider.certpath.RevocationChecker$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.security.provider.certpath.RevocationChecker$RejectKeySelector", "sun.security.provider.certpath.RevocationChecker", "RejectKeySelector", $PRIVATE | $STATIC},
	{"sun.security.provider.certpath.RevocationChecker$RevocationProperties", "sun.security.provider.certpath.RevocationChecker", "RevocationProperties", $PRIVATE | $STATIC},
	{"sun.security.provider.certpath.RevocationChecker$Mode", "sun.security.provider.certpath.RevocationChecker", "Mode", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{"sun.security.provider.certpath.RevocationChecker$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RevocationChecker_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.certpath.RevocationChecker",
	"java.security.cert.PKIXRevocationChecker",
	nullptr,
	_RevocationChecker_FieldInfo_,
	_RevocationChecker_MethodInfo_,
	nullptr,
	nullptr,
	_RevocationChecker_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.certpath.RevocationChecker$2,sun.security.provider.certpath.RevocationChecker$RejectKeySelector,sun.security.provider.certpath.RevocationChecker$RevocationProperties,sun.security.provider.certpath.RevocationChecker$Mode,sun.security.provider.certpath.RevocationChecker$1"
};

$Object* allocate$RevocationChecker($Class* clazz) {
	return $of($alloc(RevocationChecker));
}

$Debug* RevocationChecker::debug = nullptr;
$booleans* RevocationChecker::ALL_REASONS = nullptr;
$booleans* RevocationChecker::CRL_SIGN_USAGE = nullptr;

void RevocationChecker::init$() {
	$PKIXRevocationChecker::init$();
	$set(this, softFailExceptions, $new($LinkedList));
	$init($RevocationChecker$Mode);
	$set(this, mode, $RevocationChecker$Mode::PREFER_OCSP);
	this->legacy = false;
}

void RevocationChecker::init$($TrustAnchor* anchor, $PKIX$ValidatorParams* params) {
	$PKIXRevocationChecker::init$();
	$set(this, softFailExceptions, $new($LinkedList));
	$init($RevocationChecker$Mode);
	$set(this, mode, $RevocationChecker$Mode::PREFER_OCSP);
	this->legacy = true;
	init(anchor, params);
}

void RevocationChecker::init($TrustAnchor* anchor, $PKIX$ValidatorParams* params) {
	$useLocalCurrentObjectStackCache();
	$set(this, rp, getRevocationProperties());
	$var($URI, uri, getOcspResponder());
	$set(this, responderURI, (uri == nullptr) ? toURI($nc(this->rp)->ocspUrl) : uri);
	$var($X509Certificate, cert, getOcspResponderCert());
	$var($X509Certificate, var$0, nullptr);
	if (cert == nullptr) {
		$var($RevocationChecker$RevocationProperties, var$1, this->rp);
		$var($Set, var$2, $nc(params)->trustAnchors());
		$assign(var$0, getResponderCert(var$1, var$2, $(params->certStores())));
	} else {
		$assign(var$0, cert);
	}
	$set(this, responderCert, var$0);
	$var($Set, options, getOptions());
	{
		$var($Iterator, i$, $nc(options)->iterator());
		for (; $nc(i$)->hasNext();) {
			$PKIXRevocationChecker$Option* option = $cast($PKIXRevocationChecker$Option, i$->next());
			{
				$init($RevocationChecker$2);
				switch ($nc($RevocationChecker$2::$SwitchMap$java$security$cert$PKIXRevocationChecker$Option)->get($nc((option))->ordinal())) {
				case 1:
					{}
				case 2:
					{}
				case 3:
					{}
				case 4:
					{
						break;
					}
				default:
					{
						$throwNew($CertPathValidatorException, $$str({"Unrecognized revocation parameter option: "_s, option}));
					}
				}
			}
		}
	}
	$init($PKIXRevocationChecker$Option);
	this->softFail = options->contains($PKIXRevocationChecker$Option::SOFT_FAIL);
	if (this->legacy) {
		$init($RevocationChecker$Mode);
		$set(this, mode, ($nc(this->rp)->ocspEnabled) ? $RevocationChecker$Mode::PREFER_OCSP : $RevocationChecker$Mode::ONLY_CRLS);
		this->onlyEE = $nc(this->rp)->onlyEE;
	} else {
		if (options->contains($PKIXRevocationChecker$Option::NO_FALLBACK)) {
			if (options->contains($PKIXRevocationChecker$Option::PREFER_CRLS)) {
				$init($RevocationChecker$Mode);
				$set(this, mode, $RevocationChecker$Mode::ONLY_CRLS);
			} else {
				$init($RevocationChecker$Mode);
				$set(this, mode, $RevocationChecker$Mode::ONLY_OCSP);
			}
		} else {
			if (options->contains($PKIXRevocationChecker$Option::PREFER_CRLS)) {
				$init($RevocationChecker$Mode);
				$set(this, mode, $RevocationChecker$Mode::PREFER_CRLS);
			}
		}
		this->onlyEE = options->contains($PKIXRevocationChecker$Option::ONLY_END_ENTITY);
	}
	if (this->legacy) {
		this->crlDP = $nc(this->rp)->crlDPEnabled;
	} else {
		this->crlDP = true;
	}
	$set(this, ocspResponses, getOcspResponses());
	$set(this, ocspExtensions, getOcspExtensions());
	$set(this, anchor, anchor);
	$set(this, params, params);
	$set(this, certStores, $new($ArrayList, $(static_cast<$Collection*>($nc(params)->certStores()))));
	try {
		$nc(this->certStores)->add($($CertStore::getInstance("Collection"_s, $$new($CollectionCertStoreParameters, $($nc(params)->certificates())))));
	} catch ($InvalidAlgorithmParameterException& e) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println($$str({"RevocationChecker: error creating Collection CertStore: "_s, e}));
		}
	} catch ($NoSuchAlgorithmException& e) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println($$str({"RevocationChecker: error creating Collection CertStore: "_s, e}));
		}
	}
}

$URI* RevocationChecker::toURI($String* uriString) {
	$init(RevocationChecker);
	try {
		if (uriString != nullptr) {
			return $new($URI, uriString);
		}
		return nullptr;
	} catch ($URISyntaxException& e) {
		$throwNew($CertPathValidatorException, "cannot parse ocsp.responderURL property"_s, e);
	}
	$shouldNotReachHere();
}

$RevocationChecker$RevocationProperties* RevocationChecker::getRevocationProperties() {
	$init(RevocationChecker);
	$beforeCallerSensitive();
	return $cast($RevocationChecker$RevocationProperties, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RevocationChecker$1))));
}

$X509Certificate* RevocationChecker::getResponderCert($RevocationChecker$RevocationProperties* rp, $Set* anchors, $List* stores) {
	$init(RevocationChecker);
	if ($nc(rp)->ocspSubject != nullptr) {
		return getResponderCert(rp->ocspSubject, anchors, stores);
	} else if (rp->ocspIssuer != nullptr && rp->ocspSerial != nullptr) {
		return getResponderCert(rp->ocspIssuer, rp->ocspSerial, anchors, stores);
	} else if (rp->ocspIssuer != nullptr || rp->ocspSerial != nullptr) {
		$throwNew($CertPathValidatorException, "Must specify both ocsp.responderCertIssuerName and ocsp.responderCertSerialNumber properties"_s);
	}
	return nullptr;
}

$X509Certificate* RevocationChecker::getResponderCert($String* subject, $Set* anchors, $List* stores) {
	$init(RevocationChecker);
	$useLocalCurrentObjectStackCache();
	$var($X509CertSelector, sel, $new($X509CertSelector));
	try {
		sel->setSubject($$new($X500Principal, subject));
	} catch ($IllegalArgumentException& e) {
		$throwNew($CertPathValidatorException, "cannot parse ocsp.responderCertSubjectName property"_s, e);
	}
	return getResponderCert(sel, anchors, stores);
}

$X509Certificate* RevocationChecker::getResponderCert($String* issuer, $String* serial, $Set* anchors, $List* stores) {
	$init(RevocationChecker);
	$useLocalCurrentObjectStackCache();
	$var($X509CertSelector, sel, $new($X509CertSelector));
	try {
		sel->setIssuer($$new($X500Principal, issuer));
	} catch ($IllegalArgumentException& e) {
		$throwNew($CertPathValidatorException, "cannot parse ocsp.responderCertIssuerName property"_s, e);
	}
	try {
		sel->setSerialNumber($$new($BigInteger, $(stripOutSeparators(serial)), 16));
	} catch ($NumberFormatException& e) {
		$throwNew($CertPathValidatorException, "cannot parse ocsp.responderCertSerialNumber property"_s, e);
	}
	return getResponderCert(sel, anchors, stores);
}

$X509Certificate* RevocationChecker::getResponderCert($X509CertSelector* sel, $Set* anchors, $List* stores) {
	$init(RevocationChecker);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(anchors)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TrustAnchor, anchor, $cast($TrustAnchor, i$->next()));
			{
				$var($X509Certificate, cert, $nc(anchor)->getTrustedCert());
				if (cert == nullptr) {
					continue;
				}
				if ($nc(sel)->match(cert)) {
					return cert;
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc(stores)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertStore, store, $cast($CertStore, i$->next()));
			{
				try {
					$var($Collection, certs, $nc(store)->getCertificates(sel));
					if (!$nc(certs)->isEmpty()) {
						return $cast($X509Certificate, $nc($(certs->iterator()))->next());
					}
				} catch ($CertStoreException& e) {
					if (RevocationChecker::debug != nullptr) {
						$nc(RevocationChecker::debug)->println($$str({"CertStore exception:"_s, e}));
					}
					continue;
				}
			}
		}
	}
	$throwNew($CertPathValidatorException, "Cannot find the responder\'s certificate (set using the OCSP security properties)."_s);
	$shouldNotReachHere();
}

void RevocationChecker::init(bool forward) {
	$useLocalCurrentObjectStackCache();
	if (forward) {
		$throwNew($CertPathValidatorException, "forward checking not supported"_s);
	}
	if (this->anchor != nullptr) {
		$set(this, issuerInfo, $new($OCSPResponse$IssuerInfo, this->anchor));
		$set(this, prevPubKey, $nc(this->issuerInfo)->getPublicKey());
	}
	this->crlSignFlag = true;
	if (this->params != nullptr && $nc(this->params)->certPath() != nullptr) {
		this->certIndex = $nc($($nc($($nc(this->params)->certPath()))->getCertificates()))->size() - 1;
	} else {
		this->certIndex = -1;
	}
	$nc(this->softFailExceptions)->clear();
}

bool RevocationChecker::isForwardCheckingSupported() {
	return false;
}

$Set* RevocationChecker::getSupportedExtensions() {
	return nullptr;
}

$List* RevocationChecker::getSoftFailExceptions() {
	return $Collections::unmodifiableList(this->softFailExceptions);
}

void RevocationChecker::check($Certificate* cert, $Collection* unresolvedCritExts) {
	check($cast($X509Certificate, cert), unresolvedCritExts, this->prevPubKey, this->crlSignFlag);
}

void RevocationChecker::check($X509Certificate* xcert, $Collection* unresolvedCritExts, $PublicKey* pubKey, bool crlSignFlag) {
	$useLocalCurrentObjectStackCache();
	if (RevocationChecker::debug != nullptr) {
		$var($String, var$2, $$str({"RevocationChecker.check: checking cert\n  SN: "_s, $($Debug::toHexString($($nc(xcert)->getSerialNumber()))), "\n  Subject: "_s}));
		$var($String, var$1, $$concat(var$2, $($nc(xcert)->getSubjectX500Principal())));
		$var($String, var$0, $$concat(var$1, "\n  Issuer: "_s));
		$nc(RevocationChecker::debug)->println($$concat(var$0, $(xcert->getIssuerX500Principal())));
	}
	{
		$var($Throwable, var$3, nullptr);
		bool return$4 = false;
		try {
			try {
				if (this->onlyEE && $nc(xcert)->getBasicConstraints() != -1) {
					if (RevocationChecker::debug != nullptr) {
						$nc(RevocationChecker::debug)->println("Skipping revocation check; cert is not an end entity cert"_s);
					}
					return$4 = true;
					goto $finally;
				}
				$init($RevocationChecker$2);
				switch ($nc($RevocationChecker$2::$SwitchMap$sun$security$provider$certpath$RevocationChecker$Mode)->get($nc((this->mode))->ordinal())) {
				case 1:
					{}
				case 2:
					{
						checkOCSP(xcert, unresolvedCritExts);
						break;
					}
				case 3:
					{}
				case 4:
					{
						checkCRLs(xcert, unresolvedCritExts, nullptr, pubKey, crlSignFlag);
						break;
					}
				}
			} catch ($CertPathValidatorException& e) {
				$init($CertPathValidatorException$BasicReason);
				if ($equals(e->getReason(), $CertPathValidatorException$BasicReason::REVOKED)) {
					$throw(e);
				}
				bool eSoftFail = isSoftFailException(e);
				if (eSoftFail) {
					$init($RevocationChecker$Mode);
					if (this->mode == $RevocationChecker$Mode::ONLY_OCSP || this->mode == $RevocationChecker$Mode::ONLY_CRLS) {
						return$4 = true;
						goto $finally;
					}
				} else {
					$init($RevocationChecker$Mode);
					if (this->mode == $RevocationChecker$Mode::ONLY_OCSP || this->mode == $RevocationChecker$Mode::ONLY_CRLS) {
						$throw(e);
					}
				}
				$var($CertPathValidatorException, cause, e);
				if (RevocationChecker::debug != nullptr) {
					$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.check() "_s, $(e->getMessage())}));
					$nc(RevocationChecker::debug)->println("RevocationChecker.check() preparing to failover"_s);
				}
				try {
					$init($RevocationChecker$2);
					switch ($nc($RevocationChecker$2::$SwitchMap$sun$security$provider$certpath$RevocationChecker$Mode)->get($nc((this->mode))->ordinal())) {
					case 1:
						{
							checkCRLs(xcert, unresolvedCritExts, nullptr, pubKey, crlSignFlag);
							break;
						}
					case 3:
						{
							checkOCSP(xcert, unresolvedCritExts);
							break;
						}
					}
				} catch ($CertPathValidatorException& x) {
					if (RevocationChecker::debug != nullptr) {
						$nc(RevocationChecker::debug)->println("RevocationChecker.check() failover failed"_s);
						$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.check() "_s, $(x->getMessage())}));
					}
					if ($equals(x->getReason(), $CertPathValidatorException$BasicReason::REVOKED)) {
						$throw(x);
					}
					if (!isSoftFailException(x)) {
						cause->addSuppressed(x);
						$throw(cause);
					} else if (!eSoftFail) {
						$throw(cause);
					}
				}
			}
		} catch ($Throwable& var$5) {
			$assign(var$3, var$5);
		} $finally: {
			updateState(xcert);
		}
		if (var$3 != nullptr) {
			$throw(var$3);
		}
		if (return$4) {
			return;
		}
	}
}

bool RevocationChecker::isSoftFailException($CertPathValidatorException* e) {
	$useLocalCurrentObjectStackCache();
	$init($CertPathValidatorException$BasicReason);
	if (this->softFail && $equals($nc(e)->getReason(), $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS)) {
		$var($String, var$0, e->getMessage());
		$var($Throwable, var$1, e->getCause());
		$var($CertPath, var$2, $nc(this->params)->certPath());
		int32_t var$3 = this->certIndex;
		$var($CertPathValidatorException, e2, $new($CertPathValidatorException, var$0, var$1, var$2, var$3, $(e->getReason())));
		$nc(this->softFailExceptions)->addFirst(e2);
		return true;
	}
	return false;
}

void RevocationChecker::updateState($X509Certificate* cert) {
	$set(this, issuerInfo, $new($OCSPResponse$IssuerInfo, this->anchor, cert));
	$var($PublicKey, pubKey, $nc(cert)->getPublicKey());
	if ($PKIX::isDSAPublicKeyWithoutParams(pubKey)) {
		$assign(pubKey, $BasicChecker::makeInheritedParamsKey(pubKey, this->prevPubKey));
	}
	$set(this, prevPubKey, pubKey);
	this->crlSignFlag = certCanSignCrl(cert);
	if (this->certIndex > 0) {
		--this->certIndex;
	}
}

void RevocationChecker::checkCRLs($X509Certificate* cert, $Collection* unresolvedCritExts, $Set* stackedCerts, $PublicKey* pubKey, bool signFlag) {
	checkCRLs(cert, pubKey, nullptr, signFlag, true, stackedCerts, $($nc(this->params)->trustAnchors()));
}

bool RevocationChecker::isCausedByNetworkIssue($String* type, $CertStoreException* cse) {
	$init(RevocationChecker);
	$useLocalCurrentObjectStackCache();
	bool result = false;
	$var($Throwable, t, $nc(cse)->getCause());
	{
		$var($String, s18116$, type);
		int32_t tmp18116$ = -1;
		switch ($nc(s18116$)->hashCode()) {
		case 0x002393A7:
			{
				if (s18116$->equals("LDAP"_s)) {
					tmp18116$ = 0;
				}
				break;
			}
		case 0x07F23C4F:
			{
				if (s18116$->equals("SSLServer"_s)) {
					tmp18116$ = 1;
				}
				break;
			}
		case 0x0001494C:
			{
				if (s18116$->equals("URI"_s)) {
					tmp18116$ = 2;
				}
				break;
			}
		}
		switch (tmp18116$) {
		case 0:
			{
				if (t != nullptr) {
					$var($String, cn, $of(t)->getClass()->getName());
					bool var$0 = $nc(cn)->equals("javax.naming.ServiceUnavailableException"_s);
					result = (var$0 || $nc(cn)->equals("javax.naming.CommunicationException"_s));
				} else {
					result = false;
				}
				break;
			}
		case 1:
			{
				result = (t != nullptr && $instanceOf($IOException, t));
				break;
			}
		case 2:
			{
				result = (t != nullptr && $instanceOf($IOException, t));
				break;
			}
		default:
			{
				return false;
			}
		}
	}
	return result;
}

void RevocationChecker::checkCRLs($X509Certificate* cert, $PublicKey* prevKey, $X509Certificate* prevCert, bool signFlag, bool allowSeparateKey, $Set* stackedCerts, $Set* anchors) {
	$useLocalCurrentObjectStackCache();
	if (RevocationChecker::debug != nullptr) {
		$nc(RevocationChecker::debug)->println("RevocationChecker.checkCRLs() ---checking revocation status ..."_s);
	}
	if (stackedCerts != nullptr && stackedCerts->contains(cert)) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println("RevocationChecker.checkCRLs() circular dependency"_s);
		}
		$init($CertPathValidatorException$BasicReason);
		$throwNew($CertPathValidatorException, "Could not determine revocation status"_s, nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
	}
	$var($Set, possibleCRLs, $new($HashSet));
	$var($Set, approvedCRLs, $new($HashSet));
	$var($X509CRLSelector, sel, $new($X509CRLSelector));
	sel->setCertificateChecking(cert);
	$CertPathHelper::setDateAndTime(sel, $($nc(this->params)->date()), RevocationChecker::MAX_CLOCK_SKEW);
	$var($CertPathValidatorException, networkFailureException, nullptr);
	{
		$var($Iterator, i$, $nc(this->certStores)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertStore, store, $cast($CertStore, i$->next()));
			{
				try {
					{
						$var($Iterator, i$, $nc($($nc(store)->getCRLs(sel)))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($CRL, crl, $cast($CRL, i$->next()));
							{
								possibleCRLs->add($cast($X509CRL, crl));
							}
						}
					}
				} catch ($CertStoreException& e) {
					if (RevocationChecker::debug != nullptr) {
						$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.checkCRLs() CertStoreException: "_s, $(e->getMessage())}));
					}
					if (networkFailureException == nullptr && isCausedByNetworkIssue($($nc(store)->getType()), e)) {
						$init($CertPathValidatorException$BasicReason);
						$assign(networkFailureException, $new($CertPathValidatorException, "Unable to determine revocation status due to network error"_s, e, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS));
					}
				}
			}
		}
	}
	if (RevocationChecker::debug != nullptr) {
		$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.checkCRLs() possible crls.size() = "_s, $$str(possibleCRLs->size())}));
	}
	$var($booleans, reasonsMask, $new($booleans, 9));
	if (!possibleCRLs->isEmpty()) {
		approvedCRLs->addAll($(verifyPossibleCRLs(possibleCRLs, cert, prevKey, signFlag, reasonsMask, anchors)));
	}
	if (RevocationChecker::debug != nullptr) {
		$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.checkCRLs() approved crls.size() = "_s, $$str(approvedCRLs->size())}));
	}
	bool var$0 = !approvedCRLs->isEmpty();
	if (var$0 && $Arrays::equals(reasonsMask, RevocationChecker::ALL_REASONS)) {
		checkApprovedCRLs(cert, approvedCRLs);
	} else {
		try {
			if (this->crlDP) {
				$var($X509CRLSelector, var$1, sel);
				bool var$2 = signFlag;
				$var($PublicKey, var$3, prevKey);
				$var($X509Certificate, var$4, prevCert);
				$var($String, var$5, $nc(this->params)->sigProvider());
				$var($List, var$6, this->certStores);
				$var($booleans, var$7, reasonsMask);
				$var($Set, var$8, anchors);
				approvedCRLs->addAll($($DistributionPointFetcher::getCRLs(var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, nullptr, $($nc(this->params)->variant()), this->anchor)));
			}
		} catch ($CertStoreException& e) {
			if ($instanceOf($PKIX$CertStoreTypeException, e)) {
				$var($PKIX$CertStoreTypeException, cste, $cast($PKIX$CertStoreTypeException, e));
				if (isCausedByNetworkIssue($(cste->getType()), e)) {
					$init($CertPathValidatorException$BasicReason);
					$throwNew($CertPathValidatorException, "Unable to determine revocation status due to network error"_s, e, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
				}
			}
			$throwNew($CertPathValidatorException, static_cast<$Throwable*>(e));
		}
		bool var$9 = !approvedCRLs->isEmpty();
		if (var$9 && $Arrays::equals(reasonsMask, RevocationChecker::ALL_REASONS)) {
			checkApprovedCRLs(cert, approvedCRLs);
		} else if (allowSeparateKey) {
			try {
				verifyWithSeparateSigningKey(cert, prevKey, signFlag, stackedCerts);
				return;
			} catch ($CertPathValidatorException& cpve) {
				if (networkFailureException != nullptr) {
					$throw(networkFailureException);
				}
				$throw(cpve);
			}
		} else {
			if (networkFailureException != nullptr) {
				$throw(networkFailureException);
			}
			$init($CertPathValidatorException$BasicReason);
			$throwNew($CertPathValidatorException, "Could not determine revocation status"_s, nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
		}
	}
}

void RevocationChecker::checkApprovedCRLs($X509Certificate* cert, $Set* approvedCRLs) {
	$useLocalCurrentObjectStackCache();
	if (RevocationChecker::debug != nullptr) {
		$var($BigInteger, sn, $nc(cert)->getSerialNumber());
		$nc(RevocationChecker::debug)->println("RevocationChecker.checkApprovedCRLs() starting the final sweep..."_s);
		$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.checkApprovedCRLs() cert SN: "_s, $($nc(sn)->toString())}));
	}
	$init($CRLReason);
	$CRLReason* reasonCode = $CRLReason::UNSPECIFIED;
	$var($X509CRLEntryImpl, entry, nullptr);
	{
		$var($Iterator, i$, $nc(approvedCRLs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509CRL, crl, $cast($X509CRL, i$->next()));
			{
				$var($X509CRLEntry, e, $nc(crl)->getRevokedCertificate(cert));
				if (e != nullptr) {
					try {
						$assign(entry, $X509CRLEntryImpl::toImpl(e));
					} catch ($CRLException& ce) {
						$throwNew($CertPathValidatorException, static_cast<$Throwable*>(ce));
					}
					if (RevocationChecker::debug != nullptr) {
						$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.checkApprovedCRLs() CRL entry: "_s, $($nc(entry)->toString())}));
					}
					$var($Set, unresCritExts, $nc(entry)->getCriticalExtensionOIDs());
					if (unresCritExts != nullptr && !unresCritExts->isEmpty()) {
						$init($PKIXExtensions);
						unresCritExts->remove($($nc($PKIXExtensions::ReasonCode_Id)->toString()));
						unresCritExts->remove($($nc($PKIXExtensions::CertificateIssuer_Id)->toString()));
						if (!unresCritExts->isEmpty()) {
							$throwNew($CertPathValidatorException, "Unrecognized critical extension(s) in revoked CRL entry"_s);
						}
					}
					reasonCode = entry->getRevocationReason();
					if (reasonCode == nullptr) {
						reasonCode = $CRLReason::UNSPECIFIED;
					}
					$var($Date, revocationDate, entry->getRevocationDate());
					if ($nc(revocationDate)->before($($nc(this->params)->date()))) {
						$var($Date, var$0, revocationDate);
						$var($CRLReason, var$1, reasonCode);
						$var($X500Principal, var$2, crl->getIssuerX500Principal());
						$var($Throwable, t, $new($CertificateRevokedException, var$0, var$1, var$2, $(entry->getExtensions())));
						$init($CertPathValidatorException$BasicReason);
						$throwNew($CertPathValidatorException, $(t->getMessage()), t, nullptr, -1, $CertPathValidatorException$BasicReason::REVOKED);
					}
				}
			}
		}
	}
}

void RevocationChecker::checkOCSP($X509Certificate* cert, $Collection* unresolvedCritExts) {
	$useLocalCurrentObjectStackCache();
	$var($X509CertImpl, currCert, nullptr);
	try {
		$assign(currCert, $X509CertImpl::toImpl(cert));
	} catch ($CertificateException& ce) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(ce));
	}
	$var($OCSPResponse, response, nullptr);
	$var($CertId, certId, nullptr);
	try {
		$var($X500Principal, var$0, $nc(this->issuerInfo)->getName());
		$var($PublicKey, var$1, $nc(this->issuerInfo)->getPublicKey());
		$assign(certId, $new($CertId, var$0, var$1, $($nc(currCert)->getSerialNumberObject())));
		$var($bytes, nonce, nullptr);
		{
			$var($Iterator, i$, $nc(this->ocspExtensions)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Extension, ext, $cast($Extension, i$->next()));
				{
					$init($KnownOIDs);
					if ($nc($($nc(ext)->getId()))->equals($($KnownOIDs::OCSPNonceExt->value()))) {
						$assign(nonce, ext->getValue());
					}
				}
			}
		}
		$var($bytes, responseBytes, $cast($bytes, $nc(this->ocspResponses)->get(cert)));
		if (responseBytes != nullptr) {
			if (RevocationChecker::debug != nullptr) {
				$nc(RevocationChecker::debug)->println("Found cached OCSP response"_s);
			}
			$assign(response, $new($OCSPResponse, responseBytes));
			$var($List, var$2, $Collections::singletonList(certId));
			$var($OCSPResponse$IssuerInfo, var$3, this->issuerInfo);
			$var($X509Certificate, var$4, this->responderCert);
			$var($Date, var$5, $nc(this->params)->date());
			$var($bytes, var$6, nonce);
			response->verify(var$2, var$3, var$4, var$5, var$6, $($nc(this->params)->variant()));
		} else {
			$var($URI, responderURI, (this->responderURI != nullptr) ? this->responderURI : $OCSP::getResponderURI(currCert));
			if (responderURI == nullptr) {
				$throwNew($CertPathValidatorException, "Certificate does not specify OCSP responder"_s, nullptr, nullptr, -1);
			}
			$var($List, tmpExtensions, nullptr);
			if ($nc(this->rp)->ocspNonce) {
				if (nonce == nullptr) {
					try {
						$var($Extension, nonceExt, $new($OCSPNonceExtension, RevocationChecker::DEFAULT_NONCE_BYTES));
						if ($nc(this->ocspExtensions)->size() > 0) {
							$assign(tmpExtensions, $new($ArrayList, static_cast<$Collection*>(this->ocspExtensions)));
							tmpExtensions->add(nonceExt);
						} else {
							$assign(tmpExtensions, $List::of($of(nonceExt)));
						}
						if (RevocationChecker::debug != nullptr) {
							$nc(RevocationChecker::debug)->println("Default nonce has been created in the OCSP extensions"_s);
						}
					} catch ($IOException& e) {
						$throwNew($CertPathValidatorException, "Failed to create the default nonce in OCSP extensions"_s, e);
					}
				} else {
					$throwNew($CertPathValidatorException, "Application provided nonce cannot be used if the value of the jdk.security.certpath.ocspNonce system property is true"_s);
				}
			} else if (nonce != nullptr) {
				if (RevocationChecker::debug != nullptr) {
					$nc(RevocationChecker::debug)->println("Using application provided nonce"_s);
				}
			}
			$var($List, var$7, $Collections::singletonList(certId));
			$var($URI, var$8, responderURI);
			$var($OCSPResponse$IssuerInfo, var$9, this->issuerInfo);
			$var($X509Certificate, var$10, this->responderCert);
			$var($List, var$11, $nc(this->rp)->ocspNonce ? tmpExtensions : this->ocspExtensions);
			$assign(response, $OCSP::check(var$7, var$8, var$9, var$10, ($Date*)nullptr, var$11, $($nc(this->params)->variant())));
		}
	} catch ($IOException& e) {
		$init($CertPathValidatorException$BasicReason);
		$throwNew($CertPathValidatorException, "Unable to determine revocation status due to network error"_s, e, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
	}
	$var($OCSP$RevocationStatus, rs, static_cast<$OCSP$RevocationStatus*>($nc(response)->getSingleResponse(certId)));
	$OCSP$RevocationStatus$CertStatus* certStatus = $nc(rs)->getCertStatus();
	$init($OCSP$RevocationStatus$CertStatus);
	if (certStatus == $OCSP$RevocationStatus$CertStatus::REVOKED) {
		$var($Date, revocationTime, rs->getRevocationTime());
		if ($nc(revocationTime)->before($($nc(this->params)->date()))) {
			$var($Date, var$12, revocationTime);
			$var($CRLReason, var$13, rs->getRevocationReason());
			$var($X500Principal, var$14, $nc($(response->getSignerCertificate()))->getSubjectX500Principal());
			$var($Throwable, t, $new($CertificateRevokedException, var$12, var$13, var$14, $(rs->getSingleExtensions())));
			$init($CertPathValidatorException$BasicReason);
			$throwNew($CertPathValidatorException, $(t->getMessage()), t, nullptr, -1, $CertPathValidatorException$BasicReason::REVOKED);
		}
	} else {
		if (certStatus == $OCSP$RevocationStatus$CertStatus::UNKNOWN) {
			$init($CertPathValidatorException$BasicReason);
			$throwNew($CertPathValidatorException, "Certificate\'s revocation status is unknown"_s, nullptr, $($nc(this->params)->certPath()), -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
		}
	}
}

$String* RevocationChecker::stripOutSeparators($String* value) {
	$init(RevocationChecker);
	$useLocalCurrentObjectStackCache();
	$var($chars, chars, $nc(value)->toCharArray());
	$var($StringBuilder, hexNumber, $new($StringBuilder));
	for (int32_t i = 0; i < chars->length; ++i) {
		if ($HexFormat::isHexDigit(chars->get(i))) {
			hexNumber->append(chars->get(i));
		}
	}
	return hexNumber->toString();
}

bool RevocationChecker::certCanSignCrl($X509Certificate* cert) {
	$init(RevocationChecker);
	$var($booleans, keyUsage, $nc(cert)->getKeyUsage());
	if (keyUsage != nullptr) {
		return keyUsage->get(6);
	}
	return false;
}

$Collection* RevocationChecker::verifyPossibleCRLs($Set* crls, $X509Certificate* cert, $PublicKey* prevKey, bool signFlag, $booleans* reasonsMask, $Set* anchors) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($X509CertImpl, certImpl, $X509CertImpl::toImpl(cert));
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.verifyPossibleCRLs: Checking CRLDPs for "_s, $($nc(certImpl)->getSubjectX500Principal())}));
		}
		$var($CRLDistributionPointsExtension, ext, $nc(certImpl)->getCRLDistributionPointsExtension());
		$var($List, points, nullptr);
		if (ext == nullptr) {
			$var($X500Name, certIssuer, $cast($X500Name, certImpl->getIssuerDN()));
			$var($DistributionPoint, point, $new($DistributionPoint, $($$new($GeneralNames)->add($$new($GeneralName, static_cast<$GeneralNameInterface*>(certIssuer)))), ($booleans*)nullptr, ($GeneralNames*)nullptr));
			$assign(points, $Collections::singletonList(point));
		} else {
			$init($CRLDistributionPointsExtension);
			$assign(points, $cast($List, $nc(ext)->get($CRLDistributionPointsExtension::POINTS)));
		}
		$var($Set, results, $new($HashSet));
		{
			$var($Iterator, i$, $nc(points)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($DistributionPoint, point, $cast($DistributionPoint, i$->next()));
				{
					{
						$var($Iterator, i$, $nc(crls)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($X509CRL, crl, $cast($X509CRL, i$->next()));
							{
								$var($X509CertImpl, var$0, certImpl);
								$var($DistributionPoint, var$1, point);
								$var($X509CRL, var$2, crl);
								$var($booleans, var$3, reasonsMask);
								bool var$4 = signFlag;
								$var($PublicKey, var$5, prevKey);
								$var($String, var$6, $nc(this->params)->sigProvider());
								$var($Set, var$7, anchors);
								$var($List, var$8, this->certStores);
								$var($Date, var$9, $nc(this->params)->date());
								if ($DistributionPointFetcher::verifyCRL(var$0, var$1, var$2, var$3, var$4, var$5, nullptr, var$6, var$7, var$8, var$9, $($nc(this->params)->variant()), this->anchor)) {
									results->add(crl);
								}
							}
						}
					}
					if ($Arrays::equals(reasonsMask, RevocationChecker::ALL_REASONS)) {
						break;
					}
				}
			}
		}
		return results;
	} catch ($CertificateException& e) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println($$str({"Exception while verifying CRL: "_s, $(e->getMessage())}));
			e->printStackTrace();
		}
		return $Collections::emptySet();
	} catch ($CRLException& e) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println($$str({"Exception while verifying CRL: "_s, $(e->getMessage())}));
			e->printStackTrace();
		}
		return $Collections::emptySet();
	} catch ($IOException& e) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println($$str({"Exception while verifying CRL: "_s, $(e->getMessage())}));
			e->printStackTrace();
		}
		return $Collections::emptySet();
	}
	$shouldNotReachHere();
}

void RevocationChecker::verifyWithSeparateSigningKey($X509Certificate* cert, $PublicKey* prevKey, bool signFlag, $Set* stackedCerts) {
	$useLocalCurrentObjectStackCache();
	$var($String, msg, "revocation status"_s);
	if (RevocationChecker::debug != nullptr) {
		$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.verifyWithSeparateSigningKey() ---checking "_s, msg, "..."_s}));
	}
	if ((stackedCerts != nullptr) && stackedCerts->contains(cert)) {
		if (RevocationChecker::debug != nullptr) {
			$nc(RevocationChecker::debug)->println("RevocationChecker.verifyWithSeparateSigningKey() circular dependency"_s);
		}
		$init($CertPathValidatorException$BasicReason);
		$throwNew($CertPathValidatorException, "Could not determine revocation status"_s, nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
	}
	if (!signFlag) {
		buildToNewKey(cert, nullptr, stackedCerts);
	} else {
		buildToNewKey(cert, prevKey, stackedCerts);
	}
}

void RevocationChecker::buildToNewKey($X509Certificate* currCert, $PublicKey* prevKey, $Set* stackedCerts$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Set, stackedCerts, stackedCerts$renamed);
	if (RevocationChecker::debug != nullptr) {
		$nc(RevocationChecker::debug)->println("RevocationChecker.buildToNewKey() starting work"_s);
	}
	$var($Set, badKeys, $new($HashSet));
	if (prevKey != nullptr) {
		badKeys->add(prevKey);
	}
	$var($X509CertSelector, certSel, $new($RevocationChecker$RejectKeySelector, badKeys));
	certSel->setSubject($($nc(currCert)->getIssuerX500Principal()));
	certSel->setKeyUsage(RevocationChecker::CRL_SIGN_USAGE);
	$var($Set, newAnchors, this->anchor == nullptr ? $nc(this->params)->trustAnchors() : $Collections::singleton(this->anchor));
	$var($PKIXBuilderParameters, builderParams, nullptr);
	try {
		$assign(builderParams, $new($PKIXBuilderParameters, newAnchors, static_cast<$CertSelector*>(certSel)));
	} catch ($InvalidAlgorithmParameterException& iape) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(iape));
	}
	$nc(builderParams)->setInitialPolicies($($nc(this->params)->initialPolicies()));
	builderParams->setCertStores(this->certStores);
	builderParams->setExplicitPolicyRequired($nc(this->params)->explicitPolicyRequired());
	builderParams->setPolicyMappingInhibited($nc(this->params)->policyMappingInhibited());
	builderParams->setAnyPolicyInhibited($nc(this->params)->anyPolicyInhibited());
	builderParams->setDate($($nc(this->params)->date()));
	builderParams->setCertPathCheckers($($nc(this->params)->certPathCheckers()));
	builderParams->setSigProvider($($nc(this->params)->sigProvider()));
	builderParams->setRevocationEnabled(false);
	$init($Builder);
	if ($Builder::USE_AIA == true) {
		$var($X509CertImpl, currCertImpl, nullptr);
		try {
			$assign(currCertImpl, $X509CertImpl::toImpl(currCert));
		} catch ($CertificateException& ce) {
			if (RevocationChecker::debug != nullptr) {
				$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.buildToNewKey: error decoding cert: "_s, ce}));
			}
		}
		$var($AuthorityInfoAccessExtension, aiaExt, nullptr);
		if (currCertImpl != nullptr) {
			$assign(aiaExt, currCertImpl->getAuthorityInfoAccessExtension());
		}
		if (aiaExt != nullptr) {
			$var($List, adList, aiaExt->getAccessDescriptions());
			if (adList != nullptr) {
				{
					$var($Iterator, i$, adList->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($AccessDescription, ad, $cast($AccessDescription, i$->next()));
						{
							$var($CertStore, cs, $URICertStore::getInstance(ad));
							if (cs != nullptr) {
								if (RevocationChecker::debug != nullptr) {
									$nc(RevocationChecker::debug)->println("adding AIAext CertStore"_s);
								}
								builderParams->addCertStore(cs);
							}
						}
					}
				}
			}
		}
	}
	$var($CertPathBuilder, builder, nullptr);
	try {
		$assign(builder, $CertPathBuilder::getInstance("PKIX"_s));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($CertPathValidatorException, static_cast<$Throwable*>(nsae));
	}
	while (true) {
		try {
			if (RevocationChecker::debug != nullptr) {
				$nc(RevocationChecker::debug)->println("RevocationChecker.buildToNewKey() about to try build ..."_s);
			}
			$var($PKIXCertPathBuilderResult, cpbr, $cast($PKIXCertPathBuilderResult, $nc(builder)->build(builderParams)));
			if (RevocationChecker::debug != nullptr) {
				$nc(RevocationChecker::debug)->println("RevocationChecker.buildToNewKey() about to check revocation ..."_s);
			}
			if (stackedCerts == nullptr) {
				$assign(stackedCerts, $new($HashSet));
			}
			$nc(stackedCerts)->add(currCert);
			$var($TrustAnchor, ta, $nc(cpbr)->getTrustAnchor());
			$var($PublicKey, prevKey2, $nc(ta)->getCAPublicKey());
			if (prevKey2 == nullptr) {
				$assign(prevKey2, $nc($(ta->getTrustedCert()))->getPublicKey());
			}
			bool signFlag = true;
			$var($List, cpList, $nc($(cpbr->getCertPath()))->getCertificates());
			try {
				for (int32_t i = $nc(cpList)->size() - 1; i >= 0; --i) {
					$var($X509Certificate, cert, $cast($X509Certificate, cpList->get(i)));
					if (RevocationChecker::debug != nullptr) {
						$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.buildToNewKey() index "_s, $$str(i), " checking "_s, cert}));
					}
					checkCRLs(cert, prevKey2, nullptr, signFlag, true, stackedCerts, newAnchors);
					signFlag = certCanSignCrl(cert);
					$assign(prevKey2, $nc(cert)->getPublicKey());
				}
			} catch ($CertPathValidatorException& cpve) {
				badKeys->add($(cpbr->getPublicKey()));
				continue;
			}
			if (RevocationChecker::debug != nullptr) {
				$nc(RevocationChecker::debug)->println($$str({"RevocationChecker.buildToNewKey() got key "_s, $(cpbr->getPublicKey())}));
			}
			$var($PublicKey, newKey, cpbr->getPublicKey());
			$var($X509Certificate, newCert, $nc(cpList)->isEmpty() ? ($X509Certificate*)nullptr : $cast($X509Certificate, $nc(cpList)->get(0)));
			try {
				checkCRLs(currCert, newKey, newCert, true, false, nullptr, $($nc(this->params)->trustAnchors()));
				return;
			} catch ($CertPathValidatorException& cpve) {
				$init($CertPathValidatorException$BasicReason);
				if ($equals(cpve->getReason(), $CertPathValidatorException$BasicReason::REVOKED)) {
					$throw(cpve);
				}
			}
			badKeys->add(newKey);
		} catch ($InvalidAlgorithmParameterException& iape) {
			$throwNew($CertPathValidatorException, static_cast<$Throwable*>(iape));
		} catch ($CertPathBuilderException& cpbe) {
			$init($CertPathValidatorException$BasicReason);
			$throwNew($CertPathValidatorException, "Could not determine revocation status"_s, nullptr, nullptr, -1, $CertPathValidatorException$BasicReason::UNDETERMINED_REVOCATION_STATUS);
		}
	}
}

void clinit$RevocationChecker($Class* class$) {
	$assignStatic(RevocationChecker::debug, $Debug::getInstance("certpath"_s));
	$assignStatic(RevocationChecker::ALL_REASONS, $new($booleans, {
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true
	}));
	$assignStatic(RevocationChecker::CRL_SIGN_USAGE, $new($booleans, {
		false,
		false,
		false,
		false,
		false,
		false,
		true
	}));
}

RevocationChecker::RevocationChecker() {
}

$Class* RevocationChecker::load$($String* name, bool initialize) {
	$loadClass(RevocationChecker, name, initialize, &_RevocationChecker_ClassInfo_, clinit$RevocationChecker, allocate$RevocationChecker);
	return class$;
}

$Class* RevocationChecker::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun