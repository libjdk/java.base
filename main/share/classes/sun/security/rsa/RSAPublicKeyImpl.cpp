#include <sun/security/rsa/RSAPublicKeyImpl.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/KeyRep$Type.h>
#include <java/security/KeyRep.h>
#include <java/security/ProviderException.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <sun/security/rsa/RSAKeyFactory.h>
#include <sun/security/rsa/RSAUtil$KeyType.h>
#include <sun/security/rsa/RSAUtil.h>
#include <sun/security/util/BitArray.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/X509Key.h>
#include <jcpp.h>

#undef PUBLIC
#undef THREE

using $BigIntegerArray = $Array<::java::math::BigInteger>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $KeyRep = ::java::security::KeyRep;
using $KeyRep$Type = ::java::security::KeyRep$Type;
using $ProviderException = ::java::security::ProviderException;
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $RSAKeyFactory = ::sun::security::rsa::RSAKeyFactory;
using $RSAUtil = ::sun::security::rsa::RSAUtil;
using $RSAUtil$KeyType = ::sun::security::rsa::RSAUtil$KeyType;
using $BitArray = ::sun::security::util::BitArray;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $X509Key = ::sun::security::x509::X509Key;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _RSAPublicKeyImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSAPublicKeyImpl, serialVersionUID)},
	{"THREE", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSAPublicKeyImpl, THREE)},
	{"n", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPublicKeyImpl, n)},
	{"e", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPublicKeyImpl, e)},
	{"type", "Lsun/security/rsa/RSAUtil$KeyType;", nullptr, $PRIVATE | $TRANSIENT, $field(RSAPublicKeyImpl, type)},
	{"keyParams", "Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PRIVATE | $TRANSIENT, $field(RSAPublicKeyImpl, keyParams)},
	{}
};

$MethodInfo _RSAPublicKeyImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getEncoded", "()[B", nullptr, $PUBLIC},
	{"*getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;Ljava/math/BigInteger;Ljava/math/BigInteger;)V", nullptr, 0, $method(RSAPublicKeyImpl, init$, void, $RSAUtil$KeyType*, $AlgorithmParameterSpec*, $BigInteger*, $BigInteger*), "java.security.InvalidKeyException"},
	{"<init>", "([B)V", nullptr, $PRIVATE, $method(RSAPublicKeyImpl, init$, void, $bytes*), "java.security.InvalidKeyException"},
	{"checkExponentRange", "(Ljava/math/BigInteger;Ljava/math/BigInteger;)V", nullptr, $STATIC, $staticMethod(RSAPublicKeyImpl, checkExponentRange, void, $BigInteger*, $BigInteger*), "java.security.InvalidKeyException"},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(RSAPublicKeyImpl, getAlgorithm, $String*)},
	{"getModulus", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPublicKeyImpl, getModulus, $BigInteger*)},
	{"getParams", "()Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC, $virtualMethod(RSAPublicKeyImpl, getParams, $AlgorithmParameterSpec*)},
	{"getPublicExponent", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPublicKeyImpl, getPublicExponent, $BigInteger*)},
	{"newKey", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/lang/String;[B)Ljava/security/interfaces/RSAPublicKey;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPublicKeyImpl, newKey, $RSAPublicKey*, $RSAUtil$KeyType*, $String*, $bytes*), "java.security.InvalidKeyException"},
	{"newKey", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/security/interfaces/RSAPublicKey;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPublicKeyImpl, newKey, $RSAPublicKey*, $RSAUtil$KeyType*, $AlgorithmParameterSpec*, $BigInteger*, $BigInteger*), "java.security.InvalidKeyException"},
	{"parseASN1", "([B)[Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAPublicKeyImpl, parseASN1, $BigIntegerArray*, $bytes*), "java.io.IOException"},
	{"parseKeyBits", "()V", nullptr, $PROTECTED, $virtualMethod(RSAPublicKeyImpl, parseKeyBits, void), "java.security.InvalidKeyException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(RSAPublicKeyImpl, toString, $String*)},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PROTECTED, $method(RSAPublicKeyImpl, writeReplace, $Object*), "java.io.ObjectStreamException"},
	{}
};

$ClassInfo _RSAPublicKeyImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.rsa.RSAPublicKeyImpl",
	"sun.security.x509.X509Key",
	"java.security.interfaces.RSAPublicKey",
	_RSAPublicKeyImpl_FieldInfo_,
	_RSAPublicKeyImpl_MethodInfo_
};

