#include <sun/security/provider/DSAPrivateKey.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/interfaces/DSAParams.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/DSAParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/util/Arrays.h>
#include <sun/security/pkcs/PKCS8Key.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/AlgIdDSA.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $DSAParams = ::java::security::interfaces::DSAParams;
using $DSAParameterSpec = ::java::security::spec::DSAParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $Arrays = ::java::util::Arrays;
using $PKCS8Key = ::sun::security::pkcs::PKCS8Key;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;
using $AlgIdDSA = ::sun::security::x509::AlgIdDSA;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _DSAPrivateKey_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DSAPrivateKey, serialVersionUID)},
	{"x", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(DSAPrivateKey, x)},
	{}
};

$MethodInfo _DSAPrivateKey_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*destroy", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getEncoded", "()[B", nullptr, $PUBLIC},
	{"*getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)V", nullptr, $PUBLIC, $method(DSAPrivateKey, init$, void, $BigInteger*, $BigInteger*, $BigInteger*, $BigInteger*)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(DSAPrivateKey, init$, void, $bytes*), "java.security.InvalidKeyException"},
	{"getParams", "()Ljava/security/interfaces/DSAParams;", nullptr, $PUBLIC, $virtualMethod(DSAPrivateKey, getParams, $DSAParams*)},
	{"getX", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(DSAPrivateKey, getX, $BigInteger*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*isDestroyed", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _DSAPrivateKey_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.DSAPrivateKey",
	"sun.security.pkcs.PKCS8Key",
	"java.security.interfaces.DSAPrivateKey",
	_DSAPrivateKey_FieldInfo_,
	_DSAPrivateKey_MethodInfo_
};

$Object* allocate$DSAPrivateKey($Class* clazz) {
	return $of($alloc(DSAPrivateKey));
}

$String* DSAPrivateKey::getAlgorithm() {
	 return this->$PKCS8Key::getAlgorithm();
}

$bytes* DSAPrivateKey::getEncoded() {
	 return this->$PKCS8Key::getEncoded();
}

$String* DSAPrivateKey::getFormat() {
	 return this->$PKCS8Key::getFormat();
}

bool DSAPrivateKey::equals(Object$* object) {
	 return this->$PKCS8Key::equals(object);
}

int32_t DSAPrivateKey::hashCode() {
	 return this->$PKCS8Key::hashCode();
}

$Object* DSAPrivateKey::clone() {
	 return this->$PKCS8Key::clone();
}

$String* DSAPrivateKey::toString() {
	 return this->$PKCS8Key::toString();
}

void DSAPrivateKey::finalize() {
	this->$PKCS8Key::finalize();
}

void DSAPrivateKey::destroy() {
	this->$PKCS8Key::destroy();
}

bool DSAPrivateKey::isDestroyed() {
	 return this->$PKCS8Key::isDestroyed();
}

void DSAPrivateKey::init$($BigInteger* x, $BigInteger* p, $BigInteger* q, $BigInteger* g) {
	$useLocalCurrentObjectStackCache();
	$PKCS8Key::init$();
	$set(this, x, x);
	$set(this, algid, $new($AlgIdDSA, p, q, g));
	try {
		$var($bytes, xbytes, $nc(x)->toByteArray());
		$var($DerValue, val, $new($DerValue, $DerValue::tag_Integer, xbytes));
		$set(this, key, val->toByteArray());
		val->clear();
		$Arrays::fill(xbytes, (int8_t)0);
	} catch ($IOException& e) {
		$throwNew($AssertionError, "Should not happen"_s, e);
	}
}

void DSAPrivateKey::init$($bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$PKCS8Key::init$(encoded);
	try {
		$var($DerInputStream, in, $new($DerInputStream, this->key));
		$set(this, x, in->getBigInteger());
	} catch ($IOException& e) {
		$throwNew($InvalidKeyException, $(e->getMessage()), e);
	}
}

$DSAParams* DSAPrivateKey::getParams() {
	$useLocalCurrentObjectStackCache();
	try {
		if ($instanceOf($DSAParams, this->algid)) {
			return $cast($DSAParams, this->algid);
		} else {
			$var($DSAParameterSpec, paramSpec, nullptr);
			$var($AlgorithmParameters, algParams, $nc(this->algid)->getParameters());
			if (algParams == nullptr) {
				return nullptr;
			}
			$load($DSAParameterSpec);
			$assign(paramSpec, $cast($DSAParameterSpec, $nc(algParams)->getParameterSpec($DSAParameterSpec::class$)));
			return paramSpec;
		}
	} catch ($InvalidParameterSpecException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$BigInteger* DSAPrivateKey::getX() {
	return this->x;
}

DSAPrivateKey::DSAPrivateKey() {
}

$Class* DSAPrivateKey::load$($String* name, bool initialize) {
	$loadClass(DSAPrivateKey, name, initialize, &_DSAPrivateKey_ClassInfo_, allocate$DSAPrivateKey);
	return class$;
}

$Class* DSAPrivateKey::class$ = nullptr;

		} // provider
	} // security
} // sun