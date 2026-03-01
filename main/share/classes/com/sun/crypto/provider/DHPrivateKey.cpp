#include <com/sun/crypto/provider/DHPrivateKey.h>

#include <com/sun/crypto/provider/DHPublicKey.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/NumberFormatException.h>
#include <java/math/BigInteger.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/KeyRep$Type.h>
#include <java/security/KeyRep.h>
#include <java/security/ProviderException.h>
#include <java/util/Arrays.h>
#include <java/util/Objects.h>
#include <javax/crypto/interfaces/DHKey.h>
#include <javax/crypto/interfaces/DHPrivateKey.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef DH_OID
#undef PKCS8_VERSION
#undef PRIVATE
#undef ZERO

using $DHPublicKey = ::com::sun::crypto::provider::DHPublicKey;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $BigInteger = ::java::math::BigInteger;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $KeyRep = ::java::security::KeyRep;
using $KeyRep$Type = ::java::security::KeyRep$Type;
using $ProviderException = ::java::security::ProviderException;
using $Arrays = ::java::util::Arrays;
using $Objects = ::java::util::Objects;
using $DHPrivateKey = ::javax::crypto::interfaces::DHPrivateKey;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _DHPrivateKey_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(DHPrivateKey, serialVersionUID)},
	{"PKCS8_VERSION", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DHPrivateKey, PKCS8_VERSION)},
	{"x", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHPrivateKey, x)},
	{"key", "[B", nullptr, $PRIVATE, $field(DHPrivateKey, key)},
	{"encodedKey", "[B", nullptr, $PRIVATE, $field(DHPrivateKey, encodedKey)},
	{"p", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHPrivateKey, p)},
	{"g", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DHPrivateKey, g)},
	{"l", "I", nullptr, $PRIVATE, $field(DHPrivateKey, l)},
	{}
};

