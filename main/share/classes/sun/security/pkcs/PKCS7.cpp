#include <sun/security/pkcs/PKCS7.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/math/BigInteger.h>
#include <java/net/URI.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/security/Signature.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Random.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <java/util/function/Function.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/pkcs/ContentInfo.h>
#include <sun/security/pkcs/PKCS7$SecureRandomHolder.h>
#include <sun/security/pkcs/PKCS9Attribute.h>
#include <sun/security/pkcs/PKCS9Attributes.h>
#include <sun/security/pkcs/ParsingException.h>
#include <sun/security/pkcs/SignerInfo.h>
#include <sun/security/provider/SHAKE256.h>
#include <sun/security/timestamp/HttpTimestamper.h>
#include <sun/security/timestamp/TSRequest.h>
#include <sun/security/timestamp/TSResponse.h>
#include <sun/security/timestamp/TimestampToken.h>
#include <sun/security/timestamp/Timestamper.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerEncoder.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AccessDescription.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/URIName.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CRLImpl.h>
#include <sun/security/x509/X509CertImpl.h>
#include <sun/security/x509/X509CertInfo.h>
#include <jcpp.h>

#undef CMS_ALGORITHM_PROTECTION_OID
#undef CONTENT_TYPE_OID
#undef DATA_OID
#undef DN_NAME
#undef ISSUER
#undef MESSAGE_DIGEST_OID
#undef NAME_URI
#undef NETSCAPE_CERT_SEQUENCE_OID
#undef OLD_SIGNED_DATA_OID
#undef ONE
#undef PKCS7
#undef RANDOM
#undef SIGNATURE_TIMESTAMP_TOKEN_OID
#undef SIGNED_DATA_OID
#undef SIGNING_TIME_OID

using $PrincipalArray = $Array<::java::security::Principal>;
using $X509CRLArray = $Array<::java::security::cert::X509CRL>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $PKCS9AttributeArray = $Array<::sun::security::pkcs::PKCS9Attribute>;
using $SignerInfoArray = $Array<::sun::security::pkcs::SignerInfo>;
using $DerEncoderArray = $Array<::sun::security::util::DerEncoder>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $AlgorithmIdArray = $Array<::sun::security::x509::AlgorithmId>;
using $X509CRLImplArray = $Array<::sun::security::x509::X509CRLImpl>;
using $X509CertImplArray = $Array<::sun::security::x509::X509CertImpl>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $BigInteger = ::java::math::BigInteger;
using $URI = ::java::net::URI;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Principal = ::java::security::Principal;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $Signature = ::java::security::Signature;
using $CRLException = ::java::security::cert::CRLException;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $List = ::java::util::List;
using $Random = ::java::util::Random;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $Function = ::java::util::function::Function;
using $ContentInfo = ::sun::security::pkcs::ContentInfo;
using $PKCS7$SecureRandomHolder = ::sun::security::pkcs::PKCS7$SecureRandomHolder;
using $PKCS9Attribute = ::sun::security::pkcs::PKCS9Attribute;
using $PKCS9Attributes = ::sun::security::pkcs::PKCS9Attributes;
using $ParsingException = ::sun::security::pkcs::ParsingException;
using $SignerInfo = ::sun::security::pkcs::SignerInfo;
using $SHAKE256 = ::sun::security::provider::SHAKE256;
using $HttpTimestamper = ::sun::security::timestamp::HttpTimestamper;
using $TSRequest = ::sun::security::timestamp::TSRequest;
using $TSResponse = ::sun::security::timestamp::TSResponse;
using $TimestampToken = ::sun::security::timestamp::TimestampToken;
using $Timestamper = ::sun::security::timestamp::Timestamper;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $AccessDescription = ::sun::security::x509::AccessDescription;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $URIName = ::sun::security::x509::URIName;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CRLImpl = ::sun::security::x509::X509CRLImpl;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;
using $X509CertInfo = ::sun::security::x509::X509CertInfo;

