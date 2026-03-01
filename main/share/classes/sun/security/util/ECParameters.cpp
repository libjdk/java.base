#include <sun/security/util/ECParameters.h>

#include <java/io/IOException.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/AlgorithmParametersSpi.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/ECField.h>
#include <java/security/spec/ECGenParameterSpec.h>
#include <java/security/spec/ECParameterSpec.h>
#include <java/security/spec/EllipticCurve.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <sun/security/util/CurveDB.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ECKeySizeParameterSpec.h>
#include <sun/security/util/NamedCurve.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $AlgorithmParametersSpi = ::java::security::AlgorithmParametersSpi;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $ECField = ::java::security::spec::ECField;
using $ECGenParameterSpec = ::java::security::spec::ECGenParameterSpec;
using $ECParameterSpec = ::java::security::spec::ECParameterSpec;
using $EllipticCurve = ::java::security::spec::EllipticCurve;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $CurveDB = ::sun::security::util::CurveDB;
using $DerValue = ::sun::security::util::DerValue;
using $ECKeySizeParameterSpec = ::sun::security::util::ECKeySizeParameterSpec;
using $NamedCurve = ::sun::security::util::NamedCurve;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _ECParameters_FieldInfo_[] = {
	{"namedCurve", "Lsun/security/util/NamedCurve;", nullptr, $PRIVATE, $field(ECParameters, namedCurve)},
	{}
};

$MethodInfo _ECParameters_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ECParameters, init$, void)},
	{"engineGetEncoded", "()[B", nullptr, $PROTECTED, $virtualMethod(ECParameters, engineGetEncoded, $bytes*), "java.io.IOException"},
	{"engineGetEncoded", "(Ljava/lang/String;)[B", nullptr, $PROTECTED, $virtualMethod(ECParameters, engineGetEncoded, $bytes*, $String*), "java.io.IOException"},
	{"engineGetParameterSpec", "(Ljava/lang/Class;)Ljava/security/spec/AlgorithmParameterSpec;", "<T::Ljava/security/spec/AlgorithmParameterSpec;>(Ljava/lang/Class<TT;>;)TT;", $PROTECTED, $virtualMethod(ECParameters, engineGetParameterSpec, $AlgorithmParameterSpec*, $Class*), "java.security.spec.InvalidParameterSpecException"},
	{"engineInit", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(ECParameters, engineInit, void, $AlgorithmParameterSpec*), "java.security.spec.InvalidParameterSpecException"},
	{"engineInit", "([B)V", nullptr, $PROTECTED, $virtualMethod(ECParameters, engineInit, void, $bytes*), "java.io.IOException"},
	{"engineInit", "([BLjava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(ECParameters, engineInit, void, $bytes*, $String*), "java.io.IOException"},
	{"engineToString", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(ECParameters, engineToString, $String*)},
	{"getAlgorithmParameters", "(Ljava/security/spec/ECParameterSpec;)Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC | $STATIC, $staticMethod(ECParameters, getAlgorithmParameters, $AlgorithmParameters*, $ECParameterSpec*), "java.security.InvalidKeyException"},
	{}
};

$ClassInfo _ECParameters_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.util.ECParameters",
	"java.security.AlgorithmParametersSpi",
	nullptr,
	_ECParameters_FieldInfo_,
	_ECParameters_MethodInfo_
};

$Object* allocate$ECParameters($Class* clazz) {
	return $of($alloc(ECParameters));
}

$AlgorithmParameters* ECParameters::getAlgorithmParameters($ECParameterSpec* spec) {
	$init(ECParameters);
	try {
		$var($AlgorithmParameters, params, $AlgorithmParameters::getInstance("EC"_s, "SunEC"_s));
		$nc(params)->init(static_cast<$AlgorithmParameterSpec*>(spec));
		return params;
	} catch ($GeneralSecurityException& e) {
		$throwNew($InvalidKeyException, "EC parameters error"_s, e);
	}
	$shouldNotReachHere();
}

void ECParameters::init$() {
	$AlgorithmParametersSpi::init$();
}

