#include <java/security/cert/X509CertSelector.h>

#include <java/io/IOException.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/math/BigInteger.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPathHelperImpl.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateExpiredException.h>
#include <java/security/cert/CertificateNotYetValidException.h>
#include <java/security/cert/Extension.h>
#include <java/security/cert/X509CertSelector$1.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/CertificatePoliciesExtension.h>
#include <sun/security/x509/CertificatePolicyId.h>
#include <sun/security/x509/CertificatePolicySet.h>
#include <sun/security/x509/DNSName.h>
#include <sun/security/x509/EDIPartyName.h>
#include <sun/security/x509/ExtendedKeyUsageExtension.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/GeneralSubtree.h>
#include <sun/security/x509/GeneralSubtrees.h>
#include <sun/security/x509/IPAddressName.h>
#include <sun/security/x509/NameConstraintsExtension.h>
#include <sun/security/x509/OIDName.h>
#include <sun/security/x509/OtherName.h>
#include <sun/security/x509/PolicyInformation.h>
#include <sun/security/x509/PrivateKeyUsageExtension.h>
#include <sun/security/x509/RFC822Name.h>
#include <sun/security/x509/SubjectAlternativeNameExtension.h>
#include <sun/security/x509/URIName.h>
#include <sun/security/x509/X400Address.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CertImpl.h>
#include <sun/security/x509/X509Key.h>
#include <jcpp.h>

#undef ANY_EXTENDED_KEY_USAGE
#undef EXCLUDED_SUBTREES
#undef FALSE
#undef NAME_ANY
#undef NAME_DIRECTORY
#undef NAME_DNS
#undef NAME_EDI
#undef NAME_IP
#undef NAME_MATCH
#undef NAME_OID
#undef NAME_RFC822
#undef NAME_URI
#undef NAME_WIDENS
#undef NAME_X400
#undef NOT_AFTER
#undef NOT_BEFORE
#undef PERMITTED_SUBTREES
#undef POLICIES
#undef SUBJECT_NAME
#undef USAGES

using $IOException = ::java::io::IOException;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $PublicKey = ::java::security::PublicKey;
using $CertPathHelperImpl = ::java::security::cert::CertPathHelperImpl;
using $CertSelector = ::java::security::cert::CertSelector;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateExpiredException = ::java::security::cert::CertificateExpiredException;
using $CertificateNotYetValidException = ::java::security::cert::CertificateNotYetValidException;
using $Extension = ::java::security::cert::Extension;
using $X509CertSelector$1 = ::java::security::cert::X509CertSelector$1;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $CertificatePoliciesExtension = ::sun::security::x509::CertificatePoliciesExtension;
using $CertificatePolicyId = ::sun::security::x509::CertificatePolicyId;
using $CertificatePolicySet = ::sun::security::x509::CertificatePolicySet;
using $DNSName = ::sun::security::x509::DNSName;
using $EDIPartyName = ::sun::security::x509::EDIPartyName;
using $ExtendedKeyUsageExtension = ::sun::security::x509::ExtendedKeyUsageExtension;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $GeneralSubtree = ::sun::security::x509::GeneralSubtree;
using $GeneralSubtrees = ::sun::security::x509::GeneralSubtrees;
using $IPAddressName = ::sun::security::x509::IPAddressName;
using $NameConstraintsExtension = ::sun::security::x509::NameConstraintsExtension;
using $OIDName = ::sun::security::x509::OIDName;
using $OtherName = ::sun::security::x509::OtherName;
using $PolicyInformation = ::sun::security::x509::PolicyInformation;
using $PrivateKeyUsageExtension = ::sun::security::x509::PrivateKeyUsageExtension;
using $RFC822Name = ::sun::security::x509::RFC822Name;
using $SubjectAlternativeNameExtension = ::sun::security::x509::SubjectAlternativeNameExtension;
using $URIName = ::sun::security::x509::URIName;
using $X400Address = ::sun::security::x509::X400Address;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;
using $X509Key = ::sun::security::x509::X509Key;

