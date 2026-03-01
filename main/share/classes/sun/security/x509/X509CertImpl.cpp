#include <sun/security/x509/X509CertImpl.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedReader.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/math/BigInteger.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateEncodingException.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateNotYetValidException.h>
#include <java/security/cert/CertificateParsingException.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/cert/X509Extension.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Function.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/X509Factory.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/Pem.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/AuthorityInfoAccessExtension.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <sun/security/x509/BasicConstraintsExtension.h>
#include <sun/security/x509/CRLDistributionPointsExtension.h>
#include <sun/security/x509/CertificateAlgorithmId.h>
#include <sun/security/x509/CertificateExtensions.h>
#include <sun/security/x509/CertificatePoliciesExtension.h>
#include <sun/security/x509/CertificateSerialNumber.h>
#include <sun/security/x509/CertificateValidity.h>
#include <sun/security/x509/CertificateVersion.h>
#include <sun/security/x509/CertificateX509Key.h>
#include <sun/security/x509/DNSName.h>
#include <sun/security/x509/ExtendedKeyUsageExtension.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/IPAddressName.h>
#include <sun/security/x509/IssuerAlternativeNameExtension.h>
#include <sun/security/x509/KeyIdentifier.h>
#include <sun/security/x509/KeyUsageExtension.h>
#include <sun/security/x509/NameConstraintsExtension.h>
#include <sun/security/x509/OIDMap.h>
#include <sun/security/x509/OIDName.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/PolicyConstraintsExtension.h>
#include <sun/security/x509/PolicyMappingsExtension.h>
#include <sun/security/x509/PrivateKeyUsageExtension.h>
#include <sun/security/x509/RFC822Name.h>
#include <sun/security/x509/SerialNumber.h>
#include <sun/security/x509/SubjectAlternativeNameExtension.h>
#include <sun/security/x509/SubjectKeyIdentifierExtension.h>
#include <sun/security/x509/URIName.h>
#include <sun/security/x509/UniqueIdentity.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509AttributeName.h>
#include <sun/security/x509/X509CertInfo.h>
#include <jcpp.h>

#undef ALGORITHM
#undef ALGORITHM_ID
#undef ALG_ID
#undef BEGIN_CERT
#undef DN_NAME
#undef DOT
#undef END_CERT
#undef FALSE
#undef INFO
#undef ISSUER
#undef ISSUER_DN
#undef ISSUER_ID
#undef ISSUER_NAME
#undef IS_CA
#undef KEY
#undef KEY_ID
#undef MAX_VALUE
#undef NAME
#undef NAME_DIRECTORY
#undef NAME_DNS
#undef NAME_IP
#undef NAME_OID
#undef NAME_RFC822
#undef NAME_URI
#undef NOT_AFTER
#undef NOT_BEFORE
#undef NUMBER
#undef NUM_STANDARD_KEY_USAGE
#undef PATH_LEN
#undef PUBLIC_KEY
#undef SERIAL_ID
#undef SERIAL_NUMBER
#undef SIG
#undef SIGNATURE
#undef SIGNED_CERT
#undef SIG_ALG
#undef SUBJECT
#undef SUBJECT_DN
#undef SUBJECT_ID
#undef SUBJECT_NAME
#undef US_ASCII
#undef VERSION

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedReader = ::java::io::BufferedReader;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $BigInteger = ::java::math::BigInteger;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Principal = ::java::security::Principal;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateEncodingException = ::java::security::cert::CertificateEncodingException;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateNotYetValidException = ::java::security::cert::CertificateNotYetValidException;
using $CertificateParsingException = ::java::security::cert::CertificateParsingException;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Function = ::java::util::function::Function;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $X509Factory = ::sun::security::provider::X509Factory;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $Pem = ::sun::security::util::Pem;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $AuthorityInfoAccessExtension = ::sun::security::x509::AuthorityInfoAccessExtension;
using $AuthorityKeyIdentifierExtension = ::sun::security::x509::AuthorityKeyIdentifierExtension;
using $BasicConstraintsExtension = ::sun::security::x509::BasicConstraintsExtension;
using $CRLDistributionPointsExtension = ::sun::security::x509::CRLDistributionPointsExtension;
using $CertificateAlgorithmId = ::sun::security::x509::CertificateAlgorithmId;
using $CertificateExtensions = ::sun::security::x509::CertificateExtensions;
using $CertificatePoliciesExtension = ::sun::security::x509::CertificatePoliciesExtension;
using $CertificateSerialNumber = ::sun::security::x509::CertificateSerialNumber;
using $CertificateValidity = ::sun::security::x509::CertificateValidity;
using $CertificateVersion = ::sun::security::x509::CertificateVersion;
using $CertificateX509Key = ::sun::security::x509::CertificateX509Key;
using $DNSName = ::sun::security::x509::DNSName;
using $ExtendedKeyUsageExtension = ::sun::security::x509::ExtendedKeyUsageExtension;
using $Extension = ::sun::security::x509::Extension;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $IPAddressName = ::sun::security::x509::IPAddressName;
using $IssuerAlternativeNameExtension = ::sun::security::x509::IssuerAlternativeNameExtension;
using $KeyIdentifier = ::sun::security::x509::KeyIdentifier;
using $KeyUsageExtension = ::sun::security::x509::KeyUsageExtension;
using $NameConstraintsExtension = ::sun::security::x509::NameConstraintsExtension;
using $OIDMap = ::sun::security::x509::OIDMap;
using $OIDName = ::sun::security::x509::OIDName;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $PolicyConstraintsExtension = ::sun::security::x509::PolicyConstraintsExtension;
using $PolicyMappingsExtension = ::sun::security::x509::PolicyMappingsExtension;
using $PrivateKeyUsageExtension = ::sun::security::x509::PrivateKeyUsageExtension;
using $RFC822Name = ::sun::security::x509::RFC822Name;
using $SerialNumber = ::sun::security::x509::SerialNumber;
using $SubjectAlternativeNameExtension = ::sun::security::x509::SubjectAlternativeNameExtension;
using $SubjectKeyIdentifierExtension = ::sun::security::x509::SubjectKeyIdentifierExtension;
using $URIName = ::sun::security::x509::URIName;
using $UniqueIdentity = ::sun::security::x509::UniqueIdentity;
using $X500Name = ::sun::security::x509::X500Name;
using $X509AttributeName = ::sun::security::x509::X509AttributeName;
using $X509CertInfo = ::sun::security::x509::X509CertInfo;