namespace sun {
	namespace security {
		namespace pkcs {

$NamedAttribute PKCS7_Attribute_var$0[] = {
	{"since", 's', "16"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _PKCS7_MethodAnnotations_generateSignedData9[] = {
	{"Ljava/lang/Deprecated;", PKCS7_Attribute_var$0},
	{}
};

$FieldInfo _PKCS7_FieldInfo_[] = {
	{"contentType", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(PKCS7, contentType)},
	{"version", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(PKCS7, version)},
	{"digestAlgorithmIds", "[Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE, $field(PKCS7, digestAlgorithmIds)},
	{"contentInfo", "Lsun/security/pkcs/ContentInfo;", nullptr, $PRIVATE, $field(PKCS7, contentInfo)},
	{"certificates", "[Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(PKCS7, certificates)},
	{"crls", "[Ljava/security/cert/X509CRL;", nullptr, $PRIVATE, $field(PKCS7, crls)},
	{"signerInfos", "[Lsun/security/pkcs/SignerInfo;", nullptr, $PRIVATE, $field(PKCS7, signerInfos)},
	{"oldStyle", "Z", nullptr, $PRIVATE, $field(PKCS7, oldStyle)},
	{"certIssuerNames", "[Ljava/security/Principal;", nullptr, $PRIVATE, $field(PKCS7, certIssuerNames)},
	{}
};

$MethodInfo _PKCS7_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(PKCS7, init$, void, $InputStream*), "sun.security.pkcs.ParsingException,java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(PKCS7, init$, void, $DerInputStream*), "sun.security.pkcs.ParsingException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(PKCS7, init$, void, $bytes*), "sun.security.pkcs.ParsingException"},
	{"<init>", "([Lsun/security/x509/AlgorithmId;Lsun/security/pkcs/ContentInfo;[Ljava/security/cert/X509Certificate;[Ljava/security/cert/X509CRL;[Lsun/security/pkcs/SignerInfo;)V", nullptr, $PUBLIC, $method(PKCS7, init$, void, $AlgorithmIdArray*, $ContentInfo*, $X509CertificateArray*, $X509CRLArray*, $SignerInfoArray*)},
	{"<init>", "([Lsun/security/x509/AlgorithmId;Lsun/security/pkcs/ContentInfo;[Ljava/security/cert/X509Certificate;[Lsun/security/pkcs/SignerInfo;)V", nullptr, $PUBLIC, $method(PKCS7, init$, void, $AlgorithmIdArray*, $ContentInfo*, $X509CertificateArray*, $SignerInfoArray*)},
	{"constructToken", "([B[Ljava/security/cert/X509Certificate;[BLsun/security/pkcs/PKCS9Attributes;Lsun/security/pkcs/PKCS9Attributes;Lsun/security/x509/AlgorithmId;Lsun/security/x509/AlgorithmId;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS7, constructToken, $bytes*, $bytes*, $X509CertificateArray*, $bytes*, $PKCS9Attributes*, $PKCS9Attributes*, $AlgorithmId*, $AlgorithmId*), "java.io.IOException"},
	{"encodeSignedData", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(PKCS7, encodeSignedData, void, $OutputStream*), "java.io.IOException"},
	{"encodeSignedData", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(PKCS7, encodeSignedData, void, $DerOutputStream*), "java.io.IOException"},
	{"generateNewSignedData", "(Ljava/lang/String;Ljava/security/Provider;Ljava/security/PrivateKey;[Ljava/security/cert/X509Certificate;[BZZLjava/util/function/Function;)[B", "(Ljava/lang/String;Ljava/security/Provider;Ljava/security/PrivateKey;[Ljava/security/cert/X509Certificate;[BZZLjava/util/function/Function<[BLsun/security/pkcs/PKCS9Attributes;>;)[B", $PUBLIC | $STATIC, $staticMethod(PKCS7, generateNewSignedData, $bytes*, $String*, $Provider*, $PrivateKey*, $X509CertificateArray*, $bytes*, bool, bool, $Function*), "java.security.SignatureException,java.security.InvalidKeyException,java.io.IOException,java.security.NoSuchAlgorithmException"},
	{"generateSignedData", "([B[Ljava/security/cert/X509Certificate;[BLjava/lang/String;Ljava/net/URI;Ljava/lang/String;Ljava/lang/String;)[B", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(PKCS7, generateSignedData, $bytes*, $bytes*, $X509CertificateArray*, $bytes*, $String*, $URI*, $String*, $String*), "java.security.cert.CertificateException,java.io.IOException,java.security.NoSuchAlgorithmException", nullptr, _PKCS7_MethodAnnotations_generateSignedData9},
	{"generateTimestampToken", "(Lsun/security/timestamp/Timestamper;Ljava/lang/String;Ljava/lang/String;[B)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(PKCS7, generateTimestampToken, $bytes*, $Timestamper*, $String*, $String*, $bytes*), "java.io.IOException,java.security.cert.CertificateException"},
	{"getCRLs", "()[Ljava/security/cert/X509CRL;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getCRLs, $X509CRLArray*)},
	{"getCertificate", "(Ljava/math/BigInteger;Lsun/security/x509/X500Name;)Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getCertificate, $X509Certificate*, $BigInteger*, $X500Name*)},
	{"getCertificates", "()[Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getCertificates, $X509CertificateArray*)},
	{"getContentInfo", "()Lsun/security/pkcs/ContentInfo;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getContentInfo, $ContentInfo*)},
	{"getDigestAlgorithmIds", "()[Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getDigestAlgorithmIds, $AlgorithmIdArray*)},
	{"getSignerInfos", "()[Lsun/security/pkcs/SignerInfo;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getSignerInfos, $SignerInfoArray*)},
	{"getTimestampingURI", "(Ljava/security/cert/X509Certificate;)Ljava/net/URI;", nullptr, $PUBLIC | $STATIC, $staticMethod(PKCS7, getTimestampingURI, $URI*, $X509Certificate*)},
	{"getVersion", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(PKCS7, getVersion, $BigInteger*)},
	{"isOldStyle", "()Z", nullptr, $PUBLIC, $virtualMethod(PKCS7, isOldStyle, bool)},
	{"parse", "(Lsun/security/util/DerInputStream;)V", nullptr, $PRIVATE, $method(PKCS7, parse, void, $DerInputStream*), "sun.security.pkcs.ParsingException"},
	{"parse", "(Lsun/security/util/DerInputStream;Z)V", nullptr, $PRIVATE, $method(PKCS7, parse, void, $DerInputStream*, bool), "java.io.IOException"},
	{"parseNetscapeCertChain", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(PKCS7, parseNetscapeCertChain, void, $DerValue*), "sun.security.pkcs.ParsingException,java.io.IOException"},
	{"parseOldSignedData", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(PKCS7, parseOldSignedData, void, $DerValue*), "sun.security.pkcs.ParsingException,java.io.IOException"},
	{"parseSignedData", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(PKCS7, parseSignedData, void, $DerValue*), "sun.security.pkcs.ParsingException,java.io.IOException"},
	{"populateCertIssuerNames", "()V", nullptr, $PRIVATE, $method(PKCS7, populateCertIssuerNames, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS7, toString, $String*)},
	{"verify", "(Lsun/security/pkcs/SignerInfo;[B)Lsun/security/pkcs/SignerInfo;", nullptr, $PUBLIC, $virtualMethod(PKCS7, verify, $SignerInfo*, $SignerInfo*, $bytes*), "java.security.NoSuchAlgorithmException,java.security.SignatureException"},
	{"verify", "([B)[Lsun/security/pkcs/SignerInfo;", nullptr, $PUBLIC, $virtualMethod(PKCS7, verify, $SignerInfoArray*, $bytes*), "java.security.NoSuchAlgorithmException,java.security.SignatureException"},
	{"verify", "()[Lsun/security/pkcs/SignerInfo;", nullptr, $PUBLIC, $virtualMethod(PKCS7, verify, $SignerInfoArray*), "java.security.NoSuchAlgorithmException,java.security.SignatureException"},
	{}
};

$InnerClassInfo _PKCS7_InnerClassesInfo_[] = {
	{"sun.security.pkcs.PKCS7$SecureRandomHolder", "sun.security.pkcs.PKCS7", "SecureRandomHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PKCS7_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.pkcs.PKCS7",
	"java.lang.Object",
	nullptr,
	_PKCS7_FieldInfo_,
	_PKCS7_MethodInfo_,
	nullptr,
	nullptr,
	_PKCS7_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.pkcs.PKCS7$SecureRandomHolder"
};

$Object* allocate$PKCS7($Class* clazz) {
	return $of($alloc(PKCS7));
}

void PKCS7::init$($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$set(this, version, nullptr);
	$set(this, digestAlgorithmIds, nullptr);
	$set(this, contentInfo, nullptr);
	$set(this, certificates, nullptr);
	$set(this, crls, nullptr);
	$set(this, signerInfos, nullptr);
	this->oldStyle = false;
	$var($DataInputStream, dis, $new($DataInputStream, in));
	$var($bytes, data, $new($bytes, dis->available()));
	dis->readFully(data);
	parse($$new($DerInputStream, data));
}

void PKCS7::init$($DerInputStream* derin) {
	$set(this, version, nullptr);
	$set(this, digestAlgorithmIds, nullptr);
	$set(this, contentInfo, nullptr);
	$set(this, certificates, nullptr);
	$set(this, crls, nullptr);
	$set(this, signerInfos, nullptr);
	this->oldStyle = false;
	parse(derin);
}

void PKCS7::init$($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	$set(this, version, nullptr);
	$set(this, digestAlgorithmIds, nullptr);
	$set(this, contentInfo, nullptr);
	$set(this, certificates, nullptr);
	$set(this, crls, nullptr);
	$set(this, signerInfos, nullptr);
	this->oldStyle = false;
	try {
		$var($DerInputStream, derin, $new($DerInputStream, bytes));
		parse(derin);
	} catch ($IOException& ioe1) {
		$var($ParsingException, pe, $new($ParsingException, "Unable to parse the encoded bytes"_s));
		pe->initCause(ioe1);
		$throw(pe);
	}
}

void PKCS7::parse($DerInputStream* derin) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(derin)->mark(derin->available());
		parse(derin, false);
	} catch ($IOException& ioe) {
		try {
			$nc(derin)->reset();
			parse(derin, true);
			this->oldStyle = true;
		} catch ($IOException& ioe1) {
			$var($ParsingException, pe, $new($ParsingException, $(ioe1->getMessage())));
			pe->initCause(ioe);
			pe->addSuppressed(ioe1);
			$throw(pe);
		}
	}
}

void PKCS7::parse($DerInputStream* derin, bool oldStyle) {
	$useLocalCurrentObjectStackCache();
	$var($ContentInfo, block, $new($ContentInfo, derin, oldStyle));
	$set(this, contentType, block->contentType);
	$var($DerValue, content, block->getContent());
	if ($nc(this->contentType)->equals($ContentInfo::SIGNED_DATA_OID)) {
		parseSignedData(content);
	} else {
		if ($nc(this->contentType)->equals($ContentInfo::OLD_SIGNED_DATA_OID)) {
			parseOldSignedData(content);
		} else {
			if ($nc(this->contentType)->equals($ContentInfo::NETSCAPE_CERT_SEQUENCE_OID)) {
				parseNetscapeCertChain(content);
				$set(this, contentInfo, block);
			} else {
				$throwNew($ParsingException, $$str({"content type "_s, this->contentType, " not supported."_s}));
			}
		}
	}
}

void PKCS7::init$($AlgorithmIdArray* digestAlgorithmIds, $ContentInfo* contentInfo, $X509CertificateArray* certificates, $X509CRLArray* crls, $SignerInfoArray* signerInfos) {
	$set(this, version, nullptr);
	$set(this, digestAlgorithmIds, nullptr);
	$set(this, contentInfo, nullptr);
	$set(this, certificates, nullptr);
	$set(this, crls, nullptr);
	$set(this, signerInfos, nullptr);
	this->oldStyle = false;
	$init($BigInteger);
	$set(this, version, $BigInteger::ONE);
	$set(this, digestAlgorithmIds, digestAlgorithmIds);
	$set(this, contentInfo, contentInfo);
	$set(this, certificates, certificates);
	$set(this, crls, crls);
	$set(this, signerInfos, signerInfos);
}

void PKCS7::init$($AlgorithmIdArray* digestAlgorithmIds, $ContentInfo* contentInfo, $X509CertificateArray* certificates, $SignerInfoArray* signerInfos) {
	PKCS7::init$(digestAlgorithmIds, contentInfo, certificates, nullptr, signerInfos);
}

void PKCS7::parseNetscapeCertChain($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, dis, $new($DerInputStream, $($nc(val)->toByteArray())));
	$var($DerValueArray, contents, dis->getSequence(2));
	$set(this, certificates, $new($X509CertificateArray, $nc(contents)->length));
	$var($CertificateFactory, certfac, nullptr);
	try {
		$assign(certfac, $CertificateFactory::getInstance("X.509"_s));
	} catch ($CertificateException& ce) {
	}
	for (int32_t i = 0; i < contents->length; ++i) {
		$var($ByteArrayInputStream, bais, nullptr);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if (certfac == nullptr) {
						$nc(this->certificates)->set(i, $$new($X509CertImpl, contents->get(i)));
					} else {
						$var($bytes, encoded, $nc(contents->get(i))->toByteArray());
						$assign(bais, $new($ByteArrayInputStream, encoded));
						$nc(this->certificates)->set(i, $cast($X509Certificate, $($nc(certfac)->generateCertificate(bais))));
						bais->close();
						$assign(bais, nullptr);
					}
				} catch ($CertificateException& ce) {
					$var($ParsingException, pe, $new($ParsingException, $(ce->getMessage())));
					pe->initCause(ce);
					$throw(pe);
				} catch ($IOException& ioe) {
					$var($ParsingException, pe, $new($ParsingException, $(ioe->getMessage())));
					pe->initCause(ioe);
					$throw(pe);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (bais != nullptr) {
					bais->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void PKCS7::parseSignedData($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, dis, $nc(val)->toDerInputStream());
	$set(this, version, $nc(dis)->getBigInteger());
	$var($DerValueArray, digestAlgorithmIdVals, dis->getSet(1));
	int32_t len = $nc(digestAlgorithmIdVals)->length;
	$set(this, digestAlgorithmIds, $new($AlgorithmIdArray, len));
	try {
		for (int32_t i = 0; i < len; ++i) {
			$var($DerValue, oid, digestAlgorithmIdVals->get(i));
			$nc(this->digestAlgorithmIds)->set(i, $($AlgorithmId::parse(oid)));
		}
	} catch ($IOException& e) {
		$var($ParsingException, pe, $new($ParsingException, $$str({"Error parsing digest AlgorithmId IDs: "_s, $(e->getMessage())})));
		pe->initCause(e);
		$throw(pe);
	}
	$set(this, contentInfo, $new($ContentInfo, dis));
	$var($CertificateFactory, certfac, nullptr);
	try {
		$assign(certfac, $CertificateFactory::getInstance("X.509"_s));
	} catch ($CertificateException& ce) {
	}
	if ((int8_t)(dis->peekByte()) == (int8_t)160) {
		$var($DerValueArray, certVals, dis->getSet(2, true));
		len = $nc(certVals)->length;
		$set(this, certificates, $new($X509CertificateArray, len));
		int32_t count = 0;
		for (int32_t i = 0; i < len; ++i) {
			$var($ByteArrayInputStream, bais, nullptr);
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						int8_t tag = $nc(certVals->get(i))->getTag();
						if (tag == $DerValue::tag_Sequence) {
							if (certfac == nullptr) {
								$nc(this->certificates)->set(count, $$new($X509CertImpl, certVals->get(i)));
							} else {
								$var($bytes, encoded, $nc(certVals->get(i))->toByteArray());
								$assign(bais, $new($ByteArrayInputStream, encoded));
								$nc(this->certificates)->set(count, $cast($X509Certificate, $($nc(certfac)->generateCertificate(bais))));
								bais->close();
								$assign(bais, nullptr);
							}
							++count;
						}
					} catch ($CertificateException& ce) {
						$var($ParsingException, pe, $new($ParsingException, $(ce->getMessage())));
						pe->initCause(ce);
						$throw(pe);
					} catch ($IOException& ioe) {
						$var($ParsingException, pe, $new($ParsingException, $(ioe->getMessage())));
						pe->initCause(ioe);
						$throw(pe);
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					if (bais != nullptr) {
						bais->close();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
		if (count != len) {
			$set(this, certificates, $fcast($X509CertificateArray, $Arrays::copyOf(this->certificates, count)));
		}
	}
	if ((int8_t)(dis->peekByte()) == (int8_t)161) {
		$var($DerValueArray, crlVals, dis->getSet(1, true));
		len = $nc(crlVals)->length;
		$set(this, crls, $new($X509CRLArray, len));
		for (int32_t i = 0; i < len; ++i) {
			$var($ByteArrayInputStream, bais, nullptr);
			{
				$var($Throwable, var$2, nullptr);
				try {
					try {
						if (certfac == nullptr) {
							$nc(this->crls)->set(i, $$new($X509CRLImpl, crlVals->get(i)));
						} else {
							$var($bytes, encoded, $nc(crlVals->get(i))->toByteArray());
							$assign(bais, $new($ByteArrayInputStream, encoded));
							$nc(this->crls)->set(i, $cast($X509CRL, $($nc(certfac)->generateCRL(bais))));
							bais->close();
							$assign(bais, nullptr);
						}
					} catch ($CRLException& e) {
						$var($ParsingException, pe, $new($ParsingException, $(e->getMessage())));
						pe->initCause(e);
						$throw(pe);
					}
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					if (bais != nullptr) {
						bais->close();
					}
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		}
	}
	$var($DerValueArray, signerInfoVals, dis->getSet(1));
	len = $nc(signerInfoVals)->length;
	$set(this, signerInfos, $new($SignerInfoArray, len));
	for (int32_t i = 0; i < len; ++i) {
		$var($DerInputStream, in, $nc(signerInfoVals->get(i))->toDerInputStream());
		$nc(this->signerInfos)->set(i, $$new($SignerInfo, in));
	}
}

void PKCS7::parseOldSignedData($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, dis, $nc(val)->toDerInputStream());
	$set(this, version, $nc(dis)->getBigInteger());
	$var($DerValueArray, digestAlgorithmIdVals, dis->getSet(1));
	int32_t len = $nc(digestAlgorithmIdVals)->length;
	$set(this, digestAlgorithmIds, $new($AlgorithmIdArray, len));
	try {
		for (int32_t i = 0; i < len; ++i) {
			$var($DerValue, oid, digestAlgorithmIdVals->get(i));
			$nc(this->digestAlgorithmIds)->set(i, $($AlgorithmId::parse(oid)));
		}
	} catch ($IOException& e) {
		$throwNew($ParsingException, "Error parsing digest AlgorithmId IDs"_s);
	}
	$set(this, contentInfo, $new($ContentInfo, dis, true));
	$var($CertificateFactory, certfac, nullptr);
	try {
		$assign(certfac, $CertificateFactory::getInstance("X.509"_s));
	} catch ($CertificateException& ce) {
	}
	$var($DerValueArray, certVals, dis->getSet(2));
	len = $nc(certVals)->length;
	$set(this, certificates, $new($X509CertificateArray, len));
	for (int32_t i = 0; i < len; ++i) {
		$var($ByteArrayInputStream, bais, nullptr);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if (certfac == nullptr) {
						$nc(this->certificates)->set(i, $$new($X509CertImpl, certVals->get(i)));
					} else {
						$var($bytes, encoded, $nc(certVals->get(i))->toByteArray());
						$assign(bais, $new($ByteArrayInputStream, encoded));
						$nc(this->certificates)->set(i, $cast($X509Certificate, $($nc(certfac)->generateCertificate(bais))));
						bais->close();
						$assign(bais, nullptr);
					}
				} catch ($CertificateException& ce) {
					$var($ParsingException, pe, $new($ParsingException, $(ce->getMessage())));
					pe->initCause(ce);
					$throw(pe);
				} catch ($IOException& ioe) {
					$var($ParsingException, pe, $new($ParsingException, $(ioe->getMessage())));
					pe->initCause(ioe);
					$throw(pe);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (bais != nullptr) {
					bais->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	dis->getSet(0);
	$var($DerValueArray, signerInfoVals, dis->getSet(1));
	len = $nc(signerInfoVals)->length;
	$set(this, signerInfos, $new($SignerInfoArray, len));
	for (int32_t i = 0; i < len; ++i) {
		$var($DerInputStream, in, $nc(signerInfoVals->get(i))->toDerInputStream());
		$nc(this->signerInfos)->set(i, $$new($SignerInfo, in, true));
	}
}

void PKCS7::encodeSignedData($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, derout, $new($DerOutputStream));
	encodeSignedData(derout);
	$nc(out)->write($(derout->toByteArray()));
}

void PKCS7::encodeSignedData($DerOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, signedData, $new($DerOutputStream));
	signedData->putInteger(this->version);
	signedData->putOrderedSetOf($DerValue::tag_Set, $fcast($DerEncoderArray, this->digestAlgorithmIds));
	$nc(this->contentInfo)->encode(signedData);
	if (this->certificates != nullptr && $nc(this->certificates)->length != 0) {
		$var($X509CertImplArray, implCerts, $new($X509CertImplArray, $nc(this->certificates)->length));
		for (int32_t i = 0; i < $nc(this->certificates)->length; ++i) {
			if ($instanceOf($X509CertImpl, $nc(this->certificates)->get(i))) {
				implCerts->set(i, $cast($X509CertImpl, $nc(this->certificates)->get(i)));
			} else {
				try {
					$var($bytes, encoded, $nc($nc(this->certificates)->get(i))->getEncoded());
					implCerts->set(i, $$new($X509CertImpl, encoded));
				} catch ($CertificateException& ce) {
					$throwNew($IOException, static_cast<$Throwable*>(ce));
				}
			}
		}
		signedData->putOrderedSetOf((int8_t)160, $fcast($DerEncoderArray, implCerts));
	}
	if (this->crls != nullptr && $nc(this->crls)->length != 0) {
		$var($Set, implCRLs, $new($HashSet, $nc(this->crls)->length));
		{
			$var($X509CRLArray, arr$, this->crls);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($X509CRL, crl, arr$->get(i$));
				{
					if ($instanceOf($X509CRLImpl, crl)) {
						implCRLs->add($cast($X509CRLImpl, crl));
					} else {
						try {
							$var($bytes, encoded, $nc(crl)->getEncoded());
							implCRLs->add($$new($X509CRLImpl, encoded));
						} catch ($CRLException& ce) {
							$throwNew($IOException, static_cast<$Throwable*>(ce));
						}
					}
				}
			}
		}
		signedData->putOrderedSetOf((int8_t)161, $fcast($DerEncoderArray, $(implCRLs->toArray($$new($X509CRLImplArray, implCRLs->size())))));
	}
	signedData->putOrderedSetOf($DerValue::tag_Set, $fcast($DerEncoderArray, this->signerInfos));
	$var($DerValue, signedDataSeq, $new($DerValue, $DerValue::tag_Sequence, $(signedData->toByteArray())));
	$var($ContentInfo, block, $new($ContentInfo, $ContentInfo::SIGNED_DATA_OID, signedDataSeq));
	block->encode(out);
}

$SignerInfo* PKCS7::verify($SignerInfo* info, $bytes* bytes) {
	return $nc(info)->verify(this, bytes);
}

$SignerInfoArray* PKCS7::verify($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	$var($Vector, intResult, $new($Vector));
	for (int32_t i = 0; i < $nc(this->signerInfos)->length; ++i) {
		$var($SignerInfo, signerInfo, verify($nc(this->signerInfos)->get(i), bytes));
		if (signerInfo != nullptr) {
			intResult->addElement(signerInfo);
		}
	}
	if (!intResult->isEmpty()) {
		$var($SignerInfoArray, result, $new($SignerInfoArray, intResult->size()));
		intResult->copyInto(result);
		return result;
	}
	return nullptr;
}

$SignerInfoArray* PKCS7::verify() {
	return verify(nullptr);
}

$BigInteger* PKCS7::getVersion() {
	return this->version;
}

$AlgorithmIdArray* PKCS7::getDigestAlgorithmIds() {
	return this->digestAlgorithmIds;
}

$ContentInfo* PKCS7::getContentInfo() {
	return this->contentInfo;
}

$X509CertificateArray* PKCS7::getCertificates() {
	if (this->certificates != nullptr) {
		return $cast($X509CertificateArray, $nc(this->certificates)->clone());
	} else {
		return nullptr;
	}
}

$X509CRLArray* PKCS7::getCRLs() {
	if (this->crls != nullptr) {
		return $cast($X509CRLArray, $nc(this->crls)->clone());
	} else {
		return nullptr;
	}
}

$SignerInfoArray* PKCS7::getSignerInfos() {
	return this->signerInfos;
}

$X509Certificate* PKCS7::getCertificate($BigInteger* serial, $X500Name* issuerName) {
	$useLocalCurrentObjectStackCache();
	if (this->certificates != nullptr) {
		if (this->certIssuerNames == nullptr) {
			populateCertIssuerNames();
		}
		for (int32_t i = 0; i < $nc(this->certificates)->length; ++i) {
			$var($X509Certificate, cert, $nc(this->certificates)->get(i));
			$var($BigInteger, thisSerial, $nc(cert)->getSerialNumber());
			bool var$0 = $nc(serial)->equals(thisSerial);
			if (var$0 && $nc(issuerName)->equals($nc(this->certIssuerNames)->get(i))) {
				return cert;
			}
		}
	}
	return nullptr;
}

void PKCS7::populateCertIssuerNames() {
	$useLocalCurrentObjectStackCache();
	if (this->certificates == nullptr) {
		return;
	}
	$set(this, certIssuerNames, $new($PrincipalArray, $nc(this->certificates)->length));
	for (int32_t i = 0; i < $nc(this->certificates)->length; ++i) {
		$var($X509Certificate, cert, $nc(this->certificates)->get(i));
		$var($Principal, certIssuerName, $nc(cert)->getIssuerDN());
		if (!($instanceOf($X500Name, certIssuerName))) {
			try {
				$var($X509CertInfo, tbsCert, $new($X509CertInfo, $(cert->getTBSCertificate())));
				$init($X509CertInfo);
				$assign(certIssuerName, $cast($Principal, tbsCert->get($$str({$X509CertInfo::ISSUER, "."_s, $X509CertInfo::DN_NAME}))));
			} catch ($Exception& e) {
			}
		}
		$nc(this->certIssuerNames)->set(i, certIssuerName);
	}
}

$String* PKCS7::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, out, ""_s);
	$plusAssign(out, $$str({this->contentInfo, "\n"_s}));
	if (this->version != nullptr) {
		$plusAssign(out, $$str({"PKCS7 :: version: "_s, $($Debug::toHexString(this->version)), "\n"_s}));
	}
	if (this->digestAlgorithmIds != nullptr) {
		$plusAssign(out, "PKCS7 :: digest AlgorithmIds: \n"_s);
		for (int32_t i = 0; i < $nc(this->digestAlgorithmIds)->length; ++i) {
			$plusAssign(out, $$str({"\t"_s, $nc(this->digestAlgorithmIds)->get(i), "\n"_s}));
		}
	}
	if (this->certificates != nullptr) {
		$plusAssign(out, "PKCS7 :: certificates: \n"_s);
		for (int32_t i = 0; i < $nc(this->certificates)->length; ++i) {
			$plusAssign(out, $$str({"\t"_s, $$str(i), ".   "_s, $nc(this->certificates)->get(i), "\n"_s}));
		}
	}
	if (this->crls != nullptr) {
		$plusAssign(out, "PKCS7 :: crls: \n"_s);
		for (int32_t i = 0; i < $nc(this->crls)->length; ++i) {
			$plusAssign(out, $$str({"\t"_s, $$str(i), ".   "_s, $nc(this->crls)->get(i), "\n"_s}));
		}
	}
	if (this->signerInfos != nullptr) {
		$plusAssign(out, "PKCS7 :: signer infos: \n"_s);
		for (int32_t i = 0; i < $nc(this->signerInfos)->length; ++i) {
			$plusAssign(out, ($$str({"\t"_s, $$str(i), ".  "_s, $nc(this->signerInfos)->get(i), "\n"_s})));
		}
	}
	return out;
}

bool PKCS7::isOldStyle() {
	return this->oldStyle;
}

$bytes* PKCS7::generateNewSignedData($String* sigalg, $Provider* sigProvider, $PrivateKey* privateKey, $X509CertificateArray* signerChain, $bytes* content, bool internalsf, bool directsign, $Function* ts) {
	$useLocalCurrentObjectStackCache();
	$var($Signature, signer, $SignatureUtil::fromKey(sigalg, static_cast<$Key*>(privateKey), sigProvider));
	$var($AlgorithmId, digAlgID, $SignatureUtil::getDigestAlgInPkcs7SignerInfo(signer, sigalg, privateKey, directsign));
	$var($AlgorithmId, sigAlgID, $SignatureUtil::fromSignature(signer, privateKey));
	$var($PKCS9Attributes, authAttrs, nullptr);
	if (!directsign) {
		$var($bytes, md, nullptr);
		$var($String, digAlgName, $nc(digAlgID)->getName());
		bool var$0 = $nc(digAlgName)->equals("SHAKE256"_s);
		if (var$0 || $nc(digAlgName)->equals("SHAKE256-LEN"_s)) {
			$var($SHAKE256, shaker, $new($SHAKE256, 64));
			shaker->update(content, 0, $nc(content)->length);
			$assign(md, shaker->digest());
		} else {
			$assign(md, $nc($($MessageDigest::getInstance(digAlgName)))->digest(content));
		}
		$var($DerOutputStream, derAp, $new($DerOutputStream));
		$var($DerOutputStream, derAlgs, $new($DerOutputStream));
		digAlgID->derEncode(derAlgs);
		$var($DerOutputStream, derSigAlg, $new($DerOutputStream));
		$nc(sigAlgID)->derEncode(derSigAlg);
		derAlgs->writeImplicit((int8_t)161, derSigAlg);
		derAp->write($DerValue::tag_Sequence, derAlgs);
		$init($PKCS9Attribute);
		$init($ContentInfo);
		$assign(authAttrs, $new($PKCS9Attributes, $$new($PKCS9AttributeArray, {
			$$new($PKCS9Attribute, $PKCS9Attribute::CONTENT_TYPE_OID, $ContentInfo::DATA_OID),
			$$new($PKCS9Attribute, $PKCS9Attribute::SIGNING_TIME_OID, $$new($Date)),
			$$new($PKCS9Attribute, $PKCS9Attribute::CMS_ALGORITHM_PROTECTION_OID, $(derAp->toByteArray())),
			$$new($PKCS9Attribute, $PKCS9Attribute::MESSAGE_DIGEST_OID, md)
		})));
		$nc(signer)->update($(authAttrs->getDerEncoding()));
	} else {
		$nc(signer)->update(content);
	}
	$var($bytes, signature, $nc(signer)->sign());
	return constructToken(signature, signerChain, internalsf ? content : ($bytes*)nullptr, authAttrs, ts == nullptr ? ($PKCS9Attributes*)nullptr : $cast($PKCS9Attributes, $($nc(ts)->apply(signature))), digAlgID, sigAlgID);
}

$bytes* PKCS7::constructToken($bytes* signature, $X509CertificateArray* signerChain, $bytes* content, $PKCS9Attributes* authAttrs, $PKCS9Attributes* unauthAttrs, $AlgorithmId* digAlgID, $AlgorithmId* encAlgID) {
	$useLocalCurrentObjectStackCache();
	$var($X500Name, issuerName, $X500Name::asX500Name($($nc($nc(signerChain)->get(0))->getIssuerX500Principal())));
	$var($BigInteger, serialNumber, $nc($nc(signerChain)->get(0))->getSerialNumber());
	$var($SignerInfo, signerInfo, $new($SignerInfo, issuerName, serialNumber, digAlgID, authAttrs, encAlgID, signature, unauthAttrs));
	$var($SignerInfoArray, signerInfos, $new($SignerInfoArray, {signerInfo}));
	$var($AlgorithmIdArray, algorithms, $new($AlgorithmIdArray, {$(signerInfo->getDigestAlgorithmId())}));
	$init($ContentInfo);
	$var($ContentInfo, contentInfo, (content == nullptr) ? $new($ContentInfo, $ContentInfo::DATA_OID, ($DerValue*)nullptr) : $new($ContentInfo, content));
	$var(PKCS7, pkcs7, $new(PKCS7, algorithms, contentInfo, signerChain, signerInfos));
	$var($ByteArrayOutputStream, p7out, $new($ByteArrayOutputStream));
	pkcs7->encodeSignedData(static_cast<$OutputStream*>(p7out));
	return p7out->toByteArray();
}

$bytes* PKCS7::generateSignedData($bytes* signature, $X509CertificateArray* signerChain, $bytes* content, $String* signatureAlgorithm, $URI* tsaURI, $String* tSAPolicyID, $String* tSADigestAlg) {
	$useLocalCurrentObjectStackCache();
	$var($PKCS9Attributes, unauthAttrs, nullptr);
	if (tsaURI != nullptr) {
		$var($HttpTimestamper, tsa, $new($HttpTimestamper, tsaURI));
		$var($bytes, tsToken, generateTimestampToken(tsa, tSAPolicyID, tSADigestAlg, signature));
		$init($PKCS9Attribute);
		$assign(unauthAttrs, $new($PKCS9Attributes, $$new($PKCS9AttributeArray, {$$new($PKCS9Attribute, $PKCS9Attribute::SIGNATURE_TIMESTAMP_TOKEN_OID, tsToken)})));
	}
	$var($bytes, var$0, signature);
	$var($X509CertificateArray, var$1, signerChain);
	$var($bytes, var$2, content);
	$var($PKCS9Attributes, var$3, unauthAttrs);
	$var($AlgorithmId, var$4, $AlgorithmId::get($($SignatureUtil::extractDigestAlgFromDwithE(signatureAlgorithm))));
	return constructToken(var$0, var$1, var$2, nullptr, var$3, var$4, $($AlgorithmId::get(signatureAlgorithm)));
}

$URI* PKCS7::getTimestampingURI($X509Certificate* tsaCertificate) {
	$useLocalCurrentObjectStackCache();
	if (tsaCertificate == nullptr) {
		return nullptr;
	}
	try {
		$init($KnownOIDs);
		$var($bytes, extensionValue, $nc(tsaCertificate)->getExtensionValue($($KnownOIDs::SubjectInfoAccess->value())));
		if (extensionValue == nullptr) {
			return nullptr;
		}
		$var($DerInputStream, der, $new($DerInputStream, extensionValue));
		$assign(der, $new($DerInputStream, $(der->getOctetString())));
		$var($DerValueArray, derValue, der->getSequence(5));
		$var($AccessDescription, description, nullptr);
		$var($GeneralName, location, nullptr);
		$var($URIName, uri, nullptr);
		for (int32_t i = 0; i < $nc(derValue)->length; ++i) {
			$assign(description, $new($AccessDescription, derValue->get(i)));
			if ($nc($(description->getAccessMethod()))->equals($($ObjectIdentifier::of($KnownOIDs::AD_TimeStamping)))) {
				$assign(location, description->getAccessLocation());
				if ($nc(location)->getType() == $GeneralNameInterface::NAME_URI) {
					$assign(uri, $cast($URIName, location->getName()));
					bool var$0 = $nc($($nc(uri)->getScheme()))->equalsIgnoreCase("http"_s);
					if (var$0 || $nc($($nc(uri)->getScheme()))->equalsIgnoreCase("https"_s)) {
						return uri->getURI();
					}
				}
			}
		}
	} catch ($IOException& ioe) {
	}
	return nullptr;
}

$bytes* PKCS7::generateTimestampToken($Timestamper* tsa, $String* tSAPolicyID, $String* tSADigestAlg, $bytes* toBeTimestamped) {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, messageDigest, nullptr);
	$var($TSRequest, tsQuery, nullptr);
	try {
		$assign(messageDigest, $MessageDigest::getInstance(tSADigestAlg));
		$assign(tsQuery, $new($TSRequest, tSAPolicyID, toBeTimestamped, messageDigest));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(e));
	}
	$var($BigInteger, nonce, nullptr);
	$init($PKCS7$SecureRandomHolder);
	if ($PKCS7$SecureRandomHolder::RANDOM != nullptr) {
		$assign(nonce, $new($BigInteger, 64, static_cast<$Random*>($PKCS7$SecureRandomHolder::RANDOM)));
		$nc(tsQuery)->setNonce(nonce);
	}
	$nc(tsQuery)->requestCertificate(true);
	$var($TSResponse, tsReply, $nc(tsa)->generateTimestamp(tsQuery));
	int32_t status = $nc(tsReply)->getStatusCode();
	if (status != 0 && status != 1) {
		$var($String, var$0, $$str({"Error generating timestamp: "_s, $(tsReply->getStatusCodeAsText()), " "_s}));
		$throwNew($IOException, $$concat(var$0, $(tsReply->getFailureCodeAsText())));
	}
	if (tSAPolicyID != nullptr && !tSAPolicyID->equals($($nc($(tsReply->getTimestampToken()))->getPolicyID()))) {
		$throwNew($IOException, "TSAPolicyID changed in timestamp token"_s);
	}
	$var(PKCS7, tsToken, tsReply->getToken());
	$var($TimestampToken, tst, tsReply->getTimestampToken());
	try {
		if (!$nc($($nc(tst)->getHashAlgorithm()))->equals($($AlgorithmId::get(tSADigestAlg)))) {
			$throwNew($IOException, $$str({"Digest algorithm not "_s, tSADigestAlg, " in timestamp token"_s}));
		}
	} catch ($NoSuchAlgorithmException& nase) {
		$throwNew($IllegalArgumentException);
	}
	$var($bytes, var$1, $nc(tst)->getHashedMessage());
	if (!$MessageDigest::isEqual(var$1, $(tsQuery->getHashedMessage()))) {
		$throwNew($IOException, "Digest octets changed in timestamp token"_s);
	}
	$var($BigInteger, replyNonce, $nc(tst)->getNonce());
	if (replyNonce == nullptr && nonce != nullptr) {
		$throwNew($IOException, "Nonce missing in timestamp token"_s);
	}
	if (replyNonce != nullptr && !replyNonce->equals(nonce)) {
		$throwNew($IOException, "Nonce changed in timestamp token"_s);
	}
	{
		$var($SignerInfoArray, arr$, $nc(tsToken)->getSignerInfos());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($SignerInfo, si, arr$->get(i$));
			{
				$var($X509Certificate, cert, $nc(si)->getCertificate(tsToken));
				if (cert == nullptr) {
					$throwNew($CertificateException, "Certificate not included in timestamp token"_s);
				} else {
					$init($KnownOIDs);
					if (!$nc($($nc(cert)->getCriticalExtensionOIDs()))->contains($($KnownOIDs::extendedKeyUsage->value()))) {
						$throwNew($CertificateException, "Certificate is not valid for timestamping"_s);
					}
					$var($List, keyPurposes, $nc(cert)->getExtendedKeyUsage());
					if (keyPurposes == nullptr || !$nc(keyPurposes)->contains($($KnownOIDs::KP_TimeStamping->value()))) {
						$throwNew($CertificateException, "Certificate is not valid for timestamping"_s);
					}
				}
			}
		}
	}
	return tsReply->getEncodedToken();
}

PKCS7::PKCS7() {
}

$Class* PKCS7::load$($String* name, bool initialize) {
	$loadClass(PKCS7, name, initialize, &_PKCS7_ClassInfo_, allocate$PKCS7);
	return class$;
}

$Class* PKCS7::class$ = nullptr;

		} // pkcs
	} // security
} // sun