void ECParameters::engineInit($AlgorithmParameterSpec* paramSpec) {
	$useLocalCurrentObjectStackCache();
	if (paramSpec == nullptr) {
		$throwNew($InvalidParameterSpecException, "paramSpec must not be null"_s);
	}
	if ($instanceOf($NamedCurve, paramSpec)) {
		$set(this, namedCurve, $cast($NamedCurve, paramSpec));
		return;
	}
	if ($instanceOf($ECParameterSpec, paramSpec)) {
		$set(this, namedCurve, $CurveDB::lookup($cast($ECParameterSpec, paramSpec)));
	} else if ($instanceOf($ECGenParameterSpec, paramSpec)) {
		$var($String, name, $nc(($cast($ECGenParameterSpec, paramSpec)))->getName());
		$set(this, namedCurve, $CurveDB::lookup(name));
	} else if ($instanceOf($ECKeySizeParameterSpec, paramSpec)) {
		int32_t keySize = $nc(($cast($ECKeySizeParameterSpec, paramSpec)))->getKeySize();
		$set(this, namedCurve, $CurveDB::lookup(keySize));
	} else {
		$throwNew($InvalidParameterSpecException, "Only ECParameterSpec and ECGenParameterSpec supported"_s);
	}
	if (this->namedCurve == nullptr) {
		$throwNew($InvalidParameterSpecException, $$str({"Not a supported curve: "_s, paramSpec}));
	}
}

void ECParameters::engineInit($bytes* params) {
	$useLocalCurrentObjectStackCache();
	$var($DerValue, encodedParams, $new($DerValue, params));
	if (encodedParams->tag == $DerValue::tag_ObjectId) {
		$var($ObjectIdentifier, oid, encodedParams->getOID());
		$var($NamedCurve, spec, $CurveDB::lookup($($nc(oid)->toString())));
		if (spec == nullptr) {
			$throwNew($IOException, $$str({"Unknown named curve: "_s, oid}));
		}
		$set(this, namedCurve, spec);
		return;
	}
	$throwNew($IOException, "Only named ECParameters supported"_s);
}

void ECParameters::engineInit($bytes* params, $String* decodingMethod) {
	engineInit(params);
}

$AlgorithmParameterSpec* ECParameters::engineGetParameterSpec($Class* spec) {
	$useLocalCurrentObjectStackCache();
	$load($ECParameterSpec);
	if ($nc(spec)->isAssignableFrom($ECParameterSpec::class$)) {
		return $cast($AlgorithmParameterSpec, spec->cast(this->namedCurve));
	}
	$load($ECGenParameterSpec);
	if ($nc(spec)->isAssignableFrom($ECGenParameterSpec::class$)) {
		$var($String, name, $nc(this->namedCurve)->getObjectId());
		return $cast($AlgorithmParameterSpec, spec->cast($$new($ECGenParameterSpec, name)));
	}
	$load($ECKeySizeParameterSpec);
	if ($nc(spec)->isAssignableFrom($ECKeySizeParameterSpec::class$)) {
		int32_t keySize = $nc($($nc($($nc(this->namedCurve)->getCurve()))->getField()))->getFieldSize();
		return $cast($AlgorithmParameterSpec, spec->cast($$new($ECKeySizeParameterSpec, keySize)));
	}
	$throwNew($InvalidParameterSpecException, "Only ECParameterSpec and ECGenParameterSpec supported"_s);
}

$bytes* ECParameters::engineGetEncoded() {
	return $nc(this->namedCurve)->getEncoded();
}

$bytes* ECParameters::engineGetEncoded($String* encodingMethod) {
	return engineGetEncoded();
}

$String* ECParameters::engineToString() {
	if (this->namedCurve == nullptr) {
		return "Not initialized"_s;
	}
	return $nc(this->namedCurve)->toString();
}

ECParameters::ECParameters() {
}

$Class* ECParameters::load$($String* name, bool initialize) {
	$loadClass(ECParameters, name, initialize, &_ECParameters_ClassInfo_, allocate$ECParameters);
	return class$;
}

$Class* ECParameters::class$ = nullptr;

		} // util
	} // security
} // sun