namespace sun {
	namespace security {
		namespace x509 {

class X509CertImpl$$Lambda$lambda$getFingerprint$0 : public $Function {
	$class(X509CertImpl$$Lambda$lambda$getFingerprint$0, $NO_CLASS_INIT, $Function)
public:
	void init$(X509CertImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* x) override {
		 return $of($nc(inst$)->lambda$getFingerprint$0($cast($String, x)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<X509CertImpl$$Lambda$lambda$getFingerprint$0>());
	}
	X509CertImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo X509CertImpl$$Lambda$lambda$getFingerprint$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(X509CertImpl$$Lambda$lambda$getFingerprint$0, inst$)},
	{}
};
$MethodInfo X509CertImpl$$Lambda$lambda$getFingerprint$0::methodInfos[3] = {
	{"<init>", "(Lsun/security/x509/X509CertImpl;)V", nullptr, $PUBLIC, $method(X509CertImpl$$Lambda$lambda$getFingerprint$0, init$, void, X509CertImpl*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl$$Lambda$lambda$getFingerprint$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo X509CertImpl$$Lambda$lambda$getFingerprint$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.x509.X509CertImpl$$Lambda$lambda$getFingerprint$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* X509CertImpl$$Lambda$lambda$getFingerprint$0::load$($String* name, bool initialize) {
	$loadClass(X509CertImpl$$Lambda$lambda$getFingerprint$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* X509CertImpl$$Lambda$lambda$getFingerprint$0::class$ = nullptr;

$FieldInfo _X509CertImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertImpl, serialVersionUID)},
	{"DOT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertImpl, DOT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, NAME)},
	{"INFO", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, INFO)},
	{"ALG_ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, ALG_ID)},
	{"SIGNATURE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, SIGNATURE)},
	{"SIGNED_CERT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, SIGNED_CERT)},
	{"SUBJECT_DN", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, SUBJECT_DN)},
	{"ISSUER_DN", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, ISSUER_DN)},
	{"SERIAL_ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, SERIAL_ID)},
	{"PUBLIC_KEY", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, PUBLIC_KEY)},
	{"VERSION", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, VERSION)},
	{"SIG_ALG", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, SIG_ALG)},
	{"SIG", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertImpl, SIG)},
	{"readOnly", "Z", nullptr, $PRIVATE, $field(X509CertImpl, readOnly)},
	{"signedCert", "[B", nullptr, $PRIVATE, $field(X509CertImpl, signedCert)},
	{"info", "Lsun/security/x509/X509CertInfo;", nullptr, $PROTECTED, $field(X509CertImpl, info)},
	{"algId", "Lsun/security/x509/AlgorithmId;", nullptr, $PROTECTED, $field(X509CertImpl, algId)},
	{"signature", "[B", nullptr, $PROTECTED, $field(X509CertImpl, signature)},
	{"NUM_STANDARD_KEY_USAGE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertImpl, NUM_STANDARD_KEY_USAGE)},
	{"subjectAlternativeNames", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/util/List<*>;>;", $PRIVATE, $field(X509CertImpl, subjectAlternativeNames)},
	{"issuerAlternativeNames", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/util/List<*>;>;", $PRIVATE, $field(X509CertImpl, issuerAlternativeNames)},
	{"extKeyUsage", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(X509CertImpl, extKeyUsage)},
	{"authInfoAccess", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/x509/AccessDescription;>;", $PRIVATE, $field(X509CertImpl, authInfoAccess)},
	{"verifiedPublicKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(X509CertImpl, verifiedPublicKey)},
	{"verifiedProvider", "Ljava/lang/String;", nullptr, $PRIVATE, $field(X509CertImpl, verifiedProvider)},
	{"verificationResult", "Z", nullptr, $PRIVATE, $field(X509CertImpl, verificationResult)},
	{"fingerprints", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE, $field(X509CertImpl, fingerprints)},
	{}
};

$MethodInfo _X509CertImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(X509CertImpl, init$, void)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(X509CertImpl, init$, void, $bytes*), "java.security.cert.CertificateException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(X509CertImpl, init$, void, $InputStream*), "java.security.cert.CertificateException"},
	{"<init>", "(Lsun/security/x509/X509CertInfo;)V", nullptr, $PUBLIC, $method(X509CertImpl, init$, void, $X509CertInfo*)},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(X509CertImpl, init$, void, $DerValue*), "java.security.cert.CertificateException"},
	{"checkValidity", "()V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, checkValidity, void), "java.security.cert.CertificateExpiredException,java.security.cert.CertificateNotYetValidException"},
	{"checkValidity", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, checkValidity, void, $Date*), "java.security.cert.CertificateExpiredException,java.security.cert.CertificateNotYetValidException"},
	{"cloneAltNames", "(Ljava/util/Collection;)Ljava/util/Collection;", "(Ljava/util/Collection<Ljava/util/List<*>;>;)Ljava/util/Collection<Ljava/util/List<*>;>;", $PRIVATE | $STATIC, $staticMethod(X509CertImpl, cloneAltNames, $Collection*, $Collection*)},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, delete$, void, $String*), "java.security.cert.CertificateException,java.io.IOException"},
	{"derEncode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, derEncode, void, $OutputStream*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, encode, void, $OutputStream*), "java.security.cert.CertificateEncodingException"},
	{"get", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, get, $Object*, $String*), "java.security.cert.CertificateParsingException"},
	{"getAuthKeyId", "()Lsun/security/x509/KeyIdentifier;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getAuthKeyId, $KeyIdentifier*)},
	{"getAuthorityInfoAccessExtension", "()Lsun/security/x509/AuthorityInfoAccessExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getAuthorityInfoAccessExtension, $AuthorityInfoAccessExtension*)},
	{"getAuthorityKeyIdentifierExtension", "()Lsun/security/x509/AuthorityKeyIdentifierExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getAuthorityKeyIdentifierExtension, $AuthorityKeyIdentifierExtension*)},
	{"getBasicConstraints", "()I", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getBasicConstraints, int32_t)},
	{"getBasicConstraintsExtension", "()Lsun/security/x509/BasicConstraintsExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getBasicConstraintsExtension, $BasicConstraintsExtension*)},
	{"getCRLDistributionPointsExtension", "()Lsun/security/x509/CRLDistributionPointsExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getCRLDistributionPointsExtension, $CRLDistributionPointsExtension*)},
	{"getCertificatePoliciesExtension", "()Lsun/security/x509/CertificatePoliciesExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getCertificatePoliciesExtension, $CertificatePoliciesExtension*)},
	{"getCriticalExtensionOIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertImpl, getCriticalExtensionOIDs, $Set*)},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertImpl, getElements, $Enumeration*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getEncoded, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getEncodedInternal", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getEncodedInternal, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getEncodedInternal", "(Ljava/security/cert/Certificate;)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getEncodedInternal, $bytes*, $Certificate*), "java.security.cert.CertificateEncodingException"},
	{"getExtendedKeyUsage", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CertImpl, getExtendedKeyUsage, $List*), "java.security.cert.CertificateParsingException"},
	{"getExtendedKeyUsage", "(Ljava/security/cert/X509Certificate;)Ljava/util/List;", "(Ljava/security/cert/X509Certificate;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getExtendedKeyUsage, $List*, $X509Certificate*), "java.security.cert.CertificateParsingException"},
	{"getExtendedKeyUsageExtension", "()Lsun/security/x509/ExtendedKeyUsageExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getExtendedKeyUsageExtension, $ExtendedKeyUsageExtension*)},
	{"getExtension", "(Lsun/security/util/ObjectIdentifier;)Lsun/security/x509/Extension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getExtension, $Extension*, $ObjectIdentifier*)},
	{"getExtensionValue", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getExtensionValue, $bytes*, $String*)},
	{"getFingerprint", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getFingerprint, $String*, $String*)},
	{"getFingerprint", "(Ljava/lang/String;Ljava/security/cert/X509Certificate;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getFingerprint, $String*, $String*, $X509Certificate*)},
	{"getIssuerAlternativeNameExtension", "()Lsun/security/x509/IssuerAlternativeNameExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getIssuerAlternativeNameExtension, $IssuerAlternativeNameExtension*)},
	{"getIssuerAlternativeNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CertImpl, getIssuerAlternativeNames, $Collection*), "java.security.cert.CertificateParsingException"},
	{"getIssuerAlternativeNames", "(Ljava/security/cert/X509Certificate;)Ljava/util/Collection;", "(Ljava/security/cert/X509Certificate;)Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getIssuerAlternativeNames, $Collection*, $X509Certificate*), "java.security.cert.CertificateParsingException"},
	{"getIssuerDN", "()Ljava/security/Principal;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getIssuerDN, $Principal*)},
	{"getIssuerUniqueID", "()[Z", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getIssuerUniqueID, $booleans*)},
	{"getIssuerX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getIssuerX500Principal, $X500Principal*)},
	{"getIssuerX500Principal", "(Ljava/security/cert/X509Certificate;)Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getIssuerX500Principal, $X500Principal*, $X509Certificate*)},
	{"getKeyUsage", "()[Z", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getKeyUsage, $booleans*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getName, $String*)},
	{"getNameConstraintsExtension", "()Lsun/security/x509/NameConstraintsExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getNameConstraintsExtension, $NameConstraintsExtension*)},
	{"getNonCriticalExtensionOIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertImpl, getNonCriticalExtensionOIDs, $Set*)},
	{"getNotAfter", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getNotAfter, $Date*)},
	{"getNotBefore", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getNotBefore, $Date*)},
	{"getPolicyConstraintsExtension", "()Lsun/security/x509/PolicyConstraintsExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getPolicyConstraintsExtension, $PolicyConstraintsExtension*)},
	{"getPolicyMappingsExtension", "()Lsun/security/x509/PolicyMappingsExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getPolicyMappingsExtension, $PolicyMappingsExtension*)},
	{"getPrivateKeyUsageExtension", "()Lsun/security/x509/PrivateKeyUsageExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getPrivateKeyUsageExtension, $PrivateKeyUsageExtension*)},
	{"getPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getPublicKey, $PublicKey*)},
	{"getSerialNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSerialNumber, $BigInteger*)},
	{"getSerialNumberObject", "()Lsun/security/x509/SerialNumber;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSerialNumberObject, $SerialNumber*)},
	{"getSigAlgName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSigAlgName, $String*)},
	{"getSigAlgOID", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSigAlgOID, $String*)},
	{"getSigAlgParams", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSigAlgParams, $bytes*)},
	{"getSignature", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSignature, $bytes*)},
	{"getSubjectAlternativeNameExtension", "()Lsun/security/x509/SubjectAlternativeNameExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSubjectAlternativeNameExtension, $SubjectAlternativeNameExtension*)},
	{"getSubjectAlternativeNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CertImpl, getSubjectAlternativeNames, $Collection*), "java.security.cert.CertificateParsingException"},
	{"getSubjectAlternativeNames", "(Ljava/security/cert/X509Certificate;)Ljava/util/Collection;", "(Ljava/security/cert/X509Certificate;)Ljava/util/Collection<Ljava/util/List<*>;>;", $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getSubjectAlternativeNames, $Collection*, $X509Certificate*), "java.security.cert.CertificateParsingException"},
	{"getSubjectDN", "()Ljava/security/Principal;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSubjectDN, $Principal*)},
	{"getSubjectKeyId", "()Lsun/security/x509/KeyIdentifier;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSubjectKeyId, $KeyIdentifier*)},
	{"getSubjectKeyIdentifierExtension", "()Lsun/security/x509/SubjectKeyIdentifierExtension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSubjectKeyIdentifierExtension, $SubjectKeyIdentifierExtension*)},
	{"getSubjectUniqueID", "()[Z", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSubjectUniqueID, $booleans*)},
	{"getSubjectX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getSubjectX500Principal, $X500Principal*)},
	{"getSubjectX500Principal", "(Ljava/security/cert/X509Certificate;)Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, getSubjectX500Principal, $X500Principal*, $X509Certificate*)},
	{"getTBSCertificate", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getTBSCertificate, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getUnparseableExtension", "(Lsun/security/util/ObjectIdentifier;)Lsun/security/x509/Extension;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getUnparseableExtension, $Extension*, $ObjectIdentifier*)},
	{"getVersion", "()I", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, getVersion, int32_t)},
	{"getX500Principal", "(Ljava/security/cert/X509Certificate;Z)Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $STATIC, $staticMethod(X509CertImpl, getX500Principal, $X500Principal*, $X509Certificate*, bool), "java.lang.Exception"},
	{"hasUnsupportedCriticalExtension", "()Z", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, hasUnsupportedCriticalExtension, bool)},
	{"isSelfIssued", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, isSelfIssued, bool, $X509Certificate*)},
	{"isSelfSigned", "(Ljava/security/cert/X509Certificate;Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, isSelfSigned, bool, $X509Certificate*, $String*)},
	{"lambda$getFingerprint$0", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(X509CertImpl, lambda$getFingerprint$0, $String*, $String*)},
	{"makeAltNames", "(Lsun/security/x509/GeneralNames;)Ljava/util/Collection;", "(Lsun/security/x509/GeneralNames;)Ljava/util/Collection<Ljava/util/List<*>;>;", $PRIVATE | $STATIC, $staticMethod(X509CertImpl, makeAltNames, $Collection*, $GeneralNames*)},
	{"parse", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(X509CertImpl, parse, void, $DerValue*), "java.security.cert.CertificateException,java.io.IOException"},
	{"readRFC1421Cert", "(Ljava/io/InputStream;)Lsun/security/util/DerValue;", nullptr, $PRIVATE, $method(X509CertImpl, readRFC1421Cert, $DerValue*, $InputStream*), "java.io.IOException"},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, set, void, $String*, Object$*), "java.security.cert.CertificateException,java.io.IOException"},
	{"sign", "(Ljava/security/PrivateKey;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, sign, void, $PrivateKey*, $String*), "java.security.cert.CertificateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"sign", "(Ljava/security/PrivateKey;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, sign, void, $PrivateKey*, $String*, $String*), "java.security.cert.CertificateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"toImpl", "(Ljava/security/cert/X509Certificate;)Lsun/security/x509/X509CertImpl;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CertImpl, toImpl, X509CertImpl*, $X509Certificate*), "java.security.cert.CertificateException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, toString, $String*)},
	{"verify", "(Ljava/security/PublicKey;)V", nullptr, $PUBLIC, $virtualMethod(X509CertImpl, verify, void, $PublicKey*), "java.security.cert.CertificateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"verify", "(Ljava/security/PublicKey;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CertImpl, verify, void, $PublicKey*, $String*), "java.security.cert.CertificateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"verify", "(Ljava/security/PublicKey;Ljava/security/Provider;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CertImpl, verify, void, $PublicKey*, $Provider*), "java.security.cert.CertificateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.SignatureException"},
	{}
};

$ClassInfo _X509CertImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.X509CertImpl",
	"java.security.cert.X509Certificate",
	"sun.security.util.DerEncoder",
	_X509CertImpl_FieldInfo_,
	_X509CertImpl_MethodInfo_
};

$Object* allocate$X509CertImpl($Class* clazz) {
	return $of($alloc(X509CertImpl));
}

bool X509CertImpl::equals(Object$* other) {
	 return this->$X509Certificate::equals(other);
}

int32_t X509CertImpl::hashCode() {
	 return this->$X509Certificate::hashCode();
}

$Object* X509CertImpl::clone() {
	 return this->$X509Certificate::clone();
}

void X509CertImpl::finalize() {
	this->$X509Certificate::finalize();
}

$String* X509CertImpl::NAME = nullptr;
$String* X509CertImpl::INFO = nullptr;
$String* X509CertImpl::ALG_ID = nullptr;
$String* X509CertImpl::SIGNATURE = nullptr;
$String* X509CertImpl::SIGNED_CERT = nullptr;
$String* X509CertImpl::SUBJECT_DN = nullptr;
$String* X509CertImpl::ISSUER_DN = nullptr;
$String* X509CertImpl::SERIAL_ID = nullptr;
$String* X509CertImpl::PUBLIC_KEY = nullptr;
$String* X509CertImpl::VERSION = nullptr;
$String* X509CertImpl::SIG_ALG = nullptr;
$String* X509CertImpl::SIG = nullptr;

void X509CertImpl::init$() {
	$X509Certificate::init$();
	this->readOnly = false;
	$set(this, signedCert, nullptr);
	$set(this, info, nullptr);
	$set(this, algId, nullptr);
	$set(this, signature, nullptr);
	$set(this, fingerprints, $new($ConcurrentHashMap, 2));
}

void X509CertImpl::init$($bytes* certData) {
	$useLocalCurrentObjectStackCache();
	$X509Certificate::init$();
	this->readOnly = false;
	$set(this, signedCert, nullptr);
	$set(this, info, nullptr);
	$set(this, algId, nullptr);
	$set(this, signature, nullptr);
	$set(this, fingerprints, $new($ConcurrentHashMap, 2));
	try {
		parse($$new($DerValue, certData));
	} catch ($IOException& e) {
		$set(this, signedCert, nullptr);
		$throwNew($CertificateException, $$str({"Unable to initialize, "_s, e}), e);
	}
}

void X509CertImpl::init$($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$X509Certificate::init$();
	this->readOnly = false;
	$set(this, signedCert, nullptr);
	$set(this, info, nullptr);
	$set(this, algId, nullptr);
	$set(this, signature, nullptr);
	$set(this, fingerprints, $new($ConcurrentHashMap, 2));
	$var($DerValue, der, nullptr);
	$var($BufferedInputStream, inBuffered, $new($BufferedInputStream, in));
	try {
		inBuffered->mark($Integer::MAX_VALUE);
		$assign(der, readRFC1421Cert(inBuffered));
	} catch ($IOException& ioe) {
		try {
			inBuffered->reset();
			$assign(der, $new($DerValue, static_cast<$InputStream*>(inBuffered)));
		} catch ($IOException& ioe1) {
			$throwNew($CertificateException, $$str({"Input stream must be either DER-encoded bytes or RFC1421 hex-encoded DER-encoded bytes: "_s, $(ioe1->getMessage())}), ioe1);
		}
	}
	try {
		parse(der);
	} catch ($IOException& ioe) {
		$set(this, signedCert, nullptr);
		$throwNew($CertificateException, $$str({"Unable to parse DER value of certificate, "_s, ioe}), ioe);
	}
}

$DerValue* X509CertImpl::readRFC1421Cert($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($DerValue, der, nullptr);
	$var($String, line, nullptr);
	$init($StandardCharsets);
	$var($BufferedReader, certBufferedReader, $new($BufferedReader, $$new($InputStreamReader, in, $StandardCharsets::US_ASCII)));
	try {
		$assign(line, certBufferedReader->readLine());
	} catch ($IOException& ioe1) {
		$throwNew($IOException, $$str({"Unable to read InputStream: "_s, $(ioe1->getMessage())}));
	}
	$init($X509Factory);
	if ($nc(line)->equals($X509Factory::BEGIN_CERT)) {
		$var($ByteArrayOutputStream, decstream, $new($ByteArrayOutputStream));
		try {
			while (($assign(line, certBufferedReader->readLine())) != nullptr) {
				if ($nc(line)->equals($X509Factory::END_CERT)) {
					$assign(der, $new($DerValue, $(decstream->toByteArray())));
					break;
				} else {
					decstream->write($($Pem::decode(line)));
				}
			}
		} catch ($IOException& ioe2) {
			$throwNew($IOException, $$str({"Unable to read InputStream: "_s, $(ioe2->getMessage())}));
		}
	} else {
		$throwNew($IOException, "InputStream is not RFC1421 hex-encoded DER bytes"_s);
	}
	return der;
}

void X509CertImpl::init$($X509CertInfo* certInfo) {
	$X509Certificate::init$();
	this->readOnly = false;
	$set(this, signedCert, nullptr);
	$set(this, info, nullptr);
	$set(this, algId, nullptr);
	$set(this, signature, nullptr);
	$set(this, fingerprints, $new($ConcurrentHashMap, 2));
	$set(this, info, certInfo);
}

void X509CertImpl::init$($DerValue* derVal) {
	$X509Certificate::init$();
	this->readOnly = false;
	$set(this, signedCert, nullptr);
	$set(this, info, nullptr);
	$set(this, algId, nullptr);
	$set(this, signature, nullptr);
	$set(this, fingerprints, $new($ConcurrentHashMap, 2));
	try {
		parse(derVal);
	} catch ($IOException& e) {
		$set(this, signedCert, nullptr);
		$throwNew($CertificateException, $$str({"Unable to initialize, "_s, e}), e);
	}
}

void X509CertImpl::encode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	if (this->signedCert == nullptr) {
		$throwNew($CertificateEncodingException, "Null certificate to encode"_s);
	}
	try {
		$nc(out)->write($cast($bytes, $($nc(this->signedCert)->clone())));
	} catch ($IOException& e) {
		$throwNew($CertificateEncodingException, $(e->toString()));
	}
}

void X509CertImpl::derEncode($OutputStream* out) {
	if (this->signedCert == nullptr) {
		$throwNew($IOException, "Null certificate to encode"_s);
	}
	$nc(out)->write($cast($bytes, $($nc(this->signedCert)->clone())));
}

$bytes* X509CertImpl::getEncoded() {
	return $cast($bytes, $nc($(getEncodedInternal()))->clone());
}

$bytes* X509CertImpl::getEncodedInternal() {
	if (this->signedCert == nullptr) {
		$throwNew($CertificateEncodingException, "Null certificate to encode"_s);
	}
	return this->signedCert;
}

void X509CertImpl::verify($PublicKey* key) {
	verify(key, ""_s);
}

void X509CertImpl::verify($PublicKey* key, $String* sigProvider$renamed) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($String, sigProvider, sigProvider$renamed);
		if (sigProvider == nullptr) {
			$assign(sigProvider, ""_s);
		}
		if ((this->verifiedPublicKey != nullptr) && $nc($of(this->verifiedPublicKey))->equals(key)) {
			if ($nc(sigProvider)->equals(this->verifiedProvider)) {
				if (this->verificationResult) {
					return;
				} else {
					$throwNew($SignatureException, "Signature does not match."_s);
				}
			}
		}
		if (this->signedCert == nullptr) {
			$throwNew($CertificateEncodingException, "Uninitialized certificate"_s);
		}
		$var($Signature, sigVerf, nullptr);
		$var($String, sigName, $nc(this->algId)->getName());
		if ($nc(sigProvider)->isEmpty()) {
			$assign(sigVerf, $Signature::getInstance(sigName));
		} else {
			$assign(sigVerf, $Signature::getInstance(sigName, sigProvider));
		}
		try {
			$SignatureUtil::initVerifyWithParam(sigVerf, key, $($SignatureUtil::getParamSpec(sigName, $(getSigAlgParams()))));
		} catch ($ProviderException& e) {
			$var($String, var$0, e->getMessage());
			$throwNew($CertificateException, var$0, $(e->getCause()));
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($CertificateException, static_cast<$Throwable*>(e));
		}
		$var($bytes, rawCert, $nc(this->info)->getEncodedInfo());
		$nc(sigVerf)->update(rawCert, 0, $nc(rawCert)->length);
		this->verificationResult = sigVerf->verify(this->signature);
		$set(this, verifiedPublicKey, key);
		$set(this, verifiedProvider, sigProvider);
		if (this->verificationResult == false) {
			$throwNew($SignatureException, "Signature does not match."_s);
		}
	}
}

void X509CertImpl::verify($PublicKey* key, $Provider* sigProvider) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->signedCert == nullptr) {
			$throwNew($CertificateEncodingException, "Uninitialized certificate"_s);
		}
		$var($Signature, sigVerf, nullptr);
		$var($String, sigName, $nc(this->algId)->getName());
		if (sigProvider == nullptr) {
			$assign(sigVerf, $Signature::getInstance(sigName));
		} else {
			$assign(sigVerf, $Signature::getInstance(sigName, sigProvider));
		}
		try {
			$SignatureUtil::initVerifyWithParam(sigVerf, key, $($SignatureUtil::getParamSpec(sigName, $(getSigAlgParams()))));
		} catch ($ProviderException& e) {
			$var($String, var$0, e->getMessage());
			$throwNew($CertificateException, var$0, $(e->getCause()));
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($CertificateException, static_cast<$Throwable*>(e));
		}
		$var($bytes, rawCert, $nc(this->info)->getEncodedInfo());
		$nc(sigVerf)->update(rawCert, 0, $nc(rawCert)->length);
		this->verificationResult = sigVerf->verify(this->signature);
		$set(this, verifiedPublicKey, key);
		if (this->verificationResult == false) {
			$throwNew($SignatureException, "Signature does not match."_s);
		}
	}
}

void X509CertImpl::sign($PrivateKey* key, $String* algorithm) {
	sign(key, algorithm, nullptr);
}

void X509CertImpl::sign($PrivateKey* key, $String* algorithm, $String* provider) {
	$useLocalCurrentObjectStackCache();
	try {
		if (this->readOnly) {
			$throwNew($CertificateEncodingException, "cannot over-write existing certificate"_s);
		}
		$var($Signature, sigEngine, $SignatureUtil::fromKey(algorithm, static_cast<$Key*>(key), provider));
		$set(this, algId, $SignatureUtil::fromSignature(sigEngine, key));
		$var($DerOutputStream, out, $new($DerOutputStream));
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		$init($X509CertInfo);
		$nc(this->info)->set($X509CertInfo::ALGORITHM_ID, $$new($CertificateAlgorithmId, this->algId));
		$nc(this->info)->encode(tmp);
		$var($bytes, rawCert, tmp->toByteArray());
		$nc(this->algId)->encode(tmp);
		$nc(sigEngine)->update(rawCert, 0, $nc(rawCert)->length);
		$set(this, signature, sigEngine->sign());
		tmp->putBitString(this->signature);
		out->write($DerValue::tag_Sequence, tmp);
		$set(this, signedCert, out->toByteArray());
		this->readOnly = true;
	} catch ($IOException& e) {
		$throwNew($CertificateEncodingException, $(e->toString()));
	}
}

void X509CertImpl::checkValidity() {
	$var($Date, date, $new($Date));
	checkValidity(date);
}

void X509CertImpl::checkValidity($Date* date) {
	$var($CertificateValidity, interval, nullptr);
	try {
		$init($CertificateValidity);
		$assign(interval, $cast($CertificateValidity, $nc(this->info)->get($CertificateValidity::NAME)));
	} catch ($Exception& e) {
		$throwNew($CertificateNotYetValidException, "Incorrect validity period"_s);
	}
	if (interval == nullptr) {
		$throwNew($CertificateNotYetValidException, "Null validity period"_s);
	}
	$nc(interval)->valid(date);
}

$Object* X509CertImpl::get($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($X509AttributeName, attr, $new($X509AttributeName, name));
	$var($String, id, attr->getPrefix());
	if (!($nc(id)->equalsIgnoreCase(X509CertImpl::NAME))) {
		$throwNew($CertificateParsingException, $$str({"Invalid root of attribute name, expected ["_s, X509CertImpl::NAME, "], received ["_s, id, "]"_s}));
	}
	$assign(attr, $new($X509AttributeName, $(attr->getSuffix())));
	$assign(id, attr->getPrefix());
	if ($nc(id)->equalsIgnoreCase(X509CertImpl::INFO)) {
		if (this->info == nullptr) {
			return $of(nullptr);
		}
		if (attr->getSuffix() != nullptr) {
			try {
				return $of($nc(this->info)->get($(attr->getSuffix())));
			} catch ($IOException& e) {
				$throwNew($CertificateParsingException, $(e->toString()));
			} catch ($CertificateException& e) {
				$throwNew($CertificateParsingException, $(e->toString()));
			}
		} else {
			return $of(this->info);
		}
	} else if (id->equalsIgnoreCase(X509CertImpl::ALG_ID)) {
		return $of((this->algId));
	} else if (id->equalsIgnoreCase(X509CertImpl::SIGNATURE)) {
		if (this->signature != nullptr) {
			return $of($nc(this->signature)->clone());
		} else {
			return $of(nullptr);
		}
	} else if (id->equalsIgnoreCase(X509CertImpl::SIGNED_CERT)) {
		if (this->signedCert != nullptr) {
			return $of($nc(this->signedCert)->clone());
		} else {
			return $of(nullptr);
		}
	} else {
		$throwNew($CertificateParsingException, $$str({"Attribute name not recognized or get() not allowed for the same: "_s, id}));
	}
}

void X509CertImpl::set($String* name, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (this->readOnly) {
		$throwNew($CertificateException, "cannot over-write existing certificate"_s);
	}
	$var($X509AttributeName, attr, $new($X509AttributeName, name));
	$var($String, id, attr->getPrefix());
	if (!($nc(id)->equalsIgnoreCase(X509CertImpl::NAME))) {
		$throwNew($CertificateException, $$str({"Invalid root of attribute name, expected ["_s, X509CertImpl::NAME, "], received "_s, id}));
	}
	$assign(attr, $new($X509AttributeName, $(attr->getSuffix())));
	$assign(id, attr->getPrefix());
	if ($nc(id)->equalsIgnoreCase(X509CertImpl::INFO)) {
		if (attr->getSuffix() == nullptr) {
			if (!($instanceOf($X509CertInfo, obj))) {
				$throwNew($CertificateException, "Attribute value should be of type X509CertInfo."_s);
			}
			$set(this, info, $cast($X509CertInfo, obj));
			$set(this, signedCert, nullptr);
		} else {
			$nc(this->info)->set($(attr->getSuffix()), obj);
			$set(this, signedCert, nullptr);
		}
	} else {
		$throwNew($CertificateException, $$str({"Attribute name not recognized or set() not allowed for the same: "_s, id}));
	}
}

void X509CertImpl::delete$($String* name) {
	$useLocalCurrentObjectStackCache();
	if (this->readOnly) {
		$throwNew($CertificateException, "cannot over-write existing certificate"_s);
	}
	$var($X509AttributeName, attr, $new($X509AttributeName, name));
	$var($String, id, attr->getPrefix());
	if (!($nc(id)->equalsIgnoreCase(X509CertImpl::NAME))) {
		$throwNew($CertificateException, $$str({"Invalid root of attribute name, expected ["_s, X509CertImpl::NAME, "], received "_s, id}));
	}
	$assign(attr, $new($X509AttributeName, $(attr->getSuffix())));
	$assign(id, attr->getPrefix());
	if ($nc(id)->equalsIgnoreCase(X509CertImpl::INFO)) {
		if (attr->getSuffix() != nullptr) {
			$set(this, info, nullptr);
		} else {
			$nc(this->info)->delete$($(attr->getSuffix()));
		}
	} else if (id->equalsIgnoreCase(X509CertImpl::ALG_ID)) {
		$set(this, algId, nullptr);
	} else if (id->equalsIgnoreCase(X509CertImpl::SIGNATURE)) {
		$set(this, signature, nullptr);
	} else if (id->equalsIgnoreCase(X509CertImpl::SIGNED_CERT)) {
		$set(this, signedCert, nullptr);
	} else {
		$throwNew($CertificateException, $$str({"Attribute name not recognized or delete() not allowed for the same: "_s, id}));
	}
}

$Enumeration* X509CertImpl::getElements() {
	$useLocalCurrentObjectStackCache();
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement($$str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::INFO}));
	elements->addElement($$str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::ALG_ID}));
	elements->addElement($$str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::SIGNATURE}));
	elements->addElement($$str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::SIGNED_CERT}));
	return elements->elements();
}

$String* X509CertImpl::getName() {
	return (X509CertImpl::NAME);
}

$String* X509CertImpl::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr || this->algId == nullptr || this->signature == nullptr) {
		return ""_s;
	}
	$var($HexDumpEncoder, encoder, $new($HexDumpEncoder));
	$var($String, var$1, $$str({"[\n"_s, this->info, $$str(u'\n'), "  Algorithm: ["_s, this->algId, "]\n  Signature:\n"_s}));
	$var($String, var$0, $$concat(var$1, $(encoder->encodeBuffer(this->signature))));
	return $concat(var$0, "\n]"_s);
}