namespace java {
	namespace security {
		namespace cert {

$NamedAttribute X509CertSelector_Attribute_var$0[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509CertSelector_MethodAnnotations_getIssuerAsString20[] = {
	{"Ljava/lang/Deprecated;", X509CertSelector_Attribute_var$0},
	{}
};

$NamedAttribute X509CertSelector_Attribute_var$1[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509CertSelector_MethodAnnotations_getSubjectAsString31[] = {
	{"Ljava/lang/Deprecated;", X509CertSelector_Attribute_var$1},
	{}
};

$NamedAttribute X509CertSelector_Attribute_var$2[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509CertSelector_MethodAnnotations_setIssuer58[] = {
	{"Ljava/lang/Deprecated;", X509CertSelector_Attribute_var$2},
	{}
};

$NamedAttribute X509CertSelector_Attribute_var$3[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509CertSelector_MethodAnnotations_setSubject69[] = {
	{"Ljava/lang/Deprecated;", X509CertSelector_Attribute_var$3},
	{}
};

$FieldInfo _X509CertSelector_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CertSelector, debug)},
	{"ANY_EXTENDED_KEY_USAGE", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CertSelector, ANY_EXTENDED_KEY_USAGE)},
	{"serialNumber", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(X509CertSelector, serialNumber)},
	{"issuer", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $field(X509CertSelector, issuer)},
	{"subject", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $field(X509CertSelector, subject)},
	{"subjectKeyID", "[B", nullptr, $PRIVATE, $field(X509CertSelector, subjectKeyID)},
	{"authorityKeyID", "[B", nullptr, $PRIVATE, $field(X509CertSelector, authorityKeyID)},
	{"certificateValid", "Ljava/util/Date;", nullptr, $PRIVATE, $field(X509CertSelector, certificateValid)},
	{"privateKeyValid", "Ljava/util/Date;", nullptr, $PRIVATE, $field(X509CertSelector, privateKeyValid)},
	{"subjectPublicKeyAlgID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(X509CertSelector, subjectPublicKeyAlgID)},
	{"subjectPublicKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(X509CertSelector, subjectPublicKey)},
	{"subjectPublicKeyBytes", "[B", nullptr, $PRIVATE, $field(X509CertSelector, subjectPublicKeyBytes)},
	{"keyUsage", "[Z", nullptr, $PRIVATE, $field(X509CertSelector, keyUsage)},
	{"keyPurposeSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(X509CertSelector, keyPurposeSet)},
	{"keyPurposeOIDSet", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/util/ObjectIdentifier;>;", $PRIVATE, $field(X509CertSelector, keyPurposeOIDSet)},
	{"subjectAlternativeNames", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/List<*>;>;", $PRIVATE, $field(X509CertSelector, subjectAlternativeNames)},
	{"subjectAlternativeGeneralNames", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/x509/GeneralNameInterface;>;", $PRIVATE, $field(X509CertSelector, subjectAlternativeGeneralNames)},
	{"policy", "Lsun/security/x509/CertificatePolicySet;", nullptr, $PRIVATE, $field(X509CertSelector, policy)},
	{"policySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(X509CertSelector, policySet)},
	{"pathToNames", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/List<*>;>;", $PRIVATE, $field(X509CertSelector, pathToNames)},
	{"pathToGeneralNames", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/x509/GeneralNameInterface;>;", $PRIVATE, $field(X509CertSelector, pathToGeneralNames)},
	{"nc", "Lsun/security/x509/NameConstraintsExtension;", nullptr, $PRIVATE, $field(X509CertSelector, nc)},
	{"ncBytes", "[B", nullptr, $PRIVATE, $field(X509CertSelector, ncBytes)},
	{"basicConstraints", "I", nullptr, $PRIVATE, $field(X509CertSelector, basicConstraints)},
	{"x509Cert", "Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(X509CertSelector, x509Cert)},
	{"matchAllSubjectAltNames", "Z", nullptr, $PRIVATE, $field(X509CertSelector, matchAllSubjectAltNames)},
	{"FALSE", "Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CertSelector, FALSE)},
	{"NAME_ANY", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_ANY)},
	{"NAME_RFC822", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_RFC822)},
	{"NAME_DNS", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_DNS)},
	{"NAME_X400", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_X400)},
	{"NAME_DIRECTORY", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_DIRECTORY)},
	{"NAME_EDI", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_EDI)},
	{"NAME_URI", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_URI)},
	{"NAME_IP", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_IP)},
	{"NAME_OID", "I", nullptr, $STATIC | $FINAL, $constField(X509CertSelector, NAME_OID)},
	{}
};

$MethodInfo _X509CertSelector_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(X509CertSelector, init$, void)},
	{"addPathToName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, addPathToName, void, int32_t, $String*), "java.io.IOException"},
	{"addPathToName", "(I[B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, addPathToName, void, int32_t, $bytes*), "java.io.IOException"},
	{"addPathToNameInternal", "(ILjava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertSelector, addPathToNameInternal, void, int32_t, Object$*), "java.io.IOException"},
	{"addSubjectAlternativeName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, addSubjectAlternativeName, void, int32_t, $String*), "java.io.IOException"},
	{"addSubjectAlternativeName", "(I[B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, addSubjectAlternativeName, void, int32_t, $bytes*), "java.io.IOException"},
	{"addSubjectAlternativeNameInternal", "(ILjava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertSelector, addSubjectAlternativeNameInternal, void, int32_t, Object$*), "java.io.IOException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, clone, $Object*)},
	{"cloneAndCheckNames", "(Ljava/util/Collection;)Ljava/util/Set;", "(Ljava/util/Collection<Ljava/util/List<*>;>;)Ljava/util/Set<Ljava/util/List<*>;>;", $PRIVATE | $STATIC, $staticMethod(X509CertSelector, cloneAndCheckNames, $Set*, $Collection*), "java.io.IOException"},
	{"cloneNames", "(Ljava/util/Collection;)Ljava/util/Set;", "(Ljava/util/Collection<Ljava/util/List<*>;>;)Ljava/util/Set<Ljava/util/List<*>;>;", $PRIVATE | $STATIC, $staticMethod(X509CertSelector, cloneNames, $Set*, $Collection*)},
	{"cloneSet", "(Ljava/util/Set;)Ljava/util/Set;", "<T:Ljava/lang/Object;>(Ljava/util/Set<TT;>;)Ljava/util/Set<TT;>;", $PRIVATE | $STATIC, $staticMethod(X509CertSelector, cloneSet, $Set*, $Set*)},
	{"equalNames", "(Ljava/util/Collection;Ljava/util/Collection;)Z", "(Ljava/util/Collection<*>;Ljava/util/Collection<*>;)Z", $STATIC, $staticMethod(X509CertSelector, equalNames, bool, $Collection*, $Collection*)},
	{"getAuthorityKeyIdentifier", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getAuthorityKeyIdentifier, $bytes*)},
	{"getBasicConstraints", "()I", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getBasicConstraints, int32_t)},
	{"getCertificate", "()Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getCertificate, $X509Certificate*)},
	{"getCertificateValid", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getCertificateValid, $Date*)},
	{"getExtendedKeyUsage", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertSelector, getExtendedKeyUsage, $Set*)},
	{"getExtensionObject", "(Ljava/security/cert/X509Certificate;Lsun/security/util/KnownOIDs;)Ljava/security/cert/Extension;", nullptr, $PRIVATE | $STATIC, $staticMethod(X509CertSelector, getExtensionObject, $Extension*, $X509Certificate*, $KnownOIDs*), "java.io.IOException"},
	{"getIssuer", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getIssuer, $X500Principal*)},
	{"getIssuerAsBytes", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getIssuerAsBytes, $bytes*), "java.io.IOException"},
	{"getIssuerAsString", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(X509CertSelector, getIssuerAsString, $String*), nullptr, nullptr, _X509CertSelector_MethodAnnotations_getIssuerAsString20},
	{"getKeyUsage", "()[Z", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getKeyUsage, $booleans*)},
	{"getMatchAllSubjectAltNames", "()Z", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getMatchAllSubjectAltNames, bool)},
	{"getNameConstraints", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getNameConstraints, $bytes*)},
	{"getPathToNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC, $virtualMethod(X509CertSelector, getPathToNames, $Collection*)},
	{"getPolicy", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertSelector, getPolicy, $Set*)},
	{"getPrivateKeyValid", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getPrivateKeyValid, $Date*)},
	{"getSerialNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getSerialNumber, $BigInteger*)},
	{"getSubject", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getSubject, $X500Principal*)},
	{"getSubjectAlternativeNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC, $virtualMethod(X509CertSelector, getSubjectAlternativeNames, $Collection*)},
	{"getSubjectAsBytes", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getSubjectAsBytes, $bytes*), "java.io.IOException"},
	{"getSubjectAsString", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(X509CertSelector, getSubjectAsString, $String*), nullptr, nullptr, _X509CertSelector_MethodAnnotations_getSubjectAsString31},
	{"getSubjectKeyIdentifier", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getSubjectKeyIdentifier, $bytes*)},
	{"getSubjectPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getSubjectPublicKey, $PublicKey*)},
	{"getSubjectPublicKeyAlgID", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, getSubjectPublicKeyAlgID, $String*)},
	{"keyUsageToString", "([Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(X509CertSelector, keyUsageToString, $String*, $booleans*)},
	{"makeGeneralNameInterface", "(ILjava/lang/Object;)Lsun/security/x509/GeneralNameInterface;", nullptr, $STATIC, $staticMethod(X509CertSelector, makeGeneralNameInterface, $GeneralNameInterface*, int32_t, Object$*), "java.io.IOException"},
	{"match", "(Ljava/security/cert/Certificate;)Z", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, match, bool, $Certificate*)},
	{"matchAuthorityKeyID", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchAuthorityKeyID, bool, $X509Certificate*)},
	{"matchBasicConstraints", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchBasicConstraints, bool, $X509Certificate*)},
	{"matchExcluded", "(Lsun/security/x509/GeneralSubtrees;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchExcluded, bool, $GeneralSubtrees*)},
	{"matchExtendedKeyUsage", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchExtendedKeyUsage, bool, $X509Certificate*)},
	{"matchKeyUsage", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchKeyUsage, bool, $X509Certificate*)},
	{"matchNameConstraints", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchNameConstraints, bool, $X509Certificate*)},
	{"matchPathToNames", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchPathToNames, bool, $X509Certificate*)},
	{"matchPermitted", "(Lsun/security/x509/GeneralSubtrees;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchPermitted, bool, $GeneralSubtrees*)},
	{"matchPolicy", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchPolicy, bool, $X509Certificate*)},
	{"matchPrivateKeyValid", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchPrivateKeyValid, bool, $X509Certificate*)},
	{"matchSubjectAlternativeNames", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchSubjectAlternativeNames, bool, $X509Certificate*)},
	{"matchSubjectKeyID", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchSubjectKeyID, bool, $X509Certificate*)},
	{"matchSubjectPublicKeyAlgID", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PRIVATE, $method(X509CertSelector, matchSubjectPublicKeyAlgID, bool, $X509Certificate*)},
	{"parseNames", "(Ljava/util/Collection;)Ljava/util/Set;", "(Ljava/util/Collection<Ljava/util/List<*>;>;)Ljava/util/Set<Lsun/security/x509/GeneralNameInterface;>;", $PRIVATE | $STATIC, $staticMethod(X509CertSelector, parseNames, $Set*, $Collection*), "java.io.IOException"},
	{"setAuthorityKeyIdentifier", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setAuthorityKeyIdentifier, void, $bytes*)},
	{"setBasicConstraints", "(I)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setBasicConstraints, void, int32_t)},
	{"setCertificate", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setCertificate, void, $X509Certificate*)},
	{"setCertificateValid", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setCertificateValid, void, $Date*)},
	{"setExtendedKeyUsage", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(X509CertSelector, setExtendedKeyUsage, void, $Set*), "java.io.IOException"},
	{"setIssuer", "(Ljavax/security/auth/x500/X500Principal;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setIssuer, void, $X500Principal*)},
	{"setIssuer", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(X509CertSelector, setIssuer, void, $String*), "java.io.IOException", nullptr, _X509CertSelector_MethodAnnotations_setIssuer58},
	{"setIssuer", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setIssuer, void, $bytes*), "java.io.IOException"},
	{"setKeyUsage", "([Z)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setKeyUsage, void, $booleans*)},
	{"setMatchAllSubjectAltNames", "(Z)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setMatchAllSubjectAltNames, void, bool)},
	{"setNameConstraints", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setNameConstraints, void, $bytes*), "java.io.IOException"},
	{"setPathToNames", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<Ljava/util/List<*>;>;)V", $PUBLIC, $virtualMethod(X509CertSelector, setPathToNames, void, $Collection*), "java.io.IOException"},
	{"setPathToNamesInternal", "(Ljava/util/Set;)V", "(Ljava/util/Set<Lsun/security/x509/GeneralNameInterface;>;)V", 0, $virtualMethod(X509CertSelector, setPathToNamesInternal, void, $Set*)},
	{"setPolicy", "(Ljava/util/Set;)V", "(Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC, $virtualMethod(X509CertSelector, setPolicy, void, $Set*), "java.io.IOException"},
	{"setPrivateKeyValid", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setPrivateKeyValid, void, $Date*)},
	{"setSerialNumber", "(Ljava/math/BigInteger;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSerialNumber, void, $BigInteger*)},
	{"setSubject", "(Ljavax/security/auth/x500/X500Principal;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSubject, void, $X500Principal*)},
	{"setSubject", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(X509CertSelector, setSubject, void, $String*), "java.io.IOException", nullptr, _X509CertSelector_MethodAnnotations_setSubject69},
	{"setSubject", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSubject, void, $bytes*), "java.io.IOException"},
	{"setSubjectAlternativeNames", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<Ljava/util/List<*>;>;)V", $PUBLIC, $virtualMethod(X509CertSelector, setSubjectAlternativeNames, void, $Collection*), "java.io.IOException"},
	{"setSubjectKeyIdentifier", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSubjectKeyIdentifier, void, $bytes*)},
	{"setSubjectPublicKey", "(Ljava/security/PublicKey;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSubjectPublicKey, void, $PublicKey*)},
	{"setSubjectPublicKey", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSubjectPublicKey, void, $bytes*), "java.io.IOException"},
	{"setSubjectPublicKeyAlgID", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, setSubjectPublicKeyAlgID, void, $String*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertSelector, toString, $String*)},
	{}
};

