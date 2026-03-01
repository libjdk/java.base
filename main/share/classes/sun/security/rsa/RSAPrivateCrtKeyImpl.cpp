#include <sun/security/rsa/RSAPrivateCrtKeyImpl.h>

#include <java/io/IOException.h>
#include <java/math/BigInteger.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/interfaces/RSAPrivateKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <sun/security/pkcs/PKCS8Key.h>
#include <sun/security/rsa/RSAKeyFactory.h>
#include <sun/security/rsa/RSAPrivateKeyImpl.h>
#include <sun/security/rsa/RSAUtil$KeyType.h>
#include <sun/security/rsa/RSAUtil.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

using $BigIntegerArray = $Array<::java::math::BigInteger>;
using $byteArray2 = $Array<int8_t, 2>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $RSAPrivateKey = ::java::security::interfaces::RSAPrivateKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $PKCS8Key = ::sun::security::pkcs::PKCS8Key;
using $RSAKeyFactory = ::sun::security::rsa::RSAKeyFactory;
using $RSAPrivateKeyImpl = ::sun::security::rsa::RSAPrivateKeyImpl;
using $RSAUtil = ::sun::security::rsa::RSAUtil;
using $RSAUtil$KeyType = ::sun::security::rsa::RSAUtil$KeyType;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace rsa {

$FieldInfo _RSAPrivateCrtKeyImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSAPrivateCrtKeyImpl, serialVersionUID)},
	{"n", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, n)},
	{"e", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, e)},
	{"d", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, d)},
	{"p", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, p)},
	{"q", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, q)},
	{"pe", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, pe)},
	{"qe", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, qe)},
	{"coeff", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(RSAPrivateCrtKeyImpl, coeff)},
	{"type", "Lsun/security/rsa/RSAUtil$KeyType;", nullptr, $PRIVATE | $TRANSIENT, $field(RSAPrivateCrtKeyImpl, type)},
	{"keyParams", "Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PRIVATE | $TRANSIENT, $field(RSAPrivateCrtKeyImpl, keyParams)},
	{}
};

$MethodInfo _RSAPrivateCrtKeyImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*destroy", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getEncoded", "()[B", nullptr, $PUBLIC},
	{"*getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "([B)V", nullptr, $PRIVATE, $method(RSAPrivateCrtKeyImpl, init$, void, $bytes*), "java.security.InvalidKeyException"},
	{"<init>", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)V", nullptr, 0, $method(RSAPrivateCrtKeyImpl, init$, void, $RSAUtil$KeyType*, $AlgorithmParameterSpec*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*), "java.security.InvalidKeyException"},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getAlgorithm, $String*)},
	{"getCrtCoefficient", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getCrtCoefficient, $BigInteger*)},
	{"getModulus", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getModulus, $BigInteger*)},
	{"getParams", "()Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getParams, $AlgorithmParameterSpec*)},
	{"getPrimeExponentP", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getPrimeExponentP, $BigInteger*)},
	{"getPrimeExponentQ", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getPrimeExponentQ, $BigInteger*)},
	{"getPrimeP", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getPrimeP, $BigInteger*)},
	{"getPrimeQ", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getPrimeQ, $BigInteger*)},
	{"getPrivateExponent", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getPrivateExponent, $BigInteger*)},
	{"getPublicExponent", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, getPublicExponent, $BigInteger*)},
	{"*isDestroyed", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"newKey", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/lang/String;[B)Ljava/security/interfaces/RSAPrivateKey;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPrivateCrtKeyImpl, newKey, $RSAPrivateKey*, $RSAUtil$KeyType*, $String*, $bytes*), "java.security.InvalidKeyException"},
	{"newKey", "(Lsun/security/rsa/RSAUtil$KeyType;Ljava/security/spec/AlgorithmParameterSpec;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Ljava/security/interfaces/RSAPrivateKey;", nullptr, $PUBLIC | $STATIC, $staticMethod(RSAPrivateCrtKeyImpl, newKey, $RSAPrivateKey*, $RSAUtil$KeyType*, $AlgorithmParameterSpec*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*), "java.security.InvalidKeyException"},
	{"parseASN1", "([B)[Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(RSAPrivateCrtKeyImpl, parseASN1, $BigIntegerArray*, $bytes*), "java.io.IOException"},
	{"parseKeyBits", "()V", nullptr, $PRIVATE, $method(RSAPrivateCrtKeyImpl, parseKeyBits, void), "java.security.InvalidKeyException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(RSAPrivateCrtKeyImpl, toString, $String*)},
	{}
};

$ClassInfo _RSAPrivateCrtKeyImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.rsa.RSAPrivateCrtKeyImpl",
	"sun.security.pkcs.PKCS8Key",
	"java.security.interfaces.RSAPrivateCrtKey",
	_RSAPrivateCrtKeyImpl_FieldInfo_,
	_RSAPrivateCrtKeyImpl_MethodInfo_
};