$PublicKey* X509CertImpl::getPublicKey() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($CertificateX509Key);
		$var($PublicKey, key, $cast($PublicKey, $nc(this->info)->get($$str({$CertificateX509Key::NAME, $$str(X509CertImpl::DOT), $CertificateX509Key::KEY}))));
		return key;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

int32_t X509CertImpl::getVersion() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return -1;
	}
	try {
		$init($CertificateVersion);
		int32_t vers = $nc(($cast($Integer, $($nc(this->info)->get($$str({$CertificateVersion::NAME, $$str(X509CertImpl::DOT), $CertificateVersion::VERSION}))))))->intValue();
		return vers + 1;
	} catch ($Exception& e) {
		return -1;
	}
	$shouldNotReachHere();
}

$BigInteger* X509CertImpl::getSerialNumber() {
	$var($SerialNumber, ser, getSerialNumberObject());
	return ser != nullptr ? $nc(ser)->getNumber() : ($BigInteger*)nullptr;
}

$SerialNumber* X509CertImpl::getSerialNumberObject() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($CertificateSerialNumber);
		$var($SerialNumber, ser, $cast($SerialNumber, $nc(this->info)->get($$str({$CertificateSerialNumber::NAME, $$str(X509CertImpl::DOT), $CertificateSerialNumber::NUMBER}))));
		return ser;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Principal* X509CertImpl::getSubjectDN() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($X509CertInfo);
		$var($Principal, subject, $cast($Principal, $nc(this->info)->get($$str({$X509CertInfo::SUBJECT, $$str(X509CertImpl::DOT), $X509CertInfo::DN_NAME}))));
		return subject;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$X500Principal* X509CertImpl::getSubjectX500Principal() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($X509CertInfo);
		$var($X500Principal, subject, $cast($X500Principal, $nc(this->info)->get($$str({$X509CertInfo::SUBJECT, $$str(X509CertImpl::DOT), "x500principal"_s}))));
		return subject;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Principal* X509CertImpl::getIssuerDN() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($X509CertInfo);
		$var($Principal, issuer, $cast($Principal, $nc(this->info)->get($$str({$X509CertInfo::ISSUER, $$str(X509CertImpl::DOT), $X509CertInfo::DN_NAME}))));
		return issuer;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$X500Principal* X509CertImpl::getIssuerX500Principal() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($X509CertInfo);
		$var($X500Principal, issuer, $cast($X500Principal, $nc(this->info)->get($$str({$X509CertInfo::ISSUER, $$str(X509CertImpl::DOT), "x500principal"_s}))));
		return issuer;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Date* X509CertImpl::getNotBefore() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($CertificateValidity);
		$var($Date, d, $cast($Date, $nc(this->info)->get($$str({$CertificateValidity::NAME, $$str(X509CertImpl::DOT), $CertificateValidity::NOT_BEFORE}))));
		return d;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Date* X509CertImpl::getNotAfter() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($CertificateValidity);
		$var($Date, d, $cast($Date, $nc(this->info)->get($$str({$CertificateValidity::NAME, $$str(X509CertImpl::DOT), $CertificateValidity::NOT_AFTER}))));
		return d;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$bytes* X509CertImpl::getTBSCertificate() {
	if (this->info != nullptr) {
		return $nc(this->info)->getEncodedInfo();
	} else {
		$throwNew($CertificateEncodingException, "Uninitialized certificate"_s);
	}
}