$InnerClassInfo _X509CertSelector_InnerClassesInfo_[] = {
	{"java.security.cert.X509CertSelector$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _X509CertSelector_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.X509CertSelector",
	"java.lang.Object",
	"java.security.cert.CertSelector",
	_X509CertSelector_FieldInfo_,
	_X509CertSelector_MethodInfo_,
	nullptr,
	nullptr,
	_X509CertSelector_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.cert.X509CertSelector$1"
};

$Object* allocate$X509CertSelector($Class* clazz) {
	return $of($alloc(X509CertSelector));
}

$Debug* X509CertSelector::debug = nullptr;
$ObjectIdentifier* X509CertSelector::ANY_EXTENDED_KEY_USAGE = nullptr;
$Boolean* X509CertSelector::FALSE = nullptr;

void X509CertSelector::init$() {
	this->basicConstraints = -1;
	this->matchAllSubjectAltNames = true;
}

void X509CertSelector::setCertificate($X509Certificate* cert) {
	$set(this, x509Cert, cert);
}

void X509CertSelector::setSerialNumber($BigInteger* serial) {
	$set(this, serialNumber, serial);
}

void X509CertSelector::setIssuer($X500Principal* issuer) {
	$set(this, issuer, issuer);
}

void X509CertSelector::setIssuer($String* issuerDN) {
	if (issuerDN == nullptr) {
		$set(this, issuer, nullptr);
	} else {
		$set(this, issuer, $$new($X500Name, issuerDN)->asX500Principal());
	}
}

void X509CertSelector::setIssuer($bytes* issuerDN) {
	try {
		$set(this, issuer, issuerDN == nullptr ? ($X500Principal*)nullptr : $new($X500Principal, issuerDN));
	} catch ($IllegalArgumentException& e) {
		$throwNew($IOException, "Invalid name"_s, e);
	}
}

void X509CertSelector::setSubject($X500Principal* subject) {
	$set(this, subject, subject);
}

void X509CertSelector::setSubject($String* subjectDN) {
	if (subjectDN == nullptr) {
		$set(this, subject, nullptr);
	} else {
		$set(this, subject, $$new($X500Name, subjectDN)->asX500Principal());
	}
}

void X509CertSelector::setSubject($bytes* subjectDN) {
	try {
		$set(this, subject, subjectDN == nullptr ? ($X500Principal*)nullptr : $new($X500Principal, subjectDN));
	} catch ($IllegalArgumentException& e) {
		$throwNew($IOException, "Invalid name"_s, e);
	}
}

void X509CertSelector::setSubjectKeyIdentifier($bytes* subjectKeyID) {
	if (subjectKeyID == nullptr) {
		$set(this, subjectKeyID, nullptr);
	} else {
		$set(this, subjectKeyID, $cast($bytes, $nc(subjectKeyID)->clone()));
	}
}

void X509CertSelector::setAuthorityKeyIdentifier($bytes* authorityKeyID) {
	if (authorityKeyID == nullptr) {
		$set(this, authorityKeyID, nullptr);
	} else {
		$set(this, authorityKeyID, $cast($bytes, $nc(authorityKeyID)->clone()));
	}
}

void X509CertSelector::setCertificateValid($Date* certValid) {
	if (certValid == nullptr) {
		$set(this, certificateValid, nullptr);
	} else {
		$set(this, certificateValid, $cast($Date, $nc(certValid)->clone()));
	}
}

void X509CertSelector::setPrivateKeyValid($Date* privateKeyValid) {
	if (privateKeyValid == nullptr) {
		$set(this, privateKeyValid, nullptr);
	} else {
		$set(this, privateKeyValid, $cast($Date, $nc(privateKeyValid)->clone()));
	}
}

void X509CertSelector::setSubjectPublicKeyAlgID($String* oid) {
	if (oid == nullptr) {
		$set(this, subjectPublicKeyAlgID, nullptr);
	} else {
		$set(this, subjectPublicKeyAlgID, $ObjectIdentifier::of(oid));
	}
}

void X509CertSelector::setSubjectPublicKey($PublicKey* key) {
	if (key == nullptr) {
		$set(this, subjectPublicKey, nullptr);
		$set(this, subjectPublicKeyBytes, nullptr);
	} else {
		$set(this, subjectPublicKey, key);
		$set(this, subjectPublicKeyBytes, $nc(key)->getEncoded());
	}
}

void X509CertSelector::setSubjectPublicKey($bytes* key) {
	if (key == nullptr) {
		$set(this, subjectPublicKey, nullptr);
		$set(this, subjectPublicKeyBytes, nullptr);
	} else {
		$set(this, subjectPublicKeyBytes, $cast($bytes, $nc(key)->clone()));
		$set(this, subjectPublicKey, $X509Key::parse($$new($DerValue, this->subjectPublicKeyBytes)));
	}
}

void X509CertSelector::setKeyUsage($booleans* keyUsage) {
	if (keyUsage == nullptr) {
		$set(this, keyUsage, nullptr);
	} else {
		$set(this, keyUsage, $cast($booleans, $nc(keyUsage)->clone()));
	}
}

void X509CertSelector::setExtendedKeyUsage($Set* keyPurposeSet) {
	$useLocalCurrentObjectStackCache();
	if ((keyPurposeSet == nullptr) || $nc(keyPurposeSet)->isEmpty()) {
		$set(this, keyPurposeSet, nullptr);
		$set(this, keyPurposeOIDSet, nullptr);
	} else {
		$set(this, keyPurposeSet, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(keyPurposeSet))));
		$set(this, keyPurposeOIDSet, $new($HashSet));
		{
			$var($Iterator, i$, $nc(this->keyPurposeSet)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, s, $cast($String, i$->next()));
				{
					$nc(this->keyPurposeOIDSet)->add($($ObjectIdentifier::of(s)));
				}
			}
		}
	}
}

void X509CertSelector::setMatchAllSubjectAltNames(bool matchAllNames) {
	this->matchAllSubjectAltNames = matchAllNames;
}

void X509CertSelector::setSubjectAlternativeNames($Collection* names) {
	if (names == nullptr) {
		$set(this, subjectAlternativeNames, nullptr);
		$set(this, subjectAlternativeGeneralNames, nullptr);
	} else {
		if ($nc(names)->isEmpty()) {
			$set(this, subjectAlternativeNames, nullptr);
			$set(this, subjectAlternativeGeneralNames, nullptr);
			return;
		}
		$var($Set, tempNames, cloneAndCheckNames(names));
		$set(this, subjectAlternativeGeneralNames, parseNames(tempNames));
		$set(this, subjectAlternativeNames, tempNames);
	}
}

void X509CertSelector::addSubjectAlternativeName(int32_t type, $String* name) {
	addSubjectAlternativeNameInternal(type, name);
}