$Object* allocate$RSAPrivateCrtKeyImpl($Class* clazz) {
	return $of($alloc(RSAPrivateCrtKeyImpl));
}

$bytes* RSAPrivateCrtKeyImpl::getEncoded() {
	 return this->$PKCS8Key::getEncoded();
}

$String* RSAPrivateCrtKeyImpl::getFormat() {
	 return this->$PKCS8Key::getFormat();
}

bool RSAPrivateCrtKeyImpl::equals(Object$* object) {
	 return this->$PKCS8Key::equals(object);
}

int32_t RSAPrivateCrtKeyImpl::hashCode() {
	 return this->$PKCS8Key::hashCode();
}

$Object* RSAPrivateCrtKeyImpl::clone() {
	 return this->$PKCS8Key::clone();
}

void RSAPrivateCrtKeyImpl::finalize() {
	this->$PKCS8Key::finalize();
}

void RSAPrivateCrtKeyImpl::destroy() {
	this->$PKCS8Key::destroy();
}

bool RSAPrivateCrtKeyImpl::isDestroyed() {
	 return this->$PKCS8Key::isDestroyed();
}

$RSAPrivateKey* RSAPrivateCrtKeyImpl::newKey($RSAUtil$KeyType* type, $String* format, $bytes* encoded) {
	$init(RSAPrivateCrtKeyImpl);
	$useLocalCurrentObjectStackCache();
	if (encoded == nullptr || $nc(encoded)->length == 0) {
		$throwNew($InvalidKeyException, "Missing key encoding"_s);
	}
	{
		$var($String, s3190$, format);
		int32_t tmp3190$ = -1;
		switch ($nc(s3190$)->hashCode()) {
		case (int32_t)0x8CC44560:
			{
				if (s3190$->equals("PKCS#8"_s)) {
					tmp3190$ = 0;
				}
				break;
			}
		case (int32_t)0x8CC44559:
			{
				if (s3190$->equals("PKCS#1"_s)) {
					tmp3190$ = 1;
				}
				break;
			}
		}
		{
			$var(RSAPrivateCrtKeyImpl, key, nullptr)
			switch (tmp3190$) {
			case 0:
				{
					$assign(key, $new(RSAPrivateCrtKeyImpl, encoded));
					$RSAKeyFactory::checkKeyAlgo(static_cast<$Key*>(static_cast<$PrivateKey*>(static_cast<$PKCS8Key*>(key))), $nc(type)->keyAlgo);
					bool var$4 = ($nc($($nc(key)->getPublicExponent()))->signum() == 0);
					bool var$3 = var$4 || ($nc($($nc(key)->getPrimeExponentP()))->signum() == 0);
					bool var$2 = var$3 || ($nc($($nc(key)->getPrimeExponentQ()))->signum() == 0);
					bool var$1 = var$2 || ($nc($($nc(key)->getPrimeP()))->signum() == 0);
					bool var$0 = var$1 || ($nc($($nc(key)->getPrimeQ()))->signum() == 0);
					if (var$0 || ($nc($($nc(key)->getCrtCoefficient()))->signum() == 0)) {
						$var($RSAUtil$KeyType, var$5, key->type);
						$var($AlgorithmParameterSpec, var$6, key->keyParams);
						$var($BigInteger, var$7, key->getModulus());
						return $new($RSAPrivateKeyImpl, var$5, var$6, var$7, $(key->getPrivateExponent()));
					} else {
						return key;
					}
				}
			case 1:
				{
					try {
						$var($BigIntegerArray, comps, parseASN1(encoded));
						bool var$12 = ($nc($nc(comps)->get(1))->signum() == 0);
						bool var$11 = var$12 || ($nc($nc(comps)->get(3))->signum() == 0);
						bool var$10 = var$11 || ($nc($nc(comps)->get(4))->signum() == 0);
						bool var$9 = var$10 || ($nc($nc(comps)->get(5))->signum() == 0);
						bool var$8 = var$9 || ($nc($nc(comps)->get(6))->signum() == 0);
						if (var$8 || ($nc($nc(comps)->get(7))->signum() == 0)) {
							return $new($RSAPrivateKeyImpl, type, nullptr, comps->get(0), comps->get(2));
						} else {
							return $new(RSAPrivateCrtKeyImpl, type, nullptr, comps->get(0), comps->get(1), comps->get(2), comps->get(3), comps->get(4), comps->get(5), comps->get(6), comps->get(7));
						}
					} catch ($IOException& ioe) {
						$throwNew($InvalidKeyException, "Invalid PKCS#1 encoding"_s, ioe);
					}
				}
			default:
				{
					$throwNew($InvalidKeyException, $$str({"Unsupported RSA Private(Crt)Key format: "_s, format}));
				}
			}
		}
	}
	$shouldNotReachHere();
}

