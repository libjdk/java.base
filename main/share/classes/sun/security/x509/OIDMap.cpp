#include <sun/security/x509/OIDMap.h>

#include <java/io/IOException.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AuthorityInfoAccessExtension.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <sun/security/x509/BasicConstraintsExtension.h>
#include <sun/security/x509/CRLDistributionPointsExtension.h>
#include <sun/security/x509/CRLNumberExtension.h>
#include <sun/security/x509/CRLReasonCodeExtension.h>
#include <sun/security/x509/CertificateIssuerExtension.h>
#include <sun/security/x509/CertificatePoliciesExtension.h>
#include <sun/security/x509/DeltaCRLIndicatorExtension.h>
#include <sun/security/x509/ExtendedKeyUsageExtension.h>
#include <sun/security/x509/FreshestCRLExtension.h>
#include <sun/security/x509/InhibitAnyPolicyExtension.h>
#include <sun/security/x509/IssuerAlternativeNameExtension.h>
#include <sun/security/x509/IssuingDistributionPointExtension.h>
#include <sun/security/x509/KeyUsageExtension.h>
#include <sun/security/x509/NameConstraintsExtension.h>
#include <sun/security/x509/NetscapeCertTypeExtension.h>
#include <sun/security/x509/OCSPNoCheckExtension.h>
#include <sun/security/x509/OIDMap$OIDInfo.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/PolicyConstraintsExtension.h>
#include <sun/security/x509/PolicyMappingsExtension.h>
#include <sun/security/x509/PrivateKeyUsageExtension.h>
#include <sun/security/x509/SubjectAlternativeNameExtension.h>
#include <sun/security/x509/SubjectInfoAccessExtension.h>
#include <sun/security/x509/SubjectKeyIdentifierExtension.h>
#include <sun/security/x509/X509CertImpl.h>
#include <sun/security/x509/X509CertInfo.h>
#include <jcpp.h>