void X509CertSelector::addSubjectAlternativeName(int32_t type, $bytes* name) {
	addSubjectAlternativeNameInternal(type, $($nc(name)->clone()));
}

void X509CertSelector::addSubjectAlternativeNameInternal(int32_t type, Object$* name) {
	$useLocalCurrentObjectStackCache();
	$var($GeneralNameInterface, tempName, makeGeneralNameInterface(type, name));
	if (this->subjectAlternativeNames == nullptr) {
		$set(this, subjectAlternativeNames, $new($HashSet));
	}
	if (this->subjectAlternativeGeneralNames == nullptr) {
		$set(this, subjectAlternativeGeneralNames, $new($HashSet));
	}
	$var($List, list, $new($ArrayList, 2));
	list->add($($Integer::valueOf(type)));
	list->add(name);
	$nc(this->subjectAlternativeNames)->add(list);
	$nc(this->subjectAlternativeGeneralNames)->add(tempName);
}

$Set* X509CertSelector::parseNames($Collection* names) {
	$init(X509CertSelector);
	$useLocalCurrentObjectStackCache();
	$var($Set, genNames, $new($HashSet));
	{
		$var($Iterator, i$, $nc(names)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, nameList, $cast($List, i$->next()));
			{
				if ($nc(nameList)->size() != 2) {
					$throwNew($IOException, "name list size not 2"_s);
				}
				$var($Object, o, $nc(nameList)->get(0));
				$var($Integer, nameType, nullptr);
				bool var$0 = $instanceOf($Integer, o);
				if (var$0) {
					$assign(nameType, $cast($Integer, o));
					var$0 = true;
				}
				if (!(var$0)) {
					$throwNew($IOException, "expected an Integer"_s);
				}
				$assign(o, nameList->get(1));
				genNames->add($(makeGeneralNameInterface($nc(nameType)->intValue(), o)));
			}
		}
	}
	return genNames;
}

bool X509CertSelector::equalNames($Collection* object1, $Collection* object2) {
	$init(X509CertSelector);
	if ((object1 == nullptr) || (object2 == nullptr)) {
		return object1 == object2;
	}
	return $nc(object1)->equals(object2);
}

$GeneralNameInterface* X509CertSelector::makeGeneralNameInterface(int32_t type, Object$* name) {
	$init(X509CertSelector);
	$useLocalCurrentObjectStackCache();
	$var($GeneralNameInterface, result, nullptr);
	if (X509CertSelector::debug != nullptr) {
		$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.makeGeneralNameInterface("_s, $$str(type), ")..."_s}));
	}
	{
		$var($String, nameAsString, nullptr);
		bool var$0 = $instanceOf($String, name);
		if (var$0) {
			$assign(nameAsString, $cast($String, name));
			var$0 = true;
		}
		if (var$0) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.makeGeneralNameInterface() name is String: "_s, nameAsString}));
			}
			switch (type) {
			case X509CertSelector::NAME_RFC822:
				{
					$assign(result, $new($RFC822Name, nameAsString));
					break;
				}
			case X509CertSelector::NAME_DNS:
				{
					$assign(result, $new($DNSName, nameAsString));
					break;
				}
			case X509CertSelector::NAME_DIRECTORY:
				{
					$assign(result, $new($X500Name, nameAsString));
					break;
				}
			case X509CertSelector::NAME_URI:
				{
					$assign(result, $new($URIName, nameAsString));
					break;
				}
			case X509CertSelector::NAME_IP:
				{
					$assign(result, $new($IPAddressName, nameAsString));
					break;
				}
			case X509CertSelector::NAME_OID:
				{
					$assign(result, $new($OIDName, nameAsString));
					break;
				}
			default:
				{
					$throwNew($IOException, $$str({"unable to parse String names of type "_s, $$str(type)}));
				}
			}
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.makeGeneralNameInterface() result: "_s, $($nc($of(result))->toString())}));
			}
		} else if ($instanceOf($bytes, name)) {
			$var($DerValue, val, $new($DerValue, $cast($bytes, name)));
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.makeGeneralNameInterface() is byte[]"_s);
			}
			switch (type) {
			case X509CertSelector::NAME_ANY:
				{
					$assign(result, $new($OtherName, val));
					break;
				}
			case X509CertSelector::NAME_RFC822:
				{
					$assign(result, $new($RFC822Name, val));
					break;
				}
			case X509CertSelector::NAME_DNS:
				{
					$assign(result, $new($DNSName, val));
					break;
				}
			case X509CertSelector::NAME_X400:
				{
					$assign(result, $new($X400Address, val));
					break;
				}
			case X509CertSelector::NAME_DIRECTORY:
				{
					$assign(result, $new($X500Name, val));
					break;
				}
			case X509CertSelector::NAME_EDI:
				{
					$assign(result, $new($EDIPartyName, val));
					break;
				}
			case X509CertSelector::NAME_URI:
				{
					$assign(result, $new($URIName, val));
					break;
				}
			case X509CertSelector::NAME_IP:
				{
					$assign(result, $new($IPAddressName, val));
					break;
				}
			case X509CertSelector::NAME_OID:
				{
					$assign(result, $new($OIDName, val));
					break;
				}
			default:
				{
					$throwNew($IOException, $$str({"unable to parse byte array names of type "_s, $$str(type)}));
				}
			}
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.makeGeneralNameInterface() result: "_s, $($nc($of(result))->toString())}));
			}
		} else {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.makeGeneralName() input name not String or byte array"_s);
			}
			$throwNew($IOException, "name not String or byte array"_s);
		}
	}
	return result;
}

void X509CertSelector::setNameConstraints($bytes* bytes) {
	if (bytes == nullptr) {
		$set(this, ncBytes, nullptr);
		$set(this, nc, nullptr);
	} else {
		$set(this, ncBytes, $cast($bytes, $nc(bytes)->clone()));
		$set(this, nc, $new($NameConstraintsExtension, X509CertSelector::FALSE, $of(bytes)));
	}
}

void X509CertSelector::setBasicConstraints(int32_t minMaxPathLen) {
	if (minMaxPathLen < -2) {
		$throwNew($IllegalArgumentException, "basic constraints less than -2"_s);
	}
	this->basicConstraints = minMaxPathLen;
}

void X509CertSelector::setPolicy($Set* certPolicySet) {
	$useLocalCurrentObjectStackCache();
	if (certPolicySet == nullptr) {
		$set(this, policySet, nullptr);
		$set(this, policy, nullptr);
	} else {
		$var($Set, tempSet, $Collections::unmodifiableSet($$new($HashSet, static_cast<$Collection*>(certPolicySet))));
		$var($Iterator, i, $nc(tempSet)->iterator());
		$var($Vector, polIdVector, $new($Vector));
		while ($nc(i)->hasNext()) {
			$var($Object, o, i->next());
			if (!($instanceOf($String, o))) {
				$throwNew($IOException, "non String in certPolicySet"_s);
			}
			polIdVector->add($$new($CertificatePolicyId, $($ObjectIdentifier::of($cast($String, o)))));
		}
		$set(this, policySet, tempSet);
		$set(this, policy, $new($CertificatePolicySet, polIdVector));
	}
}

void X509CertSelector::setPathToNames($Collection* names) {
	if ((names == nullptr) || $nc(names)->isEmpty()) {
		$set(this, pathToNames, nullptr);
		$set(this, pathToGeneralNames, nullptr);
	} else {
		$var($Set, tempNames, cloneAndCheckNames(names));
		$set(this, pathToGeneralNames, parseNames(tempNames));
		$set(this, pathToNames, tempNames);
	}
}

void X509CertSelector::setPathToNamesInternal($Set* names) {
	$set(this, pathToNames, $Collections::emptySet());
	$set(this, pathToGeneralNames, names);
}

void X509CertSelector::addPathToName(int32_t type, $String* name) {
	addPathToNameInternal(type, name);
}

void X509CertSelector::addPathToName(int32_t type, $bytes* name) {
	addPathToNameInternal(type, $($nc(name)->clone()));
}

void X509CertSelector::addPathToNameInternal(int32_t type, Object$* name) {
	$useLocalCurrentObjectStackCache();
	$var($GeneralNameInterface, tempName, makeGeneralNameInterface(type, name));
	if (this->pathToGeneralNames == nullptr) {
		$set(this, pathToNames, $new($HashSet));
		$set(this, pathToGeneralNames, $new($HashSet));
	}
	$var($List, list, $new($ArrayList, 2));
	list->add($($Integer::valueOf(type)));
	list->add(name);
	$nc(this->pathToNames)->add(list);
	$nc(this->pathToGeneralNames)->add(tempName);
}