$bytes* X509CertImpl::getSignature() {
	if (this->signature == nullptr) {
		return nullptr;
	}
	return $cast($bytes, $nc(this->signature)->clone());
}

$String* X509CertImpl::getSigAlgName() {
	if (this->algId == nullptr) {
		return nullptr;
	}
	return ($nc(this->algId)->getName());
}

$String* X509CertImpl::getSigAlgOID() {
	if (this->algId == nullptr) {
		return nullptr;
	}
	$var($ObjectIdentifier, oid, $nc(this->algId)->getOID());
	return ($nc(oid)->toString());
}

$bytes* X509CertImpl::getSigAlgParams() {
	if (this->algId == nullptr) {
		return nullptr;
	}
	try {
		return $nc(this->algId)->getEncodedParams();
	} catch ($IOException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$booleans* X509CertImpl::getIssuerUniqueID() {
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($X509CertInfo);
		$var($UniqueIdentity, id, $cast($UniqueIdentity, $nc(this->info)->get($X509CertInfo::ISSUER_ID)));
		if (id == nullptr) {
			return nullptr;
		} else {
			return ($nc(id)->getId());
		}
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$booleans* X509CertImpl::getSubjectUniqueID() {
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($X509CertInfo);
		$var($UniqueIdentity, id, $cast($UniqueIdentity, $nc(this->info)->get($X509CertInfo::SUBJECT_ID)));
		if (id == nullptr) {
			return nullptr;
		} else {
			return ($nc(id)->getId());
		}
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$KeyIdentifier* X509CertImpl::getAuthKeyId() {
	$var($AuthorityKeyIdentifierExtension, aki, getAuthorityKeyIdentifierExtension());
	if (aki != nullptr) {
		try {
			$init($AuthorityKeyIdentifierExtension);
			return $cast($KeyIdentifier, aki->get($AuthorityKeyIdentifierExtension::KEY_ID));
		} catch ($IOException& ioe) {
		}
	}
	return nullptr;
}

$KeyIdentifier* X509CertImpl::getSubjectKeyId() {
	$var($SubjectKeyIdentifierExtension, ski, getSubjectKeyIdentifierExtension());
	if (ski != nullptr) {
		try {
			$init($SubjectKeyIdentifierExtension);
			return $cast($KeyIdentifier, ski->get($SubjectKeyIdentifierExtension::KEY_ID));
		} catch ($IOException& ioe) {
		}
	}
	return nullptr;
}

$AuthorityKeyIdentifierExtension* X509CertImpl::getAuthorityKeyIdentifierExtension() {
	$init($PKIXExtensions);
	return $cast($AuthorityKeyIdentifierExtension, getExtension($PKIXExtensions::AuthorityKey_Id));
}

$BasicConstraintsExtension* X509CertImpl::getBasicConstraintsExtension() {
	$init($PKIXExtensions);
	return $cast($BasicConstraintsExtension, getExtension($PKIXExtensions::BasicConstraints_Id));
}

$CertificatePoliciesExtension* X509CertImpl::getCertificatePoliciesExtension() {
	$init($PKIXExtensions);
	return $cast($CertificatePoliciesExtension, getExtension($PKIXExtensions::CertificatePolicies_Id));
}

$ExtendedKeyUsageExtension* X509CertImpl::getExtendedKeyUsageExtension() {
	$init($PKIXExtensions);
	return $cast($ExtendedKeyUsageExtension, getExtension($PKIXExtensions::ExtendedKeyUsage_Id));
}

$IssuerAlternativeNameExtension* X509CertImpl::getIssuerAlternativeNameExtension() {
	$init($PKIXExtensions);
	return $cast($IssuerAlternativeNameExtension, getExtension($PKIXExtensions::IssuerAlternativeName_Id));
}

$NameConstraintsExtension* X509CertImpl::getNameConstraintsExtension() {
	$init($PKIXExtensions);
	return $cast($NameConstraintsExtension, getExtension($PKIXExtensions::NameConstraints_Id));
}

$PolicyConstraintsExtension* X509CertImpl::getPolicyConstraintsExtension() {
	$init($PKIXExtensions);
	return $cast($PolicyConstraintsExtension, getExtension($PKIXExtensions::PolicyConstraints_Id));
}

$PolicyMappingsExtension* X509CertImpl::getPolicyMappingsExtension() {
	$init($PKIXExtensions);
	return $cast($PolicyMappingsExtension, getExtension($PKIXExtensions::PolicyMappings_Id));
}

$PrivateKeyUsageExtension* X509CertImpl::getPrivateKeyUsageExtension() {
	$init($PKIXExtensions);
	return $cast($PrivateKeyUsageExtension, getExtension($PKIXExtensions::PrivateKeyUsage_Id));
}

$SubjectAlternativeNameExtension* X509CertImpl::getSubjectAlternativeNameExtension() {
	$init($PKIXExtensions);
	return $cast($SubjectAlternativeNameExtension, getExtension($PKIXExtensions::SubjectAlternativeName_Id));
}

$SubjectKeyIdentifierExtension* X509CertImpl::getSubjectKeyIdentifierExtension() {
	$init($PKIXExtensions);
	return $cast($SubjectKeyIdentifierExtension, getExtension($PKIXExtensions::SubjectKey_Id));
}

$CRLDistributionPointsExtension* X509CertImpl::getCRLDistributionPointsExtension() {
	$init($PKIXExtensions);
	return $cast($CRLDistributionPointsExtension, getExtension($PKIXExtensions::CRLDistributionPoints_Id));
}

bool X509CertImpl::hasUnsupportedCriticalExtension() {
	if (this->info == nullptr) {
		return false;
	}
	try {
		$init($CertificateExtensions);
		$var($CertificateExtensions, exts, $cast($CertificateExtensions, $nc(this->info)->get($CertificateExtensions::NAME)));
		if (exts == nullptr) {
			return false;
		}
		return $nc(exts)->hasUnsupportedCriticalExtension();
	} catch ($Exception& e) {
		return false;
	}
	$shouldNotReachHere();
}

$Set* X509CertImpl::getCriticalExtensionOIDs() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($CertificateExtensions);
		$var($CertificateExtensions, exts, $cast($CertificateExtensions, $nc(this->info)->get($CertificateExtensions::NAME)));
		if (exts == nullptr) {
			return nullptr;
		}
		$var($Set, extSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
		{
			$var($Iterator, i$, $nc($($nc(exts)->getAllExtensions()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Extension, ex, $cast($Extension, i$->next()));
				{
					if ($nc(ex)->isCritical()) {
						extSet->add($($nc($(ex->getExtensionId()))->toString()));
					}
				}
			}
		}
		return extSet;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Set* X509CertImpl::getNonCriticalExtensionOIDs() {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$init($CertificateExtensions);
		$var($CertificateExtensions, exts, $cast($CertificateExtensions, $nc(this->info)->get($CertificateExtensions::NAME)));
		if (exts == nullptr) {
			return nullptr;
		}
		$var($Set, extSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
		{
			$var($Iterator, i$, $nc($($nc(exts)->getAllExtensions()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Extension, ex, $cast($Extension, i$->next()));
				{
					if (!$nc(ex)->isCritical()) {
						extSet->add($($nc($(ex->getExtensionId()))->toString()));
					}
				}
			}
		}
		extSet->addAll($($nc($(exts->getUnparseableExtensions()))->keySet()));
		return extSet;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Extension* X509CertImpl::getExtension($ObjectIdentifier* oid) {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$var($CertificateExtensions, extensions, nullptr);
		try {
			$init($CertificateExtensions);
			$assign(extensions, $cast($CertificateExtensions, $nc(this->info)->get($CertificateExtensions::NAME)));
		} catch ($CertificateException& ce) {
			return nullptr;
		}
		if (extensions == nullptr) {
			return nullptr;
		} else {
			$var($Extension, ex, $nc(extensions)->getExtension($($nc(oid)->toString())));
			if (ex != nullptr) {
				return ex;
			}
			{
				$var($Iterator, i$, $nc($(extensions->getAllExtensions()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Extension, ex2, $cast($Extension, i$->next()));
					{
						if ($nc($($nc(ex2)->getExtensionId()))->equals(oid)) {
							return ex2;
						}
					}
				}
			}
			return nullptr;
		}
	} catch ($IOException& ioe) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Extension* X509CertImpl::getUnparseableExtension($ObjectIdentifier* oid) {
	$useLocalCurrentObjectStackCache();
	if (this->info == nullptr) {
		return nullptr;
	}
	try {
		$var($CertificateExtensions, extensions, nullptr);
		try {
			$init($CertificateExtensions);
			$assign(extensions, $cast($CertificateExtensions, $nc(this->info)->get($CertificateExtensions::NAME)));
		} catch ($CertificateException& ce) {
			return nullptr;
		}
		if (extensions == nullptr) {
			return nullptr;
		} else {
			return $cast($Extension, $nc($($nc(extensions)->getUnparseableExtensions()))->get($($nc(oid)->toString())));
		}
	} catch ($IOException& ioe) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$bytes* X509CertImpl::getExtensionValue($String* oid) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectIdentifier, findOID, $ObjectIdentifier::of(oid));
		$var($String, extAlias, $OIDMap::getName(findOID));
		$var($Extension, certExt, nullptr);
		$init($CertificateExtensions);
		$var($CertificateExtensions, exts, $cast($CertificateExtensions, $nc(this->info)->get($CertificateExtensions::NAME)));
		if (extAlias == nullptr) {
			if (exts == nullptr) {
				return nullptr;
			}
			{
				$var($Iterator, i$, $nc($($nc(exts)->getAllExtensions()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Extension, ex, $cast($Extension, i$->next()));
					{
						$var($ObjectIdentifier, inCertOID, $nc(ex)->getExtensionId());
						if ($nc(inCertOID)->equals(findOID)) {
							$assign(certExt, ex);
							break;
						}
					}
				}
			}
		} else {
			try {
				$assign(certExt, $cast($Extension, this->get(extAlias)));
			} catch ($CertificateException& e) {
			}
		}
		if (certExt == nullptr) {
			if (exts != nullptr) {
				$assign(certExt, $cast($Extension, $nc($(exts->getUnparseableExtensions()))->get(oid)));
			}
			if (certExt == nullptr) {
				return nullptr;
			}
		}
		$var($bytes, extData, $nc(certExt)->getExtensionValue());
		if (extData == nullptr) {
			return nullptr;
		}
		$var($DerOutputStream, out, $new($DerOutputStream));
		out->putOctetString(extData);
		return out->toByteArray();
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$booleans* X509CertImpl::getKeyUsage() {
	$useLocalCurrentObjectStackCache();
	try {
		$init($PKIXExtensions);
		$var($String, extAlias, $OIDMap::getName($PKIXExtensions::KeyUsage_Id));
		if (extAlias == nullptr) {
			return nullptr;
		}
		$var($KeyUsageExtension, certExt, $cast($KeyUsageExtension, this->get(extAlias)));
		if (certExt == nullptr) {
			return nullptr;
		}
		$var($booleans, ret, $nc(certExt)->getBits());
		if ($nc(ret)->length < X509CertImpl::NUM_STANDARD_KEY_USAGE) {
			$var($booleans, usageBits, $new($booleans, X509CertImpl::NUM_STANDARD_KEY_USAGE));
			$System::arraycopy(ret, 0, usageBits, 0, ret->length);
			$assign(ret, usageBits);
		}
		return ret;
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$List* X509CertImpl::getExtendedKeyUsage() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->readOnly && this->extKeyUsage != nullptr) {
			return this->extKeyUsage;
		} else {
			$var($ExtendedKeyUsageExtension, ext, getExtendedKeyUsageExtension());
			if (ext == nullptr) {
				return nullptr;
			}
			$set(this, extKeyUsage, $Collections::unmodifiableList($($nc(ext)->getExtendedKeyUsage())));
			return this->extKeyUsage;
		}
	}
}

$List* X509CertImpl::getExtendedKeyUsage($X509Certificate* cert) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	try {
		$init($KnownOIDs);
		$var($bytes, ext, $nc(cert)->getExtensionValue($($KnownOIDs::extendedKeyUsage->value())));
		if (ext == nullptr) {
			return nullptr;
		}
		$var($DerValue, val, $new($DerValue, ext));
		$var($bytes, data, val->getOctetString());
		$init($Boolean);
		$var($ExtendedKeyUsageExtension, ekuExt, $new($ExtendedKeyUsageExtension, $Boolean::FALSE, $of(data)));
		return $Collections::unmodifiableList($(ekuExt->getExtendedKeyUsage()));
	} catch ($IOException& ioe) {
		$throwNew($CertificateParsingException, static_cast<$Throwable*>(ioe));
	}
	$shouldNotReachHere();
}

int32_t X509CertImpl::getBasicConstraints() {
	$useLocalCurrentObjectStackCache();
	try {
		$init($PKIXExtensions);
		$var($String, extAlias, $OIDMap::getName($PKIXExtensions::BasicConstraints_Id));
		if (extAlias == nullptr) {
			return -1;
		}
		$var($BasicConstraintsExtension, certExt, $cast($BasicConstraintsExtension, this->get(extAlias)));
		if (certExt == nullptr) {
			return -1;
		}
		$init($BasicConstraintsExtension);
		if ($nc(($cast($Boolean, $($nc(certExt)->get($BasicConstraintsExtension::IS_CA)))))->booleanValue() == true) {
			return $nc(($cast($Integer, $(certExt->get($BasicConstraintsExtension::PATH_LEN)))))->intValue();
		} else {
			return -1;
		}
	} catch ($Exception& e) {
		return -1;
	}
	$shouldNotReachHere();
}

$Collection* X509CertImpl::makeAltNames($GeneralNames* names) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	if ($nc(names)->isEmpty()) {
		return $Collections::emptySet();
	}
	$var($List, newNames, $new($ArrayList));
	{
		$var($Iterator, i$, $nc($($nc(names)->names()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($GeneralName, gname, $cast($GeneralName, i$->next()));
			{
				$var($GeneralNameInterface, name, $nc(gname)->getName());
				$var($List, nameEntry, $new($ArrayList, 2));
				nameEntry->add($($Integer::valueOf($nc(name)->getType())));
				{
					$var($DerOutputStream, derOut, nullptr)
					switch ($nc(name)->getType()) {
					case $GeneralNameInterface::NAME_RFC822:
						{
							nameEntry->add($($nc(($cast($RFC822Name, name)))->getName()));
							break;
						}
					case $GeneralNameInterface::NAME_DNS:
						{
							nameEntry->add($($nc(($cast($DNSName, name)))->getName()));
							break;
						}
					case $GeneralNameInterface::NAME_DIRECTORY:
						{
							nameEntry->add($($nc(($cast($X500Name, name)))->getRFC2253Name()));
							break;
						}
					case $GeneralNameInterface::NAME_URI:
						{
							nameEntry->add($($nc(($cast($URIName, name)))->getName()));
							break;
						}
					case $GeneralNameInterface::NAME_IP:
						{
							try {
								nameEntry->add($($nc(($cast($IPAddressName, name)))->getName()));
							} catch ($IOException& ioe) {
								$throwNew($RuntimeException, "IPAddress cannot be parsed"_s, ioe);
							}
							break;
						}
					case $GeneralNameInterface::NAME_OID:
						{
							nameEntry->add($($nc($($nc(($cast($OIDName, name)))->getOID()))->toString()));
							break;
						}
					default:
						{
							$assign(derOut, $new($DerOutputStream));
							try {
								name->encode(derOut);
							} catch ($IOException& ioe) {
								$throwNew($RuntimeException, "name cannot be encoded"_s, ioe);
							}
							nameEntry->add($($nc(derOut)->toByteArray()));
							break;
						}
					}
				}
				newNames->add($($Collections::unmodifiableList(nameEntry)));
			}
		}
	}
	return $Collections::unmodifiableCollection(newNames);
}

$Collection* X509CertImpl::cloneAltNames($Collection* altNames) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	bool mustClone = false;
	{
		$var($Iterator, i$, $nc(altNames)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, nameEntry, $cast($List, i$->next()));
			{
				if ($instanceOf($bytes, $($nc(nameEntry)->get(1)))) {
					mustClone = true;
				}
			}
		}
	}
	if (mustClone) {
		$var($List, namesCopy, $new($ArrayList));
		{
			$var($Iterator, i$, altNames->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($List, nameEntry, $cast($List, i$->next()));
				{
					$var($Object, nameObject, $nc(nameEntry)->get(1));
					if ($instanceOf($bytes, nameObject)) {
						$var($List, nameEntryCopy, $new($ArrayList, static_cast<$Collection*>(nameEntry)));
						nameEntryCopy->set(1, $($nc(($cast($bytes, nameObject)))->clone()));
						namesCopy->add($($Collections::unmodifiableList(nameEntryCopy)));
					} else {
						namesCopy->add(nameEntry);
					}
				}
			}
		}
		return $Collections::unmodifiableCollection(namesCopy);
	} else {
		return altNames;
	}
}

$Collection* X509CertImpl::getSubjectAlternativeNames() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->readOnly && this->subjectAlternativeNames != nullptr) {
			return cloneAltNames(this->subjectAlternativeNames);
		}
		$var($SubjectAlternativeNameExtension, subjectAltNameExt, getSubjectAlternativeNameExtension());
		if (subjectAltNameExt == nullptr) {
			return nullptr;
		}
		$var($GeneralNames, names, nullptr);
		try {
			$init($SubjectAlternativeNameExtension);
			$assign(names, $cast($GeneralNames, $nc(subjectAltNameExt)->get($SubjectAlternativeNameExtension::SUBJECT_NAME)));
		} catch ($IOException& ioe) {
			return $Collections::emptySet();
		}
		$set(this, subjectAlternativeNames, makeAltNames(names));
		return this->subjectAlternativeNames;
	}
}

$Collection* X509CertImpl::getSubjectAlternativeNames($X509Certificate* cert) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	try {
		$init($KnownOIDs);
		$var($bytes, ext, $nc(cert)->getExtensionValue($($KnownOIDs::SubjectAlternativeName->value())));
		if (ext == nullptr) {
			return nullptr;
		}
		$var($DerValue, val, $new($DerValue, ext));
		$var($bytes, data, val->getOctetString());
		$init($Boolean);
		$var($SubjectAlternativeNameExtension, subjectAltNameExt, $new($SubjectAlternativeNameExtension, $Boolean::FALSE, $of(data)));
		$var($GeneralNames, names, nullptr);
		try {
			$init($SubjectAlternativeNameExtension);
			$assign(names, $cast($GeneralNames, subjectAltNameExt->get($SubjectAlternativeNameExtension::SUBJECT_NAME)));
		} catch ($IOException& ioe) {
			return $Collections::emptySet();
		}
		return makeAltNames(names);
	} catch ($IOException& ioe) {
		$throwNew($CertificateParsingException, static_cast<$Throwable*>(ioe));
	}
	$shouldNotReachHere();
}

$Collection* X509CertImpl::getIssuerAlternativeNames() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->readOnly && this->issuerAlternativeNames != nullptr) {
			return cloneAltNames(this->issuerAlternativeNames);
		}
		$var($IssuerAlternativeNameExtension, issuerAltNameExt, getIssuerAlternativeNameExtension());
		if (issuerAltNameExt == nullptr) {
			return nullptr;
		}
		$var($GeneralNames, names, nullptr);
		try {
			$init($IssuerAlternativeNameExtension);
			$assign(names, $cast($GeneralNames, $nc(issuerAltNameExt)->get($IssuerAlternativeNameExtension::ISSUER_NAME)));
		} catch ($IOException& ioe) {
			return $Collections::emptySet();
		}
		$set(this, issuerAlternativeNames, makeAltNames(names));
		return this->issuerAlternativeNames;
	}
}

$Collection* X509CertImpl::getIssuerAlternativeNames($X509Certificate* cert) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	try {
		$init($KnownOIDs);
		$var($bytes, ext, $nc(cert)->getExtensionValue($($KnownOIDs::IssuerAlternativeName->value())));
		if (ext == nullptr) {
			return nullptr;
		}
		$var($DerValue, val, $new($DerValue, ext));
		$var($bytes, data, val->getOctetString());
		$init($Boolean);
		$var($IssuerAlternativeNameExtension, issuerAltNameExt, $new($IssuerAlternativeNameExtension, $Boolean::FALSE, $of(data)));
		$var($GeneralNames, names, nullptr);
		try {
			$init($IssuerAlternativeNameExtension);
			$assign(names, $cast($GeneralNames, issuerAltNameExt->get($IssuerAlternativeNameExtension::ISSUER_NAME)));
		} catch ($IOException& ioe) {
			return $Collections::emptySet();
		}
		return makeAltNames(names);
	} catch ($IOException& ioe) {
		$throwNew($CertificateParsingException, static_cast<$Throwable*>(ioe));
	}
	$shouldNotReachHere();
}

