#include <sun/security/pkcs/SignerInfo.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Principal.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/Timestamp.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertPathValidatorException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/PSSParameterSpec.h>
#include <java/util/ArrayList.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/pkcs/ContentInfo.h>
#include <sun/security/pkcs/PKCS7.h>
#include <sun/security/pkcs/PKCS9Attribute.h>
#include <sun/security/pkcs/PKCS9Attributes.h>
#include <sun/security/pkcs/ParsingException.h>
#include <sun/security/provider/SHAKE256.h>
#include <sun/security/timestamp/TimestampToken.h>
#include <sun/security/util/ConstraintsParameters.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/DisabledAlgorithmConstraints.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/JarConstraintsParameters.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/SignatureUtil$EdDSADigestAlgHolder.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/KeyUsageExtension.h>
#include <sun/security/x509/X500Name.h>
#include <jcpp.h>

#undef CMS_ALGORITHM_PROTECTION_OID
#undef CONTENT_TYPE_OID
#undef DIGITAL_SIGNATURE
#undef JAR_DISABLED_CHECK
#undef MESSAGE_DIGEST_OID
#undef NON_REPUDIATION
#undef ONE
#undef SIGNATURE_TIMESTAMP_TOKEN_OID

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $SignerInfoArray = $Array<::sun::security::pkcs::SignerInfo>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Principal = ::java::security::Principal;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $Timestamp = ::java::security::Timestamp;
using $CertPath = ::java::security::cert::CertPath;
using $CertPathValidatorException = ::java::security::cert::CertPathValidatorException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $PSSParameterSpec = ::java::security::spec::PSSParameterSpec;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $ContentInfo = ::sun::security::pkcs::ContentInfo;
using $PKCS7 = ::sun::security::pkcs::PKCS7;
using $PKCS9Attribute = ::sun::security::pkcs::PKCS9Attribute;
using $PKCS9Attributes = ::sun::security::pkcs::PKCS9Attributes;
using $ParsingException = ::sun::security::pkcs::ParsingException;
using $SHAKE256 = ::sun::security::provider::SHAKE256;
using $TimestampToken = ::sun::security::timestamp::TimestampToken;
using $ConstraintsParameters = ::sun::security::util::ConstraintsParameters;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $DisabledAlgorithmConstraints = ::sun::security::util::DisabledAlgorithmConstraints;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $JarConstraintsParameters = ::sun::security::util::JarConstraintsParameters;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $SignatureUtil$EdDSADigestAlgHolder = ::sun::security::util::SignatureUtil$EdDSADigestAlgHolder;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $KeyUsageExtension = ::sun::security::x509::KeyUsageExtension;
using $X500Name = ::sun::security::x509::X500Name;