$X509Certificate* X509CertSelector::getCertificate() {
	return this->x509Cert;
}

$BigInteger* X509CertSelector::getSerialNumber() {
	return this->serialNumber;
}

$X500Principal* X509CertSelector::getIssuer() {
	return this->issuer;
}

$String* X509CertSelector::getIssuerAsString() {
	return (this->issuer == nullptr ? ($String*)nullptr : $nc(this->issuer)->getName());
}

$bytes* X509CertSelector::getIssuerAsBytes() {
	return (this->issuer == nullptr ? ($bytes*)nullptr : $nc(this->issuer)->getEncoded());
}

$X500Principal* X509CertSelector::getSubject() {
	return this->subject;
}

$String* X509CertSelector::getSubjectAsString() {
	return (this->subject == nullptr ? ($String*)nullptr : $nc(this->subject)->getName());
}

$bytes* X509CertSelector::getSubjectAsBytes() {
	return (this->subject == nullptr ? ($bytes*)nullptr : $nc(this->subject)->getEncoded());
}

$bytes* X509CertSelector::getSubjectKeyIdentifier() {
	if (this->subjectKeyID == nullptr) {
		return nullptr;
	}
	return $cast($bytes, $nc(this->subjectKeyID)->clone());
}

$bytes* X509CertSelector::getAuthorityKeyIdentifier() {
	if (this->authorityKeyID == nullptr) {
		return nullptr;
	}
	return $cast($bytes, $nc(this->authorityKeyID)->clone());
}

$Date* X509CertSelector::getCertificateValid() {
	if (this->certificateValid == nullptr) {
		return nullptr;
	}
	return $cast($Date, $nc(this->certificateValid)->clone());
}

$Date* X509CertSelector::getPrivateKeyValid() {
	if (this->privateKeyValid == nullptr) {
		return nullptr;
	}
	return $cast($Date, $nc(this->privateKeyValid)->clone());
}

$String* X509CertSelector::getSubjectPublicKeyAlgID() {
	if (this->subjectPublicKeyAlgID == nullptr) {
		return nullptr;
	}
	return $nc(this->subjectPublicKeyAlgID)->toString();
}

$PublicKey* X509CertSelector::getSubjectPublicKey() {
	return this->subjectPublicKey;
}

$booleans* X509CertSelector::getKeyUsage() {
	if (this->keyUsage == nullptr) {
		return nullptr;
	}
	return $cast($booleans, $nc(this->keyUsage)->clone());
}

$Set* X509CertSelector::getExtendedKeyUsage() {
	return this->keyPurposeSet;
}

bool X509CertSelector::getMatchAllSubjectAltNames() {
	return this->matchAllSubjectAltNames;
}

$Collection* X509CertSelector::getSubjectAlternativeNames() {
	if (this->subjectAlternativeNames == nullptr) {
		return nullptr;
	}
	return cloneNames(this->subjectAlternativeNames);
}

$Set* X509CertSelector::cloneNames($Collection* names) {
	$init(X509CertSelector);
	$useLocalCurrentObjectStackCache();
	try {
		return cloneAndCheckNames(names);
	} catch ($IOException& e) {
		$throwNew($RuntimeException, $$str({"cloneNames encountered IOException: "_s, $(e->getMessage())}));
	}
	$shouldNotReachHere();
}

$Set* X509CertSelector::cloneAndCheckNames($Collection* names) {
	$init(X509CertSelector);
	$useLocalCurrentObjectStackCache();
	$var($Set, namesCopy, $new($HashSet));
	{
		$var($Iterator, i$, $nc(names)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, o, $cast($List, i$->next()));
			{
				namesCopy->add($$new($ArrayList, static_cast<$Collection*>(o)));
			}
		}
	}
	{
		$var($Iterator, i$, namesCopy->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, list, $cast($List, i$->next()));
			{
				$var($List, nameList, list);
				if ($nc(nameList)->size() != 2) {
					$throwNew($IOException, "name list size not 2"_s);
				}
				$var($Object, o, $nc(nameList)->get(0));
				$var($Integer, nameType, nullptr);
				bool var$0 = $instanceOf($Integer, o);
				if (var$0) {
					$assign(nameType, $cast($Integer, o));
					var$0 = true;
				}
				if (!(var$0)) {
					$throwNew($IOException, "expected an Integer"_s);
				}
				bool var$1 = ($nc(nameType)->intValue() < 0);
				if (var$1 || ($nc(nameType)->intValue() > 8)) {
					$throwNew($IOException, "name type not 0-8"_s);
				}
				$var($Object, nameObject, nameList->get(1));
				if (!($instanceOf($bytes, nameObject)) && !($instanceOf($String, nameObject))) {
					if (X509CertSelector::debug != nullptr) {
						$nc(X509CertSelector::debug)->println("X509CertSelector.cloneAndCheckNames() name not byte array"_s);
					}
					$throwNew($IOException, "name not byte array or String"_s);
				}
				if ($instanceOf($bytes, nameObject)) {
					nameList->set(1, $($nc(($cast($bytes, nameObject)))->clone()));
				}
			}
		}
	}
	return namesCopy;
}

$bytes* X509CertSelector::getNameConstraints() {
	if (this->ncBytes == nullptr) {
		return nullptr;
	} else {
		return $cast($bytes, $nc(this->ncBytes)->clone());
	}
}

int32_t X509CertSelector::getBasicConstraints() {
	return this->basicConstraints;
}

$Set* X509CertSelector::getPolicy() {
	return this->policySet;
}

$Collection* X509CertSelector::getPathToNames() {
	if (this->pathToNames == nullptr) {
		return nullptr;
	}
	return cloneNames(this->pathToNames);
}

$String* X509CertSelector::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("X509CertSelector: [\n"_s);
	if (this->x509Cert != nullptr) {
		sb->append($$str({"  Certificate: "_s, $($nc(this->x509Cert)->toString()), "\n"_s}));
	}
	if (this->serialNumber != nullptr) {
		sb->append($$str({"  Serial Number: "_s, $($nc(this->serialNumber)->toString()), "\n"_s}));
	}
	if (this->issuer != nullptr) {
		sb->append($$str({"  Issuer: "_s, $(getIssuerAsString()), "\n"_s}));
	}
	if (this->subject != nullptr) {
		sb->append($$str({"  Subject: "_s, $(getSubjectAsString()), "\n"_s}));
	}
	sb->append($$str({"  matchAllSubjectAltNames flag: "_s, $($String::valueOf(this->matchAllSubjectAltNames)), "\n"_s}));
	if (this->subjectAlternativeNames != nullptr) {
		sb->append("  SubjectAlternativeNames:\n"_s);
		$var($Iterator, i, $nc(this->subjectAlternativeNames)->iterator());
		while ($nc(i)->hasNext()) {
			$var($List, list, $cast($List, i->next()));
			$var($String, var$1, $$str({"    type "_s, $($nc(list)->get(0)), ", name "_s}));
			$var($String, var$0, $$concat(var$1, $(list->get(1))));
			sb->append($$concat(var$0, "\n"_s));
		}
	}
	if (this->subjectKeyID != nullptr) {
		$var($HexDumpEncoder, enc, $new($HexDumpEncoder));
		sb->append($$str({"  Subject Key Identifier: "_s, $(enc->encodeBuffer(this->subjectKeyID)), "\n"_s}));
	}
	if (this->authorityKeyID != nullptr) {
		$var($HexDumpEncoder, enc, $new($HexDumpEncoder));
		sb->append($$str({"  Authority Key Identifier: "_s, $(enc->encodeBuffer(this->authorityKeyID)), "\n"_s}));
	}
	if (this->certificateValid != nullptr) {
		sb->append($$str({"  Certificate Valid: "_s, $($nc(this->certificateValid)->toString()), "\n"_s}));
	}
	if (this->privateKeyValid != nullptr) {
		sb->append($$str({"  Private Key Valid: "_s, $($nc(this->privateKeyValid)->toString()), "\n"_s}));
	}
	if (this->subjectPublicKeyAlgID != nullptr) {
		sb->append($$str({"  Subject Public Key AlgID: "_s, $($nc(this->subjectPublicKeyAlgID)->toString()), "\n"_s}));
	}
	if (this->subjectPublicKey != nullptr) {
		sb->append($$str({"  Subject Public Key: "_s, $($nc($of(this->subjectPublicKey))->toString()), "\n"_s}));
	}
	if (this->keyUsage != nullptr) {
		sb->append($$str({"  Key Usage: "_s, $(keyUsageToString(this->keyUsage)), "\n"_s}));
	}
	if (this->keyPurposeSet != nullptr) {
		sb->append($$str({"  Extended Key Usage: "_s, $($nc($of(this->keyPurposeSet))->toString()), "\n"_s}));
	}
	if (this->policy != nullptr) {
		sb->append($$str({"  Policy: "_s, $($nc(this->policy)->toString()), "\n"_s}));
	}
	if (this->pathToGeneralNames != nullptr) {
		sb->append("  Path to names:\n"_s);
		$var($Iterator, i, $nc(this->pathToGeneralNames)->iterator());
		while ($nc(i)->hasNext()) {
			sb->append($$str({"    "_s, $(i->next()), "\n"_s}));
		}
	}
	sb->append("]"_s);
	return sb->toString();
}