$AuthorityInfoAccessExtension* X509CertImpl::getAuthorityInfoAccessExtension() {
	$init($PKIXExtensions);
	return $cast($AuthorityInfoAccessExtension, getExtension($PKIXExtensions::AuthInfoAccess_Id));
}

void X509CertImpl::parse($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	if (this->readOnly) {
		$throwNew($CertificateParsingException, "cannot over-write existing certificate"_s);
	}
	if ($nc(val)->data$ == nullptr || $nc(val)->tag != $DerValue::tag_Sequence) {
		$throwNew($CertificateParsingException, "invalid DER-encoded certificate data"_s);
	}
	$set(this, signedCert, $nc(val)->toByteArray());
	$var($DerValueArray, seq, $new($DerValueArray, 3));
	seq->set(0, $($nc(val->data$)->getDerValue()));
	seq->set(1, $($nc(val->data$)->getDerValue()));
	seq->set(2, $($nc(val->data$)->getDerValue()));
	if ($nc(val->data$)->available() != 0) {
		$throwNew($CertificateParsingException, $$str({"signed overrun, bytes = "_s, $$str($nc(val->data$)->available())}));
	}
	if ($nc(seq->get(0))->tag != $DerValue::tag_Sequence) {
		$throwNew($CertificateParsingException, "signed fields invalid"_s);
	}
	$set(this, algId, $AlgorithmId::parse(seq->get(1)));
	$set(this, signature, $nc(seq->get(2))->getBitString());
	if ($nc($nc(seq->get(1))->data$)->available() != 0) {
		$throwNew($CertificateParsingException, "algid field overrun"_s);
	}
	if ($nc($nc(seq->get(2))->data$)->available() != 0) {
		$throwNew($CertificateParsingException, "signed fields overrun"_s);
	}
	$set(this, info, $new($X509CertInfo, seq->get(0)));
	$init($CertificateAlgorithmId);
	$var($AlgorithmId, infoSigAlg, $cast($AlgorithmId, $nc(this->info)->get($$str({$CertificateAlgorithmId::NAME, $$str(X509CertImpl::DOT), $CertificateAlgorithmId::ALGORITHM}))));
	if (!$nc(this->algId)->equals(infoSigAlg)) {
		$throwNew($CertificateException, "Signature algorithm mismatch"_s);
	}
	this->readOnly = true;
}