$RSAPrivateKey* RSAPrivateCrtKeyImpl::newKey($RSAUtil$KeyType* type, $AlgorithmParameterSpec* params, $BigInteger* n, $BigInteger* e, $BigInteger* d, $BigInteger* p, $BigInteger* q, $BigInteger* pe, $BigInteger* qe, $BigInteger* coeff) {
	$init(RSAPrivateCrtKeyImpl);
	$var($RSAPrivateKey, key, nullptr);
	bool var$4 = ($nc(e)->signum() == 0);
	bool var$3 = var$4 || ($nc(p)->signum() == 0);
	bool var$2 = var$3 || ($nc(q)->signum() == 0);
	bool var$1 = var$2 || ($nc(pe)->signum() == 0);
	bool var$0 = var$1 || ($nc(qe)->signum() == 0);
	if (var$0 || ($nc(coeff)->signum() == 0)) {
		return $new($RSAPrivateKeyImpl, type, params, n, d);
	} else {
		return $new(RSAPrivateCrtKeyImpl, type, params, n, e, d, p, q, pe, qe, coeff);
	}
}

void RSAPrivateCrtKeyImpl::init$($bytes* encoded) {
	$PKCS8Key::init$(encoded);
	parseKeyBits();
	$RSAKeyFactory::checkRSAProviderKeyLengths($nc(this->n)->bitLength(), this->e);
	try {
		$var($ObjectArray, o, $RSAUtil::getTypeAndParamSpec(this->algid));
		$set(this, type, $cast($RSAUtil$KeyType, $nc(o)->get(0)));
		$set(this, keyParams, $cast($AlgorithmParameterSpec, o->get(1)));
	} catch ($ProviderException& e) {
		$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
	}
}

void RSAPrivateCrtKeyImpl::init$($RSAUtil$KeyType* type, $AlgorithmParameterSpec* keyParams, $BigInteger* n, $BigInteger* e, $BigInteger* d, $BigInteger* p, $BigInteger* q, $BigInteger* pe, $BigInteger* qe, $BigInteger* coeff) {
	$useLocalCurrentObjectStackCache();
	$PKCS8Key::init$();
	$RSAKeyFactory::checkRSAProviderKeyLengths($nc(n)->bitLength(), e);
	$set(this, n, n);
	$set(this, e, e);
	$set(this, d, d);
	$set(this, p, p);
	$set(this, q, q);
	$set(this, pe, pe);
	$set(this, qe, qe);
	$set(this, coeff, coeff);
	try {
		$set(this, algid, $RSAUtil::createAlgorithmId(type, keyParams));
	} catch ($ProviderException& exc) {
		$throwNew($InvalidKeyException, static_cast<$Throwable*>(exc));
	}
	$set(this, type, type);
	$set(this, keyParams, keyParams);
	try {
		$var($byteArray2, nbytes, $new($byteArray2, 8));
		nbytes->set(0, $($nc(n)->toByteArray()));
		nbytes->set(1, $($nc(e)->toByteArray()));
		nbytes->set(2, $($nc(d)->toByteArray()));
		nbytes->set(3, $($nc(p)->toByteArray()));
		nbytes->set(4, $($nc(q)->toByteArray()));
		nbytes->set(5, $($nc(pe)->toByteArray()));
		nbytes->set(6, $($nc(qe)->toByteArray()));
		nbytes->set(7, $($nc(coeff)->toByteArray()));
		$var($DerOutputStream, out, $new($DerOutputStream, $nc(nbytes->get(0))->length + $nc(nbytes->get(1))->length + $nc(nbytes->get(2))->length + $nc(nbytes->get(3))->length + $nc(nbytes->get(4))->length + $nc(nbytes->get(5))->length + $nc(nbytes->get(6))->length + $nc(nbytes->get(7))->length + 100));
		out->putInteger(0);
		out->putInteger(nbytes->get(0));
		out->putInteger(nbytes->get(1));
		out->putInteger(nbytes->get(2));
		out->putInteger(nbytes->get(3));
		out->putInteger(nbytes->get(4));
		out->putInteger(nbytes->get(5));
		out->putInteger(nbytes->get(6));
		out->putInteger(nbytes->get(7));
		$Arrays::fill(nbytes->get(2), (int8_t)0);
		$Arrays::fill(nbytes->get(3), (int8_t)0);
		$Arrays::fill(nbytes->get(4), (int8_t)0);
		$Arrays::fill(nbytes->get(5), (int8_t)0);
		$Arrays::fill(nbytes->get(6), (int8_t)0);
		$Arrays::fill(nbytes->get(7), (int8_t)0);
		$var($DerValue, val, $DerValue::wrap($DerValue::tag_Sequence, out));
		$set(this, key, $nc(val)->toByteArray());
		val->clear();
	} catch ($IOException& exc) {
		$throwNew($InvalidKeyException, static_cast<$Throwable*>(exc));
	}
}

