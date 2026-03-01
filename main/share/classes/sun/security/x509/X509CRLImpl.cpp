#include <sun/security/x509/X509CRLImpl.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/math/BigInteger.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Key.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509CRLEntry.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/TreeSet.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/X509Factory.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <sun/security/x509/CRLExtensions.h>
#include <sun/security/x509/CRLNumberExtension.h>
#include <sun/security/x509/CertificateIssuerExtension.h>
#include <sun/security/x509/CertificateValidity.h>
#include <sun/security/x509/DeltaCRLIndicatorExtension.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/IssuerAlternativeNameExtension.h>
#include <sun/security/x509/IssuingDistributionPointExtension.h>
#include <sun/security/x509/KeyIdentifier.h>
#include <sun/security/x509/OIDMap.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CRLEntryImpl.h>
#include <sun/security/x509/X509CRLImpl$X509IssuerSerial.h>
#include <jcpp.h>

#undef ISSUER
#undef KEY_ID
#undef NUMBER

using $X509CRLEntryArray = $Array<::java::security::cert::X509CRLEntry>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Key = ::java::security::Key;
using $Principal = ::java::security::Principal;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $CRLException = ::java::security::cert::CRLException;
using $Certificate = ::java::security::cert::Certificate;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509CRLEntry = ::java::security::cert::X509CRLEntry;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $TreeSet = ::java::util::TreeSet;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $X509Factory = ::sun::security::provider::X509Factory;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $AuthorityKeyIdentifierExtension = ::sun::security::x509::AuthorityKeyIdentifierExtension;
using $CRLExtensions = ::sun::security::x509::CRLExtensions;
using $CRLNumberExtension = ::sun::security::x509::CRLNumberExtension;
using $CertificateIssuerExtension = ::sun::security::x509::CertificateIssuerExtension;
using $CertificateValidity = ::sun::security::x509::CertificateValidity;
using $DeltaCRLIndicatorExtension = ::sun::security::x509::DeltaCRLIndicatorExtension;
using $Extension = ::sun::security::x509::Extension;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $IssuerAlternativeNameExtension = ::sun::security::x509::IssuerAlternativeNameExtension;
using $IssuingDistributionPointExtension = ::sun::security::x509::IssuingDistributionPointExtension;
using $KeyIdentifier = ::sun::security::x509::KeyIdentifier;
using $OIDMap = ::sun::security::x509::OIDMap;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CRLEntryImpl = ::sun::security::x509::X509CRLEntryImpl;
using $X509CRLImpl$X509IssuerSerial = ::sun::security::x509::X509CRLImpl$X509IssuerSerial;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _X509CRLImpl_FieldInfo_[] = {
	{"signedCRL", "[B", nullptr, $PRIVATE, $field(X509CRLImpl, signedCRL)},
	{"signature", "[B", nullptr, $PRIVATE, $field(X509CRLImpl, signature)},
	{"tbsCertList", "[B", nullptr, $PRIVATE, $field(X509CRLImpl, tbsCertList)},
	{"sigAlgId", "Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE, $field(X509CRLImpl, sigAlgId)},
	{"version", "I", nullptr, $PRIVATE, $field(X509CRLImpl, version)},
	{"infoSigAlgId", "Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE, $field(X509CRLImpl, infoSigAlgId)},
	{"issuer", "Lsun/security/x509/X500Name;", nullptr, $PRIVATE, $field(X509CRLImpl, issuer)},
	{"issuerPrincipal", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $field(X509CRLImpl, issuerPrincipal)},
	{"thisUpdate", "Ljava/util/Date;", nullptr, $PRIVATE, $field(X509CRLImpl, thisUpdate)},
	{"nextUpdate", "Ljava/util/Date;", nullptr, $PRIVATE, $field(X509CRLImpl, nextUpdate)},
	{"revokedMap", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/x509/X509CRLImpl$X509IssuerSerial;Ljava/security/cert/X509CRLEntry;>;", $PRIVATE, $field(X509CRLImpl, revokedMap)},
	{"revokedList", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/X509CRLEntry;>;", $PRIVATE, $field(X509CRLImpl, revokedList)},
	{"extensions", "Lsun/security/x509/CRLExtensions;", nullptr, $PRIVATE, $field(X509CRLImpl, extensions)},
	{"isExplicit", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CRLImpl, isExplicit)},
	{"readOnly", "Z", nullptr, $PRIVATE, $field(X509CRLImpl, readOnly)},
	{"verifiedPublicKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(X509CRLImpl, verifiedPublicKey)},
	{"verifiedProvider", "Ljava/lang/String;", nullptr, $PRIVATE, $field(X509CRLImpl, verifiedProvider)},
	{}
};

$MethodInfo _X509CRLImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PRIVATE, $method(X509CRLImpl, init$, void)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(X509CRLImpl, init$, void, $bytes*), "java.security.cert.CRLException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(X509CRLImpl, init$, void, $DerValue*), "java.security.cert.CRLException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(X509CRLImpl, init$, void, $InputStream*), "java.security.cert.CRLException"},
	{"<init>", "(Lsun/security/x509/X500Name;Ljava/util/Date;Ljava/util/Date;)V", nullptr, $PUBLIC, $method(X509CRLImpl, init$, void, $X500Name*, $Date*, $Date*)},
	{"<init>", "(Lsun/security/x509/X500Name;Ljava/util/Date;Ljava/util/Date;[Ljava/security/cert/X509CRLEntry;)V", nullptr, $PUBLIC, $method(X509CRLImpl, init$, void, $X500Name*, $Date*, $Date*, $X509CRLEntryArray*), "java.security.cert.CRLException"},
	{"<init>", "(Lsun/security/x509/X500Name;Ljava/util/Date;Ljava/util/Date;[Ljava/security/cert/X509CRLEntry;Lsun/security/x509/CRLExtensions;)V", nullptr, $PUBLIC, $method(X509CRLImpl, init$, void, $X500Name*, $Date*, $Date*, $X509CRLEntryArray*, $CRLExtensions*), "java.security.cert.CRLException"},
	{"derEncode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, derEncode, void, $OutputStream*), "java.io.IOException"},
	{"encodeInfo", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, encodeInfo, void, $OutputStream*), "java.security.cert.CRLException"},
	{"getAuthKeyId", "()Lsun/security/x509/KeyIdentifier;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getAuthKeyId, $KeyIdentifier*), "java.io.IOException"},
	{"getAuthKeyIdExtension", "()Lsun/security/x509/AuthorityKeyIdentifierExtension;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getAuthKeyIdExtension, $AuthorityKeyIdentifierExtension*), "java.io.IOException"},
	{"getBaseCRLNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getBaseCRLNumber, $BigInteger*), "java.io.IOException"},
	{"getCRLNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getCRLNumber, $BigInteger*), "java.io.IOException"},
	{"getCRLNumberExtension", "()Lsun/security/x509/CRLNumberExtension;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getCRLNumberExtension, $CRLNumberExtension*), "java.io.IOException"},
	{"getCertIssuer", "(Lsun/security/x509/X509CRLEntryImpl;Ljavax/security/auth/x500/X500Principal;)Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $method(X509CRLImpl, getCertIssuer, $X500Principal*, $X509CRLEntryImpl*, $X500Principal*), "java.io.IOException"},
	{"getCriticalExtensionOIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CRLImpl, getCriticalExtensionOIDs, $Set*)},
	{"getDeltaCRLIndicatorExtension", "()Lsun/security/x509/DeltaCRLIndicatorExtension;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getDeltaCRLIndicatorExtension, $DeltaCRLIndicatorExtension*), "java.io.IOException"},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getEncoded, $bytes*), "java.security.cert.CRLException"},
	{"getEncodedInternal", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getEncodedInternal, $bytes*), "java.security.cert.CRLException"},
	{"getEncodedInternal", "(Ljava/security/cert/X509CRL;)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CRLImpl, getEncodedInternal, $bytes*, $X509CRL*), "java.security.cert.CRLException"},
	{"getExtension", "(Lsun/security/util/ObjectIdentifier;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getExtension, $Object*, $ObjectIdentifier*)},
	{"getExtensionValue", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getExtensionValue, $bytes*, $String*)},
	{"getIssuerAltNameExtension", "()Lsun/security/x509/IssuerAlternativeNameExtension;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getIssuerAltNameExtension, $IssuerAlternativeNameExtension*), "java.io.IOException"},
	{"getIssuerDN", "()Ljava/security/Principal;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getIssuerDN, $Principal*)},
	{"getIssuerX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getIssuerX500Principal, $X500Principal*)},
	{"getIssuerX500Principal", "(Ljava/security/cert/X509CRL;)Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CRLImpl, getIssuerX500Principal, $X500Principal*, $X509CRL*)},
	{"getIssuingDistributionPointExtension", "()Lsun/security/x509/IssuingDistributionPointExtension;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getIssuingDistributionPointExtension, $IssuingDistributionPointExtension*), "java.io.IOException"},
	{"getNextUpdate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getNextUpdate, $Date*)},
	{"getNonCriticalExtensionOIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CRLImpl, getNonCriticalExtensionOIDs, $Set*)},
	{"getRevokedCertificate", "(Ljava/math/BigInteger;)Ljava/security/cert/X509CRLEntry;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getRevokedCertificate, $X509CRLEntry*, $BigInteger*)},
	{"getRevokedCertificate", "(Ljava/security/cert/X509Certificate;)Ljava/security/cert/X509CRLEntry;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getRevokedCertificate, $X509CRLEntry*, $X509Certificate*)},
	{"getRevokedCertificates", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/cert/X509CRLEntry;>;", $PUBLIC, $virtualMethod(X509CRLImpl, getRevokedCertificates, $Set*)},
	{"getSigAlgId", "()Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getSigAlgId, $AlgorithmId*)},
	{"getSigAlgName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getSigAlgName, $String*)},
	{"getSigAlgOID", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getSigAlgOID, $String*)},
	{"getSigAlgParams", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getSigAlgParams, $bytes*)},
	{"getSignature", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getSignature, $bytes*)},
	{"getTBSCertList", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getTBSCertList, $bytes*), "java.security.cert.CRLException"},
	{"getThisUpdate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getThisUpdate, $Date*)},
	{"getVersion", "()I", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, getVersion, int32_t)},
	{"hasUnsupportedCriticalExtension", "()Z", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, hasUnsupportedCriticalExtension, bool)},
	{"isRevoked", "(Ljava/security/cert/Certificate;)Z", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, isRevoked, bool, $Certificate*)},
	{"parse", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(X509CRLImpl, parse, void, $DerValue*), "java.security.cert.CRLException,java.io.IOException"},
	{"sign", "(Ljava/security/PrivateKey;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, sign, void, $PrivateKey*, $String*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"sign", "(Ljava/security/PrivateKey;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, sign, void, $PrivateKey*, $String*, $String*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"toImpl", "(Ljava/security/cert/X509CRL;)Lsun/security/x509/X509CRLImpl;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CRLImpl, toImpl, X509CRLImpl*, $X509CRL*), "java.security.cert.CRLException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, toString, $String*)},
	{"toStringWithAlgName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, toStringWithAlgName, $String*, $String*)},
	{"verify", "(Ljava/security/PublicKey;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLImpl, verify, void, $PublicKey*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"verify", "(Ljava/security/PublicKey;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CRLImpl, verify, void, $PublicKey*, $String*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.NoSuchProviderException,java.security.SignatureException"},
	{"verify", "(Ljava/security/PublicKey;Ljava/security/Provider;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(X509CRLImpl, verify, void, $PublicKey*, $Provider*), "java.security.cert.CRLException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException,java.security.SignatureException"},
	{}
};

$InnerClassInfo _X509CRLImpl_InnerClassesInfo_[] = {
	{"sun.security.x509.X509CRLImpl$X509IssuerSerial", "sun.security.x509.X509CRLImpl", "X509IssuerSerial", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _X509CRLImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.X509CRLImpl",
	"java.security.cert.X509CRL",
	"sun.security.util.DerEncoder",
	_X509CRLImpl_FieldInfo_,
	_X509CRLImpl_MethodInfo_,
	nullptr,
	nullptr,
	_X509CRLImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.x509.X509CRLImpl$X509IssuerSerial"
};

$Object* allocate$X509CRLImpl($Class* clazz) {
	return $of($alloc(X509CRLImpl));
}

bool X509CRLImpl::equals(Object$* other) {
	 return this->$X509CRL::equals(other);
}

int32_t X509CRLImpl::hashCode() {
	 return this->$X509CRL::hashCode();
}

$Object* X509CRLImpl::clone() {
	 return this->$X509CRL::clone();
}

void X509CRLImpl::finalize() {
	this->$X509CRL::finalize();
}

void X509CRLImpl::init$() {
	$X509CRL::init$();
	$set(this, signedCRL, nullptr);
	$set(this, signature, nullptr);
	$set(this, tbsCertList, nullptr);
	$set(this, sigAlgId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, issuerPrincipal, nullptr);
	$set(this, thisUpdate, nullptr);
	$set(this, nextUpdate, nullptr);
	$set(this, revokedMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$set(this, revokedList, $new($LinkedList));
	$set(this, extensions, nullptr);
	this->readOnly = false;
}

void X509CRLImpl::init$($bytes* crlData) {
	$useLocalCurrentObjectStackCache();
	$X509CRL::init$();
	$set(this, signedCRL, nullptr);
	$set(this, signature, nullptr);
	$set(this, tbsCertList, nullptr);
	$set(this, sigAlgId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, issuerPrincipal, nullptr);
	$set(this, thisUpdate, nullptr);
	$set(this, nextUpdate, nullptr);
	$set(this, revokedMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$set(this, revokedList, $new($LinkedList));
	$set(this, extensions, nullptr);
	this->readOnly = false;
	try {
		parse($$new($DerValue, crlData));
	} catch ($IOException& e) {
		$set(this, signedCRL, nullptr);
		$throwNew($CRLException, $$str({"Parsing error: "_s, $(e->getMessage())}));
	}
}

void X509CRLImpl::init$($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	$X509CRL::init$();
	$set(this, signedCRL, nullptr);
	$set(this, signature, nullptr);
	$set(this, tbsCertList, nullptr);
	$set(this, sigAlgId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, issuerPrincipal, nullptr);
	$set(this, thisUpdate, nullptr);
	$set(this, nextUpdate, nullptr);
	$set(this, revokedMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$set(this, revokedList, $new($LinkedList));
	$set(this, extensions, nullptr);
	this->readOnly = false;
	try {
		parse(val);
	} catch ($IOException& e) {
		$set(this, signedCRL, nullptr);
		$throwNew($CRLException, $$str({"Parsing error: "_s, $(e->getMessage())}));
	}
}

void X509CRLImpl::init$($InputStream* inStrm) {
	$useLocalCurrentObjectStackCache();
	$X509CRL::init$();
	$set(this, signedCRL, nullptr);
	$set(this, signature, nullptr);
	$set(this, tbsCertList, nullptr);
	$set(this, sigAlgId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, issuerPrincipal, nullptr);
	$set(this, thisUpdate, nullptr);
	$set(this, nextUpdate, nullptr);
	$set(this, revokedMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$set(this, revokedList, $new($LinkedList));
	$set(this, extensions, nullptr);
	this->readOnly = false;
	try {
		parse($$new($DerValue, inStrm));
	} catch ($IOException& e) {
		$set(this, signedCRL, nullptr);
		$throwNew($CRLException, $$str({"Parsing error: "_s, $(e->getMessage())}));
	}
}

void X509CRLImpl::init$($X500Name* issuer, $Date* thisDate, $Date* nextDate) {
	$X509CRL::init$();
	$set(this, signedCRL, nullptr);
	$set(this, signature, nullptr);
	$set(this, tbsCertList, nullptr);
	$set(this, sigAlgId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, issuerPrincipal, nullptr);
	$set(this, thisUpdate, nullptr);
	$set(this, nextUpdate, nullptr);
	$set(this, revokedMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$set(this, revokedList, $new($LinkedList));
	$set(this, extensions, nullptr);
	this->readOnly = false;
	$set(this, issuer, issuer);
	$set(this, thisUpdate, thisDate);
	$set(this, nextUpdate, nextDate);
}

void X509CRLImpl::init$($X500Name* issuer, $Date* thisDate, $Date* nextDate, $X509CRLEntryArray* badCerts) {
	$useLocalCurrentObjectStackCache();
	$X509CRL::init$();
	$set(this, signedCRL, nullptr);
	$set(this, signature, nullptr);
	$set(this, tbsCertList, nullptr);
	$set(this, sigAlgId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, issuerPrincipal, nullptr);
	$set(this, thisUpdate, nullptr);
	$set(this, nextUpdate, nullptr);
	$set(this, revokedMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	$set(this, revokedList, $new($LinkedList));
	$set(this, extensions, nullptr);
	this->readOnly = false;
	$set(this, issuer, issuer);
	$set(this, thisUpdate, thisDate);
	$set(this, nextUpdate, nextDate);
	if (badCerts != nullptr) {
		$var($X500Principal, crlIssuer, getIssuerX500Principal());
		$var($X500Principal, badCertIssuer, crlIssuer);
		for (int32_t i = 0; i < badCerts->length; ++i) {
			$var($X509CRLEntryImpl, badCert, $cast($X509CRLEntryImpl, badCerts->get(i)));
			try {
				$assign(badCertIssuer, getCertIssuer(badCert, badCertIssuer));
			} catch ($IOException& ioe) {
				$throwNew($CRLException, static_cast<$Throwable*>(ioe));
			}
			$nc(badCert)->setCertificateIssuer(crlIssuer, badCertIssuer);
			$var($X509CRLImpl$X509IssuerSerial, issuerSerial, $new($X509CRLImpl$X509IssuerSerial, badCertIssuer, $(badCert->getSerialNumber())));
			$nc(this->revokedMap)->put(issuerSerial, badCert);
			$nc(this->revokedList)->add(badCert);
			if (badCert->hasExtensions()) {
				this->version = 1;
			}
		}
	}
}

void X509CRLImpl::init$($X500Name* issuer, $Date* thisDate, $Date* nextDate, $X509CRLEntryArray* badCerts, $CRLExtensions* crlExts) {
	X509CRLImpl::init$(issuer, thisDate, nextDate, badCerts);
	if (crlExts != nullptr) {
		$set(this, extensions, crlExts);
		this->version = 1;
	}
}

$bytes* X509CRLImpl::getEncodedInternal() {
	if (this->signedCRL == nullptr) {
		$throwNew($CRLException, "Null CRL to encode"_s);
	}
	return this->signedCRL;
}

$bytes* X509CRLImpl::getEncoded() {
	return $cast($bytes, $nc($(getEncodedInternal()))->clone());
}

void X509CRLImpl::encodeInfo($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		$var($DerOutputStream, rCerts, $new($DerOutputStream));
		$var($DerOutputStream, seq, $new($DerOutputStream));
		if (this->version != 0) {
			tmp->putInteger(this->version);
		}
		$nc(this->infoSigAlgId)->encode(tmp);
		if ((this->version == 0) && ($nc(this->issuer)->toString() == nullptr)) {
			$throwNew($CRLException, "Null Issuer DN not allowed in v1 CRL"_s);
		}
		$nc(this->issuer)->encode(tmp);
		if ($nc(this->thisUpdate)->getTime() < $CertificateValidity::YR_2050) {
			tmp->putUTCTime(this->thisUpdate);
		} else {
			tmp->putGeneralizedTime(this->thisUpdate);
		}
		if (this->nextUpdate != nullptr) {
			if ($nc(this->nextUpdate)->getTime() < $CertificateValidity::YR_2050) {
				tmp->putUTCTime(this->nextUpdate);
			} else {
				tmp->putGeneralizedTime(this->nextUpdate);
			}
		}
		if (!$nc(this->revokedList)->isEmpty()) {
			{
				$var($Iterator, i$, $nc(this->revokedList)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($X509CRLEntry, entry, $cast($X509CRLEntry, i$->next()));
					{
						$nc(($cast($X509CRLEntryImpl, entry)))->encode(rCerts);
					}
				}
			}
			tmp->write($DerValue::tag_Sequence, rCerts);
		}
		if (this->extensions != nullptr) {
			$nc(this->extensions)->encode(tmp, X509CRLImpl::isExplicit);
		}
		seq->write($DerValue::tag_Sequence, tmp);
		$set(this, tbsCertList, seq->toByteArray());
		$nc(out)->write(this->tbsCertList);
	} catch ($IOException& e) {
		$throwNew($CRLException, $$str({"Encoding error: "_s, $(e->getMessage())}));
	}
}

void X509CRLImpl::verify($PublicKey* key) {
	verify(key, ""_s);
}

void X509CRLImpl::verify($PublicKey* key, $String* sigProvider$renamed) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($String, sigProvider, sigProvider$renamed);
		if (sigProvider == nullptr) {
			$assign(sigProvider, ""_s);
		}
		if ((this->verifiedPublicKey != nullptr) && $nc($of(this->verifiedPublicKey))->equals(key)) {
			if ($nc(sigProvider)->equals(this->verifiedProvider)) {
				return;
			}
		}
		if (this->signedCRL == nullptr) {
			$throwNew($CRLException, "Uninitialized CRL"_s);
		}
		$var($Signature, sigVerf, nullptr);
		$var($String, sigName, $nc(this->sigAlgId)->getName());
		if ($nc(sigProvider)->isEmpty()) {
			$assign(sigVerf, $Signature::getInstance(sigName));
		} else {
			$assign(sigVerf, $Signature::getInstance(sigName, sigProvider));
		}
		try {
			$SignatureUtil::initVerifyWithParam(sigVerf, key, $($SignatureUtil::getParamSpec(sigName, $(getSigAlgParams()))));
		} catch ($ProviderException& e) {
			$var($String, var$0, e->getMessage());
			$throwNew($CRLException, var$0, $(e->getCause()));
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($CRLException, static_cast<$Throwable*>(e));
		}
		if (this->tbsCertList == nullptr) {
			$throwNew($CRLException, "Uninitialized CRL"_s);
		}
		$nc(sigVerf)->update(this->tbsCertList, 0, $nc(this->tbsCertList)->length);
		if (!sigVerf->verify(this->signature)) {
			$throwNew($SignatureException, "Signature does not match."_s);
		}
		$set(this, verifiedPublicKey, key);
		$set(this, verifiedProvider, sigProvider);
	}
}

void X509CRLImpl::verify($PublicKey* key, $Provider* sigProvider) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->signedCRL == nullptr) {
			$throwNew($CRLException, "Uninitialized CRL"_s);
		}
		$var($Signature, sigVerf, nullptr);
		$var($String, sigName, $nc(this->sigAlgId)->getName());
		if (sigProvider == nullptr) {
			$assign(sigVerf, $Signature::getInstance(sigName));
		} else {
			$assign(sigVerf, $Signature::getInstance(sigName, sigProvider));
		}
		try {
			$SignatureUtil::initVerifyWithParam(sigVerf, key, $($SignatureUtil::getParamSpec(sigName, $(getSigAlgParams()))));
		} catch ($ProviderException& e) {
			$var($String, var$0, e->getMessage());
			$throwNew($CRLException, var$0, $(e->getCause()));
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($CRLException, static_cast<$Throwable*>(e));
		}
		if (this->tbsCertList == nullptr) {
			$throwNew($CRLException, "Uninitialized CRL"_s);
		}
		$nc(sigVerf)->update(this->tbsCertList, 0, $nc(this->tbsCertList)->length);
		if (!sigVerf->verify(this->signature)) {
			$throwNew($SignatureException, "Signature does not match."_s);
		}
		$set(this, verifiedPublicKey, key);
	}
}

void X509CRLImpl::sign($PrivateKey* key, $String* algorithm) {
	sign(key, algorithm, nullptr);
}

void X509CRLImpl::sign($PrivateKey* key, $String* algorithm, $String* provider) {
	$useLocalCurrentObjectStackCache();
	try {
		if (this->readOnly) {
			$throwNew($CRLException, "cannot over-write existing CRL"_s);
		}
		$var($Signature, sigEngine, $SignatureUtil::fromKey(algorithm, static_cast<$Key*>(key), provider));
		$set(this, sigAlgId, $SignatureUtil::fromSignature(sigEngine, key));
		$set(this, infoSigAlgId, this->sigAlgId);
		$var($DerOutputStream, out, $new($DerOutputStream));
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		encodeInfo(tmp);
		$nc(this->sigAlgId)->encode(tmp);
		$nc(sigEngine)->update(this->tbsCertList, 0, $nc(this->tbsCertList)->length);
		$set(this, signature, sigEngine->sign());
		tmp->putBitString(this->signature);
		out->write($DerValue::tag_Sequence, tmp);
		$set(this, signedCRL, out->toByteArray());
		this->readOnly = true;
	} catch ($IOException& e) {
		$throwNew($CRLException, $$str({"Error while encoding data: "_s, $(e->getMessage())}));
	}
}

$String* X509CRLImpl::toString() {
	return toStringWithAlgName($$str({""_s, this->sigAlgId}));
}

$String* X509CRLImpl::toStringWithAlgName($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("X.509 CRL v"_s)->append(this->version + 1)->append(u'\n');
	if (this->sigAlgId != nullptr) {
		sb->append("Signature Algorithm: "_s)->append(name)->append(", OID="_s)->append($($of($nc(this->sigAlgId)->getOID())))->append(u'\n');
	}
	if (this->issuer != nullptr) {
		sb->append("Issuer: "_s)->append($of(this->issuer))->append(u'\n');
	}
	if (this->thisUpdate != nullptr) {
		sb->append("\nThis Update: "_s)->append($of(this->thisUpdate))->append(u'\n');
	}
	if (this->nextUpdate != nullptr) {
		sb->append("Next Update: "_s)->append($of(this->nextUpdate))->append(u'\n');
	}
	if ($nc(this->revokedList)->isEmpty()) {
		sb->append("\nNO certificates have been revoked\n"_s);
	} else {
		sb->append("\nRevoked Certificates: "_s)->append($nc(this->revokedList)->size());
		int32_t i = 1;
		{
			$var($Iterator, i$, $nc(this->revokedList)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($X509CRLEntry, entry, $cast($X509CRLEntry, i$->next()));
				{
					sb->append("\n["_s)->append(i++)->append("] "_s)->append($of(entry));
				}
			}
		}
	}
	if (this->extensions != nullptr) {
		$var($Collection, allExts, $nc(this->extensions)->getAllExtensions());
		$var($ObjectArray, objs, $nc(allExts)->toArray());
		sb->append("\nCRL Extensions: "_s)->append($nc(objs)->length);
		for (int32_t i = 0; i < $nc(objs)->length; ++i) {
			sb->append("\n["_s)->append(i + 1)->append("]: "_s);
			$var($Extension, ext, $cast($Extension, objs->get(i)));
			try {
				if ($OIDMap::getClass($($nc(ext)->getExtensionId())) == nullptr) {
					sb->append($of(ext));
					$var($bytes, extValue, $nc(ext)->getExtensionValue());
					if (extValue != nullptr) {
						$var($DerOutputStream, out, $new($DerOutputStream));
						out->putOctetString(extValue);
						$assign(extValue, out->toByteArray());
						$var($HexDumpEncoder, enc, $new($HexDumpEncoder));
						sb->append("Extension unknown: "_s)->append("DER encoded OCTET string =\n"_s)->append($(enc->encodeBuffer(extValue)))->append(u'\n');
					}
				} else {
					sb->append($of(ext));
				}
			} catch ($Exception& e) {
				sb->append(", Error parsing this extension"_s);
			}
		}
	}
	if (this->signature != nullptr) {
		$var($HexDumpEncoder, encoder, $new($HexDumpEncoder));
		sb->append("\nSignature:\n"_s)->append($(encoder->encodeBuffer(this->signature)))->append(u'\n');
	} else {
		sb->append("NOT signed yet\n"_s);
	}
	return sb->toString();
}

bool X509CRLImpl::isRevoked($Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->revokedMap)->isEmpty() || (!($instanceOf($X509Certificate, cert)))) {
		return false;
	}
	$var($X509Certificate, xcert, $cast($X509Certificate, cert));
	$var($X509CRLImpl$X509IssuerSerial, issuerSerial, $new($X509CRLImpl$X509IssuerSerial, xcert));
	return $nc(this->revokedMap)->containsKey(issuerSerial);
}

int32_t X509CRLImpl::getVersion() {
	return this->version + 1;
}

$Principal* X509CRLImpl::getIssuerDN() {
	return this->issuer;
}

$X500Principal* X509CRLImpl::getIssuerX500Principal() {
	if (this->issuerPrincipal == nullptr) {
		$set(this, issuerPrincipal, $nc(this->issuer)->asX500Principal());
	}
	return this->issuerPrincipal;
}

$Date* X509CRLImpl::getThisUpdate() {
	return ($new($Date, $nc(this->thisUpdate)->getTime()));
}

$Date* X509CRLImpl::getNextUpdate() {
	if (this->nextUpdate == nullptr) {
		return nullptr;
	}
	return ($new($Date, $nc(this->nextUpdate)->getTime()));
}

$X509CRLEntry* X509CRLImpl::getRevokedCertificate($BigInteger* serialNumber) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->revokedMap)->isEmpty()) {
		return nullptr;
	}
	$var($X509CRLImpl$X509IssuerSerial, issuerSerial, $new($X509CRLImpl$X509IssuerSerial, $(getIssuerX500Principal()), serialNumber));
	return $cast($X509CRLEntry, $nc(this->revokedMap)->get(issuerSerial));
}

$X509CRLEntry* X509CRLImpl::getRevokedCertificate($X509Certificate* cert) {
	if ($nc(this->revokedMap)->isEmpty()) {
		return nullptr;
	}
	$var($X509CRLImpl$X509IssuerSerial, issuerSerial, $new($X509CRLImpl$X509IssuerSerial, cert));
	return $cast($X509CRLEntry, $nc(this->revokedMap)->get(issuerSerial));
}

$Set* X509CRLImpl::getRevokedCertificates() {
	if ($nc(this->revokedList)->isEmpty()) {
		return nullptr;
	} else {
		return static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, static_cast<$Collection*>(this->revokedList))));
	}
}

$bytes* X509CRLImpl::getTBSCertList() {
	if (this->tbsCertList == nullptr) {
		$throwNew($CRLException, "Uninitialized CRL"_s);
	}
	return $cast($bytes, $nc(this->tbsCertList)->clone());
}

$bytes* X509CRLImpl::getSignature() {
	if (this->signature == nullptr) {
		return nullptr;
	}
	return $cast($bytes, $nc(this->signature)->clone());
}

$String* X509CRLImpl::getSigAlgName() {
	if (this->sigAlgId == nullptr) {
		return nullptr;
	}
	return $nc(this->sigAlgId)->getName();
}

$String* X509CRLImpl::getSigAlgOID() {
	if (this->sigAlgId == nullptr) {
		return nullptr;
	}
	$var($ObjectIdentifier, oid, $nc(this->sigAlgId)->getOID());
	return $nc(oid)->toString();
}

$bytes* X509CRLImpl::getSigAlgParams() {
	if (this->sigAlgId == nullptr) {
		return nullptr;
	}
	try {
		return $nc(this->sigAlgId)->getEncodedParams();
	} catch ($IOException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$AlgorithmId* X509CRLImpl::getSigAlgId() {
	return this->sigAlgId;
}

$KeyIdentifier* X509CRLImpl::getAuthKeyId() {
	$useLocalCurrentObjectStackCache();
	$var($AuthorityKeyIdentifierExtension, aki, getAuthKeyIdExtension());
	if (aki != nullptr) {
		$init($AuthorityKeyIdentifierExtension);
		$var($KeyIdentifier, keyId, $cast($KeyIdentifier, aki->get($AuthorityKeyIdentifierExtension::KEY_ID)));
		return keyId;
	} else {
		return nullptr;
	}
}

$AuthorityKeyIdentifierExtension* X509CRLImpl::getAuthKeyIdExtension() {
	$init($PKIXExtensions);
	$var($Object, obj, getExtension($PKIXExtensions::AuthorityKey_Id));
	return $cast($AuthorityKeyIdentifierExtension, obj);
}

$CRLNumberExtension* X509CRLImpl::getCRLNumberExtension() {
	$init($PKIXExtensions);
	$var($Object, obj, getExtension($PKIXExtensions::CRLNumber_Id));
	return $cast($CRLNumberExtension, obj);
}

$BigInteger* X509CRLImpl::getCRLNumber() {
	$useLocalCurrentObjectStackCache();
	$var($CRLNumberExtension, numExt, getCRLNumberExtension());
	if (numExt != nullptr) {
		$init($CRLNumberExtension);
		$var($BigInteger, num, $cast($BigInteger, numExt->get($CRLNumberExtension::NUMBER)));
		return num;
	} else {
		return nullptr;
	}
}

$DeltaCRLIndicatorExtension* X509CRLImpl::getDeltaCRLIndicatorExtension() {
	$init($PKIXExtensions);
	$var($Object, obj, getExtension($PKIXExtensions::DeltaCRLIndicator_Id));
	return $cast($DeltaCRLIndicatorExtension, obj);
}

$BigInteger* X509CRLImpl::getBaseCRLNumber() {
	$useLocalCurrentObjectStackCache();
	$var($DeltaCRLIndicatorExtension, dciExt, getDeltaCRLIndicatorExtension());
	if (dciExt != nullptr) {
		$init($DeltaCRLIndicatorExtension);
		$var($BigInteger, num, $cast($BigInteger, dciExt->get($DeltaCRLIndicatorExtension::NUMBER)));
		return num;
	} else {
		return nullptr;
	}
}

$IssuerAlternativeNameExtension* X509CRLImpl::getIssuerAltNameExtension() {
	$init($PKIXExtensions);
	$var($Object, obj, getExtension($PKIXExtensions::IssuerAlternativeName_Id));
	return $cast($IssuerAlternativeNameExtension, obj);
}

$IssuingDistributionPointExtension* X509CRLImpl::getIssuingDistributionPointExtension() {
	$init($PKIXExtensions);
	$var($Object, obj, getExtension($PKIXExtensions::IssuingDistributionPoint_Id));
	return $cast($IssuingDistributionPointExtension, obj);
}

bool X509CRLImpl::hasUnsupportedCriticalExtension() {
	if (this->extensions == nullptr) {
		return false;
	}
	return $nc(this->extensions)->hasUnsupportedCriticalExtension();
}

$Set* X509CRLImpl::getCriticalExtensionOIDs() {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return nullptr;
	}
	$var($Set, extSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
	{
		$var($Iterator, i$, $nc($($nc(this->extensions)->getAllExtensions()))->iterator());
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
}

$Set* X509CRLImpl::getNonCriticalExtensionOIDs() {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return nullptr;
	}
	$var($Set, extSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
	{
		$var($Iterator, i$, $nc($($nc(this->extensions)->getAllExtensions()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Extension, ex, $cast($Extension, i$->next()));
			{
				if (!$nc(ex)->isCritical()) {
					extSet->add($($nc($(ex->getExtensionId()))->toString()));
				}
			}
		}
	}
	return extSet;
}

$bytes* X509CRLImpl::getExtensionValue($String* oid) {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return nullptr;
	}
	try {
		$var($String, extAlias, $OIDMap::getName($($ObjectIdentifier::of(oid))));
		$var($Extension, crlExt, nullptr);
		if (extAlias == nullptr) {
			$var($ObjectIdentifier, findOID, $ObjectIdentifier::of(oid));
			$var($Extension, ex, nullptr);
			$var($ObjectIdentifier, inCertOID, nullptr);
			{
				$var($Enumeration, e, $nc(this->extensions)->getElements());
				for (; $nc(e)->hasMoreElements();) {
					$assign(ex, $cast($Extension, e->nextElement()));
					$assign(inCertOID, $nc(ex)->getExtensionId());
					if ($nc(inCertOID)->equals(findOID)) {
						$assign(crlExt, ex);
						break;
					}
				}
			}
		} else {
			$assign(crlExt, $nc(this->extensions)->get(extAlias));
		}
		if (crlExt == nullptr) {
			return nullptr;
		}
		$var($bytes, extData, $nc(crlExt)->getExtensionValue());
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

$Object* X509CRLImpl::getExtension($ObjectIdentifier* oid) {
	if (this->extensions == nullptr) {
		return $of(nullptr);
	}
	return $of($nc(this->extensions)->get($($OIDMap::getName(oid))));
}

void X509CRLImpl::parse($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	if (this->readOnly) {
		$throwNew($CRLException, "cannot over-write existing CRL"_s);
	}
	if ($nc(val)->getData() == nullptr || $nc(val)->tag != $DerValue::tag_Sequence) {
		$throwNew($CRLException, "Invalid DER-encoded CRL data"_s);
	}
	$set(this, signedCRL, $nc(val)->toByteArray());
	$var($DerValueArray, seq, $new($DerValueArray, 3));
	seq->set(0, $($nc(val->data$)->getDerValue()));
	seq->set(1, $($nc(val->data$)->getDerValue()));
	seq->set(2, $($nc(val->data$)->getDerValue()));
	if ($nc(val->data$)->available() != 0) {
		$throwNew($CRLException, $$str({"signed overrun, bytes = "_s, $$str($nc(val->data$)->available())}));
	}
	if ($nc(seq->get(0))->tag != $DerValue::tag_Sequence) {
		$throwNew($CRLException, "signed CRL fields invalid"_s);
	}
	$set(this, sigAlgId, $AlgorithmId::parse(seq->get(1)));
	$set(this, signature, $nc(seq->get(2))->getBitString());
	if ($nc($nc(seq->get(1))->data$)->available() != 0) {
		$throwNew($CRLException, "AlgorithmId field overrun"_s);
	}
	if ($nc($nc(seq->get(2))->data$)->available() != 0) {
		$throwNew($CRLException, "Signature field overrun"_s);
	}
	$set(this, tbsCertList, $nc(seq->get(0))->toByteArray());
	$var($DerInputStream, derStrm, $nc(seq->get(0))->data$);
	$var($DerValue, tmp, nullptr);
	int8_t nextByte = 0;
	this->version = 0;
	nextByte = (int8_t)$nc(derStrm)->peekByte();
	if (nextByte == $DerValue::tag_Integer) {
		this->version = derStrm->getInteger();
		if (this->version != 1) {
			$throwNew($CRLException, "Invalid version"_s);
		}
	}
	$assign(tmp, derStrm->getDerValue());
	$var($AlgorithmId, tmpId, $AlgorithmId::parse(tmp));
	if (!$nc(tmpId)->equals(this->sigAlgId)) {
		$throwNew($CRLException, "Signature algorithm mismatch"_s);
	}
	$set(this, infoSigAlgId, tmpId);
	$set(this, issuer, $new($X500Name, derStrm));
	if ($nc(this->issuer)->isEmpty()) {
		$throwNew($CRLException, "Empty issuer DN not allowed in X509CRLs"_s);
	}
	nextByte = (int8_t)derStrm->peekByte();
	if (nextByte == $DerValue::tag_UtcTime) {
		$set(this, thisUpdate, derStrm->getUTCTime());
	} else if (nextByte == $DerValue::tag_GeneralizedTime) {
		$set(this, thisUpdate, derStrm->getGeneralizedTime());
	} else {
		$throwNew($CRLException, $$str({"Invalid encoding for thisUpdate (tag="_s, $$str(nextByte), ")"_s}));
	}
	if (derStrm->available() == 0) {
		return;
	}
	nextByte = (int8_t)derStrm->peekByte();
	if (nextByte == $DerValue::tag_UtcTime) {
		$set(this, nextUpdate, derStrm->getUTCTime());
	} else if (nextByte == $DerValue::tag_GeneralizedTime) {
		$set(this, nextUpdate, derStrm->getGeneralizedTime());
	}
	if (derStrm->available() == 0) {
		return;
	}
	nextByte = (int8_t)derStrm->peekByte();
	if ((nextByte == $DerValue::tag_SequenceOf) && (!(((int32_t)(nextByte & (uint32_t)192)) == 128))) {
		$var($DerValueArray, badCerts, derStrm->getSequence(4));
		$var($X500Principal, crlIssuer, getIssuerX500Principal());
		$var($X500Principal, badCertIssuer, crlIssuer);
		for (int32_t i = 0; i < $nc(badCerts)->length; ++i) {
			$var($X509CRLEntryImpl, entry, $new($X509CRLEntryImpl, badCerts->get(i)));
			$assign(badCertIssuer, getCertIssuer(entry, badCertIssuer));
			entry->setCertificateIssuer(crlIssuer, badCertIssuer);
			$var($X509CRLImpl$X509IssuerSerial, issuerSerial, $new($X509CRLImpl$X509IssuerSerial, badCertIssuer, $(entry->getSerialNumber())));
			$nc(this->revokedMap)->put(issuerSerial, entry);
			$nc(this->revokedList)->add(entry);
		}
	}
	if (derStrm->available() == 0) {
		return;
	}
	$assign(tmp, derStrm->getDerValue());
	bool var$0 = $nc(tmp)->isConstructed();
	if (var$0 && tmp->isContextSpecific((int8_t)0)) {
		$set(this, extensions, $new($CRLExtensions, tmp->data$));
	}
	this->readOnly = true;
}

$X500Principal* X509CRLImpl::getIssuerX500Principal($X509CRL* crl) {
	$init(X509CRLImpl);
	$useLocalCurrentObjectStackCache();
	try {
		$var($bytes, encoded, $nc(crl)->getEncoded());
		$var($DerInputStream, derIn, $new($DerInputStream, encoded));
		$var($DerValue, tbsCert, $nc($(derIn->getSequence(3)))->get(0));
		$var($DerInputStream, tbsIn, $nc(tbsCert)->data$);
		$var($DerValue, tmp, nullptr);
		int8_t nextByte = (int8_t)$nc(tbsIn)->peekByte();
		if (nextByte == $DerValue::tag_Integer) {
			$assign(tmp, tbsIn->getDerValue());
		}
		$assign(tmp, tbsIn->getDerValue());
		$assign(tmp, tbsIn->getDerValue());
		$var($bytes, principalBytes, $nc(tmp)->toByteArray());
		return $new($X500Principal, principalBytes);
	} catch ($Exception& e) {
		$throwNew($RuntimeException, "Could not parse issuer"_s, e);
	}
	$shouldNotReachHere();
}

$bytes* X509CRLImpl::getEncodedInternal($X509CRL* crl) {
	$init(X509CRLImpl);
	if ($instanceOf(X509CRLImpl, crl)) {
		return $nc(($cast(X509CRLImpl, crl)))->getEncodedInternal();
	} else {
		return $nc(crl)->getEncoded();
	}
}

X509CRLImpl* X509CRLImpl::toImpl($X509CRL* crl) {
	$init(X509CRLImpl);
	if ($instanceOf(X509CRLImpl, crl)) {
		return $cast(X509CRLImpl, crl);
	} else {
		return $X509Factory::intern(crl);
	}
}

$X500Principal* X509CRLImpl::getCertIssuer($X509CRLEntryImpl* entry, $X500Principal* prevCertIssuer) {
	$useLocalCurrentObjectStackCache();
	$var($CertificateIssuerExtension, ciExt, $nc(entry)->getCertificateIssuerExtension());
	if (ciExt != nullptr) {
		$init($CertificateIssuerExtension);
		$var($GeneralNames, names, $cast($GeneralNames, ciExt->get($CertificateIssuerExtension::ISSUER)));
		$var($X500Name, issuerDN, $cast($X500Name, $nc($($nc(names)->get(0)))->getName()));
		return $nc(issuerDN)->asX500Principal();
	} else {
		return prevCertIssuer;
	}
}

void X509CRLImpl::derEncode($OutputStream* out) {
	if (this->signedCRL == nullptr) {
		$throwNew($IOException, "Null CRL to encode"_s);
	}
	$nc(out)->write($cast($bytes, $($nc(this->signedCRL)->clone())));
}

X509CRLImpl::X509CRLImpl() {
}

$Class* X509CRLImpl::load$($String* name, bool initialize) {
	$loadClass(X509CRLImpl, name, initialize, &_X509CRLImpl_ClassInfo_, allocate$X509CRLImpl);
	return class$;
}

$Class* X509CRLImpl::class$ = nullptr;

		} // x509
	} // security
} // sun