$X500Principal* X509CertImpl::getX500Principal($X509Certificate* cert, bool getIssuer) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $nc(cert)->getEncoded());
	$var($DerInputStream, derIn, $new($DerInputStream, encoded));
	$var($DerValue, tbsCert, $nc($(derIn->getSequence(3)))->get(0));
	$var($DerInputStream, tbsIn, $nc(tbsCert)->data$);
	$var($DerValue, tmp, nullptr);
	$assign(tmp, $nc(tbsIn)->getDerValue());
	if ($nc(tmp)->isContextSpecific((int8_t)0)) {
		$assign(tmp, tbsIn->getDerValue());
	}
	$assign(tmp, tbsIn->getDerValue());
	$assign(tmp, tbsIn->getDerValue());
	if (getIssuer == false) {
		$assign(tmp, tbsIn->getDerValue());
		$assign(tmp, tbsIn->getDerValue());
	}
	$var($bytes, principalBytes, $nc(tmp)->toByteArray());
	return $new($X500Principal, principalBytes);
}

$X500Principal* X509CertImpl::getSubjectX500Principal($X509Certificate* cert) {
	$init(X509CertImpl);
	try {
		return getX500Principal(cert, false);
	} catch ($Exception& e) {
		$throwNew($RuntimeException, "Could not parse subject"_s, e);
	}
	$shouldNotReachHere();
}

