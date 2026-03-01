#include <sun/security/pkcs10/PKCS10.h>

#include <java/io/OutputStream.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/Signature.h>
#include <java/security/SignatureException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <sun/security/pkcs10/PKCS10Attributes.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509Key.h>
#include <jcpp.h>

#undef CRLF
#undef PKCS10
#undef ZERO

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $Signature = ::java::security::Signature;
using $SignatureException = ::java::security::SignatureException;
using $Arrays = ::java::util::Arrays;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $PKCS10Attributes = ::sun::security::pkcs10::PKCS10Attributes;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $X500Name = ::sun::security::x509::X500Name;
using $X509Key = ::sun::security::x509::X509Key;

namespace sun {
	namespace security {
		namespace pkcs10 {

$FieldInfo _PKCS10_FieldInfo_[] = {
	{"subject", "Lsun/security/x509/X500Name;", nullptr, $PRIVATE, $field(PKCS10, subject)},
	{"subjectPublicKeyInfo", "Ljava/security/PublicKey;", nullptr, $PRIVATE, $field(PKCS10, subjectPublicKeyInfo)},
	{"sigAlg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS10, sigAlg)},
	{"attributeSet", "Lsun/security/pkcs10/PKCS10Attributes;", nullptr, $PRIVATE, $field(PKCS10, attributeSet)},
	{"encoded", "[B", nullptr, $PRIVATE, $field(PKCS10, encoded)},
	{}
};

$MethodInfo _PKCS10_MethodInfo_[] = {
	{"<init>", "(Ljava/security/PublicKey;)V", nullptr, $PUBLIC, $method(PKCS10, init$, void, $PublicKey*)},
	{"<init>", "(Ljava/security/PublicKey;Lsun/security/pkcs10/PKCS10Attributes;)V", nullptr, $PUBLIC, $method(PKCS10, init$, void, $PublicKey*, $PKCS10Attributes*)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(PKCS10, init$, void, $bytes*), "java.io.IOException,java.security.SignatureException,java.security.NoSuchAlgorithmException"},
	{"encodeAndSign", "(Lsun/security/x509/X500Name;Ljava/security/PrivateKey;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PKCS10, encodeAndSign, void, $X500Name*, $PrivateKey*, $String*), "java.io.IOException,java.security.SignatureException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PKCS10, equals, bool, Object$*)},
	{"getAttributes", "()Lsun/security/pkcs10/PKCS10Attributes;", nullptr, $PUBLIC, $virtualMethod(PKCS10, getAttributes, $PKCS10Attributes*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(PKCS10, getEncoded, $bytes*)},
	{"getSigAlg", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS10, getSigAlg, $String*)},
	{"getSubjectName", "()Lsun/security/x509/X500Name;", nullptr, $PUBLIC, $virtualMethod(PKCS10, getSubjectName, $X500Name*)},
	{"getSubjectPublicKeyInfo", "()Ljava/security/PublicKey;", nullptr, $PUBLIC, $virtualMethod(PKCS10, getSubjectPublicKeyInfo, $PublicKey*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(PKCS10, hashCode, int32_t)},
	{"print", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC, $virtualMethod(PKCS10, print, void, $PrintStream*), "java.io.IOException,java.security.SignatureException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS10, toString, $String*)},
	{}
};

$ClassInfo _PKCS10_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.pkcs10.PKCS10",
	"java.lang.Object",
	nullptr,
	_PKCS10_FieldInfo_,
	_PKCS10_MethodInfo_
};

$Object* allocate$PKCS10($Class* clazz) {
	return $of($alloc(PKCS10));
}

void PKCS10::init$($PublicKey* publicKey) {
	$set(this, subjectPublicKeyInfo, publicKey);
	$set(this, attributeSet, $new($PKCS10Attributes));
}

void PKCS10::init$($PublicKey* publicKey, $PKCS10Attributes* attributes) {
	$set(this, subjectPublicKeyInfo, publicKey);
	$set(this, attributeSet, attributes);
}

void PKCS10::init$($bytes* data$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, data, data$renamed);
	$var($DerInputStream, in, nullptr);
	$var($DerValueArray, seq, nullptr);
	$var($AlgorithmId, id, nullptr);
	$var($bytes, sigData, nullptr);
	$var($Signature, sig, nullptr);
	$set(this, encoded, data);
	$assign(in, $new($DerInputStream, data));
	$assign(seq, in->getSequence(3));
	if ($nc(seq)->length != 3) {
		$throwNew($IllegalArgumentException, "not a PKCS #10 request"_s);
	}
	$assign(data, $nc($nc(seq)->get(0))->toByteArray());
	$assign(id, $AlgorithmId::parse(seq->get(1)));
	$assign(sigData, $nc(seq->get(2))->getBitString());
	$var($BigInteger, serial, nullptr);
	$var($DerValue, val, nullptr);
	$assign(serial, $nc($nc(seq->get(0))->data$)->getBigInteger());
	$init($BigInteger);
	if (!$nc(serial)->equals($BigInteger::ZERO)) {
		$throwNew($IllegalArgumentException, "not PKCS #10 v1"_s);
	}
	$set(this, subject, $new($X500Name, $nc(seq->get(0))->data$));
	$set(this, subjectPublicKeyInfo, $X509Key::parse($($nc($nc(seq->get(0))->data$)->getDerValue())));
	if ($nc($nc(seq->get(0))->data$)->available() != 0) {
		$set(this, attributeSet, $new($PKCS10Attributes, $nc(seq->get(0))->data$));
	} else {
		$set(this, attributeSet, $new($PKCS10Attributes));
	}
	if ($nc($nc(seq->get(0))->data$)->available() != 0) {
		$throwNew($IllegalArgumentException, "illegal PKCS #10 data"_s);
	}
	try {
		$set(this, sigAlg, $nc(id)->getName());
		$assign(sig, $Signature::getInstance(this->sigAlg));
		$SignatureUtil::initVerifyWithParam(sig, this->subjectPublicKeyInfo, $($SignatureUtil::getParamSpec(this->sigAlg, $(id->getParameters()))));
		$nc(sig)->update(data);
		if (!sig->verify(sigData)) {
			$throwNew($SignatureException, "Invalid PKCS #10 signature"_s);
		}
	} catch ($InvalidKeyException& e) {
		$throwNew($SignatureException, "Invalid key"_s);
	} catch ($InvalidAlgorithmParameterException& e) {
		$throwNew($SignatureException, "Invalid signature parameters"_s, e);
	} catch ($ProviderException& e) {
		$throwNew($SignatureException, "Error parsing signature parameters"_s, $(e->getCause()));
	}
}

void PKCS10::encodeAndSign($X500Name* subject, $PrivateKey* key, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, out, nullptr);
	$var($DerOutputStream, scratch, nullptr);
	$var($bytes, certificateRequestInfo, nullptr);
	$var($bytes, sig, nullptr);
	if (this->encoded != nullptr) {
		$throwNew($SignatureException, "request is already signed"_s);
	}
	$var($Signature, signature, $SignatureUtil::fromKey(algorithm, static_cast<$Key*>(key), ($Provider*)nullptr));
	$set(this, subject, subject);
	$assign(scratch, $new($DerOutputStream));
	$init($BigInteger);
	scratch->putInteger($BigInteger::ZERO);
	$nc(subject)->encode(scratch);
	scratch->write($($nc(this->subjectPublicKeyInfo)->getEncoded()));
	$nc(this->attributeSet)->encode(scratch);
	$assign(out, $new($DerOutputStream));
	out->write($DerValue::tag_Sequence, scratch);
	$assign(certificateRequestInfo, out->toByteArray());
	$assign(scratch, out);
	$nc(signature)->update(certificateRequestInfo, 0, $nc(certificateRequestInfo)->length);
	$assign(sig, signature->sign());
	$set(this, sigAlg, signature->getAlgorithm());
	$var($AlgorithmId, algId, $SignatureUtil::fromSignature(signature, key));
	$nc(algId)->encode(scratch);
	scratch->putBitString(sig);
	$assign(out, $new($DerOutputStream));
	out->write($DerValue::tag_Sequence, scratch);
	$set(this, encoded, out->toByteArray());
}

$X500Name* PKCS10::getSubjectName() {
	return this->subject;
}

$PublicKey* PKCS10::getSubjectPublicKeyInfo() {
	return this->subjectPublicKeyInfo;
}

$String* PKCS10::getSigAlg() {
	return this->sigAlg;
}

$PKCS10Attributes* PKCS10::getAttributes() {
	return this->attributeSet;
}

$bytes* PKCS10::getEncoded() {
	if (this->encoded != nullptr) {
		return $cast($bytes, $nc(this->encoded)->clone());
	} else {
		return nullptr;
	}
}

void PKCS10::print($PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	if (this->encoded == nullptr) {
		$throwNew($SignatureException, "Cert request was not signed"_s);
	}
	$var($bytes, CRLF, $new($bytes, {
		(int8_t)u'\r',
		(int8_t)u'\n'
	}));
	$nc(out)->println("-----BEGIN NEW CERTIFICATE REQUEST-----"_s);
	out->println($($nc($($Base64::getMimeEncoder(64, CRLF)))->encodeToString(this->encoded)));
	out->println("-----END NEW CERTIFICATE REQUEST-----"_s);
}

$String* PKCS10::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$1, $$str({"[PKCS #10 certificate request:\n"_s, $($nc($of(this->subjectPublicKeyInfo))->toString()), " subject: <"_s, this->subject, ">\n attributes: "_s}));
	$var($String, var$0, $$concat(var$1, $($nc(this->attributeSet)->toString())));
	return $concat(var$0, "\n]"_s);
}

bool PKCS10::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	if (!($instanceOf(PKCS10, other))) {
		return false;
	}
	if (this->encoded == nullptr) {
		return false;
	}
	$var($bytes, otherEncoded, $nc(($cast(PKCS10, other)))->getEncoded());
	if (otherEncoded == nullptr) {
		return false;
	}
	return $Arrays::equals(this->encoded, otherEncoded);
}

int32_t PKCS10::hashCode() {
	int32_t retval = 0;
	if (this->encoded != nullptr) {
		for (int32_t i = 1; i < $nc(this->encoded)->length; ++i) {
			retval += $nc(this->encoded)->get(i) * i;
		}
	}
	return (retval);
}

PKCS10::PKCS10() {
}

$Class* PKCS10::load$($String* name, bool initialize) {
	$loadClass(PKCS10, name, initialize, &_PKCS10_ClassInfo_, allocate$PKCS10);
	return class$;
}

$Class* PKCS10::class$ = nullptr;

		} // pkcs10
	} // security
} // sun