#undef AUTH_INFO_ACCESS
#undef AUTH_KEY_IDENTIFIER
#undef BASIC_CONSTRAINTS
#undef CERT_ISSUER
#undef CERT_POLICIES
#undef CRL_DIST_POINTS
#undef CRL_NUMBER
#undef CRL_REASON
#undef DELTA_CRL_INDICATOR
#undef EXTENSIONS
#undef EXT_KEY_USAGE
#undef FRESHEST_CRL
#undef INHIBIT_ANY_POLICY
#undef ISSUER_ALT_NAME
#undef ISSUING_DIST_POINT
#undef KEY_USAGE
#undef NAME
#undef NAME_CONSTRAINTS
#undef NETSCAPE_CERT
#undef OCSPNOCHECK
#undef POLICY_CONSTRAINTS
#undef POLICY_MAPPINGS
#undef PRIVATE_KEY_USAGE
#undef ROOT
#undef SUBJECT_INFO_ACCESS
#undef SUB_ALT_NAME
#undef SUB_KEY_IDENTIFIER

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertificateException = ::java::security::cert::CertificateException;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AuthorityInfoAccessExtension = ::sun::security::x509::AuthorityInfoAccessExtension;
using $AuthorityKeyIdentifierExtension = ::sun::security::x509::AuthorityKeyIdentifierExtension;
using $BasicConstraintsExtension = ::sun::security::x509::BasicConstraintsExtension;
using $CRLDistributionPointsExtension = ::sun::security::x509::CRLDistributionPointsExtension;
using $CRLNumberExtension = ::sun::security::x509::CRLNumberExtension;
using $CRLReasonCodeExtension = ::sun::security::x509::CRLReasonCodeExtension;
using $CertificateIssuerExtension = ::sun::security::x509::CertificateIssuerExtension;
using $CertificatePoliciesExtension = ::sun::security::x509::CertificatePoliciesExtension;
using $DeltaCRLIndicatorExtension = ::sun::security::x509::DeltaCRLIndicatorExtension;
using $ExtendedKeyUsageExtension = ::sun::security::x509::ExtendedKeyUsageExtension;
using $FreshestCRLExtension = ::sun::security::x509::FreshestCRLExtension;
using $InhibitAnyPolicyExtension = ::sun::security::x509::InhibitAnyPolicyExtension;
using $IssuerAlternativeNameExtension = ::sun::security::x509::IssuerAlternativeNameExtension;
using $IssuingDistributionPointExtension = ::sun::security::x509::IssuingDistributionPointExtension;
using $KeyUsageExtension = ::sun::security::x509::KeyUsageExtension;
using $NameConstraintsExtension = ::sun::security::x509::NameConstraintsExtension;
using $NetscapeCertTypeExtension = ::sun::security::x509::NetscapeCertTypeExtension;
using $OCSPNoCheckExtension = ::sun::security::x509::OCSPNoCheckExtension;
using $OIDMap$OIDInfo = ::sun::security::x509::OIDMap$OIDInfo;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $PolicyConstraintsExtension = ::sun::security::x509::PolicyConstraintsExtension;
using $PolicyMappingsExtension = ::sun::security::x509::PolicyMappingsExtension;
using $PrivateKeyUsageExtension = ::sun::security::x509::PrivateKeyUsageExtension;
using $SubjectAlternativeNameExtension = ::sun::security::x509::SubjectAlternativeNameExtension;
using $SubjectInfoAccessExtension = ::sun::security::x509::SubjectInfoAccessExtension;
using $SubjectKeyIdentifierExtension = ::sun::security::x509::SubjectKeyIdentifierExtension;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;
using $X509CertInfo = ::sun::security::x509::X509CertInfo;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _OIDMap_FieldInfo_[] = {
	{"ROOT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, ROOT)},
	{"AUTH_KEY_IDENTIFIER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, AUTH_KEY_IDENTIFIER)},
	{"SUB_KEY_IDENTIFIER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, SUB_KEY_IDENTIFIER)},
	{"KEY_USAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, KEY_USAGE)},
	{"PRIVATE_KEY_USAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, PRIVATE_KEY_USAGE)},
	{"POLICY_MAPPINGS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, POLICY_MAPPINGS)},
	{"SUB_ALT_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, SUB_ALT_NAME)},
	{"ISSUER_ALT_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, ISSUER_ALT_NAME)},
	{"BASIC_CONSTRAINTS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, BASIC_CONSTRAINTS)},
	{"NAME_CONSTRAINTS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, NAME_CONSTRAINTS)},
	{"POLICY_CONSTRAINTS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, POLICY_CONSTRAINTS)},
	{"CRL_NUMBER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, CRL_NUMBER)},
	{"CRL_REASON", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, CRL_REASON)},
	{"NETSCAPE_CERT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, NETSCAPE_CERT)},
	{"CERT_POLICIES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, CERT_POLICIES)},
	{"EXT_KEY_USAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, EXT_KEY_USAGE)},
	{"INHIBIT_ANY_POLICY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, INHIBIT_ANY_POLICY)},
	{"CRL_DIST_POINTS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, CRL_DIST_POINTS)},
	{"CERT_ISSUER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, CERT_ISSUER)},
	{"SUBJECT_INFO_ACCESS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, SUBJECT_INFO_ACCESS)},
	{"AUTH_INFO_ACCESS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, AUTH_INFO_ACCESS)},
	{"ISSUING_DIST_POINT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, ISSUING_DIST_POINT)},
	{"DELTA_CRL_INDICATOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, DELTA_CRL_INDICATOR)},
	{"FRESHEST_CRL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, FRESHEST_CRL)},
	{"OCSPNOCHECK", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, OCSPNOCHECK)},
	{"oidMap", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/util/ObjectIdentifier;Lsun/security/x509/OIDMap$OIDInfo;>;", $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, oidMap)},
	{"nameMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/x509/OIDMap$OIDInfo;>;", $PRIVATE | $STATIC | $FINAL, $staticField(OIDMap, nameMap)},
	{}
};

$MethodInfo _OIDMap_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(OIDMap, init$, void)},
	{"addAttribute", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<*>;)V", $PUBLIC | $STATIC, $staticMethod(OIDMap, addAttribute, void, $String*, $String*, $Class*), "java.security.cert.CertificateException"},
	{"addInternal", "(Ljava/lang/String;Lsun/security/util/ObjectIdentifier;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(OIDMap, addInternal, void, $String*, $ObjectIdentifier*, $String*)},
	{"getClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(OIDMap, getClass, $Class*, $String*), "java.security.cert.CertificateException"},
	{"getClass", "(Lsun/security/util/ObjectIdentifier;)Ljava/lang/Class;", "(Lsun/security/util/ObjectIdentifier;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $staticMethod(OIDMap, getClass, $Class*, $ObjectIdentifier*), "java.security.cert.CertificateException"},
	{"getName", "(Lsun/security/util/ObjectIdentifier;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(OIDMap, getName, $String*, $ObjectIdentifier*)},
	{"getOID", "(Ljava/lang/String;)Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC, $staticMethod(OIDMap, getOID, $ObjectIdentifier*, $String*)},
	{}
};

$InnerClassInfo _OIDMap_InnerClassesInfo_[] = {
	{"sun.security.x509.OIDMap$OIDInfo", "sun.security.x509.OIDMap", "OIDInfo", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _OIDMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.OIDMap",
	"java.lang.Object",
	nullptr,
	_OIDMap_FieldInfo_,
	_OIDMap_MethodInfo_,
	nullptr,
	nullptr,
	_OIDMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.x509.OIDMap$OIDInfo"
};

$Object* allocate$OIDMap($Class* clazz) {
	return $of($alloc(OIDMap));
}

$String* OIDMap::ROOT = nullptr;
$String* OIDMap::AUTH_KEY_IDENTIFIER = nullptr;
$String* OIDMap::SUB_KEY_IDENTIFIER = nullptr;
$String* OIDMap::KEY_USAGE = nullptr;
$String* OIDMap::PRIVATE_KEY_USAGE = nullptr;
$String* OIDMap::POLICY_MAPPINGS = nullptr;
$String* OIDMap::SUB_ALT_NAME = nullptr;
$String* OIDMap::ISSUER_ALT_NAME = nullptr;
$String* OIDMap::BASIC_CONSTRAINTS = nullptr;
$String* OIDMap::NAME_CONSTRAINTS = nullptr;
$String* OIDMap::POLICY_CONSTRAINTS = nullptr;
$String* OIDMap::CRL_NUMBER = nullptr;
$String* OIDMap::CRL_REASON = nullptr;
$String* OIDMap::NETSCAPE_CERT = nullptr;
$String* OIDMap::CERT_POLICIES = nullptr;
$String* OIDMap::EXT_KEY_USAGE = nullptr;
$String* OIDMap::INHIBIT_ANY_POLICY = nullptr;
$String* OIDMap::CRL_DIST_POINTS = nullptr;
$String* OIDMap::CERT_ISSUER = nullptr;
$String* OIDMap::SUBJECT_INFO_ACCESS = nullptr;
$String* OIDMap::AUTH_INFO_ACCESS = nullptr;
$String* OIDMap::ISSUING_DIST_POINT = nullptr;
$String* OIDMap::DELTA_CRL_INDICATOR = nullptr;
$String* OIDMap::FRESHEST_CRL = nullptr;
$String* OIDMap::OCSPNOCHECK = nullptr;
$Map* OIDMap::oidMap = nullptr;
$Map* OIDMap::nameMap = nullptr;

void OIDMap::init$() {
}

void OIDMap::addInternal($String* name, $ObjectIdentifier* oid, $String* className) {
	$init(OIDMap);
	$var($OIDMap$OIDInfo, info, $new($OIDMap$OIDInfo, name, oid, className));
	$nc(OIDMap::oidMap)->put(oid, info);
	$nc(OIDMap::nameMap)->put(name, info);
}

void OIDMap::addAttribute($String* name, $String* oid, $Class* clazz) {
	$init(OIDMap);
	$useLocalCurrentObjectStackCache();
	$var($ObjectIdentifier, objId, nullptr);
	try {
		$assign(objId, $ObjectIdentifier::of(oid));
	} catch ($IOException& ioe) {
		$throwNew($CertificateException, $$str({"Invalid Object identifier: "_s, oid}));
	}
	$var($OIDMap$OIDInfo, info, $new($OIDMap$OIDInfo, name, objId, clazz));
	if ($nc(OIDMap::oidMap)->put(objId, info) != nullptr) {
		$throwNew($CertificateException, $$str({"Object identifier already exists: "_s, oid}));
	}
	if ($nc(OIDMap::nameMap)->put(name, info) != nullptr) {
		$throwNew($CertificateException, $$str({"Name already exists: "_s, name}));
	}
}

$String* OIDMap::getName($ObjectIdentifier* oid) {
	$init(OIDMap);
	$var($OIDMap$OIDInfo, info, $cast($OIDMap$OIDInfo, $nc(OIDMap::oidMap)->get(oid)));
	return (info == nullptr) ? ($String*)nullptr : $nc(info)->name;
}

$ObjectIdentifier* OIDMap::getOID($String* name) {
	$init(OIDMap);
	$var($OIDMap$OIDInfo, info, $cast($OIDMap$OIDInfo, $nc(OIDMap::nameMap)->get(name)));
	return (info == nullptr) ? ($ObjectIdentifier*)nullptr : $nc(info)->oid;
}

$Class* OIDMap::getClass($String* name) {
	$init(OIDMap);
	$var($OIDMap$OIDInfo, info, $cast($OIDMap$OIDInfo, $nc(OIDMap::nameMap)->get(name)));
	return (info == nullptr) ? ($Class*)nullptr : $nc(info)->getClazz();
}

$Class* OIDMap::getClass($ObjectIdentifier* oid) {
	$init(OIDMap);
	$var($OIDMap$OIDInfo, info, $cast($OIDMap$OIDInfo, $nc(OIDMap::oidMap)->get(oid)));
	return (info == nullptr) ? ($Class*)nullptr : $nc(info)->getClazz();
}

void clinit$OIDMap($Class* class$) {
	$init($X509CertImpl);
	$init($X509CertInfo);
	$assignStatic(OIDMap::ROOT, $str({$X509CertImpl::NAME, "."_s, $X509CertInfo::NAME, "."_s, $X509CertInfo::EXTENSIONS}));
	$init($AuthorityKeyIdentifierExtension);
	$assignStatic(OIDMap::AUTH_KEY_IDENTIFIER, $str({OIDMap::ROOT, "."_s, $AuthorityKeyIdentifierExtension::NAME}));
	$init($SubjectKeyIdentifierExtension);
	$assignStatic(OIDMap::SUB_KEY_IDENTIFIER, $str({OIDMap::ROOT, "."_s, $SubjectKeyIdentifierExtension::NAME}));
	$init($KeyUsageExtension);
	$assignStatic(OIDMap::KEY_USAGE, $str({OIDMap::ROOT, "."_s, $KeyUsageExtension::NAME}));
	$init($PrivateKeyUsageExtension);
	$assignStatic(OIDMap::PRIVATE_KEY_USAGE, $str({OIDMap::ROOT, "."_s, $PrivateKeyUsageExtension::NAME}));
	$init($PolicyMappingsExtension);
	$assignStatic(OIDMap::POLICY_MAPPINGS, $str({OIDMap::ROOT, "."_s, $PolicyMappingsExtension::NAME}));
	$init($SubjectAlternativeNameExtension);
	$assignStatic(OIDMap::SUB_ALT_NAME, $str({OIDMap::ROOT, "."_s, $SubjectAlternativeNameExtension::NAME}));
	$init($IssuerAlternativeNameExtension);
	$assignStatic(OIDMap::ISSUER_ALT_NAME, $str({OIDMap::ROOT, "."_s, $IssuerAlternativeNameExtension::NAME}));
	$init($BasicConstraintsExtension);
	$assignStatic(OIDMap::BASIC_CONSTRAINTS, $str({OIDMap::ROOT, "."_s, $BasicConstraintsExtension::NAME}));
	$init($NameConstraintsExtension);
	$assignStatic(OIDMap::NAME_CONSTRAINTS, $str({OIDMap::ROOT, "."_s, $NameConstraintsExtension::NAME}));
	$init($PolicyConstraintsExtension);
	$assignStatic(OIDMap::POLICY_CONSTRAINTS, $str({OIDMap::ROOT, "."_s, $PolicyConstraintsExtension::NAME}));
	$init($CRLNumberExtension);
	$assignStatic(OIDMap::CRL_NUMBER, $str({OIDMap::ROOT, "."_s, $CRLNumberExtension::NAME}));
	$init($CRLReasonCodeExtension);
	$assignStatic(OIDMap::CRL_REASON, $str({OIDMap::ROOT, "."_s, $CRLReasonCodeExtension::NAME}));
	$init($NetscapeCertTypeExtension);
	$assignStatic(OIDMap::NETSCAPE_CERT, $str({OIDMap::ROOT, "."_s, $NetscapeCertTypeExtension::NAME}));
	$init($CertificatePoliciesExtension);
	$assignStatic(OIDMap::CERT_POLICIES, $str({OIDMap::ROOT, "."_s, $CertificatePoliciesExtension::NAME}));
	$init($ExtendedKeyUsageExtension);
	$assignStatic(OIDMap::EXT_KEY_USAGE, $str({OIDMap::ROOT, "."_s, $ExtendedKeyUsageExtension::NAME}));
	$init($InhibitAnyPolicyExtension);
	$assignStatic(OIDMap::INHIBIT_ANY_POLICY, $str({OIDMap::ROOT, "."_s, $InhibitAnyPolicyExtension::NAME}));
	$init($CRLDistributionPointsExtension);
	$assignStatic(OIDMap::CRL_DIST_POINTS, $str({OIDMap::ROOT, "."_s, $CRLDistributionPointsExtension::NAME}));
	$init($CertificateIssuerExtension);
	$assignStatic(OIDMap::CERT_ISSUER, $str({OIDMap::ROOT, "."_s, $CertificateIssuerExtension::NAME}));
	$init($SubjectInfoAccessExtension);
	$assignStatic(OIDMap::SUBJECT_INFO_ACCESS, $str({OIDMap::ROOT, "."_s, $SubjectInfoAccessExtension::NAME}));
	$init($AuthorityInfoAccessExtension);
	$assignStatic(OIDMap::AUTH_INFO_ACCESS, $str({OIDMap::ROOT, "."_s, $AuthorityInfoAccessExtension::NAME}));
	$init($IssuingDistributionPointExtension);
	$assignStatic(OIDMap::ISSUING_DIST_POINT, $str({OIDMap::ROOT, "."_s, $IssuingDistributionPointExtension::NAME}));
	$init($DeltaCRLIndicatorExtension);
	$assignStatic(OIDMap::DELTA_CRL_INDICATOR, $str({OIDMap::ROOT, "."_s, $DeltaCRLIndicatorExtension::NAME}));
	$init($FreshestCRLExtension);
	$assignStatic(OIDMap::FRESHEST_CRL, $str({OIDMap::ROOT, "."_s, $FreshestCRLExtension::NAME}));
	$init($OCSPNoCheckExtension);
	$assignStatic(OIDMap::OCSPNOCHECK, $str({OIDMap::ROOT, "."_s, $OCSPNoCheckExtension::NAME}));
	{
		$assignStatic(OIDMap::oidMap, $new($HashMap));
		$assignStatic(OIDMap::nameMap, $new($HashMap));
		$init($PKIXExtensions);
		OIDMap::addInternal(OIDMap::SUB_KEY_IDENTIFIER, $PKIXExtensions::SubjectKey_Id, "sun.security.x509.SubjectKeyIdentifierExtension"_s);
		OIDMap::addInternal(OIDMap::KEY_USAGE, $PKIXExtensions::KeyUsage_Id, "sun.security.x509.KeyUsageExtension"_s);
		OIDMap::addInternal(OIDMap::PRIVATE_KEY_USAGE, $PKIXExtensions::PrivateKeyUsage_Id, "sun.security.x509.PrivateKeyUsageExtension"_s);
		OIDMap::addInternal(OIDMap::SUB_ALT_NAME, $PKIXExtensions::SubjectAlternativeName_Id, "sun.security.x509.SubjectAlternativeNameExtension"_s);
		OIDMap::addInternal(OIDMap::ISSUER_ALT_NAME, $PKIXExtensions::IssuerAlternativeName_Id, "sun.security.x509.IssuerAlternativeNameExtension"_s);
		OIDMap::addInternal(OIDMap::BASIC_CONSTRAINTS, $PKIXExtensions::BasicConstraints_Id, "sun.security.x509.BasicConstraintsExtension"_s);
		OIDMap::addInternal(OIDMap::CRL_NUMBER, $PKIXExtensions::CRLNumber_Id, "sun.security.x509.CRLNumberExtension"_s);
		OIDMap::addInternal(OIDMap::CRL_REASON, $PKIXExtensions::ReasonCode_Id, "sun.security.x509.CRLReasonCodeExtension"_s);
		OIDMap::addInternal(OIDMap::NAME_CONSTRAINTS, $PKIXExtensions::NameConstraints_Id, "sun.security.x509.NameConstraintsExtension"_s);
		OIDMap::addInternal(OIDMap::POLICY_MAPPINGS, $PKIXExtensions::PolicyMappings_Id, "sun.security.x509.PolicyMappingsExtension"_s);
		OIDMap::addInternal(OIDMap::AUTH_KEY_IDENTIFIER, $PKIXExtensions::AuthorityKey_Id, "sun.security.x509.AuthorityKeyIdentifierExtension"_s);
		OIDMap::addInternal(OIDMap::POLICY_CONSTRAINTS, $PKIXExtensions::PolicyConstraints_Id, "sun.security.x509.PolicyConstraintsExtension"_s);
		$init($KnownOIDs);
		OIDMap::addInternal(OIDMap::NETSCAPE_CERT, $($ObjectIdentifier::of($KnownOIDs::NETSCAPE_CertType)), "sun.security.x509.NetscapeCertTypeExtension"_s);
		OIDMap::addInternal(OIDMap::CERT_POLICIES, $PKIXExtensions::CertificatePolicies_Id, "sun.security.x509.CertificatePoliciesExtension"_s);
		OIDMap::addInternal(OIDMap::EXT_KEY_USAGE, $PKIXExtensions::ExtendedKeyUsage_Id, "sun.security.x509.ExtendedKeyUsageExtension"_s);
		OIDMap::addInternal(OIDMap::INHIBIT_ANY_POLICY, $PKIXExtensions::InhibitAnyPolicy_Id, "sun.security.x509.InhibitAnyPolicyExtension"_s);
		OIDMap::addInternal(OIDMap::CRL_DIST_POINTS, $PKIXExtensions::CRLDistributionPoints_Id, "sun.security.x509.CRLDistributionPointsExtension"_s);
		OIDMap::addInternal(OIDMap::CERT_ISSUER, $PKIXExtensions::CertificateIssuer_Id, "sun.security.x509.CertificateIssuerExtension"_s);
		OIDMap::addInternal(OIDMap::SUBJECT_INFO_ACCESS, $PKIXExtensions::SubjectInfoAccess_Id, "sun.security.x509.SubjectInfoAccessExtension"_s);
		OIDMap::addInternal(OIDMap::AUTH_INFO_ACCESS, $PKIXExtensions::AuthInfoAccess_Id, "sun.security.x509.AuthorityInfoAccessExtension"_s);
		OIDMap::addInternal(OIDMap::ISSUING_DIST_POINT, $PKIXExtensions::IssuingDistributionPoint_Id, "sun.security.x509.IssuingDistributionPointExtension"_s);
		OIDMap::addInternal(OIDMap::DELTA_CRL_INDICATOR, $PKIXExtensions::DeltaCRLIndicator_Id, "sun.security.x509.DeltaCRLIndicatorExtension"_s);
		OIDMap::addInternal(OIDMap::FRESHEST_CRL, $PKIXExtensions::FreshestCRL_Id, "sun.security.x509.FreshestCRLExtension"_s);
		OIDMap::addInternal(OIDMap::OCSPNOCHECK, $PKIXExtensions::OCSPNoCheck_Id, "sun.security.x509.OCSPNoCheckExtension"_s);
	}
}

OIDMap::OIDMap() {
}

$Class* OIDMap::load$($String* name, bool initialize) {
	$loadClass(OIDMap, name, initialize, &_OIDMap_ClassInfo_, clinit$OIDMap, allocate$OIDMap);
	return class$;
}

$Class* OIDMap::class$ = nullptr;

		} // x509
	} // security
} // sun