$Object* allocate$RSAPublicKeyImpl($Class* clazz) {
	return $of($alloc(RSAPublicKeyImpl));
}

$bytes* RSAPublicKeyImpl::getEncoded() {
	 return this->$X509Key::getEncoded();
}

$String* RSAPublicKeyImpl::getFormat() {
	 return this->$X509Key::getFormat();
}

bool RSAPublicKeyImpl::equals(Object$* obj) {
	 return this->$X509Key::equals(obj);
}

int32_t RSAPublicKeyImpl::hashCode() {
	 return this->$X509Key::hashCode();
}

$Object* RSAPublicKeyImpl::clone() {
	 return this->$X509Key::clone();
}

void RSAPublicKeyImpl::finalize() {
	this->$X509Key::finalize();
}

$BigInteger* RSAPublicKeyImpl::THREE = nullptr;

$RSAPublicKey* RSAPublicKeyImpl::newKey($RSAUtil$KeyType* type, $String* format, $bytes* encoded) {
	$init(RSAPublicKeyImpl);
	$useLocalCurrentObjectStackCache();
	$var($RSAPublicKey, key, nullptr);
	{
		$var($String, s2624$, format);
		int32_t tmp2624$ = -1;
		switch ($nc(s2624$)->hashCode()) {
		case 0x04EDCA68:
			{
				if (s2624$->equals("X.509"_s)) {
					tmp2624$ = 0;
				}
				break;
			}
		case (int32_t)0x8CC44559:
			{
				if (s2624$->equals("PKCS#1"_s)) {
					tmp2624$ = 1;
				}
				break;
			}
		}
		switch (tmp2624$) {
		case 0:
			{
				$assign(key, $new(RSAPublicKeyImpl, encoded));
				$RSAKeyFactory::checkKeyAlgo(key, $nc(type)->keyAlgo);
				break;
			}
		case 1:
			{
				try {
					$var($BigIntegerArray, comps, parseASN1(encoded));
					$assign(key, $new(RSAPublicKeyImpl, type, nullptr, $nc(comps)->get(0), comps->get(1)));
				} catch ($IOException& ioe) {
					$throwNew($InvalidKeyException, "Invalid PKCS#1 encoding"_s, ioe);
				}
				break;
			}
		default:
			{
				$throwNew($InvalidKeyException, $$str({"Unsupported RSA PublicKey format: "_s, format}));
			}
		}
	}
	return key;
}

$RSAPublicKey* RSAPublicKeyImpl::newKey($RSAUtil$KeyType* type, $AlgorithmParameterSpec* params, $BigInteger* n, $BigInteger* e) {
	$init(RSAPublicKeyImpl);
	return $new(RSAPublicKeyImpl, type, params, n, e);
}

void RSAPublicKeyImpl::init$($RSAUtil$KeyType* type, $AlgorithmParameterSpec* keyParams, $BigInteger* n, $BigInteger* e) {
	$useLocalCurrentObjectStackCache();
	$X509Key::init$();
	$RSAKeyFactory::checkRSAProviderKeyLengths($nc(n)->bitLength(), e);
	checkExponentRange(n, e);
	$set(this, n, n);
	$set(this, e, e);
	try {
		$set(this, algid, $RSAUtil::createAlgorithmId(type, keyParams));
	} catch ($ProviderException& pe) {
		$throwNew($InvalidKeyException, static_cast<$Throwable*>(pe));
	}
	$set(this, type, type);
	$set(this, keyParams, keyParams);
	try {
		$var($DerOutputStream, out, $new($DerOutputStream));
		out->putInteger(n);
		out->putInteger(e);
		$var($bytes, keyArray, $$new($DerValue, $DerValue::tag_Sequence, $(out->toByteArray()))->toByteArray());
		setKey($$new($BitArray, $nc(keyArray)->length * 8, keyArray));
	} catch ($IOException& exc) {
		$throwNew($InvalidKeyException, static_cast<$Throwable*>(exc));
	}
}