$String* X509CertSelector::keyUsageToString($booleans* k) {
	$init(X509CertSelector);
	$var($String, s, "KeyUsage [\n"_s);
	try {
		if ($nc(k)->get(0)) {
			$plusAssign(s, "  DigitalSignature\n"_s);
		}
		if ($nc(k)->get(1)) {
			$plusAssign(s, "  Non_repudiation\n"_s);
		}
		if ($nc(k)->get(2)) {
			$plusAssign(s, "  Key_Encipherment\n"_s);
		}
		if ($nc(k)->get(3)) {
			$plusAssign(s, "  Data_Encipherment\n"_s);
		}
		if ($nc(k)->get(4)) {
			$plusAssign(s, "  Key_Agreement\n"_s);
		}
		if ($nc(k)->get(5)) {
			$plusAssign(s, "  Key_CertSign\n"_s);
		}
		if ($nc(k)->get(6)) {
			$plusAssign(s, "  Crl_Sign\n"_s);
		}
		if ($nc(k)->get(7)) {
			$plusAssign(s, "  Encipher_Only\n"_s);
		}
		if ($nc(k)->get(8)) {
			$plusAssign(s, "  Decipher_Only\n"_s);
		}
	} catch ($ArrayIndexOutOfBoundsException& ex) {
	}
	$plusAssign(s, "]\n"_s);
	return (s);
}

$Extension* X509CertSelector::getExtensionObject($X509Certificate* cert, $KnownOIDs* extId) {
	$init(X509CertSelector);
	$useLocalCurrentObjectStackCache();
	{
		$var($X509CertImpl, impl, nullptr);
		bool var$0 = $instanceOf($X509CertImpl, cert);
		if (var$0) {
			$assign(impl, $cast($X509CertImpl, cert));
			var$0 = true;
		}
		if (var$0) {
			$init($X509CertSelector$1);
			switch ($nc($X509CertSelector$1::$SwitchMap$sun$security$util$KnownOIDs)->get($nc((extId))->ordinal())) {
			case 1:
				{
					return $nc(impl)->getPrivateKeyUsageExtension();
				}
			case 2:
				{
					return $nc(impl)->getSubjectAlternativeNameExtension();
				}
			case 3:
				{
					return $nc(impl)->getNameConstraintsExtension();
				}
			case 4:
				{
					return $nc(impl)->getCertificatePoliciesExtension();
				}
			case 5:
				{
					return $nc(impl)->getExtendedKeyUsageExtension();
				}
			default:
				{
					return nullptr;
				}
			}
		}
	}
	$var($bytes, rawExtVal, $nc(cert)->getExtensionValue($($nc(extId)->value())));
	if (rawExtVal == nullptr) {
		return nullptr;
	}
	$var($DerInputStream, in, $new($DerInputStream, rawExtVal));
	$var($bytes, encoded, in->getOctetString());
	$init($X509CertSelector$1);
	switch ($nc($X509CertSelector$1::$SwitchMap$sun$security$util$KnownOIDs)->get($nc((extId))->ordinal())) {
	case 1:
		{
			try {
				return $new($PrivateKeyUsageExtension, X509CertSelector::FALSE, $of(encoded));
			} catch ($CertificateException& ex) {
				$throwNew($IOException, $(ex->getMessage()));
			}
		}
	case 2:
		{
			return $new($SubjectAlternativeNameExtension, X509CertSelector::FALSE, $of(encoded));
		}
	case 3:
		{
			return $new($NameConstraintsExtension, X509CertSelector::FALSE, $of(encoded));
		}
	case 4:
		{
			return $new($CertificatePoliciesExtension, X509CertSelector::FALSE, $of(encoded));
		}
	case 5:
		{
			return $new($ExtendedKeyUsageExtension, X509CertSelector::FALSE, $of(encoded));
		}
	default:
		{
			return nullptr;
		}
	}
}

bool X509CertSelector::match($Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($X509Certificate, xcert, nullptr);
	bool var$0 = $instanceOf($X509Certificate, cert);
	if (var$0) {
		$assign(xcert, $cast($X509Certificate, cert));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (X509CertSelector::debug != nullptr) {
		$var($String, var$4, $$str({"X509CertSelector.match(SN: "_s, $($nc(($($nc(xcert)->getSerialNumber())))->toString(16)), "\n  Issuer: "_s}));
		$var($String, var$3, $$concat(var$4, $(xcert->getIssuerX500Principal())));
		$var($String, var$2, $$concat(var$3, "\n  Subject: "_s));
		$var($String, var$1, $$concat(var$2, $(xcert->getSubjectX500Principal())));
		$nc(X509CertSelector::debug)->println($$concat(var$1, ")"_s));
	}
	if (this->x509Cert != nullptr) {
		if (!$nc(this->x509Cert)->equals(xcert)) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: certs don\'t match"_s);
			}
			return false;
		}
	}
	if (this->serialNumber != nullptr) {
		if (!$nc(this->serialNumber)->equals($($nc(xcert)->getSerialNumber()))) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: serial numbers don\'t match"_s);
			}
			return false;
		}
	}
	if (this->issuer != nullptr) {
		if (!$nc(this->issuer)->equals($($nc(xcert)->getIssuerX500Principal()))) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: issuer DNs don\'t match"_s);
			}
			return false;
		}
	}
	if (this->subject != nullptr) {
		if (!$nc(this->subject)->equals($($nc(xcert)->getSubjectX500Principal()))) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: subject DNs don\'t match"_s);
			}
			return false;
		}
	}
	if (this->certificateValid != nullptr) {
		try {
			$nc(xcert)->checkValidity(this->certificateValid);
		} catch ($CertificateException& e) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: certificate not within validity period"_s);
			}
			return false;
		}
	}
	if (this->subjectPublicKeyBytes != nullptr) {
		$var($bytes, certKey, $nc($($nc(xcert)->getPublicKey()))->getEncoded());
		if (!$Arrays::equals(this->subjectPublicKeyBytes, certKey)) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: subject public keys don\'t match"_s);
			}
			return false;
		}
	}
	bool var$14 = matchBasicConstraints(xcert);
	bool var$13 = var$14 && matchKeyUsage(xcert);
	bool var$12 = var$13 && matchExtendedKeyUsage(xcert);
	bool var$11 = var$12 && matchSubjectKeyID(xcert);
	bool var$10 = var$11 && matchAuthorityKeyID(xcert);
	bool var$9 = var$10 && matchPrivateKeyValid(xcert);
	bool var$8 = var$9 && matchSubjectPublicKeyAlgID(xcert);
	bool var$7 = var$8 && matchPolicy(xcert);
	bool var$6 = var$7 && matchSubjectAlternativeNames(xcert);
	bool var$5 = var$6 && matchPathToNames(xcert);
	bool result = var$5 && matchNameConstraints(xcert);
	if (result && (X509CertSelector::debug != nullptr)) {
		$nc(X509CertSelector::debug)->println("X509CertSelector.match returning: true"_s);
	}
	return result;
}