namespace sun {
	namespace security {
		namespace pkcs {

$FieldInfo _SignerInfo_FieldInfo_[] = {
	{"JAR_DISABLED_CHECK", "Lsun/security/util/DisabledAlgorithmConstraints;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SignerInfo, JAR_DISABLED_CHECK)},
	{"version", "Ljava/math/BigInteger;", nullptr, 0, $field(SignerInfo, version)},
	{"issuerName", "Lsun/security/x509/X500Name;", nullptr, 0, $field(SignerInfo, issuerName)},
	{"certificateSerialNumber", "Ljava/math/BigInteger;", nullptr, 0, $field(SignerInfo, certificateSerialNumber)},
	{"digestAlgorithmId", "Lsun/security/x509/AlgorithmId;", nullptr, 0, $field(SignerInfo, digestAlgorithmId)},
	{"digestEncryptionAlgorithmId", "Lsun/security/x509/AlgorithmId;", nullptr, 0, $field(SignerInfo, digestEncryptionAlgorithmId)},
	{"encryptedDigest", "[B", nullptr, 0, $field(SignerInfo, encryptedDigest)},
	{"timestamp", "Ljava/security/Timestamp;", nullptr, 0, $field(SignerInfo, timestamp)},
	{"hasTimestamp", "Z", nullptr, $PRIVATE, $field(SignerInfo, hasTimestamp)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SignerInfo, debug)},
	{"authenticatedAttributes", "Lsun/security/pkcs/PKCS9Attributes;", nullptr, 0, $field(SignerInfo, authenticatedAttributes)},
	{"unauthenticatedAttributes", "Lsun/security/pkcs/PKCS9Attributes;", nullptr, 0, $field(SignerInfo, unauthenticatedAttributes)},
	{"algorithms", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/x509/AlgorithmId;Ljava/lang/String;>;", $PRIVATE, $field(SignerInfo, algorithms)},
	{}
};

$MethodInfo _SignerInfo_MethodInfo_[] = {
	{"<init>", "(Lsun/security/x509/X500Name;Ljava/math/BigInteger;Lsun/security/x509/AlgorithmId;Lsun/security/x509/AlgorithmId;[B)V", nullptr, $PUBLIC, $method(SignerInfo, init$, void, $X500Name*, $BigInteger*, $AlgorithmId*, $AlgorithmId*, $bytes*)},
	{"<init>", "(Lsun/security/x509/X500Name;Ljava/math/BigInteger;Lsun/security/x509/AlgorithmId;Lsun/security/pkcs/PKCS9Attributes;Lsun/security/x509/AlgorithmId;[BLsun/security/pkcs/PKCS9Attributes;)V", nullptr, $PUBLIC, $method(SignerInfo, init$, void, $X500Name*, $BigInteger*, $AlgorithmId*, $PKCS9Attributes*, $AlgorithmId*, $bytes*, $PKCS9Attributes*)},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(SignerInfo, init$, void, $DerInputStream*), "java.io.IOException,sun.security.pkcs.ParsingException"},
	{"<init>", "(Lsun/security/util/DerInputStream;Z)V", nullptr, $PUBLIC, $method(SignerInfo, init$, void, $DerInputStream*, bool), "java.io.IOException,sun.security.pkcs.ParsingException"},
	{"checkCMSAlgorithmProtection", "()V", nullptr, $PRIVATE, $method(SignerInfo, checkCMSAlgorithmProtection, void), "java.io.IOException"},
	{"derEncode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(SignerInfo, derEncode, void, $OutputStream*), "java.io.IOException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(SignerInfo, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"getAuthenticatedAttributes", "()Lsun/security/pkcs/PKCS9Attributes;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getAuthenticatedAttributes, $PKCS9Attributes*)},
	{"getCertificate", "(Lsun/security/pkcs/PKCS7;)Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getCertificate, $X509Certificate*, $PKCS7*), "java.io.IOException"},
	{"getCertificateChain", "(Lsun/security/pkcs/PKCS7;)Ljava/util/ArrayList;", "(Lsun/security/pkcs/PKCS7;)Ljava/util/ArrayList<Ljava/security/cert/X509Certificate;>;", $PUBLIC, $virtualMethod(SignerInfo, getCertificateChain, $ArrayList*, $PKCS7*), "java.io.IOException"},
	{"getCertificateSerialNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getCertificateSerialNumber, $BigInteger*)},
	{"getDigestAlgorithmId", "()Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getDigestAlgorithmId, $AlgorithmId*)},
	{"getDigestEncryptionAlgorithmId", "()Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getDigestEncryptionAlgorithmId, $AlgorithmId*)},
	{"getEncryptedDigest", "()[B", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getEncryptedDigest, $bytes*)},
	{"getIssuerName", "()Lsun/security/x509/X500Name;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getIssuerName, $X500Name*)},
	{"getTimestamp", "()Ljava/security/Timestamp;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getTimestamp, $Timestamp*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.SignatureException,java.security.cert.CertificateException"},
	{"getTsToken", "()Lsun/security/pkcs/PKCS7;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getTsToken, $PKCS7*), "java.io.IOException"},
	{"getUnauthenticatedAttributes", "()Lsun/security/pkcs/PKCS9Attributes;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getUnauthenticatedAttributes, $PKCS9Attributes*)},
	{"getVersion", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, getVersion, $BigInteger*)},
	{"makeSigAlg", "(Lsun/security/x509/AlgorithmId;Lsun/security/x509/AlgorithmId;Z)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignerInfo, makeSigAlg, $String*, $AlgorithmId*, $AlgorithmId*, bool), "java.security.NoSuchAlgorithmException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SignerInfo, toString, $String*)},
	{"verify", "(Lsun/security/pkcs/PKCS7;[B)Lsun/security/pkcs/SignerInfo;", nullptr, 0, $virtualMethod(SignerInfo, verify, SignerInfo*, $PKCS7*, $bytes*), "java.security.NoSuchAlgorithmException,java.security.SignatureException"},
	{"verify", "(Lsun/security/pkcs/PKCS7;)Lsun/security/pkcs/SignerInfo;", nullptr, 0, $virtualMethod(SignerInfo, verify, SignerInfo*, $PKCS7*), "java.security.NoSuchAlgorithmException,java.security.SignatureException"},
	{"verifyAlgorithms", "([Lsun/security/pkcs/SignerInfo;Lsun/security/util/JarConstraintsParameters;Ljava/lang/String;)Ljava/util/Set;", "([Lsun/security/pkcs/SignerInfo;Lsun/security/util/JarConstraintsParameters;Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(SignerInfo, verifyAlgorithms, $Set*, $SignerInfoArray*, $JarConstraintsParameters*, $String*), "java.security.SignatureException"},
	{"verifyTimestamp", "(Lsun/security/timestamp/TimestampToken;)V", nullptr, $PRIVATE, $method(SignerInfo, verifyTimestamp, void, $TimestampToken*), "java.security.NoSuchAlgorithmException,java.security.SignatureException"},
	{}
};

$ClassInfo _SignerInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.pkcs.SignerInfo",
	"java.lang.Object",
	"sun.security.util.DerEncoder",
	_SignerInfo_FieldInfo_,
	_SignerInfo_MethodInfo_
};

$Object* allocate$SignerInfo($Class* clazz) {
	return $of($alloc(SignerInfo));
}

$DisabledAlgorithmConstraints* SignerInfo::JAR_DISABLED_CHECK = nullptr;
$Debug* SignerInfo::debug = nullptr;

void SignerInfo::init$($X500Name* issuerName, $BigInteger* serial, $AlgorithmId* digestAlgorithmId, $AlgorithmId* digestEncryptionAlgorithmId, $bytes* encryptedDigest) {
	SignerInfo::init$(issuerName, serial, digestAlgorithmId, nullptr, digestEncryptionAlgorithmId, encryptedDigest, nullptr);
}

void SignerInfo::init$($X500Name* issuerName, $BigInteger* serial, $AlgorithmId* digestAlgorithmId, $PKCS9Attributes* authenticatedAttributes, $AlgorithmId* digestEncryptionAlgorithmId, $bytes* encryptedDigest, $PKCS9Attributes* unauthenticatedAttributes) {
	this->hasTimestamp = true;
	$set(this, algorithms, $new($HashMap));
	$init($BigInteger);
	$set(this, version, $BigInteger::ONE);
	$set(this, issuerName, issuerName);
	$set(this, certificateSerialNumber, serial);
	$set(this, digestAlgorithmId, digestAlgorithmId);
	$set(this, authenticatedAttributes, authenticatedAttributes);
	$set(this, digestEncryptionAlgorithmId, digestEncryptionAlgorithmId);
	$set(this, encryptedDigest, encryptedDigest);
	$set(this, unauthenticatedAttributes, unauthenticatedAttributes);
}

void SignerInfo::init$($DerInputStream* derin) {
	SignerInfo::init$(derin, false);
}

void SignerInfo::init$($DerInputStream* derin, bool oldStyle) {
	$useLocalCurrentObjectStackCache();
	this->hasTimestamp = true;
	$set(this, algorithms, $new($HashMap));
	$set(this, version, $nc(derin)->getBigInteger());
	$var($DerValueArray, issuerAndSerialNumber, derin->getSequence(2));
	if ($nc(issuerAndSerialNumber)->length != 2) {
		$throwNew($ParsingException, "Invalid length for IssuerAndSerialNumber"_s);
	}
	$var($bytes, issuerBytes, $nc($nc(issuerAndSerialNumber)->get(0))->toByteArray());
	$set(this, issuerName, $new($X500Name, $$new($DerValue, $DerValue::tag_Sequence, issuerBytes)));
	$set(this, certificateSerialNumber, $nc(issuerAndSerialNumber->get(1))->getBigInteger());
	$var($DerValue, tmp, derin->getDerValue());
	$set(this, digestAlgorithmId, $AlgorithmId::parse(tmp));
	if (oldStyle) {
		derin->getSet(0);
	} else if ((int8_t)(derin->peekByte()) == (int8_t)160) {
		$set(this, authenticatedAttributes, $new($PKCS9Attributes, derin));
	}
	$assign(tmp, derin->getDerValue());
	$set(this, digestEncryptionAlgorithmId, $AlgorithmId::parse(tmp));
	$set(this, encryptedDigest, derin->getOctetString());
	if (oldStyle) {
		derin->getSet(0);
	} else {
		bool var$1 = derin->available() != 0;
		if (var$1 && (int8_t)(derin->peekByte()) == (int8_t)161) {
			$set(this, unauthenticatedAttributes, $new($PKCS9Attributes, derin, true));
		}
	}
	if (derin->available() != 0) {
		$throwNew($ParsingException, "extra data at the end"_s);
	}
	checkCMSAlgorithmProtection();
}

void SignerInfo::checkCMSAlgorithmProtection() {
	$useLocalCurrentObjectStackCache();
	if (this->authenticatedAttributes == nullptr) {
		return;
	}
	$init($PKCS9Attribute);
	$var($PKCS9Attribute, ap, $nc(this->authenticatedAttributes)->getAttribute($PKCS9Attribute::CMS_ALGORITHM_PROTECTION_OID));
	if (ap == nullptr) {
		return;
	}
	$var($DerValue, dv, $new($DerValue, $cast($bytes, $($nc(ap)->getValue()))));
	$var($DerInputStream, data, dv->data());
	$var($AlgorithmId, d, $AlgorithmId::parse($($nc(data)->getDerValue())));
	$var($DerValue, ds, $nc(data)->getDerValue());
	if (data->available() > 0) {
		$throwNew($IOException, "Unknown field in CMSAlgorithmProtection"_s);
	}
	if (!$nc(ds)->isContextSpecific((int8_t)1)) {
		$throwNew($IOException, "No signature algorithm in CMSAlgorithmProtection"_s);
	}
	$var($AlgorithmId, s, $AlgorithmId::parse($($nc(ds)->withTag($DerValue::tag_Sequence))));
	bool var$0 = !$nc(s)->equals(this->digestEncryptionAlgorithmId);
	if (var$0 || !$nc(d)->equals(this->digestAlgorithmId)) {
		$throwNew($IOException, "CMSAlgorithmProtection check failed"_s);
	}
}

void SignerInfo::encode($DerOutputStream* out) {
	derEncode(out);
}

void SignerInfo::derEncode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, seq, $new($DerOutputStream));
	seq->putInteger(this->version);
	$var($DerOutputStream, issuerAndSerialNumber, $new($DerOutputStream));
	$nc(this->issuerName)->encode(issuerAndSerialNumber);
	issuerAndSerialNumber->putInteger(this->certificateSerialNumber);
	seq->write($DerValue::tag_Sequence, issuerAndSerialNumber);
	$nc(this->digestAlgorithmId)->encode(seq);
	if (this->authenticatedAttributes != nullptr) {
		$nc(this->authenticatedAttributes)->encode((int8_t)160, seq);
	}
	$nc(this->digestEncryptionAlgorithmId)->encode(seq);
	seq->putOctetString(this->encryptedDigest);
	if (this->unauthenticatedAttributes != nullptr) {
		$nc(this->unauthenticatedAttributes)->encode((int8_t)161, seq);
	}
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	tmp->write($DerValue::tag_Sequence, seq);
	$nc(out)->write($(tmp->toByteArray()));
}

$X509Certificate* SignerInfo::getCertificate($PKCS7* block) {
	return $nc(block)->getCertificate(this->certificateSerialNumber, this->issuerName);
}

$ArrayList* SignerInfo::getCertificateChain($PKCS7* block) {
	$useLocalCurrentObjectStackCache();
	$var($X509Certificate, userCert, nullptr);
	$assign(userCert, $nc(block)->getCertificate(this->certificateSerialNumber, this->issuerName));
	if (userCert == nullptr) {
		return nullptr;
	}
	$var($ArrayList, certList, $new($ArrayList));
	certList->add(userCert);
	$var($X509CertificateArray, pkcsCerts, block->getCertificates());
	if (pkcsCerts == nullptr || $nc($($nc(userCert)->getSubjectX500Principal()))->equals($(userCert->getIssuerX500Principal()))) {
		return certList;
	}
	$var($Principal, issuer, $nc(userCert)->getIssuerX500Principal());
	int32_t start = 0;
	while (true) {
		bool match = false;
		int32_t i = start;
		while (i < $nc(pkcsCerts)->length) {
			if ($nc(issuer)->equals($($nc(pkcsCerts->get(i))->getSubjectX500Principal()))) {
				certList->add(pkcsCerts->get(i));
				if ($nc($($nc(pkcsCerts->get(i))->getSubjectX500Principal()))->equals($($nc(pkcsCerts->get(i))->getIssuerX500Principal()))) {
					start = pkcsCerts->length;
				} else {
					$assign(issuer, $nc(pkcsCerts->get(i))->getIssuerX500Principal());
					$var($X509Certificate, tmpCert, pkcsCerts->get(start));
					pkcsCerts->set(start, pkcsCerts->get(i));
					pkcsCerts->set(i, tmpCert);
					++start;
				}
				match = true;
				break;
			} else {
				++i;
			}
		}
		if (!match) {
			break;
		}
	}
	return certList;
}

SignerInfo* SignerInfo::verify($PKCS7* block, $bytes* data$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, data, data$renamed);
	try {
		$var($Timestamp, timestamp, nullptr);
		try {
			$assign(timestamp, getTimestamp());
		} catch ($Exception& e) {
			if (SignerInfo::debug != nullptr) {
				$nc(SignerInfo::debug)->println($$str({"Unexpected exception while getting timestamp: "_s, e}));
			}
		}
		$var($ContentInfo, content, $nc(block)->getContentInfo());
		if (data == nullptr) {
			$assign(data, $nc(content)->getContentBytes());
		}
		$var($String, digestAlgName, $nc(this->digestAlgorithmId)->getName());
		$nc(this->algorithms)->put(this->digestAlgorithmId, "SignerInfo digestAlgorithm field"_s);
		$var($bytes, dataSigned, nullptr);
		if (this->authenticatedAttributes == nullptr) {
			$assign(dataSigned, data);
		} else {
			$init($PKCS9Attribute);
			$var($ObjectIdentifier, contentType, $cast($ObjectIdentifier, $nc(this->authenticatedAttributes)->getAttributeValue($PKCS9Attribute::CONTENT_TYPE_OID)));
			if (contentType == nullptr || !$nc(contentType)->equals($nc(content)->contentType)) {
				return nullptr;
			}
			$var($bytes, messageDigest, $cast($bytes, $nc(this->authenticatedAttributes)->getAttributeValue($PKCS9Attribute::MESSAGE_DIGEST_OID)));
			if (messageDigest == nullptr) {
				return nullptr;
			}
			$var($bytes, computedMessageDigest, nullptr);
			bool var$0 = $nc(digestAlgName)->equals("SHAKE256"_s);
			if (var$0 || $nc(digestAlgName)->equals("SHAKE256-LEN"_s)) {
				if (digestAlgName->equals("SHAKE256-LEN"_s)) {
					int32_t v = $$new($DerValue, $($nc(this->digestAlgorithmId)->getEncodedParams()))->getInteger();
					if (v != 512) {
						$throwNew($SignatureException, $$str({"Unsupported id-shake256-"_s, $$str(v)}));
					}
				}
				$var($SHAKE256, md, $new($SHAKE256, 64));
				md->update(data, 0, $nc(data)->length);
				$assign(computedMessageDigest, md->digest());
			} else {
				$var($MessageDigest, md, $MessageDigest::getInstance(digestAlgName));
				$assign(computedMessageDigest, $nc(md)->digest(data));
			}
			if (!$MessageDigest::isEqual(messageDigest, computedMessageDigest)) {
				return nullptr;
			}
			$assign(dataSigned, $nc(this->authenticatedAttributes)->getDerEncoding());
		}
		$var($String, sigAlgName, makeSigAlg(this->digestAlgorithmId, this->digestEncryptionAlgorithmId, this->authenticatedAttributes == nullptr));
		$KnownOIDs* oid = $KnownOIDs::findMatch(sigAlgName);
		if (oid != nullptr) {
			$var($ObjectIdentifier, var$1, $ObjectIdentifier::of(oid));
			$var($AlgorithmId, sigAlgId, $new($AlgorithmId, var$1, $($nc(this->digestEncryptionAlgorithmId)->getParameters())));
			$nc(this->algorithms)->put(sigAlgId, "SignerInfo digestEncryptionAlgorithm field"_s);
		}
		$var($X509Certificate, cert, getCertificate(block));
		if (cert == nullptr) {
			return nullptr;
		}
		$var($PublicKey, key, $nc(cert)->getPublicKey());
		if (cert->hasUnsupportedCriticalExtension()) {
			$throwNew($SignatureException, "Certificate has unsupported critical extension(s)"_s);
		}
		$var($booleans, keyUsageBits, cert->getKeyUsage());
		if (keyUsageBits != nullptr) {
			$var($KeyUsageExtension, keyUsage, nullptr);
			try {
				$assign(keyUsage, $new($KeyUsageExtension, keyUsageBits));
			} catch ($IOException& ioe) {
				$throwNew($SignatureException, "Failed to parse keyUsage extension"_s);
			}
			$init($KeyUsageExtension);
			bool digSigAllowed = $nc($($cast($Boolean, $nc(keyUsage)->get($KeyUsageExtension::DIGITAL_SIGNATURE))))->booleanValue();
			bool nonRepuAllowed = $nc($($cast($Boolean, keyUsage->get($KeyUsageExtension::NON_REPUDIATION))))->booleanValue();
			if (!digSigAllowed && !nonRepuAllowed) {
				$throwNew($SignatureException, "Key usage restricted: cannot be used for digital signatures"_s);
			}
		}
		$var($Signature, sig, $Signature::getInstance(sigAlgName));
		$var($AlgorithmParameters, ap, $nc(this->digestEncryptionAlgorithmId)->getParameters());
		try {
			$SignatureUtil::initVerifyWithParam(sig, key, $($SignatureUtil::getParamSpec(sigAlgName, ap)));
		} catch ($ProviderException& e) {
			$throwNew($SignatureException, $(e->getMessage()), e);
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($SignatureException, $(e->getMessage()), e);
		} catch ($InvalidKeyException& e) {
			$throwNew($SignatureException, $(e->getMessage()), e);
		}
		$nc(sig)->update(dataSigned);
		if (sig->verify(this->encryptedDigest)) {
			return this;
		}
	} catch ($IOException& e) {
		$throwNew($SignatureException, "Error verifying signature"_s, e);
	}
	return nullptr;
}

$String* SignerInfo::makeSigAlg($AlgorithmId* digAlgId, $AlgorithmId* encAlgId, bool directSign) {
	$init(SignerInfo);
	$useLocalCurrentObjectStackCache();
	$var($String, encAlg, $nc(encAlgId)->getName());
	{
		$var($String, s20057$, encAlg);
		int32_t tmp20057$ = -1;
		switch ($nc(s20057$)->hashCode()) {
		case 0x69D3B2A4:
			{
				if (s20057$->equals("RSASSA-PSS"_s)) {
					tmp20057$ = 0;
				}
				break;
			}
		case (int32_t)0xEF8C129B:
			{
				if (s20057$->equals("Ed25519"_s)) {
					tmp20057$ = 1;
				}
				break;
			}
		case 0x03FA9499:
			{
				if (s20057$->equals("Ed448"_s)) {
					tmp20057$ = 2;
				}
				break;
			}
		}
		{
			$var($PSSParameterSpec, spec, nullptr)
			$var($String, digAlg, nullptr)
			$var($String, keyAlg, nullptr)
			switch (tmp20057$) {
			case 0:
				{
					$assign(spec, $cast($PSSParameterSpec, $SignatureUtil::getParamSpec(encAlg, $(encAlgId->getParameters()))));
					if (!$nc($($AlgorithmId::get($($nc(spec)->getDigestAlgorithm()))))->equals(digAlgId)) {
						$throwNew($NoSuchAlgorithmException, "Incompatible digest algorithm"_s);
					}
					return encAlg;
				}
			case 1:
				{
					$init($SignatureUtil$EdDSADigestAlgHolder);
					if (!$nc(digAlgId)->equals($SignatureUtil$EdDSADigestAlgHolder::sha512)) {
						$throwNew($NoSuchAlgorithmException, "Incompatible digest algorithm"_s);
					}
					return encAlg;
				}
			case 2:
				{
					if (directSign) {
						$init($SignatureUtil$EdDSADigestAlgHolder);
						if (!$nc(digAlgId)->equals($SignatureUtil$EdDSADigestAlgHolder::shake256)) {
							$throwNew($NoSuchAlgorithmException, "Incompatible digest algorithm"_s);
						}
					} else {
						$init($SignatureUtil$EdDSADigestAlgHolder);
						if (!$nc(digAlgId)->equals($SignatureUtil$EdDSADigestAlgHolder::shake256$512)) {
							$throwNew($NoSuchAlgorithmException, "Incompatible digest algorithm"_s);
						}
					}
					return encAlg;
				}
			default:
				{
					$assign(digAlg, $nc(digAlgId)->getName());
					$assign(keyAlg, $SignatureUtil::extractKeyAlgFromDwithE(encAlg));
					if (keyAlg == nullptr) {
						$assign(keyAlg, encAlg);
					}
					if ($nc(digAlg)->startsWith("SHA-"_s)) {
						$assign(digAlg, $str({"SHA"_s, $(digAlg->substring(4))}));
					}
					if ($nc(keyAlg)->equals("EC"_s)) {
						$assign(keyAlg, "ECDSA"_s);
					}
					return $str({digAlg, "with"_s, keyAlg});
				}
			}
		}
	}
}

SignerInfo* SignerInfo::verify($PKCS7* block) {
	return verify(block, nullptr);
}

$BigInteger* SignerInfo::getVersion() {
	return this->version;
}

$X500Name* SignerInfo::getIssuerName() {
	return this->issuerName;
}

$BigInteger* SignerInfo::getCertificateSerialNumber() {
	return this->certificateSerialNumber;
}

$AlgorithmId* SignerInfo::getDigestAlgorithmId() {
	return this->digestAlgorithmId;
}

$PKCS9Attributes* SignerInfo::getAuthenticatedAttributes() {
	return this->authenticatedAttributes;
}

$AlgorithmId* SignerInfo::getDigestEncryptionAlgorithmId() {
	return this->digestEncryptionAlgorithmId;
}

$bytes* SignerInfo::getEncryptedDigest() {
	return this->encryptedDigest;
}

$PKCS9Attributes* SignerInfo::getUnauthenticatedAttributes() {
	return this->unauthenticatedAttributes;
}

$PKCS7* SignerInfo::getTsToken() {
	$useLocalCurrentObjectStackCache();
	if (this->unauthenticatedAttributes == nullptr) {
		return nullptr;
	}
	$init($PKCS9Attribute);
	$var($PKCS9Attribute, tsTokenAttr, $nc(this->unauthenticatedAttributes)->getAttribute($PKCS9Attribute::SIGNATURE_TIMESTAMP_TOKEN_OID));
	if (tsTokenAttr == nullptr) {
		return nullptr;
	}
	return $new($PKCS7, $cast($bytes, $($nc(tsTokenAttr)->getValue())));
}

$Timestamp* SignerInfo::getTimestamp() {
	$useLocalCurrentObjectStackCache();
	if (this->timestamp != nullptr || !this->hasTimestamp) {
		return this->timestamp;
	}
	$var($PKCS7, tsToken, getTsToken());
	if (tsToken == nullptr) {
		this->hasTimestamp = false;
		return nullptr;
	}
	$var($bytes, encTsTokenInfo, $nc($($nc(tsToken)->getContentInfo()))->getData());
	$var($SignerInfoArray, tsa, tsToken->verify(encTsTokenInfo));
	if (tsa == nullptr || $nc(tsa)->length == 0) {
		$throwNew($SignatureException, "Unable to verify timestamp"_s);
	}
	$var($ArrayList, chain, $nc($nc(tsa)->get(0))->getCertificateChain(tsToken));
	$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
	$var($CertPath, tsaChain, $nc(cf)->generateCertPath(static_cast<$List*>(chain)));
	$var($TimestampToken, tsTokenInfo, $new($TimestampToken, encTsTokenInfo));
	verifyTimestamp(tsTokenInfo);
	$nc(this->algorithms)->putAll($nc(tsa->get(0))->algorithms);
	$set(this, timestamp, $new($Timestamp, $(tsTokenInfo->getDate()), tsaChain));
	return this->timestamp;
}

void SignerInfo::verifyTimestamp($TimestampToken* token) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmId, digestAlgId, $nc(token)->getHashAlgorithm());
	$nc(this->algorithms)->put(digestAlgId, "TimestampToken digestAlgorithm field"_s);
	$var($MessageDigest, md, $MessageDigest::getInstance($($nc(digestAlgId)->getName())));
	$var($bytes, var$0, token->getHashedMessage());
	if (!$MessageDigest::isEqual(var$0, $($nc(md)->digest(this->encryptedDigest)))) {
		$var($String, var$2, $$str({"Signature timestamp (#"_s, $(token->getSerialNumber()), ") generated on "_s}));
		$var($String, var$1, $$concat(var$2, $(token->getDate())));
		$throwNew($SignatureException, $$concat(var$1, " is inapplicable"_s));
	}
	if (SignerInfo::debug != nullptr) {
		$nc(SignerInfo::debug)->println();
		$var($String, var$3, $$str({"Detected signature timestamp (#"_s, $(token->getSerialNumber()), ") generated on "_s}));
		$nc(SignerInfo::debug)->println($$concat(var$3, $(token->getDate())));
		$nc(SignerInfo::debug)->println();
	}
}

$String* SignerInfo::toString() {
	$useLocalCurrentObjectStackCache();
	$var($HexDumpEncoder, hexDump, $new($HexDumpEncoder));
	$var($String, out, ""_s);
	$plusAssign(out, $$str({"Signer Info for (issuer): "_s, this->issuerName, "\n"_s}));
	$plusAssign(out, $$str({"\tversion: "_s, $($Debug::toHexString(this->version)), "\n"_s}));
	$plusAssign(out, $$str({"\tcertificateSerialNumber: "_s, $($Debug::toHexString(this->certificateSerialNumber)), "\n"_s}));
	$plusAssign(out, $$str({"\tdigestAlgorithmId: "_s, this->digestAlgorithmId, "\n"_s}));
	if (this->authenticatedAttributes != nullptr) {
		$plusAssign(out, $$str({"\tauthenticatedAttributes: "_s, this->authenticatedAttributes, "\n"_s}));
	}
	$plusAssign(out, $$str({"\tdigestEncryptionAlgorithmId: "_s, this->digestEncryptionAlgorithmId, "\n"_s}));
	$plusAssign(out, $$str({"\tencryptedDigest: \n"_s, $(hexDump->encodeBuffer(this->encryptedDigest)), "\n"_s}));
	if (this->unauthenticatedAttributes != nullptr) {
		$plusAssign(out, $$str({"\tunauthenticatedAttributes: "_s, this->unauthenticatedAttributes, "\n"_s}));
	}
	return out;
}

$Set* SignerInfo::verifyAlgorithms($SignerInfoArray* infos, $JarConstraintsParameters* params, $String* name) {
	$init(SignerInfo);
	$useLocalCurrentObjectStackCache();
	$var($Map, algorithms, $new($HashMap));
	{
		$var($SignerInfoArray, arr$, infos);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var(SignerInfo, info, arr$->get(i$));
			{
				algorithms->putAll($nc(info)->algorithms);
			}
		}
	}
	$var($Set, enabledAlgorithms, $new($HashSet));
	try {
		{
			$var($Iterator, i$, $nc($(algorithms->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, algorithm, $cast($Map$Entry, i$->next()));
				{
					$nc(params)->setExtendedExceptionMsg(name, $cast($String, $($nc(algorithm)->getValue())));
					$var($AlgorithmId, algId, $cast($AlgorithmId, $nc(algorithm)->getKey()));
					$var($String, var$0, $nc(algId)->getName());
					$nc(SignerInfo::JAR_DISABLED_CHECK)->permits(var$0, $(algId->getParameters()), static_cast<$ConstraintsParameters*>(params));
					enabledAlgorithms->add($($nc(algId)->getName()));
				}
			}
		}
	} catch ($CertPathValidatorException& e) {
		$throwNew($SignatureException, static_cast<$Throwable*>(e));
	}
	return enabledAlgorithms;
}

void clinit$SignerInfo($Class* class$) {
	$assignStatic(SignerInfo::JAR_DISABLED_CHECK, $DisabledAlgorithmConstraints::jarConstraints());
	$assignStatic(SignerInfo::debug, $Debug::getInstance("jar"_s));
}

SignerInfo::SignerInfo() {
}

$Class* SignerInfo::load$($String* name, bool initialize) {
	$loadClass(SignerInfo, name, initialize, &_SignerInfo_ClassInfo_, clinit$SignerInfo, allocate$SignerInfo);
	return class$;
}

$Class* SignerInfo::class$ = nullptr;

		} // pkcs
	} // security
} // sun