$MethodInfo _DHPrivateKey_MethodInfo_[] = {
	{"<init>", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)V", nullptr, 0, $method(DHPrivateKey, init$, void, $BigInteger*, $BigInteger*, $BigInteger*), "java.security.InvalidKeyException"},
	{"<init>", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;I)V", nullptr, 0, $method(DHPrivateKey, init$, void, $BigInteger*, $BigInteger*, $BigInteger*, int32_t)},
	{"<init>", "([B)V", nullptr, 0, $method(DHPrivateKey, init$, void, $bytes*), "java.security.InvalidKeyException"},
	{"encode", "()V", nullptr, $PRIVATE, $method(DHPrivateKey, encode, void)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DHPrivateKey, equals, bool, Object$*)},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DHPrivateKey, getAlgorithm, $String*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(DHPrivateKey, getEncoded, $bytes*)},
	{"getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DHPrivateKey, getFormat, $String*)},
	{"getParams", "()Ljavax/crypto/spec/DHParameterSpec;", nullptr, $PUBLIC, $virtualMethod(DHPrivateKey, getParams, $DHParameterSpec*)},
	{"getX", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(DHPrivateKey, getX, $BigInteger*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(DHPrivateKey, hashCode, int32_t)},
	{"parseKeyBits", "()V", nullptr, $PRIVATE, $method(DHPrivateKey, parseKeyBits, void), "java.security.InvalidKeyException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(DHPrivateKey, writeReplace, $Object*), "java.io.ObjectStreamException"},
	{}
};

$ClassInfo _DHPrivateKey_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.DHPrivateKey",
	"java.lang.Object",
	"javax.crypto.interfaces.DHPrivateKey",
	_DHPrivateKey_FieldInfo_,
	_DHPrivateKey_MethodInfo_
};

$Object* allocate$DHPrivateKey($Class* clazz) {
	return $of($alloc(DHPrivateKey));
}

$BigInteger* DHPrivateKey::PKCS8_VERSION = nullptr;

void DHPrivateKey::init$($BigInteger* x, $BigInteger* p, $BigInteger* g) {
	DHPrivateKey::init$(x, p, g, 0);
}

void DHPrivateKey::init$($BigInteger* x, $BigInteger* p, $BigInteger* g, int32_t l) {
	$useLocalCurrentObjectStackCache();
	$set(this, x, x);
	$set(this, p, p);
	$set(this, g, g);
	this->l = l;
	try {
		$var($bytes, xbytes, $nc(x)->toByteArray());
		$var($DerValue, val, $new($DerValue, $DerValue::tag_Integer, xbytes));
		$set(this, key, val->toByteArray());
		val->clear();
		$Arrays::fill(xbytes, (int8_t)0);
		encode();
	} catch ($IOException& e) {
		$throwNew($ProviderException, "Cannot produce ASN.1 encoding"_s, e);
	}
}

void DHPrivateKey::init$($bytes* encodedKey) {
	$useLocalCurrentObjectStackCache();
	$var($DerValue, val, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$assign(val, $new($DerValue, encodedKey));
				if (val->tag != $DerValue::tag_Sequence) {
					$throwNew($InvalidKeyException, "Key not a SEQUENCE"_s);
				}
				$var($BigInteger, parsedVersion, $nc(val->data$)->getBigInteger());
				if (!$nc(parsedVersion)->equals(DHPrivateKey::PKCS8_VERSION)) {
					$throwNew($IOException, $$str({"version mismatch: (supported: "_s, DHPrivateKey::PKCS8_VERSION, ", parsed: "_s, parsedVersion}));
				}
				$var($DerValue, algid, $nc(val->data$)->getDerValue());
				if ($nc(algid)->tag != $DerValue::tag_Sequence) {
					$throwNew($InvalidKeyException, "AlgId is not a SEQUENCE"_s);
				}
				$var($DerInputStream, derInStream, $nc(algid)->toDerInputStream());
				$var($ObjectIdentifier, oid, $nc(derInStream)->getOID());
				if (oid == nullptr) {
					$throwNew($InvalidKeyException, "Null OID"_s);
				}
				if (derInStream->available() == 0) {
					$throwNew($InvalidKeyException, "Parameters missing"_s);
				}
				$var($DerValue, params, derInStream->getDerValue());
				if ($nc(params)->tag == $DerValue::tag_Null) {
					$throwNew($InvalidKeyException, "Null parameters"_s);
				}
				if ($nc(params)->tag != $DerValue::tag_Sequence) {
					$throwNew($InvalidKeyException, "Parameters not a SEQUENCE"_s);
				}
				$nc($nc(params)->data$)->reset();
				$set(this, p, $nc(params->data$)->getBigInteger());
				$set(this, g, $nc(params->data$)->getBigInteger());
				if ($nc(params->data$)->available() != 0) {
					this->l = $nc(params->data$)->getInteger();
				}
				if ($nc(params->data$)->available() != 0) {
					$throwNew($InvalidKeyException, "Extra parameter data"_s);
				}
				$set(this, key, $nc(val->data$)->getOctetString());
				parseKeyBits();
				$set(this, encodedKey, $cast($bytes, $nc(encodedKey)->clone()));
			} catch ($IOException& e) {
				$throwNew($InvalidKeyException, "Error parsing key encoding"_s, e);
			} catch ($NumberFormatException& e) {
				$throwNew($InvalidKeyException, "Error parsing key encoding"_s, e);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (val != nullptr) {
				val->clear();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$String* DHPrivateKey::getFormat() {
	return "PKCS#8"_s;
}

$String* DHPrivateKey::getAlgorithm() {
	return "DH"_s;
}

$bytes* DHPrivateKey::getEncoded() {
	$synchronized(this) {
		encode();
		return $cast($bytes, $nc(this->encodedKey)->clone());
	}
}

void DHPrivateKey::encode() {
	$useLocalCurrentObjectStackCache();
	if (this->encodedKey == nullptr) {
		try {
			$var($DerOutputStream, tmp, $new($DerOutputStream));
			tmp->putInteger(DHPrivateKey::PKCS8_VERSION);
			$var($DerOutputStream, algid, $new($DerOutputStream));
			$init($DHPublicKey);
			algid->putOID($DHPublicKey::DH_OID);
			$var($DerOutputStream, params, $new($DerOutputStream));
			params->putInteger(this->p);
			params->putInteger(this->g);
			if (this->l != 0) {
				params->putInteger(this->l);
			}
			$var($DerValue, paramSequence, $new($DerValue, $DerValue::tag_Sequence, $(params->toByteArray())));
			algid->putDerValue(paramSequence);
			tmp->write($DerValue::tag_Sequence, algid);
			tmp->putOctetString(this->key);
			$var($DerValue, val, $DerValue::wrap($DerValue::tag_Sequence, tmp));
			$set(this, encodedKey, $nc(val)->toByteArray());
			val->clear();
		} catch ($IOException& e) {
			$throwNew($AssertionError, $of(e));
		}
	}
}

$BigInteger* DHPrivateKey::getX() {
	return this->x;
}

$DHParameterSpec* DHPrivateKey::getParams() {
	if (this->l != 0) {
		return $new($DHParameterSpec, this->p, this->g, this->l);
	} else {
		return $new($DHParameterSpec, this->p, this->g);
	}
}

void DHPrivateKey::parseKeyBits() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($DerInputStream, in, $new($DerInputStream, this->key));
		$set(this, x, in->getBigInteger());
	} catch ($IOException& e) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, $$str({"Error parsing key encoding: "_s, $(e->getMessage())})));
		ike->initCause(e);
		$throw(ike);
	}
}

int32_t DHPrivateKey::hashCode() {
	return $Objects::hash($$new($ObjectArray, {
		$of(this->x),
		$of(this->p),
		$of(this->g)
	}));
}

bool DHPrivateKey::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf($DHPrivateKey, obj))) {
		return false;
	}
	$var($DHPrivateKey, other, $cast($DHPrivateKey, obj));
	$var($DHParameterSpec, otherParams, $nc(other)->getParams());
	bool var$1 = ($nc(this->x)->compareTo($(other->getX())) == 0);
	bool var$0 = var$1 && ($nc(this->p)->compareTo($($nc(otherParams)->getP())) == 0);
	return (var$0 && ($nc(this->g)->compareTo($($nc(otherParams)->getG())) == 0));
}

$Object* DHPrivateKey::writeReplace() {
	$useLocalCurrentObjectStackCache();
	encode();
	$init($KeyRep$Type);
	$var($KeyRep$Type, var$0, $KeyRep$Type::PRIVATE);
	$var($String, var$1, getAlgorithm());
	return $of($new($KeyRep, var$0, var$1, $(getFormat()), this->encodedKey));
}

void clinit$DHPrivateKey($Class* class$) {
	$init($BigInteger);
	$assignStatic(DHPrivateKey::PKCS8_VERSION, $BigInteger::ZERO);
}

DHPrivateKey::DHPrivateKey() {
}

$Class* DHPrivateKey::load$($String* name, bool initialize) {
	$loadClass(DHPrivateKey, name, initialize, &_DHPrivateKey_ClassInfo_, clinit$DHPrivateKey, allocate$DHPrivateKey);
	return class$;
}

$Class* DHPrivateKey::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com