bool X509CertSelector::matchSubjectKeyID($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->subjectKeyID == nullptr) {
		return true;
	}
	try {
		$var($bytes, extVal, $nc(xcert)->getExtensionValue("2.5.29.14"_s));
		if (extVal == nullptr) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: no subject key ID extension"_s);
			}
			return false;
		}
		$var($DerInputStream, in, $new($DerInputStream, extVal));
		$var($bytes, certSubjectKeyID, in->getOctetString());
		if (certSubjectKeyID == nullptr || !$Arrays::equals(this->subjectKeyID, certSubjectKeyID)) {
			if (X509CertSelector::debug != nullptr) {
				$var($String, var$0, $$str({"X509CertSelector.match: subject key IDs don\'t match\nX509CertSelector.match: subjectKeyID: "_s, $($Arrays::toString(this->subjectKeyID)), "\nX509CertSelector.match: certSubjectKeyID: "_s}));
				$nc(X509CertSelector::debug)->println($$concat(var$0, $($Arrays::toString(certSubjectKeyID))));
			}
			return false;
		}
	} catch ($IOException& ex) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: exception in subject key ID check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchAuthorityKeyID($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->authorityKeyID == nullptr) {
		return true;
	}
	try {
		$var($bytes, extVal, $nc(xcert)->getExtensionValue("2.5.29.35"_s));
		if (extVal == nullptr) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: no authority key ID extension"_s);
			}
			return false;
		}
		$var($DerInputStream, in, $new($DerInputStream, extVal));
		$var($bytes, certAuthKeyID, in->getOctetString());
		if (certAuthKeyID == nullptr || !$Arrays::equals(this->authorityKeyID, certAuthKeyID)) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: authority key IDs don\'t match"_s);
			}
			return false;
		}
	} catch ($IOException& ex) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: exception in authority key ID check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchPrivateKeyValid($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->privateKeyValid == nullptr) {
		return true;
	}
	$var($PrivateKeyUsageExtension, ext, nullptr);
	try {
		$init($KnownOIDs);
		$assign(ext, $cast($PrivateKeyUsageExtension, getExtensionObject(xcert, $KnownOIDs::PrivateKeyUsage)));
		if (ext != nullptr) {
			ext->valid(this->privateKeyValid);
		}
	} catch ($CertificateExpiredException& e1) {
		if (X509CertSelector::debug != nullptr) {
			$var($String, time, "n/a"_s);
			try {
				$init($PrivateKeyUsageExtension);
				$var($Date, notAfter, $cast($Date, $nc(ext)->get($PrivateKeyUsageExtension::NOT_AFTER)));
				$assign(time, $nc(notAfter)->toString());
			} catch ($CertificateException& ex) {
			}
			$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: private key usage not within validity date; ext.NOT_After: "_s, time, "; X509CertSelector: "_s, $(this->toString())}));
			e1->printStackTrace();
		}
		return false;
	} catch ($CertificateNotYetValidException& e2) {
		if (X509CertSelector::debug != nullptr) {
			$var($String, time, "n/a"_s);
			try {
				$init($PrivateKeyUsageExtension);
				$var($Date, notBefore, $cast($Date, $nc(ext)->get($PrivateKeyUsageExtension::NOT_BEFORE)));
				$assign(time, $nc(notBefore)->toString());
			} catch ($CertificateException& ex) {
			}
			$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: private key usage not within validity date; ext.NOT_BEFORE: "_s, time, "; X509CertSelector: "_s, $(this->toString())}));
			e2->printStackTrace();
		}
		return false;
	} catch ($IOException& e4) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: IOException in private key usage check; X509CertSelector: "_s, $(this->toString())}));
			e4->printStackTrace();
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchSubjectPublicKeyAlgID($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->subjectPublicKeyAlgID == nullptr) {
		return true;
	}
	try {
		$var($bytes, encodedKey, $nc($($nc(xcert)->getPublicKey()))->getEncoded());
		$var($DerValue, val, $new($DerValue, encodedKey));
		if (val->tag != $DerValue::tag_Sequence) {
			$throwNew($IOException, "invalid key format"_s);
		}
		$var($AlgorithmId, algID, $AlgorithmId::parse($($nc(val->data$)->getDerValue())));
		if (X509CertSelector::debug != nullptr) {
			$var($String, var$0, $$str({"X509CertSelector.match: subjectPublicKeyAlgID = "_s, this->subjectPublicKeyAlgID, ", xcert subjectPublicKeyAlgID = "_s}));
			$nc(X509CertSelector::debug)->println($$concat(var$0, $($nc(algID)->getOID())));
		}
		if (!$nc(this->subjectPublicKeyAlgID)->equals($($nc(algID)->getOID()))) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: subject public key alg IDs don\'t match"_s);
			}
			return false;
		}
	} catch ($IOException& e5) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: IOException in subject public key algorithm OID check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchKeyUsage($X509Certificate* xcert) {
	if (this->keyUsage == nullptr) {
		return true;
	}
	$var($booleans, certKeyUsage, $nc(xcert)->getKeyUsage());
	if (certKeyUsage != nullptr) {
		for (int32_t keyBit = 0; keyBit < $nc(this->keyUsage)->length; ++keyBit) {
			if ($nc(this->keyUsage)->get(keyBit) && ((keyBit >= certKeyUsage->length) || !certKeyUsage->get(keyBit))) {
				if (X509CertSelector::debug != nullptr) {
					$nc(X509CertSelector::debug)->println("X509CertSelector.match: key usage bits don\'t match"_s);
				}
				return false;
			}
		}
	}
	return true;
}

bool X509CertSelector::matchExtendedKeyUsage($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if ((this->keyPurposeSet == nullptr) || $nc(this->keyPurposeSet)->isEmpty()) {
		return true;
	}
	try {
		$init($KnownOIDs);
		$var($ExtendedKeyUsageExtension, ext, $cast($ExtendedKeyUsageExtension, getExtensionObject(xcert, $KnownOIDs::extendedKeyUsage)));
		if (ext != nullptr) {
			$init($ExtendedKeyUsageExtension);
			$var($Vector, certKeyPurposeVector, $cast($Vector, ext->get($ExtendedKeyUsageExtension::USAGES)));
			bool var$0 = !$nc(certKeyPurposeVector)->contains(X509CertSelector::ANY_EXTENDED_KEY_USAGE);
			if (var$0 && !certKeyPurposeVector->containsAll(this->keyPurposeOIDSet)) {
				if (X509CertSelector::debug != nullptr) {
					$nc(X509CertSelector::debug)->println("X509CertSelector.match: cert failed extendedKeyUsage criterion"_s);
				}
				return false;
			}
		}
	} catch ($IOException& ex) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: IOException in extended key usage check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchSubjectAlternativeNames($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if ((this->subjectAlternativeNames == nullptr) || $nc(this->subjectAlternativeNames)->isEmpty()) {
		return true;
	}
	try {
		$init($KnownOIDs);
		$var($SubjectAlternativeNameExtension, sanExt, $cast($SubjectAlternativeNameExtension, getExtensionObject(xcert, $KnownOIDs::SubjectAlternativeName)));
		if (sanExt == nullptr) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: no subject alternative name extension"_s);
			}
			return false;
		}
		$init($SubjectAlternativeNameExtension);
		$var($GeneralNames, certNames, $cast($GeneralNames, $nc(sanExt)->get($SubjectAlternativeNameExtension::SUBJECT_NAME)));
		$var($Iterator, i, $nc(this->subjectAlternativeGeneralNames)->iterator());
		while ($nc(i)->hasNext()) {
			$var($GeneralNameInterface, matchName, $cast($GeneralNameInterface, i->next()));
			bool found = false;
			{
				$var($Iterator, t, $nc(certNames)->iterator());
				for (; $nc(t)->hasNext() && !found;) {
					$var($GeneralNameInterface, certName, $nc(($cast($GeneralName, $(t->next()))))->getName());
					found = $nc($of(certName))->equals(matchName);
				}
			}
			if (!found && (this->matchAllSubjectAltNames || !i->hasNext())) {
				if (X509CertSelector::debug != nullptr) {
					$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: subject alternative name "_s, matchName, " not found"_s}));
				}
				return false;
			} else if (found && !this->matchAllSubjectAltNames) {
				break;
			}
		}
	} catch ($IOException& ex) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: IOException in subject alternative name check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchNameConstraints($X509Certificate* xcert) {
	if (this->nc == nullptr) {
		return true;
	}
	try {
		if (!$nc(this->nc)->verify(xcert)) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: name constraints not satisfied"_s);
			}
			return false;
		}
	} catch ($IOException& e) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: IOException in name constraints check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchPolicy($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->policy == nullptr) {
		return true;
	}
	try {
		$init($KnownOIDs);
		$var($CertificatePoliciesExtension, ext, $cast($CertificatePoliciesExtension, getExtensionObject(xcert, $KnownOIDs::CertificatePolicies)));
		if (ext == nullptr) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: no certificate policy extension"_s);
			}
			return false;
		}
		$init($CertificatePoliciesExtension);
		$var($List, policies, $cast($List, $nc(ext)->get($CertificatePoliciesExtension::POLICIES)));
		$var($List, policyIDs, $new($ArrayList, $nc(policies)->size()));
		{
			$var($Iterator, i$, $nc(policies)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PolicyInformation, info, $cast($PolicyInformation, i$->next()));
				{
					policyIDs->add($($nc(info)->getPolicyIdentifier()));
				}
			}
		}
		if (this->policy != nullptr) {
			bool foundOne = false;
			if ($nc($($nc(this->policy)->getCertPolicyIds()))->isEmpty()) {
				if (policyIDs->isEmpty()) {
					if (X509CertSelector::debug != nullptr) {
						$nc(X509CertSelector::debug)->println("X509CertSelector.match: cert failed policyAny criterion"_s);
					}
					return false;
				}
			} else {
				{
					$var($Iterator, i$, $nc($($nc(this->policy)->getCertPolicyIds()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($CertificatePolicyId, id, $cast($CertificatePolicyId, i$->next()));
						{
							if (policyIDs->contains(id)) {
								foundOne = true;
								break;
							}
						}
					}
				}
				if (!foundOne) {
					if (X509CertSelector::debug != nullptr) {
						$nc(X509CertSelector::debug)->println("X509CertSelector.match: cert failed policyAny criterion"_s);
					}
					return false;
				}
			}
		}
	} catch ($IOException& ex) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: IOException in certificate policy ID check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchPathToNames($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->pathToGeneralNames == nullptr) {
		return true;
	}
	try {
		$init($KnownOIDs);
		$var($NameConstraintsExtension, ext, $cast($NameConstraintsExtension, getExtensionObject(xcert, $KnownOIDs::NameConstraints)));
		if (ext == nullptr) {
			return true;
		}
		if ((X509CertSelector::debug != nullptr) && $Debug::isOn("certpath"_s)) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match pathToNames:\n"_s);
			$var($Iterator, i, $nc(this->pathToGeneralNames)->iterator());
			while ($nc(i)->hasNext()) {
				$nc(X509CertSelector::debug)->println($$str({"    "_s, $(i->next()), "\n"_s}));
			}
		}
		$init($NameConstraintsExtension);
		$var($GeneralSubtrees, permitted, $cast($GeneralSubtrees, $nc(ext)->get($NameConstraintsExtension::PERMITTED_SUBTREES)));
		$var($GeneralSubtrees, excluded, $cast($GeneralSubtrees, ext->get($NameConstraintsExtension::EXCLUDED_SUBTREES)));
		if (excluded != nullptr) {
			if (matchExcluded(excluded) == false) {
				return false;
			}
		}
		if (permitted != nullptr) {
			if (matchPermitted(permitted) == false) {
				return false;
			}
		}
	} catch ($IOException& ex) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println("X509CertSelector.match: IOException in name constraints check"_s);
		}
		return false;
	}
	return true;
}