$X500Principal* X509CertImpl::getIssuerX500Principal($X509Certificate* cert) {
	$init(X509CertImpl);
	try {
		return getX500Principal(cert, true);
	} catch ($Exception& e) {
		$throwNew($RuntimeException, "Could not parse issuer"_s, e);
	}
	$shouldNotReachHere();
}

$bytes* X509CertImpl::getEncodedInternal($Certificate* cert) {
	$init(X509CertImpl);
	if ($instanceOf(X509CertImpl, cert)) {
		return $nc(($cast(X509CertImpl, cert)))->getEncodedInternal();
	} else {
		return $nc(cert)->getEncoded();
	}
}

X509CertImpl* X509CertImpl::toImpl($X509Certificate* cert) {
	$init(X509CertImpl);
	if ($instanceOf(X509CertImpl, cert)) {
		return $cast(X509CertImpl, cert);
	} else {
		return $X509Factory::intern(cert);
	}
}

bool X509CertImpl::isSelfIssued($X509Certificate* cert) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	$var($X500Principal, subject, $nc(cert)->getSubjectX500Principal());
	$var($X500Principal, issuer, cert->getIssuerX500Principal());
	return $nc(subject)->equals(issuer);
}

bool X509CertImpl::isSelfSigned($X509Certificate* cert, $String* sigProvider) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	if (isSelfIssued(cert)) {
		try {
			if (sigProvider == nullptr) {
				$nc(cert)->verify($(cert->getPublicKey()));
			} else {
				$nc(cert)->verify($(cert->getPublicKey()), sigProvider);
			}
			return true;
		} catch ($Exception& e) {
		}
	}
	return false;
}

