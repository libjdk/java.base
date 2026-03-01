#include <sun/security/provider/certpath/CertId.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/Arrays.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/SerialNumber.h>
#include <jcpp.h>

#undef SHA1_ALGID

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PublicKey = ::java::security::PublicKey;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Arrays = ::java::util::Arrays;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $SerialNumber = ::sun::security::x509::SerialNumber;

namespace sun {
	namespace security {
		namespace provider {
			namespace certpath {

$FieldInfo _CertId_FieldInfo_[] = {
	{"debug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CertId, debug)},
	{"SHA1_ALGID", "Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CertId, SHA1_ALGID)},
	{"hashAlgId", "Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE | $FINAL, $field(CertId, hashAlgId)},
	{"issuerNameHash", "[B", nullptr, $PRIVATE | $FINAL, $field(CertId, issuerNameHash)},
	{"issuerKeyHash", "[B", nullptr, $PRIVATE | $FINAL, $field(CertId, issuerKeyHash)},
	{"certSerialNumber", "Lsun/security/x509/SerialNumber;", nullptr, $PRIVATE | $FINAL, $field(CertId, certSerialNumber)},
	{"myhash", "I", nullptr, $PRIVATE, $field(CertId, myhash)},
	{}
};

$MethodInfo _CertId_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/X509Certificate;Lsun/security/x509/SerialNumber;)V", nullptr, $PUBLIC, $method(CertId, init$, void, $X509Certificate*, $SerialNumber*), "java.io.IOException"},
	{"<init>", "(Ljavax/security/auth/x500/X500Principal;Ljava/security/PublicKey;Lsun/security/x509/SerialNumber;)V", nullptr, $PUBLIC, $method(CertId, init$, void, $X500Principal*, $PublicKey*, $SerialNumber*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(CertId, init$, void, $DerInputStream*), "java.io.IOException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(CertId, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CertId, equals, bool, Object$*)},
	{"getHashAlgorithm", "()Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC, $virtualMethod(CertId, getHashAlgorithm, $AlgorithmId*)},
	{"getIssuerKeyHash", "()[B", nullptr, $PUBLIC, $virtualMethod(CertId, getIssuerKeyHash, $bytes*)},
	{"getIssuerNameHash", "()[B", nullptr, $PUBLIC, $virtualMethod(CertId, getIssuerNameHash, $bytes*)},
	{"getSerialNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(CertId, getSerialNumber, $BigInteger*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CertId, hashCode, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertId, toString, $String*)},
	{}
};

$ClassInfo _CertId_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.certpath.CertId",
	"java.lang.Object",
	nullptr,
	_CertId_FieldInfo_,
	_CertId_MethodInfo_
};

$Object* allocate$CertId($Class* clazz) {
	return $of($alloc(CertId));
}

$AlgorithmId* CertId::SHA1_ALGID = nullptr;

void CertId::init$($X509Certificate* issuerCert, $SerialNumber* serialNumber) {
	$useLocalCurrentObjectStackCache();
	$var($X500Principal, var$0, $nc(issuerCert)->getSubjectX500Principal());
	CertId::init$(var$0, $(issuerCert->getPublicKey()), serialNumber);
}

void CertId::init$($X500Principal* issuerName, $PublicKey* issuerKey, $SerialNumber* serialNumber) {
	$useLocalCurrentObjectStackCache();
	this->myhash = -1;
	$var($MessageDigest, md, nullptr);
	try {
		$assign(md, $MessageDigest::getInstance("SHA1"_s));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($IOException, "Unable to create CertId"_s, nsae);
	}
	$set(this, hashAlgId, CertId::SHA1_ALGID);
	$nc(md)->update($($nc(issuerName)->getEncoded()));
	$set(this, issuerNameHash, md->digest());
	$var($bytes, pubKey, $nc(issuerKey)->getEncoded());
	$var($DerValue, val, $new($DerValue, pubKey));
	$var($DerValueArray, seq, $new($DerValueArray, 2));
	seq->set(0, $($nc(val->data$)->getDerValue()));
	seq->set(1, $($nc(val->data$)->getDerValue()));
	$var($bytes, keyBytes, $nc(seq->get(1))->getBitString());
	md->update(keyBytes);
	$set(this, issuerKeyHash, md->digest());
	$set(this, certSerialNumber, serialNumber);
}

void CertId::init$($DerInputStream* derIn) {
	this->myhash = -1;
	$set(this, hashAlgId, $AlgorithmId::parse($($nc(derIn)->getDerValue())));
	$set(this, issuerNameHash, $nc(derIn)->getOctetString());
	$set(this, issuerKeyHash, derIn->getOctetString());
	$set(this, certSerialNumber, $new($SerialNumber, derIn));
}

$AlgorithmId* CertId::getHashAlgorithm() {
	return this->hashAlgId;
}

$bytes* CertId::getIssuerNameHash() {
	return this->issuerNameHash;
}

$bytes* CertId::getIssuerKeyHash() {
	return this->issuerKeyHash;
}

$BigInteger* CertId::getSerialNumber() {
	return $nc(this->certSerialNumber)->getNumber();
}

void CertId::encode($DerOutputStream* out) {
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$nc(this->hashAlgId)->encode(tmp);
	tmp->putOctetString(this->issuerNameHash);
	tmp->putOctetString(this->issuerKeyHash);
	$nc(this->certSerialNumber)->encode(tmp);
	$nc(out)->write($DerValue::tag_Sequence, tmp);
}

int32_t CertId::hashCode() {
	if (this->myhash == -1) {
		this->myhash = $nc(this->hashAlgId)->hashCode();
		for (int32_t i = 0; i < $nc(this->issuerNameHash)->length; ++i) {
			this->myhash += $nc(this->issuerNameHash)->get(i) * i;
		}
		for (int32_t i = 0; i < $nc(this->issuerKeyHash)->length; ++i) {
			this->myhash += $nc(this->issuerKeyHash)->get(i) * i;
		}
		this->myhash += $nc($($nc(this->certSerialNumber)->getNumber()))->hashCode();
	}
	return this->myhash;
}

bool CertId::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other)) {
		return true;
	}
	if (other == nullptr || (!($instanceOf(CertId, other)))) {
		return false;
	}
	$var(CertId, that, $cast(CertId, other));
	bool var$2 = $nc(this->hashAlgId)->equals($($nc(that)->getHashAlgorithm()));
	bool var$1 = var$2 && $Arrays::equals(this->issuerNameHash, $($nc(that)->getIssuerNameHash()));
	bool var$0 = var$1 && $Arrays::equals(this->issuerKeyHash, $($nc(that)->getIssuerKeyHash()));
	if (var$0 && $nc($($nc(this->certSerialNumber)->getNumber()))->equals($($nc(that)->getSerialNumber()))) {
		return true;
	} else {
		return false;
	}
}

$String* CertId::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("CertId \n"_s);
	sb->append($$str({"Algorithm: "_s, $($nc(this->hashAlgId)->toString()), "\n"_s}));
	sb->append("issuerNameHash \n"_s);
	$var($HexDumpEncoder, encoder, $new($HexDumpEncoder));
	sb->append($(encoder->encode(this->issuerNameHash)));
	sb->append("\nissuerKeyHash: \n"_s);
	sb->append($(encoder->encode(this->issuerKeyHash)));
	sb->append($$str({"\n"_s, $($nc(this->certSerialNumber)->toString())}));
	return sb->toString();
}

void clinit$CertId($Class* class$) {
	$init($AlgorithmId);
	$assignStatic(CertId::SHA1_ALGID, $new($AlgorithmId, $AlgorithmId::SHA_oid));
}

CertId::CertId() {
}

$Class* CertId::load$($String* name, bool initialize) {
	$loadClass(CertId, name, initialize, &_CertId_ClassInfo_, clinit$CertId, allocate$CertId);
	return class$;
}

$Class* CertId::class$ = nullptr;

			} // certpath
		} // provider
	} // security
} // sun