$String* RSAPrivateCrtKeyImpl::getAlgorithm() {
	return $nc(this->type)->keyAlgo;
}

$BigInteger* RSAPrivateCrtKeyImpl::getModulus() {
	return this->n;
}

$BigInteger* RSAPrivateCrtKeyImpl::getPublicExponent() {
	return this->e;
}

$BigInteger* RSAPrivateCrtKeyImpl::getPrivateExponent() {
	return this->d;
}

$BigInteger* RSAPrivateCrtKeyImpl::getPrimeP() {
	return this->p;
}

$BigInteger* RSAPrivateCrtKeyImpl::getPrimeQ() {
	return this->q;
}

$BigInteger* RSAPrivateCrtKeyImpl::getPrimeExponentP() {
	return this->pe;
}

$BigInteger* RSAPrivateCrtKeyImpl::getPrimeExponentQ() {
	return this->qe;
}

$BigInteger* RSAPrivateCrtKeyImpl::getCrtCoefficient() {
	return this->coeff;
}

$AlgorithmParameterSpec* RSAPrivateCrtKeyImpl::getParams() {
	return this->keyParams;
}

$String* RSAPrivateCrtKeyImpl::toString() {
	return $str({"SunRsaSign "_s, $nc(this->type)->keyAlgo, " private CRT key, "_s, $$str($nc(this->n)->bitLength()), " bits\n  params: "_s, this->keyParams, "\n  modulus: "_s, this->n, "\n  private exponent: "_s, this->d});
}

$BigIntegerArray* RSAPrivateCrtKeyImpl::parseASN1($bytes* raw) {
	$init(RSAPrivateCrtKeyImpl);
	$useLocalCurrentObjectStackCache();
	$var($DerValue, derValue, $new($DerValue, raw));
	{
		$var($Throwable, var$0, nullptr);
		$var($BigIntegerArray, var$2, nullptr);
		bool return$1 = false;
		try {
			if (derValue->tag != $DerValue::tag_Sequence) {
				$throwNew($IOException, "Not a SEQUENCE"_s);
			}
			int32_t version = $nc(derValue->data$)->getInteger();
			if (version != 0) {
				$throwNew($IOException, "Version must be 0"_s);
			}
			$var($BigIntegerArray, result, $new($BigIntegerArray, 8));
			for (int32_t i = 0; i < result->length; ++i) {
				result->set(i, $($nc(derValue->data$)->getPositiveBigInteger()));
			}
			if ($nc(derValue->data$)->available() != 0) {
				$throwNew($IOException, "Extra data available"_s);
			}
			$assign(var$2, result);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			derValue->clear();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void RSAPrivateCrtKeyImpl::parseKeyBits() {
	try {
		$var($BigIntegerArray, comps, parseASN1(this->key));
		$set(this, n, $nc(comps)->get(0));
		$set(this, e, comps->get(1));
		$set(this, d, comps->get(2));
		$set(this, p, comps->get(3));
		$set(this, q, comps->get(4));
		$set(this, pe, comps->get(5));
		$set(this, qe, comps->get(6));
		$set(this, coeff, comps->get(7));
	} catch ($IOException& e) {
		$throwNew($InvalidKeyException, "Invalid RSA private key"_s, e);
	}
}

RSAPrivateCrtKeyImpl::RSAPrivateCrtKeyImpl() {
}

$Class* RSAPrivateCrtKeyImpl::load$($String* name, bool initialize) {
	$loadClass(RSAPrivateCrtKeyImpl, name, initialize, &_RSAPrivateCrtKeyImpl_ClassInfo_, allocate$RSAPrivateCrtKeyImpl);
	return class$;
}

$Class* RSAPrivateCrtKeyImpl::class$ = nullptr;

		} // rsa
	} // security
} // sun