void RSAPublicKeyImpl::init$($bytes* encoded) {
	$X509Key::init$();
	if (encoded == nullptr || $nc(encoded)->length == 0) {
		$throwNew($InvalidKeyException, "Missing key encoding"_s);
	}
	decode(encoded);
	$RSAKeyFactory::checkRSAProviderKeyLengths($nc(this->n)->bitLength(), this->e);
	checkExponentRange(this->n, this->e);
	try {
		$var($ObjectArray, o, $RSAUtil::getTypeAndParamSpec(this->algid));
		$set(this, type, $cast($RSAUtil$KeyType, $nc(o)->get(0)));
		$set(this, keyParams, $cast($AlgorithmParameterSpec, o->get(1)));
	} catch ($ProviderException& e) {
		$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
	}
}

void RSAPublicKeyImpl::checkExponentRange($BigInteger* mod, $BigInteger* exp) {
	$init(RSAPublicKeyImpl);
	if ($nc(exp)->compareTo(mod) >= 0) {
		$throwNew($InvalidKeyException, "exponent is larger than modulus"_s);
	}
	if ($nc(exp)->compareTo(RSAPublicKeyImpl::THREE) < 0) {
		$throwNew($InvalidKeyException, "exponent is smaller than 3"_s);
	}
}

$String* RSAPublicKeyImpl::getAlgorithm() {
	return $nc(this->type)->keyAlgo;
}

$BigInteger* RSAPublicKeyImpl::getModulus() {
	return this->n;
}

$BigInteger* RSAPublicKeyImpl::getPublicExponent() {
	return this->e;
}

$AlgorithmParameterSpec* RSAPublicKeyImpl::getParams() {
	return this->keyParams;
}

$BigIntegerArray* RSAPublicKeyImpl::parseASN1($bytes* raw) {
	$init(RSAPublicKeyImpl);
	$useLocalCurrentObjectStackCache();
	$var($DerValue, derValue, $new($DerValue, raw));
	if (derValue->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Not a SEQUENCE"_s);
	}
	$var($BigIntegerArray, result, $new($BigIntegerArray, 2));
	result->set(0, $($nc(derValue->data$)->getPositiveBigInteger()));
	result->set(1, $($nc(derValue->data$)->getPositiveBigInteger()));
	if ($nc(derValue->data$)->available() != 0) {
		$throwNew($IOException, "Extra data available"_s);
	}
	return result;
}

void RSAPublicKeyImpl::parseKeyBits() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($BigIntegerArray, comps, parseASN1($($nc($(getKey()))->toByteArray())));
		$set(this, n, $nc(comps)->get(0));
		$set(this, e, comps->get(1));
	} catch ($IOException& e) {
		$throwNew($InvalidKeyException, "Invalid RSA public key"_s, e);
	}
}

$String* RSAPublicKeyImpl::toString() {
	return $str({"Sun "_s, $nc(this->type)->keyAlgo, " public key, "_s, $$str($nc(this->n)->bitLength()), " bits\n  params: "_s, this->keyParams, "\n  modulus: "_s, this->n, "\n  public exponent: "_s, this->e});
}

$Object* RSAPublicKeyImpl::writeReplace() {
	$useLocalCurrentObjectStackCache();
	$init($KeyRep$Type);
	$var($KeyRep$Type, var$0, $KeyRep$Type::PUBLIC);
	$var($String, var$1, getAlgorithm());
	$var($String, var$2, getFormat());
	return $of($new($KeyRep, var$0, var$1, var$2, $(getEncoded())));
}

void clinit$RSAPublicKeyImpl($Class* class$) {
	$assignStatic(RSAPublicKeyImpl::THREE, $BigInteger::valueOf((int64_t)3));
}

RSAPublicKeyImpl::RSAPublicKeyImpl() {
}

$Class* RSAPublicKeyImpl::load$($String* name, bool initialize) {
	$loadClass(RSAPublicKeyImpl, name, initialize, &_RSAPublicKeyImpl_ClassInfo_, clinit$RSAPublicKeyImpl, allocate$RSAPublicKeyImpl);
	return class$;
}

$Class* RSAPublicKeyImpl::class$ = nullptr;

		} // rsa
	} // security
} // sun