bool X509CertSelector::matchExcluded($GeneralSubtrees* excluded) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, t, $nc(excluded)->iterator());
		for (; $nc(t)->hasNext();) {
			$var($GeneralSubtree, tree, $cast($GeneralSubtree, t->next()));
			$var($GeneralNameInterface, excludedName, $nc($($nc(tree)->getName()))->getName());
			$var($Iterator, i, $nc(this->pathToGeneralNames)->iterator());
			while ($nc(i)->hasNext()) {
				$var($GeneralNameInterface, pathToName, $cast($GeneralNameInterface, i->next()));
				int32_t var$0 = $nc(excludedName)->getType();
				if (var$0 == $nc(pathToName)->getType()) {
					switch (pathToName->constrains(excludedName)) {
					case $GeneralNameInterface::NAME_WIDENS:
						{}
					case $GeneralNameInterface::NAME_MATCH:
						{
							if (X509CertSelector::debug != nullptr) {
								$nc(X509CertSelector::debug)->println("X509CertSelector.match: name constraints inhibit path to specified name"_s);
								$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: excluded name: "_s, pathToName}));
							}
							return false;
						}
					default:
						{}
					}
				}
			}
		}
	}
	return true;
}

bool X509CertSelector::matchPermitted($GeneralSubtrees* permitted) {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, i, $nc(this->pathToGeneralNames)->iterator());
	while ($nc(i)->hasNext()) {
		$var($GeneralNameInterface, pathToName, $cast($GeneralNameInterface, i->next()));
		$var($Iterator, t, $nc(permitted)->iterator());
		bool permittedNameFound = false;
		bool nameTypeFound = false;
		$var($String, names, ""_s);
		while ($nc(t)->hasNext() && !permittedNameFound) {
			$var($GeneralSubtree, tree, $cast($GeneralSubtree, t->next()));
			$var($GeneralNameInterface, permittedName, $nc($($nc(tree)->getName()))->getName());
			int32_t var$0 = $nc(permittedName)->getType();
			if (var$0 == $nc(pathToName)->getType()) {
				nameTypeFound = true;
				$assign(names, $str({names, "  "_s, permittedName}));
				switch (pathToName->constrains(permittedName)) {
				case $GeneralNameInterface::NAME_WIDENS:
					{}
				case $GeneralNameInterface::NAME_MATCH:
					{
						permittedNameFound = true;
						break;
					}
				default:
					{}
				}
			}
		}
		if (!permittedNameFound && nameTypeFound) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: name constraints inhibit path to specified name; permitted names of type "_s, $$str($nc(pathToName)->getType()), ": "_s, names}));
			}
			return false;
		}
	}
	return true;
}

bool X509CertSelector::matchBasicConstraints($X509Certificate* xcert) {
	$useLocalCurrentObjectStackCache();
	if (this->basicConstraints == -1) {
		return true;
	}
	int32_t maxPathLen = $nc(xcert)->getBasicConstraints();
	if (this->basicConstraints == -2) {
		if (maxPathLen != -1) {
			if (X509CertSelector::debug != nullptr) {
				$nc(X509CertSelector::debug)->println("X509CertSelector.match: not an EE cert"_s);
			}
			return false;
		}
	} else if (maxPathLen < this->basicConstraints) {
		if (X509CertSelector::debug != nullptr) {
			$nc(X509CertSelector::debug)->println($$str({"X509CertSelector.match: cert\'s maxPathLen is less than the min maxPathLen set by basicConstraints. ("_s, $$str(maxPathLen), " < "_s, $$str(this->basicConstraints), ")"_s}));
		}
		return false;
	}
	return true;
}

$Set* X509CertSelector::cloneSet($Set* set) {
	$init(X509CertSelector);
	if ($instanceOf($HashSet, set)) {
		$var($Object, clone, $nc(($cast($HashSet, set)))->clone());
		return $cast($Set, clone);
	} else {
		return $new($HashSet, static_cast<$Collection*>(set));
	}
}

$Object* X509CertSelector::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(X509CertSelector, copy, $cast(X509CertSelector, $CertSelector::clone()));
		if (this->subjectAlternativeNames != nullptr) {
			$set($nc(copy), subjectAlternativeNames, cloneSet(this->subjectAlternativeNames));
			$set(copy, subjectAlternativeGeneralNames, cloneSet(this->subjectAlternativeGeneralNames));
		}
		if (this->pathToGeneralNames != nullptr) {
			$set($nc(copy), pathToNames, cloneSet(this->pathToNames));
			$set(copy, pathToGeneralNames, cloneSet(this->pathToGeneralNames));
		}
		return $of(copy);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

void clinit$X509CertSelector($Class* class$) {
	$assignStatic(X509CertSelector::debug, $Debug::getInstance("certpath"_s));
	$init($KnownOIDs);
	$assignStatic(X509CertSelector::ANY_EXTENDED_KEY_USAGE, $ObjectIdentifier::of($KnownOIDs::anyExtendedKeyUsage));
	{
		$CertPathHelperImpl::initialize();
	}
	$init($Boolean);
	$assignStatic(X509CertSelector::FALSE, $Boolean::FALSE);
}

X509CertSelector::X509CertSelector() {
}

$Class* X509CertSelector::load$($String* name, bool initialize) {
	$loadClass(X509CertSelector, name, initialize, &_X509CertSelector_ClassInfo_, clinit$X509CertSelector, allocate$X509CertSelector);
	return class$;
}

$Class* X509CertSelector::class$ = nullptr;

		} // cert
	} // security
} // java