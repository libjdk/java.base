#include <javax/crypto/EncryptedPrivateKeyInfo.h>

#include <java/io/IOException.h>
#include <java/lang/IllegalStateException.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/Provider.h>
#include <java/security/Security.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <javax/crypto/Cipher.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef DECRYPT_MODE
#undef TAG_CONTEXT

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $Provider = ::java::security::Provider;
using $Security = ::java::security::Security;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $Cipher = ::javax::crypto::Cipher;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace javax {
	namespace crypto {

$FieldInfo _EncryptedPrivateKeyInfo_FieldInfo_[] = {
	{"algid", "Lsun/security/x509/AlgorithmId;", nullptr, $PRIVATE, $field(EncryptedPrivateKeyInfo, algid)},
	{"keyAlg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(EncryptedPrivateKeyInfo, keyAlg)},
	{"encryptedData", "[B", nullptr, $PRIVATE, $field(EncryptedPrivateKeyInfo, encryptedData)},
	{"encoded", "[B", nullptr, $PRIVATE, $field(EncryptedPrivateKeyInfo, encoded)},
	{}
};

$MethodInfo _EncryptedPrivateKeyInfo_MethodInfo_[] = {
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(EncryptedPrivateKeyInfo, init$, void, $bytes*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(EncryptedPrivateKeyInfo, init$, void, $String*, $bytes*), "java.security.NoSuchAlgorithmException"},
	{"<init>", "(Ljava/security/AlgorithmParameters;[B)V", nullptr, $PUBLIC, $method(EncryptedPrivateKeyInfo, init$, void, $AlgorithmParameters*, $bytes*), "java.security.NoSuchAlgorithmException"},
	{"checkPKCS8Encoding", "([B)V", nullptr, $PRIVATE, $method(EncryptedPrivateKeyInfo, checkPKCS8Encoding, void, $bytes*), "java.io.IOException"},
	{"checkTag", "(Lsun/security/util/DerValue;BLjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(EncryptedPrivateKeyInfo, checkTag, void, $DerValue*, int8_t, $String*), "java.io.IOException"},
	{"getAlgName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getAlgName, $String*)},
	{"getAlgParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getAlgParameters, $AlgorithmParameters*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getEncoded, $bytes*), "java.io.IOException"},
	{"getEncryptedData", "()[B", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getEncryptedData, $bytes*)},
	{"getKeySpec", "(Ljavax/crypto/Cipher;)Ljava/security/spec/PKCS8EncodedKeySpec;", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getKeySpec, $PKCS8EncodedKeySpec*, $Cipher*), "java.security.spec.InvalidKeySpecException"},
	{"getKeySpec", "(Ljava/security/Key;)Ljava/security/spec/PKCS8EncodedKeySpec;", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getKeySpec, $PKCS8EncodedKeySpec*, $Key*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"getKeySpec", "(Ljava/security/Key;Ljava/lang/String;)Ljava/security/spec/PKCS8EncodedKeySpec;", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getKeySpec, $PKCS8EncodedKeySpec*, $Key*, $String*), "java.security.NoSuchProviderException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"getKeySpec", "(Ljava/security/Key;Ljava/security/Provider;)Ljava/security/spec/PKCS8EncodedKeySpec;", nullptr, $PUBLIC, $virtualMethod(EncryptedPrivateKeyInfo, getKeySpec, $PKCS8EncodedKeySpec*, $Key*, $Provider*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"getKeySpecImpl", "(Ljava/security/Key;Ljava/security/Provider;)Ljava/security/spec/PKCS8EncodedKeySpec;", nullptr, $PRIVATE, $method(EncryptedPrivateKeyInfo, getKeySpecImpl, $PKCS8EncodedKeySpec*, $Key*, $Provider*), "java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{}
};

$ClassInfo _EncryptedPrivateKeyInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.crypto.EncryptedPrivateKeyInfo",
	"java.lang.Object",
	nullptr,
	_EncryptedPrivateKeyInfo_FieldInfo_,
	_EncryptedPrivateKeyInfo_MethodInfo_
};

$Object* allocate$EncryptedPrivateKeyInfo($Class* clazz) {
	return $of($alloc(EncryptedPrivateKeyInfo));
}

void EncryptedPrivateKeyInfo::init$($bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$set(this, encoded, nullptr);
	if (encoded == nullptr) {
		$throwNew($NullPointerException, "the encoded parameter must be non-null"_s);
	}
	$set(this, encoded, $cast($bytes, $nc(encoded)->clone()));
	$var($DerValue, val, $new($DerValue, this->encoded));
	$var($DerValueArray, seq, $new($DerValueArray, 2));
	seq->set(0, $($nc(val->data$)->getDerValue()));
	seq->set(1, $($nc(val->data$)->getDerValue()));
	if ($nc(val->data$)->available() != 0) {
		$throwNew($IOException, $$str({"overrun, bytes = "_s, $$str($nc(val->data$)->available())}));
	}
	$set(this, algid, $AlgorithmId::parse(seq->get(0)));
	if ($nc($nc(seq->get(0))->data$)->available() != 0) {
		$throwNew($IOException, "encryptionAlgorithm field overrun"_s);
	}
	$set(this, encryptedData, $nc(seq->get(1))->getOctetString());
	if ($nc($nc(seq->get(1))->data$)->available() != 0) {
		$throwNew($IOException, "encryptedData field overrun"_s);
	}
}

void EncryptedPrivateKeyInfo::init$($String* algName, $bytes* encryptedData) {
	$set(this, encoded, nullptr);
	if (algName == nullptr) {
		$throwNew($NullPointerException, "the algName parameter must be non-null"_s);
	}
	$set(this, algid, $AlgorithmId::get(algName));
	if (encryptedData == nullptr) {
		$throwNew($NullPointerException, "the encryptedData parameter must be non-null"_s);
	} else if ($nc(encryptedData)->length == 0) {
		$throwNew($IllegalArgumentException, "the encryptedData parameter must not be empty"_s);
	} else {
		$set(this, encryptedData, $cast($bytes, encryptedData->clone()));
	}
	$set(this, encoded, nullptr);
}

void EncryptedPrivateKeyInfo::init$($AlgorithmParameters* algParams, $bytes* encryptedData) {
	$set(this, encoded, nullptr);
	if (algParams == nullptr) {
		$throwNew($NullPointerException, "algParams must be non-null"_s);
	}
	$set(this, algid, $AlgorithmId::get(algParams));
	if (encryptedData == nullptr) {
		$throwNew($NullPointerException, "encryptedData must be non-null"_s);
	} else if ($nc(encryptedData)->length == 0) {
		$throwNew($IllegalArgumentException, "the encryptedData parameter must not be empty"_s);
	} else {
		$set(this, encryptedData, $cast($bytes, encryptedData->clone()));
	}
	$set(this, encoded, nullptr);
}

$String* EncryptedPrivateKeyInfo::getAlgName() {
	return $nc(this->algid)->getName();
}

$AlgorithmParameters* EncryptedPrivateKeyInfo::getAlgParameters() {
	return $nc(this->algid)->getParameters();
}

$bytes* EncryptedPrivateKeyInfo::getEncryptedData() {
	return $cast($bytes, $nc(this->encryptedData)->clone());
}

$PKCS8EncodedKeySpec* EncryptedPrivateKeyInfo::getKeySpec($Cipher* cipher) {
	$var($bytes, encoded, nullptr);
	try {
		$assign(encoded, $nc(cipher)->doFinal(this->encryptedData));
		checkPKCS8Encoding(encoded);
	} catch ($GeneralSecurityException& ex) {
		$throwNew($InvalidKeySpecException, "Cannot retrieve the PKCS8EncodedKeySpec"_s, ex);
	} catch ($IOException& ex) {
		$throwNew($InvalidKeySpecException, "Cannot retrieve the PKCS8EncodedKeySpec"_s, ex);
	} catch ($IllegalStateException& ex) {
		$throwNew($InvalidKeySpecException, "Cannot retrieve the PKCS8EncodedKeySpec"_s, ex);
	}
	return $new($PKCS8EncodedKeySpec, encoded, this->keyAlg);
}

$PKCS8EncodedKeySpec* EncryptedPrivateKeyInfo::getKeySpecImpl($Key* decryptKey, $Provider* provider) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, nullptr);
	$var($Cipher, c, nullptr);
	try {
		if (provider == nullptr) {
			$assign(c, $Cipher::getInstance($($nc(this->algid)->getName())));
		} else {
			$assign(c, $Cipher::getInstance($($nc(this->algid)->getName()), provider));
		}
		$nc(c)->init($Cipher::DECRYPT_MODE, decryptKey, $($nc(this->algid)->getParameters()));
		$assign(encoded, c->doFinal(this->encryptedData));
		checkPKCS8Encoding(encoded);
	} catch ($NoSuchAlgorithmException& nsae) {
		$throw(nsae);
	} catch ($GeneralSecurityException& ex) {
		$throwNew($InvalidKeyException, "Cannot retrieve the PKCS8EncodedKeySpec"_s, ex);
	} catch ($IOException& ex) {
		$throwNew($InvalidKeyException, "Cannot retrieve the PKCS8EncodedKeySpec"_s, ex);
	}
	return $new($PKCS8EncodedKeySpec, encoded, this->keyAlg);
}

$PKCS8EncodedKeySpec* EncryptedPrivateKeyInfo::getKeySpec($Key* decryptKey) {
	if (decryptKey == nullptr) {
		$throwNew($NullPointerException, "decryptKey is null"_s);
	}
	return getKeySpecImpl(decryptKey, nullptr);
}

$PKCS8EncodedKeySpec* EncryptedPrivateKeyInfo::getKeySpec($Key* decryptKey, $String* providerName) {
	$useLocalCurrentObjectStackCache();
	if (decryptKey == nullptr) {
		$throwNew($NullPointerException, "decryptKey is null"_s);
	}
	if (providerName == nullptr) {
		$throwNew($NullPointerException, "provider is null"_s);
	}
	$var($Provider, provider, $Security::getProvider(providerName));
	if (provider == nullptr) {
		$throwNew($NoSuchProviderException, $$str({"provider "_s, providerName, " not found"_s}));
	}
	return getKeySpecImpl(decryptKey, provider);
}

$PKCS8EncodedKeySpec* EncryptedPrivateKeyInfo::getKeySpec($Key* decryptKey, $Provider* provider) {
	if (decryptKey == nullptr) {
		$throwNew($NullPointerException, "decryptKey is null"_s);
	}
	if (provider == nullptr) {
		$throwNew($NullPointerException, "provider is null"_s);
	}
	return getKeySpecImpl(decryptKey, provider);
}

$bytes* EncryptedPrivateKeyInfo::getEncoded() {
	$useLocalCurrentObjectStackCache();
	if (this->encoded == nullptr) {
		$var($DerOutputStream, out, $new($DerOutputStream));
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		$nc(this->algid)->encode(tmp);
		tmp->putOctetString(this->encryptedData);
		out->write($DerValue::tag_Sequence, tmp);
		$set(this, encoded, out->toByteArray());
	}
	return $cast($bytes, $nc(this->encoded)->clone());
}

void EncryptedPrivateKeyInfo::checkTag($DerValue* val, int8_t tag, $String* valName) {
	if ($nc(val)->getTag() != tag) {
		$throwNew($IOException, $$str({"invalid key encoding - wrong tag for "_s, valName}));
	}
}

void EncryptedPrivateKeyInfo::checkPKCS8Encoding($bytes* encodedKey) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, in, $new($DerInputStream, encodedKey));
	$var($DerValueArray, values, in->getSequence(3));
	switch ($nc(values)->length) {
	case 4:
		{
			checkTag(values->get(3), $DerValue::TAG_CONTEXT, "attributes"_s);
		}
	case 3:
		{
			checkTag(values->get(0), $DerValue::tag_Integer, "version"_s);
			$set(this, keyAlg, $nc($($AlgorithmId::parse(values->get(1))))->getName());
			checkTag(values->get(2), $DerValue::tag_OctetString, "privateKey"_s);
			break;
		}
	default:
		{
			$throwNew($IOException, "invalid key encoding"_s);
		}
	}
}

EncryptedPrivateKeyInfo::EncryptedPrivateKeyInfo() {
}

$Class* EncryptedPrivateKeyInfo::load$($String* name, bool initialize) {
	$loadClass(EncryptedPrivateKeyInfo, name, initialize, &_EncryptedPrivateKeyInfo_ClassInfo_, allocate$EncryptedPrivateKeyInfo);
	return class$;
}

$Class* EncryptedPrivateKeyInfo::class$ = nullptr;

	} // crypto
} // javax