$String* X509CertImpl::getFingerprint($String* algorithm) {
	return $cast($String, $nc(this->fingerprints)->computeIfAbsent(algorithm, static_cast<$Function*>($$new(X509CertImpl$$Lambda$lambda$getFingerprint$0, this))));
}

$String* X509CertImpl::getFingerprint($String* algorithm, $X509Certificate* cert) {
	$init(X509CertImpl);
	$useLocalCurrentObjectStackCache();
	try {
		$var($bytes, encCertInfo, $nc(cert)->getEncoded());
		$var($MessageDigest, md, $MessageDigest::getInstance(algorithm));
		$var($bytes, digest, $nc(md)->digest(encCertInfo));
		return $nc($($nc($($HexFormat::of()))->withUpperCase()))->formatHex(digest);
	} catch ($NoSuchAlgorithmException& e) {
	} catch ($CertificateEncodingException& e) {
	}
	return ""_s;
}

$String* X509CertImpl::lambda$getFingerprint$0($String* x) {
	return getFingerprint(x, this);
}

X509CertImpl::X509CertImpl() {
}

void clinit$X509CertImpl($Class* class$) {
	$assignStatic(X509CertImpl::NAME, "x509"_s);
	$init($X509CertInfo);
	$assignStatic(X509CertImpl::INFO, $X509CertInfo::NAME);
	$assignStatic(X509CertImpl::ALG_ID, "algorithm"_s);
	$assignStatic(X509CertImpl::SIGNATURE, "signature"_s);
	$assignStatic(X509CertImpl::SIGNED_CERT, "signed_cert"_s);
	$assignStatic(X509CertImpl::SUBJECT_DN, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::INFO, $$str(X509CertImpl::DOT), $X509CertInfo::SUBJECT, $$str(X509CertImpl::DOT), $X509CertInfo::DN_NAME}));
	$assignStatic(X509CertImpl::ISSUER_DN, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::INFO, $$str(X509CertImpl::DOT), $X509CertInfo::ISSUER, $$str(X509CertImpl::DOT), $X509CertInfo::DN_NAME}));
	$init($CertificateSerialNumber);
	$assignStatic(X509CertImpl::SERIAL_ID, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::INFO, $$str(X509CertImpl::DOT), $X509CertInfo::SERIAL_NUMBER, $$str(X509CertImpl::DOT), $CertificateSerialNumber::NUMBER}));
	$init($CertificateX509Key);
	$assignStatic(X509CertImpl::PUBLIC_KEY, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::INFO, $$str(X509CertImpl::DOT), $X509CertInfo::KEY, $$str(X509CertImpl::DOT), $CertificateX509Key::KEY}));
	$init($CertificateVersion);
	$assignStatic(X509CertImpl::VERSION, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::INFO, $$str(X509CertImpl::DOT), $X509CertInfo::VERSION, $$str(X509CertImpl::DOT), $CertificateVersion::VERSION}));
	$assignStatic(X509CertImpl::SIG_ALG, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::ALG_ID}));
	$assignStatic(X509CertImpl::SIG, $str({X509CertImpl::NAME, $$str(X509CertImpl::DOT), X509CertImpl::SIGNATURE}));
}

$Class* X509CertImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(X509CertImpl$$Lambda$lambda$getFingerprint$0::classInfo$.name)) {
			return X509CertImpl$$Lambda$lambda$getFingerprint$0::load$(name, initialize);
		}
	}
	$loadClass(X509CertImpl, name, initialize, &_X509CertImpl_ClassInfo_, clinit$X509CertImpl, allocate$X509CertImpl);
	return class$;
}

$Class* X509CertImpl::class$ = nullptr;

		} // x509
	} // security
} // sun